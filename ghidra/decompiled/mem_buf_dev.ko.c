// Decompiled by Ghidra 12.2
// Program: mem_buf_dev.ko
// Image base: 00100000

//------------------------------------------------------------
// mem_buf_hyp_assign_table @ 00101c6c size=188
// signature: undefined mem_buf_hyp_assign_table(void)
// callers: [mem_buf_map_mem_s2]
//------------------------------------------------------------

int mem_buf_hyp_assign_table
              (undefined8 param_1,int *param_2,undefined4 param_3,undefined8 param_4,
              undefined8 param_5,undefined4 param_6)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  
  uVar5 = mem_buf_vm_uses_hyp_assign();
  iVar3 = current_vmid;
  if ((uVar5 & 1) == 0) {
    iVar4 = 0;
  }
  else {
    iVar2 = *param_2;
    iVar4 = hyp_assign_table(param_1,param_2,param_3,param_4,param_5,param_6);
    if (iVar4 < 0) {
      pcVar1 = "Assign";
      if (iVar2 != iVar3) {
        pcVar1 = "Unassign";
      }
      _printk(&DAT_00108825,pcVar1,iVar4);
    }
  }
  return iVar4;
}



//------------------------------------------------------------
// mem_buf_assign_mem @ 00101d2c size=424
// signature: undefined mem_buf_assign_mem(void)
// callers: [mem_buf_lend_internal]
//------------------------------------------------------------

int mem_buf_assign_mem(undefined4 param_1,long param_2,int *param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  int *piVar7;
  long lVar8;
  long lVar9;
  undefined4 local_70;
  int iStack_6c;
  long local_68;
  
  iVar5 = current_vmid;
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  local_70 = 7;
  iStack_6c = current_vmid;
  if ((((param_2 == 0) || (iVar4 = *param_3, iVar4 == 0)) ||
      (lVar8 = *(long *)(param_3 + 2), lVar8 == 0)) || (lVar9 = *(long *)(param_3 + 4), lVar9 == 0))
  {
    iVar4 = -0x16;
    goto LAB_00101e68;
  }
  param_3[6] = -1;
  uVar6 = mem_buf_vm_uses_hyp_assign();
  iVar3 = current_vmid;
  if ((uVar6 & 1) != 0) {
    iVar4 = hyp_assign_table(param_2,&iStack_6c,1,lVar8,lVar9,iVar4);
    if (iVar4 < 0) {
      pcVar1 = "Assign";
      if (iVar5 != iVar3) {
        pcVar1 = "Unassign";
      }
      _printk(&DAT_00108825,pcVar1,iVar4);
      goto LAB_00101e68;
    }
    if (iVar4 != 0) goto LAB_00101e68;
  }
  iVar4 = mem_buf_assign_mem_gunyah(param_1,param_2,param_3);
  if (iVar4 != 0) {
    piVar7 = *(int **)(param_3 + 2);
    iVar5 = *param_3;
    uVar6 = mem_buf_vm_uses_hyp_assign();
    iVar3 = current_vmid;
    if ((uVar6 & 1) != 0) {
      iVar2 = *piVar7;
      iVar5 = hyp_assign_table(param_2,piVar7,iVar5,&iStack_6c,&local_70,1);
      if (iVar5 < 0) {
        pcVar1 = "Assign";
        if (iVar2 != iVar3) {
          pcVar1 = "Unassign";
        }
        _printk(&DAT_00108825,pcVar1,iVar5);
        _printk(&DAT_0010860e,iVar5);
        iVar4 = -99;
      }
    }
  }
LAB_00101e68:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// mem_buf_unassign_mem @ 00101ed8 size=264
// signature: undefined mem_buf_unassign_mem(void)
// callers: [__mem_buf_vmperm_reclaim]
//------------------------------------------------------------

int mem_buf_unassign_mem(long param_1,int *param_2,int param_3,int param_4)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  undefined4 local_50;
  int iStack_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  iVar5 = -0x16;
  local_50 = 7;
  iStack_4c = current_vmid;
  if (((param_1 != 0) && (param_2 != (int *)0x0)) && (param_3 != 0)) {
    if (param_4 != -1) {
      iVar5 = mem_buf_unassign_mem_gunyah(param_4);
      if (iVar5 != 0) goto LAB_00101fa8;
    }
    uVar6 = mem_buf_vm_uses_hyp_assign();
    iVar4 = current_vmid;
    if ((uVar6 & 1) == 0) {
      iVar5 = 0;
    }
    else {
      iVar2 = *param_2;
      iVar5 = hyp_assign_table(param_1,param_2,param_3,&iStack_4c,&local_50,1);
      if (iVar5 < 0) {
        pcVar1 = "Assign";
        if (iVar2 != iVar4) {
          pcVar1 = "Unassign";
        }
        _printk(&DAT_00108825,pcVar1,iVar5);
      }
    }
  }
LAB_00101fa8:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// mem_buf_probe @ 00101fe4 size=400
// signature: undefined mem_buf_probe(void)
// callers: []
//------------------------------------------------------------

int mem_buf_probe(long param_1)

{
  long lVar1;
  int iVar2;
  char extraout_var;
  long lVar3;
  char *pcVar4;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  lVar1 = param_1 + 0x10;
  local_3c = 0;
  iVar2 = mem_buf_dma_buf_init();
  if (iVar2 == 0) {
    iVar2 = of_property_match_string
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,mem-buf-capabilities","supplier");
    if (iVar2 < 0) {
      iVar2 = of_property_match_string
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,mem-buf-capabilities","consumer");
      if (iVar2 < 0) {
        of_property_match_string
                  (*(undefined8 *)(param_1 + 0x2f8),"qcom,mem-buf-capabilities",&DAT_00108404);
        mem_buf_capability = (extraout_var >> 7 ^ 0xffU) & 3;
      }
      else {
        mem_buf_capability = 2;
      }
    }
    else {
      mem_buf_capability = 1;
    }
    iVar2 = dma_set_mask(lVar1,0xffffffffffffffff);
    if (iVar2 == 0) {
      dma_set_coherent_mask(lVar1,0xffffffffffffffff);
      lVar3 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"memory-region",&local_3c);
      if ((lVar3 == 0) ||
         (iVar2 = of_reserved_mem_device_init_by_idx(lVar1,*(undefined8 *)(param_1 + 0x2f8),0),
         iVar2 == 0)) {
        iVar2 = mem_buf_vm_init(lVar1);
        if (iVar2 == 0) {
          mem_buf_dev = lVar1;
          goto LAB_00102108;
        }
        pcVar4 = "mem_buf_vm_init failed %d\n";
      }
      else {
        pcVar4 = "Failed to get memory-region property %d\n";
      }
    }
    else {
      pcVar4 = "Unable to set dma mask: %d\n";
    }
    _dev_err(lVar1,pcVar4,iVar2);
  }
  else {
    iVar2 = dev_err_probe(lVar1,iVar2,"mem_buf_dma_buf_init failed\n");
  }
LAB_00102108:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// mem_buf_remove @ 00102178 size=16
// signature: undefined mem_buf_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 mem_buf_remove(void)

{
  mem_buf_dev = 0;
  return 0;
}



//------------------------------------------------------------
// mem_buf_vmperm_alloc_accept @ 0010218c size=36
// signature: undefined mem_buf_vmperm_alloc_accept(void)
// callers: []
//------------------------------------------------------------

void mem_buf_vmperm_alloc_accept(undefined8 param_1)

{
  mem_buf_vmperm_alloc_flags(param_1,4);
  return;
}



//------------------------------------------------------------
// mem_buf_vmperm_alloc_flags @ 001021b0 size=632
// signature: undefined mem_buf_vmperm_alloc_flags(void)
// callers: [mem_buf_vmperm_alloc_staticvm, mem_buf_vmperm_alloc_accept, mem_buf_vmperm_alloc]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
mem_buf_vmperm_alloc_flags
          (long *param_1,undefined4 param_2,void *param_3,void *param_4,uint param_5,
          undefined8 param_6,undefined8 param_7,int param_8)

{
  undefined8 *puVar1;
  char cVar2;
  bool bVar3;
  size_t __n;
  undefined *puVar4;
  code *pcVar5;
  int iVar6;
  undefined8 *puVar7;
  long lVar8;
  uint *puVar9;
  ulong uVar10;
  undefined8 uVar11;
  uint uVar12;
  
  puVar7 = (undefined8 *)kmalloc_trace(___mutex_init,0xdc0,0xb8);
  if (puVar7 != (undefined8 *)0x0) {
    puVar1 = puVar7 + 0xb;
    __mutex_init(puVar1,"&vmperm->lock",&mem_buf_vmperm_alloc_flags___key);
    mutex_lock(puVar1);
    iVar6 = mem_buf_vmperm_resize(puVar7,(ulong)param_5);
    if (iVar6 == 0) {
      __n = (ulong)param_5 << 2;
      if (*(uint *)((long)puVar7 + 0x34) < param_5) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x102408);
        (*pcVar5)();
      }
      memcpy((void *)puVar7[4],param_3,__n);
      memcpy((void *)puVar7[5],param_4,__n);
      *(uint *)(puVar7 + 6) = param_5;
      *(undefined4 *)((long)puVar7 + 0x14) = 0;
      iVar6 = current_vmid;
      if (param_5 != 0) {
        uVar12 = 0;
        do {
          if (*(int *)((long)param_3 + (long)(int)uVar12 * 4) == iVar6) {
            *(undefined4 *)((long)puVar7 + 0x14) =
                 *(undefined4 *)((long)param_4 + (long)(int)uVar12 * 4);
          }
          uVar12 = uVar12 + 1;
        } while (param_5 != uVar12);
      }
      mutex_unlock(puVar1);
      iVar6 = *(int *)((long)param_1 + 0xc);
      puVar7[8] = param_1;
      if (iVar6 != 0) {
        uVar12 = 0;
        lVar8 = *param_1;
        do {
          uVar12 = uVar12 + 1;
          puVar7[9] = puVar7[9] + (ulong)*(uint *)(lVar8 + 0xc);
          lVar8 = sg_next();
        } while (uVar12 < *(uint *)((long)param_1 + 0xc));
      }
      *(undefined4 *)(puVar7 + 2) = param_2;
      *(int *)(puVar7 + 10) = param_8;
      puVar7[0x13] = param_6;
      puVar7[0x14] = param_7;
      if (param_8 == -1) {
LAB_001023bc:
        mutex_lock(&vmperm_list_lock);
        puVar4 = vmperm_list;
        uVar10 = __list_add_valid(puVar7,&vmperm_list,vmperm_list);
        if ((uVar10 & 1) != 0) {
          *puVar7 = puVar4;
          puVar7[1] = &vmperm_list;
          vmperm_list = (undefined *)puVar7;
          *(undefined8 **)(puVar4 + 8) = puVar7;
        }
        mutex_unlock(&vmperm_list_lock);
        return puVar7;
      }
      _raw_spin_lock(vmperm_xa);
      iVar6 = __xa_insert(vmperm_xa,param_8,puVar7,0xcc0);
      _raw_spin_unlock(vmperm_xa);
      if (iVar6 == 0) {
        puVar9 = (uint *)puVar7[0x14];
        Hint_Prefetch(puVar9,2,0,1);
        do {
          uVar12 = *puVar9;
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar9,0x10);
          if (bVar3) {
            *puVar9 = uVar12 + 1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        if (uVar12 == 0) {
          uVar11 = 2;
        }
        else {
          if (-1 < (int)(uVar12 + 1 | uVar12)) goto LAB_001023bc;
          uVar11 = 1;
        }
        refcount_warn_saturate(puVar9,uVar11);
        goto LAB_001023bc;
      }
      kfree(puVar7[5]);
      kfree(puVar7[4]);
    }
    else {
      mutex_unlock(puVar1);
    }
    kfree(puVar7);
  }
  return (undefined8 *)0xfffffffffffffff4;
}



//------------------------------------------------------------
// mem_buf_vmperm_alloc_staticvm @ 0010243c size=56
// signature: undefined mem_buf_vmperm_alloc_staticvm(void)
// callers: []
//------------------------------------------------------------

void mem_buf_vmperm_alloc_staticvm
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 param_5,undefined8 param_6)

{
  mem_buf_vmperm_alloc_flags(param_1,1,param_2,param_3,param_4,param_5,param_6,0xffffffff);
  return;
}



//------------------------------------------------------------
// mem_buf_vmperm_alloc @ 00102478 size=116
// signature: undefined mem_buf_vmperm_alloc(void)
// callers: []
//------------------------------------------------------------

void mem_buf_vmperm_alloc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined4 local_20;
  undefined4 uStack_1c;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_20 = 7;
  uStack_1c = current_vmid;
  mem_buf_vmperm_alloc_flags(param_1,0,&uStack_1c,&local_20,1,param_2,param_3,0xffffffff);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mem_buf_vmperm_free @ 001024f0 size=132
// signature: undefined mem_buf_vmperm_free(void)
// callers: []
//------------------------------------------------------------

void mem_buf_vmperm_free(long *param_1)

{
  long lVar1;
  long *plVar2;
  code *pcVar3;
  ulong uVar4;
  
  if ((*(uint *)(param_1 + 2) >> 1 & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x102570);
    (*pcVar3)();
  }
  if ((*(uint *)(param_1 + 2) >> 2 & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x10257c);
    (*pcVar3)();
  }
  mutex_lock(&vmperm_list_lock);
  uVar4 = __list_del_entry_valid(param_1);
  if ((uVar4 & 1) != 0) {
    lVar1 = *param_1;
    plVar2 = (long *)param_1[1];
    *(long **)(lVar1 + 8) = plVar2;
    *plVar2 = lVar1;
  }
  param_1[1] = -0x2152fffffffffede;
  mutex_unlock(&vmperm_list_lock);
  call_rcu(param_1 + 0x15,vmperm_rcu_cb);
  return;
}



//------------------------------------------------------------
// vmperm_rcu_cb @ 00102584 size=64
// signature: undefined vmperm_rcu_cb(void)
// callers: []
//------------------------------------------------------------

void vmperm_rcu_cb(long param_1)

{
  kfree(*(undefined8 *)(param_1 + -0x80));
  kfree(*(undefined8 *)(param_1 + -0x88));
  kfree(param_1 + -0xa8);
  return;
}



//------------------------------------------------------------
// mem_buf_vmperm_try_reclaim @ 001025c8 size=488
// signature: undefined mem_buf_vmperm_try_reclaim(void)
// callers: [mem_buf_lend_internal, mem_buf_vmperm_gh_notifier]
//------------------------------------------------------------

ulong mem_buf_vmperm_try_reclaim(long param_1,ulong param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  code *pcVar7;
  ulong uVar8;
  
  mutex_lock(param_1 + 0x58);
  if (((param_2 & 1) != 0) && ((*(byte *)(param_1 + 0x10) >> 4 & 1) == 0)) {
LAB_001025fc:
    uVar8 = 0;
    goto LAB_001026b4;
  }
  pcVar7 = *(code **)(param_1 + 0x88);
  if (pcVar7 == (code *)0x0) {
    uVar8 = 0;
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x102628);
      (*pcVar7)();
    }
    uVar5 = (*pcVar7)(*(undefined8 *)(param_1 + 0x90));
    uVar8 = uVar5 & 0xffffffff;
    *(undefined8 *)(param_1 + 0x88) = 0;
    if (((int)uVar5 != 0) &&
       (iVar4 = ___ratelimit(mem_buf_vmperm_try_reclaim__rs,"mem_buf_vmperm_try_reclaim"),
       iVar4 != 0)) {
      _printk(&DAT_00108017,*(undefined8 *)(param_1 + 0x88),*(undefined4 *)(param_1 + 0x50),uVar8);
    }
  }
  if ((*(uint *)(param_1 + 0x10) >> 1 & 1) == 0) {
    if ((*(uint *)(param_1 + 0x10) >> 2 & 1) == 0) goto LAB_001026a4;
    uVar5 = mem_buf_sgt_to_gh_sgl_desc(*(undefined8 *)(param_1 + 0x40));
    if (0xfffffffffffff000 < uVar5) {
      uVar8 = uVar5 & 0xffffffff;
      goto LAB_001026a4;
    }
    uVar6 = mem_buf_unmap_mem_s1(uVar5);
    uVar8 = uVar6 & 0xffffffff;
    kvfree(uVar5);
    if ((int)uVar6 == 0) {
      uVar5 = mem_buf_unmap_mem_s2(*(undefined4 *)(param_1 + 0x50));
      uVar8 = uVar5 & 0xffffffff;
      if ((int)uVar5 == 0) {
        iVar4 = gh_rm_mem_notify(*(undefined4 *)(param_1 + 0x50),2,0x3a,0);
        if (iVar4 != 0) {
          _printk(&DAT_00108296,"mem_buf_vmperm_relinquish");
        }
        xa_erase(vmperm_xa,*(undefined4 *)(param_1 + 0x50));
        *(undefined4 *)(param_1 + 0x50) = 0xffffffff;
        pcVar7 = *(code **)(param_1 + 0x98);
        piVar1 = *(int **)(param_1 + 0xa0);
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffb;
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
          if (*(int *)(pcVar7 + -4) != -0x214e6a45) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x102768);
            (*pcVar7)();
          }
          (*pcVar7)();
        }
        else if (iVar4 < 1) {
          refcount_warn_saturate(piVar1,3);
        }
        goto LAB_001025fc;
      }
    }
  }
  else {
    uVar8 = __mem_buf_vmperm_reclaim(param_1);
    uVar8 = uVar8 & 0xffffffff;
LAB_001026a4:
    if ((int)uVar8 == 0) goto LAB_001026b4;
  }
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x10;
LAB_001026b4:
  mutex_unlock(param_1 + 0x58);
  return uVar8;
}



//------------------------------------------------------------
// __mem_buf_vmperm_reclaim @ 001027bc size=268
// signature: undefined __mem_buf_vmperm_reclaim(void)
// callers: [mem_buf_reclaim, mem_buf_vmperm_try_reclaim]
//------------------------------------------------------------

int __mem_buf_vmperm_reclaim(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar2 = current_vmid;
  iVar6 = mem_buf_unassign_mem
                    (*(undefined8 *)(param_1 + 0x40),*(undefined8 *)(param_1 + 0x20),
                     *(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x50));
  if (iVar6 == 0) {
    if (*(int *)(param_1 + 0x34) == 0) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x800,0x102888);
      (*pcVar5)();
    }
    **(int **)(param_1 + 0x20) = iVar2;
    **(undefined4 **)(param_1 + 0x28) = 7;
    uVar7 = 7;
    if (iVar2 != current_vmid) {
      uVar7 = 0;
    }
    *(undefined4 *)(param_1 + 0x30) = 1;
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffd;
    *(undefined4 *)(param_1 + 0x14) = uVar7;
    xa_erase(vmperm_xa,*(undefined4 *)(param_1 + 0x50));
    pcVar5 = *(code **)(param_1 + 0x98);
    piVar1 = *(int **)(param_1 + 0xa0);
    *(undefined4 *)(param_1 + 0x50) = 0xffffffff;
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
      if (*(int *)(pcVar5 + -4) != -0x214e6a45) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10287c);
        (*pcVar5)();
      }
      (*pcVar5)();
    }
    else if (iVar2 < 1) {
      refcount_warn_saturate(piVar1,3);
    }
  }
  return iVar6;
}



