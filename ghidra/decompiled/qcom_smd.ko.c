// Decompiled by Ghidra 12.2
// Program: qcom_smd.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_smd_register_signals_cb @ 001006e4 size=32
// signature: undefined qcom_smd_register_signals_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_smd_register_signals_cb(long param_1,long param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0xffffffea;
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = 0;
    *(long *)(*(long *)(param_1 + 0x60) + 0xb0) = param_2;
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_smd_get_sigs @ 00100708 size=132
// signature: undefined qcom_smd_get_sigs(void)
// callers: []
//------------------------------------------------------------

uint qcom_smd_get_sigs(long param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  
  lVar7 = *(long *)(*(long *)(param_1 + 0x60) + 0x48);
  if (lVar7 == 0) {
    lVar7 = *(long *)(*(long *)(param_1 + 0x60) + 0x40);
    uVar1 = (uint)*(byte *)(lVar7 + 0x18);
    uVar2 = (uint)*(byte *)(lVar7 + 0x19);
    uVar3 = (uint)*(byte *)(lVar7 + 0x1a);
    uVar4 = (uint)*(byte *)(lVar7 + 0x1b);
    uVar5 = (uint)*(byte *)(lVar7 + 4);
    uVar6 = (uint)*(byte *)(lVar7 + 5);
  }
  else {
    uVar1 = *(uint *)(lVar7 + 0x30);
    uVar2 = *(uint *)(lVar7 + 0x34);
    uVar3 = *(uint *)(lVar7 + 0x38);
    uVar4 = *(uint *)(lVar7 + 0x3c);
    uVar5 = *(uint *)(lVar7 + 4);
    uVar6 = *(uint *)(lVar7 + 8);
  }
  return (uint)(uVar5 != 0) << 1 | (uint)(uVar3 != 0) << 6 | (uint)(uVar1 != 0) << 8 |
         (uint)(uVar2 != 0) << 5 | (uint)(uVar4 != 0) << 7 | (uint)(uVar6 != 0) << 2;
}



//------------------------------------------------------------
// qcom_smd_set_sigs @ 00100790 size=292
// signature: undefined qcom_smd_set_sigs(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

undefined8 qcom_smd_set_sigs(long param_1,uint param_2)

{
  long *plVar1;
  long lVar2;
  
  plVar1 = *(long **)(param_1 + 0x60);
  lVar2 = plVar1[9];
  if ((param_2 >> 1 & 1) == 0) {
    if (lVar2 == 0) {
      *(undefined1 *)(plVar1[8] + 4) = 0;
      lVar2 = plVar1[9];
    }
    else {
      *(undefined4 *)(lVar2 + 4) = 0;
      lVar2 = plVar1[9];
    }
  }
  else if (lVar2 == 0) {
    *(undefined1 *)(plVar1[8] + 4) = 1;
    lVar2 = plVar1[9];
  }
  else {
    *(undefined4 *)(lVar2 + 4) = 1;
    lVar2 = plVar1[9];
  }
  if ((param_2 >> 2 & 1) == 0) {
    if (lVar2 == 0) {
      *(undefined1 *)(plVar1[8] + 4) = 0;
      lVar2 = plVar1[9];
    }
    else {
      *(undefined4 *)(lVar2 + 4) = 0;
      lVar2 = plVar1[9];
    }
  }
  else if (lVar2 == 0) {
    *(undefined1 *)(plVar1[8] + 5) = 1;
    lVar2 = plVar1[9];
  }
  else {
    *(undefined4 *)(lVar2 + 8) = 1;
    lVar2 = plVar1[9];
  }
  if (lVar2 == 0) {
    *(undefined1 *)(plVar1[8] + 10) = 1;
  }
  else {
    *(undefined4 *)(lVar2 + 0x1c) = 1;
  }
  lVar2 = *plVar1;
  if (*(long *)(lVar2 + 0x3f8) == 0) {
    regmap_write(*(undefined8 *)(lVar2 + 0x3b0),*(undefined4 *)(lVar2 + 0x3b8),
                 1L << ((ulong)*(uint *)(lVar2 + 0x3bc) & 0x3f));
  }
  else {
    mbox_send_message(*(long *)(lVar2 + 0x3f8),0);
    mbox_client_txdone(*(undefined8 *)(lVar2 + 0x3f8),0);
  }
  return 0;
}



//------------------------------------------------------------
// qcom_smd_register_edge @ 001008b8 size=1024
// signature: undefined qcom_smd_register_edge(void)
// callers: [qcom_smd_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long qcom_smd_register_edge(long *param_1,undefined8 *param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  char *pcVar5;
  long lVar6;
  char *pcVar7;
  long local_88 [11];
  
  lVar3 = sp_el0;
  local_88[10] = *(long *)(lVar3 + 0x638);
  lVar3 = kmalloc_trace(_irq_of_parse_and_map,0xdc0,0x4a8);
  if (lVar3 == 0) {
    lVar3 = -0xc;
    goto LAB_00100c5c;
  }
  __init_waitqueue_head(lVar3 + 0x430,"&edge->new_channel_event",&qcom_smd_register_edge___key);
  lVar6 = param_1[0xe];
  *(long **)(lVar3 + 0x60) = param_1;
  *(undefined8 **)(lVar3 + 0x2e8) = param_2;
  *(code **)(lVar3 + 0x328) = qcom_smd_edge_release;
  *(undefined ***)(lVar3 + 800) = &qcom_smd_edge_groups;
  if (lVar6 == 0) {
    lVar6 = *param_1;
  }
  dev_set_name(lVar3,"%s:%pOFn",lVar6,param_2);
  iVar1 = device_register(lVar3);
  if (iVar1 == 0) {
    *(long *)(lVar3 + 0x400) = lVar3 + 0x400;
    *(long *)(lVar3 + 0x408) = lVar3 + 0x400;
    *(undefined4 *)(lVar3 + 0x410) = 0;
    *(undefined8 *)(lVar3 + 0x448) = 0xfffffffe0;
    *(long *)(lVar3 + 0x450) = lVar3 + 0x450;
    *(long *)(lVar3 + 0x458) = lVar3 + 0x450;
    *(code **)(lVar3 + 0x460) = qcom_channel_scan_worker;
    *(undefined8 *)(lVar3 + 0x478) = 0xfffffffe0;
    *(long *)(lVar3 + 0x480) = lVar3 + 0x480;
    *(long *)(lVar3 + 0x488) = lVar3 + 0x480;
    *(code **)(lVar3 + 0x490) = qcom_channel_state_worker;
    *(undefined8 **)(lVar3 + 0x398) = param_2;
    iVar1 = of_property_read_variable_u32_array(param_2,"qcom,smd-edge",lVar3 + 0x3a0,1,0);
    if (iVar1 < 0) {
      pcVar5 = "edge missing %s property\n";
      pcVar7 = "qcom,smd-edge";
LAB_00100bc0:
      _dev_err(lVar3,pcVar5,pcVar7);
LAB_00100c28:
      *(undefined8 *)(lVar3 + 0x398) = 0;
LAB_00100c2c:
      pcVar5 = "failed to parse smd edge\n";
    }
    else {
      *(undefined4 *)(lVar3 + 0x3a4) = 0xffffffff;
      of_property_read_variable_u32_array(param_2,"qcom,remote-pid",lVar3 + 0x3a4,1,0);
      *(long *)(lVar3 + 0x3c0) = lVar3;
      *(undefined1 *)(lVar3 + 0x3d8) = 1;
      uVar4 = mbox_request_channel(lVar3 + 0x3c0,0);
      *(ulong *)(lVar3 + 0x3f8) = uVar4;
      if (uVar4 < 0xfffffffffffff001) {
LAB_00100acc:
        iVar1 = of_property_read_string(param_2,"label",(undefined8 *)(lVar3 + 0x390));
        if (iVar1 < 0) {
          *(undefined8 *)(lVar3 + 0x390) = *param_2;
        }
        iVar2 = irq_of_parse_and_map(param_2,0);
        if (iVar2 == 0) {
          _dev_err(lVar3,"required smd interrupt missing\n");
          iVar1 = -0x16;
        }
        else {
          iVar1 = devm_request_threaded_irq(lVar3,iVar2,qcom_smd_edge_intr,0,0x4001,*param_2,lVar3);
          if (iVar1 == 0) {
            *(int *)(lVar3 + 0x3a8) = iVar2;
            goto LAB_00100b30;
          }
          _dev_err(lVar3,"failed to request smd irq\n");
        }
        goto LAB_00100c28;
      }
      if (uVar4 == 0xffffffffffffffed) {
        *(undefined8 *)(lVar3 + 0x3f8) = 0;
        local_88[8] = 0;
        local_88[9] = 0;
        local_88[6] = 0;
        local_88[7] = 0;
        local_88[4] = 0;
        local_88[5] = 0;
        local_88[2] = 0;
        local_88[3] = 0;
        local_88[0] = 0;
        local_88[1] = 0;
        iVar1 = __of_parse_phandle_with_args(param_2,"qcom,ipc",0,0,0,local_88);
        if ((iVar1 != 0) || (local_88[0] == 0)) {
          _dev_err(lVar3,"no qcom,ipc node\n");
          iVar1 = -0x13;
          goto LAB_00100c28;
        }
        uVar4 = syscon_node_to_regmap();
        *(ulong *)(lVar3 + 0x3b0) = uVar4;
        if (uVar4 < 0xfffffffffffff001) {
          iVar1 = of_property_read_u32_index(param_2,"qcom,ipc",1,lVar3 + 0x3b8);
          if (iVar1 < 0) {
            pcVar5 = "no offset in %s\n";
          }
          else {
            iVar1 = of_property_read_u32_index(param_2,"qcom,ipc",2,lVar3 + 0x3bc);
            if (-1 < iVar1) goto LAB_00100acc;
            pcVar5 = "no bit in %s\n";
          }
          pcVar7 = "qcom,ipc";
          goto LAB_00100bc0;
        }
      }
      *(undefined8 *)(lVar3 + 0x398) = 0;
      iVar1 = (int)uVar4;
      if (iVar1 != 0) goto LAB_00100c2c;
LAB_00100b30:
      lVar6 = kmalloc_trace(_of_property_read_string,0xdc0,1000);
      if (lVar6 == 0) {
        iVar1 = -0xc;
      }
      else {
        *(long *)(lVar6 + 0x3e0) = lVar3;
        *(undefined1 **)(lVar6 + 0x3d8) = qcom_smd_device_ops;
        *(long *)(lVar6 + 0x60) = lVar3;
        *(code **)(lVar6 + 0x328) = qcom_smd_release_device;
        iVar1 = rpmsg_register_device_override(lVar6,"rpmsg_ctrl");
        if (iVar1 == 0) {
          queue_work_on(0x20,_system_wq,lVar3 + 0x448);
          goto LAB_00100c5c;
        }
      }
      pcVar5 = "failed to register chrdev for edge\n";
    }
    _dev_err(lVar3,pcVar5);
    if ((*(ulong *)(lVar3 + 0x3f8) != 0) && (*(ulong *)(lVar3 + 0x3f8) < 0xfffffffffffff001)) {
      mbox_free_channel();
    }
    device_unregister(lVar3);
  }
  else {
    _printk(&DAT_00102b51);
    put_device(lVar3);
  }
  lVar3 = (long)iVar1;
