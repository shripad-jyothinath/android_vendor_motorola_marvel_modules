// Decompiled by Ghidra 12.2
// Program: gunyah_loader.ko
// Image base: 00100000

//------------------------------------------------------------
// gh_register_vm_notifier @ 00102604 size=40
// signature: undefined gh_register_vm_notifier(void)
// callers: []
//------------------------------------------------------------

void gh_register_vm_notifier(undefined8 param_1)

{
  srcu_notifier_chain_register(&gh_vm_notifier,param_1);
  return;
}



//------------------------------------------------------------
// gh_unregister_vm_notifier @ 00102630 size=40
// signature: undefined gh_unregister_vm_notifier(void)
// callers: []
//------------------------------------------------------------

void gh_unregister_vm_notifier(undefined8 param_1)

{
  srcu_notifier_chain_unregister(&gh_vm_notifier,param_1);
  return;
}



//------------------------------------------------------------
// gh_destroy_vcpu @ 0010265c size=76
// signature: undefined gh_destroy_vcpu(void)
// callers: []
//------------------------------------------------------------

void gh_destroy_vcpu(uint *param_1)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 2);
  uVar1 = *param_1;
  kfree();
  if (7 < uVar1) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1026a8);
    (*pcVar3)();
  }
  iVar2 = *(int *)(lVar4 + 8);
  *(undefined8 *)(lVar4 + (ulong)uVar1 * 8 + 0x18) = 0;
  *(int *)(lVar4 + 8) = iVar2 + -1;
  return;
}



//------------------------------------------------------------
// gh_destroy_vm @ 001026ac size=760
// signature: undefined gh_destroy_vm(void)
// callers: [gh_vcpu_release, gh_vm_release, gh_dev_ioctl]
//------------------------------------------------------------

int gh_destroy_vm(char *param_1)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  undefined2 uVar4;
  code *pcVar5;
  bool bVar6;
  int iVar7;
  uint *puVar8;
  undefined8 uVar9;
  char *pcVar10;
  ulong uVar11;
  long lVar12;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar12 = sp_el0;
  local_48 = *(long *)(lVar12 + 0x638);
  if (param_1[0x80] != '\0') {
    pcVar10 = param_1 + 0x10;
    uVar4 = *(undefined2 *)pcVar10;
    if ((param_1[4] == '\0') || ((uVar9 = 1, param_1[2] != '\0' && (param_1[0x80] == '\x03')))) {
      uVar9 = 0;
    }
    iVar7 = gh_exit_vm(param_1,1,uVar9);
    if (iVar7 == -0x13) goto LAB_001028dc;
    if ((iVar7 != 0) && (iVar7 = gh_exit_vm(param_1,3,1), iVar7 != 0)) {
      _printk(&DAT_0010f322,uVar4);
      goto LAB_001028dc;
    }
    if (*(int *)(param_1 + 8) != 0) {
      uVar11 = 0;
      do {
        puVar8 = *(uint **)(param_1 + uVar11 * 8 + 0x18);
        if (puVar8 == (uint *)0x0) {
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        lVar12 = *(long *)(puVar8 + 2);
        uVar1 = *puVar8;
        kfree();
        if (7 < uVar1) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x1029a0);
          (*pcVar5)();
        }
        iVar7 = *(int *)(lVar12 + 8);
        *(undefined8 *)(lVar12 + (ulong)uVar1 * 8 + 0x18) = 0;
        *(int *)(lVar12 + 8) = iVar7 + -1;
      } while ((*(int *)(param_1 + 8) != 0) && (bVar6 = uVar11 < 7, uVar11 = uVar11 + 1, bVar6));
    }
    bVar2 = param_1[0x80];
    if (bVar2 < 10) {
      uVar4 = *(undefined2 *)(param_1 + 0x10);
      uVar1 = 1 << (ulong)(bVar2 & 0x1f);
      if ((uVar1 & 0x20c) == 0) {
        if ((uVar1 & 0x42) != 0) goto LAB_001027f4;
        if (bVar2 != 5) goto LAB_0010289c;
      }
      else {
        srcu_notifier_call_chain(&gh_vm_notifier,5,pcVar10);
        iVar7 = gh_rm_unpopulate_hyp_res(uVar4,param_1 + 0x58);
        if (iVar7 != 0) {
          _printk(&DAT_0010d9ca,iVar7);
        }
LAB_001027f4:
        iVar7 = ghd_rm_vm_reset(uVar4);
        if (iVar7 == 0) {
          if (param_1[0x80] != '\v') {
            local_58 = 0;
            uStack_50 = 0;
            local_68 = 0;
            uStack_60 = 0;
            local_70 = 0;
            init_wait_entry(&local_70,0);
            while (prepare_to_wait_event(param_1 + 0x88,&local_70,2), param_1[0x80] != '\v') {
              schedule();
            }
            finish_wait(param_1 + 0x88,&local_70);
          }
        }
        else {
          _printk(&DAT_0010e8b3,uVar4);
        }
        srcu_notifier_call_chain(&gh_vm_notifier,3,pcVar10);
        iVar7 = gh_virtio_mmio_exit(uVar4,param_1 + 0x58);
        if (iVar7 == 0) {
          cVar3 = *param_1;
        }
        else {
          _printk(&DAT_0010f3f3,iVar7);
          cVar3 = *param_1;
        }
        if ((cVar3 != '\0') && (iVar7 = gh_secure_vm_loader_reclaim_fw(param_1), iVar7 != 0)) {
          _printk(&DAT_0010f032,uVar4,iVar7);
        }
      }
      iVar7 = gh_rm_vm_dealloc_vmid(uVar4);
      if (iVar7 != 0) {
        _printk(&DAT_0010ea54,uVar4,iVar7);
      }
    }
LAB_0010289c:
    param_1[0x80] = '\0';
    srcu_notifier_call_chain(&gh_vm_notifier,4,pcVar10);
    gh_uevent_notify_change(1,param_1);
    param_1[0x58] = '\0';
    param_1[0x59] = '\0';
    param_1[0x5a] = '\0';
    param_1[0x5b] = '\0';
    param_1[0x5c] = '\0';
    param_1[0x5d] = '\0';
    param_1[0x5e] = '\0';
    param_1[0x5f] = '\0';
    param_1[0x60] = '\0';
    param_1[0x61] = '\0';
    param_1[0x62] = '\0';
    param_1[99] = '\0';
    param_1[100] = '\0';
    param_1[0x65] = '\0';
    param_1[0x66] = '\0';
    param_1[0x67] = '\0';
    param_1[0x10] = '\0';
    param_1[0x11] = '\0';
  }
  gh_rm_unregister_notifier(param_1 + 0x68);
  kfree(param_1);
  iVar7 = 0;
LAB_001028dc:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// gh_uevent_notify_change @ 001029a8 size=224
// signature: undefined gh_uevent_notify_change(void)
// callers: [gh_destroy_vm, gh_vm_ioctl_set_fw_name]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gh_uevent_notify_change(int param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  
  lVar3 = kmalloc_trace(___wake_up,0x400dc0,0xa20);
  if (lVar3 != 0) {
    if (param_1 == 1) {
      add_uevent_var(lVar3,"EVENT=destroy");
      add_uevent_var(lVar3,"vm_exit=%d",*(undefined4 *)(param_2 + 0xa0));
    }
    else if (param_1 == 0) {
      add_uevent_var(lVar3,"EVENT=create");
    }
    add_uevent_var(lVar3,"vm_name=%s",param_2 + 0x58);
    uVar1 = *(uint *)(lVar3 + 0x218);
    *(uint *)(lVar3 + 0x218) = uVar1 + 1;
    if (0x3f < uVar1) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x102a88);
      (*pcVar2)();
    }
    *(undefined8 *)(lVar3 + 0x18 + (ulong)uVar1 * 8) = 0;
    kobject_uevent_env(gh_dev._48_8_,2);
    kfree(lVar3);
  }
  return;
}



//------------------------------------------------------------
// gh_reclaim_mem @ 00102a8c size=392
// signature: undefined gh_reclaim_mem(void)
// callers: [gh_secure_vm_loader_reclaim_fw]
//------------------------------------------------------------

uint gh_reclaim_mem(long param_1,undefined8 param_2,undefined8 param_3,ulong param_4)

{
  char cVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  long local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  uVar6 = (ulong)*(ushort *)(param_1 + 0x10);
  local_60 = 1L << (uVar6 & 0x3f);
  uStack_50 = 0x700000003;
  local_58 = param_2;
  if (((param_4 & 1) == 0) &&
     (iVar3 = ghd_rm_mem_reclaim(*(undefined4 *)(param_1 + 0xa8),0), iVar3 != 0)) {
    _printk(&DAT_0010ecf1,*(undefined2 *)(param_1 + 0x10),iVar3);
  }
  uVar4 = qcom_scm_assign_mem(param_2,param_3,&local_60,&uStack_50,1);
  if (uVar4 == 0) {
    cVar1 = *(char *)(param_1 + 0xb8);
  }
  else {
    _printk(&DAT_0010df86,&local_58,param_3,uVar6,uVar4);
    cVar1 = *(char *)(param_1 + 0xb8);
  }
  if (cVar1 != '\0') {
    if ((param_4 & 1) == 0) {
      uVar5 = ghd_rm_mem_reclaim(*(undefined4 *)(*(long *)(param_1 + 0xb0) + 0x18),0);
      uVar4 = 0;
      if (uVar5 != 0) {
        _printk(&DAT_0010ecf1,*(undefined2 *)(param_1 + 0x10),uVar5);
        uVar4 = uVar5;
      }
    }
    uVar5 = qcom_scm_assign_mem(*(undefined8 *)(*(long *)(param_1 + 0xb0) + 8),
                                *(undefined8 *)(*(long *)(param_1 + 0xb0) + 0x10),&local_60,
                                &uStack_50,1);
    uVar4 = uVar5 | uVar4;
    if (uVar4 != 0) {
      _printk(&DAT_0010df86,*(long *)(param_1 + 0xb0) + 8,
              *(undefined8 *)(*(long *)(param_1 + 0xb0) + 0x10),uVar6,uVar4);
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



//------------------------------------------------------------
// gh_provide_mem @ 00102c18 size=536
// signature: undefined gh_provide_mem(void)
// callers: [gh_vm_ioctl_set_fw_name]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int gh_provide_mem(long param_1,undefined8 param_2,undefined8 param_3,ulong param_4)

{
  char cVar1;
  ushort uVar2;
  long lVar3;
  undefined8 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  ulong uVar10;
  long local_90 [3];
  uint local_78 [2];
  ulong local_70;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  uVar2 = *(ushort *)(param_1 + 0x10);
  uVar10 = (ulong)uVar2;
  local_90[1] = 8;
  local_70 = 0x700000003;
  local_90[0] = 1L << (uVar10 & 0x3f);
  local_78[0] = (uint)uVar2;
  local_78[1] = 7;
  local_90[2] = param_2;
  puVar6 = (undefined4 *)kmalloc_trace(_gh_rm_mem_donate,0xdc0,8);
  if (puVar6 == (undefined4 *)0x0) {
    iVar5 = -0xc;
    goto LAB_00102df0;
  }
  *puVar6 = 1;
  uVar4 = _gh_rm_mem_donate;
  *(ushort *)(puVar6 + 1) = uVar2;
  *(undefined1 *)((long)puVar6 + 6) = 7;
  puVar7 = (undefined4 *)kmalloc_trace(uVar4,0xdc0,0x14);
  if (puVar7 == (undefined4 *)0x0) {
    iVar5 = -0xc;
  }
  else {
    cVar1 = *(char *)(param_1 + 0xb8);
    *(undefined8 *)(puVar7 + 1) = param_2;
    *(undefined8 *)(puVar7 + 3) = param_3;
    *(undefined2 *)puVar7 = 1;
    if (cVar1 != '\0') {
      local_78[1] = 4;
      *(undefined1 *)((long)puVar6 + 6) = 4;
    }
    iVar5 = qcom_scm_assign_mem(param_2,param_3,local_90 + 1,local_78,1);
    if (iVar5 == 0) {
      if ((param_4 & 1) == 0) {
        if (*(char *)(param_1 + 0xb8) == '\0') {
          puVar9 = (undefined4 *)(param_1 + 0xa8);
          uVar8 = 0;
        }
        else {
          puVar9 = *(undefined4 **)(param_1 + 0xb0) + 6;
          uVar8 = **(undefined4 **)(param_1 + 0xb0);
        }
        iVar5 = ghd_rm_mem_lend(0,0,uVar8,puVar6,puVar7,0,puVar9);
        if (iVar5 != 0) goto LAB_00102d2c;
      }
      else {
        iVar5 = gh_rm_mem_donate(0,0,0,puVar6,puVar7,0,param_1 + 0xa8);
        if (iVar5 != 0) {
LAB_00102d2c:
          iVar5 = qcom_scm_assign_mem(param_2,param_3,local_90,&local_70,1);
          if (iVar5 != 0) {
            uVar10 = local_70 & 0xffffffff;
            goto LAB_00102dd8;
          }
          goto LAB_00102de0;
        }
      }
      iVar5 = 0;
    }
    else {
LAB_00102dd8:
      _printk(&DAT_0010df86,local_90 + 2,param_3,uVar10,iVar5);
    }
LAB_00102de0:
    kfree(puVar6);
    puVar6 = puVar7;
  }
  kfree(puVar6);
LAB_00102df0:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// gh_vm_configure @ 00102e34 size=516
// signature: undefined gh_vm_configure(void)
// callers: [gh_vm_ioctl_set_fw_name]
//------------------------------------------------------------

long gh_vm_configure(short param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined8 param_5,int param_6,undefined8 param_7,char *param_8)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  undefined2 uVar4;
  long lVar5;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_40 = 0;
  if (param_1 == 1) {
    iVar2 = gh_rm_vm_config_image
                      (*(undefined2 *)(param_8 + 0x10),1,*(undefined4 *)(param_8 + 0xa8),param_2,
                       param_3,param_4,param_5);
    if (iVar2 == 0) {
      param_8[0x80] = '\x06';
      if (param_6 == 0) {
        _printk(&DAT_0010e2de,0,*(undefined2 *)(param_8 + 0x10));
        lVar5 = -0x16;
        goto LAB_00103004;
      }
      local_40 = CONCAT44(param_6,(undefined4)local_40);
      iVar2 = gh_rm_vm_auth_image(*(undefined2 *)(param_8 + 0x10),1,&local_40);
      if (iVar2 == 0) {
        param_8[0x80] = '\x01';
        iVar2 = ghd_rm_vm_init(*(undefined2 *)(param_8 + 0x10));
        if (iVar2 == 0) {
          if (param_8[0x80] != '\x02') {
            local_50 = 0;
            uStack_48 = 0;
            local_60 = 0;
            uStack_58 = 0;
            local_68 = 0;
            init_wait_entry(&local_68,0);
            while( true ) {
              prepare_to_wait_event(param_8 + 0x88,&local_68,2);
              if (param_8[0x80] == '\x02') break;
              schedule();
            }
            finish_wait(param_8 + 0x88,&local_68);
          }
          iVar2 = gh_rm_populate_hyp_res(*(undefined2 *)(param_8 + 0x10),param_7);
          lVar5 = (long)iVar2;
          if (iVar2 < 0) {
            _printk(&DAT_0010e6de,lVar5);
          }
          else if (*param_8 != '\0') {
            iVar2 = gh_get_nr_vcpus(*(undefined2 *)(param_8 + 0x10));
            if (iVar2 < 0) {
              _printk(&DAT_0010e241,*(undefined2 *)(param_8 + 0x10),iVar2);
              lVar5 = (long)iVar2;
            }
            else {
              if (iVar2 == 0) {
                iVar2 = 1;
              }
              *(int *)(param_8 + 0xc) = iVar2;
            }
          }
          goto LAB_00103004;
        }
        uVar4 = *(undefined2 *)(param_8 + 0x10);
        lVar5 = (long)iVar2;
        puVar3 = &DAT_0010dfde;
      }
      else {
        uVar4 = *(undefined2 *)(param_8 + 0x10);
        lVar5 = (long)iVar2;
        puVar3 = &DAT_0010dafe;
      }
    }
    else {
      lVar5 = (long)iVar2;
      uVar4 = *(undefined2 *)(param_8 + 0x10);
      puVar3 = &DAT_0010e6ae;
    }
    _printk(puVar3,uVar4,lVar5);
  }
  else {
    _printk(&DAT_0010f69f);
    lVar5 = -0x16;
  }
LAB_00103004:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar5;
}



//------------------------------------------------------------
// gh_exit_vm @ 00103038 size=372
// signature: undefined gh_exit_vm(void)
// callers: [gh_destroy_vm]
//------------------------------------------------------------

int gh_exit_vm(long param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  short sVar2;
  int iVar3;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  sVar2 = *(short *)(param_1 + 0x10);
  if (sVar2 == 0) {
    iVar3 = -0x13;
  }
  else {
    lVar1 = param_1 + 0xc0;
    mutex_lock(lVar1);
    if (*(char *)(param_1 + 0x80) == '\x03') {
      iVar3 = ghd_rm_vm_stop(sVar2,param_2,param_3);
      if (iVar3 != 0) {
        _printk(&DAT_0010d998,sVar2,iVar3);
        mutex_unlock(lVar1);
        goto LAB_0010310c;
      }
      mutex_unlock(lVar1);
      if (*(char *)(param_1 + 0x80) != '\t') {
        local_58 = 0;
        uStack_50 = 0;
        local_68 = 0;
        uStack_60 = 0;
        local_70 = 0;
        init_wait_entry(&local_70,0);
        while( true ) {
          prepare_to_wait_event(param_1 + 0x88,&local_70,2);
          if (*(char *)(param_1 + 0x80) == '\t') break;
          schedule();
        }
        finish_wait(param_1 + 0x88,&local_70);
      }
    }
    else {
      if (*(char *)(param_1 + 0x80) != '\t') {
        _printk(&DAT_0010ef3c,sVar2);
        mutex_unlock(lVar1);
        iVar3 = -0x13;
        goto LAB_0010310c;
      }
      _printk(&DAT_0010e012,sVar2);
      mutex_unlock(lVar1);
    }
    iVar3 = 0;
  }
LAB_0010310c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// gh_dev_ioctl @ 001031b0 size=468
// signature: undefined gh_dev_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong gh_dev_ioctl(undefined8 param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  
  if (param_2 == 0xb201) {
    uVar6 = kmalloc_trace(_gh_rm_vm_config_image,0xdc0,0xf0);
    if ((uVar6 == 0) || (lVar7 = kmalloc_trace(_gh_rm_mem_donate,0xdc0,0x20), lVar7 == 0)) {
      uVar6 = 0xfffffffffffffff4;
    }
    else {
      *(long *)(uVar6 + 0xb0) = lVar7;
      __mutex_init(uVar6 + 0xc0,"&vm->vm_lock",&gh_create_vm___key);
      *(code **)(uVar6 + 0x68) = gh_vm_rm_notifier_fn;
      *(undefined4 *)(uVar6 + 0x78) = 1;
      iVar4 = gh_rm_register_notifier();
      if (iVar4 == 0) {
        *(undefined4 *)(uVar6 + 0xa4) = 1;
        __init_waitqueue_head(uVar6 + 0x88,"&vm->vm_status_wait",&gh_create_vm___key_28);
        *(undefined1 *)(uVar6 + 0x80) = 0;
        *(undefined4 *)(uVar6 + 0xa0) = 0xffffffea;
      }
      else {
        kfree(uVar6);
        uVar6 = (ulong)iVar4;
      }
      if (uVar6 < 0xfffffffffffff001) {
        uVar5 = get_unused_fd_flags(0x80000);
        uVar9 = (ulong)uVar5;
        if (-1 < (int)uVar5) {
          uVar8 = anon_inode_getfile("gunyah-vm",gh_vm_fops,uVar6,2);
          if (uVar8 < 0xfffffffffffff001) {
            fd_install(uVar9,uVar8);
            return uVar9;
          }
          put_unused_fd(uVar9);
          uVar5 = (uint)uVar8;
        }
        piVar1 = (int *)(uVar6 + 0xa4);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar4 = *piVar1;
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar3) {
            *piVar1 = iVar4 + -1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        if (iVar4 == 1) {
          DataMemoryBarrier(2,1);
          iVar4 = gh_destroy_vm(uVar6);
          if (iVar4 != 0) {
            _printk(&DAT_0010e811,*(undefined2 *)(uVar6 + 0x10),iVar4);
          }
        }
        else if (iVar4 < 1) {
          refcount_warn_saturate(piVar1,3);
        }
        uVar6 = (ulong)(int)uVar5;
      }
    }
  }
  else {
    _printk(&DAT_0010eeaa);
    uVar6 = 0xffffffffffffffea;
  }
  return uVar6;
}



//------------------------------------------------------------
// gh_vm_rm_notifier_fn @ 00103398 size=324
// signature: undefined gh_vm_rm_notifier_fn(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_vm_rm_notifier_fn(long param_1,long param_2,short *param_3)

{
  char cVar1;
  undefined1 uVar2;
  
  if (param_2 == 0x56100001) {
    if (*(short *)(param_1 + -0x58) != *param_3) {
      return 0;
    }
    mutex_lock(param_1 + 0x58);
    *(uint *)(param_1 + 0x38) = (uint)(ushort)param_3[1];
    if ((ushort)param_3[1] - 4 < 3) {
      srcu_notifier_call_chain(&gh_vm_notifier,6,(short *)(param_1 + -0x58));
    }
    *(undefined1 *)(param_1 + 0x18) = 9;
    gh_wakeup_all_vcpus(*(undefined2 *)(param_1 + -0x58));
    __wake_up(param_1 + 0x20,3,1,0);
    mutex_unlock(param_1 + 0x58);
    return 0;
  }
  if (param_2 != 0x56100008) {
    return 0;
  }
  if (*(short *)(param_1 + -0x58) != *param_3) {
    return 0;
  }
  cVar1 = (char)param_3[2];
  if (cVar1 == *(char *)(param_1 + 0x18)) {
    return 0;
  }
  if (cVar1 != '\x02') {
    if (cVar1 == '\f') {
      _printk(&DAT_0010e5a3);
      uVar2 = 0xb;
      goto LAB_001034c0;
    }
    if (cVar1 != '\v') {
      return 0;
    }
  }
  _printk(&DAT_0010e8e5);
  uVar2 = (undefined1)param_3[2];
LAB_001034c0:
  *(undefined1 *)(param_1 + 0x18) = uVar2;
  __wake_up(param_1 + 0x20,3,1,0);
  return 0;
}



//------------------------------------------------------------
// gh_vm_ioctl @ 001034e0 size=584
// signature: undefined gh_vm_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gh_vm_ioctl(long param_1,undefined8 param_2,ulong param_3)

{
  char *pcVar1;
  uint *puVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  uint *puVar8;
  ulong uVar9;
  int iVar10;
  undefined8 uVar11;
  char *pcVar12;
  uint uVar13;
  char local_60 [24];
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  pcVar12 = *(char **)(param_1 + 0xd8);
  iVar10 = (int)param_2;
  if (0xb242 < iVar10) {
    if (iVar10 == 0xb243) {
      if (*pcVar12 != '\0') {
        if (pcVar12[0x80] == '\x02') {
          uVar7 = (ulong)*(int *)(pcVar12 + 0xc);
        }
        else {
          uVar7 = 0xfffffffffffffff5;
        }
        goto LAB_001036d4;
      }
LAB_001035d8:
      uVar7 = 0xffffffffffffffea;
      goto LAB_001036d4;
    }
    if (iVar10 == 0x4010b241) {
      uVar7 = gh_vm_ioctl_set_fw_name(pcVar12,param_3);
      goto LAB_001036d4;
    }
LAB_0010359c:
    uVar7 = gh_virtio_backend_ioctl(pcVar12 + 0x58,param_2,param_3);
    goto LAB_001036d4;
  }
  if (iVar10 == -0x7fef4dbe) {
    uVar7 = gh_vm_ioctl_get_fw_name(pcVar12,param_3);
    goto LAB_001036d4;
  }
  if (iVar10 != 0xb240) goto LAB_0010359c;
  uVar13 = (uint)param_3;
  local_60[0x10] = '\0';
  local_60[0x11] = '\0';
  local_60[0x12] = '\0';
  local_60[0x13] = '\0';
  local_60[0] = '\0';
  local_60[1] = '\0';
  local_60[2] = '\0';
  local_60[3] = '\0';
  local_60[4] = '\0';
  local_60[5] = '\0';
  local_60[6] = '\0';
  local_60[7] = '\0';
  local_60[8] = '\0';
  local_60[9] = '\0';
  local_60[10] = '\0';
  local_60[0xb] = '\0';
  local_60[0xc] = '\0';
  local_60[0xd] = '\0';
  local_60[0xe] = '\0';
  local_60[0xf] = '\0';
  if (7 < uVar13) goto LAB_001035d8;
  pcVar1 = pcVar12 + 0xc0;
  mutex_lock(pcVar1);
  if (*(long *)(pcVar12 + (param_3 & 0xffffffff) * 8 + 0x18) != 0) {
    mutex_unlock(pcVar1);
    uVar7 = 0xffffffffffffffef;
    goto LAB_001036d4;
  }
  puVar8 = (uint *)kmalloc_trace(_gh_rm_mem_donate,0xdc0,0x10);
  if (puVar8 == (uint *)0x0) {
    mutex_unlock(pcVar1);
    uVar7 = 0xfffffffffffffff4;
    goto LAB_001036d4;
  }
  *puVar8 = uVar13;
  *(char **)(puVar8 + 2) = pcVar12;
  uVar6 = get_unused_fd_flags(0x80000);
  uVar7 = (ulong)uVar6;
  if (-1 < (int)uVar6) {
    snprintf(local_60,0x14,"gh-vcpu:%d",uVar13);
    uVar9 = anon_inode_getfile(local_60,gh_vcpu_fops,puVar8,2);
    if (uVar9 < 0xfffffffffffff001) {
      fd_install(uVar7,uVar9);
      puVar2 = (uint *)(pcVar12 + 0xa4);
      Hint_Prefetch(puVar2,2,0,1);
      do {
        uVar13 = *puVar2;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
        if (bVar4) {
          *puVar2 = uVar13 + 1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      if (uVar13 == 0) {
        uVar11 = 2;
LAB_0010372c:
        refcount_warn_saturate(puVar2,uVar11);
      }
      else if ((int)(uVar13 + 1 | uVar13) < 0) {
        uVar11 = 1;
        goto LAB_0010372c;
      }
      iVar10 = *(int *)(pcVar12 + 8);
      *(uint **)(pcVar12 + (param_3 & 0xffffffff) * 8 + 0x18) = puVar8;
      *(int *)(pcVar12 + 8) = iVar10 + 1;
      mutex_unlock(pcVar1);
      goto LAB_001036d4;
    }
    put_unused_fd(uVar7);
    uVar6 = (uint)uVar9;
  }
  kfree(puVar8);
  mutex_unlock(pcVar1);
  uVar7 = (ulong)(int)uVar6;
LAB_001036d4:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// gh_vm_mmap @ 00103738 size=36
// signature: undefined gh_vm_mmap(void)
// callers: []
//------------------------------------------------------------

void gh_vm_mmap(long param_1)

{
  gh_virtio_backend_mmap(*(long *)(param_1 + 0xd8) + 0x58);
  return;
}



//------------------------------------------------------------
// gh_vm_release @ 00103760 size=168
// signature: undefined gh_vm_release(void)
// callers: []
//------------------------------------------------------------

int gh_vm_release(undefined8 param_1,long param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_2 + 0xd8);
  if ((*(char *)(lVar5 + 3) != '\0') || (*(char *)(lVar5 + 2) == '\0')) {
    piVar1 = (int *)(lVar5 + 0xa4);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar4 = *piVar1;
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = iVar4 + -1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    if (iVar4 == 1) {
      DataMemoryBarrier(2,1);
      iVar4 = gh_destroy_vm(lVar5);
      if (iVar4 == 0) {
        return 0;
      }
      _printk(&DAT_0010e811,*(undefined2 *)(lVar5 + 0x10),iVar4);
      return iVar4;
    }
    if (iVar4 < 1) {
      refcount_warn_saturate(piVar1,3);
    }
  }
  return 0;
}



//------------------------------------------------------------
// gh_vcpu_ioctl @ 0010381c size=596
// signature: undefined gh_vcpu_ioctl(void)
// callers: []
//------------------------------------------------------------

void gh_vcpu_ioctl(long param_1,int param_2)

{
  char *pcVar1;
  char *pcVar2;
  undefined2 uVar3;
  long lVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  undefined *puVar8;
  char *pcVar9;
  undefined4 *puVar10;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  if (param_2 != 0xb280) {
    _printk(&DAT_0010e34d);
    lVar7 = -0x16;
    goto LAB_00103934;
  }
  puVar10 = *(undefined4 **)(param_1 + 0xd8);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  pcVar9 = *(char **)(puVar10 + 2);
  pcVar1 = pcVar9 + 0xc0;
  mutex_lock(pcVar1);
  if (pcVar9[0x80] == '\x03') {
LAB_0010387c:
    mutex_unlock(pcVar1);
    uVar6 = gh_vm_supports_proxy_sched(*(undefined2 *)(pcVar9 + 0x10));
    if ((uVar6 & 1) == 0) {
      if (pcVar9[0x80] != '\t') {
        local_88 = 0;
        uStack_80 = 0;
        local_98 = 0;
        uStack_90 = 0;
        local_a0 = 0;
        init_wait_entry(&local_a0,0);
        while (lVar7 = prepare_to_wait_event(pcVar9 + 0x88,&local_a0,0x2001), pcVar9[0x80] != '\t')
        {
          if (lVar7 != 0) {
            iVar5 = (int)lVar7;
            if (iVar5 < 0) goto LAB_00103930;
            goto LAB_0010392c;
          }
          schedule();
        }
        finish_wait(pcVar9 + 0x88,&local_a0);
      }
LAB_0010392c:
      iVar5 = *(int *)(pcVar9 + 0xa0);
    }
    else {
      pcVar9[4] = '\x01';
      iVar5 = gh_vcpu_run(*(undefined2 *)(pcVar9 + 0x10),*puVar10,0,0,0,&local_78);
      if (iVar5 < 0) {
        _printk(&DAT_0010ef8b,iVar5);
      }
    }
  }
  else {
    if (pcVar9[1] == '\0') {
      pcVar9[1] = '\x01';
      if (*pcVar9 == '\0') {
LAB_001039a8:
        pcVar2 = pcVar9 + 0x10;
        if (pcVar9[0x80] == '\x02') {
          srcu_notifier_call_chain(&gh_vm_notifier,1,pcVar2);
          iVar5 = ghd_rm_vm_start(*(undefined2 *)pcVar2);
          if (iVar5 == 0) {
            pcVar9[0x80] = '\x03';
            _printk(&DAT_0010ef63,*(undefined2 *)(pcVar9 + 0x10));
            goto LAB_0010387c;
          }
          _printk(&DAT_0010f29a,*(undefined2 *)pcVar2,iVar5);
          mutex_unlock(pcVar1);
          srcu_notifier_call_chain(&gh_vm_notifier,2,pcVar2);
          goto LAB_00103930;
        }
        uVar3 = *(undefined2 *)pcVar2;
        puVar8 = &DAT_0010eeef;
        goto LAB_00103a0c;
      }
      if (*(int *)(pcVar9 + 8) == *(int *)(pcVar9 + 0xc)) goto LAB_001039a8;
      _printk(&DAT_0010f24f,*(int *)(pcVar9 + 8),*(int *)(pcVar9 + 0xc),
              *(undefined2 *)(pcVar9 + 0x10));
    }
    else {
      uVar3 = *(undefined2 *)(pcVar9 + 0x10);
      puVar8 = &DAT_0010e46d;
LAB_00103a0c:
      _printk(puVar8,uVar3);
    }
    mutex_unlock(pcVar1);
    iVar5 = -0x16;
  }
LAB_00103930:
  lVar7 = (long)iVar5;
LAB_00103934:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar7);
  }
  return;
}



//------------------------------------------------------------
// gh_vcpu_release @ 00103a74 size=216
// signature: undefined gh_vcpu_release(void)
// callers: []
//------------------------------------------------------------

int gh_vcpu_release(undefined8 param_1,long param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  undefined4 *puVar6;
  
  puVar6 = *(undefined4 **)(param_2 + 0xd8);
  lVar5 = *(long *)(puVar6 + 2);
  if ((*(char *)(lVar5 + 2) != '\0') &&
     ((*(char *)(lVar5 + 3) == '\0' || (*(char *)(lVar5 + 0x80) == '\x03')))) {
    gh_vcpu_create_wq(*(undefined2 *)(lVar5 + 0x10),*puVar6);
    lVar5 = *(long *)(puVar6 + 2);
  }
  if ((*(char *)(lVar5 + 3) != '\0') || (*(char *)(lVar5 + 2) == '\0')) {
    piVar1 = (int *)(lVar5 + 0xa4);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar4 = *piVar1;
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = iVar4 + -1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    if (iVar4 == 1) {
      DataMemoryBarrier(2,1);
      iVar4 = gh_destroy_vm(lVar5);
      if (iVar4 == 0) {
        return 0;
      }
      _printk(&DAT_0010e811,*(undefined2 *)(lVar5 + 0x10),iVar4);
      return iVar4;
    }
    if (iVar4 < 1) {
      refcount_warn_saturate(piVar1,3);
    }
  }
  return 0;
}



//------------------------------------------------------------
// __traceiter_gh_virtio_backend_irq_inj @ 00103b60 size=116
// signature: undefined __traceiter_gh_virtio_backend_irq_inj(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_gh_virtio_backend_irq_inj(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00110138;
  plVar2 = DAT_00110138;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x5885f495) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103bb0);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_gh_virtio_backend_queue_notify @ 00103bd8 size=116
// signature: undefined __traceiter_gh_virtio_backend_queue_notify(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_gh_virtio_backend_queue_notify(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00110180;
  plVar2 = _DAT_00110180;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x5885f495) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103c28);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_gh_virtio_backend_wait_event @ 00103c50 size=148
