// Decompiled by Ghidra 12.2
// Program: rmnet_ctl.ko
// Image base: 00100000

//------------------------------------------------------------
// rmnet_ctl_ipa_ready @ 00100354 size=112
// signature: undefined rmnet_ctl_ipa_ready(void)
// callers: [init_module]
//------------------------------------------------------------

void rmnet_ctl_ipa_ready(void)

{
  int iVar1;
  
  iVar1 = ipa_register_rmnet_ctl_cb
                    (rmnet_ctl_probe,&ctl_ipa_dev,rmnet_ctl_remove,&ctl_ipa_dev,
                     rmnet_ctl_dl_callback,&ctl_ipa_dev);
  if (iVar1 == 0) {
    rmnet_ctl_ipa_registered = 1;
  }
  else {
    _printk(&DAT_00100cf3,"rmnet_ctl_ipa_ready",iVar1);
  }
  return;
}



//------------------------------------------------------------
// rmnet_ctl_probe @ 001003c8 size=72
// signature: undefined rmnet_ctl_probe(void)
// callers: []
//------------------------------------------------------------

void rmnet_ctl_probe(void)

{
  DAT_00100d98 = 0;
  DAT_00100da0 = 0;
  DAT_00100d88 = 0;
  DAT_00100d90 = 0;
  DAT_00100d78 = 0;
  DAT_00100d80 = 0;
  ctl_ipa_dev = rmnet_ctl_send_ipa;
  rmnet_ctl_endpoint_setdev();
  _printk(&DAT_00100d00);
  return;
}



//------------------------------------------------------------
// rmnet_ctl_remove @ 00100414 size=44
// signature: undefined rmnet_ctl_remove(void)
// callers: []
//------------------------------------------------------------

void rmnet_ctl_remove(void)

{
  rmnet_ctl_endpoint_setdev(0);
  _printk(&DAT_00100d1f);
  return;
}



//------------------------------------------------------------
// rmnet_ctl_dl_callback @ 00100444 size=48
// signature: undefined rmnet_ctl_dl_callback(void)
// callers: []
//------------------------------------------------------------

void rmnet_ctl_dl_callback(long param_1,undefined8 param_2)

{
  *(long *)(param_1 + 8) = *(long *)(param_1 + 8) + 1;
  rmnet_ctl_endpoint_post(param_2,0xffffffff);
  return;
}



//------------------------------------------------------------
// rmnet_ctl_send_ipa @ 00100478 size=112
// signature: undefined rmnet_ctl_send_ipa(void)
// callers: []
//------------------------------------------------------------

int rmnet_ctl_send_ipa(long param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  
  _raw_spin_lock_bh(param_1 + 0x34);
  iVar2 = ipa_rmnet_ctl_xmit(param_2);
  lVar1 = 0x18;
  if (iVar2 != 0) {
    lVar1 = 0x20;
  }
  *(long *)(param_1 + lVar1) = *(long *)(param_1 + lVar1) + 1;
  _raw_spin_unlock_bh(param_1 + 0x34);
  return iVar2;
}



//------------------------------------------------------------
// rmnet_ctl_set_dbgfs @ 001004ec size=188
// signature: undefined rmnet_ctl_set_dbgfs(void)
// callers: []
//------------------------------------------------------------

void rmnet_ctl_set_dbgfs(ulong param_1)

{
  if ((param_1 & 1) == 0) {
    debugfs_remove(DAT_00100dc0);
    ipc_log_context_destroy(DAT_00100dd0);
    DAT_00100dc0 = 0;
    DAT_00100dc8 = 0;
    DAT_00100dd0 = 0;
  }
  else {
    if ((DAT_00100dc0 == 0) || (0xfffffffffffff000 < DAT_00100dc0)) {
      DAT_00100dc0 = debugfs_create_dir("rmnet_ctl",0);
    }
    if ((DAT_00100dc0 != 0) && (DAT_00100dc0 < 0xfffffffffffff001)) {
      debugfs_create_u8("ipc_log_lvl",0x1a4,DAT_00100dc0,&ipc_log_lvl);
    }
    if (DAT_00100dd0 == 0) {
      DAT_00100dd0 = ipc_log_context_create(10,"rmnet_ctl",0);
    }
  }
  return;
}



//------------------------------------------------------------
// rmnet_ctl_endpoint_setdev @ 001005ac size=16
// signature: undefined rmnet_ctl_endpoint_setdev(void)
// callers: [rmnet_ctl_probe, rmnet_ctl_remove]
//------------------------------------------------------------

