// Decompiled by Ghidra 12.2
// Program: cnss_plat_ipc_qmi_svc.ko
// Image base: 00100000

//------------------------------------------------------------
// cnss_plat_ipc_qmi_file_upload @ 001004d4 size=956
// signature: undefined cnss_plat_ipc_qmi_file_upload(void)
// callers: []
//------------------------------------------------------------

undefined4 cnss_plat_ipc_qmi_file_upload(int param_1,long param_2,long param_3,int param_4)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  undefined8 *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_60 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_88 = 0;
  if (param_1 < 2) {
    lVar1 = (long)param_1 + (long)param_1 * 4;
    if (lVar1 * 8 - 0x45U < 0xffffffffffffff5f) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x100890);
      (*pcVar3)();
    }
    uVar7 = 0xffffffea;
    if (((param_3 != 0) && (param_2 != 0)) && ((&DAT_0010247c)[(long)param_1 * 0x28] != '\0')) {
      lVar2 = sp_el0;
      if ((*(uint *)(lVar2 + 0x10) & 0xf0000) == 0) {
        pcVar6 = (char *)(lVar2 + 0x848);
        if ((*(uint *)(lVar2 + 0x10) & 0xff00) != 0) {
          pcVar6 = "soft_irq";
        }
      }
      else {
        pcVar6 = "irq";
      }
      cnss_plat_ipc_debug_log_print
                (cnss_plat_ipc_log_context,pcVar6,"cnss_plat_ipc_qmi_file_upload",&DAT_00102702,
                 "File name: %s Size: %d\n",param_2,param_4);
      if (0x7e < param_4 + 0xfdffffffU >> 0x19) {
        puVar5 = (undefined8 *)cnss_plat_ipc_init_file_data(param_2,param_3,param_4,param_4);
        if (puVar5 == (undefined8 *)0x0) {
          if ((*(uint *)(lVar2 + 0x10) & 0xf0000) == 0) {
            pcVar6 = (char *)(lVar2 + 0x848);
            if ((*(uint *)(lVar2 + 0x10) & 0xff00) != 0) {
              pcVar6 = "soft_irq";
            }
          }
          else {
            pcVar6 = "irq";
          }
          cnss_plat_ipc_debug_log_print
                    (cnss_plat_ipc_log_context,pcVar6,"cnss_plat_ipc_qmi_file_upload",&DAT_00102585,
                     "Unable to initialize file transfer data\n");
        }
        else {
          scnprintf(&local_88,0x20,&DAT_00102605,*puVar5);
          local_60 = *(undefined4 *)(puVar5 + 3);
          uStack_68 = CONCAT44(*(undefined4 *)(puVar5 + 2),(undefined4)uStack_68);
          iVar4 = qmi_send_indication(plat_ipc_qmi_svc,&DAT_00102470 + lVar1 * 4,4,0x31,
                                      cnss_plat_ipc_qmi_file_upload_ind_msg_v01_ei,&local_88);
          if (iVar4 < 0) {
            if ((*(uint *)(lVar2 + 0x10) & 0xf0000) == 0) {
              pcVar6 = (char *)(lVar2 + 0x848);
              if ((*(uint *)(lVar2 + 0x10) & 0xff00) != 0) {
                pcVar6 = "soft_irq";
              }
            }
            else {
              pcVar6 = "irq";
            }
            cnss_plat_ipc_debug_log_print
                      (cnss_plat_ipc_log_context,pcVar6,"cnss_plat_ipc_qmi_file_upload",
                       &DAT_00102585,"QMI failed: %d\n");
          }
          else {
            iVar4 = wait_for_completion_timeout(puVar5 + 5,0x9c4);
            if (iVar4 == 0) {
              if ((*(uint *)(lVar2 + 0x10) & 0xf0000) == 0) {
                pcVar6 = (char *)(lVar2 + 0x848);
                if ((*(uint *)(lVar2 + 0x10) & 0xff00) != 0) {
                  pcVar6 = "soft_irq";
                }
              }
              else {
                pcVar6 = "irq";
              }
              cnss_plat_ipc_debug_log_print
                        (cnss_plat_ipc_log_context,pcVar6,"cnss_plat_ipc_qmi_file_upload",
                         &DAT_00102585,"Timeout Uploading file: %s\n",*puVar5);
            }
          }
          mutex_lock(&DAT_00102440);
          idr_remove(&DAT_00102428,*(undefined4 *)(puVar5 + 2));
          mutex_unlock(&DAT_00102440);
          uVar7 = 0xffffffea;
          if (*(int *)((long)puVar5 + 0x24) != 0) {
            uVar7 = 0;
          }
          kfree(puVar5);
          if ((*(uint *)(lVar2 + 0x10) & 0xf0000) == 0) {
            pcVar6 = (char *)(lVar2 + 0x848);
            if ((*(uint *)(lVar2 + 0x10) & 0xff00) != 0) {
              pcVar6 = "soft_irq";
            }
          }
          else {
            pcVar6 = "irq";
          }
          cnss_plat_ipc_debug_log_print
                    (cnss_plat_ipc_log_context,pcVar6,"cnss_plat_ipc_qmi_file_upload",&DAT_00102953,
                     "Status: %d\n",uVar7);
        }
      }
    }
  }
  else {
    lVar1 = sp_el0;
    if ((*(uint *)(lVar1 + 0x10) & 0xf0000) == 0) {
      pcVar6 = (char *)(lVar1 + 0x848);
      if ((*(uint *)(lVar1 + 0x10) & 0xff00) != 0) {
        pcVar6 = "soft_irq";
      }
    }
    else {
      pcVar6 = "irq";
    }
    cnss_plat_ipc_debug_log_print
              (cnss_plat_ipc_log_context,pcVar6,"cnss_plat_ipc_qmi_file_upload",&DAT_00102585,
               "Invalid Client ID: %d\n");
    uVar7 = 0xffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// cnss_plat_ipc_debug_log_print @ 00100890 size=192
// signature: undefined cnss_plat_ipc_debug_log_print(void)
// callers: [cnss_plat_ipc_qmi_reg_client_req_handler, cnss_plat_ipc_qmi_disconnect_cb, cnss_plat_ipc_unregister, cnss_plat_ipc_init_fn, cnss_plat_ipc_qmi_file_download_req_handler, cnss_plat_ipc_qmi_file_download, cnss_plat_ipc_register, cnss_plat_ipc_qmi_file_upload, cnss_plat_ipc_qmi_file_upload_req_handler, cnss_plat_ipc_qmi_init_setup_req_handler]
//------------------------------------------------------------

void cnss_plat_ipc_debug_log_print
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4,
               undefined8 param_5)

