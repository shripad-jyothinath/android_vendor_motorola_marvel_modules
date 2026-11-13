// Decompiled by Ghidra 12.2
// Program: qcrypto-msm_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// qcrypto_get_num_engines @ 001019fc size=36
// signature: undefined qcrypto_get_num_engines(void)
// callers: []
//------------------------------------------------------------

int qcrypto_get_num_engines(void)

{
  int iVar1;
  undefined8 *puVar2;
  
  iVar1 = -1;
  puVar2 = &DAT_0010c998;
  do {
    puVar2 = (undefined8 *)*puVar2;
    iVar1 = iVar1 + 1;
  } while (puVar2 != &DAT_0010c998);
  return iVar1;
}



//------------------------------------------------------------
// qcrypto_get_engine_list @ 00101a24 size=68
// signature: undefined qcrypto_get_engine_list(void)
// callers: []
//------------------------------------------------------------

void qcrypto_get_engine_list(ulong param_1,long param_2)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  
  if (param_1 < 2) {
    param_1 = 1;
  }
  puVar1 = (undefined4 *)(param_2 + 4);
  puVar2 = &DAT_0010c998;
  do {
    puVar2 = (undefined8 *)*puVar2;
    if (puVar2 == &DAT_0010c998) {
      return;
    }
    param_1 = param_1 - 1;
    *puVar1 = *(undefined4 *)((long)puVar2 + 100);
    puVar1[-1] = *(undefined4 *)(puVar2 + 0xd);
    puVar1 = puVar1 + 3;
  } while (param_1 != 0);
  return;
}



//------------------------------------------------------------
// qcrypto_cipher_set_device @ 00101a6c size=164
// signature: undefined qcrypto_cipher_set_device(void)
// callers: []
//------------------------------------------------------------

undefined8 qcrypto_cipher_set_device(long param_1,int param_2)

{
  long lVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  
  lVar4 = *(long *)(param_1 + 0x40);
  lVar5 = *(long *)(lVar4 + 0x58);
  lVar1 = lVar5 + 0x34;
  uVar3 = _raw_spin_lock_irqsave(lVar1);
  plVar2 = (long *)(lVar5 + 0x80);
  plVar6 = plVar2;
  do {
    plVar6 = (long *)*plVar6;
    if (plVar6 == plVar2) {
      plVar6 = plVar2;
      break;
    }
  } while (*(int *)((long)plVar6 + 100) != param_2);
  _raw_spin_unlock_irqrestore(lVar1,uVar3);
  if ((plVar6 == (long *)0x0) || (*(int *)((long)plVar6 + 100) != param_2)) {
    _printk(&DAT_0010e7af,param_2);
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = 0;
    *(long **)(lVar4 + 0x50) = plVar6;
  }
  return uVar3;
}



//------------------------------------------------------------
// qcrypto_cipher_set_device_hw @ 00101b14 size=196
// signature: undefined qcrypto_cipher_set_device_hw(void)
// callers: []
//------------------------------------------------------------

undefined8 qcrypto_cipher_set_device_hw(long param_1,int param_2,int param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  long lVar4;
  long lVar5;
  undefined8 *puVar6;
  
  lVar4 = *(long *)(param_1 + 0x40);
  lVar5 = *(long *)(lVar4 + 0x58);
  lVar1 = lVar5 + 0x34;
  uVar2 = _raw_spin_lock_irqsave(lVar1);
  puVar6 = (undefined8 *)(lVar5 + 0x80);
  puVar3 = (undefined8 *)*puVar6;
  do {
    if (puVar3 == puVar6) {
LAB_00101b7c:
      _raw_spin_unlock_irqrestore(lVar1,uVar2);
      if (((puVar6 == (undefined8 *)0x0) || (*(int *)((long)puVar6 + 100) != param_2)) ||
         (*(int *)(puVar6 + 0xd) != param_3)) {
        _printk(&DAT_0010e7af,param_2);
        uVar2 = 0xffffffed;
      }
      else {
        uVar2 = 0;
        *(undefined8 **)(lVar4 + 0x50) = puVar6;
      }
      return uVar2;
    }
    if ((*(int *)((long)puVar3 + 100) == param_2) && (*(int *)(puVar3 + 0xd) == param_3)) {
      puVar6 = puVar3;
      goto LAB_00101b7c;
    }
    puVar3 = (undefined8 *)*puVar3;
  } while( true );
}



//------------------------------------------------------------
// qcrypto_aead_set_device @ 00101bdc size=164
// signature: undefined qcrypto_aead_set_device(void)
// callers: []
//------------------------------------------------------------

undefined8 qcrypto_aead_set_device(long param_1,int param_2)

{
  long lVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  
  lVar4 = *(long *)(param_1 + 0x20);
  lVar5 = *(long *)(lVar4 + 0x58);
  lVar1 = lVar5 + 0x34;
  uVar3 = _raw_spin_lock_irqsave(lVar1);
  plVar2 = (long *)(lVar5 + 0x80);
  plVar6 = plVar2;
  do {
    plVar6 = (long *)*plVar6;
    if (plVar6 == plVar2) {
      plVar6 = plVar2;
      break;
    }
  } while (*(int *)((long)plVar6 + 100) != param_2);
  _raw_spin_unlock_irqrestore(lVar1,uVar3);
  if ((plVar6 == (long *)0x0) || (*(int *)((long)plVar6 + 100) != param_2)) {
    _printk(&DAT_0010e7af,param_2);
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = 0;
    *(long **)(lVar4 + 0x50) = plVar6;
  }
  return uVar3;
}



//------------------------------------------------------------
// qcrypto_ahash_set_device @ 00101c84 size=164
// signature: undefined qcrypto_ahash_set_device(void)
// callers: []
//------------------------------------------------------------

undefined8 qcrypto_ahash_set_device(long param_1,int param_2)

{
  long lVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  
  lVar4 = *(long *)(param_1 + 0x20);
  lVar5 = *(long *)(lVar4 + 0x58);
  lVar1 = lVar5 + 0x34;
  uVar3 = _raw_spin_lock_irqsave(lVar1);
  plVar2 = (long *)(lVar5 + 0x80);
  plVar6 = plVar2;
  do {
    plVar6 = (long *)*plVar6;
    if (plVar6 == plVar2) {
      plVar6 = plVar2;
      break;
    }
  } while (*(int *)((long)plVar6 + 100) != param_2);
  _raw_spin_unlock_irqrestore(lVar1,uVar3);
  if ((plVar6 == (long *)0x0) || (*(int *)((long)plVar6 + 100) != param_2)) {
    _printk(&DAT_0010e7af,param_2);
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = 0;
    *(long **)(lVar4 + 0x50) = plVar6;
  }
  return uVar3;
}



//------------------------------------------------------------
// qcrypto_cipher_set_flag @ 00101d2c size=112
// signature: undefined qcrypto_cipher_set_flag(void)
// callers: []
//------------------------------------------------------------

undefined8 qcrypto_cipher_set_flag(long param_1,uint param_2)

{
  undefined *puVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x40);
  if (((param_2 & 1) == 0) || (*(int *)(*(long *)(lVar2 + 0x58) + 8) != 0)) {
    param_2 = *(uint *)(lVar2 + 0x60) | param_2;
    if (((param_2 ^ 0xffffffff) & 0xff) != 0) {
      *(uint *)(lVar2 + 0x60) = param_2;
      return 0;
    }
    puVar1 = &DAT_0010eb01;
  }
  else {
    puVar1 = &DAT_0010eb40;
  }
  _printk(puVar1,"qcrypto_cipher_set_flag");
  return 0xffffffea;
}



//------------------------------------------------------------
// qcrypto_aead_set_flag @ 00101da0 size=112
// signature: undefined qcrypto_aead_set_flag(void)
// callers: []
//------------------------------------------------------------

undefined8 qcrypto_aead_set_flag(long param_1,uint param_2)

{
  undefined *puVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20);
  if (((param_2 & 1) == 0) || (*(int *)(*(long *)(lVar2 + 0x58) + 8) != 0)) {
    param_2 = *(uint *)(lVar2 + 0x60) | param_2;
    if (((param_2 ^ 0xffffffff) & 0xff) != 0) {
      *(uint *)(lVar2 + 0x60) = param_2;
      return 0;
    }
    puVar1 = &DAT_0010eb01;
  }
  else {
    puVar1 = &DAT_0010eb40;
  }
  _printk(puVar1,"qcrypto_aead_set_flag");
  return 0xffffffea;
}



//------------------------------------------------------------
// qcrypto_ahash_set_flag @ 00101e14 size=112
// signature: undefined qcrypto_ahash_set_flag(void)
// callers: []
//------------------------------------------------------------

undefined8 qcrypto_ahash_set_flag(long param_1,uint param_2)

{
  undefined *puVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20);
  if (((param_2 & 1) == 0) || (*(int *)(*(long *)(lVar2 + 0x58) + 8) != 0)) {
    param_2 = *(uint *)(lVar2 + 0x60) | param_2;
    if (((param_2 ^ 0xffffffff) & 0xff) != 0) {
      *(uint *)(lVar2 + 0x60) = param_2;
      return 0;
    }
    puVar1 = &DAT_0010eb01;
  }
  else {
    puVar1 = &DAT_0010eb40;
  }
  _printk(puVar1,"qcrypto_ahash_set_flag");
  return 0xffffffea;
}



//------------------------------------------------------------
// qcrypto_cipher_clear_flag @ 00101e88 size=24
// signature: undefined qcrypto_cipher_clear_flag(void)
// callers: []
//------------------------------------------------------------

undefined8 qcrypto_cipher_clear_flag(long param_1,uint param_2)

{
  *(uint *)(*(long *)(param_1 + 0x40) + 0x60) =
       *(uint *)(*(long *)(param_1 + 0x40) + 0x60) & (param_2 ^ 0xffffffff);
  return 0;
}



//------------------------------------------------------------
// qcrypto_aead_clear_flag @ 00101ea4 size=24
// signature: undefined qcrypto_aead_clear_flag(void)
// callers: []
//------------------------------------------------------------

undefined8 qcrypto_aead_clear_flag(long param_1,uint param_2)

{
  *(uint *)(*(long *)(param_1 + 0x20) + 0x60) =
       *(uint *)(*(long *)(param_1 + 0x20) + 0x60) & (param_2 ^ 0xffffffff);
  return 0;
}



//------------------------------------------------------------
// qcrypto_ahash_clear_flag @ 00101ec0 size=24
// signature: undefined qcrypto_ahash_clear_flag(void)
// callers: []
//------------------------------------------------------------

undefined8 qcrypto_ahash_clear_flag(long param_1,uint param_2)

{
  *(uint *)(*(long *)(param_1 + 0x20) + 0x60) =
       *(uint *)(*(long *)(param_1 + 0x20) + 0x60) & (param_2 ^ 0xffffffff);
  return 0;
}



//------------------------------------------------------------
// seq_response @ 00101edc size=676
// signature: undefined seq_response(void)
// callers: []
//------------------------------------------------------------

void seq_response(long param_1)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  long *plVar8;
  int *piVar9;
  code *pcVar10;
  long *plVar11;
  int iVar12;
  int iVar13;
  long lVar14;
  long *plVar15;
  undefined8 *puVar16;
  long *plVar17;
  
  piVar1 = (int *)(param_1 + 0x34);
  lVar14 = param_1 + -0xd4;
  plVar17 = (long *)(param_1 + -0x88);
  piVar2 = (int *)(param_1 + 0x30);
  puVar16 = (undefined8 *)(param_1 + -0x18);
  lVar5 = sp_el0;
LAB_00101f28:
  Hint_Prefetch(puVar16,2,0,1);
  do {
    plVar8 = (long *)*puVar16;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(puVar16,0x10);
    if (bVar4) {
      *puVar16 = 0;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  DataMemoryBarrier(2,3);
  if (plVar8 != (long *)0x0) {
    plVar11 = (long *)0x0;
    do {
      plVar15 = plVar8;
      plVar8 = (long *)*plVar15;
      *plVar15 = (long)plVar11;
      plVar11 = plVar15;
    } while (plVar8 != (long *)0x0);
    while (plVar15 != (long *)0x0) {
      plVar8 = (long *)*plVar15;
      lVar6 = plVar15[1];
      *(int *)(lVar5 + 0x10) = *(int *)(lVar5 + 0x10) + 0x200;
      pcVar10 = *(code **)(lVar6 + 0x10);
      if (*(int *)(pcVar10 + -4) != -0x223f6f35) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x8229,0x101f98);
        (*pcVar10)();
      }
      (*pcVar10)(lVar6,*(undefined4 *)(plVar15 + 2));
      local_bh_enable();
      piVar9 = (int *)(param_1 + -0x10);
      Hint_Prefetch(piVar9,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar9,0x10);
        if (bVar4) {
          *piVar9 = *piVar9 + -1;
          cVar3 = ExclusiveMonitorsStatus();
        }
        plVar15 = plVar8;
      } while (cVar3 != '\0');
    }
    if (*(int *)(param_1 + -0x10) < 200) {
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar13 = *piVar1;
        if (iVar13 != 0) goto LAB_001021c4;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar4) {
          *piVar1 = 1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      DataMemoryBarrier(2,3);
LAB_001021c4:
      if (iVar13 == 0) {
        *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
        iVar13 = *(int *)(param_1 + -0x78);
        if (0 < *(int *)(param_1 + -0x78)) {
          while( true ) {
            uVar7 = _raw_spin_lock_irqsave(lVar14);
            plVar8 = *(long **)(param_1 + -0x88);
            if (plVar8 == plVar17) break;
            if ((*(long **)(param_1 + 0x48) == (long *)0x0) ||
               (plVar11 = (long *)**(long **)(param_1 + 0x48), plVar11 == plVar17)) {
              plVar11 = plVar8;
            }
            iVar12 = *(int *)(param_1 + -0x78) + 1;
            plVar15 = plVar11;
LAB_00102068:
            iVar12 = iVar12 + -1;
            if (iVar12 < 1) goto LAB_001020d0;
            if ((*(char *)((long)plVar15 + 300) != '\0') ||
               (*(uint *)((long)plVar15 + 0x11c) <= *(uint *)(plVar15 + 0x25))) goto LAB_0010208c;
            *(long **)(param_1 + 0x48) = plVar15;
            _raw_spin_unlock_irqrestore(lVar14,uVar7);
            if ((plVar15 == (long *)0x0) ||
               (_start_qcrypto_process(param_1 + -0x108,plVar15), bVar4 = iVar13 < 2,
               iVar13 = iVar13 + -1, bVar4)) goto LAB_00102128;
          }
          _printk(&DAT_0010dfab,"_avail_eng");
LAB_001020d4:
          _raw_spin_unlock_irqrestore(lVar14,uVar7);
        }
      }
    }
  }
LAB_00102128:
  do {
    Hint_Prefetch(piVar2,2,0,1);
    do {
      iVar13 = *piVar2;
      if (iVar13 != 2) goto LAB_00102148;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar2,0x10);
      if (bVar4) {
        *piVar2 = 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
LAB_00102148:
    if (iVar13 == 2) goto LAB_00101f28;
    Hint_Prefetch(piVar2,2,0,1);
    do {
      iVar13 = *piVar2;
      if (iVar13 != 1) goto LAB_00102174;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar2,0x10);
      if (bVar4) {
        *piVar2 = 0;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
LAB_00102174:
    if (iVar13 != 2) {
      return;
    }
  } while( true );
LAB_0010208c:
  if ((plVar15 == (long *)0x0) || (plVar15 = (long *)*plVar15, plVar15 == plVar17)) {
    plVar15 = plVar8;
  }
  if (plVar11 == plVar15) {
LAB_001020d0:
    *(undefined8 *)(param_1 + 0x48) = 0;
    goto LAB_001020d4;
  }
  goto LAB_00102068;
}



//------------------------------------------------------------
// _debug_stats_read @ 001021f4 size=2580
// signature: undefined _debug_stats_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long _debug_stats_read(long param_1,undefined8 param_2,ulong param_3,undefined8 param_4)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  undefined8 *puVar7;
  
  uVar2 = scnprintf(_debug_read_buf,0xfff,"\nQTI crypto accelerator %d Statistics\n",
                    **(int **)(param_1 + 0xd8) + 1);
  if (uVar2 < 0x1001) {
    iVar3 = scnprintf(_debug_read_buf + uVar2,(long)(int)(0xfff - uVar2),
                      "   SK CIPHER AES encryption          : %llu\n",DAT_0010db68);
    uVar2 = iVar3 + uVar2;
    if (uVar2 < 0x1001) {
      iVar3 = scnprintf(_debug_read_buf + uVar2,(long)(int)(0xfff - uVar2),
                        "   SK CIPHER AES decryption          : %llu\n",DAT_0010db70);
      uVar2 = iVar3 + uVar2;
      if (uVar2 < 0x1001) {
        iVar3 = scnprintf(_debug_read_buf + uVar2,(long)(int)(0xfff - uVar2),
                          "   SK CIPHER DES encryption          : %llu\n",DAT_0010db78);
        uVar2 = iVar3 + uVar2;
        if (uVar2 < 0x1001) {
          iVar3 = scnprintf(_debug_read_buf + uVar2,(long)(int)(0xfff - uVar2),
                            "   SK CIPHER DES decryption          : %llu\n",DAT_0010db80);
          uVar2 = iVar3 + uVar2;
          if (uVar2 < 0x1001) {
            iVar3 = scnprintf(_debug_read_buf + uVar2,(long)(int)(0xfff - uVar2),
                              "   SK CIPHER 3DES encryption         : %llu\n",DAT_0010db88);
            uVar2 = iVar3 + uVar2;
            if (uVar2 < 0x1001) {
              iVar3 = scnprintf(_debug_read_buf + uVar2,(long)(int)(0xfff - uVar2),
                                "   SK CIPHER 3DES decryption         : %llu\n",DAT_0010db90);
              uVar2 = iVar3 + uVar2;
              if (uVar2 < 0x1001) {
                iVar3 = scnprintf(_debug_read_buf + uVar2,(long)(int)(0xfff - uVar2),
                                  "   SK CIPHER operation success       : %llu\n",DAT_0010db98);
                uVar2 = iVar3 + uVar2;
                if (uVar2 < 0x1001) {
                  iVar3 = scnprintf(_debug_read_buf + uVar2,(long)(int)(0xfff - uVar2),
                                    "   SK CIPHER operation fail          : %llu\n",DAT_0010dba0);
                  uVar2 = iVar3 + uVar2;
                  if (uVar2 < 0x1001) {
                    iVar3 = scnprintf(_debug_read_buf + uVar2,(long)(int)(0xfff - uVar2),
                                      &DAT_0010e909);
                    uVar2 = iVar3 + uVar2;
                    if (uVar2 < 0x1001) {
                      iVar3 = scnprintf(_debug_read_buf + uVar2,(long)(int)(0xfff - uVar2),
                                        "   AEAD SHA1-AES encryption            : %llu\n",
                                        _qcrypto_stat);
                      uVar2 = iVar3 + uVar2;
                      if (uVar2 < 0x1001) {
                        iVar3 = scnprintf(_debug_read_buf + uVar2,(long)(int)(0xfff - uVar2),
                                          "   AEAD SHA1-AES decryption            : %llu\n",
                                          DAT_0010dad8);
                        uVar2 = iVar3 + uVar2;
                        if (uVar2 < 0x1001) {
                          iVar3 = scnprintf(_debug_read_buf + uVar2,(long)(int)(0xfff - uVar2),
                                            "   AEAD SHA1-DES encryption            : %llu\n",
                                            DAT_0010dae0);
                          uVar2 = iVar3 + uVar2;
                          if (uVar2 < 0x1001) {
                            iVar3 = scnprintf(_debug_read_buf + uVar2,(long)(int)(0xfff - uVar2),
                                              "   AEAD SHA1-DES decryption            : %llu\n",
                                              DAT_0010dae8);
                            uVar2 = iVar3 + uVar2;
                            if (uVar2 < 0x1001) {
                              iVar3 = scnprintf(_debug_read_buf + uVar2,(long)(int)(0xfff - uVar2),
                                                "   AEAD SHA1-3DES encryption           : %llu\n",
                                                DAT_0010daf0);
                              uVar2 = iVar3 + uVar2;
                              if (uVar2 < 0x1001) {
                                iVar3 = scnprintf(_debug_read_buf + uVar2,(long)(int)(0xfff - uVar2)
                                                  ,"   AEAD SHA1-3DES decryption           : %llu\n"
                                                  ,DAT_0010daf8);
                                uVar2 = iVar3 + uVar2;
                                if (uVar2 < 0x1001) {
                                  iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                    (long)(int)(0xfff - uVar2),
                                                                                                        
                                                  "   AEAD SHA256-AES encryption          : %llu\n",
                                                  DAT_0010db00);
                                  uVar2 = iVar3 + uVar2;
                                  if (uVar2 < 0x1001) {
                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                      (long)(int)(0xfff - uVar2),
                                                                                                            
                                                  "   AEAD SHA256-AES decryption          : %llu\n",
                                                  DAT_0010db08);
                                    uVar2 = iVar3 + uVar2;
                                    if (uVar2 < 0x1001) {
                                      iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                        (long)(int)(0xfff - uVar2),
                                                                                                                
                                                  "   AEAD SHA256-DES encryption          : %llu\n",
                                                  DAT_0010db10);
                                      uVar2 = iVar3 + uVar2;
                                      if (uVar2 < 0x1001) {
                                        iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                          (long)(int)(0xfff - uVar2),
                                                                                                                    
                                                  "   AEAD SHA256-DES decryption          : %llu\n",
                                                  DAT_0010db18);
                                        uVar2 = iVar3 + uVar2;
                                        if (uVar2 < 0x1001) {
                                          iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                            (long)(int)(0xfff - uVar2),
                                                                                                                        
                                                  "   AEAD SHA256-3DES encryption         : %llu\n",
                                                  DAT_0010db20);
                                          uVar2 = iVar3 + uVar2;
                                          if (uVar2 < 0x1001) {
                                            iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                              (long)(int)(0xfff - uVar2),
                                                                                                                            
                                                  "   AEAD SHA256-3DES decryption         : %llu\n",
                                                  DAT_0010db28);
                                            uVar2 = iVar3 + uVar2;
                                            if (uVar2 < 0x1001) {
                                              iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                (long)(int)(0xfff - uVar2),
                                                                                                                                
                                                  "   AEAD CCM-AES encryption             : %llu\n",
                                                  DAT_0010db30);
                                              uVar2 = iVar3 + uVar2;
                                              if (uVar2 < 0x1001) {
                                                iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                  (long)(int)(0xfff - uVar2),
                                                                                                                                    
                                                  "   AEAD CCM-AES decryption             : %llu\n",
                                                  DAT_0010db38);
                                                uVar2 = iVar3 + uVar2;
                                                if (uVar2 < 0x1001) {
                                                  iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                    (long)(int)(0xfff - uVar2),
                                                                                                                                        
                                                  "   AEAD RFC4309-CCM-AES encryption     : %llu\n",
                                                  DAT_0010db40);
                                                  uVar2 = iVar3 + uVar2;
                                                  if (uVar2 < 0x1001) {
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "   AEAD RFC4309-CCM-AES decryption     : %llu\n",
                                                  DAT_0010db48);
                                                  uVar2 = iVar3 + uVar2;
                                                  if (uVar2 < 0x1001) {
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "   AEAD operation success              : %llu\n",
                                                  DAT_0010db50);
                                                  uVar2 = iVar3 + uVar2;
                                                  if (uVar2 < 0x1001) {
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "   AEAD operation fail                 : %llu\n",
                                                  DAT_0010db58);
                                                  uVar2 = iVar3 + uVar2;
                                                  if (uVar2 < 0x1001) {
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "   AEAD bad message                    : %llu\n",
                                                  DAT_0010db60);
                                                  uVar2 = iVar3 + uVar2;
                                                  if (uVar2 < 0x1001) {
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                      &DAT_0010e909);
                                                    uVar2 = iVar3 + uVar2;
                                                    if (uVar2 < 0x1001) {
                                                      iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                        (long)(int)(0xfff - uVar2),
                                                                                                                                                
                                                  "   AHASH SHA1 digest                   : %llu\n",
                                                  DAT_0010dba8);
                                                  uVar2 = iVar3 + uVar2;
                                                  if (uVar2 < 0x1001) {
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "   AHASH SHA256 digest                 : %llu\n",
                                                  DAT_0010dbb0);
                                                  uVar2 = iVar3 + uVar2;
                                                  if (uVar2 < 0x1001) {
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "   AHASH SHA1 HMAC digest              : %llu\n",
                                                  DAT_0010dbb8);
                                                  uVar2 = iVar3 + uVar2;
                                                  if (uVar2 < 0x1001) {
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "   AHASH SHA256 HMAC digest            : %llu\n",
                                                  DAT_0010dbc0);
                                                  uVar2 = iVar3 + uVar2;
                                                  if (uVar2 < 0x1001) {
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "   AHASH operation success             : %llu\n",
                                                  DAT_0010dbc8);
                                                  uVar2 = iVar3 + uVar2;
                                                  if (uVar2 < 0x1001) {
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "   AHASH operation fail                : %llu\n",
                                                  DAT_0010dbd0);
                                                  uVar2 = iVar3 + uVar2;
                                                  if (uVar2 < 0x1001) {
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "   resp start, resp stop, max rsp queue reorder-cnt : %u %u %u %u\n"
                                                  ,DAT_0010ca78,_DAT_0010ca74,_DAT_0010ca8c,
                                                  DAT_0010ca90);
                                                  uVar2 = iVar3 + uVar2;
                                                  if (uVar2 < 0x1001) {
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "   max queue length, no avail          : %u %u\n"
                                                  ,DAT_0010ca7c,DAT_0010ca70);
                                                  uVar2 = iVar3 + uVar2;
                                                  if (uVar2 < 0x1001) {
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "   work queue                          : %u %u %u\n"
                                                  ,DAT_0010ca80,DAT_0010ca84,DAT_0010ca88);
                                                  uVar2 = iVar3 + uVar2;
                                                  if (uVar2 < 0x1001) {
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                      &DAT_0010e909);
                                                    uVar2 = iVar3 + uVar2;
                                                    uVar4 = _raw_spin_lock_irqsave(&DAT_0010c94c);
                                                    puVar7 = DAT_0010c998;
                                                    if ((undefined8 **)DAT_0010c998 != &DAT_0010c998
                                                       ) {
                                                      do {
                                                        if (0x1000 < uVar2) goto LAB_00102c04;
                                                        iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                          (long)(int)(0xfff - uVar2)
                                                                          ,
                                                  "   Engine %4d Req max %d          : %llu\n",
                                                  *(undefined4 *)(puVar7 + 0xc),
                                                  *(undefined4 *)((long)puVar7 + 0x134),puVar7[10]);
                                                  uVar2 = iVar3 + uVar2;
                                                  if (0x1000 < uVar2) goto LAB_00102c04;
                                                  iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                    (long)(int)(0xfff - uVar2),
                                                                                                                                        
                                                  "   Engine %4d Req Error               : %llu\n",
                                                  *(undefined4 *)(puVar7 + 0xc),puVar7[0xb]);
                                                  uVar2 = iVar3 + uVar2;
                                                  qce_get_driver_stats(puVar7[2]);
                                                  puVar7 = (undefined8 *)*puVar7;
                                                  } while ((undefined8 **)puVar7 != &DAT_0010c998);
                                                  }
                                                  _raw_spin_unlock_irqrestore(&DAT_0010c94c,uVar4);
                                                  if (DAT_0010ca94 != 0) {
                                                    if (0x1000 < uVar2) goto LAB_00102c04;
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "CPU %d Issue Req                     : %d\n",0);
                                                  uVar2 = iVar3 + uVar2;
                                                  }
                                                  if (DAT_0010ca98 != 0) {
                                                    if (0x1000 < uVar2) goto LAB_00102c04;
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "CPU %d Issue Req                     : %d\n",1);
                                                  uVar2 = iVar3 + uVar2;
                                                  }
                                                  if (DAT_0010ca9c != 0) {
                                                    if (0x1000 < uVar2) goto LAB_00102c04;
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "CPU %d Issue Req                     : %d\n",2);
                                                  uVar2 = iVar3 + uVar2;
                                                  }
                                                  if (DAT_0010caa0 != 0) {
                                                    if (0x1000 < uVar2) goto LAB_00102c04;
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "CPU %d Issue Req                     : %d\n",3);
                                                  uVar2 = iVar3 + uVar2;
                                                  }
                                                  if (DAT_0010caa4 != 0) {
                                                    if (0x1000 < uVar2) goto LAB_00102c04;
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "CPU %d Issue Req                     : %d\n",4);
                                                  uVar2 = iVar3 + uVar2;
                                                  }
                                                  if (DAT_0010caa8 != 0) {
                                                    if (0x1000 < uVar2) goto LAB_00102c04;
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "CPU %d Issue Req                     : %d\n",5);
                                                  uVar2 = iVar3 + uVar2;
                                                  }
                                                  if (DAT_0010caac != 0) {
                                                    if (0x1000 < uVar2) goto LAB_00102c04;
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "CPU %d Issue Req                     : %d\n",6);
                                                  uVar2 = iVar3 + uVar2;
                                                  }
                                                  if (DAT_0010cab0 != 0) {
                                                    if (0x1000 < uVar2) goto LAB_00102c04;
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "CPU %d Issue Req                     : %d\n",7);
                                                  uVar2 = iVar3 + uVar2;
                                                  }
                                                  if (DAT_0010cab4 != 0) {
                                                    if (0x1000 < uVar2) goto LAB_00102c04;
                                                    iVar3 = scnprintf(_debug_read_buf + uVar2,
                                                                      (long)(int)(0xfff - uVar2),
                                                                                                                                            
                                                  "CPU %d Issue Req                     : %d\n",8);
                                                  uVar2 = iVar3 + uVar2;
                                                  }
                                                  uVar6 = (ulong)(int)uVar2;
                                                  if (param_3 < uVar6) {
                                                    lVar5 = -0x16;
                                                  }
                                                  else {
                                                    iVar3 = simple_read_from_buffer
                                                                      (param_2,uVar6,param_4,
                                                                       _debug_read_buf,uVar6);
                                                    lVar5 = (long)iVar3;
                                                  }
                                                  return lVar5;
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
            }
          }
        }
      }
    }
  }
LAB_00102c04:
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x102c08);
  (*pcVar1)();
}



//------------------------------------------------------------
// _debug_stats_write @ 00102c0c size=232
// signature: undefined _debug_stats_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _debug_stats_write(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  memset(&_qcrypto_stat,0,0x108);
  uVar1 = _raw_spin_lock_irqsave(&DAT_0010c94c);
  puVar2 = DAT_0010c998;
  if ((undefined8 **)DAT_0010c998 != &DAT_0010c998) {
    do {
      puVar2[10] = 0;
      puVar2[0xb] = 0;
      qce_clear_driver_stats(puVar2[2]);
      *(undefined4 *)((long)puVar2 + 0x134) = 0;
      puVar2 = (undefined8 *)*puVar2;
    } while ((undefined8 **)puVar2 != &DAT_0010c998);
  }
  _DAT_0010cab0 = 0;
  _DAT_0010caa8 = 0;
  _DAT_0010caa0 = 0;
  _DAT_0010ca98 = 0;
  _DAT_0010ca90 = 0;
  _DAT_0010ca88 = 0;
  _DAT_0010ca80 = 0;
  _DAT_0010ca78 = 0;
  _DAT_0010ca70 = 0;
  _raw_spin_unlock_irqrestore(&DAT_0010c94c,uVar1);
  return param_3;
}



//------------------------------------------------------------
// local_bh_enable @ 00102cf4 size=40
// signature: undefined local_bh_enable(void)
// callers: [seq_response]
//------------------------------------------------------------

void local_bh_enable(void)

{
  __local_bh_enable_ip(local_bh_enable,0x200);
  return;
}



//------------------------------------------------------------
// _start_qcrypto_process @ 00102d1c size=2764
// signature: undefined _start_qcrypto_process(void)
// callers: [seq_response, qcrypto_bw_allocate_work, _qcrypto_queue_req, req_done, qcrypto_bw_reaper_work]
//------------------------------------------------------------

void _start_qcrypto_process(long param_1,long param_2)

