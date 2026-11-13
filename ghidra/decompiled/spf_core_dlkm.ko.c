// Decompiled by Ghidra 12.2
// Program: spf_core_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// spf_core_is_apm_ready @ 00100384 size=652
// signature: undefined spf_core_is_apm_ready(void)
// callers: [spf_core_add_child_devices]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool spf_core_is_apm_ready(int param_1)

{
  undefined8 *puVar1;
  long lVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  long lVar8;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined4 local_80;
  undefined2 local_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 local_6c;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  if (spf_core_priv == (undefined8 *)0x0) {
    bVar3 = false;
  }
  else {
    mutex_lock(spf_core_priv + 1);
    lVar2 = _jiffies;
    puVar6 = (undefined8 *)spf_core_priv[7];
    if (puVar6 == (undefined8 *)0x0) {
      bVar3 = false;
    }
    else {
      lVar5 = __msecs_to_jiffies(param_1);
      mutex_lock();
      puVar1 = puVar6 + 1;
      do {
        uVar7 = *puVar6;
        *(undefined8 *)((ulong)&local_80 | 4) = 0;
        ((undefined8 *)((ulong)&local_80 | 4))[1] = 0;
        local_80 = 0x1860;
        local_7c = 0x302;
        local_6c = 0x1001021;
        local_78 = 3;
        uStack_74 = 1;
        iVar4 = ___ratelimit(__spf_core_is_apm_ready__rs,"__spf_core_is_apm_ready");
        if (iVar4 != 0) {
          _dev_err(*spf_core_priv,"%s: send_command ret\n","__spf_core_is_apm_ready");
        }
        iVar4 = gpr_send_pkt(uVar7,&local_80);
        if (iVar4 < 0) {
LAB_00100530:
          bVar3 = false;
          *(undefined1 *)(puVar6 + 10) = 0;
        }
        else {
          if (*(char *)(puVar6 + 10) == '\0') {
            local_90 = 0;
            uStack_88 = 0;
            local_a0 = 0;
            uStack_98 = 0;
            local_a8 = 0;
            init_wait_entry(&local_a8,0);
            prepare_to_wait_event(puVar1,&local_a8,2);
            if (*(char *)(puVar6 + 10) == '\0') {
              lVar8 = 0xfa;
              do {
                lVar8 = schedule_timeout(lVar8);
                prepare_to_wait_event(puVar1,&local_a8,2);
                if (lVar8 == 0 && *(char *)(puVar6 + 10) != '\0') {
                  lVar8 = 1;
                }
              } while ((*(char *)(puVar6 + 10) == '\0') && (lVar8 != 0));
              finish_wait(puVar1,&local_a8);
              if (0 < (int)lVar8) goto LAB_001004fc;
            }
            else {
              finish_wait(puVar1,&local_a8);
LAB_001004fc:
              if (*(char *)(puVar6 + 10) != '\0') goto LAB_00100504;
            }
            iVar4 = ___ratelimit(__spf_core_is_apm_ready__rs_10,"__spf_core_is_apm_ready");
            if (iVar4 != 0) {
              _dev_err(*spf_core_priv,"%s: command timedout, ret\n","__spf_core_is_apm_ready");
            }
            goto LAB_00100530;
          }
LAB_00100504:
          bVar3 = *(int *)((long)puVar6 + 0x54) != 0;
          *(undefined1 *)(puVar6 + 10) = 0;
        }
        if ((param_1 == 0) || (bVar3 != false)) goto LAB_001005b8;
        usleep_range_state(50000,0xc382,2);
      } while (_jiffies - (lVar5 + lVar2) < 0);
      bVar3 = false;
LAB_001005b8:
      mutex_unlock(puVar6 + 4);
    }
    mutex_unlock(spf_core_priv + 1);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar3;
}



//------------------------------------------------------------
// spf_core_apm_close_all @ 00100614 size=684
// signature: undefined spf_core_apm_close_all(void)
// callers: []
//------------------------------------------------------------

void spf_core_apm_close_all(void)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  undefined2 local_5c;
  undefined2 uStack_5a;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 local_4c;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  local_54 = 0;
  uStack_50 = 0;
  local_5c = 0;
  uStack_5a = 0;
  uStack_58 = 0;
  if (spf_core_priv == (undefined8 *)0x0) goto LAB_0010086c;
  mutex_lock(spf_core_priv + 1);
  puVar7 = (undefined8 *)spf_core_priv[7];
  if (puVar7 != (undefined8 *)0x0) {
    mutex_lock(puVar7 + 4);
    uVar5 = *puVar7;
    local_60 = 0x1860;
    uStack_58 = 3;
    local_54 = 1;
    local_5c = 0x302;
    local_4c = 0x1001013;
    iVar2 = ___ratelimit(&spf_core_apm_close_all__rs,"spf_core_apm_close_all");
    if (iVar2 != 0) {
      _dev_info(*spf_core_priv,"%s: send_command \n","spf_core_apm_close_all");
    }
    iVar2 = gpr_send_pkt(uVar5,&local_60);
    if (iVar2 < 0) {
      iVar3 = ___ratelimit(spf_core_apm_close_all__rs_1,"spf_core_apm_close_all");
      if (iVar3 != 0) {
        pcVar4 = "%s: send_pkt_failed %d\n";
LAB_001007ec:
        _dev_err(*spf_core_priv,pcVar4,"spf_core_apm_close_all",iVar2);
      }
    }
    else {
      if (*(char *)(puVar7 + 10) == '\0') {
        local_70 = 0;
        uStack_68 = 0;
        local_80 = 0;
        uStack_78 = 0;
        local_88 = 0;
        init_wait_entry(&local_88,0);
        puVar1 = puVar7 + 1;
        prepare_to_wait_event(puVar1,&local_88,2);
        if (*(char *)(puVar7 + 10) == '\0') {
          lVar6 = 0x4e2;
          do {
            lVar6 = schedule_timeout(lVar6);
            prepare_to_wait_event(puVar1,&local_88,2);
            if (lVar6 == 0 && *(char *)(puVar7 + 10) != '\0') {
              lVar6 = 1;
            }
          } while ((*(char *)(puVar7 + 10) == '\0') && (lVar6 != 0));
        }
        else {
          lVar6 = 0x4e2;
        }
        iVar2 = (int)lVar6;
        finish_wait(puVar1,&local_88);
      }
      else {
        iVar2 = 0x4e2;
      }
      iVar3 = ___ratelimit(spf_core_apm_close_all__rs_3,"spf_core_apm_close_all");
      if (iVar3 != 0) {
        _dev_info(*spf_core_priv,"%s: wait event unblocked \n","spf_core_apm_close_all");
      }
      if ((iVar2 < 1) || (*(char *)(puVar7 + 10) == '\0')) {
        iVar2 = ___ratelimit(spf_core_apm_close_all__rs_7,"spf_core_apm_close_all");
        if (iVar2 != 0) {
          _dev_err(*spf_core_priv,"%s: command timedout, ret\n","spf_core_apm_close_all");
        }
      }
      else if ((*(int *)((long)puVar7 + 0x54) != 0) &&
              (iVar2 = ___ratelimit(spf_core_apm_close_all__rs_5,"spf_core_apm_close_all"),
              iVar2 != 0)) {
        pcVar4 = "%s, cmd failed status %d";
        iVar2 = *(int *)((long)puVar7 + 0x54);
        goto LAB_001007ec;
      }
    }
    *(undefined1 *)(puVar7 + 10) = 0;
    mutex_unlock(puVar7 + 4);
  }
  mutex_unlock(spf_core_priv + 1);
LAB_0010086c:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// spf_core_platform_driver_probe @ 001008c4 size=224
// signature: undefined spf_core_platform_driver_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 spf_core_platform_driver_probe(long param_1)

{
  long *plVar1;
  int iVar2;
  long *plVar3;
  undefined8 uVar4;
  
  _printk(&DAT_001018e8,"spf_core_platform_driver_probe");
  spf_core_priv = (long *)devm_kmalloc(param_1 + 0x10,0x78,0xdc0);
  if (spf_core_priv == (long *)0x0) {
    uVar4 = 0xfffffff4;
  }
  else {
    plVar3 = spf_core_priv + 1;
    *spf_core_priv = param_1 + 0x10;
    __mutex_init(plVar3,"&spf_core_priv->lock",&spf_core_platform_driver_probe___key);
    plVar1 = spf_core_priv;
    plVar3 = spf_core_priv + 10;
    spf_core_priv[9] = 0xfffffffe0;
    plVar1[10] = (long)plVar3;
    plVar1[0xb] = (long)plVar3;
    plVar1[0xc] = (long)spf_core_add_child_devices;
    *(undefined1 *)(plVar1 + 8) = 1;
    iVar2 = __gpr_driver_register(&qcom_spf_core_driver,&__this_module);
    if (iVar2 != 0) {
      _printk(&DAT_0010185b,"spf_core_platform_driver_probe",iVar2);
    }
    digital_cdc_rsc_mgr_init();
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// spf_core_platform_driver_remove @ 001009a8 size=52
// signature: undefined spf_core_platform_driver_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 spf_core_platform_driver_remove(void)

{
  gpr_driver_unregister(&qcom_spf_core_driver);
  spf_core_priv = 0;
  digital_cdc_rsc_mgr_exit();
  return 0;
}



//------------------------------------------------------------
// spf_core_add_child_devices @ 001009e0 size=196
// signature: undefined spf_core_add_child_devices(void)
// callers: []
//------------------------------------------------------------

void spf_core_add_child_devices(void)

{
  int iVar1;
  ulong uVar2;
  
  _printk(&DAT_00101714,"spf_core_add_child_devices");
  uVar2 = spf_core_is_apm_ready(10000);
  if ((uVar2 & 1) == 0) {
    _dev_err(*spf_core_priv,"%s: apm is not up\n","spf_core_add_child_devices");
  }
  else {
    _dev_err(*spf_core_priv,"%s: apm is up\n","spf_core_add_child_devices");
    iVar1 = of_platform_populate(*(undefined8 *)(*spf_core_priv + 0x2e8),0,0);
    if (iVar1 != 0) {
      _dev_err(*spf_core_priv,"%s: failed to add child nodes, ret=%d\n","spf_core_add_child_devices"
               ,iVar1);
    }
    *(undefined1 *)(spf_core_priv + 8) = 0;
  }
  return;
}



//------------------------------------------------------------
// spf_core_probe @ 00100aa8 size=268
// signature: undefined spf_core_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 spf_core_probe(long param_1)

{
  char *pcVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  
  _printk(&DAT_001018e8,"spf_core_probe");
  if (spf_core_priv == 0) {
    _printk(&DAT_00101640,"spf_core_probe");
    uVar3 = 0xfffffdfb;
  }
  else {
    mutex_lock(spf_core_priv + 8);
    plVar2 = (long *)kmalloc_trace(_clk_prepare,0xdc0,0x58);
    if (plVar2 == (long *)0x0) {
      mutex_unlock(spf_core_priv + 8);
      uVar3 = 0xfffffff4;
    }
    else {
      *(long **)(param_1 + 0x98) = plVar2;
      __mutex_init(plVar2 + 4,"&core->lock",&spf_core_probe___key);
      *plVar2 = param_1;
      __init_waitqueue_head(plVar2 + 1,"&core->wait",&spf_core_probe___key_22);
      lVar4 = spf_core_priv;
      pcVar1 = (char *)(spf_core_priv + 0x40);
      *(long **)(spf_core_priv + 0x38) = plVar2;
      if (*pcVar1 != '\0') {
        queue_work_on(0x20,_system_wq,lVar4 + 0x48);
        lVar4 = spf_core_priv;
      }
      mutex_unlock(lVar4 + 8);
      uVar3 = 0;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// spf_core_exit @ 00100bb8 size=116
// signature: undefined spf_core_exit(void)
// callers: []
//------------------------------------------------------------

undefined8 spf_core_exit(long param_1)

{
  undefined8 uVar1;
  
  if (spf_core_priv == 0) {
    _printk(&DAT_00101640,"spf_core_exit");
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined8 *)(param_1 + 0x98);
    mutex_lock(spf_core_priv + 8);
    *(undefined8 *)(spf_core_priv + 0x38) = 0;
    kfree(uVar1);
    mutex_unlock(spf_core_priv + 8);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// spf_core_callback @ 00100c30 size=472
// signature: undefined spf_core_callback(void)
// callers: []
//------------------------------------------------------------

undefined8 spf_core_callback(long param_1,uint *param_2)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x98);
  iVar4 = ___ratelimit(spf_core_callback__rs,"spf_core_callback");
  if (iVar4 != 0) {
    _dev_info(param_1,"%s: Payload %x","spf_core_callback",param_2[5]);
  }
  if (param_2[5] == 0x2001007) {
    uVar2 = *param_2;
    iVar4 = ___ratelimit(spf_core_callback__rs_29,"spf_core_callback");
    if (iVar4 != 0) {
      _dev_info(param_1,"%s: sucess response received","spf_core_callback");
    }
    uVar3 = *(undefined4 *)((long)param_2 + ((ulong)(uVar2 >> 2) & 0x3c));
    *(undefined1 *)(lVar5 + 0x50) = 1;
    *(undefined4 *)(lVar5 + 0x54) = uVar3;
  }
  else if (param_2[5] == 0x2001005) {
    piVar1 = (int *)((long)param_2 + ((ulong)(*param_2 >> 2) & 0x3c));
    iVar4 = ___ratelimit(spf_core_callback__rs_25,"spf_core_callback");
    if (iVar4 != 0) {
      _dev_info(param_1,"%s: op %x status %d","spf_core_callback",*piVar1,piVar1[1]);
    }
    if (*piVar1 == 0x1001013) {
      *(int *)(lVar5 + 0x54) = piVar1[1];
    }
    else {
      iVar4 = ___ratelimit(spf_core_callback__rs_27,"spf_core_callback");
      if (iVar4 != 0) {
        _dev_err(param_1,"%s: Failed response received","spf_core_callback");
      }
    }
    *(undefined1 *)(lVar5 + 0x50) = 1;
  }
  else {
    iVar4 = ___ratelimit(spf_core_callback__rs_31,"spf_core_callback");
    if (iVar4 != 0) {
      _dev_err(param_1,"Message ID from apm: 0x%x\n",param_2[5]);
    }
  }
  if (*(char *)(lVar5 + 0x50) != '\0') {
    __wake_up(lVar5 + 8,3,1,0);
  }
  return 0;
}



//------------------------------------------------------------
// digital_cdc_rsc_mgr_hw_vote_enable @ 00100e0c size=176
// signature: undefined digital_cdc_rsc_mgr_hw_vote_enable(void)
// callers: []
//------------------------------------------------------------

int digital_cdc_rsc_mgr_hw_vote_enable(long param_1)

{
  int iVar1;
  
  if ((param_1 == 0) || ((is_init_done & 1) == 0)) {
    iVar1 = ___ratelimit(&digital_cdc_rsc_mgr_hw_vote_enable__rs,
                         "digital_cdc_rsc_mgr_hw_vote_enable");
    if (iVar1 != 0) {
      _printk(&DAT_001018b3,"digital_cdc_rsc_mgr_hw_vote_enable");
    }
    iVar1 = -0x16;
  }
  else {
    mutex_lock(hw_vote_lock);
    iVar1 = clk_prepare(param_1);
    if (iVar1 == 0) {
      iVar1 = clk_enable(param_1);
      if (iVar1 != 0) {
        clk_unprepare(param_1);
      }
    }
    mutex_unlock(hw_vote_lock);
  }
  return iVar1;
}



//------------------------------------------------------------
// digital_cdc_rsc_mgr_hw_vote_disable @ 00100ec0 size=144
// signature: undefined digital_cdc_rsc_mgr_hw_vote_disable(void)
// callers: []
//------------------------------------------------------------

void digital_cdc_rsc_mgr_hw_vote_disable(long param_1)

{
  int iVar1;
  
  if ((param_1 == 0) || ((is_init_done & 1) == 0)) {
    iVar1 = ___ratelimit(digital_cdc_rsc_mgr_hw_vote_disable__rs,
                         "digital_cdc_rsc_mgr_hw_vote_disable");
    if (iVar1 != 0) {
      _printk(&DAT_001018b3,"digital_cdc_rsc_mgr_hw_vote_disable");
    }
  }
  else {
    mutex_lock(hw_vote_lock);
    clk_disable(param_1);
    clk_unprepare(param_1);
    mutex_unlock(hw_vote_lock);
  }
  return;
}



//------------------------------------------------------------
// digital_cdc_rsc_mgr_hw_vote_reset @ 00100f54 size=224
// signature: undefined digital_cdc_rsc_mgr_hw_vote_reset(void)
// callers: []
//------------------------------------------------------------

void digital_cdc_rsc_mgr_hw_vote_reset(long param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  
  if ((param_1 == 0) || ((is_init_done & 1) == 0)) {
    iVar3 = ___ratelimit(digital_cdc_rsc_mgr_hw_vote_reset__rs,"digital_cdc_rsc_mgr_hw_vote_reset");
    if (iVar3 != 0) {
      _printk(&DAT_001018b3,"digital_cdc_rsc_mgr_hw_vote_reset");
    }
  }
  else {
    mutex_lock(hw_vote_lock);
    uVar4 = __clk_is_enabled(param_1);
    if ((uVar4 & 1) != 0) {
      iVar3 = 0;
      do {
        clk_disable(param_1);
        clk_unprepare(param_1);
        uVar4 = __clk_is_enabled(param_1);
        iVar3 = iVar3 + -1;
      } while ((uVar4 & 1) != 0);
      if (iVar3 != 0) {
        do {
          iVar2 = clk_prepare(param_1);
          if ((iVar2 == 0) && (iVar2 = clk_enable(param_1), iVar2 != 0)) {
            clk_unprepare(param_1);
          }
          bVar1 = iVar3 != -1;
          iVar3 = iVar3 + 1;
        } while (bVar1);
      }
    }
    mutex_unlock(hw_vote_lock);
  }
  return;
}



//------------------------------------------------------------
// digital_cdc_rsc_mgr_init @ 00101038 size=64
// signature: undefined digital_cdc_rsc_mgr_init(void)
// callers: [spf_core_platform_driver_probe]
//------------------------------------------------------------

void digital_cdc_rsc_mgr_init(void)

{
  __mutex_init(hw_vote_lock,"&hw_vote_lock",&digital_cdc_rsc_mgr_init___key);
  is_init_done = 1;
  return;
}



//------------------------------------------------------------
// digital_cdc_rsc_mgr_exit @ 0010107c size=12
// signature: undefined digital_cdc_rsc_mgr_exit(void)
// callers: [spf_core_platform_driver_remove]
//------------------------------------------------------------

void digital_cdc_rsc_mgr_exit(void)

{
  is_init_done = 0;
  return;
}



//------------------------------------------------------------
// init_module @ 00101124 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&spf_core_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101154 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&spf_core_driver);
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00103000 size=1
// signature: undefined mutex_lock(void)
// callers: [spf_core_apm_close_all, spf_core_probe, spf_core_exit, spf_core_is_apm_ready, digital_cdc_rsc_mgr_hw_vote_disable, digital_cdc_rsc_mgr_hw_vote_reset, digital_cdc_rsc_mgr_hw_vote_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00103010 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [spf_core_is_apm_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00103018 size=1
// signature: undefined ___ratelimit(void)
// callers: [spf_core_callback, spf_core_apm_close_all, spf_core_is_apm_ready, digital_cdc_rsc_mgr_hw_vote_disable, digital_cdc_rsc_mgr_hw_vote_reset, digital_cdc_rsc_mgr_hw_vote_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpr_send_pkt @ 00103020 size=1
// signature: undefined gpr_send_pkt(void)
// callers: [spf_core_apm_close_all, spf_core_is_apm_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpr_send_pkt(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00103028 size=1
// signature: undefined init_wait_entry(void)
// callers: [spf_core_apm_close_all, spf_core_is_apm_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00103030 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [spf_core_apm_close_all, spf_core_is_apm_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 00103038 size=1
// signature: undefined finish_wait(void)
// callers: [spf_core_apm_close_all, spf_core_is_apm_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 00103040 size=1
// signature: undefined schedule_timeout(void)
// callers: [spf_core_apm_close_all, spf_core_is_apm_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00103048 size=1
// signature: undefined usleep_range_state(void)
// callers: [spf_core_is_apm_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103050 size=1
// signature: undefined _dev_err(void)
// callers: [spf_core_callback, spf_core_apm_close_all, spf_core_is_apm_ready, spf_core_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103058 size=1
// signature: undefined mutex_unlock(void)
// callers: [spf_core_apm_close_all, spf_core_probe, spf_core_exit, spf_core_is_apm_ready, digital_cdc_rsc_mgr_hw_vote_disable, digital_cdc_rsc_mgr_hw_vote_reset, digital_cdc_rsc_mgr_hw_vote_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103060 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [spf_core_apm_close_all, spf_core_is_apm_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00103068 size=1
// signature: undefined _dev_info(void)
// callers: [spf_core_callback, spf_core_apm_close_all]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00103070 size=1
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
// platform_driver_unregister @ 00103078 size=1
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
// _printk @ 00103080 size=1
// signature: undefined _printk(void)
// callers: [spf_core_probe, spf_core_exit, spf_core_platform_driver_probe, digital_cdc_rsc_mgr_hw_vote_disable, digital_cdc_rsc_mgr_hw_vote_reset, spf_core_add_child_devices, digital_cdc_rsc_mgr_hw_vote_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103088 size=1
// signature: undefined devm_kmalloc(void)
// callers: [spf_core_platform_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00103090 size=1
// signature: undefined __mutex_init(void)
// callers: [spf_core_probe, spf_core_platform_driver_probe, digital_cdc_rsc_mgr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __gpr_driver_register @ 00103098 size=1
// signature: undefined __gpr_driver_register(void)
// callers: [spf_core_platform_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __gpr_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpr_driver_unregister @ 001030a0 size=1
// signature: undefined gpr_driver_unregister(void)
// callers: [spf_core_platform_driver_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpr_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_populate @ 001030a8 size=1
// signature: undefined of_platform_populate(void)
// callers: [spf_core_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001030b8 size=1
// signature: undefined kmalloc_trace(void)
// callers: [spf_core_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 001030c0 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [spf_core_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001030d0 size=1
// signature: undefined queue_work_on(void)
// callers: [spf_core_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001030d8 size=1
// signature: undefined kfree(void)
// callers: [spf_core_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 001030e0 size=1
// signature: undefined __wake_up(void)
// callers: [spf_core_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 001030e8 size=1
// signature: undefined clk_prepare(void)
// callers: [digital_cdc_rsc_mgr_hw_vote_reset, digital_cdc_rsc_mgr_hw_vote_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 001030f0 size=1
// signature: undefined clk_enable(void)
// callers: [digital_cdc_rsc_mgr_hw_vote_reset, digital_cdc_rsc_mgr_hw_vote_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001030f8 size=1
// signature: undefined clk_unprepare(void)
// callers: [digital_cdc_rsc_mgr_hw_vote_disable, digital_cdc_rsc_mgr_hw_vote_reset, digital_cdc_rsc_mgr_hw_vote_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 00103100 size=1
// signature: undefined clk_disable(void)
// callers: [digital_cdc_rsc_mgr_hw_vote_disable, digital_cdc_rsc_mgr_hw_vote_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __clk_is_enabled @ 00103108 size=1
// signature: undefined __clk_is_enabled(void)
// callers: [digital_cdc_rsc_mgr_hw_vote_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __clk_is_enabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



