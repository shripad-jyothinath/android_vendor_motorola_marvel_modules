// Decompiled by Ghidra 12.2
// Program: minidump.ko
// Image base: 00100000

//------------------------------------------------------------
// elf_lookup_string @ 0010141c size=60
// signature: undefined elf_lookup_string(void)
// callers: []
//------------------------------------------------------------

long elf_lookup_string(long param_1,int param_2)

{
  long lVar1;
  long lVar2;
  
  lVar2 = 0;
  if ((ulong)*(ushort *)(param_1 + 0x3e) != 0) {
    lVar2 = param_1 + *(long *)(*(long *)(param_1 + 0x28) + param_1 +
                                (ulong)*(ushort *)(param_1 + 0x3e) * 0x40 + 0x18);
  }
  lVar1 = 0;
  if ((ulong)(long)param_2 <= DAT_00108838 && lVar2 != 0) {
    lVar1 = lVar2 + param_2;
  }
  return lVar1;
}



//------------------------------------------------------------
// set_section_name @ 0010145c size=132
// signature: undefined set_section_name(void)
// callers: [md_smem_add_header]
//------------------------------------------------------------

ulong set_section_name(long param_1)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  
  uVar2 = DAT_00108838;
  if ((ulong)*(ushort *)(minidump_elfheader + 0x3e) == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = 0;
    if ((param_1 != 0) &&
       (lVar1 = minidump_elfheader +
                *(long *)(*(long *)(minidump_elfheader + 0x28) + minidump_elfheader +
                          (ulong)*(ushort *)(minidump_elfheader + 0x3e) * 0x40 + 0x18), lVar1 != 0))
    {
      iVar4 = (int)DAT_00108838;
      iVar3 = strscpy(lVar1 + iVar4,param_1,0x10);
      DAT_00108838 = (ulong)(iVar3 + iVar4 + 1);
      uVar5 = uVar2;
    }
  }
  return uVar5 & 0xffffffff;
}



//------------------------------------------------------------
// md_get_region @ 001014e4 size=64
// signature: undefined md_get_region(void)
// callers: [md_unregister_memory_dump]
//------------------------------------------------------------

void md_get_region(void)

{
  code *pcVar1;
  
  if (*(int *)(*(code **)(md_core_0 + 0x40) + -4) != -0x4bc95eb4) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8229,0x101514);
    (*pcVar1)();
  }
  (**(code **)(md_core_0 + 0x40))();
  return;
}



//------------------------------------------------------------
// md_add_elf_header @ 00101528 size=308
// signature: undefined md_add_elf_header(void)
// callers: [md_smem_add_region, md_smem_add_pending_entry]
//------------------------------------------------------------

void md_add_elf_header(long param_1)

{
  int *piVar1;
  long lVar2;
  long lVar3;
  ushort uVar4;
  long lVar5;
  int iVar6;
  undefined8 uVar7;
  undefined4 *puVar8;
  int iVar9;
  
  lVar5 = minidump_elfheader;
  iVar9 = 0;
  lVar3 = *(long *)(minidump_elfheader + 0x20);
  uVar4 = *(ushort *)(minidump_elfheader + 0x38);
  piVar1 = (int *)(*(long *)(minidump_elfheader + 0x28) + minidump_elfheader +
                  (ulong)*(ushort *)(minidump_elfheader + 0x3c) * 0x40);
  *(ushort *)(minidump_elfheader + 0x3c) = *(ushort *)(minidump_elfheader + 0x3c) + 1;
  *(ushort *)(lVar5 + 0x38) = uVar4 + 1;
  piVar1[1] = 1;
  if ((((ulong)*(ushort *)(minidump_elfheader + 0x3e) != 0) && (param_1 != 0)) &&
     (lVar2 = minidump_elfheader +
              *(long *)(*(long *)(minidump_elfheader + 0x28) + minidump_elfheader +
                        (ulong)*(ushort *)(minidump_elfheader + 0x3e) * 0x40 + 0x18), lVar2 != 0)) {
    iVar9 = (int)DAT_00108838;
    iVar6 = strscpy(lVar2 + iVar9,param_1,0x10);
    DAT_00108838 = (long)(iVar6 + iVar9 + 1);
  }
  *piVar1 = iVar9;
  *(undefined8 *)(piVar1 + 4) = *(undefined8 *)(param_1 + 0x18);
  uVar7 = *(undefined8 *)(param_1 + 0x28);
  piVar1[2] = 1;
  piVar1[3] = 0;
  *(undefined8 *)(piVar1 + 8) = uVar7;
  lVar2 = DAT_00108830;
  puVar8 = (undefined4 *)(lVar3 + lVar5 + (ulong)uVar4 * 0x38);
  piVar1[0xe] = 0;
  piVar1[0xf] = 0;
  *(long *)(piVar1 + 6) = lVar2;
  *puVar8 = 1;
  *(long *)(puVar8 + 2) = DAT_00108830;
  *(undefined8 *)(puVar8 + 4) = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(puVar8 + 6) = *(undefined8 *)(param_1 + 0x20);
  uVar7 = *(undefined8 *)(param_1 + 0x28);
  puVar8[1] = 6;
  *(undefined8 *)(puVar8 + 8) = uVar7;
  *(undefined8 *)(puVar8 + 10) = uVar7;
  DAT_00108830 = DAT_00108830 + *(long *)(piVar1 + 8);
  return;
}



//------------------------------------------------------------
// msm_minidump_clear_headers @ 00101660 size=820
// signature: undefined msm_minidump_clear_headers(void)
// callers: [md_smem_remove_region]
//------------------------------------------------------------

undefined8 msm_minidump_clear_headers(char *param_1)

{
  uint *puVar1;
  long lVar2;
  int *piVar3;
  ushort uVar4;
  ushort uVar5;
  long lVar6;
  int iVar7;
  size_t sVar8;
  char *pcVar9;
  ulong uVar10;
  undefined8 *puVar11;
  long lVar12;
  long lVar13;
  ulong uVar14;
  ulong uVar15;
  uint *puVar16;
  
  uVar10 = DAT_00108838;
  lVar6 = minidump_elfheader;
  lVar13 = *(long *)(param_1 + 0x28);
  uVar4 = *(ushort *)(minidump_elfheader + 0x38);
  if (uVar4 != 0) {
    uVar15 = 0;
    lVar12 = *(long *)(minidump_elfheader + 0x20) + minidump_elfheader;
    do {
      if ((*(long *)(lVar12 + 0x18) == *(long *)(param_1 + 0x20)) &&
         (*(long *)(lVar12 + 0x28) == lVar13)) {
        if ((uint)uVar15 != (uint)uVar4) {
          uVar4 = *(ushort *)(minidump_elfheader + 0x3c);
          if (uVar4 != 0) {
            uVar14 = 0;
            uVar5 = *(ushort *)(minidump_elfheader + 0x3e);
            puVar16 = (uint *)(*(long *)(minidump_elfheader + 0x28) + minidump_elfheader);
            puVar1 = puVar16 + (ulong)uVar5 * 0x10 + 6;
            goto LAB_00101734;
          }
        }
        break;
      }
      uVar15 = uVar15 + 1;
      lVar12 = lVar12 + 0x38;
    } while (uVar4 != uVar15);
  }
  goto LAB_00101870;
  while( true ) {
    uVar14 = uVar14 + 1;
    puVar16 = puVar16 + 0x10;
    if (uVar4 == uVar14) break;
LAB_00101734:
    if ((((uVar5 != 0) && (lVar6 + *(long *)puVar1 != 0)) && ((ulong)(long)(int)*puVar16 <= uVar10))
       && (((pcVar9 = (char *)(lVar6 + *(long *)puVar1 + (long)(int)*puVar16), pcVar9 != (char *)0x0
            && (iVar7 = strcmp(pcVar9,param_1), iVar7 == 0)) &&
           ((*(long *)(puVar16 + 4) == *(long *)(param_1 + 0x18) &&
            (*(long *)(puVar16 + 8) == lVar13)))))) {
      if ((uint)uVar14 != (uint)uVar4) {
        if (*(long *)(puVar16 + 6) == *(long *)(lVar12 + 8)) {
          sVar8 = strlen(pcVar9);
          iVar7 = (int)sVar8 + 1;
          memmove(pcVar9,pcVar9 + iVar7,DAT_00108838 - *puVar16);
          DAT_00108838 = DAT_00108838 - (long)iVar7;
          uVar10 = uVar15 & 0xffffffff;
          if ((int)(uint)uVar15 < (int)(*(ushort *)(lVar6 + 0x38) - 1)) {
            lVar12 = uVar10 * 0x38;
            do {
              uVar10 = uVar10 + 1;
              lVar2 = *(long *)(lVar6 + 0x20) + lVar6;
              puVar11 = (undefined8 *)(lVar2 + lVar12);
              lVar12 = lVar12 + 0x38;
              puVar11[5] = puVar11[0xc];
              puVar11[6] = puVar11[0xd];
              puVar11[3] = puVar11[10];
              puVar11[4] = puVar11[0xb];
              *puVar11 = puVar11[7];
              puVar11[1] = puVar11[8] - lVar13;
              puVar11[2] = puVar11[9];
            } while ((long)uVar10 < (long)((ulong)*(ushort *)(lVar6 + 0x38) - 1));
            puVar11 = (undefined8 *)(lVar2 + lVar12);
          }
          else {
            puVar11 = (undefined8 *)(*(long *)(lVar6 + 0x20) + lVar6 + uVar10 * 0x38);
          }
          puVar11[5] = 0;
          puVar11[6] = 0;
          puVar11[3] = 0;
          puVar11[4] = 0;
          puVar11[1] = 0;
          puVar11[2] = 0;
          *puVar11 = 0;
          uVar10 = uVar14 & 0xffffffff;
          *(short *)(lVar6 + 0x38) = *(short *)(lVar6 + 0x38) + -1;
          if ((int)(uint)uVar14 < (int)(*(ushort *)(lVar6 + 0x3c) - 1)) {
            lVar12 = uVar10 << 6;
            do {
              uVar10 = uVar10 + 1;
              lVar2 = *(long *)(lVar6 + 0x28) + lVar6;
              piVar3 = (int *)(lVar2 + lVar12);
              lVar12 = lVar12 + 0x40;
              *(undefined8 *)piVar3 = *(undefined8 *)(piVar3 + 0x10);
              *(undefined8 *)(piVar3 + 2) = *(undefined8 *)(piVar3 + 0x12);
              *(undefined8 *)(piVar3 + 0xc) = *(undefined8 *)(piVar3 + 0x1c);
              *(undefined8 *)(piVar3 + 0xe) = *(undefined8 *)(piVar3 + 0x1e);
              *piVar3 = (int)*(undefined8 *)(piVar3 + 0x10) - iVar7;
              *(undefined8 *)(piVar3 + 8) = *(undefined8 *)(piVar3 + 0x18);
              *(undefined8 *)(piVar3 + 10) = *(undefined8 *)(piVar3 + 0x1a);
              *(undefined8 *)(piVar3 + 4) = *(undefined8 *)(piVar3 + 0x14);
              *(long *)(piVar3 + 6) = *(long *)(piVar3 + 0x16) - lVar13;
            } while ((long)uVar10 < (long)((ulong)*(ushort *)(lVar6 + 0x3c) - 1));
            puVar11 = (undefined8 *)(lVar2 + lVar12);
          }
          else {
            puVar11 = (undefined8 *)(*(long *)(lVar6 + 0x28) + lVar6 + uVar10 * 0x40);
          }
          puVar11[6] = 0;
          puVar11[7] = 0;
          puVar11[4] = 0;
          puVar11[5] = 0;
          puVar11[2] = 0;
          puVar11[3] = 0;
          *puVar11 = 0;
          puVar11[1] = 0;
          *(short *)(lVar6 + 0x3c) = *(short *)(lVar6 + 0x3c) + -1;
          DAT_00108830 = DAT_00108830 - lVar13;
          return 0;
        }
        pcVar9 = "Invalid entry details in elf, Minidump broken..\n";
        goto LAB_00101878;
      }
      break;
    }
  }
LAB_00101870:
  pcVar9 = "Cannot find entry in elf\n";
LAB_00101878:
  _printk_deferred(pcVar9);
  return 0xffffffea;
}



//------------------------------------------------------------
// msm_minidump_enabled @ 00101998 size=80
// signature: undefined msm_minidump_enabled(void)
// callers: []
//------------------------------------------------------------

uint msm_minidump_enabled(void)

{
  code *pcVar1;
  uint uVar2;
  
  if (md_core_0 == 0) {
    uVar2 = 0;
  }
  else {
    if (*(int *)(*(code **)(md_core_0 + 0x38) + -4) != 0x7f318e9b) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1019cc);
      (*pcVar1)();
    }
    uVar2 = (**(code **)(md_core_0 + 0x38))();
  }
  return uVar2 & 1;
}



//------------------------------------------------------------
// msm_minidump_get_available_region @ 001019ec size=76
// signature: undefined msm_minidump_get_available_region(void)
// callers: [md_module_process]
//------------------------------------------------------------

undefined8 msm_minidump_get_available_region(void)

{
  code *pcVar1;
  undefined8 uVar2;
  
  if (md_core_0 == 0) {
    uVar2 = 0xfffffff0;
  }
  else {
    if (*(int *)(*(code **)(md_core_0 + 0x30) + -4) != 0x36b1c5a6) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101a20);
      (*pcVar1)();
    }
    uVar2 = (**(code **)(md_core_0 + 0x30))();
  }
  return uVar2;
}



//------------------------------------------------------------
// msm_minidump_update_region @ 00101a3c size=216
// signature: undefined msm_minidump_update_region(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_minidump_update_region(int param_1,char *param_2)

{
  code *pcVar1;
  size_t sVar2;
  undefined8 uVar3;
  
  if ((param_2 != (char *)0x0) && ((md_init_done & 1) != 0)) {
    sVar2 = strnlen(param_2,0xd);
    if (0xd < sVar2) {
                    /* WARNING: Subroutine does not return */
      fortify_panic("strnlen");
    }
    if (sVar2 == 0xd) {
                    /* WARNING: Subroutine does not return */
      fortify_panic("__fortify_strlen");
    }
    if ((*(long *)(param_2 + 0x18) == 0) || ((param_2[0x28] & 3U) != 0)) {
      _printk_deferred("Invalid entry details\n");
    }
    else if ((param_1 < 0xc9) && (md_core_0 != 0)) {
      if (*(int *)(*(code **)(md_core_0 + 0x28) + -4) != -0x48027330) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101ad4);
        (*pcVar1)();
      }
      uVar3 = (**(code **)(md_core_0 + 0x28))(param_1,param_2);
      return uVar3;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// msm_minidump_add_region @ 00101b18 size=424
// signature: undefined msm_minidump_add_region(void)
// callers: [md_register_minidump_entry, msm_minidump_log_init, dump_stack_minidump, md_register_memory_dump]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint msm_minidump_add_region(char *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined *puVar5;
  code *pcVar6;
  uint uVar7;
  size_t sVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  ulong uVar11;
  
  if (param_1 != (char *)0x0) {
    sVar8 = strnlen(param_1,0xd);
    if (0xd < sVar8) {
                    /* WARNING: Subroutine does not return */
      fortify_panic("strnlen");
    }
    if (sVar8 == 0xd) {
                    /* WARNING: Subroutine does not return */
      fortify_panic("__fortify_strlen");
    }
    if ((*(long *)(param_1 + 0x18) != 0) && ((param_1[0x28] & 3U) == 0)) {
      if ((md_core_0 != 0) && ((md_init_done & 1) != 0)) {
        if (*(int *)(*(code **)(md_core_0 + 0x20) + -4) != -0x118902f9) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x101ba4);
          (*pcVar6)();
        }
        uVar7 = (**(code **)(md_core_0 + 0x20))(param_1);
        return uVar7;
      }
      _printk(&DAT_0020b4e5);
      uVar9 = _raw_spin_lock_irqsave(&mdt_lock);
      if (md_num_regions < 0xc9) {
        puVar10 = (undefined8 *)kmalloc_trace(___kmalloc,0xb20,0x40);
        if (puVar10 != (undefined8 *)0x0) {
          uVar2 = *(undefined8 *)(param_1 + 0x18);
          uVar1 = *(undefined8 *)(param_1 + 0x20);
          uVar3 = *(undefined8 *)(param_1 + 0x28);
          puVar10[4] = *(undefined8 *)(param_1 + 0x10);
          puVar10[5] = uVar2;
          uVar2 = *(undefined8 *)param_1;
          uVar4 = *(undefined8 *)(param_1 + 8);
          puVar10[6] = uVar1;
          puVar10[7] = uVar3;
          puVar5 = PTR_pending_list_0020c3e0;
          puVar10[2] = uVar2;
          puVar10[3] = uVar4;
          uVar11 = __list_add_valid(puVar10,puVar5,&pending_list);
          if ((uVar11 & 1) != 0) {
            PTR_pending_list_0020c3e0 = (undefined *)puVar10;
            *puVar10 = &pending_list;
            puVar10[1] = puVar5;
            *(undefined8 **)puVar5 = puVar10;
          }
          uVar7 = md_num_regions;
          md_num_regions = md_num_regions + 1;
          _raw_spin_unlock_irqrestore(&mdt_lock,uVar9);
          return uVar7;
        }
      }
      else {
        _printk_deferred("Maximum entries reached\n");
      }
      _raw_spin_unlock_irqrestore(&mdt_lock,uVar9);
      return 0xfffffff4;
    }
    _printk_deferred("Invalid entry details\n");
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// msm_minidump_remove_region @ 00101cc4 size=148
// signature: undefined msm_minidump_remove_region(void)
// callers: [md_unregister_memory_dump]
//------------------------------------------------------------

int msm_minidump_remove_region(long param_1)

{
  code *pcVar1;
  int iVar2;
  
  if ((param_1 == 0) || ((md_init_done & 1) == 0)) {
    iVar2 = -0x16;
  }
  else {
    if (md_core_0 == 0) {
      iVar2 = -0x16;
    }
    else {
      if (*(int *)(*(code **)(md_core_0 + 0x18) + -4) != -0x118902f9) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101d20);
        (*pcVar1)();
      }
      iVar2 = (**(code **)(md_core_0 + 0x18))(param_1);
      if (iVar2 == 0) {
        return 0;
      }
    }
    _printk_deferred("Failed to remove region:%s\n",param_1);
  }
  return iVar2;
}



//------------------------------------------------------------
// msm_minidump_driver_probe @ 00101d5c size=856
// signature: undefined msm_minidump_driver_probe(void)
// callers: [minidump_smem_driver_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int msm_minidump_driver_probe(long *param_1)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  undefined8 *puVar4;
  long lVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  ulong uVar9;
  char *__s;
  size_t sVar10;
  undefined8 *puVar11;
  undefined4 uVar12;
  
  uVar9 = debug_symbol_available();
  if ((uVar9 & 1) == 0) {
    iVar7 = -0x205;
  }
  else {
    md_core_0 = (undefined8 *)*param_1;
    if (*(int *)((code *)*md_core_0 + -4) != 0x36b1c5a6) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x101dd0);
      (*pcVar6)();
    }
    iVar7 = (*(code *)*md_core_0)();
    if (iVar7 == 0) {
      __s = (char *)debug_symbol_lookup_name("linux_banner");
      sVar10 = strlen(__s);
      uVar9 = (ulong)(((uint)sVar10 & 0xfffffffc) + 0x6cec);
      puVar11 = (undefined8 *)__kmalloc(uVar9,0xdc0);
      minidump_elfheader = puVar11;
      if (puVar11 == (undefined8 *)0x0) {
        iVar7 = -0xc;
      }
      else {
        *puVar11 = 0x10102464c457f;
        *(undefined4 *)((long)puVar11 + 0x34) = 0x380040;
        puVar11[2] = 0x100b70004;
        puVar11[4] = 0x3280;
        puVar11[5] = 0x40;
        *(undefined2 *)((long)puVar11 + 0x3a) = 0x40;
        *(undefined2 *)((long)puVar11 + 0x3e) = 1;
        *(undefined4 *)((long)puVar11 + 0x84) = 3;
        DAT_00108820 = puVar11 + 8;
        puVar11[0x13] = 0x5e78;
        puVar11[0x14] = 0xc90;
        puVar4 = minidump_elfheader;
        puVar11[0x17] = 0;
        DAT_00108828 = puVar11 + 0x650;
        puVar11[0x11] = 0;
        DAT_00108838 = 1;
        DAT_00108830 = uVar9;
        if (((ulong)*(ushort *)((long)puVar4 + 0x3e) == 0) ||
           (lVar1 = (long)puVar4 +
                    *(long *)((long)puVar4 +
                             (ulong)*(ushort *)((long)puVar4 + 0x3e) * 0x40 + puVar4[5] + 0x18),
           lVar1 == 0)) {
          uVar12 = 0;
        }
        else {
          uVar12 = 1;
          iVar7 = strscpy(lVar1 + 1,"STR_TBL",8);
          DAT_00108838 = (long)(iVar7 + 2);
        }
        *(undefined4 *)(puVar11 + 0x10) = uVar12;
        strscpy(puVar11 + 0xd61,__s,0xc90);
        *(undefined4 *)((long)puVar11 + 0xc4) = 1;
        puVar11[0x1b] = 0x6b08;
        sVar10 = strlen(__s);
        puVar4 = minidump_elfheader;
        puVar11[0x1f] = 0;
        puVar11[0x19] = 1;
        puVar11[0x1a] = __s;
        puVar11[0x1c] = sVar10 + 1;
        if (((ulong)*(ushort *)((long)puVar4 + 0x3e) == 0) ||
           (lVar1 = (long)puVar4 +
                    *(long *)((long)puVar4 +
                             (ulong)*(ushort *)((long)puVar4 + 0x3e) * 0x40 + puVar4[5] + 0x18),
           lVar1 == 0)) {
          iVar7 = 0;
        }
        else {
          iVar7 = (int)DAT_00108838;
          iVar8 = strscpy(lVar1 + iVar7,"linux_banner",0xd);
          DAT_00108838 = (long)(iVar8 + iVar7 + 1);
        }
        lVar3 = ((long)__s << 8) >> 8;
        uVar2 = lVar3 + 0x8000000000;
        *(int *)(puVar11 + 0x18) = iVar7;
        lVar5 = _kimage_voffset;
        lVar1 = _memstart_addr;
        puVar11[0x652] = __s;
        lVar1 = lVar1 + uVar2;
        if (uVar2 >> 0x26 != 0) {
          lVar1 = lVar3 - lVar5;
        }
        *(undefined4 *)(puVar11 + 0x650) = 1;
        puVar11[0x651] = 0x6b08;
        puVar11[0x653] = lVar1;
        sVar10 = strlen(__s);
        puVar4 = md_core_0;
        *(undefined2 *)(puVar11 + 7) = 1;
        *(undefined4 *)((long)puVar11 + 0x3284) = 6;
        puVar11[0x655] = sVar10 + 1;
        puVar11[0x654] = sVar10 + 1;
        if (puVar4 != (undefined8 *)0x0) {
          pcVar6 = (code *)puVar4[2];
          if (*(int *)(pcVar6 + -4) != -0x3eea980e) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102044);
            (*pcVar6)();
          }
          (*pcVar6)(puVar11 + 0x18,puVar11,uVar9);
          md_init_done = 1;
          if (*(int *)((code *)md_core_0[1] + -4) != 0x1f2096a7) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102080);
            (*pcVar6)();
          }
          iVar7 = (*(code *)md_core_0[1])(&pending_list);
          if (iVar7 == 0) {
            msm_minidump_log_init();
            _printk(&DAT_0020b8ea,200);
            return 0;
          }
          _printk(&DAT_0020c1fc);
          return iVar7;
        }
        iVar7 = -0x16;
      }
      _printk(&DAT_0020ba65);
    }
    else {
      _printk(&DAT_0020c0cb);
    }
  }
  return iVar7;
}



//------------------------------------------------------------
// dump_stack_minidump @ 001020b8 size=592
// signature: undefined dump_stack_minidump(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void dump_stack_minidump(long *param_1)

