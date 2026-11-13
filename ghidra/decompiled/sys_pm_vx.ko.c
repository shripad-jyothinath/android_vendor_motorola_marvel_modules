// Decompiled by Ghidra 12.2
// Program: sys_pm_vx.ko
// Image base: 00100000

//------------------------------------------------------------
// trigger_dump_enable @ 001004b4 size=68
// signature: undefined trigger_dump_enable(void)
// callers: []
//------------------------------------------------------------

void trigger_dump_enable(void)

{
  long lVar1;
  
  mutex_lock(g_pd + 0x30);
  lVar1 = g_pd + 0x30;
  *(undefined1 *)(g_pd + 0x85) = 1;
  mutex_unlock(lVar1);
  return;
}



//------------------------------------------------------------
// trigger_dump_disable @ 001004fc size=64
// signature: undefined trigger_dump_disable(void)
// callers: []
//------------------------------------------------------------

void trigger_dump_disable(void)

{
  long lVar1;
  
  mutex_lock(g_pd + 0x30);
  lVar1 = g_pd + 0x30;
  *(undefined1 *)(g_pd + 0x85) = 0;
  mutex_unlock(lVar1);
  return;
}



//------------------------------------------------------------
// vx_probe @ 00100540 size=600
// signature: undefined vx_probe(void)
// callers: []
//------------------------------------------------------------

ulong vx_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  ulong *puVar3;
  ulong uVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  
  lVar1 = param_1 + 0x10;
  puVar3 = (ulong *)devm_kmalloc(lVar1,0x88,0xdc0);
  g_pd = puVar3;
  if (puVar3 == (ulong *)0x0) {
    uVar4 = 0xfffffff4;
  }
  else {
    uVar4 = of_iomap(*(undefined8 *)(param_1 + 0x2f8),0);
    *puVar3 = uVar4;
    if ((uVar4 != 0) && (uVar4 < 0xfffffffffffff001)) {
      lVar5 = of_match_node(&drv_match_table,*(undefined8 *)(param_1 + 0x2f8));
      if (lVar5 == 0) {
        uVar4 = 0xffffffed;
      }
      else {
        uVar4 = *(ulong *)(lVar5 + 0xc0);
        iVar7 = 0;
        do {
          iVar6 = iVar7;
          iVar7 = iVar6 + 1;
        } while (**(char **)(uVar4 + (long)iVar6 * 8) != '\0');
        iVar7 = -1;
        puVar3[4] = uVar4;
        puVar3[2] = (long)iVar6;
        do {
          iVar6 = iVar7 + 0x1c;
          iVar7 = iVar7 + 1;
        } while (**(char **)(uVar4 + (long)iVar6 * 8) != '\0');
        puVar3[3] = (long)iVar7;
        puVar3[5] = uVar4 + 0xd8;
        uVar4 = debugfs_create_dir("sys_pm_vx",0);
        puVar3[1] = uVar4;
        if (uVar4 == 0) {
          uVar4 = 0xffffffea;
        }
        else {
          debugfs_create_file("sys_pm_violators",0x100,uVar4,puVar3,sys_pm_vx_fops);
          debugfs_create_file("trigger_dump",0x180,uVar4,puVar3,&trigger_dump_enable_fops);
          uVar2 = device_create_file(lVar1,&dev_attr_debug_time_ms);
          if (uVar2 == 0) {
            uVar2 = device_create_file(lVar1,&dev_attr_debug_enable);
            if (uVar2 == 0) {
              uVar2 = device_create_file(lVar1,&dev_attr_set_timer_ms);
              if (uVar2 == 0) {
                uVar4 = qmp_get(lVar1);
                puVar3[0xc] = uVar4;
                if (uVar4 < 0xfffffffffffff001) {
                  __mutex_init(puVar3 + 6,"&pd->lock",&vx_probe___key);
                  uVar4 = 0;
                  *(undefined1 *)(puVar3 + 0xf) = 0;
                  *(undefined2 *)((long)puVar3 + 0x84) = 0;
                  *(ulong **)(param_1 + 0xa8) = puVar3;
                  *(undefined8 *)((long)puVar3 + 0x7c) = 0x138800002710;
                  goto LAB_00100738;
                }
                device_remove_file(lVar1,&dev_attr_set_timer_ms);
              }
              else {
                uVar4 = (ulong)uVar2;
                _dev_err(lVar1,"failed: create sys pm vx sysfs set timer_ms entry\n");
              }
              device_remove_file(lVar1,&dev_attr_debug_enable);
            }
            else {
              uVar4 = (ulong)uVar2;
              _dev_err(lVar1,"failed: create sys pm vx sysfs debug enable entry\n");
            }
            device_remove_file(lVar1,&dev_attr_debug_time_ms);
          }
          else {
            uVar4 = (ulong)uVar2;
            _dev_err(lVar1,"failed: create sys pm vx sysfs debug time entry\n");
          }
          debugfs_remove(puVar3[1]);
        }
      }
    }
  }
