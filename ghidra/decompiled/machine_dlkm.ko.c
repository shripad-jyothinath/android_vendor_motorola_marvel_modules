// Decompiled by Ghidra 12.2
// Program: machine_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// snd_card_notify_user @ 00100984 size=104
// signature: undefined snd_card_notify_user(void)
// callers: [pineapple_ssr_enable, pineapple_ssr_disable]
//------------------------------------------------------------

undefined8 snd_card_notify_user(int param_1)

{
  long lVar1;
  
  lVar1 = snd_card_pdata;
  *(int *)(snd_card_pdata + 0x60) = param_1;
  sysfs_notify(lVar1,0,"card_state");
  if (param_1 == 0) {
    mutex_lock(vote_against_sleep_lock);
    vote_against_sleep_cnt = 0;
    mutex_unlock(vote_against_sleep_lock);
  }
  return 0;
}



//------------------------------------------------------------
// snd_card_set_card_status @ 001009f0 size=24
// signature: undefined snd_card_set_card_status(void)
// callers: [msm_asoc_machine_probe]
//------------------------------------------------------------

undefined8 snd_card_set_card_status(undefined4 param_1)

{
  *(undefined4 *)(snd_card_pdata + 0x60) = param_1;
  return 0;
}



//------------------------------------------------------------
// snd_card_sysfs_init @ 00100a0c size=256
// signature: undefined snd_card_sysfs_init(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int snd_card_sysfs_init(void)

{
  long lVar1;
  int iVar2;
  char local_38 [8];
  undefined2 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  local_38 = (char  [8])s_snd_card_0010b8a8._0_8_;
  snd_card_pdata = kmalloc_trace(___stack_chk_fail,0xdc0,0x68);
  iVar2 = kobject_init_and_add(snd_card_pdata,&snd_card_ktype,_kernel_kobj,local_38);
  if (iVar2 < 0) {
    _printk(&DAT_00109d28,"snd_card_sysfs_init",local_38,iVar2);
  }
  else {
    iVar2 = sysfs_create_file_ns(snd_card_pdata,&card_state_attr,0);
    if (iVar2 < 0) {
      _printk(&DAT_0010a9cd,"snd_card_sysfs_init",local_38);
      kobject_put(snd_card_pdata);
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
// mi2s_tdm_hw_vote_req @ 00100b10 size=260
// signature: undefined mi2s_tdm_hw_vote_req(void)
// callers: [msm_common_snd_hw_params]
//------------------------------------------------------------

int mi2s_tdm_hw_vote_req(long param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x268) == 0)) {
    _printk(&DAT_0010a7a2,"mi2s_tdm_hw_vote_req");
    iVar4 = -0x16;
  }
  else {
    piVar1 = (int *)(param_1 + 0x264);
    if (param_2 == 0) {
      Hint_Prefetch(piVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar3) {
          *piVar1 = *piVar1 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      if (*(int *)(param_1 + 0x264) == 0) {
        digital_cdc_rsc_mgr_hw_vote_disable(*(undefined8 *)(param_1 + 0x268),0);
        iVar4 = 0;
      }
      else if (*(int *)(param_1 + 0x264) < 0) {
        iVar4 = 0;
        *(undefined4 *)(param_1 + 0x264) = 0;
      }
      else {
        iVar4 = 0;
      }
    }
    else {
      if (*(int *)(param_1 + 0x264) == 0) {
        iVar4 = digital_cdc_rsc_mgr_hw_vote_enable(*(long *)(param_1 + 0x268),0);
        if (iVar4 < 0) {
          _printk(&DAT_0010b46c,"mi2s_tdm_hw_vote_req",iVar4);
          return iVar4;
        }
      }
      else {
        iVar4 = 0;
      }
      Hint_Prefetch(piVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar3) {
          *piVar1 = *piVar1 + 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
  }
  return iVar4;
}



//------------------------------------------------------------
// msm_common_snd_hw_params @ 00100c30 size=1044
// signature: undefined msm_common_snd_hw_params(void)
// callers: []
//------------------------------------------------------------

int msm_common_snd_hw_params(long param_1,long param_2)

{
  int *piVar1;
  long lVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  long lVar8;
  size_t sVar9;
  long lVar10;
  undefined *puVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  long lVar15;
  char *pcVar16;
  ulong uVar17;
  undefined8 local_68;
  ulong local_60;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  lVar15 = *(long *)(param_1 + 0x10);
  pcVar16 = *(char **)(*(long *)(lVar15 + 0x10) + 8);
  lVar8 = msm_common_get_pdata(*(undefined8 *)(lVar15 + 8));
  uVar6 = get_mi2s_tdm_auxpcm_intf_index(pcVar16);
  local_68 = 0;
  local_60 = 0;
  if (lVar8 == 0) {
    _dev_err(*(undefined8 *)(*(long *)(lVar15 + 8) + 0x40),"%s: pdata is NULL\n",
             "msm_common_snd_hw_params");
    iVar7 = -0x16;
    goto LAB_00100f10;
  }
  if ((int)uVar6 < 0) {
    iVar7 = 0;
    goto LAB_00100f10;
  }
  if (7 < uVar6) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x101024);
    (*pcVar5)();
  }
  uVar17 = (ulong)uVar6;
  lVar15 = lVar8 + uVar17 * 0x30 + 0xd8;
  mutex_lock(lVar15);
  lVar2 = lVar8 + uVar17 * 4;
  if (*(int *)(lVar2 + 0x248) == 0) {
    sVar9 = strlen(pcVar16);
    lVar10 = strnstr(pcVar16,&DAT_0010a31a,sVar9);
    if (lVar10 == 0) {
      sVar9 = strlen(pcVar16);
      lVar10 = strnstr(pcVar16,&DAT_00109f4d,sVar9);
      if (lVar10 == 0) {
        _printk(&DAT_0010a31e,"msm_common_snd_hw_params",pcVar16);
        iVar7 = 0;
        goto LAB_00100f08;
      }
      if (6 < uVar6) {
        pcVar16 = "get_mi2s_clk_id";
        goto LAB_00100fa4;
      }
      uVar13 = *(uint *)(param_2 + 0x24);
      iVar7 = *(int *)(param_2 + 0x128);
      if (uVar13 == 0) {
        uVar13 = *(uint *)(param_2 + 0x28);
        if (uVar13 != 0) {
          uVar14 = 0x20;
          goto LAB_00100e34;
        }
LAB_00100e68:
        iVar12 = 0x10;
      }
      else {
        uVar14 = 0;
LAB_00100e34:
        uVar13 = (uVar13 & 0xaaaaaaaa) >> 1 | (uVar13 & 0x55555555) << 1;
        uVar13 = (uVar13 & 0xcccccccc) >> 2 | (uVar13 & 0x33333333) << 2;
        uVar13 = (uVar13 & 0xf0f0f0f0) >> 4 | (uVar13 & 0xf0f0f0f) << 4;
        uVar13 = (uVar13 & 0xff00ff00) >> 8 | (uVar13 & 0xff00ff) << 8;
        uVar14 = (uint)LZCOUNT(uVar13 >> 0x10 | uVar13 << 0x10) | uVar14;
        if ((0x20 < uVar14) || ((1L << uVar14 & 0x100000440U) == 0)) goto LAB_00100e68;
        iVar12 = 0x20;
      }
      lVar10 = lVar8 + uVar17 * 4;
      local_68 = CONCAT44(iVar7 * iVar12 * 2,*(undefined4 *)(&DAT_0010bb94 + (long)(int)uVar6 * 4));
      local_60 = (ulong)*(uint *)(lVar10 + 0x2a8);
      if (*(int *)(lVar10 + 0x270) != 0) {
        if (iVar7 < 0x2b110) {
          if (iVar7 != 0xac44) {
            iVar12 = 0x15888;
            goto LAB_00100ecc;
          }
        }
        else if (iVar7 != 0x2b110) {
          iVar12 = 0x56220;
LAB_00100ecc:
          if ((iVar7 != iVar12) && (uVar6 != 4)) goto LAB_00100ee4;
        }
        iVar7 = mi2s_tdm_hw_vote_req(lVar8,1);
        if (iVar7 < 0) goto LAB_00101000;
      }
LAB_00100ee4:
      iVar7 = audio_prm_set_lpass_clk_cfg(&local_68,1);
      if (iVar7 < 0) {
        puVar11 = &DAT_0010a17a;
        goto LAB_00101008;
      }
      goto LAB_00100ef8;
    }
    if (uVar6 < 7) {
      iVar7 = *(int *)(param_2 + 0x128);
      lVar10 = lVar8 + uVar17 * 4;
      local_68 = CONCAT44(*(int *)(lVar8 + 0x228) * iVar7 * 0x20,
                          *(undefined4 *)(&DAT_0010bb78 + (long)(int)uVar6 * 4));
      local_60 = (ulong)*(uint *)(lVar10 + 0x28c);
      if (*(int *)(lVar10 + 0x270) == 0) {
LAB_00100e08:
        iVar7 = audio_prm_set_lpass_clk_cfg(&local_68,1);
        if (-1 < iVar7) goto LAB_00100ef8;
        puVar11 = &DAT_0010b497;
      }
      else {
        if (iVar7 < 0x2b110) {
          if (iVar7 != 0xac44) {
            iVar12 = 0x15888;
            goto LAB_00100dd4;
          }
        }
        else if (iVar7 != 0x2b110) {
          iVar12 = 0x56220;
LAB_00100dd4:
          if ((iVar7 != iVar12) && (uVar6 != 4)) goto LAB_00100e08;
        }
        if (*(long *)(lVar8 + 0x268) == 0) {
          _printk(&DAT_0010a7a2,"mi2s_tdm_hw_vote_req");
          iVar7 = -0x16;
        }
        else {
          if ((*(int *)(lVar8 + 0x264) != 0) ||
             (iVar7 = digital_cdc_rsc_mgr_hw_vote_enable(*(long *)(lVar8 + 0x268),0), -1 < iVar7)) {
            piVar1 = (int *)(lVar8 + 0x264);
            Hint_Prefetch(piVar1,2,0,1);
            do {
              cVar3 = '\x01';
              bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
              if (bVar4) {
                *piVar1 = *piVar1 + 1;
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
            goto LAB_00100e08;
          }
          _printk(&DAT_0010b46c,"mi2s_tdm_hw_vote_req",iVar7);
        }
LAB_00101000:
        puVar11 = &DAT_0010b46c;
      }
LAB_00101008:
      _printk(puVar11,"msm_common_snd_hw_params",iVar7);
    }
    else {
      pcVar16 = "get_tdm_clk_id";
LAB_00100fa4:
      _printk(&DAT_0010afe9,pcVar16,uVar6);
      iVar7 = -0x16;
    }
  }
  else {
    iVar7 = 0;
LAB_00100ef8:
    piVar1 = (int *)(lVar2 + 0x248);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = *piVar1 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
  }
LAB_00100f08:
  mutex_unlock(lVar15);
LAB_00100f10:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// get_mi2s_tdm_auxpcm_intf_index @ 00101054 size=468
// signature: undefined get_mi2s_tdm_auxpcm_intf_index(void)
// callers: [msm_common_snd_hw_params, msm_common_snd_shutdown, msm_common_snd_startup]
//------------------------------------------------------------

undefined8 get_mi2s_tdm_auxpcm_intf_index(char *param_1)

{
  size_t sVar1;
  long lVar2;
  
  sVar1 = strlen(param_1);
  lVar2 = strnstr(param_1,&DAT_0010a31a,sVar1);
  if (lVar2 == 0) {
    sVar1 = strlen(param_1);
    lVar2 = strnstr(param_1,&DAT_00109f4d,sVar1);
    if (lVar2 == 0) {
      sVar1 = strlen(param_1);
      lVar2 = strnstr(param_1,"AUXPCM",sVar1);
      if (lVar2 == 0) {
        return 0xffffffea;
      }
    }
  }
  sVar1 = strlen(param_1);
  lVar2 = strnstr(param_1,"LPAIF_RXTX",sVar1);
  if (lVar2 != 0) {
    return 3;
  }
  sVar1 = strlen(param_1);
  lVar2 = strnstr(param_1,"LPAIF_WSA",sVar1);
  if (lVar2 != 0) {
    return 5;
  }
  sVar1 = strlen(param_1);
  lVar2 = strnstr(param_1,"LPAIF_VA",sVar1);
  if (lVar2 != 0) {
    return 4;
  }
  sVar1 = strlen(param_1);
  lVar2 = strnstr(param_1,"LPAIF_AUD",sVar1);
  sVar1 = strlen(param_1);
  if (lVar2 == 0) {
    lVar2 = strnstr(param_1,"LPAIF",sVar1);
    if (lVar2 != 0) {
      sVar1 = strlen(param_1);
      lVar2 = strnstr(param_1,"PRIMARY",sVar1);
      if (lVar2 != 0) {
        return 0;
      }
      sVar1 = strlen(param_1);
      lVar2 = strnstr(param_1,"SECONDARY",sVar1);
      if (lVar2 != 0) {
        return 1;
      }
    }
  }
  else {
    lVar2 = strnstr(param_1,"PRIMARY",sVar1);
    if (lVar2 != 0) {
      return 6;
    }
    sVar1 = strlen(param_1);
    lVar2 = strnstr(param_1,"SECONDARY",sVar1);
    if (lVar2 != 0) {
      return 2;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// msm_common_snd_startup @ 0010122c size=312
// signature: undefined msm_common_snd_startup(void)
// callers: []
//------------------------------------------------------------

int msm_common_snd_startup(long param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  
  lVar8 = *(long *)(param_1 + 0x10);
  lVar7 = msm_common_get_pdata(*(undefined8 *)(lVar8 + 8));
  uVar5 = get_mi2s_tdm_auxpcm_intf_index(*(undefined8 *)(*(long *)(lVar8 + 0x10) + 8));
  if (lVar7 == 0) {
    _dev_err(*(undefined8 *)(*(long *)(lVar8 + 8) + 0x40),"%s: pdata is NULL\n",
             "msm_common_snd_startup");
    return -0x16;
  }
  if (-1 < *(char *)(*(long *)(lVar8 + 0x10) + 0x80)) {
    snd_soc_set_runtime_hwparams(param_1,dummy_dma_hardware);
  }
  if ((int)uVar5 < 0) {
    return 0;
  }
  if (7 < uVar5) {
LAB_00101350:
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x101354);
    (*pcVar4)();
  }
  lVar8 = lVar7 + (ulong)uVar5 * 0x30 + 0xd8;
  mutex_lock(lVar8);
  if (uVar5 == 7) goto LAB_00101350;
  if (*(long *)(lVar7 + (ulong)uVar5 * 8 + 0xa0) != 0) {
    lVar7 = lVar7 + (ulong)uVar5 * 4;
    if ((*(int *)(lVar7 + 0x22c) == 0) &&
       (iVar6 = msm_cdc_pinctrl_select_active_state(), iVar6 != 0)) {
      _printk(&DAT_0010a9fd,"msm_common_snd_startup",iVar6);
      goto LAB_001012e4;
    }
    piVar1 = (int *)(lVar7 + 0x22c);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = *piVar1 + 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
  }
  iVar6 = 0;
LAB_001012e4:
  mutex_unlock(lVar8);
  return iVar6;
}



//------------------------------------------------------------
// msm_common_snd_shutdown @ 00101370 size=880
// signature: undefined msm_common_snd_shutdown(void)
// callers: []
//------------------------------------------------------------

void msm_common_snd_shutdown(long param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  size_t sVar9;
  undefined *puVar10;
  long *plVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  char *pcVar15;
  ulong uVar16;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  lVar14 = *(long *)(param_1 + 0x10);
  lVar12 = *(long *)(lVar14 + 8);
  lVar8 = msm_common_get_pdata(lVar12);
  lVar13 = *(long *)(param_1 + 0xc0);
  pcVar15 = *(char **)(*(long *)(lVar14 + 0x10) + 8);
  uVar5 = get_mi2s_tdm_auxpcm_intf_index(pcVar15);
  iVar7 = *(int *)(lVar13 + 0x6c);
  local_68 = 0;
  uStack_60 = 0;
  if (lVar8 == 0) {
    _dev_err(*(undefined8 *)(lVar12 + 0x40),"%s: pdata is NULL\n","msm_common_snd_shutdown");
    goto LAB_00101688;
  }
  if ((int)uVar5 < 0) goto LAB_00101688;
  if (7 < uVar5) goto LAB_00101634;
  uVar16 = (ulong)uVar5;
  lVar13 = lVar8 + uVar16 * 0x30 + 0xd8;
  mutex_lock(lVar13);
  piVar1 = (int *)(lVar8 + uVar16 * 4 + 0x248);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar3) {
      *piVar1 = *piVar1 + -1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  if (*piVar1 == 0) {
    sVar9 = strlen(pcVar15);
    lVar14 = strnstr(pcVar15,&DAT_0010a31a,sVar9);
    if (lVar14 == 0) {
      sVar9 = strlen(pcVar15);
      lVar14 = strnstr(pcVar15,&DAT_00109f4d,sVar9);
      if (lVar14 == 0) {
        _printk(&DAT_0010a31e,"msm_common_snd_shutdown",pcVar15);
        if (6 < uVar5) goto LAB_00101634;
      }
      else {
        if (6 < uVar5) {
          pcVar15 = "get_mi2s_clk_id";
          goto LAB_00101624;
        }
        local_68 = CONCAT44(local_68._4_4_,*(undefined4 *)(&DAT_0010bb94 + (long)(int)uVar5 * 4));
        iVar6 = audio_prm_set_lpass_clk_cfg(&local_68,0);
        if (iVar6 < 0) {
          puVar10 = &DAT_0010a341;
          goto LAB_00101644;
        }
      }
    }
    else {
      if (6 < uVar5) {
        pcVar15 = "get_tdm_clk_id";
LAB_00101624:
        _printk(&DAT_0010afe9,pcVar15,uVar5);
LAB_00101634:
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x101638);
        (*pcVar4)();
      }
      local_68 = CONCAT44(local_68._4_4_,*(undefined4 *)(&DAT_0010bb78 + (long)(int)uVar5 * 4));
      iVar6 = audio_prm_set_lpass_clk_cfg(&local_68,0);
      if (iVar6 < 0) {
        puVar10 = &DAT_0010b2db;
LAB_00101644:
        _printk(puVar10,"msm_common_snd_shutdown",iVar6);
      }
    }
    if (*(int *)(lVar8 + uVar16 * 4 + 0x270) != 0) {
      if (iVar7 < 0x2b110) {
        if ((iVar7 != 0xac44) && (iVar7 != 0x15888)) {
LAB_0010159c:
          if (uVar5 != 4) goto LAB_0010142c;
        }
      }
      else if ((iVar7 != 0x2b110) && (iVar7 != 0x56220)) goto LAB_0010159c;
      if (*(long *)(lVar8 + 0x268) == 0) {
        _printk(&DAT_0010a7a2,"mi2s_tdm_hw_vote_req");
      }
      else {
        piVar1 = (int *)(lVar8 + 0x264);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar3) {
            *piVar1 = *piVar1 + -1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        if (*(int *)(lVar8 + 0x264) == 0) {
          digital_cdc_rsc_mgr_hw_vote_disable(*(undefined8 *)(lVar8 + 0x268),0);
        }
        else if (*(int *)(lVar8 + 0x264) < 0) {
          *(undefined4 *)(lVar8 + 0x264) = 0;
        }
      }
    }
  }
  else {
    if (*piVar1 < 0) {
      *piVar1 = 0;
    }
    if (6 < uVar5) goto LAB_00101634;
  }
LAB_0010142c:
  plVar11 = (long *)(lVar8 + uVar16 * 8 + 0xa0);
  if (*plVar11 != 0) {
    piVar1 = (int *)(lVar8 + uVar16 * 4 + 0x22c);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = *piVar1 + -1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    if (*piVar1 == 0) {
      iVar7 = msm_cdc_pinctrl_select_sleep_state(*plVar11);
      if (iVar7 != 0) {
        _dev_err(*(undefined8 *)(lVar12 + 0x40),"%s: pinctrl set actv fail %d\n",
                 "msm_common_snd_shutdown",iVar7);
      }
    }
    else if (*piVar1 < 0) {
      *piVar1 = 0;
    }
  }
  mutex_unlock(lVar13);
LAB_00101688:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_common_snd_init @ 00101714 size=1960
// signature: undefined msm_common_snd_init(void)
// callers: [msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void msm_common_snd_init(long param_1,long param_2)

{
  int *piVar1;
  long lVar2;
  undefined8 *puVar3;
  char acVar4 [8];
  undefined4 uVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  ulong uVar13;
  ulong uVar14;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  char local_a8 [8];
  ulong local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  local_b0 = 0;
  local_c0 = 0;
  local_b8 = 0;
  local_c8 = 0;
  puVar11 = (undefined8 *)kmalloc_trace(_digital_cdc_rsc_mgr_hw_vote_disable,0xdc0,0x2c8);
  if (puVar11 == (undefined8 *)0x0) {
    uVar12 = 0xfffffff4;
  }
  else {
    __mutex_init(puVar11 + 0x1b,"&common_pdata->lock[count]",&msm_common_snd_init___key);
    *(undefined4 *)((long)puVar11 + 0x22c) = 0;
    __mutex_init(puVar11 + 0x21,"&common_pdata->lock[count]",&msm_common_snd_init___key);
    *(undefined4 *)(puVar11 + 0x46) = 0;
    __mutex_init(puVar11 + 0x27,"&common_pdata->lock[count]",&msm_common_snd_init___key);
    *(undefined4 *)((long)puVar11 + 0x234) = 0;
    __mutex_init(puVar11 + 0x2d,"&common_pdata->lock[count]",&msm_common_snd_init___key);
    *(undefined4 *)(puVar11 + 0x47) = 0;
    __mutex_init(puVar11 + 0x33,"&common_pdata->lock[count]",&msm_common_snd_init___key);
    *(undefined4 *)((long)puVar11 + 0x23c) = 0;
    __mutex_init(puVar11 + 0x39,"&common_pdata->lock[count]",&msm_common_snd_init___key);
    *(undefined4 *)(puVar11 + 0x48) = 0;
    __mutex_init(puVar11 + 0x3f,"&common_pdata->lock[count]",&msm_common_snd_init___key);
    *(undefined4 *)((long)puVar11 + 0x244) = 0;
    piVar1 = (int *)(puVar11 + 0x45);
    lVar2 = param_1 + 0x10;
    iVar7 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,tdm-max-slots",piVar1,1,0);
    if (iVar7 < 0) {
      _dev_info(lVar2,"%s: No DT match for tdm max slots\n","msm_common_snd_init");
    }
    if (*piVar1 - 9U < 0xfffffff8) {
      *piVar1 = 8;
      _dev_info(lVar2,"%s: Using default tdm max slot: %d\n","msm_common_snd_init",8);
    }
    uVar13 = devm_clk_get(lVar2,"lpass_audio_hw_vote");
    uVar14 = 0;
    if (uVar13 < 0xfffffffffffff001) {
      uVar14 = uVar13;
    }
    uVar12 = *(undefined8 *)(param_1 + 0x2f8);
    puVar11[0x4d] = uVar14;
    iVar7 = of_property_read_variable_u32_array
                      (uVar12,"qcom,mi2s-tdm-is-hw-vote-needed",&local_c8,7,0);
    if (-1 < iVar7) {
      puVar11[0x4e] = local_c8;
      puVar11[0x4f] = local_c0;
      puVar11[0x50] = local_b8;
      *(undefined4 *)(puVar11 + 0x51) = local_b0;
    }
    iVar7 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,tdm-clk-attribute",&local_c8,7,0);
    if (iVar7 < 0) {
      _dev_info(lVar2,"%s: No DT match for tdm clk attribute, set to default\n",
                "msm_common_snd_init");
      *(undefined8 *)((long)puVar11 + 0x28c) = 0x100000001;
      *(undefined8 *)((long)puVar11 + 0x294) = 0x100000001;
      *(undefined8 *)((long)puVar11 + 0x29c) = 0x100000001;
      *(undefined4 *)((long)puVar11 + 0x2a4) = 1;
    }
    else {
      *(undefined4 *)((long)puVar11 + 0x2a4) = local_b0;
      *(undefined8 *)((long)puVar11 + 0x28c) = local_c8;
      *(undefined8 *)((long)puVar11 + 0x294) = local_c0;
      *(undefined8 *)((long)puVar11 + 0x29c) = local_b8;
    }
    iVar7 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,mi2s-clk-attribute",&local_c8,7,0);
    if (iVar7 < 0) {
      _dev_info(lVar2,"%s: No DT match for mi2s clk attribute, set to default\n",
                "msm_common_snd_init");
      puVar11[0x55] = 0x100000001;
      puVar11[0x56] = 0x100000001;
      puVar11[0x57] = 0x100000001;
      *(undefined4 *)(puVar11 + 0x58) = 1;
    }
    else {
      puVar11[0x55] = local_c8;
      puVar11[0x56] = local_c0;
      puVar11[0x57] = local_b8;
      *(undefined4 *)(puVar11 + 0x58) = local_b0;
    }
    local_68 = 0;
    uStack_60 = 0;
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    uStack_80 = 0;
    local_98 = 0;
    uStack_90 = 0;
    local_a8[0] = '\0';
    local_a8[1] = '\0';
    local_a8[2] = '\0';
    local_a8[3] = '\0';
    local_a8[4] = '\0';
    local_a8[5] = '\0';
    local_a8[6] = '\0';
    local_a8[7] = '\0';
    local_a0 = 0;
    iVar7 = __of_parse_phandle_with_args
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,pri-mi2s-gpios",0,0,0,local_a8);
    uVar12 = *(undefined8 *)(param_1 + 0x2f8);
    if (iVar7 != 0) {
      local_a8 = (char  [8])0x0;
    }
    local_68 = 0;
    uStack_60 = 0;
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    uStack_80 = 0;
    puVar11[0x14] = local_a8;
    local_98 = 0;
    uStack_90 = 0;
    local_a8[0] = '\0';
    local_a8[1] = '\0';
    local_a8[2] = '\0';
    local_a8[3] = '\0';
    local_a8[4] = '\0';
    local_a8[5] = '\0';
    local_a8[6] = '\0';
    local_a8[7] = '\0';
    local_a0 = 0;
    iVar7 = __of_parse_phandle_with_args(uVar12,"qcom,sec-mi2s-gpios",0,0,0,local_a8);
    uVar12 = *(undefined8 *)(param_1 + 0x2f8);
    if (iVar7 != 0) {
      local_a8 = (char  [8])0x0;
    }
    local_68 = 0;
    uStack_60 = 0;
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    uStack_80 = 0;
    puVar11[0x15] = local_a8;
    local_98 = 0;
    uStack_90 = 0;
    local_a8[0] = '\0';
    local_a8[1] = '\0';
    local_a8[2] = '\0';
    local_a8[3] = '\0';
    local_a8[4] = '\0';
    local_a8[5] = '\0';
    local_a8[6] = '\0';
    local_a8[7] = '\0';
    local_a0 = 0;
    iVar7 = __of_parse_phandle_with_args(uVar12,"qcom,tert-mi2s-gpios",0,0,0,local_a8);
    uVar12 = *(undefined8 *)(param_1 + 0x2f8);
    if (iVar7 != 0) {
      local_a8 = (char  [8])0x0;
    }
    local_68 = 0;
    uStack_60 = 0;
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    uStack_80 = 0;
    puVar11[0x16] = local_a8;
    local_98 = 0;
    uStack_90 = 0;
    local_a8[0] = '\0';
    local_a8[1] = '\0';
    local_a8[2] = '\0';
    local_a8[3] = '\0';
    local_a8[4] = '\0';
    local_a8[5] = '\0';
    local_a8[6] = '\0';
    local_a8[7] = '\0';
    local_a0 = 0;
    iVar7 = __of_parse_phandle_with_args(uVar12,"qcom,quat-mi2s-gpios",0,0,0,local_a8);
    uVar12 = *(undefined8 *)(param_1 + 0x2f8);
    if (iVar7 != 0) {
      local_a8 = (char  [8])0x0;
    }
    local_68 = 0;
    uStack_60 = 0;
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    uStack_80 = 0;
    puVar11[0x17] = local_a8;
    local_98 = 0;
    uStack_90 = 0;
    local_a8[0] = '\0';
    local_a8[1] = '\0';
    local_a8[2] = '\0';
    local_a8[3] = '\0';
    local_a8[4] = '\0';
    local_a8[5] = '\0';
    local_a8[6] = '\0';
    local_a8[7] = '\0';
    local_a0 = 0;
    iVar7 = __of_parse_phandle_with_args(uVar12,"qcom,quin-mi2s-gpios",0,0,0,local_a8);
    uVar12 = *(undefined8 *)(param_1 + 0x2f8);
    if (iVar7 != 0) {
      local_a8 = (char  [8])0x0;
    }
    local_68 = 0;
    uStack_60 = 0;
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    uStack_80 = 0;
    puVar11[0x18] = local_a8;
    local_98 = 0;
    uStack_90 = 0;
    local_a8[0] = '\0';
    local_a8[1] = '\0';
    local_a8[2] = '\0';
    local_a8[3] = '\0';
    local_a8[4] = '\0';
    local_a8[5] = '\0';
    local_a8[6] = '\0';
    local_a8[7] = '\0';
    local_a0 = 0;
    iVar7 = __of_parse_phandle_with_args(uVar12,"qcom,sen-mi2s-gpios",0,0,0,local_a8);
    uVar12 = *(undefined8 *)(param_1 + 0x2f8);
    if (iVar7 != 0) {
      local_a8 = (char  [8])0x0;
    }
    local_68 = 0;
    uStack_60 = 0;
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    uStack_80 = 0;
    puVar11[0x19] = local_a8;
    local_98 = 0;
    uStack_90 = 0;
    local_a8[0] = '\0';
    local_a8[1] = '\0';
    local_a8[2] = '\0';
    local_a8[3] = '\0';
    local_a8[4] = '\0';
    local_a8[5] = '\0';
    local_a8[6] = '\0';
    local_a8[7] = '\0';
    local_a0 = 0;
    iVar8 = __of_parse_phandle_with_args(uVar12,"qcom,sep-mi2s-gpios",0,0,0,local_a8);
    iVar7 = *(int *)(param_2 + 0x160);
    acVar4 = local_a8;
    if (iVar8 != 0) {
      acVar4 = (char  [8])0x0;
    }
    puVar11[0x1a] = acVar4;
    uVar12 = devm_kmalloc(lVar2,(long)iVar7,0xdc0);
    uVar5 = *(undefined4 *)(param_2 + 0x160);
    *puVar11 = uVar12;
    _dev_info(param_1 + 0x10,"num_links %d \n",uVar5);
    *(undefined4 *)(puVar11 + 0x13) = *(undefined4 *)(param_2 + 0x160);
    __mutex_init(puVar11 + 0xd,"&common_pdata->aud_dev_lock",&msm_common_snd_init___key_33);
    puVar3 = puVar11 + 1;
    local_a0 = local_a0 & 0xffffffffffff0000;
    local_a8[0] = s_aud_dev_0010b968[0];
    local_a8[1] = s_aud_dev_0010b968[1];
    local_a8[2] = s_aud_dev_0010b968[2];
    local_a8[3] = s_aud_dev_0010b968[3];
    local_a8[4] = s_aud_dev_0010b968[4];
    local_a8[5] = s_aud_dev_0010b968[5];
    local_a8[6] = s_aud_dev_0010b968[6];
    local_a8[7] = s_aud_dev_0010b968[7];
    iVar7 = kobject_init_and_add(puVar3,aud_dev_ktype,_kernel_kobj,local_a8);
    if (iVar7 < 0) {
      _printk(&DAT_00109d28,"aud_dev_sysfs_init",local_a8,iVar7);
    }
    else {
      iVar7 = sysfs_create_file_ns(puVar3,&device_state_attr,0);
      if (iVar7 < 0) {
        _printk(&DAT_00109daf,"aud_dev_sysfs_init",local_a8);
        kobject_put(puVar3);
      }
    }
    msm_common_set_pdata(param_2,puVar11);
    uVar14 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids);
    msm_audio_req = __kmalloc((uVar14 & 0xffffffff) * 0x50,0xdc0);
    if (msm_audio_req != 0) {
      iVar7 = 0;
      iVar8 = -1;
      uVar14 = 0;
      uVar10 = _nr_cpu_ids;
      while( true ) {
        uVar9 = _find_next_bit(&__cpu_possible_mask,uVar10,(long)iVar7);
        uVar10 = _nr_cpu_ids;
        if (_nr_cpu_ids <= uVar9) break;
        if ((uVar9 & 0xffffffe0) != 0) goto LAB_00101eb4;
        iVar7 = *(int *)(_find_next_bit + (ulong)uVar9 * 0x38);
        uVar13 = uVar14;
        if (iVar7 != iVar8) {
          if (3 < uVar14) goto LAB_00101eb4;
          uVar13 = uVar14 + 1;
          (&cluster_first_cpu)[uVar14] = uVar9;
          iVar8 = iVar7;
        }
        iVar7 = uVar9 + 1;
        uVar14 = uVar13;
      }
      if (0x1f < cluster_first_cpu) {
LAB_00101eb4:
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x101eb8);
        (*pcVar6)();
      }
      uVar14 = (ulong)cluster_first_cpu;
      uVar10 = _find_next_bit(dev_pm_qos_add_request + uVar14 * 0x38,_nr_cpu_ids,0);
      if (uVar10 < _nr_cpu_ids) {
        uVar12 = get_cpu_device(uVar10);
        iVar7 = dev_pm_qos_add_request(uVar12,msm_audio_req + (long)(int)uVar10 * 0x50,1,2000000000)
        ;
        if (iVar7 < 0) {
          _printk(&DAT_0010ae9e,"msm_audio_add_qos_request",iVar7,uVar10);
        }
        else {
          cpu_vote_mask = cpu_vote_mask | (byte)(1 << (ulong)(uVar10 & 0x1f));
        }
        uVar10 = _find_next_bit(dev_pm_qos_add_request + uVar14 * 0x38,_nr_cpu_ids,
                                (long)(((ulong)uVar10 << 0x20) + 0x100000000) >> 0x20);
        if (uVar10 < _nr_cpu_ids) {
          uVar12 = get_cpu_device(uVar10);
          iVar7 = dev_pm_qos_add_request
                            (uVar12,msm_audio_req + (long)(int)uVar10 * 0x50,1,2000000000);
          if (iVar7 < 0) {
            _printk(&DAT_0010ae9e,"msm_audio_add_qos_request",iVar7,uVar10);
          }
          else {
            cpu_vote_mask = cpu_vote_mask | (byte)(1 << (ulong)(uVar10 & 0x1f));
          }
        }
      }
    }
    __mutex_init(vote_against_sleep_lock,"&vote_against_sleep_lock",&msm_common_snd_init___key_35);
    uVar12 = 0;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar12);
  }
  return;
}



//------------------------------------------------------------
// msm_common_snd_deinit @ 00101ec0 size=280
// signature: undefined msm_common_snd_deinit(void)
// callers: [msm_asoc_machine_remove]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void msm_common_snd_deinit(long param_1)

{
  uint uVar1;
  ulong uVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 != 0) {
    if (0x1f < cluster_first_cpu) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x101fd8);
      (*pcVar3)();
    }
    if (msm_audio_req != 0) {
      iVar5 = 0;
      uVar2 = (ulong)cluster_first_cpu;
      iVar6 = 0;
      while( true ) {
        uVar4 = _find_next_bit(dev_pm_qos_add_request + uVar2 * 0x38,_nr_cpu_ids,(long)iVar6);
        if (_nr_cpu_ids <= uVar4) break;
        uVar1 = 1 << (ulong)(uVar4 & 0x1f);
        if ((uVar1 & cpu_vote_mask) != 0) {
          iVar5 = dev_pm_qos_remove_request(msm_audio_req + (long)(int)uVar4 * 0x50);
          cpu_vote_mask = cpu_vote_mask & ((byte)uVar1 ^ 0xff);
        }
        if (iVar5 < 0) {
          _printk(&DAT_0010ac8e,"msm_audio_remove_qos_request",iVar5,uVar4);
        }
        iVar6 = uVar4 + 1;
      }
      kfree(msm_audio_req);
    }
  }
  return;
}



