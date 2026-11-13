// Decompiled by Ghidra 12.2
// Program: llcc-qcom.ko
// Image base: 00100000

//------------------------------------------------------------
// llcc_tcm_activate @ 0010056c size=332
// signature: undefined llcc_tcm_activate(void)
// callers: []
//------------------------------------------------------------

long llcc_tcm_activate(void)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  void *__s;
  
  if (0xfffffffffffff000 < tcm_drv_data) {
    return -0x205;
  }
  mutex_lock(tcm_drv_data + 0x20);
  iVar3 = -0x10;
  if ((*(ulong *)(tcm_drv_data + 8) != 0) && (*(ulong *)(tcm_drv_data + 8) < 0xfffffffffffff001)) {
    iVar3 = -0x10;
    if ((*(ulong *)(tcm_drv_data + 0x10) != 0) &&
       (*(ulong *)(tcm_drv_data + 0x10) < 0xfffffffffffff001)) {
      if (*(char *)(tcm_drv_data + 0x18) == '\0') {
        iVar3 = llcc_slice_activate();
        if (iVar3 == 0) {
          if (*(char *)(drv_data + 0x90) == '\0') {
LAB_00100688:
            lVar1 = tcm_drv_data + 0x20;
            *(undefined1 *)(tcm_drv_data + 0x18) = 1;
            mutex_unlock(lVar1);
            return *(long *)(tcm_drv_data + 0x10);
          }
          uVar2 = 0x68000000000713;
          if (arm64_use_ng_mappings != '\0') {
            uVar2 = 0x68000000000f13;
          }
          __s = (void *)ioremap_prot(**(undefined8 **)(tcm_drv_data + 0x10),
                                     (*(undefined8 **)(tcm_drv_data + 0x10))[2],uVar2);
          iVar3 = -0xc;
          if ((__s != (void *)0x0) && (__s < (void *)0xfffffffffffff001)) {
            memset(__s,0xff,*(size_t *)(*(long *)(tcm_drv_data + 0x10) + 0x10));
            iounmap(__s);
            goto LAB_00100688;
          }
        }
        else if (*(char *)(tcm_drv_data + 0x19) != '\0') goto LAB_001005d8;
        llcc_slice_deactivate(*(undefined8 *)(tcm_drv_data + 8));
      }
      else {
        iVar3 = -0x10;
      }
    }
  }
LAB_001005d8:
  mutex_unlock(tcm_drv_data + 0x20);
  return (long)iVar3;
}



//------------------------------------------------------------
// llcc_slice_activate @ 001006bc size=316
// signature: undefined llcc_slice_activate(void)
// callers: [qcom_llcc_cfg_program, llcc_tcm_activate]
//------------------------------------------------------------

ulong llcc_slice_activate(uint *param_1)

{
  uint *puVar1;
  char cVar2;
  bool bVar3;
  ulong uVar4;
  uint uVar5;
  ulong uVar6;
  
  if (0xfffffffffffff000 < drv_data) {
    return drv_data & 0xffffffff;
  }
  if (param_1 == (uint *)0x0) {
    return 0xffffffea;
  }
  if ((uint *)0xfffffffffffff000 < param_1) {
    return 0xffffffea;
  }
  mutex_lock(drv_data + 0x20);
  if ((int)param_1[4] < 1) {
    uVar5 = *param_1;
    if ((*(ulong *)(*(long *)(drv_data + 0x60) + ((ulong)(uVar5 >> 3) & 0x1ffffff8)) >>
         ((ulong)uVar5 & 0x3f) & 1) == 0) {
      uVar5 = llcc_update_act_ctrl((ulong)uVar5,2,2);
      if (uVar5 != 0) {
        mutex_unlock(drv_data + 0x20);
        return (ulong)uVar5;
      }
      puVar1 = param_1 + 4;
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 + 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
        uVar4 = drv_data;
      } while (cVar2 != '\0');
      DataMemoryBarrier(2,3);
      uVar6 = (ulong)(*param_1 >> 3) & 0x1ffffff8;
      *(ulong *)(*(long *)(drv_data + 0x60) + uVar6) =
           *(ulong *)(*(long *)(drv_data + 0x60) + uVar6) | 1L << ((ulong)*param_1 & 0x3f);
      goto LAB_0010074c;
    }
  }
  else {
    param_1 = param_1 + 4;
    Hint_Prefetch(param_1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(param_1,0x10);
      if (bVar3) {
        *param_1 = *param_1 + 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    DataMemoryBarrier(2,3);
  }
  uVar4 = drv_data;
LAB_0010074c:
  mutex_unlock(uVar4 + 0x20);
  return 0;
}



//------------------------------------------------------------
// llcc_slice_deactivate @ 00100814 size=288
// signature: undefined llcc_slice_deactivate(void)
// callers: [llcc_tcm_activate, llcc_tcm_deactivate]
//------------------------------------------------------------

ulong llcc_slice_deactivate(uint *param_1)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  ulong uVar4;
  ulong uVar5;
  
  if (drv_data < 0xfffffffffffff001) {
    uVar5 = 0xffffffea;
    if ((param_1 != (uint *)0x0) && (param_1 < (uint *)0xfffffffffffff001)) {
      mutex_lock(drv_data + 0x20);
      if ((int)param_1[4] < 2) {
        uVar3 = *param_1;
        if ((*(ulong *)(*(long *)(drv_data + 0x60) + ((ulong)(uVar3 >> 3) & 0x1ffffff8)) >>
             ((ulong)uVar3 & 0x3f) & 1) != 0) {
          uVar3 = llcc_update_act_ctrl((ulong)uVar3,4,1);
          if (uVar3 == 0) {
            param_1[4] = 0;
            uVar5 = drv_data;
            uVar4 = (ulong)(*param_1 >> 3) & 0x1ffffff8;
            *(ulong *)(*(long *)(drv_data + 0x60) + uVar4) =
                 *(ulong *)(*(long *)(drv_data + 0x60) + uVar4) &
                 (1L << ((ulong)*param_1 & 0x3f) ^ 0xffffffffffffffffU);
          }
          else {
            uVar5 = drv_data;
          }
          mutex_unlock(uVar5 + 0x20);
          return (ulong)uVar3;
        }
      }
      else {
        param_1 = param_1 + 4;
        Hint_Prefetch(param_1,2,0,1);
        do {
          cVar1 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(param_1,0x10);
          if (bVar2) {
            *param_1 = *param_1 - 1;
            cVar1 = ExclusiveMonitorsStatus();
          }
        } while (cVar1 != '\0');
        DataMemoryBarrier(2,3);
      }
      mutex_unlock(drv_data + 0x20);
      uVar5 = 0;
    }
  }
  else {
    uVar5 = drv_data & 0xffffffff;
  }
  return uVar5;
}



//------------------------------------------------------------
// llcc_tcm_deactivate @ 00100944 size=140
// signature: undefined llcc_tcm_deactivate(void)
// callers: []
//------------------------------------------------------------

void llcc_tcm_deactivate(ulong param_1)