{
  long lVar1;
  undefined1 auStack_e8 [128];
  undefined8 local_48;
  undefined1 *puStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  puStack_40 = auStack_e8 + 0x80;
  local_48 = param_5;
  if (param_4 != 0) {
    _printk("%scnss_plat: %pV",param_4,&local_48);
  }
  ipc_log_string(param_1,"[%s] %s: %pV",param_2,param_3,&local_48);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// cnss_plat_ipc_init_file_data @ 00100950 size=244
// signature: undefined cnss_plat_ipc_init_file_data(void)
// callers: [cnss_plat_ipc_qmi_file_download, cnss_plat_ipc_qmi_file_upload]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
cnss_plat_ipc_init_file_data(undefined8 param_1,undefined8 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  
  puVar2 = (undefined8 *)kmalloc_trace(_ipc_log_context_create,0xcc0,0x48);
  if (puVar2 != (undefined8 *)0x0) {
    *puVar2 = param_1;
    puVar2[1] = param_2;
    *(undefined4 *)((long)puVar2 + 0x14) = param_3;
    *(uint *)(puVar2 + 3) = param_4;
    *(undefined4 *)((long)puVar2 + 0x1c) = 0;
    *(undefined4 *)((long)puVar2 + 0x24) = 0;
    if (param_4 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = param_4 / 0xf000;
      if (param_4 % 0xf000 != 0) {
        uVar3 = param_4 / 0xf000 + 1;
      }
    }
    *(uint *)(puVar2 + 4) = uVar3;
    *(undefined4 *)(puVar2 + 5) = 0;
    __init_swait_queue_head(puVar2 + 6,"&x->wait",&init_completion___key);
    mutex_lock(&DAT_00102440);
    uVar1 = idr_alloc_cyclic(&DAT_00102428,puVar2,0,0xffffffff,0xcc0);
    *(undefined4 *)(puVar2 + 2) = uVar1;
    mutex_unlock(&DAT_00102440);
  }
  return puVar2;
}



//------------------------------------------------------------
// cnss_plat_ipc_qmi_file_download @ 00100a48 size=856
// signature: undefined cnss_plat_ipc_qmi_file_download(void)
// callers: []
//------------------------------------------------------------

undefined4
cnss_plat_ipc_qmi_file_download(int param_1,long param_2,long param_3,undefined4 *param_4)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 *puVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_70 = 0;
  if (param_1 < 2) {
    lVar1 = (long)param_1 + (long)param_1 * 4;
    if (lVar1 * 8 - 0x45U < 0xffffffffffffff5f) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x100da0);
      (*pcVar2)();
    }
    uVar6 = 0xffffffea;
    if (((param_3 != 0) && (param_2 != 0)) && ((&DAT_0010247c)[(long)param_1 * 0x28] != '\0')) {
      puVar4 = (undefined8 *)cnss_plat_ipc_init_file_data(param_2,param_3,*param_4,0);
      if (puVar4 == (undefined8 *)0x0) {
        lVar1 = sp_el0;
        if ((*(uint *)(lVar1 + 0x10) & 0xf0000) == 0) {
          pcVar5 = (char *)(lVar1 + 0x848);
          if ((*(uint *)(lVar1 + 0x10) & 0xff00) != 0) {
            pcVar5 = "soft_irq";
          }
        }
        else {
          pcVar5 = "irq";
        }
        cnss_plat_ipc_debug_log_print
                  (cnss_plat_ipc_log_context,pcVar5,"cnss_plat_ipc_qmi_file_download",&DAT_00102585,
                   "Unable to initialize file transfer data\n");
      }
      else {
        scnprintf(&local_70,0x20,&DAT_00102605,param_2);
        uStack_50 = CONCAT44(*(undefined4 *)(puVar4 + 2),(undefined4)uStack_50);
        iVar3 = qmi_send_indication(plat_ipc_qmi_svc,&DAT_00102470 + lVar1 * 4,2,0x2a,
                                    cnss_plat_ipc_qmi_file_download_ind_msg_v01_ei,&local_70);
        if (iVar3 < 0) {
          lVar1 = sp_el0;
          if ((*(uint *)(lVar1 + 0x10) & 0xf0000) == 0) {
            pcVar5 = (char *)(lVar1 + 0x848);
            if ((*(uint *)(lVar1 + 0x10) & 0xff00) != 0) {
              pcVar5 = "soft_irq";
            }
          }
          else {
            pcVar5 = "irq";
          }
          cnss_plat_ipc_debug_log_print
                    (cnss_plat_ipc_log_context,pcVar5,"cnss_plat_ipc_qmi_file_download",
                     &DAT_00102585,"QMI failed: %d\n");
        }
        else {
          iVar3 = wait_for_completion_timeout(puVar4 + 5,0x9c4);
          if (iVar3 == 0) {
            lVar1 = sp_el0;
            if ((*(uint *)(lVar1 + 0x10) & 0xf0000) == 0) {
              pcVar5 = (char *)(lVar1 + 0x848);
              if ((*(uint *)(lVar1 + 0x10) & 0xff00) != 0) {
                pcVar5 = "soft_irq";
              }
            }
            else {
              pcVar5 = "irq";
            }
            cnss_plat_ipc_debug_log_print
                      (cnss_plat_ipc_log_context,pcVar5,"cnss_plat_ipc_qmi_file_download",
                       &DAT_00102585,"Timeout downloading file:%s\n",*puVar4);
          }
        }
        *param_4 = *(undefined4 *)(puVar4 + 3);
        mutex_lock(&DAT_00102440);
        idr_remove(&DAT_00102428,*(undefined4 *)(puVar4 + 2));
        mutex_unlock(&DAT_00102440);
        uVar6 = 0xffffffea;
        if (*(int *)((long)puVar4 + 0x24) != 0) {
          uVar6 = 0;
        }
        kfree(puVar4);
        lVar1 = sp_el0;
        if ((*(uint *)(lVar1 + 0x10) & 0xf0000) == 0) {
          pcVar5 = (char *)(lVar1 + 0x848);
          if ((*(uint *)(lVar1 + 0x10) & 0xff00) != 0) {
            pcVar5 = "soft_irq";
          }
        }
        else {
          pcVar5 = "irq";
        }
        cnss_plat_ipc_debug_log_print
                  (cnss_plat_ipc_log_context,pcVar5,"cnss_plat_ipc_qmi_file_download",&DAT_00102953,
                   "Status: %d Size: %d\n",uVar6,*param_4);
      }
    }
  }
  else {
    lVar1 = sp_el0;
    if ((*(uint *)(lVar1 + 0x10) & 0xf0000) == 0) {
      pcVar5 = (char *)(lVar1 + 0x848);
      if ((*(uint *)(lVar1 + 0x10) & 0xff00) != 0) {
        pcVar5 = "soft_irq";
      }
    }
    else {
      pcVar5 = "irq";
    }
    cnss_plat_ipc_debug_log_print
              (cnss_plat_ipc_log_context,pcVar5,"cnss_plat_ipc_qmi_file_download",&DAT_00102585,
               "Invalid Client ID: %d\n");
    uVar6 = 0xffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// cnss_plat_ipc_qmi_daemon_config @ 00100da4 size=112
// signature: undefined cnss_plat_ipc_qmi_daemon_config(void)
// callers: []
//------------------------------------------------------------

undefined1 * cnss_plat_ipc_qmi_daemon_config(void)

{
  undefined1 *puVar1;
  uint uVar2;
  
  if (DAT_001024a4 == '\0') {
    puVar1 = (undefined1 *)0x0;
  }
  else {
    puVar1 = &daemon_cfg;
    if (daemon_cfg != '\x01') {
      uVar2 = 0;
      do {
        msleep(0x32);
        if (0xc6 < uVar2) {
          return puVar1;
        }
        uVar2 = uVar2 + 1;
      } while (daemon_cfg != '\x01');
    }
  }
  return puVar1;
}



//------------------------------------------------------------
// cnss_plat_ipc_register @ 00100e18 size=364
// signature: undefined cnss_plat_ipc_register(void)
// callers: []
//------------------------------------------------------------

undefined8 cnss_plat_ipc_register(int param_1,undefined8 param_2,undefined8 param_3)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  code *pcVar4;
  char *pcVar5;
  
  if (1 < param_1) {
    lVar3 = sp_el0;
    if ((*(uint *)(lVar3 + 0x10) & 0xf0000) == 0) {
      pcVar5 = (char *)(lVar3 + 0x848);
      if ((*(uint *)(lVar3 + 0x10) & 0xff00) != 0) {
        pcVar5 = "soft_irq";
      }
    }
    else {
      pcVar5 = "irq";
    }
    cnss_plat_ipc_debug_log_print
              (cnss_plat_ipc_log_context,pcVar5,"cnss_plat_ipc_register",&DAT_00102585,
               "Invalid Client ID: %d\n");
    return 0xffffffea;
  }
  uVar1 = (long)param_1 * 0x28 + 0x70;
  if (uVar1 < 0xa1) {
    iVar2 = (&DAT_00102490)[(long)param_1 * 10];
    if (0 < iVar2) {
      lVar3 = sp_el0;
      if ((*(uint *)(lVar3 + 0x10) & 0xf0000) == 0) {
        pcVar5 = (char *)(lVar3 + 0x848);
        if ((*(uint *)(lVar3 + 0x10) & 0xff00) != 0) {
          pcVar5 = "soft_irq";
        }
      }
      else {
        pcVar5 = "irq";
      }
      cnss_plat_ipc_debug_log_print
                (cnss_plat_ipc_log_context,pcVar5,"cnss_plat_ipc_register",&DAT_00102585,
                 "Max Service users reached\n");
      return 0xffffffea;
    }
    if (iVar2 != 0) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x100f84);
      (*pcVar4)();
    }
    if (((0xffffffffffffff5e < (long)param_1 * 0x28 - 0x41U) &&
        ((&DAT_00102480)[(long)param_1 * 5] = param_2,
        0xffffffffffffff5e < (long)param_1 * 0x28 - 0x39U)) &&
       ((&DAT_00102488)[(long)param_1 * 5] = param_3, uVar1 < 0xa1)) {
      (&DAT_00102490)[(long)param_1 * 10] = 1;
      return 0;
    }
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(1,0x100f80);
  (*pcVar4)();
}