//------------------------------------------------------------
// msm_channel_map_info @ 00101fdc size=24
// signature: undefined msm_channel_map_info(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_channel_map_info(undefined8 param_1,long param_2)

{
  *(undefined4 *)(param_2 + 0x40) = 4;
  *(undefined4 *)(param_2 + 0x48) = 0x50;
  return 0;
}



//------------------------------------------------------------
// msm_channel_map_get @ 00101ff8 size=668
// signature: undefined msm_channel_map_get(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int msm_channel_map_get(long param_1,long param_2)

{
  undefined8 *__src;
  long lVar1;
  int iVar2;
  uint *__src_00;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  ulong __n;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  piVar4 = *(int **)(param_1 + 0x80);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_108 = 0;
  uStack_100 = 0;
  local_110 = 0;
  if (piVar4 == (int *)0x0) {
    iVar2 = -0x16;
    goto LAB_00102214;
  }
  if (*piVar4 == 2) {
    uVar3 = piVar4[1];
    uVar5 = 0;
    uVar6 = 0;
    uVar7 = 0;
    uVar8 = 0;
    local_120 = 0;
    local_118 = 0;
    if (uVar3 != 0) {
      uVar9 = 0;
      do {
        if (*(long *)(piVar4 + (long)(int)uVar9 * 2 + 2) != 0) {
          local_120 = 0;
          local_118 = 0;
          iVar2 = snd_soc_dai_get_channel_map
                            (*(long *)(piVar4 + (long)(int)uVar9 * 2 + 2),&local_120,&local_118,
                             (long)&local_120 + 4,(long)&local_118 + 4);
          if ((iVar2 != -0x20c) && (iVar2 != 0)) {
            _printk(&DAT_0010a7fb,"msm_channel_map_get",2,iVar2);
            goto LAB_00102214;
          }
          uVar8 = uVar8 + local_120._4_4_;
          uVar7 = uVar7 + (int)local_120;
          uVar6 = uVar6 | local_118._4_4_;
          uVar5 = uVar5 | (uint)local_118;
          uVar3 = piVar4[1];
          local_110 = CONCAT44(uVar8,uVar7);
          local_b8 = CONCAT44(local_b8._4_4_,uVar6);
          local_108 = CONCAT44(local_108._4_4_,uVar5);
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < uVar3);
    }
    if (uVar8 == 0 && uVar7 == 0) {
LAB_001021c4:
      iVar2 = 0;
      goto LAB_00102214;
    }
    __src_00 = (uint *)kmalloc_trace(_kobject_put,0xdc0,8);
    if (__src_00 == (uint *)0x0) {
LAB_00102210:
      iVar2 = -0xc;
      goto LAB_00102214;
    }
    if (uVar8 != 0) {
      uVar5 = uVar6;
      uVar7 = uVar8;
    }
    iVar2 = 0;
    *__src_00 = uVar7;
    __src_00[1] = uVar5;
    *(undefined8 *)(param_2 + 0x48) = *(undefined8 *)__src_00;
  }
  else if (*piVar4 == 1) {
    iVar2 = snd_soc_dai_get_channel_map
                      (*(undefined8 *)(piVar4 + 2),&local_110,&local_108,(long)&local_110 + 4,
                       &local_b8);
    if (iVar2 != 0) goto LAB_00102214;
    if ((uint)local_110 == 0 && local_110._4_4_ == 0) goto LAB_001021c4;
    uVar8 = (uint)local_110;
    if (local_110._4_4_ != 0) {
      uVar8 = local_110._4_4_;
    }
    __src = &local_108;
    if (local_110._4_4_ != 0) {
      __src = &local_b8;
    }
    if (2 < uVar8) {
      _printk(&DAT_0010b0aa,"msm_channel_map_get",uVar8);
      iVar2 = -0x16;
      goto LAB_00102214;
    }
    __n = (ulong)(uVar8 * 4 + 4);
    __src_00 = (uint *)__kmalloc(__n,0xdc0);
    if (__src_00 == (uint *)0x0) goto LAB_00102210;
    *__src_00 = uVar8;
    if (uVar8 != 0) {
      memcpy(__src_00 + 1,__src,(ulong)uVar8 << 2);
    }
    memcpy((void *)(param_2 + 0x48),__src_00,__n);
    iVar2 = 0;
  }
  else {
    _printk(&DAT_0010b77c,"msm_channel_map_get");
    __src_00 = (uint *)0x0;
    iVar2 = -0x16;
  }
  kfree(__src_00);
LAB_00102214:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// msm_common_get_backend_name @ 00102298 size=236
// signature: undefined msm_common_get_backend_name(void)
// callers: [msm_common_dai_link_init]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * msm_common_get_backend_name(char *param_1,undefined8 *param_2)

{
  long lVar1;
  char *__s1;
  int iVar2;
  void *__dest;
  size_t sVar3;
  void *pvVar4;
  long lVar5;
  undefined4 *puVar6;
  long lVar7;
  undefined *puVar8;
  undefined8 *in_x7;
  uint uVar9;
  long lVar10;
  long lVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  char *__s;
  ulong uVar14;
  long lVar15;
  undefined8 in_d7;
  undefined8 extraout_d24;
  char *pcStack_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  char *pcStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined *puStack_100;
  undefined *puStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  long lStack_d8;
  char *pcStack_d0;
  undefined1 *puStack_c8;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined5 uStack_50;
  undefined3 local_4b;
  undefined5 uStack_48;
  char local_40 [24];
  undefined8 local_28;
  
  lVar7 = sp_el0;
  local_28 = *(long *)(lVar7 + 0x638);
  local_40[0x10] = '\0';
  local_40[0x11] = '\0';
  local_40[0x12] = '\0';
  local_40[0x13] = '\0';
  local_40[0x14] = '\0';
  local_40[0] = '\0';
  local_40[1] = '\0';
  local_40[2] = '\0';
  local_40[3] = '\0';
  local_40[4] = '\0';
  local_40[5] = '\0';
  local_40[6] = '\0';
  local_40[7] = '\0';
  local_40[8] = '\0';
  local_40[9] = '\0';
  local_40[10] = '\0';
  local_40[0xb] = '\0';
  local_40[0xc] = '\0';
  local_40[0xd] = '\0';
  local_40[0xe] = '\0';
  local_40[0xf] = '\0';
  uStack_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_4b = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_80 = 0;
  sscanf(param_1,"%20[^-]-%60s",local_40,&local_80);
  __dest = (void *)kmalloc_trace(_kobject_put,0xdc0,0x15);
  *param_2 = __dest;
  pvVar4 = (void *)0x0;
  if (__dest == (void *)0x0) {
LAB_00102340:
    lVar7 = sp_el0;
    if (*(long *)(lVar7 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return pvVar4;
  }
  sVar3 = strnlen(local_40,0x15);
  if (sVar3 < 0x16) {
    if (sVar3 != 0x15) {
      pvVar4 = memcpy(__dest,local_40,sVar3);
      *(undefined1 *)((long)__dest + sVar3) = 0;
      goto LAB_00102340;
    }
  }
  else {
    fortify_panic("strnlen");
  }
  lVar5 = fortify_panic("__fortify_strlen");
  *in_x7 = in_d7;
  in_x7[1] = extraout_d24;
  puStack_c8 = &UNK_00102384;
  lVar7 = sp_el0;
  lStack_d8 = *(long *)(lVar7 + 0x638);
  lVar7 = *(long *)(lVar5 + 0x10);
  lVar15 = *(long *)(*(long *)(lVar5 + 0x620) + (ulong)*(uint *)(lVar7 + 0x18) * 8);
  puStack_f8 = PTR_msm_channel_map_get_0010b938;
  uStack_f0 = DAT_0010b940;
  uVar13 = *(undefined8 *)(*(long *)(lVar5 + 8) + 0x40);
  uStack_e8 = DAT_0010b948;
  uStack_e0 = DAT_0010b950;
  pcStack_118 = PTR_DAT_0010b918;
  uStack_110 = DAT_0010b920;
  uStack_108 = DAT_0010b928;
  puStack_100 = PTR_msm_channel_map_info_0010b930;
  pcStack_130 = (char *)0x0;
  uStack_128 = DAT_0010b908;
  uStack_120 = DAT_0010b910;
  pcStack_d0 = local_40 + 0x20;
  if (lVar15 == 0) {
    puVar8 = &DAT_0010b4c6;
  }
  else {
    uVar12 = *(undefined8 *)(lVar15 + 0x58);
    msm_common_get_backend_name(*(undefined8 *)(lVar7 + 8),&pcStack_130);
    __s1 = pcStack_130;
    if (pcStack_130 != (char *)0x0) {
      puVar6 = (undefined4 *)devm_kmalloc(uVar13,0x48,0xdc0);
      if (puVar6 == (undefined4 *)0x0) {
LAB_00102558:
        pvVar4 = (void *)0xfffffff4;
      }
      else {
        iVar2 = strncmp(__s1,"SLIM",4);
        if ((iVar2 == 0) || (iVar2 = strncmp(__s1,"CODEC_DMA",9), iVar2 == 0)) {
          sVar3 = strlen(*(char **)(lVar7 + 8));
          uVar14 = (ulong)((int)sVar3 + 0xd);
          __s = (char *)__kmalloc(uVar14,0xdc0);
          if (__s == (char *)0x0) goto LAB_00102558;
          snprintf(__s,uVar14,"%s %s",*(undefined8 *)(lVar7 + 8),"Channel Map");
          uStack_e0 = 0;
          pcStack_118 = __s;
          uVar14 = snd_soc_add_component_controls(uVar12,&uStack_128,1);
          pvVar4 = (void *)(uVar14 & 0xffffffff);
          lVar7 = snd_soc_card_get_kcontrol(*(undefined8 *)(lVar5 + 8),__s);
          if (lVar7 != 0) {
            *(long *)(puVar6 + 2) = lVar15;
            puVar6[1] = 1;
            iVar2 = strncmp(__s1,"SLIM",4);
            if (iVar2 == 0) {
              *puVar6 = 1;
            }
            else {
              lVar15 = *(long *)(lVar5 + 0x10);
              *puVar6 = 2;
              if ((*(uint *)(lVar15 + 0x28) < 9) &&
                 (puVar6[1] = *(uint *)(lVar15 + 0x28), *(int *)(lVar15 + 0x28) != 0)) {
                uVar9 = 0;
                lVar10 = *(long *)(lVar5 + 0x620);
                do {
                  lVar11 = *(long *)(lVar10 + (ulong)(uVar9 + *(int *)(lVar15 + 0x18)) * 8);
                  if (lVar11 == 0) break;
                  lVar1 = (long)(int)uVar9;
                  uVar9 = uVar9 + 1;
                  *(long *)(puVar6 + lVar1 * 2 + 2) = lVar11;
                } while (uVar9 < *(uint *)(lVar15 + 0x28));
              }
            }
            *(undefined4 **)(lVar7 + 0x80) = puVar6;
            goto LAB_0010256c;
          }
          _printk(&DAT_00109bdd,__s);
          pvVar4 = (void *)0xffffffea;
        }
        else {
          pvVar4 = (void *)0x0;
          __s = (char *)0x0;
LAB_0010256c:
          if ((kregister_pm_qos_latency_controls & 1) == 0) {
            lVar7 = snd_soc_rtdcom_lookup(lVar5,"lpass-cdc");
            if (lVar7 == 0) {
              _printk(&DAT_0010a59b,"msm_register_pm_qos_latency_controls");
            }
            else {
              iVar2 = snd_soc_add_component_controls(lVar7,card_mixer_controls,3);
              if (iVar2 < 0) {
                _printk(&DAT_0010b200,"msm_register_pm_qos_latency_controls",iVar2);
              }
              else {
                kregister_pm_qos_latency_controls = 1;
              }
            }
          }
        }
        if (__s != (char *)0x0) {
          kfree(__s);
        }
      }
      kfree(__s1);
      goto LAB_001025bc;
    }
    puVar8 = &DAT_00109f52;
  }
  _printk(puVar8,"msm_common_dai_link_init");
  pvVar4 = (void *)0xffffffea;
LAB_001025bc:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != lStack_d8) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pvVar4;
}



//------------------------------------------------------------
// msm_common_dai_link_init @ 00102388 size=740
// signature: undefined msm_common_dai_link_init(void)
// callers: [msm_int_wsa881x_init, msm_int_wsa_init, msm_tx_codec_init, msm_rx_tx_codec_init, msm_wcn_init, msm_wcn_init_btfm, msm_int_wsa2_init]
//------------------------------------------------------------

undefined4 msm_common_dai_link_init(long param_1)

{
  long lVar1;
  char *__s1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  size_t sVar5;
  long lVar6;
  undefined *puVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  char *param0;
  ulong param1;
  long lVar13;
  char *local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  char *local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined *puStack_80;
  undefined *local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x10);
  lVar13 = *(long *)(*(long *)(param_1 + 0x620) + (ulong)*(uint *)(lVar6 + 0x18) * 8);
  local_78 = PTR_msm_channel_map_get_0010b938;
  uStack_70 = DAT_0010b940;
  uVar12 = *(undefined8 *)(*(long *)(param_1 + 8) + 0x40);
  local_68 = DAT_0010b948;
  local_60 = DAT_0010b950;
  local_98 = PTR_DAT_0010b918;
  uStack_90 = DAT_0010b920;
  local_88 = DAT_0010b928;
  puStack_80 = PTR_msm_channel_map_info_0010b930;
  local_b0 = (char *)0x0;
  uStack_a8 = DAT_0010b908;
  local_a0 = DAT_0010b910;
  if (lVar13 == 0) {
    puVar7 = &DAT_0010b4c6;
  }
  else {
    uVar11 = *(undefined8 *)(lVar13 + 0x58);
    msm_common_get_backend_name(*(undefined8 *)(lVar6 + 8),&local_b0);
    __s1 = local_b0;
    if (local_b0 != (char *)0x0) {
      puVar4 = (undefined4 *)devm_kmalloc(uVar12,0x48,0xdc0);
      if (puVar4 == (undefined4 *)0x0) {
LAB_00102558:
        uVar3 = 0xfffffff4;
      }
      else {
        iVar2 = strncmp(__s1,"SLIM",4);
        if ((iVar2 == 0) || (iVar2 = strncmp(__s1,"CODEC_DMA",9), iVar2 == 0)) {
          sVar5 = strlen(*(char **)(lVar6 + 8));
          param1 = (ulong)((int)sVar5 + 0xd);
          param0 = (char *)__kmalloc(param1,0xdc0);
          if (param0 == (char *)0x0) goto LAB_00102558;
          snprintf(param0,param1,"%s %s",*(char **)(lVar6 + 8),"Channel Map");
          local_60 = 0;
          local_98 = param0;
          uVar3 = snd_soc_add_component_controls(uVar11,&uStack_a8,1);
          lVar6 = snd_soc_card_get_kcontrol(*(undefined8 *)(param_1 + 8),param0);
          if (lVar6 != 0) {
            *(long *)(puVar4 + 2) = lVar13;
            puVar4[1] = 1;
            iVar2 = strncmp(__s1,"SLIM",4);
            if (iVar2 == 0) {
              *puVar4 = 1;
            }
            else {
              lVar13 = *(long *)(param_1 + 0x10);
              *puVar4 = 2;
              if ((*(uint *)(lVar13 + 0x28) < 9) &&
                 (puVar4[1] = *(uint *)(lVar13 + 0x28), *(int *)(lVar13 + 0x28) != 0)) {
                uVar8 = 0;
                lVar9 = *(long *)(param_1 + 0x620);
                do {
                  lVar10 = *(long *)(lVar9 + (ulong)(uVar8 + *(int *)(lVar13 + 0x18)) * 8);
                  if (lVar10 == 0) break;
                  lVar1 = (long)(int)uVar8;
                  uVar8 = uVar8 + 1;
                  *(long *)(puVar4 + lVar1 * 2 + 2) = lVar10;
                } while (uVar8 < *(uint *)(lVar13 + 0x28));
              }
            }
            *(undefined4 **)(lVar6 + 0x80) = puVar4;
            goto LAB_0010256c;
          }
          _printk(&DAT_00109bdd,param0);
          uVar3 = 0xffffffea;
        }
        else {
          uVar3 = 0;
          param0 = (char *)0x0;
LAB_0010256c:
          if ((kregister_pm_qos_latency_controls & 1) == 0) {
            lVar6 = snd_soc_rtdcom_lookup(param_1,"lpass-cdc");
            if (lVar6 == 0) {
              _printk(&DAT_0010a59b,"msm_register_pm_qos_latency_controls");
            }
            else {
              iVar2 = snd_soc_add_component_controls(lVar6,card_mixer_controls,3);
              if (iVar2 < 0) {
                _printk(&DAT_0010b200,"msm_register_pm_qos_latency_controls",iVar2);
              }
              else {
                kregister_pm_qos_latency_controls = 1;
              }
            }
          }
        }
        if (param0 != (char *)0x0) {
          kfree(param0);
        }
      }
      kfree(__s1);
      goto LAB_001025bc;
    }
    puVar7 = &DAT_00109f52;
  }
  _printk(puVar7,"msm_common_dai_link_init");
  uVar3 = 0xffffffea;
LAB_001025bc:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// snd_card_sysfs_show @ 00102670 size=60
// signature: undefined snd_card_sysfs_show(void)
// callers: []
//------------------------------------------------------------

long snd_card_sysfs_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x20,"%d",(ulong)*(uint *)(snd_card_pdata + 0x60));
  return (long)iVar1;
}



//------------------------------------------------------------
// snd_card_sysfs_store @ 001026b0 size=84
// signature: undefined snd_card_sysfs_store(void)
// callers: []
//------------------------------------------------------------

undefined8 snd_card_sysfs_store(undefined8 param_1,undefined8 param_2,char *param_3)

{
  sscanf(param_3,"%d",snd_card_pdata + 0x60);
  sysfs_notify(snd_card_pdata,0,"card_state");
  return 0;
}



//------------------------------------------------------------
// aud_dev_sysfs_store @ 00102708 size=276
// signature: undefined aud_dev_sysfs_store(void)
// callers: []
//------------------------------------------------------------

ulong aud_dev_sysfs_store(long param_1,undefined8 param_2,char *param_3,ulong param_4)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  if (param_4 < 0xb) {
    uVar2 = sscanf(param_3,"%d %d",(int *)((long)&local_30 + 4),(int *)&local_30);
    uVar3 = (ulong)uVar2;
    if (local_30._4_4_ < *(uint *)(param_1 + 0x90)) {
      if ((uint)local_30 < 2) {
        *(char *)(*(long *)(param_1 + -8) + (ulong)local_30._4_4_) = (char)local_30;
      }
      else {
        uVar3 = _printk(&DAT_0010a833,"aud_dev_sysfs_store",local_30 & 0xffffffff);
        if ((uint)local_30 == 9) {
                    /* WARNING: Subroutine does not return */
          panic("upd trigger panic");
        }
        param_4 = 0xffffffffffffffea;
      }
    }
    else {
      uVar3 = _printk(&DAT_0010a3a0,"aud_dev_sysfs_store");
      param_4 = 0xffffffffffffffea;
    }
  }
  else {
    uVar3 = _printk(&DAT_0010a069,"aud_dev_sysfs_store");
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return param_4;
}



//------------------------------------------------------------
// msm_qos_ctl_get @ 00102820 size=20
// signature: undefined msm_qos_ctl_get(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_qos_ctl_get(undefined8 param_1,long param_2)

{
  *(undefined4 *)(param_2 + 0x48) = qos_vote_status;
  return 0;
}



//------------------------------------------------------------
// msm_qos_ctl_put @ 00102838 size=480
// signature: undefined msm_qos_ctl_put(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 msm_qos_ctl_put(undefined8 param_1,long param_2)

{
  bool bVar1;
  code *pcVar2;
  uint uVar3;
  ulong uVar4;
  ulong uVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  long local_40;
  long local_38;
  
  lVar7 = sp_el0;
  local_38 = *(long *)(lVar7 + 0x638);
  qos_vote_status = *(int *)(param_2 + 0x48);
  if (0x1f < cluster_first_cpu) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x102a14);
    (*pcVar2)();
  }
  pcVar2 = dev_pm_qos_add_request + (ulong)cluster_first_cpu * 0x38;
  if (qos_vote_status == 0) {
    if ((qos_client_active_cnt == 0) ||
       (qos_client_active_cnt = qos_client_active_cnt + -1, qos_client_active_cnt == 0)) {
      msm_audio_update_qos_request(2000000000);
      local_40 = walt_get_cpus_taken();
      if (local_40 != 0) {
        iVar6 = 0;
        do {
          uVar3 = _find_next_bit(&local_40,_nr_cpu_ids,(long)iVar6);
          iVar6 = uVar3 + 1;
        } while (uVar3 < _nr_cpu_ids);
        if (local_40 != 0) {
          walt_unset_cpus_taken(pcVar2);
          local_40 = walt_get_cpus_taken();
          if (local_40 != 0) {
            iVar6 = 0;
            do {
              uVar3 = _find_next_bit(&local_40,_nr_cpu_ids,(long)iVar6);
              iVar6 = uVar3 + 1;
            } while (uVar3 < _nr_cpu_ids);
          }
        }
      }
    }
  }
  else {
    if (latency_pm_qos_req._72_8_ != 0) {
      dev_pm_qos_remove_request(latency_pm_qos_req);
    }
    iVar6 = qos_client_active_cnt + 1;
    bVar1 = qos_client_active_cnt == 0;
    qos_client_active_cnt = iVar6;
    if (bVar1) {
      msm_audio_update_qos_request(300);
      lVar8 = *(long *)pcVar2;
      local_40 = walt_get_cpus_taken();
      lVar7 = 0;
      if (local_40 != 0) {
        uVar5 = (ulong)_nr_cpu_ids;
        do {
          uVar4 = _find_next_bit(&local_40,uVar5,(long)(int)lVar7);
          uVar5 = (ulong)_nr_cpu_ids;
          lVar7 = uVar4 + 1;
        } while ((uVar4 & 0xffffffff) < uVar5);
        lVar7 = local_40;
      }
      if (lVar7 != lVar8) {
        walt_set_cpus_taken(pcVar2);
        local_40 = walt_get_cpus_taken();
        if (local_40 != 0) {
          iVar6 = 0;
          do {
            uVar3 = _find_next_bit(&local_40,_nr_cpu_ids,(long)iVar6);
            iVar6 = uVar3 + 1;
          } while (uVar3 < _nr_cpu_ids);
        }
      }
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// msm_lpi_logging_enable_get @ 00102a1c size=20
// signature: undefined msm_lpi_logging_enable_get(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_lpi_logging_enable_get(undefined8 param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) = (ulong)lpi_pcm_logging_enable;
  return 0;
}



//------------------------------------------------------------
// msm_lpi_logging_enable_put @ 00102a34 size=52
// signature: undefined msm_lpi_logging_enable_put(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_lpi_logging_enable_put(undefined8 param_1,long param_2)

{
  lpi_pcm_logging_enable = *(long *)(param_2 + 0x48) != 0;
  audio_prm_set_lpi_logging_status();
  return 0;
}



//------------------------------------------------------------
// msm_vote_against_sleep_ctl_get @ 00102a6c size=20
// signature: undefined msm_vote_against_sleep_ctl_get(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_vote_against_sleep_ctl_get(undefined8 param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) = (ulong)vote_against_sleep_enable;
  return 0;
}



