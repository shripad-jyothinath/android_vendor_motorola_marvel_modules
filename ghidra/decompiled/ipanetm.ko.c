// Decompiled by Ghidra 12.2
// Program: ipanetm.ko
// Image base: 00100000

//------------------------------------------------------------
// init_module @ 00100084 size=544
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int init_module(void)

{
  int iVar1;
  
  if (_ipa3_ctx != 0) {
    if (*(long *)(_ipa3_ctx + 0x85a0) != 0) {
      ipc_log_string(*(long *)(_ipa3_ctx + 0x85a0),"ipa %s:%d IPA late init\n","ipa_late_init",0x20)
      ;
    }
    if (*(long *)(_ipa3_ctx + 0x85a8) != 0) {
      ipc_log_string(*(long *)(_ipa3_ctx + 0x85a8),"ipa %s:%d IPA late init\n","ipa_late_init",0x20)
      ;
    }
  }
  iVar1 = ipa3_wwan_platform_driver_register();
  if (iVar1 != 0) {
    _printk(&DAT_001003f0,"ipa_late_init",0x25,iVar1);
    if (_ipa3_ctx != 0) {
      if (*(long *)(_ipa3_ctx + 0x85a0) != 0) {
        ipc_log_string(*(long *)(_ipa3_ctx + 0x85a0),
                       "ipa %s:%d ipa3_wwan_platform_driver_register failed: %d\n","ipa_late_init",
                       0x25,iVar1);
      }
      if (*(long *)(_ipa3_ctx + 0x85a8) != 0) {
        ipc_log_string(*(long *)(_ipa3_ctx + 0x85a8),
                       "ipa %s:%d ipa3_wwan_platform_driver_register failed: %d\n","ipa_late_init",
                       0x25,iVar1);
      }
    }
    ipa3_wwan_cleanup();
  }
  iVar1 = rndis_ipa_init_module();
  if (iVar1 != 0) {
    _printk(&DAT_0010042b,"ipa_late_init",0x2c,iVar1);
    if (_ipa3_ctx != 0) {
      if (*(long *)(_ipa3_ctx + 0x85a0) != 0) {
        ipc_log_string(*(long *)(_ipa3_ctx + 0x85a0),"ipa %s:%d rndis_ipa_init_module failed: %d\n",
                       "ipa_late_init",0x2c,iVar1);
      }
      if (*(long *)(_ipa3_ctx + 0x85a8) != 0) {
        ipc_log_string(*(long *)(_ipa3_ctx + 0x85a8),"ipa %s:%d rndis_ipa_init_module failed: %d\n",
                       "ipa_late_init",0x2c,iVar1);
      }
    }
    rndis_ipa_cleanup_module();
  }
  iVar1 = ncm_ipa_init_module();
  if (iVar1 != 0) {
    _printk(&DAT_001004aa,"ipa_late_init",0x33,iVar1);
    if (_ipa3_ctx != 0) {
      if (*(long *)(_ipa3_ctx + 0x85a0) != 0) {
        ipc_log_string(*(long *)(_ipa3_ctx + 0x85a0),"ipa %s:%d ncm_ipa_init_module failed: %d\n",
                       "ipa_late_init",0x33,iVar1);
      }
      if (*(long *)(_ipa3_ctx + 0x85a8) != 0) {
        ipc_log_string(*(long *)(_ipa3_ctx + 0x85a8),"ipa %s:%d ncm_ipa_init_module failed: %d\n",
                       "ipa_late_init",0x33,iVar1);
      }
    }
    ncm_ipa_cleanup_module();
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 001002a8 size=132
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cleanup_module(void)

{
  if (_ipa3_ctx != 0) {
    if (*(long *)(_ipa3_ctx + 0x85a0) != 0) {
      ipc_log_string(*(long *)(_ipa3_ctx + 0x85a0),"ipa %s:%d IPA late exit\n","ipa_late_exit",0x3c)
      ;
    }
    if (*(long *)(_ipa3_ctx + 0x85a8) != 0) {
      ipc_log_string(*(long *)(_ipa3_ctx + 0x85a8),"ipa %s:%d IPA late exit\n","ipa_late_exit",0x3c)
      ;
    }
  }
  ipa3_wwan_cleanup();
  rndis_ipa_cleanup_module();
  ncm_ipa_cleanup_module();
  return;
}



//------------------------------------------------------------
// ipc_log_string @ 00101008 size=1
// signature: undefined ipc_log_string(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipa3_wwan_platform_driver_register @ 00101010 size=1
// signature: undefined ipa3_wwan_platform_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipa3_wwan_platform_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rndis_ipa_init_module @ 00101018 size=1
// signature: undefined rndis_ipa_init_module(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rndis_ipa_init_module(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ncm_ipa_init_module @ 00101020 size=1
// signature: undefined ncm_ipa_init_module(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ncm_ipa_init_module(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00101028 size=1
// signature: undefined _printk(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipa3_wwan_cleanup @ 00101030 size=1
// signature: undefined ipa3_wwan_cleanup(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipa3_wwan_cleanup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rndis_ipa_cleanup_module @ 00101038 size=1
// signature: undefined rndis_ipa_cleanup_module(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rndis_ipa_cleanup_module(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ncm_ipa_cleanup_module @ 00101040 size=1
// signature: undefined ncm_ipa_cleanup_module(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ncm_ipa_cleanup_module(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



