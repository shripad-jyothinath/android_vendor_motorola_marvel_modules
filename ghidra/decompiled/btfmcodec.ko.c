// Decompiled by Ghidra 12.2
// Program: btfmcodec.ko
// Image base: 00100000

//------------------------------------------------------------
// coverttostring @ 00100d84 size=36
// signature: undefined coverttostring(void)
// callers: [btfmcodec_dai_set_channel_map, btfmcodec_codec_read, btfmcodec_codec_probe, btfmcodec_prepare_bearer, btfmcodec_codec_write, btfmcodec_dai_shutdown, btfmcodec_dai_hw_params, btfmcodec_revert_current_state, btfmcodec_configure_hwep, btfmcodec_codec_remove, btfmcodec_move_to_next_state, btfmcodec_dai_prepare, btfmcodec_hwep_shutdown, btfmcodec_set_current_state]
//------------------------------------------------------------

char * coverttostring(uint param_1)

{
  if (param_1 < 5) {
    return (&PTR_DAT_00107560)[(int)param_1];
  }
  return "INVALID_STATE";
}



//------------------------------------------------------------
// STREAM_TO_UINT32 @ 00100dac size=12
// signature: undefined STREAM_TO_UINT32(void)
// callers: []
//------------------------------------------------------------

undefined4 STREAM_TO_UINT32(long param_1)

{
  return **(undefined4 **)(param_1 + 0xe0);
}



//------------------------------------------------------------
// btfmcodec_dev_enqueue_pkt @ 00100dbc size=348
// signature: undefined btfmcodec_dev_enqueue_pkt(void)
// callers: [btfmcodec_configure_hwep, btfmcodec_frame_transport_switch_ind_pkt, btfmcodec_frame_prepare_bearer_rsp_pkt, btfmcodec_prepare_bearer, btfmcodec_adsp_ssr_notify, btfmcodec_configure_master, btfmcodec_configure_dma, btfmcodec_dai_prepare, btfmcodec_hwep_shutdown]
//------------------------------------------------------------

undefined8 btfmcodec_dev_enqueue_pkt(long param_1,void *param_2,ulong param_3)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  void *__dest;
  
  param_3 = param_3 & 0xffffffff;
  if (3 < log_lvl) {
    _printk(&DAT_001069a6,"btfmcodec_dev_enqueue_pkt");
  }
  lVar1 = param_1 + 0x200;
  uVar2 = _raw_spin_lock_irqsave(lVar1);
  if (*(int *)(param_1 + 0x88) == 1) {
    _printk(&DAT_00106400,"btfmcodec_dev_enqueue_pkt");
    _raw_spin_unlock_irqrestore(lVar1,uVar2);
    uVar2 = 0xffffffea;
  }
  else {
    lVar3 = __alloc_skb(param_3,0xa20,0,0xffffffff);
    if (lVar3 == 0) {
      _printk(&DAT_001064a0,"btfmcodec_dev_enqueue_pkt");
      _raw_spin_unlock_irqrestore(lVar1,uVar2);
      uVar2 = 0xfffffff4;
    }
    else {
      __dest = (void *)skb_put(lVar3,param_3);
      memcpy(__dest,param_2,param_3);
      skb_queue_tail(param_1 + 0x208,lVar3);
      __wake_up(param_1 + 0x1e8,1,1,0);
      _raw_spin_unlock_irqrestore(lVar1,uVar2);
      if (3 < log_lvl) {
        _printk(&DAT_0010675b,"btfmcodec_dev_enqueue_pkt");
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// isCpSupported @ 00100f1c size=12
// signature: undefined isCpSupported(void)
// callers: [btfm_register_codec]
//------------------------------------------------------------

undefined1 isCpSupported(void)

{
  return is_cp_supported;
}



//------------------------------------------------------------
// btfm_get_btfmcodec @ 00100f2c size=12
// signature: undefined btfm_get_btfmcodec(void)
// callers: [btfm_register_codec, btfm_unregister_codec, btfmcodec_register_hw_ep, btfmcodec_unregister_hw_ep]
//------------------------------------------------------------

undefined8 btfm_get_btfmcodec(void)

{
  return btfmcodec;
}



//------------------------------------------------------------
// btfmcodec_dev_rxwork @ 00100f3c size=1332
// signature: undefined btfmcodec_dev_rxwork(void)
// callers: []
//------------------------------------------------------------

void btfmcodec_dev_rxwork(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined *puVar4;
  undefined1 uVar5;
  char cVar6;
  long lVar7;
  
  if (3 < log_lvl) {
    _printk(&DAT_001069a6,"btfmcodec_dev_rxwork");
  }
  lVar3 = skb_dequeue(param_1 + -0x18);
  if (lVar3 != 0) {
    cVar6 = '\0';
    lVar7 = 0;
    do {
      iVar1 = **(int **)(lVar3 + 0xe0);
      skb_pull(lVar3,4);
      iVar2 = **(int **)(lVar3 + 0xe0);
      skb_pull(lVar3,4);
      if (iVar1 == 0x50000000) {
        if (log_lvl < 4) {
          if (iVar2 != 1) goto LAB_001011a4;
LAB_0010102c:
          if (*(char *)(param_1 + 0x1a3) == '\0') {
            if (3 < log_lvl) {
              _printk(&DAT_00105afc,"btfmcodec_dev_rxwork");
            }
            *(undefined1 *)(param_1 + 0x1a3) = 2;
            __wake_up(param_1 + 0x140,1,1,0);
          }
          uVar5 = **(undefined1 **)(lVar3 + 0xe0);
          *(undefined1 *)(param_1 + 0x1a3) = 0;
          *(undefined1 *)(param_1 + 0x1a0) = uVar5;
          queue_work_on(0x20,*(undefined8 *)(param_1 + -0x20),param_1 + 0x60);
        }
        else {
          _printk(&DAT_00106cf1,"btfmcodec_dev_rxwork");
          if (iVar2 == 1) goto LAB_0010102c;
LAB_001011a4:
          _printk(&DAT_0010662d,"btfmcodec_dev_rxwork",iVar2);
        }
        lVar7 = 0;
      }
      else if (iVar1 < 0x58000001) {
        if (iVar1 == 0x50000003) {
          if (iVar2 == 2) {
            cVar6 = *(char *)(*(long *)(lVar3 + 0xe0) + 1);
            uVar5 = 1;
            if (cVar6 != '\0') {
              uVar5 = 2;
            }
          }
          else {
            _printk(&DAT_0010662d,"btfmcodec_dev_rxwork",iVar2);
            uVar5 = 2;
          }
          *(undefined1 *)(param_1 + 0x1a1) = uVar5;
          puVar4 = &DAT_00105bd3;
          if (log_lvl < 8) {
            puVar4 = &DAT_001059fb;
          }
          _printk(puVar4,"btfmcodec_dev_rxwork",cVar6);
          __wake_up(param_1 + 0x110,1,1,0);
          lVar7 = 1;
        }
        else if (iVar1 == 0x50000005) {
          if (iVar2 == 2) {
            cVar6 = *(char *)(*(long *)(lVar3 + 0xe0) + 1);
            uVar5 = 1;
            if (cVar6 != '\0') {
              uVar5 = 2;
            }
          }
          else {
            _printk(&DAT_0010662d,"btfmcodec_dev_rxwork",iVar2);
            uVar5 = 2;
          }
          *(undefined1 *)(param_1 + 0x1a2) = uVar5;
          puVar4 = &DAT_00105e84;
          if (log_lvl < 8) {
            puVar4 = &DAT_00106fe2;
          }
          _printk(puVar4,"btfmcodec_dev_rxwork",cVar6);
          __wake_up(param_1 + 0x128,1,1,0);
          puVar4 = &DAT_0010701d;
          if (log_lvl < 8) {
            puVar4 = &DAT_00105a66;
          }
          _printk(puVar4,"btfmcodec_dev_rxwork","btfmcodec_dev_rxwork");
          cancel_work_sync(param_1 + 0x60);
          if (log_lvl < 8) {
            puVar4 = &DAT_00105a95;
          }
          else {
            puVar4 = &DAT_0010704c;
          }
          _printk(puVar4,"btfmcodec_dev_rxwork","btfmcodec_dev_rxwork");
          lVar7 = 2;
        }
        else {
LAB_00100fbc:
          _printk(&DAT_00106654,"btfmcodec_dev_rxwork",iVar1);
        }
      }
      else if (iVar1 == 0x58000001) {
        if (iVar2 == 1) {
          cVar6 = **(char **)(lVar3 + 0xe0);
          uVar5 = 1;
          if (cVar6 != '\0') {
            uVar5 = 2;
          }
        }
        else {
          _printk(&DAT_0010662d,"btfmcodec_dev_rxwork",iVar2);
          uVar5 = 2;
        }
        *(undefined1 *)(param_1 + 0x1a3) = uVar5;
        puVar4 = &DAT_00105572;
        if (log_lvl < 8) {
          puVar4 = &DAT_00106543;
        }
        _printk(puVar4,"btfmcodec_dev_rxwork",cVar6);
        __wake_up(param_1 + 0x140,1,1,0);
        lVar7 = 3;
      }
      else if (iVar1 == 0x58000004) {
        if (iVar2 == 1) {
          log_lvl = **(byte **)(lVar3 + 0xe0);
        }
        else {
          _printk(&DAT_0010662d,"btfmcodec_dev_rxwork",iVar2);
        }
        puVar4 = &DAT_0010639d;
        if (log_lvl < 8) {
          puVar4 = &DAT_00106bf5;
        }
        _printk(puVar4,"btfmcodec_dev_rxwork");
        __wake_up(param_1 + 0xf8 + lVar7 * 0x18,1,1,0);
      }
      else {
        if (iVar1 != 0x58000007) goto LAB_00100fbc;
        if (iVar2 == 2) {
          cVar6 = *(char *)(*(long *)(lVar3 + 0xe0) + 1);
          uVar5 = 1;
          if (cVar6 != '\0') {
            uVar5 = 2;
          }
        }
        else {
          _printk(&DAT_0010662d,"btfmcodec_dev_rxwork",iVar2);
          uVar5 = 2;
        }
        *(undefined1 *)(param_1 + 0x1a6) = uVar5;
        puVar4 = &DAT_00106109;
        if (log_lvl < 8) {
          puVar4 = &DAT_00105a2f;
        }
        _printk(puVar4,"btfmcodec_dev_rxwork",cVar6);
        __wake_up(param_1 + 0x188,1,1,0);
        lVar7 = 6;
      }
      kfree_skb_reason(lVar3,1);
      lVar3 = skb_dequeue(param_1 + -0x18);
    } while (lVar3 != 0);
  }
  if (3 < log_lvl) {
    _printk(&DAT_0010675b,"btfmcodec_dev_rxwork");
  }
  return;
}



//------------------------------------------------------------
// btfmcodec_dev_read @ 00101474 size=880
// signature: undefined btfmcodec_dev_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btfmcodec_dev_read(long param_1,ulong param_2,ulong param_3)

{
  long *plVar1;
  long lVar2;
  ulong uVar3;
  code *pcVar4;
  undefined8 uVar5;
  long lVar6;
  undefined *puVar7;
  int iVar8;
  undefined8 *puVar9;
  long *plVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  lVar14 = *(long *)(param_1 + 0xd8);
  if (3 < log_lvl) {
    _printk(&DAT_001069a6,"btfmcodec_dev_read");
  }
  if (((lVar14 == 0) || (lVar13 = *(long *)(lVar14 + 0x3d0), lVar13 == 0)) ||
     (*(int *)(lVar13 + 0x88) == 1)) {
    lVar14 = sp_el0;
    if (log_lvl < 8) {
      puVar7 = &DAT_0010687a;
    }
    else {
      puVar7 = &DAT_0010686b;
    }
    _printk(puVar7,"btfmcodec_dev_read",lVar14 + 0x848,*(undefined4 *)(lVar14 + 0x630));
    lVar14 = -0x16;
    goto LAB_00101750;
  }
  lVar12 = lVar13 + 0x200;
  uVar5 = _raw_spin_lock_irqsave(lVar12);
  plVar1 = (long *)(lVar13 + 0x208);
  if (*(long **)(lVar13 + 0x208) == plVar1) {
    _raw_spin_unlock_irqrestore(lVar12,uVar5);
    if ((*(byte *)(param_1 + 0x41) >> 3 & 1) != 0) {
      lVar14 = -0xb;
      goto LAB_00101750;
    }
    if ((long *)*plVar1 == plVar1) {
      local_78 = 0;
      uStack_70 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_90 = 0;
      init_wait_entry(&local_90,0);
      lVar2 = lVar13 + 0x1e8;
      lVar6 = prepare_to_wait_event(lVar2,&local_90,1);
      plVar10 = *(long **)(lVar13 + 0x208);
      while (plVar10 == plVar1) {
        if (lVar6 != 0) {
          if ((int)lVar6 == 0) goto LAB_001016c4;
          lVar14 = -0x200;
          goto LAB_00101750;
        }
        schedule();
        lVar6 = prepare_to_wait_event(lVar2,&local_90,1);
        plVar10 = (long *)*plVar1;
      }
      finish_wait(lVar2,&local_90);
    }
LAB_001016c4:
    if (*(int *)(*(long *)(lVar14 + 0x3d0) + 0x88) == 1) {
      lVar14 = -0x66;
      goto LAB_00101750;
    }
    uVar5 = _raw_spin_lock_irqsave(lVar12);
  }
  lVar14 = skb_dequeue(plVar1);
  _raw_spin_unlock_irqrestore(lVar12,uVar5);
  if (lVar14 == 0) {
    lVar14 = -0xe;
  }
  else {
    uVar11 = (ulong)*(uint *)(lVar14 + 0x70);
    if (param_3 <= *(uint *)(lVar14 + 0x70)) {
      uVar11 = param_3;
    }
    if (uVar11 >> 0x1f != 0) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x800,0x1017c8);
      (*pcVar4)();
    }
    uVar5 = *(undefined8 *)(lVar14 + 0xe0);
    iVar8 = (int)uVar11;
    lVar12 = (long)iVar8;
    __check_object_size(uVar5,lVar12,1);
    puVar9 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar9 + 0x46) >> 5 & 1) != 0) ||
       (uVar11 = param_2, ((uint)*puVar9 >> 0x1a & 1) != 0)) {
      uVar11 = param_2 & (long)(param_2 << 8) >> 8;
    }
    if (uVar11 <= 0x8000000000U - lVar12) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar11 = daif;
        if ((uVar11 & 0x80) == 0) {
          uVar3 = daif;
          daif = uVar3 | 0xc0;
        }
        puVar9 = (undefined8 *)puVar9[1];
        uVar3 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar9 & 0xffff000000000000 | uVar3 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar9;
        InstructionSynchronizationBarrier();
        daif = uVar11;
      }
      lVar12 = __arch_copy_to_user(puVar9,param_2 & 0xff7fffffffffffff,uVar5,lVar12);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar11 = daif;
        if ((uVar11 & 0x80) == 0) {
          uVar3 = daif;
          daif = uVar3 | 0xc0;
        }
        uVar3 = ttbr1_el1;
        ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar3 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar11;
      }
    }
    if (lVar12 != 0) {
      iVar8 = -0xe;
    }
    kfree_skb_reason(0xfffffff2,lVar14,1);
    if (3 < log_lvl) {
      lVar14 = sp_el0;
      _printk(&DAT_0010576d,"btfmcodec_dev_read",lVar13 + 0xc4,lVar14 + 0x848,
              *(undefined4 *)(lVar14 + 0x630),iVar8);
    }
    lVar14 = (long)iVar8;
  }
