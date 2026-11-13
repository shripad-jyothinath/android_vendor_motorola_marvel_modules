// Decompiled by Ghidra 12.2
// Program: hdmi_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// msm_ext_disp_audio_codec_rx_plat_probe @ 00100364 size=52
// signature: undefined msm_ext_disp_audio_codec_rx_plat_probe(void)
// callers: []
//------------------------------------------------------------

void msm_ext_disp_audio_codec_rx_plat_probe(long param_1)

{
  snd_soc_register_component
            (param_1 + 0x10,&msm_ext_disp_codec_rx_driver,&msm_ext_disp_audio_codec_rx_dais,4);
  return;
}



//------------------------------------------------------------
// msm_ext_disp_audio_codec_rx_plat_remove @ 0010039c size=36
// signature: undefined msm_ext_disp_audio_codec_rx_plat_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_ext_disp_audio_codec_rx_plat_remove(long param_1)

{
  snd_soc_unregister_component(param_1 + 0x10);
  return 0;
}



//------------------------------------------------------------
// msm_ext_disp_audio_codec_rx_probe @ 001003c4 size=240
// signature: undefined msm_ext_disp_audio_codec_rx_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 msm_ext_disp_audio_codec_rx_probe(long param_1)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  plVar2 = (long *)kmalloc_trace(_of_get_parent,0xdc0,0xb0);
  if (plVar2 == (long *)0x0) {
    _dev_err(*(long *)(param_1 + 0x18),"%s(): fail to allocate dai data\n",
             "msm_ext_disp_audio_codec_rx_probe");
    uVar4 = 0xfffffff4;
  }
  else {
    lVar3 = of_get_parent(*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x2e8));
    if (lVar3 == 0) {
      uVar4 = *(undefined8 *)(param_1 + 0x18);
      pcVar5 = "%s(): Parent device tree node not found\n";
    }
    else {
      lVar3 = of_find_device_by_node();
      *plVar2 = lVar3;
      if (lVar3 == 0) {
        uVar4 = *(undefined8 *)(param_1 + 0x18);
        pcVar5 = "%s(): can\'t get parent pdev\n";
      }
      else {
        iVar1 = msm_ext_disp_register_audio_codec(lVar3,plVar2 + 1);
        if (iVar1 == 0) {
          __mutex_init(plVar2 + 8,"&codec_data->dp_ops_lock",
                       &msm_ext_disp_audio_codec_rx_probe___key);
          *(long **)(*(long *)(param_1 + 0x18) + 0x98) = plVar2;
          return 0;
        }
        uVar4 = *(undefined8 *)(param_1 + 0x18);
        pcVar5 = "%s(): can\'t register with ext disp core";
      }
    }
    _dev_err(uVar4,pcVar5,"msm_ext_disp_audio_codec_rx_probe");
    kfree(plVar2);
    uVar4 = 0xffffffed;
  }
  return uVar4;
}



//------------------------------------------------------------
// msm_ext_disp_audio_codec_rx_remove @ 001004b8 size=36
// signature: undefined msm_ext_disp_audio_codec_rx_remove(void)
// callers: []
//------------------------------------------------------------

void msm_ext_disp_audio_codec_rx_remove(long param_1)

{
  kfree(*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x98));
  return;
}



//------------------------------------------------------------
// msm_ext_disp_edid_ctl_info @ 001004e0 size=392
// signature: undefined msm_ext_disp_edid_ctl_info(void)
// callers: []
//------------------------------------------------------------

int msm_ext_disp_edid_ctl_info(long param_1,long param_2)

{
  undefined8 *puVar1;
  int iVar2;
  code *pcVar3;
  long lVar4;
  undefined8 *puVar5;
  ulong uVar6;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x80);
  local_48 = 0;
  local_40 = 0;
  local_58 = 0;
  local_50 = 0;
  puVar5 = *(undefined8 **)(*(long *)(lVar4 + 0x18) + 0x98);
  if (puVar5 == (undefined8 *)0x0) {
    iVar2 = ___ratelimit(msm_ext_disp_edid_ctl_info__rs,"msm_ext_disp_edid_ctl_info");
    if (iVar2 == 0) {
      iVar2 = -0x16;
    }
    else {
      _dev_err(*(undefined8 *)(lVar4 + 0x18),"%s: codec_data is NULL\n","msm_ext_disp_edid_ctl_info"
              );
      iVar2 = -0x16;
    }
  }
  else {
    puVar1 = puVar5 + 8;
    uVar6 = *(ulong *)(param_1 + 0x78);
    mutex_lock(puVar1);
    local_68 = 0x28;
    if ((int)uVar6 != 4) {
      local_68 = 0x2c;
    }
    local_64 = *(undefined4 *)((long)puVar5 + ((long)(uVar6 << 0x20) >> 0x1e) + 0x98);
    if (4 < (uVar6 & 0xffffffff)) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100668);
      (*pcVar3)();
    }
    local_60 = *(undefined4 *)((long)puVar5 + (long)(int)uVar6 * 4 + 0x84);
    iVar2 = msm_ext_disp_select_audio_codec(*puVar5,&local_68);
    pcVar3 = (code *)puVar5[2];
    if ((pcVar3 == (code *)0x0) || (iVar2 != 0)) {
      *(undefined4 *)(param_2 + 0x48) = 0;
      *(undefined4 *)(param_2 + 0x40) = 4;
      mutex_unlock(puVar1);
      iVar2 = 0;
    }
    else {
      if (*(int *)(pcVar3 + -4) != 0x15f62889) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1005a8);
        (*pcVar3)();
      }
      iVar2 = (*pcVar3)(*puVar5,&local_58);
      mutex_unlock(puVar1);
      if (-1 < iVar2) {
        *(undefined4 *)(param_2 + 0x40) = 4;
        *(int *)(param_2 + 0x48) = (int)local_40 + (int)local_50;
      }
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// msm_ext_disp_edid_get @ 0010066c size=624
// signature: undefined msm_ext_disp_edid_get(void)
// callers: []
//------------------------------------------------------------

