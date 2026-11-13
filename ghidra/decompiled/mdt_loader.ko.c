// Decompiled by Ghidra 12.2
// Program: mdt_loader.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_mdt_get_size @ 0010020c size=252
// signature: undefined qcom_mdt_get_size(void)
// callers: []
//------------------------------------------------------------

long qcom_mdt_get_size(ulong *param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  int *piVar6;
  ulong uVar7;
  uint *puVar8;
  
  uVar5 = *param_1;
  if (((0x33 < uVar5) && (piVar6 = (int *)param_1[1], *piVar6 == 0x464c457f)) &&
     (*(short *)((long)piVar6 + 0x2a) == 0x20)) {
    uVar4 = (ulong)*(ushort *)(piVar6 + 0xb);
    if ((ulong)(uint)piVar6[7] + uVar4 * 0x20 <= uVar5) {
      if (*(short *)((long)piVar6 + 0x2e) == 0x28) {
        if ((ulong)(uint)piVar6[8] + (ulong)*(ushort *)(piVar6 + 0xc) * 0x28 <= uVar5)
        goto LAB_00100288;
      }
      else if ((*(short *)((long)piVar6 + 0x2e) == 0) && ((short)piVar6[0xc] == 0)) {
LAB_00100288:
        uVar5 = 0;
        if (*(ushort *)(piVar6 + 0xb) == 0) {
          uVar7 = 0xffffffffffffffff;
        }
        else {
          puVar8 = (uint *)(piVar6 + 0x13);
          uVar7 = 0xffffffffffffffff;
          do {
            if (((puVar8[-6] == 1) && ((*puVar8 & 0x7000000) != 0x2000000)) && (puVar8[-1] != 0)) {
              uVar2 = puVar8[-3];
              uVar1 = puVar8[-1] + uVar2;
              if (uVar2 <= uVar7) {
                uVar7 = (ulong)uVar2;
              }
              if (uVar5 < uVar1) {
                uVar5 = (ulong)(uVar1 + 0xfff & 0xfffff000);
              }
            }
            puVar8 = puVar8 + 8;
            uVar4 = uVar4 - 1;
          } while (uVar4 != 0);
        }
        lVar3 = uVar5 - uVar7;
        if (uVar5 < uVar7 || lVar3 == 0) {
          lVar3 = -0x16;
        }
        return lVar3;
      }
    }
  }
  return -0x16;
}



//------------------------------------------------------------
// qcom_mdt_read_metadata @ 0010030c size=788
// signature: undefined qcom_mdt_read_metadata(void)
// callers: [__qcom_mdt_load]
//------------------------------------------------------------

void * qcom_mdt_read_metadata
                 (long param_1,ulong *param_2,undefined8 param_3,long *param_4,ulong param_5,
                 undefined8 *param_6)

