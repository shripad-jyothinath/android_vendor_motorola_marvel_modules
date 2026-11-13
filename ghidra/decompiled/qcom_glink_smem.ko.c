// Decompiled by Ghidra 12.2
// Program: qcom_glink_smem.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_glink_smem_register @ 00100234 size=724
// signature: undefined qcom_glink_smem_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_glink_smem_register(long param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  char *pcVar6;
  long lVar7;
  long *plVar8;
  ulong uVar9;
  long local_58;
  undefined4 local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_4c = 0;
  local_58 = 0;
  lVar4 = kmalloc_trace(_put_device,0xdc0,0x390);
  if (lVar4 == 0) {
    uVar9 = 0xfffffffffffffff4;
    goto LAB_001004bc;
  }
  plVar8 = *(long **)(param_1 + 0x60);
  *(long *)(lVar4 + 0x60) = param_1;
  *(undefined8 *)(lVar4 + 0x2e8) = param_2;
  *(code **)(lVar4 + 0x328) = qcom_glink_smem_release;
  lVar7 = plVar8[0xe];
  if (lVar7 == 0) {
    lVar7 = *plVar8;
  }
  dev_set_name(lVar4,"%s:%pOFn",lVar7,param_2);
  iVar2 = device_register(lVar4);
  if (iVar2 != 0) {
    _printk(&DAT_0010096e);
    put_device(lVar4);
    uVar9 = (ulong)iVar2;
    goto LAB_001004bc;
  }
  uVar3 = of_property_read_variable_u32_array
                    (*(undefined8 *)(lVar4 + 0x2e8),"qcom,remote-pid",&local_4c,1,0);
  if ((int)uVar3 < 0) {
    uVar9 = (ulong)uVar3;
    pcVar6 = "failed to parse qcom,remote-pid\n";
LAB_00100464:
    _dev_err(lVar4,pcVar6);
  }
  else {
    lVar7 = devm_kmalloc(lVar4,0x50,0xdc0);
    lVar5 = devm_kmalloc(lVar4,0x50,0xdc0);
    uVar9 = 0xfffffff4;
    if ((lVar7 != 0) && (lVar5 != 0)) {
      uVar3 = qcom_smem_alloc(local_4c,0x1de,0x20);
      if ((uVar3 != 0xffffffef) && (uVar9 = (ulong)uVar3, uVar3 != 0)) {
        pcVar6 = "failed to allocate glink descriptors\n";
        goto LAB_00100464;
      }
      uVar9 = qcom_smem_get(local_4c,0x1de,&local_58);
      if (uVar9 < 0xfffffffffffff001) {
        if (local_58 == 0x20) {
          puVar1 = (undefined4 *)(uVar9 + 8);
          *(ulong *)(lVar5 + 0x30) = uVar9;
          *(ulong *)(lVar5 + 0x38) = uVar9 + 4;
          *(undefined4 **)(lVar7 + 0x30) = puVar1;
          *(ulong *)(lVar7 + 0x38) = uVar9 + 0xc;
          uVar3 = qcom_smem_alloc(local_4c,0x1df,0x4000);
          if ((uVar3 != 0xffffffef) && (uVar9 = (ulong)uVar3, uVar3 != 0)) {
            pcVar6 = "failed to allocate TX fifo\n";
            goto LAB_00100464;
          }
          uVar9 = qcom_smem_get(local_4c,0x1df,lVar5);
          *(ulong *)(lVar5 + 0x40) = uVar9;
          if (uVar9 < 0xfffffffffffff001) {
            *(code **)(lVar7 + 8) = glink_smem_rx_avail;
            *(code **)(lVar7 + 0x10) = glink_smem_rx_peak;
            *(code **)(lVar7 + 0x18) = glink_smem_rx_advance;
            *(undefined4 *)(lVar7 + 0x48) = local_4c;
            *(undefined4 *)(lVar5 + 0x48) = local_4c;
            *(code **)(lVar5 + 8) = glink_smem_tx_avail;
            *(code **)(lVar5 + 0x20) = glink_smem_tx_write;
            *puVar1 = 0;
            **(undefined4 **)(lVar5 + 0x38) = 0;
            uVar9 = qcom_glink_native_probe(lVar4,9,lVar7,lVar5,0);
            if (uVar9 < 0xfffffffffffff001) goto LAB_001004bc;
            uVar9 = uVar9 & 0xffffffff;
          }
          else {
            _dev_err(lVar4,"failed to acquire TX fifo\n");
            uVar9 = (ulong)*(uint *)(lVar5 + 0x40);
          }
        }
        else {
          _dev_err(lVar4,"glink descriptor of invalid size\n");
          uVar9 = 0xffffffea;
        }
      }
      else {
        _dev_err(lVar4,"failed to acquire xprt descriptor\n");
      }
    }
  }
  device_unregister(lVar4);
  uVar9 = (ulong)(int)uVar9;
