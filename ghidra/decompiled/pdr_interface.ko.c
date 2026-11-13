// Decompiled by Ghidra 12.2
// Program: pdr_interface.ko
// Image base: 00100000

//------------------------------------------------------------
// pdr_add_lookup @ 00100454 size=80
// signature: undefined pdr_add_lookup(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong pdr_add_lookup(long param_1)

{
  ulong uVar1;
  
  uVar1 = pdr_lookup_common();
  if ((uVar1 != 0) && (uVar1 < 0xfffffffffffff001)) {
    queue_work_on(0x20,_system_wq,param_1 + 0x358);
  }
  return uVar1;
}



//------------------------------------------------------------
// pdr_lookup_common @ 001004a4 size=412
// signature: undefined pdr_lookup_common(void)
// callers: [pdr_add_service_lookup, pdr_add_lookup]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long pdr_lookup_common(ulong param_1,char *param_2,char *param_3)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  int iVar4;
  size_t sVar5;
  ulong uVar6;
  long lVar7;
  long *plVar8;
  long lVar9;
  
  lVar7 = -0x16;
  if ((((param_1 != 0) && (param_1 < 0xfffffffffffff001)) && (param_2 != (char *)0x0)) &&
     (((sVar5 = strlen(param_2), param_3 != (char *)0x0 && (sVar5 < 0x41)) &&
      (sVar5 = strlen(param_3), sVar5 < 0x41)))) {
    lVar7 = kmalloc_trace(_strnlen,0xdc0,0xc0);
    if (lVar7 != 0) {
      *(undefined4 *)(lVar7 + 0x94) = 0x42;
      uVar6 = strnlen(param_2,0x41);
      if (uVar6 == 0xffffffffffffffff) {
LAB_00100628:
                    /* WARNING: Subroutine does not return */
        fortify_panic("strnlen");
      }
      if (uVar6 != 0x41) {
        uVar6 = uVar6 + 1;
      }
      if (uVar6 < 0x42) {
        strscpy(lVar7,param_2);
        uVar6 = strnlen(param_3,0x41);
        if (uVar6 == 0xffffffffffffffff) goto LAB_00100628;
        if (uVar6 != 0x41) {
          uVar6 = uVar6 + 1;
        }
        if (uVar6 < 0x42) {
          strscpy(lVar7 + 0x41,param_3);
          lVar1 = param_1 + 0x2c0;
          *(undefined2 *)(lVar7 + 0xa6) = 1;
          mutex_lock(lVar1);
          plVar2 = (long *)(param_1 + 0x2a0);
          plVar8 = plVar2;
          do {
            plVar8 = (long *)*plVar8;
            if (plVar8 == plVar2) {
              lVar9 = *plVar2;
              lVar3 = lVar7 + 0xb0;
              uVar6 = __list_add_valid(lVar3,plVar2,lVar9);
              if ((uVar6 & 1) != 0) {
                *(long *)(lVar9 + 8) = lVar3;
                *(long *)(lVar7 + 0xb0) = lVar9;
                *(long **)(lVar7 + 0xb8) = plVar2;
                *plVar2 = lVar3;
              }
              mutex_unlock(lVar1);
              return lVar7;
            }
            iVar4 = strcmp((char *)((long)plVar8 + -0x6f),param_3);
          } while (iVar4 != 0);
          mutex_unlock(lVar1);
          kfree(lVar7);
          return -0x72;
        }
      }
                    /* WARNING: Subroutine does not return */
      fortify_panic("strscpy");
    }
    lVar7 = -0xc;
  }
  return lVar7;
}



//------------------------------------------------------------
// pdr_add_service_lookup @ 00100644 size=88
// signature: undefined pdr_add_service_lookup(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong pdr_add_service_lookup(long param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  
  uVar2 = pdr_lookup_common();
  uVar1 = _system_wq;
  if ((uVar2 != 0) && (uVar2 < 0xfffffffffffff001)) {
    *(undefined1 *)(uVar2 + 0xa7) = 1;
    queue_work_on(0x20,uVar1,param_1 + 0x358);
  }
  return uVar2;
}



//------------------------------------------------------------
// pdr_restart_pd @ 001006a0 size=572
// signature: undefined pdr_restart_pd(void)
// callers: []
//------------------------------------------------------------

