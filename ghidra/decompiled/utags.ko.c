// Decompiled by Ghidra 12.2
// Program: utags.ko
// Image base: 00100000

//------------------------------------------------------------
// load_work_func @ 0010099c size=1684
// signature: undefined load_work_func(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void load_work_func(long param_1)

{
  char *pcVar1;
  size_t sVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  char cVar6;
  code *pcVar7;
  int iVar8;
  ulong uVar9;
  char *pcVar10;
  size_t sVar11;
  undefined1 *puVar12;
  long lVar13;
  undefined *puVar14;
  undefined8 uVar15;
  long lVar16;
  char *pcVar17;
  ulong *puVar18;
  char *pcVar19;
  char *__s1;
  undefined8 *puVar20;
  char *pcVar21;
  char *pcVar22;
  char *__string;
  undefined6 local_d0;
  undefined2 uStack_ca;
  undefined6 local_c8;
  undefined2 uStack_c2;
  undefined8 uStack_c0;
  undefined8 local_b8;
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
  
  lVar13 = sp_el0;
  puVar18 = (ulong *)(param_1 + -0x108);
  local_68 = *(long *)(lVar13 + 0x638);
  puVar20 = (undefined8 *)(param_1 + -0x120);
  if (*puVar18 == 0) {
    uVar9 = blkdev_get_by_path(*puVar20,3,puVar20);
    if (uVar9 < 0xfffffffffffff001) {
      *puVar18 = uVar9;
      uVar15 = *(undefined8 *)(*(long *)(uVar9 + 0x30) + 0x50);
      *(undefined8 *)(param_1 + -0x118) = 0;
      *(undefined8 *)(param_1 + -0x110) = uVar15;
      goto LAB_00100a14;
    }
    _printk(&DAT_00104e52,"open_utags",*puVar20);
  }
  else {
LAB_00100a14:
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
    local_c8 = 0;
    uStack_c2 = 0;
    uStack_c0 = 0;
    local_d0 = 0;
    uStack_ca = 0;
    pcVar10 = (char *)vmalloc(0x2c);
    if (pcVar10 == (char *)0x0) {
LAB_00100e74:
      pcVar10 = (char *)0x0;
LAB_00100e78:
      _printk(&DAT_001052d7,"load_utags",*(undefined8 *)(param_1 + -0xa0),pcVar10);
      if ((*(int *)(param_1 + -0x94) == 0) || (iVar8 = init_empty(puVar20), iVar8 != 0))
      goto LAB_00100eec;
      pcVar10 = (char *)0x58;
    }
    else {
      iVar8 = rw_bdev(*puVar18,pcVar10,0x2c,0);
      if (iVar8 < 0x2c) {
        _printk(&DAT_00104942,"read_head",*puVar20);
LAB_00100e6c:
        vfree(pcVar10);
        goto LAB_00100e74;
      }
      sVar11 = strnlen(pcVar10,0x20);
      if (0x20 < sVar11) {
LAB_00101014:
        fortify_panic("strnlen");
LAB_00101020:
        fortify_panic("__fortify_strlen");
        goto LAB_0010102c;
      }
      if (sVar11 == 0x20) goto LAB_00101020;
      sVar2 = 0x1e;
      if (sVar11 != 0x1f) {
        sVar2 = sVar11;
      }
      memcpy(&local_d0,pcVar10,sVar2);
      if (0x67 < sVar2) {
LAB_00101010:
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(1,0x101014);
        (*pcVar7)();
      }
      *(undefined1 *)((long)&local_d0 + sVar2) = 0;
      if (CONCAT26(uStack_ca,local_d0) != 0x485f474154555f5f ||
          CONCAT62(local_c8,uStack_ca) != 0x5f5f444145485f) {
        _printk(&DAT_00104c5b,"read_head",*puVar20);
        goto LAB_00100e6c;
      }
      uVar3 = *(uint *)(pcVar10 + 0x24);
      uVar4 = *(uint *)(pcVar10 + 0x28);
      vfree(pcVar10);
      *(uint *)(param_1 + -0x98) = uVar3 >> 0x18 & 1;
      if (*(int *)(param_1 + -0x94) == 0) {
        pcVar10 = *(char **)(param_1 + -0x110);
      }
      else {
        pcVar10 = *(char **)(param_1 + -0x110);
        uVar3 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
        pcVar17 = (char *)(ulong)(uVar3 >> 0x10 | uVar3 << 0x10);
        if ((pcVar17 <= pcVar10 && uVar4 != 0) && *(long *)(param_1 + -200) != 0) {
          pcVar10 = pcVar17;
        }
      }
      *(char **)(param_1 + -200) = pcVar10;
      if (pcVar10 < (char *)0x58) goto LAB_00100e78;
    }
    pcVar17 = (char *)vmalloc(pcVar10);
    if (pcVar17 != (char *)0x0) {
      iVar8 = rw_bdev(*puVar18,pcVar17,pcVar10,0);
      if (pcVar10 == (char *)(long)iVar8) {
        pcVar21 = (char *)0x0;
        pcVar22 = (char *)0x0;
        __s1 = (char *)0x0;
        pcVar19 = (char *)0x0;
        __string = pcVar17;
        do {
          if ((pcVar19 == (char *)0x0) &&
             (__s1 = (char *)kmalloc_trace(_complete,0xdc0,0x68), __s1 == (char *)0x0))
          goto LAB_00100f88;
          if (((long)pcVar21 < 0) ||
             (((pcVar10 <= pcVar21 || ((long)pcVar22 < 0)) || (pcVar10 <= pcVar22))))
          goto LAB_00101010;
          sVar11 = strnlen(__string,0x20);
          if (0x20 < sVar11) goto LAB_00101014;
          if (sVar11 == 0x20) goto LAB_00101020;
          sVar2 = 0x1e;
          if (sVar11 != 0x1f) {
            sVar2 = sVar11;
          }
          memcpy(__s1,__string,sVar2);
          __s1[sVar2] = '\0';
          if (((long)pcVar22 < 0) || (pcVar10 <= pcVar22)) goto LAB_00101010;
          sVar11 = strnlen(__string,0x20);
          if (0x20 < sVar11) goto LAB_00101014;
          if (sVar11 == 0x20) goto LAB_00101020;
          pcVar1 = __s1 + 0x20;
          sVar2 = 0x1e;
          if (sVar11 != 0x1f) {
            sVar2 = sVar11;
          }
          memcpy(pcVar1,__string,sVar2);
          pcVar1[sVar2] = '\0';
          puVar12 = (undefined1 *)strnchr(pcVar1,0x20,0x3a);
          if (puVar12 != (undefined1 *)0x0) {
            *puVar12 = 0;
          }
          pcVar1 = pcVar21 + 0x24;
          if ((((long)pcVar1 < 0) || (pcVar10 < pcVar1)) ||
             ((ulong)((long)pcVar10 - (long)pcVar1) < 4)) goto LAB_00101010;
          pcVar1 = pcVar22 + 0x24;
          if ((((long)pcVar1 < 0) || (pcVar10 < pcVar1)) ||
             ((ulong)((long)pcVar10 - (long)pcVar1) < 4)) goto LAB_00101010;
          pcVar1 = pcVar21 + 0x28;
          uVar3 = (*(uint *)(__string + 0x24) & 0xff00ff00) >> 8 |
                  (*(uint *)(__string + 0x24) & 0xff00ff) << 8;
          *(uint *)(__s1 + 0x44) = uVar3 >> 0x10 | uVar3 << 0x10;
          if ((((long)pcVar1 < 0) || (pcVar10 < pcVar1)) ||
             ((ulong)((long)pcVar10 - (long)pcVar1) < 4)) goto LAB_00101010;
          pcVar1 = pcVar22 + 0x28;
          if ((((long)pcVar1 < 0) || (pcVar10 < pcVar1)) ||
             ((ulong)((long)pcVar10 - (long)pcVar1) < 4)) goto LAB_00101010;
          uVar3 = (*(uint *)(__string + 0x28) & 0xff00ff00) >> 8 |
                  (*(uint *)(__string + 0x28) & 0xff00ff) << 8;
          *(uint *)(__s1 + 0x48) = uVar3 >> 0x10 | uVar3 << 0x10;
          if ((pcVar10 < pcVar21 + 0x20) || ((ulong)((long)pcVar10 - (long)(pcVar21 + 0x20)) < 4))
          goto LAB_00101010;
          pcVar1 = pcVar22 + 0x20;
          if (((long)pcVar1 < 0) ||
             ((pcVar10 < pcVar1 || ((ulong)((long)pcVar10 - (long)pcVar1) < 4)))) goto LAB_00101010;
          uVar3 = *(uint *)(__string + 0x20);
          uVar4 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
          uVar4 = uVar4 >> 0x10 | uVar4 << 0x10;
          *(uint *)(__s1 + 0x40) = uVar4;
          if (pcVar19 == (char *)0x0) {
            iVar8 = strcmp(__s1,"__UTAG_HEAD__");
            pcVar19 = __s1;
            if (iVar8 == 0) goto LAB_00100d6c;
            puVar14 = &DAT_00104a8e;
LAB_00100f74:
            _printk(puVar14,"thaw_tags");
            pcVar19 = __s1;
            break;
          }
LAB_00100d6c:
          iVar8 = strcmp(__s1,"__UTAG_TAIL__");
          if (iVar8 == 0) {
            if (uVar3 != 0) {
              puVar14 = &DAT_00104d79;
              __s1 = pcVar19;
              goto LAB_00100f74;
            }
            if (pcVar19 == (char *)0x0) goto LAB_00100f88;
            if (*(int *)(param_1 + -0x94) == 0) goto LAB_00100fc4;
            lVar13 = *(long *)(pcVar19 + 0x58);
            goto LAB_00100dfc;
          }
          pcVar1 = __string + 0x2c;
          uVar9 = (ulong)(uVar4 + 3 & 0xfffffffc);
          __string = pcVar1 + uVar9;
          if (pcVar10 < __string + (0x2c - (long)pcVar17)) {
            puVar14 = &DAT_001053b1;
            __s1 = pcVar19;
            goto LAB_00100f74;
          }
          if (uVar3 != 0) {
            lVar13 = __kmalloc(uVar4 + 1,0xdc0);
            *(long *)(__s1 + 0x50) = lVar13;
            if (lVar13 == 0) break;
            memcpy(*(void **)(__s1 + 0x50),pcVar1,(ulong)*(uint *)(__s1 + 0x40));
          }
          pcVar21 = pcVar21 + uVar9 + 0x2c;
          pcVar22 = pcVar22 + uVar9 + 0x2c;
          lVar13 = kmalloc_trace(_complete,0xdc0,0x68);
          *(long *)(__s1 + 0x58) = lVar13;
          *(char **)(lVar13 + 0x60) = __s1;
          __s1 = *(char **)(__s1 + 0x58);
        } while (__s1 != (char *)0x0);
        while (pcVar19 != (char *)0x0) {
          pcVar10 = *(char **)(pcVar19 + 0x58);
          kfree(*(undefined8 *)(pcVar19 + 0x50));
          kfree(pcVar19);
          pcVar19 = pcVar10;
        }
LAB_00100f88:
        if (*(int *)(param_1 + -0x94) != 0) {
          init_empty(puVar20);
          pcVar19 = (char *)0x0;
          if (*(int *)(param_1 + -0x94) != 0) {
            lVar16 = 0;
            *(undefined8 *)(param_1 + -0x60) = 0;
            goto LAB_00100fb4;
          }
          goto LAB_00100fc4;
        }
      }
      else {
        _printk(&DAT_00104d36,"load_utags",*puVar20);
      }
      pcVar19 = (char *)0x0;
      goto LAB_00100fc4;
    }
  }
LAB_00100eec:
  pcVar19 = (char *)0x0;
  goto LAB_00100fcc;
  while( true ) {
    if (*(long *)(lVar16 + 0x58) == 0) {
      lVar16 = 0;
      break;
    }
    lVar13 = 0;
    do {
      cVar5 = ".attributes"[lVar13];
      cVar6 = *(char *)(lVar16 + lVar13);
      lVar13 = lVar13 + 1;
    } while ((cVar5 == cVar6 && cVar5 != '\0') && cVar6 != '\0');
    lVar13 = *(long *)(lVar16 + 0x58);
    if (cVar5 == cVar6) break;
LAB_00100dfc:
    lVar16 = lVar13;
    if (lVar16 == 0) break;
  }
  *(long *)(param_1 + -0x60) = lVar16;
  lVar13 = *(long *)(pcVar19 + 0x58);
  do {
    lVar16 = lVar13;
    if (lVar16 == 0) break;
    if (*(long *)(lVar16 + 0x58) == 0) {
      lVar16 = 0;
      break;
    }
    lVar13 = 0;
    do {
      cVar5 = ".features"[lVar13];
      cVar6 = *(char *)(lVar16 + lVar13);
      lVar13 = lVar13 + 1;
    } while ((cVar5 == cVar6 && cVar5 != '\0') && cVar6 != '\0');
    lVar13 = *(long *)(lVar16 + 0x58);
  } while (cVar5 != cVar6);
LAB_00100fb4:
  *(long *)(param_1 + -0x58) = lVar16;
LAB_00100fc4:
  vfree(pcVar17);
LAB_00100fcc:
  *(char **)(param_1 + 0x60) = pcVar19;
  complete(param_1 + -0x50);
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) == local_68) {
    return;
  }
LAB_0010102c:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// store_work_func @ 00101034 size=1128
// signature: undefined store_work_func(void)
// callers: []
//------------------------------------------------------------