int msm_ext_disp_edid_get(long param_1,long param_2)

{
  undefined8 *puVar1;
  int iVar2;
  code *pcVar3;
  undefined8 *puVar4;
  long lVar5;
  ulong uVar6;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  void *local_68;
  ulong local_60;
  void *local_58;
  ulong local_50;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  lVar5 = *(long *)(param_1 + 0x80);
  local_58 = (void *)0x0;
  local_50 = 0;
  local_68 = (void *)0x0;
  local_60 = 0;
  local_70 = 0;
  puVar4 = *(undefined8 **)(*(long *)(lVar5 + 0x18) + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    iVar2 = ___ratelimit(msm_ext_disp_edid_get__rs,"msm_ext_disp_edid_get");
    if (iVar2 == 0) {
      iVar2 = -0x16;
    }
    else {
      _dev_err(*(undefined8 *)(lVar5 + 0x18),"%s: codec_data is NULL\n","msm_ext_disp_edid_get");
      iVar2 = -0x16;
    }
  }
  else {
    puVar1 = puVar4 + 8;
    uVar6 = *(ulong *)(param_1 + 0x78);
    mutex_lock(puVar1);
    local_78 = 0x28;
    if ((int)uVar6 != 4) {
      local_78 = 0x2c;
    }
    local_74 = *(undefined4 *)((long)puVar4 + ((long)(uVar6 << 0x20) >> 0x1e) + 0x98);
    if (4 < (uVar6 & 0xffffffff)) {
LAB_001008dc:
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1008e0);
      (*pcVar3)();
    }
    local_70 = *(undefined4 *)((long)puVar4 + (long)(int)uVar6 * 4 + 0x84);
    iVar2 = msm_ext_disp_select_audio_codec(*puVar4,&local_78);
    pcVar3 = (code *)puVar4[2];
    if ((pcVar3 == (code *)0x0) || (iVar2 != 0)) {
      iVar2 = ___ratelimit(msm_ext_disp_edid_get__rs_19,"msm_ext_disp_edid_get");
      if (iVar2 != 0) {
        _dev_err(*(undefined8 *)(lVar5 + 0x18),"%s: codec_data or get_audio_edid_blk() is NULL\n",
                 "msm_ext_disp_edid_get");
      }
      mutex_unlock(puVar1);
      iVar2 = -0x16;
    }
    else {
      if (*(int *)(pcVar3 + -4) != 0x15f62889) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10073c);
        (*pcVar3)();
      }
      iVar2 = (*pcVar3)(*puVar4,&local_68);
      mutex_unlock(puVar1);
      if (-1 < iVar2) {
        if ((int)local_50 + (uint)local_60 < 0x201) {
          if ((0x200 < (uint)local_60) && ((msm_ext_disp_edid_get___already_done & 1) == 0)) {
            msm_ext_disp_edid_get___already_done = 1;
            __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n"
                          ,local_60 & 0xffffffff,
                          "field \"ucontrol->value.bytes.data\" at ../vendor/qcom/opensource/audio-kernel/asoc/codecs/msm_hdmi_codec_rx.c:192"
                          ,0x200);
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1008d4);
            (*pcVar3)();
          }
          memcpy((void *)(param_2 + 0x48),local_68,local_60 & 0xffffffff);
          if ((0x200 < (uint)local_60) || (0x200 < (uint)local_60)) goto LAB_001008dc;
          memcpy((void *)(param_2 + 0x48 + (local_60 & 0xffffffff)),local_58,local_50 & 0xffffffff);
        }
        else {
          iVar2 = ___ratelimit(msm_ext_disp_edid_get__rs_21,"msm_ext_disp_edid_get");
          if (iVar2 == 0) {
            iVar2 = -0xc;
          }
          else {
            _dev_err(*(undefined8 *)(lVar5 + 0x18),"%s: Not enough memory to copy EDID data\n",
                     "msm_ext_disp_edid_get");
            iVar2 = -0xc;
          }
        }
      }
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// msm_ext_disp_audio_type_get @ 001008e4 size=604
// signature: undefined msm_ext_disp_audio_type_get(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_ext_disp_audio_type_get(long param_1,long param_2)

