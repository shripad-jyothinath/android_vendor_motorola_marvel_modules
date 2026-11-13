// Decompiled by Ghidra 12.2
// Program: stm_heartbeat.ko
// Image base: 00100000

//------------------------------------------------------------
// init_module @ 00100134 size=408
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  
  if (nr_devs < 0x21) {
    if (nr_devs != 0) {
      lVar6 = 0;
      uVar5 = 0;
      do {
        lVar3 = kasprintf(0xcc0,"heartbeat.%d",uVar5 & 0xffffffff);
        if (lVar6 == 0xf00) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x100264);
          (*pcVar1)();
        }
        *(long *)((long)&stm_heartbeat + lVar6) = lVar3;
        if (lVar3 == 0) {
          iVar2 = -0xc;
          goto LAB_00100288;
        }
        if (((lVar6 - 0xeedU < 0xfffffffffffff0ff) ||
            (*(undefined4 *)((long)&DAT_0010066c + lVar6) = 1, lVar6 - 0xee8U < 0xfffffffffffff100))
           || (*(code **)((long)&DAT_00100670 + lVar6) = stm_heartbeat_link,
              lVar6 - 0xee0U < 0xfffffffffffff100)) goto LAB_001002c8;
        *(code **)((long)&DAT_00100678 + lVar6) = stm_heartbeat_unlink;
        hrtimer_init(&DAT_00100680 + lVar6,1,0);
        if (lVar6 - 0xeb0U < 0xfffffffffffff100) goto LAB_001002c8;
        *(code **)((long)&DAT_001006a8 + lVar6) = stm_heartbeat_hrtimer_handler;
        iVar2 = stm_source_register_device(0,(long *)((long)&stm_heartbeat + lVar6));
        if (iVar2 != 0) goto LAB_0010029c;
        uVar5 = uVar5 + 1;
        lVar6 = lVar6 + 0x78;
      } while ((long)uVar5 < (long)(int)nr_devs);
    }
    iVar2 = 0;
  }
  else {
    iVar2 = -0x16;
  }
  return iVar2;
LAB_0010029c:
  while ((uVar5 * 0x78 < 0xf01 && (uVar5 != 0x20))) {
    kfree((&stm_heartbeat)[uVar5 * 0xf]);
LAB_00100288:
    iVar4 = (int)uVar5;
    uVar5 = (ulong)(iVar4 - 1);
    if (iVar4 < 1) {
      return iVar2;
    }
    stm_source_unregister_device(&stm_heartbeat + uVar5 * 0xf);
  }
LAB_001002c8:
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0x1002cc);
  (*pcVar1)();
}



//------------------------------------------------------------
// cleanup_module @ 001002d0 size=132
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  
  if (0 < nr_devs) {
    lVar2 = 0;
    lVar3 = 0;
    do {
      if (lVar2 == 0xf00) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x100350);
        (*pcVar1)();
      }
      stm_source_unregister_device((long)&stm_heartbeat + lVar2);
      if (lVar2 == 0xf00) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(1,0x100354);
        (*pcVar1)();
      }
      kfree(*(undefined8 *)((long)&stm_heartbeat + lVar2));
      lVar3 = lVar3 + 1;
      lVar2 = lVar2 + 0x78;
    } while (lVar3 < nr_devs);
  }
  return;
}



//------------------------------------------------------------
// stm_heartbeat_link @ 00100358 size=76
// signature: undefined stm_heartbeat_link(void)
// callers: []
//------------------------------------------------------------

undefined8 stm_heartbeat_link(long param_1)

{
  int iVar1;
  
  iVar1 = interval_ms;
  *(undefined4 *)(param_1 + 0x70) = 1;
  hrtimer_start_range_ns(param_1 + 0x28,(long)iVar1 * 1000000,0,0);
  return 0;
}



//------------------------------------------------------------
// stm_heartbeat_unlink @ 001003a8 size=40
// signature: undefined stm_heartbeat_unlink(void)
// callers: []
//------------------------------------------------------------

void stm_heartbeat_unlink(long param_1)

{
  *(undefined4 *)(param_1 + 0x70) = 0;
  hrtimer_cancel(param_1 + 0x28);
  return;
}



//------------------------------------------------------------
// stm_heartbeat_hrtimer_handler @ 001003d4 size=160
// signature: undefined stm_heartbeat_hrtimer_handler(void)
// callers: []
//------------------------------------------------------------

bool stm_heartbeat_hrtimer_handler(long param_1)

{
  long lVar1;
  bool bVar2;
  undefined8 uVar3;
  code *pcVar4;
  
  stm_source_write(param_1 + -0x28,0,"heartbeat stm source driver is here to serve you",0x31);
  if (*(int *)(param_1 + 0x48) == 0) {
    bVar2 = false;
  }
  else {
    lVar1 = (long)interval_ms;
    pcVar4 = *(code **)(*(long *)(param_1 + 0x30) + 0x30);
    if (*(int *)(pcVar4 + -4) != 0x7230bf2a) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10043c);
      (*pcVar4)();
    }
    uVar3 = (*pcVar4)();
    hrtimer_forward(param_1,uVar3,lVar1 * 1000000);
    bVar2 = *(int *)(param_1 + 0x48) != 0;
  }
  return bVar2;
}



//------------------------------------------------------------
// kasprintf @ 00102000 size=1
// signature: undefined kasprintf(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kasprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_init @ 00102008 size=1
// signature: undefined hrtimer_init(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// stm_source_register_device @ 00102010 size=1
// signature: undefined stm_source_register_device(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void stm_source_register_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// stm_source_unregister_device @ 00102018 size=1
// signature: undefined stm_source_unregister_device(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void stm_source_unregister_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102020 size=1
// signature: undefined kfree(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_start_range_ns @ 00102028 size=1
// signature: undefined hrtimer_start_range_ns(void)
// callers: [stm_heartbeat_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_start_range_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_cancel @ 00102030 size=1
// signature: undefined hrtimer_cancel(void)
// callers: [stm_heartbeat_unlink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_cancel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// stm_source_write @ 00102038 size=1
// signature: undefined stm_source_write(void)
// callers: [stm_heartbeat_hrtimer_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void stm_source_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_forward @ 00102040 size=1
// signature: undefined hrtimer_forward(void)
// callers: [stm_heartbeat_hrtimer_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_forward(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



