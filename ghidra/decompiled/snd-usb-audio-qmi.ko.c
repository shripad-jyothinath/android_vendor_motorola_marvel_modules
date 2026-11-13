// Decompiled by Ghidra 12.2
// Program: snd-usb-audio-qmi.ko
// Image base: 00100000

//------------------------------------------------------------
// _snd_usb_pcm_has_fixed_rate @ 0010085c size=120
// signature: undefined _snd_usb_pcm_has_fixed_rate(void)
// callers: [enable_audio_stream]
//------------------------------------------------------------

undefined8 _snd_usb_pcm_has_fixed_rate(undefined8 *param_1)

{
  bool bVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  
  if ((param_1 == (undefined8 *)0x0) || ((*(byte *)(*(long *)*param_1 + 0xfa) >> 5 & 1) == 0)) {
    return 0;
  }
  param_1 = param_1 + 0x13;
  puVar2 = (undefined8 *)*param_1;
  if (puVar2 != param_1) {
    iVar4 = -1;
    do {
      if ((*(byte *)((long)puVar2 + 0x3f) >> 6 & 1) != 0) {
        return 0;
      }
      iVar3 = iVar4;
      if (*(int *)(puVar2 + 9) != 0) {
        if (*(int *)(puVar2 + 9) != 1) {
          return 0;
        }
        iVar3 = *(int *)puVar2[10];
        if ((-1 < iVar4) && (bVar1 = iVar4 != iVar3, iVar3 = iVar4, bVar1)) {
          return 0;
        }
      }
      puVar2 = (undefined8 *)*puVar2;
      iVar4 = iVar3;
    } while (puVar2 != param_1);
  }
  return 1;
}



//------------------------------------------------------------
// uaudio_qmi_plat_probe @ 001008d8 size=832
// signature: undefined uaudio_qmi_plat_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int uaudio_qmi_plat_probe(long param_1)

{
  long *plVar1;
  int iVar2;
  undefined4 uVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  char *pcVar7;
  undefined8 uVar8;
  
  uVar8 = *(undefined8 *)(param_1 + 0x2f8);
  if (uaudio_svc != (long *)0x0) {
LAB_00100908:
    lVar5 = param_1 + 0x10;
    uaudio_qdev = (long *)devm_kmalloc(lVar5,0x70,0xdc0);
    if (uaudio_qdev == (long *)0x0) {
      return -0xc;
    }
    plVar4 = uaudio_qdev + 1;
    *uaudio_qdev = lVar5;
    iVar2 = of_property_read_variable_u32_array(uVar8,"qcom,usb-audio-stream-id",plVar4,1,0);
    if (iVar2 < 0) {
      pcVar7 = "failed to read sid.\n";
    }
    else {
      iVar2 = of_property_read_variable_u32_array
                        (uVar8,"qcom,usb-audio-intr-num",(long)uaudio_qdev + 0xc,1,0);
      if (iVar2 < 0) {
        pcVar7 = "failed to read intr num.\n";
      }
      else {
        lVar6 = iommu_domain_alloc(*(undefined8 *)(param_1 + 0x90));
        uaudio_qdev[3] = lVar6;
        if (lVar6 != 0) {
          iVar2 = iommu_attach_device(lVar6,lVar5);
          plVar4 = uaudio_qdev;
          if (iVar2 == 0) {
            plVar1 = uaudio_qdev + 4;
            uaudio_qdev[4] = (long)plVar1;
            plVar4[5] = (long)plVar1;
            plVar4[6] = 0x3ff000;
            plVar4[7] = 0x22000;
            plVar4[8] = (long)(plVar4 + 8);
            plVar4[9] = (long)(plVar4 + 8);
            plVar4[10] = 0xffbdc000;
            plVar4[0xb] = 0x422000;
            iVar2 = tracepoint_probe_register
                              (&__tracepoint_android_vh_audio_usb_offload_connect,uaudio_connect,0);
            if (iVar2 == 0) {
              uVar3 = android_rvh_probe_register
                                (&__tracepoint_android_rvh_audio_usb_offload_disconnect,
                                 uaudio_disconnect,0);
              _dev_err(lVar5,"failed to register disconnect callback ret = %d\n",uVar3);
              return 0;
            }
            _dev_err(lVar5,"failed to register connect callback ret = %d\n",iVar2);
            iommu_detach_device(uaudio_qdev[3],lVar5);
          }
          else {
            _dev_err(lVar5,"failed to attach device ret = %d\n",iVar2);
          }
          iommu_domain_free(uaudio_qdev[3]);
          return iVar2;
        }
        pcVar7 = "failed to allocate iommu domain\n";
      }
    }
    _dev_err(lVar5,pcVar7);
    return -0x13;
  }
  plVar4 = (long *)kmalloc_trace(_iommu_domain_alloc,0xdc0,0x58);
  if (plVar4 == (long *)0x0) {
    return -0xc;
  }
  lVar5 = alloc_workqueue(&DAT_0010698d,0xe000a,1,"uaudio_svc");
  plVar4[7] = lVar5;
  if (lVar5 == 0) {
    iVar2 = -0xc;
  }
  else {
    lVar6 = kmalloc_trace(__printk,0xdc0,0x148);
    *plVar4 = lVar6;
    if (lVar6 == 0) {
      iVar2 = -0xc;
    }
    else {
      iVar2 = qmi_handle_init(lVar6,0x2e,&uaudio_svc_ops_options,&uaudio_stream_req_handlers);
      if (iVar2 < 0) {
        _printk(&DAT_00106c19,"uaudio_qmi_svc_init",iVar2);
      }
      else {
        uaudio_svc = plVar4;
        plVar4[1] = 0xfffffffe0;
        plVar4[2] = (long)(plVar4 + 2);
        plVar4[3] = (long)(plVar4 + 2);
        plVar4[4] = (long)uaudio_qmi_disconnect_work;
        iVar2 = qmi_add_server(lVar6,0x41d,1,0);
        if (-1 < iVar2) {
          lVar5 = ipc_log_context_create(10,"usb_audio",0);
          plVar4[10] = lVar5;
          goto LAB_00100908;
        }
        _printk(&DAT_00106cff,"uaudio_qmi_svc_init",iVar2);
        qmi_handle_release(*plVar4);
        lVar6 = *plVar4;
        uaudio_svc = (long *)0x0;
      }
      kfree(lVar6);
      lVar5 = plVar4[7];
    }
    destroy_workqueue(lVar5);
  }
  kfree(plVar4);
  return iVar2;
}



//------------------------------------------------------------
// uaudio_qmi_plat_remove @ 00100c1c size=104
// signature: undefined uaudio_qmi_plat_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 uaudio_qmi_plat_remove(long param_1)

{
  tracepoint_probe_unregister(&__tracepoint_android_vh_audio_usb_offload_connect,uaudio_connect,0);
  iommu_detach_device(*(undefined8 *)(uaudio_qdev + 0x18),param_1 + 0x10);
  iommu_domain_free(*(undefined8 *)(uaudio_qdev + 0x18));
  *(undefined8 *)(uaudio_qdev + 0x18) = 0;
  return 0;
}



//------------------------------------------------------------
// uaudio_connect @ 00100c88 size=364
// signature: undefined uaudio_connect(void)
// callers: []
//------------------------------------------------------------

void uaudio_connect(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_2 + 0xa0);
  if (lVar3 == 0) {
    lVar3 = *(long *)(param_2 + 0x30);
  }
  ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: intf: %s: %p chip: %p card_number:%d\n",
                 &DAT_00106b2d,"uaudio_connect",lVar3,param_2,param_3,
                 **(undefined4 **)(param_3 + 0x10));
  lVar3 = *(long *)(param_2 + 0xa0);
  if (lVar3 == 0) {
    lVar3 = *(long *)(param_2 + 0x30);
  }
  _printk("%s%s: intf: %s: %p chip: %p card_number:%d\n",&DAT_001073a9,"uaudio_connect",lVar3,
          param_2,param_3,**(undefined4 **)(param_3 + 0x10));
  uVar1 = **(uint **)(param_3 + 0x10);
  if (0x1f < (int)uVar1) {
    ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: Invalid card number\n",&DAT_00106b2d,
                   "uaudio_connect");
    _printk("%s%s: Invalid card number\n",&DAT_00106770,"uaudio_connect");
    return;
  }
  if (0x1f < uVar1) {
LAB_00100dec:
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x100df0);
    (*pcVar2)();
  }
  if ((ulong)uVar1 * 0x50 < 0x9b9) {
    *(long *)(uadev + (ulong)uVar1 * 0x50 + 0x48) = param_3;
    uVar1 = **(uint **)(param_3 + 0x10);
    if (0x1f < uVar1) goto LAB_00100dec;
    if ((ulong)uVar1 * 0x50 < 0x9b9) {
      *(uint *)(*(long *)(uadev + (ulong)uVar1 * 0x50 + 0x48) + 0xf8) =
           *(uint *)(*(long *)(uadev + (ulong)uVar1 * 0x50 + 0x48) + 0xf8) | 0x400;
      return;
    }
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(1,0x100df4);
  (*pcVar2)();
}



//------------------------------------------------------------
// uaudio_disconnect @ 00100df8 size=1252
// signature: undefined uaudio_disconnect(void)
// callers: []
//------------------------------------------------------------

void uaudio_disconnect(undefined8 param_1,long param_2)

{
  long *plVar1;
  uint uVar2;
  undefined8 *puVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  char *pcVar8;
  ulong uVar9;
  long lVar10;
  undefined8 *puVar11;
  ulong uVar12;
  int *piVar13;
  ulong uVar14;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  puVar3 = uaudio_svc;
  lVar10 = sp_el0;
  local_70 = *(long *)(lVar10 + 0x638);
  lVar10 = *(long *)(param_2 + 200);
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_100 = 0;
  uStack_f8 = 0;
  local_110 = 0;
  uStack_108 = 0;
  local_120 = 0;
  uStack_118 = 0;
  local_130 = 0;
  uStack_128 = 0;
  if (lVar10 == 0) {
    uVar6 = uaudio_svc[10];
    pcVar8 = "%s%s: chip is NULL\n";
  }
  else {
    lVar7 = *(long *)(param_2 + 0xa0);
    uVar2 = **(uint **)(lVar10 + 0x10);
    uVar9 = (ulong)uVar2;
    if (lVar7 == 0) {
      lVar7 = *(long *)(param_2 + 0x30);
    }
    ipc_log_string(uaudio_svc[10],"%s%s: intf: %s: %p chip: %p card: %d\n",&DAT_00106b2d,
                   "uaudio_disconnect",lVar7,param_2,lVar10,uVar9);
    lVar7 = *(long *)(param_2 + 0xa0);
    if (lVar7 == 0) {
      lVar7 = *(long *)(param_2 + 0x30);
    }
    _printk("%s%s: intf: %s: %p chip: %p card: %d\n",&DAT_001073a9,"uaudio_disconnect",lVar7,param_2
            ,lVar10,uVar9);
    if ((int)uVar2 < 0x20) {
      lVar10 = lVar10 + 0xa0;
      mutex_lock(lVar10);
      if (0x20 < uVar2) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1012dc);
        (*pcVar4)();
      }
      uVar14 = uVar9 * 0x50;
      if ((0xa00 < uVar14) || (uVar2 == 0x20)) goto LAB_001012d4;
      plVar1 = (long *)(uadev + uVar14);
      if (*plVar1 == 0) {
        ipc_log_string(uaudio_svc[10],"%s%s: no clean up required\n",&DAT_00106b2d,
                       "uaudio_disconnect");
        _printk("%s%s: no clean up required\n",&DAT_001073a9,"uaudio_disconnect");
      }
      else {
        piVar13 = (int *)(uadev + (ulong)uVar2 * 0x50 + 0x18);
        if (*piVar13 != 0) {
          mutex_unlock(lVar10);
          ipc_log_string(uaudio_svc[10],"%s%s: sending qmi indication disconnect\n",&DAT_00106b2d,
                         "uaudio_disconnect");
          _printk("%s%s: sending qmi indication disconnect\n",&DAT_001073a9,"uaudio_disconnect");
          puVar11 = puVar3 + 8;
          ipc_log_string(uaudio_svc[10],"%s%s: sq->sq_family:%x sq->sq_node:%x sq->sq_port:%x\n",
                         &DAT_00106b2d,"uaudio_disconnect",*(undefined2 *)puVar11,
                         *(undefined4 *)((long)puVar3 + 0x44),*(undefined4 *)(puVar3 + 9));
          _printk("%s%s: sq->sq_family:%x sq->sq_node:%x sq->sq_port:%x\n",&DAT_001073a9,
                  "uaudio_disconnect",*(undefined2 *)puVar11,*(undefined4 *)((long)puVar3 + 0x44),
                  *(undefined4 *)(puVar3 + 9));
          uVar6 = uStack_78;
          local_130 = CONCAT44(local_130._4_4_,1);
          if (((0xa00 < uVar14) || (uVar2 == 0x20)) ||
             (local_130 = CONCAT44(*(undefined4 *)(*plVar1 + 0x5d8),1), 0x9ec < uVar9 * 0x50))
          goto LAB_001012d4;
          uStack_78._4_4_ = SUB84(uVar6,4);
          uStack_78._0_4_ =
               CONCAT13((char)*(undefined4 *)(uadev + (ulong)uVar2 * 0x50 + 0x14),
                        CONCAT12(1,(undefined2)uStack_78));
          iVar5 = qmi_send_indication(*puVar3,puVar11,1,0xb5,qmi_uaudio_stream_ind_msg_v01_ei,
                                      &local_130);
          if (iVar5 < 0) {
            ipc_log_string(uaudio_svc[10],"%s%s: qmi send failed with err: %d\n",&DAT_00106b2d,
                           "uaudio_disconnect",iVar5);
            _printk("%s%s: qmi send failed with err: %d\n",&DAT_00106770,"uaudio_disconnect",iVar5);
            iVar5 = *piVar13;
          }
          else {
            iVar5 = *piVar13;
          }
          if (iVar5 != 0) {
            local_140 = 0;
            uStack_138 = 0;
            local_150 = 0;
            uStack_148 = 0;
            local_158 = 0;
            init_wait_entry(&local_158,0);
            lVar7 = (ulong)uVar2 * 0x50 + 0x107590;
            uVar14 = prepare_to_wait_event(lVar7,&local_158,1);
            if (*piVar13 == 0) {
              uVar12 = 0x9c4;
            }
            else {
              uVar12 = 0x9c4;
              do {
                if (uVar14 != 0) goto LAB_001011dc;
                uVar12 = schedule_timeout(uVar12);
                uVar14 = prepare_to_wait_event(lVar7,&local_158,1);
                if (uVar12 == 0 && *piVar13 == 0) {
                  uVar12 = 1;
                }
              } while ((*piVar13 != 0) && (uVar12 != 0));
            }
            uVar14 = uVar12;
            finish_wait(lVar7,&local_158);
LAB_001011dc:
            if ((int)uVar14 == 0) {
              ipc_log_string(uaudio_svc[10],"%s%s: timeout while waiting for dev_release\n",
                             &DAT_00106b2d,"uaudio_disconnect");
              _printk("%s%s: timeout while waiting for dev_release\n",&DAT_00106770,
                      "uaudio_disconnect");
            }
            else {
              if (-1 < (int)uVar14) goto LAB_001011e4;
              ipc_log_string(uaudio_svc[10],"%s%s: failed with ret %d\n",&DAT_00106b2d,
                             "uaudio_disconnect",uVar14 & 0xffffffff);
              _printk("%s%s: failed with ret %d\n",&DAT_00106770,"uaudio_disconnect",
                      uVar14 & 0xffffffff);
            }
            *piVar13 = 0;
          }
LAB_001011e4:
          mutex_lock(lVar10);
        }
        uaudio_dev_cleanup(plVar1);
      }
      mutex_unlock(lVar10);
      if (0x9b8 < uVar9 * 0x50) {
LAB_001012d4:
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(1,0x1012d8);
        (*pcVar4)();
      }
      *(undefined8 *)(uadev + (ulong)uVar2 * 0x50 + 0x48) = 0;
      goto LAB_00100fa4;
    }
    pcVar8 = "%s%s: invalid card number\n";
    uVar6 = uaudio_svc[10];
  }
  ipc_log_string(uVar6,pcVar8,&DAT_00106b2d,"uaudio_disconnect");
  _printk(pcVar8,&DAT_00106770,"uaudio_disconnect");
LAB_00100fa4:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// uaudio_qmi_disconnect_work @ 001012e0 size=624
// signature: undefined uaudio_qmi_disconnect_work(void)
// callers: []
//------------------------------------------------------------