LAB_00100738:
  return uVar4 & 0xffffffff;
}



//------------------------------------------------------------
// vx_remove @ 0010079c size=116
// signature: undefined vx_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 vx_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  param_1 = param_1 + 0x10;
  debugfs_remove(*(undefined8 *)(lVar1 + 8));
  device_remove_file(param_1,&dev_attr_debug_time_ms);
  device_remove_file(param_1,&dev_attr_debug_enable);
  device_remove_file(param_1,&dev_attr_set_timer_ms);
  qmp_put(*(undefined8 *)(lVar1 + 0x60));
  subsystem_sleep_debug_enable(0);
  return 0;
}



//------------------------------------------------------------
// open_vx @ 00100814 size=48
// signature: undefined open_vx(void)
// callers: []
//------------------------------------------------------------

void open_vx(long param_1,undefined8 param_2)

{
  single_open(param_2,vx_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// vx_show @ 00100848 size=768
// signature: undefined vx_show(void)
// callers: []
//------------------------------------------------------------

void vx_show(long param_1)

{
  uint *puVar1;
  ulong *puVar2;
  undefined4 *puVar3;
  char cVar4;
  undefined8 uVar5;
  undefined *puVar6;
  undefined *puVar7;
  uint *puVar8;
  ulong uVar9;
  uint uVar10;
  long lVar11;
  ulong uVar12;
  undefined8 *puVar13;
  bool bVar14;
  ulong uVar15;
  long *plVar16;
  ulong uVar17;
  undefined8 local_80;
  long local_78;
  ulong local_70;
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  lVar11 = *(long *)(param_1 + 0x80);
  local_78 = 0;
  local_70 = 0;
  local_80 = 0;
  uVar5 = read_vx_data(lVar11,&local_80);
  if ((int)uVar5 != 0) goto LAB_00100b0c;
  cVar4 = local_80._3_1_;
  if (local_80._3_1_ == -0x56) {
    puVar2 = (ulong *)(lVar11 + 0x18);
    lVar11 = *(long *)(lVar11 + 0x28);
joined_r0x001008d4:
    if ((lVar11 != 0) && (uVar12 = *puVar2, uVar12 != 0)) {
      if (local_80._3_1_ == -0x56) {
        puVar6 = &DAT_00101d60;
      }
      else if (local_80._3_1_ == -0x34) {
        puVar6 = &DAT_00101c37;
      }
      else {
        puVar6 = &DAT_00101d2b;
        if (local_80._3_1_ != -0x23) {
          puVar6 = &DAT_00101a77;
        }
      }
      seq_printf(param_1,
                 "Mode           : %s\nDuration (ms)  : %u\nTime Shift     : %u\nFlush Threshold: %u\nMax Log Entries: %u\n"
                 ,puVar6,local_80._6_2_,local_80._5_1_,local_80._4_1_,local_80._2_1_);
      seq_puts(param_1,"Timestamp|");
      uVar15 = 0;
      do {
        seq_printf(param_1,&DAT_00101adf,8,*(undefined8 *)(lVar11 + uVar15 * 8));
        uVar15 = (ulong)((int)uVar15 + 1);
      } while (uVar15 < uVar12);
      seq_puts(param_1,&DAT_00101cc3);
      lVar11 = local_78;
      uVar15 = local_70 & 0xffffffff;
      if (0 < (int)local_70) {
        uVar17 = 0;
        bVar14 = false;
        puVar6 = &DAT_00101d2b;
        if (cVar4 != -0x23) {
          puVar6 = &DAT_00101a77;
        }
        do {
          puVar3 = (undefined4 *)(lVar11 + uVar17 * 0x10);
          seq_printf(param_1,&DAT_00101d65,9,*puVar3);
          plVar16 = (long *)(puVar3 + 2);
          puVar8 = (uint *)*plVar16;
          uVar9 = 0;
          uVar10 = *puVar8;
          do {
            puVar1 = puVar8 + uVar9;
            uVar9 = (ulong)((int)uVar9 + 1);
            uVar10 = *puVar1 | uVar10;
          } while (uVar9 < uVar12);
          if (uVar10 == 0) {
            if (bVar14) {
              if (cVar4 == -0x56) {
                puVar7 = &DAT_00101d60;
              }
              else {
                puVar7 = &DAT_00101c37;
                if (cVar4 != -0x34) {
                  puVar7 = puVar6;
                }
              }
              seq_printf(param_1,"%s Exit\n",puVar7);
              bVar14 = false;
            }
            else {
              if (cVar4 == -0x56) {
                puVar7 = &DAT_00101d60;
              }
              else {
                puVar7 = &DAT_00101c37;
                if (cVar4 != -0x34) {
                  puVar7 = puVar6;
                }
              }
              seq_printf(param_1,"%s Enter\n",puVar7);
              bVar14 = true;
            }
          }
          else {
            uVar9 = 0;
            do {
              seq_printf(param_1,&DAT_00101d6a,8,*(undefined4 *)(*plVar16 + uVar9 * 4));
              uVar9 = (ulong)((int)uVar9 + 1);
            } while (uVar9 < uVar12);
            seq_puts(param_1,&DAT_00101cc3);
          }
          uVar17 = uVar17 + 1;
        } while (uVar17 != uVar15);
      }
    }
  }
  else if ((local_80._3_1_ == -0x23) || (local_80._3_1_ == -0x34)) {
    puVar2 = (ulong *)(lVar11 + 0x10);
    lVar11 = *(long *)(lVar11 + 0x20);
    goto joined_r0x001008d4;
  }
  lVar11 = local_78;
  uVar12 = local_70 & 0xffffffff;
  if (0 < (int)local_70) {
    puVar13 = (undefined8 *)(local_78 + 8);
    do {
      kfree(*puVar13);
      uVar12 = uVar12 - 1;
      puVar13 = puVar13 + 2;
    } while (uVar12 != 0);
  }
  kfree(lVar11);
  uVar5 = 0;
LAB_00100b0c:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// read_vx_data @ 00100b48 size=528
// signature: undefined read_vx_data(void)
// callers: [vx_show, vx_resume]
//------------------------------------------------------------

undefined8 read_vx_data(long *param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  ulong *puVar11;
  undefined8 *puVar12;
  long lVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  
  lVar13 = *param_1;
  uVar7 = readl_relaxed(lVar13);
  DataMemoryBarrier(2,1);
  if (uVar7 != 0) {
    uVar5 = uVar7 & 0xff;
    *(ushort *)(param_2 + 2) = (ushort)(uVar7 >> 8) & 0xff | (ushort)((uVar7 & 0xff00ff) << 8);
    if (uVar5 == 0xaa) {
      puVar11 = (ulong *)(param_1 + 3);
      param_1 = param_1 + 5;
    }
    else {
      if ((uVar5 != 0xdd) && (uVar5 != 0xcc)) {
        return 0xffffffed;
      }
      puVar11 = (ulong *)(param_1 + 2);
      param_1 = param_1 + 4;
    }
    if (*param_1 == 0) {
      return 0xffffffed;
    }
    uVar15 = *puVar11;
    if (uVar15 == 0) {
      return 0xffffffed;
    }
    iVar8 = readl_relaxed(lVar13 + 4);
    DataMemoryBarrier(2,1);
    if (iVar8 != 0) {
      *(short *)(param_2 + 6) = (short)iVar8;
      *(char *)(param_2 + 5) = (char)((uint)iVar8 >> 0x10);
      *(char *)(param_2 + 4) = (char)((uint)iVar8 >> 0x18);
      lVar9 = __kmalloc((ulong)*(byte *)(param_2 + 2) << 4,0xdc0);
      if (lVar9 == 0) {
        return 0xfffffff4;
      }
      if (*(char *)(param_2 + 2) == '\0') {
        uVar14 = 0;
      }
      else {
        uVar14 = 0;
        uVar16 = 8;
        do {
          iVar8 = readl_relaxed(lVar13 + uVar16);
          DataMemoryBarrier(2,1);
          piVar4 = (int *)(lVar9 + uVar14 * 0x10);
          *piVar4 = iVar8;
          if (iVar8 == 0) break;
          *piVar4 = iVar8 << (ulong)(*(byte *)(param_2 + 5) & 0x1f);
          if ((uVar15 + 3 >> 0x3e != 0) ||
             (lVar10 = __kmalloc((uVar15 + 3 & 0xfffffffffffffffc) << 2,0xdc0), lVar10 == 0)) {
            if (0 < (int)uVar14) {
              puVar12 = (undefined8 *)(lVar9 + 8);
              do {
                kfree(*puVar12);
                uVar14 = uVar14 - 1;
                puVar12 = puVar12 + 2;
              } while (uVar14 != 0);
            }
            kfree(lVar9);
            return 0xfffffff4;
          }
          iVar8 = 4;
          do {
            uVar7 = readl_relaxed(lVar13 + (ulong)(uint)((int)uVar16 + iVar8));
            DataMemoryBarrier(2,1);
            *(uint *)(lVar10 + (long)(iVar8 + -4) * 4) = uVar7 & 0xff;
            iVar3 = iVar8 + 4;
            *(uint *)(lVar10 + (long)(iVar8 + -3) * 4) = uVar7 >> 8 & 0xff;
            uVar2 = (ulong)iVar8;
            *(uint *)(lVar10 + (long)(iVar8 + -2) * 4) = uVar7 >> 0x10 & 0xff;
            *(uint *)(lVar10 + (long)(iVar8 + -1) * 4) = uVar7 >> 0x18;
            iVar8 = iVar3;
          } while (uVar2 < uVar15);
          bVar6 = *(byte *)(param_2 + 2);
          lVar1 = uVar14 * 0x10;
          uVar14 = uVar14 + 1;
          uVar16 = (ulong)(uint)((int)uVar16 + iVar3);
          *(long *)(lVar9 + lVar1 + 8) = lVar10;
        } while (uVar14 < bVar6);
      }
      *(long *)(param_2 + 8) = lVar9;
      *(int *)(param_2 + 0x10) = (int)uVar14;
      return 0;
    }
  }
  return 0xfffffffe;
}



//------------------------------------------------------------
// readl_relaxed @ 00100d58 size=124
// signature: undefined readl_relaxed(void)
// callers: [read_vx_data]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x100da0,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// trigger_dump_enable_fops_open @ 00100dd8 size=52
// signature: undefined trigger_dump_enable_fops_open(void)
// callers: []
//------------------------------------------------------------

void trigger_dump_enable_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,trigger_dump_enable_get,trigger_dump_enable_set,"%lld\n");
  return;
}



//------------------------------------------------------------
// trigger_dump_enable_get @ 00100e10 size=80
// signature: undefined trigger_dump_enable_get(void)
// callers: []
//------------------------------------------------------------

undefined8 trigger_dump_enable_get(long param_1,ulong *param_2)

{
  mutex_lock(param_1 + 0x30);
  *param_2 = (ulong)*(byte *)(param_1 + 0x85);
  mutex_unlock(param_1 + 0x30);
  return 0;
}



//------------------------------------------------------------
// trigger_dump_enable_set @ 00100e64 size=84
// signature: undefined trigger_dump_enable_set(void)
// callers: []
//------------------------------------------------------------

undefined8 trigger_dump_enable_set(long param_1,long param_2)

{
  mutex_lock(param_1 + 0x30);
  *(bool *)(param_1 + 0x85) = param_2 != 0;
  mutex_unlock(param_1 + 0x30);
  return 0;
}



//------------------------------------------------------------
// debug_time_ms_show @ 00100ebc size=60
// signature: undefined debug_time_ms_show(void)
// callers: []
//------------------------------------------------------------

long debug_time_ms_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00101a1c,*(undefined4 *)(*(long *)(param_1 + 0x98) + 0x7c));
  return (long)iVar1;
}