LAB_00100c5c:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_88[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3;
}



//------------------------------------------------------------
// qcom_smd_edge_release @ 00100cbc size=216
// signature: undefined qcom_smd_edge_release(void)
// callers: []
//------------------------------------------------------------

void qcom_smd_edge_release(long param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  
  plVar3 = *(long **)(param_1 + 0x400);
  while (plVar3 != (long *)(param_1 + 0x400)) {
    plVar5 = (long *)*plVar3;
    __wake_up(plVar3 + -9,1,0,0);
    __wake_up(plVar3 + -0xf,1,0,0);
    uVar4 = __list_del_entry_valid(plVar3);
    if ((uVar4 & 1) != 0) {
      lVar1 = *plVar3;
      plVar2 = (long *)plVar3[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *plVar3 = -0x2152ffffffffff00;
    plVar3[1] = -0x2152fffffffffede;
    synchronize_rcu();
    kfree(plVar3[-0x11]);
    kfree(plVar3 + -0x14);
    plVar3 = plVar5;
  }
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// qcom_smd_unregister_edge @ 00100d98 size=128
// signature: undefined qcom_smd_unregister_edge(void)
// callers: [qcom_smd_remove_edge]
//------------------------------------------------------------

undefined8 qcom_smd_unregister_edge(long param_1)

{
  int iVar1;
  
  disable_irq(*(undefined4 *)(param_1 + 0x3a8));
  cancel_work_sync(param_1 + 0x448);
  cancel_work_sync(param_1 + 0x478);
  iVar1 = device_for_each_child(param_1,0,qcom_smd_remove_device);
  if (iVar1 != 0) {
    _dev_warn(param_1,"can\'t remove smd device: %d\n",iVar1);
  }
  mbox_free_channel(*(undefined8 *)(param_1 + 0x3f8));
  device_unregister(param_1);
  return 0;
}



//------------------------------------------------------------
// qcom_smd_remove_device @ 00100e1c size=32
// signature: undefined qcom_smd_remove_device(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_smd_remove_device(void)

{
  device_unregister();
  return 0;
}



//------------------------------------------------------------
// rpmsg_name_show @ 00100e40 size=52
// signature: undefined rpmsg_name_show(void)
// callers: []
//------------------------------------------------------------

long rpmsg_name_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = sprintf(param_3,"%s\n",*(undefined8 *)(param_1 + 0x390));
  return (long)iVar1;
}



//------------------------------------------------------------
// qcom_channel_scan_worker @ 00100e78 size=840
// signature: undefined qcom_channel_scan_worker(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_channel_scan_worker(long param_1)

{
  long *plVar1;
  long lVar2;
  ulong *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  bool bVar8;
  char *pcVar9;
  long *plVar10;
  long lVar11;
  ulong uVar12;
  undefined8 uVar13;
  long *plVar14;
  ulong uVar15;
  long lVar16;
  int iVar17;
  long local_78;
  ulong local_70;
  long local_68;
  
  lVar16 = sp_el0;
  local_68 = *(long *)(lVar16 + 0x638);
  lVar16 = 0;
  plVar14 = (long *)(param_1 + -0x48);
  do {
    pcVar9 = (char *)qcom_smem_get(*(undefined4 *)(param_1 + -0xa4),(&smem_items)[lVar16 * 3],0);
    if (pcVar9 < (char *)0xfffffffffffff001) {
      uVar15 = 0;
      lVar2 = param_1 + -0x30 + lVar16 * 8;
      do {
        uVar4 = *(uint *)(pcVar9 + 0x18);
        if (((((*(ulong *)(lVar2 + (uVar15 >> 3 & 0x1ffffffffffffff8)) >> (uVar15 & 0x3f) & 1) == 0)
             && (*(int *)(pcVar9 + 0x1c) != 0)) && (*pcVar9 != '\0')) &&
           (((uVar4 & 0x300) != 0 && (*(uint *)(param_1 + -0xa8) == (uVar4 & 0xff))))) {
          iVar17 = *(int *)(pcVar9 + 0x14);
          local_78 = 0;
          local_70 = 0;
          iVar5 = (&DAT_00102f64)[lVar16 * 3];
          iVar6 = (&DAT_00102f68)[lVar16 * 3];
          plVar10 = (long *)kmalloc_trace(___init_waitqueue_head,0xdc0,0xc0);
          if (plVar10 != (long *)0x0) {
            *plVar10 = param_1 + -0x448;
            lVar11 = kstrdup(pcVar9,0xcc0);
            plVar10[3] = lVar11;
            if (lVar11 == 0) {
              iVar17 = -0xc;
LAB_00101084:
              kfree(plVar10);
              plVar10 = (long *)(long)iVar17;
            }
            else {
              *(undefined4 *)(plVar10 + 10) = 0;
              *(undefined4 *)(plVar10 + 0x12) = 0;
              __init_waitqueue_head
                        (plVar10 + 0xb,"&channel->fblockread_event",&qcom_smd_create_channel___key);
              __init_waitqueue_head
                        (plVar10 + 5,"&channel->state_change_event",
                         &qcom_smd_create_channel___key_20);
              uVar12 = qcom_smem_get(*(undefined4 *)(param_1 + -0xa4),iVar5 + iVar17,&local_78);
              if (0xfffffffffffff000 < uVar12) {
LAB_00101078:
                iVar17 = (int)uVar12;
                kfree(plVar10[3]);
                goto LAB_00101084;
              }
              if (local_78 == 0x28) {
                plVar10[8] = uVar12;
              }
              else {
                if (local_78 != 0x58) {
                  _dev_err(param_1 + -0x448,"channel info of size %zu not supported\n");
                  uVar12 = 0xffffffffffffffea;
                  goto LAB_00101078;
                }
                plVar10[9] = uVar12;
              }
              uVar12 = qcom_smem_get(*(undefined4 *)(param_1 + -0xa4),iVar6 + iVar17,&local_70);
              if (0xfffffffffffff000 < uVar12) goto LAB_00101078;
              local_70 = local_70 >> 1;
              plVar10[0xe] = uVar12;
              plVar10[0xf] = uVar12 + local_70;
              *(int *)(plVar10 + 0x10) = (int)local_70;
              qcom_smd_channel_reset(plVar10);
            }
            if (plVar10 < (long *)0xfffffffffffff001) {
              *(byte *)((long)plVar10 + 0xbc) = (byte)(uVar4 >> 9) & 1;
              uVar13 = _raw_spin_lock_irqsave(param_1 + -0x38);
              plVar1 = plVar10 + 0x14;
              lVar11 = *plVar14;
              uVar12 = __list_add_valid(plVar1,plVar14,lVar11);
              if ((uVar12 & 1) != 0) {
                *(long **)(lVar11 + 8) = plVar1;
                plVar10[0x14] = lVar11;
                plVar10[0x15] = (long)plVar14;
                *plVar14 = (long)plVar1;
              }
              _raw_spin_unlock_irqrestore(param_1 + -0x38,uVar13);
              puVar3 = (ulong *)(lVar2 + (uVar15 >> 6) * 8);
              Hint_Prefetch(puVar3,2,0,1);
              do {
                cVar7 = '\x01';
                bVar8 = (bool)ExclusiveMonitorPass(puVar3,0x10);
                if (bVar8) {
                  *puVar3 = *puVar3 | 1L << (uVar15 & 0x3f);
                  cVar7 = ExclusiveMonitorsStatus();
                }
              } while (cVar7 != '\0');
              __wake_up(param_1 + -0x18,1,0,0);
            }
          }
        }
        uVar15 = uVar15 + 1;
        pcVar9 = pcVar9 + 0x20;
      } while (uVar15 != 0x40);
    }
    lVar16 = lVar16 + 1;
    if (lVar16 == 2) {
      queue_work_on(0x20,_system_wq,param_1 + 0x30);
      lVar16 = sp_el0;
      if (*(long *)(lVar16 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// qcom_channel_state_worker @ 001011cc size=668
// signature: undefined qcom_channel_state_worker(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_channel_state_worker(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  int *piVar5;
  long lVar6;
  long *plVar7;
  long lVar8;
  char *__s2;
  long *plVar9;
  char *local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar3 = sp_el0;
  lVar6 = param_1 + -0x68;
  local_68 = *(long *)(lVar3 + 0x638);
  local_78 = 0;
  local_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  uVar2 = _raw_spin_lock_irqsave(lVar6);
  plVar7 = (long *)(param_1 + -0x78);
  plVar9 = (long *)*plVar7;
  if (plVar9 != plVar7) {
    do {
      if ((int)plVar9[-0x10] == 0) {
        if (plVar9[-0xb] == 0) {
          piVar5 = (int *)(plVar9[-0xc] + 0x14);
        }
        else {
          piVar5 = (int *)(plVar9[-0xb] + 0x2c);
        }
        if (((0xfffffffd < *piVar5 - 3U) ||
            (iVar1 = strcmp((char *)plVar9[-0x11],"rpm_requests"), iVar1 == 0)) &&
           ((char)plVar9[-0x12] == '\0')) {
          _raw_spin_unlock_irqrestore(lVar6,uVar2);
          lVar8 = plVar9[-0x14];
          lVar3 = kmalloc_trace(_of_property_read_string,0xdc0,1000);
          if (lVar3 != 0) {
            *(long *)(lVar3 + 0x3e0) = lVar8;
            *(undefined1 **)(lVar3 + 0x3d8) = qcom_smd_device_ops;
            strscpy_pad(lVar3 + 0x390,plVar9[-0x11],0x20);
            lVar4 = 0;
            *(undefined8 *)(lVar3 + 0x3c0) = 0xffffffffffffffff;
            uVar2 = *(undefined8 *)(lVar8 + 0x398);
            __s2 = (char *)plVar9[-0x11];
            local_98 = (char *)0x0;
            do {
              lVar4 = of_get_next_available_child(uVar2,lVar4);
              if (lVar4 == 0) break;
              iVar1 = of_property_read_string(lVar4,"qcom,smd-channels",&local_98);
            } while ((iVar1 != 0) || (iVar1 = strcmp(local_98,__s2), iVar1 != 0));
            *(long *)(lVar3 + 0x2e8) = lVar4;
            *(long *)(lVar3 + 0x60) = lVar8;
            *(code **)(lVar3 + 0x328) = qcom_smd_release_device;
            rpmsg_register_device(lVar3);
          }
          uVar2 = _raw_spin_lock_irqsave(lVar6);
          *(undefined1 *)(plVar9 + -0x12) = 1;
        }
      }
      plVar9 = (long *)*plVar9;
    } while (plVar9 != plVar7);
    for (plVar9 = (long *)*plVar7; plVar9 != plVar7; plVar9 = (long *)*plVar9) {
      if (*(int *)(plVar9 + -0x10) - 1U < 2) {
        if (plVar9[-0xb] == 0) {
          piVar5 = (int *)(plVar9[-0xc] + 0x14);
        }
        else {
          piVar5 = (int *)(plVar9[-0xb] + 0x2c);
        }
        if (1 < *piVar5 - 1U) {
          _raw_spin_unlock_irqrestore(lVar6,uVar2);
          strscpy_pad(&local_90,plVar9[-0x11],0x20);
          local_70 = 0xffffffffffffffff;
          rpmsg_unregister_device(param_1 + -0x478,&local_90);
          *(undefined1 *)(plVar9 + -0x12) = 0;
          uVar2 = _raw_spin_lock_irqsave(lVar6);
        }
      }
    }
  }
  _raw_spin_unlock_irqrestore(lVar6,uVar2);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_smd_edge_intr @ 0010146c size=224
// signature: undefined qcom_smd_edge_intr(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_smd_edge_intr(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  long *plVar5;
  
  _raw_spin_lock(param_2 + 0x410);
  plVar5 = *(long **)(param_2 + 0x400);
  if (plVar5 == (long *)(param_2 + 0x400)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0;
    do {
      _raw_spin_lock(plVar5 + -2);
      uVar2 = qcom_smd_channel_intr(plVar5 + -0x14);
      uVar4 = uVar4 | uVar2;
      _raw_spin_unlock(plVar5 + -2);
      plVar5 = (long *)*plVar5;
    } while (plVar5 != (long *)(param_2 + 0x400));
  }
  _raw_spin_unlock(param_2 + 0x410);
  iVar3 = qcom_smem_get_free_space(*(undefined4 *)(param_2 + 0x3a4));
  uVar1 = _system_wq;
  if (iVar3 != *(int *)(param_2 + 0x428)) {
    *(int *)(param_2 + 0x428) = iVar3;
    queue_work_on(0x20,uVar1,param_2 + 0x448);
  }
  if ((uVar4 & 1) != 0) {
    queue_work_on(0x20,_system_wq,param_2 + 0x478);
  }
  return 1;
}



//------------------------------------------------------------
// qcom_smd_channel_reset @ 0010154c size=408
// signature: undefined qcom_smd_channel_reset(void)
// callers: [qcom_smd_destroy_ept, qcom_channel_scan_worker]
//------------------------------------------------------------

void qcom_smd_channel_reset(long *param_1)

{
  undefined4 *puVar1;
  long lVar2;
  
  puVar1 = (undefined4 *)param_1[9];
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)param_1[8];
  }
  *puVar1 = 0;
  if (param_1[9] == 0) {
    *(undefined1 *)(param_1[8] + 4) = 0;
    lVar2 = param_1[9];
  }
  else {
    *(undefined4 *)(param_1[9] + 4) = 0;
    lVar2 = param_1[9];
  }
  if (lVar2 == 0) {
    *(undefined1 *)(param_1[8] + 5) = 0;
    lVar2 = param_1[9];
  }
  else {
    *(undefined4 *)(lVar2 + 8) = 0;
    lVar2 = param_1[9];
  }
  if (lVar2 == 0) {
    *(undefined1 *)(param_1[8] + 6) = 0;
    lVar2 = param_1[9];
  }
  else {
    *(undefined4 *)(lVar2 + 0xc) = 0;
    lVar2 = param_1[9];
  }
  if (lVar2 == 0) {
    *(undefined1 *)(param_1[8] + 7) = 0;
    lVar2 = param_1[9];
  }
  else {
    *(undefined4 *)(lVar2 + 0x10) = 0;
    lVar2 = param_1[9];
  }
  if (lVar2 == 0) {
    *(undefined1 *)(param_1[8] + 8) = 0;
    lVar2 = param_1[9];
  }
  else {
    *(undefined4 *)(lVar2 + 0x14) = 0;
    lVar2 = param_1[9];
  }
  if (lVar2 == 0) {
    *(undefined1 *)(param_1[8] + 9) = 0;
    lVar2 = param_1[9];
  }
  else {
    *(undefined4 *)(lVar2 + 0x18) = 0;
    lVar2 = param_1[9];
  }
  if (lVar2 == 0) {
    *(undefined1 *)(param_1[8] + 10) = 1;
    lVar2 = param_1[9];
  }
  else {
    *(undefined4 *)(lVar2 + 0x1c) = 1;
    lVar2 = param_1[9];
  }
  if (lVar2 == 0) {
    *(undefined1 *)(param_1[8] + 0xb) = 1;
    lVar2 = param_1[9];
  }
  else {
    *(undefined4 *)(lVar2 + 0x20) = 1;
    lVar2 = param_1[9];
  }
  if (lVar2 == 0) {
    puVar1 = (undefined4 *)(param_1[8] + 0x10);
  }
  else {
    puVar1 = (undefined4 *)(lVar2 + 0x28);
  }
  *puVar1 = 0;
  if (param_1[9] == 0) {
    puVar1 = (undefined4 *)(param_1[8] + 0x20);
  }
  else {
    puVar1 = (undefined4 *)(param_1[9] + 0x50);
  }
  *puVar1 = 0;
  lVar2 = *param_1;
  if (*(long *)(lVar2 + 0x3f8) == 0) {
    regmap_write(*(undefined8 *)(lVar2 + 0x3b0),*(undefined4 *)(lVar2 + 0x3b8),
                 1L << ((ulong)*(uint *)(lVar2 + 0x3bc) & 0x3f));
  }
  else {
    mbox_send_message(*(long *)(lVar2 + 0x3f8),0);
    mbox_client_txdone(*(undefined8 *)(lVar2 + 0x3f8),0);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)((long)param_1 + 0x94) = 0;
  return;
}



//------------------------------------------------------------
// qcom_smd_release_device @ 001016e8 size=28
// signature: undefined qcom_smd_release_device(void)
// callers: []
//------------------------------------------------------------

void qcom_smd_release_device(void)

{
  kfree();
  return;
}



//------------------------------------------------------------
// qcom_smd_create_ept @ 00101708 size=1060
// signature: undefined qcom_smd_create_ept(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * qcom_smd_create_ept(long param_1,long param_2,long param_3,char *param_4)

{
  long *plVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  long *plVar8;
  char *pcVar9;
  long *plVar10;
  long *plVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  lVar13 = *(long *)(param_1 + 0x3e0);
  lVar12 = lVar13 + 0x410;
  uVar6 = _raw_spin_lock_irqsave(lVar12);
  plVar8 = (long *)(lVar13 + 0x400);
  plVar10 = plVar8;
  do {
    plVar10 = (long *)*plVar10;
    if (plVar10 == plVar8) {
      _raw_spin_unlock_irqrestore(lVar12,uVar6);
      goto LAB_001017a4;
    }
    iVar5 = strcmp((char *)plVar10[-0x11],param_4);
  } while (iVar5 != 0);
  plVar10 = plVar10 + -0x14;
  _raw_spin_unlock_irqrestore(lVar12,uVar6);
  if (plVar10 == (long *)0x0) {
LAB_001017a4:
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    uStack_80 = 0;
    local_90 = 0;
    init_wait_entry(&local_90,0);
    lVar14 = 0xfa;
LAB_001017c4:
    lVar7 = prepare_to_wait_event(lVar13 + 0x430,&local_90,1);
    uVar6 = _raw_spin_lock_irqsave(lVar12);
    plVar10 = plVar8;
    do {
      plVar10 = (long *)*plVar10;
      if (plVar10 == plVar8) {
        plVar10 = (long *)0x0;
        goto LAB_00101810;
      }
      iVar5 = strcmp((char *)plVar10[-0x11],param_4);
    } while (iVar5 != 0);
    plVar10 = plVar10 + -0x14;
LAB_00101810:
    _raw_spin_unlock_irqrestore(lVar12,uVar6);
    if (lVar14 == 0 && plVar10 != (long *)0x0) {
      lVar14 = 1;
    }
    if ((plVar10 == (long *)0x0) && (lVar14 != 0)) {
      if (lVar7 != 0) goto LAB_00101854;
      lVar14 = schedule_timeout(lVar14);
      goto LAB_001017c4;
    }
    finish_wait(lVar13 + 0x430,&local_90);
    lVar7 = lVar14;
LAB_00101854:
    if ((int)lVar7 != 0) goto LAB_00101858;
  }
  else {
LAB_00101858:
    if ((int)plVar10[4] == 0) {
      plVar8 = (long *)kmalloc_trace(___of_parse_phandle_with_args,0xdc0,0x68);
      if (plVar8 == (long *)0x0) goto LAB_00101aec;
      plVar11 = plVar8 + 1;
      *(int *)plVar11 = 1;
      *plVar8 = param_1;
      plVar8[2] = param_2;
      plVar8[10] = param_3;
      plVar8[0xb] = (long)&qcom_smd_endpoint_ops;
      plVar10[1] = (long)plVar8;
      plVar8[0xc] = (long)plVar10;
      iVar5 = (int)plVar10[0x10];
      lVar12 = *plVar10;
      if (0x1fff < iVar5) {
        iVar5 = 0x2000;
      }
      lVar13 = __kmalloc((long)iVar5,0xcc0);
      plVar10[0x11] = lVar13;
      if (lVar13 != 0) {
        lVar13 = plVar10[1];
        uVar6 = _raw_spin_lock_irqsave(plVar10 + 0x12);
        *(long *)(lVar13 + 0x10) = param_2;
        _raw_spin_unlock_irqrestore(plVar10 + 0x12,uVar6);
        qcom_smd_channel_set_state(plVar10,1);
        if (*(int *)((long)plVar10 + 0x24) - 1U < 2) {
LAB_001019b0:
          qcom_smd_channel_set_state(plVar10,2);
          if (*(int *)((long)plVar10 + 0x24) == 2) goto LAB_00101aec;
          local_78 = 0;
          uStack_70 = 0;
          local_88 = 0;
          uStack_80 = 0;
          local_90 = 0;
          init_wait_entry(&local_90,0);
          plVar1 = plVar10 + 5;
          lVar14 = prepare_to_wait_event(plVar1,&local_90,1);
          lVar13 = 0xfa;
          if (*(int *)((long)plVar10 + 0x24) != 2) {
            do {
              if (lVar14 != 0) goto LAB_00101a14;
              lVar13 = schedule_timeout(lVar13);
              lVar14 = prepare_to_wait_event(plVar1,&local_90,1);
              if (lVar13 == 0 && *(int *)((long)plVar10 + 0x24) == 2) {
                lVar13 = 1;
              }
            } while ((*(int *)((long)plVar10 + 0x24) != 2) && (lVar13 != 0));
          }
          lVar14 = lVar13;
          finish_wait(plVar1,&local_90);
LAB_00101a14:
          if ((int)lVar14 != 0) goto LAB_00101aec;
          pcVar9 = "remote side did not enter open state\n";
        }
        else {
          local_78 = 0;
          uStack_70 = 0;
          local_88 = 0;
          uStack_80 = 0;
          local_90 = 0;
          init_wait_entry(&local_90,0);
          plVar1 = plVar10 + 5;
          lVar13 = prepare_to_wait_event(plVar1,&local_90,1);
          if (*(int *)((long)plVar10 + 0x24) - 1U < 2) {
            lVar14 = 0xfa;
          }
          else {
            lVar14 = 0xfa;
            do {
              if (lVar13 != 0) goto LAB_001019ac;
              lVar14 = schedule_timeout(lVar14);
              lVar13 = prepare_to_wait_event(plVar1,&local_90,1);
              uVar4 = *(int *)((long)plVar10 + 0x24) - 1;
              if (lVar14 == 0 && uVar4 < 2) {
                lVar14 = 1;
              }
            } while ((lVar14 != 0 && *(int *)((long)plVar10 + 0x24) != 1) &&
                     (lVar14 == 0 || uVar4 != 1));
          }
          finish_wait(plVar1,&local_90);
          lVar13 = lVar14;
LAB_001019ac:
          if ((int)lVar13 != 0) goto LAB_001019b0;
          pcVar9 = "remote side did not enter opening state\n";
        }
        _dev_err(lVar12,pcVar9);
        qcom_smd_channel_set_state(plVar10,0);
      }
      plVar10[1] = 0;
      Hint_Prefetch(plVar11,2,0,1);
      do {
        iVar5 = (int)*plVar11;
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(plVar11,0x10);
        if (bVar3) {
          *(int *)plVar11 = iVar5 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      if (iVar5 == 1) {
        DataMemoryBarrier(2,1);
        kfree(plVar8);
      }
      else if (iVar5 < 1) {
        refcount_warn_saturate(plVar11,3);
      }
    }
    else {
      _dev_err(param_1,"channel %s is busy\n",plVar10[3]);
    }
  }
  plVar8 = (long *)0x0;
LAB_00101aec:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return plVar8;
}



//------------------------------------------------------------
// qcom_smd_announce_create @ 00101b40 size=120
// signature: undefined qcom_smd_announce_create(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_smd_announce_create(long param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  long *plVar3;
  
  plVar3 = *(long **)(*(long *)(param_1 + 0x3c8) + 0x60);
  uVar1 = _raw_spin_lock_irqsave(plVar3 + 0x12);
  uVar2 = qcom_smd_channel_intr(plVar3);
  _raw_spin_unlock_irqrestore(plVar3 + 0x12,uVar1);
  if ((uVar2 & 1) != 0) {
    queue_work_on(0x20,_system_wq,*plVar3 + 0x478);
  }
  return 0;
}



//------------------------------------------------------------
// qcom_smd_destroy_ept @ 00101bbc size=192
// signature: undefined qcom_smd_destroy_ept(void)
// callers: []
//------------------------------------------------------------

void qcom_smd_destroy_ept(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  
  lVar6 = *(long *)(param_1 + 0x60);
  lVar7 = *(long *)(lVar6 + 8);
  uVar5 = _raw_spin_lock_irqsave(lVar6 + 0x90);
  *(undefined8 *)(lVar7 + 0x10) = 0;
  _raw_spin_unlock_irqrestore(lVar6 + 0x90,uVar5);
  kfree(*(undefined8 *)(lVar6 + 0x88));
  *(undefined8 *)(lVar6 + 0x88) = 0;
  qcom_smd_channel_set_state(lVar6,0);
  qcom_smd_channel_reset(lVar6);
  piVar1 = (int *)(param_1 + 8);
  *(undefined8 *)(lVar6 + 8) = 0;
  Hint_Prefetch(piVar1,2,0,1);
  do {
    iVar2 = *piVar1;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar4) {
      *piVar1 = iVar2 + -1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (iVar2 == 1) {
    DataMemoryBarrier(2,1);
    kfree(param_1);
  }
  else if (iVar2 < 1) {
    refcount_warn_saturate(piVar1,3);
  }
  return;
}



//------------------------------------------------------------
// qcom_smd_send @ 00101c90 size=36
// signature: undefined qcom_smd_send(void)
// callers: []
//------------------------------------------------------------

void qcom_smd_send(long param_1,undefined8 param_2,undefined8 param_3)

{
  __qcom_smd_send(*(undefined8 *)(param_1 + 0x60),param_2,param_3,1);
  return;
}



//------------------------------------------------------------
// qcom_smd_sendto @ 00101cb8 size=36
// signature: undefined qcom_smd_sendto(void)
// callers: []
//------------------------------------------------------------

void qcom_smd_sendto(long param_1,undefined8 param_2,undefined8 param_3)

{
  __qcom_smd_send(*(undefined8 *)(param_1 + 0x60),param_2,param_3,1);
  return;
}



//------------------------------------------------------------
// qcom_smd_trysend @ 00101ce0 size=36
// signature: undefined qcom_smd_trysend(void)
// callers: []
//------------------------------------------------------------

void qcom_smd_trysend(long param_1,undefined8 param_2,undefined8 param_3)

{
  __qcom_smd_send(*(undefined8 *)(param_1 + 0x60),param_2,param_3,0);
  return;
}



//------------------------------------------------------------
// qcom_smd_trysendto @ 00101d08 size=36
// signature: undefined qcom_smd_trysendto(void)
// callers: []
//------------------------------------------------------------

void qcom_smd_trysendto(long param_1,undefined8 param_2,undefined8 param_3)

{
  __qcom_smd_send(*(undefined8 *)(param_1 + 0x60),param_2,param_3,0);
  return;
}



//------------------------------------------------------------
// qcom_smd_poll @ 00101d30 size=172
// signature: undefined qcom_smd_poll(void)
// callers: []
//------------------------------------------------------------

undefined4 qcom_smd_poll(long param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  uint *puVar3;
  long lVar4;
  int *piVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x60);
  if (param_3 != (undefined8 *)0x0) {
    pcVar2 = (code *)*param_3;
    if (lVar6 + 0x58 != 0 && pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != 0x7db4acb9) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x101d7c);
        (*pcVar2)();
      }
      (*pcVar2)(param_2,lVar6 + 0x58);
      DataMemoryBarrier(2,3);
    }
  }
  lVar4 = *(long *)(lVar6 + 0x48);
  if (lVar4 == 0) {
    puVar3 = (uint *)(*(long *)(lVar6 + 0x40) + 0x10);
    piVar5 = (int *)(*(long *)(lVar6 + 0x40) + 0xc);
  }
  else {
    puVar3 = (uint *)(lVar4 + 0x28);
    piVar5 = (int *)(lVar4 + 0x24);
  }
  uVar1 = 0x104;
  if ((*piVar5 + ~*puVar3 & *(int *)(lVar6 + 0x80) - 1U) < 0x15) {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_smd_channel_set_state @ 00101ddc size=276
// signature: undefined qcom_smd_channel_set_state(void)
// callers: [qcom_smd_destroy_ept, qcom_smd_create_ept]
//------------------------------------------------------------

void qcom_smd_channel_set_state(long *param_1,int param_2)

{
  bool bVar1;
  int *piVar2;
  long lVar3;
  
  bVar1 = param_2 == 2;
  if ((int)param_1[4] == param_2) {
    return;
  }
  if (param_1[9] == 0) {
    *(bool *)(param_1[8] + 4) = bVar1;
    lVar3 = param_1[9];
  }
  else {
    *(uint *)(param_1[9] + 4) = (uint)(param_2 == 2);
    lVar3 = param_1[9];
  }
  if (lVar3 == 0) {
    *(bool *)(param_1[8] + 5) = bVar1;
    lVar3 = param_1[9];
  }
  else {
    *(uint *)(lVar3 + 8) = (uint)(param_2 == 2);
    lVar3 = param_1[9];
  }
  if (lVar3 == 0) {
    *(bool *)(param_1[8] + 6) = bVar1;
    piVar2 = (int *)param_1[9];
  }
  else {
    *(uint *)(lVar3 + 0xc) = (uint)(param_2 == 2);
    piVar2 = (int *)param_1[9];
  }
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)param_1[8];
  }
  *piVar2 = param_2;
  if (param_1[9] == 0) {
    *(undefined1 *)(param_1[8] + 10) = 1;
  }
  else {
    *(undefined4 *)(param_1[9] + 0x1c) = 1;
  }
  lVar3 = *param_1;
  *(int *)(param_1 + 4) = param_2;
  if (*(long *)(lVar3 + 0x3f8) == 0) {
    regmap_write(*(undefined8 *)(lVar3 + 0x3b0),*(undefined4 *)(lVar3 + 0x3b8),
                 1L << ((ulong)*(uint *)(lVar3 + 0x3bc) & 0x3f));
  }
  else {
    mbox_send_message(*(long *)(lVar3 + 0x3f8),0);
    mbox_client_txdone(*(undefined8 *)(lVar3 + 0x3f8),0);
  }
  return;
}



//------------------------------------------------------------
// __qcom_smd_send @ 00101ef0 size=832
// signature: undefined __qcom_smd_send(void)
// callers: [qcom_smd_send, qcom_smd_sendto, qcom_smd_trysend, qcom_smd_trysendto]
//------------------------------------------------------------

ulong __qcom_smd_send(long *param_1,undefined8 param_2,uint param_3,uint param_4)

{
  long *plVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ulong uVar5;
  uint uVar6;
  long lVar7;
  uint *puVar8;
  int *piVar9;
  ulong uVar10;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  uint local_7c [5];
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  local_7c[1] = 0;
  local_7c[2] = 0;
  local_7c[3] = 0;
  local_7c[4] = 0;
  uVar6 = param_3;
  if (*(char *)((long)param_1 + 0xbc) != '\0') {
    uVar6 = param_3 + 0x14;
  }
  local_7c[0] = param_3;
  if ((((param_3 & 3) == 0) || (param_1[9] == 0)) && ((int)uVar6 < (int)param_1[0x10])) {
    plVar1 = param_1 + 10;
    uVar3 = _raw_spin_lock_irqsave(plVar1);
    uVar10 = (ulong)(int)uVar6;
    uVar4 = uVar3;
    while( true ) {
      lVar7 = param_1[9];
      if (lVar7 == 0) {
        puVar8 = (uint *)(param_1[8] + 0x10);
        piVar9 = (int *)(param_1[8] + 0xc);
      }
      else {
        puVar8 = (uint *)(lVar7 + 0x28);
        piVar9 = (int *)(lVar7 + 0x24);
      }
      iVar2 = (int)param_1[4];
      if (uVar10 <= (*piVar9 + ~*puVar8 & (int)param_1[0x10] - 1U)) break;
      if ((iVar2 != 2) || ((param_4 & 1) == 0)) {
        if (iVar2 != 2) {
          uVar3 = uVar4;
        }
        uVar6 = 0xfffffff5;
        if (iVar2 != 2) {
          uVar6 = 0xffffffe0;
        }
        uVar5 = (ulong)uVar6;
        uVar4 = uVar3;
        goto LAB_001021e4;
      }
      if (lVar7 == 0) {
        *(undefined1 *)(param_1[8] + 0xb) = 0;
      }
      else {
        *(undefined4 *)(lVar7 + 0x20) = 0;
      }
      _raw_spin_unlock_irqrestore(plVar1,uVar4);
      lVar7 = param_1[9];
      if (lVar7 == 0) {
        puVar8 = (uint *)(param_1[8] + 0x10);
        piVar9 = (int *)(param_1[8] + 0xc);
      }
      else {
        puVar8 = (uint *)(lVar7 + 0x28);
        piVar9 = (int *)(lVar7 + 0x24);
      }
      if (((*piVar9 + ~*puVar8 & (int)param_1[0x10] - 1U) < uVar10) && ((int)param_1[4] == 2)) {
        local_90 = 0;
        uStack_88 = 0;
        local_a0 = 0;
        uStack_98 = 0;
        local_a8 = 0;
        init_wait_entry(&local_a8,0);
        while( true ) {
          uVar5 = prepare_to_wait_event(param_1 + 0xb,&local_a8,1);
          lVar7 = param_1[9];
          if (lVar7 == 0) {
            puVar8 = (uint *)(param_1[8] + 0x10);
            piVar9 = (int *)(param_1[8] + 0xc);
          }
          else {
            puVar8 = (uint *)(lVar7 + 0x28);
            piVar9 = (int *)(lVar7 + 0x24);
          }
          if ((uVar10 <= (*piVar9 + ~*puVar8 & (int)param_1[0x10] - 1U)) || ((int)param_1[4] != 2))
          {
            finish_wait(param_1 + 0xb,&local_a8);
            goto LAB_00101fa0;
          }
          if (uVar5 != 0) break;
          schedule();
        }
        if ((int)uVar5 != 0) goto LAB_001021f0;
      }
LAB_00101fa0:
      uVar4 = _raw_spin_lock_irqsave(plVar1);
      if (param_1[9] == 0) {
        *(undefined1 *)(param_1[8] + 0xb) = 1;
      }
      else {
        *(undefined4 *)(param_1[9] + 0x20) = 1;
      }
    }
    if (iVar2 == 2) {
      if (lVar7 == 0) {
        *(undefined1 *)(param_1[8] + 9) = 0;
      }
      else {
        *(undefined4 *)(lVar7 + 0x18) = 0;
      }
      if (*(char *)((long)param_1 + 0xbc) != '\0') {
        qcom_smd_write_fifo(param_1,local_7c,0x14);
      }
      qcom_smd_write_fifo(param_1,param_2,(long)(int)param_3);
      if (param_1[9] == 0) {
        *(undefined1 *)(param_1[8] + 8) = 1;
      }
      else {
        *(undefined4 *)(param_1[9] + 0x14) = 1;
      }
      DataSynchronizationBarrier(3,2,0);
      lVar7 = *param_1;
      if (*(long *)(lVar7 + 0x3f8) == 0) {
        regmap_write(*(undefined8 *)(lVar7 + 0x3b0),*(undefined4 *)(lVar7 + 0x3b8),
                     1L << ((ulong)*(uint *)(lVar7 + 0x3bc) & 0x3f));
      }
      else {
        mbox_send_message(*(long *)(lVar7 + 0x3f8),0);
        mbox_client_txdone(*(undefined8 *)(lVar7 + 0x3f8),0);
      }
      uVar5 = 0;
    }
    else {
      uVar5 = 0xffffffe0;
    }
LAB_001021e4:
    _raw_spin_unlock_irqrestore(plVar1,uVar4);
  }
  else {
    uVar5 = 0xffffffea;
  }
LAB_001021f0:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_smd_write_fifo @ 00102230 size=276
// signature: undefined qcom_smd_write_fifo(void)
// callers: [__qcom_smd_send]
//------------------------------------------------------------

void qcom_smd_write_fifo(long param_1,long param_2,ulong param_3)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  uint *puVar6;
  ulong uVar7;
  
  lVar5 = *(long *)(param_1 + 0x48);
  if (lVar5 == 0) {
    puVar6 = (uint *)(*(long *)(param_1 + 0x40) + 0x10);
  }
  else {
    puVar6 = (uint *)(lVar5 + 0x28);
  }
  uVar2 = *puVar6;
  uVar7 = (ulong)(*(int *)(param_1 + 0x80) - uVar2);
  uVar4 = uVar7;
  if (param_3 <= uVar7) {
    uVar4 = param_3;
  }
  if (uVar4 == 0) {
    if (param_3 <= uVar7) goto LAB_00102300;
    uVar3 = *(undefined8 *)(param_1 + 0x70);
    uVar4 = param_3;
    if (lVar5 == 0) goto LAB_001022f8;
  }
  else {
    lVar1 = *(long *)(param_1 + 0x70) + (ulong)uVar2;
    if (lVar5 == 0) {
      __memcpy_toio(lVar1,param_2,uVar4);
      if (param_3 <= uVar7) goto LAB_00102300;
      uVar3 = *(undefined8 *)(param_1 + 0x70);
      param_2 = param_2 + uVar4;
      uVar4 = param_3 - uVar4;
LAB_001022f8:
      __memcpy_toio(uVar3,param_2,uVar4);
      goto LAB_00102300;
    }
    __iowrite32_copy(lVar1,param_2,uVar4 >> 2);
    if (param_3 <= uVar7) goto LAB_00102300;
    uVar3 = *(undefined8 *)(param_1 + 0x70);
    param_2 = param_2 + uVar4;
    uVar4 = param_3 - uVar4;
  }
  __iowrite32_copy(uVar3,param_2,uVar4 >> 2);
LAB_00102300:
  if (*(long *)(param_1 + 0x48) == 0) {
    puVar6 = (uint *)(*(long *)(param_1 + 0x40) + 0x10);
  }
  else {
    puVar6 = (uint *)(*(long *)(param_1 + 0x48) + 0x28);
  }
  *puVar6 = *(int *)(param_1 + 0x80) - 1U & uVar2 + (int)param_3;
  return;
}



//------------------------------------------------------------
// qcom_smd_channel_intr @ 00102344 size=1072
// signature: undefined qcom_smd_channel_intr(void)
// callers: [qcom_smd_edge_intr, qcom_smd_announce_create]
//------------------------------------------------------------

void qcom_smd_channel_intr(long *param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  uint *puVar6;
  uint uVar7;
  long lVar8;
  code *pcVar9;
  int *piVar10;
  uint uVar11;
  int *piVar12;
  undefined8 *puVar13;
  undefined4 local_4c;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  lVar5 = param_1[9];
  local_4c = 0;
  puVar13 = (undefined8 *)param_1[1];
  if (lVar5 == 0) {
    piVar10 = (int *)(param_1[8] + 0x14);
  }
  else {
    piVar10 = (int *)(lVar5 + 0x2c);
  }
  iVar1 = *piVar10;
  iVar2 = *(int *)((long)param_1 + 0x24);
  if (iVar1 != iVar2) {
    *(int *)((long)param_1 + 0x24) = iVar1;
    __wake_up(param_1 + 5,1,0,0);
    lVar5 = param_1[9];
  }
  if (lVar5 == 0) {
    *(undefined1 *)(param_1[8] + 0x1e) = 0;
    lVar5 = param_1[9];
    if (lVar5 == 0) goto LAB_00102458;
LAB_001023cc:
    if (*(int *)(lVar5 + 0x20) != 0) goto LAB_001023e8;
  }
  else {
    *(undefined4 *)(lVar5 + 0x48) = 0;
    lVar5 = param_1[9];
    if (lVar5 != 0) goto LAB_001023cc;
LAB_00102458:
    if (*(char *)(param_1[8] + 0xb) != '\0') goto LAB_001023e8;
  }
  __wake_up(param_1 + 0xb,1,0,0);
LAB_001023e8:
  if ((int)param_1[4] != 2) {
LAB_00102738:
    lVar5 = sp_el0;
    if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail(iVar1 != iVar2);
    }
    return;
  }
  lVar5 = param_1[9];
  if (lVar5 == 0) {
    lVar8 = param_1[8];
    uVar7 = (uint)*(byte *)(lVar8 + 5);
    uVar11 = (uint)(*(char *)(lVar8 + 0x18) != '\0') << 8 |
             (uint)(*(char *)(lVar8 + 0x19) != '\0') << 5 |
             (uint)(*(char *)(lVar8 + 0x1a) != '\0') << 6 |
             (uint)(*(char *)(lVar8 + 0x1b) != '\0') << 7 |
             (uint)(*(char *)(lVar8 + 4) != '\0') << 1;
  }
  else {
    uVar7 = *(uint *)(lVar5 + 8);
    uVar11 = (uint)(*(int *)(lVar5 + 0x30) != 0) << 8 | (uint)(*(int *)(lVar5 + 0x34) != 0) << 5 |
             (uint)(*(int *)(lVar5 + 0x38) != 0) << 6 | (uint)(*(int *)(lVar5 + 0x3c) != 0) << 7 |
             (uint)(*(int *)(lVar5 + 4) != 0) << 1;
  }
  pcVar9 = (code *)param_1[0x16];
  if (pcVar9 != (code *)0x0) {
    uVar11 = uVar11 | (uint)(uVar7 != 0) << 2;
    if (*(uint *)(param_1 + 0x17) != uVar11) {
      if (*(int *)(pcVar9 + -4) != -0x28f03d04) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8229,0x102504);
        (*pcVar9)();
      }
      (*pcVar9)(*puVar13,puVar13[10],*(uint *)(param_1 + 0x17),uVar11);
      lVar5 = param_1[9];
      *(uint *)(param_1 + 0x17) = uVar11;
    }
  }
  if (lVar5 == 0) {
    *(undefined1 *)(param_1[8] + 0x1c) = 0;
    lVar5 = param_1[9];
  }
  else {
    *(undefined4 *)(lVar5 + 0x40) = 0;
    lVar5 = param_1[9];
  }