void store_work_func(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined *puVar8;
  uint uVar9;
  long *plVar10;
  ulong uVar11;
  undefined8 uVar12;
  char *__s1;
  ulong uVar13;
  ulong uVar14;
  long lVar15;
  char *__s1_00;
  undefined4 uVar16;
  long lVar17;
  undefined8 *__dest;
  long lVar18;
  
  __s1_00 = *(char **)(param_1 + 0x30);
  if (__s1_00 != (char *)0x0) {
    uVar14 = *(ulong *)(param_1 + -0x140);
    iVar6 = strncmp(__s1_00,"__UTAG_HEAD__",0x20);
    if (iVar6 == 0) {
      lVar17 = 0;
      plVar10 = (long *)(param_1 + -0x150);
      __s1 = __s1_00;
      do {
        lVar18 = lVar17 + (ulong)(*(int *)(__s1 + 0x40) + 3U & 0xfffffffc);
        lVar17 = lVar18 + 0x2c;
        iVar6 = strncmp(__s1,"__UTAG_TAIL__",0x20);
        if (iVar6 == 0) {
          if (*(long *)(__s1 + 0x58) == 0) {
            uVar13 = lVar18 + 0x22bU & 0xfffffffffffffe00;
            if (uVar14 < uVar13) {
              _printk(&DAT_00104f55,"freeze_tags",uVar13);
              goto LAB_001013bc;
            }
            puVar7 = (undefined8 *)vmalloc(uVar13);
            if (puVar7 == (undefined8 *)0x0) goto LAB_001013bc;
            lVar18 = 0;
            lVar15 = 0;
            lVar17 = 0;
            *(int *)(__s1_00 + 0x48) = (int)uVar13;
            __dest = puVar7;
            goto LAB_00101118;
          }
          break;
        }
        __s1 = *(char **)(__s1 + 0x58);
      } while (__s1 != (char *)0x0);
      puVar8 = &DAT_00105352;
      goto LAB_001013b0;
    }
  }
  puVar8 = &DAT_00104e1f;
LAB_001013b0:
  _printk(puVar8,"freeze_tags");
LAB_001013bc:
  uVar16 = 0xfffffffb;
LAB_001013c0:
  _printk(&DAT_0010548d,"store_work_func");
LAB_001013d4:
  *(undefined4 *)(param_1 + 0x38) = uVar16;
  complete(param_1 + -0x60);
  return;
LAB_00101118:
  uVar2 = *(undefined8 *)(__s1_00 + 0x18);
  uVar14 = lVar17 + 0x20;
  uVar12 = *(undefined8 *)__s1_00;
  uVar3 = *(undefined8 *)(__s1_00 + 8);
  uVar9 = *(uint *)(__s1_00 + 0x40);
  uVar1 = *(uint *)(__s1_00 + 0x44);
  uVar4 = *(uint *)(__s1_00 + 0x48);
  __dest[2] = *(undefined8 *)(__s1_00 + 0x10);
  __dest[3] = uVar2;
  *__dest = uVar12;
  __dest[1] = uVar3;
  if ((((long)uVar14 < 0) || (uVar13 < uVar14)) || (uVar13 - uVar14 < 4)) {
LAB_00101498:
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(1,0x10149c);
    (*pcVar5)();
  }
  uVar14 = lVar18 + 0x20;
  if ((((long)uVar14 < 0) || (uVar13 < uVar14)) || (uVar13 - uVar14 < 4)) goto LAB_00101498;
  uVar14 = lVar15 + 0x20;
  if ((((long)uVar14 < 0) || (uVar13 < uVar14)) || (uVar13 - uVar14 < 4)) goto LAB_00101498;
  uVar14 = lVar17 + 0x24;
  uVar9 = (uVar9 & 0xff00ff00) >> 8 | (uVar9 & 0xff00ff) << 8;
  *(uint *)(__dest + 4) = uVar9 >> 0x10 | uVar9 << 0x10;
  if ((((long)uVar14 < 0) || (uVar13 < uVar14)) || (uVar13 - uVar14 < 4)) goto LAB_00101498;
  uVar14 = lVar18 + 0x24;
  if ((((long)uVar14 < 0) || (uVar13 < uVar14)) || (uVar13 - uVar14 < 4)) goto LAB_00101498;
  uVar14 = lVar15 + 0x24;
  if ((((long)uVar14 < 0) || (uVar13 < uVar14)) || (uVar13 - uVar14 < 4)) goto LAB_00101498;
  uVar14 = lVar17 + 0x28;
  uVar9 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
  *(uint *)((long)__dest + 0x24) = uVar9 >> 0x10 | uVar9 << 0x10;
  if ((((long)uVar14 < 0) || (uVar13 < uVar14)) || (uVar13 - uVar14 < 4)) goto LAB_00101498;
  uVar14 = lVar18 + 0x28;
  if ((((long)uVar14 < 0) || (uVar13 < uVar14)) || (uVar13 - uVar14 < 4)) goto LAB_00101498;
  uVar14 = lVar15 + 0x28;
  if ((((long)uVar14 < 0) || (uVar13 < uVar14)) || (uVar13 - uVar14 < 4)) goto LAB_00101498;
  uVar9 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
  lVar17 = lVar17 + 0x2c;
  lVar18 = lVar18 + 0x2c;
  lVar15 = lVar15 + 0x2c;
  *(uint *)(__dest + 5) = uVar9 >> 0x10 | uVar9 << 0x10;
  __dest = (undefined8 *)((long)__dest + 0x2c);
  if (*(uint *)(__s1_00 + 0x40) == 0) {
    uVar9 = 0;
  }
  else {
    memcpy(__dest,*(void **)(__s1_00 + 0x50),(ulong)*(uint *)(__s1_00 + 0x40));
    uVar9 = *(uint *)(__s1_00 + 0x40);
    uVar14 = (ulong)uVar9;
    lVar17 = lVar17 + uVar14;
    lVar18 = lVar18 + uVar14;
    lVar15 = lVar15 + uVar14;
    __dest = (undefined8 *)((long)__dest + uVar14);
  }
  uVar9 = (uVar9 + 3 & 0xfffffffc) - uVar9;
  uVar14 = (ulong)uVar9;
  if (uVar9 != 0) {
    memset(__dest,0,uVar14);
    lVar17 = lVar17 + uVar14;
    lVar18 = lVar18 + uVar14;
    lVar15 = lVar15 + uVar14;
    __dest = (undefined8 *)((long)__dest + uVar14);
  }
  iVar6 = strncmp(__s1_00,"__UTAG_TAIL__",0x20);
  if (iVar6 == 0) {
    memset(__dest,0,(long)puVar7 + (uVar13 - (long)__dest));
    uVar14 = *(ulong *)(param_1 + -0x138);
    if (uVar14 != 0) {
LAB_00101300:
      uVar14 = rw_bdev(uVar14,puVar7,uVar13,0x801);
      if (uVar14 < uVar13) {
        _printk(&DAT_001050e6,"store_utags",*plVar10,uVar14);
        uVar16 = 0xfffffffb;
      }
      else {
        uVar16 = 0;
      }
      plVar10 = (long *)(param_1 + -0x130);
      if (*plVar10 != 0) {
        uVar11 = *(ulong *)(param_1 + -0x118);
        if (uVar11 == 0) {
          uVar11 = blkdev_get_by_path(*plVar10,3,plVar10);
          if (0xfffffffffffff000 < uVar11) {
            lVar17 = *plVar10;
            goto LAB_00101478;
          }
          *(ulong *)(param_1 + -0x118) = uVar11;
          uVar12 = *(undefined8 *)(*(long *)(uVar11 + 0x30) + 0x50);
          *(undefined8 *)(param_1 + -0x128) = 0;
          *(undefined8 *)(param_1 + -0x120) = uVar12;
        }
        uVar11 = rw_bdev(uVar11,puVar7,uVar13,0x801);
        if (uVar11 < uVar13) {
          _printk(&DAT_001050e6,"store_utags",*plVar10,uVar11);
          goto LAB_0010148c;
        }
      }
      vfree(puVar7);
      if (uVar14 < uVar13) goto LAB_001013c0;
      uVar16 = 0;
      goto LAB_001013d4;
    }
    uVar14 = blkdev_get_by_path(*plVar10,3);
    if (uVar14 < 0xfffffffffffff001) {
      *(ulong *)(param_1 + -0x138) = uVar14;
      uVar11 = *(ulong *)(*(long *)(uVar14 + 0x30) + 0x50);
      *(undefined8 *)(param_1 + -0x148) = 0;
      *(ulong *)(param_1 + -0x140) = uVar11;
      goto LAB_00101300;
    }
    lVar17 = *plVar10;
LAB_00101478:
    _printk(&DAT_00104e52,"open_utags",lVar17);
LAB_0010148c:
    vfree(puVar7);
    goto LAB_001013bc;
  }
  __s1_00 = *(char **)(__s1_00 + 0x58);
  goto LAB_00101118;
}



//------------------------------------------------------------
// init_empty @ 0010149c size=180
// signature: undefined init_empty(void)
// callers: [load_work_func]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 init_empty(long param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  _printk(&DAT_00104d5d,"init_empty",*(undefined8 *)(param_1 + 0x80));
  puVar2 = (undefined8 *)kmalloc_trace(_complete,0xdc0,0x68);
  if (puVar2 == (undefined8 *)0x0) {
    uVar3 = 0xfffffff4;
  }
  else {
    uVar3 = CONCAT35(s___UTAG_HEAD___00104f3d._5_3_,s___UTAG_HEAD___00104f3d._0_5_);
    *(undefined1 *)((long)puVar2 + 0xd) = 0;
    uVar1 = CONCAT53(s___UTAG_HEAD___00104f3d._8_5_,s___UTAG_HEAD___00104f3d._5_3_);
    *puVar2 = uVar3;
    *(undefined8 *)((long)puVar2 + 5) = uVar1;
    add_utag_tail(puVar2,"__UTAG_TAIL__",0);
    *(undefined8 **)(param_1 + 0x180) = puVar2;
    queue_work_on(0x20,*(undefined8 *)(param_1 + 0x118),param_1 + 0x150);
    wait_for_completion(param_1 + 0xf0);
    kfree(puVar2);
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// add_utag_tail @ 00101550 size=352
// signature: undefined add_utag_tail(void)
// callers: [new_utag, init_empty]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long add_utag_tail(long param_1,undefined8 param_2,undefined *param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  void *__dest;
  size_t __n;
  long lVar6;
  ulong uVar7;
  long lVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  undefined1 auVar16 [16];
  char local_58 [32];
  long local_38;
  
  lVar12 = sp_el0;
  local_38 = *(long *)(lVar12 + 0x638);
  puVar1 = &DAT_00104cf9;
  if (param_3 != (undefined *)0x0) {
    puVar1 = &DAT_0010506d;
  }
  puVar2 = &DAT_00104cf9;
  if (param_3 != (undefined *)0x0) {
    puVar2 = param_3;
  }
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
  scnprintf(local_58,0x20,"%s%s%s",param_2,puVar1,puVar2);
  while( true ) {
    uVar9 = (undefined4)param_2;
    lVar12 = *(long *)(param_1 + 0x58);
    if (lVar12 == 0) break;
    iVar4 = strncmp((char *)(param_1 + 0x20),local_58,0x20);
    param_1 = lVar12;
    if (iVar4 == 0) {
      lVar12 = 0xffffffef;
LAB_00101668:
      lVar6 = sp_el0;
      if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail(lVar12);
      }
      return lVar12;
    }
  }
  lVar12 = 0x68;
  __dest = (void *)kmalloc_trace(_complete,0xdc0);
  if (__dest == (void *)0x0) {
    lVar12 = 0xfffffff4;
    goto LAB_00101668;
  }
  __n = strnlen(local_58,0x20);
  if (__n < 0x21) {
    if (__n != 0x20) {
      memcpy(__dest,local_58,__n);
      *(undefined1 *)((long)__dest + __n) = 0;
      *(undefined4 *)((long)__dest + 0x48) = 0;
      *(undefined8 *)((long)__dest + 0x40) = 0;
      lVar12 = *(long *)(param_1 + 0x60);
      if (lVar12 == 0) {
        lVar12 = 0;
        *(void **)(param_1 + 0x58) = __dest;
        *(long *)((long)__dest + 0x60) = param_1;
      }
      else {
        *(long *)((long)__dest + 0x58) = param_1;
        *(long *)((long)__dest + 0x60) = lVar12;
        lVar12 = 0;
        *(void **)(*(long *)(param_1 + 0x60) + 0x58) = __dest;
        *(void **)(param_1 + 0x60) = __dest;
      }
      goto LAB_00101668;
    }
  }
  else {
    fortify_panic("strnlen");
  }
  auVar16 = fortify_panic("__fortify_strlen");
  uVar14 = lVar12 + 0xfffU >> 0xc;
  iVar4 = (int)uVar14;
  if (iVar4 < 1) {
    return lVar12;
  }
  uVar14 = uVar14 & 0xffffffff;
  do {
    uVar11 = (uint)uVar14;
    uVar10 = uVar11;
    if (0xff < uVar11) {
      uVar10 = 0x100;
    }
    uVar14 = (ulong)uVar10;
    lVar6 = bio_alloc_bioset(auVar16._0_8_,uVar14,0,0xcc0,&fs_bio_set);
    if (lVar6 == 0) {
      iVar5 = -0xc;
      goto LAB_00101804;
    }
    uVar3 = iVar4 - uVar11;
    uVar13 = (ulong)uVar3;
    *(ulong *)(lVar6 + 0x20) = -(ulong)(uVar3 >> 0x1f) & 0xfffffff800000000 | uVar13 << 3;
    *(undefined4 *)(lVar6 + 0x10) = uVar9;
    uVar15 = uVar14;
    do {
      lVar8 = auVar16._8_8_ + (long)(int)uVar13 * 0x1000;
      uVar7 = is_vmalloc_addr(lVar8);
      if ((uVar7 & 1) == 0) {
        lVar8 = ((lVar8 * 0x100 >> 8) + 0x8000000000U >> 0xc) * 0x40 + -0x200000000;
      }
      else {
        lVar8 = vmalloc_to_page(lVar8);
      }
      iVar5 = bio_add_page(lVar6,lVar8,0x1000,0);
      if (iVar5 == 0) {
        bio_put(lVar6);
        iVar5 = -5;
        goto LAB_00101804;
      }
      uVar15 = uVar15 - 1;
      uVar13 = (ulong)((int)uVar13 + 1);
    } while (uVar15 != 0);
    iVar5 = submit_bio_wait(lVar6);
    if (iVar5 != 0) {
      _printk(&DAT_00104c90,"utags_submit_bio",uVar14,uVar9,iVar5);
    }
    bio_put(lVar6);
    uVar14 = (ulong)(uVar11 - uVar10);
  } while (0 < (int)(uVar11 - uVar10));
  if (iVar5 < 0) {
LAB_00101804:
    lVar12 = (long)iVar5;
  }
  return lVar12;
}



//------------------------------------------------------------
// rw_bdev @ 001016b0 size=404
// signature: undefined rw_bdev(void)
// callers: [load_work_func, store_work_func]
//------------------------------------------------------------