{
  ulong uVar1;
  ulong uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  int iVar8;
  ulong uVar9;
  uint uVar10;
  long local_d0 [14];
  
  lVar7 = sp_el0;
  lVar6 = sp_el0;
  local_d0[0xd] = *(long *)(lVar7 + 0x638);
  local_d0[0xb] = 0;
  local_d0[0xc] = 0;
  local_d0[9] = 0;
  local_d0[10] = 0;
  local_d0[7] = 0;
  local_d0[8] = 0;
  local_d0[5] = 0;
  local_d0[6] = 0;
  local_d0[3] = 0;
  local_d0[4] = 0;
  local_d0[1] = 0;
  local_d0[2] = 0;
  lVar7 = tpidr_el1;
  if ((*(byte *)(lVar6 + 0x44) >> 1 & 1) == 0) {
    uVar3 = *(undefined4 *)(&cpu_number + lVar7);
    is_vmap_stack = '\x01';
    if ((undefined1 *)((long)param_1 + 0xff) < (undefined1 *)0xffffffc0080000ff) {
      param_1 = local_d0;
    }
    lVar7 = *(long *)(lVar6 + 0xbb0);
    uVar9 = (ulong)param_1 & 0xfffffffffffff000;
    uVar2 = *(ulong *)(lVar7 + 8);
    uVar1 = *(ulong *)(lVar7 + 0x10) - 0x1000;
    if ((*(byte *)(lVar7 + 0x18) & 0x40) != 0) {
      uVar1 = *(ulong *)(lVar7 + 0x10);
    }
    local_d0[0] = lVar6;
    if (((uVar2 <= uVar9) && (uVar9 < uVar2 + (uVar1 & 0xffffffff))) &&
       (iVar5 = (int)(uVar9 - uVar2 >> 0xc), iVar8 = (int)(uVar1 >> 0xc), iVar8 != iVar5)) {
      uVar10 = 0;
      lVar7 = ((ulong)param_1 & 0xfffffffffff000) << 8;
      do {
        scnprintf(local_d0 + 7,0xd,"KSTACK%d_%d",uVar3,uVar10);
        local_d0[0xc] = 0x1000;
        local_d0[10] = uVar9;
        if (is_vmap_stack == '\x01') {
          lVar6 = vmalloc_to_page(uVar9);
          local_d0[0xb] = (lVar6 + (_memstart_addr >> 0xc) * 0x40) * 0x40 + 0x8000000000;
        }
        else {
          uVar1 = (lVar7 >> 8) + 0x8000000000;
          local_d0[0xb] = _memstart_addr + uVar1;
          if (uVar1 >> 0x26 != 0) {
            local_d0[0xb] = (lVar7 >> 8) - _kimage_voffset;
          }
        }
        iVar4 = msm_minidump_add_region(local_d0 + 7);
        if (iVar4 < 0) {
          _printk_deferred("Failed to add stack of entry %s in Minidump\n",local_d0 + 7);
        }
        uVar9 = uVar9 + 0x1000;
        uVar10 = uVar10 + 1;
        lVar7 = lVar7 + 0x100000;
      } while (uVar10 < (uint)(iVar8 - iVar5));
    }
    scnprintf(local_d0 + 1,0xd,"KTASK%d",uVar3);
    lVar7 = (local_d0[0] << 8) >> 8;
    uVar9 = lVar7 + 0x8000000000;
    local_d0[5] = _memstart_addr + uVar9;
    if (uVar9 >> 0x26 != 0) {
      local_d0[5] = lVar7 - _kimage_voffset;
    }
    local_d0[4] = local_d0[0];
    local_d0[6] = 0x12c0;
    iVar5 = msm_minidump_add_region(local_d0 + 1);
    if (iVar5 < 0) {
      _printk(&DAT_0020bd55,uVar3);
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_d0[0xd]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// md_dump_process @ 0010230c size=2096
// signature: undefined md_dump_process(void)
// callers: [md_panic_handler]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void md_dump_process(void)

{
  long *plVar1;
  ulong *puVar2;
  long lVar3;
  char cVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  int iVar8;
  code *pcVar9;
  bool bVar10;
  uint uVar11;
  long lVar12;
  undefined8 uVar13;
  undefined8 in_x3;
  undefined8 in_x4;
  undefined8 in_x5;
  undefined8 in_x6;
  undefined8 in_x7;
  uint uVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  ulong uVar18;
  int iVar19;
  undefined8 *puVar20;
  undefined8 *puVar21;
  long *plVar22;
  undefined8 *puVar23;
  undefined1 auStack_240 [128];
  void *local_1c0 [2];
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined *puStack_128;
  undefined1 *local_120;
  
  lVar15 = sp_el0;
  lVar15 = *(long *)(lVar15 + 0x638);
  if ((md_in_oops_handler & 1) == 0) {
    iVar19 = md_handle_done;
    do {
      if (iVar19 == 1) goto LAB_00102b10;
      Hint_Prefetch(0x10884c,2,0,1);
      do {
        iVar8 = md_handle_done;
        if (md_handle_done != iVar19) goto LAB_0010237c;
        cVar4 = '\x01';
        bVar10 = (bool)ExclusiveMonitorPass(0x10884c,0x10);
        if (bVar10) {
          cVar4 = ExclusiveMonitorsStatus();
          md_handle_done = iVar19 + 1;
        }
      } while (cVar4 != '\0');
      DataMemoryBarrier(2,3);
LAB_0010237c:
      bVar10 = iVar19 != iVar8;
      iVar19 = iVar8;
    } while (bVar10);
    md_in_oops_handler = 1;
    if (md_cntxt_seq_buf != 0) {
      lVar12 = tpidr_el1;
      if (*(int *)(&cpu_number + lVar12) != die_cpu) {
        uVar13 = 0x150;
        local_1c0[0] = memset(local_1c0,0,0x150);
        puStack_128 = &cpu_number;
        uVar6 = currentel;
        uVar18 = spsel;
        uVar5 = daif;
        uVar7 = nzcv;
        lVar12 = tpidr_el1;
        local_1b0 = uVar13;
        uStack_1a8 = in_x3;
        local_1a0 = in_x4;
        uStack_198 = in_x5;
        local_190 = in_x6;
        uStack_188 = in_x7;
        local_120 = (undefined1 *)local_1c0;
        seq_buf_printf(md_cntxt_seq_buf,"PANIC CPU : %d\n",*(undefined4 *)(&cpu_number + lVar12));
        if (((uVar6 | uVar18 | uVar5 | uVar7) & 0xf) != 0) {
          md_dump_data(0x1023dc,&DAT_0020c0f9);
          md_dump_data(&LAB_00102378,&DAT_0020b52b);
          md_dump_data(auStack_240,&DAT_0020b52e);
        }
      }
      iVar19 = 0;
      while (uVar11 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar19),
            uVar11 < _nr_cpu_ids) {
        if ((uVar11 & 0xffffffe0) != 0) goto LAB_00102b48;
        lVar16 = *(long *)(&__per_cpu_offset + (ulong)uVar11 * 8);
        lVar12 = *(long *)(&DAT_0020d750 + lVar16);
        lVar3 = *(long *)(&DAT_0020d758 + lVar16);
        lVar17 = *(long *)(&DAT_0020d760 + lVar16);
        uVar18 = *(ulong *)(&DAT_0020d768 + lVar16);
        seq_buf_printf(md_cntxt_seq_buf,"\nSTOPPED CPU : %d\n",uVar11);
        if ((uVar18 & 0xf) != 0 && lVar17 != 0) {
          md_dump_data(lVar17 + -0x80,&DAT_0020c0f9);
          md_dump_data(lVar12 + -0x80,&DAT_0020b52b);
          md_dump_data(lVar3 + -0x80,&DAT_0020b52e);
        }
        iVar19 = uVar11 + 1;
      }
    }
    lVar12 = debug_symbol_lookup_name("tick_cpu_device");
    if (lVar12 != 0) {
      iVar19 = 0;
      while (uVar11 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar19),
            uVar11 < _nr_cpu_ids) {
        if ((uVar11 & 0xffffffe0) != 0) goto LAB_00102b48;
        if (*(long *)(*(long *)(&__per_cpu_offset + (ulong)uVar11 * 8) + lVar12) == 0) {
          _printk(&DAT_0020b863,uVar11);
          iVar19 = uVar11 + 1;
        }
        else {
          _printk(&DAT_0020b1b3,uVar11,
                  *(undefined8 *)
                   (*(long *)(*(long *)(&__per_cpu_offset + (ulong)uVar11 * 8) + lVar12) + 0x18));
          iVar19 = uVar11 + 1;
        }
      }
    }
    if (md_runq_seq_buf != 0) {
      iVar19 = 0;
      while (uVar11 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar19),
            uVar11 < _nr_cpu_ids) {
        if ((uVar11 & 0xffffffe0) != 0) {
LAB_00102b48:
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x5512,0x102b4c);
          (*pcVar9)();
        }
        lVar12 = (ulong)uVar11 * 8;
        lVar17 = *(long *)(&__per_cpu_offset + lVar12);
        puVar2 = (ulong *)(lVar17 + 0x210468);
        seq_buf_printf(md_runq_seq_buf,"CPU%d has %d process, current is pid %d\n",uVar11,
                       *(undefined4 *)(&DAT_002100ec + lVar17),
                       *(undefined4 *)(*(long *)(lVar17 + 0x210b88) + 0x630));
        seq_buf_printf(md_runq_seq_buf,"CFS has %d process\n",
                       *(undefined4 *)(get_each_object_track + lVar17));
        md_dump_cfs_rq(page_ext_put + lVar17,
                       *(undefined8 *)(*(long *)(&__per_cpu_offset + lVar12) + 0x210b88));
        seq_buf_printf(md_runq_seq_buf,"RT has %d process\n",*(undefined4 *)(lVar17 + 0x210ab8));
        uVar13 = *(undefined8 *)(*(long *)(&__per_cpu_offset + lVar12) + 0x210b88);
        lVar12 = _find_first_bit(puVar2,100);
        if (lVar12 != 100) {
          uVar18 = *puVar2;
          if (uVar18 == 0) {
            uVar18 = (*(ulong *)(lVar17 + 0x210470) & 0xaaaaaaaaaaaaaaaa) >> 1 |
                     (*(ulong *)(lVar17 + 0x210470) & 0x5555555555555555) << 1;
            uVar18 = (uVar18 & 0xcccccccccccccccc) >> 2 | (uVar18 & 0x3333333333333333) << 2;
            uVar18 = (uVar18 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar18 & 0xf0f0f0f0f0f0f0f) << 4;
            uVar18 = (uVar18 & 0xff00ff00ff00ff00) >> 8 | (uVar18 & 0xff00ff00ff00ff) << 8;
            uVar18 = (uVar18 & 0xffff0000ffff0000) >> 0x10 | (uVar18 & 0xffff0000ffff) << 0x10;
            uVar14 = (uint)LZCOUNT(uVar18 >> 0x20 | uVar18 << 0x20);
            if (0x23 < uVar14) goto LAB_00102644;
            uVar18 = (ulong)(uVar14 + 0x40);
          }
          else {
            uVar18 = (uVar18 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar18 & 0x5555555555555555) << 1;
            uVar18 = (uVar18 & 0xcccccccccccccccc) >> 2 | (uVar18 & 0x3333333333333333) << 2;
            uVar18 = (uVar18 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar18 & 0xf0f0f0f0f0f0f0f) << 4;
            uVar18 = (uVar18 & 0xff00ff00ff00ff00) >> 8 | (uVar18 & 0xff00ff00ff00ff) << 8;
            uVar18 = (uVar18 & 0xffff0000ffff0000) >> 0x10 | (uVar18 & 0xffff0000ffff) << 0x10;
            uVar18 = LZCOUNT(uVar18 >> 0x20 | uVar18 << 0x20);
          }
          do {
            plVar1 = (long *)(lVar17 + 0x210478 + (long)(int)uVar18 * 0x10);
            for (plVar22 = (long *)*plVar1; plVar22 != plVar1; plVar22 = (long *)*plVar22) {
              md_dump_task_info(plVar22 + -0x40,&DAT_0020b5ee,uVar13);
            }
            uVar18 = _find_next_bit(puVar2,100,(long)((int)uVar18 + 1));
          } while ((int)uVar18 < 100);
        }
LAB_00102644:
        seq_buf_printf(md_runq_seq_buf,&DAT_0020bef7);
        iVar19 = uVar11 + 1;
      }
      seq_buf_printf(md_runq_seq_buf,"%-15s","Task name");
      seq_buf_printf(md_runq_seq_buf,&DAT_0020b95c,6,&DAT_0020b588);
      seq_buf_printf(md_runq_seq_buf,&DAT_0020b95c,0x10,"Exec_started_at");
      seq_buf_printf(md_runq_seq_buf,&DAT_0020b95c,0x10,"Last_queued_at");
      seq_buf_printf(md_runq_seq_buf,&DAT_0020b95c,0x10,"Total_wait_time");
      seq_buf_printf(md_runq_seq_buf,&DAT_0020b95c,0xc,"Exec_times");
      seq_buf_printf(md_runq_seq_buf,&DAT_0020b95c,4,&DAT_0020bd82);
      seq_buf_printf(md_runq_seq_buf,&DAT_0020b95c,5,&DAT_0020b1ce);
      seq_buf_printf(md_runq_seq_buf,&DAT_0020b95c,6,"State");
      seq_buf_printf(md_runq_seq_buf,&DAT_0020b95c,0x11,"Last_enqueued_ts");
      seq_buf_printf(md_runq_seq_buf,&DAT_0020b95c,0x10,"Last_sleep_ts");
      seq_buf_printf(md_runq_seq_buf,&DAT_0020bef7);
      puVar21 = _DAT_00210648;
      if (_DAT_00210648 != (undefined8 *)&DAT_00210648) {
        do {
          lVar12 = puVar21[0x68];
          puVar20 = (undefined8 *)(lVar12 + 0x10);
          for (puVar23 = (undefined8 *)*puVar20; puVar23 != puVar20;
              puVar23 = (undefined8 *)*puVar23) {
            if (*(uint *)(puVar23 + -0xd8) == 0) {
              seq_buf_printf(md_runq_seq_buf,"%-15s",puVar23 + 0x2b);
              seq_buf_printf(md_runq_seq_buf,&DAT_0020bc01,*(undefined4 *)(puVar23 + -0x18));
              seq_buf_printf(md_runq_seq_buf,"%16lld",puVar23[-0x36]);
              seq_buf_printf(md_runq_seq_buf,"%16lld",puVar23[-0x35]);
              seq_buf_printf(md_runq_seq_buf,"%16lld",puVar23[-0x37]);
              seq_buf_printf(md_runq_seq_buf,"%12ld",puVar23[-0x38]);
              seq_buf_printf(md_runq_seq_buf,&DAT_0020b53b,*(undefined4 *)((long)puVar23 + -0x6a4));
              seq_buf_printf(md_runq_seq_buf,&DAT_0020bd86,*(undefined4 *)((long)puVar23 + -0x66c));
              uVar14 = *(uint *)(puVar23 + -0xd8);
              uVar11 = 0x80;
              if (uVar14 != 0x402) {
                uVar11 = (*(uint *)((long)puVar23 + -300) | uVar14) & 0x7f;
              }
              uVar14 = 0;
              if (uVar11 != 0) {
                uVar14 = 0x20 - (int)LZCOUNT(uVar11);
              }
              if (8 < uVar14) goto LAB_00102b48;
              seq_buf_printf(md_runq_seq_buf,&DAT_0020b95c,6,(&task_state_array)[uVar14]);
              seq_buf_printf(md_runq_seq_buf,"%17ld",puVar23[0xbb]);
              seq_buf_printf(md_runq_seq_buf,"%16ld",puVar23[0xb8]);
              seq_buf_printf(md_runq_seq_buf,&DAT_0020bef7);
              lVar12 = puVar21[0x68];
            }
            puVar20 = (undefined8 *)(lVar12 + 0x10);
          }
          puVar21 = (undefined8 *)*puVar21;
        } while (puVar21 != (undefined8 *)&DAT_00210648);
      }
    }
    if (md_meminfo_seq_buf != 0) {
      md_dump_meminfo();
    }
    if (md_slabinfo_seq_buf != 0) {
      md_dump_slabinfo();
    }
    if (md_pageowner_dump_addr != 0) {
      md_dump_pageowner(md_pageowner_dump_addr,md_pageowner_dump_size);
    }
    if (md_slabowner_dump_addr != 0) {
      md_dump_slabowner(md_slabowner_dump_addr,md_slabowner_dump_size);
    }
    if (md_dma_buf_info_addr != 0) {
      md_dma_buf_info(md_dma_buf_info_addr,md_dma_buf_info_size);
    }
    if (md_dma_buf_procs_addr != 0) {
      md_dma_buf_procs(md_dma_buf_procs_addr,md_dma_buf_procs_size);
    }
    md_in_oops_handler = 0;
  }
LAB_00102b10:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != lVar15) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_minidump_log_init @ 00102b54 size=2220
// signature: undefined msm_minidump_log_init(void)
// callers: [msm_minidump_driver_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 msm_minidump_log_init(void)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  undefined *puVar8;
  long lVar9;
  long *plVar10;
  undefined8 uVar11;
  long *plVar12;
  uint local_ec;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  ulong local_d0;
  long local_c8;
  ulong local_c0;
  long local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  long local_a0;
  long local_98;
  ulong local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar9 = sp_el0;
  local_58 = *(long *)(lVar9 + 0x638);
  local_98 = 0;
  local_90 = 0;
  local_a8 = 0;
  local_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  lVar5 = debug_symbol_lookup_name("_sdata");
  lVar6 = debug_symbol_lookup_name("__bss_stop");
  debug_symbol_lookup_name("__per_cpu_start");
  debug_symbol_lookup_name("__per_cpu_end");
  strscpy(&local_b8,"KDATABSS",9);
  lVar9 = (lVar5 << 8) >> 8;
  uVar1 = lVar9 + 0x8000000000;
  uVar7 = (lVar6 - lVar5) + 3;
  local_98 = _memstart_addr + uVar1;
  if (uVar1 >> 0x26 != 0) {
    local_98 = lVar9 - _kimage_voffset;
  }
  local_90 = (lVar6 - lVar5) + 6;
  if (-1 < (long)uVar7) {
    local_90 = uVar7;
  }
  local_90 = local_90 & 0xfffffffffffffffc;
  local_a0 = lVar5;
  iVar3 = msm_minidump_add_region(&local_b8);
  if (iVar3 < 0) {
    _printk(&DAT_0020bda5);
  }
  lVar5 = debug_symbol_lookup_name("__start_ro_after_init");
  lVar6 = debug_symbol_lookup_name("__end_ro_after_init");
  strscpy(&local_b8,"KROAIDATA",10);
  lVar9 = (lVar5 << 8) >> 8;
  uVar7 = lVar9 + 0x8000000000;
  local_98 = _memstart_addr + uVar7;
  if (uVar7 >> 0x26 != 0) {
    local_98 = lVar9 - _kimage_voffset;
  }
  uVar7 = (lVar6 - lVar5) + 3;
  local_90 = (lVar6 - lVar5) + 6;
  if (-1 < (long)uVar7) {
    local_90 = uVar7;
  }
  local_90 = local_90 & 0xfffffffffffffffc;
  local_a0 = lVar5;
  iVar3 = msm_minidump_add_region(&local_b8);
  if (iVar3 < 0) {
    _printk(&DAT_0020b013);
  }
  local_68 = 0;
  uStack_60 = 0;
  is_vmap_stack = 1;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  local_90 = 0;
  local_a8 = 0;
  local_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_ec = 0;
  local_c8 = 0;
  local_c0 = 0;
  local_d8 = 0;
  local_d0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  uVar7 = of_find_compatible_node(0,0,"ramoops");
  puVar8 = &DAT_0020b7ae;
  if ((uVar7 != 0) && (uVar7 < 0xfffffffffffff001)) {
    plVar10 = &local_b8;
    iVar3 = of_address_to_resource(uVar7,0,&local_b8);
    if (iVar3 != 0) {
      lVar9 = of_reserved_mem_lookup(uVar7);
      if (lVar9 == 0) {
        puVar8 = &DAT_0020b91d;
        goto LAB_00102f14;
      }
      plVar10 = (long *)(lVar9 + 0x20);
    }
    lVar9 = *plVar10;
    iVar3 = of_property_read_variable_u32_array(uVar7,"record-size",&local_ec,1,0);
    if ((-1 < iVar3) && (local_ec != 0)) {
      strscpy(&local_e8,"KDMESG",7);
      local_c0 = (ulong)local_ec;
      local_d0 = lVar9 - _memstart_addr | 0xffffff8000000000;
      local_c8 = lVar9;
      iVar3 = msm_minidump_add_region(&local_e8);
      if (iVar3 < 0) {
        _printk(&DAT_0020b2e4);
      }
      lVar9 = lVar9 + (ulong)local_ec;
    }
    iVar3 = of_property_read_variable_u32_array(uVar7,"console-size",&local_ec,1,0);
    if ((-1 < iVar3) && (local_ec != 0)) {
      strscpy(&local_e8,"KCONSOLE",9);
      local_c0 = (ulong)local_ec;
      local_d0 = lVar9 - _memstart_addr | 0xffffff8000000000;
      local_c8 = lVar9;
      iVar3 = msm_minidump_add_region(&local_e8);
      if (iVar3 < 0) {
        _printk(&DAT_0020b25a);
      }
      lVar9 = lVar9 + (ulong)local_ec;
    }
    iVar3 = of_property_read_variable_u32_array(uVar7,"ftrace-size",&local_ec,1,0);
    if ((-1 < iVar3) && (local_ec != 0)) {
      strscpy(&local_e8,"KFTRACE",8);
      local_c0 = (ulong)local_ec;
      local_d0 = lVar9 - _memstart_addr | 0xffffff8000000000;
      local_c8 = lVar9;
      iVar3 = msm_minidump_add_region(&local_e8);
      if (iVar3 < 0) {
        _printk(&DAT_0020b960);
      }
      lVar9 = lVar9 + (ulong)local_ec;
    }
    iVar3 = of_property_read_variable_u32_array(uVar7,"pmsg-size",&local_ec,1,0);
    if ((iVar3 < 0) || (local_ec == 0)) goto LAB_00102f18;
    strscpy(&local_e8,"KPMSG",6);
    local_c0 = (ulong)local_ec;
    local_d0 = lVar9 - _memstart_addr | 0xffffff8000000000;
    local_c8 = lVar9;
    iVar3 = msm_minidump_add_region(&local_e8);
    if (-1 < iVar3) goto LAB_00102f18;
    puVar8 = &DAT_0020b0e9;
  }
LAB_00102f14:
  _printk(puVar8);
LAB_00102f18:
  local_98 = 0;
  local_90 = 0;
  local_a8 = 0;
  local_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  lVar9 = kmalloc_large(0x200000,0xdc0);
  if (lVar9 != 0) {
    strscpy(&local_b8,"KFTRACE",8);
    lVar5 = (lVar9 << 8) >> 8;
    uVar7 = lVar5 + 0x8000000000;
    local_98 = _memstart_addr + uVar7;
    if (uVar7 >> 0x26 != 0) {
      local_98 = lVar5 - _kimage_voffset;
    }
    local_90 = 0x200000;
    local_a0 = lVar9;
    iVar3 = msm_minidump_add_region(&local_b8);
    if (iVar3 < 0) {
      _printk(&DAT_0020bf70);
    }
    tracepoint_probe_register(&__tracepoint_android_vh_ftrace_oops_enter,md_trace_oops_enter,0);
    tracepoint_probe_register(&__tracepoint_android_vh_ftrace_oops_exit,md_trace_oops_exit,0);
    tracepoint_probe_register(&__tracepoint_android_vh_ftrace_size_check,md_buf_size_check,0);
    tracepoint_probe_register(&__tracepoint_android_vh_ftrace_format_check,md_update_trace_fmt,0);
    tracepoint_probe_register(&__tracepoint_android_vh_ftrace_dump_buffer,md_dump_trace_buf,0);
    DataMemoryBarrier(2,3);
    md_ftrace_buf_addr = lVar9;
  }
  iVar3 = 0;
  local_98 = 0;
  local_90 = 0;
  local_a8 = 0;
  local_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  while (uVar4 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar3), uVar4 < _nr_cpu_ids)
  {
    if ((uVar4 & 0xffffffe0) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1033fc);
      (*pcVar2)();
    }
    if (max_cluster < *(int *)(&__tracepoint_android_vh_cpufreq_resolve_freq + (ulong)uVar4 * 0x38))
    {
      max_cluster = *(int *)(&__tracepoint_android_vh_cpufreq_resolve_freq + (ulong)uVar4 * 0x38);
    }
    iVar3 = uVar4 + 1;
  }
  lVar5 = (long)(max_cluster + 1) * 0x108;
  cpuclk_log = __kmalloc(lVar5,0xdc0);
  strscpy(&local_b8,"FREQ_LOG",9);
  lVar9 = (cpuclk_log << 8) >> 8;
  uVar7 = lVar9 + 0x8000000000;
  local_98 = uVar7 + _memstart_addr;
  if (uVar7 >> 0x26 != 0) {
    local_98 = lVar9 - _kimage_voffset;
  }
  local_a0 = cpuclk_log;
  local_90 = lVar5;
  iVar3 = msm_minidump_add_region(&local_b8);
  if (iVar3 < 0) {
    _printk(&DAT_0020b0e9);
  }
  tracepoint_probe_register(&__tracepoint_android_vh_cpufreq_resolve_freq,log_cpu_freq,0);
  tracepoint_probe_register(&__tracepoint_android_vh_cpufreq_fast_switch,log_cpu_freq,0);
  tracepoint_probe_register(&__tracepoint_android_vh_cpufreq_target,log_cpu_freq,0);
  iVar3 = md_register_panic_entries(8,"KMODULES",&md_mod_info_seq_buf);
  if (iVar3 == 0) {
    seq_buf_printf(md_mod_info_seq_buf,"=== MODULE INFO ===\n");
    iVar3 = register_module_notifier(&md_module_nb);
    if (iVar3 == 0) {
      plVar10 = (long *)debug_symbol_lookup_name("modules");
      if ((plVar10 != (long *)0x0) && (plVar10 < (long *)0xfffffffffffff001)) {
        lVar9 = sp_el0;
        *(int *)(lVar9 + 0x10) = *(int *)(lVar9 + 0x10) + 1;
        for (plVar12 = (long *)*plVar10; plVar12 != plVar10; plVar12 = (long *)*plVar12) {
          if (plVar12 != (long *)0x20d888) {
            md_module_process();
          }
        }
        lVar5 = *(long *)(lVar9 + 0x10) + -1;
        *(int *)(lVar9 + 0x10) = (int)lVar5;
        if ((lVar5 == 0) || (*(long *)(lVar9 + 0x10) == 0)) {
          preempt_schedule();
        }
      }
    }
    else {
      _printk(&DAT_0020b755);
    }
  }
  else {
    _printk(&DAT_0020bf03);
  }
  iVar3 = md_minidump_memory_init();
  if (iVar3 == 0) {
    md_register_panic_entries(1,"MEMINFO",&md_meminfo_seq_buf);
    md_register_panic_entries(8,"SLABINFO",&md_slabinfo_seq_buf);
    uVar11 = debugfs_create_dir("minidump",0);
    uVar7 = is_page_owner_enabled();
    if ((uVar7 & 1) != 0) {
      md_register_memory_dump((undefined4)md_pageowner_dump_size,"PAGEOWNER");
      md_debugfs_pageowner(uVar11);
    }
    uVar7 = is_slub_debug_enabled();
    if ((uVar7 & 1) != 0) {
      md_register_memory_dump((undefined4)md_slabowner_dump_size,"SLABOWNER");
      md_debugfs_slabowner(uVar11);
    }
    md_register_memory_dump((undefined4)md_dma_buf_info_size,"DMA_INFO");
    md_debugfs_dmabufinfo(uVar11);
    md_register_memory_dump((undefined4)md_dma_buf_procs_size,"DMA_PROC");
    md_debugfs_dmabufprocs(uVar11);
    md_register_panic_entries(0x20,"KCNTXT",&md_cntxt_seq_buf);
    tracepoint_probe_register(&__tracepoint_android_vh_ipi_stop,md_ipi_stop,0);
    md_register_panic_entries(8,"KRUNQUEUE",&md_runq_seq_buf);
  }
  else {
    _printk(&DAT_0020bc05,iVar3);
  }
  atomic_notifier_chain_register(&panic_notifier_list,&md_panic_blk);
  register_die_notifier(&md_die_context_nb);
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// md_dump_data @ 00103400 size=724
// signature: undefined md_dump_data(void)
// callers: [md_dump_process, md_die_context_notify]
//------------------------------------------------------------