//------------------------------------------------------------
// msm_vote_against_sleep_ctl_put @ 00102a84 size=224
// signature: undefined msm_vote_against_sleep_ctl_put(void)
// callers: []
//------------------------------------------------------------

int msm_vote_against_sleep_ctl_put(undefined8 param_1,long param_2)

{
  int iVar1;
  
  mutex_lock(vote_against_sleep_lock);
  vote_against_sleep_enable = *(long *)(param_2 + 0x48) != 0;
  if (*(long *)(param_2 + 0x48) == 0) {
    if (vote_against_sleep_cnt == 1) {
      iVar1 = audio_prm_set_vote_against_sleep(0);
    }
    else {
      iVar1 = 0;
    }
    if (vote_against_sleep_cnt != 0) {
      vote_against_sleep_cnt = vote_against_sleep_cnt + -1;
    }
  }
  else if (vote_against_sleep_cnt == 0) {
    vote_against_sleep_cnt = vote_against_sleep_cnt + 1;
    iVar1 = audio_prm_set_vote_against_sleep(1);
    if (iVar1 < 0) {
      if (vote_against_sleep_cnt != 0) {
        vote_against_sleep_cnt = vote_against_sleep_cnt + -1;
      }
      _printk(&DAT_001099bb,"msm_vote_against_sleep_ctl_put",iVar1);
    }
  }
  else {
    iVar1 = 0;
    vote_against_sleep_cnt = vote_against_sleep_cnt + 1;
  }
  mutex_unlock(vote_against_sleep_lock);
  return iVar1;
}