long rw_bdev(undefined8 param_1,long param_2,long param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  int iVar9;
  ulong uVar10;
  ulong uVar11;
  
  uVar10 = param_3 + 0xfffU >> 0xc;
  iVar9 = (int)uVar10;
  if (0 < iVar9) {
    uVar10 = uVar10 & 0xffffffff;
    do {
      uVar7 = (uint)uVar10;
      uVar6 = uVar7;
      if (0xff < uVar7) {
        uVar6 = 0x100;
      }
      uVar10 = (ulong)uVar6;
      lVar3 = bio_alloc_bioset(param_1,uVar10,0,0xcc0,&fs_bio_set);
      if (lVar3 == 0) {
        iVar2 = -0xc;
        goto LAB_00101804;
      }
      uVar1 = iVar9 - uVar7;
      uVar8 = (ulong)uVar1;
      *(ulong *)(lVar3 + 0x20) = -(ulong)(uVar1 >> 0x1f) & 0xfffffff800000000 | uVar8 << 3;
      *(undefined4 *)(lVar3 + 0x10) = param_4;
      uVar11 = uVar10;
      do {
        lVar5 = param_2 + (long)(int)uVar8 * 0x1000;
        uVar4 = is_vmalloc_addr(lVar5);
        if ((uVar4 & 1) == 0) {
          lVar5 = ((lVar5 * 0x100 >> 8) + 0x8000000000U >> 0xc) * 0x40 + -0x200000000;
        }
        else {
          lVar5 = vmalloc_to_page(lVar5);
        }
        iVar2 = bio_add_page(lVar3,lVar5,0x1000,0);
        if (iVar2 == 0) {
          bio_put(lVar3);
          iVar2 = -5;
          goto LAB_00101804;
        }
        uVar11 = uVar11 - 1;
        uVar8 = (ulong)((int)uVar8 + 1);
      } while (uVar11 != 0);
      iVar2 = submit_bio_wait(lVar3);
      if (iVar2 != 0) {
        _printk(&DAT_00104c90,"utags_submit_bio",uVar10,param_4,iVar2);
      }
      bio_put(lVar3);
      uVar10 = (ulong)(uVar7 - uVar6);
    } while (0 < (int)(uVar7 - uVar6));
    if (iVar2 < 0) {
LAB_00101804:
      param_3 = (long)iVar2;
    }
  }
  return param_3;
}



//------------------------------------------------------------
// utags_probe @ 00101848 size=916
// signature: undefined utags_probe(void)
// callers: []
//------------------------------------------------------------

void utags_probe(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  undefined *puVar5;
  char *pcVar6;
  undefined8 *puVar7;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  lVar2 = devm_kmalloc(param_1 + 0x10,400,0xdc0);
  if (lVar2 != 0) {
    *(long *)(lVar2 + 0x60) = lVar2 + 0x60;
    *(long *)(lVar2 + 0x68) = lVar2 + 0x60;
    *(long *)(lVar2 + 0x70) = lVar2 + 0x70;
    *(long *)(lVar2 + 0x78) = lVar2 + 0x70;
    *(long *)(lVar2 + 0x40) = param_1;
    *(undefined1 *)(lVar2 + 0x50) = 0x32;
    __mutex_init(lVar2 + 0x90,"&ctrl->access_lock",&utags_probe___key);
    *(undefined4 *)(lVar2 + 0xd0) = 0;
    __init_swait_queue_head(lVar2 + 0xd8,"&x->wait",&init_completion___key);
    *(undefined4 *)(lVar2 + 0xf0) = 0;
    __init_swait_queue_head(lVar2 + 0xf8,"&x->wait",&init_completion___key);
    *(undefined8 *)(lVar2 + 0x120) = 0xfffffffe0;
    *(long *)(lVar2 + 0x128) = lVar2 + 0x128;
    *(long *)(lVar2 + 0x130) = lVar2 + 0x128;
    *(code **)(lVar2 + 0x138) = load_work_func;
    *(undefined8 *)(lVar2 + 0x150) = 0xfffffffe0;
    *(long *)(lVar2 + 0x158) = lVar2 + 0x158;
    *(long *)(lVar2 + 0x160) = lVar2 + 0x158;
    uVar3 = *(undefined8 *)(param_1 + 0x2f8);
    *(long *)(param_1 + 0xa8) = lVar2;
    *(code **)(lVar2 + 0x168) = store_work_func;
    local_50 = 0;
    iVar1 = of_property_read_string(uVar3,"mmi,main-utags",&local_50);
    if (iVar1 != 0) {
      puVar5 = &DAT_001053de;
      pcVar6 = "utags_dt_init";
LAB_001019d4:
      _printk(puVar5,pcVar6);
      uVar3 = 0xfffffffb;
      goto LAB_0010188c;
    }
    utags_bootdevice_expand(lVar2,local_50);
    iVar1 = of_property_read_string(uVar3,"mmi,backup-utags",&local_50);
    if (iVar1 == 0) {
      utags_bootdevice_expand(lVar2 + 0x20,local_50);
    }
    else {
      _printk(&DAT_00104cfa,"utags_dt_init");
    }
    puVar7 = (undefined8 *)(lVar2 + 0x80);
    *puVar7 = "config";
    of_property_read_string(uVar3,"mmi,dir-name",puVar7);
    scnprintf(&local_48,0x10,"%s_load",*puVar7);
    lVar4 = alloc_workqueue(&DAT_00104bfb,0x40008,1,&local_48);
    *(long *)(lVar2 + 0x110) = lVar4;
    if (lVar4 != 0) {
      scnprintf(&local_48,0x10,"%s_store",*(undefined8 *)(lVar2 + 0x80));
      lVar4 = alloc_workqueue(&DAT_00104bfb,0x40008,1,&local_48);
      *(long *)(lVar2 + 0x118) = lVar4;
      if (lVar4 != 0) {
        lVar4 = proc_mkdir_data(*(undefined8 *)(lVar2 + 0x80),0x1f9,0,0);
        *(long *)(lVar2 + 0x48) = lVar4;
        if (lVar4 != 0) {
          iVar1 = strncmp((char *)*puVar7,"hw",3);
          if (iVar1 == 0) {
            *(undefined4 *)(lVar2 + 0x8c) = 1;
          }
          lVar4 = proc_create_data("reload",0x1b0,lVar4,&reload_fops,lVar2);
          if (lVar4 == 0) {
            _printk(&DAT_001048d2,"utags_probe");
            destroy_workqueue(*(undefined8 *)(lVar2 + 0x110));
            destroy_workqueue(*(undefined8 *)(lVar2 + 0x118));
            remove_proc_subtree(*(undefined8 *)(lVar2 + 0x80),0);
            uVar3 = 0xfffffffb;
          }
          else {
            iVar1 = proc_utag_util(lVar2);
            if (iVar1 == 0) {
              _printk(&DAT_00104e7e,"utags_probe",*puVar7);
              uVar3 = 0;
            }
            else {
              _printk(&DAT_0010499c,"utags_probe");
              destroy_workqueue(*(undefined8 *)(lVar2 + 0x110));
              destroy_workqueue(*(undefined8 *)(lVar2 + 0x118));
              remove_proc_subtree(*(undefined8 *)(lVar2 + 0x80),0);
              uVar3 = 0xfffffff2;
            }
          }
          goto LAB_0010188c;
        }
        destroy_workqueue(*(undefined8 *)(lVar2 + 0x110));
        destroy_workqueue(*(undefined8 *)(lVar2 + 0x118));
        puVar5 = &DAT_00104972;
        pcVar6 = "utags_probe";
        goto LAB_001019d4;
      }
      destroy_workqueue(*(undefined8 *)(lVar2 + 0x110));
    }
    _printk(&DAT_00105146,"utags_probe",&local_48);
  }
  uVar3 = 0xfffffff4;
LAB_0010188c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// utags_remove @ 00101be0 size=228
// signature: undefined utags_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 utags_remove(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0xa8);
  clear_utags_directory(plVar1);
  remove_proc_subtree(plVar1[0x10],0);
  destroy_workqueue(plVar1[0x22]);
  destroy_workqueue(plVar1[0x23]);
  if (plVar1[1] != 0) {
    filp_close(plVar1[1],0);
    plVar1[1] = 0;
  }
  if (plVar1[5] != 0) {
    filp_close(plVar1[5],0);
    plVar1[5] = 0;
  }
  if (plVar1[3] != 0) {
    blkdev_put(plVar1[3],3);
    plVar1[3] = 0;
  }
  if (plVar1[7] != 0) {
    blkdev_put(plVar1[7],3);
    plVar1[7] = 0;
  }
  if (*plVar1 != 0) {
    kfree();
  }
  if (plVar1[4] != 0) {
    kfree();
  }
  if (bootargs_str != 0) {
    kfree();
    bootargs_str = 0;
  }
  devm_kfree(param_1 + 0x10,plVar1);
  *(undefined8 *)(param_1 + 0xa8) = 0;
  return 0;
}



//------------------------------------------------------------
// proc_utag_util @ 00101cc4 size=244
// signature: undefined proc_utag_util(void)
// callers: [utags_probe]
//------------------------------------------------------------

undefined8 proc_utag_util(long param_1)

{
  long lVar1;
  long lVar2;
  undefined *puVar3;
  
  lVar1 = proc_mkdir_data(&DAT_00105299,0x1f9,*(undefined8 *)(param_1 + 0x48),0);
  if (lVar1 == 0) {
    puVar3 = &DAT_00104ed4;
  }
  else {
    lVar2 = proc_create_data(&DAT_00105035,0x90,lVar1,new_fops,param_1);
    if (lVar2 == 0) {
      puVar3 = &DAT_00104b12;
    }
    else {
      lVar2 = proc_create_data(&DAT_001053ac,0x1b0,lVar1,lock_fops,param_1);
      if (lVar2 == 0) {
        puVar3 = &DAT_00104917;
      }
      else {
        lVar1 = proc_create_data(".delete",0x90,lVar1,delete_fops,param_1);
        if (lVar1 != 0) {
          return 0;
        }
        puVar3 = &DAT_00104a23;
      }
    }
  }
  _printk(puVar3,"proc_utag_util");
  return 0xfffffffb;
}



//------------------------------------------------------------
// utags_bootdevice_expand @ 00101db8 size=480
// signature: undefined utags_bootdevice_expand(void)
// callers: [utags_probe]
//------------------------------------------------------------

void utags_bootdevice_expand(undefined8 *param_1,char *param_2)

{
  bool bVar1;
  int iVar2;
  size_t sVar3;
  long lVar4;
  char *pcVar5;
  char *param0;
  size_t sVar6;
  char *pcVar7;
  undefined1 auVar8 [16];
  char *pcStack_b0;
  char *pcStack_a8;
  char *pcStack_a0;
  long lStack_98;
  long lStack_90;
  code *pcStack_88;
  char *pcStack_80;
  size_t sStack_70;
  char *pcStack_68;
  char *pcStack_60;
  undefined8 *puStack_58;
  char *local_50;
  undefined8 local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  sVar3 = strlen(param_2);
  local_50 = (char *)0x0;
  if (param_2 == (char *)0x0) goto LAB_00101ed8;
  if ((utags_get_bootdevice_from_bootconfig_bootdevice_init & 1) == 0) {
    pcVar5 = "\n";
    iVar2 = utag_get_bootarg(&local_50,"mmi,bootconfig");
    pcVar7 = local_50;
    if ((iVar2 == 0) && (local_50 != (char *)0x0)) {
      sVar6 = strlen(local_50);
      if (0x100 < sVar6) {
        auVar8 = fortify_panic("strncpy");
        pcStack_88 = utag_get_bootarg;
        pcStack_80 = "(%s): range payload for [%s] is not null terminated\n";
        pcStack_68 = pcVar7;
        lVar4 = sp_el0;
        lStack_98 = *(long *)(lVar4 + 0x638);
        pcStack_a0 = (char *)0x0;
        lStack_90 = (long)register0x00000008 + -0x40;
        sStack_70 = sVar3;
        pcStack_60 = param_2;
        puStack_58 = param_1;
        lVar4 = of_find_node_opts_by_path("/chosen",0);
        if ((lVar4 != 0) &&
           (iVar2 = of_property_read_string(lVar4,auVar8._8_8_,&pcStack_a0), pcVar7 = pcStack_a0,
           iVar2 == 0)) {
          sVar3 = strlen(pcStack_a0);
          if (bootargs_str == (char *)0x0) {
            bootargs_str = (char *)__kmalloc(sVar3 + 1,0xdc0);
            if (bootargs_str == (char *)0x0) goto LAB_00101ff4;
            pcVar7 = pcStack_a0;
          }
          strlcpy(bootargs_str,pcVar7,sVar3 + 1);
          pcVar7 = bootargs_str;
          sVar3 = strlen(bootargs_str);
          pcStack_a8 = (char *)strnstr(pcVar7,"androidboot.bootdevice=",sVar3);
          if (((pcStack_a8 != (char *)0x0) &&
              (pcStack_b0 = strsep(&pcStack_a8," "), pcStack_b0 != (char *)0x0)) &&
             (pcVar7 = strsep(&pcStack_b0,"="), pcVar7 != (char *)0x0)) {
            pcVar7 = strsep(&pcStack_b0,pcVar5);
            bVar1 = pcVar7 == (char *)0x0;
            *auVar8._0_8_ = pcVar7;
            goto LAB_00101ff8;
          }
        }
LAB_00101ff4:
        bVar1 = true;
LAB_00101ff8:
        lVar4 = sp_el0;
        if (*(long *)(lVar4 + 0x638) != lStack_98) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail(bVar1);
        }
        return;
      }
      strncpy(bootdevice_name,pcVar7,sVar6);
      utags_get_bootdevice_from_bootconfig_bootdevice_init = 1;
      goto LAB_00101e8c;
    }
    iVar2 = utag_get_bootarg(&local_50,"bootargs",&DAT_00105173);
    if ((iVar2 == 0) && (pcVar7 = local_50, local_50 != (char *)0x0)) goto LAB_00101e8c;
LAB_00101ec4:
    param0 = (char *)kstrdup(param_2,0xcc0);
  }
  else {
    pcVar7 = bootdevice_name;
LAB_00101e8c:
    lVar4 = strnstr(param_2,"bootdevice",sVar3);
    pcVar5 = (char *)strnstr(param_2,"by-name",sVar3);
    if ((lVar4 == 0) || (pcVar5 == (char *)0x0)) goto LAB_00101ec4;
    sVar3 = strlen(pcVar7);
    sVar6 = strlen(pcVar5);
    sVar3 = sVar3 + sVar6 + 0x1a;
    param0 = (char *)__kmalloc(sVar3,0xdc0);
    if (param0 == (char *)0x0) {
      _printk(&DAT_0010523b,"utags_bootdevice_expand");
      goto LAB_00101ec4;
    }
    snprintf(param0,sVar3,"/dev/block/platform/soc/%s/%s",pcVar7,pcVar5);
    _printk(&DAT_00104abe,"utags_bootdevice_expand",param0,sVar3);
  }
  *param_1 = param0;
LAB_00101ed8:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// utag_get_bootarg @ 00101f98 size=332
// signature: undefined utag_get_bootarg(void)
// callers: [utags_bootdevice_expand]
//------------------------------------------------------------

