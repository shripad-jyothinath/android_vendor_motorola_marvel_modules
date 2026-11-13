// Decompiled by Ghidra 12.2
// Program: audio_pkt_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// audio_pkt_open @ 001003c4 size=104
// signature: undefined audio_pkt_open(void)
// callers: []
//------------------------------------------------------------

undefined8 audio_pkt_open(undefined8 param_1,long param_2)

{
  if ((audio_pkt_debug_mask & 1) != 0) {
    ipc_log_string(0,"[%s]: %s: for %s \n","audio_pkt_open","audio_pkt_open",
                   *(long *)(ap_priv + 0x10) + 0x10c);
  }
  *(long *)(param_2 + 0xd8) = ap_priv;
  return 0;
}



//------------------------------------------------------------
// audio_pkt_release @ 00100430 size=296
// signature: undefined audio_pkt_release(void)
// callers: []
//------------------------------------------------------------

undefined8 audio_pkt_release(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  long lVar6;
  
  lVar6 = *(long *)(*(long *)(param_2 + 0xd8) + 0x10);
  if (lVar6 == 0) {
    iVar1 = ___ratelimit(&audio_pkt_release__rs,"audio_pkt_release");
    if (iVar1 != 0) {
      _printk(&DAT_00101cd1,"audio_pkt_release");
    }
    ipc_log_string(0,"[%s]: invalid device handle\n","audio_pkt_release");
    uVar2 = 0xffffffea;
  }
  else {
    if ((audio_pkt_debug_mask & 1) != 0) {
      ipc_log_string(0,"[%s]: %s: for %s \n","audio_pkt_release","audio_pkt_release",lVar6 + 0x10c);
    }
    uVar2 = _raw_spin_lock_irqsave(lVar6 + 0xc0);
    puVar5 = (undefined8 *)(lVar6 + 200);
    puVar4 = (undefined8 *)*puVar5;
    while (puVar4 != puVar5) {
      uVar3 = skb_dequeue(puVar5);
      kfree_skb_reason(uVar3,1);
      puVar4 = (undefined8 *)*puVar5;
    }
    __wake_up(lVar6 + 0xe0,1,1,0);
    _raw_spin_unlock_irqrestore(lVar6 + 0xc0,uVar2);
    *(undefined8 *)(param_2 + 0xd8) = 0;
    spf_core_apm_close_all();
    msm_audio_ion_crash_handler();
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// audio_pkt_read @ 0010055c size=860
// signature: undefined audio_pkt_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void audio_pkt_read(long param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  undefined8 *puVar8;
  ulong uVar9;
  long *plVar10;
  long lVar11;
  long lVar12;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar11 = sp_el0;
  local_58 = *(long *)(lVar11 + 0x638);
  lVar11 = *(long *)(param_1 + 0xd8);
  lVar12 = *(long *)(lVar11 + 0x10);
  if (lVar12 == 0) {
    iVar3 = ___ratelimit(audio_pkt_read__rs,"audio_pkt_read");
    if (iVar3 != 0) {
      _printk(&DAT_00101cd1,"audio_pkt_read");
    }
    ipc_log_string(0,"[%s]: invalid device handle\n","audio_pkt_read");
    lVar11 = -0x16;
  }
  else {
    mutex_lock(lVar11 + 0x18);
    iVar3 = *(int *)(lVar11 + 0x48);
    mutex_unlock(lVar11 + 0x18);
    if (iVar3 == 1) {
      lVar11 = lVar12 + 0xc0;
      uVar4 = _raw_spin_lock_irqsave(lVar11);
      plVar10 = (long *)(lVar12 + 200);
      if ((long *)*plVar10 == plVar10) {
        _raw_spin_unlock_irqrestore(lVar11,uVar4);
        if ((*(byte *)(param_1 + 0x41) >> 3 & 1) != 0) {
          lVar11 = -0xb;
          goto LAB_00100820;
        }
        if ((long *)*plVar10 == plVar10) {
          local_68 = 0;
          uStack_60 = 0;
          local_78 = 0;
          uStack_70 = 0;
          local_80 = 0;
          init_wait_entry(&local_80,0);
          lVar6 = lVar12 + 0xe0;
          lVar5 = prepare_to_wait_event(lVar6,&local_80,1);
          plVar7 = *(long **)(lVar12 + 200);
          while (plVar7 == plVar10) {
            if (lVar5 != 0) {
              if ((int)lVar5 == 0) goto LAB_00100668;
              lVar11 = -0x200;
              goto LAB_00100820;
            }
            schedule();
            lVar5 = prepare_to_wait_event(lVar6,&local_80,1);
            plVar7 = (long *)*plVar10;
          }
          finish_wait(lVar6,&local_80);
        }
LAB_00100668:
        uVar4 = _raw_spin_lock_irqsave(lVar11);
      }
      lVar12 = skb_dequeue(plVar10);
      _raw_spin_unlock_irqrestore(lVar11,uVar4);
      if (lVar12 == 0) {
        lVar11 = -0xe;
      }
      else {
        uVar9 = (ulong)*(uint *)(lVar12 + 0x70);
        if (param_3 <= *(uint *)(lVar12 + 0x70)) {
          uVar9 = param_3;
        }
        if (uVar9 >> 0x1f != 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10089c);
          (*pcVar2)();
        }
        uVar4 = *(undefined8 *)(lVar12 + 0xe0);
        lVar11 = (long)(int)uVar9;
        __check_object_size(uVar4,lVar11,1);
        puVar8 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
           (uVar9 = param_2, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
          uVar9 = param_2 & (long)(param_2 << 8) >> 8;
        }
        lVar6 = lVar11;
        if (uVar9 <= 0x8000000000U - lVar11) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar9 = daif;
            if ((uVar9 & 0x80) == 0) {
              uVar1 = daif;
              daif = uVar1 | 0xc0;
            }
            puVar8 = (undefined8 *)puVar8[1];
            uVar1 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar8 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar8;
            InstructionSynchronizationBarrier();
            daif = uVar9;
          }
          lVar6 = __arch_copy_to_user(puVar8,param_2 & 0xff7fffffffffffff,uVar4,lVar11);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar9 = daif;
            if ((uVar9 & 0x80) == 0) {
              uVar1 = daif;
              daif = uVar1 | 0xc0;
            }
            uVar1 = ttbr1_el1;
            ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar1 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar9;
          }
        }
        kfree_skb_reason(lVar12,1);
        if (lVar6 != 0) {
          lVar11 = -0xe;
        }
      }
    }
    else {
      iVar3 = ___ratelimit(audio_pkt_read__rs_3,"audio_pkt_read");
      if (iVar3 != 0) {
        _printk(&DAT_00101e0a,"audio_pkt_read");
      }
      ipc_log_string(0,"[%s]: dev is in reset\n","audio_pkt_read");
      lVar11 = -0x66;
    }
  }
