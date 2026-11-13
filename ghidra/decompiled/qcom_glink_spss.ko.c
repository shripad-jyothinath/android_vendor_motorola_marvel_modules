// Decompiled by Ghidra 12.2
// Program: qcom_glink_spss.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_glink_spss_register @ 00100224 size=1104
// signature: undefined qcom_glink_spss_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong qcom_glink_spss_register(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  ulong uVar6;
  ulong uVar7;
  char *pcVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  undefined8 uVar11;
  long local_140;
  undefined4 local_134;
  long local_130;
  long lStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  long local_d0;
  long lStack_c8;
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
  
  lVar4 = sp_el0;
  local_70 = *(long *)(lVar4 + 0x638);
  local_134 = 0;
  local_140 = 0;
  lVar4 = kmalloc_trace(_of_address_to_resource,0xdc0,0x390);
  if (lVar4 == 0) {
    uVar6 = 0xfffffffffffffff4;
    goto LAB_00100600;
  }
  puVar10 = (undefined8 *)param_2[0xe];
  *(undefined8 *)(lVar4 + 0x60) = param_1;
  *(undefined8 **)(lVar4 + 0x2e8) = param_2;
  uVar9 = *param_2;
  *(code **)(lVar4 + 0x328) = qcom_glink_spss_release;
  dev_set_name(lVar4,"%s:%s",*puVar10,uVar9);
  iVar2 = device_register(lVar4);
  if (iVar2 != 0) {
    _printk(&DAT_00100a93,*param_2);
    uVar6 = (ulong)iVar2;
    goto LAB_00100600;
  }
  iVar2 = of_property_read_variable_u32_array
                    (*(undefined8 *)(lVar4 + 0x2e8),"qcom,remote-pid",&local_134,1,0);
  if (iVar2 < 0) {
    pcVar8 = "failed to parse qcom,remote-pid\n";
LAB_00100518:
    _dev_err(lVar4,pcVar8);
  }
  else {
    puVar10 = (undefined8 *)devm_kmalloc(lVar4,0x50,0xdc0);
    puVar5 = (undefined8 *)devm_kmalloc(lVar4,0x50,0xdc0);
    iVar2 = -0xc;
    if ((puVar10 != (undefined8 *)0x0) && (puVar5 != (undefined8 *)0x0)) {
      local_140 = 0x1018;
      iVar2 = qcom_smem_alloc(local_134,0x1de,0x1018);
      if ((iVar2 != -0x11) && (iVar2 != 0)) {
        pcVar8 = "failed to allocate glink descriptors\n";
        goto LAB_00100518;
      }
      uVar6 = qcom_smem_get(local_134,0x1de,&local_140);
      if (uVar6 < 0xfffffffffffff001) {
        if (local_140 == 0x1018) {
          *(undefined4 *)(uVar6 + 8) = 0x800;
          *(undefined4 *)(uVar6 + 0x14) = 0x800;
          puVar5[6] = uVar6;
          puVar5[7] = uVar6 + 4;
          puVar5[8] = uVar6 + 0x18;
          puVar10[7] = uVar6 + 0x10;
          puVar10[8] = uVar6 + 0x818;
          puVar10[5] = glink_spss_reset;
          puVar10[6] = uVar6 + 0xc;
          *puVar10 = 0x800;
          puVar10[1] = glink_spss_rx_avail;
          *puVar5 = 0x800;
          puVar5[1] = glink_spss_tx_avail;
          puVar10[2] = glink_spss_rx_peak;
          puVar10[3] = glink_spss_rx_advance;
          puVar5[4] = glink_spss_tx_write;
          puVar5[5] = glink_spss_reset;
          *(undefined4 *)(puVar10 + 9) = local_134;
          *(undefined4 *)(puVar5 + 9) = local_134;
          *(undefined4 *)(uVar6 + 0xc) = 0;
          *(undefined4 *)puVar5[7] = 0;
          uVar9 = qcom_smem_virt_to_phys(uVar6);
          uVar11 = *(undefined8 *)(lVar4 + 0x2e8);
          local_80 = 0;
          uStack_78 = 0;
          local_90 = 0;
          uStack_88 = 0;
          local_a0 = 0;
          uStack_98 = 0;
          local_b0 = 0;
          uStack_a8 = 0;
          local_c0 = 0;
          uStack_b8 = 0;
          local_d0 = 0;
          lStack_c8 = 0;
          local_e0 = 0;
          uStack_d8 = 0;
          local_f0 = 0;
          uStack_e8 = 0;
          local_100 = 0;
          uStack_f8 = 0;
          local_110 = 0;
          uStack_108 = 0;
          local_120 = 0;
          uStack_118 = 0;
          local_130 = 0;
          lStack_128 = 0;
          iVar2 = of_property_match_string(uVar11,"reg-names","qcom,spss-addr");
          iVar3 = of_property_match_string(uVar11,"reg-names","qcom,spss-size");
          if ((-1 < iVar2) && (-1 < iVar3)) {
            iVar2 = of_address_to_resource(uVar11,iVar2,&local_d0);
            if (iVar2 == 0) {
              uVar1 = 0x68000000000713;
              if (arm64_use_ng_mappings != '\0') {
                uVar1 = 0x68000000000f13;
              }
              uVar6 = ioremap_prot(local_d0,(lStack_c8 - local_d0) + 1,uVar1);
              if ((uVar6 != 0) && (uVar6 < 0xfffffffffffff001)) {
                iVar2 = of_address_to_resource(uVar11,iVar3,&local_130);
                if (iVar2 == 0) {
                  uVar11 = 0x68000000000713;
                  if (arm64_use_ng_mappings != '\0') {
                    uVar11 = 0x68000000000f13;
                  }
                  uVar7 = ioremap_prot(local_130,(lStack_128 - local_130) + 1,uVar11);
                  if ((uVar7 == 0) || (0xfffffffffffff000 < uVar7)) {
                    iounmap(uVar6);
                    pcVar8 = "failed to map spss size resource\n";
                    goto LAB_00100664;
                  }
                  writeq_relaxed(uVar9,uVar6);
                  writel_relaxed(0x1018,uVar7);
                  iounmap(uVar6);
                  iounmap(uVar7);
                  uVar6 = qcom_glink_native_probe(lVar4,1,puVar10,puVar5,0);
                  if (uVar6 < 0xfffffffffffff001) {
                    iVar2 = qcom_glink_native_start(uVar6);
                    if (iVar2 == 0) goto LAB_00100600;
                  }
                  else {
                    iVar2 = (int)uVar6;
                  }
                }
                else {
                  iounmap(uVar6);
                  iVar2 = -0xc;
                }
                goto LAB_001005f4;
              }
              pcVar8 = "failed to map spss addr resource\n";
LAB_00100664:
              _dev_err(lVar4,pcVar8);
            }
            iVar2 = -0xc;
            goto LAB_001005f4;
          }
          pcVar8 = "failed to find location registers\n";
        }
        else {
          pcVar8 = "glink descriptor of invalid size\n";
        }
        _dev_err(lVar4,pcVar8);
        iVar2 = -0x16;
      }
      else {
        _dev_err(lVar4,"failed to acquire xprt descriptor\n");
        iVar2 = (int)uVar6;
      }
    }
  }
