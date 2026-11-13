// Decompiled by Ghidra 12.2
// Program: audio_prm_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// audio_prm_set_lpi_logging_status @ 001002f4 size=12
// signature: undefined audio_prm_set_lpi_logging_status(void)
// callers: []
//------------------------------------------------------------

void audio_prm_set_lpi_logging_status(undefined4 param_1)

{
  DAT_00100f7c = param_1;
  return;
}



//------------------------------------------------------------
// _audio_prm_set_lpass_hw_core_req @ 00100304 size=184
// signature: undefined _audio_prm_set_lpass_hw_core_req(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _audio_prm_set_lpass_hw_core_req(undefined4 param_1,char param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)kmalloc_trace(_init_wait_entry,0xdc0,0x3c);
  if (puVar2 == (undefined4 *)0x0) {
    uVar1 = 0xfffffff4;
  }
  else {
    *puVar2 = 0x3c60;
    uVar1 = 0x100100f;
    *(undefined2 *)(puVar2 + 1) = 0x302;
    if (param_2 == '\0') {
      uVar1 = 0x1001010;
    }
    *(undefined8 *)(puVar2 + 2) = 0x200000007;
    puVar2[0xe] = param_1;
    puVar2[4] = 0;
    puVar2[5] = uVar1;
    *(undefined8 *)(puVar2 + 6) = 0;
    *(undefined8 *)(puVar2 + 8) = 0x1400000000;
    *(undefined8 *)(puVar2 + 10) = 0x800103200000002;
    *(undefined8 *)(puVar2 + 0xc) = 4;
    uVar1 = prm_gpr_send_pkt();
    kfree(puVar2);
  }
  return uVar1;
}



//------------------------------------------------------------
// prm_gpr_send_pkt @ 001003bc size=620
// signature: undefined prm_gpr_send_pkt(void)
// callers: [audio_prm_set_lpass_clk_cfg, _audio_prm_set_lpass_hw_core_req, audio_prm_set_cdc_earpa_duty_cycling_req, audio_prm_set_vote_against_sleep, audio_prm_set_lpass_hw_core_req]
//------------------------------------------------------------