{
  long lVar1;
  int *piVar2;
  char *pcVar3;
  long lVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  char cVar9;
  char cVar10;
  bool bVar11;
  code *pcVar12;
  int iVar13;
  undefined8 uVar14;
  long lVar15;
  undefined2 *puVar16;
  long lVar17;
  uint uVar18;
  undefined2 uVar19;
  uint uVar20;
  uint uVar21;
  uint *puVar22;
  ulong uVar23;
  long *plVar24;
  size_t __n;
  ulong uVar25;
  long lVar26;
  long lVar27;
  int iVar28;
  long lVar29;
  long lVar30;
  long local_140;
  code *local_120;
  code *local_118;
  uint *local_110;
  undefined8 local_108;
  undefined8 local_100;
  long local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  ulong local_e0;
  long local_d8;
  undefined8 local_d0;
  ulong *local_c8;
  long local_c0;
  ulong local_b8;
  byte *local_b0;
  ulong local_a8;
  ulong local_a0;
  undefined8 uStack_98;
  ulong local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  lVar1 = sp_el0;
  local_70 = *(long *)(lVar1 + 0x638);
  if (*(int *)(param_1 + 0x13c) != 0) {
    lVar1 = sp_el0;
    if ((*(uint *)(lVar1 + 0x10) & 0xffff00) == 0) {
      uVar23 = 8;
    }
    else {
      lVar1 = tpidr_el1;
      uVar20 = *(uint *)(&cpu_number + lVar1);
      if (6 < uVar20) {
        uVar20 = 7;
      }
      uVar23 = (ulong)uVar20;
    }
    lVar1 = param_1 + 0x34;
    uVar14 = _raw_spin_lock_irqsave(lVar1);
    if (*(char *)(param_2 + 300) == '\0') {
      piVar2 = (int *)(param_1 + uVar23 * 4 + 0x17c);
      local_140 = 0;
      do {
        if (*(uint *)(param_2 + 0x11c) <= *(uint *)(param_2 + 0x128)) break;
        lVar27 = 0;
        if (*(long *)(param_2 + 0x40) != param_2 + 0x30) {
          lVar27 = *(long *)(param_2 + 0x40);
        }
        if (*(int *)(param_2 + 0x70) != 1) break;
        lVar15 = crypto_dequeue_request(param_2 + 0x30);
        if (lVar15 == 0) {
          local_140 = 0;
          if (*(long *)(param_1 + 0xe0) != param_1 + 0xd0) {
            local_140 = *(long *)(param_1 + 0xe0);
          }
          lVar15 = crypto_dequeue_request();
          if (lVar15 == 0) break;
        }
        if (*(int *)(param_2 + 0x11c) == 0) {
LAB_001037ec:
          _printk(&DAT_0010e1e9);
          break;
        }
        uVar20 = 0;
        lVar30 = *(long *)(param_2 + 0x120);
        while( true ) {
          pcVar3 = (char *)(lVar30 + 4);
          Hint_Prefetch(pcVar3,2,0,1);
          do {
            cVar9 = *pcVar3;
            cVar10 = '\x01';
            bVar11 = (bool)ExclusiveMonitorPass(pcVar3,0x10);
            if (bVar11) {
              *pcVar3 = '\x01';
              cVar10 = ExclusiveMonitorsStatus();
            }
          } while (cVar10 != '\0');
          DataMemoryBarrier(2,3);
          if (cVar9 == '\0') break;
          lVar30 = lVar30 + 0x28;
          uVar20 = uVar20 + 1;
          if (*(uint *)(param_2 + 0x11c) <= uVar20) goto LAB_001037ec;
        }
        puVar22 = (uint *)(param_2 + 0x128);
        Hint_Prefetch(puVar22,2,0,1);
        do {
          uVar20 = *puVar22 + 1;
          cVar9 = '\x01';
          bVar11 = (bool)ExclusiveMonitorPass(puVar22,0x10);
          if (bVar11) {
            *puVar22 = uVar20;
            cVar9 = ExclusiveMonitorsStatus();
          }
        } while (cVar9 != '\0');
        DataMemoryBarrier(2,3);
        if (*(uint *)(param_2 + 0x134) < uVar20) {
          *(uint *)(param_2 + 0x134) = uVar20;
        }
        if (lVar30 == 0) goto LAB_001037ec;
        lVar26 = *(long *)(lVar15 + 0x20);
        lVar4 = lVar26 + 0x40;
        uVar20 = *(uint *)(*(long *)(lVar26 + 0x10) + 0x20) & 0xf;
        if (uVar20 == 5) {
          plVar24 = *(long **)(lVar26 + 0x48);
          lVar29 = lVar15 + 0x60;
          uVar23 = __list_add_valid(lVar29,plVar24,lVar4);
          if ((uVar23 & 1) != 0) {
            *(long *)(lVar26 + 0x48) = lVar29;
            *(long *)(lVar15 + 0x60) = lVar4;
            *(long **)(lVar15 + 0x68) = plVar24;
            goto LAB_00102f74;
          }
        }
        else {
          plVar24 = *(long **)(lVar26 + 0x48);
          lVar29 = lVar15 + 0x80;
          uVar23 = __list_add_valid(lVar29,plVar24,lVar4);
          if ((uVar23 & 1) != 0) {
            *(long *)(lVar26 + 0x48) = lVar29;
            *(long *)(lVar15 + 0x80) = lVar4;
            *(long **)(lVar15 + 0x88) = plVar24;
LAB_00102f74:
            *plVar24 = lVar29;
          }
        }
        *(long *)(lVar29 + 0x18) = lVar15;
        *(undefined4 *)(lVar29 + 0x20) = 0xffffff8d;
        plVar24 = (long *)(lVar30 + 0x10);
        *plVar24 = lVar15;
        *(long *)(lVar30 + 8) = param_2;
        *(long *)(lVar30 + 0x18) = lVar29;
        *(undefined1 *)(param_2 + 0x118) = 1;
        *(undefined1 *)(param_2 + 300) = 1;
        *(int *)(param_2 + 0x110) = *(int *)(param_2 + 0x110) + 1;
        *piVar2 = *piVar2 + 1;
        DataMemoryBarrier(2,3);
        _raw_spin_unlock_irqrestore(lVar1,uVar14);
        if (lVar27 != 0) {
          if (*(int *)(*(code **)(lVar27 + 0x10) + -4) != -0x223f6f35) {
                    /* WARNING: Does not return */
            pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x103000);
            (*pcVar12)();
          }
          (**(code **)(lVar27 + 0x10))(lVar27,0xffffff8d);
        }
        if (local_140 != 0) {
          if (*(int *)(*(code **)(local_140 + 0x10) + -4) != -0x223f6f35) {
                    /* WARNING: Does not return */
            pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x103030);
            (*pcVar12)();
          }
          (**(code **)(local_140 + 0x10))(local_140,0xffffff8d);
        }
        if (uVar20 == 3) {
          local_d0 = 0;
          local_c8 = (ulong *)0x0;
          local_80 = 0;
          uStack_78 = 0;
          uStack_88 = 0;
          local_a0 = 0;
          uStack_98 = 0;
          local_e0 = 0;
          local_d8 = 0;
          local_e8 = 0;
          puVar22 = (uint *)*plVar24;
          local_120 = (code *)0x2;
          lVar27 = *(long *)(puVar22 + 8);
          *(long *)(puVar22 + 0x2a) = param_2;
          local_118 = _qce_aead_complete;
          local_108 = *(undefined8 *)(puVar22 + 0x40);
          local_c0 = lVar27 + 0xb8;
          local_b0 = *(byte **)(puVar22 + 0x2c);
          local_f8 = lVar27 + 0x68;
          local_b8 = (ulong)*(uint *)(lVar27 + 0xf8);
          iVar13 = *(int *)(lVar27 + -0x40);
          local_100 = CONCAT44(*(undefined4 *)(lVar27 + 100),puVar22[0x42]);
          local_f0 = CONCAT44(iVar13,*(undefined4 *)(lVar27 + 0x100));
          local_110 = puVar22;
          if (puVar22[0x42] == 4) {
            iVar6 = 0;
            if (puVar22[0x41] != 0) {
              iVar6 = iVar13;
            }
            local_a8 = 0x10;
            local_90 = (ulong)*(uint *)(lVar27 + 0x60);
            uVar21 = puVar22[0xd];
            local_a0 = (ulong)(uVar21 - iVar6);
            local_e0 = *(ulong *)(local_b0 + 8);
            bVar8 = *local_b0;
            local_e8._0_1_ = (byte)*(undefined8 *)local_b0;
            uVar7 = puVar22[0xc];
            if (puVar22[0x34] != 0) {
              uVar7 = puVar22[0xc] - 8;
            }
            uVar23 = (ulong)uVar7;
            local_e8._0_1_ = (byte)local_e8 | ((byte)iVar13 & 0xfe) * '\x04' - 8;
            if (uVar7 != 0) {
              local_e8._0_1_ = (byte)local_e8 | 0x40;
            }
            local_e8._1_7_ = (undefined7)((ulong)*(undefined8 *)local_b0 >> 8);
            if (0xf < bVar8) {
LAB_00103468:
              iVar13 = -0x16;
              goto LAB_001036bc;
            }
            __n = (ulong)bVar8 + 1;
            memset((void *)((long)&local_d8 - __n),0,__n);
            if (bVar8 < 3) {
              if ((uint)(1 << (ulong)(((uint)__n & 3) << 3)) < uVar21 - iVar6) {
                iVar13 = -0x4b;
                goto LAB_001036bc;
              }
            }
            else {
              __n = 4;
            }
            memcpy((void *)((long)&local_d8 - __n),(void *)((long)&local_120 - __n),__n);
            if (uVar7 == 0) {
              local_d0 = local_d0 & 0xffffffff00000000;
              puVar22[0x3e] = 0;
              puVar22[0x3f] = 0;
            }
            else {
              puVar16 = (undefined2 *)__kmalloc(uVar7 + 100,0xb20);
              *(undefined2 **)(puVar22 + 0x3e) = puVar16;
              if (puVar16 == (undefined2 *)0x0) {
                iVar13 = -0xc;
                goto LAB_001036bc;
              }
              lVar27 = *(long *)(puVar22 + 0x10);
              uVar21 = (uVar7 & 0xff00ff00) >> 8 | (uVar7 & 0xff00ff) << 8;
              if (uVar7 >> 8 < 0xff) {
                uVar19 = (undefined2)uVar21;
                uVar18 = 2;
              }
              else {
                uVar18 = 6;
                uVar19 = 0xfeff;
                *(uint *)(puVar16 + 1) = uVar21 >> 0x10 | uVar21 << 0x10;
              }
              uVar21 = 0;
              *puVar16 = uVar19;
              local_d0 = CONCAT44(local_d0._4_4_,uVar7 + uVar18 + 0xf) & 0xfffffffffffffff0;
              if ((0 < (int)uVar7) && (lVar27 != 0)) {
                lVar15 = (long)puVar16 + (ulong)uVar18;
                iVar13 = 1;
                lVar26 = lVar27;
                uVar25 = uVar23;
                iVar6 = 1;
                do {
                  iVar28 = iVar6;
                  uVar21 = (int)uVar25 - *(int *)(lVar26 + 0xc);
                  uVar25 = (ulong)uVar21;
                  lVar26 = sg_next();
                  iVar13 = iVar13 + -1;
                  if ((int)uVar21 < 1) break;
                  iVar6 = iVar28 + 1;
                } while (lVar26 != 0);
                if (iVar13 == 1) {
                  uVar21 = 0;
                }
                else {
                  lVar26 = 0;
                  do {
                    lVar17 = sg_copy_to_buffer(lVar27,1,lVar15,uVar23);
                    lVar15 = lVar15 + lVar17;
                    uVar23 = uVar23 - lVar17;
                    lVar26 = lVar17 + lVar26;
                    uVar21 = (uint)lVar26;
                    lVar27 = sg_next(lVar27);
                    iVar28 = iVar28 + -1;
                  } while (iVar28 != 0);
                }
              }
              if (uVar21 != uVar7) {
                _printk(&DAT_0010de03,uVar21);
              }
            }
            local_c8 = (ulong *)(puVar22 + 0x36);
            lVar27 = *(long *)(puVar22 + 0x3e);
            if (lVar27 == 0) {
              uVar23 = *local_c8;
            }
            else {
              uVar23 = (((lVar27 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 - 0x200000000;
              puVar22[0x38] = (uint)lVar27 & 0xfff;
              puVar22[0x39] = (uint)local_d0;
            }
            *local_c8 = uVar23 & 0xfffffffffffffffc | 2;
          }
          else {
            local_a8 = (ulong)*(uint *)(*(long *)(lVar27 + 0x10) + -0x10);
            local_90 = (ulong)*(uint *)(lVar27 + 0x60);
          }
          iVar13 = qce_aead_req(*(undefined8 *)(param_2 + 0x10),&local_120);
          goto LAB_001036bc;
        }
        if (uVar20 != 0xf) {
          if (uVar20 == 5) {
            local_b0 = (byte *)0x0;
            local_a8 = 0;
            local_c0 = 0;
            local_b8 = 0;
            local_d0 = 0;
            local_c8 = (ulong *)0x0;
            local_80 = 0;
            uStack_78 = 0;
            local_90 = 0;
            uStack_88 = 0;
            local_a0 = 0;
            uStack_98 = 0;
            local_e0 = 0;
            local_d8 = 0;
            local_f0 = 0;
            local_e8 = 0;
            local_100 = 0;
            local_f8 = 0;
            local_110 = (uint *)0x0;
            local_108 = 0;
            local_120 = (code *)0x0;
            local_118 = (code *)0x0;
            lVar27 = *plVar24;
            *(long *)(lVar27 + 0x88) = param_2;
            puVar22 = (uint *)(lVar27 + -0x20);
            lVar15 = *(long *)(lVar27 + 0x20);
            if (*(char *)(*(long *)(param_2 + 0x20) + 0x19) != '\0') {
              *(undefined8 *)(lVar27 + 0xf0) = *(undefined8 *)(lVar27 + -0x10);
              *(undefined8 *)(lVar27 + 0xf8) = *(undefined8 *)(lVar27 + -8);
              lVar26 = __kmalloc(*(int *)(lVar27 + -0x20) + 0x40,0xb20);
              *(long *)(lVar27 + 0x140) = lVar26;
              if (lVar26 == 0) {
                iVar13 = -0xc;
                goto LAB_001036bc;
              }
              lVar26 = *(long *)(lVar27 + -0x10);
              uVar7 = *(uint *)(lVar27 + -0x20);
              uVar23 = (ulong)uVar7;
              if ((lVar26 == 0) || ((int)uVar7 < 1)) {
joined_r0x001033a0:
                uVar21 = 0;
                uVar25 = 0;
                if (uVar7 != 0) {
LAB_00103554:
                  _printk(&DAT_0010de03,uVar25 & 0xffffffff,uVar23);
                  uVar21 = *puVar22;
                }
              }
              else {
                iVar13 = 1;
                iVar6 = 1;
                do {
                  iVar28 = iVar6;
                  uVar7 = (int)uVar23 - *(int *)(lVar26 + 0xc);
                  uVar23 = (ulong)uVar7;
                  lVar26 = sg_next();
                  iVar13 = iVar13 + -1;
                  if ((int)uVar7 < 1) break;
                  iVar6 = iVar28 + 1;
                } while (lVar26 != 0);
                uVar7 = *puVar22;
                uVar23 = (ulong)uVar7;
                if (iVar13 == 1) goto joined_r0x001033a0;
                uVar25 = 0;
                lVar26 = *(long *)(lVar27 + 0x140);
                uVar14 = *(undefined8 *)(lVar27 + -0x10);
                do {
                  lVar17 = sg_copy_to_buffer(uVar14,1,lVar26,uVar23);
                  lVar26 = lVar26 + lVar17;
                  uVar23 = uVar23 - lVar17;
                  uVar25 = lVar17 + uVar25;
                  uVar14 = sg_next(uVar14);
                  iVar28 = iVar28 + -1;
                } while (iVar28 != 0);
                uVar21 = *puVar22;
                uVar23 = (ulong)uVar21;
                if (uVar21 != (uint)uVar25) goto LAB_00103554;
              }
              *(uint *)(lVar27 + 0x10c) = uVar21;
              *(uint *)(lVar27 + 0x108) = (uint)*(long *)(lVar27 + 0x140) & 0xfff;
              *(undefined8 *)(lVar27 + 0x90) = *(undefined8 *)(lVar27 + -0x18);
              *(ulong *)(lVar27 + 0x100) =
                   (((*(long *)(lVar27 + 0x140) << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 +
                   -0x1fffffffe;
              *(long *)(lVar27 + -0x10) = lVar27 + 0x100;
              *(long *)(lVar27 + -8) = lVar27 + 0x100;
            }
            local_120 = (code *)((ulong)local_120 & 0xffffffff00000000);
            local_c0 = lVar15 + 0xb8;
            local_118 = _qce_sk_cipher_complete;
            local_108 = *(undefined8 *)(lVar27 + 0xe0);
            local_b8 = CONCAT44(local_b8._4_4_,*(int *)(lVar15 + 0xf8));
            local_100 = CONCAT44(local_100._4_4_,*(undefined4 *)(lVar27 + 0xe8));
            local_b0 = *(byte **)(lVar27 + -0x18);
            local_a8 = CONCAT44(local_a8._4_4_,*(undefined4 *)(*(long *)(lVar15 + 0x10) + -0x10));
            local_a0 = (ulong)*(uint *)(lVar27 + -0x20);
            local_90 = CONCAT44(local_90._4_4_,*(undefined4 *)(lVar15 + 0x60));
            local_110 = puVar22;
            if ((*(int *)(lVar15 + 0xf8) == 0) && (*(int *)(*(long *)(param_2 + 0x20) + 8) == 0))
            goto LAB_00103468;
            iVar13 = qce_ablk_cipher_req(*(undefined8 *)(param_2 + 0x10),&local_120);
          }
          else {
            iVar13 = -0x16;
          }
          goto LAB_001036bc;
        }
        local_f0 = 0;
        local_118 = (code *)0x0;
        local_d8 = *plVar24;
        local_120 = _qce_ahash_complete;
        local_110 = (uint *)(local_d8 + 0x1f8);
        local_108 = *(undefined8 *)(local_d8 + 0x38);
        *(long *)(local_d8 + 0xa8) = param_2;
        lVar27 = *(long *)(local_d8 + 0x20);
        local_100 = CONCAT44(*(undefined4 *)(local_d8 + 0xfc),*(undefined4 *)(local_d8 + 0xf8));
        local_f8 = *(long *)(local_d8 + 0x100);
        uVar7 = (uint)CONCAT11(*(char *)(local_d8 + 0x111) != '\0',
                               *(char *)(local_d8 + 0x110) != '\0');
        local_e8 = (ulong)uVar7 << 0x20;
        local_d0 = (ulong)*(uint *)(lVar27 + 0x60);
        local_e0 = (ulong)*(uint *)(local_d8 + 0x30);
        switch(*(undefined4 *)(lVar27 + 100)) {
        case 0:
          local_f0 = 0;
          break;
        case 1:
          local_118 = (code *)0x1;
          break;
        case 2:
          uVar21 = 2;
          goto LAB_0010336c;
        case 3:
          uVar21 = 3;
LAB_0010336c:
          local_f0 = lVar27 + 0x70;
          local_118 = (code *)(ulong)uVar21;
          local_e8 = CONCAT44(uVar7,0x40);
          break;
        default:
          _printk(&DAT_0010eada);
        }
        iVar13 = qce_process_sha_req(*(undefined8 *)(param_2 + 0x10),&local_120);
LAB_001036bc:
        *(undefined1 *)(param_2 + 300) = 0;
        DataMemoryBarrier(2,3);
        *(long *)(param_2 + 0x50) = *(long *)(param_2 + 0x50) + 1;
        if (iVar13 == 0) goto LAB_00102db4;
        pcVar3 = (char *)(lVar30 + 4);
        *(long *)(param_2 + 0x58) = *(long *)(param_2 + 0x58) + 1;
        *plVar24 = 0;
        *(undefined8 *)(lVar30 + 0x18) = 0;
        Hint_Prefetch(pcVar3,2,0,1);
        do {
          cVar9 = *pcVar3;
          cVar10 = '\x01';
          bVar11 = (bool)ExclusiveMonitorPass(pcVar3,0x10);
          if (bVar11) {
            *pcVar3 = '\0';
            cVar10 = ExclusiveMonitorsStatus();
          }
        } while (cVar10 != '\0');
        DataMemoryBarrier(2,3);
        if (cVar9 == '\0') {
          _printk(&DAT_0010e548,lVar30);
        }
        else {
          piVar5 = (int *)(param_2 + 0x128);
          Hint_Prefetch(piVar5,2,0,1);
          do {
            cVar9 = '\x01';
            bVar11 = (bool)ExclusiveMonitorPass(piVar5,0x10);
            if (bVar11) {
              *piVar5 = *piVar5 + -1;
              cVar9 = ExclusiveMonitorsStatus();
            }
          } while (cVar9 != '\0');
        }
        lVar27 = 0x100;
        if (uVar20 != 0xf) {
          lVar27 = 0x88;
        }
        lVar15 = 0xd0;
        if (uVar20 != 5) {
          lVar15 = lVar27;
        }
        *(long *)((long)&_qcrypto_stat + lVar15) = *(long *)((long)&_qcrypto_stat + lVar15) + 1;
        _qcrypto_tfm_complete(param_2,lVar4,lVar29,iVar13);
        uVar14 = _raw_spin_lock_irqsave(lVar1);
      } while (*(char *)(param_2 + 300) == '\0');
    }
    _raw_spin_unlock_irqrestore(lVar1,uVar14);
  }
LAB_00102db4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// _qcrypto_tfm_complete @ 00103800 size=576
// signature: undefined _qcrypto_tfm_complete(void)
// callers: [_start_qcrypto_process, req_done]
//------------------------------------------------------------

void _qcrypto_tfm_complete(long param_1,long *param_2,long param_3,undefined4 param_4)

{
  int *piVar1;
  long lVar2;
  long *plVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  bool bVar7;
  undefined8 uVar8;
  ulong uVar9;
  undefined4 uVar10;
  int *piVar11;
  long *plVar12;
  long lVar13;
  uint uVar14;
  
  lVar13 = *(long *)(param_1 + 0x20);
  uVar8 = _raw_spin_lock_irqsave(lVar13 + 0x34);
  *(undefined4 *)(param_3 + 0x20) = param_4;
  plVar12 = (long *)*param_2;
  if (plVar12 == param_2) {
    uVar14 = 0;
  }
  else {
    uVar14 = 0;
    do {
      if ((int)plVar12[4] == -0x73) break;
      uVar9 = __list_del_entry_valid(plVar12);
      if ((uVar9 & 1) != 0) {
        lVar2 = *plVar12;
        plVar3 = (long *)plVar12[1];
        *(long **)(lVar2 + 8) = plVar3;
        *plVar3 = lVar2;
      }
      *plVar12 = -0x2152ffffffffff00;
      plVar12[1] = -0x2152fffffffffede;
      llist_add_batch(plVar12 + 2,plVar12 + 2,lVar13 + 0xf0);
      piVar1 = (int *)(lVar13 + 0xf8);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        cVar6 = '\x01';
        bVar7 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar7) {
          *piVar1 = *piVar1 + 1;
          cVar6 = ExclusiveMonitorsStatus();
        }
      } while (cVar6 != '\0');
      plVar12 = (long *)*param_2;
      uVar14 = uVar14 + 1;
    } while (plVar12 != param_2);
  }
  uVar4 = *(uint *)(lVar13 + 0xf8);
  if (*(uint *)(lVar13 + 0x174) < uVar4) {
    *(uint *)(lVar13 + 0x174) = uVar4;
  }
  if (*(uint *)(lVar13 + 0x178) < uVar14) {
    *(uint *)(lVar13 + 0x178) = uVar14;
  }
  if (399 < uVar4) {
    piVar1 = (int *)(lVar13 + 0x13c);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar5 = *piVar1;
      if (iVar5 != 1) goto LAB_00103a98;
      cVar6 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar7) {
        *piVar1 = 0;
        cVar6 = ExclusiveMonitorsStatus();
      }
    } while (cVar6 != '\0');
    DataMemoryBarrier(2,3);
LAB_00103a98:
    if (iVar5 == 1) {
      *(int *)(lVar13 + 0x15c) = *(int *)(lVar13 + 0x15c) + 1;
    }
  }
  _raw_spin_unlock_irqrestore(lVar13 + 0x34,uVar8);
  piVar1 = (int *)(lVar13 + 0x138);
  do {
    if (*(long *)(lVar13 + 0xf0) == 0) {
      return;
    }
    if (*(char *)(param_1 + 0x12d) == '\0') {
      uVar10 = *(undefined4 *)(lVar13 + 0x140);
      *(int *)(lVar13 + 0x16c) = *(int *)(lVar13 + 0x16c) + 1;
      if ((*(long *)(lVar13 + 0x148) != 0) && (*(int *)(*(long *)(lVar13 + 0x148) + 0x128) != 0)) {
        piVar11 = (int *)(lVar13 + 0x170);
        if (uVar4 < 0x40) {
          return;
        }
        goto LAB_0010397c;
      }
    }
    else {
      uVar10 = 0x20;
      piVar11 = (int *)(lVar13 + 0x168);
LAB_0010397c:
      *piVar11 = *piVar11 + 1;
    }
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar5 = *piVar1;
      if (iVar5 != 0) goto LAB_00103a1c;
      cVar6 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar7) {
        *piVar1 = 1;
        cVar6 = ExclusiveMonitorsStatus();
      }
    } while (cVar6 != '\0');
    DataMemoryBarrier(2,3);
LAB_00103a1c:
    if (iVar5 == 0) {
      queue_work_on(uVar10,*(undefined8 *)(lVar13 + 0x100),lVar13 + 0x108);
      return;
    }
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar5 = *piVar1;
      if (iVar5 != 1) goto LAB_00103a40;
      cVar6 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar7) {
        *piVar1 = 2;
        cVar6 = ExclusiveMonitorsStatus();
      }
    } while (cVar6 != '\0');
    DataMemoryBarrier(2,3);
LAB_00103a40:
    if (iVar5 != 0) {
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// _qce_sk_cipher_complete @ 00103aa8 size=508
// signature: undefined _qce_sk_cipher_complete(void)
// callers: []
//------------------------------------------------------------

void _qce_sk_cipher_complete(uint *param_1,undefined8 param_2,void *param_3,int param_4)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  int iVar4;
  undefined4 uVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  undefined8 uVar9;
  long lVar10;
  
  iVar4 = *(int *)(*(long *)(param_1 + 0x2a) + 0x11c);
  if (iVar4 != 0) {
    lVar3 = *(long *)(param_1 + 0x10);
    lVar6 = *(long *)(*(long *)(param_1 + 0x2a) + 0x120);
    lVar10 = *(long *)(lVar3 + 0x58);
    do {
      if (*(uint **)(lVar6 + 0x10) == param_1 + 8) {
        if (lVar6 != 0) {
          if (param_3 != (void *)0x0) {
            uVar1 = *(uint *)(*(long *)(lVar3 + 0x10) + -0x10);
            if ((0x10 < uVar1) && ((_qce_sk_cipher_complete___already_done & 1) == 0)) {
              _qce_sk_cipher_complete___already_done = 1;
              __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n"
                            ,(ulong)uVar1,
                            "field \"ctx->iv\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcrypto.c:1824"
                            ,0x10);
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x800,0x103ca4);
              (*pcVar2)();
            }
            memcpy((void *)(lVar3 + 0xa8),param_3,(ulong)uVar1);
          }
          lVar3 = 200;
          if (param_4 != 0) {
            lVar3 = 0xd0;
          }
          uVar5 = 0;
          if (param_4 != 0) {
            uVar5 = 0xfffffffa;
          }
          *(long *)((long)&_qcrypto_stat + lVar3) = *(long *)((long)&_qcrypto_stat + lVar3) + 1;
          *(undefined4 *)(lVar6 + 0x20) = uVar5;
          if (*(char *)(lVar10 + 0x19) == '\0') goto LAB_00103c24;
          lVar3 = *(long *)(param_1 + 0x46);
          uVar1 = *param_1;
          uVar7 = (ulong)uVar1;
          *(undefined8 *)(param_1 + 4) = *(undefined8 *)(param_1 + 0x44);
          *(long *)(param_1 + 6) = lVar3;
          if ((lVar3 == 0) || ((int)uVar1 < 1)) goto joined_r0x00103c60;
          iVar4 = 0;
          do {
            iVar4 = iVar4 + 1;
            uVar1 = (int)uVar7 - *(int *)(lVar3 + 0xc);
            uVar7 = (ulong)uVar1;
            lVar3 = sg_next();
          } while (0 < (int)uVar1 && lVar3 != 0);
          uVar1 = *param_1;
          uVar7 = (ulong)uVar1;
          if (iVar4 == 0) {
joined_r0x00103c60:
            uVar8 = 0;
            if (uVar1 != 0) {
LAB_00103c64:
              _printk(&DAT_0010de03,uVar8 & 0xffffffff,uVar7);
            }
          }
          else {
            uVar8 = 0;
            lVar3 = *(long *)(param_1 + 0x58);
            uVar9 = *(undefined8 *)(param_1 + 6);
            do {
              lVar10 = sg_copy_from_buffer(uVar9,1,lVar3,uVar7);
              lVar3 = lVar3 + lVar10;
              uVar7 = uVar7 - lVar10;
              uVar8 = lVar10 + uVar8;
              uVar9 = sg_next(uVar9);
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
            uVar7 = (ulong)*param_1;
            if (*param_1 != (uint)uVar8) goto LAB_00103c64;
          }
          kfree_sensitive(*(undefined8 *)(param_1 + 0x58));
LAB_00103c24:
          req_done(lVar6);
          return;
        }
        break;
      }
      lVar6 = lVar6 + 0x28;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  _printk(&DAT_0010eb61);
  return;
}



//------------------------------------------------------------
// req_done @ 00103ca8 size=268
// signature: undefined req_done(void)
// callers: [_qce_sk_cipher_complete, _qce_aead_complete, _qce_ahash_complete]
//------------------------------------------------------------

void req_done(long param_1)

{
  char *pcVar1;
  int *piVar2;
  long lVar3;
  long lVar4;
  undefined4 uVar5;
  int iVar6;
  char cVar7;
  char cVar8;
  bool bVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  undefined8 uVar13;
  
  lVar3 = *(long *)(param_1 + 8);
  lVar4 = *(long *)(param_1 + 0x10);
  pcVar1 = (char *)(param_1 + 4);
  uVar13 = *(undefined8 *)(param_1 + 0x18);
  uVar5 = *(undefined4 *)(param_1 + 0x20);
  lVar12 = *(long *)(lVar3 + 0x20);
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  Hint_Prefetch(pcVar1,2,0,1);
  do {
    cVar7 = *pcVar1;
    cVar8 = '\x01';
    bVar9 = (bool)ExclusiveMonitorPass(pcVar1,0x10);
    if (bVar9) {
      *pcVar1 = '\0';
      cVar8 = ExclusiveMonitorsStatus();
    }
  } while (cVar8 != '\0');
  DataMemoryBarrier(2,3);
  if (cVar7 == '\0') {
    _printk(&DAT_0010e548,param_1);
  }
  else {
    piVar2 = (int *)(lVar3 + 0x128);
    Hint_Prefetch(piVar2,2,0,1);
    do {
      cVar7 = '\x01';
      bVar9 = (bool)ExclusiveMonitorPass(piVar2,0x10);
      if (bVar9) {
        *piVar2 = *piVar2 + -1;
        cVar7 = ExclusiveMonitorsStatus();
      }
    } while (cVar7 != '\0');
  }
  if (lVar4 == 0) {
    lVar11 = 0;
  }
  else {
    lVar11 = *(long *)(lVar4 + 0x20) + 0x40;
  }
  lVar10 = tpidr_el1;
  iVar6 = *(int *)(&cpu_number + lVar10);
  *(int *)(lVar3 + 0x130) = iVar6;
  if ((*(char *)(lVar3 + 0x12d) != '\0') && (iVar6 != *(int *)(lVar12 + 0x140))) {
    *(int *)(lVar12 + 0x140) = iVar6;
  }
  if (lVar4 != 0) {
    _qcrypto_tfm_complete(lVar3,lVar11,uVar13,uVar5);
  }
  if (*(int *)(lVar12 + 0x13c) == 1) {
    _start_qcrypto_process(lVar12,lVar3);
  }
  return;
}



//------------------------------------------------------------
// _qce_ahash_complete @ 00103dc4 size=396
// signature: undefined _qce_ahash_complete(void)
// callers: []
//------------------------------------------------------------

void _qce_ahash_complete(long param_1,void *param_2,undefined4 *param_3,int param_4)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  long lVar6;
  ulong __n;
  long lVar7;
  
  iVar4 = *(int *)(*(long *)(param_1 + 0xa8) + 0x11c);
  if (iVar4 != 0) {
    lVar6 = *(long *)(*(long *)(param_1 + 0xa8) + 0x120);
    lVar7 = *(long *)(*(long *)(param_1 + 0x20) + 0x58);
    uVar2 = *(uint *)(*(long *)(*(long *)(param_1 + 0x20) + 0x10) + -0x40);
    __n = (ulong)uVar2;
    do {
      if (*(long *)(lVar6 + 0x10) == param_1) {
        if (lVar6 != 0) {
          if (param_2 != (void *)0x0) {
            if ((0x20 < uVar2) && ((_qce_ahash_complete___already_done & 1) == 0)) {
              _qce_ahash_complete___already_done = 1;
              __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n"
                            ,__n,
                            "field \"rctx->digest\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcrypto.c:1765"
                            ,0x20);
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x800,0x103f50);
              (*pcVar3)();
            }
            memcpy((void *)(param_1 + 0x1f8),param_2,__n);
            if (*(char *)(param_1 + 0x111) != '\0') {
              memcpy(*(void **)(param_1 + 0x40),param_2,__n);
            }
          }
          if (param_3 != (undefined4 *)0x0) {
            *(undefined4 *)(param_1 + 0xf8) = *param_3;
            *(undefined4 *)(param_1 + 0xfc) = param_3[1];
            *(undefined4 *)(param_1 + 0x100) = param_3[2];
            *(undefined4 *)(param_1 + 0x104) = param_3[3];
          }
          *(undefined2 *)(param_1 + 0x110) = 0;
          *(undefined8 *)(param_1 + 0x38) = *(undefined8 *)(param_1 + 0xb0);
          lVar1 = 0xf8;
          if (param_4 != 0) {
            lVar1 = 0x100;
          }
          *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0xb8);
          uVar5 = 0;
          if (param_4 != 0) {
            uVar5 = 0xfffffffa;
          }
          *(long *)((long)&_qcrypto_stat + lVar1) = *(long *)((long)&_qcrypto_stat + lVar1) + 1;
          *(undefined4 *)(lVar6 + 0x20) = uVar5;
          if (*(char *)(lVar7 + 0x19) != '\0') {
            *(undefined8 *)(param_1 + 0x38) = *(undefined8 *)(param_1 + 0xc0);
            kfree(*(undefined8 *)(param_1 + 0xe8));
          }
          req_done(lVar6);
          return;
        }
        break;
      }
      lVar6 = lVar6 + 0x28;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  _printk(&DAT_0010eb61);
  return;
}