void rmnet_ctl_endpoint_setdev(undefined8 param_1)

{
  ctl_ep = param_1;
  return;
}



//------------------------------------------------------------
// rmnet_ctl_endpoint_post @ 001005c0 size=452
// signature: undefined rmnet_ctl_endpoint_post(void)
// callers: [rmnet_ctl_dl_callback]
//------------------------------------------------------------

void rmnet_ctl_endpoint_post(void *param_1,ulong param_2)

{
  long *plVar1;
  void *pvVar2;
  void *__dest;
  uint uVar3;
  code *pcVar4;
  
  if (param_1 == (void *)0x0) {
    return;
  }
  if (param_2 == 0) {
    return;
  }
  if (param_2 == 0xffffffff) {
    if ((1 < ipc_log_lvl) && (DAT_00100dd0 != 0)) {
      if ((*(long *)((long)param_1 + 0xe0) == 0) ||
         (uVar3 = *(uint *)((long)param_1 + 0x70), uVar3 == 0)) {
        ipc_log_string(DAT_00100dd0,"%3s(%d): (null)\n",&DAT_00100cdf,0);
      }
      else {
        if (0x1f < uVar3) {
          uVar3 = 0x20;
        }
        ipc_log_string(DAT_00100dd0,"%3s(%d): %*ph\n",&DAT_00100cdf,0,uVar3);
      }
    }
    __rcu_read_lock();
    plVar1 = DAT_00100db8;
    if ((DAT_00100db8 == (long *)0x0) || (*DAT_00100db8 == 0)) {
      kfree(param_1);
      goto LAB_0010076c;
    }
    *(undefined2 *)((long)param_1 + 0xb4) = 0xf900;
    pcVar4 = (code *)*plVar1;
    pvVar2 = param_1;
  }
  else {
    uVar3 = (uint)param_2;
    if ((1 < ipc_log_lvl) && (DAT_00100dd0 != 0)) {
      if (uVar3 == 0) {
        ipc_log_string(DAT_00100dd0,"%3s(%d): (null)\n",&DAT_00100cdf,0);
      }
      else {
        if (0x1f < uVar3) {
          uVar3 = 0x20;
        }
        ipc_log_string(DAT_00100dd0,"%3s(%d): %*ph\n",&DAT_00100cdf,0,uVar3,param_1);
      }
    }
    __rcu_read_lock();
    plVar1 = DAT_00100db8;
    if (((DAT_00100db8 == (long *)0x0) || (*DAT_00100db8 == 0)) ||
       (pvVar2 = (void *)__alloc_skb(param_2 & 0xffffffff,0xa20,0,0xffffffff), pvVar2 == (void *)0x0
       )) goto LAB_0010076c;
    __dest = (void *)skb_put(pvVar2,param_2 & 0xffffffff);
    memcpy(__dest,param_1,param_2 & 0xffffffff);
    *(undefined2 *)((long)pvVar2 + 0xb4) = 0xf900;
    pcVar4 = (code *)*plVar1;
  }
  if (*(int *)(pcVar4 + -4) != 0x50ad483a) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x100768);
    (*pcVar4)();
  }
  (*pcVar4)(pvVar2);
LAB_0010076c:
  __rcu_read_unlock();
  return;
}



//------------------------------------------------------------
// rmnet_ctl_log @ 00100788 size=116
// signature: undefined rmnet_ctl_log(void)
// callers: []
//------------------------------------------------------------

void rmnet_ctl_log(uint param_1,undefined8 param_2,undefined4 param_3,long param_4,uint param_5)

{
  if (param_1 <= ipc_log_lvl && DAT_00100dd0 != 0) {
    if ((param_4 == 0) || (param_5 == 0)) {
      ipc_log_string(DAT_00100dd0,"%3s(%d): (null)\n",param_2,param_3);
    }
    else {
      if (0x1f < param_5) {
        param_5 = 0x20;
      }
      ipc_log_string(DAT_00100dd0,"%3s(%d): %*ph\n",param_2,param_3,param_5);
    }
  }
  return;
}



//------------------------------------------------------------
// rmnet_ctl_register_client @ 00100800 size=272
// signature: undefined rmnet_ctl_register_client(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * rmnet_ctl_register_client(undefined8 *param_1)