void md_dump_data(ulong param_1,undefined8 param_2)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  undefined4 local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  if (0xffffff80000000fe < param_1 + 0xff) {
    seq_buf_printf(md_cntxt_seq_buf,"\n%s: %#lx:\n",param_2,param_1);
    uVar2 = param_1 & 0xfffffffffffffffc;
    uVar4 = ((uint)param_1 & 3) + 0x11f >> 5;
    uVar3 = uVar2;
    do {
      seq_buf_printf(md_cntxt_seq_buf,"%04lx ",uVar3 & 0xffff);
      local_5c = 0;
      lVar1 = copy_from_kernel_nofault(&local_5c,uVar2,4);
      if (lVar1 == 0) {
        seq_buf_printf(md_cntxt_seq_buf," %08x",local_5c);
      }
      else {
        seq_buf_printf(md_cntxt_seq_buf," ********");
      }
      local_5c = 0;
      lVar1 = copy_from_kernel_nofault(&local_5c,uVar2 + 4,4);
      if (lVar1 == 0) {
        seq_buf_printf(md_cntxt_seq_buf," %08x",local_5c);
      }
      else {
        seq_buf_printf(md_cntxt_seq_buf," ********");
      }
      local_5c = 0;
      lVar1 = copy_from_kernel_nofault(&local_5c,uVar2 + 8,4);
      if (lVar1 == 0) {
        seq_buf_printf(md_cntxt_seq_buf," %08x",local_5c);
      }
      else {
        seq_buf_printf(md_cntxt_seq_buf," ********");
      }
      local_5c = 0;
      lVar1 = copy_from_kernel_nofault(&local_5c,uVar2 + 0xc,4);
      if (lVar1 == 0) {
        seq_buf_printf(md_cntxt_seq_buf," %08x",local_5c);
      }
      else {
        seq_buf_printf(md_cntxt_seq_buf," ********");
      }
      local_5c = 0;
      lVar1 = copy_from_kernel_nofault(&local_5c,uVar2 + 0x10,4);
      if (lVar1 == 0) {
        seq_buf_printf(md_cntxt_seq_buf," %08x",local_5c);
      }
      else {
        seq_buf_printf(md_cntxt_seq_buf," ********");
      }
      local_5c = 0;
      lVar1 = copy_from_kernel_nofault(&local_5c,uVar2 + 0x14,4);
      if (lVar1 == 0) {
        seq_buf_printf(md_cntxt_seq_buf," %08x",local_5c);
      }
      else {
        seq_buf_printf(md_cntxt_seq_buf," ********");
      }
      local_5c = 0;
      lVar1 = copy_from_kernel_nofault(&local_5c,uVar2 + 0x18,4);
      if (lVar1 == 0) {
        seq_buf_printf(md_cntxt_seq_buf," %08x",local_5c);
      }
      else {
        seq_buf_printf(md_cntxt_seq_buf," ********");
      }
      local_5c = 0;
      lVar1 = copy_from_kernel_nofault(&local_5c,uVar2 + 0x1c,4);
      if (lVar1 == 0) {
        seq_buf_printf(md_cntxt_seq_buf," %08x",local_5c);
      }
      else {
        seq_buf_printf(md_cntxt_seq_buf," ********");
      }
      seq_buf_printf(md_cntxt_seq_buf,&DAT_0020bef7);
      uVar4 = uVar4 - 1;
      uVar3 = uVar3 + 0x20;
      uVar2 = uVar2 + 0x20;
    } while (uVar4 != 0);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// md_dump_cfs_rq @ 001036d4 size=212
// signature: undefined md_dump_cfs_rq(void)
// callers: [md_dump_process, md_dump_cgroup_state]
//------------------------------------------------------------

void md_dump_cfs_rq(long param_1,undefined8 param_2)

{
  bool bVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  
  md_dump_cgroup_state(&DAT_0020b34f,*(undefined8 *)(param_1 + 0x40),param_2);
  md_dump_cgroup_state(&DAT_0020af6a,*(undefined8 *)(param_1 + 0x48),param_2);
  md_dump_cgroup_state(&DAT_0020ba0b,*(undefined8 *)(param_1 + 0x50),param_2);
  md_dump_cgroup_state(&DAT_0020b2d5,*(undefined8 *)(param_1 + 0x58),param_2);
  lVar4 = *(long *)(param_1 + 0x38);
  lVar2 = rb_first(param_1 + 0x30);
  if ((lVar4 != 0) && (lVar2 != 0)) {
    iVar3 = -199;
    do {
      md_dump_cgroup_state(&DAT_0020b5ee,lVar2 + -0x10,param_2);
      lVar2 = rb_next(lVar2);
      if (lVar2 == 0) {
        return;
      }
      bVar1 = iVar3 != 0;
      iVar3 = iVar3 + 1;
    } while (bVar1);
  }
  return;
}



//------------------------------------------------------------
// md_dump_cgroup_state @ 001037a8 size=308
// signature: undefined md_dump_cgroup_state(void)
// callers: [md_dump_cfs_rq]
//------------------------------------------------------------

void md_dump_cgroup_state(undefined8 param_1,long param_2,undefined8 param_3)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  
  iVar2 = md_align_offset;
  if (param_2 == 0) {
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      seq_buf_printf(md_runq_seq_buf,&DAT_0020af7d);
    }
    seq_buf_printf(md_runq_seq_buf,&DAT_0020bda0);
    seq_buf_printf(md_runq_seq_buf,"%s : None(0)\n",param_1);
  }
  else {
    lVar3 = *(long *)(param_2 + 0x80);
    if (lVar3 == 0) {
      md_dump_task_info(param_2 + -0xc0,param_1,param_3);
    }
    else {
      uVar1 = *(undefined4 *)(lVar3 + 0x10);
      for (; iVar2 != 0; iVar2 = iVar2 + -1) {
        seq_buf_printf(md_runq_seq_buf,&DAT_0020af7d);
      }
      seq_buf_printf(md_runq_seq_buf,&DAT_0020bda0);
      seq_buf_printf(md_runq_seq_buf,"%s: %d process is grouping\n",param_1,uVar1);
      md_align_offset = md_align_offset + 1;
      md_dump_cfs_rq(lVar3,param_3);
      md_align_offset = md_align_offset + -1;
    }
  }
  return;
}



//------------------------------------------------------------
// md_dump_task_info @ 001038dc size=208
// signature: undefined md_dump_task_info(void)
// callers: [md_dump_process, md_dump_cgroup_state]
//------------------------------------------------------------

void md_dump_task_info(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  
  for (iVar1 = md_align_offset; iVar1 != 0; iVar1 = iVar1 + -1) {
    seq_buf_printf(md_runq_seq_buf,&DAT_0020af7d);
  }
  seq_buf_printf(md_runq_seq_buf,&DAT_0020bda0);
  if (param_1 == 0) {
    seq_buf_printf(md_runq_seq_buf,"%s : None(0)\n",param_2);
  }
  else if (param_1 == param_3) {
    seq_buf_printf(md_runq_seq_buf,"[status: curr] pid: %d preempt: %#x\n",
                   *(undefined4 *)(param_1 + 0x630),*(undefined8 *)(param_1 + 0x10));
  }
  else {
    seq_buf_printf(md_runq_seq_buf,"[status: %s] pid: %d\n",param_2);
  }
  return;
}



//------------------------------------------------------------
// md_trace_oops_enter @ 001039b0 size=32
// signature: undefined md_trace_oops_enter(void)
// callers: []
//------------------------------------------------------------

void md_trace_oops_enter(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  
  bVar1 = (minidump_ftrace_in_oops & 1) != 0;
  if (!bVar1) {
    minidump_ftrace_in_oops = 1;
  }
  *(bool *)param_2 = bVar1;
  return;
}



//------------------------------------------------------------
// md_trace_oops_exit @ 001039d4 size=12
// signature: undefined md_trace_oops_exit(void)
// callers: []
//------------------------------------------------------------

void md_trace_oops_exit(void)

{
  minidump_ftrace_in_oops = 0;
  return;
}



//------------------------------------------------------------
// md_buf_size_check @ 001039e4 size=92
// signature: undefined md_buf_size_check(void)
// callers: []
//------------------------------------------------------------

void md_buf_size_check(undefined8 param_1,ulong param_2,undefined1 *param_3)

{
  if ((minidump_ftrace_dump & 1) == 0) {
    if (param_2 < 0x41001) {
      return;
    }
    _printk(&DAT_0020c33b);
    minidump_ftrace_dump = 1;
  }
  *param_3 = 1;
  return;
}



//------------------------------------------------------------
// md_update_trace_fmt @ 00103a44 size=8
// signature: undefined md_update_trace_fmt(void)
// callers: []
//------------------------------------------------------------

void md_update_trace_fmt(undefined8 param_1,undefined1 *param_2)

{
  *param_2 = 0;
  return;
}



//------------------------------------------------------------
// md_dump_trace_buf @ 00103a50 size=152
// signature: undefined md_dump_trace_buf(void)
// callers: []
//------------------------------------------------------------

void md_dump_trace_buf(undefined8 param_1,void *param_2,undefined1 *param_3)

{
  ulong __n;
  
  if ((minidump_ftrace_in_oops == '\x01') && ((minidump_ftrace_dump & 1) == 0)) {
    __n = *(ulong *)((long)param_2 + 0x1010);
    if ((__n < 0x200001) && (md_ftrace_buf_addr != 0)) {
      if (0x200000 < md_ftrace_buf_current + __n) {
        md_ftrace_buf_current = 0;
      }
      memcpy((void *)(md_ftrace_buf_addr + md_ftrace_buf_current),param_2,__n);
      md_ftrace_buf_current = md_ftrace_buf_current + __n;
    }
    *param_3 = 0;
  }
  return;
}



//------------------------------------------------------------
// log_cpu_freq @ 00103aec size=180
// signature: undefined log_cpu_freq(void)
// callers: []
//------------------------------------------------------------

void log_cpu_freq(undefined8 param_1,long param_2,uint *param_3)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  code *pcVar6;
  undefined8 uVar7;
  uint *puVar8;
  
  if (0x1f < *(uint *)(param_2 + 0x1c)) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x103b8c);
    (*pcVar6)();
  }
  iVar2 = *(int *)(&__tracepoint_android_vh_cpufreq_resolve_freq +
                  (ulong)*(uint *)(param_2 + 0x1c) * 0x38);
  if (iVar2 <= max_cluster) {
    puVar8 = (uint *)(cpuclk_log + (long)iVar2 * 0x108);
    Hint_Prefetch(puVar8,2,0,1);
    do {
      uVar3 = *puVar8;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar8,0x10);
      if (bVar5) {
        *puVar8 = uVar3 + 1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    DataMemoryBarrier(2,3);
    uVar7 = sched_clock();
    lVar1 = cpuclk_log + (long)iVar2 * 0x108 + (ulong)(uVar3 & 0xf) * 0x10;
    *(undefined8 *)(lVar1 + 8) = uVar7;
    *(ulong *)(lVar1 + 0x10) = (ulong)*param_3;
  }
  return;
}



//------------------------------------------------------------
// md_register_panic_entries @ 00103ba8 size=244
// signature: undefined md_register_panic_entries(void)
// callers: [msm_minidump_log_init]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int md_register_panic_entries(long param_1,undefined8 param_2,undefined8 *param_3)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  int iVar5;
  long lVar6;
  long *plVar7;
  
  uVar4 = param_1 << 0xc & 0xffffffff000;
  lVar6 = __kmalloc(uVar4,0xdc0);
  if (lVar6 == 0) {
    iVar5 = -0x16;
  }
  else {
    plVar7 = (long *)kmalloc_trace(___kmalloc,0xdc0,0x20);
    if (plVar7 == (long *)0x0) {
      iVar5 = -0x16;
    }
    else {
      lVar3 = (lVar6 << 8) >> 8;
      uVar1 = lVar3 + 0x8000000000;
      lVar2 = _memstart_addr + uVar1;
      if (uVar1 >> 0x26 != 0) {
        lVar2 = lVar3 - _kimage_voffset;
      }
      iVar5 = md_register_minidump_entry(param_2,lVar6,lVar2,uVar4);
      if (-1 < iVar5) {
        plVar7[2] = 0;
        plVar7[3] = 0;
        *plVar7 = lVar6;
        plVar7[1] = param_1 << 0xc & 0xfffff000;
        DataMemoryBarrier(2,3);
        *param_3 = plVar7;
        return 0;
      }
      kfree(plVar7);
    }
    kfree(lVar6);
  }
  return iVar5;
}



//------------------------------------------------------------
// md_module_process @ 00103c9c size=928
// signature: undefined md_module_process(void)
// callers: [md_module_notify, msm_minidump_log_init]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void md_module_process(long param_1)

