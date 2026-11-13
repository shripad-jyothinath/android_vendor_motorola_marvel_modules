// Decompiled by Ghidra 12.2
// Program: cnss_nl.ko
// Image base: 00100000

//------------------------------------------------------------
// register_cld_cmd_cb @ 0010014c size=96
// signature: undefined register_cld_cmd_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 register_cld_cmd_cb(uint param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long lVar2;
  
  if ((param_1 & 0xff) - 0x29 < 0xffffffd8) {
    return 0xffffffea;
  }
  lVar2 = (ulong)(param_1 & 0xff) - 1;
  if (((0x280 < (ulong)(lVar2 * 0x10)) || (lVar2 == 0x28)) ||
     (*(undefined8 *)(&nl_data + lVar2 * 0x10) = param_2, 0x280 < (lVar2 * 0x10 | 8U))) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(1,0x1001ac);
    (*pcVar1)();
  }
  *(undefined8 *)(&DAT_00100580 + lVar2 * 0x10) = param_3;
  return 0;
}



//------------------------------------------------------------
// deregister_cld_cmd_cb @ 001001b0 size=48
// signature: undefined deregister_cld_cmd_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 deregister_cld_cmd_cb(uint param_1)

{
  long lVar1;
  char *pcVar2;
  
  if ((param_1 & 0xff) - 0x29 < 0xffffffd8) {
    return 0xffffffea;
  }
  lVar1 = (ulong)(param_1 & 0xff) * 0x10;
  pcVar2 = "name=cnss_nl" + lVar1 + 0xc;
  pcVar2[0] = '\0';
  pcVar2[1] = '\0';
  pcVar2[2] = '\0';
  pcVar2[3] = '\0';
  pcVar2[4] = '\0';
  pcVar2[5] = '\0';
  pcVar2[6] = '\0';
  pcVar2[7] = '\0';
  pcVar2 = "depends=" + lVar1 + 7;
  pcVar2[0] = '\0';
  pcVar2[1] = '\0';
  pcVar2[2] = '\0';
  pcVar2[3] = '\0';
  pcVar2[4] = '\0';
  pcVar2[5] = '\0';
  pcVar2[6] = '\0';
  pcVar2[7] = '\0';
  return 0;
}



//------------------------------------------------------------
// cld80211_get_genl_family @ 001001e4 size=12
// signature: undefined cld80211_get_genl_family(void)
// callers: []
//------------------------------------------------------------

undefined1 * cld80211_get_genl_family(void)

{
  return &cld80211_fam;
}



//------------------------------------------------------------
// cld80211_pre_doit @ 001001f4 size=128
// signature: undefined cld80211_pre_doit(void)
// callers: []
//------------------------------------------------------------

undefined8 cld80211_pre_doit(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  if (*(byte *)(param_1 + 0x2c) - 0x29 < 0xffffffd8) {
    _printk(&DAT_001011a9);
    uVar3 = 0xffffffa1;
  }
  else {
    uVar1 = *(byte *)(param_1 + 0x2c) - 1;
    uVar4 = (ulong)uVar1;
    if ((0x27 < uVar1) ||
       (*(undefined8 *)(param_3 + 0x30) = *(undefined8 *)(&nl_data + uVar4 * 0x10),
       0x280 < (uVar4 << 4 | 8))) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x100274);
      (*pcVar2)();
    }
    uVar3 = 0;
    *(undefined8 *)(param_3 + 0x38) = *(undefined8 *)(&DAT_00100580 + uVar4 * 0x10);
  }
  return uVar3;
}



//------------------------------------------------------------
// cld80211_doit @ 00100278 size=136
// signature: undefined cld80211_doit(void)
// callers: []
//------------------------------------------------------------

undefined8 cld80211_doit(undefined8 param_1,long param_2)

{
  ushort *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  
  pcVar3 = *(code **)(param_2 + 0x30);
  if (pcVar3 == (code *)0x0) {
    _printk(&DAT_001011ea);
    uVar2 = 0xffffffa1;
  }
  else {
    puVar1 = *(ushort **)(*(long *)(param_2 + 0x20) + 8);
    if (puVar1 == (ushort *)0x0) {
      _printk(&DAT_00101239);
      uVar2 = 0xffffffea;
    }
    else {
      if (*(int *)(pcVar3 + -4) != 0x422b553a) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x1002c4);
        (*pcVar3)();
      }
      (*pcVar3)(puVar1 + 2,*puVar1 - 4,*(undefined8 *)(param_2 + 0x38),*(undefined4 *)(param_2 + 4))
      ;
      uVar2 = 0;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 00100348 size=224
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  undefined1 *puVar4;
  
  lVar2 = of_find_node_with_property(0,"qcom,wlan");
  if (lVar2 != 0) {
    do {
      uVar3 = of_device_is_available(lVar2);
      if ((uVar3 & 1) != 0) {
        memset(&nl_ops,0,0x8c0);
        _printk(&DAT_001011d0);
        lVar2 = 1;
        puVar4 = &DAT_00100826;
        do {
          puVar4[-2] = (char)lVar2;
          lVar2 = lVar2 + 1;
          *(code **)(puVar4 + -0x2e) = cld80211_doit;
          *puVar4 = 1;
          puVar4 = puVar4 + 0x38;
        } while (lVar2 != 0x29);
        iVar1 = genl_register_family(&cld80211_fam);
        if (iVar1 == 0) {
          return 0;
        }
        _printk(&DAT_00101205,iVar1);
        return iVar1;
      }
      lVar2 = of_find_node_with_property(lVar2,"qcom,wlan");
    } while (lVar2 != 0);
  }
  return -0x13;
}



//------------------------------------------------------------
// cleanup_module @ 0010042c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  genl_unregister_family(&cld80211_fam);
  return;
}



//------------------------------------------------------------
// of_find_node_with_property @ 00102000 size=1
// signature: undefined of_find_node_with_property(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_with_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_available @ 00102008 size=1
// signature: undefined of_device_is_available(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00102010 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102018 size=1
// signature: undefined _printk(void)
// callers: [cld80211_pre_doit, cld80211_doit, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genl_register_family @ 00102020 size=1
// signature: undefined genl_register_family(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genl_register_family(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genl_unregister_family @ 00102028 size=1
// signature: undefined genl_unregister_family(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genl_unregister_family(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



