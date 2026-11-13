// Decompiled by Ghidra 12.2
// Program: q6_pdr_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// audio_pdr_service_register @ 001000c4 size=96
// signature: undefined audio_pdr_service_register(void)
// callers: []
//------------------------------------------------------------

undefined8 audio_pdr_service_register(int param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    audio_pdr_services = pdr_handle_alloc(param_2,0);
    uVar1 = pdr_add_lookup(audio_pdr_services,s_avs_audio_00100228,s_msm_adsp_audio_pd_00100269);
  }
  else {
    _printk(&DAT_001001fc,"audio_pdr_service_register",param_1);
    uVar1 = 0xffffffffffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// audio_pdr_service_deregister @ 00100128 size=76
// signature: undefined audio_pdr_service_deregister(void)
// callers: []
//------------------------------------------------------------

undefined8 audio_pdr_service_deregister(int param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    pdr_handle_release(audio_pdr_services);
    uVar1 = 0;
  }
  else {
    _printk(&DAT_001001fc,"audio_pdr_service_deregister",param_1);
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// init_module @ 001001b4 size=8
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 001001c0 size=4
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  return;
}



//------------------------------------------------------------
// pdr_handle_alloc @ 00101000 size=1
// signature: undefined pdr_handle_alloc(void)
// callers: [audio_pdr_service_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pdr_handle_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pdr_add_lookup @ 00101008 size=1
// signature: undefined pdr_add_lookup(void)
// callers: [audio_pdr_service_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pdr_add_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00101010 size=1
// signature: undefined _printk(void)
// callers: [audio_pdr_service_deregister, audio_pdr_service_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pdr_handle_release @ 00101018 size=1
// signature: undefined pdr_handle_release(void)
// callers: [audio_pdr_service_deregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pdr_handle_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



