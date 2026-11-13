// Decompiled by Ghidra 12.2
// Program: mem_buf_msgq.ko
// Image base: 00100000

//------------------------------------------------------------
// mem_buf_construct_alloc_req @ 001003ac size=276
// signature: undefined mem_buf_construct_alloc_req(void)
// callers: []
//------------------------------------------------------------

undefined4 *
mem_buf_construct_alloc_req
          (undefined4 *param_1,undefined8 param_2,uint *param_3,int param_4,undefined8 param_5,
          undefined4 param_6)

{
  size_t __n;
  long lVar1;
  uint uVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 *puVar5;
  long lVar6;
  
  uVar2 = *param_3;
  uVar3 = *param_1;
  lVar6 = (ulong)uVar2 * 4;
  lVar1 = lVar6 + 0x20 + (ulong)(param_4 == 1) * 0x80;
  puVar5 = (undefined4 *)__kmalloc(lVar1,0xdc0);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0xfffffffffffffff4;
  }
  else {
    puVar5[2] = (int)lVar1;
    *(undefined8 *)(puVar5 + 3) = param_2;
    __n = lVar6 + 4;
    *puVar5 = uVar3;
    puVar5[1] = 0;
    puVar5[5] = param_4;
    puVar5[6] = param_6;
    if ((uVar2 != 0) && ((mem_buf_construct_alloc_req___already_done & 1) == 0)) {
      mem_buf_construct_alloc_req___already_done = 1;
      __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",__n
                    ,"field \"&req->acl_desc\" at drivers/soc/qcom/mem_buf/mem-buf-msgq.c:127",4);
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x800,0x100528);
      (*pcVar4)();
    }
    memcpy(puVar5 + 7,param_3,__n);
    if (param_4 == 1) {
      strscpy(puVar5 + (ulong)uVar2 + 8,param_5,0x80);
    }
  }
  return puVar5;
}



//------------------------------------------------------------
// mem_buf_construct_alloc_resp @ 00100530 size=116
// signature: undefined mem_buf_construct_alloc_resp(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 *
mem_buf_construct_alloc_resp
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)kmalloc_trace(__printk,0xdc0,0x18);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0xfffffffffffffff4;
  }
  else {
    uVar1 = *param_1;
    puVar2[3] = param_2;
    puVar2[4] = param_3;
    puVar2[5] = param_4;
    *puVar2 = uVar1;
    *(undefined8 *)(puVar2 + 1) = 0x1800000001;
  }
  return puVar2;
}



//------------------------------------------------------------
// mem_buf_construct_relinquish_msg @ 001005a8 size=108
// signature: undefined mem_buf_construct_relinquish_msg(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 *
mem_buf_construct_relinquish_msg(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)kmalloc_trace(__printk,0xdc0,0x14);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0xfffffffffffffff4;
  }
  else {
    uVar1 = *param_1;
    puVar2[3] = param_3;
    puVar2[4] = param_2;
    *puVar2 = uVar1;
    *(undefined8 *)(puVar2 + 1) = 0x1400000002;
  }
  return puVar2;
}



//------------------------------------------------------------
// mem_buf_construct_relinquish_resp @ 00100618 size=88
// signature: undefined mem_buf_construct_relinquish_resp(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * mem_buf_construct_relinquish_resp(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)kmalloc_trace(__printk,0xdc0,0x14);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0xfffffffffffffff4;
  }
  else {
    *puVar1 = *param_1;
    *(undefined8 *)(puVar1 + 1) = 0x1400000003;
  }
  return puVar1;
}



//------------------------------------------------------------
// mem_buf_retrieve_txn_id @ 00100674 size=8
// signature: undefined mem_buf_retrieve_txn_id(void)
// callers: []
//------------------------------------------------------------

undefined4 mem_buf_retrieve_txn_id(undefined4 *param_1)

{
  return *param_1;
}