//------------------------------------------------------------
// debug_time_ms_store @ 00100efc size=200
// signature: undefined debug_time_ms_store(void)
// callers: []
//------------------------------------------------------------

undefined8
debug_time_ms_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  int local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar2 = kstrtoint(param_3,0,&local_3c);
  if (iVar2 == 0) {
    if (local_3c < 1) {
      _printk(&DAT_00101ae4,"debug_time_ms_store");
      param_4 = 0xffffffffffffffea;
    }
    else {
      lVar1 = lVar3 + 0x30;
      mutex_lock(lVar1);
      *(int *)(lVar3 + 0x7c) = local_3c;
      mutex_unlock(lVar1);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// debug_enable_show @ 00100fc8 size=60
// signature: undefined debug_enable_show(void)
// callers: []
//------------------------------------------------------------

long debug_enable_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00101a1c,*(undefined1 *)(*(long *)(param_1 + 0x98) + 0x78));
  return (long)iVar1;
}



//------------------------------------------------------------
// debug_enable_store @ 00101008 size=216
// signature: undefined debug_enable_store(void)
// callers: []
//------------------------------------------------------------

undefined8 debug_enable_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar1 = kstrtoint(param_3,0,&local_3c);
  if (iVar1 == 0) {
    if (local_3c < 2) {
      mutex_lock(lVar2 + 0x30);
      *(bool *)(lVar2 + 0x78) = local_3c != 0;
      mutex_unlock(lVar2 + 0x30);
      subsystem_sleep_debug_enable(*(undefined1 *)(lVar2 + 0x78));
    }
    else {
      _printk(&DAT_00101d6f,"debug_enable_store");
      param_4 = 0xffffffffffffffea;
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// set_timer_ms_show @ 001010e4 size=60
// signature: undefined set_timer_ms_show(void)
// callers: []
//------------------------------------------------------------

long set_timer_ms_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00101a1c,*(undefined4 *)(*(long *)(param_1 + 0x98) + 0x80));
  return (long)iVar1;
}