LAB_001005f4:
  put_device(lVar4);
  uVar6 = (ulong)iVar2;
LAB_00100600:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// qcom_glink_spss_release @ 00100678 size=28
// signature: undefined qcom_glink_spss_release(void)
// callers: []
//------------------------------------------------------------

void qcom_glink_spss_release(void)

{
  kfree();
  return;
}



//------------------------------------------------------------
// glink_spss_rx_avail @ 00100698 size=44
// signature: undefined glink_spss_rx_avail(void)
// callers: []
//------------------------------------------------------------

ulong glink_spss_rx_avail(long *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)param_1[6];
  uVar2 = *(uint *)param_1[7];
  if (uVar2 < uVar1) {
    return ((ulong)uVar2 - (ulong)uVar1) + *param_1;
  }
  return (ulong)(uVar2 - uVar1);
}



//------------------------------------------------------------
// glink_spss_rx_peak @ 001006c8 size=148
// signature: undefined glink_spss_rx_peak(void)
// callers: []
//------------------------------------------------------------

void glink_spss_rx_peak(ulong *param_1,long param_2,int param_3,ulong param_4)

{
  ulong uVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  
  uVar4 = *param_1;
  iVar3 = 0;
  if (uVar4 <= (uint)(*(int *)param_1[6] + param_3)) {
    iVar3 = (int)uVar4;
  }
  uVar2 = (ulong)(uint)((*(int *)param_1[6] + param_3) - iVar3);
  uVar4 = uVar4 - uVar2;
  uVar1 = uVar4;
  if (param_4 <= uVar4) {
    uVar1 = param_4;
  }
  if (uVar1 != 0) {
    __memcpy_fromio(param_2,param_1[8] + uVar2,uVar1);
  }
  if (uVar4 < param_4) {
    __memcpy_fromio(param_2 + uVar1,param_1[8],param_4 - uVar1);
  }
  return;
}



//------------------------------------------------------------
// glink_spss_rx_advance @ 00100760 size=36
// signature: undefined glink_spss_rx_advance(void)
// callers: []
//------------------------------------------------------------

void glink_spss_rx_advance(ulong *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(int *)param_1[6] + param_2;
  iVar2 = 0;
  if (*param_1 <= (ulong)uVar1) {
    iVar2 = (int)*param_1;
  }
  *(int *)param_1[6] = uVar1 - iVar2;
  return;
}



//------------------------------------------------------------
// glink_spss_reset @ 00100788 size=20
// signature: undefined glink_spss_reset(void)
// callers: []
//------------------------------------------------------------

void glink_spss_reset(long param_1)

{
  **(undefined4 **)(param_1 + 0x38) = 0;
  **(undefined4 **)(param_1 + 0x30) = 0;
  return;
}



//------------------------------------------------------------
// glink_spss_tx_avail @ 001007a0 size=40
// signature: undefined glink_spss_tx_avail(void)
// callers: []
//------------------------------------------------------------