//------------------------------------------------------------
// mem_buf_init_txn @ 00100680 size=224
// signature: undefined mem_buf_init_txn(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * mem_buf_init_txn(long param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)kmalloc_trace(__printk,0xdc0,0x30);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0xfffffffffffffff4;
  }
  else {
    lVar1 = param_1 + 0x10;
    mutex_lock(lVar1);
    iVar2 = idr_alloc_cyclic(param_1 + 0x40,piVar3,0,0x7fffffff,0xcc0);
    if (iVar2 < 0) {
      _printk(&DAT_0010110a,"mem_buf_init_txn",iVar2);
      mutex_unlock(lVar1);
      kfree(piVar3);
      piVar3 = (int *)(long)iVar2;
    }
    else {
      *piVar3 = iVar2;
      piVar3[2] = 0;
      __init_swait_queue_head(piVar3 + 4,"&x->wait",&init_completion___key);
      *(undefined8 *)(piVar3 + 10) = param_2;
      mutex_unlock(lVar1);
    }
  }
  return piVar3;
}



//------------------------------------------------------------
// mem_buf_msgq_send @ 00100764 size=128
// signature: undefined mem_buf_msgq_send(void)
// callers: []
//------------------------------------------------------------

int mem_buf_msgq_send(long param_1,long param_2)

{
  int iVar1;
  
  if (*(uint *)(param_2 + 4) < 4) {
    iVar1 = gh_msgq_send(*(undefined8 *)(param_1 + 0x58),param_2,*(undefined4 *)(param_2 + 8),0);
    if (iVar1 < 0) {
      _printk(&DAT_00101256,"mem_buf_msgq_send",iVar1);
    }
  }
  else {
    _printk(&DAT_001012d9,"mem_buf_msgq_send");
    iVar1 = -0x16;
  }
  return iVar1;
}



//------------------------------------------------------------
// mem_buf_txn_wait @ 001007e8 size=176
// signature: undefined mem_buf_txn_wait(void)
// callers: []
//------------------------------------------------------------

int mem_buf_txn_wait(long param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  ulong uVar3;
  
  iVar2 = wait_for_completion_timeout(param_2 + 2,0x36b);
  mutex_lock(param_1 + 0x10);
  if ((iVar2 == 0) && (uVar3 = try_wait_for_completion(param_2 + 2), (uVar3 & 1) == 0)) {
    _printk(&DAT_00101215,"mem_buf_txn_wait");
    bVar1 = false;
    iVar2 = -0x6e;
  }
  else {
    iVar2 = 0;
    bVar1 = true;
  }
  idr_remove(param_1 + 0x40,(long)*param_2);
  mutex_unlock(param_1 + 0x10);
  if (bVar1) {
    iVar2 = param_2[1];
  }
  return iVar2;
}



//------------------------------------------------------------
// mem_buf_destroy_txn @ 0010089c size=32
// signature: undefined mem_buf_destroy_txn(void)
// callers: []
//------------------------------------------------------------

void mem_buf_destroy_txn(undefined8 param_1,undefined8 param_2)

{
  kfree(param_2);
  return;
}