{
  undefined8 *puVar1;
  byte bVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  long lVar9;
  ulong uVar10;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  long local_48;
  
  lVar9 = sp_el0;
  local_48 = *(long *)(lVar9 + 0x638);
  lVar9 = *(long *)(param_1 + 0x80);
  puVar7 = *(undefined8 **)(*(long *)(lVar9 + 0x18) + 0x98);
  if (puVar7 == (undefined8 *)0x0) {
    iVar4 = ___ratelimit(msm_ext_disp_audio_type_get__rs,"msm_ext_disp_audio_type_get");
    if (iVar4 != 0) {
      _dev_err(*(undefined8 *)(lVar9 + 0x18),"%s: codec_data is NULL\n",
               "msm_ext_disp_audio_type_get");
    }
LAB_00100a40:
    uVar8 = 0xffffffea;
  }
  else {
    puVar1 = puVar7 + 8;
    bVar2 = *(byte *)(*(long *)(param_1 + 0x78) + 4);
    uVar10 = (ulong)bVar2;
    mutex_lock(puVar1);
    local_58 = 0x28;
    if (bVar2 != 4) {
      local_58 = 0x2c;
    }
    local_54 = *(undefined4 *)((long)puVar7 + uVar10 * 4 + 0x98);
    if (4 < bVar2) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100b40);
      (*pcVar3)();
    }
    local_50 = *(undefined4 *)((long)puVar7 + uVar10 * 4 + 0x84);
    iVar4 = msm_ext_disp_select_audio_codec(*puVar7,&local_58);
    if (((puVar7[2] == 0) || (puVar7[4] == 0)) || (iVar4 != 0)) {
      iVar4 = ___ratelimit(msm_ext_disp_audio_type_get__rs_28,"msm_ext_disp_audio_type_get");
      if (iVar4 != 0) {
        _dev_err(*(undefined8 *)(lVar9 + 0x18),"%s: get_audio_edid_blk() or get_intf_id is NULL\n",
                 "msm_ext_disp_audio_type_get");
      }
      uVar8 = 0xffffffea;
    }
    else {
      if (*(int *)((code *)puVar7[3] + -4) != 0x3e37fe6d) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1009a8);
        (*pcVar3)();
      }
      iVar4 = (*(code *)puVar7[3])(*puVar7,1);
      *(int *)((long)puVar7 + uVar10 * 4 + 0x70) = iVar4;
      if (iVar4 != 0) {
        if (*(int *)((code *)puVar7[4] + -4) != 0x63df1691) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1009d8);
          (*pcVar3)();
        }
        iVar4 = (*(code *)puVar7[4])(*puVar7);
        mutex_unlock(puVar1);
        if (iVar4 == 0x28) {
          uVar6 = 1;
        }
        else {
          if (iVar4 != 0x2c) {
            iVar5 = ___ratelimit(msm_ext_disp_audio_type_get__rs_34,"msm_ext_disp_audio_type_get");
            if (iVar5 != 0) {
              _dev_err(*(undefined8 *)(lVar9 + 0x18),"%s: Invalid disp_type:%d\n",
                       "msm_ext_disp_audio_type_get",iVar4);
            }
            goto LAB_00100a40;
          }
          uVar6 = 2;
        }
        uVar8 = 0;
        *(undefined8 *)(param_2 + 0x48) = uVar6;
        goto LAB_00100a44;
      }
      iVar4 = ___ratelimit(msm_ext_disp_audio_type_get__rs_32,"msm_ext_disp_audio_type_get");
      if (iVar4 != 0) {
        _dev_err(*(undefined8 *)(lVar9 + 0x18),"%s: Display cable disconnected\n",
                 "msm_ext_disp_audio_type_get");
      }
      uVar8 = 0;
      *(undefined8 *)(param_2 + 0x48) = 0;
    }
    mutex_unlock(puVar1);
  }
LAB_00100a44:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



//------------------------------------------------------------
// msm_ext_disp_audio_ack_set @ 00100b44 size=512
// signature: undefined msm_ext_disp_audio_ack_set(void)
// callers: []
//------------------------------------------------------------

int msm_ext_disp_audio_ack_set(long param_1,long param_2)

