// Decompiled by Ghidra 12.2
// Program: gh_rm_drv.ko
// Image base: 00100000

//------------------------------------------------------------
// gh_get_image_name @ 00101c3c size=240
// signature: undefined gh_get_image_name(void)
// callers: []
//------------------------------------------------------------

undefined4 gh_get_image_name(char *param_1)

{
  int iVar1;
  long lVar2;
  
  iVar1 = strcmp(param_1,"pvm");
  if (iVar1 == 0) {
    lVar2 = 0;
  }
  else {
    iVar1 = strcmp(param_1,"trustedvm");
    if (iVar1 == 0) {
      lVar2 = 1;
    }
    else {
      iVar1 = strcmp(param_1,"cpusys_vm");
      if (iVar1 == 0) {
        lVar2 = 2;
      }
      else {
        iVar1 = strcmp(param_1,"oem_vm");
        if (iVar1 == 0) {
          lVar2 = 3;
        }
        else {
          iVar1 = strcmp(param_1,"autoghgvm");
          if (iVar1 == 0) {
            lVar2 = 4;
          }
          else {
            iVar1 = strcmp(param_1,"autoghgvmlv");
            if (iVar1 != 0) {
              _printk(&DAT_00109bb8,param_1);
              return 7;
            }
            lVar2 = 5;
          }
        }
      }
    }
  }
  return (&vm_name_map)[lVar2 * 6];
}



//------------------------------------------------------------
// gh_get_vm_name @ 00101d30 size=228
// signature: undefined gh_get_vm_name(void)
// callers: [gh_rm_drv_probe, gh_rm_get_vm_id_info]
//------------------------------------------------------------

undefined4 gh_get_vm_name(char *param_1)

{
  int iVar1;
  long lVar2;
  
  if (*param_1 == '\0') {
    lVar2 = 0;
  }
  else {
    iVar1 = strcmp(param_1,"qcom,trustedvm");
    if (iVar1 == 0) {
      lVar2 = 1;
    }
    else {
      iVar1 = strcmp(param_1,"qcom,cpusysvm");
      if (iVar1 == 0) {
        lVar2 = 2;
      }
      else {
        iVar1 = strcmp(param_1,"qcom,oemvm");
        if (iVar1 == 0) {
          lVar2 = 3;
        }
        else {
          iVar1 = strcmp(param_1,"qcom,autoghgvm");
          if (iVar1 == 0) {
            lVar2 = 4;
          }
          else {
            iVar1 = strcmp(param_1,"qcom,autoghgvmlv");
            if (iVar1 != 0) {
              _printk(&DAT_0010ac4a,param_1);
              return 7;
            }
            lVar2 = 5;
          }
        }
      }
    }
  }
  return (&vm_name_map)[lVar2 * 6];
}



//------------------------------------------------------------
// gh_rm_register_notifier @ 00101e18 size=40
// signature: undefined gh_rm_register_notifier(void)
// callers: []
//------------------------------------------------------------

void gh_rm_register_notifier(undefined8 param_1)

{
  srcu_notifier_chain_register(&gh_rm_notifier,param_1);
  return;
}



//------------------------------------------------------------
// gh_rm_unregister_notifier @ 00101e44 size=40
// signature: undefined gh_rm_unregister_notifier(void)
// callers: []
//------------------------------------------------------------

void gh_rm_unregister_notifier(undefined8 param_1)

{
  srcu_notifier_chain_unregister(&gh_rm_notifier,param_1);
  return;
}



//------------------------------------------------------------
// gh_rm_virq_to_irq @ 00101e70 size=48
// signature: undefined gh_rm_virq_to_irq(void)
// callers: []
//------------------------------------------------------------

void gh_rm_virq_to_irq(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = 0;
  if (gh_rm_intc != 0) {
    lVar1 = gh_rm_intc + 0x18;
  }
  gh_get_irq(param_1,param_2,lVar1);
  return;
}



//------------------------------------------------------------
// gh_rm_irq_to_virq @ 00101ea4 size=88
// signature: undefined gh_rm_irq_to_virq(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_rm_irq_to_virq(undefined4 param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = irq_domain_get_irq_data(gh_rm_irq_domain,param_1);
  if (lVar1 == 0) {
    uVar2 = 0xffffffea;
  }
  else if (param_2 == (undefined4 *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    *param_2 = (int)*(undefined8 *)(lVar1 + 8);
  }
  return uVar2;
}



//------------------------------------------------------------
// gh_rm_get_vm_id_info @ 00101f00 size=464
// signature: undefined gh_rm_get_vm_id_info(void)
// callers: [gh_vm_status_nb_handler, gh_rm_drv_probe]
//------------------------------------------------------------

ulong gh_rm_get_vm_id_info(undefined8 param_1)

{
  long lVar1;
  undefined1 *puVar2;
  void *pvVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  undefined1 *puVar8;
  uint local_94;
  undefined8 local_90;
  void *local_88;
  void *local_80;
  void *local_78;
  void *local_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  local_78 = (void *)0x0;
  local_70 = (void *)0x0;
  local_88 = (void *)0x0;
  local_80 = (void *)0x0;
  local_90 = 0;
  local_94 = 0;
  puVar2 = (undefined1 *)gh_rm_vm_get_id(param_1,&local_94);
  if ((puVar2 == (undefined1 *)0x0) || ((undefined1 *)0xfffffffffffff000 < puVar2)) {
    uVar6 = (ulong)puVar2 & 0xffffffff;
    goto LAB_00102074;
  }
  if (local_94 == 0) {
LAB_00102044:
    pvVar3 = local_78;
    local_90 = CONCAT62(local_90._2_6_,(short)param_1);
    if ((local_78 == (void *)0x0) || (uVar4 = gh_get_vm_name(local_78), (int)uVar4 == 7)) {
      _printk(&DAT_00109de2,pvVar3,(uint)param_1 & 0xffff);
      uVar6 = 0xffffffea;
    }
    else {
      uVar6 = gh_update_vm_prop_table(uVar4,&local_90);
      uVar6 = uVar6 & 0xffffffff;
    }
  }
  else {
    uVar6 = 0;
    uVar7 = 0;
    puVar8 = puVar2;
    do {
      uVar5 = (ulong)*(ushort *)(puVar8 + 2);
      if ((*(ushort *)(puVar8 + 2) & 3) != 0) {
        uVar5 = uVar5 + 1;
      }
      pvVar3 = (void *)__kmalloc(uVar5,0xdc0);
      if (pvVar3 == (void *)0x0) {
        uVar6 = 0xfffffff4;
        goto LAB_0010206c;
      }
      memcpy(pvVar3,puVar8 + 4,(ulong)*(ushort *)(puVar8 + 2));
      switch(*puVar8) {
      case 0:
        local_88 = pvVar3;
        break;
      case 1:
        local_80 = pvVar3;
        break;
      case 2:
        local_78 = pvVar3;
        break;
      case 3:
        local_70 = pvVar3;
        break;
      default:
        _printk(&DAT_00109c85,"gh_rm_get_vm_id_info");
        kfree(pvVar3);
        uVar6 = 0xffffffea;
      }
      uVar7 = uVar7 + 1;
      puVar8 = puVar8 + 4 + ((ulong)*(ushort *)(puVar8 + 2) - 1 | 3) + 1;
    } while (uVar7 < local_94);
    if ((int)uVar6 == 0) goto LAB_00102044;
  }
LAB_0010206c:
  kfree(puVar2);
LAB_00102074:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// gh_rm_populate_hyp_res @ 001020d4 size=1076
// signature: undefined gh_rm_populate_hyp_res(void)
// callers: [gh_vm_status_nb_handler, gh_rm_drv_probe, gh_rm_get_svm_res_work_fn]
//------------------------------------------------------------

ulong gh_rm_populate_hyp_res(ulong param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  undefined8 uVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  byte *pbVar13;
  undefined8 uVar14;
  ulong uVar15;
  ulong uVar16;
  uint local_6c;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  uVar9 = param_1 & 0xffffffff;
  local_6c = 0;
  uVar5 = gh_rm_vm_get_hyp_res(param_1,&local_6c);
  if ((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) {
    uVar16 = uVar5 & 0xffffffff;
  }
  else {
    if (local_6c == 0) {
      uVar15 = 0;
    }
    else {
      uVar10 = 0;
      uVar15 = 0;
      do {
        if (*(char *)(uVar5 + uVar10 * 0x2c) == '\x04') {
          lVar8 = uVar5 + uVar10 * 0x2c;
          iVar1 = *(int *)(lVar8 + 0x18);
          if (*(int *)(lVar8 + 0x14) == 0 && iVar1 == 0 || iVar1 == -1) {
            uVar16 = 0;
          }
          else {
            lVar8 = 0;
            if (gh_rm_intc != 0) {
              lVar8 = gh_rm_intc + 0x18;
            }
            uVar15 = gh_get_irq(iVar1,1,lVar8);
            uVar16 = uVar15 & 0xffffffff;
            if ((int)uVar15 < 0) goto LAB_001024a4;
          }
          uVar15 = uVar16;
          if (gh_vcpu_affinity_set_fn != (code *)0x0) {
            lVar8 = uVar5 + uVar10 * 0x2c;
            uVar11 = *(undefined8 *)(lVar8 + 0xc);
            uVar2 = *(undefined4 *)(lVar8 + 8);
            do {
              if (*(int *)(gh_vcpu_affinity_set_fn + -4) != -0x5e3b4b5d) {
                    /* WARNING: Does not return */
                pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1021e8);
                (*pcVar3)();
              }
              uVar4 = (*gh_vcpu_affinity_set_fn)(uVar9,uVar2,uVar11,uVar16);
            } while (uVar4 == 0xfffffff5);
            uVar16 = (ulong)uVar4;
            uVar15 = uVar16;
            if ((int)uVar4 < 0) goto LAB_001024a4;
          }
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < local_6c);
      if (local_6c != 0) {
        uVar10 = 0;
        do {
          pbVar13 = (byte *)(uVar5 + uVar10 * 0x2c);
          iVar1 = *(int *)(pbVar13 + 0x18);
          if (*(int *)(pbVar13 + 0x14) == 0 && iVar1 == 0 || iVar1 == -1) {
            uVar15 = 0;
          }
          else {
            lVar8 = 0;
            if (gh_rm_intc != 0) {
              lVar8 = gh_rm_intc + 0x18;
            }
            uVar6 = gh_get_irq(iVar1,1,lVar8);
            uVar15 = uVar6 & 0xffffffff;
            uVar16 = uVar6 & 0xffffffff;
            if ((int)uVar6 < 0) goto LAB_001024a4;
          }
          if (8 < *pbVar13) {
switchD_001022c0_caseD_7:
            _printk(&DAT_00109f5f,"gh_rm_populate_hyp_res");
            uVar16 = 0xffffffea;
            goto LAB_001024a4;
          }
          lVar8 = uVar5 + uVar10 * 0x2c;
          uVar11 = *(undefined8 *)(lVar8 + 0x1c);
          uVar12 = *(undefined8 *)(lVar8 + 0xc);
          uVar14 = *(undefined8 *)(lVar8 + 0x24);
          uVar2 = *(undefined4 *)(lVar8 + 8);
          switch(*pbVar13) {
          case 0:
switchD_001022c0_caseD_0:
            uVar7 = 0;
LAB_001023c4:
            uVar16 = gh_dbl_populate_cap_info(uVar2,uVar12,uVar7,uVar15);
LAB_001023e4:
            uVar16 = uVar16 & 0xffffffff;
switchD_0010240c_caseD_4:
            if ((int)uVar16 != -0xb) {
              uVar15 = uVar16;
              if (-1 < (int)uVar16) break;
              goto LAB_001024a4;
            }
            uVar16 = 0xfffffff5;
            switch(*pbVar13) {
            case 0:
              goto switchD_001022c0_caseD_0;
            case 1:
              goto switchD_001022c0_caseD_1;
            case 2:
              goto switchD_001022c0_caseD_2;
            case 3:
              goto switchD_001022c0_caseD_3;
            case 4:
              goto switchD_0010240c_caseD_4;
            case 5:
              if (gh_vpm_grp_set_fn != (code *)0x0) goto LAB_001022e0;
              goto switchD_0010240c_caseD_4;
            case 6:
              mutex_lock(gh_virtio_mmio_fn_lock);
              if (gh_virtio_mmio_fn == (code *)0x0) {
                mutex_unlock(gh_virtio_mmio_fn_lock);
                uVar16 = 0xfffffff5;
              }
              else {
LAB_00102328:
                if (*(int *)(gh_virtio_mmio_fn + -4) != -0x1543a734) {
                    /* WARNING: Does not return */
                  pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102358);
                  (*pcVar3)();
                }
                uVar16 = (*gh_virtio_mmio_fn)(uVar9,param_2,uVar2,uVar12,uVar15,uVar11,uVar14);
                uVar16 = uVar16 & 0xffffffff;
                mutex_unlock(gh_virtio_mmio_fn_lock);
              }
              goto switchD_0010240c_caseD_4;
            default:
              goto switchD_001022c0_caseD_7;
            case 8:
              if (gh_wdog_manage_fn != (code *)0x0) goto LAB_0010238c;
              goto switchD_0010240c_caseD_4;
            }
          case 1:
            goto switchD_001022c0_caseD_1;
          case 2:
            goto switchD_001022c0_caseD_2;
          case 3:
            goto switchD_001022c0_caseD_3;
          case 5:
            if (gh_vpm_grp_set_fn != (code *)0x0) goto LAB_001022e0;
            break;
          case 6:
            mutex_lock(gh_virtio_mmio_fn_lock);
            if (gh_virtio_mmio_fn != (code *)0x0) goto LAB_00102328;
            mutex_unlock(gh_virtio_mmio_fn_lock);
            break;
          case 7:
            goto switchD_001022c0_caseD_7;
          case 8:
            if (gh_wdog_manage_fn != (code *)0x0) goto LAB_0010238c;
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < local_6c);
      }
    }
    if (gh_all_res_populated_fn != (code *)0x0) {
      if (*(int *)(gh_all_res_populated_fn + -4) != 0x4b323aad) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10249c);
        (*pcVar3)();
      }
      (*gh_all_res_populated_fn)(uVar9,1);
    }
    uVar16 = uVar15;
LAB_001024a4:
    kfree(uVar5);
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar16;
LAB_0010238c:
  if (*(int *)(gh_wdog_manage_fn + -4) != 0x1dd5c40d) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1023b0);
    (*pcVar3)();
  }
  uVar16 = (*gh_wdog_manage_fn)(uVar9,uVar12,1);
  goto LAB_001023e4;
LAB_001022e0:
  if (*(int *)(gh_vpm_grp_set_fn + -4) != -0x13628736) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102304);
    (*pcVar3)();
  }
  uVar16 = (*gh_vpm_grp_set_fn)(uVar9,uVar12,uVar15);
  goto LAB_001023e4;
switchD_001022c0_caseD_3:
  uVar7 = 1;
  goto LAB_001023dc;
switchD_001022c0_caseD_2:
  uVar7 = 0;
LAB_001023dc:
  uVar16 = gh_msgq_populate_cap_info(uVar2,uVar12,uVar7,uVar15);
  goto LAB_001023e4;
switchD_001022c0_caseD_1:
  uVar7 = 1;
  goto LAB_001023c4;
}



//------------------------------------------------------------
// gh_rm_unpopulate_hyp_res @ 0010250c size=608
// signature: undefined gh_rm_unpopulate_hyp_res(void)
// callers: []
//------------------------------------------------------------

ulong gh_rm_unpopulate_hyp_res(ulong param_1)

{
  undefined4 uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  undefined8 *puVar10;
  int local_70;
  uint local_6c;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  uVar7 = param_1 & 0xffffffff;
  local_70 = -1;
  local_6c = 0;
  uVar5 = gh_rm_vm_get_hyp_res(param_1,&local_6c);
  if ((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) {
    uVar8 = uVar5 & 0xffffffff;
  }
  else {
    if (local_6c == 0) {
      uVar8 = 0;
    }
    else {
      uVar9 = 0;
      uVar8 = 0;
      puVar10 = (undefined8 *)(uVar5 + 0xc);
      do {
        if (8 < *(byte *)((long)puVar10 + -0xc)) {
switchD_001025c0_caseD_7:
          _printk(&DAT_00109f5f,"gh_rm_unpopulate_hyp_res");
          uVar8 = 0xffffffea;
          goto LAB_00102708;
        }
        uVar1 = *(undefined4 *)((long)puVar10 + -4);
        switch(*(byte *)((long)puVar10 + -0xc)) {
        case 0:
          uVar6 = gh_dbl_reset_cap_info(uVar1,0,&local_70);
          goto LAB_001026a8;
        case 1:
          uVar6 = gh_dbl_reset_cap_info(uVar1,1,&local_70);
          goto LAB_001026a8;
        case 2:
          uVar6 = gh_msgq_reset_cap_info(uVar1,0,&local_70);
          goto LAB_001026a8;
        case 3:
          uVar6 = gh_msgq_reset_cap_info(uVar1,1,&local_70);
LAB_001026a8:
          uVar8 = uVar6 & 0xffffffff;
          if ((int)uVar6 < 0) goto LAB_00102708;
          break;
        case 4:
          if (gh_vcpu_affinity_reset_fn != (code *)0x0) {
            if (*(int *)(gh_vcpu_affinity_reset_fn + -4) != -0x1dbb8264) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x102640);
              (*pcVar3)();
            }
            uVar6 = (*gh_vcpu_affinity_reset_fn)(uVar7,uVar1,*puVar10,&local_70);
            goto LAB_001026a8;
          }
          break;
        case 5:
          if (gh_vpm_grp_reset_fn != (code *)0x0) {
            if (*(int *)(gh_vpm_grp_reset_fn + -4) != -0xeb6d44a) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102670);
              (*pcVar3)();
            }
            uVar6 = (*gh_vpm_grp_reset_fn)(uVar7,&local_70);
            goto LAB_001026a8;
          }
          break;
        case 7:
          goto switchD_001025c0_caseD_7;
        case 8:
          if (gh_wdog_manage_fn != (code *)0x0) {
            if (*(int *)(gh_wdog_manage_fn + -4) != 0x1dd5c40d) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x1026a4);
              (*pcVar3)();
            }
            uVar6 = (*gh_wdog_manage_fn)(uVar7,*puVar10,0);
            goto LAB_001026a8;
          }
        }
        if ((-1 < local_70) && (iVar4 = gh_put_irq(), iVar4 == 0)) {
          gh_rm_vm_irq_release(*(undefined4 *)(puVar10 + 1));
        }
        uVar9 = uVar9 + 1;
        puVar10 = (undefined8 *)((long)puVar10 + 0x2c);
      } while (uVar9 < local_6c);
    }
    if (gh_all_res_populated_fn != (code *)0x0) {
      if (*(int *)(gh_all_res_populated_fn + -4) != 0x4b323aad) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102704);
        (*pcVar3)();
      }
      (*gh_all_res_populated_fn)(uVar7,0);
    }
LAB_00102708:
    kfree(uVar5);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



//------------------------------------------------------------
// gh_rm_set_virtio_mmio_cb @ 00102770 size=104
// signature: undefined gh_rm_set_virtio_mmio_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_rm_set_virtio_mmio_cb(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    mutex_lock(gh_virtio_mmio_fn_lock);
    if (gh_virtio_mmio_fn == 0) {
      uVar1 = 0;
      gh_virtio_mmio_fn = param_1;
    }
    else {
      uVar1 = 0xfffffff0;
    }
    mutex_unlock(gh_virtio_mmio_fn_lock);
  }
  return uVar1;
}



//------------------------------------------------------------
// gh_rm_unset_virtio_mmio_cb @ 001027dc size=64
// signature: undefined gh_rm_unset_virtio_mmio_cb(void)
// callers: []
//------------------------------------------------------------

void gh_rm_unset_virtio_mmio_cb(void)

{
  mutex_lock(gh_virtio_mmio_fn_lock);
  gh_virtio_mmio_fn = 0;
  mutex_unlock(gh_virtio_mmio_fn_lock);
  return;
}



//------------------------------------------------------------
// gh_rm_set_wdog_manage_cb @ 00102820 size=48
// signature: undefined gh_rm_set_wdog_manage_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_rm_set_wdog_manage_cb(long param_1)

{
  if (param_1 == 0) {
    return 0xffffffea;
  }
  if (gh_wdog_manage_fn == 0) {
    gh_wdog_manage_fn = param_1;
    return 0;
  }
  return 0xfffffff0;
}



//------------------------------------------------------------
// gh_rm_set_vcpu_affinity_cb @ 00102854 size=48
// signature: undefined gh_rm_set_vcpu_affinity_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_rm_set_vcpu_affinity_cb(long param_1)

{
  if (param_1 == 0) {
    return 0xffffffea;
  }
  if (gh_vcpu_affinity_set_fn == 0) {
    gh_vcpu_affinity_set_fn = param_1;
    return 0;
  }
  return 0xfffffff0;
}



//------------------------------------------------------------
// gh_rm_reset_vcpu_affinity_cb @ 00102888 size=48
// signature: undefined gh_rm_reset_vcpu_affinity_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_rm_reset_vcpu_affinity_cb(long param_1)

