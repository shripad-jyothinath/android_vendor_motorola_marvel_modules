// Decompiled by Ghidra 12.2
// Program: ubwcp.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_ubwcp_probe @ 001029dc size=100
// signature: undefined __traceiter_ubwcp_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 __traceiter_ubwcp_probe(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00113c10;
  plVar2 = DAT_00113c10;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0xe7e1609) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102a20);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_remove @ 00102a44 size=100
// signature: undefined __traceiter_ubwcp_remove(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_remove(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00113c58;
  plVar2 = _DAT_00113c58;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0xe7e1609) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102a88);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_init_buffer_start @ 00102aac size=100
// signature: undefined __traceiter_ubwcp_init_buffer_start(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_init_buffer_start(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00113ca0;
  plVar2 = _DAT_00113ca0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x673baa2e) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102af0);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_init_buffer_end @ 00102b14 size=100
// signature: undefined __traceiter_ubwcp_init_buffer_end(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_init_buffer_end(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00113ce8;
  plVar2 = _DAT_00113ce8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x673baa2e) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102b58);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_memremap_pages_start @ 00102b7c size=100
// signature: undefined __traceiter_ubwcp_memremap_pages_start(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_memremap_pages_start(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00113d30;
  plVar2 = _DAT_00113d30;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x43dbf732) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102bc0);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_memremap_pages_end @ 00102be4 size=100
// signature: undefined __traceiter_ubwcp_memremap_pages_end(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_memremap_pages_end(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00113d78;
  plVar2 = _DAT_00113d78;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x43dbf732) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102c28);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_set_buf_attrs_start @ 00102c4c size=100
// signature: undefined __traceiter_ubwcp_set_buf_attrs_start(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_set_buf_attrs_start(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00113dc0;
  plVar2 = _DAT_00113dc0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x673baa2e) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102c90);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_set_buf_attrs_end @ 00102cb4 size=100
// signature: undefined __traceiter_ubwcp_set_buf_attrs_end(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_set_buf_attrs_end(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00113e08;
  plVar2 = _DAT_00113e08;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x673baa2e) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102cf8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_lock_start @ 00102d1c size=100
// signature: undefined __traceiter_ubwcp_lock_start(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_lock_start(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00113e50;
  plVar2 = _DAT_00113e50;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x673baa2e) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102d60);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_lock_end @ 00102d84 size=100
// signature: undefined __traceiter_ubwcp_lock_end(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_lock_end(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00113e98;
  plVar2 = _DAT_00113e98;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x673baa2e) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102dc8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_unlock_start @ 00102dec size=100
// signature: undefined __traceiter_ubwcp_unlock_start(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_unlock_start(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00113ee0;
  plVar2 = _DAT_00113ee0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x673baa2e) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102e30);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_unlock_end @ 00102e54 size=100
// signature: undefined __traceiter_ubwcp_unlock_end(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_unlock_end(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00113f28;
  plVar2 = _DAT_00113f28;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x673baa2e) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102e98);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_offline_sync_start @ 00102ebc size=100
// signature: undefined __traceiter_ubwcp_offline_sync_start(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_offline_sync_start(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00113f70;
  plVar2 = _DAT_00113f70;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x43dbf732) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102f00);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_offline_sync_end @ 00102f24 size=100
// signature: undefined __traceiter_ubwcp_offline_sync_end(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_offline_sync_end(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00113fb8;
  plVar2 = _DAT_00113fb8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x43dbf732) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102f68);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_dma_sync_single_for_device_start @ 00102f8c size=116
// signature: undefined __traceiter_ubwcp_dma_sync_single_for_device_start(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_ubwcp_dma_sync_single_for_device_start
          (undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00114000;
  plVar2 = _DAT_00114000;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x3c50a1b9) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102fdc);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_dma_sync_single_for_device_end @ 00103004 size=116
// signature: undefined __traceiter_ubwcp_dma_sync_single_for_device_end(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_ubwcp_dma_sync_single_for_device_end
          (undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00114048;
  plVar2 = _DAT_00114048;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x3c50a1b9) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103054);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_dma_sync_single_for_cpu_start @ 0010307c size=116
// signature: undefined __traceiter_ubwcp_dma_sync_single_for_cpu_start(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_ubwcp_dma_sync_single_for_cpu_start
          (undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00114090;
  plVar2 = _DAT_00114090;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x3c50a1b9) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1030cc);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_dma_sync_single_for_cpu_end @ 001030f4 size=116
// signature: undefined __traceiter_ubwcp_dma_sync_single_for_cpu_end(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_ubwcp_dma_sync_single_for_cpu_end
          (undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001140d8;
  plVar2 = _DAT_001140d8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x3c50a1b9) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103144);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_hw_flush_start @ 0010316c size=100
// signature: undefined __traceiter_ubwcp_hw_flush_start(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_hw_flush_start(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00114120;
  plVar2 = _DAT_00114120;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x43dbf732) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1031b0);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_hw_flush_end @ 001031d4 size=100
// signature: undefined __traceiter_ubwcp_hw_flush_end(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_hw_flush_end(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00114168;
  plVar2 = _DAT_00114168;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x43dbf732) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103218);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_memunmap_pages_start @ 0010323c size=100
// signature: undefined __traceiter_ubwcp_memunmap_pages_start(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_memunmap_pages_start(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001141b0;
  plVar2 = _DAT_001141b0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x43dbf732) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103280);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_memunmap_pages_end @ 001032a4 size=100
// signature: undefined __traceiter_ubwcp_memunmap_pages_end(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_memunmap_pages_end(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001141f8;
  plVar2 = _DAT_001141f8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x43dbf732) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1032e8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_set_direct_map_range_uncached_start @ 0010330c size=100
// signature: undefined __traceiter_ubwcp_set_direct_map_range_uncached_start(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_ubwcp_set_direct_map_range_uncached_start(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00114240;
  plVar2 = _DAT_00114240;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x43dbf732) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103350);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_set_direct_map_range_uncached_end @ 00103374 size=100
// signature: undefined __traceiter_ubwcp_set_direct_map_range_uncached_end(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_ubwcp_set_direct_map_range_uncached_end(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00114288;
  plVar2 = _DAT_00114288;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x43dbf732) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1033b8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_free_buffer_start @ 001033dc size=100
// signature: undefined __traceiter_ubwcp_free_buffer_start(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_free_buffer_start(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001142d0;
  plVar2 = _DAT_001142d0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x673baa2e) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103420);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_free_buffer_end @ 00103444 size=100
// signature: undefined __traceiter_ubwcp_free_buffer_end(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_free_buffer_end(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00114318;
  plVar2 = _DAT_00114318;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x673baa2e) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103488);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_prefetch_tgt_start @ 001034ac size=100
// signature: undefined __traceiter_ubwcp_prefetch_tgt_start(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_prefetch_tgt_start(undefined8 param_1,undefined4 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00114360;
  plVar2 = _DAT_00114360;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0xce76772) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1034f0);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ubwcp_prefetch_tgt_end @ 00103514 size=100
// signature: undefined __traceiter_ubwcp_prefetch_tgt_end(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ubwcp_prefetch_tgt_end(undefined8 param_1,undefined4 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001143a8;
  plVar2 = _DAT_001143a8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0xce76772) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103558);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_ubwcp_platform_device_event @ 0010357c size=168
// signature: undefined trace_event_raw_event_ubwcp_platform_device_event(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_ubwcp_platform_device_event(long param_1,undefined8 param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x10), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_ubwcp_platform_device_event @ 00103628 size=236
// signature: undefined perf_trace_ubwcp_platform_device_event(void)
// callers: []
//------------------------------------------------------------

void perf_trace_ubwcp_platform_device_event(long param_1,undefined8 param_2)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_50 [12];
  undefined4 local_44;
  long local_40;
  undefined8 local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  local_44 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x14,&local_40,&local_44), lVar3 != 0)) {
    *(undefined1 **)(local_40 + 0xe8) = auStack_50 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_40 + 0xf8) = auStack_50;
    *(ulong *)(local_40 + 0x100) = uVar2;
    *(undefined8 *)(local_40 + 0x108) = 5;
    *(undefined8 *)(lVar3 + 8) = param_2;
    perf_trace_run_bpf_submit(lVar3,0x14,local_44,param_1,1,local_40,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_ubwcp_dmabuf_event @ 00103718 size=168
// signature: undefined trace_event_raw_event_ubwcp_dmabuf_event(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_ubwcp_dmabuf_event(long param_1,undefined8 param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x10), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_ubwcp_dmabuf_event @ 001037c4 size=236
// signature: undefined perf_trace_ubwcp_dmabuf_event(void)
// callers: []
//------------------------------------------------------------

void perf_trace_ubwcp_dmabuf_event(long param_1,undefined8 param_2)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_50 [12];
  undefined4 local_44;
  long local_40;
  undefined8 local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  local_44 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x14,&local_40,&local_44), lVar3 != 0)) {
    *(undefined1 **)(local_40 + 0xe8) = auStack_50 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_40 + 0xf8) = auStack_50;
    *(ulong *)(local_40 + 0x100) = uVar2;
    *(undefined8 *)(local_40 + 0x108) = 5;
    *(undefined8 *)(lVar3 + 8) = param_2;
    perf_trace_run_bpf_submit(lVar3,0x14,local_44,param_1,1,local_40,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_ubwcp_size_event @ 001038b4 size=168
// signature: undefined trace_event_raw_event_ubwcp_size_event(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_ubwcp_size_event(long param_1,undefined8 param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x10), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_ubwcp_size_event @ 00103960 size=236
// signature: undefined perf_trace_ubwcp_size_event(void)
// callers: []
//------------------------------------------------------------

void perf_trace_ubwcp_size_event(long param_1,undefined8 param_2)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_50 [12];
  undefined4 local_44;
  long local_40;
  undefined8 local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  local_44 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x14,&local_40,&local_44), lVar3 != 0)) {
    *(undefined1 **)(local_40 + 0xe8) = auStack_50 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_40 + 0xf8) = auStack_50;
    *(ulong *)(local_40 + 0x100) = uVar2;
    *(undefined8 *)(local_40 + 0x108) = 5;
    *(undefined8 *)(lVar3 + 8) = param_2;
    perf_trace_run_bpf_submit(lVar3,0x14,local_44,param_1,1,local_40,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_ubwcp_sync_event @ 00103a50 size=176
// signature: undefined trace_event_raw_event_ubwcp_sync_event(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_ubwcp_sync_event(long param_1,undefined8 param_2,undefined4 param_3)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x18), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0x10) = param_3;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_ubwcp_sync_event @ 00103b04 size=252
// signature: undefined perf_trace_ubwcp_sync_event(void)
// callers: []
//------------------------------------------------------------

void perf_trace_ubwcp_sync_event(long param_1,undefined8 param_2,undefined4 param_3)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined8 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0x10) = param_3;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_ubwcp_int_event @ 00103c04 size=168
// signature: undefined trace_event_raw_event_ubwcp_int_event(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_ubwcp_int_event(long param_1,undefined4 param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0xc), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_ubwcp_int_event @ 00103cb0 size=236
// signature: undefined perf_trace_ubwcp_int_event(void)
// callers: []
//------------------------------------------------------------

