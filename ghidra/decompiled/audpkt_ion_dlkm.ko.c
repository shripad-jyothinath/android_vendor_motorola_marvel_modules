// Decompiled by Ghidra 12.2
// Program: audpkt_ion_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// msm_audio_fd_list_debug @ 0010037c size=4
// signature: undefined msm_audio_fd_list_debug(void)
// callers: []
//------------------------------------------------------------

void msm_audio_fd_list_debug(void)

{
  return;
}



//------------------------------------------------------------
// msm_audio_update_fd_list @ 00100384 size=176
// signature: undefined msm_audio_update_fd_list(void)
// callers: []
//------------------------------------------------------------

void msm_audio_update_fd_list(int *param_1)

{
  long *plVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 *puVar4;
  
  mutex_lock(&msm_audio_ion_fd_list);
  plVar2 = DAT_00101bf8;
  puVar4 = &DAT_00101bf0;
  do {
    puVar4 = (undefined8 *)*puVar4;
    if (puVar4 == &DAT_00101bf0) {
      plVar1 = (long *)(param_1 + 10);
      uVar3 = __list_add_valid(plVar1,DAT_00101bf8,&DAT_00101bf0);
      if ((uVar3 & 1) != 0) {
        DAT_00101bf8 = plVar1;
        *(undefined8 **)(param_1 + 10) = &DAT_00101bf0;
        *(long **)(param_1 + 0xc) = plVar2;
        *plVar2 = (long)plVar1;
      }
      goto LAB_00100414;
    }
  } while (*(int *)(puVar4 + -5) != *param_1);
  _printk(&DAT_00102314,"msm_audio_update_fd_list");
LAB_00100414:
  mutex_unlock(&msm_audio_ion_fd_list);
  return;
}



//------------------------------------------------------------
// msm_audio_delete_fd_entry @ 00100438 size=184
// signature: undefined msm_audio_delete_fd_entry(void)
// callers: []
//------------------------------------------------------------