//------------------------------------------------------------
// _qce_aead_complete @ 00103f58 size=500
// signature: undefined _qce_aead_complete(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _qce_aead_complete(long param_1,void *param_2,void *param_3,int param_4)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  iVar4 = *(int *)(*(long *)(param_1 + 0xa8) + 0x11c);
  if (iVar4 != 0) {
    lVar6 = *(long *)(param_1 + 0x20);
    lVar5 = *(long *)(*(long *)(param_1 + 0xa8) + 0x120);
    do {
      if (*(long *)(lVar5 + 0x10) == param_1) {
        if (lVar5 != 0) {
          if (*(int *)(param_1 + 0x108) == 4) {
            kfree_sensitive(*(undefined8 *)(param_1 + 0xf8));
          }
          else {
            uVar2 = *(uint *)(*(long *)(lVar6 + 0x10) + -0x10);
            if (param_4 == 0) {
              if (*(int *)(param_1 + 0x104) == 0) {
                scatterwalk_map_and_copy
                          (param_2,*(undefined8 *)(param_1 + 0x48),
                           *(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x34),
                           *(undefined4 *)(lVar6 + 0xfc),1);
                param_4 = 0;
              }
              else {
                local_58 = 0;
                uStack_50 = 0;
                local_68 = 0;
                uStack_60 = 0;
                scatterwalk_map_and_copy
                          (&local_68,*(undefined8 *)(param_1 + 0x40),
                           (*(int *)(param_1 + 0x34) + *(int *)(param_1 + 0x30)) -
                           *(int *)(lVar6 + 0xfc),*(int *)(lVar6 + 0xfc),0);
                if (0x20 < *(uint *)(lVar6 + 0xfc)) {
                  fortify_panic("memcmp");
                    /* WARNING: Bad instruction - Truncating control flow here */
                  halt_baddata();
                }
                iVar4 = bcmp(param_2,&local_68,(ulong)*(uint *)(lVar6 + 0xfc));
                param_4 = 0;
                if (iVar4 != 0) {
                  param_4 = -0x4a;
                }
              }
            }
            else {
              param_4 = -6;
            }
            if (param_3 != (void *)0x0) {
              if ((0x10 < uVar2) && ((_qce_aead_complete___already_done & 1) == 0)) {
                _qce_aead_complete___already_done = 1;
                __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n"
                              ,(ulong)uVar2,
                              "field \"ctx->iv\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcrypto.c:1907"
                              ,0x10);
                    /* WARNING: Does not return */
                pcVar3 = (code *)SoftwareBreakpoint(0x800,0x10413c);
                (*pcVar3)();
              }
              memcpy((void *)(lVar6 + 0xa8),param_3,(ulong)uVar2);
            }
          }
          lVar6 = 0x80;
          if (param_4 != 0) {
            lVar6 = 0x88;
          }
          lVar1 = 0x90;
          if (param_4 != -0x4a) {
            lVar1 = lVar6;
          }
          *(long *)((long)&_qcrypto_stat + lVar1) = *(long *)((long)&_qcrypto_stat + lVar1) + 1;
          *(int *)(lVar5 + 0x20) = param_4;
          req_done(lVar5);
          goto LAB_001040e4;
        }
        break;
      }
      lVar5 = lVar5 + 0x28;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  _printk(&DAT_0010eb61);
LAB_001040e4:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// _qcrypto_probe @ 00104154 size=3908
// signature: undefined _qcrypto_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _qcrypto_probe(long param_1)

{
  int *piVar1;
  uint uVar2;
  undefined8 *puVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  undefined8 *puVar7;
  ulong uVar8;
  long lVar9;
  undefined8 *puVar10;
  size_t sVar11;
  long lVar12;
  char *pcVar13;
  char cVar14;
  int iVar15;
  ulong uVar16;
  uint *puVar17;
  ulong uVar18;
  long unaff_x22;
  undefined4 *unaff_x25;
  long lVar19;
  long local_78;
  int local_6c;
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  local_6c = 0;
  puVar7 = (undefined8 *)kmalloc_trace(_crypto_register_skcipher,0xdc0,0x138);
  if (puVar7 == (undefined8 *)0x0) {
    iVar6 = -0xc;
    goto LAB_001046f0;
  }
  lVar12 = param_1 + 0x10;
  uVar8 = of_icc_get(lVar12,"data_path");
  puVar7[5] = uVar8;
  if (0xfffffffffffff000 < uVar8) {
    _dev_err(lVar12,"failed to get icc path\n");
    local_6c = (int)puVar7[5];
    goto LAB_001046c4;
  }
  *(undefined4 *)(puVar7 + 0xe) = 0;
  local_6c = icc_set_bw(uVar8,0x180,0x180);
  if (local_6c != 0) {
    _dev_err(lVar12,"failed to set high bandwidth\n");
    goto LAB_001046c4;
  }
  lVar9 = qce_open(param_1,&local_6c);
  if (lVar9 == 0) {
    local_6c = -0x13;
    goto LAB_001046b0;
  }
  local_6c = icc_set_bw(puVar7[5],0,0);
  if (local_6c != 0) {
    _dev_err(lVar12,"failed to set low bandwidth\n");
    lVar12 = puVar7[2];
    unaff_x22 = lVar9;
    goto joined_r0x00104678;
  }
  unaff_x25 = &qcrypto_dev;
  *(undefined8 **)(param_1 + 0xa8) = puVar7;
  puVar7[3] = param_1;
  puVar7[4] = &qcrypto_dev;
  puVar7[2] = lVar9;
  *(undefined4 *)((long)puVar7 + 0x6c) = 0xdeadbeef;
  init_timer_key(puVar7 + 0xf,qcrypto_bw_reaper_timer_callback,0,0,0);
  puVar7[0x16] = 0xfffffffe0;
  puVar7[0x17] = puVar7 + 0x17;
  puVar7[0x18] = puVar7 + 0x17;
  puVar7[0x1c] = 0xfffffffe0;
  puVar7[0x19] = qcrypto_bw_reaper_work;
  puVar7[0x1d] = puVar7 + 0x1d;
  puVar7[0x1e] = puVar7 + 0x1d;
  puVar7[0x1f] = qcrypto_bw_allocate_work;
  *(undefined1 *)((long)puVar7 + 0x74) = 0;
  *(undefined4 *)((long)puVar7 + 0x134) = 0;
  *(undefined1 *)((long)puVar7 + 300) = 0;
  puVar7[0x22] = 0;
  *(undefined1 *)(puVar7 + 0x23) = 0;
  crypto_init_queue(puVar7 + 6,0x300);
  mutex_lock(&DAT_0010c9b0);
  DAT_0010c9a8 = DAT_0010c9a8 + 1;
  *(int *)(puVar7 + 0xc) = DAT_0010c9a8;
  lVar9 = _raw_spin_lock_irqsave(&DAT_0010c94c);
  bVar5 = (undefined8 **)DAT_0010c998 == &DAT_0010c998;
  *(bool *)((long)puVar7 + 0x12d) = bVar5;
  puVar10 = DAT_0010c9a0;
  if (bVar5) {
    DAT_0010ca60 = puVar7;
  }
  uVar8 = __list_add_valid(puVar7,DAT_0010c9a0,&DAT_0010c998);
  if ((uVar8 & 1) != 0) {
    DAT_0010c9a0 = puVar7;
    *puVar7 = &DAT_0010c998;
    puVar7[1] = puVar10;
    *puVar10 = puVar7;
  }
  DAT_0010c9e0 = puVar7;
  _raw_spin_unlock_irqrestore(&DAT_0010c94c,lVar9);
  qce_hw_support(puVar7[2],&DAT_0010c928);
  uVar2 = DAT_0010c948;
  uVar8 = (ulong)DAT_0010c948;
  *(undefined4 *)(puVar7 + 0xd) = DAT_0010c944;
  uVar8 = uVar8 * 0x28;
  *(uint *)((long)puVar7 + 0x11c) = uVar2;
  unaff_x22 = __kmalloc(uVar8,0xdc0);
  if (unaff_x22 == 0) {
    local_6c = -0xc;
    goto LAB_00104698;
  }
  iVar6 = *(int *)((long)puVar7 + 0x11c);
  puVar7[0x24] = unaff_x22;
  *(undefined4 *)(puVar7 + 0x25) = 0;
  if (iVar6 != 0) {
    iVar15 = 0;
    uVar18 = 0;
    uVar16 = uVar8 - 8;
    do {
      if (uVar8 <= uVar18) {
LAB_0010497c:
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(1,0x104980);
        (*pcVar4)();
      }
      piVar1 = (int *)(unaff_x22 + uVar18);
      *piVar1 = iVar15;
      if (((uVar8 < uVar18 + 4) || (*(undefined1 *)(piVar1 + 1) = 0, uVar8 < uVar18 + 8)) ||
         (uVar16 < 8)) goto LAB_0010497c;
      iVar15 = iVar15 + 1;
      uVar16 = uVar16 - 0x28;
      uVar18 = uVar18 + 0x28;
      *(undefined8 **)(piVar1 + 2) = puVar7;
    } while (iVar6 != iVar15);
  }
  if (DAT_0010c932 == '\0') {
    puVar17 = *(uint **)(param_1 + 0xa0);
    qcrypto_dev = *puVar17;
    DAT_0010c91c = puVar17[1];
    DAT_0010c920 = puVar17[2];
    DAT_0010c924 = puVar17[3];
  }
  else {
    DAT_0010c91c = 0;
    DAT_0010c924 = 1;
    qcrypto_dev = (uint)DAT_0010c933;
    DAT_0010c920 = (uint)DAT_0010c934;
    *(undefined4 *)((long)puVar7 + 100) = DAT_0010c940;
  }
  lVar9 = unaff_x22;
  if (DAT_0010c9a8 != 1) goto LAB_00104698;
  lVar19 = 0;
  do {
    puVar10 = (undefined8 *)kmalloc_trace(__dev_err,0xdc0,0x640);
    local_78 = lVar12;
    if (puVar10 == (undefined8 *)0x0) {
      puVar10 = (undefined8 *)0xfffffffffffffff4;
LAB_00104684:
      local_6c = (int)puVar10;
      goto LAB_00104688;
    }
    *(undefined4 *)(puVar10 + 0xc0) = 0;
    memcpy(puVar10 + 8,(void *)((long)&_qcrypto_sk_cipher_algos + lVar19),0x1c0);
    puVar10[0xc1] = &qcrypto_dev;
    if ((undefined8 *)0xfffffffffffff000 < puVar10) goto LAB_00104684;
    if (DAT_0010c935 != '\0') {
      pcVar13 = (char *)(puVar10 + 0x17);
      sVar11 = strnlen(pcVar13,0x80);
      if (0x80 < sVar11) goto LAB_00105014;
      if (sVar11 == 0x80) goto LAB_00105008;
      local_6c = _qcrypto_prefix_alg_cra_name(pcVar13,sVar11);
      if (local_6c != 0) {
        _dev_err(lVar12,"The algorithm name %s is too long.\n",pcVar13);
        goto LAB_00104740;
      }
    }
    local_6c = crypto_register_skcipher(puVar10 + 8);
    puVar3 = DAT_0010c958;
    if (local_6c == 0) {
      uVar8 = __list_add_valid(puVar10,DAT_0010c958);
      if ((uVar8 & 1) != 0) {
        DAT_0010c958 = puVar10;
        *puVar10 = &DAT_0010c950;
        puVar10[1] = puVar3;
        *puVar3 = puVar10;
      }
      _dev_info(lVar12,&DAT_0010e756,puVar10 + 0x27);
    }
    else {
      _dev_err(lVar12,"%s alg registration failed\n",puVar10 + 0x27);
      kfree_sensitive(puVar10);
    }
    lVar19 = lVar19 + 0x1c0;
  } while (lVar19 != 0xc40);
  if (DAT_0010c92e == '\0') {
LAB_00104768:
    puVar10 = (undefined8 *)kmalloc_trace(__dev_err,0xdc0,0x640);
    if (puVar10 != (undefined8 *)0x0) {
      *(undefined4 *)(puVar10 + 0xc0) = 1;
      memcpy(puVar10 + 0x40,&_qcrypto_ahash_algos,0x240);
      puVar10[0xc1] = &qcrypto_dev;
      if (puVar10 < (undefined8 *)0xfffffffffffff001) {
        if (DAT_0010c938 != '\0') {
          pcVar13 = (char *)(puVar10 + 0x5f);
          sVar11 = strnlen(pcVar13,0x80);
          if (0x80 < sVar11) goto LAB_00105014;
          if (sVar11 == 0x80) goto LAB_00105008;
          local_6c = _qcrypto_prefix_alg_cra_name(pcVar13,sVar11);
          if (local_6c != 0) goto LAB_00104970;
        }
        local_6c = crypto_register_ahash(puVar10 + 0x40);
        puVar3 = DAT_0010c958;
        if (local_6c == 0) {
          uVar8 = __list_add_valid(puVar10,DAT_0010c958);
          if ((uVar8 & 1) != 0) {
            DAT_0010c958 = puVar10;
            *puVar10 = &DAT_0010c950;
            puVar10[1] = puVar3;
            *puVar3 = puVar10;
          }
          _dev_info(lVar12,&DAT_0010e756,puVar10 + 0x6f);
        }
        else {
          _dev_err(lVar12,"%s alg registration failed\n",puVar10 + 0x6f);
          kfree_sensitive(puVar10);
        }
        puVar10 = (undefined8 *)kmalloc_trace(__dev_err,0xdc0,0x640);
        if (puVar10 == (undefined8 *)0x0) goto LAB_00104954;
        *(undefined4 *)(puVar10 + 0xc0) = 1;
        memcpy(puVar10 + 0x40,&PTR__sha256_init_0010b400,0x240);
        puVar10[0xc1] = &qcrypto_dev;
        if (puVar10 < (undefined8 *)0xfffffffffffff001) {
          if (DAT_0010c938 != '\0') {
            pcVar13 = (char *)(puVar10 + 0x5f);
            sVar11 = strnlen(pcVar13,0x80);
            if (0x80 < sVar11) goto LAB_00105014;
            if (sVar11 == 0x80) goto LAB_00105008;
            local_6c = _qcrypto_prefix_alg_cra_name(pcVar13,sVar11);
            if (local_6c != 0) {
LAB_00104970:
              _dev_err(lVar12,"The algorithm name %s is too long.\n",pcVar13);
              goto LAB_00104740;
            }
          }
          local_6c = crypto_register_ahash(puVar10 + 0x40);
          puVar3 = DAT_0010c958;
          if (local_6c == 0) {
            uVar8 = __list_add_valid(puVar10,DAT_0010c958);
            if ((uVar8 & 1) != 0) {
              DAT_0010c958 = puVar10;
              *puVar10 = &DAT_0010c950;
              puVar10[1] = puVar3;
              *puVar3 = puVar10;
            }
            _dev_info(lVar12,&DAT_0010e756,puVar10 + 0x6f);
          }
          else {
            _dev_err(lVar12,"%s alg registration failed\n",puVar10 + 0x6f);
            kfree_sensitive(puVar10);
          }
          if (((DAT_0010c928 != '\0') || (DAT_0010c929 != '\0')) ||
             (cVar14 = DAT_0010c92b, DAT_0010c92b != '\0')) {
            lVar19 = 0;
            do {
              puVar10 = (undefined8 *)kmalloc_trace(__dev_err,0xdc0,0x640);
              if (puVar10 == (undefined8 *)0x0) goto LAB_00104d48;
              *(undefined4 *)(puVar10 + 0xc0) = 2;
              memcpy(puVar10 + 0x88,(void *)((long)&_qcrypto_aead_sha1_hmac_algos + lVar19),0x1c0);
              puVar10[0xc1] = &qcrypto_dev;
              if ((undefined8 *)0xfffffffffffff000 < puVar10) goto LAB_00104d4c;
              if (DAT_0010c936 != '\0') {
                pcVar13 = (char *)(puVar10 + 0x97);
                sVar11 = strnlen(pcVar13,0x80);
                if (0x80 < sVar11) goto LAB_00105014;
                if (sVar11 == 0x80) goto LAB_00105008;
                local_6c = _qcrypto_prefix_alg_cra_name(pcVar13,sVar11);
                if (local_6c != 0) goto LAB_00104d54;
              }
              local_6c = crypto_register_aead(puVar10 + 0x88);
              puVar3 = DAT_0010c958;
              if (local_6c == 0) {
                uVar8 = __list_add_valid(puVar10,DAT_0010c958);
                if ((uVar8 & 1) != 0) {
                  DAT_0010c958 = puVar10;
                  *puVar10 = &DAT_0010c950;
                  puVar10[1] = puVar3;
                  *puVar3 = puVar10;
                }
                _dev_info(lVar12,&DAT_0010e756,puVar10 + 0xa7);
              }
              else {
                _dev_err(lVar12,"%s alg registration failed\n",puVar10 + 0xa7);
                kfree(puVar10);
              }
              lVar19 = lVar19 + 0x1c0;
            } while (lVar19 != 0x540);
            cVar14 = '\0';
            if (DAT_0010c92b != '\0') {
              lVar19 = 0;
              do {
                puVar10 = (undefined8 *)kmalloc_trace(__dev_err,0xdc0,0x640);
                if (puVar10 == (undefined8 *)0x0) goto LAB_00104d48;
                *(undefined4 *)(puVar10 + 0xc0) = 2;
                memcpy(puVar10 + 0x88,(void *)((long)&_qcrypto_aead_sha256_hmac_algos + lVar19),
                       0x1c0);
                puVar10[0xc1] = &qcrypto_dev;
                if ((undefined8 *)0xfffffffffffff000 < puVar10) goto LAB_00104d4c;
                if (DAT_0010c936 != '\0') {
                  pcVar13 = (char *)(puVar10 + 0x97);
                  sVar11 = strnlen(pcVar13,0x80);
                  if (0x80 < sVar11) goto LAB_00105014;
                  if (sVar11 == 0x80) goto LAB_00105008;
                  local_6c = _qcrypto_prefix_alg_cra_name(pcVar13,sVar11);
                  if (local_6c != 0) {
LAB_00104d54:
                    _dev_err(lVar12,"The algorithm name %s is too long.\n",pcVar13);
                    goto LAB_00104740;
                  }
                }
                local_6c = crypto_register_aead(puVar10 + 0x88);
                puVar3 = DAT_0010c958;
                if (local_6c == 0) {
                  uVar8 = __list_add_valid(puVar10,DAT_0010c958);
                  if ((uVar8 & 1) != 0) {
                    DAT_0010c958 = puVar10;
                    *puVar10 = &DAT_0010c950;
                    puVar10[1] = puVar3;
                    *puVar3 = puVar10;
                  }
                  _dev_info(lVar12,&DAT_0010e756,puVar10 + 0xa7);
                }
                else {
                  _dev_err(lVar12,"%s alg registration failed\n",puVar10 + 0xa7);
                  kfree(puVar10);
                }
                lVar19 = lVar19 + 0x1c0;
              } while (lVar19 != 0x540);
              cVar14 = DAT_0010c92b;
            }
          }
          if (cVar14 != '\0' || DAT_0010c924 != 0) goto LAB_00104cf8;
          goto LAB_001049c8;
        }
      }
LAB_001047ac:
      local_6c = (int)puVar10;
      goto LAB_00104688;
    }
  }
  else {
    puVar10 = (undefined8 *)kmalloc_trace(__dev_err,0xdc0,0x640);
    if (puVar10 != (undefined8 *)0x0) {
      *(undefined4 *)(puVar10 + 0xc0) = 0;
      memcpy(puVar10 + 8,&_qcrypto_sk_cipher_xts_algo,0x1c0);
      puVar10[0xc1] = &qcrypto_dev;
      if (puVar10 < (undefined8 *)0xfffffffffffff001) {
        if (DAT_0010c937 != '\0') {
          pcVar13 = (char *)(puVar10 + 0x17);
          sVar11 = strnlen(pcVar13,0x80);
          if (0x80 < sVar11) goto LAB_00105014;
          if (sVar11 == 0x80) goto LAB_00105008;
          local_6c = _qcrypto_prefix_alg_cra_name(pcVar13,sVar11);
          if (local_6c != 0) goto LAB_00104970;
        }
        local_6c = crypto_register_skcipher(puVar10 + 8);
        puVar3 = DAT_0010c958;
        if (local_6c == 0) {
          uVar8 = __list_add_valid(puVar10,DAT_0010c958);
          if ((uVar8 & 1) != 0) {
            DAT_0010c958 = puVar10;
            *puVar10 = &DAT_0010c950;
            puVar10[1] = puVar3;
            *puVar3 = puVar10;
          }
          _dev_info(lVar12,&DAT_0010e756,puVar10 + 0x27);
        }
        else {
          _dev_err(lVar12,"%s alg registration failed\n",puVar10 + 0x27);
          kfree_sensitive(puVar10);
        }
        goto LAB_00104768;
      }
      goto LAB_001047ac;
    }
  }
LAB_00104954:
  local_6c = -0xc;
  goto LAB_00104688;
LAB_00104d48:
  puVar10 = (undefined8 *)0xfffffffffffffff4;
LAB_00104d4c:
  local_6c = (int)puVar10;
LAB_00104688:
  _qcrypto_remove_engine(puVar7);
  kfree_sensitive(lVar9);
LAB_00104698:
  mutex_unlock(&DAT_0010c9b0);
  lVar12 = puVar7[2];
  unaff_x22 = lVar9;
joined_r0x00104678:
  if (lVar12 != 0) {
    qce_close();
  }
LAB_001046b0:
  icc_set_bw(puVar7[5],0,0);
  *(undefined8 *)(param_1 + 0xa8) = 0;
LAB_001046c4:
  uVar8 = ksize(puVar7);
  if (uVar8 < 0x139) {
    memset(puVar7,0,uVar8);
    kfree(puVar7);
    iVar6 = local_6c;
    goto LAB_001046f0;
  }
  fortify_panic("memset");
LAB_00104cf8:
  puVar10 = (undefined8 *)kmalloc_trace(__dev_err,0xdc0,0x640);
  if (puVar10 == (undefined8 *)0x0) goto LAB_00105020;
  *(undefined4 *)(puVar10 + 0xc0) = 1;
  memcpy(puVar10 + 0x40,&_qcrypto_sha_hmac_algos,0x240);
  puVar10[0xc1] = unaff_x25;
  if ((undefined8 *)0xfffffffffffff000 < puVar10) goto LAB_00104d40;
  if (DAT_0010c939 != '\0') {
    pcVar13 = (char *)(puVar10 + 0x5f);
    sVar11 = strnlen(pcVar13,0x80);
    if (sVar11 < 0x81) {
      if (sVar11 != 0x80) {
        local_6c = _qcrypto_prefix_alg_cra_name(pcVar13,sVar11);
        if (local_6c == 0) goto LAB_00104db0;
LAB_0010503c:
        _dev_err(local_78,"The algorithm name %s is too long.\n",pcVar13);
LAB_00104740:
        kfree(puVar10);
        lVar9 = unaff_x22;
        goto LAB_00104688;
      }
LAB_00105008:
      fortify_panic("__fortify_strlen");
    }
LAB_00105014:
    fortify_panic("strnlen");
LAB_00105020:
    local_6c = -0xc;
    lVar9 = unaff_x22;
    goto LAB_00104688;
  }
LAB_00104db0:
  local_6c = crypto_register_ahash(puVar10 + 0x40);
  puVar3 = DAT_0010c958;
  if (local_6c == 0) {
    uVar8 = __list_add_valid(puVar10,DAT_0010c958);
    if ((uVar8 & 1) != 0) {
      DAT_0010c958 = puVar10;
      *puVar10 = &DAT_0010c950;
      puVar10[1] = puVar3;
      *puVar3 = puVar10;
    }
    _dev_info(local_78,&DAT_0010e756,puVar10 + 0x6f);
  }
  else {
    _dev_err(local_78,"%s alg registration failed\n",puVar10 + 0x6f);
    kfree_sensitive(puVar10);
  }
  puVar10 = (undefined8 *)kmalloc_trace(__dev_err,0xdc0,0x640);
  if (puVar10 == (undefined8 *)0x0) goto LAB_00105020;
  *(undefined4 *)(puVar10 + 0xc0) = 1;
  memcpy(puVar10 + 0x40,&PTR__sha256_hmac_init_0010c300,0x240);
  puVar10[0xc1] = unaff_x25;
  if (puVar10 < (undefined8 *)0xfffffffffffff001) {
    if (DAT_0010c939 != '\0') {
      pcVar13 = (char *)(puVar10 + 0x5f);
      sVar11 = strnlen(pcVar13,0x80);
      if (0x80 < sVar11) goto LAB_00105014;
      if (sVar11 == 0x80) goto LAB_00105008;
      local_6c = _qcrypto_prefix_alg_cra_name(pcVar13,sVar11);
      if (local_6c != 0) goto LAB_0010503c;
    }
    local_6c = crypto_register_ahash(puVar10 + 0x40);
    puVar3 = DAT_0010c958;
    if (local_6c == 0) {
      uVar8 = __list_add_valid(puVar10,DAT_0010c958);
      if ((uVar8 & 1) != 0) {
        DAT_0010c958 = puVar10;
        *puVar10 = &DAT_0010c950;
        puVar10[1] = puVar3;
        *puVar3 = puVar10;
      }
      _dev_info(local_78,&DAT_0010e756,puVar10 + 0x6f);
    }
    else {
      _dev_err(local_78,"%s alg registration failed\n",puVar10 + 0x6f);
      kfree_sensitive(puVar10);
    }
LAB_001049c8:
    if (DAT_0010c92f == '\0') goto LAB_00105084;
    puVar10 = (undefined8 *)kmalloc_trace(__dev_err,0xdc0,0x640);
    if (puVar10 == (undefined8 *)0x0) goto LAB_00105020;
    *(undefined4 *)(puVar10 + 0xc0) = 2;
    memcpy(puVar10 + 0x88,&_qcrypto_aead_ccm_algo,0x1c0);
    puVar10[0xc1] = unaff_x25;
    if (puVar10 < (undefined8 *)0xfffffffffffff001) {
      if (DAT_0010c93a != '\0') {
        pcVar13 = (char *)(puVar10 + 0x97);
        sVar11 = strnlen(pcVar13,0x80);
        if (0x80 < sVar11) goto LAB_00105014;
        if (sVar11 == 0x80) goto LAB_00105008;
        local_6c = _qcrypto_prefix_alg_cra_name(pcVar13,sVar11);
        if (local_6c != 0) goto LAB_0010503c;
      }
      local_6c = crypto_register_aead(puVar10 + 0x88);
      puVar3 = DAT_0010c958;
      if (local_6c == 0) {
        uVar8 = __list_add_valid(puVar10,DAT_0010c958);
        if ((uVar8 & 1) != 0) {
          DAT_0010c958 = puVar10;
          *puVar10 = &DAT_0010c950;
          puVar10[1] = puVar3;
          *puVar3 = puVar10;
        }
        _dev_info(local_78,&DAT_0010e756,puVar10 + 0xa7);
      }
      else {
        _dev_err(local_78,"%s alg registration failed\n",puVar10 + 0xa7);
        kfree_sensitive(puVar10);
      }
      puVar10 = (undefined8 *)kmalloc_trace(__dev_err,0xdc0,0x640);
      if (puVar10 == (undefined8 *)0x0) goto LAB_00105020;
      *(undefined4 *)(puVar10 + 0xc0) = 2;
      memcpy(puVar10 + 0x88,&_qcrypto_aead_rfc4309_ccm_algo,0x1c0);
      puVar10[0xc1] = unaff_x25;
      if (puVar10 < (undefined8 *)0xfffffffffffff001) {
        if (DAT_0010c93a != '\0') {
          pcVar13 = (char *)(puVar10 + 0x97);
          sVar11 = strnlen(pcVar13,0x80);
          if (0x80 < sVar11) goto LAB_00105014;
          if (sVar11 == 0x80) goto LAB_00105008;
          local_6c = _qcrypto_prefix_alg_cra_name(pcVar13,sVar11);
          if (local_6c != 0) goto LAB_0010503c;
        }
        local_6c = crypto_register_aead(puVar10 + 0x88);
        puVar7 = DAT_0010c958;
        if (local_6c == 0) {
          uVar8 = __list_add_valid(puVar10,DAT_0010c958);
          if ((uVar8 & 1) != 0) {
            DAT_0010c958 = puVar10;
            *puVar10 = &DAT_0010c950;
            puVar10[1] = puVar7;
            *puVar7 = puVar10;
          }
          _dev_info(local_78,&DAT_0010e756,puVar10 + 0xa7);
        }
        else {
          _dev_err(local_78,"%s alg registration failed\n",puVar10 + 0xa7);
          kfree(puVar10);
        }
LAB_00105084:
        mutex_unlock(&DAT_0010c9b0);
        iVar6 = 0;
LAB_001046f0:
        lVar12 = sp_el0;
        if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail(iVar6);
        }
        return;
      }
    }
  }
LAB_00104d40:
  local_6c = (int)puVar10;
  lVar9 = unaff_x22;
  goto LAB_00104688;
}



//------------------------------------------------------------
// _qcrypto_remove @ 0010509c size=96
// signature: undefined _qcrypto_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_remove(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xa8);
  if (lVar2 != 0) {
    lVar1 = *(long *)(lVar2 + 0x20) + 0x98;
    mutex_lock(lVar1);
    _qcrypto_remove_engine(lVar2);
    mutex_unlock(lVar1);
    if (*(long *)(lVar2 + 0x10) != 0) {
      qce_close();
    }
    kfree_sensitive(lVar2);
  }
  return 0;
}



//------------------------------------------------------------
// _qcrypto_suspend @ 00105100 size=292
// signature: undefined _qcrypto_suspend(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _qcrypto_suspend(long param_1)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0xa8);
  if (lVar4 == 0) {
    return 0xffffffea;
  }
  if (*(char *)(*(long *)(lVar4 + 0x20) + 0x23) != '\0') {
    lVar1 = *(long *)(lVar4 + 0x20) + 0x34;
    uVar3 = _raw_spin_lock_irqsave(lVar1);
    if (*(int *)(lVar4 + 0x70) == 1) {
      if (((0 < *(int *)(lVar4 + 0x128)) || (*(int *)(lVar4 + 0x48) != 0)) ||
         (*(int *)(*(long *)(lVar4 + 0x20) + 0xe8) != 0)) goto LAB_001051d4;
      *(undefined4 *)(lVar4 + 0x70) = 5;
      _raw_spin_unlock_irqrestore(lVar1,uVar3);
      del_timer_sync(lVar4 + 0x78);
      qcrypto_ce_set_bus(lVar4,0);
      uVar3 = _raw_spin_lock_irqsave(lVar1);
    }
    else if ((*(int *)(lVar4 + 0x70) != 0) || (*(char *)(lVar4 + 0x74) != '\0')) {
LAB_001051d4:
      _raw_spin_unlock_irqrestore(lVar1,uVar3);
      return 0xfffffff0;
    }
    *(undefined4 *)(lVar4 + 0x70) = 4;
    _raw_spin_unlock_irqrestore(lVar1,uVar3);
    if (_qce_pm_table != (code *)0x0) {
      qcrypto_ce_set_bus(lVar4,1);
      if (*(int *)(_qce_pm_table + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x105194);
        (*pcVar2)();
      }
      (*_qce_pm_table)(*(undefined8 *)(lVar4 + 0x10));
      qcrypto_ce_set_bus(lVar4,0);
    }
  }
  return 0;
}



//------------------------------------------------------------
// _qcrypto_resume @ 00105228 size=308
// signature: undefined _qcrypto_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _qcrypto_resume(long param_1)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  
  lVar4 = *(long *)(param_1 + 0xa8);
  if (lVar4 == 0) {
    uVar6 = 0xffffffea;
  }
  else {
    lVar5 = *(long *)(lVar4 + 0x20);
    if (*(char *)(lVar5 + 0x23) == '\0') {
      uVar6 = 0;
    }
    else {
      lVar1 = lVar5 + 0x34;
      uVar3 = _raw_spin_lock_irqsave(lVar1);
      if (*(int *)(lVar4 + 0x70) == 4) {
        _raw_spin_unlock_irqrestore(lVar1,uVar3);
        if (_del_timer_sync != (code *)0x0) {
          qcrypto_ce_set_bus(lVar4,1);
          if (*(int *)(_del_timer_sync + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1052b0);
            (*pcVar2)();
          }
          (*_del_timer_sync)(*(undefined8 *)(lVar4 + 0x10));
          qcrypto_ce_set_bus(lVar4,0);
        }
        uVar3 = _raw_spin_lock_irqsave(lVar1);
        *(undefined4 *)(lVar4 + 0x70) = 0;
        *(undefined1 *)(lVar4 + 0x118) = 0;
        *(int *)(lVar4 + 0x110) = *(int *)(lVar4 + 0x110) + 1;
        if (((*(int *)(lVar5 + 0xe8) == 0) && (*(int *)(lVar4 + 0x48) == 0)) ||
           (*(char *)(lVar4 + 0x74) != '\0')) {
          uVar6 = 0;
        }
        else {
          queue_work_on(0x20,_system_wq,lVar4 + 0xe0);
          uVar6 = 0;
          *(undefined1 *)(lVar4 + 0x74) = 1;
        }
      }
      else {
        uVar6 = 0xfffffff0;
      }
      _raw_spin_unlock_irqrestore(lVar1,uVar3);
    }
  }
  return uVar6;
}



//------------------------------------------------------------
// qcrypto_bw_reaper_timer_callback @ 00105360 size=44
// signature: undefined qcrypto_bw_reaper_timer_callback(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcrypto_bw_reaper_timer_callback(long param_1)

{
  queue_work_on(0x20,_system_wq,param_1 + 0x38);
  return;
}



//------------------------------------------------------------
// qcrypto_bw_reaper_work @ 00105390 size=356
// signature: undefined qcrypto_bw_reaper_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcrypto_bw_reaper_work(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = *(long *)(param_1 + -0x90);
  lVar1 = lVar4 + 0x34;
  uVar3 = _raw_spin_lock_irqsave(lVar1);
  iVar2 = *(int *)(param_1 + 0x60);
  if ((*(int *)(param_1 + -0x40) == 1) && (iVar2 == *(int *)(param_1 + 100))) {
    if (*(int *)(param_1 + 0x78) < 1) {
      lVar5 = param_1 + -0xb0;
      *(undefined4 *)(param_1 + -0x40) = 2;
      _raw_spin_unlock_irqrestore(lVar1,uVar3);
      qcrypto_ce_set_bus(lVar5,0);
      uVar3 = _raw_spin_lock_irqsave(lVar1);
      if (*(char *)(param_1 + -0x3c) != '\0') {
        *(undefined4 *)(param_1 + -0x40) = 3;
        _raw_spin_unlock_irqrestore(lVar1,uVar3);
        qcrypto_ce_set_bus(lVar5,1);
        uVar3 = _raw_spin_lock_irqsave(lVar1);
        *(undefined4 *)(param_1 + -0x40) = 1;
        *(undefined1 *)(param_1 + -0x3c) = 0;
        *(int *)(param_1 + 100) = iVar2;
        _raw_spin_unlock_irqrestore(lVar1,uVar3);
        _start_qcrypto_process(lVar4,lVar5);
        iVar2 = *(int *)(param_1 + -0x40);
        goto joined_r0x00105408;
      }
      *(undefined4 *)(param_1 + -0x40) = 0;
    }
    else {
      if (*(char *)(param_1 + 0x68) != '\0') {
        _dev_warn(*(long *)(param_1 + -0x98) + 0x10,"The engine appears to be stuck seq %d.\n",iVar2
                 );
      }
      *(undefined1 *)(param_1 + 0x68) = 0;
    }
  }
  *(int *)(param_1 + 100) = iVar2;
  _raw_spin_unlock_irqrestore(lVar1,uVar3);
  iVar2 = *(int *)(param_1 + -0x40);
joined_r0x00105408:
  if (iVar2 != 0) {
    *(long *)(param_1 + -0x28) = _jiffies + 0xfa;
    mod_timer(param_1 + -0x38);
  }
  return;
}



//------------------------------------------------------------
// qcrypto_bw_allocate_work @ 001054f8 size=188
// signature: undefined qcrypto_bw_allocate_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcrypto_bw_allocate_work(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + -0xc0);
  lVar1 = lVar3 + 0x34;
  uVar2 = _raw_spin_lock_irqsave(lVar1);
  *(undefined4 *)(param_1 + -0x70) = 3;
  _raw_spin_unlock_irqrestore(lVar1,uVar2);
  qcrypto_ce_set_bus(param_1 + -0xe0,1);
  *(long *)(param_1 + -0x58) = _jiffies + 0xfa;
  mod_timer(param_1 + -0x68);
  uVar2 = _raw_spin_lock_irqsave(lVar1);
  *(undefined4 *)(param_1 + -0x70) = 1;
  *(undefined1 *)(param_1 + -0x6c) = 0;
  *(undefined1 *)(param_1 + 0x38) = 1;
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
  _raw_spin_unlock_irqrestore(lVar1,uVar2);
  _start_qcrypto_process(lVar3,param_1 + -0xe0);
  return;
}



//------------------------------------------------------------
// _qcrypto_prefix_alg_cra_name @ 001055b4 size=296
// signature: undefined _qcrypto_prefix_alg_cra_name(void)
// callers: [_qcrypto_probe]
//------------------------------------------------------------

void _qcrypto_prefix_alg_cra_name(void *param_1,uint param_2)