LAB_00101750:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar14);
  }
  return;
}



//------------------------------------------------------------
// btfmcodec_dev_write @ 00101804 size=508
// signature: undefined btfmcodec_dev_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong btfmcodec_dev_write(long param_1,undefined8 param_2,ulong param_3)

{
  ulong uVar1;
  int iVar2;
  undefined *puVar3;
  void *__dest;
  void *__src;
  long lVar4;
  long lVar5;
  
  lVar4 = *(long *)(param_1 + 0xd8);
  if (((lVar4 == 0) || (lVar5 = *(long *)(lVar4 + 0x3d0), lVar5 == 0)) ||
     (*(int *)(lVar5 + 0x88) == 1)) {
    lVar4 = sp_el0;
    if (log_lvl < 8) {
      puVar3 = &DAT_0010687a;
    }
    else {
      puVar3 = &DAT_0010686b;
    }
    _printk(puVar3,"btfmcodec_dev_write",lVar4 + 0x848,*(undefined4 *)(lVar4 + 0x630));
    return 0xffffffffffffffea;
  }
  iVar2 = mutex_lock_interruptible(lVar5 + 0x90);
  if (iVar2 != 0) {
    __src = (void *)0xfffffe00;
    goto LAB_0010191c;
  }
  if (param_3 < 9) {
    _printk(&DAT_00105b85,"btfmcodec_dev_write");
  }
  else {
    if (*(int *)(*(long *)(lVar4 + 0x3d0) + 0x88) == 0) {
      _printk(&DAT_00105e69,"btfmcodec_dev_write");
      __src = (void *)0xffffff9a;
      goto LAB_0010191c;
    }
    if (3 < log_lvl) {
      _printk(&DAT_00106e14,"btfmcodec_dev_write",lVar5 + 0xc4,param_3);
    }
    __src = (void *)memdup_user(param_2,param_3);
    if ((void *)0xfffffffffffff000 < __src) goto LAB_0010191c;
    lVar4 = __alloc_skb((int)param_3 << 3,0xcc0,0,0xffffffff);
    if (lVar4 == 0) {
      _printk(&DAT_001058cb,"btfmcodec_dev_write");
      __src = (void *)0xfffffff4;
      goto LAB_0010191c;
    }
    __dest = (void *)skb_put(lVar4,param_3 & 0xffffffff);
    memcpy(__dest,__src,param_3 & 0xffffffff);
    skb_queue_tail(lVar5 + 0x110,lVar4);
    queue_work_on(0x20,_system_wq,lVar5 + 0x128);
    kfree(__src);
  }
  __src = (void *)0x0;
LAB_0010191c:
  mutex_unlock(lVar5 + 0x90);
  if (3 < log_lvl) {
    _printk(&DAT_00105900,"btfmcodec_dev_write",lVar5 + 0xc4,(ulong)__src & 0xffffffff);
  }
  uVar1 = (long)(int)__src;
  if (-1 < (int)__src) {
    uVar1 = param_3;
  }
  return uVar1;
}



//------------------------------------------------------------
// btfmcodec_dev_poll @ 00101a04 size=404
// signature: undefined btfmcodec_dev_poll(void)
// callers: []
//------------------------------------------------------------