{
  undefined8 *puVar1;
  
  if (param_1 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)kmalloc_trace(_DAT_001020c8,0xdc0,8);
    if (puVar1 == (undefined8 *)0x0) {
      return (undefined8 *)0x0;
    }
    *puVar1 = *param_1;
    _raw_spin_lock(&client_lock);
    if (DAT_00100db8 == (undefined8 *)0x0) {
      DAT_00100db8 = puVar1;
      _raw_spin_unlock(&client_lock);
      if ((DAT_00100dc0 == 0) || (0xfffffffffffff000 < DAT_00100dc0)) {
        DAT_00100dc0 = debugfs_create_dir("rmnet_ctl",0);
      }
      if ((DAT_00100dc0 != 0) && (DAT_00100dc0 < 0xfffffffffffff001)) {
        debugfs_create_u8("ipc_log_lvl",0x1a4,DAT_00100dc0,&ipc_log_lvl);
      }
      if (DAT_00100dd0 == 0) {
        DAT_00100dd0 = ipc_log_context_create(10,"rmnet_ctl",0);
        return puVar1;
      }
      return puVar1;
    }
    _raw_spin_unlock(&client_lock);
    kfree(puVar1);
  }
  return (undefined8 *)0x0;
}



//------------------------------------------------------------
// rmnet_ctl_unregister_client @ 00100914 size=148
// signature: undefined rmnet_ctl_unregister_client(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_ctl_unregister_client(long param_1)

{
  undefined8 uVar1;
  
  _raw_spin_lock(&client_lock);
  if (DAT_00100db8 == param_1) {
    DAT_00100db8 = 0;
    _raw_spin_unlock(&client_lock);
    synchronize_rcu();
    kfree(param_1);
    debugfs_remove(DAT_00100dc0);
    ipc_log_context_destroy(DAT_00100dd0);
    uVar1 = 0;
    DAT_00100dc0 = 0;
    DAT_00100dc8 = 0;
    DAT_00100dd0 = 0;
  }
  else {
    _raw_spin_unlock(&client_lock);
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// rmnet_ctl_send_client @ 001009ac size=324
// signature: undefined rmnet_ctl_send_client(void)
// callers: []
//------------------------------------------------------------

int rmnet_ctl_send_client(long param_1,long param_2)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  
  if (DAT_00100db8 == param_1) {
    if ((1 < ipc_log_lvl) && (DAT_00100dd0 != 0)) {
      if ((*(long *)(param_2 + 0xe0) == 0) || (uVar3 = *(uint *)(param_2 + 0x70), uVar3 == 0)) {
        ipc_log_string(DAT_00100dd0,"%3s(%d): (null)\n",&DAT_00100cfd,0);
      }
      else {
        if (0x1f < uVar3) {
          uVar3 = 0x20;
        }
        ipc_log_string(DAT_00100dd0,"%3s(%d): %*ph\n",&DAT_00100cfd,0,uVar3);
      }
    }
    __rcu_read_lock();
    if ((ctl_ep == (undefined8 *)0x0) || (pcVar2 = (code *)*ctl_ep, pcVar2 == (code *)0x0)) {
      kfree_skb_reason(param_2,1);
      __rcu_read_unlock();
      iVar1 = -0x16;
    }
    else {
      if (*(int *)(pcVar2 + -4) != 0x64dd56d4) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100a88);
        (*pcVar2)();
      }
      iVar1 = (*pcVar2)(ctl_ep,param_2);
      __rcu_read_unlock();
      if (iVar1 == 0) {
        return 0;
      }
    }
    if ((ipc_log_lvl != 0) && (DAT_00100dd0 != 0)) {
      ipc_log_string(DAT_00100dd0,"%3s(%d): (null)\n",&DAT_00100d1b,iVar1);
    }
  }
  else {
    kfree_skb_reason(param_2,1);
    iVar1 = -0x16;
  }
  return iVar1;
}



//------------------------------------------------------------
// rmnet_ctl_if @ 00100af4 size=12
// signature: undefined rmnet_ctl_if(void)
// callers: []
//------------------------------------------------------------

undefined ** rmnet_ctl_if(void)

{
  return &client_if;
}



//------------------------------------------------------------
// rmnet_ctl_get_stats @ 00100b04 size=100
// signature: undefined rmnet_ctl_get_stats(void)
// callers: []
//------------------------------------------------------------