void utag_get_bootarg(undefined8 *param_1,undefined8 param_2,char *param_3)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  size_t sVar4;
  char *pcVar5;
  char *local_60;
  char *local_58;
  char *local_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = (char *)0x0;
  lVar3 = of_find_node_opts_by_path("/chosen",0);
  if ((lVar3 != 0) &&
     (iVar2 = of_property_read_string(lVar3,param_2,&local_50), pcVar5 = local_50, iVar2 == 0)) {
    sVar4 = strlen(local_50);
    if (bootargs_str == (char *)0x0) {
      bootargs_str = (char *)__kmalloc(sVar4 + 1,0xdc0);
      if (bootargs_str == (char *)0x0) goto LAB_00101ff4;
      pcVar5 = local_50;
    }
    strlcpy(bootargs_str,pcVar5,sVar4 + 1);
    pcVar5 = bootargs_str;
    sVar4 = strlen(bootargs_str);
    local_58 = (char *)strnstr(pcVar5,"androidboot.bootdevice=",sVar4);
    if (local_58 != (char *)0x0) {
      local_60 = strsep(&local_58," ");
      if ((local_60 != (char *)0x0) && (pcVar5 = strsep(&local_60,"="), pcVar5 != (char *)0x0)) {
        pcVar5 = strsep(&local_60,param_3);
        bVar1 = pcVar5 == (char *)0x0;
        *param_1 = pcVar5;
        goto LAB_00101ff8;
      }
    }
  }
LAB_00101ff4:
  bVar1 = true;
LAB_00101ff8:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar1);
  }
  return;
}



//------------------------------------------------------------
// reload_open @ 001020e8 size=48
// signature: undefined reload_open(void)
// callers: []
//------------------------------------------------------------

void reload_open(long param_1,undefined8 param_2)

{
  single_open(param_2,reload_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// reload_write @ 0010211c size=520
// signature: undefined reload_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong reload_write(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  undefined8 *puVar2;
  ulong uVar3;
  int iVar4;
  size_t __n;
  ulong uVar5;
  char *pcVar6;
  long lVar7;
  
  if (2 < param_3) {
    _printk(&DAT_00104dc5,"reload_write");
    return 0xfffffffffffffffb;
  }
  lVar7 = *(long *)(*(long *)(param_1 + 0x20) + 0x2b8);
  lVar1 = lVar7 + 0x90;
  mutex_lock(lVar1);
  puVar2 = (undefined8 *)sp_el0;
  pcVar6 = (char *)(lVar7 + 0x50);
  if (*pcVar6 == '0') {
    _printk(&DAT_001049c5,"reload_write",puVar2 + 0x109,*(undefined4 *)(puVar2 + 0xc6),
            *(undefined8 *)(lVar7 + 0x80));
LAB_001022b0:
    mutex_unlock(lVar1);
  }
  else {
    if (((*(byte *)((long)puVar2 + 0x46) >> 5 & 1) != 0) ||
       (uVar5 = param_2, ((uint)*puVar2 >> 0x1a & 1) != 0)) {
      uVar5 = param_2 & (long)(param_2 << 8) >> 8;
    }
    if (uVar5 >> 0x27 == 0) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar5 = daif;
        if ((uVar5 & 0x80) == 0) {
          uVar3 = daif;
          daif = uVar3 | 0xc0;
        }
        uVar3 = ttbr1_el1;
        ttbr1_el1 = puVar2[1] & 0xffff000000000000 | uVar3 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar2[1];
        InstructionSynchronizationBarrier();
        daif = uVar5;
      }
      __n = __arch_copy_from_user(pcVar6,param_2 & 0xff7fffffffffffff,1);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar5 = daif;
        if ((uVar5 & 0x80) == 0) {
          uVar3 = daif;
          daif = uVar3 | 0xc0;
        }
        uVar3 = ttbr1_el1;
        ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar3 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar5;
      }
      if (__n == 0) {
        _printk(&DAT_001050af,"reload_write",puVar2 + 0x109,*(undefined4 *)(puVar2 + 0xc6),
                *(undefined8 *)(lVar7 + 0x80),*(undefined1 *)(lVar7 + 0x50));
        if ((*(char *)(lVar7 + 0x50) == '1') && (iVar4 = rebuild_utags_directory(lVar7), iVar4 != 0)
           ) {
          *pcVar6 = '3';
        }
        goto LAB_001022b0;
      }
    }
    else {
      __n = 1;
    }
    memset(pcVar6 + (1 - __n),0,__n);
    _printk(&DAT_00105407,"reload_write");
    mutex_unlock(lVar1);
    param_3 = 0xfffffffffffffff2;
  }
  return param_3;
}



//------------------------------------------------------------
// reload_show @ 00102340 size=80
// signature: undefined reload_show(void)
// callers: []
//------------------------------------------------------------

undefined8 reload_show(long param_1)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0x80) == 0) {
    _printk(&DAT_00104cc8,"reload_show");
    uVar1 = 0xfffffffb;
  }
  else {
    seq_printf(param_1,&DAT_00104ceb,*(undefined1 *)(*(long *)(param_1 + 0x80) + 0x50));
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// rebuild_utags_directory @ 00102390 size=948
// signature: undefined rebuild_utags_directory(void)
// callers: [delete_utag, reload_write]
//------------------------------------------------------------

undefined8 rebuild_utags_directory(long param_1)

{
  code *pcVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  char *pcVar4;
  size_t sVar5;
  size_t sVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  ulong *puVar10;
  undefined1 *puVar11;
  ulong uVar12;
  ulong uVar13;
  undefined8 uVar14;
  long lVar15;
  char local_d0 [32];
  ulong *local_b0 [5];
  ulong local_88;
  ulong uStack_80;
  ulong local_78;
  ulong uStack_70;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  clear_utags_directory();
  queue_work_on(0x20,*(undefined8 *)(param_1 + 0x110),param_1 + 0x120);
  wait_for_completion(param_1 + 0xd0);
  lVar9 = *(long *)(param_1 + 0x180);
  if (lVar9 == 0) {
    _printk(&DAT_00104deb,"build_utags_directory",*(undefined8 *)(param_1 + 0x80));
    uVar14 = 0xfffffffb;
LAB_001026ac:
    lVar9 = sp_el0;
    if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return uVar14;
  }
  puVar10 = *(ulong **)(lVar9 + 0x58);
  do {
    while( true ) {
      local_78 = 0;
      uStack_70 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_d0[0x10] = '\0';
      local_d0[0x11] = '\0';
      local_d0[0x12] = '\0';
      local_d0[0x13] = '\0';
      local_d0[0x14] = '\0';
      local_d0[0x15] = '\0';
      local_d0[0x16] = '\0';
      local_d0[0x17] = '\0';
      local_d0[0x18] = '\0';
      local_d0[0x19] = '\0';
      local_d0[0x1a] = '\0';
      local_d0[0x1b] = '\0';
      local_d0[0x1c] = '\0';
      local_d0[0x1d] = '\0';
      local_d0[0x1e] = '\0';
      local_d0[0x1f] = '\0';
      local_d0[0] = '\0';
      local_d0[1] = '\0';
      local_d0[2] = '\0';
      local_d0[3] = '\0';
      local_d0[4] = '\0';
      local_d0[5] = '\0';
      local_d0[6] = '\0';
      local_d0[7] = '\0';
      local_d0[8] = '\0';
      local_d0[9] = '\0';
      local_d0[10] = '\0';
      local_d0[0xb] = '\0';
      local_d0[0xc] = '\0';
      local_d0[0xd] = '\0';
      local_d0[0xe] = '\0';
      local_d0[0xf] = '\0';
      local_b0[3] = (ulong *)0x0;
      local_b0[4] = (ulong *)0x0;
      local_b0[1] = (ulong *)0x0;
      local_b0[2] = (ulong *)0x0;
      if ((char)*puVar10 != '.') break;
      if (*(char *)((long)puVar10 + 1) != '\0') goto LAB_00102450;
      puVar2 = &DAT_00104f95;
LAB_00102664:
      _printk(puVar2,"no_show_tag");
      puVar10 = (ulong *)puVar10[0xb];
    }
    if (((char)*puVar10 == '/') && (*(char *)((long)puVar10 + 1) == '\0')) {
      puVar2 = &DAT_00105175;
      goto LAB_00102664;
    }
LAB_00102450:
    uVar12 = puVar10[0xb];
    if (uVar12 == 0) {
      uVar14 = 0;
LAB_00102684:
      do {
        lVar7 = *(long *)(lVar9 + 0x58);
        kfree(*(undefined8 *)(lVar9 + 0x50));
        kfree(lVar9);
        lVar9 = lVar7;
      } while (lVar7 != 0);
      if (uVar12 == 0) {
        uVar14 = 0;
        *(undefined1 *)(param_1 + 0x50) = 0x30;
      }
      goto LAB_001026ac;
    }
    local_78 = puVar10[2];
    uStack_70 = puVar10[3];
    local_88 = *puVar10;
    uStack_80 = puVar10[1];
    puVar3 = (undefined1 *)strnchr(&local_88,0x20,0x3a);
    puVar11 = puVar3;
    if (puVar3 != (undefined1 *)0x0) {
      puVar11 = puVar3 + 1;
      *puVar3 = 0;
    }
    if ((char)local_88 == '/') {
      local_88 = local_88 & 0xffffffffffffff00;
      local_b0[0] = (ulong *)((ulong)&local_88 | 1);
    }
    else {
      local_b0[0] = &local_88;
    }
    pcVar4 = (char *)strnchr(local_b0[0],0x20,0x2f);
    if (pcVar4 == (char *)0x0) {
      lVar7 = 0;
      lVar8 = 1;
    }
    else {
      local_b0[1] = (ulong *)pcVar4;
      if (*pcVar4 == '/') {
        local_b0[1] = (ulong *)(pcVar4 + 1);
        *pcVar4 = '\0';
      }
      pcVar4 = (char *)strnchr(local_b0[1],0x20,0x2f);
      if (pcVar4 == (char *)0x0) {
        lVar8 = 2;
        lVar7 = 1;
      }
      else {
        local_b0[2] = (ulong *)pcVar4;
        if (*pcVar4 == '/') {
          local_b0[2] = (ulong *)(pcVar4 + 1);
          *pcVar4 = '\0';
        }
        pcVar4 = (char *)strnchr(local_b0[2],0x20,0x2f);
        if (pcVar4 == (char *)0x0) {
          lVar8 = 3;
          lVar7 = 2;
        }
        else {
          local_b0[3] = (ulong *)pcVar4;
          if (*pcVar4 == '/') {
            local_b0[3] = (ulong *)(pcVar4 + 1);
            *pcVar4 = '\0';
          }
          pcVar4 = (char *)strnchr(local_b0[3],0x20,0x2f);
          if (pcVar4 == (char *)0x0) {
            lVar8 = 4;
            lVar7 = 3;
          }
          else {
            local_b0[4] = (ulong *)pcVar4;
            if (*pcVar4 == '/') {
              local_b0[4] = (ulong *)(pcVar4 + 1);
              *pcVar4 = '\0';
            }
            pcVar4 = (char *)strnchr(local_b0[4],0x20,0x2f);
            if (pcVar4 != (char *)0x0) {
              if (*pcVar4 == '/') {
                *pcVar4 = '\0';
              }
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(1,0x102744);
              (*pcVar1)();
            }
            lVar8 = 5;
            lVar7 = 4;
          }
        }
      }
    }
    lVar15 = 0;
    uVar13 = 0;
    do {
      sVar5 = strnlen(local_d0,0x20);
      if (0x20 < sVar5) {
LAB_00102710:
        fortify_panic("strnlen");
LAB_0010271c:
        fortify_panic("__fortify_strlen");
LAB_00102728:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10272c);
        (*pcVar1)();
      }
      if (sVar5 == 0x20) goto LAB_0010271c;
      sVar6 = strnlen(local_d0,0x20);
      if (0x20 < sVar6) goto LAB_00102710;
      if (sVar6 == 0x20) goto LAB_0010271c;
      if (lVar15 == 0x28) goto LAB_00102728;
      uVar14 = *(undefined8 *)((long)local_b0 + lVar15);
      puVar2 = &DAT_00104cf9;
      if (lVar15 != 0) {
        puVar2 = &DAT_0010506b;
      }
      scnprintf(local_d0 + sVar5,0x20 - sVar6,&DAT_00104e0a,puVar2,uVar14);
      uVar13 = proc_utag_dir(param_1,uVar14,local_d0,puVar11,lVar7 * 8 == lVar15,uVar13);
      if (0xfffffffffffff000 < uVar13) {
        uVar14 = 0xffffffea;
        goto LAB_00102684;
      }
      lVar15 = lVar15 + 8;
    } while (lVar8 * 8 != lVar15);
    puVar10 = (ulong *)puVar10[0xb];
  } while( true );
}



//------------------------------------------------------------
// clear_utags_directory @ 00102744 size=308
// signature: undefined clear_utags_directory(void)
// callers: [utags_remove, rebuild_utags_directory]
//------------------------------------------------------------