LAB_00100820:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar11);
  }
  return;
}



//------------------------------------------------------------
// audpkt_chk_and_update_physical_addr @ 001008e0 size=272
// signature: undefined audpkt_chk_and_update_physical_addr(void)
// callers: [audio_pkt_write]
//------------------------------------------------------------

int audpkt_chk_and_update_physical_addr(long param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  if ((*(byte *)(param_1 + 0x1c) >> 2 & 1) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = msm_audio_get_phy_addr(*(undefined4 *)(param_1 + 0x20),&local_38,&uStack_30);
    if (iVar2 < 0) {
      iVar3 = ___ratelimit(audpkt_chk_and_update_physical_addr__rs,
                           "audpkt_chk_and_update_physical_addr");
      if (iVar3 != 0) {
        _printk(&DAT_00101e7b,"audpkt_chk_and_update_physical_addr",
                "audpkt_chk_and_update_physical_addr",iVar2);
      }
      ipc_log_string(0,"[%s]: %s Get phy. address failed, ret %d\n",
                     "audpkt_chk_and_update_physical_addr","audpkt_chk_and_update_physical_addr",
                     iVar2);
    }
    else {
      if ((audio_pkt_debug_mask & 1) != 0) {
        ipc_log_string(0,"[%s]: %s physical address %pK","audpkt_chk_and_update_physical_addr",
                       "audpkt_chk_and_update_physical_addr",local_38);
      }
      *(undefined8 *)(param_1 + 0x20) = local_38;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// audio_pkt_write @ 001009f4 size=876
// signature: undefined audio_pkt_write(void)
// callers: []
//------------------------------------------------------------

uint * audio_pkt_write(long param_1,long param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  char *pcVar4;
  uint *puVar5;
  undefined8 *puVar6;
  long lVar7;
  
  if (((param_1 == 0) || (param_2 == 0)) ||
     (puVar6 = *(undefined8 **)(param_1 + 0xd8), puVar6 == (undefined8 *)0x0)) {
    iVar1 = ___ratelimit(audio_pkt_write__rs,"audio_pkt_write");
    if (iVar1 != 0) {
      _printk(&DAT_00101f83,"audio_pkt_write");
    }
    pcVar4 = "[%s]: invalid parameters\n";
LAB_00100aac:
    ipc_log_string(0,pcVar4,"audio_pkt_write");
    return (uint *)0xffffffffffffffea;
  }
  lVar7 = puVar6[2];
  if (lVar7 == 0) {
    iVar1 = ___ratelimit(audio_pkt_write__rs_11,"audio_pkt_write");
    if (iVar1 != 0) {
      _printk(&DAT_00101cd1,"audio_pkt_write");
    }
    pcVar4 = "[%s]: invalid device handle\n";
    goto LAB_00100aac;
  }
  mutex_lock(puVar6 + 3);
  iVar1 = *(int *)(puVar6 + 9);
  mutex_unlock(puVar6 + 3);
  if (iVar1 != 1) {
    iVar1 = ___ratelimit(audio_pkt_write__rs_12,"audio_pkt_write");
    if (iVar1 != 0) {
      _printk(&DAT_00101e0a,"audio_pkt_write");
    }
    ipc_log_string(0,"[%s]: dev is in reset\n","audio_pkt_write");
    return (uint *)0xffffffffffffff9a;
  }
  if (param_3 < (uint *)0x18) {
    iVar1 = ___ratelimit(audio_pkt_write__rs_13,"audio_pkt_write");
    if (iVar1 != 0) {
      _printk(&DAT_00101dce,"audio_pkt_write",param_3);
    }
    ipc_log_string(0,"[%s]: Invalid count %zu\n","audio_pkt_write",param_3);
    return (uint *)0xffffffffffffffea;
  }
  puVar3 = (uint *)memdup_user(param_2,param_3);
  if ((uint *)0xfffffffffffff000 < puVar3) {
    return puVar3;
  }
  if (((uint *)0x1000 < param_3) || (param_3 < (uint *)(ulong)(*puVar3 >> 8))) {
    puVar5 = (uint *)0xffffffffffffffea;
    goto LAB_00100b88;
  }
  if (puVar3[5] == 0x100100c) {
    if (param_3 < (uint *)0x2c) {
      iVar1 = ___ratelimit(audio_pkt_write__rs_16,"audio_pkt_write");
      if (iVar1 != 0) {
        _printk(&DAT_00101dce,"audio_pkt_write",param_3);
      }
      ipc_log_string(0,"[%s]: Invalid count %zu\n","audio_pkt_write",param_3);
      puVar5 = (uint *)0xffffffffffffffea;
      goto LAB_00100b88;
    }
    iVar1 = audpkt_chk_and_update_physical_addr(puVar3);
    if (iVar1 < 0) {
      iVar2 = ___ratelimit(audio_pkt_write__rs_17,"audio_pkt_write");
      if (iVar2 != 0) {
        _printk(&DAT_00101cf0,"audio_pkt_write",iVar1);
      }
      ipc_log_string(0,"[%s]: Update Physical Address Failed -%d\n","audio_pkt_write",iVar1);
      puVar5 = (uint *)(long)iVar1;
      goto LAB_00100b88;
    }
  }
  lVar7 = lVar7 + 0x90;
  iVar1 = mutex_lock_interruptible(lVar7);
  if (iVar1 == 0) {
    iVar2 = gpr_send_pkt(*puVar6,puVar3);
    iVar1 = iVar2;
    if (iVar2 < 0) {
      iVar1 = ___ratelimit(audio_pkt_write__rs_21,"audio_pkt_write");
      if (iVar1 != 0) {
        _printk(&DAT_00102168,"audio_pkt_write",iVar2);
      }
      ipc_log_string(0,"[%s]: APR Send Packet Failed ret -%d\n","audio_pkt_write",iVar2);
      iVar1 = -0x66;
      if (iVar2 != -0x68) {
        iVar1 = iVar2;
      }
    }
    mutex_unlock(lVar7);
    kfree(puVar3);
    if (iVar1 < 0) {
      return (uint *)(long)iVar1;
    }
    return param_3;
  }
  puVar5 = (uint *)0xfffffffffffffe00;
LAB_00100b88:
  kfree(puVar3);
  return puVar5;
}



//------------------------------------------------------------
// audio_pkt_platform_driver_probe @ 00100d64 size=988
// signature: undefined audio_pkt_platform_driver_probe(void)
// callers: []
//------------------------------------------------------------

ulong audio_pkt_platform_driver_probe(long param_1)

{
  long lVar1;
  byte bVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint uVar5;
  int iVar6;
  ulong *puVar7;
  ulong uVar8;
  ulong uVar9;
  ulong *puVar10;
  
  lVar1 = param_1 + 0x10;
  puVar7 = (ulong *)devm_kmalloc(lVar1,0x130,0xdc0);
  if (puVar7 == (ulong *)0x0) {
    uVar8 = 0xfffffff4;
  }
  else {
    uVar5 = alloc_chrdev_region(puVar7 + 0x24,0,1,"aud_pasthru_adsp");
    if ((int)uVar5 < 0) {
      uVar8 = (ulong)uVar5;
      iVar6 = ___ratelimit(audio_pkt_platform_driver_probe__rs,"audio_pkt_platform_driver_probe");
      if (iVar6 != 0) {
        _printk(&DAT_00101ca6,"audio_pkt_platform_driver_probe",uVar8);
      }
      ipc_log_string(0,"[%s]: alloc_chrdev_region failed ret:%d\n","audio_pkt_platform_driver_probe"
                     ,uVar8);
    }
    else {
      uVar8 = __class_create(&__this_module,"aud_pasthru_adsp",
                             &audio_pkt_platform_driver_probe___key);
      puVar7[0x25] = uVar8;
      if (uVar8 < 0xfffffffffffff001) {
        uVar8 = device_create(uVar8,0,(int)puVar7[0x24],0,"aud_pasthru_adsp");
        *puVar7 = uVar8;
        uVar4 = s_aud_pasthru_adsp_001020f0._8_8_;
        uVar3 = s_adsp_apps_001020e6._0_8_;
        if (uVar8 < 0xfffffffffffff001) {
          puVar10 = puVar7 + 0x1f;
          *puVar10 = s_aud_pasthru_adsp_001020f0._0_8_;
          puVar7[0x20] = uVar4;
          *(undefined1 *)(puVar7 + 0x21) = 0;
          *(undefined8 *)((long)puVar7 + 0x10c) = uVar3;
          *(undefined2 *)((long)puVar7 + 0x114) = 0x73;
          dev_set_name(uVar8,puVar10);
          __mutex_init(puVar7 + 0x12,"&audpkt_dev->lock",&audio_pkt_platform_driver_probe___key_35);
          *(undefined4 *)(puVar7 + 0x18) = 0;
          puVar7[0x19] = (ulong)(puVar7 + 0x19);
          puVar7[0x1a] = (ulong)(puVar7 + 0x19);
          puVar7[0x1b] = 0;
          __init_waitqueue_head
                    (puVar7 + 0x1c,"&audpkt_dev->readq",&audio_pkt_platform_driver_probe___key_37);
          cdev_init(puVar7 + 1,&audio_pkt_fops);
          puVar7[0xd] = (ulong)&__this_module;
          uVar5 = cdev_add(puVar7 + 1,(int)puVar7[0x24],1);
          if (uVar5 == 0) {
            ap_priv = devm_kmalloc(lVar1,0x50,0xdc0);
            if (ap_priv == 0) {
              uVar8 = 0xfffffff4;
            }
            else {
              uVar9 = __gpr_driver_register(&audio_pkt_driver,&__this_module);
              uVar8 = uVar9 & 0xffffffff;
              if (-1 < (int)uVar9) {
                __mutex_init(ap_priv + 0x18,"&ap_priv->lock",
                             &audio_pkt_plaform_driver_register_gpr___key);
                lVar1 = ap_priv;
                *(undefined4 *)(ap_priv + 0x48) = 0;
                bVar2 = audio_pkt_debug_mask;
                *(ulong **)(lVar1 + 0x10) = puVar7;
                *(ulong *)(lVar1 + 8) = *puVar7;
                *(long *)(param_1 + 0xa8) = lVar1;
                if ((bVar2 & 1) != 0) {
                  ipc_log_string(0,"[%s]: Audio Packet Port Driver Initialized\n",
                                 "audio_pkt_platform_driver_probe");
                }
                goto LAB_00100fd4;
              }
              _dev_err(lVar1,"%s: registering to gpr driver failed, err = %d\n",
                       "audio_pkt_plaform_driver_register_gpr",uVar8);
            }
            _dev_err(lVar1,"%s: Failed to register with gpr, err = %d\n",
                     "audio_pkt_platform_driver_probe",uVar8);
          }
          else {
            uVar8 = (ulong)uVar5;
            iVar6 = ___ratelimit(audio_pkt_platform_driver_probe__rs_39,
                                 "audio_pkt_platform_driver_probe");
            if (iVar6 != 0) {
              _printk(&DAT_00101f09,"audio_pkt_platform_driver_probe",puVar10,uVar8);
            }
            ipc_log_string(0,"[%s]: cdev_add failed for %s ret:%d\n",
                           "audio_pkt_platform_driver_probe",puVar10,uVar8);
          }
          device_destroy(puVar7[0x25],(int)puVar7[0x24]);
        }
        else {
          iVar6 = ___ratelimit(audio_pkt_platform_driver_probe__rs_31,
                               "audio_pkt_platform_driver_probe");
          if (iVar6 != 0) {
            _printk(&DAT_00101fc6,"audio_pkt_platform_driver_probe",*puVar7);
          }
          ipc_log_string(0,"[%s]: device_create failed ret:%ld\n","audio_pkt_platform_driver_probe",
                         *puVar7);
        }
        class_destroy(puVar7[0x25]);
      }
      else {
        iVar6 = ___ratelimit(audio_pkt_platform_driver_probe__rs_28,
                             "audio_pkt_platform_driver_probe");
        if (iVar6 != 0) {
          _printk(&DAT_00101d1c,"audio_pkt_platform_driver_probe",puVar7[0x25]);
        }
        ipc_log_string(0,"[%s]: class_create failed ret:%ld\n","audio_pkt_platform_driver_probe",
                       puVar7[0x25]);
      }
      unregister_chrdev_region((uint)puVar7[0x24] >> 0x14,1);
    }
  }
LAB_00100fd4:
  return uVar8 & 0xffffffff;
}



//------------------------------------------------------------
// audio_pkt_platform_driver_remove @ 00101144 size=384
// signature: undefined audio_pkt_platform_driver_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 audio_pkt_platform_driver_remove(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  long lVar6;
  long lVar7;
  
  lVar6 = *(long *)(*(long *)(param_1 + 0xa8) + 0x10);
  gpr_driver_unregister(&audio_pkt_driver);
  lVar7 = *(long *)(*(long *)(param_1 + 0xa8) + 0x10);
  if (lVar7 == 0) {
    iVar1 = ___ratelimit(audio_pkt_internal_release__rs,"audio_pkt_internal_release");
    if (iVar1 != 0) {
      _printk(&DAT_00101cd1,"audio_pkt_internal_release");
    }
    ipc_log_string(0,"[%s]: invalid device handle\n","audio_pkt_internal_release");
  }
  else {
    if ((audio_pkt_debug_mask & 1) != 0) {
      ipc_log_string(0,"[%s]: %s: for %s\n","audio_pkt_internal_release",
                     "audio_pkt_internal_release",lVar7 + 0x10c);
    }
    uVar2 = _raw_spin_lock_irqsave(lVar7 + 0xc0);
    puVar5 = (undefined8 *)(lVar7 + 200);
    puVar4 = (undefined8 *)*puVar5;
    while (puVar4 != puVar5) {
      uVar3 = skb_dequeue(puVar5);
      kfree_skb_reason(uVar3,1);
      puVar4 = (undefined8 *)*puVar5;
    }
    _raw_spin_unlock_irqrestore(lVar7 + 0xc0,uVar2);
    __wake_up(lVar7 + 0xe0,1,1,0);
  }
  if (lVar6 != 0) {
    cdev_del(lVar6 + 8);
    device_destroy(*(undefined8 *)(lVar6 + 0x128),*(undefined4 *)(lVar6 + 0x120));
    class_destroy(*(undefined8 *)(lVar6 + 0x128));
    unregister_chrdev_region(*(uint *)(lVar6 + 0x120) >> 0x14,1);
  }
  if ((audio_pkt_debug_mask & 1) != 0) {
    ipc_log_string(0,"[%s]: Audio Packet Port Driver Removed\n","audio_pkt_platform_driver_remove");
  }
  return 0;
}



//------------------------------------------------------------
// audio_pkt_poll @ 001012c8 size=256
// signature: undefined audio_pkt_poll(void)
// callers: []
//------------------------------------------------------------

undefined4 audio_pkt_poll(long param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  long lVar5;
  
  lVar5 = *(long *)(*(long *)(param_1 + 0xd8) + 0x10);
  if (lVar5 == 0) {
    iVar1 = ___ratelimit(audio_pkt_poll__rs,"audio_pkt_poll");
    if (iVar1 != 0) {
      _printk(&DAT_00101cd1,"audio_pkt_poll");
    }
    ipc_log_string(0,"[%s]: invalid device handle\n","audio_pkt_poll");
    uVar3 = 8;
  }
  else {
    if ((param_2 != (undefined8 *)0x0) &&
       (pcVar4 = (code *)*param_2, lVar5 != -0xe0 && pcVar4 != (code *)0x0)) {
      if (*(int *)(pcVar4 + -4) != 0x7db4acb9) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10131c);
        (*pcVar4)();
      }
      (*pcVar4)();
      DataMemoryBarrier(2,3);
    }
    mutex_lock(lVar5 + 0x90);
    uVar2 = _raw_spin_lock_irqsave(lVar5 + 0xc0);
    uVar3 = 0;
    if (*(long **)(lVar5 + 200) != (long *)(lVar5 + 200)) {
      uVar3 = 0x41;
    }
    _raw_spin_unlock_irqrestore(lVar5 + 0xc0,uVar2);
    mutex_unlock(lVar5 + 0x90);
  }
  return uVar3;
}