joined_r0x00102530:
  if (lVar5 != 0) goto LAB_00102564;
LAB_00102570:
  piVar10 = (int *)(param_1[8] + 0x24);
  piVar12 = (int *)(param_1[8] + 0x20);
LAB_0010257c:
  uVar7 = *(uint *)(param_1 + 0x10) - 1 & *piVar10 - *piVar12;
  if (*(char *)((long)param_1 + 0xbc) == '\0') {
    if (0 < (int)uVar7) {
      bVar3 = false;
      *(uint *)((long)param_1 + 0x94) = uVar7;
      uVar11 = uVar7;
      goto LAB_001025e8;
    }
  }
  else {
    uVar11 = *(uint *)((long)param_1 + 0x94);
    bVar3 = uVar11 == 0;
    if ((uVar11 == 0) && (0x13 < (int)uVar7)) {
      qcom_smd_channel_peek(param_1,&local_4c,4);
      if (param_1[9] == 0) {
        puVar6 = (uint *)(param_1[8] + 0x20);
      }
      else {
        puVar6 = (uint *)(param_1[9] + 0x50);
      }
      *puVar6 = (int)param_1[0x10] - 1U & *puVar6 + 0x14;
      *(undefined4 *)((long)param_1 + 0x94) = local_4c;
      lVar5 = param_1[9];
      if (lVar5 == 0) goto LAB_00102570;
LAB_00102564:
      piVar10 = (int *)(lVar5 + 0x54);
      piVar12 = (int *)(lVar5 + 0x50);
      goto LAB_0010257c;
    }
LAB_001025e8:
    if ((!bVar3) && ((int)uVar11 <= (int)uVar7)) {
      if (lVar5 == 0) {
        puVar6 = (uint *)(param_1[8] + 0x20);
      }
      else {
        puVar6 = (uint *)(lVar5 + 0x50);
      }
      puVar13 = (undefined8 *)param_1[1];
      if (*puVar6 + uVar11 < *(uint *)(param_1 + 0x10)) {
        lVar5 = param_1[0xf] + (ulong)*puVar6;
      }
      else {
        lVar5 = param_1[0x11];
        qcom_smd_channel_peek(param_1,lVar5,(long)(int)uVar11);
      }
      if (*(int *)((code *)puVar13[2] + -4) != 0x505af011) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x10266c);
        (*pcVar9)();
      }
      iVar4 = (*(code *)puVar13[2])(*puVar13,lVar5,uVar11,puVar13[10],0xffffffff);
      lVar5 = param_1[9];
      if (iVar4 < 0) goto LAB_001026b8;
      if (lVar5 == 0) {
        puVar6 = (uint *)(param_1[8] + 0x20);
      }
      else {
        puVar6 = (uint *)(lVar5 + 0x50);
      }
      *puVar6 = (int)param_1[0x10] - 1U & *puVar6 + uVar11;
      *(undefined4 *)((long)param_1 + 0x94) = 0;
      lVar5 = param_1[9];
      goto joined_r0x00102530;
    }
  }