//------------------------------------------------------------
// mem_buf_dma_buf_attach @ 001028dc size=60
// signature: undefined mem_buf_dma_buf_attach(void)
// callers: []
//------------------------------------------------------------

void mem_buf_dma_buf_attach(long param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(long *)(param_1 + 0x20) + -8);
  if (*(int *)(pcVar1 + -4) != -0x68aaa802) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102908);
    (*pcVar1)();
  }
  (*pcVar1)();
  return;
}



//------------------------------------------------------------
// to_mem_buf_vmperm @ 0010291c size=88
// signature: undefined to_mem_buf_vmperm(void)
// callers: []
//------------------------------------------------------------

undefined8 to_mem_buf_vmperm(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  if (*(code **)(*(long *)(param_1 + 0x20) + 8) == mem_buf_dma_buf_attach) {
    pcVar2 = *(code **)(*(long *)(param_1 + 0x20) + -0x10);
    if (*(int *)(pcVar2 + -4) != -0x48d2931) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102964);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  else {
    uVar1 = 0xffffffffffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// mem_buf_dma_buf_set_destructor @ 00102978 size=156
// signature: undefined mem_buf_dma_buf_set_destructor(void)
// callers: []
//------------------------------------------------------------

ulong mem_buf_dma_buf_set_destructor(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  ulong uVar2;
  
  if (*(code **)(*(long *)(param_1 + 0x20) + 8) == mem_buf_dma_buf_attach) {
    pcVar1 = *(code **)(*(long *)(param_1 + 0x20) + -0x10);
    if (*(int *)(pcVar1 + -4) != -0x48d2931) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1029d0);
      (*pcVar1)();
    }
    uVar2 = (*pcVar1)();
    if (uVar2 < 0xfffffffffffff001) {
      mutex_lock(uVar2 + 0x58);
      *(undefined8 *)(uVar2 + 0x88) = param_2;
      *(undefined8 *)(uVar2 + 0x90) = param_3;
      mutex_unlock(uVar2 + 0x58);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xffffffffffffffea;
  }
  return uVar2 & 0xffffffff;
}



//------------------------------------------------------------
// mem_buf_dma_buf_export @ 00102a18 size=184
// signature: undefined mem_buf_dma_buf_export(void)
// callers: []
//------------------------------------------------------------

ulong mem_buf_dma_buf_export(long param_1,long param_2)

{
  code *pcVar1;
  ulong uVar2;
  ulong uVar3;
  
  if (*(code **)(param_2 + 0x18) != mem_buf_dma_buf_attach) {
    if (*(code **)(param_2 + 0x18) != (code *)0x0) {
      _printk(&DAT_00108bb9,*(undefined8 *)(param_1 + 0x10));
      return 0xffffffffffffffea;
    }
    *(code **)(param_2 + 0x18) = mem_buf_dma_buf_attach;
  }
  *(long *)(param_1 + 0x10) = param_2 + 0x10;
  uVar2 = dma_buf_export();
  if (0xfffffffffffff000 < uVar2) {
    return uVar2;
  }
  if (*(code **)(*(long *)(uVar2 + 0x20) + 8) == mem_buf_dma_buf_attach) {
    pcVar1 = *(code **)(*(long *)(uVar2 + 0x20) + -0x10);
    if (*(int *)(pcVar1 + -4) != -0x48d2931) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102aa0);
      (*pcVar1)();
    }
    uVar3 = (*pcVar1)(uVar2);
    if (uVar3 < 0xfffffffffffff001) {
      *(ulong *)(uVar3 + 0x38) = uVar2;
      return uVar2;
    }
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x800,0x102a74);
  (*pcVar1)();
}



//------------------------------------------------------------
// mem_buf_vmperm_pin @ 00102ae0 size=68
// signature: undefined mem_buf_vmperm_pin(void)
// callers: []
//------------------------------------------------------------

void mem_buf_vmperm_pin(long param_1)

{
  mutex_lock(param_1 + 0x58);
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  mutex_unlock(param_1 + 0x58);
  return;
}



//------------------------------------------------------------
// mem_buf_vmperm_unpin @ 00102b28 size=76
// signature: undefined mem_buf_vmperm_unpin(void)
// callers: []
//------------------------------------------------------------

void mem_buf_vmperm_unpin(long param_1)

{
  code *pcVar1;
  
  mutex_lock(param_1 + 0x58);
  if (*(int *)(param_1 + 0x18) == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x102b74);
    (*pcVar1)();
  }
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
  mutex_unlock(param_1 + 0x58);
  return;
}



//------------------------------------------------------------
// mem_buf_vmperm_can_cmo @ 00102b7c size=104
// signature: undefined mem_buf_vmperm_can_cmo(void)
// callers: []
//------------------------------------------------------------

bool mem_buf_vmperm_can_cmo(long param_1)

{
  bool bVar1;
  
  mutex_lock(param_1 + 0x58);
  if (((*(byte *)(param_1 + 0x10) >> 3 & 1) == 0) &&
     (((*(uint *)(param_1 + 0x14) ^ 0xffffffff) & 6) == 0)) {
    bVar1 = *(int *)(param_1 + 0x18) != 0;
  }
  else {
    bVar1 = false;
  }
  mutex_unlock(param_1 + 0x58);
  return bVar1;
}



//------------------------------------------------------------
// mem_buf_vmperm_can_vmap @ 00102be8 size=104
// signature: undefined mem_buf_vmperm_can_vmap(void)
// callers: []
//------------------------------------------------------------

bool mem_buf_vmperm_can_vmap(long param_1)

{
  bool bVar1;
  
  mutex_lock(param_1 + 0x58);
  if (((*(byte *)(param_1 + 0x10) >> 3 & 1) == 0) &&
     (((*(uint *)(param_1 + 0x14) ^ 0xffffffff) & 6) == 0)) {
    bVar1 = *(int *)(param_1 + 0x18) != 0;
  }
  else {
    bVar1 = false;
  }
  mutex_unlock(param_1 + 0x58);
  return bVar1;
}



//------------------------------------------------------------
// mem_buf_vmperm_can_mmap @ 00102c54 size=132
// signature: undefined mem_buf_vmperm_can_mmap(void)
// callers: []
//------------------------------------------------------------

undefined8 mem_buf_vmperm_can_mmap(long param_1,long param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  mutex_lock(param_1 + 0x58);
  if (((*(byte *)(param_1 + 0x10) >> 3 & 1) == 0) && (*(int *)(param_1 + 0x18) != 0)) {
    uVar1 = *(uint *)(param_1 + 0x14);
    if ((((uVar1 >> 2 & 1) != 0) &&
        (((uVar1 >> 1 & 1) != 0 || ((*(byte *)(param_2 + 0x20) >> 1 & 1) == 0)))) &&
       (((uVar1 & 1) != 0 || ((*(byte *)(param_2 + 0x20) >> 2 & 1) == 0)))) {
      uVar2 = 1;
      goto LAB_00102c98;
    }
  }
  uVar2 = 0;
LAB_00102c98:
  mutex_unlock(param_1 + 0x58);
  return uVar2;
}



//------------------------------------------------------------
// mem_buf_lend @ 00102cdc size=32
// signature: undefined mem_buf_lend(void)
// callers: []
//------------------------------------------------------------

void mem_buf_lend(undefined8 param_1,undefined8 param_2)

{
  mem_buf_lend_internal(param_1,param_2,1);
  return;
}



//------------------------------------------------------------
// mem_buf_lend_internal @ 00102cfc size=912
// signature: undefined mem_buf_lend_internal(void)
// callers: [mem_buf_lend, mem_buf_share]
//------------------------------------------------------------

int mem_buf_lend_internal(long param_1,uint *param_2,int param_3)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  undefined *puVar8;
  ulong uVar9;
  code *pcVar10;
  uint uVar11;
  
  if (*param_2 == 0) {
    return -0x16;
  }
  if (*(long *)(param_2 + 2) == 0) {
    return -0x16;
  }
  if (*(long *)(param_2 + 4) == 0) {
    return -0x16;
  }
  if (mem_buf_dev == 0) {
    _printk(&DAT_0010832c,"mem_buf_lend_internal");
    return -0x13;
  }
  if (*(code **)(*(long *)(param_1 + 0x20) + 8) != mem_buf_dma_buf_attach) {
LAB_00102d88:
    iVar5 = ___ratelimit(mem_buf_lend_internal__rs,"mem_buf_lend_internal");
    if (iVar5 != 0) {
      _printk(&DAT_0010872a,*(undefined8 *)(param_1 + 0x20));
    }
    return -0x16;
  }
  pcVar10 = *(code **)(*(long *)(param_1 + 0x20) + -0x10);
  if (*(int *)(pcVar10 + -4) != -0x48d2931) {
                    /* WARNING: Does not return */
    pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x102d7c);
    (*pcVar10)();
  }
  uVar7 = (*pcVar10)(param_1);
  if (0xfffffffffffff000 < uVar7) goto LAB_00102d88;
  uVar2 = *param_2;
  if (uVar2 == 0) {
LAB_00102e60:
    if (param_3 == 2) {
      iVar5 = ___ratelimit(validate_lend_vmids__rs_34,"validate_lend_vmids");
      if (iVar5 == 0) {
        return -0x16;
      }
      puVar8 = &DAT_00108c23;
LAB_00102e88:
      _printk(puVar8);
      return -0x16;
    }
  }
  else {
    if (**(int **)(param_2 + 2) == current_vmid) {
      bVar4 = true;
    }
    else {
      uVar3 = 1;
      do {
        uVar11 = uVar3;
        if (uVar2 == uVar11) goto LAB_00102e60;
        uVar3 = uVar11 + 1;
      } while ((*(int **)(param_2 + 2))[(int)uVar11] != current_vmid);
      bVar4 = uVar11 < uVar2;
    }
    if ((param_3 == 1) && (bVar4)) {
      iVar5 = ___ratelimit(validate_lend_vmids__rs,"validate_lend_vmids");
      if (iVar5 == 0) {
        return -0x16;
      }
      puVar8 = &DAT_0010846b;
      goto LAB_00102e88;
    }
  }
  lVar1 = uVar7 + 0x58;
  mutex_lock(lVar1);
  uVar2 = *(uint *)(uVar7 + 0x10);
  if ((uVar2 >> 3 & 1) == 0) {
    if ((uVar2 & 1) == 0) {
      if ((uVar2 >> 1 & 1) == 0) {
        if ((uVar2 >> 2 & 1) == 0) {
          uVar9 = validate_lend_mapcount(uVar7,param_2);
          if ((uVar9 & 1) != 0) {
            dma_map_sgtable(mem_buf_dev,*(undefined8 *)(uVar7 + 0x40),1,0);
            dma_unmap_sg_attrs(mem_buf_dev,**(undefined8 **)(uVar7 + 0x40),
                               *(undefined4 *)((long)*(undefined8 **)(uVar7 + 0x40) + 0xc),1,0);
            iVar5 = mem_buf_vmperm_resize(uVar7,*param_2);
            if (iVar5 == 0) {
              iVar5 = mem_buf_assign_mem(param_3,*(undefined8 *)(uVar7 + 0x40),param_2);
              if (iVar5 == 0) {
                mem_buf_vmperm_update_state
                          (uVar7,*(undefined8 *)(param_2 + 2),*(undefined8 *)(param_2 + 4),*param_2)
                ;
                *(uint *)(uVar7 + 0x10) = *(uint *)(uVar7 + 0x10) | 2;
                *(uint *)(uVar7 + 0x50) = param_2[6];
                kref_get(*(undefined8 *)(uVar7 + 0xa0));
                mutex_unlock(lVar1);
                if (*(int *)(uVar7 + 0x50) == -1) {
                  return 0;
                }
                iVar5 = xa_insert(*(int *)(uVar7 + 0x50),uVar7);
                if (iVar5 == 0) {
                  mem_buf_lend_notify(uVar7);
                  return 0;
                }
                iVar6 = ___ratelimit(mem_buf_lend_internal__rs_31,"mem_buf_lend_internal");
                if (iVar6 != 0) {
                  _printk(&DAT_00108bee,*(undefined4 *)(uVar7 + 0x50));
                }
                mem_buf_vmperm_try_reclaim(uVar7,0);
                return iVar5;
              }
              if (iVar5 == -99) {
                mem_buf_vmperm_set_err(uVar7);
              }
            }
            mutex_unlock(lVar1);
            return iVar5;
          }
          goto LAB_00102fb4;
        }
        iVar5 = ___ratelimit(mem_buf_lend_internal__rs_30,"mem_buf_lend_internal");
        if (iVar5 == 0) goto LAB_00102fb4;
        puVar8 = &DAT_00108059;
      }
      else {
        iVar5 = ___ratelimit(mem_buf_lend_internal__rs_28,"mem_buf_lend_internal");
        if (iVar5 == 0) goto LAB_00102fb4;
        puVar8 = &DAT_0010808d;
      }
    }
    else {
      iVar5 = ___ratelimit(mem_buf_lend_internal__rs_27,"mem_buf_lend_internal");
      if (iVar5 == 0) goto LAB_00102fb4;
      puVar8 = &DAT_0010887f;
    }
  }
  else {
    iVar5 = ___ratelimit(mem_buf_lend_internal__rs_25,"mem_buf_lend_internal");
    if (iVar5 == 0) goto LAB_00102fb4;
    puVar8 = &DAT_00107f28;
  }
  _printk(puVar8);
LAB_00102fb4:
  mutex_unlock(lVar1);
  return -0x16;
}



//------------------------------------------------------------
// mem_buf_share @ 00103090 size=336
// signature: undefined mem_buf_share(void)
// callers: []
//------------------------------------------------------------

undefined4 mem_buf_share(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  void *__dest;
  void *__dest_00;
  int *piVar7;
  ulong uVar8;
  size_t __n;
  
  uVar4 = *param_2;
  uVar8 = (ulong)uVar4;
  if (0 < (int)uVar4) {
    piVar7 = *(int **)(param_2 + 2);
    do {
      if (*piVar7 == current_vmid) {
        uVar6 = mem_buf_lend_internal(param_1,param_2,2);
        return uVar6;
      }
      piVar7 = piVar7 + 1;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
  }
  uVar1 = uVar4 + 1;
  if (-1 < (int)uVar1) {
    uVar8 = -(ulong)(uVar1 >> 0x1f) & 0xfffffffc00000000 | (ulong)uVar1 << 2;
    __dest = (void *)__kmalloc(uVar8,0xcc0);
    if (__dest != (void *)0x0) {
      __dest_00 = (void *)__kmalloc(uVar8,0xcc0);
      if (__dest_00 != (void *)0x0) {
        __n = (long)(int)uVar4 * 4;
        memcpy(__dest,*(void **)(param_2 + 2),__n);
        memcpy(__dest_00,*(void **)(param_2 + 4),__n);
        iVar5 = current_vmid;
        uVar4 = *param_2;
        *(undefined4 *)((long)__dest_00 + __n) = 7;
        *(int *)((long)__dest + __n) = iVar5;
        uVar2 = *(undefined8 *)(param_2 + 2);
        uVar3 = *(undefined8 *)(param_2 + 4);
        *(void **)(param_2 + 2) = __dest;
        *(void **)(param_2 + 4) = __dest_00;
        *param_2 = uVar4 + 1;
        uVar6 = mem_buf_lend_internal(param_1,param_2,2);
        *(undefined8 *)(param_2 + 2) = uVar2;
        *(undefined8 *)(param_2 + 4) = uVar3;
        *param_2 = *param_2 - 1;
        kfree(__dest);
        kfree(__dest_00);
        return uVar6;
      }
      kfree(__dest);
    }
  }
  return 0xfffffff4;
}



//------------------------------------------------------------
// mem_buf_reclaim @ 001031e4 size=332
// signature: undefined mem_buf_reclaim(void)
// callers: []
//------------------------------------------------------------

undefined4 mem_buf_reclaim(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  ulong uVar5;
  undefined *puVar6;
  code *pcVar7;
  
  if (*(code **)(*(long *)(param_1 + 0x20) + 8) != mem_buf_dma_buf_attach) {
LAB_0010323c:
    iVar3 = ___ratelimit(mem_buf_reclaim__rs,"mem_buf_reclaim");
    if (iVar3 != 0) {
      _printk(&DAT_0010872a,*(undefined8 *)(param_1 + 0x20));
    }
    return 0xffffffea;
  }
  pcVar7 = *(code **)(*(long *)(param_1 + 0x20) + -0x10);
  if (*(int *)(pcVar7 + -4) != -0x48d2931) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x103230);
    (*pcVar7)();
  }
  uVar5 = (*pcVar7)(param_1);
  if (0xfffffffffffff000 < uVar5) goto LAB_0010323c;
  lVar1 = uVar5 + 0x58;
  mutex_lock(lVar1);
  uVar2 = *(uint *)(uVar5 + 0x10);
  if ((uVar2 & 1) == 0) {
    if ((uVar2 >> 1 & 1) == 0) {
      iVar3 = ___ratelimit(mem_buf_reclaim__rs_10,"mem_buf_reclaim");
      if (iVar3 == 0) goto LAB_00103324;
      puVar6 = &DAT_0010852a;
    }
    else {
      if ((uVar2 >> 2 & 1) == 0) {
        uVar4 = __mem_buf_vmperm_reclaim(uVar5);
        mutex_unlock(lVar1);
        return uVar4;
      }
      iVar3 = ___ratelimit(mem_buf_reclaim__rs_12,"mem_buf_reclaim");
      if (iVar3 == 0) goto LAB_00103324;
      puVar6 = &DAT_00108059;
    }
  }
  else {
    iVar3 = ___ratelimit(mem_buf_reclaim__rs_8,"mem_buf_reclaim");
    if (iVar3 == 0) goto LAB_00103324;
    puVar6 = &DAT_0010887f;
  }
  _printk(puVar6);
LAB_00103324:
  mutex_unlock(lVar1);
  return 0xffffffea;
}



//------------------------------------------------------------
// mem_buf_dma_buf_exclusive_owner @ 00103334 size=144
// signature: undefined mem_buf_dma_buf_exclusive_owner(void)
// callers: []
//------------------------------------------------------------

bool mem_buf_dma_buf_exclusive_owner(long param_1)

{
  uint uVar1;
  code *pcVar2;
  ulong uVar3;
  
  if (*(code **)(*(long *)(param_1 + 0x20) + 8) == mem_buf_dma_buf_attach) {
    pcVar2 = *(code **)(*(long *)(param_1 + 0x20) + -0x10);
    if (*(int *)(pcVar2 + -4) != -0x48d2931) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103384);
      (*pcVar2)();
    }
    uVar3 = (*pcVar2)();
    if (uVar3 < 0xfffffffffffff001) {
      mutex_lock(uVar3 + 0x58);
      uVar1 = *(uint *)(uVar3 + 0x10);
      mutex_unlock(uVar3 + 0x58);
      return (uVar1 & 7) == 0;
    }
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x800,0x103364);
  (*pcVar2)();
}



//------------------------------------------------------------
// mem_buf_dma_buf_get_vmperm @ 001033cc size=188
// signature: undefined mem_buf_dma_buf_get_vmperm(void)
// callers: []
//------------------------------------------------------------

ulong mem_buf_dma_buf_get_vmperm
                (long param_1,undefined8 *param_2,undefined8 *param_3,undefined4 *param_4)