// signature: undefined __traceiter_gh_virtio_backend_wait_event(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_gh_virtio_backend_wait_event
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001101c8;
  plVar2 = _DAT_001101c8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x4ffc7ec8) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103cbc);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_gh_virtio_backend_irq @ 00103ce8 size=140
// signature: undefined __traceiter_gh_virtio_backend_irq(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_gh_virtio_backend_irq
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00110210;
  plVar2 = _DAT_00110210;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x3798430b) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103d4c);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_gh_virtio_backend_irq_inj @ 00103d78 size=172
// signature: undefined trace_event_raw_event_gh_virtio_backend_irq_inj(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_gh_virtio_backend_irq_inj
               (long param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x10), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_gh_virtio_backend_irq_inj @ 00103e28 size=248
// signature: undefined perf_trace_gh_virtio_backend_irq_inj(void)
// callers: []
//------------------------------------------------------------

void perf_trace_gh_virtio_backend_irq_inj(long param_1,undefined4 param_2,undefined4 param_3)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x14,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    perf_trace_run_bpf_submit(lVar3,0x14,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_gh_virtio_backend_queue_notify @ 00103f24 size=172
// signature: undefined trace_event_raw_event_gh_virtio_backend_queue_notify(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_gh_virtio_backend_queue_notify
               (long param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x10), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_gh_virtio_backend_queue_notify @ 00103fd4 size=248
// signature: undefined perf_trace_gh_virtio_backend_queue_notify(void)
// callers: []
//------------------------------------------------------------

void perf_trace_gh_virtio_backend_queue_notify(long param_1,undefined4 param_2,undefined4 param_3)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x14,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    perf_trace_run_bpf_submit(lVar3,0x14,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_gh_virtio_backend_wait_event @ 001040d0 size=212
// signature: undefined trace_event_raw_event_gh_virtio_backend_wait_event(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_gh_virtio_backend_wait_event
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_78;
  undefined8 uStack_70;
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
  local_78 = 0;
  uStack_70 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_78,param_1,0x1c), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    *(undefined4 *)(lVar1 + 0x14) = param_5;
    *(undefined4 *)(lVar1 + 0x18) = param_6;
    trace_event_buffer_commit(&local_78);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_gh_virtio_backend_wait_event @ 001041a8 size=276
// signature: undefined perf_trace_gh_virtio_backend_wait_event(void)
// callers: []
//------------------------------------------------------------

void perf_trace_gh_virtio_backend_wait_event
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_60 = 0;
  local_64 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    *(undefined4 *)(lVar3 + 0x14) = param_5;
    *(undefined4 *)(lVar3 + 0x18) = param_6;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_gh_virtio_backend_irq @ 001042c0 size=196
// signature: undefined trace_event_raw_event_gh_virtio_backend_irq(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_gh_virtio_backend_irq
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x18), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    *(undefined4 *)(lVar1 + 0x14) = param_5;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_gh_virtio_backend_irq @ 00104388 size=268
// signature: undefined perf_trace_gh_virtio_backend_irq(void)
// callers: []
//------------------------------------------------------------

void perf_trace_gh_virtio_backend_irq
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_60 = 0;
  local_64 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    *(undefined4 *)(lVar3 + 0x14) = param_5;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_gh_virtio_backend_irq_inj @ 00104498 size=36