{
  char *pcVar1;
  ulong uVar2;
  code *pcVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ulong uVar8;
  uint uVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  char local_78 [16];
  long local_68;
  
  iVar7 = n_modump;
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  if (n_modump < 1) {
    bVar4 = false;
LAB_00103e90:
    if (md_mod_info_seq_buf != 0) {
      pcVar1 = (char *)(param_1 + 0x18);
      lVar11 = *(long *)(param_1 + 0x180);
      seq_buf_printf(md_mod_info_seq_buf,"name: %s, base: %lx, nplt: %d",pcVar1,lVar11,
                     *(int *)(param_1 + 0x228) + 3);
      if (bVar4) {
        uVar10 = (ulong)*(uint *)(param_1 + 0x194) + lVar11;
        uVar2 = (ulong)*(uint *)(param_1 + 0x188) + lVar11;
        uVar12 = uVar2 - uVar10;
        iVar7 = msm_minidump_get_available_region();
        if (uVar12 >> 0xc < (ulong)(long)iVar7) {
          lVar11 = *(long *)(param_1 + 0x2e8);
          if (*(int *)(lVar11 + 0x28) != 0) {
            uVar9 = 0;
            do {
              uVar8 = *(ulong *)(lVar11 + (long)(int)uVar9 * 0x48 + 0x70);
              if (uVar10 <= uVar8 && uVar8 < uVar2) {
                seq_buf_printf(md_mod_info_seq_buf,", %s: %lx",
                               *(undefined8 *)(lVar11 + (long)(int)uVar9 * 0x48 + 0x30));
                lVar11 = *(long *)(param_1 + 0x2e8);
              }
              uVar9 = uVar9 + 1;
            } while (uVar9 < *(uint *)(lVar11 + 0x28));
          }
          local_78[8] = '\0';
          local_78[9] = '\0';
          local_78[10] = '\0';
          local_78[0xb] = '\0';
          local_78[0] = '\0';
          local_78[1] = '\0';
          local_78[2] = '\0';
          local_78[3] = '\0';
          local_78[4] = '\0';
          local_78[5] = '\0';
          local_78[6] = '\0';
          local_78[7] = '\0';
          if (uVar12 != 0) {
            iVar7 = 0;
            do {
              uVar8 = 0x1000 - (uVar10 & 0xfff);
              uVar2 = uVar12;
              if (uVar8 <= uVar12) {
                uVar2 = uVar8;
              }
              lVar11 = vmalloc_to_page(uVar10);
              uVar8 = _memstart_addr >> 0xc;
              snprintf(local_78,0xc,"%d_%s",iVar7,pcVar1);
              md_register_minidump_entry
                        (local_78,uVar10,(lVar11 + uVar8 * 0x40) * 0x40 + 0x8000000000,uVar2);
              uVar10 = uVar10 + uVar2;
              uVar12 = uVar12 - uVar2;
              iVar7 = iVar7 + 1;
            } while (uVar12 != 0);
          }
        }
        else {
          _printk(&DAT_0020b1d7,pcVar1);
        }
      }
      seq_buf_printf(md_mod_info_seq_buf,&DAT_0020bef7);
    }
    lVar11 = sp_el0;
    if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  uVar9 = n_modump - 0xb;
  if (0xfffffff5 < uVar9) {
    pcVar1 = (char *)(param_1 + 0x18);
    iVar5 = strcmp(key_modules,pcVar1);
    bVar4 = iVar5 == 0;
    if (iVar7 == 1) goto LAB_00103e90;
    if (0xfffffff5 < uVar9) {
      iVar6 = strcmp(DAT_00108898,pcVar1);
      bVar4 = iVar6 == 0 || iVar5 == 0;
      if (iVar7 == 2) goto LAB_00103e90;
      if (0xfffffff5 < uVar9) {
        iVar5 = strcmp(DAT_001088a0,pcVar1);
        bVar4 = iVar5 == 0 || bVar4;
        if (iVar7 == 3) goto LAB_00103e90;
        if (0xfffffff5 < uVar9) {
          iVar5 = strcmp(DAT_001088a8,pcVar1);
          bVar4 = iVar5 == 0 || bVar4;
          if (iVar7 == 4) goto LAB_00103e90;
          if (0xfffffff5 < uVar9) {
            iVar5 = strcmp(DAT_001088b0,pcVar1);
            bVar4 = iVar5 == 0 || bVar4;
            if (iVar7 == 5) goto LAB_00103e90;
            if (0xfffffff5 < uVar9) {
              iVar5 = strcmp(DAT_001088b8,pcVar1);
              bVar4 = iVar5 == 0 || bVar4;
              if (iVar7 == 6) goto LAB_00103e90;
              if (0xfffffff5 < uVar9) {
                iVar5 = strcmp(DAT_001088c0,pcVar1);
                bVar4 = iVar5 == 0 || bVar4;
                if (iVar7 == 7) goto LAB_00103e90;
                if (0xfffffff5 < uVar9) {
                  iVar5 = strcmp(DAT_001088c8,pcVar1);
                  bVar4 = iVar5 == 0 || bVar4;
                  if (iVar7 == 8) goto LAB_00103e90;
                  if (0xfffffff5 < uVar9) {
                    iVar5 = strcmp(DAT_001088d0,pcVar1);
                    bVar4 = iVar5 == 0 || bVar4;
                    if (iVar7 == 9) goto LAB_00103e90;
                    if (0xfffffff5 < uVar9) {
                      iVar5 = strcmp(DAT_001088d8,pcVar1);
                      bVar4 = iVar5 == 0 || bVar4;
                      if (iVar7 == 10) goto LAB_00103e90;
                      if (0xfffffff5 < uVar9) {
                    /* WARNING: Does not return */
                        pcVar3 = (code *)SoftwareBreakpoint(1,0x10403c);
                        (*pcVar3)();
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x103e8c);
  (*pcVar3)();
}



//------------------------------------------------------------
// md_register_minidump_entry @ 0010403c size=228
// signature: undefined md_register_minidump_entry(void)
// callers: [md_module_process, md_register_panic_entries]
//------------------------------------------------------------

int md_register_minidump_entry
              (char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  local_40 = 0;
  local_58 = 0;
  local_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  uVar3 = strnlen(param_1,0xd);
  if (uVar3 == 0xffffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (uVar3 != 0xd) {
    uVar3 = uVar3 + 1;
  }
  if (0xd < uVar3) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("strscpy");
  }
  strscpy(&local_68,param_1);
  local_50 = param_2;
  local_48 = param_3;
  local_40 = param_4;
  iVar2 = msm_minidump_add_region(&local_68);
  if (iVar2 < 0) {
    _printk(&DAT_0020b354,param_1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// md_module_notify @ 00104124 size=80
// signature: undefined md_module_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 md_module_notify(undefined8 param_1,undefined8 param_2,int *param_3)

{
  _raw_spin_lock(&md_modules_lock);
  if (*param_3 == 0) {
    md_module_process(param_3);
  }
  _raw_spin_unlock(&md_modules_lock);
  return 0;
}



//------------------------------------------------------------
// md_ipi_stop @ 00104178 size=84
// signature: undefined md_ipi_stop(void)
// callers: []
//------------------------------------------------------------

void md_ipi_stop(undefined8 param_1,void *param_2)

{
  long lVar1;
  code *pcVar2;
  
  lVar1 = tpidr_el1;
  if (0x1f < *(uint *)(&cpu_number + lVar1)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1041cc);
    (*pcVar2)();
  }
  memcpy(&regs_before_stop +
         *(long *)(&__per_cpu_offset + (ulong)*(uint *)(&cpu_number + lVar1) * 8),param_2,0x150);
  return;
}



//------------------------------------------------------------
// md_panic_handler @ 001041d0 size=32
// signature: undefined md_panic_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 md_panic_handler(void)

{
  md_dump_process();
  return 0;
}



//------------------------------------------------------------
// md_die_context_notify @ 001041f4 size=192
// signature: undefined md_die_context_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 md_die_context_notify(undefined8 param_1,undefined8 param_2,long *param_3)

{
  long lVar1;
  
  if ((md_in_oops_handler & 1) == 0) {
    md_in_oops_handler = 1;
    if (md_cntxt_seq_buf != 0) {
      lVar1 = tpidr_el1;
      die_cpu = *(undefined4 *)(&cpu_number + lVar1);
      seq_buf_printf(md_cntxt_seq_buf,"\nDIE CPU : %d\n");
      lVar1 = *param_3;
      if (((*(byte *)(lVar1 + 0x108) & 0xf) != 0) && (*(long *)(lVar1 + 0x100) != 0)) {
        md_dump_data(*(long *)(lVar1 + 0x100) + -0x80,&DAT_0020c0f9);
        md_dump_data(*(long *)(lVar1 + 0xf0) + -0x80,&DAT_0020b52b);
        md_dump_data(*(long *)(lVar1 + 0xf8) + -0x80,&DAT_0020b52e);
      }
    }
    md_in_oops_handler = 0;
  }
  return 0;
}



//------------------------------------------------------------
// minidump_smem_driver_probe @ 001042cc size=36
// signature: undefined minidump_smem_driver_probe(void)
// callers: []
//------------------------------------------------------------

void minidump_smem_driver_probe(void)

{
  msm_minidump_driver_probe(&md_smem_init_data);
  return;
}



//------------------------------------------------------------
// md_smem_init_md_table @ 001042f4 size=336
// signature: undefined md_smem_init_md_table(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void md_smem_init_md_table(void)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  int *piVar4;
  ulong uVar5;
  ulong local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_30 = 0;
  piVar4 = (int *)qcom_smem_get(0xffffffff,0x25a,&local_30);
  _md_global_toc = piVar4;
  if ((piVar4 == (int *)0x0) || ((int *)0xfffffffffffff000 < piVar4)) {
    _printk(&DAT_0020b603);
    uVar5 = (ulong)_md_global_toc & 0xffffffff;
  }
  else if ((local_30 < 0x150) || (*piVar4 == 0)) {
    _printk(&DAT_0020c161);
    uVar5 = 0xffffffed;
  }
  else {
    DAT_00108938 = piVar4 + 4;
    _DAT_00108940 = piVar4;
    piVar4[6] = 0x444f4e45;
    piVar4[7] = 0x4e52;
    minidump_table = piVar4[1];
    md_ss_toc = DAT_00108938;
    DAT_00108948 = kmalloc_trace(_alt_cb_patch_nops,0xdc0,0x1f68);
    piVar4 = md_ss_toc;
    if (DAT_00108948 == 0) {
      uVar5 = 0xfffffff4;
    }
    else {
      lVar2 = (DAT_00108948 << 8) >> 8;
      uVar5 = 0;
      uVar1 = lVar2 + 0x8000000000;
      lVar3 = _memstart_addr + uVar1;
      if (uVar1 >> 0x26 != 0) {
        lVar3 = lVar2 - _kimage_voffset;
      }
      *(long *)(md_ss_toc + 6) = lVar3;
      piVar4[4] = 1;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// md_smem_add_pending_entry @ 00104448 size=280
// signature: undefined md_smem_add_pending_entry(void)
// callers: []
//------------------------------------------------------------

undefined8 md_smem_add_pending_entry(long *param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  ulong uVar6;
  long *plVar7;
  long *plVar8;
  uint uVar9;
  long *plVar10;
  
  uVar5 = _raw_spin_lock_irqsave(&mdt_lock);
  *md_ss_toc = 0x454e424c00000001;
  if ((long *)*param_1 != param_1) {
    uVar9 = 0;
    plVar7 = (long *)*param_1;
    do {
      lVar1 = plVar7[3];
      lVar4 = (ulong)uVar9 * 0x30;
      plVar10 = (long *)*plVar7;
      plVar8 = (long *)(&DAT_00108950 + lVar4);
      *plVar8 = plVar7[2];
      *(long *)(&DAT_00108958 + lVar4) = lVar1;
      lVar2 = plVar7[7];
      lVar1 = plVar7[4];
      lVar3 = plVar7[5];
      *(long *)(&DAT_00108970 + lVar4) = plVar7[6];
      *(long *)(&DAT_00108978 + lVar4) = lVar2;
      *(long *)(&DAT_00108960 + lVar4) = lVar1;
      *(long *)(&DAT_00108968 + lVar4) = lVar3;
      md_add_ss_toc(plVar8,1);
      md_add_elf_header(plVar8);
      uVar6 = __list_del_entry_valid(plVar7);
      if ((uVar6 & 1) != 0) {
        lVar1 = *plVar7;
        plVar8 = (long *)plVar7[1];
        *(long **)(lVar1 + 8) = plVar8;
        *plVar8 = lVar1;
      }
      *plVar7 = -0x2152ffffffffff00;
      plVar7[1] = -0x2152fffffffffede;
      kfree(plVar7);
      uVar9 = uVar9 + 1;
      plVar7 = plVar10;
    } while (plVar10 != param_1);
  }
  _raw_spin_unlock_irqrestore(&mdt_lock,uVar5);
  return 0;
}



//------------------------------------------------------------
// md_smem_add_header @ 00104564 size=208
// signature: undefined md_smem_add_header(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void md_smem_add_header(undefined4 *param_1,long param_2,uint param_3)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  undefined4 uVar5;
  
  lVar4 = DAT_00108948;
  strscpy(DAT_00108948,"KELF_HDR",9);
  lVar3 = (minidump_elfheader << 8) >> 8;
  uVar1 = lVar3 + 0x8000000000;
  lVar2 = uVar1 + _memstart_addr;
  if (uVar1 >> 0x26 != 0) {
    lVar2 = lVar3 - _kimage_voffset;
  }
  *(long *)(lVar4 + 0x18) = lVar2;
  *(ulong *)(lVar4 + 0x20) = (ulong)param_3;
  param_1[1] = 1;
  *(undefined8 *)(param_1 + 0xe) = 0;
  *(undefined8 *)(param_1 + 2) = 0;
  *(undefined4 **)(param_1 + 4) = &minidump_table;
  uVar5 = set_section_name("minidump_table");
  *param_1 = uVar5;
  *(undefined2 *)(param_2 + 0x3c) = 4;
  *(undefined4 *)(lVar4 + 0x14) = 0x56414c49;
  return;
}



//------------------------------------------------------------
// md_smem_remove_region @ 00104638 size=624
// signature: undefined md_smem_remove_region(void)
// callers: []
//------------------------------------------------------------

ulong md_smem_remove_region(char *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  ulong uVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  char *__s1;
  uint uVar11;
  long lVar12;
  ulong uVar13;
  
  if ((DAT_00108938 == (undefined4 *)0x0) || (DAT_00108938[1] != 0x454e424c)) {
    uVar7 = 0xffffffea;
  }
  else {
    uVar6 = _raw_spin_lock_irqsave(&mdt_lock);
    _raw_write_lock(&mdt_remove_lock);
    puVar3 = DAT_00108938;
    uVar2 = md_num_regions;
    if ((DAT_00108938 == (undefined4 *)0x0) || (DAT_00108938[1] != 0x454e424c)) {
LAB_00104860:
      uVar7 = 0xffffffea;
    }
    else {
      uVar13 = (ulong)md_num_regions;
      if (0 < (int)md_num_regions) {
        uVar7 = 0;
        lVar12 = 0x100000000;
        pcVar8 = &DAT_00108950;
LAB_001046d4:
        iVar4 = strcmp(pcVar8,param_1);
        if (iVar4 != 0) goto code_r0x001046e4;
        iVar4 = (int)uVar7;
        if (-1 < iVar4) {
          uVar1 = puVar3[4];
          if ((int)uVar1 < 1) {
            uVar10 = 0xffffffea;
          }
          else {
            uVar11 = 0;
            __s1 = DAT_00108948;
            uVar9 = 0xffffffea;
            do {
              iVar5 = strcmp(__s1,param_1);
              __s1 = __s1 + 0x28;
              uVar10 = uVar11;
              if (iVar5 != 0) {
                uVar10 = uVar9;
              }
              uVar11 = uVar11 + 1;
              uVar9 = uVar10;
            } while (uVar1 != uVar11);
            if (-1 < (int)uVar10) {
              if (iVar4 < first_removed_entry) {
                first_removed_entry = iVar4;
              }
              *puVar3 = 0;
              memmove(pcVar8,&DAT_00108950 + (long)(int)((ulong)lVar12 >> 0x20) * 0x30,
                      (long)(int)((uVar2 - 1) - iVar4) * 0x30);
              lVar12 = (long)(int)(uVar2 - 1) * 0x30;
              *(undefined8 *)(&DAT_00108960 + lVar12) = 0;
              *(undefined8 *)(&DAT_00108968 + lVar12) = 0;
              *(undefined8 *)(&DAT_00108970 + lVar12) = 0;
              *(undefined8 *)(&DAT_00108978 + lVar12) = 0;
              *(undefined8 *)(&DAT_00108950 + lVar12) = 0;
              *(undefined8 *)(&DAT_00108958 + lVar12) = 0;
              memmove(DAT_00108948 + (ulong)uVar10 * 0x28,
                      DAT_00108948 + (long)(int)(uVar10 + 1) * 0x28,
                      (long)(int)(uVar1 + ~uVar10) * 0x28);
              pcVar8 = DAT_00108948 + (long)(int)(uVar1 - 1) * 0x28;
              pcVar8[0] = '\0';
              pcVar8[1] = '\0';
              pcVar8[2] = '\0';
              pcVar8[3] = '\0';
              pcVar8[4] = '\0';
              pcVar8[5] = '\0';
              pcVar8[6] = '\0';
              pcVar8[7] = '\0';
              pcVar8[8] = '\0';
              pcVar8[9] = '\0';
              pcVar8[10] = '\0';
              pcVar8[0xb] = '\0';
              pcVar8[0xc] = '\0';
              pcVar8[0xd] = '\0';
              pcVar8[0xe] = '\0';
              pcVar8[0xf] = '\0';
              pcVar8[0x10] = '\0';
              pcVar8[0x11] = '\0';
              pcVar8[0x12] = '\0';
              pcVar8[0x13] = '\0';
              pcVar8[0x14] = '\0';
              pcVar8[0x15] = '\0';
              pcVar8[0x16] = '\0';
              pcVar8[0x17] = '\0';
              pcVar8[0x18] = '\0';
              pcVar8[0x19] = '\0';
              pcVar8[0x1a] = '\0';
              pcVar8[0x1b] = '\0';
              pcVar8[0x1c] = '\0';
              pcVar8[0x1d] = '\0';
              pcVar8[0x1e] = '\0';
              pcVar8[0x1f] = '\0';
              pcVar8[0x20] = '\0';
              pcVar8[0x21] = '\0';
              pcVar8[0x22] = '\0';
              pcVar8[0x23] = '\0';
              pcVar8[0x24] = '\0';
              pcVar8[0x25] = '\0';
              pcVar8[0x26] = '\0';
              pcVar8[0x27] = '\0';
              uVar13 = msm_minidump_clear_headers(param_1);
              puVar3 = DAT_00108938;
              uVar7 = uVar13 & 0xffffffff;
              if ((int)uVar13 == 0) {
                *DAT_00108938 = 1;
                md_num_regions = md_num_regions - 1;
                puVar3[4] = puVar3[4] + -1;
              }
              goto LAB_00104864;
            }
          }
          _printk_deferred("Not able to find the region %s (%d,%d) in table\n",param_1,
                           uVar7 & 0xffffffff,uVar10);
          goto LAB_00104860;
        }
        goto LAB_0010482c;
      }
LAB_001046f8:
      uVar7 = 0xfffffffe;
LAB_0010482c:
      _printk_deferred("Not able to find the entry %s in table\n",param_1);
    }
LAB_00104864:
    _raw_write_unlock(&mdt_remove_lock);
    _raw_spin_unlock_irqrestore(&mdt_lock,uVar6);
  }
  return uVar7 & 0xffffffff;
code_r0x001046e4:
  uVar7 = uVar7 + 1;
  lVar12 = lVar12 + 0x100000000;
  pcVar8 = pcVar8 + 0x30;
  if (uVar13 == uVar7) goto LAB_001046f8;
  goto LAB_001046d4;
}



//------------------------------------------------------------
// md_smem_add_region @ 001048ac size=288
// signature: undefined md_smem_add_region(void)
// callers: []
//------------------------------------------------------------

ulong md_smem_add_region(char *param_1)

{
  int iVar1;
  undefined8 uVar2;
  ulong uVar3;
  char *pcVar4;
  ulong uVar5;
  
  uVar2 = _raw_spin_lock_irqsave(&mdt_lock);
  uVar3 = (ulong)md_num_regions;
  if (md_num_regions < 0xc9) {
    if ((DAT_00108938 != 0) && (*(int *)(DAT_00108938 + 4) == 0x454e424c)) {
      if (200 < *(uint *)(DAT_00108938 + 0x10)) {
        pcVar4 = "Maximum regions in minidump table reached\n";
        goto LAB_001049ac;
      }
      if (md_num_regions != 0) {
        uVar5 = 0;
        pcVar4 = &DAT_00108950;
        do {
          iVar1 = strcmp(pcVar4,param_1);
          if (iVar1 == 0) {
            if (-1 < (int)uVar5) {
              _printk_deferred("Entry name already exist\n");
              uVar3 = 0xffffffef;
              goto LAB_0010496c;
            }
            break;
          }
          uVar5 = uVar5 + 1;
          pcVar4 = pcVar4 + 0x30;
        } while (uVar3 != uVar5);
      }
      md_add_ss_toc(param_1,0);
      md_add_elf_header(param_1);
      uVar3 = (ulong)md_num_regions;
    }
    md_num_regions = (int)uVar3 + 1;
  }
  else {
    pcVar4 = "Maximum entries reached\n";
LAB_001049ac:
    _printk_deferred(pcVar4);
    uVar3 = 0xfffffff4;
  }
LAB_0010496c:
  _raw_spin_unlock_irqrestore(&mdt_lock,uVar2);
  return uVar3;
}



//------------------------------------------------------------
// md_smem_update_region @ 001049d0 size=448
// signature: undefined md_smem_update_region(void)
// callers: []
//------------------------------------------------------------

ulong md_smem_update_region(int param_1,char *param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  char *__s1;
  ulong uVar7;
  
  uVar4 = _raw_read_lock_irqsave(&mdt_remove_lock);
  if (param_1 < first_removed_entry) {
    uVar7 = (ulong)md_num_regions;
    if (0 < (int)md_num_regions) {
      uVar6 = 0;
      __s1 = &DAT_00108950;
      do {
        iVar3 = strcmp(__s1,param_2);
        if (iVar3 == 0) {
          if ((int)uVar6 < 0) goto LAB_00104b60;
          lVar5 = ((long)param_1 + (long)param_1 * 2) * 0x10;
          if ((((lVar5 - 0x2599U < 0xffffffffffffda2f) ||
               ((long)param_1 * 0x30 - 0x2599U < 0xffffffffffffda2f)) ||
              (*(undefined8 *)(&DAT_00108968 + (long)param_1 * 0x30) =
                    *(undefined8 *)(param_2 + 0x18), lVar1 = DAT_00108948,
              lVar5 - 0x2591U < 0xffffffffffffda2f)) ||
             ((long)param_1 * 0x30 - 0x2591U < 0xffffffffffffda2f)) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(1,0x104b90);
            (*pcVar2)();
          }
          uVar6 = 0;
          *(undefined8 *)(&DAT_00108970 + (long)param_1 * 0x30) = *(undefined8 *)(param_2 + 0x20);
          *(undefined8 *)(lVar1 + (long)(param_1 + 1) * 0x28 + 0x18) =
               *(undefined8 *)(param_2 + 0x20);
          goto LAB_00104af0;
        }
        uVar6 = uVar6 + 1;
        __s1 = __s1 + 0x30;
      } while (uVar7 != uVar6);
    }
    uVar6 = 0xfffffffe;
LAB_00104b60:
    _printk_deferred("Region:[%s] does not exist to update\n",param_2);
  }
  else {
    _printk_deferred("Region:[%s] was moved\n",param_2);
    uVar6 = 0xffffffea;
  }
LAB_00104af0:
  lVar5 = *(long *)(minidump_elfheader + 0x20) + minidump_elfheader + (long)(param_1 + 1) * 0x38;
  *(undefined8 *)
   (*(long *)(minidump_elfheader + 0x28) + minidump_elfheader + (long)(param_1 + 4) * 0x40 + 0x10) =
       *(undefined8 *)(param_2 + 0x18);
  *(undefined8 *)(lVar5 + 0x10) = *(undefined8 *)(param_2 + 0x18);
  *(undefined8 *)(lVar5 + 0x18) = *(undefined8 *)(param_2 + 0x20);
  _raw_read_unlock_irqrestore(&mdt_remove_lock,uVar4);
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// md_smem_get_available_region @ 00104b94 size=80
// signature: undefined md_smem_get_available_region(void)
// callers: []
//------------------------------------------------------------

int md_smem_get_available_region(void)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = _raw_spin_lock_irqsave(&mdt_lock);
  iVar1 = 0xc9 - md_num_regions;
  _raw_spin_unlock_irqrestore(&mdt_lock,uVar2);
  return iVar1;
}



//------------------------------------------------------------
// md_smem_md_enable @ 00104be8 size=104
// signature: undefined md_smem_md_enable(void)
// callers: []
//------------------------------------------------------------

bool md_smem_md_enable(void)

{
  bool bVar1;
  undefined8 uVar2;
  
  uVar2 = _raw_spin_lock_irqsave(&mdt_lock);
  if (DAT_00108938 == 0) {
    bVar1 = false;
  }
  else {
    bVar1 = *(int *)(DAT_00108938 + 4) == 0x454e424c;
  }
  _raw_spin_unlock_irqrestore(&mdt_lock,uVar2);
  return bVar1;
}



//------------------------------------------------------------
// md_smem_get_region @ 00104c54 size=140
// signature: undefined md_smem_get_region(void)
// callers: []
//------------------------------------------------------------

void md_smem_get_region(undefined8 *param_1,char *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint uVar5;
  int iVar6;
  char *__s1;
  ulong uVar7;
  
  uVar5 = md_num_regions;
  uVar7 = (ulong)md_num_regions;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  if (0 < (int)uVar5) {
    __s1 = &DAT_00108950;
    do {
      iVar6 = strcmp(__s1,param_2);
      if (iVar6 == 0) {
        uVar2 = *(undefined8 *)(__s1 + 0x18);
        uVar1 = *(undefined8 *)(__s1 + 0x20);
        uVar3 = *(undefined8 *)(__s1 + 0x28);
        param_1[2] = *(undefined8 *)(__s1 + 0x10);
        param_1[3] = uVar2;
        uVar2 = *(undefined8 *)__s1;
        uVar4 = *(undefined8 *)(__s1 + 8);
        param_1[4] = uVar1;
        param_1[5] = uVar3;
        *param_1 = uVar2;
        param_1[1] = uVar4;
        return;
      }
      __s1 = __s1 + 0x30;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  return;
}



//------------------------------------------------------------
// md_add_ss_toc @ 00104ce0 size=532
// signature: undefined md_add_ss_toc(void)
// callers: [md_smem_add_region, md_smem_add_pending_entry]
//------------------------------------------------------------

void md_add_ss_toc(char *param_1,ulong param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  code *pcVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  char *__s1;
  uint uVar9;
  int iVar10;
  int iVar11;
  
  iVar3 = *(int *)(DAT_00108938 + 0x10);
  if ((param_2 & 1) == 0) {
    uVar8 = (ulong)md_num_regions;
    uVar7 = strnlen(param_1,0xd);
    if (0xd < uVar7) goto LAB_00104edc;
    if (uVar7 != 0xd) {
      uVar7 = uVar7 + 1;
    }
    if (0xd < uVar7) goto LAB_00104ee8;
    strscpy(&DAT_00108950 + uVar8 * 0x30,param_1);
    uVar7 = uVar8 * 0x30;
    if ((0x2598 < uVar7) ||
       (*(undefined8 *)(&DAT_00108968 + uVar7) = *(undefined8 *)(param_1 + 0x18), 0x2590 < uVar7)) {
LAB_00104ed8:
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(1,0x104edc);
      (*pcVar5)();
    }
    uVar7 = uVar8 * 0x30;
    *(undefined8 *)(&DAT_00108970 + uVar7) = *(undefined8 *)(param_1 + 0x20);
    if ((0x2588 < uVar7) ||
       (*(undefined8 *)(&DAT_00108978 + uVar7) = *(undefined8 *)(param_1 + 0x28), 0x25a0 < uVar7))
    goto LAB_00104ed8;
    *(undefined4 *)(&DAT_00108960 + uVar8 * 0x30) = *(undefined4 *)(param_1 + 0x10);
  }
  pcVar4 = DAT_00108948;
  uVar7 = strnlen(param_1,0xd);
  if ((uVar7 < 0xd) || (uVar7 == 0x10)) {
    if (uVar7 != 0x10) {
      uVar7 = uVar7 + 1;
    }
    if (uVar7 < 0x11) {
      strscpy(pcVar4 + (long)iVar3 * 0x28,param_1);
      *(undefined8 *)(pcVar4 + (long)iVar3 * 0x28 + 0x18) = *(undefined8 *)(param_1 + 0x20);
      *(undefined8 *)(pcVar4 + (long)iVar3 * 0x28 + 0x20) = *(undefined8 *)(param_1 + 0x28);
      iVar2 = *(int *)(DAT_00108938 + 0x10);
      if (0 < iVar2) {
        uVar9 = 0;
        iVar10 = 0;
        iVar11 = -0x16;
        __s1 = DAT_00108948;
        do {
          iVar6 = strcmp(__s1,param_1);
          if (iVar6 == 0) {
            uVar1 = *(uint *)(__s1 + 0x10);
            if (*(uint *)(__s1 + 0x10) <= uVar9) {
              uVar1 = uVar9;
            }
            iVar11 = iVar10;
            uVar9 = uVar1;
          }
          iVar10 = iVar10 + 1;
          __s1 = __s1 + 0x28;
        } while (iVar2 != iVar10);
        if (-1 < iVar11) {
          *(uint *)(pcVar4 + (long)iVar3 * 0x28 + 0x10) = uVar9 + 1;
        }
      }
      builtin_strncpy(pcVar4 + (long)iVar3 * 0x28 + 0x14,"ILAV",4);
      *(int *)(DAT_00108938 + 0x10) = *(int *)(DAT_00108938 + 0x10) + 1;
      return;
    }
LAB_00104ee8:
                    /* WARNING: Subroutine does not return */
    fortify_panic("strscpy");
  }
LAB_00104edc:
                    /* WARNING: Subroutine does not return */
  fortify_panic("strnlen");
}



//------------------------------------------------------------
// md_dump_meminfo @ 00104ef8 size=1548
// signature: undefined md_dump_meminfo(void)
// callers: [md_dump_process]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void md_dump_meminfo(undefined8 param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  long local_b8;
  long local_b0;
  long local_a8;
  long local_a0;
  long local_98;
  long local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  local_90 = 0;
  local_a8 = 0;
  local_a0 = 0;
  local_b8 = 0;
  local_b0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  si_meminfo(&local_d8);
  si_swapinfo(&local_d8);
  lVar8 = _vm_node_stat;
  if (_vm_node_stat < 1) {
    lVar8 = 0;
  }
  lVar1 = _si_mem_available;
  if (_si_mem_available < 1) {
    lVar1 = 0;
  }
  lVar2 = _vm_zone_stat;
  if (_vm_zone_stat < 1) {
    lVar2 = 0;
  }
  lVar3 = _vmalloc_nr_pages;
  if (_vmalloc_nr_pages < 1) {
    lVar3 = 0;
  }
  lVar4 = _pcpu_nr_pages;
  if (_pcpu_nr_pages < 1) {
    lVar4 = 0;
  }
  lVar5 = _cpu_hwcaps;
  if (_cpu_hwcaps < 1) {
    lVar5 = 0;
  }
  lVar9 = _debugfs_create_file;
  if (_debugfs_create_file < 1) {
    lVar9 = 0;
  }
  lVar9 = lVar9 - (local_a0 + lVar5);
  if (lVar9 < 1) {
    lVar9 = 0;
  }
  lVar7 = si_mem_available();
  lVar5 = _mutex_trylock;
  if (_mutex_trylock < 1) {
    lVar5 = 0;
  }
  lVar6 = _get_slabinfo;
  if (_get_slabinfo < 1) {
    lVar6 = 0;
  }
  seq_buf_printf(param_1,"%s : %lld KB\n","MemTotal:       ",local_b8 << 2);
  seq_buf_printf(param_1,"%s : %lld KB\n","MemFree:        ",local_b0 << 2);
  seq_buf_printf(param_1,"%s : %lld KB\n","MemAvailable:   ",lVar7 << 2);
  seq_buf_printf(param_1,"%s : %lld KB\n","Buffers:        ",local_a0 << 2);
  seq_buf_printf(param_1,"%s : %lld KB\n","Cached:         ",lVar9 << 2);
  lVar9 = _cpu_hwcaps;
  if (_cpu_hwcaps < 1) {
    lVar9 = 0;
  }
  seq_buf_printf(param_1,"%s : %lld KB\n","SwapCached:     ",lVar9 << 2);
  seq_buf_printf(param_1,"%s : %lld KB\n","Active:         ",(lVar3 + lVar1) * 4);
  seq_buf_printf(param_1,"%s : %lld KB\n","Inactive:       ",(lVar2 + lVar8) * 4);
  seq_buf_printf(param_1,"%s : %lld KB\n","Active(anon):   ",lVar1 << 2);
  seq_buf_printf(param_1,"%s : %lld KB\n","Inactive(anon): ",lVar8 << 2);
  seq_buf_printf(param_1,"%s : %lld KB\n","Active(file):   ",lVar3 << 2);
  seq_buf_printf(param_1,"%s : %lld KB\n","Inactive(file): ",lVar2 << 2);
  seq_buf_printf(param_1,"%s : %lld KB\n","Unevictable:    ",lVar4 << 2);
  lVar8 = _cma_alloc;
  if (_cma_alloc < 1) {
    lVar8 = 0;
  }
  seq_buf_printf(param_1,"%s : %lld KB\n","Mlocked:        ",lVar8 << 2);
  seq_buf_printf(param_1,"%s : %lld KB\n","SwapTotal:      ",local_98 << 2);
  seq_buf_printf(param_1,"%s : %lld KB\n","SwapFree:       ",local_90 << 2);
  lVar8 = _get_each_object_track;
  if (_get_each_object_track < 1) {
    lVar8 = 0;
  }
  seq_buf_printf(param_1,"%s : %lld KB\n","Dirty:          ",lVar8 << 2);
  lVar8 = _dma_buf_get_each;
  if (_dma_buf_get_each < 1) {
    lVar8 = 0;
  }
  seq_buf_printf(param_1,"%s : %lld KB\n","Writeback:      ",lVar8 << 2);
  lVar8 = ____ratelimit;
  if (____ratelimit < 1) {
    lVar8 = 0;
  }
  seq_buf_printf(param_1,"%s : %lld KB\n","AnonPages:      ",lVar8 << 2);
  lVar8 = _page_ext_put;
  if (_page_ext_put < 1) {
    lVar8 = 0;
  }
  seq_buf_printf(param_1,"%s : %lld KB\n","Mapped:         ",lVar8 << 2);
  seq_buf_printf(param_1,"%s : %lld KB\n","Shmem:          ",local_a8 << 2);
  lVar8 = _kstrtoull_from_user;
  if (_kstrtoull_from_user < 1) {
    lVar8 = 0;
  }
  seq_buf_printf(param_1,"%s : %lld KB\n","KReclaimable:   ",(lVar8 + lVar5) * 4);
  seq_buf_printf(param_1,"%s : %lld KB\n","Slab:           ",(lVar6 + lVar5) * 4);
  seq_buf_printf(param_1,"%s : %lld KB\n","SReclaimable:   ",lVar5 << 2);
  seq_buf_printf(param_1,"%s : %lld KB\n","SUnreclaim:     ",lVar6 << 2);
  lVar8 = ___check_object_size;
  if (___check_object_size < 1) {
    lVar8 = 0;
  }
  seq_buf_printf(param_1,"KernelStack:    %8lu kB\n",lVar8);
  lVar8 = _gic_nonsecure_priorities;
  if (_gic_nonsecure_priorities < 1) {
    lVar8 = 0;
  }
  seq_buf_printf(param_1,"ShadowCallStack:%8lu kB\n",lVar8);
  lVar8 = ___arch_copy_from_user;
  if (___arch_copy_from_user < 1) {
    lVar8 = 0;
  }
  seq_buf_printf(param_1,"%s : %lld KB\n","PageTables:     ",lVar8 << 2);
  lVar8 = _kasan_flag_enabled;
  if (_kasan_flag_enabled < 1) {
    lVar8 = 0;
  }
  seq_buf_printf(param_1,"%s : %lld KB\n","Bounce:         ",lVar8 << 2);
  lVar8 = _ww_mutex_lock;
  if (_ww_mutex_lock < 1) {
    lVar8 = 0;
  }
  seq_buf_printf(param_1,"%s : %lld KB\n","WritebackTmp:   ",lVar8 << 2);
  seq_buf_printf(param_1,"VmallocTotal:   %8lu kB\n",0xf7a0000);
  lVar8 = vmalloc_nr_pages();
  seq_buf_printf(param_1,"%s : %lld KB\n","VmallocUsed: ",lVar8 << 2);
  lVar8 = pcpu_nr_pages();
  seq_buf_printf(param_1,"%s : %lld KB\n","Percpu:         ",lVar8 << 2);
  lVar8 = _ww_mutex_unlock;
  if (_ww_mutex_unlock < 1) {
    lVar8 = 0;
  }
  seq_buf_printf(param_1,"%s : %lld KB\n","AnonHugePages:  ",lVar8 << 0xb);
  lVar8 = _dma_fence_release;
  if (_dma_fence_release < 1) {
    lVar8 = 0;
  }
  seq_buf_printf(param_1,"%s : %lld KB\n","ShmemHugePages: ",lVar8 << 0xb);
  lVar8 = _dma_resv_iter_next;
  if (_dma_resv_iter_next < 1) {
    lVar8 = 0;
  }
  seq_buf_printf(param_1,"%s : %lld KB\n","ShmemPmdMapped: ",lVar8 << 0xb);
  lVar8 = _dma_fence_signal;
  if (_dma_fence_signal < 1) {
    lVar8 = 0;
  }
  seq_buf_printf(param_1,"%s : %lld KB\n","FileHugePages:  ",lVar8 << 0xb);
  lVar8 = _refcount_warn_saturate;
  if (_refcount_warn_saturate < 1) {
    lVar8 = 0;
  }
  seq_buf_printf(param_1,"%s : %lld KB\n","FilePmdMapped:  ",lVar8 << 0xb);
  seq_buf_printf(param_1,"%s : %lld KB\n","CmaTotal:       ",*md_debug_totalcma_pages << 2);
  lVar8 = _mem_section;
  if (_mem_section < 1) {
    lVar8 = 0;
  }
  seq_buf_printf(param_1,"%s : %lld KB\n","CmaFree:        ",lVar8 << 2);
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// md_dump_slabinfo @ 00105508 size=412
// signature: undefined md_dump_slabinfo(void)
// callers: [md_dump_process]
//------------------------------------------------------------

void md_dump_slabinfo(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  local_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  if (((md_debug_slab_caches != (long *)0x0) && (md_debug_slab_mutex != 0)) &&
     (iVar2 = mutex_trylock(), iVar2 != 0)) {
    seq_buf_printf(param_1,
                   "# name            <active_objs> <num_objs> <objsize> <objperslab> <pagesperslab>"
                  );
    seq_buf_printf(param_1," : tunables <limit> <batchcount> <sharedfactor>");
    seq_buf_printf(param_1," : slabdata <active_slabs> <num_slabs> <sharedavail>");
    seq_buf_printf(param_1,&DAT_0020bef7);
    plVar3 = (long *)*md_debug_slab_caches;
    if (plVar3 != md_debug_slab_caches) {
      do {
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        local_80 = 0;
        local_98 = 0;
        uStack_90 = 0;
        local_a8 = 0;
        uStack_a0 = 0;
        get_slabinfo(plVar3 + -0xd,&local_a8);
        seq_buf_printf(param_1,"%-17s %6lu %6lu %6u %4u %4d",plVar3[-1],local_a8,uStack_a0,
                       (int)plVar3[-10],local_78._4_4_,1 << (ulong)((uint)uStack_70 & 0x1f));
        seq_buf_printf(param_1," : tunables %4u %4u %4u",local_80 & 0xffffffff,local_80._4_4_,
                       local_78 & 0xffffffff);
        seq_buf_printf(param_1," : slabdata %6lu %6lu %6lu",local_98,uStack_90,local_88);
        seq_buf_printf(param_1,&DAT_0020bef7);
        plVar3 = (long *)*plVar3;
      } while (plVar3 != md_debug_slab_caches);
    }
    mutex_unlock(md_debug_slab_mutex);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// md_register_memory_dump @ 001056a8 size=520
// signature: undefined md_register_memory_dump(void)
// callers: [update_dump_size, msm_minidump_log_init]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void md_register_memory_dump(uint param_1,char *param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  undefined8 uVar6;
  undefined *puVar7;
  void *__s;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  void *local_70;
  long local_68;
  size_t local_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  lVar1 = (long)((ulong)param_1 << 0x20) >> 0x2c;
  local_68 = 0;
  local_60 = 0;
  local_78 = 0;
  local_70 = (void *)0x0;
  local_88 = 0;
  uStack_80 = 0;
  uVar4 = cma_alloc(_dma_contiguous_default_area,lVar1,0,1);
  if (uVar4 == 0) {
    puVar7 = &DAT_0020bcd5;
  }
  else {
    uVar5 = strnlen(param_2,0xd);
    if (uVar5 == 0xffffffffffffffff) {
                    /* WARNING: Subroutine does not return */
      fortify_panic("strnlen");
    }
    if (uVar5 != 0xd) {
      uVar5 = uVar5 + 1;
    }
    if (0xd < uVar5) {
                    /* WARNING: Subroutine does not return */
      fortify_panic("strscpy");
    }
    __s = (void *)((uVar4 & 0x3ffffffffffc0) << 6 | 0xff00000000000000);
    strscpy(&local_88,param_2);
    lVar2 = (long)((uVar4 & 0x3ffffffffffc0) << 0xe) >> 8;
    uVar5 = lVar2 + 0x8000000000;
    local_68 = _memstart_addr + uVar5;
    if (uVar5 >> 0x26 != 0) {
      local_68 = lVar2 - _kimage_voffset;
    }
    local_70 = __s;
    local_60 = (long)(int)param_1;
    iVar3 = msm_minidump_add_region(&local_88);
    if (-1 < iVar3) {
      memset(__s,0,(long)(int)param_1);
      DataMemoryBarrier(2,3);
      iVar3 = strcmp(param_2,"PAGEOWNER");
      if (iVar3 == 0) {
        md_pageowner_dump_addr = __s;
      }
      iVar3 = strcmp(param_2,"SLABOWNER");
      if (iVar3 == 0) {
        md_slabowner_dump_addr = __s;
      }
      iVar3 = strcmp(param_2,"DMA_INFO");
      if (iVar3 == 0) {
        md_dma_buf_info_addr = __s;
      }
      iVar3 = strcmp(param_2,"DMA_PROC");
      if (iVar3 == 0) {
        uVar6 = 1;
        md_dma_buf_procs_addr = __s;
      }
      else {
        uVar6 = 1;
      }
      goto LAB_00105868;
    }
    cma_release(_dma_contiguous_default_area,uVar4,lVar1);
    puVar7 = &DAT_0020b354;
  }
  _printk(puVar7,param_2);
  uVar6 = 0;
LAB_00105868:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// md_unregister_memory_dump @ 001058bc size=292
// signature: undefined md_unregister_memory_dump(void)
// callers: [update_dump_size]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void md_unregister_memory_dump(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  long local_70;
  undefined8 local_68;
  ulong local_60;
  char local_58 [24];
  long local_40;
  undefined8 local_38;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_30 = 0;
  local_58[0x10] = '\0';
  local_58[0x11] = '\0';
  local_58[0x12] = '\0';
  local_58[0x13] = '\0';
  local_58[0x14] = '\0';
  local_58[0x15] = '\0';
  local_58[0x16] = '\0';
  local_58[0x17] = '\0';
  local_40 = 0;
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
  local_68 = 0;
  local_60 = 0;
  local_78 = 0;
  local_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  md_get_region(local_58);
  if (local_40 == 0) {
    _printk(&DAT_0020afca,param_1);
  }
  else {
    uVar3 = strnlen(local_58,0xd);
    if (0xd < uVar3) {
                    /* WARNING: Subroutine does not return */
      fortify_panic("strnlen");
    }
    if (uVar3 != 0xd) {
      uVar3 = uVar3 + 1;
    }
    if (0xd < uVar3) {
                    /* WARNING: Subroutine does not return */
      fortify_panic("strscpy");
    }
    strscpy(&local_88,local_58);
    lVar1 = local_40;
    local_70 = local_40;
    local_68 = local_38;
    local_60 = local_30;
    iVar2 = msm_minidump_remove_region(&local_88);
    if (-1 < iVar2) {
      cma_release(_dma_contiguous_default_area,
                  (((lVar1 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 + -0x200000000,local_60 >> 0xc
                 );
      uVar4 = 1;
      goto LAB_0010599c;
    }
  }
  uVar4 = 0;
LAB_0010599c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// is_page_owner_enabled @ 001059e4 size=36
// signature: undefined is_page_owner_enabled(void)
// callers: [msm_minidump_log_init]
//------------------------------------------------------------

undefined8 is_page_owner_enabled(void)

{
  if ((md_debug_page_owner_inited == (int *)0x0) || (*md_debug_page_owner_inited == 0)) {
    return 0;
  }
  return 1;
}



//------------------------------------------------------------
// md_dump_pageowner @ 00105a0c size=1480
// signature: undefined md_dump_pageowner(void)
// callers: [md_dump_process]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void md_dump_pageowner(int *param_1,long param_2)

{
  undefined8 *puVar1;
  uint *puVar2;
  byte bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ulong *puVar10;
  undefined8 uVar11;
  size_t sVar12;
  long lVar13;
  int *piVar14;
  long lVar15;
  uint uVar16;
  ulong uVar17;
  ulong uVar18;
  ulong uVar19;
  undefined **ppuVar20;
  long local_78;
  long local_70;
  long local_68;
  
  lVar15 = sp_el0;
  local_68 = *(long *)(lVar15 + 0x638);
  if (md_debug_min_low_pfn != (ulong *)0x0 && md_debug_max_pfn != (ulong *)0x0) {
    uVar17 = *md_debug_min_low_pfn;
    do {
      uVar19 = uVar17;
      if ((((uVar19 >> 0x34 == 0) && (uVar19 >> 0x24 == 0)) && (_mem_section != 0)) &&
         (lVar15 = *(long *)(_mem_section + (uVar19 >> 0x13 & 0x1ffffffffff8)), lVar15 != 0)) {
        uVar17 = uVar19 >> 0xf & 0x7f;
        puVar1 = (undefined8 *)(lVar15 + uVar17 * 0x20);
        if ((puVar1 == (undefined8 *)0x0) || (uVar16 = (uint)*puVar1, (uVar16 >> 1 & 1) == 0))
        goto LAB_00105aac;
        if ((uVar16 >> 3 & 1) != 0) goto LAB_00105ae4;
        uVar16 = (uint)(**(ulong **)(lVar15 + uVar17 * 0x20 + 8) >> (uVar19 >> 9 & 0x3f)) & 1;
      }
      else {
LAB_00105aac:
        uVar16 = 0;
      }
      if (((uVar19 & 0x3ff) == 0) || (uVar17 = uVar19 + 1, uVar16 != 0)) goto LAB_00105ae4;
    } while( true );
  }
  goto LAB_00105f98;
LAB_00105ae4:
  uVar17 = *md_debug_max_pfn;
  if (uVar19 < uVar17) {
    do {
      if ((uVar19 & 0x3ff) == 0) {
        if ((((uVar19 >> 0x34 == 0) && (uVar19 >> 0x24 == 0)) && (_mem_section != 0)) &&
           (lVar15 = *(long *)(_mem_section + (uVar19 >> 0x13 & 0x1ffffffffff8)), lVar15 != 0)) {
          uVar18 = uVar19 >> 0xf & 0x7f;
          puVar1 = (undefined8 *)(lVar15 + uVar18 * 0x20);
          if (((puVar1 != (undefined8 *)0x0) && (uVar16 = (uint)*puVar1, (uVar16 >> 1 & 1) != 0)) &&
             (((uVar16 >> 3 & 1) != 0 ||
              ((**(ulong **)(lVar15 + uVar18 * 0x20 + 8) >> (uVar19 >> 9 & 0x3f) & 1) != 0))))
          goto LAB_00105b28;
        }
        uVar19 = uVar19 + 0x3ff;
      }
      else {
LAB_00105b28:
        lVar15 = uVar19 * 0x40 + (_memstart_addr >> 0xc) * -0x40;
        puVar2 = (uint *)(lVar15 + -0x200000000);
        if ((*(uint *)(lVar15 + -0x1ffffffd0) & 0xf0000080) == 0xf0000000) {
          uVar18 = 0;
          if (*(ulong *)(lVar15 + -0x1ffffffd8) < 0xb) {
            uVar18 = ~(-1L << (*(ulong *)(lVar15 + -0x1ffffffd8) & 0x3f));
          }
          uVar19 = uVar18 + uVar19;
        }
        else {
          puVar10 = (ulong *)page_ext_get(puVar2);
          if (((puVar10 != (ulong *)0x0) && ((*puVar10 & 1) != 0)) &&
             ((((uint)*puVar10 >> 1 & 1) != 0 &&
              (iVar5 = get_page_owner_handle(puVar10,uVar19), iVar5 != 0)))) {
            local_78 = 0;
            lVar13 = 0;
            if (page_owner_filter != 0) {
              if (page_owner_filter == 0xf) {
LAB_00105c10:
                iVar6 = stack_depot_fetch(iVar5,&local_78);
                piVar14 = (int *)((md_pageowner_dump_addr + md_pageowner_dump_size) -
                                 page_owner_handles_size);
                if (param_1 <= piVar14) {
                  uVar17 = (ulong)nr_page_owner_handles;
                  if (0 < (int)nr_page_owner_handles) {
                    if (*piVar14 != iVar5) {
                      uVar18 = 0;
                      do {
                        if (uVar17 - 1 == uVar18) goto joined_r0x00105e74;
                        lVar15 = uVar18 * 4;
                        uVar18 = uVar18 + 1;
                      } while (*(int *)(md_pageowner_dump_addr +
                                        (md_pageowner_dump_size - page_owner_handles_size) + 4 +
                                       lVar15) != iVar5);
                      if (uVar17 <= uVar18) goto LAB_00105e90;
                    }
                    iVar5 = scnprintf(param_1,param_2,"%lu %u %u\n",uVar19,iVar5,0);
                    lVar13 = (long)iVar5;
                    goto LAB_00105f30;
                  }
                  uVar17 = (ulong)(int)nr_page_owner_handles;
joined_r0x00105e74:
                  if (piVar14 + uVar17 < (int *)(md_pageowner_dump_addr + md_pageowner_dump_size)) {
                    piVar14[uVar17] = iVar5;
                    nr_page_owner_handles = nr_page_owner_handles + 1;
                  }
                  else {
                    iVar8 = ___ratelimit(found_stack__rs,"found_stack");
                    if (iVar8 != 0) {
                      _printk(&DAT_0020b482);
                    }
                  }
                }
LAB_00105e90:
                iVar5 = scnprintf(param_1,param_2,"%lu %u %u\n",uVar19,iVar5,iVar6);
                lVar13 = (long)iVar5;
                if ((param_2 + -1 != lVar13) && (iVar6 != 0)) {
                  iVar8 = 0;
                  do {
                    iVar9 = scnprintf((long)param_1 + (long)iVar5,param_2 - iVar5,&DAT_0020c3ce,
                                      *(undefined8 *)(local_78 + (long)iVar8 * 8));
                    iVar5 = iVar9 + iVar5;
                    lVar13 = (long)iVar5;
                    bVar4 = iVar6 + -1 != iVar8;
                    iVar8 = iVar8 + 1;
                  } while (param_2 + -1 != lVar13 && bVar4);
                }
              }
              else {
                uVar18 = 1;
                iVar6 = 1;
                uVar17 = page_owner_filter;
                do {
                  if ((uVar18 & uVar17) == 0) goto switchD_00105cf4_caseD_3;
                  switch(iVar6) {
                  case 1:
                    local_70 = 0;
                    if ((*puVar2 & 0x80210) == 0) {
                      iVar8 = stack_depot_fetch(iVar5,&local_70);
                      if (iVar8 == 0) goto LAB_00105c10;
                      iVar9 = 0;
                      while (iVar7 = scnprintf(param_1,param_2,&DAT_0020beb0,
                                               *(undefined8 *)(local_70 + (long)iVar9 * 8)),
                            param_2 + -1 != (long)iVar7) {
                        uVar11 = _raw_spin_lock_irqsave(&accounted_call_site_lock);
                        ppuVar20 = &accounted_call_site_list;
                        while (ppuVar20 = (undefined **)*ppuVar20,
                              ppuVar20 != &accounted_call_site_list) {
                          sVar12 = strlen((char *)param_1);
                          lVar13 = strnstr(param_1,ppuVar20 + 2,sVar12);
                          if (lVar13 != 0) {
                            _raw_spin_unlock_irqrestore(&accounted_call_site_lock,uVar11);
                            goto switchD_00105cf4_caseD_3;
                          }
                        }
                        _raw_spin_unlock_irqrestore(&accounted_call_site_lock,uVar11);
                        iVar9 = iVar9 + 1;
                        if (iVar9 == iVar8) goto LAB_00105c10;
                      }
                    }
                    break;
                  case 2:
                    bVar3 = *(byte *)(lVar15 + -0x1ffffffff) >> 1;
                    goto joined_r0x00105cb8;
                  case 4:
                    bVar3 = *(byte *)(lVar15 + -0x1fffffffe) >> 3;
joined_r0x00105cb8:
                    if ((bVar3 & 1) == 0) goto LAB_00105cbc;
                    goto LAB_00105c10;
                  case 8:
                    if ((*(byte *)puVar2 >> 4 & 1) != 0) goto LAB_00105c10;
                    goto LAB_00105f28;
                  }
switchD_00105cf4_caseD_3:
                  if (7 < iVar6) break;
                  uVar17 = page_owner_filter;
LAB_00105cbc:
                  iVar6 = iVar6 << 1;
                  uVar18 = (ulong)iVar6;
                } while (uVar18 <= uVar17);
LAB_00105f28:
                lVar13 = 0;
              }
            }
LAB_00105f30:
            if (lVar13 == param_2 + -1) {
              _printk(&DAT_0020c266);
              page_ext_put(puVar10);
              break;
            }
            param_2 = param_2 - lVar13;
            param_1 = (int *)((long)param_1 + lVar13);
          }
          page_ext_put(puVar10);
          uVar17 = *md_debug_max_pfn;
        }
      }
      uVar19 = uVar19 + 1;
    } while (uVar19 < uVar17);
  }
LAB_00105f98:
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// md_debugfs_pageowner @ 00105fd8 size=164
// signature: undefined md_debugfs_pageowner(void)
// callers: [msm_minidump_log_init]
//------------------------------------------------------------

void md_debugfs_pageowner(undefined8 param_1)

{
  debugfs_create_file("page_owner_dump_size_mb",0x100,param_1,0,proc_page_owner_dump_size_ops);
  debugfs_create_file("page_owner_filter",0x100,param_1,0,proc_page_owner_filter_ops);
  debugfs_create_file("page_owner_handles_size_kb",0x100,param_1,0,proc_page_owner_handle_ops);
  debugfs_create_file("page_owner_call_sites",0x100,param_1,0,proc_page_owner_call_site_ops);
  return;
}



//------------------------------------------------------------
// is_slub_debug_enabled @ 00106080 size=36
// signature: undefined is_slub_debug_enabled(void)
// callers: [msm_minidump_log_init]
//------------------------------------------------------------

undefined8 is_slub_debug_enabled(void)

{
  if ((md_debug_slub_debug_enabled == (int *)0x0) || (*md_debug_slub_debug_enabled == 0)) {
    return 0;
  }
  return 1;
}



//------------------------------------------------------------
// md_dump_slabowner @ 001060a8 size=504
// signature: undefined md_dump_slabowner(void)
// callers: [md_dump_process]
//------------------------------------------------------------

void md_dump_slabowner(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  long *plVar6;
  long local_80;
  long local_78;
  long local_70;
  long local_68;
  
  lVar3 = sp_el0;
  uVar5 = 0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_70 = 0;
  local_80 = param_1;
  local_78 = param_2;
  do {
    if (((*(ulong *)((long)&slab_owner_filter + (uVar5 >> 3 & 0x1ffffffffffffff8)) >> (uVar5 & 0x3f)
         & 1) != 0) && (lVar3 = *(long *)(&kmalloc_caches + uVar5 * 8), lVar3 != 0)) {
      iVar1 = scnprintf(param_1,param_2,&DAT_0020bba7,*(undefined8 *)(lVar3 + 0x60));
      if (local_78 + -1 == (long)iVar1) break;
      lVar4 = *(long *)(lVar3 + 0xf8);
      local_80 = local_80 + iVar1;
      if ((lVar4 != 0) && (*(long *)(lVar4 + 0x20) != 0)) {
        uVar2 = _raw_spin_lock_irqsave(lVar4);
        plVar6 = (long *)(lVar4 + 0x10);
        while (plVar6 = (long *)*plVar6, plVar6 != (long *)(lVar4 + 0x10)) {
          get_each_object_track(lVar3,plVar6 + -1,0,dump_tracking,&local_80);
          if (local_70 == local_78 + -1) goto LAB_0010624c;
        }
        plVar6 = (long *)(lVar4 + 0x30);
        while (plVar6 = (long *)*plVar6, plVar6 != (long *)(lVar4 + 0x30)) {
          get_each_object_track(lVar3,plVar6 + -1,0,dump_tracking,&local_80);
          if (local_70 == local_78 + -1) goto LAB_0010624c;
        }
        _raw_spin_unlock_irqrestore(lVar4,uVar2);
      }
      iVar1 = scnprintf(local_80,local_78,&DAT_0020bef7);
      if (local_78 + -1 == (long)iVar1) break;
      param_1 = local_80 + iVar1;
      param_2 = local_78;
      local_80 = param_1;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 != 0xe);
LAB_00106264:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_0010624c:
  _raw_spin_unlock_irqrestore(lVar4,uVar2);
  _printk(&DAT_0020c188);
  goto LAB_00106264;
}



//------------------------------------------------------------
// dump_tracking @ 001062a4 size=572
// signature: undefined dump_tracking(void)
// callers: []
//------------------------------------------------------------

int dump_tracking(undefined8 param_1,undefined8 param_2,long *param_3,long *param_4)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  int *piVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  int iVar11;
  long local_60;
  long local_58;
  
  lVar10 = sp_el0;
  local_58 = *(long *)(lVar10 + 0x638);
  local_60 = 0;
  if ((*param_3 == 0) || ((int)param_3[1] == 0)) {
    iVar4 = 0;
    goto LAB_00106494;
  }
  piVar1 = (int *)(*param_4 + param_4[2]);
  lVar10 = param_4[1] - param_4[2];
  iVar3 = stack_depot_fetch((int)param_3[1],&local_60);
  piVar7 = (int *)((md_slabowner_dump_addr + md_slabowner_dump_size) - slab_owner_handles_size);
  if (piVar7 < piVar1) {
LAB_00106404:
    iVar4 = scnprintf(piVar1,lVar10,"%p %p %u\n",param_2,(int)param_3[1],iVar3);
    lVar6 = (long)iVar4;
    if ((lVar10 + -1 != lVar6) && (iVar3 != 0)) {
      iVar11 = 0;
      do {
        iVar5 = scnprintf((long)piVar1 + (long)iVar4,lVar10 - iVar4,&DAT_0020c3ce,
                          *(undefined8 *)(local_60 + (long)iVar11 * 8));
        iVar4 = iVar5 + iVar4;
        lVar6 = (long)iVar4;
        bVar2 = iVar3 + -1 != iVar11;
        iVar11 = iVar11 + 1;
      } while (lVar10 + -1 != lVar6 && bVar2);
    }
  }
  else {
    iVar4 = (int)param_3[1];
    uVar8 = (ulong)nr_slab_owner_handles;
    if ((int)nr_slab_owner_handles < 1) {
      uVar8 = (ulong)(int)nr_slab_owner_handles;
joined_r0x00106390:
      if (piVar7 + uVar8 < (int *)(md_slabowner_dump_addr + md_slabowner_dump_size)) {
        piVar7[uVar8] = iVar4;
        nr_slab_owner_handles = nr_slab_owner_handles + 1;
      }
      else {
        iVar4 = ___ratelimit(found_stack__rs,"found_stack");
        if (iVar4 != 0) {
          _printk(&DAT_0020b482);
        }
      }
      goto LAB_00106404;
    }
    if (*piVar7 != iVar4) {
      uVar9 = 0;
      do {
        if (uVar8 - 1 == uVar9) goto joined_r0x00106390;
        lVar6 = uVar9 * 4;
        uVar9 = uVar9 + 1;
      } while (*(int *)((md_slabowner_dump_size - slab_owner_handles_size) + md_slabowner_dump_addr
                        + 4 + lVar6) != iVar4);
      if (uVar8 <= uVar9) goto LAB_00106404;
    }
    iVar4 = scnprintf(piVar1,lVar10,"%p %p %u\n",param_2,(int)param_3[1],0);
    lVar6 = (long)iVar4;
  }
  param_4[2] = param_4[2] + lVar6;
LAB_00106494:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// md_debugfs_slabowner @ 001064e4 size=208
// signature: undefined md_debugfs_slabowner(void)
// callers: [msm_minidump_log_init]
//------------------------------------------------------------

void md_debugfs_slabowner(undefined8 param_1)

{
  char cVar1;
  bool bVar2;
  ulong uVar3;
  
  debugfs_create_file("slab_owner_dump_size_mb",0x100,param_1,0,proc_slab_owner_dump_size_ops);
  debugfs_create_file("slab_owner_filter",0x100,param_1,0,proc_slab_owner_filter_ops);
  debugfs_create_file("slab_owner_handles_size_kb",0x100,param_1,0,proc_slab_owner_handle_ops);
  uVar3 = 0;
  do {
    if (*(long *)(&kmalloc_caches + uVar3 * 8) != 0) {
      Hint_Prefetch(0x10af48,2,0,1);
      do {
        cVar1 = '\x01';
        bVar2 = (bool)ExclusiveMonitorPass(0x10af48,0x10);
        if (bVar2) {
          cVar1 = ExclusiveMonitorsStatus();
          slab_owner_filter = slab_owner_filter | 1L << (uVar3 & 0x3f);
        }
      } while (cVar1 != '\0');
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 != 0xe);
  return;
}



//------------------------------------------------------------
// md_dma_buf_info @ 001065c0 size=280
// signature: undefined md_dma_buf_info(void)
// callers: [md_dump_process]
//------------------------------------------------------------

void md_dma_buf_info(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  long local_60;
  long local_58;
  long local_50;
  undefined1 *puStack_48;
  undefined8 local_40;
  ulong local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  lVar1 = sp_el0;
  local_40 = 0;
  local_38 = 0;
  if (((*(uint *)(lVar1 + 0x10) & 0xff0100) == 0) && (*(int *)(lVar1 + 0x10) == 0)) {
    local_38 = 0;
    local_50 = 0;
    local_30 = 0;
    local_60 = param_1;
    local_58 = param_2;
    puStack_48 = (undefined1 *)&local_60;
    iVar2 = scnprintf(param_1,param_2,"\nDma-buf Objects:\n");
    iVar3 = scnprintf(local_60 + iVar2,local_58 - iVar2,"%-8s\t%-8s\t%-8s\t%-8s\texp_name\t%-8s\n",
                      &DAT_0020b255,"flags",&DAT_0020b39c,"count",&DAT_0020bc3e);
    local_50 = (long)(iVar3 + iVar2);
    dma_buf_get_each(dump_bufinfo,&puStack_48);
    scnprintf(local_60 + local_50,local_58 - local_50,"\nTotal %d objects, %zu bytes\n",
              local_38 & 0xffffffff,local_30);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// dump_bufinfo @ 001066dc size=1048
// signature: undefined dump_bufinfo(void)
// callers: []
//------------------------------------------------------------

void dump_bufinfo(long *param_1,undefined8 *param_2)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulong uVar9;
  long lVar10;
  undefined *puVar11;
  uint uVar12;
  code *pcVar13;
  long lVar14;
  uint uVar15;
  long lVar16;
  long *plVar17;
  uint *puVar18;
  long *plVar19;
  long *plVar20;
  long local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  plVar20 = (long *)*param_2;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  local_90 = 0;
  iVar4 = ww_mutex_lock(param_1[0x15],0);
  if (iVar4 == 0) {
    lVar6 = param_1[1];
    puVar11 = &DAT_0020b582;
    if ((undefined *)param_1[0xf] != (undefined *)0x0) {
      puVar11 = (undefined *)param_1[0xf];
    }
    iVar4 = scnprintf(*plVar20 + plVar20[2],plVar20[1] - plVar20[2],
                      "%08zu\t%08x\t%08x\t%08ld\t%s\t%08lu\t%s\n",*param_1,
                      *(undefined4 *)(lVar6 + 0x40),*(undefined4 *)(lVar6 + 0x44),
                      *(undefined8 *)(lVar6 + 0x38),param_1[0xe],
                      *(undefined8 *)(*(long *)(lVar6 + 0x20) + 0x40),puVar11);
    lVar6 = plVar20[2];
    plVar20[2] = lVar6 + iVar4;
    if (lVar6 + iVar4 != plVar20[1] + -1) {
      local_88 = 0;
      local_98 = param_1[0x15];
      local_90 = CONCAT44(local_90._4_4_,3);
      lVar6 = dma_resv_iter_first(&local_98);
      if (lVar6 != 0) {
        do {
          puVar18 = (uint *)(lVar6 + 0x38);
          uVar12 = *puVar18;
          if (*puVar18 == 0) {
            uVar15 = 0;
          }
          else {
            do {
              Hint_Prefetch(puVar18,2,0,1);
              do {
                uVar1 = *puVar18;
                if (uVar1 != uVar12) break;
                cVar2 = '\x01';
                bVar3 = (bool)ExclusiveMonitorPass(puVar18,0x10);
                if (bVar3) {
                  *puVar18 = uVar12 + 1;
                  cVar2 = ExclusiveMonitorsStatus();
                }
              } while (cVar2 != '\0');
              uVar15 = uVar12;
              if (uVar12 == uVar1) break;
              uVar15 = 0;
              uVar12 = uVar1;
            } while (uVar1 != 0);
          }
          if ((int)(uVar15 + 1 | uVar15) < 0) {
            refcount_warn_saturate(puVar18,0);
          }
          if (uVar15 != 0) {
            lVar14 = plVar20[1];
            lVar10 = plVar20[2];
            lVar16 = *plVar20;
            pcVar13 = *(code **)(*(long *)(lVar6 + 8) + 8);
            if (*(int *)(pcVar13 + -4) != 0x5a96816f) {
                    /* WARNING: Does not return */
              pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x106894);
              (*pcVar13)();
            }
            uVar7 = (*pcVar13)(lVar6);
            pcVar13 = *(code **)(*(long *)(lVar6 + 8) + 0x10);
            if (*(int *)(pcVar13 + -4) != 0x5a96816f) {
                    /* WARNING: Does not return */
              pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x1068c0);
              (*pcVar13)();
            }
            uVar8 = (*pcVar13)(lVar6);
            puVar11 = &DAT_0020b582;
            if ((*(ulong *)(lVar6 + 0x30) & 1) == 0) {
              pcVar13 = *(code **)(*(long *)(lVar6 + 8) + 0x20);
              if (pcVar13 == (code *)0x0) {
                puVar11 = &DAT_0020bafe;
              }
              else {
                if (*(int *)(pcVar13 + -4) != -0xc4a187e) {
                    /* WARNING: Does not return */
                  pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x1068fc);
                  (*pcVar13)();
                }
                uVar9 = (*pcVar13)(lVar6);
                puVar11 = &DAT_0020bafe;
                if ((uVar9 & 1) != 0) {
                  dma_fence_signal(lVar6);
                  puVar11 = &DAT_0020b582;
                }
              }
            }
            iVar4 = scnprintf(lVar16 + lVar10,lVar14 - lVar10,"\tFence: %s %s %ssignalled\n",uVar7,
                              uVar8,puVar11);
            lVar6 = plVar20[2];
            plVar20[2] = lVar6 + iVar4;
            if (lVar6 + iVar4 == plVar20[1] + -1) goto LAB_00106acc;
            Hint_Prefetch(puVar18,2,0,1);
            do {
              uVar12 = *puVar18;
              cVar2 = '\x01';
              bVar3 = (bool)ExclusiveMonitorPass(puVar18,0x10);
              if (bVar3) {
                *puVar18 = uVar12 - 1;
                cVar2 = ExclusiveMonitorsStatus();
              }
            } while (cVar2 != '\0');
            if (uVar12 == 1) {
              DataMemoryBarrier(2,1);
              dma_fence_release(puVar18);
            }
            else if ((int)uVar12 < 1) {
              refcount_warn_saturate(puVar18,3);
            }
          }
          lVar6 = dma_resv_iter_next(&local_98);
        } while (lVar6 != 0);
      }
      iVar4 = scnprintf(*plVar20 + plVar20[2],plVar20[1] - plVar20[2],"\tAttached Devices:\n");
      lVar14 = plVar20[1];
      lVar6 = plVar20[2] + (long)iVar4;
      plVar20[2] = lVar6;
      if (lVar6 != lVar14 + -1) {
        plVar17 = param_1 + 2;
        plVar19 = (long *)*plVar17;
        if (plVar19 == plVar17) {
          iVar4 = 0;
        }
        else {
          iVar4 = 0;
          do {
            lVar10 = ((long *)plVar19[-1])[0xe];
            if (lVar10 == 0) {
              lVar10 = *(long *)plVar19[-1];
            }
            iVar5 = scnprintf(*plVar20 + lVar6,lVar14 - lVar6,&DAT_0020b583,lVar10);
            lVar14 = plVar20[1];
            lVar6 = plVar20[2] + (long)iVar5;
            plVar20[2] = lVar6;
            if (lVar6 == lVar14 + -1) goto LAB_00106acc;
            plVar19 = (long *)*plVar19;
            iVar4 = iVar4 + 1;
          } while (plVar19 != plVar17);
        }
        ww_mutex_unlock(param_1[0x15]);
        iVar4 = scnprintf(*plVar20 + plVar20[2],plVar20[1] - plVar20[2],
                          "Total %d devices attached\n\n",iVar4);
        lVar6 = plVar20[2];
        plVar20[2] = lVar6 + iVar4;
        if (lVar6 + iVar4 != plVar20[1] + -1) {
          uVar7 = 0;
          *(int *)(param_2 + 2) = *(int *)(param_2 + 2) + 1;
          param_2[3] = param_2[3] + *param_1;
          goto LAB_00106adc;
        }
      }
    }
  }
LAB_00106acc:
  _printk(&DAT_0020bc73);
  uVar7 = 0xffffffe4;
LAB_00106adc:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// md_debugfs_dmabufinfo @ 00106b1c size=56
// signature: undefined md_debugfs_dmabufinfo(void)
// callers: [msm_minidump_log_init]
//------------------------------------------------------------

void md_debugfs_dmabufinfo(undefined8 param_1)

{
  debugfs_create_file("dma_buf_info_size_mb",0x100,param_1,0,proc_dma_buf_info_size_ops);
  return;
}



//------------------------------------------------------------
// md_dma_buf_procs @ 00106b58 size=560
// signature: undefined md_dma_buf_procs(void)
// callers: [md_dump_process]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void md_dma_buf_procs(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  undefined *puVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  long *local_a0;
  undefined *local_98;
  ulong local_90;
  undefined8 local_88;
  long local_80;
  long local_78;
  long local_70;
  long local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  local_a0 = &local_80;
  local_70 = 0;
  local_98 = (undefined *)0x0;
  local_90 = 0;
  local_88 = 0;
  local_80 = param_1;
  local_78 = param_2;
  __rcu_read_lock();
  puVar4 = (undefined *)(_DAT_00210648 + -0x550);
  if (puVar4 != &init_task) {
    iVar1 = 0;
    lVar5 = _DAT_00210648;
    do {
      plVar3 = (long *)(*(long *)(lVar5 + 0x340) + 0x10);
      plVar6 = (long *)*plVar3;
      local_98 = puVar4;
      if (plVar6 != plVar3) {
        _raw_spin_lock(plVar6 + 0x46);
        lVar2 = plVar6[0x31];
        lVar7 = *(long *)(*(long *)(lVar5 + 0x120) + 0x878);
        if ((lVar2 != 0) &&
           ((lVar7 != lVar2 || (plVar6 + -0xde == (long *)*(long *)(lVar5 + 0x120))))) {
          iVar1 = iterate_fd(lVar2,0,get_dma_info,&local_a0);
        }
        _raw_spin_unlock(plVar6 + 0x46);
        while( true ) {
          if (iVar1 != 0) goto LAB_00106d3c;
          plVar6 = (long *)*plVar6;
          if (plVar6 == (long *)(*(long *)(lVar5 + 0x340) + 0x10)) break;
          _raw_spin_lock(plVar6 + 0x46);
          if (lVar7 == 0) {
            lVar7 = *(long *)(*(long *)(lVar5 + 0x120) + 0x878);
            lVar2 = plVar6[0x31];
            if (lVar2 != 0) goto LAB_00106ca8;
LAB_00106c6c:
            iVar1 = 0;
          }
          else {
            lVar2 = plVar6[0x31];
            if (lVar2 == 0) goto LAB_00106c6c;
LAB_00106ca8:
            if ((lVar7 == lVar2) && (plVar6 + -0xde != (long *)*(long *)(lVar5 + 0x120)))
            goto LAB_00106c6c;
            iVar1 = iterate_fd(lVar2,0,get_dma_info,&local_a0);
          }
          _raw_spin_unlock(plVar6 + 0x46);
        }
        if ((int)local_90 == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = scnprintf(local_80 + local_70,local_78 - local_70,
                            "\nTotal %d objects, %zu bytes\n",local_90 & 0xffffffff,local_88);
          local_70 = local_70 + iVar1;
          if (local_70 == local_78 + -1) {
LAB_00106d3c:
            __rcu_read_unlock();
            _printk(&DAT_0020bfff);
            goto LAB_00106d4c;
          }
          local_90 = local_90 & 0xffffffff00000000;
          local_88 = 0;
          memset(dma_buf_hash,0,0x100000);
        }
      }
      lVar5 = *(long *)(puVar4 + 0x550);
      puVar4 = (undefined *)(lVar5 + -0x550);
    } while (puVar4 != &init_task);
  }
  __rcu_read_unlock();
LAB_00106d4c:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// get_dma_info @ 00106d8c size=656
// signature: undefined get_dma_info(void)
// callers: []
//------------------------------------------------------------

undefined8 get_dma_info(undefined8 *param_1,long param_2)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  ulong uVar7;
  undefined8 uVar8;
  uint uVar9;
  long *plVar10;
  uint uVar11;
  uint uVar12;
  long *plVar13;
  long *plVar14;
  
  uVar7 = qcom_is_dma_buf_file(param_2);
  if ((uVar7 & 1) == 0) {
LAB_00106f14:
    uVar8 = 0;
  }
  else {
    plVar14 = (long *)*param_1;
    if (*(int *)(param_1 + 2) == 0) {
      iVar6 = scnprintf(*plVar14 + plVar14[2],plVar14[1] - plVar14[2],
                        "\n%s (PID %d)\nDMA Buffers:\n",param_1[1] + 0x848,
                        *(undefined4 *)(param_1[1] + 0x634));
      lVar4 = plVar14[2];
      plVar14[2] = lVar4 + iVar6;
      if (lVar4 + iVar6 != plVar14[1] + -1) goto LAB_00106e04;
    }
    else {
LAB_00106e04:
      plVar13 = *(long **)(param_2 + 0xd8);
      uVar12 = 0x75f572ab;
      uVar9 = 0x130;
      uVar11 = 0x75f572ab;
      iVar6 = 0x75f572ab;
      plVar10 = plVar13;
      do {
        uVar9 = uVar9 - 0xc;
        uVar12 = (int)plVar10[1] + uVar12;
        iVar1 = *(int *)((long)plVar10 + 4) + uVar11;
        uVar11 = ((int)*plVar10 + iVar6) - uVar12 ^ (uVar12 >> 0x1c | uVar12 * 0x10);
        iVar6 = uVar12 + iVar1;
        uVar12 = iVar1 - uVar11 ^ (uVar11 >> 0x1a | uVar11 << 6);
        iVar1 = uVar11 + iVar6;
        uVar11 = iVar6 - uVar12 ^ (uVar12 >> 0x18 | uVar12 << 8);
        iVar6 = uVar12 + iVar1;
        uVar12 = iVar1 - uVar11 ^ (uVar11 >> 0x10 | uVar11 << 0x10);
        iVar1 = uVar11 + iVar6;
        uVar3 = iVar6 - uVar12 ^ (uVar12 >> 0xd | uVar12 << 0x13);
        iVar6 = uVar12 + iVar1;
        uVar11 = uVar3 + iVar6;
        uVar12 = iVar1 - uVar3 ^ (uVar3 >> 0x1c | uVar3 << 4);
        plVar10 = (long *)((long)plVar10 + 0xc);
      } while (0xc < uVar9);
      uVar12 = (uVar12 ^ uVar11) - (uVar11 >> 0x12 | uVar11 * 0x4000);
      uVar9 = (iVar6 + (uint)*(byte *)((long)plVar13 + 0x12f) * 0x1000000 +
               (uint)*(byte *)((long)plVar13 + 0x12e) * 0x10000 +
               (uint)*(byte *)((long)plVar13 + 0x12d) * 0x100 + (uint)*(byte *)((long)plVar13 + 300)
              ^ uVar12) - (uVar12 >> 0x15 | uVar12 * 0x800);
      uVar11 = (uVar9 ^ uVar11) - (uVar9 >> 7 | uVar9 * 0x2000000);
      uVar12 = (uVar11 ^ uVar12) - (uVar11 >> 0x10 | uVar11 * 0x10000);
      uVar9 = (uVar12 ^ uVar9) - (uVar12 >> 0x1c | uVar12 * 0x10);
      uVar11 = (uVar9 ^ uVar11) - (uVar9 >> 0x12 | uVar9 * 0x4000);
      uVar7 = (ulong)((uVar11 ^ uVar12) - (uVar11 >> 8)) & 0xfffff;
      if (dma_buf_hash[uVar7] != '\0') goto LAB_00106f14;
      dma_buf_hash[uVar7] = 1;
      *(int *)(param_1 + 2) = *(int *)(param_1 + 2) + 1;
      iVar6 = scnprintf(*plVar14 + plVar14[2],plVar14[1] - plVar14[2],
                        "%-8s\t%-8s\t%-8s\t%-8s\texp_name\t%-8s\n",&DAT_0020b255,"flags",
                        &DAT_0020b39c,"count",&DAT_0020bc3e);
      lVar4 = plVar14[2] + (long)iVar6;
      plVar14[2] = lVar4;
      if (lVar4 != plVar14[1] + -1) {
        lVar5 = plVar13[1];
        puVar2 = &DAT_0020b582;
        if ((undefined *)plVar13[0xf] != (undefined *)0x0) {
          puVar2 = (undefined *)plVar13[0xf];
        }
        iVar6 = scnprintf(*plVar14 + lVar4,plVar14[1] - lVar4,
                          "%08zu\t%08x\t%08x\t%08ld\t%s\t%08lu\t%s\n",*plVar13,
                          *(undefined4 *)(lVar5 + 0x40),*(undefined4 *)(lVar5 + 0x44),
                          *(undefined8 *)(lVar5 + 0x38),plVar13[0xe],
                          *(undefined8 *)(*(long *)(lVar5 + 0x20) + 0x40),puVar2);
        lVar4 = plVar14[2];
        plVar14[2] = lVar4 + iVar6;
        if (lVar4 + iVar6 != plVar14[1] + -1) {
          param_1[3] = param_1[3] + *plVar13;
          return 0;
        }
      }
    }
    uVar8 = 0xffffffea;
  }
  return uVar8;
}



//------------------------------------------------------------
// md_debugfs_dmabufprocs @ 00107020 size=56
// signature: undefined md_debugfs_dmabufprocs(void)
// callers: [msm_minidump_log_init]
//------------------------------------------------------------

void md_debugfs_dmabufprocs(undefined8 param_1)

{
  debugfs_create_file("dma_buf_procs_size_mb",0x100,param_1,0,proc_dma_buf_procs_size_ops);
  return;
}



//------------------------------------------------------------
// md_minidump_memory_init @ 0010705c size=404
// signature: undefined md_minidump_memory_init(void)
// callers: [msm_minidump_log_init]
//------------------------------------------------------------

bool md_minidump_memory_init(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  
  md_debug_totalcma_pages = debug_symbol_lookup_name("totalcma_pages");
  bVar1 = md_debug_totalcma_pages == 0;
  if (bVar1) {
    _printk(&DAT_0020b131,"totalcma_pages");
  }
  md_debug_slab_caches = debug_symbol_lookup_name("slab_caches");
  bVar2 = md_debug_slab_caches == 0;
  if (bVar2) {
    _printk(&DAT_0020b131,"slab_caches");
  }
  md_debug_slab_mutex = debug_symbol_lookup_name("slab_mutex");
  bVar3 = md_debug_slab_mutex == 0;
  if (bVar3) {
    _printk(&DAT_0020b131,"slab_mutex");
  }
  md_debug_page_owner_inited = debug_symbol_lookup_name("page_owner_inited");
  bVar4 = md_debug_page_owner_inited == 0;
  if (bVar4) {
    _printk(&DAT_0020b131,"page_owner_inited");
  }
  md_debug_slub_debug_enabled = debug_symbol_lookup_name("slub_debug_enabled");
  bVar5 = md_debug_slub_debug_enabled == 0;
  if (bVar5) {
    _printk(&DAT_0020b131,"slub_debug_enabled");
  }
  md_debug_min_low_pfn = debug_symbol_lookup_name("min_low_pfn");
  bVar6 = md_debug_min_low_pfn == 0;
  if (bVar6) {
    _printk(&DAT_0020b131,"min_low_pfn");
  }
  md_debug_max_pfn = debug_symbol_lookup_name("max_pfn");
  bVar7 = md_debug_max_pfn == 0;
  if (bVar7) {
    _printk(&DAT_0020b131,"max_pfn");
  }
  return bVar7 || (bVar6 || (bVar5 || (bVar4 || (bVar3 || (bVar2 || bVar1)))));
}



//------------------------------------------------------------
// page_owner_dump_size_read @ 001071f4 size=232
// signature: undefined page_owner_dump_size_read(void)
// callers: []
//------------------------------------------------------------

void page_owner_dump_size_read
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  size_t sVar2;
  char local_a0 [104];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_a0[0x60] = '\0';
  local_a0[0x61] = '\0';
  local_a0[0x62] = '\0';
  local_a0[99] = '\0';
  local_a0[0x50] = '\0';
  local_a0[0x51] = '\0';
  local_a0[0x52] = '\0';
  local_a0[0x53] = '\0';
  local_a0[0x54] = '\0';
  local_a0[0x55] = '\0';
  local_a0[0x56] = '\0';
  local_a0[0x57] = '\0';
  local_a0[0x58] = '\0';
  local_a0[0x59] = '\0';
  local_a0[0x5a] = '\0';
  local_a0[0x5b] = '\0';
  local_a0[0x5c] = '\0';
  local_a0[0x5d] = '\0';
  local_a0[0x5e] = '\0';
  local_a0[0x5f] = '\0';
  local_a0[0x40] = '\0';
  local_a0[0x41] = '\0';
  local_a0[0x42] = '\0';
  local_a0[0x43] = '\0';
  local_a0[0x44] = '\0';
  local_a0[0x45] = '\0';
  local_a0[0x46] = '\0';
  local_a0[0x47] = '\0';
  local_a0[0x48] = '\0';
  local_a0[0x49] = '\0';
  local_a0[0x4a] = '\0';
  local_a0[0x4b] = '\0';
  local_a0[0x4c] = '\0';
  local_a0[0x4d] = '\0';
  local_a0[0x4e] = '\0';
  local_a0[0x4f] = '\0';
  local_a0[0x30] = '\0';
  local_a0[0x31] = '\0';
  local_a0[0x32] = '\0';
  local_a0[0x33] = '\0';
  local_a0[0x34] = '\0';
  local_a0[0x35] = '\0';
  local_a0[0x36] = '\0';
  local_a0[0x37] = '\0';
  local_a0[0x38] = '\0';
  local_a0[0x39] = '\0';
  local_a0[0x3a] = '\0';
  local_a0[0x3b] = '\0';
  local_a0[0x3c] = '\0';
  local_a0[0x3d] = '\0';
  local_a0[0x3e] = '\0';
  local_a0[0x3f] = '\0';
  local_a0[0x20] = '\0';
  local_a0[0x21] = '\0';
  local_a0[0x22] = '\0';
  local_a0[0x23] = '\0';
  local_a0[0x24] = '\0';
  local_a0[0x25] = '\0';
  local_a0[0x26] = '\0';
  local_a0[0x27] = '\0';
  local_a0[0x28] = '\0';
  local_a0[0x29] = '\0';
  local_a0[0x2a] = '\0';
  local_a0[0x2b] = '\0';
  local_a0[0x2c] = '\0';
  local_a0[0x2d] = '\0';
  local_a0[0x2e] = '\0';
  local_a0[0x2f] = '\0';
  local_a0[0x10] = '\0';
  local_a0[0x11] = '\0';
  local_a0[0x12] = '\0';
  local_a0[0x13] = '\0';
  local_a0[0x14] = '\0';
  local_a0[0x15] = '\0';
  local_a0[0x16] = '\0';
  local_a0[0x17] = '\0';
  local_a0[0x18] = '\0';
  local_a0[0x19] = '\0';
  local_a0[0x1a] = '\0';
  local_a0[0x1b] = '\0';
  local_a0[0x1c] = '\0';
  local_a0[0x1d] = '\0';
  local_a0[0x1e] = '\0';
  local_a0[0x1f] = '\0';
  local_a0[0] = '\0';
  local_a0[1] = '\0';
  local_a0[2] = '\0';
  local_a0[3] = '\0';
  local_a0[4] = '\0';
  local_a0[5] = '\0';
  local_a0[6] = '\0';
  local_a0[7] = '\0';
  local_a0[8] = '\0';
  local_a0[9] = '\0';
  local_a0[10] = '\0';
  local_a0[0xb] = '\0';
  local_a0[0xc] = '\0';
  local_a0[0xd] = '\0';
  local_a0[0xe] = '\0';
  local_a0[0xf] = '\0';
  snprintf(local_a0,100,"%llu MB\n",md_pageowner_dump_size >> 0x14);
  sVar2 = strnlen(local_a0,100);
  if (100 < sVar2) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar2 == 100) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("__fortify_strlen");
  }
  simple_read_from_buffer(param_2,param_3,param_4,local_a0);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// page_owner_dump_size_write @ 001072e0 size=220
// signature: undefined page_owner_dump_size_write(void)
// callers: []
//------------------------------------------------------------

undefined8 page_owner_dump_size_write(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = kstrtoull_from_user(param_2,param_3,0,&local_30);
  if (iVar2 == 0) {
    mutex_lock(page_owner_dump_size_lock);
    update_dump_size("PAGEOWNER",local_30,&md_pageowner_dump_addr,&md_pageowner_dump_size);
    mutex_unlock(page_owner_dump_size_lock);
  }
  else {
    iVar2 = ___ratelimit(page_owner_dump_size_write__rs,"page_owner_dump_size_write");
    if (iVar2 == 0) {
      param_3 = 0xffffffffffffffea;
    }
    else {
      _printk(&DAT_0020b8b5);
      param_3 = 0xffffffffffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// update_dump_size @ 001073bc size=424
// signature: undefined update_dump_size(void)
// callers: [dma_buf_info_size_write, dma_buf_procs_size_write, page_owner_dump_size_write, slab_owner_dump_size_write]
//------------------------------------------------------------

void update_dump_size(undefined8 param_1,long param_2,undefined8 *param_3,ulong *param_4)

{
  int iVar1;
  ulong uVar2;
  undefined *puVar3;
  
  if (*param_4 == 0) {
    uVar2 = md_register_memory_dump(param_2 << 0x14 & 0xffffffff,param_1);
    if ((uVar2 & 1) == 0) {
      return;
    }
    *param_4 = param_2 << 0x14;
    iVar1 = ___ratelimit(update_dump_size__rs,"update_dump_size");
    if (iVar1 == 0) {
      return;
    }
    puVar3 = &DAT_0020b425;
LAB_00107470:
    _printk(puVar3,param_1,param_2);
  }
  else {
    uVar2 = md_unregister_memory_dump(param_1);
    if ((uVar2 & 1) == 0) {
      iVar1 = ___ratelimit(update_dump_size__rs_101,"update_dump_size");
      if (iVar1 == 0) {
        return;
      }
      puVar3 = &DAT_0020b188;
    }
    else {
      *param_3 = 0;
      if (param_2 != 0) {
        uVar2 = md_register_memory_dump(param_2 << 0x14 & 0xffffffff,param_1);
        if ((uVar2 & 1) == 0) {
          uVar2 = md_register_memory_dump((int)*param_4,param_1);
          if ((uVar2 & 1) == 0) {
            iVar1 = ___ratelimit(update_dump_size__rs_99,"update_dump_size");
            if (iVar1 != 0) {
              _printk(&DAT_0020b4b0,param_1,*param_4 >> 0x14);
            }
            *param_4 = 0;
            return;
          }
          iVar1 = ___ratelimit(update_dump_size__rs_97,"update_dump_size");
          if (iVar1 == 0) {
            return;
          }
          _printk(&DAT_0020b0b3,param_1,*param_4 >> 0x14);
          return;
        }
        *param_4 = param_2 << 0x14;
        iVar1 = ___ratelimit(update_dump_size__rs_95,"update_dump_size");
        if (iVar1 == 0) {
          return;
        }
        puVar3 = &DAT_0020beb5;
        goto LAB_00107470;
      }
      *param_4 = 0;
      iVar1 = ___ratelimit(update_dump_size__rs_93,"update_dump_size");
      if (iVar1 == 0) {
        return;
      }
      puVar3 = &DAT_0020b8d0;
    }
    _printk(puVar3,param_1);
  }
  return;
}



//------------------------------------------------------------
// page_owner_filter_read @ 00107568 size=216
// signature: undefined page_owner_filter_read(void)
// callers: []
//------------------------------------------------------------

void page_owner_filter_read
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  size_t sVar2;
  char local_78 [64];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_78[0x30] = '\0';
  local_78[0x31] = '\0';
  local_78[0x32] = '\0';
  local_78[0x33] = '\0';
  local_78[0x34] = '\0';
  local_78[0x35] = '\0';
  local_78[0x36] = '\0';
  local_78[0x37] = '\0';
  local_78[0x38] = '\0';
  local_78[0x39] = '\0';
  local_78[0x3a] = '\0';
  local_78[0x3b] = '\0';
  local_78[0x3c] = '\0';
  local_78[0x3d] = '\0';
  local_78[0x3e] = '\0';
  local_78[0x3f] = '\0';
  local_78[0x20] = '\0';
  local_78[0x21] = '\0';
  local_78[0x22] = '\0';
  local_78[0x23] = '\0';
  local_78[0x24] = '\0';
  local_78[0x25] = '\0';
  local_78[0x26] = '\0';
  local_78[0x27] = '\0';
  local_78[0x28] = '\0';
  local_78[0x29] = '\0';
  local_78[0x2a] = '\0';
  local_78[0x2b] = '\0';
  local_78[0x2c] = '\0';
  local_78[0x2d] = '\0';
  local_78[0x2e] = '\0';
  local_78[0x2f] = '\0';
  local_78[0x10] = '\0';
  local_78[0x11] = '\0';
  local_78[0x12] = '\0';
  local_78[0x13] = '\0';
  local_78[0x14] = '\0';
  local_78[0x15] = '\0';
  local_78[0x16] = '\0';
  local_78[0x17] = '\0';
  local_78[0x18] = '\0';
  local_78[0x19] = '\0';
  local_78[0x1a] = '\0';
  local_78[0x1b] = '\0';
  local_78[0x1c] = '\0';
  local_78[0x1d] = '\0';
  local_78[0x1e] = '\0';
  local_78[0x1f] = '\0';
  local_78[0] = '\0';
  local_78[1] = '\0';
  local_78[2] = '\0';
  local_78[3] = '\0';
  local_78[4] = '\0';
  local_78[5] = '\0';
  local_78[6] = '\0';
  local_78[7] = '\0';
  local_78[8] = '\0';
  local_78[9] = '\0';
  local_78[10] = '\0';
  local_78[0xb] = '\0';
  local_78[0xc] = '\0';
  local_78[0xd] = '\0';
  local_78[0xe] = '\0';
  local_78[0xf] = '\0';
  snprintf(local_78,0x40,"0x%lx\n",page_owner_filter);
  sVar2 = strnlen(local_78,0x40);
  if (0x40 < sVar2) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar2 == 0x40) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("__fortify_strlen");
  }
  simple_read_from_buffer(param_2,param_3,param_4,local_78);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// page_owner_filter_write @ 00107644 size=212
// signature: undefined page_owner_filter_write(void)
// callers: []
//------------------------------------------------------------

undefined8 page_owner_filter_write(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = kstrtoul_from_user(param_2,param_3,0,&local_30);
  if (iVar2 == 0) {
    if (local_30 < 0x10) {
      page_owner_filter = local_30;
      goto LAB_001076e8;
    }
    iVar2 = ___ratelimit(page_owner_filter_write__rs_105,"page_owner_filter_write");
    if (iVar2 != 0) {
      puVar3 = &DAT_0020b64b;
      goto LAB_001076e0;
    }
  }
  else {
    iVar2 = ___ratelimit(page_owner_filter_write__rs,"page_owner_filter_write");
    if (iVar2 != 0) {
      puVar3 = &DAT_0020bbc9;
LAB_001076e0:
      _printk(puVar3);
    }
  }
  param_3 = 0xffffffffffffffea;
LAB_001076e8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// page_owner_handle_read @ 0010771c size=220
// signature: undefined page_owner_handle_read(void)
// callers: []
//------------------------------------------------------------

void page_owner_handle_read
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  size_t sVar2;
  char local_78 [64];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_78[0x30] = '\0';
  local_78[0x31] = '\0';
  local_78[0x32] = '\0';
  local_78[0x33] = '\0';
  local_78[0x34] = '\0';
  local_78[0x35] = '\0';
  local_78[0x36] = '\0';
  local_78[0x37] = '\0';
  local_78[0x38] = '\0';
  local_78[0x39] = '\0';
  local_78[0x3a] = '\0';
  local_78[0x3b] = '\0';
  local_78[0x3c] = '\0';
  local_78[0x3d] = '\0';
  local_78[0x3e] = '\0';
  local_78[0x3f] = '\0';
  local_78[0x20] = '\0';
  local_78[0x21] = '\0';
  local_78[0x22] = '\0';
  local_78[0x23] = '\0';
  local_78[0x24] = '\0';
  local_78[0x25] = '\0';
  local_78[0x26] = '\0';
  local_78[0x27] = '\0';
  local_78[0x28] = '\0';
  local_78[0x29] = '\0';
  local_78[0x2a] = '\0';
  local_78[0x2b] = '\0';
  local_78[0x2c] = '\0';
  local_78[0x2d] = '\0';
  local_78[0x2e] = '\0';
  local_78[0x2f] = '\0';
  local_78[0x10] = '\0';
  local_78[0x11] = '\0';
  local_78[0x12] = '\0';
  local_78[0x13] = '\0';
  local_78[0x14] = '\0';
  local_78[0x15] = '\0';
  local_78[0x16] = '\0';
  local_78[0x17] = '\0';
  local_78[0x18] = '\0';
  local_78[0x19] = '\0';
  local_78[0x1a] = '\0';
  local_78[0x1b] = '\0';
  local_78[0x1c] = '\0';
  local_78[0x1d] = '\0';
  local_78[0x1e] = '\0';
  local_78[0x1f] = '\0';
  local_78[0] = '\0';
  local_78[1] = '\0';
  local_78[2] = '\0';
  local_78[3] = '\0';
  local_78[4] = '\0';
  local_78[5] = '\0';
  local_78[6] = '\0';
  local_78[7] = '\0';
  local_78[8] = '\0';
  local_78[9] = '\0';
  local_78[10] = '\0';
  local_78[0xb] = '\0';
  local_78[0xc] = '\0';
  local_78[0xd] = '\0';
  local_78[0xe] = '\0';
  local_78[0xf] = '\0';
  snprintf(local_78,0x40,"%lu KB\n",page_owner_handles_size >> 10);
  sVar2 = strnlen(local_78,0x40);
  if (0x40 < sVar2) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar2 == 0x40) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("__fortify_strlen");
  }
  simple_read_from_buffer(param_2,param_3,param_4,local_78);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// page_owner_handle_write @ 001077fc size=248
// signature: undefined page_owner_handle_write(void)
// callers: []
//------------------------------------------------------------

undefined8 page_owner_handle_write(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = kstrtoul_from_user(param_2,param_3,0,&local_30);
  if (iVar2 == 0) {
    if (local_30 != 0) {
      if (md_pageowner_dump_size >> 0xe < local_30) {
        iVar2 = ___ratelimit(page_owner_handle_write__rs_109,"page_owner_handle_write");
        if (iVar2 != 0) {
          _printk(&DAT_0020ba3a,local_30,md_pageowner_dump_size >> 0xe);
        }
      }
      else {
        page_owner_handles_size = local_30 << 10;
      }
    }
  }
  else {
    iVar2 = ___ratelimit(page_owner_handle_write__rs,"page_owner_handle_write");
    if (iVar2 != 0) {
      _printk(&DAT_0020c041);
    }
    param_3 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// page_owner_call_site_read @ 001078f8 size=388
// signature: undefined page_owner_call_site_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long page_owner_call_site_read
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  char *__string;
  undefined8 uVar3;
  size_t sVar4;
  long lVar5;
  int iVar6;
  undefined **ppuVar7;
  
  __string = (char *)kmalloc_trace(___stack_chk_fail,0xcc0,0x1000);
  if (__string == (char *)0x0) {
    lVar5 = -0xc;
  }
  else {
    iVar1 = scnprintf(__string,param_3,&DAT_0020bba7,"Accounted call sites:");
    uVar3 = _raw_spin_lock_irqsave(&accounted_call_site_lock);
    if ((undefined **)accounted_call_site_list != &accounted_call_site_list) {
      iVar6 = 1;
      ppuVar7 = (undefined **)accounted_call_site_list;
      do {
        iVar2 = scnprintf(__string + iVar1,0x1000 - (long)iVar1,"%d. %s\n",iVar6,ppuVar7 + 2);
        iVar1 = iVar2 + iVar1;
        if (iVar1 == 0x1000) {
          _raw_spin_unlock_irqrestore(&accounted_call_site_lock,uVar3);
          lVar5 = -0xc;
          goto LAB_00107a34;
        }
        ppuVar7 = (undefined **)*ppuVar7;
        iVar6 = iVar6 + 1;
      } while (ppuVar7 != &accounted_call_site_list);
    }
    _raw_spin_unlock_irqrestore(&accounted_call_site_lock,uVar3);
    sVar4 = strnlen(__string,0x1000);
    if (0x1000 < sVar4) {
                    /* WARNING: Subroutine does not return */
      fortify_panic("strnlen");
    }
    if (sVar4 == 0x1000) {
                    /* WARNING: Subroutine does not return */
      fortify_panic("__fortify_strlen");
    }
    iVar1 = simple_read_from_buffer(param_2,param_3,param_4,__string,sVar4);
    lVar5 = (long)iVar1;
LAB_00107a34:
    kfree(__string);
  }
  return lVar5;
}



//------------------------------------------------------------
// page_owner_call_site_write @ 00107a80 size=812
// signature: undefined page_owner_call_site_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong page_owner_call_site_write(undefined8 param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  undefined *puVar4;
  ulong uVar5;
  size_t sVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  ulong uVar9;
  ulong local_80 [6];
  undefined2 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_50 = 0;
  local_80[4] = 0;
  local_80[5] = 0;
  local_80[2] = 0;
  local_80[3] = 0;
  local_80[0] = 0;
  local_80[1] = 0;
  if (param_3 < 0x32) {
    __check_object_size(local_80,param_3,0);
    puVar8 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
       (uVar9 = param_2, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
      uVar9 = param_2 & (long)(param_2 << 8) >> 8;
    }
    uVar5 = param_3;
    if (uVar9 <= 0x8000000000 - param_3) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar9 = daif;
        if ((uVar9 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        puVar8 = (undefined8 *)puVar8[1];
        uVar5 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar8 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar8;
        InstructionSynchronizationBarrier();
        daif = uVar9;
      }
      uVar5 = __arch_copy_from_user(puVar8,local_80,param_2 & 0xff7fffffffffffff,param_3);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar9 = daif;
        if ((uVar9 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar9;
      }
    }
    if (uVar5 != 0) {
      memset((void *)((long)local_80 + (param_3 - uVar5)),0,uVar5);
      iVar3 = ___ratelimit(page_owner_call_site_write__rs_115,"page_owner_call_site_write");
      if (iVar3 == 0) {
        param_3 = 0xfffffffffffffff2;
      }
      else {
        _printk(&DAT_0020c063);
        param_3 = 0xfffffffffffffff2;
      }
      goto LAB_00107c08;
    }
    if ((((&_ctype)[local_80[0] & 0xff] & 3) != 0) || ((char)local_80[0] == '_')) {
      puVar8 = (undefined8 *)kmalloc_trace(_memstart_addr,0xdc0,0x48);
      if (puVar8 != (undefined8 *)0x0) {
        uVar9 = strnlen((char *)(puVar8 + 2),0x38);
        if (uVar9 < 0x39) {
          if (uVar9 == 0x38) {
                    /* WARNING: Subroutine does not return */
            fortify_panic("__fortify_strlen");
          }
          sVar6 = uVar9;
          if (0x31 < uVar9) {
            sVar6 = 0x32;
          }
          sVar6 = strnlen((char *)local_80,sVar6);
          if ((sVar6 < 0x32) || (sVar6 == uVar9)) {
            if (sVar6 != uVar9) {
              uVar9 = sVar6 + 1;
            }
            if (0x38 < uVar9) {
                    /* WARNING: Subroutine does not return */
              fortify_panic("strscpy");
            }
            strscpy(puVar8 + 2,local_80);
            uVar7 = _raw_spin_lock_irqsave(&accounted_call_site_lock);
            puVar4 = PTR_accounted_call_site_list_0020c578;
            uVar9 = __list_add_valid(puVar8,PTR_accounted_call_site_list_0020c578,
                                     &accounted_call_site_list);
            if ((uVar9 & 1) != 0) {
              PTR_accounted_call_site_list_0020c578 = (undefined *)puVar8;
              *puVar8 = &accounted_call_site_list;
              puVar8[1] = puVar4;
              *(undefined8 **)puVar4 = puVar8;
            }
            _raw_spin_unlock_irqrestore(&accounted_call_site_lock,uVar7);
            goto LAB_00107c08;
          }
        }
                    /* WARNING: Subroutine does not return */
        fortify_panic("strnlen");
      }
      param_3 = 0xfffffffffffffff4;
      goto LAB_00107c08;
    }
    iVar3 = ___ratelimit(page_owner_call_site_write__rs_117,"page_owner_call_site_write");
    if (iVar3 != 0) {
      puVar4 = &DAT_0020c0fc;
      goto LAB_00107d1c;
    }
  }
  else {
    iVar3 = ___ratelimit(page_owner_call_site_write__rs,"page_owner_call_site_write");
    if (iVar3 != 0) {
      puVar4 = &DAT_0020b447;
LAB_00107d1c:
      _printk(puVar4);
    }
  }
  param_3 = 0xffffffffffffffea;
LAB_00107c08:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// slab_owner_dump_size_read @ 00107dc8 size=232
// signature: undefined slab_owner_dump_size_read(void)
// callers: []
//------------------------------------------------------------

void slab_owner_dump_size_read
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  size_t sVar2;
  char local_a0 [104];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_a0[0x60] = '\0';
  local_a0[0x61] = '\0';
  local_a0[0x62] = '\0';
  local_a0[99] = '\0';
  local_a0[0x50] = '\0';
  local_a0[0x51] = '\0';
  local_a0[0x52] = '\0';
  local_a0[0x53] = '\0';
  local_a0[0x54] = '\0';
  local_a0[0x55] = '\0';
  local_a0[0x56] = '\0';
  local_a0[0x57] = '\0';
  local_a0[0x58] = '\0';
  local_a0[0x59] = '\0';
  local_a0[0x5a] = '\0';
  local_a0[0x5b] = '\0';
  local_a0[0x5c] = '\0';
  local_a0[0x5d] = '\0';
  local_a0[0x5e] = '\0';
  local_a0[0x5f] = '\0';
  local_a0[0x40] = '\0';
  local_a0[0x41] = '\0';
  local_a0[0x42] = '\0';
  local_a0[0x43] = '\0';
  local_a0[0x44] = '\0';
  local_a0[0x45] = '\0';
  local_a0[0x46] = '\0';
  local_a0[0x47] = '\0';
  local_a0[0x48] = '\0';
  local_a0[0x49] = '\0';
  local_a0[0x4a] = '\0';
  local_a0[0x4b] = '\0';
  local_a0[0x4c] = '\0';
  local_a0[0x4d] = '\0';
  local_a0[0x4e] = '\0';
  local_a0[0x4f] = '\0';
  local_a0[0x30] = '\0';
  local_a0[0x31] = '\0';
  local_a0[0x32] = '\0';
  local_a0[0x33] = '\0';
  local_a0[0x34] = '\0';
  local_a0[0x35] = '\0';
  local_a0[0x36] = '\0';
  local_a0[0x37] = '\0';
  local_a0[0x38] = '\0';
  local_a0[0x39] = '\0';
  local_a0[0x3a] = '\0';
  local_a0[0x3b] = '\0';
  local_a0[0x3c] = '\0';
  local_a0[0x3d] = '\0';
  local_a0[0x3e] = '\0';
  local_a0[0x3f] = '\0';
  local_a0[0x20] = '\0';
  local_a0[0x21] = '\0';
  local_a0[0x22] = '\0';
  local_a0[0x23] = '\0';
  local_a0[0x24] = '\0';
  local_a0[0x25] = '\0';
  local_a0[0x26] = '\0';
  local_a0[0x27] = '\0';
  local_a0[0x28] = '\0';
  local_a0[0x29] = '\0';
  local_a0[0x2a] = '\0';
  local_a0[0x2b] = '\0';
  local_a0[0x2c] = '\0';
  local_a0[0x2d] = '\0';
  local_a0[0x2e] = '\0';
  local_a0[0x2f] = '\0';
  local_a0[0x10] = '\0';
  local_a0[0x11] = '\0';
  local_a0[0x12] = '\0';
  local_a0[0x13] = '\0';
  local_a0[0x14] = '\0';
  local_a0[0x15] = '\0';
  local_a0[0x16] = '\0';
  local_a0[0x17] = '\0';
  local_a0[0x18] = '\0';
  local_a0[0x19] = '\0';
  local_a0[0x1a] = '\0';
  local_a0[0x1b] = '\0';
  local_a0[0x1c] = '\0';
  local_a0[0x1d] = '\0';
  local_a0[0x1e] = '\0';
  local_a0[0x1f] = '\0';
  local_a0[0] = '\0';
  local_a0[1] = '\0';
  local_a0[2] = '\0';
  local_a0[3] = '\0';
  local_a0[4] = '\0';
  local_a0[5] = '\0';
  local_a0[6] = '\0';
  local_a0[7] = '\0';
  local_a0[8] = '\0';
  local_a0[9] = '\0';
  local_a0[10] = '\0';
  local_a0[0xb] = '\0';
  local_a0[0xc] = '\0';
  local_a0[0xd] = '\0';
  local_a0[0xe] = '\0';
  local_a0[0xf] = '\0';
  snprintf(local_a0,100,"%llu MB\n",md_slabowner_dump_size >> 0x14);
  sVar2 = strnlen(local_a0,100);
  if (100 < sVar2) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar2 == 100) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("__fortify_strlen");
  }
  simple_read_from_buffer(param_2,param_3,param_4,local_a0);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// slab_owner_dump_size_write @ 00107eb4 size=196
// signature: undefined slab_owner_dump_size_write(void)
// callers: []
//------------------------------------------------------------

undefined8 slab_owner_dump_size_write(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = kstrtoull_from_user(param_2,param_3,0,&local_30);
  if (iVar2 == 0) {
    update_dump_size("SLABOWNER",local_30,&md_slabowner_dump_addr,&md_slabowner_dump_size);
  }
  else {
    iVar2 = ___ratelimit(slab_owner_dump_size_write__rs,"slab_owner_dump_size_write");
    if (iVar2 == 0) {
      param_3 = 0xffffffffffffffea;
    }
    else {
      _printk(&DAT_0020b8b5);
      param_3 = 0xffffffffffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// slab_owner_filter_read @ 00107f7c size=216
// signature: undefined slab_owner_filter_read(void)
// callers: []
//------------------------------------------------------------

void slab_owner_filter_read
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  size_t sVar2;
  char local_78 [64];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_78[0x30] = '\0';
  local_78[0x31] = '\0';
  local_78[0x32] = '\0';
  local_78[0x33] = '\0';
  local_78[0x34] = '\0';
  local_78[0x35] = '\0';
  local_78[0x36] = '\0';
  local_78[0x37] = '\0';
  local_78[0x38] = '\0';
  local_78[0x39] = '\0';
  local_78[0x3a] = '\0';
  local_78[0x3b] = '\0';
  local_78[0x3c] = '\0';
  local_78[0x3d] = '\0';
  local_78[0x3e] = '\0';
  local_78[0x3f] = '\0';
  local_78[0x20] = '\0';
  local_78[0x21] = '\0';
  local_78[0x22] = '\0';
  local_78[0x23] = '\0';
  local_78[0x24] = '\0';
  local_78[0x25] = '\0';
  local_78[0x26] = '\0';
  local_78[0x27] = '\0';
  local_78[0x28] = '\0';
  local_78[0x29] = '\0';
  local_78[0x2a] = '\0';
  local_78[0x2b] = '\0';
  local_78[0x2c] = '\0';
  local_78[0x2d] = '\0';
  local_78[0x2e] = '\0';
  local_78[0x2f] = '\0';
  local_78[0x10] = '\0';
  local_78[0x11] = '\0';
  local_78[0x12] = '\0';
  local_78[0x13] = '\0';
  local_78[0x14] = '\0';
  local_78[0x15] = '\0';
  local_78[0x16] = '\0';
  local_78[0x17] = '\0';
  local_78[0x18] = '\0';
  local_78[0x19] = '\0';
  local_78[0x1a] = '\0';
  local_78[0x1b] = '\0';
  local_78[0x1c] = '\0';
  local_78[0x1d] = '\0';
  local_78[0x1e] = '\0';
  local_78[0x1f] = '\0';
  local_78[0] = '\0';
  local_78[1] = '\0';
  local_78[2] = '\0';
  local_78[3] = '\0';
  local_78[4] = '\0';
  local_78[5] = '\0';
  local_78[6] = '\0';
  local_78[7] = '\0';
  local_78[8] = '\0';
  local_78[9] = '\0';
  local_78[10] = '\0';
  local_78[0xb] = '\0';
  local_78[0xc] = '\0';
  local_78[0xd] = '\0';
  local_78[0xe] = '\0';
  local_78[0xf] = '\0';
  snprintf(local_78,0x40,"0x%lx\n",slab_owner_filter);
  sVar2 = strnlen(local_78,0x40);
  if (0x40 < sVar2) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar2 == 0x40) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("__fortify_strlen");
  }
  simple_read_from_buffer(param_2,param_3,param_4,local_78);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// slab_owner_filter_write @ 00108058 size=272
// signature: undefined slab_owner_filter_write(void)
// callers: []
//------------------------------------------------------------

undefined8 slab_owner_filter_write(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar3 = kstrtoul_from_user(param_2,param_3,0,&local_30);
  if (iVar3 == 0) {
    if (local_30 != 0) {
      uVar5 = 1;
      uVar4 = 0;
      iVar3 = 1;
      do {
        if ((local_30 & uVar5) != 0) {
          if (0xd < (uint)uVar4) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x108164);
            (*pcVar2)();
          }
          if (*(long *)(&kmalloc_caches + uVar4 * 8) == 0) {
            _printk(&DAT_0020bc42);
            param_3 = 0xffffffffffffffea;
            goto LAB_00108120;
          }
        }
        iVar3 = iVar3 << 1;
        uVar4 = (ulong)((uint)uVar4 + 1);
        uVar5 = (ulong)iVar3;
      } while (uVar5 <= local_30);
    }
    slab_owner_filter = local_30;
  }
  else {
    iVar3 = ___ratelimit(slab_owner_filter_write__rs,"slab_owner_filter_write");
    if (iVar3 == 0) {
      param_3 = 0xffffffffffffffea;
    }
    else {
      _printk(&DAT_0020bbc9);
      param_3 = 0xffffffffffffffea;
    }
  }
LAB_00108120:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// slab_owner_handle_read @ 0010816c size=220
// signature: undefined slab_owner_handle_read(void)
// callers: []
//------------------------------------------------------------

void slab_owner_handle_read
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  size_t sVar2;
  char local_78 [64];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_78[0x30] = '\0';
  local_78[0x31] = '\0';
  local_78[0x32] = '\0';
  local_78[0x33] = '\0';
  local_78[0x34] = '\0';
  local_78[0x35] = '\0';
  local_78[0x36] = '\0';
  local_78[0x37] = '\0';
  local_78[0x38] = '\0';
  local_78[0x39] = '\0';
  local_78[0x3a] = '\0';
  local_78[0x3b] = '\0';
  local_78[0x3c] = '\0';
  local_78[0x3d] = '\0';
  local_78[0x3e] = '\0';
  local_78[0x3f] = '\0';
  local_78[0x20] = '\0';
  local_78[0x21] = '\0';
  local_78[0x22] = '\0';
  local_78[0x23] = '\0';
  local_78[0x24] = '\0';
  local_78[0x25] = '\0';
  local_78[0x26] = '\0';
  local_78[0x27] = '\0';
  local_78[0x28] = '\0';
  local_78[0x29] = '\0';
  local_78[0x2a] = '\0';
  local_78[0x2b] = '\0';
  local_78[0x2c] = '\0';
  local_78[0x2d] = '\0';
  local_78[0x2e] = '\0';
  local_78[0x2f] = '\0';
  local_78[0x10] = '\0';
  local_78[0x11] = '\0';
  local_78[0x12] = '\0';
  local_78[0x13] = '\0';
  local_78[0x14] = '\0';
  local_78[0x15] = '\0';
  local_78[0x16] = '\0';
  local_78[0x17] = '\0';
  local_78[0x18] = '\0';
  local_78[0x19] = '\0';
  local_78[0x1a] = '\0';
  local_78[0x1b] = '\0';
  local_78[0x1c] = '\0';
  local_78[0x1d] = '\0';
  local_78[0x1e] = '\0';
  local_78[0x1f] = '\0';
  local_78[0] = '\0';
  local_78[1] = '\0';
  local_78[2] = '\0';
  local_78[3] = '\0';
  local_78[4] = '\0';
  local_78[5] = '\0';
  local_78[6] = '\0';
  local_78[7] = '\0';
  local_78[8] = '\0';
  local_78[9] = '\0';
  local_78[10] = '\0';
  local_78[0xb] = '\0';
  local_78[0xc] = '\0';
  local_78[0xd] = '\0';
  local_78[0xe] = '\0';
  local_78[0xf] = '\0';
  snprintf(local_78,0x40,"%lu KB\n",slab_owner_handles_size >> 10);
  sVar2 = strnlen(local_78,0x40);
  if (0x40 < sVar2) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar2 == 0x40) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("__fortify_strlen");
  }
  simple_read_from_buffer(param_2,param_3,param_4,local_78);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// slab_owner_handle_write @ 0010824c size=248
// signature: undefined slab_owner_handle_write(void)
// callers: []
//------------------------------------------------------------

undefined8 slab_owner_handle_write(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = kstrtoul_from_user(param_2,param_3,0,&local_30);
  if (iVar2 == 0) {
    if (local_30 != 0) {
      if (md_slabowner_dump_size >> 0xe < local_30) {
        iVar2 = ___ratelimit(slab_owner_handle_write__rs_121,"slab_owner_handle_write");
        if (iVar2 != 0) {
          _printk(&DAT_0020ba3a,local_30,md_slabowner_dump_size >> 0xe);
        }
      }
      else {
        slab_owner_handles_size = local_30 << 10;
      }
    }
  }
  else {
    iVar2 = ___ratelimit(slab_owner_handle_write__rs,"slab_owner_handle_write");
    if (iVar2 != 0) {
      _printk(&DAT_0020c041);
    }
    param_3 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// dma_buf_info_size_read @ 00108348 size=232
// signature: undefined dma_buf_info_size_read(void)
// callers: []
//------------------------------------------------------------

void dma_buf_info_size_read
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  size_t sVar2;
  char local_a0 [104];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_a0[0x60] = '\0';
  local_a0[0x61] = '\0';
  local_a0[0x62] = '\0';
  local_a0[99] = '\0';
  local_a0[0x50] = '\0';
  local_a0[0x51] = '\0';
  local_a0[0x52] = '\0';
  local_a0[0x53] = '\0';
  local_a0[0x54] = '\0';
  local_a0[0x55] = '\0';
  local_a0[0x56] = '\0';
  local_a0[0x57] = '\0';
  local_a0[0x58] = '\0';
  local_a0[0x59] = '\0';
  local_a0[0x5a] = '\0';
  local_a0[0x5b] = '\0';
  local_a0[0x5c] = '\0';
  local_a0[0x5d] = '\0';
  local_a0[0x5e] = '\0';
  local_a0[0x5f] = '\0';
  local_a0[0x40] = '\0';
  local_a0[0x41] = '\0';
  local_a0[0x42] = '\0';
  local_a0[0x43] = '\0';
  local_a0[0x44] = '\0';
  local_a0[0x45] = '\0';
  local_a0[0x46] = '\0';
  local_a0[0x47] = '\0';
  local_a0[0x48] = '\0';
  local_a0[0x49] = '\0';
  local_a0[0x4a] = '\0';
  local_a0[0x4b] = '\0';
  local_a0[0x4c] = '\0';
  local_a0[0x4d] = '\0';
  local_a0[0x4e] = '\0';
  local_a0[0x4f] = '\0';
  local_a0[0x30] = '\0';
  local_a0[0x31] = '\0';
  local_a0[0x32] = '\0';
  local_a0[0x33] = '\0';
  local_a0[0x34] = '\0';
  local_a0[0x35] = '\0';
  local_a0[0x36] = '\0';
  local_a0[0x37] = '\0';
  local_a0[0x38] = '\0';
  local_a0[0x39] = '\0';
  local_a0[0x3a] = '\0';
  local_a0[0x3b] = '\0';
  local_a0[0x3c] = '\0';
  local_a0[0x3d] = '\0';
  local_a0[0x3e] = '\0';
  local_a0[0x3f] = '\0';
  local_a0[0x20] = '\0';
  local_a0[0x21] = '\0';
  local_a0[0x22] = '\0';
  local_a0[0x23] = '\0';
  local_a0[0x24] = '\0';
  local_a0[0x25] = '\0';
  local_a0[0x26] = '\0';
  local_a0[0x27] = '\0';
  local_a0[0x28] = '\0';
  local_a0[0x29] = '\0';
  local_a0[0x2a] = '\0';
  local_a0[0x2b] = '\0';
  local_a0[0x2c] = '\0';
  local_a0[0x2d] = '\0';
  local_a0[0x2e] = '\0';
  local_a0[0x2f] = '\0';
  local_a0[0x10] = '\0';
  local_a0[0x11] = '\0';
  local_a0[0x12] = '\0';
  local_a0[0x13] = '\0';
  local_a0[0x14] = '\0';
  local_a0[0x15] = '\0';
  local_a0[0x16] = '\0';
  local_a0[0x17] = '\0';
  local_a0[0x18] = '\0';
  local_a0[0x19] = '\0';
  local_a0[0x1a] = '\0';
  local_a0[0x1b] = '\0';
  local_a0[0x1c] = '\0';
  local_a0[0x1d] = '\0';
  local_a0[0x1e] = '\0';
  local_a0[0x1f] = '\0';
  local_a0[0] = '\0';
  local_a0[1] = '\0';
  local_a0[2] = '\0';
  local_a0[3] = '\0';
  local_a0[4] = '\0';
  local_a0[5] = '\0';
  local_a0[6] = '\0';
  local_a0[7] = '\0';
  local_a0[8] = '\0';
  local_a0[9] = '\0';
  local_a0[10] = '\0';
  local_a0[0xb] = '\0';
  local_a0[0xc] = '\0';
  local_a0[0xd] = '\0';
  local_a0[0xe] = '\0';
  local_a0[0xf] = '\0';
  snprintf(local_a0,100,"%llu MB\n",md_dma_buf_info_size >> 0x14);
  sVar2 = strnlen(local_a0,100);
  if (100 < sVar2) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar2 == 100) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("__fortify_strlen");
  }
  simple_read_from_buffer(param_2,param_3,param_4,local_a0);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// dma_buf_info_size_write @ 00108434 size=196
// signature: undefined dma_buf_info_size_write(void)
// callers: []
//------------------------------------------------------------

undefined8 dma_buf_info_size_write(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = kstrtoull_from_user(param_2,param_3,0,&local_30);
  if (iVar2 == 0) {
    update_dump_size("DMA_INFO",local_30,&md_dma_buf_info_addr,&md_dma_buf_info_size);
  }
  else {
    iVar2 = ___ratelimit(dma_buf_info_size_write__rs,"dma_buf_info_size_write");
    if (iVar2 == 0) {
      param_3 = 0xffffffffffffffea;
    }
    else {
      _printk(&DAT_0020b8b5);
      param_3 = 0xffffffffffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// dma_buf_procs_size_read @ 001084fc size=232
// signature: undefined dma_buf_procs_size_read(void)
// callers: []
//------------------------------------------------------------

void dma_buf_procs_size_read
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  size_t sVar2;
  char local_a0 [104];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_a0[0x60] = '\0';
  local_a0[0x61] = '\0';
  local_a0[0x62] = '\0';
  local_a0[99] = '\0';
  local_a0[0x50] = '\0';
  local_a0[0x51] = '\0';
  local_a0[0x52] = '\0';
  local_a0[0x53] = '\0';
  local_a0[0x54] = '\0';
  local_a0[0x55] = '\0';
  local_a0[0x56] = '\0';
  local_a0[0x57] = '\0';
  local_a0[0x58] = '\0';
  local_a0[0x59] = '\0';
  local_a0[0x5a] = '\0';
  local_a0[0x5b] = '\0';
  local_a0[0x5c] = '\0';
  local_a0[0x5d] = '\0';
  local_a0[0x5e] = '\0';
  local_a0[0x5f] = '\0';
  local_a0[0x40] = '\0';
  local_a0[0x41] = '\0';
  local_a0[0x42] = '\0';
  local_a0[0x43] = '\0';
  local_a0[0x44] = '\0';
  local_a0[0x45] = '\0';
  local_a0[0x46] = '\0';
  local_a0[0x47] = '\0';
  local_a0[0x48] = '\0';
  local_a0[0x49] = '\0';
  local_a0[0x4a] = '\0';
  local_a0[0x4b] = '\0';
  local_a0[0x4c] = '\0';
  local_a0[0x4d] = '\0';
  local_a0[0x4e] = '\0';
  local_a0[0x4f] = '\0';
  local_a0[0x30] = '\0';
  local_a0[0x31] = '\0';
  local_a0[0x32] = '\0';
  local_a0[0x33] = '\0';
  local_a0[0x34] = '\0';
  local_a0[0x35] = '\0';
  local_a0[0x36] = '\0';
  local_a0[0x37] = '\0';
  local_a0[0x38] = '\0';
  local_a0[0x39] = '\0';
  local_a0[0x3a] = '\0';
  local_a0[0x3b] = '\0';
  local_a0[0x3c] = '\0';
  local_a0[0x3d] = '\0';
  local_a0[0x3e] = '\0';
  local_a0[0x3f] = '\0';
  local_a0[0x20] = '\0';
  local_a0[0x21] = '\0';
  local_a0[0x22] = '\0';
  local_a0[0x23] = '\0';
  local_a0[0x24] = '\0';
  local_a0[0x25] = '\0';
  local_a0[0x26] = '\0';
  local_a0[0x27] = '\0';
  local_a0[0x28] = '\0';
  local_a0[0x29] = '\0';
  local_a0[0x2a] = '\0';
  local_a0[0x2b] = '\0';
  local_a0[0x2c] = '\0';
  local_a0[0x2d] = '\0';
  local_a0[0x2e] = '\0';
  local_a0[0x2f] = '\0';
  local_a0[0x10] = '\0';
  local_a0[0x11] = '\0';
  local_a0[0x12] = '\0';
  local_a0[0x13] = '\0';
  local_a0[0x14] = '\0';
  local_a0[0x15] = '\0';
  local_a0[0x16] = '\0';
  local_a0[0x17] = '\0';
  local_a0[0x18] = '\0';
  local_a0[0x19] = '\0';
  local_a0[0x1a] = '\0';
  local_a0[0x1b] = '\0';
  local_a0[0x1c] = '\0';
  local_a0[0x1d] = '\0';
  local_a0[0x1e] = '\0';
  local_a0[0x1f] = '\0';
  local_a0[0] = '\0';
  local_a0[1] = '\0';
  local_a0[2] = '\0';
  local_a0[3] = '\0';
  local_a0[4] = '\0';
  local_a0[5] = '\0';
  local_a0[6] = '\0';
  local_a0[7] = '\0';
  local_a0[8] = '\0';
  local_a0[9] = '\0';
  local_a0[10] = '\0';
  local_a0[0xb] = '\0';
  local_a0[0xc] = '\0';
  local_a0[0xd] = '\0';
  local_a0[0xe] = '\0';
  local_a0[0xf] = '\0';
  snprintf(local_a0,100,"%llu MB\n",md_dma_buf_procs_size >> 0x14);
  sVar2 = strnlen(local_a0,100);
  if (100 < sVar2) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar2 == 100) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("__fortify_strlen");
  }
  simple_read_from_buffer(param_2,param_3,param_4,local_a0);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// dma_buf_procs_size_write @ 001085e8 size=196
// signature: undefined dma_buf_procs_size_write(void)
// callers: []
//------------------------------------------------------------

undefined8 dma_buf_procs_size_write(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = kstrtoull_from_user(param_2,param_3,0,&local_30);
  if (iVar2 == 0) {
    update_dump_size("DMA_PROC",local_30,&md_dma_buf_procs_addr,&md_dma_buf_procs_size);
  }
  else {
    iVar2 = ___ratelimit(dma_buf_procs_size_write__rs,"dma_buf_procs_size_write");
    if (iVar2 == 0) {
      param_3 = 0xffffffffffffffea;
    }
    else {
      _printk(&DAT_0020b8b5);
      param_3 = 0xffffffffffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// init_module @ 0020d7b4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&msm_minidump_smem_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0020d7e4 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&msm_minidump_smem_driver);
  return;
}



//------------------------------------------------------------
// strscpy @ 00210000 size=1
// signature: undefined strscpy(void)
// callers: [md_add_elf_header, md_smem_add_header, md_unregister_memory_dump, md_register_minidump_entry, md_add_ss_toc, page_owner_call_site_write, msm_minidump_log_init, set_section_name, md_register_memory_dump, msm_minidump_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00210008 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [msm_minidump_clear_headers, md_smem_add_region, md_smem_update_region, md_smem_get_region, md_module_process, md_add_ss_toc, md_register_memory_dump, md_smem_remove_region]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00210010 size=1
// signature: size_t strlen(char * __s)
// callers: [md_dump_pageowner, msm_minidump_clear_headers, msm_minidump_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memmove @ 00210018 size=1
// signature: void * memmove(void * __dest, void * __src, size_t __n)
// callers: [msm_minidump_clear_headers, md_smem_remove_region]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memmove(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk_deferred @ 00210020 size=1
// signature: undefined _printk_deferred(void)
// callers: [msm_minidump_clear_headers, md_smem_add_region, md_smem_update_region, msm_minidump_remove_region, dump_stack_minidump, msm_minidump_add_region, msm_minidump_update_region, md_smem_remove_region]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk_deferred(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00210028 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [page_owner_handle_read, md_add_ss_toc, dma_buf_procs_size_read, msm_minidump_add_region, slab_owner_filter_read, page_owner_dump_size_read, dma_buf_info_size_read, md_unregister_memory_dump, page_owner_filter_read, page_owner_call_site_read, slab_owner_dump_size_read, md_register_minidump_entry, page_owner_call_site_write, slab_owner_handle_read, md_register_memory_dump, msm_minidump_update_region]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00210030 size=1
// signature: noreturn undefined fortify_panic(void)
// callers: [page_owner_handle_read, md_add_ss_toc, dma_buf_procs_size_read, msm_minidump_add_region, slab_owner_filter_read, page_owner_dump_size_read, dma_buf_info_size_read, md_unregister_memory_dump, page_owner_filter_read, page_owner_call_site_read, slab_owner_dump_size_read, md_register_minidump_entry, page_owner_call_site_write, slab_owner_handle_read, md_register_memory_dump, msm_minidump_update_region]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00210038 size=1
// signature: undefined _printk(void)
// callers: [md_dump_process, md_dump_pageowner, dump_tracking, md_dump_slabowner, slab_owner_filter_write, md_smem_init_md_table, page_owner_handle_write, update_dump_size, md_module_process, msm_minidump_log_init, md_register_minidump_entry, page_owner_call_site_write, md_register_memory_dump, page_owner_filter_write, dma_buf_procs_size_write, slab_owner_handle_write, md_minidump_memory_init, md_dma_buf_procs, page_owner_dump_size_write, dump_stack_minidump, msm_minidump_add_region, msm_minidump_driver_probe, dump_bufinfo, dma_buf_info_size_write, md_buf_size_check, md_unregister_memory_dump, slab_owner_dump_size_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00210040 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [md_dump_pageowner, md_smem_add_region, md_dump_slabowner, md_smem_get_available_region, md_smem_md_enable, page_owner_call_site_read, page_owner_call_site_write, md_smem_add_pending_entry, msm_minidump_add_region, md_smem_remove_region]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00210050 size=1
// signature: undefined kmalloc_trace(void)
// callers: [md_smem_init_md_table, page_owner_call_site_read, page_owner_call_site_write, md_register_panic_entries, msm_minidump_add_region]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00210058 size=1
// signature: undefined __list_add_valid(void)
// callers: [page_owner_call_site_write, msm_minidump_add_region]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00210060 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [md_dump_pageowner, md_smem_add_region, md_dump_slabowner, md_smem_get_available_region, md_smem_md_enable, page_owner_call_site_read, page_owner_call_site_write, md_smem_add_pending_entry, msm_minidump_add_region, md_smem_remove_region]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debug_symbol_available @ 00210068 size=1
// signature: undefined debug_symbol_available(void)
// callers: [msm_minidump_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debug_symbol_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debug_symbol_lookup_name @ 00210070 size=1
// signature: undefined debug_symbol_lookup_name(void)
// callers: [md_dump_process, md_minidump_memory_init, msm_minidump_log_init, msm_minidump_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debug_symbol_lookup_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00210078 size=1
// signature: undefined __kmalloc(void)
// callers: [md_register_panic_entries, msm_minidump_log_init, msm_minidump_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00210098 size=1
// signature: undefined scnprintf(void)
// callers: [md_dump_pageowner, dump_tracking, md_dump_slabowner, md_dma_buf_procs, page_owner_call_site_read, md_dma_buf_info, dump_stack_minidump, get_dma_info, dump_bufinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmalloc_to_page @ 002100a0 size=1
// signature: undefined vmalloc_to_page(void)
// callers: [md_module_process, dump_stack_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmalloc_to_page(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 002100a8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [md_dump_process, md_dump_pageowner, dump_tracking, md_dump_slabowner, slab_owner_filter_write, md_smem_init_md_table, page_owner_handle_write, page_owner_handle_read, md_module_process, msm_minidump_log_init, dma_buf_procs_size_read, page_owner_dump_size_read, dma_buf_info_size_read, md_register_minidump_entry, md_dump_data, page_owner_call_site_write, md_register_memory_dump, page_owner_filter_write, dma_buf_procs_size_write, slab_owner_handle_write, md_dma_buf_procs, md_dump_slabinfo, page_owner_dump_size_write, dump_stack_minidump, md_dump_meminfo, dump_bufinfo, dma_buf_info_size_write, slab_owner_filter_read, md_unregister_memory_dump, page_owner_filter_read, md_dma_buf_info, slab_owner_dump_size_read, slab_owner_handle_read, slab_owner_dump_size_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 002100b8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [md_dump_process, md_dma_buf_procs, page_owner_call_site_write, md_register_memory_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_buf_printf @ 002100c0 size=1
// signature: undefined seq_buf_printf(void)
// callers: [md_dump_process, md_dump_slabinfo, md_die_context_notify, md_module_process, md_dump_data, md_dump_cgroup_state, md_dump_task_info, msm_minidump_log_init, md_dump_meminfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_buf_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 002100d8 size=1
// signature: undefined _find_next_bit(void)
// callers: [md_dump_process, msm_minidump_log_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_first_bit @ 002100f0 size=1
// signature: undefined _find_first_bit(void)
// callers: [md_dump_process]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_first_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_compatible_node @ 00210100 size=1
// signature: undefined of_find_compatible_node(void)
// callers: [msm_minidump_log_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_compatible_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 00210108 size=1
// signature: undefined of_address_to_resource(void)
// callers: [msm_minidump_log_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_lookup @ 00210110 size=1
// signature: undefined of_reserved_mem_lookup(void)
// callers: [msm_minidump_log_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00210118 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [msm_minidump_log_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_large @ 00210120 size=1
// signature: undefined kmalloc_large(void)
// callers: [msm_minidump_log_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_large(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 00210130 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [msm_minidump_log_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_module_notifier @ 00210178 size=1
// signature: undefined register_module_notifier(void)
// callers: [msm_minidump_log_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_module_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00210180 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [msm_minidump_log_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_chain_register @ 00210198 size=1
// signature: undefined atomic_notifier_chain_register(void)
// callers: [msm_minidump_log_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_die_notifier @ 002101a0 size=1
// signature: undefined register_die_notifier(void)
// callers: [msm_minidump_log_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_die_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule @ 002101a8 size=1
// signature: undefined preempt_schedule(void)
// callers: [msm_minidump_log_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// copy_from_kernel_nofault @ 002101b0 size=1
// signature: undefined copy_from_kernel_nofault(void)
// callers: [md_dump_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void copy_from_kernel_nofault(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rb_first @ 002101b8 size=1
// signature: undefined rb_first(void)
// callers: [md_dump_cfs_rq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rb_first(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rb_next @ 002101c0 size=1
// signature: undefined rb_next(void)
// callers: [md_dump_cfs_rq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rb_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 002101c8 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [md_ipi_stop, md_dump_trace_buf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_clock @ 002101d0 size=1
// signature: undefined sched_clock(void)
// callers: [log_cpu_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sched_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 002101d8 size=1
// signature: undefined kfree(void)
// callers: [page_owner_call_site_read, md_register_panic_entries, md_smem_add_pending_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 002101e0 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [slab_owner_filter_read, page_owner_dump_size_read, dma_buf_info_size_read, page_owner_filter_read, page_owner_handle_read, slab_owner_dump_size_read, md_module_process, slab_owner_handle_read, dma_buf_procs_size_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 002101e8 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [md_module_notify, md_dma_buf_procs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 002101f0 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [md_module_notify, md_dma_buf_procs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00210208 size=1
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
// platform_driver_unregister @ 00210210 size=1
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
// qcom_smem_get @ 00210218 size=1
// signature: undefined qcom_smem_get(void)
// callers: [md_smem_init_md_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00210220 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [md_smem_add_pending_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_lock @ 00210228 size=1
// signature: undefined _raw_write_lock(void)
// callers: [md_smem_remove_region]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_unlock @ 00210230 size=1
// signature: undefined _raw_write_unlock(void)
// callers: [md_smem_remove_region]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_lock_irqsave @ 00210238 size=1
// signature: undefined _raw_read_lock_irqsave(void)
// callers: [md_smem_update_region]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_unlock_irqrestore @ 00210240 size=1
// signature: undefined _raw_read_unlock_irqrestore(void)
// callers: [md_smem_update_region]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// si_meminfo @ 00210248 size=1
// signature: undefined si_meminfo(void)
// callers: [md_dump_meminfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void si_meminfo(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// si_swapinfo @ 00210250 size=1
// signature: undefined si_swapinfo(void)
// callers: [md_dump_meminfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void si_swapinfo(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// si_mem_available @ 00210260 size=1
// signature: undefined si_mem_available(void)
// callers: [md_dump_meminfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void si_mem_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmalloc_nr_pages @ 00210270 size=1
// signature: undefined vmalloc_nr_pages(void)
// callers: [md_dump_meminfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmalloc_nr_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pcpu_nr_pages @ 00210278 size=1
// signature: undefined pcpu_nr_pages(void)
// callers: [md_dump_meminfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pcpu_nr_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_trylock @ 00210280 size=1
// signature: undefined mutex_trylock(void)
// callers: [md_dump_slabinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_slabinfo @ 00210288 size=1
// signature: undefined get_slabinfo(void)
// callers: [md_dump_slabinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_slabinfo(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00210290 size=1
// signature: undefined mutex_unlock(void)
// callers: [md_dump_slabinfo, page_owner_dump_size_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cma_alloc @ 002102a0 size=1
// signature: undefined cma_alloc(void)
// callers: [md_register_memory_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cma_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cma_release @ 002102b0 size=1
// signature: undefined cma_release(void)
// callers: [md_unregister_memory_dump, md_register_memory_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cma_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// page_ext_get @ 002102c0 size=1
// signature: undefined page_ext_get(void)
// callers: [md_dump_pageowner]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void page_ext_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_page_owner_handle @ 002102c8 size=1
// signature: undefined get_page_owner_handle(void)
// callers: [md_dump_pageowner]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_page_owner_handle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// stack_depot_fetch @ 002102d0 size=1
// signature: undefined stack_depot_fetch(void)
// callers: [md_dump_pageowner, dump_tracking]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void stack_depot_fetch(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 002102d8 size=1
// signature: undefined strnstr(void)
// callers: [md_dump_pageowner]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 002102e0 size=1
// signature: undefined ___ratelimit(void)
// callers: [md_dump_pageowner, dump_tracking, dma_buf_info_size_write, page_owner_filter_write, dma_buf_procs_size_write, slab_owner_handle_write, slab_owner_filter_write, page_owner_handle_write, update_dump_size, page_owner_dump_size_write, page_owner_call_site_write, slab_owner_dump_size_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// page_ext_put @ 002102e8 size=1
// signature: undefined page_ext_put(void)
// callers: [md_dump_pageowner]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void page_ext_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 002102f0 size=1
// signature: undefined debugfs_create_file(void)
// callers: [md_debugfs_dmabufinfo, md_debugfs_pageowner, md_debugfs_slabowner, md_debugfs_dmabufprocs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_each_object_track @ 002102f8 size=1
// signature: undefined get_each_object_track(void)
// callers: [md_dump_slabowner]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_each_object_track(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_get_each @ 00210300 size=1
// signature: undefined dma_buf_get_each(void)
// callers: [md_dma_buf_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_get_each(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ww_mutex_lock @ 00210308 size=1
// signature: undefined ww_mutex_lock(void)
// callers: [dump_bufinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ww_mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_resv_iter_first @ 00210310 size=1
// signature: undefined dma_resv_iter_first(void)
// callers: [dump_bufinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_resv_iter_first(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_fence_release @ 00210318 size=1
// signature: undefined dma_fence_release(void)
// callers: [dump_bufinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_fence_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_resv_iter_next @ 00210320 size=1
// signature: undefined dma_resv_iter_next(void)
// callers: [dump_bufinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_resv_iter_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_fence_signal @ 00210328 size=1
// signature: undefined dma_fence_signal(void)
// callers: [dump_bufinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_fence_signal(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 00210330 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [dump_bufinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ww_mutex_unlock @ 00210338 size=1
// signature: undefined ww_mutex_unlock(void)
// callers: [dump_bufinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ww_mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_lock @ 00210340 size=1
// signature: undefined __rcu_read_lock(void)
// callers: [md_dma_buf_procs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iterate_fd @ 00210348 size=1
// signature: undefined iterate_fd(void)
// callers: [md_dma_buf_procs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iterate_fd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_unlock @ 00210350 size=1
// signature: undefined __rcu_read_unlock(void)
// callers: [md_dma_buf_procs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_is_dma_buf_file @ 00210358 size=1
// signature: undefined qcom_is_dma_buf_file(void)
// callers: [get_dma_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_is_dma_buf_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 00210360 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [slab_owner_filter_read, page_owner_dump_size_read, dma_buf_info_size_read, page_owner_filter_read, page_owner_handle_read, page_owner_call_site_read, slab_owner_dump_size_read, slab_owner_handle_read, dma_buf_procs_size_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull_from_user @ 00210368 size=1
// signature: undefined kstrtoull_from_user(void)
// callers: [dma_buf_info_size_write, dma_buf_procs_size_write, page_owner_dump_size_write, slab_owner_dump_size_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00210370 size=1
// signature: undefined mutex_lock(void)
// callers: [page_owner_dump_size_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoul_from_user @ 00210378 size=1
// signature: undefined kstrtoul_from_user(void)
// callers: [page_owner_filter_write, slab_owner_handle_write, slab_owner_filter_write, page_owner_handle_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoul_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00210380 size=1
// signature: undefined __check_object_size(void)
// callers: [page_owner_call_site_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00210390 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [page_owner_call_site_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