{
  if (param_1 == 0) {
    return 0xffffffea;
  }
  if (gh_vcpu_affinity_reset_fn == 0) {
    gh_vcpu_affinity_reset_fn = param_1;
    return 0;
  }
  return 0xfffffff0;
}



//------------------------------------------------------------
// gh_rm_set_vpm_grp_cb @ 001028bc size=48
// signature: undefined gh_rm_set_vpm_grp_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_rm_set_vpm_grp_cb(long param_1)

{
  if (param_1 == 0) {
    return 0xffffffea;
  }
  if (gh_vpm_grp_set_fn == 0) {
    gh_vpm_grp_set_fn = param_1;
    return 0;
  }
  return 0xfffffff0;
}



//------------------------------------------------------------
// gh_rm_reset_vpm_grp_cb @ 001028f0 size=48
// signature: undefined gh_rm_reset_vpm_grp_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_rm_reset_vpm_grp_cb(long param_1)

{
  if (param_1 == 0) {
    return 0xffffffea;
  }
  if (gh_vpm_grp_reset_fn == 0) {
    gh_vpm_grp_reset_fn = param_1;
    return 0;
  }
  return 0xfffffff0;
}



//------------------------------------------------------------
// gh_rm_all_res_populated_cb @ 00102924 size=48
// signature: undefined gh_rm_all_res_populated_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_rm_all_res_populated_cb(long param_1)

{
  if (param_1 == 0) {
    return 0xffffffea;
  }
  if (gh_all_res_populated_fn == 0) {
    gh_all_res_populated_fn = param_1;
    return 0;
  }
  return 0xfffffff0;
}



//------------------------------------------------------------
// gh_rm_drv_probe @ 00102958 size=1408
// signature: undefined gh_rm_drv_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int gh_rm_drv_probe(long param_1)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  ulong uVar7;
  size_t sVar8;
  char *pcVar9;
  long lVar10;
  undefined8 uVar11;
  long lVar12;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined4 local_d0;
  undefined2 local_cc [2];
  long local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
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
  local_68 = *(long *)(lVar10 + 0x638);
  rm = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  lVar10 = *(long *)(*(long *)(param_1 + 0x60) + 0x2e8);
  if (rm == 0) {
    _dev_err(param_1,"Failed to get the rm pointer\n");
  }
  iVar3 = of_property_read_variable_u32_array(lVar10,"qcom,free-irq-start",&gh_rm_base_virq,1,0);
  if (iVar3 < 0) {
    pcVar9 = "Failed to get the vIRQ base\n";
  }
  else {
    gh_rm_intc = of_irq_find_parent(lVar10);
    if (gh_rm_intc != 0) {
      lVar12 = gh_rm_intc + 0x18;
      local_88 = 0;
      uStack_80 = 0;
      local_98 = 0;
      uStack_90 = 0;
      local_a8 = 0;
      uStack_a0 = 0;
      local_b8 = 0;
      local_b0 = 0;
      local_c0 = 0;
      local_c8 = lVar12;
      lVar6 = irq_find_matching_fwspec(&local_c8,1);
      if (lVar6 == 0) {
        local_88 = 0;
        uStack_80 = 0;
        local_98 = 0;
        uStack_90 = 0;
        local_a8 = 0;
        uStack_a0 = 0;
        local_b8 = 0;
        local_b0 = 0;
        local_c0 = 0;
        local_c8 = lVar12;
        gh_rm_irq_domain = irq_find_matching_fwspec(&local_c8,0);
        if (gh_rm_irq_domain == 0) {
          pcVar9 = "Failed to get IRQ domain associated with RM\n";
          goto LAB_00102ec0;
        }
      }
      else {
        gh_rm_irq_domain = lVar6;
      }
      iVar3 = gh_rm_notifier_register(rm,&gh_rm_core_notifier_blk);
      if (iVar3 == 0) {
        uVar11 = *(undefined8 *)(lVar10 + 0x70);
        local_b0 = 0;
        local_a8 = 0;
        local_c0 = 0;
        local_b8 = 0;
        local_c8 = 0;
        local_100 = 0;
        local_f8 = 0;
        gh_init_vm_prop_table();
        uVar7 = of_find_compatible_node(uVar11,0,"qcom,gunyah-vm-id-1.0");
        if (((uVar7 == 0) || (0xfffffffffffff000 < uVar7)) &&
           ((uVar7 = of_find_compatible_node(uVar11,0,"qcom,haven-vm-id-1.0"), uVar7 == 0 ||
            (0xfffffffffffff000 < uVar7)))) {
          _dev_err(param_1,"Could not find vm-id node\n");
        }
        else {
          iVar3 = of_property_read_variable_u32_array(uVar7,"qcom,vmid",(long)&local_f8 + 4,1,0);
          if (iVar3 < 0) {
            _dev_err(param_1,"Could not read vmid: %d\n",iVar3);
            if (iVar3 != -0x13) goto LAB_00102e68;
          }
          else {
            iVar3 = of_property_read_variable_u32_array(uVar7,"qcom,owner-vmid",&local_f8,1,0);
            if (iVar3 < 0) {
              local_c8 = CONCAT62(local_c8._2_6_,(short)((ulong)local_f8 >> 0x20));
              gh_update_vm_prop_table(1,&local_c8);
              gh_rm_core_initialized = 1;
            }
            else {
              iVar4 = of_property_read_string(uVar7,"qcom,image-name",&local_100);
              iVar3 = 2;
              if (iVar4 == 0) {
                iVar4 = gh_get_vm_name(local_100);
                iVar3 = 2;
                if (iVar4 != 7) {
                  iVar3 = iVar4;
                }
              }
              local_c8._0_2_ = (short)((ulong)local_f8 >> 0x20);
              gh_update_vm_prop_table(iVar3,&local_c8);
              local_c8 = CONCAT62(local_c8._2_6_,(short)local_f8);
              gh_update_vm_prop_table(1,&local_c8);
              local_cc[0] = 0;
              local_d0 = 0;
              local_e0 = 0;
              uStack_d8 = 0;
              local_f0 = 0;
              uStack_e8 = 0;
              local_78 = 0;
              uStack_70 = 0;
              uVar5 = of_property_read_string_helper(uVar7,"qcom,peers",0,0,0);
              if ((int)uVar5 < 0) {
                _dev_info(param_1,"No qcom,peers found\n");
              }
              else {
                uVar1 = (ulong)uVar5 * 8;
                lVar10 = __kmalloc(uVar1,0xdc0);
                if (lVar10 == 0) {
                  _dev_err(param_1,"Failed to allocate memory\n");
                }
                else {
                  iVar3 = of_property_read_string_helper(uVar7,"qcom,peers",lVar10,(ulong)uVar5,0);
                  if (iVar3 < 0) {
                    _dev_err(param_1,"Failed to find qcom,peers\n");
                  }
                  else if (uVar5 != 0) {
                    uVar7 = 0;
                    do {
                      if ((uVar1 == uVar7) || (uVar1 <= uVar7)) {
                    /* WARNING: Does not return */
                        pcVar2 = (code *)SoftwareBreakpoint(1,0x102ed4);
                        (*pcVar2)();
                      }
                      lVar12 = *(long *)(lVar10 + uVar7);
                      if (lVar12 != 0) {
                        lVar6 = strnstr(lVar12,"vm-name:",8);
                        if (lVar6 == 0) {
                          lVar6 = strnstr(lVar12,"vm-uri:",7);
                          if (lVar6 != 0) {
                            pcVar9 = (char *)(lVar12 + 7);
                            sVar8 = strlen(pcVar9);
                            uVar11 = 1;
                            goto LAB_00102c70;
                          }
                          lVar6 = strnstr(lVar12,"vm-guid:",8);
                          if (lVar6 == 0) {
                            _dev_err(param_1,"Unknown peer type:%s\n",lVar12);
                            goto LAB_00102bf0;
                          }
                          iVar3 = uuid_parse(lVar12 + 8,&local_78);
                          if (iVar3 == 0) {
                            pcVar9 = (char *)&local_78;
                            uVar11 = 2;
                            sVar8 = 0x10;
                            goto LAB_00102c70;
                          }
                          _dev_err(param_1,"Invalid GUID:%s\n",lVar12 + 8);
                        }
                        else {
                          pcVar9 = (char *)(lVar12 + 8);
                          sVar8 = strlen(pcVar9);
                          uVar11 = 0;
LAB_00102c70:
                          iVar3 = gh_rm_vm_lookup(uVar11,pcVar9,sVar8,local_cc);
                        }
                        if (iVar3 < 0) {
                          _dev_err(param_1,"lookup %s failed, VM is not running ret=%d\n",lVar12,
                                   iVar3);
                        }
                        else {
                          iVar3 = gh_rm_get_vm_id_info(local_cc[0]);
                          if ((iVar3 < 0) ||
                             (iVar3 = gh_rm_get_vm_name(local_cc[0],&local_d0), iVar3 < 0)) {
                            pcVar9 = "Failed to get vmid info for vmid = %d ret = %d\n";
                          }
                          else {
                            gh_rm_get_vminfo(local_d0,&local_f0);
                            iVar3 = gh_rm_populate_hyp_res(local_cc[0],local_e0);
                            if (-1 < iVar3) goto LAB_00102bf0;
                            pcVar9 = "Failed to get hyp resources for vmid = %d ret = %d\n";
                          }
                          _dev_err(param_1,pcVar9,local_cc[0],iVar3);
                        }
                      }
LAB_00102bf0:
                      uVar7 = uVar7 + 8;
                    } while (uVar1 != uVar7);
                  }
                  kfree(lVar10);
                }
              }
              srcu_notifier_chain_register(&gh_rm_notifier,&gh_vm_status_nb);
              gh_rm_core_initialized = 1;
              queue_work_on(0x20,_system_wq,gh_rm_get_svm_res_work);
            }
          }
        }
        iVar3 = 0;
      }
      else {
        _dev_err(param_1,"Failed to register to RM notifier %d\n",iVar3);
      }
      goto LAB_00102e68;
    }
    pcVar9 = "Failed to get the IRQ parent node\n";
  }
LAB_00102ec0:
  _dev_err(param_1,pcVar9);
  iVar3 = -6;
LAB_00102e68:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// gh_rm_drv_remove @ 00102edc size=56
// signature: undefined gh_rm_drv_remove(void)
// callers: []
//------------------------------------------------------------

void gh_rm_drv_remove(void)

{
  gh_rm_notifier_unregister(rm,&gh_rm_core_notifier_blk);
  idr_destroy(gh_rm_call_idr);
  return;
}



//------------------------------------------------------------
// gh_rm_core_notifier_call @ 00102f18 size=36
// signature: undefined gh_rm_core_notifier_call(void)
// callers: []
//------------------------------------------------------------

void gh_rm_core_notifier_call(void)

{
  srcu_notifier_call_chain(&gh_rm_notifier);
  return;
}



//------------------------------------------------------------
// gh_vm_status_nb_handler @ 00102f40 size=340
// signature: undefined gh_vm_status_nb_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_vm_status_nb_handler(undefined8 param_1,long param_2,undefined2 *param_3)

{
  byte bVar1;
  long lVar2;
  int iVar3;
  undefined *puVar4;
  undefined2 uVar5;
  uint uVar6;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_4c = 0;
  if (param_2 == 0x56100008) {
    bVar1 = *(byte *)(param_3 + 2);
    uVar6 = (uint)bVar1;
    if (bVar1 == 3) {
      _printk(&DAT_00109b54,*param_3);
    }
    else {
      if (bVar1 == 2) {
        _printk(&DAT_0010abf2,*param_3);
        uVar6 = gh_rm_get_vm_id_info(*param_3);
        uVar5 = *param_3;
        if ((int)uVar6 < 0) {
          puVar4 = &DAT_0010a7ab;
        }
        else {
          uVar6 = gh_rm_get_vm_name(uVar5,&local_4c);
          if (-1 < (int)uVar6) {
            iVar3 = gh_rm_get_vminfo(local_4c,&local_48);
            if (iVar3 < 0) {
              _printk(&DAT_0010acd6,local_4c);
            }
            iVar3 = gh_rm_populate_hyp_res(*param_3,local_38);
            if (iVar3 < 0) {
              _printk(&DAT_0010ab00,*param_3,local_4c,iVar3);
            }
            goto LAB_00102f7c;
          }
          uVar5 = *param_3;
          puVar4 = &DAT_0010a260;
        }
      }
      else {
        uVar5 = *param_3;
        puVar4 = &DAT_0010a489;
      }
      _printk(puVar4,uVar5,uVar6);
    }
  }
LAB_00102f7c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// gh_rm_get_svm_res_work_fn @ 00103098 size=128
// signature: undefined gh_rm_get_svm_res_work_fn(void)
// callers: []
//------------------------------------------------------------

void gh_rm_get_svm_res_work_fn(void)

{
  long lVar1;
  int iVar2;
  undefined2 local_1c [2];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  iVar2 = ghd_rm_get_vmid(1,local_1c);
  if (iVar2 == 0) {
    gh_rm_populate_hyp_res(local_1c[0],0);
  }
  else {
    _printk(&DAT_0010ab42,"gh_rm_get_svm_res_work_fn",1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __traceiter_gh_rm_mem_accept @ 0010311c size=204
// signature: undefined __traceiter_gh_rm_mem_accept(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_gh_rm_mem_accept
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined2 param_9,undefined1 param_10)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_0010ccb0;
  plVar2 = DAT_0010ccb0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x68b5ee40) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1031b4);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_gh_rm_mem_donate @ 001031ec size=204
// signature: undefined __traceiter_gh_rm_mem_donate(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_gh_rm_mem_donate
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined2 param_9,undefined1 param_10)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0010ccf8;
  plVar2 = _DAT_0010ccf8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x68b5ee40) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103284);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_gh_rm_mem_lend @ 001032bc size=204
// signature: undefined __traceiter_gh_rm_mem_lend(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_gh_rm_mem_lend
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined2 param_9,undefined1 param_10)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0010cd40;
  plVar2 = _DAT_0010cd40;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x68b5ee40) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103354);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_gh_rm_mem_share @ 0010338c size=204
// signature: undefined __traceiter_gh_rm_mem_share(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_gh_rm_mem_share
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined2 param_9,undefined1 param_10)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0010cd88;
  plVar2 = _DAT_0010cd88;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x68b5ee40) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103424);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_gh_rm_mem_accept_reply @ 0010345c size=100
// signature: undefined __traceiter_gh_rm_mem_accept_reply(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_gh_rm_mem_accept_reply(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0010cdd0;
  plVar2 = _DAT_0010cdd0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x182fa0e6) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1034a0);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_gh_rm_mem_release @ 001034c4 size=116
// signature: undefined __traceiter_gh_rm_mem_release(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_gh_rm_mem_release(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0010ce18;
  plVar2 = _DAT_0010ce18;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x25e39c2e) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103514);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_gh_rm_mem_reclaim @ 0010353c size=116
// signature: undefined __traceiter_gh_rm_mem_reclaim(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_gh_rm_mem_reclaim(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0010ce60;
  plVar2 = _DAT_0010ce60;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x25e39c2e) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10358c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_gh_rm_mem_call_return @ 001035b4 size=116
// signature: undefined __traceiter_gh_rm_mem_call_return(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_gh_rm_mem_call_return(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0010cea8;
  plVar2 = _DAT_0010cea8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x10c2814e) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103604);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_gh_rm_mem_notify @ 0010362c size=140
// signature: undefined __traceiter_gh_rm_mem_notify(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_gh_rm_mem_notify
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined8 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0010cef0;
  plVar2 = _DAT_0010cef0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x35c33f36) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103690);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_gh_rm_mem_accept_donate_lend_share @ 001036bc size=724
// signature: undefined trace_event_raw_event_gh_rm_mem_accept_donate_lend_share(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_gh_rm_mem_accept_donate_lend_share
               (long param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,int *param_5,
               ushort *param_6,ushort *param_7,undefined4 *param_8,undefined2 param_9,
               undefined1 param_10)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  ushort uVar5;
  uint uVar6;
  long lVar7;
  int iVar8;
  uint uVar9;
  ulong uVar10;
  ushort *puVar11;
  undefined1 *puVar12;
  long lVar13;
  ulong uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) != 0) &&
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) == 0)) &&
     (uVar14 = __trace_trigger_soft_disabled(param_1), (uVar14 & 1) != 0)) goto LAB_00103930;
  uVar14 = 0x40;
  if (param_5 == (int *)0x0) {
    iVar17 = 0;
    iVar15 = 0;
    iVar8 = 0;
    if (param_6 == (ushort *)0x0) goto LAB_00103778;
LAB_0010373c:
    uVar5 = *param_6;
    uVar6 = 0x200000;
    if (uVar5 < 5) {
      uVar6 = (uint)uVar5 << 0x13;
    }
    uVar6 = uVar6 | iVar8 + 0x40U;
    iVar18 = 0x20;
    if (uVar5 < 5) {
      iVar18 = (uint)uVar5 << 3;
    }
  }
  else {
    iVar15 = *param_5;
    iVar17 = iVar15 * 2;
    uVar14 = (ulong)(iVar15 << 0x11 | 0x40);
    iVar8 = iVar15 * 3;
    if (param_6 != (ushort *)0x0) goto LAB_0010373c;
LAB_00103778:
    iVar18 = 0;
    uVar6 = iVar8 + 0x40;
  }
  iVar3 = iVar18 + iVar8 + iVar18;
  if (param_7 == (ushort *)0x0) {
    iVar19 = 0;
    uVar16 = iVar3 + 0x40;
  }
  else {
    iVar19 = (uint)*param_7 << 1;
    uVar16 = iVar3 + 0x40U | (uint)*param_7 << 0x11;
  }
  lVar7 = trace_event_buffer_reserve(&local_98,param_1,(long)(iVar19 + iVar3 + iVar19) + 0x40);
  if (lVar7 == 0) goto LAB_00103930;
  uVar1 = iVar19 + iVar3 + 0x40;
  uVar2 = iVar18 + iVar8 + 0x40;
  *(int *)(lVar7 + 0x14) = (int)uVar14;
  *(uint *)(lVar7 + 0x18) = iVar17 + 0x40U | iVar15 << 0x10;
  *(uint *)(lVar7 + 0x20) = uVar6;
  *(uint *)(lVar7 + 0x24) = uVar2 | iVar18 << 0x10;
  *(uint *)(lVar7 + 0x2c) = uVar16;
  *(uint *)(lVar7 + 0x30) = uVar1 | iVar19 << 0x10;
  *(undefined1 *)(lVar7 + 8) = param_2;
  *(undefined1 *)(lVar7 + 9) = param_3;
  *(undefined4 *)(lVar7 + 0xc) = param_4;
  if (param_5 == (int *)0x0) {
    *(undefined4 *)(lVar7 + 0x10) = 0;
    if (param_6 == (ushort *)0x0) goto LAB_001038b8;
LAB_0010385c:
    uVar5 = *param_6;
    *(ushort *)(lVar7 + 0x1c) = uVar5;
    uVar9 = (uint)uVar5;
    if (3 < uVar5) {
      uVar9 = 4;
    }
    *(uint *)(lVar7 + 0x3c) = uVar9;
    if (uVar9 != 0) {
      uVar14 = 0;
      puVar11 = param_6 + 6;
      do {
        lVar13 = uVar14 * 8;
        uVar14 = uVar14 + 1;
        *(undefined8 *)(lVar7 + ((ulong)uVar6 & 0xffff) + lVar13) = *(undefined8 *)(puVar11 + -4);
        *(undefined8 *)(lVar7 + (ulong)(ushort)uVar2 + lVar13) = *(undefined8 *)puVar11;
        puVar11 = puVar11 + 8;
      } while (uVar14 < *(uint *)(lVar7 + 0x3c));
    }
  }
  else {
    iVar8 = *param_5;
    *(int *)(lVar7 + 0x10) = iVar8;
    if (iVar8 != 0) {
      uVar10 = 0;
      puVar12 = (undefined1 *)((long)param_5 + 6);
      do {
        *(undefined2 *)(lVar7 + (uVar14 & 0xffff) + uVar10 * 2) = *(undefined2 *)(puVar12 + -2);
        *(undefined1 *)(lVar7 + (ulong)(ushort)(iVar17 + 0x40U) + uVar10) = *puVar12;
        uVar10 = uVar10 + 1;
        puVar12 = puVar12 + 4;
      } while (uVar10 < *(uint *)(lVar7 + 0x10));
    }
    if (param_6 != (ushort *)0x0) goto LAB_0010385c;
LAB_001038b8:
    *(undefined2 *)(lVar7 + 0x1c) = 0;
    *(undefined4 *)(lVar7 + 0x3c) = 0;
  }
  if (param_7 == (ushort *)0x0) {
    *(undefined2 *)(lVar7 + 0x28) = 0;
  }
  else {
    uVar5 = *param_7;
    *(ushort *)(lVar7 + 0x28) = uVar5;
    if (uVar5 != 0) {
      uVar14 = 0;
      puVar11 = param_7 + 3;
      do {
        lVar13 = uVar14 * 2;
        uVar14 = uVar14 + 1;
        *(ushort *)(lVar7 + (ulong)(ushort)uVar16 + lVar13) = puVar11[-1];
        *(ushort *)(lVar7 + (ulong)(ushort)uVar1 + lVar13) = *puVar11;
        puVar11 = puVar11 + 2;
      } while (uVar14 < *(ushort *)(lVar7 + 0x28));
    }
  }
  uVar4 = *param_8;
  *(undefined2 *)(lVar7 + 0x38) = param_9;
  *(undefined1 *)(lVar7 + 0x3a) = param_10;
  *(undefined4 *)(lVar7 + 0x34) = uVar4;
  trace_event_buffer_commit(&local_98);