int pdr_restart_pd(ulong param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  long *plVar4;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined4 local_90;
  undefined4 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined1 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  iVar2 = -0x16;
  local_38 = *(long *)(lVar1 + 0x638);
  local_88 = 0;
  local_40 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  local_a0 = 0;
  local_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  if ((((param_1 != 0) && (param_1 < 0xfffffffffffff001)) && (iVar2 = -0x16, param_2 != 0)) &&
     (param_2 < 0xfffffffffffff001)) {
    if (*(char *)(param_2 + 0xa7) == '\0') {
      mutex_lock(param_1 + 0x2c0);
      plVar4 = (long *)(param_1 + 0x2a0);
      do {
        plVar4 = (long *)*plVar4;
        if (plVar4 == (long *)(param_1 + 0x2a0)) goto LAB_001007d0;
      } while (plVar4 + -0x16 != (long *)param_2);
      if (*(char *)(param_2 + 0xa8) != '\0') {
        uVar3 = strnlen((char *)(param_2 + 0x41),0x41);
        if (0x41 < uVar3) {
                    /* WARNING: Subroutine does not return */
          fortify_panic("strnlen");
        }
        if (uVar3 != 0x41) {
          uVar3 = uVar3 + 1;
        }
        if (0x41 < uVar3) {
                    /* WARNING: Subroutine does not return */
          fortify_panic("strscpy");
        }
        strscpy(&local_80,(char *)(param_2 + 0x41));
        local_98 = *(undefined8 *)(param_2 + 0x84);
        local_90 = *(undefined4 *)(param_2 + 0x8c);
      }
LAB_001007d0:
      mutex_unlock(param_1 + 0x2c0);
      if ((char)local_80 != '\0') {
        iVar2 = qmi_txn_init(param_1 + 0x148,&local_e0,&servreg_restart_pd_resp_ei,&local_88);
        if (-1 < iVar2) {
          iVar2 = qmi_send_request(param_1 + 0x148,&local_98,&local_e0,0x24,0x43,
                                   servreg_restart_pd_req_ei,&local_80);
          if (iVar2 < 0) {
            qmi_txn_cancel(&local_e0);
          }
          else {
            iVar2 = qmi_txn_wait(&local_e0,0x4e2);
            if (iVar2 < 0) {
              _printk(&DAT_00102004,&local_80,iVar2);
            }
            else if (((local_88 & 0xffff) == 1) && (local_88._2_2_ == 0x45)) {
              _printk(&DAT_00102051,&local_80);
              iVar2 = -0x5f;
            }
            else if ((local_88 & 0xffff) == 0) {
              iVar2 = 0;
            }
            else {
              _printk(&DAT_00101fd5,&local_80);
              iVar2 = -0x79;
            }
          }
        }
        goto LAB_00100728;
      }
    }
    iVar2 = -0x16;
  }
LAB_00100728:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// pdr_handle_alloc @ 001008e0 size=512
// signature: undefined pdr_handle_alloc(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long pdr_handle_alloc(long param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  if (param_1 == 0) {
    lVar2 = -0x16;
  }
  else {
    lVar2 = kmalloc_trace(_qmi_send_request,0xdc0,0x408);
    if (lVar2 == 0) {
      lVar2 = -0xc;
    }
    else {
      *(long *)(lVar2 + 0x3f8) = param_1;
      *(undefined8 *)(lVar2 + 0x400) = param_2;
      __mutex_init(lVar2 + 0x2f0,"&pdr->status_lock",&pdr_handle_alloc___key);
      __mutex_init(lVar2 + 0x2c0,"&pdr->list_lock",&pdr_handle_alloc___key_4);
      __mutex_init(lVar2 + 800,"&pdr->lock",&pdr_handle_alloc___key_6);
      *(long *)(lVar2 + 0x2a0) = lVar2 + 0x2a0;
      *(long *)(lVar2 + 0x2a8) = lVar2 + 0x2a0;
      *(long *)(lVar2 + 0x2b0) = lVar2 + 0x2b0;
      *(long *)(lVar2 + 0x2b8) = lVar2 + 0x2b0;
      *(undefined8 *)(lVar2 + 0x358) = 0xfffffffe0;
      *(long *)(lVar2 + 0x360) = lVar2 + 0x360;
      *(long *)(lVar2 + 0x368) = lVar2 + 0x360;
      *(code **)(lVar2 + 0x370) = pdr_locator_work;
      *(undefined8 *)(lVar2 + 0x388) = 0xfffffffe0;
      *(long *)(lVar2 + 0x390) = lVar2 + 0x390;
      *(long *)(lVar2 + 0x398) = lVar2 + 0x390;
      *(code **)(lVar2 + 0x3a0) = pdr_notifier_work;
      *(undefined8 *)(lVar2 + 0x3b8) = 0xfffffffe0;
      *(long *)(lVar2 + 0x3c0) = lVar2 + 0x3c0;
      *(long *)(lVar2 + 0x3c8) = lVar2 + 0x3c0;
      *(code **)(lVar2 + 0x3d0) = pdr_indack_work;
      lVar3 = alloc_workqueue(&DAT_00101f6f,0xe000a,1,"pdr_notifier_wq");
      *(long *)(lVar2 + 1000) = lVar3;
      if (lVar3 == 0) {
        iVar1 = -0xc;
      }
      else {
        lVar3 = alloc_workqueue("pdr_indack_wq",0xa0012,1);
        *(long *)(lVar2 + 0x3f0) = lVar3;
        if (lVar3 == 0) {
          iVar1 = -0xc;
        }
        else {
          iVar1 = qmi_handle_init(lVar2,0x955,&pdr_locator_ops,0);
          if (-1 < iVar1) {
            iVar1 = qmi_add_lookup(lVar2,0x40,1,1);
            if ((-1 < iVar1) &&
               (iVar1 = qmi_handle_init(lVar2 + 0x148,0x4f,&pdr_notifier_ops,qmi_indication_handler)
               , -1 < iVar1)) {
              return lVar2;
            }
            qmi_handle_release(lVar2);
          }
          destroy_workqueue(*(undefined8 *)(lVar2 + 0x3f0));
        }
        destroy_workqueue(*(undefined8 *)(lVar2 + 1000));
      }
      kfree(lVar2);
      lVar2 = (long)iVar1;
    }
  }
  return lVar2;
}