void perf_trace_ubwcp_int_event(long param_1,undefined4 param_2)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_50 [12];
  undefined4 local_44;
  long local_40;
  undefined8 local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  local_44 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0xc,&local_40,&local_44), lVar3 != 0)) {
    *(undefined1 **)(local_40 + 0xe8) = auStack_50 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_40 + 0xf8) = auStack_50;
    *(ulong *)(local_40 + 0x100) = uVar2;
    *(undefined8 *)(local_40 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    perf_trace_run_bpf_submit(lVar3,0xc,local_44,param_1,1,local_40,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_ubwcp_platform_device_event @ 00103da0 size=28
// signature: undefined __bpf_trace_ubwcp_platform_device_event(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_ubwcp_platform_device_event(void)

{
  bpf_trace_run1();
  return;
}



//------------------------------------------------------------
// __bpf_trace_ubwcp_dmabuf_event @ 00103dc0 size=28
// signature: undefined __bpf_trace_ubwcp_dmabuf_event(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_ubwcp_dmabuf_event(void)

{
  bpf_trace_run1();
  return;
}



//------------------------------------------------------------
// __bpf_trace_ubwcp_size_event @ 00103de0 size=28
// signature: undefined __bpf_trace_ubwcp_size_event(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_ubwcp_size_event(void)

{
  bpf_trace_run1();
  return;
}



//------------------------------------------------------------
// __bpf_trace_ubwcp_sync_event @ 00103e00 size=32
// signature: undefined __bpf_trace_ubwcp_sync_event(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_ubwcp_sync_event(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  bpf_trace_run2(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_ubwcp_int_event @ 00103e24 size=32
// signature: undefined __bpf_trace_ubwcp_int_event(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_ubwcp_int_event(undefined8 param_1,undefined4 param_2)

{
  bpf_trace_run1(param_1,param_2);
  return;
}



//------------------------------------------------------------
// ubwcp_get_hw_version @ 00103e48 size=188
// signature: undefined ubwcp_get_hw_version(void)
// callers: []
//------------------------------------------------------------

undefined8 ubwcp_get_hw_version(undefined4 *param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  
  lVar1 = me;
  if (param_1 == (undefined4 *)0x0) {
    iVar3 = ___ratelimit(ubwcp_get_hw_version__rs,"ubwcp_get_hw_version");
    if (iVar3 == 0) {
      uVar4 = 0xffffffea;
    }
    else {
      _printk(&DAT_00114e2a,"ubwcp","ubwcp_get_hw_version",0x1d0);
      uVar4 = 0xffffffea;
    }
  }
  else {
    if (me == 0) {
      __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x103e7c);
      (*pcVar2)();
    }
    if (*(int *)(me + 0x111d4) == -1) {
      uVar4 = 0xffffffff;
    }
    else {
      uVar4 = 0;
      *param_1 = *(undefined4 *)(me + 0x118);
      param_1[1] = *(undefined4 *)(lVar1 + 0x11c);
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// ubwcp_set_buf_attrs @ 00103f10 size=4980
// signature: undefined ubwcp_set_buf_attrs(void)
// callers: [ubwcp_ioctl]
//------------------------------------------------------------

int ubwcp_set_buf_attrs(long param_1,ushort *param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  char cVar5;
  ushort uVar6;
  short sVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  code *pcVar11;
  int iVar12;
  int iVar13;
  undefined8 uVar14;
  undefined *puVar15;
  long lVar16;
  ulong uVar17;
  uint uVar18;
  uint uVar19;
  long lVar20;
  uint uVar21;
  undefined8 uVar22;
  undefined2 uVar23;
  uint uVar24;
  long *plVar25;
  long lVar26;
  bool bVar27;
  ulong uVar28;
  long local_d8;
  ushort local_c0 [2];
  uint local_bc;
  ulong local_b8;
  ulong local_b0;
  long local_a8;
  ulong local_a0;
  long local_98;
  ulong local_90;
  undefined8 local_88;
  long local_80;
  long local_78;
  undefined4 local_6c;
  long local_68;
  
  lVar1 = me;
  lVar26 = sp_el0;
  local_68 = *(long *)(lVar26 + 0x638);
  local_80 = 0;
  local_78 = 0;
  local_90 = 0;
  local_88 = 0;
  local_a0 = 0;
  local_98 = 0;
  local_a8 = 0;
  local_b8 = 0;
  local_b0 = 0;
  local_bc = 0;
  local_c0[0] = 0;
  if (param_1 == 0) {
    iVar12 = ___ratelimit(ubwcp_set_buf_attrs__rs,"ubwcp_set_buf_attrs");
    if (iVar12 == 0) goto LAB_00104090;
    puVar15 = &DAT_00116825;
    uVar14 = 0x645;
LAB_001041d4:
    _printk(puVar15,"ubwcp","ubwcp_set_buf_attrs",uVar14);
  }
  else if (param_2 == (ushort *)0x0) {
    iVar12 = ___ratelimit(ubwcp_set_buf_attrs__rs_3,"ubwcp_set_buf_attrs");
    if (iVar12 != 0) {
      puVar15 = &DAT_001164b4;
      uVar14 = 0x64b;
      goto LAB_001041d4;
    }
  }
  else {
    if (me == 0) {
      __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
      pcVar11 = (code *)SoftwareBreakpoint(0x800,0x103f8c);
      (*pcVar11)();
    }
    lVar26 = me + 0x11210;
    uVar14 = _raw_spin_lock_irqsave(lVar26);
    plVar25 = (long *)(lVar1 + ((ulong)(param_1 * 0x61c8864680b583eb) >> 0x33) * 8 + 0x120);
    do {
      plVar25 = (long *)*plVar25;
      if (plVar25 == (long *)0x0) {
        _raw_spin_unlock_irqrestore(lVar26,uVar14);
        iVar12 = ___ratelimit(ubwcp_set_buf_attrs__rs_5,"ubwcp_set_buf_attrs");
        if (iVar12 == 0) goto LAB_00104090;
        puVar15 = &DAT_00114f3b;
        uVar14 = 0x652;
        goto LAB_001041d4;
      }
    } while (plVar25[0x12] != param_1);
    _raw_spin_unlock_irqrestore(lVar26,uVar14);
    lVar26 = plVar25[2];
    if (*(int *)(lVar26 + 0x111d4) != 0) {
      iVar12 = 1;
      goto LAB_00104098;
    }
    local_6c = 0;
    if ((((((*(int *)(param_2 + 0x1a) == 0) && (*(int *)(param_2 + 0x1c) == 0)) &&
          (*(int *)(param_2 + 0x1e) == 0)) &&
         ((*(int *)(param_2 + 0x20) == 0 && (*(int *)(param_2 + 0x22) == 0)))) &&
        ((*(int *)(param_2 + 0x24) == 0 &&
         ((*(int *)(param_2 + 0x26) == 0 && (*(int *)(param_2 + 0x28) == 0)))))) &&
       (*(int *)(param_2 + 0x2a) == 0)) {
      if ((((*(int *)(param_2 + 8) == 0) || (*(int *)(param_2 + 10) == 0)) ||
          (*(int *)(param_2 + 0xc) == 0)) || (*(int *)(param_2 + 0xe) == 0)) {
        iVar12 = ___ratelimit(ubwcp_buf_attrs_valid__rs_92,"ubwcp_buf_attrs_valid");
        if (iVar12 != 0) {
          _printk(&DAT_00116516,"ubwcp","ubwcp_buf_attrs_valid",0x3a5);
        }
        goto LAB_00104138;
      }
      uVar6 = *param_2;
      if (0x10 < uVar6) {
        iVar12 = ___ratelimit(ubwcp_buf_attrs_valid__rs_94,"ubwcp_buf_attrs_valid");
        if (iVar12 != 0) {
          uVar18 = (uint)*param_2;
          puVar15 = &DAT_001157eb;
          uVar14 = 0x3aa;
          goto LAB_00104a4c;
        }
        goto LAB_00104138;
      }
      if (uVar6 != 0) {
        iVar12 = to_std_format(uVar6,&local_6c);
        if (iVar12 == 0) {
          if ((param_2[1] == 0) && (param_2[2] == 0)) {
            if (param_2[3] == 0) {
              if (*(long *)(param_2 + 4) == 0) {
                if (*(uint *)(param_2 + 8) < 0x2801) {
                  if (*(uint *)(param_2 + 10) < 0x2801) {
                    uVar28 = stride_is_valid(lVar26,local_6c,*(uint *)(param_2 + 8),
                                             *(undefined4 *)(param_2 + 0xc));
                    if ((uVar28 & 1) == 0) {
                      iVar12 = ___ratelimit(ubwcp_buf_attrs_valid__rs_106,"ubwcp_buf_attrs_valid");
                      if (iVar12 != 0) {
                        uVar18 = *(uint *)(param_2 + 0xc);
                        puVar15 = &DAT_001150d4;
                        uVar14 = 0x3d2;
                        goto LAB_00104a4c;
                      }
                    }
                    else if ((*(uint *)(param_2 + 0xe) < *(uint *)(param_2 + 10)) ||
                            (*(uint *)(param_2 + 10) + 0x8000 < *(uint *)(param_2 + 0xe))) {
                      iVar12 = ___ratelimit(ubwcp_buf_attrs_valid__rs_108,"ubwcp_buf_attrs_valid");
                      if (iVar12 != 0) {
                        _printk(&DAT_0011559e,"ubwcp","ubwcp_buf_attrs_valid",0x3d9,
                                *(undefined4 *)(param_2 + 10),*(undefined4 *)(param_2 + 0xe));
                      }
                    }
                    else if (*(uint *)(param_2 + 0x10) < 0x1001) {
                      if (*(int *)(param_2 + 0x12) == 0) {
                        if (*(uint *)(param_2 + 0x14) < 2) {
                          if (*(uint *)(param_2 + 0x14) == 0) {
                            iVar12 = ___ratelimit(ubwcp_buf_attrs_valid__rs_116,
                                                  "ubwcp_buf_attrs_valid");
                            if (iVar12 != 0) {
                              uVar18 = *(uint *)(param_2 + 0x14);
                              puVar15 = &DAT_00117720;
                              uVar14 = 0x3ef;
                              goto LAB_00104a4c;
                            }
                          }
                          else if (*(int *)(param_2 + 0x16) == 0) {
                            if (*(int *)(param_2 + 0x18) == 1) goto LAB_00105374;
                            iVar12 = ___ratelimit(ubwcp_buf_attrs_valid__rs_120,
                                                  "ubwcp_buf_attrs_valid");
                            if (iVar12 != 0) {
                              uVar18 = *(uint *)(param_2 + 0x18);
                              puVar15 = &DAT_00117766;
                              uVar14 = 0x3f9;
                              goto LAB_00104a4c;
                            }
                          }
                          else {
                            iVar12 = ___ratelimit(ubwcp_buf_attrs_valid__rs_118,
                                                  "ubwcp_buf_attrs_valid");
                            if (iVar12 != 0) {
                              uVar18 = *(uint *)(param_2 + 0x16);
                              puVar15 = &DAT_0011692b;
                              uVar14 = 0x3f4;
                              goto LAB_00104a4c;
                            }
                          }
                        }
                        else {
                          iVar12 = ___ratelimit(ubwcp_buf_attrs_valid__rs_114,
                                                "ubwcp_buf_attrs_valid");
                          if (iVar12 != 0) {
                            uVar18 = *(uint *)(param_2 + 0x14);
                            puVar15 = &DAT_00115108;
                            uVar14 = 0x3e9;
                            goto LAB_00104a4c;
                          }
                        }
                      }
                      else {
                        iVar12 = ___ratelimit(ubwcp_buf_attrs_valid__rs_112,"ubwcp_buf_attrs_valid")
                        ;
                        if (iVar12 != 0) {
                          uVar18 = *(uint *)(param_2 + 0x12);
                          puVar15 = &DAT_00116195;
                          uVar14 = 0x3e3;
                          goto LAB_00104a4c;
                        }
                      }
                    }
                    else {
                      iVar12 = ___ratelimit(ubwcp_buf_attrs_valid__rs_110,"ubwcp_buf_attrs_valid");
                      if (iVar12 != 0) {
                        uVar18 = *(uint *)(param_2 + 0x10);
                        puVar15 = &DAT_001149d1;
                        uVar14 = 0x3de;
                        goto LAB_00104a4c;
                      }
                    }
                  }
                  else {
                    iVar12 = ___ratelimit(ubwcp_buf_attrs_valid__rs_104,"ubwcp_buf_attrs_valid");
                    if (iVar12 != 0) {
                      uVar18 = *(uint *)(param_2 + 10);
                      puVar15 = &DAT_00115556;
                      uVar14 = 0x3cd;
                      goto LAB_00104a4c;
                    }
                  }
                }
                else {
                  iVar12 = ___ratelimit(ubwcp_buf_attrs_valid__rs_102,"ubwcp_buf_attrs_valid");
                  if (iVar12 != 0) {
                    uVar18 = *(uint *)(param_2 + 8);
                    puVar15 = &DAT_001168e4;
                    uVar14 = 0x3c8;
LAB_00104a4c:
                    _printk(puVar15,"ubwcp","ubwcp_buf_attrs_valid",uVar14,uVar18);
                  }
                }
              }
              else {
                iVar12 = ___ratelimit(ubwcp_buf_attrs_valid__rs_100,"ubwcp_buf_attrs_valid");
                if (iVar12 != 0) {
                  _printk(&DAT_0011798a,"ubwcp","ubwcp_buf_attrs_valid",0x3c3,
                          *(undefined8 *)(param_2 + 4));
                }
              }
            }
            else {
              iVar12 = ___ratelimit(ubwcp_buf_attrs_valid__rs_98,"ubwcp_buf_attrs_valid");
              if (iVar12 != 0) {
                uVar18 = (uint)param_2[3];
                puVar15 = &DAT_001168a4;
                uVar14 = 0x3be;
                goto LAB_00104a4c;
              }
            }
          }
          else {
            iVar12 = ___ratelimit(ubwcp_buf_attrs_valid__rs_96,"ubwcp_buf_attrs_valid");
            if (iVar12 != 0) {
              _printk(&DAT_00115822,"ubwcp","ubwcp_buf_attrs_valid",0x3b8,param_2[1],param_2[2]);
            }
          }
        }
        goto LAB_00104138;
      }
LAB_00105374:
      bVar27 = true;
    }
    else {
      iVar12 = ___ratelimit(ubwcp_buf_attrs_valid__rs,"ubwcp_buf_attrs_valid");
      if (iVar12 != 0) {
        _printk(&DAT_001157a5,"ubwcp","ubwcp_buf_attrs_valid",0x3a0);
      }
LAB_00104138:
      bVar27 = false;
    }
    if (((((ubwcp_debug_trace_enable != 0) &&
          (_printk(&DAT_00115efc,"ubwcp","dump_attributes"), ubwcp_debug_trace_enable != 0)) &&
         (_printk(&DAT_00114b66,"ubwcp","dump_attributes",*param_2), ubwcp_debug_trace_enable != 0))
        && ((((_printk(&DAT_001163d0,"ubwcp","dump_attributes",param_2[1]),
              ubwcp_debug_trace_enable != 0 &&
              (_printk(&DAT_00117deb,"ubwcp","dump_attributes",param_2[2]),
              ubwcp_debug_trace_enable != 0)) &&
             ((_printk(&DAT_0011570d,"ubwcp","dump_attributes",param_2[3]),
              ubwcp_debug_trace_enable != 0 &&
              ((_printk(&DAT_0011720d,"ubwcp","dump_attributes",*(undefined8 *)(param_2 + 4)),
               ubwcp_debug_trace_enable != 0 &&
               (_printk(&DAT_001175f8,"ubwcp","dump_attributes",*(undefined4 *)(param_2 + 8)),
               ubwcp_debug_trace_enable != 0)))))) &&
            (_printk(&DAT_00115874,"ubwcp","dump_attributes",*(undefined4 *)(param_2 + 10)),
            ubwcp_debug_trace_enable != 0)))) &&
       ((((((_printk(&DAT_00116b39,"ubwcp","dump_attributes",*(undefined4 *)(param_2 + 0xc)),
            ubwcp_debug_trace_enable != 0 &&
            (_printk(&DAT_00117428,"ubwcp","dump_attributes",*(undefined4 *)(param_2 + 0xe)),
            ubwcp_debug_trace_enable != 0)) &&
           (_printk(&DAT_0011515c,"ubwcp","dump_attributes",*(undefined4 *)(param_2 + 0x10)),
           ubwcp_debug_trace_enable != 0)) &&
          ((_printk(&DAT_00115cbd,"ubwcp","dump_attributes",*(undefined4 *)(param_2 + 0x12)),
           ubwcp_debug_trace_enable != 0 &&
           (_printk(&DAT_00116e5f,"ubwcp","dump_attributes",*(undefined4 *)(param_2 + 0x14)),
           ubwcp_debug_trace_enable != 0)))) &&
         (_printk(&DAT_00117443,"ubwcp","dump_attributes",*(undefined4 *)(param_2 + 0x16)),
         ubwcp_debug_trace_enable != 0)) &&
        (_printk(&DAT_0011722d,"ubwcp","dump_attributes",*(undefined4 *)(param_2 + 0x18)),
        ubwcp_debug_trace_enable != 0)))) {
      _printk(&DAT_00115efc,"ubwcp","dump_attributes");
    }
    if (bVar27) {
      lVar1 = (long)(plVar25 + 0x1b);
      mutex_lock(lVar1);
      if (*(int *)(plVar25 + 0x11) == 0) {
        sVar7 = *(short *)(plVar25 + 3);
        if (*(int *)(*(code **)(lVar26 + 0x110) + -4) != 0x52b3fa06) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x104210);
          (*pcVar11)();
        }
        iVar12 = (**(code **)(lVar26 + 0x110))(plVar25[0x12],1,0,0);
        if (iVar12 == 0) {
          if (*param_2 == 0) {
            if (ubwcp_debug_trace_enable == 0) {
              cVar5 = *(char *)(plVar25 + 0x10);
            }
            else {
              _printk(&DAT_001175b8,"ubwcp","ubwcp_set_buf_attrs");
              cVar5 = *(char *)(plVar25 + 0x10);
            }
            if (cVar5 != '\0') {
              reset_buf_attrs(plVar25);
            }
            if (sVar7 == 0) {
              iVar12 = 0;
            }
            else {
              iVar12 = dec_num_non_lin_buffers(lVar26);
            }
LAB_00104340:
            mutex_unlock(lVar1);
            trace_ubwcp_set_buf_attrs_end(param_1);
            goto LAB_00104098;
          }
          iVar12 = to_std_format(*param_2,&local_bc);
          uVar18 = local_bc;
          if (iVar12 != 0) {
            iVar12 = ___ratelimit(ubwcp_set_buf_attrs__rs_14,"ubwcp_set_buf_attrs");
            if (iVar12 != 0) {
              puVar15 = &DAT_00117f9e;
              uVar14 = 0x689;
LAB_001044a8:
              _printk(puVar15,"ubwcp","ubwcp_set_buf_attrs",uVar14);
            }
LAB_0010432c:
            mutex_unlock(lVar1);
            iVar12 = -1;
            goto LAB_00104098;
          }
          uVar28 = (ulong)local_bc;
          iVar12 = std_to_hw_img_fmt(uVar28,local_c0);
          if (iVar12 != 0) {
            iVar12 = ___ratelimit(ubwcp_set_buf_attrs__rs_16,"ubwcp_set_buf_attrs");
            if (iVar12 != 0) {
              puVar15 = &DAT_0011793a;
              uVar14 = 0x68e;
              goto LAB_001044a8;
            }
            goto LAB_0010432c;
          }
          iVar12 = ubwcp_calc_ula_params(lVar26,param_2,&local_78,&local_88,&local_80);
          lVar10 = local_80;
          if (iVar12 == 0) {
            iVar12 = ubwcp_validate_uv_align(lVar26,param_2,local_88);
            if (iVar12 == 0) {
              iVar12 = ubwcp_calc_ubwcp_buf_params
                                 (lVar26,param_2,&local_90,&local_98,&local_a0,&local_a8,&local_b0);
              uVar9 = local_90;
              lVar20 = local_98;
              uVar8 = local_a0;
              lVar16 = local_a8;
              if (iVar12 == 0) {
                lVar2 = local_98 + local_90;
                lVar3 = lVar2 + local_a0 + local_a8;
                if (((ubwcp_debug_trace_enable == 0) ||
                    (_printk(&DAT_00115efc,"ubwcp","ubwcp_set_buf_attrs"),
                    ubwcp_debug_trace_enable == 0)) ||
                   ((_printk(&DAT_00115efc,"ubwcp","ubwcp_set_buf_attrs"),
                    ubwcp_debug_trace_enable == 0 ||
                    (_printk(&DAT_00115aa5,"ubwcp","ubwcp_set_buf_attrs"),
                    ubwcp_debug_trace_enable == 0)))) {
LAB_0010474c:
                  local_d8 = local_78;
                }
                else {
                  local_d8 = local_78;
                  _printk(&DAT_00117333,"ubwcp","ubwcp_set_buf_attrs",local_78,local_78);
                  if (ubwcp_debug_trace_enable != 0) {
                    _printk(&DAT_00115c90,"ubwcp","ubwcp_set_buf_attrs",lVar10,lVar10);
                    if ((((ubwcp_debug_trace_enable != 0) &&
                         (_printk(&DAT_00117c21,"ubwcp","ubwcp_set_buf_attrs"),
                         ubwcp_debug_trace_enable != 0)) &&
                        (_printk(&DAT_00115f0a,"ubwcp","ubwcp_set_buf_attrs",uVar9,uVar9),
                        ubwcp_debug_trace_enable != 0)) &&
                       (((_printk(&DAT_0011530f,"ubwcp","ubwcp_set_buf_attrs",lVar20,lVar20),
                         ubwcp_debug_trace_enable != 0 &&
                         (_printk(&DAT_00114b01,"ubwcp","ubwcp_set_buf_attrs",uVar8,uVar8),
                         ubwcp_debug_trace_enable != 0)) &&
                        ((_printk(&DAT_0011665c,"ubwcp","ubwcp_set_buf_attrs",lVar16,lVar16),
                         ubwcp_debug_trace_enable != 0 &&
                         ((_printk(&DAT_00116688,"ubwcp","ubwcp_set_buf_attrs",local_b0,local_b0),
                          ubwcp_debug_trace_enable != 0 &&
                          (_printk(&DAT_00115779,"ubwcp","ubwcp_set_buf_attrs",lVar3,lVar3),
                          ubwcp_debug_trace_enable != 0)))))))) {
                      _printk(&DAT_00115efc,"ubwcp","ubwcp_set_buf_attrs");
                    }
                    goto LAB_0010474c;
                  }
                }
                if (local_d8 == 0) {
                  iVar12 = ___ratelimit(ubwcp_set_buf_attrs__rs_35,"ubwcp_set_buf_attrs");
                  if (iVar12 != 0) {
                    puVar15 = &DAT_00114980;
                    uVar14 = 0x6b7;
                    goto LAB_001044a8;
                  }
                  goto LAB_0010432c;
                }
                lVar16 = ubwcp_ula_realloc(lVar26,plVar25[0x15],plVar25[0x16],local_d8);
                iVar12 = ubwcp_debug_trace_enable;
                if (lVar16 == 0) {
                  iVar12 = ___ratelimit(ubwcp_set_buf_attrs__rs_37,"ubwcp_set_buf_attrs");
                  if (iVar12 == 0) goto LAB_00104908;
                  puVar15 = &DAT_00116359;
                  uVar14 = 0x6be;
LAB_00104c40:
                  _printk(puVar15,"ubwcp","ubwcp_set_buf_attrs",uVar14);
                  iVar12 = 0;
LAB_0010490c:
                  reset_buf_attrs(plVar25);
                  if (sVar7 != 0) goto LAB_00104918;
                }
                else {
                  plVar25[0x15] = lVar16;
                  plVar25[0x16] = local_d8;
                  if ((iVar12 != 0) &&
                     (_printk(&DAT_00116aaa,"ubwcp","ubwcp_set_buf_attrs",lVar16,local_d8),
                     ubwcp_debug_trace_enable != 0)) {
                    _printk(&DAT_00115efc,"ubwcp","ubwcp_set_buf_attrs");
                  }
                  if (*(char *)(plVar25 + 0x10) == '\0') {
                    iVar12 = ubwcp_dma_map(plVar25,*(undefined8 *)(lVar26 + 0xc0),&local_b8);
                    if (iVar12 == 0) {
                      if (ubwcp_debug_trace_enable != 0) {
                        _printk(&DAT_00116add,"ubwcp","ubwcp_set_buf_attrs",local_b8,lVar3,
                                local_b8 + lVar3);
                      }
                      goto LAB_00104790;
                    }
                    iVar13 = ___ratelimit(ubwcp_set_buf_attrs__rs_40,"ubwcp_set_buf_attrs");
                    if (iVar13 != 0) {
                      _printk(&DAT_00114b2d,"ubwcp","ubwcp_set_buf_attrs",0x6cc,iVar12);
                    }
                    goto LAB_0010490c;
                  }
LAB_00104790:
                  uVar17 = verify_dma_buf_size(plVar25,lVar3);
                  if ((uVar17 & 1) == 0) {
LAB_00104908:
                    iVar12 = 0;
                    goto LAB_0010490c;
                  }
                  if ((lVar16 + lVar10 & 0x3fU) != 0) {
                    iVar12 = ___ratelimit(ubwcp_set_buf_attrs__rs_43,"ubwcp_set_buf_attrs");
                    if (iVar12 != 0) {
                      puVar15 = &DAT_00116048;
                      uVar14 = 0x6d8;
                      goto LAB_00104c40;
                    }
                    goto LAB_00104908;
                  }
                  if (uVar18 == 4) {
                    uVar6 = *(ushort *)(lVar26 + 0x1118a);
                    uVar24 = *(int *)(param_2 + 10) * (uint)*(ushort *)(lVar26 + 0x11188);
                    uVar19 = 0;
                    if (uVar6 != 0) {
                      uVar19 = (*(int *)(param_2 + 8) * (uint)*(ushort *)(lVar26 + 0x11188)) /
                               (uint)uVar6;
                    }
                  }
                  else {
                    if (6 < uVar18) {
                    /* WARNING: Does not return */
                      pcVar11 = (code *)SoftwareBreakpoint(0x5512,0x1053bc);
                      (*pcVar11)();
                    }
                    lVar20 = lVar26 + uVar28 * 0x1a;
                    uVar6 = *(ushort *)(lVar20 + 0x1113c);
                    uVar24 = (uint)*(ushort *)(lVar20 + 0x1113a);
                    uVar19 = 0;
                    if (uVar6 != 0) {
                      uVar19 = (*(int *)(param_2 + 8) * uVar24) / (uint)uVar6;
                    }
                    uVar24 = *(int *)(param_2 + 10) * uVar24;
                  }
                  uVar21 = 0;
                  if (uVar6 != 0) {
                    uVar21 = uVar24 / uVar6;
                  }
                  uVar24 = *(uint *)(param_2 + 0xc);
                  *(undefined4 *)(plVar25 + 0x1a) = 0;
                  uVar23 = (undefined2)(uVar24 >> 6);
                  plVar25[0x18] = 0;
                  plVar25[0x19] = 0;
                  plVar25[0x17] =
                       (ulong)(lVar16 + lVar10) >> 6 & 0xffffffffffff | (ulong)local_c0[0] << 0x30;
                  if (uVar18 == 4) {
                    *(undefined2 *)((long)plVar25 + 0xc2) = uVar23;
                    uVar23 = (undefined2)(local_b0 >> 6);
                  }
                  *(undefined2 *)(plVar25 + 0x18) = uVar23;
                  *(int *)((long)plVar25 + 0xc4) = (int)(local_b8 >> 0xc);
                  *(int *)(plVar25 + 0x19) = (int)(lVar2 + local_b8 >> 0xc);
                  *(short *)((long)plVar25 + 0xcc) = (short)(uVar9 >> 0xc);
                  *(short *)((long)plVar25 + 0xce) = (short)(uVar8 >> 0xc);
                  if ((*(int *)(lVar26 + 0x118) != 1) || (*(int *)(lVar26 + 0x11c) != 1)) {
                    uVar21 = *(uint *)(param_2 + 10);
                  }
                  *(uint *)(plVar25 + 0x1a) = uVar21 | uVar19 << 0x10;
                  print_mmdata_desc(plVar25 + 0x17);
                  if ((sVar7 == 0) && (iVar12 = inc_num_non_lin_buffers(lVar26), iVar12 != 0)) {
                    iVar13 = ___ratelimit(ubwcp_set_buf_attrs__rs_45,"ubwcp_set_buf_attrs");
                    if (iVar13 != 0) {
                      _printk(&DAT_00116ffd,"ubwcp","ubwcp_set_buf_attrs",0x70a,iVar12);
                    }
LAB_00104c7c:
                    reset_buf_attrs(plVar25);
                    goto LAB_00104234;
                  }
                  if (ubwcp_debug_trace_enable != 0) {
                    _printk(&DAT_001156d0,"ubwcp","ubwcp_set_buf_attrs",lVar16,local_d8);
                  }
                  if (*(int *)(*(code **)(lVar26 + 0x110) + -4) != 0x52b3fa06) {
                    /* WARNING: Does not return */
                    pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x104b64);
                    (*pcVar11)();
                  }
                  iVar12 = (**(code **)(lVar26 + 0x110))
                                     (plVar25[0x12],0,plVar25[0x15],plVar25[0x16]);
                  if (iVar12 == 0) {
                    uVar14 = *(undefined8 *)(param_2 + 8);
                    uVar22 = *(undefined8 *)param_2;
                    plVar25[4] = *(undefined8 *)(param_2 + 4);
                    plVar25[5] = uVar14;
                    plVar25[3] = uVar22;
                    uVar22 = *(undefined8 *)(param_2 + 0x18);
                    uVar14 = *(undefined8 *)(param_2 + 0xc);
                    uVar4 = *(undefined8 *)(param_2 + 0x10);
                    plVar25[8] = *(undefined8 *)(param_2 + 0x14);
                    plVar25[9] = uVar22;
                    plVar25[6] = uVar14;
                    plVar25[7] = uVar4;
                    uVar22 = *(undefined8 *)(param_2 + 0x28);
                    uVar14 = *(undefined8 *)(param_2 + 0x1c);
                    uVar4 = *(undefined8 *)(param_2 + 0x20);
                    plVar25[0xc] = *(undefined8 *)(param_2 + 0x24);
                    plVar25[0xd] = uVar22;
                    plVar25[10] = uVar14;
                    plVar25[0xb] = uVar4;
                    *(undefined1 *)(plVar25 + 0x10) = 1;
                    goto LAB_00104340;
                  }
                  iVar13 = ___ratelimit(ubwcp_set_buf_attrs__rs_48,"ubwcp_set_buf_attrs");
                  if (iVar13 != 0) {
                    _printk(&DAT_0011703e,"ubwcp","ubwcp_set_buf_attrs",0x712,iVar12);
                  }
                  if (sVar7 == 0) {
                    dec_num_non_lin_buffers(lVar26);
                    goto LAB_00104c7c;
                  }
                  reset_buf_attrs(plVar25);
LAB_00104918:
                  dec_num_non_lin_buffers(lVar26);
                }
                mutex_unlock(lVar1);
                if (iVar12 == 0) {
                  iVar12 = -1;
                }
                goto LAB_00104098;
              }
              iVar13 = ___ratelimit(ubwcp_set_buf_attrs__rs_22,"ubwcp_set_buf_attrs");
              if (iVar13 != 0) {
                puVar15 = &DAT_00115ebb;
                uVar14 = 0x6a2;
                goto LAB_00104370;
              }
            }
            else {
              iVar13 = ___ratelimit(ubwcp_set_buf_attrs__rs_20,"ubwcp_set_buf_attrs");
              if (iVar13 != 0) {
                puVar15 = &DAT_00116d18;
                uVar14 = 0x69b;
                goto LAB_00104370;
              }
            }
          }
          else {
            iVar13 = ___ratelimit(ubwcp_set_buf_attrs__rs_18,"ubwcp_set_buf_attrs");
            if (iVar13 != 0) {
              puVar15 = &DAT_00114f8e;
              uVar14 = 0x695;
LAB_00104370:
              _printk(puVar15,"ubwcp","ubwcp_set_buf_attrs",uVar14,iVar12);
            }
          }
        }
        else {
          iVar13 = ___ratelimit(ubwcp_set_buf_attrs__rs_11,"ubwcp_set_buf_attrs");
          if (iVar13 != 0) {
            puVar15 = &DAT_00116fbb;
            uVar14 = 0x671;
            goto LAB_00104370;
          }
        }
      }
      else {
        iVar12 = ___ratelimit(ubwcp_set_buf_attrs__rs_9,"ubwcp_set_buf_attrs");
        if (iVar12 != 0) {
          _printk(&DAT_00116859,"ubwcp","ubwcp_set_buf_attrs",0x666);
        }
        iVar12 = -0x10;
      }
LAB_00104234:
      mutex_unlock(lVar1);
      goto LAB_00104098;
    }
    iVar12 = ___ratelimit(ubwcp_set_buf_attrs__rs_7,"ubwcp_set_buf_attrs");
    if (iVar12 != 0) {
      puVar15 = &DAT_00117588;
      uVar14 = 0x65e;
      goto LAB_001041d4;
    }
  }
LAB_00104090:
  iVar12 = -0x16;
LAB_00104098:
  lVar26 = sp_el0;
  if (*(long *)(lVar26 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar12;
}



//------------------------------------------------------------
// reset_buf_attrs @ 001053bc size=176
// signature: undefined reset_buf_attrs(void)
// callers: [ubwcp_set_buf_attrs, ubwcp_free_buffer]
//------------------------------------------------------------

void reset_buf_attrs(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 0x10);
  if ((*(long *)(param_1 + 0x90) != 0) && (lVar1 = *(long *)(param_1 + 0x98), lVar1 != 0)) {
    if (ubwcp_debug_trace_enable != 0) {
      _printk(&DAT_00117249,"ubwcp","ubwcp_dma_unmap");
      lVar1 = *(long *)(param_1 + 0x98);
    }
    dma_buf_unmap_attachment(lVar1,*(undefined8 *)(param_1 + 0xa0),0);
    *(undefined8 *)(param_1 + 0xa0) = 0;
    dma_buf_detach(*(undefined8 *)(param_1 + 0x90),*(undefined8 *)(param_1 + 0x98));
    *(undefined8 *)(param_1 + 0x98) = 0;
  }
  if (*(long *)(param_1 + 0xb0) != 0) {
    ubwcp_ula_free(uVar2,*(undefined8 *)(param_1 + 0xa8));
    *(undefined8 *)(param_1 + 0xa8) = 0;
    *(undefined8 *)(param_1 + 0xb0) = 0;
  }
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined8 *)(param_1 + 0xc0) = 0;
  *(undefined8 *)(param_1 + 200) = 0;
  *(undefined8 *)(param_1 + 0xb8) = 0;
  *(undefined1 *)(param_1 + 0x80) = 0;
  *(undefined2 *)(param_1 + 0x18) = 0;
  return;
}



//------------------------------------------------------------
// dec_num_non_lin_buffers @ 0010546c size=792
// signature: undefined dec_num_non_lin_buffers(void)
// callers: [ubwcp_set_buf_attrs, ubwcp_free_buffer]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 dec_num_non_lin_buffers(long param_1)

{
  long lVar1;
  int *piVar2;
  ulong uVar3;
  char cVar4;
  bool bVar5;
  undefined8 uVar6;
  int iVar7;
  int iVar8;
  ulong uVar9;
  long lVar10;
  
  piVar2 = (int *)(param_1 + 0x111d8);
  Hint_Prefetch(piVar2,2,0,1);
  do {
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
    if (bVar5) {
      *piVar2 = *piVar2 + -1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  lVar1 = param_1 + 0x11218;
  mutex_lock(lVar1);
  if (*(int *)(param_1 + 0x111d8) != 0) {
LAB_001054c4:
    mutex_unlock(lVar1);
    return 0;
  }
  if (ubwcp_debug_trace_enable == 0) {
    cVar4 = *(char *)(param_1 + 0x111dc);
  }
  else {
    _printk(&DAT_0011588c,"ubwcp","dec_num_non_lin_buffers");
    cVar4 = *(char *)(param_1 + 0x111dc);
  }
  if (cVar4 == '\0') {
    iVar7 = ___ratelimit(dec_num_non_lin_buffers__rs,"dec_num_non_lin_buffers");
    if (iVar7 != 0) {
      _printk(&DAT_00117279,"ubwcp","dec_num_non_lin_buffers",0x274);
    }
  }
  else {
    lVar10 = *(long *)(param_1 + 0xf8);
    uVar9 = *(ulong *)(param_1 + 0x100);
    iVar7 = set_direct_map_range_uncached(lVar10 - _memstart_addr | 0xffffff8000000000,uVar9 >> 0xc)
    ;
    if (iVar7 == 0) {
      if (uVar9 != 0) {
        lVar10 = 0;
        uVar6 = sp_el0;
        do {
          if (0 < *(int *)(param_1 + 0x111d8)) {
            ula_unmap(param_1);
            iVar7 = ula_add_mem(param_1);
            if (iVar7 == 0) {
              if (ubwcp_debug_trace_enable != 0) {
                _printk(&DAT_00117ff1,"ubwcp","dec_num_non_lin_buffers");
              }
              goto LAB_001054c4;
            }
            iVar7 = ___ratelimit(ula_remove_mem__rs,"ula_remove_mem");
            if (iVar7 != 0) {
              _printk(&DAT_00114b84,"ubwcp","ula_remove_mem",0x234);
            }
            goto LAB_0010580c;
          }
          uVar3 = uVar9;
          if (0x3ffffff < uVar9) {
            uVar3 = 0x4000000;
          }
          dma_sync_single_for_cpu
                    (*(undefined8 *)(param_1 + 0xb0),*(long *)(param_1 + 0xf8) + lVar10,uVar3,0);
          lVar10 = uVar3 + lVar10;
          bVar5 = 0x4000000 < uVar9;
          uVar9 = uVar9 - 0x4000000;
        } while (bVar5);
      }
      ula_unmap(param_1);
      *(undefined1 *)(param_1 + 0x111dc) = 0;
      iVar7 = ubwcp_power(param_1,0);
      if (iVar7 == 0) goto LAB_001054c4;
    }
    else {
      iVar8 = ___ratelimit(ula_map_uncached__rs,"ula_map_uncached");
      if (iVar8 != 0) {
        _printk(&DAT_00115373,"ubwcp","ula_map_uncached",0x209,lVar10,uVar9 >> 0xc,iVar7);
      }
    }
  }
LAB_0010580c:
  piVar2 = (int *)(param_1 + 0x111d8);
  Hint_Prefetch(piVar2,2,0,1);
  do {
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
    if (bVar5) {
      *piVar2 = *piVar2 + 1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  mutex_unlock(lVar1);
  *(undefined4 *)(param_1 + 0x111d4) = 0xfffffffe;
  iVar7 = ___ratelimit(dec_num_non_lin_buffers__rs_149,"dec_num_non_lin_buffers");
  if (iVar7 != 0) {
    _printk(&DAT_00115635,"ubwcp","dec_num_non_lin_buffers",0x28e);
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// trace_ubwcp_set_buf_attrs_end @ 00105be8 size=44
// signature: undefined trace_ubwcp_set_buf_attrs_end(void)
// callers: [ubwcp_set_buf_attrs]
//------------------------------------------------------------

void trace_ubwcp_set_buf_attrs_end(void)

{
  return;
}



//------------------------------------------------------------
// to_std_format @ 00105cb0 size=200
// signature: undefined to_std_format(void)
// callers: [ubwcp_set_buf_attrs]
//------------------------------------------------------------

undefined8 to_std_format(undefined2 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  switch(param_1) {
  case 1:
    *param_2 = 0;
    return 0;
  case 2:
  case 3:
  case 4:
    uVar2 = 1;
    break;
  case 5:
  case 6:
  case 7:
    uVar2 = 2;
    break;
  case 8:
  case 9:
  case 10:
    uVar2 = 4;
    break;
  case 0xb:
  case 0xc:
  case 0xd:
    uVar2 = 3;
    break;
  case 0xe:
  case 0xf:
  case 0x10:
    uVar2 = 5;
    break;
  default:
    iVar1 = ___ratelimit(to_std_format__rs,"to_std_format");
    if (iVar1 != 0) {
      _printk(&DAT_001153d5,"ubwcp","to_std_format",0x303,param_1);
    }
    return 0xffffffff;
  }
  *param_2 = uVar2;
  return 0;
}



//------------------------------------------------------------
// std_to_hw_img_fmt @ 00105d78 size=200
// signature: undefined std_to_hw_img_fmt(void)
// callers: [ubwcp_set_buf_attrs]
//------------------------------------------------------------

undefined8 std_to_hw_img_fmt(undefined4 param_1,undefined2 *param_2)

{
  int iVar1;
  undefined2 uVar2;
  
  switch(param_1) {
  case 0:
    *param_2 = 0;
    return 0;
  case 1:
    uVar2 = 2;
    break;
  case 2:
    uVar2 = 4;
    break;
  case 3:
    uVar2 = 6;
    break;
  case 4:
    uVar2 = 8;
    break;
  case 5:
    uVar2 = 10;
    break;
  default:
    iVar1 = ___ratelimit(std_to_hw_img_fmt__rs,"std_to_hw_img_fmt");
    if (iVar1 != 0) {
      _printk(&DAT_001161ce,"ubwcp","std_to_hw_img_fmt",0x31e,param_1);
    }
    return 0xffffffff;
  }
  *param_2 = uVar2;
  return 0;
}



//------------------------------------------------------------
// ubwcp_calc_ula_params @ 00105e40 size=1468
// signature: undefined ubwcp_calc_ula_params(void)
// callers: [ubwcp_set_buf_attrs]
//------------------------------------------------------------

undefined8
ubwcp_calc_ula_params(long param_1,undefined2 *param_2,ulong *param_3,ulong *param_4,ulong *param_5)

{
  undefined2 uVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  long lVar10;
  uint uVar11;
  int iVar12;
  
  uVar1 = *param_2;
  lVar10 = 1;
  switch(uVar1) {
  case 1:
    iVar4 = *(int *)(param_2 + 0xc);
    uVar9 = *(uint *)(param_2 + 0xe);
    lVar10 = 0;
    uVar6 = 1;
    uVar11 = *(uint *)(param_2 + 0x10);
    bVar3 = true;
    goto switchD_00105ee8_caseD_5;
  case 2:
  case 3:
  case 4:
    break;
  case 5:
  case 6:
  case 7:
    lVar10 = 2;
    break;
  case 8:
  case 9:
  case 10:
    lVar10 = 4;
    break;
  case 0xb:
  case 0xc:
  case 0xd:
    lVar10 = 3;
    break;
  case 0xe:
  case 0xf:
  case 0x10:
    lVar10 = 5;
    break;
  default:
    iVar4 = ___ratelimit(to_std_format__rs,"to_std_format");
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    _printk(&DAT_001153d5,"ubwcp","to_std_format",0x303,uVar1);
    return 0xffffffff;
  }
  iVar4 = *(int *)(param_2 + 0xc);
  uVar9 = *(uint *)(param_2 + 0xe);
  bVar3 = false;
  uVar6 = 2;
  uVar11 = *(uint *)(param_2 + 0x10);
  iVar12 = 2;
  switch(uVar1) {
  case 3:
  case 6:
  case 9:
  case 0xc:
  case 0xf:
    break;
  case 4:
  case 7:
  case 10:
  case 0xd:
  case 0x10:
    bVar3 = false;
    iVar12 = 1;
    break;
  default:
switchD_00105ee8_caseD_5:
    iVar12 = 0;
  }
  if ((((ubwcp_debug_trace_enable != 0) &&
       (_printk(&DAT_00115b33,"ubwcp","ubwcp_calc_ula_params"), ubwcp_debug_trace_enable != 0)) &&
      (_printk(&DAT_00115b4f,"ubwcp","ubwcp_calc_ula_params",*param_2,lVar10),
      ubwcp_debug_trace_enable != 0)) &&
     ((_printk(&DAT_00114cb5,"ubwcp","ubwcp_calc_ula_params",uVar6), ubwcp_debug_trace_enable != 0
      && (_printk(&DAT_00116b51,"ubwcp","ubwcp_calc_ula_params",iVar12),
         ubwcp_debug_trace_enable != 0)))) {
    _printk(&DAT_00115d34,"ubwcp","ubwcp_calc_ula_params",uVar11);
  }
  if ((bVar3) || (iVar12 == 2)) {
    if (ubwcp_debug_trace_enable == 0) {
      bVar3 = true;
    }
    else {
      _printk(&DAT_0011697b,"ubwcp","ubwcp_ula_size","ubwcp_ula_size",lVar10,0);
      bVar3 = ubwcp_debug_trace_enable == 0;
    }
    uVar2 = *(ushort *)(param_1 + lVar10 * 0x1a + 0x11140);
    uVar11 = 0;
    uVar5 = (uint)uVar2;
    if (uVar5 != 0) {
      uVar11 = ((uVar9 + uVar2) - 1) / uVar5;
    }
    uVar8 = (ulong)(uVar11 * uVar5 * iVar4);
    if (!bVar3) {
      _printk(&DAT_001166c8,"ubwcp","ubwcp_ula_size",0,iVar4,uVar11 * uVar5,uVar8,uVar8);
    }
    *param_5 = uVar8;
    *param_4 = uVar8;
    goto LAB_00105fcc;
  }
  if (iVar12 != 0) {
    if (ubwcp_debug_trace_enable == 0) {
      bVar3 = true;
    }
    else {
      _printk(&DAT_0011697b,"ubwcp","ubwcp_ula_size","ubwcp_ula_size",lVar10,1);
      bVar3 = ubwcp_debug_trace_enable == 0;
    }
    uVar2 = *(ushort *)(param_1 + lVar10 * 0x1a + 0x1114c);
    uVar11 = 0;
    uVar5 = (uint)uVar2;
    if (uVar5 != 0) {
      uVar11 = (((uint)uVar2 + (uVar9 >> 1)) - 1) / uVar5;
    }
    uVar8 = (ulong)(uVar11 * uVar5 * iVar4);
    if (!bVar3) {
      _printk(&DAT_001166c8,"ubwcp","ubwcp_ula_size",1,iVar4,uVar11 * uVar5,uVar8,uVar8);
    }
    *param_5 = 0;
    *param_4 = 0;
    goto LAB_00105fcc;
  }
  if (ubwcp_debug_trace_enable == 0) {
    uVar7 = (ulong)(uVar9 * iVar4);
LAB_00105f3c:
    uVar8 = uVar7 + uVar11;
    bVar3 = true;
    *param_4 = uVar7;
    *param_5 = uVar8;
  }
  else {
    _printk(&DAT_0011697b,"ubwcp","ubwcp_ula_size","ubwcp_ula_size",lVar10,0);
    uVar7 = (ulong)(uVar9 * iVar4);
    if (ubwcp_debug_trace_enable == 0) goto LAB_00105f3c;
    _printk(&DAT_001166c8,"ubwcp","ubwcp_ula_size",0,iVar4,uVar9,uVar7,uVar7);
    iVar12 = ubwcp_debug_trace_enable;
    uVar8 = uVar7 + uVar11;
    *param_4 = uVar7;
    *param_5 = uVar8;
    if (iVar12 == 0) {
      bVar3 = true;
    }
    else {
      _printk(&DAT_0011697b,"ubwcp","ubwcp_ula_size","ubwcp_ula_size",lVar10,1);
      bVar3 = ubwcp_debug_trace_enable == 0;
    }
  }
  uVar2 = *(ushort *)(param_1 + lVar10 * 0x1a + 0x1114c);
  uVar11 = 0;
  uVar5 = (uint)uVar2;
  if (uVar5 != 0) {
    uVar11 = (((uint)uVar2 + (uVar9 >> 1)) - 1) / uVar5;
  }
  uVar7 = (ulong)(uVar11 * uVar5 * iVar4);
  if (!bVar3) {
    _printk(&DAT_001166c8,"ubwcp","ubwcp_ula_size",1,iVar4,uVar11 * uVar5,uVar7,uVar7);
  }
  uVar8 = uVar8 + uVar7;
LAB_00105fcc:
  iVar4 = ubwcp_debug_trace_enable;
  uVar7 = uVar8 + 0xfff & 0x7fffff000;
  *param_3 = uVar7;
  if (iVar4 != 0) {
    _printk(&DAT_00114cda,"ubwcp","ubwcp_calc_ula_params",uVar7,uVar7,uVar8);
  }
  return 0;
}



//------------------------------------------------------------
// ubwcp_validate_uv_align @ 001063fc size=432
// signature: undefined ubwcp_validate_uv_align(void)
// callers: [ubwcp_set_buf_attrs]
//------------------------------------------------------------

undefined8 ubwcp_validate_uv_align(long param_1,undefined2 *param_2,long param_3,ulong param_4)

{
  undefined2 uVar1;
  ulong uVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  long lVar6;
  
  uVar1 = *param_2;
  uVar4 = 0;
  lVar6 = 1;
  switch(uVar1) {
  case 1:
    goto switchD_00106444_caseD_1;
  case 5:
  case 6:
  case 7:
    lVar6 = 2;
    break;
  case 8:
  case 9:
  case 10:
    lVar6 = 4;
    break;
  case 0xb:
  case 0xc:
  case 0xd:
    lVar6 = 3;
  case 2:
  case 3:
  case 4:
    break;
  case 0xe:
  case 0xf:
  case 0x10:
    lVar6 = 5;
    break;
  default:
    iVar3 = ___ratelimit(to_std_format__rs,"to_std_format");
    if (iVar3 == 0) {
      uVar4 = 0xffffffff;
    }
    else {
      _printk(&DAT_001153d5,"ubwcp","to_std_format",0x303,uVar1);
      uVar4 = 0xffffffff;
    }
    goto switchD_00106444_caseD_1;
  }
  if ((param_4 & 0x3f) == 0) {
    uVar5 = (ulong)(*(int *)(param_2 + 0xc) * (uint)*(ushort *)(param_1 + lVar6 * 0x1a + 0x11140));
    uVar2 = 0;
    if (uVar5 != 0) {
      uVar2 = ((param_3 + uVar5) - 1) / uVar5;
    }
    if (uVar2 * uVar5 <= param_4) {
      return 0;
    }
    iVar3 = ___ratelimit(ubwcp_validate_uv_align__rs_176,"ubwcp_validate_uv_align");
    if (iVar3 != 0) {
      _printk(&DAT_00117c9b,"ubwcp","ubwcp_validate_uv_align",0x4f8,param_4,uVar2 * uVar5,param_3);
    }
  }
  else {
    iVar3 = ___ratelimit(ubwcp_validate_uv_align__rs,"ubwcp_validate_uv_align");
    if (iVar3 != 0) {
      _printk(&DAT_001174ae,"ubwcp","ubwcp_validate_uv_align",0x4e8,param_4);
    }
  }
  uVar4 = 0xffffffea;
switchD_00106444_caseD_1:
  return uVar4;
}



//------------------------------------------------------------
// ubwcp_calc_ubwcp_buf_params @ 001065ac size=800
// signature: undefined ubwcp_calc_ubwcp_buf_params(void)
// callers: [ubwcp_set_buf_attrs]
//------------------------------------------------------------

undefined8
ubwcp_calc_ubwcp_buf_params
          (undefined8 param_1,undefined2 *param_2,undefined8 *param_3,undefined8 *param_4,
          undefined8 *param_5,undefined8 *param_6,long *param_7)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  ulong uVar5;
  byte bVar6;
  bool bVar7;
  int iVar8;
  undefined8 uVar9;
  
  uVar1 = *param_2;
  iVar8 = 1;
  iVar3 = 0;
  iVar2 = 2;
  switch(uVar1) {
  case 1:
    goto switchD_00106614_caseD_1;
  case 2:
  case 3:
  case 4:
    goto switchD_00106614_caseD_2;
  case 5:
  case 6:
  case 7:
    break;
  case 8:
  case 9:
  case 10:
    iVar2 = 4;
    break;
  case 0xb:
  case 0xc:
  case 0xd:
    iVar2 = 3;
    break;
  case 0xe:
  case 0xf:
  case 0x10:
    iVar2 = 5;
    break;
  default:
    iVar3 = ___ratelimit(to_std_format__rs,"to_std_format");
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    _printk(&DAT_001153d5,"ubwcp","to_std_format",0x303,uVar1);
    return 0xffffffff;
  }
  iVar8 = iVar2;
switchD_00106614_caseD_2:
  bVar7 = false;
  bVar6 = 0;
  uVar9 = 2;
  iVar3 = iVar8;
  switch(uVar1) {
  case 3:
  case 6:
  case 9:
  case 0xc:
  case 0xf:
    break;
  case 4:
  case 7:
  case 10:
  case 0xd:
  case 0x10:
    bVar7 = true;
    bVar6 = 1;
    uVar9 = 1;
    break;
  default:
switchD_00106614_caseD_1:
    iVar8 = iVar3;
    bVar7 = false;
    uVar9 = 0;
    bVar6 = 1;
  }
  uVar4 = 1;
  if (iVar8 != 0) {
    uVar4 = 2;
  }
  if ((((ubwcp_debug_trace_enable != 0) &&
       (_printk(1,&DAT_001159c8,"ubwcp","ubwcp_calc_ubwcp_buf_params"),
       ubwcp_debug_trace_enable != 0)) &&
      (_printk(&DAT_00115b4f,"ubwcp","ubwcp_calc_ubwcp_buf_params",*param_2,iVar8),
      ubwcp_debug_trace_enable != 0)) &&
     (_printk(&DAT_00114cb5,"ubwcp","ubwcp_calc_ubwcp_buf_params",uVar4),
     ubwcp_debug_trace_enable != 0)) {
    _printk(&DAT_00116b51,"ubwcp","ubwcp_calc_ubwcp_buf_params",uVar9);
  }
  *param_3 = 0;
  *param_4 = 0;
  *param_5 = 0;
  *param_6 = 0;
  *param_7 = 0;
  if ((bVar7) ||
     ((iVar3 = metadata_buf_sz(param_1,iVar8,*(undefined4 *)(param_2 + 8),
                               *(undefined4 *)(param_2 + 10),0,param_3), iVar3 == 0 &&
      (iVar3 = pixeldata_buf_sz(param_1,iVar8,*(undefined4 *)(param_2 + 8),
                                *(undefined4 *)(param_2 + 10),0,param_4), iVar3 == 0)))) {
    bVar7 = (bool)(bVar6 ^ 1);
    if (iVar8 == 0) {
      bVar7 = true;
    }
    if ((bVar7) ||
       ((iVar3 = metadata_buf_sz(param_1,iVar8,*(undefined4 *)(param_2 + 8),
                                 *(undefined4 *)(param_2 + 10),1,param_5), iVar3 == 0 &&
        (iVar3 = pixeldata_buf_sz(param_1,iVar8,*(undefined4 *)(param_2 + 8),
                                  *(undefined4 *)(param_2 + 10),1,param_6), iVar3 == 0)))) {
      if (iVar8 == 4) {
        uVar5 = (ulong)(((*(int *)(param_2 + 8) + 0xbfU) / 0xc0) * 0xc0);
        *param_7 = uVar5 + uVar5 / 3;
        return 0;
      }
      return 0;
    }
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// ubwcp_ula_realloc @ 001068cc size=128
// signature: undefined ubwcp_ula_realloc(void)
// callers: [ubwcp_set_buf_attrs]
//------------------------------------------------------------

long ubwcp_ula_realloc(long param_1,long param_2,long param_3,long param_4)

{
  long lVar1;
  
  if (param_3 != param_4) {
    if (param_2 != 0) {
      ubwcp_ula_free(param_1,param_2);
    }
    mutex_lock(param_1 + 0x11248);
    lVar1 = *(long *)(param_1 + 0x108);
    param_2 = gen_pool_alloc_algo_owner
                        (lVar1,param_4,*(undefined8 *)(lVar1 + 0x20),*(undefined8 *)(lVar1 + 0x28),0
                        );
    mutex_unlock(param_1 + 0x11248);
  }
  return param_2;
}



//------------------------------------------------------------
// ubwcp_dma_map @ 0010694c size=416
// signature: undefined ubwcp_dma_map(void)
// callers: [ubwcp_set_buf_attrs]
//------------------------------------------------------------

int ubwcp_dma_map(long param_1,long param_2,undefined8 *param_3)

{
  int iVar1;
  ulong uVar2;
  long *plVar3;
  undefined8 uVar4;
  
  uVar4 = *(undefined8 *)(param_1 + 0x90);
  uVar2 = dma_buf_attach(uVar4);
  if (uVar2 < 0xfffffffffffff001) {
    if (*(undefined4 **)(param_2 + 0x2b8) != (undefined4 *)0x0) {
      **(undefined4 **)(param_2 + 0x2b8) = 0xffffffff;
      if (*(long *)(param_2 + 0x2b8) != 0) {
        *(undefined8 *)(*(long *)(param_2 + 0x2b8) + 8) = 0xffffffffffffffff;
      }
    }
    plVar3 = (long *)dma_buf_map_attachment(uVar2,0);
    if ((plVar3 == (long *)0x0) || ((long *)0xfffffffffffff000 < plVar3)) {
      iVar1 = ___ratelimit(ubwcp_dma_map__rs_193,"ubwcp_dma_map");
      if (iVar1 != 0) {
        _printk(&DAT_00116b76,"ubwcp","ubwcp_dma_map",0x5dc,(ulong)plVar3 & 0xffffffff);
      }
    }
    else {
      if ((int)plVar3[1] == 1) {
        *param_3 = *(undefined8 *)(*plVar3 + 0x10);
        *(ulong *)(param_1 + 0x98) = uVar2;
        *(long **)(param_1 + 0xa0) = plVar3;
        return 0;
      }
      iVar1 = ___ratelimit(ubwcp_dma_map__rs_195,"ubwcp_dma_map");
      if (iVar1 != 0) {
        _printk(&DAT_00118077,"ubwcp","ubwcp_dma_map",0x5e1,(int)plVar3[1]);
      }
      dma_buf_unmap_attachment(uVar2,plVar3,0);
      plVar3 = (long *)0x0;
    }
    dma_buf_detach(uVar4,uVar2);
    uVar2 = (ulong)plVar3 & 0xffffffff;
  }
  else {
    iVar1 = ___ratelimit(ubwcp_dma_map__rs,"ubwcp_dma_map");
    if (iVar1 != 0) {
      _printk(&DAT_00117d1b,"ubwcp","ubwcp_dma_map",0x5d2,uVar2 & 0xffffffff);
    }
  }
  iVar1 = (int)uVar2;
  if (iVar1 == 0) {
    iVar1 = -1;
  }
  return iVar1;
}



//------------------------------------------------------------
// verify_dma_buf_size @ 00106aec size=132
// signature: undefined verify_dma_buf_size(void)
// callers: [ubwcp_set_buf_attrs]
//------------------------------------------------------------

bool verify_dma_buf_size(long param_1,ulong param_2)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = (ulong)*(uint *)(**(long **)(param_1 + 0xa0) + 0x18);
  if ((uVar2 < param_2) &&
     (iVar1 = ___ratelimit(verify_dma_buf_size__rs,"verify_dma_buf_size"), iVar1 != 0)) {
    _printk(&DAT_00116bb8,"ubwcp","verify_dma_buf_size",0x5be,uVar2,param_2);
  }
  return param_2 <= uVar2;
}



//------------------------------------------------------------
// print_mmdata_desc @ 00106b70 size=552
// signature: undefined print_mmdata_desc(void)
// callers: [ubwcp_set_buf_attrs]
//------------------------------------------------------------

void print_mmdata_desc(ulong *param_1)

{
  uint uVar1;
  
  if (ubwcp_debug_trace_enable != 0) {
    _printk(&DAT_00115efc,"ubwcp","print_mmdata_desc");
    if ((ubwcp_debug_trace_enable != 0) &&
       (_printk(&DAT_001151b3,"ubwcp","print_mmdata_desc"), ubwcp_debug_trace_enable != 0)) {
      _printk(&DAT_0011764c,"ubwcp","print_mmdata_desc",*param_1 & 0xffffffffffff,
              (*param_1 & 0xffffffffffff) << 6);
      if (ubwcp_debug_trace_enable != 0) {
        _printk(&DAT_00116268,"ubwcp","print_mmdata_desc",*(undefined2 *)((long)param_1 + 6));
        if (ubwcp_debug_trace_enable != 0) {
          _printk(&DAT_0011542a,"ubwcp","print_mmdata_desc",(ushort)param_1[1],
                  (ulong)(ushort)param_1[1] << 6);
          if (ubwcp_debug_trace_enable != 0) {
            _printk(&DAT_00117872,"ubwcp","print_mmdata_desc",*(ushort *)((long)param_1 + 10),
                    (ulong)*(ushort *)((long)param_1 + 10) << 6);
            if (ubwcp_debug_trace_enable != 0) {
              _printk(&DAT_00115007,"ubwcp","print_mmdata_desc",*(int *)((long)param_1 + 0xc),
                      *(int *)((long)param_1 + 0xc) << 0xc);
              if (ubwcp_debug_trace_enable != 0) {
                _printk(&DAT_00114bdb,"ubwcp","print_mmdata_desc",(int)param_1[2],
                        (int)param_1[2] << 0xc);
                if (ubwcp_debug_trace_enable != 0) {
                  _printk(&DAT_00116093,"ubwcp","print_mmdata_desc",
                          *(ushort *)((long)param_1 + 0x14),
                          (ulong)*(ushort *)((long)param_1 + 0x14) << 0xc);
                  if (ubwcp_debug_trace_enable != 0) {
                    _printk(&DAT_001158b2,"ubwcp","print_mmdata_desc",
                            *(ushort *)((long)param_1 + 0x16),
                            (ulong)*(ushort *)((long)param_1 + 0x16) << 0xc);
                    if (ubwcp_debug_trace_enable != 0) {
                      uVar1 = (uint)param_1[3];
                      _printk(&DAT_001160d6,"ubwcp","print_mmdata_desc",uVar1,uVar1 >> 0x10,
                              uVar1 & 0xffff);
                      if (ubwcp_debug_trace_enable != 0) {
                        _printk(&DAT_00115efc,"ubwcp","print_mmdata_desc");
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}



//------------------------------------------------------------
// inc_num_non_lin_buffers @ 00106d98 size=364
// signature: undefined inc_num_non_lin_buffers(void)
// callers: [ubwcp_set_buf_attrs]
//------------------------------------------------------------

undefined8 inc_num_non_lin_buffers(long param_1)

{
  long lVar1;
  int *piVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  undefined8 uVar6;
  
  piVar2 = (int *)(param_1 + 0x111d8);
  Hint_Prefetch(piVar2,2,0,1);
  do {
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar2,0x10);
    if (bVar4) {
      *piVar2 = *piVar2 + 1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  lVar1 = param_1 + 0x11218;
  mutex_lock(lVar1);
  if (*(char *)(param_1 + 0x111dc) == '\0') {
    if (*(int *)(param_1 + 0x111d8) == 0) {
      iVar5 = ___ratelimit(inc_num_non_lin_buffers__rs,"inc_num_non_lin_buffers");
      if (iVar5 != 0) {
        _printk(&DAT_001169c0,"ubwcp","inc_num_non_lin_buffers",0x252);
      }
    }
    else {
      iVar5 = ubwcp_power(param_1,1);
      if (iVar5 == 0) {
        iVar5 = ula_add_mem(param_1);
        if (iVar5 == 0) {
          *(undefined1 *)(param_1 + 0x111dc) = 1;
          goto LAB_00106de0;
        }
        ubwcp_power(param_1,0);
      }
    }
    piVar2 = (int *)(param_1 + 0x111d8);
    Hint_Prefetch(piVar2,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar2,0x10);
      if (bVar4) {
        *piVar2 = *piVar2 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    mutex_unlock(lVar1);
    *(undefined4 *)(param_1 + 0x111d4) = 0xfffffffe;
    iVar5 = ___ratelimit(inc_num_non_lin_buffers__rs_210,"inc_num_non_lin_buffers");
    if (iVar5 != 0) {
      _printk(&DAT_00115635,"ubwcp","inc_num_non_lin_buffers",0x267);
    }
    uVar6 = 0xffffffff;
  }
  else {
LAB_00106de0:
    mutex_unlock(lVar1);
    uVar6 = 0;
  }
  return uVar6;
}



//------------------------------------------------------------
// ubwcp_get_buf_attrs @ 00106f20 size=616
// signature: undefined ubwcp_get_buf_attrs(void)
// callers: []
//------------------------------------------------------------

undefined8 ubwcp_get_buf_attrs(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  undefined *puVar7;
  undefined8 uVar8;
  long *plVar9;
  
  lVar2 = me;
  if (param_1 == 0) {
    iVar5 = ___ratelimit(ubwcp_get_buf_attrs__rs,"ubwcp_get_buf_attrs");
    if (iVar5 != 0) {
      puVar7 = &DAT_00116825;
      uVar6 = 0x88f;
      goto LAB_0010713c;
    }
  }
  else {
    if (param_2 != (undefined8 *)0x0) {
      if (me == 0) {
        __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x800,0x106f60);
        (*pcVar4)();
      }
      lVar1 = me + 0x11210;
      uVar6 = _raw_spin_lock_irqsave(lVar1);
      plVar9 = (long *)(lVar2 + ((ulong)(param_1 * 0x61c8864680b583eb) >> 0x33) * 8 + 0x120);
      do {
        plVar9 = (long *)*plVar9;
        if (plVar9 == (long *)0x0) {
          _raw_spin_unlock_irqrestore(lVar1,uVar6);
          iVar5 = ___ratelimit(ubwcp_get_buf_attrs__rs_51,"ubwcp_get_buf_attrs");
          if (iVar5 == 0) {
            return 0xffffffff;
          }
          _printk(&DAT_001164e0,"ubwcp","ubwcp_get_buf_attrs",0x89a);
          return 0xffffffff;
        }
      } while (plVar9[0x12] != param_1);
      _raw_spin_unlock_irqrestore(lVar1,uVar6);
      if (*(int *)(plVar9[2] + 0x111d4) == 0) {
        lVar2 = (long)(plVar9 + 0x1b);
        mutex_lock(lVar2);
        if (*(char *)(plVar9 + 0x10) != '\0') {
          uVar6 = plVar9[5];
          uVar8 = plVar9[3];
          param_2[1] = plVar9[4];
          param_2[2] = uVar6;
          *param_2 = uVar8;
          uVar8 = plVar9[9];
          uVar6 = plVar9[6];
          uVar3 = plVar9[7];
          param_2[5] = plVar9[8];
          param_2[6] = uVar8;
          param_2[3] = uVar6;
          param_2[4] = uVar3;
          uVar8 = plVar9[0xd];
          uVar6 = plVar9[10];
          uVar3 = plVar9[0xb];
          param_2[9] = plVar9[0xc];
          param_2[10] = uVar8;
          param_2[7] = uVar6;
          param_2[8] = uVar3;
          mutex_unlock(lVar2);
          return 0;
        }
        iVar5 = ___ratelimit(ubwcp_get_buf_attrs__rs_55,"ubwcp_get_buf_attrs");
        if (iVar5 != 0) {
          _printk(&DAT_0011533b,"ubwcp","ubwcp_get_buf_attrs",0x8a5);
        }
        mutex_unlock(lVar2);
      }
      else {
        iVar5 = ___ratelimit(ubwcp_get_buf_attrs__rs_53,"ubwcp_get_buf_attrs");
        if (iVar5 != 0) {
          _printk(&DAT_00115096,"ubwcp","ubwcp_get_buf_attrs",0x89f,
                  *(undefined4 *)(plVar9[2] + 0x111d4));
        }
      }
      return 0xffffffff;
    }
    iVar5 = ___ratelimit(ubwcp_get_buf_attrs__rs_50,"ubwcp_get_buf_attrs");
    if (iVar5 != 0) {
      puVar7 = &DAT_001164b4;
      uVar6 = 0x894;
LAB_0010713c:
      _printk(puVar7,"ubwcp","ubwcp_get_buf_attrs",uVar6);
      return 0xffffffea;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// ubwcp_set_perm_range_translation @ 00107194 size=448
// signature: undefined ubwcp_set_perm_range_translation(void)
// callers: []
//------------------------------------------------------------

undefined8 ubwcp_set_perm_range_translation(long param_1)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  undefined *puVar6;
  long *plVar7;
  
  lVar2 = me;
  if (param_1 == 0) {
    iVar4 = ___ratelimit(ubwcp_set_perm_range_translation__rs,"ubwcp_set_perm_range_translation");
    if (iVar4 == 0) {
      uVar5 = 0xffffffea;
    }
    else {
      _printk(&DAT_00116825,"ubwcp","ubwcp_set_perm_range_translation",0x8c0);
      uVar5 = 0xffffffea;
    }
  }
  else {
    if (me == 0) {
      __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1071cc);
      (*pcVar3)();
    }
    lVar1 = me + 0x11210;
    uVar5 = _raw_spin_lock_irqsave(lVar1);
    plVar7 = (long *)(lVar2 + ((ulong)(param_1 * 0x61c8864680b583eb) >> 0x33) * 8 + 0x120);
    do {
      plVar7 = (long *)*plVar7;
      if (plVar7 == (long *)0x0) {
        _raw_spin_unlock_irqrestore(lVar1,uVar5);
        iVar4 = ___ratelimit(ubwcp_set_perm_range_translation__rs_57,
                             "ubwcp_set_perm_range_translation");
        if (iVar4 == 0) goto LAB_0010731c;
        puVar6 = &DAT_001171db;
        uVar5 = 0x8c6;
        goto LAB_00107318;
      }
    } while (plVar7[0x12] != param_1);
    _raw_spin_unlock_irqrestore(lVar1,uVar5);
    if (*(int *)(plVar7[2] + 0x111d4) == 0) {
      iVar4 = ___ratelimit(ubwcp_set_perm_range_translation__rs_60,
                           "ubwcp_set_perm_range_translation");
      if (iVar4 != 0) {
        puVar6 = &DAT_00114e5c;
        uVar5 = 0x8d1;
LAB_00107318:
        _printk(puVar6,"ubwcp","ubwcp_set_perm_range_translation",uVar5);
      }
    }
    else {
      iVar4 = ___ratelimit(ubwcp_set_perm_range_translation__rs_59,
                           "ubwcp_set_perm_range_translation");
      if (iVar4 != 0) {
        _printk(&DAT_00115096,"ubwcp","ubwcp_set_perm_range_translation",0x8cb,
                *(undefined4 *)(plVar7[2] + 0x111d4));
      }
    }
LAB_0010731c:
    uVar5 = 0xffffffff;
  }
  return uVar5;
}



//------------------------------------------------------------
// ubwcp_register_error_handler @ 00107360 size=268
// signature: undefined ubwcp_register_error_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ubwcp_register_error_handler(int param_1,long param_2,long param_3)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  long *plVar4;
  ulong uVar5;
  undefined8 *puVar6;
  
  lVar1 = me;
  if (me == 0) {
    __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1073a0);
    (*pcVar2)();
  }
  uVar3 = 0xffffffea;
  if (((param_2 != 0) && (param_1 == -1)) && (me != 0)) {
    if (*(int *)(me + 0x111d4) == 0) {
      plVar4 = (long *)kmalloc_trace(_devm_kmalloc,0xdc0,0x28);
      if (plVar4 == (long *)0x0) {
        uVar3 = 0xfffffff4;
      }
      else {
        plVar4[3] = param_2;
        plVar4[4] = param_3;
        *(undefined4 *)(plVar4 + 2) = 0xffffffff;
        uVar3 = _raw_spin_lock_irqsave(lVar1 + 0x112e8);
        puVar6 = *(undefined8 **)(lVar1 + 0x112e0);
        uVar5 = __list_add_valid(plVar4,puVar6,lVar1 + 0x112d8);
        if ((uVar5 & 1) != 0) {
          *(long **)(lVar1 + 0x112e0) = plVar4;
          *plVar4 = lVar1 + 0x112d8;
          plVar4[1] = (long)puVar6;
          *puVar6 = plVar4;
        }
        _raw_spin_unlock_irqrestore(lVar1 + 0x112e8,uVar3);
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// ubwcp_unregister_error_handler @ 00107474 size=248
// signature: undefined ubwcp_unregister_error_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 ubwcp_unregister_error_handler(int param_1)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  code *pcVar4;
  undefined8 uVar5;
  ulong uVar6;
  undefined8 uVar7;
  long *plVar8;
  
  if (me == 0) {
    __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x1074ac);
    (*pcVar4)();
  }
  if (*(int *)(me + 0x111d4) == -1) {
    lVar1 = me + 0x112e8;
    plVar2 = (long *)(me + 0x112d8);
    uVar5 = _raw_spin_lock_irqsave(lVar1);
    plVar8 = plVar2;
    do {
      plVar8 = (long *)*plVar8;
      if (plVar8 == plVar2) {
        uVar7 = 0xffffffea;
        goto LAB_00107548;
      }
    } while ((int)plVar8[2] != param_1);
    uVar6 = __list_del_entry_valid(plVar8);
    if ((uVar6 & 1) != 0) {
      lVar3 = *plVar8;
      plVar2 = (long *)plVar8[1];
      *(long **)(lVar3 + 8) = plVar2;
      *plVar2 = lVar3;
    }
    *plVar8 = -0x2152ffffffffff00;
    plVar8[1] = -0x2152fffffffffede;
    kfree(plVar8);
    uVar7 = 0;
LAB_00107548:
    _raw_spin_unlock_irqrestore(lVar1,uVar5);
  }
  else {
    uVar7 = 0xffffffff;
  }
  return uVar7;
}



//------------------------------------------------------------
// ubwcp_iommu_fault_handler @ 0010757c size=544
// signature: undefined ubwcp_iommu_fault_handler(void)
// callers: []
//------------------------------------------------------------

void ubwcp_iommu_fault_handler
               (undefined8 param_1,undefined8 param_2,ulong param_3,undefined4 param_4,long param_5)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  long *plVar7;
  ulong uVar8;
  long lVar9;
  uint uVar10;
  undefined8 uVar11;
  undefined8 local_68;
  undefined8 local_60;
  ulong local_58;
  undefined8 local_50;
  long local_48;
  
  lVar2 = me;
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  local_50 = 0;
  local_68 = 0;
  local_60 = 0;
  if (me == 0) {
    __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1075d4);
    (*pcVar3)();
  }
  local_68 = 3;
  if (*(long *)(me + 0xb8) == param_5) {
    uVar10 = 0;
    local_50 = 0;
  }
  else {
    if (*(long *)(me + 0xc0) == param_5) {
      uVar10 = 1;
    }
    else {
      uVar10 = 2;
    }
    local_50 = (ulong)uVar10;
  }
  lVar1 = me + 0x11210;
  uVar5 = _raw_spin_lock_irqsave(lVar1);
  lVar6 = 0;
  do {
    for (plVar7 = *(long **)(lVar2 + lVar6 * 8 + 0x120); plVar7 != (long *)0x0;
        plVar7 = (long *)*plVar7) {
      if ((long *)plVar7[0x14] != (long *)0x0) {
        lVar9 = *(long *)plVar7[0x14];
        uVar8 = *(ulong *)(lVar9 + 0x10);
        if ((uVar8 <= param_3) && (param_3 < uVar8 + *(uint *)(lVar9 + 0x18))) {
          uVar11 = plVar7[0x12];
          goto LAB_00107684;
        }
      }
    }
    lVar6 = lVar6 + 1;
    if (lVar6 == 0x2000) {
      uVar11 = 0;
LAB_00107684:
      _raw_spin_unlock_irqrestore(lVar1,uVar5);
      local_50 = CONCAT44(param_4,(undefined4)local_50);
      local_60 = uVar11;
      local_58 = param_3;
      iVar4 = ___ratelimit(ubwcp_iommu_fault_handler__rs,"ubwcp_iommu_fault_handler");
      lVar1 = me;
      if (iVar4 != 0) {
        _printk(&DAT_00117360,"ubwcp","ubwcp_iommu_fault_handler",0xbdc,3,uVar10,param_3,param_4);
        lVar1 = me;
      }
      me = lVar1;
      if (lVar1 == 0) {
        __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1076c4);
        (*pcVar3)();
      }
      uVar5 = _raw_spin_lock_irqsave(lVar1 + 0x112e8);
      for (plVar7 = *(long **)(lVar1 + 0x112d8); plVar7 != (long *)(lVar1 + 0x112d8);
          plVar7 = (long *)*plVar7) {
        if (*(int *)((code *)plVar7[3] + -4) != -0x2f58620e) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x107714);
          (*pcVar3)();
        }
        (*(code *)plVar7[3])(&local_68,plVar7[4]);
      }
      _raw_spin_unlock_irqrestore(lVar1 + 0x112e8,uVar5);
      lVar1 = sp_el0;
      if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail(0);
      }
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// ubwcp_probe @ 001077b8 size=3084
// signature: undefined ubwcp_probe(void)
// callers: []
//------------------------------------------------------------

ulong ubwcp_probe(long param_1)

{
  long *plVar1;
  undefined8 *puVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  undefined *puVar9;
  long lVar10;
  ulong uVar11;
  long lVar12;
  char *pcVar13;
  undefined8 uVar14;
  undefined8 *puVar15;
  undefined *local_70;
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  local_70 = &DAT_001159e6;
  iVar4 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2f8),"qcom,ubwcp");
  if (iVar4 == 0) {
    iVar4 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2f8),"qcom,ubwcp-context-bank-desc")
    ;
    if (iVar4 == 0) {
      iVar4 = of_device_is_compatible
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,ubwcp-context-bank-buf");
      if (iVar4 == 0) {
        of_property_read_string(*(undefined8 *)(param_1 + 0x2f8),"compatible",&local_70);
        iVar4 = ___ratelimit(ubwcp_probe__rs,"ubwcp_probe");
        if (iVar4 != 0) {
          _printk(&DAT_0011628e,"ubwcp","ubwcp_probe",0xdbd,local_70);
        }
      }
      else {
        lVar12 = *(long *)(*(long *)(param_1 + 0x70) + 0x98);
        if (lVar12 != 0) {
          *(long *)(lVar12 + 0xc0) = param_1 + 0x10;
          lVar7 = iommu_get_domain_for_dev();
          if (lVar7 != 0) {
            iommu_set_fault_handler(lVar7,ubwcp_iommu_fault_handler,*(undefined8 *)(lVar12 + 0xc0));
          }
          if (*(long *)(lVar12 + 0xb8) != 0) {
            uVar8 = 0;
            *(undefined4 *)(lVar12 + 0x111d4) = 0;
            goto LAB_00107be4;
          }
LAB_00107e6c:
          uVar8 = 0;
          goto LAB_00107be4;
        }
        iVar4 = ___ratelimit(ubwcp_probe_cb_buf__rs,"ubwcp_probe_cb_buf");
        if (iVar4 != 0) {
          _printk(&DAT_00116626,"ubwcp","ubwcp_probe_cb_buf",0xd03);
        }
      }
    }
    else {
      lVar12 = *(long *)(*(long *)(param_1 + 0x70) + 0x98);
      if (lVar12 != 0) {
        plVar1 = (long *)(lVar12 + 0x10120);
        lVar7 = param_1 + 0x10;
        *(undefined8 *)(lVar12 + 0x10130) = 0x4000;
        *(long *)(lVar12 + 0xb8) = lVar7;
        if (*(undefined4 **)(param_1 + 0x2c8) != (undefined4 *)0x0) {
          **(undefined4 **)(param_1 + 0x2c8) = 0xffffffff;
          lVar7 = *(long *)(lVar12 + 0xb8);
        }
        if (*(long *)(lVar7 + 0x2b8) != 0) {
          *(undefined8 *)(*(long *)(lVar7 + 0x2b8) + 8) = 0xffffffffffffffff;
          lVar7 = *(long *)(lVar12 + 0xb8);
        }
        lVar7 = dma_alloc_attrs(lVar7,*(undefined8 *)(lVar12 + 0x10130),
                                (undefined8 *)(lVar12 + 0x10128),0xcc0,0);
        *plVar1 = lVar7;
        if (lVar7 == 0) {
          iVar4 = ___ratelimit(ubwcp_probe_cb_desc__rs_371,"ubwcp_probe_cb_desc");
          if (iVar4 != 0) {
            puVar9 = &DAT_00114efe;
            pcVar13 = "ubwcp_probe_cb_desc";
            uVar14 = 0xd2e;
            goto LAB_00107df8;
          }
          goto LAB_00107974;
        }
        if (ubwcp_debug_trace_enable != 0) {
          _printk(&DAT_001171b4,"ubwcp","ubwcp_probe_cb_desc",lVar7,
                  *(undefined8 *)(lVar12 + 0x10130));
        }
        iVar4 = ubwcp_power(lVar12,1);
        if (iVar4 == 0) {
          ubwcp_hw_set_buf_desc
                    (*(undefined8 *)(lVar12 + 200),*(undefined8 *)(lVar12 + 0x10128),0x40);
          iVar4 = ubwcp_power(lVar12,0);
          if (iVar4 == 0) {
            lVar7 = iommu_get_domain_for_dev(*(undefined8 *)(lVar12 + 0xb8));
            if (lVar7 != 0) {
              iommu_set_fault_handler
                        (lVar7,ubwcp_iommu_fault_handler,*(undefined8 *)(lVar12 + 0xb8));
            }
            if (*(long *)(lVar12 + 0xc0) != 0) {
              uVar8 = 0;
              *(undefined4 *)(lVar12 + 0x111d4) = 0;
              goto LAB_00107be4;
            }
            goto LAB_00107e6c;
          }
          iVar4 = ___ratelimit(ubwcp_probe_cb_desc__rs_376,"ubwcp_probe_cb_desc");
          if (iVar4 != 0) {
            puVar9 = &DAT_00114df8;
            uVar14 = 0xd3f;
            goto LAB_00107fc0;
          }
        }
        else {
          iVar4 = ___ratelimit(ubwcp_probe_cb_desc__rs_374,"ubwcp_probe_cb_desc");
          if (iVar4 != 0) {
            puVar9 = &DAT_00116439;
            uVar14 = 0xd37;
LAB_00107fc0:
            _printk(puVar9,"ubwcp","ubwcp_probe_cb_desc",uVar14);
          }
        }
        dma_free_attrs(*(undefined8 *)(lVar12 + 0xb8),*(undefined8 *)(lVar12 + 0x10130),*plVar1,
                       *(undefined8 *)(lVar12 + 0x10128),0);
        *(undefined8 *)(lVar12 + 0xb8) = 0;
        uVar8 = 0xffffffff;
        *plVar1 = 0;
        *(undefined8 *)(lVar12 + 0x10128) = 0;
        goto LAB_00107be4;
      }
      iVar4 = ___ratelimit(ubwcp_probe_cb_desc__rs,"ubwcp_probe_cb_desc");
      if (iVar4 != 0) {
        _printk(&DAT_00116626,"ubwcp","ubwcp_probe_cb_desc",0xd1b);
      }
    }
    uVar8 = 0xffffffea;
    goto LAB_00107be4;
  }
  lVar12 = param_1 + 0x10;
  lVar7 = devm_kmalloc(lVar12,0x113d0,0xdc0);
  if (lVar7 == 0) {
    iVar4 = ___ratelimit(qcom_ubwcp_probe__rs,"qcom_ubwcp_probe");
    if (iVar4 != 0) {
      puVar9 = &DAT_00115d8a;
      pcVar13 = "qcom_ubwcp_probe";
      uVar14 = 0xc5e;
LAB_00107df8:
      _printk(puVar9,"ubwcp",pcVar13,uVar14);
      uVar8 = 0xfffffff4;
      goto LAB_00107be4;
    }
LAB_00107974:
    uVar8 = 0xfffffff4;
    goto LAB_00107be4;
  }
  *(long *)(lVar7 + 0xb0) = lVar12;
  iVar4 = dma_set_mask(lVar12,0xffffffffffffffff);
  if (iVar4 == 0) {
    dma_set_coherent_mask(lVar12,0xffffffffffffffff);
  }
  uVar8 = devm_platform_ioremap_resource(param_1,0);
  *(ulong *)(lVar7 + 200) = uVar8;
  if (0xfffffffffffff000 < uVar8) {
    iVar4 = ___ratelimit(qcom_ubwcp_probe__rs_218,"qcom_ubwcp_probe");
    if (iVar4 != 0) {
      _printk(&DAT_001162bf,"ubwcp","qcom_ubwcp_probe",0xc68,*(undefined8 *)(lVar7 + 200));
    }
    uVar8 = (ulong)*(uint *)(lVar7 + 200);
    goto LAB_00107be4;
  }
  if (ubwcp_debug_trace_enable != 0) {
    _printk(&DAT_00117eb0,"ubwcp","qcom_ubwcp_probe",uVar8);
  }
  puVar15 = (undefined8 *)(lVar7 + 0xf8);
  uVar5 = of_property_read_u64_index(*(undefined8 *)(param_1 + 0x2f8),"ula_range",0,puVar15);
  if (uVar5 == 0) {
    if (ubwcp_debug_trace_enable != 0) {
      _printk(&DAT_001179c6,"ubwcp","qcom_ubwcp_probe",*puVar15);
    }
    puVar2 = (undefined8 *)(lVar7 + 0x100);
    uVar5 = of_property_read_u64_index(*(undefined8 *)(param_1 + 0x2f8),"ula_range",1,puVar2);
    if (uVar5 == 0) {
      if (ubwcp_debug_trace_enable != 0) {
        _printk(&DAT_0011673d,"ubwcp","qcom_ubwcp_probe",*puVar2);
      }
      *(long *)(lVar7 + 0x112d8) = lVar7 + 0x112d8;
      *(long *)(lVar7 + 0x112e0) = lVar7 + 0x112d8;
      *(undefined4 *)(lVar7 + 0x111d4) = 0xffffffff;
      *(undefined4 *)(lVar7 + 0x111d8) = 0;
      *(undefined1 *)(lVar7 + 0x111dc) = 0;
      __mutex_init(lVar7 + 0x111e0,"&ubwcp->desc_lock",&qcom_ubwcp_probe___key);
      *(undefined4 *)(lVar7 + 0x11210) = 0;
      __mutex_init(lVar7 + 0x11218,"&ubwcp->mem_hotplug_lock",&qcom_ubwcp_probe___key_229);
      __mutex_init(lVar7 + 0x11248,"&ubwcp->ula_lock",&qcom_ubwcp_probe___key_231);
      __mutex_init(lVar7 + 0x11278,"&ubwcp->ubwcp_flush_lock",&qcom_ubwcp_probe___key_233);
      __mutex_init(lVar7 + 0x112a8,"&ubwcp->hw_range_ck_lock",&qcom_ubwcp_probe___key_235);
      __mutex_init(lVar7 + 0x11390,"&ubwcp->power_ctrl_lock",&qcom_ubwcp_probe___key_237);
      *(undefined4 *)(lVar7 + 0x112e8) = 0;
      uVar8 = devm_regulator_get(lVar12,&DAT_00117d6e);
      *(ulong *)(lVar7 + 0xd0) = uVar8;
      if ((uVar8 != 0) && (uVar8 < 0xfffffffffffff001)) {
        uVar5 = of_property_read_string_helper(*(undefined8 *)(param_1 + 0x2f8),"clock-names",0,0,0)
        ;
        *(uint *)(lVar7 + 0xe0) = uVar5;
        if ((int)uVar5 < 1) {
          *(undefined4 *)(lVar7 + 0xe0) = 0;
        }
        else {
          lVar10 = devm_kmalloc(lVar12,(ulong)uVar5 << 3,0xdc0);
          *(long *)(lVar7 + 0xd8) = lVar10;
          if (lVar10 == 0) {
            uVar8 = 0xfffffff4;
LAB_00107f64:
            iVar4 = ___ratelimit(qcom_ubwcp_probe__rs_242,"qcom_ubwcp_probe");
            if (iVar4 == 0) goto LAB_00107be4;
            puVar9 = &DAT_00115901;
            uVar14 = 0xc95;
            goto LAB_00107f98;
          }
          uVar14 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"clock-names",0);
          lVar10 = of_prop_next_string(uVar14,0);
          if (lVar10 != 0) {
            iVar4 = 0;
            do {
              uVar11 = devm_clk_get(lVar12,lVar10);
              if (0xfffffffffffff000 < uVar11) {
                iVar4 = ___ratelimit(ubwcp_init_clocks__rs,"ubwcp_init_clocks");
                if (iVar4 != 0) {
                  _printk(&DAT_00114ec8,"ubwcp","ubwcp_init_clocks",0x15a,lVar10);
                }
                uVar8 = uVar11 & 0xffffffff;
                if ((int)uVar11 != 0) goto LAB_00107f64;
                break;
              }
              *(ulong *)(*(long *)(lVar7 + 0xd8) + (long)iVar4 * 8) = uVar11;
              iVar4 = iVar4 + 1;
              lVar10 = of_prop_next_string(uVar14,lVar10);
            } while (lVar10 != 0);
          }
        }
        iVar4 = ubwcp_power(lVar7,1);
        if ((iVar4 == 0) && (iVar4 = ubwcp_cdev_init(lVar7), iVar4 == 0)) {
          ubwcp_hw_interrupt_enable(*(undefined8 *)(lVar7 + 200),0,0);
          ubwcp_hw_interrupt_enable(*(undefined8 *)(lVar7 + 200),1,0);
          ubwcp_hw_interrupt_enable(*(undefined8 *)(lVar7 + 200),3,0);
          ubwcp_hw_interrupt_enable(*(undefined8 *)(lVar7 + 200),2,0);
          iVar4 = ubwcp_interrupt_register(param_1,lVar7);
          if (iVar4 == 0) {
            ubwcp_debugfs_init(lVar7);
            lVar12 = gen_pool_create(0xc,0xffffffff);
            *(long *)(lVar7 + 0x108) = lVar12;
            if (lVar12 == 0) {
              iVar4 = ___ratelimit(qcom_ubwcp_probe__rs_244,"qcom_ubwcp_probe");
              if (iVar4 != 0) {
                _printk(&DAT_00117d72,"ubwcp","qcom_ubwcp_probe",0xcad);
              }
              uVar8 = 0xffffffff;
            }
            else {
              iVar4 = gen_pool_add_owner(lVar12,*puVar15,0xffffffffffffffff,*puVar2,0xffffffff,0);
              if (iVar4 == 0) {
                *(undefined **)(lVar7 + 0x110) = &msm_ubwcp_dma_buf_configure_mmap;
                memset((void *)(lVar7 + 0x120),0,0x10000);
                lVar12 = 0x100;
                puVar15 = (undefined8 *)(lVar7 + 0x10140);
                do {
                  lVar12 = lVar12 + -1;
                  *(undefined4 *)(puVar15 + -1) = 0xffffffff;
                  *puVar15 = 0;
                  puVar15 = puVar15 + 2;
                } while (lVar12 != 0);
                image_format_init(lVar7);
                ubwcp_hw_one_time_init(*(undefined8 *)(lVar7 + 200));
                ubwcp_hw_single_tile(*(undefined8 *)(lVar7 + 200),1);
                *(undefined1 *)(lVar7 + 0xac) = 1;
                ubwcp_hw_version(*(undefined8 *)(lVar7 + 200),lVar7 + 0x118,lVar7 + 0x11c);
                _printk(&DAT_00117692,"ubwcp","qcom_ubwcp_probe",*(undefined4 *)(lVar7 + 0x118),
                        *(undefined4 *)(lVar7 + 0x11c));
                if (*(int *)(lVar7 + 0x118) == 0) {
                  iVar4 = ___ratelimit(qcom_ubwcp_probe__rs_249,"qcom_ubwcp_probe");
                  if (iVar4 != 0) {
                    _printk(&DAT_00116a0d,"ubwcp","qcom_ubwcp_probe",0xcc7);
                  }
                  goto LAB_00108020;
                }
                cVar3 = *(char *)(lVar7 + 0xa8);
                *(long *)(param_1 + 0xa8) = lVar7;
                if (cVar3 != '\0') {
                  ubwcp_hw_interrupt_enable(*(undefined8 *)(lVar7 + 200),0,1);
                }
                if (*(char *)(lVar7 + 0xa9) != '\0') {
                  ubwcp_hw_interrupt_enable(*(undefined8 *)(lVar7 + 200),1,1);
                }
                if (*(char *)(lVar7 + 0xaa) != '\0') {
                  ubwcp_hw_interrupt_enable(*(undefined8 *)(lVar7 + 200),2,1);
                }
                if (*(char *)(lVar7 + 0xab) != '\0') {
                  ubwcp_hw_interrupt_enable(*(undefined8 *)(lVar7 + 200),3,1);
                }
                iVar4 = ubwcp_power(lVar7,0);
                if (iVar4 == 0) {
                  uVar8 = msm_ubwcp_set_ops(ubwcp_init_buffer,ubwcp_free_buffer,ubwcp_lock,
                                            ubwcp_unlock);
                  if ((int)uVar8 == 0) {
                    if (ubwcp_debug_trace_enable != 0) {
                      _printk(&DAT_00117ecd,"ubwcp","qcom_ubwcp_probe");
                    }
                    uVar8 = 0;
                    me = lVar7;
                    goto LAB_00107be4;
                  }
                  uVar8 = uVar8 & 0xffffffff;
                  iVar4 = ___ratelimit(qcom_ubwcp_probe__rs_251,"qcom_ubwcp_probe");
                  if (iVar4 != 0) {
                    _printk(&DAT_00116769,"ubwcp","qcom_ubwcp_probe",0xce2,uVar8);
                  }
                }
                else {
                  uVar8 = 0xffffffff;
                }
                iVar4 = ubwcp_power(lVar7,1);
                if (iVar4 == 0) {
                  ubwcp_hw_interrupt_enable(*(undefined8 *)(lVar7 + 200),0,0);
                  ubwcp_hw_interrupt_enable(*(undefined8 *)(lVar7 + 200),1,0);
                  ubwcp_hw_interrupt_enable(*(undefined8 *)(lVar7 + 200),3,0);
                  ubwcp_hw_interrupt_enable(*(undefined8 *)(lVar7 + 200),2,0);
                  ubwcp_power(lVar7,0);
                }
              }
              else {
                iVar6 = ___ratelimit(qcom_ubwcp_probe__rs_246,"qcom_ubwcp_probe");
                if (iVar6 != 0) {
                  _printk(&DAT_001178b5,"ubwcp","qcom_ubwcp_probe",0xcb4,iVar4);
                }
LAB_00108020:
                uVar8 = 0xffffffff;
              }
              gen_pool_destroy(*(undefined8 *)(lVar7 + 0x108));
            }
            debugfs_remove(*(undefined8 *)(lVar7 + 0xa0));
            ubwcp_cdev_deinit(lVar7);
            goto LAB_00107be4;
          }
        }
        uVar8 = 0xffffffff;
        goto LAB_00107be4;
      }
      iVar4 = ___ratelimit(qcom_ubwcp_probe__rs_240,"qcom_ubwcp_probe");
      if (iVar4 == 0) goto LAB_00107be4;
      puVar9 = &DAT_001179f2;
      uVar14 = 0xc8f;
    }
    else {
      uVar8 = (ulong)uVar5;
      iVar4 = ___ratelimit(qcom_ubwcp_probe__rs_225,"qcom_ubwcp_probe");
      if (iVar4 == 0) goto LAB_00107be4;
      puVar9 = &DAT_00114a0f;
      uVar14 = 0xc76;
    }
  }
  else {
    uVar8 = (ulong)uVar5;
    iVar4 = ___ratelimit(qcom_ubwcp_probe__rs_222,"qcom_ubwcp_probe");
    if (iVar4 == 0) goto LAB_00107be4;
    puVar9 = &DAT_00116e82;
    uVar14 = 0xc6f;
  }
LAB_00107f98:
  _printk(puVar9,"ubwcp","qcom_ubwcp_probe",uVar14,uVar8 & 0xffffffff);
LAB_00107be4:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8 & 0xffffffff;
}



//------------------------------------------------------------
// ubwcp_remove @ 00108460 size=996
// signature: undefined ubwcp_remove(void)
// callers: []
//------------------------------------------------------------

void ubwcp_remove(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  undefined *puVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined *local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = &DAT_001159e6;
  iVar1 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2f8),"qcom,ubwcp");
  if (iVar1 == 0) {
    iVar1 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2f8),"qcom,ubwcp-context-bank-desc")
    ;
    if (iVar1 == 0) {
      iVar1 = of_device_is_compatible
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,ubwcp-context-bank-buf");
      if (iVar1 == 0) {
        of_property_read_string(*(undefined8 *)(param_1 + 0x2f8),"compatible",&local_40);
        iVar1 = ___ratelimit(ubwcp_remove__rs,"ubwcp_remove");
        if (iVar1 != 0) {
          _printk(&DAT_0011628e,"ubwcp","ubwcp_remove",0xdd4,local_40);
        }
      }
      else {
        lVar2 = *(long *)(*(long *)(param_1 + 0x70) + 0x98);
        if (lVar2 != 0) {
          uVar4 = 0;
          *(undefined8 *)(lVar2 + 0xc0) = 0;
          *(undefined4 *)(lVar2 + 0x111d4) = 0xffffffff;
          goto LAB_00108778;
        }
        iVar1 = ___ratelimit(ubwcp_remove_cb_buf__rs,"ubwcp_remove_cb_buf");
        if (iVar1 != 0) {
          _printk(&DAT_00116626,"ubwcp","ubwcp_remove_cb_buf",0xd5e);
        }
      }
    }
    else {
      lVar2 = *(long *)(*(long *)(param_1 + 0x70) + 0x98);
      if (lVar2 != 0) {
        if (*(long *)(lVar2 + 0xb8) != 0) {
          iVar1 = ubwcp_power(lVar2,1);
          if (iVar1 == 0) {
            ubwcp_hw_set_buf_desc(*(undefined8 *)(lVar2 + 200),0,0);
            ubwcp_power(lVar2,0);
          }
          *(undefined4 *)(lVar2 + 0x111d4) = 0xffffffff;
          dma_free_attrs(*(undefined8 *)(lVar2 + 0xb8),*(undefined8 *)(lVar2 + 0x10130),
                         *(undefined8 *)(lVar2 + 0x10120),*(undefined8 *)(lVar2 + 0x10128),0);
          uVar4 = 0;
          *(undefined8 *)(lVar2 + 0x10120) = 0;
          *(undefined8 *)(lVar2 + 0x10128) = 0;
          goto LAB_00108778;
        }
        iVar1 = ___ratelimit(ubwcp_remove_cb_desc__rs_383,"ubwcp_remove_cb_desc");
        if (iVar1 != 0) {
          puVar5 = &DAT_00116db5;
          pcVar6 = "ubwcp_remove_cb_desc";
          uVar4 = 0xd73;
          goto LAB_001087c0;
        }
        goto LAB_001085e4;
      }
      iVar1 = ___ratelimit(ubwcp_remove_cb_desc__rs,"ubwcp_remove_cb_desc");
      if (iVar1 != 0) {
        _printk(&DAT_00116626,"ubwcp","ubwcp_remove_cb_desc",0xd6e);
      }
    }
    uVar4 = 0xffffffea;
  }
  else {
    puVar7 = *(undefined4 **)(param_1 + 0xa8);
    if (puVar7 != (undefined4 *)0x0) {
      iVar1 = ubwcp_power(puVar7,1);
      if (iVar1 == 0) {
        ubwcp_hw_interrupt_enable(*(undefined8 *)(puVar7 + 0x32),0,0);
        ubwcp_hw_interrupt_enable(*(undefined8 *)(puVar7 + 0x32),1,0);
        ubwcp_hw_interrupt_enable(*(undefined8 *)(puVar7 + 0x32),3,0);
        ubwcp_hw_interrupt_enable(*(undefined8 *)(puVar7 + 0x32),2,0);
        ubwcp_power(puVar7,0);
      }
      puVar7[0x4475] = 0xffffffff;
      lVar2 = gen_pool_avail(*(undefined8 *)(puVar7 + 0x42));
      lVar3 = gen_pool_size(*(undefined8 *)(puVar7 + 0x42));
      if (lVar3 == lVar2) {
        gen_pool_destroy(*(undefined8 *)(puVar7 + 0x42));
      }
      else {
        iVar1 = ___ratelimit(qcom_ubwcp_remove__rs_379,"qcom_ubwcp_remove");
        if (iVar1 != 0) {
          _printk(&DAT_0011646a,"ubwcp","qcom_ubwcp_remove",0xda2,lVar2,lVar3);
        }
        iVar1 = ___ratelimit(qcom_ubwcp_remove__rs_381,"qcom_ubwcp_remove");
        if (iVar1 != 0) {
          _printk(&DAT_00115fdb,"ubwcp","qcom_ubwcp_remove",0xda3);
        }
      }
      debugfs_remove(*(undefined8 *)(puVar7 + 0x28));
      device_destroy(*(undefined8 *)(puVar7 + 2),*puVar7);
      class_destroy(*(undefined8 *)(puVar7 + 2));
      cdev_del(puVar7 + 6);
      unregister_chrdev_region(*puVar7,1);
      uVar4 = 0;
      goto LAB_00108778;
    }
    iVar1 = ___ratelimit(qcom_ubwcp_remove__rs,"qcom_ubwcp_remove");
    if (iVar1 != 0) {
      puVar5 = &DAT_00117545;
      pcVar6 = "qcom_ubwcp_remove";
      uVar4 = 0xd90;
LAB_001087c0:
      _printk(puVar5,"ubwcp",pcVar6,uVar4);
      uVar4 = 0xffffffff;
      goto LAB_00108778;
    }
LAB_001085e4:
    uVar4 = 0xffffffff;
  }
LAB_00108778:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001088e0 size=172
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  int iVar2;
  
  if (ubwcp_debug_trace_enable != 0) {
    _printk(&DAT_001149b3,"ubwcp","ubwcp_init");
  }
  iVar1 = __platform_driver_register(&ubwcp_platform_driver,&__this_module);
  if ((iVar1 != 0) && (iVar2 = ___ratelimit(ubwcp_init__rs,"ubwcp_init"), iVar2 != 0)) {
    _printk(&DAT_001173ca,"ubwcp","ubwcp_init",0xdf1,iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00108990 size=80
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&ubwcp_platform_driver);
  if (ubwcp_debug_trace_enable != 0) {
    _printk(&DAT_00115f36,"ubwcp","ubwcp_exit");
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_ubwcp_platform_device_event @ 001089e4 size=100
// signature: undefined trace_raw_output_ubwcp_platform_device_event(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_ubwcp_platform_device_event
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"platform_device:0x%lx\n",*(undefined8 *)(lVar2 + 8));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_ubwcp_dmabuf_event @ 00108a4c size=100
// signature: undefined trace_raw_output_ubwcp_dmabuf_event(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_ubwcp_dmabuf_event(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"dma-buf:0x%lx\n",*(undefined8 *)(lVar2 + 8));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_ubwcp_size_event @ 00108ab4 size=100
// signature: undefined trace_raw_output_ubwcp_size_event(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_ubwcp_size_event(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"size:%zu\n",*(undefined8 *)(lVar2 + 8));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_ubwcp_sync_event @ 00108b1c size=104
// signature: undefined trace_raw_output_ubwcp_sync_event(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_ubwcp_sync_event(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"size:%zu, dir:%d\n",*(undefined8 *)(lVar2 + 8),
                       *(undefined4 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_ubwcp_int_event @ 00108b88 size=100
// signature: undefined trace_raw_output_ubwcp_int_event(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_ubwcp_int_event(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"value:%d\n",*(undefined4 *)(lVar2 + 8));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// stride_is_valid @ 00108bec size=404
// signature: undefined stride_is_valid(void)
// callers: [ubwcp_set_buf_attrs, ubwcp_ioctl]
//------------------------------------------------------------

undefined8 stride_is_valid(long param_1,uint param_2,int param_3,uint param_4)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  undefined8 uVar6;
  uint uVar7;
  long lVar8;
  uint uVar9;
  
  if (6 < param_2) {
LAB_00108d7c:
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x108d80);
    (*pcVar5)();
  }
  lVar8 = param_1 + (ulong)param_2 * 0x1a;
  uVar1 = *(ushort *)(lVar8 + 0x1113c);
  uVar7 = (uint)*(ushort *)(lVar8 + 0x1113a);
  uVar3 = 0;
  if (uVar1 != 0) {
    uVar3 = (uVar7 * param_3) / (uint)uVar1;
  }
  if ((param_4 < 0x10001) && (uVar3 <= param_4)) {
    if (param_2 == 4) {
      if ((param_4 & 0x3f) == 0) {
        return 1;
      }
      uVar6 = ___ratelimit(stride_is_valid__rs_123,"stride_is_valid");
      if ((int)uVar6 == 0) {
        return uVar6;
      }
      _printk(&DAT_001177a0,"ubwcp","stride_is_valid",0x370,param_4);
    }
    else {
      if (5 < param_2) goto LAB_00108d7c;
      uVar2 = *(ushort *)(param_1 + (ulong)param_2 * 0x1a + 0x11142);
      uVar3 = 0;
      uVar9 = (uint)uVar2;
      if (uVar9 != 0) {
        uVar3 = ((param_3 + (uint)uVar2) - 1) / uVar9;
      }
      uVar4 = 0;
      if (uVar1 != 0) {
        uVar4 = (uVar3 * uVar9 * uVar7) / (uint)uVar1;
      }
      if (uVar4 == param_4) {
        return 1;
      }
      uVar6 = ___ratelimit(stride_is_valid__rs_125,"stride_is_valid");
      if ((int)uVar6 == 0) {
        return uVar6;
      }
      _printk(&DAT_00116e09,"ubwcp","stride_is_valid",0x377,param_4,uVar4);
    }
  }
  else {
    uVar6 = ___ratelimit(stride_is_valid__rs,"stride_is_valid");
    if ((int)uVar6 == 0) {
      return uVar6;
    }
    _printk(&DAT_001155ee,"ubwcp","stride_is_valid",0x36a,param_4,param_3,uVar3);
  }
  return 0;
}



//------------------------------------------------------------
// ubwcp_ula_free @ 00108d80 size=240
// signature: undefined ubwcp_ula_free(void)
// callers: [reset_buf_attrs, ubwcp_ula_realloc]
//------------------------------------------------------------

void ubwcp_ula_free(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  ulong uVar2;
  
  mutex_lock(param_1 + 0x11248);
  uVar2 = gen_pool_has_addr(*(undefined8 *)(param_1 + 0x108),param_2,param_3);
  if ((uVar2 & 1) == 0) {
    iVar1 = ___ratelimit(ubwcp_ula_free__rs,"ubwcp_ula_free");
    if (iVar1 != 0) {
      _printk(&DAT_001170b4,"ubwcp","ubwcp_ula_free",0x58f,param_2,param_3);
    }
  }
  else {
    if (ubwcp_debug_trace_enable != 0) {
      _printk(&DAT_0011655e,"ubwcp","ubwcp_ula_free",param_2,param_3);
    }
    gen_pool_free_owner(*(undefined8 *)(param_1 + 0x108),param_2,param_3,0);
  }
  mutex_unlock(param_1 + 0x11248);
  return;
}



//------------------------------------------------------------
// ubwcp_power @ 00108e70 size=660
// signature: undefined ubwcp_power(void)
// callers: [inc_num_non_lin_buffers, single_tile_w_op, dec_num_non_lin_buffers, ubwcp_probe, decode_err_w_op, ubwcp_remove, write_err_w_op, encode_err_w_op, read_err_w_op]
//------------------------------------------------------------

int ubwcp_power(long param_1,ulong param_2)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  
  mutex_lock(param_1 + 0x11390);
  piVar1 = (int *)(param_1 + 0x11388);
  iVar3 = *piVar1;
  if ((param_2 & 1) == 0) {
    *piVar1 = iVar3 + -1;
    if (iVar3 + -1 == 0) {
      iVar3 = regulator_disable(*(undefined8 *)(param_1 + 0xd0));
      if (iVar3 == 0) {
        if (*(int *)(param_1 + 0xe0) != 0) {
          iVar3 = *(int *)(param_1 + 0xe0) + -1;
          do {
            uVar5 = *(undefined8 *)(*(long *)(param_1 + 0xd8) + (long)iVar3 * 8);
            clk_disable(uVar5);
            clk_unprepare(uVar5);
            iVar3 = iVar3 + -1;
          } while (iVar3 != -1);
        }
        iVar3 = prefetch_tgt(param_1,1);
        goto LAB_00108f2c;
      }
      iVar4 = ___ratelimit(ubwcp_power__rs_160,"ubwcp_power");
      if (iVar4 == 0) goto LAB_00108f2c;
      uVar5 = 0x1a5;
      uVar6 = 0;
LAB_00108f98:
      _printk(&DAT_001172c1,"ubwcp","ubwcp_power",uVar5,uVar6,iVar3);
      goto LAB_00108f2c;
    }
  }
  else {
    *piVar1 = iVar3 + 1;
    if (iVar3 == 0) {
      iVar3 = prefetch_tgt(param_1,0);
      if (iVar3 != 0) goto LAB_00108f2c;
      iVar3 = regulator_enable(*(undefined8 *)(param_1 + 0xd0));
      if (iVar3 != 0) {
        iVar4 = ___ratelimit(ubwcp_power__rs,"ubwcp_power");
        if (iVar4 == 0) goto LAB_00108f2c;
        uVar5 = 0x199;
        uVar6 = 1;
        goto LAB_00108f98;
      }
      if (0 < *(int *)(param_1 + 0xe0)) {
        uVar7 = 0;
        lVar8 = 8;
        do {
          uVar5 = *(undefined8 *)(*(long *)(param_1 + 0xd8) + uVar7 * 8);
          iVar3 = clk_prepare(uVar5);
          if (iVar3 != 0) {
LAB_00109048:
            iVar4 = ___ratelimit(ubwcp_enable_clocks__rs,"ubwcp_enable_clocks");
            if (iVar4 != 0) {
              _printk(&DAT_0011657f,"ubwcp","ubwcp_enable_clocks",0x16c,uVar7 & 0xffffffff);
            }
            if ((int)uVar7 != 0) {
              lVar8 = -lVar8;
              do {
                uVar5 = *(undefined8 *)(*(long *)(param_1 + 0xd8) + lVar8);
                clk_disable(uVar5);
                clk_unprepare(uVar5);
                bVar2 = lVar8 != 0;
                lVar8 = lVar8 + -8;
              } while (bVar2);
            }
            iVar4 = ___ratelimit(ubwcp_power__rs_158,"ubwcp_power");
            if (iVar4 != 0) {
              _printk(&DAT_0011517c,"ubwcp","ubwcp_power",0x19e,iVar3);
            }
            regulator_disable(*(undefined8 *)(param_1 + 0xd0));
            break;
          }
          iVar3 = clk_enable(uVar5);
          if (iVar3 != 0) {
            clk_unprepare(uVar5);
            goto LAB_00109048;
          }
          uVar7 = uVar7 + 1;
          lVar8 = lVar8 + -8;
        } while ((long)uVar7 < (long)*(int *)(param_1 + 0xe0));
        goto LAB_00108f2c;
      }
    }
  }
  iVar3 = 0;
LAB_00108f2c:
  mutex_unlock(param_1 + 0x11390);
  return iVar3;
}



//------------------------------------------------------------
// ula_unmap @ 00109104 size=116
// signature: undefined ula_unmap(void)
// callers: [dec_num_non_lin_buffers]
//------------------------------------------------------------

void ula_unmap(long param_1)

{
  if (ubwcp_debug_trace_enable != 0) {
    _printk(&DAT_00114c6d,"ubwcp","ula_unmap");
  }
  memunmap_pages(param_1 + 0x112f0);
  return;
}



//------------------------------------------------------------
// ula_add_mem @ 001092ac size=356
// signature: undefined ula_add_mem(void)
// callers: [inc_num_non_lin_buffers, dec_num_non_lin_buffers]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ula_add_mem(long param_1)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  if (ubwcp_debug_trace_enable != 0) {
    _printk(&DAT_001177f0,"ubwcp","ula_add_mem");
  }
  *(undefined4 *)(param_1 + 0x11350) = 4;
  *(undefined4 *)(param_1 + 0x11370) = 1;
  *(long *)(param_1 + 0x11378) = *(long *)(param_1 + 0xf8);
  *(long *)(param_1 + 0x11380) = *(long *)(param_1 + 0xf8) + *(long *)(param_1 + 0x100) + -1;
  uVar2 = memremap_pages(param_1 + 0x112f0,0);
  if (uVar2 < 0xfffffffffffff001) {
    if (ubwcp_debug_trace_enable != 0) {
      _printk(&DAT_0011745d,"ubwcp","ula_add_mem",*(ulong *)(param_1 + 0xf8),
              *(undefined8 *)(param_1 + 0x100),
              ((*(ulong *)(param_1 + 0xf8) >> 6 & 0x3ffffffffffffc0) +
               (_memstart_addr >> 0xc) * -0x40 + -0x200000000) * 0x40 & 0xfffffffffff000 |
              0xff00000000000000);
    }
    uVar3 = 0;
  }
  else {
    iVar1 = ___ratelimit(*(undefined8 *)(param_1 + 0x100),ula_add_mem__rs,"ula_add_mem");
    if (iVar1 == 0) {
      uVar3 = 1;
    }
    else {
      uVar3 = 1;
      _printk(&DAT_00115ce4,"ubwcp","ula_add_mem",0x1f6,*(undefined8 *)(param_1 + 0xf8),
              *(undefined8 *)(param_1 + 0x100),1);
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// trace_ubwcp_dma_sync_single_for_cpu_start @ 00109560 size=44
// signature: undefined trace_ubwcp_dma_sync_single_for_cpu_start(void)
// callers: [ubwcp_lock]
//------------------------------------------------------------

void trace_ubwcp_dma_sync_single_for_cpu_start(void)

{
  return;
}



//------------------------------------------------------------
// trace_ubwcp_dma_sync_single_for_cpu_end @ 00109630 size=44
// signature: undefined trace_ubwcp_dma_sync_single_for_cpu_end(void)
// callers: [ubwcp_lock]
//------------------------------------------------------------

void trace_ubwcp_dma_sync_single_for_cpu_end(void)

{
  return;
}



//------------------------------------------------------------
// prefetch_tgt @ 00109700 size=312
// signature: undefined prefetch_tgt(void)
// callers: [ubwcp_power]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 prefetch_tgt(long param_1,byte param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  
  piVar1 = (int *)(param_1 + 0x113c0);
  if (ubwcp_debug_trace_enable != 0) {
    _printk(&DAT_00116963,"ubwcp","prefetch_tgt",param_2 & 1);
  }
  *(byte *)(param_1 + 0x113c4) = param_2 & 1;
  *(undefined4 *)(param_1 + 0x113c8) = 0;
  *piVar1 = 0;
  cpus_read_lock();
  iVar5 = 0;
  while( true ) {
    uVar4 = _find_next_bit(&__cpu_online_mask,_nr_cpu_ids,(long)iVar5);
    if (_nr_cpu_ids <= uVar4) break;
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = *piVar1 + 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    smp_call_function_single(uVar4,prefetch_tgt_per_cpu,piVar1,0);
    iVar5 = uVar4 + 1;
  }
  cpus_read_unlock();
  do {
  } while (*piVar1 != 0);
  if (ubwcp_debug_trace_enable != 0) {
    _printk(&DAT_001163f0,"ubwcp","prefetch_tgt");
  }
  return *(undefined4 *)(param_1 + 0x113c8);
}



//------------------------------------------------------------
// prefetch_tgt_per_cpu @ 00109968 size=128
// signature: undefined prefetch_tgt_per_cpu(void)
// callers: []
//------------------------------------------------------------

void prefetch_tgt_per_cpu(int *param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = qcom_scm_prefetch_tgt_ctrl((char)param_1[1]);
  if ((iVar3 != 0) && (ubwcp_debug_trace_enable != 0)) {
    _printk(&DAT_00115af4,"ubwcp","prefetch_tgt_per_cpu",iVar3);
  }
  Hint_Prefetch(param_1,2,0,1);
  do {
    cVar1 = '\x01';
    bVar2 = (bool)ExclusiveMonitorPass(param_1,0x10);
    if (bVar2) {
      *param_1 = *param_1 + -1;
      cVar1 = ExclusiveMonitorsStatus();
    }
  } while (cVar1 != '\0');
  return;
}



//------------------------------------------------------------
// metadata_buf_sz @ 001099f0 size=812
// signature: undefined metadata_buf_sz(void)
// callers: [ubwcp_calc_ubwcp_buf_params]
//------------------------------------------------------------

void metadata_buf_sz(long param_1,uint param_2,uint param_3,uint param_4,byte param_5,ulong *param_6
                    )

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  long lVar4;
  code *pcVar5;
  int iVar6;
  undefined8 uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined2 local_60;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  if (6 < param_2) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x109cb4);
    (*pcVar5)();
  }
  param_1 = param_1 + (ulong)param_2 * 0x1a;
  local_78 = *(undefined8 *)(param_1 + 0x11138);
  uStack_70 = *(undefined8 *)(param_1 + 0x11140);
  local_68 = *(undefined8 *)(param_1 + 0x11148);
  local_60 = *(undefined2 *)(param_1 + 0x11150);
  if (((ubwcp_debug_trace_enable != 0) &&
      (_printk(&DAT_00115efc,"ubwcp","metadata_buf_sz"), ubwcp_debug_trace_enable != 0)) &&
     (_printk(&DAT_00115efc,"ubwcp","metadata_buf_sz"), ubwcp_debug_trace_enable != 0)) {
    _printk(&DAT_00117e21,"ubwcp","metadata_buf_sz",param_2,param_5);
  }
  if (param_5 < (ushort)local_78) {
    uVar8 = ((ulong)param_5 + (ulong)param_5 * 2) * 4;
    if ((0x16 < uVar8) || (0x14 < uVar8)) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(1,0x109cb8);
      (*pcVar5)();
    }
    lVar4 = (ulong)param_5 * 0xc;
    uVar1 = *(ushort *)((long)&local_78 + lVar4 + 6);
    uVar10 = (ulong)uVar1;
    param_3 = param_3 >> (param_5 == 1);
    param_4 = param_4 >> (ulong)(param_5 == 1);
    uVar2 = *(ushort *)(((long)&local_78 + lVar4 | 2U) + 6);
    uVar8 = 0;
    if (uVar10 != 0) {
      uVar8 = ((param_3 + uVar10) - 1) / uVar10;
    }
    uVar8 = uVar8 + 0x3f & 0xffffffffffffffc0;
    uVar3 = 0;
    if (uVar2 != 0) {
      uVar3 = ((param_4 + uVar2) - 1) / (uint)uVar2;
    }
    uVar9 = (ulong)(uVar3 + 0xf & 0xfffffff0);
    if (((ubwcp_debug_trace_enable != 0) &&
        (_printk(&DAT_00118023,"ubwcp","metadata_buf_sz",(ulong)param_3,param_4),
        ubwcp_debug_trace_enable != 0)) &&
       (_printk(&DAT_00117819,"ubwcp","metadata_buf_sz",uVar10,(uint)uVar2),
       ubwcp_debug_trace_enable != 0)) {
      uVar3 = 0;
      if (uVar1 != 0) {
        uVar3 = param_3 / uVar1;
      }
      _printk(&DAT_0011784a,"ubwcp","metadata_buf_sz",uVar8,uVar3);
      if (ubwcp_debug_trace_enable != 0) {
        _printk(&DAT_00114ea0,"ubwcp","metadata_buf_sz",uVar9,param_4);
        if (ubwcp_debug_trace_enable != 0) {
          _printk(&DAT_00114fe4,"ubwcp","metadata_buf_sz",uVar8 * uVar9);
          iVar6 = ubwcp_debug_trace_enable;
          uVar8 = uVar8 * uVar9 + 0xfff & 0xfffffffffffff000;
          *param_6 = uVar8;
          if (iVar6 != 0) {
            _printk(&DAT_001166ff,"ubwcp","metadata_buf_sz",uVar8,uVar8);
          }
          uVar7 = 0;
          goto LAB_00109b24;
        }
      }
    }
    uVar7 = 0;
    *param_6 = uVar8 * uVar9 + 0xfff & 0xfffffffffffff000;
  }
  else {
    iVar6 = ___ratelimit(metadata_buf_sz__rs,"metadata_buf_sz");
    if (iVar6 != 0) {
      _printk(&DAT_00116220,"ubwcp","metadata_buf_sz",0x41b,param_2,(ushort)param_5);
    }
    uVar7 = 0xffffffff;
  }
LAB_00109b24:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// pixeldata_buf_sz @ 00109d1c size=892
// signature: undefined pixeldata_buf_sz(void)
// callers: [ubwcp_calc_ubwcp_buf_params]
//------------------------------------------------------------

void pixeldata_buf_sz(long param_1,ushort param_2,uint param_3,uint param_4,byte param_5,
                     ulong *param_6)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  ushort *puVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined2 local_60;
  long local_58;
  
  lVar10 = sp_el0;
  local_58 = *(long *)(lVar10 + 0x638);
  if (6 < param_2) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10a094);
    (*pcVar1)();
  }
  param_1 = param_1 + (ulong)param_2 * 0x1a;
  local_78 = *(undefined8 *)(param_1 + 0x11138);
  uStack_70 = *(undefined8 *)(param_1 + 0x11140);
  local_68 = *(undefined8 *)(param_1 + 0x11148);
  local_60 = *(undefined2 *)(param_1 + 0x11150);
  if (ubwcp_debug_trace_enable != 0) {
    _printk(&DAT_00115efc,"ubwcp","pixeldata_buf_sz");
    if (ubwcp_debug_trace_enable != 0) {
      _printk(&DAT_00115efc,"ubwcp","pixeldata_buf_sz");
      if (ubwcp_debug_trace_enable != 0) {
        _printk(&DAT_00117e68,"ubwcp","pixeldata_buf_sz",param_2,param_5);
      }
    }
  }
  if (param_5 < (ushort)local_78) {
    lVar10 = (ulong)param_5 + (ulong)param_5 * 2;
    if ((((0x1c < (lVar10 * 4 | 2U)) || (uVar4 = lVar10 * 4, 0x18 < uVar4)) || (param_5 == 2)) ||
       ((0x12 < uVar4 || (0x10 < uVar4)))) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(1,0x10a090);
      (*pcVar1)();
    }
    puVar5 = (ushort *)((long)&local_78 + uVar4 | 2);
    uVar6 = (ulong)puVar5[4];
    uVar7 = (ulong)puVar5[5];
    uVar9 = (ulong)*puVar5;
    uVar8 = (ulong)puVar5[1];
    uVar4 = 0;
    if (uVar6 != 0) {
      uVar4 = (((param_3 >> (param_5 == 1)) + uVar6) - 1) / uVar6;
    }
    lVar10 = uVar4 * uVar6;
    uVar4 = 0;
    if (uVar7 != 0) {
      uVar4 = (((param_4 >> (ulong)(param_5 == 1)) + uVar7) - 1) / uVar7;
    }
    lVar11 = uVar4 * uVar7;
    if (ubwcp_debug_trace_enable != 0) {
      _printk(&DAT_00118023,"ubwcp","pixeldata_buf_sz");
      if (ubwcp_debug_trace_enable != 0) {
        _printk(&DAT_00114d13,"ubwcp","pixeldata_buf_sz",uVar6,uVar7);
        if (ubwcp_debug_trace_enable != 0) {
          _printk(&DAT_00115b84,"ubwcp","pixeldata_buf_sz",uVar9,uVar8);
          if (ubwcp_debug_trace_enable != 0) {
            _printk(&DAT_00118054,"ubwcp","pixeldata_buf_sz",lVar10);
            if ((ubwcp_debug_trace_enable != 0) &&
               (_printk(&DAT_00117cf8,"ubwcp","pixeldata_buf_sz",lVar11),
               ubwcp_debug_trace_enable != 0)) {
              uVar4 = 0;
              if (uVar8 != 0) {
                uVar4 = (lVar11 * lVar10 * uVar9) / uVar8;
              }
              _printk(&DAT_00114fe4,"ubwcp","pixeldata_buf_sz",uVar4);
              iVar2 = ubwcp_debug_trace_enable;
              uVar4 = uVar4 + 0xfff & 0xfffffffffffff000;
              *param_6 = uVar4;
              if (iVar2 != 0) {
                _printk(&DAT_001166ff,"ubwcp","pixeldata_buf_sz",uVar4,uVar4);
              }
              uVar3 = 0;
              goto LAB_00109e88;
            }
          }
        }
      }
    }
    uVar3 = 0;
    uVar4 = 0;
    if (uVar8 != 0) {
      uVar4 = (lVar11 * lVar10 * uVar9) / uVar8;
    }
    *param_6 = uVar4 + 0xfff & 0xfffffffffffff000;
  }
  else {
    iVar2 = ___ratelimit(pixeldata_buf_sz__rs,"pixeldata_buf_sz");
    if (iVar2 != 0) {
      _printk(&DAT_00116220,"ubwcp","pixeldata_buf_sz",0x456,param_2,(ushort)param_5);
    }
    uVar3 = 0xffffffff;
  }
LAB_00109e88:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// ubwcp_cdev_init @ 0010a098 size=576
// signature: undefined ubwcp_cdev_init(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

ulong ubwcp_cdev_init(undefined4 *param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  uVar2 = alloc_chrdev_region(&local_3c,0,1,"ubwcp");
  if (uVar2 == 0) {
    uVar4 = __class_create(&__this_module,"ubwcp_class",&ubwcp_cdev_init___key);
    if (uVar4 < 0xfffffffffffff001) {
      uVar6 = device_create(uVar4,0,local_3c,0,"ubwcp");
      if (uVar6 < 0xfffffffffffff001) {
        cdev_init(param_1 + 6,&ubwcp_fops);
        uVar5 = cdev_add(param_1 + 6,local_3c,1);
        if ((int)uVar5 == 0) {
          *(ulong *)(param_1 + 2) = uVar4;
          *(ulong *)(param_1 + 4) = uVar6;
          uVar6 = 0;
          *param_1 = local_3c;
          goto LAB_0010a23c;
        }
        uVar6 = uVar5 & 0xffffffff;
        iVar3 = ___ratelimit(ubwcp_cdev_init__rs_262,"ubwcp_cdev_init");
        if (iVar3 != 0) {
          _printk(&DAT_00115baa,"ubwcp","ubwcp_cdev_init",0xb1a,uVar6);
        }
        device_destroy(uVar4,local_3c);
      }
      else {
        iVar3 = ___ratelimit(ubwcp_cdev_init__rs_260,"ubwcp_cdev_init");
        if (iVar3 == 0) {
          uVar6 = uVar6 & 0xffffffff;
        }
        else {
          _printk(&DAT_00114a6a,"ubwcp","ubwcp_cdev_init",0xb0e,uVar6 & 0xffffffff);
          uVar6 = uVar6 & 0xffffffff;
        }
      }
      class_destroy(uVar4);
    }
    else {
      iVar3 = ___ratelimit(ubwcp_cdev_init__rs_258,"ubwcp_cdev_init");
      uVar6 = uVar4;
      if (iVar3 != 0) {
        _printk(&DAT_00115203,"ubwcp","ubwcp_cdev_init",0xb03,uVar4 & 0xffffffff);
      }
    }
    unregister_chrdev_region(local_3c,1);
  }
  else {
    uVar6 = (ulong)uVar2;
    iVar3 = ___ratelimit(ubwcp_cdev_init__rs,"ubwcp_cdev_init");
    if (iVar3 != 0) {
      _printk(&DAT_00114d55,"ubwcp","ubwcp_cdev_init",0xafb,uVar6);
    }
  }
LAB_0010a23c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// ubwcp_interrupt_register @ 0010a2d8 size=636
// signature: undefined ubwcp_interrupt_register(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

int ubwcp_interrupt_register(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  
  iVar1 = platform_get_irq(param_1,0);
  *(int *)(param_2 + 0xe4) = iVar1;
  if (-1 < iVar1) {
    iVar1 = platform_get_irq(param_1,1);
    *(int *)(param_2 + 0xe8) = iVar1;
    if (-1 < iVar1) {
      iVar1 = platform_get_irq(param_1,2);
      *(int *)(param_2 + 0xec) = iVar1;
      if (-1 < iVar1) {
        iVar1 = platform_get_irq(param_1,3);
        *(int *)(param_2 + 0xf0) = iVar1;
        if (iVar1 < 0) {
          return iVar1;
        }
        param_1 = param_1 + 0x10;
        if (ubwcp_debug_trace_enable != 0) {
          _printk(&DAT_00115240,"ubwcp","ubwcp_interrupt_register",*(undefined4 *)(param_2 + 0xe4),
                  *(undefined4 *)(param_2 + 0xe8),*(undefined4 *)(param_2 + 0xec),iVar1);
        }
        iVar1 = devm_request_threaded_irq
                          (param_1,*(undefined4 *)(param_2 + 0xe4),ubwcp_irq_handler,0,0,"ubwcp",
                           param_2);
        if (iVar1 == 0) {
          iVar1 = devm_request_threaded_irq
                            (param_1,*(undefined4 *)(param_2 + 0xe8),ubwcp_irq_handler,0,0,"ubwcp",
                             param_2);
          if (iVar1 == 0) {
            iVar1 = devm_request_threaded_irq
                              (param_1,*(undefined4 *)(param_2 + 0xec),ubwcp_irq_handler,0,0,"ubwcp"
                               ,param_2);
            if (iVar1 == 0) {
              iVar1 = devm_request_threaded_irq
                                (param_1,*(undefined4 *)(param_2 + 0xf0),ubwcp_irq_handler,0,0,
                                 "ubwcp",param_2);
              if (iVar1 == 0) {
                return 0;
              }
              iVar2 = ___ratelimit(ubwcp_interrupt_register__rs_292,"ubwcp_interrupt_register");
              if (iVar2 == 0) {
                return iVar1;
              }
              uVar4 = *(undefined4 *)(param_2 + 0xf0);
              uVar3 = 0xc4e;
            }
            else {
              iVar2 = ___ratelimit(ubwcp_interrupt_register__rs_291,"ubwcp_interrupt_register");
              if (iVar2 == 0) {
                return iVar1;
              }
              uVar4 = *(undefined4 *)(param_2 + 0xec);
              uVar3 = 0xc47;
            }
          }
          else {
            iVar2 = ___ratelimit(ubwcp_interrupt_register__rs_290,"ubwcp_interrupt_register");
            if (iVar2 == 0) {
              return iVar1;
            }
            uVar4 = *(undefined4 *)(param_2 + 0xe8);
            uVar3 = 0xc40;
          }
        }
        else {
          iVar2 = ___ratelimit(ubwcp_interrupt_register__rs,"ubwcp_interrupt_register");
          if (iVar2 == 0) {
            return iVar1;
          }
          uVar4 = *(undefined4 *)(param_2 + 0xe4);
          uVar3 = 0xc39;
        }
        _printk(&DAT_00117a30,"ubwcp","ubwcp_interrupt_register",uVar3,uVar4,iVar1);
        return iVar1;
      }
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// ubwcp_debugfs_init @ 0010a554 size=776
// signature: undefined ubwcp_debugfs_init(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

void ubwcp_debugfs_init(long param_1)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  undefined *puVar4;
  undefined8 uVar5;
  
  uVar2 = debugfs_create_dir("ubwcp",0);
  if ((uVar2 == 0) || (0xfffffffffffff000 < uVar2)) {
    iVar1 = ___ratelimit(ubwcp_debugfs_init__rs,"ubwcp_debugfs_init");
    if (iVar1 == 0) {
      return;
    }
    _printk(&DAT_00116303,"ubwcp","ubwcp_debugfs_init",0xab7);
    return;
  }
  debugfs_create_u32("debug_trace_enable",0x1a4,uVar2,&ubwcp_debug_trace_enable);
  uVar3 = debugfs_create_file("reg_rw_trace_en",0x1a4,uVar2,param_1,&reg_rw_trace_fops);
  if ((uVar3 == 0) || (0xfffffffffffff000 < uVar3)) {
    iVar1 = ___ratelimit(ubwcp_debugfs_init__rs_305,"ubwcp_debugfs_init");
    if (iVar1 == 0) goto LAB_0010a840;
    puVar4 = &DAT_00115499;
    uVar5 = 0xabf;
  }
  else {
    uVar3 = debugfs_create_file("read_err_irq_en",0x1a4,uVar2,param_1,&read_err_fops);
    if ((uVar3 == 0) || (0xfffffffffffff000 < uVar3)) {
      iVar1 = ___ratelimit(ubwcp_debugfs_init__rs_308,"ubwcp_debugfs_init");
      if (iVar1 == 0) goto LAB_0010a840;
      puVar4 = &DAT_001165dd;
      uVar5 = 0xac5;
    }
    else {
      uVar3 = debugfs_create_file("write_err_irq_en",0x1a4,uVar2,param_1,&write_err_fops);
      if ((uVar3 == 0) || (0xfffffffffffff000 < uVar3)) {
        iVar1 = ___ratelimit(ubwcp_debugfs_init__rs_311,"ubwcp_debugfs_init");
        if (iVar1 == 0) goto LAB_0010a840;
        puVar4 = &DAT_00116eee;
        uVar5 = 0xacb;
      }
      else {
        uVar3 = debugfs_create_file("decode_err_irq_en",0x1a4,uVar2,param_1,&decode_err_fops);
        if ((uVar3 == 0) || (0xfffffffffffff000 < uVar3)) {
          iVar1 = ___ratelimit(ubwcp_debugfs_init__rs_314,"ubwcp_debugfs_init");
          if (iVar1 == 0) goto LAB_0010a840;
          puVar4 = &DAT_001154e5;
          uVar5 = 0xad2;
        }
        else {
          uVar3 = debugfs_create_file("encode_err_irq_en",0x1a4,uVar2,param_1,&encode_err_fops);
          if ((uVar3 == 0) || (0xfffffffffffff000 < uVar3)) {
            iVar1 = ___ratelimit(ubwcp_debugfs_init__rs_317,"ubwcp_debugfs_init");
            if (iVar1 == 0) goto LAB_0010a840;
            puVar4 = &DAT_00115972;
            uVar5 = 0xad9;
          }
          else {
            uVar3 = debugfs_create_file("single_tile_en",0x1a4,uVar2,param_1,&single_tile_fops);
            if ((uVar3 != 0) && (uVar3 < 0xfffffffffffff001)) {
              *(ulong *)(param_1 + 0xa0) = uVar2;
              return;
            }
            iVar1 = ___ratelimit(ubwcp_debugfs_init__rs_320,"ubwcp_debugfs_init");
            if (iVar1 == 0) goto LAB_0010a840;
            puVar4 = &DAT_00116eee;
            uVar5 = 0xadf;
          }
        }
      }
    }
  }
  _printk(puVar4,"ubwcp","ubwcp_debugfs_init",uVar5);
LAB_0010a840:
  debugfs_remove(*(undefined8 *)(param_1 + 0xa0));
  *(undefined8 *)(param_1 + 0xa0) = 0;
  return;
}



//------------------------------------------------------------
// image_format_init @ 0010a85c size=216
// signature: undefined image_format_init(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

void image_format_init(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  *(undefined4 *)(param_1 + 0x11140) = 0x400004;
  uVar1 = DAT_001109b8;
  *(undefined2 *)(param_1 + 0x11144) = 0x10;
  uVar2 = DAT_001109c0;
  *(undefined8 *)(param_1 + 0x11154) = uVar1;
  uVar1 = DAT_001109c8;
  *(undefined8 *)(param_1 + 0x1115c) = uVar2;
  *(undefined8 *)(param_1 + 0x11146) = 0;
  *(undefined8 *)(param_1 + 0x11164) = uVar1;
  uVar3 = DAT_001109e0;
  *(undefined4 *)(param_1 + 0x1114e) = 0;
  uVar2 = DAT_001109d8;
  *(undefined8 *)(param_1 + 0x11138) = 0x10000100040001;
  uVar1 = DAT_001109d0;
  *(undefined8 *)(param_1 + 0x1117e) = uVar3;
  uVar3 = DAT_001109e8;
  *(undefined8 *)(param_1 + 0x11176) = uVar2;
  uVar2 = DAT_001109f0;
  *(undefined8 *)(param_1 + 0x1116e) = uVar1;
  uVar4 = DAT_00110a00;
  *(undefined8 *)(param_1 + 0x111a2) = uVar3;
  uVar5 = DAT_00110a10;
  uVar3 = DAT_00110a08;
  *(undefined2 *)(param_1 + 0x11152) = 2;
  uVar1 = DAT_001109f8;
  *(undefined2 *)(param_1 + 0x1116c) = 2;
  *(undefined2 *)(param_1 + 0x11186) = 2;
  *(undefined8 *)(param_1 + 0x11188) = uVar4;
  *(undefined8 *)(param_1 + 0x11190) = uVar3;
  *(undefined8 *)(param_1 + 0x11198) = uVar5;
  *(undefined2 *)(param_1 + 0x111a0) = 2;
  *(undefined8 *)(param_1 + 0x111aa) = uVar2;
  *(undefined8 *)(param_1 + 0x111b2) = uVar1;
  *(undefined2 *)(param_1 + 0x111ba) = 2;
  *(undefined8 *)(param_1 + 0x111bc) = uVar4;
  *(undefined8 *)(param_1 + 0x111c4) = uVar3;
  *(undefined8 *)(param_1 + 0x111cc) = uVar5;
  return;
}



//------------------------------------------------------------
// ubwcp_init_buffer @ 0010a938 size=668
// signature: undefined ubwcp_init_buffer(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ubwcp_init_buffer(long param_1)

{
  int *piVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  code *pcVar5;
  int iVar6;
  undefined8 uVar7;
  long *plVar8;
  long lVar9;
  
  lVar4 = me;
  if (me == 0) {
    __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x10a970);
    (*pcVar5)();
  }
  if (me != 0) {
    piVar1 = (int *)(me + 0x111d4);
    if (*piVar1 == 0) {
      if (param_1 == 0) {
        iVar6 = ___ratelimit(ubwcp_init_buffer__rs_326,"ubwcp_init_buffer");
        if (iVar6 != 0) {
          _printk(&DAT_00116825,"ubwcp","ubwcp_init_buffer",0x2b0);
        }
        return 0xffffffea;
      }
      if (me == 0) {
        __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x10aa78);
        (*pcVar5)();
      }
      lVar2 = me + 0x11210;
      uVar7 = _raw_spin_lock_irqsave(lVar2);
      plVar8 = (long *)(lVar4 + ((ulong)(param_1 * 0x61c8864680b583eb) >> 0x33) * 8 + 0x120);
      do {
        plVar8 = (long *)*plVar8;
        if (plVar8 == (long *)0x0) {
          _raw_spin_unlock_irqrestore(lVar2,uVar7);
          plVar8 = (long *)kmalloc_trace(_devm_platform_ioremap_resource,0xdc0,0x108);
          if (plVar8 == (long *)0x0) {
            iVar6 = ___ratelimit(ubwcp_init_buffer__rs_329,"ubwcp_init_buffer");
            if (iVar6 != 0) {
              _printk(&DAT_00116c6b,"ubwcp","ubwcp_init_buffer",0x2bd);
            }
            return 0xfffffff4;
          }
          __mutex_init(plVar8 + 0x1b,"&buf->lock",&ubwcp_init_buffer___key);
          plVar8[0x12] = param_1;
          plVar8[2] = lVar4;
          *(undefined2 *)(plVar8 + 3) = 0;
          uVar7 = _raw_spin_lock_irqsave(lVar4 + 0x11210);
          lVar2 = lVar4 + ((ulong)(plVar8[0x12] * 0x61c8864680b583eb) >> 0x33) * 8;
          lVar9 = *(long *)(lVar2 + 0x120);
          plVar3 = (long *)(lVar2 + 0x120);
          *plVar8 = lVar9;
          if (lVar9 != 0) {
            *(long **)(lVar9 + 8) = plVar8;
          }
          *plVar3 = (long)plVar8;
          plVar8[1] = (long)plVar3;
          _raw_spin_unlock_irqrestore(lVar4 + 0x11210,uVar7);
          return 0;
        }
      } while (plVar8[0x12] != param_1);
      _raw_spin_unlock_irqrestore(lVar2,uVar7);
      iVar6 = ___ratelimit(ubwcp_init_buffer__rs_327,"ubwcp_init_buffer");
      if (iVar6 != 0) {
        _printk(&DAT_00117158,"ubwcp","ubwcp_init_buffer",0x2b6);
      }
      return 0xffffffef;
    }
    iVar6 = ___ratelimit(ubwcp_init_buffer__rs,"ubwcp_init_buffer");
    if (iVar6 != 0) {
      _printk(&DAT_00115096,"ubwcp","ubwcp_init_buffer",0x2aa,*piVar1);
    }
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// ubwcp_free_buffer @ 0010b01c size=888
// signature: undefined ubwcp_free_buffer(void)
// callers: []
//------------------------------------------------------------

int ubwcp_free_buffer(long param_1)

{
  long lVar1;
  int *piVar2;
  long lVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  long *plVar9;
  long lVar10;
  long *plVar11;
  long lVar12;
  
  lVar12 = me;
  if (param_1 == 0) {
    iVar6 = ___ratelimit(ubwcp_free_buffer__rs,"ubwcp_free_buffer");
    if (iVar6 != 0) {
      _printk(&DAT_00116825,"ubwcp","ubwcp_free_buffer",0x8fb);
    }
    iVar6 = -0x16;
  }
  else {
    if (me == 0) {
      __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x800,0x10b064);
      (*pcVar5)();
    }
    lVar1 = me + 0x11210;
    uVar8 = _raw_spin_lock_irqsave(lVar1);
    plVar11 = (long *)(lVar12 + ((ulong)(param_1 * 0x61c8864680b583eb) >> 0x33) * 8 + 0x120);
    do {
      plVar11 = (long *)*plVar11;
      if (plVar11 == (long *)0x0) {
        _raw_spin_unlock_irqrestore(lVar1,uVar8);
        iVar6 = ___ratelimit(ubwcp_free_buffer__rs_332,"ubwcp_free_buffer");
        if (iVar6 != 0) {
          _printk(&DAT_001164e0,"ubwcp","ubwcp_free_buffer",0x902);
        }
        goto LAB_0010b1b4;
      }
    } while (plVar11[0x12] != param_1);
    _raw_spin_unlock_irqrestore(lVar1,uVar8);
    lVar12 = plVar11[2];
    piVar2 = (int *)(lVar12 + 0x111d4);
    if (*piVar2 == 0) {
      mutex_lock(plVar11 + 0x1b);
      lVar1 = plVar11[3];
      if ((int)plVar11[0x11] == 0) {
        iVar6 = 0;
      }
      else {
        if (ubwcp_debug_trace_enable != 0) {
          _printk(&DAT_00116a45,"ubwcp","ubwcp_free_buffer");
        }
        iVar6 = unlock_internal(plVar11,*(undefined4 *)((long)plVar11 + 0x84),1);
        if ((iVar6 != 0) &&
           (iVar7 = ___ratelimit(ubwcp_free_buffer__rs_335,"ubwcp_free_buffer"), iVar7 != 0)) {
          _printk(&DAT_00117b55,"ubwcp","ubwcp_free_buffer",0x915,iVar6);
        }
      }
      if (plVar11[0xf] != 0) {
        if ((char)plVar11[0xe] == '\0') {
          *piVar2 = -2;
          iVar7 = ___ratelimit(ubwcp_free_buffer__rs_337,"ubwcp_free_buffer");
          if (iVar7 != 0) {
            _printk(&DAT_00115635,"ubwcp","ubwcp_free_buffer",0x91c);
          }
        }
        iVar7 = *(int *)plVar11[0xf];
        lVar10 = plVar11[2] + 0x111e0;
        lVar3 = plVar11[2] + (long)iVar7 * 0x10;
        mutex_lock(lVar10);
        *(undefined4 *)(lVar3 + 0x10138) = 0xffffffff;
        iVar4 = ubwcp_debug_trace_enable;
        *(undefined8 *)(lVar3 + 0x10140) = 0;
        if (iVar4 != 0) {
          _printk(&DAT_00114aa8,"ubwcp","ubwcp_buf_desc_free",iVar7);
        }
        mutex_unlock(lVar10);
        plVar11[0xf] = 0;
      }
      if ((char)plVar11[0x10] != '\0') {
        reset_buf_attrs(plVar11);
      }
      uVar8 = _raw_spin_lock_irqsave(lVar12 + 0x11210);
      plVar9 = (long *)plVar11[1];
      if (plVar9 != (long *)0x0) {
        lVar10 = *plVar11;
        *plVar9 = lVar10;
        if (lVar10 != 0) {
          *(long **)(lVar10 + 8) = plVar9;
        }
        *plVar11 = 0;
        plVar11[1] = 0;
      }
      _raw_spin_unlock_irqrestore(lVar12 + 0x11210,uVar8);
      mutex_unlock(plVar11 + 0x1b);
      kfree(plVar11);
      if ((short)lVar1 != 0) {
        dec_num_non_lin_buffers(lVar12);
      }
    }
    else {
      iVar6 = ___ratelimit(ubwcp_free_buffer__rs_333,"ubwcp_free_buffer");
      if (iVar6 != 0) {
        _printk(&DAT_00115096,"ubwcp","ubwcp_free_buffer",0x909,*piVar2);
      }
LAB_0010b1b4:
      iVar6 = -1;
    }
  }
  return iVar6;
}



//------------------------------------------------------------
// ubwcp_lock @ 0010b68c size=1360
// signature: undefined ubwcp_lock(void)
// callers: []
//------------------------------------------------------------

int ubwcp_lock(long param_1,uint param_2)

{
  long lVar1;
  int *piVar2;
  undefined8 uVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  undefined *puVar8;
  long lVar9;
  undefined8 *puVar10;
  undefined8 uVar11;
  long lVar12;
  long *plVar13;
  
  lVar12 = me;
  if (param_1 == 0) {
    iVar5 = ___ratelimit(ubwcp_lock__rs,"ubwcp_lock");
    if (iVar5 != 0) {
      _printk(&DAT_00116825,"ubwcp","ubwcp_lock",0x78e);
    }
    return -0x16;
  }
  if (2 < param_2) {
    iVar5 = ___ratelimit(ubwcp_lock__rs_345,"ubwcp_lock");
    if (iVar5 == 0) {
      return -0x16;
    }
    _printk(&DAT_00114acd,"ubwcp","ubwcp_lock",0x794,param_2);
    return -0x16;
  }
  if (me == 0) {
    __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x10b7b4);
    (*pcVar4)();
  }
  lVar1 = me + 0x11210;
  uVar7 = _raw_spin_lock_irqsave(lVar1);
  plVar13 = (long *)(lVar12 + ((ulong)(param_1 * 0x61c8864680b583eb) >> 0x33) * 8 + 0x120);
  do {
    plVar13 = (long *)*plVar13;
    if (plVar13 == (long *)0x0) {
      _raw_spin_unlock_irqrestore(lVar1,uVar7);
      iVar5 = ___ratelimit(ubwcp_lock__rs_347,"ubwcp_lock");
      if (iVar5 == 0) {
        return -1;
      }
      _printk(&DAT_001164e0,"ubwcp","ubwcp_lock",0x79b);
      return -1;
    }
  } while (plVar13[0x12] != param_1);
  _raw_spin_unlock_irqrestore(lVar1,uVar7);
  lVar12 = plVar13[2];
  piVar2 = (int *)(lVar12 + 0x111d4);
  if (*piVar2 != 0) {
    iVar5 = ___ratelimit(ubwcp_lock__rs_348,"ubwcp_lock");
    if (iVar5 != 0) {
      _printk(&DAT_00115096,"ubwcp","ubwcp_lock",0x7a2,*piVar2);
    }
    return -1;
  }
  lVar1 = (long)(plVar13 + 0x1b);
  mutex_lock(lVar1);
  if (*(char *)(plVar13 + 0x10) == '\0') {
    iVar5 = ___ratelimit(ubwcp_lock__rs_349,"ubwcp_lock");
    if (iVar5 != 0) {
      puVar8 = &DAT_00115e29;
      uVar7 = 0x7aa;
LAB_0010bc80:
      _printk(puVar8,"ubwcp","ubwcp_lock",uVar7);
    }
  }
  else {
    if (*(short *)(plVar13 + 3) != 0) {
      if (*(int *)(plVar13 + 0x11) != 0) {
        if (ubwcp_debug_trace_enable != 0) {
          _printk(&DAT_00115076,"ubwcp","ubwcp_lock");
        }
        if ((param_2 == 1) || (*(uint *)((long)plVar13 + 0x84) != 1)) {
          if (*(uint *)((long)plVar13 + 0x84) != param_2) {
            *(undefined4 *)((long)plVar13 + 0x84) = 0;
          }
          goto LAB_0010bc00;
        }
        iVar5 = ___ratelimit(ubwcp_lock__rs_361,"ubwcp_lock");
        if (iVar5 != 0) {
          _printk(&DAT_00114da6,"ubwcp","ubwcp_lock",0x803);
        }
        iVar5 = -0x16;
        goto LAB_0010ba08;
      }
      if (ubwcp_debug_trace_enable == 0) {
        lVar9 = plVar13[0xf];
      }
      else {
        _printk(&DAT_00115e71,"ubwcp","ubwcp_lock");
        lVar9 = plVar13[0xf];
      }
      if (lVar9 == 0) {
        lVar9 = ubwcp_buf_desc_allocate(plVar13[2]);
        plVar13[0xf] = lVar9;
        if (lVar9 == 0) {
          iVar5 = ___ratelimit(ubwcp_lock__rs_354,"ubwcp_lock");
          if (iVar5 != 0) {
            puVar8 = &DAT_001152a9;
            uVar7 = 0x7bb;
            goto LAB_0010bc80;
          }
          goto LAB_0010ba04;
        }
        puVar10 = *(undefined8 **)(lVar9 + 8);
        uVar7 = plVar13[0x18];
        uVar3 = plVar13[0x19];
        uVar11 = plVar13[0x17];
        *(undefined4 *)(puVar10 + 3) = *(undefined4 *)(plVar13 + 0x1a);
        iVar5 = ubwcp_debug_trace_enable;
        puVar10[1] = uVar7;
        puVar10[2] = uVar3;
        *puVar10 = uVar11;
        if (iVar5 != 0) {
          _printk(&DAT_00116d6c,"ubwcp","ubwcp_lock",*(undefined4 *)plVar13[0xf],plVar13[0x15],
                  plVar13[0x16]);
        }
        ubwcp_hw_set_range_check
                  (*(undefined8 *)(lVar12 + 200),*(undefined4 *)plVar13[0xf],plVar13[0x15],
                   plVar13[0x16]);
      }
      if (ubwcp_debug_trace_enable != 0) {
        _printk(&DAT_00117ba9,"ubwcp","ubwcp_lock",*(undefined4 *)plVar13[0xf]);
      }
      range_check_enable(lVar12,*(undefined4 *)plVar13[0xf]);
      iVar5 = ubwcp_flush(lVar12);
      if (iVar5 == 0) {
        if ((param_2 & 0xfffffffd) == 0) {
          trace_ubwcp_dma_sync_single_for_cpu_start(plVar13[0x16],param_2);
          dma_sync_single_for_cpu
                    (*(undefined8 *)(lVar12 + 0xb0),plVar13[0x15],plVar13[0x16],param_2);
          trace_ubwcp_dma_sync_single_for_cpu_end(plVar13[0x16],param_2);
        }
        *(uint *)((long)plVar13 + 0x84) = param_2;
LAB_0010bc00:
        iVar5 = ubwcp_debug_trace_enable;
        *(int *)(plVar13 + 0x11) = *(int *)(plVar13 + 0x11) + 1;
        if (iVar5 != 0) {
          _printk(&DAT_00116a8a,"ubwcp","ubwcp_lock");
        }
        mutex_unlock(lVar1);
        trace_ubwcp_lock_end(param_1);
        return 0;
      }
      *piVar2 = -2;
      iVar6 = ___ratelimit(ubwcp_lock__rs_359,"ubwcp_lock");
      if (iVar6 != 0) {
        _printk(&DAT_00115635,"ubwcp","ubwcp_lock",0x7ea);
      }
      range_check_disable(lVar12,*(undefined4 *)plVar13[0xf]);
      ubwcp_buf_desc_free(lVar12,plVar13[0xf]);
      plVar13[0xf] = 0;
      goto LAB_0010ba08;
    }
    iVar5 = ___ratelimit(ubwcp_lock__rs_351,"ubwcp_lock");
    if (iVar5 != 0) {
      puVar8 = &DAT_00116f7e;
      uVar7 = 0x7af;
      goto LAB_0010bc80;
    }
  }
LAB_0010ba04:
  iVar5 = -1;
LAB_0010ba08:
  mutex_unlock(lVar1);
  return iVar5;
}



//------------------------------------------------------------
// ubwcp_unlock @ 0010bf5c size=632
// signature: undefined ubwcp_unlock(void)
// callers: []
//------------------------------------------------------------

undefined4 ubwcp_unlock(long param_1,uint param_2)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  long *plVar7;
  
  lVar2 = me;
  if (param_1 == 0) {
    iVar4 = ___ratelimit(ubwcp_unlock__rs,"ubwcp_unlock");
    if (iVar4 != 0) {
      _printk(&DAT_00116825,"ubwcp","ubwcp_unlock",0x862);
    }
  }
  else {
    if (param_2 < 3) {
      if (me == 0) {
        __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x10c07c);
        (*pcVar3)();
      }
      lVar1 = me + 0x11210;
      uVar6 = _raw_spin_lock_irqsave(lVar1);
      plVar7 = (long *)(lVar2 + ((ulong)(param_1 * 0x61c8864680b583eb) >> 0x33) * 8 + 0x120);
      do {
        plVar7 = (long *)*plVar7;
        if (plVar7 == (long *)0x0) {
          _raw_spin_unlock_irqrestore(lVar1,uVar6);
          iVar4 = ___ratelimit(ubwcp_unlock__rs_366,"ubwcp_unlock");
          if (iVar4 == 0) {
            return 0xffffffff;
          }
          _printk(&DAT_001171db,"ubwcp","ubwcp_unlock",0x86f);
          return 0xffffffff;
        }
      } while (plVar7[0x12] != param_1);
      _raw_spin_unlock_irqrestore(lVar1,uVar6);
      if (*(int *)(plVar7[2] + 0x111d4) == 0) {
        lVar2 = (long)(plVar7 + 0x1b);
        mutex_lock(lVar2);
        if (*(int *)(plVar7 + 0x11) != 0) {
          uVar5 = unlock_internal(plVar7,param_2,0);
          mutex_unlock(lVar2);
          return uVar5;
        }
        iVar4 = ___ratelimit(ubwcp_unlock__rs_368,"ubwcp_unlock");
        if (iVar4 != 0) {
          _printk(&DAT_00116cab,"ubwcp","ubwcp_unlock",0x87c);
        }
        mutex_unlock(lVar2);
      }
      else {
        iVar4 = ___ratelimit(ubwcp_unlock__rs_367,"ubwcp_unlock");
        if (iVar4 != 0) {
          _printk(&DAT_00115096,"ubwcp","ubwcp_unlock",0x875,*(undefined4 *)(plVar7[2] + 0x111d4));
        }
      }
      return 0xffffffff;
    }
    iVar4 = ___ratelimit(ubwcp_unlock__rs_365,"ubwcp_unlock");
    if (iVar4 != 0) {
      _printk(&DAT_00114acd,"ubwcp","ubwcp_unlock",0x868,param_2);
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// ubwcp_cdev_deinit @ 0010c5e8 size=76
// signature: undefined ubwcp_cdev_deinit(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

void ubwcp_cdev_deinit(undefined4 *param_1)

{
  device_destroy(*(undefined8 *)(param_1 + 2),*param_1);
  class_destroy(*(undefined8 *)(param_1 + 2));
  cdev_del(param_1 + 6);
  unregister_chrdev_region(*param_1,1);
  return;
}



//------------------------------------------------------------
// ubwcp_ioctl @ 0010c638 size=3284
// signature: undefined ubwcp_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ubwcp_ioctl(undefined8 param_1,uint param_2,ulong param_3)

{
  int *piVar1;
  ulong uVar2;
  ushort uVar3;
  code *pcVar4;
  undefined2 uVar5;
  int iVar6;
  long lVar7;
  size_t sVar8;
  long lVar9;
  undefined *puVar10;
  char *pcVar11;
  undefined8 uVar12;
  ulong uVar13;
  undefined8 *puVar14;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar7 = me;
  lVar9 = sp_el0;
  local_48 = *(long *)(lVar9 + 0x638);
  if (me == 0) {
    __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x10c684);
    (*pcVar4)();
  }
  piVar1 = (int *)(me + 0x111d4);
  if (*piVar1 != 0) {
    iVar6 = ___ratelimit(ubwcp_ioctl__rs,"ubwcp_ioctl");
    if (iVar6 == 0) {
      lVar7 = -1;
    }
    else {
      _printk(&DAT_00115096,"ubwcp","ubwcp_ioctl",0x9cb,*piVar1);
      lVar7 = -1;
    }
    goto LAB_0010cff8;
  }
  if ((int)param_2 < -0x3febaafc) {
    if (param_2 == 0x80085502) {
      if (ubwcp_debug_trace_enable != 0) {
        _printk(&DAT_00115c5f,"ubwcp","ioctl_get_hw_ver");
        if (me == 0) {
          __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x800,0x10d1c8);
          (*pcVar4)();
        }
      }
      if (*(int *)(me + 0x111d4) == -1) goto LAB_0010cff4;
      puVar14 = (undefined8 *)sp_el0;
      local_a8 = CONCAT44(*(undefined4 *)(me + 0x11c),*(undefined4 *)(me + 0x118));
      if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
         (uVar13 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
        uVar13 = param_3 & (long)(param_3 << 8) >> 8;
      }
      if (uVar13 < 0x7ffffffff9) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar13 = daif;
          if ((uVar13 & 0x80) == 0) {
            uVar2 = daif;
            daif = uVar2 | 0xc0;
          }
          puVar14 = (undefined8 *)puVar14[1];
          uVar2 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar14 & 0xffff000000000000 | uVar2 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar14;
          InstructionSynchronizationBarrier();
          daif = uVar13;
        }
        lVar9 = __arch_copy_to_user(puVar14,param_3 & 0xff7fffffffffffff,&local_a8,8);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar13 = daif;
          if ((uVar13 & 0x80) == 0) {
            uVar2 = daif;
            daif = uVar2 | 0xc0;
          }
          uVar2 = ttbr1_el1;
          ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar2 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar13;
        }
        lVar7 = 0;
        if (lVar9 == 0) goto LAB_0010cff8;
      }
      iVar6 = ___ratelimit(ioctl_get_hw_ver__rs,"ioctl_get_hw_ver");
      if (iVar6 != 0) {
        _printk(&DAT_00115f82,"ubwcp","ioctl_get_hw_ver",0x961);
      }
    }
    else {
      if (param_2 != 0xc0085503) goto LAB_0010c954;
      local_a8 = 0;
      if (ubwcp_debug_trace_enable != 0) {
        _printk(&DAT_001165b8,"ubwcp","ioctl_get_stride_align");
      }
      puVar14 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
         (uVar13 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
        uVar13 = param_3 & (long)(param_3 << 8) >> 8;
      }
      if (uVar13 < 0x7ffffffff9) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar13 = daif;
          if ((uVar13 & 0x80) == 0) {
            uVar2 = daif;
            daif = uVar2 | 0xc0;
          }
          uVar2 = ttbr1_el1;
          ttbr1_el1 = puVar14[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar14[1];
          InstructionSynchronizationBarrier();
          daif = uVar13;
        }
        sVar8 = __arch_copy_from_user(&local_a8,param_3 & 0xff7fffffffffffff,8);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar13 = daif;
          if ((uVar13 & 0x80) == 0) {
            uVar2 = daif;
            daif = uVar2 | 0xc0;
          }
          uVar2 = ttbr1_el1;
          ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar2 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar13;
        }
        if (sVar8 == 0) {
          if (local_a8._4_4_ == 0) {
            uVar3 = (ushort)local_a8;
            if ((ushort)local_a8 < 0x11) {
              if ((ushort)local_a8 == 0) {
                iVar6 = ___ratelimit(ioctl_get_stride_align__rs_276,"ioctl_get_stride_align");
                if (iVar6 != 0) {
                  _printk(&DAT_00115a1d,"ubwcp","ioctl_get_stride_align",0x97e);
                }
              }
              else {
                if ((ushort)local_a8 < 0x11) {
                  local_a8 = (ulong)CONCAT22(*(undefined2 *)
                                              (&DAT_001180f0 +
                                              (long)(short)((ushort)local_a8 - 1) * 2),
                                             (ushort)local_a8);
                  if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
                     (uVar13 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
                    uVar13 = param_3 & (long)(param_3 << 8) >> 8;
                  }
                  if (uVar13 < 0x7ffffffff9) {
                    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                      uVar13 = daif;
                      if ((uVar13 & 0x80) == 0) {
                        uVar2 = daif;
                        daif = uVar2 | 0xc0;
                      }
                      uVar2 = ttbr1_el1;
                      ttbr1_el1 = puVar14[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
                      InstructionSynchronizationBarrier();
                      ttbr0_el1 = puVar14[1];
                      InstructionSynchronizationBarrier();
                      daif = uVar13;
                    }
                    lVar9 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,&local_a8,8);
                    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                      uVar13 = daif;
                      if ((uVar13 & 0x80) == 0) {
                        uVar2 = daif;
                        daif = uVar2 | 0xc0;
                      }
                      uVar2 = ttbr1_el1;
                      ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
                      InstructionSynchronizationBarrier();
                      ttbr1_el1 = uVar2 & 0xffffffffffff;
                      InstructionSynchronizationBarrier();
                      daif = uVar13;
                    }
                    lVar7 = 0;
                    if (lVar9 == 0) goto LAB_0010cff8;
                  }
                  iVar6 = ___ratelimit(ioctl_get_stride_align__rs_281,"ioctl_get_stride_align");
                  if (iVar6 != 0) {
                    puVar10 = &DAT_00115f82;
                    pcVar11 = "ioctl_get_stride_align";
                    uVar12 = 0x98e;
                    goto LAB_0010ce78;
                  }
                  goto LAB_0010ca9c;
                }
                iVar6 = ___ratelimit(to_std_format__rs,"to_std_format");
                if (iVar6 != 0) {
                  _printk(&DAT_001153d5,"ubwcp","to_std_format",0x303,uVar3);
                }
                iVar6 = ___ratelimit(ioctl_get_stride_align__rs_278,"ioctl_get_stride_align");
                if (iVar6 != 0) {
                  _printk(&DAT_00117f9e,"ubwcp","ioctl_get_stride_align",0x983);
                }
              }
            }
            else {
              iVar6 = ___ratelimit(ioctl_get_stride_align__rs_275,"ioctl_get_stride_align");
              if (iVar6 != 0) {
                param_2 = (uint)(ushort)local_a8;
                puVar10 = &DAT_001157eb;
                pcVar11 = "ioctl_get_stride_align";
                uVar12 = 0x979;
                goto LAB_0010c98c;
              }
            }
          }
          else {
            iVar6 = ___ratelimit(ioctl_get_stride_align__rs_273,"ioctl_get_stride_align");
            if (iVar6 != 0) {
              _printk(&DAT_0011711b,"ubwcp","ioctl_get_stride_align",0x974);
            }
          }
          goto LAB_0010cff4;
        }
      }
      else {
        sVar8 = 8;
      }
      memset((void *)((long)&uStack_a0 - sVar8),0,sVar8);
      iVar6 = ___ratelimit(ioctl_get_stride_align__rs,"ioctl_get_stride_align");
      if (iVar6 != 0) {
        puVar10 = &DAT_001159e7;
        pcVar11 = "ioctl_get_stride_align";
        uVar12 = 0x96f;
LAB_0010ce78:
        _printk(puVar10,"ubwcp",pcVar11,uVar12);
      }
    }
  }
  else {
    if (param_2 != 0xc0145504) {
      if (param_2 == 0x40605501) {
        local_58 = 0;
        uStack_50 = 0;
        puVar14 = (undefined8 *)sp_el0;
        local_68 = 0;
        uStack_60 = 0;
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        uStack_80 = 0;
        local_98 = 0;
        uStack_90 = 0;
        local_a8 = 0;
        uStack_a0 = 0;
        if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
           (uVar13 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
          uVar13 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (uVar13 < 0x7fffffffa1) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar13 = daif;
            if ((uVar13 & 0x80) == 0) {
              uVar2 = daif;
              daif = uVar2 | 0xc0;
            }
            puVar14 = (undefined8 *)puVar14[1];
            uVar2 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar14 & 0xffff000000000000 | uVar2 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar14;
            InstructionSynchronizationBarrier();
            daif = uVar13;
          }
          sVar8 = __arch_copy_from_user(puVar14,&local_a8,param_3 & 0xff7fffffffffffff,0x60);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar13 = daif;
            if ((uVar13 & 0x80) == 0) {
              uVar2 = daif;
              daif = uVar2 | 0xc0;
            }
            uVar2 = ttbr1_el1;
            ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar2 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar13;
          }
          if (sVar8 == 0) {
            if (ubwcp_debug_trace_enable != 0) {
              _printk(&DAT_00116ec4,"ubwcp","ioctl_set_buf_attr",local_a8 & 0xffffffff);
            }
            uVar13 = dma_buf_get(local_a8 & 0xffffffff);
            if (uVar13 < 0xfffffffffffff001) {
              iVar6 = ubwcp_set_buf_attrs(uVar13,&uStack_a0);
              dma_buf_put(uVar13);
              lVar7 = (long)iVar6;
            }
            else {
              iVar6 = ___ratelimit(ioctl_set_buf_attr__rs_268,"ioctl_set_buf_attr");
              if (iVar6 != 0) {
                _printk(&DAT_00115c18,"ubwcp","ioctl_set_buf_attr",0x950,local_a8 & 0xffffffff);
              }
              lVar7 = (long)(int)uVar13;
            }
            goto LAB_0010cff8;
          }
        }
        else {
          sVar8 = 0x60;
        }
        memset((void *)((long)&local_48 - sVar8),0,sVar8);
        iVar6 = ___ratelimit(ioctl_set_buf_attr__rs,"ioctl_set_buf_attr");
        if (iVar6 != 0) {
          _printk(&DAT_001159e7,"ubwcp","ioctl_set_buf_attr",0x949);
        }
        lVar7 = -0xe;
        goto LAB_0010cff8;
      }