void uaudio_qmi_disconnect_work(void)

{
  byte bVar1;
  code *pcVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  byte *pbVar8;
  long lVar9;
  byte *pbVar10;
  undefined8 *puVar11;
  byte *pbVar12;
  
  lVar9 = 0;
  do {
    if (*(int *)(uadev + lVar9 * 0x50 + 0x18) != 0) {
      if (0 < *(int *)(uadev + lVar9 * 0x50 + 0x38)) {
        lVar7 = 0;
        do {
          lVar3 = *(long *)(uadev + lVar9 * 0x50 + 0x40);
          if ((lVar3 != 0) && (*(char *)(lVar3 + lVar7 * 0x50 + 0x4c) != '\0')) {
            lVar3 = lVar3 + lVar7 * 0x50;
            pbVar8 = (byte *)(lVar3 + 0x49);
            uVar4 = (ulong)*pbVar8;
            if (0x1f < uVar4) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10154c);
              (*pcVar2)();
            }
            if (0x9b8 < uVar4 * 0x50) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(1,0x101550);
              (*pcVar2)();
            }
            pbVar12 = (byte *)(lVar3 + 0x4a);
            lVar5 = *(long *)(uadev + uVar4 * 0x50 + 0x48);
            pbVar10 = (byte *)(lVar3 + 0x4b);
            bVar1 = *pbVar10;
            if ((lVar5 != 0) && (*(int *)(lVar5 + 0xd8) == 0)) {
              if ((uint)*pbVar12 < *(uint *)(lVar5 + 0x158)) {
                if (bVar1 < 2) {
                  plVar6 = (long *)(lVar5 + 0x118);
                  do {
                    plVar6 = (long *)*plVar6;
                    if (plVar6 == (long *)(lVar5 + 0x118)) goto LAB_00101394;
                  } while (*(uint *)(plVar6 + -0x35) != (uint)*pbVar12);
                  puVar11 = plVar6 + (ulong)bVar1 * 0x1a + -0x34;
                  if ((puVar11 != (undefined8 *)0x0 && *(long *)(uadev + lVar9 * 0x50 + 0x48) != 0)
                     && (*(int *)(*(long *)(uadev + lVar9 * 0x50 + 0x48) + 0xd8) == 0)) {
                    lVar3 = *(long *)*puVar11;
                    if ((plVar6[(ulong)bVar1 * 0x1a + -0x27] != 0) ||
                       (plVar6[(ulong)bVar1 * 0x1a + -0x26] != 0)) {
                      close_endpoints(lVar3,puVar11);
                      mutex_lock(lVar3 + 0xa0);
                      plVar6[(ulong)bVar1 * 0x1a + -0x30] = 0;
                      mutex_unlock(lVar3 + 0xa0);
                    }
                    snd_usb_autosuspend(lVar3);
                    goto LAB_001013f4;
                  }
                }
                else {
                  _printk(&DAT_00106f6e,"find_substream",bVar1);
                }
              }
              else {
                _printk(&DAT_00106f48,"find_substream");
              }
            }
LAB_00101394:
            ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),
                           "%s%s: no subs for c#%u, dev#%u dir%u\n",&DAT_00106b2d,
                           "uaudio_qmi_disconnect_work",*pbVar8,*pbVar12,*pbVar10);
            _printk("%s%s: no subs for c#%u, dev#%u dir%u\n",&DAT_001073a9,
                    "uaudio_qmi_disconnect_work",*pbVar8,*pbVar12,*pbVar10);
          }