//------------------------------------------------------------
// audio_pkt_probe @ 001013cc size=128
// signature: undefined audio_pkt_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 audio_pkt_probe(long param_1)

{
  long *plVar1;
  long *plVar2;
  undefined8 uVar3;
  
  if (ap_priv == (long *)0x0) {
    _dev_err(param_1,"%s: Driver[%s] Probe Failed\n","audio_pkt_probe",param_1 + 0x398);
    uVar3 = 0xffffffea;
  }
  else {
    mutex_lock(ap_priv + 3);
    plVar2 = ap_priv;
    plVar1 = ap_priv + 3;
    *ap_priv = param_1;
    *(undefined4 *)(plVar2 + 9) = 1;
    mutex_unlock(plVar1);
    uVar3 = 0;
    *(long **)(param_1 + 0x98) = ap_priv;
  }
  return uVar3;
}



//------------------------------------------------------------
// audio_pkt_remove @ 00101450 size=124
// signature: undefined audio_pkt_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 audio_pkt_remove(long param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  if (ap_priv == (undefined8 *)0x0) {
    _dev_err(param_1,"%s: Driver[%s] Remove Failed\n","audio_pkt_remove",param_1 + 0x398);
    uVar3 = 0xffffffea;
  }
  else {
    mutex_lock(ap_priv + 3);
    puVar2 = ap_priv;
    puVar1 = ap_priv + 3;
    *ap_priv = 0;
    *(undefined4 *)(puVar2 + 9) = 2;
    mutex_unlock(puVar1);
    uVar3 = 0;
    *(undefined8 *)(param_1 + 0x98) = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// audio_pkt_srvc_callback @ 001014d0 size=240
// signature: undefined audio_pkt_srvc_callback(void)
// callers: []
//------------------------------------------------------------

undefined8 audio_pkt_srvc_callback(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  void *__dest;
  undefined8 uVar3;
  uint uVar4;
  long lVar5;
  
  lVar5 = *(long *)(*(long *)(param_1 + 0x98) + 0x10);
  uVar1 = *param_2;
  if ((audio_pkt_debug_mask & 1) == 0) {
    uVar4 = uVar1 >> 8 & 0xffff;
  }
  else {
    uVar4 = uVar1 >> 8 & 0xffff;
    ipc_log_string(0,"[%s]: %s: header %d packet %d \n","audio_pkt_srvc_callback",
                   "audio_pkt_srvc_callback",uVar1 >> 2 & 0x3c,uVar4);
  }
  lVar2 = __alloc_skb(uVar4,0xa20,0,0xffffffff);
  if (lVar2 == 0) {
    uVar3 = 0xfffffff4;
  }
  else {
    __dest = (void *)skb_put(lVar2,uVar4);
    memcpy(__dest,param_2,(ulong)uVar4);
    uVar3 = _raw_spin_lock_irqsave(lVar5 + 0xc0);
    skb_queue_tail(lVar5 + 200,lVar2);
    _raw_spin_unlock_irqrestore(lVar5 + 0xc0,uVar3);
    __wake_up(lVar5 + 0xe0,1,1,0);
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// init_module @ 00101608 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&audio_pkt_core_platform_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101638 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&audio_pkt_core_platform_driver);
  return;
}



//------------------------------------------------------------
// ipc_log_string @ 00104000 size=1
// signature: undefined ipc_log_string(void)
// callers: [audio_pkt_srvc_callback, audio_pkt_platform_driver_remove, audpkt_chk_and_update_physical_addr, audio_pkt_platform_driver_probe, audio_pkt_poll, audio_pkt_read, audio_pkt_open, audio_pkt_release, audio_pkt_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00104008 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [audio_pkt_srvc_callback, audio_pkt_platform_driver_remove, audio_pkt_poll, audio_pkt_read, audio_pkt_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_dequeue @ 00104010 size=1
// signature: undefined skb_dequeue(void)
// callers: [audio_pkt_platform_driver_remove, audio_pkt_read, audio_pkt_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_dequeue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_skb_reason @ 00104018 size=1
// signature: undefined kfree_skb_reason(void)
// callers: [audio_pkt_platform_driver_remove, audio_pkt_read, audio_pkt_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_skb_reason(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 00104020 size=1
// signature: undefined __wake_up(void)
// callers: [audio_pkt_srvc_callback, audio_pkt_platform_driver_remove, audio_pkt_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00104028 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [audio_pkt_srvc_callback, audio_pkt_platform_driver_remove, audio_pkt_poll, audio_pkt_read, audio_pkt_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// spf_core_apm_close_all @ 00104030 size=1
// signature: undefined spf_core_apm_close_all(void)
// callers: [audio_pkt_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void spf_core_apm_close_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_audio_ion_crash_handler @ 00104038 size=1
// signature: undefined msm_audio_ion_crash_handler(void)
// callers: [audio_pkt_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_audio_ion_crash_handler(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00104040 size=1
// signature: undefined ___ratelimit(void)
// callers: [audio_pkt_platform_driver_remove, audpkt_chk_and_update_physical_addr, audio_pkt_platform_driver_probe, audio_pkt_poll, audio_pkt_read, audio_pkt_release, audio_pkt_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104048 size=1
// signature: undefined _printk(void)
// callers: [audio_pkt_platform_driver_remove, audpkt_chk_and_update_physical_addr, audio_pkt_platform_driver_probe, audio_pkt_poll, audio_pkt_read, audio_pkt_release, audio_pkt_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00104050 size=1
// signature: undefined mutex_lock(void)
// callers: [audio_pkt_remove, audio_pkt_poll, audio_pkt_read, audio_pkt_probe, audio_pkt_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104058 size=1
// signature: undefined mutex_unlock(void)
// callers: [audio_pkt_remove, audio_pkt_poll, audio_pkt_read, audio_pkt_probe, audio_pkt_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00104060 size=1
// signature: undefined init_wait_entry(void)
// callers: [audio_pkt_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00104068 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [audio_pkt_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 00104070 size=1
// signature: undefined schedule(void)
// callers: [audio_pkt_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 00104078 size=1
// signature: undefined finish_wait(void)
// callers: [audio_pkt_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00104080 size=1
// signature: undefined __check_object_size(void)
// callers: [audio_pkt_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 00104098 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [audio_pkt_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001040a0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [audpkt_chk_and_update_physical_addr, audio_pkt_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_audio_get_phy_addr @ 001040b0 size=1
// signature: undefined msm_audio_get_phy_addr(void)
// callers: [audpkt_chk_and_update_physical_addr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_audio_get_phy_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memdup_user @ 001040b8 size=1
// signature: undefined memdup_user(void)
// callers: [audio_pkt_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void memdup_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001040c0 size=1
// signature: undefined kfree(void)
// callers: [audio_pkt_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock_interruptible @ 001040c8 size=1
// signature: undefined mutex_lock_interruptible(void)
// callers: [audio_pkt_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock_interruptible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpr_send_pkt @ 001040d0 size=1
// signature: undefined gpr_send_pkt(void)
// callers: [audio_pkt_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpr_send_pkt(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 001040d8 size=1
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
// platform_driver_unregister @ 001040e0 size=1
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
// devm_kmalloc @ 001040e8 size=1
// signature: undefined devm_kmalloc(void)
// callers: [audio_pkt_platform_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 001040f0 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [audio_pkt_platform_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 001040f8 size=1
// signature: undefined __class_create(void)
// callers: [audio_pkt_platform_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 00104100 size=1
// signature: undefined device_create(void)
// callers: [audio_pkt_platform_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 00104108 size=1
// signature: undefined dev_set_name(void)
// callers: [audio_pkt_platform_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00104110 size=1
// signature: undefined __mutex_init(void)
// callers: [audio_pkt_platform_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00104118 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [audio_pkt_platform_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 00104120 size=1
// signature: undefined cdev_init(void)
// callers: [audio_pkt_platform_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 00104128 size=1
// signature: undefined cdev_add(void)
// callers: [audio_pkt_platform_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 00104130 size=1
// signature: undefined device_destroy(void)
// callers: [audio_pkt_platform_driver_remove, audio_pkt_platform_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 00104138 size=1
// signature: undefined class_destroy(void)
// callers: [audio_pkt_platform_driver_remove, audio_pkt_platform_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 00104140 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [audio_pkt_platform_driver_remove, audio_pkt_platform_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __gpr_driver_register @ 00104148 size=1
// signature: undefined __gpr_driver_register(void)
// callers: [audio_pkt_platform_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __gpr_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104150 size=1
// signature: undefined _dev_err(void)
// callers: [audio_pkt_remove, audio_pkt_platform_driver_probe, audio_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpr_driver_unregister @ 00104158 size=1
// signature: undefined gpr_driver_unregister(void)
// callers: [audio_pkt_platform_driver_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpr_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 00104160 size=1
// signature: undefined cdev_del(void)
// callers: [audio_pkt_platform_driver_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_skb @ 00104168 size=1
// signature: undefined __alloc_skb(void)
// callers: [audio_pkt_srvc_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_put @ 00104170 size=1
// signature: undefined skb_put(void)
// callers: [audio_pkt_srvc_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00104178 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [audio_pkt_srvc_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_queue_tail @ 00104180 size=1
// signature: undefined skb_queue_tail(void)
// callers: [audio_pkt_srvc_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_queue_tail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