LAB_0010c954:
      iVar6 = ___ratelimit(ubwcp_ioctl__rs_264,"ubwcp_ioctl");
      if (iVar6 != 0) {
        puVar10 = &DAT_00115be3;
        pcVar11 = "ubwcp_ioctl";
        uVar12 = 0x9dd;
LAB_0010c98c:
        _printk(puVar10,"ubwcp",pcVar11,uVar12,param_2);
      }
LAB_0010cff4:
      lVar7 = -0x16;
      goto LAB_0010cff8;
    }
    local_98 = local_98 & 0xffffffff00000000;
    local_a8 = 0;
    uStack_a0 = 0;
    if (ubwcp_debug_trace_enable != 0) {
      _printk(&DAT_001178ed,"ubwcp","ioctl_validate_stride");
    }
    puVar14 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
       (uVar13 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
      uVar13 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar13 < 0x7fffffffed) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar13 = daif;
        if ((uVar13 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr1_el1 = puVar14[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar14[1];
        InstructionSynchronizationBarrier();
        daif = uVar13;
      }
      sVar8 = __arch_copy_from_user(&local_a8,param_3 & 0xff7fffffffffffff,0x14);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar13 = daif;
        if ((uVar13 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar13;
      }
      if (sVar8 == 0) {
        if (uStack_a0._6_2_ == 0 && (short)local_98 == 0) {
          uVar3 = (ushort)local_a8;
          if ((ushort)local_a8 < 0x11) {
            if ((ushort)local_a8 == 0) {
              iVar6 = ___ratelimit(ioctl_validate_stride__rs_285,"ioctl_validate_stride");
              if (iVar6 != 0) {
                _printk(&DAT_00115a1d,"ubwcp","ioctl_validate_stride",0x9ac);
              }
            }
            else {
              if ((ushort)local_a8 < 0x11) {
                uVar5 = stride_is_valid(lVar7,*(undefined4 *)
                                               (&DAT_00110a18 +
                                               (long)(short)((ushort)local_a8 - 1) * 4),
                                        local_a8._4_4_,uStack_a0 & 0xffffffff);
                uStack_a0 = CONCAT26(uStack_a0._6_2_,CONCAT24(uVar5,(undefined4)uStack_a0)) &
                            0xffff0001ffffffff;
                if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
                   (uVar13 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
                  uVar13 = param_3 & (long)(param_3 << 8) >> 8;
                }
                if (uVar13 < 0x7fffffffed) {
                  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                    uVar13 = daif;
                    if ((uVar13 & 0x80) == 0) {
                      uVar2 = daif;
                      daif = uVar2 | 0xc0;
                    }
                    uVar2 = ttbr1_el1;
                    ttbr1_el1 = puVar14[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
                    InstructionSynchronizationBarrier();
                    ttbr0_el1 = puVar14[1];
                    InstructionSynchronizationBarrier();
                    daif = uVar13;
                  }
                  lVar9 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,&local_a8,0x14);
                  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                    uVar13 = daif;
                    if ((uVar13 & 0x80) == 0) {
                      uVar2 = daif;
                      daif = uVar2 | 0xc0;
                    }
                    uVar2 = ttbr1_el1;
                    ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
                    InstructionSynchronizationBarrier();
                    ttbr1_el1 = uVar2 & 0xffffffffffff;
                    InstructionSynchronizationBarrier();
                    daif = uVar13;
                  }
                  lVar7 = 0;
                  if (lVar9 == 0) goto LAB_0010cff8;
                }
                iVar6 = ___ratelimit(ioctl_validate_stride__rs_287,"ioctl_validate_stride");
                if (iVar6 == 0) goto LAB_0010ca9c;
                puVar10 = &DAT_00115f82;
                pcVar11 = "ioctl_validate_stride";
                uVar12 = 0x9ba;
                goto LAB_0010ce78;
              }
              iVar6 = ___ratelimit(to_std_format__rs,"to_std_format");
              if (iVar6 != 0) {
                _printk(&DAT_001153d5,"ubwcp","to_std_format",0x303,uVar3);
              }
              iVar6 = ___ratelimit(ioctl_validate_stride__rs_286,"ioctl_validate_stride");
              if (iVar6 != 0) {
                _printk(&DAT_00117f9e,"ubwcp","ioctl_validate_stride",0x9b1);
              }
            }
          }
          else {
            iVar6 = ___ratelimit(ioctl_validate_stride__rs_284,"ioctl_validate_stride");
            if (iVar6 != 0) {
              _printk(&DAT_00115a1d,"ubwcp","ioctl_validate_stride",0x9a7);
            }
          }
        }
        else {
          iVar6 = ___ratelimit(ioctl_validate_stride__rs_283,"ioctl_validate_stride");
          if (iVar6 != 0) {
            _printk(&DAT_0011711b,"ubwcp","ioctl_validate_stride",0x9a2);
          }
        }
        goto LAB_0010cff4;
      }
    }
    else {
      sVar8 = 0x14;
    }
    memset((void *)((long)&local_98 + (4 - sVar8)),0,sVar8);
    iVar6 = ___ratelimit(ioctl_validate_stride__rs,"ioctl_validate_stride");
    if (iVar6 != 0) {
      puVar10 = &DAT_001159e7;
      pcVar11 = "ioctl_validate_stride";
      uVar12 = 0x99d;
      goto LAB_0010ce78;
    }
  }