undefined4 btfmcodec_dev_poll(long param_1,undefined8 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined *puVar3;
  undefined4 uVar4;
  code *pcVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0xd8);
  if (3 < log_lvl) {
    _printk(&DAT_001069a6,"btfmcodec_dev_poll");
  }
  if (((lVar6 == 0) || (lVar6 = *(long *)(lVar6 + 0x3d0), lVar6 == 0)) ||
     (*(int *)(lVar6 + 0x88) == 1)) {
    lVar6 = sp_el0;
    if (log_lvl < 8) {
      puVar3 = &DAT_0010687a;
    }
    else {
      puVar3 = &DAT_0010686b;
    }
    _printk(puVar3,"btfmcodec_dev_poll",lVar6 + 0x848,*(undefined4 *)(lVar6 + 0x630));
    uVar4 = 0xffffffea;
  }
  else {
    if (((param_2 != (undefined8 *)0x0) && (lVar6 + 0x1e8 != 0)) &&
       (pcVar5 = (code *)*param_2, pcVar5 != (code *)0x0)) {
      if (*(int *)(pcVar5 + -4) != 0x7db4acb9) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101a84);
        (*pcVar5)();
      }
      (*pcVar5)(param_1,lVar6 + 0x1e8,param_2);
      DataMemoryBarrier(2,3);
    }
    lVar1 = lVar6 + 0x90;
    mutex_lock(lVar1);
    if (*(int *)(lVar6 + 0x88) == 1) {
      _printk(&DAT_00106bd1,"btfmcodec_dev_poll");
      mutex_unlock(lVar1);
      uVar4 = 0x10;
    }
    else {
      uVar2 = _raw_spin_lock_irqsave(lVar6 + 0x200);
      uVar4 = 0;
      if (*(long *)(lVar6 + 0x208) != lVar6 + 0x208) {
        uVar4 = 0x41;
      }
      _raw_spin_unlock_irqrestore(lVar6 + 0x200,uVar2);
      mutex_unlock(lVar1);
      if (3 < log_lvl) {
        _printk(&DAT_00105504,"btfmcodec_dev_poll",uVar4);
      }
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// btfmcodec_ioctl @ 00101b9c size=620
// signature: undefined btfmcodec_ioctl(void)
// callers: []
//------------------------------------------------------------

undefined8 btfmcodec_ioctl(long param_1,int param_2,int param_3)

{
  long lVar1;
  char *__s1;
  ulong *puVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  undefined *puVar6;
  long lVar7;
  
  lVar7 = *(long *)(param_1 + 0xd8);
  puVar6 = &DAT_0010606b;
  if (log_lvl < 8) {
    puVar6 = &DAT_001059c2;
  }
  _printk(puVar6,"btfmcodec_ioctl","btfmcodec_ioctl",param_2);
  lVar1 = lVar7 + 0x410;
  mutex_lock(lVar1);
  lVar7 = *(long *)(lVar7 + 0x3d8);
  if (lVar7 == 0) {
    _printk(&DAT_00106a0c,"btfmcodec_ioctl","btfmcodec_ioctl");
    _printk(&DAT_00106f48,"btfmcodec_ioctl","btfmcodec_ioctl");
    is_cp_supported = param_3 == 1;
    mutex_unlock(lVar1);
  }
  else {
    mutex_unlock(lVar1);
    if (param_2 == 0xbfaf) {
      if (param_3 == 1) {
        __s1 = (char *)(lVar7 + 8);
        iVar5 = strcmp(__s1,"btfmslim");
        if (iVar5 == 0) {
          puVar2 = (ulong *)(lVar7 + 0x68);
          Hint_Prefetch(puVar2,2,0,1);
          do {
            cVar3 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
            if (bVar4) {
              *puVar2 = *puVar2 | 1;
              cVar3 = ExclusiveMonitorsStatus();
            }
          } while (cVar3 != '\0');
        }
        else {
          iVar5 = strcmp(__s1,"btfmswr_slave");
          if (iVar5 == 0) {
            puVar2 = (ulong *)(lVar7 + 0x68);
            Hint_Prefetch(puVar2,2,0,1);
            do {
              cVar3 = '\x01';
              bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
              if (bVar4) {
                *puVar2 = *puVar2 | 2;
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
          }
        }
        if (log_lvl < 8) {
          puVar6 = &DAT_0010643c;
        }
        else {
          puVar6 = &DAT_00106889;
        }
        _printk(puVar6,"btfmcodec_ioctl","btfmcodec_ioctl",__s1);
      }
      else {
        puVar2 = (ulong *)(lVar7 + 0x68);
        Hint_Prefetch(puVar2,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
          if (bVar4) {
            *puVar2 = *puVar2 & 0xfffffffffffffffe;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        puVar2 = (ulong *)(lVar7 + 0x68);
        Hint_Prefetch(puVar2,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
          if (bVar4) {
            *puVar2 = *puVar2 & 0xfffffffffffffffd;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        if (log_lvl < 8) {
          puVar6 = &DAT_001064ee;
        }
        else {
          puVar6 = &DAT_00105d99;
        }
        _printk(puVar6,"btfmcodec_ioctl","btfmcodec_ioctl");
      }
      if (log_lvl < 8) {
        puVar6 = &DAT_001059da;
      }
      else {
        puVar6 = &DAT_00105dc3;
      }
      _printk(puVar6,"btfmcodec_ioctl","btfmcodec_ioctl",(uint)*(undefined8 *)(lVar7 + 0x68) & 1,
              (uint)*(undefined8 *)(lVar7 + 0x68) >> 1 & 1);
    }
    else {
      _printk(&DAT_00105691,"btfmcodec_ioctl","btfmcodec_ioctl",param_2);
    }
  }
  return 0;
}



//------------------------------------------------------------
// btfmcodec_dev_open @ 00101e40 size=240
// signature: undefined btfmcodec_dev_open(void)
// callers: []
//------------------------------------------------------------

undefined8 btfmcodec_dev_open(long param_1,long param_2)

{
  undefined *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  uint *puVar8;
  long lVar9;
  
  lVar7 = *(long *)(param_1 + 0x290);
  puVar8 = (uint *)(lVar7 + 0x88);
  uVar2 = *puVar8;
  lVar9 = *(long *)(lVar7 + 0x2d0);
  lVar5 = sp_el0;
  puVar1 = &DAT_00106372;
  if (log_lvl < 8) {
    puVar1 = &DAT_00106e38;
  }
  *(undefined8 *)(lVar9 + 0x3c4) = 0;
  _printk(puVar1,"btfmcodec_dev_open",lVar7 + 0xc4,lVar5 + 0x848,*(undefined4 *)(lVar5 + 0x630),
          *puVar8);
  if (1 < uVar2) {
    _printk(&DAT_00106e63,"btfmcodec_dev_open","btfmcodec_dev_open");
    return 0xd;
  }
  *(long *)(param_2 + 0xd8) = lVar9;
  Hint_Prefetch(puVar8,2,0,1);
  do {
    uVar2 = *puVar8;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(puVar8,0x10);
    if (bVar4) {
      *puVar8 = uVar2 + 1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (uVar2 == 0) {
    uVar6 = 2;
  }
  else {
    if (-1 < (int)(uVar2 + 1 | uVar2)) {
      return 0;
    }
    uVar6 = 1;
  }
  refcount_warn_saturate(puVar8,uVar6);
  return 0;
}



//------------------------------------------------------------
// btfmcodec_dev_release @ 00101f40 size=480
// signature: undefined btfmcodec_dev_release(void)
// callers: []
//------------------------------------------------------------

undefined8 btfmcodec_dev_release(long param_1)

{
  undefined *puVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  undefined8 uVar6;
  int *piVar7;
  long lVar8;
  
  lVar8 = *(long *)(param_1 + 0x290);
  lVar5 = sp_el0;
  puVar1 = &DAT_00105531;
  if (log_lvl < 8) {
    puVar1 = &DAT_00106518;
  }
  piVar7 = (int *)(lVar8 + 0x88);
  _printk(puVar1,"btfmcodec_dev_release",lVar8 + 0xc4,lVar5 + 0x848,*(undefined4 *)(lVar5 + 0x630),
          *piVar7);
  Hint_Prefetch(piVar7,2,0,1);
  do {
    iVar2 = *piVar7;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar7,0x10);
    if (bVar4) {
      *piVar7 = iVar2 + -1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (iVar2 < 2) {
    refcount_warn_saturate(piVar7,4);
  }
  if (*piVar7 == 1) {
    uVar6 = _raw_spin_lock_irqsave(lVar8 + 0x200);
    skb_queue_purge(lVar8 + 0x208);
    __wake_up(lVar8 + 0x1e8,1,1,0);
    _raw_spin_unlock_irqrestore(lVar8 + 0x200,uVar6);
    skb_queue_purge(lVar8 + 0x110);
  }
  *(undefined1 *)(lVar8 + 0x2c8) = 3;
  __wake_up(lVar8 + 0x220,1,1,0);
  *(undefined1 *)(lVar8 + 0x2c9) = 3;
  __wake_up(lVar8 + 0x238,1,1,0);
  *(undefined1 *)(lVar8 + 0x2ca) = 3;
  __wake_up(lVar8 + 0x250,1,1,0);
  *(undefined1 *)(lVar8 + 0x2cb) = 3;
  __wake_up(lVar8 + 0x268,1,1,0);
  *(undefined1 *)(lVar8 + 0x2cc) = 3;
  __wake_up(lVar8 + 0x280,1,1,0);
  *(undefined1 *)(lVar8 + 0x2cd) = 3;
  __wake_up(lVar8 + 0x298,1,1,0);
  *(undefined1 *)(lVar8 + 0x2ce) = 3;
  __wake_up(lVar8 + 0x2b0,1,1,0);
  if (*(long *)(lVar8 + 0x170) != 0) {
    cancel_work_sync(lVar8 + 0x158);
  }
  if (*(long *)(lVar8 + 0x1d0) != 0) {
    cancel_work_sync(lVar8 + 0x1b8);
  }
  if (*(long *)(lVar8 + 0x1a0) != 0) {
    cancel_work_sync(lVar8 + 0x188);
  }
  *(undefined8 *)(btfmcodec + 0x3c4) = 0;
  return 0;
}



//------------------------------------------------------------
// btfmcodec_attributes_show @ 00102134 size=8
// signature: undefined btfmcodec_attributes_show(void)
// callers: []
//------------------------------------------------------------

undefined8 btfmcodec_attributes_show(void)

{
  return 0;
}



//------------------------------------------------------------
// btfmcodec_attributes_store @ 00102140 size=152
// signature: undefined btfmcodec_attributes_store(void)
// callers: []
//------------------------------------------------------------

void btfmcodec_attributes_store
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  lVar1 = *(long *)(param_1 + 0x3d0) + 0x90;
  mutex_lock(lVar1);
  iVar2 = kstrtoll(param_3,0,&local_40);
  mutex_unlock(lVar1);
  lVar1 = sp_el0;
  if (iVar2 != 0) {
    param_4 = 0xffffffffffffffea;
  }
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// btfmcodec_initiate_hwep_shutdown @ 00102204 size=396
// signature: undefined btfmcodec_initiate_hwep_shutdown(void)
// callers: [btfmcodec_configure_hwep, btfmcodec_prepare_bearer]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btfmcodec_initiate_hwep_shutdown(long param_1)

{
  long lVar1;
  byte bVar2;
  long lVar3;
  undefined *puVar4;
  long lVar5;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  *(undefined1 *)(param_1 + 0x2cc) = 0;
  _printk(&DAT_00106a3d,"btfmcodec_initiate_hwep_shutdown");
  queue_work_on(0x20,_system_wq,param_1 + 0x158);
  _printk(&DAT_00105791,"btfmcodec_initiate_hwep_shutdown");
  bVar2 = *(byte *)(param_1 + 0x2cc);
  if (bVar2 == 0) {
    local_48 = 0;
    uStack_40 = 0;
    lVar1 = param_1 + 0x280;
    local_58 = 0;
    uStack_50 = 0;
    local_60 = 0;
    init_wait_entry(&local_60,0);
    lVar3 = prepare_to_wait_event(lVar1,&local_60,1);
    if (*(char *)(param_1 + 0x2cc) == '\0') {
      lVar5 = 0x4e2;
      do {
        if (lVar3 != 0) goto LAB_001022c0;
        lVar5 = schedule_timeout(lVar5);
        lVar3 = prepare_to_wait_event(lVar1,&local_60,1);
        if (lVar5 == 0 && *(char *)(param_1 + 0x2cc) != '\0') {
          lVar5 = 1;
        }
      } while ((*(char *)(param_1 + 0x2cc) == '\0') && (lVar5 != 0));
    }
    else {
      lVar5 = 0x4e2;
    }
    lVar3 = lVar5;
    finish_wait(lVar1,&local_60);
LAB_001022c0:
    if ((int)lVar3 == 0) {
      _printk(&DAT_001068da,"btfmcodec_initiate_hwep_shutdown");
      flush_work(param_1 + 0x158);
      goto LAB_001022dc;
    }
    bVar2 = *(byte *)(param_1 + 0x2cc);
  }
  if (bVar2 - 2 < 2) {
    puVar4 = &DAT_00105c07;
  }
  else {
    if (bVar2 != 1) goto LAB_001022dc;
    puVar4 = &DAT_001055a6;
  }
  _printk(puVar4,"btfmcodec_initiate_hwep_shutdown");
LAB_001022dc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// btfmcodec_move_to_next_state @ 00102394 size=148
// signature: undefined btfmcodec_move_to_next_state(void)
// callers: [btfmcodec_configure_hwep, btfmcodec_prepare_bearer]
//------------------------------------------------------------

void btfmcodec_move_to_next_state(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  mutex_lock();
  if ((*(uint *)(param_1 + 0x34) | 2) == 3) {
    *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) + 1;
    uVar1 = coverttostring();
    uVar2 = coverttostring(*(undefined4 *)(param_1 + 0x34));
    _printk(&DAT_001069d5,"btfmcodec_move_to_next_state",uVar1,uVar2);
  }
  else {
    _printk(&DAT_00105edc,"btfmcodec_move_to_next_state");
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  *(undefined4 *)(param_1 + 0x30) = 0;
  mutex_unlock(param_1);
  return;
}



//------------------------------------------------------------
// btfmcodec_revert_current_state @ 0010242c size=104
// signature: undefined btfmcodec_revert_current_state(void)
// callers: [btfmcodec_prepare_bearer]
//------------------------------------------------------------

void btfmcodec_revert_current_state(long param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  mutex_lock();
  uVar2 = coverttostring(*(undefined4 *)(param_1 + 0x34));
  uVar3 = coverttostring(*(undefined4 *)(param_1 + 0x30));
  _printk(&DAT_00106337,"btfmcodec_revert_current_state",uVar2,uVar3);
  uVar1 = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  mutex_unlock(param_1);
  return;
}



//------------------------------------------------------------
// btfmcodec_set_current_state @ 00102498 size=116
// signature: undefined btfmcodec_set_current_state(void)
// callers: [btfmcodec_hwep_prepare, btfmcodec_prepare_bearer, btfmcodec_dai_shutdown]
//------------------------------------------------------------

void btfmcodec_set_current_state(long param_1,undefined4 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  mutex_lock();
  uVar1 = coverttostring(*(undefined4 *)(param_1 + 0x34));
  uVar2 = coverttostring(param_2);
  _printk(&DAT_001069d5,"btfmcodec_set_current_state",uVar1,uVar2);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x34) = param_2;
  mutex_unlock(param_1);
  return;
}



//------------------------------------------------------------
// btfmcodec_get_current_transport @ 00102510 size=56
// signature: undefined btfmcodec_get_current_transport(void)
// callers: [btfmcodec_dai_hw_params, btfmcodec_codec_read, btfmcodec_codec_probe, btfmcodec_codec_remove, btfmcodec_dai_startup, btfmcodec_codec_write, btfmcodec_dai_shutdown, btfmcodec_dai_prepare, btfmcodec_hwep_shutdown]
//------------------------------------------------------------

undefined4 btfmcodec_get_current_transport(long param_1)

{
  undefined4 uVar1;
  
  mutex_lock();
  uVar1 = *(undefined4 *)(param_1 + 0x34);
  mutex_unlock(param_1);
  return uVar1;
}



//------------------------------------------------------------
// btfmcodec_frame_transport_switch_ind_pkt @ 0010254c size=100
// signature: undefined btfmcodec_frame_transport_switch_ind_pkt(void)
// callers: []
//------------------------------------------------------------

void btfmcodec_frame_transport_switch_ind_pkt
               (undefined8 param_1,undefined1 param_2,undefined1 param_3)

{
  long lVar1;
  undefined8 local_28;
  undefined1 local_20;
  undefined1 local_1f;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_28 = 0x258000002;
  local_20 = param_2;
  local_1f = param_3;
  btfmcodec_dev_enqueue_pkt(param_1,&local_28,10);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// btfmcodec_frame_prepare_bearer_rsp_pkt @ 001025b4 size=104
// signature: undefined btfmcodec_frame_prepare_bearer_rsp_pkt(void)
// callers: []
//------------------------------------------------------------

void btfmcodec_frame_prepare_bearer_rsp_pkt
               (undefined8 param_1,undefined1 param_2,undefined1 param_3)

{
  long lVar1;
  undefined8 local_28;
  undefined1 local_20;
  undefined1 local_1f;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_28 = 0x250000001;
  local_20 = param_2;
  local_1f = param_3;
  btfmcodec_dev_enqueue_pkt(param_1,&local_28,10);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// btfmcodec_wait_for_bearer_ind @ 00102620 size=348
// signature: undefined btfmcodec_wait_for_bearer_ind(void)
// callers: [btfmcodec_configure_hwep, btfmcodec_prepare_bearer]
//------------------------------------------------------------

void btfmcodec_wait_for_bearer_ind(long param_1)

{
  long lVar1;
  char cVar2;
  long lVar3;
  undefined *puVar4;
  long lVar5;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  cVar2 = *(char *)(param_1 + 0x2cb);
  if (cVar2 == '\0') {
    lVar1 = param_1 + 0x268;
    local_48 = 0;
    uStack_40 = 0;
    local_58 = 0;
    uStack_50 = 0;
    local_60 = 0;
    init_wait_entry(&local_60,0);
    lVar3 = prepare_to_wait_event(lVar1,&local_60,1);
    if (*(char *)(param_1 + 0x2cb) == '\0') {
      lVar5 = 0x4e2;
      do {
        if (lVar3 != 0) goto LAB_001026c0;
        lVar5 = schedule_timeout(lVar5);
        lVar3 = prepare_to_wait_event(lVar1,&local_60,1);
        if (lVar5 == 0 && *(char *)(param_1 + 0x2cb) != '\0') {
          lVar5 = 1;
        }
      } while ((*(char *)(param_1 + 0x2cb) == '\0') && (lVar5 != 0));
    }
    else {
      lVar5 = 0x4e2;
    }
    lVar3 = lVar5;
    finish_wait(lVar1,&local_60);
LAB_001026c0:
    if ((int)lVar3 == 0) {
      _printk(&DAT_00106711,"btfmcodec_wait_for_bearer_ind");
      lVar3 = 0xfffffffd;
      goto LAB_001026d4;
    }
    cVar2 = *(char *)(param_1 + 0x2cb);
  }
  else {
    lVar3 = 0x4e2;
  }
  if (cVar2 == '\x01') {
    lVar3 = 0;
  }
  else {
    if (cVar2 == '\x03') {
      puVar4 = &DAT_0010690d;
    }
    else {
      if (cVar2 != '\x02') goto LAB_001026d4;
      puVar4 = &DAT_001057b2;
    }
    _printk(puVar4,"btfmcodec_wait_for_bearer_ind");
    lVar3 = 0xffffffff;
  }
LAB_001026d4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// btfmcodec_initiate_hwep_configuration @ 00102780 size=344
// signature: undefined btfmcodec_initiate_hwep_configuration(void)
// callers: [btfmcodec_configure_hwep]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btfmcodec_initiate_hwep_configuration(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  lVar1 = param_1 + 0x298;
  queue_work_on(0x20,_system_wq,param_1 + 0x1b8);
  *(undefined1 *)(param_1 + 0x2cd) = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_60 = 0;
  init_wait_entry(&local_60,0);
  lVar2 = prepare_to_wait_event(lVar1,&local_60,1);
  if (*(char *)(param_1 + 0x2cd) == '\0') {
    lVar3 = 0x4e2;
    do {
      if (lVar2 != 0) goto LAB_0010280c;
      lVar3 = schedule_timeout(lVar3);
      lVar2 = prepare_to_wait_event(lVar1,&local_60,1);
      if (lVar3 == 0 && *(char *)(param_1 + 0x2cd) != '\0') {
        lVar3 = 1;
      }
    } while ((*(char *)(param_1 + 0x2cd) == '\0') && (lVar3 != 0));
  }
  else {
    lVar3 = 0x4e2;
  }
  lVar2 = lVar3;
  finish_wait(lVar1,&local_60);
LAB_0010280c:
  if ((int)lVar2 == 0) {
    _printk(&DAT_00106258,"btfmcodec_initiate_hwep_configuration");
    flush_work(param_1 + 0x1b8);
  }
  else {
    if (*(byte *)(param_1 + 0x2cd) == 1) {
      lVar2 = 0;
      goto LAB_001028a8;
    }
    if (1 < *(byte *)(param_1 + 0x2cd) - 2) goto LAB_001028a8;
    _printk(&DAT_00106b7e,"btfmcodec_initiate_hwep_configuration");
  }
  lVar2 = 0xffffffff;
LAB_001028a8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar2);
  }
  return;
}



//------------------------------------------------------------
// btfmcodec_configure_hwep @ 001028dc size=448
// signature: undefined btfmcodec_configure_hwep(void)
// callers: [btfmcodec_prepare_bearer]
//------------------------------------------------------------

void btfmcodec_configure_hwep(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  long lVar8;
  undefined8 local_58;
  undefined2 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  lVar8 = *(long *)(param_1 + 0x2d0);
  lVar1 = lVar8 + 0x390;
  iVar3 = btfmcodec_initiate_hwep_configuration();
  if (iVar3 < 0) {
    mutex_lock(lVar1);
    uVar5 = coverttostring(*(undefined4 *)(lVar8 + 0x3c4));
    uVar6 = coverttostring(*(undefined4 *)(lVar8 + 0x3c0));
    _printk(&DAT_00106337,"btfmcodec_revert_current_state",uVar5,uVar6);
    uVar2 = *(undefined4 *)(lVar8 + 0x3c0);
    *(undefined4 *)(lVar8 + 0x3c0) = 0;
    *(undefined4 *)(lVar8 + 0x3c4) = uVar2;
    mutex_unlock(lVar1);
    uVar7 = 4;
  }
  else {
    uVar7 = 0;
  }
  mutex_lock(lVar1);
  uVar2 = *(undefined4 *)(lVar8 + 0x3c4);
  mutex_unlock(lVar1);
  local_50 = CONCAT11(uVar7,(char)uVar2);
  local_58 = 0x250000001;
  iVar4 = btfmcodec_dev_enqueue_pkt(param_1,&local_58,10);
  if ((-1 < iVar3) && (iVar4 < 0)) {
    iVar3 = btfmcodec_wait_for_bearer_ind(param_1);
    if (iVar3 < 0) {
      _printk(&DAT_00106140,"btfmcodec_configure_hwep");
      mutex_lock(lVar1);
      uVar5 = coverttostring(*(undefined4 *)(lVar8 + 0x3c4));
      uVar6 = coverttostring(*(undefined4 *)(lVar8 + 0x3c0));
      _printk(&DAT_00106337,"btfmcodec_revert_current_state",uVar5,uVar6);
      uVar2 = *(undefined4 *)(lVar8 + 0x3c0);
      *(undefined4 *)(lVar8 + 0x3c0) = 0;
      *(undefined4 *)(lVar8 + 0x3c4) = uVar2;
      mutex_unlock(lVar1);
      btfmcodec_initiate_hwep_shutdown(param_1);
      if (iVar3 == -3) {
        local_50 = 0x301;
        local_58 = 0x258000002;
        btfmcodec_dev_enqueue_pkt(param_1,&local_58,10);
      }
    }
    else {
      btfmcodec_move_to_next_state(lVar1);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// btfmcodec_prepare_bearer @ 00102aa0 size=760
// signature: undefined btfmcodec_prepare_bearer(void)
// callers: [btfmcodec_wq_prepare_bearer]
//------------------------------------------------------------

void btfmcodec_prepare_bearer(long param_1,uint param_2)

{
  long lVar1;
  undefined *puVar2;
  undefined4 uVar3;
  uint uVar4;
  byte bVar5;
  code *pcVar6;
  int iVar7;
  undefined8 uVar8;
  ulong uVar9;
  long lVar10;
  undefined8 local_58;
  undefined2 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  lVar10 = *(long *)(param_1 + 0x2d0);
  lVar1 = lVar10 + 0x390;
  mutex_lock(lVar1);
  uVar3 = *(undefined4 *)(lVar10 + 0x3c4);
  mutex_unlock(lVar1);
  if (param_2 < 4) {
    uVar8 = coverttostring(uVar3);
    if (2 < param_2 - 1) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x102d98);
      (*pcVar6)();
    }
    _printk(&DAT_0010666d,"btfmcodec_prepare_bearer",uVar8,(&transport_type_text)[param_2 - 1]);
    mutex_lock(lVar1);
    uVar4 = *(uint *)(lVar10 + 0x3c4);
    mutex_unlock(lVar1);
    if (param_2 == 3) {
      if (uVar4 - 3 < 0xfffffffe) {
        btfmcodec_set_current_state(lVar1,0);
      }
LAB_00102c3c:
      bVar5 = (byte)uVar4;
    }
    else {
      if (param_2 == 2) {
        if (1 < uVar4 - 3) {
          btfmcodec_set_current_state(lVar1,3);
          uVar9 = btfmcodec_is_valid_cache_avb(lVar10);
          puVar2 = &DAT_0010580c;
          if ((uVar9 & 1) == 0) {
            puVar2 = &DAT_00105fbb;
          }
          _printk(puVar2,"btfmcodec_prepare_bearer");
          local_50 = 3;
          local_58 = 0x250000001;
          iVar7 = btfmcodec_dev_enqueue_pkt(param_1,&local_58,10);
          if (iVar7 < 0) goto LAB_00102b20;
          iVar7 = btfmcodec_wait_for_bearer_ind(param_1);
          if (-1 < iVar7) {
            btfmcodec_move_to_next_state(lVar1);
            uVar9 = btfmcodec_is_valid_cache_avb(lVar10);
            if ((uVar9 & 1) != 0) {
              _printk(&DAT_00105f1a,"btfmcodec_prepare_bearer");
              btfmcodec_initiate_hwep_shutdown(param_1);
            }
            goto LAB_00102b20;
          }
          _printk(&DAT_00106140,"btfmcodec_prepare_bearer");
          btfmcodec_revert_current_state(lVar1);
          if (iVar7 != -3) goto LAB_00102b20;
          local_58 = 0x258000002;
          local_50 = 0x302;
          goto LAB_00102b10;
        }
        goto LAB_00102c3c;
      }
      if (param_2 != 1) goto LAB_00102b20;
      if (uVar4 - 1 < 2) goto LAB_00102c3c;
      if ((4 < uVar4) || ((1 << (ulong)(uVar4 & 0x1f) & 0x19U) == 0)) goto LAB_00102b20;
      uVar9 = btfmcodec_is_valid_cache_avb(lVar10);
      if ((uVar9 & 1) != 0) {
        _printk(&DAT_001070a1,"btfmcodec_prepare_bearer");
        btfmcodec_set_current_state(lVar1,1);
        btfmcodec_configure_hwep(param_1);
        goto LAB_00102b20;
      }
      if (uVar4 != 0) {
        _printk(&DAT_00106f69,"btfmcodec_prepare_bearer");
      }
      _printk(&DAT_00106934,"btfmcodec_prepare_bearer");
      btfmcodec_set_current_state(lVar1,0);
      mutex_lock(lVar1);
      uVar3 = *(undefined4 *)(lVar10 + 0x3c4);
      mutex_unlock(lVar1);
      bVar5 = (byte)uVar3;
    }
    local_58 = 0x250000001;
    local_50 = (ushort)bVar5;
  }
  else {
    local_58 = 0x250000001;
    local_50 = CONCAT11(2,(char)uVar3);
  }
LAB_00102b10:
  btfmcodec_dev_enqueue_pkt(param_1,&local_58,10);
LAB_00102b20:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// btfmcodec_wq_prepare_bearer @ 00102d9c size=72
// signature: undefined btfmcodec_wq_prepare_bearer(void)
// callers: []
//------------------------------------------------------------

void btfmcodec_wq_prepare_bearer(long param_1)

{
  _printk(&DAT_0010583d,"btfmcodec_wq_prepare_bearer",*(undefined1 *)(param_1 + 0x140));
  btfmcodec_prepare_bearer(param_1 + -0x188,*(undefined1 *)(param_1 + 0x140));
  return;
}



//------------------------------------------------------------
// btfmcodec_register_hw_ep @ 00102de8 size=376
// signature: undefined btfmcodec_register_hw_ep(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 btfmcodec_register_hw_ep(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  long lVar6;
  undefined *puVar7;
  undefined8 *puVar8;
  
  lVar6 = btfm_get_btfmcodec();
  mutex_lock(lVar6 + 0x410);
  if (lVar6 == 0) {
    puVar7 = &DAT_0010585a;
  }
  else if (*(int *)(param_1 + 0xc) == 0) {
    puVar7 = &DAT_001055c5;
  }
  else {
    if (*(long *)(lVar6 + 0x3d8) == 0) {
      puVar8 = (undefined8 *)kmalloc_trace(_cdev_init,0xdc0,0x70);
      if (puVar8 == (undefined8 *)0x0) {
        _printk(&DAT_001061bc,"btfmcodec_register_hw_ep","btfmcodec_register_hw_ep");
        uVar5 = 0xfffffff4;
      }
      else {
        *(undefined8 **)(lVar6 + 0x3d8) = puVar8;
        uVar2 = param_1[0xb];
        uVar1 = param_1[0xc];
        uVar3 = param_1[0xd];
        puVar8[10] = param_1[10];
        puVar8[0xb] = uVar2;
        uVar2 = param_1[6];
        uVar4 = param_1[7];
        puVar8[0xc] = uVar1;
        puVar8[0xd] = uVar3;
        uVar1 = param_1[8];
        uVar3 = param_1[9];
        puVar8[6] = uVar2;
        puVar8[7] = uVar4;
        uVar2 = param_1[2];
        uVar4 = param_1[3];
        puVar8[8] = uVar1;
        puVar8[9] = uVar3;
        puVar8[2] = uVar2;
        puVar8[3] = uVar4;
        uVar2 = param_1[5];
        uVar1 = *param_1;
        uVar3 = param_1[1];
        puVar8[4] = param_1[4];
        puVar8[5] = uVar2;
        *puVar8 = uVar1;
        puVar8[1] = uVar3;
        _printk(&DAT_0010617e,"btfmcodec_register_hw_ep");
        _printk(&DAT_00106c28,"btfmcodec_register_hw_ep",puVar8 + 1);
        _printk(&DAT_001056cd,"btfmcodec_register_hw_ep",*(undefined4 *)(puVar8 + 0xc));
        _printk(&DAT_0010669e,"btfmcodec_register_hw_ep",(uint)puVar8[0xd] & 1);
        uVar5 = btfm_register_codec(puVar8);
      }
      goto LAB_00102e90;
    }
    puVar7 = &DAT_0010593d;
  }
  _printk(puVar7,"btfmcodec_register_hw_ep");
  uVar5 = 0xffffffff;
LAB_00102e90:
  mutex_unlock(lVar6 + 0x410);
  return uVar5;
}



//------------------------------------------------------------
// btfmcodec_unregister_hw_ep @ 00102f64 size=212
// signature: undefined btfmcodec_unregister_hw_ep(void)
// callers: []
//------------------------------------------------------------

undefined8 btfmcodec_unregister_hw_ep(char *param_1)

{
  int iVar1;
  long lVar2;
  undefined *puVar3;
  long lVar4;
  
  lVar2 = btfm_get_btfmcodec();
  mutex_lock(lVar2 + 0x410);
  if (lVar2 == 0) {
    _printk(&DAT_0010585a,"btfmcodec_unregister_hw_ep");
  }
  else {
    lVar4 = *(long *)(lVar2 + 0x3d8);
    if (lVar4 == 0) {
      _printk(&DAT_001061e2,"btfmcodec_unregister_hw_ep","btfmcodec_unregister_hw_ep");
    }
    else {
      iVar1 = strncmp((char *)(lVar4 + 8),param_1,0x40);
      if (iVar1 == 0) {
        btfm_unregister_codec();
        kfree(lVar4);
        puVar3 = &DAT_00105ff0;
      }
      else {
        puVar3 = &DAT_00106a79;
      }
      _printk(puVar3,"btfmcodec_unregister_hw_ep","btfmcodec_unregister_hw_ep",param_1);
    }
  }
  mutex_unlock(lVar2 + 0x410);
  return 0xffffffff;
}



//------------------------------------------------------------
// btfmcodec_hwep_startup @ 0010303c size=92
// signature: undefined btfmcodec_hwep_startup(void)
// callers: []
//------------------------------------------------------------

undefined8 btfmcodec_hwep_startup(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 *puVar3;
  code *pcVar4;
  
  if ((((*(long *)(param_1 + 0x3d8) == 0) ||
       (lVar2 = *(long *)(*(long *)(param_1 + 0x3d8) + 0x50), lVar2 == 0)) ||
      (puVar3 = *(undefined8 **)(lVar2 + 0x60), puVar3 == (undefined8 *)0x0)) ||
     (pcVar4 = (code *)*puVar3, pcVar4 == (code *)0x0)) {
    uVar1 = 0xffffffff;
  }
  else {
    if (*(int *)(pcVar4 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x103080);
      (*pcVar4)();
    }
    uVar1 = (*pcVar4)();
  }
  return uVar1;
}



//------------------------------------------------------------
// btfmcodec_hwep_shutdown @ 0010309c size=564
// signature: undefined btfmcodec_hwep_shutdown(void)
// callers: [btfmcodec_wq_hwep_shutdown]
//------------------------------------------------------------

ulong btfmcodec_hwep_shutdown(long param_1,undefined4 param_2,ulong param_3)

{
  long lVar1;
  byte bVar2;
  int iVar3;
  undefined8 uVar4;
  code *pcVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined1 local_60;
  long local_58;
  
  lVar9 = sp_el0;
  local_58 = *(long *)(lVar9 + 0x638);
  if (*(long *)(param_1 + 0x3d8) == 0) {
    lVar9 = 0;
  }
  else {
    lVar9 = *(long *)(*(long *)(param_1 + 0x3d8) + 0x50);
  }
  lVar6 = *(long *)(param_1 + 0x3d0);
  local_60 = 0;
  local_68 = 0;
  iVar3 = btfmcodec_get_current_transport(param_1 + 0x390);
  if ((iVar3 == 2) && ((param_3 & 1) != 0)) {
    local_60 = (undefined1)param_2;
    local_68 = 0x150000004;
    *(undefined1 *)(lVar6 + 0x2ca) = 0;
    btfmcodec_dev_enqueue_pkt(lVar6,&local_68,9);
    bVar2 = *(byte *)(lVar6 + 0x2ca);
    if (bVar2 == 0) {
      local_78 = 0;
      uStack_70 = 0;
      lVar1 = lVar6 + 0x250;
      local_88 = 0;
      uStack_80 = 0;
      local_90 = 0;
      init_wait_entry(&local_90,0);
      uVar7 = prepare_to_wait_event(lVar1,&local_90,1);
      if (*(char *)(lVar6 + 0x2ca) == '\0') {
        uVar8 = 0x4e2;
        do {
          if (uVar7 != 0) goto LAB_00103190;
          uVar8 = schedule_timeout(uVar8);
          uVar7 = prepare_to_wait_event(lVar1,&local_90,1);
          if (uVar8 == 0 && *(char *)(lVar6 + 0x2ca) != '\0') {
            uVar8 = 1;
          }
        } while ((*(char *)(lVar6 + 0x2ca) == '\0') && (uVar8 != 0));
      }
      else {
        uVar8 = 0x4e2;
      }
      uVar7 = uVar8;
      finish_wait(lVar1,&local_90);
LAB_00103190:
      if ((int)uVar7 == 0) {
        _printk(&DAT_00105c41,"btfmcodec_hwep_shutdown");
        goto LAB_001031b4;
      }
      bVar2 = *(byte *)(lVar6 + 0x2ca);
    }
    else {
      uVar7 = 0x4e2;
    }
    if (bVar2 - 1 < 3) {
      uVar7 = (ulong)*(uint *)(&DAT_00107718 + (long)(char)(bVar2 - 1) * 4);
    }
  }
  else {
    if ((param_3 & 1) == 0) {
      _printk(&DAT_00106aad,"btfmcodec_hwep_shutdown");
    }
    else {
      btfmcodec_get_current_transport(param_1 + 0x390);
      uVar4 = coverttostring();
      _printk(&DAT_00106af3,"btfmcodec_hwep_shutdown",uVar4);
    }
    uVar7 = 0;
  }
LAB_001031b4:
  if (((lVar9 != 0) && (*(long *)(lVar9 + 0x60) != 0)) &&
     (pcVar5 = *(code **)(*(long *)(lVar9 + 0x60) + 8), pcVar5 != (code *)0x0)) {
    if (*(int *)(pcVar5 + -4) != -0xce76772) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1031e8);
      (*pcVar5)();
    }
    (*pcVar5)(*(undefined8 *)(param_1 + 0x3d8),param_2);
  }
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7 & 0xffffffff;
}



//------------------------------------------------------------
// btfmcodec_wq_hwep_shutdown @ 001032d4 size=228
// signature: undefined btfmcodec_wq_hwep_shutdown(void)
// callers: []
//------------------------------------------------------------

void btfmcodec_wq_hwep_shutdown(long param_1)

{
  int iVar1;
  undefined1 uVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  
  lVar3 = *(long *)(param_1 + 0x178);
  _printk(&DAT_001055fe,"btfmcodec_wq_hwep_shutdown");
  plVar4 = *(long **)(lVar3 + 0x3e0);
  if (plVar4 == (long *)(lVar3 + 0x3e0)) {
LAB_00103380:
    uVar2 = 2;
  }
  else {
    do {
      plVar5 = (long *)*plVar4;
      _printk(&DAT_00106c5f,"btfmcodec_wq_hwep_shutdown",(char)plVar4[-3]);
      iVar1 = btfmcodec_hwep_shutdown(lVar3,(char)plVar4[-3],1);
      if (iVar1 < 0) {
        _printk(&DAT_00106083,"btfmcodec_wq_hwep_shutdown",(char)plVar4[-3]);
        goto LAB_00103380;
      }
      plVar4 = plVar5;
    } while (plVar5 != (long *)(lVar3 + 0x3e0));
    uVar2 = 1;
  }
  *(undefined1 *)(param_1 + 0x174) = uVar2;
  __wake_up(param_1 + 0x128,1,1,0);
  return;
}



//------------------------------------------------------------
// btfmcodec_hwep_hw_params @ 001033bc size=92
// signature: undefined btfmcodec_hwep_hw_params(void)
// callers: []
//------------------------------------------------------------

undefined8 btfmcodec_hwep_hw_params(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  
  if ((((*(long *)(param_1 + 0x3d8) == 0) ||
       (lVar2 = *(long *)(*(long *)(param_1 + 0x3d8) + 0x50), lVar2 == 0)) ||
      (lVar2 = *(long *)(lVar2 + 0x60), lVar2 == 0)) ||
     (pcVar3 = *(code **)(lVar2 + 0x10), pcVar3 == (code *)0x0)) {
    uVar1 = 0xffffffff;
  }
  else {
    if (*(int *)(pcVar3 + -4) != 0x183ab1ff) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103400);
      (*pcVar3)();
    }
    uVar1 = (*pcVar3)();
  }
  return uVar1;
}



//------------------------------------------------------------
// btfmcodec_is_valid_cache_avb @ 0010341c size=20
// signature: undefined btfmcodec_is_valid_cache_avb(void)
// callers: [btfmcodec_prepare_bearer]
//------------------------------------------------------------

bool btfmcodec_is_valid_cache_avb(long param_1)

{
  return *(long *)(param_1 + 0x3e0) != param_1 + 0x3e0;
}



//------------------------------------------------------------
// btfmcodec_hwep_prepare @ 00103434 size=280
// signature: undefined btfmcodec_hwep_prepare(void)
// callers: [btfmcodec_wq_hwep_configure, btfmcodec_dai_prepare]
//------------------------------------------------------------

int btfmcodec_hwep_prepare(long param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  code *pcVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x3d8);
  if ((((lVar6 == 0) || (*(long *)(lVar6 + 0x50) == 0)) ||
      (lVar4 = *(long *)(*(long *)(lVar6 + 0x50) + 0x60), lVar4 == 0)) ||
     (pcVar5 = *(code **)(lVar4 + 0x18), pcVar5 == (code *)0x0)) {
    return -1;
  }
  if (*(int *)(pcVar5 + -4) != -0x42ed814f) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1034a8);
    (*pcVar5)();
  }
  iVar1 = (*pcVar5)(lVar6);
  _printk(&DAT_001067be,"btfmcodec_hwep_prepare","btfmcodec_hwep_prepare",
          *(undefined8 *)(lVar6 + 0x68));
  if (iVar1 != 0) {
    return iVar1;
  }
  if ((*(ulong *)(lVar6 + 0x68) & 1) == 0) {
    if (param_4 == 0) {
      return 0;
    }
    if (((uint)*(undefined8 *)(lVar6 + 0x68) >> 1 & 1) == 0) {
      return 0;
    }
    iVar1 = btfmcodec_configure_dma(param_1,param_4);
    if (-1 < iVar1) {
LAB_0010351c:
      uVar3 = 2;
      goto LAB_00103520;
    }
    puVar2 = &DAT_00106289;
  }
  else {
    iVar1 = btfmcodec_configure_master(param_1,param_4);
    if (-1 < iVar1) goto LAB_0010351c;
    puVar2 = &DAT_00106590;
  }
  _printk(puVar2,"btfmcodec_hwep_prepare",iVar1);
  uVar3 = 0;
LAB_00103520:
  btfmcodec_set_current_state(param_1 + 0x390,uVar3);
  return iVar1;
}



//------------------------------------------------------------
// btfmcodec_configure_master @ 0010354c size=504
// signature: undefined btfmcodec_configure_master(void)
// callers: [btfmcodec_hwep_prepare]
//------------------------------------------------------------

void btfmcodec_configure_master(long param_1,uint param_2)

{
  byte bVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  code *pcVar5;
  long lVar6;
  ulong uVar7;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined1 local_60;
  undefined8 local_5f;
  undefined4 local_57;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  undefined4 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x3d8);
  local_40 = 0;
  lVar6 = *(long *)(param_1 + 0x3d0);
  local_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  local_44 = 0;
  if ((((lVar2 == 0) || (*(long *)(lVar2 + 0x50) == 0)) ||
      (lVar4 = *(long *)(*(long *)(lVar2 + 0x50) + 0x60), lVar4 == 0)) ||
     (pcVar5 = *(code **)(lVar4 + 0x30), pcVar5 == (code *)0x0)) {
    _printk(&DAT_00106d26,"btfmcodec_configure_master");
    uVar3 = 0xffffffff;
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x4abb06c2) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x103608);
      (*pcVar5)();
    }
    (*pcVar5)(lVar2,&local_50,param_2);
    _printk(&DAT_001060d1,"btfmcodec_configure_master",param_2 & 0xff);
    local_5f = CONCAT44(uStack_48,uStack_4c);
    local_60 = (undefined1)local_50;
    local_68 = 0xd50000002;
    local_57 = local_44;
    *(undefined1 *)(lVar6 + 0x2c9) = 0;
    btfmcodec_dev_enqueue_pkt(lVar6,&local_68,0x15);
    bVar1 = *(byte *)(lVar6 + 0x2c9);
    if (bVar1 == 0) {
      local_78 = 0;
      uStack_70 = 0;
      lVar2 = lVar6 + 0x238;
      local_88 = 0;
      uStack_80 = 0;
      local_90 = 0;
      init_wait_entry(&local_90,0);
      uVar3 = prepare_to_wait_event(lVar2,&local_90,1);
      if (*(char *)(lVar6 + 0x2c9) == '\0') {
        uVar7 = 0x4e2;
        do {
          if (uVar3 != 0) goto LAB_001036bc;
          uVar7 = schedule_timeout(uVar7);
          uVar3 = prepare_to_wait_event(lVar2,&local_90,1);
          if (uVar7 == 0 && *(char *)(lVar6 + 0x2c9) != '\0') {
            uVar7 = 1;
          }
        } while ((*(char *)(lVar6 + 0x2c9) == '\0') && (uVar7 != 0));
      }
      else {
        uVar7 = 0x4e2;
      }
      uVar3 = uVar7;
      finish_wait(lVar2,&local_90);
LAB_001036bc:
      if ((int)uVar3 == 0) {
        _printk(&DAT_00105c41,"btfmcodec_configure_master");
        uVar3 = 0xffffff92;
        goto LAB_001035b8;
      }
      bVar1 = *(byte *)(lVar6 + 0x2c9);
    }
    else {
      uVar3 = 0x4e2;
    }
    if (bVar1 - 1 < 3) {
      uVar3 = (ulong)*(uint *)(&DAT_00107718 + (long)(char)(bVar1 - 1) * 4);
    }
  }
LAB_001035b8:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// btfmcodec_configure_dma @ 00103744 size=508
// signature: undefined btfmcodec_configure_dma(void)
// callers: [btfmcodec_hwep_prepare]
//------------------------------------------------------------

void btfmcodec_configure_dma(long param_1,uint param_2)

{
  byte bVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  code *pcVar5;
  long lVar6;
  ulong uVar7;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined1 local_58;
  undefined4 local_57;
  undefined2 local_53;
  undefined4 local_51;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x3d8);
  local_48 = 0;
  local_40 = 0;
  lVar6 = *(long *)(param_1 + 0x3d0);
  if ((((lVar2 == 0) || (*(long *)(lVar2 + 0x50) == 0)) ||
      (lVar4 = *(long *)(*(long *)(lVar2 + 0x50) + 0x60), lVar4 == 0)) ||
     (pcVar5 = *(code **)(lVar4 + 0x30), pcVar5 == (code *)0x0)) {
    _printk(&DAT_00106d26,"btfmcodec_configure_dma");
    uVar3 = 0xffffffff;
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x4abb06c2) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1037fc);
      (*pcVar5)();
    }
    (*pcVar5)(lVar2,&local_48,param_2);
    _printk(&DAT_001060d1,"btfmcodec_configure_dma",param_2 & 0xff);
    local_58 = (undefined1)local_48;
    local_57 = local_48._4_4_;
    local_60 = 0xb58000006;
    local_53 = (undefined2)local_40;
    local_51 = local_40._2_4_;
    *(undefined1 *)(lVar6 + 0x2ce) = 0;
    btfmcodec_dev_enqueue_pkt(lVar6,&local_60,0x13);
    bVar1 = *(byte *)(lVar6 + 0x2ce);
    if (bVar1 == 0) {
      local_70 = 0;
      uStack_68 = 0;
      lVar2 = lVar6 + 0x2b0;
      local_80 = 0;
      uStack_78 = 0;
      local_88 = 0;
      init_wait_entry(&local_88,0);
      uVar3 = prepare_to_wait_event(lVar2,&local_88,1);
      if (*(char *)(lVar6 + 0x2ce) == '\0') {
        uVar7 = 0x4e2;
        do {
          if (uVar3 != 0) goto LAB_001038b8;
          uVar7 = schedule_timeout(uVar7);
          uVar3 = prepare_to_wait_event(lVar2,&local_88,1);
          if (uVar7 == 0 && *(char *)(lVar6 + 0x2ce) != '\0') {
            uVar7 = 1;
          }
        } while ((*(char *)(lVar6 + 0x2ce) == '\0') && (uVar7 != 0));
      }
      else {
        uVar7 = 0x4e2;
      }
      uVar3 = uVar7;
      finish_wait(lVar2,&local_88);
LAB_001038b8:
      if ((int)uVar3 == 0) {
        _printk(&DAT_00105c41,"btfmcodec_configure_dma");
        uVar3 = 0xffffff92;
        goto LAB_001037ac;
      }
      bVar1 = *(byte *)(lVar6 + 0x2ce);
    }
    else {
      uVar3 = 0x4e2;
    }
    if (bVar1 - 1 < 3) {
      uVar3 = (ulong)*(uint *)(&DAT_00107718 + (long)(char)(bVar1 - 1) * 4);
    }
  }