LAB_001004bc:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9);
  }
  return;
}



//------------------------------------------------------------
// qcom_glink_smem_release @ 0010050c size=28
// signature: undefined qcom_glink_smem_release(void)
// callers: []
//------------------------------------------------------------

void qcom_glink_smem_release(void)

{
  kfree();
  return;
}



//------------------------------------------------------------
// glink_smem_rx_avail @ 0010052c size=216
// signature: undefined glink_smem_rx_avail(void)
// callers: []
//------------------------------------------------------------

void glink_smem_rx_avail(ulong *param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  ulong uVar5;
  ulong uVar6;
  ulong local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_30 = 0;
  if (param_1[8] == 0) {
    uVar5 = qcom_smem_get((int)param_1[9],0x1e0,&local_30);
    if (0xfffffffffffff000 < uVar5) {
      _printk(&DAT_00100a2c);
      uVar5 = 0;
      goto LAB_001005bc;
    }
    param_1[8] = uVar5;
    *param_1 = local_30;
  }
  uVar1 = *(uint *)param_1[6];
  uVar2 = *(uint *)param_1[7];
  if (uVar2 < uVar1) {
    uVar6 = *param_1;
    uVar5 = ((ulong)uVar2 - (ulong)uVar1) + uVar6;
  }
  else {
    uVar5 = (ulong)(uVar2 - uVar1);
    uVar6 = *param_1;
  }
  local_30 = uVar5;
  if (uVar6 < uVar5) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x100600);
    (*pcVar4)();
  }
LAB_001005bc:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// glink_smem_rx_peak @ 0010060c size=160
// signature: undefined glink_smem_rx_peak(void)
// callers: []
//------------------------------------------------------------

void glink_smem_rx_peak(ulong *param_1,long param_2,int param_3,ulong param_4)

{
  uint uVar1;
  ulong uVar2;
  code *pcVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  
  uVar5 = *param_1;
  if (uVar5 < *(uint *)param_1[6]) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1006ac);
    (*pcVar3)();
  }
  uVar1 = *(uint *)param_1[6] + param_3;
  iVar4 = 0;
  if (uVar5 <= uVar1) {
    iVar4 = (int)uVar5;
  }
  uVar6 = (ulong)(uVar1 - iVar4);
  uVar5 = uVar5 - uVar6;
  uVar2 = uVar5;
  if (param_4 <= uVar5) {
    uVar2 = param_4;
  }
  if (uVar2 != 0) {
    __memcpy_fromio(param_2,param_1[8] + uVar6,uVar2);
  }
  if (uVar5 < param_4) {
    __memcpy_fromio(param_2 + uVar2,param_1[8],param_4 - uVar2);
  }
  return;
}



//------------------------------------------------------------
// glink_smem_rx_advance @ 001006b4 size=40
// signature: undefined glink_smem_rx_advance(void)
// callers: []
//------------------------------------------------------------

void glink_smem_rx_advance(ulong *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  
  uVar3 = *param_1;
  uVar2 = *(uint *)param_1[6] + param_2;
  if (uVar3 <= uVar2) {
    iVar1 = 0;
    if (uVar3 != 0) {
      iVar1 = (int)(uVar2 / uVar3);
    }
    uVar2 = uVar2 - iVar1 * (int)uVar3;
  }
  *(uint *)param_1[6] = uVar2;
  return;
}



//------------------------------------------------------------
// glink_smem_tx_avail @ 001006e0 size=68
// signature: undefined glink_smem_tx_avail(void)
// callers: []
//------------------------------------------------------------

ulong glink_smem_tx_avail(ulong *param_1)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  ulong uVar4;
  
  uVar3 = *(uint *)param_1[6] - *(uint *)param_1[7];
  if (*(uint *)param_1[6] < *(uint *)param_1[7] || uVar3 == 0) {
    uVar4 = *param_1;
    uVar3 = uVar3 + (int)uVar4;
  }
  else {
    uVar4 = *param_1;
  }
  uVar1 = 0;
  if (0xf < uVar3) {
    uVar1 = uVar3 - 0x10;
  }
  if (uVar4 < uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x100724);
    (*pcVar2)();
  }
  return (ulong)uVar1;
}



//------------------------------------------------------------
// glink_smem_tx_write @ 00100730 size=296
// signature: undefined glink_smem_tx_write(void)
// callers: []
//------------------------------------------------------------

