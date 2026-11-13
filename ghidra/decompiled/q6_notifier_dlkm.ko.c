// Decompiled by Ghidra 12.2
// Program: q6_notifier_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// audio_notifier_deregister @ 00100364 size=992
// signature: undefined audio_notifier_deregister(void)
// callers: []
//------------------------------------------------------------

int audio_notifier_deregister(char *param_1)

{
  int *piVar1;
  undefined *puVar2;
  long *plVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ulong uVar10;
  ulong uVar11;
  undefined **ppuVar12;
  undefined **ppuVar13;
  undefined **__s2;
  
  if (param_1 == (char *)0x0) {
    iVar8 = ___ratelimit(&audio_notifier_deregister__rs,"audio_notifier_deregister");
    if (iVar8 == 0) {
      iVar8 = -0x16;
    }
    else {
      _printk(&DAT_001024d4,"audio_notifier_deregister");
      iVar8 = -0x16;
    }
  }
  else if ((undefined **)client_list == &client_list) {
    iVar8 = 0;
  }
  else {
    iVar8 = 0;
    ppuVar12 = (undefined **)client_list;
    do {
      __s2 = ppuVar12 + 3;
      ppuVar13 = (undefined **)*ppuVar12;
      iVar7 = strcmp(param_1,(char *)__s2);
      if (iVar7 == 0) {
        uVar4 = *(uint *)((long)ppuVar12 + 0x2c);
        if (uVar4 < 2) {
          uVar5 = *(uint *)(ppuVar12 + 6);
          if (1 < uVar5) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x100744);
            (*pcVar6)();
          }
          uVar11 = (ulong)uVar5 * 0x250 + (ulong)uVar4 * 0x4a0;
          if (0x90c < uVar11) goto LAB_0010073c;
          piVar1 = (int *)(&DAT_001014e8 + uVar11);
          if (*piVar1 == 1) {
            if (uVar4 == 1) {
              if (0x48c < (ulong)uVar5 * 0x250) goto LAB_0010073c;
              iVar7 = audio_pdr_service_deregister
                                (*(undefined4 *)(&DAT_0010196c + (ulong)uVar5 * 0x250));
joined_r0x001004fc:
              if (-1 < iVar7) {
                mutex_lock(&notifier_mutex);
                if ((0x924 < (ulong)uVar5 * 0x250 + (ulong)uVar4 * 0x4a0) ||
                   (uVar10 = (ulong)uVar5 * 0x250 + (ulong)uVar4 * 0x4a0,
                   *(undefined4 *)(&DAT_001014d0 + uVar10) = 0, 0x918 < uVar10)) goto LAB_0010073c;
                *(undefined8 *)(&DAT_001014d8 + (ulong)uVar4 * 0x4a0 + (ulong)uVar5 * 0x250) = 0;
                mutex_unlock(&notifier_mutex);
                goto LAB_0010056c;
              }
              iVar8 = ___ratelimit(audio_notifier_dereg_service__rs_17,
                                   "audio_notifier_dereg_service");
              if (iVar8 != 0) {
                _printk(&DAT_001026a4,"audio_notifier_dereg_service",service_data + uVar11,iVar7);
              }
            }
            else {
              if (uVar4 == 0) {
                if ((0x920 < (ulong)uVar5 * 0x250) || (0x918 < (ulong)uVar5 * 0x250))
                goto LAB_0010073c;
                iVar7 = audio_ssr_deregister
                                  (*(undefined8 *)(&DAT_001014d8 + (ulong)uVar5 * 0x250),
                                   (&PTR_notifier_ssr_adsp_nb_001014e0)[(ulong)uVar5 * 0x4a]);
                goto joined_r0x001004fc;
              }
              iVar8 = ___ratelimit(audio_notifier_dereg_service__rs,"audio_notifier_dereg_service");
              if (iVar8 != 0) {
                _printk(&DAT_00102575,"audio_notifier_dereg_service",uVar4);
              }
              iVar7 = -0x16;
            }
            iVar8 = ___ratelimit(audio_notifier_dereg_client__rs_9,"audio_notifier_dereg_client");
            if (iVar8 != 0) {
              _printk(&DAT_00102232,"audio_notifier_dereg_client",__s2,service_data + uVar11,iVar7);
            }
          }
          else {
LAB_0010056c:
            iVar7 = srcu_notifier_chain_unregister
                              (&DAT_001014f0 + (ulong)uVar4 * 0x4a0 + (ulong)uVar5 * 0x250,
                               ppuVar12[2]);
            if (-1 < iVar7) {
              *(undefined4 *)((long)ppuVar12 + 0x2c) = 0xfffffffe;
              if (0x90c < uVar11) {
LAB_0010073c:
                    /* WARNING: Does not return */
                pcVar6 = (code *)SoftwareBreakpoint(1,0x100740);
                (*pcVar6)();
              }
              if (0 < *piVar1) {
                if (0x90c < uVar11) goto LAB_0010073c;
                *piVar1 = *piVar1 + -1;
              }
              goto LAB_001005b4;
            }
            iVar8 = ___ratelimit(audio_notifier_dereg_client__rs_11,"audio_notifier_dereg_client");
            if (iVar8 != 0) {
              _printk(&DAT_00102401,"audio_notifier_dereg_client",iVar7);
            }
          }
        }
        else {
          if (uVar4 == 0xfffffffe) {
LAB_001005b4:
            uVar11 = __list_del_entry_valid(ppuVar12);
            if ((uVar11 & 1) != 0) {
              puVar2 = *ppuVar12;
              plVar3 = (long *)ppuVar12[1];
              *(long **)(puVar2 + 8) = plVar3;
              *plVar3 = (long)puVar2;
            }
            *ppuVar12 = (undefined *)0xdead000000000100;
            ppuVar12[1] = (undefined *)0xdead000000000122;
            kfree(ppuVar12);
            goto LAB_001003c4;
          }
          iVar8 = ___ratelimit(audio_notifier_dereg_client__rs,"audio_notifier_dereg_client");
          if (iVar8 != 0) {
            _printk(&DAT_001021d5,"audio_notifier_dereg_client",__s2,
                    *(undefined4 *)((long)ppuVar12 + 0x2c));
          }
          iVar7 = -0x16;
        }
        iVar9 = ___ratelimit(audio_notifier_deregister__rs_1,"audio_notifier_deregister");
        iVar8 = iVar7;
        if (iVar9 != 0) {
          _printk(&DAT_0010236a,"audio_notifier_deregister",iVar7,
                  *(undefined4 *)((long)ppuVar12 + 0x2c),*(undefined4 *)(ppuVar12 + 6));
        }
      }
LAB_001003c4:
      ppuVar12 = ppuVar13;
    } while (ppuVar13 != &client_list);
  }
  return iVar8;
}