{
  long *plVar1;
  int iVar2;
  undefined8 uVar3;
  size_t __n;
  long *plVar4;
  ulong uVar5;
  long lVar6;
  long *plVar7;
  long lVar8;
  undefined4 local_a8;
  undefined8 local_a4;
  undefined8 local_9c;
  undefined8 local_94;
  undefined8 local_8c;
  undefined8 local_84;
  undefined8 local_7c;
  undefined8 local_74;
  undefined8 local_6c;
  undefined8 local_64;
  undefined8 local_5c;
  undefined8 local_54;
  undefined8 local_4c;
  undefined8 local_44;
  undefined8 local_3c;
  undefined8 local_34;
  undefined4 local_2c;
  long local_28;
  
  lVar8 = sp_el0;
  local_28 = *(long *)(lVar8 + 0x638);
  local_2c = 0;
  local_34 = 0;
  local_a8 = 0x6d6f6371;
  local_3c = 0;
  local_44 = 0;
  local_4c = 0;
  local_54 = 0;
  local_5c = 0;
  local_64 = 0;
  local_6c = 0;
  local_74 = 0;
  local_7c = 0;
  local_84 = 0;
  local_8c = 0;
  local_94 = 0;
  local_9c = 0;
  local_a4 = 0x2d;
  if (0x7a < param_2) {
    uVar3 = 0xffffffea;
LAB_0010568c:
    lVar8 = sp_el0;
    if (*(long *)(lVar8 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail(uVar3);
    }
    return;
  }
  strlcat(&local_a8,param_1,0x80);
  __n = strnlen((char *)&local_a8,0x80);
  if (__n < 0x81) {
    if (__n != 0xffffffffffffffff) {
      if (__n != 0x80) {
        memcpy(param_1,&local_a8,__n);
        uVar3 = 0;
        *(undefined1 *)((long)param_1 + __n) = 0;
        goto LAB_0010568c;
      }
      goto LAB_001056d0;
    }
  }
  else {
    fortify_panic("strnlen");
  }
  fortify_panic("strlcpy");
LAB_001056d0:
  plVar4 = (long *)fortify_panic("__fortify_strlen");
  lVar8 = plVar4[4];
  uVar3 = _raw_spin_lock_irqsave(lVar8 + 0x34);
  uVar5 = __list_del_entry_valid(plVar4);
  if ((uVar5 & 1) != 0) {
    lVar6 = *plVar4;
    plVar7 = (long *)plVar4[1];
    *(long **)(lVar6 + 8) = plVar7;
    *plVar7 = lVar6;
  }
  *plVar4 = -0x2152ffffffffff00;
  plVar4[1] = -0x2152fffffffffede;
  if (*(char *)((long)plVar4 + 0x12d) != '\0') {
    lVar6 = *(long *)(lVar8 + 0x80);
    *(undefined8 *)(lVar8 + 0x148) = 0;
    if (lVar6 != 0) {
      *(undefined1 *)(lVar6 + 0x12d) = 1;
      *(long *)(lVar8 + 0x148) = lVar6;
    }
  }
  if (*(long **)(lVar8 + 200) == plVar4) {
    *(undefined8 *)(lVar8 + 200) = 0;
  }
  if (*(long **)(lVar8 + 0x150) == plVar4) {
    *(undefined8 *)(lVar8 + 0x150) = 0;
  }
  _raw_spin_unlock_irqrestore(lVar8 + 0x34,uVar3);
  *(int *)(lVar8 + 0x90) = *(int *)(lVar8 + 0x90) + -1;
  cancel_work_sync(plVar4 + 0x16);
  cancel_work_sync(plVar4 + 0x1c);
  del_timer_sync(plVar4 + 0xf);
  if (plVar4[5] != 0) {
    icc_put();
  }
  plVar4[5] = 0;
  kfree_sensitive(plVar4[0x24]);
  if (*(int *)(lVar8 + 0x90) == 0) {
    plVar4 = *(long **)(lVar8 + 0x38);
    while (plVar4 != (long *)(lVar8 + 0x38)) {
      iVar2 = (int)plVar4[0xc0];
      plVar7 = (long *)*plVar4;
      if (iVar2 == 0) {
        crypto_unregister_skcipher(plVar4 + 8);
        iVar2 = (int)plVar4[0xc0];
      }
      if (iVar2 == 1) {
        crypto_unregister_ahash(plVar4 + 0x40);
        iVar2 = (int)plVar4[0xc0];
      }
      if (iVar2 == 2) {
        crypto_unregister_aead(plVar4 + 0x88);
      }
      uVar5 = __list_del_entry_valid(plVar4);
      if ((uVar5 & 1) != 0) {
        lVar6 = *plVar4;
        plVar1 = (long *)plVar4[1];
        *(long **)(lVar6 + 8) = plVar1;
        *plVar1 = lVar6;
      }
      *plVar4 = -0x2152ffffffffff00;
      plVar4[1] = -0x2152fffffffffede;
      kfree_sensitive(plVar4);
      plVar4 = plVar7;
    }
  }
  return;
}



//------------------------------------------------------------
// _qcrypto_remove_engine @ 001056dc size=408
// signature: undefined _qcrypto_remove_engine(void)
// callers: [_qcrypto_probe, _qcrypto_remove]
//------------------------------------------------------------

void _qcrypto_remove_engine(long *param_1)

{
  long *plVar1;
  long *plVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  long lVar6;
  long *plVar7;
  long lVar8;
  
  lVar8 = param_1[4];
  uVar4 = _raw_spin_lock_irqsave(lVar8 + 0x34);
  uVar5 = __list_del_entry_valid(param_1);
  if ((uVar5 & 1) != 0) {
    lVar6 = *param_1;
    plVar1 = (long *)param_1[1];
    *(long **)(lVar6 + 8) = plVar1;
    *plVar1 = lVar6;
  }
  *param_1 = -0x2152ffffffffff00;
  param_1[1] = -0x2152fffffffffede;
  if (*(char *)((long)param_1 + 0x12d) != '\0') {
    lVar6 = *(long *)(lVar8 + 0x80);
    *(undefined8 *)(lVar8 + 0x148) = 0;
    if (lVar6 != 0) {
      *(undefined1 *)(lVar6 + 0x12d) = 1;
      *(long *)(lVar8 + 0x148) = lVar6;
    }
  }
  if (*(long **)(lVar8 + 200) == param_1) {
    *(undefined8 *)(lVar8 + 200) = 0;
  }
  if (*(long **)(lVar8 + 0x150) == param_1) {
    *(undefined8 *)(lVar8 + 0x150) = 0;
  }
  _raw_spin_unlock_irqrestore(lVar8 + 0x34,uVar4);
  *(int *)(lVar8 + 0x90) = *(int *)(lVar8 + 0x90) + -1;
  cancel_work_sync(param_1 + 0x16);
  cancel_work_sync(param_1 + 0x1c);
  del_timer_sync(param_1 + 0xf);
  if (param_1[5] != 0) {
    icc_put();
  }
  param_1[5] = 0;
  kfree_sensitive(param_1[0x24]);
  if (*(int *)(lVar8 + 0x90) == 0) {
    plVar1 = *(long **)(lVar8 + 0x38);
    while (plVar1 != (long *)(lVar8 + 0x38)) {
      iVar3 = (int)plVar1[0xc0];
      plVar7 = (long *)*plVar1;
      if (iVar3 == 0) {
        crypto_unregister_skcipher(plVar1 + 8);
        iVar3 = (int)plVar1[0xc0];
      }
      if (iVar3 == 1) {
        crypto_unregister_ahash(plVar1 + 0x40);
        iVar3 = (int)plVar1[0xc0];
      }
      if (iVar3 == 2) {
        crypto_unregister_aead(plVar1 + 0x88);
      }
      uVar5 = __list_del_entry_valid(plVar1);
      if ((uVar5 & 1) != 0) {
        lVar6 = *plVar1;
        plVar2 = (long *)plVar1[1];
        *(long **)(lVar6 + 8) = plVar2;
        *plVar2 = lVar6;
      }
      *plVar1 = -0x2152ffffffffff00;
      plVar1[1] = -0x2152fffffffffede;
      kfree_sensitive(plVar1);
      plVar1 = plVar7;
    }
  }
  return;
}



//------------------------------------------------------------
// qcrypto_ce_set_bus @ 00105874 size=452
// signature: undefined qcrypto_ce_set_bus(void)
// callers: [_qcrypto_resume, qcrypto_bw_allocate_work, qcrypto_bw_reaper_work, _qcrypto_suspend]
//------------------------------------------------------------

void qcrypto_ce_set_bus(long param_1,ulong param_2)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  bVar1 = (param_2 & 1) == 0;
  uVar4 = 2;
  if (bVar1) {
    uVar4 = 3;
  }
  uVar5 = 4;
  if (!bVar1) {
    uVar5 = 1;
  }
  if (*(char *)(*(long *)(param_1 + 0x20) + 0x24) != '\0') {
    uVar5 = uVar4;
  }
  switch(uVar5) {
  case 1:
    iVar2 = qce_enable_clk(*(undefined8 *)(param_1 + 0x10));
    if (iVar2 == 0) {
      iVar2 = icc_set_bw(*(undefined8 *)(param_1 + 0x28),0x180,0x180);
      if (iVar2 == 0) {
        return;
      }
      _printk(&DAT_0010de2c,"qcrypto_ce_set_bus");
      iVar2 = qce_disable_clk(*(undefined8 *)(param_1 + 0x10));
      if (iVar2 == 0) {
        return;
      }
      puVar3 = &DAT_0010e26e;
    }
    else {
LAB_001059a8:
      puVar3 = &DAT_0010dd56;
    }
    break;
  case 2:
    iVar2 = icc_set_bw(*(undefined8 *)(param_1 + 0x28),0x180,0x180);
    if (iVar2 == 0) {
      iVar2 = qce_enable_clk(*(undefined8 *)(param_1 + 0x10));
      if (iVar2 == 0) {
        return;
      }
      _printk(&DAT_0010dd56,"qcrypto_ce_set_bus");
      iVar2 = icc_set_bw(*(undefined8 *)(param_1 + 0x28),0,0);
      if (iVar2 == 0) {
        return;
      }
      goto LAB_00105a08;
    }
LAB_001059fc:
    puVar3 = &DAT_0010de2c;
    break;
  case 3:
    iVar2 = qce_disable_clk(*(undefined8 *)(param_1 + 0x10));
    if (iVar2 == 0) {
      iVar2 = icc_set_bw(*(undefined8 *)(param_1 + 0x28),0,0);
      if (iVar2 == 0) {
        return;
      }
      _printk(&DAT_0010e77f,"qcrypto_ce_set_bus");
      iVar2 = qce_enable_clk(*(undefined8 *)(param_1 + 0x10));
      if (iVar2 == 0) {
        return;
      }
      goto LAB_001059a8;
    }
    puVar3 = &DAT_0010e662;
    break;
  case 4:
    iVar2 = icc_set_bw(*(undefined8 *)(param_1 + 0x28),0,0);
    if (iVar2 == 0) {
      iVar2 = qce_disable_clk(*(undefined8 *)(param_1 + 0x10));
      if (iVar2 == 0) {
        return;
      }
      _printk(&DAT_0010e662,"qcrypto_ce_set_bus");
      iVar2 = icc_set_bw(*(undefined8 *)(param_1 + 0x28),0x180,0x180);
      if (iVar2 == 0) {
        return;
      }
      goto LAB_001059fc;
    }
LAB_00105a08:
    puVar3 = &DAT_0010e77f;
    break;
  default:
    goto switchD_001058cc_default;
  }
  _printk(puVar3,"qcrypto_ce_set_bus");
switchD_001058cc_default:
  return;
}



//------------------------------------------------------------
// _qcrypto_setkey_aes @ 00105a3c size=192
// signature: undefined _qcrypto_setkey_aes(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_setkey_aes(long param_1,void *param_2,uint param_3)

{
  undefined8 uVar1;
  long lVar2;
  
  if ((*(uint *)(param_1 + 0xa0) & 1) == 0) {
    if ((param_3 != 0x10) && (param_3 != 0x20)) {
      if (param_3 != 0x18) {
        return 0xffffffea;
      }
      if (*(char *)(*(long *)(param_1 + 0x98) + 0x15) == '\0') {
        lVar2 = *(long *)(param_1 + 0x148);
        if (lVar2 == 0) {
          return 0xffffffea;
        }
        *(undefined4 *)(param_1 + 0x138) = 0x18;
        *(uint *)(lVar2 + 0x40) = *(uint *)(lVar2 + 0x40) & 0xfff000ff;
        *(uint *)(*(long *)(param_1 + 0x148) + 0x40) =
             *(uint *)(*(long *)(param_1 + 0x148) + 0x40) | *(uint *)(param_1 + 0x40) & 0xfff00;
        uVar1 = crypto_skcipher_setkey(*(undefined8 *)(param_1 + 0x148),param_2,0x18);
        return uVar1;
      }
    }
    *(uint *)(param_1 + 0x138) = param_3;
    if ((*(uint *)(param_1 + 0xa0) >> 1 & 1) == 0) {
      if (param_2 == (void *)0x0) {
        _printk(&DAT_0010dd77,"_qcrypto_setkey_aes");
        return 0xffffffea;
      }
      memcpy((void *)(param_1 + 0xf8),param_2,(ulong)param_3);
    }
  }
  return 0;
}



//------------------------------------------------------------
// _qcrypto_enc_aes_ecb @ 00105b00 size=320
// signature: undefined _qcrypto_enc_aes_ecb(void)
// callers: []
//------------------------------------------------------------

undefined4 _qcrypto_enc_aes_ecb(undefined4 *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  undefined4 local_240 [2];
  undefined8 local_238;
  undefined8 local_230;
  undefined8 uStack_228;
  undefined8 local_210;
  undefined8 uStack_208;
  long local_200;
  undefined4 local_1f8;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar4 = *(long *)(param_1 + 0x10);
  lVar3 = *(long *)(lVar4 + 0x58);
  if ((*(uint *)(*(long *)(lVar4 + 0x10) + 0x20) & 0xf) != 5) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x105c3c);
    (*pcVar1)();
  }
  if (((*(int *)(lVar4 + 0xf8) == 0x18) && (*(char *)(lVar3 + 0x15) == '\0')) &&
     (*(long *)(lVar4 + 0x108) != 0)) {
    lVar3 = *(long *)(param_1 + 0x10);
    memset(local_240,0,0x200);
    local_1f8 = param_1[0x12];
    local_210 = 0;
    uStack_208 = 0;
    uStack_228 = *(undefined8 *)(param_1 + 6);
    local_240[0] = *param_1;
    local_200 = *(long *)(lVar3 + 0x108) + 0x40;
    local_238 = *(undefined8 *)(param_1 + 2);
    local_230 = *(undefined8 *)(param_1 + 4);
    uVar2 = crypto_skcipher_encrypt(local_240);
    memset(local_240,0,(ulong)*(uint *)(local_200 + -0x40) + 0x80);
  }
  else {
    param_1[0x33] = 0;
    *(undefined8 *)(param_1 + 0x40) = 2;
    param_1[0x42] = 1;
    DAT_0010db68 = DAT_0010db68 + 1;
    uVar2 = _qcrypto_queue_req(lVar3,*(undefined8 *)(lVar4 + 0x50),param_1 + 8);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// _qcrypto_dec_aes_ecb @ 00105c48 size=324
// signature: undefined _qcrypto_dec_aes_ecb(void)
// callers: []
//------------------------------------------------------------

undefined4 _qcrypto_dec_aes_ecb(undefined4 *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  undefined4 local_240 [2];
  undefined8 local_238;
  undefined8 local_230;
  undefined8 uStack_228;
  undefined8 local_210;
  undefined8 uStack_208;
  long local_200;
  undefined4 local_1f8;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar4 = *(long *)(param_1 + 0x10);
  lVar3 = *(long *)(lVar4 + 0x58);
  if ((*(uint *)(*(long *)(lVar4 + 0x10) + 0x20) & 0xf) != 5) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x105d88);
    (*pcVar1)();
  }
  if (((*(int *)(lVar4 + 0xf8) == 0x18) && (*(char *)(lVar3 + 0x15) == '\0')) &&
     (*(long *)(lVar4 + 0x108) != 0)) {
    lVar3 = *(long *)(param_1 + 0x10);
    memset(local_240,0,0x200);
    local_1f8 = param_1[0x12];
    local_210 = 0;
    uStack_208 = 0;
    uStack_228 = *(undefined8 *)(param_1 + 6);
    local_240[0] = *param_1;
    local_200 = *(long *)(lVar3 + 0x108) + 0x40;
    local_238 = *(undefined8 *)(param_1 + 2);
    local_230 = *(undefined8 *)(param_1 + 4);
    uVar2 = crypto_skcipher_decrypt(local_240);
    memset(local_240,0,(ulong)*(uint *)(local_200 + -0x40) + 0x80);
  }
  else {
    param_1[0x33] = 0;
    *(undefined8 *)(param_1 + 0x40) = 0x100000002;
    param_1[0x42] = 1;
    DAT_0010db70 = DAT_0010db70 + 1;
    uVar2 = _qcrypto_queue_req(lVar3,*(undefined8 *)(lVar4 + 0x50),param_1 + 8);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// _qcrypto_aes_skcipher_init @ 00105d94 size=228
// signature: undefined _qcrypto_aes_skcipher_init(void)
// callers: []
//------------------------------------------------------------

undefined4 _qcrypto_aes_skcipher_init(undefined4 *param_1)

{
  undefined4 uVar1;
  ulong uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x14);
  if (DAT_0010c935 == '\0') {
    uVar2 = crypto_alloc_sync_skcipher(lVar3 + 0x38,0,0x180);
    *(ulong *)(param_1 + 0x52) = uVar2;
    if (0xfffffffffffff000 < uVar2) {
      _printk(&DAT_0010e75a,lVar3 + 0x38);
      uVar1 = param_1[0x52];
      *(undefined8 *)(param_1 + 0x52) = 0;
      return uVar1;
    }
    lVar3 = *(long *)(param_1 + 0x14);
  }
  else {
    *(undefined8 *)(param_1 + 0x52) = 0;
  }
  *param_1 = 0x1c8;
  if (lVar3 == 0x80) {
    _printk(&DAT_0010e48d);
    uVar1 = 0xffffffea;
  }
  else {
    param_1[0x28] = 0;
    *(undefined8 *)(param_1 + 0x26) = *(undefined8 *)(lVar3 + 0x588);
    get_random_bytes(param_1 + 0x3a,0x10);
    uVar1 = 0;
    *(undefined8 *)(param_1 + 0x24) = 0;
    *(undefined4 **)(param_1 + 0x20) = param_1 + 0x20;
    *(undefined4 **)(param_1 + 0x22) = param_1 + 0x20;
    param_1[0x29] = 5;
  }
  return uVar1;
}



//------------------------------------------------------------
// _qcrypto_aes_skcipher_exit @ 00105e7c size=96
// signature: undefined _qcrypto_aes_skcipher_exit(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_aes_skcipher_exit(long param_1)

{
  long lVar1;
  
  if (*(long **)(param_1 + 0x80) == (long *)(param_1 + 0x80)) {
    lVar1 = *(long *)(param_1 + 0x148);
  }
  else {
    _printk(&DAT_0010e969);
    lVar1 = *(long *)(param_1 + 0x148);
  }
  if (lVar1 != 0) {
    crypto_destroy_tfm(lVar1,lVar1 + 0x40);
  }
  *(undefined8 *)(param_1 + 0x148) = 0;
  return;
}



//------------------------------------------------------------
// _qcrypto_enc_aes_cbc @ 00105ee0 size=316
// signature: undefined _qcrypto_enc_aes_cbc(void)
// callers: []
//------------------------------------------------------------

undefined4 _qcrypto_enc_aes_cbc(undefined4 *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  undefined4 local_240 [2];
  undefined8 local_238;
  undefined8 local_230;
  undefined8 uStack_228;
  undefined8 local_210;
  undefined8 uStack_208;
  long local_200;
  undefined4 local_1f8;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar4 = *(long *)(param_1 + 0x10);
  lVar3 = *(long *)(lVar4 + 0x58);
  if ((*(uint *)(*(long *)(lVar4 + 0x10) + 0x20) & 0xf) != 5) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x106018);
    (*pcVar1)();
  }
  if (((*(int *)(lVar4 + 0xf8) == 0x18) && (*(char *)(lVar3 + 0x15) == '\0')) &&
     (*(long *)(lVar4 + 0x108) != 0)) {
    lVar3 = *(long *)(param_1 + 0x10);
    memset(local_240,0,0x200);
    local_1f8 = param_1[0x12];
    local_210 = 0;
    uStack_208 = 0;
    uStack_228 = *(undefined8 *)(param_1 + 6);
    local_240[0] = *param_1;
    local_200 = *(long *)(lVar3 + 0x108) + 0x40;
    local_238 = *(undefined8 *)(param_1 + 2);
    local_230 = *(undefined8 *)(param_1 + 4);
    uVar2 = crypto_skcipher_encrypt(local_240);
    memset(local_240,0,(ulong)*(uint *)(local_200 + -0x40) + 0x80);
  }
  else {
    param_1[0x33] = 0;
    param_1[0x42] = 0;
    *(undefined8 *)(param_1 + 0x40) = 2;
    DAT_0010db68 = DAT_0010db68 + 1;
    uVar2 = _qcrypto_queue_req(lVar3,*(undefined8 *)(lVar4 + 0x50),param_1 + 8);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// _qcrypto_dec_aes_cbc @ 00106024 size=320
// signature: undefined _qcrypto_dec_aes_cbc(void)
// callers: []
//------------------------------------------------------------

undefined4 _qcrypto_dec_aes_cbc(undefined4 *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  undefined4 local_240 [2];
  undefined8 local_238;
  undefined8 local_230;
  undefined8 uStack_228;
  undefined8 local_210;
  undefined8 uStack_208;
  long local_200;
  undefined4 local_1f8;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar4 = *(long *)(param_1 + 0x10);
  lVar3 = *(long *)(lVar4 + 0x58);
  if ((*(uint *)(*(long *)(lVar4 + 0x10) + 0x20) & 0xf) != 5) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x106160);
    (*pcVar1)();
  }
  if (((*(int *)(lVar4 + 0xf8) == 0x18) && (*(char *)(lVar3 + 0x15) == '\0')) &&
     (*(long *)(lVar4 + 0x108) != 0)) {
    lVar3 = *(long *)(param_1 + 0x10);
    memset(local_240,0,0x200);
    local_1f8 = param_1[0x12];
    local_210 = 0;
    uStack_208 = 0;
    uStack_228 = *(undefined8 *)(param_1 + 6);
    local_240[0] = *param_1;
    local_200 = *(long *)(lVar3 + 0x108) + 0x40;
    local_238 = *(undefined8 *)(param_1 + 2);
    local_230 = *(undefined8 *)(param_1 + 4);
    uVar2 = crypto_skcipher_decrypt(local_240);
    memset(local_240,0,(ulong)*(uint *)(local_200 + -0x40) + 0x80);
  }
  else {
    param_1[0x33] = 0;
    param_1[0x42] = 0;
    *(undefined8 *)(param_1 + 0x40) = 0x100000002;
    DAT_0010db70 = DAT_0010db70 + 1;
    uVar2 = _qcrypto_queue_req(lVar3,*(undefined8 *)(lVar4 + 0x50),param_1 + 8);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// _qcrypto_enc_aes_ctr @ 0010616c size=316
// signature: undefined _qcrypto_enc_aes_ctr(void)
// callers: []
//------------------------------------------------------------

undefined4 _qcrypto_enc_aes_ctr(undefined4 *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  undefined4 local_240 [2];
  undefined8 local_238;
  undefined8 local_230;
  undefined8 uStack_228;
  undefined8 local_210;
  undefined8 uStack_208;
  long local_200;
  undefined4 local_1f8;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar4 = *(long *)(param_1 + 0x10);
  lVar3 = *(long *)(lVar4 + 0x58);
  if ((*(uint *)(*(long *)(lVar4 + 0x10) + 0x20) & 0xf) != 5) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1062a4);
    (*pcVar1)();
  }
  if (((*(int *)(lVar4 + 0xf8) == 0x18) && (*(char *)(lVar3 + 0x15) == '\0')) &&
     (*(long *)(lVar4 + 0x108) != 0)) {
    lVar3 = *(long *)(param_1 + 0x10);
    memset(local_240,0,0x200);
    local_1f8 = param_1[0x12];
    local_210 = 0;
    uStack_208 = 0;
    uStack_228 = *(undefined8 *)(param_1 + 6);
    local_240[0] = *param_1;
    local_200 = *(long *)(lVar3 + 0x108) + 0x40;
    local_238 = *(undefined8 *)(param_1 + 2);
    local_230 = *(undefined8 *)(param_1 + 4);
    uVar2 = crypto_skcipher_encrypt(local_240);
    memset(local_240,0,(ulong)*(uint *)(local_200 + -0x40) + 0x80);
  }
  else {
    param_1[0x33] = 0;
    *(undefined8 *)(param_1 + 0x40) = 2;
    param_1[0x42] = 2;
    DAT_0010db68 = DAT_0010db68 + 1;
    uVar2 = _qcrypto_queue_req(lVar3,*(undefined8 *)(lVar4 + 0x50),param_1 + 8);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// _qcrypto_dec_aes_ctr @ 001062b0 size=316
// signature: undefined _qcrypto_dec_aes_ctr(void)
// callers: []
//------------------------------------------------------------

undefined4 _qcrypto_dec_aes_ctr(undefined4 *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  undefined4 local_240 [2];
  undefined8 local_238;
  undefined8 local_230;
  undefined8 uStack_228;
  undefined8 local_210;
  undefined8 uStack_208;
  long local_200;
  undefined4 local_1f8;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar4 = *(long *)(param_1 + 0x10);
  lVar3 = *(long *)(lVar4 + 0x58);
  if ((*(uint *)(*(long *)(lVar4 + 0x10) + 0x20) & 0xf) != 5) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1063e8);
    (*pcVar1)();
  }
  if (((*(int *)(lVar4 + 0xf8) == 0x18) && (*(char *)(lVar3 + 0x15) == '\0')) &&
     (*(long *)(lVar4 + 0x108) != 0)) {
    lVar3 = *(long *)(param_1 + 0x10);
    memset(local_240,0,0x200);
    local_1f8 = param_1[0x12];
    local_210 = 0;
    uStack_208 = 0;
    uStack_228 = *(undefined8 *)(param_1 + 6);
    local_240[0] = *param_1;
    local_200 = *(long *)(lVar3 + 0x108) + 0x40;
    local_238 = *(undefined8 *)(param_1 + 2);
    local_230 = *(undefined8 *)(param_1 + 4);
    uVar2 = crypto_skcipher_decrypt(local_240);
    memset(local_240,0,(ulong)*(uint *)(local_200 + -0x40) + 0x80);
  }
  else {
    param_1[0x33] = 0;
    *(undefined8 *)(param_1 + 0x40) = 2;
    param_1[0x42] = 2;
    DAT_0010db70 = DAT_0010db70 + 1;
    uVar2 = _qcrypto_queue_req(lVar3,*(undefined8 *)(lVar4 + 0x50),param_1 + 8);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// _qcrypto_setkey_des @ 001063f4 size=136
// signature: undefined _qcrypto_setkey_des(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_setkey_des(long param_1,undefined8 *param_2,int param_3)

{
  if (param_2 == (undefined8 *)0x0) {
    _printk(&DAT_0010dd77,"_qcrypto_setkey_des");
    return 0xffffffea;
  }
  if ((*(uint *)(param_1 + 0xa0) & 1) == 0) {
    if (param_3 != 8) {
      return 0xffffffea;
    }
    *(undefined4 *)(param_1 + 0x138) = 8;
    if ((*(uint *)(param_1 + 0xa0) >> 1 & 1) == 0) {
      *(undefined8 *)(param_1 + 0xf8) = *param_2;
      return 0;
    }
  }
  else {
    _printk(&DAT_0010e129,"_qcrypto_setkey_des");
  }
  return 0;
}



//------------------------------------------------------------
// _qcrypto_enc_des_ecb @ 00106480 size=104
// signature: undefined _qcrypto_enc_des_ecb(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_enc_des_ecb(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x40);
  uVar2 = *(undefined8 *)(lVar3 + 0x58);
  if ((*(uint *)(*(long *)(lVar3 + 0x10) + 0x20) & 0xf) != 5) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1064e8);
    (*pcVar1)();
  }
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0x108) = 1;
  DAT_0010db78 = DAT_0010db78 + 1;
  _qcrypto_queue_req(uVar2,*(undefined8 *)(lVar3 + 0x50),param_1 + 0x20);
  return;
}



//------------------------------------------------------------
// _qcrypto_dec_des_ecb @ 001064f0 size=108
// signature: undefined _qcrypto_dec_des_ecb(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_dec_des_ecb(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x40);
  uVar2 = *(undefined8 *)(lVar3 + 0x58);
  if ((*(uint *)(*(long *)(lVar3 + 0x10) + 0x20) & 0xf) != 5) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10655c);
    (*pcVar1)();
  }
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0x100000000;
  *(undefined4 *)(param_1 + 0x108) = 1;
  DAT_0010db80 = DAT_0010db80 + 1;
  _qcrypto_queue_req(uVar2,*(undefined8 *)(lVar3 + 0x50),param_1 + 0x20);
  return;
}



//------------------------------------------------------------
// _qcrypto_skcipher_init @ 00106564 size=144
// signature: undefined _qcrypto_skcipher_init(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_skcipher_init(undefined4 *param_1)

{
  undefined8 uVar1;
  
  *param_1 = 0x1c8;
  if ((param_1 + 0x20 == (undefined4 *)0x0) || (*(long *)(param_1 + 0x14) == 0x80)) {
    _printk(&DAT_0010e48d);
    uVar1 = 0xffffffea;
  }
  else {
    param_1[0x28] = 0;
    *(undefined8 *)(param_1 + 0x26) = *(undefined8 *)(*(long *)(param_1 + 0x14) + 0x588);
    get_random_bytes(param_1 + 0x3a,0x10);
    uVar1 = 0;
    *(undefined8 *)(param_1 + 0x24) = 0;
    *(undefined4 **)(param_1 + 0x20) = param_1 + 0x20;
    *(undefined4 **)(param_1 + 0x22) = param_1 + 0x20;
    param_1[0x29] = 5;
  }
  return uVar1;
}



//------------------------------------------------------------
// _qcrypto_skcipher_exit @ 001065f8 size=52
// signature: undefined _qcrypto_skcipher_exit(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_skcipher_exit(long param_1)

{
  if (*(long **)(param_1 + 0x80) != (long *)(param_1 + 0x80)) {
    _printk(&DAT_0010e969);
  }
  return;
}



//------------------------------------------------------------
// _qcrypto_enc_des_cbc @ 00106630 size=100
// signature: undefined _qcrypto_enc_des_cbc(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_enc_des_cbc(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x40);
  uVar2 = *(undefined8 *)(lVar3 + 0x58);
  if ((*(uint *)(*(long *)(lVar3 + 0x10) + 0x20) & 0xf) != 5) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x106694);
    (*pcVar1)();
  }
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  DAT_0010db78 = DAT_0010db78 + 1;
  _qcrypto_queue_req(uVar2,*(undefined8 *)(lVar3 + 0x50),param_1 + 0x20);
  return;
}



//------------------------------------------------------------
// _qcrypto_dec_des_cbc @ 0010669c size=104
// signature: undefined _qcrypto_dec_des_cbc(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_dec_des_cbc(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x40);
  uVar2 = *(undefined8 *)(lVar3 + 0x58);
  if ((*(uint *)(*(long *)(lVar3 + 0x10) + 0x20) & 0xf) != 5) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x106704);
    (*pcVar1)();
  }
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0x100000000;
  DAT_0010db80 = DAT_0010db80 + 1;
  _qcrypto_queue_req(uVar2,*(undefined8 *)(lVar3 + 0x50),param_1 + 0x20);
  return;
}



//------------------------------------------------------------
// _qcrypto_setkey_3des @ 0010670c size=144
// signature: undefined _qcrypto_setkey_3des(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_setkey_3des(long param_1,undefined8 *param_2,int param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if ((*(uint *)(param_1 + 0xa0) & 1) != 0) {
    _printk(&DAT_0010e3db,"_qcrypto_setkey_3des");
    return 0;
  }
  if (param_3 == 0x18) {
    *(undefined4 *)(param_1 + 0x138) = 0x18;
    if ((*(uint *)(param_1 + 0xa0) >> 1 & 1) != 0) {
      return 0;
    }
    if (param_2 != (undefined8 *)0x0) {
      uVar1 = param_2[2];
      uVar2 = *param_2;
      *(undefined8 *)(param_1 + 0x100) = param_2[1];
      *(undefined8 *)(param_1 + 0x108) = uVar1;
      *(undefined8 *)(param_1 + 0xf8) = uVar2;
      return 0;
    }
    _printk(&DAT_0010dd77,"_qcrypto_setkey_3des");
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// _qcrypto_enc_3des_ecb @ 001067a0 size=104
// signature: undefined _qcrypto_enc_3des_ecb(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_enc_3des_ecb(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x40);
  uVar2 = *(undefined8 *)(lVar3 + 0x58);
  if ((*(uint *)(*(long *)(lVar3 + 0x10) + 0x20) & 0xf) != 5) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x106808);
    (*pcVar1)();
  }
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined8 *)(param_1 + 0x100) = 1;
  *(undefined4 *)(param_1 + 0x108) = 1;
  DAT_0010db88 = DAT_0010db88 + 1;
  _qcrypto_queue_req(uVar2,*(undefined8 *)(lVar3 + 0x50),param_1 + 0x20);
  return;
}



//------------------------------------------------------------
// _qcrypto_dec_3des_ecb @ 00106810 size=108
// signature: undefined _qcrypto_dec_3des_ecb(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_dec_3des_ecb(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x40);
  uVar2 = *(undefined8 *)(lVar3 + 0x58);
  if ((*(uint *)(*(long *)(lVar3 + 0x10) + 0x20) & 0xf) != 5) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10687c);
    (*pcVar1)();
  }
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0x100000001;
  *(undefined4 *)(param_1 + 0x108) = 1;
  DAT_0010db90 = DAT_0010db90 + 1;
  _qcrypto_queue_req(uVar2,*(undefined8 *)(lVar3 + 0x50),param_1 + 0x20);
  return;
}



//------------------------------------------------------------
// _qcrypto_enc_3des_cbc @ 00106884 size=104
// signature: undefined _qcrypto_enc_3des_cbc(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_enc_3des_cbc(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x40);
  uVar2 = *(undefined8 *)(lVar3 + 0x58);
  if ((*(uint *)(*(long *)(lVar3 + 0x10) + 0x20) & 0xf) != 5) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1068ec);
    (*pcVar1)();
  }
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined8 *)(param_1 + 0x100) = 1;
  DAT_0010db88 = DAT_0010db88 + 1;
  _qcrypto_queue_req(uVar2,*(undefined8 *)(lVar3 + 0x50),param_1 + 0x20);
  return;
}



//------------------------------------------------------------
// _qcrypto_dec_3des_cbc @ 001068f4 size=104
// signature: undefined _qcrypto_dec_3des_cbc(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_dec_3des_cbc(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x40);
  uVar2 = *(undefined8 *)(lVar3 + 0x58);
  if ((*(uint *)(*(long *)(lVar3 + 0x10) + 0x20) & 0xf) != 5) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10695c);
    (*pcVar1)();
  }
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0x100000001;
  DAT_0010db90 = DAT_0010db90 + 1;
  _qcrypto_queue_req(uVar2,*(undefined8 *)(lVar3 + 0x50),param_1 + 0x20);
  return;
}