{
  ulong uVar1;
  
  if ((tcm_drv_data < 0xfffffffffffff001 && param_1 != 0) && (param_1 < 0xfffffffffffff001)) {
    mutex_lock(tcm_drv_data + 0x20);
    uVar1 = tcm_drv_data;
    if (((*(ulong *)(tcm_drv_data + 8) != 0) &&
        (((*(ulong *)(tcm_drv_data + 8) < 0xfffffffffffff001 &&
          (*(ulong *)(tcm_drv_data + 0x10) != 0)) &&
         (*(ulong *)(tcm_drv_data + 0x10) < 0xfffffffffffff001)))) &&
       (*(char *)(tcm_drv_data + 0x18) != '\0')) {
      if (*(char *)(tcm_drv_data + 0x19) == '\0') {
        llcc_slice_deactivate();
      }
      uVar1 = tcm_drv_data;
      *(undefined1 *)(tcm_drv_data + 0x18) = 0;
    }
    mutex_unlock(uVar1 + 0x20);
  }
  return;
}



//------------------------------------------------------------
// llcc_tcm_get_phys_addr @ 001009d4 size=68
// signature: undefined llcc_tcm_get_phys_addr(void)
// callers: []
//------------------------------------------------------------

undefined8 llcc_tcm_get_phys_addr(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((drv_data != 0) && (drv_data < 0xfffffffffffff001)) {
    if (*(char *)(drv_data + 0x90) != '\0') {
      return 0;
    }
    uVar1 = 0;
    if ((param_1 != (undefined8 *)0x0) && (param_1 < (undefined8 *)0xfffffffffffff001)) {
      uVar1 = *param_1;
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// llcc_tcm_get_virt_addr @ 00100a1c size=68
// signature: undefined llcc_tcm_get_virt_addr(void)
// callers: []
//------------------------------------------------------------

undefined8 llcc_tcm_get_virt_addr(ulong param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((drv_data != 0) && (drv_data < 0xfffffffffffff001)) {
    if (*(char *)(drv_data + 0x90) != '\0') {
      return 0;
    }
    uVar1 = 0;
    if ((param_1 != 0) && (param_1 < 0xfffffffffffff001)) {
      uVar1 = *(undefined8 *)(param_1 + 8);
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// llcc_tcm_get_slice_size @ 00100a64 size=28
// signature: undefined llcc_tcm_get_slice_size(void)
// callers: []
//------------------------------------------------------------

undefined8 llcc_tcm_get_slice_size(ulong param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((param_1 != 0) && (param_1 < 0xfffffffffffff001)) {
    uVar1 = *(undefined8 *)(param_1 + 0x10);
  }
  return uVar1;
}



//------------------------------------------------------------
// llcc_slice_getd @ 00100a84 size=372
// signature: undefined llcc_slice_getd(void)
// callers: [qcom_llcc_cfg_program, qcom_llcc_tcm_init]
//------------------------------------------------------------

ulong llcc_slice_getd(int param_1)

{
  uint uVar1;
  bool bVar2;
  ulong uVar3;
  ulong *puVar4;
  ulong uVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  
  mutex_lock(dev_avail);
  if (is_llcc_device_available_ptr == 0) {
    of_find_node_by_name(0,"cache-controller");
    uVar3 = of_device_is_available();
    if ((uVar3 & 1) == 0) {
      _printk(&DAT_00102f66);
      drv_data = 0xffffffffffffffed;
    }
    is_llcc_device_available_ptr = drv_data;
  }
  mutex_unlock(dev_avail);
  if ((is_llcc_device_available_ptr == 0xffffffffffffffed) || (0xfffffffffffff000 < drv_data)) {
    uVar3 = drv_data;
  }
  else if (*(char *)(drv_data + 0x90) == '\0') {
    piVar7 = *(int **)(drv_data + 0x10);
    uVar1 = *(uint *)(drv_data + 0x54);
    bVar2 = piVar7 != (int *)0x0;
    uVar6 = 0;
    if ((piVar7 != (int *)0x0) && (uVar1 != 0)) {
      uVar6 = 0;
      while (piVar8 = piVar7 + 0xd, *piVar7 != param_1) {
        bVar2 = piVar8 != (int *)0x0;
        uVar6 = uVar6 + 1;
        if ((piVar8 == (int *)0x0) || (piVar7 = piVar8, uVar1 <= uVar6)) goto LAB_00100bb4;
      }
      bVar2 = true;
    }
LAB_00100bb4:
    uVar3 = 0xffffffffffffffed;
    if ((((uVar6 != uVar1) && (bVar2)) && (uVar5 = *(ulong *)(drv_data + 0x80), uVar5 != 0)) &&
       (uVar5 < 0xfffffffffffff001)) {
      uVar3 = uVar5 + (ulong)uVar6 * 0x18;
    }
  }
  else {
    uVar3 = (ulong)*(uint *)(drv_data + 0x54);
    if (*(uint *)(drv_data + 0x54) != 0) {
      puVar4 = (ulong *)(*(long *)(drv_data + 0x88) + 8);
      do {
        if ((int)puVar4[-1] == param_1) {
          return *puVar4;
        }
        puVar4 = puVar4 + 2;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    _printk(&DAT_00102f1b,param_1);
    uVar3 = 0xffffffffffffffea;
  }
  return uVar3;
}



//------------------------------------------------------------
// llcc_slice_putd @ 00100bfc size=64
// signature: undefined llcc_slice_putd(void)
// callers: []
//------------------------------------------------------------

void llcc_slice_putd(undefined4 *param_1)

{
  code *pcVar1;
  
  if (((param_1 != (undefined4 *)0x0) && (param_1 < (undefined4 *)0xfffffffffffff001)) &&
     (param_1[4] != 0)) {
    __warn_printk(" Slice %d is still active\n",*param_1);
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x100c3c);
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// llcc_update_act_ctrl @ 00100c40 size=604
// signature: undefined llcc_update_act_ctrl(void)
// callers: [llcc_slice_activate, llcc_slice_deactivate]
//------------------------------------------------------------

ulong llcc_update_act_ctrl(int param_1,uint param_2,uint param_3)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  ulong uVar7;
  uint local_5c;
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  local_5c = 0;
  uVar7 = drv_data;
  if (drv_data < 0xfffffffffffff001) {
    uVar1 = regmap_write(*(undefined8 *)(drv_data + 8),param_1 << 0xc,param_2 | 1);
    uVar7 = uVar1 & 0xffffffff;
    if ((int)uVar1 == 0) {
      uVar1 = regmap_write(*(undefined8 *)(drv_data + 8),param_1 << 0xc,param_2 & 0xfffffffe);
      uVar7 = uVar1 & 0xffffffff;
      if ((int)uVar1 == 0) {
        uVar5 = param_1 << 0xc | 4;
        if (*(int *)(drv_data + 0x74) < 0x29) {
LAB_00100db0:
          lVar2 = ktime_get();
          uVar1 = regmap_read(*(undefined8 *)(drv_data + 8),uVar5,&local_5c);
          uVar7 = uVar1 & 0xffffffff;
          if ((int)uVar1 == 0) {
            do {
              if ((local_5c & param_3) == 0) {
                uVar7 = 0;
                goto LAB_00100dd4;
              }
              lVar3 = ktime_get();
              if (lVar2 + 100000 < lVar3) {
                uVar1 = regmap_read(*(undefined8 *)(drv_data + 8),uVar5,&local_5c);
                uVar7 = uVar1 & 0xffffffff;
                uVar5 = 0;
                if ((local_5c & param_3) != 0) {
                  uVar5 = 0xffffff92;
                }
                if ((int)uVar1 == 0) {
                  uVar7 = (ulong)uVar5;
                }
                goto LAB_00100dd4;
              }
              Yield();
              uVar7 = regmap_read(*(undefined8 *)(drv_data + 8),uVar5,&local_5c);
            } while ((int)uVar7 == 0);
            uVar7 = uVar7 & 0xffffffff;
          }
LAB_00100dd4:
          if (0x28 < *(int *)(drv_data + 0x74)) {
            regmap_write(*(undefined8 *)(drv_data + 8),param_1 << 0xc | 8,1);
          }
        }
        else {
          lVar2 = ktime_get();
          uVar1 = regmap_read(*(undefined8 *)(drv_data + 8),uVar5,&local_5c);
          uVar7 = uVar1 & 0xffffffff;
          if ((int)uVar1 == 0) {
            do {
              if (((byte)local_5c >> 4 & 1) != 0) {
                uVar7 = 0;
                uVar4 = 1;
LAB_00100da8:
                iVar6 = (int)uVar7;
                if ((iVar6 == 0) && (uVar4 != 0)) goto LAB_00100db0;
                if (iVar6 != 0) {
                  uVar4 = 1;
                }
                uVar5 = 0;
                if (uVar4 == 0) {
                  uVar5 = 0xffffff92;
                }
                if (iVar6 == 0) {
                  uVar7 = (ulong)uVar5;
                }
                goto LAB_00100cc4;
              }
              lVar3 = ktime_get();
              if (lVar2 + 100000 < lVar3) {
                uVar7 = regmap_read(*(undefined8 *)(drv_data + 8),uVar5,&local_5c);
                uVar7 = uVar7 & 0xffffffff;
                uVar4 = local_5c >> 4 & 1;
                goto LAB_00100da8;
              }
              Yield();
              uVar7 = regmap_read(*(undefined8 *)(drv_data + 8),uVar5,&local_5c);
            } while ((int)uVar7 == 0);
            uVar7 = uVar7 & 0xffffffff;
          }
        }
      }
    }
  }
LAB_00100cc4:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7 & 0xffffffff;
}



//------------------------------------------------------------
// llcc_get_slice_id @ 00100ea0 size=28
// signature: undefined llcc_get_slice_id(void)
// callers: []
//------------------------------------------------------------

undefined4 llcc_get_slice_id(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffea;
  if ((param_1 != (undefined4 *)0x0) && (param_1 < (undefined4 *)0xfffffffffffff001)) {
    uVar1 = *param_1;
  }
  return uVar1;
}



//------------------------------------------------------------
// llcc_get_slice_size @ 00100ec0 size=28
// signature: undefined llcc_get_slice_size(void)
// callers: []
//------------------------------------------------------------

undefined8 llcc_get_slice_size(ulong param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((param_1 != 0) && (param_1 < 0xfffffffffffff001)) {
    uVar1 = *(undefined8 *)(param_1 + 8);
  }
  return uVar1;
}



//------------------------------------------------------------
// llcc_configure_staling_mode @ 00100ee0 size=148
// signature: undefined llcc_configure_staling_mode(void)
// callers: []
//------------------------------------------------------------

ulong llcc_configure_staling_mode(undefined4 *param_1,uint *param_2)

{
  code *pcVar1;
  ulong uVar2;
  
  uVar2 = drv_data;
  if (drv_data < 0xfffffffffffff001) {
    if (*(int *)(drv_data + 0x74) < 0x32) {
      uVar2 = 0xffffffa1;
    }
    else {
      uVar2 = 0xffffffea;
      if (((param_2 != (uint *)0x0) && (param_1 != (undefined4 *)0x0)) &&
         (param_1 < (undefined4 *)0xfffffffffffff001)) {
        if (1 < *param_2) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x100f74);
          (*pcVar1)();
        }
        if (*(int *)((&staling_mode_ops)[*param_2] + -4) != 0x47079941) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100f58);
          (*pcVar1)();
        }
        uVar2 = (*(code *)(&staling_mode_ops)[*param_2])(*param_1);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
  }
  return uVar2 & 0xffffffff;
}



//------------------------------------------------------------
// llcc_notif_staling_inc_counter @ 00100f78 size=212
// signature: undefined llcc_notif_staling_inc_counter(void)
// callers: []
//------------------------------------------------------------

void llcc_notif_staling_inc_counter(int *param_1)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = 0;
  if (drv_data < 0xfffffffffffff001) {
    if (*(int *)(drv_data + 0x74) < 0x32) {
      uVar3 = 0xffffffa1;
    }
    else {
      uVar3 = 0xffffffea;
      if ((param_1 != (int *)0x0) && (param_1 < (int *)0xfffffffffffff001)) {
        uVar1 = *param_1 << 0xc | 0xc;
        uVar3 = regmap_update_bits_base(*(undefined8 *)(drv_data + 8),uVar1,1,1,0,0,0);
        if ((int)uVar3 == 0) {
          uVar3 = regmap_read(*(undefined8 *)(drv_data + 8),uVar1,&local_2c);
        }
      }
    }
  }
  else {
    uVar3 = drv_data & 0xffffffff;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// llcc_staling_conf_capacity @ 00101050 size=68
// signature: undefined llcc_staling_conf_capacity(void)
// callers: []
//------------------------------------------------------------

void llcc_staling_conf_capacity(int param_1)

{
  regmap_update_bits_base(*(undefined8 *)(drv_data + 8),param_1 << 0xc | 0x10,1,0,0,0,0);
  return;
}



//------------------------------------------------------------
// llcc_staling_conf_notify @ 00101098 size=148
// signature: undefined llcc_staling_conf_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 llcc_staling_conf_notify(int param_1,long param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_2 + 8) == 0) {
    uVar1 = param_1 << 0xc | 0x10;
    uVar2 = regmap_update_bits_base(*(undefined8 *)(drv_data + 8),uVar1,1,1,0,0,0);
    if ((int)uVar2 == 0) {
      uVar2 = regmap_update_bits_base
                        (*(undefined8 *)(drv_data + 8),uVar1,0x70,*(undefined1 *)(param_2 + 4),0,0,0
                        );
    }
  }
  else {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// qcom_llcc_probe @ 00101130 size=2448
// signature: undefined qcom_llcc_probe(void)
// callers: []
//------------------------------------------------------------

ulong qcom_llcc_probe(long param_1)

{
  ushort *puVar1;
  char *pcVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  ulong *puVar6;
  int iVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  long *plVar11;
  ulong *puVar12;
  ulong uVar13;
  ulong uVar14;
  char *pcVar15;
  undefined4 uVar16;
  long lVar17;
  uint uVar18;
  undefined1 *puVar19;
  undefined4 uVar20;
  uint uVar21;
  ushort *puVar22;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  char *local_1b0;
  undefined8 local_1a8;
  long local_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  ulong *puStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined1 local_108;
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  local_1c0 = 0;
  uStack_1b8 = 0;
  if (drv_data < (ulong *)0xfffffffffffff001) {
    uVar9 = 0xfffffff0;
    goto LAB_001016c8;
  }
  pcVar2 = (char *)(param_1 + 0x10);
  drv_data = (ulong *)devm_kmalloc(pcVar2,0x98,0xdc0);
  if (drv_data == (ulong *)0x0) {
LAB_001016bc:
    uVar9 = 0xfffffff4;
  }
  else {
    memset(&local_1a0,0,0x138);
    local_1a8 = 0x400000020;
    uStack_198 = (char *)CONCAT44(0x20,(undefined4)uStack_198);
    local_108 = 1;
    uVar9 = devm_platform_ioremap_resource_byname(param_1,"llcc_base");
    if (uVar9 < 0xfffffffffffff001) {
      local_1b0 = "llcc_base";
      uVar9 = __devm_regmap_init_mmio_clk(pcVar2,0,uVar9,&local_1b0,0,0);
    }
    *drv_data = uVar9;
    if (uVar9 < 0xfffffffffffff001) {
      memset(&local_1a0,0,0x138);
      local_1a8 = 0x400000020;
      uStack_198 = (char *)CONCAT44(0x20,(undefined4)uStack_198);
      local_108 = 1;
      uVar9 = devm_platform_ioremap_resource_byname(param_1,"llcc_broadcast_base");
      if (uVar9 < 0xfffffffffffff001) {
        local_1b0 = "llcc_broadcast_base";
        uVar9 = __devm_regmap_init_mmio_clk(pcVar2,0,uVar9,&local_1b0,0,0);
      }
      drv_data[1] = uVar9;
      if (uVar9 < 0xfffffffffffff001) {
        iVar7 = of_property_match_string
                          (*(undefined8 *)(param_1 + 0x2f8),"compatible","qcom,llcc-v51");
        if (iVar7 < 0) {
          iVar7 = of_property_match_string
                            (*(undefined8 *)(param_1 + 0x2f8),"compatible","qcom,llcc-v50");
          if (-1 < iVar7) {
            uVar16 = 0x32;
LAB_00101328:
            puVar19 = llcc_offsets_v41;
            uVar20 = 4;
            goto LAB_00101334;
          }
          iVar7 = of_property_match_string
                            (*(undefined8 *)(param_1 + 0x2f8),"compatible","qcom,llcc-v41");
          if (-1 < iVar7) {
            uVar16 = 0x29;
            goto LAB_00101328;
          }
          iVar7 = of_property_match_string
                            (*(undefined8 *)(param_1 + 0x2f8),"compatible","qcom,llcc-v31");
          puVar12 = drv_data;
          if (iVar7 < 0) {
            iVar7 = of_property_match_string
                              (*(undefined8 *)(param_1 + 0x2f8),"compatible","qcom,llcc-v21");
            puVar12 = drv_data;
            if (iVar7 < 0) {
              uVar16 = 0x14;
              puVar19 = llcc_offsets_v2;
            }
            else {
              uVar16 = 0x15;
              puVar19 = llcc_offsets_v21;
            }
            uVar20 = 4;
            drv_data[0xd] = (ulong)puVar19;
            *(undefined4 *)((long)puVar12 + 0x74) = uVar16;
            goto LAB_0010133c;
          }
          *(undefined4 *)((long)drv_data + 0x74) = 0x1f;
          puVar12[0xd] = (ulong)&llcc_offsets_v31;
          *(undefined4 *)((long)puVar12 + 0x5c) = 2;
          iVar7 = of_property_match_string
                            (*(undefined8 *)(param_1 + 0x2f8),"compatible",
                             "qcom,monaco_auto_ivi-llcc");
          if (-1 < iVar7) {
            drv_data[0xd] = (ulong)llcc_offsets_monaco_auto;
          }
        }
        else {
          uVar16 = 0x33;
          puVar19 = (undefined1 *)&llcc_offsets_v51;
          uVar20 = 2;
LAB_00101334:
          puVar12 = drv_data;
          *(undefined4 *)((long)drv_data + 0x74) = uVar16;
          puVar12[0xd] = (ulong)puVar19;
LAB_0010133c:
          *(undefined4 *)((long)puVar12 + 0x5c) = uVar20;
        }
        iVar7 = of_property_read_variable_u32_array
                          (*(undefined8 *)(param_1 + 0x2f8),"max-banks",(long)&uStack_1b8 + 4,1,0);
        puVar12 = drv_data;
        if (-1 < iVar7) {
          uVar21 = *(uint *)((long)drv_data + 0x5c);
          if (uStack_1b8._4_4_ <= *(uint *)((long)drv_data + 0x5c)) {
            uVar21 = uStack_1b8._4_4_;
          }
          *(uint *)((long)drv_data + 0x5c) = uVar21;
        }
        __mutex_init(puVar12 + 4,"&drv_data->lock",&qcom_llcc_probe___key);
        *(ulong **)(param_1 + 0xa8) = drv_data;
        lVar10 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,sct-initialized",0);
        *(bool *)(drv_data + 0x12) = lVar10 != 0;
        if (lVar10 == 0) {
          puVar12 = (ulong *)of_device_get_match_data(pcVar2);
          if (puVar12 == (ulong *)0x0) {
            pcVar15 = "No matching LLCC configuration found\n";
LAB_00101888:
            _dev_err(pcVar2,pcVar15);
            uVar9 = 0xffffffed;
          }
          else {
            iVar7 = of_property_read_variable_u32_array
                              (*(undefined8 *)(param_1 + 0x2f8),"qcom,sct-config",&local_1c0,1,0);
            lVar10 = platform_get_resource_byname(param_1,0x200,"multi_ch_reg");
            if (((lVar10 == 0) || (uVar9 = devm_ioremap_resource(pcVar2,lVar10), uVar9 == 0)) ||
               (0xfffffffffffff000 < uVar9)) {
              if (iVar7 < 0) {
                uVar14 = *puVar12;
                uVar21 = (uint)puVar12[1];
              }
              else {
                uVar14 = puVar12[(local_1c0 & 0xffffffff) * 2];
                uVar21 = (uint)(puVar12 + (local_1c0 & 0xffffffff) * 2)[1];
              }
            }
            else {
              iVar7 = of_property_read_u32_index
                                (*(undefined8 *)(param_1 + 0x2f8),"multi-ch-off",1,&uStack_1b8);
              if (iVar7 != 0) {
                pcVar15 = "Couldn\'t get size of multi channel feature register\n";
                goto LAB_00101888;
              }
              iVar7 = of_property_read_variable_u32_array
                                (*(undefined8 *)(param_1 + 0x2f8),"multi-ch-off",
                                 (long)&local_1c0 + 4,1,0);
              if (iVar7 < 0) {
                local_1c0 = local_1c0 & 0xffffffff;
              }
              uVar14 = readl_relaxed(uVar9);
              uVar13 = (uVar14 & 0xffffffff) >> (local_1c0 >> 0x20 & 0x3f) &
                       (ulong)(uint)~(-1 << (ulong)((uint)uStack_1b8 & 0x1f));
              *(int *)(drv_data + 10) = (int)uVar13;
              uVar14 = puVar12[uVar13 * 2];
              uVar21 = (uint)(puVar12 + uVar13 * 2)[1];
              devm_iounmap(pcVar2,uVar9);
            }
            uVar13 = devm_kmalloc(pcVar2,((ulong)uVar21 + (ulong)uVar21 * 2) * 8,0xdc0);
            puVar12 = drv_data;
            uVar9 = 0xfffffff4;
            drv_data[0x10] = uVar13;
            if ((uVar13 != 0) && (uVar13 < 0xfffffffffffff001)) {
              if (uVar21 != 0) {
                uVar8 = 0;
                uVar18 = (uint)puVar12[0xb];
                do {
                  uVar5 = *(uint *)(uVar14 + (long)(int)uVar8 * 0x34 + 4);
                  if (uVar18 < uVar5) {
                    *(uint *)(puVar12 + 0xb) = uVar5;
                    uVar18 = uVar5;
                  }
                  uVar8 = uVar8 + 1;
                } while (uVar21 != uVar8);
              }
              lVar10 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),
                                        "cap-based-alloc-and-pwr-collapse",0);
              puVar12 = drv_data + 0xb;
              *(bool *)(drv_data + 0xf) = lVar10 != 0;
              uVar9 = devm_kmalloc(pcVar2,(ulong)(uint)*puVar12 + 0x3f >> 3 & 0x3ffffff8,0xdc0);
              puVar12 = drv_data;
              drv_data[0xc] = uVar9;
              if (uVar9 == 0) goto LAB_001016bc;
              puVar12[2] = uVar14;
              *(uint *)((long)puVar12 + 0x54) = uVar21;
              uVar8 = qcom_llcc_cfg_program(param_1);
              if (uVar8 != 0) {
                uVar9 = (ulong)uVar8;
                _printk(&DAT_00102eef);
                goto LAB_001016c0;
              }
              local_170 = 0;
              uStack_168 = 0;
              local_180 = 0;
              puStack_178 = (ulong *)0x0;
              local_190 = 0;
              uStack_188 = 0;
              local_1a0 = 0;
              uStack_198 = (char *)0x0;
              local_1b0 = (char *)0x0;
              local_1a8 = 0;
              iVar7 = __of_parse_phandle_with_args
                                (*(undefined8 *)(param_1 + 0x2f8),"memory-region",0,0,0,&local_1b0);
              if (((iVar7 == 0) && (local_1b0 != (char *)0x0)) &&
                 (iVar7 = qcom_llcc_tcm_init(param_1,uVar14,(ulong)uVar21,local_1b0,drv_data),
                 iVar7 != 0)) {
                _dev_err(pcVar2,"Failed to probe TCM manager\n");
              }
LAB_00101648:
              iVar7 = platform_get_irq_optional(param_1,0);
              puVar12 = drv_data;
              *(int *)(drv_data + 0xe) = iVar7;
              if (-1 < iVar7) {
                uStack_188 = 0;
                local_1a8 = 0;
                local_1a0 = 0;
                uStack_198 = "qcom_llcc_edac";
                local_180 = 0;
                puStack_178 = puVar12;
                local_160 = 0;
                uStack_158 = 0;
                local_190 = 0xffffffff;
                local_170 = 0x98;
                uStack_168 = 0;
                local_1b0 = pcVar2;
                uVar9 = platform_device_register_full(&local_1b0);
                if (0xfffffffffffff000 < uVar9) {
                  _dev_err(pcVar2,"Failed to register llcc edac driver\n");
                }
              }
              iVar7 = of_platform_populate(*(undefined8 *)(param_1 + 0x2f8),0,0,pcVar2);
              if (iVar7 < 0) {
                _dev_err(pcVar2,"llcc populate failed!!\n");
              }
              uVar9 = 0;
              goto LAB_001016c8;
            }
          }
        }
        else {
          lVar10 = platform_get_resource_byname(param_1,0x200,"slc_mem_base");
          if (lVar10 == 0) {
            uVar9 = 0xffffffea;
          }
          else {
            plVar11 = (long *)devm_ioremap_resource(pcVar2,lVar10);
            if ((plVar11 == (long *)0x0) || ((long *)0xfffffffffffff000 < plVar11)) {
              _dev_err(pcVar2,"Failed to get SLC shared memory\n");
              uVar9 = 0xffffffea;
            }
            else {
              lVar10 = *plVar11;
              if (lVar10 == 0) {
                uVar9 = 0xfffffdfb;
              }
              else {
                if (lVar10 == 0x5343544641494c) {
                  if ((*(byte *)(plVar11 + 1) & 0xfe) != 0) {
                    pcVar15 = "Error Undefined version\n";
                    goto LAB_00101844;
                  }
                  _dev_err(pcVar2,"SCT Initialization failed with error : %d and param: %d\n",
                           plVar11[2],plVar11[3]);
LAB_0010184c:
                  pcVar15 = "LLCC memory based init memory verification failed\n";
                }
                else {
                  if (lVar10 != 0x534354444f4e45) {
                    pcVar15 = "Unknown SCT Initialization error\n";
LAB_00101844:
                    _dev_err(pcVar2,pcVar15);
                    goto LAB_0010184c;
                  }
                  if ((char)plVar11[1] == '\x01') {
                    uVar21 = *(uint *)(plVar11 + 7);
                    uVar8 = *(uint *)((long)plVar11 + 0x3c);
                  }
                  else {
                    if ((char)plVar11[1] != '\0') goto LAB_0010184c;
                    uVar21 = *(uint *)(plVar11 + 4);
                    uVar8 = *(uint *)((long)plVar11 + 0x24);
                  }
                  if (uVar8 < uVar21) goto LAB_0010184c;
                  _dev_info(pcVar2,"SCT initialized with slice descriptor : %d\n");
                  if ((char)plVar11[1] == '\x01') {
                    uVar14 = (ulong)*(uint *)(plVar11 + 7);
                    uVar21 = *(uint *)((long)plVar11 + 0x3c);
                    puVar22 = (ushort *)(plVar11 + 8);
                    if ((int)plVar11[6] != 0) {
                      slc_tcm_shmem = (long)plVar11 + (ulong)*(uint *)((long)plVar11 + 0x34);
                    }
LAB_0010192c:
                    uVar9 = devm_kmalloc(pcVar2,uVar14 * 0x18,0xdc0);
                    drv_data[0x10] = uVar9;
                    uVar13 = devm_kmalloc(pcVar2,uVar14 << 4,0xdc0);
                    puVar6 = drv_data;
                    uVar9 = 0xfffffff4;
                    puVar12 = drv_data + 0x10;
                    drv_data[0x11] = uVar13;
                    if ((*puVar12 != 0) && (uVar13 != 0)) {
                      if ((int)uVar14 != 0) {
                        lVar17 = 0;
                        lVar10 = 0;
                        do {
                          *(uint *)(puVar6[0x10] + lVar10) = (uint)*puVar22;
                          *(undefined8 *)(puVar6[0x10] + lVar10 + 8) = 0;
                          puVar1 = puVar22 + 1;
                          puVar22 = puVar22 + 4;
                          *(uint *)(puVar6[0x11] + lVar17) = (uint)*puVar1;
                          lVar3 = puVar6[0x10] + lVar10;
                          lVar10 = lVar10 + 0x18;
                          lVar4 = puVar6[0x11] + lVar17;
                          lVar17 = lVar17 + 0x10;
                          *(long *)(lVar4 + 8) = lVar3;
                        } while (uVar14 * 0x18 != lVar10);
                      }
                      uVar9 = devm_kmalloc(pcVar2,(ulong)uVar21 + 0x3f >> 3 & 0x3ffffff8,0xdc0);
                      puVar12 = drv_data;
                      drv_data[0xc] = uVar9;
                      if (uVar9 != 0) {
                        puVar12[2] = 0;
                        *(int *)((long)puVar12 + 0x54) = (int)uVar14;
                        *(uint *)(puVar12 + 0xb) = uVar21;
                        local_170 = 0;
                        uStack_168 = 0;
                        local_180 = 0;
                        puStack_178 = (ulong *)0x0;
                        local_190 = 0;
                        uStack_188 = 0;
                        local_1a0 = 0;
                        uStack_198 = (char *)0x0;
                        local_1b0 = (char *)0x0;
                        local_1a8 = 0;
                        iVar7 = __of_parse_phandle_with_args
                                          (*(undefined8 *)(param_1 + 0x2f8),"memory-region",0,0,0,
                                           &local_1b0);
                        uVar9 = 0;
                        if ((iVar7 == 0) && (local_1b0 != (char *)0x0)) {
                          uVar14 = qcom_llcc_tcm_init(param_1,0,uVar14,local_1b0,drv_data);
                          uVar9 = uVar14 & 0xffffffff;
                          if ((int)uVar14 != 0) {
                            _dev_err(pcVar2,"Failed to probe TCM manager\n");
                          }
                        }
                        _dev_warn(pcVar2,"llcc slice size not supported and is set to 0\n");
                        devm_iounmap(pcVar2,plVar11);
                        if ((int)uVar9 == 0) goto LAB_00101648;
                        goto LAB_001016c0;
                      }
                      uVar9 = 0xfffffff4;
                    }
                    goto LAB_00101400;
                  }
                  if ((char)plVar11[1] == '\0') {
                    uVar14 = (ulong)*(uint *)(plVar11 + 4);
                    uVar21 = *(uint *)((long)plVar11 + 0x24);
                    puVar22 = (ushort *)(plVar11 + 5);
                    goto LAB_0010192c;
                  }
                  pcVar15 = "Invalid slc_sct_mem version\n";
                }
                _dev_err(pcVar2,pcVar15);
                uVar9 = 0xffffffea;
              }
LAB_00101400:
              devm_iounmap(pcVar2,plVar11);
            }
          }
        }
      }
      else {
        uVar9 = uVar9 & 0xffffffff;
      }
    }
  }
LAB_001016c0:
  drv_data = (ulong *)0xffffffffffffffed;
LAB_001016c8:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_llcc_remove @ 00101ac4 size=20
// signature: undefined qcom_llcc_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_llcc_remove(void)

{
  drv_data = 0xffffffffffffffed;
  return 0;
}



//------------------------------------------------------------
// readl_relaxed @ 00101ad8 size=124
// signature: undefined readl_relaxed(void)
// callers: [qcom_llcc_probe]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x101b20,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// qcom_llcc_cfg_program @ 00101b54 size=1720
// signature: undefined qcom_llcc_cfg_program(void)
// callers: [qcom_llcc_probe]
//------------------------------------------------------------

int qcom_llcc_cfg_program(long param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  ulong uVar6;
  char *pcVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  uint *puVar14;
  uint uVar15;
  long lVar16;
  undefined4 *puVar17;
  undefined8 local_74;
  uint local_6c;
  long local_68;
  
  lVar12 = drv_data;
  lVar16 = sp_el0;
  local_68 = *(long *)(lVar16 + 0x638);
  iVar2 = *(int *)(drv_data + 0x54);
  if (iVar2 != 0) {
    cVar3 = *(char *)(drv_data + 0x78);
    iVar8 = 0;
    lVar16 = *(long *)(drv_data + 0x10);
    do {
      lVar11 = lVar16 + (long)iVar8 * 0x34;
      lVar13 = ((long)iVar8 + (long)iVar8 * 2) * 8;
      iVar8 = iVar8 + 1;
      *(undefined4 *)(*(long *)(lVar12 + 0x80) + lVar13) = *(undefined4 *)(lVar11 + 4);
      *(ulong *)(*(long *)(lVar12 + 0x80) + lVar13 + 8) = (ulong)*(uint *)(lVar11 + 8);
      *(undefined4 *)(*(long *)(lVar12 + 0x80) + lVar13 + 0x10) = 0;
    } while (iVar2 != iVar8);
    if (iVar2 != 0) {
      uVar15 = 0;
      iVar8 = 0;
      local_74 = 0;
      do {
        puVar17 = (undefined4 *)(lVar16 + (long)iVar8 * 0x34);
        uVar9 = 0;
        if (*(uint *)(drv_data + 0x5c) != 0) {
          uVar9 = (uint)(puVar17[2] << 10) / *(uint *)(drv_data + 0x5c);
        }
        puVar14 = puVar17 + 1;
        iVar1 = *puVar14 * 8;
        uVar9 = uVar9 >> 6;
        if (*(int *)(drv_data + 0x74) < 0x29) {
          if (0x1e < *(int *)(drv_data + 0x74)) {
            uVar9 = uVar9 << 0xe;
            goto LAB_00101c9c;
          }
          lVar12 = lVar16 + (long)iVar8 * 0x34;
          uVar9 = uVar9 << 0x10;
          uVar10 = (uint)*(ushort *)(lVar12 + 0x18) | *(int *)(lVar12 + 0x14) << 0x10;
        }
        else {
          uVar9 = uVar9 << 0x10;
LAB_00101c9c:
          lVar12 = lVar16 + (long)iVar8 * 0x34;
          uVar10 = *(uint *)(lVar12 + 0x18);
          local_74 = CONCAT44(*puVar14 * 4 + 0x21100,*(undefined4 *)(lVar12 + 0x14));
        }
        iVar5 = regmap_write(*(undefined8 *)(drv_data + 8),iVar1 + 0x21004,
                             puVar17[7] | puVar17[8] << 2 | (uint)*(byte *)(puVar17 + 4) << 3 |
                             puVar17[3] << 4 | uVar9);
        if ((iVar5 != 0) ||
           (iVar5 = regmap_write(*(undefined8 *)(drv_data + 8),iVar1 + 0x21000,uVar10), iVar5 != 0))
        break;
        iVar1 = *(int *)(drv_data + 0x74);
        if (0x1e < iVar1) {
          iVar5 = regmap_write(*(undefined8 *)(drv_data + 8),local_74._4_4_,local_74 & 0xffffffff);
          if (iVar5 != 0) break;
          iVar1 = *(int *)(drv_data + 0x74);
        }
        if ((0x13 < iVar1) &&
           ((iVar5 = regmap_write(*(undefined8 *)(drv_data + 8),0x21f20), iVar5 != 0 ||
            ((0x14 < *(int *)(drv_data + 0x74) &&
             (iVar5 = regmap_write(*(undefined8 *)(drv_data + 8),0x21f2c), iVar5 != 0)))))) break;
        if (cVar3 != '\0') {
          uVar15 = (uint)*(byte *)(lVar16 + (long)iVar8 * 0x34 + 0x24) << (ulong)(*puVar14 & 0x1f) |
                   uVar15;
          iVar5 = regmap_write(*(undefined8 *)(drv_data + 8),0x21f00,uVar15);
          if ((iVar5 != 0) ||
             ((*(int *)(drv_data + 0x74) < 0x29 &&
              (iVar5 = regmap_write(*(undefined8 *)(drv_data + 8),0x21f04), iVar5 != 0)))) break;
        }
        if (0x28 < *(int *)(drv_data + 0x74)) {
          uVar9 = *puVar14;
          cVar4 = *(char *)(lVar16 + (long)iVar8 * 0x34 + 0x29);
          local_6c = 0;
          regmap_read(*(undefined8 *)(drv_data + 8),0x21f0c,&local_6c);
          uVar10 = (uint)(1L << ((ulong)uVar9 & 0x3f));
          uVar9 = local_6c & (uVar10 ^ 0xffffffff);
          if (cVar4 != '\0') {
            uVar9 = local_6c | uVar10;
          }
          iVar5 = regmap_write(*(undefined8 *)(drv_data + 8),0x21f0c,uVar9);
          if (iVar5 != 0) break;
          uVar9 = *puVar14;
          cVar4 = *(char *)(lVar16 + (long)iVar8 * 0x34 + 0x2a);
          local_6c = 0;
          regmap_read(*(undefined8 *)(drv_data + 8),0x21f10,&local_6c);
          uVar10 = (uint)(1L << ((ulong)uVar9 & 0x3f));
          uVar9 = local_6c & (uVar10 ^ 0xffffffff);
          if (cVar4 != '\0') {
            uVar9 = local_6c | uVar10;
          }
          iVar5 = regmap_write(*(undefined8 *)(drv_data + 8),0x21f10,uVar9);
          if (iVar5 != 0) break;
          uVar9 = *puVar14;
          cVar4 = *(char *)(lVar16 + (long)iVar8 * 0x34 + 0x2b);
          local_6c = 0;
          regmap_read(*(undefined8 *)(drv_data + 8),0x21f14,&local_6c);
          uVar10 = (uint)(1L << ((ulong)uVar9 & 0x3f));
          uVar9 = local_6c & (uVar10 ^ 0xffffffff);
          if (cVar4 != '\0') {
            uVar9 = local_6c | uVar10;
          }
          iVar5 = regmap_write(*(undefined8 *)(drv_data + 8),0x21f14,uVar9);
          if (iVar5 != 0) break;
          uVar9 = *puVar14;
          cVar4 = *(char *)(lVar16 + (long)iVar8 * 0x34 + 0x2c);
          local_6c = 0;
          regmap_read(*(undefined8 *)(drv_data + 8),0x21f18,&local_6c);
          uVar10 = (uint)(1L << ((ulong)uVar9 & 0x3f));
          uVar9 = local_6c & (uVar10 ^ 0xffffffff);
          if (cVar4 != '\0') {
            uVar9 = local_6c | uVar10;
          }
          iVar5 = regmap_write(*(undefined8 *)(drv_data + 8),0x21f18,uVar9);
          if (iVar5 != 0) break;
          uVar9 = *puVar14;
          cVar4 = *(char *)(lVar16 + (long)iVar8 * 0x34 + 0x2d);
          local_6c = 0;
          regmap_read(*(undefined8 *)(drv_data + 8),0x21f1c,&local_6c);
          uVar10 = (uint)(1L << ((ulong)uVar9 & 0x3f));
          uVar9 = local_6c & (uVar10 ^ 0xffffffff);
          if (cVar4 != '\0') {
            uVar9 = local_6c | uVar10;
          }
          iVar5 = regmap_write(*(undefined8 *)(drv_data + 8),0x21f1c,uVar9);
          if (iVar5 != 0) break;
          uVar9 = *puVar14;
          cVar4 = *(char *)(lVar16 + (long)iVar8 * 0x34 + 0x2e);
          local_6c = 0;
          regmap_read(*(undefined8 *)(drv_data + 8),0x21f24,&local_6c);
          uVar10 = (uint)(1L << ((ulong)uVar9 & 0x3f));
          uVar9 = local_6c & (uVar10 ^ 0xffffffff);
          if (cVar4 != '\0') {
            uVar9 = local_6c | uVar10;
          }
          iVar5 = regmap_write(*(undefined8 *)(drv_data + 8),0x21f24,uVar9);
          if (iVar5 != 0) break;
          uVar9 = *puVar14;
          cVar4 = *(char *)(lVar16 + (long)iVar8 * 0x34 + 0x2f);
          local_6c = 0;
          regmap_read(*(undefined8 *)(drv_data + 8),0x21f28,&local_6c);
          uVar10 = (uint)(1L << ((ulong)uVar9 & 0x3f));
          uVar9 = local_6c & (uVar10 ^ 0xffffffff);
          if (cVar4 != '\0') {
            uVar9 = local_6c | uVar10;
          }
          iVar5 = regmap_write(*(undefined8 *)(drv_data + 8),0x21f28,uVar9);
          if (iVar5 != 0) break;
          uVar9 = *puVar14;
          cVar4 = *(char *)(lVar16 + (long)iVar8 * 0x34 + 0x30);
          local_6c = 0;
          regmap_read(*(undefined8 *)(drv_data + 8),0x21f30,&local_6c);
          uVar10 = (uint)(1L << ((ulong)uVar9 & 0x3f));
          uVar9 = local_6c & (uVar10 ^ 0xffffffff);
          if (cVar4 != '\0') {
            uVar9 = local_6c | uVar10;
          }
          iVar5 = regmap_write(*(undefined8 *)(drv_data + 8),0x21f30,uVar9);
          if (iVar5 != 0) break;
        }
        if (*(char *)(lVar16 + (long)iVar8 * 0x34 + 0x26) == '\0') {
          iVar5 = 0;
        }
        else {
          uVar6 = llcc_slice_getd(*puVar17);
          if ((uVar6 < 0xfffffffffffff001) || ((uVar6 & 0xffffffff) == 0)) {
            iVar5 = llcc_slice_activate();
            if (iVar5 == 0) goto LAB_00101c28;
            pcVar7 = "Failed to activate slice=%d\n";
          }
          else {
            iVar5 = 0;
            pcVar7 = "Failed to get slice=%d\n";
          }
          _dev_err(param_1 + 0x10,pcVar7,*puVar14);
        }
LAB_00101c28:
        iVar8 = iVar8 + 1;
      } while (iVar2 != iVar8);
      goto LAB_001021cc;
    }
  }
  iVar5 = 0;
LAB_001021cc:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// qcom_llcc_tcm_init @ 0010220c size=748
// signature: undefined qcom_llcc_tcm_init(void)
// callers: [qcom_llcc_probe]
//------------------------------------------------------------

void qcom_llcc_tcm_init(long param_1,long param_2,ulong param_3,undefined8 param_4,long param_5)

{
  ulong *puVar1;
  char cVar2;
  code *pcVar3;
  long lVar4;
  undefined8 uVar5;
  ulong uVar6;
  undefined *puVar7;
  long *plVar9;
  undefined4 *puVar8;
  ulong uVar10;
  undefined8 local_a8;
  undefined8 uStack_a0;
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
  
  lVar4 = sp_el0;
  param_1 = param_1 + 0x10;
  local_48 = *(long *)(lVar4 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  tcm_drv_data = (long *)devm_kmalloc(param_1,0x50,0xdc0);
  if (tcm_drv_data == (long *)0x0) {
    puVar7 = &DAT_0010302a;
LAB_001023c4:
    _printk(puVar7);
    uVar5 = 0xfffffff4;
  }
  else {
    lVar4 = devm_kmalloc(param_1,0x18,0xdc0);
    plVar9 = tcm_drv_data;
    tcm_drv_data[2] = lVar4;
    if (lVar4 == 0) {
      puVar7 = &DAT_00102d7f;
      goto LAB_001023c4;
    }
    *plVar9 = param_1;
    uVar5 = of_address_to_resource(param_4,0,&local_a8);
    if ((int)uVar5 == 0) {
      *(undefined8 *)tcm_drv_data[2] = local_a8;
      if (*(char *)(param_5 + 0x90) == '\0') {
        uVar10 = llcc_slice_getd(0x1e);
        plVar9 = tcm_drv_data;
        tcm_drv_data[1] = uVar10;
        if ((uVar10 != 0) && (uVar10 < 0xfffffffffffff001)) {
          if (param_3 != 0) {
            uVar6 = 0;
            do {
              if (*(int *)(param_2 + uVar6 * 0x34) == 0x1e) {
                *(undefined1 *)((long)plVar9 + 0x19) =
                     *(undefined1 *)(param_2 + uVar6 * 0x34 + 0x26);
                break;
              }
              uVar6 = (ulong)((int)uVar6 + 1);
            } while (uVar6 < param_3);
          }
          cVar2 = arm64_use_ng_mappings;
          *(long *)(plVar9[2] + 0x10) = *(long *)(uVar10 + 8) << 10;
          uVar5 = 0x68000000000713;
          if (cVar2 != '\0') {
            uVar5 = 0x68000000000f13;
          }
          uVar5 = ioremap_prot(*(undefined8 *)plVar9[2],((undefined8 *)plVar9[2])[2],uVar5);
          plVar9 = tcm_drv_data;
          *(undefined8 *)(tcm_drv_data[2] + 8) = uVar5;
          uVar10 = *(ulong *)(plVar9[2] + 8);
          if ((uVar10 != 0) && (uVar10 < 0xfffffffffffff001)) {
LAB_0010243c:
            __mutex_init(plVar9 + 4,"&tcm_drv_data->lock",&qcom_llcc_tcm_init___key);
            uVar5 = 0;
            goto LAB_00102458;
          }
          if ((*(char *)(param_5 + 0x90) == '\0') && ((plVar9[2] != 0 && (uVar10 != 0)))) {
            iounmap();
            plVar9 = tcm_drv_data;
          }
          puVar8 = (undefined4 *)plVar9[1];
          uVar5 = 0xfffffff4;
          if (((puVar8 != (undefined4 *)0x0) && (puVar8 < (undefined4 *)0xfffffffffffff001)) &&
             (puVar8[4] != 0)) {
            __warn_printk(" Slice %d is still active\n",*puVar8);
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1024d4);
            (*pcVar3)();
          }
          goto LAB_001022b0;
        }
LAB_001024d8:
        puVar7 = &DAT_001031a9;
      }
      else if ((slc_tcm_shmem == (ulong *)0x0) || ((ulong *)0xfffffffffffff000 < slc_tcm_shmem)) {
        puVar7 = &DAT_001030dc;
      }
      else {
        if (*slc_tcm_shmem != 0) {
          uVar10 = 0;
          puVar1 = slc_tcm_shmem;
          do {
            if (*(int *)((long)puVar1 + 0xc) != 0) {
              uVar6 = llcc_slice_getd((int)puVar1[1]);
              plVar9 = tcm_drv_data;
              tcm_drv_data[1] = uVar6;
              if ((uVar6 == 0) || (0xfffffffffffff000 < uVar6)) goto LAB_001024d8;
              *(ulong *)(plVar9[2] + 0x10) = (ulong)(uint)(*(int *)((long)puVar1 + 0xc) << 10);
              *(ulong *)plVar9[2] = puVar1[2];
              if (uVar10 < *slc_tcm_shmem) goto LAB_0010243c;
              break;
            }
            uVar10 = uVar10 + 1;
            puVar1 = puVar1 + 2;
          } while (*slc_tcm_shmem != uVar10);
        }
        puVar7 = &DAT_00102da3;
      }
      _printk(puVar7);
      uVar5 = 0xffffffed;
    }
  }
LAB_001022b0:
  tcm_drv_data = (long *)0xffffffffffffffed;
LAB_00102458:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 0010263c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_llcc_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010266c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_llcc_driver);
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00109000 size=1
// signature: undefined mutex_lock(void)
// callers: [llcc_slice_activate, llcc_tcm_activate, llcc_tcm_deactivate, llcc_slice_getd, llcc_slice_deactivate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00109008 size=1
// signature: undefined mutex_unlock(void)
// callers: [llcc_slice_activate, llcc_tcm_activate, llcc_tcm_deactivate, llcc_slice_getd, llcc_slice_deactivate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ioremap_prot @ 00109018 size=1
// signature: undefined ioremap_prot(void)
// callers: [llcc_tcm_activate, qcom_llcc_tcm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ioremap_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00109020 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [llcc_tcm_activate, qcom_llcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 00109028 size=1
// signature: undefined iounmap(void)
// callers: [llcc_tcm_activate, qcom_llcc_tcm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_by_name @ 00109038 size=1
// signature: undefined of_find_node_by_name(void)
// callers: [llcc_slice_getd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_available @ 00109040 size=1
// signature: undefined of_device_is_available(void)
// callers: [llcc_slice_getd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00109048 size=1
// signature: undefined _printk(void)
// callers: [llcc_slice_getd, qcom_llcc_probe, qcom_llcc_tcm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 00109050 size=1
// signature: undefined __warn_printk(void)
// callers: [llcc_slice_putd, qcom_llcc_tcm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 00109058 size=1
// signature: undefined regmap_write(void)
// callers: [qcom_llcc_cfg_program, llcc_update_act_ctrl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 00109060 size=1
// signature: undefined ktime_get(void)
// callers: [llcc_update_act_ctrl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00109068 size=1
// signature: undefined regmap_read(void)
// callers: [qcom_llcc_cfg_program, llcc_update_act_ctrl, llcc_notif_staling_inc_counter]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00109070 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_llcc_cfg_program, llcc_update_act_ctrl, qcom_llcc_probe, qcom_llcc_tcm_init, llcc_notif_staling_inc_counter]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00109078 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [llcc_staling_conf_capacity, llcc_notif_staling_inc_counter, llcc_staling_conf_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00109080 size=1
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
// platform_driver_unregister @ 00109088 size=1
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
// devm_kmalloc @ 00109090 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_llcc_probe, qcom_llcc_tcm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_platform_ioremap_resource_byname @ 00109098 size=1
// signature: undefined devm_platform_ioremap_resource_byname(void)
// callers: [qcom_llcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_platform_ioremap_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init_mmio_clk @ 001090a0 size=1
// signature: undefined __devm_regmap_init_mmio_clk(void)
// callers: [qcom_llcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init_mmio_clk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_match_string @ 001090a8 size=1
// signature: undefined of_property_match_string(void)
// callers: [qcom_llcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_match_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001090b0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qcom_llcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001090b8 size=1
// signature: undefined __mutex_init(void)
// callers: [qcom_llcc_probe, qcom_llcc_tcm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001090c0 size=1
// signature: undefined of_find_property(void)
// callers: [qcom_llcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 001090c8 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [qcom_llcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 001090d0 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [qcom_llcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_iounmap @ 001090d8 size=1
// signature: undefined devm_iounmap(void)
// callers: [qcom_llcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 001090e0 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [qcom_llcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 001090e8 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [qcom_llcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 001090f0 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qcom_llcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq_optional @ 001090f8 size=1
// signature: undefined platform_get_irq_optional(void)
// callers: [qcom_llcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq_optional(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_register_full @ 00109100 size=1
// signature: undefined platform_device_register_full(void)
// callers: [qcom_llcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_register_full(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_populate @ 00109108 size=1
// signature: undefined of_platform_populate(void)
// callers: [qcom_llcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00109110 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_llcc_cfg_program, qcom_llcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00109118 size=1
// signature: undefined _dev_info(void)
// callers: [qcom_llcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 00109120 size=1
// signature: undefined _dev_warn(void)
// callers: [qcom_llcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00109128 size=1
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
// log_post_read_mmio @ 00109130 size=1
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
// of_address_to_resource @ 00109138 size=1
// signature: undefined of_address_to_resource(void)
// callers: [qcom_llcc_tcm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