//------------------------------------------------------------
// audio_notifier_register @ 00100748 size=428
// signature: undefined audio_notifier_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int audio_notifier_register(char *param_1,undefined4 param_2,long param_3)

{
  undefined8 *__dest;
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  size_t __n;
  ulong uVar4;
  undefined *puVar5;
  
  if (param_1 == (char *)0x0) {
    iVar1 = ___ratelimit(audio_notifier_register__rs,"audio_notifier_register");
    if (iVar1 == 0) {
      return -0x16;
    }
    puVar5 = &DAT_001024d4;
  }
  else {
    if (param_3 != 0) {
      puVar3 = (undefined8 *)kmalloc_trace(__dev_err,0xcc0,0x38);
      if (puVar3 == (undefined8 *)0x0) {
        return -0xc;
      }
      *puVar3 = puVar3;
      __dest = puVar3 + 3;
      puVar3[1] = puVar3;
      puVar3[2] = param_3;
      __n = strlen(param_1);
      if (0x12 < __n) {
        __n = 0x13;
      }
      memcpy(__dest,param_1,__n);
      *(undefined1 *)((long)__dest + __n) = 0;
      *(undefined4 *)((long)puVar3 + 0x2c) = 0xfffffffe;
      *(undefined4 *)(puVar3 + 6) = param_2;
      mutex_lock(&notifier_mutex);
      iVar1 = audio_notifier_reg_client(puVar3);
      puVar5 = PTR_client_list_001013e8;
      if (iVar1 < 0) {
        mutex_unlock(&notifier_mutex);
        iVar2 = ___ratelimit(audio_notifier_register__rs_5,"audio_notifier_register");
        if (iVar2 != 0) {
          _printk(&DAT_00102196,"audio_notifier_register",__dest,iVar1);
        }
        kfree(puVar3);
        return iVar1;
      }
      uVar4 = __list_add_valid(puVar3,PTR_client_list_001013e8,&client_list);
      if ((uVar4 & 1) != 0) {
        PTR_client_list_001013e8 = (undefined *)puVar3;
        *puVar3 = &client_list;
        puVar3[1] = puVar5;
        *(undefined8 **)puVar5 = puVar3;
      }
      mutex_unlock(&notifier_mutex);
      return iVar1;
    }
    iVar1 = ___ratelimit(audio_notifier_register__rs_3,"audio_notifier_register");
    if (iVar1 == 0) {
      return -0x16;
    }
    puVar5 = &DAT_00102178;
  }
  _printk(puVar5,"audio_notifier_register");
  return -0x16;
}