LAB_0010ca9c:
  lVar7 = -0xe;
LAB_0010cff8:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar7);
  }
  return;
}



//------------------------------------------------------------
// ubwcp_open @ 0010d3b4 size=8
// signature: undefined ubwcp_open(void)
// callers: []
//------------------------------------------------------------

undefined8 ubwcp_open(void)

{
  return 0;
}



//------------------------------------------------------------
// ubwcp_close @ 0010d3c0 size=8
// signature: undefined ubwcp_close(void)
// callers: []
//------------------------------------------------------------

undefined8 ubwcp_close(void)

{
  return 0;
}



//------------------------------------------------------------
// ubwcp_irq_handler @ 0010d3cc size=1784
// signature: undefined ubwcp_irq_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 ubwcp_irq_handler(int param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  ulong uVar8;
  undefined8 uVar9;
  ulong local_68;
  undefined8 local_60;
  ulong local_58;
  ulong local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  local_50 = 0;
  uVar4 = *(undefined8 *)(param_2 + 200);
  local_68 = 0;
  local_60 = 0;
  if (*(int *)(param_2 + 0xe4) == param_1) {
    lVar5 = ubwcp_hw_interrupt_src_address(uVar4,0);
    lVar1 = me;
    uVar8 = lVar5 * 0x40;
    local_68 = CONCAT44(local_68._4_4_,2);
    if (me == 0) {
      __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10d444);
      (*pcVar2)();
    }
    lVar5 = me + 0x11210;
    uVar4 = _raw_spin_lock_irqsave(lVar5);
    lVar6 = 0;
    do {
      for (plVar7 = *(long **)(lVar1 + lVar6 * 8 + 0x120); plVar7 != (long *)0x0;
          plVar7 = (long *)*plVar7) {
        if (((ulong)plVar7[0x15] <= uVar8) && (uVar8 < (ulong)(plVar7[0x16] + plVar7[0x15]))) {
          uVar9 = plVar7[0x12];
          goto LAB_0010d4ac;
        }
      }
      lVar6 = lVar6 + 1;
    } while (lVar6 != 0x2000);
    uVar9 = 0;
