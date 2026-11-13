// Decompiled by Ghidra 12.2
// Program: con_dfpar.ko
// Image base: 00100000

//------------------------------------------------------------
// con_dfpar_suspend_resume_hook @ 001002dc size=104
// signature: undefined con_dfpar_suspend_resume_hook(void)
// callers: []
//------------------------------------------------------------

void con_dfpar_suspend_resume_hook(undefined8 param_1,char *param_2,undefined8 param_3,uint param_4)

{
  int iVar1;
  
  if (((con_dfpar_enable != 0) && (iVar1 = strcmp(param_2,"suspend_enter"), iVar1 == 0)) &&
     ((param_4 & 1) == 0)) {
    _printk(&DAT_00100cbc);
    dump_packet_rx = 1;
  }
  return;
}



//------------------------------------------------------------
// con_dfpar_enable_read @ 00100348 size=156
// signature: undefined con_dfpar_enable_read(void)
// callers: []
//------------------------------------------------------------

void con_dfpar_enable_read
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char acStack_48 [16];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  acStack_48[8] = '\0';
  acStack_48[9] = '\0';
  acStack_48[10] = '\0';
  acStack_48[0xb] = '\0';
  acStack_48[0xc] = '\0';
  acStack_48[0] = '\0';
  acStack_48[1] = '\0';
  acStack_48[2] = '\0';
  acStack_48[3] = '\0';
  acStack_48[4] = '\0';
  acStack_48[5] = '\0';
  acStack_48[6] = '\0';
  acStack_48[7] = '\0';
  iVar2 = snprintf(acStack_48,0xd,"%d\n",(ulong)con_dfpar_enable);
  simple_read_from_buffer(param_2,param_3,param_4,acStack_48,(long)iVar2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// con_dfpar_enable_write @ 001003e8 size=404
// signature: undefined con_dfpar_enable_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong con_dfpar_enable_write(undefined8 param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  ulong uVar7;
  undefined4 local_3c;
  undefined5 local_38;
  undefined3 uStack_33;
  undefined5 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  if (0xb < param_3) {
    param_3 = 0xc;
  }
  local_28 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  local_38 = 0;
  uStack_33 = 0;
  uStack_30 = 0;
  __check_object_size(&local_38,param_3,0);
  puVar6 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
     (uVar7 = param_2, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
    uVar7 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar4 = param_3;
  if (uVar7 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar4 = daif;
        daif = uVar4 | 0xc0;
      }
      puVar6 = (undefined8 *)puVar6[1];
      uVar4 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar6;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
    uVar4 = __arch_copy_from_user(puVar6,&local_38,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
  }
  if (uVar4 == 0) {
    uVar5 = strim(&local_38);
    iVar3 = kstrtouint(uVar5,0,&local_3c);
    if (iVar3 == 0) {
      con_dfpar_enable = local_3c;
    }
    else {
      param_3 = (ulong)iVar3;
    }
  }
  else {
    param_3 = 0xfffffffffffffff2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// con_dfpar_ip4_in_hook @ 00100598 size=180
// signature: undefined con_dfpar_ip4_in_hook(void)
// callers: []
//------------------------------------------------------------

undefined8 con_dfpar_ip4_in_hook(undefined8 param_1,long param_2)

{
  long lVar1;
  
  if (dump_packet_rx == '\x01') {
    _printk(&DAT_00100d6f);
    detect_packet_owner(param_2);
    lVar1 = *(long *)(param_2 + 0xd8) + (ulong)*(ushort *)(param_2 + 0xb8);
    if ((lVar1 != 0) && ((*(char *)(lVar1 + 9) == '\x11' || (*(char *)(lVar1 + 9) == '\x06')))) {
      _printk(&DAT_00100cff,*(undefined1 *)(lVar1 + 0xc),*(undefined1 *)(lVar1 + 0xd),
              *(undefined1 *)(lVar1 + 0xe),*(undefined1 *)(lVar1 + 0xf),
              *(undefined1 *)(lVar1 + 0x10),*(undefined1 *)(lVar1 + 0x11),
              *(undefined1 *)(lVar1 + 0x12),*(undefined1 *)(lVar1 + 0x13));
    }
    dump_packet_rx = '\0';
  }
  return 1;
}



//------------------------------------------------------------
// con_dfpar_ip6_in_hook @ 00100650 size=372
// signature: undefined con_dfpar_ip6_in_hook(void)
// callers: []
//------------------------------------------------------------

undefined8 con_dfpar_ip6_in_hook(undefined8 param_1,long param_2)

{
  long lVar1;
  
  if (dump_packet_rx == '\x01') {
    _printk(&DAT_00100c94);
    detect_packet_owner(param_2);
    lVar1 = *(long *)(param_2 + 0xd8) + (ulong)*(ushort *)(param_2 + 0xb8);
    if ((lVar1 != 0) && ((*(char *)(lVar1 + 6) == '\x11' || (*(char *)(lVar1 + 6) == '\x06')))) {
      _printk(&DAT_00100dc0,*(ushort *)(lVar1 + 8) >> 8 | *(ushort *)(lVar1 + 8) << 8,
              *(ushort *)(lVar1 + 10) >> 8 | *(ushort *)(lVar1 + 10) << 8,
              *(ushort *)(lVar1 + 0xc) >> 8 | *(ushort *)(lVar1 + 0xc) << 8,
              *(ushort *)(lVar1 + 0xe) >> 8 | *(ushort *)(lVar1 + 0xe) << 8,
              *(ushort *)(lVar1 + 0x10) >> 8 | *(ushort *)(lVar1 + 0x10) << 8,
              *(ushort *)(lVar1 + 0x12) >> 8 | *(ushort *)(lVar1 + 0x12) << 8,
              *(ushort *)(lVar1 + 0x14) >> 8 | *(ushort *)(lVar1 + 0x14) << 8,
              *(ushort *)(lVar1 + 0x16) >> 8 | *(ushort *)(lVar1 + 0x16) << 8,
              *(ushort *)(lVar1 + 0x18) >> 8 | *(ushort *)(lVar1 + 0x18) << 8,
              *(ushort *)(lVar1 + 0x1a) >> 8 | *(ushort *)(lVar1 + 0x1a) << 8,
              *(ushort *)(lVar1 + 0x1c) >> 8 | *(ushort *)(lVar1 + 0x1c) << 8,
              *(ushort *)(lVar1 + 0x1e) >> 8 | *(ushort *)(lVar1 + 0x1e) << 8,
              *(ushort *)(lVar1 + 0x20) >> 8 | *(ushort *)(lVar1 + 0x20) << 8,
              *(ushort *)(lVar1 + 0x22) >> 8 | *(ushort *)(lVar1 + 0x22) << 8,
              *(ushort *)(lVar1 + 0x24) >> 8 | *(ushort *)(lVar1 + 0x24) << 8,
              *(ushort *)(lVar1 + 0x26) >> 8 | *(ushort *)(lVar1 + 0x26) << 8);
    }
    dump_packet_rx = '\0';
  }
  return 1;
}



//------------------------------------------------------------
// detect_packet_owner @ 001007c4 size=532
// signature: undefined detect_packet_owner(void)
// callers: [con_dfpar_ip4_in_hook, con_dfpar_ip6_in_hook]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void detect_packet_owner(long param_1)

{
  long *plVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  bool bVar6;
  int *piVar7;
  uint uVar8;
  _STACK *p_Var9;
  _STACK *p_Var10;
  uint uVar11;
  undefined *puVar12;
  long lVar13;
  
  if ((((param_1 != 0) && (p_Var9 = *(_STACK **)(param_1 + 0x18), p_Var9 != (_STACK *)0x0)) &&
      ((*(char *)((long)&p_Var9->sorted + 2) != '\f' ||
       (p_Var9 = *(_STACK **)(p_Var9 + 3), p_Var9 != (_STACK *)0x0)))) &&
     ((1 << (ulong)(*(byte *)((long)&p_Var9->sorted + 2) & 0x1f) & 0xffffefbfU) != 0)) {
    p_Var10 = p_Var9 + 4;
    uVar8 = p_Var10->num;
    if (p_Var10->num == 0) {
      uVar11 = 0;
    }
    else {
      do {
        Hint_Prefetch(p_Var10,2,0,1);
        do {
          uVar3 = p_Var10->num;
          if (uVar3 != uVar8) break;
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(p_Var10,0x10);
          if (bVar6) {
            p_Var10->num = uVar8 + 1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        uVar11 = uVar8;
      } while ((uVar8 != uVar3) && (uVar11 = 0, uVar8 = uVar3, uVar3 != 0));
    }
    if ((int)(uVar11 + 1 | uVar11) < 0) {
      refcount_warn_saturate(p_Var10,0);
    }
    if (uVar11 != 0) {
      iVar2 = p_Var9[0x12].num;
      if (iVar2 != 0) {
        __rcu_read_lock();
        puVar12 = (undefined *)(_DAT_001025f8 + -0x550);
        lVar13 = _DAT_001025f8;
        if (puVar12 != &init_task) {
LAB_001008d4:
          piVar7 = (int *)get_task_cred(puVar12);
          if (piVar7 == (int *)0x0) goto LAB_001008c4;
          if (*(int *)(*(long *)(lVar13 + 0x2e8) + 4) != iVar2) {
            Hint_Prefetch(piVar7,2,0,1);
            do {
              iVar4 = *piVar7;
              cVar5 = '\x01';
              bVar6 = (bool)ExclusiveMonitorPass(piVar7,0x10);
              if (bVar6) {
                *piVar7 = iVar4 + -1;
                cVar5 = ExclusiveMonitorsStatus();
              }
            } while (cVar5 != '\0');
            DataMemoryBarrier(2,3);
            if (iVar4 + -1 == 0) {
              __put_cred(piVar7);
            }
            goto LAB_001008c4;
          }
          _printk(&DAT_00100d97,iVar2,lVar13 + 0x2f8);
          Hint_Prefetch(piVar7,2,0,1);
          do {
            iVar2 = *piVar7;
            cVar5 = '\x01';
            bVar6 = (bool)ExclusiveMonitorPass(piVar7,0x10);
            if (bVar6) {
              *piVar7 = iVar2 + -1;
              cVar5 = ExclusiveMonitorsStatus();
            }
          } while (cVar5 != '\0');
          DataMemoryBarrier(2,3);
          if (iVar2 + -1 == 0) {
            __put_cred(piVar7);
          }
        }
LAB_00100960:
        __rcu_read_unlock();
      }
      Hint_Prefetch(p_Var10,2,0,1);
      do {
        iVar2 = p_Var10->num;
        cVar5 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(p_Var10,0x10);
        if (bVar6) {
          p_Var10->num = iVar2 + -1;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      if (iVar2 == 1) {
        DataMemoryBarrier(2,1);
        sk_free(p_Var9);
      }
      else if (iVar2 < 1) {
        refcount_warn_saturate(p_Var10,3);
      }
    }
  }
  return;
LAB_001008c4:
  plVar1 = (long *)(puVar12 + 0x550);
  puVar12 = (undefined *)(*plVar1 + -0x550);
  lVar13 = *plVar1;
  if (puVar12 == &init_task) goto LAB_00100960;
  goto LAB_001008d4;
}



//------------------------------------------------------------
// init_module @ 00100a44 size=124
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = proc_con_dfpar_init();
  if (iVar1 == 0) {
    iVar1 = nf_register_net_hooks(&init_net,&con_dfpar_hook_ops,2);
    if (iVar1 == 0) {
      tracepoint_probe_register(&__tracepoint_suspend_resume,con_dfpar_suspend_resume_hook,0);
    }
    else {
      _printk(&DAT_00100d29,iVar1);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// proc_con_dfpar_init @ 00100ac0 size=96
// signature: undefined proc_con_dfpar_init(void)
// callers: [init_module]
//------------------------------------------------------------

undefined8 proc_con_dfpar_init(void)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = proc_mkdir("con_dfpar",0);
  if (lVar1 == 0) {
    _printk(&DAT_00100c70);
    uVar2 = 0xfffffffe;
  }
  else {
    proc_create("con_dfpar_enable",0x1b6,lVar1,&con_dfpar_enable_ops);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// cleanup_module @ 00100b24 size=72
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  nf_unregister_net_hooks(&init_net,&con_dfpar_hook_ops,2);
  tracepoint_probe_unregister(&__tracepoint_suspend_resume,con_dfpar_suspend_resume_hook,0);
  return;
}



//------------------------------------------------------------
// nf_register_net_hooks @ 00102008 size=1
// signature: undefined nf_register_net_hooks(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nf_register_net_hooks(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 00102018 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102020 size=1
// signature: undefined _printk(void)
// callers: [detect_packet_owner, con_dfpar_ip4_in_hook, init_module, con_dfpar_ip6_in_hook, proc_con_dfpar_init, con_dfpar_suspend_resume_hook]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nf_unregister_net_hooks @ 00102028 size=1
// signature: undefined nf_unregister_net_hooks(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nf_unregister_net_hooks(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_unregister @ 00102030 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_mkdir @ 00102038 size=1
// signature: undefined proc_mkdir(void)
// callers: [proc_con_dfpar_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_mkdir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_create @ 00102040 size=1
// signature: undefined proc_create(void)
// callers: [proc_con_dfpar_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00102048 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [con_dfpar_suspend_resume_hook]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00102050 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [con_dfpar_enable_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 00102058 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [con_dfpar_enable_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102060 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [con_dfpar_enable_write, con_dfpar_enable_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00102068 size=1
// signature: undefined __check_object_size(void)
// callers: [con_dfpar_enable_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00102080 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [con_dfpar_enable_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strim @ 00102088 size=1
// signature: undefined strim(void)
// callers: [con_dfpar_enable_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strim(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00102090 size=1
// signature: undefined kstrtouint(void)
// callers: [con_dfpar_enable_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_lock @ 001020a0 size=1
// signature: undefined __rcu_read_lock(void)
// callers: [detect_packet_owner]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_task_cred @ 001020b0 size=1
// signature: undefined get_task_cred(void)
// callers: [detect_packet_owner]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_task_cred(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __put_cred @ 001020b8 size=1
// signature: undefined __put_cred(void)
// callers: [detect_packet_owner]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __put_cred(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_unlock @ 001020c0 size=1
// signature: undefined __rcu_read_unlock(void)
// callers: [detect_packet_owner]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sk_free @ 001020c8 size=1
// signature: void sk_free(_STACK * param_1)
// callers: [detect_packet_owner]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void sk_free(_STACK *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 001020d0 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [detect_packet_owner]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