//------------------------------------------------------------
// cnss_plat_ipc_unregister @ 00100f88 size=260
// signature: undefined cnss_plat_ipc_unregister(void)
// callers: []
//------------------------------------------------------------

void cnss_plat_ipc_unregister(int param_1,long param_2)

{
  ulong uVar1;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  char *pcVar5;
  
  if (param_1 < 2) {
    uVar1 = (long)param_1 * 0x28 + 0x70;
    if (0xa0 < uVar1) {
LAB_00101088:
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(1,0x10108c);
      (*pcVar4)();
    }
    uVar2 = (&DAT_00102490)[(long)param_1 * 10];
    if (uVar2 != 0) {
      if ((long)param_1 * 0x28 - 0x39U < 0xffffffffffffff5f) goto LAB_00101088;
      if ((&DAT_00102488)[(long)param_1 * 5] == param_2) {
        (&DAT_00102480)[(long)param_1 * 5] = 0;
        (&DAT_00102488)[(long)param_1 * 5] = 0;
        if (0xa0 < uVar1) goto LAB_00101088;
        (&DAT_00102490)[(long)param_1 * 10] = uVar2 - 1;
      }
      else if (1 < uVar2) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x101028);
        (*pcVar4)();
      }
    }
  }
  else {
    lVar3 = sp_el0;
    if ((*(uint *)(lVar3 + 0x10) & 0xf0000) == 0) {
      pcVar5 = (char *)(lVar3 + 0x848);
      if ((*(uint *)(lVar3 + 0x10) & 0xff00) != 0) {
        pcVar5 = "soft_irq";
      }
    }
    else {
      pcVar5 = "irq";
    }
    cnss_plat_ipc_debug_log_print
              (cnss_plat_ipc_log_context,pcVar5,"cnss_plat_ipc_unregister",&DAT_00102585,
               "Invalid Client ID: %d\n");
  }
  return;
}