void clear_utags_directory(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  
  plVar5 = (long *)(param_1 + 0x60);
  plVar4 = (long *)*plVar5;
  if ((long *)*plVar5 != plVar5) {
    do {
      plVar6 = (long *)*plVar4;
      if (plVar4[0xb] == *(long *)(param_1 + 0x48)) {
        remove_proc_subtree(plVar4 + 2);
        uVar3 = __list_del_entry_valid(plVar4);
        if ((uVar3 & 1) != 0) {
          lVar1 = *plVar4;
          plVar2 = (long *)plVar4[1];
          *(long **)(lVar1 + 8) = plVar2;
          *plVar2 = lVar1;
        }
        *plVar4 = -0x2152ffffffffff00;
        plVar4[1] = -0x2152fffffffffede;
        kfree(plVar4);
      }
      plVar4 = plVar6;
    } while (plVar6 != plVar5);
    plVar4 = (long *)*plVar5;
    while (plVar4 != plVar5) {
      plVar6 = (long *)*plVar4;
      uVar3 = __list_del_entry_valid(plVar4);
      if ((uVar3 & 1) != 0) {
        lVar1 = *plVar4;
        plVar2 = (long *)plVar4[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar4 = -0x2152ffffffffff00;
      plVar4[1] = -0x2152fffffffffede;
      kfree(plVar4);
      plVar4 = plVar6;
    }
  }
  plVar4 = *(long **)(param_1 + 0x70);
  while (plVar4 != (long *)(param_1 + 0x70)) {
    plVar5 = (long *)*plVar4;
    uVar3 = __list_del_entry_valid(plVar4);
    if ((uVar3 & 1) != 0) {
      lVar1 = *plVar4;
      plVar6 = (long *)plVar4[1];
      *(long **)(lVar1 + 8) = plVar6;
      *plVar6 = lVar1;
    }
    *plVar4 = -0x2152ffffffffff00;
    plVar4[1] = -0x2152fffffffffede;
    kfree(plVar4);
    plVar4 = plVar5;
  }
  return;
}



//------------------------------------------------------------
// proc_utag_dir @ 00102878 size=472
// signature: undefined proc_utag_dir(void)
// callers: [new_utag, rebuild_utags_directory]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long proc_utag_dir(long param_1,char *param_2,char *param_3,undefined8 param_4,uint param_5,
                  long param_6)

{
  long *plVar1;
  int iVar2;
  ulong uVar3;
  size_t sVar4;
  long lVar5;
  long *plVar6;
  undefined8 *puVar7;
  
  if (param_6 == 0) {
    param_6 = *(long *)(param_1 + 0x48);
  }
  plVar1 = (long *)(param_1 + 0x60);
  plVar6 = plVar1;
  do {
    plVar6 = (long *)*plVar6;
    if (plVar6 == plVar1) goto LAB_001028f0;
    iVar2 = strncmp((char *)(plVar6 + 6),param_3,0x20);
  } while (iVar2 != 0);
  if (plVar6 == (long *)0x0) {
LAB_001028f0:
    lVar5 = proc_mkdir_data(param_2,0x1f9,param_6,0);
    if (lVar5 == 0) {
      _printk(&DAT_00104ae7,"proc_utag_dir",param_2);
    }
    else {
      plVar6 = (long *)kmalloc_trace(_complete,0xdc0,0x68);
      if (plVar6 != (long *)0x0) {
        puVar7 = *(undefined8 **)(param_1 + 0x68);
        plVar6[0xb] = param_6;
        plVar6[0xc] = param_1;
        plVar6[10] = lVar5;
        uVar3 = __list_add_valid(plVar6,puVar7,plVar1);
        if ((uVar3 & 1) != 0) {
          *(long **)(param_1 + 0x68) = plVar6;
          *plVar6 = (long)plVar1;
          plVar6[1] = (long)puVar7;
          *puVar7 = plVar6;
        }
        sVar4 = strlen(param_2);
        if (0x1e < sVar4) {
          sVar4 = 0x1f;
        }
        memcpy(plVar6 + 2,param_2,sVar4);
        *(undefined1 *)((long)(plVar6 + 2) + sVar4) = 0;
        sVar4 = strlen(param_3);
        if (0x1e < sVar4) {
          sVar4 = 0x1f;
        }
        memcpy(plVar6 + 6,param_3,sVar4);
        *(undefined1 *)((long)(plVar6 + 6) + sVar4) = 0;
        if ((param_5 & 1) == 0) {
          return lVar5;
        }
        goto LAB_001029a8;
      }
      kfree(lVar5);
      _printk(&DAT_00105117,"proc_utag_dir");
    }
    lVar5 = -0xc;
  }
  else {
    if ((param_5 & 1) == 0) {
      return plVar6[10];
    }
    lVar5 = 0;
LAB_001029a8:
    proc_utag_file(param_2,param_4,0,plVar6);
    proc_utag_file(param_2,param_4,1,plVar6);
    proc_utag_file(param_2,param_4,2,plVar6);
  }
  return lVar5;
}



//------------------------------------------------------------
// proc_utag_file @ 00102a50 size=360
// signature: undefined proc_utag_file(void)
// callers: [proc_utag_dir]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void proc_utag_file(char *param_1,char *param_2,uint param_3,long param_4)

{
  long *__dest;
  long *__dest_00;
  code *pcVar1;
  long *plVar2;
  ulong uVar3;
  size_t sVar4;
  long lVar5;
  undefined8 *puVar6;
  char *__s;
  long lVar7;
  
  lVar7 = *(long *)(param_4 + 0x60);
  plVar2 = (long *)kmalloc_trace(_strnchr,0xdc0,0x90);
  if (plVar2 != (long *)0x0) {
    puVar6 = *(undefined8 **)(lVar7 + 0x78);
    uVar3 = __list_add_valid(plVar2,puVar6,lVar7 + 0x70);
    if ((uVar3 & 1) != 0) {
      *(long **)(lVar7 + 0x78) = plVar2;
      *plVar2 = lVar7 + 0x70;
      plVar2[1] = (long)puVar6;
      *puVar6 = plVar2;
    }
    if (2 < param_3) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(1,0x102bb8);
      (*pcVar1)();
    }
    __dest = plVar2 + 10;
    __s = (&files)[param_3];
    sVar4 = strlen(__s);
    if (0x1e < sVar4) {
      sVar4 = 0x1f;
    }
    memcpy(__dest,__s,sVar4);
    *(undefined1 *)((long)__dest + sVar4) = 0;
    sVar4 = strlen(param_1);
    if (0x1e < sVar4) {
      sVar4 = 0x1f;
    }
    memcpy(plVar2 + 2,param_1,sVar4);
    __dest_00 = plVar2 + 6;
    *(undefined1 *)((long)(plVar2 + 2) + sVar4) = 0;
    if (param_2 == (char *)0x0) {
      *(undefined1 *)__dest_00 = 0;
    }
    else {
      sVar4 = strlen(param_2);
      if (0x1e < sVar4) {
        sVar4 = 0x1f;
      }
      memcpy(__dest_00,param_2,sVar4);
      *(undefined1 *)((long)__dest_00 + sVar4) = 0;
    }
    lVar5 = *(long *)(param_4 + 0x50);
    *(uint *)(plVar2 + 0x10) = param_3;
    plVar2[0xf] = lVar5;
    plVar2[0x11] = lVar7;
    lVar7 = proc_create_data(__dest,0x1b0,lVar5,utag_fops,plVar2);
    plVar2[0xe] = lVar7;
  }
  return;
}



//------------------------------------------------------------
// partition_open @ 00102bbc size=48
// signature: undefined partition_open(void)
// callers: []
//------------------------------------------------------------

void partition_open(long param_1,undefined8 param_2)

{
  single_open(param_2,read_utag,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// write_utag @ 00102bf0 size=1736
// signature: undefined write_utag(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong write_utag(long param_1,ulong param_2,ulong param_3)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  ulong uVar4;
  code *pcVar5;
  bool bVar6;
  int iVar7;
  char *__string;
  ulong uVar8;
  size_t sVar9;
  undefined1 *puVar10;
  char *__dest;
  char *__string_00;
  size_t sVar11;
  undefined *puVar12;
  long lVar13;
  undefined8 *extraout_x8;
  undefined8 *puVar14;
  ulong uVar15;
  ulong uVar16;
  long lVar17;
  undefined8 uVar18;
  long lVar19;
  char *local_b0;
  char local_a8 [32];
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar17 = sp_el0;
  local_68 = *(long *)(lVar17 + 0x638);
  local_a8[0x10] = '\0';
  local_a8[0x11] = '\0';
  local_a8[0x12] = '\0';
  local_a8[0x13] = '\0';
  local_a8[0x14] = '\0';
  local_a8[0x15] = '\0';
  local_a8[0x16] = '\0';
  local_a8[0x17] = '\0';
  local_a8[0x18] = '\0';
  local_a8[0x19] = '\0';
  local_a8[0x1a] = '\0';
  local_a8[0x1b] = '\0';
  local_a8[0x1c] = '\0';
  local_a8[0x1d] = '\0';
  local_a8[0x1e] = '\0';
  local_a8[0x1f] = '\0';
  local_a8[0] = '\0';
  local_a8[1] = '\0';
  local_a8[2] = '\0';
  local_a8[3] = '\0';
  local_a8[4] = '\0';
  local_a8[5] = '\0';
  local_a8[6] = '\0';
  local_a8[7] = '\0';
  local_a8[8] = '\0';
  local_a8[9] = '\0';
  local_a8[10] = '\0';
  local_a8[0xb] = '\0';
  local_a8[0xc] = '\0';
  local_a8[0xd] = '\0';
  local_a8[0xe] = '\0';
  local_a8[0xf] = '\0';
  lVar17 = *(long *)(*(long *)(param_1 + 0x20) + 0x2b8);
  if (*(int *)(lVar17 + 0x80) == 2) {
    param_3 = 0xffffffffffffffea;
  }
  else if (param_3 < 0x401) {
    uVar16 = param_3 + 1;
    lVar19 = *(long *)(lVar17 + 0x88);
    __string = (char *)__kmalloc(uVar16,0xdc0);
    if (__string != (char *)0x0) {
      __check_object_size(__string,param_3,0);
      puVar14 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
         (uVar15 = param_2, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
        uVar15 = param_2 & (long)(param_2 << 8) >> 8;
      }
      uVar8 = param_3;
      if (0x8000000000 - param_3 < uVar15) goto LAB_00102d48;
      do {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar15 = daif;
          if ((uVar15 & 0x80) == 0) {
            uVar8 = daif;
            daif = uVar8 | 0xc0;
          }
          uVar8 = ttbr1_el1;
          ttbr1_el1 = puVar14[1] & 0xffff000000000000 | uVar8 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar14[1];
          InstructionSynchronizationBarrier();
          daif = uVar15;
        }
        uVar8 = __arch_copy_from_user(__string,param_2 & 0xff7fffffffffffff,param_3);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar15 = daif;
          if ((uVar15 & 0x80) == 0) {
            uVar4 = daif;
            daif = uVar4 | 0xc0;
          }
          uVar4 = ttbr1_el1;
          ttbr0_el1 = (uVar4 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar4 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar15;
        }
LAB_00102d48:
        if (uVar8 != 0) {
          memset(__string + (param_3 - uVar8),0,uVar8);
          _printk(&DAT_00105407,"write_utag");
          param_3 = 0xfffffffffffffffb;
          goto LAB_001030ac;
        }
        param_2 = param_3 - 1;
        if (((long)param_3 < 1) || (uVar16 < param_2)) {
LAB_00103280:
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(1,0x103284);
          (*pcVar5)();
        }
        if (__string[param_2] == '\n') {
          if (((long)param_3 < 1) || (uVar16 < param_2)) goto LAB_00103280;
          uVar16 = 0;
          if (param_2 != 0) {
            uVar16 = param_3 - 2;
          }
          __string[param_2] = '\0';
          iVar7 = *(int *)(lVar17 + 0x80);
        }
        else {
          iVar7 = *(int *)(lVar17 + 0x80);
          uVar16 = param_2;
          param_2 = param_3;
        }
        if (iVar7 == 0) {
          uVar15 = 0;
          do {
            if (((long)uVar15 < 0) || (param_3 < uVar15)) goto LAB_00103280;
            if (__string[uVar15] == '\0') goto LAB_00102df0;
            uVar15 = (ulong)((int)uVar15 + 1);
          } while (uVar15 <= uVar16);
          if (((long)(uVar16 + 1) < 0) || (param_3 <= uVar16)) goto LAB_00103280;
          param_2 = param_2 + 1;
          __string[uVar16 + 1] = '\0';
        }
LAB_00102df0:
        mutex_lock(lVar19 + 0x90);
        queue_work_on(0x20,*(undefined8 *)(lVar19 + 0x110),lVar19 + 0x120);
        wait_for_completion(lVar19 + 0xd0);
        uVar16 = *(ulong *)(lVar19 + 0x180);
        if (uVar16 == 0) {
          _printk(&DAT_00104deb,"write_utag",*(undefined8 *)(lVar19 + 0x80));
          param_3 = 0xfffffffffffffffb;
          goto LAB_001030ac;
        }
        if (*(int *)(lVar19 + 0x88) != 0) {
          _printk(&DAT_00104b91,"write_utag",lVar17 + 0x10,*(undefined8 *)(lVar19 + 0x80));
          param_3 = 0xfffffffffffffff3;
          goto LAB_00103094;
        }
        iVar7 = full_utag_name(lVar17,local_a8);
        if (iVar7 == 0) {
          _printk(&DAT_00104c21,"write_utag");
          param_3 = 0xfffffffffffffffb;
          goto LAB_00103094;
        }
        if ((param_2 == 0) || (*(int *)(lVar19 + 0x8c) == 0)) goto LAB_00102fe8;
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        uStack_80 = 0;
        sVar9 = strnlen(local_a8,0x20);
        if (0x20 < sVar9) goto LAB_00103284;
        if (sVar9 != 0x20) goto code_r0x00102e64;
        fortify_panic("__fortify_strlen");
        lVar17 = 0x20;
        puVar14 = extraout_x8;
      } while( true );
    }
    param_3 = 0xfffffffffffffff4;
  }
  else {
    _printk(&DAT_00105081,"write_utag",param_3);
    param_3 = 0xffffffffffffffea;
  }
LAB_001030bc:
  lVar17 = sp_el0;
  if (*(long *)(lVar17 + 0x638) == local_68) {
    return param_3;
  }
LAB_00103290:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
code_r0x00102e64:
  memcpy(&local_88,local_a8,sVar9);
  local_a8[sVar9 + 0x20] = '\0';
  puVar10 = (undefined1 *)strnchr(&local_88,0x20,0x3a);
  if (puVar10 != (undefined1 *)0x0) {
    *puVar10 = 0;
  }
  uVar15 = strlcat(&local_88,"/.range",0x20);
  if (uVar15 < 0x21) {
    lVar17 = *(long *)(uVar16 + 0x58);
    do {
      lVar13 = lVar17;
      if ((lVar13 == 0) || (*(long *)(lVar13 + 0x58) == 0)) goto LAB_00102fe8;
      lVar17 = 0;
      do {
        if (lVar17 == 0x20) goto LAB_00102efc;
        cVar2 = local_a8[lVar17 + 0x20];
        cVar3 = *(char *)(lVar13 + lVar17);
      } while (((cVar2 == cVar3) && (cVar2 != '\0')) && (lVar17 = lVar17 + 1, cVar3 != '\0'));
      lVar17 = *(long *)(lVar13 + 0x58);
    } while (cVar2 != cVar3);
LAB_00102efc:
    uVar1 = *(uint *)(lVar13 + 0x40);
    if (uVar1 == 0) {
LAB_00102fe8:
      lVar17 = *(long *)(uVar16 + 0x58);
      do {
        lVar13 = lVar17;
        if ((lVar13 == 0) || (*(long *)(lVar13 + 0x58) == 0)) goto LAB_00103070;
        lVar17 = 0;
        do {
          if (lVar17 == 0x20) goto LAB_00103034;
          cVar2 = local_a8[lVar17];
          cVar3 = *(char *)(lVar13 + lVar17);
        } while (((cVar2 == cVar3) && (cVar2 != '\0')) && (lVar17 = lVar17 + 1, cVar3 != '\0'));
        lVar17 = *(long *)(lVar13 + 0x58);
      } while (cVar2 != cVar3);
LAB_00103034:
      if ((*(byte *)(lVar13 + 0x44) & 1) == 0) {
        uVar18 = *(undefined8 *)(lVar13 + 0x50);
        lVar17 = __kmalloc(param_2 + 1,0xdc0);
        *(long *)(lVar13 + 0x50) = lVar17;
        if (lVar17 != 0) {
          memcpy(*(void **)(lVar13 + 0x50),__string,param_2);
          *(int *)(lVar13 + 0x40) = (int)param_2;
          kfree(uVar18);
LAB_00103070:
          queue_work_on(0x20,*(undefined8 *)(lVar19 + 0x118),lVar19 + 0x150);
          wait_for_completion(lVar19 + 0xf0);
          if (*(int *)(lVar19 + 0x188) != 0) {
            param_3 = (long)*(int *)(lVar19 + 0x188);
          }
          goto LAB_00103094;
        }
        *(undefined8 *)(lVar13 + 0x50) = uVar18;
      }
      else {
        _printk(&DAT_0010531b,"replace_first_utag",local_a8);
      }
      _printk(&DAT_001051ca,"write_utag",local_a8);
      param_3 = 0xfffffffffffffffb;
    }
    else {
      sVar9 = strnlen(*(char **)(lVar13 + 0x50),(ulong)uVar1);
      if (sVar9 == 0xffffffffffffffff) {
LAB_00103284:
        fortify_panic("strnlen");
        goto LAB_00103290;
      }
      if (sVar9 == uVar1) {
        puVar12 = &DAT_00104ff8;
        goto LAB_001031cc;
      }
      if (sVar9 + 1 < param_2) {
        _printk(&DAT_0010543b,"check_utag_range",local_a8,param_2);
        param_3 = 0xffffffffffffffea;
      }
      else {
        sVar9 = strnlen(__string,param_2);
        if ((sVar9 == 0xffffffffffffffff) && (param_2 != 0xffffffffffffffff)) goto LAB_00103284;
        if (sVar9 == param_2) {
          _printk(&DAT_00105382,"check_utag_range",local_a8);
          param_3 = 0xffffffffffffffea;
        }
        else {
          __dest = (char *)__kmalloc(uVar1 + 1,0xdc0);
          local_b0 = __dest;
          if (__dest != (char *)0x0) {
            memcpy(__dest,*(void **)(lVar13 + 0x50),(ulong)*(uint *)(lVar13 + 0x40));
            if (local_b0 == (char *)0x0) {
              kfree(__dest);
            }
            else {
              do {
                __string_00 = strsep(&local_b0,",");
                sVar11 = strnlen(__string_00,0x400);
                if (sVar11 == 0xffffffffffffffff) goto LAB_00103284;
                if (sVar9 == sVar11) {
                  iVar7 = strncmp(__string_00,__string,sVar9);
                  bVar6 = iVar7 == 0;
                }
                else {
                  bVar6 = false;
                }
              } while ((local_b0 != (char *)0x0) && (!bVar6));
              kfree(__dest);
              if (bVar6) goto LAB_00102fe8;
            }
            _printk(&DAT_0010526d,"check_utag_range",__string,&local_88);
          }
          param_3 = 0xffffffffffffffea;
        }
      }
    }
  }
  else {
    puVar12 = &DAT_00104bb4;
LAB_001031cc:
    _printk(puVar12,"check_utag_range",&local_88);
    param_3 = 0xffffffffffffffea;
  }
LAB_00103094:
  do {
    uVar15 = *(ulong *)(uVar16 + 0x58);
    kfree(*(undefined8 *)(uVar16 + 0x50));
    kfree(uVar16);
    uVar16 = uVar15;
  } while (uVar15 != 0);
LAB_001030ac:
  kfree(__string);
  mutex_unlock(lVar19 + 0x90);
  goto LAB_001030bc;
}