LAB_00103930:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_gh_rm_mem_accept_donate_lend_share @ 00103994 size=776
// signature: undefined perf_trace_gh_rm_mem_accept_donate_lend_share(void)
// callers: []
//------------------------------------------------------------

void perf_trace_gh_rm_mem_accept_donate_lend_share
               (long param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,int *param_5,
               ushort *param_6,ushort *param_7,undefined4 *param_8,undefined2 param_9,
               undefined1 param_10)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long *plVar4;
  undefined4 uVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  int iVar10;
  uint uVar11;
  ulong uVar12;
  ushort *puVar13;
  undefined1 *puVar14;
  long lVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  ulong unaff_x30;
  undefined1 auStack_c0 [4];
  int local_bc;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  uVar11 = 0x40;
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  local_70 = 0;
  local_74 = 0;
  if (param_5 == (int *)0x0) {
    iVar19 = 0;
    iVar18 = 0;
    iVar10 = 0;
    if (param_6 == (ushort *)0x0) goto LAB_00103a3c;
LAB_00103a00:
    uVar6 = *param_6;
    uVar7 = 0x200000;
    if (uVar6 < 5) {
      uVar7 = (uint)uVar6 << 0x13;
    }
    uVar7 = uVar7 | iVar10 + 0x40U;
    iVar17 = 0x20;
    if (uVar6 < 5) {
      iVar17 = (uint)uVar6 << 3;
    }
  }
  else {
    iVar18 = *param_5;
    iVar19 = iVar18 * 2;
    uVar11 = iVar18 << 0x11 | 0x40;
    iVar10 = iVar18 * 3;
    if (param_6 != (ushort *)0x0) goto LAB_00103a00;
LAB_00103a3c:
    iVar17 = 0;
    uVar7 = iVar10 + 0x40;
  }
  iVar3 = iVar17 + iVar10 + iVar17;
  if (param_7 == (ushort *)0x0) {
    iVar16 = 0;
    uVar8 = iVar3 + 0x40;
  }
  else {
    iVar16 = (uint)*param_7 << 1;
    uVar8 = iVar3 + 0x40U | (uint)*param_7 << 0x11;
  }
  lVar9 = tpidr_el1;
  plVar4 = (long *)(lVar9 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) == 0) && (*plVar4 == 0)) goto LAB_00103c60;
  local_bc = (iVar16 + iVar16 + iVar3 + 0x4bU & 0xfffffff8) - 4;
  lVar9 = perf_trace_buf_alloc(local_bc,&local_70,&local_74);
  if (lVar9 == 0) goto LAB_00103c60;
  *(undefined1 **)(local_70 + 0xe8) = auStack_c0 + 0x60;
  uVar12 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar12 = unaff_x30 | 0xffffff8000000000;
  }
  *(undefined1 **)(local_70 + 0xf8) = auStack_c0;
  uVar1 = iVar16 + iVar3 + 0x40;
  *(ulong *)(local_70 + 0x100) = uVar12;
  *(undefined8 *)(local_70 + 0x108) = 5;
  uVar2 = iVar17 + iVar10 + 0x40;
  *(uint *)(lVar9 + 0x20) = uVar7;
  *(uint *)(lVar9 + 0x24) = uVar2 | iVar17 << 0x10;
  *(uint *)(lVar9 + 0x14) = uVar11;
  *(uint *)(lVar9 + 0x18) = iVar19 + 0x40U | iVar18 << 0x10;
  *(uint *)(lVar9 + 0x2c) = uVar8;
  *(uint *)(lVar9 + 0x30) = uVar1 | iVar16 << 0x10;
  *(undefined1 *)(lVar9 + 8) = param_2;
  *(undefined1 *)(lVar9 + 9) = param_3;
  *(undefined4 *)(lVar9 + 0xc) = param_4;
  if (param_5 == (int *)0x0) {
    *(undefined4 *)(lVar9 + 0x10) = 0;
    if (param_6 == (ushort *)0x0) goto LAB_00103bd0;
LAB_00103b74:
    uVar6 = *param_6;
    *(ushort *)(lVar9 + 0x1c) = uVar6;
    uVar11 = (uint)uVar6;
    if (3 < uVar6) {
      uVar11 = 4;
    }
    *(uint *)(lVar9 + 0x3c) = uVar11;
    if (uVar11 != 0) {
      uVar12 = 0;
      puVar13 = param_6 + 6;
      do {
        lVar15 = uVar12 * 8;
        uVar12 = uVar12 + 1;
        *(undefined8 *)(lVar9 + ((ulong)uVar7 & 0xffff) + lVar15) = *(undefined8 *)(puVar13 + -4);
        *(undefined8 *)(lVar9 + (ulong)(ushort)uVar2 + lVar15) = *(undefined8 *)puVar13;
        puVar13 = puVar13 + 8;
      } while (uVar12 < *(uint *)(lVar9 + 0x3c));
    }
  }
  else {
    iVar10 = *param_5;
    *(int *)(lVar9 + 0x10) = iVar10;
    if (iVar10 != 0) {
      uVar12 = 0;
      puVar14 = (undefined1 *)((long)param_5 + 6);
      do {
        *(undefined2 *)(lVar9 + (ulong)(ushort)uVar11 + uVar12 * 2) = *(undefined2 *)(puVar14 + -2);
        *(undefined1 *)(lVar9 + (ulong)(ushort)(iVar19 + 0x40U) + uVar12) = *puVar14;
        uVar12 = uVar12 + 1;
        puVar14 = puVar14 + 4;
      } while (uVar12 < *(uint *)(lVar9 + 0x10));
    }
    if (param_6 != (ushort *)0x0) goto LAB_00103b74;
LAB_00103bd0:
    *(undefined2 *)(lVar9 + 0x1c) = 0;
    *(undefined4 *)(lVar9 + 0x3c) = 0;
  }
  if (param_7 == (ushort *)0x0) {
    *(undefined2 *)(lVar9 + 0x28) = 0;
  }
  else {
    uVar6 = *param_7;
    *(ushort *)(lVar9 + 0x28) = uVar6;
    if (uVar6 != 0) {
      uVar12 = 0;
      puVar13 = param_7 + 3;
      do {
        lVar15 = uVar12 * 2;
        uVar12 = uVar12 + 1;
        *(ushort *)(lVar9 + ((ulong)uVar8 & 0xffff) + lVar15) = puVar13[-1];
        *(ushort *)(lVar9 + (ulong)(ushort)uVar1 + lVar15) = *puVar13;
        puVar13 = puVar13 + 2;
      } while (uVar12 < *(ushort *)(lVar9 + 0x28));
    }
  }
  uVar5 = *param_8;
  *(undefined2 *)(lVar9 + 0x38) = param_9;
  *(undefined1 *)(lVar9 + 0x3a) = param_10;
  *(undefined4 *)(lVar9 + 0x34) = uVar5;
  perf_trace_run_bpf_submit(lVar9,local_bc,local_74,param_1,1,local_70,plVar4,0);
LAB_00103c60:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_gh_rm_mem_accept_reply @ 00103ca0 size=352
// signature: undefined trace_event_raw_event_gh_rm_mem_accept_reply(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_gh_rm_mem_accept_reply(long param_1,ushort *param_2)