int prm_gpr_send_pkt(undefined8 param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  mutex_lock(&DAT_00100f40);
  DAT_00100f74 = 1;
  DAT_00100f78 = 0;
  if (g_prm == 0) {
    _printk(&DAT_00101410,"prm_gpr_send_pkt");
    iVar1 = -0x13;
  }
  else {
    if ((((is_apm_ready_check_done & 1) == 0) && (DAT_00100f80 != '\0')) &&
       (iVar1 = gpr_get_q6_state(), iVar1 == 2)) {
      _printk(&DAT_0010122a,"prm_gpr_send_pkt");
      uVar2 = spf_core_is_apm_ready(0);
      if ((uVar2 & 1) == 0) {
        msleep(2);
        uVar2 = spf_core_is_apm_ready(0);
        if ((uVar2 & 1) == 0) {
          msleep(2);
          uVar2 = spf_core_is_apm_ready(0);
          if ((uVar2 & 1) == 0) {
            msleep(2);
            spf_core_is_apm_ready(0);
          }
        }
      }
      is_apm_ready_check_done = 1;
      _printk(&DAT_001013e5,"prm_gpr_send_pkt");
    }
    DAT_00100f70 = '\0';
    iVar1 = gpr_send_pkt(g_prm,param_1);
    if (iVar1 < 0) {
      _printk(&DAT_001012fb,"prm_gpr_send_pkt",iVar1);
    }
    else {
      if (DAT_00100f70 == '\0') {
        local_48 = 0;
        uStack_40 = 0;
        local_58 = 0;
        uStack_50 = 0;
        local_60 = 0;
        init_wait_entry(&local_60,0);
        prepare_to_wait_event(&DAT_00100f28,&local_60,2);
        if (DAT_00100f70 == '\0') {
          lVar3 = 0xfa;
          do {
            lVar3 = schedule_timeout(lVar3);
            prepare_to_wait_event(&DAT_00100f28,&local_60,2);
            if (lVar3 == 0 && DAT_00100f70 != '\0') {
              lVar3 = 1;
            }
          } while ((DAT_00100f70 == '\0') && (lVar3 != 0));
          finish_wait(&DAT_00100f28,&local_60);
          if ((int)lVar3 == 0) {
            _printk(&DAT_0010139e,"prm_gpr_send_pkt");
            iVar1 = -0x6e;
            goto LAB_001004f8;
          }
        }
        else {
          finish_wait(&DAT_00100f28,&local_60);
        }
      }
      if (DAT_00100f78 < 1) {
        iVar1 = 0;
      }
      else {
        _printk(&DAT_00101328,"prm_gpr_send_pkt",DAT_00100f78);
        iVar1 = -0x16;
      }
    }
  }
LAB_001004f8:
  mutex_unlock(&DAT_00100f40);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// audio_prm_set_lpass_hw_core_req @ 0010062c size=256
// signature: undefined audio_prm_set_lpass_hw_core_req(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 audio_prm_set_lpass_hw_core_req(undefined8 param_1,int param_2,char param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  iVar2 = DAT_00100f84;
  uVar3 = 0x8001032;
  if (param_2 == 1) {
    puVar4 = (undefined4 *)kmalloc_trace(_init_wait_entry,0xdc0,0x3c);
    if (iVar2 != 0) {
      uVar3 = 0x8001a6e;
    }
    if (puVar4 == (undefined4 *)0x0) {
      return 0xfffffff4;
    }
    param_2 = 1;
  }
  else {
    puVar4 = (undefined4 *)kmalloc_trace(_init_wait_entry,0xdc0,0x3c);
    if (puVar4 == (undefined4 *)0x0) {
      return 0xfffffff4;
    }
  }
  *puVar4 = 0x3c60;
  uVar1 = 0x100100f;
  *(undefined8 *)(puVar4 + 2) = 0x200000007;
  if (param_3 == '\0') {
    uVar1 = 0x1001010;
  }
  *(undefined2 *)(puVar4 + 1) = 0x302;
  puVar4[0xe] = param_2;
  puVar4[4] = 0;
  puVar4[5] = uVar1;
  *(undefined8 *)(puVar4 + 6) = 0;
  *(undefined8 *)(puVar4 + 8) = 0x1400000000;
  puVar4[10] = 2;
  puVar4[0xb] = uVar3;
  *(undefined8 *)(puVar4 + 0xc) = 4;
  uVar3 = prm_gpr_send_pkt(puVar4);
  kfree(puVar4);
  return uVar3;
}



//------------------------------------------------------------
// audio_prm_set_cdc_earpa_duty_cycling_req @ 00100730 size=256
// signature: undefined audio_prm_set_cdc_earpa_duty_cycling_req(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 audio_prm_set_cdc_earpa_duty_cycling_req(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)kmalloc_trace(_prepare_to_wait_event,0xdc0,0x7c);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0xfffffff4;
  }
  else {
    uVar3 = 0x100100f;
    *puVar4 = 0x7c60;
    if (param_2 == 0) {
      uVar3 = 0x1001010;
    }
    *(undefined2 *)(puVar4 + 1) = 0x302;
    puVar4[4] = 0;
    puVar4[5] = uVar3;
    *(undefined8 *)(puVar4 + 2) = 0x200000007;
    *(undefined8 *)(puVar4 + 10) = 0x800131b00000002;
    *(undefined8 *)(puVar4 + 0xc) = 0x44;
    uVar3 = *param_1;
    uVar1 = param_1[1];
    *(undefined8 *)(puVar4 + 6) = 0;
    *(undefined8 *)(puVar4 + 8) = 0x5400000000;
    puVar4[0x10] = 0;
    puVar4[0x11] = uVar3;
    *(undefined8 *)(puVar4 + 0xe) = 0x100000002;
    *(undefined8 *)(puVar4 + 0x12) = 0x100000002;
    *(undefined8 *)(puVar4 + 0x14) = 0x200000034;
    uVar3 = param_1[2];
    uVar2 = param_1[3];
    *(undefined8 *)(puVar4 + 0x16) = 0x200000024;
    puVar4[0x18] = 0;
    puVar4[0x19] = uVar1;
    puVar4[0x1e] = uVar2;
    *(undefined8 *)(puVar4 + 0x1a) = 0x300000002;
    puVar4[0x1c] = uVar3;
    puVar4[0x1d] = 4;
    uVar3 = prm_gpr_send_pkt();
    kfree(puVar4);
  }
  return uVar3;
}