//------------------------------------------------------------
// _qcrypto_queue_req @ 00106960 size=432
// signature: undefined _qcrypto_queue_req(void)
// callers: [_qcrypto_enc_3des_cbc, _sha_hmac_inner_hash, _qcrypto_aead_decrypt_aes_ccm, _sha_final, _sha256_hmac_final, _qcrypto_enc_aes_ecb, _sha_update, _sha1_hmac_digest, _sha1_digest, _sha256_hmac_digest, _qcrypto_enc_des_ecb, _sha256_digest, _qcrypto_aead_rfc4309_dec_aes_ccm, _qcrypto_dec_des_ecb, _qcrypto_enc_des_cbc, _qcrypto_aead_decrypt_3des_cbc, _qcrypto_enc_aes_cbc, _qcrypto_aead_encrypt_aes_ccm, _qcrypto_dec_des_cbc, _qcrypto_dec_3des_ecb, _sha_hmac_setkey, _sha1_hmac_final, _qcrypto_enc_aes_xts, _qcrypto_aead_decrypt_aes_cbc, _qcrypto_aead_encrypt_des_cbc, _qcrypto_dec_aes_ctr, _qcrypto_aead_encrypt_aes_cbc, _qcrypto_enc_aes_ctr, _qcrypto_enc_3des_ecb, _qcrypto_aead_decrypt_des_cbc, _qcrypto_dec_aes_xts, _qcrypto_dec_aes_ecb, _qcrypto_aead_rfc4309_enc_aes_ccm, _qcrypto_dec_aes_cbc, _qcrypto_dec_3des_cbc, _qcrypto_aead_encrypt_3des_cbc]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _qcrypto_queue_req(long param_1,long *param_2,undefined8 param_3)

{
  long lVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  int iVar7;
  
  lVar1 = param_1 + 0x34;
  uVar3 = _raw_spin_lock_irqsave(lVar1);
  if (param_2 == (long *)0x0) {
    uVar2 = crypto_enqueue_request(param_1 + 0xd0,param_3);
    plVar4 = (long *)(param_1 + 0x80);
    plVar5 = (long *)*plVar4;
    if (plVar5 == plVar4) {
      _printk(&DAT_0010dfab,"_avail_eng");
      param_2 = (long *)0x0;
    }
    else {
      if ((*(undefined8 **)(param_1 + 0x150) == (undefined8 *)0x0) ||
         (plVar6 = (long *)**(undefined8 **)(param_1 + 0x150), plVar6 == plVar4)) {
        plVar6 = plVar5;
      }
      iVar7 = *(int *)(param_1 + 0x90) + 1;
      param_2 = plVar6;
      do {
        iVar7 = iVar7 + -1;
        if (iVar7 < 1) break;
        if ((*(char *)((long)param_2 + 300) == '\0') &&
           (*(uint *)(param_2 + 0x25) < *(uint *)((long)param_2 + 0x11c))) goto LAB_00106a3c;
        if ((param_2 == (long *)0x0) || (param_2 = (long *)*param_2, param_2 == plVar4)) {
          param_2 = plVar5;
        }
      } while (plVar6 != param_2);
      param_2 = (long *)0x0;
LAB_00106a3c:
      *(long **)(param_1 + 0x150) = param_2;
    }
    if (*(uint *)(param_1 + 0x164) < *(uint *)(param_1 + 0xe8)) {
      *(uint *)(param_1 + 0x164) = *(uint *)(param_1 + 0xe8);
    }
    if (param_2 == (long *)0x0) {
      *(int *)(param_1 + 0x158) = *(int *)(param_1 + 0x158) + 1;
      goto LAB_00106acc;
    }
  }
  else {
    uVar2 = crypto_enqueue_request(param_2 + 6,param_3);
  }
  iVar7 = (int)param_2[0xe];
  if (iVar7 != 2) {
    if (iVar7 == 1) {
      _raw_spin_unlock_irqrestore(lVar1,uVar3);
      if (*(int *)(param_1 + 0x13c) == 1) {
        _start_qcrypto_process(param_1,param_2);
        return uVar2;
      }
      return uVar2;
    }
    if ((iVar7 != 0) || (*(char *)((long)param_2 + 0x74) != '\0')) goto LAB_00106acc;
    queue_work_on(0x20,_system_wq,param_2 + 0x1c);
  }
  *(undefined1 *)((long)param_2 + 0x74) = 1;
LAB_00106acc:
  _raw_spin_unlock_irqrestore(lVar1,uVar3);
  return uVar2;
}



//------------------------------------------------------------
// _qcrypto_setkey_aes_xts @ 00106b14 size=220
// signature: undefined _qcrypto_setkey_aes_xts(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_setkey_aes_xts(long param_1,void *param_2,ulong param_3)

{
  code *pcVar1;
  uint uVar2;
  
  if ((*(uint *)(param_1 + 0xa0) & 1) == 0) {
    uVar2 = (uint)(param_3 >> 1) & 0x7fffffff;
    if (((uVar2 != 0x10) && (uVar2 != 0x20)) &&
       ((uVar2 != 0x18 || (*(char *)(*(long *)(param_1 + 0x98) + 0x15) == '\0')))) {
      return 0xffffffea;
    }
    *(uint *)(param_1 + 0x138) = (uint)param_3;
    if ((*(uint *)(param_1 + 0xa0) >> 1 & 1) == 0) {
      if (param_2 == (void *)0x0) {
        _printk(&DAT_0010dd77,"_qcrypto_setkey_aes_xts");
        return 0xffffffea;
      }
      if ((0x40 < (uint)param_3) && ((_qcrypto_setkey_aes_xts___already_done & 1) == 0)) {
        _qcrypto_setkey_aes_xts___already_done = 1;
        __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
                      param_3 & 0xffffffff,
                      "field \"ctx->enc_key\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcrypto.c:1475"
                      ,0x40);
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x800,0x106bf0);
        (*pcVar1)();
      }
      memcpy((void *)(param_1 + 0xf8),param_2,param_3 & 0xffffffff);
    }
  }
  return 0;
}



//------------------------------------------------------------
// _qcrypto_enc_aes_xts @ 00106bf8 size=108
// signature: undefined _qcrypto_enc_aes_xts(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_enc_aes_xts(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x40);
  uVar2 = *(undefined8 *)(lVar3 + 0x58);
  if ((*(uint *)(*(long *)(lVar3 + 0x10) + 0x20) & 0xf) != 5) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x106c64);
    (*pcVar1)();
  }
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined8 *)(param_1 + 0x100) = 2;
  *(undefined4 *)(param_1 + 0x108) = 3;
  DAT_0010db68 = DAT_0010db68 + 1;
  _qcrypto_queue_req(uVar2,*(undefined8 *)(lVar3 + 0x50),param_1 + 0x20);
  return;
}



//------------------------------------------------------------
// _qcrypto_dec_aes_xts @ 00106c6c size=112
// signature: undefined _qcrypto_dec_aes_xts(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_dec_aes_xts(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x40);
  uVar2 = *(undefined8 *)(lVar3 + 0x58);
  if ((*(uint *)(*(long *)(lVar3 + 0x10) + 0x20) & 0xf) != 5) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x106cdc);
    (*pcVar1)();
  }
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0x100000002;
  *(undefined4 *)(param_1 + 0x108) = 3;
  DAT_0010db70 = DAT_0010db70 + 1;
  _qcrypto_queue_req(uVar2,*(undefined8 *)(lVar3 + 0x50),param_1 + 0x20);
  return;
}



//------------------------------------------------------------
// _sha1_init @ 00106ce4 size=108
// signature: undefined _sha1_init(void)
// callers: []
//------------------------------------------------------------

undefined8 _sha1_init(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  *(undefined4 *)(param_1 + 0x154) = 0;
  *(undefined2 *)(param_1 + 0x110) = 1;
  lVar3 = *(long *)(param_1 + 0x20);
  *(undefined8 *)(param_1 + 0xf8) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0;
  *(undefined8 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(lVar3 + 100) = 0;
  *(undefined4 *)(param_1 + 0x208) = 0xf0e1d2c3;
  uVar2 = DAT_0010c8c8;
  uVar1 = _std_init_vector_sha1_uint8;
  *(undefined8 *)(param_1 + 0x142) = 0;
  *(undefined8 *)(param_1 + 0x14a) = 0;
  *(undefined8 *)(param_1 + 0x132) = 0;
  *(undefined8 *)(param_1 + 0x13a) = 0;
  *(undefined8 *)(param_1 + 0x122) = 0;
  *(undefined8 *)(param_1 + 0x12a) = 0;
  *(undefined8 *)(param_1 + 0x112) = 0;
  *(undefined8 *)(param_1 + 0x11a) = 0;
  *(undefined8 *)(param_1 + 0x1f8) = uVar1;
  *(undefined8 *)(param_1 + 0x200) = uVar2;
  *(undefined4 *)(lVar3 + 0x68) = 0x14;
  DAT_0010dba8 = DAT_0010dba8 + 1;
  return 0;
}



//------------------------------------------------------------
// _sha1_update @ 00106d54 size=96
// signature: undefined _sha1_update(void)
// callers: []
//------------------------------------------------------------

undefined8 _sha1_update(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((*(char *)(*(long *)(*(long *)(param_1 + 0x20) + 0x58) + 0x19) == '\0') ||
     (iVar1 = _copy_source(param_1), iVar1 == 0)) {
    *(ulong *)(param_1 + 0x108) = *(long *)(param_1 + 0x108) + (ulong)*(uint *)(param_1 + 0x30);
    uVar2 = _sha_update(param_1);
  }
  else {
    uVar2 = 0xfffffff4;
  }
  return uVar2;
}



//------------------------------------------------------------
// _sha1_final @ 00106db8 size=28
// signature: undefined _sha1_final(void)
// callers: []
//------------------------------------------------------------

void _sha1_final(void)

{
  _sha_final();
  return;
}



//------------------------------------------------------------
// _sha1_digest @ 00106dd8 size=220
// signature: undefined _sha1_digest(void)
// callers: []
//------------------------------------------------------------

undefined8 _sha1_digest(long param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  *(undefined4 *)(param_1 + 0x154) = 0;
  *(undefined2 *)(param_1 + 0x110) = 1;
  lVar4 = *(long *)(param_1 + 0x20);
  *(undefined8 *)(param_1 + 0xf8) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0;
  uVar1 = DAT_0010c8c8;
  uVar3 = _std_init_vector_sha1_uint8;
  *(undefined8 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(lVar4 + 100) = 0;
  *(undefined8 *)(param_1 + 0x142) = 0;
  *(undefined8 *)(param_1 + 0x14a) = 0;
  *(undefined8 *)(param_1 + 0x132) = 0;
  *(undefined8 *)(param_1 + 0x13a) = 0;
  *(undefined8 *)(param_1 + 0x122) = 0;
  *(undefined8 *)(param_1 + 0x12a) = 0;
  *(undefined8 *)(param_1 + 0x112) = 0;
  *(undefined8 *)(param_1 + 0x11a) = 0;
  *(undefined4 *)(param_1 + 0x208) = 0xf0e1d2c3;
  *(undefined8 *)(param_1 + 0x1f8) = uVar3;
  *(undefined8 *)(param_1 + 0x200) = uVar1;
  *(undefined4 *)(lVar4 + 0x68) = 0x14;
  DAT_0010dba8 = DAT_0010dba8 + 1;
  lVar5 = *(long *)(param_1 + 0x20);
  lVar4 = *(long *)(lVar5 + 0x58);
  if ((*(char *)(lVar4 + 0x19) == '\0') || (iVar2 = _copy_source(param_1), iVar2 == 0)) {
    *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0x30);
    *(undefined2 *)(param_1 + 0x110) = 0x101;
    uVar3 = _qcrypto_queue_req(lVar4,*(undefined8 *)(lVar5 + 0x50),param_1);
  }
  else {
    uVar3 = 0xfffffff4;
  }
  return uVar3;
}



//------------------------------------------------------------
// _sha1_export @ 00106eb8 size=116
// signature: undefined _sha1_export(void)
// callers: []
//------------------------------------------------------------

undefined8 _sha1_export(long param_1,uint *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  
  *(undefined8 *)(param_2 + 6) = *(undefined8 *)(param_1 + 0x108);
  uVar4 = (*(uint *)(param_1 + 0x1f8) & 0xff00ff00) >> 8 |
          (*(uint *)(param_1 + 0x1f8) & 0xff00ff) << 8;
  *param_2 = uVar4 >> 0x10 | uVar4 << 0x10;
  uVar4 = (*(uint *)(param_1 + 0x1fc) & 0xff00ff00) >> 8 |
          (*(uint *)(param_1 + 0x1fc) & 0xff00ff) << 8;
  param_2[1] = uVar4 >> 0x10 | uVar4 << 0x10;
  uVar4 = (*(uint *)(param_1 + 0x200) & 0xff00ff00) >> 8 |
          (*(uint *)(param_1 + 0x200) & 0xff00ff) << 8;
  param_2[2] = uVar4 >> 0x10 | uVar4 << 0x10;
  uVar4 = (*(uint *)(param_1 + 0x204) & 0xff00ff00) >> 8 |
          (*(uint *)(param_1 + 0x204) & 0xff00ff) << 8;
  param_2[3] = uVar4 >> 0x10 | uVar4 << 0x10;
  uVar4 = (*(uint *)(param_1 + 0x208) & 0xff00ff00) >> 8 |
          (*(uint *)(param_1 + 0x208) & 0xff00ff) << 8;
  param_2[4] = uVar4 >> 0x10 | uVar4 << 0x10;
  uVar2 = *(undefined8 *)(param_1 + 0x12a);
  uVar1 = *(undefined8 *)(param_1 + 0x112);
  uVar3 = *(undefined8 *)(param_1 + 0x11a);
  *(undefined8 *)(param_2 + 0xc) = *(undefined8 *)(param_1 + 0x122);
  *(undefined8 *)(param_2 + 0xe) = uVar2;
  *(undefined8 *)(param_2 + 8) = uVar1;
  *(undefined8 *)(param_2 + 10) = uVar3;
  uVar2 = *(undefined8 *)(param_1 + 0x14a);
  uVar1 = *(undefined8 *)(param_1 + 0x132);
  uVar3 = *(undefined8 *)(param_1 + 0x13a);
  *(undefined8 *)(param_2 + 0x14) = *(undefined8 *)(param_1 + 0x142);
  *(undefined8 *)(param_2 + 0x16) = uVar2;
  *(undefined8 *)(param_2 + 0x10) = uVar1;
  *(undefined8 *)(param_2 + 0x12) = uVar3;
  return 0;
}



//------------------------------------------------------------
// _sha1_import @ 00106f30 size=292
// signature: undefined _sha1_import(void)
// callers: []
//------------------------------------------------------------

undefined8 _sha1_import(long param_1,uint *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulong uVar5;
  uint *puVar6;
  uint *puVar7;
  undefined8 uVar8;
  undefined1 *puVar9;
  long lVar10;
  uint uVar11;
  long lVar12;
  undefined1 *puVar13;
  long lVar14;
  
  uVar8 = *(undefined8 *)(param_2 + 6);
  *(undefined8 *)(param_1 + 0x108) = uVar8;
  uVar2 = *(undefined8 *)(param_2 + 0x16);
  uVar1 = *(undefined8 *)(param_2 + 0x10);
  uVar3 = *(undefined8 *)(param_2 + 0x12);
  *(undefined8 *)(param_1 + 0x142) = *(undefined8 *)(param_2 + 0x14);
  *(undefined8 *)(param_1 + 0x14a) = uVar2;
  *(undefined8 *)(param_1 + 0x132) = uVar1;
  *(undefined8 *)(param_1 + 0x13a) = uVar3;
  uVar2 = *(undefined8 *)(param_2 + 0xe);
  uVar1 = *(undefined8 *)(param_2 + 8);
  uVar3 = *(undefined8 *)(param_2 + 10);
  *(undefined8 *)(param_1 + 0x122) = *(undefined8 *)(param_2 + 0xc);
  *(undefined8 *)(param_1 + 0x12a) = uVar2;
  *(undefined8 *)(param_1 + 0x112) = uVar1;
  *(undefined8 *)(param_1 + 0x11a) = uVar3;
  puVar9 = (undefined1 *)(param_1 + 0x1f8);
  uVar5 = *(ulong *)(param_2 + 6);
  *(uint *)(param_1 + 0xf8) = (uint)uVar8 & 0xffffffc0;
  *(int *)(param_1 + 0xfc) = (int)((ulong)uVar8 >> 0x20);
  *(bool *)(param_1 + 0x110) = uVar5 < 0x41;
  uVar4 = *(uint *)(*(long *)(param_1 + 0x20) + 0x68);
  if (uVar4 < 4) {
    puVar7 = param_2;
  }
  else {
    uVar11 = uVar4 >> 2;
    puVar6 = param_2;
    puVar13 = puVar9;
    do {
      uVar11 = uVar11 - 1;
      *puVar13 = *(undefined1 *)((long)puVar6 + 3);
      puVar13[1] = (char)*(undefined2 *)((long)puVar6 + 2);
      puVar13[2] = (char)(*puVar6 >> 8);
      puVar9 = puVar13 + 4;
      puVar7 = puVar6 + 1;
      puVar13[3] = (char)*puVar6;
      puVar6 = puVar7;
      puVar13 = puVar9;
    } while (uVar11 != 0);
  }
  uVar4 = uVar4 & 3;
  lVar10 = 0x18;
  lVar12 = lVar10;
  if (uVar4 != 1) {
    if (uVar4 == 2) {
      lVar12 = 0x10;
      lVar14 = 1;
      puVar13 = puVar9;
    }
    else {
      if (uVar4 != 3) goto LAB_00107040;
      lVar12 = 8;
      lVar10 = 0x10;
      lVar14 = 2;
      *puVar9 = *(undefined1 *)((long)puVar7 + 3);
      puVar13 = puVar9 + 1;
    }
    puVar9 = puVar9 + lVar14;
    *puVar13 = (char)(*puVar7 >> lVar10);
  }
  *puVar9 = (char)(*puVar7 >> lVar12);
LAB_00107040:
  *(uint *)(param_1 + 0x154) = param_2[6] & 0x3f;
  return 0;
}



//------------------------------------------------------------
// _qcrypto_ahash_cra_init @ 00107058 size=52
// signature: undefined _qcrypto_ahash_cra_init(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_ahash_cra_init(long param_1)

{
  undefined8 uVar1;
  
  *(undefined4 *)(param_1 + -0x40) = 0x1d8;
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x10) + 0x348);
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0xb0) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0x58) = uVar1;
  *(long *)(param_1 + 0x40) = param_1 + 0x40;
  *(long *)(param_1 + 0x48) = param_1 + 0x40;
  return 0;
}



//------------------------------------------------------------
// _qcrypto_ahash_cra_exit @ 00107090 size=100
// signature: undefined _qcrypto_ahash_cra_exit(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_ahash_cra_exit(long param_1)

{
  long lVar1;
  
  if (*(long **)(param_1 + 0x40) == (long *)(param_1 + 0x40)) {
    lVar1 = *(long *)(param_1 + 0xb0);
  }
  else {
    _printk(&DAT_0010e569,"_qcrypto_ahash_cra_exit");
    lVar1 = *(long *)(param_1 + 0xb0);
  }
  if (lVar1 != 0) {
    kfree_sensitive();
    *(undefined8 *)(param_1 + 0xb0) = 0;
  }
  return;
}



//------------------------------------------------------------
// _sha256_init @ 001070f8 size=108
// signature: undefined _sha256_init(void)
// callers: []
//------------------------------------------------------------

undefined8 _sha256_init(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x154) = 0;
  uVar2 = DAT_0010ed77;
  uVar1 = _std_init_vector_sha256_uint8;
  *(undefined2 *)(param_1 + 0x110) = 1;
  uVar4 = DAT_0010ed87;
  uVar3 = DAT_0010ed7f;
  *(undefined8 *)(param_1 + 0xf8) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0;
  *(undefined8 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(lVar5 + 100) = 1;
  *(undefined8 *)(param_1 + 0x1f8) = uVar1;
  *(undefined8 *)(param_1 + 0x200) = uVar2;
  *(undefined8 *)(param_1 + 0x210) = uVar4;
  *(undefined8 *)(param_1 + 0x208) = uVar3;
  *(undefined8 *)(param_1 + 0x142) = 0;
  *(undefined8 *)(param_1 + 0x14a) = 0;
  *(undefined8 *)(param_1 + 0x132) = 0;
  *(undefined8 *)(param_1 + 0x13a) = 0;
  *(undefined8 *)(param_1 + 0x122) = 0;
  *(undefined8 *)(param_1 + 0x12a) = 0;
  *(undefined8 *)(param_1 + 0x112) = 0;
  *(undefined8 *)(param_1 + 0x11a) = 0;
  *(undefined4 *)(lVar5 + 0x68) = 0x20;
  DAT_0010dbb0 = DAT_0010dbb0 + 1;
  return 0;
}



//------------------------------------------------------------
// _sha256_update @ 00107168 size=96
// signature: undefined _sha256_update(void)
// callers: []
//------------------------------------------------------------

undefined8 _sha256_update(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((*(char *)(*(long *)(*(long *)(param_1 + 0x20) + 0x58) + 0x19) == '\0') ||
     (iVar1 = _copy_source(param_1), iVar1 == 0)) {
    *(ulong *)(param_1 + 0x108) = *(long *)(param_1 + 0x108) + (ulong)*(uint *)(param_1 + 0x30);
    uVar2 = _sha_update(param_1);
  }
  else {
    uVar2 = 0xfffffff4;
  }
  return uVar2;
}



//------------------------------------------------------------
// _sha256_final @ 001071cc size=28
// signature: undefined _sha256_final(void)
// callers: []
//------------------------------------------------------------

void _sha256_final(void)

{
  _sha_final();
  return;
}



//------------------------------------------------------------
// _sha256_digest @ 001071ec size=220
// signature: undefined _sha256_digest(void)
// callers: []
//------------------------------------------------------------

undefined8 _sha256_digest(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  
  lVar6 = *(long *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x154) = 0;
  *(undefined8 *)(param_1 + 0xf8) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0;
  *(undefined2 *)(param_1 + 0x110) = 1;
  *(undefined8 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(lVar6 + 100) = 1;
  *(undefined8 *)(param_1 + 0x142) = 0;
  *(undefined8 *)(param_1 + 0x14a) = 0;
  *(undefined8 *)(param_1 + 0x132) = 0;
  *(undefined8 *)(param_1 + 0x13a) = 0;
  *(undefined8 *)(param_1 + 0x122) = 0;
  *(undefined8 *)(param_1 + 0x12a) = 0;
  uVar1 = DAT_0010ed77;
  uVar5 = _std_init_vector_sha256_uint8;
  *(undefined8 *)(param_1 + 0x112) = 0;
  *(undefined8 *)(param_1 + 0x11a) = 0;
  uVar3 = DAT_0010ed87;
  uVar2 = DAT_0010ed7f;
  *(undefined8 *)(param_1 + 0x1f8) = uVar5;
  *(undefined8 *)(param_1 + 0x200) = uVar1;
  *(undefined8 *)(param_1 + 0x208) = uVar2;
  *(undefined8 *)(param_1 + 0x210) = uVar3;
  *(undefined4 *)(lVar6 + 0x68) = 0x20;
  DAT_0010dbb0 = DAT_0010dbb0 + 1;
  lVar7 = *(long *)(param_1 + 0x20);
  lVar6 = *(long *)(lVar7 + 0x58);
  if ((*(char *)(lVar6 + 0x19) == '\0') || (iVar4 = _copy_source(param_1), iVar4 == 0)) {
    *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0x30);
    *(undefined2 *)(param_1 + 0x110) = 0x101;
    uVar5 = _qcrypto_queue_req(lVar6,*(undefined8 *)(lVar7 + 0x50),param_1);
  }
  else {
    uVar5 = 0xfffffff4;
  }
  return uVar5;
}



//------------------------------------------------------------
// _sha256_export @ 001072cc size=152
// signature: undefined _sha256_export(void)
// callers: [_sha256_hmac_export]
//------------------------------------------------------------

undefined8 _sha256_export(long param_1,uint *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  
  *(undefined8 *)(param_2 + 8) = *(undefined8 *)(param_1 + 0x108);
  uVar4 = (*(uint *)(param_1 + 0x1f8) & 0xff00ff00) >> 8 |
          (*(uint *)(param_1 + 0x1f8) & 0xff00ff) << 8;
  *param_2 = uVar4 >> 0x10 | uVar4 << 0x10;
  uVar4 = (*(uint *)(param_1 + 0x1fc) & 0xff00ff00) >> 8 |
          (*(uint *)(param_1 + 0x1fc) & 0xff00ff) << 8;
  param_2[1] = uVar4 >> 0x10 | uVar4 << 0x10;
  uVar4 = (*(uint *)(param_1 + 0x200) & 0xff00ff00) >> 8 |
          (*(uint *)(param_1 + 0x200) & 0xff00ff) << 8;
  param_2[2] = uVar4 >> 0x10 | uVar4 << 0x10;
  uVar4 = (*(uint *)(param_1 + 0x204) & 0xff00ff00) >> 8 |
          (*(uint *)(param_1 + 0x204) & 0xff00ff) << 8;
  param_2[3] = uVar4 >> 0x10 | uVar4 << 0x10;
  uVar4 = (*(uint *)(param_1 + 0x208) & 0xff00ff00) >> 8 |
          (*(uint *)(param_1 + 0x208) & 0xff00ff) << 8;
  param_2[4] = uVar4 >> 0x10 | uVar4 << 0x10;
  uVar4 = (*(uint *)(param_1 + 0x20c) & 0xff00ff00) >> 8 |
          (*(uint *)(param_1 + 0x20c) & 0xff00ff) << 8;
  param_2[5] = uVar4 >> 0x10 | uVar4 << 0x10;
  uVar4 = (*(uint *)(param_1 + 0x210) & 0xff00ff00) >> 8 |
          (*(uint *)(param_1 + 0x210) & 0xff00ff) << 8;
  param_2[6] = uVar4 >> 0x10 | uVar4 << 0x10;
  uVar4 = (*(uint *)(param_1 + 0x214) & 0xff00ff00) >> 8 |
          (*(uint *)(param_1 + 0x214) & 0xff00ff) << 8;
  param_2[7] = uVar4 >> 0x10 | uVar4 << 0x10;
  uVar2 = *(undefined8 *)(param_1 + 0x12a);
  uVar1 = *(undefined8 *)(param_1 + 0x112);
  uVar3 = *(undefined8 *)(param_1 + 0x11a);
  *(undefined8 *)(param_2 + 0xe) = *(undefined8 *)(param_1 + 0x122);
  *(undefined8 *)(param_2 + 0x10) = uVar2;
  *(undefined8 *)(param_2 + 10) = uVar1;
  *(undefined8 *)(param_2 + 0xc) = uVar3;
  uVar2 = *(undefined8 *)(param_1 + 0x14a);
  uVar1 = *(undefined8 *)(param_1 + 0x132);
  uVar3 = *(undefined8 *)(param_1 + 0x13a);
  *(undefined8 *)(param_2 + 0x16) = *(undefined8 *)(param_1 + 0x142);
  *(undefined8 *)(param_2 + 0x18) = uVar2;
  *(undefined8 *)(param_2 + 0x12) = uVar1;
  *(undefined8 *)(param_2 + 0x14) = uVar3;
  return 0;
}



//------------------------------------------------------------
// _sha256_import @ 00107368 size=292
// signature: undefined _sha256_import(void)
// callers: []
//------------------------------------------------------------

undefined8 _sha256_import(long param_1,uint *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulong uVar5;
  uint *puVar6;
  uint *puVar7;
  undefined8 uVar8;
  undefined1 *puVar9;
  long lVar10;
  uint uVar11;
  long lVar12;
  undefined1 *puVar13;
  long lVar14;
  
  uVar8 = *(undefined8 *)(param_2 + 8);
  *(undefined8 *)(param_1 + 0x108) = uVar8;
  uVar2 = *(undefined8 *)(param_2 + 0x18);
  uVar1 = *(undefined8 *)(param_2 + 0x12);
  uVar3 = *(undefined8 *)(param_2 + 0x14);
  *(undefined8 *)(param_1 + 0x142) = *(undefined8 *)(param_2 + 0x16);
  *(undefined8 *)(param_1 + 0x14a) = uVar2;
  *(undefined8 *)(param_1 + 0x132) = uVar1;
  *(undefined8 *)(param_1 + 0x13a) = uVar3;
  uVar2 = *(undefined8 *)(param_2 + 0x10);
  uVar1 = *(undefined8 *)(param_2 + 10);
  uVar3 = *(undefined8 *)(param_2 + 0xc);
  *(undefined8 *)(param_1 + 0x122) = *(undefined8 *)(param_2 + 0xe);
  *(undefined8 *)(param_1 + 0x12a) = uVar2;
  *(undefined8 *)(param_1 + 0x112) = uVar1;
  *(undefined8 *)(param_1 + 0x11a) = uVar3;
  puVar9 = (undefined1 *)(param_1 + 0x1f8);
  uVar5 = *(ulong *)(param_2 + 8);
  *(uint *)(param_1 + 0xf8) = (uint)uVar8 & 0xffffffc0;
  *(int *)(param_1 + 0xfc) = (int)((ulong)uVar8 >> 0x20);
  *(bool *)(param_1 + 0x110) = uVar5 < 0x41;
  uVar4 = *(uint *)(*(long *)(param_1 + 0x20) + 0x68);
  if (uVar4 < 4) {
    puVar7 = param_2;
  }
  else {
    uVar11 = uVar4 >> 2;
    puVar6 = param_2;
    puVar13 = puVar9;
    do {
      uVar11 = uVar11 - 1;
      *puVar13 = *(undefined1 *)((long)puVar6 + 3);
      puVar13[1] = (char)*(undefined2 *)((long)puVar6 + 2);
      puVar13[2] = (char)(*puVar6 >> 8);
      puVar9 = puVar13 + 4;
      puVar7 = puVar6 + 1;
      puVar13[3] = (char)*puVar6;
      puVar6 = puVar7;
      puVar13 = puVar9;
    } while (uVar11 != 0);
  }
  uVar4 = uVar4 & 3;
  lVar10 = 0x18;
  lVar12 = lVar10;
  if (uVar4 != 1) {
    if (uVar4 == 2) {
      lVar12 = 0x10;
      lVar14 = 1;
      puVar13 = puVar9;
    }
    else {
      if (uVar4 != 3) goto LAB_00107478;
      lVar12 = 8;
      lVar10 = 0x10;
      lVar14 = 2;
      *puVar9 = *(undefined1 *)((long)puVar7 + 3);
      puVar13 = puVar9 + 1;
    }
    puVar9 = puVar9 + lVar14;
    *puVar13 = (char)(*puVar7 >> lVar10);
  }
  *puVar9 = (char)(*puVar7 >> lVar12);
LAB_00107478:
  *(uint *)(param_1 + 0x154) = param_2[8] & 0x3f;
  return 0;
}



//------------------------------------------------------------
// _copy_source @ 0010748c size=348
// signature: undefined _copy_source(void)
// callers: [_sha1_hmac_digest, _sha1_digest, _sha256_hmac_digest, _sha_final, _sha256_digest, _sha256_update, _sha256_hmac_update, _sha1_hmac_update, _sha1_update, _sha_hmac_setkey]
//------------------------------------------------------------

undefined8 _copy_source(long param_1)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  undefined8 uVar7;
  
  *(undefined8 *)(param_1 + 0xc0) = *(undefined8 *)(param_1 + 0x38);
  lVar2 = __kmalloc(*(int *)(param_1 + 0x30) + 0x40,0xb20);
  *(long *)(param_1 + 0xe8) = lVar2;
  if (lVar2 == 0) {
    _printk(&DAT_0010eb7c,0,*(int *)(param_1 + 0x30) + 0x40);
    return 0xfffffff4;
  }
  uVar6 = 0;
  lVar2 = *(long *)(param_1 + 0x38);
  uVar5 = (ulong)*(uint *)(param_1 + 0x30);
  if ((lVar2 == 0) || ((int)*(uint *)(param_1 + 0x30) < 1)) {
LAB_0010754c:
    iVar4 = (int)uVar5;
    if (iVar4 == (int)uVar6) goto LAB_00107554;
  }
  else {
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      uVar1 = (int)uVar5 - *(int *)(lVar2 + 0xc);
      uVar5 = (ulong)uVar1;
      lVar2 = sg_next();
    } while (0 < (int)uVar1 && lVar2 != 0);
    uVar5 = (ulong)*(uint *)(param_1 + 0x30);
    if (iVar4 != 0) {
      uVar6 = 0;
      lVar2 = *(long *)(param_1 + 0xe8);
      uVar7 = *(undefined8 *)(param_1 + 0x38);
      do {
        lVar3 = sg_copy_to_buffer(uVar7,1,lVar2,uVar5);
        lVar2 = lVar2 + lVar3;
        uVar5 = uVar5 - lVar3;
        uVar6 = lVar3 + uVar6;
        uVar7 = sg_next(uVar7);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      uVar5 = (ulong)*(uint *)(param_1 + 0x30);
      goto LAB_0010754c;
    }
    uVar6 = 0;
    iVar4 = 0;
    if (*(uint *)(param_1 + 0x30) == 0) goto LAB_00107554;
  }
  _printk(&DAT_0010de03,uVar6 & 0xffffffff,uVar5);
  iVar4 = *(int *)(param_1 + 0x30);