// signature: undefined __bpf_trace_gh_virtio_backend_irq_inj(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_gh_virtio_backend_irq_inj(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  bpf_trace_run2(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_gh_virtio_backend_queue_notify @ 001044c0 size=36
// signature: undefined __bpf_trace_gh_virtio_backend_queue_notify(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_gh_virtio_backend_queue_notify
               (undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  bpf_trace_run2(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_gh_virtio_backend_wait_event @ 001044e8 size=48
// signature: undefined __bpf_trace_gh_virtio_backend_wait_event(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_gh_virtio_backend_wait_event
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  bpf_trace_run5(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



//------------------------------------------------------------
// __bpf_trace_gh_virtio_backend_irq @ 0010451c size=44
// signature: undefined __bpf_trace_gh_virtio_backend_irq(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_gh_virtio_backend_irq
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  bpf_trace_run4(param_1,param_2,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// gh_virtio_backend_ioctl @ 0010454c size=6168
// signature: undefined gh_virtio_backend_ioctl(void)
// callers: [gh_vm_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gh_virtio_backend_ioctl(char *param_1,int param_2,ulong param_3)

{
  long lVar1;
  undefined4 uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  char *pcVar10;
  ulong uVar11;
  undefined *puVar12;
  undefined8 *puVar13;
  ulong uVar14;
  undefined **ppuVar15;
  ulong uVar16;
  undefined **ppuVar17;
  long lVar18;
  undefined4 *puVar19;
  uint uVar20;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  ulong local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  ulong local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  long local_70;
  
  lVar7 = sp_el0;
  local_70 = *(long *)(lVar7 + 0x638);
  _raw_spin_lock(&vm_list_lock);
  ppuVar15 = &vm_list;
  do {
    ppuVar15 = (undefined **)*ppuVar15;
    if (ppuVar15 == &vm_list) {
      ppuVar15 = (undefined **)0x0;
      break;
    }
    iVar5 = strcmp((char *)(ppuVar15 + 2),param_1);
  } while (iVar5 != 0);
  _raw_spin_unlock(&vm_list_lock);
  local_80 = 0;
  local_78 = 0;
  local_90 = 0;
  local_88 = 0;
  local_a0 = 0;
  local_98 = 0;
  local_b0 = 0;
  local_a8 = 0;
  local_c0 = 0;
  local_b8 = 0;
  local_c8 = 0;
  local_d8 = 0;
  local_d0 = 0;
  local_e8 = 0;
  local_e0 = 0;
  local_f8 = 0;
  local_f0 = 0;
  local_108 = 0;
  local_100 = 0;
  local_110 = 0;
  if (ppuVar15 == (undefined **)0x0) {
LAB_00105a60:
    lVar7 = -0x16;
  }
  else {
    uVar6 = (uint)_cpu_hwcaps;
    if (param_2 < -0x3fd74d97) {
      if (param_2 < -0x3fef4d9c) {
        if (param_2 != -0x7ff74d9f) {
          if (param_2 != -0x3ffb4d95) goto switchD_001047c4_caseD_4010b264;
          if ((int)param_3 != 0) {
            lVar7 = (long)ppuVar15 + 0x3c;
            _raw_spin_lock(lVar7);
            ppuVar17 = ppuVar15 + 8;
            do {
              ppuVar17 = (undefined **)*ppuVar17;
              if (ppuVar17 == ppuVar15 + 8) goto LAB_001057c4;
            } while (*(int *)((long)ppuVar17 + 0x7c) != (int)param_3);
            if ((*(int *)(ppuVar17 + 9) != -1) && (ppuVar17 != (undefined **)0x0)) {
              *(int *)(ppuVar17 + 9) = *(int *)(ppuVar17 + 9) + 1;
              _raw_spin_unlock(lVar7);
              puVar12 = ppuVar17[0x11];
              *(undefined4 *)(ppuVar17 + 10) = 1;
              _raw_spin_lock(puVar12 + 0x3c);
              iVar5 = *(int *)(ppuVar17 + 9);
              *(int *)(ppuVar17 + 9) = iVar5 + -1;
              if ((iVar5 + -1 == 0) && (*(int *)((long)ppuVar17 + 0x4c) != 0)) {
                __wake_up(ppuVar17 + 6,3,1,0);
              }
              _raw_spin_unlock(puVar12 + 0x3c);
              goto LAB_00105a48;
            }
LAB_001057c4:
            _raw_spin_unlock(lVar7);
          }
          goto LAB_00105a60;
        }
        puVar13 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
           (uVar11 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
          uVar11 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (uVar11 < 0x7ffffffff9) {
          if ((uVar6 >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar16 = daif;
              daif = uVar16 | 0xc0;
            }
            puVar13 = (undefined8 *)puVar13[1];
            uVar16 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar16 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar13;
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
          lVar7 = __arch_copy_to_user(puVar13,param_3 & 0xff7fffffffffffff,ppuVar15 + 0xb,8);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar16 = daif;
              daif = uVar16 | 0xc0;
            }
            uVar16 = ttbr1_el1;
            ttbr0_el1 = (uVar16 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar16 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
LAB_0010589c:
          if (lVar7 == 0) {
LAB_00105a48:
            lVar7 = 0;
            goto LAB_00105a64;
          }
        }
      }
      else if (param_2 == -0x3fef4d9c) {
        puVar13 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
           (uVar11 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
          uVar11 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (uVar11 < 0x7ffffffff1) {
          if ((uVar6 >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar16 = daif;
              daif = uVar16 | 0xc0;
            }
            uVar16 = ttbr1_el1;
            ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar16 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar13[1];
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
          lVar7 = __arch_copy_from_user(&local_110,param_3 & 0xff7fffffffffffff,0x10);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar16 = daif;
              daif = uVar16 | 0xc0;
            }
            uVar16 = ttbr1_el1;
            ttbr0_el1 = (uVar16 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar16 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
          if (lVar7 == 0) {
            if (((int)local_110 == 0) || (lVar7 = vb_dev_get(ppuVar15), lVar7 == 0))
            goto LAB_00105a60;
            lVar1 = lVar7 + 0x18;
            do {
              if (*(int *)(lVar7 + 0x54) == 0) {
                local_120 = 0;
                uStack_118 = 0;
                local_130 = 0;
                uStack_128 = 0;
                local_138 = 0;
                init_wait_entry(&local_138,0);
                lVar18 = prepare_to_wait_event(lVar1,&local_138,1);
                if (*(int *)(lVar7 + 0x54) == 0) {
                  do {
                    if (lVar18 != 0) {
                      if ((int)lVar18 == 0) goto LAB_00104c70;
                      vb_dev_put(lVar7);
                      lVar7 = (long)(int)lVar18;
                      goto LAB_00105a64;
                    }
                    schedule();
                    lVar18 = prepare_to_wait_event(lVar1,&local_138,1);
                  } while (*(int *)(lVar7 + 0x54) == 0);
                }
                finish_wait(lVar1,&local_138);
              }
LAB_00104c70:
              uVar8 = _raw_spin_lock_irqsave(lVar7 + 0x10);
              uVar11 = *(ulong *)(lVar7 + 0x70);
              *(undefined8 *)(lVar7 + 0x68) = 0;
              *(undefined8 *)(lVar7 + 0x58) = 0;
              *(undefined4 *)(lVar7 + 0x54) = 0;
              if ((uVar11 & 0x60) == 0) {
                uVar6 = (uint)uVar11;
                if ((uVar6 >> 1 & 1) == 0) {
                  if ((uVar6 >> 3 & 1) == 0) {
                    lVar18 = *(long *)(lVar7 + 0x1d0);
                    if ((uVar11 & 1) == 0) {
                      if ((uVar6 >> 2 & 1) != 0) {
                        *(undefined8 *)(lVar7 + 0x60) = 0;
                        *(undefined8 *)(lVar7 + 0x68) = 4;
                        *(ulong *)(lVar7 + 0x70) = uVar11 & 0xfffffffffffffffb;
LAB_00104d68:
                        uVar11 = readl_relaxed(lVar18 + 100);
                        *(ulong *)(lVar7 + 0x58) = uVar11 & 0xffffffff;
                      }
                    }
                    else {
                      uVar11 = uVar11 & 0xfffffffffffffffe;
                      *(ulong *)(lVar7 + 0x70) = uVar11;
                      if ((*(long *)(lVar7 + 0x60) != 0) && (*(int *)(lVar7 + 0x50) != 0)) {
                        signal_vqs(lVar7);
                        uVar11 = *(ulong *)(lVar7 + 0x70);
                      }
                      if (uVar11 != 0) {
                        *(ulong *)(lVar7 + 0x68) = uVar11;
                        *(undefined8 *)(lVar7 + 0x70) = 0;
                        *(undefined8 *)(lVar7 + 0x58) = *(undefined8 *)(lVar7 + 0x60);
                        *(undefined8 *)(lVar7 + 0x60) = 0;
                        if (((uint)uVar11 >> 2 & 1) != 0) goto LAB_00104d68;
                      }
                    }
                  }
                  else {
                    uVar11 = uVar11 & 0xfffffffffffffff7;
                    *(ulong *)(lVar7 + 0x70) = uVar11;
                    if (*(int *)(lVar7 + 0x50) == 0) {
                      *(undefined8 *)(lVar7 + 0x68) = 8;
                      goto joined_r0x00104cfc;
                    }
                  }
                }
                else {
                  uVar11 = uVar11 & 0xfffffffffffffffd;
                  *(undefined8 *)(lVar7 + 0x68) = 2;
                  *(ulong *)(lVar7 + 0x70) = uVar11;
joined_r0x00104cfc:
                  if (uVar11 != 0) {
                    *(undefined4 *)(lVar7 + 0x54) = 1;
                  }
                }
              }
              else {
                *(undefined8 *)(lVar7 + 0x68) = 0x100;
              }
              _raw_spin_unlock_irqrestore(lVar7 + 0x10,uVar8);
            } while (*(long *)(lVar7 + 0x68) == 0);
            local_110 = CONCAT44((int)*(long *)(lVar7 + 0x68),(int)local_110);
            local_108 = CONCAT44(local_108._4_4_,(int)*(undefined8 *)(lVar7 + 0x58));
            vb_dev_put(lVar7);
            if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
               (uVar11 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
              uVar11 = param_3 & (long)(param_3 << 8) >> 8;
            }
            if (uVar11 < 0x7ffffffff1) {
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar11 = daif;
                if ((uVar11 & 0x80) == 0) {
                  uVar16 = daif;
                  daif = uVar16 | 0xc0;
                }
                uVar16 = ttbr1_el1;
                ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar16 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar13[1];
                InstructionSynchronizationBarrier();
                daif = uVar11;
              }
              lVar7 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,&local_110,0x10);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar11 = daif;
                if ((uVar11 & 0x80) == 0) {
                  uVar16 = daif;
                  daif = uVar16 | 0xc0;
                }
                uVar16 = ttbr1_el1;
                ttbr0_el1 = (uVar16 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar16 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar11;
              }
              goto LAB_0010589c;
            }
          }
        }
      }
      else if (param_2 == -0x3fef4d98) {
        puVar13 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
           (uVar11 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
          uVar11 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (uVar11 < 0x7ffffffff1) {
          if ((uVar6 >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar16 = daif;
              daif = uVar16 | 0xc0;
            }
            uVar16 = ttbr1_el1;
            ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar16 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar13[1];
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
          lVar7 = __arch_copy_from_user(&local_c8,param_3 & 0xff7fffffffffffff,0x10);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar16 = daif;
              daif = uVar16 | 0xc0;
            }
            uVar16 = ttbr1_el1;
            ttbr0_el1 = (uVar16 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar16 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
          if (lVar7 == 0) {
            lVar7 = vb_dev_get(ppuVar15,local_c8 & 0xffffffff);
            if (lVar7 != 0) {
              lVar1 = lVar7 + 0x188;
              mutex_lock(lVar1);
              uVar11 = local_c0;
              if ((int)local_c8 != 0) {
                uVar6 = local_c8._4_4_;
                uVar16 = (ulong)local_c8._4_4_;
                if ((((local_c8._4_4_ != 0) && (uVar16 <= *(ulong *)(lVar7 + 0x1d8))) &&
                    (local_c0 != 0)) && (lVar18 = *(long *)(lVar7 + 0x1d0), lVar18 != 0)) {
                  if ((long)local_c8 < 0) {
                    /* WARNING: Does not return */
                    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x105b90);
                    (*pcVar4)();
                  }
                  __check_object_size(lVar18,uVar16,1);
                  if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
                     (uVar14 = uVar11, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
                    uVar14 = uVar11 & (long)(uVar11 << 8) >> 8;
                  }
                  if (uVar14 <= 0x8000000000 - uVar16) {
                    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                      uVar14 = daif;
                      if ((uVar14 & 0x80) == 0) {
                        uVar9 = daif;
                        daif = uVar9 | 0xc0;
                      }
                      uVar9 = ttbr1_el1;
                      ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar9 & 0xffffffffffff;
                      InstructionSynchronizationBarrier();
                      ttbr0_el1 = puVar13[1];
                      InstructionSynchronizationBarrier();
                      daif = uVar14;
                    }
                    uVar6 = __arch_copy_to_user(uVar11 & 0xff7fffffffffffff,lVar18,uVar16);
                    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                      uVar11 = daif;
                      if ((uVar11 & 0x80) == 0) {
                        uVar16 = daif;
                        daif = uVar16 | 0xc0;
                      }
                      uVar16 = ttbr1_el1;
                      ttbr0_el1 = (uVar16 & 0xffffffffffff) - 0x1000;
                      InstructionSynchronizationBarrier();
                      ttbr1_el1 = uVar16 & 0xffffffffffff;
                      InstructionSynchronizationBarrier();
                      daif = uVar11;
                    }
                  }
                  mutex_unlock(lVar1);
                  vb_dev_put(lVar7);
                  lVar7 = (long)(int)uVar6;
                  goto LAB_00105a64;
                }
              }
              mutex_unlock(lVar1);
LAB_00105a5c:
              vb_dev_put(lVar7);
            }
            goto LAB_00105a60;
          }
        }
      }
      else {
        if (param_2 != -0x3fef4d96) goto switchD_001047c4_caseD_4010b264;
        puVar13 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
           (uVar11 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
          uVar11 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (uVar11 < 0x7ffffffff1) {
          if ((uVar6 >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar16 = daif;
              daif = uVar16 | 0xc0;
            }
            uVar16 = ttbr1_el1;
            ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar16 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar13[1];
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
          lVar7 = __arch_copy_from_user(&local_100,param_3 & 0xff7fffffffffffff,0x10);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar16 = daif;
              daif = uVar16 | 0xc0;
            }
            uVar16 = ttbr1_el1;
            ttbr0_el1 = (uVar16 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar16 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
          if (lVar7 == 0) {
            lVar7 = -0x16;
            if (((int)local_100 == 0) || (1 < (uint)local_f8)) goto LAB_00105a64;
            lVar7 = vb_dev_get(ppuVar15);
            if (lVar7 == 0) goto LAB_00105a60;
            if (*(long *)(lVar7 + 0x1b8) == 0) goto LAB_00105a5c;
            CallHyperVisor(0x6051);
            local_138 = 0;
            iVar5 = (int)*(long *)(lVar7 + 0x1b8);
            uVar2 = (uint)local_f8;
            if (iVar5 != 0) {
              uVar2 = 0;
            }
            vb_dev_put(lVar7,local_f8 & 0xffffffff,0,0,0,0,0,0);
            if (iVar5 != 0) {
              lVar7 = (long)iVar5;
              goto LAB_00105a64;
            }
            local_f8 = CONCAT44(uVar2,(uint)local_f8);
            if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
               (uVar11 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
              uVar11 = param_3 & (long)(param_3 << 8) >> 8;
            }
            if (uVar11 < 0x7ffffffff1) {
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar11 = daif;
                if ((uVar11 & 0x80) == 0) {
                  uVar16 = daif;
                  daif = uVar16 | 0xc0;
                }
                uVar16 = ttbr1_el1;
                ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar16 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar13[1];
                InstructionSynchronizationBarrier();
                daif = uVar11;
              }
              lVar7 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,&local_100,0x10);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar11 = daif;
                if ((uVar11 & 0x80) == 0) {
                  uVar16 = daif;
                  daif = uVar16 | 0xc0;
                }
                uVar16 = ttbr1_el1;
                ttbr0_el1 = (uVar16 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar16 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar11;
              }
              goto LAB_0010589c;
            }
          }
        }
      }
    }
    else {
      switch(param_2) {
      case 0x4010b262:
        puVar13 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
           (uVar11 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
          uVar11 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (uVar11 < 0x7ffffffff1) {
          if ((uVar6 >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar16 = daif;
              daif = uVar16 | 0xc0;
            }
            puVar13 = (undefined8 *)puVar13[1];
            uVar16 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar16 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar13;
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
          lVar7 = __arch_copy_from_user(puVar13,&local_80,param_3 & 0xff7fffffffffffff,0x10);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar16 = daif;
              daif = uVar16 | 0xc0;
            }
            uVar16 = ttbr1_el1;
            ttbr0_el1 = (uVar16 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar16 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
          if (lVar7 == 0) {
            if ((uint)local_78 < 4) {
              if (local_80._4_4_ != 1) {
LAB_001058a8:
                lVar7 = -0x5f;
                goto LAB_00105a64;
              }
              lVar7 = vb_dev_get(ppuVar15,local_80 & 0xffffffff);
              if (lVar7 != 0) {
                iVar5 = vb_dev_ioeventfd(lVar7,&local_80);
LAB_00105374:
                vb_dev_put(lVar7);
                lVar7 = (long)iVar5;
                goto LAB_00105a64;
              }
            }
            goto LAB_00105a60;
          }
        }
        break;
      case 0x4010b263:
        puVar13 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
           (uVar11 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
          uVar11 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (uVar11 < 0x7ffffffff1) {
          if ((uVar6 >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar16 = daif;
              daif = uVar16 | 0xc0;
            }
            puVar13 = (undefined8 *)puVar13[1];
            uVar16 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar16 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar13;
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
          lVar7 = __arch_copy_from_user(puVar13,&local_90,param_3 & 0xff7fffffffffffff,0x10);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar16 = daif;
              daif = uVar16 | 0xc0;
            }
            uVar16 = ttbr1_el1;
            ttbr0_el1 = (uVar16 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar16 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
          if (lVar7 == 0) {
            lVar7 = -0x16;
            if (((int)local_90 == 0) || ((int)local_88 < 1)) goto LAB_00105a64;
            if (local_90._4_4_ != 1) goto LAB_001058a8;
            lVar7 = vb_dev_get(ppuVar15);
            if (lVar7 != 0) {
              iVar5 = vb_dev_irqfd(lVar7,&local_90);
              goto LAB_00105374;
            }
            goto LAB_00105a60;
          }
        }
        break;
      case 0x4010b264:
switchD_001047c4_caseD_4010b264:
        _dev_err(ppuVar15[5],"%s: cmd %x not supported\n","gh_virtio_backend",param_2);
        goto LAB_00105a60;
      case 0x4010b265:
        puVar13 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
           (uVar11 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
          uVar11 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (uVar11 < 0x7ffffffff1) {
          if ((uVar6 >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar16 = daif;
              daif = uVar16 | 0xc0;
            }
            puVar13 = (undefined8 *)puVar13[1];
            uVar16 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar16 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar13;
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
          lVar7 = __arch_copy_from_user(puVar13,&local_a0,param_3 & 0xff7fffffffffffff,0x10);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar16 = daif;
              daif = uVar16 | 0xc0;
            }
            uVar16 = ttbr1_el1;
            ttbr0_el1 = (uVar16 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar16 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
          if (lVar7 == 0) {
            lVar7 = -0x16;
            if (((int)local_a0 == 0) || (1 < (uint)local_98)) goto LAB_00105a64;
            lVar7 = vb_dev_get(ppuVar15);
            if (lVar7 != 0) {
              if (1 < (uint)local_98) {
LAB_00105bd8:
                    /* WARNING: Does not return */
                pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x105bdc);
                (*pcVar4)();
              }
              *(undefined4 *)(lVar7 + (local_98 & 0xffffffff) * 4 + 0x170) = local_98._4_4_;
              if (1 < (uint)local_98) goto LAB_00105bd8;
              uVar11 = *(ulong *)(lVar7 + 0x1b8);
              CallHyperVisor(0x604f);
              local_138 = 0;
              vb_dev_put(lVar7,local_98 & 0xffffffff,
                         *(undefined4 *)(lVar7 + (local_98 & 0xffffffff) * 4 + 0x170),0,0,0,0,0);
              if ((int)uVar11 != 0) {
                uVar16 = local_98 & 0xffffffff;
                if (1 < (uint)local_98) goto LAB_00105bd8;
                puVar12 = ppuVar15[5];
                pcVar10 = "%s: set_features %d/%x failed ret %d\n";
                uVar2 = *(undefined4 *)(lVar7 + uVar16 * 4 + 0x170);
LAB_00105af0:
                _dev_err(puVar12,pcVar10,"gh_virtio_backend",uVar16,uVar2,uVar11 & 0xffffffff);
                lVar7 = (long)(int)uVar11;
                goto LAB_00105a64;
              }
              goto LAB_00105a48;
            }
            goto LAB_00105a60;
          }
        }
        break;
      case 0x4010b266:
        puVar13 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
           (uVar11 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
          uVar11 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (uVar11 < 0x7ffffffff1) {
          if ((uVar6 >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar16 = daif;
              daif = uVar16 | 0xc0;
            }
            puVar13 = (undefined8 *)puVar13[1];
            uVar16 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar16 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar13;
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
          lVar7 = __arch_copy_from_user(puVar13,&local_b0,param_3 & 0xff7fffffffffffff,0x10);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar16 = daif;
              daif = uVar16 | 0xc0;
            }
            uVar16 = ttbr1_el1;
            ttbr0_el1 = (uVar16 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar16 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
          if (lVar7 == 0) {
            lVar7 = -0x16;
            if (((int)local_b0 == 0) || (3 < (uint)local_a8)) goto LAB_00105a64;
            lVar7 = vb_dev_get(ppuVar15);
            if (lVar7 != 0) {
              if (3 < (uint)local_a8) goto LAB_00105bd8;
              *(undefined4 *)(lVar7 + (local_a8 & 0xffffffff) * 4 + 0x178) = local_a8._4_4_;
              if (3 < (uint)local_a8) goto LAB_00105bd8;
              uVar11 = *(ulong *)(lVar7 + 0x1b8);
              CallHyperVisor(0x6050);
              local_138 = 0;
              vb_dev_put(lVar7,local_a8 & 0xffffffff,
                         *(undefined4 *)(lVar7 + (local_a8 & 0xffffffff) * 4 + 0x178),0,0,0,0,0);
              if ((int)uVar11 != 0) {
                uVar16 = local_a8 & 0xffffffff;
                if (3 < (uint)local_a8) goto LAB_00105bd8;
                puVar12 = ppuVar15[5];
                pcVar10 = "%s: set_queue_num_max %d/%x failed ret %d\n";
                uVar2 = *(undefined4 *)(lVar7 + uVar16 * 4 + 0x178);
                goto LAB_00105af0;
              }
              goto LAB_00105a48;
            }
            goto LAB_00105a60;
          }
        }
        break;
      case 0x4010b267:
        puVar13 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
           (uVar11 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
          uVar11 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (uVar11 < 0x7ffffffff1) {
          if ((uVar6 >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar16 = daif;
              daif = uVar16 | 0xc0;
            }
            uVar16 = ttbr1_el1;
            ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar16 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar13[1];
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
          lVar7 = __arch_copy_from_user(&local_c8,param_3 & 0xff7fffffffffffff,0x10);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar16 = daif;
              daif = uVar16 | 0xc0;
            }
            uVar16 = ttbr1_el1;
            ttbr0_el1 = (uVar16 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar16 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
          if (lVar7 == 0) {
            lVar7 = vb_dev_get(ppuVar15,local_c8 & 0xffffffff);
            if (lVar7 != 0) {
              lVar1 = lVar7 + 0x188;
              mutex_lock(lVar1);
              if ((int)local_c8 != 0) {
                if (((local_c8._4_4_ != 0) && ((ulong)local_c8._4_4_ <= *(ulong *)(lVar7 + 0x1d8)))
                   && (local_c0 != 0)) {
                  if (*(long *)(lVar7 + 0x1c0) != 0) {
                    mutex_unlock(lVar1);
                    vb_dev_put(lVar7);
                    lVar7 = -0x10;
                    goto LAB_00105a64;
                  }
                  if (*(long *)(lVar7 + 0x1d0) != 0) {
                    lVar18 = __get_free_pages(0xdc0,0);
                    uVar11 = local_c0;
                    *(long *)(lVar7 + 0x1c0) = lVar18;
                    if (lVar18 == 0) {
                      mutex_unlock(lVar1);
                      vb_dev_put(lVar7);
                      lVar7 = -0xc;
                      goto LAB_00105a64;
                    }
                    uVar16 = local_c8 >> 0x20;
                    if ((long)local_c8 < 0) {
                    /* WARNING: Does not return */
                      pcVar4 = (code *)SoftwareBreakpoint(0x800,0x105b9c);
                      (*pcVar4)();
                    }
                    __check_object_size(lVar18,uVar16,0);
                    if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
                       (uVar14 = uVar11, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
                      uVar14 = uVar11 & (long)(uVar11 << 8) >> 8;
                    }
                    uVar9 = uVar16;
                    if (uVar14 <= 0x8000000000 - uVar16) {
                      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                        uVar14 = daif;
                        if ((uVar14 & 0x80) == 0) {
                          uVar9 = daif;
                          daif = uVar9 | 0xc0;
                        }
                        uVar9 = ttbr1_el1;
                        ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar9 & 0xffffffffffff;
                        InstructionSynchronizationBarrier();
                        ttbr0_el1 = puVar13[1];
                        InstructionSynchronizationBarrier();
                        daif = uVar14;
                      }
                      uVar9 = __arch_copy_from_user(lVar18,uVar11 & 0xff7fffffffffffff,uVar16);
                      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                        uVar11 = daif;
                        if ((uVar11 & 0x80) == 0) {
                          uVar14 = daif;
                          daif = uVar14 | 0xc0;
                        }
                        uVar14 = ttbr1_el1;
                        ttbr0_el1 = (uVar14 & 0xffffffffffff) - 0x1000;
                        InstructionSynchronizationBarrier();
                        ttbr1_el1 = uVar14 & 0xffffffffffff;
                        InstructionSynchronizationBarrier();
                        daif = uVar11;
                      }
                    }
                    if (uVar9 != 0) {
                      memset((void *)(lVar18 + (uVar16 - uVar9)),0,uVar9);
                      free_pages(*(undefined8 *)(lVar7 + 0x1c0),0);
                      *(undefined8 *)(lVar7 + 0x1c0) = 0;
                      mutex_unlock(lVar1);
                      vb_dev_put(lVar7);
                      lVar7 = -0xe;
                      goto LAB_00105a64;
                    }
                    *(uint *)(lVar7 + 0x1c8) = local_c8._4_4_;
                    uVar6 = *(uint *)(lVar7 + 0x1c8);
                    if (3 < uVar6) {
                      uVar3 = uVar6 >> 2;
                      uVar20 = uVar3;
                      if (uVar3 < 2) {
                        uVar20 = 1;
                      }
                      lVar18 = *(long *)(lVar7 + 0x1d0);
                      puVar19 = *(undefined4 **)(lVar7 + 0x1c0);
                      do {
                        writel_relaxed(*puVar19,lVar18);
                        uVar20 = uVar20 - 1;
                        lVar18 = lVar18 + 4;
                        puVar19 = puVar19 + 1;
                      } while (uVar20 != 0);
                      if (3 < uVar6) {
                        uVar6 = 0;
                        if (uVar3 < 2) {
                          uVar3 = 1;
                        }
                        do {
                          uVar6 = uVar6 + 1;
                        } while (uVar3 != uVar6);
                      }
                    }
                    mutex_unlock(lVar1);
                    vb_dev_put(lVar7);
                    goto LAB_00105a48;
                  }
                }
              }
              mutex_unlock(lVar1);
              goto LAB_00105a5c;
            }
            goto LAB_00105a60;
          }
        }
        break;
      default:
        if (param_2 == -0x3fd74d97) {
          puVar13 = (undefined8 *)sp_el0;
          if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
             (uVar11 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
            uVar11 = param_3 & (long)(param_3 << 8) >> 8;
          }
          if (uVar11 < 0x7fffffffd9) {
            if ((uVar6 >> 0x1d & 1) == 0) {
              uVar11 = daif;
              if ((uVar11 & 0x80) == 0) {
                uVar16 = daif;
                daif = uVar16 | 0xc0;
              }
              uVar16 = ttbr1_el1;
              ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar16 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar13[1];
              InstructionSynchronizationBarrier();
              daif = uVar11;
            }
            lVar7 = __arch_copy_from_user(&local_f0,param_3 & 0xff7fffffffffffff,0x28);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar11 = daif;
              if ((uVar11 & 0x80) == 0) {
                uVar16 = daif;
                daif = uVar16 | 0xc0;
              }
              uVar16 = ttbr1_el1;
              ttbr0_el1 = (uVar16 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar16 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar11;
            }
            if (lVar7 == 0) {
              lVar7 = -0x16;
              if (((int)local_f0 == 0) || (3 < local_f0._4_4_)) goto LAB_00105a64;
              lVar7 = vb_dev_get(ppuVar15);
              if (lVar7 == 0) goto LAB_00105a60;
              if (*(long *)(lVar7 + 0x1b8) == 0) goto LAB_00105a5c;
              CallHyperVisor(0x6052);
              local_138 = 0;
              iVar5 = (int)*(long *)(lVar7 + 0x1b8);
              uVar6 = 0;
              if (iVar5 == 0) {
                uVar6 = local_f0._4_4_;
              }
              vb_dev_put(lVar7);
              if (iVar5 != 0) {
                lVar7 = (long)iVar5;
                goto LAB_00105a64;
              }
              local_e8 = (ulong)uVar6;
              local_e0 = 0;
              local_d8 = 0;
              local_d0 = 0;
              if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
                 (uVar11 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
                uVar11 = param_3 & (long)(param_3 << 8) >> 8;
              }
              if (uVar11 < 0x7fffffffd9) {
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar11 = daif;
                  if ((uVar11 & 0x80) == 0) {
                    uVar16 = daif;
                    daif = uVar16 | 0xc0;
                  }
                  uVar16 = ttbr1_el1;
                  ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar16 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  ttbr0_el1 = puVar13[1];
                  InstructionSynchronizationBarrier();
                  daif = uVar11;
                }
                lVar7 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,&local_f0,0x28);
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar11 = daif;
                  if ((uVar11 & 0x80) == 0) {
                    uVar16 = daif;
                    daif = uVar16 | 0xc0;
                  }
                  uVar16 = ttbr1_el1;
                  ttbr0_el1 = (uVar16 & 0xffffffffffff) - 0x1000;
                  InstructionSynchronizationBarrier();
                  ttbr1_el1 = uVar16 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  daif = uVar11;
                }
                goto LAB_0010589c;
              }
            }
          }
        }
        else {
          if (param_2 != 0x4008b26d) goto switchD_001047c4_caseD_4010b264;
          puVar13 = (undefined8 *)sp_el0;
          if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
             (uVar11 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
            uVar11 = param_3 & (long)(param_3 << 8) >> 8;
          }
          if (uVar11 < 0x7ffffffff9) {
            if ((uVar6 >> 0x1d & 1) == 0) {
              uVar11 = daif;
              if ((uVar11 & 0x80) == 0) {
                uVar16 = daif;
                daif = uVar16 | 0xc0;
              }
              puVar13 = (undefined8 *)puVar13[1];
              uVar16 = ttbr1_el1;
              ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar16 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar13;
              InstructionSynchronizationBarrier();
              daif = uVar11;
            }
            lVar7 = __arch_copy_from_user(puVar13,&local_b8,param_3 & 0xff7fffffffffffff,8);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar11 = daif;
              if ((uVar11 & 0x80) == 0) {
                uVar16 = daif;
                daif = uVar16 | 0xc0;
              }
              uVar16 = ttbr1_el1;
              ttbr0_el1 = (uVar16 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar16 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar11;
            }
            if (lVar7 == 0) {
              if ((((int)local_b8 != 0) && (lVar7 = vb_dev_get(ppuVar15), lVar7 != 0)) &&
                 (*(long *)(lVar7 + 0x1b8) != 0)) {
                CallHyperVisor(0x6054);
                local_138 = 0;
                vb_dev_put(lVar7,0,0,0,0,0,0,0);
                goto LAB_00105a48;
              }
              goto LAB_00105a60;
            }
          }
        }
      }
    }
    lVar7 = -0xe;
  }
LAB_00105a64:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar7);
  }
  return;
}



//------------------------------------------------------------
// vb_dev_get @ 001061ac size=144
// signature: undefined vb_dev_get(void)
// callers: [gh_virtio_backend_ioctl]
//------------------------------------------------------------

long vb_dev_get(long param_1,int param_2)

{
  long *plVar1;
  long *plVar2;
  
  _raw_spin_lock(param_1 + 0x3c);
  plVar1 = (long *)(param_1 + 0x40);
  do {
    plVar1 = (long *)*plVar1;
    if (plVar1 == (long *)(param_1 + 0x40)) {
      plVar2 = (long *)0x0;
      goto LAB_0010621c;
    }
  } while (*(int *)((long)plVar1 + 0x7c) != param_2);
  plVar2 = (long *)0;
  if ((*(int *)(plVar1 + 9) != -1) && (plVar1 != (long *)0x0)) {
    *(int *)(plVar1 + 9) = *(int *)(plVar1 + 9) + 1;
    plVar2 = plVar1;
  }
LAB_0010621c:
  _raw_spin_unlock(param_1 + 0x3c);
  return (long)plVar2;
}



//------------------------------------------------------------
// vb_dev_ioeventfd @ 0010623c size=196
// signature: undefined vb_dev_ioeventfd(void)
// callers: [gh_virtio_backend_ioctl]
//------------------------------------------------------------

ulong vb_dev_ioeventfd(long param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong uVar4;
  int *piVar5;
  
  if (*(int *)(param_2 + 0xc) < 1) {
    uVar4 = 0xffffffea;
  }
  else {
    uVar1 = *(uint *)(param_2 + 8);
    uVar3 = _raw_spin_lock_irqsave(param_1 + 0x10);
    if (3 < uVar1) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x106300);
      (*pcVar2)();
    }
    piVar5 = (int *)(param_1 + (ulong)uVar1 * 0x10 + 0x90);
    if (*piVar5 < 1) {
      uVar4 = eventfd_ctx_fdget(*(undefined4 *)(param_2 + 0xc));
      if (uVar4 < 0xfffffffffffff001) {
        *(ulong *)(param_1 + (ulong)uVar1 * 0x10 + 0x98) = uVar4;
        uVar4 = 0;
        *piVar5 = *(int *)(param_2 + 0xc);
      }
    }
    else {
      uVar4 = 0xfffffff0;
    }
    _raw_spin_unlock_irqrestore(param_1 + 0x10,uVar3);
  }
  return uVar4 & 0xffffffff;
}



//------------------------------------------------------------
// vb_dev_put @ 00106300 size=104
// signature: undefined vb_dev_put(void)
// callers: [gh_virtio_backend_ioctl, gh_virtio_mmio_init]
//------------------------------------------------------------

void vb_dev_put(long param_1)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_1 + 0x88) + 0x3c;
  _raw_spin_lock(lVar1);
  iVar2 = *(int *)(param_1 + 0x48) + -1;
  *(int *)(param_1 + 0x48) = iVar2;
  if ((iVar2 == 0) && (*(int *)(param_1 + 0x4c) != 0)) {
    __wake_up(param_1 + 0x30,3,1,0);
  }
  _raw_spin_unlock(lVar1);
  return;
}



//------------------------------------------------------------
// vb_dev_irqfd @ 00106368 size=312
// signature: undefined vb_dev_irqfd(void)
// callers: [gh_virtio_backend_ioctl]
//------------------------------------------------------------

ulong vb_dev_irqfd(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  ulong uVar4;
  code *pcVar5;
  ulong uVar6;
  
  lVar1 = param_1 + 0x10;
  uVar3 = _raw_spin_lock_irqsave(lVar1);
  if (*(long *)(param_1 + 0x110) == 0) {
    uVar4 = __fdget(*(undefined4 *)(param_2 + 8));
    uVar2 = uVar4 & 0xfffffffffffffffc;
    if (uVar2 == 0) goto LAB_001063a0;
    uVar6 = eventfd_ctx_fileget(uVar2);
    if (uVar6 < 0xfffffffffffff001) {
      *(ulong *)(param_1 + 0xd0) = uVar6;
      *(ulong *)(param_1 + 0x110) = uVar2;
      *(ulong *)(param_1 + 0x118) = uVar4 & 3;
      _raw_spin_unlock_irqrestore(lVar1,uVar3);
      *(undefined4 *)(param_1 + 0xd8) = 0;
      *(undefined8 *)(param_1 + 0xe0) = 0;
      *(code **)(param_1 + 0xe8) = vb_dev_irqfd_wakeup;
      *(undefined8 *)(param_1 + 0x120) = 0xfffffffe0;
      *(long *)(param_1 + 0x128) = param_1 + 0x128;
      *(long *)(param_1 + 0x130) = param_1 + 0x128;
      *(code **)(param_1 + 0x100) = vb_dev_irqfd_ptable_queue_proc;
      *(code **)(param_1 + 0x138) = irqfd_shutdown;
      *(undefined4 *)(param_1 + 0x108) = 0xffffffff;
      pcVar5 = *(code **)(*(long *)(uVar2 + 0x28) + 0x48);
      if (pcVar5 != (code *)0x0) {
        if (*(int *)(pcVar5 + -4) != -0x7a1a59e2) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10648c);
          (*pcVar5)();
        }
        (*pcVar5)(uVar2,param_1 + 0x100);
      }
      uVar6 = 0;
      goto LAB_001063b0;
    }
    if ((uVar4 & 1) != 0) {
      fput(uVar2);
    }
  }
  else {
LAB_001063a0:
    uVar6 = 0xfffffff0;
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar3);
LAB_001063b0:
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// signal_vqs @ 001064cc size=180
// signature: undefined signal_vqs(void)
// callers: [gh_virtio_backend_ioctl, vdev_interrupt]
//------------------------------------------------------------

void signal_vqs(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  
  lVar3 = 0;
  uVar1 = sp_el0;
  do {
    uVar4 = (ulong)(1 << (ulong)((uint)lVar3 & 0x1f));
    if ((*(ulong *)(param_1 + 0x60) & uVar4) != 0) {
      lVar2 = *(long *)(param_1 + lVar3 * 0x10 + 0x98);
      if (lVar2 != 0) {
        eventfd_signal(lVar2,1);
        *(ulong *)(param_1 + 0x60) = *(ulong *)(param_1 + 0x60) & (uVar4 ^ 0xffffffffffffffff);
      }
    }
    lVar3 = lVar3 + 1;
  } while (lVar3 != 4);
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 00106608 size=124
// signature: undefined readl_relaxed(void)
// callers: [gh_virtio_backend_ioctl]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x106650,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 00106684 size=132
// signature: undefined writel_relaxed(void)
// callers: [gh_virtio_backend_ioctl]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10669c,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1066d8,uVar1);
  return;
}



//------------------------------------------------------------
// gh_virtio_backend_mmap @ 0010670c size=436
// signature: undefined gh_virtio_backend_mmap(void)
// callers: [gh_vm_mmap]
//------------------------------------------------------------

undefined8 gh_virtio_backend_mmap(char *param_1,long *param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puVar3;
  ulong uVar4;
  undefined **ppuVar5;
  long lVar6;
  long lVar7;
  
  _raw_spin_lock(&vm_list_lock);
  ppuVar5 = &vm_list;
  do {
    ppuVar5 = (undefined **)*ppuVar5;
    if (ppuVar5 == &vm_list) {
      _raw_spin_unlock(&vm_list_lock);
      goto LAB_00106810;
    }
    iVar1 = strcmp((char *)(ppuVar5 + 2),param_1);
  } while (iVar1 != 0);
  _raw_spin_unlock(&vm_list_lock);
  if ((ppuVar5 == (undefined **)0x0) ||
     (lVar7 = *param_2, lVar6 = param_2[1], (undefined *)(lVar6 - lVar7) != ppuVar5[0xb])) {
LAB_00106810:
    uVar2 = 0xffffffea;
  }
  else {
    iVar1 = *(int *)(param_2[2] + 0xb0);
    if ((int)param_2[5] != iVar1) {
      down_write(param_2[6]);
      *(int *)(param_2 + 5) = iVar1;
      up_write(param_2[6]);
    }
    param_2[4] = param_2[4] | 0x4040000;
    if (*(char *)(ppuVar5 + 0xd) == '\0') {
      if (0 < *(int *)(ppuVar5 + 7)) {
        uVar4 = 0;
        lVar7 = 0;
        puVar3 = ppuVar5[6];
        lVar6 = 0;
        do {
          iVar1 = remap_pfn_range(param_2,*param_2 + lVar7,*(ulong *)(puVar3 + lVar6) >> 0xc,
                                  (int)*(ulong *)((long)(puVar3 + lVar6) + 0x60),param_2[3]);
          if (iVar1 != 0) {
            _dev_err(ppuVar5[5],"%s: shmem_entry %d ioremap_pfn_range failed\n","gh_virtio_backend",
                     uVar4 & 0xffffffff);
            return 0xfffffff5;
          }
          puVar3 = ppuVar5[6];
          uVar4 = uVar4 + 1;
          lVar7 = lVar7 + (ulong)*(uint *)(puVar3 + lVar6 + 0x60);
          lVar6 = lVar6 + 0x78;
        } while ((long)uVar4 < (long)*(int *)(ppuVar5 + 7));
      }
      uVar2 = 0;
    }
    else {
      uVar2 = remap_pfn_range(param_2,*param_2,(ulong)ppuVar5[10] >> 0xc,
                              (undefined *)(lVar6 - lVar7),param_2[3]);
      if ((int)uVar2 != 0) {
        _dev_err(ppuVar5[5],"%s: ioremap_pfn_range failed\n","gh_virtio_backend");
        uVar2 = 0xfffffff5;
      }
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// gh_parse_virtio_properties @ 001068c4 size=2356
// signature: undefined gh_parse_virtio_properties(void)
// callers: [gh_secure_vm_loader_probe]
//------------------------------------------------------------

undefined8 gh_parse_virtio_properties(long *param_1,char *param_2)

{
  undefined **ppuVar1;
  uint uVar2;
  long *plVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  int iVar7;
  long lVar8;
  size_t sVar9;
  ulong uVar10;
  undefined *puVar11;
  long lVar12;
  undefined8 *puVar13;
  char *pcVar14;
  long lVar15;
  undefined8 uVar16;
  undefined **ppuVar17;
  uint uVar18;
  undefined **ppuVar19;
  long lVar20;
  uint local_130;
  int local_12c;
  uint local_128;
  uint local_124;
  undefined *local_120;
  long local_118;
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
  long local_c0 [12];
  
  lVar8 = sp_el0;
  uVar16 = 0xffffffea;
  local_c0[10] = *(long *)(lVar8 + 0x638);
  local_130 = 0;
  if ((param_1 != (long *)0x0) && (param_2 != (char *)0x0)) {
    lVar20 = param_1[0x5d];
    lVar8 = of_find_property(lVar20,"virtio-backends",&local_130);
    if ((lVar8 == 0) || (local_130 < 4)) {
      uVar16 = 0;
    }
    else {
      uVar4 = local_130 >> 2;
      uVar18 = 0;
      if (uVar4 < 2) {
        uVar4 = 1;
      }
      do {
        local_e0 = 0;
        uStack_d8 = 0;
        local_f0 = 0;
        uStack_e8 = 0;
        local_100 = 0;
        uStack_f8 = 0;
        local_110 = 0;
        uStack_108 = 0;
        local_120 = (undefined *)0x0;
        local_118 = 0;
        iVar7 = __of_parse_phandle_with_args(lVar20,"virtio-backends",0,0,uVar18,&local_120);
        puVar11 = local_120;
        if ((iVar7 != 0) || (local_120 == (undefined *)0x0)) {
          _dev_err(param_1,"%s: Can\'t parse virtio-backends property %d\n","gh_virtio_backend",
                   uVar18);
          uVar16 = 0xffffffea;
          break;
        }
        local_12c = 0;
        local_e0 = 0;
        uStack_d8 = 0;
        local_f0 = 0;
        uStack_e8 = 0;
        local_100 = 0;
        uStack_f8 = 0;
        local_110 = 0;
        uStack_108 = 0;
        local_120 = (undefined *)0x0;
        local_118 = 0;
        iVar7 = __of_parse_phandle_with_args(puVar11,"qcom,vm",0,0,0,&local_120);
        puVar6 = local_120;
        if ((iVar7 != 0) || (local_120 == (undefined *)0x0)) {
          pcVar14 = "%s: \'qcom,vm\' property not present\n";
LAB_001070fc:
          _dev_err(param_1,pcVar14,"gh_virtio_backend");
LAB_0010710c:
          uVar16 = 0xffffffea;
LAB_00106fb0:
          mutex_lock(vm_mutex);
          _raw_spin_lock(&vm_list_lock);
          ppuVar17 = &vm_list;
          goto LAB_00106fcc;
        }
        sVar9 = strnlen(param_2,0x10);
        if (sVar9 == 0x10) {
          _dev_err(param_1,"%s: VM name %s too long\n","gh_virtio_backend",param_2);
          goto LAB_0010710c;
        }
        if (sVar9 == 0xffffffffffffffff) {
LAB_001071b4:
          fortify_panic("strnlen");
LAB_001071c0:
          fortify_panic("strscpy");
          __dynamic_dev_dbg(&gh_parse_virtio_properties___UNIQUE_ID_ddebug483,param_1,
                            "%s: No virtio-backends specified for vm %s\n","gh_virtio_backend",
                            param_2);
          uVar16 = 0;
          break;
        }
        iVar7 = of_property_read_variable_u32_array(puVar11,"qcom,label",&local_12c,1,0);
        if ((iVar7 < 0) || (local_12c == 0)) {
          pcVar14 = "%s: Invalid qcom,label property\n";
          goto LAB_001070fc;
        }
        mutex_lock(vm_mutex);
        _raw_spin_lock(&vm_list_lock);
        ppuVar17 = &vm_list;
        do {
          ppuVar17 = (undefined **)*ppuVar17;
          if (ppuVar17 == &vm_list) {
            _raw_spin_unlock(&vm_list_lock);
            goto LAB_00106a74;
          }
          iVar7 = strcmp((char *)(ppuVar17 + 2),param_2);
        } while (iVar7 != 0);
        _raw_spin_unlock(&vm_list_lock);
        if (ppuVar17 == (undefined **)0x0) {
LAB_00106a74:
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
          local_120 = (undefined *)0x0;
          local_118 = 0;
          local_128 = 0;
          ppuVar17 = (undefined **)devm_kmalloc(param_1,0x70,0xdc0);
          if (ppuVar17 != (undefined **)0x0) {
            uVar10 = strnlen(param_2,0x10);
            if (uVar10 == 0xffffffffffffffff) goto LAB_001071b4;
            if (uVar10 != 0x10) {
              uVar10 = uVar10 + 1;
            }
            if (0x10 < uVar10) goto LAB_001071c0;
            ppuVar1 = ppuVar17 + 2;
            strscpy(ppuVar1,param_2);
            ppuVar17[5] = (undefined *)param_1;
            local_124 = 0;
            lVar8 = of_find_property(puVar6,"shared-buffers",&local_124);
            if ((lVar8 == 0) || (local_124 < 4)) {
              _dev_err(ppuVar17[5],"%s: No shared-buffers specified for vm %s\n","gh_virtio_backend"
                       ,ppuVar1);
            }
            else {
              uVar5 = local_124 >> 2;
              puVar11 = (undefined *)devm_kmalloc(ppuVar17[5],(ulong)uVar5 * 0x78,0xdc0);
              ppuVar17[6] = puVar11;
              if (puVar11 != (undefined *)0x0) {
                uVar10 = 0;
                uVar2 = uVar5;
                if (uVar5 < 2) {
                  uVar2 = 1;
                }
                lVar8 = 0x60;
                do {
                  local_c0[8] = 0;
                  local_c0[9] = 0;
                  local_c0[6] = 0;
                  local_c0[7] = 0;
                  local_c0[4] = 0;
                  local_c0[5] = 0;
                  local_c0[2] = 0;
                  local_c0[3] = 0;
                  local_c0[0] = 0;
                  local_c0[1] = 0;
                  iVar7 = __of_parse_phandle_with_args
                                    (puVar6,"shared-buffers",0,0,uVar10 & 0xffffffff,local_c0);
                  lVar15 = local_c0[0];
                  if ((iVar7 != 0) || (local_c0[0] == 0)) {
                    puVar11 = ppuVar17[5];
                    pcVar14 = "%s: Can\'t parse shared-buffer property %d\n";
LAB_00106f90:
                    _dev_err(puVar11,pcVar14,"gh_virtio_backend",uVar10 & 0xffffffff);
                    goto LAB_00106fa0;
                  }
                  lVar12 = of_find_property(local_c0[0],"no-map",0);
                  if (lVar12 == 0) {
                    *(undefined1 *)(ppuVar17 + 0xd) = 0;
                    iVar7 = of_property_read_variable_u32_array
                                      (lVar15,&DAT_0010dd62,ppuVar17[6] + lVar8,1,0);
                    if (-1 < iVar7) goto LAB_00106be8;
                    puVar11 = ppuVar17[5];
                    pcVar14 = "%s: Invalid size at index %d\n";
                    goto LAB_00106f90;
                  }
                  *(undefined1 *)(ppuVar17 + 0xd) = 1;
                  iVar7 = of_address_to_resource(lVar15,0,ppuVar17[6] + lVar8 + -0x60);
                  if (iVar7 != 0) {
                    puVar11 = ppuVar17[5];
                    pcVar14 = "%s: Invalid address at index %d\n";
                    goto LAB_00106f90;
                  }
LAB_00106be8:
                  iVar7 = of_property_read_variable_u32_array
                                    (lVar15,"gunyah-label",ppuVar17[6] + lVar8 + 4,1,0);
                  if (iVar7 < 0) {
                    puVar11 = ppuVar17[5];
                    pcVar14 = "%s: gunyah-label property absent at index %d\n";
                    goto LAB_00106f90;
                  }
                  uVar10 = uVar10 + 1;
                  lVar8 = lVar8 + 0x78;
                } while (uVar2 != uVar10);
                *(uint *)(ppuVar17 + 7) = uVar5;
                if (*(char *)(ppuVar17 + 0xd) == '\0') {
                  puVar11 = (undefined *)devm_kmalloc(param_1,0x390,0xdc0);
                  if (puVar11 != (undefined *)0x0) {
                    device_initialize();
                    lVar8 = param_1[0xe];
                    if (lVar8 == 0) {
                      lVar8 = *param_1;
                    }
                    dev_set_name(puVar11,"%s:%s",lVar8,"com_mem");
                    lVar8 = param_1[0x54];
                    lVar15 = param_1[0x53];
                    *(long **)(puVar11 + 0x60) = param_1;
                    *(long *)(puVar11 + 0x2a0) = lVar8;
                    *(long *)(puVar11 + 0x298) = lVar15;
                    *(code **)(puVar11 + 0x328) = gh_memdev_release;
                    lVar8 = devm_kmalloc(param_1,0x10,0xdc0);
                    *(long *)(puVar11 + 0x2b8) = lVar8;
                    if (lVar8 != 0) {
                      of_dma_configure_id(puVar11,param_1[0x5d],1,0);
                      iVar7 = device_add(puVar11);
                      if (iVar7 == 0) {
                        iVar7 = of_reserved_mem_device_init_by_idx(puVar11,param_1[0x5d],1);
                        if (iVar7 == 0) {
                          ppuVar17[0xc] = puVar11;
                          iVar7 = of_property_read_variable_u32_array
                                            (puVar6,"shared-buffers-size",&local_128,1,0);
                          if (-1 < iVar7) {
                            ppuVar17[0xb] = (undefined *)(ulong)local_128;
                            _dev_info(ppuVar17[5],"%s: Recognized VM \'%s\' shmem_size %llx\n",
                                      "gh_virtio_backend",ppuVar1);
                            goto LAB_00106d24;
                          }
                          puVar11 = ppuVar17[5];
                          pcVar14 = "%s: Invalid shared memory size for VM %s\n";
                          goto LAB_00107090;
                        }
                        device_del(puVar11);
                      }
                    }
                    put_device(puVar11);
                  }
                  ppuVar17[0xc] = (undefined *)0x0;
                }
                else {
                  iVar7 = of_address_to_resource(puVar6,0,&local_120);
                  if (((iVar7 == 0) && (local_120 != (undefined *)0x0)) &&
                     (puVar11 = (undefined *)((local_118 + 1) - (long)local_120),
                     puVar11 != (undefined *)0x0)) {
                    ppuVar17[10] = local_120;
                    ppuVar17[0xb] = puVar11;
                    _dev_info(ppuVar17[5],
                              "%s: Recognized VM \'%s\' shmem_addr %pK shmem_size %llx\n",
                              "gh_virtio_backend",ppuVar1);
LAB_00106d24:
                    *(undefined4 *)((long)ppuVar17 + 0x3c) = 0;
                    ppuVar17[8] = (undefined *)(ppuVar17 + 8);
                    ppuVar17[9] = (undefined *)(ppuVar17 + 8);
                    _raw_spin_lock(&vm_list_lock);
                    puVar11 = vm_list;
                    uVar10 = __list_add_valid(ppuVar17,&vm_list,vm_list);
                    if ((uVar10 & 1) != 0) {
                      *(undefined ***)(puVar11 + 8) = ppuVar17;
                      *ppuVar17 = puVar11;
                      ppuVar17[1] = (undefined *)&vm_list;
                      vm_list = (undefined *)ppuVar17;
                    }
                    _raw_spin_unlock(&vm_list_lock);
                    goto LAB_00106d70;
                  }
                  puVar11 = ppuVar17[5];
                  pcVar14 = "%s: Invalid shared memory for VM %s\n";
LAB_00107090:
                  _dev_err(puVar11,pcVar14,"gh_virtio_backend",param_2);
                }
              }
            }
          }
LAB_00106fa0:
          mutex_unlock(vm_mutex);
          uVar16 = 0xffffffed;
          goto LAB_00106fb0;
        }
LAB_00106d70:
        lVar8 = (long)ppuVar17 + 0x3c;
        _raw_spin_lock(lVar8);
        ppuVar1 = ppuVar17 + 8;
        ppuVar19 = ppuVar1;
        do {
          ppuVar19 = (undefined **)*ppuVar19;
          if (ppuVar19 == ppuVar1) {
            _raw_spin_unlock(lVar8);
            goto LAB_00106db8;
          }
        } while (local_12c != *(int *)((long)ppuVar19 + 0x7c));
        _raw_spin_unlock(lVar8);
        if (ppuVar19 != (undefined **)0x0) {
          puVar11 = ppuVar19[0x11];
          _raw_spin_lock(puVar11 + 0x3c);
          iVar7 = *(int *)(ppuVar19 + 9);
          *(int *)(ppuVar19 + 9) = iVar7 + -1;
          if ((iVar7 + -1 == 0) && (*(int *)((long)ppuVar19 + 0x4c) != 0)) {
            __wake_up(ppuVar19 + 6,3,1,0);
          }
          _raw_spin_unlock(puVar11 + 0x3c);
          mutex_unlock(vm_mutex);
          _dev_err(param_1,"%s: Duplicate qcom,label %d\n","gh_virtio_backend",local_12c);
          goto LAB_0010710c;
        }
LAB_00106db8:
        puVar13 = (undefined8 *)devm_kmalloc(param_1,0x1e0,0xdc0);
        if (puVar13 == (undefined8 *)0x0) {
          mutex_unlock(vm_mutex);
          uVar16 = 0xfffffff4;
          goto LAB_00106fb0;
        }
        puVar13[0x11] = ppuVar17;
        *(int *)((long)puVar13 + 0x7c) = local_12c;
        *(undefined4 *)(puVar13 + 2) = 0;
        __init_waitqueue_head(puVar13 + 3,"&vb_dev->evt_queue",&gh_virtio_backend_probe___key);
        __init_waitqueue_head(puVar13 + 6,"&vb_dev->notify_queue",&gh_virtio_backend_probe___key_65)
        ;
        __mutex_init(puVar13 + 0x31,"&vb_dev->mutex",&gh_virtio_backend_probe___key_67);
        _raw_spin_lock(lVar8);
        puVar11 = ppuVar17[8];
        uVar10 = __list_add_valid(puVar13,ppuVar1,puVar11);
        if ((uVar10 & 1) != 0) {
          *(undefined8 **)(puVar11 + 8) = puVar13;
          *puVar13 = puVar11;
          puVar13[1] = ppuVar1;
          *ppuVar1 = (undefined *)puVar13;
        }
        _raw_spin_unlock(lVar8);
        snprintf((char *)(puVar13 + 0x2a),0x20,"virtio_dev_%x",*(uint *)((long)puVar13 + 0x7c));
        mutex_unlock(vm_mutex);
        _printk(&DAT_0010ec15,"gh_virtio_backend",ppuVar17 + 2,*(undefined4 *)((long)puVar13 + 0x7c)
               );
        uVar16 = 0;
        uVar18 = uVar18 + 1;
      } while (uVar18 != uVar4);
    }
  }
  goto LAB_00107048;
  while (iVar7 = strcmp((char *)(ppuVar17 + 2),param_2), iVar7 != 0) {
LAB_00106fcc:
    ppuVar17 = (undefined **)*ppuVar17;
    if (ppuVar17 == &vm_list) goto LAB_00107030;
  }
  _raw_spin_unlock(&vm_list_lock);
  if (ppuVar17 != (undefined **)0x0) {
    _raw_spin_lock(&vm_list_lock);
    uVar10 = __list_del_entry_valid(ppuVar17);
    if ((uVar10 & 1) != 0) {
      puVar11 = *ppuVar17;
      plVar3 = (long *)ppuVar17[1];
      *(long **)(puVar11 + 8) = plVar3;
      *plVar3 = (long)puVar11;
    }
    *ppuVar17 = (undefined *)0xdead000000000100;
    ppuVar17[1] = (undefined *)0xdead000000000122;
LAB_00107030:
    _raw_spin_unlock(&vm_list_lock);
  }
  mutex_unlock(vm_mutex);
LAB_00107048:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_c0[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar16;
}



//------------------------------------------------------------
// gh_virtio_backend_remove @ 001071fc size=204
// signature: undefined gh_virtio_backend_remove(void)
// callers: [gh_secure_vm_loader_remove]
//------------------------------------------------------------

undefined8 gh_virtio_backend_remove(char *param_1)

{
  undefined *puVar1;
  long *plVar2;
  int iVar3;
  ulong uVar4;
  undefined **ppuVar5;
  
  _raw_spin_lock(&vm_list_lock);
  ppuVar5 = &vm_list;
  do {
    ppuVar5 = (undefined **)*ppuVar5;
    if (ppuVar5 == &vm_list) {
      _raw_spin_unlock(&vm_list_lock);
      return 0;
    }
    iVar3 = strcmp((char *)(ppuVar5 + 2),param_1);
  } while (iVar3 != 0);
  _raw_spin_unlock(&vm_list_lock);
  if (ppuVar5 != (undefined **)0x0) {
    _raw_spin_lock(&vm_list_lock);
    uVar4 = __list_del_entry_valid(ppuVar5);
    if ((uVar4 & 1) != 0) {
      puVar1 = *ppuVar5;
      plVar2 = (long *)ppuVar5[1];
      *(long **)(puVar1 + 8) = plVar2;
      *plVar2 = (long)puVar1;
    }
    *ppuVar5 = (undefined *)0xdead000000000100;
    ppuVar5[1] = (undefined *)0xdead000000000122;
    _raw_spin_unlock(&vm_list_lock);
  }
  return 0;
}



//------------------------------------------------------------
// gh_virtio_mmio_exit @ 001072f0 size=504
// signature: undefined gh_virtio_mmio_exit(void)
// callers: [gh_destroy_vm]
//------------------------------------------------------------

void gh_virtio_mmio_exit(undefined4 param_1,char *param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  _raw_spin_lock(&vm_list_lock);
  ppuVar4 = &vm_list;
  do {
    ppuVar4 = (undefined **)*ppuVar4;
    if (ppuVar4 == &vm_list) {
      _raw_spin_unlock(&vm_list_lock);
      goto code_r0x00107490;
    }
    iVar2 = strcmp((char *)(ppuVar4 + 2),param_2);
  } while (iVar2 != 0);
  _raw_spin_unlock(&vm_list_lock);
  if (ppuVar4 == (undefined **)0x0) {
code_r0x00107490:
    uVar3 = 0;
  }
  else {
    lVar1 = (long)ppuVar4 + 0x3c;
    _raw_spin_lock(lVar1);
    for (ppuVar5 = (undefined **)ppuVar4[8]; ppuVar5 != ppuVar4 + 8;
        ppuVar5 = (undefined **)*ppuVar5) {
      uVar3 = _raw_spin_lock_irqsave(ppuVar5 + 2);
      iVar2 = *(int *)(ppuVar5 + 9);
      ppuVar5[0xe] = (undefined *)0x40;
      ppuVar5[0xc] = (undefined *)0x0;
      *(undefined4 *)((long)ppuVar5 + 0x54) = 1;
      *(undefined4 *)((long)ppuVar5 + 0x4c) = 1;
      _raw_spin_unlock_irqrestore(ppuVar5 + 2,uVar3);
      __wake_up(ppuVar5 + 3,1,1,0);
      _raw_spin_unlock(lVar1);
      if ((iVar2 != 0) && (*(int *)(ppuVar5 + 9) != 0)) {
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        uStack_80 = 0;
        local_90 = 0;
        init_wait_entry(&local_90,0);
        while (prepare_to_wait_event(ppuVar5 + 6,&local_90,2), *(int *)(ppuVar5 + 9) != 0) {
          schedule();
        }
        finish_wait(ppuVar5 + 6,&local_90);
      }
      *(undefined4 *)(ppuVar5 + 0x12) = 0;
      *(undefined4 *)(ppuVar5 + 0x14) = 0;
      *(undefined4 *)(ppuVar5 + 0x16) = 0;
      *(undefined4 *)(ppuVar5 + 0x18) = 0;
      free_pages(ppuVar5[0x38],0);
      ppuVar5[0x38] = (undefined *)0x0;
      *(undefined4 *)(ppuVar5 + 10) = 0;
      free_irq(*(undefined4 *)(ppuVar5 + 0xf),ppuVar5);
      iounmap(ppuVar5[0x3a]);
      ppuVar5[0x3a] = (undefined *)0x0;
      _raw_spin_lock(lVar1);
    }
    _raw_spin_unlock(lVar1);
    uVar3 = unshare_vm_buffers(ppuVar4,param_1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// unshare_vm_buffers @ 00107510 size=308
// signature: undefined unshare_vm_buffers(void)
// callers: [gh_virtio_mmio_exit, gh_virtio_mmio_init]
//------------------------------------------------------------

void unshare_vm_buffers(long param_1,undefined4 param_2)

{
  ulong *puVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  ulong *puVar5;
  ulong *puVar6;
  ulong uVar7;
  long lVar8;
  undefined2 local_3c [2];
  long local_38;
  
  lVar8 = sp_el0;
  local_38 = *(long *)(lVar8 + 0x638);
  local_3c[0] = 0;
  if (*(int *)(param_1 + 0x20) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ghd_rm_get_vmid(1,local_3c);
    if ((int)uVar2 == 0) {
      if (0 < *(int *)(param_1 + 0x38)) {
        lVar8 = 0;
        do {
          lVar3 = *(long *)(param_1 + 0x30) + lVar8 * 0x78;
          uVar2 = unshare_a_vm_buffer(local_3c[0],param_2,lVar3,lVar3);
          if ((int)uVar2 != 0) goto LAB_00107614;
          if (*(char *)(param_1 + 0x68) == '\0') {
            puVar5 = (ulong *)(*(long *)(param_1 + 0x30) + lVar8 * 0x78);
            puVar6 = *(ulong **)(*(long *)(param_1 + 0x60) + 0x2b0);
            uVar4 = *puVar5;
            if (puVar6 != (ulong *)0x0) {
              uVar7 = puVar6[2];
              while (uVar7 != 0) {
                if (*puVar6 <= uVar4 && uVar4 - *puVar6 < uVar7) {
                  uVar4 = uVar4 - puVar6[3];
                  goto LAB_0010757c;
                }
                puVar1 = puVar6 + 6;
                puVar6 = puVar6 + 4;
                uVar7 = *puVar1;
              }
              uVar4 = 0xffffffffffffffff;
            }
LAB_0010757c:
            dma_free_attrs(*(long *)(param_1 + 0x60),(int)puVar5[0xc],puVar5[0xe],uVar4,0);
          }
          lVar8 = lVar8 + 1;
        } while (lVar8 < *(int *)(param_1 + 0x38));
      }
      uVar2 = 0;
      *(undefined4 *)(param_1 + 0x20) = 0;
    }
  }
LAB_00107614:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// gh_virtio_mmio_init @ 00107648 size=1900
// signature: undefined gh_virtio_mmio_init(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong gh_virtio_mmio_init(ulong param_1,char *param_2,int param_3,undefined *param_4,
                         undefined4 param_5,undefined8 param_6,undefined *param_7)

{
  ulong *puVar1;
  undefined **ppuVar2;
  undefined4 uVar3;
  ushort uVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  size_t sVar9;
  undefined *puVar10;
  undefined8 uVar11;
  undefined4 *puVar12;
  undefined2 *puVar13;
  ulong uVar14;
  long lVar15;
  ulong *puVar16;
  ulong *puVar17;
  long lVar18;
  undefined **ppuVar19;
  undefined **ppuVar20;
  ulong uVar21;
  long *plVar22;
  ulong uVar23;
  ulong uVar24;
  ulong local_a0;
  ushort local_94 [2];
  ulong local_90;
  ulong local_88;
  uint local_80;
  undefined4 uStack_7c;
  uint local_78;
  undefined4 uStack_74;
  uint local_70;
  undefined4 uStack_6c;
  long local_68;
  
  lVar15 = sp_el0;
  uVar21 = param_1 & 0xffffffff;
  local_68 = *(long *)(lVar15 + 0x638);
  _raw_spin_lock(&vm_list_lock);
  ppuVar20 = &vm_list;
  do {
    ppuVar20 = (undefined **)*ppuVar20;
    if (ppuVar20 == &vm_list) {
      _raw_spin_unlock(&vm_list_lock);
      goto LAB_00107878;
    }
    iVar6 = strcmp((char *)(ppuVar20 + 2),param_2);
  } while (iVar6 != 0);
  _raw_spin_unlock(&vm_list_lock);
  if (ppuVar20 == (undefined **)0x0) {
LAB_00107878:
    _printk(&DAT_0010e5f0,"gh_virtio_backend",param_2);
    uVar24 = 0xffffffed;
  }
  else {
    while (sVar9 = strnlen(param_2,0x10), sVar9 != 0x10) {
      if (sVar9 != 0xffffffffffffffff) {
        lVar15 = (long)ppuVar20 + 0x3c;
        _raw_spin_lock(lVar15);
        ppuVar19 = ppuVar20 + 8;
        goto LAB_0010770c;
      }
      fortify_panic("strnlen");
      __dynamic_dev_dbg(&gh_virtio_mmio_init___UNIQUE_ID_ddebug487,ppuVar20[5],
                        "%s: vmid %d vm_name %s label %x cap_id %x irq %d base %pK size %d\n",
                        "gh_virtio_backend",(uint)param_1 & 0xffff,param_2,param_3,param_4,param_5,
                        param_6,param_7);
    }
    uVar24 = 0xffffffea;
  }
  goto LAB_00107d18;
  while (*(int *)((long)ppuVar19 + 0x7c) != param_3) {
LAB_0010770c:
    ppuVar19 = (undefined **)*ppuVar19;
    if (ppuVar19 == ppuVar20 + 8) goto LAB_00107b34;
  }
  if ((*(int *)(ppuVar19 + 9) == -1) || (ppuVar19 == (undefined **)0x0)) {
LAB_00107b34:
    _raw_spin_unlock(lVar15);
    _dev_err(ppuVar20[5],"%s: Device with label %x not found\n","gh_virtio_backend",param_3);
    uVar24 = 0xffffffed;
  }
  else {
    *(int *)(ppuVar19 + 9) = *(int *)(ppuVar19 + 9) + 1;
    _raw_spin_unlock(lVar15);
    ppuVar2 = ppuVar19 + 0x31;
    mutex_lock(ppuVar2);
    if (*(int *)(ppuVar20 + 4) == 0) {
      local_94[0] = 0;
      local_a0 = 0;
      uVar7 = ghd_rm_get_vmid(1,local_94);
      if (uVar7 != 0) {
        uVar24 = (ulong)uVar7;
LAB_00107ccc:
        mutex_unlock(ppuVar2);
        puVar10 = ppuVar19[0x11];
        _raw_spin_lock(puVar10 + 0x3c);
        iVar6 = *(int *)(ppuVar19 + 9);
        *(int *)(ppuVar19 + 9) = iVar6 + -1;
        if ((iVar6 + -1 == 0) && (*(int *)((long)ppuVar19 + 0x4c) != 0)) {
          __wake_up(ppuVar19 + 6,3,1,0);
        }
        _raw_spin_unlock(puVar10 + 0x3c);
        goto LAB_00107d18;
      }
      if (0 < *(int *)(ppuVar20 + 7)) {
        uVar23 = 0;
        do {
          iVar6 = (int)uVar23;
          if (*(char *)(ppuVar20 + 0xd) == '\0') {
            lVar15 = uVar23 * 0x78;
            uVar11 = dma_alloc_attrs(ppuVar20[0xc],*(undefined4 *)(ppuVar20[6] + lVar15 + 0x60),
                                     &local_a0,0xcc0,0);
            *(undefined8 *)(ppuVar20[6] + lVar15 + 0x70) = uVar11;
            if (*(long *)(ppuVar20[6] + lVar15 + 0x70) != 0) {
              lVar18 = *(long *)(ppuVar20[0xc] + 0x2b0);
              uVar24 = local_a0;
              if (lVar18 != 0) {
                uVar24 = *(ulong *)(lVar18 + 0x10);
                if (uVar24 != 0) {
                  plVar22 = (long *)(lVar18 + 0x18);
                  do {
                    if ((ulong)plVar22[-2] <= local_a0 && local_a0 - plVar22[-2] < uVar24) {
                      uVar24 = *plVar22 + local_a0;
                      goto LAB_00107960;
                    }
                    uVar24 = plVar22[3];
                    plVar22 = plVar22 + 4;
                  } while (uVar24 != 0);
                }
                uVar24 = 0xffffffffffffffff;
              }
LAB_00107960:
              *(ulong *)(ppuVar20[6] + lVar15) = uVar24;
              plVar22 = (long *)(ppuVar20[6] + lVar15);
              plVar22[1] = *plVar22 + (ulong)*(uint *)(plVar22 + 0xc) + -1;
              goto LAB_00107980;
            }
            uVar24 = 0xfffffff4;
            uVar23 = (ulong)(iVar6 - 1);
joined_r0x00107d60:
            if (-1 < iVar6 + -1) {
              lVar15 = (ulong)(iVar6 - 1) * 0x78;
              do {
                unshare_a_vm_buffer(local_94[0],uVar21,ppuVar20[6] + lVar15,ppuVar20[6] + lVar15);
                bVar5 = lVar15 != 0;
                lVar15 = lVar15 + -0x78;
              } while (bVar5);
            }
            if ((*(char *)(ppuVar20 + 0xd) == '\0') && (-1 < (int)uVar23)) {
              uVar21 = uVar23 & 0xffffffff;
              do {
                puVar16 = (ulong *)(ppuVar20[6] + uVar21 * 0x78);
                puVar17 = *(ulong **)(ppuVar20[0xc] + 0x2b0);
                uVar23 = *puVar16;
                if (puVar17 != (ulong *)0x0) {
                  uVar14 = puVar17[2];
                  while (uVar14 != 0) {
                    if (*puVar17 <= uVar23 && uVar23 - *puVar17 < uVar14) {
                      uVar23 = uVar23 - puVar17[3];
                      goto LAB_00107c5c;
                    }
                    puVar1 = puVar17 + 6;
                    puVar17 = puVar17 + 4;
                    uVar14 = *puVar1;
                  }
                  uVar23 = 0xffffffffffffffff;
                }
LAB_00107c5c:
                dma_free_attrs(ppuVar20[0xc],(int)puVar16[0xc],puVar16[0xe],uVar23,0);
                bVar5 = 0 < (long)uVar21;
                uVar21 = uVar21 - 1;
              } while (bVar5);
            }
            goto LAB_00107ccc;
          }
LAB_00107980:
          uVar4 = local_94[0];
          plVar22 = (long *)(ppuVar20[6] + uVar23 * 0x78);
          local_88 = 1L << ((ulong)local_94[0] & 0x3f);
          uVar3 = *(undefined4 *)((long)plVar22 + 100);
          local_90 = local_88 | 1L << (param_1 & 0x3f);
          local_80 = (uint)local_94[0];
          uStack_6c = 7;
          uStack_7c = 6;
          uStack_74 = 6;
          local_78 = (uint)param_1 & 0xffff;
          local_70 = local_80;
          puVar12 = (undefined4 *)kmalloc_trace(_gh_rm_mem_donate,0xdc0,0xc);
          if (puVar12 == (undefined4 *)0x0) {
LAB_00107c08:
            uVar24 = 0xfffffff4;
            goto joined_r0x00107d60;
          }
          puVar13 = (undefined2 *)kmalloc_trace(_gh_rm_mem_donate,0xdc0,0x14);
          if (puVar13 == (undefined2 *)0x0) {
            kfree(puVar12);
            goto LAB_00107c08;
          }
          uVar14 = qcom_scm_assign_mem(*plVar22,(plVar22[1] - *plVar22) + 1,&local_88,&local_80,2);
          uVar24 = uVar14 & 0xffffffff;
          if ((int)uVar14 == 0) {
            *(ushort *)(puVar12 + 1) = uVar4;
            *(short *)(puVar12 + 2) = (short)uVar21;
            *puVar12 = 2;
            *(undefined1 *)((long)puVar12 + 6) = 6;
            *(undefined1 *)((long)puVar12 + 10) = 6;
            *puVar13 = 1;
            lVar15 = *plVar22;
            *(long *)(puVar13 + 2) = lVar15;
            *(long *)(puVar13 + 6) = (plVar22[1] - lVar15) + 1;
            uVar7 = ghd_rm_mem_share(uVar14,0,uVar3,puVar12,puVar13,0,plVar22 + 0xd);
            if (uVar7 != 0) {
              uVar24 = (ulong)uVar7;
              _printk(&DAT_0010f4b6,"gh_virtio_backend",uVar24);
              iVar8 = qcom_scm_assign_mem(*plVar22,(plVar22[1] - *plVar22) + 1,&local_90,&local_70,1
                                         );
              if (iVar8 != 0) {
                _printk(&DAT_0010e3d1,"gh_virtio_backend",*plVar22,(plVar22[1] - *plVar22) + 1);
              }
            }
          }
          else {
            _printk(&DAT_0010da5e,"gh_virtio_backend",*plVar22,(plVar22[1] - *plVar22) + 1,uVar24);
          }
          kfree(puVar12);
          kfree(puVar13);
          if ((int)uVar24 != 0) goto joined_r0x00107d60;
          uVar23 = uVar23 + 1;
        } while ((long)uVar23 < (long)*(int *)(ppuVar20 + 7));
      }
      *(undefined4 *)(ppuVar20 + 4) = 1;
    }
    uVar7 = request_threaded_irq(param_5,vdev_interrupt,0,0,ppuVar19 + 0x2a,ppuVar19);
    if (uVar7 == 0) {
      uVar11 = 0x68000000000713;
      if (arm64_use_ng_mappings != '\0') {
        uVar11 = 0x68000000000f13;
      }
      puVar10 = (undefined *)ioremap_prot(param_6,param_7,uVar11);
      ppuVar19[0x3a] = puVar10;
      if (puVar10 == (undefined *)0x0) {
        _dev_err(ppuVar20[5],"%s: Unable to map config page\n","gh_virtio_backend");
        free_irq(param_5,ppuVar19);
        unshare_vm_buffers(ppuVar20,uVar21);
        mutex_unlock(ppuVar2);
        vb_dev_put(ppuVar19);
        uVar24 = 0xfffffff4;
      }
      else {
        *(undefined4 *)(ppuVar19 + 0xf) = param_5;
        ppuVar19[0x37] = param_4;
        ppuVar19[0x3b] = param_7;
        uVar11 = _raw_spin_lock_irqsave(ppuVar19 + 2);
        *(undefined4 *)((long)ppuVar19 + 0x4c) = 0;
        *(undefined8 *)((long)ppuVar19 + 0x54) = 0;
        *(undefined8 *)((long)ppuVar19 + 0x5c) = 0;
        *(undefined8 *)((long)ppuVar19 + 100) = 0;
        *(undefined8 *)((long)ppuVar19 + 0x6c) = 0;
        *(undefined4 *)((long)ppuVar19 + 0x74) = 0;
        _raw_spin_unlock_irqrestore(ppuVar19 + 2,uVar11);
        mutex_unlock(ppuVar2);
        puVar10 = ppuVar19[0x11];
        _raw_spin_lock(puVar10 + 0x3c);
        iVar6 = *(int *)(ppuVar19 + 9);
        *(int *)(ppuVar19 + 9) = iVar6 + -1;
        if ((iVar6 + -1 == 0) && (*(int *)((long)ppuVar19 + 0x4c) != 0)) {
          __wake_up(ppuVar19 + 6,3,1,0);
        }
        _raw_spin_unlock(puVar10 + 0x3c);
        uVar24 = 0;
      }
    }
    else {
      uVar24 = (ulong)uVar7;
      _dev_err(ppuVar20[5],"%s: Unable to register interrupt handler for %d\n","gh_virtio_backend",
               param_5);
      unshare_vm_buffers(ppuVar20,uVar21);
      mutex_unlock(ppuVar2);
      vb_dev_put(ppuVar19);
    }
  }
LAB_00107d18:
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar24;
}



//------------------------------------------------------------
// trace_raw_output_gh_virtio_backend_irq_inj @ 00107de4 size=100
// signature: undefined trace_raw_output_gh_virtio_backend_irq_inj(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_gh_virtio_backend_irq_inj(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"device %d inj_irq rc %d\n",*(undefined4 *)(lVar2 + 8),
                       *(undefined4 *)(lVar2 + 0xc));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_gh_virtio_backend_queue_notify @ 00107e4c size=100
// signature: undefined trace_raw_output_gh_virtio_backend_queue_notify(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_gh_virtio_backend_queue_notify
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"device %d queue_notify on %d\n",*(undefined4 *)(lVar2 + 8),
                       *(undefined4 *)(lVar2 + 0xc));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_gh_virtio_backend_wait_event @ 00107eb4 size=108
// signature: undefined trace_raw_output_gh_virtio_backend_wait_event(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_gh_virtio_backend_wait_event
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"device %d cur_evt/org_evt %x/%x, cur_evt_data/org_evt_data %x/%x\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14),
                       *(undefined4 *)(lVar2 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_gh_virtio_backend_irq @ 00107f24 size=104
// signature: undefined trace_raw_output_gh_virtio_backend_irq(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_gh_virtio_backend_irq(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"device %d irq (rc %d) event %x event_data %x\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0x14),
                       *(undefined4 *)(lVar2 + 0xc),*(undefined4 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// vb_dev_irqfd_wakeup @ 00107f90 size=180
// signature: undefined vb_dev_irqfd_wakeup(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
vb_dev_irqfd_wakeup(long param_1,undefined8 param_2,undefined8 param_3,ulong param_4,
                   undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  undefined1 auVar4 [16];
  
  lVar1 = sp_el0;
  lVar2 = *(long *)(lVar1 + 0x638);
  uVar3 = (uint)param_4;
  lVar1 = param_1;
  if ((param_4 & 1) != 0) {
    lVar1 = *(long *)(param_1 + 0xe0);
    param_2 = 1;
    param_4 = 0;
    param_5 = 0;
    param_6 = 0;
    param_7 = 0;
    param_8 = 0;
    CallHyperVisor(0x604e);
  }
  auVar4._8_8_ = param_2;
  auVar4._0_8_ = lVar1;
  if ((uVar3 >> 4 & 1) != 0) {
    auVar4 = queue_work_on(0x20,_system_wq,param_1 + 0x48,param_4,param_5,param_6,param_7,param_8);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != lVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(auVar4._0_8_,auVar4._8_8_);
  }
  return 0;
}



//------------------------------------------------------------
// irqfd_shutdown @ 001080f8 size=176
// signature: undefined irqfd_shutdown(void)
// callers: []
//------------------------------------------------------------

void irqfd_shutdown(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  uVar2 = _raw_spin_lock_irqsave(param_1 + -0x110);
  if (*(long *)(param_1 + -0x50) != 0) {
    eventfd_ctx_remove_wait_queue(*(long *)(param_1 + -0x50),param_1 + -0x48,&local_40);
    eventfd_ctx_put(*(undefined8 *)(param_1 + -0x50));
    if ((*(byte *)(param_1 + -8) & 1) != 0) {
      fput(*(undefined8 *)(param_1 + -0x10));
    }
    *(undefined8 *)(param_1 + -0x50) = 0;
    *(undefined8 *)(param_1 + -0x10) = 0;
  }
  _raw_spin_unlock_irqrestore(param_1 + -0x110,uVar2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// vb_dev_irqfd_ptable_queue_proc @ 001081ac size=36
// signature: undefined vb_dev_irqfd_ptable_queue_proc(void)
// callers: []
//------------------------------------------------------------

void vb_dev_irqfd_ptable_queue_proc(undefined8 param_1,undefined8 param_2,long param_3)

{
  add_wait_queue(param_2,param_3 + -0x28);
  return;
}



//------------------------------------------------------------
// gh_memdev_release @ 001081d4 size=28
// signature: undefined gh_memdev_release(void)
// callers: []
//------------------------------------------------------------

void gh_memdev_release(void)

{
  of_reserved_mem_device_release();
  return;
}



//------------------------------------------------------------
// unshare_a_vm_buffer @ 001081f0 size=268
// signature: undefined unshare_a_vm_buffer(void)
// callers: [unshare_vm_buffers, gh_virtio_mmio_init]
//------------------------------------------------------------

int unshare_a_vm_buffer(ulong param_1,ulong param_2,long *param_3,long param_4)

{
  long lVar1;
  int iVar2;
  ulong local_48;
  uint local_40 [2];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 1L << (param_2 & 0x3f) | 1L << (param_1 & 0x3f);
  local_40[0] = (uint)param_1 & 0xffff;
  local_40[1] = 7;
  iVar2 = ghd_rm_mem_reclaim(*(undefined4 *)(param_4 + 0x68),0);
  if (iVar2 == 0) {
    iVar2 = qcom_scm_assign_mem(*param_3,(param_3[1] - *param_3) + 1,&local_48,local_40,1);
    if (iVar2 != 0) {
      _printk(&DAT_0010da5e,"gh_virtio_backend",*param_3,(param_3[1] - *param_3) + 1,iVar2);
    }
  }
  else {
    _printk(&DAT_0010f46d,"gh_virtio_backend",*(undefined4 *)(param_4 + 0x68),*param_3,
            (param_3[1] - *param_3) + 1,iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// vdev_interrupt @ 00108300 size=296
// signature: undefined vdev_interrupt(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00108380) */
/* WARNING: Removing unreachable block (ram,0x00108398) */
/* WARNING: Removing unreachable block (ram,0x001083b0) */
/* WARNING: Removing unreachable block (ram,0x001083a0) */
/* WARNING: Removing unreachable block (ram,0x001083e4) */

undefined8 vdev_interrupt(void)

{
  long lVar1;
  long lVar2;
  
  lVar1 = sp_el0;
  CallHyperVisor(0x6053);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != *(long *)(lVar1 + 0x638)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// gh_vm_ioctl_set_fw_name @ 00108780 size=1828
// signature: undefined gh_vm_ioctl_set_fw_name(void)
// callers: [gh_vm_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long gh_vm_ioctl_set_fw_name(undefined1 *param_1,ulong param_2)

{
  byte *pbVar1;
  uint *puVar2;
  char *__string;
  undefined *puVar3;
  uint uVar4;
  long lVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  size_t sVar9;
  undefined *puVar10;
  void *__src;
  char *pcVar11;
  ulong extraout_x1;
  undefined8 *puVar12;
  undefined *puVar13;
  undefined *puVar14;
  undefined8 *extraout_x8;
  ulong uVar15;
  long *plVar16;
  undefined *puVar17;
  ulong uVar18;
  uint uVar19;
  undefined4 uVar20;
  undefined **ppuVar21;
  undefined *puVar22;
  undefined *local_a0;
  undefined *local_98;
  undefined8 local_90;
  undefined8 local_88;
  ulong uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  puVar12 = (undefined8 *)sp_el0;
  local_88 = 0;
  uStack_80 = 0;
  if (((*(byte *)((long)puVar12 + 0x46) >> 5 & 1) != 0) ||
     (uVar15 = param_2, ((uint)*puVar12 >> 0x1a & 1) != 0)) {
    uVar15 = param_2 & (long)(param_2 << 8) >> 8;
  }
  if (uVar15 < 0x7ffffffff1) {
    do {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar15 = daif;
        if ((uVar15 & 0x80) == 0) {
          uVar18 = daif;
          daif = uVar18 | 0xc0;
        }
        uVar18 = ttbr1_el1;
        ttbr1_el1 = puVar12[1] & 0xffff000000000000 | uVar18 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar12[1];
        InstructionSynchronizationBarrier();
        daif = uVar15;
      }
      lVar8 = __arch_copy_from_user(&local_88,param_2 & 0xff7fffffffffffff,0x10);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar15 = daif;
        if ((uVar15 & 0x80) == 0) {
          uVar18 = daif;
          daif = uVar18 | 0xc0;
        }
        uVar18 = ttbr1_el1;
        ttbr0_el1 = (uVar18 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar18 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar15;
      }
      if (lVar8 != 0) break;
      uStack_80 = uStack_80 & 0xffffffffffffff;
      mutex_lock(param_1 + 0xc0);
      __string = param_1 + 0x58;
      sVar9 = strnlen(__string,0x10);
      if (sVar9 < 0x11) {
        if (sVar9 == 0) {
          _raw_spin_lock(&gh_sec_vm_lock);
          ppuVar21 = &gh_sec_vm_list;
          goto LAB_001088c0;
        }
        if (sVar9 != 0x10) goto code_r0x001089f4;
      }
      else {
        fortify_panic("strnlen");
      }
      fortify_panic("__fortify_strlen");
      param_2 = extraout_x1;
      puVar12 = extraout_x8;
    } while( true );
  }
  lVar8 = -0xe;
  goto LAB_00108df4;
code_r0x001089f4:
  _printk(&DAT_0010dac3,__string,0xffffffffffffffea);
  lVar8 = -0x11;
  goto LAB_00108dec;
  while (iVar6 = strcmp(ppuVar21[2],(char *)&local_88), iVar6 != 0) {
LAB_001088c0:
    ppuVar21 = (undefined **)*ppuVar21;
    if (ppuVar21 == &gh_sec_vm_list) {
      _raw_spin_unlock(&gh_sec_vm_lock);
      goto LAB_00108c80;
    }
  }
  _raw_spin_unlock(&gh_sec_vm_lock);
  if (ppuVar21 == (undefined **)0x0) {
LAB_00108c80:
    _printk(&DAT_0010f092,&local_88);
    lVar8 = -0x16;
  }
  else {
    pcVar11 = ppuVar21[2];
    puVar3 = ppuVar21[3];
    local_a0 = (undefined *)0x0;
    iVar6 = strcmp(pcVar11,"pvm");
    if (iVar6 == 0) {
      lVar8 = 0;
LAB_001089cc:
      uVar20 = (&fw_name_to_vm_name)[lVar8 * 4];
      if (*(char *)((long)ppuVar21 + 0x54) == '\0') goto LAB_00108950;
LAB_001089e4:
      puVar10 = (undefined *)0x0;
LAB_00108a1c:
      iVar6 = gh_rm_vm_alloc_vmid(uVar20,ppuVar21 + 10);
      if (iVar6 < 0) {
        _dev_err(puVar3,"Couldn\'t allocate VMID for %s %d\n",ppuVar21[2],iVar6);
        if (*(char *)((long)ppuVar21 + 0x54) == '\0') {
          dma_free_attrs(puVar3,ppuVar21[7],puVar10,local_a0,0);
        }
      }
      else {
        local_98 = (undefined *)0x0;
        local_90 = 0;
        param_1[0x80] = 5;
        local_78 = 0;
        uStack_70 = 0;
        *(short *)(param_1 + 0x10) = (short)*(undefined4 *)(ppuVar21 + 10);
        puVar10 = ppuVar21[3];
        scnprintf(&local_78,0x10,"%s.mdt",ppuVar21[2]);
        uVar7 = request_firmware(&local_90,&local_78,puVar10);
        if (uVar7 == 0) {
          __src = (void *)qcom_mdt_read_metadata(puVar10,local_90,&local_78,&local_98,0,0);
          if (__src < (void *)0xfffffffffffff001) {
            puVar13 = (undefined *)((ulong)(local_98 + 0xfff) & 0xfffffffffffff000);
            if (puVar13 < local_98) {
              pcVar11 = "Overflow detected while calculating metadata size\"%s\"\n";
LAB_00108d44:
              _dev_err(ppuVar21[3],pcVar11,ppuVar21[2]);
LAB_00108d4c:
              _dev_err(puVar10,"Failed to load metadata \"%s\": %d\n",&local_78,0);
              uVar15 = 0;
            }
            else {
              uVar15 = (ulong)*(ushort *)((long)__src + 0x2c);
              if (uVar15 == 0) {
                puVar22 = ppuVar21[7];
                if (puVar22 < puVar13) goto LAB_00108d04;
                puVar14 = (undefined *)0x0;
LAB_00108b48:
                puVar17 = ppuVar21[5];
              }
              else {
                uVar7 = 0;
                uVar18 = 0;
                puVar14 = (undefined *)0x0;
                lVar8 = (long)__src + 0x4c;
                uVar19 = 0;
                do {
                  pbVar1 = (byte *)(lVar8 + 3);
                  uVar4 = *(uint *)(lVar8 + -0xc);
                  puVar2 = (uint *)(lVar8 + -4);
                  lVar8 = lVar8 + 0x20;
                  uVar18 = uVar18 + *puVar2;
                  puVar22 = (undefined *)(ulong)(*puVar2 + uVar4);
                  if (uVar4 <= uVar19) {
                    uVar4 = uVar19;
                    puVar22 = puVar14;
                  }
                  puVar14 = puVar22;
                  uVar7 = uVar7 | (*pbVar1 & 8) >> 3;
                  uVar15 = uVar15 - 1;
                  uVar19 = uVar4;
                } while (uVar15 != 0);
                if ((CARRY8((ulong)puVar13,uVar18)) ||
                   (puVar22 = ppuVar21[7], puVar22 < puVar13 + uVar18)) {
LAB_00108d04:
                  pcVar11 = "Metadata cannot fit in mem_region  \"%s\"\n";
                  goto LAB_00108d44;
                }
                if (uVar7 == 0) goto LAB_00108b48;
                puVar17 = (undefined *)0x0;
              }
              uVar15 = (long)puVar22 - (long)puVar13;
              if (((puVar22 < puVar13) || ((undefined *)~uVar15 < puVar17)) ||
                 ((undefined *)~uVar15 < ppuVar21[6])) {
                pcVar11 = "Overflow detected while calculating metadata offset\"%s\"\n";
                goto LAB_00108d44;
              }
              if (puVar17 + uVar15 < puVar14) {
                pcVar11 = "Metadata cannot fit in mem_region %s\n";
                goto LAB_00108d44;
              }
              memcpy(ppuVar21[6] + uVar15,__src,(size_t)local_98);
              if (puVar22 == puVar13) goto LAB_00108d4c;
              uVar7 = qcom_mdt_load_no_init
                                (puVar10,local_90,&local_78,*(undefined4 *)((long)ppuVar21 + 0x4c),
                                 ppuVar21[6],ppuVar21[5],ppuVar21[7],0);
              if (uVar7 == 0) {
                uVar7 = gh_provide_mem(param_1,ppuVar21[5],ppuVar21[7],*(undefined1 *)(ppuVar21 + 4)
                                      );
                param_1[2] = *(undefined1 *)((long)ppuVar21 + 0x21);
                param_1[3] = *(undefined1 *)((long)ppuVar21 + 0x22);
                if (uVar7 != 0) {
                  puVar12 = (undefined8 *)ppuVar21[2];
                  uVar15 = (ulong)uVar7;
                  pcVar11 = "Failed to provide memory for %s, %d\n";
                  goto LAB_00108da4;
                }
                if (*(char *)(ppuVar21 + 9) != '\0') {
                  param_1[0xb8] = 1;
                  **(undefined4 **)(param_1 + 0xb0) = *(undefined4 *)(ppuVar21[8] + 0x10);
                  *(undefined8 *)(*(long *)(param_1 + 0xb0) + 8) = *(undefined8 *)ppuVar21[8];
                  *(undefined8 *)(*(long *)(param_1 + 0xb0) + 0x10) =
                       *(undefined8 *)(ppuVar21[8] + 8);
                  uVar7 = gh_provide_mem(param_1,*(undefined8 *)ppuVar21[8],
                                         *(undefined8 *)((long)ppuVar21[8] + 8),
                                         *(undefined1 *)(ppuVar21 + 4));
                  if (uVar7 != 0) {
                    puVar12 = (undefined8 *)ppuVar21[2];
                    uVar15 = (ulong)uVar7;
                    pcVar11 = "Failed to provide memory for ext-region to vm: %s, %d\n";
                    goto LAB_00108da4;
                  }
                }
                *param_1 = 1;
                uVar15 = gh_vm_configure(1,uVar15,local_98,0,0,
                                         *(undefined4 *)((long)ppuVar21 + 0x4c),ppuVar21[2],param_1)
                ;
                if ((int)uVar15 != 0) {
                  puVar12 = (undefined8 *)ppuVar21[2];
                  pcVar11 = "Configuring secure VM %s to memory failed %ld\n";
                  goto LAB_00108da4;
                }
              }
              else {
                uVar15 = (ulong)uVar7;
                pcVar11 = "Failed to load fw \"%s\": %d\n";
                puVar12 = &local_78;
LAB_00108da4:
                _dev_err(puVar10,pcVar11,puVar12,uVar15 & 0xffffffff);
              }
            }
            kfree(__src);
            release_firmware(local_90);
            iVar6 = (int)uVar15;
          }
          else {
            release_firmware(local_90);
            uVar15 = (ulong)__src & 0xffffffff;
            iVar6 = (int)__src;
          }
          if (iVar6 == 0) {
            scnprintf(__string,0x10,&DAT_0010e17b,&local_88);
            gh_uevent_notify_change(0,param_1);
            lVar8 = 0;
            goto LAB_00108dec;
          }
        }
        else {
          uVar15 = (ulong)uVar7;
          _dev_err(puVar10,"Error requesting fw \"%s\": %d\n",&local_78,uVar15);
        }
        iVar6 = (int)uVar15;
        _dev_err(puVar3,"Loading Secure VM %s failed %d\n",ppuVar21[2],uVar15 & 0xffffffff);
      }
    }
    else {
      iVar6 = strcmp(pcVar11,"trustedvm");
      if (iVar6 == 0) {
        lVar8 = 1;
        goto LAB_001089cc;
      }
      iVar6 = strcmp(pcVar11,"cpusys_vm");
      if (iVar6 == 0) {
        lVar8 = 2;
        goto LAB_001089cc;
      }
      iVar6 = strcmp(pcVar11,"oemvm");
      if (iVar6 == 0) {
        lVar8 = 3;
        goto LAB_001089cc;
      }
      uVar20 = 7;
      if (*(char *)((long)ppuVar21 + 0x54) != '\0') goto LAB_001089e4;
LAB_00108950:
      puVar10 = (undefined *)dma_alloc_attrs(puVar3,ppuVar21[7],&local_a0,0xcc0,0);
      if (puVar10 != (undefined *)0x0) {
        ppuVar21[6] = puVar10;
        lVar8 = *(long *)(puVar3 + 0x2b0);
        puVar13 = local_a0;
        if (lVar8 != 0) {
          uVar15 = *(ulong *)(lVar8 + 0x10);
          if (uVar15 != 0) {
            plVar16 = (long *)(lVar8 + 0x18);
            do {
              if ((undefined *)plVar16[-2] <= local_a0 &&
                  (ulong)((long)local_a0 - plVar16[-2]) < uVar15) {
                puVar13 = local_a0 + *plVar16;
                goto LAB_00108a18;
              }
              uVar15 = plVar16[3];
              plVar16 = plVar16 + 4;
            } while (uVar15 != 0);
          }
          puVar13 = (undefined *)0xffffffffffffffff;
        }
LAB_00108a18:
        ppuVar21[5] = puVar13;
        goto LAB_00108a1c;
      }
      iVar6 = -0xc;
      _dev_err(puVar3,"Couldn\'t allocate cma memory for %s %d\n",ppuVar21[2],0xfffffff4);
    }
    lVar8 = (long)iVar6;
    _dev_err(puVar3,"Loading secure VM %s to memory failed %ld\n",ppuVar21[2],lVar8);
  }
LAB_00108dec:
  mutex_unlock(param_1 + 0xc0);
LAB_00108df4:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar8;
}



//------------------------------------------------------------
// gh_vm_ioctl_get_fw_name @ 00108ec0 size=376
// signature: undefined gh_vm_ioctl_get_fw_name(void)
// callers: [gh_vm_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gh_vm_ioctl_get_fw_name(long param_1,ulong param_2)

{
  ulong uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  ulong uVar5;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  mutex_lock(param_1 + 0xc0);
  scnprintf(&local_48,0x10,&DAT_0010e17b,param_1 + 0x58);
  mutex_unlock(param_1 + 0xc0);
  puVar4 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
     (uVar5 = param_2, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
    uVar5 = param_2 & (long)(param_2 << 8) >> 8;
  }
  if (uVar5 < 0x7ffffffff1) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar5 = daif;
      if ((uVar5 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      puVar4 = (undefined8 *)puVar4[1];
      uVar1 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar4 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar4;
      InstructionSynchronizationBarrier();
      daif = uVar5;
    }
    lVar2 = __arch_copy_to_user(puVar4,param_2 & 0xff7fffffffffffff,&local_48,0x10);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar5 = daif;
      if ((uVar5 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      uVar1 = ttbr1_el1;
      ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar5;
    }
    uVar3 = 0;
    if (lVar2 != 0) {
      uVar3 = 0xfffffffffffffff2;
    }
  }
  else {
    uVar3 = 0xfffffffffffffff2;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// gh_secure_vm_loader_reclaim_fw @ 00109054 size=272
// signature: undefined gh_secure_vm_loader_reclaim_fw(void)
// callers: [gh_destroy_vm]
//------------------------------------------------------------

undefined8 gh_secure_vm_loader_reclaim_fw(long param_1)

{
  ulong *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  ulong uVar6;
  undefined *puVar7;
  undefined **ppuVar8;
  
  _raw_spin_lock(&gh_sec_vm_lock);
  ppuVar8 = &gh_sec_vm_list;
  do {
    ppuVar8 = (undefined **)*ppuVar8;
    if (ppuVar8 == &gh_sec_vm_list) {
      _raw_spin_unlock(&gh_sec_vm_lock);
      goto LAB_00109120;
    }
    iVar2 = strcmp(ppuVar8[2],(char *)(param_1 + 0x58));
  } while (iVar2 != 0);
  _raw_spin_unlock(&gh_sec_vm_lock);
  if (ppuVar8 == (undefined **)0x0) {
LAB_00109120:
    _printk(&DAT_0010f092,(char *)(param_1 + 0x58));
    uVar3 = 0xffffffea;
  }
  else {
    puVar7 = ppuVar8[3];
    uVar3 = gh_reclaim_mem(param_1,ppuVar8[5],ppuVar8[7],*(undefined1 *)(ppuVar8 + 4));
    if ((int)uVar3 == 0) {
      if (*(char *)((long)ppuVar8 + 0x54) == '\0') {
        puVar5 = *(undefined8 **)(puVar7 + 0x2b0);
        puVar4 = ppuVar8[5];
        if (puVar5 != (undefined8 *)0x0) {
          uVar6 = puVar5[2];
          while (uVar6 != 0) {
            if ((undefined *)*puVar5 <= puVar4 && (ulong)((long)puVar4 - (long)*puVar5) < uVar6) {
              puVar4 = puVar4 + -puVar5[3];
              goto LAB_00109140;
            }
            puVar1 = puVar5 + 6;
            puVar5 = puVar5 + 4;
            uVar6 = *puVar1;
          }
          puVar4 = (undefined *)0xffffffffffffffff;
        }
LAB_00109140:
        dma_free_attrs(puVar7,ppuVar8[7],ppuVar8[6],puVar4,0);
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// gh_secure_vm_loader_init @ 00109168 size=44
// signature: undefined gh_secure_vm_loader_init(void)
// callers: [init_module]
//------------------------------------------------------------

void gh_secure_vm_loader_init(void)

{
  __platform_driver_register(&gh_secure_vm_loader_drv,&__this_module);
  return;
}



//------------------------------------------------------------
// gh_secure_vm_loader_exit @ 00109198 size=36
// signature: undefined gh_secure_vm_loader_exit(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

void gh_secure_vm_loader_exit(void)

{
  platform_driver_unregister(&gh_secure_vm_loader_drv);
  return;
}



//------------------------------------------------------------
// gh_secure_vm_loader_probe @ 001091c0 size=1444
// signature: undefined gh_secure_vm_loader_probe(void)
// callers: []
//------------------------------------------------------------

int gh_secure_vm_loader_probe(long param_1)

{
  undefined8 *puVar1;
  undefined *puVar2;
  long lVar3;
  int iVar4;
  undefined8 *puVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  char *pcVar12;
  undefined **ppuVar13;
  long local_f8;
  long lStack_f0;
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
  undefined8 *local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar6 = sp_el0;
  lVar11 = param_1 + 0x10;
  local_48 = *(long *)(lVar6 + 0x638);
  puVar5 = (undefined8 *)devm_kmalloc(lVar11,0x58,0xdc0);
  if ((puVar5 == (undefined8 *)0x0) || (lVar6 = devm_kmalloc(lVar11,0x18,0xdc0), lVar6 == 0)) {
    iVar4 = -0xc;
    goto LAB_001096b4;
  }
  puVar5[8] = lVar6;
  uVar7 = *(undefined8 *)(param_1 + 0x2f8);
  puVar5[3] = lVar11;
  *(undefined8 **)(param_1 + 0xa8) = puVar5;
  iVar4 = of_property_read_variable_u32_array(uVar7,"qcom,pas-id",(long)puVar5 + 0x4c,1,0);
  if (iVar4 < 0) {
    pcVar12 = "DT error getting \"qcom,pas-id\": %d\n";
  }
  else {
    lVar6 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,no-shutdown",0);
    *(bool *)(puVar5 + 4) = lVar6 != 0;
    if (lVar6 != 0) {
      _dev_info(lVar11,"Vm with no shutdown attribute added\n");
    }
    lVar6 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,keep-running",0);
    *(bool *)((long)puVar5 + 0x21) = lVar6 != 0;
    if (lVar6 != 0) {
      _dev_info(lVar11,"VM with keep running attribute added\n");
    }
    lVar6 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,rebootable",0);
    *(bool *)((long)puVar5 + 0x22) = lVar6 != 0;
    if (lVar6 != 0) {
      _dev_info(lVar11,"VM with rebootable attribute added\n");
    }
    iVar4 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,vmid",puVar5 + 10,1,0);
    if (iVar4 < 0) {
      pcVar12 = "DT error getting \"qcom,vmid\": %d\n";
    }
    else {
      lVar6 = puVar5[3];
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
      lStack_f0 = 0;
      local_58 = 0;
      uStack_50 = 0;
      local_68 = 0;
      uStack_60 = 0;
      local_78 = 0;
      uStack_70 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_98 = (undefined8 *)0x0;
      uStack_90 = 0;
      iVar4 = __of_parse_phandle_with_args
                        (*(undefined8 *)(lVar6 + 0x2e8),"memory-region",0,0,0,&local_98);
      puVar1 = local_98;
      if ((iVar4 != 0) || (local_98 == (undefined8 *)0x0)) {
        _dev_err(lVar6,"DT error getting \"memory-region\"\n");
        iVar4 = -0x16;
        goto LAB_001096b4;
      }
      lVar8 = of_find_property(local_98,"no-map",0);
      if (lVar8 == 0) {
        *(undefined1 *)((long)puVar5 + 0x54) = 0;
        iVar4 = dma_set_mask(lVar6,0xffffffffffffffff);
        if (iVar4 != 0) {
          _printk(&DAT_0010df20,"gh_vm_loader_mem_probe");
          goto LAB_001096b4;
        }
        dma_set_coherent_mask(lVar6,0xffffffffffffffff);
        iVar4 = of_reserved_mem_device_init_by_idx(lVar6,*(undefined8 *)(lVar6 + 0x2e8),0);
        if (iVar4 != 0) {
          _printk(&DAT_0010e783,"gh_vm_loader_mem_probe",iVar4);
          goto LAB_001096b4;
        }
        lVar8 = of_reserved_mem_lookup(puVar1);
        if (lVar8 == 0) {
          _printk(&DAT_0010ee38,"gh_vm_loader_mem_probe",*puVar1);
          iVar4 = -0x16;
          goto LAB_001096b4;
        }
        lVar8 = *(long *)(lVar8 + 0x28);
LAB_001093d8:
        puVar5[7] = lVar8;
        local_58 = 0;
        uStack_50 = 0;
        local_68 = 0;
        uStack_60 = 0;
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        uStack_80 = 0;
        local_98 = (undefined8 *)0x0;
        uStack_90 = 0;
        iVar4 = __of_parse_phandle_with_args
                          (*(undefined8 *)(lVar6 + 0x2e8),"ext-region",0,0,0,&local_98);
        if ((iVar4 != 0) || (local_98 == (undefined8 *)0x0)) {
LAB_00109478:
          puVar1 = puVar5 + 2;
          iVar4 = of_property_read_string
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,firmware-name",puVar1);
          if (iVar4 == 0) {
            pcVar12 = (char *)*puVar1;
            iVar4 = strcmp(pcVar12,"pvm");
            if (iVar4 == 0) {
              lVar6 = 0;
LAB_00109580:
              if ((&fw_name_to_vm_name)[lVar6 * 4] == 7) goto LAB_001096e8;
              _raw_spin_lock(&gh_sec_vm_lock);
              ppuVar13 = &gh_sec_vm_list;
              do {
                ppuVar13 = (undefined **)*ppuVar13;
                if (ppuVar13 == &gh_sec_vm_list) {
                  _raw_spin_unlock(&gh_sec_vm_lock);
                  goto LAB_00109600;
                }
                iVar4 = strcmp(ppuVar13[2],pcVar12);
              } while (iVar4 != 0);
              _raw_spin_unlock(&gh_sec_vm_lock);
              if (ppuVar13 == (undefined **)0x0) {
LAB_00109600:
                iVar4 = gh_parse_virtio_properties(lVar11,*puVar1);
                if (iVar4 == 0) {
                  _raw_spin_lock(&gh_sec_vm_lock);
                  puVar2 = gh_sec_vm_list;
                  uVar10 = __list_add_valid(puVar5,&gh_sec_vm_list,gh_sec_vm_list);
                  if ((uVar10 & 1) != 0) {
                    *(undefined8 **)(puVar2 + 8) = puVar5;
                    *puVar5 = puVar2;
                    puVar5[1] = &gh_sec_vm_list;
                    gh_sec_vm_list = (undefined *)puVar5;
                  }
                  _raw_spin_unlock(&gh_sec_vm_lock);
                  iVar4 = 0;
                  goto LAB_001096b4;
                }
                goto LAB_00109614;
              }
              _dev_err(lVar11,"Requested Secure VM %s already present\n",*puVar1);
            }
            else {
              iVar4 = strcmp(pcVar12,"trustedvm");
              if (iVar4 == 0) {
                lVar6 = 1;
                goto LAB_00109580;
              }
              iVar4 = strcmp(pcVar12,"cpusys_vm");
              if (iVar4 == 0) {
                lVar6 = 2;
                goto LAB_00109580;
              }
              iVar4 = strcmp(pcVar12,"oemvm");
              if (iVar4 == 0) {
                lVar6 = 3;
                goto LAB_00109580;
              }
LAB_001096e8:
              _dev_err(lVar11,"Requested Secure VM %d not supported\n",7);
            }
            iVar4 = -0x16;
          }
LAB_00109614:
          memunmap(puVar5[6]);
          goto LAB_001096b4;
        }
        *(undefined1 *)(puVar5 + 9) = 1;
        iVar4 = of_address_to_resource(local_98,0,&local_f8);
        if (iVar4 == 0) {
          *(long *)puVar5[8] = local_f8;
          *(long *)(puVar5[8] + 8) = (lStack_f0 - local_f8) + 1;
          iVar4 = of_property_read_variable_u32_array
                            (*(undefined8 *)(lVar6 + 0x2e8),"ext-label",puVar5[8] + 0x10,1,0);
          if (-1 < iVar4) goto LAB_00109478;
          pcVar12 = "DT error getting \"ext-label\": %d\n";
        }
        else {
          pcVar12 = "error %d getting \"ext-region\" resource\n";
        }
      }
      else {
        *(undefined1 *)((long)puVar5 + 0x54) = 1;
        iVar4 = of_address_to_resource(puVar1,0,&local_f8);
        lVar3 = local_f8;
        if (iVar4 == 0) {
          lVar8 = (lStack_f0 - local_f8) + 1;
          lVar9 = memremap(local_f8,lVar8,4);
          if (lVar9 == 0) {
            _dev_err(lVar6,"Unable to remap firmware memory\n");
            iVar4 = -0xc;
            goto LAB_001096b4;
          }
          puVar5[5] = lVar3;
          puVar5[6] = lVar9;
          goto LAB_001093d8;
        }
        pcVar12 = "error %d getting \"memory-region\" resource\n";
      }
      lVar11 = lVar6;
    }
  }
  _dev_err(lVar11,pcVar12,iVar4);
LAB_001096b4:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// gh_secure_vm_loader_remove @ 00109768 size=144
// signature: undefined gh_secure_vm_loader_remove(void)
// callers: []
//------------------------------------------------------------

void gh_secure_vm_loader_remove(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  long *plVar4;
  
  plVar4 = *(long **)(param_1 + 0xa8);
  _raw_spin_lock(&gh_sec_vm_lock);
  uVar3 = __list_del_entry_valid(plVar4);
  if ((uVar3 & 1) != 0) {
    lVar1 = *plVar4;
    plVar2 = (long *)plVar4[1];
    *(long **)(lVar1 + 8) = plVar2;
    *plVar2 = lVar1;
  }
  *plVar4 = -0x2152ffffffffff00;
  plVar4[1] = -0x2152fffffffffede;
  _raw_spin_unlock(&gh_sec_vm_lock);
  if (*(char *)((long)plVar4 + 0x54) == '\0') {
    of_reserved_mem_device_release(param_1 + 0x10);
  }
  else {
    memunmap(plVar4[6]);
  }
  gh_virtio_backend_remove(plVar4[2]);
  return;
}



//------------------------------------------------------------
// __traceiter_gh_hcall_vcpu_run @ 0010984c size=164
// signature: undefined __traceiter_gh_hcall_vcpu_run(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_gh_hcall_vcpu_run
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00110258;
  plVar2 = DAT_00110258;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x1c4f1556) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1098c4);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_gh_susp_res_irq_handler @ 001098f4 size=100
// signature: undefined __traceiter_gh_susp_res_irq_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_gh_susp_res_irq_handler(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001102a0;
  plVar2 = _DAT_001102a0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x4d7d0c96) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x109938);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_gh_vcpu_irq_handler @ 0010995c size=116
// signature: undefined __traceiter_gh_vcpu_irq_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_gh_vcpu_irq_handler(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001102e8;
  plVar2 = _DAT_001102e8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x22ea310d) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1099ac);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_gh_hcall_vcpu_run @ 001099d4 size=224
// signature: undefined trace_event_raw_event_gh_hcall_vcpu_run(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_gh_hcall_vcpu_run
               (long param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_78;
  undefined8 uStack_70;
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
  local_78 = 0;
  uStack_70 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_78,param_1,0x30), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined2 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    *(undefined8 *)(lVar1 + 0x18) = param_5;
    *(undefined8 *)(lVar1 + 0x20) = param_6;
    *(undefined8 *)(lVar1 + 0x28) = param_7;
    trace_event_buffer_commit(&local_78);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_gh_hcall_vcpu_run @ 00109ab8 size=296
// signature: undefined perf_trace_gh_hcall_vcpu_run(void)
// callers: []
//------------------------------------------------------------

void perf_trace_gh_hcall_vcpu_run
               (long param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_70 = 0;
  local_74 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x34,&local_70,&local_74), lVar3 != 0)) {
    *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_70 + 0xf8) = auStack_80;
    *(ulong *)(local_70 + 0x100) = uVar2;
    *(undefined8 *)(local_70 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined2 *)(lVar3 + 0xc) = param_3;
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    *(undefined8 *)(lVar3 + 0x18) = param_5;
    *(undefined8 *)(lVar3 + 0x20) = param_6;
    *(undefined8 *)(lVar3 + 0x28) = param_7;
    perf_trace_run_bpf_submit(lVar3,0x34,local_74,param_1,1,local_70,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_gh_susp_res_irq_handler @ 00109be4 size=168
// signature: undefined trace_event_raw_event_gh_susp_res_irq_handler(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_gh_susp_res_irq_handler(long param_1,undefined8 param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x10), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_gh_susp_res_irq_handler @ 00109c90 size=236
// signature: undefined perf_trace_gh_susp_res_irq_handler(void)
// callers: []
//------------------------------------------------------------

void perf_trace_gh_susp_res_irq_handler(long param_1,undefined8 param_2)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_50 [12];
  undefined4 local_44;
  long local_40;
  undefined8 local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  local_44 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x14,&local_40,&local_44), lVar3 != 0)) {
    *(undefined1 **)(local_40 + 0xe8) = auStack_50 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_40 + 0xf8) = auStack_50;
    *(ulong *)(local_40 + 0x100) = uVar2;
    *(undefined8 *)(local_40 + 0x108) = 5;
    *(undefined8 *)(lVar3 + 8) = param_2;
    perf_trace_run_bpf_submit(lVar3,0x14,local_44,param_1,1,local_40,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_gh_vcpu_irq_handler @ 00109d80 size=176
// signature: undefined trace_event_raw_event_gh_vcpu_irq_handler(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_gh_vcpu_irq_handler(long param_1,undefined2 param_2,undefined4 param_3)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x10), lVar1 != 0)) {
    *(undefined2 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_gh_vcpu_irq_handler @ 00109e34 size=252
// signature: undefined perf_trace_gh_vcpu_irq_handler(void)
// callers: []
//------------------------------------------------------------

void perf_trace_gh_vcpu_irq_handler(long param_1,undefined2 param_2,undefined4 param_3)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x14,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined2 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    perf_trace_run_bpf_submit(lVar3,0x14,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_gh_hcall_vcpu_run @ 00109f34 size=40
// signature: undefined __bpf_trace_gh_hcall_vcpu_run(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_gh_hcall_vcpu_run
               (undefined8 param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4)

{
  bpf_trace_run6(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_gh_susp_res_irq_handler @ 00109f60 size=28
// signature: undefined __bpf_trace_gh_susp_res_irq_handler(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_gh_susp_res_irq_handler(void)

{
  bpf_trace_run1();
  return;
}



//------------------------------------------------------------
// __bpf_trace_gh_vcpu_irq_handler @ 00109f80 size=36
// signature: undefined __bpf_trace_gh_vcpu_irq_handler(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_gh_vcpu_irq_handler(undefined8 param_1,undefined2 param_2,undefined4 param_3)

{
  bpf_trace_run2(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// gh_get_nr_vcpus @ 00109fa8 size=152
// signature: undefined gh_get_nr_vcpus(void)
// callers: [gh_vm_configure]
//------------------------------------------------------------

undefined4 gh_get_nr_vcpus(short param_1)

{
  short *psVar1;
  
  if (*gh_vms == param_1 || *gh_vms == -1) {
    psVar1 = gh_vms;
  }
  else if (gh_vms[0x378] == param_1 || gh_vms[0x378] == -1) {
    psVar1 = gh_vms + 0x378;
  }
  else {
    psVar1 = gh_vms + 0x6f0;
    if ((gh_vms[0x6f0] != param_1) && (gh_vms[0x6f0] != -1)) {
      psVar1 = gh_vms + 0xa68;
      if (gh_vms[0xa68] != -1 && gh_vms[0xa68] != param_1) {
        psVar1 = gh_vms + 0xde0;
      }
    }
  }
  if ((psVar1 == (short *)0x0) || ((char)psVar1[0x364] == '\0')) {
    return 0;
  }
  return *(undefined4 *)(psVar1 + 2);
}



//------------------------------------------------------------
// gh_wakeup_all_vcpus @ 0010a044 size=516
// signature: undefined gh_wakeup_all_vcpus(void)
// callers: [gh_vm_rm_notifier_fn]
//------------------------------------------------------------

void gh_wakeup_all_vcpus(short param_1)

{
  code *pcVar1;
  short *psVar2;
  
  if (*gh_vms == param_1 || *gh_vms == -1) {
    psVar2 = gh_vms;
  }
  else if (gh_vms[0x378] == param_1 || gh_vms[0x378] == -1) {
    psVar2 = gh_vms + 0x378;
  }
  else {
    psVar2 = gh_vms + 0x6f0;
    if ((gh_vms[0x6f0] != param_1) && (gh_vms[0x6f0] != -1)) {
      psVar2 = gh_vms + 0xa68;
      if (gh_vms[0xa68] != -1 && gh_vms[0xa68] != param_1) {
        psVar2 = gh_vms + 0xde0;
      }
    }
  }
  if (((psVar2 != (short *)0x0) && (*(char *)((long)psVar2 + 0x6c9) != '\0')) &&
     (*(undefined1 *)((long)psVar2 + 0x6c9) = 0, 0 < *(int *)(psVar2 + 2))) {
    *(undefined1 *)(psVar2 + 0xe) = 1;
    __wake_up(psVar2 + 0x38,3,1,0);
    if (1 < *(int *)(psVar2 + 2)) {
      *(undefined1 *)(psVar2 + 0x7a) = 1;
      __wake_up(psVar2 + 0xa4,3,1,0);
      if (2 < *(int *)(psVar2 + 2)) {
        *(undefined1 *)(psVar2 + 0xe6) = 1;
        __wake_up(psVar2 + 0x110,3,1,0);
        if (3 < *(int *)(psVar2 + 2)) {
          *(undefined1 *)(psVar2 + 0x152) = 1;
          __wake_up(psVar2 + 0x17c,3,1,0);
          if (4 < *(int *)(psVar2 + 2)) {
            *(undefined1 *)(psVar2 + 0x1be) = 1;
            __wake_up(psVar2 + 0x1e8,3,1,0);
            if (5 < *(int *)(psVar2 + 2)) {
              *(undefined1 *)(psVar2 + 0x22a) = 1;
              __wake_up(psVar2 + 0x254,3,1,0);
              if (6 < *(int *)(psVar2 + 2)) {
                *(undefined1 *)(psVar2 + 0x296) = 1;
                __wake_up(psVar2 + 0x2c0,3,1,0);
                if (7 < *(int *)(psVar2 + 2)) {
                  *(undefined1 *)(psVar2 + 0x302) = 1;
                  __wake_up(psVar2 + 0x32c,3,1,0);
                  if (8 < *(int *)(psVar2 + 2)) {
                    *(undefined1 *)(psVar2 + 0x36e) = 1;
                    __wake_up(psVar2 + 0x398,3,1,0);
                    if (9 < *(int *)(psVar2 + 2)) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10a248);
                      (*pcVar1)();
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}



//------------------------------------------------------------
// gh_vm_supports_proxy_sched @ 0010a24c size=160
// signature: undefined gh_vm_supports_proxy_sched(void)
// callers: [gh_vcpu_ioctl]
//------------------------------------------------------------

undefined8 gh_vm_supports_proxy_sched(short param_1)

{
  short *psVar1;
  
  if (*gh_vms == param_1 || *gh_vms == -1) {
    psVar1 = gh_vms;
  }
  else if (gh_vms[0x378] == param_1 || gh_vms[0x378] == -1) {
    psVar1 = gh_vms + 0x378;
  }
  else {
    psVar1 = gh_vms + 0x6f0;
    if ((gh_vms[0x6f0] != param_1) && (gh_vms[0x6f0] != -1)) {
      psVar1 = gh_vms + 0xa68;
      if (gh_vms[0xa68] != -1 && gh_vms[0xa68] != param_1) {
        psVar1 = gh_vms + 0xde0;
      }
    }
  }
  if (((psVar1 == (short *)0x0) || ((char)psVar1[0x364] == '\0')) || (*(int *)(psVar1 + 2) == 0)) {
    return 0;
  }
  return 1;
}



//------------------------------------------------------------
// gh_poll_vcpu_run @ 0010a2f0 size=632
// signature: undefined gh_poll_vcpu_run(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x0010a4f4) */

uint gh_poll_vcpu_run(short param_1)

{
  short sVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  short *psVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  short *psVar12;
  
  lVar6 = sp_el0;
  lVar6 = *(long *)(lVar6 + 0x638);
  sVar1 = *gh_vms;
  psVar12 = gh_vms;
  if (sVar1 != param_1 && sVar1 != -1) {
    psVar12 = gh_vms + 0x378;
    if ((gh_vms[0x378] != param_1) && (gh_vms[0x378] != -1)) {
      psVar12 = gh_vms + 0x6f0;
      if ((gh_vms[0x6f0] != param_1) &&
         ((gh_vms[0x6f0] != -1 &&
          (psVar12 = gh_vms + 0xa68, gh_vms[0xa68] != -1 && gh_vms[0xa68] != param_1)))) {
        psVar12 = gh_vms + 0xde0;
      }
    }
  }
  if ((psVar12 != (short *)0x0) && (*(char *)((long)psVar12 + 0x6c9) != '\0')) {
    if (sVar1 != param_1 && sVar1 != -1) {
      psVar8 = gh_vms + 0x378;
      if ((gh_vms[0x378] != param_1) && (gh_vms[0x378] != -1)) {
        psVar8 = gh_vms + 0x6f0;
        if ((gh_vms[0x6f0] != param_1) &&
           ((gh_vms[0x6f0] != -1 &&
            (psVar8 = gh_vms + 0xa68, gh_vms[0xa68] != -1 && gh_vms[0xa68] != param_1)))) {
          psVar8 = gh_vms + 0xde0;
        }
      }
    }
    else {
      psVar8 = gh_vms;
    }
    if ((psVar8 != (short *)0x0) && ((char)psVar8[0x364] != '\0')) {
      uVar9 = *(uint *)(psVar8 + 2);
      if ((int)uVar9 < 0) {
        _printk_deferred("Failed to get vcpu count for VM %d ret %d\n",param_1,nr_vcpus);
        goto LAB_0010a514;
      }
      if (uVar9 != 0) {
        uVar10 = 0;
        uVar2 = sp_el0;
        do {
          if (uVar10 == 8) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10a620);
            (*pcVar3)();
          }
          lVar7 = *(long *)(psVar12 + (ulong)uVar10 * 0x6c + 8);
          if (lVar7 == -1) goto LAB_0010a510;
          do {
            lVar4 = ktime_get(lVar7);
            lVar5 = *(long *)(psVar12 + (ulong)uVar10 * 0x6c + 8);
            CallHyperVisor(0x6065);
            lVar7 = ktime_get(lVar5,0,0,0,0,0,0,0);
            lVar7 = lVar7 - lVar4;
            uVar11 = (uint)lVar5;
          } while (uVar11 == 0xfffffffe);
          uVar10 = uVar10 + 1;
        } while (uVar10 != uVar9);
        uVar9 = uVar11;
        goto LAB_0010a514;
      }
    }
  }
LAB_0010a510:
  uVar9 = 0xffffffff;
LAB_0010a514:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != lVar6) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}



//------------------------------------------------------------
// gh_vcpu_work_function @ 0010a628 size=444
// signature: undefined gh_vcpu_work_function(void)
// callers: []
//------------------------------------------------------------

void gh_vcpu_work_function(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  
  lVar1 = sp_el0;
  lVar3 = *(long *)(lVar1 + 0x638);
  lVar5 = *(long *)(param_1 + -0x90);
  *(undefined1 *)(param_1 + -0x7c) = 0;
  __pm_stay_awake(*(undefined8 *)(param_1 + -0x10));
  ktime_get();
  lVar1 = sp_el0;
  *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 1;
  if (*(char *)(param_1 + -0x7b) != '\0') {
    CallHyperVisor(0x6063);
    *(undefined1 *)(param_1 + -0x7b) = 0;
  }
  uVar2 = *(undefined8 *)(param_1 + -0x88);
  CallHyperVisor(0x6065);
  iVar4 = (int)uVar2;
  if (iVar4 == 0) {
    uVar2 = *(undefined8 *)(lVar5 + 0x6d0);
    CallHyperVisor(0x6063);
    *(undefined1 *)(param_1 + -0x7b) = 1;
  }
  lVar5 = *(long *)(lVar1 + 0x10) + -1;
  *(int *)(lVar1 + 0x10) = (int)lVar5;
  if ((lVar5 == 0) || (*(long *)(lVar1 + 0x10) == 0)) {
    preempt_schedule(uVar2,0,0,0,0,0,0,0);
  }
  ktime_get();
  if (iVar4 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0010a7d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((long)DAT_0010feb0 + 0x10a7c8))();
    return;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != lVar3) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gh_vcpu_pm_notifier_call @ 0010a8b4 size=196
// signature: undefined gh_vcpu_pm_notifier_call(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_vcpu_pm_notifier_call(long param_1,long param_2)

{
  long lVar1;
  undefined1 auVar2 [16];
  long lVar3;
  undefined1 auVar4 [16];
  
  auVar2._8_8_ = param_2;
  auVar2._0_8_ = param_1;
  auVar4._8_8_ = param_2;
  auVar4._0_8_ = param_1;
  lVar3 = sp_el0;
  lVar3 = *(long *)(lVar3 + 0x638);
  if (param_2 == 4) {
    auVar4 = queue_work_on(0x20,*(undefined8 *)(*(long *)(param_1 + -0xc0) + 0x6e8),param_1 + -0x30)
    ;
  }
  else if ((param_2 == 3) && (auVar4 = auVar2, *(char *)(param_1 + -0xab) == '\0')) {
    auVar4._8_8_ = 0;
    auVar4._0_8_ = *(ulong *)(*(long *)(param_1 + -0xc0) + 0x6d0);
    CallHyperVisor(0x6063);
    *(undefined1 *)(param_1 + -0xab) = 1;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != lVar3) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(auVar4._0_8_,auVar4._8_8_);
  }
  return 1;
}



//------------------------------------------------------------
// gh_vcpu_create_wq @ 0010a97c size=316
// signature: undefined gh_vcpu_create_wq(void)
// callers: [gh_vcpu_release]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 gh_vcpu_create_wq(short param_1,uint param_2)

{
  code *pcVar1;
  short *psVar2;
  short *psVar3;
  
  if (*gh_vms == param_1 || *gh_vms == -1) {
    psVar3 = gh_vms;
  }
  else if (gh_vms[0x378] == param_1 || gh_vms[0x378] == -1) {
    psVar3 = gh_vms + 0x378;
  }
  else {
    psVar3 = gh_vms + 0x6f0;
    if ((gh_vms[0x6f0] != param_1) && (gh_vms[0x6f0] != -1)) {
      psVar3 = gh_vms + 0xa68;
      if (gh_vms[0xa68] != -1 && gh_vms[0xa68] != param_1) {
        psVar3 = gh_vms + 0xde0;
      }
    }
  }
  if ((psVar3 != (short *)0x0) && (*(char *)((long)psVar3 + 0x6c9) != '\0')) {
    if (7 < param_2) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10aab8);
      (*pcVar1)();
    }
    if (*(long *)(psVar3 + (ulong)param_2 * 0x6c + 8) != -1) {
      *(code **)(psVar3 + (ulong)param_2 * 0x6c + 100) = gh_vcpu_pm_notifier_call;
      psVar2 = psVar3 + (ulong)param_2 * 0x6c + 0x4c;
      psVar2[0] = -0x20;
      psVar2[1] = -1;
      psVar2[2] = 0xf;
      psVar2[3] = 0;
      *(short **)(psVar3 + (ulong)param_2 * 0x6c + 0x50) = psVar3 + (ulong)param_2 * 0x6c + 0x50;
      *(short **)(psVar3 + (ulong)param_2 * 0x6c + 0x54) = psVar3 + (ulong)param_2 * 0x6c + 0x50;
      *(undefined1 *)(psVar3 + (ulong)param_2 * 0x6c + 0x48) = 1;
      *(code **)(psVar3 + (ulong)param_2 * 0x6c + 0x58) = gh_vcpu_work_function;
      register_pm_notifier();
      queue_work_on(0x20,_system_wq,psVar2);
      queue_work_on(0x20,*(undefined8 *)(psVar3 + 0x374),psVar2);
      return 0;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// gh_vcpu_run @ 0010aabc size=1264
// signature: undefined gh_vcpu_run(void)
// callers: [gh_vcpu_ioctl]
//------------------------------------------------------------

void gh_vcpu_run(short param_1,ulong param_2,long param_3,undefined8 param_4,undefined8 param_5,
                int *param_6)

{
  short *psVar1;
  char *pcVar2;
  short *psVar3;
  short *psVar4;
  ulong uVar5;
  ulong *puVar6;
  code *pcVar7;
  int iVar8;
  undefined4 uVar9;
  long lVar10;
  uint uVar11;
  long lVar12;
  ulong extraout_x1;
  ulong extraout_x1_00;
  ulong extraout_x1_01;
  ulong extraout_x1_02;
  ulong extraout_x1_03;
  undefined8 uVar13;
  undefined8 uVar14;
  ulong uVar15;
  short *psVar16;
  int iVar17;
  undefined1 auVar18 [16];
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  if (*gh_vms == param_1 || *gh_vms == -1) {
    psVar16 = gh_vms;
  }
  else {
    psVar16 = gh_vms + 0x378;
    if ((gh_vms[0x378] != param_1) && (gh_vms[0x378] != -1)) {
      psVar16 = gh_vms + 0x6f0;
      if ((gh_vms[0x6f0] != param_1) && (gh_vms[0x6f0] != -1)) {
        psVar16 = gh_vms + 0xa68;
        if (gh_vms[0xa68] != -1 && gh_vms[0xa68] != param_1) {
          psVar16 = gh_vms + 0xde0;
        }
      }
    }
  }
  if ((psVar16 != (short *)0x0) && (*(char *)((long)psVar16 + 0x6c9) != '\0')) {
    uVar11 = (uint)param_2;
    if (7 < uVar11) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x10b064);
      (*pcVar7)();
    }
    uVar5 = param_2 & 0xffffffff;
    if (*(long *)(psVar16 + uVar5 * 0x6c + 8) != -1) {
      param_2 = param_2 & 0xffffffff;
      puVar6 = (ulong *)sp_el0;
      psVar1 = psVar16 + param_2 * 0x6c + 0xe;
      pcVar2 = (char *)((long)psVar16 + param_2 * 0xd8 + 0x1d);
      psVar3 = psVar16 + param_2 * 0x6c + 0x44;
      psVar4 = psVar16 + param_2 * 0x6c + 0x38;
LAB_0010ab80:
      *(char *)psVar1 = '\0';
      __pm_stay_awake(*(undefined8 *)psVar3);
      ktime_get();
      *(int *)(puVar6 + 2) = (int)puVar6[2] + 1;
      if (*pcVar2 != '\0') {
        CallHyperVisor(0x6063);
        *pcVar2 = '\0';
      }
      lVar10 = *(long *)(psVar16 + uVar5 * 0x6c + 8);
      CallHyperVisor(0x6065);
      *(long *)(param_6 + 2) = param_3;
      *(undefined8 *)(param_6 + 4) = param_4;
      *(undefined8 *)(param_6 + 6) = param_5;
      param_6[8] = 0;
      param_6[9] = 0;
      iVar17 = (int)lVar10;
      *param_6 = iVar17;
      param_6[10] = 0;
      param_6[0xb] = 0;
      lVar12 = param_3;
      uVar13 = param_4;
      uVar14 = param_5;
      if (((iVar17 == 0) && (param_3 == 0)) && (((uint)*puVar6 >> 1 & 1) != 0)) {
        lVar10 = *(long *)(psVar16 + 0x368);
        lVar12 = 0;
        uVar13 = 0;
        uVar14 = 0;
        CallHyperVisor(0x6063);
        *pcVar2 = '\x01';
      }
      local_90 = 0;
      uVar15 = puVar6[2];
      *(int *)(puVar6 + 2) = (int)(uVar15 - 1);
      if ((uVar15 - 1 == 0) || (puVar6[2] == 0)) {
        preempt_schedule(lVar10,lVar12,uVar13,uVar14,0,0,0,0);
      }
      ktime_get();
      param_2 = extraout_x1;
      if (iVar17 != 0) {
        if (iVar17 != -2) goto LAB_0010acc4;
        goto switchD_0010ad28_caseD_3;
      }
      switch(*(undefined8 *)(param_6 + 2)) {
      case 0:
        if (((uint)*puVar6 >> 1 & 1) != 0) goto switchD_0010ad28_caseD_3;
        break;
      case 1:
        if (*(long *)(param_6 + 4) != 0) {
          __pm_relax(*(undefined8 *)psVar3);
          param_2 = extraout_x1_01;
        }
        if ((((char)*psVar1 == '\0') && (((uint)*puVar6 >> 6 & 1) == 0)) && ((*puVar6 & 1) == 0)) {
          local_78 = 0;
          uStack_70 = 0;
          local_88 = 0;
          uStack_80 = 0;
          local_90 = 0;
          init_wait_entry(&local_90,0);
          while( true ) {
            auVar18 = prepare_to_wait_event(psVar4,&local_90,1);
            param_2 = auVar18._8_8_;
            if ((char)*psVar1 != '\0') break;
            if (auVar18._0_8_ != 0) goto LAB_0010acc4;
            schedule();
          }
LAB_0010ae54:
          finish_wait(psVar4,&local_90);
          param_2 = extraout_x1_03;
        }
        break;
      case 2:
        __pm_relax(*(undefined8 *)psVar3);
        param_2 = extraout_x1_02;
        if ((((char)*psVar1 == '\0') && (((uint)*puVar6 >> 6 & 1) == 0)) && ((*puVar6 & 1) == 0)) {
          local_78 = 0;
          uStack_70 = 0;
          local_88 = 0;
          uStack_80 = 0;
          local_90 = 0;
          init_wait_entry(&local_90,0);
          while( true ) {
            auVar18 = prepare_to_wait_event(psVar4,&local_90,1);
            param_2 = auVar18._8_8_;
            if ((char)*psVar1 != '\0') break;
            if (auVar18._0_8_ != 0) goto LAB_0010acc4;
            schedule();
          }
          goto LAB_0010ae54;
        }
        break;
      default:
        iVar8 = ___ratelimit(gh_vcpu_run__rs,"gh_vcpu_run");
        if (iVar8 != 0) {
          _printk(&DAT_0010eb54,*(undefined8 *)(param_6 + 2),uVar11,
                  **(undefined2 **)(psVar16 + uVar5 * 0x6c + 4),*(undefined8 *)(param_6 + 6),
                  *(undefined8 *)(param_6 + 8),*(undefined8 *)(param_6 + 10));
        }
      case 3:
switchD_0010ad28_caseD_3:
        schedule();
        param_2 = extraout_x1_00;
      }
LAB_0010acc4:
      if ((((uint)*puVar6 >> 6 & 1) == 0) && ((*puVar6 & 1) == 0)) {
        uVar9 = 0xffffffea;
        switch(iVar17) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 0xb:
        case 0xc:
        case 0xd:
        case 0xe:
        case 0xf:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1a:
        case 0x1b:
        case 0x1c:
        case 0x1d:
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x24:
        case 0x25:
        case 0x26:
        case 0x27:
        case 0x2a:
        case 0x2b:
        case 0x2c:
        case 0x2d:
        case 0x2e:
        case 0x2f:
        case 0x30:
        case 0x31:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3a:
        case 0x3b:
          goto switchD_0010acf8_caseD_1;
        case 10:
          uVar9 = 0xfffffff4;
          goto switchD_0010acf8_caseD_1;
        case 0x1e:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
          uVar9 = 0xfffffff3;
          goto switchD_0010acf8_caseD_1;
        case 0x1f:
        case 0x20:
          uVar9 = 0xfffffff0;
          goto switchD_0010acf8_caseD_1;
        case 0x28:
        case 0x29:
        case 0x3c:
        case 0x3d:
          uVar9 = 0xfffffffb;
          goto switchD_0010acf8_caseD_1;
        case -2:
        case 0:
          goto switchD_0010acf8_caseD_fffffffe;
        case -1:
          uVar9 = 0xffffffa1;
          goto switchD_0010acf8_caseD_1;
        default:
          if (iVar17 == -0x200) goto LAB_0010b044;
          goto switchD_0010acf8_caseD_1;
        }
      }
      if (*pcVar2 == '\0') {
        param_2 = 0;
        CallHyperVisor(0x6063);
        local_90 = 0;
        uVar9 = 0xfffffe00;
        *pcVar2 = '\x01';
      }
      else {
LAB_0010b044:
        uVar9 = 0xfffffe00;
      }
      goto switchD_0010acf8_caseD_1;
    }
  }
  uVar9 = 0xffffffff;
switchD_0010acf8_caseD_1:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9,param_2);
  }
  return;
switchD_0010acf8_caseD_fffffffe:
  if (*(char *)((long)psVar16 + 0x6c9) == '\0') goto LAB_0010b020;
  goto LAB_0010ab80;
LAB_0010b020:
  if (iVar17 + 2U < 3) {
    uVar9 = *(undefined4 *)(&DAT_00110948 + (long)(int)(iVar17 + 2U) * 4);
  }
  goto switchD_0010acf8_caseD_1;
}



//------------------------------------------------------------
// gh_proxy_sched_init @ 0010b068 size=552
// signature: undefined gh_proxy_sched_init(void)
// callers: [init_module]
//------------------------------------------------------------

int gh_proxy_sched_init(void)

{
  long lVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  undefined *puVar6;
  undefined2 *puVar7;
  long lVar8;
  long lVar9;
  uint *puVar10;
  long lVar11;
  
  gh_vms = kmalloc_large(0x22b0,0xdc0);
  if (gh_vms == 0) {
    iVar5 = -0xc;
  }
  else {
    iVar5 = gh_rm_set_wdog_manage_cb(gh_wdog_manage);
    if (iVar5 == 0) {
      iVar5 = gh_rm_set_vcpu_affinity_cb(gh_populate_vm_vcpu_info);
      if (iVar5 == 0) {
        iVar5 = gh_rm_reset_vcpu_affinity_cb(gh_unpopulate_vm_vcpu_info);
        if (iVar5 == 0) {
          iVar5 = gh_rm_set_vpm_grp_cb(gh_populate_vm_vpm_grp_info);
          if (iVar5 == 0) {
            iVar5 = gh_rm_reset_vpm_grp_cb(gh_unpopulate_vm_vpm_grp_info);
            if (iVar5 == 0) {
              iVar5 = gh_rm_all_res_populated_cb(gh_populate_all_res_info);
              if (iVar5 == 0) {
                lVar8 = 0;
                lVar9 = 0;
                do {
                  lVar3 = gh_vms;
                  lVar11 = 0;
                  puVar7 = (undefined2 *)(gh_vms + lVar9 * 0x6f0);
                  lVar1 = gh_vms + lVar8;
                  *puVar7 = 0xffff;
                  puVar7[0x364] = 0;
                  *(undefined4 *)(puVar7 + 0x370) = 0xffffffff;
                  *(undefined1 *)(puVar7 + 0x372) = 0;
                  *(undefined8 *)(puVar7 + 0x36c) = 0xffffffffffffffff;
                  puVar10 = (uint *)(puVar7 + 2);
                  *puVar10 = 0;
                  do {
                    lVar2 = lVar1 + lVar11;
                    *(undefined4 *)(lVar2 + 0x28) = 0xffffffff;
                    *(undefined4 *)(lVar2 + 0x18) = 0xffffffff;
                    *(undefined8 *)(lVar2 + 8) = 0;
                    *(undefined8 *)(lVar2 + 0x10) = 0xffffffffffffffff;
                    *(undefined2 *)(lVar2 + 0x1c) = 0;
                    *(undefined8 *)(lVar2 + 0x88) = 0;
                    if (7 < *puVar10) {
LAB_0010b28c:
                    /* WARNING: Does not return */
                      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10b290);
                      (*pcVar4)();
                    }
                    strscpy(lVar3 + lVar9 * 0x6f0 + (ulong)*puVar10 * 0xd8 + 0x2c,&DAT_0010e330,1);
                    if (7 < *puVar10) goto LAB_0010b28c;
                    strscpy(lVar3 + lVar9 * 0x6f0 + (ulong)*puVar10 * 0xd8 + 0x4c,&DAT_0010e330,1);
                    lVar11 = lVar11 + 0xd8;
                  } while (lVar11 != 0x6c0);
                  lVar9 = lVar9 + 1;
                  lVar8 = lVar8 + 0x6f0;
                  if (lVar9 == 5) {
                    init_done = 1;
                    return 0;
                  }
                } while( true );
              }
              puVar6 = &DAT_0010eff5;
            }
            else {
              puVar6 = &DAT_0010ebd3;
            }
          }
          else {
            puVar6 = &DAT_0010dc6e;
          }
        }
        else {
          puVar6 = &DAT_0010f0ef;
        }
      }
      else {
        puVar6 = &DAT_0010de91;
      }
    }
    else {
      puVar6 = &DAT_0010e669;
    }
    _printk(puVar6);
    kfree(gh_vms);
  }
  return iVar5;
}



//------------------------------------------------------------
// gh_proxy_sched_exit @ 0010b294 size=36
// signature: undefined gh_proxy_sched_exit(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

void gh_proxy_sched_exit(void)

{
  kfree(gh_vms);
  return;
}



//------------------------------------------------------------
// trace_raw_output_gh_hcall_vcpu_run @ 0010b2bc size=116
// signature: undefined trace_raw_output_gh_hcall_vcpu_run(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_gh_hcall_vcpu_run(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "ret=%d vm=%u vcpu=%u yield_time=%llu vcpu_state=%llu vcpu_suspend_state=%llu\n"
                       ,1,*(undefined2 *)(lVar2 + 0xc),*(undefined4 *)(lVar2 + 0x10),
                       *(undefined8 *)(lVar2 + 0x18),*(undefined8 *)(lVar2 + 0x20),
                       *(undefined8 *)(lVar2 + 0x28));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_gh_susp_res_irq_handler @ 0010b334 size=100
// signature: undefined trace_raw_output_gh_susp_res_irq_handler(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_gh_susp_res_irq_handler(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"vpmg_state=%llu\n",*(undefined8 *)(lVar2 + 8));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_gh_vcpu_irq_handler @ 0010b39c size=104
// signature: undefined trace_raw_output_gh_vcpu_irq_handler(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_gh_vcpu_irq_handler(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"vm=%u vcpu=%u\n",*(undefined2 *)(lVar2 + 8),
                       *(undefined4 *)(lVar2 + 0xc));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// gh_wdog_manage @ 0010b408 size=412
// signature: undefined gh_wdog_manage(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_wdog_manage(short param_1,undefined8 param_2,uint param_3)

{
  long lVar1;
  int iVar2;
  short *psVar3;
  undefined8 uVar4;
  short local_3c [2];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if ((init_done & 1) == 0) {
    _printk(&DAT_0010e1bd);
    uVar4 = 0xfffffffa;
    goto LAB_0010b544;
  }
  local_3c[0] = 0;
  iVar2 = ghd_rm_get_vmid(2,local_3c);
  if (((iVar2 != 0) || (local_3c[0] != param_1)) &&
     ((iVar2 = ghd_rm_get_vmid(4,local_3c), iVar2 != 0 || (local_3c[0] != param_1)))) {
    _printk(&DAT_0010f502,param_1);
    uVar4 = 0xffffffea;
    goto LAB_0010b544;
  }
  mutex_lock(gh_vm_mutex);
  psVar3 = gh_vms;
  if (*gh_vms == param_1) {
LAB_0010b514:
    if (psVar3 == (short *)0x0) goto LAB_0010b534;
LAB_0010b518:
    if ((param_3 & 1) == 0) {
      param_2 = 0xffffffffffffffff;
    }
    uVar4 = 0;
    *(undefined8 *)(psVar3 + 0x368) = param_2;
  }
  else {
    if (*gh_vms != -1) {
      psVar3 = gh_vms + 0x378;
      if ((gh_vms[0x378] != param_1) && (gh_vms[0x378] != -1)) {
        psVar3 = gh_vms + 0x6f0;
        if ((gh_vms[0x6f0] != param_1) && (gh_vms[0x6f0] != -1)) {
          psVar3 = gh_vms + 0xa68;
          if (gh_vms[0xa68] != -1 && gh_vms[0xa68] != param_1) {
            psVar3 = gh_vms + 0xde0;
          }
          goto joined_r0x0010b508;
        }
      }
      goto LAB_0010b514;
    }
joined_r0x0010b508:
    if (psVar3 != (short *)0x0) goto LAB_0010b518;
LAB_0010b534:
    uVar4 = 0xffffffed;
  }
  mutex_unlock(gh_vm_mutex);
LAB_0010b544:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



//------------------------------------------------------------
// gh_populate_vm_vcpu_info @ 0010b5a8 size=1044
// signature: undefined gh_populate_vm_vcpu_info(void)
// callers: []
//------------------------------------------------------------

int gh_populate_vm_vcpu_info(short param_1,undefined4 param_2,undefined8 param_3,int param_4)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  short *psVar5;
  short local_5c [2];
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  if ((init_done & 1) == 0) {
    _printk(&DAT_0010e1bd);
    iVar3 = -6;
    goto LAB_0010b6f4;
  }
  local_5c[0] = 0;
  iVar3 = ghd_rm_get_vmid(2,local_5c);
  if (((iVar3 != 0) || (local_5c[0] != param_1)) &&
     ((iVar3 = ghd_rm_get_vmid(4,local_5c), iVar3 != 0 || (local_5c[0] != param_1)))) {
    _printk(&DAT_0010f502,param_1);
    iVar3 = 0;
    goto LAB_0010b6f4;
  }
  if (0x27 < nr_vcpus) {
    _printk(&DAT_0010ec8a);
    iVar3 = -6;
    goto LAB_0010b6f4;
  }
  if (param_4 + 1U < 2) {
    _printk(&DAT_0010f6ea);
    iVar3 = 0;
    goto LAB_0010b6f4;
  }
  mutex_lock(gh_vm_mutex);
  psVar5 = gh_vms;
  if (*gh_vms == param_1) {
LAB_0010b6d8:
    if (psVar5 == (short *)0x0) goto LAB_0010b6e4;
LAB_0010b6dc:
    if ((char)psVar5[0x364] != '\0') goto LAB_0010b6e4;
    uVar1 = *(uint *)(psVar5 + 2);
    if ((int)uVar1 < 8) {
      if (7 < uVar1) goto LAB_0010b9b4;
      strscpy(psVar5 + (ulong)uVar1 * 0x6c + 0x16,"gh_vcpu_irq",0xc);
      uVar1 = *(uint *)(psVar5 + 2);
      if (7 < uVar1) goto LAB_0010b9b4;
      gh_get_vcpu_prop_name(param_1,(ulong)uVar1,psVar5 + (ulong)uVar1 * 0x6c + 0x16);
      uVar1 = *(uint *)(psVar5 + 2);
      if (7 < uVar1) goto LAB_0010b9b4;
      iVar3 = request_threaded_irq
                        (param_4,gh_vcpu_irq_handler,0,0,psVar5 + (ulong)uVar1 * 0x6c + 0x16,
                         psVar5 + (ulong)uVar1 * 0x6c + 4);
      if (iVar3 < 0) {
        _printk(&DAT_0010f650,"gh_populate_vm_vcpu_info",iVar3);
      }
      else {
        irq_set_irq_wake(param_4,1);
        if (7 < *(uint *)(psVar5 + 2)) goto LAB_0010b9b4;
        strscpy(psVar5 + (ulong)*(uint *)(psVar5 + 2) * 0x6c + 0x26,"gh_vcpu_ws",0xb);
        uVar1 = *(uint *)(psVar5 + 2);
        if (7 < uVar1) goto LAB_0010b9b4;
        gh_get_vcpu_prop_name(param_1,(ulong)uVar1,psVar5 + (ulong)uVar1 * 0x6c + 0x26);
        if (7 < *(uint *)(psVar5 + 2)) goto LAB_0010b9b4;
        lVar4 = wakeup_source_register(0,psVar5 + (ulong)*(uint *)(psVar5 + 2) * 0x6c + 0x26);
        uVar1 = *(uint *)(psVar5 + 2);
        if (7 < uVar1) goto LAB_0010b9b4;
        *(long *)(psVar5 + (ulong)uVar1 * 0x6c + 0x44) = lVar4;
        if (lVar4 != 0) {
          *psVar5 = param_1;
          *(uint *)(psVar5 + 2) = uVar1 + 1;
          *(int *)(psVar5 + (ulong)uVar1 * 0x6c + 0x14) = param_4;
          *(undefined4 *)(psVar5 + (ulong)uVar1 * 0x6c + 0xc) = param_2;
          *(short **)(psVar5 + (ulong)uVar1 * 0x6c + 4) = psVar5;
          *(undefined8 *)(psVar5 + (ulong)uVar1 * 0x6c + 8) = param_3;
          nr_vcpus = nr_vcpus + 1;
          _printk(&DAT_0010e1e4,param_1,param_2,param_3,param_4,psVar5 + (ulong)uVar1 * 0x6c + 0x16)
          ;
          goto LAB_0010b6e8;
        }
        _printk(&DAT_0010e10f,"gh_populate_vm_vcpu_info");
        if (7 < *(uint *)(psVar5 + 2)) goto LAB_0010b9b4;
        strscpy(psVar5 + (ulong)*(uint *)(psVar5 + 2) * 0x6c + 0x26,&DAT_0010e330,1);
        if (8 < *(uint *)(psVar5 + 2)) goto LAB_0010b9b4;
        free_irq(param_4,psVar5 + (ulong)*(uint *)(psVar5 + 2) * 0x6c + 4);
      }
      if (7 < *(uint *)(psVar5 + 2)) {
LAB_0010b9b4:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10b9b8);
        (*pcVar2)();
      }
      strscpy(psVar5 + (ulong)*(uint *)(psVar5 + 2) * 0x6c + 0x16,&DAT_0010e330,1);
    }
    else {
      _printk(&DAT_0010f3c3);
      iVar3 = -6;
    }
  }
  else {
    if (*gh_vms != -1) {
      psVar5 = gh_vms + 0x378;
      if ((gh_vms[0x378] != param_1) && (gh_vms[0x378] != -1)) {
        psVar5 = gh_vms + 0x6f0;
        if ((gh_vms[0x6f0] != param_1) && (gh_vms[0x6f0] != -1)) {
          psVar5 = gh_vms + 0xa68;
          if (gh_vms[0xa68] != -1 && gh_vms[0xa68] != param_1) {
            psVar5 = gh_vms + 0xde0;
          }
          goto joined_r0x0010b6cc;
        }
      }
      goto LAB_0010b6d8;
    }
joined_r0x0010b6cc:
    if (psVar5 != (short *)0x0) goto LAB_0010b6dc;
LAB_0010b6e4:
    iVar3 = 0;
  }
LAB_0010b6e8:
  mutex_unlock(gh_vm_mutex);
LAB_0010b6f4:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// gh_unpopulate_vm_vcpu_info @ 0010b9c0 size=736
// signature: undefined gh_unpopulate_vm_vcpu_info(void)
// callers: []
//------------------------------------------------------------

void gh_unpopulate_vm_vcpu_info(short param_1,undefined8 param_2,long param_3,undefined4 *param_4)

{
  short *psVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  short local_3c [2];
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  if ((init_done & 1) == 0) {
    _printk(&DAT_0010e1bd);
    uVar4 = 0xfffffffa;
    goto LAB_0010bb80;
  }
  local_3c[0] = 0;
  iVar3 = ghd_rm_get_vmid(2,local_3c);
  if (((iVar3 == 0) && (local_3c[0] == param_1)) ||
     ((iVar3 = ghd_rm_get_vmid(4,local_3c), iVar3 == 0 && (local_3c[0] == param_1)))) {
    mutex_lock(gh_vm_mutex);
    psVar1 = gh_vms;
    if ((*gh_vms != param_1) && (*gh_vms != -1)) {
      psVar1 = gh_vms + 0x378;
      if ((gh_vms[0x378] != param_1) && (gh_vms[0x378] != -1)) {
        psVar1 = gh_vms + 0x6f0;
        if ((gh_vms[0x6f0] != param_1) && (gh_vms[0x6f0] != -1)) {
          psVar1 = gh_vms + 0xa68;
          if (gh_vms[0xa68] != -1 && gh_vms[0xa68] != param_1) {
            psVar1 = gh_vms + 0xde0;
          }
        }
      }
    }
    if ((psVar1 != (short *)0x0) && ((char)psVar1[0x364] != '\0')) {
      if (*(long *)(psVar1 + 0x374) != 0) {
        destroy_workqueue();
        psVar1[0x374] = 0;
        psVar1[0x375] = 0;
        psVar1[0x376] = 0;
        psVar1[0x377] = 0;
      }
      iVar3 = *(int *)(psVar1 + 2);
      if (0 < iVar3) {
        if (*(long *)(psVar1 + 8) == param_3) {
          lVar5 = 0;
LAB_0010bb00:
          if (psVar1 + lVar5 * 0x6c + 4 != (short *)0x0) {
            *param_4 = *(undefined4 *)(psVar1 + lVar5 * 0x6c + 0x14);
            free_irq(*(undefined4 *)(psVar1 + lVar5 * 0x6c + 0x14),psVar1 + lVar5 * 0x6c + 4);
            uVar4 = *(undefined8 *)(psVar1 + lVar5 * 0x6c + 0x44);
            (psVar1 + lVar5 * 0x6c + 0x14)[0] = -1;
            (psVar1 + lVar5 * 0x6c + 0x14)[1] = -1;
            wakeup_source_unregister(uVar4);
            *(undefined1 *)(psVar1 + lVar5 * 0x6c + 0x48) = 0;
            unregister_pm_notifier(psVar1 + lVar5 * 0x6c + 100);
            if (nr_vcpus != 0) {
              nr_vcpus = nr_vcpus + -1;
            }
          }
        }
        else if (iVar3 != 1) {
          if (*(long *)(psVar1 + 0x74) == param_3) {
            lVar5 = 1;
            goto LAB_0010bb00;
          }
          if (iVar3 != 2) {
            if (*(long *)(psVar1 + 0xe0) == param_3) {
              lVar5 = 2;
              goto LAB_0010bb00;
            }
            if (iVar3 != 3) {
              if (*(long *)(psVar1 + 0x14c) == param_3) {
                lVar5 = 3;
                goto LAB_0010bb00;
              }
              if (iVar3 != 4) {
                if (*(long *)(psVar1 + 0x1b8) == param_3) {
                  lVar5 = 4;
                  goto LAB_0010bb00;
                }
                if (iVar3 != 5) {
                  if (*(long *)(psVar1 + 0x224) == param_3) {
                    lVar5 = 5;
                    goto LAB_0010bb00;
                  }
                  if (iVar3 != 6) {
                    if (*(long *)(psVar1 + 0x290) == param_3) {
                      lVar5 = 6;
                      goto LAB_0010bb00;
                    }
                    if (iVar3 != 7) {
                      if (*(long *)(psVar1 + 0x2fc) == param_3) {
                        lVar5 = 7;
                        goto LAB_0010bb00;
                      }
                      if (iVar3 != 8) {
                    /* WARNING: Does not return */
                        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10bc9c);
                        (*pcVar2)();
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    mutex_unlock(gh_vm_mutex);
  }
  else {
    _printk(&DAT_0010e7cf,param_1);
  }
  uVar4 = 0;
LAB_0010bb80:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// gh_populate_vm_vpm_grp_info @ 0010bca4 size=540
// signature: undefined gh_populate_vm_vpm_grp_info(void)
// callers: []
//------------------------------------------------------------

int gh_populate_vm_vpm_grp_info(short param_1,undefined8 param_2,int param_3)

{
  long lVar1;
  int iVar2;
  short *psVar3;
  short local_4c [2];
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  if ((init_done & 1) == 0) {
    _printk(&DAT_0010e53a,"gh_populate_vm_vpm_grp_info");
    iVar2 = -6;
    goto LAB_0010be1c;
  }
  local_4c[0] = 0;
  iVar2 = ghd_rm_get_vmid(2,local_4c);
  if (((iVar2 != 0) || (local_4c[0] != param_1)) &&
     ((iVar2 = ghd_rm_get_vmid(4,local_4c), iVar2 != 0 || (local_4c[0] != param_1)))) {
    _printk(&DAT_0010ea0d,param_1);
    iVar2 = 0;
    goto LAB_0010be1c;
  }
  if (param_3 < 0) {
    _printk(&DAT_0010e851,"gh_populate_vm_vpm_grp_info");
    iVar2 = -0x16;
    goto LAB_0010be1c;
  }
  mutex_lock(gh_vm_mutex);
  psVar3 = gh_vms;
  if (*gh_vms == param_1) {
LAB_0010bdb4:
    if (psVar3 == (short *)0x0) goto LAB_0010bdc0;
LAB_0010bdb8:
    if ((char)psVar3[0x372] != '\0') goto LAB_0010bdc0;
    iVar2 = request_threaded_irq(param_3,gh_susp_res_irq_handler,0,0,"gh_susp_res_irq",0);
    if (iVar2 < 0) {
      _printk(&DAT_0010f650,"gh_populate_vm_vpm_grp_info",iVar2);
    }
    else {
      *(undefined8 *)(psVar3 + 0x36c) = param_2;
      *(int *)(psVar3 + 0x370) = param_3;
      *(undefined1 *)(psVar3 + 0x372) = 1;
    }
  }
  else {
    if (*gh_vms != -1) {
      psVar3 = gh_vms + 0x378;
      if ((gh_vms[0x378] != param_1) && (gh_vms[0x378] != -1)) {
        psVar3 = gh_vms + 0x6f0;
        if ((gh_vms[0x6f0] != param_1) && (gh_vms[0x6f0] != -1)) {
          psVar3 = gh_vms + 0xa68;
          if (gh_vms[0xa68] != -1 && gh_vms[0xa68] != param_1) {
            psVar3 = gh_vms + 0xde0;
          }
          goto joined_r0x0010bda8;
        }
      }
      goto LAB_0010bdb4;
    }
joined_r0x0010bda8:
    if (psVar3 != (short *)0x0) goto LAB_0010bdb8;
LAB_0010bdc0:
    iVar2 = 0;
  }
  mutex_unlock(gh_vm_mutex);
LAB_0010be1c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gh_unpopulate_vm_vpm_grp_info @ 0010bec4 size=428
// signature: undefined gh_unpopulate_vm_vpm_grp_info(void)
// callers: []
//------------------------------------------------------------

void gh_unpopulate_vm_vpm_grp_info(short param_1,undefined4 *param_2)

{
  long lVar1;
  short *psVar2;
  int iVar3;
  undefined8 uVar4;
  short local_3c [2];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if ((init_done & 1) == 0) {
    _printk(&DAT_0010e53a,"gh_unpopulate_vm_vpm_grp_info");
    uVar4 = 0xfffffffa;
  }
  else {
    local_3c[0] = 0;
    iVar3 = ghd_rm_get_vmid(2,local_3c);
    if (((iVar3 == 0) && (local_3c[0] == param_1)) ||
       ((iVar3 = ghd_rm_get_vmid(4,local_3c), iVar3 == 0 && (local_3c[0] == param_1)))) {
      mutex_lock(gh_vm_mutex);
      psVar2 = gh_vms;
      if ((*gh_vms != param_1) && (*gh_vms != -1)) {
        psVar2 = gh_vms + 0x378;
        if ((gh_vms[0x378] != param_1) && (gh_vms[0x378] != -1)) {
          psVar2 = gh_vms + 0x6f0;
          if ((gh_vms[0x6f0] != param_1) && (gh_vms[0x6f0] != -1)) {
            psVar2 = gh_vms + 0xa68;
            if (gh_vms[0xa68] != -1 && gh_vms[0xa68] != param_1) {
              psVar2 = gh_vms + 0xde0;
            }
          }
        }
      }
      if ((psVar2 != (short *)0x0) && ((char)psVar2[0x372] != '\0')) {
        *param_2 = *(undefined4 *)(psVar2 + 0x370);
        free_irq(*(undefined4 *)(psVar2 + 0x370),0);
        *(undefined1 *)(psVar2 + 0x372) = 0;
        psVar2[0x370] = -1;
        psVar2[0x371] = -1;
      }
      mutex_unlock(gh_vm_mutex);
    }
    else {
      _printk(&DAT_0010dcae,param_1);
    }
    uVar4 = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// gh_populate_all_res_info @ 0010c074 size=996
// signature: undefined gh_populate_all_res_info(void)
// callers: []
//------------------------------------------------------------

void gh_populate_all_res_info(ushort param_1,ulong param_2)

{
  uint uVar1;
  ushort *puVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  ushort local_74 [2];
  char local_70 [24];
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_70[8] = '\0';
  local_70[9] = '\0';
  local_70[10] = '\0';
  local_70[0xb] = '\0';
  local_70[0xc] = '\0';
  local_70[0xd] = '\0';
  local_70[0xe] = '\0';
  local_70[0xf] = '\0';
  local_70[0x10] = '\0';
  local_70[0x11] = '\0';
  local_70[0x12] = '\0';
  local_70[0x13] = '\0';
  local_70[0x14] = '\0';
  local_70[0x15] = '\0';
  local_70[0x16] = '\0';
  local_70[0x17] = '\0';
  local_70[0] = '\0';
  local_70[1] = '\0';
  local_70[2] = '\0';
  local_70[3] = '\0';
  local_70[4] = '\0';
  local_70[5] = '\0';
  local_70[6] = '\0';
  local_70[7] = '\0';
  if ((init_done & 1) == 0) {
    _printk(&DAT_0010e53a,"gh_populate_all_res_info");
  }
  else {
    local_74[0] = 0;
    iVar4 = ghd_rm_get_vmid(2,local_74);
    if (((iVar4 == 0) && (local_74[0] == param_1)) ||
       ((iVar4 = ghd_rm_get_vmid(4,local_74), iVar4 == 0 && (local_74[0] == param_1)))) {
      if (nr_vms < 5) {
        mutex_lock(gh_vm_mutex);
        puVar2 = gh_vms;
        if ((*gh_vms != param_1) && (*gh_vms != 0xffff)) {
          puVar2 = gh_vms + 0x378;
          if ((gh_vms[0x378] != param_1) && (gh_vms[0x378] != 0xffff)) {
            puVar2 = gh_vms + 0x6f0;
            if ((gh_vms[0x6f0] != param_1) && (gh_vms[0x6f0] != 0xffff)) {
              puVar2 = gh_vms + 0xa68;
              if (gh_vms[0xa68] != 0xffff && gh_vms[0xa68] != param_1) {
                puVar2 = gh_vms + 0xde0;
              }
            }
          }
        }
        if (puVar2 != (ushort *)0x0) {
          if ((param_2 & 1) == 0) {
            if ((char)puVar2[0x364] != '\0') {
              lVar6 = 0;
              puVar2[2] = 0;
              puVar2[3] = 0;
              puVar2[0x364] = 0;
              *puVar2 = 0xffff;
              puVar2[0x370] = 0xffff;
              puVar2[0x371] = 0xffff;
              *(undefined1 *)(puVar2 + 0x372) = 0;
              puVar2[0x36c] = 0xffff;
              puVar2[0x36d] = 0xffff;
              puVar2[0x36e] = 0xffff;
              puVar2[0x36f] = 0xffff;
              do {
                uVar1 = *(uint *)(puVar2 + 2);
                *(undefined4 *)((long)puVar2 + lVar6 + 0x28) = 0xffffffff;
                *(undefined4 *)((long)puVar2 + lVar6 + 0x18) = 0xffffffff;
                *(undefined8 *)((long)puVar2 + lVar6 + 8) = 0;
                *(undefined8 *)((long)puVar2 + lVar6 + 0x10) = 0xffffffffffffffff;
                *(undefined2 *)((long)puVar2 + lVar6 + 0x1c) = 0;
                *(undefined8 *)((long)puVar2 + lVar6 + 0x88) = 0;
                if (7 < uVar1) goto LAB_0010c450;
                strscpy(puVar2 + (ulong)uVar1 * 0x6c + 0x16,&DAT_0010e330,1);
                if (7 < *(uint *)(puVar2 + 2)) goto LAB_0010c450;
                strscpy(puVar2 + (ulong)*(uint *)(puVar2 + 2) * 0x6c + 0x26,&DAT_0010e330,1);
                lVar6 = lVar6 + 0xd8;
              } while (lVar6 != 0x6c0);
              if (nr_vms != 0) {
                nr_vms = nr_vms + -1;
              }
            }
          }
          else if ((char)puVar2[0x364] == '\0') {
            if ((((((*(int *)(puVar2 + 2) != 0) &&
                   (__init_waitqueue_head
                              (puVar2 + 0x38,"&vm->vcpu[j].wait_queue",&gh_init_wait_queues___key),
                   1 < *(uint *)(puVar2 + 2))) &&
                  (__init_waitqueue_head
                             (puVar2 + 0xa4,"&vm->vcpu[j].wait_queue",&gh_init_wait_queues___key),
                  2 < *(uint *)(puVar2 + 2))) &&
                 ((__init_waitqueue_head
                             (puVar2 + 0x110,"&vm->vcpu[j].wait_queue",&gh_init_wait_queues___key),
                  3 < *(uint *)(puVar2 + 2) &&
                  (__init_waitqueue_head
                             (puVar2 + 0x17c,"&vm->vcpu[j].wait_queue",&gh_init_wait_queues___key),
                  4 < *(uint *)(puVar2 + 2))))) &&
                ((__init_waitqueue_head
                            (puVar2 + 0x1e8,"&vm->vcpu[j].wait_queue",&gh_init_wait_queues___key),
                 5 < *(uint *)(puVar2 + 2) &&
                 ((__init_waitqueue_head
                             (puVar2 + 0x254,"&vm->vcpu[j].wait_queue",&gh_init_wait_queues___key),
                  6 < *(uint *)(puVar2 + 2) &&
                  (__init_waitqueue_head
                             (puVar2 + 0x2c0,"&vm->vcpu[j].wait_queue",&gh_init_wait_queues___key),
                  7 < *(uint *)(puVar2 + 2))))))) &&
               (__init_waitqueue_head
                          (puVar2 + 0x32c,"&vm->vcpu[j].wait_queue",&gh_init_wait_queues___key),
               8 < *(uint *)(puVar2 + 2))) {
LAB_0010c450:
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10c454);
              (*pcVar3)();
            }
            snprintf(local_70,0x18,"vm%d_vcpu_wq",(uint)*puVar2);
            uVar5 = alloc_workqueue(&DAT_0010e17b,0x4000e,1,local_70);
            *(undefined8 *)(puVar2 + 0x374) = uVar5;
            nr_vms = nr_vms + 1;
            puVar2[0x364] = 0x101;
          }
        }
        mutex_unlock(gh_vm_mutex);
      }
      else {
        _printk(&DAT_0010ee75);
      }
    }
    else {
      _printk(&DAT_0010e565,param_1);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gh_get_vcpu_prop_name @ 0010c458 size=132
// signature: undefined gh_get_vcpu_prop_name(void)
// callers: [gh_populate_vm_vcpu_info]
//------------------------------------------------------------

void gh_get_vcpu_prop_name(undefined4 param_1,undefined4 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 local_38;
  undefined4 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  local_38 = 0;
  scnprintf(&local_38,0xc,"_%d_%d",param_1,param_2);
  strlcat(param_3,&local_38,0x20);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gh_vcpu_irq_handler @ 0010c4e0 size=168
// signature: undefined gh_vcpu_irq_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_vcpu_irq_handler(undefined8 param_1,long *param_2)

{
  long lVar1;
  
  _raw_spin_lock(&gh_vm_lock);
  if (((param_2 != (long *)0x0) && (lVar1 = *param_2, lVar1 != 0)) &&
     (*(char *)(lVar1 + 0x6c8) != '\0')) {
    if ((char)param_2[0x11] == '\0') {
      *(undefined1 *)((long)param_2 + 0x14) = 1;
      __wake_up(param_2 + 0xd,3,1,0);
    }
    else {
      queue_work_on(0x20,*(undefined8 *)(lVar1 + 0x6e8),param_2 + 0x12);
    }
  }
  _raw_spin_unlock(&gh_vm_lock);
  return 1;
}



//------------------------------------------------------------
// gh_susp_res_irq_handler @ 0010c634 size=304
// signature: undefined gh_susp_res_irq_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_susp_res_irq_handler(int param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = sp_el0;
  lVar2 = *(long *)(lVar2 + 0x638);
  if (*(int *)(gh_vms + 0x6e0) == param_1) {
    uVar3 = *(undefined8 *)(gh_vms + 0x6d8);
  }
  else {
    uVar3 = 0;
  }
  if (*(int *)(gh_vms + 0xdd0) == param_1) {
    uVar3 = *(undefined8 *)(gh_vms + 0xdc8);
  }
  if (*(int *)(gh_vms + 0x14c0) == param_1) {
    uVar3 = *(undefined8 *)(gh_vms + 0x14b8);
  }
  if (*(int *)(gh_vms + 0x1bb0) == param_1) {
    uVar3 = *(undefined8 *)(gh_vms + 0x1ba8);
  }
  if (*(int *)(gh_vms + 0x22a0) == param_1) {
    uVar3 = *(undefined8 *)(gh_vms + 0x2298);
  }
  CallHyperVisor(0x6045);
  if ((int)uVar3 == 0) {
    _printk(&DAT_0010e87b,0,uVar3,0,0,0,0,0,0);
  }
  else {
    _printk(&DAT_0010ddb5,uVar3,uVar3,0,0,0,0,0,0);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != lVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// init_module @ 0010c864 size=172
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = gh_secure_vm_loader_init();
  if (iVar1 != 0) {
    _printk(&DAT_0010f350,iVar1);
  }
  iVar1 = gh_proxy_sched_init();
  if (iVar1 != 0) {
    _printk(&DAT_0010f549,iVar1);
  }
  iVar1 = misc_register(gh_dev);
  if (iVar1 == 0) {
    iVar1 = gh_virtio_backend_init();
    if (iVar1 != 0) {
      _printk(&DAT_0010e039,iVar1);
    }
  }
  else {
    _printk(&DAT_0010e911,iVar1);
    gh_proxy_sched_exit();
    gh_secure_vm_loader_exit();
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// gh_virtio_backend_init @ 0010c914 size=36
// signature: undefined gh_virtio_backend_init(void)
// callers: [init_module]
//------------------------------------------------------------

void gh_virtio_backend_init(void)

{
  gh_rm_set_virtio_mmio_cb(gh_virtio_mmio_init);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010c93c size=48
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  misc_deregister(gh_dev);
  gh_proxy_sched_exit();
  gh_secure_vm_loader_exit();
  gh_virtio_backend_exit();
  return;
}



//------------------------------------------------------------
// gh_virtio_backend_exit @ 0010c970 size=28
// signature: undefined gh_virtio_backend_exit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void gh_virtio_backend_exit(void)

{
  gh_rm_unset_virtio_mmio_cb();
  return;
}



//------------------------------------------------------------
// srcu_notifier_chain_register @ 00114000 size=1
// signature: undefined srcu_notifier_chain_register(void)
// callers: [gh_register_vm_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void srcu_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// srcu_notifier_chain_unregister @ 00114008 size=1
// signature: undefined srcu_notifier_chain_unregister(void)
// callers: [gh_unregister_vm_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void srcu_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00114010 size=1
// signature: undefined kfree(void)
// callers: [gh_destroy_vm, gh_vm_ioctl_set_fw_name, gh_proxy_sched_exit, gh_uevent_notify_change, gh_vm_ioctl, gh_virtio_mmio_init, gh_proxy_sched_init, gh_destroy_vcpu, gh_provide_mem, gh_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// srcu_notifier_call_chain @ 00114018 size=1
// signature: undefined srcu_notifier_call_chain(void)
// callers: [gh_destroy_vm, gh_vcpu_ioctl, gh_vm_rm_notifier_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void srcu_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_unpopulate_hyp_res @ 00114020 size=1
// signature: undefined gh_rm_unpopulate_hyp_res(void)
// callers: [gh_destroy_vm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_unpopulate_hyp_res(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_vm_reset @ 00114028 size=1
// signature: undefined ghd_rm_vm_reset(void)
// callers: [gh_destroy_vm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_vm_reset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00114030 size=1
// signature: undefined init_wait_entry(void)
// callers: [gh_destroy_vm, gh_virtio_mmio_exit, gh_virtio_backend_ioctl, gh_vcpu_ioctl, gh_vcpu_run, gh_vm_configure, gh_exit_vm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00114038 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [gh_destroy_vm, gh_virtio_mmio_exit, gh_virtio_backend_ioctl, gh_vcpu_ioctl, gh_vcpu_run, gh_vm_configure, gh_exit_vm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 00114040 size=1
// signature: undefined schedule(void)
// callers: [gh_destroy_vm, gh_virtio_mmio_exit, gh_virtio_backend_ioctl, gh_vcpu_ioctl, gh_vcpu_run, gh_vm_configure, gh_exit_vm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 00114048 size=1
// signature: undefined finish_wait(void)
// callers: [gh_destroy_vm, gh_virtio_mmio_exit, gh_virtio_backend_ioctl, gh_vcpu_ioctl, gh_vcpu_run, gh_vm_configure, gh_exit_vm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_vm_dealloc_vmid @ 00114050 size=1
// signature: undefined gh_rm_vm_dealloc_vmid(void)
// callers: [gh_destroy_vm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_vm_dealloc_vmid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_unregister_notifier @ 00114058 size=1
// signature: undefined gh_rm_unregister_notifier(void)
// callers: [gh_destroy_vm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_unregister_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00114060 size=1
// signature: undefined _printk(void)
// callers: [gh_vm_ioctl_set_fw_name, gh_secure_vm_loader_probe, gh_virtio_mmio_init, gh_destroy_vm, gh_vm_rm_notifier_fn, gh_unpopulate_vm_vpm_grp_info, gh_vm_release, gh_proxy_sched_init, gh_provide_mem, gh_dev_ioctl, gh_unpopulate_vm_vcpu_info, gh_vcpu_ioctl, gh_vcpu_run, gh_wdog_manage, gh_exit_vm, gh_parse_virtio_properties, gh_populate_vm_vcpu_info, unshare_a_vm_buffer, gh_secure_vm_loader_reclaim_fw, gh_populate_vm_vpm_grp_info, gh_populate_all_res_info, gh_vcpu_release, gh_vm_configure, gh_reclaim_mem, gh_susp_res_irq_handler, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00114068 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [gh_vm_ioctl_set_fw_name, perf_trace_gh_virtio_backend_irq, gh_secure_vm_loader_probe, gh_vm_ioctl, gh_virtio_backend_ioctl, gh_vm_ioctl_get_fw_name, gh_virtio_mmio_init, trace_event_raw_event_gh_virtio_backend_wait_event, perf_trace_gh_virtio_backend_irq_inj, gh_destroy_vm, perf_trace_gh_vcpu_irq_handler, trace_event_raw_event_gh_vcpu_irq_handler, perf_trace_gh_virtio_backend_wait_event, perf_trace_gh_hcall_vcpu_run, gh_unpopulate_vm_vpm_grp_info, trace_event_raw_event_gh_hcall_vcpu_run, trace_event_raw_event_gh_virtio_backend_irq_inj, gh_provide_mem, perf_trace_gh_virtio_backend_queue_notify, gh_unpopulate_vm_vcpu_info, gh_vcpu_ioctl, gh_vcpu_run, gh_wdog_manage, gh_vcpu_work_function, gh_exit_vm, vb_dev_irqfd_wakeup, vdev_interrupt, trace_event_raw_event_gh_susp_res_irq_handler, gh_parse_virtio_properties, gh_populate_vm_vcpu_info, unshare_a_vm_buffer, perf_trace_gh_susp_res_irq_handler, gh_populate_vm_vpm_grp_info, trace_event_raw_event_gh_virtio_backend_irq, gh_poll_vcpu_run, gh_populate_all_res_info, trace_event_raw_event_gh_virtio_backend_queue_notify, gh_virtio_mmio_exit, unshare_vm_buffers, gh_vm_configure, irqfd_shutdown, gh_get_vcpu_prop_name, gh_vcpu_pm_notifier_call, gh_reclaim_mem, gh_susp_res_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00114078 size=1
// signature: undefined kmalloc_trace(void)
// callers: [gh_uevent_notify_change, gh_vm_ioctl, gh_virtio_mmio_init, gh_provide_mem, gh_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// add_uevent_var @ 00114080 size=1
// signature: undefined add_uevent_var(void)
// callers: [gh_uevent_notify_change]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void add_uevent_var(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_uevent_env @ 00114088 size=1
// signature: undefined kobject_uevent_env(void)
// callers: [gh_uevent_notify_change]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_uevent_env(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_mem_reclaim @ 00114090 size=1
// signature: undefined ghd_rm_mem_reclaim(void)
// callers: [gh_reclaim_mem, unshare_a_vm_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_mem_reclaim(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_assign_mem @ 00114098 size=1
// signature: undefined qcom_scm_assign_mem(void)
// callers: [gh_reclaim_mem, gh_virtio_mmio_init, unshare_a_vm_buffer, gh_provide_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_assign_mem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_mem_donate @ 001140a0 size=1
// signature: undefined gh_rm_mem_donate(void)
// callers: [gh_provide_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_mem_donate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_mem_lend @ 001140a8 size=1
// signature: undefined ghd_rm_mem_lend(void)
// callers: [gh_provide_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_mem_lend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_vm_config_image @ 001140b0 size=1
// signature: undefined gh_rm_vm_config_image(void)
// callers: [gh_vm_configure]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_vm_config_image(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_vm_auth_image @ 001140b8 size=1
// signature: undefined gh_rm_vm_auth_image(void)
// callers: [gh_vm_configure]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_vm_auth_image(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_vm_init @ 001140c0 size=1
// signature: undefined ghd_rm_vm_init(void)
// callers: [gh_vm_configure]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_vm_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_populate_hyp_res @ 001140c8 size=1
// signature: undefined gh_rm_populate_hyp_res(void)
// callers: [gh_vm_configure]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_populate_hyp_res(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// misc_register @ 001140d0 size=1
// signature: undefined misc_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void misc_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// misc_deregister @ 001140d8 size=1
// signature: undefined misc_deregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void misc_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001140e0 size=1
// signature: undefined mutex_lock(void)
// callers: [gh_vm_ioctl_set_fw_name, gh_unpopulate_vm_vcpu_info, gh_vm_ioctl, gh_virtio_backend_ioctl, gh_vcpu_ioctl, gh_wdog_manage, gh_vm_ioctl_get_fw_name, gh_exit_vm, gh_parse_virtio_properties, gh_populate_vm_vcpu_info, gh_virtio_mmio_init, gh_populate_vm_vpm_grp_info, gh_populate_all_res_info, gh_vm_rm_notifier_fn, gh_unpopulate_vm_vpm_grp_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_vm_stop @ 001140e8 size=1
// signature: undefined ghd_rm_vm_stop(void)
// callers: [gh_exit_vm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_vm_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001140f0 size=1
// signature: undefined mutex_unlock(void)
// callers: [gh_vm_ioctl_set_fw_name, gh_unpopulate_vm_vcpu_info, gh_vm_ioctl, gh_virtio_backend_ioctl, gh_vcpu_ioctl, gh_wdog_manage, gh_vm_ioctl_get_fw_name, gh_exit_vm, gh_parse_virtio_properties, gh_populate_vm_vcpu_info, gh_virtio_mmio_init, gh_populate_vm_vpm_grp_info, gh_populate_all_res_info, gh_vm_rm_notifier_fn, gh_unpopulate_vm_vpm_grp_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001140f8 size=1
// signature: undefined __mutex_init(void)
// callers: [gh_parse_virtio_properties, gh_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_register_notifier @ 00114100 size=1
// signature: undefined gh_rm_register_notifier(void)
// callers: [gh_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_register_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00114108 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [gh_populate_all_res_info, gh_parse_virtio_properties, gh_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_unused_fd_flags @ 00114110 size=1
// signature: undefined get_unused_fd_flags(void)
// callers: [gh_vm_ioctl, gh_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_unused_fd_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// anon_inode_getfile @ 00114118 size=1
// signature: undefined anon_inode_getfile(void)
// callers: [gh_vm_ioctl, gh_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void anon_inode_getfile(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_unused_fd @ 00114120 size=1
// signature: undefined put_unused_fd(void)
// callers: [gh_vm_ioctl, gh_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_unused_fd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fd_install @ 00114130 size=1
// signature: undefined fd_install(void)
// callers: [gh_vm_ioctl, gh_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fd_install(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 00114138 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [gh_vm_ioctl, gh_vcpu_release, gh_vm_release, gh_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 00114140 size=1
// signature: undefined __wake_up(void)
// callers: [gh_virtio_mmio_exit, gh_virtio_backend_ioctl, gh_vcpu_irq_handler, gh_vm_rm_notifier_fn, gh_wakeup_all_vcpus, vdev_interrupt, gh_parse_virtio_properties, gh_virtio_mmio_init, vb_dev_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00114148 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [gh_populate_all_res_info, gh_vm_ioctl, gh_parse_virtio_properties]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_vm_start @ 00114150 size=1
// signature: undefined ghd_rm_vm_start(void)
// callers: [gh_vcpu_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_vm_start(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 00114168 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_gh_virtio_backend_irq, trace_event_raw_event_gh_virtio_backend_queue_notify, trace_event_raw_event_gh_vcpu_irq_handler, trace_event_raw_event_gh_susp_res_irq_handler, trace_event_raw_event_gh_hcall_vcpu_run, trace_event_raw_event_gh_virtio_backend_irq_inj, trace_event_raw_event_gh_virtio_backend_wait_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 00114170 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_gh_virtio_backend_irq, trace_event_raw_event_gh_virtio_backend_queue_notify, trace_event_raw_event_gh_vcpu_irq_handler, trace_event_raw_event_gh_susp_res_irq_handler, trace_event_raw_event_gh_hcall_vcpu_run, trace_event_raw_event_gh_virtio_backend_irq_inj, trace_event_raw_event_gh_virtio_backend_wait_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 00114178 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_gh_virtio_backend_irq, trace_event_raw_event_gh_virtio_backend_queue_notify, trace_event_raw_event_gh_vcpu_irq_handler, trace_event_raw_event_gh_susp_res_irq_handler, trace_event_raw_event_gh_hcall_vcpu_run, trace_event_raw_event_gh_virtio_backend_irq_inj, trace_event_raw_event_gh_virtio_backend_wait_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 00114180 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_gh_vcpu_irq_handler, perf_trace_gh_virtio_backend_queue_notify, perf_trace_gh_virtio_backend_irq, perf_trace_gh_virtio_backend_wait_event, perf_trace_gh_hcall_vcpu_run, perf_trace_gh_virtio_backend_irq_inj, perf_trace_gh_susp_res_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 00114188 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_gh_vcpu_irq_handler, perf_trace_gh_virtio_backend_queue_notify, perf_trace_gh_virtio_backend_irq, perf_trace_gh_virtio_backend_wait_event, perf_trace_gh_hcall_vcpu_run, perf_trace_gh_virtio_backend_irq_inj, perf_trace_gh_susp_res_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run2 @ 00114190 size=1
// signature: undefined bpf_trace_run2(void)
// callers: [__bpf_trace_gh_vcpu_irq_handler, __bpf_trace_gh_virtio_backend_queue_notify, __bpf_trace_gh_virtio_backend_irq_inj]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run5 @ 00114198 size=1
// signature: undefined bpf_trace_run5(void)
// callers: [__bpf_trace_gh_virtio_backend_wait_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run5(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run4 @ 001141a0 size=1
// signature: undefined bpf_trace_run4(void)
// callers: [__bpf_trace_gh_virtio_backend_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 001141a8 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [gh_vm_ioctl_set_fw_name, gh_secure_vm_loader_probe, gh_virtio_backend_ioctl, gh_virtio_backend_remove, gh_virtio_backend_mmap, gh_parse_virtio_properties, gh_virtio_mmio_init, gh_secure_vm_loader_reclaim_fw, vb_dev_put, vb_dev_get, gh_secure_vm_loader_remove, gh_virtio_mmio_exit, gh_vcpu_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001141b0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [gh_vm_ioctl_set_fw_name, gh_secure_vm_loader_probe, gh_virtio_mmio_exit, gh_virtio_backend_ioctl, gh_virtio_backend_remove, gh_virtio_backend_mmap, gh_parse_virtio_properties, gh_virtio_mmio_init, gh_secure_vm_loader_reclaim_fw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 001141b8 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [gh_vm_ioctl_set_fw_name, gh_secure_vm_loader_probe, gh_virtio_backend_ioctl, gh_virtio_backend_remove, gh_virtio_backend_mmap, gh_parse_virtio_properties, gh_virtio_mmio_init, gh_secure_vm_loader_reclaim_fw, vb_dev_put, vb_dev_get, gh_secure_vm_loader_remove, gh_virtio_mmio_exit, gh_vcpu_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 001141c8 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [gh_vm_ioctl_set_fw_name, gh_virtio_backend_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __dynamic_dev_dbg @ 001141d0 size=1
// signature: undefined __dynamic_dev_dbg(void)
// callers: [gh_parse_virtio_properties, gh_virtio_mmio_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __dynamic_dev_dbg(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 001141d8 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [vb_dev_ioeventfd, vb_dev_irqfd, gh_virtio_mmio_exit, gh_virtio_backend_ioctl, irqfd_shutdown, vdev_interrupt, gh_virtio_mmio_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001141e0 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [vb_dev_ioeventfd, vb_dev_irqfd, gh_virtio_mmio_exit, gh_virtio_backend_ioctl, irqfd_shutdown, vdev_interrupt, gh_virtio_mmio_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 00114200 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [gh_virtio_backend_ioctl, gh_vm_ioctl_get_fw_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00114208 size=1
// signature: undefined __check_object_size(void)
// callers: [gh_virtio_backend_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00114210 size=1
// signature: undefined _dev_err(void)
// callers: [gh_vm_ioctl_set_fw_name, gh_secure_vm_loader_probe, gh_virtio_backend_ioctl, gh_virtio_backend_mmap, gh_parse_virtio_properties, gh_virtio_mmio_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __get_free_pages @ 00114218 size=1
// signature: undefined __get_free_pages(void)
// callers: [gh_virtio_backend_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __get_free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00114220 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [gh_virtio_backend_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_pages @ 00114228 size=1
// signature: undefined free_pages(void)
// callers: [gh_virtio_mmio_exit, gh_virtio_backend_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// eventfd_ctx_fdget @ 00114238 size=1
// signature: undefined eventfd_ctx_fdget(void)
// callers: [vb_dev_ioeventfd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void eventfd_ctx_fdget(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __fdget @ 00114240 size=1
// signature: undefined __fdget(void)
// callers: [vb_dev_irqfd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __fdget(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// eventfd_ctx_fileget @ 00114248 size=1
// signature: undefined eventfd_ctx_fileget(void)
// callers: [vb_dev_irqfd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void eventfd_ctx_fileget(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fput @ 00114250 size=1
// signature: undefined fput(void)
// callers: [vb_dev_irqfd, irqfd_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fput(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// eventfd_signal @ 00114258 size=1
// signature: undefined eventfd_signal(void)
// callers: [signal_vqs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void eventfd_signal(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00114260 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 00114268 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00114270 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 00114278 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_write @ 00114280 size=1
// signature: undefined down_write(void)
// callers: [gh_virtio_backend_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_write @ 00114288 size=1
// signature: undefined up_write(void)
// callers: [gh_virtio_backend_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// remap_pfn_range @ 00114290 size=1
// signature: undefined remap_pfn_range(void)
// callers: [gh_virtio_backend_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void remap_pfn_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00114298 size=1
// signature: undefined of_find_property(void)
// callers: [gh_secure_vm_loader_probe, gh_parse_virtio_properties]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 001142a0 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [gh_secure_vm_loader_probe, gh_parse_virtio_properties]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 001142a8 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [gh_vm_ioctl_set_fw_name, gh_parse_virtio_properties, gh_virtio_mmio_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001142b0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [gh_secure_vm_loader_probe, gh_parse_virtio_properties]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 001142b8 size=1
// signature: undefined devm_kmalloc(void)
// callers: [gh_secure_vm_loader_probe, gh_parse_virtio_properties]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 001142c0 size=1
// signature: undefined strscpy(void)
// callers: [gh_populate_all_res_info, gh_parse_virtio_properties, gh_populate_vm_vcpu_info, gh_proxy_sched_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 001142c8 size=1
// signature: undefined of_address_to_resource(void)
// callers: [gh_secure_vm_loader_probe, gh_parse_virtio_properties]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_initialize @ 001142d0 size=1
// signature: undefined device_initialize(void)
// callers: [gh_parse_virtio_properties]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_initialize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 001142d8 size=1
// signature: undefined dev_set_name(void)
// callers: [gh_parse_virtio_properties]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_dma_configure_id @ 001142e0 size=1
// signature: undefined of_dma_configure_id(void)
// callers: [gh_parse_virtio_properties]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_dma_configure_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_add @ 001142e8 size=1
// signature: undefined device_add(void)
// callers: [gh_parse_virtio_properties]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_device_init_by_idx @ 001142f0 size=1
// signature: undefined of_reserved_mem_device_init_by_idx(void)
// callers: [gh_secure_vm_loader_probe, gh_parse_virtio_properties]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_device_init_by_idx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001142f8 size=1
// signature: undefined _dev_info(void)
// callers: [gh_secure_vm_loader_probe, gh_parse_virtio_properties]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00114300 size=1
// signature: undefined __list_add_valid(void)
// callers: [gh_secure_vm_loader_probe, gh_parse_virtio_properties]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_del @ 00114308 size=1
// signature: undefined device_del(void)
// callers: [gh_parse_virtio_properties]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 00114310 size=1
// signature: undefined put_device(void)
// callers: [gh_parse_virtio_properties]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00114318 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [gh_secure_vm_loader_remove, gh_virtio_backend_remove, gh_parse_virtio_properties]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00114320 size=1
// signature: undefined fortify_panic(void)
// callers: [gh_vm_ioctl_set_fw_name, gh_parse_virtio_properties, gh_virtio_mmio_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_irq @ 00114330 size=1
// signature: undefined free_irq(void)
// callers: [gh_virtio_mmio_exit, gh_unpopulate_vm_vcpu_info, gh_unpopulate_vm_vpm_grp_info, gh_populate_vm_vcpu_info, gh_virtio_mmio_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 00114338 size=1
// signature: undefined iounmap(void)
// callers: [gh_virtio_mmio_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_get_vmid @ 00114340 size=1
// signature: undefined ghd_rm_get_vmid(void)
// callers: [gh_populate_all_res_info, gh_unpopulate_vm_vcpu_info, unshare_vm_buffers, gh_wdog_manage, gh_unpopulate_vm_vpm_grp_info, gh_populate_vm_vcpu_info, gh_virtio_mmio_init, gh_populate_vm_vpm_grp_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_get_vmid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 00114348 size=1
// signature: undefined dma_free_attrs(void)
// callers: [gh_vm_ioctl_set_fw_name, unshare_vm_buffers, gh_virtio_mmio_init, gh_secure_vm_loader_reclaim_fw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_set_virtio_mmio_cb @ 00114350 size=1
// signature: undefined gh_rm_set_virtio_mmio_cb(void)
// callers: [gh_virtio_backend_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_set_virtio_mmio_cb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_threaded_irq @ 00114358 size=1
// signature: undefined request_threaded_irq(void)
// callers: [gh_populate_vm_vcpu_info, gh_virtio_mmio_init, gh_populate_vm_vpm_grp_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ioremap_prot @ 00114368 size=1
// signature: undefined ioremap_prot(void)
// callers: [gh_virtio_mmio_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ioremap_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 00114370 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [gh_vm_ioctl_set_fw_name, gh_virtio_mmio_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_mem_share @ 00114378 size=1
// signature: undefined ghd_rm_mem_share(void)
// callers: [gh_virtio_mmio_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_mem_share(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_unset_virtio_mmio_cb @ 00114380 size=1
// signature: undefined gh_rm_unset_virtio_mmio_cb(void)
// callers: [gh_virtio_backend_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_unset_virtio_mmio_cb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_raw_output_prep @ 00114388 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_gh_vcpu_irq_handler, trace_raw_output_gh_virtio_backend_irq_inj, trace_raw_output_gh_virtio_backend_irq, trace_raw_output_gh_virtio_backend_wait_event, trace_raw_output_gh_susp_res_irq_handler, trace_raw_output_gh_virtio_backend_queue_notify, trace_raw_output_gh_hcall_vcpu_run]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 00114390 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_gh_vcpu_irq_handler, trace_raw_output_gh_virtio_backend_irq_inj, trace_raw_output_gh_virtio_backend_irq, trace_raw_output_gh_virtio_backend_wait_event, trace_raw_output_gh_susp_res_irq_handler, trace_raw_output_gh_virtio_backend_queue_notify, trace_raw_output_gh_hcall_vcpu_run]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 00114398 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_gh_vcpu_irq_handler, trace_raw_output_gh_virtio_backend_irq_inj, trace_raw_output_gh_virtio_backend_irq, trace_raw_output_gh_virtio_backend_wait_event, trace_raw_output_gh_susp_res_irq_handler, trace_raw_output_gh_virtio_backend_queue_notify, trace_raw_output_gh_hcall_vcpu_run]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001143a8 size=1
// signature: undefined queue_work_on(void)
// callers: [gh_vcpu_create_wq, gh_vcpu_irq_handler, vb_dev_irqfd_wakeup, gh_vcpu_pm_notifier_call]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// eventfd_ctx_remove_wait_queue @ 001143b0 size=1
// signature: undefined eventfd_ctx_remove_wait_queue(void)
// callers: [irqfd_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void eventfd_ctx_remove_wait_queue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// eventfd_ctx_put @ 001143b8 size=1
// signature: undefined eventfd_ctx_put(void)
// callers: [irqfd_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void eventfd_ctx_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// add_wait_queue @ 001143c0 size=1
// signature: undefined add_wait_queue(void)
// callers: [vb_dev_irqfd_ptable_queue_proc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void add_wait_queue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_device_release @ 001143c8 size=1
// signature: undefined of_reserved_mem_device_release(void)
// callers: [gh_memdev_release, gh_secure_vm_loader_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_device_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_vm_alloc_vmid @ 001143e0 size=1
// signature: undefined gh_rm_vm_alloc_vmid(void)
// callers: [gh_vm_ioctl_set_fw_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_vm_alloc_vmid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 001143e8 size=1
// signature: undefined scnprintf(void)
// callers: [gh_vm_ioctl_set_fw_name, gh_vm_ioctl_get_fw_name, gh_get_vcpu_prop_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_firmware @ 001143f0 size=1
// signature: undefined request_firmware(void)
// callers: [gh_vm_ioctl_set_fw_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_mdt_read_metadata @ 001143f8 size=1
// signature: undefined qcom_mdt_read_metadata(void)
// callers: [gh_vm_ioctl_set_fw_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_mdt_read_metadata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// release_firmware @ 00114400 size=1
// signature: undefined release_firmware(void)
// callers: [gh_vm_ioctl_set_fw_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void release_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00114408 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [gh_vm_ioctl_set_fw_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_mdt_load_no_init @ 00114410 size=1
// signature: undefined qcom_mdt_load_no_init(void)
// callers: [gh_vm_ioctl_set_fw_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_mdt_load_no_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00114418 size=1
// signature: undefined __platform_driver_register(void)
// callers: [gh_secure_vm_loader_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __platform_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 00114420 size=1
// signature: undefined platform_driver_unregister(void)
// callers: [gh_secure_vm_loader_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memremap @ 00114428 size=1
// signature: undefined memremap(void)
// callers: [gh_secure_vm_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void memremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 00114430 size=1
// signature: undefined dma_set_mask(void)
// callers: [gh_secure_vm_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 00114438 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [gh_secure_vm_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_lookup @ 00114440 size=1
// signature: undefined of_reserved_mem_lookup(void)
// callers: [gh_secure_vm_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00114448 size=1
// signature: undefined of_property_read_string(void)
// callers: [gh_secure_vm_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memunmap @ 00114450 size=1
// signature: undefined memunmap(void)
// callers: [gh_secure_vm_loader_probe, gh_secure_vm_loader_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void memunmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run6 @ 00114458 size=1
// signature: undefined bpf_trace_run6(void)
// callers: [__bpf_trace_gh_hcall_vcpu_run]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run6(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run1 @ 00114460 size=1
// signature: undefined bpf_trace_run1(void)
// callers: [__bpf_trace_gh_susp_res_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 00114468 size=1
// signature: undefined ktime_get(void)
// callers: [gh_poll_vcpu_run, gh_vcpu_run, gh_vcpu_work_function]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk_deferred @ 00114470 size=1
// signature: undefined _printk_deferred(void)
// callers: [gh_poll_vcpu_run]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk_deferred(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_stay_awake @ 00114478 size=1
// signature: undefined __pm_stay_awake(void)
// callers: [gh_vcpu_run, gh_vcpu_work_function]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_relax @ 00114480 size=1
// signature: undefined __pm_relax(void)
// callers: [gh_vcpu_run]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule @ 00114488 size=1
// signature: undefined preempt_schedule(void)
// callers: [gh_vcpu_run, gh_vcpu_work_function]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_pm_notifier @ 00114490 size=1
// signature: undefined register_pm_notifier(void)
// callers: [gh_vcpu_create_wq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00114498 size=1
// signature: undefined ___ratelimit(void)
// callers: [gh_vcpu_run]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_large @ 001144a0 size=1
// signature: undefined kmalloc_large(void)
// callers: [gh_proxy_sched_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_large(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_set_wdog_manage_cb @ 001144a8 size=1
// signature: undefined gh_rm_set_wdog_manage_cb(void)
// callers: [gh_proxy_sched_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_set_wdog_manage_cb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_set_vcpu_affinity_cb @ 001144b0 size=1
// signature: undefined gh_rm_set_vcpu_affinity_cb(void)
// callers: [gh_proxy_sched_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_set_vcpu_affinity_cb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_reset_vcpu_affinity_cb @ 001144b8 size=1
// signature: undefined gh_rm_reset_vcpu_affinity_cb(void)
// callers: [gh_proxy_sched_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_reset_vcpu_affinity_cb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_set_vpm_grp_cb @ 001144c0 size=1
// signature: undefined gh_rm_set_vpm_grp_cb(void)
// callers: [gh_proxy_sched_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_set_vpm_grp_cb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_reset_vpm_grp_cb @ 001144c8 size=1
// signature: undefined gh_rm_reset_vpm_grp_cb(void)
// callers: [gh_proxy_sched_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_reset_vpm_grp_cb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_all_res_populated_cb @ 001144d0 size=1
// signature: undefined gh_rm_all_res_populated_cb(void)
// callers: [gh_proxy_sched_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_all_res_populated_cb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 001144d8 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [gh_populate_vm_vcpu_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_register @ 001144e0 size=1
// signature: undefined wakeup_source_register(void)
// callers: [gh_populate_vm_vcpu_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 001144e8 size=1
// signature: undefined destroy_workqueue(void)
// callers: [gh_unpopulate_vm_vcpu_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_unregister @ 001144f0 size=1
// signature: undefined wakeup_source_unregister(void)
// callers: [gh_unpopulate_vm_vcpu_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_pm_notifier @ 001144f8 size=1
// signature: undefined unregister_pm_notifier(void)
// callers: [gh_unpopulate_vm_vcpu_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00114500 size=1
// signature: undefined alloc_workqueue(void)
// callers: [gh_populate_all_res_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlcat @ 00114508 size=1
// signature: undefined strlcat(void)
// callers: [gh_get_vcpu_prop_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcat(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