//------------------------------------------------------------
// audio_notifier_reg_client @ 001008f4 size=1140
// signature: undefined audio_notifier_reg_client(void)
// callers: [audio_notifier_register, audio_notify_probe]
//------------------------------------------------------------

void audio_notifier_reg_client(long param_1)

{
  bool bVar1;
  int *piVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  code *pcVar7;
  int iVar8;
  undefined8 uVar9;
  ulong uVar10;
  uint uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  uint local_70;
  uint uStack_6c;
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  uVar4 = *(uint *)(param_1 + 0x30);
  uVar11 = 0;
  if (uVar4 != 1) {
    uVar11 = 0xfffffffe;
  }
  if (uVar4 == 0) {
    uVar11 = 1;
  }
  if ((int)uVar11 < 0) {
    iVar8 = ___ratelimit(audio_notifier_reg_client__rs,"audio_notifier_reg_client");
    if (iVar8 != 0) {
      _printk(&DAT_00102473,"audio_notifier_reg_client",uVar11);
    }
LAB_00100d08:
    uVar9 = 0xffffffea;
  }
  else {
    uVar9 = 0;
    do {
      lVar6 = adsp_private;
      if (1 < (uVar11 | uVar4)) {
LAB_00100d60:
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x100d64);
        (*pcVar7)();
      }
      if (0x924 < (ulong)uVar4 * 0x250 + (ulong)uVar11 * 0x4a0) goto LAB_00100d5c;
      uVar13 = (ulong)uVar11;
      if (*(int *)(&DAT_001014d0 + uVar13 * 0x4a0 + (ulong)uVar4 * 0x250) == -1) {
        iVar8 = ___ratelimit(audio_notifier_reg_client__rs_22,"audio_notifier_reg_client");
        if (iVar8 != 0) {
          _printk(&DAT_00102206,"audio_notifier_reg_client");
        }
        goto LAB_00100d08;
      }
      if ((-1 < *(int *)(&DAT_001014d0 + uVar13 * 0x4a0 + (ulong)uVar4 * 0x250)) &&
         (*(int *)(param_1 + 0x2c) == -2)) {
        uVar5 = *(uint *)(param_1 + 0x30);
        if (1 < uVar5) goto LAB_00100d60;
        uVar14 = (ulong)uVar5 * 0x250 + uVar13 * 0x4a0;
        if (0x90c < uVar14) goto LAB_00100d5c;
        pcVar3 = service_data + uVar14;
        piVar2 = (int *)(&DAT_001014e8 + uVar14);
        if (*piVar2 == 0) {
          if (*(long **)(adsp_private + 0xa8) != (long *)0x0) {
            if (uVar11 == 1) {
              if ((0x48c < (ulong)uVar5 * 0x250) || (0x478 < (ulong)uVar5 * 0x250))
              goto LAB_00100d5c;
              uVar10 = audio_pdr_service_register
                                 (*(undefined4 *)(&DAT_0010196c + (ulong)uVar5 * 0x250),
                                  (&PTR_audio_notifier_pdr_adsp_cb_00101980)[(ulong)uVar5 * 0x4a]);
joined_r0x00100b50:
              if ((uVar10 != 0) && (uVar10 < 0xfffffffffffff001)) {
                if ((0x924 < (ulong)uVar5 * 0x250 + uVar13 * 0x4a0) ||
                   (uVar12 = (ulong)uVar5 * 0x250 + uVar13 * 0x4a0,
                   *(undefined4 *)(&DAT_001014d0 + uVar12) = 0, 0x918 < uVar12)) goto LAB_00100d5c;
                *(ulong *)(&DAT_001014d8 + uVar13 * 0x4a0 + (ulong)uVar5 * 0x250) = uVar10;
                _printk(&DAT_001025a1,"audio_notifier_reg_service",pcVar3);
                goto LAB_00100a20;
              }
              iVar8 = ___ratelimit(audio_notifier_reg_service__rs_30,"audio_notifier_reg_service");
              if (iVar8 != 0) {
                _printk(&DAT_0010252d,"audio_notifier_reg_service",pcVar3);
              }
            }
            else {
              if (uVar11 == 0) {
                if (0x918 < (ulong)uVar5 * 0x250) goto LAB_00100d5c;
                uVar10 = audio_ssr_register(*(undefined8 *)(**(long **)(adsp_private + 0xa8) + 0x18)
                                            ,(&PTR_notifier_ssr_adsp_nb_001014e0)
                                             [(ulong)uVar5 * 0x4a]);
                goto joined_r0x00100b50;
              }
              iVar8 = ___ratelimit(audio_notifier_reg_service__rs_29,"audio_notifier_reg_service");
              if (iVar8 != 0) {
                _printk(&DAT_00102575,"audio_notifier_reg_service",uVar11);
              }
            }
            iVar8 = ___ratelimit(audio_notifier_reg_client_service__rs_27,
                                 "audio_notifier_reg_client_service");
            if (iVar8 != 0) {
              _printk(&DAT_0010232b,"audio_notifier_reg_client_service",pcVar3,param_1 + 0x18);
            }
            iVar8 = ___ratelimit(audio_notifier_reg_client__rs_24,"audio_notifier_reg_client");
            if (iVar8 == 0) {
              uVar9 = 0xffffffea;
            }
            else {
              _printk(&DAT_0010261d,"audio_notifier_reg_client",param_1 + 0x18,
                      service_data + (ulong)uVar4 * 0x250 + (ulong)uVar11 * 0x4a0);
              uVar9 = 0xffffffea;
            }
            goto LAB_001009a4;
          }
          iVar8 = ___ratelimit(audio_notifier_reg_service__rs,"audio_notifier_reg_service");
          if (iVar8 != 0) {
            _dev_err(lVar6 + 0x10," %s: Private data get failed\n","audio_notifier_reg_service");
          }
        }
LAB_00100a20:
        *(uint *)(param_1 + 0x2c) = uVar11;
        srcu_notifier_chain_register
                  (&DAT_001014f0 + uVar13 * 0x4a0 + (ulong)uVar5 * 0x250,
                   *(undefined8 *)(param_1 + 0x10));
        if ((0x90c < uVar14) || (uVar14 - 0x90d < 4)) {
LAB_00100d5c:
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(1,0x100d60);
          (*pcVar7)();
        }
        *piVar2 = *piVar2 + 1;
        if (*(int *)(param_1 + 0x2c) == 1) {
          local_70 = uVar11;
          uStack_6c = uVar5;
          if (0x924 < (ulong)uVar5 * 0x250 + uVar13 * 0x4a0) goto LAB_00100d5c;
          pcVar7 = (code *)**(undefined8 **)(param_1 + 0x10);
          if (*(int *)(pcVar7 + -4) != 0x2a4cec24) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x8229,0x100998);
            (*pcVar7)();
          }
          (*pcVar7)(*(undefined8 **)(param_1 + 0x10),
                    (long)*(int *)(&DAT_001014d0 + uVar13 * 0x4a0 + (ulong)uVar5 * 0x250),&local_70)
          ;
        }
        uVar9 = 0;
      }