LAB_00107554:
  *(long *)(param_1 + 200) =
       (((*(long *)(param_1 + 0xe8) << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 + -0x1fffffffe;
  *(uint *)(param_1 + 0xd0) = (uint)*(long *)(param_1 + 0xe8) & 0xfff;
  *(int *)(param_1 + 0xd4) = iVar4;
  *(long **)(param_1 + 0x38) = (long *)(param_1 + 200);
  return 0;
}



//------------------------------------------------------------
// _sha_update @ 001075e8 size=736
// signature: undefined _sha_update(void)
// callers: [_sha256_update, _sha256_hmac_update, _sha1_hmac_update, _sha1_update]
//------------------------------------------------------------

undefined8 _sha_update(long param_1)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  long lVar4;
  ulong *puVar5;
  long lVar6;
  ulong uVar7;
  uint uVar8;
  undefined8 uVar9;
  int iVar10;
  long lVar11;
  int iVar12;
  
  uVar8 = *(uint *)(param_1 + 0x30);
  uVar7 = (ulong)uVar8;
  uVar2 = *(uint *)(param_1 + 0x154);
  uVar1 = uVar2 + uVar8;
  if (uVar1 < 0x41) {
    if (0x40 < uVar2) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1078c8);
      (*pcVar3)();
    }
    if ((0 < (int)uVar8) && (lVar4 = *(long *)(param_1 + 0x38), lVar4 != 0)) {
      iVar10 = 0;
      lVar11 = param_1 + (ulong)uVar2 + 0x112;
      do {
        iVar10 = iVar10 + 1;
        uVar8 = uVar8 - *(int *)(lVar4 + 0xc);
        lVar4 = sg_next();
      } while (0 < (int)uVar8 && lVar4 != 0);
      if (iVar10 != 0) {
        uVar9 = *(undefined8 *)(param_1 + 0x38);
        do {
          lVar4 = sg_copy_to_buffer(uVar9,1,lVar11,uVar7);
          lVar11 = lVar11 + lVar4;
          uVar7 = uVar7 - lVar4;
          uVar9 = sg_next(uVar9);
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
    }
    uVar9 = 0;
    *(uint *)(param_1 + 0x154) = uVar1;
  }
  else {
    lVar11 = *(long *)(param_1 + 0x20);
    uVar7 = param_1 + 0x197;
    lVar4 = *(long *)(lVar11 + 0x58);
    *(uint *)(param_1 + 0xb8) = uVar8;
    *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0x38);
    memcpy((void *)(uVar7 & 0xffffffffffffffc0),(void *)(param_1 + 0x112),(ulong)uVar2);
    iVar10 = (uVar1 - (uVar1 + 0x3f & 0xffffffc0)) + 0x40;
    if (iVar10 != 0) {
      scatterwalk_map_and_copy
                ((void *)(param_1 + 0x112),*(undefined8 *)(param_1 + 0x38),
                 *(int *)(param_1 + 0x30) - iVar10,iVar10,0);
    }
    puVar5 = *(ulong **)(param_1 + 0x38);
    uVar1 = uVar1 - iVar10;
    if ((puVar5 != (ulong *)0x0) && (iVar12 = *(int *)(param_1 + 0x30), 0 < iVar12)) {
      do {
        iVar12 = iVar12 - *(int *)((long)puVar5 + 0xc);
        puVar5 = (ulong *)sg_next();
      } while (0 < iVar12 && puVar5 != (ulong *)0x0);
      puVar5 = *(ulong **)(param_1 + 0x38);
    }
    uVar8 = *(uint *)(param_1 + 0x154);
    if (uVar8 < uVar1) {
      do {
        uVar8 = *(int *)((long)puVar5 + 0xc) + uVar8;
        if (uVar1 < uVar8) break;
        puVar5 = (ulong *)sg_next();
      } while (uVar8 < uVar1);
      uVar8 = *(uint *)(param_1 + 0x154);
    }
    if (uVar8 == 0) {
      *puVar5 = *puVar5 & 0xfffffffffffffffc | 2;
    }
    else if (*(char *)(lVar4 + 0x19) == '\0') {
      *puVar5 = *puVar5 & 0xfffffffffffffffc | 2;
      *(undefined8 *)(param_1 + 0x240) = 0;
      *(undefined8 *)(param_1 + 0x250) = 0;
      *(uint *)(param_1 + 0x220) = (uint)uVar7 & 0xfc0;
      *(undefined8 *)(param_1 + 0x248) = 0;
      *(undefined8 *)(param_1 + 0x230) = 0;
      *(undefined8 *)(param_1 + 0x228) = 0;
      *(undefined4 *)(param_1 + 0x240) = 0;
      *(ulong *)(param_1 + 0x218) =
           (((long)(uVar7 * 0x100) >> 8) + 0x8000000000U >> 0xc) * 0x40 + -0x200000000;
      *(undefined4 *)(param_1 + 0x224) = *(undefined4 *)(param_1 + 0x154);
      *(ulong *)(param_1 + 0x238) = *(ulong *)(param_1 + 0x38) & 0xfffffffffffffffc | 1;
      *(long *)(param_1 + 0x38) = param_1 + 0x218;
    }
    else {
      lVar6 = __kmalloc(*(int *)(param_1 + 0x30) + 0x40,0xb20);
      *(long *)(param_1 + 0xf0) = lVar6;
      if (lVar6 == 0) {
        return 0xfffffff4;
      }
      memcpy(*(void **)(param_1 + 0xf0),(void *)(uVar7 & 0xffffffffffffffc0),
             (ulong)*(uint *)(param_1 + 0x154));
      memcpy((void *)(*(long *)(param_1 + 0xf0) + (ulong)*(uint *)(param_1 + 0x154)),
             *(void **)(param_1 + 0xe8),(ulong)*(uint *)(*(long *)(param_1 + 0x38) + 0xc));
      kfree_sensitive(*(undefined8 *)(param_1 + 0xe8));
      lVar6 = *(long *)(param_1 + 0xf0);
      *(long *)(param_1 + 0xe8) = lVar6;
      iVar12 = *(int *)(*(long *)(param_1 + 0x38) + 0xc);
      *(uint *)(param_1 + 0x220) = (uint)lVar6 & 0xfff;
      *(int *)(param_1 + 0x224) = iVar12 + *(int *)(param_1 + 0x154);
      *(long *)(param_1 + 0x38) = param_1 + 0x218;
      *(ulong *)(param_1 + 0x218) =
           (((lVar6 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 + -0x1fffffffe;
    }
    *(uint *)(param_1 + 0x30) = uVar1;
    *(int *)(param_1 + 0x154) = iVar10;
    uVar9 = _qcrypto_queue_req(lVar4,*(undefined8 *)(lVar11 + 0x50),param_1);
  }
  return uVar9;
}



//------------------------------------------------------------
// _sha_final @ 001078c8 size=200
// signature: undefined _sha_final(void)
// callers: [_sha1_hmac_final, _sha256_final, _sha256_hmac_final, _sha1_final]
//------------------------------------------------------------

undefined8 _sha_final(long param_1)

{
  ulong uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x20);
  lVar4 = *(long *)(lVar5 + 0x58);
  if ((*(char *)(lVar4 + 0x19) == '\0') || (iVar2 = _copy_source(param_1), iVar2 == 0)) {
    uVar1 = param_1 + 0x197;
    *(undefined1 *)(param_1 + 0x111) = 1;
    *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0x30);
    memcpy((void *)(uVar1 & 0xffffffffffffffc0),(void *)(param_1 + 0x112),
           (ulong)*(uint *)(param_1 + 0x154));
    *(uint *)(param_1 + 0x220) = (uint)uVar1 & 0xfc0;
    *(undefined4 *)(param_1 + 0x224) = *(undefined4 *)(param_1 + 0x154);
    *(long *)(param_1 + 0x38) = param_1 + 0x218;
    *(ulong *)(param_1 + 0x218) =
         (((long)(uVar1 * 0x100) >> 8) + 0x8000000000U >> 0xc) * 0x40 + -0x1fffffffe;
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x154);
    uVar3 = _qcrypto_queue_req(lVar4,*(undefined8 *)(lVar5 + 0x50),param_1);
  }
  else {
    uVar3 = 0xfffffff4;
  }
  return uVar3;
}



//------------------------------------------------------------
// _qcrypto_aead_setkey @ 00107994 size=396
// signature: undefined _qcrypto_aead_setkey(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_aead_setkey(long param_1,ushort *param_2,uint param_3)

{
  void *__src;
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined8 *__dest;
  
  if (3 < param_3) {
    uVar1 = *param_2;
    if ((((3 < uVar1) && (uVar1 < param_3 || uVar1 == param_3)) && (param_2[1] == 1)) &&
       ((uVar1 & 0xfffc) != 4)) {
      uVar2 = (*(uint *)(param_2 + 2) & 0xff00ff00) >> 8 | (*(uint *)(param_2 + 2) & 0xff00ff) << 8;
      uVar2 = uVar2 >> 0x10 | uVar2 << 0x10;
      *(uint *)(param_1 + 0x138) = uVar2;
      uVar7 = (ulong)(*param_2 + 3) & 0x1fffc;
      param_3 = param_3 - (int)uVar7;
      uVar3 = param_3 - uVar2;
      if (((uVar2 <= param_3) && (*(uint *)(param_1 + 0x140) = uVar3, uVar2 < 0x40)) &&
         (uVar3 < 0x40)) {
        __src = (void *)((long)param_2 + uVar7);
        __dest = (undefined8 *)(param_1 + 0xa8);
        *__dest = 0;
        *(undefined8 *)(param_1 + 0xd8) = 0;
        *(undefined8 *)(param_1 + 0xe0) = 0;
        *(undefined8 *)(param_1 + 200) = 0;
        *(undefined8 *)(param_1 + 0xd0) = 0;
        *(undefined8 *)(param_1 + 0xb8) = 0;
        *(undefined8 *)(param_1 + 0xc0) = 0;
        *(undefined8 *)(param_1 + 0xb0) = 0;
        memcpy((void *)(param_1 + 0xf8),(void *)((long)__src + (ulong)*(uint *)(param_1 + 0x140)),
               (ulong)uVar2);
        uVar2 = *(uint *)(param_1 + 0x140);
        if ((0x40 < uVar2) && ((_qcrypto_aead_setkey___already_done_105 & 1) == 0)) {
          _qcrypto_aead_setkey___already_done_105 = 1;
          __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n"
                        ,(ulong)uVar2,
                        "field \"ctx->auth_key\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcrypto.c:3053"
                        ,0x40);
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x800,0x107b20);
          (*pcVar4)();
        }
        memcpy(__dest,__src,(ulong)uVar2);
        if (((*(int *)(param_1 + 0x138) != 0x18) || (*(long *)(param_1 + 0x148) == 0)) ||
           (*(long *)(param_1 + 0x150) == 0)) {
          return 0;
        }
        *(undefined4 *)(*(long *)(param_1 + 0x150) + 0x80) = 0;
        iVar5 = crypto_ahash_setkey(*(undefined8 *)(param_1 + 0x150),__dest,
                                    *(undefined4 *)(param_1 + 0x140));
        if (iVar5 == 0) {
          *(undefined4 *)(*(long *)(param_1 + 0x148) + 0x40) = 0;
          uVar6 = crypto_skcipher_setkey
                            (*(undefined8 *)(param_1 + 0x148),(void *)(param_1 + 0xf8),
                             *(undefined4 *)(param_1 + 0x138));
          if ((int)uVar6 == 0) {
            return uVar6;
          }
        }
      }
    }
  }
  *(undefined4 *)(param_1 + 0x138) = 0;
  return 0xffffffea;
}



//------------------------------------------------------------
// _qcrypto_aead_setauthsize @ 00107b28 size=16
// signature: undefined _qcrypto_aead_setauthsize(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_aead_setauthsize(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x13c) = param_2;
  return 0;
}



//------------------------------------------------------------
// _qcrypto_aead_encrypt_aes_cbc @ 00107b3c size=156
// signature: undefined _qcrypto_aead_encrypt_aes_cbc(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_aead_encrypt_aes_cbc(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x20);
  uVar2 = *(undefined8 *)(lVar3 + 0x58);
  *(undefined4 *)(param_1 + 0xcc) = 1;
  *(undefined8 *)(param_1 + 0x100) = 2;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0x38);
  *(long *)(param_1 + 0x168) = param_1;
  lVar1 = 0;
  if (*(int *)(lVar3 + 100) != 2) {
    lVar1 = 0x30;
  }
  *(long *)((long)&_qcrypto_stat + lVar1) = *(long *)((long)&_qcrypto_stat + lVar1) + 1;
  if (((*(int *)(lVar3 + 0xf8) == 0x18) && (*(long *)(lVar3 + 0x108) != 0)) &&
     (*(long *)(lVar3 + 0x110) != 0)) {
    _qcrypto_aead_aes_192_fallback(param_1,1);
  }
  else {
    _qcrypto_queue_req(uVar2,*(undefined8 *)(lVar3 + 0x50));
  }
  return;
}



//------------------------------------------------------------
// _qcrypto_aead_decrypt_aes_cbc @ 00107bdc size=164
// signature: undefined _qcrypto_aead_decrypt_aes_cbc(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_aead_decrypt_aes_cbc(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x20);
  uVar2 = *(undefined8 *)(lVar3 + 0x58);
  *(undefined4 *)(param_1 + 0xcc) = 1;
  *(undefined8 *)(param_1 + 0x100) = 0x100000002;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0x38);
  *(long *)(param_1 + 0x168) = param_1;
  lVar1 = 8;
  if (*(int *)(lVar3 + 100) != 2) {
    lVar1 = 0x38;
  }
  *(long *)((long)&_qcrypto_stat + lVar1) = *(long *)((long)&_qcrypto_stat + lVar1) + 1;
  if (((*(int *)(lVar3 + 0xf8) == 0x18) && (*(long *)(lVar3 + 0x108) != 0)) &&
     (*(long *)(lVar3 + 0x110) != 0)) {
    _qcrypto_aead_aes_192_fallback(param_1,0);
  }
  else {
    _qcrypto_queue_req(uVar2,*(undefined8 *)(lVar3 + 0x50));
  }
  return;
}



//------------------------------------------------------------
// _qcrypto_cra_aead_aes_sha1_init @ 00107c84 size=240
// signature: undefined _qcrypto_cra_aead_aes_sha1_init(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_cra_aead_aes_sha1_init(long param_1)

{
  char cVar1;
  ulong uVar2;
  
  *(undefined4 *)(param_1 + 4) = 0x1c8;
  if (*(long *)(param_1 + 0x50) == 0x480) {
    _printk(&DAT_0010e48d);
    return 0xffffffea;
  }
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined8 *)(param_1 + 0x98) = *(undefined8 *)(*(long *)(param_1 + 0x50) + 0x188);
  get_random_bytes(param_1 + 0xe8,0x10);
  *(undefined8 *)(param_1 + 0x90) = 0;
  *(long *)(param_1 + 0x80) = param_1 + 0x80;
  *(long *)(param_1 + 0x88) = param_1 + 0x80;
  cVar1 = DAT_0010c92d;
  *(undefined8 *)(param_1 + 0x148) = 0;
  *(undefined8 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 5;
  if (cVar1 == '\0') {
    uVar2 = crypto_alloc_sync_skcipher("cbc(aes)",0,0);
    *(ulong *)(param_1 + 0x148) = uVar2;
    if (uVar2 < 0xfffffffffffff001) {
      uVar2 = crypto_alloc_ahash("hmac(sha1)",0,0);
      *(ulong *)(param_1 + 0x150) = uVar2;
      if (uVar2 < 0xfffffffffffff001) goto LAB_00107d44;
      *(undefined8 *)(param_1 + 0x150) = 0;
      crypto_destroy_tfm(*(long *)(param_1 + 0x148),*(long *)(param_1 + 0x148) + 0x40);
    }
    *(ulong *)(param_1 + 0x148) = 0;
  }
LAB_00107d44:
  *(undefined4 *)(param_1 + 0xa4) = 2;
  return 0;
}



//------------------------------------------------------------
// _qcrypto_cra_aead_aes_exit @ 00107d78 size=116
// signature: undefined _qcrypto_cra_aead_aes_exit(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_cra_aead_aes_exit(long param_1)

{
  long lVar1;
  
  if (*(long **)(param_1 + 0x80) == (long *)(param_1 + 0x80)) {
    lVar1 = *(long *)(param_1 + 0x148);
  }
  else {
    _printk(&DAT_0010ddb1);
    lVar1 = *(long *)(param_1 + 0x148);
  }
  if (lVar1 != 0) {
    crypto_destroy_tfm(lVar1,lVar1 + 0x40);
  }
  lVar1 = *(long *)(param_1 + 0x150);
  if (lVar1 != 0) {
    crypto_destroy_tfm(lVar1,lVar1 + 0x80);
  }
  *(undefined8 *)(param_1 + 0x148) = 0;
  *(undefined8 *)(param_1 + 0x150) = 0;
  return;
}



//------------------------------------------------------------
// _qcrypto_aead_encrypt_des_cbc @ 00107df0 size=108
// signature: undefined _qcrypto_aead_encrypt_des_cbc(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_aead_encrypt_des_cbc(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x20);
  uVar2 = *(undefined8 *)(lVar3 + 0x58);
  *(undefined4 *)(param_1 + 0xcc) = 1;
  *(undefined8 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0x38);
  lVar1 = 0x10;
  if (*(int *)(lVar3 + 100) != 2) {
    lVar1 = 0x40;
  }
  *(long *)((long)&_qcrypto_stat + lVar1) = *(long *)((long)&_qcrypto_stat + lVar1) + 1;
  _qcrypto_queue_req(uVar2,*(undefined8 *)(lVar3 + 0x50));
  return;
}



//------------------------------------------------------------
// _qcrypto_aead_decrypt_des_cbc @ 00107e60 size=112
// signature: undefined _qcrypto_aead_decrypt_des_cbc(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_aead_decrypt_des_cbc(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x20);
  uVar2 = *(undefined8 *)(lVar3 + 0x58);
  *(undefined4 *)(param_1 + 0xcc) = 1;
  *(undefined8 *)(param_1 + 0x100) = 0x100000000;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0x38);
  lVar1 = 0x18;
  if (*(int *)(lVar3 + 100) != 2) {
    lVar1 = 0x48;
  }
  *(long *)((long)&_qcrypto_stat + lVar1) = *(long *)((long)&_qcrypto_stat + lVar1) + 1;
  _qcrypto_queue_req(uVar2,*(undefined8 *)(lVar3 + 0x50));
  return;
}



//------------------------------------------------------------
// _qcrypto_cra_aead_sha1_init @ 00107ed4 size=128
// signature: undefined _qcrypto_cra_aead_sha1_init(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_cra_aead_sha1_init(long param_1)

{
  undefined8 uVar1;
  
  *(undefined4 *)(param_1 + 4) = 0x1c8;
  if (*(long *)(param_1 + 0x50) == 0x480) {
    _printk(&DAT_0010e48d);
    uVar1 = 0xffffffea;
  }
  else {
    *(undefined4 *)(param_1 + 0xa0) = 0;
    *(undefined8 *)(param_1 + 0x98) = *(undefined8 *)(*(long *)(param_1 + 0x50) + 0x188);
    get_random_bytes(param_1 + 0xe8,0x10);
    uVar1 = 0;
    *(undefined8 *)(param_1 + 0x90) = 0;
    *(long *)(param_1 + 0x80) = param_1 + 0x80;
    *(long *)(param_1 + 0x88) = param_1 + 0x80;
  }
  *(undefined4 *)(param_1 + 0xa4) = 2;
  return uVar1;
}



//------------------------------------------------------------
// _qcrypto_cra_aead_exit @ 00107f58 size=52
// signature: undefined _qcrypto_cra_aead_exit(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_cra_aead_exit(long param_1)

{
  if (*(long **)(param_1 + 0x80) != (long *)(param_1 + 0x80)) {
    _printk(&DAT_0010ddb1);
  }
  return;
}



//------------------------------------------------------------
// _qcrypto_aead_encrypt_3des_cbc @ 00107f90 size=108
// signature: undefined _qcrypto_aead_encrypt_3des_cbc(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_aead_encrypt_3des_cbc(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x20);
  uVar2 = *(undefined8 *)(lVar3 + 0x58);
  *(undefined4 *)(param_1 + 0xcc) = 1;
  *(undefined8 *)(param_1 + 0x100) = 1;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0x38);
  lVar1 = 0x20;
  if (*(int *)(lVar3 + 100) != 2) {
    lVar1 = 0x50;
  }
  *(long *)((long)&_qcrypto_stat + lVar1) = *(long *)((long)&_qcrypto_stat + lVar1) + 1;
  _qcrypto_queue_req(uVar2,*(undefined8 *)(lVar3 + 0x50));
  return;
}



//------------------------------------------------------------
// _qcrypto_aead_decrypt_3des_cbc @ 00108000 size=112
// signature: undefined _qcrypto_aead_decrypt_3des_cbc(void)
// callers: []
//------------------------------------------------------------

void _qcrypto_aead_decrypt_3des_cbc(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x20);
  uVar2 = *(undefined8 *)(lVar3 + 0x58);
  *(undefined4 *)(param_1 + 0xcc) = 1;
  *(undefined8 *)(param_1 + 0x100) = 0x100000001;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0x38);
  lVar1 = 0x28;
  if (*(int *)(lVar3 + 100) != 2) {
    lVar1 = 0x58;
  }
  *(long *)((long)&_qcrypto_stat + lVar1) = *(long *)((long)&_qcrypto_stat + lVar1) + 1;
  _qcrypto_queue_req(uVar2,*(undefined8 *)(lVar3 + 0x50));
  return;
}



//------------------------------------------------------------
// _qcrypto_aead_aes_192_fallback @ 00108070 size=760
// signature: undefined _qcrypto_aead_aes_192_fallback(void)
// callers: [_qcrypto_aead_decrypt_aes_cbc, _qcrypto_aead_encrypt_aes_cbc]
//------------------------------------------------------------

int _qcrypto_aead_aes_192_fallback(long param_1,ulong param_2)

{
  long lVar1;
  void *__s1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  void *__s2;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  uint *puVar13;
  long lVar14;
  long lVar15;
  
  lVar15 = *(long *)(param_1 + 0x20);
  *(undefined8 *)(param_1 + 0x218) = 0;
  puVar13 = *(uint **)(lVar15 + 0x108);
  puVar7 = (undefined4 *)__kmalloc((ulong)*puVar13 + 0x80,0xcc0);
  if (puVar7 == (undefined4 *)0x0) {
    return -0xc;
  }
  *(uint **)(puVar7 + 0x10) = puVar13 + 0x10;
  lVar14 = *(long *)(lVar15 + 0x110);
  puVar8 = (undefined4 *)__kmalloc((ulong)*(uint *)(lVar14 + 0x40) + 0x80,0xcc0);
  if (puVar8 == (undefined4 *)0x0) {
    iVar6 = -0x16;
    goto LAB_00108274;
  }
  uVar10 = *(undefined8 *)(param_1 + 0x40);
  uVar2 = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x228) = puVar7;
  *(long *)(puVar8 + 8) = lVar14 + 0x80;
  *(long *)(param_1 + 0x168) = param_1;
  *(undefined4 **)(param_1 + 0x170) = puVar8;
  uVar10 = scatterwalk_ffwd(param_1 + 0x198,uVar10,uVar2);
  uVar9 = scatterwalk_ffwd(param_1 + 0x1d8,*(undefined8 *)(param_1 + 0x48),
                           *(undefined4 *)(param_1 + 0x30));
  iVar6 = *(int *)(param_1 + 0x34);
  if ((param_2 & 1) == 0) {
    iVar6 = iVar6 - *(int *)(lVar15 + 0xfc);
  }
  *(undefined8 *)(param_1 + 0x230) = uVar10;
  *(undefined8 *)(param_1 + 0x238) = uVar9;
  *(int *)(param_1 + 0x240) = iVar6;
  *(int *)(param_1 + 0x220) = *(int *)(param_1 + 0x30) + iVar6;
  uVar2 = *(undefined4 *)(*(long *)(lVar15 + 0x10) + -0x10);
  *(undefined4 *)(param_1 + 200) = uVar2;
  lVar14 = kmemdup(*(undefined8 *)(param_1 + 0x38),uVar2,0xa20);
  *(long *)(param_1 + 0x218) = lVar14;
  if (lVar14 == 0) {
    iVar6 = -0x16;
  }
  else {
    uVar11 = *(undefined8 *)(param_1 + 0x238);
    lVar1 = param_1 + 0x80;
    uVar12 = *(undefined8 *)(param_1 + 0x230);
    __s1 = (void *)(param_1 + 0x178);
    uVar2 = *(undefined4 *)(param_1 + 0x240);
    *(long *)(puVar7 + 2) = lVar14;
    *(undefined8 *)(puVar7 + 4) = uVar12;
    *(undefined8 *)(puVar7 + 6) = uVar11;
    uVar3 = *(undefined4 *)(param_1 + 0x220);
    *puVar7 = uVar2;
    if ((param_2 & 1) == 0) {
      uVar9 = *(undefined8 *)(param_1 + 0x40);
      puVar8[0xc] = uVar3;
      *(undefined8 *)(puVar8 + 0xe) = uVar9;
      *(void **)(puVar8 + 0x10) = __s1;
      *(code **)(puVar8 + 4) = _aead_aes_fb_stage1_ahash_complete;
      *(long *)(puVar8 + 6) = lVar1;
      puVar8[10] = 0x400;
      iVar6 = crypto_ahash_digest(puVar8);
      if (iVar6 == 0) {
        __s2 = (void *)__kmalloc(*(undefined4 *)(lVar15 + 0xfc),0xcc0);
        if (__s2 == (void *)0x0) {
          iVar6 = -0xc;
          goto LAB_0010826c;
        }
        scatterwalk_map_and_copy
                  (__s2,uVar10,*(int *)(param_1 + 0x34) - *(int *)(lVar15 + 0xfc),
                   *(int *)(lVar15 + 0xfc),0);
        iVar6 = bcmp(__s1,__s2,(ulong)*(uint *)(lVar15 + 0xfc));
        if (iVar6 == 0) {
          lVar15 = *(long *)(param_1 + 0x228);
          *(code **)(lVar15 + 0x30) = _aead_aes_fb_stage2_decrypt_complete;
          *(long *)(lVar15 + 0x38) = lVar1;
          *(undefined4 *)(lVar15 + 0x48) = 0x400;
          iVar6 = crypto_skcipher_decrypt();
        }
        else {
          iVar6 = -0x4a;
        }
        kfree(__s2);
      }
    }
    else {
      uVar10 = *(undefined8 *)(param_1 + 0x48);
      puVar8[0xc] = uVar3;
      *(undefined8 *)(puVar8 + 0xe) = uVar10;
      *(void **)(puVar8 + 0x10) = __s1;
      *(code **)(puVar7 + 0xc) = _aead_aes_fb_stage1_encrypt_complete;
      *(long *)(puVar7 + 0xe) = lVar1;
      puVar7[0x12] = 0x400;
      iVar6 = crypto_skcipher_encrypt(puVar7);
      if (iVar6 == 0) {
        uVar4 = *(uint *)(param_1 + 200);
        if ((0x10 < uVar4) && ((_qcrypto_aead_aes_192_fallback___already_done & 1) == 0)) {
          _qcrypto_aead_aes_192_fallback___already_done = 1;
          __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n"
                        ,(ulong)uVar4,
                        "field \"ctx->iv\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcrypto.c:3352"
                        ,0x10);
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x800,0x108368);
          (*pcVar5)();
        }
        memcpy((void *)(lVar15 + 0xa8),*(void **)(param_1 + 0x218),(ulong)uVar4);
        lVar14 = *(long *)(param_1 + 0x170);
        *(code **)(lVar14 + 0x10) = _aead_aes_fb_stage2_ahash_complete;
        *(long *)(lVar14 + 0x18) = lVar1;
        *(undefined4 *)(lVar14 + 0x28) = 0x400;
        iVar6 = crypto_ahash_digest();
        if (iVar6 == 0) {
          scatterwalk_map_and_copy
                    (__s1,uVar9,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(lVar15 + 0xfc),1);
          goto LAB_0010826c;
        }
      }
    }
    if (iVar6 == -0x73) {
      return -0x73;
    }
    if (iVar6 == -0x10) {
      return -0x10;
    }
  }
LAB_0010826c:
  kfree_sensitive(puVar7);
  puVar7 = puVar8;
LAB_00108274:
  kfree_sensitive(puVar7);
  kfree(*(undefined8 *)(param_1 + 0x218));
  return iVar6;
}



//------------------------------------------------------------
// _aead_aes_fb_stage1_encrypt_complete @ 00108370 size=316
// signature: undefined _aead_aes_fb_stage1_encrypt_complete(void)
// callers: []
//------------------------------------------------------------

void _aead_aes_fb_stage1_encrypt_complete(long param_1,int param_2)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  
  lVar4 = *(long *)(param_1 + 0x18);
  lVar5 = *(long *)(lVar4 + 0xe8);
  uVar1 = *(uint *)(lVar4 + 0x48);
  lVar6 = *(long *)(lVar5 + 0x20);
  if ((0x10 < uVar1) && ((_aead_aes_fb_stage1_encrypt_complete___already_done & 1) == 0)) {
    _aead_aes_fb_stage1_encrypt_complete___already_done = 1;
    __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
                  (ulong)uVar1,
                  "field \"ctx->iv\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcrypto.c:3271"
                  ,0x10);
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1084ac);
    (*pcVar3)();
  }
  memcpy((void *)(lVar6 + 0xa8),*(void **)(lVar4 + 0x198),(ulong)uVar1);
  if (param_2 == 0) {
    lVar2 = *(long *)(lVar4 + 0xf0);
    *(code **)(lVar2 + 0x10) = _aead_aes_fb_stage2_ahash_complete;
    *(long *)(lVar2 + 0x18) = lVar4;
    *(undefined4 *)(lVar2 + 0x28) = 0x400;
    param_2 = crypto_ahash_digest();
    if (param_2 == -0x73) {
      return;
    }
    if (param_2 == -0x10) {
      return;
    }
    if (param_2 == 0) {
      scatterwalk_map_and_copy
                (lVar4 + 0xf8,*(undefined8 *)(lVar4 + 0x1b8),*(undefined4 *)(lVar5 + 0x34),
                 *(undefined4 *)(lVar6 + 0xfc),1);
    }
  }
  lVar5 = *(long *)(lVar4 + 0xe8);
  if (*(long *)(lVar4 + 0x1a8) != 0) {
    kfree_sensitive();
  }
  if (*(long *)(lVar4 + 0xf0) != 0) {
    kfree_sensitive();
  }
  *(undefined8 *)(lVar4 + 0x1a8) = 0;
  *(undefined8 *)(lVar4 + 0xf0) = 0;
  kfree(*(undefined8 *)(lVar4 + 0x198));
  pcVar3 = *(code **)(lVar5 + 0x10);
  if (*(int *)(pcVar3 + -4) != -0x223f6f35) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x108418);
    (*pcVar3)();
  }
  (*pcVar3)(lVar5,param_2);
  return;
}



//------------------------------------------------------------
// _aead_aes_fb_stage1_ahash_complete @ 001084b4 size=288
// signature: undefined _aead_aes_fb_stage1_ahash_complete(void)
// callers: []
//------------------------------------------------------------

void _aead_aes_fb_stage1_ahash_complete(long param_1,int param_2)

{
  int iVar1;
  void *__s2;
  code *pcVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = *(long *)(param_1 + 0x18);
  if (param_2 == 0) {
    lVar5 = *(long *)(lVar4 + 0xe8);
    lVar3 = *(long *)(lVar5 + 0x20);
    __s2 = (void *)__kmalloc(*(undefined4 *)(lVar3 + 0xfc),0xcc0);
    if (__s2 == (void *)0x0) {
      param_2 = -0xc;
    }
    else {
      scatterwalk_map_and_copy
                (__s2,*(undefined8 *)(lVar4 + 0x1b0),*(int *)(lVar5 + 0x34) - *(int *)(lVar3 + 0xfc)
                 ,*(int *)(lVar3 + 0xfc),0);
      iVar1 = bcmp((void *)(lVar4 + 0xf8),__s2,(ulong)*(uint *)(lVar3 + 0xfc));
      kfree(__s2);
      if (iVar1 == 0) {
        lVar3 = *(long *)(lVar4 + 0x1a8);
        *(code **)(lVar3 + 0x30) = _aead_aes_fb_stage2_decrypt_complete;
        *(long *)(lVar3 + 0x38) = lVar4;
        *(undefined4 *)(lVar3 + 0x48) = 0x400;
        param_2 = crypto_skcipher_decrypt();
        if (param_2 == -0x73) {
          return;
        }
        if (param_2 == -0x10) {
          return;
        }
      }
      else {
        param_2 = -0x4a;
      }
    }
  }
  lVar3 = *(long *)(lVar4 + 0xe8);
  if (*(long *)(lVar4 + 0x1a8) != 0) {
    kfree_sensitive();
  }
  if (*(long *)(lVar4 + 0xf0) != 0) {
    kfree_sensitive();
  }
  *(undefined8 *)(lVar4 + 0x1a8) = 0;
  *(undefined8 *)(lVar4 + 0xf0) = 0;
  kfree(*(undefined8 *)(lVar4 + 0x198));
  pcVar2 = *(code **)(lVar3 + 0x10);
  if (*(int *)(pcVar2 + -4) != -0x223f6f35) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x108524);
    (*pcVar2)();
  }
  (*pcVar2)(lVar3,param_2);
  return;
}



//------------------------------------------------------------
// _aead_aes_fb_stage2_ahash_complete @ 001085d8 size=168
// signature: undefined _aead_aes_fb_stage2_ahash_complete(void)
// callers: []
//------------------------------------------------------------

void _aead_aes_fb_stage2_ahash_complete(long param_1,int param_2)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x18);
  if (param_2 == 0) {
    scatterwalk_map_and_copy
              (lVar3 + 0xf8,*(undefined8 *)(lVar3 + 0x1b8),
               *(undefined4 *)(*(long *)(lVar3 + 0xe8) + 0x34),
               *(undefined4 *)(*(long *)(*(long *)(lVar3 + 0xe8) + 0x20) + 0xfc),1);
  }
  lVar2 = *(long *)(lVar3 + 0xe8);
  if (*(long *)(lVar3 + 0x1a8) != 0) {
    kfree_sensitive();
  }
  if (*(long *)(lVar3 + 0xf0) != 0) {
    kfree_sensitive();
  }
  *(undefined8 *)(lVar3 + 0x1a8) = 0;
  *(undefined8 *)(lVar3 + 0xf0) = 0;
  kfree(*(undefined8 *)(lVar3 + 0x198));
  pcVar1 = *(code **)(lVar2 + 0x10);
  if (*(int *)(pcVar1 + -4) != -0x223f6f35) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108668);
    (*pcVar1)();
  }
  (*pcVar1)(lVar2,param_2);
  return;
}



//------------------------------------------------------------
// _aead_aes_fb_stage2_decrypt_complete @ 00108684 size=132
// signature: undefined _aead_aes_fb_stage2_decrypt_complete(void)
// callers: []
//------------------------------------------------------------

void _aead_aes_fb_stage2_decrypt_complete(long param_1,undefined4 param_2)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x18);
  lVar2 = *(long *)(lVar3 + 0xe8);
  if (*(long *)(lVar3 + 0x1a8) != 0) {
    kfree_sensitive();
  }
  if (*(long *)(lVar3 + 0xf0) != 0) {
    kfree_sensitive();
  }
  *(undefined8 *)(lVar3 + 0x1a8) = 0;
  *(undefined8 *)(lVar3 + 0xf0) = 0;
  kfree(*(undefined8 *)(lVar3 + 0x198));
  pcVar1 = *(code **)(lVar2 + 0x10);
  if (*(int *)(pcVar1 + -4) != -0x223f6f35) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1086f0);
    (*pcVar1)();
  }
  (*pcVar1)(lVar2,param_2);
  return;
}



//------------------------------------------------------------
// _qcrypto_cra_aead_aes_sha256_init @ 0010870c size=240
// signature: undefined _qcrypto_cra_aead_aes_sha256_init(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_cra_aead_aes_sha256_init(long param_1)

{
  char cVar1;
  ulong uVar2;
  
  *(undefined4 *)(param_1 + 4) = 0x1c8;
  if (*(long *)(param_1 + 0x50) == 0x480) {
    _printk(&DAT_0010e48d);
    return 0xffffffea;
  }
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined8 *)(param_1 + 0x98) = *(undefined8 *)(*(long *)(param_1 + 0x50) + 0x188);
  get_random_bytes(param_1 + 0xe8,0x10);
  *(undefined8 *)(param_1 + 0x90) = 0;
  *(long *)(param_1 + 0x80) = param_1 + 0x80;
  *(long *)(param_1 + 0x88) = param_1 + 0x80;
  cVar1 = DAT_0010c92d;
  *(undefined8 *)(param_1 + 0x148) = 0;
  *(undefined8 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 5;
  if (cVar1 == '\0') {
    uVar2 = crypto_alloc_sync_skcipher("cbc(aes)",0,0);
    *(ulong *)(param_1 + 0x148) = uVar2;
    if (uVar2 < 0xfffffffffffff001) {
      uVar2 = crypto_alloc_ahash("hmac(sha256)",0,0);
      *(ulong *)(param_1 + 0x150) = uVar2;
      if (uVar2 < 0xfffffffffffff001) goto LAB_001087cc;
      *(undefined8 *)(param_1 + 0x150) = 0;
      crypto_destroy_tfm(*(long *)(param_1 + 0x148),*(long *)(param_1 + 0x148) + 0x40);
    }
    *(ulong *)(param_1 + 0x148) = 0;
  }
LAB_001087cc:
  *(undefined4 *)(param_1 + 0xa4) = 3;
  return 0;
}