{
  code *pcVar1;
  ulong uVar2;
  
  if (*(code **)(*(long *)(param_1 + 0x20) + 8) == mem_buf_dma_buf_attach) {
    pcVar1 = *(code **)(*(long *)(param_1 + 0x20) + -0x10);
    if (*(int *)(pcVar1 + -4) != -0x48d2931) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10342c);
      (*pcVar1)();
    }
    uVar2 = (*pcVar1)();
    if (uVar2 < 0xfffffffffffff001) {
      mutex_lock(uVar2 + 0x58);
      *param_2 = *(undefined8 *)(uVar2 + 0x20);
      *param_3 = *(undefined8 *)(uVar2 + 0x28);
      *param_4 = *(undefined4 *)(uVar2 + 0x30);
      mutex_unlock(uVar2 + 0x58);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xffffffffffffffea;
  }
  return uVar2 & 0xffffffff;
}



//------------------------------------------------------------
// mem_buf_dma_buf_copy_vmperm @ 0010348c size=264
// signature: undefined mem_buf_dma_buf_copy_vmperm(void)
// callers: []
//------------------------------------------------------------

ulong mem_buf_dma_buf_copy_vmperm(long param_1,long *param_2,long *param_3,undefined4 *param_4)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  ulong uVar4;
  long lVar5;
  
  if (*(code **)(*(long *)(param_1 + 0x20) + 8) == mem_buf_dma_buf_attach) {
    pcVar3 = *(code **)(*(long *)(param_1 + 0x20) + -0x10);
    if (*(int *)(pcVar3 + -4) != -0x48d2931) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1034f0);
      (*pcVar3)();
    }
    uVar4 = (*pcVar3)();
    if (uVar4 < 0xfffffffffffff001) {
      lVar1 = uVar4 + 0x58;
      mutex_lock(lVar1);
      lVar5 = (ulong)*(uint *)(uVar4 + 0x30) << 2;
      lVar2 = kmemdup(*(undefined8 *)(uVar4 + 0x20),lVar5,0xcc0);
      if (lVar2 != 0) {
        lVar5 = kmemdup(*(undefined8 *)(uVar4 + 0x28),lVar5,0xcc0);
        if (lVar5 != 0) {
          *param_2 = lVar2;
          *param_3 = lVar5;
          *param_4 = *(undefined4 *)(uVar4 + 0x30);
          mutex_unlock(lVar1);
          uVar4 = 0;
          goto LAB_00103574;
        }
        kfree(lVar2);
      }
      mutex_unlock(lVar1);
      uVar4 = 0xfffffff4;
    }
  }
  else {
    uVar4 = 0xffffffffffffffea;
  }
LAB_00103574:
  return uVar4 & 0xffffffff;
}



//------------------------------------------------------------
// mem_buf_dma_buf_get_memparcel_hdl @ 00103598 size=136
// signature: undefined mem_buf_dma_buf_get_memparcel_hdl(void)
// callers: []
//------------------------------------------------------------

ulong mem_buf_dma_buf_get_memparcel_hdl(long param_1,int *param_2)

{
  int *piVar1;
  ulong uVar2;
  code *pcVar3;
  
  if (*(code **)(*(long *)(param_1 + 0x20) + 8) == mem_buf_dma_buf_attach) {
    pcVar3 = *(code **)(*(long *)(param_1 + 0x20) + -0x10);
    if (*(int *)(pcVar3 + -4) != -0x48d2931) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1035e8);
      (*pcVar3)();
    }
    uVar2 = (*pcVar3)();
    if (uVar2 < 0xfffffffffffff001) {
      piVar1 = (int *)(uVar2 + 0x50);
      if (*piVar1 == -1) {
        uVar2 = 0xffffffea;
      }
      else {
        uVar2 = 0;
        *param_2 = *piVar1;
      }
    }
  }
  else {
    uVar2 = 0xffffffffffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// mem_buf_dma_buf_init @ 00103624 size=132
// signature: undefined mem_buf_dma_buf_init(void)
// callers: [mem_buf_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong mem_buf_dma_buf_init(void)

{
  _gh_rm_mem_notifier_cookie = gh_mem_notifier_register(0x3a,mem_buf_vmperm_gh_notifier,0);
  if (0xfffffffffffff000 < _gh_rm_mem_notifier_cookie) {
    _printk(&DAT_001087c3);
    if (gh_rm_mem_notifier_cookie != 0) {
      return _gh_rm_mem_notifier_cookie & 0xffffffff;
    }
  }
  debugfs_create_file("mem_buf_summary",0x100,mem_buf_debugfs_root,0,summary_fops);
  return 0;
}



//------------------------------------------------------------
// mem_buf_vmperm_resize @ 001036a8 size=228
// signature: undefined mem_buf_vmperm_resize(void)
// callers: [mem_buf_lend_internal, mem_buf_vmperm_alloc_flags]
//------------------------------------------------------------

undefined8 mem_buf_vmperm_resize(long param_1,uint param_2)

{
  void *__src;
  void *__src_00;
  uint uVar1;
  void *__dest;
  void *__dest_00;
  undefined8 uVar2;
  size_t __n;
  
  uVar1 = *(uint *)(param_1 + 0x34);
  if (uVar1 < param_2) {
    __src = *(void **)(param_1 + 0x20);
    __src_00 = *(void **)(param_1 + 0x28);
    __dest = (void *)__kmalloc((ulong)param_2 << 2,0xdc0);
    if (__dest != (void *)0x0) {
      __dest_00 = (void *)__kmalloc((ulong)param_2 << 2,0xdc0);
      if (__dest_00 != (void *)0x0) {
        __n = (ulong)uVar1 << 2;
        if (*(long *)(param_1 + 0x20) != 0) {
          memcpy(__dest,__src,__n);
          kfree(__src);
        }
        if (*(long *)(param_1 + 0x28) != 0) {
          memcpy(__dest_00,__src_00,__n);
          kfree(__src_00);
        }
        *(void **)(param_1 + 0x20) = __dest;
        *(void **)(param_1 + 0x28) = __dest_00;
        *(uint *)(param_1 + 0x34) = param_2;
        return 0;
      }
      kfree(__dest);
    }
    uVar2 = 0xfffffff4;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// mem_buf_vmperm_update_state @ 0010378c size=184
// signature: undefined mem_buf_vmperm_update_state(void)
// callers: [mem_buf_lend_internal]
//------------------------------------------------------------

void mem_buf_vmperm_update_state(long param_1,void *param_2,void *param_3,uint param_4)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  
  if (*(uint *)(param_1 + 0x34) < param_4) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x103844);
    (*pcVar2)();
  }
  memcpy(*(void **)(param_1 + 0x20),param_2,(ulong)param_4 << 2);
  memcpy(*(void **)(param_1 + 0x28),param_3,(ulong)param_4 << 2);
  *(uint *)(param_1 + 0x30) = param_4;
  *(undefined4 *)(param_1 + 0x14) = 0;
  iVar1 = current_vmid;
  if (param_4 != 0) {
    uVar3 = 0;
    do {
      if (*(int *)((long)param_2 + (long)(int)uVar3 * 4) == iVar1) {
        *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)((long)param_3 + (long)(int)uVar3 * 4);
      }
      uVar3 = uVar3 + 1;
    } while (param_4 != uVar3);
  }
  return;
}



//------------------------------------------------------------
// xa_insert @ 00103848 size=100
// signature: undefined xa_insert(void)
// callers: [mem_buf_lend_internal]
//------------------------------------------------------------

undefined4 xa_insert(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  
  _raw_spin_lock(vmperm_xa);
  uVar1 = __xa_insert(vmperm_xa,param_1,param_2,0xcc0);
  _raw_spin_unlock(vmperm_xa);
  return uVar1;
}



//------------------------------------------------------------
// kref_get @ 001038ac size=84
// signature: undefined kref_get(void)
// callers: [mem_buf_lend_internal]
//------------------------------------------------------------

void kref_get(uint *param_1)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  undefined8 uVar4;
  
  Hint_Prefetch(param_1,2,0,1);
  do {
    uVar1 = *param_1;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(param_1,0x10);
    if (bVar3) {
      *param_1 = uVar1 + 1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  if (uVar1 == 0) {
    uVar4 = 2;
  }
  else {
    if (-1 < (int)(uVar1 + 1 | uVar1)) {
      return;
    }
    uVar4 = 1;
  }
  refcount_warn_saturate(param_1,uVar4);
  return;
}



//------------------------------------------------------------
// validate_lend_mapcount @ 0010390c size=304
// signature: undefined validate_lend_mapcount(void)
// callers: [mem_buf_lend_internal]
//------------------------------------------------------------

undefined8 validate_lend_mapcount(long param_1,uint *param_2)

{
  int iVar1;
  undefined8 uVar2;
  ulong uVar3;
  uint uVar4;
  ulong uVar5;
  
  if (*(int *)(param_1 + 0x18) == 0) {
LAB_0010397c:
    uVar2 = 1;
  }
  else {
    if (*param_2 != 0) {
      uVar4 = 0;
      do {
        if ((*(int *)(*(long *)(param_2 + 2) + (long)(int)uVar4 * 4) == current_vmid) &&
           (((*(uint *)(*(long *)(param_2 + 4) + (long)(int)uVar4 * 4) ^ 0xffffffff) & 6) == 0))
        goto LAB_0010397c;
        uVar4 = uVar4 + 1;
      } while (*param_2 != uVar4);
    }
    iVar1 = ___ratelimit(validate_lend_mapcount__rs,"validate_lend_mapcount");
    if (iVar1 == 0) {
      uVar4 = *param_2;
    }
    else {
      _printk(&DAT_00108784,"validate_lend_mapcount");
      uVar4 = *param_2;
    }
    if (uVar4 != 0) {
      uVar5 = 0;
      do {
        iVar1 = ___ratelimit(validate_lend_mapcount__rs_37,"validate_lend_mapcount");
        if (iVar1 != 0) {
          uVar3 = -(uVar5 >> 0x1f) & 0xfffffffc00000000 | uVar5 << 2;
          _printk(&DAT_00108a60,"validate_lend_mapcount",
                  *(undefined4 *)(*(long *)(param_2 + 2) + uVar3),
                  *(undefined4 *)(*(long *)(param_2 + 4) + uVar3));
        }
        uVar4 = (int)uVar5 + 1;
        uVar5 = (ulong)uVar4;
      } while (uVar4 < *param_2);
    }
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// mem_buf_vmperm_set_err @ 00103a3c size=112
// signature: undefined mem_buf_vmperm_set_err(void)
// callers: [mem_buf_lend_internal]
//------------------------------------------------------------

void mem_buf_vmperm_set_err(long param_1)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  uint *puVar4;
  undefined8 uVar5;
  
  puVar4 = *(uint **)(param_1 + 0xa0);
  Hint_Prefetch(puVar4,2,0,1);
  do {
    uVar1 = *puVar4;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar4,0x10);
    if (bVar3) {
      *puVar4 = uVar1 + 1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  if (uVar1 == 0) {
    uVar5 = 2;
  }
  else {
    if (-1 < (int)(uVar1 + 1 | uVar1)) goto LAB_00103a70;
    uVar5 = 1;
  }
  refcount_warn_saturate(puVar4,uVar5);
LAB_00103a70:
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 8;
  return;
}



//------------------------------------------------------------
// mem_buf_lend_notify @ 00103ab8 size=208
// signature: undefined mem_buf_lend_notify(void)
// callers: [mem_buf_lend_internal]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mem_buf_lend_notify(long param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  
  puVar3 = (undefined2 *)kmalloc_trace(_memcpy,0xdc0,8);
  if (puVar3 != (undefined2 *)0x0) {
    iVar2 = *(int *)(param_1 + 0x30);
    *puVar3 = 1;
    if (iVar2 != 0) {
      uVar4 = 0;
      do {
        uVar1 = *(undefined4 *)(param_1 + 0x50);
        puVar3[2] = (short)*(undefined4 *)(*(long *)(param_1 + 0x20) + (long)(int)uVar4 * 4);
        iVar2 = gh_rm_mem_notify(uVar1,1,0x3a,puVar3);
        if (iVar2 != 0) {
          _printk(&DAT_0010835e,"mem_buf_lend_notify",
                  *(undefined4 *)(*(long *)(param_1 + 0x20) + (long)(int)uVar4 * 4));
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(param_1 + 0x30));
    }
    kfree(puVar3);
  }
  return;
}



//------------------------------------------------------------
// mem_buf_vmperm_gh_notifier @ 00103b8c size=316
// signature: undefined mem_buf_vmperm_gh_notifier(void)
// callers: []
//------------------------------------------------------------

void mem_buf_vmperm_gh_notifier
               (undefined8 param_1,long param_2,undefined8 param_3,undefined4 *param_4)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  bool bVar6;
  code *pcVar7;
  long lVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  
  if (param_2 == 0x51100012) {
    uVar2 = *param_4;
    __rcu_read_lock();
    lVar8 = xa_load(vmperm_xa,uVar2);
    if (lVar8 != 0) {
      puVar9 = *(uint **)(lVar8 + 0xa0);
      uVar10 = *puVar9;
      if (*puVar9 == 0) {
        uVar11 = 0;
      }
      else {
        do {
          Hint_Prefetch(puVar9,2,0,1);
          do {
            uVar3 = *puVar9;
            if (uVar3 != uVar10) break;
            cVar5 = '\x01';
            bVar6 = (bool)ExclusiveMonitorPass(puVar9,0x10);
            if (bVar6) {
              *puVar9 = uVar10 + 1;
              cVar5 = ExclusiveMonitorsStatus();
            }
          } while (cVar5 != '\0');
          uVar11 = uVar10;
        } while ((uVar10 != uVar3) && (uVar11 = 0, uVar10 = uVar3, uVar3 != 0));
      }
      if ((int)(uVar11 + 1 | uVar11) < 0) {
        refcount_warn_saturate(puVar9,0);
      }
      if (uVar11 != 0) {
        __rcu_read_unlock();
        mem_buf_vmperm_try_reclaim(lVar8,1);
        pcVar7 = *(code **)(lVar8 + 0x98);
        piVar1 = *(int **)(lVar8 + 0xa0);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar4 = *piVar1;
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar6) {
            *piVar1 = iVar4 + -1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        if (iVar4 == 1) {
          DataMemoryBarrier(2,1);
          if (*(int *)(pcVar7 + -4) != -0x214e6a45) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x103c88);
            (*pcVar7)();
          }
          (*pcVar7)();
          return;
        }
        if (iVar4 < 1) {
          refcount_warn_saturate(piVar1,3);
          return;
        }
        return;
      }
    }
    __rcu_read_unlock();
  }
  return;
}



//------------------------------------------------------------
// summary_open @ 00103cf0 size=44
// signature: undefined summary_open(void)
// callers: []
//------------------------------------------------------------

void summary_open(undefined8 param_1,undefined8 param_2)

{
  single_open(param_2,summary_show,0);
  return;
}



//------------------------------------------------------------
// summary_show @ 00103d20 size=664
// signature: undefined summary_show(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

undefined8 summary_show(undefined8 param_1)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  undefined **ppuVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong local_80;
  ulong local_78;
  ulong local_70;
  ulong local_68;
  
  mutex_lock(&vmperm_list_lock);
  if ((undefined **)vmperm_list == &vmperm_list) {
    local_80 = 0;
    local_78 = 0;
    uVar5 = 0;
    uVar6 = 0;
    uVar11 = 0;
    uVar12 = 0;
    local_70 = 0;
    local_68 = 0;
    uVar10 = 0;
    uVar8 = 0;
    uVar7 = 0;
  }
  else {
    uVar5 = 0;
    uVar6 = 0;
    uVar11 = 0;
    uVar12 = 0;
    uVar10 = 0;
    uVar8 = 0;
    uVar7 = 0;
    local_80 = 0;
    local_78 = 0;
    local_70 = 0;
    local_68 = 0;
    ppuVar9 = (undefined **)vmperm_list;
    do {
      mutex_lock();
      uVar1 = *(uint *)(ppuVar9 + 6);
      uVar3 = (ulong)uVar1;
      if (uVar1 != 0) {
        uVar4 = 0;
        do {
          switch(*(undefined4 *)(ppuVar9[4] + (long)(int)uVar4 * 4)) {
          case 9:
            uVar2 = 0;
            if (uVar3 != 0) {
              uVar2 = (ulong)ppuVar9[9] / uVar3;
            }
            local_78 = local_78 + (long)ppuVar9[9];
            uVar11 = uVar11 + uVar2;
            uVar7 = uVar11 + uVar7;
            break;
          case 10:
            uVar2 = 0;
            if (uVar3 != 0) {
              uVar2 = (ulong)ppuVar9[9] / uVar3;
            }
            local_70 = local_70 + (long)ppuVar9[9];
            uVar10 = uVar10 + uVar2;
            uVar7 = uVar10 + uVar7;
            break;
          case 0xb:
            uVar2 = 0;
            if (uVar3 != 0) {
              uVar2 = (ulong)ppuVar9[9] / uVar3;
            }
            local_68 = local_68 + (long)ppuVar9[9];
            uVar8 = uVar8 + uVar2;
            uVar7 = uVar8 + uVar7;
            break;
          case 0x2d:
            uVar2 = 0;
            if (uVar3 != 0) {
              uVar2 = (ulong)ppuVar9[9] / uVar3;
            }
            uVar12 = uVar12 + (long)ppuVar9[9];
            uVar6 = uVar6 + uVar2;
            uVar7 = uVar6 + uVar7;
            break;
          case 0x31:
            uVar2 = 0;
            if (uVar3 != 0) {
              uVar2 = (ulong)ppuVar9[9] / uVar3;
            }
            local_80 = local_80 + (long)ppuVar9[9];
            uVar5 = uVar5 + uVar2;
            uVar7 = uVar5 + uVar7;
          }
          uVar4 = uVar4 + 1;
        } while (uVar1 != uVar4);
      }
      mutex_unlock(ppuVar9 + 0xb);
      ppuVar9 = (undefined **)*ppuVar9;
    } while (ppuVar9 != &vmperm_list);
  }
  mutex_unlock(&vmperm_list_lock);
  seq_printf(param_1,"%10s %10s %10s\n",&DAT_00108409,"SIZE-MB","PSS-SIZE-MB");
  seq_printf(param_1,"%#10x %10zu %10zu\n",0x2d,uVar12 >> 0x14,uVar6 >> 0x14);
  seq_printf(param_1,"%#10x %10zu %10zu\n",0x31,local_80 >> 0x14,uVar5 >> 0x14);
  seq_printf(param_1,"%#10x %10zu %10zu\n",9,local_78 >> 0x14,uVar11 >> 0x14);
  seq_printf(param_1,"%#10x %10zu %10zu\n",10,local_70 >> 0x14,uVar10 >> 0x14);
  seq_printf(param_1,"%#10x %10zu %10zu\n",0xb,local_68 >> 0x14,uVar8 >> 0x14);
  seq_printf(param_1,"\nTotal Pss: %zu\n",uVar7 >> 0x14);
  return 0;
}



//------------------------------------------------------------
// mem_buf_current_vmid @ 00103fbc size=12
// signature: undefined mem_buf_current_vmid(void)
// callers: []
//------------------------------------------------------------

undefined4 mem_buf_current_vmid(void)

{
  return current_vmid;
}



//------------------------------------------------------------
// mem_buf_vm_uses_hyp_assign @ 00103fcc size=20
// signature: undefined mem_buf_vm_uses_hyp_assign(void)
// callers: [mem_buf_hyp_assign_table, mem_buf_unassign_mem, mem_buf_assign_mem]
//------------------------------------------------------------