{
  undefined8 *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x80);
  puVar7 = *(undefined8 **)(*(long *)(lVar6 + 0x18) + 0x98);
  if (puVar7 == (undefined8 *)0x0) {
    iVar3 = ___ratelimit(msm_ext_disp_audio_ack_set__rs,"msm_ext_disp_audio_ack_set");
    if (iVar3 != 0) {
      _dev_err(*(undefined8 *)(lVar6 + 0x18),"%s: codec_data is NULL\n","msm_ext_disp_audio_ack_set"
              );
    }
  }
  else {
    puVar1 = puVar7 + 8;
    bVar2 = *(byte *)(*(long *)(param_1 + 0x78) + 4);
    mutex_lock(puVar1);
    local_58 = 0x28;
    if (bVar2 != 4) {
      local_58 = 0x2c;
    }
    local_54 = *(undefined4 *)((long)puVar7 + (ulong)bVar2 * 4 + 0x98);
    if (4 < bVar2) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x100d44);
      (*pcVar5)();
    }
    local_50 = *(undefined4 *)((long)puVar7 + (ulong)bVar2 * 4 + 0x84);
    iVar3 = msm_ext_disp_select_audio_codec(*puVar7,&local_58);
    pcVar5 = (code *)puVar7[6];
    if ((pcVar5 == (code *)0x0) || (iVar3 != 0)) {
      iVar3 = ___ratelimit(msm_ext_disp_audio_ack_set__rs_41,"msm_ext_disp_audio_ack_set");
      if (iVar3 != 0) {
        _dev_err(*(undefined8 *)(lVar6 + 0x18),"%s: codec_data ops acknowledge() is NULL\n",
                 "msm_ext_disp_audio_ack_set");
      }
    }
    else {
      if (*(uint *)(param_2 + 0x48) < 3) {
        if (*(int *)(pcVar5 + -4) != 0x3e37fe6d) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x100c10);
          (*pcVar5)();
        }
        iVar3 = (*pcVar5)(*puVar7,*(undefined4 *)
                                   (&DAT_00102218 + (long)(int)*(uint *)(param_2 + 0x48) * 4));
        mutex_unlock(puVar1);
        if ((iVar3 < 0) &&
           (iVar4 = ___ratelimit(msm_ext_disp_audio_ack_set__rs_45,"msm_ext_disp_audio_ack_set"),
           iVar4 != 0)) {
          _dev_err(*(undefined8 *)(lVar6 + 0x18),"%s: error from acknowledge(), err:%d\n",
                   "msm_ext_disp_audio_ack_set",iVar3);
        }
        goto LAB_00100ce8;
      }
      iVar3 = ___ratelimit(msm_ext_disp_audio_ack_set__rs_43,"msm_ext_disp_audio_ack_set");
      if (iVar3 != 0) {
        _dev_err(*(undefined8 *)(lVar6 + 0x18),"%s: invalid value %d for mixer ctl\n",
                 "msm_ext_disp_audio_ack_set",*(undefined4 *)(param_2 + 0x48));
      }
    }
    mutex_unlock(puVar1);
  }
  iVar3 = -0x16;