//------------------------------------------------------------
// read_utag @ 001032d4 size=560
// signature: undefined read_utag(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x001034fc) */

undefined8 read_utag(long param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  char *pcVar10;
  uint uVar11;
  char local_78 [32];
  long local_58;
  
  lVar7 = sp_el0;
  local_58 = *(long *)(lVar7 + 0x638);
  lVar9 = *(long *)(param_1 + 0x80);
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
  lVar6 = *(long *)(lVar9 + 0x88);
  mutex_lock(lVar6 + 0x90);
  queue_work_on(0x20,*(undefined8 *)(lVar6 + 0x110),lVar6 + 0x120);
  wait_for_completion(lVar6 + 0xd0);
  lVar7 = *(long *)(lVar6 + 0x180);
  if (lVar7 == 0) {
    _printk(&DAT_00104ea3,"read_utag");
    uVar8 = 0xfffffff2;
    goto LAB_00103468;
  }
  iVar3 = full_utag_name(lVar9,local_78);
  if (iVar3 == 0) {
    seq_puts(param_1,"cannot find utag associated with this file\n");
    uVar8 = 0xffffffea;
  }
  else {
    lVar5 = *(long *)(lVar7 + 0x58);
    do {
      lVar4 = lVar5;
      if ((lVar4 == 0) || (*(long *)(lVar4 + 0x58) == 0)) {
        seq_printf(param_1,"utag [%s] not found\n",local_78);
        uVar8 = 0xffffffea;
        goto LAB_00103450;
      }
      lVar5 = 0;
      do {
        if (lVar5 == 0x20) goto LAB_0010339c;
        cVar1 = local_78[lVar5];
        cVar2 = *(char *)(lVar4 + lVar5);
      } while (((cVar1 == cVar2) && (cVar1 != '\0')) && (lVar5 = lVar5 + 1, cVar2 != '\0'));
      lVar5 = *(long *)(lVar4 + 0x58);
    } while (cVar1 != cVar2);
LAB_0010339c:
    pcVar10 = *(char **)(lVar4 + 0x50);
    if (pcVar10 == (char *)0x0) {
      _printk(&DAT_00104fce,"read_utag",local_78);
    }
    else {
      iVar3 = *(int *)(lVar9 + 0x80);
      if (iVar3 == 0) {
LAB_00103438:
        seq_printf(param_1,&DAT_00104bfb,pcVar10);
      }
      else if (iVar3 == 2) {
        pcVar10 = (char *)(lVar9 + 0x30);
        if (*pcVar10 != '\0') goto LAB_00103438;
      }
      else if ((iVar3 == 1) && (*(int *)(lVar4 + 0x40) != 0)) {
        uVar11 = 0;
        do {
          seq_printf(param_1,&DAT_001051c5,pcVar10[(int)uVar11]);
          uVar11 = uVar11 + 1;
        } while (uVar11 < *(uint *)(lVar4 + 0x40));
      }
      seq_puts(param_1,&DAT_00105263);
    }
    uVar8 = 0;
  }
LAB_00103450:
  do {
    lVar9 = *(long *)(lVar7 + 0x58);
    kfree(*(undefined8 *)(lVar7 + 0x50));
    kfree(lVar7);
    lVar7 = lVar9;
  } while (lVar9 != 0);
LAB_00103468:
  mutex_unlock(lVar6 + 0x90);
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



//------------------------------------------------------------
// full_utag_name @ 00103504 size=852
// signature: undefined full_utag_name(void)
// callers: [write_utag, read_utag]
//------------------------------------------------------------

int full_utag_name(long param_1,undefined1 *param_2)

{
  long *plVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  long lVar10;
  long *plVar11;
  long *plVar12;
  long *local_80;
  long local_78;
  long *local_70;
  long *local_68;
  long *local_60;
  long local_58;
  
  lVar10 = sp_el0;
  local_58 = *(long *)(lVar10 + 0x638);
  lVar10 = *(long *)(param_1 + 0x88);
  *param_2 = 0;
  local_68 = (long *)0x0;
  local_60 = (long *)0x0;
  local_78 = 0;
  local_70 = (long *)0x0;
  if (*(long *)(param_1 + 0x78) != 0) {
    plVar1 = (long *)(lVar10 + 0x60);
    plVar12 = plVar1;
    do {
      plVar12 = (long *)*plVar12;
      if (plVar12 == plVar1) goto LAB_0010366c;
    } while (plVar12[10] != *(long *)(param_1 + 0x78));
    if (plVar12 != (long *)0x0) {
      local_80 = plVar12 + 2;
      if (plVar12[0xb] == 0) {
LAB_001036d4:
        bVar5 = false;
        iVar9 = 1;
      }
      else {
        plVar11 = plVar1;
        do {
          plVar11 = (long *)*plVar11;
          if (plVar11 == plVar1) goto LAB_001036d4;
        } while (plVar11[10] != plVar12[0xb]);
        if (plVar11 == (long *)0x0) goto LAB_001036d4;
        local_78 = (long)(plVar11 + 2);
        if (plVar11[0xb] == 0) {
LAB_00103830:
          iVar9 = 2;
        }
        else {
          plVar12 = plVar1;
          do {
            plVar12 = (long *)*plVar12;
            if (plVar12 == plVar1) goto LAB_00103830;
          } while (plVar12[10] != plVar11[0xb]);
          if (plVar12 == (long *)0x0) goto LAB_00103830;
          local_70 = plVar12 + 2;
          if (plVar12[0xb] == 0) {
LAB_0010383c:
            iVar9 = 3;
          }
          else {
            plVar11 = plVar1;
            do {
              plVar11 = (long *)*plVar11;
              if (plVar11 == plVar1) goto LAB_0010383c;
            } while (plVar11[10] != plVar12[0xb]);
            if (plVar11 == (long *)0x0) goto LAB_0010383c;
            local_68 = plVar11 + 2;
            if (plVar11[0xb] == 0) {
LAB_00103844:
              iVar9 = 4;
            }
            else {
              plVar12 = plVar1;
              do {
                plVar12 = (long *)*plVar12;
                if (plVar12 == plVar1) goto LAB_00103844;
              } while (plVar12[10] != plVar11[0xb]);
              if (plVar12 == (long *)0x0) goto LAB_00103844;
              local_60 = plVar12 + 2;
              if (plVar12[0xb] != 0) {
                plVar11 = plVar1;
                do {
                  plVar11 = (long *)*plVar11;
                  if (plVar11 == plVar1) goto LAB_00103664;
                } while (plVar11[10] != plVar12[0xb]);
                if (plVar11 != (long *)0x0) {
                    /* WARNING: Does not return */
                  pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x103858);
                  (*pcVar6)();
                }
              }
LAB_00103664:
              iVar9 = 5;
            }
          }
        }
        bVar5 = true;
      }
      uVar3 = iVar9 - 1;
      if (4 < uVar3) {
LAB_00103850:
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(1,0x103854);
        (*pcVar6)();
      }
      puVar2 = &DAT_00104cf9;
      if (uVar3 != 0) {
        puVar2 = &DAT_0010506b;
      }
      iVar7 = scnprintf(param_2,0x20,&DAT_00104e0a,(&local_80)[uVar3],puVar2);
      if (bVar5) {
        uVar4 = iVar9 - 2;
        if (4 < uVar4) goto LAB_00103850;
        puVar2 = &DAT_00104cf9;
        if (uVar4 != 0) {
          puVar2 = &DAT_0010506b;
        }
        iVar8 = scnprintf(param_2 + iVar7,(long)(0x20 - iVar7),&DAT_00104e0a,(&local_80)[uVar4],
                          puVar2);
        iVar7 = iVar8 + iVar7;
        if (1 < uVar3) {
          uVar3 = iVar9 - 3;
          if (4 < uVar3) goto LAB_00103850;
          puVar2 = &DAT_00104cf9;
          if (uVar3 != 0) {
            puVar2 = &DAT_0010506b;
          }
          iVar8 = scnprintf(param_2 + iVar7,(long)(0x20 - iVar7),&DAT_00104e0a,(&local_80)[uVar3],
                            puVar2);
          iVar7 = iVar8 + iVar7;
          if (1 < uVar4) {
            uVar4 = iVar9 - 4;
            if (4 < uVar4) goto LAB_00103850;
            puVar2 = &DAT_00104cf9;
            if (uVar4 != 0) {
              puVar2 = &DAT_0010506b;
            }
            iVar8 = scnprintf(param_2 + iVar7,(long)(0x20 - iVar7),&DAT_00104e0a,(&local_80)[uVar4],
                              puVar2);
            iVar7 = iVar8 + iVar7;
            if (1 < uVar3) {
              uVar3 = iVar9 - 5;
              if (4 < uVar3) goto LAB_00103850;
              puVar2 = &DAT_00104cf9;
              if (uVar3 != 0) {
                puVar2 = &DAT_0010506b;
              }
              iVar9 = scnprintf(param_2 + iVar7,(long)(0x20 - iVar7),&DAT_00104e0a,
                                (&local_80)[uVar3],puVar2);
              iVar7 = iVar9 + iVar7;
            }
          }
        }
      }
      goto LAB_00103670;
    }
  }
LAB_0010366c:
  iVar7 = 0;
LAB_00103670:
  if (*(char *)(param_1 + 0x30) != '\0') {
    iVar9 = scnprintf(param_2 + iVar7,(long)(0x20 - iVar7),&DAT_00104b0e,(char *)(param_1 + 0x30));
    iVar7 = iVar9 + iVar7;
  }
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// new_utag @ 0010385c size=2240
// signature: undefined new_utag(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

size_t new_utag(long param_1,ulong param_2,size_t param_3)

{
  long lVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  code *pcVar6;
  int iVar7;
  size_t __n;
  undefined *puVar8;
  undefined1 *puVar9;
  char *pcVar10;
  char *pcVar11;
  undefined8 *puVar12;
  uint uVar13;
  ulong uVar14;
  long lVar15;
  char cVar16;
  long lVar17;
  long lVar18;
  ulong uVar19;
  long lVar20;
  undefined1 *puVar21;
  ulong uVar22;
  long *plVar23;
  char *pcVar24;
  bool bVar25;
  char *local_158 [4];
  char *local_138;
  char cStack_131;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  char local_110 [32];
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  lVar18 = sp_el0;
  local_70 = *(long *)(lVar18 + 0x638);
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  lVar18 = *(long *)(*(long *)(param_1 + 0x20) + 0x2b8);
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_110[0x10] = '\0';
  local_110[0x11] = '\0';
  local_110[0x12] = '\0';
  local_110[0x13] = '\0';
  local_110[0x14] = '\0';
  local_110[0x15] = '\0';
  local_110[0x16] = '\0';
  local_110[0x17] = '\0';
  local_110[0x18] = '\0';
  local_110[0x19] = '\0';
  local_110[0x1a] = '\0';
  local_110[0x1b] = '\0';
  local_110[0x1c] = '\0';
  local_110[0x1d] = '\0';
  local_110[0x1e] = '\0';
  local_110[0x1f] = '\0';
  local_110[0] = '\0';
  local_110[1] = '\0';
  local_110[2] = '\0';
  local_110[3] = '\0';
  local_110[4] = '\0';
  local_110[5] = '\0';
  local_110[6] = '\0';
  local_110[7] = '\0';
  local_110[8] = '\0';
  local_110[9] = '\0';
  local_110[10] = '\0';
  local_110[0xb] = '\0';
  local_110[0xc] = '\0';
  local_110[0xd] = '\0';
  local_110[0xe] = '\0';
  local_110[0xf] = '\0';
  local_120 = 0;
  uStack_118 = 0;
  local_130 = 0;
  uStack_128 = 0;
  local_158[3] = (char *)0x0;
  local_138 = (char *)0x0;
  local_158[1] = (char *)0x0;
  local_158[2] = (char *)0x0;
  local_158[0] = (char *)0x0;
  if (param_3 - 0x21 < 0xffffffffffffffdf || param_3 == 0) {
    _printk(&DAT_00104ef9,"new_utag",param_3);
    param_3 = 0xfffffffffffffffb;
    goto LAB_00104044;
  }
  __check_object_size(&local_130,param_3,0);
  puVar12 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar12 + 0x46) >> 5 & 1) != 0) ||
     (uVar14 = param_2, ((uint)*puVar12 >> 0x1a & 1) != 0)) {
    uVar14 = param_2 & (long)(param_2 << 8) >> 8;
  }
  __n = param_3;
  if (uVar14 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar19 = daif;
        daif = uVar19 | 0xc0;
      }
      puVar12 = (undefined8 *)puVar12[1];
      uVar19 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar12 & 0xffff000000000000 | uVar19 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar12;
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    __n = __arch_copy_from_user(puVar12,&local_130,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar19 = daif;
        daif = uVar19 | 0xc0;
      }
      uVar19 = ttbr1_el1;
      ttbr0_el1 = (uVar19 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar19 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    if (__n == 0) {
      if (param_3 - 0x21 < 0xffffffffffffffe0) {
LAB_00104100:
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(1,0x104104);
        (*pcVar6)();
      }
      *(undefined1 *)((long)local_158 + param_3 + 0x27) = 0;
      if ((char)local_130 == ':') {
LAB_00103c5c:
        puVar8 = &DAT_00104b41;
        pcVar24 = "new_utag";
      }
      else {
        iVar7 = (int)(param_3 - 1);
        if (iVar7 != 0) {
          uVar13 = 0;
          uVar14 = 0;
          cVar16 = (char)local_130;
          do {
            if (cVar16 == ':') {
              uVar13 = uVar13 + 1;
            }
            if (1 < uVar13) goto LAB_00103c5c;
            if (0x1f < uVar14) goto LAB_00104100;
            uVar19 = uVar14 + 1;
            cVar16 = *(char *)((long)local_158 + uVar14 + 0x28);
            uVar14 = uVar19;
          } while (iVar7 != (int)uVar19);
          if (cVar16 == ':') goto LAB_00103c5c;
        }
        uVar19 = param_3 - 1 & 0xffffffff;
        uVar14 = strnchr(&local_130,uVar19,0x3a);
        uVar19 = strnchr(&local_130,uVar19,0x2f);
        if (((uVar19 == 0) || (uVar14 == 0)) || (uVar19 <= uVar14)) {
          if ((char)local_130 == '.') {
            if (local_130._1_1_ != '\0') goto LAB_00103a94;
            puVar8 = &DAT_00104f95;
          }
          else {
            if (((char)local_130 != '/') || (local_130._1_1_ != '\0')) {
LAB_00103a94:
              lVar1 = lVar18 + 0x90;
              mutex_lock(lVar1);
              queue_work_on(0x20,*(undefined8 *)(lVar18 + 0x110),lVar18 + 0x120);
              wait_for_completion(lVar18 + 0xd0);
              lVar20 = *(long *)(lVar18 + 0x180);
              if (lVar20 == 0) {
                _printk(&DAT_00104deb,"new_utag",*(undefined8 *)(lVar18 + 0x80));
                mutex_unlock(lVar1);
                param_3 = 0xfffffffffffffff2;
                goto LAB_00104044;
              }
              if (*(int *)(lVar18 + 0x88) == 0) {
                lVar15 = *(long *)(lVar20 + 0x58);
                while ((lVar15 != 0 && (*(long *)(lVar15 + 0x58) != 0))) {
                  lVar17 = 0;
                  do {
                    if (lVar17 == 0x20) goto LAB_00103c28;
                    cVar16 = *(char *)((long)local_158 + lVar17 + 0x28);
                    cVar2 = *(char *)(lVar15 + lVar17);
                  } while (((cVar16 == cVar2) && (cVar16 != '\0')) &&
                          (lVar17 = lVar17 + 1, cVar2 != '\0'));
                  lVar15 = *(long *)(lVar15 + 0x58);
                  if (cVar16 == cVar2) goto LAB_00103c28;
                }
                puVar9 = (undefined1 *)strnchr(&local_130,0x20,0x3a);
                puVar21 = puVar9;
                if (puVar9 != (undefined1 *)0x0) {
                  puVar21 = puVar9 + 1;
                  *puVar9 = 0;
                }
                pcVar24 = (char *)&local_130;
                if ((char)local_130 == '/') {
                  pcVar24 = (char *)((ulong)pcVar24 | 1);
                  local_130 = local_130 & 0xffffffffffffff00;
                }
                local_158[0] = pcVar24;
                pcVar10 = (char *)strnchr(pcVar24,0x20,0x2f);
                if (pcVar10 == (char *)0x0) {
                  bVar25 = false;
                  uVar14 = 1;
                  bVar3 = false;
                  bVar5 = false;
                  bVar4 = false;
                }
                else {
                  pcVar24 = pcVar10;
                  if (*pcVar10 == '/') {
                    pcVar24 = pcVar10 + 1;
                    *pcVar10 = '\0';
                  }
                  local_158[1] = pcVar24;
                  pcVar11 = (char *)strnchr(pcVar24,0x20,0x2f);
                  if (pcVar11 == (char *)0x0) {
                    bVar5 = false;
                    bVar4 = false;
                    bVar25 = false;
                    uVar14 = 2;
                    bVar3 = true;
                  }
                  else {
                    pcVar24 = pcVar11;
                    if (*pcVar11 == '/') {
                      pcVar24 = pcVar11 + 1;
                      *pcVar11 = '\0';
                    }
                    local_158[2] = pcVar24;
                    pcVar11 = (char *)strnchr(pcVar24,0x20,0x2f);
                    if (pcVar11 == (char *)0x0) {
                      bVar3 = false;
                      bVar25 = false;
                      uVar14 = 3;
                      bVar5 = false;
                      bVar4 = true;
                    }
                    else {
                      pcVar24 = pcVar11;
                      if (*pcVar11 == '/') {
                        pcVar24 = pcVar11 + 1;
                        *pcVar11 = '\0';
                      }
                      local_158[3] = pcVar24;
                      pcVar11 = (char *)strnchr(pcVar24,0x20,0x2f);
                      if (pcVar11 == (char *)0x0) {
                        bVar3 = false;
                        bVar25 = false;
                        uVar14 = 4;
                        bVar5 = true;
                        bVar4 = false;
                      }
                      else {
                        pcVar24 = pcVar11;
                        if (*pcVar11 == '/') {
                          pcVar24 = pcVar11 + 1;
                          *pcVar11 = '\0';
                        }
                        local_138 = pcVar24;
                        pcVar11 = (char *)strnchr(pcVar24,0x20,0x2f);
                        if (pcVar11 != (char *)0x0) {
                          if (*pcVar11 == '/') {
                            *pcVar11 = '\0';
                          }
                          goto LAB_00104100;
                        }
                        bVar3 = false;
                        bVar25 = true;
                        bVar5 = false;
                        bVar4 = false;
                        uVar14 = 5;
                      }
                    }
                  }
                }
                pcVar11 = local_158[0];
                scnprintf(local_110,0x20,"%s%s%s",&DAT_00104cf9,&DAT_00104cf9,local_158[0]);
                if (((*(int *)(lVar18 + 0x8c) != 0) && (*pcVar11 != '.')) &&
                   (iVar7 = check_hwtag(local_110,*(undefined8 *)(lVar18 + 200)), iVar7 != 0)) {
                  param_3 = 0xffffffffffffffea;
                  goto LAB_00104024;
                }
                pcVar11 = local_158[1];
                if (pcVar10 != (char *)0x0) {
                  scnprintf(&local_f0,0x20,"%s%s%s",local_110,&DAT_0010506b,local_158[1]);
                  if (((*(int *)(lVar18 + 0x8c) != 0) && (*pcVar11 != '.')) &&
                     (iVar7 = check_hwtag(&local_f0,*(undefined8 *)(lVar18 + 200)), iVar7 != 0))
                  goto LAB_00103f3c;
                  pcVar11 = local_158[2];
                  if (bVar3) goto LAB_00103f14;
                  scnprintf(&local_d0,0x20,"%s%s%s",&local_f0,&DAT_0010506b,local_158[2]);
                  if (((*(int *)(lVar18 + 0x8c) != 0) && (*pcVar11 != '.')) &&
                     (iVar7 = check_hwtag(&local_d0,*(undefined8 *)(lVar18 + 200)), iVar7 != 0))
                  goto LAB_00103f3c;
                  pcVar11 = local_158[3];
                  if (!bVar4) {
                    scnprintf(&local_b0,0x20,"%s%s%s",&local_d0,&DAT_0010506b,local_158[3]);
                    if (((*(int *)(lVar18 + 0x8c) != 0) && (*pcVar11 != '.')) &&
                       (iVar7 = check_hwtag(&local_b0,*(undefined8 *)(lVar18 + 200)), iVar7 != 0))
                    goto LAB_00103f3c;
                    pcVar11 = local_138;
                    if (!bVar5) {
                      scnprintf(&local_90,0x20,"%s%s%s",&local_b0,&DAT_0010506b,local_138);
                      if (((*(int *)(lVar18 + 0x8c) != 0) && (*pcVar11 != '.')) &&
                         (iVar7 = check_hwtag(&local_90,*(undefined8 *)(lVar18 + 200)), iVar7 != 0))
                      goto LAB_00103f3c;
                      if (!bVar25) goto LAB_001040e8;
                    }
                  }
                }
LAB_00103f14:
                if ((((*(int *)(lVar18 + 0x8c) == 0) || (pcVar10 == (char *)0x0)) ||
                    (*pcVar24 != '.')) ||
                   (iVar7 = check_hwtag(pcVar24,*(undefined8 *)(lVar18 + 0xc0)), iVar7 == 0)) {
                  uVar19 = 0;
                  uVar22 = 0;
                  goto LAB_00103f70;
                }
LAB_00103f3c:
                param_3 = 0xffffffffffffffea;
                goto LAB_00104024;
              }
              _printk(&DAT_00104b91,"new_utag",&local_130,*(undefined8 *)(lVar18 + 0x80));
              param_3 = 0xfffffffffffffff3;
              goto LAB_00104024;
            }
            puVar8 = &DAT_00105175;
          }
          _printk(puVar8,"no_show_tag");
          _printk(&DAT_001052a6,"new_utag",*(undefined8 *)(lVar18 + 0x80),&local_130);
          param_3 = 0xfffffffffffffff2;
          goto LAB_00104044;
        }
        puVar8 = &DAT_00104f1e;
        pcVar24 = "check_path";
      }
      _printk(puVar8,pcVar24,&local_130);
      param_3 = 0xfffffffffffffff2;
      goto LAB_00104044;
    }
  }
  memset((void *)((long)local_158 + (param_3 - __n) + 0x28),0,__n);
  _printk(&DAT_00105407,"new_utag");
  param_3 = 0xfffffffffffffff2;
  goto LAB_00104044;