LAB_001037ac:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// btfmcodec_hwep_set_channel_map @ 00103944 size=88
// signature: undefined btfmcodec_hwep_set_channel_map(void)
// callers: []
//------------------------------------------------------------

undefined8 btfmcodec_hwep_set_channel_map(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  
  if ((((param_1 == 0) || (*(long *)(param_1 + 0x50) == 0)) ||
      (lVar2 = *(long *)(*(long *)(param_1 + 0x50) + 0x60), lVar2 == 0)) ||
     (pcVar3 = *(code **)(lVar2 + 0x20), pcVar3 == (code *)0x0)) {
    uVar1 = 0xffffffff;
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x48bc95d8) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103984);
      (*pcVar3)();
    }
    uVar1 = (*pcVar3)();
  }
  return uVar1;
}



//------------------------------------------------------------
// btfmcodec_hwep_get_channel_map @ 001039a0 size=88
// signature: undefined btfmcodec_hwep_get_channel_map(void)
// callers: []
//------------------------------------------------------------

undefined8 btfmcodec_hwep_get_channel_map(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  
  if ((((param_1 == 0) || (*(long *)(param_1 + 0x50) == 0)) ||
      (lVar2 = *(long *)(*(long *)(param_1 + 0x50) + 0x60), lVar2 == 0)) ||
     (pcVar3 = *(code **)(lVar2 + 0x28), pcVar3 == (code *)0x0)) {
    uVar1 = 0xffffffff;
  }
  else {
    if (*(int *)(pcVar3 + -4) != 0x53aada0d) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1039e0);
      (*pcVar3)();
    }
    uVar1 = (*pcVar3)();
  }
  return uVar1;
}