//------------------------------------------------------------
// msm_audio_update_qos_request @ 00102b64 size=344
// signature: undefined msm_audio_update_qos_request(void)
// callers: [msm_qos_ctl_put]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void msm_audio_update_qos_request(undefined4 param_1)

{
  ulong uVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  
  if (0x1f < cluster_first_cpu) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x102cbc);
    (*pcVar2)();
  }
  if (msm_audio_req == 0) {
    return;
  }
  uVar1 = (ulong)cluster_first_cpu;
  uVar3 = _find_next_bit(dev_pm_qos_add_request + uVar1 * 0x38,_nr_cpu_ids,0);
  if (_nr_cpu_ids <= uVar3) {
    return;
  }
  if ((cpu_vote_mask >> (ulong)(uVar3 & 0x1f) & 1) == 0) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = dev_pm_qos_update_request(msm_audio_req + (long)(int)uVar3 * 0x50,param_1);
    if (uVar4 < 2) goto LAB_00102c08;
  }
  _printk(&DAT_0010a84c,"msm_audio_update_qos_request",uVar3,uVar4);
LAB_00102c08:
  uVar3 = _find_next_bit(dev_pm_qos_add_request + uVar1 * 0x38,_nr_cpu_ids,(long)(int)(uVar3 + 1));
  if (uVar3 < _nr_cpu_ids) {
    if ((cpu_vote_mask >> (ulong)(uVar3 & 0x1f) & 1) != 0) {
      uVar4 = dev_pm_qos_update_request(msm_audio_req + (long)(int)uVar3 * 0x50,param_1);
    }
    if (1 < uVar4) {
      _printk(&DAT_0010a84c,"msm_audio_update_qos_request",uVar3,uVar4);
    }
  }
  return;
}



//------------------------------------------------------------
// msm_common_get_pdata @ 00102cc0 size=24
// signature: undefined msm_common_get_pdata(void)
// callers: [msm_common_snd_hw_params, msm_common_snd_shutdown, msm_common_snd_startup]
//------------------------------------------------------------

undefined8 msm_common_get_pdata(long param_1)

{
  if (*(long *)(param_1 + 0x318) == 0) {
    return 0;
  }
  return *(undefined8 *)(*(long *)(param_1 + 0x318) + 8);
}



//------------------------------------------------------------
// msm_common_set_pdata @ 00102cdc size=16
// signature: undefined msm_common_set_pdata(void)
// callers: [msm_common_snd_init]
//------------------------------------------------------------

void msm_common_set_pdata(long param_1,undefined8 param_2)

{
  if (*(long *)(param_1 + 0x318) != 0) {
    *(undefined8 *)(*(long *)(param_1 + 0x318) + 8) = param_2;
  }
  return;
}



//------------------------------------------------------------
// msm_asoc_machine_probe @ 00102cf0 size=3612
// signature: undefined msm_asoc_machine_probe(void)
// callers: []
//------------------------------------------------------------

int msm_asoc_machine_probe(long param_1)