LAB_001026b8:
  if (lVar5 == 0) {
    *(undefined1 *)(param_1[8] + 0x1d) = 1;
    lVar5 = param_1[9];
    if (lVar5 == 0) goto LAB_001026ec;
LAB_001026cc:
    if (*(int *)(lVar5 + 0x4c) != 0) goto LAB_00102738;
  }
  else {
    *(undefined4 *)(lVar5 + 0x44) = 1;
    lVar5 = param_1[9];
    if (lVar5 != 0) goto LAB_001026cc;
LAB_001026ec:
    if (*(char *)(param_1[8] + 0x1f) != '\0') goto LAB_00102738;
  }
  DataSynchronizationBarrier(3,2,0);
  lVar5 = *param_1;
  if (*(long *)(lVar5 + 0x3f8) == 0) {
    regmap_write(*(undefined8 *)(lVar5 + 0x3b0),*(undefined4 *)(lVar5 + 0x3b8),
                 1L << ((ulong)*(uint *)(lVar5 + 0x3bc) & 0x3f));
  }
  else {
    mbox_send_message(*(long *)(lVar5 + 0x3f8),0);
    mbox_client_txdone(*(undefined8 *)(lVar5 + 0x3f8),0);
  }
  goto LAB_00102738;
}



//------------------------------------------------------------
// qcom_smd_channel_peek @ 00102774 size=236
// signature: undefined qcom_smd_channel_peek(void)
// callers: [qcom_smd_channel_intr]
//------------------------------------------------------------