//------------------------------------------------------------
// btfmcodec_wq_hwep_configure @ 001039fc size=372
// signature: undefined btfmcodec_wq_hwep_configure(void)
// callers: []
//------------------------------------------------------------

void btfmcodec_wq_hwep_configure(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  int iVar5;
  undefined1 uVar6;
  long lVar7;
  undefined8 *puVar8;
  code *pcVar9;
  long lVar10;
  long lVar11;
  long *plVar12;
  long *plVar13;
  
  lVar11 = *(long *)(param_1 + 0x118);
  plVar13 = (long *)*(long *)(lVar11 + 0x3e0);
  while( true ) {
    plVar12 = plVar13;
    if (plVar12 == (long *)(lVar11 + 0x3e0)) {
      uVar6 = 1;
      goto LAB_00103b38;
    }
    plVar13 = (long *)*plVar12;
    uVar6 = *(undefined1 *)(plVar12 + -3);
    uVar1 = *(undefined4 *)((long)plVar12 + -0x14);
    uVar3 = *(undefined1 *)(plVar12 + -2);
    uVar2 = *(undefined4 *)((long)plVar12 + -0xc);
    uVar4 = *(undefined1 *)(plVar12 + -1);
    _printk(&DAT_00105618,"btfmcodec_wq_hwep_configure",uVar6,uVar1,uVar3);
    if ((((*(long *)(lVar11 + 0x3d8) == 0) ||
         (lVar7 = *(long *)(*(long *)(lVar11 + 0x3d8) + 0x50), lVar7 == 0)) ||
        (puVar8 = *(undefined8 **)(lVar7 + 0x60), puVar8 == (undefined8 *)0x0)) ||
       (pcVar9 = (code *)*puVar8, pcVar9 == (code *)0x0)) break;
    if (*(int *)(pcVar9 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x103aa8);
      (*pcVar9)();
    }
    iVar5 = (*pcVar9)();
    if (((iVar5 < 0) || (lVar7 = *(long *)(lVar11 + 0x3d8), lVar7 == 0)) ||
       ((*(long *)(lVar7 + 0x50) == 0 ||
        ((lVar10 = *(long *)(*(long *)(lVar7 + 0x50) + 0x60), lVar10 == 0 ||
         (pcVar9 = *(code **)(lVar10 + 0x10), pcVar9 == (code *)0x0)))))) break;
    if (*(int *)(pcVar9 + -4) != 0x183ab1ff) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x103af4);
      (*pcVar9)();
    }
    iVar5 = (*pcVar9)(lVar7,uVar3,uVar2,uVar4);
    if ((iVar5 < 0) || (iVar5 = btfmcodec_hwep_prepare(lVar11,uVar1,uVar2,uVar6), iVar5 < 0)) break;
  }
  _printk(&DAT_00105886,"btfmcodec_wq_hwep_configure",*(undefined1 *)(plVar12 + -3));
  uVar6 = 2;
LAB_00103b38:
  *(undefined1 *)(param_1 + 0x115) = uVar6;
  __wake_up(param_1 + 0xe0,1,1,0);
  return;
}



//------------------------------------------------------------
// btfm_register_codec @ 00103b74 size=1008
// signature: undefined btfm_register_codec(void)
// callers: [btfmcodec_register_hw_ep]
//------------------------------------------------------------

ulong btfm_register_codec(long param_1)

{
  ulong *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  char cVar6;
  bool bVar7;
  int iVar8;
  long lVar9;
  ulong uVar10;
  undefined8 *puVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  undefined8 *puVar15;
  undefined8 uVar16;
  long lVar17;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  code *pcStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar9 = sp_el0;
  local_58 = *(long *)(lVar9 + 0x638);
  lVar9 = btfm_get_btfmcodec();
  lVar17 = *(long *)(lVar9 + 0x3d0);
  *(code **)(lVar9 + 0x3f8) = btfmcodec_adsp_ssr_notify;
  uVar10 = qcom_register_ssr_notifier("lpass",lVar9 + 0x3f8);
  *(ulong *)(lVar9 + 0x3f0) = uVar10;
  if (uVar10 < 0xfffffffffffff001) {
    btfmcodec_dai_info = (undefined8 *)__kmalloc((long)*(int *)(param_1 + 0x60) * 0xe0,0xdc0);
    if (btfmcodec_dai_info == (undefined8 *)0x0) {
      _printk(&DAT_001064a0,"btfm_register_codec");
      uVar10 = 0xfffffff4;
    }
    else {
      if (0 < *(int *)(param_1 + 0x60)) {
        lVar13 = 0;
        lVar14 = 0;
        puVar11 = btfmcodec_dai_info;
        puVar15 = btfmcodec_dai_info + 0xe;
        do {
          lVar14 = lVar14 + 1;
          puVar2 = (undefined8 *)(*(long *)(param_1 + 0x50) + lVar13);
          lVar13 = lVar13 + 0x68;
          *puVar11 = *puVar2;
          *(undefined4 *)(puVar15 + -0xd) = *(undefined4 *)(puVar2 + 1);
          puVar15[2] = puVar2[2];
          uVar4 = puVar2[6];
          uVar3 = puVar2[3];
          uVar5 = puVar2[4];
          puVar15[5] = puVar2[5];
          puVar15[6] = uVar4;
          puVar15[3] = uVar3;
          puVar15[4] = uVar5;
          uVar3 = puVar2[10];
          uVar4 = puVar2[8];
          uVar5 = puVar2[9];
          puVar15[0xb] = puVar2[0xb];
          uVar16 = puVar2[7];
          puVar15[9] = uVar5;
          puVar15[10] = uVar3;
          puVar15[7] = uVar16;
          puVar15[8] = uVar4;
          *puVar15 = &btfmcodec_dai_ops;
          puVar11 = puVar11 + 0x1c;
          puVar15 = puVar15 + 0x1c;
        } while (lVar14 < *(int *)(param_1 + 0x60));
      }
      _printk(&DAT_00105f3d,"btfm_register_codec");
      _printk(&DAT_00106f96,"btfm_register_codec",**(undefined8 **)(lVar9 + 0x88));
      uVar10 = snd_soc_register_component
                         (lVar9,btfmcodec_codec_component,btfmcodec_dai_info,
                          *(undefined4 *)(param_1 + 0x60));
      uVar10 = uVar10 & 0xffffffff;
      _printk(&DAT_00106356,"btfm_register_codec",lVar9);
      _printk(&DAT_00105c90,"btfm_register_codec",lVar9);
      _printk(&DAT_001070da,"btfm_register_codec",param_1);
      _printk(&DAT_001065bb,"btfm_register_codec",*(undefined8 *)(lVar9 + 0x3d0));
      local_78 = *(undefined8 *)(lVar17 + 0x168);
      pcStack_70 = *(code **)(lVar17 + 0x170);
      local_68 = *(undefined8 *)(lVar17 + 0x178);
      uStack_60 = *(undefined8 *)(lVar17 + 0x180);
      local_88 = *(undefined8 *)(lVar17 + 0x158);
      uStack_80 = *(undefined8 *)(lVar17 + 0x160);
      _printk(&DAT_00105b2a,"btfm_register_codec",&local_88);
      local_78 = *(undefined8 *)(lVar17 + 0x198);
      pcStack_70 = *(code **)(lVar17 + 0x1a0);
      local_68 = *(undefined8 *)(lVar17 + 0x1a8);
      uStack_60 = *(undefined8 *)(lVar17 + 0x1b0);
      local_88 = *(undefined8 *)(lVar17 + 0x188);
      uStack_80 = *(undefined8 *)(lVar17 + 400);
      _printk(&DAT_001062b1,"btfm_register_codec",&local_88);
      *(undefined8 *)(lVar17 + 0x158) = 0xfffffffe0;
      *(long *)(lVar17 + 0x160) = lVar17 + 0x160;
      *(long *)(lVar17 + 0x168) = lVar17 + 0x160;
      *(code **)(lVar17 + 0x170) = btfmcodec_wq_hwep_shutdown;
      *(undefined8 *)(lVar17 + 0x188) = 0xfffffffe0;
      *(long *)(lVar17 + 400) = lVar17 + 400;
      *(long *)(lVar17 + 0x198) = lVar17 + 400;
      *(code **)(lVar17 + 0x1a0) = btfmcodec_wq_prepare_bearer;
      *(undefined8 *)(lVar17 + 0x1b8) = 0xfffffffe0;
      *(long *)(lVar17 + 0x1c0) = lVar17 + 0x1c0;
      *(long *)(lVar17 + 0x1c8) = lVar17 + 0x1c0;
      local_78 = *(undefined8 *)(lVar17 + 0x168);
      *(code **)(lVar17 + 0x1d0) = btfmcodec_wq_hwep_configure;
      local_68 = *(undefined8 *)(lVar17 + 0x178);
      uStack_60 = *(undefined8 *)(lVar17 + 0x180);
      pcStack_70 = btfmcodec_wq_hwep_shutdown;
      local_88 = *(undefined8 *)(lVar17 + 0x158);
      uStack_80 = *(undefined8 *)(lVar17 + 0x160);
      _printk(&DAT_00105f63,"btfm_register_codec",&local_88);
      local_78 = *(undefined8 *)(lVar17 + 0x198);
      pcStack_70 = *(code **)(lVar17 + 0x1a0);
      local_68 = *(undefined8 *)(lVar17 + 0x1a8);
      uStack_60 = *(undefined8 *)(lVar17 + 0x1b0);
      local_88 = *(undefined8 *)(lVar17 + 0x188);
      uStack_80 = *(undefined8 *)(lVar17 + 400);
      _printk(&DAT_001058a9,"btfm_register_codec",&local_88);
      _printk(&DAT_001062d4,"btfm_register_codec",btfmcodec_wq_prepare_bearer);
      _printk(&DAT_001067f2,"btfm_register_codec",btfmcodec_wq_hwep_shutdown);
      uVar12 = isCpSupported();
      if ((uVar12 & 1) != 0) {
        iVar8 = strcmp((char *)(param_1 + 8),"btfmslim");
        if (iVar8 == 0) {
          puVar1 = (ulong *)(param_1 + 0x68);
          Hint_Prefetch(puVar1,2,0,1);
          do {
            cVar6 = '\x01';
            bVar7 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar7) {
              *puVar1 = *puVar1 | 1;
              cVar6 = ExclusiveMonitorsStatus();
            }
          } while (cVar6 != '\0');
        }
        else {
          iVar8 = strcmp((char *)(param_1 + 8),"btfmswr_slave");
          if (iVar8 == 0) {
            puVar1 = (ulong *)(param_1 + 0x68);
            Hint_Prefetch(puVar1,2,0,1);
            do {
              cVar6 = '\x01';
              bVar7 = (bool)ExclusiveMonitorPass(puVar1,0x10);
              if (bVar7) {
                *puVar1 = *puVar1 | 2;
                cVar6 = ExclusiveMonitorsStatus();
              }
            } while (cVar6 != '\0');
          }
        }
        _printk(&DAT_001060af,"btfm_register_codec","btfm_register_codec",
                (uint)*(undefined8 *)(param_1 + 0x68) & 1,
                (uint)*(undefined8 *)(param_1 + 0x68) >> 1 & 1);
      }
    }
  }
  else {
    _printk(&DAT_00106961,"btfm_register_codec",uVar10 & 0xffffffff);
  }
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10 & 0xffffffff;
}