LAB_001013f4:
          lVar7 = lVar7 + 1;
        } while (lVar7 < *(int *)(uadev + lVar9 * 0x50 + 0x38));
      }
      *(int *)(uadev + lVar9 * 0x50 + 0x18) = 0;
      uaudio_dev_cleanup(uadev + lVar9 * 0x50);
    }
    lVar9 = lVar9 + 1;
    if (lVar9 == 0x20) {
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// uaudio_qmi_bye_cb @ 00101554 size=260
// signature: undefined uaudio_qmi_bye_cb(void)
// callers: []
//------------------------------------------------------------

void uaudio_qmi_bye_cb(long param_1,int param_2)

{
  long *plVar1;
  int *piVar2;
  
  plVar1 = uaudio_svc;
  if (*uaudio_svc == param_1) {
    if (*(char *)((long)uaudio_svc + 0x4c) != '\0') {
      piVar2 = (int *)((long)uaudio_svc + 0x44);
      if (*piVar2 == param_2) {
        ipc_log_string(uaudio_svc[10],"%s%s: node: %d\n",&DAT_00106b2d,"uaudio_qmi_bye_cb",param_2);
        _printk("%s%s: node: %d\n",&DAT_001073a9,"uaudio_qmi_bye_cb",param_2);
        queue_work_on(0x20,plVar1[7],plVar1 + 1);
        *(undefined2 *)(plVar1 + 8) = 0;
        piVar2[0] = 0;
        piVar2[1] = 0;
        *(undefined1 *)((long)plVar1 + 0x4c) = 0;
      }
    }
  }
  else {
    ipc_log_string(uaudio_svc[10],"%s%s: handle mismatch\n",&DAT_00106b2d,"uaudio_qmi_bye_cb");
    _printk("%s%s: handle mismatch\n",&DAT_00106770,"uaudio_qmi_bye_cb");
  }
  return;
}



//------------------------------------------------------------
// uaudio_qmi_svc_disconnect_cb @ 0010165c size=288
// signature: undefined uaudio_qmi_svc_disconnect_cb(void)
// callers: []
//------------------------------------------------------------

void uaudio_qmi_svc_disconnect_cb(long param_1,int param_2,int param_3)

{
  long *plVar1;
  int *piVar2;
  
  plVar1 = uaudio_svc;
  if (uaudio_svc != (long *)0x0) {
    if (*uaudio_svc == param_1) {
      if (*(char *)((long)uaudio_svc + 0x4c) != '\0') {
        piVar2 = (int *)((long)uaudio_svc + 0x44);
        if (*piVar2 == param_2) {
          if ((int)uaudio_svc[9] == param_3) {
            ipc_log_string(uaudio_svc[10],"%s%s: client node:%x port:%x\n",&DAT_00106b2d,
                           "uaudio_qmi_svc_disconnect_cb",param_2,param_3);
            _printk("%s%s: client node:%x port:%x\n",&DAT_001073a9,"uaudio_qmi_svc_disconnect_cb",
                    param_2,param_3);
            queue_work_on(0x20,plVar1[7],plVar1 + 1);
            *(undefined2 *)(plVar1 + 8) = 0;
            piVar2[0] = 0;
            piVar2[1] = 0;
            *(undefined1 *)((long)plVar1 + 0x4c) = 0;
          }
        }
      }
    }
    else {
      ipc_log_string(uaudio_svc[10],"%s%s: handle mismatch\n",&DAT_00106b2d,
                     "uaudio_qmi_svc_disconnect_cb");
      _printk("%s%s: handle mismatch\n",&DAT_00106770,"uaudio_qmi_svc_disconnect_cb");
    }
  }
  return;
}



//------------------------------------------------------------
// handle_uaudio_stream_req @ 00101780 size=3232
// signature: undefined handle_uaudio_stream_req(void)
// callers: []
//------------------------------------------------------------

void handle_uaudio_stream_req
               (undefined8 param_1,undefined8 *param_2,undefined8 param_3,char *param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  bool bVar4;
  long *plVar5;
  long lVar6;
  undefined8 *puVar7;
  code *pcVar8;
  undefined4 uVar9;
  int iVar10;
  long lVar11;
  char *pcVar12;
  long lVar13;
  ulong uVar14;
  long *plVar15;
  undefined8 *puVar16;
  undefined8 uVar17;
  long lVar18;
  ulong uVar19;
  uint *puVar20;
  long lVar21;
  uint uVar22;
  ulong uVar23;
  uint uVar24;
  undefined1 *puVar25;
  uint uVar26;
  ulong uVar27;
  long lVar28;
  undefined8 local_148;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  puVar7 = uaudio_svc;
  lVar11 = sp_el0;
  local_70 = *(long *)(lVar11 + 0x638);
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_100 = 0;
  uStack_f8 = 0;
  local_110 = 0;
  uStack_108 = 0;
  local_120 = 0;
  uStack_118 = 0;
  local_130 = 0;
  local_128 = 0;
  local_140 = 0;
  local_138 = 0;
  local_148 = 0;
  lVar11 = ktime_get();
  ipc_log_string(uaudio_svc[10],"%s%s: sq_node:%x sq_port:%x sq_family:%x\n",&DAT_00106b2d,
                 "handle_uaudio_stream_req",*(undefined4 *)((long)param_2 + 4),
                 *(undefined4 *)(param_2 + 1),*(undefined2 *)param_2);
  _printk("%s%s: sq_node:%x sq_port:%x sq_family:%x\n",&DAT_001073a9,"handle_uaudio_stream_req",
          *(undefined4 *)((long)param_2 + 4),*(undefined4 *)(param_2 + 1),*(undefined2 *)param_2);
  if (*(char *)((long)puVar7 + 0x4c) == '\0') {
    uVar17 = *param_2;
    *(undefined4 *)(puVar7 + 9) = *(undefined4 *)(param_2 + 1);
    puVar7[8] = uVar17;
    *(undefined1 *)((long)puVar7 + 0x4c) = 1;
  }
  if ((((param_4[8] == '\0') || (param_4[0x18] == '\0')) || (param_4[0x10] == '\0')) ||
     (param_4[0x20] == '\0')) {
    ipc_log_string(uaudio_svc[10],"%s%s: invalid request msg\n",&DAT_00106b2d,
                   "handle_uaudio_stream_req");
    _printk("%s%s: invalid request msg\n",&DAT_00106770,"handle_uaudio_stream_req");
    uVar23 = 0;
    lVar28 = 0;
    uVar24 = 0xffffffea;
    iVar10 = -0x16;
    cVar2 = *param_4;
  }
  else {
    uVar24 = *(uint *)(param_4 + 4);
    uVar23 = (ulong)(uVar24 >> 0x10) & 0xff;
    uVar22 = (uint)uVar23;
    if (0x1f < uVar22) goto LAB_00101d90;
    uVar27 = uVar23 * 0x50;
    if (0x9b8 < uVar27) goto LAB_00102228;
    lVar28 = *(long *)(uadev + uVar27 + 0x48);
    if ((lVar28 == 0) || (*(int *)(lVar28 + 0xd8) != 0)) {
LAB_00101aa8:
      ipc_log_string(uaudio_svc[10],"%s%s: invalid substream\n",&DAT_00106b2d,
                     "handle_uaudio_stream_req");
      _printk("%s%s: invalid substream\n",&DAT_00106770,"handle_uaudio_stream_req");
      lVar28 = 0;
LAB_00101aec:
      uVar24 = 0xffffffea;
LAB_00101af0:
      iVar10 = -0x16;
    }
    else {
      uVar26 = uVar24 >> 8 & 0xff;
      if (*(uint *)(lVar28 + 0x158) <= uVar26) {
        _printk(&DAT_00106f48,"find_substream",uVar26);
        goto LAB_00101aa8;
      }
      uVar14 = (ulong)uVar24 & 0xff;
      if (1 < (uint)uVar14) {
        _printk(&DAT_00106f6e,"find_substream",uVar14);
        goto LAB_00101aa8;
      }
      plVar15 = (long *)(lVar28 + 0x118);
      do {
        plVar15 = (long *)*plVar15;
        if (plVar15 == (long *)(lVar28 + 0x118)) goto LAB_00101aa8;
      } while (*(uint *)(plVar15 + -0x35) != uVar26);
      lVar6 = (long)(plVar15 + uVar14 * 0x1a + -0x34);
      if (lVar6 == 0) goto LAB_00101aa8;
      ipc_log_string(uaudio_svc[10],"%s%s: card#:%d dev#:%d dir:%d en:%d fmt:%d rate:%d #ch:%d\n",
                     &DAT_00106b2d,"__handle_uaudio_stream_req",uVar23,uVar26,uVar14,*param_4,
                     *(undefined4 *)(param_4 + 0xc),*(undefined4 *)(param_4 + 0x1c),
                     *(undefined4 *)(param_4 + 0x14));
      _printk("%s%s: card#:%d dev#:%d dir:%d en:%d fmt:%d rate:%d #ch:%d\n",&DAT_00106cfc,
              "__handle_uaudio_stream_req",uVar23,uVar26,uVar14,*param_4,
              *(undefined4 *)(param_4 + 0xc),*(undefined4 *)(param_4 + 0x1c),
              *(undefined4 *)(param_4 + 0x14));
      if (0x1f < uVar22) {
        ipc_log_string(uaudio_svc[10],"%s%s: invalid card # %u",&DAT_00106b2d,
                       "__handle_uaudio_stream_req",uVar23);
        pcVar12 = "%s%s: invalid card # %u";
        uVar27 = uVar23;
LAB_00101c60:
        _printk(pcVar12,&DAT_00106770,"__handle_uaudio_stream_req",uVar27);
        goto LAB_00101aec;
      }
      if (0x11 < *(uint *)(param_4 + 0xc)) {
        ipc_log_string(uaudio_svc[10],"%s%s: unsupported pcm format received %d\n",&DAT_00106b2d,
                       "__handle_uaudio_stream_req");
        uVar27 = (ulong)*(uint *)(param_4 + 0xc);
        pcVar12 = "%s%s: unsupported pcm format received %d\n";
        goto LAB_00101c60;
      }
      if (0x9b8 < uVar27) goto LAB_00102228;
      lVar18 = *(long *)(uadev + uVar27 + 0x48);
      if ((lVar18 != 0) && (*(int *)(lVar18 + 0xd8) == 0)) {
        if (*(uint *)(lVar18 + 0x158) <= uVar26) {
          _printk(&DAT_00106f48,"find_substream",uVar26);
          goto LAB_00101d28;
        }
        uVar19 = uVar23 * 0x50;
        uVar27 = uVar23 * 0x50;
        plVar15 = (long *)(lVar18 + 0x118);
        do {
          plVar15 = (long *)*plVar15;
          if (plVar15 == (long *)(lVar18 + 0x118)) goto LAB_00101d28;
        } while (*(uint *)(plVar15 + -0x35) != uVar26);
        plVar5 = plVar15 + uVar14 * 0x1a + -0x34;
        if ((plVar5 == (long *)0x0) || (*(int *)(lVar18 + 0xd8) != 0)) goto LAB_00101d28;
        if (plVar15[uVar14 * 0x1a + -0x30] == 0) {
          uVar26 = 0xffffffff;
        }
        else {
          uVar26 = (uint)*(byte *)(plVar15[uVar14 * 0x1a + -0x30] + 0x28);
        }
        cVar2 = *param_4;
        if (cVar2 == '\0') {
          if (0x9c8 < uVar27) goto LAB_00102228;
LAB_00101de4:
          uVar14 = uVar23 * 0x50;
          if (0x9c8 < uVar14) goto LAB_00102228;
          if (0 < (int)*(uint *)(uadev + uVar23 * 0x50 + 0x38)) {
            lVar21 = 0;
            uVar24 = 0;
            do {
              if (cVar2 == '\0') {
                if ((0x9c0 < uVar27) || (0x9c0 < uVar14)) goto LAB_00102228;
                if (uVar26 == *(byte *)(*(long *)(uadev + uVar14 + 0x40) + lVar21 + 0x48))
                goto LAB_00101e94;
              }
              else {
                if ((0x9c0 < uVar27) || (0x9c0 < uVar14)) goto LAB_00102228;
                if (*(char *)(*(long *)(uadev + uVar14 + 0x40) + lVar21 + 0x4c) == '\0')
                goto LAB_00101e94;
              }
              uVar24 = uVar24 + 1;
              lVar21 = lVar21 + 0x50;
            } while ((ulong)*(uint *)(uadev + uVar23 * 0x50 + 0x38) * 0x50 != lVar21);
          }
          uVar24 = 0xffffffea;
        }
        else {
          if ((0x9c0 < uVar27) || (0x9c0 < uVar23 * 0x50)) goto LAB_00102228;
          if (*(long *)(uadev + uVar23 * 0x50 + 0x40) != 0) goto LAB_00101de4;
          uVar24 = 0;
        }
LAB_00101e94:
        plVar15 = (long *)*plVar5;
        if ((((*(int *)(lVar18 + 0xd8) != 0) || (plVar15 == (long *)0x0)) || (plVar15[1] == 0)) ||
           (*plVar15 == 0)) {
          ipc_log_string(uaudio_svc[10],"%s%s: chip or sub not available: shutdown:%d stream:%p\n",
                         &DAT_00106b2d,"__handle_uaudio_stream_req",*(undefined4 *)(lVar18 + 0xd8));
          _printk("%s%s: chip or sub not available: shutdown:%d stream:%p\n",&DAT_00106770,
                  "__handle_uaudio_stream_req",*(undefined4 *)(lVar18 + 0xd8),*plVar5);
          puVar16 = (undefined8 *)*plVar5;
          if (puVar16 == (undefined8 *)0x0) {
            iVar10 = -0x13;
          }
          else {
            ipc_log_string(uaudio_svc[10],"%s%s: pcm:%p chip:%p\n",&DAT_00106b2d,
                           "__handle_uaudio_stream_req",puVar16[1],*puVar16);
            _printk("%s%s: pcm:%p chip:%p\n",&DAT_00106770,"__handle_uaudio_stream_req",
                    ((undefined8 *)*plVar5)[1],*(undefined8 *)*plVar5);
            iVar10 = -0x13;
          }
          goto LAB_00101af4;
        }
        if ((cVar2 != '\0') && ((int)uVar24 < 0)) {
          ipc_log_string(uaudio_svc[10],"%s%s: interface# %d already in use card# %d\n",
                         &DAT_00106b2d,"__handle_uaudio_stream_req",uVar26,uVar23);
          _printk("%s%s: interface# %d already in use card# %d\n",&DAT_00106770,
                  "__handle_uaudio_stream_req",uVar26,uVar23);
          iVar10 = -0x10;
          goto LAB_00101af4;
        }
        if (param_4[0x28] == '\0') {
          iVar10 = 0;
          iVar3 = -0x16;
LAB_00102094:
          if (0xa00 < (uVar23 * 0x50 | 8)) goto LAB_00102228;
          *(undefined8 *)(uadev + uVar23 * 0x50 + 8) = *(undefined8 *)(lVar28 + 0x188);
          piVar1 = (int *)(lVar28 + 0xdc);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            cVar2 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar4) {
              *piVar1 = *piVar1 + 1;
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
          if (*param_4 == '\0') {
            if (0x9c0 < uVar23 * 0x50) goto LAB_00102228;
            lVar18 = *(long *)(uadev + uVar23 * 0x50 + 0x40);
            puVar20 = (uint *)(lVar18 + (long)(int)uVar24 * 0x50 + 0x38);
            uVar26 = *puVar20;
            if (uVar26 != 0) {
              if ((0xa00 < uVar19) || (uVar22 == 0x20)) goto LAB_00102228;
              lVar13 = *(long *)(uadev + uVar19);
              lVar21 = lVar13 + 0x4e8;
              if ((uVar26 & 0x80) != 0) {
                lVar21 = lVar13 + 0x468;
              }
              if (*(long *)(lVar21 + ((ulong)(uVar26 >> 0xf) & 0xf) * 8) == 0) {
                ipc_log_string(uaudio_svc[10],"%s%s: no data ep\n",&DAT_00106b2d,
                               "handle_uaudio_stream_req");
                _printk("%s%s: no data ep\n",&DAT_001073a9,"handle_uaudio_stream_req");
              }
              else {
                xhci_stop_endpoint();
              }
              *puVar20 = 0;
            }
            puVar20 = (uint *)(lVar18 + (long)(int)uVar24 * 0x50 + 0x3c);
            uVar26 = *puVar20;
            if (uVar26 != 0) {
              if ((0xa00 < uVar19) || (uVar22 == 0x20)) goto LAB_00102228;
              lVar21 = *(long *)(uadev + uVar19);
              lVar18 = lVar21 + 0x4e8;
              if ((uVar26 & 0x80) != 0) {
                lVar18 = lVar21 + 0x468;
              }
              if (*(long *)(lVar18 + ((ulong)(uVar26 >> 0xf) & 0xf) * 8) == 0) {
                ipc_log_string(uaudio_svc[10],"%s%s: no sync ep\n",&DAT_00106b2d,
                               "handle_uaudio_stream_req");
                _printk("%s%s: no sync ep\n",&DAT_001073a9,"handle_uaudio_stream_req");
              }
              else {
                xhci_stop_endpoint();
              }
              *puVar20 = 0;
            }
            disable_audio_stream(lVar6);
          }
          else {
            uVar9 = map_pcm_format(*(undefined4 *)(param_4 + 0xc));
            iVar10 = enable_audio_stream(lVar6,uVar9,*(undefined4 *)(param_4 + 0x14),
                                         *(undefined4 *)(param_4 + 0x1c),iVar3);
            if (iVar10 == 0) {
              iVar10 = prepare_qmi_response(lVar6,param_4,&local_148,uVar24);
            }
          }
          piVar1 = (int *)(lVar28 + 0xdc);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            iVar3 = *piVar1;
            cVar2 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar4) {
              *piVar1 = iVar3 + -1;
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
          DataMemoryBarrier(2,3);
          if ((iVar3 + -1 == 0) && (*(int *)(lVar28 + 0xd8) != 0)) {
            __wake_up(lVar28 + 0xe0,3,1,0);
          }
          goto LAB_00101af4;
        }
        uVar9 = *(undefined4 *)(param_4 + 0x2c);
        iVar10 = get_data_interval_from_si(lVar6,uVar9);
        if (iVar10 != -0x16) {
          ipc_log_string(uaudio_svc[10],"%s%s: data interval %u\n",&DAT_00106b2d,
                         "handle_uaudio_stream_req",iVar10);
          _printk("%s%s: data interval %u\n",&DAT_001073a9,"handle_uaudio_stream_req",iVar10);
          iVar3 = iVar10;
          goto LAB_00102094;
        }
        ipc_log_string(uaudio_svc[10],"%s%s: invalid service interval %u\n",&DAT_00106b2d,
                       "handle_uaudio_stream_req",uVar9);
        _printk("%s%s: invalid service interval %u\n",&DAT_00106770,"handle_uaudio_stream_req",
                *(undefined4 *)(param_4 + 0x2c));
        goto LAB_00101af0;
      }
LAB_00101d28:
      ipc_log_string(uaudio_svc[10],"%s%s: can\'t find substream for card# %u, dev# %u dir%u\n",
                     &DAT_00106b2d,"__handle_uaudio_stream_req",uVar23,uVar26,uVar14);
      _printk("%s%s: can\'t find substream for card# %u, dev# %u dir%u\n",&DAT_00106770,
              "__handle_uaudio_stream_req",uVar23,uVar26,uVar14);
      iVar10 = -0x13;
      uVar24 = 0xffffffea;
    }
LAB_00101af4:
    cVar2 = *param_4;
  }
  if (((cVar2 == '\0') && (iVar10 != -0x16)) && (iVar10 != -0x13)) {
    mutex_lock(lVar28 + 0xa0);
    uVar22 = (uint)uVar23;
    if ((int)uVar24 < 0) {
      if (0x1f < uVar22) goto LAB_00101d90;
    }
    else {
      if (0x1f < uVar22) {
LAB_00101d90:
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x101d94);
        (*pcVar8)();
      }
      if (((0x9c0 < uVar23 * 0x50) || (0xa00 < uVar23 * 0x50)) || (uVar22 == 0x20)) {
LAB_00102228:
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(1,0x10222c);
        (*pcVar8)();
      }
      uaudio_dev_intf_cleanup
                (*(undefined8 *)(uadev + uVar23 * 0x50),
                 *(long *)(uadev + uVar23 * 0x50 + 0x40) + (ulong)uVar24 * 0x50);
    }
    if (*(int *)(uadev + uVar23 * 0x50 + 0x18) != 0) {
      lVar6 = uVar23 * 0x50;
      piVar1 = (int *)(uadev + lVar6 + 0x1c);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar3 = *piVar1;
        cVar2 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar4) {
          *piVar1 = iVar3 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      if (iVar3 == 1) {
        DataMemoryBarrier(2,1);
        puVar25 = uadev + lVar6;
        ipc_log_string(uaudio_svc[10],"%s%s: for dev %pK\n",&DAT_00106b2d,"uaudio_dev_release",
                       puVar25);
        _printk("%s%s: for dev %pK\n",&DAT_001073a9,"uaudio_dev_release",puVar25);
        uaudio_event_ring_cleanup_free(puVar25);
        *(undefined4 *)(uadev + lVar6 + 0x18) = 0;
        __wake_up(lVar6 + 0x107590,3,1,0);
      }
      else if (iVar3 < 1) {
        refcount_warn_saturate(piVar1,3);
      }
    }
    mutex_unlock(lVar28 + 0xa0);
  }
  local_138 = CONCAT44(local_138._4_4_,iVar10);
  local_128 = CONCAT44(local_128._4_4_,*(undefined4 *)(param_4 + 4));
  local_130._0_5_ = CONCAT14(1,(undefined4)local_130);
  local_140 = CONCAT35(local_140._5_3_,0x100000000);
  local_140 = CONCAT44(local_140._4_4_,(uint)(iVar10 != 0));
  local_148._0_5_ = CONCAT14(1,(undefined4)local_148);
  uVar9 = qmi_send_response(*puVar7,param_2,param_3,1,0xca,qmi_uaudio_stream_resp_msg_v01_ei,
                            &local_148);
  uVar17 = uaudio_svc[10];
  lVar28 = ktime_get();
  ipc_log_string(uVar17,"%s%s: ret %d: qmi response latency %lld ms\n",&DAT_00106b2d,
                 "handle_uaudio_stream_req",uVar9,(lVar28 - lVar11) / 1000000);
  lVar28 = ktime_get();
  _printk("%s%s: ret %d: qmi response latency %lld ms\n",&DAT_001073a9,"handle_uaudio_stream_req",
          uVar9,(lVar28 - lVar11) / 1000000);
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// get_data_interval_from_si @ 00102458 size=88
// signature: undefined get_data_interval_from_si(void)
// callers: [handle_uaudio_stream_req]
//------------------------------------------------------------

int get_data_interval_from_si(long param_1,uint param_2)

{
  uint uVar2;
  uint uVar1;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0x7d;
  if (*(uint *)(*(long *)(param_1 + 8) + 0x1c) < 3) {
    uVar5 = 1000;
  }
  uVar3 = 0;
  if (uVar5 != 0) {
    uVar3 = param_2 / uVar5;
  }
  if (param_2 != uVar3 * uVar5) {
    return -0x16;
  }
  uVar1 = (uVar3 & 0xaaaaaaaa) >> 1 | (uVar3 & 0x55555555) << 1;
  uVar1 = (uVar1 & 0xcccccccc) >> 2 | (uVar1 & 0x33333333) << 2;
  uVar1 = (uVar1 & 0xf0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f) << 4;
  uVar2 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
  uVar1 = 0;
  if (uVar5 <= param_2) {
    uVar1 = (int)LZCOUNT(uVar2 >> 0x10 | uVar2 << 0x10) + 1;
  }
  iVar4 = uVar1 - 1;
  if ((uVar3 >> (ulong)(uVar1 & 0x1f) != 0 || 0x10 < uVar1) || param_2 < uVar5) {
    iVar4 = -0x16;
  }
  return iVar4;
}



//------------------------------------------------------------
// enable_audio_stream @ 001024b0 size=1596
// signature: undefined enable_audio_stream(void)
// callers: [handle_uaudio_stream_req]
//------------------------------------------------------------

int enable_audio_stream(undefined8 *param_1,ulong param_2,uint param_3,uint param_4,uint param_5)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  byte bVar7;
  byte bVar8;
  ulong uVar9;
  uint *puVar10;
  char *pcVar11;
  long lVar12;
  int iVar13;
  undefined8 *puVar14;
  undefined8 *puVar15;
  uint local_2d8;
  uint local_2d4;
  undefined4 uStack_2d0;
  undefined1 auStack_2c8 [36];
  uint local_2a4 [62];
  undefined1 auStack_1ac [12];
  undefined1 auStack_1a0 [216];
  uint local_c8;
  uint local_c4;
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  lVar12 = *(long *)*param_1;
  memset(auStack_2c8,0,0x260);
  _snd_pcm_hw_params_any(auStack_2c8);
  if ((local_2a4[0] == 0) ||
     (uVar3 = local_2a4[0] - (local_2a4[0] >> 1 & 0x55555555),
     uVar3 = (uVar3 & 0x33333333) + (uVar3 >> 2 & 0x33333333),
     (uVar3 + (uVar3 >> 4) & 0xf0f0f0f) * 0x1010101 >> 0x18 < 2)) {
    if ((local_2a4[1] == 0) ||
       ((bVar7 = 1, local_2a4[0] == 0 &&
        (local_2a4[1] = local_2a4[1] - (local_2a4[1] >> 1 & 0x55555555),
        uVar3 = (local_2a4[1] & 0x33333333) + (local_2a4[1] >> 2 & 0x33333333),
        (uVar3 + (uVar3 >> 4) & 0xf0f0f0f) * 0x1010101 >> 0x18 < 2)))) {
      bVar7 = 0;
    }
  }
  else {
    bVar7 = 1;
  }
  if ((8 < (uint)((param_2 & 0xffffffff) >> 9)) ||
     (uVar9 = (param_2 & 0xffffffff) >> 5, (int)uVar9 == 0x8f)) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(1,0x102ae8);
    (*pcVar1)();
  }
  local_2a4[4] = 0;
  local_2a4[5] = 0;
  local_2a4[6] = 0;
  local_2a4[7] = 0;
  local_2a4[0] = 0;
  local_2a4[1] = 0;
  local_2a4[2] = 0;
  local_2a4[3] = 0;
  local_2a4[uVar9] = local_2a4[uVar9] & 1 << (ulong)((uint)param_2 & 0x1f);
  if (!(bool)((local_2a4[1] != 0 || local_2a4[0] != 0) & (bVar7 ^ 1))) {
    local_c4 = local_c4 | 2;
    local_c8 = local_c8 | 2;
  }
  uStack_2d0 = 4;
  local_2d8 = param_3;
  local_2d4 = param_3;
  iVar2 = snd_interval_refine(auStack_1ac,&local_2d8);
  if (iVar2 != 0) {
    local_c4 = local_c4 | 0x400;
    local_c8 = local_c8 | 0x400;
  }
  uStack_2d0 = 4;
  local_2d8 = param_4;
  local_2d4 = param_4;
  iVar2 = snd_interval_refine(auStack_1a0,&local_2d8);
  if (iVar2 != 0) {
    local_c4 = local_c4 | 0x800;
    local_c8 = local_c8 | 0x800;
  }
  if (*(long *)(lVar12 + 0x18) == 0) {
LAB_00102688:
    iVar2 = -0x13;
    goto LAB_0010268c;
  }
  pm_runtime_barrier(*(long *)(lVar12 + 0x18) + 0x30);
  snd_usb_autoresume(lVar12);
  if ((param_1[5] != 0) &&
     (iVar2 = snd_usb_power_domain_set(*(undefined8 *)*param_1,param_1[5],0), iVar2 < 0)) {
    _dev_err(param_1[1] + 0xa8,"Cannot change Power Domain ID: %d to state: %d. Err: %d\n",
             *(undefined4 *)param_1[5],0,iVar2);
    goto LAB_0010268c;
  }
  puVar5 = param_1 + 0x13;
  puVar6 = (undefined8 *)*puVar5;
  if (puVar6 != puVar5) {
    puVar15 = (undefined8 *)0x0;
    bVar7 = 0;
    do {
      if (((((param_5 == 0xffffffea) || (*(byte *)((long)puVar6 + 0x34) == param_5)) &&
           ((puVar6[2] & 1L << (param_2 & 0x3f)) != 0)) &&
          ((*(uint *)(puVar6 + 3) == param_3 && (*(uint *)(puVar6 + 8) <= param_4)))) &&
         (param_4 <= *(uint *)((long)puVar6 + 0x44))) {
        if ((*(byte *)((long)puVar6 + 0x3f) >> 6 & 1) == 0) {
          uVar9 = (ulong)*(uint *)(puVar6 + 9);
          if (*(uint *)(puVar6 + 9) != 0) {
            puVar10 = (uint *)puVar6[10];
            do {
              if (*puVar10 == param_4) goto LAB_001027d4;
              uVar9 = uVar9 - 1;
              puVar10 = puVar10 + 1;
            } while (uVar9 != 0);
          }
          goto LAB_00102744;
        }
LAB_001027d4:
        bVar8 = *(byte *)((long)puVar6 + 0x2e) & 0xc;
        puVar14 = puVar6;
        if (puVar15 == (undefined8 *)0x0) goto LAB_0010274c;
        if (bVar7 == bVar8) goto LAB_001027e8;
        if (bVar8 == 8) {
          if (*(int *)(param_1 + 3) != 1) goto LAB_00102830;
          goto LAB_00102744;
        }
        if ((bVar8 == 4) && (*(int *)(param_1 + 3) == 0)) goto LAB_00102744;
LAB_00102830:
        if (bVar7 == 8) {
          if (*(int *)(param_1 + 3) != 1) goto LAB_001027e8;
        }
        else if ((bVar7 != 4) || (*(int *)(param_1 + 3) != 0)) {
LAB_001027e8:
          if (*(uint *)(puVar6 + 7) <= *(uint *)(puVar15 + 7)) {
            puVar14 = puVar15;
            bVar8 = bVar7;
          }
        }
      }
      else {
LAB_00102744:
        puVar14 = puVar15;
        bVar8 = bVar7;
      }
LAB_0010274c:
      puVar6 = (undefined8 *)*puVar6;
      puVar15 = puVar14;
      bVar7 = bVar8;
    } while (puVar6 != puVar5);
    if (puVar14 != (undefined8 *)0x0) {
      if (*(int *)(lVar12 + 0xd8) != 0) {
        ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: chip already shutdown\n",
                       &DAT_00106b2d,"enable_audio_stream");
        _printk("%s%s: chip already shutdown\n",&DAT_00106770,"enable_audio_stream");
        goto LAB_00102688;
      }
      if (param_1[0xd] != 0) {
        close_endpoints(lVar12,param_1);
      }
      uVar3 = _snd_usb_pcm_has_fixed_rate(param_1);
      lVar4 = snd_usb_endpoint_open(lVar12,puVar14,auStack_2c8,0,uVar3 & 1);
      param_1[0xd] = lVar4;
      if (lVar4 == 0) {
        pcVar11 = "%s%s: failed to open data endpoint\n";
LAB_001028e4:
        ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),pcVar11,&DAT_00106b2d,
                       "enable_audio_stream");
        _printk(pcVar11,&DAT_00106770,"enable_audio_stream");
        iVar2 = -0x16;
      }
      else {
        if (*(char *)(puVar14 + 6) != '\0') {
          lVar4 = snd_usb_endpoint_open(lVar12,puVar14,auStack_2c8,1,uVar3 & 1);
          param_1[0xe] = lVar4;
          if (lVar4 == 0) {
            pcVar11 = "%s%s: failed to open sync endpoint\n";
            goto LAB_001028e4;
          }
          *(long *)(param_1[0xd] + 0x48) = lVar4;
        }
        mutex_lock(lVar12 + 0xa0);
        param_1[4] = puVar14;
        mutex_unlock(lVar12 + 0xa0);
        iVar2 = configure_endpoints(lVar12,param_1);
        if (iVar2 < 0) {
          ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),
                         "%s%s: %d:%d: usb_set_interface failed (%d)\n",&DAT_00106b2d,
                         "enable_audio_stream",*(undefined1 *)(puVar14 + 5),
                         *(undefined1 *)((long)puVar14 + 0x29),iVar2);
          _printk("%s%s: %d:%d: usb_set_interface failed (%d)\n",&DAT_00106770,"enable_audio_stream"
                  ,*(undefined1 *)(puVar14 + 5),*(undefined1 *)((long)puVar14 + 0x29),iVar2);
        }
        else {
          pcVar11 = "playback";
          if (*(int *)(param_1 + 3) != 0) {
            pcVar11 = "capture";
          }
          iVar13 = 0x7d;
          if (*(uint *)(param_1[1] + 0x1c) < 3) {
            iVar13 = 1000;
          }
          ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),
                         "%s%s: selected %s iface:%d altsetting:%d datainterval:%dus\n",
                         &DAT_00106b2d,"enable_audio_stream",pcVar11,*(undefined1 *)(puVar14 + 5),
                         *(undefined1 *)((long)puVar14 + 0x29),
                         iVar13 << (ulong)(*(byte *)((long)puVar14 + 0x34) & 0x1f));
          pcVar11 = "playback";
          if (*(int *)(param_1 + 3) != 0) {
            pcVar11 = "capture";
          }
          iVar13 = 0x7d;
          if (*(uint *)(param_1[1] + 0x1c) < 3) {
            iVar13 = 1000;
          }
          _printk("%s%s: selected %s iface:%d altsetting:%d datainterval:%dus\n",&DAT_00106cfc,
                  "enable_audio_stream",pcVar11,*(undefined1 *)(puVar14 + 5),
                  *(undefined1 *)((long)puVar14 + 0x29),
                  iVar13 << (ulong)(*(byte *)((long)puVar14 + 0x34) & 0x1f));
        }
      }
      goto LAB_0010268c;
    }
  }
  _dev_err(param_1[1] + 0xa8,"cannot find format: format = %#x, rate = %d, channels = %d\n",
           param_2 & 0xffffffff,param_4,param_3);
  iVar2 = -0x16;