//------------------------------------------------------------
// mem_buf_msgq_register @ 001008c0 size=488
// signature: undefined mem_buf_msgq_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * mem_buf_msgq_register(char *param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  undefined8 *puVar5;
  ulong uVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  long *plVar10;
  
  puVar5 = (undefined8 *)kmalloc_trace(_kfree,0xdc0,0x78);
  if (puVar5 == (undefined8 *)0x0) {
    return (undefined8 *)0xfffffffffffffff4;
  }
  if ((((param_2 == (undefined8 *)0x0) || (plVar10 = (long *)*param_2, plVar10 == (long *)0x0)) ||
      (*plVar10 == 0)) || ((plVar10[1] == 0 || (plVar10[2] == 0)))) {
LAB_00100944:
    puVar9 = (undefined8 *)0xffffffffffffffea;
  }
  else {
    iVar4 = strcmp(param_1,"trusted_vm");
    if (iVar4 == 0) {
      lVar7 = 0;
    }
    else {
      iVar4 = strcmp(param_1,(char *)0x0);
      if (iVar4 != 0) goto LAB_00100944;
      lVar7 = 1;
    }
    puVar1 = puVar5 + 0xd;
    uVar2 = *(undefined4 *)(mem_buf_msgqs + lVar7 * 0x10 + 8);
    puVar5[0xd] = puVar1;
    puVar5[0xe] = puVar1;
    uVar8 = param_2[1];
    *puVar5 = plVar10;
    puVar5[1] = uVar8;
    __mutex_init(puVar5 + 2,"&desc->idr_mutex",&mem_buf_msgq_register___key);
    puVar5[8] = 0x1000000400000000;
    puVar5[9] = 0;
    puVar5[10] = 0;
    puVar9 = (undefined8 *)gh_msgq_register(uVar2);
    puVar5[0xb] = puVar9;
    if (puVar9 < (undefined8 *)0xfffffffffffff001) {
      mutex_lock(&mem_buf_msgq_list_lock);
      puVar3 = PTR_mem_buf_msgq_list_001013b0;
      uVar6 = __list_add_valid(puVar1,PTR_mem_buf_msgq_list_001013b0,&mem_buf_msgq_list);
      if ((uVar6 & 1) != 0) {
        PTR_mem_buf_msgq_list_001013b0 = (undefined *)puVar1;
        puVar5[0xd] = &mem_buf_msgq_list;
        puVar5[0xe] = puVar3;
        *(undefined8 **)puVar3 = puVar1;
      }
      mutex_unlock(&mem_buf_msgq_list_lock);
      puVar9 = (undefined8 *)
               kthread_create_on_node
                         (mem_buf_msgq_recv_fn,puVar5,0xffffffff,"mem_buf_%s_rcvr",param_1);
      if (puVar9 < (undefined8 *)0xfffffffffffff001) {
        wake_up_process(puVar9);
        puVar5[0xc] = puVar9;
        return puVar5;
      }
      puVar5[0xc] = puVar9;
      _printk(&DAT_001011ca,puVar9);
      gh_msgq_unregister(puVar5[0xb]);
    }
    else {
      _printk(&DAT_00101311,puVar9);
    }
    idr_destroy(puVar5 + 8);
    kfree(puVar5);
  }
  return puVar9;
}



//------------------------------------------------------------
// mem_buf_msgq_recv_fn @ 00100aac size=804
// signature: undefined mem_buf_msgq_recv_fn(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mem_buf_msgq_recv_fn(long *param_1)