LAB_00103c28:
  _printk(&DAT_00104a50,"new_utag",&local_130);
  param_3 = 0xffffffffffffffea;
  goto LAB_00104024;
  while (uVar19 = uVar19 + 1, uVar19 != uVar14) {
LAB_00103f70:
    if (uVar19 == 6) {
LAB_001040e8:
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x1040ec);
      (*pcVar6)();
    }
    pcVar24 = local_110 + uVar19 * 0x20;
    iVar7 = add_utag_tail(lVar20,pcVar24,puVar21);
    if (iVar7 == -0x11) {
      plVar23 = (long *)(lVar18 + 0x60);
      do {
        plVar23 = (long *)*plVar23;
        if (plVar23 == (long *)(lVar18 + 0x60)) {
          plVar23 = (long *)0x0;
          break;
        }
        iVar7 = strncmp((char *)(plVar23 + 6),pcVar24,0x20);
      } while (iVar7 != 0);
      uVar22 = *(ulong *)((long)plVar23 + 0x50);
    }
    else {
      if (4 < uVar19) goto LAB_001040e8;
      if (0x27 < uVar19 * 8) goto LAB_00104100;
      uVar22 = proc_utag_dir(lVar18,local_158[uVar19],pcVar24,puVar21,1,uVar22);
      if (0xfffffffffffff000 < uVar22) break;
    }
  }
  queue_work_on(0x20,*(undefined8 *)(lVar18 + 0x118),lVar18 + 0x150);
  wait_for_completion(lVar18 + 0xf0);
  if (*(int *)(lVar18 + 0x188) != 0) {
    param_3 = (long)*(int *)(lVar18 + 0x188);
  }
LAB_00104024:
  do {
    lVar18 = *(long *)(lVar20 + 0x58);
    kfree(*(undefined8 *)(lVar20 + 0x50));
    kfree(lVar20);
    lVar20 = lVar18;
  } while (lVar18 != 0);
  mutex_unlock(lVar1);