LAB_0010268c:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// map_pcm_format @ 00102aec size=36
// signature: undefined map_pcm_format(void)
// callers: [handle_uaudio_stream_req]
//------------------------------------------------------------

undefined4 map_pcm_format(int param_1)

{
  if (param_1 - 1U < 0x11) {
    return *(undefined4 *)(&DAT_00106380 + (long)(int)(param_1 - 1U) * 4);
  }
  return 0;
}



//------------------------------------------------------------
// prepare_qmi_response @ 00102b10 size=3436
// signature: undefined prepare_qmi_response(void)
// callers: [handle_uaudio_stream_req]
//------------------------------------------------------------

ulong prepare_qmi_response(long param_1,long param_2,long param_3,int param_4)

{
  uint *puVar1;
  ulong *puVar2;
  byte *pbVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  byte bVar7;
  ushort uVar8;
  undefined2 uVar9;
  char cVar10;
  bool bVar11;
  uint uVar12;
  byte *pbVar13;
  byte *pbVar14;
  code *pcVar15;
  int iVar16;
  long *plVar17;
  ulong uVar18;
  undefined1 uVar19;
  long lVar20;
  ulong uVar21;
  byte *pbVar22;
  byte *pbVar23;
  undefined8 uVar24;
  long lVar25;
  char *pcVar26;
  undefined8 *puVar27;
  ulong uVar28;
  uint uVar29;
  ulong uVar30;
  ulong uVar31;
  uint uVar32;
  long lVar33;
  uint uVar34;
  ulong local_a8;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar20 = sp_el0;
  local_68 = *(long *)(lVar20 + 0x638);
  local_78 = 0;
  local_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  plVar17 = (long *)usb_ifnum_to_if(*(undefined8 *)(param_1 + 8),
                                    *(undefined1 *)(*(long *)(param_1 + 0x20) + 0x28));
  if (plVar17 == (long *)0x0) {
    pcVar26 = "%s%s: interface # %d does not exist\n";
    ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: interface # %d does not exist\n",
                   &DAT_00106b2d,"prepare_qmi_response",
                   *(undefined1 *)(*(long *)(param_1 + 0x20) + 0x28));
    uVar29 = (uint)*(byte *)(*(long *)(param_1 + 0x20) + 0x28);
LAB_00102fd8:
    _printk(pcVar26,&DAT_00106770,"prepare_qmi_response",uVar29);
    uVar28 = 0xffffffed;
    goto LAB_001036f0;
  }
  lVar20 = *(long *)(param_1 + 0x20);
  lVar33 = *plVar17;
  uVar28 = (ulong)*(byte *)(lVar20 + 0x2b);
  uVar4 = *(uint *)(param_2 + 4);
  uVar34 = *(uint *)(param_2 + 0x24);
  puVar27 = (undefined8 *)(lVar33 + uVar28 * 0x28);
  bVar7 = *(byte *)((long)puVar27 + 7);
  uVar29 = (uint)bVar7;
  if (bVar7 != 0x30) {
    lVar25 = lVar33 + uVar28 * 0x28;
    pbVar23 = *(byte **)(lVar25 + 0x10);
    pbVar3 = pbVar23 + *(int *)(lVar25 + 0xc);
    do {
      pbVar22 = pbVar23;
      if ((pbVar3 <= pbVar22) ||
         (pbVar23 = pbVar22 + *pbVar22, (ulong)*pbVar22 < 2 || pbVar3 < pbVar23)) goto LAB_00102d90;
    } while ((pbVar22[1] != 0x24) || (pbVar22[2] != 2));
    if (pbVar22 != (byte *)0x0) goto LAB_00102bfc;
LAB_00102d90:
    uVar19 = *(undefined1 *)(lVar20 + 0x28);
    pcVar26 = "%s%s: %u:%d : no UAC_FORMAT_TYPE desc\n";
LAB_00102da0:
    ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),pcVar26,&DAT_00106b2d,"prepare_qmi_response",
                   uVar19,uVar28);
    _printk(pcVar26,&DAT_00106770,"prepare_qmi_response",
            *(undefined1 *)(*(long *)(param_1 + 0x20) + 0x28),
            *(undefined1 *)(*(long *)(param_1 + 0x20) + 0x2b));
    uVar28 = 0xffffffed;
    goto LAB_001036f0;
  }
  pbVar22 = (byte *)0x0;
LAB_00102bfc:
  if (0x1fffff < uVar4) {
                    /* WARNING: Does not return */
    pcVar15 = (code *)SoftwareBreakpoint(0x5512,0x10384c);
    (*pcVar15)();
  }
  uVar12 = uVar4 >> 0x10;
  uVar31 = (ulong)uVar12;
  if (0xa00 < (uVar31 * 0x50 | 8)) goto LAB_00103844;
  lVar25 = *(long *)(uadev + uVar31 * 0x50 + 8);
  if (lVar25 == 0) {
    pcVar26 = "%s%s: audio ctrl intf info not cached\n";
LAB_00103448:
    ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),pcVar26,&DAT_00106b2d,"prepare_qmi_response");
    _printk(pcVar26,&DAT_00106770,"prepare_qmi_response");
    uVar28 = 0xffffffed;
    goto LAB_001036f0;
  }
  if (bVar7 == 0x30) {
LAB_00102c40:
    if (*(char *)(plVar17[3] + 5) == '\x01') {
      ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: full adc is not supported\n",
                     &DAT_00106b2d,"prepare_qmi_response");
      _printk("%s%s: full adc is not supported\n",&DAT_00106770,"prepare_qmi_response");
    }
    uVar8 = *(ushort *)(*(long *)(lVar33 + uVar28 * 0x28 + 0x18) + 4);
    uVar19 = 2;
    if (uVar8 < 0xc0) {
      if (uVar8 < 0x90) {
        if ((uVar8 == 0x60) || (uVar8 == 0x62)) goto LAB_00102e28;
      }
      else if ((uVar8 == 0x90) || (uVar8 == 0x93)) goto LAB_00102e24;
    }
    else if (uVar8 < 0x120) {
      if ((uVar8 == 0xc0) || (uVar8 == 0xc4)) goto LAB_00102e28;
    }
    else if ((uVar8 == 0x126) || (uVar8 == 0x120)) {
LAB_00102e24:
      uVar19 = 3;
LAB_00102e28:
      *(undefined1 *)(param_3 + 0x4d) = uVar19;
      *(undefined1 *)(param_3 + 0x4c) = 1;
      goto LAB_00102e34;
    }
    ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: %d: %u: Invalid wMaxPacketSize\n",
                   &DAT_00106b2d,"prepare_qmi_response",
                   *(undefined1 *)(*(long *)(param_1 + 0x20) + 0x28),
                   *(undefined1 *)(*(long *)(param_1 + 0x20) + 0x2b));
    _printk("%s%s: %d: %u: Invalid wMaxPacketSize\n",&DAT_00106770,"prepare_qmi_response",
            *(undefined1 *)(*(long *)(param_1 + 0x20) + 0x28),
            *(undefined1 *)(*(long *)(param_1 + 0x20) + 0x2b));
    uVar28 = 0xffffffea;
    goto LAB_001036f0;
  }
  pbVar3 = *(byte **)(lVar25 + 0x10) + *(int *)(lVar25 + 0xc);
  pbVar23 = *(byte **)(lVar25 + 0x10);
  do {
    pbVar13 = pbVar23;
    if ((pbVar3 <= pbVar13) ||
       (pbVar23 = pbVar13 + *pbVar13, (ulong)*pbVar13 < 2 || pbVar3 < pbVar23)) goto LAB_00102df0;
  } while ((pbVar13[1] != 0x24) || (pbVar13[2] != 1));
  if (pbVar13 == (byte *)0x0) {
LAB_00102df0:
    pcVar26 = "%s%s: no UAC_HEADER desc\n";
    goto LAB_00103448;
  }
  if (bVar7 == 0x30) goto LAB_00102c40;
  if (bVar7 == 0x20) {
    *(byte *)(param_3 + 0x4d) = pbVar22[4];
    *(undefined1 *)(param_3 + 0x4c) = 1;
    uVar9 = *(undefined2 *)(pbVar13 + 3);
    *(undefined1 *)(param_3 + 0x46) = 1;
    *(undefined2 *)(param_3 + 0x48) = uVar9;
  }
  else {
    if (bVar7 != 0) {
      ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: unknown protocol version %x\n",
                     &DAT_00106b2d,"prepare_qmi_response",bVar7);
      pcVar26 = "%s%s: unknown protocol version %x\n";
      goto LAB_00102fd8;
    }
    lVar33 = lVar33 + uVar28 * 0x28;
    pbVar23 = *(byte **)(lVar33 + 0x10);
    pbVar3 = pbVar23 + *(int *)(lVar33 + 0xc);
    do {
      pbVar14 = pbVar23;
      if ((pbVar3 <= pbVar14) ||
         (pbVar23 = pbVar14 + *pbVar14, (ulong)*pbVar14 < 2 || pbVar3 < pbVar23)) goto LAB_00102ff4;
    } while ((pbVar14[1] != 0x24) || (pbVar14[2] != 1));
    if (pbVar14 == (byte *)0x0) {
LAB_00102ff4:
      uVar19 = *(undefined1 *)(lVar20 + 0x28);
      pcVar26 = "%s%s: %u:%d : no UAC_AS_GENERAL desc\n";
      goto LAB_00102da0;
    }
    *(byte *)(param_3 + 0x4b) = pbVar14[4];
    *(undefined1 *)(param_3 + 0x4a) = 1;
    bVar7 = pbVar22[5];
    *(undefined1 *)(param_3 + 0x4c) = 1;
    *(byte *)(param_3 + 0x4d) = bVar7;
    uVar9 = *(undefined2 *)(pbVar13 + 3);
    *(undefined1 *)(param_3 + 0x46) = 1;
    *(undefined2 *)(param_3 + 0x48) = uVar9;
  }