LAB_0010d4ac:
    _raw_spin_unlock_irqrestore(lVar5,uVar4);
    local_50 = CONCAT71(local_50._1_7_,1);
    local_60 = uVar9;
    local_58 = uVar8;
    iVar3 = ___ratelimit(ubwcp_irq_handler__rs,"ubwcp_irq_handler");
    lVar1 = me;
    if (iVar3 != 0) {
      _printk(&DAT_00116c0b,"ubwcp","ubwcp_irq_handler",0xbf4,2,uVar9,1,uVar8);
      lVar1 = me;
    }
    me = lVar1;
    if (lVar1 == 0) {
      __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10d4f0);
      (*pcVar2)();
    }
    uVar4 = _raw_spin_lock_irqsave(lVar1 + 0x112e8);
    for (plVar7 = *(long **)(lVar1 + 0x112d8); plVar7 != (long *)(lVar1 + 0x112d8);
        plVar7 = (long *)*plVar7) {
      if (*(int *)((code *)plVar7[3] + -4) != -0x2f58620e) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10d540);
        (*pcVar2)();
      }
      (*(code *)plVar7[3])(&local_68,plVar7[4]);
    }
    _raw_spin_unlock_irqrestore(lVar1 + 0x112e8,uVar4);
    uVar4 = *(undefined8 *)(param_2 + 200);
    uVar9 = 0;
  }
  else {
    if (*(int *)(param_2 + 0xe8) == param_1) {
      lVar5 = ubwcp_hw_interrupt_src_address(uVar4,1);
      lVar1 = me;
      uVar8 = lVar5 * 0x40;
      local_68 = CONCAT44(local_68._4_4_,2);
      if (me == 0) {
        __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10d5a4);
        (*pcVar2)();
      }
      lVar5 = me + 0x11210;
      uVar4 = _raw_spin_lock_irqsave(lVar5);
      lVar6 = 0;
      do {
        for (plVar7 = *(long **)(lVar1 + lVar6 * 8 + 0x120); plVar7 != (long *)0x0;
            plVar7 = (long *)*plVar7) {
          if (((ulong)plVar7[0x15] <= uVar8) && (uVar8 < (ulong)(plVar7[0x16] + plVar7[0x15]))) {
            uVar9 = plVar7[0x12];
            goto LAB_0010d60c;
          }
        }
        lVar6 = lVar6 + 1;
      } while (lVar6 != 0x2000);
      uVar9 = 0;
LAB_0010d60c:
      _raw_spin_unlock_irqrestore(lVar5,uVar4);
      local_50 = local_50 & 0xffffffffffffff00;
      local_60 = uVar9;
      local_58 = uVar8;
      iVar3 = ___ratelimit(ubwcp_irq_handler__rs_294,"ubwcp_irq_handler");
      lVar1 = me;
      if (iVar3 != 0) {
        _printk(&DAT_00117a74,"ubwcp","ubwcp_irq_handler",0xbff,2,uVar9,0,uVar8);
        lVar1 = me;
      }
      me = lVar1;
      if (lVar1 == 0) {
        __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10d64c);
        (*pcVar2)();
      }
      uVar4 = _raw_spin_lock_irqsave(lVar1 + 0x112e8);
      for (plVar7 = *(long **)(lVar1 + 0x112d8); plVar7 != (long *)(lVar1 + 0x112d8);
          plVar7 = (long *)*plVar7) {
        if (*(int *)((code *)plVar7[3] + -4) != -0x2f58620e) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10d69c);
          (*pcVar2)();
        }
        (*(code *)plVar7[3])(&local_68,plVar7[4]);
      }
      _raw_spin_unlock_irqrestore(lVar1 + 0x112e8,uVar4);
      uVar4 = 1;
      ubwcp_hw_interrupt_clear(*(undefined8 *)(param_2 + 200),1);
      goto LAB_0010d97c;
    }
    if (*(int *)(param_2 + 0xec) == param_1) {
      lVar5 = ubwcp_hw_interrupt_src_address(uVar4,3);
      lVar1 = me;
      uVar8 = lVar5 * 0x40;
      local_68 = local_68 & 0xffffffff00000000;
      if (me == 0) {
        __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10d704);
        (*pcVar2)();
      }
      lVar5 = me + 0x11210;
      uVar4 = _raw_spin_lock_irqsave(lVar5);
      lVar6 = 0;
      do {
        for (plVar7 = *(long **)(lVar1 + lVar6 * 8 + 0x120); plVar7 != (long *)0x0;
            plVar7 = (long *)*plVar7) {
          if (((ulong)plVar7[0x15] <= uVar8) && (uVar8 < (ulong)(plVar7[0x16] + plVar7[0x15]))) {
            uVar9 = plVar7[0x12];
            goto LAB_0010d76c;
          }
        }
        lVar6 = lVar6 + 1;
      } while (lVar6 != 0x2000);
      uVar9 = 0;