ulong qcom_smd_channel_peek(long param_1,long param_2,ulong param_3)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  uint *puVar5;
  ulong uVar6;
  
  lVar4 = *(long *)(param_1 + 0x48);
  if (lVar4 == 0) {
    puVar5 = (uint *)(*(long *)(param_1 + 0x40) + 0x20);
  }
  else {
    puVar5 = (uint *)(lVar4 + 0x50);
  }
  uVar6 = (ulong)(*(int *)(param_1 + 0x80) - *puVar5);
  uVar3 = uVar6;
  if (param_3 <= uVar6) {
    uVar3 = param_3;
  }
  if (uVar3 == 0) {
    if (param_3 <= uVar6) {
      return param_3;
    }
    uVar2 = *(undefined8 *)(param_1 + 0x78);
    uVar3 = param_3;
    if (lVar4 == 0) goto LAB_0010283c;
  }
  else {
    lVar1 = *(long *)(param_1 + 0x78) + (ulong)*puVar5;
    if (lVar4 == 0) {
      __memcpy_fromio(param_2,lVar1,uVar3);
      if (param_3 <= uVar6) {
        return param_3;
      }
      param_2 = param_2 + uVar3;
      uVar2 = *(undefined8 *)(param_1 + 0x78);
      uVar3 = param_3 - uVar3;
LAB_0010283c:
      __memcpy_fromio(param_2,uVar2,uVar3);
      return param_3;
    }
    __ioread32_copy(param_2,lVar1,uVar3 >> 2);
    if (param_3 <= uVar6) {
      return param_3;
    }
    uVar2 = *(undefined8 *)(param_1 + 0x78);
    param_2 = param_2 + uVar3;
    uVar3 = param_3 - uVar3;
  }
  __ioread32_copy(param_2,uVar2,uVar3 >> 2);
  return param_3;
}