{
  undefined *puVar1;
  long *plVar2;
  int *piVar3;
  int *piVar4;
  long *plVar5;
  size_t sVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  void *__src;
  ulong uVar13;
  uint uVar14;
  undefined8 *puVar15;
  uint uVar16;
  long lVar17;
  undefined8 uVar18;
  uint *puVar19;
  undefined *puVar20;
  undefined1 *puVar21;
  uint uVar22;
  char *pcVar23;
  undefined *puVar24;
  undefined **ppuVar25;
  int local_bc;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar10 = sp_el0;
  puVar1 = (undefined *)(param_1 + 0x10);
  local_68 = *(long *)(lVar10 + 0x638);
  if (*(long *)(param_1 + 0x2f8) == 0) {
    _dev_err(puVar1,"%s: No platform supplied from device tree\n","msm_asoc_machine_probe");
    iVar7 = -0x16;
    goto LAB_00103a08;
  }
  puVar9 = (undefined *)devm_kmalloc(puVar1,0xb0,0xdc0);
  if (puVar9 == (undefined *)0x0) {
    iVar7 = -0xc;
    goto LAB_00103a08;
  }
  plVar2 = (long *)(param_1 + 0x2f8);
  of_property_read_variable_u32_array(*plVar2,"qcom,wcd-disabled",puVar9 + 0x70,1,0);
  piVar3 = (int *)(puVar9 + 0x6c);
  iVar7 = of_property_read_variable_u32_array(*plVar2,"qcom,wsa-max-devs",piVar3,1,0);
  if (iVar7 < 0) {
    _dev_info(puVar1,"%s: wsa-max-devs property missing in DT %s, ret = %d\n",
              "msm_asoc_machine_probe",*(undefined8 *)(*plVar2 + 0x10),iVar7);
    *piVar3 = 0;
  }
  lVar10 = of_find_property(*plVar2,"qcom,dedicated-wsa2",0);
  piVar4 = (int *)(puVar9 + 0xa8);
  lVar11 = *plVar2;
  puVar9[0xa0] = lVar10 != 0;
  iVar7 = of_property_read_variable_u32_array(lVar11,"qcom,wsa-hac-en",piVar4,1,0);
  if (iVar7 < 0) {
    *piVar4 = 0;
  }
  local_b8 = (ulong)local_b8._4_4_ << 0x20;
  lVar10 = of_match_node(&pineapple_asoc_machine_of_match,*plVar2);
  if (lVar10 == 0) {
    iVar7 = ___ratelimit(populate_snd_card_dailinks__rs,"populate_snd_card_dailinks");
    if (iVar7 != 0) {
      _dev_err(puVar1,"%s: No DT match found for sound card\n","populate_snd_card_dailinks");
    }
LAB_00102fac:
    pcVar23 = "%s: Card uninitialized\n";
LAB_00103644:
    _dev_err(puVar1,pcVar23,"msm_asoc_machine_probe");
    iVar7 = -0x16;
  }
  else {
    pcVar23 = *(char **)(lVar10 + 0xc0);
    iVar7 = strcmp(pcVar23,"codec");
    if (iVar7 == 0) {
      puVar21 = msm_pineapple_dai_links;
      if (*piVar4 == 0) {
        memcpy(msm_pineapple_dai_links,&msm_rx_tx_cdc_dma_be_dai_links,0x750);
        if (*piVar3 - 1U < 2) {
          memcpy(msm_pineapple_dai_links + 0x750,&msm_wsa_cdc_dma_be_dai_links,0x4e0);
          lVar11 = 0xf;
        }
        else if (*piVar3 == 4) {
          lVar11 = of_find_property(*plVar2,"qcom,dedicated-wsa2",0);
          if (lVar11 == 0) {
            memcpy(msm_pineapple_dai_links + 0x750,&msm_wsa2_cdc_dma_be_dai_links,0x410);
            memcpy(msm_pineapple_dai_links + 0xb60,&msm_wsa_wsa2_cdc_dma_be_dai_links,0x410);
            lVar11 = 0x13;
          }
          else {
            memcpy(msm_pineapple_dai_links + 0x750,&msm_wsa_cdc_dma_be_dai_links,0x4e0);
            memcpy(msm_pineapple_dai_links + 0xc30,&msm_wsa2_cdc_dma_be_dai_links,0x410);
            lVar11 = 0x14;
          }
        }
        else {
          lVar11 = 9;
        }
      }
      else {
        memcpy(msm_pineapple_dai_links,&msm_hac_wsa_cdc_dma_be_dai_links,0x340);
        memcpy(msm_pineapple_dai_links + 0x340,&msm_tx_cdc_dma_be_dai_links,0x1a0);
        lVar11 = 6;
      }
      memcpy(msm_pineapple_dai_links + lVar11 * 0xd0,&msm_va_cdc_dma_be_dai_links,0x270);
      memcpy(msm_pineapple_dai_links + lVar11 * 0xd0 + 0x270,&msm_common_be_dai_links,0x750);
      uVar22 = (int)lVar11 + 0xc;
      iVar7 = of_property_read_variable_u32_array(*plVar2,"qcom,mi2s-audio-intf",&local_b8,1,0);
      if ((-1 < iVar7) && ((int)local_b8 != 0)) {
        iVar8 = of_property_read_variable_u32_array(*plVar2,"custom-mi2s-audio-intf",&local_b8,1,0);
        iVar7 = iVar8;
        if (-1 < iVar8) {
          iVar7 = 0;
        }
        _dev_info(puVar1,"%s:read custom-mi2s-audio-intf:rc=%d,val=%d","populate_snd_card_dailinks",
                  iVar7,local_b8 & 0xffffffff);
        if ((iVar8 < 0) || ((int)local_b8 != 1)) {
          ppuVar25 = &msm_mi2s_dai_links;
        }
        else {
          _dev_info(puVar1,"%s: add msm_mi2s_aw882xx_dai_links","populate_snd_card_dailinks");
          ppuVar25 = &msm_mi2s_aw882xx_dai_links;
        }
        memcpy(msm_pineapple_dai_links + (ulong)uVar22 * 0xd0,ppuVar25,0xb60);
        uVar22 = (int)lVar11 + 0x1a;
      }
      iVar7 = of_property_read_variable_u32_array(*plVar2,"qcom,tdm-audio-intf",&local_b8,1,0);
      if ((-1 < iVar7) && ((int)local_b8 != 0)) {
        memcpy(msm_pineapple_dai_links + (ulong)uVar22 * 0xd0,&msm_tdm_dai_links,0xb60);
        uVar22 = uVar22 + 0xe;
      }
      iVar7 = of_property_read_variable_u32_array(*plVar2,"qcom,ext-disp-audio-rx",&local_b8,1,0);
      if (((-1 < iVar7) && ((int)local_b8 != 0)) &&
         (uVar12 = socinfo_get_part_info(4), (uVar12 & 1) == 0)) {
        memcpy(msm_pineapple_dai_links + (ulong)uVar22 * 0xd0,&ext_disp_be_dai_link,0xd0);
        uVar22 = uVar22 + 1;
      }
      iVar7 = of_property_read_variable_u32_array(*plVar2,"qcom,wcn-btfm-proxy",&local_b8,1,0);
      if ((iVar7 < 0) || ((int)local_b8 == 0)) {
        iVar7 = of_property_read_variable_u32_array(*plVar2,"qcom,wcn-bt",&local_b8,1,0);
        if ((iVar7 < 0) || ((int)local_b8 == 0)) {
          iVar7 = of_property_read_variable_u32_array(*plVar2,"qcom,wcn-btfm",&local_b8,1,0);
          ppuVar25 = (undefined **)snd_soc_card_pineapple_msm;
          if ((-1 < iVar7) && ((int)local_b8 != 0)) {
            memcpy(msm_pineapple_dai_links + (ulong)uVar22 * 0xd0,&msm_wcn_btfm_be_dai_links,0x270);
            uVar22 = uVar22 + 3;
          }
          goto LAB_00103170;
        }
        memcpy(msm_pineapple_dai_links + (ulong)uVar22 * 0xd0,&msm_wcn_be_dai_links,0x1a0);
        uVar22 = uVar22 + 2;
      }
      else {
        memcpy(msm_pineapple_dai_links + (ulong)uVar22 * 0xd0,&msm_wcn_btfm_proxy_be_dai_links,0x270
              );
        uVar22 = uVar22 + 3;
      }
      ppuVar25 = (undefined **)snd_soc_card_pineapple_msm;
    }
    else {
      iVar7 = strcmp(pcVar23,"stub_codec");
      if (iVar7 != 0) goto LAB_00102fac;
      puVar21 = (undefined1 *)&msm_stub_dai_links;
      memcpy(&msm_stub_dai_links,&msm_stub_be_dai_links,0x1a0);
      uVar22 = 2;
      ppuVar25 = &snd_soc_card_stub_msm;
    }
LAB_00103170:
    ppuVar25[0x2b] = puVar21;
    *(uint *)(ppuVar25 + 0x2c) = uVar22;
    iVar7 = strcmp(*(char **)(lVar10 + 0xc0),"codec");
    if (iVar7 == 0) {
      ppuVar25[0x1f] = msm_snd_card_late_probe;
    }
    lVar10 = of_match_node(&pineapple_asoc_machine_of_match,*plVar2);
    if (lVar10 == 0) {
      pcVar23 = "%s: No DT match found for sound card\n";
      goto LAB_00103644;
    }
    ppuVar25[8] = puVar1;
    *(undefined ***)(param_1 + 0xa8) = ppuVar25;
    ppuVar25[99] = puVar9;
    local_b8 = 0;
    local_bc = 0;
    uVar12 = nvmem_cell_get(puVar1,"adsp_variant");
    if ((uVar12 == 0) || (0xfffffffffffff000 < uVar12)) {
LAB_0010324c:
      pcVar23 = "qcom,model";
    }
    else {
      __src = (void *)nvmem_cell_read(uVar12,&local_b8);
      nvmem_cell_put(uVar12);
      if ((__src == (void *)0x0) || ((void *)0xfffffffffffff000 < __src)) goto LAB_0010324c;
      if (local_b8 - 5 < 0xfffffffffffffffb || local_b8 == 0) {
        kfree(__src);
        goto LAB_0010324c;
      }
      memcpy(&local_bc,__src,local_b8);
      kfree(__src);
      if (local_bc == 0) goto LAB_0010324c;
      pcVar23 = "qcom,sku-model";
    }
    iVar7 = snd_soc_of_parse_card_name(ppuVar25,pcVar23);
    if (iVar7 == 0) {
      iVar7 = strcmp(*(char **)(lVar10 + 0xc0),"codec");
      if ((iVar7 == 0) &&
         (iVar7 = snd_soc_of_parse_audio_routing(ppuVar25,"qcom,audio-routing"), iVar7 != 0)) {
        pcVar23 = "%s: parse audio routing failed, err:%d\n";
        goto LAB_001039e8;
      }
      puVar20 = ppuVar25[8];
      if (puVar20 == (undefined *)0x0) {
        iVar7 = ___ratelimit(msm_populate_dai_link_component_of_node__rs,
                             "msm_populate_dai_link_component_of_node");
        if (iVar7 != 0) {
          _dev_err(0,"%s: Sound card device memory NULL\n","msm_populate_dai_link_component_of_node"
                  );
        }
        iVar7 = -0x205;
      }
      else {
        if (0 < *(int *)(ppuVar25 + 0x2c)) {
          lVar10 = 0;
          puVar24 = ppuVar25[0x2b];
          do {
            if (*(long *)(puVar24 + lVar10 * 0xd0 + 0x58) == 0) {
              *(code **)(puVar24 + lVar10 * 0xd0 + 0x58) = msm_common_dai_link_init;
            }
            if (*(uint *)(puVar24 + lVar10 * 0xd0 + 0x28) != 0) {
              uVar22 = 0;
              plVar5 = (long *)(puVar24 + lVar10 * 0xd0 + 0x20);
              do {
                if (((*(long *)(*plVar5 + (long)(int)uVar22 * 0x18 + 8) == 0) &&
                    (*(long *)(*plVar5 + (long)(int)uVar22 * 0x18) != 0)) &&
                   (iVar7 = of_property_match_string
                                      (*(undefined8 *)(puVar20 + 0x2e8),"asoc-codec-names"),
                   -1 < iVar7)) {
                  local_78 = 0;
                  uStack_70 = 0;
                  local_88 = 0;
                  uStack_80 = 0;
                  local_98 = 0;
                  uStack_90 = 0;
                  local_a8 = 0;
                  uStack_a0 = 0;
                  local_b8 = 0;
                  uStack_b0 = 0;
                  iVar7 = __of_parse_phandle_with_args
                                    (*(undefined8 *)(puVar20 + 0x2e8),"asoc-codec",0,0,iVar7,
                                     &local_b8);
                  if ((iVar7 != 0) || (local_b8 == 0)) {
                    iVar7 = ___ratelimit(msm_populate_dai_link_component_of_node__rs_298,
                                         "msm_populate_dai_link_component_of_node");
                    if (iVar7 == 0) goto LAB_001033e8;
                    pcVar23 = "%s: retrieving phandle for codec %s failed\n";
                    uVar18 = *(undefined8 *)(*plVar5 + (long)(int)uVar22 * 0x18);
                    goto LAB_00103a5c;
                  }
                  *(size_t *)(*plVar5 + (long)(int)uVar22 * 0x18 + 8) = local_b8;
                  *(undefined8 *)(*plVar5 + (long)(int)uVar22 * 0x18) = 0;
                }
                uVar22 = uVar22 + 1;
              } while (uVar22 < *(uint *)(puVar24 + lVar10 * 0xd0 + 0x28));
            }
            lVar10 = lVar10 + 1;
          } while (lVar10 < *(int *)(ppuVar25 + 0x2c));
          if (0 < *(int *)(ppuVar25 + 0x2c)) {
            lVar10 = 0;
LAB_00103480:
            puVar19 = (uint *)(puVar24 + lVar10 * 0xd0 + 0x28);
            if (*puVar19 < 2) goto LAB_0010346c;
            uVar22 = 0;
            uVar14 = 0;
            plVar5 = (long *)(puVar24 + lVar10 * 0xd0 + 0x20);
            do {
              lVar11 = *(long *)(*plVar5 + (long)(int)uVar14 * 0x18 + 8);
              if (lVar11 != 0) {
                uVar12 = of_device_is_available(lVar11);
                if ((uVar12 & 1) == 0) {
                  iVar7 = ___ratelimit(msm_populate_dai_link_component_of_node__rs_300,
                                       "msm_populate_dai_link_component_of_node");
                  if (iVar7 != 0) {
                    _dev_err(puVar20,"%s: codec is disabled: %s\n",
                             "msm_populate_dai_link_component_of_node",
                             *(undefined8 *)(lVar11 + 0x10));
                  }
                  *(undefined8 *)(*plVar5 + (long)(int)uVar14 * 0x18 + 8) = 0;
                }
                else {
                  uVar22 = uVar22 + 1;
                }
              }
              uVar14 = uVar14 + 1;
            } while (uVar14 < *puVar19);
            if (((int)uVar22 < 1) || (*puVar19 <= uVar22)) goto LAB_0010346c;
            lVar11 = devm_kmalloc(puVar20,(ulong)uVar22 * 0x18,0xdc0);
            if (lVar11 != 0) {
              uVar14 = *puVar19;
              if (uVar14 != 0) {
                iVar7 = 0;
                uVar16 = 0;
                do {
                  lVar17 = *(long *)(*plVar5 + (long)(int)uVar16 * 0x18 + 8);
                  if (lVar17 != 0) {
                    puVar15 = (undefined8 *)(lVar11 + (long)iVar7 * 0x18);
                    iVar7 = iVar7 + 1;
                    puVar15[1] = lVar17;
                    uVar18 = *(undefined8 *)(*plVar5 + (long)(int)uVar16 * 0x18 + 0x10);
                    *puVar15 = 0;
                    puVar15[2] = uVar18;
                    uVar14 = *puVar19;
                  }
                  uVar16 = uVar16 + 1;
                } while (uVar16 < uVar14);
              }
              *plVar5 = lVar11;
              *puVar19 = uVar22;
              goto LAB_0010346c;
            }
            iVar7 = ___ratelimit(msm_populate_dai_link_component_of_node__rs_302,
                                 "msm_populate_dai_link_component_of_node");
            if (iVar7 != 0) {
              pcVar23 = "%s: %s dailink codec component alloc failed\n";
              uVar18 = *(undefined8 *)(puVar24 + lVar10 * 0xd0);
LAB_00103a5c:
              _dev_err(puVar20,pcVar23,"msm_populate_dai_link_component_of_node",uVar18);
            }
LAB_001033e8:
            iVar7 = -0x205;
            goto LAB_001039fc;
          }
        }
LAB_0010359c:
        local_b8 = 0;
        if (((param_1 != 0) &&
            (iVar7 = of_property_read_string(*plVar2,"qcom,upd_backends_used",puVar9 + 0x98),
            iVar7 == 0)) &&
           (iVar7 = of_property_read_variable_u32_array
                              (*plVar2,"qcom,upd_lpass_reg_addr",&local_b8,2,0), -1 < iVar7)) {
          lVar10 = *plVar2;
          *(int *)(puVar9 + 0x84) = (int)local_b8;
          *(uint *)(puVar9 + 0x88) = local_b8._4_4_;
          of_property_read_variable_u32_array(lVar10,"qcom,upd_ear_pa_reg_addr",puVar9 + 0x94,1,0);
        }
        iVar7 = devm_snd_soc_register_card(puVar1,ppuVar25);
        if (iVar7 != -0x205) {
          if (iVar7 == 0) {
            _dev_info(puVar1,"%s: Sound card %s registered\n","msm_asoc_machine_probe",*ppuVar25);
            if ((wcd_mbhc_cfg._88_4_ != 0) || (wcd_mbhc_cfg[0x5d] != '\0')) {
              wcd_mbhc_cfg._24_8_ = msm_usbc_swap_gnd_mic;
            }
            local_78 = 0;
            uStack_70 = 0;
            local_88 = 0;
            uStack_80 = 0;
            local_98 = 0;
            uStack_90 = 0;
            local_a8 = 0;
            uStack_a0 = 0;
            local_b8 = 0;
            uStack_b0 = 0;
            iVar7 = __of_parse_phandle_with_args(*plVar2,"fsa4480-i2c-handle",0,0,0,&local_b8);
            lVar10 = *plVar2;
            if (iVar7 != 0) {
              local_b8 = 0;
            }
            local_78 = 0;
            uStack_70 = 0;
            local_88 = 0;
            uStack_80 = 0;
            local_98 = 0;
            uStack_90 = 0;
            *(size_t *)(puVar9 + 0x50) = local_b8;
            local_a8 = 0;
            uStack_a0 = 0;
            local_b8 = 0;
            uStack_b0 = 0;
            iVar7 = __of_parse_phandle_with_args(lVar10,"wcd939x-i2c-handle",0,0,0,&local_b8);
            lVar10 = *plVar2;
            if (iVar7 != 0) {
              local_b8 = 0;
            }
            local_78 = 0;
            uStack_70 = 0;
            local_88 = 0;
            uStack_80 = 0;
            local_98 = 0;
            uStack_90 = 0;
            *(size_t *)(puVar9 + 0x58) = local_b8;
            local_a8 = 0;
            uStack_a0 = 0;
            local_b8 = 0;
            uStack_b0 = 0;
            iVar7 = __of_parse_phandle_with_args(lVar10,"qcom,cdc-dmic01-gpios",0,0,0,&local_b8);
            lVar10 = *plVar2;
            if (iVar7 != 0) {
              local_b8 = 0;
            }
            local_78 = 0;
            uStack_70 = 0;
            local_88 = 0;
            uStack_80 = 0;
            local_98 = 0;
            uStack_90 = 0;
            *(size_t *)(puVar9 + 0x18) = local_b8;
            local_a8 = 0;
            uStack_a0 = 0;
            local_b8 = 0;
            uStack_b0 = 0;
            iVar7 = __of_parse_phandle_with_args(lVar10,"qcom,cdc-dmic23-gpios",0,0,0,&local_b8);
            lVar10 = *plVar2;
            if (iVar7 != 0) {
              local_b8 = 0;
            }
            local_78 = 0;
            uStack_70 = 0;
            local_88 = 0;
            uStack_80 = 0;
            local_98 = 0;
            uStack_90 = 0;
            *(size_t *)(puVar9 + 0x20) = local_b8;
            local_a8 = 0;
            uStack_a0 = 0;
            local_b8 = 0;
            uStack_b0 = 0;
            iVar7 = __of_parse_phandle_with_args(lVar10,"qcom,cdc-dmic45-gpios",0,0,0,&local_b8);
            lVar10 = *plVar2;
            if (iVar7 != 0) {
              local_b8 = 0;
            }
            local_78 = 0;
            uStack_70 = 0;
            local_88 = 0;
            uStack_80 = 0;
            local_98 = 0;
            uStack_90 = 0;
            *(size_t *)(puVar9 + 0x28) = local_b8;
            local_a8 = 0;
            uStack_a0 = 0;
            local_b8 = 0;
            uStack_b0 = 0;
            iVar7 = __of_parse_phandle_with_args(lVar10,"qcom,cdc-dmic67-gpios",0,0,0,&local_b8);
            lVar10 = *plVar2;
            if (iVar7 != 0) {
              local_b8 = 0;
            }
            local_78 = 0;
            uStack_70 = 0;
            local_88 = 0;
            uStack_80 = 0;
            local_98 = 0;
            uStack_90 = 0;
            *(size_t *)(puVar9 + 0x30) = local_b8;
            local_a8 = 0;
            uStack_a0 = 0;
            local_b8 = 0;
            uStack_b0 = 0;
            iVar7 = __of_parse_phandle_with_args(lVar10,"qcom,dmic-micbias-en-gpio",0,0,0,&local_b8)
            ;
            sVar6 = local_b8;
            if (iVar7 != 0) {
              sVar6 = 0;
            }
            *(size_t *)(puVar9 + 0x38) = sVar6;
            if (*(long *)(puVar9 + 0x18) != 0) {
              msm_cdc_pinctrl_set_wakeup_capable(*(long *)(puVar9 + 0x18),0);
            }
            if (*(long *)(puVar9 + 0x20) != 0) {
              msm_cdc_pinctrl_set_wakeup_capable(*(long *)(puVar9 + 0x20),0);
            }
            if (*(long *)(puVar9 + 0x28) != 0) {
              msm_cdc_pinctrl_set_wakeup_capable(*(long *)(puVar9 + 0x28),0);
            }
            if (*(long *)(puVar9 + 0x30) != 0) {
              msm_cdc_pinctrl_set_wakeup_capable(*(long *)(puVar9 + 0x30),0);
            }
            if (*(long *)(puVar9 + 0x38) != 0) {
              _printk(&DAT_0010b3d3,"msm_asoc_machine_probe");
              msm_cdc_pinctrl_set_wakeup_capable(*(undefined8 *)(puVar9 + 0x38),0);
            }
            msm_common_snd_init(param_1,ppuVar25);
            uVar13 = devm_clk_get(puVar1,"lpass_audio_hw_vote");
            *(undefined4 *)(puVar9 + 0x68) = 0;
            uVar12 = 0;
            if (uVar13 < 0xfffffffffffff001) {
              uVar12 = uVar13;
            }
            *(ulong *)(puVar9 + 0x60) = uVar12;
            iVar7 = msm_audio_ssr_register(puVar1);
            if (iVar7 != 0) {
              _printk(&DAT_00109d62,"msm_asoc_machine_probe",iVar7);
            }
            snd_card_set_card_status(1);
            iVar7 = 0;
            goto LAB_00103a08;
          }
          pcVar23 = "%s: snd_soc_register_card failed (%d)\n";
          goto LAB_001039e8;
        }
        iVar7 = -0x16;
        if (codec_reg_done == '\0') {
          iVar7 = -0x205;
        }
      }
    }
    else {
      _dev_err(puVar1,"%s: parse card name failed, err:%d\n","msm_asoc_parse_soundcard_name",iVar7);
      pcVar23 = "%s: parse soundcard name failed, err:%d\n";
LAB_001039e8:
      _dev_err(puVar1,pcVar23,"msm_asoc_machine_probe",iVar7);
    }
  }
LAB_001039fc:
  devm_kfree(puVar1,puVar9);
LAB_00103a08:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
LAB_0010346c:
  lVar10 = lVar10 + 1;
  if (*(int *)(ppuVar25 + 0x2c) <= lVar10) goto LAB_0010359c;
  goto LAB_00103480;
}



//------------------------------------------------------------
// msm_asoc_machine_remove @ 00103b10 size=88
// signature: undefined msm_asoc_machine_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_asoc_machine_remove(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xa8);
  if ((lVar2 == 0) || (*(long *)(lVar2 + 0x318) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined8 *)(*(long *)(lVar2 + 0x318) + 8);
  }
  msm_common_snd_deinit(uVar1);
  snd_event_master_deregister(param_1 + 0x10);
  snd_soc_unregister_card(lVar2);
  return 0;
}



//------------------------------------------------------------
// msm_usbc_swap_gnd_mic @ 00103b6c size=128
// signature: undefined msm_usbc_swap_gnd_mic(void)
// callers: []
//------------------------------------------------------------

bool msm_usbc_swap_gnd_mic(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x20) + 0x318);
  lVar2 = *(long *)(lVar4 + 0x50);
  if (lVar2 == 0) {
    if (*(long *)(lVar4 + 0x58) == 0) {
      return false;
    }
    if (wcd_mbhc_cfg[0x5d] == '\0') {
      if (wcd_mbhc_cfg._88_4_ == 0) {
        iVar1 = 0;
        goto LAB_00103bd0;
      }
      uVar3 = 4;
    }
    else {
      uVar3 = 7;
    }
    iVar1 = wcd_usbss_switch_update(uVar3,1);
  }
  else {
    iVar1 = fsa4480_switch_event(lVar2,0);
  }
LAB_00103bd0:
  return iVar1 == 0;
}



//------------------------------------------------------------
// msm_audio_ssr_register @ 00103bec size=320
// signature: undefined msm_audio_ssr_register(void)
// callers: [msm_asoc_machine_probe]
//------------------------------------------------------------