//------------------------------------------------------------
// audio_prm_set_vote_against_sleep @ 00100834 size=208
// signature: undefined audio_prm_set_vote_against_sleep(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 audio_prm_set_vote_against_sleep(char param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  iVar2 = DAT_00100f84;
  puVar4 = (undefined4 *)kmalloc_trace(_init_wait_entry,0xdc0,0x3c);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0xfffffff4;
  }
  else {
    uVar3 = 0x8001032;
    if (iVar2 != 0) {
      uVar3 = 0x8001a6e;
    }
    *puVar4 = 0x3c60;
    uVar1 = 0x100100f;
    *(undefined8 *)(puVar4 + 2) = 0x200000007;
    if (param_1 == '\0') {
      uVar1 = 0x1001010;
    }
    *(undefined2 *)(puVar4 + 1) = 0x302;
    puVar4[4] = 0;
    puVar4[5] = uVar1;
    *(undefined8 *)(puVar4 + 6) = 0;
    *(undefined8 *)(puVar4 + 8) = 0x1400000000;
    puVar4[0xe] = 1;
    puVar4[10] = 2;
    puVar4[0xb] = uVar3;
    *(undefined8 *)(puVar4 + 0xc) = 4;
    uVar3 = prm_gpr_send_pkt();
    kfree(puVar4);
  }
  return uVar3;
}



//------------------------------------------------------------
// audio_prm_set_lpass_clk_cfg @ 00100908 size=360
// signature: undefined audio_prm_set_lpass_clk_cfg(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 audio_prm_set_lpass_clk_cfg(int *param_1,char param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  
  if (param_2 == '\0') {
    puVar6 = (undefined4 *)kmalloc_trace(_init_wait_entry,0xdc0,0x40);
    if (puVar6 == (undefined4 *)0x0) {
      return 0xfffffff4;
    }
    iVar1 = *param_1;
    *puVar6 = 0x4060;
    *(undefined8 *)(puVar6 + 2) = 0x200000007;
    *(undefined2 *)(puVar6 + 1) = 0x302;
    puVar6[4] = 0;
    puVar6[5] = 0x1001010;
    *(undefined8 *)(puVar6 + 6) = 0;
    *(undefined8 *)(puVar6 + 8) = 0x1800000000;
    *(undefined8 *)(puVar6 + 10) = 0x800102c00000002;
    *(undefined8 *)(puVar6 + 0xc) = 8;
    puVar6[0xe] = 1;
    puVar6[0xf] = iVar1;
  }
  else {
    puVar6 = (undefined4 *)kmalloc_trace(_prepare_to_wait_event,0xdc0,0x4c);
    if (puVar6 == (undefined4 *)0x0) {
      return 0xfffffff4;
    }
    iVar1 = *param_1;
    iVar2 = param_1[1];
    *puVar6 = 0x4c60;
    iVar7 = DAT_00100f7c;
    iVar3 = param_1[2];
    *(undefined2 *)(puVar6 + 1) = 0x302;
    *(undefined8 *)(puVar6 + 2) = 0x200000007;
    *(undefined8 *)(puVar6 + 4) = 0x100100f00000000;
    if (((iVar7 == 0) || (uVar4 = (uint)(CONCAT44(iVar1,iVar1 + -0x30c) >> 1), 5 < uVar4)) ||
       ((0x39U >> (ulong)(uVar4 & 0x1f) & 1) == 0)) {
      iVar7 = param_1[3];
    }
    else {
      iVar7 = 2;
    }
    *(undefined8 *)(puVar6 + 6) = 0;
    *(undefined8 *)(puVar6 + 8) = 0x2400000000;
    puVar6[0x10] = iVar2;
    puVar6[0x11] = iVar3;
    *(undefined8 *)(puVar6 + 10) = 0x800102c00000002;
    *(undefined8 *)(puVar6 + 0xc) = 0x14;
    puVar6[0xe] = 1;
    puVar6[0xf] = iVar1;
    puVar6[0x12] = iVar7;
  }
  uVar5 = prm_gpr_send_pkt(puVar6);
  kfree(puVar6);
  return uVar5;
}