//------------------------------------------------------------
// qcom_smd_probe @ 00102864 size=132
// signature: undefined qcom_smd_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_smd_probe(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = qcom_smem_get(0xffffffff,0xd,0);
  if (lVar1 == -0x205) {
    uVar2 = 0xfffffdfb;
  }
  else {
    lVar1 = of_get_next_available_child(*(undefined8 *)(param_1 + 0x2f8),0);
    uVar2 = 0;
    if (lVar1 != 0) {
      do {
        qcom_smd_register_edge(param_1 + 0x10,lVar1);
        lVar1 = of_get_next_available_child(*(undefined8 *)(param_1 + 0x2f8),lVar1);
      } while (lVar1 != 0);
      uVar2 = 0;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// qcom_smd_remove @ 001028ec size=92
// signature: undefined qcom_smd_remove(void)
// callers: []
//------------------------------------------------------------

int qcom_smd_remove(long param_1)

{
  int iVar1;
  
  iVar1 = device_for_each_child(param_1 + 0x10,0,qcom_smd_remove_edge);
  if (iVar1 != 0) {
    _dev_warn(param_1 + 0x10,"can\'t remove smd device: %d\n",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// qcom_smd_remove_edge @ 0010294c size=32
// signature: undefined qcom_smd_remove_edge(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_smd_remove_edge(void)

{
  qcom_smd_unregister_edge();
  return 0;
}



//------------------------------------------------------------
// init_module @ 001029c0 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_smd_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001029f0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_smd_driver);
  return;
}



//------------------------------------------------------------
// mbox_send_message @ 00105000 size=1
// signature: undefined mbox_send_message(void)
// callers: [qcom_smd_channel_reset, __qcom_smd_send, qcom_smd_channel_set_state, qcom_smd_set_sigs, qcom_smd_channel_intr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_send_message(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_client_txdone @ 00105008 size=1
// signature: undefined mbox_client_txdone(void)
// callers: [qcom_smd_channel_reset, __qcom_smd_send, qcom_smd_channel_set_state, qcom_smd_set_sigs, qcom_smd_channel_intr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_client_txdone(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 00105010 size=1
// signature: undefined regmap_write(void)
// callers: [qcom_smd_channel_reset, __qcom_smd_send, qcom_smd_channel_set_state, qcom_smd_set_sigs, qcom_smd_channel_intr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00105020 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qcom_smd_create_ept, qcom_channel_state_worker, qcom_channel_scan_worker, qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00105028 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [qcom_channel_scan_worker, qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 00105030 size=1
// signature: undefined dev_set_name(void)
// callers: [qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_register @ 00105038 size=1
// signature: undefined device_register(void)
// callers: [qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00105040 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_request_channel @ 00105048 size=1
// signature: undefined mbox_request_channel(void)
// callers: [qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_request_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00105050 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// syscon_node_to_regmap @ 00105058 size=1
// signature: undefined syscon_node_to_regmap(void)
// callers: [qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void syscon_node_to_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 00105060 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00105068 size=1
// signature: undefined of_property_read_string(void)
// callers: [qcom_channel_state_worker, qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_of_parse_and_map @ 00105070 size=1
// signature: undefined irq_of_parse_and_map(void)
// callers: [qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_of_parse_and_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00105078 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmsg_register_device_override @ 00105080 size=1
// signature: undefined rpmsg_register_device_override(void)
// callers: [qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmsg_register_device_override(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00105090 size=1
// signature: undefined queue_work_on(void)
// callers: [qcom_smd_edge_intr, qcom_smd_announce_create, qcom_channel_scan_worker, qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00105098 size=1
// signature: undefined _printk(void)
// callers: [qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 001050a0 size=1
// signature: undefined put_device(void)
// callers: [qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001050a8 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_smd_create_ept, qcom_channel_scan_worker, qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_free_channel @ 001050b0 size=1
// signature: undefined mbox_free_channel(void)
// callers: [qcom_smd_unregister_edge, qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_free_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_unregister @ 001050b8 size=1
// signature: undefined device_unregister(void)
// callers: [qcom_smd_unregister_edge, qcom_smd_remove_device, qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001050c0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [__qcom_smd_send, qcom_smd_create_ept, qcom_channel_state_worker, qcom_channel_scan_worker, qcom_smd_channel_intr, qcom_smd_register_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// synchronize_rcu @ 001050c8 size=1
// signature: undefined synchronize_rcu(void)
// callers: [qcom_smd_edge_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void synchronize_rcu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001050d0 size=1
// signature: undefined kfree(void)
// callers: [qcom_smd_destroy_ept, qcom_smd_release_device, qcom_smd_edge_release, qcom_smd_create_ept, qcom_channel_scan_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 001050d8 size=1
// signature: undefined __wake_up(void)
// callers: [qcom_smd_edge_release, qcom_channel_scan_worker, qcom_smd_channel_intr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001050e0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qcom_smd_edge_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 001050e8 size=1
// signature: undefined disable_irq(void)
// callers: [qcom_smd_unregister_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 001050f0 size=1
// signature: undefined cancel_work_sync(void)
// callers: [qcom_smd_unregister_edge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_for_each_child @ 001050f8 size=1
// signature: undefined device_for_each_child(void)
// callers: [qcom_smd_unregister_edge, qcom_smd_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_for_each_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 00105100 size=1
// signature: undefined _dev_warn(void)
// callers: [qcom_smd_unregister_edge, qcom_smd_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00105108 size=1
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
// platform_driver_unregister @ 00105110 size=1
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
// sprintf @ 00105118 size=1
// signature: int sprintf(char * __s, char * __format, ...)
// callers: [rpmsg_name_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_get @ 00105120 size=1
// signature: undefined qcom_smem_get(void)
// callers: [qcom_smd_probe, qcom_channel_scan_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrdup @ 00105128 size=1
// signature: undefined kstrdup(void)
// callers: [qcom_channel_scan_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00105130 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [__qcom_smd_send, qcom_smd_destroy_ept, qcom_smd_announce_create, qcom_smd_create_ept, qcom_channel_state_worker, qcom_channel_scan_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00105138 size=1
// signature: undefined __list_add_valid(void)
// callers: [qcom_channel_scan_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00105140 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [__qcom_smd_send, qcom_smd_destroy_ept, qcom_smd_announce_create, qcom_smd_create_ept, qcom_channel_state_worker, qcom_channel_scan_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00105150 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [qcom_smd_create_ept, qcom_channel_state_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy_pad @ 00105158 size=1
// signature: undefined strscpy_pad(void)
// callers: [qcom_channel_state_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy_pad(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 00105160 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [qcom_smd_probe, qcom_channel_state_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmsg_register_device @ 00105168 size=1
// signature: undefined rpmsg_register_device(void)
// callers: [qcom_channel_state_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmsg_register_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmsg_unregister_device @ 00105170 size=1
// signature: undefined rpmsg_unregister_device(void)
// callers: [qcom_channel_state_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmsg_unregister_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00105178 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [qcom_smd_edge_intr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00105180 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [qcom_smd_edge_intr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_get_free_space @ 00105188 size=1
// signature: undefined qcom_smem_get_free_space(void)
// callers: [qcom_smd_edge_intr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_get_free_space(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00105190 size=1
// signature: undefined init_wait_entry(void)
// callers: [__qcom_smd_send, qcom_smd_create_ept]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00105198 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [__qcom_smd_send, qcom_smd_create_ept]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 001051a0 size=1
// signature: undefined schedule_timeout(void)
// callers: [qcom_smd_create_ept]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 001051a8 size=1
// signature: undefined finish_wait(void)
// callers: [__qcom_smd_send, qcom_smd_create_ept]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001051b0 size=1
// signature: undefined __kmalloc(void)
// callers: [qcom_smd_create_ept]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 001051b8 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [qcom_smd_destroy_ept, qcom_smd_create_ept]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 001051c0 size=1
// signature: undefined schedule(void)
// callers: [__qcom_smd_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __iowrite32_copy @ 001051c8 size=1
// signature: undefined __iowrite32_copy(void)
// callers: [qcom_smd_write_fifo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __iowrite32_copy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_toio @ 001051d0 size=1
// signature: undefined __memcpy_toio(void)
// callers: [qcom_smd_write_fifo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_toio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __ioread32_copy @ 001051d8 size=1
// signature: undefined __ioread32_copy(void)
// callers: [qcom_smd_channel_peek]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __ioread32_copy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_fromio @ 001051e0 size=1
// signature: undefined __memcpy_fromio(void)
// callers: [qcom_smd_channel_peek]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_fromio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