//------------------------------------------------------------
// _qcrypto_cra_aead_sha256_init @ 00108800 size=128
// signature: undefined _qcrypto_cra_aead_sha256_init(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_cra_aead_sha256_init(long param_1)

{
  undefined8 uVar1;
  
  *(undefined4 *)(param_1 + 4) = 0x1c8;
  if (*(long *)(param_1 + 0x50) == 0x480) {
    _printk(&DAT_0010e48d);
    uVar1 = 0xffffffea;
  }
  else {
    *(undefined4 *)(param_1 + 0xa0) = 0;
    *(undefined8 *)(param_1 + 0x98) = *(undefined8 *)(*(long *)(param_1 + 0x50) + 0x188);
    get_random_bytes(param_1 + 0xe8,0x10);
    uVar1 = 0;
    *(undefined8 *)(param_1 + 0x90) = 0;
    *(long *)(param_1 + 0x80) = param_1 + 0x80;
    *(long *)(param_1 + 0x88) = param_1 + 0x80;
  }
  *(undefined4 *)(param_1 + 0xa4) = 3;
  return uVar1;
}



//------------------------------------------------------------
// _sha1_hmac_init @ 00108884 size=184
// signature: undefined _sha1_hmac_init(void)
// callers: []
//------------------------------------------------------------

undefined8 _sha1_hmac_init(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = *(long *)(param_1 + 0x20);
  lVar4 = *(long *)(lVar3 + 0x58);
  *(undefined2 *)(param_1 + 0x110) = 1;
  *(undefined4 *)(param_1 + 0x154) = 0;
  DAT_0010dbb8 = DAT_0010dbb8 + 1;
  *(undefined8 *)(param_1 + 0xf8) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0;
  *(undefined8 *)(param_1 + 0x108) = 0;
  *(undefined8 *)(param_1 + 0x112) = 0;
  *(undefined8 *)(param_1 + 0x11a) = 0;
  *(undefined8 *)(param_1 + 0x122) = 0;
  *(undefined8 *)(param_1 + 0x12a) = 0;
  *(undefined8 *)(param_1 + 0x132) = 0;
  *(undefined8 *)(param_1 + 0x13a) = 0;
  uVar2 = DAT_0010c8c8;
  uVar1 = _std_init_vector_sha1_uint8;
  *(undefined4 *)(param_1 + 0x208) = 0xf0e1d2c3;
  *(undefined8 *)(param_1 + 0x142) = 0;
  *(undefined8 *)(param_1 + 0x14a) = 0;
  *(undefined8 *)(param_1 + 0x1f8) = uVar1;
  *(undefined8 *)(param_1 + 0x200) = uVar2;
  *(undefined4 *)(lVar3 + 0x68) = 0x14;
  if (*(char *)(lVar4 + 0x13) != '\0') {
    *(undefined4 *)(lVar3 + 100) = 2;
    return 0;
  }
  *(undefined4 *)(lVar3 + 100) = 0;
  lVar3 = 0;
  lVar4 = *(long *)(param_1 + 0x20);
  do {
    *(byte *)(param_1 + 0x112 + lVar3) = *(byte *)(lVar4 + 0x70 + lVar3) ^ 0x36;
    lVar3 = lVar3 + 1;
  } while (lVar3 != 0x40);
  *(undefined4 *)(param_1 + 0x154) = 0x40;
  return 0;
}



//------------------------------------------------------------
// _sha1_hmac_update @ 00108940 size=96
// signature: undefined _sha1_hmac_update(void)
// callers: []
//------------------------------------------------------------

undefined8 _sha1_hmac_update(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((*(char *)(*(long *)(*(long *)(param_1 + 0x20) + 0x58) + 0x19) == '\0') ||
     (iVar1 = _copy_source(param_1), iVar1 == 0)) {
    *(ulong *)(param_1 + 0x108) = *(long *)(param_1 + 0x108) + (ulong)*(uint *)(param_1 + 0x30);
    uVar2 = _sha_update(param_1);
  }
  else {
    uVar2 = 0xfffffff4;
  }
  return uVar2;
}



//------------------------------------------------------------
// _sha1_hmac_final @ 001089a4 size=344
// signature: undefined _sha1_hmac_final(void)
// callers: []
//------------------------------------------------------------

void _sha1_hmac_final(long param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iVar7;
  undefined8 uVar8;
  long lVar9;
  undefined4 uVar10;
  long lVar11;
  ulong uVar12;
  
  if (*(char *)(*(long *)(*(long *)(param_1 + 0x20) + 0x58) + 0x13) == '\0') {
    iVar7 = _sha_hmac_inner_hash(param_1);
    if (iVar7 == 0) {
      lVar9 = *(long *)(param_1 + 0x20);
      uVar1 = param_1 + 0x197;
      lVar11 = 0;
      uVar12 = uVar1 & 0xffffffffffffffc0;
      uVar8 = *(undefined8 *)(lVar9 + 0x58);
      do {
        *(byte *)(uVar12 + lVar11) = *(byte *)(lVar9 + 0x70 + lVar11) ^ 0x5c;
        lVar11 = lVar11 + 1;
      } while (lVar11 != 0x40);
      uVar2 = *(undefined8 *)(param_1 + 0x1f8);
      uVar3 = *(undefined8 *)(param_1 + 0x200);
      *(undefined4 *)(uVar12 + 0x50) = *(undefined4 *)(param_1 + 0x208);
      *(undefined8 *)(uVar12 + 0x40) = uVar2;
      *(undefined8 *)(uVar12 + 0x48) = uVar3;
      *(uint *)(param_1 + 0x220) = (uint)uVar1 & 0xfc0;
      *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0x38);
      *(undefined4 *)(param_1 + 0x224) = 0x54;
      *(ulong *)(param_1 + 0x218) =
           (((long)(uVar1 * 0x100) >> 8) + 0x8000000000U >> 0xc) * 0x40 + -0x1fffffffe;
      *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0x30);
      *(long *)(param_1 + 0x38) = param_1 + 0x218;
      *(undefined4 *)(param_1 + 0x30) = 0x54;
      *(undefined2 *)(param_1 + 0x110) = 1;
      *(undefined4 *)(param_1 + 0x154) = 0;
      *(undefined8 *)(param_1 + 0xf8) = 0;
      *(undefined8 *)(param_1 + 0x100) = 0;
      *(undefined8 *)(param_1 + 0x108) = 0;
      uVar6 = DAT_0010ed87;
      uVar5 = DAT_0010ed7f;
      uVar4 = DAT_0010ed77;
      uVar3 = DAT_0010c8c8;
      uVar2 = _std_init_vector_sha1_uint8;
      if (*(int *)(lVar9 + 100) == 0) {
        uVar10 = 0x14;
        *(undefined4 *)(param_1 + 0x208) = 0xf0e1d2c3;
        *(undefined8 *)(param_1 + 0x1f8) = uVar2;
        *(undefined8 *)(param_1 + 0x200) = uVar3;
      }
      else {
        uVar10 = 0x20;
        *(undefined8 *)(param_1 + 0x1f8) = _std_init_vector_sha256_uint8;
        *(undefined8 *)(param_1 + 0x200) = uVar4;
        *(undefined8 *)(param_1 + 0x208) = uVar5;
        *(undefined8 *)(param_1 + 0x210) = uVar6;
      }
      *(undefined4 *)(lVar9 + 0x68) = uVar10;
      *(undefined1 *)(param_1 + 0x111) = 1;
      _qcrypto_queue_req(uVar8,*(undefined8 *)(lVar9 + 0x50),param_1);
    }
  }
  else {
    _sha_final(param_1);
  }
  return;
}



//------------------------------------------------------------
// _sha1_hmac_digest @ 00108b00 size=200
// signature: undefined _sha1_hmac_digest(void)
// callers: []
//------------------------------------------------------------

undefined8 _sha1_hmac_digest(long param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  *(undefined4 *)(param_1 + 0x154) = 0;
  *(undefined2 *)(param_1 + 0x110) = 1;
  *(undefined8 *)(param_1 + 0xf8) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0;
  *(undefined8 *)(param_1 + 0x108) = 0;
  uVar1 = DAT_0010c8c8;
  uVar3 = _std_init_vector_sha1_uint8;
  DAT_0010dbb8 = DAT_0010dbb8 + 1;
  *(undefined4 *)(param_1 + 0x208) = 0xf0e1d2c3;
  *(undefined8 *)(param_1 + 0x1f8) = uVar3;
  *(undefined8 *)(param_1 + 0x200) = uVar1;
  *(undefined8 *)(*(long *)(param_1 + 0x20) + 100) = 0x1400000002;
  lVar5 = *(long *)(param_1 + 0x20);
  lVar4 = *(long *)(lVar5 + 0x58);
  if ((*(char *)(lVar4 + 0x19) == '\0') || (iVar2 = _copy_source(param_1), iVar2 == 0)) {
    *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0x30);
    *(undefined2 *)(param_1 + 0x110) = 0x101;
    uVar3 = _qcrypto_queue_req(lVar4,*(undefined8 *)(lVar5 + 0x50),param_1);
  }
  else {
    uVar3 = 0xfffffff4;
  }
  return uVar3;
}



//------------------------------------------------------------
// _sha1_hmac_export @ 00108bcc size=116
// signature: undefined _sha1_hmac_export(void)
// callers: []
//------------------------------------------------------------

undefined8 _sha1_hmac_export(long param_1,uint *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  
  *(undefined8 *)(param_2 + 6) = *(undefined8 *)(param_1 + 0x108);
  uVar4 = (*(uint *)(param_1 + 0x1f8) & 0xff00ff00) >> 8 |
          (*(uint *)(param_1 + 0x1f8) & 0xff00ff) << 8;
  *param_2 = uVar4 >> 0x10 | uVar4 << 0x10;
  uVar4 = (*(uint *)(param_1 + 0x1fc) & 0xff00ff00) >> 8 |
          (*(uint *)(param_1 + 0x1fc) & 0xff00ff) << 8;
  param_2[1] = uVar4 >> 0x10 | uVar4 << 0x10;
  uVar4 = (*(uint *)(param_1 + 0x200) & 0xff00ff00) >> 8 |
          (*(uint *)(param_1 + 0x200) & 0xff00ff) << 8;
  param_2[2] = uVar4 >> 0x10 | uVar4 << 0x10;
  uVar4 = (*(uint *)(param_1 + 0x204) & 0xff00ff00) >> 8 |
          (*(uint *)(param_1 + 0x204) & 0xff00ff) << 8;
  param_2[3] = uVar4 >> 0x10 | uVar4 << 0x10;
  uVar4 = (*(uint *)(param_1 + 0x208) & 0xff00ff00) >> 8 |
          (*(uint *)(param_1 + 0x208) & 0xff00ff) << 8;
  param_2[4] = uVar4 >> 0x10 | uVar4 << 0x10;
  uVar2 = *(undefined8 *)(param_1 + 0x12a);
  uVar1 = *(undefined8 *)(param_1 + 0x112);
  uVar3 = *(undefined8 *)(param_1 + 0x11a);
  *(undefined8 *)(param_2 + 0xc) = *(undefined8 *)(param_1 + 0x122);
  *(undefined8 *)(param_2 + 0xe) = uVar2;
  *(undefined8 *)(param_2 + 8) = uVar1;
  *(undefined8 *)(param_2 + 10) = uVar3;
  uVar2 = *(undefined8 *)(param_1 + 0x14a);
  uVar1 = *(undefined8 *)(param_1 + 0x132);
  uVar3 = *(undefined8 *)(param_1 + 0x13a);
  *(undefined8 *)(param_2 + 0x14) = *(undefined8 *)(param_1 + 0x142);
  *(undefined8 *)(param_2 + 0x16) = uVar2;
  *(undefined8 *)(param_2 + 0x10) = uVar1;
  *(undefined8 *)(param_2 + 0x12) = uVar3;
  return 0;
}



//------------------------------------------------------------
// _sha1_hmac_import @ 00108c44 size=300
// signature: undefined _sha1_hmac_import(void)
// callers: []
//------------------------------------------------------------

undefined8 _sha1_hmac_import(long param_1,uint *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  long lVar7;
  undefined1 *puVar8;
  long lVar9;
  uint uVar10;
  undefined1 *puVar11;
  long lVar12;
  
  lVar7 = *(long *)(param_2 + 6);
  *(long *)(param_1 + 0x108) = lVar7;
  uVar2 = *(undefined8 *)(param_2 + 0x16);
  uVar1 = *(undefined8 *)(param_2 + 0x10);
  uVar3 = *(undefined8 *)(param_2 + 0x12);
  *(undefined8 *)(param_1 + 0x142) = *(undefined8 *)(param_2 + 0x14);
  *(undefined8 *)(param_1 + 0x14a) = uVar2;
  *(undefined8 *)(param_1 + 0x132) = uVar1;
  *(undefined8 *)(param_1 + 0x13a) = uVar3;
  uVar2 = *(undefined8 *)(param_2 + 0xe);
  uVar1 = *(undefined8 *)(param_2 + 8);
  uVar3 = *(undefined8 *)(param_2 + 10);
  *(undefined8 *)(param_1 + 0x122) = *(undefined8 *)(param_2 + 0xc);
  *(undefined8 *)(param_1 + 0x12a) = uVar2;
  *(undefined8 *)(param_1 + 0x112) = uVar1;
  *(undefined8 *)(param_1 + 0x11a) = uVar3;
  puVar8 = (undefined1 *)(param_1 + 0x1f8);
  if (*(ulong *)(param_2 + 6) >= 0x41) {
    lVar7 = lVar7 + 0x40;
  }
  *(bool *)(param_1 + 0x110) = *(ulong *)(param_2 + 6) < 0x41;
  *(uint *)(param_1 + 0xf8) = (uint)lVar7 & 0xffffffc0;
  *(int *)(param_1 + 0xfc) = (int)((ulong)lVar7 >> 0x20);
  uVar4 = *(uint *)(*(long *)(param_1 + 0x20) + 0x68);
  if (uVar4 < 4) {
    puVar6 = param_2;
  }
  else {
    uVar10 = uVar4 >> 2;
    puVar5 = param_2;
    puVar11 = puVar8;
    do {
      uVar10 = uVar10 - 1;
      *puVar11 = *(undefined1 *)((long)puVar5 + 3);
      puVar11[1] = (char)*(undefined2 *)((long)puVar5 + 2);
      puVar11[2] = (char)(*puVar5 >> 8);
      puVar8 = puVar11 + 4;
      puVar6 = puVar5 + 1;
      puVar11[3] = (char)*puVar5;
      puVar5 = puVar6;
      puVar11 = puVar8;
    } while (uVar10 != 0);
  }
  uVar4 = uVar4 & 3;
  lVar9 = 0x18;
  lVar7 = lVar9;
  if (uVar4 != 1) {
    if (uVar4 == 2) {
      lVar7 = 0x10;
      lVar12 = 1;
      puVar11 = puVar8;
    }
    else {
      if (uVar4 != 3) goto LAB_00108d5c;
      lVar7 = 8;
      lVar9 = 0x10;
      lVar12 = 2;
      *puVar8 = *(undefined1 *)((long)puVar6 + 3);
      puVar11 = puVar8 + 1;
    }
    puVar8 = puVar8 + lVar12;
    *puVar11 = (char)(*puVar6 >> lVar9);
  }
  *puVar8 = (char)(*puVar6 >> lVar7);
LAB_00108d5c:
  *(uint *)(param_1 + 0x154) = param_2[6] & 0x3f;
  return 0;
}



//------------------------------------------------------------
// _sha1_hmac_setkey @ 00108d74 size=148
// signature: undefined _sha1_hmac_setkey(void)
// callers: []
//------------------------------------------------------------

int _sha1_hmac_setkey(long param_1,void *param_2,uint param_3)

{
  int iVar1;
  
  *(undefined8 *)(param_1 + 0xf0) = 0;
  *(undefined8 *)(param_1 + 0x120) = 0;
  *(undefined8 *)(param_1 + 0x128) = 0;
  *(undefined8 *)(param_1 + 0x110) = 0;
  *(undefined8 *)(param_1 + 0x118) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0;
  *(undefined8 *)(param_1 + 0x108) = 0;
  *(undefined8 *)(param_1 + 0xf8) = 0;
  if (param_3 < 0x41) {
    memcpy((undefined8 *)(param_1 + 0xf0),param_2,(ulong)param_3);
    iVar1 = 0;
  }
  else {
    *(undefined8 *)(param_1 + 0xe4) = 0x1400000000;
    iVar1 = _sha_hmac_setkey(param_1,param_2,param_3);
    if (iVar1 != 0) {
      _printk(&DAT_0010dde8);
    }
    param_3 = 0x40;
  }
  *(uint *)(param_1 + 0xec) = param_3;
  return iVar1;
}



//------------------------------------------------------------
// _qcrypto_ahash_hmac_cra_init @ 00108e0c size=244
// signature: undefined _qcrypto_ahash_hmac_cra_init(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _qcrypto_ahash_hmac_cra_init(undefined4 *param_1)

{
  undefined4 *puVar1;
  long lVar2;
  undefined8 uVar3;
  
  puVar1 = param_1 + 0x10;
  param_1[-0x10] = 0x1d8;
  uVar3 = *(undefined8 *)(*(long *)(param_1 + 4) + 0x348);
  param_1[0x18] = 0;
  *(undefined8 *)(param_1 + 0x2c) = 0;
  *(undefined8 *)(param_1 + 0x14) = 0;
  *(undefined8 *)(param_1 + 0x16) = uVar3;
  *(undefined4 **)(param_1 + 0x10) = puVar1;
  *(undefined4 **)(param_1 + 0x12) = puVar1;
  lVar2 = kmalloc_trace(__dev_info,0xcc0,600);
  if (lVar2 == 0) {
    *(undefined8 *)(param_1 + 0x2c) = 0;
    if ((*(undefined4 **)(param_1 + 0x10) != puVar1) &&
       (_printk(&DAT_0010e569,"_qcrypto_ahash_cra_exit"), *(long *)(param_1 + 0x2c) != 0)) {
      kfree_sensitive();
      *(undefined8 *)(param_1 + 0x2c) = 0;
      return 0xfffffff4;
    }
    uVar3 = 0xfffffff4;
  }
  else {
    *(undefined4 **)(lVar2 + 0x20) = param_1;
    *(long *)(param_1 + 0x2c) = lVar2;
    param_1[0x2e] = 0;
    __init_swait_queue_head(param_1 + 0x30,"&x->wait",&init_completion___key);
    uVar3 = 0;
    lVar2 = *(long *)(param_1 + 0x2c);
    *(code **)(lVar2 + 0x10) = _crypto_sha_hmac_ahash_req_complete;
    *(undefined4 **)(lVar2 + 0x18) = param_1 + 0x2e;
    *(undefined4 *)(lVar2 + 0x28) = 0x400;
    *param_1 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// _sha256_hmac_init @ 00108f04 size=184
// signature: undefined _sha256_hmac_init(void)
// callers: []
//------------------------------------------------------------

undefined8 _sha256_hmac_init(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  
  lVar5 = *(long *)(param_1 + 0x20);
  lVar6 = *(long *)(lVar5 + 0x58);
  *(undefined4 *)(param_1 + 0x154) = 0;
  *(undefined2 *)(param_1 + 0x110) = 1;
  DAT_0010dbc0 = DAT_0010dbc0 + 1;
  *(undefined8 *)(param_1 + 0xf8) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0;
  *(undefined8 *)(param_1 + 0x108) = 0;
  *(undefined8 *)(param_1 + 0x112) = 0;
  *(undefined8 *)(param_1 + 0x11a) = 0;
  uVar4 = DAT_0010ed87;
  uVar3 = DAT_0010ed7f;
  *(undefined8 *)(param_1 + 0x122) = 0;
  *(undefined8 *)(param_1 + 0x12a) = 0;
  uVar2 = DAT_0010ed77;
  uVar1 = _std_init_vector_sha256_uint8;
  *(undefined8 *)(param_1 + 0x132) = 0;
  *(undefined8 *)(param_1 + 0x13a) = 0;
  *(undefined8 *)(param_1 + 0x142) = 0;
  *(undefined8 *)(param_1 + 0x14a) = 0;
  *(undefined8 *)(param_1 + 0x210) = uVar4;
  *(undefined8 *)(param_1 + 0x208) = uVar3;
  *(undefined8 *)(param_1 + 0x1f8) = uVar1;
  *(undefined8 *)(param_1 + 0x200) = uVar2;
  *(undefined4 *)(lVar5 + 0x68) = 0x20;
  if (*(char *)(lVar6 + 0x13) != '\0') {
    *(undefined4 *)(lVar5 + 100) = 3;
    return 0;
  }
  *(undefined4 *)(lVar5 + 100) = 1;
  lVar5 = 0;
  lVar6 = *(long *)(param_1 + 0x20);
  do {
    *(byte *)(param_1 + 0x112 + lVar5) = *(byte *)(lVar6 + 0x70 + lVar5) ^ 0x36;
    lVar5 = lVar5 + 1;
  } while (lVar5 != 0x40);
  *(undefined4 *)(param_1 + 0x154) = 0x40;
  return 0;
}



//------------------------------------------------------------
// _sha256_hmac_update @ 00108fc0 size=96
// signature: undefined _sha256_hmac_update(void)
// callers: []
//------------------------------------------------------------

undefined8 _sha256_hmac_update(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((*(char *)(*(long *)(*(long *)(param_1 + 0x20) + 0x58) + 0x19) == '\0') ||
     (iVar1 = _copy_source(param_1), iVar1 == 0)) {
    *(ulong *)(param_1 + 0x108) = *(long *)(param_1 + 0x108) + (ulong)*(uint *)(param_1 + 0x30);
    uVar2 = _sha_update(param_1);
  }
  else {
    uVar2 = 0xfffffff4;
  }
  return uVar2;
}



//------------------------------------------------------------
// _sha256_hmac_final @ 00109024 size=348
// signature: undefined _sha256_hmac_final(void)
// callers: []
//------------------------------------------------------------

void _sha256_hmac_final(long param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  undefined4 uVar9;
  long lVar10;
  ulong uVar11;
  undefined8 uVar12;
  
  if (*(char *)(*(long *)(*(long *)(param_1 + 0x20) + 0x58) + 0x13) == '\0') {
    iVar6 = _sha_hmac_inner_hash(param_1);
    if (iVar6 == 0) {
      lVar8 = *(long *)(param_1 + 0x20);
      uVar1 = param_1 + 0x197;
      lVar10 = 0;
      uVar11 = uVar1 & 0xffffffffffffffc0;
      uVar7 = *(undefined8 *)(lVar8 + 0x58);
      do {
        *(byte *)(uVar11 + lVar10) = *(byte *)(lVar8 + 0x70 + lVar10) ^ 0x5c;
        lVar10 = lVar10 + 1;
      } while (lVar10 != 0x40);
      uVar12 = *(undefined8 *)(param_1 + 0x210);
      uVar2 = *(undefined8 *)(param_1 + 0x1f8);
      uVar3 = *(undefined8 *)(param_1 + 0x200);
      *(undefined8 *)(uVar11 + 0x50) = *(undefined8 *)(param_1 + 0x208);
      *(undefined8 *)(uVar11 + 0x58) = uVar12;
      *(undefined8 *)(uVar11 + 0x40) = uVar2;
      *(undefined8 *)(uVar11 + 0x48) = uVar3;
      *(uint *)(param_1 + 0x220) = (uint)uVar1 & 0xfc0;
      *(undefined4 *)(param_1 + 0x224) = 0x60;
      *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0x38);
      *(ulong *)(param_1 + 0x218) =
           (((long)(uVar1 * 0x100) >> 8) + 0x8000000000U >> 0xc) * 0x40 + -0x1fffffffe;
      *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0x30);
      *(long *)(param_1 + 0x38) = param_1 + 0x218;
      *(undefined4 *)(param_1 + 0x30) = 0x60;
      *(undefined2 *)(param_1 + 0x110) = 1;
      *(undefined4 *)(param_1 + 0x154) = 0;
      *(undefined8 *)(param_1 + 0xf8) = 0;
      *(undefined8 *)(param_1 + 0x100) = 0;
      *(undefined8 *)(param_1 + 0x108) = 0;
      uVar5 = DAT_0010ed87;
      uVar4 = DAT_0010ed7f;
      uVar12 = DAT_0010ed77;
      uVar3 = DAT_0010c8c8;
      uVar2 = _std_init_vector_sha1_uint8;
      if (*(int *)(lVar8 + 100) == 0) {
        uVar9 = 0x14;
        *(undefined4 *)(param_1 + 0x208) = 0xf0e1d2c3;
        *(undefined8 *)(param_1 + 0x1f8) = uVar2;
        *(undefined8 *)(param_1 + 0x200) = uVar3;
      }
      else {
        uVar9 = 0x20;
        *(undefined8 *)(param_1 + 0x1f8) = _std_init_vector_sha256_uint8;
        *(undefined8 *)(param_1 + 0x200) = uVar12;
        *(undefined8 *)(param_1 + 0x208) = uVar4;
        *(undefined8 *)(param_1 + 0x210) = uVar5;
      }
      *(undefined4 *)(lVar8 + 0x68) = uVar9;
      *(undefined1 *)(param_1 + 0x111) = 1;
      _qcrypto_queue_req(uVar7,*(undefined8 *)(lVar8 + 0x50),param_1);
    }
  }
  else {
    _sha_final(param_1);
  }
  return;
}



//------------------------------------------------------------
// _sha256_hmac_digest @ 00109184 size=200
// signature: undefined _sha256_hmac_digest(void)
// callers: []
//------------------------------------------------------------

undefined8 _sha256_hmac_digest(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  *(undefined4 *)(param_1 + 0x154) = 0;
  *(undefined8 *)(param_1 + 0xf8) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0;
  *(undefined8 *)(param_1 + 0x108) = 0;
  *(undefined2 *)(param_1 + 0x110) = 1;
  uVar2 = DAT_0010ed77;
  DAT_0010dbc0 = DAT_0010dbc0 + 1;
  *(undefined8 *)(param_1 + 0x1f8) = _std_init_vector_sha256_uint8;
  *(undefined8 *)(param_1 + 0x200) = uVar2;
  uVar2 = DAT_0010ed87;
  *(undefined8 *)(param_1 + 0x208) = DAT_0010ed7f;
  *(undefined8 *)(param_1 + 0x210) = uVar2;
  *(undefined8 *)(*(long *)(param_1 + 0x20) + 100) = 0x2000000003;
  lVar4 = *(long *)(param_1 + 0x20);
  lVar3 = *(long *)(lVar4 + 0x58);
  if ((*(char *)(lVar3 + 0x19) == '\0') || (iVar1 = _copy_source(param_1), iVar1 == 0)) {
    *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0x30);
    *(undefined2 *)(param_1 + 0x110) = 0x101;
    uVar2 = _qcrypto_queue_req(lVar3,*(undefined8 *)(lVar4 + 0x50),param_1);
  }
  else {
    uVar2 = 0xfffffff4;
  }
  return uVar2;
}



//------------------------------------------------------------
// _sha256_hmac_export @ 00109250 size=32
// signature: undefined _sha256_hmac_export(void)
// callers: []
//------------------------------------------------------------

undefined8 _sha256_hmac_export(void)

{
  _sha256_export();
  return 0;
}



//------------------------------------------------------------
// _sha256_hmac_import @ 00109274 size=300
// signature: undefined _sha256_hmac_import(void)
// callers: []
//------------------------------------------------------------

undefined8 _sha256_hmac_import(long param_1,uint *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  long lVar7;
  undefined1 *puVar8;
  long lVar9;
  uint uVar10;
  undefined1 *puVar11;
  long lVar12;
  
  lVar7 = *(long *)(param_2 + 8);
  *(long *)(param_1 + 0x108) = lVar7;
  uVar2 = *(undefined8 *)(param_2 + 0x18);
  uVar1 = *(undefined8 *)(param_2 + 0x12);
  uVar3 = *(undefined8 *)(param_2 + 0x14);
  *(undefined8 *)(param_1 + 0x142) = *(undefined8 *)(param_2 + 0x16);
  *(undefined8 *)(param_1 + 0x14a) = uVar2;
  *(undefined8 *)(param_1 + 0x132) = uVar1;
  *(undefined8 *)(param_1 + 0x13a) = uVar3;
  uVar2 = *(undefined8 *)(param_2 + 0x10);
  uVar1 = *(undefined8 *)(param_2 + 10);
  uVar3 = *(undefined8 *)(param_2 + 0xc);
  *(undefined8 *)(param_1 + 0x122) = *(undefined8 *)(param_2 + 0xe);
  *(undefined8 *)(param_1 + 0x12a) = uVar2;
  *(undefined8 *)(param_1 + 0x112) = uVar1;
  *(undefined8 *)(param_1 + 0x11a) = uVar3;
  puVar8 = (undefined1 *)(param_1 + 0x1f8);
  if (*(ulong *)(param_2 + 8) >= 0x41) {
    lVar7 = lVar7 + 0x40;
  }
  *(bool *)(param_1 + 0x110) = *(ulong *)(param_2 + 8) < 0x41;
  *(uint *)(param_1 + 0xf8) = (uint)lVar7 & 0xffffffc0;
  *(int *)(param_1 + 0xfc) = (int)((ulong)lVar7 >> 0x20);
  uVar4 = *(uint *)(*(long *)(param_1 + 0x20) + 0x68);
  if (uVar4 < 4) {
    puVar6 = param_2;
  }
  else {
    uVar10 = uVar4 >> 2;
    puVar5 = param_2;
    puVar11 = puVar8;
    do {
      uVar10 = uVar10 - 1;
      *puVar11 = *(undefined1 *)((long)puVar5 + 3);
      puVar11[1] = (char)*(undefined2 *)((long)puVar5 + 2);
      puVar11[2] = (char)(*puVar5 >> 8);
      puVar8 = puVar11 + 4;
      puVar6 = puVar5 + 1;
      puVar11[3] = (char)*puVar5;
      puVar5 = puVar6;
      puVar11 = puVar8;
    } while (uVar10 != 0);
  }
  uVar4 = uVar4 & 3;
  lVar9 = 0x18;
  lVar7 = lVar9;
  if (uVar4 != 1) {
    if (uVar4 == 2) {
      lVar7 = 0x10;
      lVar12 = 1;
      puVar11 = puVar8;
    }
    else {
      if (uVar4 != 3) goto LAB_0010938c;
      lVar7 = 8;
      lVar9 = 0x10;
      lVar12 = 2;
      *puVar8 = *(undefined1 *)((long)puVar6 + 3);
      puVar11 = puVar8 + 1;
    }
    puVar8 = puVar8 + lVar12;
    *puVar11 = (char)(*puVar6 >> lVar9);
  }
  *puVar8 = (char)(*puVar6 >> lVar7);
LAB_0010938c:
  *(uint *)(param_1 + 0x154) = param_2[8] & 0x3f;
  return 0;
}



//------------------------------------------------------------
// _sha256_hmac_setkey @ 001093a4 size=152
// signature: undefined _sha256_hmac_setkey(void)
// callers: []
//------------------------------------------------------------

int _sha256_hmac_setkey(long param_1,void *param_2,uint param_3)

{
  int iVar1;
  
  *(undefined8 *)(param_1 + 0xf0) = 0;
  *(undefined8 *)(param_1 + 0x120) = 0;
  *(undefined8 *)(param_1 + 0x128) = 0;
  *(undefined8 *)(param_1 + 0x110) = 0;
  *(undefined8 *)(param_1 + 0x118) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0;
  *(undefined8 *)(param_1 + 0x108) = 0;
  *(undefined8 *)(param_1 + 0xf8) = 0;
  if (param_3 < 0x41) {
    memcpy((undefined8 *)(param_1 + 0xf0),param_2,(ulong)param_3);
    iVar1 = 0;
  }
  else {
    *(undefined8 *)(param_1 + 0xe4) = 0x2000000001;
    iVar1 = _sha_hmac_setkey(param_1,param_2,param_3);
    if (iVar1 != 0) {
      _printk(&DAT_0010dc35);
    }
    param_3 = 0x40;
  }
  *(uint *)(param_1 + 0xec) = param_3;
  return iVar1;
}



//------------------------------------------------------------
// _sha_hmac_inner_hash @ 0010943c size=200
// signature: undefined _sha_hmac_inner_hash(void)
// callers: [_sha1_hmac_final, _sha256_hmac_final]
//------------------------------------------------------------

void _sha_hmac_inner_hash(long param_1)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  
  uVar1 = param_1 + 0x197;
  lVar5 = *(long *)(param_1 + 0x20);
  lVar3 = *(long *)(lVar5 + 0xb0);
  uVar4 = *(undefined8 *)(lVar5 + 0x58);
  memcpy((void *)(uVar1 & 0xffffffffffffffc0),(void *)(param_1 + 0x112),
         (ulong)*(uint *)(param_1 + 0x154));
  *(undefined4 *)(param_1 + 0x224) = *(undefined4 *)(param_1 + 0x154);
  *(uint *)(param_1 + 0x220) = (uint)uVar1 & 0xfc0;
  *(ulong *)(param_1 + 0x218) =
       (((long)(uVar1 * 0x100) >> 8) + 0x8000000000U >> 0xc) * 0x40 + -0x1fffffffe;
  *(undefined4 *)(lVar3 + 0x30) = *(undefined4 *)(param_1 + 0x154);
  *(long *)(lVar3 + 0x38) = param_1 + 0x218;
  *(long *)(lVar3 + 0x40) = param_1 + 0x1f8;
  *(undefined1 *)(param_1 + 0x111) = 1;
  iVar2 = _qcrypto_queue_req(uVar4,*(undefined8 *)(lVar5 + 0x50),lVar3);
  if ((iVar2 == -0x10) || (iVar2 == -0x73)) {
    wait_for_completion_interruptible(lVar5 + 0xb8);
    *(undefined4 *)(lVar5 + 0xb8) = 0;
  }
  return;
}



//------------------------------------------------------------
// _sha_hmac_setkey @ 00109504 size=800
// signature: undefined _sha_hmac_setkey(void)
// callers: [_sha256_hmac_setkey, _sha1_hmac_setkey]
//------------------------------------------------------------