void msm_audio_delete_fd_entry(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  long *plVar4;
  
  if (param_1 == 0) {
    _printk(&DAT_00101c38,"msm_audio_delete_fd_entry");
  }
  else {
    mutex_lock(&msm_audio_ion_fd_list);
    plVar4 = &DAT_00101bf0;
    do {
      plVar4 = (long *)*plVar4;
      if (plVar4 == &DAT_00101bf0) goto LAB_001004bc;
    } while (plVar4[-3] != param_1);
    uVar3 = __list_del_entry_valid(plVar4);
    if ((uVar3 & 1) != 0) {
      lVar1 = *plVar4;
      plVar2 = (long *)plVar4[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *plVar4 = -0x2152ffffffffff00;
    plVar4[1] = -0x2152fffffffffede;
    kfree(plVar4 + -5);
LAB_001004bc:
    mutex_unlock(&msm_audio_ion_fd_list);
  }
  return;
}



//------------------------------------------------------------
// msm_audio_get_phy_addr @ 001004f4 size=196
// signature: undefined msm_audio_get_phy_addr(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_audio_get_phy_addr(int param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  if (param_2 == (undefined8 *)0x0) {
    uVar2 = 0xffffffea;
    _printk(&DAT_00102130,"msm_audio_get_phy_addr",0xffffffea);
  }
  else {
    mutex_lock(&msm_audio_ion_fd_list);
    puVar1 = &DAT_00101bf0;
    do {
      puVar1 = (undefined8 *)*puVar1;
      if (puVar1 == &DAT_00101bf0) {
        mutex_unlock(&msm_audio_ion_fd_list);
        return 0xffffffea;
      }
    } while (*(int *)(puVar1 + -5) != param_1);
    *param_2 = puVar1[-2];
    *param_3 = puVar1[-4];
    mutex_unlock(&msm_audio_ion_fd_list);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// msm_audio_get_handle @ 001005bc size=124
// signature: undefined msm_audio_get_handle(void)
// callers: []
//------------------------------------------------------------

void msm_audio_get_handle(int param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  
  mutex_lock(&msm_audio_ion_fd_list);
  puVar1 = &DAT_00101bf0;
  *param_2 = 0;
  do {
    puVar1 = (undefined8 *)*puVar1;
    if (puVar1 == &DAT_00101bf0) goto LAB_00100618;
  } while (*(int *)(puVar1 + -5) != param_1);
  *param_2 = puVar1[-3];
LAB_00100618:
  mutex_unlock(&msm_audio_ion_fd_list);
  return;
}



//------------------------------------------------------------
// msm_audio_ion_crash_handler @ 0010063c size=448
// signature: undefined msm_audio_ion_crash_handler(void)
// callers: []
//------------------------------------------------------------

void msm_audio_ion_crash_handler(void)

{
  long *plVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  undefined8 uVar5;
  long *plVar6;
  long *plVar7;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  if ((msm_audio_ion_fd_list_init & 1) == 0) {
    _printk(&DAT_00101cd8,"msm_audio_ion_crash_handler");
  }
  else {
    mutex_lock(&msm_audio_ion_fd_list);
    plVar7 = DAT_00101bf0;
    if ((long **)DAT_00101bf0 != &DAT_00101bf0) {
      do {
        if (plVar7 != (long *)0x28) {
          lVar4 = plVar7[-3];
          uVar5 = *(undefined8 *)(plVar7[-1] + 0x98);
          if ((char)plVar7[2] != '\0') {
            local_68 = 0x2000400000;
            uStack_60 = 0x700000003;
            if ((char)plVar7[2] != '\0') {
              iVar2 = qcom_scm_assign_mem(plVar7[-2],plVar7[-4],&local_68,&uStack_60,1);
              if (iVar2 < 0) {
                _printk(&DAT_00101dca,"msm_audio_hyp_unassign",iVar2,plVar7[-2],plVar7[-4]);
              }
              *(undefined1 *)(plVar7 + 2) = 0;
            }
          }
          if (lVar4 != 0) {
            msm_audio_ion_free(lVar4,uVar5);
          }
        }
        plVar7 = (long *)*plVar7;
      } while ((long **)plVar7 != &DAT_00101bf0);
      plVar7 = DAT_00101bf0;
      if ((long **)DAT_00101bf0 != &DAT_00101bf0) {
        do {
          plVar6 = (long *)*plVar7;
          if ((plVar7 != (long *)0x0) && (plVar7 + -5 != (long *)0x0)) {
            uVar3 = __list_del_entry_valid(plVar7);
            if ((uVar3 & 1) != 0) {
              lVar4 = *plVar7;
              plVar1 = (long *)plVar7[1];
              *(long **)(lVar4 + 8) = plVar1;
              *plVar1 = lVar4;
            }
            *plVar7 = -0x2152ffffffffff00;
            plVar7[1] = -0x2152fffffffffede;
            kfree(plVar7 + -5);
          }
          plVar7 = plVar6;
        } while ((long **)plVar6 != &DAT_00101bf0);
      }
    }
    mutex_unlock(&msm_audio_ion_fd_list);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_audio_ion_free @ 001007fc size=280
// signature: undefined msm_audio_ion_free(void)
// callers: [msm_audio_ion_crash_handler, msm_audio_ion_ioctl]
//------------------------------------------------------------

int msm_audio_ion_free(long param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  
  if (param_1 == 0) {
    _printk(&DAT_00102258,"msm_audio_ion_free");
    return -0x16;
  }
  pcVar1 = param_2 + 0x28;
  mutex_lock(pcVar1);
  if (*param_2 == '\0') {
LAB_00100878:
    msm_audio_dma_buf_unmap(param_1,param_2);
    mutex_unlock(pcVar1);
    iVar2 = 0;
  }
  else {
    uVar4 = *(undefined8 *)(param_2 + 8);
    pcVar3 = param_2 + 0x18;
    do {
      pcVar3 = *(char **)pcVar3;
      if (pcVar3 == param_2 + 0x18) goto LAB_001008ac;
    } while (*(long *)(pcVar3 + -0x18) != param_1);
    if (*(long *)(pcVar3 + -0x20) == 0) {
LAB_001008ac:
      _dev_err(uVar4,"%s: cannot find allocation for dma_buf %pK","msm_audio_ion_unmap_kernel",
               param_1);
      iVar2 = -0x16;
    }
    else {
      dma_buf_vunmap(param_1);
      iVar2 = dma_buf_end_cpu_access(param_1,0);
      if (iVar2 == 0) goto LAB_00100878;
      _dev_err(uVar4,"%s: kmap dma_buf_end_cpu_access fail\n","msm_audio_ion_unmap_kernel");
    }
    mutex_unlock(pcVar1);
  }
  return iVar2;
}



//------------------------------------------------------------
// cleanup_module @ 00100918 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&msm_audio_ion_driver);
  return;
}



//------------------------------------------------------------
// msm_audio_dma_buf_unmap @ 0010093c size=188
// signature: undefined msm_audio_dma_buf_unmap(void)
// callers: [msm_audio_ion_ioctl, msm_audio_ion_free]
//------------------------------------------------------------

void msm_audio_dma_buf_unmap(long param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  long *plVar4;
  
  plVar4 = (long *)(param_2 + 0x18);
  do {
    plVar4 = (long *)*plVar4;
    if (plVar4 == (long *)(param_2 + 0x18)) {
      _dev_err(*(undefined8 *)(param_2 + 8),"%s: cannot find allocation, dma_buf %pK",
               "msm_audio_dma_buf_unmap");
      return;
    }
  } while (plVar4[-3] != param_1);
  dma_buf_unmap_attachment(plVar4[-2],plVar4[-1],0);
  dma_buf_detach(plVar4[-3],plVar4[-2]);
  dma_buf_put(plVar4[-3]);
  uVar3 = __list_del_entry_valid(plVar4);
  if ((uVar3 & 1) != 0) {
    lVar1 = *plVar4;
    plVar2 = (long *)plVar4[1];
    *(long **)(lVar1 + 8) = plVar2;
    *plVar2 = lVar1;
  }
  *plVar4 = -0x2152ffffffffff00;
  plVar4[1] = -0x2152fffffffffede;
  kfree(plVar4[-4]);
  kfree(plVar4 + -5);
  return;
}



//------------------------------------------------------------
// msm_audio_ion_probe @ 001009fc size=980
// signature: undefined msm_audio_ion_probe(void)
// callers: []
//------------------------------------------------------------

ulong msm_audio_ion_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  ulong uVar8;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar4 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_38 = *(long *)(lVar4 + 0x638);
  local_90 = 0;
  uStack_88 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_80 = 0;
  _dev_err(lVar1,"%s: msm_audio_ion_probe\n","msm_audio_ion_probe");
  if (*(long *)(param_1 + 0x2f8) == 0) {
    _dev_err(lVar1,"%s: device tree is not found\n","msm_audio_ion_probe");
LAB_00100c54:
    uVar8 = 0;
  }
  else {
    lVar4 = devm_kmalloc(lVar1,0x110,0xdc0);
    if (lVar4 == 0) {
      uVar8 = 0xfffffff4;
      goto LAB_00100c58;
    }
    lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,non-hyp-assign",0);
    uVar6 = *(undefined8 *)(param_1 + 0x2f8);
    *(bool *)(lVar4 + 100) = lVar5 != 0;
    lVar5 = of_find_property(uVar6,"qcom,smmu-enabled",0);
    *(bool *)lVar4 = lVar5 != 0;
    if (lVar5 == 0) {
      *(char **)(lVar4 + 0x68) = "msm_audio_ion_cma";
LAB_00100b54:
      *(byte *)(lVar4 + 0x10) = *(byte *)(lVar4 + 0x10) | 1;
    }
    else {
      uVar6 = *(undefined8 *)(param_1 + 0x2f8);
      *(char **)(lVar4 + 0x68) = "msm_audio_ion";
      uVar2 = of_property_read_variable_u32_array(uVar6,"qcom,smmu-version",lVar4 + 0x60,1,0);
      if ((int)uVar2 < 0) {
        uVar8 = (ulong)uVar2;
        _dev_err(lVar1,"%s: qcom,smmu_version missing in DT node\n","msm_audio_ion_probe");
        goto LAB_00100c58;
      }
      iVar3 = of_property_read_u64(*(undefined8 *)(param_1 + 0x2f8),"qcom,smmu-sid-mask",&local_90);
      if (iVar3 != 0) {
        _dev_err(lVar1,"%s: qcom,smmu-sid-mask missing in DT node, using default\n",
                 "msm_audio_ion_probe");
        local_90 = 0xffffffffffffffff;
      }
      iVar3 = __of_parse_phandle_with_args
                        (*(undefined8 *)(param_1 + 0x2f8),"iommus","#iommu-cells",0xffffffff,0,
                         &uStack_88);
      if (iVar3 == 0) {
        *(ulong *)(lVar4 + 0x58) = (ulong)((uint)local_90 & local_80._4_4_) << 0x20;
        goto LAB_00100b54;
      }
      _dev_err(lVar1,"%s: could not get smmu SID, ret = %d\n","msm_audio_ion_probe",iVar3);
      *(undefined8 *)(lVar4 + 0x58) = 0;
    }
    *(long *)(lVar4 + 8) = lVar1;
    *(long *)(param_1 + 0xa8) = lVar4;
    if ((msm_audio_ion_fd_list_init & 1) == 0) {
      DAT_00101bf0 = &DAT_00101bf0;
      DAT_00101bf8 = &DAT_00101bf0;
      __mutex_init(&msm_audio_ion_fd_list,"&(msm_audio_ion_fd_list.list_mutex)",
                   &msm_audio_ion_probe___key);
      msm_audio_ion_fd_list_init = 1;
    }
    *(long *)(lVar4 + 0x18) = lVar4 + 0x18;
    *(long *)(lVar4 + 0x20) = lVar4 + 0x18;
    __mutex_init(lVar4 + 0x28,"&(msm_audio_ion_data->list_mutex)",&msm_audio_ion_probe___key_24);
    uVar2 = alloc_chrdev_region(lVar4 + 0x70,0,1,*(undefined8 *)(lVar4 + 0x68));
    if ((int)uVar2 < 0) {
      uVar7 = (ulong)uVar2;
      _printk(&DAT_00102172,"msm_audio_ion_reg_chrdev",uVar7);
    }
    else {
      uVar7 = __class_create(&__this_module,*(undefined8 *)(lVar4 + 0x68),
                             &msm_audio_ion_reg_chrdev___key);
      *(ulong *)(lVar4 + 0x78) = uVar7;
      if (uVar7 < 0xfffffffffffff001) {
        uVar7 = device_create(uVar7,0,*(undefined4 *)(lVar4 + 0x70),0,*(undefined8 *)(lVar4 + 0x68))
        ;
        *(ulong *)(lVar4 + 0x80) = uVar7;
        if (uVar7 < 0xfffffffffffff001) {
          cdev_init(lVar4 + 0x88,&msm_audio_ion_fops);
          uVar7 = cdev_add(lVar4 + 0x88,*(undefined4 *)(lVar4 + 0x70),1);
          if ((int)uVar7 == 0) goto LAB_00100c54;
          uVar7 = uVar7 & 0xffffffff;
          _printk(&DAT_001022cf,"msm_audio_ion_reg_chrdev",uVar7);
          device_destroy(*(undefined8 *)(lVar4 + 0x78),*(undefined4 *)(lVar4 + 0x70));
        }
        else {
          _printk(&DAT_00101e4a,"msm_audio_ion_reg_chrdev",uVar7 & 0xffffffff);
        }
        class_destroy(*(undefined8 *)(lVar4 + 0x78));
      }
      else {
        _printk(&DAT_0010237f,"msm_audio_ion_reg_chrdev",uVar7 & 0xffffffff);
      }
      unregister_chrdev_region(0,1);
      uVar8 = 0;
      if ((int)uVar7 == 0) goto LAB_00100c58;
    }
    _printk(&DAT_00101ebf,"msm_audio_ion_probe",uVar7 & 0xffffffff);
    uVar8 = uVar7 & 0xffffffff;
  }
LAB_00100c58:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



//------------------------------------------------------------
// msm_audio_ion_remove @ 00100dd4 size=88
// signature: undefined msm_audio_ion_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_audio_ion_remove(long param_1)

{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)(param_1 + 0xa8);
  *puVar1 = 0;
  puVar1[0x10] = 0;
  cdev_del(puVar1 + 0x88);
  device_destroy(*(undefined8 *)(puVar1 + 0x78),*(undefined4 *)(puVar1 + 0x70));
  class_destroy(*(undefined8 *)(puVar1 + 0x78));
  unregister_chrdev_region(0,1);
  return 0;
}



//------------------------------------------------------------
// msm_audio_ion_ioctl @ 00100e30 size=2004
// signature: undefined msm_audio_ion_ioctl(void)
// callers: [msm_audio_ion_ioctl_compat]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void msm_audio_ion_ioctl(long param_1,ulong param_2,int param_3)

{
  char cVar1;
  int iVar2;
  long lVar3;
  int *piVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  long *plVar7;
  ulong uVar8;
  undefined *puVar9;
  ulong uVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  long *plVar13;
  long lVar14;
  undefined8 uVar15;
  char *pcVar16;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  local_90 = 0x2000400000;
  uStack_88 = 8;
  uVar10 = param_2 & 0xffffffff;
  local_78 = 0x600000016;
  uStack_70 = 0x600000025;
  local_80 = 0x700000003;
  if ((int)param_2 + 0xbffb9e9fU < 0xe) {
    lVar14 = *(long *)(*(long *)(param_1 + 0x20) + 0x290);
    pcVar16 = (char *)(lVar14 + -0x88);
    switch((int)param_2) {
    case 0x40046161:
      lVar3 = kmalloc_trace(_dma_buf_vmap,0xdc0,0x40);
      if (lVar3 == 0) {
        lVar14 = -0xc;
        goto LAB_00101398;
      }
      piVar4 = (int *)kmalloc_trace(_dma_buf_vmap,0xdc0,0x40);
      if (piVar4 == (int *)0x0) {
        kfree(lVar3);
        lVar14 = -0xc;
        goto LAB_00101398;
      }
      if ((*(byte *)(lVar14 + -0x78) & 1) == 0) {
        uVar10 = 0xfffffdfb;
      }
      else {
        puVar11 = (undefined8 *)dma_buf_get(param_3);
        if ((puVar11 != (undefined8 *)0x0) && (puVar11 < (undefined8 *)0xfffffffffffff001)) {
          cVar1 = *(char *)(lVar14 + -0x88);
          uVar12 = *(undefined8 *)(lVar14 + -0x80);
          puVar5 = (undefined8 *)kmalloc_trace(_dma_buf_vmap,0xdc0,0x10);
          if (puVar5 == (undefined8 *)0x0) {
            uVar15 = 0;
            uVar10 = 0xfffffff4;
            if (cVar1 != '\0') {
LAB_00101238:
              iVar2 = (int)uVar10;
              if (iVar2 == 0) {
                uVar10 = 0;
LAB_00101240:
                if (*pcVar16 != '\0') {
                  uVar10 = *(ulong *)(lVar14 + -0x30) | uVar10;
                }
                iVar2 = dma_buf_begin_cpu_access(puVar11,0);
                if (iVar2 == 0) {
                  iVar2 = dma_buf_vmap(puVar11,lVar3);
                  if (iVar2 == 0) {
                    mutex_lock(lVar14 + -0x60);
                    plVar13 = (long *)(lVar14 + -0x70);
                    do {
                      plVar13 = (long *)*plVar13;
                      if (plVar13 == (long *)(lVar14 + -0x70)) goto LAB_001012a0;
                    } while ((undefined8 *)plVar13[-3] != puVar11);
                    plVar13[-4] = lVar3;
LAB_001012a0:
                    mutex_unlock(lVar14 + -0x60);
                    goto LAB_001012a8;
                  }
                  _printk(&DAT_0010226f,"msm_audio_ion_map_kernel");
                  dma_buf_end_cpu_access(puVar11,0);
                }
                else {
                  _printk(&DAT_00102297,"msm_audio_ion_map_kernel");
                }
                _printk(&DAT_00101c68,"msm_audio_ion_buf_map",iVar2);
                mutex_lock(lVar14 + -0x60);
                msm_audio_dma_buf_unmap(puVar11,pcVar16);
                mutex_unlock(lVar14 + -0x60);
                uVar10 = 0xfffffff4;
                _printk(&DAT_00102359,"msm_audio_ion_import",0xfffffff4);
              }
              else {
                _printk(&DAT_00101e6e,"msm_audio_ion_get_phys",uVar10);
                _printk(&DAT_00101d98,"msm_audio_ion_buf_map",uVar10);
                dma_buf_put(puVar11);
                _printk(&DAT_00102359,"msm_audio_ion_import",uVar10);
                if (-1 < iVar2) {
                  uVar10 = 0;
                  puVar11 = (undefined8 *)0x0;
                  goto LAB_00101300;
                }
              }
              goto LAB_00101510;
            }
LAB_001012f8:
            iVar2 = 0;
            uVar10 = 0;
          }
          else {
            puVar6 = (undefined8 *)kmalloc_trace(_dma_buf_vmap,0xdc0,0x38);
            if (puVar6 == (undefined8 *)0x0) {
              uVar15 = 0;
              uVar10 = 0xfffffff4;
LAB_001012e8:
              kfree(puVar5);
              if (cVar1 == '\0') goto LAB_001012f8;
              goto LAB_00101238;
            }
            puVar6[2] = puVar11;
            uVar15 = *puVar11;
            *puVar6 = uVar15;
            plVar13 = (long *)dma_buf_attach(puVar11,uVar12);
            puVar6[3] = plVar13;
            if ((long *)0xfffffffffffff000 < plVar13) {
              _dev_err(uVar12,"%s: Fail to attach dma_buf to CB, rc = %d\n","msm_audio_dma_buf_map",
                       (ulong)plVar13 & 0xffffffff);
LAB_001015f0:
              uVar10 = (ulong)plVar13 & 0xffffffff;
              kfree(puVar5);
              puVar5 = puVar6;
              goto LAB_001012e8;
            }
            plVar7 = (long *)dma_buf_map_attachment(plVar13,0);
            puVar6[4] = plVar7;
            if ((long *)0xfffffffffffff000 < plVar7) {
              _dev_err(uVar12,"%s: Fail to map attachment, rc = %d\n","msm_audio_dma_buf_map",
                       (ulong)plVar7 & 0xffffffff);
              dma_buf_detach(puVar11,plVar13);
              plVar13 = plVar7;
              goto LAB_001015f0;
            }
            uVar10 = *(ulong *)(*plVar7 + 0x10);
            kfree(puVar5);
            mutex_lock(lVar14 + -0x60);
            plVar13 = *(long **)(lVar14 + -0x68);
            puVar5 = puVar6 + 5;
            uVar8 = __list_add_valid(puVar5,plVar13,lVar14 + -0x70);
            if ((uVar8 & 1) != 0) {
              *(undefined8 **)(lVar14 + -0x68) = puVar5;
              puVar6[5] = lVar14 + -0x70;
              puVar6[6] = plVar13;
              *plVar13 = (long)puVar5;
            }
            mutex_unlock(lVar14 + -0x60);
            if (cVar1 != '\0') goto LAB_00101240;
LAB_001012a8:
            iVar2 = 0;
          }
LAB_00101300:
          *piVar4 = param_3;
          *(undefined8 **)(piVar4 + 4) = puVar11;
          *(ulong *)(piVar4 + 6) = uVar10;
          *(undefined8 *)(piVar4 + 2) = uVar15;
          *(undefined8 *)(piVar4 + 8) = *(undefined8 *)(lVar14 + -0x80);
          mutex_lock(&msm_audio_ion_fd_list);
          plVar13 = DAT_00101bf8;
          puVar11 = &DAT_00101bf0;
          do {
            puVar11 = (undefined8 *)*puVar11;
            if (puVar11 == &DAT_00101bf0) {
              plVar7 = (long *)(piVar4 + 10);
              uVar10 = __list_add_valid(plVar7,DAT_00101bf8,&DAT_00101bf0);
              if ((uVar10 & 1) != 0) {
                DAT_00101bf8 = plVar7;
                *(undefined8 **)(piVar4 + 10) = &DAT_00101bf0;
                *(long **)(piVar4 + 0xc) = plVar13;
                *plVar13 = (long)plVar7;
              }
              goto LAB_00101388;
            }
          } while (*(int *)(puVar11 + -5) != param_3);
          _printk(&DAT_00102314,"msm_audio_update_fd_list");
          goto LAB_00101388;
        }
        _printk(&DAT_00102011,"msm_audio_ion_import");
        uVar10 = 0xffffffea;
      }
LAB_00101510:
      iVar2 = (int)uVar10;
      _printk(&DAT_00102115,"msm_audio_ion_ioctl",uVar10);
      kfree(lVar3);
      kfree(piVar4);
      break;
    case 0x40046162:
      mutex_lock(&msm_audio_ion_fd_list,param_2,uVar10);
      puVar11 = &DAT_00101bf0;
      do {
        puVar11 = (undefined8 *)*puVar11;
        if (puVar11 == &DAT_00101bf0) {
          lVar14 = 0;
          goto LAB_00101188;
        }
      } while (*(int *)(puVar11 + -5) != param_3);
      lVar14 = puVar11[-3];
LAB_00101188:
      mutex_unlock(&msm_audio_ion_fd_list);
      iVar2 = msm_audio_ion_free(lVar14,pcVar16);
      if (iVar2 < 0) {
        _printk(&DAT_00101d0e,"msm_audio_ion_ioctl",iVar2);
      }
      else {
        if (lVar14 != 0) {
          mutex_lock(&msm_audio_ion_fd_list);
          plVar13 = &DAT_00101bf0;
          do {
            plVar13 = (long *)*plVar13;
            if (plVar13 == &DAT_00101bf0) goto LAB_00101388;
          } while (plVar13[-3] != lVar14);
          uVar10 = __list_del_entry_valid(plVar13);
          if ((uVar10 & 1) != 0) {
            lVar14 = *plVar13;
            plVar7 = (long *)plVar13[1];
            *(long **)(lVar14 + 8) = plVar7;
            *plVar7 = lVar14;
          }
          *plVar13 = -0x2152ffffffffff00;
          plVar13[1] = -0x2152fffffffffede;
          kfree(plVar13 + -5);
          goto LAB_00101388;
        }
        _printk(&DAT_00101c38,"msm_audio_delete_fd_entry");
      }
      break;
    default:
      goto switchD_00100ecc_caseD_40046163;
    case 0x4004616d:
      mutex_lock(&msm_audio_ion_fd_list,param_2,uVar10);
      puVar11 = &DAT_00101bf0;
      do {
        puVar11 = (undefined8 *)*puVar11;
        if (puVar11 == &DAT_00101bf0) goto LAB_001012b0;
      } while (*(int *)(puVar11 + -5) != param_3);
      uVar12 = puVar11[-2];
      uVar15 = puVar11[-4];
      mutex_unlock(&msm_audio_ion_fd_list);
      iVar2 = qcom_scm_assign_mem(uVar12,uVar15,&uStack_88,&local_78,2);
      if (-1 < iVar2) {
        mutex_lock(&msm_audio_ion_fd_list);
        puVar11 = &DAT_00101bf0;
        do {
          puVar11 = (undefined8 *)*puVar11;
          if (puVar11 == &DAT_00101bf0) goto LAB_00101388;
        } while (*(int *)(puVar11 + -5) != param_3);
        *(undefined1 *)(puVar11 + 2) = 1;
        goto LAB_00101388;
      }
      puVar9 = &DAT_00101ee6;
LAB_00101434:
      _printk(puVar9,"msm_audio_ion_ioctl",iVar2,uVar12,uVar15);
      break;
    case 0x4004616e:
      mutex_lock(&msm_audio_ion_fd_list,param_2,uVar10);
      puVar11 = &DAT_00101bf0;
      do {
        puVar11 = (undefined8 *)*puVar11;
        if (puVar11 == &DAT_00101bf0) goto LAB_001012b0;
      } while (*(int *)(puVar11 + -5) != param_3);
      uVar12 = puVar11[-2];
      uVar15 = puVar11[-4];
      mutex_unlock(&msm_audio_ion_fd_list);
      iVar2 = qcom_scm_assign_mem(uVar12,uVar15,&local_90,&local_80,1);
      if (iVar2 < 0) {
        puVar9 = &DAT_00101d27;
        goto LAB_00101434;
      }
      mutex_lock(&msm_audio_ion_fd_list);
      puVar11 = &DAT_00101bf0;
      do {
        puVar11 = (undefined8 *)*puVar11;
        if (puVar11 == &DAT_00101bf0) goto LAB_00101388;
      } while (*(int *)(puVar11 + -5) != param_3);
      *(undefined1 *)(puVar11 + 2) = 0;
LAB_00101388:
      mutex_unlock(&msm_audio_ion_fd_list);
    }
  }
  else {
switchD_00100ecc_caseD_40046163:
    _printk(&DAT_001021c5,"msm_audio_ion_ioctl");
    iVar2 = -0x16;
  }
  lVar14 = (long)iVar2;
LAB_00101398:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar14);
  }
  return;
LAB_001012b0:
  mutex_unlock(&msm_audio_ion_fd_list);
  _printk(&DAT_00102065,"msm_audio_ion_ioctl",0xffffffea);
  lVar14 = -0x16;
  goto LAB_00101398;
}