bool mem_buf_vm_uses_hyp_assign(void)

{
  return current_vmid == 3;
}



//------------------------------------------------------------
// mem_buf_vm_uses_gunyah @ 00103fe4 size=248
// signature: undefined mem_buf_vm_uses_gunyah(void)
// callers: [mem_buf_assign_mem_gunyah]
//------------------------------------------------------------

ulong mem_buf_vm_uses_gunyah(long param_1,int param_2)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  int iVar4;
  
  if (param_2 != 0) {
    iVar4 = 0;
    do {
      lVar2 = xa_load(mem_buf_vms,(long)*(int *)(param_1 + (long)iVar4 * 4));
      if (lVar2 == 0) {
        iVar1 = ___ratelimit(mem_buf_vm_uses_gunyah__rs,"mem_buf_vm_uses_gunyah");
        if (iVar1 == 0) {
          return 0xffffffea;
        }
        _printk(&DAT_0010856f,*(undefined4 *)(param_1 + (long)iVar4 * 4));
        return 0xffffffea;
      }
      if ((*(byte *)(lVar2 + 0xc) >> 1 & 1) != 0) {
        return 1;
      }
      iVar4 = iVar4 + 1;
    } while (param_2 != iVar4);
  }
  lVar2 = xa_load(mem_buf_vms,(long)current_vmid);
  if (lVar2 == 0) {
    uVar3 = ___ratelimit(mem_buf_vm_uses_gunyah__rs_1,"mem_buf_vm_uses_gunyah");
    if ((int)uVar3 != 0) {
      _printk(&DAT_0010856f,current_vmid);
      uVar3 = 0;
    }
  }
  else {
    uVar3 = (ulong)(*(uint *)(lVar2 + 0xc) >> 1 & 1);
  }
  return uVar3;
}



//------------------------------------------------------------
// mem_buf_fd_to_vmid @ 001040e0 size=144
// signature: undefined mem_buf_fd_to_vmid(void)
// callers: []
//------------------------------------------------------------

ulong mem_buf_fd_to_vmid(void)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  
  lVar2 = fget();
  if (lVar2 == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    if (*(undefined1 **)(lVar2 + 0x28) == &mem_buf_vm_fops) {
      uVar3 = (ulong)*(ushort *)(*(long *)(lVar2 + 0xd8) + 8);
    }
    else {
      iVar1 = ___ratelimit(mem_buf_fd_to_vmid__rs,"mem_buf_fd_to_vmid");
      if (iVar1 == 0) {
        uVar3 = 0xffffffea;
      }
      else {
        _printk(&DAT_00108ac5);
        uVar3 = 0xffffffea;
      }
    }
    fput(lVar2);
  }
  return uVar3;
}



//------------------------------------------------------------
// mem_buf_vm_init @ 00104174 size=512
// signature: undefined mem_buf_vm_init(void)
// callers: [mem_buf_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong mem_buf_vm_init(long param_1)

{
  uint uVar1;
  ulong uVar2;
  undefined8 *puVar3;
  undefined *puVar4;
  long lVar5;
  ulong uVar6;
  undefined **ppuVar7;
  int local_4c;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  local_4c = 0;
  uVar1 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2e8),"qcom,vmid",&local_4c,1,0);
  if ((int)uVar1 < 0) {
    uVar6 = (ulong)uVar1;
    _dev_err(param_1,"missing qcom,vmid property\n");
  }
  else {
    current_vmid = local_4c;
    uVar2 = alloc_chrdev_region(&mem_buf_vm_devt,0,0x80,"mem_buf_vm");
    uVar6 = uVar2 & 0xffffffff;
    if ((int)uVar2 == 0) {
      uVar6 = __class_create(&__this_module,"mem_buf_vm",&mem_buf_vm_init___key);
      puVar4 = pdata_array;
      mem_buf_vm_class = uVar6;
      if (uVar6 < 0xfffffffffffff001) {
        *(code **)(uVar6 + 0x30) = mem_buf_vm_devnode;
        if (puVar4 != (undefined *)0x0) {
          ppuVar7 = &PTR_vm_oemvm_0010cf60;
          do {
            puVar3 = (undefined8 *)kmemdup(puVar4,0x428,0xcc0);
            if (puVar3 == (undefined8 *)0x0) goto LAB_001042c8;
            uVar1 = mem_buf_vm_add();
            if (uVar1 != 0) {
              uVar6 = (ulong)uVar1;
              goto LAB_001042ec;
            }
            puVar4 = *ppuVar7;
            ppuVar7 = ppuVar7 + 1;
          } while (puVar4 != (undefined *)0x0);
        }
        lVar5 = xa_load(mem_buf_vms,(long)current_vmid);
        uVar6 = 0;
        if (lVar5 == 0) goto LAB_0010433c;
        puVar3 = (undefined8 *)kmalloc_trace(_alt_cb_patch_nops,0xdc0,0x428);
        if (puVar3 == (undefined8 *)0x0) {
LAB_001042c8:
          uVar6 = 0xfffffff4;
        }
        else {
          *puVar3 = "qcom,self";
          *(undefined2 *)(puVar3 + 1) = *(undefined2 *)(lVar5 + 8);
          *(undefined4 *)((long)puVar3 + 0xc) = *(undefined4 *)(lVar5 + 0xc);
          uVar2 = mem_buf_vm_add();
          uVar6 = uVar2 & 0xffffffff;
          if ((int)uVar2 == 0) goto LAB_0010433c;
LAB_001042ec:
          kfree(puVar3);
        }
        xa_destroy(mem_buf_vms);
        xa_destroy(mem_buf_vm_minors);
        class_for_each_device(mem_buf_vm_class,0,0,mem_buf_vm_put_class_device_cb);
        class_destroy(mem_buf_vm_class);
      }
      unregister_chrdev_region(mem_buf_vm_devt,0x80);
    }
  }
LAB_0010433c:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// mem_buf_vm_devnode @ 00104378 size=52
// signature: undefined mem_buf_vm_devnode(void)
// callers: []
//------------------------------------------------------------

void mem_buf_vm_devnode(long *param_1)

{
  long lVar1;
  
  lVar1 = param_1[0xe];
  if (lVar1 == 0) {
    lVar1 = *param_1;
  }
  kasprintf(0xcc0,"mem_buf_vm/%s",lVar1);
  return;
}



//------------------------------------------------------------
// mem_buf_vm_put_class_device_cb @ 001043b0 size=40
// signature: undefined mem_buf_vm_put_class_device_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 mem_buf_vm_put_class_device_cb(long param_1)

{
  cdev_device_del(param_1 + -0x88,param_1);
  return 0;
}



//------------------------------------------------------------
// mem_buf_vm_exit @ 001043dc size=108
// signature: undefined mem_buf_vm_exit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void mem_buf_vm_exit(void)

{
  xa_destroy(mem_buf_vms);
  xa_destroy(mem_buf_vm_minors);
  class_for_each_device(mem_buf_vm_class,0,0,mem_buf_vm_put_class_device_cb);
  class_destroy(mem_buf_vm_class);
  unregister_chrdev_region(mem_buf_vm_devt,0x80);
  return;
}



//------------------------------------------------------------
// mem_buf_vm_open @ 0010444c size=20
// signature: undefined mem_buf_vm_open(void)
// callers: []
//------------------------------------------------------------

undefined8 mem_buf_vm_open(long param_1,long param_2)

{
  *(long *)(param_2 + 0xd8) = *(long *)(param_1 + 0x290) + -0x10;
  return 0;
}



//------------------------------------------------------------
// mem_buf_vm_add @ 00104460 size=524
// signature: undefined mem_buf_vm_add(void)
// callers: [mem_buf_vm_init]
//------------------------------------------------------------

ulong mem_buf_vm_add(undefined8 *param_1)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  undefined8 *puVar5;
  ulong uVar6;
  char *__s1;
  ulong uVar7;
  undefined8 local_48;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  local_48 = 0;
  puVar5 = (undefined8 *)xa_find(mem_buf_vm_minors,&local_48,0xffffffffffffffff,8);
  while (puVar5 != (undefined8 *)0x0) {
    __s1 = (char *)*puVar5;
    iVar4 = strcmp(__s1,(char *)*param_1);
    if (iVar4 == 0) {
      _printk(&DAT_001080e1,__s1);
      uVar7 = 0xffffffea;
      goto LAB_001045ec;
    }
    puVar5 = (undefined8 *)xa_find_after(mem_buf_vm_minors,&local_48,0xffffffffffffffff,8);
  }
  _raw_spin_lock(mem_buf_vm_minors);
  uVar6 = __xa_alloc(mem_buf_vm_minors,&local_3c,param_1,0x7f,0xcc0);
  uVar7 = uVar6 & 0xffffffff;
  _raw_spin_unlock(mem_buf_vm_minors);
  if ((int)uVar6 < 0) {
    _printk(&DAT_00108443);
  }
  else {
    cdev_init(param_1 + 2,&mem_buf_vm_fops);
    puVar5 = param_1 + 0x13;
    device_initialize(puVar5);
    uVar3 = mem_buf_vm_class;
    uVar2 = mem_buf_vm_devt;
    param_1[0x1f] = 0;
    param_1[0x78] = mem_buf_vm_device_release;
    param_1[0x76] = uVar3;
    param_1[0x26] = param_1;
    *(uint *)(param_1 + 0x72) = uVar2 & 0xfff00000 | local_3c;
    dev_set_name(puVar5,&DAT_001082cd,*param_1);
    uVar7 = xa_store(mem_buf_vms,*(undefined2 *)(param_1 + 1),param_1,0xcc0);
    if (((uVar7 < 0xffffffffffffc006) || ((uVar7 & 3) != 2)) ||
       (uVar7 = uVar7 >> 2, (int)uVar7 == 0)) {
      uVar6 = cdev_device_add(param_1 + 2,puVar5);
      uVar7 = uVar6 & 0xffffffff;
      if ((int)uVar6 == 0) goto LAB_001045ec;
      _printk(&DAT_001086c1,*param_1);
      xa_erase(mem_buf_vms,*(undefined2 *)(param_1 + 1));
    }
    xa_erase(mem_buf_vm_minors,(long)(int)local_3c);
    put_device(puVar5);
  }
LAB_001045ec:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7 & 0xffffffff;
}



//------------------------------------------------------------
// mem_buf_vm_device_release @ 00104670 size=32
// signature: undefined mem_buf_vm_device_release(void)
// callers: []
//------------------------------------------------------------

void mem_buf_vm_device_release(long param_1)

{
  kfree(param_1 + -0x98);
  return;
}



//------------------------------------------------------------
// __traceiter_mem_buf_alloc_info @ 00104694 size=140
// signature: undefined __traceiter_mem_buf_alloc_info(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_mem_buf_alloc_info
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined8 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_0010e950;
  plVar2 = DAT_0010e950;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0xadc711e) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1046f8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_send_alloc_req @ 00104724 size=100
// signature: undefined __traceiter_send_alloc_req(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_send_alloc_req(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0010e998;
  plVar2 = _DAT_0010e998;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x49f2df6d) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104768);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_receive_alloc_req @ 0010478c size=100
// signature: undefined __traceiter_receive_alloc_req(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_receive_alloc_req(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0010e9e0;
  plVar2 = _DAT_0010e9e0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x49f2df6d) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1047d0);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_send_relinquish_msg @ 001047f4 size=100
// signature: undefined __traceiter_send_relinquish_msg(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_send_relinquish_msg(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0010ea28;
  plVar2 = _DAT_0010ea28;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x4cb34d79) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104838);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_receive_relinquish_msg @ 0010485c size=100
// signature: undefined __traceiter_receive_relinquish_msg(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_receive_relinquish_msg(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0010ea70;
  plVar2 = _DAT_0010ea70;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x4cb34d79) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1048a0);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_send_alloc_resp_msg @ 001048c4 size=100
// signature: undefined __traceiter_send_alloc_resp_msg(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_send_alloc_resp_msg(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0010eab8;
  plVar2 = _DAT_0010eab8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x1e0e024c) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104908);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_receive_alloc_resp_msg @ 0010492c size=100
// signature: undefined __traceiter_receive_alloc_resp_msg(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_receive_alloc_resp_msg(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0010eb00;
  plVar2 = _DAT_0010eb00;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x1e0e024c) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104970);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_send_relinquish_resp_msg @ 00104994 size=100
// signature: undefined __traceiter_send_relinquish_resp_msg(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_send_relinquish_resp_msg(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0010eb48;
  plVar2 = _DAT_0010eb48;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x4cb34d79) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1049d8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_receive_relinquish_resp_msg @ 001049fc size=100
// signature: undefined __traceiter_receive_relinquish_resp_msg(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_receive_relinquish_resp_msg(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0010eb90;
  plVar2 = _DAT_0010eb90;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x4cb34d79) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104a40);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_lookup_sgl @ 00104a64 size=124
// signature: undefined __traceiter_lookup_sgl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_lookup_sgl(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0010ebd8;
  plVar2 = _DAT_0010ebd8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x20f0f5e9) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104abc);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_map_mem_s2 @ 00104ae4 size=116
// signature: undefined __traceiter_map_mem_s2(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_map_mem_s2(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0010ec20;
  plVar2 = _DAT_0010ec20;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x530746e0) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104b34);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_mem_buf_alloc_info @ 00104b5c size=512
// signature: undefined trace_event_raw_event_mem_buf_alloc_info(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_mem_buf_alloc_info
               (long param_1,undefined8 param_2,int param_3,int param_4,uint *param_5)

{
  char *pcVar1;
  ushort uVar2;
  ushort uVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  size_t sVar7;
  ulong uVar8;
  undefined1 *puVar9;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 local_5c;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  local_5c = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar8 = __trace_trigger_soft_disabled(param_1), (uVar8 & 1) == 0)) {
    iVar5 = trace_event_get_offsets_mem_buf_alloc_info(&local_68,param_3,param_4,param_5);
    lVar6 = trace_event_buffer_reserve(&local_98,param_1,(long)iVar5 + 0x28);
    uVar4 = local_68;
    if (lVar6 != 0) {
      pcVar1 = "ION_MEM_TYPE";
      if (param_3 != 0) {
        pcVar1 = "(null)";
      }
      *(undefined4 *)(lVar6 + 0x14) = local_68;
      *(ulong *)(lVar6 + 0x18) = CONCAT44(uStack_60,uStack_64);
      *(undefined4 *)(lVar6 + 0x20) = local_5c;
      *(undefined8 *)(lVar6 + 8) = param_2;
      sVar7 = strnlen(pcVar1,0xd);
      if (0xd < sVar7) {
LAB_00104d34:
                    /* WARNING: Subroutine does not return */
        fortify_panic("strnlen");
      }
      if (sVar7 == 0xffffffffffffffff) {
LAB_00104d40:
                    /* WARNING: Subroutine does not return */
        fortify_panic("strcpy");
      }
      if (sVar7 != 0xd) {
        memcpy((void *)(lVar6 + (ulong)(ushort)uVar4),pcVar1,sVar7 + 1);
        pcVar1 = "ION_MEM_TYPE";
        if (param_4 != 0) {
          pcVar1 = "(null)";
        }
        uVar2 = *(ushort *)(lVar6 + 0x18);
        sVar7 = strnlen(pcVar1,0xd);
        if (0xd < sVar7) goto LAB_00104d34;
        if (sVar7 == 0xffffffffffffffff) goto LAB_00104d40;
        if (sVar7 != 0xd) {
          memcpy((void *)(lVar6 + (ulong)uVar2),pcVar1,sVar7 + 1);
          *(uint *)(lVar6 + 0x10) = *param_5;
          if (*param_5 != 0) {
            uVar2 = *(ushort *)(lVar6 + 0x1c);
            uVar8 = 0;
            uVar3 = *(ushort *)(lVar6 + 0x20);
            puVar9 = (undefined1 *)((long)param_5 + 6);
            do {
              *(undefined2 *)(lVar6 + (ulong)uVar2 + uVar8 * 2) = *(undefined2 *)(puVar9 + -2);
              *(undefined1 *)(lVar6 + (ulong)uVar3 + uVar8) = *puVar9;
              uVar8 = uVar8 + 1;
              puVar9 = puVar9 + 4;
            } while (uVar8 < *param_5);
          }
          trace_event_buffer_commit(&local_98);
          goto LAB_00104cec;
        }
      }
                    /* WARNING: Subroutine does not return */
      fortify_panic("__fortify_strlen");
    }
  }
LAB_00104cec:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_mem_buf_alloc_info @ 00104d60 size=600
// signature: undefined perf_trace_mem_buf_alloc_info(void)
// callers: []
//------------------------------------------------------------

void perf_trace_mem_buf_alloc_info
               (long param_1,undefined8 param_2,int param_3,int param_4,uint *param_5)

{
  long *plVar1;
  char *pcVar2;
  ushort uVar3;
  ushort uVar4;
  undefined4 uVar5;
  int iVar6;
  long lVar7;
  size_t sVar8;
  ulong uVar9;
  undefined1 *puVar10;
  ulong unaff_x30;
  long *local_90;
  undefined4 local_84;
  long local_80;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 local_6c;
  undefined8 local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  local_78 = 0;
  uStack_74 = 0;
  uStack_70 = 0;
  local_6c = 0;
  local_80 = 0;
  local_84 = 0;
  iVar6 = trace_event_get_offsets_mem_buf_alloc_info(&local_78,param_3,param_4,param_5);
  lVar7 = tpidr_el1;
  plVar1 = (long *)(lVar7 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar6 = (iVar6 + 0x33U & 0xfffffff8) - 4;
    lVar7 = perf_trace_buf_alloc(iVar6,&local_80,&local_84);
    uVar5 = local_78;
    if (lVar7 != 0) {
      uVar9 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar9 = unaff_x30 | 0xffffff8000000000;
      }
      *(long ***)(local_80 + 0xf8) = &local_90;
      *(long *)(local_80 + 0xe8) = (long)register0x00000008 + -0x60;
      *(ulong *)(local_80 + 0x100) = uVar9;
      *(undefined8 *)(local_80 + 0x108) = 5;
      pcVar2 = "ION_MEM_TYPE";
      if (param_3 != 0) {
        pcVar2 = "(null)";
      }
      *(undefined4 *)(lVar7 + 0x14) = local_78;
      *(ulong *)(lVar7 + 0x18) = CONCAT44(uStack_70,uStack_74);
      *(undefined4 *)(lVar7 + 0x20) = local_6c;
      *(undefined8 *)(lVar7 + 8) = param_2;
      local_90 = plVar1;
      sVar8 = strnlen(pcVar2,0xd);
      if (0xd < sVar8) {
LAB_00104f90:
                    /* WARNING: Subroutine does not return */
        fortify_panic("strnlen");
      }
      if (sVar8 == 0xffffffffffffffff) {
LAB_00104f9c:
                    /* WARNING: Subroutine does not return */
        fortify_panic("strcpy");
      }
      if (sVar8 != 0xd) {
        memcpy((void *)(lVar7 + (ulong)(ushort)uVar5),pcVar2,sVar8 + 1);
        pcVar2 = "ION_MEM_TYPE";
        if (param_4 != 0) {
          pcVar2 = "(null)";
        }
        uVar3 = *(ushort *)(lVar7 + 0x18);
        sVar8 = strnlen(pcVar2,0xd);
        if (0xd < sVar8) goto LAB_00104f90;
        if (sVar8 == 0xffffffffffffffff) goto LAB_00104f9c;
        if (sVar8 != 0xd) {
          memcpy((void *)(lVar7 + (ulong)uVar3),pcVar2,sVar8 + 1);
          *(uint *)(lVar7 + 0x10) = *param_5;
          if (*param_5 != 0) {
            uVar3 = *(ushort *)(lVar7 + 0x1c);
            uVar9 = 0;
            uVar4 = *(ushort *)(lVar7 + 0x20);
            puVar10 = (undefined1 *)((long)param_5 + 6);
            do {
              *(undefined2 *)(lVar7 + (ulong)uVar3 + uVar9 * 2) = *(undefined2 *)(puVar10 + -2);
              *(undefined1 *)(lVar7 + (ulong)uVar4 + uVar9) = *puVar10;
              uVar9 = uVar9 + 1;
              puVar10 = puVar10 + 4;
            } while (uVar9 < *param_5);
          }
          perf_trace_run_bpf_submit(lVar7,iVar6,local_84,param_1,1,local_80,local_90,0);
          goto LAB_00104f58;
        }
      }
                    /* WARNING: Subroutine does not return */
      fortify_panic("__fortify_strlen");
    }
  }