{
  long *plVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  ulong uVar8;
  undefined8 uVar9;
  long lVar10;
  undefined *puVar11;
  char *pcVar12;
  code *pcVar13;
  ulong local_70;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_70 = 0;
  puVar7 = (undefined4 *)kmalloc_trace(_gh_msgq_send,0xdc0,0xf0);
  if (puVar7 == (undefined4 *)0x0) {
    uVar9 = 0xfffffff4;
  }
  else {
    uVar8 = kthread_should_stop();
    if ((uVar8 & 1) == 0) {
      plVar1 = param_1 + 2;
      lVar3 = sp_el0;
      do {
        iVar5 = gh_msgq_recv(param_1[0xb],puVar7,0xf0,&local_70,0);
        uVar8 = local_70;
        if (iVar5 < 0) {
          iVar4 = ___ratelimit(mem_buf_msgq_recv_fn__rs,"mem_buf_msgq_recv_fn");
          if (iVar4 != 0) {
            puVar11 = &DAT_001010cf;
            pcVar12 = "mem_buf_msgq_recv_fn";
LAB_00100d34:
            _printk(puVar11,pcVar12,iVar5);
          }
          goto LAB_00100b94;
        }
        if ((local_70 < 0xc) || (local_70 != (uint)puVar7[2])) {
          _printk(&DAT_0010133e,"mem_buf_process_msg",local_70);
          goto LAB_00100b94;
        }
        iVar5 = puVar7[1];
        switch(iVar5) {
        case 0:
          lVar10 = param_1[1];
          pcVar13 = *(code **)*param_1;
          goto LAB_00100c00;
        case 1:
          mutex_lock(plVar1);
          uVar2 = *(uint *)(lVar3 + 0x44);
          *(uint *)(lVar3 + 0x44) = uVar2 | 0x800;
          lVar10 = idr_find(param_1 + 8,*puVar7);
          if (lVar10 == 0) {
            _printk(&DAT_00101286,"mem_buf_process_alloc_resp",*puVar7);
            mutex_unlock(plVar1);
            if (puVar7[3] == 0) {
              if (*(int *)(*(code **)(*param_1 + 0x18) + -4) != -0x4fdd1823) {
                    /* WARNING: Does not return */
                pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x100da0);
                (*pcVar13)();
              }
              (**(code **)(*param_1 + 0x18))(param_1[1],puVar7[5],puVar7[4]);
            }
            mutex_lock(plVar1);
          }
          else {
            if (*(int *)(*(code **)(*param_1 + 8) + -4) != -0x76fd7064) {
                    /* WARNING: Does not return */
              pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x100cbc);
              (*pcVar13)();
            }
            uVar6 = (**(code **)(*param_1 + 8))
                              (param_1[1],puVar7,uVar8,*(undefined8 *)(lVar10 + 0x28));
            *(undefined4 *)(lVar10 + 4) = uVar6;
            complete(lVar10 + 8);
          }
          *(uint *)(lVar3 + 0x44) =
               *(uint *)(lVar3 + 0x44) & 0xfffff000 |
               *(uint *)(lVar3 + 0x44) & 0x7ff | (uVar2 >> 0xb & 1) << 0xb;
          mutex_unlock(plVar1);
          break;
        case 2:
          lVar10 = param_1[1];
          pcVar13 = *(code **)(*param_1 + 0x10);
LAB_00100c00:
          if (*(int *)(pcVar13 + -4) != -0xa12073e) {
                    /* WARNING: Does not return */
            pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x100c20);
            (*pcVar13)();
          }
          (*pcVar13)(lVar10,puVar7,local_70);
          break;
        case 3:
          if (local_70 == 0x14) {
            mutex_lock(plVar1);
            lVar10 = idr_find(param_1 + 8,*puVar7);
            if (lVar10 == 0) {
              _printk(&DAT_00101286,"mem_buf_process_relinquish_resp",*puVar7);
            }
            else {
              complete(lVar10 + 8);
            }
            mutex_unlock(plVar1);
          }
          else {
            _printk(&DAT_001012aa,"mem_buf_process_relinquish_resp");
          }
          break;
        default:
          puVar11 = &DAT_001010a3;
          pcVar12 = "mem_buf_process_msg";
          goto LAB_00100d34;
        }
LAB_00100b94:
        uVar8 = kthread_should_stop();
      } while ((uVar8 & 1) == 0);
    }
    kfree(puVar7);
    uVar9 = 0;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9);
  }
  return;
}



//------------------------------------------------------------
// mem_buf_msgq_unregister @ 00100e38 size=136
// signature: undefined mem_buf_msgq_unregister(void)
// callers: []
//------------------------------------------------------------

