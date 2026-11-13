// Decompiled by Ghidra 12.2
// Program: cpucp_log.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_cpucp_log @ 001002ac size=100
// signature: undefined __traceiter_cpucp_log(void)
// callers: []
//------------------------------------------------------------

undefined8 __traceiter_cpucp_log(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00101170;
  plVar2 = DAT_00101170;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x5a85e8c8) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1002f0);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_cpucp_log @ 00100314 size=232
// signature: undefined trace_event_raw_event_cpucp_log(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_cpucp_log(long param_1,char *param_2)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
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
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_68,param_1,(long)iVar1 + 0xc);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0xc;
      strcpy((char *)(lVar3 + 0xc),__s);
      trace_event_buffer_commit(&local_68);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_cpucp_log @ 00100400 size=316
// signature: undefined perf_trace_cpucp_log(void)
// callers: []
//------------------------------------------------------------

void perf_trace_cpucp_log(long param_1,char *param_2)

{
  int iVar1;
  long *plVar2;
  char *__s;
  ulong uVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar5 = sp_el0;
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_58 = *(long *)(lVar5 + 0x638);
  local_60 = 0;
  local_64 = 0;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar2 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = ((uint)sVar4 & 0xfffffff8) + 0x14;
    lVar5 = perf_trace_buf_alloc(iVar1,&local_60,&local_64);
    if (lVar5 != 0) {
      *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_60 + 0xf8) = auStack_70;
      *(ulong *)(local_60 + 0x100) = uVar3;
      *(undefined8 *)(local_60 + 0x108) = 5;
      *(uint *)(lVar5 + 8) = (uint)sVar4 * 0x10000 + 0x1000c;
      strcpy((char *)(lVar5 + 0xc),__s);
      perf_trace_run_bpf_submit(lVar5,iVar1,local_64,param_1,1,local_60,plVar2,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_cpucp_log @ 00100540 size=28
// signature: undefined __bpf_trace_cpucp_log(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_cpucp_log(void)

{
  bpf_trace_run1();
  return;
}



//------------------------------------------------------------
// trace_raw_output_cpucp_log @ 00100560 size=104
// signature: undefined trace_raw_output_cpucp_log(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_cpucp_log(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,&DAT_001014ae,lVar2 + (ulong)*(ushort *)(lVar2 + 8));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// cpucp_log_probe @ 001005cc size=936
// signature: undefined cpucp_log_probe(void)
// callers: []
//------------------------------------------------------------

ulong cpucp_log_probe(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined **ppuVar4;
  uint uVar5;
  undefined **ppuVar6;
  long *plVar7;
  long lVar8;
  long *plVar9;
  ulong uVar10;
  undefined *puVar11;
  undefined **ppuVar12;
  ulong uVar13;
  char *pcVar14;
  uint uVar15;
  int iVar16;
  long lVar17;
  
  lVar2 = param_1 + 0x10;
  plVar7 = (long *)devm_kmalloc(lVar2,0x110,0xdc0);
  if (plVar7 != (long *)0x0) {
    uVar15 = *(uint *)(param_1 + 0x3b8);
    plVar7[0x1a] = lVar2;
    lVar8 = __kmalloc((ulong)uVar15 << 4,0xdc0);
    if (lVar8 != 0) {
      iVar16 = *(int *)(param_1 + 0x3b8);
      *plVar7 = lVar8;
      if (iVar16 != 0) {
        uVar15 = 0;
        iVar16 = 0;
        do {
          lVar17 = *plVar7;
          plVar9 = (long *)platform_get_resource(param_1,0x200,uVar15);
          if (plVar9 == (long *)0x0) {
            _dev_err(lVar2,"Failed to get the device base address\n");
            uVar10 = 0xffffffed;
            goto LAB_001008f0;
          }
          uVar10 = devm_ioremap(lVar2,*plVar9,(plVar9[1] - *plVar9) + 1);
          if (0xfffffffffffff000 < uVar10) {
            pcVar14 = "Failed to io remap the region err: %d\n";
            goto LAB_00100964;
          }
          *(ulong *)(lVar17 + (long)(int)uVar15 * 0x10) = uVar10;
          lVar3 = (plVar9[1] - *plVar9) + 1;
          *(long *)(lVar17 + (long)(int)uVar15 * 0x10 + 8) = lVar3;
          if ((iVar16 != 0) && (lVar3 != iVar16)) {
            uVar10 = 0xffffffea;
            goto LAB_001008f0;
          }
          uVar5 = *(uint *)(param_1 + 0x3b8);
          uVar15 = uVar15 + 1;
          iVar1 = (int)lVar3;
          if (iVar16 != 0) {
            iVar1 = iVar16;
          }
          *(int *)((long)plVar7 + 0xe4) = *(int *)((long)plVar7 + 0xe4) + 1;
          *(int *)(plVar7 + 0x1d) = (int)plVar7[0x1d] + (int)lVar3;
          iVar16 = iVar1;
        } while (uVar15 < uVar5);
      }
      puVar11 = (undefined *)devm_kmalloc(lVar2,*(long *)(lVar8 + 8) * 4 + 0x1000,0xdc0);
      plVar7[0x1f] = (long)puVar11;
      if (puVar11 == (undefined *)0x0) {
LAB_001008ec:
        uVar10 = 0xfffffff4;
      }
      else {
        lVar17 = devm_kmalloc(lVar2,0x400,0xdc0);
        plVar7[0x1e] = lVar17;
        if (lVar17 == 0) goto LAB_001008ec;
        iVar16 = *(int *)(lVar8 + 8);
        ppuVar12 = (undefined **)devm_kmalloc(plVar7[0x1a],0x80,0xdc0);
        ppuVar4 = DAT_00101128;
        if (ppuVar12 == (undefined **)0x0) goto LAB_001008ec;
        iVar1 = iVar16 + 0x400;
        ppuVar12[2] = puVar11;
        *(int *)(ppuVar12 + 3) = iVar16;
        *(undefined4 *)((long)ppuVar12 + 0x1c) = 0x400;
        uVar10 = __list_add_valid(ppuVar12,ppuVar4,&free_buffers_list);
        if ((uVar10 & 1) != 0) {
          DAT_00101128 = ppuVar12;
          *ppuVar12 = (undefined *)&free_buffers_list;
          ppuVar12[1] = (undefined *)ppuVar4;
          *ppuVar4 = (undefined *)ppuVar12;
          puVar11 = (undefined *)plVar7[0x1f];
        }
        ppuVar6 = DAT_00101128;
        ppuVar4 = ppuVar12 + 4;
        ppuVar12[6] = puVar11 + iVar1;
        *(int *)(ppuVar12 + 7) = iVar16;
        *(undefined4 *)((long)ppuVar12 + 0x3c) = 0x400;
        uVar10 = __list_add_valid(ppuVar4,ppuVar6,&free_buffers_list);
        if ((uVar10 & 1) != 0) {
          DAT_00101128 = ppuVar4;
          ppuVar12[4] = (undefined *)&free_buffers_list;
          ppuVar12[5] = (undefined *)ppuVar6;
          *ppuVar6 = (undefined *)ppuVar4;
          puVar11 = (undefined *)plVar7[0x1f];
        }
        ppuVar6 = DAT_00101128;
        ppuVar4 = ppuVar12 + 8;
        *(int *)(ppuVar12 + 0xb) = iVar16;
        *(undefined4 *)((long)ppuVar12 + 0x5c) = 0x400;
        ppuVar12[10] = puVar11 + iVar1 * 2;
        uVar10 = __list_add_valid(ppuVar4,ppuVar6,&free_buffers_list);
        if ((uVar10 & 1) != 0) {
          DAT_00101128 = ppuVar4;
          ppuVar12[8] = (undefined *)&free_buffers_list;
          ppuVar12[9] = (undefined *)ppuVar6;
          *ppuVar6 = (undefined *)ppuVar4;
          puVar11 = (undefined *)plVar7[0x1f];
        }
        ppuVar6 = DAT_00101128;
        ppuVar4 = ppuVar12 + 0xc;
        ppuVar12[0xe] = puVar11 + iVar1 * 3;
        *(int *)(ppuVar12 + 0xf) = iVar16;
        *(undefined4 *)((long)ppuVar12 + 0x7c) = 0x400;
        uVar10 = __list_add_valid(ppuVar4,ppuVar6,&free_buffers_list);
        if ((uVar10 & 1) != 0) {
          DAT_00101128 = ppuVar4;
          ppuVar12[0xc] = (undefined *)&free_buffers_list;
          ppuVar12[0xd] = (undefined *)ppuVar6;
          *ppuVar6 = (undefined *)ppuVar4;
        }
        *(undefined1 *)(plVar7 + 4) = 1;
        plVar7[5] = (long)cpucp_log_rx;
        plVar7[9] = 0xfffffffe0;
        *(long **)(param_1 + 0xa8) = plVar7;
        plVar7[1] = lVar2;
        *(undefined1 *)(plVar7 + 2) = 0;
        plVar7[10] = (long)(plVar7 + 10);
        plVar7[0xb] = (long)(plVar7 + 10);
        plVar7[0xc] = (long)cpucp_log_work;
        init_timer_key(plVar7 + 0xf,&delayed_work_timer_fn,0x280000,0,0);
        *(undefined8 *)((long)plVar7 + 0x104) = 0;
        cpucp_wq = alloc_workqueue(&DAT_0010145d,0x4000e,1,"cpucp_wq");
        uVar13 = mbox_request_channel(plVar7 + 1,0);
        uVar10 = 0;
        plVar7[8] = uVar13;
        if (uVar13 < 0xfffffffffffff001) goto LAB_00100910;
        if ((int)uVar13 == -0x205) {
          uVar10 = 0xfffffdfb;
        }
        else {
          uVar10 = uVar13 & 0xffffffff;
          pcVar14 = "Failed to request mbox info: %d\n";
LAB_00100964:
          _dev_err(lVar2,pcVar14,uVar10 & 0xffffffff);
        }
      }
LAB_001008f0:
      kfree(*plVar7);
      full_buffers_list = (undefined *)&full_buffers_list;
      PTR_full_buffers_list_00101118 = (undefined *)&full_buffers_list;
      free_buffers_list = (undefined *)&free_buffers_list;
      DAT_00101128 = &free_buffers_list;
      goto LAB_00100910;
    }
  }
  uVar10 = 0xfffffff4;
LAB_00100910:
  return uVar10 & 0xffffffff;
}



//------------------------------------------------------------
// cpucp_log_remove @ 00100978 size=40
// signature: undefined cpucp_log_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 cpucp_log_remove(long param_1)

{
  mbox_free_channel(*(undefined8 *)(*(long *)(param_1 + 0xa8) + 0x40));
  return 0;
}



//------------------------------------------------------------
// cpucp_log_rx @ 001009a4 size=424
// signature: undefined cpucp_log_rx(void)
// callers: []
//------------------------------------------------------------

void cpucp_log_rx(long *param_1)

{
  long *plVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  ulong uVar5;
  undefined8 *puVar6;
  long lVar7;
  long lVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  
  puVar9 = *(undefined8 **)(*param_1 + 0x98);
  lVar7 = (long)puVar9 + 0x104;
  uVar10 = puVar9[0x1a];
  uVar4 = _raw_spin_lock_irqsave(lVar7);
  puVar3 = free_buffers_list;
  if ((undefined **)free_buffers_list == &free_buffers_list) {
    _raw_spin_unlock_irqrestore(lVar7,uVar4);
  }
  else {
    uVar5 = __list_del_entry_valid(free_buffers_list);
    if ((uVar5 & 1) != 0) {
      lVar8 = *(long *)puVar3;
      plVar1 = *(long **)(puVar3 + 8);
      *(long **)(lVar8 + 8) = plVar1;
      *plVar1 = lVar8;
    }
    *(undefined8 *)puVar3 = 0xdead000000000100;
    *(undefined8 *)(puVar3 + 8) = 0xdead000000000122;
    _raw_spin_unlock_irqrestore(lVar7,uVar4);
    if (puVar3 != (undefined *)0x0) {
      puVar6 = (undefined8 *)*puVar9;
      uVar5 = (ulong)*(uint *)*puVar6;
      if ((ulong)puVar6[1] < uVar5) {
        if (*(uint *)(puVar9 + 0x1d) < *(uint *)*puVar6) {
          _printk(&DAT_001014b3,"cpucp_log_rx");
          return;
        }
        lVar8 = 1;
        lVar7 = 0;
        *(undefined4 *)(puVar9 + 0x1c) = 1;
        uVar5 = uVar5 - puVar6[1];
      }
      else {
        lVar8 = 0;
        lVar7 = 4;
        *(undefined4 *)(puVar9 + 0x1c) = 0;
      }
      __memcpy_fromio(*(long *)(puVar3 + 0x10) + (ulong)*(uint *)(puVar3 + 0x1c),
                      puVar6[lVar8 * 2] + lVar7,uVar5 - lVar7);
      *(int *)(puVar3 + 0x18) = (int)(uVar5 - lVar7);
      uVar4 = _raw_spin_lock_irqsave(puVar9 + 0x21);
      puVar2 = PTR_full_buffers_list_00101118;
      uVar5 = __list_add_valid(puVar3,PTR_full_buffers_list_00101118,&full_buffers_list);
      if ((uVar5 & 1) != 0) {
        PTR_full_buffers_list_00101118 = puVar3;
        *(undefined ***)puVar3 = &full_buffers_list;
        *(undefined **)(puVar3 + 8) = puVar2;
        *(undefined **)puVar2 = puVar3;
      }
      _raw_spin_unlock_irqrestore(puVar9 + 0x21,uVar4);
      if ((puVar9[9] & 1) == 0) {
        queue_delayed_work_on(0x20,cpucp_wq,puVar9 + 9,0);
        return;
      }
      return;
    }
  }
  _dev_err(uVar10,"global buffer full dropping buffers\n");
  return;
}



//------------------------------------------------------------
// cpucp_log_work @ 00100b50 size=568
// signature: undefined cpucp_log_work(void)
// callers: []
//------------------------------------------------------------

void cpucp_log_work(long param_1)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined *puVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  ulong uVar9;
  void *__src;
  int iVar10;
  uint uVar11;
  long lVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  char acStack_474 [1028];
  long local_70;
  
  lVar1 = sp_el0;
  local_70 = *(long *)(lVar1 + 0x638);
  memset(acStack_474,0,0x401);
  lVar1 = param_1 + 0xc0;
  uVar8 = _raw_spin_lock_irqsave(lVar1);
  if ((undefined **)full_buffers_list != &full_buffers_list) {
    uVar5 = sp_el0;
    do {
      puVar6 = full_buffers_list;
      uVar9 = __list_del_entry_valid(full_buffers_list);
      if ((uVar9 & 1) != 0) {
        lVar12 = *(long *)puVar6;
        plVar2 = *(long **)(puVar6 + 8);
        *(long **)(lVar12 + 8) = plVar2;
        *plVar2 = lVar12;
      }
      *(undefined8 *)puVar6 = 0xdead000000000100;
      *(undefined8 *)(puVar6 + 8) = 0xdead000000000122;
      _raw_spin_unlock_irqrestore(lVar1,uVar8);
      iVar10 = *(int *)(puVar6 + 0x18);
      iVar3 = *(int *)(param_1 + 0xb8);
      lVar12 = *(long *)(puVar6 + 0x10);
      iVar14 = *(int *)(puVar6 + 0x1c) - iVar3;
      if (iVar3 != 0) {
        memcpy((void *)(*(long *)(puVar6 + 0x10) + (long)iVar14),*(void **)(param_1 + 0xa8),
               (long)iVar3);
        *(undefined4 *)(param_1 + 0xb8) = 0;
      }
      __src = (void *)(lVar12 + iVar14);
      uVar13 = iVar10 + iVar3;
      do {
        iVar10 = -1;
        uVar15 = uVar13;
        if (0x3ff < (int)uVar13) {
          uVar15 = 0x400;
        }
        uVar4 = uVar15;
        do {
          uVar11 = uVar4;
          uVar4 = uVar11 - 1;
          if ((int)uVar4 < 0) {
            if (0x3ff < (int)uVar13) goto LAB_00100c7c;
            *(uint *)(param_1 + 0xb8) = uVar13;
            memcpy(*(void **)(param_1 + 0xa8),__src,(long)(int)uVar13);
            goto LAB_00100e20;
          }
          iVar10 = iVar10 + -1;
        } while (*(char *)((long)__src + (ulong)uVar4) != '\n');
        *(undefined1 *)((long)__src + (ulong)uVar4) = 0;
        if (iVar10 == -2) {
LAB_00100c7c:
          snprintf(acStack_474,(long)(int)(uVar15 + 1),"%s");
        }
        else {
          uVar15 = uVar11;
        }
        iVar14 = uVar15 + iVar14;
        uVar13 = uVar13 - uVar15;
        __src = (void *)(*(long *)(puVar6 + 0x10) + (long)iVar14);
      } while (0 < (int)uVar13);
LAB_00100e20:
      uVar8 = _raw_spin_lock_irqsave(param_1 + 0xbc);
      puVar7 = DAT_00101128;
      uVar9 = __list_add_valid(puVar6,DAT_00101128);
      if ((uVar9 & 1) != 0) {
        DAT_00101128 = (undefined8 *)puVar6;
        *(undefined ***)puVar6 = &free_buffers_list;
        *(undefined8 **)(puVar6 + 8) = puVar7;
        *puVar7 = puVar6;
      }
      _raw_spin_unlock_irqrestore(param_1 + 0xbc,uVar8);
      uVar8 = _raw_spin_lock_irqsave(lVar1);
    } while ((undefined **)full_buffers_list != &full_buffers_list);
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar8);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00100ebc size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&cpucp_log_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// strlen @ 00103000 size=1
// signature: size_t strlen(char * __s)
// callers: [trace_event_raw_event_cpucp_log, perf_trace_cpucp_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 00103008 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_cpucp_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 00103010 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [trace_event_raw_event_cpucp_log, perf_trace_cpucp_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 00103018 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_cpucp_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 00103020 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_cpucp_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [trace_event_raw_event_cpucp_log, cpucp_log_work, perf_trace_cpucp_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 00103030 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_cpucp_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 00103038 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_cpucp_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run1 @ 00103040 size=1
// signature: undefined bpf_trace_run1(void)
// callers: [__bpf_trace_cpucp_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00103048 size=1
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
// trace_raw_output_prep @ 00103050 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_cpucp_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 00103058 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_cpucp_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 00103060 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_cpucp_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103068 size=1
// signature: undefined devm_kmalloc(void)
// callers: [cpucp_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00103070 size=1
// signature: undefined __kmalloc(void)
// callers: [cpucp_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource @ 00103078 size=1
// signature: undefined platform_get_resource(void)
// callers: [cpucp_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00103080 size=1
// signature: undefined devm_ioremap(void)
// callers: [cpucp_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00103088 size=1
// signature: undefined __list_add_valid(void)
// callers: [cpucp_log_work, cpucp_log_rx, cpucp_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00103098 size=1
// signature: undefined init_timer_key(void)
// callers: [cpucp_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 001030a0 size=1
// signature: undefined alloc_workqueue(void)
// callers: [cpucp_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_request_channel @ 001030a8 size=1
// signature: undefined mbox_request_channel(void)
// callers: [cpucp_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_request_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001030b0 size=1
// signature: undefined kfree(void)
// callers: [cpucp_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001030b8 size=1
// signature: undefined _dev_err(void)
// callers: [cpucp_log_rx, cpucp_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_free_channel @ 001030c0 size=1
// signature: undefined mbox_free_channel(void)
// callers: [cpucp_log_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_free_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 001030c8 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [cpucp_log_work, cpucp_log_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001030d0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [cpucp_log_work, cpucp_log_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001030d8 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [cpucp_log_work, cpucp_log_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_fromio @ 001030e0 size=1
// signature: undefined __memcpy_fromio(void)
// callers: [cpucp_log_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_fromio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 001030e8 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [cpucp_log_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001030f0 size=1
// signature: undefined _printk(void)
// callers: [cpucp_log_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001030f8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [cpucp_log_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00103100 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [cpucp_log_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00103108 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [cpucp_log_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