LAB_00104f58:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_alloc_req_msg_class @ 00104fbc size=508
// signature: undefined trace_event_raw_event_alloc_req_msg_class(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_alloc_req_msg_class(long param_1,undefined4 *param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  long lVar4;
  size_t sVar5;
  ulong uVar6;
  undefined1 *puVar7;
  char *pcVar8;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_58 = 0;
  local_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar6 = __trace_trigger_soft_disabled(param_1), (uVar6 & 1) == 0)) {
    iVar3 = trace_event_get_offsets_alloc_req_msg_class(&local_58,param_2);
    lVar4 = trace_event_buffer_reserve(&local_88,param_1,(long)iVar3 + 0x28);
    uVar6 = local_58;
    if (lVar4 != 0) {
      pcVar8 = "(null)";
      *(undefined4 *)(lVar4 + 0xc) = (undefined4)local_58;
      *(undefined4 *)(lVar4 + 0x18) = local_58._4_4_;
      *(undefined4 *)(lVar4 + 0x20) = (undefined4)local_50;
      *(undefined4 *)(lVar4 + 0x24) = local_50._4_4_;
      *(undefined4 *)(lVar4 + 8) = *param_2;
      if ((uint)param_2[1] < 4) {
        pcVar8 = (&PTR_s_MEM_BUF_ALLOC_REQ_0010e790)[(int)param_2[1]];
      }
      sVar5 = strnlen(pcVar8,0x1e);
      if (0x1e < sVar5) {
LAB_00105190:
                    /* WARNING: Subroutine does not return */
        fortify_panic("strnlen");
      }
      if (sVar5 != 0x1e) {
        memcpy((void *)(lVar4 + (uVar6 & 0xffff)),pcVar8,sVar5 + 1);
        uVar1 = *(ushort *)(lVar4 + 0x18);
        *(undefined8 *)(lVar4 + 0x10) = *(undefined8 *)(param_2 + 3);
        pcVar8 = "ION_MEM_TYPE";
        if (param_2[5] != 0) {
          pcVar8 = "(null)";
        }
        sVar5 = strnlen(pcVar8,0xd);
        if (0xd < sVar5) goto LAB_00105190;
        if (sVar5 == 0xffffffffffffffff) {
                    /* WARNING: Subroutine does not return */
          fortify_panic("strcpy");
        }
        if (sVar5 != 0xd) {
          memcpy((void *)(lVar4 + (ulong)uVar1),pcVar8,sVar5 + 1);
          *(undefined4 *)(lVar4 + 0x1c) = param_2[7];
          if (param_2[7] != 0) {
            uVar1 = *(ushort *)(lVar4 + 0x20);
            uVar6 = 0;
            uVar2 = *(ushort *)(lVar4 + 0x24);
            puVar7 = (undefined1 *)((long)param_2 + 0x22);
            do {
              *(undefined2 *)(lVar4 + (ulong)uVar1 + uVar6 * 2) = *(undefined2 *)(puVar7 + -2);
              *(undefined1 *)(lVar4 + (ulong)uVar2 + uVar6) = *puVar7;
              uVar6 = uVar6 + 1;
              puVar7 = puVar7 + 4;
            } while (uVar6 < (uint)param_2[7]);
          }
          trace_event_buffer_commit(&local_88);
          goto LAB_0010514c;
        }
      }
                    /* WARNING: Subroutine does not return */
      fortify_panic("__fortify_strlen");
    }
  }
LAB_0010514c:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_alloc_req_msg_class @ 001051bc size=588
// signature: undefined perf_trace_alloc_req_msg_class(void)
// callers: []
//------------------------------------------------------------

void perf_trace_alloc_req_msg_class(long param_1,undefined4 *param_2)