LAB_00102e34:
  uVar5 = *(undefined4 *)(*(long *)(param_1 + 8) + 0x5d8);
  *(undefined1 *)(param_3 + 0x14) = 1;
  *(undefined4 *)(param_3 + 0x18) = uVar5;
  uVar19 = *(undefined1 *)(puVar27 + 1);
  uVar24 = *puVar27;
  *(undefined1 *)(param_3 + 0x24) = 1;
  *(undefined1 *)(param_3 + 0x2d) = uVar19;
  *(undefined8 *)(param_3 + 0x25) = uVar24;
  uVar29 = *(uint *)(*(long *)(param_1 + 0x68) + 0x15d0);
  lVar20 = *(long *)(param_1 + 8) + 0x4e8;
  if ((uVar29 & 0x80) != 0) {
    lVar20 = *(long *)(param_1 + 8) + 0x468;
  }
  puVar27 = *(undefined8 **)(lVar20 + ((ulong)(uVar29 >> 0xf) & 0xf) * 8);
  if (puVar27 == (undefined8 *)0x0) {
    pcVar26 = "%s%s: data ep # %d context is null\n";
    ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: data ep # %d context is null\n",
                   &DAT_00106b2d,"prepare_qmi_response",
                   *(undefined4 *)(*(long *)(param_1 + 0x68) + 0x20));
    uVar29 = *(uint *)(*(long *)(param_1 + 0x68) + 0x20);
    goto LAB_00102fd8;
  }
  uVar19 = *(undefined1 *)(puVar27 + 1);
  uVar24 = *puVar27;
  *(undefined1 *)(param_3 + 0x2e) = 1;
  *(undefined1 *)(param_3 + 0x38) = uVar19;
  *(undefined8 *)(param_3 + 0x30) = uVar24;
  lVar20 = xhci_get_xfer_ring_phys_addr(*(undefined8 *)(param_1 + 8),puVar27,&local_78);
  if (lVar20 == 0) {
    pcVar26 = "%s%s: failed to get data ep ring dma address\n";
    goto LAB_00103448;
  }
  *(undefined8 *)(param_3 + 0x70) = local_78;
  if (*(long *)(param_1 + 0x70) == 0) {
LAB_0010309c:
    lVar33 = 0;
    uVar32 = 0;
  }
  else {
    uVar32 = *(uint *)(*(long *)(param_1 + 0x70) + 0x15d0);
    lVar33 = *(long *)(param_1 + 8) + 0x4e8;
    if ((uVar32 & 0x80) != 0) {
      lVar33 = *(long *)(param_1 + 8) + 0x468;
    }
    puVar27 = *(undefined8 **)(lVar33 + ((ulong)(uVar32 >> 0xf) & 0xf) * 8);
    if (puVar27 == (undefined8 *)0x0) {
      ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: implicit fb on data ep\n",
                     &DAT_00106b2d,"prepare_qmi_response");
      _printk("%s%s: implicit fb on data ep\n",&DAT_001073a9,"prepare_qmi_response");
      goto LAB_0010309c;
    }
    uVar24 = *puVar27;
    *(undefined1 *)(param_3 + 0x44) = *(undefined1 *)(puVar27 + 1);
    *(undefined8 *)(param_3 + 0x3c) = uVar24;
    *(undefined1 *)(param_3 + 0x3a) = 1;
    lVar33 = xhci_get_xfer_ring_phys_addr(*(undefined8 *)(param_1 + 8),puVar27,&local_78);
    if (lVar33 == 0) {
      pcVar26 = "%s%s: failed to get sync ep ring dma address\n";
      goto LAB_00103448;
    }
    *(undefined8 *)(param_3 + 0x88) = local_78;
  }
  uVar5 = *(undefined4 *)(uaudio_qdev + 0xc);
  *(undefined1 *)(param_3 + 200) = 1;
  *(undefined1 *)(param_3 + 0xd0) = 0;
  *(char *)(param_3 + 0xc9) = (char)uVar5;
  lVar25 = *(long *)(*(long *)(*(long *)(param_1 + 8) + 0x50) + 8);
  if (((lVar25 != 0) && (lVar25 = *(long *)(lVar25 + 0x2e8), lVar25 != 0)) &&
     (iVar16 = of_alias_get_id(lVar25,&DAT_00107188), -1 < iVar16)) {
    *(char *)(param_3 + 0xd1) = (char)iVar16;
    *(undefined1 *)(param_3 + 0xd0) = 1;
  }
  bVar7 = *(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 8) + 0x50) + 8) + 0x34c);
  uVar28 = xhci_sec_event_ring_setup(*(long *)(param_1 + 8),*(undefined1 *)(param_3 + 0xc9));
  *(ulong *)(uaudio_qdev + 0x10) = uVar28;
  if (0xfffffffffffff000 < uVar28) {
    ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),
                   "%s%s: failed to setup sec event ring ret %d\n",&DAT_00106b2d,
                   "prepare_qmi_response",uVar28 & 0xffffffff);
    _printk("%s%s: failed to setup sec event ring ret %d\n",&DAT_00106770,"prepare_qmi_response",
            uVar28 & 0xffffffff);
    goto LAB_001036f0;
  }
  lVar25 = xhci_get_sec_event_ring_phys_addr(*(undefined8 *)(param_1 + 8),uVar28,&local_78);
  if (lVar25 == 0) {
    ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),
                   "%s%s: failed to get sec event ring dma address\n",&DAT_00106b2d,
                   "prepare_qmi_response");
    _printk("%s%s: failed to get sec event ring dma address\n",&DAT_00106770,"prepare_qmi_response")
    ;
    uVar28 = 0xffffffed;
  }
  else {
    bVar7 = bVar7 >> 5 & 1;
    uVar28 = uaudio_iommu_map(0,bVar7,lVar25,0x1000,0);
    lVar25 = uaudio_qdev;
    if (uVar28 == 0) {
      uVar28 = 0xfffffff4;
    }
    else {
      uVar6 = *(uint *)(uaudio_qdev + 8);
      *(undefined4 *)(param_3 + 0x60) = 0x1000;
      *(ulong *)(param_3 + 0x50) = uVar28 | (ulong)uVar6 << 0x20;
      *(undefined8 *)(param_3 + 0x58) = local_78;
      *(undefined1 *)(lVar25 + 0x68) = 1;
      iVar16 = *(int *)(*(long *)(param_1 + 8) + 0x1c);
      uVar6 = iVar16 - 1;
      if ((uVar6 < 6) && ((0x37U >> (ulong)(uVar6 & 0x1f) & 1) != 0)) {
        uVar5 = *(undefined4 *)(&DAT_001063c4 + (long)(int)uVar6 * 4);
        *(undefined1 *)(param_3 + 0xca) = 1;
        *(undefined4 *)(param_3 + 0xcc) = uVar5;
        uVar28 = uaudio_iommu_map(1,bVar7,lVar20,0x1000,0);
        if (uVar28 != 0) {
          uVar6 = *(uint *)(uaudio_qdev + 8);
          *(undefined4 *)(param_3 + 0x78) = 0x1000;
          *(ulong *)(param_3 + 0x68) = uVar28 | (ulong)uVar6 << 0x20;
          if (*(long *)(param_3 + 0x88) == 0) {
            local_a8 = 0;
LAB_0010324c:
            uVar6 = 0x1000;
            if (uVar34 != 0) {
              uVar6 = uVar34;
            }
            uVar34 = (uVar6 & 0xfffff000) + (uint)((uVar6 & 0xfff) != 0) * 0x1000;
            if (0x18000 < uVar34) {
              ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),
                             "%s%s: req buf len %d > max buf len %lu, setting %lu\n",&DAT_00106b2d,
                             "prepare_qmi_response",uVar34,0x18000,0x18000);
              _printk("%s%s: req buf len %d > max buf len %lu, setting %lu\n",&DAT_00106770,
                      "prepare_qmi_response",uVar34,0x18000,0x18000);
              uVar34 = 0x18000;
            }
            uVar30 = (ulong)uVar34;
            lVar20 = usb_alloc_coherent(*(undefined8 *)(param_1 + 8),uVar30,0xcc0,&local_70);
            if (lVar20 != 0) {
              dma_get_sgtable_attrs
                        (*(undefined8 *)(*(long *)(*(long *)(param_1 + 8) + 0x50) + 8),&local_88,
                         lVar20,local_70,uVar30,0);
              uVar18 = uaudio_iommu_map(2,bVar7,local_70,uVar30,&local_88);
              if (uVar18 != 0) {
                *(uint *)(param_3 + 0xa8) = uVar34;
                lVar33 = uaudio_qdev;
                *(undefined8 *)(param_3 + 0xa0) = local_70;
                uVar34 = *(uint *)(lVar33 + 8);
                *(undefined1 *)(param_3 + 0x4e) = 1;
                *(ulong *)(param_3 + 0x98) = uVar18 | (ulong)uVar34 << 0x20;
                sg_free_table(&local_88);
                puVar1 = (uint *)(uadev + uVar31 * 0x50 + 0x1c);
                if (*(int *)(uadev + uVar31 * 0x50 + 0x18) != 0) {
                  Hint_Prefetch(puVar1,2,0,1);
                  do {
                    uVar34 = *puVar1;
                    cVar10 = '\x01';
                    bVar11 = (bool)ExclusiveMonitorPass(puVar1,0x10);
                    if (bVar11) {
                      *puVar1 = uVar34 + 1;
                      cVar10 = ExclusiveMonitorsStatus();
                    }
                  } while (cVar10 != '\0');
                  if (uVar34 == 0) {
                    uVar24 = 2;
LAB_0010388c:
                    refcount_warn_saturate(puVar1,uVar24);
                  }
                  else if ((int)(uVar34 + 1 | uVar34) < 0) {
                    uVar24 = 1;
                    goto LAB_0010388c;
                  }
LAB_00103548:
                  uVar21 = uVar31 * 0x50;
                  if (((0x9f0 < uVar21) ||
                      (*(uint *)(uadev + uVar21 + 0x10) = uVar12, 0x9ec < uVar21)) ||
                     (*(uint *)(uadev + uVar31 * 0x50 + 0x14) = (uint)*(byte *)(param_3 + 0xd1),
                     0x9c0 < uVar31 * 0x50)) {
LAB_00103844:
                    /* WARNING: Does not return */
                    pcVar15 = (code *)SoftwareBreakpoint(1,0x103848);
                    (*pcVar15)();
                  }
                  lVar33 = uVar31 * 0x50;
                  *(ulong *)(*(long *)(uadev + lVar33 + 0x40) + (long)param_4 * 0x50) = uVar28;
                  *(undefined8 *)(*(long *)(uadev + lVar33 + 0x40) + (long)param_4 * 0x50 + 8) =
                       0x1000;
                  *(ulong *)(*(long *)(uadev + lVar33 + 0x40) + (long)param_4 * 0x50 + 0x10) =
                       local_a8;
                  *(undefined8 *)(*(long *)(uadev + lVar33 + 0x40) + (long)param_4 * 0x50 + 0x18) =
                       0x1000;
                  *(ulong *)(*(long *)(uadev + lVar33 + 0x40) + (long)param_4 * 0x50 + 0x20) =
                       uVar18;
                  *(undefined8 *)(*(long *)(uadev + lVar33 + 0x40) + (long)param_4 * 0x50 + 0x30) =
                       local_70;
                  *(ulong *)(*(long *)(uadev + lVar33 + 0x40) + (long)param_4 * 0x50 + 0x28) =
                       uVar30;
                  *(uint *)(*(long *)(uadev + lVar33 + 0x40) + (long)param_4 * 0x50 + 0x38) = uVar29
                  ;
                  *(uint *)(*(long *)(uadev + lVar33 + 0x40) + (long)param_4 * 0x50 + 0x3c) = uVar32
                  ;
                  *(long *)(*(long *)(uadev + lVar33 + 0x40) + (long)param_4 * 0x50 + 0x40) = lVar20
                  ;
                  *(char *)(*(long *)(uadev + lVar33 + 0x40) + (long)param_4 * 0x50 + 0x49) =
                       (char)(uVar4 >> 0x10);
                  *(char *)(*(long *)(uadev + lVar33 + 0x40) + (long)param_4 * 0x50 + 0x4a) =
                       (char)(uVar4 >> 8);
                  *(char *)(*(long *)(uadev + lVar33 + 0x40) + (long)param_4 * 0x50 + 0x4b) =
                       (char)*(undefined4 *)(param_1 + 0x18);
                  *(undefined1 *)(*(long *)(uadev + lVar33 + 0x40) + (long)param_4 * 0x50 + 0x48) =
                       *(undefined1 *)(*(long *)(param_1 + 0x20) + 0x28);
                  *(undefined1 *)(*(long *)(uadev + lVar33 + 0x40) + (long)param_4 * 0x50 + 0x4c) =
                       1;
                  puVar2 = (ulong *)(uaudio_qdev + 0x60);
                  Hint_Prefetch(puVar2,2,0,1);
                  do {
                    cVar10 = '\x01';
                    bVar11 = (bool)ExclusiveMonitorPass(puVar2,0x10);
                    if (bVar11) {
                      *puVar2 = *puVar2 | 1L << (uVar31 & 0x3f);
                      cVar10 = ExclusiveMonitorsStatus();
                    }
                  } while (cVar10 != '\0');
                  uVar28 = 0;
                  goto LAB_001036f0;
                }
                uVar21 = uVar31 * 0x50;
                *puVar1 = 1;
                __init_waitqueue_head
                          (uVar21 + 0x107590,"&uadev[card_num].disconnect_wq",
                           &prepare_qmi_response___key);
                if (0x9c8 < uVar21) goto LAB_00103844;
                bVar7 = *(byte *)(*(long *)(*(long *)(param_1 + 8) + 0x458) + 4);
                *(uint *)(uadev + uVar21 + 0x38) = (uint)bVar7;
                lVar33 = __kmalloc((ulong)bVar7 * 0x50,0xdc0);
                if (0x9c0 < uVar21) goto LAB_00103844;
                *(long *)(uadev + uVar31 * 0x50 + 0x40) = lVar33;
                if (lVar33 != 0) {
                  if ((0xa00 < uVar31 * 0x50) || (uVar12 == 0x20)) goto LAB_00103844;
                  *(undefined8 *)(uadev + uVar31 * 0x50) = *(undefined8 *)(param_1 + 8);
                  *(int *)(uadev + uVar31 * 0x50 + 0x18) = 1;
                  goto LAB_00103548;
                }
              }
            }
            usb_free_coherent(*(undefined8 *)(param_1 + 8),uVar30,lVar20,local_70);
            uaudio_iommu_unmap(1,local_a8,0x1000,0x1000);
          }
          else {
            local_a8 = uaudio_iommu_map(1,bVar7,lVar33,0x1000,0);
            if (local_a8 != 0) {
              uVar6 = *(uint *)(uaudio_qdev + 8);
              *(undefined4 *)(param_3 + 0x90) = 0x1000;
              *(ulong *)(param_3 + 0x80) = local_a8 | (ulong)uVar6 << 0x20;
              goto LAB_0010324c;
            }
          }
          uaudio_iommu_unmap(1,uVar28,0x1000,0x1000);
        }
        uVar28 = 0xfffffff4;
      }
      else {
        ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: udev speed %d\n",&DAT_00106b2d,
                       "get_speed_info",iVar16);
        _printk("%s%s: udev speed %d\n",&DAT_00106770,"get_speed_info",iVar16);
        uVar28 = 0xffffffed;
        *(undefined4 *)(param_3 + 0xcc) = 0;
      }
      uaudio_iommu_unmap(0,0x1000,0x1000,0x1000);
    }
  }
  xhci_sec_event_ring_cleanup(*(undefined8 *)(param_1 + 8),*(undefined8 *)(uaudio_qdev + 0x10));
LAB_001036f0:
  lVar20 = sp_el0;
  if (*(long *)(lVar20 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar28 & 0xffffffff;
}



//------------------------------------------------------------
// disable_audio_stream @ 0010389c size=112
// signature: undefined disable_audio_stream(void)
// callers: [handle_uaudio_stream_req]
//------------------------------------------------------------

void disable_audio_stream(undefined8 *param_1)

{
  long lVar1;
  
  lVar1 = *(long *)*param_1;
  if ((param_1[0xd] != 0) || (param_1[0xe] != 0)) {
    close_endpoints(lVar1,param_1);
    mutex_lock(lVar1 + 0xa0);
    param_1[4] = 0;
    mutex_unlock(lVar1 + 0xa0);
  }
  snd_usb_autosuspend(lVar1);
  return;
}



//------------------------------------------------------------
// uaudio_dev_intf_cleanup @ 0010390c size=300
// signature: undefined uaudio_dev_intf_cleanup(void)
// callers: [handle_uaudio_stream_req, uaudio_dev_cleanup]
//------------------------------------------------------------

void uaudio_dev_intf_cleanup(undefined8 param_1,undefined8 *param_2)

{
  if (param_2 == (undefined8 *)0x0) {
    ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: info is NULL\n",&DAT_00106b2d,
                   "uaudio_dev_intf_cleanup");
    _printk("%s%s: info is NULL\n",&DAT_00106770,"uaudio_dev_intf_cleanup");
  }
  else {
    uaudio_iommu_unmap(1,*param_2,param_2[1],param_2[1]);
    *param_2 = 0;
    param_2[1] = 0;
    uaudio_iommu_unmap(1,param_2[2],param_2[3],param_2[3]);
    param_2[2] = 0;
    param_2[3] = 0;
    uaudio_iommu_unmap(2,param_2[4],param_2[5],param_2[5]);
    param_2[4] = 0;
    usb_free_coherent(param_1,param_2[5],param_2[8],param_2[6]);
    param_2[8] = 0;
    *(undefined1 *)((long)param_2 + 0x4c) = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: release resources: intf# %d card# %d\n"
                   ,&DAT_00106b2d,"uaudio_dev_intf_cleanup",*(undefined1 *)(param_2 + 9),
                   *(undefined1 *)((long)param_2 + 0x49));
    _printk("%s%s: release resources: intf# %d card# %d\n",&DAT_001073a9,"uaudio_dev_intf_cleanup",
            *(undefined1 *)(param_2 + 9),*(undefined1 *)((long)param_2 + 0x49));
  }
  return;
}



//------------------------------------------------------------
// close_endpoints @ 00103a38 size=152
// signature: undefined close_endpoints(void)
// callers: [disable_audio_stream, enable_audio_stream, uaudio_qmi_disconnect_work]
//------------------------------------------------------------