LAB_0010d76c:
      _raw_spin_unlock_irqrestore(lVar5,uVar4);
      local_60 = uVar9;
      local_58 = uVar8;
      iVar3 = ___ratelimit(ubwcp_irq_handler__rs_296,"ubwcp_irq_handler");
      lVar1 = me;
      if (iVar3 != 0) {
        _printk(&DAT_00117ad5,"ubwcp","ubwcp_irq_handler",0xc08,0,uVar9,uVar8);
        lVar1 = me;
      }
      me = lVar1;
      if (lVar1 == 0) {
        __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10d7a8);
        (*pcVar2)();
      }
      uVar4 = _raw_spin_lock_irqsave(lVar1 + 0x112e8);
      for (plVar7 = *(long **)(lVar1 + 0x112d8); plVar7 != (long *)(lVar1 + 0x112d8);
          plVar7 = (long *)*plVar7) {
        if (*(int *)((code *)plVar7[3] + -4) != -0x2f58620e) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10d7f8);
          (*pcVar2)();
        }
        (*(code *)plVar7[3])(&local_68,plVar7[4]);
      }
      _raw_spin_unlock_irqrestore(lVar1 + 0x112e8,uVar4);
      uVar4 = *(undefined8 *)(param_2 + 200);
      uVar9 = 3;
    }
    else {
      if (*(int *)(param_2 + 0xf0) != param_1) {
        iVar3 = ___ratelimit(ubwcp_irq_handler__rs_300,"ubwcp_irq_handler");
        if (iVar3 != 0) {
          _printk(&DAT_00117b27,"ubwcp","ubwcp_irq_handler",0xc15,param_1);
        }
        uVar4 = 0;
        goto LAB_0010d97c;
      }
      lVar5 = ubwcp_hw_interrupt_src_address(uVar4,2);
      lVar1 = me;
      uVar8 = lVar5 * 0x40;
      local_68 = CONCAT44(local_68._4_4_,1);
      if (me == 0) {
        __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10d85c);
        (*pcVar2)();
      }
      lVar5 = me + 0x11210;
      uVar4 = _raw_spin_lock_irqsave(lVar5);
      lVar6 = 0;
      do {
        for (plVar7 = *(long **)(lVar1 + lVar6 * 8 + 0x120); plVar7 != (long *)0x0;
            plVar7 = (long *)*plVar7) {
          if (((ulong)plVar7[0x15] <= uVar8) && (uVar8 < (ulong)(plVar7[0x16] + plVar7[0x15]))) {
            uVar9 = plVar7[0x12];
            goto LAB_0010d8c4;
          }
        }
        lVar6 = lVar6 + 1;
      } while (lVar6 != 0x2000);
      uVar9 = 0;