void mem_buf_msgq_unregister(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  
  kthread_stop(*(undefined8 *)(param_1 + 0x60));
  mutex_lock(&mem_buf_msgq_list_lock);
  uVar3 = __list_del_entry_valid(param_1 + 0x68);
  if ((uVar3 & 1) != 0) {
    lVar1 = *(long *)(param_1 + 0x68);
    plVar2 = *(long **)(param_1 + 0x70);
    *(long **)(lVar1 + 8) = plVar2;
    *plVar2 = lVar1;
  }
  *(undefined8 *)(param_1 + 0x68) = 0xdead000000000100;
  *(undefined8 *)(param_1 + 0x70) = 0xdead000000000122;
  mutex_unlock(&mem_buf_msgq_list_lock);
  gh_msgq_unregister(*(undefined8 *)(param_1 + 0x58));
  idr_destroy(param_1 + 0x40);
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// __kmalloc @ 00103000 size=1
// signature: undefined __kmalloc(void)
// callers: [mem_buf_construct_alloc_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00103008 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [mem_buf_construct_alloc_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00103010 size=1
// signature: undefined strscpy(void)
// callers: [mem_buf_construct_alloc_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 00103040 size=1
// signature: undefined __warn_printk(void)
// callers: [mem_buf_construct_alloc_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00103050 size=1
// signature: undefined kmalloc_trace(void)
// callers: [mem_buf_construct_relinquish_resp, mem_buf_construct_alloc_resp, mem_buf_msgq_register, mem_buf_init_txn, mem_buf_msgq_recv_fn, mem_buf_construct_relinquish_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103058 size=1
// signature: undefined mutex_lock(void)
// callers: [mem_buf_msgq_unregister, mem_buf_txn_wait, mem_buf_msgq_register, mem_buf_init_txn, mem_buf_msgq_recv_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_alloc_cyclic @ 00103060 size=1
// signature: undefined idr_alloc_cyclic(void)
// callers: [mem_buf_init_txn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_alloc_cyclic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00103068 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [mem_buf_init_txn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103070 size=1
// signature: undefined mutex_unlock(void)
// callers: [mem_buf_msgq_unregister, mem_buf_txn_wait, mem_buf_msgq_register, mem_buf_init_txn, mem_buf_msgq_recv_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103078 size=1
// signature: undefined _printk(void)
// callers: [mem_buf_txn_wait, mem_buf_msgq_register, mem_buf_init_txn, mem_buf_msgq_recv_fn, mem_buf_msgq_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00103080 size=1
// signature: undefined kfree(void)
// callers: [mem_buf_msgq_unregister, mem_buf_destroy_txn, mem_buf_msgq_register, mem_buf_init_txn, mem_buf_msgq_recv_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_msgq_send @ 00103088 size=1
// signature: undefined gh_msgq_send(void)
// callers: [mem_buf_msgq_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_msgq_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00103090 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [mem_buf_txn_wait]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// try_wait_for_completion @ 00103098 size=1
// signature: undefined try_wait_for_completion(void)
// callers: [mem_buf_txn_wait]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void try_wait_for_completion(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_remove @ 001030a0 size=1
// signature: undefined idr_remove(void)
// callers: [mem_buf_txn_wait]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001030a8 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [mem_buf_msgq_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001030b0 size=1
// signature: undefined __mutex_init(void)
// callers: [mem_buf_msgq_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_msgq_register @ 001030b8 size=1
// signature: undefined gh_msgq_register(void)
// callers: [mem_buf_msgq_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_msgq_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001030c0 size=1
// signature: undefined __list_add_valid(void)
// callers: [mem_buf_msgq_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_create_on_node @ 001030c8 size=1
// signature: undefined kthread_create_on_node(void)
// callers: [mem_buf_msgq_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_create_on_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wake_up_process @ 001030d0 size=1
// signature: undefined wake_up_process(void)
// callers: [mem_buf_msgq_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wake_up_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_msgq_unregister @ 001030d8 size=1
// signature: undefined gh_msgq_unregister(void)
// callers: [mem_buf_msgq_unregister, mem_buf_msgq_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_msgq_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_destroy @ 001030e0 size=1
// signature: undefined idr_destroy(void)
// callers: [mem_buf_msgq_unregister, mem_buf_msgq_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_should_stop @ 001030e8 size=1
// signature: undefined kthread_should_stop(void)
// callers: [mem_buf_msgq_recv_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_should_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 001030f0 size=1
// signature: undefined ___ratelimit(void)
// callers: [mem_buf_msgq_recv_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_msgq_recv @ 001030f8 size=1
// signature: undefined gh_msgq_recv(void)
// callers: [mem_buf_msgq_recv_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_msgq_recv(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_find @ 00103108 size=1
// signature: undefined idr_find(void)
// callers: [mem_buf_msgq_recv_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00103110 size=1
// signature: undefined complete(void)
// callers: [mem_buf_msgq_recv_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103120 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [mem_buf_msgq_recv_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_stop @ 00103128 size=1
// signature: undefined kthread_stop(void)
// callers: [mem_buf_msgq_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00103130 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [mem_buf_msgq_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



