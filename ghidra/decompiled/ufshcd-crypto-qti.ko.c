// Decompiled by Ghidra 12.2
// Program: ufshcd-crypto-qti.ko
// Image base: 00100000

//------------------------------------------------------------
// ufshcd_qti_hba_init_crypto_capabilities @ 0010019c size=344
// signature: undefined ufshcd_qti_hba_init_crypto_capabilities(void)
// callers: []
//------------------------------------------------------------

undefined8 ufshcd_qti_hba_init_crypto_capabilities(long *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  long lVar7;
  ulong uVar8;
  
  uVar4 = readl(*param_1);
  if (((uVar4 >> 0x1c & 1) == 0) || ((*(byte *)((long)param_1 + 0xbf1) & 1) == 0)) {
    uVar6 = 0;
  }
  else {
    uVar6 = readl(*param_1 + 0x100);
    *(uint *)(param_1 + 0x243) = (uint)uVar6;
    *(uint *)(param_1 + 0x245) = (uint)((ulong)uVar6 >> 0x10) & 0xff00;
    lVar7 = devm_kmalloc(param_1[8],((uint)uVar6 & 0xff) << 2,0xdc0);
    param_1[0x244] = lVar7;
    if (lVar7 == 0) {
      uVar6 = 0xfffffff4;
    }
    else {
      uVar6 = devm_blk_crypto_profile_init
                        (param_1[8],param_1 + 0x246,*(byte *)((long)param_1 + 0x1219) + 1);
      puVar2 = PTR_ufshcd_crypto_qti_keyslot_evict_00100818;
      puVar1 = ufshcd_qti_crypto_ops;
      if ((int)uVar6 == 0) {
        param_1[0x24d] = param_1[8];
        puVar3 = PTR_ufshcd_crypto_qti_derive_raw_secret_00100820;
        param_1[0x249] = 0x200000008;
        param_1[0x246] = (long)puVar1;
        param_1[0x247] = (long)puVar2;
        param_1[0x248] = (long)puVar3;
        if (*(byte *)(param_1 + 0x243) != 0) {
          uVar8 = 0;
          lVar7 = 0x104;
          do {
            uVar5 = readl(*param_1 + lVar7);
            *(undefined4 *)(param_1[0x244] + uVar8 * 4) = uVar5;
            uVar4 = *(uint *)(param_1[0x244] + uVar8 * 4);
            if ((uVar4 & 0xff00ff) == 0x30000) {
              *(uint *)((long)param_1 + 0x1254) =
                   (uVar4 & 0xff00) << 1 | *(uint *)((long)param_1 + 0x1254);
            }
            uVar8 = uVar8 + 1;
            lVar7 = lVar7 + 4;
          } while (uVar8 < *(byte *)(param_1 + 0x243));
        }
        return 0;
      }
    }
  }
  *(uint *)(param_1 + 0x17e) = *(uint *)(param_1 + 0x17e) & 0xfffffeff;
  return uVar6;
}



//------------------------------------------------------------
// readl @ 001002f4 size=140
// signature: undefined readl(void)
// callers: [ufshcd_qti_hba_init_crypto_capabilities]
//------------------------------------------------------------

undefined4 readl(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl,uVar1);
  uVar2 = *param_1;
  DataMemoryBarrier(0,1);
  log_post_read_mmio(uVar2,0x20,param_1,0x10034c,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// ufshcd_crypto_qti_keyslot_program @ 00100384 size=492
// signature: undefined ufshcd_crypto_qti_keyslot_program(void)
// callers: []
//------------------------------------------------------------

int ufshcd_crypto_qti_keyslot_program(long param_1,uint *param_2,undefined4 param_3)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  byte *pbVar7;
  ulong uVar8;
  long lVar9;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  lVar1 = param_1 + -0x1230;
  if (lVar1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x100570);
    (*pcVar4)();
  }
  if (param_2 == (uint *)0x0) {
    _printk(&DAT_0010095b);
    iVar5 = -0x16;
LAB_001004bc:
    lVar1 = sp_el0;
    if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return iVar5;
  }
  uVar2 = *param_2;
  if (5 < uVar2) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10056c);
    (*pcVar4)();
  }
  if ((ulong)*(byte *)(param_1 + -0x18) != 0) {
    if (4 < uVar2) {
LAB_00100560:
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(1,0x100564);
      (*pcVar4)();
    }
    lVar6 = (ulong)uVar2 * 8;
    uVar3 = param_2[1];
    lVar9 = *(long *)(param_1 + -0x1180);
    uVar8 = 0;
    pbVar7 = (byte *)(*(long *)(param_1 + -0x10) + 1);
    do {
      if (*(uint *)(ufs_crypto_algs + lVar6) == (uint)pbVar7[-1]) {
        if (0x28 < ((ulong)uVar2 << 3 | 4)) goto LAB_00100560;
        if ((*(uint *)(ufs_crypto_algs + lVar6 + 4) == (uint)pbVar7[1]) &&
           ((uVar3 >> 9 & (uint)*pbVar7) != 0)) {
          if (-1 < (int)uVar8) {
            if (*(char *)(lVar9 + 0xb8) == '\0') {
              iVar5 = ufshcd_hold(lVar1,0);
              if (iVar5 == 0) {
                local_68 = *(undefined8 *)(lVar9 + 0xa8);
                uStack_60 = *(undefined8 *)(lVar9 + 0xb0);
                iVar5 = crypto_qti_keyslot_program
                                  (&local_68,param_2,param_3,uVar3 >> 9,uVar8 & 0xffffffff,10);
                if (iVar5 != 0) {
                  _printk(&DAT_00100975,"ufshcd_crypto_qti_keyslot_program",iVar5);
                }
                ufshcd_release(lVar1);
              }
              else {
                _printk(&DAT_00100912,"ufshcd_crypto_qti_keyslot_program",iVar5);
              }
            }
            else {
              _printk(&DAT_001009d5,*(undefined4 *)(param_1 + -0x1048));
              iVar5 = -0x16;
            }
            goto LAB_001004bc;
          }
          break;
        }
      }
      uVar8 = uVar8 + 1;
      pbVar7 = pbVar7 + 4;
    } while (*(byte *)(param_1 + -0x18) != uVar8);
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(0x800,0x1004bc);
  (*pcVar4)();
}