LAB_00100ce8:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// msm_ext_disp_audio_device_get @ 00100d48 size=200
// signature: undefined msm_ext_disp_audio_device_get(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_ext_disp_audio_device_get(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  
  lVar1 = *(long *)(param_1 + 0x80);
  uVar2 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  if (uVar2 < 3) {
    lVar4 = *(long *)(*(long *)(lVar1 + 0x18) + 0x98);
    if (lVar4 != 0) {
      lVar4 = lVar4 + (ulong)uVar2 * 4;
      *(long *)(param_2 + 0x48) = (long)*(int *)(lVar4 + 0x98);
      *(long *)(param_2 + 0x50) = (long)*(int *)(lVar4 + 0x84);
      return 0;
    }
    iVar3 = ___ratelimit(msm_ext_disp_audio_device_get__rs_51,"msm_ext_disp_audio_device_get");
    if (iVar3 != 0) {
      _dev_err(*(undefined8 *)(lVar1 + 0x18),"%s: codec_data or ops acknowledge() is NULL\n",
               "msm_ext_disp_audio_device_get");
    }
  }
  else {
    iVar3 = ___ratelimit(msm_ext_disp_audio_device_get__rs,"msm_ext_disp_audio_device_get");
    if (iVar3 != 0) {
      _dev_err(*(undefined8 *)(lVar1 + 0x18),"%s: invalid dai id: %d\n",
               "msm_ext_disp_audio_device_get",uVar2);
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// msm_ext_disp_audio_device_set @ 00100e14 size=300
// signature: undefined msm_ext_disp_audio_device_set(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_ext_disp_audio_device_set(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  long lVar6;
  
  lVar1 = *(long *)(param_1 + 0x80);
  uVar2 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  if (uVar2 < 3) {
    lVar6 = *(long *)(*(long *)(lVar1 + 0x18) + 0x98);
    if (lVar6 == 0) {
      iVar3 = ___ratelimit(msm_ext_disp_audio_device_set__rs_53,"msm_ext_disp_audio_device_set");
      if (iVar3 == 0) {
        return 0xffffffea;
      }
      uVar4 = *(undefined8 *)(lVar1 + 0x18);
      pcVar5 = "%s: codec_data or ops acknowledge() is NULL\n";
    }
    else {
      if (((*(long *)(param_2 + 0x48) < 1) && (*(ulong *)(param_2 + 0x50) < 3)) &&
         (*(long *)(param_2 + 0x48) == 0)) {
        mutex_lock(lVar6 + 0x40);
        lVar1 = lVar6 + (ulong)uVar2 * 4;
        *(int *)(lVar1 + 0x98) = (int)*(undefined8 *)(param_2 + 0x48);
        *(int *)(lVar1 + 0x84) = (int)*(undefined8 *)(param_2 + 0x50);
        mutex_unlock(lVar6 + 0x40);
        return 0;
      }
      iVar3 = ___ratelimit(msm_ext_disp_audio_device_set__rs_54,"msm_ext_disp_audio_device_set");
      if (iVar3 == 0) {
        return 0xffffffea;
      }
      uVar4 = *(undefined8 *)(lVar1 + 0x18);
      pcVar5 = "%s: DP audio control index invalid\n";
    }
    _dev_err(uVar4,pcVar5,"msm_ext_disp_audio_device_set");
  }
  else {
    iVar3 = ___ratelimit(msm_ext_disp_audio_device_set__rs,"msm_ext_disp_audio_device_set");
    if (iVar3 != 0) {
      _dev_err(*(undefined8 *)(lVar1 + 0x18),"%s: invalid dai id: %d\n",
               "msm_ext_disp_audio_device_set",uVar2);
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// msm_ext_disp_audio_codec_rx_dai_startup @ 00100f44 size=620
// signature: undefined msm_ext_disp_audio_codec_rx_dai_startup(void)
// callers: []
//------------------------------------------------------------

void msm_ext_disp_audio_codec_rx_dai_startup(long param_1,long param_2)

{
  undefined8 *puVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_40 = 0;
  puVar6 = *(undefined8 **)(*(long *)(*(long *)(param_2 + 0x58) + 0x18) + 0x98);
  if (puVar6 == (undefined8 *)0x0) {
    iVar2 = ___ratelimit(msm_ext_disp_audio_codec_rx_dai_startup__rs,
                         "msm_ext_disp_audio_codec_rx_dai_startup");
    if (iVar2 != 0) {
      _dev_err(*(undefined8 *)(param_2 + 0x10),"%s() codec_data is null\n",
               "msm_ext_disp_audio_codec_rx_dai_startup");
    }
  }
  else {
    if (-1 < *(char *)(*(long *)(*(long *)(param_1 + 0x10) + 0x10) + 0x80)) {
      snd_soc_set_runtime_hwparams(param_1,dummy_dma_hardware);
    }
    puVar1 = puVar6 + 8;
    mutex_lock(puVar1);
    lVar5 = (long)(int)*(uint *)(param_2 + 8);
    local_48 = 0x28;
    if (lVar5 != 4) {
      local_48 = 0x2c;
    }
    local_44 = *(undefined4 *)((long)puVar6 + lVar5 * 4 + 0x98);
    if (4 < *(uint *)(param_2 + 8)) goto LAB_001011a8;
    local_40 = *(undefined4 *)((long)puVar6 + lVar5 * 4 + 0x84);
    iVar2 = msm_ext_disp_select_audio_codec(*puVar6,&local_48);
    pcVar4 = (code *)puVar6[3];
    if ((pcVar4 != (code *)0x0) && (iVar2 == 0)) {
      if (*(int *)(pcVar4 + -4) != 0x3e37fe6d) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x101014);
        (*pcVar4)();
      }
      uVar3 = (*pcVar4)(*puVar6,1);
      if (4 < *(uint *)(param_2 + 8)) {
LAB_001011a8:
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1011ac);
        (*pcVar4)();
      }
      *(undefined4 *)((long)puVar6 + (ulong)*(uint *)(param_2 + 8) * 4 + 0x70) = uVar3;
      mutex_unlock(puVar1);
      if (4 < *(uint *)(param_2 + 8)) goto LAB_001011a8;
      iVar2 = *(int *)((long)puVar6 + (ulong)*(uint *)(param_2 + 8) * 4 + 0x70);
      if (iVar2 < 0) {
        iVar2 = ___ratelimit(msm_ext_disp_audio_codec_rx_dai_startup__rs_73,
                             "msm_ext_disp_audio_codec_rx_dai_startup");
        if (iVar2 != 0) {
          if (4 < *(uint *)(param_2 + 8)) goto LAB_001011a8;
          _dev_err(*(undefined8 *)(param_2 + 0x10),
                   "%s() ext disp core is not ready (ret val = %d)\n",
                   "msm_ext_disp_audio_codec_rx_dai_startup",
                   *(undefined4 *)((long)puVar6 + (ulong)*(uint *)(param_2 + 8) * 4 + 0x70));
        }
        if (4 < *(uint *)(param_2 + 8)) goto LAB_001011a8;
        uVar3 = *(undefined4 *)((long)puVar6 + (ulong)*(uint *)(param_2 + 8) * 4 + 0x70);
      }
      else if (iVar2 == 0) {
        iVar2 = ___ratelimit(msm_ext_disp_audio_codec_rx_dai_startup__rs_75,
                             "msm_ext_disp_audio_codec_rx_dai_startup");
        if (iVar2 != 0) {
          if (4 < *(uint *)(param_2 + 8)) goto LAB_001011a8;
          _dev_err(*(undefined8 *)(param_2 + 0x10),
                   "%s() ext disp cable is not connected (ret val = %d)\n",
                   "msm_ext_disp_audio_codec_rx_dai_startup",
                   *(undefined4 *)((long)puVar6 + (ulong)*(uint *)(param_2 + 8) * 4 + 0x70));
        }
        uVar3 = 0xffffffed;
      }
      else {
        uVar3 = 0;
      }
      goto LAB_001010b0;
    }
    iVar2 = ___ratelimit(msm_ext_disp_audio_codec_rx_dai_startup__rs_71,
                         "msm_ext_disp_audio_codec_rx_dai_startup");
    if (iVar2 != 0) {
      _dev_err(*(undefined8 *)(param_2 + 0x10),"%s() cable_status is null\n",
               "msm_ext_disp_audio_codec_rx_dai_startup");
    }
    mutex_unlock(puVar1);
  }
  uVar3 = 0xffffffea;
LAB_001010b0:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// msm_ext_disp_audio_codec_rx_dai_shutdown @ 001011b4 size=452
// signature: undefined msm_ext_disp_audio_codec_rx_dai_shutdown(void)
// callers: []
//------------------------------------------------------------

void msm_ext_disp_audio_codec_rx_dai_shutdown(undefined8 param_1,long param_2)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  puVar4 = *(undefined8 **)(*(long *)(*(long *)(param_2 + 0x58) + 0x18) + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    iVar1 = ___ratelimit(msm_ext_disp_audio_codec_rx_dai_shutdown__rs,
                         "msm_ext_disp_audio_codec_rx_dai_shutdown");
    if (iVar1 != 0) {
      _dev_err(*(undefined8 *)(param_2 + 0x10),"%s() codec_data is null\n",
               "msm_ext_disp_audio_codec_rx_dai_shutdown");
    }
  }
  else {
    mutex_lock(puVar4 + 8);
    lVar3 = (long)(int)*(uint *)(param_2 + 8);
    local_48 = 0x28;
    if (lVar3 != 4) {
      local_48 = 0x2c;
    }
    local_44 = *(undefined4 *)((long)puVar4 + lVar3 * 4 + 0x98);
    if (4 < *(uint *)(param_2 + 8)) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x101378);
      (*pcVar2)();
    }
    local_40 = *(undefined4 *)((long)puVar4 + lVar3 * 4 + 0x84);
    iVar1 = msm_ext_disp_select_audio_codec(*puVar4,&local_48);
    if (((puVar4[5] == 0) || (pcVar2 = (code *)puVar4[3], pcVar2 == (code *)0x0)) || (iVar1 != 0)) {
      iVar1 = ___ratelimit(msm_ext_disp_audio_codec_rx_dai_shutdown__rs_77,
                           "msm_ext_disp_audio_codec_rx_dai_shutdown");
      if (iVar1 != 0) {
        _dev_err(*(undefined8 *)(param_2 + 0x10),"%s: teardown_done or cable_status is null\n",
                 "msm_ext_disp_audio_codec_rx_dai_shutdown");
      }
    }
    else {
      if (*(int *)(pcVar2 + -4) != 0x3e37fe6d) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10126c);
        (*pcVar2)();
      }
      iVar1 = (*pcVar2)(*puVar4,0);
      if ((iVar1 < 0) &&
         (iVar1 = ___ratelimit(msm_ext_disp_audio_codec_rx_dai_shutdown__rs_79,
                               "msm_ext_disp_audio_codec_rx_dai_shutdown"), iVar1 != 0)) {
        _dev_err(*(undefined8 *)(param_2 + 0x10),
                 "%s: ext disp core had problems releasing audio flag\n",
                 "msm_ext_disp_audio_codec_rx_dai_shutdown");
      }
      if (*(int *)((code *)puVar4[5] + -4) != -0x58910faa) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1012ac);
        (*pcVar2)();
      }
      (*(code *)puVar4[5])(*puVar4);
    }
    mutex_unlock(puVar4 + 8);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_ext_disp_audio_codec_rx_dai_hw_params @ 0010137c size=912