LAB_0010d8c4:
      _raw_spin_unlock_irqrestore(lVar5,uVar4);
      local_60 = uVar9;
      local_58 = uVar8;
      iVar3 = ___ratelimit(ubwcp_irq_handler__rs_298,"ubwcp_irq_handler");
      lVar1 = me;
      if (iVar3 != 0) {
        _printk(&DAT_00117ef7,"ubwcp","ubwcp_irq_handler",0xc11,1,uVar9,uVar8);
        lVar1 = me;
      }
      me = lVar1;
      if (lVar1 == 0) {
        __warn_printk("ubwcp: driver ptr requested but driver not initialized");
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10d900);
        (*pcVar2)();
      }
      uVar4 = _raw_spin_lock_irqsave(lVar1 + 0x112e8);
      for (plVar7 = *(long **)(lVar1 + 0x112d8); plVar7 != (long *)(lVar1 + 0x112d8);
          plVar7 = (long *)*plVar7) {
        if (*(int *)((code *)plVar7[3] + -4) != -0x2f58620e) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10d950);
          (*pcVar2)();
        }
        (*(code *)plVar7[3])(&local_68,plVar7[4]);
      }
      _raw_spin_unlock_irqrestore(lVar1 + 0x112e8,uVar4);
      uVar4 = *(undefined8 *)(param_2 + 200);
      uVar9 = 2;
    }
  }
  ubwcp_hw_interrupt_clear(uVar4,uVar9);
  uVar4 = 1;
LAB_0010d97c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



//------------------------------------------------------------
// reg_rw_trace_fops_open @ 0010db08 size=52
// signature: undefined reg_rw_trace_fops_open(void)
// callers: []
//------------------------------------------------------------

void reg_rw_trace_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,reg_rw_trace_r_op,reg_rw_trace_w_op,&DAT_00115672);
  return;
}



//------------------------------------------------------------
// reg_rw_trace_r_op @ 0010db40 size=128
// signature: undefined reg_rw_trace_r_op(void)
// callers: []
//------------------------------------------------------------

void reg_rw_trace_r_op(long param_1,ulong *param_2)

{
  long lVar1;
  undefined8 uVar2;
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  if (*(int *)(param_1 + 0x111d4) == 0) {
    ubwcp_hw_trace_get(local_2c);
    uVar2 = 0;
    *param_2 = (ulong)local_2c[0];
  }
  else {
    uVar2 = 0xffffffff;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// reg_rw_trace_w_op @ 0010dbc4 size=64
// signature: undefined reg_rw_trace_w_op(void)
// callers: []
//------------------------------------------------------------

undefined8 reg_rw_trace_w_op(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if (*(int *)(param_1 + 0x111d4) == 0) {
    ubwcp_hw_trace_set(param_2 != 0);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



//------------------------------------------------------------
// read_err_fops_open @ 0010dc08 size=52
// signature: undefined read_err_fops_open(void)
// callers: []
//------------------------------------------------------------

void read_err_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,read_err_r_op,read_err_w_op,&DAT_00115672);
  return;
}



//------------------------------------------------------------
// read_err_r_op @ 0010dc40 size=16
// signature: undefined read_err_r_op(void)
// callers: []
//------------------------------------------------------------

undefined8 read_err_r_op(long param_1,ulong *param_2)

{
  *param_2 = (ulong)*(byte *)(param_1 + 0xa8);
  return 0;
}



//------------------------------------------------------------
// read_err_w_op @ 0010dc54 size=192
// signature: undefined read_err_w_op(void)
// callers: []
//------------------------------------------------------------

undefined8 read_err_w_op(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x111d4) == 0) {
    iVar1 = ubwcp_power(param_1,1);
    if (iVar1 == 0) {
      ubwcp_hw_interrupt_enable(*(undefined8 *)(param_1 + 200),0,param_2 != 0);
      *(bool *)(param_1 + 0xa8) = param_2 != 0;
      uVar2 = ubwcp_power(param_1,0);
      if ((int)uVar2 == 0) {
        return uVar2;
      }
    }
    *(int *)(param_1 + 0x111d4) = -2;
    iVar1 = ___ratelimit(read_err_w_op__rs,"read_err_w_op");
    if (iVar1 != 0) {
      _printk(&DAT_00115635,"ubwcp","read_err_w_op",0xa05);
    }
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// write_err_fops_open @ 0010dd18 size=52
// signature: undefined write_err_fops_open(void)
// callers: []
//------------------------------------------------------------

void write_err_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,write_err_r_op,write_err_w_op,&DAT_00115672);
  return;
}



//------------------------------------------------------------
// write_err_r_op @ 0010dd50 size=40
// signature: undefined write_err_r_op(void)
// callers: []
//------------------------------------------------------------

undefined8 write_err_r_op(long param_1,ulong *param_2)

{
  if (*(int *)(param_1 + 0x111d4) == 0) {
    *param_2 = (ulong)*(byte *)(param_1 + 0xa9);
    return 0;
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// write_err_w_op @ 0010dd7c size=192
// signature: undefined write_err_w_op(void)
// callers: []
//------------------------------------------------------------

undefined8 write_err_w_op(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x111d4) == 0) {
    iVar1 = ubwcp_power(param_1,1);
    if (iVar1 == 0) {
      ubwcp_hw_interrupt_enable(*(undefined8 *)(param_1 + 200),1,param_2 != 0);
      *(bool *)(param_1 + 0xa9) = param_2 != 0;
      uVar2 = ubwcp_power(param_1,0);
      if ((int)uVar2 == 0) {
        return uVar2;
      }
    }
    *(int *)(param_1 + 0x111d4) = -2;
    iVar1 = ___ratelimit(write_err_w_op__rs,"write_err_w_op");
    if (iVar1 != 0) {
      _printk(&DAT_00115635,"ubwcp","write_err_w_op",0xa27);
    }
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// decode_err_fops_open @ 0010de40 size=52
// signature: undefined decode_err_fops_open(void)
// callers: []
//------------------------------------------------------------

void decode_err_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,decode_err_r_op,decode_err_w_op,&DAT_00115672);
  return;
}



//------------------------------------------------------------
// decode_err_r_op @ 0010de78 size=40
// signature: undefined decode_err_r_op(void)
// callers: []
//------------------------------------------------------------

undefined8 decode_err_r_op(long param_1,ulong *param_2)

{
  if (*(int *)(param_1 + 0x111d4) == 0) {
    *param_2 = (ulong)*(byte *)(param_1 + 0xaa);
    return 0;
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// decode_err_w_op @ 0010dea4 size=192
// signature: undefined decode_err_w_op(void)
// callers: []
//------------------------------------------------------------

undefined8 decode_err_w_op(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x111d4) == 0) {
    iVar1 = ubwcp_power(param_1,1);
    if (iVar1 == 0) {
      ubwcp_hw_interrupt_enable(*(undefined8 *)(param_1 + 200),2,param_2 != 0);
      *(bool *)(param_1 + 0xaa) = param_2 != 0;
      uVar2 = ubwcp_power(param_1,0);
      if ((int)uVar2 == 0) {
        return uVar2;
      }
    }
    *(int *)(param_1 + 0x111d4) = -2;
    iVar1 = ___ratelimit(decode_err_w_op__rs,"decode_err_w_op");
    if (iVar1 != 0) {
      _printk(&DAT_00115635,"ubwcp","decode_err_w_op",0xa49);
    }
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// encode_err_fops_open @ 0010df68 size=52
// signature: undefined encode_err_fops_open(void)
// callers: []
//------------------------------------------------------------

void encode_err_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,encode_err_r_op,encode_err_w_op,&DAT_00115672);
  return;
}



//------------------------------------------------------------
// encode_err_r_op @ 0010dfa0 size=40
// signature: undefined encode_err_r_op(void)
// callers: []
//------------------------------------------------------------

undefined8 encode_err_r_op(long param_1,ulong *param_2)

{
  if (*(int *)(param_1 + 0x111d4) == 0) {
    *param_2 = (ulong)*(byte *)(param_1 + 0xab);
    return 0;
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// encode_err_w_op @ 0010dfcc size=192
// signature: undefined encode_err_w_op(void)
// callers: []
//------------------------------------------------------------

undefined8 encode_err_w_op(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x111d4) == 0) {
    iVar1 = ubwcp_power(param_1,1);
    if (iVar1 == 0) {
      ubwcp_hw_interrupt_enable(*(undefined8 *)(param_1 + 200),3,param_2 != 0);
      *(bool *)(param_1 + 0xab) = param_2 != 0;
      uVar2 = ubwcp_power(param_1,0);
      if ((int)uVar2 == 0) {
        return uVar2;
      }
    }
    *(int *)(param_1 + 0x111d4) = -2;
    iVar1 = ___ratelimit(encode_err_w_op__rs,"encode_err_w_op");
    if (iVar1 != 0) {
      _printk(&DAT_00115635,"ubwcp","encode_err_w_op",0xa6b);
    }
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// single_tile_fops_open @ 0010e090 size=52
// signature: undefined single_tile_fops_open(void)
// callers: []
//------------------------------------------------------------

void single_tile_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,single_tile_r_op,single_tile_w_op,&DAT_00115672);
  return;
}



//------------------------------------------------------------
// single_tile_r_op @ 0010e0c8 size=40
// signature: undefined single_tile_r_op(void)
// callers: []
//------------------------------------------------------------

undefined8 single_tile_r_op(long param_1,ulong *param_2)

{
  if (*(int *)(param_1 + 0x111d4) == 0) {
    *param_2 = (ulong)*(byte *)(param_1 + 0xac);
    return 0;
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// single_tile_w_op @ 0010e0f4 size=188
// signature: undefined single_tile_w_op(void)
// callers: []
//------------------------------------------------------------

undefined8 single_tile_w_op(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x111d4) == 0) {
    iVar1 = ubwcp_power(param_1,1);
    if (iVar1 == 0) {
      ubwcp_hw_single_tile(*(undefined8 *)(param_1 + 200),param_2 != 0);
      *(bool *)(param_1 + 0xac) = param_2 != 0;
      uVar2 = ubwcp_power(param_1,0);
      if ((int)uVar2 == 0) {
        return uVar2;
      }
    }
    *(int *)(param_1 + 0x111d4) = -2;
    iVar1 = ___ratelimit(single_tile_w_op__rs,"single_tile_w_op");
    if (iVar1 != 0) {
      _printk(&DAT_00115635,"ubwcp","single_tile_w_op",0xaa5);
    }
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// unlock_internal @ 0010e1b0 size=616
// signature: undefined unlock_internal(void)
// callers: [ubwcp_unlock, ubwcp_free_buffer]
//------------------------------------------------------------

int unlock_internal(long param_1,int param_2,ulong param_3)

{
  long lVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  
  if (ubwcp_debug_trace_enable == 0) {
    if ((param_3 & 1) != 0) goto LAB_0010e1e8;
LAB_0010e23c:
    if (*(int *)(param_1 + 0x84) != param_2) {
      *(undefined4 *)(param_1 + 0x84) = 0;
    }
    iVar5 = ubwcp_debug_trace_enable;
    iVar4 = *(int *)(param_1 + 0x88) + -1;
    *(int *)(param_1 + 0x88) = iVar4;
    if (iVar5 != 0) {
      _printk(&DAT_00116a8a,"ubwcp","unlock_internal");
      iVar4 = *(int *)(param_1 + 0x88);
    }
    if (iVar4 != 0) {
      if (ubwcp_debug_trace_enable == 0) {
        return 0;
      }
      _printk(&DAT_00115de6,"ubwcp","unlock_internal");
      return 0;
    }
  }
  else {
    _printk(&DAT_00115a5b,"ubwcp","unlock_internal",*(undefined4 *)(param_1 + 0x88));
    if ((param_3 & 1) == 0) goto LAB_0010e23c;
LAB_0010e1e8:
    iVar4 = ubwcp_debug_trace_enable;
    *(undefined4 *)(param_1 + 0x88) = 0;
    if (iVar4 != 0) {
      _printk(&DAT_00116f38,"ubwcp","unlock_internal",0);
    }
  }
  lVar6 = *(long *)(param_1 + 0x10);
  if (*(uint *)(param_1 + 0x84) < 2) {
    dma_sync_single_for_device
              (*(undefined8 *)(param_1 + 0xb0),*(undefined8 *)(lVar6 + 0xb0),
               *(undefined8 *)(param_1 + 0xa8),*(undefined8 *)(param_1 + 0xb0),
               *(undefined4 *)(param_1 + 0x84));
  }
  if (ubwcp_debug_trace_enable != 0) {
    _printk(&DAT_00116f5b,"ubwcp","unlock_internal");
  }
  iVar4 = range_check_disable(lVar6,**(undefined4 **)(param_1 + 0x78));
  if (iVar4 != 0) {
    *(undefined4 *)(lVar6 + 0x111d4) = 0xfffffffe;
    iVar5 = ___ratelimit(unlock_internal__rs,"unlock_internal");
    if (iVar5 != 0) {
      _printk(&DAT_00115635,"ubwcp","unlock_internal",0x843);
      cVar2 = *(char *)(param_1 + 0x70);
      goto joined_r0x0010e318;
    }
  }
  cVar2 = *(char *)(param_1 + 0x70);
joined_r0x0010e318:
  if (cVar2 == '\0') {
    iVar5 = **(int **)(param_1 + 0x78);
    lVar6 = *(long *)(param_1 + 0x10) + 0x111e0;
    lVar1 = *(long *)(param_1 + 0x10) + (long)iVar5 * 0x10;
    mutex_lock(lVar6);
    *(undefined4 *)(lVar1 + 0x10138) = 0xffffffff;
    iVar3 = ubwcp_debug_trace_enable;
    *(undefined8 *)(lVar1 + 0x10140) = 0;
    if (iVar3 != 0) {
      _printk(&DAT_00114aa8,"ubwcp","ubwcp_buf_desc_free",iVar5);
    }
    mutex_unlock(lVar6);
    *(undefined8 *)(param_1 + 0x78) = 0;
  }
  return iVar4;
}



//------------------------------------------------------------
// ubwcp_buf_desc_free @ 0010e558 size=140
// signature: undefined ubwcp_buf_desc_free(void)
// callers: [ubwcp_lock]
//------------------------------------------------------------

void ubwcp_buf_desc_free(long param_1,int *param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_2;
  lVar1 = param_1 + (long)iVar2 * 0x10;
  mutex_lock(param_1 + 0x111e0);
  *(undefined4 *)(lVar1 + 0x10138) = 0xffffffff;
  iVar3 = ubwcp_debug_trace_enable;
  *(undefined8 *)(lVar1 + 0x10140) = 0;
  if (iVar3 != 0) {
    _printk(&DAT_00114aa8,"ubwcp","ubwcp_buf_desc_free",iVar2);
  }
  mutex_unlock(param_1 + 0x111e0);
  return;
}



//------------------------------------------------------------
// range_check_disable @ 0010e5e4 size=200
// signature: undefined range_check_disable(void)
// callers: [ubwcp_lock, unlock_internal]
//------------------------------------------------------------

int range_check_disable(long param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  mutex_lock(param_1 + 0x11278);
  mutex_lock(param_1 + 0x112a8);
  iVar1 = ubwcp_hw_disable_range_check_with_flush(*(undefined8 *)(param_1 + 200),param_2);
  if ((iVar1 != 0) &&
     (iVar2 = ___ratelimit(range_check_disable__rs,"range_check_disable"), iVar2 != 0)) {
    _printk(&DAT_00115686,"ubwcp","range_check_disable",0x76a,iVar1);
  }
  mutex_unlock(param_1 + 0x112a8);
  mutex_unlock(param_1 + 0x11278);
  return iVar1;
}



//------------------------------------------------------------
// trace_ubwcp_lock_end @ 0010e7dc size=44
// signature: undefined trace_ubwcp_lock_end(void)
// callers: [ubwcp_lock]
//------------------------------------------------------------

void trace_ubwcp_lock_end(void)

{
  return;
}



//------------------------------------------------------------
// ubwcp_buf_desc_allocate @ 0010e8a4 size=192
// signature: undefined ubwcp_buf_desc_allocate(void)
// callers: [ubwcp_lock]
//------------------------------------------------------------

int * ubwcp_buf_desc_allocate(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  int *piVar4;
  
  piVar4 = (int *)(param_1 + 0x10138);
  mutex_lock(param_1 + 0x111e0);
  lVar3 = 0;
  lVar2 = 0;
  do {
    if (*piVar4 == -1) {
      *piVar4 = (int)lVar2;
      iVar1 = ubwcp_debug_trace_enable;
      *(long *)(piVar4 + 2) = *(long *)(param_1 + 0x10120) - lVar3;
      if (iVar1 != 0) {
        _printk(&DAT_00117bde,"ubwcp","ubwcp_buf_desc_allocate");
      }
      goto LAB_0010e924;
    }
    lVar2 = lVar2 + 1;
    piVar4 = piVar4 + 4;
    lVar3 = lVar3 + -0x40;
  } while (lVar2 != 0x100);
  piVar4 = (int *)0x0;
LAB_0010e924:
  mutex_unlock(param_1 + 0x111e0);
  return piVar4;
}



//------------------------------------------------------------
// range_check_enable @ 0010e964 size=84
// signature: undefined range_check_enable(void)
// callers: [ubwcp_lock]
//------------------------------------------------------------

void range_check_enable(long param_1,undefined4 param_2)

{
  mutex_lock(param_1 + 0x112a8);
  ubwcp_hw_enable_range_check(*(undefined8 *)(param_1 + 200),param_2);
  mutex_unlock(param_1 + 0x112a8);
  return;
}



//------------------------------------------------------------
// ubwcp_flush @ 0010e9b8 size=160
// signature: undefined ubwcp_flush(void)
// callers: [ubwcp_lock]
//------------------------------------------------------------

int ubwcp_flush(long param_1)

{
  int iVar1;
  int iVar2;
  
  mutex_lock(param_1 + 0x11278);
  iVar1 = ubwcp_hw_flush(*(undefined8 *)(param_1 + 200));
  if ((iVar1 != 0) && (iVar2 = ___ratelimit(ubwcp_flush__rs,"ubwcp_flush"), iVar2 != 0)) {
    _printk(&DAT_001167b1,"ubwcp","ubwcp_flush",0x75c,iVar1);
  }
  mutex_unlock(param_1 + 0x11278);
  return iVar1;
}



//------------------------------------------------------------
// ubwcp_hw_interrupt_enable @ 0010ed60 size=212
// signature: undefined ubwcp_hw_interrupt_enable(void)
// callers: [read_err_w_op, ubwcp_probe, decode_err_w_op, write_err_w_op, ubwcp_remove, encode_err_w_op]
//------------------------------------------------------------

void ubwcp_hw_interrupt_enable(long param_1,uint param_2,ulong param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = readl(param_1 + 0x10b0);
  if (ubwcp_hw_trace_en != '\0') {
    _printk(&DAT_00117da9,"ubwcp","ubwcp_hw_interrupt_enable",0x10b0,uVar3);
  }
  uVar2 = 1 << (ulong)(param_2 & 0x1f);
  uVar1 = uVar3 | uVar2;
  if ((param_3 & 1) == 0) {
    uVar1 = uVar3 & (uVar2 ^ 0xffffffff);
  }
  if (ubwcp_hw_trace_en != '\0') {
    _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_interrupt_enable",0x10b0,uVar1);
  }
  writel(uVar1,param_1 + 0x10b0);
  return;
}



//------------------------------------------------------------
// ubwcp_hw_interrupt_clear @ 0010ee38 size=48
// signature: undefined ubwcp_hw_interrupt_clear(void)
// callers: [ubwcp_irq_handler]
//------------------------------------------------------------

void ubwcp_hw_interrupt_clear(long param_1,uint param_2)

{
  writel(1 << (ulong)(param_2 & 0x1f),param_1 + 0x1120);
  return;
}



//------------------------------------------------------------
// ubwcp_hw_interrupt_status @ 0010ee6c size=340
// signature: undefined ubwcp_hw_interrupt_status(void)
// callers: []
//------------------------------------------------------------

uint ubwcp_hw_interrupt_status(long param_1,undefined2 param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  switch(param_2) {
  case 0:
    uVar1 = readl(param_1 + 0x10c0);
    if (ubwcp_hw_trace_en == '\0') goto LAB_0010ef7c;
    uVar2 = 0x10c0;
    break;
  case 1:
    uVar1 = readl(param_1 + 0x10c4);
    if (ubwcp_hw_trace_en == '\0') goto LAB_0010ef7c;
    uVar2 = 0x10c4;
    break;
  case 2:
    uVar1 = readl(param_1 + 0x10cc);
    if (ubwcp_hw_trace_en == '\0') goto LAB_0010ef7c;
    uVar2 = 0x10cc;
    break;
  case 3:
    uVar1 = readl(param_1 + 0x10c8);
    if (ubwcp_hw_trace_en == '\0') goto LAB_0010ef7c;
    uVar2 = 0x10c8;
    break;
  default:
    return 0xffffffff;
  }
  _printk(&DAT_00117da9,"ubwcp","ubwcp_hw_interrupt_status",uVar2,uVar1);
LAB_0010ef7c:
  return uVar1 & 1;
}



//------------------------------------------------------------
// ubwcp_hw_interrupt_src_address @ 0010efc4 size=116
// signature: undefined ubwcp_hw_interrupt_src_address(void)
// callers: [ubwcp_irq_handler]
//------------------------------------------------------------

uint ubwcp_hw_interrupt_src_address(long param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  
  if ((param_2 & 0xffff) < 4) {
    uVar3 = -(((ulong)param_2 & 0x8000) >> 0xf) & 0xfffffffffff80000 |
            ((ulong)param_2 & 0xffff) << 3;
    lVar4 = *(long *)(&DAT_00118110 + uVar3);
    uVar1 = readl(param_1 + *(long *)(&DAT_00118130 + uVar3));
    iVar2 = readl(param_1 + lVar4);
    return uVar1 | iVar2 << 0x1f;
  }
  return 0;
}



//------------------------------------------------------------
// ubwcp_hw_set_range_check @ 0010f03c size=200
// signature: undefined ubwcp_hw_set_range_check(void)
// callers: [ubwcp_lock]
//------------------------------------------------------------

void ubwcp_hw_set_range_check(long param_1,uint param_2,ulong param_3,long param_4)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = param_4 + param_3 >> 0xc;
  uVar1 = (param_2 & 0xffff) * 4;
  if (ubwcp_hw_trace_en != '\0') {
    _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_set_range_check",(ulong)uVar1,
            param_3 >> 0xc & 0xffffffff);
  }
  param_1 = param_1 + (ulong)uVar1;
  writel(param_3 >> 0xc & 0xffffffff,param_1);
  if (ubwcp_hw_trace_en != '\0') {
    _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_set_range_check",uVar1 + 0x800,uVar2 & 0xffffffff);
  }
  writel(uVar2 & 0xffffffff,param_1 + 0x800);
  return;
}