void close_endpoints(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = param_1 + 0xa0;
  mutex_lock(lVar1);
  if (*(long *)(param_2 + 0x68) != 0) {
    *(undefined8 *)(*(long *)(param_2 + 0x68) + 0x48) = 0;
    mutex_unlock(lVar1);
    snd_usb_endpoint_close(param_1,*(undefined8 *)(param_2 + 0x68));
    mutex_lock(lVar1);
    *(undefined8 *)(param_2 + 0x68) = 0;
  }
  if (*(long *)(param_2 + 0x70) != 0) {
    mutex_unlock(lVar1);
    snd_usb_endpoint_close(param_1,*(undefined8 *)(param_2 + 0x70));
    mutex_lock(lVar1);
    *(undefined8 *)(param_2 + 0x70) = 0;
  }
  mutex_unlock(lVar1);
  return;
}



//------------------------------------------------------------
// configure_endpoints @ 00103ad0 size=196
// signature: undefined configure_endpoints(void)
// callers: [enable_audio_stream]
//------------------------------------------------------------

int configure_endpoints(undefined8 param_1,long param_2)

{
  int iVar1;
  char *pcVar2;
  
  if ((*(char *)(*(long *)(param_2 + 0x68) + 0x162e) == '\0') ||
     (iVar1 = snd_usb_endpoint_prepare(param_1), -1 < iVar1)) {
    if ((*(long *)(param_2 + 0x70) == 0) || (iVar1 = snd_usb_endpoint_prepare(param_1), -1 < iVar1))
    {
      return 0;
    }
    pcVar2 = "%s%s: failed to configure endpoint\n";
  }
  else {
    pcVar2 = "%s%s: failed to configure data endpoint\n";
  }
  ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),pcVar2,&DAT_00106b2d,"configure_endpoints");
  _printk(pcVar2,&DAT_00106770,"configure_endpoints");
  return iVar1;
}



//------------------------------------------------------------
// uaudio_iommu_map @ 00103b94 size=1176
// signature: undefined uaudio_iommu_map(void)
// callers: [prepare_qmi_response]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long uaudio_iommu_map(int param_1,ulong param_2,undefined8 param_3,long param_4,undefined8 *param_5)

{
  int iVar1;
  long lVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  ulong *puVar6;
  uint uVar7;
  ulong uVar8;
  long local_78;
  undefined8 local_70;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  uVar3 = 7;
  if ((param_2 & 1) == 0) {
    uVar3 = 3;
  }
  local_78 = 0;
  local_70 = param_3;
  if (param_1 == 2) {
    lVar4 = uaudio_qdev + 0x58;
    lVar5 = uaudio_qdev + 0x50;
    lVar2 = uaudio_qdev + 0x40;
LAB_00103c4c:
    lVar4 = uaudio_get_iova(lVar4,lVar5,lVar2,param_4);
  }
  else {
    if (param_1 == 1) {
      lVar4 = uaudio_qdev + 0x38;
      lVar5 = uaudio_qdev + 0x30;
      lVar2 = uaudio_qdev + 0x20;
      goto LAB_00103c4c;
    }
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: unknown mem type %d\n",&DAT_00106b2d,
                     "uaudio_iommu_map",param_1);
      _printk("%s%s: unknown mem type %d\n",&DAT_00106770,"uaudio_iommu_map",param_1);
      lVar4 = 0;
      goto LAB_00103d80;
    }
    lVar4 = 0x1000;
    if (*(char *)(uaudio_qdev + 0x68) != '\0') goto LAB_00103d80;
  }
  if (lVar4 != 0) {
    if (param_5 == (undefined8 *)0x0) {
      ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),
                     "%s%s: type:%d map pa:%pa to iova:0x%08lx size:%zu\n",&DAT_00106b2d,
                     "uaudio_iommu_map",param_1,&local_70,lVar4,param_4);
      _printk("%s%s: type:%d map pa:%pa to iova:0x%08lx size:%zu\n",&DAT_001073a9,"uaudio_iommu_map"
              ,param_1,&local_70,lVar4,param_4);
      iVar1 = iommu_map(*(undefined8 *)(uaudio_qdev + 0x18),lVar4,local_70,param_4,uVar3);
      if (iVar1 != 0) {
        ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),
                       "%s%s: failed to map pa:%pa iova:0x%lx type:%d ret:%d\n",&DAT_00106b2d,
                       "uaudio_iommu_map",&local_70,lVar4,param_1,iVar1);
        _printk("%s%s: failed to map pa:%pa iova:0x%lx type:%d ret:%d\n",&DAT_00106770,
                "uaudio_iommu_map",&local_70,lVar4,param_1,iVar1);
      }
    }
    else {
      if (*(int *)(param_5 + 1) == 0) {
        lVar5 = 0;
      }
      else {
        uVar7 = 0;
        lVar5 = 0;
        puVar6 = (ulong *)*param_5;
        lVar2 = lVar4;
        do {
          uVar8 = (ulong)((int)puVar6[1] + *(int *)((long)puVar6 + 0xc) + 0xfffU & 0xfffff000);
          local_78 = ((*puVar6 & 0x3fffffffffffffc) + (_memstart_addr >> 0xc) * 0x40) * 0x40 +
                     0x8000000000;
          iVar1 = iommu_map(*(undefined8 *)(uaudio_qdev + 0x18),lVar2,local_78,uVar8,uVar3);
          if (iVar1 != 0) {
            ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: mapping failed ret%d\n",
                           &DAT_00106b2d,"uaudio_iommu_map",iVar1);
            _printk("%s%s: mapping failed ret%d\n",&DAT_00106770,"uaudio_iommu_map",iVar1);
            ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),
                           "%s%s: type:%d, pa:%pa iova:0x%08lx sg_len:%zu\n",&DAT_00106b2d,
                           "uaudio_iommu_map",param_1,&local_78,lVar2,uVar8);
            _printk("%s%s: type:%d, pa:%pa iova:0x%08lx sg_len:%zu\n",&DAT_00106770,
                    "uaudio_iommu_map",param_1,&local_78,lVar2,uVar8);
            goto LAB_00103fc4;
          }
          ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),
                         "%s%s: type:%d map pa:%pa to iova:0x%08lx len:%zu offset:%u\n",
                         &DAT_00106b2d,"uaudio_iommu_map",param_1,&local_78,lVar2,uVar8,
                         (int)puVar6[1]);
          _printk("%s%s: type:%d map pa:%pa to iova:0x%08lx len:%zu offset:%u\n",&DAT_001073a9,
                  "uaudio_iommu_map",param_1,&local_78,lVar2,uVar8,(int)puVar6[1]);
          lVar2 = lVar2 + uVar8;
          lVar5 = lVar5 + uVar8;
          uVar7 = uVar7 + 1;
          puVar6 = (ulong *)sg_next(puVar6);
        } while (uVar7 < *(uint *)(param_5 + 1));
      }
      if (lVar5 != param_4) {
        ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),
                       "%s%s: iova size %zu != mapped iova size %zu\n",&DAT_00106b2d,
                       "uaudio_iommu_map",param_4,lVar5);
        _printk("%s%s: iova size %zu != mapped iova size %zu\n",&DAT_00106770,"uaudio_iommu_map",
                param_4,lVar5);
LAB_00103fc4:
        uaudio_iommu_unmap(2,lVar4,param_4,lVar5);
        lVar4 = 0;
      }
    }
  }
LAB_00103d80:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar4;
}



//------------------------------------------------------------
// uaudio_iommu_unmap @ 0010402c size=460
// signature: undefined uaudio_iommu_unmap(void)
// callers: [uaudio_dev_intf_cleanup, prepare_qmi_response, uaudio_event_ring_cleanup_free, uaudio_iommu_map]
//------------------------------------------------------------

void uaudio_iommu_unmap(int param_1,long param_2,long param_3,long param_4)

{
  long lVar1;
  long lVar2;
  
  if (param_2 == 0) {
    return;
  }
  if (param_3 == 0) {
    return;
  }
  if (param_1 == 2) {
    lVar1 = uaudio_qdev + 0x40;
    lVar2 = uaudio_qdev + 0x50;
  }
  else {
    if (param_1 != 1) {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: unknown mem type %d\n",
                       &DAT_00106b2d,"uaudio_iommu_unmap",param_1);
        _printk("%s%s: unknown mem type %d\n",&DAT_00106770,"uaudio_iommu_unmap",param_1);
        return;
      }
      if (*(char *)(uaudio_qdev + 0x68) == '\0') {
        return;
      }
      *(undefined1 *)(uaudio_qdev + 0x68) = 0;
      goto LAB_001040b8;
    }
    lVar1 = uaudio_qdev + 0x20;
    lVar2 = uaudio_qdev + 0x30;
  }
  uaudio_put_iova(param_2,param_3,lVar1,lVar2);
LAB_001040b8:
  if (param_4 != 0) {
    ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: type %d: unmap iova 0x%08lx size %zu\n"
                   ,&DAT_00106b2d,"uaudio_iommu_unmap",param_1,param_2,param_4);
    _printk("%s%s: type %d: unmap iova 0x%08lx size %zu\n",&DAT_001073a9,"uaudio_iommu_unmap",
            param_1,param_2,param_4);
    lVar1 = iommu_unmap(*(undefined8 *)(uaudio_qdev + 0x18),param_2,param_4);
    if (lVar1 != param_4) {
      ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),
                     "%s%s: unmapped size %zu for iova 0x%08lx of mapped size %zu\n",&DAT_00106b2d,
                     "uaudio_iommu_unmap",lVar1,param_2,param_4);
      _printk("%s%s: unmapped size %zu for iova 0x%08lx of mapped size %zu\n",&DAT_00106770,
              "uaudio_iommu_unmap",lVar1,param_2,param_4);
    }
  }
  return;
}



//------------------------------------------------------------
// uaudio_get_iova @ 001041f8 size=916
// signature: undefined uaudio_get_iova(void)
// callers: [uaudio_iommu_map]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long uaudio_get_iova(long *param_1,ulong *param_2,long *param_3,ulong param_4)

{
  ulong uVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  
  if ((param_4 & 0xfff) == 0) {
    if (*param_2 < param_4) {
      ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: size %zu > curr size %zu\n",
                     &DAT_00106b2d,"uaudio_get_iova",param_4);
      _printk("%s%s: size %zu > curr size %zu\n",&DAT_00106770,"uaudio_get_iova",param_4,*param_2);
    }
    else if (*param_2 == 0) {
      ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: iova mapping is full\n",&DAT_00106b2d
                     ,"uaudio_get_iova");
      _printk("%s%s: iova mapping is full\n",&DAT_00106770,"uaudio_get_iova");
    }
    else {
      plVar5 = (long *)*param_3;
      if (plVar5 != param_3) {
        uVar1 = param_4;
        plVar4 = (long *)0x0;
        do {
          if ((char)plVar5[4] == '\0') {
            if (plVar5[3] == param_4) {
              lVar2 = plVar5[2];
              *(undefined1 *)(plVar5 + 4) = 1;
              *param_2 = *param_2 - param_4;
              ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: exact size: %zu found\n",
                             &DAT_00106b2d,"uaudio_get_iova",param_4);
              _printk("%s%s: exact size: %zu found\n",&DAT_001073a9,"uaudio_get_iova",param_4);
              goto LAB_00104530;
            }
            if (uVar1 < (ulong)plVar5[3]) goto LAB_001043d4;
            plVar3 = plVar5;
            if (plVar4 != (long *)0x0) {
              plVar3 = plVar4;
            }
            ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: partial size: %zu found\n",
                           &DAT_00106b2d,"uaudio_get_iova");
            _printk("%s%s: partial size: %zu found\n",&DAT_001073a9,"uaudio_get_iova",plVar5[3]);
            uVar1 = uVar1 - plVar5[3];
            if (uVar1 == 0) {
              lVar2 = plVar3[2];
              for (; plVar3 != plVar5; plVar3 = (long *)*plVar3) {
                *(undefined1 *)(plVar3 + 4) = 1;
              }
              *(undefined1 *)(plVar5 + 4) = 1;
              *param_2 = *param_2 - param_4;
              goto LAB_00104530;
            }
          }
          else {
LAB_001043d4:
            plVar3 = (long *)0x0;
            uVar1 = param_4;
          }
          plVar5 = (long *)*plVar5;
          plVar4 = plVar3;
        } while (plVar5 != param_3);
      }
      plVar5 = (long *)kmalloc_trace(_of_property_read_variable_u32_array,0xdc0,0x28);
      if (plVar5 != (long *)0x0) {
        lVar2 = *param_1;
        plVar5[2] = lVar2;
        plVar5[3] = param_4;
        *(undefined1 *)(plVar5 + 4) = 1;
        *param_1 = lVar2 + param_4;
        *param_2 = *param_2 - param_4;
        plVar4 = (long *)param_3[1];
        uVar1 = __list_add_valid(plVar5,plVar4,param_3);
        if ((uVar1 & 1) != 0) {
          param_3[1] = (long)plVar5;
          *plVar5 = (long)param_3;
          plVar5[1] = (long)plVar4;
          *plVar4 = (long)plVar5;
        }
LAB_00104530:
        ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),
                       "%s%s: va:0x%08lx curr_iova:0x%08lx curr_iova_size:%zu\n",&DAT_00106b2d,
                       "uaudio_get_iova",lVar2,*param_1,*param_2);
        _printk("%s%s: va:0x%08lx curr_iova:0x%08lx curr_iova_size:%zu\n",&DAT_001073a9,
                "uaudio_get_iova",lVar2,*param_1,*param_2);
        return lVar2;
      }
    }
  }
  else {
    ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: size %zu is not page size multiple\n",
                   &DAT_00106b2d,"uaudio_get_iova",param_4);
    _printk("%s%s: size %zu is not page size multiple\n",&DAT_00106770,"uaudio_get_iova",param_4);
  }
  ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: unable to find %zu size iova\n",
                 &DAT_00106b2d,"uaudio_get_iova",param_4);
  _printk("%s%s: unable to find %zu size iova\n",&DAT_00106770,"uaudio_get_iova",param_4);
  return 0;
}



//------------------------------------------------------------
// uaudio_put_iova @ 0010458c size=356
// signature: undefined uaudio_put_iova(void)
// callers: [uaudio_iommu_unmap]
//------------------------------------------------------------

void uaudio_put_iova(long param_1,ulong param_2,long *param_3,long *param_4)

{
  ulong uVar1;
  undefined *puVar2;
  long *plVar3;
  ulong uVar4;
  bool bVar5;
  ulong uVar6;
  char *pcVar7;
  
  plVar3 = (long *)*param_3;
  if (plVar3 == param_3) {
LAB_001045b0:
    pcVar7 = "%s%s: unable to find the va %lu\n";
LAB_001045bc:
    ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),pcVar7,&DAT_00106b2d,"uaudio_put_iova",param_1
                  );
    puVar2 = &DAT_00106770;
  }
  else {
    bVar5 = false;
    uVar4 = param_2;
    do {
      if (plVar3[2] == param_1) {
LAB_00104660:
        if ((char)plVar3[4] == '\0') {
          pcVar7 = "%s%s: va %lu is not in use\n";
          goto LAB_001045bc;
        }
        uVar6 = plVar3[3];
        *(undefined1 *)(plVar3 + 4) = 0;
        if (uVar6 == param_2) break;
      }
      else {
        if (!bVar5) {
          do {
            plVar3 = (long *)*plVar3;
            if (plVar3 == param_3) goto LAB_001045b0;
          } while (plVar3[2] != param_1);
          goto LAB_00104660;
        }
        uVar6 = plVar3[3];
      }
      uVar1 = uVar4 - uVar6;
      if ((uVar6 <= uVar4) && (*(undefined1 *)(plVar3 + 4) = 0, uVar4 = uVar1, uVar1 == 0)) break;
      plVar3 = (long *)*plVar3;
      bVar5 = true;
    } while (plVar3 != param_3);
    *param_4 = *param_4 + param_2;
    ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: curr_iova_size %zu\n",&DAT_00106b2d,
                   "uaudio_put_iova");
    param_1 = *param_4;
    puVar2 = &DAT_001073a9;
    pcVar7 = "%s%s: curr_iova_size %zu\n";
  }
  _printk(pcVar7,puVar2,"uaudio_put_iova",param_1);
  return;
}



//------------------------------------------------------------
// uaudio_event_ring_cleanup_free @ 001046f0 size=216
// signature: undefined uaudio_event_ring_cleanup_free(void)
// callers: [handle_uaudio_stream_req, uaudio_dev_cleanup]
//------------------------------------------------------------

void uaudio_event_ring_cleanup_free(undefined8 *param_1)

