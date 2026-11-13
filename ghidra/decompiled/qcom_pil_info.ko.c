// Decompiled by Ghidra 12.2
// Program: qcom_pil_info.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_pil_timeouts_disabled @ 00100174 size=316
// signature: undefined qcom_pil_timeouts_disabled(void)
// callers: []
//------------------------------------------------------------

void qcom_pil_timeouts_disabled(void)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  int *piVar4;
  undefined *puVar5;
  long local_98;
  long lStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  lStack_90 = 0;
  lVar3 = of_find_compatible_node(0,0,"qcom,msm-imem-pil-disable-timeout");
  if (lVar3 == 0) {
    puVar5 = &DAT_001006e7;
  }
  else {
    iVar2 = of_address_to_resource(lVar3,0,&local_98);
    if (-1 < iVar2) {
      uVar1 = 0x68000000000713;
      if (arm64_use_ng_mappings != '\0') {
        uVar1 = 0x68000000000f13;
      }
      piVar4 = (int *)ioremap_prot(local_98,(lStack_90 - local_98) + 1,uVar1);
      if (piVar4 == (int *)0x0) {
        _printk(&DAT_00100668);
      }
      else {
        iVar2 = *piVar4;
        if (iVar2 == 0x53444247) {
          _printk(&DAT_001006fc);
        }
        timeouts_disabled = iVar2 == 0x53444247;
        iounmap(piVar4);
      }
      goto LAB_00100238;
    }
    puVar5 = &DAT_001006b7;
  }
  _printk(puVar5,"qcom,msm-imem-pil-disable-timeout");
LAB_00100238:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(timeouts_disabled);
  }
  return;
}



//------------------------------------------------------------
// qcom_pil_info_store @ 001002b4 size=584
// signature: undefined qcom_pil_info_store(void)
// callers: []
//------------------------------------------------------------

int qcom_pil_info_store(char *param_1,ulong param_2,undefined4 param_3)

{
  undefined8 uVar1;
  int iVar2;
  undefined *puVar3;
  size_t sVar4;
  long lVar5;
  ulong uVar6;
  long local_c0;
  long local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  local_60 = 0;
  mutex_lock(&pil_reloc_lock);
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = 0;
  local_b8 = 0;
  if ((hibernation & 1) == 0) {
    register_syscore_ops(pil_reloc_restore_syscore_ops);
    hibernation = 1;
  }
  if (_reloc_0 == 0) {
    lVar5 = of_find_compatible_node(0,0,"qcom,pil-reloc-info");
    if (lVar5 == 0) {
      iVar2 = -2;
      goto LAB_00100498;
    }
    iVar2 = of_address_to_resource(lVar5,0,&local_c0);
    if (iVar2 < 0) goto LAB_00100498;
    uVar1 = 0x68000000000713;
    if (arm64_use_ng_mappings != '\0') {
      uVar1 = 0x68000000000f13;
    }
    lVar5 = ioremap_prot(local_c0,(local_b8 - local_c0) + 1,uVar1);
    if (lVar5 != 0) {
      __memset_io(lVar5,0,(local_b8 - local_c0) + 1);
      _reloc_1 = (ulong)(((int)local_b8 - (int)local_c0) + 1) / 0x14;
      _reloc_0 = lVar5;
      goto joined_r0x00100438;
    }
    puVar3 = &DAT_00100724;
  }
  else {
joined_r0x00100438:
    if (_reloc_1 != 0) {
      uVar6 = 0;
      do {
        lVar5 = _reloc_0 + uVar6 * 0x14;
        __memcpy_fromio(&local_60,lVar5,8);
        if ((char)local_60 == '\0') {
          sVar4 = strlen(param_1);
          if (0x12 < sVar4) {
            sVar4 = 0x13;
          }
          __memcpy_toio(lVar5,param_1,sVar4);
LAB_00100470:
          writel(param_2 & 0xffffffff,lVar5 + 8);
          writel(param_2 >> 0x20,lVar5 + 0xc);
          writel(param_3,lVar5 + 0x10);
          iVar2 = 0;
          goto LAB_00100498;
        }
        iVar2 = strncmp((char *)&local_60,param_1,8);
        if (iVar2 == 0) goto LAB_00100470;
        uVar6 = (ulong)((int)uVar6 + 1);
      } while (uVar6 < _reloc_1);
    }
    puVar3 = &DAT_0010079b;
  }
  _printk(puVar3);
  iVar2 = -0xc;
LAB_00100498:
  mutex_unlock(&pil_reloc_lock);
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// writel @ 001004fc size=136
// signature: undefined writel(void)
// callers: [qcom_pil_info_store]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x100514,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x100554,uVar1);
  return;
}



//------------------------------------------------------------
// pil_reloc_restore_syscore_resume @ 00100588 size=96
// signature: undefined pil_reloc_restore_syscore_resume(void)
// callers: []
//------------------------------------------------------------

void pil_reloc_restore_syscore_resume(void)

{
  if (_reloc_0 == 0) {
    _printk(&DAT_00100764);
  }
  else {
    mutex_lock(&pil_reloc_lock);
    iounmap(_reloc_0);
    _reloc_0 = 0;
    mutex_unlock(&pil_reloc_lock);
  }
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100620 size=72
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  mutex_lock(&pil_reloc_lock);
  iounmap(_reloc_0);
  _reloc_0 = 0;
  mutex_unlock(&pil_reloc_lock);
  return;
}



//------------------------------------------------------------
// of_find_compatible_node @ 00102000 size=1
// signature: undefined of_find_compatible_node(void)
// callers: [qcom_pil_info_store, qcom_pil_timeouts_disabled]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_compatible_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 00102008 size=1
// signature: undefined of_address_to_resource(void)
// callers: [qcom_pil_info_store, qcom_pil_timeouts_disabled]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ioremap_prot @ 00102018 size=1
// signature: undefined ioremap_prot(void)
// callers: [qcom_pil_info_store, qcom_pil_timeouts_disabled]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ioremap_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 00102020 size=1
// signature: undefined iounmap(void)
// callers: [cleanup_module, qcom_pil_timeouts_disabled, pil_reloc_restore_syscore_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102028 size=1
// signature: undefined _printk(void)
// callers: [qcom_pil_info_store, qcom_pil_timeouts_disabled, pil_reloc_restore_syscore_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102030 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_pil_info_store, qcom_pil_timeouts_disabled]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00102038 size=1
// signature: undefined mutex_lock(void)
// callers: [qcom_pil_info_store, cleanup_module, pil_reloc_restore_syscore_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_syscore_ops @ 00102040 size=1
// signature: undefined register_syscore_ops(void)
// callers: [qcom_pil_info_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_syscore_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_fromio @ 00102048 size=1
// signature: undefined __memcpy_fromio(void)
// callers: [qcom_pil_info_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_fromio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncmp @ 00102050 size=1
// signature: int strncmp(char * __s1, char * __s2, size_t __n)
// callers: [qcom_pil_info_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memset_io @ 00102058 size=1
// signature: undefined __memset_io(void)
// callers: [qcom_pil_info_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memset_io(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00102060 size=1
// signature: size_t strlen(char * __s)
// callers: [qcom_pil_info_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_toio @ 00102068 size=1
// signature: undefined __memcpy_toio(void)
// callers: [qcom_pil_info_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_toio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00102070 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcom_pil_info_store, cleanup_module, pil_reloc_restore_syscore_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00102078 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 00102080 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