//------------------------------------------------------------
// ubwcp_hw_enable_range_check @ 0010f108 size=220
// signature: undefined ubwcp_hw_enable_range_check(void)
// callers: [range_check_enable]
//------------------------------------------------------------

void ubwcp_hw_enable_range_check(long param_1,ulong param_2)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (uint)(param_2 >> 3) & 0x1ffc;
  lVar2 = param_1 + 0x1020 + (ulong)uVar3;
  uVar4 = readl(lVar2);
  if (ubwcp_hw_trace_en == '\0') {
    uVar4 = uVar4 | 1 << (ulong)((uint)param_2 & 0x1f);
  }
  else {
    iVar1 = uVar3 + 0x1020;
    _printk(&DAT_00117da9,"ubwcp","ubwcp_hw_enable_range_check",iVar1,uVar4);
    uVar4 = uVar4 | 1 << (ulong)((uint)param_2 & 0x1f);
    if (ubwcp_hw_trace_en != '\0') {
      _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_enable_range_check",iVar1,uVar4);
    }
  }
  writel(uVar4,lVar2);
  return;
}



//------------------------------------------------------------
// ubwcp_hw_flush @ 0010f1e8 size=384
// signature: undefined ubwcp_hw_flush(void)
// callers: [ubwcp_flush, ubwcp_hw_disable_range_check_with_flush]
//------------------------------------------------------------

undefined8 ubwcp_hw_flush(long param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (ubwcp_hw_trace_en != '\0') {
    _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_flush",0x10a0,3);
  }
  writel(3,param_1 + 0x10a0);
  uVar3 = 3000;
  while( true ) {
    if (uVar3 < 2000) {
      __const_udelay(0x10c7);
    }
    uVar1 = readl(param_1 + 0x10a4);
    if (ubwcp_hw_trace_en != '\0') {
      _printk(&DAT_00117da9,"ubwcp","ubwcp_hw_flush",0x10a4,uVar1);
    }
    if ((uVar1 & 1) != 0) break;
    uVar3 = uVar3 - 1;
    if (uVar3 == 0xffffffff) {
      iVar2 = ___ratelimit(&ubwcp_hw_flush__rs,"ubwcp_hw_flush");
      if (iVar2 != 0) {
        _printk(&DAT_00116135,"ubwcp","ubwcp_hw_flush",0xdf);
      }
      return 0xffffffff;
    }
  }
  if (ubwcp_hw_trace_en != '\0') {
    _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_flush",0x10a0,0);
  }
  writel(0,param_1 + 0x10a0);
  return 0;
}



//------------------------------------------------------------
// ubwcp_hw_disable_range_check_with_flush @ 0010f36c size=312
// signature: undefined ubwcp_hw_disable_range_check_with_flush(void)
// callers: [range_check_disable]
//------------------------------------------------------------

void ubwcp_hw_disable_range_check_with_flush(long param_1,ulong param_2)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (uint)(param_2 >> 3) & 0x1ffc;
  lVar2 = param_1 + 0x1020 + (ulong)uVar3;
  InstructionSynchronizationBarrier();
  uVar4 = readl(lVar2);
  if (ubwcp_hw_trace_en == '\0') {
    uVar4 = uVar4 & (1 << (ulong)((uint)param_2 & 0x1f) ^ 0xffffffffU);
  }
  else {
    iVar1 = uVar3 + 0x1020;
    _printk(&DAT_00117da9,"ubwcp","ubwcp_hw_disable_range_check_with_flush",iVar1,uVar4);
    uVar4 = uVar4 & (1 << (ulong)((uint)param_2 & 0x1f) ^ 0xffffffffU);
    if (ubwcp_hw_trace_en != '\0') {
      _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_disable_range_check_with_flush",iVar1,uVar4);
    }
  }
  writel(uVar4,lVar2);
  InstructionSynchronizationBarrier();
  if (ubwcp_hw_trace_en != '\0') {
    _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_disable_range_check_with_flush",0x10a0,3);
  }
  writel(3,param_1 + 0x10a0);
  ubwcp_hw_flush(param_1);
  return;
}



//------------------------------------------------------------
// ubwcp_hw_set_buf_desc @ 0010f4a8 size=184
// signature: undefined ubwcp_hw_set_buf_desc(void)
// callers: [ubwcp_probe, ubwcp_remove]
//------------------------------------------------------------

void ubwcp_hw_set_buf_desc(long param_1,ulong param_2,undefined2 param_3)

{
  if (ubwcp_hw_trace_en != '\0') {
    _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_set_buf_desc",0x1000,param_2 >> 0xc);
  }
  writel(param_2 >> 0xc & 0xffffffff,param_1 + 0x1000);
  if (ubwcp_hw_trace_en != '\0') {
    _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_set_buf_desc",0x1004,param_3);
  }
  writel(param_3,param_1 + 0x1004);
  return;
}



//------------------------------------------------------------
// ubwcp_hw_set_default_range_check_value @ 0010f564 size=108
// signature: undefined ubwcp_hw_set_default_range_check_value(void)
// callers: []
//------------------------------------------------------------

void ubwcp_hw_set_default_range_check_value(long param_1,undefined4 param_2)

{
  if (ubwcp_hw_trace_en != '\0') {
    _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_set_default_range_check_value",0x101c,param_2);
  }
  writel(param_2,param_1 + 0x101c);
  return;
}



//------------------------------------------------------------
// ubwcp_hw_version @ 0010f5d4 size=132
// signature: undefined ubwcp_hw_version(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

void ubwcp_hw_version(long param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = readl(param_1 + 0x1130);
  if (ubwcp_hw_trace_en != '\0') {
    _printk(&DAT_00117da9,"ubwcp","ubwcp_hw_version",0x1130,uVar1);
  }
  *param_2 = uVar1 & 0xf;
  *param_3 = uVar1 >> 4 & 0xf;
  return;
}



//------------------------------------------------------------
// ubwcp_hw_macro_tile_config @ 0010f65c size=104
// signature: undefined ubwcp_hw_macro_tile_config(void)
// callers: []
//------------------------------------------------------------

void ubwcp_hw_macro_tile_config(long param_1)

{
  if (ubwcp_hw_trace_en != '\0') {
    _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_macro_tile_config",0x1008,0x1e3);
  }
  writel(0x1e3,param_1 + 0x1008);
  return;
}



//------------------------------------------------------------
// ubwcp_hw_decoder_config @ 0010f6c8 size=104
// signature: undefined ubwcp_hw_decoder_config(void)
// callers: []
//------------------------------------------------------------

void ubwcp_hw_decoder_config(long param_1)

{
  if (ubwcp_hw_trace_en != '\0') {
    _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_decoder_config",0x1014,7);
  }
  writel(7,param_1 + 0x1014);
  return;
}



//------------------------------------------------------------
// ubwcp_hw_encoder_config @ 0010f734 size=104
// signature: undefined ubwcp_hw_encoder_config(void)
// callers: []
//------------------------------------------------------------

void ubwcp_hw_encoder_config(long param_1)

{
  if (ubwcp_hw_trace_en != '\0') {
    _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_encoder_config",0x100c,7);
  }
  writel(7,param_1 + 0x100c);
  return;
}



//------------------------------------------------------------
// ubwcp_hw_power_vote_status @ 0010f7a0 size=124
// signature: undefined ubwcp_hw_power_vote_status(void)
// callers: []
//------------------------------------------------------------

void ubwcp_hw_power_vote_status(undefined8 param_1,byte *param_2,undefined1 *param_3)

{
  ulong uVar1;
  
  uVar1 = readl();
  if (ubwcp_hw_trace_en != '\0') {
    _printk(&DAT_00117da9,"ubwcp","ubwcp_hw_power_vote_status",0,uVar1 & 0xffffffff);
  }
  *param_2 = (byte)uVar1 & 1;
  *param_3 = (char)((uVar1 & 0xffffffff) >> 0x1f);
  return;
}



//------------------------------------------------------------
// ubwcp_hw_single_tile @ 0010f820 size=212
// signature: undefined ubwcp_hw_single_tile(void)
// callers: [single_tile_w_op, ubwcp_probe]
//------------------------------------------------------------

void ubwcp_hw_single_tile(long param_1,ulong param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = readl(param_1 + 0x1188);
  if (ubwcp_hw_trace_en == '\0') {
    uVar2 = 0x8000;
    if ((param_2 & 1) == 0) {
      uVar2 = 0;
    }
    uVar2 = uVar1 & 0xffff7fff | uVar2;
  }
  else {
    _printk(&DAT_00117da9,"ubwcp","ubwcp_hw_single_tile",0x1188,uVar1);
    uVar2 = 0x8000;
    if ((param_2 & 1) == 0) {
      uVar2 = 0;
    }
    uVar2 = uVar1 & 0xffff7fff | uVar2;
    if (ubwcp_hw_trace_en != '\0') {
      _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_single_tile",0x1188,uVar2);
    }
  }
  writel(uVar2,param_1 + 0x1188);
  return;
}



//------------------------------------------------------------
// ubwcp_hw_one_time_init @ 0010f8f8 size=520
// signature: undefined ubwcp_hw_one_time_init(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

void ubwcp_hw_one_time_init(long param_1)

{
  uint uVar1;
  
  uVar1 = readl(param_1 + 0x1188);
  if (ubwcp_hw_trace_en != '\0') {
    _printk(&DAT_00117da9,"ubwcp","ubwcp_hw_one_time_init",0x1188,uVar1);
    if (ubwcp_hw_trace_en != '\0') {
      _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_one_time_init",0x1188,uVar1 | 0x202);
    }
  }
  writel(uVar1 | 0x202,param_1 + 0x1188);
  uVar1 = readl(param_1 + 0x1124);
  if (ubwcp_hw_trace_en == '\0') {
    uVar1 = uVar1 & 0xffffffc0 | 1;
  }
  else {
    _printk(&DAT_00117da9,"ubwcp","ubwcp_hw_one_time_init",0x1124,uVar1);
    uVar1 = uVar1 & 0xffffffc0 | 1;
    if (ubwcp_hw_trace_en != '\0') {
      _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_one_time_init",0x1124,uVar1);
    }
  }
  writel(uVar1,param_1 + 0x1124);
  if (ubwcp_hw_trace_en != '\0') {
    _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_decoder_config",0x1014,7);
  }
  writel(7,param_1 + 0x1014);
  if (ubwcp_hw_trace_en != '\0') {
    _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_encoder_config",0x100c,7);
  }
  writel(7,param_1 + 0x100c);
  if (ubwcp_hw_trace_en != '\0') {
    _printk(&DAT_001152e8,"ubwcp","ubwcp_hw_macro_tile_config",0x1008,0x1e3);
  }
  writel(0x1e3,param_1 + 0x1008);
  return;
}



//------------------------------------------------------------
// ubwcp_hw_trace_set @ 0010fb04 size=12
// signature: undefined ubwcp_hw_trace_set(void)
// callers: [reg_rw_trace_w_op]
//------------------------------------------------------------

void ubwcp_hw_trace_set(undefined1 param_1)

{
  ubwcp_hw_trace_en = param_1;
  return;
}



//------------------------------------------------------------
// ubwcp_hw_trace_get @ 0010fb14 size=16
// signature: undefined ubwcp_hw_trace_get(void)
// callers: [reg_rw_trace_r_op]
//------------------------------------------------------------

void ubwcp_hw_trace_get(undefined1 *param_1)

{
  *param_1 = ubwcp_hw_trace_en;
  return;
}



//------------------------------------------------------------
// readl @ 0010fb24 size=140
// signature: undefined readl(void)
// callers: [ubwcp_hw_power_vote_status, ubwcp_hw_interrupt_enable, ubwcp_hw_enable_range_check, ubwcp_hw_version, ubwcp_hw_single_tile, ubwcp_hw_interrupt_src_address, ubwcp_hw_flush, ubwcp_hw_one_time_init, ubwcp_hw_interrupt_status, ubwcp_hw_disable_range_check_with_flush]
//------------------------------------------------------------

undefined4 readl(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl,uVar1);
  uVar2 = *param_1;
  DataMemoryBarrier(0,1);
  log_post_read_mmio(uVar2,0x20,param_1,0x10fb7c,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel @ 0010fbb0 size=136
// signature: undefined writel(void)
// callers: [ubwcp_hw_enable_range_check, ubwcp_hw_macro_tile_config, ubwcp_hw_set_default_range_check_value, ubwcp_hw_decoder_config, ubwcp_hw_disable_range_check_with_flush, ubwcp_hw_set_buf_desc, ubwcp_hw_encoder_config, ubwcp_hw_interrupt_enable, ubwcp_hw_single_tile, ubwcp_hw_set_range_check, ubwcp_hw_flush, ubwcp_hw_interrupt_clear, ubwcp_hw_one_time_init]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10fbc8,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x10fc08,uVar1);
  return;
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 0011b000 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_ubwcp_dmabuf_event, trace_event_raw_event_ubwcp_sync_event, trace_event_raw_event_ubwcp_size_event, trace_event_raw_event_ubwcp_int_event, trace_event_raw_event_ubwcp_platform_device_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 0011b008 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_ubwcp_dmabuf_event, trace_event_raw_event_ubwcp_sync_event, trace_event_raw_event_ubwcp_size_event, trace_event_raw_event_ubwcp_int_event, trace_event_raw_event_ubwcp_platform_device_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 0011b010 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_ubwcp_dmabuf_event, trace_event_raw_event_ubwcp_sync_event, trace_event_raw_event_ubwcp_size_event, trace_event_raw_event_ubwcp_int_event, trace_event_raw_event_ubwcp_platform_device_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0011b018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [reg_rw_trace_r_op, perf_trace_ubwcp_dmabuf_event, ubwcp_probe, trace_event_raw_event_ubwcp_size_event, trace_event_raw_event_ubwcp_int_event, ubwcp_cdev_init, ubwcp_iommu_fault_handler, trace_event_raw_event_ubwcp_platform_device_event, perf_trace_ubwcp_size_event, pixeldata_buf_sz, perf_trace_ubwcp_sync_event, ubwcp_set_buf_attrs, ubwcp_irq_handler, trace_event_raw_event_ubwcp_dmabuf_event, trace_event_raw_event_ubwcp_sync_event, ubwcp_ioctl, metadata_buf_sz, perf_trace_ubwcp_int_event, perf_trace_ubwcp_platform_device_event, ubwcp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 0011b020 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_ubwcp_sync_event, perf_trace_ubwcp_dmabuf_event, perf_trace_ubwcp_int_event, perf_trace_ubwcp_platform_device_event, perf_trace_ubwcp_size_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 0011b028 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_ubwcp_sync_event, perf_trace_ubwcp_dmabuf_event, perf_trace_ubwcp_int_event, perf_trace_ubwcp_platform_device_event, perf_trace_ubwcp_size_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run1 @ 0011b030 size=1
// signature: undefined bpf_trace_run1(void)
// callers: [__bpf_trace_ubwcp_dmabuf_event, __bpf_trace_ubwcp_int_event, __bpf_trace_ubwcp_platform_device_event, __bpf_trace_ubwcp_size_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run2 @ 0011b038 size=1
// signature: undefined bpf_trace_run2(void)
// callers: [__bpf_trace_ubwcp_sync_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 0011b040 size=1
// signature: undefined __warn_printk(void)
// callers: [ubwcp_set_perm_range_translation, ubwcp_register_error_handler, ubwcp_lock, ubwcp_iommu_fault_handler, ubwcp_set_buf_attrs, ubwcp_get_hw_version, ubwcp_irq_handler, ubwcp_unlock, ubwcp_get_buf_attrs, ubwcp_init_buffer, ubwcp_ioctl, ubwcp_free_buffer, ubwcp_unregister_error_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0011b048 size=1
// signature: undefined ___ratelimit(void)
// callers: [ubwcp_set_perm_range_translation, read_err_w_op, decode_err_w_op, range_check_disable, ula_add_mem, stride_is_valid, ubwcp_debugfs_init, ubwcp_irq_handler, ubwcp_calc_ula_params, metadata_buf_sz, write_err_w_op, ubwcp_ula_free, inc_num_non_lin_buffers, ubwcp_power, dec_num_non_lin_buffers, ubwcp_probe, ubwcp_lock, ubwcp_cdev_init, ubwcp_iommu_fault_handler, std_to_hw_img_fmt, ubwcp_interrupt_register, encode_err_w_op, pixeldata_buf_sz, to_std_format, init_module, ubwcp_set_buf_attrs, ubwcp_validate_uv_align, single_tile_w_op, ubwcp_get_hw_version, ubwcp_flush, ubwcp_calc_ubwcp_buf_params, ubwcp_unlock, ubwcp_get_buf_attrs, ubwcp_init_buffer, ubwcp_ioctl, ubwcp_free_buffer, ubwcp_hw_flush, unlock_internal, ubwcp_dma_map, verify_dma_buf_size, ubwcp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0011b050 size=1
// signature: undefined _printk(void)
// callers: [ubwcp_set_perm_range_translation, read_err_w_op, reset_buf_attrs, decode_err_w_op, prefetch_tgt_per_cpu, ubwcp_hw_set_default_range_check_value, prefetch_tgt, ubwcp_hw_set_buf_desc, ubwcp_irq_handler, ubwcp_hw_interrupt_enable, ubwcp_calc_ula_params, ubwcp_hw_single_tile, metadata_buf_sz, write_err_w_op, ubwcp_hw_interrupt_status, dec_num_non_lin_buffers, ubwcp_lock, ubwcp_hw_enable_range_check, ubwcp_cdev_init, std_to_hw_img_fmt, ubwcp_interrupt_register, ubwcp_buf_desc_free, encode_err_w_op, pixeldata_buf_sz, to_std_format, ubwcp_set_buf_attrs, ubwcp_validate_uv_align, single_tile_w_op, ubwcp_flush, ubwcp_hw_version, ubwcp_get_buf_attrs, ubwcp_init_buffer, ula_unmap, ubwcp_dma_map, cleanup_module, print_mmdata_desc, ubwcp_hw_macro_tile_config, ubwcp_hw_decoder_config, range_check_disable, ula_add_mem, ubwcp_hw_disable_range_check_with_flush, stride_is_valid, ubwcp_debugfs_init, ubwcp_ula_free, inc_num_non_lin_buffers, ubwcp_power, ubwcp_probe, ubwcp_iommu_fault_handler, ubwcp_buf_desc_allocate, init_module, ubwcp_get_hw_version, ubwcp_hw_power_vote_status, ubwcp_hw_encoder_config, ubwcp_calc_ubwcp_buf_params, ubwcp_hw_set_range_check, ubwcp_unlock, ubwcp_ioctl, ubwcp_free_buffer, ubwcp_hw_flush, unlock_internal, ubwcp_hw_one_time_init, verify_dma_buf_size, ubwcp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0011b058 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [ubwcp_set_buf_attrs, ubwcp_set_perm_range_translation, ubwcp_register_error_handler, ubwcp_irq_handler, ubwcp_lock, ubwcp_unlock, ubwcp_get_buf_attrs, ubwcp_init_buffer, ubwcp_free_buffer, ubwcp_iommu_fault_handler, ubwcp_unregister_error_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0011b060 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [ubwcp_set_buf_attrs, ubwcp_set_perm_range_translation, ubwcp_register_error_handler, ubwcp_irq_handler, ubwcp_lock, ubwcp_unlock, ubwcp_get_buf_attrs, ubwcp_init_buffer, ubwcp_free_buffer, ubwcp_iommu_fault_handler, ubwcp_unregister_error_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0011b068 size=1
// signature: undefined mutex_lock(void)
// callers: [inc_num_non_lin_buffers, ubwcp_power, dec_num_non_lin_buffers, ubwcp_lock, range_check_enable, ubwcp_ula_realloc, range_check_disable, ubwcp_buf_desc_allocate, ubwcp_buf_desc_free, ubwcp_set_buf_attrs, ubwcp_flush, ubwcp_unlock, ubwcp_get_buf_attrs, ubwcp_free_buffer, ubwcp_ula_free, unlock_internal]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0011b070 size=1
// signature: undefined mutex_unlock(void)
// callers: [inc_num_non_lin_buffers, ubwcp_power, dec_num_non_lin_buffers, ubwcp_lock, range_check_enable, ubwcp_ula_realloc, range_check_disable, ubwcp_buf_desc_allocate, ubwcp_buf_desc_free, ubwcp_set_buf_attrs, ubwcp_flush, ubwcp_unlock, ubwcp_get_buf_attrs, ubwcp_free_buffer, ubwcp_ula_free, unlock_internal]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_unmap_attachment @ 0011b090 size=1
// signature: undefined dma_buf_unmap_attachment(void)
// callers: [reset_buf_attrs, ubwcp_dma_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_unmap_attachment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_detach @ 0011b098 size=1
// signature: undefined dma_buf_detach(void)
// callers: [reset_buf_attrs, ubwcp_dma_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_detach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// set_direct_map_range_uncached @ 0011b0b0 size=1
// signature: undefined set_direct_map_range_uncached(void)
// callers: [dec_num_non_lin_buffers]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void set_direct_map_range_uncached(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_sync_single_for_cpu @ 0011b0b8 size=1
// signature: undefined dma_sync_single_for_cpu(void)
// callers: [dec_num_non_lin_buffers, ubwcp_lock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_sync_single_for_cpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_alloc_algo_owner @ 0011b0c0 size=1
// signature: undefined gen_pool_alloc_algo_owner(void)
// callers: [ubwcp_ula_realloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_alloc_algo_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_attach @ 0011b0c8 size=1
// signature: undefined dma_buf_attach(void)
// callers: [ubwcp_dma_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_attach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_map_attachment @ 0011b0d0 size=1
// signature: undefined dma_buf_map_attachment(void)
// callers: [ubwcp_dma_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_map_attachment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0011b0e0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [ubwcp_register_error_handler, ubwcp_init_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0011b0e8 size=1
// signature: undefined __list_add_valid(void)
// callers: [ubwcp_register_error_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0011b0f0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [ubwcp_unregister_error_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0011b0f8 size=1
// signature: undefined kfree(void)
// callers: [ubwcp_free_buffer, ubwcp_unregister_error_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 0011b100 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [ubwcp_probe, ubwcp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0011b108 size=1
// signature: undefined devm_kmalloc(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 0011b110 size=1
// signature: undefined dma_set_mask(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 0011b118 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_platform_ioremap_resource @ 0011b120 size=1
// signature: undefined devm_platform_ioremap_resource(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_platform_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 0011b128 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u64_index @ 0011b130 size=1
// signature: undefined of_property_read_u64_index(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u64_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_get_domain_for_dev @ 0011b138 size=1
// signature: undefined iommu_get_domain_for_dev(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_get_domain_for_dev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_set_fault_handler @ 0011b140 size=1
// signature: undefined iommu_set_fault_handler(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_set_fault_handler(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 0011b148 size=1
// signature: undefined of_property_read_string(void)
// callers: [ubwcp_probe, ubwcp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 0011b150 size=1
// signature: undefined dma_free_attrs(void)
// callers: [ubwcp_probe, ubwcp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0011b158 size=1
// signature: undefined __mutex_init(void)
// callers: [ubwcp_probe, ubwcp_init_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 0011b160 size=1
// signature: undefined devm_regulator_get(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 0011b168 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0011b170 size=1
// signature: undefined of_find_property(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_prop_next_string @ 0011b178 size=1
// signature: undefined of_prop_next_string(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_prop_next_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 0011b180 size=1
// signature: undefined devm_clk_get(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_create @ 0011b188 size=1
// signature: undefined gen_pool_create(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_add_owner @ 0011b190 size=1
// signature: undefined gen_pool_add_owner(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_add_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_destroy @ 0011b198 size=1
// signature: undefined gen_pool_destroy(void)
// callers: [ubwcp_probe, ubwcp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 0011b1a0 size=1
// signature: undefined debugfs_remove(void)
// callers: [ubwcp_debugfs_init, ubwcp_probe, ubwcp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0011b1b0 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [ubwcp_probe, ubwcp_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_ubwcp_set_ops @ 0011b1b8 size=1
// signature: undefined msm_ubwcp_set_ops(void)
// callers: [ubwcp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_ubwcp_set_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_avail @ 0011b1c0 size=1
// signature: undefined gen_pool_avail(void)
// callers: [ubwcp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_avail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_size @ 0011b1c8 size=1
// signature: undefined gen_pool_size(void)
// callers: [ubwcp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 0011b1d0 size=1
// signature: undefined device_destroy(void)
// callers: [ubwcp_cdev_init, ubwcp_cdev_deinit, ubwcp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 0011b1d8 size=1
// signature: undefined class_destroy(void)
// callers: [ubwcp_cdev_init, ubwcp_cdev_deinit, ubwcp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 0011b1e0 size=1
// signature: undefined cdev_del(void)
// callers: [ubwcp_cdev_deinit, ubwcp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 0011b1e8 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [ubwcp_cdev_init, ubwcp_cdev_deinit, ubwcp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0011b1f0 size=1
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
// platform_driver_unregister @ 0011b1f8 size=1
// signature: undefined platform_driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_raw_output_prep @ 0011b200 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_ubwcp_dmabuf_event, trace_raw_output_ubwcp_sync_event, trace_raw_output_ubwcp_size_event, trace_raw_output_ubwcp_int_event, trace_raw_output_ubwcp_platform_device_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 0011b208 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_ubwcp_dmabuf_event, trace_raw_output_ubwcp_sync_event, trace_raw_output_ubwcp_size_event, trace_raw_output_ubwcp_int_event, trace_raw_output_ubwcp_platform_device_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 0011b210 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_ubwcp_dmabuf_event, trace_raw_output_ubwcp_sync_event, trace_raw_output_ubwcp_size_event, trace_raw_output_ubwcp_int_event, trace_raw_output_ubwcp_platform_device_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_has_addr @ 0011b218 size=1
// signature: undefined gen_pool_has_addr(void)
// callers: [ubwcp_ula_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_has_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_free_owner @ 0011b220 size=1
// signature: undefined gen_pool_free_owner(void)
// callers: [ubwcp_ula_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_free_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 0011b228 size=1
// signature: undefined regulator_enable(void)
// callers: [ubwcp_power]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 0011b230 size=1
// signature: undefined regulator_disable(void)
// callers: [ubwcp_power]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 0011b238 size=1
// signature: undefined clk_disable(void)
// callers: [ubwcp_power]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 0011b240 size=1
// signature: undefined clk_unprepare(void)
// callers: [ubwcp_power]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 0011b248 size=1
// signature: undefined clk_prepare(void)
// callers: [ubwcp_power]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 0011b250 size=1
// signature: undefined clk_enable(void)
// callers: [ubwcp_power]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memunmap_pages @ 0011b258 size=1
// signature: undefined memunmap_pages(void)
// callers: [ula_unmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void memunmap_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memremap_pages @ 0011b260 size=1
// signature: undefined memremap_pages(void)
// callers: [ula_add_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void memremap_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpus_read_lock @ 0011b270 size=1
// signature: undefined cpus_read_lock(void)
// callers: [prefetch_tgt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpus_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 0011b280 size=1
// signature: undefined _find_next_bit(void)
// callers: [prefetch_tgt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// smp_call_function_single @ 0011b288 size=1
// signature: undefined smp_call_function_single(void)
// callers: [prefetch_tgt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void smp_call_function_single(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpus_read_unlock @ 0011b290 size=1
// signature: undefined cpus_read_unlock(void)
// callers: [prefetch_tgt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpus_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_prefetch_tgt_ctrl @ 0011b298 size=1
// signature: undefined qcom_scm_prefetch_tgt_ctrl(void)
// callers: [prefetch_tgt_per_cpu]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_prefetch_tgt_ctrl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 0011b2a0 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [ubwcp_cdev_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 0011b2a8 size=1
// signature: undefined __class_create(void)
// callers: [ubwcp_cdev_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 0011b2b0 size=1
// signature: undefined device_create(void)
// callers: [ubwcp_cdev_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 0011b2b8 size=1
// signature: undefined cdev_init(void)
// callers: [ubwcp_cdev_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 0011b2c0 size=1
// signature: undefined cdev_add(void)
// callers: [ubwcp_cdev_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 0011b2c8 size=1
// signature: undefined platform_get_irq(void)
// callers: [ubwcp_interrupt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 0011b2d0 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [ubwcp_interrupt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 0011b2d8 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [ubwcp_debugfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_u32 @ 0011b2e0 size=1
// signature: undefined debugfs_create_u32(void)
// callers: [ubwcp_debugfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_u32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 0011b2e8 size=1
// signature: undefined debugfs_create_file(void)
// callers: [ubwcp_debugfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 0011b2f8 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [ubwcp_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_get @ 0011b300 size=1
// signature: undefined dma_buf_get(void)
// callers: [ubwcp_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 0011b308 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [ubwcp_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_put @ 0011b310 size=1
// signature: undefined dma_buf_put(void)
// callers: [ubwcp_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_attr_open @ 0011b320 size=1
// signature: undefined simple_attr_open(void)
// callers: [reg_rw_trace_fops_open, write_err_fops_open, single_tile_fops_open, encode_err_fops_open, decode_err_fops_open, read_err_fops_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_attr_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_sync_single_for_device @ 0011b328 size=1
// signature: undefined dma_sync_single_for_device(void)
// callers: [unlock_internal]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_sync_single_for_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 0011b358 size=1
// signature: undefined __const_udelay(void)
// callers: [ubwcp_hw_flush]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 0011b360 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 0011b368 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 0011b370 size=1
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
// log_post_write_mmio @ 0011b378 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