//------------------------------------------------------------
// audio_prm_probe @ 00100a74 size=256
// signature: undefined audio_prm_probe(void)
// callers: []
//------------------------------------------------------------

int audio_prm_probe(long param_1)

{
  int iVar1;
  ulong uVar2;
  undefined *puVar3;
  int iVar4;
  
  uVar2 = audio_notifier_probe_status();
  if ((uVar2 & 1) == 0) {
    _printk(&DAT_00101452,"audio_prm_probe");
    iVar1 = -0x205;
  }
  else {
    of_property_read_variable_u32_array
              (*(undefined8 *)(param_1 + 0x2e8),"qcom,sleep-api-supported",&DAT_00100f84,1,0);
    iVar1 = audio_notifier_register("audio_prm",0,&service_nb);
    if (iVar1 < 0) {
      if (iVar1 == -0x205) {
        return -0x205;
      }
      puVar3 = &DAT_001013b6;
      iVar4 = iVar1;
    }
    else {
      *(long **)(param_1 + 0x98) = &g_prm;
      g_prm = param_1;
      __init_waitqueue_head(&DAT_00100f28,"&g_prm.wait",&audio_prm_probe___key);
      puVar3 = &DAT_00101345;
      DAT_00100f80 = 1;
      iVar4 = DAT_00100f84;
    }
    _printk(puVar3,"audio_prm_probe",iVar4);
  }
  return iVar1;
}



//------------------------------------------------------------
// audio_prm_remove @ 00100b78 size=84
// signature: undefined audio_prm_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 audio_prm_remove(void)

{
  audio_notifier_deregister("audio_prm");
  mutex_lock(&DAT_00100f40);
  DAT_00100f80 = 0;
  g_prm = 0;
  mutex_unlock(&DAT_00100f40);
  return 0;
}



//------------------------------------------------------------
// audio_prm_callback @ 00100bd0 size=376
// signature: undefined audio_prm_callback(void)
// callers: []
//------------------------------------------------------------

undefined8 audio_prm_callback(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  int *piVar2;
  
  piVar2 = (int *)((long)param_2 + ((ulong)(*param_2 >> 2) & 0x3c));
  if (param_2[5] + 0xfdffeffe < 2) {
    if (piVar2[1] != 0) {
      DAT_00100f78 = piVar2[1];
      _printk(&DAT_001012d3,"audio_prm_callback",*piVar2,piVar2[1]);
    }
    DAT_00100f70 = '\x01';
    uVar1 = *piVar2 + 0xf7ffefd5;
    if (((uVar1 < 8) && ((1 << (ulong)(uVar1 & 0x1f) & 0x83U) != 0)) || (*piVar2 == 0x8001a6e)) {
      if (piVar2[1] == 0) {
        DAT_00100f74 = 0;
      }
      else {
        _printk(&DAT_0010124a,"audio_prm_callback");
        DAT_00100f74 = piVar2[1];
      }
    }
    else {
      _printk(&DAT_00101491,"audio_prm_callback");
    }
  }
  else if (param_2[5] == 0x2001005) {
    _printk(&DAT_001012aa,"audio_prm_callback");
    DAT_00100f78 = piVar2[1];
    DAT_00100f70 = '\x01';
    goto LAB_00100c8c;
  }
  if (DAT_00100f70 == '\0') {
    return 0;
  }
LAB_00100c8c:
  __wake_up(&DAT_00100f28,3,1,0);
  return 0;
}



//------------------------------------------------------------
// audio_prm_service_cb @ 00100d4c size=136
// signature: undefined audio_prm_service_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 audio_prm_service_cb(undefined8 param_1,long param_2)