LAB_00104044:
  lVar18 = sp_el0;
  if (*(long *)(lVar18 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// check_hwtag @ 00104134 size=384
// signature: undefined check_hwtag(void)
// callers: [new_utag]
//------------------------------------------------------------

void check_hwtag(char *param_1,long param_2)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  size_t sVar5;
  char *__dest;
  char *__string;
  size_t __n;
  char *local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  uVar4 = 0;
  if ((param_1 != (char *)0x0) && (param_2 != 0)) {
    iVar3 = *(int *)(param_2 + 0x40);
    if (iVar3 == 0) {
      _printk(&DAT_0010520b,"check_hwtag",param_1,param_2);
      uVar4 = 0;
    }
    else {
      sVar5 = strnlen(param_1,0x20);
      if (sVar5 == 0xffffffffffffffff) {
LAB_001042a4:
        uVar4 = fortify_panic("strnlen");
        goto LAB_001042b0;
      }
      __dest = (char *)__kmalloc(iVar3,0xdc0);
      local_50 = __dest;
      if (__dest == (char *)0x0) {
        uVar4 = 0xfffffff4;
      }
      else {
        memcpy(__dest,*(void **)(param_2 + 0x50),(ulong)*(uint *)(param_2 + 0x40));
        do {
          __string = strsep(&local_50,",");
          __n = strnlen(__string,0x20);
          if (__n == 0xffffffffffffffff) goto LAB_001042a4;
          if (__n < sVar5) {
            bVar2 = false;
          }
          else {
            iVar3 = strncmp(__string,param_1,__n);
            bVar2 = iVar3 == 0;
          }
        } while ((local_50 != (char *)0x0) && (!bVar2));
        kfree(__dest);
        if (bVar2) {
          uVar4 = 0;
        }
        else {
          _printk(&DAT_00104b62,"check_hwtag",param_1);
          uVar4 = 0xffffffea;
        }
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) == local_48) {
    return;
  }
LAB_001042b0:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar4);
}



//------------------------------------------------------------
// lock_open @ 001042b8 size=48
// signature: undefined lock_open(void)
// callers: []
//------------------------------------------------------------

void lock_open(long param_1,undefined8 param_2)

{
  single_open(param_2,lock_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// lock_show @ 001042ec size=80
// signature: undefined lock_show(void)
// callers: []
//------------------------------------------------------------

undefined8 lock_show(long param_1)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0x80) == 0) {
    _printk(&DAT_00104cc8,"lock_show");
    uVar1 = 0xfffffffb;
  }
  else {
    seq_printf(param_1,&DAT_00104b85,*(undefined4 *)(*(long *)(param_1 + 0x80) + 0x88));
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// delete_utag @ 00104340 size=1116
// signature: undefined delete_utag(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

size_t delete_utag(long param_1,ulong param_2,size_t param_3)

{
  long lVar1;
  char cVar2;
  code *pcVar3;
  size_t __n;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  undefined *puVar7;
  char *pcVar8;
  uint uVar9;
  undefined8 *puVar10;
  long lVar11;
  ulong uVar12;
  char cVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  long *plVar17;
  char cStack_79;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar15 = sp_el0;
  local_58 = *(long *)(lVar15 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (param_3 - 0x21 < 0xffffffffffffffdf || param_3 == 0) {
    _printk(&DAT_00104ef9,"delete_utag",param_3);
    param_3 = 0xfffffffffffffffb;
    goto LAB_00104654;
  }
  lVar15 = *(long *)(*(long *)(param_1 + 0x20) + 0x2b8);
  __check_object_size(&local_78,param_3,0);
  puVar10 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
     (uVar12 = param_2, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
    uVar12 = param_2 & (long)(param_2 << 8) >> 8;
  }
  __n = param_3;
  if (uVar12 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar12 = daif;
      if ((uVar12 & 0x80) == 0) {
        uVar4 = daif;
        daif = uVar4 | 0xc0;
      }
      puVar10 = (undefined8 *)puVar10[1];
      uVar4 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar10 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar10;
      InstructionSynchronizationBarrier();
      daif = uVar12;
    }
    __n = __arch_copy_from_user(puVar10,&local_78,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar12 = daif;
      if ((uVar12 & 0x80) == 0) {
        uVar4 = daif;
        daif = uVar4 | 0xc0;
      }
      uVar4 = ttbr1_el1;
      ttbr0_el1 = (uVar4 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar4 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar12;
    }
    if (__n == 0) {
      if (param_3 - 0x21 < 0xffffffffffffffe0) {
LAB_0010477c:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(1,0x104780);
        (*pcVar3)();
      }
      uVar12 = param_3 - 1;
      (&cStack_79)[param_3] = '\0';
      if ((char)local_78 == ':') {
LAB_0010468c:
        puVar7 = &DAT_00104b41;
        pcVar8 = "delete_utag";
      }
      else {
        if ((int)uVar12 != 0) {
          uVar9 = 0;
          uVar4 = 0;
          cVar13 = (char)local_78;
          do {
            if (cVar13 == ':') {
              uVar9 = uVar9 + 1;
            }
            if (1 < uVar9) goto LAB_0010468c;
            if (0x1f < uVar4) goto LAB_0010477c;
            uVar5 = uVar4 + 1;
            cVar13 = *(char *)((long)&local_78 + uVar4);
            uVar4 = uVar5;
          } while ((int)uVar12 != (int)uVar5);
          if (cVar13 == ':') goto LAB_0010468c;
        }
        uVar4 = strnchr(&local_78,uVar12 & 0xffffffff,0x3a);
        uVar5 = strnchr(&local_78,uVar12 & 0xffffffff,0x2f);
        if (((uVar5 == 0) || (uVar4 == 0)) || (uVar5 <= uVar4)) {
          lVar1 = lVar15 + 0x90;
          mutex_lock(lVar1);
          queue_work_on(0x20,*(undefined8 *)(lVar15 + 0x110),lVar15 + 0x120);
          wait_for_completion(lVar15 + 0xd0);
          lVar16 = *(long *)(lVar15 + 0x180);
          if (lVar16 == 0) {
            _printk(&DAT_00104deb,"delete_utag",*(undefined8 *)(lVar15 + 0x80));
            mutex_unlock(lVar1);
            param_3 = 0xffffffffffffffea;
          }
          else {
            if (*(int *)(lVar15 + 0x88) == 0) {
              lVar11 = *(long *)(lVar16 + 0x58);
              do {
                lVar6 = lVar11;
                if ((lVar6 == 0) || (lVar11 = *(long *)(lVar6 + 0x58), lVar11 == 0)) {
                  _printk(&DAT_00105198,"delete_utag",&local_78);
                  param_3 = 0xffffffffffffffea;
                  goto LAB_00104634;
                }
                lVar14 = 0;
                do {
                  if (lVar14 == 0x20) goto LAB_00104590;
                  cVar13 = *(char *)((long)&local_78 + lVar14);
                  cVar2 = *(char *)(lVar6 + lVar14);
                } while (((cVar13 == cVar2) && (cVar13 != '\0')) &&
                        (lVar14 = lVar14 + 1, cVar2 != '\0'));
              } while (cVar13 != cVar2);
LAB_00104590:
              *(long *)(*(long *)(lVar6 + 0x60) + 0x58) = lVar11;
              *(undefined8 *)(*(long *)(lVar6 + 0x58) + 0x60) = *(undefined8 *)(lVar6 + 0x60);
              kfree();
              lVar11 = *(long *)(lVar16 + 0x58);
              while (plVar17 = (long *)(lVar11 + 0x58), *plVar17 != 0) {
                lVar6 = strnstr(lVar11,&local_78,0x20);
                if ((lVar6 == lVar11) && (*(char *)(lVar11 + uVar12) == '/')) {
                  lVar6 = *plVar17;
                  *(long *)(*(long *)(lVar11 + 0x60) + 0x58) = lVar6;
                  *(undefined8 *)(*plVar17 + 0x60) = *(undefined8 *)(lVar11 + 0x60);
                  kfree(lVar11);
                  lVar11 = lVar6;
                }
                else {
                  lVar11 = *plVar17;
                }
              }
              queue_work_on(0x20,*(undefined8 *)(lVar15 + 0x118),lVar15 + 0x150);
              wait_for_completion(lVar15 + 0xf0);
              if (*(int *)(lVar15 + 0x188) != 0) {
                param_3 = (long)*(int *)(lVar15 + 0x188);
              }
              rebuild_utags_directory(lVar15);
            }
            else {
              _printk(&DAT_00104b91,"delete_utag",&local_78,*(undefined8 *)(lVar15 + 0x80));
              param_3 = 0xfffffffffffffff3;
            }
LAB_00104634:
            do {
              lVar15 = *(long *)(lVar16 + 0x58);
              kfree(*(undefined8 *)(lVar16 + 0x50));
              kfree(lVar16);
              lVar16 = lVar15;
            } while (lVar15 != 0);
            mutex_unlock(lVar1);
          }
          goto LAB_00104654;
        }
        puVar7 = &DAT_00104f1e;
        pcVar8 = "check_path";
      }
      _printk(puVar7,pcVar8,&local_78);
      param_3 = 0xffffffffffffffea;
      goto LAB_00104654;
    }
  }
  memset((void *)((long)&local_78 + (param_3 - __n)),0,__n);
  _printk(&DAT_00105407,"delete_utag");
  param_3 = 0xfffffffffffffff2;
LAB_00104654:
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// init_module @ 00104858 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&utags_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00104888 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&utags_driver);
  return;
}



//------------------------------------------------------------
// blkdev_get_by_path @ 00108000 size=1
// signature: undefined blkdev_get_by_path(void)
// callers: [load_work_func, store_work_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blkdev_get_by_path(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmalloc @ 00108008 size=1
// signature: undefined vmalloc(void)
// callers: [load_work_func, store_work_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00108010 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [load_work_func, write_utag, check_hwtag, add_utag_tail, rebuild_utags_directory]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00108018 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [proc_utag_dir, load_work_func, proc_utag_file, write_utag, store_work_func, check_hwtag, add_utag_tail]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vfree @ 00108020 size=1
// signature: undefined vfree(void)
// callers: [load_work_func, store_work_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00108030 size=1
// signature: undefined kmalloc_trace(void)
// callers: [proc_utag_dir, load_work_func, proc_utag_file, init_empty, add_utag_tail]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnchr @ 00108038 size=1
// signature: undefined strnchr(void)
// callers: [load_work_func, delete_utag, write_utag, new_utag, rebuild_utags_directory]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnchr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00108040 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [load_work_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00108048 size=1
// signature: undefined __kmalloc(void)
// callers: [load_work_func, write_utag, utag_get_bootarg, check_hwtag, utags_bootdevice_expand]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00108050 size=1
// signature: undefined kfree(void)
// callers: [proc_utag_dir, load_work_func, delete_utag, write_utag, new_utag, utags_remove, init_empty, read_utag, clear_utags_directory, check_hwtag, rebuild_utags_directory]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00108058 size=1
// signature: undefined _printk(void)
// callers: [proc_utag_dir, load_work_func, utags_probe, delete_utag, write_utag, new_utag, check_hwtag, reload_write, proc_utag_util, rebuild_utags_directory, lock_show, init_empty, read_utag, rw_bdev, store_work_func, utags_bootdevice_expand, reload_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00108060 size=1
// signature: undefined complete(void)
// callers: [load_work_func, store_work_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00108068 size=1
// signature: undefined fortify_panic(void)
// callers: [load_work_func, write_utag, check_hwtag, add_utag_tail, utags_bootdevice_expand, rebuild_utags_directory]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00108070 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [load_work_func, full_utag_name, utags_probe, delete_utag, write_utag, new_utag, read_utag, utag_get_bootarg, check_hwtag, add_utag_tail, utags_bootdevice_expand, rebuild_utags_directory]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncmp @ 00108078 size=1
// signature: int strncmp(char * __s1, char * __s2, size_t __n)
// callers: [proc_utag_dir, utags_probe, write_utag, new_utag, store_work_func, check_hwtag, add_utag_tail]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00108080 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [delete_utag, write_utag, new_utag, store_work_func, reload_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00108088 size=1
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
// platform_driver_unregister @ 00108090 size=1
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
// queue_work_on @ 00108098 size=1
// signature: undefined queue_work_on(void)
// callers: [delete_utag, write_utag, new_utag, init_empty, read_utag, rebuild_utags_directory]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion @ 001080a0 size=1
// signature: undefined wait_for_completion(void)
// callers: [delete_utag, write_utag, new_utag, init_empty, read_utag, rebuild_utags_directory]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 001080a8 size=1
// signature: undefined scnprintf(void)
// callers: [full_utag_name, utags_probe, new_utag, add_utag_tail, rebuild_utags_directory]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bio_alloc_bioset @ 001080b8 size=1
// signature: undefined bio_alloc_bioset(void)
// callers: [rw_bdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bio_alloc_bioset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// is_vmalloc_addr @ 001080c0 size=1
// signature: undefined is_vmalloc_addr(void)
// callers: [rw_bdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void is_vmalloc_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmalloc_to_page @ 001080c8 size=1
// signature: undefined vmalloc_to_page(void)
// callers: [rw_bdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmalloc_to_page(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bio_add_page @ 001080d0 size=1
// signature: undefined bio_add_page(void)
// callers: [rw_bdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bio_add_page(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// submit_bio_wait @ 001080d8 size=1
// signature: undefined submit_bio_wait(void)
// callers: [rw_bdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void submit_bio_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bio_put @ 001080e0 size=1
// signature: undefined bio_put(void)
// callers: [rw_bdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bio_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 001080e8 size=1
// signature: undefined devm_kmalloc(void)
// callers: [utags_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001080f0 size=1
// signature: undefined __mutex_init(void)
// callers: [utags_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 001080f8 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [utags_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00108100 size=1
// signature: undefined of_property_read_string(void)
// callers: [utags_probe, utag_get_bootarg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00108108 size=1
// signature: undefined alloc_workqueue(void)
// callers: [utags_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 00108110 size=1
// signature: undefined destroy_workqueue(void)
// callers: [utags_probe, utags_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_mkdir_data @ 00108118 size=1
// signature: undefined proc_mkdir_data(void)
// callers: [proc_utag_dir, utags_probe, proc_utag_util]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_mkdir_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_create_data @ 00108120 size=1
// signature: undefined proc_create_data(void)
// callers: [utags_probe, proc_utag_file, proc_utag_util]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_create_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// remove_proc_subtree @ 00108128 size=1
// signature: undefined remove_proc_subtree(void)
// callers: [utags_probe, utags_remove, clear_utags_directory]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void remove_proc_subtree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// filp_close @ 00108130 size=1
// signature: undefined filp_close(void)
// callers: [utags_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void filp_close(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blkdev_put @ 00108138 size=1
// signature: undefined blkdev_put(void)
// callers: [utags_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blkdev_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 00108140 size=1
// signature: undefined devm_kfree(void)
// callers: [utags_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00108148 size=1
// signature: size_t strlen(char * __s)
// callers: [proc_utag_dir, proc_utag_file, utag_get_bootarg, utags_bootdevice_expand]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncpy @ 00108150 size=1
// signature: char * strncpy(char * __dest, char * __src, size_t __n)
// callers: [utags_bootdevice_expand]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strncpy(char *__dest,char *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 00108158 size=1
// signature: undefined strnstr(void)
// callers: [delete_utag, utag_get_bootarg, utags_bootdevice_expand]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrdup @ 00108160 size=1
// signature: undefined kstrdup(void)
// callers: [utags_bootdevice_expand]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00108168 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [utags_bootdevice_expand]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_opts_by_path @ 00108170 size=1
// signature: undefined of_find_node_opts_by_path(void)
// callers: [utag_get_bootarg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_opts_by_path(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlcpy @ 00108178 size=1
// signature: undefined strlcpy(void)
// callers: [utag_get_bootarg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 00108180 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [write_utag, utag_get_bootarg, check_hwtag]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 00108188 size=1
// signature: undefined single_open(void)
// callers: [reload_open, lock_open, partition_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00108190 size=1
// signature: undefined mutex_lock(void)
// callers: [delete_utag, write_utag, new_utag, read_utag, reload_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 001081a8 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [delete_utag, write_utag, new_utag, reload_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001081b0 size=1
// signature: undefined mutex_unlock(void)
// callers: [delete_utag, write_utag, new_utag, read_utag, reload_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 001081c0 size=1
// signature: undefined seq_printf(void)
// callers: [lock_show, read_utag, reload_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001081c8 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [clear_utags_directory]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001081d0 size=1
// signature: undefined __list_add_valid(void)
// callers: [proc_utag_dir, proc_utag_file]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 001081d8 size=1
// signature: undefined __check_object_size(void)
// callers: [delete_utag, write_utag, new_utag]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlcat @ 001081e0 size=1
// signature: undefined strlcat(void)
// callers: [write_utag]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcat(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 001081e8 size=1
// signature: undefined seq_puts(void)
// callers: [read_utag]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



