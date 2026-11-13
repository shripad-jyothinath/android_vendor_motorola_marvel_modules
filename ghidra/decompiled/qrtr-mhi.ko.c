// Decompiled by Ghidra 12.2
// Program: qrtr-mhi.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_mhi_qrtr_probe @ 001001c4 size=452
// signature: undefined qcom_mhi_qrtr_probe(void)
// callers: []
//------------------------------------------------------------

int qcom_mhi_qrtr_probe(long param_1)

{
  bool bVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined4 uVar5;
  long *plVar6;
  undefined8 local_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  puVar3 = (undefined8 *)devm_kmalloc(param_1 + 0x28,0x60,0xdc0);
  if (puVar3 == (undefined8 *)0x0) {
    iVar2 = -0xc;
    goto LAB_00100350;
  }
  puVar3[2] = param_1;
  puVar3[3] = param_1 + 0x28;
  *puVar3 = qcom_mhi_qrtr_send;
  *(undefined4 *)(puVar3 + 4) = 0;
  __init_swait_queue_head(puVar3 + 5,"&x->wait",&init_completion___key);
  *(undefined4 *)(puVar3 + 8) = 0;
  __init_swait_queue_head(puVar3 + 9,"&x->wait",&init_completion___key);
  plVar6 = *(long **)(param_1 + 0x10);
  *(undefined8 **)(param_1 + 0xc0) = puVar3;
  local_50 = 0;
  lVar4 = of_find_compatible_node(0,0,"qcom,qrtr-mhi");
  if (lVar4 == 0) {
LAB_00100304:
    bVar1 = false;
    uVar5 = 1;
  }
  else {
    uVar5 = 1;
    iVar2 = of_property_read_variable_u32_array(lVar4,"qcom,dev-id",(long)&local_50 + 4,1,0);
    if (iVar2 < 0) {
      bVar1 = false;
    }
    else {
      if (local_50._4_4_ != *(ushort *)(*plVar6 + -0x92)) goto LAB_00100304;
      iVar2 = of_property_read_variable_u32_array(lVar4,"qcom,net-id",&local_50,1,0);
      uVar5 = (undefined4)local_50;
      if (iVar2 < 0) {
        uVar5 = 1;
      }
      lVar4 = of_find_property(lVar4,"qcom,low-latency",0);
      bVar1 = lVar4 != 0;
    }
  }
  iVar2 = qrtr_endpoint_register(puVar3,uVar5,bVar1,0);
  if (iVar2 == 0) {
    iVar2 = mhi_prepare_for_transfer_autoqueue(param_1);
    if (iVar2 == 0) {
      complete_all(puVar3 + 4);
    }
    else {
      qrtr_endpoint_unregister(puVar3);
    }
  }
LAB_00100350:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// qcom_mhi_qrtr_remove @ 0010038c size=56
// signature: undefined qcom_mhi_qrtr_remove(void)
// callers: []
//------------------------------------------------------------

void qcom_mhi_qrtr_remove(long param_1)

{
  qrtr_endpoint_unregister(*(undefined8 *)(param_1 + 0xc0));
  mhi_unprepare_from_transfer(param_1);
  *(undefined8 *)(param_1 + 0xc0) = 0;
  return;
}



//------------------------------------------------------------
// qcom_mhi_qrtr_ul_callback @ 001003c8 size=144
// signature: undefined qcom_mhi_qrtr_ul_callback(void)
// callers: []
//------------------------------------------------------------

void qcom_mhi_qrtr_ul_callback(long param_1,long *param_2)

{
  _STACK *p_Var1;
  int iVar2;
  char cVar3;
  bool bVar4;
  _STACK *p_Var5;
  long lVar6;
  long lVar7;
  
  lVar6 = *param_2;
  p_Var5 = *(_STACK **)(lVar6 + 0x18);
  lVar7 = *(long *)(param_1 + 0xc0);
  if (p_Var5 != (_STACK *)0x0) {
    p_Var1 = p_Var5 + 4;
    Hint_Prefetch(p_Var1,2,0,1);
    do {
      iVar2 = p_Var1->num;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(p_Var1,0x10);
      if (bVar4) {
        p_Var1->num = iVar2 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (iVar2 == 1) {
      DataMemoryBarrier(2,1);
      sk_free(p_Var5);
    }
    else if (iVar2 < 1) {
      refcount_warn_saturate(p_Var1,3);
    }
  }
  consume_skb(lVar6);
  complete_all(lVar7 + 0x40);
  return;
}



//------------------------------------------------------------
// qcom_mhi_qrtr_dl_callback @ 0010046c size=92
// signature: undefined qcom_mhi_qrtr_dl_callback(void)
// callers: []
//------------------------------------------------------------

void qcom_mhi_qrtr_dl_callback(long param_1,undefined8 *param_2)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xc0);
  if (((lVar2 != 0) && (*(int *)((long)param_2 + 0x14) == 0)) &&
     (iVar1 = qrtr_endpoint_post(lVar2,*param_2,param_2[1]), iVar1 == -0x16)) {
    _dev_err(*(undefined8 *)(lVar2 + 0x18),"invalid ipcrouter packet\n");
  }
  return;
}



//------------------------------------------------------------
// qcom_mhi_qrtr_send @ 001004cc size=428
// signature: undefined qcom_mhi_qrtr_send(void)
// callers: []
//------------------------------------------------------------

int qcom_mhi_qrtr_send(long param_1,long param_2)

{
  uint *puVar1;
  _STACK *p_Var2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  _STACK *p_Var9;
  undefined8 uVar10;
  
  do {
    *(undefined4 *)(param_1 + 0x40) = 0;
    if (*(long *)(param_2 + 0x18) != 0) {
      puVar1 = (uint *)(*(long *)(param_2 + 0x18) + 0x80);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        uVar3 = *puVar1;
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar5) {
          *puVar1 = uVar3 + 1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      if (uVar3 == 0) {
        uVar10 = 2;
      }
      else {
        if (-1 < (int)(uVar3 + 1 | uVar3)) goto LAB_00100540;
        uVar10 = 1;
      }
      refcount_warn_saturate(puVar1,uVar10);
    }
LAB_00100540:
    iVar6 = wait_for_completion_interruptible_timeout(param_1 + 0x20,0x4e2);
    if (iVar6 < 1) {
      _printk(&DAT_00100977,"__qcom_mhi_qrtr_send",iVar6);
      iVar7 = -0x6e;
      if (iVar6 != 0) {
        iVar7 = iVar6;
      }
      p_Var9 = *(_STACK **)(param_2 + 0x18);
joined_r0x001005e0:
      if (p_Var9 != (_STACK *)0x0) {
        p_Var2 = p_Var9 + 4;
        Hint_Prefetch(p_Var2,2,0,1);
        do {
          iVar6 = p_Var2->num;
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(p_Var2,0x10);
          if (bVar5) {
            p_Var2->num = iVar6 + -1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        if (iVar6 == 1) {
          DataMemoryBarrier(2,1);
          sk_free(p_Var9);
        }
        else if (iVar6 < 1) {
          refcount_warn_saturate(p_Var2,3);
        }
      }
      kfree_skb_reason(param_2,1);
    }
    else {
      if ((*(int *)(param_2 + 0x74) != 0) && (lVar8 = __pskb_pull_tail(param_2), lVar8 == 0)) {
        iVar7 = -0xc;
LAB_0010059c:
        p_Var9 = *(_STACK **)(param_2 + 0x18);
        goto joined_r0x001005e0;
      }
      iVar7 = mhi_queue_skb(*(undefined8 *)(param_1 + 0x10),1,param_2,
                            *(undefined4 *)(param_2 + 0x70),2);
      if ((iVar7 != -0xb) && (iVar7 != 0)) goto LAB_0010059c;
    }
    if (iVar7 != -0xb) {
      return iVar7;
    }
    wait_for_completion((undefined4 *)(param_1 + 0x40));
  } while( true );
}



//------------------------------------------------------------
// init_module @ 00100690 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __mhi_driver_register(&qcom_mhi_qrtr_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001006c0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  mhi_driver_unregister(&qcom_mhi_qrtr_driver);
  return;
}



//------------------------------------------------------------
// __mhi_driver_register @ 00102000 size=1
// signature: undefined __mhi_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mhi_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mhi_driver_unregister @ 00102008 size=1
// signature: undefined mhi_driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mhi_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_mhi_qrtr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00102018 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [qcom_mhi_qrtr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_compatible_node @ 00102020 size=1
// signature: undefined of_find_compatible_node(void)
// callers: [qcom_mhi_qrtr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_compatible_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102028 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qcom_mhi_qrtr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00102030 size=1
// signature: undefined of_find_property(void)
// callers: [qcom_mhi_qrtr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qrtr_endpoint_register @ 00102038 size=1
// signature: undefined qrtr_endpoint_register(void)
// callers: [qcom_mhi_qrtr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qrtr_endpoint_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mhi_prepare_for_transfer_autoqueue @ 00102040 size=1
// signature: undefined mhi_prepare_for_transfer_autoqueue(void)
// callers: [qcom_mhi_qrtr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mhi_prepare_for_transfer_autoqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qrtr_endpoint_unregister @ 00102048 size=1
// signature: undefined qrtr_endpoint_unregister(void)
// callers: [qcom_mhi_qrtr_probe, qcom_mhi_qrtr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qrtr_endpoint_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete_all @ 00102050 size=1
// signature: undefined complete_all(void)
// callers: [qcom_mhi_qrtr_ul_callback, qcom_mhi_qrtr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102058 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_mhi_qrtr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mhi_unprepare_from_transfer @ 00102060 size=1
// signature: undefined mhi_unprepare_from_transfer(void)
// callers: [qcom_mhi_qrtr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mhi_unprepare_from_transfer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sk_free @ 00102070 size=1
// signature: void sk_free(_STACK * param_1)
// callers: [qcom_mhi_qrtr_send, qcom_mhi_qrtr_ul_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void sk_free(_STACK *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// consume_skb @ 00102078 size=1
// signature: undefined consume_skb(void)
// callers: [qcom_mhi_qrtr_ul_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void consume_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 00102080 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [qcom_mhi_qrtr_send, qcom_mhi_qrtr_ul_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qrtr_endpoint_post @ 00102088 size=1
// signature: undefined qrtr_endpoint_post(void)
// callers: [qcom_mhi_qrtr_dl_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qrtr_endpoint_post(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102090 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_mhi_qrtr_dl_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_interruptible_timeout @ 00102098 size=1
// signature: undefined wait_for_completion_interruptible_timeout(void)
// callers: [qcom_mhi_qrtr_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_interruptible_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pskb_pull_tail @ 001020a0 size=1
// signature: undefined __pskb_pull_tail(void)
// callers: [qcom_mhi_qrtr_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pskb_pull_tail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mhi_queue_skb @ 001020a8 size=1
// signature: undefined mhi_queue_skb(void)
// callers: [qcom_mhi_qrtr_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mhi_queue_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001020b0 size=1
// signature: undefined _printk(void)
// callers: [qcom_mhi_qrtr_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_skb_reason @ 001020b8 size=1
// signature: undefined kfree_skb_reason(void)
// callers: [qcom_mhi_qrtr_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_skb_reason(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion @ 001020c0 size=1
// signature: undefined wait_for_completion(void)
// callers: [qcom_mhi_qrtr_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