//------------------------------------------------------------
// cnss_plat_ipc_init_fn @ 00101090 size=524
// signature: undefined cnss_plat_ipc_init_fn(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cnss_plat_ipc_init_fn(void)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  plat_ipc_qmi_svc = kmalloc_trace(_queue_work_on,0xdc0,0x148);
  if (plat_ipc_qmi_svc != 0) {
    iVar3 = qmi_handle_init(plat_ipc_qmi_svc,0xffff,cnss_plat_ipc_qmi_ops,
                            cnss_plat_ipc_qmi_req_handlers);
    if (iVar3 < 0) {
      iVar3 = 0xf0;
      do {
        msleep(0xfa);
        iVar4 = qmi_handle_init(plat_ipc_qmi_svc,0xffff,cnss_plat_ipc_qmi_ops,
                                cnss_plat_ipc_qmi_req_handlers);
        if (-1 < iVar4) goto LAB_001010e0;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      lVar2 = sp_el0;
      if ((*(uint *)(lVar2 + 0x10) & 0xf0000) == 0) {
        pcVar5 = (char *)(lVar2 + 0x848);
        if ((*(uint *)(lVar2 + 0x10) & 0xff00) != 0) {
          pcVar5 = "soft_irq";
        }
      }
      else {
        pcVar5 = "irq";
      }
      cnss_plat_ipc_debug_log_print
                (cnss_plat_ipc_log_context,pcVar5,"cnss_plat_ipc_init_fn",&DAT_00102585,
                 "Failed to init QMI handle after %d ms * %d, err = %d\n",0xfa,0xf0,iVar4);
    }
    else {
LAB_001010e0:
      iVar3 = qmi_add_server(plat_ipc_qmi_svc,0x42e,1,0);
      lVar2 = sp_el0;
      uVar1 = *(uint *)(lVar2 + 0x10) & 0xf0000;
      if (-1 < iVar3) {
        if (uVar1 == 0) {
          pcVar5 = (char *)(lVar2 + 0x848);
          if ((*(uint *)(lVar2 + 0x10) & 0xff00) != 0) {
            pcVar5 = "soft_irq";
          }
        }
        else {
          pcVar5 = "irq";
        }
        cnss_plat_ipc_debug_log_print
                  (cnss_plat_ipc_log_context,pcVar5,"cnss_plat_ipc_init_fn",&DAT_00102702,
                   "CNSS Platform IPC QMI Service is started\n");
        DAT_00102428 = 0x1000000400000000;
        DAT_00102430 = 0;
        DAT_00102438 = 0;
        __mutex_init(&DAT_00102440,"&svc->file_idr_lock",&cnss_plat_ipc_init_fn___key);
        return;
      }
      if (uVar1 == 0) {
        pcVar5 = (char *)(lVar2 + 0x848);
        if ((*(uint *)(lVar2 + 0x10) & 0xff00) != 0) {
          pcVar5 = "soft_irq";
        }
      }
      else {
        pcVar5 = "irq";
      }
      cnss_plat_ipc_debug_log_print
                (cnss_plat_ipc_log_context,pcVar5,"cnss_plat_ipc_init_fn",&DAT_00102585,
                 "Server add fail: %d\n",iVar3);
      qmi_handle_release(plat_ipc_qmi_svc);
    }
    kfree(plat_ipc_qmi_svc);
  }
  return;
}



//------------------------------------------------------------
// cnss_plat_ipc_qmi_bye_cb @ 001012a0 size=80
// signature: undefined cnss_plat_ipc_qmi_bye_cb(void)
// callers: []
//------------------------------------------------------------

void cnss_plat_ipc_qmi_bye_cb(undefined8 param_1,ulong param_2)

{
  cnss_plat_ipc_qmi_disconnect_cb(param_1,param_2,DAT_00102474._4_4_);
  cnss_plat_ipc_qmi_disconnect_cb(param_1,param_2 & 0xffffffff,DAT_001024a0);
  return;
}



//------------------------------------------------------------
// cnss_plat_ipc_qmi_disconnect_cb @ 001012f4 size=568
// signature: undefined cnss_plat_ipc_qmi_disconnect_cb(void)
// callers: [cnss_plat_ipc_qmi_bye_cb]
//------------------------------------------------------------

void cnss_plat_ipc_qmi_disconnect_cb(long param_1,int param_2,int param_3)