{
  int iVar1;
  ulong uVar2;
  char *__s;
  size_t sVar3;
  int *piVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  void *__dest;
  uint *puVar9;
  undefined8 local_70;
  long local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  uVar7 = *param_2;
  local_70 = 0;
  if (uVar7 < 0x34) {
    _dev_err(param_1,"Image is too small\n");
  }
  else {
    piVar4 = (int *)param_2[1];
    if ((*piVar4 == 0x464c457f) && (*(short *)((long)piVar4 + 0x2a) == 0x20)) {
      uVar6 = (ulong)*(ushort *)(piVar4 + 0xb);
      uVar8 = (ulong)(uint)piVar4[7];
      if (uVar8 + uVar6 * 0x20 <= uVar7) {
        if (*(short *)((long)piVar4 + 0x2e) == 0x28) {
          if (((ulong)(uint)piVar4[8] + (ulong)*(ushort *)(piVar4 + 0xc) * 0x28 <= uVar7) &&
             ((ulong)(uint)piVar4[8] + (ulong)*(ushort *)(piVar4 + 0xc) * 0x28 <= uVar7))
          goto LAB_00100438;
        }
        else if ((*(short *)((long)piVar4 + 0x2e) == 0) && ((short)piVar4[0xc] == 0)) {
LAB_00100438:
          __dest = (void *)0xffffffffffffffea;
          if ((((1 < *(ushort *)(piVar4 + 0xb)) && (uVar8 <= uVar7)) &&
              (uVar6 << 3 <= uVar7 - uVar8)) && (piVar4[0xd] != 1)) {
            puVar9 = (uint *)(piVar4 + 0x1b);
            uVar7 = 1;
            do {
              if ((puVar9[-6] != 1) && ((*puVar9 & 0x7000000) == 0x2000000)) {
                uVar8 = (ulong)(uint)piVar4[0x11];
                uVar6 = (ulong)puVar9[-2];
                if (param_6 == (undefined8 *)0x0) {
                  __dest = (void *)__kmalloc(uVar6 + uVar8,0xcc0);
LAB_001004dc:
                  lVar5 = 0;
                }
                else {
                  if ((param_5 & 1) != 0) {
                    __dest = (void *)dma_alloc_attrs(param_1,uVar6 + uVar8,param_6,0xcc0,0);
                    goto LAB_001004dc;
                  }
                  lVar5 = qcom_get_scm_device();
                  if (lVar5 == 0) {
                    __dest = (void *)0xfffffffffffffdfb;
                    break;
                  }
                  __dest = (void *)dma_alloc_attrs(lVar5,uVar6 + uVar8,param_6,0xcc0,0);
                }
                if (__dest == (void *)0x0) {
                  __dest = (void *)0xfffffffffffffff4;
                }
                else {
                  memcpy(__dest,(void *)param_2[1],uVar8);
                  uVar2 = qcom_mdt_bins_are_split(param_2);
                  if ((uVar2 & 1) == 0) {
                    memcpy((void *)((long)__dest + uVar8),(void *)(param_2[1] + (ulong)puVar9[-5]),
                           uVar6);
LAB_001005c4:
                    *param_4 = uVar6 + uVar8;
                  }
                  else {
                    __s = (char *)kstrdup(param_3,0xcc0);
                    if (__s == (char *)0x0) {
                      iVar1 = -0xc;
                    }
                    else {
                      sVar3 = strlen(__s);
                      snprintf(__s + (sVar3 - 3),4,"b%02d",(int)uVar7);
                      iVar1 = request_firmware_into_buf
                                        (&local_70,__s,param_1,(long)__dest + uVar8,uVar6);
                      kfree(__s);
                      if (iVar1 == 0) {
                        release_firmware(local_70);
                        goto LAB_001005c4;
                      }
                    }
                    if (param_6 == (undefined8 *)0x0) {
                      kfree(__dest);
                    }
                    else {
                      if ((param_5 & 1) != 0) {
                        lVar5 = param_1;
                      }
                      dma_free_attrs(lVar5,uVar6 + uVar8,__dest,*param_6,0);
                    }
                    __dest = (void *)(long)iVar1;
                  }
                }
                break;
              }
              uVar7 = uVar7 + 1;
              puVar9 = puVar9 + 8;
            } while (uVar6 != uVar7);
          }
          goto LAB_001003fc;
        }
      }
    }
  }
  __dest = (void *)0xffffffffffffffea;
LAB_001003fc:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return __dest;
}



//------------------------------------------------------------
// qcom_mdt_bins_are_split @ 00100620 size=120
// signature: undefined qcom_mdt_bins_are_split(void)
// callers: [qcom_mdt_read_metadata]
//------------------------------------------------------------

bool qcom_mdt_bins_are_split(ulong *param_1)

{
  bool bVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  int *piVar5;
  ulong uVar6;
  
  uVar4 = param_1[1];
  uVar2 = (ulong)*(ushort *)(uVar4 + 0x2c);
  if (uVar2 == 0) {
    return false;
  }
  uVar3 = *param_1;
  uVar6 = (ulong)*(uint *)(uVar4 + 0x38);
  if (uVar3 < uVar6) {
    return true;
  }
  piVar5 = (int *)(uVar4 + 0x44);
  uVar4 = 1;
  bVar1 = true;
  while( true ) {
    if (uVar3 < (uint)(*piVar5 + (int)uVar6)) {
      return bVar1;
    }
    bVar1 = uVar4 < uVar2;
    if (uVar2 == uVar4) break;
    uVar6 = (ulong)(uint)piVar5[5];
    piVar5 = piVar5 + 8;
    uVar4 = uVar4 + 1;
    if (uVar3 < uVar6) {
      return bVar1;
    }
  }
  return bVar1;
}



//------------------------------------------------------------
// qcom_mdt_load @ 0010069c size=52
// signature: undefined qcom_mdt_load(void)
// callers: []
//------------------------------------------------------------

void qcom_mdt_load(void)

{
  __qcom_mdt_load();
  return;
}