void glink_smem_tx_write(ulong *param_1,void *param_2,ulong param_3,void *param_4,ulong param_5)

{
  size_t sVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  
  uVar2 = *(uint *)param_1[7];
  uVar6 = (ulong)uVar2;
  uVar5 = *param_1 - uVar6;
  if (*param_1 < uVar6) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x100854);
    (*pcVar3)();
  }
  sVar1 = uVar5;
  if (param_3 <= uVar5) {
    sVar1 = param_3;
  }
  if (sVar1 != 0) {
    memcpy((void *)(param_1[8] + uVar6),param_2,sVar1);
  }
  if (uVar5 < param_3) {
    memcpy((void *)param_1[8],(void *)((long)param_2 + sVar1),param_3 - sVar1);
  }
  uVar5 = *param_1;
  uVar2 = uVar2 + (int)param_3;
  iVar4 = 0;
  if (uVar5 <= uVar2) {
    iVar4 = (int)uVar5;
  }
  uVar2 = uVar2 - iVar4;
  uVar7 = (ulong)uVar2;
  uVar6 = uVar5 - uVar7;
  if (uVar5 < uVar7) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x100864);
    (*pcVar3)();
  }
  sVar1 = uVar6;
  if (param_5 <= uVar6) {
    sVar1 = param_5;
  }
  if (sVar1 != 0) {
    memcpy((void *)(param_1[8] + uVar7),param_4,sVar1);
  }
  if (uVar6 < param_5) {
    memcpy((void *)param_1[8],(void *)((long)param_4 + sVar1),param_5 - sVar1);
  }
  uVar5 = *param_1;
  uVar2 = uVar2 + (int)param_5;
  iVar4 = 0;
  if (uVar5 <= uVar2) {
    iVar4 = (int)uVar5;
  }
  DataSynchronizationBarrier(3,2,0);
  uVar2 = (uVar2 - iVar4) + 7 & 0xfffffff8;
  iVar4 = 0;
  if (uVar5 <= uVar2) {
    iVar4 = (int)uVar5;
  }
  *(uint *)param_1[7] = uVar2 - iVar4;
  return;
}



//------------------------------------------------------------
// qcom_glink_smem_start @ 00100870 size=28
// signature: undefined qcom_glink_smem_start(void)
// callers: []
//------------------------------------------------------------

void qcom_glink_smem_start(void)

{
  qcom_glink_native_start();
  return;
}



//------------------------------------------------------------
// qcom_glink_smem_unregister @ 00100890 size=52
// signature: undefined qcom_glink_smem_unregister(void)
// callers: []
//------------------------------------------------------------

void qcom_glink_smem_unregister(long param_1)

{
  if (param_1 != 0) {
    qcom_glink_native_remove();
    qcom_glink_native_unregister(param_1);
  }
  return;
}



//------------------------------------------------------------
// kmalloc_trace @ 00102008 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qcom_glink_smem_register]
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
// callers: [qcom_glink_smem_register]
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
// callers: [qcom_glink_smem_register]
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
// callers: [qcom_glink_smem_register]
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
// callers: [qcom_glink_smem_register]
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
// callers: [qcom_glink_smem_register]
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
// callers: [glink_smem_rx_avail, qcom_glink_smem_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_native_probe @ 00102040 size=1
// signature: undefined qcom_glink_native_probe(void)
// callers: [qcom_glink_smem_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_native_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102048 size=1
// signature: undefined _printk(void)
// callers: [glink_smem_rx_avail, qcom_glink_smem_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 00102050 size=1
// signature: undefined put_device(void)
// callers: [qcom_glink_smem_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102058 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_glink_smem_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_unregister @ 00102060 size=1
// signature: undefined device_unregister(void)
// callers: [qcom_glink_smem_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102068 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [glink_smem_rx_avail, qcom_glink_smem_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102070 size=1
// signature: undefined kfree(void)
// callers: [qcom_glink_smem_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_fromio @ 00102078 size=1
// signature: undefined __memcpy_fromio(void)
// callers: [glink_smem_rx_peak]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_fromio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00102080 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [glink_smem_tx_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_native_start @ 00102088 size=1
// signature: undefined qcom_glink_native_start(void)
// callers: [qcom_glink_smem_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_native_start(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_native_remove @ 00102090 size=1
// signature: undefined qcom_glink_native_remove(void)
// callers: [qcom_glink_smem_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_native_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_native_unregister @ 00102098 size=1
// signature: undefined qcom_glink_native_unregister(void)
// callers: [qcom_glink_smem_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_native_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