{
  long lVar1;
  long lVar2;
  char *pcVar3;
  uint uVar4;
  code *pcVar5;
  int *piVar6;
  long lVar7;
  int local_6c;
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  local_6c = 0;
  if (plat_ipc_qmi_svc == param_1) {
    lVar7 = 0;
    lVar1 = sp_el0;
    do {
      lVar2 = lVar7 * 0x28;
      if ((&DAT_0010247c)[lVar2] != '\0') {
        piVar6 = (int *)(&DAT_00102474 + lVar7 * 5);
        if ((*piVar6 == param_2) && (*(int *)((long)&DAT_00102474 + lVar2 + 4) == param_3)) {
          pcVar3 = "irq";
          if (((*(uint *)(lVar1 + 0x10) & 0xf0000) == 0) &&
             (pcVar3 = (char *)(lVar1 + 0x848), (*(uint *)(lVar1 + 0x10) & 0xff00) != 0)) {
            pcVar3 = "soft_irq";
          }
          cnss_plat_ipc_debug_log_print
                    (cnss_plat_ipc_log_context,pcVar3,"cnss_plat_ipc_qmi_disconnect_cb",
                     &DAT_00102585,"%s: QMI client disconnect. QMI Socket Node:%d Port:%d ID: %d\n",
                     "cnss_plat_ipc_qmi_disconnect_cb",param_2,param_3,(int)lVar7);
          (&DAT_00102470)[lVar7 * 0x14] = 0;
          piVar6[0] = 0;
          piVar6[1] = 0;
          (&DAT_0010247c)[lVar2] = 0;
          mutex_lock(&DAT_00102440);
          local_6c = 0;
          while (lVar2 = idr_get_next(&DAT_00102428,&local_6c), lVar2 != 0) {
            complete(lVar2 + 0x28);
            local_6c = local_6c + 1;
          }
          mutex_unlock(&DAT_00102440);
          uVar4 = (&DAT_00102490)[lVar7 * 10];
          if (uVar4 != 0) {
            pcVar5 = (code *)(&DAT_00102480)[lVar7 * 5];
            if (pcVar5 != (code *)0x0) {
              if (*(int *)(pcVar5 + -4) != -0x722f0ed1) {
                    /* WARNING: Does not return */
                pcVar5 = (code *)SoftwareBreakpoint(0x8229,0x1014ac);
                (*pcVar5)();
              }
              (*pcVar5)((&DAT_00102488)[lVar7 * 5],(&DAT_0010247c)[lVar7 * 0x28]);
              uVar4 = (&DAT_00102490)[lVar7 * 10];
            }
            if (1 < uVar4) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x101528);
              (*pcVar5)();
            }
          }
        }
      }
      lVar7 = lVar7 + 1;
    } while (lVar7 != 2);
  }
  else {
    lVar7 = sp_el0;
    if ((*(uint *)(lVar7 + 0x10) & 0xf0000) == 0) {
      pcVar3 = (char *)(lVar7 + 0x848);
      if ((*(uint *)(lVar7 + 0x10) & 0xff00) != 0) {
        pcVar3 = "soft_irq";
      }
    }
    else {
      pcVar3 = "irq";
    }
    cnss_plat_ipc_debug_log_print
              (cnss_plat_ipc_log_context,pcVar3,"cnss_plat_ipc_qmi_disconnect_cb",&DAT_00102585,
               "Invalid QMI Handle\n");
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// cnss_plat_ipc_qmi_reg_client_req_handler @ 00101530 size=800
// signature: undefined cnss_plat_ipc_qmi_reg_client_req_handler(void)
// callers: []
//------------------------------------------------------------

void cnss_plat_ipc_qmi_reg_client_req_handler
               (undefined8 param_1,undefined8 *param_2,undefined8 param_3,char *param_4)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  long lVar4;
  code *pcVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined4 local_50 [2];
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50[0] = 0;
  if (*param_4 == '\0') {
LAB_0010178c:
    iVar1 = qmi_send_response(plat_ipc_qmi_svc,param_2,param_3,6,7,
                              cnss_plat_ipc_qmi_reg_client_resp_msg_v01_ei,local_50);
    if (iVar1 < 0) {
      lVar3 = sp_el0;
      if ((*(uint *)(lVar3 + 0x10) & 0xf0000) == 0) {
        pcVar2 = (char *)(lVar3 + 0x848);
        if ((*(uint *)(lVar3 + 0x10) & 0xff00) != 0) {
          pcVar2 = "soft_irq";
        }
      }
      else {
        pcVar2 = "irq";
      }
      cnss_plat_ipc_debug_log_print
                (cnss_plat_ipc_log_context,pcVar2,"cnss_plat_ipc_qmi_reg_client_req_handler",
                 &DAT_00102585,"QMI failed: %d\n");
    }
  }
  else {
    iVar1 = *(int *)(param_4 + 4);
    if (iVar1 < 2) {
      if ((long)iVar1 * 0x28 - 0x45U < 0xffffffffffffff5f) goto LAB_00101848;
      if ((&DAT_0010247c)[(long)iVar1 * 0x28] == '\0') {
        lVar3 = sp_el0;
        if ((*(uint *)(lVar3 + 0x10) & 0xf0000) == 0) {
          pcVar2 = (char *)(lVar3 + 0x848);
          if ((*(uint *)(lVar3 + 0x10) & 0xff00) != 0) {
            pcVar2 = "soft_irq";
          }
        }
        else {
          pcVar2 = "irq";
        }
        cnss_plat_ipc_debug_log_print
                  (cnss_plat_ipc_log_context,pcVar2,"cnss_plat_ipc_qmi_reg_client_req_handler",
                   &DAT_00102702,"%s: QMI Client Connected. QMI Socket Node: %d Port: %d ID: %d\n",
                   "cnss_plat_ipc_qmi_reg_client_req_handler",*(undefined4 *)((long)param_2 + 4),
                   *(undefined4 *)(param_2 + 1),iVar1);
        iVar1 = *(int *)(param_4 + 4);
        uVar7 = *param_2;
        *(undefined4 *)((long)&DAT_00102474 + (long)iVar1 * 0x28 + 4) = *(undefined4 *)(param_2 + 1)
        ;
        *(undefined8 *)(&DAT_00102470 + (long)iVar1 * 0x14) = uVar7;
        if ((long)*(int *)(param_4 + 4) * 0x28 - 0x45U < 0xffffffffffffff5f) {
LAB_00101848:
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(1,0x10184c);
          (*pcVar5)();
        }
        (&DAT_0010247c)[(long)*(int *)(param_4 + 4) * 0x28] = 1;
        iVar1 = *(int *)(param_4 + 4);
        lVar3 = (long)iVar1;
        lVar4 = lVar3 * 0x28;
        if ((lVar4 - 0x31U < 0xffffffffffffff5f) || (0xa0 < lVar4 + 0x70U)) goto LAB_00101848;
        uVar6 = (&DAT_00102490)[lVar3 * 10];
        if (uVar6 != 0) {
          if ((lVar4 - 0x41U < 0xffffffffffffff5f) ||
             ((long)iVar1 * 0x28 - 0x41U < 0xffffffffffffff5f)) goto LAB_00101848;
          pcVar5 = (code *)(&DAT_00102480)[(long)iVar1 * 5];
          if (pcVar5 != (code *)0x0) {
            if (((lVar4 - 0x45U < 0xffffffffffffff5f) || (lVar3 * 0x28 - 0x39U < 0xffffffffffffff5f)
                ) || ((long)iVar1 * 0x28 - 0x45U < 0xffffffffffffff5f)) goto LAB_00101848;
            if (*(int *)(pcVar5 + -4) != -0x722f0ed1) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x822a,0x101774);
              (*pcVar5)();
            }
            (*pcVar5)((&DAT_00102488)[(long)iVar1 * 5],(&DAT_0010247c)[lVar3 * 0x28]);
            if (0xa0 < lVar4 + 0x70U) goto LAB_00101848;
            uVar6 = (&DAT_00102490)[lVar3 * 10];
          }
          if (1 < uVar6) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x101850);
            (*pcVar5)();
          }
        }
        goto LAB_0010178c;
      }
    }
    lVar3 = sp_el0;
    if ((*(uint *)(lVar3 + 0x10) & 0xf0000) == 0) {
      pcVar2 = (char *)(lVar3 + 0x848);
      if ((*(uint *)(lVar3 + 0x10) & 0xff00) != 0) {
        pcVar2 = "soft_irq";
      }
    }
    else {
      pcVar2 = "irq";
    }
    cnss_plat_ipc_debug_log_print
              (cnss_plat_ipc_log_context,pcVar2,"cnss_plat_ipc_qmi_reg_client_req_handler",
               &DAT_00102585,"QMI client already connected or Invalid client id\n");
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// cnss_plat_ipc_qmi_init_setup_req_handler @ 00101854 size=380
// signature: undefined cnss_plat_ipc_qmi_init_setup_req_handler(void)
// callers: []
//------------------------------------------------------------