// signature: undefined msm_ext_disp_audio_codec_rx_dai_hw_params(void)
// callers: []
//------------------------------------------------------------

int msm_ext_disp_audio_codec_rx_dai_hw_params(undefined8 param_1,long param_2,long param_3)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  long lVar10;
  undefined4 uVar11;
  undefined8 *puVar12;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  long local_48;
  
  lVar10 = sp_el0;
  local_48 = *(long *)(lVar10 + 0x638);
  local_50 = 0;
  uVar2 = *(undefined4 *)(param_2 + 0x11c);
  local_60 = 0;
  local_58 = 0;
  puVar12 = *(undefined8 **)(*(long *)(*(long *)(param_3 + 0x58) + 0x18) + 0x98);
  if (puVar12 == (undefined8 *)0x0) {
    iVar5 = ___ratelimit(msm_ext_disp_audio_codec_rx_dai_hw_params__rs,
                         "msm_ext_disp_audio_codec_rx_dai_hw_params");
    if (iVar5 != 0) {
      _dev_err(*(undefined8 *)(param_3 + 0x10),"%s() codec_data is null\n",
               "msm_ext_disp_audio_codec_rx_dai_hw_params");
      iVar5 = -0x16;
      goto LAB_0010164c;
    }
LAB_00101494:
    iVar5 = -0x16;
    goto LAB_0010164c;
  }
  puVar1 = puVar12 + 8;
  mutex_lock(puVar1);
  lVar10 = (long)(int)*(uint *)(param_3 + 8);
  uVar7 = 0x28;
  if (lVar10 != 4) {
    uVar7 = 0x2c;
  }
  local_58 = CONCAT44(*(undefined4 *)((long)puVar12 + lVar10 * 4 + 0x98),uVar7);
  if (4 < *(uint *)(param_3 + 8)) goto LAB_00101704;
  local_50 = *(undefined4 *)((long)puVar12 + lVar10 * 4 + 0x84);
  iVar5 = msm_ext_disp_select_audio_codec(*puVar12,&local_58);
  if ((puVar12[1] == 0) || (iVar5 != 0)) {
    iVar5 = ___ratelimit(msm_ext_disp_audio_codec_rx_dai_hw_params__rs_81,
                         "msm_ext_disp_audio_codec_rx_dai_hw_params");
    if (iVar5 != 0) {
      _dev_err(*(undefined8 *)(param_3 + 0x10),"%s: audio_info_setup is null\n",
               "msm_ext_disp_audio_codec_rx_dai_hw_params");
    }
    mutex_unlock(puVar1);
    iVar5 = -0x16;
    goto LAB_0010164c;
  }
  mutex_unlock(puVar1);
  if (4 < *(uint *)(param_3 + 8)) goto LAB_00101704;
  iVar5 = *(int *)((long)puVar12 + (ulong)*(uint *)(param_3 + 8) * 4 + 0x70);
  if (iVar5 < 0) {
    iVar5 = ___ratelimit(msm_ext_disp_audio_codec_rx_dai_hw_params__rs_83,
                         "msm_ext_disp_audio_codec_rx_dai_hw_params");
    if (iVar5 != 0) {
      if (4 < *(uint *)(param_3 + 8)) goto LAB_00101704;
      _dev_err(*(undefined8 *)(param_3 + 0x10),"%s() ext disp core is not ready (ret val = %d)\n",
               "msm_ext_disp_audio_codec_rx_dai_hw_params",
               *(undefined4 *)((long)puVar12 + (ulong)*(uint *)(param_3 + 8) * 4 + 0x70));
    }
    if (4 < *(uint *)(param_3 + 8)) goto LAB_00101704;
    iVar5 = *(int *)((long)puVar12 + (ulong)*(uint *)(param_3 + 8) * 4 + 0x70);
    goto LAB_0010164c;
  }
  if (iVar5 == 0) {
    iVar5 = ___ratelimit(msm_ext_disp_audio_codec_rx_dai_hw_params__rs_84,
                         "msm_ext_disp_audio_codec_rx_dai_hw_params");
    if (iVar5 == 0) {
      iVar5 = -0x13;
    }
    else {
      if (4 < *(uint *)(param_3 + 8)) goto LAB_00101704;
      _dev_err(*(undefined8 *)(param_3 + 0x10),
               "%s() ext disp cable is not connected (ret val = %d)\n",
               "msm_ext_disp_audio_codec_rx_dai_hw_params",
               *(undefined4 *)((long)puVar12 + (ulong)*(uint *)(param_3 + 8) * 4 + 0x70));
      iVar5 = -0x13;
    }
    goto LAB_0010164c;
  }
  uVar11 = 0;
  uVar9 = uVar2;
  uVar8 = 2;
  switch(uVar2) {
  case 2:
    goto switchD_00101470_caseD_2;
  case 3:
    goto switchD_00101470_caseD_3;
  case 4:
    uVar8 = 6;
    break;
  case 5:
    uVar8 = 10;
    break;
  case 6:
    uVar8 = 0xb;
    break;
  case 7:
    uVar8 = 0x12;
    goto LAB_001015a4;
  case 8:
    uVar8 = 0x13;
LAB_001015a4:
    uVar9 = 0xf;
    goto switchD_00101470_caseD_3;
  default:
    iVar5 = ___ratelimit(msm_ext_disp_audio_codec_rx_dai_hw_params__rs_85,
                         "msm_ext_disp_audio_codec_rx_dai_hw_params");
    if (iVar5 != 0) {
      _dev_err(*(undefined8 *)(param_3 + 0x10),"invalid Channels = %u\n",uVar2);
      iVar5 = -0x16;
      goto LAB_0010164c;
    }
    goto LAB_00101494;
  }
  uVar9 = 7;