LAB_001009a4:
      bVar1 = 0 < (int)uVar11;
      uVar11 = uVar11 - 1;
    } while (bVar1);
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9);
  }
  return;
}



//------------------------------------------------------------
// audio_notifier_probe_status @ 00100d6c size=88
// signature: undefined audio_notifier_probe_status(void)
// callers: []
//------------------------------------------------------------

undefined8 audio_notifier_probe_status(void)

{
  if (adsp_private != 0) {
    if (*(long *)(adsp_private + 0xa8) == 0) {
      _dev_err(adsp_private + 0x10," %s: Private data get failed\n","audio_notifier_probe_status");
    }
    else if (*(char *)(*(long *)(adsp_private + 0xa8) + 8) != '\0') {
      return 1;
    }
  }
  return 0;
}



//------------------------------------------------------------
// audio_notifier_pdr_adsp_cb @ 00100dc8 size=40
// signature: undefined audio_notifier_pdr_adsp_cb(void)
// callers: []
//------------------------------------------------------------

void audio_notifier_pdr_adsp_cb(int param_1)

{
  audio_notifier_service_cb((long)param_1,1,0);
  return;
}



//------------------------------------------------------------
// audio_notifier_ssr_adsp_cb @ 00100df4 size=44
// signature: undefined audio_notifier_ssr_adsp_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 audio_notifier_ssr_adsp_cb(undefined8 param_1,undefined8 param_2)