//------------------------------------------------------------
// __qcom_mdt_load @ 001006d0 size=1420
// signature: undefined __qcom_mdt_load(void)
// callers: [qcom_mdt_load_no_init, qcom_mdt_load_no_free, qcom_mdt_load]
//------------------------------------------------------------

int __qcom_mdt_load(long param_1,ulong *param_2,char *param_3,undefined4 param_4,long param_5,
                   ulong param_6,ulong param_7,ulong *param_8,byte param_9,byte param_10,
                   ulong *param_11)

{
  uint uVar1;
  void *__dest;
  uint uVar2;
  long lVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  size_t sVar7;
  long lVar8;
  char *pcVar9;
  ulong uVar10;
  ulong uVar11;
  uint uVar12;
  ulong uVar13;
  int *piVar14;
  uint *puVar15;
  ulong uVar16;
  int *piVar17;
  ulong local_b0;
  ulong local_80;
  ulong local_78;
  ulong *local_70;
  long local_68;
  
  lVar8 = sp_el0;
  iVar6 = -0x16;
  local_68 = *(long *)(lVar8 + 0x638);
  local_78 = 0;
  local_70 = (ulong *)0x0;
  local_80 = 0;
  if (((((param_2 == (ulong *)0x0) || (param_5 == 0)) || (param_6 == 0)) ||
      ((param_7 == 0 || (uVar10 = *param_2, uVar10 < 0x34)))) ||
     ((piVar17 = (int *)param_2[1], *piVar17 != 0x464c457f ||
      (*(short *)((long)piVar17 + 0x2a) != 0x20)))) goto LAB_00100b3c;
  uVar13 = (ulong)*(ushort *)(piVar17 + 0xb);
  if (uVar10 < (ulong)(uint)piVar17[7] + uVar13 * 0x20) goto LAB_00100b3c;
  if (*(short *)((long)piVar17 + 0x2e) == 0x28) {
    if (uVar10 < (ulong)(uint)piVar17[8] + (ulong)*(ushort *)(piVar17 + 0xc) * 0x28)
    goto LAB_00100b3c;
  }
  else if ((*(short *)((long)piVar17 + 0x2e) != 0) || ((short)piVar17[0xc] != 0)) goto LAB_00100b3c;
  if (*(ushort *)(piVar17 + 0xb) == 0) {
    bVar4 = false;
  }
  else if ((uVar10 < (uint)piVar17[0xe]) || (uVar10 < (uint)(piVar17[0x11] + piVar17[0xe]))) {
    bVar4 = true;
  }
  else {
    piVar14 = piVar17 + 0x19;
    uVar11 = 1;
    do {
      uVar16 = uVar11;
      if ((uVar13 == uVar16) || (puVar15 = (uint *)(piVar14 + -3), uVar10 < *puVar15)) break;
      iVar6 = *piVar14;
      piVar14 = piVar14 + 8;
      uVar11 = uVar16 + 1;
    } while (iVar6 + *puVar15 <= uVar10);
    bVar4 = uVar16 < uVar13;
  }
  sVar7 = strlen(param_3);
  if (sVar7 < 5) {
    iVar6 = -0x16;
    goto LAB_00100b3c;
  }
  lVar8 = kstrdup(param_3,0xcc0);
  if (lVar8 == 0) {
    iVar6 = -0xc;
    goto LAB_00100b3c;
  }
  if ((param_9 & 1) == 0) {
    local_b0 = 0;
LAB_001008cc:
    uVar10 = (ulong)*(ushort *)(piVar17 + 0xb);
    if (uVar10 == 0) {
      iVar6 = 0;
      uVar13 = param_6;
    }
    else {
      uVar11 = 0;
      uVar12 = 0;
      puVar15 = (uint *)(piVar17 + 0x13);
      uVar13 = 0xffffffffffffffff;
      do {
        if (((puVar15[-6] == 1) && ((*puVar15 & 0x7000000) != 0x2000000)) && (puVar15[-1] != 0)) {
          uVar2 = puVar15[-3];
          uVar12 = uVar12 | (*puVar15 & 0x8000000) >> 0x1b;
          uVar1 = puVar15[-1] + uVar2;
          if (uVar2 <= uVar13) {
            uVar13 = (ulong)uVar2;
          }
          if (uVar11 < uVar1) {
            uVar11 = (ulong)(uVar1 + 0xfff & 0xfffff000);
          }
        }
        puVar15 = puVar15 + 8;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
      bVar5 = false;
      if (uVar12 == 0) {
        uVar13 = param_6;
      }
      else if ((param_9 & 1) != 0) {
        iVar6 = qcom_scm_pas_mem_setup(param_4,param_6,uVar11 - uVar13);
        if (iVar6 != 0) {
          pcVar9 = "unable to setup relocation\n";
          goto LAB_00100bb8;
        }
        bVar5 = (short)piVar17[0xb] == 0;
      }
      if (!bVar5) {
        uVar10 = 0;
        puVar15 = (uint *)(piVar17 + 0x13);
        do {
          if ((puVar15[-6] == 1) && ((*puVar15 & 0x7000000) != 0x2000000)) {
            uVar12 = puVar15[-1];
            if (uVar12 != 0) {
              lVar3 = puVar15[-3] - uVar13;
              if ((lVar3 < 0) || (param_7 < lVar3 + (ulong)uVar12)) {
                _dev_err(param_1,"segment outside memory range\n");
              }
              else {
                uVar1 = puVar15[-2];
                if (uVar1 <= uVar12) {
                  __dest = (void *)(param_5 + lVar3);
                  if (uVar1 != 0) {
                    if (bVar4) {
                      snprintf((char *)(lVar8 + sVar7 + -3),4,"b%02d",(int)uVar10);
                      iVar6 = request_firmware_into_buf(&local_70,lVar8,param_1,__dest,puVar15[-2]);
                      if (iVar6 != 0) {
                        _dev_err(param_1,"failed to load %s\n",lVar8);
                        goto joined_r0x00100c50;
                      }
                      if (*local_70 != (ulong)puVar15[-2]) {
                        _dev_err(param_1,"failed to load segment %d from truncated file %s\n",
                                 uVar10 & 0xffffffff,lVar8);
                        release_firmware(local_70);
                        iVar6 = -0x16;
                        goto joined_r0x00100c50;
                      }
                      release_firmware();
                    }
                    else {
                      memcpy(__dest,(void *)(param_2[1] + (ulong)puVar15[-5]),(ulong)uVar1);
                    }
                  }
                  uVar12 = puVar15[-1] - puVar15[-2];
                  if (puVar15[-2] <= puVar15[-1] && uVar12 != 0) {
                    memset((void *)((long)__dest + (ulong)puVar15[-2]),0,(ulong)uVar12);
                  }
                  goto LAB_00100a0c;
                }
                _dev_err(param_1,"refusing to load segment %d with p_filesz > p_memsz\n",
                         uVar10 & 0xffffffff);
              }
              iVar6 = -0x16;
              goto joined_r0x00100c50;
            }
          }
LAB_00100a0c:
          uVar10 = uVar10 + 1;
          puVar15 = puVar15 + 8;
        } while (uVar10 < *(ushort *)(piVar17 + 0xb));
      }
      iVar6 = 0;
    }
joined_r0x00100c50:
    if (param_8 != (ulong *)0x0) {
      *param_8 = uVar13;
    }
    if (iVar6 != 0) {
LAB_001009a4:
      qcom_scm_pas_shutdown(param_4);
    }
    if (((param_11 == (ulong *)0x0) && ((param_9 & 1) != 0)) &&
       (((param_10 & 1) != 0 || (param_1 = qcom_get_scm_device(), param_1 != 0)))) {
      dma_free_attrs(param_1,local_80,local_b0,local_78,0);
    }
  }
  else {
    local_b0 = qcom_mdt_read_metadata(param_1,param_2,param_3,&local_80,param_10 & 1,&local_78);
    if (local_b0 < 0xfffffffffffff001) {
      if (param_11 != (ulong *)0x0) {
        param_11[2] = local_80;
        *param_11 = local_b0;
        param_11[1] = local_78;
      }
      iVar6 = qcom_scm_pas_init_image(param_4,local_78);
      if (iVar6 == 0) goto LAB_001008cc;
      pcVar9 = "invalid firmware metadata\n";
LAB_00100bb8:
      _dev_err(param_1,pcVar9);
      goto LAB_001009a4;
    }
    _dev_err(param_1,"error %d reading firmware %s metadata\n",local_b0 & 0xffffffff,lVar8);
    iVar6 = (int)local_b0;
  }
  kfree(lVar8);
LAB_00100b3c:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// qcom_mdt_load_no_init @ 00100c60 size=48
// signature: undefined qcom_mdt_load_no_init(void)
// callers: []
//------------------------------------------------------------

void qcom_mdt_load_no_init(void)

{
  __qcom_mdt_load();
  return;
}



//------------------------------------------------------------
// qcom_mdt_load_no_free @ 00100c94 size=60
// signature: undefined qcom_mdt_load_no_free(void)
// callers: []
//------------------------------------------------------------

void qcom_mdt_load_no_free(void)

{
  __qcom_mdt_load();
  return;
}



//------------------------------------------------------------
// qcom_mdt_free_metadata @ 00100cd4 size=156
// signature: undefined qcom_mdt_free_metadata(void)
// callers: []
//------------------------------------------------------------

void qcom_mdt_free_metadata
               (long param_1,undefined4 param_2,undefined8 *param_3,ulong param_4,int param_5)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if ((param_5 != 0) && (iVar1 = qcom_scm_pas_shutdown_retry(param_2), iVar1 != 0)) {
                    /* WARNING: Subroutine does not return */
    panic("Panicking, failed to shutdown peripheral %d\n",param_2);
  }
  if (param_3 != (undefined8 *)0x0) {
    if ((param_4 & 1) == 0) {
      param_1 = qcom_get_scm_device();
      if (param_1 == 0) {
        _printk(&DAT_00100eaf,"qcom_mdt_free_metadata");
        return;
      }
      uVar3 = param_3[1];
      uVar2 = param_3[2];
    }
    else {
      uVar3 = param_3[1];
      uVar2 = param_3[2];
    }
    dma_free_attrs(param_1,uVar2,*param_3,uVar3,0);
  }
  return;
}



//------------------------------------------------------------
// _dev_err @ 00102000 size=1
// signature: undefined _dev_err(void)
// callers: [__qcom_mdt_load, qcom_mdt_read_metadata]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 00102008 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [qcom_mdt_read_metadata]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00102010 size=1
// signature: undefined __kmalloc(void)
// callers: [qcom_mdt_read_metadata]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_get_scm_device @ 00102018 size=1
// signature: undefined qcom_get_scm_device(void)
// callers: [qcom_mdt_free_metadata, __qcom_mdt_load, qcom_mdt_read_metadata]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_get_scm_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00102020 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [__qcom_mdt_load, qcom_mdt_read_metadata]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrdup @ 00102028 size=1
// signature: undefined kstrdup(void)
// callers: [__qcom_mdt_load, qcom_mdt_read_metadata]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00102030 size=1
// signature: size_t strlen(char * __s)
// callers: [__qcom_mdt_load, qcom_mdt_read_metadata]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00102038 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [__qcom_mdt_load, qcom_mdt_read_metadata]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_firmware_into_buf @ 00102040 size=1
// signature: undefined request_firmware_into_buf(void)
// callers: [__qcom_mdt_load, qcom_mdt_read_metadata]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_firmware_into_buf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102048 size=1
// signature: undefined kfree(void)
// callers: [__qcom_mdt_load, qcom_mdt_read_metadata]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// release_firmware @ 00102050 size=1
// signature: undefined release_firmware(void)
// callers: [__qcom_mdt_load, qcom_mdt_read_metadata]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void release_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 00102058 size=1
// signature: undefined dma_free_attrs(void)
// callers: [qcom_mdt_free_metadata, __qcom_mdt_load, qcom_mdt_read_metadata]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102060 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [__qcom_mdt_load, qcom_mdt_read_metadata]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_pas_init_image @ 00102068 size=1
// signature: undefined qcom_scm_pas_init_image(void)
// callers: [__qcom_mdt_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_pas_init_image(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_pas_mem_setup @ 00102070 size=1
// signature: undefined qcom_scm_pas_mem_setup(void)
// callers: [__qcom_mdt_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_pas_mem_setup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_pas_shutdown @ 00102078 size=1
// signature: undefined qcom_scm_pas_shutdown(void)
// callers: [__qcom_mdt_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_pas_shutdown(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00102080 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [__qcom_mdt_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_pas_shutdown_retry @ 00102088 size=1
// signature: undefined qcom_scm_pas_shutdown_retry(void)
// callers: [qcom_mdt_free_metadata]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_pas_shutdown_retry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102090 size=1
// signature: undefined _printk(void)
// callers: [qcom_mdt_free_metadata]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panic @ 00102098 size=1
// signature: noreturn undefined panic(void)
// callers: [qcom_mdt_free_metadata]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