switchD_00101470_caseD_3:
  uVar11 = uVar8;
  local_60 = CONCAT44(uVar9,(undefined4)local_60);
switchD_00101470_caseD_2:
  local_70 = *(undefined4 *)(param_2 + 0x128);
  uStack_64 = 0;
  local_60 = local_60 & 0xffffffffffffff00;
  uStack_6c = uVar2;
  local_68 = uVar11;
  mutex_lock(puVar1);
  uVar3 = *(uint *)(param_3 + 8);
  local_58 = CONCAT44(*(undefined4 *)((long)puVar12 + (long)(int)uVar3 * 4 + 0x98),uVar7);
  if (4 < uVar3) {
LAB_00101704:
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x101708);
    (*pcVar4)();
  }
  local_50 = *(undefined4 *)((long)puVar12 + (long)(int)uVar3 * 4 + 0x84);
  iVar5 = msm_ext_disp_select_audio_codec(*puVar12,&local_58);
  if (iVar5 == 0) {
    if (*(int *)((code *)puVar12[1] + -4) != 0x4a93820f) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x101620);
      (*pcVar4)();
    }
    iVar5 = (*(code *)puVar12[1])(*puVar12,&local_70);
  }
  mutex_unlock(puVar1);
  if ((iVar5 < 0) &&
     (iVar6 = ___ratelimit(msm_ext_disp_audio_codec_rx_dai_hw_params__rs_87,
                           "msm_ext_disp_audio_codec_rx_dai_hw_params"), iVar6 != 0)) {
    _dev_err(*(undefined8 *)(param_3 + 0x10),"%s() ext disp core is not ready, rc: %d\n",
             "msm_ext_disp_audio_codec_rx_dai_hw_params",iVar5);
  }