ulong rmnet_ctl_get_stats(void *param_1,ulong param_2)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = param_2 & 0xffffffff;
  __rcu_read_lock();
  uVar1 = (uint)param_2;
  if ((0 < (int)uVar1) && (ctl_ep != 0)) {
    if (4 < (int)uVar1) {
      uVar1 = 5;
    }
    uVar2 = (ulong)uVar1;
    memcpy(param_1,(void *)(ctl_ep + 8),uVar2 << 3);
  }
  __rcu_read_unlock();
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 00100b6c size=88
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  int iVar1;
  
  iVar1 = ipa_register_ipa_ready_cb(rmnet_ctl_ipa_ready,0);
  if (iVar1 != 0) {
    if (iVar1 == -0x11) {
      rmnet_ctl_ipa_ready();
    }
    else {
      _printk(&DAT_00100cf3,"rmnet_ctl_init",iVar1);
    }
  }
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 00100bc8 size=56
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  if (rmnet_ctl_ipa_registered == '\x01') {
    ipa_unregister_rmnet_ctl_cb();
    rmnet_ctl_ipa_registered = '\0';
  }
  return;
}



//------------------------------------------------------------
// ipa_register_ipa_ready_cb @ 00102000 size=1
// signature: undefined ipa_register_ipa_ready_cb(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipa_register_ipa_ready_cb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102008 size=1
// signature: undefined _printk(void)
// callers: [rmnet_ctl_probe, rmnet_ctl_remove, rmnet_ctl_ipa_ready, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipa_unregister_rmnet_ctl_cb @ 00102010 size=1
// signature: undefined ipa_unregister_rmnet_ctl_cb(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipa_unregister_rmnet_ctl_cb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipa_register_rmnet_ctl_cb @ 00102018 size=1
// signature: undefined ipa_register_rmnet_ctl_cb(void)
// callers: [rmnet_ctl_ipa_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipa_register_rmnet_ctl_cb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_bh @ 00102020 size=1
// signature: undefined _raw_spin_lock_bh(void)
// callers: [rmnet_ctl_send_ipa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipa_rmnet_ctl_xmit @ 00102028 size=1
// signature: undefined ipa_rmnet_ctl_xmit(void)
// callers: [rmnet_ctl_send_ipa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipa_rmnet_ctl_xmit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_bh @ 00102030 size=1
// signature: undefined _raw_spin_unlock_bh(void)
// callers: [rmnet_ctl_send_ipa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00102038 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [rmnet_ctl_set_dbgfs, rmnet_ctl_register_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_u8 @ 00102040 size=1
// signature: undefined debugfs_create_u8(void)
// callers: [rmnet_ctl_set_dbgfs, rmnet_ctl_register_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_u8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00102048 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [rmnet_ctl_set_dbgfs, rmnet_ctl_register_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00102050 size=1
// signature: undefined debugfs_remove(void)
// callers: [rmnet_ctl_unregister_client, rmnet_ctl_set_dbgfs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 00102058 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [rmnet_ctl_unregister_client, rmnet_ctl_set_dbgfs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00102060 size=1
// signature: undefined ipc_log_string(void)
// callers: [rmnet_ctl_send_client, rmnet_ctl_log, rmnet_ctl_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_lock @ 00102068 size=1
// signature: undefined __rcu_read_lock(void)
// callers: [rmnet_ctl_get_stats, rmnet_ctl_send_client, rmnet_ctl_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102070 size=1
// signature: undefined kfree(void)
// callers: [rmnet_ctl_unregister_client, rmnet_ctl_endpoint_post, rmnet_ctl_register_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_skb @ 00102078 size=1
// signature: undefined __alloc_skb(void)
// callers: [rmnet_ctl_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_put @ 00102080 size=1
// signature: undefined skb_put(void)
// callers: [rmnet_ctl_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00102088 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [rmnet_ctl_get_stats, rmnet_ctl_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_unlock @ 00102090 size=1
// signature: undefined __rcu_read_unlock(void)
// callers: [rmnet_ctl_get_stats, rmnet_ctl_send_client, rmnet_ctl_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001020a0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [rmnet_ctl_register_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 001020a8 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [rmnet_ctl_unregister_client, rmnet_ctl_register_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 001020b0 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [rmnet_ctl_unregister_client, rmnet_ctl_register_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// synchronize_rcu @ 001020b8 size=1
// signature: undefined synchronize_rcu(void)
// callers: [rmnet_ctl_unregister_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void synchronize_rcu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_skb_reason @ 001020c0 size=1
// signature: undefined kfree_skb_reason(void)
// callers: [rmnet_ctl_send_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_skb_reason(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