int glink_spss_tx_avail(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = **(uint **)(param_1 + 0xc) - **(uint **)(param_1 + 0xe);
  if (**(uint **)(param_1 + 0xc) < **(uint **)(param_1 + 0xe) || uVar2 == 0) {
    uVar2 = uVar2 + *param_1;
  }
  iVar1 = 0;
  if (0xf < uVar2) {
    iVar1 = uVar2 - 0x10;
  }
  return iVar1;
}



//------------------------------------------------------------
// glink_spss_tx_write @ 001007cc size=280
// signature: undefined glink_spss_tx_write(void)
// callers: []
//------------------------------------------------------------

void glink_spss_tx_write(ulong *param_1,void *param_2,ulong param_3,void *param_4,ulong param_5)

{
  size_t sVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  
  uVar2 = *(uint *)param_1[7];
  uVar4 = *param_1 - (ulong)uVar2;
  sVar1 = uVar4;
  if (param_3 <= uVar4) {
    sVar1 = param_3;
  }
  if (sVar1 != 0) {
    memcpy((void *)(param_1[8] + (ulong)uVar2),param_2,sVar1);
  }
  if (uVar4 < param_3) {
    memcpy((void *)param_1[8],(void *)((long)param_2 + sVar1),param_3 - sVar1);
  }
  uVar4 = *param_1;
  uVar2 = uVar2 + (int)param_3;
  iVar3 = 0;
  if (uVar4 <= uVar2) {
    iVar3 = (int)uVar4;
  }
  uVar2 = uVar2 - iVar3;
  uVar4 = uVar4 - uVar2;
  sVar1 = uVar4;
  if (param_5 <= uVar4) {
    sVar1 = param_5;
  }
  if (sVar1 != 0) {
    memcpy((void *)(param_1[8] + (ulong)uVar2),param_4,sVar1);
  }
  if (uVar4 < param_5) {
    memcpy((void *)param_1[8],(void *)((long)param_4 + sVar1),param_5 - sVar1);
  }
  uVar4 = *param_1;
  uVar2 = uVar2 + (int)param_5;
  DataSynchronizationBarrier(3,2,0);
  iVar3 = 0;
  if (uVar4 <= uVar2) {
    iVar3 = (int)uVar4;
  }
  uVar2 = (uVar2 - iVar3) + 7 & 0xfffffff8;
  iVar3 = 0;
  if (uVar4 <= uVar2) {
    iVar3 = (int)uVar4;
  }
  *(uint *)param_1[7] = uVar2 - iVar3;
  return;
}



//------------------------------------------------------------
// qcom_glink_spss_unregister @ 001008e8 size=52
// signature: undefined qcom_glink_spss_unregister(void)
// callers: []
//------------------------------------------------------------

void qcom_glink_spss_unregister(long param_1)

{
  if (param_1 != 0) {
    qcom_glink_native_remove();
    qcom_glink_native_unregister(param_1);
  }
  return;
}



//------------------------------------------------------------
// writeq_relaxed @ 0010091c size=124
// signature: undefined writeq_relaxed(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

void writeq_relaxed(undefined8 param_1,undefined8 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x40,param_2,writeq_relaxed,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x40,param_2,0x100968,uVar1);
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 00100998 size=132
// signature: undefined writel_relaxed(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x1009b0,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1009ec,uVar1);
  return;
}



//------------------------------------------------------------
// kmalloc_trace @ 00102008 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 00102010 size=1
// signature: undefined dev_set_name(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_register @ 00102018 size=1
// signature: undefined device_register(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102020 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102028 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_alloc @ 00102030 size=1
// signature: undefined qcom_smem_alloc(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_get @ 00102038 size=1
// signature: undefined qcom_smem_get(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_virt_to_phys @ 00102040 size=1
// signature: undefined qcom_smem_virt_to_phys(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_virt_to_phys(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_match_string @ 00102048 size=1
// signature: undefined of_property_match_string(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_match_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 00102050 size=1
// signature: undefined of_address_to_resource(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ioremap_prot @ 00102060 size=1
// signature: undefined ioremap_prot(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ioremap_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 00102068 size=1
// signature: undefined iounmap(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102070 size=1
// signature: undefined _printk(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102078 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_native_probe @ 00102080 size=1
// signature: undefined qcom_glink_native_probe(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_native_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_native_start @ 00102088 size=1
// signature: undefined qcom_glink_native_start(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_native_start(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 00102090 size=1
// signature: undefined put_device(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102098 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_glink_spss_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001020a0 size=1
// signature: undefined kfree(void)
// callers: [qcom_glink_spss_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_fromio @ 001020a8 size=1
// signature: undefined __memcpy_fromio(void)
// callers: [glink_spss_rx_peak]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_fromio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001020b0 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [glink_spss_tx_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_native_remove @ 001020b8 size=1
// signature: undefined qcom_glink_native_remove(void)
// callers: [qcom_glink_spss_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_native_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_native_unregister @ 001020c0 size=1
// signature: undefined qcom_glink_native_unregister(void)
// callers: [qcom_glink_spss_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_native_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 001020c8 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed, writeq_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 001020d0 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed, writeq_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