//------------------------------------------------------------
// btfmcodec_adsp_ssr_notify @ 00103f84 size=252
// signature: undefined btfmcodec_adsp_ssr_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 btfmcodec_adsp_ssr_notify(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 local_38;
  undefined4 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  switch(param_2) {
  case 0:
    puVar2 = &DAT_00105ac1;
    break;
  case 1:
    uVar3 = *(undefined8 *)(param_1 + -0x28);
    _printk(&DAT_0010647e,"btfmcodec_adsp_ssr_notify");
    local_30 = 1;
    local_38 = 0x458000003;
    btfmcodec_dev_enqueue_pkt(uVar3,&local_38,0xc);
    goto LAB_00104050;
  case 2:
    puVar2 = &DAT_001070f5;
    break;
  case 3:
    puVar2 = &DAT_001060ee;
    break;
  default:
    _printk(&DAT_00106c40,"btfmcodec_adsp_ssr_notify");
    goto LAB_00104050;
  }
  _printk(puVar2,"btfmcodec_adsp_ssr_notify");
LAB_00104050:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// btfm_unregister_codec @ 00104084 size=32
// signature: undefined btfm_unregister_codec(void)
// callers: [btfmcodec_unregister_hw_ep]
//------------------------------------------------------------

void btfm_unregister_codec(void)

{
  btfm_get_btfmcodec();
  snd_soc_unregister_component();
  return;
}



//------------------------------------------------------------
// btfmcodec_dai_set_channel_map @ 001040a8 size=148
// signature: undefined btfmcodec_dai_set_channel_map(void)
// callers: []
//------------------------------------------------------------

undefined8 btfmcodec_dai_set_channel_map(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0x58) + 0x18) + 0x98);
  if (*(int *)(lVar2 + 0x3c4) == 0) {
    lVar2 = *(long *)(lVar2 + 0x3d8);
    if ((((lVar2 == 0) || (lVar2 = *(long *)(lVar2 + 0x50), lVar2 == 0)) ||
        (lVar2 = *(long *)(lVar2 + 0x60), lVar2 == 0)) ||
       (pcVar3 = *(code **)(lVar2 + 0x20), pcVar3 == (code *)0x0)) {
      uVar1 = 0xffffffff;
    }
    else {
      if (*(int *)(pcVar3 + -4) != -0x48bc95d8) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x104100);
        (*pcVar3)();
      }
      uVar1 = (*pcVar3)();
    }
  }
  else {
    uVar1 = coverttostring();
    _printk(&DAT_001056ed,"btfmcodec_dai_set_channel_map",uVar1);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// btfmcodec_dai_get_channel_map @ 00104140 size=112
// signature: undefined btfmcodec_dai_get_channel_map(void)
// callers: []
//------------------------------------------------------------

undefined8 btfmcodec_dai_get_channel_map(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  
  lVar2 = *(long *)(*(long *)(*(long *)(*(long *)(param_1 + 0x58) + 0x18) + 0x98) + 0x3d8);
  if ((((lVar2 == 0) || (*(long *)(lVar2 + 0x50) == 0)) ||
      (lVar3 = *(long *)(*(long *)(lVar2 + 0x50) + 0x60), lVar3 == 0)) ||
     (pcVar4 = *(code **)(lVar3 + 0x28), pcVar4 == (code *)0x0)) {
    uVar1 = 0xffffffff;
  }
  else {
    if (*(int *)(pcVar4 + -4) != 0x53aada0d) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x104198);
      (*pcVar4)();
    }
    uVar1 = (*pcVar4)(lVar2);
  }
  return uVar1;
}



//------------------------------------------------------------
// btfmcodec_dai_startup @ 001041b4 size=152
// signature: undefined btfmcodec_dai_startup(void)
// callers: []
//------------------------------------------------------------

undefined8 btfmcodec_dai_startup(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  code *pcVar5;
  long lVar6;
  
  lVar6 = *(long *)(*(long *)(*(long *)(param_2 + 0x58) + 0x18) + 0x98);
  lVar2 = lVar6 + 0x390;
  iVar1 = btfmcodec_get_current_transport(lVar2);
  if ((iVar1 == 0) || (iVar1 = btfmcodec_get_current_transport(lVar2), iVar1 == 2)) {
    lVar2 = *(long *)(lVar6 + 0x3d8);
    if ((((lVar2 == 0) || (lVar2 = *(long *)(lVar2 + 0x50), lVar2 == 0)) ||
        (puVar4 = *(undefined8 **)(lVar2 + 0x60), puVar4 == (undefined8 *)0x0)) ||
       (pcVar5 = (code *)*puVar4, pcVar5 == (code *)0x0)) {
      uVar3 = 0xffffffff;
    }
    else {
      if (*(int *)(pcVar5 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x104228);
        (*pcVar5)();
      }
      uVar3 = (*pcVar5)();
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// btfmcodec_dai_shutdown @ 00104250 size=500
// signature: undefined btfmcodec_dai_shutdown(void)
// callers: []
//------------------------------------------------------------

void btfmcodec_dai_shutdown(undefined8 param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  undefined4 uVar3;
  int iVar4;
  ulong uVar5;
  undefined8 uVar6;
  code *pcVar7;
  long *plVar8;
  long *plVar9;
  long lVar10;
  long lVar11;
  
  lVar10 = *(long *)(*(long *)(*(long *)(param_2 + 0x58) + 0x18) + 0x98);
  lVar1 = lVar10 + 0x390;
  iVar4 = btfmcodec_get_current_transport(lVar1);
  if ((iVar4 == 0) || (iVar4 = btfmcodec_get_current_transport(lVar1), iVar4 == 2)) {
    if (*(long *)(lVar10 + 0x3d8) == 0) {
      lVar11 = 0;
    }
    else {
      lVar11 = *(long *)(*(long *)(lVar10 + 0x3d8) + 0x50);
    }
    uVar3 = *(undefined4 *)(param_2 + 8);
    btfmcodec_get_current_transport(lVar1);
    _printk(&DAT_00106aad,"btfmcodec_hwep_shutdown");
    if (((lVar11 != 0) && (*(long *)(lVar11 + 0x60) != 0)) &&
       (pcVar7 = *(code **)(*(long *)(lVar11 + 0x60) + 8), pcVar7 != (code *)0x0)) {
      if (*(int *)(pcVar7 + -4) != -0xce76772) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x104300);
        (*pcVar7)();
      }
      (*pcVar7)(*(undefined8 *)(lVar10 + 0x3d8),uVar3);
    }
    plVar8 = (long *)(lVar10 + 0x3e0);
    plVar9 = plVar8;
    do {
      plVar9 = (long *)*plVar9;
      if (plVar9 == plVar8) goto LAB_00104368;
    } while ((char)plVar9[-3] != *(char *)(param_2 + 8));
    _printk(&DAT_00105b4c,"btfmcodec_delete_configs");
    uVar5 = __list_del_entry_valid(plVar9);
    if ((uVar5 & 1) != 0) {
      lVar10 = *plVar9;
      plVar2 = (long *)plVar9[1];
      *(long **)(lVar10 + 8) = plVar2;
      *plVar2 = lVar10;
    }
    *plVar9 = -0x2152ffffffffff00;
    plVar9[1] = -0x2152fffffffffede;
LAB_00104368:
    if ((long *)*plVar8 == plVar8) {
      uVar6 = 0;
    }
    else {
      _printk(&DAT_0010713f,"btfmcodec_dai_shutdown");
      uVar6 = 2;
    }
    btfmcodec_set_current_state(lVar1,uVar6);
  }
  else {
    btfmcodec_get_current_transport(lVar1);
    uVar6 = coverttostring();
    _printk(&DAT_00105cad,"btfmcodec_dai_shutdown",uVar6);
    plVar8 = (long *)(lVar10 + 0x3e0);
    do {
      plVar8 = (long *)*plVar8;
      if (plVar8 == (long *)(lVar10 + 0x3e0)) {
        return;
      }
    } while ((char)plVar8[-3] != *(char *)(param_2 + 8));
    _printk(&DAT_00105b4c,"btfmcodec_delete_configs");
    uVar5 = __list_del_entry_valid(plVar8);
    if ((uVar5 & 1) != 0) {
      lVar1 = *plVar8;
      plVar9 = (long *)plVar8[1];
      *(long **)(lVar1 + 8) = plVar9;
      *plVar9 = lVar1;
    }
    *plVar8 = -0x2152ffffffffff00;
    plVar8[1] = -0x2152fffffffffede;
  }
  return;
}



//------------------------------------------------------------
// btfmcodec_dai_hw_params @ 00104448 size=292
// signature: undefined btfmcodec_dai_hw_params(void)
// callers: []
//------------------------------------------------------------

undefined8 btfmcodec_dai_hw_params(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  uint uVar5;
  code *pcVar6;
  uint uVar7;
  long lVar8;
  
  lVar8 = *(long *)(*(long *)(*(long *)(param_3 + 0x58) + 0x18) + 0x98);
  uVar5 = *(uint *)(param_2 + 0x24);
  lVar3 = lVar8 + 0x390;
  if (uVar5 == 0) {
    uVar5 = *(uint *)(param_2 + 0x28);
    uVar7 = 0;
    if (uVar5 == 0) goto LAB_0010449c;
    uVar7 = 0x20;
  }
  else {
    uVar7 = 0;
  }
  uVar5 = (uVar5 & 0xaaaaaaaa) >> 1 | (uVar5 & 0x55555555) << 1;
  uVar5 = (uVar5 & 0xcccccccc) >> 2 | (uVar5 & 0x33333333) << 2;
  uVar5 = (uVar5 & 0xf0f0f0f0) >> 4 | (uVar5 & 0xf0f0f0f) << 4;
  uVar5 = (uVar5 & 0xff00ff00) >> 8 | (uVar5 & 0xff00ff) << 8;
  uVar7 = (uint)LZCOUNT(uVar5 >> 0x10 | uVar5 << 0x10) | uVar7;
LAB_0010449c:
  uVar1 = *(undefined4 *)(param_1 + 0x3c);
  bits_per_second = snd_pcm_format_width(uVar7);
  num_channels = (undefined1)*(undefined4 *)(param_2 + 0x11c);
  iVar2 = btfmcodec_get_current_transport(lVar3);
  if ((iVar2 == 0) || (iVar2 = btfmcodec_get_current_transport(lVar3), iVar2 == 2)) {
    lVar3 = *(long *)(lVar8 + 0x3d8);
    if ((((lVar3 == 0) || (*(long *)(lVar3 + 0x50) == 0)) ||
        (lVar8 = *(long *)(*(long *)(lVar3 + 0x50) + 0x60), lVar8 == 0)) ||
       (pcVar6 = *(code **)(lVar8 + 0x10), pcVar6 == (code *)0x0)) {
      uVar4 = 0xffffffff;
    }
    else {
      if (*(int *)(pcVar6 + -4) != 0x183ab1ff) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x10451c);
        (*pcVar6)();
      }
      uVar4 = (*pcVar6)(lVar3,bits_per_second,uVar1,num_channels);
    }
  }
  else {
    btfmcodec_get_current_transport(lVar3);
    uVar4 = coverttostring();
    _printk(&DAT_00105658,"btfmcodec_dai_hw_params",uVar4);
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// btfmcodec_dai_prepare @ 00104570 size=644
// signature: undefined btfmcodec_dai_prepare(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 btfmcodec_dai_prepare(long param_1,undefined8 *param_2)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 uVar7;
  long *plVar8;
  undefined1 uVar9;
  int iVar10;
  undefined4 uVar11;
  long lVar12;
  ulong uVar13;
  undefined8 uVar14;
  long lVar15;
  long lVar16;
  undefined1 *puVar17;
  long lVar18;
  long *plVar19;
  undefined8 local_78;
  undefined1 local_70;
  long local_68;
  
  lVar15 = sp_el0;
  local_68 = *(long *)(lVar15 + 0x638);
  lVar16 = *(long *)(*(long *)(param_2[0xb] + 0x18) + 0x98);
  lVar15 = 0;
  if (*(long *)(lVar16 + 0x3d8) != 0) {
    lVar15 = *(long *)(*(long *)(lVar16 + 0x3d8) + 0x50);
  }
  uVar4 = *(undefined4 *)(param_2 + 9);
  uVar5 = *(undefined4 *)(param_1 + 0x3c);
  uVar6 = *(uint *)(param_2 + 1);
  puVar17 = *(undefined1 **)(*(long *)(lVar15 + 0x60) + 0x38);
  lVar15 = lVar16 + 0x390;
  _printk(&DAT_00106d58,"btfmcodec_dai_prepare",*param_2,uVar6,uVar4,uVar5);
  plVar1 = (long *)(lVar16 + 0x3e0);
  uVar7 = *puVar17;
  plVar19 = *(long **)(lVar16 + 0x3e0);
  while (plVar8 = plVar19, plVar8 != plVar1) {
    plVar19 = (long *)*plVar8;
    if (uVar6 == *(byte *)(plVar8 + -3)) {
      _printk(&DAT_00105cd9,"btfmcodec_check_and_cache_configs",uVar6);
      uVar13 = __list_del_entry_valid(plVar8);
      if ((uVar13 & 1) != 0) {
        lVar12 = *plVar8;
        plVar3 = (long *)plVar8[1];
        *(long **)(lVar12 + 8) = plVar3;
        *plVar3 = lVar12;
      }
      *plVar8 = -0x2152ffffffffff00;
      plVar8[1] = -0x2152fffffffffede;
    }
  }
  lVar12 = kmalloc_trace(_device_initialize,0xdc0,0x30);
  if (lVar12 == 0) {
    _printk(&DAT_001064a0,"btfmcodec_check_and_cache_configs");
    uVar11 = 0xfffffff4;
  }
  else {
    *(char *)(lVar12 + 8) = (char)uVar6;
    *(undefined4 *)(lVar12 + 0xc) = uVar4;
    uVar11 = bits_per_second;
    lVar2 = lVar12 + 0x20;
    *(undefined4 *)(lVar12 + 0x14) = uVar5;
    uVar9 = num_channels;
    *(undefined1 *)(lVar12 + 0x11) = uVar7;
    *(char *)(lVar12 + 0x10) = (char)uVar11;
    *(undefined1 *)(lVar12 + 0x18) = uVar9;
    lVar18 = *plVar1;
    uVar13 = __list_add_valid(lVar2,plVar1,lVar18);
    if ((uVar13 & 1) != 0) {
      *(long *)(lVar18 + 8) = lVar2;
      *(long *)(lVar12 + 0x20) = lVar18;
      *(long **)(lVar12 + 0x28) = plVar1;
      *plVar1 = lVar2;
    }
    _printk(&DAT_00106b2d,"btfmcodec_check_and_cache_configs",uVar6,uVar4,uVar5);
    uVar11 = 1;
  }
  iVar10 = btfmcodec_get_current_transport(lVar15);
  if ((iVar10 == 0) || (iVar10 = btfmcodec_get_current_transport(lVar15), iVar10 == 2)) {
    uVar11 = btfmcodec_hwep_prepare(lVar16,uVar4,uVar5,uVar6);
  }
  else {
    btfmcodec_get_current_transport(lVar15);
    uVar14 = coverttostring();
    _printk(&DAT_001063d5,"btfmcodec_dai_prepare",uVar14);
    local_70 = 2;
    local_78 = 0x158000008;
    btfmcodec_dev_enqueue_pkt(*(undefined8 *)(lVar16 + 0x3d0),&local_78,9);
  }
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11;
}