//------------------------------------------------------------
// pdr_locator_work @ 00100ae4 size=984
// signature: undefined pdr_locator_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void pdr_locator_work(long param_1)

{
  char *__string;
  char cVar1;
  code *pcVar2;
  int iVar3;
  short *psVar4;
  ulong uVar5;
  size_t sVar6;
  uint uVar7;
  uint uVar8;
  long *plVar9;
  long lVar10;
  long lVar11;
  int iVar12;
  long *__string_00;
  long *plVar13;
  long *plVar14;
  char *__s2;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  lVar11 = sp_el0;
  lVar10 = param_1 + -0x38;
  local_70 = *(long *)(lVar11 + 0x638);
  mutex_lock(lVar10);
  cVar1 = *(char *)(param_1 + -8);
  mutex_unlock(lVar10);
  if (cVar1 != '\0') {
    mutex_lock();
    plVar9 = (long *)(param_1 + -0xb8);
    if ((long *)*plVar9 != plVar9) {
      lVar11 = param_1 + -0x358;
      plVar14 = (long *)*plVar9;
      do {
        plVar13 = (long *)*plVar14;
        if (*(char *)((long)plVar14 + -10) != '\0') {
          local_80 = 0;
          uStack_78 = 0;
          local_90 = 0;
          uStack_88 = 0;
          __string_00 = plVar14 + -0x16;
          local_a0 = 0;
          uStack_98 = 0;
          local_b0 = 0;
          uStack_a8 = 0;
          local_b8 = 0;
          psVar4 = (short *)kmalloc_trace(_qmi_txn_wait,0xdc0,0x994);
          if (psVar4 == (short *)0x0) {
            iVar3 = -0xc;
          }
          else {
            uVar5 = strnlen((char *)__string_00,0x41);
            if (0x41 < uVar5) {
LAB_00100ea0:
                    /* WARNING: Subroutine does not return */
              fortify_panic("strnlen");
            }
            if (uVar5 != 0x41) {
              uVar5 = uVar5 + 1;
            }
            if (0x41 < uVar5) {
                    /* WARNING: Subroutine does not return */
              fortify_panic("strscpy");
            }
            strscpy(&local_b8,__string_00);
            iVar12 = 0;
            __s2 = (char *)((long)plVar14 + -0x6f);
            uStack_78._0_2_ = CONCAT11(1,(undefined1)uStack_78);
            do {
              uStack_78 = CONCAT44(iVar12,(undefined4)uStack_78);
              local_c8 = 0;
              uStack_c0 = 0;
              local_d8 = 0;
              uStack_d0 = 0;
              local_e8 = 0;
              uStack_e0 = 0;
              local_f8 = 0;
              uStack_f0 = 0;
              local_100 = 0;
              iVar3 = qmi_txn_init(lVar11,&local_100,servreg_get_domain_list_resp_ei,psVar4);
              if (iVar3 < 0) goto LAB_00100ddc;
              mutex_lock(lVar10);
              iVar3 = qmi_send_request(lVar11,param_1 + -200,&local_100,0x21,0x4a,
                                       servreg_get_domain_list_req_ei,&local_b8);
              mutex_unlock(lVar10);
              if (iVar3 < 0) {
                qmi_txn_cancel(&local_100);
                kfree(psVar4);
                if (iVar3 < 0) goto LAB_00100e10;
LAB_00100da8:
                iVar3 = qmi_add_lookup(param_1 + -0x210,*(undefined4 *)((long)plVar14 + -0x1c),1,
                                       (int)plVar14[-4]);
                if (iVar3 < 0) {
                  pdr_notify_lookup_failure(lVar11,__string_00,iVar3);
                }
                else {
                  *(undefined1 *)((long)plVar14 + -10) = 0;
                }
                goto LAB_00100b70;
              }
              iVar3 = qmi_txn_wait(&local_100,0x4e2);
              if (iVar3 < 0) {
                _printk(&DAT_00101e68,&local_b8,iVar3);
LAB_00100ddc:
                kfree(psVar4);
                goto LAB_00100e10;
              }
              if (*psVar4 != 0) {
                _printk(&DAT_00101eec,&local_b8,psVar4[1]);
                iVar3 = -0x79;
                goto LAB_00100ddc;
              }
              uVar8 = *(uint *)(psVar4 + 8);
              if (uVar8 != 0) {
                uVar5 = 0;
                uVar7 = uVar8;
                do {
                  if ((int)uVar5 == 0x980) {
LAB_00100e9c:
                    /* WARNING: Does not return */
                    pcVar2 = (code *)SoftwareBreakpoint(1,0x100ea0);
                    (*pcVar2)();
                  }
                  __string = (char *)((long)psVar4 + uVar5 + 0x14);
                  sVar6 = strnlen(__string,0x41);
                  if (0x41 < sVar6) goto LAB_00100ea0;
                  if ((sVar6 != 0x41) && (iVar3 = strcmp(__string,__s2), iVar3 == 0)) {
                    if (((uVar5 - 0x940 < 0xfffffffffffff66b) ||
                        (((0x93f < uVar5 ||
                          (*(undefined1 *)(plVar14 + -3) =
                                *(undefined1 *)((long)psVar4 + uVar5 + 0x55),
                          uVar5 - 0x93d < 0xfffffffffffff66b)) || (0x93c < uVar5)))) ||
                       ((*(undefined4 *)((long)plVar14 + -0x14) =
                              *(undefined4 *)((long)psVar4 + uVar5 + 0x58),
                        uVar5 - 0x939 < 0xfffffffffffff66b || (0x938 < uVar5)))) goto LAB_00100e9c;
                    *(undefined4 *)(plVar14 + -4) = *(undefined4 *)((long)psVar4 + uVar5 + 0x5c);
                    if (*(char *)((long)plVar14 + -9) != '\0') {
                      scnprintf(__s2,0x41,"%s/%s",__s2,__string_00);
                    }
                    kfree(psVar4);
                    goto LAB_00100da8;
                  }
                  uVar5 = uVar5 + 0x4c;
                  uVar7 = uVar7 - 1;
                } while (uVar7 != 0);
              }
              uVar7 = (uint)(ushort)psVar4[3];
              if (uVar7 < uVar8) {
                *(uint *)(psVar4 + 8) = uVar7;
                uVar8 = uVar7;
              }
              iVar12 = uVar8 + iVar12;
            } while (iVar12 < (int)(uint)(ushort)psVar4[3]);
            kfree(psVar4);
            iVar3 = -6;
          }
LAB_00100e10:
          pdr_notify_lookup_failure(lVar11,__string_00,iVar3);
        }
LAB_00100b70:
        plVar14 = plVar13;
      } while (plVar13 != plVar9);
    }
    mutex_unlock(param_1 + -0x98);
  }
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// pdr_notifier_work @ 00100ec0 size=568
// signature: undefined pdr_notifier_work(void)
// callers: []
//------------------------------------------------------------

void pdr_notifier_work(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  undefined *puVar6;
  long *plVar7;
  long *plVar8;
  char *__string;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined4 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined2 local_78;
  long local_70;
  
  lVar1 = sp_el0;
  local_70 = *(long *)(lVar1 + 0x638);
  mutex_lock();
  plVar8 = (long *)(param_1 + -0xe8);
  plVar7 = (long *)*plVar8;
  if (plVar7 != plVar8) {
    do {
      if ((char)plVar7[-1] == '\0') {
        if (*(char *)((long)plVar7 + -0xb) != '\0') {
          *(undefined1 *)((long)plVar7 + -0xb) = 0;
          goto LAB_00100f40;
        }
      }
      else if (*(char *)((long)plVar7 + -0xc) != '\0') {
        *(undefined1 *)((long)plVar7 + -0xc) = 0;
        local_c0 = 0;
        local_d0 = 0;
        local_c8 = 0;
        local_78 = 0;
        local_88 = 0;
        uStack_80 = 0;
        local_98 = 0;
        uStack_90 = 0;
        local_a8 = 0;
        uStack_a0 = 0;
        local_b8 = 0;
        uStack_b0 = 0;
        local_e0 = 0;
        uStack_d8 = 0;
        local_f0 = 0;
        uStack_e8 = 0;
        local_100 = 0;
        uStack_f8 = 0;
        local_110 = 0;
        uStack_108 = 0;
        iVar3 = qmi_txn_init(param_1 + -0x240,&local_110,servreg_register_listener_resp_ei,&local_c8
                            );
        if (iVar3 < 0) {
LAB_00100f40:
          *(undefined4 *)(plVar7 + -2) = 0xfffffff;
        }
        else {
          __string = (char *)((long)plVar7 + -0x6f);
          local_b8 = CONCAT71(local_b8._1_7_,1);
          uVar5 = strnlen(__string,0x41);
          if (0x41 < uVar5) {
                    /* WARNING: Subroutine does not return */
            fortify_panic("strnlen");
          }
          if (uVar5 != 0x41) {
            uVar5 = uVar5 + 1;
          }
          if (0x41 < uVar5) {
                    /* WARNING: Subroutine does not return */
            fortify_panic("strscpy");
          }
          strscpy((ulong)&local_b8 | 1,__string);
          iVar3 = qmi_send_request(param_1 + -0x240,(long)plVar7 + -0x2c,&local_110,0x20,0x47,
                                   servreg_register_listener_req_ei,&local_b8);
          if (iVar3 < 0) {
            qmi_txn_cancel(&local_110);
            goto LAB_00100f40;
          }
          uVar4 = qmi_txn_wait(&local_110,0x4e2);
          if ((int)uVar4 < 0) {
            puVar6 = &DAT_00101f14;
LAB_00101090:
            _printk(puVar6,__string,uVar4);
            goto LAB_00100f40;
          }
          if ((short)local_c8 != 0) {
            uVar4 = (uint)local_c8._2_2_;
            puVar6 = &DAT_00101f45;
            goto LAB_00101090;
          }
          *(undefined4 *)(plVar7 + -2) = local_c0;
        }
        mutex_lock(param_1 + -0x98);
        if (*(int *)(*(code **)(param_1 + 0x70) + -4) != -0x25e72fda) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100f70);
          (*pcVar2)();
        }
        (**(code **)(param_1 + 0x70))
                  ((int)plVar7[-2],(long)plVar7 + -0x6f,*(undefined8 *)(param_1 + 0x78));
        mutex_unlock(param_1 + -0x98);
      }
      plVar7 = (long *)*plVar7;
    } while (plVar7 != plVar8);
  }
  mutex_unlock(param_1 + -200);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// pdr_indack_work @ 001010fc size=548