int _sha_hmac_setkey(long param_1,void *param_2,uint param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  code *pcVar6;
  int iVar7;
  long lVar8;
  void *__dest;
  long lVar9;
  long lVar10;
  ulong uVar11;
  ulong local_88 [9];
  
  lVar8 = sp_el0;
  local_88[8] = *(long *)(lVar8 + 0x638);
  uVar1 = *(uint *)(param_1 + 0x40);
  uVar11 = (ulong)uVar1;
  local_88[6] = 0;
  local_88[7] = 0;
  local_88[4] = 0;
  local_88[5] = 0;
  local_88[2] = 0;
  local_88[3] = 0;
  local_88[0] = 0;
  local_88[1] = 0;
  lVar8 = __kmalloc(uVar11 + 0x80,0xcc0);
  if (lVar8 == 0) {
    iVar7 = -0xc;
  }
  else {
    *(long *)(lVar8 + 0x20) = param_1 + 0x80;
    local_88[0] = local_88[0] & 0xffffffff00000000;
    __init_swait_queue_head(local_88 + 1,"&x->wait",&init_completion___key);
    *(undefined4 *)(param_1 + 0x80) = 0;
    *(code **)(lVar8 + 0x10) = _crypto_sha_hmac_ahash_req_complete;
    *(ulong **)(lVar8 + 0x18) = local_88;
    *(undefined4 *)(lVar8 + 0x28) = 0x400;
    __dest = (void *)__kmalloc(param_3 + 0x40,0xdc0);
    if (__dest == (void *)0x0) {
      iVar7 = -0xc;
    }
    else {
      memcpy(__dest,param_2,(ulong)param_3);
      *(uint *)(lVar8 + 0x30) = param_3;
      local_88[4] = ((((long)__dest << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 + -0x1fffffffe;
      local_88[5] = CONCAT44(param_3,(int)__dest) & 0xffffffff00000fc0;
      iVar7 = *(int *)(param_1 + 0xe4);
      lVar9 = *(long *)(lVar8 + 0x20);
      *(ulong **)(lVar8 + 0x38) = local_88 + 4;
      *(long *)(lVar8 + 0x40) = param_1 + 0xf0;
      if (iVar7 == 0) {
        if ((((uVar1 < 0x91) || (*(undefined1 *)(lVar8 + 0x110) = 1, uVar1 == 0x91)) ||
            (*(undefined1 *)(lVar8 + 0x111) = 0, uVar1 < 0xd4)) || ((uVar11 & 0xfffffffc) == 0xd4))
        goto LAB_0010981c;
        *(undefined4 *)(lVar8 + 0x154) = 0;
        uVar3 = DAT_0010c8c8;
        uVar2 = _std_init_vector_sha1_uint8;
        *(undefined8 *)(lVar8 + 0xf8) = 0;
        *(undefined8 *)(lVar8 + 0x100) = 0;
        *(undefined8 *)(lVar8 + 0x108) = 0;
        *(undefined4 *)(lVar9 + 100) = 0;
        *(undefined8 *)(lVar8 + 0x142) = 0;
        *(undefined8 *)(lVar8 + 0x14a) = 0;
        *(undefined8 *)(lVar8 + 0x132) = 0;
        *(undefined8 *)(lVar8 + 0x13a) = 0;
        *(undefined8 *)(lVar8 + 0x122) = 0;
        *(undefined8 *)(lVar8 + 0x12a) = 0;
        *(undefined8 *)(lVar8 + 0x112) = 0;
        *(undefined8 *)(lVar8 + 0x11a) = 0;
        *(undefined4 *)(lVar8 + 0x208) = 0xf0e1d2c3;
        *(undefined8 *)(lVar8 + 0x1f8) = uVar2;
        *(undefined8 *)(lVar8 + 0x200) = uVar3;
        *(undefined4 *)(lVar9 + 0x68) = 0x14;
        lVar9 = *(long *)(lVar8 + 0x20);
        DAT_0010dba8 = DAT_0010dba8 + 1;
      }
      else {
        if (((uVar1 < 0x91) || (*(undefined1 *)(lVar8 + 0x110) = 1, uVar1 == 0x91)) ||
           ((*(undefined1 *)(lVar8 + 0x111) = 0, uVar1 < 0xd4 || ((uVar11 & 0xfffffffc) == 0xd4))))
        goto LAB_0010981c;
        *(undefined4 *)(lVar8 + 0x154) = 0;
        *(undefined8 *)(lVar8 + 0xf8) = 0;
        *(undefined8 *)(lVar8 + 0x100) = 0;
        *(undefined8 *)(lVar8 + 0x108) = 0;
        *(undefined4 *)(lVar9 + 100) = 1;
        *(undefined8 *)(lVar8 + 0x142) = 0;
        *(undefined8 *)(lVar8 + 0x14a) = 0;
        *(undefined8 *)(lVar8 + 0x132) = 0;
        *(undefined8 *)(lVar8 + 0x13a) = 0;
        *(undefined8 *)(lVar8 + 0x122) = 0;
        *(undefined8 *)(lVar8 + 0x12a) = 0;
        uVar3 = DAT_0010ed77;
        uVar2 = _std_init_vector_sha256_uint8;
        *(undefined8 *)(lVar8 + 0x112) = 0;
        *(undefined8 *)(lVar8 + 0x11a) = 0;
        uVar5 = DAT_0010ed87;
        uVar4 = DAT_0010ed7f;
        *(undefined8 *)(lVar8 + 0x1f8) = uVar2;
        *(undefined8 *)(lVar8 + 0x200) = uVar3;
        *(undefined8 *)(lVar8 + 0x208) = uVar4;
        *(undefined8 *)(lVar8 + 0x210) = uVar5;
        *(undefined4 *)(lVar9 + 0x68) = 0x20;
        lVar9 = *(long *)(lVar8 + 0x20);
        DAT_0010dbb0 = DAT_0010dbb0 + 1;
      }
      lVar10 = *(long *)(lVar9 + 0x58);
      if ((*(char *)(lVar10 + 0x19) == '\0') || (iVar7 = _copy_source(lVar8), iVar7 == 0)) {
        if (((uVar1 < 0x30) ||
            ((((uVar11 & 0xfffffff8) == 0x30 ||
              (*(undefined8 *)(lVar8 + 0xb0) = *(undefined8 *)(lVar8 + 0x38), uVar1 < 0x38)) ||
             ((uVar11 & 0xfffffffc) == 0x38)))) ||
           ((*(undefined4 *)(lVar8 + 0xb8) = *(undefined4 *)(lVar8 + 0x30), uVar1 < 0x91 ||
            (*(undefined1 *)(lVar8 + 0x110) = 1, uVar1 == 0x91)))) {
LAB_0010981c:
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(1,0x109820);
          (*pcVar6)();
        }
        *(undefined1 *)(lVar8 + 0x111) = 1;
        iVar7 = _qcrypto_queue_req(lVar10,*(undefined8 *)(lVar9 + 0x50),lVar8);
        if ((iVar7 == -0x10) || (iVar7 == -0x73)) {
          iVar7 = wait_for_completion_interruptible(local_88);
          *(undefined4 *)(param_1 + 0x138) = 0;
        }
      }
      else {
        iVar7 = -0xc;
      }
      kfree_sensitive(__dest);
    }
    kfree_sensitive(lVar8);
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_88[8]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// _crypto_sha_hmac_ahash_req_complete @ 00109828 size=40
// signature: undefined _crypto_sha_hmac_ahash_req_complete(void)
// callers: []
//------------------------------------------------------------

void _crypto_sha_hmac_ahash_req_complete(long param_1,int param_2)

{
  if (param_2 != -0x73) {
    complete(*(undefined8 *)(param_1 + 0x18));
  }
  return;
}



//------------------------------------------------------------
// _qcrypto_aead_ccm_setkey @ 00109854 size=148
// signature: undefined _qcrypto_aead_ccm_setkey(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_aead_ccm_setkey(long param_1,void *param_2,uint param_3)

{
  undefined8 uVar1;
  
  if (((param_3 == 0x10) || (param_3 == 0x20)) ||
     ((param_3 == 0x18 && (*(char *)(*(long *)(param_1 + 0x98) + 0x15) != '\0')))) {
    *(uint *)(param_1 + 0x138) = param_3;
    memcpy((void *)(param_1 + 0xf8),param_2,(ulong)param_3);
    *(uint *)(param_1 + 0x140) = param_3;
    memcpy((void *)(param_1 + 0xa8),param_2,(ulong)param_3);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffea;
    *(undefined4 *)(param_1 + 0x138) = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// _qcrypto_aead_ccm_setauthsize @ 001098ec size=52
// signature: undefined _qcrypto_aead_ccm_setauthsize(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_aead_ccm_setauthsize(long param_1,uint param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0xffffffea;
  if ((param_2 < 0x11) && ((1 << (ulong)(param_2 & 0x1f) & 0x15550U) != 0)) {
    uVar1 = 0;
    *(uint *)(param_1 + 0x13c) = param_2;
  }
  return uVar1;
}



//------------------------------------------------------------
// _qcrypto_aead_encrypt_aes_ccm @ 00109924 size=144
// signature: undefined _qcrypto_aead_encrypt_aes_ccm(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_aead_encrypt_aes_ccm(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20);
  if (*(uint *)(lVar2 + 0xfc) - 4 < 0xd && (*(uint *)(lVar2 + 0xfc) & 1) == 0) {
    uVar1 = *(undefined8 *)(lVar2 + 0x58);
    if ((*(int *)(lVar2 + 0x100) == 0x20) || (*(int *)(lVar2 + 0x100) == 0x10)) {
      *(undefined8 *)(param_1 + 0xcc) = 1;
      *(undefined8 *)(param_1 + 0x100) = 2;
      *(undefined4 *)(param_1 + 0x108) = 4;
      DAT_0010db30 = DAT_0010db30 + 1;
      *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0x38);
      uVar1 = _qcrypto_queue_req(uVar1,*(undefined8 *)(lVar2 + 0x50));
      return uVar1;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// _qcrypto_aead_decrypt_aes_ccm @ 001099b8 size=148
// signature: undefined _qcrypto_aead_decrypt_aes_ccm(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_aead_decrypt_aes_ccm(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20);
  if (*(uint *)(lVar2 + 0xfc) - 4 < 0xd && (*(uint *)(lVar2 + 0xfc) & 1) == 0) {
    uVar1 = *(undefined8 *)(lVar2 + 0x58);
    if ((*(int *)(lVar2 + 0x100) == 0x20) || (*(int *)(lVar2 + 0x100) == 0x10)) {
      *(undefined8 *)(param_1 + 0xcc) = 1;
      *(undefined8 *)(param_1 + 0x100) = 0x100000002;
      DAT_0010db38 = DAT_0010db38 + 1;
      *(undefined4 *)(param_1 + 0x108) = 4;
      *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0x38);
      uVar1 = _qcrypto_queue_req(uVar1,*(undefined8 *)(lVar2 + 0x50));
      return uVar1;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// _qcrypto_cra_aead_ccm_init @ 00109a50 size=128
// signature: undefined _qcrypto_cra_aead_ccm_init(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_cra_aead_ccm_init(long param_1)

{
  undefined8 uVar1;
  
  *(undefined4 *)(param_1 + 4) = 0x1c8;
  if (*(long *)(param_1 + 0x50) == 0x480) {
    _printk(&DAT_0010e48d);
    uVar1 = 0xffffffea;
  }
  else {
    *(undefined4 *)(param_1 + 0xa0) = 0;
    *(undefined8 *)(param_1 + 0x98) = *(undefined8 *)(*(long *)(param_1 + 0x50) + 0x188);
    get_random_bytes(param_1 + 0xe8,0x10);
    uVar1 = 0;
    *(undefined8 *)(param_1 + 0x90) = 0;
    *(long *)(param_1 + 0x80) = param_1 + 0x80;
    *(long *)(param_1 + 0x88) = param_1 + 0x80;
  }
  *(undefined4 *)(param_1 + 0xa4) = 4;
  return uVar1;
}



//------------------------------------------------------------
// _qcrypto_aead_rfc4309_ccm_setkey @ 00109ad4 size=176
// signature: undefined _qcrypto_aead_rfc4309_ccm_setkey(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_aead_rfc4309_ccm_setkey(long param_1,void *param_2,uint param_3)

{
  undefined2 uVar1;
  uint uVar2;
  undefined8 uVar3;
  ulong __n;
  
  uVar2 = param_3 - 3;
  __n = (ulong)uVar2;
  if (param_3 < 3) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar1 = *(undefined2 *)((long)param_2 + __n);
    *(undefined1 *)(param_1 + 0x146) = *(undefined1 *)((undefined2 *)((long)param_2 + __n) + 1);
    *(undefined2 *)(param_1 + 0x144) = uVar1;
    if (((param_3 == 0x13) || (param_3 == 0x23)) ||
       ((param_3 == 0x1b && (*(char *)(*(long *)(param_1 + 0x98) + 0x15) != '\0')))) {
      *(uint *)(param_1 + 0x138) = uVar2;
      memcpy((void *)(param_1 + 0xf8),param_2,__n);
      *(uint *)(param_1 + 0x140) = uVar2;
      memcpy((void *)(param_1 + 0xa8),param_2,__n);
      uVar3 = 0;
    }
    else {
      uVar3 = 0xffffffea;
      *(undefined4 *)(param_1 + 0x138) = 0;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// _qcrypto_aead_rfc4309_ccm_setauthsize @ 00109b88 size=52
// signature: undefined _qcrypto_aead_rfc4309_ccm_setauthsize(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_aead_rfc4309_ccm_setauthsize(long param_1,uint param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0xffffffea;
  if ((param_2 < 0x11) && ((1 << (ulong)(param_2 & 0x1f) & 0x11100U) != 0)) {
    uVar1 = 0;
    *(uint *)(param_1 + 0x13c) = param_2;
  }
  return uVar1;
}



//------------------------------------------------------------
// _qcrypto_aead_rfc4309_enc_aes_ccm @ 00109bc0 size=164
// signature: undefined _qcrypto_aead_rfc4309_enc_aes_ccm(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_aead_rfc4309_enc_aes_ccm(long param_1)

{
  undefined2 uVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  
  if ((*(uint *)(param_1 + 0x30) | 4) == 0x14) {
    lVar3 = *(long *)(param_1 + 0x20);
    uVar2 = *(undefined8 *)(lVar3 + 0x58);
    *(undefined8 *)(param_1 + 0xc0) = 0;
    *(undefined8 *)(param_1 + 0x100) = 2;
    *(undefined4 *)(param_1 + 0xcc) = 1;
    *(undefined4 *)(param_1 + 0x108) = 4;
    puVar5 = (undefined8 *)(param_1 + 0xb8);
    *puVar5 = 0;
    *(undefined1 *)puVar5 = 3;
    uVar1 = *(undefined2 *)(lVar3 + 0x104);
    *(undefined1 *)(param_1 + 0xbb) = *(undefined1 *)(lVar3 + 0x106);
    *(undefined2 *)(param_1 + 0xb9) = uVar1;
    uVar4 = **(undefined8 **)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0xd0) = 1;
    *(undefined8 **)(param_1 + 0xb0) = puVar5;
    *(undefined8 *)(param_1 + 0xbc) = uVar4;
    DAT_0010db40 = DAT_0010db40 + 1;
    uVar2 = _qcrypto_queue_req(uVar2,*(undefined8 *)(lVar3 + 0x50));
  }
  else {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// _qcrypto_aead_rfc4309_dec_aes_ccm @ 00109c68 size=168
// signature: undefined _qcrypto_aead_rfc4309_dec_aes_ccm(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_aead_rfc4309_dec_aes_ccm(long param_1)

{
  undefined2 uVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  
  if ((*(uint *)(param_1 + 0x30) | 4) == 0x14) {
    lVar3 = *(long *)(param_1 + 0x20);
    uVar2 = *(undefined8 *)(lVar3 + 0x58);
    *(undefined8 *)(param_1 + 0x100) = 0x100000002;
    *(undefined4 *)(param_1 + 0xcc) = 1;
    *(undefined4 *)(param_1 + 0x108) = 4;
    *(undefined8 *)(param_1 + 0xc0) = 0;
    puVar5 = (undefined8 *)(param_1 + 0xb8);
    *puVar5 = 0;
    *(undefined1 *)puVar5 = 3;
    uVar1 = *(undefined2 *)(lVar3 + 0x104);
    *(undefined1 *)(param_1 + 0xbb) = *(undefined1 *)(lVar3 + 0x106);
    *(undefined2 *)(param_1 + 0xb9) = uVar1;
    uVar4 = **(undefined8 **)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0xd0) = 1;
    *(undefined8 **)(param_1 + 0xb0) = puVar5;
    *(undefined8 *)(param_1 + 0xbc) = uVar4;
    DAT_0010db48 = DAT_0010db48 + 1;
    uVar2 = _qcrypto_queue_req(uVar2,*(undefined8 *)(lVar3 + 0x50));
  }
  else {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// _qcrypto_cra_aead_rfc4309_ccm_init @ 00109d14 size=128
// signature: undefined _qcrypto_cra_aead_rfc4309_ccm_init(void)
// callers: []
//------------------------------------------------------------

undefined8 _qcrypto_cra_aead_rfc4309_ccm_init(long param_1)

{
  undefined8 uVar1;
  
  *(undefined4 *)(param_1 + 4) = 0x1c8;
  if (*(long *)(param_1 + 0x50) == 0x480) {
    _printk(&DAT_0010e48d);
    uVar1 = 0xffffffea;
  }
  else {
    *(undefined4 *)(param_1 + 0xa0) = 0;
    *(undefined8 *)(param_1 + 0x98) = *(undefined8 *)(*(long *)(param_1 + 0x50) + 0x188);
    get_random_bytes(param_1 + 0xe8,0x10);
    uVar1 = 0;
    *(undefined8 *)(param_1 + 0x90) = 0;
    *(long *)(param_1 + 0x80) = param_1 + 0x80;
    *(long *)(param_1 + 0x88) = param_1 + 0x80;
  }
  *(undefined4 *)(param_1 + 0xa4) = 4;
  return uVar1;
}



//------------------------------------------------------------
// init_module @ 00109f1c size=388
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  long lVar1;
  undefined8 uVar2;
  char local_38 [16];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38[0] = '\0';
  local_38[1] = '\0';
  local_38[2] = '\0';
  local_38[3] = '\0';
  local_38[4] = '\0';
  local_38[5] = '\0';
  local_38[6] = '\0';
  local_38[7] = '\0';
  local_38[8] = '\0';
  local_38[9] = '\0';
  local_38[10] = '\0';
  local_38[0xb] = '\0';
  local_38[0xc] = '\0';
  local_38[0xd] = '\0';
  local_38[0xe] = '\0';
  local_38[0xf] = '\0';
  _debug_dent = debugfs_create_dir("qcrypto",0);
  if (_debug_dent < 0xfffffffffffff001) {
    snprintf(local_38,0xf,"stats-%d",1);
    _debug_qcrypto = 0;
    lVar1 = debugfs_create_file(local_38,0x1a4,_debug_dent,&_debug_qcrypto,_debug_stats_ops);
    if (lVar1 == 0) {
      debugfs_remove(_debug_dent);
    }
  }
  DAT_0010c950 = &DAT_0010c950;
  DAT_0010c958 = &DAT_0010c950;
  DAT_0010c998 = &DAT_0010c998;
  DAT_0010c9a0 = &DAT_0010c998;
  DAT_0010ca08 = 0;
  DAT_0010c94c = 0;
  __mutex_init(&DAT_0010c9b0,"&pcp->engine_lock",&_qcrypto_init___key);
  DAT_0010ca18 = alloc_workqueue("qcrypto_seq_response_wq",0x38,1);
  if (DAT_0010ca18 == 0) {
    _printk(&DAT_0010dcd3);
    uVar2 = 0xfffffff4;
  }
  else {
    DAT_0010ca20 = 0xfffffffe0;
    DAT_0010ca28 = &DAT_0010ca28;
    DAT_0010ca30 = &DAT_0010ca28;
    DAT_0010c9a8 = 0;
    DAT_0010ca38 = seq_response;
    DAT_0010c9e0 = 0;
    DAT_0010ca68 = 0;
    DAT_0010ca54 = 1;
    crypto_init_queue(&DAT_0010c9e8,0x300);
    uVar2 = __platform_driver_register(&__qcrypto,&__this_module);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010a0a4 size=48
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  debugfs_remove(_debug_dent);
  platform_driver_unregister(&__qcrypto);
  return;
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00111000 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [qcrypto_cipher_set_device_hw, _qcrypto_remove_engine, qcrypto_ahash_set_device, qcrypto_bw_allocate_work, _qcrypto_queue_req, qcrypto_bw_reaper_work, _debug_stats_write, qcrypto_aead_set_device, _qcrypto_tfm_complete, qcrypto_cipher_set_device, _start_qcrypto_process, _qcrypto_resume, seq_response, _debug_stats_read, _qcrypto_probe, _qcrypto_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00111008 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [qcrypto_cipher_set_device_hw, _qcrypto_remove_engine, qcrypto_ahash_set_device, qcrypto_bw_allocate_work, _qcrypto_queue_req, qcrypto_bw_reaper_work, _debug_stats_write, qcrypto_aead_set_device, _qcrypto_tfm_complete, qcrypto_cipher_set_device, _start_qcrypto_process, _qcrypto_resume, seq_response, _debug_stats_read, _qcrypto_probe, _qcrypto_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00111010 size=1
// signature: undefined _printk(void)
// callers: [qcrypto_cipher_set_device_hw, _qcrypto_cra_aead_ccm_init, qcrypto_ahash_set_flag, _qcrypto_queue_req, qcrypto_cipher_set_flag, req_done, qcrypto_cipher_set_device, _qcrypto_aes_skcipher_exit, _start_qcrypto_process, _qcrypto_cra_aead_sha1_init, _qce_aead_complete, _qcrypto_skcipher_init, _qcrypto_cra_aead_sha256_init, seq_response, _qcrypto_ahash_cra_exit, _qcrypto_cra_aead_aes_sha256_init, _qce_ahash_complete, _qcrypto_cra_aead_rfc4309_ccm_init, _qcrypto_aes_skcipher_init, _qcrypto_cra_aead_aes_exit, _qcrypto_cra_aead_exit, qcrypto_ahash_set_device, _sha1_hmac_setkey, _qcrypto_setkey_aes, _copy_source, qcrypto_aead_set_device, qcrypto_ce_set_bus, _qce_sk_cipher_complete, _sha256_hmac_setkey, init_module, _qcrypto_setkey_aes_xts, _qcrypto_setkey_des, qcrypto_aead_set_flag, _qcrypto_ahash_hmac_cra_init, _qcrypto_setkey_3des, _qcrypto_skcipher_exit, _qcrypto_cra_aead_aes_sha1_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00111018 size=1
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
// snprintf @ 00111020 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00111028 size=1
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
// debugfs_remove @ 00111030 size=1
// signature: undefined debugfs_remove(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00111038 size=1
// signature: undefined __mutex_init(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00111040 size=1
// signature: undefined alloc_workqueue(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_init_queue @ 00111048 size=1
// signature: undefined crypto_init_queue(void)
// callers: [init_module, _qcrypto_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_init_queue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00111050 size=1
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
// __stack_chk_fail @ 00111058 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [_qcrypto_prefix_alg_cra_name, _start_qcrypto_process, _qcrypto_dec_aes_ecb, init_module, _qce_aead_complete, _qcrypto_dec_aes_cbc, _qcrypto_dec_aes_ctr, _qcrypto_enc_aes_ecb, _qcrypto_enc_aes_cbc, _qcrypto_enc_aes_ctr, _qcrypto_probe, _sha_hmac_setkey]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 00111060 size=1
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
// scnprintf @ 00111070 size=1
// signature: undefined scnprintf(void)
// callers: [_debug_stats_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_get_driver_stats @ 00111078 size=1
// signature: undefined qce_get_driver_stats(void)
// callers: [_debug_stats_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_get_driver_stats(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 00111080 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [_debug_stats_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00111088 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [_start_qcrypto_process, _qcrypto_dec_aes_ecb, _qcrypto_dec_aes_cbc, _qcrypto_dec_aes_ctr, _qcrypto_enc_aes_ecb, _qcrypto_enc_aes_cbc, _qcrypto_enc_aes_ctr, _qcrypto_probe, _debug_stats_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_clear_driver_stats @ 00111090 size=1
// signature: undefined qce_clear_driver_stats(void)
// callers: [_debug_stats_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_clear_driver_stats(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __local_bh_enable_ip @ 00111098 size=1
// signature: undefined __local_bh_enable_ip(void)
// callers: [local_bh_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __local_bh_enable_ip(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_dequeue_request @ 001110a8 size=1
// signature: undefined crypto_dequeue_request(void)
// callers: [_start_qcrypto_process]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_dequeue_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001110b0 size=1
// signature: undefined __list_add_valid(void)
// callers: [_start_qcrypto_process, _qcrypto_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001110b8 size=1
// signature: undefined __kmalloc(void)
// callers: [_aead_aes_fb_stage1_ahash_complete, _start_qcrypto_process, _copy_source, _qcrypto_probe, _sha_update, _qcrypto_aead_aes_192_fallback, _sha_hmac_setkey]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_next @ 001110c0 size=1
// signature: undefined sg_next(void)
// callers: [_qce_sk_cipher_complete, _start_qcrypto_process, _copy_source, _sha_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_process_sha_req @ 001110c8 size=1
// signature: undefined qce_process_sha_req(void)
// callers: [_start_qcrypto_process]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_process_sha_req(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_ablk_cipher_req @ 001110d0 size=1
// signature: undefined qce_ablk_cipher_req(void)
// callers: [_start_qcrypto_process]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_ablk_cipher_req(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001110d8 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [_qcrypto_prefix_alg_cra_name, _aead_aes_fb_stage1_encrypt_complete, _sha_hmac_inner_hash, _sha_final, _sha1_hmac_setkey, _qcrypto_aead_rfc4309_ccm_setkey, _qcrypto_setkey_aes, _qcrypto_aead_setkey, _sha_update, _qcrypto_aead_aes_192_fallback, _qce_sk_cipher_complete, _start_qcrypto_process, _sha256_hmac_setkey, _qce_aead_complete, _qcrypto_setkey_aes_xts, _qcrypto_aead_ccm_setkey, _qcrypto_probe, _qce_ahash_complete, _sha_hmac_setkey]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_copy_to_buffer @ 001110e0 size=1
// signature: undefined sg_copy_to_buffer(void)
// callers: [_start_qcrypto_process, _copy_source, _sha_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_copy_to_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_aead_req @ 001110e8 size=1
// signature: undefined qce_aead_req(void)
// callers: [_start_qcrypto_process]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_aead_req(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001110f0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [_qcrypto_tfm_complete, _qcrypto_remove_engine]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// llist_add_batch @ 001110f8 size=1
// signature: undefined llist_add_batch(void)
// callers: [_qcrypto_tfm_complete]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void llist_add_batch(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00111100 size=1
// signature: undefined queue_work_on(void)
// callers: [_qcrypto_tfm_complete, _qcrypto_resume, qcrypto_bw_reaper_timer_callback, _qcrypto_queue_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_copy_from_buffer @ 00111108 size=1
// signature: undefined sg_copy_from_buffer(void)
// callers: [_qce_sk_cipher_complete]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_copy_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_sensitive @ 00111110 size=1
// signature: undefined kfree_sensitive(void)
// callers: [_aead_aes_fb_stage1_encrypt_complete, _qcrypto_remove_engine, _aead_aes_fb_stage2_ahash_complete, _sha_update, _qcrypto_aead_aes_192_fallback, _qce_sk_cipher_complete, _aead_aes_fb_stage1_ahash_complete, _qce_aead_complete, _qcrypto_ahash_cra_exit, _qcrypto_ahash_hmac_cra_init, _aead_aes_fb_stage2_decrypt_complete, _qcrypto_probe, _qcrypto_remove, _sha_hmac_setkey]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_sensitive(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 00111118 size=1
// signature: undefined __warn_printk(void)
// callers: [_qce_sk_cipher_complete, _aead_aes_fb_stage1_encrypt_complete, _qce_aead_complete, _qcrypto_setkey_aes_xts, _qcrypto_aead_setkey, _qcrypto_aead_aes_192_fallback, _qce_ahash_complete]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00111120 size=1
// signature: undefined kfree(void)
// callers: [_aead_aes_fb_stage1_ahash_complete, _aead_aes_fb_stage1_encrypt_complete, _aead_aes_fb_stage2_ahash_complete, _aead_aes_fb_stage2_decrypt_complete, _qcrypto_probe, _qcrypto_aead_aes_192_fallback, _qce_ahash_complete]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scatterwalk_map_and_copy @ 00111128 size=1
// signature: undefined scatterwalk_map_and_copy(void)
// callers: [_aead_aes_fb_stage1_ahash_complete, _aead_aes_fb_stage1_encrypt_complete, _qce_aead_complete, _aead_aes_fb_stage2_ahash_complete, _sha_update, _qcrypto_aead_aes_192_fallback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scatterwalk_map_and_copy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bcmp @ 00111130 size=1
// signature: int bcmp(void * __s1, void * __s2, size_t __n)
// callers: [_aead_aes_fb_stage1_ahash_complete, _qce_aead_complete, _qcrypto_aead_aes_192_fallback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int bcmp(void *__s1,void *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00111138 size=1
// signature: undefined fortify_panic(void)
// callers: [_qcrypto_prefix_alg_cra_name, _qce_aead_complete, _qcrypto_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00111148 size=1
// signature: undefined kmalloc_trace(void)
// callers: [_qcrypto_ahash_hmac_cra_init, _qcrypto_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_icc_get @ 00111150 size=1
// signature: undefined of_icc_get(void)
// callers: [_qcrypto_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_bw @ 00111158 size=1
// signature: undefined icc_set_bw(void)
// callers: [_qcrypto_probe, qcrypto_ce_set_bus]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_open @ 00111160 size=1
// signature: undefined qce_open(void)
// callers: [_qcrypto_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00111168 size=1
// signature: undefined init_timer_key(void)
// callers: [_qcrypto_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00111170 size=1
// signature: undefined mutex_lock(void)
// callers: [_qcrypto_probe, _qcrypto_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_hw_support @ 00111178 size=1
// signature: undefined qce_hw_support(void)
// callers: [_qcrypto_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_hw_support(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00111180 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [_qcrypto_prefix_alg_cra_name, _qcrypto_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_register_skcipher @ 00111188 size=1
// signature: undefined crypto_register_skcipher(void)
// callers: [_qcrypto_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_register_skcipher(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00111190 size=1
// signature: undefined _dev_info(void)
// callers: [_qcrypto_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00111198 size=1
// signature: undefined _dev_err(void)
// callers: [_qcrypto_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001111a0 size=1
// signature: undefined mutex_unlock(void)
// callers: [_qcrypto_probe, _qcrypto_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_close @ 001111a8 size=1
// signature: undefined qce_close(void)
// callers: [_qcrypto_probe, _qcrypto_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_close(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ksize @ 001111b0 size=1
// signature: undefined ksize(void)
// callers: [_qcrypto_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ksize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_register_ahash @ 001111b8 size=1
// signature: undefined crypto_register_ahash(void)
// callers: [_qcrypto_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_register_ahash(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_register_aead @ 001111c0 size=1
// signature: undefined crypto_register_aead(void)
// callers: [_qcrypto_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_register_aead(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// del_timer_sync @ 001111d0 size=1
// signature: undefined del_timer_sync(void)
// callers: [_qcrypto_remove_engine, _qcrypto_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void del_timer_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mod_timer @ 001111e8 size=1
// signature: undefined mod_timer(void)
// callers: [qcrypto_bw_allocate_work, qcrypto_bw_reaper_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mod_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 001111f0 size=1
// signature: undefined _dev_warn(void)
// callers: [qcrypto_bw_reaper_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlcat @ 001111f8 size=1
// signature: undefined strlcat(void)
// callers: [_qcrypto_prefix_alg_cra_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcat(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 00111200 size=1
// signature: undefined cancel_work_sync(void)
// callers: [_qcrypto_remove_engine]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_put @ 00111208 size=1
// signature: undefined icc_put(void)
// callers: [_qcrypto_remove_engine]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_unregister_aead @ 00111210 size=1
// signature: undefined crypto_unregister_aead(void)
// callers: [_qcrypto_remove_engine]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_unregister_aead(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_unregister_skcipher @ 00111218 size=1
// signature: undefined crypto_unregister_skcipher(void)
// callers: [_qcrypto_remove_engine]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_unregister_skcipher(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_unregister_ahash @ 00111220 size=1
// signature: undefined crypto_unregister_ahash(void)
// callers: [_qcrypto_remove_engine]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_unregister_ahash(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_enable_clk @ 00111228 size=1
// signature: undefined qce_enable_clk(void)
// callers: [qcrypto_ce_set_bus]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_enable_clk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_disable_clk @ 00111230 size=1
// signature: undefined qce_disable_clk(void)
// callers: [qcrypto_ce_set_bus]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_disable_clk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_skcipher_setkey @ 00111238 size=1
// signature: undefined crypto_skcipher_setkey(void)
// callers: [_qcrypto_setkey_aes, _qcrypto_aead_setkey]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_skcipher_setkey(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_skcipher_encrypt @ 00111240 size=1
// signature: undefined crypto_skcipher_encrypt(void)
// callers: [_qcrypto_enc_aes_ecb, _qcrypto_enc_aes_cbc, _qcrypto_enc_aes_ctr, _qcrypto_aead_aes_192_fallback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_skcipher_encrypt(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_skcipher_decrypt @ 00111248 size=1
// signature: undefined crypto_skcipher_decrypt(void)
// callers: [_aead_aes_fb_stage1_ahash_complete, _qcrypto_dec_aes_ecb, _qcrypto_dec_aes_cbc, _qcrypto_dec_aes_ctr, _qcrypto_aead_aes_192_fallback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_skcipher_decrypt(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_alloc_sync_skcipher @ 00111250 size=1
// signature: undefined crypto_alloc_sync_skcipher(void)
// callers: [_qcrypto_aes_skcipher_init, _qcrypto_cra_aead_aes_sha256_init, _qcrypto_cra_aead_aes_sha1_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_alloc_sync_skcipher(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_random_bytes @ 00111258 size=1
// signature: undefined get_random_bytes(void)
// callers: [_qcrypto_cra_aead_rfc4309_ccm_init, _qcrypto_aes_skcipher_init, _qcrypto_cra_aead_ccm_init, _qcrypto_cra_aead_sha1_init, _qcrypto_skcipher_init, _qcrypto_cra_aead_sha256_init, _qcrypto_cra_aead_aes_sha256_init, _qcrypto_cra_aead_aes_sha1_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_random_bytes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_destroy_tfm @ 00111260 size=1
// signature: undefined crypto_destroy_tfm(void)
// callers: [_qcrypto_aes_skcipher_exit, _qcrypto_cra_aead_aes_exit, _qcrypto_cra_aead_aes_sha256_init, _qcrypto_cra_aead_aes_sha1_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_destroy_tfm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_enqueue_request @ 00111268 size=1
// signature: undefined crypto_enqueue_request(void)
// callers: [_qcrypto_queue_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_enqueue_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_ahash_setkey @ 00111270 size=1
// signature: undefined crypto_ahash_setkey(void)
// callers: [_qcrypto_aead_setkey]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_ahash_setkey(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_alloc_ahash @ 00111278 size=1
// signature: undefined crypto_alloc_ahash(void)
// callers: [_qcrypto_cra_aead_aes_sha256_init, _qcrypto_cra_aead_aes_sha1_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_alloc_ahash(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scatterwalk_ffwd @ 00111280 size=1
// signature: undefined scatterwalk_ffwd(void)
// callers: [_qcrypto_aead_aes_192_fallback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scatterwalk_ffwd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmemdup @ 00111288 size=1
// signature: undefined kmemdup(void)
// callers: [_qcrypto_aead_aes_192_fallback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmemdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_ahash_digest @ 00111290 size=1
// signature: undefined crypto_ahash_digest(void)
// callers: [_aead_aes_fb_stage1_encrypt_complete, _qcrypto_aead_aes_192_fallback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_ahash_digest(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00111298 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [_qcrypto_ahash_hmac_cra_init, _sha_hmac_setkey]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_interruptible @ 001112a0 size=1
// signature: undefined wait_for_completion_interruptible(void)
// callers: [_sha_hmac_inner_hash, _sha_hmac_setkey]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_interruptible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 001112a8 size=1
// signature: undefined complete(void)
// callers: [_crypto_sha_hmac_ahash_req_complete]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