int msm_audio_ssr_register(long param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 local_a0;
  long local_98 [11];
  
  lVar1 = sp_el0;
  local_98[10] = *(long *)(lVar1 + 0x638);
  uVar5 = *(undefined8 *)(param_1 + 0x2e8);
  local_a0 = 0;
  local_98[0] = 0;
  local_98[8] = 0;
  local_98[9] = 0;
  local_98[6] = 0;
  local_98[7] = 0;
  local_98[4] = 0;
  local_98[5] = 0;
  local_98[2] = 0;
  local_98[3] = 0;
  local_98[1] = 0;
  iVar2 = __of_parse_phandle_with_args(uVar5,"qcom,msm_audio_ssr_devs",0,0,0,local_98);
  uVar4 = 0;
  if ((iVar2 == 0) && (local_98[0] != 0)) {
    iVar2 = 1;
    do {
      snd_event_mstr_add_client(&local_a0,msm_audio_ssr_compare);
      local_98[8] = 0;
      local_98[9] = 0;
      local_98[6] = 0;
      local_98[7] = 0;
      local_98[4] = 0;
      local_98[5] = 0;
      local_98[2] = 0;
      local_98[3] = 0;
      local_98[0] = 0;
      local_98[1] = 0;
      iVar3 = __of_parse_phandle_with_args(uVar5,"qcom,msm_audio_ssr_devs",0,0,iVar2,local_98);
      if (iVar3 != 0) break;
      iVar2 = iVar2 + 1;
    } while (local_98[0] != 0);
    uVar4 = local_a0;
  }
  iVar2 = snd_event_master_register(param_1,&pineapple_ssr_ops,uVar4,0);
  if (iVar2 == 0) {
    snd_event_notify(param_1,1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_98[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// msm_snd_card_late_probe @ 00103d30 size=584
// signature: undefined msm_snd_card_late_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int msm_snd_card_late_probe(long param_1)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  undefined1 auStack_130 [208];
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  lVar8 = *(long *)(param_1 + 0x318);
  local_50 = 0;
  local_60 = 0;
  uStack_58 = 0;
  if (lVar8 == 0) {
LAB_00103e8c:
    iVar3 = -0x16;
  }
  else {
    if ((*(int *)(lVar8 + 0x70) != 0) || (*(int *)(lVar8 + 0xa8) != 0)) {
      iVar3 = 0;
      goto LAB_00103e90;
    }
    lVar4 = snd_soc_get_pcm_runtime(param_1,*(undefined8 *)(param_1 + 0x158));
    if (lVar4 == 0) {
      uVar7 = *(undefined8 *)(param_1 + 0x40);
      memcpy(auStack_130,*(void **)(param_1 + 0x158),0xd0);
      _dev_err(uVar7,"%s: snd_soc_get_pcm_runtime for %s failed!\n","msm_snd_card_late_probe",
               auStack_130);
      iVar3 = -0x16;
      goto LAB_00103e90;
    }
    pcVar1 = "wcd9378_codec";
    if (*(int *)(lVar8 + 0xa4) != 2) {
      pcVar1 = "wcd939x_codec";
    }
    pcVar2 = "wcd937x_codec";
    if (*(int *)(lVar8 + 0xa4) != 0) {
      pcVar2 = pcVar1;
    }
    strscpy(&local_60,pcVar2,0xe);
    lVar4 = snd_soc_rtdcom_lookup(lVar4,&local_60);
    if (lVar4 == 0) {
      _printk(&DAT_0010a3df,"msm_snd_card_late_probe");
      iVar3 = -0x16;
      goto LAB_00103e90;
    }
    lVar5 = kmalloc_trace(_kernel_kobj,0xdc0,0x9a);
    if (lVar5 == 0) {
      iVar3 = -0xc;
      goto LAB_00103e90;
    }
    *(undefined2 *)(lVar5 + 0x30) = 0x640;
    lVar6 = *(long *)(param_1 + 0x40);
    *(undefined1 *)(lVar5 + 0x41) = 8;
    *(undefined8 *)(lVar5 + 0x60) = 0x1f400ed0096004b;
    *(undefined8 *)(lVar5 + 0x68) = 0x1f401f401f401f4;
    wcd_mbhc_cfg._8_8_ = lVar5;
    lVar6 = of_find_property(*(undefined8 *)(lVar6 + 0x2e8),"qcom,usbss-hsj-connect-enabled",0);
    if (lVar6 != 0) {
      wcd_mbhc_cfg[0x5d] = 1;
    }
    iVar3 = *(int *)(lVar8 + 0xa4);
    if (iVar3 == 2) {
      iVar3 = wcd9378_mbhc_hs_detect(lVar4,wcd_mbhc_cfg);
    }
    else if (iVar3 == 1) {
      iVar3 = wcd939x_mbhc_hs_detect(lVar4,wcd_mbhc_cfg);
    }
    else {
      if (iVar3 != 0) goto LAB_00103e8c;
      iVar3 = wcd937x_mbhc_hs_detect(lVar4,wcd_mbhc_cfg);
    }
    if (iVar3 != 0) {
      _dev_err(*(undefined8 *)(lVar4 + 0x18),"%s: mbhc hs detect failed, err:%d\n",
               "msm_snd_card_late_probe",iVar3);
      kfree(lVar5);
    }
  }
LAB_00103e90:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// msm_int_wsa_init @ 00103f7c size=1540
// signature: undefined msm_int_wsa_init(void)
// callers: []
//------------------------------------------------------------

void msm_int_wsa_init(long param_1)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  undefined8 uVar4;
  undefined *puVar5;
  int *piVar6;
  int *piVar7;
  uint param3;
  undefined8 *puVar8;
  int local_c8 [3];
  undefined2 local_bc;
  int local_b8;
  undefined2 local_b4;
  int local_b0;
  undefined2 local_ac;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  puVar8 = (undefined8 *)(*(undefined8 **)(param_1 + 8))[99];
  pcVar2 = strstr((char *)**(undefined8 **)(param_1 + 8),"wsa883x");
  if (pcVar2 == (char *)0x0) {
    if (*(int *)(puVar8 + 0x15) == 0) {
      local_80 = CONCAT26(local_80._6_2_,0x50400000000);
      local_ac = 0x504;
      local_b4 = 0xd0a;
      local_80 = CONCAT44(local_80._4_4_,0x3020100);
      local_b0 = 0x3020100;
      local_b8 = 0x7030201;
      local_c8[2] = 0x7060504;
      local_bc = 0xd0b;
      local_a0 = 0xbb80000493e0;
      uStack_98 = 0x5dc000124f80;
      local_a8 = DAT_0010e384;
      local_68 = 0x100000003;
      uStack_60 = 0x300000003;
      local_70 = 0xf00000001;
      if (*(int *)((long)puVar8 + 0x6c) != 0) {
        lVar3 = snd_soc_rtdcom_lookup(param_1,"wsa-codec.1");
        if (lVar3 != 0) {
          piVar7 = (int *)&local_80;
          piVar6 = &local_b8;
LAB_00104344:
          wsa884x_set_channel_map(lVar3,piVar7,6,&local_70,&local_a8,piVar6);
          wsa884x_codec_info_create_codec_entry(*puVar8,lVar3);
          if (1 < *(uint *)((long)puVar8 + 0x6c)) {
            lVar3 = snd_soc_rtdcom_lookup(param_1,"wsa-codec.2");
            if (lVar3 == 0) goto LAB_00104550;
            wsa884x_set_channel_map(lVar3,&local_b0,6,&local_70,&local_a8,local_c8 + 2);
            wsa884x_codec_info_create_codec_entry(*puVar8,lVar3);
          }
          goto LAB_001043a4;
        }
        _printk(&DAT_00109afe,"msm_int_wsa884x_init");
        lVar3 = snd_soc_rtdcom_lookup(param_1,"wsa-codec.2");
        if (lVar3 != 0) {
          piVar7 = &local_b0;
          piVar6 = local_c8 + 2;
          goto LAB_00104344;
        }
LAB_00104550:
        puVar5 = &DAT_0010a4fb;
LAB_00104570:
        pcVar2 = "msm_int_wsa884x_init";
        goto LAB_00104544;
      }
LAB_001043a4:
      if ((*(char *)(puVar8 + 0x14) == '\0') && (2 < *(uint *)((long)puVar8 + 0x6c))) {
        lVar3 = snd_soc_rtdcom_lookup(param_1,"wsa-codec.3");
        if (lVar3 == 0) {
          puVar5 = &DAT_0010b7c8;
          goto LAB_00104570;
        }
        wsa884x_set_channel_map(lVar3,&local_80,6,&local_70,&local_a8,&local_b8);
        wsa884x_codec_info_create_codec_entry(*puVar8,lVar3);
        if (3 < *(uint *)((long)puVar8 + 0x6c)) {
          lVar3 = snd_soc_rtdcom_lookup(param_1,"wsa-codec.4");
          if (lVar3 == 0) {
            puVar5 = &DAT_00109ea1;
            goto LAB_00104570;
          }
          wsa884x_set_channel_map(lVar3,&local_b0,6,&local_70,&local_a8,local_c8 + 2);
          wsa884x_codec_info_create_codec_entry(*puVar8,lVar3);
        }
      }
    }
    else {
      local_b0 = 0x3020100;
      local_b8 = 0x3020100;
      local_c8[1] = 0xb060504;
      local_c8[2] = 0xa030201;
      local_90 = 0;
      uStack_88 = 0;
      local_a0 = 0;
      uStack_98 = 0;
      local_80 = 0xf00000001;
      uStack_78 = 0x300000003;
      local_70 = DAT_00114848;
      local_68 = DAT_00114850;
      local_a8 = 0;
      local_c8[0] = 0;
      if (*(int *)((long)puVar8 + 0x6c) - 1U < 0xfffffffe) {
        param3 = 1;
        do {
          local_c8[0] = 0;
          snprintf((char *)&local_a8,0x28,"wsa-codec.%d",param3);
          lVar3 = snd_soc_rtdcom_lookup(param_1,&local_a8);
          if (lVar3 == 0) {
            _printk(&DAT_0010b3eb,"msm_int_wsa883x_hac_init",param3);
            uVar4 = 0xffffffea;
            goto LAB_00104448;
          }
          iVar1 = of_property_read_variable_u32_array
                            (*(undefined8 *)(*(long *)(lVar3 + 0x18) + 0x2e8),
                             "qcom,connect-to-left-port",local_c8,1,0);
          if (iVar1 < 0) {
            _printk(&DAT_0010b68f,"msm_int_wsa883x_hac_init",param3);
            local_c8[0] = 0;
LAB_001041e4:
            piVar6 = &local_b8;
            piVar7 = local_c8 + 1;
          }
          else {
            if (local_c8[0] == 0) goto LAB_001041e4;
            piVar6 = &local_b0;
            piVar7 = local_c8 + 2;
          }
          wsa883x_set_channel_map(lVar3,piVar6,4,&local_80,&local_70,piVar7);
          wsa883x_codec_info_create_codec_entry(*puVar8,lVar3);
          param3 = param3 + 1;
        } while (param3 < *(int *)((long)puVar8 + 0x6c) + 1U);
      }
    }
  }
  else {
    local_80 = CONCAT44(local_80._4_4_,0x3020100);
    local_b0 = 0x3020100;
    local_b8 = 0xa030201;
    local_c8[2] = 0xb060504;
    local_a8 = DAT_00114848;
    local_a0 = DAT_00114850;
    local_70 = 0xf00000001;
    local_68 = 0x300000003;
    if (*(int *)((long)puVar8 + 0x6c) != 0) {
      lVar3 = snd_soc_rtdcom_lookup(param_1,"wsa-codec.1");
      if (lVar3 != 0) {
        piVar7 = (int *)&local_80;
        piVar6 = &local_b8;
LAB_00104040:
        wsa883x_set_channel_map(lVar3,piVar7,4,&local_70,&local_a8,piVar6);
        wsa883x_codec_info_create_codec_entry(*puVar8,lVar3);
        if (1 < *(uint *)((long)puVar8 + 0x6c)) {
          lVar3 = snd_soc_rtdcom_lookup(param_1,"wsa-codec.2");
          if (lVar3 == 0) goto LAB_001044bc;
          wsa883x_set_channel_map(lVar3,&local_b0,4,&local_70,&local_a8,local_c8 + 2);
          wsa883x_codec_info_create_codec_entry(*puVar8,lVar3);
        }
        goto LAB_001040a0;
      }
      _printk(&DAT_00109afe,"msm_int_wsa883x_init");
      lVar3 = snd_soc_rtdcom_lookup(param_1,"wsa-codec.2");
      if (lVar3 != 0) {
        piVar7 = &local_b0;
        piVar6 = local_c8 + 2;
        goto LAB_00104040;
      }
LAB_001044bc:
      puVar5 = &DAT_0010a4fb;
LAB_0010453c:
      pcVar2 = "msm_int_wsa883x_init";
LAB_00104544:
      _printk(puVar5,pcVar2);
      uVar4 = 0xffffffea;
      goto LAB_00104448;
    }
LAB_001040a0:
    if ((*(char *)(puVar8 + 0x14) == '\0') && (2 < *(uint *)((long)puVar8 + 0x6c))) {
      lVar3 = snd_soc_rtdcom_lookup(param_1,"wsa-codec.3");
      if (lVar3 == 0) {
        puVar5 = &DAT_0010b7c8;
        goto LAB_0010453c;
      }
      wsa883x_set_channel_map(lVar3,&local_80,4,&local_70,&local_a8,&local_b8);
      wsa883x_codec_info_create_codec_entry(*puVar8,lVar3);
      if (3 < *(uint *)((long)puVar8 + 0x6c)) {
        lVar3 = snd_soc_rtdcom_lookup(param_1,"wsa-codec.4");
        if (lVar3 == 0) {
          puVar5 = &DAT_00109ea1;
          goto LAB_0010453c;
        }
        wsa883x_set_channel_map(lVar3,&local_b0,4,&local_70,&local_a8,local_c8 + 2);
        wsa883x_codec_info_create_codec_entry(*puVar8,lVar3);
      }
    }
  }
  msm_common_dai_link_init(param_1);
  uVar4 = 0;
LAB_00104448:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// msm_tx_codec_init @ 00104584 size=396
// signature: undefined msm_tx_codec_init(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_tx_codec_init(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  long *plVar5;
  
  plVar5 = *(long **)(*(long *)(param_1 + 8) + 0x318);
  lVar2 = snd_soc_rtdcom_lookup(param_1,"lpass-cdc");
  if (lVar2 == 0) {
    _printk(&DAT_0010a59b,"msm_tx_codec_init");
    return 0xffffffea;
  }
  lVar4 = lVar2 + 0xd0;
  snd_soc_dapm_new_controls(lVar4,msm_int_dapm_widgets,0xd);
  snd_soc_dapm_ignore_suspend(lVar4,"Digital Mic0");
  snd_soc_dapm_ignore_suspend(lVar4,"Digital Mic1");
  snd_soc_dapm_ignore_suspend(lVar4,"Digital Mic2");
  snd_soc_dapm_ignore_suspend(lVar4,"Digital Mic3");
  snd_soc_dapm_ignore_suspend(lVar4,"Digital Mic4");
  snd_soc_dapm_ignore_suspend(lVar4,"Digital Mic5");
  snd_soc_dapm_ignore_suspend(lVar4,"Digital Mic6");
  snd_soc_dapm_ignore_suspend(lVar4,"Digital Mic7");
  lVar4 = *plVar5;
  if (lVar4 == 0) {
    lVar4 = *(long *)(*(long *)(param_1 + 8) + 0x48);
    lVar4 = snd_info_create_module_entry
                      (*(undefined8 *)(lVar4 + 0x188),"codecs",*(undefined8 *)(lVar4 + 0x5e8));
    if (lVar4 == 0) {
      return 0xffffffea;
    }
    *(undefined2 *)(lVar4 + 8) = 0x416d;
    iVar1 = snd_info_register();
    if (iVar1 < 0) {
      snd_info_free_entry(lVar4);
      return 0xffffffea;
    }
    *plVar5 = lVar4;
  }
  lpass_cdc_info_create_codec_entry(lVar4,lVar2);
  lpass_cdc_set_port_map(lVar2,2,sm_port_map_hac_wsa);
  codec_reg_done = 1;
  uVar3 = msm_common_dai_link_init(param_1);
  return uVar3;
}



//------------------------------------------------------------
// msm_dmic_event @ 00104714 size=848
// signature: undefined msm_dmic_event(void)
// callers: []
//------------------------------------------------------------

int msm_dmic_event(long param_1,undefined8 param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined *puVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  long lVar8;
  int *piVar9;
  long lVar10;
  uint local_4c;
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  lVar8 = *(long *)(param_1 + 0x28);
  local_4c = 0;
  pcVar4 = strpbrk(*(char **)(param_1 + 8),"01234567");
  if (pcVar4 == (char *)0x0) {
    iVar2 = ___ratelimit(msm_dmic_event__rs,"msm_dmic_event");
    if (iVar2 != 0) {
      uVar6 = *(undefined8 *)(lVar8 + -0xb8);
      pcVar4 = "%s: widget not found\n";
LAB_001047f4:
      _dev_err(uVar6,pcVar4,"msm_dmic_event");
    }
  }
  else {
    iVar2 = kstrtouint(pcVar4,10,&local_4c);
    if (iVar2 < 0) {
      iVar2 = ___ratelimit(msm_dmic_event__rs_132,"msm_dmic_event");
      if (iVar2 != 0) {
        uVar6 = *(undefined8 *)(lVar8 + -0xb8);
        pcVar4 = "%s: Invalid DMIC line on the codec\n";
        goto LAB_001047f4;
      }
    }
    else {
      if (local_4c < 8) {
        lVar10 = *(long *)(*(long *)(lVar8 + -0xb0) + 0x318);
        switch(local_4c) {
        default:
          puVar7 = (undefined8 *)(lVar10 + 0x18);
          piVar9 = &dmic_0_1_gpio_cnt;
          break;
        case 2:
        case 3:
          puVar7 = (undefined8 *)(lVar10 + 0x20);
          piVar9 = &dmic_2_3_gpio_cnt;
          break;
        case 4:
        case 5:
          puVar7 = (undefined8 *)(lVar10 + 0x28);
          piVar9 = &dmic_4_5_gpio_cnt;
          break;
        case 6:
        case 7:
          puVar7 = (undefined8 *)(lVar10 + 0x30);
          piVar9 = &dmic_6_7_gpio_cnt;
        }
        uVar6 = *puVar7;
        if (param_3 == 8) {
          if ((*(long *)(lVar10 + 0x38) != 0) &&
             (dmic_micbias_cnt = dmic_micbias_cnt + -1, dmic_micbias_cnt == 0)) {
            _dev_info(*(undefined8 *)(lVar8 + -0xb8),"%s: disable micbias\n","msm_dmic_event");
            iVar2 = msm_cdc_pinctrl_select_sleep_state(*(undefined8 *)(lVar10 + 0x38));
            if (iVar2 < 0) {
              iVar3 = ___ratelimit(msm_dmic_event__rs_144,"msm_dmic_event");
              if (iVar3 == 0) goto LAB_00104934;
              puVar5 = &DAT_0010b6b6;
LAB_00104a38:
              _printk(puVar5,"msm_dmic_event","pdata->dmic_micbias_gpio_p");
              goto LAB_00104934;
            }
          }
          iVar2 = *piVar9;
          *piVar9 = iVar2 + -1;
          if ((iVar2 + -1 != 0) || (iVar2 = msm_cdc_pinctrl_select_sleep_state(uVar6), -1 < iVar2))
          {
LAB_001048dc:
            iVar2 = 0;
            goto LAB_00104934;
          }
          iVar3 = ___ratelimit(msm_dmic_event__rs_146,"msm_dmic_event");
          if (iVar3 == 0) goto LAB_00104934;
          puVar5 = &DAT_0010a0c2;
        }
        else {
          if (param_3 != 1) {
            iVar2 = ___ratelimit(msm_dmic_event__rs_148,"msm_dmic_event");
            if (iVar2 != 0) {
              _printk(&DAT_0010b556,"msm_dmic_event",param_3);
            }
            goto LAB_00104930;
          }
          if ((*(long *)(lVar10 + 0x38) != 0) &&
             (iVar2 = dmic_micbias_cnt + 1, bVar1 = dmic_micbias_cnt == 0, dmic_micbias_cnt = iVar2,
             bVar1)) {
            _dev_info(*(undefined8 *)(lVar8 + -0xb8),"%s: enable micbias\n","msm_dmic_event");
            iVar2 = msm_cdc_pinctrl_select_active_state(*(undefined8 *)(lVar10 + 0x38));
            if (iVar2 < 0) {
              iVar3 = ___ratelimit(msm_dmic_event__rs_137,"msm_dmic_event");
              if (iVar3 == 0) goto LAB_00104934;
              puVar5 = &DAT_0010b35b;
              goto LAB_00104a38;
            }
          }
          iVar2 = *piVar9;
          *piVar9 = iVar2 + 1;
          if ((iVar2 != 0) || (iVar2 = msm_cdc_pinctrl_select_active_state(uVar6), -1 < iVar2))
          goto LAB_001048dc;
          iVar3 = ___ratelimit(msm_dmic_event__rs_140,"msm_dmic_event");
          if (iVar3 == 0) goto LAB_00104934;
          puVar5 = &DAT_0010b181;
        }
        _printk(puVar5,"msm_dmic_event","dmic_gpio");
        goto LAB_00104934;
      }
      iVar2 = ___ratelimit(msm_dmic_event__rs_134,"msm_dmic_event");
      if (iVar2 != 0) {
        uVar6 = *(undefined8 *)(lVar8 + -0xb8);
        pcVar4 = "%s: Invalid DMIC Selection\n";
        goto LAB_001047f4;
      }
    }
  }
LAB_00104930:
  iVar2 = -0x16;
LAB_00104934:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// msm_rx_tx_codec_init @ 00104a68 size=1024
// signature: undefined msm_rx_tx_codec_init(void)
// callers: []
//------------------------------------------------------------

int msm_rx_tx_codec_init(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined4 uVar5;
  long lVar6;
  long *plVar7;
  long lVar8;
  
  plVar7 = *(long **)(*(long *)(param_1 + 8) + 0x318);
  lVar3 = snd_soc_rtdcom_lookup(param_1,"lpass-cdc");
  if (lVar3 == 0) {
    _printk(&DAT_0010a59b,"msm_rx_tx_codec_init");
    return 0;
  }
  lVar6 = lVar3 + 0xd0;
  snd_soc_dapm_new_controls(lVar6,msm_int_dapm_widgets,0xd);
  snd_soc_dapm_ignore_suspend(lVar6,"Digital Mic0");
  snd_soc_dapm_ignore_suspend(lVar6,"Digital Mic1");
  snd_soc_dapm_ignore_suspend(lVar6,"Digital Mic2");
  snd_soc_dapm_ignore_suspend(lVar6,"Digital Mic3");
  snd_soc_dapm_ignore_suspend(lVar6,"Digital Mic4");
  snd_soc_dapm_ignore_suspend(lVar6,"Digital Mic5");
  snd_soc_dapm_ignore_suspend(lVar6,"Digital Mic6");
  snd_soc_dapm_ignore_suspend(lVar6,"Digital Mic7");
  snd_soc_dapm_ignore_suspend(lVar6,"Analog Mic1");
  snd_soc_dapm_ignore_suspend(lVar6,"Analog Mic2");
  snd_soc_dapm_ignore_suspend(lVar6,"Analog Mic3");
  snd_soc_dapm_ignore_suspend(lVar6,"Analog Mic4");
  snd_soc_dapm_ignore_suspend(lVar6,"Analog Mic5");
  lpass_cdc_set_port_map(lVar3,7,sm_port_map);
  lVar6 = *plVar7;
  if (lVar6 == 0) {
    lVar6 = *(long *)(*(long *)(param_1 + 8) + 0x48);
    lVar6 = snd_info_create_module_entry
                      (*(undefined8 *)(lVar6 + 0x188),"codecs",*(undefined8 *)(lVar6 + 0x5e8));
    if (lVar6 == 0) {
      return 0;
    }
    *(undefined2 *)(lVar6 + 8) = 0x416d;
    iVar1 = snd_info_register();
    if (iVar1 < 0) goto LAB_00104e40;
    *plVar7 = lVar6;
  }
  lpass_cdc_info_create_codec_entry(lVar6,lVar3);
  lpass_cdc_register_wake_irq(lVar3,0);
  iVar1 = 0;
  if ((int)plVar7[0xe] == 0) {
    lVar4 = snd_soc_rtdcom_lookup(param_1,"wcd939x_codec");
    if (lVar4 == 0) {
      lVar4 = snd_soc_rtdcom_lookup(param_1,"wcd937x_codec");
      if (lVar4 == 0) {
        lVar4 = snd_soc_rtdcom_lookup(param_1,"wcd9378_codec");
        if (lVar4 == 0) {
          _printk(&DAT_0010a3df,"msm_rx_tx_codec_init");
          return -0x16;
        }
        uVar5 = 2;
      }
      else {
        uVar5 = 0;
      }
    }
    else {
      uVar5 = 1;
    }
    *(undefined4 *)((long)plVar7 + 0xa4) = uVar5;
    lVar6 = lVar4 + 0xd0;
    lVar8 = *(long *)(*(long *)(lVar4 + 0x20) + 0x48);
    snd_soc_dapm_ignore_suspend(lVar6,&DAT_00109fe5);
    if (*(int *)((long)plVar7 + 0xa4) != 1) {
      snd_soc_dapm_ignore_suspend(lVar6,&DAT_0010adf1);
    }
    snd_soc_dapm_ignore_suspend(lVar6,&DAT_0010a309);
    snd_soc_dapm_ignore_suspend(lVar6,&DAT_00109b7f);
    snd_soc_dapm_ignore_suspend(lVar6,"AMIC1");
    snd_soc_dapm_ignore_suspend(lVar6,"AMIC2");
    snd_soc_dapm_ignore_suspend(lVar6,"AMIC3");
    snd_soc_dapm_ignore_suspend(lVar6,"AMIC4");
    snd_soc_dapm_sync(lVar6);
    plVar7 = *(long **)(*(long *)(lVar4 + 0x20) + 0x318);
    lVar6 = *plVar7;
    if (lVar6 == 0) {
      lVar6 = snd_info_create_module_entry
                        (*(undefined8 *)(lVar8 + 0x188),"codecs",*(undefined8 *)(lVar8 + 0x5e8));
      if (lVar6 == 0) {
        return 0;
      }
      *(undefined2 *)(lVar6 + 8) = 0x416d;
      iVar1 = snd_info_register(lVar6);
      if (iVar1 < 0) {
LAB_00104e40:
        snd_info_free_entry(lVar6);
        return 0;
      }
      *plVar7 = lVar6;
    }
    if (*(int *)((long)plVar7 + 0xa4) == 2) {
      wcd9378_info_create_codec_entry(lVar6,lVar4);
    }
    else {
      if (*(int *)((long)plVar7 + 0xa4) != 0) {
        wcd939x_info_create_codec_entry(lVar6,lVar4);
        iVar1 = wcd939x_get_codec_variant(lVar4);
        iVar1 = lpass_cdc_rx_set_fir_capability(lVar3,iVar1 == 5);
        if (iVar1 < 0) {
          iVar2 = ___ratelimit(msm_rx_tx_codec_init__rs,"msm_rx_tx_codec_init");
          if (iVar2 == 0) {
            return iVar1;
          }
          _dev_err(*(undefined8 *)(lVar4 + 0x18),"%s: set fir capability failed: %d\n",
                   "msm_rx_tx_codec_init",iVar1);
          return iVar1;
        }
        goto LAB_00104dd4;
      }
      wcd937x_info_create_codec_entry();
      wcd937x_get_codec_variant(lVar4);
    }
    iVar1 = 0;
  }
LAB_00104dd4:
  codec_reg_done = 1;
  msm_common_dai_link_init(param_1);
  return iVar1;
}



//------------------------------------------------------------
// msm_int_wsa881x_init @ 00104e6c size=88
// signature: undefined msm_int_wsa881x_init(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_int_wsa881x_init(long param_1)

{
  if (*(int *)(*(long *)(*(long *)(param_1 + 8) + 0x318) + 0x6c) == 0) {
    _printk(&DAT_0010a8ba,"msm_int_wsa881x_init");
  }
  msm_common_dai_link_init(param_1);
  return 0;
}



//------------------------------------------------------------
// msm_int_wsa2_init @ 00104ec8 size=724
// signature: undefined msm_int_wsa2_init(void)
// callers: []
//------------------------------------------------------------

void msm_int_wsa2_init(long param_1)

{
  char *pcVar1;
  long lVar2;
  undefined8 uVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  undefined4 local_88;
  undefined2 local_84;
  undefined4 local_80;
  undefined2 local_7c;
  undefined4 local_78;
  undefined2 local_74;
  undefined4 local_70;
  undefined2 local_6c;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  puVar5 = *(undefined8 **)(param_1 + 8);
  pcVar1 = strstr((char *)*puVar5,"wsa883x");
  if (pcVar1 == (char *)0x0) {
    local_6c = 0x504;
    puVar5 = (undefined8 *)puVar5[99];
    local_74 = 0x504;
    local_7c = 0xd0a;
    local_70 = 0x3020100;
    local_78 = 0x3020100;
    local_80 = 0x7030201;
    local_88 = 0x7060504;
    local_84 = 0xd0b;
    local_48 = 0xbb80000493e0;
    uStack_40 = 0x5dc000124f80;
    local_50 = DAT_0010e384;
    local_60 = 0x100000003;
    uStack_58 = 0x300000003;
    local_68 = 0xf00000001;
    if (*(char *)(puVar5 + 0x14) != '\0') {
      if (2 < *(uint *)((long)puVar5 + 0x6c)) {
        lVar2 = snd_soc_rtdcom_lookup(param_1,"wsa-codec.3");
        if (lVar2 == 0) {
          puVar4 = &DAT_0010b7c8;
LAB_00105184:
          pcVar1 = "msm_int_wsa884x_2_init";
          goto LAB_0010518c;
        }
        wsa884x_set_channel_map(lVar2,&local_70,6,&local_68,&local_50,&local_80);
        wsa884x_codec_info_create_codec_entry(*puVar5,lVar2);
        if (3 < *(uint *)((long)puVar5 + 0x6c)) {
          lVar2 = snd_soc_rtdcom_lookup(param_1,"wsa-codec.4");
          if (lVar2 == 0) {
            puVar4 = &DAT_00109ea1;
            goto LAB_00105184;
          }
          wsa884x_set_channel_map(lVar2,&local_78,6,&local_68,&local_50,&local_88);
          wsa884x_codec_info_create_codec_entry(*puVar5,lVar2);
        }
      }
      goto LAB_00105118;
    }
  }
  else {
    puVar5 = (undefined8 *)puVar5[99];
    local_70 = 0x3020100;
    local_78 = 0x3020100;
    local_80 = 0xa030201;
    local_88 = 0xb060504;
    local_50 = DAT_00114848;
    local_48 = DAT_00114850;
    local_68 = 0xf00000001;
    local_60 = 0x300000003;
    if (*(char *)(puVar5 + 0x14) != '\0') {
      if (2 < *(uint *)((long)puVar5 + 0x6c)) {
        lVar2 = snd_soc_rtdcom_lookup(param_1,"wsa-codec.3");
        if (lVar2 == 0) {
          puVar4 = &DAT_0010b7c8;
LAB_00105170:
          pcVar1 = "msm_int_wsa883x_2_init";
LAB_0010518c:
          _printk(puVar4,pcVar1);
          uVar3 = 0xffffffea;
          goto LAB_00105124;
        }
        wsa883x_set_channel_map(lVar2,&local_70,4,&local_68,&local_50,&local_80);
        wsa883x_codec_info_create_codec_entry(*puVar5,lVar2);
        if (3 < *(uint *)((long)puVar5 + 0x6c)) {
          lVar2 = snd_soc_rtdcom_lookup(param_1,"wsa-codec.4");
          if (lVar2 == 0) {
            puVar4 = &DAT_00109ea1;
            goto LAB_00105170;
          }
          wsa883x_set_channel_map(lVar2,&local_78,4,&local_68,&local_50,&local_88);
          wsa883x_codec_info_create_codec_entry(*puVar5,lVar2);
        }
      }
LAB_00105118:
      msm_common_dai_link_init(param_1);
    }
  }
  uVar3 = 0;
LAB_00105124:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// msm_wcn_init @ 001051a0 size=156
// signature: undefined msm_wcn_init(void)
// callers: []
//------------------------------------------------------------

int msm_wcn_init(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0xa00000009f;
  uStack_30 = 0x9e0000009d;
  iVar2 = snd_soc_dai_set_channel_map
                    (*(undefined8 *)
                      (*(long *)(param_1 + 0x620) +
                      (ulong)*(uint *)(*(long *)(param_1 + 0x10) + 0x18) * 8),2,&local_38,2,
                     &uStack_30);
  if (iVar2 == 0) {
    msm_common_dai_link_init(param_1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// msm_wcn_init_btfm @ 00105240 size=168
// signature: undefined msm_wcn_init_btfm(void)
// callers: []
//------------------------------------------------------------

int msm_wcn_init_btfm(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0xa1;
  local_40 = 0xa00000009f;
  local_30 = 0x9e0000009d;
  iVar2 = snd_soc_dai_set_channel_map
                    (*(undefined8 *)
                      (*(long *)(param_1 + 0x620) +
                      (ulong)*(uint *)(*(long *)(param_1 + 0x10) + 0x18) * 8),3,&local_40,2,
                     &local_30);
  if (iVar2 == 0) {
    msm_common_dai_link_init(param_1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// msm_audrx_stub_init @ 001052ec size=8
// signature: undefined msm_audrx_stub_init(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_audrx_stub_init(void)

{
  return 0;
}



//------------------------------------------------------------
// msm_snd_stub_hw_params @ 001052f8 size=8
// signature: undefined msm_snd_stub_hw_params(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_snd_stub_hw_params(void)

{
  return 0;
}



//------------------------------------------------------------
// msm_audio_ssr_compare @ 00105304 size=20
// signature: undefined msm_audio_ssr_compare(void)
// callers: []
//------------------------------------------------------------

bool msm_audio_ssr_compare(long param_1,long param_2)

{
  return *(long *)(param_1 + 0x2e8) != 0 && *(long *)(param_1 + 0x2e8) == param_2;
}



//------------------------------------------------------------
// pineapple_ssr_enable @ 0010531c size=1072
// signature: undefined pineapple_ssr_enable(void)
// callers: []
//------------------------------------------------------------

void pineapple_ssr_enable(long param_1)

{
  char *pcVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  undefined *puVar7;
  undefined8 uVar8;
  uint uVar9;
  code *pcVar10;
  long lVar11;
  char *pcVar12;
  long lVar13;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  long local_48;
  
  lVar11 = sp_el0;
  local_48 = *(long *)(lVar11 + 0x638);
  lVar11 = *(long *)(param_1 + 0x98);
  if (lVar11 == 0) {
    iVar3 = ___ratelimit(pineapple_ssr_enable__rs,"pineapple_ssr_enable");
    if (iVar3 == 0) {
      uVar8 = 0xffffffea;
    }
    else {
      _dev_err(param_1,"%s: card is NULL\n","pineapple_ssr_enable");
      uVar8 = 0xffffffea;
    }
    goto LAB_001056f8;
  }
  snd_card_notify_user(1);
  lVar13 = *(long *)(lVar11 + 0x318);
  if (lVar13 != 0) {
    lVar5 = snd_soc_get_pcm_runtime(lVar11,*(undefined8 *)(lVar11 + 0x158));
    if (*(int *)(lVar13 + 0x6c) == 0) {
      lVar6 = 0;
      pcVar12 = *(char **)(lVar13 + 0x98);
    }
    else {
      lVar6 = 0x750;
      if (*(int *)(lVar13 + 0xa8) != 0) {
        lVar6 = 0x1a0;
      }
      lVar6 = snd_soc_get_pcm_runtime(lVar11,*(long *)(lVar11 + 0x158) + lVar6);
      pcVar12 = *(char **)(lVar13 + 0x98);
    }
    if (pcVar12 != (char *)0x0) {
      iVar3 = strcmp(pcVar12,"wsa");
      if (iVar3 == 0) {
        if (lVar6 != 0) {
LAB_00105444:
          local_50 = 0;
          local_60 = 0;
          uStack_58 = 0;
          lVar11 = *(long *)(*(long *)(lVar6 + 8) + 0x318);
          if (lVar11 == 0) {
            iVar3 = ___ratelimit(msm_set_upd_config__rs_314,"msm_set_upd_config");
            if (iVar3 != 0) {
              puVar7 = &DAT_0010ae89;
              goto LAB_001056e8;
            }
          }
          else if (((*(int *)(lVar11 + 0x84) == 0) || (*(int *)(lVar11 + 0x88) == 0)) ||
                  (*(int *)(lVar11 + 0x94) == 0)) {
            iVar3 = ___ratelimit(msm_set_upd_config__rs_316,"msm_set_upd_config");
            if (iVar3 != 0) {
              puVar7 = &DAT_0010ab29;
              goto LAB_001056e8;
            }
          }
          else {
            iVar3 = strcmp(*(char **)(lVar11 + 0x98),"wsa");
            if (iVar3 == 0) {
              if (*(int *)(lVar11 + 0x6c) != 0) {
                lVar13 = snd_soc_rtdcom_lookup(lVar6,"wsa-codec.1");
                if (lVar13 == 0) {
                  _printk(&DAT_0010ad2e,"msm_set_upd_config","wsa-codec.1");
                  goto LAB_001056f4;
                }
                goto LAB_00105594;
              }
              puVar7 = &DAT_0010a786;
            }
            else {
              pcVar12 = "wcd9378_codec";
              if (*(int *)(lVar11 + 0xa4) != 2) {
                pcVar12 = "wcd939x_codec";
              }
              pcVar1 = "wcd937x_codec";
              if (*(int *)(lVar11 + 0xa4) != 0) {
                pcVar1 = pcVar12;
              }
              strscpy(&local_60,pcVar1,0xe);
              lVar13 = snd_soc_rtdcom_lookup(lVar6,&local_60);
              if (lVar13 != 0) {
LAB_00105594:
                iVar3 = strcmp(*(char **)(lVar11 + 0x98),"wsa");
                if (iVar3 == 0) {
                  pcVar12 = strstr((char *)**(undefined8 **)(lVar6 + 8),"wsa883x");
                  if (pcVar12 == (char *)0x0) {
                    pcVar10 = (code *)&wsa884x_codec_get_dev_num;
                  }
                  else {
                    pcVar10 = (code *)&wsa883x_codec_get_dev_num;
                  }
                }
                else if (*(int *)(lVar11 + 0xa4) == 2) {
                  pcVar10 = (code *)&wcd9378_codec_get_dev_num;
                }
                else if (*(int *)(lVar11 + 0xa4) == 0) {
                  pcVar10 = wcd937x_codec_get_dev_num;
                }
                else {
                  pcVar10 = (code *)&wcd939x_codec_get_dev_num;
                }
                *(code **)(lVar11 + 0x78) = pcVar10;
                if (*(int *)(pcVar10 + -4) != -0x2fe24ac8) {
                    /* WARNING: Does not return */
                  pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x105628);
                  (*pcVar10)();
                }
                uVar4 = (*pcVar10)(lVar13);
                uVar4 = uVar4 & 0xff;
                if (uVar4 < 7) {
                  uVar2 = *(ushort *)(lVar11 + 0x94);
                  *(uint *)(lVar11 + 0x8c) = (uint)uVar2;
                  *(uint *)(lVar11 + 0x90) = (uint)uVar2;
                  iVar3 = strcmp(*(char **)(lVar11 + 0x98),"wsa");
                  uVar9 = 0x1010000;
                  if (iVar3 != 0) {
                    uVar9 = 0x80010000;
                  }
                  *(uint *)(lVar11 + 0x8c) = uVar4 << 0x14 | (uint)uVar2 | uVar9;
                  *(uint *)(lVar11 + 0x90) = (uint)uVar2 | uVar4 << 0x14 | 0x10000;
                  iVar3 = audio_prm_set_cdc_earpa_duty_cycling_req((int *)(lVar11 + 0x84),1);
                  if ((iVar3 < 0) &&
                     (iVar3 = ___ratelimit(msm_set_upd_config__rs_323,"msm_set_upd_config"),
                     iVar3 != 0)) {
                    puVar7 = &DAT_0010ac30;
                    goto LAB_001056e8;
                  }
                }
                else {
                  iVar3 = ___ratelimit(msm_set_upd_config__rs_321,"msm_set_upd_config");
                  if (iVar3 != 0) {
                    _printk(&DAT_0010a270,"msm_set_upd_config",uVar4);
                  }
                }
                goto LAB_001056f4;
              }
              puVar7 = &DAT_0010a3df;
            }
LAB_001056e8:
            _printk(puVar7,"msm_set_upd_config");
          }
        }
      }
      else {
        iVar3 = strcmp(pcVar12,"wcd");
        if (iVar3 == 0) {
          lVar6 = lVar5;
          if (lVar5 != 0) goto LAB_00105444;
          if ((*(int *)(lVar13 + 0x70) != 0) &&
             (iVar3 = ___ratelimit(msm_set_upd_config__rs,"msm_set_upd_config"), iVar3 != 0)) {
            puVar7 = &DAT_0010b755;
            goto LAB_001056e8;
          }
        }
        else {
          uVar8 = ___ratelimit(pineapple_ssr_enable__rs_311,"pineapple_ssr_enable");
          if ((int)uVar8 == 0) goto LAB_001056f8;
          _dev_err(*(undefined8 *)(lVar11 + 0x40),"%s: Invalid backend to set UPD config\n",
                   "pineapple_ssr_enable");
        }
      }
    }
  }
LAB_001056f4:
  uVar8 = 0;
LAB_001056f8:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}



//------------------------------------------------------------
// pineapple_ssr_disable @ 00105750 size=108
// signature: undefined pineapple_ssr_disable(void)
// callers: []
//------------------------------------------------------------

void pineapple_ssr_disable(long param_1)

{
  int iVar1;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    iVar1 = ___ratelimit(pineapple_ssr_disable__rs,"pineapple_ssr_disable");
    if (iVar1 != 0) {
      _dev_err(param_1,"%s: card is NULL\n","pineapple_ssr_disable");
    }
  }
  else {
    snd_card_notify_user(0);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 0011457c size=48
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  snd_card_sysfs_init();
  __platform_driver_register(&pineapple_asoc_machine_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001145b0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&pineapple_asoc_machine_driver);
  return;
}



//------------------------------------------------------------
// sysfs_notify @ 00117000 size=1
// signature: undefined sysfs_notify(void)
// callers: [snd_card_sysfs_store, snd_card_notify_user]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00117008 size=1
// signature: undefined mutex_lock(void)
// callers: [msm_common_snd_hw_params, snd_card_notify_user, msm_vote_against_sleep_ctl_put, msm_common_snd_shutdown, msm_common_snd_startup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00117010 size=1
// signature: undefined mutex_unlock(void)
// callers: [msm_common_snd_hw_params, snd_card_notify_user, msm_vote_against_sleep_ctl_put, msm_common_snd_shutdown, msm_common_snd_startup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00117020 size=1
// signature: undefined kmalloc_trace(void)
// callers: [msm_channel_map_get, msm_common_get_backend_name, msm_snd_card_late_probe, msm_common_snd_init, snd_card_sysfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_init_and_add @ 00117030 size=1
// signature: undefined kobject_init_and_add(void)
// callers: [msm_common_snd_init, snd_card_sysfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_init_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_file_ns @ 00117038 size=1
// signature: undefined sysfs_create_file_ns(void)
// callers: [msm_common_snd_init, snd_card_sysfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00117040 size=1
// signature: undefined _printk(void)
// callers: [msm_common_snd_hw_params, msm_int_wsa881x_init, msm_vote_against_sleep_ctl_put, pineapple_ssr_enable, mi2s_tdm_hw_vote_req, aud_dev_sysfs_store, msm_rx_tx_codec_init, msm_channel_map_get, msm_audio_update_qos_request, msm_snd_card_late_probe, msm_int_wsa_init, msm_common_snd_init, msm_dmic_event, msm_common_snd_deinit, msm_common_dai_link_init, msm_asoc_machine_probe, msm_tx_codec_init, msm_common_snd_shutdown, snd_card_sysfs_init, msm_common_snd_startup, msm_int_wsa2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_put @ 00117048 size=1
// signature: undefined kobject_put(void)
// callers: [msm_common_snd_init, snd_card_sysfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00117050 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [msm_common_snd_hw_params, pineapple_ssr_enable, aud_dev_sysfs_store, msm_qos_ctl_put, msm_wcn_init, msm_audio_ssr_register, msm_channel_map_get, msm_common_get_backend_name, msm_snd_card_late_probe, msm_int_wsa_init, msm_common_snd_init, msm_dmic_event, msm_common_dai_link_init, msm_asoc_machine_probe, msm_common_snd_shutdown, snd_card_sysfs_init, msm_wcn_init_btfm, msm_int_wsa2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// digital_cdc_rsc_mgr_hw_vote_enable @ 00117060 size=1
// signature: undefined digital_cdc_rsc_mgr_hw_vote_enable(void)
// callers: [msm_common_snd_hw_params, mi2s_tdm_hw_vote_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void digital_cdc_rsc_mgr_hw_vote_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// digital_cdc_rsc_mgr_hw_vote_disable @ 00117068 size=1
// signature: undefined digital_cdc_rsc_mgr_hw_vote_disable(void)
// callers: [mi2s_tdm_hw_vote_req, msm_common_snd_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void digital_cdc_rsc_mgr_hw_vote_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00117070 size=1
// signature: size_t strlen(char * __s)
// callers: [msm_common_snd_hw_params, msm_common_dai_link_init, get_mi2s_tdm_auxpcm_intf_index, msm_common_snd_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 00117078 size=1
// signature: undefined strnstr(void)
// callers: [msm_common_snd_hw_params, get_mi2s_tdm_auxpcm_intf_index, msm_common_snd_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00117080 size=1
// signature: undefined _dev_err(void)
// callers: [msm_common_snd_hw_params, pineapple_ssr_enable, msm_snd_card_late_probe, msm_dmic_event, msm_asoc_machine_probe, msm_common_snd_shutdown, msm_rx_tx_codec_init, msm_common_snd_startup, pineapple_ssr_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// audio_prm_set_lpass_clk_cfg @ 00117088 size=1
// signature: undefined audio_prm_set_lpass_clk_cfg(void)
// callers: [msm_common_snd_hw_params, msm_common_snd_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void audio_prm_set_lpass_clk_cfg(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_set_runtime_hwparams @ 00117090 size=1
// signature: undefined snd_soc_set_runtime_hwparams(void)
// callers: [msm_common_snd_startup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_set_runtime_hwparams(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_active_state @ 00117098 size=1
// signature: undefined msm_cdc_pinctrl_select_active_state(void)
// callers: [msm_dmic_event, msm_common_snd_startup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_active_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_sleep_state @ 001170a0 size=1
// signature: undefined msm_cdc_pinctrl_select_sleep_state(void)
// callers: [msm_dmic_event, msm_common_snd_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_sleep_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001170a8 size=1
// signature: undefined __mutex_init(void)
// callers: [msm_common_snd_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001170b0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [msm_int_wsa_init, msm_common_snd_init, msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001170b8 size=1
// signature: undefined _dev_info(void)
// callers: [msm_common_snd_init, msm_dmic_event, msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 001170c0 size=1
// signature: undefined devm_clk_get(void)
// callers: [msm_common_snd_init, msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 001170c8 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [msm_audio_ssr_register, msm_common_snd_init, msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 001170d0 size=1
// signature: undefined devm_kmalloc(void)
// callers: [msm_common_snd_init, msm_common_dai_link_init, msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_weight @ 001170e8 size=1
// signature: undefined __bitmap_weight(void)
// callers: [msm_common_snd_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_weight(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001170f0 size=1
// signature: undefined __kmalloc(void)
// callers: [msm_channel_map_get, msm_common_snd_init, msm_common_dai_link_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 00117100 size=1
// signature: undefined _find_next_bit(void)
// callers: [msm_audio_update_qos_request, msm_common_snd_init, msm_common_snd_deinit, msm_qos_ctl_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_cpu_device @ 00117108 size=1
// signature: undefined get_cpu_device(void)
// callers: [msm_common_snd_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_cpu_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_qos_add_request @ 00117110 size=1
// signature: undefined dev_pm_qos_add_request(void)
// callers: [msm_common_snd_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_qos_add_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_qos_remove_request @ 00117118 size=1
// signature: undefined dev_pm_qos_remove_request(void)
// callers: [msm_common_snd_deinit, msm_qos_ctl_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_qos_remove_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00117120 size=1
// signature: undefined kfree(void)
// callers: [msm_channel_map_get, msm_snd_card_late_probe, msm_common_snd_deinit, msm_common_dai_link_init, msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dai_get_channel_map @ 00117128 size=1
// signature: undefined snd_soc_dai_get_channel_map(void)
// callers: [msm_channel_map_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dai_get_channel_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00117130 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [msm_channel_map_get, msm_common_get_backend_name, msm_snd_card_late_probe, msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 00117138 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [snd_card_sysfs_store, msm_common_get_backend_name, aud_dev_sysfs_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00117140 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [msm_common_get_backend_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00117148 size=1
// signature: undefined fortify_panic(void)
// callers: [msm_common_get_backend_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncmp @ 00117150 size=1
// signature: int strncmp(char * __s1, char * __s2, size_t __n)
// callers: [msm_common_dai_link_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00117158 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [msm_int_wsa_init, snd_card_sysfs_show, msm_common_dai_link_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_add_component_controls @ 00117160 size=1
// signature: undefined snd_soc_add_component_controls(void)
// callers: [msm_common_dai_link_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_add_component_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_card_get_kcontrol @ 00117168 size=1
// signature: undefined snd_soc_card_get_kcontrol(void)
// callers: [msm_common_dai_link_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_card_get_kcontrol(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_rtdcom_lookup @ 00117170 size=1
// signature: undefined snd_soc_rtdcom_lookup(void)
// callers: [pineapple_ssr_enable, msm_snd_card_late_probe, msm_int_wsa_init, msm_common_dai_link_init, msm_tx_codec_init, msm_rx_tx_codec_init, msm_int_wsa2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_rtdcom_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panic @ 00117178 size=1
// signature: noreturn undefined panic(void)
// callers: [aud_dev_sysfs_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// walt_get_cpus_taken @ 00117180 size=1
// signature: undefined walt_get_cpus_taken(void)
// callers: [msm_qos_ctl_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void walt_get_cpus_taken(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// walt_set_cpus_taken @ 00117188 size=1
// signature: undefined walt_set_cpus_taken(void)
// callers: [msm_qos_ctl_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void walt_set_cpus_taken(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// walt_unset_cpus_taken @ 00117190 size=1
// signature: undefined walt_unset_cpus_taken(void)
// callers: [msm_qos_ctl_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void walt_unset_cpus_taken(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// audio_prm_set_lpi_logging_status @ 00117198 size=1
// signature: undefined audio_prm_set_lpi_logging_status(void)
// callers: [msm_lpi_logging_enable_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void audio_prm_set_lpi_logging_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// audio_prm_set_vote_against_sleep @ 001171a0 size=1
// signature: undefined audio_prm_set_vote_against_sleep(void)
// callers: [msm_vote_against_sleep_ctl_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void audio_prm_set_vote_against_sleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_qos_update_request @ 001171a8 size=1
// signature: undefined dev_pm_qos_update_request(void)
// callers: [msm_audio_update_qos_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_qos_update_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 001171c0 size=1
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
// platform_driver_unregister @ 001171c8 size=1
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
// of_find_property @ 001171d0 size=1
// signature: undefined of_find_property(void)
// callers: [msm_snd_card_late_probe, msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_match_node @ 001171d8 size=1
// signature: undefined of_match_node(void)
// callers: [msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001171e0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [pineapple_ssr_enable, msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 001171e8 size=1
// signature: undefined ___ratelimit(void)
// callers: [pineapple_ssr_enable, msm_dmic_event, msm_asoc_machine_probe, msm_rx_tx_codec_init, pineapple_ssr_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// socinfo_get_part_info @ 001171f0 size=1
// signature: undefined socinfo_get_part_info(void)
// callers: [msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void socinfo_get_part_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_get @ 001171f8 size=1
// signature: undefined nvmem_cell_get(void)
// callers: [msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_read @ 00117200 size=1
// signature: undefined nvmem_cell_read(void)
// callers: [msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_put @ 00117208 size=1
// signature: undefined nvmem_cell_put(void)
// callers: [msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_of_parse_card_name @ 00117210 size=1
// signature: undefined snd_soc_of_parse_card_name(void)
// callers: [msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_of_parse_card_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_of_parse_audio_routing @ 00117218 size=1
// signature: undefined snd_soc_of_parse_audio_routing(void)
// callers: [msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_of_parse_audio_routing(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_match_string @ 00117220 size=1
// signature: undefined of_property_match_string(void)
// callers: [msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_match_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_available @ 00117228 size=1
// signature: undefined of_device_is_available(void)
// callers: [msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00117230 size=1
// signature: undefined of_property_read_string(void)
// callers: [msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_snd_soc_register_card @ 00117238 size=1
// signature: undefined devm_snd_soc_register_card(void)
// callers: [msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_snd_soc_register_card(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_set_wakeup_capable @ 00117240 size=1
// signature: undefined msm_cdc_pinctrl_set_wakeup_capable(void)
// callers: [msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 00117248 size=1
// signature: undefined devm_kfree(void)
// callers: [msm_asoc_machine_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_event_master_deregister @ 00117250 size=1
// signature: undefined snd_event_master_deregister(void)
// callers: [msm_asoc_machine_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_event_master_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_unregister_card @ 00117258 size=1
// signature: undefined snd_soc_unregister_card(void)
// callers: [msm_asoc_machine_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_unregister_card(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fsa4480_switch_event @ 00117260 size=1
// signature: undefined fsa4480_switch_event(void)
// callers: [msm_usbc_swap_gnd_mic]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fsa4480_switch_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_usbss_switch_update @ 00117268 size=1
// signature: undefined wcd_usbss_switch_update(void)
// callers: [msm_usbc_swap_gnd_mic]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_usbss_switch_update(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_event_mstr_add_client @ 00117270 size=1
// signature: undefined snd_event_mstr_add_client(void)
// callers: [msm_audio_ssr_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_event_mstr_add_client(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_event_master_register @ 00117278 size=1
// signature: undefined snd_event_master_register(void)
// callers: [msm_audio_ssr_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_event_master_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_event_notify @ 00117280 size=1
// signature: undefined snd_event_notify(void)
// callers: [msm_audio_ssr_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_event_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_get_pcm_runtime @ 00117288 size=1
// signature: undefined snd_soc_get_pcm_runtime(void)
// callers: [pineapple_ssr_enable, msm_snd_card_late_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_get_pcm_runtime(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00117290 size=1
// signature: undefined strscpy(void)
// callers: [pineapple_ssr_enable, msm_snd_card_late_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd937x_mbhc_hs_detect @ 00117298 size=1
// signature: undefined wcd937x_mbhc_hs_detect(void)
// callers: [msm_snd_card_late_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd937x_mbhc_hs_detect(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd9378_mbhc_hs_detect @ 001172a0 size=1
// signature: undefined wcd9378_mbhc_hs_detect(void)
// callers: [msm_snd_card_late_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd9378_mbhc_hs_detect(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd939x_mbhc_hs_detect @ 001172a8 size=1
// signature: undefined wcd939x_mbhc_hs_detect(void)
// callers: [msm_snd_card_late_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd939x_mbhc_hs_detect(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strstr @ 001172b0 size=1
// signature: char * strstr(char * __haystack, char * __needle)
// callers: [pineapple_ssr_enable, msm_int_wsa_init, msm_int_wsa2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wsa883x_set_channel_map @ 001172b8 size=1
// signature: undefined wsa883x_set_channel_map(void)
// callers: [msm_int_wsa_init, msm_int_wsa2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wsa883x_set_channel_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wsa883x_codec_info_create_codec_entry @ 001172c0 size=1
// signature: undefined wsa883x_codec_info_create_codec_entry(void)
// callers: [msm_int_wsa_init, msm_int_wsa2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wsa883x_codec_info_create_codec_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wsa884x_set_channel_map @ 001172c8 size=1
// signature: undefined wsa884x_set_channel_map(void)
// callers: [msm_int_wsa_init, msm_int_wsa2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wsa884x_set_channel_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wsa884x_codec_info_create_codec_entry @ 001172d0 size=1
// signature: undefined wsa884x_codec_info_create_codec_entry(void)
// callers: [msm_int_wsa_init, msm_int_wsa2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wsa884x_codec_info_create_codec_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_new_controls @ 001172d8 size=1
// signature: undefined snd_soc_dapm_new_controls(void)
// callers: [msm_tx_codec_init, msm_rx_tx_codec_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_new_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_ignore_suspend @ 001172e0 size=1
// signature: undefined snd_soc_dapm_ignore_suspend(void)
// callers: [msm_tx_codec_init, msm_rx_tx_codec_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_ignore_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_info_create_codec_entry @ 001172e8 size=1
// signature: undefined lpass_cdc_info_create_codec_entry(void)
// callers: [msm_tx_codec_init, msm_rx_tx_codec_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_info_create_codec_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_set_port_map @ 001172f0 size=1
// signature: undefined lpass_cdc_set_port_map(void)
// callers: [msm_tx_codec_init, msm_rx_tx_codec_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_set_port_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_create_module_entry @ 001172f8 size=1
// signature: undefined snd_info_create_module_entry(void)
// callers: [msm_tx_codec_init, msm_rx_tx_codec_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_create_module_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_register @ 00117300 size=1
// signature: undefined snd_info_register(void)
// callers: [msm_tx_codec_init, msm_rx_tx_codec_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_free_entry @ 00117308 size=1
// signature: undefined snd_info_free_entry(void)
// callers: [msm_tx_codec_init, msm_rx_tx_codec_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_free_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strpbrk @ 00117310 size=1
// signature: char * strpbrk(char * __s, char * __accept)
// callers: [msm_dmic_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strpbrk(char *__s,char *__accept)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00117318 size=1
// signature: undefined kstrtouint(void)
// callers: [msm_dmic_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_register_wake_irq @ 00117320 size=1
// signature: undefined lpass_cdc_register_wake_irq(void)
// callers: [msm_rx_tx_codec_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_register_wake_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_sync @ 00117328 size=1
// signature: undefined snd_soc_dapm_sync(void)
// callers: [msm_rx_tx_codec_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd937x_info_create_codec_entry @ 00117330 size=1
// signature: undefined wcd937x_info_create_codec_entry(void)
// callers: [msm_rx_tx_codec_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd937x_info_create_codec_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd937x_get_codec_variant @ 00117338 size=1
// signature: undefined wcd937x_get_codec_variant(void)
// callers: [msm_rx_tx_codec_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd937x_get_codec_variant(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd9378_info_create_codec_entry @ 00117340 size=1
// signature: undefined wcd9378_info_create_codec_entry(void)
// callers: [msm_rx_tx_codec_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd9378_info_create_codec_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd939x_info_create_codec_entry @ 00117348 size=1
// signature: undefined wcd939x_info_create_codec_entry(void)
// callers: [msm_rx_tx_codec_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd939x_info_create_codec_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd939x_get_codec_variant @ 00117350 size=1
// signature: undefined wcd939x_get_codec_variant(void)
// callers: [msm_rx_tx_codec_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd939x_get_codec_variant(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_rx_set_fir_capability @ 00117358 size=1
// signature: undefined lpass_cdc_rx_set_fir_capability(void)
// callers: [msm_rx_tx_codec_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_rx_set_fir_capability(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dai_set_channel_map @ 00117360 size=1
// signature: undefined snd_soc_dai_set_channel_map(void)
// callers: [msm_wcn_init, msm_wcn_init_btfm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dai_set_channel_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd937x_codec_get_dev_num @ 00117368 size=1
// signature: undefined wcd937x_codec_get_dev_num(void)
// callers: [pineapple_ssr_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd937x_codec_get_dev_num(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// audio_prm_set_cdc_earpa_duty_cycling_req @ 00117390 size=1
// signature: undefined audio_prm_set_cdc_earpa_duty_cycling_req(void)
// callers: [pineapple_ssr_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void audio_prm_set_cdc_earpa_duty_cycling_req(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



