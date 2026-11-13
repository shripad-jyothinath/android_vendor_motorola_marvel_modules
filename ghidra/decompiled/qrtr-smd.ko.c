// Decompiled by Ghidra 12.2
// Program: qrtr-smd.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_smd_qrtr_probe @ 0010014c size=392
// signature: undefined qcom_smd_qrtr_probe(void)
// callers: []
//------------------------------------------------------------

int qcom_smd_qrtr_probe(long param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  long lVar5;
  undefined4 local_4c;
  long local_48;
  ulong local_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_48 = 0;
  local_40 = 0;
  local_4c = 0;
  puVar3 = (undefined8 *)devm_kmalloc(param_1,0x20,0xdc0);
  if (puVar3 == (undefined8 *)0x0) {
LAB_0010021c:
    iVar1 = -0xc;
  }
  else {
    uVar4 = *(undefined8 *)(param_1 + 0x2e8);
    puVar3[2] = *(undefined8 *)(param_1 + 0x3c8);
    puVar3[3] = param_1;
    *puVar3 = qcom_smd_qrtr_send;
    iVar1 = of_property_read_variable_u32_array(uVar4,"qcom,net-id",&local_4c,1,0);
    if (iVar1 < 0) {
      local_4c = 1;
    }
    lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),"qcom,low-latency",0);
    uVar2 = of_property_count_elems_of_size(*(undefined8 *)(param_1 + 0x2e8),"qcom,no-wake-svc",4);
    if (0 < (int)uVar2) {
      local_40 = (ulong)uVar2;
      local_48 = __kmalloc((ulong)uVar2 << 2,0xcc0);
      if (local_48 == 0) goto LAB_0010021c;
      of_property_read_variable_u32_array
                (*(undefined8 *)(param_1 + 0x2e8),"qcom,no-wake-svc",local_48,(ulong)uVar2,0);
    }
    iVar1 = qrtr_endpoint_register(puVar3,local_4c,lVar5 != 0,&local_48);
    kfree(local_48);
    if (iVar1 == 0) {
      *(undefined8 **)(param_1 + 0x98) = puVar3;
      _printk(&DAT_00100678,"qcom_smd_qrtr_probe");
    }
    else {
      _dev_err(puVar3[3],"endpoint register failed: %d, low-latency: %d\n",iVar1,lVar5 != 0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// qcom_smd_qrtr_remove @ 001002d8 size=48
// signature: undefined qcom_smd_qrtr_remove(void)
// callers: []
//------------------------------------------------------------

void qcom_smd_qrtr_remove(long param_1)

{
  qrtr_endpoint_unregister(*(undefined8 *)(param_1 + 0x98));
  *(undefined8 *)(param_1 + 0x98) = 0;
  return;
}



//------------------------------------------------------------
// qcom_smd_qrtr_callback @ 0010030c size=180
// signature: undefined qcom_smd_qrtr_callback(void)
// callers: []
//------------------------------------------------------------

int qcom_smd_qrtr_callback(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  if (lVar3 == 0) {
    iVar1 = ___ratelimit(qcom_smd_qrtr_callback__rs,"qcom_smd_qrtr_callback");
    if (iVar1 != 0) {
      _printk(&DAT_0010071b,"qcom_smd_qrtr_callback");
    }
    iVar1 = -0xb;
  }
  else {
    iVar1 = qrtr_endpoint_post(lVar3,param_2,(long)param_3);
    if (iVar1 == -0x16) {
      _dev_err(*(undefined8 *)(lVar3 + 0x18),"invalid ipcrouter packet\n");
      iVar1 = 0;
    }
    uVar2 = qcom_glink_is_wakeup(1);
    if ((uVar2 & 1) != 0) {
      qrtr_print_wakeup_reason(param_2);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// qcom_smd_qrtr_send @ 001003c4 size=116
// signature: undefined qcom_smd_qrtr_send(void)
// callers: []
//------------------------------------------------------------

int qcom_smd_qrtr_send(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  
  if ((*(int *)(param_2 + 0x74) == 0) || (lVar2 = __pskb_pull_tail(param_2), lVar2 != 0)) {
    iVar1 = rpmsg_send(*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_2 + 0xe0),
                       *(undefined4 *)(param_2 + 0x70));
    if (iVar1 == 0) {
      consume_skb(param_2);
      return 0;
    }
  }
  else {
    iVar1 = -0xc;
  }
  kfree_skb_reason(param_2,1);
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 0010043c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __register_rpmsg_driver(&qcom_smd_qrtr_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010046c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  unregister_rpmsg_driver(&qcom_smd_qrtr_driver);
  return;
}



//------------------------------------------------------------
// __register_rpmsg_driver @ 00102000 size=1
// signature: undefined __register_rpmsg_driver(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __register_rpmsg_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_rpmsg_driver @ 00102008 size=1
// signature: undefined unregister_rpmsg_driver(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_rpmsg_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_smd_qrtr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102018 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qcom_smd_qrtr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00102020 size=1
// signature: undefined of_find_property(void)
// callers: [qcom_smd_qrtr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 00102028 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [qcom_smd_qrtr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00102030 size=1
// signature: undefined __kmalloc(void)
// callers: [qcom_smd_qrtr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qrtr_endpoint_register @ 00102038 size=1
// signature: undefined qrtr_endpoint_register(void)
// callers: [qcom_smd_qrtr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qrtr_endpoint_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102040 size=1
// signature: undefined kfree(void)
// callers: [qcom_smd_qrtr_probe]
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
// callers: [qcom_smd_qrtr_callback, qcom_smd_qrtr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102050 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_smd_qrtr_callback, qcom_smd_qrtr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102058 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_smd_qrtr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qrtr_endpoint_unregister @ 00102060 size=1
// signature: undefined qrtr_endpoint_unregister(void)
// callers: [qcom_smd_qrtr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qrtr_endpoint_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qrtr_endpoint_post @ 00102068 size=1
// signature: undefined qrtr_endpoint_post(void)
// callers: [qcom_smd_qrtr_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qrtr_endpoint_post(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_is_wakeup @ 00102070 size=1
// signature: undefined qcom_glink_is_wakeup(void)
// callers: [qcom_smd_qrtr_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_is_wakeup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qrtr_print_wakeup_reason @ 00102078 size=1
// signature: undefined qrtr_print_wakeup_reason(void)
// callers: [qcom_smd_qrtr_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qrtr_print_wakeup_reason(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00102080 size=1
// signature: undefined ___ratelimit(void)
// callers: [qcom_smd_qrtr_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pskb_pull_tail @ 00102088 size=1
// signature: undefined __pskb_pull_tail(void)
// callers: [qcom_smd_qrtr_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pskb_pull_tail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmsg_send @ 00102090 size=1
// signature: undefined rpmsg_send(void)
// callers: [qcom_smd_qrtr_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmsg_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// consume_skb @ 00102098 size=1
// signature: undefined consume_skb(void)
// callers: [qcom_smd_qrtr_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void consume_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_skb_reason @ 001020a0 size=1
// signature: undefined kfree_skb_reason(void)
// callers: [qcom_smd_qrtr_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_skb_reason(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