{
  ushort uVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  ushort *puVar5;
  long lVar6;
  int iVar7;
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
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    uVar3 = 0x19;
    if (param_2 == (ushort *)0x0) {
      iVar7 = 0;
    }
    else {
      uVar1 = *param_2;
      uVar3 = 0x200019;
      iVar7 = 0x20;
      if (uVar1 < 5) {
        uVar3 = (uint)uVar1 << 0x13 | 0x19;
        iVar7 = (uint)uVar1 << 3;
      }
    }
    lVar2 = trace_event_buffer_reserve(&local_68,param_1,iVar7 * 2 + 0x1c);
    if (lVar2 != 0) {
      *(uint *)(lVar2 + 0xc) = uVar3;
      *(uint *)(lVar2 + 0x10) = iVar7 + 0x19U | iVar7 << 0x10;
      *(bool *)(lVar2 + 0x18) = (ushort *)0xfffffffffffff000 < param_2;
      if ((param_2 == (ushort *)0x0) || ((ushort *)0xfffffffffffff000 < param_2)) {
        *(undefined2 *)(lVar2 + 8) = 0;
        *(undefined4 *)(lVar2 + 0x14) = 0;
      }
      else {
        uVar1 = *param_2;
        *(ushort *)(lVar2 + 8) = uVar1;
        uVar3 = (uint)uVar1;
        if (3 < uVar1) {
          uVar3 = 4;
        }
        *(uint *)(lVar2 + 0x14) = uVar3;
        if (uVar3 != 0) {
          uVar4 = 0;
          puVar5 = param_2 + 6;
          do {
            lVar6 = uVar4 * 8;
            uVar4 = uVar4 + 1;
            *(undefined8 *)(lVar2 + 0x19 + lVar6) = *(undefined8 *)(puVar5 + -4);
            *(undefined8 *)(lVar2 + (ulong)(ushort)(iVar7 + 0x19U) + lVar6) = *(undefined8 *)puVar5;
            puVar5 = puVar5 + 8;
          } while (uVar4 < *(uint *)(lVar2 + 0x14));
        }
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
// perf_trace_gh_rm_mem_accept_reply @ 00103e04 size=440
// signature: undefined perf_trace_gh_rm_mem_accept_reply(void)
// callers: []
//------------------------------------------------------------

void perf_trace_gh_rm_mem_accept_reply(long param_1,ushort *param_2)

{
  long *plVar1;
  ushort uVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  ulong uVar6;
  ushort *puVar7;
  long lVar8;
  int iVar9;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  uVar5 = 0x19;
  local_60 = 0;
  local_64 = 0;
  if (param_2 == (ushort *)0x0) {
    iVar9 = 0;
  }
  else {
    uVar2 = *param_2;
    uVar5 = 0x200019;
    iVar9 = 0x20;
    if (uVar2 < 5) {
      uVar5 = (uint)uVar2 << 0x13 | 0x19;
      iVar9 = (uint)uVar2 << 3;
    }
  }
  lVar4 = tpidr_el1;
  plVar1 = (long *)(lVar4 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = (iVar9 * 2 + 0x27U & 0x1ffff8) - 4;
    lVar4 = perf_trace_buf_alloc(iVar3,&local_60,&local_64);
    if (lVar4 != 0) {
      *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
      *(undefined1 **)(local_60 + 0xf8) = auStack_70;
      uVar6 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar6 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_60 + 0x100) = uVar6;
      *(undefined8 *)(local_60 + 0x108) = 5;
      *(uint *)(lVar4 + 0xc) = uVar5;
      *(uint *)(lVar4 + 0x10) = iVar9 + 0x19U | iVar9 << 0x10;
      *(bool *)(lVar4 + 0x18) = (ushort *)0xfffffffffffff000 < param_2;
      if ((param_2 == (ushort *)0x0) || ((ushort *)0xfffffffffffff000 < param_2)) {
        *(undefined2 *)(lVar4 + 8) = 0;
        *(undefined4 *)(lVar4 + 0x14) = 0;
      }
      else {
        uVar2 = *param_2;
        *(ushort *)(lVar4 + 8) = uVar2;
        uVar5 = (uint)uVar2;
        if (3 < uVar2) {
          uVar5 = 4;
        }
        *(uint *)(lVar4 + 0x14) = uVar5;
        if (uVar5 != 0) {
          uVar6 = 0;
          puVar7 = param_2 + 6;
          do {
            lVar8 = uVar6 * 8;
            uVar6 = uVar6 + 1;
            *(undefined8 *)(lVar4 + 0x19 + lVar8) = *(undefined8 *)(puVar7 + -4);
            *(undefined8 *)(lVar4 + (ulong)(ushort)(iVar9 + 0x19U) + lVar8) = *(undefined8 *)puVar7;
            puVar7 = puVar7 + 8;
          } while (uVar6 < *(uint *)(lVar4 + 0x14));
        }
      }
      perf_trace_run_bpf_submit(lVar4,iVar3,local_64,param_1,1,local_60,plVar1,0);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_gh_rm_mem_release_reclaim @ 00103fc0 size=176
// signature: undefined trace_event_raw_event_gh_rm_mem_release_reclaim(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_gh_rm_mem_release_reclaim
               (long param_1,undefined4 param_2,undefined1 param_3)

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
    *(undefined1 *)(lVar1 + 0xc) = param_3;
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
// perf_trace_gh_rm_mem_release_reclaim @ 00104074 size=252
// signature: undefined perf_trace_gh_rm_mem_release_reclaim(void)
// callers: []
//------------------------------------------------------------

void perf_trace_gh_rm_mem_release_reclaim(long param_1,undefined4 param_2,undefined1 param_3)

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
    *(undefined1 *)(lVar3 + 0xc) = param_3;
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
// trace_event_raw_event_gh_rm_mem_call_return @ 00104174 size=172
// signature: undefined trace_event_raw_event_gh_rm_mem_call_return(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_gh_rm_mem_call_return(long param_1,undefined4 param_2,undefined4 param_3)

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
// perf_trace_gh_rm_mem_call_return @ 00104224 size=248
// signature: undefined perf_trace_gh_rm_mem_call_return(void)
// callers: []
//------------------------------------------------------------

void perf_trace_gh_rm_mem_call_return(long param_1,undefined4 param_2,undefined4 param_3)

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
// trace_event_raw_event_gh_rm_mem_notify @ 00104320 size=304
// signature: undefined trace_event_raw_event_gh_rm_mem_notify(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_gh_rm_mem_notify
               (long param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4,
               ushort *param_5)

{
  ushort uVar1;
  long lVar2;
  ulong uVar3;
  int iVar4;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar3 = __trace_trigger_soft_disabled(param_1), (uVar3 & 1) == 0)) {
    if (param_5 == (ushort *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = (uint)*param_5 << 1;
    }
    lVar2 = trace_event_buffer_reserve(&local_78,param_1,iVar4 + 0x1c);
    if (lVar2 != 0) {
      *(undefined4 *)(lVar2 + 8) = param_2;
      *(undefined1 *)(lVar2 + 0xc) = param_3;
      *(undefined4 *)(lVar2 + 0x10) = param_4;
      *(uint *)(lVar2 + 0x18) = iVar4 << 0x10 | 0x1c;
      if (param_5 == (ushort *)0x0) {
        *(undefined2 *)(lVar2 + 0x14) = 0;
      }
      else {
        uVar1 = *param_5;
        *(ushort *)(lVar2 + 0x14) = uVar1;
        if (uVar1 != 0) {
          uVar3 = 0;
          do {
            param_5 = param_5 + 2;
            uVar1 = *(ushort *)(lVar2 + 0x14);
            *(ushort *)(lVar2 + 0x1c + uVar3 * 2) = *param_5;
            uVar3 = uVar3 + 1;
          } while (uVar3 < uVar1);
        }
      }
      trace_event_buffer_commit(&local_78);
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_gh_rm_mem_notify @ 00104454 size=384
// signature: undefined perf_trace_gh_rm_mem_notify(void)
// callers: []
//------------------------------------------------------------

void perf_trace_gh_rm_mem_notify
               (long param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4,
               ushort *param_5)

{
  long *plVar1;
  ushort uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  int iVar6;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  local_70 = 0;
  local_74 = 0;
  if (param_5 == (ushort *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = (uint)*param_5 << 1;
  }
  lVar4 = tpidr_el1;
  plVar1 = (long *)(lVar4 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = (iVar6 + 0x27U & 0x3fff8) - 4;
    lVar4 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar4 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      uVar5 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar5 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_70 + 0x100) = uVar5;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(uint *)(lVar4 + 0x18) = iVar6 << 0x10 | 0x1c;
      *(undefined4 *)(lVar4 + 8) = param_2;
      *(undefined1 *)(lVar4 + 0xc) = param_3;
      *(undefined4 *)(lVar4 + 0x10) = param_4;
      if (param_5 == (ushort *)0x0) {
        *(undefined2 *)(lVar4 + 0x14) = 0;
      }
      else {
        uVar2 = *param_5;
        *(ushort *)(lVar4 + 0x14) = uVar2;
        if (uVar2 != 0) {
          uVar5 = 0;
          do {
            param_5 = param_5 + 2;
            uVar2 = *(ushort *)(lVar4 + 0x14);
            *(ushort *)(lVar4 + 0x1c + uVar5 * 2) = *param_5;
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar2);
        }
      }
      perf_trace_run_bpf_submit(lVar4,iVar3,local_74,param_1,1,local_70,plVar1,0);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_gh_rm_mem_accept_donate_lend_share @ 001045d8 size=60
// signature: undefined __bpf_trace_gh_rm_mem_accept_donate_lend_share(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_gh_rm_mem_accept_donate_lend_share
               (undefined8 param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4)

{
  bpf_trace_run9(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_gh_rm_mem_accept_reply @ 00104618 size=28
// signature: undefined __bpf_trace_gh_rm_mem_accept_reply(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_gh_rm_mem_accept_reply(void)

{
  bpf_trace_run1();
  return;
}



//------------------------------------------------------------
// __bpf_trace_gh_rm_mem_release_reclaim @ 00104638 size=36
// signature: undefined __bpf_trace_gh_rm_mem_release_reclaim(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_gh_rm_mem_release_reclaim(undefined8 param_1,undefined4 param_2,undefined1 param_3)

{
  bpf_trace_run2(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_gh_rm_mem_call_return @ 00104660 size=36
// signature: undefined __bpf_trace_gh_rm_mem_call_return(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_gh_rm_mem_call_return(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  bpf_trace_run2(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_gh_rm_mem_notify @ 00104688 size=40
// signature: undefined __bpf_trace_gh_rm_mem_notify(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_gh_rm_mem_notify
               (undefined8 param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4)

{
  bpf_trace_run4(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// gh_init_vm_prop_table @ 001046b4 size=144
// signature: undefined gh_init_vm_prop_table(void)
// callers: [gh_rm_drv_probe]
//------------------------------------------------------------

void gh_init_vm_prop_table(void)

{
  _raw_spin_lock(&gh_vm_table_lock);
  gh_vm_table = 0;
  DAT_0010c808 = 0;
  DAT_0010c810 = 0;
  DAT_0010c800 = 0xffff;
  DAT_0010c818 = 0;
  DAT_0010c820 = 0;
  DAT_0010c828 = 0xffff;
  DAT_0010c830 = 0;
  DAT_0010c838 = 0;
  DAT_0010c840 = 0;
  DAT_0010c848 = 0;
  DAT_0010c850 = 0xffff;
  DAT_0010c858 = 0;
  DAT_0010c860 = 0;
  DAT_0010c868 = 0;
  DAT_0010c870 = 0;
  DAT_0010c878 = 0xffff;
  DAT_0010c890 = 0;
  DAT_0010c898 = 0;
  DAT_0010c880 = 0;
  DAT_0010c888 = 0;
  DAT_0010c8a0 = 0xffff;
  DAT_0010c8a8 = 0;
  DAT_0010c8b0 = 0;
  DAT_0010c8b8 = 0;
  DAT_0010c8c0 = 0;
  DAT_0010c8c8 = 0xffff;
  DAT_0010c8d0 = 0;
  DAT_0010c8d8 = 0;
  DAT_0010c8e0 = 0;
  DAT_0010c8e8 = 0;
  _raw_spin_unlock(&gh_vm_table_lock);
  return;
}



//------------------------------------------------------------
// gh_update_vm_prop_table @ 00104748 size=356
// signature: undefined gh_update_vm_prop_table(void)
// callers: [gh_rm_drv_probe, gh_rm_vm_alloc_vmid, gh_rm_get_vm_id_info]
//------------------------------------------------------------

undefined8 gh_update_vm_prop_table(uint param_1,short *param_2)

{
  long lVar1;
  code *pcVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  undefined8 uVar7;
  
  if (6 < param_1) {
    return 0xffffffea;
  }
  if (param_2 == (short *)0x0) {
    return 0xffffffea;
  }
  _raw_spin_lock(&gh_vm_table_lock);
  uVar3 = (ulong)param_1;
  lVar1 = uVar3 + (ulong)param_1 * 4;
  uVar4 = lVar1 * 8;
  if (0x110 < uVar4) {
LAB_001048a8:
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(1,0x1048ac);
    (*pcVar2)();
  }
  if (*(long *)(&DAT_0010c7e0 + uVar4) == 0) {
    uVar5 = uVar3 * 0x28;
    if (0x108 < uVar5) goto LAB_001048a8;
    if (*(long *)(&DAT_0010c7e8 + uVar5) == 0) {
      uVar6 = uVar3 * 0x28;
      if (0x100 < uVar6) goto LAB_001048a8;
      if (*(long *)(&DAT_0010c7f0 + uVar6) == 0) {
        uVar3 = uVar3 * 0x28;
        if (0xf8 < uVar3) goto LAB_001048a8;
        if (*(long *)(&DAT_0010c7f8 + uVar3) == 0) {
          if (*param_2 != 0) {
            if ((0x118 < uVar4) || (param_1 == 7)) goto LAB_001048a8;
            (&gh_vm_table)[lVar1 * 4] = *param_2;
          }
          if (*(long *)(param_2 + 4) != 0) {
            if (0x110 < uVar4) goto LAB_001048a8;
            *(long *)(&DAT_0010c7e0 + uVar4) = *(long *)(param_2 + 4);
          }
          if (*(long *)(param_2 + 8) != 0) {
            if (0x108 < uVar5) goto LAB_001048a8;
            *(long *)(&DAT_0010c7e8 + uVar5) = *(long *)(param_2 + 8);
          }
          if (*(long *)(param_2 + 0xc) != 0) {
            if (0x100 < uVar6) goto LAB_001048a8;
            *(long *)(&DAT_0010c7f0 + uVar6) = *(long *)(param_2 + 0xc);
          }
          if (*(long *)(param_2 + 0x10) == 0) {
            uVar7 = 0;
          }
          else {
            if (0xf8 < uVar3) goto LAB_001048a8;
            uVar7 = 0;
            *(long *)(&DAT_0010c7f8 + uVar3) = *(long *)(param_2 + 0x10);
          }
          goto LAB_00104808;
        }
      }
    }
  }
  uVar7 = 0xffffffef;
LAB_00104808:
  _raw_spin_unlock(&gh_vm_table_lock);
  return uVar7;
}



//------------------------------------------------------------
// gh_reset_vm_prop_table_entry @ 001048b0 size=256
// signature: undefined gh_reset_vm_prop_table_entry(void)
// callers: []
//------------------------------------------------------------

void gh_reset_vm_prop_table_entry(short param_1)

{
  undefined2 *puVar1;
  long lVar2;
  
  _raw_spin_lock(&gh_vm_table_lock);
  puVar1 = &DAT_0010c800;
  if (DAT_0010c800 == param_1) {
    lVar2 = 1;
  }
  else {
    puVar1 = &DAT_0010c828;
    if (DAT_0010c828 == param_1) {
      lVar2 = 2;
    }
    else {
      puVar1 = &DAT_0010c850;
      if (DAT_0010c850 == param_1) {
        lVar2 = 3;
      }
      else {
        puVar1 = &DAT_0010c878;
        if (DAT_0010c878 == param_1) {
          lVar2 = 4;
        }
        else {
          puVar1 = &DAT_0010c8a0;
          if (DAT_0010c8a0 == param_1) {
            lVar2 = 5;
          }
          else {
            puVar1 = &DAT_0010c8c8;
            if (DAT_0010c8c8 != param_1) goto LAB_00104994;
            lVar2 = 6;
          }
        }
      }
    }
  }
  lVar2 = lVar2 * 0x28;
  *puVar1 = 0xffff;
  *(undefined8 *)(&DAT_0010c7f0 + lVar2) = 0;
  *(undefined8 *)(&DAT_0010c7f8 + lVar2) = 0;
  *(undefined8 *)(&DAT_0010c7e0 + lVar2) = 0;
  *(undefined8 *)(&DAT_0010c7e8 + lVar2) = 0;
LAB_00104994:
  _raw_spin_unlock(&gh_vm_table_lock);
  return;
}



//------------------------------------------------------------
// ghd_rm_get_vmid @ 001049b4 size=176
// signature: undefined ghd_rm_get_vmid(void)
// callers: [gh_rm_get_svm_res_work_fn]
//------------------------------------------------------------

undefined8 ghd_rm_get_vmid(uint param_1,short *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  
  if (param_1 < 7) {
    _raw_spin_lock(&gh_vm_table_lock);
    if (0x118 < ((ulong)param_1 + (ulong)param_1 * 4) * 8) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(1,0x104a64);
      (*pcVar1)();
    }
    if (gh_rm_core_initialized == '\0') {
      uVar2 = 0xfffffdfb;
    }
    else if ((param_1 == 0) || ((&gh_vm_table)[(ulong)param_1 * 0x14] != 0)) {
      uVar2 = 0;
      if (param_2 != (short *)0x0) {
        *param_2 = (&gh_vm_table)[(ulong)param_1 * 0x14];
      }
    }
    else {
      uVar2 = 0xffffffea;
    }
    _raw_spin_unlock(&gh_vm_table_lock);
  }
  else {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// gh_rm_get_vm_name @ 00104a68 size=252
// signature: undefined gh_rm_get_vm_name(void)
// callers: [gh_vm_status_nb_handler, gh_rm_drv_probe]
//------------------------------------------------------------

undefined8 gh_rm_get_vm_name(short param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  _raw_spin_lock(&gh_vm_table_lock);
  if (gh_vm_table == param_1) {
    uVar1 = 0;
  }
  else if (DAT_0010c800 == param_1) {
    uVar1 = 1;
  }
  else if (DAT_0010c828 == param_1) {
    uVar1 = 2;
  }
  else if (DAT_0010c850 == param_1) {
    uVar1 = 3;
  }
  else if (DAT_0010c878 == param_1) {
    uVar1 = 4;
  }
  else if (DAT_0010c8a0 == param_1) {
    uVar1 = 5;
  }
  else {
    if (DAT_0010c8c8 != param_1) {
      uVar2 = 0xffffffea;
      goto LAB_00104b3c;
    }
    uVar1 = 6;
  }
  uVar2 = 0;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = uVar1;
  }
LAB_00104b3c:
  _raw_spin_unlock(&gh_vm_table_lock);
  return uVar2;
}



//------------------------------------------------------------
// gh_rm_get_vminfo @ 00104b68 size=204
// signature: undefined gh_rm_get_vminfo(void)
// callers: [gh_vm_status_nb_handler, gh_rm_drv_probe]
//------------------------------------------------------------

undefined8 gh_rm_get_vminfo(uint param_1,undefined8 *param_2)

{
  code *pcVar1;
  ulong uVar2;
  ulong uVar3;
  
  if ((6 < param_1) || (param_2 == (undefined8 *)0x0)) {
    return 0xffffffea;
  }
  _raw_spin_lock(&gh_vm_table_lock);
  uVar2 = (ulong)param_1;
  if ((uVar2 + (ulong)param_1 * 4) * 8 < 0x111) {
    uVar3 = uVar2 * 0x28;
    *param_2 = *(undefined8 *)(&DAT_0010c7e0 + uVar3);
    if (((uVar3 < 0x109) && (param_2[1] = *(undefined8 *)(&DAT_0010c7e8 + uVar3), uVar3 < 0x101)) &&
       (param_2[2] = *(undefined8 *)(&DAT_0010c7f0 + uVar2 * 0x28), uVar2 * 0x28 < 0xf9)) {
      param_2[3] = *(undefined8 *)(&DAT_0010c7f8 + uVar2 * 0x28);
      _raw_spin_unlock(&gh_vm_table_lock);
      return 0;
    }
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0x104c34);
  (*pcVar1)();
}



//------------------------------------------------------------
// gh_rm_vm_get_id @ 00104c38 size=380
// signature: undefined gh_rm_vm_get_id(void)
// callers: [gh_rm_get_vm_id_info]
//------------------------------------------------------------

long gh_rm_vm_get_id(undefined2 param_1,int *param_2)

{
  long lVar1;
  int iVar2;
  int *piVar3;
  ulong uVar4;
  long lVar5;
  ulong local_40;
  undefined2 local_38;
  undefined2 local_36;
  int *local_30;
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  local_30 = (int *)0x0;
  local_36 = 0;
  local_40 = 0;
  local_38 = param_1;
  if (param_2 == (int *)0x0) {
    lVar5 = -0x16;
  }
  else {
    iVar2 = gh_rm_call(rm,0x56000010,&local_38,4,&local_30,&local_40);
    if (iVar2 == 0) {
      if (local_40 < 4) {
        if (local_40 == 0) {
          lVar5 = -0x4a;
        }
        else {
          kfree(local_30);
          lVar5 = -0x4a;
        }
      }
      else {
        iVar2 = *local_30;
        if (iVar2 == 0) {
          lVar5 = 0;
        }
        else {
          lVar5 = 0;
          piVar3 = local_30 + 1;
          do {
            iVar2 = iVar2 + -1;
            uVar4 = (ulong)*(ushort *)((long)piVar3 + 2) - 1 | 3;
            lVar5 = lVar5 + uVar4 + 5;
            piVar3 = (int *)((long)piVar3 + uVar4 + 5);
          } while (iVar2 != 0);
        }
        if (lVar5 == local_40 - 4) {
          lVar5 = kmemdup(local_30 + 1,lVar5,0xcc0);
          if (lVar5 == 0) {
            lVar5 = -0xc;
          }
          else {
            *param_2 = *local_30;
          }
        }
        else {
          _printk(&DAT_0010a2fb,"gh_rm_vm_get_id");
          lVar5 = -0x16;
        }
        kfree(local_30);
      }
    }
    else {
      _printk(&DAT_0010a2d9,"gh_rm_vm_get_id",iVar2);
      lVar5 = (long)iVar2;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar5;
}



//------------------------------------------------------------
// gh_rm_vm_lookup @ 00104db8 size=440
// signature: undefined gh_rm_vm_lookup(void)
// callers: [gh_rm_drv_probe]
//------------------------------------------------------------

int gh_rm_vm_lookup(int param_1,long param_2,long param_3,undefined2 *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  long lVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  ulong local_48;
  uint *local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  if (param_1 != 2) {
    if (param_1 == 1) {
      uVar2 = 0x56000011;
    }
    else {
      if (param_1 != 0) {
        _printk(&DAT_00109a73);
        iVar4 = 0;
        goto LAB_00104e80;
      }
      uVar2 = 0x56000013;
    }
    iVar4 = gh_rm_vm_lookup_name_uri(uVar2,param_2,param_3,param_4);
    goto LAB_00104e80;
  }
  if (param_3 != 0x10) {
    _printk(&DAT_0010ad86,param_3);
    iVar4 = -0x16;
    goto LAB_00104e80;
  }
  iVar6 = -0x16;
  local_48 = 0;
  local_40 = (uint *)0x0;
  iVar4 = iVar6;
  if ((param_2 == 0) || (param_4 == (undefined2 *)0x0)) goto LAB_00104e80;
  iVar4 = gh_rm_call(rm,0x56000012,param_2,0x10,&local_40,&local_48);
  if (iVar4 != 0) {
    _printk(&DAT_00109ecc,"gh_rm_vm_lookup_guid",iVar4);
    goto LAB_00104e80;
  }
  if (local_48 < 4) {
    if (local_48 != 0) goto LAB_00104ee8;
  }
  else {
    uVar1 = *local_40;
    if (local_48 == (ulong)uVar1 * 4 + 4) {
      if (uVar1 == 1) {
        *param_4 = (short)local_40[1];
        iVar4 = 0;
      }
      else {
        if (uVar1 == 0) {
          puVar5 = &DAT_0010ae4e;
        }
        else {
          puVar5 = &DAT_0010ae74;
        }
        _printk(puVar5,"gh_rm_vm_lookup_guid",param_2);
        iVar4 = iVar6;
      }
      kfree(local_40);
      goto LAB_00104e80;
    }
LAB_00104ee8:
    kfree(local_40);
  }
  iVar4 = -0x4a;
LAB_00104e80:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// gh_rm_vm_lookup_name_uri @ 00104f70 size=396
// signature: undefined gh_rm_vm_lookup_name_uri(void)
// callers: [gh_rm_vm_lookup]
//------------------------------------------------------------

int gh_rm_vm_lookup_name_uri(undefined4 param_1,void *param_2,size_t param_3,undefined2 *param_4)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined *puVar5;
  ulong local_58;
  uint *local_50;
  long local_48;
  
  lVar1 = sp_el0;
  iVar3 = -0x16;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  local_50 = (uint *)0x0;
  if ((param_2 == (void *)0x0) || (param_4 == (undefined2 *)0x0)) goto LAB_00105074;
  lVar1 = (param_3 - 1 | 3) + 5;
  puVar4 = (undefined2 *)__kmalloc(lVar1,0xdc0);
  if (puVar4 == (undefined2 *)0x0) {
    iVar3 = -0xc;
    goto LAB_00105074;
  }
  *puVar4 = (short)param_3;
  memcpy(puVar4 + 2,param_2,param_3);
  iVar3 = gh_rm_call(rm,param_1,puVar4,lVar1,&local_50,&local_58);
  if (iVar3 == 0) {
    if (local_58 < 4) {
      if (local_58 != 0) {
LAB_00105064:
        kfree(local_50);
      }
      iVar3 = -0x4a;
    }
    else {
      uVar2 = *local_50;
      if (local_58 != (ulong)uVar2 * 4 + 4) goto LAB_00105064;
      if (uVar2 == 1) {
        iVar3 = 0;
        *param_4 = (short)local_50[1];
      }
      else {
        if (uVar2 == 0) {
          puVar5 = &DAT_0010a8a4;
        }
        else {
          puVar5 = &DAT_0010af4c;
        }
        _printk(puVar5,"gh_rm_vm_lookup_name_uri",param_2);
        iVar3 = -0x16;
      }
      kfree(local_50);
    }
  }
  else {
    _printk(&DAT_0010ae23,"gh_rm_vm_lookup_name_uri",iVar3);
  }
  kfree(puVar4);
LAB_00105074:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// gh_rm_get_this_vmid @ 00105100 size=264
// signature: undefined gh_rm_get_this_vmid(void)
// callers: []
//------------------------------------------------------------

int gh_rm_get_this_vmid(short *param_1)

{
  long lVar1;
  int iVar2;
  short *local_48;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = (short *)0x0;
  local_40 = 0;
  if (gh_rm_get_this_vmid_cached_vmid == -1) {
    iVar2 = gh_rm_call(rm,0x56000024,0,0,&local_48,&local_40);
    if (iVar2 == 0) {
      if (local_40 == 0) {
        iVar2 = -0x4a;
      }
      else if (local_40 == 4) {
        gh_rm_get_this_vmid_cached_vmid = *local_48;
        *param_1 = gh_rm_get_this_vmid_cached_vmid;
        kfree();
        iVar2 = 0;
      }
      else {
        kfree(local_48);
        iVar2 = -0x4a;
      }
    }
    else {
      _printk(&DAT_0010a4c8,"gh_rm_get_this_vmid",iVar2);
    }
  }
  else {
    iVar2 = 0;
    *param_1 = gh_rm_get_this_vmid_cached_vmid;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gh_rm_vm_get_status @ 0010520c size=260
// signature: undefined gh_rm_vm_get_status(void)
// callers: [gh_rm_vm_set_vm_status, gh_rm_vm_set_os_status, gh_rm_vm_set_app_status]
//------------------------------------------------------------

long gh_rm_vm_get_status(undefined2 param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long local_40;
  long local_38;
  undefined2 local_30;
  undefined2 local_2e;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2e = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = param_1;
  iVar1 = gh_rm_call(rm,0x56000017,&local_30,4,&local_38,&local_40);
  if (iVar1 == 0) {
    if (local_40 == 4) {
      lVar2 = kmemdup(local_38,4,0xcc0);
      lVar3 = -0xc;
      if (lVar2 != 0) {
        lVar3 = lVar2;
      }
    }
    else {
      _printk(&DAT_00109d74,"gh_rm_vm_get_status");
      lVar3 = -0x16;
    }
  }
  else {
    _printk(&DAT_00109bfa,"gh_rm_vm_get_status",iVar1);
    lVar3 = (long)iVar1;
    if (local_38 == 0) goto LAB_00105298;
  }
  if (local_40 != 0) {
    kfree(local_38);
  }
LAB_00105298:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3;
}



//------------------------------------------------------------
// gh_rm_vm_set_status @ 00105314 size=224
// signature: undefined gh_rm_vm_set_status(void)
// callers: [gh_rm_vm_set_vm_status, gh_rm_vm_set_os_status, gh_rm_vm_set_app_status]
//------------------------------------------------------------

int gh_rm_vm_set_status(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  undefined8 local_40;
  long local_38;
  undefined1 local_30;
  undefined1 local_2f;
  undefined2 local_2e;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = (undefined1)param_1;
  local_2f = (undefined1)((ulong)param_1 >> 8);
  local_2e = (undefined2)((ulong)param_1 >> 0x10);
  local_40 = 0;
  local_38 = 0;
  iVar2 = gh_rm_call(rm,0x56000080,&local_30,4,&local_40,&local_38);
  if (iVar2 == 0) {
    if (local_38 == 0) {
      iVar2 = 0;
    }
    else {
      _printk(&DAT_0010ac96,"gh_rm_vm_set_status");
      kfree(local_40);
      iVar2 = -0x16;
    }
  }
  else {
    _printk(&DAT_0010a4e3,"gh_rm_vm_set_status",iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gh_rm_vm_set_vm_status @ 001053f8 size=92
// signature: undefined gh_rm_vm_set_vm_status(void)
// callers: []
//------------------------------------------------------------

ulong gh_rm_vm_set_vm_status(undefined1 param_1)

{
  undefined4 *puVar1;
  ulong uVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)gh_rm_vm_get_status(0);
  puVar3 = puVar1;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1 < (undefined4 *)0xfffffffffffff001)) {
    *(undefined1 *)puVar1 = param_1;
    uVar2 = gh_rm_vm_set_status(*puVar1);
    puVar3 = (undefined4 *)(uVar2 & 0xffffffff);
    kfree(puVar1);
  }
  return (ulong)puVar3 & 0xffffffff;
}



//------------------------------------------------------------
// gh_rm_vm_set_os_status @ 00105458 size=92
// signature: undefined gh_rm_vm_set_os_status(void)
// callers: []
//------------------------------------------------------------

ulong gh_rm_vm_set_os_status(undefined1 param_1)

{
  undefined4 *puVar1;
  ulong uVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)gh_rm_vm_get_status(0);
  puVar3 = puVar1;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1 < (undefined4 *)0xfffffffffffff001)) {
    *(undefined1 *)((long)puVar1 + 1) = param_1;
    uVar2 = gh_rm_vm_set_status(*puVar1);
    puVar3 = (undefined4 *)(uVar2 & 0xffffffff);
    kfree(puVar1);
  }
  return (ulong)puVar3 & 0xffffffff;
}



//------------------------------------------------------------
// gh_rm_vm_set_app_status @ 001054b8 size=92
// signature: undefined gh_rm_vm_set_app_status(void)
// callers: []
//------------------------------------------------------------

ulong gh_rm_vm_set_app_status(undefined2 param_1)

{
  undefined4 *puVar1;
  ulong uVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)gh_rm_vm_get_status(0);
  puVar3 = puVar1;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1 < (undefined4 *)0xfffffffffffff001)) {
    *(undefined2 *)((long)puVar1 + 2) = param_1;
    uVar2 = gh_rm_vm_set_status(*puVar1);
    puVar3 = (undefined4 *)(uVar2 & 0xffffffff);
    kfree(puVar1);
  }
  return (ulong)puVar3 & 0xffffffff;
}



//------------------------------------------------------------
// gh_rm_vm_get_hyp_res @ 00105518 size=328
// signature: undefined gh_rm_vm_get_hyp_res(void)
// callers: [gh_rm_unpopulate_hyp_res, gh_rm_populate_hyp_res]
//------------------------------------------------------------

long gh_rm_vm_get_hyp_res(undefined2 param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  ulong local_40;
  undefined2 local_38;
  undefined2 local_36;
  uint *local_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_30 = (uint *)0x0;
  local_36 = 0;
  local_40 = 0;
  local_38 = param_1;
  if (param_2 == (uint *)0x0) {
    lVar4 = -0x16;
    goto LAB_0010560c;
  }
  iVar3 = gh_rm_call(rm,0x56000020,&local_38,4,&local_30,&local_40);
  if (iVar3 != 0) {
    _printk(&DAT_0010a7dd,"gh_rm_vm_get_hyp_res",iVar3);
    lVar4 = (long)iVar3;
    goto LAB_0010560c;
  }
  if (local_40 < 4) {
LAB_001055ec:
    _printk(&DAT_0010a50b,"gh_rm_vm_get_hyp_res");
    lVar4 = -0x16;
  }
  else {
    uVar1 = *local_30;
    if (((0x5d1745d < uVar1) || (uVar1 == 0x5d1745d)) || (local_40 != (ulong)uVar1 * 0x2c + 4))
    goto LAB_001055ec;
    lVar4 = kmemdup(local_30 + 1,(ulong)uVar1 * 0x2c,0xcc0);
    if (lVar4 == 0) {
      lVar4 = -0xc;
    }
    else {
      *param_2 = *local_30;
    }
  }
  kfree(local_30);
LAB_0010560c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar4;
}



//------------------------------------------------------------
// gh_rm_vm_irq_lend @ 00105664 size=256
// signature: undefined gh_rm_vm_irq_lend(void)
// callers: []
//------------------------------------------------------------

int gh_rm_vm_irq_lend(ushort param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  long lVar1;
  int iVar2;
  long local_48;
  uint local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 *local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_40 = (uint)param_1;
  local_30 = (undefined4 *)0x0;
  local_48 = 0;
  uStack_3c = param_2;
  local_38 = param_3;
  iVar2 = gh_rm_call(rm,0x56000051,&local_40,0xc,&local_30,&local_48);
  if (iVar2 == 0) {
    if (local_48 == 4) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = *local_30;
      }
      kfree();
      iVar2 = 0;
    }
    else {
      _printk(&DAT_0010ac05,"gh_rm_vm_irq_lend");
      if (local_48 != 0) {
        kfree(local_30);
      }
      iVar2 = -0x16;
    }
  }
  else {
    _printk(&DAT_0010a0b1,"gh_rm_vm_irq_lend",iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gh_rm_vm_irq_lend_notify @ 00105768 size=92
// signature: undefined gh_rm_vm_irq_lend_notify(void)
// callers: []
//------------------------------------------------------------

void gh_rm_vm_irq_lend_notify(undefined2 param_1,undefined4 param_2)

{
  long lVar1;
  undefined2 local_1c [2];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = param_1;
  gh_rm_vm_irq_notify(local_1c,1,1,param_2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gh_rm_vm_irq_notify @ 001057c4 size=352
// signature: undefined gh_rm_vm_irq_notify(void)
// callers: [gh_rm_vm_irq_accept_notify, gh_rm_vm_irq_release_notify, gh_rm_vm_irq_lend_notify]
//------------------------------------------------------------

int gh_rm_vm_irq_notify(undefined2 *param_1,uint param_2,byte param_3,undefined4 param_4)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  long local_58;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  local_50 = 0;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    lVar1 = 8;
    if ((param_3 & 1) != 0) {
      lVar1 = (ulong)param_2 * 4 + 0xc;
    }
    puVar4 = (undefined4 *)__kmalloc(lVar1,0xdc0);
    if (puVar4 == (undefined4 *)0x0) {
      iVar3 = -0xc;
      goto LAB_001058ac;
    }
    *puVar4 = param_4;
    *(byte *)(puVar4 + 1) = param_3;
    if (((param_3 & 1) != 0) && (*(short *)(puVar4 + 2) = (short)param_2, param_2 != 0)) {
      if ((param_3 & 1) == 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(1,0x105924);
        (*pcVar2)();
      }
      *(undefined2 *)(puVar4 + 3) = *param_1;
      if (param_2 != 1) {
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
    }
    iVar3 = gh_rm_call(rm,0x56000054,puVar4,lVar1,&local_50,&local_58);
    kfree(puVar4);
    if (iVar3 != 0) {
      _printk(&DAT_0010b001,"gh_rm_vm_irq_notify",iVar3);
      goto LAB_001058ac;
    }
    if (local_58 == 0) {
      iVar3 = 0;
      goto LAB_001058ac;
    }
    _printk(&DAT_00109cfa,"gh_rm_vm_irq_notify");
    kfree(local_50);
  }
  iVar3 = -0x16;
LAB_001058ac:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// gh_rm_vm_irq_release @ 00105928 size=212
// signature: undefined gh_rm_vm_irq_release(void)
// callers: [gh_rm_unpopulate_hyp_res]
//------------------------------------------------------------

int gh_rm_vm_irq_release(undefined4 param_1)

{
  long lVar1;
  int iVar2;
  long local_40;
  undefined8 local_38;
  undefined4 local_30 [2];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  local_38 = 0;
  local_30[0] = param_1;
  iVar2 = gh_rm_call(rm,0x56000052,local_30,4,&local_38,&local_40);
  if (iVar2 == 0) {
    if (local_40 == 0) {
      iVar2 = 0;
    }
    else {
      _printk(&DAT_0010acfd,"gh_rm_vm_irq_release");
      kfree(local_38);
      iVar2 = -0x16;
    }
  }
  else {
    _printk(&DAT_0010a663,"gh_rm_vm_irq_release",iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gh_rm_vm_irq_release_notify @ 00105a00 size=44
// signature: undefined gh_rm_vm_irq_release_notify(void)
// callers: []
//------------------------------------------------------------

void gh_rm_vm_irq_release_notify(undefined8 param_1,undefined4 param_2)

{
  gh_rm_vm_irq_notify(0,0,2,param_2);
  return;
}



//------------------------------------------------------------
// gh_rm_vm_irq_accept @ 00105a30 size=272
// signature: undefined gh_rm_vm_irq_accept(void)
// callers: []
//------------------------------------------------------------

int gh_rm_vm_irq_accept(undefined4 param_1,int param_2)

{
  long lVar1;
  int iVar2;
  long local_40;
  undefined4 local_38;
  int iStack_34;
  int *local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = (int *)0x0;
  local_40 = 0;
  if (-2 < param_2) {
    local_38 = param_1;
    iStack_34 = param_2;
    iVar2 = gh_rm_call(rm,0x56000050,&local_38,8,&local_30,&local_40);
    if (iVar2 != 0) {
      _printk(&DAT_00109c21,"gh_rm_vm_irq_accept",iVar2);
      goto LAB_00105ac4;
    }
    if ((param_2 != -1) || (local_40 == 4)) {
      if (param_2 == -1) {
        param_2 = *local_30;
      }
      kfree();
      iVar2 = param_2;
      goto LAB_00105ac4;
    }
    _printk(&DAT_00109a8d,"gh_rm_vm_irq_accept");
    if (local_40 != 0) {
      kfree(local_30);
    }
  }
  iVar2 = -0x16;
LAB_00105ac4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gh_rm_vm_irq_accept_notify @ 00105b44 size=44
// signature: undefined gh_rm_vm_irq_accept_notify(void)
// callers: []
//------------------------------------------------------------

void gh_rm_vm_irq_accept_notify(undefined8 param_1,undefined4 param_2)

{
  gh_rm_vm_irq_notify(0,0,4,param_2);
  return;
}



//------------------------------------------------------------
// gh_rm_vm_irq_reclaim @ 00105b74 size=212
// signature: undefined gh_rm_vm_irq_reclaim(void)
// callers: []
//------------------------------------------------------------

int gh_rm_vm_irq_reclaim(undefined4 param_1)

{
  long lVar1;
  int iVar2;
  long local_40;
  undefined8 local_38;
  undefined4 local_30 [2];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  local_38 = 0;
  local_30[0] = param_1;
  iVar2 = gh_rm_call(rm,0x56000053,local_30,4,&local_38,&local_40);
  if (iVar2 == 0) {
    if (local_40 == 0) {
      iVar2 = 0;
    }
    else {
      _printk(&DAT_0010acfd,"gh_rm_vm_irq_reclaim");
      kfree(local_38);
      iVar2 = -0x16;
    }
  }
  else {
    _printk(&DAT_0010a663,"gh_rm_vm_irq_reclaim",iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gh_rm_vm_alloc_vmid @ 00105c4c size=480
// signature: undefined gh_rm_vm_alloc_vmid(void)
// callers: []
//------------------------------------------------------------

int gh_rm_vm_alloc_vmid(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  ulong local_78 [6];
  undefined4 local_48 [2];
  undefined4 *local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = (undefined4 *)0x0;
  local_48[0] = 0;
  local_78[5] = 0;
  local_78[3] = 0;
  local_78[4] = 0;
  local_78[1] = 0;
  local_78[2] = 0;
  local_78[0] = 0;
  if (param_1 < 7) {
    _raw_spin_lock(&gh_vm_table_lock);
    if (0x118 < (ulong)param_1 * 0x28) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x105e2c);
      (*pcVar3)();
    }
    if ((param_1 == 0) || ((&gh_vm_table)[(ulong)param_1 * 0x14] != -1)) {
      _printk(&DAT_0010aa9c,"gh_rm_vm_alloc_vmid");
      _raw_spin_unlock(&gh_vm_table_lock);
      iVar4 = -0x16;
    }
    else {
      _raw_spin_unlock(&gh_vm_table_lock);
      local_48[0] = CONCAT22(local_48[0]._2_2_,(short)*param_2);
      iVar4 = gh_rm_call(rm,0x56000001,local_48,4,&local_40,local_78 + 5);
      if (iVar4 == 0) {
        if ((local_40 == (undefined4 *)0x0) || (local_78[5] == 4)) {
          if (local_40 == (undefined4 *)0x0) {
            uVar1 = *param_2;
          }
          else {
            uVar1 = *local_40;
            *param_2 = uVar1;
          }
          local_78[0] = CONCAT62(local_78[0]._2_6_,(short)uVar1);
          iVar4 = gh_update_vm_prop_table(param_1,local_78);
          if (iVar4 == 0) {
            kfree(local_40);
            iVar4 = 0;
          }
          else {
            _printk(&DAT_00109ef3,"gh_rm_vm_alloc_vmid",local_78[0] & 0xffff);
            iVar4 = -0x16;
          }
        }
        else {
          _printk(&DAT_0010ad9e,"gh_rm_vm_alloc_vmid");
          kfree(local_40);
          iVar4 = -0x16;
        }
      }
      else {
        _printk(&DAT_00109ff1,"gh_rm_vm_alloc_vmid",iVar4);
      }
    }
  }
  else {
    iVar4 = -0x16;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// gh_rm_vm_dealloc_vmid @ 00105e30 size=440
// signature: undefined gh_rm_vm_dealloc_vmid(void)
// callers: []
//------------------------------------------------------------

int gh_rm_vm_dealloc_vmid(short param_1)

{
  int iVar1;
  undefined2 *puVar2;
  long lVar3;
  undefined8 local_40;
  long local_38;
  short local_30 [4];
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_30[1] = 0;
  local_40 = 0;
  local_38 = 0;
  local_30[0] = param_1;
  iVar1 = gh_rm_call(rm,0x56000002,local_30,4,&local_40,&local_38);
  if (iVar1 != 0) {
    _printk(&DAT_00109e49,"gh_rm_vm_dealloc_vmid",iVar1);
    goto LAB_00105fb8;
  }
  if (local_38 != 0) {
    _printk(&DAT_00109ac0,"gh_rm_vm_dealloc_vmid");
    kfree(local_40);
    iVar1 = -0x16;
    goto LAB_00105fb8;
  }
  _raw_spin_lock(&gh_vm_table_lock);
  puVar2 = &DAT_0010c800;
  if (DAT_0010c800 == param_1) {
    lVar3 = 1;
LAB_00105f88:
    lVar3 = lVar3 * 0x28;
    *puVar2 = 0xffff;
    *(undefined8 *)(&DAT_0010c7f0 + lVar3) = 0;
    *(undefined8 *)(&DAT_0010c7f8 + lVar3) = 0;
    *(undefined8 *)(&DAT_0010c7e0 + lVar3) = 0;
    *(undefined8 *)(&DAT_0010c7e8 + lVar3) = 0;
  }
  else {
    puVar2 = &DAT_0010c828;
    if (DAT_0010c828 == param_1) {
      lVar3 = 2;
      goto LAB_00105f88;
    }
    puVar2 = &DAT_0010c850;
    if (DAT_0010c850 == param_1) {
      lVar3 = 3;
      goto LAB_00105f88;
    }
    puVar2 = &DAT_0010c878;
    if (DAT_0010c878 == param_1) {
      lVar3 = 4;
      goto LAB_00105f88;
    }
    puVar2 = &DAT_0010c8a0;
    if (DAT_0010c8a0 == param_1) {
      lVar3 = 5;
      goto LAB_00105f88;
    }
    puVar2 = &DAT_0010c8c8;
    if (DAT_0010c8c8 == param_1) {
      lVar3 = 6;
      goto LAB_00105f88;
    }
  }
  _raw_spin_unlock(&gh_vm_table_lock);
  iVar1 = 0;
LAB_00105fb8:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// gh_rm_vm_config_image @ 00105fec size=248
// signature: undefined gh_rm_vm_config_image(void)
// callers: []
//------------------------------------------------------------

int gh_rm_vm_config_image
              (undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined8 param_4,
              undefined8 param_5,undefined8 param_6,undefined4 param_7)

{
  long lVar1;
  int iVar2;
  undefined8 local_60;
  long local_58;
  undefined2 local_50;
  undefined2 local_4e;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uStack_48 = (undefined4)param_4;
  local_44 = (undefined4)((ulong)param_4 >> 0x20);
  uStack_40 = (undefined4)param_5;
  local_3c = (undefined4)((ulong)param_5 >> 0x20);
  uStack_38 = (undefined4)param_6;
  local_34 = (undefined4)((ulong)param_6 >> 0x20);
  local_60 = 0;
  local_58 = 0;
  local_50 = param_1;
  local_4e = param_2;
  local_4c = param_3;
  uStack_30 = param_7;
  iVar2 = gh_rm_call(rm,0x56000009,&local_50,0x28,&local_60,&local_58);
  if (iVar2 == 0) {
    if (local_58 == 0) {
      iVar2 = 0;
    }
    else {
      _printk(&DAT_0010a80a,"gh_rm_vm_config_image");
      kfree(local_60);
      iVar2 = -0x16;
    }
  }
  else {
    _printk(&DAT_00109da6,"gh_rm_vm_config_image",iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gh_rm_vm_auth_image @ 001060e8 size=400
// signature: undefined gh_rm_vm_auth_image(void)
// callers: []
//------------------------------------------------------------

int gh_rm_vm_auth_image(undefined2 param_1,long param_2,long param_3)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  undefined2 *puVar6;
  long lVar7;
  ulong uVar8;
  undefined8 local_58;
  long local_50;
  long local_48;
  
  lVar7 = sp_el0;
  uVar8 = param_2 << 3 | 4;
  local_48 = *(long *)(lVar7 + 0x638);
  local_58 = 0;
  local_50 = 0;
  puVar6 = (undefined2 *)__kmalloc(uVar8,0xdc0);
  if (puVar6 == (undefined2 *)0x0) {
    iVar5 = -0xc;
  }
  else {
    *puVar6 = param_1;
    puVar6[1] = (short)param_2;
    if (0 < param_2) {
      lVar7 = 0;
      do {
        if ((lVar7 << 3 < 0) || (uVar8 <= (lVar7 << 3 | 4U))) {
LAB_00106270:
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(1,0x106274);
          (*pcVar4)();
        }
        lVar3 = lVar7 * 4;
        *(undefined4 *)(puVar6 + lVar3 + 2) = *(undefined4 *)(param_3 + lVar7 * 8);
        if ((lVar7 < -1) || ((uVar2 = lVar7 * 8 + 8, uVar8 < uVar2 || (uVar8 - uVar2 < 4))))
        goto LAB_00106270;
        lVar1 = lVar7 * 8;
        lVar7 = (long)((int)lVar7 + 1);
        *(undefined4 *)((long)(puVar6 + lVar3 + 2) + 4) = *(undefined4 *)(param_3 + lVar1 + 4);
      } while (lVar7 < param_2);
    }
    iVar5 = gh_rm_call(rm,0x5600000a,puVar6,uVar8,&local_58,&local_50);
    if (iVar5 == 0) {
      if (local_50 == 0) {
        iVar5 = 0;
      }
      else {
        _printk(&DAT_0010a0d8,"gh_rm_vm_auth_image");
        kfree(local_58);
        iVar5 = -0x16;
      }
    }
    else {
      _printk(&DAT_0010a919,"gh_rm_vm_auth_image",iVar5);
    }
    kfree(puVar6);
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// ghd_rm_vm_init @ 0010627c size=212
// signature: undefined ghd_rm_vm_init(void)
// callers: []
//------------------------------------------------------------

int ghd_rm_vm_init(undefined2 param_1)

{
  long lVar1;
  int iVar2;
  undefined8 local_40;
  long local_38;
  undefined2 local_30;
  undefined2 local_2e;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2e = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = param_1;
  iVar2 = gh_rm_call(rm,0x5600000b,&local_30,4,&local_40,&local_38);
  if (iVar2 == 0) {
    if (local_38 == 0) {
      iVar2 = 0;
    }
    else {
      _printk(&DAT_0010a5b5,"ghd_rm_vm_init");
      kfree(local_40);
      iVar2 = -0x16;
    }
  }
  else {
    _printk(&DAT_0010adcf,"ghd_rm_vm_init",iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// ghd_rm_vm_start @ 00106354 size=220
// signature: undefined ghd_rm_vm_start(void)
// callers: []
//------------------------------------------------------------

int ghd_rm_vm_start(ushort param_1)

{
  long lVar1;
  int iVar2;
  long local_40;
  uint local_38 [2];
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38[0] = (uint)param_1;
  local_30 = 0;
  local_40 = 0;
  iVar2 = gh_rm_call(rm,0x56000004,local_38,4,&local_30,&local_40);
  if (iVar2 == 0) {
    if (local_40 == 0) {
      iVar2 = 0;
    }
    else {
      _printk(&DAT_00109af3,"ghd_rm_vm_start");
      kfree(local_30);
      iVar2 = -0x16;
    }
  }
  else {
    _printk(&DAT_0010b05b,"ghd_rm_vm_start",iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// ghd_rm_vm_stop @ 00106434 size=252
// signature: undefined ghd_rm_vm_stop(void)
// callers: []
//------------------------------------------------------------

int ghd_rm_vm_stop(undefined2 param_1,uint param_2,undefined1 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_40;
  long local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_30 = 0;
  local_40 = 0;
  if (param_2 < 4) {
    local_30 = (ulong)param_2 << 0x20;
    local_30._0_3_ = CONCAT12(param_3,param_1);
    iVar2 = gh_rm_call(rm,0x56000005,&local_30,8,&local_40,&local_38);
    if (iVar2 != 0) {
      _printk(&DAT_00109e72,"ghd_rm_vm_stop",iVar2);
      goto LAB_001064a4;
    }
    if (local_38 == 0) {
      iVar2 = 0;
      goto LAB_001064a4;
    }
    _printk(&DAT_0010a83f,"ghd_rm_vm_stop");
    kfree(local_40);
  }
  else {
    _printk(&DAT_0010a689,"ghd_rm_vm_stop");
  }
  iVar2 = -0x16;
LAB_001064a4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// ghd_rm_vm_reset @ 00106534 size=212
// signature: undefined ghd_rm_vm_reset(void)
// callers: []
//------------------------------------------------------------

int ghd_rm_vm_reset(undefined2 param_1)

{
  long lVar1;
  int iVar2;
  undefined8 local_40;
  long local_38;
  undefined2 local_30;
  undefined2 local_2e;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2e = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = param_1;
  iVar2 = gh_rm_call(rm,0x56000006,&local_30,4,&local_40,&local_38);
  if (iVar2 == 0) {
    if (local_38 == 0) {
      iVar2 = 0;
    }
    else {
      _printk(&DAT_0010a6b9,"ghd_rm_vm_reset");
      kfree(local_40);
      iVar2 = -0x16;
    }
  }
  else {
    _printk(&DAT_00109b80,"ghd_rm_vm_reset",iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gh_rm_console_open @ 0010660c size=220
// signature: undefined gh_rm_console_open(void)
// callers: []
//------------------------------------------------------------

int gh_rm_console_open(ushort param_1)

{
  long lVar1;
  int iVar2;
  long local_40;
  uint local_38 [2];
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38[0] = (uint)param_1;
  local_30 = 0;
  local_40 = 0;
  iVar2 = gh_rm_call(rm,0x56000081,local_38,4,&local_30,&local_40);
  if (iVar2 == 0) {
    if (local_40 == 0) {
      iVar2 = 0;
    }
    else {
      _printk(&DAT_0010a341,"gh_rm_console_open");
      kfree(local_30);
      iVar2 = -0x16;
    }
  }
  else {
    _printk(&DAT_0010a018,"gh_rm_console_open",iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gh_rm_console_close @ 001066ec size=220
// signature: undefined gh_rm_console_close(void)
// callers: []
//------------------------------------------------------------

int gh_rm_console_close(ushort param_1)

{
  long lVar1;
  int iVar2;
  long local_40;
  uint local_38 [2];
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38[0] = (uint)param_1;
  local_30 = 0;
  local_40 = 0;
  iVar2 = gh_rm_call(rm,0x56000082,local_38,4,&local_30,&local_40);
  if (iVar2 == 0) {
    if (local_40 == 0) {
      iVar2 = 0;
    }
    else {
      _printk(&DAT_0010a193,"gh_rm_console_close");
      kfree(local_30);
      iVar2 = -0x16;
    }
  }
  else {
    _printk(&DAT_0010a942,"gh_rm_console_close",iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gh_rm_console_write @ 001067cc size=324
// signature: undefined gh_rm_console_write(void)
// callers: []
//------------------------------------------------------------

int gh_rm_console_write(undefined2 param_1,void *param_2,size_t param_3)

{
  long lVar1;
  int iVar2;
  undefined2 *puVar3;
  long local_58;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  local_50 = 0;
  if (0xffffffff00000004 < param_3 - 0xfffffffc) {
    puVar3 = (undefined2 *)__kmalloc(param_3 + 4,0xdc0);
    if (puVar3 == (undefined2 *)0x0) {
      iVar2 = -0xc;
      goto LAB_0010689c;
    }
    *puVar3 = param_1;
    puVar3[1] = (short)param_3;
    memcpy(puVar3 + 2,param_2,param_3);
    iVar2 = gh_rm_call(rm,0x56000083,puVar3,param_3 + 4,&local_50,&local_58);
    kfree(puVar3);
    if (iVar2 != 0) {
      _printk(&DAT_0010a87c,"gh_rm_console_write",iVar2);
      goto LAB_0010689c;
    }
    if (local_58 == 0) {
      iVar2 = 0;
      goto LAB_0010689c;
    }
    _printk(&DAT_0010a5e2,"gh_rm_console_write");
    kfree(local_50);
  }
  iVar2 = -0x16;
LAB_0010689c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gh_rm_console_flush @ 00106914 size=220
// signature: undefined gh_rm_console_flush(void)
// callers: []
//------------------------------------------------------------

int gh_rm_console_flush(ushort param_1)

{
  long lVar1;
  int iVar2;
  long local_40;
  uint local_38 [2];
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38[0] = (uint)param_1;
  local_30 = 0;
  local_40 = 0;
  iVar2 = gh_rm_call(rm,0x56000084,local_38,4,&local_30,&local_40);
  if (iVar2 == 0) {
    if (local_40 == 0) {
      iVar2 = 0;
    }
    else {
      _printk(&DAT_00109b21,"gh_rm_console_flush");
      kfree(local_30);
      iVar2 = -0x16;
    }
  }
  else {
    _printk(&DAT_0010a1c6,"gh_rm_console_flush",iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gh_rm_mem_qcom_lookup_sgl @ 001069f4 size=448
// signature: undefined gh_rm_mem_qcom_lookup_sgl(void)
// callers: []
//------------------------------------------------------------

ulong gh_rm_mem_qcom_lookup_sgl
                (byte param_1,undefined4 param_2,uint *param_3,ushort *param_4,ushort *param_5,
                undefined4 *param_6)

{
  long lVar1;
  uint uVar2;
  byte *pbVar3;
  ulong uVar4;
  ulong uVar5;
  long local_68;
  undefined4 *local_60;
  long local_58;
  
  lVar1 = sp_el0;
  uVar5 = 0xffffffea;
  local_58 = *(long *)(lVar1 + 0x638);
  local_68 = 0;
  local_60 = (undefined4 *)0x0;
  if ((((param_1 < 2) && (param_3 != (uint *)0x0)) && (param_4 != (ushort *)0x0)) &&
     (((*param_3 != 0 && (param_6 != (undefined4 *)0x0)) && (*param_4 != 0)))) {
    if (param_5 == (ushort *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (ulong)*param_5;
      if (uVar4 == 0) goto LAB_00106b2c;
    }
    lVar1 = (uVar4 + *param_3) * 4 + (ulong)*param_4 * 0x10 + 0x14;
    pbVar3 = (byte *)__kmalloc(lVar1,0xdc0);
    if (pbVar3 == (byte *)0x0) {
      uVar5 = 0xfffffff4;
    }
    else if (pbVar3 < (byte *)0xfffffffffffff001) {
      *pbVar3 = param_1;
      *(undefined4 *)(pbVar3 + 4) = param_2;
      gh_rm_populate_mem_request(pbVar3,0x5100001a,param_3,param_4,0,param_5);
      uVar2 = gh_rm_call(rm,0x5100001a,pbVar3,lVar1,&local_60,&local_68);
      if (uVar2 == 0) {
        if (local_68 == 4) {
          uVar5 = 0;
          *param_6 = *local_60;
        }
        else {
          _printk(&DAT_0010ab6c,"gh_rm_mem_qcom_lookup_sgl");
          if (local_68 != 0) {
            kfree(local_60);
          }
          uVar5 = 0xffffffea;
        }
      }
      else {
        uVar5 = (ulong)uVar2;
        _printk(&DAT_00109f39,"gh_rm_mem_qcom_lookup_sgl",uVar5);
      }
      kfree(pbVar3);
    }
    else {
      uVar5 = (ulong)pbVar3 & 0xffffffff;
    }
  }
LAB_00106b2c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// gh_rm_populate_mem_request @ 00106bb4 size=308
// signature: undefined gh_rm_populate_mem_request(void)
// callers: [gh_rm_mem_qcom_lookup_sgl, gh_rm_mem_accept, gh_rm_mem_share_lend_helper]
//------------------------------------------------------------

void gh_rm_populate_mem_request
               (long param_1,int param_2,uint *param_3,ushort *param_4,undefined2 param_5,
               ushort *param_6)

{
  uint *puVar1;
  undefined2 *puVar2;
  ushort *puVar3;
  ushort uVar4;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  uint uVar8;
  long lVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  
  if (param_3 == (uint *)0x0) {
    lVar5 = 4;
  }
  else {
    lVar5 = (ulong)*param_3 * 4 + 4;
  }
  if (param_4 == (ushort *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (uint)*param_4;
  }
  if (0x1ff < uVar6) {
    uVar6 = 0x200;
  }
  uVar8 = param_2 + 0xaefffff0;
  if (10 < uVar8) {
    return;
  }
  if ((0x40fU >> (ulong)(uVar8 & 0x1f) & 1) == 0) {
    return;
  }
  lVar9 = *(long *)(&DAT_00109980 + (long)(int)uVar8 * 8);
  puVar1 = (uint *)(param_1 + lVar9);
  puVar2 = (undefined2 *)((long)puVar1 + lVar5);
  if (param_3 == (uint *)0x0) {
    *puVar1 = 0;
  }
  else {
    uVar8 = *param_3;
    uVar7 = (ulong)uVar8;
    *puVar1 = uVar8;
    if (uVar8 != 0) {
      puVar10 = (undefined1 *)(lVar9 + param_1 + 6);
      puVar11 = (undefined1 *)((long)param_3 + 6);
      do {
        uVar7 = uVar7 - 1;
        *(undefined2 *)(puVar10 + -2) = *(undefined2 *)(puVar11 + -2);
        *puVar10 = *puVar11;
        puVar10 = puVar10 + 4;
        puVar11 = puVar11 + 4;
      } while (uVar7 != 0);
    }
  }
  if (param_4 == (ushort *)0x0) {
    uVar8 = 0;
  }
  else {
    uVar8 = (uint)*param_4;
  }
  if (0x1ff < uVar8) {
    uVar8 = 0x200;
  }
  puVar3 = (ushort *)((long)puVar2 + (ulong)(uVar6 << 4 | 4));
  puVar2[1] = param_5;
  *puVar2 = (short)uVar8;
  if (uVar8 != 0) {
    memcpy(puVar2 + 2,param_4 + 2,(ulong)(uVar8 << 4));
  }
  if (param_6 == (ushort *)0x0) {
    *puVar3 = 0;
  }
  else {
    uVar4 = *param_6;
    *puVar3 = uVar4;
    if ((ulong)uVar4 != 0) {
      memcpy(puVar3 + 2,param_6 + 2,(ulong)uVar4 << 2);
    }
  }
  return;
}



//------------------------------------------------------------
// gh_rm_mem_release @ 00106cec size=232
// signature: undefined gh_rm_mem_release(void)
// callers: [gh_rm_mem_accept]
//------------------------------------------------------------

int gh_rm_mem_release(undefined4 param_1,uint param_2)

{
  long lVar1;
  int iVar2;
  long local_50;
  undefined8 local_48;
  undefined4 local_40;
  uint uStack_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_50 = 0;
  local_48 = 0;
  if ((param_2 & 0xff) < 2) {
    local_40 = param_1;
    uStack_3c = param_2 & 0xff;
    iVar2 = gh_rm_call(rm,0x51000014,&local_40,8,&local_48,&local_50);
    if (iVar2 == 0) {
      if (local_50 == 0) {
        iVar2 = 0;
      }
      else {
        kfree(local_48);
        iVar2 = -0x4a;
      }
    }
    else {
      _printk(&DAT_00109f39,"gh_rm_mem_release_helper",iVar2);
    }
  }
  else {
    iVar2 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// ghd_rm_mem_reclaim @ 00106f10 size=232
// signature: undefined ghd_rm_mem_reclaim(void)
// callers: [gh_rm_mem_share_lend_helper]
//------------------------------------------------------------

int ghd_rm_mem_reclaim(undefined4 param_1,uint param_2)

{
  long lVar1;
  int iVar2;
  long local_50;
  undefined8 local_48;
  undefined4 local_40;
  uint uStack_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_50 = 0;
  local_48 = 0;
  if ((param_2 & 0xff) < 2) {
    local_40 = param_1;
    uStack_3c = param_2 & 0xff;
    iVar2 = gh_rm_call(rm,0x51000015,&local_40,8,&local_48,&local_50);
    if (iVar2 == 0) {
      if (local_50 == 0) {
        iVar2 = 0;
      }
      else {
        kfree(local_48);
        iVar2 = -0x4a;
      }
    }
    else {
      _printk(&DAT_00109f39,"gh_rm_mem_release_helper",iVar2);
    }
  }
  else {
    iVar2 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gh_rm_mem_accept @ 00107134 size=1484
// signature: undefined gh_rm_mem_accept(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort * gh_rm_mem_accept(undefined4 param_1,byte param_2,byte param_3,uint param_4,
                         undefined4 param_5,uint *param_6,ushort *param_7,ushort *param_8,
                         undefined2 param_9)

{
  long lVar1;
  long *plVar2;
  ushort uVar3;
  undefined8 uVar4;
  int iVar5;
  ushort *puVar6;
  long *plVar7;
  long *plVar8;
  uint uVar9;
  ulong uVar10;
  ulong uVar11;
  ushort *puVar12;
  ushort *__dest;
  long *plVar13;
  long lVar14;
  ulong local_80;
  ushort *local_78;
  undefined4 local_6c;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  local_78 = (ushort *)0x0;
  local_80 = 0;
  puVar12 = (ushort *)0xffffffffffffffea;
  local_6c = param_1;
  if ((((param_2 < 2) && (param_3 < 3)) && ((param_4 & 0x68) == 0)) &&
     ((param_7 == (ushort *)0x0 || (*param_7 < 0x201)))) {
    if (((param_4 & 0xff) >> 1 & 1) == 0) {
      uVar10 = 0;
      uVar9 = 0;
    }
    else if ((param_6 == (uint *)0x0) || (uVar9 = *param_6, uVar9 == 0)) {
      if ((param_8 == (ushort *)0x0) || (uVar10 = (ulong)*param_8, *param_8 == 0))
      goto LAB_001071bc;
      if (param_6 == (uint *)0x0) {
        uVar9 = 0;
      }
      else {
        uVar9 = *param_6;
      }
    }
    else if (param_8 == (ushort *)0x0) {
      uVar10 = 0;
    }
    else {
      uVar10 = (ulong)*param_8;
    }
    if (param_7 == (ushort *)0x0) {
      uVar11 = 0xc;
    }
    else {
      uVar11 = (ulong)*param_7 << 4 | 0xc;
    }
    lVar1 = uVar11 + (uVar10 + uVar9) * 4 + 0xc;
    puVar6 = (ushort *)__kmalloc(lVar1,0xdc0);
    if (puVar6 == (ushort *)0x0) {
      puVar12 = (ushort *)0xfffffffffffffff4;
    }
    else {
      puVar12 = puVar6;
      if (puVar6 < (ushort *)0xfffffffffffff001) {
        *(undefined4 *)puVar6 = param_1;
        *(byte *)(puVar6 + 2) = param_2;
        *(byte *)((long)puVar6 + 5) = param_3;
        *(char *)(puVar6 + 3) = (char)param_4;
        if (((param_4 & 0xff) >> 2 & 1) != 0) {
          *(undefined4 *)(puVar6 + 4) = param_5;
        }
        gh_rm_populate_mem_request(puVar6,0x51000011,param_6,param_7,param_9,param_8);
        uVar9 = param_4 >> 4 & 1;
        if (param_7 != (ushort *)0x0) {
          uVar9 = 1;
        }
        if (uVar9 == 0) {
          *(byte *)(puVar6 + 3) = (byte)puVar6[3] & 0x7f;
        }
        plVar7 = (long *)kmalloc_trace(_gic_nonsecure_priorities,0xdc0,0x18);
        if (plVar7 == (long *)0x0) {
          iVar5 = -0xc;
        }
        else {
          *plVar7 = (long)plVar7;
          plVar7[1] = (long)plVar7;
          iVar5 = gh_rm_call(rm,0x51000011,puVar6,lVar1,&local_78,&local_80);
          if (iVar5 == 0) {
            do {
              puVar12 = local_78;
              if (param_7 == (ushort *)0x0) {
                if (local_80 < 4) {
                  uVar10 = 4;
                }
                else {
                  uVar10 = (ulong)*local_78 << 4 | 4;
                }
              }
              else {
                uVar10 = 0;
              }
              if (uVar10 != local_80) {
                _printk(&DAT_0010aea9,"gh_rm_mem_accept_check_resp");
                if (local_80 == 0) {
                  iVar5 = -0x16;
                  goto LAB_00107650;
                }
                kfree(local_78);
LAB_00107498:
                uVar4 = rm;
                if (-1 < (char)param_4) {
                  uVar9 = 1;
                }
                if (uVar9 == 0) {
                  *(byte *)(puVar6 + 3) = (byte)puVar6[3] | 0x80;
                  iVar5 = gh_rm_call(uVar4,0x51000011,puVar6,lVar1,&local_78,&local_80);
                  if (iVar5 != 0) {
                    _printk(&DAT_0010a615,"gh_rm_mem_accept",iVar5);
                    goto LAB_00107650;
                  }
                  if (local_80 != 0) {
                    kfree(local_78);
                  }
                }
                else {
                  puVar12 = param_7;
                  if (param_7 != (ushort *)0x0) goto LAB_001075ac;
                }
                puVar12 = (ushort *)
                          kvmalloc_node((ulong)*(ushort *)(plVar7 + 2) << 4 | 4,0xcc0,0xffffffff);
                if (puVar12 != (ushort *)0x0) {
                  if ((long *)*plVar7 != plVar7) {
                    __dest = puVar12 + 2;
                    plVar8 = (long *)*plVar7;
                    do {
                      plVar13 = (long *)*plVar8;
                      memcpy(__dest,(ushort *)plVar8[2] + 2,(ulong)*(ushort *)plVar8[2] << 4);
                      uVar3 = *(ushort *)plVar8[2];
                      uVar10 = __list_del_entry_valid(plVar8);
                      if ((uVar10 & 1) != 0) {
                        lVar1 = *plVar8;
                        plVar2 = (long *)plVar8[1];
                        *(long **)(lVar1 + 8) = plVar2;
                        *plVar2 = lVar1;
                      }
                      __dest = __dest + (ulong)uVar3 * 8;
                      *plVar8 = -0x2152ffffffffff00;
                      plVar8[1] = -0x2152fffffffffede;
                      kfree(plVar8[2]);
                      kfree(plVar8);
                      plVar8 = plVar13;
                    } while (plVar13 != plVar7);
                  }
                  uVar3 = *(ushort *)(plVar7 + 2);
                  *(undefined2 *)(plVar7 + 2) = 0;
                  *puVar12 = uVar3;
                  if ((ushort *)0xfffffffffffff000 < puVar12) {
                    iVar5 = (int)puVar12;
                    goto LAB_00107650;
                  }
LAB_001075ac:
                  plVar8 = (long *)*plVar7;
                  while (plVar8 != plVar7) {
                    plVar13 = (long *)*plVar8;
                    uVar10 = __list_del_entry_valid(plVar8);
                    if ((uVar10 & 1) != 0) {
                      lVar1 = *plVar8;
                      plVar2 = (long *)plVar8[1];
                      *(long **)(lVar1 + 8) = plVar2;
                      *plVar2 = lVar1;
                    }
                    *plVar8 = -0x2152ffffffffff00;
                    plVar8[1] = -0x2152fffffffffede;
                    kfree(plVar8[2]);
                    kfree(plVar8);
                    plVar8 = plVar13;
                  }
                  kfree(plVar7);
                  kfree(puVar6);
                  goto LAB_001071bc;
                }
                iVar5 = -0xc;
                goto LAB_00107650;
              }
              if (local_80 == 0) goto LAB_00107498;
              if ((*(ushort *)(plVar7 + 2) ^ 0xffff) < *local_78) {
                _printk(&DAT_0010a75a,"gh_sgl_fragment_append");
LAB_00107644:
                kfree(local_78);
                iVar5 = -0xc;
                goto LAB_00107650;
              }
              plVar8 = (long *)kmalloc_trace(_gic_nonsecure_priorities,0xdc0,0x18);
              if (plVar8 == (long *)0x0) goto LAB_00107644;
              lVar14 = *plVar7;
              plVar8[2] = (long)puVar12;
              uVar10 = __list_add_valid(plVar8,plVar7,lVar14);
              if ((uVar10 & 1) != 0) {
                *(long **)(lVar14 + 8) = plVar8;
                *plVar8 = lVar14;
                plVar8[1] = (long)plVar7;
                *plVar7 = (long)plVar8;
              }
              *(ushort *)(plVar7 + 2) = (short)plVar7[2] + *puVar12;
              if ((local_78[1] & 1) == 0) goto LAB_00107498;
              iVar5 = gh_rm_call(rm,0x51000011,puVar6,lVar1,&local_78,&local_80);
            } while (iVar5 == 0);
            _printk(&DAT_0010a615,"gh_rm_mem_accept",iVar5);
LAB_00107650:
            gh_rm_mem_release(local_6c,0);
          }
          else {
            _printk(&DAT_0010a615,"gh_rm_mem_accept",iVar5);
          }
          plVar8 = (long *)*plVar7;
          while (plVar8 != plVar7) {
            plVar13 = (long *)*plVar8;
            uVar10 = __list_del_entry_valid(plVar8);
            if ((uVar10 & 1) != 0) {
              lVar1 = *plVar8;
              plVar2 = (long *)plVar8[1];
              *(long **)(lVar1 + 8) = plVar2;
              *plVar2 = lVar1;
            }
            *plVar8 = -0x2152ffffffffff00;
            plVar8[1] = -0x2152fffffffffede;
            kfree(plVar8[2]);
            kfree(plVar8);
            plVar8 = plVar13;
          }
          kfree(plVar7);
        }
        kfree(puVar6);
        puVar12 = (ushort *)(long)iVar5;
      }
    }
  }
LAB_001071bc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar12;
}



//------------------------------------------------------------
// gh_rm_mem_append @ 001078f8 size=332
// signature: undefined gh_rm_mem_append(void)
// callers: [gh_rm_mem_share_lend_helper]
//------------------------------------------------------------

int gh_rm_mem_append(undefined4 param_1,byte param_2,void *param_3,uint param_4)

{
  ulong uVar1;
  long lVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined8 local_58;
  long local_50;
  long local_48;
  
  lVar2 = sp_el0;
  iVar3 = -0x16;
  local_48 = *(long *)(lVar2 + 0x638);
  local_58 = 0;
  local_50 = 0;
  if ((param_2 < 2) && (param_4 < 0x201)) {
    uVar1 = (ulong)param_4 << 4 | 0xc;
    puVar4 = (undefined4 *)__kmalloc(uVar1,0xcc0);
    if (puVar4 == (undefined4 *)0x0) {
      iVar3 = -0xc;
    }
    else {
      *puVar4 = param_1;
      *(byte *)(puVar4 + 1) = param_2;
      *(short *)(puVar4 + 2) = (short)param_4;
      memcpy(puVar4 + 3,param_3,(ulong)param_4 << 4);
      iVar3 = gh_rm_call(rm,0x51000018,puVar4,uVar1,&local_58,&local_50);
      if (iVar3 == 0) {
        if (local_50 == 0) {
          iVar3 = 0;
        }
        else {
          _printk(&DAT_0010afc1,"gh_rm_mem_append");
          kfree(local_58);
          iVar3 = -0x16;
        }
      }
      else {
        _printk(&DAT_0010a615,"gh_rm_mem_append",iVar3);
      }
      kfree(puVar4);
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// ghd_rm_mem_share @ 00107a48 size=104
// signature: undefined ghd_rm_mem_share(void)
// callers: []
//------------------------------------------------------------

void ghd_rm_mem_share(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                     undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  gh_rm_mem_share_lend_helper(0x51000013,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



//------------------------------------------------------------
// gh_rm_mem_share_lend_helper @ 00107c3c size=700
// signature: undefined gh_rm_mem_share_lend_helper(void)
// callers: [gh_rm_mem_donate, ghd_rm_mem_lend, ghd_rm_mem_share]
//------------------------------------------------------------

ulong gh_rm_mem_share_lend_helper
                (int param_1,byte param_2,byte param_3,undefined4 param_4,uint *param_5,
                ushort *param_6,ushort *param_7,undefined4 *param_8)

{
  long lVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  ulong uVar8;
  uint uVar9;
  byte *pbVar10;
  long local_78;
  undefined4 *local_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  local_78 = 0;
  local_70 = (undefined4 *)0x0;
  if ((param_2 < 2) && ((param_1 + 0xaeffffecU < 0xfffffffe || (param_3 < 2)))) {
    if (param_1 == 0x51000010) {
      pbVar10 = (byte *)0xffffffea;
      if ((1 < param_3) || (param_5 == (uint *)0x0)) goto LAB_00107cbc;
    }
    else if (param_5 == (uint *)0x0) goto LAB_00107cb8;
    pbVar10 = (byte *)0xffffffea;
    if ((param_6 == (ushort *)0x0) || (*param_5 == 0)) goto LAB_00107cbc;
    uVar3 = *param_6;
    if (uVar3 != 0) {
      if (param_7 == (ushort *)0x0) {
        if (param_8 == (undefined4 *)0x0) goto LAB_00107cb8;
        uVar8 = 0;
      }
      else {
        pbVar10 = (byte *)0xffffffea;
        if ((param_8 == (undefined4 *)0x0) || (uVar8 = (ulong)*param_7, *param_7 == 0))
        goto LAB_00107cbc;
      }
      uVar9 = (uint)uVar3;
      if (0x1ff < uVar3) {
        uVar9 = 0x200;
      }
      bVar2 = param_3 | 2;
      if (uVar3 < 0x201) {
        bVar2 = param_3;
      }
      uVar5 = param_1 + 0xaefffff0;
      if ((10 < uVar5) || ((0x40fU >> (ulong)(uVar5 & 0x1f) & 1) == 0)) {
        pbVar10 = (byte *)0xffffffffffffffea;
        goto LAB_00107cbc;
      }
      lVar1 = ((ulong)(uVar9 << 4 | 0xc) & 0xfffc) + (uVar8 + ((ulong)*param_5 & 0xffff)) * 4 +
              *(long *)(&DAT_00109980 + (long)(int)uVar5 * 8);
      pbVar6 = (byte *)__kmalloc(lVar1,0xdc0);
      if (pbVar6 == (byte *)0x0) {
        pbVar10 = (byte *)0xfffffffffffffff4;
        goto LAB_00107cbc;
      }
      pbVar10 = pbVar6;
      if ((byte *)0xfffffffffffff000 < pbVar6) goto LAB_00107cbc;
      *pbVar6 = param_2;
      pbVar6[2] = bVar2;
      *(undefined4 *)(pbVar6 + 4) = param_4;
      gh_rm_populate_mem_request(pbVar6,param_1,param_5,param_6,0,param_7);
      uVar5 = gh_rm_call(rm,param_1,pbVar6,lVar1,&local_70,&local_78);
      if (uVar5 == 0) {
        if (local_78 != 0) {
          if (local_78 == 4) {
            do {
              uVar3 = *param_6;
              uVar5 = (uint)uVar3;
              if (uVar5 <= uVar9) {
                *param_8 = *local_70;
                kfree();
                kfree(pbVar6);
                pbVar10 = (byte *)0x0;
                goto LAB_00107cbc;
              }
              uVar7 = uVar9 + 0x200;
              bVar4 = uVar5 <= uVar7;
              if (bVar4) {
                uVar7 = (uint)uVar3;
              }
              uVar5 = gh_rm_mem_append(*local_70,bVar4,param_6 + (ulong)uVar9 * 8 + 2,uVar7 - uVar9)
              ;
              uVar9 = uVar7;
            } while (uVar5 == 0);
            pbVar10 = (byte *)(ulong)uVar5;
            ghd_rm_mem_reclaim(*local_70,0);
            kfree(local_70);
            goto LAB_00107ea4;
          }
          kfree(local_70);
        }
        pbVar10 = (byte *)0xffffffea;
      }
      else {
        pbVar10 = (byte *)(ulong)uVar5;
        _printk(&DAT_0010a615,"gh_rm_mem_share_lend_helper",pbVar10);
      }
LAB_00107ea4:
      kfree(pbVar6);
      goto LAB_00107cbc;
    }
  }
LAB_00107cb8:
  pbVar10 = (byte *)0xffffffea;
LAB_00107cbc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)pbVar10 & 0xffffffff;
}



//------------------------------------------------------------
// ghd_rm_mem_lend @ 00107efc size=104
// signature: undefined ghd_rm_mem_lend(void)
// callers: []
//------------------------------------------------------------

void ghd_rm_mem_lend(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                    undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  gh_rm_mem_share_lend_helper(0x51000012,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



//------------------------------------------------------------
// gh_rm_mem_donate @ 001080f4 size=168
// signature: undefined gh_rm_mem_donate(void)
// callers: []
//------------------------------------------------------------

undefined8
gh_rm_mem_donate(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
                undefined8 param_5,undefined8 param_6)

{
  undefined8 uVar1;
  undefined *puVar2;
  
  if (*param_4 == 1) {
    if (*(char *)((long)param_4 + 6) == '\a') {
      uVar1 = gh_rm_mem_share_lend_helper(0x51000010,param_1);
      return uVar1;
    }
    puVar2 = &DAT_0010a432;
  }
  else {
    puVar2 = &DAT_0010a1ee;
  }
  _printk(puVar2,"gh_rm_mem_donate",param_2,param_3,param_4,param_5,param_6);
  return 0xffffffea;
}



//------------------------------------------------------------
// gh_rm_mem_notify @ 00108328 size=452
// signature: undefined gh_rm_mem_notify(void)
// callers: []
//------------------------------------------------------------

int gh_rm_mem_notify(undefined4 param_1,byte param_2,undefined4 param_3,ushort *param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  long local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  if ((((param_2 < 8) && (((param_2 & 1) == 0 || ((param_4 != (ushort *)0x0 && (*param_4 != 0))))))
      && (((param_2 & 6) == 0 || (param_4 == (ushort *)0x0)))) &&
     (iVar2 = __sw_hweight8(param_2), iVar2 == 1)) {
    if ((param_2 & 1) == 0) {
      uVar7 = 0;
      uVar6 = 0xc;
    }
    else {
      uVar7 = (ulong)*param_4;
      uVar6 = uVar7 * 4 + 0x10;
    }
    puVar3 = (undefined4 *)__kmalloc(uVar6,0xdc0);
    if (puVar3 == (undefined4 *)0x0) {
      iVar2 = -0xc;
    }
    else {
      *puVar3 = param_1;
      *(byte *)(puVar3 + 1) = param_2;
      puVar3[2] = param_3;
      if ((param_2 & 1) != 0) {
        if (uVar6 == 0xc) {
LAB_001084f4:
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(1,0x1084f8);
          (*pcVar1)();
        }
        *(short *)(puVar3 + 3) = (short)uVar7;
        if (uVar7 != 0) {
          lVar4 = 0;
          uVar5 = uVar6 - 0x10;
          do {
            if ((uVar6 < lVar4 + 0x10U) || (uVar5 < 2)) goto LAB_001084f4;
            uVar5 = uVar5 - 4;
            *(undefined2 *)((long)puVar3 + lVar4 + 0x10) =
                 *(undefined2 *)((long)param_4 + lVar4 + 4);
            lVar4 = lVar4 + 4;
          } while (uVar7 * 4 != lVar4);
        }
      }
      iVar2 = gh_rm_call(rm,0x51000017,puVar3,uVar6,&uStack_60,&local_68);
      if (iVar2 != 0) {
        _printk(&DAT_00109f39,"gh_rm_mem_notify",iVar2);
      }
      if (local_68 != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1084e4);
        (*pcVar1)();
      }
      kfree(puVar3);
    }
  }
  else {
    iVar2 = -0x16;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gh_rm_vm_set_time_base @ 001085a0 size=368
// signature: undefined gh_rm_vm_set_time_base(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int gh_rm_vm_set_time_base(ushort param_1)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 local_60;
  long local_58;
  long local_50;
  long local_48;
  uint local_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  local_50 = 0;
  local_48 = 0;
  local_60 = 0;
  local_58 = 0;
  local_40 = (uint)param_1;
  uVar1 = daif;
  daif = uVar1 | 0xc0;
  ktime_get_real_ts64(0x60,&local_58);
  if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x108604);
    (*pcVar2)();
  }
  uVar4 = (*_arch_timer_read_counter)();
  uVar1 = daif;
  daif = uVar1 & 0xffffffffffffff3f;
  if (local_58 < 0x225c17d04) {
    if (local_58 < -0x225c17d03) {
      lVar5 = -0x8000000000000000;
    }
    else {
      lVar5 = local_50 + local_58 * 1000000000;
    }
  }
  else {
    lVar5 = 0x7fffffffffffffff;
  }
  local_3c = (undefined4)lVar5;
  uStack_38 = (undefined4)((ulong)lVar5 >> 0x20);
  local_34 = (undefined4)uVar4;
  uStack_30 = (undefined4)((ulong)uVar4 >> 0x20);
  iVar3 = gh_rm_call(rm,0x56000030,&local_40,0x14,&local_60,&local_48);
  if (iVar3 == 0) {
    if (local_48 == 0) {
      iVar3 = 0;
    }
    else {
      _printk(&DAT_0010a03f,"gh_rm_vm_set_time_base");
      iVar3 = -0x16;
    }
  }
  else {
    _printk(&DAT_0010ab8b,"gh_rm_vm_set_time_base",iVar3);
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// gh_rm_minidump_get_info @ 0010871c size=244
// signature: undefined gh_rm_minidump_get_info(void)
// callers: []
//------------------------------------------------------------

uint gh_rm_minidump_get_info(void)

{
  long lVar1;
  uint uVar2;
  long local_40;
  ushort *local_38;
  undefined4 local_30 [2];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30[0] = 0;
  local_40 = 0;
  local_38 = (ushort *)0x0;
  if (rm == 0) {
    uVar2 = 0xfffffdfb;
  }
  else {
    uVar2 = gh_rm_call(rm,0x56000040,local_30,4,&local_38,&local_40);
    if (uVar2 == 0) {
      if (local_40 == 4) {
        uVar2 = (uint)*local_38;
        kfree();
      }
      else {
        _printk(&DAT_0010afc1,"gh_rm_minidump_get_info");
        if (local_40 != 0) {
          kfree(local_38);
        }
        uVar2 = 0xffffffea;
      }
    }
    else {
      _printk(&DAT_0010a542,"gh_rm_minidump_get_info",local_38,uVar2);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// gh_rm_minidump_register_range @ 00108814 size=348
// signature: undefined gh_rm_minidump_register_range(void)
// callers: []
//------------------------------------------------------------

uint gh_rm_minidump_register_range
               (undefined8 param_1,undefined8 param_2,void *param_3,size_t param_4)

{
  long lVar1;
  uint uVar2;
  undefined8 *puVar3;
  long local_58;
  ushort *local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  local_50 = (ushort *)0x0;
  if (param_3 == (void *)0x0) {
    uVar2 = 0xffffffea;
  }
  else {
    puVar3 = (undefined8 *)__kmalloc(param_4 + 0x14,0xcc0);
    if (puVar3 == (undefined8 *)0x0) {
      uVar2 = 0xfffffff4;
    }
    else {
      *puVar3 = param_1;
      puVar3[1] = param_2;
      *(uint *)(puVar3 + 2) =
           (uint)param_4 & 0xff | (uint)*(ushort *)((long)puVar3 + 0x12) << 0x10 | 0x1c00;
      memcpy((void *)((long)puVar3 + 0x14),param_3,param_4);
      uVar2 = gh_rm_call(rm,0x56000041,puVar3,param_4 + 0x14,&local_50,&local_58);
      if (uVar2 == 0) {
        if (local_58 == 4) {
          uVar2 = (uint)*local_50;
        }
        else {
          _printk(&DAT_0010afc1,"gh_rm_minidump_register_range");
          if (local_58 != 0) {
            kfree(local_50);
          }
          uVar2 = 0xffffffea;
        }
      }
      else {
        _printk(&DAT_0010a542,"gh_rm_minidump_register_range",local_50,uVar2);
      }
      kfree(puVar3);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// gh_rm_minidump_deregister_slot @ 00108974 size=224
// signature: undefined gh_rm_minidump_deregister_slot(void)
// callers: []
//------------------------------------------------------------

int gh_rm_minidump_deregister_slot(ushort param_1)

{
  long lVar1;
  int iVar2;
  long local_40;
  undefined8 local_38;
  uint local_30 [2];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30[0] = (uint)param_1;
  local_40 = 0;
  local_38 = 0;
  iVar2 = gh_rm_call(rm,0x56000042,local_30,4,&local_38,&local_40);
  if (iVar2 == 0) {
    if (local_40 == 0) {
      iVar2 = 0;
    }
    else {
      kfree(local_38);
      _printk(&DAT_0010afc1,"gh_rm_minidump_deregister_slot",local_40);
      iVar2 = -0x16;
    }
  }
  else {
    _printk(&DAT_0010a542,"gh_rm_minidump_deregister_slot",local_38,iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gh_rm_minidump_get_slot_from_name @ 00108a58 size=332
// signature: undefined gh_rm_minidump_get_slot_from_name(void)
// callers: []
//------------------------------------------------------------

uint gh_rm_minidump_get_slot_from_name(undefined2 param_1,void *param_2,size_t param_3)

{
  long lVar1;
  uint uVar2;
  undefined1 *puVar3;
  long local_58;
  ushort *local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  local_50 = (ushort *)0x0;
  if (param_2 == (void *)0x0) {
    uVar2 = 0xffffffea;
  }
  else {
    puVar3 = (undefined1 *)__kmalloc(param_3 + 8,0xdc0);
    if (puVar3 == (undefined1 *)0x0) {
      uVar2 = 0xfffffff4;
    }
    else {
      *puVar3 = (char)param_3;
      *(undefined2 *)(puVar3 + 4) = param_1;
      memcpy(puVar3 + 8,param_2,param_3);
      uVar2 = gh_rm_call(rm,0x56000043,puVar3,param_3 + 8,&local_50,&local_58);
      if (uVar2 == 0) {
        if (local_58 == 4) {
          uVar2 = (uint)*local_50;
          kfree();
        }
        else {
          if (local_58 != 0) {
            kfree(local_50);
          }
          _printk(&DAT_0010afc1,"gh_rm_minidump_get_slot_from_name",local_58);
          uVar2 = 0xffffffea;
        }
      }
      else {
        _printk(&DAT_0010a542,"gh_rm_minidump_get_slot_from_name",local_50,uVar2);
      }
      kfree(puVar3);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// gh_rm_ipa_reserve @ 00108ba8 size=352
// signature: undefined gh_rm_ipa_reserve(void)
// callers: []
//------------------------------------------------------------

int gh_rm_ipa_reserve(undefined8 param_1,undefined8 param_2,ulong param_3,long param_4,uint param_5,
                     uint param_6,undefined8 *param_7)

{
  ulong uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  long local_68;
  long local_60;
  undefined4 local_58;
  uint local_54;
  uint uStack_50;
  undefined4 local_4c;
  ulong local_48;
  ulong uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_58 = 0;
  local_68 = 0;
  local_60 = 0;
  if (gh_rm_core_initialized == '\0') {
    iVar3 = -0x205;
  }
  else {
    iVar4 = -0x16;
    uVar1 = 0xfffffffffffff000;
    if (param_4 - param_3 != -1) {
      uVar1 = (param_4 - param_3) + 1;
    }
    iVar3 = iVar4;
    if (((((param_5 & 0xffffffb0) == 0) && (param_6 < 8)) &&
        ((((uint)param_2 | (uint)param_1) & 0xfff) == 0)) &&
       (((param_3 & 0xfff) == 0 && ((uVar1 & 0xfff) == 0)))) {
      local_58 = 1;
      local_4c = 1;
      local_54 = param_5;
      uStack_50 = param_6;
      local_48 = param_3;
      uStack_40 = uVar1;
      local_38 = param_1;
      uStack_30 = param_2;
      iVar3 = gh_rm_call(rm,0x560000b0,&local_58,0x30,&local_60,&local_68);
      if (iVar3 == 0) {
        if (local_68 == 0xc) {
          *param_7 = *(undefined8 *)(local_60 + 4);
          kfree();
          iVar3 = 0;
        }
        else {
          _printk(&DAT_0010b092,"gh_rm_ipa_reserve");
          iVar3 = iVar4;
          if (local_68 != 0) {
            kfree(local_60);
          }
        }
      }
      else {
        _printk(&DAT_0010a615,"gh_rm_ipa_reserve",iVar3);
      }
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// trace_raw_output_gh_rm_mem_accept_donate_lend_share @ 00108d0c size=744
// signature: undefined trace_raw_output_gh_rm_mem_accept_donate_lend_share(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_gh_rm_mem_accept_donate_lend_share
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  ulong uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte bVar5;
  undefined1 uVar6;
  ushort uVar7;
  ushort uVar8;
  short sVar9;
  undefined2 uVar10;
  code *pcVar11;
  int iVar12;
  undefined8 uVar13;
  undefined *puVar14;
  undefined8 uVar15;
  undefined *puVar16;
  short sVar17;
  long lVar18;
  undefined2 *puVar19;
  undefined *puVar20;
  undefined *puVar21;
  int iVar22;
  byte *pbVar23;
  undefined *local_88;
  
  lVar18 = *(long *)(param_1 + 0x20f0);
  iVar12 = trace_raw_output_prep(param_1,param_3);
  if (iVar12 != 1) {
    return;
  }
  lVar1 = param_1 + 0x90;
  uVar13 = trace_print_symbols_seq
                     (lVar1,*(undefined1 *)(lVar18 + 8),
                      trace_raw_output_gh_rm_mem_accept_donate_lend_share_symbols);
  uVar3 = *(undefined4 *)(lVar18 + 0xc);
  iVar12 = *(int *)(lVar18 + 0x10);
  uVar6 = *(undefined1 *)(lVar18 + 9);
  if (iVar12 == 0) {
    puVar16 = &DAT_00109f56;
  }
  else {
    uVar2 = *(ulong *)(param_1 + 0x10a0);
    if (*(ulong *)(param_1 + 0x1098) <= *(ulong *)(param_1 + 0x10a0)) {
      uVar2 = *(ulong *)(param_1 + 0x1098);
    }
    if (0x1000 < (uint)uVar2) {
                    /* WARNING: Does not return */
      pcVar11 = (code *)SoftwareBreakpoint(0x5512,0x108ff4);
      (*pcVar11)();
    }
    uVar7 = *(ushort *)(lVar18 + 0x18);
    uVar8 = *(ushort *)(lVar18 + 0x14);
    trace_seq_putc(lVar1,0x7b);
    if (0 < iVar12) {
      puVar19 = (undefined2 *)(lVar18 + (ulong)uVar8);
      pbVar23 = (byte *)(lVar18 + (ulong)uVar7);
      iVar22 = iVar12;
      do {
        trace_seq_printf(lVar1,"(0x%x,",*puVar19);
        bVar5 = *pbVar23;
        puVar16 = &DAT_00109f80;
        if ((bVar5 & 4) != 0) {
          puVar16 = &DAT_00109bb6;
        }
        puVar14 = &DAT_00109f80;
        if ((bVar5 & 2) != 0) {
          puVar14 = &DAT_0010af4a;
        }
        puVar21 = &DAT_00109f80;
        if ((bVar5 & 1) != 0) {
          puVar21 = &DAT_0010a2bc;
        }
        trace_seq_printf(lVar1,"%s%s%s)",puVar16,puVar14,puVar21);
        if (iVar22 != 1) {
          trace_seq_printf(lVar1,&DAT_0010acc9);
        }
        iVar22 = iVar22 + -1;
        puVar19 = puVar19 + 1;
        pbVar23 = pbVar23 + 1;
      } while (iVar22 != 0);
    }
    puVar16 = (undefined *)(lVar1 + (uVar2 & 0xffffffff));
    trace_seq_putc(lVar1,0x7d);
    trace_seq_putc(lVar1,0);
  }
  sVar9 = *(short *)(lVar18 + 0x1c);
  if (sVar9 == 0) {
    puVar14 = &DAT_00109f56;
    sVar17 = *(short *)(lVar18 + 0x28);
joined_r0x00108ef4:
    local_88 = &DAT_00109f56;
    if (sVar17 == 0) {
LAB_00108f4c:
      puVar21 = &DAT_00109f56;
      puVar20 = &DAT_00109f56;
      goto LAB_00108f64;
    }
  }
  else {
    puVar14 = (undefined *)
              trace_print_array_seq
                        (lVar1,lVar18 + (ulong)*(ushort *)(lVar18 + 0x20),
                         *(undefined4 *)(lVar18 + 0x3c),8);
    if (*(short *)(lVar18 + 0x1c) == 0) {
      sVar17 = *(short *)(lVar18 + 0x28);
      goto joined_r0x00108ef4;
    }
    local_88 = (undefined *)
               trace_print_array_seq
                         (lVar1,lVar18 + (ulong)*(ushort *)(lVar18 + 0x24),
                          *(undefined4 *)(lVar18 + 0x3c),8);
    sVar17 = *(short *)(lVar18 + 0x28);
    if (sVar17 == 0) {
      sVar17 = 0;
      goto LAB_00108f4c;
    }
  }
  puVar21 = (undefined *)
            trace_print_array_seq(lVar1,lVar18 + (ulong)*(ushort *)(lVar18 + 0x2c),sVar17,2);
  if (*(short *)(lVar18 + 0x28) == 0) {
    puVar20 = &DAT_00109f56;
  }
  else {
    puVar20 = (undefined *)
              trace_print_array_seq
                        (lVar1,lVar18 + (ulong)*(ushort *)(lVar18 + 0x30),*(short *)(lVar18 + 0x28),
                         2);
  }
LAB_00108f64:
  uVar4 = *(undefined4 *)(lVar18 + 0x34);
  uVar10 = *(undefined2 *)(lVar18 + 0x38);
  uVar15 = trace_print_symbols_seq
                     (lVar1,*(undefined1 *)(lVar18 + 0x3a),
                      trace_raw_output_gh_rm_mem_accept_donate_lend_share_symbols_89);
  trace_event_printf(param_1,
                     "mem_type = %s flags = 0x%x label = %u\t\tacl_entries = %u acl_arr = %s\t\tsgl_entries = %u sgl_ipa_base = %s sgl_size = %s\t\tmem_attr_entries = %u mem_attr_attr = %s mem_attr_vmid = %s\t\thandle = %u map_vmid = 0x%x trans_type = %s\n"
                     ,uVar13,uVar6,uVar3,iVar12,puVar16,sVar9,puVar14,local_88,sVar17,puVar21,
                     puVar20,uVar4,uVar10,uVar15);
  trace_handle_return(param_1 + 0x10c8);
  return;
}



//------------------------------------------------------------
// trace_raw_output_gh_rm_mem_accept_reply @ 00108ff8 size=232
// signature: undefined trace_raw_output_gh_rm_mem_accept_reply(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_gh_rm_mem_accept_reply(long param_1,undefined8 param_2,undefined8 param_3)

{
  short sVar1;
  int iVar2;
  undefined *puVar3;
  undefined *puVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x20f0);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 == 1) {
    sVar1 = *(short *)(lVar5 + 8);
    if ((sVar1 == 0) || (*(char *)(lVar5 + 0x18) != '\0')) {
      puVar4 = &DAT_00109f56;
      puVar3 = &DAT_00109f56;
    }
    else {
      puVar4 = (undefined *)
               trace_print_array_seq
                         (param_1 + 0x90,lVar5 + (ulong)*(ushort *)(lVar5 + 0xc),
                          *(undefined4 *)(lVar5 + 0x14),8);
      if ((*(short *)(lVar5 + 8) == 0) || (*(char *)(lVar5 + 0x18) != '\0')) {
        puVar3 = &DAT_00109f56;
      }
      else {
        puVar3 = (undefined *)
                 trace_print_array_seq
                           (param_1 + 0x90,lVar5 + (ulong)*(ushort *)(lVar5 + 0x10),
                            *(undefined4 *)(lVar5 + 0x14),8);
      }
    }
    trace_event_printf(param_1,"sgl_entries = %u sgl_ipa_base = %s sgl_size = %s\t\t\n",sVar1,puVar4
                       ,puVar3);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_gh_rm_mem_release_reclaim @ 001090e4 size=104
// signature: undefined trace_raw_output_gh_rm_mem_release_reclaim(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_gh_rm_mem_release_reclaim(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"handle_s = %u flags = 0x%x\n",*(undefined4 *)(lVar2 + 8),
                       *(undefined1 *)(lVar2 + 0xc));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_gh_rm_mem_call_return @ 00109150 size=100
// signature: undefined trace_raw_output_gh_rm_mem_call_return(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_gh_rm_mem_call_return(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"handle = %u, return_value = %d\n",*(undefined4 *)(lVar2 + 8),
                       *(undefined4 *)(lVar2 + 0xc));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_gh_rm_mem_notify @ 001091b8 size=188
// signature: undefined trace_raw_output_gh_rm_mem_notify(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_gh_rm_mem_notify(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  short sVar4;
  int iVar5;
  undefined *puVar6;
  long lVar7;
  
  lVar7 = *(long *)(param_1 + 0x20f0);
  iVar5 = trace_raw_output_prep(param_1,param_3);
  if (iVar5 == 1) {
    uVar1 = *(undefined4 *)(lVar7 + 8);
    uVar3 = *(undefined1 *)(lVar7 + 0xc);
    sVar4 = *(short *)(lVar7 + 0x14);
    uVar2 = *(undefined4 *)(lVar7 + 0x10);
    if (sVar4 == 0) {
      puVar6 = &DAT_00109f56;
    }
    else {
      puVar6 = (undefined *)
               trace_print_array_seq
                         (param_1 + 0x90,lVar7 + (ulong)*(ushort *)(lVar7 + 0x18),sVar4,2);
    }
    trace_event_printf(param_1,
                       "handle = %u flags = 0x%x mem_info_tag = %u\t\tvmid_entries = %u entry_vmid_arr = %s\n"
                       ,uVar1,uVar3,uVar2,sVar4,puVar6);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001099dc size=52
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __auxiliary_driver_register(&gh_rm_driver,&__this_module,"gh_rm_drv");
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00109a14 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  auxiliary_driver_unregister(&gh_rm_driver);
  return;
}



//------------------------------------------------------------
// strcmp @ 0010f000 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [gh_get_image_name, gh_get_vm_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010f008 size=1
// signature: undefined _printk(void)
// callers: [gh_rm_mem_notify, gh_rm_get_svm_res_work_fn, gh_rm_vm_irq_reclaim, gh_get_image_name, gh_get_vm_name, gh_rm_console_flush, gh_vm_status_nb_handler, gh_rm_vm_set_time_base, gh_rm_minidump_deregister_slot, gh_rm_vm_alloc_vmid, gh_rm_vm_get_hyp_res, gh_rm_vm_get_status, gh_rm_vm_irq_lend, ghd_rm_mem_reclaim, gh_rm_ipa_reserve, gh_rm_mem_qcom_lookup_sgl, gh_rm_mem_accept, gh_rm_mem_release, gh_rm_get_this_vmid, gh_rm_mem_donate, gh_rm_vm_irq_notify, gh_rm_mem_append, gh_rm_minidump_register_range, ghd_rm_vm_reset, gh_rm_mem_share_lend_helper, gh_rm_minidump_get_info, gh_rm_console_write, gh_rm_populate_hyp_res, gh_rm_console_open, gh_rm_unpopulate_hyp_res, gh_rm_get_vm_id_info, gh_rm_vm_lookup, gh_rm_vm_lookup_name_uri, gh_rm_vm_dealloc_vmid, ghd_rm_vm_start, gh_rm_console_close, ghd_rm_vm_stop, gh_rm_minidump_get_slot_from_name, gh_rm_vm_get_id, ghd_rm_vm_init, gh_rm_vm_irq_accept, gh_rm_vm_config_image, gh_rm_vm_irq_release, gh_rm_vm_set_status, gh_rm_vm_auth_image]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// srcu_notifier_chain_register @ 0010f010 size=1
// signature: undefined srcu_notifier_chain_register(void)
// callers: [gh_rm_register_notifier, gh_rm_drv_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void srcu_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// srcu_notifier_chain_unregister @ 0010f018 size=1
// signature: undefined srcu_notifier_chain_unregister(void)
// callers: [gh_rm_unregister_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void srcu_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_get_irq @ 0010f020 size=1
// signature: undefined gh_get_irq(void)
// callers: [gh_rm_virq_to_irq, gh_rm_populate_hyp_res]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_domain_get_irq_data @ 0010f028 size=1
// signature: undefined irq_domain_get_irq_data(void)
// callers: [gh_rm_irq_to_virq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_domain_get_irq_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0010f030 size=1
// signature: undefined __kmalloc(void)
// callers: [gh_rm_mem_notify, gh_rm_vm_irq_notify, gh_rm_mem_append, gh_rm_minidump_register_range, gh_rm_mem_share_lend_helper, gh_rm_console_write, gh_rm_get_vm_id_info, gh_rm_vm_lookup_name_uri, gh_rm_minidump_get_slot_from_name, gh_rm_mem_qcom_lookup_sgl, gh_rm_mem_accept, gh_rm_drv_probe, gh_rm_vm_auth_image]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0010f038 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [gh_rm_vm_lookup_name_uri, gh_rm_minidump_get_slot_from_name, gh_rm_mem_append, gh_rm_minidump_register_range, gh_rm_mem_accept, gh_rm_console_write, gh_rm_populate_mem_request, gh_rm_get_vm_id_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010f040 size=1
// signature: undefined kfree(void)
// callers: [gh_rm_mem_notify, gh_rm_vm_irq_reclaim, gh_rm_vm_set_app_status, gh_rm_console_flush, gh_rm_minidump_deregister_slot, gh_rm_vm_set_vm_status, gh_rm_vm_alloc_vmid, gh_rm_vm_get_hyp_res, gh_rm_vm_get_status, gh_rm_vm_irq_lend, ghd_rm_mem_reclaim, gh_rm_ipa_reserve, gh_rm_mem_qcom_lookup_sgl, gh_rm_vm_set_os_status, gh_rm_mem_accept, gh_rm_drv_probe, gh_rm_mem_release, gh_rm_get_this_vmid, gh_rm_vm_irq_notify, gh_rm_mem_append, gh_rm_minidump_register_range, ghd_rm_vm_reset, gh_rm_mem_share_lend_helper, gh_rm_minidump_get_info, gh_rm_console_write, gh_rm_populate_hyp_res, gh_rm_console_open, gh_rm_unpopulate_hyp_res, gh_rm_get_vm_id_info, gh_rm_vm_lookup, gh_rm_vm_lookup_name_uri, gh_rm_vm_dealloc_vmid, ghd_rm_vm_start, gh_rm_console_close, ghd_rm_vm_stop, gh_rm_minidump_get_slot_from_name, gh_rm_vm_get_id, ghd_rm_vm_init, gh_rm_vm_irq_accept, gh_rm_vm_config_image, gh_rm_vm_irq_release, gh_rm_vm_set_status, gh_rm_vm_auth_image]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010f048 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [gh_rm_vm_irq_reclaim, gh_rm_console_flush, gh_vm_status_nb_handler, gh_rm_vm_set_time_base, trace_event_raw_event_gh_rm_mem_call_return, gh_rm_minidump_deregister_slot, gh_rm_vm_get_hyp_res, gh_rm_vm_get_status, gh_rm_vm_irq_lend, ghd_rm_mem_reclaim, gh_rm_ipa_reserve, gh_rm_mem_qcom_lookup_sgl, trace_event_raw_event_gh_rm_mem_notify, gh_rm_mem_accept, gh_rm_drv_probe, gh_rm_vm_irq_lend_notify, trace_event_raw_event_gh_rm_mem_accept_donate_lend_share, gh_rm_mem_append, gh_rm_minidump_register_range, gh_rm_minidump_get_info, gh_rm_console_write, gh_rm_populate_hyp_res, gh_rm_console_open, gh_rm_unpopulate_hyp_res, gh_rm_vm_lookup, ghd_rm_vm_init, perf_trace_gh_rm_mem_release_reclaim, gh_rm_mem_notify, gh_rm_get_svm_res_work_fn, perf_trace_gh_rm_mem_accept_donate_lend_share, perf_trace_gh_rm_mem_call_return, gh_rm_vm_alloc_vmid, perf_trace_gh_rm_mem_accept_reply, gh_rm_mem_release, gh_rm_get_this_vmid, gh_rm_vm_irq_notify, ghd_rm_vm_reset, trace_event_raw_event_gh_rm_mem_release_reclaim, gh_rm_mem_share_lend_helper, trace_event_raw_event_gh_rm_mem_accept_reply, gh_rm_get_vm_id_info, gh_rm_vm_lookup_name_uri, gh_rm_vm_dealloc_vmid, ghd_rm_vm_start, gh_rm_console_close, ghd_rm_vm_stop, gh_rm_minidump_get_slot_from_name, gh_rm_vm_get_id, perf_trace_gh_rm_mem_notify, gh_rm_vm_irq_accept, gh_rm_vm_config_image, gh_rm_vm_irq_release, gh_rm_vm_set_status, gh_rm_vm_auth_image]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010f050 size=1
// signature: undefined mutex_lock(void)
// callers: [gh_rm_unset_virtio_mmio_cb, gh_rm_populate_hyp_res, gh_rm_set_virtio_mmio_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010f058 size=1
// signature: undefined mutex_unlock(void)
// callers: [gh_rm_unset_virtio_mmio_cb, gh_rm_populate_hyp_res, gh_rm_set_virtio_mmio_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_populate_cap_info @ 0010f060 size=1
// signature: undefined gh_dbl_populate_cap_info(void)
// callers: [gh_rm_populate_hyp_res]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_populate_cap_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_msgq_populate_cap_info @ 0010f068 size=1
// signature: undefined gh_msgq_populate_cap_info(void)
// callers: [gh_rm_populate_hyp_res]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_msgq_populate_cap_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_reset_cap_info @ 0010f070 size=1
// signature: undefined gh_dbl_reset_cap_info(void)
// callers: [gh_rm_unpopulate_hyp_res]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_reset_cap_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_msgq_reset_cap_info @ 0010f078 size=1
// signature: undefined gh_msgq_reset_cap_info(void)
// callers: [gh_rm_unpopulate_hyp_res]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_msgq_reset_cap_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_put_irq @ 0010f080 size=1
// signature: undefined gh_put_irq(void)
// callers: [gh_rm_unpopulate_hyp_res]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_put_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __auxiliary_driver_register @ 0010f088 size=1
// signature: undefined __auxiliary_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __auxiliary_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// auxiliary_driver_unregister @ 0010f090 size=1
// signature: undefined auxiliary_driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void auxiliary_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010f098 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [gh_rm_drv_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_irq_find_parent @ 0010f0a0 size=1
// signature: undefined of_irq_find_parent(void)
// callers: [gh_rm_drv_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_irq_find_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_find_matching_fwspec @ 0010f0a8 size=1
// signature: undefined irq_find_matching_fwspec(void)
// callers: [gh_rm_drv_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_find_matching_fwspec(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_notifier_register @ 0010f0b0 size=1
// signature: undefined gh_rm_notifier_register(void)
// callers: [gh_rm_drv_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_notifier_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_compatible_node @ 0010f0b8 size=1
// signature: undefined of_find_compatible_node(void)
// callers: [gh_rm_drv_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_compatible_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 0010f0c0 size=1
// signature: undefined of_property_read_string(void)
// callers: [gh_rm_drv_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 0010f0c8 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [gh_rm_drv_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010f0d0 size=1
// signature: undefined _dev_err(void)
// callers: [gh_rm_drv_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 0010f0d8 size=1
// signature: undefined strnstr(void)
// callers: [gh_rm_drv_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0010f0e0 size=1
// signature: size_t strlen(char * __s)
// callers: [gh_rm_drv_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// uuid_parse @ 0010f0e8 size=1
// signature: undefined uuid_parse(void)
// callers: [gh_rm_drv_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void uuid_parse(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0010f0f0 size=1
// signature: undefined _dev_info(void)
// callers: [gh_rm_drv_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0010f100 size=1
// signature: undefined queue_work_on(void)
// callers: [gh_rm_drv_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_notifier_unregister @ 0010f108 size=1
// signature: undefined gh_rm_notifier_unregister(void)
// callers: [gh_rm_drv_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_notifier_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_destroy @ 0010f110 size=1
// signature: undefined idr_destroy(void)
// callers: [gh_rm_drv_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// srcu_notifier_call_chain @ 0010f118 size=1
// signature: undefined srcu_notifier_call_chain(void)
// callers: [gh_rm_core_notifier_call]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void srcu_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 0010f128 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_gh_rm_mem_release_reclaim, trace_event_raw_event_gh_rm_mem_notify, trace_event_raw_event_gh_rm_mem_call_return, trace_event_raw_event_gh_rm_mem_accept_reply, trace_event_raw_event_gh_rm_mem_accept_donate_lend_share]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 0010f130 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_gh_rm_mem_release_reclaim, trace_event_raw_event_gh_rm_mem_notify, trace_event_raw_event_gh_rm_mem_call_return, trace_event_raw_event_gh_rm_mem_accept_reply, trace_event_raw_event_gh_rm_mem_accept_donate_lend_share]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 0010f138 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_gh_rm_mem_release_reclaim, trace_event_raw_event_gh_rm_mem_notify, trace_event_raw_event_gh_rm_mem_call_return, trace_event_raw_event_gh_rm_mem_accept_reply, trace_event_raw_event_gh_rm_mem_accept_donate_lend_share]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 0010f140 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_gh_rm_mem_accept_reply, perf_trace_gh_rm_mem_accept_donate_lend_share, perf_trace_gh_rm_mem_notify, perf_trace_gh_rm_mem_call_return, perf_trace_gh_rm_mem_release_reclaim]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 0010f148 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_gh_rm_mem_accept_reply, perf_trace_gh_rm_mem_accept_donate_lend_share, perf_trace_gh_rm_mem_notify, perf_trace_gh_rm_mem_call_return, perf_trace_gh_rm_mem_release_reclaim]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run9 @ 0010f150 size=1
// signature: undefined bpf_trace_run9(void)
// callers: [__bpf_trace_gh_rm_mem_accept_donate_lend_share]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run9(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run1 @ 0010f158 size=1
// signature: undefined bpf_trace_run1(void)
// callers: [__bpf_trace_gh_rm_mem_accept_reply]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run2 @ 0010f160 size=1
// signature: undefined bpf_trace_run2(void)
// callers: [__bpf_trace_gh_rm_mem_call_return, __bpf_trace_gh_rm_mem_release_reclaim]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run4 @ 0010f168 size=1
// signature: undefined bpf_trace_run4(void)
// callers: [__bpf_trace_gh_rm_mem_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 0010f170 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [gh_rm_vm_dealloc_vmid, gh_init_vm_prop_table, ghd_rm_get_vmid, gh_rm_get_vm_name, gh_rm_get_vminfo, gh_rm_vm_alloc_vmid, gh_update_vm_prop_table, gh_reset_vm_prop_table_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 0010f178 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [gh_rm_vm_dealloc_vmid, gh_init_vm_prop_table, ghd_rm_get_vmid, gh_rm_get_vm_name, gh_rm_get_vminfo, gh_rm_vm_alloc_vmid, gh_update_vm_prop_table, gh_reset_vm_prop_table_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_call @ 0010f180 size=1
// signature: undefined gh_rm_call(void)
// callers: [gh_rm_mem_notify, gh_rm_vm_irq_reclaim, gh_rm_console_flush, gh_rm_vm_set_time_base, gh_rm_minidump_deregister_slot, gh_rm_vm_alloc_vmid, gh_rm_vm_get_hyp_res, gh_rm_vm_get_status, gh_rm_vm_irq_lend, ghd_rm_mem_reclaim, gh_rm_ipa_reserve, gh_rm_mem_qcom_lookup_sgl, gh_rm_mem_accept, gh_rm_mem_release, gh_rm_get_this_vmid, gh_rm_vm_irq_notify, gh_rm_mem_append, gh_rm_minidump_register_range, ghd_rm_vm_reset, gh_rm_mem_share_lend_helper, gh_rm_minidump_get_info, gh_rm_console_write, gh_rm_console_open, gh_rm_vm_lookup, gh_rm_vm_lookup_name_uri, gh_rm_vm_dealloc_vmid, ghd_rm_vm_start, gh_rm_console_close, ghd_rm_vm_stop, gh_rm_minidump_get_slot_from_name, gh_rm_vm_get_id, ghd_rm_vm_init, gh_rm_vm_irq_accept, gh_rm_vm_config_image, gh_rm_vm_irq_release, gh_rm_vm_set_status, gh_rm_vm_auth_image]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_call(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmemdup @ 0010f188 size=1
// signature: undefined kmemdup(void)
// callers: [gh_rm_vm_get_id, gh_rm_vm_get_hyp_res, gh_rm_vm_get_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmemdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010f1b0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [gh_rm_mem_accept]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0010f1b8 size=1
// signature: undefined __list_add_valid(void)
// callers: [gh_rm_mem_accept]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kvmalloc_node @ 0010f1c0 size=1
// signature: undefined kvmalloc_node(void)
// callers: [gh_rm_mem_accept]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kvmalloc_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0010f1c8 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [gh_rm_mem_accept]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sw_hweight8 @ 0010f1d0 size=1
// signature: undefined __sw_hweight8(void)
// callers: [gh_rm_mem_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sw_hweight8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_real_ts64 @ 0010f1e0 size=1
// signature: undefined ktime_get_real_ts64(void)
// callers: [gh_rm_vm_set_time_base]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_real_ts64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_raw_output_prep @ 0010f1f0 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_gh_rm_mem_call_return, trace_raw_output_gh_rm_mem_notify, trace_raw_output_gh_rm_mem_accept_donate_lend_share, trace_raw_output_gh_rm_mem_accept_reply, trace_raw_output_gh_rm_mem_release_reclaim]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_print_symbols_seq @ 0010f1f8 size=1
// signature: undefined trace_print_symbols_seq(void)
// callers: [trace_raw_output_gh_rm_mem_accept_donate_lend_share]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_print_symbols_seq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_seq_putc @ 0010f200 size=1
// signature: undefined trace_seq_putc(void)
// callers: [trace_raw_output_gh_rm_mem_accept_donate_lend_share]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_seq_putc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_seq_printf @ 0010f208 size=1
// signature: undefined trace_seq_printf(void)
// callers: [trace_raw_output_gh_rm_mem_accept_donate_lend_share]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_print_array_seq @ 0010f210 size=1
// signature: undefined trace_print_array_seq(void)
// callers: [trace_raw_output_gh_rm_mem_notify, trace_raw_output_gh_rm_mem_accept_donate_lend_share, trace_raw_output_gh_rm_mem_accept_reply]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_print_array_seq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 0010f218 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_gh_rm_mem_call_return, trace_raw_output_gh_rm_mem_notify, trace_raw_output_gh_rm_mem_accept_donate_lend_share, trace_raw_output_gh_rm_mem_accept_reply, trace_raw_output_gh_rm_mem_release_reclaim]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 0010f220 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_gh_rm_mem_call_return, trace_raw_output_gh_rm_mem_notify, trace_raw_output_gh_rm_mem_accept_donate_lend_share, trace_raw_output_gh_rm_mem_accept_reply, trace_raw_output_gh_rm_mem_release_reclaim]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