{
  audio_notifier_service_cb(param_2,0,0);
  return 1;
}



//------------------------------------------------------------
// audio_notifier_service_cb @ 00100e20 size=452
// signature: undefined audio_notifier_service_cb(void)
// callers: [audio_notifier_ssr_modem_cb, audio_notifier_ssr_adsp_cb, audio_notifier_pdr_adsp_cb]
//------------------------------------------------------------

void audio_notifier_service_cb(long param_1,uint param_2,uint param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  ulong uVar6;
  uint local_50;
  uint uStack_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  uVar5 = 1;
  if (param_1 < 0xfffffff) {
    if (param_1 != 1) {
      if (param_1 != 2) goto LAB_00100f88;
      goto LAB_00100edc;
    }
  }
  else if (param_1 == 0xfffffff) {
    if (service_early_down == '\x01') {
      service_early_down = '\0';
      _printk(&DAT_00102509,"audio_notifier_convert_opcode",0);
      goto LAB_00100f88;
    }
LAB_00100edc:
    uVar5 = 0;
  }
  else if (param_1 != 0x1fffffff) {
    if (param_1 != 0x2fffffff) goto LAB_00100f88;
    uVar5 = 0;
    service_early_down = '\x01';
  }
  uVar6 = (ulong)param_3 * 0x250 + (ulong)param_2 * 0x4a0;
  local_50 = param_2;
  uStack_4c = param_3;
  _printk(&DAT_001022bf,"audio_notifier_service_cb",service_data + uVar6,uVar5);
  mutex_lock(&notifier_mutex);
  if (0x924 < uVar6) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(1,0x100fe4);
    (*pcVar2)();
  }
  lVar1 = (ulong)param_3 * 0x250 + (ulong)param_2 * 0x4a0;
  *(undefined4 *)(service_data + lVar1 + 0x18) = uVar5;
  iVar3 = srcu_notifier_call_chain(service_data + lVar1 + 0x38,uVar5,&local_50);
  mutex_unlock(&notifier_mutex);
  if ((iVar3 < 0) &&
     (iVar4 = ___ratelimit(audio_notifier_service_cb__rs,"audio_notifier_service_cb"), iVar4 != 0))
  {
    _printk(&DAT_001023b8,"audio_notifier_service_cb",iVar3,service_data + uVar6,uVar5);
  }
LAB_00100f88:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// audio_notifier_ssr_modem_cb @ 00100fe8 size=44
// signature: undefined audio_notifier_ssr_modem_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 audio_notifier_ssr_modem_cb(undefined8 param_1,undefined8 param_2)