//------------------------------------------------------------
// btfmcodec_codec_probe @ 001047f8 size=500
// signature: undefined btfmcodec_codec_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 btfmcodec_codec_probe(long param_1)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  void *__dest;
  undefined *puVar4;
  long lVar5;
  code *pcVar6;
  ulong __n;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  
  lVar5 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  lVar7 = *(long *)(lVar5 + 0x3d8);
  lVar5 = lVar5 + 0x390;
  uVar2 = *(uint *)(lVar7 + 100);
  iVar3 = btfmcodec_get_current_transport(lVar5);
  if (iVar3 == 0) {
    if (*(undefined8 **)(lVar7 + 0x48) == (undefined8 *)0x0) {
      return 0;
    }
    pcVar6 = (code *)**(undefined8 **)(lVar7 + 0x48);
    if (pcVar6 == (code *)0x0) {
      return 0;
    }
    if (*(int *)(pcVar6 + -4) != -0x2fe24ac8) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x104868);
      (*pcVar6)();
    }
    (*pcVar6)(param_1);
    if (*(long *)(lVar7 + 0x58) == 0 || (int)uVar2 < 1) {
      return 0;
    }
    __n = (ulong)uVar2 * 0x50;
    __dest = (void *)__kmalloc(__n,0xdc0);
    if (__dest == (void *)0x0) {
      _printk(&DAT_00106c7d,"btfmcodec_codec_probe");
      return 0;
    }
    _printk(&DAT_00107177,"btfmcodec_codec_probe",(ulong)uVar2);
    memcpy(__dest,*(void **)(lVar7 + 0x58),__n);
    uVar9 = __n - 0x38;
    uVar8 = 0;
    do {
      if ((__n < uVar8 + 0x10) || (uVar9 + 0x28 < 8)) {
LAB_001049e8:
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(1,0x1049ec);
        (*pcVar6)();
      }
      _printk(&DAT_00106eec,"btfmcodec_codec_probe",*(undefined8 *)((long)__dest + uVar8 + 0x10));
      if ((__n < uVar8 + 0x30) ||
         (((0xfffffffffffffff7 < uVar9 ||
           (*(code **)((long)__dest + uVar8 + 0x30) = btfm_codec_get_mixer_control,
           __n < uVar8 + 0x38)) || (uVar9 < 8)))) goto LAB_001049e8;
      uVar9 = uVar9 - 0x50;
      uVar1 = uVar8 + 0x50;
      *(code **)((long)__dest + uVar8 + 0x38) = btfmcodec_put_mixer_control;
      uVar8 = uVar1;
    } while (__n != uVar1);
    snd_soc_add_component_controls(param_1,__dest,uVar2);
    puVar4 = &DAT_00105d0b;
  }
  else {
    btfmcodec_get_current_transport(lVar5);
    param_1 = coverttostring();
    puVar4 = &DAT_001056ed;
  }
  _printk(puVar4,"btfmcodec_codec_probe",param_1);
  return 0;
}



//------------------------------------------------------------
// btfmcodec_codec_remove @ 001049f0 size=160
// signature: undefined btfmcodec_codec_remove(void)
// callers: []
//------------------------------------------------------------

void btfmcodec_codec_remove(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  code *pcVar5;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  lVar4 = lVar3 + 0x390;
  lVar3 = *(long *)(lVar3 + 0x3d8);
  iVar1 = btfmcodec_get_current_transport(lVar4);
  if (iVar1 == 0) {
    lVar4 = *(long *)(lVar3 + 0x48);
    if ((lVar4 != 0) && (pcVar5 = *(code **)(lVar4 + 8), pcVar5 != (code *)0x0)) {
      if (*(int *)(pcVar5 + -4) != 0x16879923) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x104a50);
        (*pcVar5)();
      }
      (*pcVar5)(param_1);
    }
  }
  else {
    btfmcodec_get_current_transport(lVar4);
    uVar2 = coverttostring();
    _printk(&DAT_001056ed,"btfmcodec_codec_remove",uVar2);
  }
  return;
}



//------------------------------------------------------------
// btfmcodec_codec_read @ 00104a94 size=172
// signature: undefined btfmcodec_codec_read(void)
// callers: []
//------------------------------------------------------------

undefined8 btfmcodec_codec_read(long param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  code *pcVar5;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  lVar4 = lVar3 + 0x390;
  lVar3 = *(long *)(lVar3 + 0x3d8);
  iVar1 = btfmcodec_get_current_transport(lVar4);
  if (iVar1 == 0) {
    lVar4 = *(long *)(lVar3 + 0x48);
    if ((lVar4 != 0) && (pcVar5 = *(code **)(lVar4 + 0x10), pcVar5 != (code *)0x0)) {
      if (*(int *)(pcVar5 + -4) != -0x446bac11) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x104afc);
        (*pcVar5)();
      }
      uVar2 = (*pcVar5)(param_1,param_2);
      return uVar2;
    }
  }
  else {
    btfmcodec_get_current_transport(lVar4);
    uVar2 = coverttostring();
    _printk(&DAT_001056ed,"btfmcodec_codec_read",uVar2);
  }
  return 0;
}



//------------------------------------------------------------
// btfmcodec_codec_write @ 00104b44 size=192
// signature: undefined btfmcodec_codec_write(void)
// callers: []
//------------------------------------------------------------

undefined8 btfmcodec_codec_write(long param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  lVar5 = lVar4 + 0x390;
  lVar4 = *(long *)(lVar4 + 0x3d8);
  iVar2 = btfmcodec_get_current_transport(lVar5);
  if (iVar2 == 0) {
    lVar5 = *(long *)(lVar4 + 0x48);
    if ((lVar5 != 0) && (*(long *)(lVar5 + 8) != 0)) {
      if (*(int *)(*(code **)(lVar5 + 0x18) + -4) != 0xa27b8ea) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104bbc);
        (*pcVar1)();
      }
      uVar3 = (**(code **)(lVar5 + 0x18))(param_1,param_2,param_3);
      return uVar3;
    }
  }
  else {
    btfmcodec_get_current_transport(lVar5);
    uVar3 = coverttostring();
    _printk(&DAT_001056ed,"btfmcodec_codec_write",uVar3);
  }
  return 0;
}



//------------------------------------------------------------
// btfm_codec_get_mixer_control @ 00104c08 size=280
// signature: undefined btfm_codec_get_mixer_control(void)
// callers: []
//------------------------------------------------------------

void btfm_codec_get_mixer_control(long param_1,undefined8 param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_68 = *(undefined8 *)(param_1 + 0x30);
  uStack_60 = *(undefined8 *)(param_1 + 0x38);
  local_58 = *(undefined8 *)(param_1 + 0x40);
  uStack_50 = *(undefined8 *)(param_1 + 0x48);
  lVar4 = *(long *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x3d8);
  local_78 = *(undefined8 *)(param_1 + 0x20);
  uStack_70 = *(undefined8 *)(param_1 + 0x28);
  uVar1 = *(uint *)(lVar4 + 100);
  if ((int)uVar1 < 1) {
    uVar5 = 0;
  }
  else {
    uVar5 = 0;
    puVar6 = (undefined8 *)(*(long *)(lVar4 + 0x58) + 0x30);
    do {
      iVar3 = strncmp((char *)&local_78,(char *)puVar6[-4],0x40);
      if (iVar3 == 0) {
        if (*(int *)((code *)*puVar6 + -4) != -0x697f7228) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x104ce0);
          (*pcVar2)();
        }
        (*(code *)*puVar6)(param_1,param_2);
        goto LAB_00104ce4;
      }
      uVar5 = uVar5 + 1;
      puVar6 = puVar6 + 10;
    } while (uVar1 != uVar5);
    uVar5 = (ulong)uVar1;
  }
LAB_00104ce4:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1 != (uint)uVar5);
  }
  return;
}



//------------------------------------------------------------
// btfmcodec_put_mixer_control @ 00104d24 size=280
// signature: undefined btfmcodec_put_mixer_control(void)
// callers: []
//------------------------------------------------------------

void btfmcodec_put_mixer_control(long param_1,undefined8 param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_68 = *(undefined8 *)(param_1 + 0x30);
  uStack_60 = *(undefined8 *)(param_1 + 0x38);
  local_58 = *(undefined8 *)(param_1 + 0x40);
  uStack_50 = *(undefined8 *)(param_1 + 0x48);
  lVar4 = *(long *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x3d8);
  local_78 = *(undefined8 *)(param_1 + 0x20);
  uStack_70 = *(undefined8 *)(param_1 + 0x28);
  uVar1 = *(uint *)(lVar4 + 100);
  if ((int)uVar1 < 1) {
    uVar5 = 0;
  }
  else {
    uVar5 = 0;
    puVar6 = (undefined8 *)(*(long *)(lVar4 + 0x58) + 0x38);
    do {
      iVar3 = strncmp((char *)&local_78,(char *)puVar6[-5],0x40);
      if (iVar3 == 0) {
        if (*(int *)((code *)*puVar6 + -4) != -0x697f7228) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x104dfc);
          (*pcVar2)();
        }
        (*(code *)*puVar6)(param_1,param_2);
        goto LAB_00104e00;
      }
      uVar5 = uVar5 + 1;
      puVar6 = puVar6 + 10;
    } while (uVar1 != uVar5);
    uVar5 = (ulong)uVar1;
  }
LAB_00104e00:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1 != (uint)uVar5);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00104e88 size=1316
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong init_module(void)