void cnss_plat_ipc_qmi_init_setup_req_handler
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 *param_4)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  lVar1 = sp_el0;
  local_58 = 0;
  uStack_50 = 0;
  if ((*(uint *)(lVar1 + 0x10) & 0xf0000) == 0) {
    pcVar3 = (char *)(lVar1 + 0x848);
    if ((*(uint *)(lVar1 + 0x10) & 0xff00) != 0) {
      pcVar3 = "soft_irq";
    }
  }
  else {
    pcVar3 = "irq";
  }
  cnss_plat_ipc_debug_log_print
            (cnss_plat_ipc_log_context,pcVar3,"cnss_plat_ipc_qmi_init_setup_req_handler",
             &DAT_00102953,"MAC: %d HW_TRC: %d CAL: %d\n",*param_4,param_4[1],
             *(undefined4 *)(param_4 + 4));
  DAT_001024c9 = *param_4;
  DAT_001024cc = *(undefined4 *)(param_4 + 4);
  DAT_001024ca = param_4[1];
  daemon_cfg = 1;
  iVar2 = qmi_send_response(plat_ipc_qmi_svc,param_2,param_3,1,0x12,
                            cnss_plat_ipc_qmi_init_setup_resp_msg_v01_ei,&local_58);
  if (iVar2 < 0) {
    if ((*(uint *)(lVar1 + 0x10) & 0xf0000) == 0) {
      pcVar3 = (char *)(lVar1 + 0x848);
      if ((*(uint *)(lVar1 + 0x10) & 0xff00) != 0) {
        pcVar3 = "soft_irq";
      }
    }
    else {
      pcVar3 = "irq";
    }
    cnss_plat_ipc_debug_log_print
              (cnss_plat_ipc_log_context,pcVar3,"cnss_plat_ipc_qmi_init_setup_req_handler",
               &DAT_00102585,"%s: QMI failed: %d\n","cnss_plat_ipc_qmi_init_setup_req_handler");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// cnss_plat_ipc_qmi_file_download_req_handler @ 001019d4 size=912
// signature: undefined cnss_plat_ipc_qmi_file_download_req_handler(void)
// callers: []
//------------------------------------------------------------

void cnss_plat_ipc_qmi_file_download_req_handler
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  int iVar5;
  undefined8 *puVar6;
  char *pcVar7;
  ulong __n;
  uint uVar8;
  undefined4 uVar9;
  undefined8 local_68;
  int local_60;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_60 = 0;
  local_68 = 0;
  if (param_4 != (undefined4 *)0x0) {
    lVar3 = sp_el0;
    if ((*(uint *)(lVar3 + 0x10) & 0xf0000) == 0) {
      pcVar7 = (char *)(lVar3 + 0x848);
      if ((*(uint *)(lVar3 + 0x10) & 0xff00) != 0) {
        pcVar7 = "soft_irq";
      }
    }
    else {
      pcVar7 = "irq";
    }
    uVar9 = param_4[3];
    uVar8 = (uint)*(byte *)(param_4 + 2);
    cnss_plat_ipc_debug_log_print
              (cnss_plat_ipc_log_context,pcVar7,"cnss_plat_ipc_qmi_file_download_req_handler",
               &DAT_00102953,"File ID: %d Size: %d Seg Len: %d Index: %d End: %d\n",*param_4,
               param_4[1],param_4[4],uVar9,uVar8);
    mutex_lock(&DAT_00102440);
    puVar6 = (undefined8 *)idr_find(&DAT_00102428,*param_4);
    mutex_unlock(&DAT_00102440);
    if (puVar6 == (undefined8 *)0x0) {
      if ((*(uint *)(lVar3 + 0x10) & 0xf0000) == 0) {
        pcVar7 = (char *)(lVar3 + 0x848);
        if ((*(uint *)(lVar3 + 0x10) & 0xff00) != 0) {
          pcVar7 = "soft_irq";
        }
      }
      else {
        pcVar7 = "irq";
      }
      cnss_plat_ipc_debug_log_print
                (cnss_plat_ipc_log_context,pcVar7,"cnss_plat_ipc_qmi_file_download_req_handler",
                 &DAT_00102585,"Invalid File ID: %d\n",*param_4);
    }
    else {
      uVar1 = *(uint *)((long)puVar6 + 0x14);
      if (uVar1 < (uint)param_4[1]) {
        if ((*(uint *)(lVar3 + 0x10) & 0xf0000) == 0) {
          pcVar7 = (char *)(lVar3 + 0x848);
          if ((*(uint *)(lVar3 + 0x10) & 0xff00) != 0) {
            pcVar7 = "soft_irq";
          }
        }
        else {
          pcVar7 = "irq";
        }
        cnss_plat_ipc_debug_log_print
                  (cnss_plat_ipc_log_context,pcVar7,"cnss_plat_ipc_qmi_file_download_req_handler",
                   &DAT_00102585,"File %s size %d larger than buffer size %d\n",*puVar6,param_4[1],
                   uVar1,uVar9,uVar8);
      }
      else {
        uVar2 = param_4[4];
        __n = (ulong)uVar2;
        if ((uVar2 < 0xf001) && (*(int *)(puVar6 + 3) + uVar2 <= uVar1)) {
          if (param_4[3] == *(int *)((long)puVar6 + 0x1c)) {
            memcpy((void *)puVar6[1],param_4 + 5,__n);
            local_60 = *(int *)((long)puVar6 + 0x1c) + 1;
            *(int *)((long)puVar6 + 0x1c) = local_60;
            puVar6[1] = puVar6[1] + (ulong)(uint)param_4[4];
            uVar4 = plat_ipc_qmi_svc;
            *(int *)(puVar6 + 3) = *(int *)(puVar6 + 3) + param_4[4];
            local_68 = CONCAT44(*(undefined4 *)(puVar6 + 2),(undefined4)local_68);
            iVar5 = qmi_send_response(uVar4,param_2,param_3,3,0x15,
                                      cnss_plat_ipc_qmi_file_download_resp_msg_v01_ei,&local_68);
            if (iVar5 < 0) {
              if ((*(uint *)(lVar3 + 0x10) & 0xf0000) == 0) {
                pcVar7 = (char *)(lVar3 + 0x848);
                if ((*(uint *)(lVar3 + 0x10) & 0xff00) != 0) {
                  pcVar7 = "soft_irq";
                }
              }
              else {
                pcVar7 = "irq";
              }
              cnss_plat_ipc_debug_log_print
                        (cnss_plat_ipc_log_context,pcVar7,
                         "cnss_plat_ipc_qmi_file_download_req_handler",&DAT_00102585,
                         "QMI failed: %d\n");
            }
            if (*(char *)(param_4 + 2) == '\0') goto LAB_00101bec;
            *(undefined4 *)((long)puVar6 + 0x24) = 1;
          }
          else {
            if ((*(uint *)(lVar3 + 0x10) & 0xf0000) == 0) {
              pcVar7 = (char *)(lVar3 + 0x848);
              if ((*(uint *)(lVar3 + 0x10) & 0xff00) != 0) {
                pcVar7 = "soft_irq";
              }
            }
            else {
              pcVar7 = "irq";
            }
            cnss_plat_ipc_debug_log_print
                      (cnss_plat_ipc_log_context,pcVar7,
                       "cnss_plat_ipc_qmi_file_download_req_handler",&DAT_00102585,
                       "File %s transfer segment failure\n",*puVar6,__n,uVar1,uVar9,uVar8);
          }
        }
        else {
          if ((*(uint *)(lVar3 + 0x10) & 0xf0000) == 0) {
            pcVar7 = (char *)(lVar3 + 0x848);
            if ((*(uint *)(lVar3 + 0x10) & 0xff00) != 0) {
              pcVar7 = "soft_irq";
            }
          }
          else {
            pcVar7 = "irq";
          }
          cnss_plat_ipc_debug_log_print
                    (cnss_plat_ipc_log_context,pcVar7,"cnss_plat_ipc_qmi_file_download_req_handler",
                     &DAT_00102585,"Segment buf ID: %d buffer size %d not allowed\n",param_4[3],__n,
                     uVar1,uVar9,uVar8);
        }
      }
      complete(puVar6 + 5);
    }
  }
LAB_00101bec:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// cnss_plat_ipc_qmi_file_upload_req_handler @ 00101d68 size=824
// signature: undefined cnss_plat_ipc_qmi_file_upload_req_handler(void)
// callers: []
//------------------------------------------------------------

void cnss_plat_ipc_qmi_file_upload_req_handler
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  undefined8 *puVar5;
  long lVar6;
  char *pcVar7;
  uint uVar8;
  
  if (param_4 != (undefined4 *)0x0) {
    lVar3 = sp_el0;
    if ((*(uint *)(lVar3 + 0x10) & 0xf0000) == 0) {
      pcVar7 = (char *)(lVar3 + 0x848);
      if ((*(uint *)(lVar3 + 0x10) & 0xff00) != 0) {
        pcVar7 = "soft_irq";
      }
    }
    else {
      pcVar7 = "irq";
    }
    cnss_plat_ipc_debug_log_print
              (cnss_plat_ipc_log_context,pcVar7,"cnss_plat_ipc_qmi_file_upload_req_handler",
               &DAT_00102953,"File ID: %d Seg Index: %d\n",*param_4,param_4[1]);
    mutex_lock(&DAT_00102440);
    puVar5 = (undefined8 *)idr_find(&DAT_00102428,*param_4);
    mutex_unlock(&DAT_00102440);
    if (puVar5 == (undefined8 *)0x0) {
      if ((*(uint *)(lVar3 + 0x10) & 0xf0000) == 0) {
        pcVar7 = (char *)(lVar3 + 0x848);
        if ((*(uint *)(lVar3 + 0x10) & 0xff00) != 0) {
          pcVar7 = "soft_irq";
        }
      }
      else {
        pcVar7 = "irq";
      }
      cnss_plat_ipc_debug_log_print
                (cnss_plat_ipc_log_context,pcVar7,"cnss_plat_ipc_qmi_file_upload_req_handler",
                 &DAT_00102585,"Invalid File ID %d\n",*param_4);
    }
    else {
      if (param_4[1] != *(int *)((long)puVar5 + 0x1c)) {
        if ((*(uint *)(lVar3 + 0x10) & 0xf0000) == 0) {
          pcVar7 = (char *)(lVar3 + 0x848);
          if ((*(uint *)(lVar3 + 0x10) & 0xff00) != 0) {
            pcVar7 = "soft_irq";
          }
        }
        else {
          pcVar7 = "irq";
        }
        cnss_plat_ipc_debug_log_print
                  (cnss_plat_ipc_log_context,pcVar7,"cnss_plat_ipc_qmi_file_upload_req_handler",
                   &DAT_00102585,"File %s transfer segment failure\n",*puVar5);
        complete(puVar5 + 5);
      }
      lVar6 = kmalloc_large(0xf014,0xdc0);
      if (lVar6 != 0) {
        *(undefined4 *)(lVar6 + 4) = *(undefined4 *)(puVar5 + 2);
        iVar4 = *(int *)((long)puVar5 + 0x1c);
        *(int *)((long)puVar5 + 0x1c) = iVar4 + 1;
        *(int *)(lVar6 + 0xc) = iVar4;
        uVar8 = *(uint *)((long)puVar5 + 0x14);
        if (0xefff < uVar8) {
          uVar8 = 0xf000;
        }
        *(uint *)(lVar6 + 0x10) = uVar8;
        iVar1 = *(int *)((long)puVar5 + 0x1c);
        iVar2 = *(int *)(puVar5 + 4);
        *(bool *)(lVar6 + 8) = iVar1 == iVar2;
        memcpy((void *)(lVar6 + 0x14),(void *)puVar5[1],(ulong)uVar8);
        if ((*(uint *)(lVar3 + 0x10) & 0xf0000) == 0) {
          pcVar7 = (char *)(lVar3 + 0x848);
          if ((*(uint *)(lVar3 + 0x10) & 0xff00) != 0) {
            pcVar7 = "soft_irq";
          }
        }
        else {
          pcVar7 = "irq";
        }
        cnss_plat_ipc_debug_log_print
                  (cnss_plat_ipc_log_context,pcVar7,"cnss_plat_ipc_qmi_file_upload_req_handler",
                   &DAT_00102953,"ID: %d Seg ID: %d Len: %d End: %d\n",*(undefined4 *)(lVar6 + 4),
                   iVar4,uVar8,iVar1 == iVar2);
        iVar4 = qmi_send_response(plat_ipc_qmi_svc,param_2,param_3,5,0xf01e,
                                  cnss_plat_ipc_qmi_file_upload_resp_msg_v01_ei,lVar6);
        if (iVar4 < 0) {
          if ((*(uint *)(lVar3 + 0x10) & 0xf0000) == 0) {
            pcVar7 = (char *)(lVar3 + 0x848);
            if ((*(uint *)(lVar3 + 0x10) & 0xff00) != 0) {
              pcVar7 = "soft_irq";
            }
          }
          else {
            pcVar7 = "irq";
          }
          cnss_plat_ipc_debug_log_print
                    (cnss_plat_ipc_log_context,pcVar7,"cnss_plat_ipc_qmi_file_upload_req_handler",
                     &DAT_00102585,"QMI failed: %d\n");
        }
        else {
          *(int *)((long)puVar5 + 0x14) = *(int *)((long)puVar5 + 0x14) - *(int *)(lVar6 + 0x10);
          puVar5[1] = puVar5[1] + (ulong)*(uint *)(lVar6 + 0x10);
          if (*(char *)(lVar6 + 8) != '\0') {
            *(undefined4 *)((long)puVar5 + 0x24) = 1;
            complete(puVar5 + 5);
          }
        }
        kfree(lVar6);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001022fc size=180
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 init_module(void)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = of_find_node_with_property(0,"qcom,wlan");
  if (lVar1 != 0) {
    do {
      uVar2 = of_device_is_available(lVar1);
      if ((uVar2 & 1) != 0) {
        cnss_plat_ipc_log_context = ipc_log_context_create(10,"cnss_plat",0);
        if (cnss_plat_ipc_log_context == 0) {
          _printk(&DAT_00102599);
        }
        queue_work_on(0x20,_system_wq,&cnss_plat_ipc_init_work);
        return 0;
      }
      lVar1 = of_find_node_with_property(lVar1,"qcom,wlan");
    } while (lVar1 != 0);
  }
  return 0xffffffed;
}



//------------------------------------------------------------
// cleanup_module @ 001023b4 size=104
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  cancel_work_sync(&cnss_plat_ipc_init_work);
  if (plat_ipc_qmi_svc != 0) {
    qmi_handle_release();
    kfree(plat_ipc_qmi_svc);
    idr_destroy(&DAT_00102428);
  }
  if (cnss_plat_ipc_log_context != 0) {
    ipc_log_context_destroy();
    cnss_plat_ipc_log_context = 0;
  }
  return;
}



//------------------------------------------------------------
// scnprintf @ 00104000 size=1
// signature: undefined scnprintf(void)
// callers: [cnss_plat_ipc_qmi_file_download, cnss_plat_ipc_qmi_file_upload]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_send_indication @ 00104008 size=1
// signature: undefined qmi_send_indication(void)
// callers: [cnss_plat_ipc_qmi_file_download, cnss_plat_ipc_qmi_file_upload]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_send_indication(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00104010 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [cnss_plat_ipc_qmi_file_download, cnss_plat_ipc_qmi_file_upload]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00104018 size=1
// signature: undefined mutex_lock(void)
// callers: [cnss_plat_ipc_qmi_disconnect_cb, cnss_plat_ipc_qmi_file_download_req_handler, cnss_plat_ipc_qmi_file_download, cnss_plat_ipc_qmi_file_upload, cnss_plat_ipc_qmi_file_upload_req_handler, cnss_plat_ipc_init_file_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_remove @ 00104020 size=1
// signature: undefined idr_remove(void)
// callers: [cnss_plat_ipc_qmi_file_download, cnss_plat_ipc_qmi_file_upload]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104028 size=1
// signature: undefined mutex_unlock(void)
// callers: [cnss_plat_ipc_qmi_disconnect_cb, cnss_plat_ipc_qmi_file_download_req_handler, cnss_plat_ipc_qmi_file_download, cnss_plat_ipc_qmi_file_upload, cnss_plat_ipc_qmi_file_upload_req_handler, cnss_plat_ipc_init_file_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00104030 size=1
// signature: undefined kfree(void)
// callers: [cnss_plat_ipc_init_fn, cleanup_module, cnss_plat_ipc_qmi_file_download, cnss_plat_ipc_qmi_file_upload, cnss_plat_ipc_qmi_file_upload_req_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104038 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [cnss_plat_ipc_qmi_reg_client_req_handler, cnss_plat_ipc_qmi_disconnect_cb, cnss_plat_ipc_qmi_file_download_req_handler, cnss_plat_ipc_debug_log_print, cnss_plat_ipc_qmi_file_download, cnss_plat_ipc_qmi_file_upload, cnss_plat_ipc_qmi_init_setup_req_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00104040 size=1
// signature: undefined ipc_log_string(void)
// callers: [cnss_plat_ipc_debug_log_print]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104048 size=1
// signature: undefined _printk(void)
// callers: [cnss_plat_ipc_debug_log_print, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00104058 size=1
// signature: undefined kmalloc_trace(void)
// callers: [cnss_plat_ipc_init_fn, cnss_plat_ipc_init_file_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00104060 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [cnss_plat_ipc_init_file_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_alloc_cyclic @ 00104068 size=1
// signature: undefined idr_alloc_cyclic(void)
// callers: [cnss_plat_ipc_init_file_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_alloc_cyclic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00104070 size=1
// signature: undefined msleep(void)
// callers: [cnss_plat_ipc_qmi_daemon_config, cnss_plat_ipc_init_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_with_property @ 00104078 size=1
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
// of_device_is_available @ 00104080 size=1
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
// ipc_log_context_create @ 00104088 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00104098 size=1
// signature: undefined queue_work_on(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 001040a0 size=1
// signature: undefined cancel_work_sync(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_release @ 001040a8 size=1
// signature: undefined qmi_handle_release(void)
// callers: [cnss_plat_ipc_init_fn, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_destroy @ 001040b0 size=1
// signature: undefined idr_destroy(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 001040b8 size=1
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
// qmi_handle_init @ 001040c0 size=1
// signature: undefined qmi_handle_init(void)
// callers: [cnss_plat_ipc_init_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_add_server @ 001040c8 size=1
// signature: undefined qmi_add_server(void)
// callers: [cnss_plat_ipc_init_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_add_server(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001040d0 size=1
// signature: undefined __mutex_init(void)
// callers: [cnss_plat_ipc_init_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_get_next @ 001040d8 size=1
// signature: undefined idr_get_next(void)
// callers: [cnss_plat_ipc_qmi_disconnect_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_get_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 001040e0 size=1
// signature: undefined complete(void)
// callers: [cnss_plat_ipc_qmi_disconnect_cb, cnss_plat_ipc_qmi_file_download_req_handler, cnss_plat_ipc_qmi_file_upload_req_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_send_response @ 001040e8 size=1
// signature: undefined qmi_send_response(void)
// callers: [cnss_plat_ipc_qmi_reg_client_req_handler, cnss_plat_ipc_qmi_file_download_req_handler, cnss_plat_ipc_qmi_file_upload_req_handler, cnss_plat_ipc_qmi_init_setup_req_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_send_response(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_find @ 001040f0 size=1
// signature: undefined idr_find(void)
// callers: [cnss_plat_ipc_qmi_file_download_req_handler, cnss_plat_ipc_qmi_file_upload_req_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001040f8 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [cnss_plat_ipc_qmi_file_download_req_handler, cnss_plat_ipc_qmi_file_upload_req_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_large @ 00104100 size=1
// signature: undefined kmalloc_large(void)
// callers: [cnss_plat_ipc_qmi_file_upload_req_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_large(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