{
  ulong *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  
  uVar2 = *(uint *)(param_1 + 2);
  puVar1 = (ulong *)(uaudio_qdev + 0x60 + (ulong)(uVar2 >> 6) * 8);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar4) {
      *puVar1 = *puVar1 & (1L << ((ulong)uVar2 & 0x3f) ^ 0xffffffffffffffffU);
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (*(long *)(uaudio_qdev + 0x60) == 0) {
    uaudio_iommu_unmap(0,0x1000,0x1000,0x1000);
    xhci_sec_event_ring_cleanup(*param_1,*(undefined8 *)(uaudio_qdev + 0x10));
    ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),"%s%s: all audio devices disconnected\n",
                   &DAT_00106b2d,"uaudio_event_ring_cleanup_free");
    _printk("%s%s: all audio devices disconnected\n",&DAT_001073a9,"uaudio_event_ring_cleanup_free")
    ;
  }
  return;
}



//------------------------------------------------------------
// uaudio_dev_cleanup @ 001047d0 size=228
// signature: undefined uaudio_dev_cleanup(void)
// callers: [uaudio_disconnect, uaudio_qmi_disconnect_work]
//------------------------------------------------------------

void uaudio_dev_cleanup(long *param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  if (*param_1 == 0) {
    ipc_log_string(*(undefined8 *)(uaudio_svc + 0x50),
                   "%s%s: USB audio device memory is already freed.\n",&DAT_00106b2d,
                   "uaudio_dev_cleanup");
    _printk("%s%s: USB audio device memory is already freed.\n",&DAT_001073a9,"uaudio_dev_cleanup");
  }
  else {
    iVar1 = (int)param_1[7];
    if (0 < iVar1) {
      lVar2 = 0;
      lVar3 = 0x4c;
      do {
        if (*(char *)(param_1[8] + lVar3) != '\0') {
          uaudio_dev_intf_cleanup(*param_1,param_1[8] + lVar3 + -0x4c);
          iVar1 = (int)param_1[7];
        }
        lVar2 = lVar2 + 1;
        lVar3 = lVar3 + 0x50;
      } while (lVar2 < iVar1);
    }
    *(undefined4 *)(param_1 + 7) = 0;
    kfree(param_1[8]);
    param_1[8] = 0;
    uaudio_event_ring_cleanup_free(param_1);
    *param_1 = 0;
  }
  return;
}



//------------------------------------------------------------
// xhci_sec_event_ring_setup @ 001048b8 size=680
// signature: undefined xhci_sec_event_ring_setup(void)
// callers: [prepare_qmi_response]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * xhci_sec_event_ring_setup(long param_1,uint param_2)

{
  undefined8 *puVar1;
  undefined **ppuVar2;
  long lVar3;
  undefined4 uVar4;
  long lVar5;
  int iVar6;
  undefined *puVar7;
  ulong uVar8;
  uint uVar9;
  long lVar10;
  undefined **ppuVar11;
  
  lVar10 = *(long *)(param_1 + 0x50);
  lVar3 = lVar10;
  if (*(long *)(lVar10 + 0x278) != 0) {
    lVar3 = *(long *)(lVar10 + 0x278);
  }
  if ((*(int *)(param_1 + 0x18) == 0) || ((*(byte *)(lVar10 + 0x198) >> 5 & 1) == 0)) {
    puVar7 = (undefined *)0xffffffffffffffed;
  }
  else {
    uVar9 = (uint)*(byte *)(lVar3 + 0x325);
    puVar1 = (undefined8 *)(lVar3 + 0x2d0);
    if (*(byte *)(lVar3 + 0x325) == 0) {
      uVar9 = *(uint *)(lVar3 + 0x308) >> 8;
      *(char *)(lVar3 + 0x325) = (char)(*(uint *)(lVar3 + 0x308) >> 8);
    }
    if (((*(uint *)(lVar3 + 0xcc8) >> 1 & 1) == 0) && (param_2 < (uVar9 & 0xff))) {
      for (ppuVar11 = (undefined **)xhci_sec; ppuVar11 != &xhci_sec;
          ppuVar11 = (undefined **)*ppuVar11) {
        if (((undefined8 *)ppuVar11[-2] == puVar1) && (*(uint *)(ppuVar11 + -1) == param_2)) {
          ppuVar11 = ppuVar11 + -9;
          goto LAB_00104abc;
        }
      }
      ppuVar11 = (undefined **)kmalloc_trace(_iommu_domain_alloc,0xdc0,0x58);
      if (ppuVar11 == (undefined **)0x0) {
        puVar7 = (undefined *)0xfffffffffffffff4;
      }
      else {
        *(uint *)(ppuVar11 + 8) = param_2;
        ppuVar11[7] = (undefined *)puVar1;
        lVar10 = *(long *)(lVar3 + 0x2f0);
        lVar3 = lVar10 + (ulong)param_2 * 0x20;
        ppuVar11[6] = (undefined *)(lVar3 + 0x20);
        puVar7 = (undefined *)xhci_ring_alloc(puVar1,1,1,6,0,0xcc0);
        *ppuVar11 = puVar7;
        if (puVar7 == (undefined *)0x0) {
          iVar6 = -0xc;
        }
        else {
          iVar6 = xhci_alloc_erst(puVar1,puVar7,ppuVar11 + 1,0xcc0);
          if (iVar6 == 0) {
            lVar10 = lVar10 + (ulong)param_2 * 0x20;
            uVar9 = readl_relaxed(lVar10 + 0x28);
            writel_relaxed(uVar9 & 0xffff0000 | 1,lVar10 + 0x28);
            uVar9 = readl(lVar10 + 0x30);
            readl(lVar3 + 0x34);
            uVar4 = *(undefined4 *)((long)ppuVar11 + 0x1c);
            writel(*(uint *)(ppuVar11 + 3) & 0xfffffff0 | uVar9 & 0xf,lVar10 + 0x30);
            writel(uVar4,lVar3 + 0x34);
            uVar8 = xhci_trb_virt_to_dma
                              (*(undefined8 *)(*ppuVar11 + 0x28),*(undefined8 *)(*ppuVar11 + 0x20));
            if ((uVar8 == 0) && (lVar5 = sp_el0, (*(uint *)(lVar5 + 0x10) & 0xffff00) == 0)) {
              _dev_warn(*(undefined8 *)*puVar1,
                        "intr# %d:WARN something wrong with SW event ring deq ptr.\n",param_2);
            }
            uVar9 = readl(lVar10 + 0x38);
            readl(lVar3 + 0x3c);
            writel((uint)uVar8 & 0xfffffff0 | uVar9 & 7,lVar10 + 0x38);
            writel(uVar8 >> 0x20,lVar3 + 0x3c);
            puVar7 = PTR_xhci_sec_00106148;
            ppuVar2 = ppuVar11 + 9;
            uVar8 = __list_add_valid(ppuVar2,PTR_xhci_sec_00106148,&xhci_sec);
            if ((uVar8 & 1) != 0) {
              PTR_xhci_sec_00106148 = (undefined *)ppuVar2;
              ppuVar11[9] = (undefined *)&xhci_sec;
              ppuVar11[10] = puVar7;
              *(undefined ***)puVar7 = ppuVar2;
            }
LAB_00104abc:
            return *ppuVar11;
          }
        }
        _dev_err(*(undefined8 *)*puVar1,"sec event ring setup failed inter#%d\n",param_2);
        kfree(ppuVar11);
        puVar7 = (undefined *)(long)iVar6;
      }
    }
    else {
      _dev_err(*(undefined8 *)*puVar1,"%s:state %x intr# %d\n","xhci_sec_event_ring_setup",
               *(uint *)(lVar3 + 0xcc8),param_2);
      puVar7 = (undefined *)0xffffffffffffffea;
    }
  }
  return puVar7;
}



//------------------------------------------------------------
// xhci_sec_event_ring_cleanup @ 00104b64 size=564
// signature: undefined xhci_sec_event_ring_cleanup(void)
// callers: [prepare_qmi_response, uaudio_event_ring_cleanup_free]
//------------------------------------------------------------

undefined8 xhci_sec_event_ring_cleanup(long param_1,undefined8 *param_2)

{
  long *plVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  long *plVar8;
  long lVar9;
  long lVar10;
  undefined **ppuVar11;
  undefined *puVar12;
  ulong uVar13;
  
  lVar9 = *(long *)(*(long *)(param_1 + 0x50) + 0x278);
  lVar7 = *(long *)(param_1 + 0x50);
  if (lVar9 != 0) {
    lVar7 = lVar9;
  }
  lVar9 = lVar7 + 0x31c;
  plVar1 = (long *)(lVar7 + 0x2d0);
  uVar4 = _raw_spin_lock_irqsave(lVar9);
  ppuVar11 = &xhci_sec;
  do {
    ppuVar11 = (undefined **)*ppuVar11;
    if (ppuVar11 == &xhci_sec) {
      _raw_spin_unlock_irqrestore(lVar9,uVar4);
      return 0;
    }
  } while ((undefined8 *)ppuVar11[-9] != param_2);
  uVar5 = __list_del_entry_valid(ppuVar11);
  if ((uVar5 & 1) != 0) {
    puVar12 = *ppuVar11;
    plVar8 = (long *)ppuVar11[1];
    *(long **)(puVar12 + 8) = plVar8;
    *plVar8 = (long)puVar12;
  }
  *ppuVar11 = (undefined *)0xdead000000000100;
  ppuVar11[1] = (undefined *)0xdead000000000122;
  _raw_spin_unlock_irqrestore(lVar9,uVar4);
  if ((*(byte *)(*plVar1 + 0x198) >> 5 & 1) != 0) {
    if (ppuVar11[-8] != (undefined *)0x0) {
      puVar12 = ppuVar11[-3];
      uVar4 = *(undefined8 *)(*plVar1 + 8);
      iVar2 = *(int *)(ppuVar11 + -7);
      uVar3 = readl_relaxed(puVar12);
      writel_relaxed(uVar3 & 0xfffffffd,puVar12);
      uVar5 = readl_relaxed(puVar12);
      if ((uVar5 & 1) != 0) {
        writel_relaxed(uVar5,puVar12);
      }
      uVar6 = readl(puVar12 + 0x18);
      lVar7 = readl(puVar12 + 0x1c);
      uVar13 = uVar6 & 0xffffffff | lVar7 << 0x20;
      uVar5 = uVar6 & 0xfffffff0 | lVar7 << 0x20;
      if (uVar5 != 0) {
        plVar8 = (long *)*param_2;
        lVar9 = *plVar8 + (uVar5 - plVar8[2] & 0xfffffffffffffff0);
        uVar3 = *(uint *)(lVar9 + 0xc) & 1;
        *(uint *)(param_2 + 8) = uVar3;
        lVar10 = *plVar8;
        lVar7 = lVar9;
        do {
          if (lVar7 == lVar10 + 0xff0) {
            uVar3 = uVar3 ^ 1;
            *(uint *)(param_2 + 8) = uVar3;
            lVar7 = *plVar8;
            lVar10 = lVar7;
          }
          else {
            lVar7 = lVar7 + 0x10;
          }
        } while ((*(uint *)(lVar7 + 0xc) & 1) == uVar3);
        if (lVar9 != lVar7) {
          uVar5 = xhci_trb_virt_to_dma(param_2[5]);
          if (uVar5 == 0) {
            _dev_warn(*(undefined8 *)*plVar1,"WARN invalid SW event ring dequeue ptr.\n");
          }
          uVar13 = uVar5 & 0xfffffffffffffff0 | uVar6 & 0xf;
        }
        writel((uint)uVar13 | 8,puVar12 + 0x18);
        writel(uVar13 >> 0x20,puVar12 + 0x1c);
      }
      dma_free_attrs(uVar4,(long)(iVar2 << 4),ppuVar11[-8],ppuVar11[-6],0);
      ppuVar11[-8] = (undefined *)0x0;
    }
    xhci_ring_free(plVar1,param_2);
  }
  kfree(ppuVar11 + -9);
  return 0;
}



//------------------------------------------------------------
// xhci_get_sec_event_ring_phys_addr @ 00104d9c size=264
// signature: undefined xhci_get_sec_event_ring_phys_addr(void)
// callers: [prepare_qmi_response]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long xhci_get_sec_event_ring_phys_addr(long param_1,long *param_2,undefined8 *param_3)

{
  long lVar1;
  undefined **ppuVar2;
  long lVar3;
  ulong *local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  lVar1 = *(long *)(param_1 + 0x50);
  local_38 = (ulong *)0x0;
  uStack_30 = 0;
  lVar3 = lVar1;
  if (*(long *)(lVar1 + 0x278) != 0) {
    lVar3 = *(long *)(lVar1 + 0x278);
  }
  if (((*(int *)(param_1 + 0x18) == 0) || ((*(byte *)(lVar1 + 0x198) >> 5 & 1) == 0)) ||
     ((*(byte *)(lVar3 + 0xcc8) >> 1 & 1) != 0)) {
LAB_00104e70:
    lVar3 = 0;
  }
  else {
    ppuVar2 = &xhci_sec;
    do {
      ppuVar2 = (undefined **)*ppuVar2;
      if (ppuVar2 == &xhci_sec) goto LAB_00104e70;
    } while ((long *)ppuVar2[-9] != param_2);
    dma_get_sgtable_attrs
              (*(undefined8 *)(lVar1 + 8),&local_38,*(undefined8 *)*param_2,
               ((undefined8 *)*param_2)[2],0x1000,0);
    *param_3 = *(undefined8 *)(*param_2 + 0x10);
    lVar3 = ((*local_38 & 0x3fffffffffffffc) + (_memstart_addr >> 0xc) * 0x40) * 0x40 + 0x8000000000
    ;
    sg_free_table(&local_38);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3;
}



//------------------------------------------------------------
// xhci_get_xfer_ring_phys_addr @ 00104ea8 size=368
// signature: undefined xhci_get_xfer_ring_phys_addr(void)
// callers: [prepare_qmi_response]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long xhci_get_xfer_ring_phys_addr(long param_1,long param_2,undefined8 *param_3)

{
  code *pcVar1;
  uint uVar2;
  undefined8 *puVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  ulong *local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  lVar4 = *(long *)(param_1 + 0x50);
  uVar6 = *(undefined8 *)(lVar4 + 8);
  local_48 = (ulong *)0x0;
  uStack_40 = 0;
  lVar5 = lVar4;
  if (*(long *)(lVar4 + 0x278) != 0) {
    lVar5 = *(long *)(lVar4 + 0x278);
  }
  if ((*(int *)(param_1 + 0x18) != 0) && ((*(byte *)(lVar4 + 0x198) >> 5 & 1) != 0)) {
    if ((lVar4 != 0) && (((param_1 != 0 && (param_2 != 0)) && (*(long *)(param_1 + 0x48) != 0)))) {
      uVar2 = *(uint *)(param_1 + 0x5d8);
      if (uVar2 != 0) {
        if (0xff < uVar2) {
LAB_00105014:
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x105018);
          (*pcVar1)();
        }
        lVar4 = *(long *)(lVar5 + (ulong)uVar2 * 8 + 0x4a0);
        if (((lVar4 != 0) && (*(long *)(lVar4 + 8) == param_1)) &&
           ((*(byte *)(lVar5 + 0xcc8) >> 1 & 1) == 0)) {
          uVar2 = xhci_get_endpoint_index(param_2);
          if (0x1e < uVar2) goto LAB_00105014;
          puVar7 = (undefined8 *)(lVar4 + (ulong)uVar2 * 0x90 + 0x30);
          puVar3 = (undefined8 *)*puVar7;
          if ((puVar3 != (undefined8 *)0x0) &&
             (puVar3 = (undefined8 *)*puVar3, puVar3 != (undefined8 *)0x0)) {
            dma_get_sgtable_attrs(uVar6,&local_48,*puVar3,puVar3[2],0x1000,0);
            *param_3 = *(undefined8 *)(*(long *)*puVar7 + 0x10);
            lVar5 = ((*local_48 & 0x3fffffffffffffc) + (_memstart_addr >> 0xc) * 0x40) * 0x40 +
                    0x8000000000;
            sg_free_table(&local_48);
            goto LAB_00104fe0;
          }
          goto LAB_00104fdc;
        }
      }
    }
    _dev_err(**(undefined8 **)(lVar5 + 0x2d0),"%s: invalid args\n","xhci_get_xfer_ring_phys_addr");
  }
LAB_00104fdc:
  lVar5 = 0;
LAB_00104fe0:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar5;
}