// signature: undefined pdr_indack_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void pdr_indack_work(long param_1)

{
  char *__string;
  long lVar1;
  long *plVar2;
  long *plVar3;
  undefined2 uVar4;
  code *pcVar5;
  int iVar6;
  ulong uVar7;
  long *plVar8;
  long *plVar9;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined4 local_c0 [2];
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined2 local_78;
  undefined2 local_76;
  long local_70;
  
  lVar1 = sp_el0;
  plVar9 = (long *)(param_1 + -0x108);
  local_70 = *(long *)(lVar1 + 0x638);
  if ((long *)*plVar9 != plVar9) {
    plVar8 = (long *)*plVar9;
    do {
      lVar1 = plVar8[-1];
      plVar2 = (long *)*plVar8;
      mutex_lock(param_1 + -200);
      *(int *)(lVar1 + 0xa0) = (int)plVar8[-2];
      mod_timer(plVar8 + 2,_jiffies + 0x8ca);
      __string = (char *)(lVar1 + 0x41);
      if (*(int *)(*(code **)(param_1 + 0x40) + -4) != -0x25e72fda) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1011a8);
        (*pcVar5)();
      }
      (**(code **)(param_1 + 0x40))
                (*(undefined4 *)(lVar1 + 0xa0),__string,*(undefined8 *)(param_1 + 0x48));
      del_timer_sync(plVar8 + 2);
      mutex_unlock(param_1 + -200);
      uVar4 = *(undefined2 *)((long)plVar8 + -0xc);
      local_c0[0] = 0;
      local_78 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_98 = 0;
      uStack_90 = 0;
      local_a8 = 0;
      uStack_a0 = 0;
      local_b8 = 0;
      uStack_b0 = 0;
      local_d0 = 0;
      uStack_c8 = 0;
      local_e0 = 0;
      uStack_d8 = 0;
      local_f0 = 0;
      uStack_e8 = 0;
      local_100 = 0;
      uStack_f8 = 0;
      local_108 = 0;
      iVar6 = qmi_txn_init(param_1 + -0x270,&local_108,servreg_set_ack_resp_ei,local_c0);
      if (-1 < iVar6) {
        local_76 = uVar4;
        uVar7 = strnlen(__string,0x41);
        if (0x41 < uVar7) {
                    /* WARNING: Subroutine does not return */
          fortify_panic("strnlen");
        }
        if (uVar7 != 0x41) {
          uVar7 = uVar7 + 1;
        }
        if (0x41 < uVar7) {
                    /* WARNING: Subroutine does not return */
          fortify_panic("strscpy");
        }
        strscpy(&local_b8,__string);
        qmi_send_request(param_1 + -0x270,lVar1 + 0x84,&local_108,0x23,0x48,servreg_set_ack_req_ei,
                         &local_b8);
        qmi_txn_cancel(&local_108);
      }
      _printk(&DAT_00101f72,__string,*(undefined4 *)(lVar1 + 0xa0),
              *(undefined2 *)((long)plVar8 + -0xc));
      mutex_lock(param_1 + -0xf8);
      uVar7 = __list_del_entry_valid(plVar8);
      if ((uVar7 & 1) != 0) {
        lVar1 = *plVar8;
        plVar3 = (long *)plVar8[1];
        *(long **)(lVar1 + 8) = plVar3;
        *plVar3 = lVar1;
      }
      *plVar8 = -0x2152ffffffffff00;
      plVar8[1] = -0x2152fffffffffede;
      mutex_unlock(param_1 + -0xf8);
      kfree(plVar8 + -2);
      plVar8 = plVar2;
    } while (plVar2 != plVar9);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// pdr_handle_release @ 00101324 size=248