//------------------------------------------------------------
// msm_audio_ion_ioctl_compat @ 00101608 size=32
// signature: undefined msm_audio_ion_ioctl_compat(void)
// callers: []
//------------------------------------------------------------

void msm_audio_ion_ioctl_compat(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  msm_audio_ion_ioctl(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// msm_audio_ion_open @ 0010162c size=40
// signature: undefined msm_audio_ion_open(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_audio_ion_open(long param_1)

{
  get_device(*(undefined8 *)(*(long *)(param_1 + 0x290) + -8));
  return 0;
}



//------------------------------------------------------------
// msm_audio_ion_release @ 00101658 size=40
// signature: undefined msm_audio_ion_release(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_audio_ion_release(long param_1)

{
  put_device(*(undefined8 *)(*(long *)(param_1 + 0x290) + -8));
  return 0;
}



//------------------------------------------------------------
// init_module @ 001016b8 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&msm_audio_ion_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00104000 size=1
// signature: undefined mutex_lock(void)
// callers: [msm_audio_update_fd_list, msm_audio_ion_crash_handler, msm_audio_ion_ioctl, msm_audio_get_phy_addr, msm_audio_ion_free, msm_audio_delete_fd_entry, msm_audio_get_handle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104008 size=1
// signature: undefined _printk(void)
// callers: [msm_audio_update_fd_list, msm_audio_ion_crash_handler, msm_audio_ion_ioctl, msm_audio_get_phy_addr, msm_audio_ion_free, msm_audio_delete_fd_entry, msm_audio_ion_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00104010 size=1
// signature: undefined __list_add_valid(void)
// callers: [msm_audio_update_fd_list, msm_audio_ion_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104018 size=1
// signature: undefined mutex_unlock(void)
// callers: [msm_audio_update_fd_list, msm_audio_ion_crash_handler, msm_audio_ion_ioctl, msm_audio_get_phy_addr, msm_audio_ion_free, msm_audio_delete_fd_entry, msm_audio_get_handle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00104020 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [msm_audio_ion_crash_handler, msm_audio_ion_ioctl, msm_audio_delete_fd_entry, msm_audio_dma_buf_unmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00104028 size=1
// signature: undefined kfree(void)
// callers: [msm_audio_ion_crash_handler, msm_audio_ion_ioctl, msm_audio_delete_fd_entry, msm_audio_dma_buf_unmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_assign_mem @ 00104030 size=1
// signature: undefined qcom_scm_assign_mem(void)
// callers: [msm_audio_ion_crash_handler, msm_audio_ion_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_assign_mem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104038 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [msm_audio_ion_crash_handler, msm_audio_ion_ioctl, msm_audio_ion_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_vunmap @ 00104040 size=1
// signature: undefined dma_buf_vunmap(void)
// callers: [msm_audio_ion_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_vunmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_end_cpu_access @ 00104048 size=1
// signature: undefined dma_buf_end_cpu_access(void)
// callers: [msm_audio_ion_ioctl, msm_audio_ion_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_end_cpu_access(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104050 size=1
// signature: undefined _dev_err(void)
// callers: [msm_audio_ion_ioctl, msm_audio_ion_free, msm_audio_ion_probe, msm_audio_dma_buf_unmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00104058 size=1
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
// platform_driver_unregister @ 00104060 size=1
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
// dma_buf_unmap_attachment @ 00104068 size=1
// signature: undefined dma_buf_unmap_attachment(void)
// callers: [msm_audio_dma_buf_unmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_unmap_attachment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_detach @ 00104070 size=1
// signature: undefined dma_buf_detach(void)
// callers: [msm_audio_ion_ioctl, msm_audio_dma_buf_unmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_detach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_put @ 00104078 size=1
// signature: undefined dma_buf_put(void)
// callers: [msm_audio_ion_ioctl, msm_audio_dma_buf_unmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00104080 size=1
// signature: undefined devm_kmalloc(void)
// callers: [msm_audio_ion_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00104088 size=1
// signature: undefined of_find_property(void)
// callers: [msm_audio_ion_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00104090 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [msm_audio_ion_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u64 @ 00104098 size=1
// signature: undefined of_property_read_u64(void)
// callers: [msm_audio_ion_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 001040a0 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [msm_audio_ion_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001040a8 size=1
// signature: undefined __mutex_init(void)
// callers: [msm_audio_ion_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 001040b0 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [msm_audio_ion_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 001040b8 size=1
// signature: undefined __class_create(void)
// callers: [msm_audio_ion_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 001040c0 size=1
// signature: undefined device_create(void)
// callers: [msm_audio_ion_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 001040c8 size=1
// signature: undefined cdev_init(void)
// callers: [msm_audio_ion_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 001040d0 size=1
// signature: undefined cdev_add(void)
// callers: [msm_audio_ion_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 001040d8 size=1
// signature: undefined device_destroy(void)
// callers: [msm_audio_ion_remove, msm_audio_ion_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 001040e0 size=1
// signature: undefined class_destroy(void)
// callers: [msm_audio_ion_remove, msm_audio_ion_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 001040e8 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [msm_audio_ion_remove, msm_audio_ion_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 001040f0 size=1
// signature: undefined cdev_del(void)
// callers: [msm_audio_ion_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00104100 size=1
// signature: undefined kmalloc_trace(void)
// callers: [msm_audio_ion_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_get @ 00104108 size=1
// signature: undefined dma_buf_get(void)
// callers: [msm_audio_ion_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_attach @ 00104110 size=1
// signature: undefined dma_buf_attach(void)
// callers: [msm_audio_ion_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_attach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_map_attachment @ 00104118 size=1
// signature: undefined dma_buf_map_attachment(void)
// callers: [msm_audio_ion_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_map_attachment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_begin_cpu_access @ 00104120 size=1
// signature: undefined dma_buf_begin_cpu_access(void)
// callers: [msm_audio_ion_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_begin_cpu_access(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_vmap @ 00104128 size=1
// signature: undefined dma_buf_vmap(void)
// callers: [msm_audio_ion_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_vmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_device @ 00104130 size=1
// signature: undefined get_device(void)
// callers: [msm_audio_ion_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 00104138 size=1
// signature: undefined put_device(void)
// callers: [msm_audio_ion_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