{
  audio_notifier_service_cb(param_2,0,1);
  return 1;
}



//------------------------------------------------------------
// audio_notify_probe @ 00101018 size=652
// signature: undefined audio_notify_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void audio_notify_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  undefined8 uVar6;
  long lVar7;
  undefined **ppuVar8;
  undefined **ppuVar9;
  undefined4 local_5c;
  long local_58;
  
  lVar7 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_58 = *(long *)(lVar7 + 0x638);
  local_5c = 0;
  adsp_private = 0;
  plVar5 = (long *)devm_kmalloc(lVar1,0x10,0xdc0);
  if (plVar5 == (long *)0x0) {
    uVar6 = 0xfffffff4;
  }
  else {
    uVar6 = *(undefined8 *)(param_1 + 0x2f8);
    *(undefined1 *)(plVar5 + 1) = 0;
    *(long **)(param_1 + 0xa8) = plVar5;
    lVar7 = of_find_property(uVar6,"qcom,rproc-handle",&local_5c);
    if (lVar7 == 0) {
      _dev_err(lVar1,"Missing remotproc handle\n");
      uVar6 = 0xffffffea;
    }
    else {
      uVar2 = (**(uint **)(lVar7 + 0x10) & 0xff00ff00) >> 8 |
              (**(uint **)(lVar7 + 0x10) & 0xff00ff) << 8;
      lVar7 = rproc_get_by_phandle(uVar2 >> 0x10 | uVar2 << 0x10);
      *plVar5 = lVar7;
      if (lVar7 == 0) {
        iVar3 = ___ratelimit(audio_notify_probe__rs,"audio_notify_probe");
        if (iVar3 != 0) {
          _dev_info(lVar1,"remotproc handle NULL\n");
        }
        uVar6 = 0xfffffdfb;
      }
      else {
        adsp_private = param_1;
        __mutex_init(&notifier_mutex,"&notifier_mutex",&audio_notifier_subsys_init___key);
        if (-2 < _DAT_001014d0) {
          srcu_init_notifier_head(&DAT_001014f0);
        }
        if (-2 < _DAT_00101720) {
          srcu_init_notifier_head(&DAT_00101740);
        }
        if (-2 < _DAT_00101970) {
          srcu_init_notifier_head(&DAT_00101990);
        }
        if (-2 < _DAT_00101bc0) {
          srcu_init_notifier_head(&DAT_00101be0);
        }
        if (_DAT_00101970 == -1) {
          _DAT_00101970 = 0;
        }
        if (_DAT_00101bc0 == -1) {
          _DAT_00101bc0 = 0;
        }
        mutex_lock(&notifier_mutex);
        if (((_DAT_00101970 == -2) && (_DAT_00101bc0 == -2)) &&
           (ppuVar8 = (undefined **)client_list, (undefined **)client_list != &client_list)) {
          do {
            ppuVar9 = (undefined **)*ppuVar8;
            iVar3 = audio_notifier_reg_client(ppuVar8);
            if ((iVar3 < 0) &&
               (iVar4 = ___ratelimit(audio_notifier_reg_all_clients__rs,
                                     "audio_notifier_reg_all_clients"), iVar4 != 0)) {
              _printk(&DAT_00102492,"audio_notifier_reg_all_clients",ppuVar8 + 3,iVar3);
            }
            ppuVar8 = ppuVar9;
          } while (ppuVar9 != &client_list);
        }
        mutex_unlock(&notifier_mutex);
        uVar6 = 0;
        *(undefined1 *)(plVar5 + 1) = 1;
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// audio_notify_remove @ 001012a8 size=8
// signature: undefined audio_notify_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 audio_notify_remove(void)

{
  return 0;
}



//------------------------------------------------------------
// audio_ssr_register @ 001012b4 size=60
// signature: undefined audio_ssr_register(void)
// callers: [audio_notifier_reg_client]
//------------------------------------------------------------

undefined8 audio_ssr_register(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    _printk(&DAT_001022f6,"audio_ssr_register");
    uVar1 = 0xffffffffffffffea;
  }
  else {
    uVar1 = qcom_register_ssr_notifier();
  }
  return uVar1;
}



//------------------------------------------------------------
// audio_ssr_deregister @ 001012f4 size=28
// signature: undefined audio_ssr_deregister(void)
// callers: [audio_notifier_deregister]
//------------------------------------------------------------

void audio_ssr_deregister(void)

{
  qcom_unregister_ssr_notifier();
  return;
}



//------------------------------------------------------------
// init_module @ 0010138c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&adsp_notify_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001013bc size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&adsp_notify_driver);
  return;
}



//------------------------------------------------------------
// kfree @ 00104000 size=1
// signature: undefined kfree(void)
// callers: [audio_notifier_deregister, audio_notifier_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00104008 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [audio_notifier_deregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00104010 size=1
// signature: undefined ___ratelimit(void)
// callers: [audio_notifier_deregister, audio_notifier_reg_client, audio_notifier_register, audio_notifier_service_cb, audio_notify_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104018 size=1
// signature: undefined _printk(void)
// callers: [audio_ssr_register, audio_notifier_deregister, audio_notifier_reg_client, audio_notifier_register, audio_notifier_service_cb, audio_notify_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// audio_pdr_service_deregister @ 00104020 size=1
// signature: undefined audio_pdr_service_deregister(void)
// callers: [audio_notifier_deregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void audio_pdr_service_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00104028 size=1
// signature: undefined mutex_lock(void)
// callers: [audio_notifier_deregister, audio_notifier_register, audio_notifier_service_cb, audio_notify_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104030 size=1
// signature: undefined mutex_unlock(void)
// callers: [audio_notifier_deregister, audio_notifier_register, audio_notifier_service_cb, audio_notify_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// srcu_notifier_chain_unregister @ 00104038 size=1
// signature: undefined srcu_notifier_chain_unregister(void)
// callers: [audio_notifier_deregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void srcu_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00104040 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [audio_notifier_deregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00104050 size=1
// signature: undefined kmalloc_trace(void)
// callers: [audio_notifier_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00104058 size=1
// signature: size_t strlen(char * __s)
// callers: [audio_notifier_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00104060 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [audio_notifier_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00104068 size=1
// signature: undefined __list_add_valid(void)
// callers: [audio_notifier_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// srcu_notifier_chain_register @ 00104070 size=1
// signature: undefined srcu_notifier_chain_register(void)
// callers: [audio_notifier_reg_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void srcu_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104078 size=1
// signature: undefined _dev_err(void)
// callers: [audio_notifier_probe_status, audio_notifier_reg_client, audio_notify_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// audio_pdr_service_register @ 00104080 size=1
// signature: undefined audio_pdr_service_register(void)
// callers: [audio_notifier_reg_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void audio_pdr_service_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104088 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [audio_notifier_reg_client, audio_notifier_service_cb, audio_notify_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00104090 size=1
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
// platform_driver_unregister @ 00104098 size=1
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
// srcu_notifier_call_chain @ 001040a0 size=1
// signature: undefined srcu_notifier_call_chain(void)
// callers: [audio_notifier_service_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void srcu_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 001040a8 size=1
// signature: undefined devm_kmalloc(void)
// callers: [audio_notify_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001040b0 size=1
// signature: undefined of_find_property(void)
// callers: [audio_notify_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_get_by_phandle @ 001040b8 size=1
// signature: undefined rproc_get_by_phandle(void)
// callers: [audio_notify_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_get_by_phandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001040c0 size=1
// signature: undefined __mutex_init(void)
// callers: [audio_notify_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// srcu_init_notifier_head @ 001040c8 size=1
// signature: undefined srcu_init_notifier_head(void)
// callers: [audio_notify_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void srcu_init_notifier_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001040d0 size=1
// signature: undefined _dev_info(void)
// callers: [audio_notify_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_register_ssr_notifier @ 001040d8 size=1
// signature: undefined qcom_register_ssr_notifier(void)
// callers: [audio_ssr_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_register_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_unregister_ssr_notifier @ 001040e0 size=1
// signature: undefined qcom_unregister_ssr_notifier(void)
// callers: [audio_ssr_deregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_unregister_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