LAB_0010164c:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// init_module @ 00101710 size=92
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = __platform_driver_register(&msm_ext_disp_audio_codec_rx_driver,&__this_module);
  if (iVar1 != 0) {
    _printk(&DAT_001032ba,"msm_ext_disp_audio_codec_rx_init",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00101770 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&msm_ext_disp_audio_codec_rx_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00105000 size=1
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
// _printk @ 00105008 size=1
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
// platform_driver_unregister @ 00105010 size=1
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
// snd_soc_register_component @ 00105018 size=1
// signature: undefined snd_soc_register_component(void)
// callers: [msm_ext_disp_audio_codec_rx_plat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_register_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_unregister_component @ 00105020 size=1
// signature: undefined snd_soc_unregister_component(void)
// callers: [msm_ext_disp_audio_codec_rx_plat_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_unregister_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00105030 size=1
// signature: undefined kmalloc_trace(void)
// callers: [msm_ext_disp_audio_codec_rx_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_parent @ 00105038 size=1
// signature: undefined of_get_parent(void)
// callers: [msm_ext_disp_audio_codec_rx_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_device_by_node @ 00105040 size=1
// signature: undefined of_find_device_by_node(void)
// callers: [msm_ext_disp_audio_codec_rx_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_device_by_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_ext_disp_register_audio_codec @ 00105048 size=1
// signature: undefined msm_ext_disp_register_audio_codec(void)
// callers: [msm_ext_disp_audio_codec_rx_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_ext_disp_register_audio_codec(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00105050 size=1
// signature: undefined __mutex_init(void)
// callers: [msm_ext_disp_audio_codec_rx_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00105058 size=1
// signature: undefined _dev_err(void)
// callers: [msm_ext_disp_audio_codec_rx_dai_shutdown, msm_ext_disp_audio_type_get, msm_ext_disp_audio_codec_rx_probe, msm_ext_disp_audio_codec_rx_dai_hw_params, msm_ext_disp_edid_ctl_info, msm_ext_disp_audio_ack_set, msm_ext_disp_audio_codec_rx_dai_startup, msm_ext_disp_audio_device_get, msm_ext_disp_audio_device_set, msm_ext_disp_edid_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00105060 size=1
// signature: undefined kfree(void)
// callers: [msm_ext_disp_audio_codec_rx_remove, msm_ext_disp_audio_codec_rx_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00105068 size=1
// signature: undefined mutex_lock(void)
// callers: [msm_ext_disp_audio_codec_rx_dai_shutdown, msm_ext_disp_audio_type_get, msm_ext_disp_audio_codec_rx_dai_hw_params, msm_ext_disp_edid_ctl_info, msm_ext_disp_audio_ack_set, msm_ext_disp_audio_codec_rx_dai_startup, msm_ext_disp_audio_device_set, msm_ext_disp_edid_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_ext_disp_select_audio_codec @ 00105070 size=1
// signature: undefined msm_ext_disp_select_audio_codec(void)
// callers: [msm_ext_disp_audio_codec_rx_dai_shutdown, msm_ext_disp_audio_type_get, msm_ext_disp_audio_codec_rx_dai_hw_params, msm_ext_disp_edid_ctl_info, msm_ext_disp_audio_ack_set, msm_ext_disp_audio_codec_rx_dai_startup, msm_ext_disp_edid_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_ext_disp_select_audio_codec(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00105078 size=1
// signature: undefined mutex_unlock(void)
// callers: [msm_ext_disp_audio_codec_rx_dai_shutdown, msm_ext_disp_audio_type_get, msm_ext_disp_audio_codec_rx_dai_hw_params, msm_ext_disp_edid_ctl_info, msm_ext_disp_audio_ack_set, msm_ext_disp_audio_codec_rx_dai_startup, msm_ext_disp_audio_device_set, msm_ext_disp_edid_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00105080 size=1
// signature: undefined ___ratelimit(void)
// callers: [msm_ext_disp_audio_codec_rx_dai_shutdown, msm_ext_disp_audio_type_get, msm_ext_disp_audio_codec_rx_dai_hw_params, msm_ext_disp_edid_ctl_info, msm_ext_disp_audio_ack_set, msm_ext_disp_audio_codec_rx_dai_startup, msm_ext_disp_audio_device_get, msm_ext_disp_audio_device_set, msm_ext_disp_edid_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105088 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [msm_ext_disp_audio_codec_rx_dai_shutdown, msm_ext_disp_audio_type_get, msm_ext_disp_audio_codec_rx_dai_hw_params, msm_ext_disp_edid_ctl_info, msm_ext_disp_audio_ack_set, msm_ext_disp_audio_codec_rx_dai_startup, msm_ext_disp_edid_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00105090 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [msm_ext_disp_edid_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 00105098 size=1
// signature: undefined __warn_printk(void)
// callers: [msm_ext_disp_edid_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_set_runtime_hwparams @ 001050a0 size=1
// signature: undefined snd_soc_set_runtime_hwparams(void)
// callers: [msm_ext_disp_audio_codec_rx_dai_startup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_set_runtime_hwparams(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