//------------------------------------------------------------
// ufshcd_crypto_qti_keyslot_evict @ 00100574 size=268
// signature: undefined ufshcd_crypto_qti_keyslot_evict(void)
// callers: []
//------------------------------------------------------------

int ufshcd_crypto_qti_keyslot_evict(long param_1,undefined8 param_2,undefined4 param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  lVar1 = param_1 + -0x1230;
  if (lVar1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x100680);
    (*pcVar2)();
  }
  lVar4 = *(long *)(param_1 + -0x1180);
  if (*(char *)(lVar4 + 0xb8) == '\0') {
    iVar3 = ufshcd_hold(lVar1,0);
    if (iVar3 == 0) {
      local_48 = *(undefined8 *)(lVar4 + 0xa8);
      uStack_40 = *(undefined8 *)(lVar4 + 0xb0);
      iVar3 = crypto_qti_keyslot_evict(&local_48,param_3,10);
      if (iVar3 != 0) {
        _printk(&DAT_00100975,"ufshcd_crypto_qti_keyslot_evict",iVar3);
      }
      ufshcd_release(lVar1);
    }
    else {
      _printk(&DAT_00100912,"ufshcd_crypto_qti_keyslot_evict",iVar3);
    }
  }
  else {
    _printk(&DAT_001009d5,*(undefined4 *)(param_1 + -0x1048));
    iVar3 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// ufshcd_crypto_qti_derive_raw_secret @ 00100684 size=292
// signature: undefined ufshcd_crypto_qti_derive_raw_secret(void)
// callers: []
//------------------------------------------------------------

int ufshcd_crypto_qti_derive_raw_secret
              (long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  lVar1 = param_1 + -0x1230;
  if (lVar1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1007a8);
    (*pcVar2)();
  }
  lVar4 = *(long *)(param_1 + -0x1180);
  if (*(char *)(lVar4 + 0xb8) == '\0') {
    iVar3 = ufshcd_hold(lVar1,0);
    if (iVar3 == 0) {
      local_58 = *(undefined8 *)(lVar4 + 0xa8);
      uStack_50 = *(undefined8 *)(lVar4 + 0xb0);
      iVar3 = crypto_qti_derive_raw_secret(&local_58,param_2,param_3,param_4,0x20);
      if (iVar3 != 0) {
        _printk(&DAT_00100975,"ufshcd_crypto_qti_derive_raw_secret",iVar3);
      }
      ufshcd_release(lVar1);
    }
    else {
      _printk(&DAT_00100912,"ufshcd_crypto_qti_derive_raw_secret",iVar3);
    }
  }
  else {
    _printk(&DAT_001009d5,*(undefined4 *)(param_1 + -0x1048));
    iVar3 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// devm_kmalloc @ 00102000 size=1
// signature: undefined devm_kmalloc(void)
// callers: [ufshcd_qti_hba_init_crypto_capabilities]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_blk_crypto_profile_init @ 00102008 size=1
// signature: undefined devm_blk_crypto_profile_init(void)
// callers: [ufshcd_qti_hba_init_crypto_capabilities]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_blk_crypto_profile_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00102010 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 00102018 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_hold @ 00102020 size=1
// signature: undefined ufshcd_hold(void)
// callers: [ufshcd_crypto_qti_keyslot_program, ufshcd_crypto_qti_keyslot_evict, ufshcd_crypto_qti_derive_raw_secret]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_hold(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_qti_keyslot_program @ 00102028 size=1
// signature: undefined crypto_qti_keyslot_program(void)
// callers: [ufshcd_crypto_qti_keyslot_program]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_qti_keyslot_program(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_release @ 00102030 size=1
// signature: undefined ufshcd_release(void)
// callers: [ufshcd_crypto_qti_keyslot_program, ufshcd_crypto_qti_keyslot_evict, ufshcd_crypto_qti_derive_raw_secret]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102038 size=1
// signature: undefined _printk(void)
// callers: [ufshcd_crypto_qti_keyslot_program, ufshcd_crypto_qti_keyslot_evict, ufshcd_crypto_qti_derive_raw_secret]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102040 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [ufshcd_crypto_qti_keyslot_program, ufshcd_crypto_qti_keyslot_evict, ufshcd_crypto_qti_derive_raw_secret]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_qti_keyslot_evict @ 00102048 size=1
// signature: undefined crypto_qti_keyslot_evict(void)
// callers: [ufshcd_crypto_qti_keyslot_evict]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_qti_keyslot_evict(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_qti_derive_raw_secret @ 00102050 size=1
// signature: undefined crypto_qti_derive_raw_secret(void)
// callers: [ufshcd_crypto_qti_derive_raw_secret]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_qti_derive_raw_secret(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