//------------------------------------------------------------
// xhci_stop_endpoint @ 0010501c size=480
// signature: undefined xhci_stop_endpoint(void)
// callers: [handle_uaudio_stream_req]
//------------------------------------------------------------

int xhci_stop_endpoint(long param_1,long param_2)

{
  undefined8 *puVar1;
  long lVar2;
  undefined *puVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  
  lVar8 = *(long *)(param_1 + 0x50);
  lVar9 = lVar8;
  if (*(long *)(lVar8 + 0x278) != 0) {
    lVar9 = *(long *)(lVar8 + 0x278);
  }
  if (lVar8 == 0) {
    return -0x16;
  }
  if (param_1 == 0) {
    return -0x16;
  }
  if (param_2 == 0) {
    return -0x16;
  }
  if (*(long *)(param_1 + 0x48) == 0) {
    return 0;
  }
  uVar5 = *(uint *)(param_1 + 0x5d8);
  if (uVar5 == 0) {
    return -0x16;
  }
  if (0xff < uVar5) {
LAB_001051f8:
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1051fc);
    (*pcVar4)();
  }
  lVar8 = *(long *)(lVar9 + 0x4a0 + (ulong)uVar5 * 8);
  if (lVar8 == 0) {
    return -0x16;
  }
  if (*(long *)(lVar8 + 8) != param_1) {
    return -0x16;
  }
  if ((*(byte *)(lVar9 + 0xcc8) >> 1 & 1) != 0) {
    return -0x13;
  }
  puVar1 = (undefined8 *)(lVar9 + 0x2d0);
  lVar8 = xhci_alloc_command(puVar1,1,0xc00);
  if (lVar8 == 0) {
    return -0xc;
  }
  lVar2 = lVar9 + 0x31c;
  uVar7 = _raw_spin_lock_irqsave(lVar2);
  if (0xff < *(uint *)(param_1 + 0x5d8)) goto LAB_001051f8;
  lVar9 = *(long *)(lVar9 + 0x4a0 + (ulong)*(uint *)(param_1 + 0x5d8) * 8);
  if (lVar9 == 0) {
    iVar6 = -0x13;
  }
  else {
    uVar5 = xhci_get_endpoint_index(param_2);
    if (0x1e < uVar5) goto LAB_001051f8;
    lVar9 = *(long *)(lVar9 + (ulong)uVar5 * 0x90 + 0x30);
    if ((lVar9 == 0) || (*(long *)(lVar9 + 0x20) == 0)) {
      iVar6 = 1;
    }
    else {
      iVar6 = xhci_queue_stop_endpoint(puVar1,lVar8,*(undefined4 *)(param_1 + 0x5d8),uVar5,0);
      if (iVar6 == 0) {
        xhci_ring_cmd_db(puVar1);
        _raw_spin_unlock_irqrestore(lVar2,uVar7);
        wait_for_completion(*(undefined8 *)(lVar8 + 0x10));
        if (*(int *)(lVar8 + 8) - 0x19U < 2) {
          puVar3 = &DAT_0010655a;
          if ((char)*(byte *)(param_2 + 2) < '\0') {
            puVar3 = &DAT_00106a26;
          }
          _dev_warn(*(undefined8 *)*puVar1,"stop endpoint command timeout for ep%d%s\n",
                    *(byte *)(param_2 + 2) & 0xf,puVar3);
          iVar6 = -0x3e;
        }
        else {
          iVar6 = 0;
        }
        goto LAB_001051a8;
      }
    }
  }
  _raw_spin_unlock_irqrestore(lVar2,uVar7);
LAB_001051a8:
  xhci_free_command(puVar1,lVar8);
  return iVar6;
}



//------------------------------------------------------------
// readl_relaxed @ 001051fc size=124
// signature: undefined readl_relaxed(void)
// callers: [xhci_sec_event_ring_cleanup, xhci_sec_event_ring_setup]
//------------------------------------------------------------

undefined4 readl_relaxed(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x20,param_1,0x105244,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 00105278 size=132
// signature: undefined writel_relaxed(void)
// callers: [xhci_sec_event_ring_cleanup, xhci_sec_event_ring_setup]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x105290,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1052cc,uVar1);
  return;
}



//------------------------------------------------------------
// readl @ 001052fc size=140
// signature: undefined readl(void)
// callers: [xhci_sec_event_ring_cleanup, xhci_sec_event_ring_setup]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x105354,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel @ 00105388 size=136
// signature: undefined writel(void)
// callers: [xhci_sec_event_ring_cleanup, xhci_sec_event_ring_setup]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x1053a0,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1053e0,uVar1);
  return;
}



//------------------------------------------------------------
// init_module @ 00106154 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&uaudio_qmi_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00106184 size=104
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  undefined8 *puVar1;
  
  puVar1 = uaudio_svc;
  qmi_handle_release(*uaudio_svc);
  __flush_workqueue(puVar1[7]);
  destroy_workqueue(puVar1[7]);
  kfree(*puVar1);
  ipc_log_context_destroy(puVar1[10]);
  kfree(puVar1);
  uaudio_svc = (undefined8 *)0x0;
  platform_driver_unregister(&uaudio_qmi_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 0010a008 size=1
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
// qmi_handle_release @ 0010a010 size=1
// signature: undefined qmi_handle_release(void)
// callers: [cleanup_module, uaudio_qmi_plat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __flush_workqueue @ 0010a018 size=1
// signature: undefined __flush_workqueue(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __flush_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 0010a020 size=1
// signature: undefined destroy_workqueue(void)
// callers: [cleanup_module, uaudio_qmi_plat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010a028 size=1
// signature: undefined kfree(void)
// callers: [cleanup_module, uaudio_qmi_plat_probe, xhci_sec_event_ring_cleanup, uaudio_dev_cleanup, xhci_sec_event_ring_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 0010a030 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 0010a038 size=1
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
// devm_kmalloc @ 0010a040 size=1
// signature: undefined devm_kmalloc(void)
// callers: [uaudio_qmi_plat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010a050 size=1
// signature: undefined kmalloc_trace(void)
// callers: [uaudio_qmi_plat_probe, xhci_sec_event_ring_setup, uaudio_get_iova]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 0010a058 size=1
// signature: undefined alloc_workqueue(void)
// callers: [uaudio_qmi_plat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_init @ 0010a060 size=1
// signature: undefined qmi_handle_init(void)
// callers: [uaudio_qmi_plat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_add_server @ 0010a068 size=1
// signature: undefined qmi_add_server(void)
// callers: [uaudio_qmi_plat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_add_server(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 0010a070 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [uaudio_qmi_plat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010a078 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [uaudio_qmi_plat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_domain_alloc @ 0010a080 size=1
// signature: undefined iommu_domain_alloc(void)
// callers: [uaudio_qmi_plat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_domain_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010a088 size=1
// signature: undefined _dev_err(void)
// callers: [uaudio_qmi_plat_probe, xhci_get_xfer_ring_phys_addr, enable_audio_stream, xhci_sec_event_ring_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010a090 size=1
// signature: undefined _printk(void)
// callers: [uaudio_disconnect, uaudio_qmi_plat_probe, uaudio_dev_intf_cleanup, uaudio_event_ring_cleanup_free, handle_uaudio_stream_req, enable_audio_stream, configure_endpoints, uaudio_iommu_unmap, uaudio_qmi_bye_cb, uaudio_connect, prepare_qmi_response, uaudio_iommu_map, uaudio_dev_cleanup, uaudio_qmi_disconnect_work, uaudio_qmi_svc_disconnect_cb, uaudio_put_iova, uaudio_get_iova]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_attach_device @ 0010a098 size=1
// signature: undefined iommu_attach_device(void)
// callers: [uaudio_qmi_plat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_attach_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 0010a0a8 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [uaudio_qmi_plat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// android_rvh_probe_register @ 0010a0b8 size=1
// signature: undefined android_rvh_probe_register(void)
// callers: [uaudio_qmi_plat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void android_rvh_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_detach_device @ 0010a0c0 size=1
// signature: undefined iommu_detach_device(void)
// callers: [uaudio_qmi_plat_probe, uaudio_qmi_plat_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_detach_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_domain_free @ 0010a0c8 size=1
// signature: undefined iommu_domain_free(void)
// callers: [uaudio_qmi_plat_probe, uaudio_qmi_plat_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_domain_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_unregister @ 0010a0d0 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [uaudio_qmi_plat_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 0010a0d8 size=1
// signature: undefined ipc_log_string(void)
// callers: [uaudio_disconnect, uaudio_dev_intf_cleanup, uaudio_event_ring_cleanup_free, handle_uaudio_stream_req, enable_audio_stream, configure_endpoints, uaudio_iommu_unmap, uaudio_qmi_bye_cb, uaudio_connect, prepare_qmi_response, uaudio_iommu_map, uaudio_dev_cleanup, uaudio_qmi_disconnect_work, uaudio_qmi_svc_disconnect_cb, uaudio_put_iova, uaudio_get_iova]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010a0e0 size=1
// signature: undefined mutex_lock(void)
// callers: [uaudio_disconnect, disable_audio_stream, handle_uaudio_stream_req, enable_audio_stream, uaudio_qmi_disconnect_work, close_endpoints]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010a0e8 size=1
// signature: undefined mutex_unlock(void)
// callers: [uaudio_disconnect, disable_audio_stream, handle_uaudio_stream_req, enable_audio_stream, uaudio_qmi_disconnect_work, close_endpoints]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_send_indication @ 0010a0f0 size=1
// signature: undefined qmi_send_indication(void)
// callers: [uaudio_disconnect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_send_indication(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 0010a0f8 size=1
// signature: undefined init_wait_entry(void)
// callers: [uaudio_disconnect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 0010a100 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [uaudio_disconnect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 0010a108 size=1
// signature: undefined schedule_timeout(void)
// callers: [uaudio_disconnect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 0010a110 size=1
// signature: undefined finish_wait(void)
// callers: [uaudio_disconnect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010a118 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [uaudio_disconnect, prepare_qmi_response, handle_uaudio_stream_req, uaudio_iommu_map, xhci_get_xfer_ring_phys_addr, enable_audio_stream, xhci_get_sec_event_ring_phys_addr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_usb_autosuspend @ 0010a120 size=1
// signature: undefined snd_usb_autosuspend(void)
// callers: [disable_audio_stream, uaudio_qmi_disconnect_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_usb_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0010a128 size=1
// signature: undefined queue_work_on(void)
// callers: [uaudio_qmi_bye_cb, uaudio_qmi_svc_disconnect_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 0010a130 size=1
// signature: undefined ktime_get(void)
// callers: [handle_uaudio_stream_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 0010a140 size=1
// signature: undefined __wake_up(void)
// callers: [handle_uaudio_stream_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_send_response @ 0010a148 size=1
// signature: undefined qmi_send_response(void)
// callers: [handle_uaudio_stream_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_send_response(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 0010a150 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [prepare_qmi_response, handle_uaudio_stream_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0010a158 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [enable_audio_stream]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _snd_pcm_hw_params_any @ 0010a160 size=1
// signature: undefined _snd_pcm_hw_params_any(void)
// callers: [enable_audio_stream]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _snd_pcm_hw_params_any(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_interval_refine @ 0010a168 size=1
// signature: undefined snd_interval_refine(void)
// callers: [enable_audio_stream]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_interval_refine(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_barrier @ 0010a170 size=1
// signature: undefined pm_runtime_barrier(void)
// callers: [enable_audio_stream]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_barrier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_usb_autoresume @ 0010a178 size=1
// signature: undefined snd_usb_autoresume(void)
// callers: [enable_audio_stream]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_usb_autoresume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_usb_power_domain_set @ 0010a180 size=1
// signature: undefined snd_usb_power_domain_set(void)
// callers: [enable_audio_stream]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_usb_power_domain_set(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_usb_endpoint_open @ 0010a188 size=1
// signature: undefined snd_usb_endpoint_open(void)
// callers: [enable_audio_stream]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_usb_endpoint_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ifnum_to_if @ 0010a190 size=1
// signature: undefined usb_ifnum_to_if(void)
// callers: [prepare_qmi_response]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ifnum_to_if(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_alias_get_id @ 0010a198 size=1
// signature: undefined of_alias_get_id(void)
// callers: [prepare_qmi_response]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_alias_get_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_alloc_coherent @ 0010a1a0 size=1
// signature: undefined usb_alloc_coherent(void)
// callers: [prepare_qmi_response]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_alloc_coherent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_get_sgtable_attrs @ 0010a1a8 size=1
// signature: undefined dma_get_sgtable_attrs(void)
// callers: [prepare_qmi_response, xhci_get_xfer_ring_phys_addr, xhci_get_sec_event_ring_phys_addr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_get_sgtable_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_free_table @ 0010a1b0 size=1
// signature: undefined sg_free_table(void)
// callers: [prepare_qmi_response, xhci_get_xfer_ring_phys_addr, xhci_get_sec_event_ring_phys_addr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_free_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 0010a1b8 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [prepare_qmi_response]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0010a1c0 size=1
// signature: undefined __kmalloc(void)
// callers: [prepare_qmi_response]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_free_coherent @ 0010a1c8 size=1
// signature: undefined usb_free_coherent(void)
// callers: [uaudio_dev_intf_cleanup, prepare_qmi_response]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_free_coherent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_usb_endpoint_close @ 0010a1d0 size=1
// signature: undefined snd_usb_endpoint_close(void)
// callers: [close_endpoints]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_usb_endpoint_close(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_usb_endpoint_prepare @ 0010a1d8 size=1
// signature: undefined snd_usb_endpoint_prepare(void)
// callers: [configure_endpoints]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_usb_endpoint_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_map @ 0010a1e8 size=1
// signature: undefined iommu_map(void)
// callers: [uaudio_iommu_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_next @ 0010a1f0 size=1
// signature: undefined sg_next(void)
// callers: [uaudio_iommu_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_unmap @ 0010a1f8 size=1
// signature: undefined iommu_unmap(void)
// callers: [uaudio_iommu_unmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_unmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0010a200 size=1
// signature: undefined __list_add_valid(void)
// callers: [xhci_sec_event_ring_setup, uaudio_get_iova]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xhci_ring_alloc @ 0010a208 size=1
// signature: undefined xhci_ring_alloc(void)
// callers: [xhci_sec_event_ring_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xhci_ring_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xhci_alloc_erst @ 0010a210 size=1
// signature: undefined xhci_alloc_erst(void)
// callers: [xhci_sec_event_ring_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xhci_alloc_erst(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xhci_trb_virt_to_dma @ 0010a218 size=1
// signature: undefined xhci_trb_virt_to_dma(void)
// callers: [xhci_sec_event_ring_cleanup, xhci_sec_event_ring_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xhci_trb_virt_to_dma(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 0010a220 size=1
// signature: undefined _dev_warn(void)
// callers: [xhci_sec_event_ring_cleanup, xhci_sec_event_ring_setup, xhci_stop_endpoint]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0010a228 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [xhci_sec_event_ring_cleanup, xhci_stop_endpoint]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0010a230 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [xhci_sec_event_ring_cleanup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0010a238 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [xhci_sec_event_ring_cleanup, xhci_stop_endpoint]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 0010a240 size=1
// signature: undefined dma_free_attrs(void)
// callers: [xhci_sec_event_ring_cleanup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xhci_ring_free @ 0010a248 size=1
// signature: undefined xhci_ring_free(void)
// callers: [xhci_sec_event_ring_cleanup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xhci_ring_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xhci_get_endpoint_index @ 0010a250 size=1
// signature: undefined xhci_get_endpoint_index(void)
// callers: [xhci_get_xfer_ring_phys_addr, xhci_stop_endpoint]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xhci_get_endpoint_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xhci_alloc_command @ 0010a258 size=1
// signature: undefined xhci_alloc_command(void)
// callers: [xhci_stop_endpoint]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xhci_alloc_command(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xhci_queue_stop_endpoint @ 0010a260 size=1
// signature: undefined xhci_queue_stop_endpoint(void)
// callers: [xhci_stop_endpoint]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xhci_queue_stop_endpoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xhci_ring_cmd_db @ 0010a268 size=1
// signature: undefined xhci_ring_cmd_db(void)
// callers: [xhci_stop_endpoint]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xhci_ring_cmd_db(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion @ 0010a270 size=1
// signature: undefined wait_for_completion(void)
// callers: [xhci_stop_endpoint]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xhci_free_command @ 0010a278 size=1
// signature: undefined xhci_free_command(void)
// callers: [xhci_stop_endpoint]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xhci_free_command(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 0010a280 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl_relaxed, readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 0010a288 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed, readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 0010a290 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed, writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 0010a298 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed, writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



