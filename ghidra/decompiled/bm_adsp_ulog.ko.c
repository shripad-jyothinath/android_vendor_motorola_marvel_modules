// Decompiled by Ghidra 12.2
// Program: bm_adsp_ulog.ko
// Image base: 00100000

//------------------------------------------------------------
// bm_ulog_get_log @ 001004e4 size=436
// signature: undefined bm_ulog_get_log(void)
// callers: []
//------------------------------------------------------------

int bm_ulog_get_log(void *param_1,uint param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined8 local_58;
  undefined4 local_50;
  uint uStack_4c;
  long local_48;
  
  lVar2 = g_bmdev;
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  if (g_bmdev == 0) {
    puVar4 = &DAT_001027af;
  }
  else {
    if (*(char **)(g_bmdev + 0x78) != (char *)0x0) {
      if (**(char **)(g_bmdev + 0x78) == '\0') {
        iVar3 = -0x20c;
      }
      else if (param_1 == (void *)0x0) {
        _printk(&DAT_00102b4d,"bm_ulog_get_log",0);
        iVar3 = -0x16;
      }
      else if (param_2 - 0x2001 < 0xffffe000) {
        _printk(&DAT_00102547,"bm_ulog_get_log",(ulong)param_2);
        iVar3 = -0x16;
      }
      else {
        lVar1 = g_bmdev + 0x10;
        local_58 = 0x10000800a;
        local_50 = 0x18;
        uStack_4c = param_2;
        mutex_lock(lVar1);
        *(undefined4 *)(lVar2 + 0x40) = 0;
        iVar3 = pmic_glink_write(*(undefined8 *)(lVar2 + 8),&local_58,0x10);
        if (iVar3 == 0) {
          iVar3 = wait_for_completion_timeout((undefined4 *)(lVar2 + 0x40),0x4e2);
          if (iVar3 != 0) {
            mutex_unlock(lVar1);
            memcpy(param_1,(void *)(lVar2 + 0x90),(ulong)param_2);
            iVar3 = 0;
            goto LAB_00100660;
          }
          _printk(&DAT_00102acd,"bm_ulog_write");
          iVar3 = -0x6e;
        }
        mutex_unlock(lVar1);
        _printk(&DAT_00102c1e,"bm_ulog_get_log",iVar3);
      }
      goto LAB_00100660;
    }
    puVar4 = &DAT_00102a24;
  }
  _printk(puVar4,"bm_ulog_get_log");
  iVar3 = -0x13;
LAB_00100660:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// bm_ulog_get_mask_log @ 0010069c size=472
// signature: undefined bm_ulog_get_mask_log(void)
// callers: []
//------------------------------------------------------------

int bm_ulog_get_mask_log(undefined8 param_1,undefined4 param_2,void *param_3,uint param_4)

{
  long lVar1;
  long lVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined *puVar5;
  undefined8 local_58;
  undefined4 local_50;
  uint uStack_4c;
  long local_48;
  
  lVar2 = g_bmdev;
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  if (g_bmdev == 0) {
    puVar4 = &DAT_001027af;
  }
  else {
    if (*(char **)(g_bmdev + 0x78) != (char *)0x0) {
      if (**(char **)(g_bmdev + 0x78) == '\0') {
        iVar3 = -0x20c;
      }
      else if (param_3 == (void *)0x0) {
        _printk(&DAT_00102b4d,"bm_ulog_get_mask_log",0);
        iVar3 = -0x16;
      }
      else if (param_4 - 0x2001 < 0xffffe000) {
        _printk(&DAT_00102547,"bm_ulog_get_mask_log",param_4);
        iVar3 = -0x16;
      }
      else {
        iVar3 = bm_ulog_set_mask(g_bmdev,param_1,param_2);
        if (iVar3 == 0) {
          lVar1 = lVar2 + 0x10;
          local_58 = 0x10000800a;
          local_50 = 0x18;
          uStack_4c = param_4;
          mutex_lock(lVar1);
          *(undefined4 *)(lVar2 + 0x40) = 0;
          iVar3 = pmic_glink_write(*(undefined8 *)(lVar2 + 8),&local_58,0x10);
          if (iVar3 == 0) {
            iVar3 = wait_for_completion_timeout((undefined4 *)(lVar2 + 0x40),0x4e2);
            if (iVar3 != 0) {
              mutex_unlock(lVar1);
              memcpy(param_3,(void *)(lVar2 + 0x90),(ulong)param_4);
              iVar3 = 0;
              goto LAB_0010083c;
            }
            _printk(&DAT_00102acd,"bm_ulog_write");
            iVar3 = -0x6e;
          }
          mutex_unlock(lVar1);
          puVar5 = &DAT_00102c1e;
        }
        else {
          puVar5 = &DAT_001029c3;
        }
        _printk(puVar5,"bm_ulog_get_mask_log",iVar3);
      }
      goto LAB_0010083c;
    }
    puVar4 = &DAT_00102a24;
  }
  _printk(puVar4,"bm_ulog_get_mask_log");
  iVar3 = -0x13;
LAB_0010083c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// bm_ulog_set_mask @ 00100874 size=284
// signature: undefined bm_ulog_set_mask(void)
// callers: [bm_ulog_dump_show, bm_ulog_probe, bm_ulog_get_mask_log, bm_ulog_print_mask_log]
//------------------------------------------------------------

int bm_ulog_set_mask(long param_1,undefined8 param_2,uint param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  ulong local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  lVar1 = param_1 + 0x10;
  if (4 < param_3) {
    param_3 = 5;
  }
  local_68 = 0x10000800a;
  local_60 = 0x19;
  local_50 = (ulong)param_3;
  local_58 = param_2;
  mutex_lock(lVar1);
  *(undefined4 *)(param_1 + 0x40) = 0;
  iVar2 = pmic_glink_write(*(undefined8 *)(param_1 + 8),&local_68,0x20);
  if (iVar2 == 0) {
    iVar2 = wait_for_completion_timeout((undefined4 *)(param_1 + 0x40),0x4e2);
    if (iVar2 != 0) {
      mutex_unlock(lVar1);
      iVar2 = 0;
      *(uint *)(param_1 + 0x60) = param_3;
      *(undefined8 *)(param_1 + 0x68) = param_2;
      goto LAB_00100918;
    }
    _printk(&DAT_00102acd,"bm_ulog_write");
    iVar2 = -0x6e;
  }
  mutex_unlock(lVar1);
  _printk(&DAT_00102850,"bm_ulog_set_mask");
LAB_00100918:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// bm_ulog_print_log @ 00100994 size=392
// signature: undefined bm_ulog_print_log(void)
// callers: [bm_ulog_probe]
//------------------------------------------------------------

int bm_ulog_print_log(int param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined8 local_58;
  undefined4 local_50;
  int iStack_4c;
  long local_48;
  
  lVar2 = g_bmdev;
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  if (g_bmdev == 0) {
    puVar4 = &DAT_001027af;
  }
  else {
    if (*(char **)(g_bmdev + 0x78) != (char *)0x0) {
      if (**(char **)(g_bmdev + 0x78) == '\0') {
        iVar3 = -0x20c;
      }
      else if (param_1 - 0x2001U < 0xffffe000) {
        _printk(&DAT_00102547,"bm_ulog_print_log",param_1);
        iVar3 = -0x16;
      }
      else {
        lVar1 = g_bmdev + 0x10;
        local_58 = 0x10000800a;
        local_50 = 0x18;
        iStack_4c = param_1;
        mutex_lock(lVar1);
        *(undefined4 *)(lVar2 + 0x40) = 0;
        iVar3 = pmic_glink_write(*(undefined8 *)(lVar2 + 8),&local_58,0x10);
        if (iVar3 == 0) {
          iVar3 = wait_for_completion_timeout((undefined4 *)(lVar2 + 0x40),0x4e2);
          if (iVar3 != 0) {
            mutex_unlock(lVar1);
            bm_ulog_print_buffer(lVar2,param_1);
            iVar3 = 0;
            goto LAB_00100ae4;
          }
          _printk(&DAT_00102acd,"bm_ulog_write");
          iVar3 = -0x6e;
        }
        mutex_unlock(lVar1);
        _printk(&DAT_00102c1e,"bm_ulog_print_log",iVar3);
      }
      goto LAB_00100ae4;
    }
    puVar4 = &DAT_00102a24;
  }
  _printk(puVar4,"bm_ulog_print_log");
  iVar3 = -0x13;
LAB_00100ae4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// bm_ulog_print_buffer @ 00100b1c size=764
// signature: undefined bm_ulog_print_buffer(void)
// callers: [bm_ulog_kthread, bm_ulog_probe, bm_ulog_print_log, bm_ulog_print_mask_log]
//------------------------------------------------------------

void bm_ulog_print_buffer(long param_1,uint param_2)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  int iVar7;
  int iVar8;
  ulong uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  ulong uVar13;
  int iVar14;
  undefined4 uVar15;
  ulong uVar16;
  ulong local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined2 local_70;
  undefined1 local_6e;
  long local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  local_88 = 0;
  local_80 = 0;
  local_70 = 0;
  local_78 = 0;
  if (param_1 == 0) {
    _printk(&DAT_001027af,"bm_ulog_print_buffer");
    uVar15 = 0xffffffed;
  }
  else {
    uVar6 = (ulong)param_2;
    if (param_2 == 0) {
      uVar15 = 0;
    }
    else {
      uVar16 = 0;
      uVar12 = 0;
      iVar7 = 0;
      uVar9 = 0;
      uVar11 = 0;
      iVar10 = 0;
      iVar8 = 0;
      do {
        cVar1 = *(char *)(param_1 + 0x90 + uVar16);
        iVar14 = (int)uVar16;
        if (cVar1 == '\0') {
          uVar6 = uVar16 & 0xffffffff;
joined_r0x00100bbc:
          if ((int)uVar12 < iVar14) {
            if ((int)(iVar14 - uVar12) < 0x12) {
              if (0 < (int)(iVar14 - uVar12)) {
                iVar7 = iVar7 + 1;
                uVar12 = iVar14 + 1;
              }
            }
            else {
              lVar5 = param_1 + (ulong)uVar12;
              local_6e = 0;
              local_80 = *(undefined8 *)(lVar5 + 0x90);
              local_78 = *(undefined8 *)(lVar5 + 0x98);
              local_70 = *(undefined2 *)(lVar5 + 0xa0);
              iVar3 = kstrtoull(&local_80,0,&local_88);
              if (iVar3 == 0) {
                uVar13 = local_88 / 19200000;
                uVar9 = (local_88 * 1000) / 19200000;
                iVar8 = (int)uVar9 + (int)(uVar9 / 1000) * -1000;
                uVar11 = (uint)(((int)uVar13 + (int)(uVar13 / 0xe10) * -0xe10) * 0x889) >> 0x11;
                iVar10 = (int)uVar13 + (int)(uVar13 / 0x3c) * -0x3c;
                uVar9 = local_88 / 0x1017df8000;
                local_88 = uVar13;
              }
              if (*(char *)(param_1 + 0x2091) == '\0') {
                if ((*(char **)(param_1 + 0x78) == (char *)0x0) ||
                   (**(char **)(param_1 + 0x78) == '\0')) {
                  uVar13 = (ulong)(uVar12 + 0x12);
                  if (0x2000 < uVar12 + 0x12) goto LAB_00100e10;
                }
                else {
                  uVar13 = (ulong)(uVar12 + 0x12);
                  if (0x2000 < uVar12 + 0x12) {
LAB_00100e10:
                    /* WARNING: Does not return */
                    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x100e14);
                    (*pcVar2)();
                  }
                  _printk(&DAT_001023a8,uVar9,uVar11,iVar10,iVar8,param_1 + uVar13 + 0x90);
                }
                uVar4 = *(undefined8 *)(param_1 + 0x80);
                lVar5 = param_1 + uVar13 + 0x90;
              }
              else {
                if (0x2000 < uVar12 + 0x12) goto LAB_00100e10;
                lVar5 = param_1 + (ulong)(uVar12 + 0x12) + 0x90;
                _printk(&DAT_001023a8,uVar9,uVar11,iVar10,iVar8,lVar5);
                uVar4 = *(undefined8 *)(param_1 + 0x80);
              }
              ipc_log_string(uVar4,"[%02d:%02d:%02d.%03d]%s\n",uVar9,uVar11,iVar10,iVar8,lVar5);
              uVar12 = iVar14 + 1;
              iVar7 = iVar7 + 1;
            }
          }
        }
        else if (cVar1 == '\n') {
          *(undefined1 *)(param_1 + 0x90 + uVar16) = 0;
          goto joined_r0x00100bbc;
        }
        uVar16 = uVar16 + 1;
      } while ((uVar16 < uVar6) && (uVar12 < (uint)uVar6));
      uVar15 = (undefined4)uVar16;
      if (iVar7 < 1) {
        uVar15 = 0;
      }
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar15);
  }
  return;
}



//------------------------------------------------------------
// bm_ulog_print_mask_log @ 00100e1c size=428
// signature: undefined bm_ulog_print_mask_log(void)
// callers: []
//------------------------------------------------------------

int bm_ulog_print_mask_log(undefined8 param_1,undefined4 param_2,int param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined *puVar5;
  undefined8 local_58;
  undefined4 local_50;
  int iStack_4c;
  long local_48;
  
  lVar2 = g_bmdev;
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  if (g_bmdev == 0) {
    puVar4 = &DAT_001027af;
  }
  else {
    if (*(char **)(g_bmdev + 0x78) != (char *)0x0) {
      if (**(char **)(g_bmdev + 0x78) == '\0') {
        iVar3 = -0x20c;
      }
      else if (param_3 - 0x2001U < 0xffffe000) {
        _printk(&DAT_00102547,"bm_ulog_print_mask_log",param_3);
        iVar3 = -0x16;
      }
      else {
        iVar3 = bm_ulog_set_mask(g_bmdev,param_1,param_2);
        if (iVar3 == 0) {
          lVar1 = lVar2 + 0x10;
          local_58 = 0x10000800a;
          local_50 = 0x18;
          iStack_4c = param_3;
          mutex_lock(lVar1);
          *(undefined4 *)(lVar2 + 0x40) = 0;
          iVar3 = pmic_glink_write(*(undefined8 *)(lVar2 + 8),&local_58,0x10);
          if (iVar3 == 0) {
            iVar3 = wait_for_completion_timeout((undefined4 *)(lVar2 + 0x40),0x4e2);
            if (iVar3 != 0) {
              mutex_unlock(lVar1);
              bm_ulog_print_buffer(lVar2,param_3);
              iVar3 = 0;
              goto LAB_00100f90;
            }
            _printk(&DAT_00102acd,"bm_ulog_write");
            iVar3 = -0x6e;
          }
          mutex_unlock(lVar1);
          puVar5 = &DAT_00102c1e;
        }
        else {
          puVar5 = &DAT_001029c3;
        }
        _printk(puVar5,"bm_ulog_print_mask_log",iVar3);
      }
      goto LAB_00100f90;
    }
    puVar4 = &DAT_00102a24;
  }
  _printk(puVar4,"bm_ulog_print_mask_log");
  iVar3 = -0x13;
LAB_00100f90:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// bm_ulog_enable_log @ 00100fcc size=336
// signature: undefined bm_ulog_enable_log(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 bm_ulog_enable_log(byte param_1,int param_2)

{
  char *pcVar1;
  ulong *puVar2;
  ulong uVar3;
  undefined8 uVar4;
  ulong uVar5;
  
  puVar2 = g_bmdev;
  if ((((g_bmdev == (ulong *)0x0) || ((ulong *)0xfffffffffffff000 < g_bmdev)) ||
      (uVar3 = *g_bmdev, uVar3 == 0)) ||
     (((0xfffffffffffff000 < uVar3 || (uVar5 = g_bmdev[0x11], uVar5 == 0)) ||
      ((0xfffffffffffff000 < uVar5 || ((char)g_bmdev[0x424] == '\0')))))) {
    _printk(&DAT_001027af,"bm_ulog_enable_log");
    uVar4 = 0xffffffed;
  }
  else {
    if ((char)g_bmdev[0x412] == '\0') {
      if (*(byte *)((long)g_bmdev + 0x2091) != (param_1 & 1)) {
        *(byte *)((long)g_bmdev + 0x2091) = param_1 & 1;
        wake_up_process(uVar5);
        pcVar1 = "enabled";
        if ((param_1 & 1) == 0) {
          pcVar1 = "disabled";
        }
        _printk(&DAT_0010269d,"bm_ulog_enable_log",pcVar1);
        uVar3 = *puVar2;
      }
      pm_relax(uVar3);
      cancel_delayed_work(puVar2 + 0x413);
      if (param_2 == 0) {
        return 0;
      }
      if ((param_1 & 1) == 0) {
        return 0;
      }
      _printk(&DAT_00102a52,"bm_ulog_enable_log",param_2);
      pm_stay_awake(*puVar2);
      uVar4 = __msecs_to_jiffies(param_2);
      queue_delayed_work_on(0x20,_system_wq,puVar2 + 0x413,uVar4);
    }
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// bm_ulog_is_enabled_by_cmd @ 00101120 size=404
// signature: undefined bm_ulog_is_enabled_by_cmd(void)
// callers: []
//------------------------------------------------------------

bool bm_ulog_is_enabled_by_cmd(void)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  char *pcVar5;
  char *local_40;
  long local_38;
  
  lVar1 = g_bmdev;
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_40 = (char *)0x0;
  if (g_bmdev == 0) {
    _printk(&DAT_001027af,"bm_ulog_is_enabled_by_cmd");
    bVar2 = false;
  }
  else if ((*(char **)(g_bmdev + 0x78) == (char *)0x0) || (**(char **)(g_bmdev + 0x78) == '\0')) {
    if ((int)bm_ulog_is_enabled_by_cmd_bm_ulog_en_rt < 0) {
      lVar4 = of_find_node_opts_by_path("/chosen",0);
      if (lVar4 == 0) {
        _printk(&DAT_00102391);
        ipc_log_string(*(undefined8 *)(lVar1 + 0x80),"np is null\n");
        bVar2 = false;
      }
      else {
        iVar3 = of_property_read_string(lVar4,"bootargs",&local_40);
        if (iVar3 == 0) {
          pcVar5 = strstr(local_40,"bm_ulog_enabled=1");
          bVar2 = pcVar5 != (char *)0x0;
          bm_ulog_is_enabled_by_cmd_bm_ulog_en_rt = (uint)bVar2;
          _printk(&DAT_00102bb7,pcVar5,bVar2);
          ipc_log_string(*(undefined8 *)(lVar1 + 0x80),
                         "of_property_read_string bm_ulog_enabled=%s bm_ulog_en_rt=%d\n",pcVar5,
                         bm_ulog_is_enabled_by_cmd_bm_ulog_en_rt);
        }
        else {
          bVar2 = false;
        }
        _printk(&DAT_00102c96,bVar2);
        ipc_log_string(*(undefined8 *)(lVar1 + 0x80),"bm ulog rt = %d\n",bVar2);
      }
    }
    else {
      bVar2 = bm_ulog_is_enabled_by_cmd_bm_ulog_en_rt != 0;
    }
  }
  else {
    _printk(&DAT_00102a78);
    ipc_log_string(*(undefined8 *)(lVar1 + 0x80),"bmdev->bm_ulog_enabled is true\n");
    bVar2 = true;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar2;
}



//------------------------------------------------------------
// bm_ulog_is_bm_ulog_enabled @ 001012b8 size=328
// signature: undefined bm_ulog_is_bm_ulog_enabled(void)
// callers: [bm_ulog_probe]
//------------------------------------------------------------

bool bm_ulog_is_bm_ulog_enabled(long param_1)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  char *local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  lVar3 = of_find_node_opts_by_path("/chosen",0);
  local_30 = (char *)0x0;
  if (((param_1 == 0) || (*(char **)(param_1 + 0x78) == (char *)0x0)) ||
     (**(char **)(param_1 + 0x78) == '\0')) {
    if (lVar3 == 0) {
      _printk(&DAT_00102391);
      ipc_log_string(*(undefined8 *)(param_1 + 0x80),"np is null\n");
      bVar1 = false;
    }
    else {
      iVar2 = of_property_read_string(lVar3,"bootargs",&local_30);
      if (iVar2 == 0) {
        pcVar4 = strstr(local_30,"bm_ulog_enabled=1");
        _printk(&DAT_00102811,pcVar4);
        ipc_log_string(*(undefined8 *)(param_1 + 0x80),
                       "of_property_read_string bm_ulog_enabled=%s\n",pcVar4);
        bVar1 = pcVar4 != (char *)0x0;
      }
      else {
        bVar1 = false;
      }
      _printk(&DAT_00102c96,bVar1);
      ipc_log_string(*(undefined8 *)(param_1 + 0x80),"bm ulog rt = %d\n",bVar1);
    }
  }
  else {
    _printk(&DAT_00102a78);
    ipc_log_string(*(undefined8 *)(param_1 + 0x80),"bmdev->bm_ulog_enabled is true\n");
    bVar1 = true;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar1;
}



//------------------------------------------------------------
// bm_ulog_probe @ 00101404 size=1276
// signature: undefined bm_ulog_probe(void)
// callers: []
//------------------------------------------------------------

ulong bm_ulog_probe(long param_1)

{
  long *plVar1;
  long *plVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  long *plVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  undefined1 *puVar10;
  ulong uVar11;
  undefined8 uVar12;
  char *local_a0;
  undefined8 local_98;
  long *local_90;
  code *local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar7 = sp_el0;
  lVar9 = param_1 + 0x10;
  local_68 = *(long *)(lVar7 + 0x638);
  uVar12 = *(undefined8 *)(param_1 + 0x2f8);
  local_88 = (code *)0x0;
  uStack_80 = 0;
  local_98 = 0;
  local_90 = (long *)0x0;
  plVar6 = (long *)devm_kmalloc(lVar9,0x2128,0xdc0);
  if (plVar6 == (long *)0x0) {
    uVar11 = 0xfffffff4;
  }
  else {
    iVar4 = of_property_read_u64(uVar12,"categories",plVar6 + 0xd);
    if (iVar4 != 0) {
      plVar6[0xd] = 0x1fffbfffff;
    }
    iVar4 = of_property_read_variable_u32_array(uVar12,"level",plVar6 + 0xc,1,0);
    if (iVar4 < 0) {
      *(undefined4 *)(plVar6 + 0xc) = 3;
    }
    lVar7 = of_find_property(uVar12,"init-log-enabled",0);
    lVar8 = of_find_property(uVar12,"disable-dynamic-open-log",0);
    *(bool *)(plVar6 + 0x412) = lVar8 != 0;
    _printk(&DAT_00102488);
    ipc_log_string(plVar6[0x10],"disable_dynamic_open_ulog=%d\n",(char)plVar6[0x412]);
    *plVar6 = lVar9;
    local_a0 = "battery_manager_adsp_ulog";
    local_98 = CONCAT44(local_98._4_4_,0x800a);
    local_88 = bm_ulog_callback;
    local_90 = plVar6;
    uVar11 = pmic_glink_register_client(lVar9,&local_a0);
    plVar6[1] = uVar11;
    if (uVar11 < 0xfffffffffffff001) {
      __mutex_init(plVar6 + 2,"&bmdev->lock",&bm_ulog_probe___key);
      *(undefined4 *)(plVar6 + 8) = 0;
      __init_swait_queue_head(plVar6 + 9,"&x->wait",&init_completion___key);
      *(long **)(param_1 + 0xa8) = plVar6;
      plVar6[0xf] = (long)&debug_enabled;
      g_bmdev = plVar6;
      lVar9 = ipc_log_context_create(0x32,"bm_ulog",0);
      plVar6[0x10] = lVar9;
      if (lVar9 == 0) {
        _dev_err(*plVar6,"Failed to create ipc log\n");
      }
      bVar3 = debug_enabled;
      if (lVar7 != 0) {
        debug_enabled = lVar7 != 0;
        bm_ulog_set_mask(plVar6,plVar6[0xd],(int)plVar6[0xc]);
        iVar4 = 0;
        do {
          plVar2 = g_bmdev;
          if (g_bmdev == (long *)0x0) {
            puVar10 = &DAT_001027af;
LAB_00101674:
            _printk(puVar10,"bm_ulog_print_init_log");
          }
          else {
            if (g_bmdev[0xf] == 0) {
              puVar10 = &DAT_00102a24;
              goto LAB_00101674;
            }
            plVar1 = g_bmdev + 2;
            local_78 = 0x10000800a;
            local_70 = 0x200000000023;
            mutex_lock(plVar1);
            *(undefined4 *)(plVar2 + 8) = 0;
            iVar5 = pmic_glink_write(plVar2[1],&local_78,0x10);
            if (iVar5 == 0) {
              iVar5 = wait_for_completion_timeout(plVar2 + 8,0x4e2);
              if (iVar5 == 0) {
                _printk(&DAT_00102acd,"bm_ulog_write");
                iVar5 = -0x6e;
                goto LAB_00101740;
              }
              mutex_unlock(plVar1);
              bm_ulog_print_buffer(plVar2,0x2000);
            }
            else {
LAB_00101740:
              mutex_unlock(plVar1);
              _printk(&DAT_00102c1e,"bm_ulog_print_init_log",iVar5);
            }
          }
          bm_ulog_print_log(0x2000);
          _printk(&DAT_0010292f,iVar4);
          ipc_log_string(plVar6[0x10],"ulog_retry_cnt = %d\n",iVar4);
          iVar4 = iVar4 + 1;
        } while (iVar4 != 3);
      }
      debug_enabled = bVar3;
      bVar3 = bm_ulog_is_bm_ulog_enabled(plVar6);
      debug_enabled = bVar3 & 1;
      _printk(&DAT_00102889);
      ipc_log_string(plVar6[0x10],"bm_ulog_check_debug_enabled debug_enabled=%d\n",debug_enabled);
      uVar11 = kthread_create_on_node(bm_ulog_kthread,plVar6,0xffffffff,"bm_ulog_kthread");
      plVar6[0x11] = uVar11;
      if ((uVar11 == 0) || (0xfffffffffffff000 < uVar11)) {
        plVar6[0x11] = 0;
        _printk(&DAT_001023cc,0);
        ipc_log_string(plVar6[0x10],"Failed to create bm_ulog_task ret = %ld\n",plVar6[0x11]);
      }
      else {
        lVar9 = *plVar6;
        device_set_wakeup_capable(lVar9,1);
        device_wakeup_enable(lVar9);
        wake_up_process(plVar6[0x11]);
        _printk(&DAT_00102400);
        ipc_log_string(plVar6[0x10],"Successed to create bm_ulog_task\n");
        plVar6[0x413] = 0xfffffffe0;
        plVar6[0x414] = (long)(plVar6 + 0x414);
        plVar6[0x415] = (long)(plVar6 + 0x414);
        plVar6[0x416] = (long)bm_ulog_complete_work;
        init_timer_key(plVar6 + 0x419,&delayed_work_timer_fn,0x200000,0,0);
        *(undefined1 *)(plVar6 + 0x424) = 1;
      }
      bm_ulog_add_debugfs(plVar6);
      _printk(&DAT_00102770);
      ipc_log_string(plVar6[0x10],"BM adsp ulog driver initialized successfully\n");
      uVar11 = 0;
    }
    else if ((int)uVar11 == -0x205) {
      uVar11 = 0xfffffdfb;
    }
    else {
      _dev_err(*plVar6,"Error in registering with pmic_glink %d\n",uVar11 & 0xffffffff);
    }
  }
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11 & 0xffffffff;
}



//------------------------------------------------------------
// bm_ulog_remove @ 00101904 size=144
// signature: undefined bm_ulog_remove(void)
// callers: []
//------------------------------------------------------------

int bm_ulog_remove(long param_1)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_1 + 0xa8);
  if (puVar2[0x11] != 0) {
    kthread_stop();
    cancel_delayed_work(puVar2 + 0x413);
    pm_relax(*puVar2);
  }
  ipc_log_context_destroy(puVar2[0x10]);
  debugfs_remove(puVar2[0xe]);
  iVar1 = pmic_glink_unregister_client(puVar2[1]);
  if (iVar1 < 0) {
    _printk(&DAT_00102b12,"bm_ulog_remove",iVar1);
  }
  else {
    iVar1 = 0;
    g_bmdev = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// bm_ulog_callback @ 00101998 size=156
// signature: undefined bm_ulog_callback(void)
// callers: []
//------------------------------------------------------------

undefined8 bm_ulog_callback(long param_1,long param_2,long param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 8);
  if ((iVar1 == 0x18) || (iVar1 == 0x23)) {
    if (param_3 != 0x200c) {
      _printk(&DAT_001026da,"bm_ulog_callback");
      return 0;
    }
    memcpy((void *)(param_1 + 0x90),(void *)(param_2 + 0xc),0x2000);
  }
  else if (iVar1 != 0x19) {
    _printk(&DAT_00102c53,"bm_ulog_callback",iVar1);
    return 0;
  }
  complete(param_1 + 0x40);
  return 0;
}



//------------------------------------------------------------
// bm_ulog_kthread @ 00101a38 size=388
// signature: undefined bm_ulog_kthread(void)
// callers: []
//------------------------------------------------------------

undefined8 bm_ulog_kthread(long param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined4 uVar4;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  _printk(&DAT_00102a02);
  ipc_log_string(*(undefined8 *)(param_1 + 0x80),"bm ulog kthread start\n");
  do {
    if ((*(char *)(param_1 + 0x2091) == '\0') &&
       ((*(char **)(param_1 + 0x78) == (char *)0x0 || (**(char **)(param_1 + 0x78) == '\0')))) {
      uVar4 = 1000;
    }
    else {
      local_78 = 0x10000800a;
      uStack_70 = 0x200000000018;
      mutex_lock(param_1 + 0x10);
      *(undefined4 *)(param_1 + 0x40) = 0;
      iVar2 = pmic_glink_write(*(undefined8 *)(param_1 + 8),&local_78,0x10);
      if ((iVar2 == 0) && (iVar2 = wait_for_completion_timeout(param_1 + 0x40,0x4e2), iVar2 == 0)) {
        _printk(&DAT_00102acd,"bm_ulog_write");
      }
      mutex_unlock(param_1 + 0x10);
      iVar2 = bm_ulog_print_buffer(param_1,0x2000);
      if (iVar2 < 0x401) {
        uVar4 = 100;
        if (iVar2 < 0x81) {
          uVar4 = 200;
        }
      }
      else {
        uVar4 = 0x32;
      }
    }
    msleep(uVar4);
    uVar3 = kthread_should_stop();
  } while ((uVar3 & 1) == 0);
  _printk(&DAT_00102c75);
  ipc_log_string(*(undefined8 *)(param_1 + 0x80),"bm ulog kthread exit\n");
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// bm_ulog_complete_work @ 00101bc0 size=132
// signature: undefined bm_ulog_complete_work(void)
// callers: []
//------------------------------------------------------------

void bm_ulog_complete_work(long param_1)

{
  if ((undefined8 *)(param_1 + -0x2098) == (undefined8 *)0x0) {
    _printk(&DAT_00102443,"bm_ulog_complete_work");
  }
  else {
    if (*(char *)(param_1 + -7) != '\0') {
      _printk(&DAT_0010260c,"bm_ulog_complete_work");
      *(undefined1 *)(param_1 + -7) = 0;
      if (*(long *)(param_1 + -0x2010) != 0) {
        wake_up_process();
      }
    }
    pm_relax(*(undefined8 *)(param_1 + -0x2098));
  }
  return;
}



//------------------------------------------------------------
// bm_ulog_add_debugfs @ 00101c44 size=220
// signature: undefined bm_ulog_add_debugfs(void)
// callers: [bm_ulog_probe]
//------------------------------------------------------------

void bm_ulog_add_debugfs(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = debugfs_create_dir("bm_ulog",0);
  if (uVar1 < 0xfffffffffffff001) {
    uVar2 = debugfs_create_file(&DAT_00102698,0x124,uVar1,param_1,bm_ulog_fops);
    if (uVar2 < 0xfffffffffffff001) {
      debugfs_create_x64("categories",0x1b4,uVar1,param_1 + 0x68);
      debugfs_create_x32("level",0x1b4,uVar1,param_1 + 0x60);
      *(ulong *)(param_1 + 0x70) = uVar1;
    }
    else {
      _printk(&DAT_0010297b,"bm_ulog_add_debugfs",uVar2);
      debugfs_remove(uVar1);
    }
  }
  else {
    _printk(&DAT_001028d3,"bm_ulog_add_debugfs",uVar1 & 0xffffffff);
  }
  return;
}



//------------------------------------------------------------
// bm_ulog_open @ 00101d24 size=48
// signature: undefined bm_ulog_open(void)
// callers: []
//------------------------------------------------------------

void bm_ulog_open(long param_1,undefined8 param_2)

{
  single_open(param_2,bm_ulog_dump_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// bm_ulog_dump_show @ 00101d58 size=308
// signature: undefined bm_ulog_dump_show(void)
// callers: []
//------------------------------------------------------------

int bm_ulog_dump_show(long param_1)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  long lVar4;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x80);
  iVar2 = bm_ulog_set_mask(lVar4,*(undefined8 *)(lVar4 + 0x68),*(undefined4 *)(lVar4 + 0x60));
  if (iVar2 == 0) {
    lVar1 = lVar4 + 0x10;
    local_58 = 0x10000800a;
    uStack_50 = 0x200000000018;
    mutex_lock(lVar1);
    *(undefined4 *)(lVar4 + 0x40) = 0;
    iVar2 = pmic_glink_write(*(undefined8 *)(lVar4 + 8),&local_58,0x10);
    if (iVar2 == 0) {
      iVar2 = wait_for_completion_timeout((undefined4 *)(lVar4 + 0x40),0x4e2);
      if (iVar2 != 0) {
        mutex_unlock(lVar1);
        seq_puts(param_1,lVar4 + 0x90);
        iVar2 = 0;
        goto LAB_00101e00;
      }
      _printk(&DAT_00102acd,"bm_ulog_write");
      iVar2 = -0x6e;
    }
    mutex_unlock(lVar1);
    puVar3 = &DAT_00102c1e;
  }
  else {
    puVar3 = &DAT_001029c3;
  }
  _printk(puVar3,"bm_ulog_dump_show",iVar2);
LAB_00101e00:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// init_module @ 00101f0c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&bm_ulog_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101f3c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&bm_ulog_driver);
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00105000 size=1
// signature: undefined mutex_lock(void)
// callers: [bm_ulog_kthread, bm_ulog_dump_show, bm_ulog_get_log, bm_ulog_probe, bm_ulog_set_mask, bm_ulog_get_mask_log, bm_ulog_print_log, bm_ulog_print_mask_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_write @ 00105008 size=1
// signature: undefined pmic_glink_write(void)
// callers: [bm_ulog_kthread, bm_ulog_dump_show, bm_ulog_get_log, bm_ulog_probe, bm_ulog_set_mask, bm_ulog_get_mask_log, bm_ulog_print_log, bm_ulog_print_mask_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00105010 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [bm_ulog_kthread, bm_ulog_dump_show, bm_ulog_get_log, bm_ulog_probe, bm_ulog_set_mask, bm_ulog_get_mask_log, bm_ulog_print_log, bm_ulog_print_mask_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00105018 size=1
// signature: undefined mutex_unlock(void)
// callers: [bm_ulog_kthread, bm_ulog_dump_show, bm_ulog_get_log, bm_ulog_probe, bm_ulog_set_mask, bm_ulog_get_mask_log, bm_ulog_print_log, bm_ulog_print_mask_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00105020 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [bm_ulog_get_log, bm_ulog_callback, bm_ulog_get_mask_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00105028 size=1
// signature: undefined _printk(void)
// callers: [bm_ulog_kthread, bm_ulog_dump_show, bm_ulog_get_log, bm_ulog_callback, bm_ulog_set_mask, bm_ulog_complete_work, bm_ulog_is_enabled_by_cmd, bm_ulog_print_mask_log, bm_ulog_print_buffer, bm_ulog_is_bm_ulog_enabled, bm_ulog_probe, bm_ulog_add_debugfs, bm_ulog_get_mask_log, bm_ulog_remove, bm_ulog_enable_log, bm_ulog_print_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105030 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [bm_ulog_print_buffer, bm_ulog_kthread, bm_ulog_dump_show, bm_ulog_is_bm_ulog_enabled, bm_ulog_get_log, bm_ulog_probe, bm_ulog_set_mask, bm_ulog_get_mask_log, bm_ulog_is_enabled_by_cmd, bm_ulog_print_log, bm_ulog_print_mask_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 00105038 size=1
// signature: undefined kstrtoull(void)
// callers: [bm_ulog_print_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00105040 size=1
// signature: undefined ipc_log_string(void)
// callers: [bm_ulog_print_buffer, bm_ulog_kthread, bm_ulog_is_bm_ulog_enabled, bm_ulog_probe, bm_ulog_is_enabled_by_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_relax @ 00105048 size=1
// signature: undefined pm_relax(void)
// callers: [bm_ulog_complete_work, bm_ulog_remove, bm_ulog_enable_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work @ 00105050 size=1
// signature: undefined cancel_delayed_work(void)
// callers: [bm_ulog_remove, bm_ulog_enable_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_stay_awake @ 00105058 size=1
// signature: undefined pm_stay_awake(void)
// callers: [bm_ulog_enable_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00105060 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [bm_ulog_enable_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 00105070 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [bm_ulog_enable_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wake_up_process @ 00105078 size=1
// signature: undefined wake_up_process(void)
// callers: [bm_ulog_probe, bm_ulog_complete_work, bm_ulog_enable_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wake_up_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_opts_by_path @ 00105080 size=1
// signature: undefined of_find_node_opts_by_path(void)
// callers: [bm_ulog_is_bm_ulog_enabled, bm_ulog_is_enabled_by_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_opts_by_path(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00105088 size=1
// signature: undefined of_property_read_string(void)
// callers: [bm_ulog_is_bm_ulog_enabled, bm_ulog_is_enabled_by_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strstr @ 00105090 size=1
// signature: char * strstr(char * __haystack, char * __needle)
// callers: [bm_ulog_is_bm_ulog_enabled, bm_ulog_is_enabled_by_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00105098 size=1
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
// platform_driver_unregister @ 001050a0 size=1
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
// devm_kmalloc @ 001050a8 size=1
// signature: undefined devm_kmalloc(void)
// callers: [bm_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u64 @ 001050b0 size=1
// signature: undefined of_property_read_u64(void)
// callers: [bm_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001050b8 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [bm_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001050c0 size=1
// signature: undefined of_find_property(void)
// callers: [bm_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_register_client @ 001050c8 size=1
// signature: undefined pmic_glink_register_client(void)
// callers: [bm_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_register_client(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001050d0 size=1
// signature: undefined __mutex_init(void)
// callers: [bm_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 001050d8 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [bm_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 001050e0 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [bm_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001050e8 size=1
// signature: undefined _dev_err(void)
// callers: [bm_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_create_on_node @ 001050f0 size=1
// signature: undefined kthread_create_on_node(void)
// callers: [bm_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_create_on_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_set_wakeup_capable @ 001050f8 size=1
// signature: undefined device_set_wakeup_capable(void)
// callers: [bm_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_enable @ 00105100 size=1
// signature: undefined device_wakeup_enable(void)
// callers: [bm_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00105110 size=1
// signature: undefined init_timer_key(void)
// callers: [bm_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_stop @ 00105118 size=1
// signature: undefined kthread_stop(void)
// callers: [bm_ulog_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 00105120 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [bm_ulog_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00105128 size=1
// signature: undefined debugfs_remove(void)
// callers: [bm_ulog_add_debugfs, bm_ulog_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_unregister_client @ 00105130 size=1
// signature: undefined pmic_glink_unregister_client(void)
// callers: [bm_ulog_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_unregister_client(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00105138 size=1
// signature: undefined complete(void)
// callers: [bm_ulog_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00105140 size=1
// signature: undefined msleep(void)
// callers: [bm_ulog_kthread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_should_stop @ 00105148 size=1
// signature: undefined kthread_should_stop(void)
// callers: [bm_ulog_kthread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_should_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00105150 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [bm_ulog_add_debugfs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00105158 size=1
// signature: undefined debugfs_create_file(void)
// callers: [bm_ulog_add_debugfs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_x64 @ 00105160 size=1
// signature: undefined debugfs_create_x64(void)
// callers: [bm_ulog_add_debugfs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_x64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_x32 @ 00105168 size=1
// signature: undefined debugfs_create_x32(void)
// callers: [bm_ulog_add_debugfs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_x32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 00105170 size=1
// signature: undefined single_open(void)
// callers: [bm_ulog_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 00105178 size=1
// signature: undefined seq_puts(void)
// callers: [bm_ulog_dump_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