//------------------------------------------------------------
// set_timer_ms_store @ 00101124 size=200
// signature: undefined set_timer_ms_store(void)
// callers: []
//------------------------------------------------------------

undefined8 set_timer_ms_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  int local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar2 = kstrtoint(param_3,0,&local_3c);
  if (iVar2 == 0) {
    if (local_3c < 1) {
      _printk(&DAT_00101962,"set_timer_ms_store");
      param_4 = 0xffffffffffffffea;
    }
    else {
      lVar1 = lVar3 + 0x30;
      mutex_lock(lVar1);
      *(int *)(lVar3 + 0x80) = local_3c;
      mutex_unlock(lVar1);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// vx_suspend @ 001011f0 size=224
// signature: undefined vx_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 vx_suspend(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  if (*(char *)(lVar3 + 0x78) != '\0') {
    uVar2 = ktime_get_with_offset(1);
    *(undefined8 *)(lVar3 + 0x68) = uVar2;
    if (*(char *)(lVar3 + 0x84) != '\0') {
      local_38 = 0;
      uStack_30 = 0;
      local_48 = 0;
      uStack_40 = 0;
      local_58 = 0;
      uStack_50 = 0;
      local_68 = 0;
      uStack_60 = 0;
      local_78 = 0;
      uStack_70 = 0;
      local_88 = 0;
      uStack_80 = 0;
      mutex_lock(lVar3 + 0x30);
      scnprintf(&local_88,0x60,"{class: lpm_mon, type: cxpc, dur: 1000, flush: 5, ts_adj: 1}");
      iVar1 = qmp_send(*(undefined8 *)(lVar3 + 0x60),&local_88,0x60);
      if (iVar1 != 0) {
        _printk(&DAT_00101b82,"sys_pm_vx_send_msg",iVar1);
      }
      mutex_unlock(lVar3 + 0x30);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// vx_resume @ 001012d4 size=724
// signature: undefined vx_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 vx_resume(long param_1)

{
  long *plVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  undefined8 *puVar9;
  ulong uVar10;
  ulong uVar11;
  long *plVar12;
  ulong uVar13;
  ulong uVar14;
  undefined8 local_e0;
  long local_d8;
  ulong local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  lVar8 = *(long *)(param_1 + 0x98);
  if (*(char *)(lVar8 + 0x78) != '\0') {
    lVar5 = ktime_get_with_offset(1);
    *(long *)(lVar8 + 0x70) = lVar5;
    if ((long)(ulong)*(uint *)(lVar8 + 0x7c) < (lVar5 - *(long *)(lVar8 + 0x68)) / 1000000) {
      uVar6 = has_system_slept();
      if (((uVar6 & 1) == 0) && (uVar6 = has_subsystem_slept(), (uVar6 & 1) != 0)) {
        if (*(char *)(lVar8 + 0x84) == '\0') {
          *(undefined1 *)(lVar8 + 0x84) = 1;
        }
        else {
          local_d8 = 0;
          local_d0 = 0;
          local_e0 = 0;
          iVar3 = read_vx_data(lVar8,&local_e0);
          uVar6 = local_d0;
          lVar5 = local_d8;
          if (iVar3 == 0) {
            uVar7 = *(ulong *)(lVar8 + 0x10);
            iVar3 = (int)local_d0;
            if (uVar7 != 0) {
              uVar10 = local_d0 & 0xffffffff;
              uVar14 = 0;
              uVar2 = (int)local_d0 - 1;
              plVar1 = (long *)(local_d8 + 8);
              do {
                uVar11 = (ulong)uVar2;
                plVar12 = plVar1;
                uVar13 = uVar10;
                if (0 < iVar3) {
                  do {
                    if (*(int *)(*plVar12 + uVar14 * 4) == 0) break;
                    if (uVar11 == 0) {
                      _printk(&DAT_00101a46,"vx_check_drv",
                              *(undefined8 *)(*(long *)(lVar8 + 0x20) + uVar14 * 8));
                      local_78 = 0;
                      uStack_70 = 0;
                      local_88 = 0;
                      uStack_80 = 0;
                      local_98 = 0;
                      uStack_90 = 0;
                      local_a8 = 0;
                      uStack_a0 = 0;
                      local_b8 = 0;
                      uStack_b0 = 0;
                      local_c8 = 0;
                      uStack_c0 = 0;
                      if (*(char *)(lVar8 + 0x85) != '\0') {
                        mutex_lock(lVar8 + 0x30);
                        scnprintf(&local_c8,0x60,"{class: misc_debug, res: do_crash_dump, tmr: %d}",
                                  *(undefined4 *)(lVar8 + 0x80));
                        iVar4 = qmp_send(*(undefined8 *)(lVar8 + 0x60),&local_c8,0x60);
                        if (iVar4 != 0) {
                          _printk(&DAT_00101b82,"trigger_dump",iVar4);
                        }
                        mutex_unlock(lVar8 + 0x30);
                      }
                    }
                    uVar13 = uVar13 - 1;
                    uVar11 = uVar11 - 1;
                    plVar12 = plVar12 + 2;
                  } while (uVar13 != 0);
                  uVar7 = *(ulong *)(lVar8 + 0x10);
                }
                uVar14 = (ulong)((int)uVar14 + 1);
              } while (uVar14 < uVar7);
            }
            if (0 < iVar3) {
              uVar6 = uVar6 & 0xffffffff;
              puVar9 = (undefined8 *)(lVar5 + 8);
              do {
                kfree(*puVar9);
                uVar6 = uVar6 - 1;
                puVar9 = puVar9 + 2;
              } while (uVar6 != 0);
            }
            kfree(lVar5);
          }
          else {
            _printk(&DAT_00101921,"vx_check_drv");
          }
        }
      }
      else {
        if (*(char *)(lVar8 + 0x84) != '\0') {
          local_78 = 0;
          uStack_70 = 0;
          local_88 = 0;
          uStack_80 = 0;
          local_98 = 0;
          uStack_90 = 0;
          local_a8 = 0;
          uStack_a0 = 0;
          local_b8 = 0;
          uStack_b0 = 0;
          local_c8 = 0;
          uStack_c0 = 0;
          mutex_lock(lVar8 + 0x30);
          scnprintf(&local_c8,0x60,"{class: lpm_mon, type: cxpc, dur: 1000, flush: 1, log_once: 1}")
          ;
          iVar3 = qmp_send(*(undefined8 *)(lVar8 + 0x60),&local_c8,0x60);
          if (iVar3 != 0) {
            _printk(&DAT_00101b82,"sys_pm_vx_send_msg",iVar3);
          }
          mutex_unlock(lVar8 + 0x30);
        }
        *(undefined1 *)(lVar8 + 0x84) = 0;
      }
    }
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 001015dc size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&vx_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010160c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&vx_driver);
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00105000 size=1
// signature: undefined mutex_lock(void)
// callers: [trigger_dump_enable, debug_time_ms_store, vx_suspend, trigger_dump_enable_get, debug_enable_store, vx_resume, trigger_dump_disable, set_timer_ms_store, trigger_dump_enable_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00105008 size=1
// signature: undefined mutex_unlock(void)
// callers: [trigger_dump_enable, debug_time_ms_store, vx_suspend, trigger_dump_enable_get, debug_enable_store, vx_resume, trigger_dump_disable, set_timer_ms_store, trigger_dump_enable_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00105010 size=1
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
// platform_driver_unregister @ 00105018 size=1
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
// devm_kmalloc @ 00105020 size=1
// signature: undefined devm_kmalloc(void)
// callers: [vx_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_iomap @ 00105028 size=1
// signature: undefined of_iomap(void)
// callers: [vx_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_iomap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_match_node @ 00105030 size=1
// signature: undefined of_match_node(void)
// callers: [vx_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00105038 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [vx_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00105040 size=1
// signature: undefined debugfs_create_file(void)
// callers: [vx_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 00105048 size=1
// signature: undefined device_create_file(void)
// callers: [vx_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmp_get @ 00105050 size=1
// signature: undefined qmp_get(void)
// callers: [vx_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmp_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_remove_file @ 00105058 size=1
// signature: undefined device_remove_file(void)
// callers: [vx_probe, vx_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_remove_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00105060 size=1
// signature: undefined debugfs_remove(void)
// callers: [vx_probe, vx_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00105068 size=1
// signature: undefined __mutex_init(void)
// callers: [vx_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00105070 size=1
// signature: undefined _dev_err(void)
// callers: [vx_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmp_put @ 00105078 size=1
// signature: undefined qmp_put(void)
// callers: [vx_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmp_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// subsystem_sleep_debug_enable @ 00105080 size=1
// signature: undefined subsystem_sleep_debug_enable(void)
// callers: [vx_remove, debug_enable_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void subsystem_sleep_debug_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 00105088 size=1
// signature: undefined single_open(void)
// callers: [open_vx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00105090 size=1
// signature: undefined seq_printf(void)
// callers: [vx_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 00105098 size=1
// signature: undefined seq_puts(void)
// callers: [vx_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001050a0 size=1
// signature: undefined kfree(void)
// callers: [read_vx_data, vx_show, vx_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001050a8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [debug_time_ms_store, vx_show, vx_suspend, debug_enable_store, vx_resume, set_timer_ms_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001050b0 size=1
// signature: undefined __kmalloc(void)
// callers: [read_vx_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 001050b8 size=1
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
// log_post_read_mmio @ 001050c0 size=1
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
// simple_attr_open @ 001050c8 size=1
// signature: undefined simple_attr_open(void)
// callers: [trigger_dump_enable_fops_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_attr_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 001050d0 size=1
// signature: undefined scnprintf(void)
// callers: [set_timer_ms_show, debug_time_ms_show, vx_suspend, vx_resume, debug_enable_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 001050d8 size=1
// signature: undefined kstrtoint(void)
// callers: [debug_time_ms_store, debug_enable_store, set_timer_ms_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001050e0 size=1
// signature: undefined _printk(void)
// callers: [debug_time_ms_store, vx_suspend, debug_enable_store, vx_resume, set_timer_ms_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_with_offset @ 001050e8 size=1
// signature: undefined ktime_get_with_offset(void)
// callers: [vx_suspend, vx_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_with_offset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmp_send @ 001050f0 size=1
// signature: undefined qmp_send(void)
// callers: [vx_suspend, vx_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmp_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// has_system_slept @ 001050f8 size=1
// signature: undefined has_system_slept(void)
// callers: [vx_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void has_system_slept(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// has_subsystem_slept @ 00105100 size=1
// signature: undefined has_subsystem_slept(void)
// callers: [vx_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void has_subsystem_slept(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