{
  _printk(&DAT_001014cd,"audio_prm_service_cb",param_2);
  if (param_2 == 1) {
    mutex_lock(&DAT_00100f40);
    DAT_00100f80 = 1;
  }
  else {
    if (param_2 != 0) {
      return 1;
    }
    mutex_lock(&DAT_00100f40);
    DAT_00100f80 = 0;
    is_apm_ready_check_done = 0;
  }
  mutex_unlock();
  return 1;
}



//------------------------------------------------------------
// init_module @ 00100e80 size=120
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = __gpr_driver_register(&qcom_audio_prm_driver,&__this_module);
  if (iVar1 != 0) {
    _printk(&DAT_0010142b,"audio_prm_module_init",iVar1);
  }
  __mutex_init(&DAT_00100f40,"&g_prm.lock",&audio_prm_module_init___key);
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00100efc size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  gpr_driver_unregister(&qcom_audio_prm_driver);
  return;
}



//------------------------------------------------------------
// kmalloc_trace @ 00103008 size=1
// signature: undefined kmalloc_trace(void)
// callers: [audio_prm_set_lpass_clk_cfg, _audio_prm_set_lpass_hw_core_req, audio_prm_set_cdc_earpa_duty_cycling_req, audio_prm_set_vote_against_sleep, audio_prm_set_lpass_hw_core_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00103010 size=1
// signature: undefined kfree(void)
// callers: [audio_prm_set_lpass_clk_cfg, _audio_prm_set_lpass_hw_core_req, audio_prm_set_cdc_earpa_duty_cycling_req, audio_prm_set_vote_against_sleep, audio_prm_set_lpass_hw_core_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103018 size=1
// signature: undefined mutex_lock(void)
// callers: [audio_prm_service_cb, audio_prm_remove, prm_gpr_send_pkt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpr_get_q6_state @ 00103020 size=1
// signature: undefined gpr_get_q6_state(void)
// callers: [prm_gpr_send_pkt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpr_get_q6_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpr_send_pkt @ 00103028 size=1
// signature: undefined gpr_send_pkt(void)
// callers: [prm_gpr_send_pkt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpr_send_pkt(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00103030 size=1
// signature: undefined init_wait_entry(void)
// callers: [prm_gpr_send_pkt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00103038 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [prm_gpr_send_pkt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 00103040 size=1
// signature: undefined finish_wait(void)
// callers: [prm_gpr_send_pkt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 00103048 size=1
// signature: undefined schedule_timeout(void)
// callers: [prm_gpr_send_pkt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103050 size=1
// signature: undefined mutex_unlock(void)
// callers: [audio_prm_service_cb, audio_prm_remove, prm_gpr_send_pkt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103058 size=1
// signature: undefined _printk(void)
// callers: [init_module, audio_prm_callback, audio_prm_service_cb, prm_gpr_send_pkt, audio_prm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// spf_core_is_apm_ready @ 00103060 size=1
// signature: undefined spf_core_is_apm_ready(void)
// callers: [prm_gpr_send_pkt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void spf_core_is_apm_ready(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00103068 size=1
// signature: undefined msleep(void)
// callers: [prm_gpr_send_pkt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103070 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [prm_gpr_send_pkt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __gpr_driver_register @ 00103078 size=1
// signature: undefined __gpr_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __gpr_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00103080 size=1
// signature: undefined __mutex_init(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpr_driver_unregister @ 00103088 size=1
// signature: undefined gpr_driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpr_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// audio_notifier_probe_status @ 00103090 size=1
// signature: undefined audio_notifier_probe_status(void)
// callers: [audio_prm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void audio_notifier_probe_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00103098 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [audio_prm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// audio_notifier_register @ 001030a0 size=1
// signature: undefined audio_notifier_register(void)
// callers: [audio_prm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void audio_notifier_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 001030a8 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [audio_prm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// audio_notifier_deregister @ 001030b0 size=1
// signature: undefined audio_notifier_deregister(void)
// callers: [audio_prm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void audio_notifier_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 001030b8 size=1
// signature: undefined __wake_up(void)
// callers: [audio_prm_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