{
  long *plVar1;
  ulong uVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  long lVar6;
  size_t sVar7;
  ulong uVar8;
  undefined1 *puVar9;
  char *pcVar10;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_68 = 0;
  local_60 = 0;
  local_70 = 0;
  local_74 = 0;
  iVar5 = trace_event_get_offsets_alloc_req_msg_class(&local_68);
  lVar6 = tpidr_el1;
  plVar1 = (long *)(lVar6 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar5 = (iVar5 + 0x33U & 0xfffffff8) - 4;
    lVar6 = perf_trace_buf_alloc(iVar5,&local_70,&local_74);
    uVar8 = local_68;
    if (lVar6 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x30;
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      pcVar10 = "(null)";
      *(ulong *)(local_70 + 0x100) = uVar2;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(undefined4 *)(lVar6 + 0xc) = (undefined4)local_68;
      *(undefined4 *)(lVar6 + 0x18) = local_68._4_4_;
      *(undefined4 *)(lVar6 + 0x20) = (undefined4)local_60;
      *(undefined4 *)(lVar6 + 0x24) = local_60._4_4_;
      *(undefined4 *)(lVar6 + 8) = *param_2;
      if ((uint)param_2[1] < 4) {
        pcVar10 = (&PTR_s_MEM_BUF_ALLOC_REQ_0010e790)[(int)param_2[1]];
      }
      sVar7 = strnlen(pcVar10,0x1e);
      if (0x1e < sVar7) {
LAB_001053e0:
                    /* WARNING: Subroutine does not return */
        fortify_panic("strnlen");
      }
      if (sVar7 != 0x1e) {
        memcpy((void *)(lVar6 + (uVar8 & 0xffff)),pcVar10,sVar7 + 1);
        uVar3 = *(ushort *)(lVar6 + 0x18);
        *(undefined8 *)(lVar6 + 0x10) = *(undefined8 *)(param_2 + 3);
        pcVar10 = "ION_MEM_TYPE";
        if (param_2[5] != 0) {
          pcVar10 = "(null)";
        }
        sVar7 = strnlen(pcVar10,0xd);
        if (0xd < sVar7) goto LAB_001053e0;
        if (sVar7 == 0xffffffffffffffff) {
                    /* WARNING: Subroutine does not return */
          fortify_panic("strcpy");
        }
        if (sVar7 != 0xd) {
          memcpy((void *)(lVar6 + (ulong)uVar3),pcVar10,sVar7 + 1);
          *(undefined4 *)(lVar6 + 0x1c) = param_2[7];
          if (param_2[7] != 0) {
            uVar3 = *(ushort *)(lVar6 + 0x20);
            uVar8 = 0;
            uVar4 = *(ushort *)(lVar6 + 0x24);
            puVar9 = (undefined1 *)((long)param_2 + 0x22);
            do {
              *(undefined2 *)(lVar6 + (ulong)uVar3 + uVar8 * 2) = *(undefined2 *)(puVar9 + -2);
              *(undefined1 *)(lVar6 + (ulong)uVar4 + uVar8) = *puVar9;
              uVar8 = uVar8 + 1;
              puVar9 = puVar9 + 4;
            } while (uVar8 < (uint)param_2[7]);
          }
          perf_trace_run_bpf_submit(lVar6,iVar5,local_74,param_1,1,local_70,plVar1,0);
          goto LAB_001053ac;
        }
      }
                    /* WARNING: Subroutine does not return */
      fortify_panic("__fortify_strlen");
    }
  }
LAB_001053ac:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_relinquish_req_msg_class @ 0010540c size=376
// signature: undefined trace_event_raw_event_relinquish_req_msg_class(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_relinquish_req_msg_class(long param_1,undefined4 *param_2)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  long lVar4;
  ulong uVar5;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar5 = __trace_trigger_soft_disabled(param_1), (uVar5 & 1) == 0)) {
    if ((uint)param_2[1] < 4) {
      pcVar2 = (&PTR_s_MEM_BUF_ALLOC_REQ_0010e790)[(int)param_2[1]];
    }
    else {
      pcVar2 = "(null)";
    }
    sVar3 = strnlen(pcVar2,0x1e);
    if (0x1e < sVar3) {
LAB_00105568:
                    /* WARNING: Subroutine does not return */
      fortify_panic("strnlen");
    }
    if (sVar3 == 0x1e) {
LAB_00105574:
                    /* WARNING: Subroutine does not return */
      fortify_panic("__fortify_strlen");
    }
    iVar1 = (int)sVar3 + 1;
    lVar4 = trace_event_buffer_reserve(&local_68,param_1,(long)iVar1 + 0x14);
    if (lVar4 != 0) {
      *(uint *)(lVar4 + 8) = iVar1 * 0x10000 | 0x14;
      if ((uint)param_2[1] < 4) {
        pcVar2 = (&PTR_s_MEM_BUF_ALLOC_REQ_0010e790)[(int)param_2[1]];
      }
      else {
        pcVar2 = "(null)";
      }
      sVar3 = strnlen(pcVar2,0x1e);
      if (0x1e < sVar3) goto LAB_00105568;
      if (sVar3 == 0x1e) goto LAB_00105574;
      memcpy((void *)(lVar4 + 0x14),pcVar2,sVar3 + 1);
      *(undefined4 *)(lVar4 + 0xc) = param_2[3];
      *(undefined4 *)(lVar4 + 0x10) = *param_2;
      trace_event_buffer_commit(&local_68);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_relinquish_req_msg_class @ 00105588 size=468
// signature: undefined perf_trace_relinquish_req_msg_class(void)
// callers: []
//------------------------------------------------------------

void perf_trace_relinquish_req_msg_class(long param_1,undefined4 *param_2)

{
  int iVar1;
  long *plVar2;
  ulong uVar3;
  char *pcVar4;
  size_t sVar5;
  long lVar6;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_60 = 0;
  local_64 = 0;
  if ((uint)param_2[1] < 4) {
    pcVar4 = (&PTR_s_MEM_BUF_ALLOC_REQ_0010e790)[(int)param_2[1]];
  }
  else {
    pcVar4 = "(null)";
  }
  sVar5 = strnlen(pcVar4,0x1e);
  if (0x1e < sVar5) {
LAB_00105740:
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar5 == 0x1e) {
LAB_0010574c:
                    /* WARNING: Subroutine does not return */
    fortify_panic("__fortify_strlen");
  }
  lVar6 = tpidr_el1;
  plVar2 = (long *)(lVar6 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = ((uint)sVar5 & 0xfffffff8) + 0x1c;
    lVar6 = perf_trace_buf_alloc(iVar1,&local_60,&local_64);
    if (lVar6 != 0) {
      *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
      *(undefined1 **)(local_60 + 0xf8) = auStack_70;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_60 + 0x100) = uVar3;
      *(undefined8 *)(local_60 + 0x108) = 5;
      *(uint *)(lVar6 + 8) = (uint)sVar5 * 0x10000 + 0x10014;
      if ((uint)param_2[1] < 4) {
        pcVar4 = (&PTR_s_MEM_BUF_ALLOC_REQ_0010e790)[(int)param_2[1]];
      }
      else {
        pcVar4 = "(null)";
      }
      sVar5 = strnlen(pcVar4,0x1e);
      if (0x1e < sVar5) goto LAB_00105740;
      if (sVar5 == 0x1e) goto LAB_0010574c;
      memcpy((void *)(lVar6 + 0x14),pcVar4,sVar5 + 1);
      *(undefined4 *)(lVar6 + 0xc) = param_2[3];
      *(undefined4 *)(lVar6 + 0x10) = *param_2;
      perf_trace_run_bpf_submit(lVar6,iVar1,local_64,param_1,1,local_60,plVar2,0);
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
// trace_event_raw_event_alloc_resp_class @ 00105760 size=384
// signature: undefined trace_event_raw_event_alloc_resp_class(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_alloc_resp_class(long param_1,undefined4 *param_2)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  long lVar4;
  ulong uVar5;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar5 = __trace_trigger_soft_disabled(param_1), (uVar5 & 1) == 0)) {
    if ((uint)param_2[1] < 4) {
      pcVar2 = (&PTR_s_MEM_BUF_ALLOC_REQ_0010e790)[(int)param_2[1]];
    }
    else {
      pcVar2 = "(null)";
    }
    sVar3 = strnlen(pcVar2,0x1e);
    if (0x1e < sVar3) {
LAB_001058c4:
                    /* WARNING: Subroutine does not return */
      fortify_panic("strnlen");
    }
    if (sVar3 == 0x1e) {
LAB_001058d0:
                    /* WARNING: Subroutine does not return */
      fortify_panic("__fortify_strlen");
    }
    iVar1 = (int)sVar3 + 1;
    lVar4 = trace_event_buffer_reserve(&local_68,param_1,(long)iVar1 + 0x18);
    if (lVar4 != 0) {
      *(uint *)(lVar4 + 0xc) = iVar1 * 0x10000 | 0x18;
      *(undefined4 *)(lVar4 + 8) = *param_2;
      if ((uint)param_2[1] < 4) {
        pcVar2 = (&PTR_s_MEM_BUF_ALLOC_REQ_0010e790)[(int)param_2[1]];
      }
      else {
        pcVar2 = "(null)";
      }
      sVar3 = strnlen(pcVar2,0x1e);
      if (0x1e < sVar3) goto LAB_001058c4;
      if (sVar3 == 0x1e) goto LAB_001058d0;
      memcpy((void *)(lVar4 + 0x18),pcVar2,sVar3 + 1);
      *(undefined4 *)(lVar4 + 0x10) = param_2[3];
      *(undefined4 *)(lVar4 + 0x14) = param_2[4];
      trace_event_buffer_commit(&local_68);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_alloc_resp_class @ 001058e4 size=480
// signature: undefined perf_trace_alloc_resp_class(void)
// callers: []
//------------------------------------------------------------

void perf_trace_alloc_resp_class(long param_1,undefined4 *param_2)

{
  long *plVar1;
  ulong uVar2;
  int iVar3;
  char *pcVar4;
  size_t sVar5;
  long lVar6;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_60 = 0;
  local_64 = 0;
  if ((uint)param_2[1] < 4) {
    pcVar4 = (&PTR_s_MEM_BUF_ALLOC_REQ_0010e790)[(int)param_2[1]];
  }
  else {
    pcVar4 = "(null)";
  }
  sVar5 = strnlen(pcVar4,0x1e);
  if (0x1e < sVar5) {
LAB_00105aa8:
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar5 == 0x1e) {
LAB_00105ab4:
                    /* WARNING: Subroutine does not return */
    fortify_panic("__fortify_strlen");
  }
  lVar6 = tpidr_el1;
  plVar1 = (long *)(lVar6 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar5 + 0x24U & 0xfffffff8) - 4;
    lVar6 = perf_trace_buf_alloc(iVar3,&local_60,&local_64);
    if (lVar6 != 0) {
      *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
      *(undefined1 **)(local_60 + 0xf8) = auStack_70;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_60 + 0x100) = uVar2;
      *(undefined8 *)(local_60 + 0x108) = 5;
      *(int *)(lVar6 + 0xc) = (int)sVar5 * 0x10000 + 0x10018;
      *(undefined4 *)(lVar6 + 8) = *param_2;
      if ((uint)param_2[1] < 4) {
        pcVar4 = (&PTR_s_MEM_BUF_ALLOC_REQ_0010e790)[(int)param_2[1]];
      }
      else {
        pcVar4 = "(null)";
      }
      sVar5 = strnlen(pcVar4,0x1e);
      if (0x1e < sVar5) goto LAB_00105aa8;
      if (sVar5 == 0x1e) goto LAB_00105ab4;
      memcpy((void *)(lVar6 + 0x18),pcVar4,sVar5 + 1);
      *(undefined4 *)(lVar6 + 0x10) = param_2[3];
      *(undefined4 *)(lVar6 + 0x14) = param_2[4];
      perf_trace_run_bpf_submit(lVar6,iVar3,local_64,param_1,1,local_60,plVar1,0);
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
// trace_event_raw_event_relinquish_resp_class @ 00105ac8 size=368
// signature: undefined trace_event_raw_event_relinquish_resp_class(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_relinquish_resp_class(long param_1,undefined4 *param_2)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  long lVar4;
  ulong uVar5;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar5 = __trace_trigger_soft_disabled(param_1), (uVar5 & 1) == 0)) {
    if ((uint)param_2[1] < 4) {
      pcVar2 = (&PTR_s_MEM_BUF_ALLOC_REQ_0010e790)[(int)param_2[1]];
    }
    else {
      pcVar2 = "(null)";
    }
    sVar3 = strnlen(pcVar2,0x1e);
    if (0x1e < sVar3) {
LAB_00105c1c:
                    /* WARNING: Subroutine does not return */
      fortify_panic("strnlen");
    }
    if (sVar3 == 0x1e) {
LAB_00105c28:
                    /* WARNING: Subroutine does not return */
      fortify_panic("__fortify_strlen");
    }
    iVar1 = (int)sVar3 + 1;
    lVar4 = trace_event_buffer_reserve(&local_68,param_1,(long)iVar1 + 0x10);
    if (lVar4 != 0) {
      *(uint *)(lVar4 + 0xc) = iVar1 * 0x10000 | 0x10;
      *(undefined4 *)(lVar4 + 8) = *param_2;
      if ((uint)param_2[1] < 4) {
        pcVar2 = (&PTR_s_MEM_BUF_ALLOC_REQ_0010e790)[(int)param_2[1]];
      }
      else {
        pcVar2 = "(null)";
      }
      sVar3 = strnlen(pcVar2,0x1e);
      if (0x1e < sVar3) goto LAB_00105c1c;
      if (sVar3 == 0x1e) goto LAB_00105c28;
      memcpy((void *)(lVar4 + 0x10),pcVar2,sVar3 + 1);
      trace_event_buffer_commit(&local_68);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_relinquish_resp_class @ 00105c3c size=464
// signature: undefined perf_trace_relinquish_resp_class(void)
// callers: []
//------------------------------------------------------------

void perf_trace_relinquish_resp_class(long param_1,undefined4 *param_2)

{
  long *plVar1;
  ulong uVar2;
  int iVar3;
  char *pcVar4;
  size_t sVar5;
  long lVar6;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_60 = 0;
  local_64 = 0;
  if ((uint)param_2[1] < 4) {
    pcVar4 = (&PTR_s_MEM_BUF_ALLOC_REQ_0010e790)[(int)param_2[1]];
  }
  else {
    pcVar4 = "(null)";
  }
  sVar5 = strnlen(pcVar4,0x1e);
  if (0x1e < sVar5) {
LAB_00105df0:
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar5 == 0x1e) {
LAB_00105dfc:
                    /* WARNING: Subroutine does not return */
    fortify_panic("__fortify_strlen");
  }
  lVar6 = tpidr_el1;
  plVar1 = (long *)(lVar6 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar5 + 0x1cU & 0xfffffff8) - 4;
    lVar6 = perf_trace_buf_alloc(iVar3,&local_60,&local_64);
    if (lVar6 != 0) {
      *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
      *(undefined1 **)(local_60 + 0xf8) = auStack_70;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_60 + 0x100) = uVar2;
      *(undefined8 *)(local_60 + 0x108) = 5;
      *(int *)(lVar6 + 0xc) = (int)sVar5 * 0x10000 + 0x10010;
      *(undefined4 *)(lVar6 + 8) = *param_2;
      if ((uint)param_2[1] < 4) {
        pcVar4 = (&PTR_s_MEM_BUF_ALLOC_REQ_0010e790)[(int)param_2[1]];
      }
      else {
        pcVar4 = "(null)";
      }
      sVar5 = strnlen(pcVar4,0x1e);
      if (0x1e < sVar5) goto LAB_00105df0;
      if (sVar5 == 0x1e) goto LAB_00105dfc;
      memcpy((void *)(lVar6 + 0x10),pcVar4,sVar5 + 1);
      perf_trace_run_bpf_submit(lVar6,iVar3,local_64,param_1,1,local_60,plVar1,0);
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
// trace_event_raw_event_lookup_sgl @ 00105e10 size=296
// signature: undefined trace_event_raw_event_lookup_sgl(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_lookup_sgl
               (long param_1,ushort *param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  ushort *puVar5;
  long lVar6;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar3 = __trace_trigger_soft_disabled(param_1), (uVar3 & 1) == 0)) {
    uVar1 = *param_2;
    lVar2 = trace_event_buffer_reserve(&local_68,param_1,(ulong)uVar1 * 0x10 + 0x1c);
    if (lVar2 != 0) {
      uVar3 = (ulong)uVar1 * 8 + 0x1c;
      *(uint *)(lVar2 + 0xc) = (uint)uVar1 << 0x13 | 0x1c;
      *(uint *)(lVar2 + 0x10) = (uint)uVar3 | (uint)uVar1 << 0x13;
      *(ushort *)(lVar2 + 8) = *param_2;
      if (*param_2 != 0) {
        uVar4 = 0;
        puVar5 = param_2 + 6;
        do {
          lVar6 = uVar4 * 8;
          uVar4 = uVar4 + 1;
          *(undefined8 *)(lVar2 + 0x1c + lVar6) = *(undefined8 *)(puVar5 + -4);
          *(undefined8 *)(lVar2 + (uVar3 & 0xfffc) + lVar6) = *(undefined8 *)puVar5;
          puVar5 = puVar5 + 8;
        } while (uVar4 < *param_2);
      }
      *(undefined4 *)(lVar2 + 0x14) = param_3;
      *(undefined4 *)(lVar2 + 0x18) = param_4;
      trace_event_buffer_commit(&local_68);
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_lookup_sgl @ 00105f3c size=376
// signature: undefined perf_trace_lookup_sgl(void)
// callers: []
//------------------------------------------------------------

void perf_trace_lookup_sgl(long param_1,ushort *param_2,undefined4 param_3,undefined4 param_4)

{
  ulong uVar1;
  long *plVar2;
  ushort uVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  ushort *puVar7;
  long lVar8;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  local_60 = 0;
  local_64 = 0;
  uVar3 = *param_2;
  lVar5 = tpidr_el1;
  plVar2 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar4 = ((uint)uVar3 * 0x10 + 0x27 & 0x1ffff0) - 4;
    lVar5 = perf_trace_buf_alloc(iVar4,&local_60,&local_64);
    if (lVar5 != 0) {
      *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
      uVar6 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar6 = unaff_x30 | 0xffffff8000000000;
      }
      uVar1 = (ulong)uVar3 * 8 + 0x1c;
      *(undefined1 **)(local_60 + 0xf8) = auStack_70;
      *(ulong *)(local_60 + 0x100) = uVar6;
      *(undefined8 *)(local_60 + 0x108) = 5;
      *(uint *)(lVar5 + 0xc) = (uint)uVar3 << 0x13 | 0x1c;
      *(uint *)(lVar5 + 0x10) = (uint)uVar1 | (uint)uVar3 << 0x13;
      *(ushort *)(lVar5 + 8) = *param_2;
      if (*param_2 != 0) {
        uVar6 = 0;
        puVar7 = param_2 + 6;
        do {
          lVar8 = uVar6 * 8;
          uVar6 = uVar6 + 1;
          *(undefined8 *)(lVar5 + 0x1c + lVar8) = *(undefined8 *)(puVar7 + -4);
          *(undefined8 *)(lVar5 + (uVar1 & 0xffff) + lVar8) = *(undefined8 *)puVar7;
          puVar7 = puVar7 + 8;
        } while (uVar6 < *param_2);
      }
      *(undefined4 *)(lVar5 + 0x14) = param_3;
      *(undefined4 *)(lVar5 + 0x18) = param_4;
      perf_trace_run_bpf_submit(lVar5,iVar4,local_64,param_1,1,local_60,plVar2,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_map_mem_s2 @ 001060b8 size=288
// signature: undefined trace_event_raw_event_map_mem_s2(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_map_mem_s2(long param_1,undefined4 param_2,ushort *param_3)

{
  ushort uVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  ushort *puVar5;
  long lVar6;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar3 = __trace_trigger_soft_disabled(param_1), (uVar3 & 1) == 0)) {
    uVar1 = *param_3;
    lVar2 = trace_event_buffer_reserve(&local_68,param_1,(ulong)uVar1 * 0x10 + 0x18);
    if (lVar2 != 0) {
      uVar3 = (ulong)uVar1 * 8 + 0x18;
      *(undefined4 *)(lVar2 + 8) = param_2;
      *(uint *)(lVar2 + 0x10) = (uint)uVar1 << 0x13 | 0x18;
      *(uint *)(lVar2 + 0x14) = (uint)uVar3 | (uint)uVar1 << 0x13;
      *(ushort *)(lVar2 + 0xc) = *param_3;
      if (*param_3 != 0) {
        uVar4 = 0;
        puVar5 = param_3 + 6;
        do {
          lVar6 = uVar4 * 8;
          uVar4 = uVar4 + 1;
          *(undefined8 *)(lVar2 + 0x18 + lVar6) = *(undefined8 *)(puVar5 + -4);
          *(undefined8 *)(lVar2 + (uVar3 & 0xfff8) + lVar6) = *(undefined8 *)puVar5;
          puVar5 = puVar5 + 8;
        } while (uVar4 < *param_3);
      }
      trace_event_buffer_commit(&local_68);
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_map_mem_s2 @ 001061dc size=372
// signature: undefined perf_trace_map_mem_s2(void)
// callers: []
//------------------------------------------------------------

void perf_trace_map_mem_s2(long param_1,undefined4 param_2,ushort *param_3)

{
  ulong uVar1;
  long *plVar2;
  ushort uVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  ushort *puVar7;
  long lVar8;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  local_60 = 0;
  local_64 = 0;
  uVar3 = *param_3;
  lVar5 = tpidr_el1;
  plVar2 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar4 = ((uint)uVar3 * 0x10 + 0x23 & 0x1ffff0) - 4;
    lVar5 = perf_trace_buf_alloc(iVar4,&local_60,&local_64);
    if (lVar5 != 0) {
      *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
      uVar6 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar6 = unaff_x30 | 0xffffff8000000000;
      }
      uVar1 = (ulong)uVar3 * 8 + 0x18;
      *(undefined1 **)(local_60 + 0xf8) = auStack_70;
      *(ulong *)(local_60 + 0x100) = uVar6;
      *(undefined8 *)(local_60 + 0x108) = 5;
      *(undefined4 *)(lVar5 + 8) = param_2;
      *(uint *)(lVar5 + 0x10) = (uint)uVar3 << 0x13 | 0x18;
      *(uint *)(lVar5 + 0x14) = (uint)uVar1 | (uint)uVar3 << 0x13;
      *(ushort *)(lVar5 + 0xc) = *param_3;
      if (*param_3 != 0) {
        uVar6 = 0;
        puVar7 = param_3 + 6;
        do {
          lVar8 = uVar6 * 8;
          uVar6 = uVar6 + 1;
          *(undefined8 *)(lVar5 + 0x18 + lVar8) = *(undefined8 *)(puVar7 + -4);
          *(undefined8 *)(lVar5 + (uVar1 & 0xffff) + lVar8) = *(undefined8 *)puVar7;
          puVar7 = puVar7 + 8;
        } while (uVar6 < *param_3);
      }
      perf_trace_run_bpf_submit(lVar5,iVar4,local_64,param_1,1,local_60,plVar2,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_mem_buf_alloc_info @ 00106354 size=36
// signature: undefined __bpf_trace_mem_buf_alloc_info(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_mem_buf_alloc_info
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  bpf_trace_run4(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_alloc_req_msg_class @ 0010637c size=28
// signature: undefined __bpf_trace_alloc_req_msg_class(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_alloc_req_msg_class(void)

{
  bpf_trace_run1();
  return;
}



//------------------------------------------------------------
// __bpf_trace_relinquish_req_msg_class @ 0010639c size=28
// signature: undefined __bpf_trace_relinquish_req_msg_class(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_relinquish_req_msg_class(void)

{
  bpf_trace_run1();
  return;
}



//------------------------------------------------------------
// __bpf_trace_alloc_resp_class @ 001063bc size=28
// signature: undefined __bpf_trace_alloc_resp_class(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_alloc_resp_class(void)

{
  bpf_trace_run1();
  return;
}



//------------------------------------------------------------
// __bpf_trace_relinquish_resp_class @ 001063dc size=28
// signature: undefined __bpf_trace_relinquish_resp_class(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_relinquish_resp_class(void)

{
  bpf_trace_run1();
  return;
}



//------------------------------------------------------------
// __bpf_trace_lookup_sgl @ 001063fc size=36
// signature: undefined __bpf_trace_lookup_sgl(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_lookup_sgl
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_map_mem_s2 @ 00106424 size=32
// signature: undefined __bpf_trace_map_mem_s2(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_map_mem_s2(undefined8 param_1,undefined4 param_2)

{
  bpf_trace_run2(param_1,param_2);
  return;
}



//------------------------------------------------------------
// mem_buf_vmid_perm_list_to_gh_acl @ 00106448 size=180
// signature: undefined mem_buf_vmid_perm_list_to_gh_acl(void)
// callers: []
//------------------------------------------------------------

uint * mem_buf_vmid_perm_list_to_gh_acl(long param_1,long param_2,uint param_3)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  code *pcVar4;
  uint *puVar5;
  ulong uVar6;
  ulong uVar7;
  
  uVar3 = (ulong)param_3 * 4;
  uVar1 = uVar3 + 4;
  puVar5 = (uint *)__kmalloc(uVar1,0xcc0);
  if (puVar5 == (uint *)0x0) {
    puVar5 = (uint *)0xfffffffffffffff4;
  }
  else {
    *puVar5 = param_3;
    if (param_3 != 0) {
      uVar6 = 0;
      uVar7 = uVar3;
      do {
        if ((uVar1 < uVar6 + 4) || (uVar7 < 2)) {
LAB_001064f8:
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(1,0x1064fc);
          (*pcVar4)();
        }
        *(short *)((long)puVar5 + uVar6 + 4) = (short)*(undefined4 *)(param_1 + uVar6);
        if (uVar1 < uVar6 + 6) goto LAB_001064f8;
        uVar2 = uVar6 + 4;
        uVar7 = uVar7 - 4;
        *(char *)((long)puVar5 + uVar6 + 6) = (char)*(undefined4 *)(param_2 + uVar6);
        uVar6 = uVar2;
      } while (uVar3 != uVar2);
    }
  }
  return puVar5;
}



//------------------------------------------------------------
// mem_buf_sgt_to_gh_sgl_desc @ 00106500 size=272
// signature: undefined mem_buf_sgt_to_gh_sgl_desc(void)
// callers: [mem_buf_assign_mem_gunyah, mem_buf_vmperm_try_reclaim]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * mem_buf_sgt_to_gh_sgl_desc(long *param_1)

{
  int iVar1;
  code *pcVar2;
  undefined2 *puVar3;
  ulong *puVar4;
  long lVar5;
  ulong uVar6;
  uint uVar7;
  
  if (0xffff < *(uint *)((long)param_1 + 0xc)) {
    __warn_printk("Too many sgl_entries\n");
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10660c);
    (*pcVar2)();
  }
  uVar6 = (ulong)*(uint *)((long)param_1 + 0xc) << 4 | 4;
  puVar3 = (undefined2 *)kvmalloc_node(uVar6,0xcc0,0xffffffff);
  if (puVar3 == (undefined2 *)0x0) {
    puVar3 = (undefined2 *)0xfffffffffffffff4;
  }
  else {
    iVar1 = *(int *)((long)param_1 + 0xc);
    *puVar3 = (short)iVar1;
    if (iVar1 != 0) {
      uVar7 = 0;
      puVar4 = (ulong *)*param_1;
      do {
        lVar5 = (long)(int)uVar7;
        if (uVar6 <= (lVar5 << 4 | 4U)) {
LAB_00106610:
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(1,0x106614);
          (*pcVar2)();
        }
        *(ulong *)(puVar3 + lVar5 * 8 + 2) =
             (ulong)(uint)puVar4[1] +
             ((*puVar4 & 0x3fffffffffffffc) + (_memstart_addr >> 0xc) * 0x40) * 0x40 + 0x8000000000;
        if (uVar6 < (lVar5 << 4 | 0xcU)) goto LAB_00106610;
        uVar7 = uVar7 + 1;
        *(ulong *)(puVar3 + lVar5 * 8 + 6) = (ulong)*(uint *)((long)puVar4 + 0xc);
        puVar4 = (ulong *)sg_next();
      } while (uVar7 < *(uint *)((long)param_1 + 0xc));
    }
  }
  return puVar3;
}



//------------------------------------------------------------
// mem_buf_gh_acl_desc_to_vmid_perm_list @ 00106618 size=204
// signature: undefined mem_buf_gh_acl_desc_to_vmid_perm_list(void)
// callers: []
//------------------------------------------------------------

undefined8 mem_buf_gh_acl_desc_to_vmid_perm_list(uint *param_1,long *param_2,long *param_3)

{
  uint uVar1;
  code *pcVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  
  uVar3 = 0xffffffea;
  if ((param_2 != (long *)0x0) && (param_3 != (long *)0x0)) {
    uVar1 = *param_1;
    uVar7 = (ulong)uVar1 * 4;
    lVar4 = __kmalloc(uVar7,0xcc0);
    if (lVar4 != 0) {
      lVar5 = __kmalloc(uVar7,0xcc0);
      if (lVar5 != 0) {
        *param_2 = lVar4;
        *param_3 = lVar5;
        if (uVar1 != 0) {
          uVar6 = 0;
          do {
            if (uVar7 <= uVar6) {
LAB_001066e0:
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(1,0x1066e4);
              (*pcVar2)();
            }
            *(uint *)(lVar4 + uVar6) = (uint)*(ushort *)((long)param_1 + uVar6 + 4);
            if (uVar7 <= uVar6) goto LAB_001066e0;
            *(uint *)(lVar5 + uVar6) = (uint)*(byte *)((long)param_1 + uVar6 + 6);
            uVar6 = uVar6 + 4;
          } while (uVar7 != uVar6);
        }
        return 0;
      }
      kfree(lVar4);
    }
    uVar3 = 0xfffffff4;
  }
  return uVar3;
}



//------------------------------------------------------------
// dup_gh_sgl_desc_to_sgt @ 001066e8 size=248
// signature: undefined dup_gh_sgl_desc_to_sgt(void)
// callers: [mem_buf_map_mem_s2]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * dup_gh_sgl_desc_to_sgt(short *param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  ulong *puVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  uint uVar8;
  
  if ((param_1 == (short *)0x0) || (*param_1 == 0)) {
    puVar3 = (undefined8 *)0xffffffffffffffea;
  }
  else {
    puVar3 = (undefined8 *)kmalloc_trace(_memcpy,0xdc0,0x10);
    if (puVar3 == (undefined8 *)0x0) {
      puVar3 = (undefined8 *)0xfffffffffffffff4;
    }
    else {
      iVar2 = sg_alloc_table(puVar3,*param_1,0xcc0);
      if (iVar2 == 0) {
        if (*(int *)(puVar3 + 1) != 0) {
          puVar4 = (ulong *)*puVar3;
          uVar8 = 0;
          do {
            uVar1 = uVar8 + 1;
            uVar7 = *(ulong *)(param_1 + (long)(int)uVar8 * 8 + 2);
            lVar6 = _memstart_addr >> 0xc;
            uVar5 = *(undefined8 *)(param_1 + (long)(int)uVar8 * 8 + 6);
            puVar4[2] = 0;
            *(undefined4 *)(puVar4 + 3) = 0;
            *(undefined4 *)(puVar4 + 1) = 0;
            *(int *)((long)puVar4 + 0xc) = (int)uVar5;
            *puVar4 = ((uVar7 >> 6 & 0x3ffffffffffffc0) + lVar6 * -0x40 | *puVar4 & 3) - 0x200000000
            ;
            puVar4 = (ulong *)sg_next();
            uVar8 = uVar1;
          } while (uVar1 < *(uint *)(puVar3 + 1));
        }
      }
      else {
        kfree(puVar3);
        puVar3 = (undefined8 *)0xfffffffffffffff4;
      }
    }
  }
  return puVar3;
}



//------------------------------------------------------------
// dup_gh_sgl_desc @ 001067e4 size=116
// signature: undefined dup_gh_sgl_desc(void)
// callers: []
//------------------------------------------------------------

void * dup_gh_sgl_desc(ushort *param_1)

{
  void *__dest;
  ulong __n;
  
  if (param_1 == (ushort *)0x0) {
    __dest = (void *)0x0;
  }
  else {
    __n = (ulong)*param_1 << 4 | 4;
    __dest = (void *)kvmalloc_node(__n,0xcc0,0xffffffff);
    if (__dest == (void *)0x0) {
      __dest = (void *)0xfffffffffffffff4;
    }
    else {
      memcpy(__dest,param_1,__n);
    }
  }
  return __dest;
}



//------------------------------------------------------------
// mem_buf_get_sgl_buf_size @ 0010685c size=128
// signature: undefined mem_buf_get_sgl_buf_size(void)
// callers: []
//------------------------------------------------------------

long mem_buf_get_sgl_buf_size(ushort *param_1)

{
  ushort uVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  ushort *puVar6;
  ulong uVar7;
  
  uVar1 = *param_1;
  uVar3 = (ulong)uVar1;
  if (uVar1 == 0) {
    return 0;
  }
  if (uVar1 == 1) {
    uVar5 = 0;
    lVar2 = 0;
  }
  else {
    uVar5 = uVar3 & 0xfffe;
    lVar4 = 0;
    lVar2 = 0;
    puVar6 = param_1 + 0xe;
    uVar7 = uVar5;
    do {
      uVar7 = uVar7 - 2;
      lVar4 = *(long *)(puVar6 + -8) + lVar4;
      lVar2 = *(long *)puVar6 + lVar2;
      puVar6 = puVar6 + 0x10;
    } while (uVar7 != 0);
    lVar2 = lVar2 + lVar4;
    if (uVar5 == uVar3) {
      return lVar2;
    }
  }
  lVar4 = uVar3 - uVar5;
  puVar6 = param_1 + uVar5 * 8 + 6;
  do {
    lVar4 = lVar4 + -1;
    lVar2 = *(long *)puVar6 + lVar2;
    puVar6 = puVar6 + 8;
  } while (lVar4 != 0);
  return lVar2;
}



//------------------------------------------------------------
// mem_buf_map_mem_s2 @ 001068e0 size=776
// signature: undefined mem_buf_map_mem_s2(void)
// callers: []
//------------------------------------------------------------

ulong mem_buf_map_mem_s2(int param_1,undefined4 *param_2,uint *param_3,ulong *param_4,
                        undefined4 param_5)

{
  undefined4 uVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  short *psVar10;
  ulong uVar11;
  ulong uVar12;
  undefined8 local_98;
  undefined4 *puStack_90;
  undefined4 *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined4 local_70;
  undefined4 uStack_6c;
  long local_68;
  
  lVar7 = sp_el0;
  uVar12 = 0xffffffea;
  local_68 = *(long *)(lVar7 + 0x638);
  if ((param_3 != (uint *)0x0) && (param_4 != (ulong *)0x0)) {
    uVar1 = *param_2;
    psVar10 = (short *)*param_4;
    if ((current_vmid == 3) && ((psVar10 == (short *)0x0 || (*psVar10 != 1)))) {
      uVar9 = 0x82;
    }
    else {
      uVar9 = 0x92;
    }
    uVar5 = gh_rm_mem_accept(uVar1,0,param_1,uVar9,0,param_3,psVar10,0,0);
    if (uVar5 < 0xfffffffffffff001) {
      if (param_1 == 0) {
        *param_2 = 0xffffffff;
      }
      local_98 = CONCAT44(local_98._4_4_,param_5);
      uVar6 = dup_gh_sgl_desc_to_sgt(uVar5);
      if (uVar6 < 0xfffffffffffff001) {
        uVar2 = *param_3;
        uVar12 = (ulong)uVar2 * 4;
        lVar7 = __kmalloc(uVar12,0xcc0);
        if (lVar7 == 0) {
          uVar12 = 0xfffffff4;
        }
        else {
          lVar8 = __kmalloc(uVar12,0xcc0);
          if (lVar8 == 0) {
            uVar12 = 0xfffffff4;
          }
          else {
            if (uVar2 != 0) {
              uVar11 = 0;
              do {
                if ((uVar12 == uVar11) || (uVar12 <= uVar11)) {
LAB_00106be0:
                    /* WARNING: Does not return */
                  pcVar3 = (code *)SoftwareBreakpoint(1,0x106be4);
                  (*pcVar3)();
                }
                *(uint *)(lVar7 + uVar11) = (uint)*(ushort *)((long)param_3 + uVar11 + 4);
                if (uVar12 <= uVar11) goto LAB_00106be0;
                *(uint *)(lVar8 + uVar11) = (uint)*(byte *)((long)param_3 + uVar11 + 6);
                uVar11 = uVar11 + 4;
              } while (uVar12 != uVar11);
            }
            uVar12 = mem_buf_hyp_assign_table(uVar6,&local_98,1,lVar7,lVar8,*param_3);
            uVar12 = uVar12 & 0xffffffff;
            kfree(lVar7);
            lVar7 = lVar8;
          }
          kfree(lVar7);
        }
        sg_free_table(uVar6);
        kfree(uVar6);
        iVar4 = (int)uVar12;
      }
      else {
        uVar12 = uVar6 & 0xffffffff;
        iVar4 = (int)uVar6;
      }
      if (iVar4 == 0) {
        uVar12 = 0;
        *param_4 = uVar5;
      }
      else {
        if (param_1 == 0) {
          puStack_90 = &uStack_6c;
          local_88 = &local_70;
          local_78 = 0;
          local_70 = 7;
          local_98 = 1;
          local_80 = 0;
          uStack_6c = param_5;
          uVar6 = dup_gh_sgl_desc_to_sgt(uVar5);
          if (uVar6 < 0xfffffffffffff001) {
            iVar4 = mem_buf_assign_mem_gunyah(0,uVar6,&local_98);
            if (iVar4 == 0) {
              *param_2 = (undefined4)local_80;
            }
            sg_free_table(uVar6);
            kfree(uVar6);
          }
          else {
            iVar4 = (int)uVar6;
          }
        }
        else {
          iVar4 = gh_rm_mem_release(uVar1,0);
          if (iVar4 < 0) {
            _printk(&DAT_00108657,"mem_buf_unmap_mem_s2",uVar1,iVar4);
            iVar4 = 1;
          }
        }
        if (uVar5 != *param_4) {
          kvfree(uVar5);
        }
        if (iVar4 != 0) {
          _printk(&DAT_00108908,"mem_buf_map_mem_s2");
          uVar12 = 0xffffff9d;
        }
      }
    }
    else {
      _printk(&DAT_001085a1,"mem_buf_map_mem_s2",uVar5);
      uVar12 = uVar5 & 0xffffffff;
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar12;
}



//------------------------------------------------------------
// mem_buf_unmap_mem_s2 @ 00106c8c size=88
// signature: undefined mem_buf_unmap_mem_s2(void)
// callers: [mem_buf_vmperm_try_reclaim]
//------------------------------------------------------------

int mem_buf_unmap_mem_s2(ulong param_1)

{
  int iVar1;
  
  iVar1 = gh_rm_mem_release(param_1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00108657,"mem_buf_unmap_mem_s2",param_1 & 0xffffffff,iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// mem_buf_map_mem_s1 @ 00106ce8 size=92
// signature: undefined mem_buf_map_mem_s1(void)
// callers: []
//------------------------------------------------------------

undefined8 mem_buf_map_mem_s1(short *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (*param_1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar1 = tpidr_el1;
    uVar2 = 0xfffffff0;
    _printk(uVar1,&DAT_00108113,"mem_buf_map_mem_s1",*(undefined8 *)(param_1 + 2),
            *(undefined8 *)(param_1 + 6),0xfffffff0);
  }
  return uVar2;
}



//------------------------------------------------------------
// mem_buf_unmap_mem_s1 @ 00106d48 size=140
// signature: undefined mem_buf_unmap_mem_s1(void)
// callers: [mem_buf_vmperm_try_reclaim]
//------------------------------------------------------------

undefined8 mem_buf_unmap_mem_s1(ushort *param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  ushort *puVar3;
  
  if (*param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar2 = 0;
    puVar3 = param_1 + 6;
    uVar1 = 0xfffffff0;
    do {
      _printk(&DAT_00108192,"mem_buf_unmap_mem_s1",*(undefined8 *)(puVar3 + -4),
              *(undefined8 *)puVar3,0xfffffff0);
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 8;
    } while (uVar2 < *param_1);
  }
  return uVar1;
}



//------------------------------------------------------------
// mem_buf_assign_mem_gunyah @ 00106dd8 size=520
// signature: undefined mem_buf_assign_mem_gunyah(void)
// callers: [mem_buf_map_mem_s2, mem_buf_assign_mem]
//------------------------------------------------------------

ulong mem_buf_assign_mem_gunyah(int param_1,undefined8 param_2,uint *param_3)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  uint uVar5;
  ulong uVar6;
  uint *puVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  uint *puVar11;
  ulong uVar12;
  
  uVar5 = mem_buf_vm_uses_gunyah(*(undefined8 *)(param_3 + 2),*param_3);
  if ((int)uVar5 < 1) {
    puVar11 = (uint *)(ulong)uVar5;
    goto LAB_00106f74;
  }
  uVar6 = mem_buf_sgt_to_gh_sgl_desc(param_2);
  if (0xfffffffffffff000 < uVar6) {
    puVar11 = (uint *)(uVar6 & 0xffffffff);
    goto LAB_00106f74;
  }
  uVar5 = *param_3;
  lVar2 = *(long *)(param_3 + 2);
  lVar3 = *(long *)(param_3 + 4);
  uVar12 = (ulong)uVar5 * 4;
  uVar8 = uVar12 + 4;
  puVar7 = (uint *)__kmalloc(uVar8,0xcc0);
  if (puVar7 == (uint *)0x0) {
    puVar11 = (uint *)0xfffffffffffffff4;
  }
  else {
    *puVar7 = uVar5;
    if (uVar5 != 0) {
      uVar9 = 0;
      uVar10 = uVar12;
      do {
        if ((((uVar12 < uVar9) || (uVar10 < 2)) || (uVar8 < uVar9 + 4)) ||
           (((uVar10 < 2 ||
             (*(short *)((long)puVar7 + uVar9 + 4) = (short)*(undefined4 *)(lVar2 + uVar9),
             uVar12 == uVar9)) || (uVar8 < uVar9 + 6)))) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(1,0x106fe0);
          (*pcVar4)();
        }
        uVar1 = uVar9 + 4;
        uVar10 = uVar10 - 4;
        *(char *)((long)puVar7 + uVar9 + 6) = (char)*(undefined4 *)(lVar3 + uVar9);
        uVar9 = uVar1;
      } while (uVar12 != uVar1);
    }
    puVar11 = puVar7;
    if (puVar7 < (uint *)0xfffffffffffff001) {
      if (param_1 == 0) {
        uVar8 = gh_rm_mem_donate(0,param_3[7],param_3[8],puVar7,uVar6,0,param_3 + 6);
LAB_00106f58:
        puVar11 = (uint *)(uVar8 & 0xffffffff);
        if (-1 < (int)uVar8) {
          kfree(puVar7);
          kvfree(uVar6);
          puVar11 = (uint *)0x0;
          goto LAB_00106f74;
        }
      }
      else {
        if (param_1 == 2) {
          uVar8 = ghd_rm_mem_share(0,param_3[7],param_3[8],puVar7,uVar6,0,param_3 + 6);
          goto LAB_00106f58;
        }
        if (param_1 == 1) {
          uVar8 = ghd_rm_mem_lend(0,param_3[7],param_3[8],puVar7,uVar6,0,param_3 + 6);
          goto LAB_00106f58;
        }
        _printk(&DAT_001083b1,"mem_buf_assign_mem_gunyah",param_1);
        puVar11 = (uint *)0xffffffea;
      }
      _printk(&DAT_00108a20,"mem_buf_assign_mem_gunyah",puVar11);
      kfree(puVar7);
    }
  }
  kvfree(uVar6);
LAB_00106f74:
  return (ulong)puVar11 & 0xffffffff;
}



//------------------------------------------------------------
// mem_buf_unassign_mem_gunyah @ 00106fe4 size=76
// signature: undefined mem_buf_unassign_mem_gunyah(void)
// callers: [mem_buf_unassign_mem]
//------------------------------------------------------------

int mem_buf_unassign_mem_gunyah(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = ghd_rm_mem_reclaim(param_1,0);
  if (iVar1 != 0) {
    _printk(&DAT_00108a8b,"mem_buf_unassign_mem_gunyah");
  }
  return iVar1;
}



//------------------------------------------------------------
// trace_event_get_offsets_mem_buf_alloc_info @ 00107030 size=252
// signature: undefined trace_event_get_offsets_mem_buf_alloc_info(void)
// callers: [trace_event_raw_event_mem_buf_alloc_info, perf_trace_mem_buf_alloc_info]
//------------------------------------------------------------

int trace_event_get_offsets_mem_buf_alloc_info(uint *param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  size_t sVar4;
  size_t sVar5;
  
  pcVar3 = "ION_MEM_TYPE";
  if (param_2 != 0) {
    pcVar3 = "(null)";
  }
  sVar4 = strnlen(pcVar3,0xd);
  if (0xd < sVar4) {
LAB_00107114:
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar4 != 0xd) {
    iVar1 = (int)sVar4 + 1;
    pcVar3 = "ION_MEM_TYPE";
    if (param_3 != 0) {
      pcVar3 = "(null)";
    }
    *param_1 = iVar1 * 0x10000 | 0x24;
    sVar5 = strnlen(pcVar3,0xd);
    if (0xd < sVar5) goto LAB_00107114;
    if (sVar5 != 0xd) {
      iVar2 = (int)sVar5 + 1;
      iVar1 = iVar2 + iVar1;
      param_1[1] = (int)sVar4 + 0x25U | iVar2 * 0x10000;
      iVar2 = iVar1 + *param_4 * 2;
      param_1[2] = iVar1 + 0x24U | *param_4 << 0x11;
      iVar1 = *param_4;
      param_1[3] = iVar2 + 0x24U | iVar1 << 0x10;
      return iVar2 + iVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fortify_panic("__fortify_strlen");
}



//------------------------------------------------------------
// trace_raw_output_mem_buf_alloc_info @ 00107130 size=224
// signature: undefined trace_raw_output_mem_buf_alloc_info(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_mem_buf_alloc_info(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  long lVar8;
  
  lVar8 = *(long *)(param_1 + 0x20f0);
  iVar4 = trace_raw_output_prep(param_1,param_3);
  if (iVar4 == 1) {
    uVar1 = *(undefined4 *)(lVar8 + 0x10);
    uVar2 = *(ushort *)(lVar8 + 0x14);
    uVar3 = *(ushort *)(lVar8 + 0x18);
    uVar7 = *(undefined8 *)(lVar8 + 8);
    uVar5 = trace_print_array_seq(param_1 + 0x90,lVar8 + (ulong)*(ushort *)(lVar8 + 0x1c),uVar1,2);
    uVar6 = trace_print_array_seq
                      (param_1 + 0x90,lVar8 + (ulong)*(ushort *)(lVar8 + 0x20),
                       *(undefined4 *)(lVar8 + 0x10),1);
    trace_event_printf(param_1,
                       "size: 0x%lx src mem type: %s dst mem type: %s nr ACL entries: %d ACL VMIDs: %s ACL Perms: %s\n"
                       ,uVar7,lVar8 + (ulong)uVar2,lVar8 + (ulong)uVar3,uVar1,uVar5,uVar6);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_event_get_offsets_alloc_req_msg_class @ 00107210 size=264
// signature: undefined trace_event_get_offsets_alloc_req_msg_class(void)
// callers: [perf_trace_alloc_req_msg_class, trace_event_raw_event_alloc_req_msg_class]
//------------------------------------------------------------

int trace_event_get_offsets_alloc_req_msg_class(uint *param_1,long param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  size_t sVar4;
  size_t sVar5;
  
  pcVar3 = "(null)";
  if (*(uint *)(param_2 + 4) < 4) {
    pcVar3 = (&PTR_s_MEM_BUF_ALLOC_REQ_0010e790)[(int)*(uint *)(param_2 + 4)];
  }
  sVar4 = strnlen(pcVar3,0x1e);
  if (0x1e < sVar4) {
LAB_00107300:
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar4 != 0x1e) {
    iVar1 = (int)sVar4 + 1;
    *param_1 = iVar1 * 0x10000 | 0x28;
    pcVar3 = "ION_MEM_TYPE";
    if (*(int *)(param_2 + 0x14) != 0) {
      pcVar3 = "(null)";
    }
    sVar5 = strnlen(pcVar3,0xd);
    if (0xd < sVar5) goto LAB_00107300;
    if (sVar5 != 0xd) {
      iVar2 = (int)sVar5 + 1;
      iVar1 = iVar2 + iVar1;
      param_1[1] = (int)sVar4 + 0x29U | iVar2 * 0x10000;
      iVar2 = iVar1 + *(int *)(param_2 + 0x1c) * 2;
      param_1[2] = iVar1 + 0x28U | *(int *)(param_2 + 0x1c) << 0x11;
      iVar1 = *(int *)(param_2 + 0x1c);
      param_1[3] = iVar2 + 0x28U | iVar1 << 0x10;
      return iVar2 + iVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fortify_panic("__fortify_strlen");
}



//------------------------------------------------------------
// trace_raw_output_alloc_req_msg_class @ 0010731c size=244
// signature: undefined trace_raw_output_alloc_req_msg_class(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_alloc_req_msg_class(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  
  lVar9 = *(long *)(param_1 + 0x20f0);
  iVar5 = trace_raw_output_prep(param_1,param_3);
  if (iVar5 == 1) {
    uVar1 = *(undefined4 *)(lVar9 + 0x1c);
    uVar3 = *(ushort *)(lVar9 + 0xc);
    uVar4 = *(ushort *)(lVar9 + 0x18);
    uVar2 = *(undefined4 *)(lVar9 + 8);
    uVar8 = *(undefined8 *)(lVar9 + 0x10);
    uVar6 = trace_print_array_seq(param_1 + 0x90,lVar9 + (ulong)*(ushort *)(lVar9 + 0x20),uVar1,2);
    uVar7 = trace_print_array_seq
                      (param_1 + 0x90,lVar9 + (ulong)*(ushort *)(lVar9 + 0x24),
                       *(undefined4 *)(lVar9 + 0x1c),1);
    trace_event_printf(param_1,
                       "txn_id: %d msg_type: %s alloc_sz: 0x%lx src_mem_type: %s nr ACL entries: %d ACL VMIDs: %s ACL Perms: %s\n"
                       ,uVar2,lVar9 + (ulong)uVar3,uVar8,lVar9 + (ulong)uVar4,uVar1,uVar6,uVar7);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_relinquish_req_msg_class @ 00107414 size=108
// signature: undefined trace_raw_output_relinquish_req_msg_class(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_relinquish_req_msg_class(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"msg_type: %s memparcel_hdl: 0x%x txn_id: 0x%x\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_alloc_resp_class @ 00107484 size=112
// signature: undefined trace_raw_output_alloc_resp_class(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_alloc_resp_class(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"txn_id: %d msg_type: %s ret: %d memparcel_hdl: 0x%x\n",
                       *(undefined4 *)(lVar2 + 8),lVar2 + (ulong)*(ushort *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_relinquish_resp_class @ 001074f8 size=108
// signature: undefined trace_raw_output_relinquish_resp_class(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_relinquish_resp_class(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"txn_id: %d msg_type: %s\n",*(undefined4 *)(lVar2 + 8),
                       lVar2 + (ulong)*(ushort *)(lVar2 + 0xc));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_lookup_sgl @ 00107568 size=180
// signature: undefined trace_raw_output_lookup_sgl(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_lookup_sgl(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x20f0);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 == 1) {
    uVar1 = *(undefined2 *)(lVar5 + 8);
    uVar3 = trace_print_array_seq(param_1 + 0x90,lVar5 + (ulong)*(ushort *)(lVar5 + 0xc),uVar1,8);
    uVar4 = trace_print_array_seq
                      (param_1 + 0x90,lVar5 + (ulong)*(ushort *)(lVar5 + 0x10),
                       *(undefined2 *)(lVar5 + 8),8);
    trace_event_printf(param_1,
                       "SGL entries: %d SGL IPA bases: %s SGL sizes: %s ret: %d memparcel_hdl: 0x%x\n"
                       ,uVar1,uVar3,uVar4,*(undefined4 *)(lVar5 + 0x14),
                       *(undefined4 *)(lVar5 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_map_mem_s2 @ 00107620 size=192
// signature: undefined trace_raw_output_map_mem_s2(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_map_mem_s2(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x20f0);
  iVar3 = trace_raw_output_prep(param_1,param_3);
  if (iVar3 == 1) {
    uVar2 = *(undefined2 *)(lVar6 + 0xc);
    uVar1 = *(undefined4 *)(lVar6 + 8);
    uVar4 = trace_print_array_seq(param_1 + 0x90,lVar6 + (ulong)*(ushort *)(lVar6 + 0x10),uVar2,8);
    uVar5 = trace_print_array_seq
                      (param_1 + 0x90,lVar6 + (ulong)*(ushort *)(lVar6 + 0x14),
                       *(undefined2 *)(lVar6 + 0xc),8);
    trace_event_printf(param_1,
                       "MEM_ACCEPT successful memparcel hdl: 0x%x SGL entries: %d SGL IPA bases: %s SGL sizes: %s\n"
                       ,uVar1,uVar2,uVar4,uVar5);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00107e48 size=68
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  mem_buf_debugfs_root = debugfs_create_dir("mem_buf",0);
  __platform_driver_register(&mem_buf_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00107e90 size=52
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  mem_buf_vm_exit();
  platform_driver_unregister(&mem_buf_driver);
  debugfs_remove(mem_buf_debugfs_root);
  return;
}



//------------------------------------------------------------
// hyp_assign_table @ 00111000 size=1
// signature: undefined hyp_assign_table(void)
// callers: [mem_buf_unassign_mem, mem_buf_hyp_assign_table, mem_buf_assign_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hyp_assign_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00111008 size=1
// signature: undefined _printk(void)
// callers: [mem_buf_hyp_assign_table, mem_buf_unmap_mem_s1, validate_lend_mapcount, mem_buf_vm_add, mem_buf_map_mem_s1, mem_buf_assign_mem_gunyah, mem_buf_lend_internal, mem_buf_unassign_mem, mem_buf_unassign_mem_gunyah, mem_buf_vmperm_try_reclaim, mem_buf_dma_buf_init, mem_buf_map_mem_s2, mem_buf_reclaim, mem_buf_vm_uses_gunyah, mem_buf_lend_notify, mem_buf_dma_buf_export, mem_buf_fd_to_vmid, mem_buf_assign_mem, mem_buf_unmap_mem_s2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00111010 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [mem_buf_vmperm_alloc, trace_event_raw_event_mem_buf_alloc_info, perf_trace_alloc_req_msg_class, perf_trace_lookup_sgl, perf_trace_map_mem_s2, mem_buf_vm_add, perf_trace_relinquish_resp_class, perf_trace_alloc_resp_class, trace_event_raw_event_lookup_sgl, mem_buf_unassign_mem, mem_buf_probe, mem_buf_map_mem_s2, perf_trace_relinquish_req_msg_class, perf_trace_mem_buf_alloc_info, trace_event_raw_event_relinquish_resp_class, mem_buf_vm_init, trace_event_raw_event_alloc_req_msg_class, trace_event_raw_event_alloc_resp_class, trace_event_raw_event_map_mem_s2, trace_event_raw_event_relinquish_req_msg_class, mem_buf_assign_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00111018 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00111020 size=1
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
// platform_driver_unregister @ 00111028 size=1
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
// debugfs_remove @ 00111030 size=1
// signature: undefined debugfs_remove(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_err_probe @ 00111038 size=1
// signature: undefined dev_err_probe(void)
// callers: [mem_buf_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_err_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_match_string @ 00111040 size=1
// signature: undefined of_property_match_string(void)
// callers: [mem_buf_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_match_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 00111048 size=1
// signature: undefined dma_set_mask(void)
// callers: [mem_buf_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 00111050 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [mem_buf_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00111058 size=1
// signature: undefined of_find_property(void)
// callers: [mem_buf_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_device_init_by_idx @ 00111060 size=1
// signature: undefined of_reserved_mem_device_init_by_idx(void)
// callers: [mem_buf_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_device_init_by_idx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00111068 size=1
// signature: undefined _dev_err(void)
// callers: [mem_buf_probe, mem_buf_vm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00111078 size=1
// signature: undefined kmalloc_trace(void)
// callers: [dup_gh_sgl_desc_to_sgt, mem_buf_vmperm_alloc_flags, mem_buf_lend_notify, mem_buf_vm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00111080 size=1
// signature: undefined __mutex_init(void)
// callers: [mem_buf_vmperm_alloc_flags]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00111088 size=1
// signature: undefined mutex_lock(void)
// callers: [mem_buf_vmperm_can_vmap, mem_buf_dma_buf_get_vmperm, mem_buf_lend_internal, mem_buf_vmperm_pin, mem_buf_dma_buf_exclusive_owner, mem_buf_dma_buf_set_destructor, summary_show, mem_buf_vmperm_try_reclaim, mem_buf_vmperm_free, mem_buf_vmperm_can_cmo, mem_buf_reclaim, mem_buf_vmperm_alloc_flags, mem_buf_vmperm_unpin, mem_buf_vmperm_can_mmap, mem_buf_dma_buf_copy_vmperm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00111090 size=1
// signature: undefined mutex_unlock(void)
// callers: [mem_buf_vmperm_can_vmap, mem_buf_dma_buf_get_vmperm, mem_buf_lend_internal, mem_buf_vmperm_pin, mem_buf_dma_buf_exclusive_owner, mem_buf_dma_buf_set_destructor, summary_show, mem_buf_vmperm_try_reclaim, mem_buf_vmperm_free, mem_buf_vmperm_can_cmo, mem_buf_reclaim, mem_buf_vmperm_alloc_flags, mem_buf_vmperm_unpin, mem_buf_vmperm_can_mmap, mem_buf_dma_buf_copy_vmperm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00111098 size=1
// signature: undefined kfree(void)
// callers: [mem_buf_map_mem_s2, mem_buf_vmperm_resize, dup_gh_sgl_desc_to_sgt, mem_buf_vmperm_alloc_flags, mem_buf_vm_device_release, mem_buf_lend_notify, vmperm_rcu_cb, mem_buf_share, mem_buf_assign_mem_gunyah, mem_buf_gh_acl_desc_to_vmid_perm_list, mem_buf_vm_init, mem_buf_dma_buf_copy_vmperm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001110a0 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [trace_event_raw_event_mem_buf_alloc_info, perf_trace_alloc_req_msg_class, dup_gh_sgl_desc, perf_trace_relinquish_resp_class, perf_trace_alloc_resp_class, mem_buf_vmperm_update_state, mem_buf_vmperm_resize, perf_trace_relinquish_req_msg_class, perf_trace_mem_buf_alloc_info, mem_buf_vmperm_alloc_flags, mem_buf_share, trace_event_raw_event_relinquish_resp_class, trace_event_raw_event_alloc_req_msg_class, trace_event_raw_event_alloc_resp_class, trace_event_raw_event_relinquish_req_msg_class]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_next @ 001110a8 size=1
// signature: undefined sg_next(void)
// callers: [mem_buf_sgt_to_gh_sgl_desc, dup_gh_sgl_desc_to_sgt, mem_buf_vmperm_alloc_flags]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 001110b0 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [xa_insert, mem_buf_vmperm_alloc_flags, mem_buf_vm_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __xa_insert @ 001110b8 size=1
// signature: undefined __xa_insert(void)
// callers: [xa_insert, mem_buf_vmperm_alloc_flags]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __xa_insert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 001110c0 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [xa_insert, mem_buf_vmperm_alloc_flags, mem_buf_vm_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001110d0 size=1
// signature: undefined __list_add_valid(void)
// callers: [mem_buf_vmperm_alloc_flags]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 001110d8 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [mem_buf_vmperm_try_reclaim, __mem_buf_vmperm_reclaim, mem_buf_vmperm_alloc_flags, mem_buf_vmperm_gh_notifier, kref_get, mem_buf_vmperm_set_err]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001110e0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [mem_buf_vmperm_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// call_rcu @ 001110e8 size=1
// signature: undefined call_rcu(void)
// callers: [mem_buf_vmperm_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void call_rcu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 001110f0 size=1
// signature: undefined ___ratelimit(void)
// callers: [mem_buf_vmperm_try_reclaim, mem_buf_reclaim, validate_lend_mapcount, mem_buf_vm_uses_gunyah, mem_buf_lend_internal, mem_buf_fd_to_vmid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kvfree @ 001110f8 size=1
// signature: undefined kvfree(void)
// callers: [mem_buf_vmperm_try_reclaim, mem_buf_map_mem_s2, mem_buf_assign_mem_gunyah]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kvfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_mem_notify @ 00111100 size=1
// signature: undefined gh_rm_mem_notify(void)
// callers: [mem_buf_vmperm_try_reclaim, mem_buf_lend_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_mem_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xa_erase @ 00111108 size=1
// signature: undefined xa_erase(void)
// callers: [mem_buf_vmperm_try_reclaim, __mem_buf_vmperm_reclaim, mem_buf_vm_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xa_erase(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_export @ 00111110 size=1
// signature: undefined dma_buf_export(void)
// callers: [mem_buf_dma_buf_export]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_export(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_sgtable @ 00111120 size=1
// signature: undefined dma_map_sgtable(void)
// callers: [mem_buf_lend_internal]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_sgtable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_sg_attrs @ 00111128 size=1
// signature: undefined dma_unmap_sg_attrs(void)
// callers: [mem_buf_lend_internal]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_sg_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00111130 size=1
// signature: undefined __kmalloc(void)
// callers: [mem_buf_map_mem_s2, mem_buf_vmperm_resize, mem_buf_share, mem_buf_assign_mem_gunyah, mem_buf_vmid_perm_list_to_gh_acl, mem_buf_gh_acl_desc_to_vmid_perm_list]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmemdup @ 00111138 size=1
// signature: undefined kmemdup(void)
// callers: [mem_buf_vm_init, mem_buf_dma_buf_copy_vmperm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmemdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_mem_notifier_register @ 00111140 size=1
// signature: undefined gh_mem_notifier_register(void)
// callers: [mem_buf_dma_buf_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_mem_notifier_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00111148 size=1
// signature: undefined debugfs_create_file(void)
// callers: [mem_buf_dma_buf_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_lock @ 00111150 size=1
// signature: undefined __rcu_read_lock(void)
// callers: [mem_buf_vmperm_gh_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xa_load @ 00111158 size=1
// signature: undefined xa_load(void)
// callers: [mem_buf_vm_uses_gunyah, mem_buf_vmperm_gh_notifier, mem_buf_vm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xa_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_unlock @ 00111160 size=1
// signature: undefined __rcu_read_unlock(void)
// callers: [mem_buf_vmperm_gh_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 00111168 size=1
// signature: undefined single_open(void)
// callers: [summary_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00111170 size=1
// signature: undefined seq_printf(void)
// callers: [summary_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fget @ 00111190 size=1
// signature: undefined fget(void)
// callers: [mem_buf_fd_to_vmid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fget(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fput @ 00111198 size=1
// signature: undefined fput(void)
// callers: [mem_buf_fd_to_vmid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fput(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001111a0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [mem_buf_vm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 001111a8 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [mem_buf_vm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 001111b0 size=1
// signature: undefined __class_create(void)
// callers: [mem_buf_vm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xa_destroy @ 001111b8 size=1
// signature: undefined xa_destroy(void)
// callers: [mem_buf_vm_init, mem_buf_vm_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xa_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_for_each_device @ 001111c0 size=1
// signature: undefined class_for_each_device(void)
// callers: [mem_buf_vm_init, mem_buf_vm_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_for_each_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 001111c8 size=1
// signature: undefined class_destroy(void)
// callers: [mem_buf_vm_init, mem_buf_vm_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 001111d0 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [mem_buf_vm_init, mem_buf_vm_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kasprintf @ 001111d8 size=1
// signature: undefined kasprintf(void)
// callers: [mem_buf_vm_devnode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kasprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_device_del @ 001111e0 size=1
// signature: undefined cdev_device_del(void)
// callers: [mem_buf_vm_put_class_device_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_device_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xa_find @ 001111e8 size=1
// signature: undefined xa_find(void)
// callers: [mem_buf_vm_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xa_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001111f0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [mem_buf_vm_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xa_find_after @ 001111f8 size=1
// signature: undefined xa_find_after(void)
// callers: [mem_buf_vm_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xa_find_after(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __xa_alloc @ 00111200 size=1
// signature: undefined __xa_alloc(void)
// callers: [mem_buf_vm_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __xa_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 00111208 size=1
// signature: undefined cdev_init(void)
// callers: [mem_buf_vm_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_initialize @ 00111210 size=1
// signature: undefined device_initialize(void)
// callers: [mem_buf_vm_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_initialize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 00111218 size=1
// signature: undefined dev_set_name(void)
// callers: [mem_buf_vm_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xa_store @ 00111220 size=1
// signature: undefined xa_store(void)
// callers: [mem_buf_vm_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xa_store(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 00111228 size=1
// signature: undefined put_device(void)
// callers: [mem_buf_vm_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_device_add @ 00111230 size=1
// signature: undefined cdev_device_add(void)
// callers: [mem_buf_vm_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_device_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 00111238 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_mem_buf_alloc_info, trace_event_raw_event_relinquish_resp_class, trace_event_raw_event_lookup_sgl, trace_event_raw_event_alloc_req_msg_class, trace_event_raw_event_alloc_resp_class, trace_event_raw_event_map_mem_s2, trace_event_raw_event_relinquish_req_msg_class]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00111240 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [trace_event_raw_event_mem_buf_alloc_info, perf_trace_relinquish_req_msg_class, perf_trace_mem_buf_alloc_info, perf_trace_alloc_req_msg_class, perf_trace_relinquish_resp_class, trace_event_raw_event_relinquish_resp_class, trace_event_get_offsets_mem_buf_alloc_info, perf_trace_alloc_resp_class, trace_event_raw_event_alloc_req_msg_class, trace_event_raw_event_alloc_resp_class, trace_event_get_offsets_alloc_req_msg_class, trace_event_raw_event_relinquish_req_msg_class]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 00111248 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_mem_buf_alloc_info, trace_event_raw_event_relinquish_resp_class, trace_event_raw_event_lookup_sgl, trace_event_raw_event_alloc_req_msg_class, trace_event_raw_event_alloc_resp_class, trace_event_raw_event_map_mem_s2, trace_event_raw_event_relinquish_req_msg_class]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 00111250 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_mem_buf_alloc_info, trace_event_raw_event_relinquish_resp_class, trace_event_raw_event_lookup_sgl, trace_event_raw_event_alloc_req_msg_class, trace_event_raw_event_alloc_resp_class, trace_event_raw_event_map_mem_s2, trace_event_raw_event_relinquish_req_msg_class]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00111258 size=1
// signature: noreturn undefined fortify_panic(void)
// callers: [trace_event_raw_event_mem_buf_alloc_info, perf_trace_relinquish_req_msg_class, perf_trace_mem_buf_alloc_info, perf_trace_alloc_req_msg_class, perf_trace_relinquish_resp_class, trace_event_raw_event_relinquish_resp_class, trace_event_get_offsets_mem_buf_alloc_info, perf_trace_alloc_resp_class, trace_event_raw_event_alloc_req_msg_class, trace_event_raw_event_alloc_resp_class, trace_event_get_offsets_alloc_req_msg_class, trace_event_raw_event_relinquish_req_msg_class]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 00111260 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_relinquish_req_msg_class, perf_trace_mem_buf_alloc_info, perf_trace_alloc_req_msg_class, perf_trace_lookup_sgl, perf_trace_map_mem_s2, perf_trace_relinquish_resp_class, perf_trace_alloc_resp_class]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 00111268 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_relinquish_req_msg_class, perf_trace_mem_buf_alloc_info, perf_trace_alloc_req_msg_class, perf_trace_lookup_sgl, perf_trace_map_mem_s2, perf_trace_relinquish_resp_class, perf_trace_alloc_resp_class]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run4 @ 00111270 size=1
// signature: undefined bpf_trace_run4(void)
// callers: [__bpf_trace_mem_buf_alloc_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run1 @ 00111278 size=1
// signature: undefined bpf_trace_run1(void)
// callers: [__bpf_trace_relinquish_req_msg_class, __bpf_trace_relinquish_resp_class, __bpf_trace_alloc_req_msg_class, __bpf_trace_alloc_resp_class]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run3 @ 00111280 size=1
// signature: undefined bpf_trace_run3(void)
// callers: [__bpf_trace_lookup_sgl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run2 @ 00111288 size=1
// signature: undefined bpf_trace_run2(void)
// callers: [__bpf_trace_map_mem_s2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kvmalloc_node @ 00111290 size=1
// signature: undefined kvmalloc_node(void)
// callers: [mem_buf_sgt_to_gh_sgl_desc, dup_gh_sgl_desc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kvmalloc_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 001112a0 size=1
// signature: undefined __warn_printk(void)
// callers: [mem_buf_sgt_to_gh_sgl_desc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_alloc_table @ 001112a8 size=1
// signature: undefined sg_alloc_table(void)
// callers: [dup_gh_sgl_desc_to_sgt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_alloc_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_mem_accept @ 001112b0 size=1
// signature: undefined gh_rm_mem_accept(void)
// callers: [mem_buf_map_mem_s2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_mem_accept(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_mem_release @ 001112b8 size=1
// signature: undefined gh_rm_mem_release(void)
// callers: [mem_buf_map_mem_s2, mem_buf_unmap_mem_s2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_mem_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_free_table @ 001112c0 size=1
// signature: undefined sg_free_table(void)
// callers: [mem_buf_map_mem_s2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_free_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_mem_lend @ 001112e0 size=1
// signature: undefined ghd_rm_mem_lend(void)
// callers: [mem_buf_assign_mem_gunyah]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_mem_lend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_mem_donate @ 001112e8 size=1
// signature: undefined gh_rm_mem_donate(void)
// callers: [mem_buf_assign_mem_gunyah]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_mem_donate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_mem_share @ 001112f0 size=1
// signature: undefined ghd_rm_mem_share(void)
// callers: [mem_buf_assign_mem_gunyah]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_mem_share(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_mem_reclaim @ 001112f8 size=1
// signature: undefined ghd_rm_mem_reclaim(void)
// callers: [mem_buf_unassign_mem_gunyah]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_mem_reclaim(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_raw_output_prep @ 00111300 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_mem_buf_alloc_info, trace_raw_output_alloc_resp_class, trace_raw_output_relinquish_resp_class, trace_raw_output_map_mem_s2, trace_raw_output_relinquish_req_msg_class, trace_raw_output_lookup_sgl, trace_raw_output_alloc_req_msg_class]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_print_array_seq @ 00111308 size=1
// signature: undefined trace_print_array_seq(void)
// callers: [trace_raw_output_mem_buf_alloc_info, trace_raw_output_map_mem_s2, trace_raw_output_lookup_sgl, trace_raw_output_alloc_req_msg_class]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_print_array_seq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 00111310 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_mem_buf_alloc_info, trace_raw_output_alloc_resp_class, trace_raw_output_relinquish_resp_class, trace_raw_output_map_mem_s2, trace_raw_output_relinquish_req_msg_class, trace_raw_output_lookup_sgl, trace_raw_output_alloc_req_msg_class]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 00111318 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_mem_buf_alloc_info, trace_raw_output_alloc_resp_class, trace_raw_output_relinquish_resp_class, trace_raw_output_map_mem_s2, trace_raw_output_relinquish_req_msg_class, trace_raw_output_lookup_sgl, trace_raw_output_alloc_req_msg_class]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