{
  long lVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  undefined4 uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  undefined8 *puVar11;
  long lVar12;
  
  puVar2 = &DAT_00105f84;
  if (log_lvl < 8) {
    puVar2 = &DAT_001066f3;
  }
  _printk(puVar2,"btfmcodec_init");
  btfmcodec = kmalloc_trace(_device_create_file,0xdc0,0x440);
  if (btfmcodec == 0) {
    _printk(&DAT_001064a0,"btfmcodec_init");
    uVar10 = 0xfffffff4;
  }
  else {
    __mutex_init(btfmcodec + 0x410,"&btfmcodec->hwep_drv_lock",&btfmcodec_init___key);
    lVar9 = btfmcodec + 0x390;
    puVar2 = &DAT_00106817;
    if (log_lvl < 8) {
      puVar2 = &DAT_00105970;
    }
    *(undefined8 *)(btfmcodec + 0x3c4) = 0;
    _printk(puVar2,"btfmcodec_init");
    lVar8 = kmalloc_trace(_device_add,0xdc0,0x2d8);
    if (lVar8 == 0) {
      _printk(&DAT_001064a0,"btfmcodec_init");
      uVar10 = 0xfffffff4;
    }
    else {
      puVar2 = &DAT_00106ca6;
      if (log_lvl < 8) {
        puVar2 = &DAT_00105d68;
      }
      _printk(puVar2,"btfmcodec_init");
      uVar6 = alloc_chrdev_region(&dev_major,0,0,"btfmcodec");
      if ((int)uVar6 < 0) {
        uVar10 = (ulong)uVar6;
        _printk(&DAT_00106d97,"btfmcodec_init");
      }
      else {
        puVar2 = &DAT_0010604a;
        if (log_lvl < 8) {
          puVar2 = &DAT_00107110;
        }
        _printk(puVar2,"btfmcodec_init");
        uVar10 = __class_create(&__this_module,"btfmcodec",&btfmcodec_init___key_25);
        dev_class = uVar10;
        if (uVar10 < 0xfffffffffffff001) {
          uVar7 = idr_alloc(dev_minor,btfmcodec,1,0,0xcc0);
          lVar4 = btfmcodec;
          *(undefined4 *)(lVar8 + 0xc0) = uVar7;
          *(undefined ***)(lVar4 + 0x88) = &driver;
          *(long *)(lVar4 + 0x3d0) = lVar8;
          *(undefined4 *)(lVar8 + 0x88) = 1;
          __mutex_init(lVar8 + 0x90,"&btfmcodec_dev->lock",&btfmcodec_init___key_28);
          *(undefined1 *)(lVar8 + 0xd1) = 0;
          uVar3 = CONCAT53(s_btfmcodec_dev_00105d8b._8_5_,s_btfmcodec_dev_00105d8b._5_3_);
          puVar11 = (undefined8 *)(lVar8 + 0xc4);
          *puVar11 = CONCAT35(s_btfmcodec_dev_00105d8b._5_3_,s_btfmcodec_dev_00105d8b._0_5_);
          *(undefined8 *)(lVar8 + 0xc9) = uVar3;
          device_initialize(lVar4);
          uVar6 = dev_major;
          *(ulong *)(lVar4 + 0x318) = dev_class;
          lVar1 = btfmcodec;
          *(uint *)(lVar4 + 0x2f8) = uVar6 & 0xfff00000 | *(uint *)(lVar8 + 0xc0);
          *(long *)(lVar4 + 0x98) = lVar1;
          cdev_init(lVar8,&btfmcodec_fops);
          lVar1 = btfmcodec;
          *(undefined1 **)(lVar8 + 0x60) = &__this_module;
          *(long *)(lVar8 + 0x2d0) = lVar1;
          dev_set_name(lVar4,puVar11,*(undefined4 *)(lVar8 + 0xc0));
          uVar6 = cdev_add(lVar8,*(undefined4 *)(lVar4 + 0x2f8),1);
          if (uVar6 == 0) {
            *(undefined8 *)(lVar4 + 0x328) = 0;
            uVar6 = device_add(lVar4);
            if (uVar6 == 0) {
              _printk(&DAT_00106f1c,"btfmcodec_init",puVar11);
              uVar6 = device_create_file(lVar4,&dev_attr_btfmcodec_attributes);
              if (uVar6 == 0) {
                puVar2 = &DAT_00106dc9;
                if (log_lvl < 8) {
                  puVar2 = &DAT_001064c1;
                }
                _printk(puVar2,"btfmcodec_init",puVar11,dev_major,*(undefined4 *)(lVar8 + 0xc0));
                *(long *)(lVar8 + 0x110) = lVar8 + 0x110;
                *(long *)(lVar8 + 0x118) = lVar8 + 0x110;
                *(undefined8 *)(lVar8 + 0x120) = 0;
                __mutex_init(lVar8 + 0x90,"&btfmcodec_dev->lock",&btfmcodec_init___key_37);
                *(undefined8 *)(lVar8 + 0x128) = 0xfffffffe0;
                *(long *)(lVar8 + 0x130) = lVar8 + 0x130;
                *(long *)(lVar8 + 0x138) = lVar8 + 0x130;
                *(code **)(lVar8 + 0x140) = btfmcodec_dev_rxwork;
                __init_waitqueue_head
                          (lVar8 + 0x1e8,"&btfmcodec_dev->readq",&btfmcodec_init___key_38);
                lVar5 = btfmcodec;
                lVar12 = 0;
                lVar1 = btfmcodec + 0x3e0;
                *(undefined4 *)(lVar8 + 0x200) = 0;
                *(undefined8 *)(lVar8 + 0x218) = 0;
                *(long *)(lVar8 + 0x208) = lVar8 + 0x208;
                *(long *)(lVar8 + 0x210) = lVar8 + 0x208;
                *(long *)(lVar5 + 0x3e0) = lVar1;
                *(long *)(lVar5 + 1000) = lVar1;
                do {
                  __init_waitqueue_head
                            (lVar8 + 0x220 + lVar12,"&btfmcodec_dev->rsp_wait_q[i]",
                             &btfmcodec_init___key_40);
                  lVar12 = lVar12 + 0x18;
                } while (lVar12 != 0xa8);
                __mutex_init(lVar9,"&states->state_machine_lock",&btfmcodec_init___key_42);
                lVar9 = alloc_workqueue("btfmcodec_wq",0xa0002,1);
                *(long *)(lVar8 + 0x108) = lVar9;
                if (lVar9 != 0) {
                  uVar10 = 0;
                  goto LAB_00105368;
                }
                _printk(&DAT_00106833,"btfmcodec_init");
                uVar10 = 0xfffffff4;
              }
              else {
                uVar10 = (ulong)uVar6;
                _printk(&DAT_001065e0,"btfmcodec_init",puVar11);
              }
            }
            else {
              uVar10 = (ulong)uVar6;
              _printk(&DAT_00106cc9,"btfmcodec_init",uVar10);
            }
            put_device(lVar4);
          }
          else {
            uVar10 = (ulong)uVar6;
            _printk(&DAT_001062fa,"btfmcodec_init",uVar10);
          }
          idr_remove(dev_minor,(long)*(int *)(lVar8 + 0xc0));
          class_destroy(dev_class);
        }
        else {
          _printk(&DAT_0010598c,"btfmcodec_init",uVar10 & 0xffffffff);
        }
        unregister_chrdev_region(dev_major >> 0x14,0);
      }
      kfree(lVar8);
    }
    kfree(btfmcodec);
  }
LAB_00105368:
  return uVar10 & 0xffffffff;
}



//------------------------------------------------------------
// cleanup_module @ 001053b0 size=292
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  undefined *puVar1;
  long lVar2;
  
  puVar1 = &DAT_0010621e;
  if (log_lvl < 8) {
    puVar1 = &DAT_00106766;
  }
  _printk(puVar1,"btfmcodec_deinit","btfmcodec_deinit");
  lVar2 = btfmcodec;
  if (btfmcodec == 0) {
    puVar1 = &DAT_001069b3;
  }
  else {
    device_remove_file(btfmcodec,&dev_attr_btfmcodec_attributes);
    put_device(lVar2);
    lVar2 = *(long *)(btfmcodec + 0x3d0);
    if (lVar2 != 0) {
      skb_queue_purge(lVar2 + 0x110);
      idr_remove(dev_minor,(long)*(int *)(lVar2 + 0xc0));
      class_destroy(dev_class);
      unregister_chrdev_region(dev_major >> 0x14,0);
      kfree(lVar2);
      goto LAB_0010548c;
    }
    puVar1 = &DAT_001068b3;
  }
  _printk(puVar1,"btfmcodec_deinit","btfmcodec_deinit");
LAB_0010548c:
  kfree(btfmcodec);
  puVar1 = &DAT_0010678f;
  if (log_lvl < 8) {
    puVar1 = &DAT_00107072;
  }
  _printk(puVar1,"btfmcodec_deinit","btfmcodec_deinit");
  return;
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00109000 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [btfmcodec_dev_enqueue_pkt, btfmcodec_dev_read, btfmcodec_dev_poll, btfmcodec_dev_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_skb @ 00109008 size=1
// signature: undefined __alloc_skb(void)
// callers: [btfmcodec_dev_enqueue_pkt, btfmcodec_dev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_put @ 00109010 size=1
// signature: undefined skb_put(void)
// callers: [btfmcodec_dev_enqueue_pkt, btfmcodec_dev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00109018 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [btfmcodec_dev_enqueue_pkt, btfmcodec_dev_write, btfmcodec_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_queue_tail @ 00109020 size=1
// signature: undefined skb_queue_tail(void)
// callers: [btfmcodec_dev_enqueue_pkt, btfmcodec_dev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_queue_tail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 00109028 size=1
// signature: undefined __wake_up(void)
// callers: [btfmcodec_wq_hwep_shutdown, btfmcodec_wq_hwep_configure, btfmcodec_dev_enqueue_pkt, btfmcodec_dev_rxwork, btfmcodec_dev_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00109030 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [btfmcodec_dev_enqueue_pkt, btfmcodec_dev_read, btfmcodec_dev_poll, btfmcodec_dev_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00109038 size=1
// signature: undefined _printk(void)
// callers: [btfmcodec_unregister_hw_ep, btfmcodec_wait_for_bearer_ind, btfmcodec_prepare_bearer, btfmcodec_set_current_state, init_module, btfmcodec_initiate_hwep_configuration, btfmcodec_codec_write, btfmcodec_initiate_hwep_shutdown, btfmcodec_configure_hwep, btfmcodec_dai_shutdown, btfmcodec_register_hw_ep, btfmcodec_dev_open, btfmcodec_wq_prepare_bearer, btfmcodec_ioctl, btfmcodec_wq_hwep_shutdown, btfmcodec_dai_hw_params, btfmcodec_hwep_prepare, btfmcodec_configure_dma, btfmcodec_dev_poll, btfmcodec_dev_write, btfmcodec_dev_rxwork, btfmcodec_codec_read, cleanup_module, btfmcodec_codec_probe, btfmcodec_adsp_ssr_notify, btfmcodec_move_to_next_state, btfm_register_codec, btfmcodec_dai_prepare, btfmcodec_wq_hwep_configure, btfmcodec_dai_set_channel_map, btfmcodec_dev_enqueue_pkt, btfmcodec_revert_current_state, btfmcodec_codec_remove, btfmcodec_configure_master, btfmcodec_dev_read, btfmcodec_hwep_shutdown, btfmcodec_dev_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00109048 size=1
// signature: undefined kmalloc_trace(void)
// callers: [btfmcodec_dai_prepare, init_module, btfmcodec_register_hw_ep]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00109050 size=1
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
// alloc_chrdev_region @ 00109058 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 00109060 size=1
// signature: undefined __class_create(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_alloc @ 00109068 size=1
// signature: undefined idr_alloc(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_initialize @ 00109070 size=1
// signature: undefined device_initialize(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_initialize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 00109078 size=1
// signature: undefined cdev_init(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 00109080 size=1
// signature: undefined dev_set_name(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 00109088 size=1
// signature: undefined cdev_add(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_add @ 00109090 size=1
// signature: undefined device_add(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 00109098 size=1
// signature: undefined device_create_file(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 001090a0 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 001090a8 size=1
// signature: undefined alloc_workqueue(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 001090b0 size=1
// signature: undefined put_device(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_remove @ 001090b8 size=1
// signature: undefined idr_remove(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 001090c0 size=1
// signature: undefined class_destroy(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 001090c8 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001090d0 size=1
// signature: undefined kfree(void)
// callers: [btfmcodec_unregister_hw_ep, btfmcodec_dev_write, cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_remove_file @ 001090d8 size=1
// signature: undefined device_remove_file(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_remove_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_queue_purge @ 001090e0 size=1
// signature: undefined skb_queue_purge(void)
// callers: [cleanup_module, btfmcodec_dev_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_queue_purge(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_dequeue @ 001090e8 size=1
// signature: undefined skb_dequeue(void)
// callers: [btfmcodec_dev_rxwork, btfmcodec_dev_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_dequeue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_skb_reason @ 001090f0 size=1
// signature: undefined kfree_skb_reason(void)
// callers: [btfmcodec_dev_rxwork, btfmcodec_dev_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_skb_reason(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_pull @ 001090f8 size=1
// signature: undefined skb_pull(void)
// callers: [btfmcodec_dev_rxwork]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_pull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00109100 size=1
// signature: undefined queue_work_on(void)
// callers: [btfmcodec_dev_write, btfmcodec_dev_rxwork, btfmcodec_initiate_hwep_configuration, btfmcodec_initiate_hwep_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 00109108 size=1
// signature: undefined cancel_work_sync(void)
// callers: [btfmcodec_dev_rxwork, btfmcodec_dev_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00109110 size=1
// signature: undefined __check_object_size(void)
// callers: [btfmcodec_dev_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 00109128 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [btfmcodec_dev_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00109130 size=1
// signature: undefined init_wait_entry(void)
// callers: [btfmcodec_wait_for_bearer_ind, btfmcodec_configure_master, btfmcodec_initiate_hwep_configuration, btfmcodec_configure_dma, btfmcodec_initiate_hwep_shutdown, btfmcodec_dev_read, btfmcodec_hwep_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00109138 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [btfmcodec_wait_for_bearer_ind, btfmcodec_configure_master, btfmcodec_initiate_hwep_configuration, btfmcodec_configure_dma, btfmcodec_initiate_hwep_shutdown, btfmcodec_dev_read, btfmcodec_hwep_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 00109140 size=1
// signature: undefined schedule(void)
// callers: [btfmcodec_dev_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 00109148 size=1
// signature: undefined finish_wait(void)
// callers: [btfmcodec_wait_for_bearer_ind, btfmcodec_configure_master, btfmcodec_initiate_hwep_configuration, btfmcodec_configure_dma, btfmcodec_initiate_hwep_shutdown, btfmcodec_dev_read, btfmcodec_hwep_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00109150 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [btfmcodec_attributes_store, btfmcodec_wait_for_bearer_ind, btfm_codec_get_mixer_control, btfmcodec_frame_transport_switch_ind_pkt, btfmcodec_prepare_bearer, btfmcodec_adsp_ssr_notify, btfmcodec_initiate_hwep_configuration, btfmcodec_initiate_hwep_shutdown, btfmcodec_configure_hwep, btfmcodec_put_mixer_control, btfm_register_codec, btfmcodec_dai_prepare, btfmcodec_frame_prepare_bearer_rsp_pkt, btfmcodec_configure_master, btfmcodec_configure_dma, btfmcodec_dev_read, btfmcodec_hwep_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock_interruptible @ 00109160 size=1
// signature: undefined mutex_lock_interruptible(void)
// callers: [btfmcodec_dev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock_interruptible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memdup_user @ 00109168 size=1
// signature: undefined memdup_user(void)
// callers: [btfmcodec_dev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void memdup_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00109178 size=1
// signature: undefined mutex_unlock(void)
// callers: [btfmcodec_unregister_hw_ep, btfmcodec_attributes_store, btfmcodec_ioctl, btfmcodec_dev_write, btfmcodec_revert_current_state, btfmcodec_prepare_bearer, btfmcodec_set_current_state, btfmcodec_move_to_next_state, btfmcodec_configure_hwep, btfmcodec_register_hw_ep, btfmcodec_dev_poll, btfmcodec_get_current_transport]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00109180 size=1
// signature: undefined mutex_lock(void)
// callers: [btfmcodec_unregister_hw_ep, btfmcodec_attributes_store, btfmcodec_ioctl, btfmcodec_revert_current_state, btfmcodec_prepare_bearer, btfmcodec_set_current_state, btfmcodec_move_to_next_state, btfmcodec_configure_hwep, btfmcodec_register_hw_ep, btfmcodec_dev_poll, btfmcodec_get_current_transport]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00109188 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [btfm_register_codec, btfmcodec_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 00109190 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [btfmcodec_dev_open, btfmcodec_dev_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoll @ 00109198 size=1
// signature: undefined kstrtoll(void)
// callers: [btfmcodec_attributes_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoll(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 001091a0 size=1
// signature: undefined schedule_timeout(void)
// callers: [btfmcodec_wait_for_bearer_ind, btfmcodec_configure_master, btfmcodec_initiate_hwep_configuration, btfmcodec_configure_dma, btfmcodec_initiate_hwep_shutdown, btfmcodec_hwep_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// flush_work @ 001091a8 size=1
// signature: undefined flush_work(void)
// callers: [btfmcodec_initiate_hwep_configuration, btfmcodec_initiate_hwep_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void flush_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncmp @ 001091b0 size=1
// signature: int strncmp(char * __s1, char * __s2, size_t __n)
// callers: [btfmcodec_unregister_hw_ep, btfm_codec_get_mixer_control, btfmcodec_put_mixer_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_register_ssr_notifier @ 001091b8 size=1
// signature: undefined qcom_register_ssr_notifier(void)
// callers: [btfm_register_codec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_register_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001091c0 size=1
// signature: undefined __kmalloc(void)
// callers: [btfm_register_codec, btfmcodec_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_register_component @ 001091c8 size=1
// signature: undefined snd_soc_register_component(void)
// callers: [btfm_register_codec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_register_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_unregister_component @ 001091d0 size=1
// signature: undefined snd_soc_unregister_component(void)
// callers: [btfm_unregister_codec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_unregister_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001091d8 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [btfmcodec_dai_prepare, btfmcodec_dai_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_pcm_format_width @ 001091e0 size=1
// signature: undefined snd_pcm_format_width(void)
// callers: [btfmcodec_dai_hw_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_pcm_format_width(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001091e8 size=1
// signature: undefined __list_add_valid(void)
// callers: [btfmcodec_dai_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_add_component_controls @ 001091f0 size=1
// signature: undefined snd_soc_add_component_controls(void)
// callers: [btfmcodec_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_add_component_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