// signature: undefined pdr_handle_release(void)
// callers: []
//------------------------------------------------------------

void pdr_handle_release(ulong param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  
  if ((param_1 != 0) && (param_1 < 0xfffffffffffff001)) {
    mutex_lock(param_1 + 0x2c0);
    plVar3 = *(long **)(param_1 + 0x2a0);
    while (plVar3 != (long *)(param_1 + 0x2a0)) {
      plVar5 = (long *)*plVar3;
      uVar4 = __list_del_entry_valid(plVar3);
      if ((uVar4 & 1) != 0) {
        lVar1 = *plVar3;
        plVar2 = (long *)plVar3[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar3 = -0x2152ffffffffff00;
      plVar3[1] = -0x2152fffffffffede;
      kfree(plVar3 + -0x16);
      plVar3 = plVar5;
    }
    mutex_unlock(param_1 + 0x2c0);
    cancel_work_sync(param_1 + 0x358);
    cancel_work_sync(param_1 + 0x388);
    cancel_work_sync(param_1 + 0x3b8);
    destroy_workqueue(*(undefined8 *)(param_1 + 1000));
    destroy_workqueue(*(undefined8 *)(param_1 + 0x3f0));
    qmi_handle_release(param_1);
    qmi_handle_release(param_1 + 0x148);
    kfree(param_1);
  }
  return;
}



//------------------------------------------------------------
// pdr_notify_lookup_failure @ 0010141c size=212
// signature: undefined pdr_notify_lookup_failure(void)
// callers: [pdr_locator_work]
//------------------------------------------------------------

void pdr_notify_lookup_failure(long param_1,long param_2,int param_3)

{
  long lVar1;
  long *plVar2;
  code *pcVar3;
  ulong uVar4;
  
  _printk(&DAT_00102079,param_2 + 0x41,param_2,param_3);
  if (param_3 != -6) {
    uVar4 = __list_del_entry_valid(param_2 + 0xb0);
    if ((uVar4 & 1) != 0) {
      lVar1 = *(long *)(param_2 + 0xb0);
      plVar2 = *(long **)(param_2 + 0xb8);
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *(undefined8 *)(param_2 + 0xb0) = 0xdead000000000100;
    *(undefined8 *)(param_2 + 0xb8) = 0xdead000000000122;
    *(undefined4 *)(param_2 + 0xa0) = 1;
    mutex_lock(param_1 + 0x2f0);
    if (*(int *)(*(code **)(param_1 + 0x3f8) + -4) != -0x25e72fda) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1014c8);
      (*pcVar3)();
    }
    (**(code **)(param_1 + 0x3f8))
              (*(undefined4 *)(param_2 + 0xa0),param_2 + 0x41,*(undefined8 *)(param_1 + 0x400));
    mutex_unlock(param_1 + 0x2f0);
    kfree(param_2);
  }
  return;
}



//------------------------------------------------------------
// pdr_locator_new_server @ 001014f4 size=124
// signature: undefined pdr_locator_new_server(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 pdr_locator_new_server(long param_1,long param_2)

{
  undefined4 uVar1;
  
  mutex_lock(param_1 + 800);
  *(undefined2 *)(param_1 + 0x290) = 0x2a;
  *(undefined4 *)(param_1 + 0x294) = *(undefined4 *)(param_2 + 0xc);
  uVar1 = *(undefined4 *)(param_2 + 0x10);
  *(undefined1 *)(param_1 + 0x350) = 1;
  *(undefined4 *)(param_1 + 0x298) = uVar1;
  mutex_unlock(param_1 + 800);
  queue_work_on(0x20,_system_wq,param_1 + 0x358);
  return 0;
}



//------------------------------------------------------------
// pdr_locator_del_server @ 00101574 size=68
// signature: undefined pdr_locator_del_server(void)
// callers: []
//------------------------------------------------------------

void pdr_locator_del_server(long param_1)

{
  mutex_lock(param_1 + 800);
  *(undefined1 *)(param_1 + 0x350) = 0;
  *(undefined8 *)(param_1 + 0x294) = 0;
  mutex_unlock(param_1 + 800);
  return;
}



//------------------------------------------------------------
// pdr_notifier_new_server @ 001015bc size=212
// signature: undefined pdr_notifier_new_server(void)
// callers: []
//------------------------------------------------------------

undefined8 pdr_notifier_new_server(long param_1,int *param_2)

{
  long *plVar1;
  
  mutex_lock(param_1 + 0x178);
  plVar1 = *(long **)(param_1 + 0x158);
  if (plVar1 != (long *)(param_1 + 0x158)) {
    do {
      if ((*(int *)((long)plVar1 + -0x1c) == *param_2) && ((int)plVar1[-4] == param_2[2])) {
        *(undefined1 *)(plVar1 + -1) = 1;
        *(undefined1 *)((long)plVar1 + -0xc) = 1;
        *(undefined2 *)((long)plVar1 + -0x2c) = 0x2a;
        *(int *)(plVar1 + -5) = param_2[3];
        *(int *)((long)plVar1 + -0x24) = param_2[4];
        queue_work_on(0x20,*(undefined8 *)(param_1 + 0x2a0),param_1 + 0x240);
      }
      plVar1 = (long *)*plVar1;
    } while (plVar1 != (long *)(param_1 + 0x158));
  }
  mutex_unlock(param_1 + 0x178);
  return 0;
}



//------------------------------------------------------------
// pdr_notifier_del_server @ 00101694 size=188
// signature: undefined pdr_notifier_del_server(void)
// callers: []
//------------------------------------------------------------

void pdr_notifier_del_server(long param_1,int *param_2)

{
  long *plVar1;
  
  mutex_lock(param_1 + 0x178);
  plVar1 = *(long **)(param_1 + 0x158);
  if (plVar1 != (long *)(param_1 + 0x158)) {
    do {
      if ((*(int *)((long)plVar1 + -0x1c) == *param_2) && ((int)plVar1[-4] == param_2[2])) {
        *(undefined1 *)(plVar1 + -1) = 0;
        *(undefined1 *)((long)plVar1 + -0xb) = 1;
        plVar1[-5] = 0;
        queue_work_on(0x20,*(undefined8 *)(param_1 + 0x2a0),param_1 + 0x240);
      }
      plVar1 = (long *)*plVar1;
    } while (plVar1 != (long *)(param_1 + 0x158));
  }
  mutex_unlock(param_1 + 0x178);
  return;
}



//------------------------------------------------------------
// pdr_indication_cb @ 00101754 size=376
// signature: undefined pdr_indication_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void pdr_indication_cb(long param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  long lVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  size_t sVar5;
  undefined4 *puVar6;
  ulong uVar7;
  char *__string;
  long *plVar8;
  
  if ((param_4 != (undefined4 *)0x0) && (__string = (char *)(param_4 + 1), *__string != '\0')) {
    sVar5 = strnlen(__string,0x41);
    if (0x41 < sVar5) {
                    /* WARNING: Subroutine does not return */
      fortify_panic("strnlen");
    }
    if (sVar5 == 0x41) {
                    /* WARNING: Subroutine does not return */
      fortify_panic("__fortify_strlen");
    }
    lVar1 = param_1 + 0x178;
    mutex_lock(lVar1);
    plVar8 = (long *)(param_1 + 0x158);
    do {
      plVar8 = (long *)*plVar8;
      if (plVar8 == (long *)(param_1 + 0x158)) {
        mutex_unlock(lVar1);
        return;
      }
      iVar4 = strcmp((char *)((long)plVar8 + -0x6f),__string);
    } while (iVar4 != 0);
    mutex_unlock(lVar1);
    if (plVar8 + -0x16 != (long *)0x0) {
      _printk(&DAT_00101ead,__string,*param_4,*(undefined2 *)((long)param_4 + 0x46));
      puVar6 = (undefined4 *)kmalloc_trace(_kfree,0xdc0,0x58);
      if (puVar6 != (undefined4 *)0x0) {
        uVar3 = *param_4;
        *(undefined2 *)(puVar6 + 1) = *(undefined2 *)((long)param_4 + 0x46);
        *puVar6 = uVar3;
        *(long **)(puVar6 + 2) = plVar8 + -0x16;
        init_timer_key(puVar6 + 8,ind_notif_timeout_handler,0,0,0);
        mutex_lock(lVar1);
        plVar8 = *(long **)(param_1 + 0x170);
        puVar2 = puVar6 + 4;
        uVar7 = __list_add_valid(puVar2,plVar8,param_1 + 0x168);
        if ((uVar7 & 1) != 0) {
          *(undefined4 **)(param_1 + 0x170) = puVar2;
          *(long *)(puVar6 + 4) = param_1 + 0x168;
          *(long **)(puVar6 + 6) = plVar8;
          *plVar8 = (long)puVar2;
        }
        mutex_unlock(lVar1);
        queue_work_on(0x20,*(undefined8 *)(param_1 + 0x2a8),param_1 + 0x270);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// ind_notif_timeout_handler @ 001018d0 size=80
// signature: undefined ind_notif_timeout_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ind_notif_timeout_handler(long param_1)

{
  code *pcVar1;
  
  if (_system_state - 7U < 0xfffffffd && qcom_device_shutdown_in_progress == '\0') {
                    /* WARNING: Subroutine does not return */
    panic("PDR: Indication notifier %s, state: 0x%x, trans-id: %d\n taking too long",
          *(long *)(param_1 + -0x18) + 0x41,*(undefined4 *)(*(long *)(param_1 + -0x18) + 0xa0),
          *(undefined2 *)(param_1 + -0x1c));
  }
  __warn_printk();
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10191c);
  (*pcVar1)();
}



//------------------------------------------------------------
// queue_work_on @ 00104008 size=1
// signature: undefined queue_work_on(void)
// callers: [pdr_locator_new_server, pdr_indication_cb, pdr_add_service_lookup, pdr_notifier_new_server, pdr_notifier_del_server, pdr_add_lookup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00104010 size=1
// signature: size_t strlen(char * __s)
// callers: [pdr_lookup_common]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00104020 size=1
// signature: undefined kmalloc_trace(void)
// callers: [pdr_indication_cb, pdr_locator_work, pdr_handle_alloc, pdr_lookup_common]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00104028 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [pdr_indication_cb, pdr_restart_pd, pdr_locator_work, pdr_notifier_work, pdr_lookup_common, pdr_indack_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00104030 size=1
// signature: undefined strscpy(void)
// callers: [pdr_restart_pd, pdr_locator_work, pdr_notifier_work, pdr_lookup_common, pdr_indack_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00104038 size=1
// signature: undefined mutex_lock(void)
// callers: [pdr_locator_new_server, pdr_notify_lookup_failure, pdr_indication_cb, pdr_handle_release, pdr_restart_pd, pdr_notifier_new_server, pdr_locator_work, pdr_notifier_work, pdr_notifier_del_server, pdr_locator_del_server, pdr_lookup_common, pdr_indack_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00104040 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [pdr_indication_cb, pdr_locator_work, pdr_lookup_common]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104048 size=1
// signature: undefined mutex_unlock(void)
// callers: [pdr_locator_new_server, pdr_notify_lookup_failure, pdr_indication_cb, pdr_handle_release, pdr_restart_pd, pdr_notifier_new_server, pdr_locator_work, pdr_notifier_work, pdr_notifier_del_server, pdr_locator_del_server, pdr_lookup_common, pdr_indack_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00104050 size=1
// signature: undefined kfree(void)
// callers: [pdr_notify_lookup_failure, pdr_handle_release, pdr_locator_work, pdr_handle_alloc, pdr_lookup_common, pdr_indack_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00104058 size=1
// signature: undefined __list_add_valid(void)
// callers: [pdr_indication_cb, pdr_lookup_common]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00104060 size=1
// signature: noreturn undefined fortify_panic(void)
// callers: [pdr_indication_cb, pdr_restart_pd, pdr_locator_work, pdr_notifier_work, pdr_lookup_common, pdr_indack_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_init @ 00104068 size=1
// signature: undefined qmi_txn_init(void)
// callers: [pdr_restart_pd, pdr_locator_work, pdr_notifier_work, pdr_indack_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_send_request @ 00104070 size=1
// signature: undefined qmi_send_request(void)
// callers: [pdr_restart_pd, pdr_locator_work, pdr_notifier_work, pdr_indack_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_send_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_wait @ 00104078 size=1
// signature: undefined qmi_txn_wait(void)
// callers: [pdr_restart_pd, pdr_locator_work, pdr_notifier_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_cancel @ 00104080 size=1
// signature: undefined qmi_txn_cancel(void)
// callers: [pdr_restart_pd, pdr_locator_work, pdr_notifier_work, pdr_indack_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_cancel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104088 size=1
// signature: undefined _printk(void)
// callers: [pdr_notify_lookup_failure, pdr_indication_cb, pdr_restart_pd, pdr_locator_work, pdr_notifier_work, pdr_indack_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104090 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [pdr_restart_pd, pdr_locator_work, pdr_notifier_work, pdr_indack_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00104098 size=1
// signature: undefined __mutex_init(void)
// callers: [pdr_handle_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 001040a0 size=1
// signature: undefined alloc_workqueue(void)
// callers: [pdr_handle_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_init @ 001040a8 size=1
// signature: undefined qmi_handle_init(void)
// callers: [pdr_handle_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_add_lookup @ 001040b0 size=1
// signature: undefined qmi_add_lookup(void)
// callers: [pdr_locator_work, pdr_handle_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_add_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_release @ 001040b8 size=1
// signature: undefined qmi_handle_release(void)
// callers: [pdr_handle_release, pdr_handle_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 001040c0 size=1
// signature: undefined destroy_workqueue(void)
// callers: [pdr_handle_release, pdr_handle_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 001040c8 size=1
// signature: undefined scnprintf(void)
// callers: [pdr_locator_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mod_timer @ 001040d8 size=1
// signature: undefined mod_timer(void)
// callers: [pdr_indack_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mod_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// del_timer_sync @ 001040e0 size=1
// signature: undefined del_timer_sync(void)
// callers: [pdr_indack_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void del_timer_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001040e8 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [pdr_notify_lookup_failure, pdr_handle_release, pdr_indack_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 001040f0 size=1
// signature: undefined cancel_work_sync(void)
// callers: [pdr_handle_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 001040f8 size=1
// signature: undefined init_timer_key(void)
// callers: [pdr_indication_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 00104110 size=1
// signature: undefined __warn_printk(void)
// callers: [ind_notif_timeout_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panic @ 00104118 size=1
// signature: noreturn undefined panic(void)
// callers: [ind_notif_timeout_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



