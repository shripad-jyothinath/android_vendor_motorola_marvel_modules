// Decompiled by Ghidra 12.2
// Program: bk_log.ko
// Image base: 00100000

//------------------------------------------------------------
// store_work_thread @ 0010020c size=1616
// signature: undefined store_work_thread(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void store_work_thread(long param_1)

{
  long *plVar1;
  long *plVar2;
  byte bVar3;
  uint uVar4;
  long *plVar5;
  uint uVar6;
  uint uVar7;
  code *pcVar8;
  undefined4 uVar9;
  char *__s;
  void *pvVar10;
  undefined1 *puVar11;
  ulong uVar12;
  undefined8 uVar13;
  ulong uVar14;
  long lVar15;
  ulong uVar16;
  long lVar17;
  uint uVar18;
  uint uVar19;
  long lVar20;
  long *plVar21;
  ulong local_90 [6];
  
  lVar17 = sp_el0;
  local_90[5] = *(long *)(lVar17 + 0x638);
  lVar17 = *(long *)(param_1 + 0x78);
  if (lVar17 == 0) {
    lVar15 = _jiffies + 0x9c4;
    do {
      uVar13 = name_to_dev_t(param_1);
      if ((int)uVar13 != 0) {
        uVar12 = blkdev_get_by_dev(uVar13,0x83,param_1);
        *(ulong *)(param_1 + 0x78) = uVar12;
        if (uVar12 < 0xfffffffffffff001) {
          uVar16 = *(ulong *)(*(long *)(uVar12 + 0x30) + 0x50);
          uVar12 = uVar16;
          if (0x1ffffff < uVar16) {
            uVar12 = 0x2000000;
          }
          uVar14 = 0;
          if ((ulong)*(byte *)(param_1 + 0x22) != 0) {
            uVar14 = (uVar12 - 0x1000) / (ulong)*(byte *)(param_1 + 0x22);
          }
          *(ulong *)(param_1 + 0x50) = uVar14 & 0xfffffffffffff000;
          *(ulong *)(param_1 + 0x58) = uVar16;
          _printk(&DAT_001014a0,"get_blkdev",param_1);
          lVar17 = *(long *)(param_1 + 0x78);
          break;
        }
        _printk(&DAT_00101519,"get_blkdev",param_1);
      }
      if (lVar15 - _jiffies < 0) {
        _printk(&DAT_00101464,"store_work_thread",param_1);
        uVar13 = 0xfffffff1;
        goto LAB_0010037c;
      }
      __const_udelay(0x418958);
      __const_udelay(0x418958);
      __const_udelay(0x418958);
      __const_udelay(0x418958);
      __const_udelay(0x418958);
      __const_udelay(0x418958);
      __const_udelay(0x418958);
      __const_udelay(0x418958);
      __const_udelay(0x418958);
      __const_udelay(0x418958);
      lVar17 = *(long *)(param_1 + 0x78);
    } while (lVar17 == 0);
  }
  uVar16 = *(ulong *)(param_1 + 0x50);
  uVar12 = *(ulong *)(param_1 + 0x58);
  local_90[0] = local_90[0] & 0xffffffff00000000;
  bVar3 = *(byte *)(param_1 + 0x22);
  __s = (char *)vzalloc(0x1000);
  if (__s == (char *)0x0) {
    _printk(&DAT_00101415,"update_bio_pos");
  }
  else {
    rw_bdev(lVar17,__s,0x1000,0,0);
    sscanf(__s,"%d\n",local_90);
    uVar7 = (uint)local_90[0];
    uVar18 = (uint)bVar3;
    uVar19 = (uint)bVar3;
    uVar4 = (uint)local_90[0];
    if (uVar18 <= (uint)local_90[0]) {
      uVar4 = uVar19;
    }
    uVar6 = 0;
    if (uVar19 != 0) {
      uVar6 = uVar4 / uVar19;
    }
    uVar4 = uVar4 - uVar6 * uVar19;
    lVar15 = uVar16 * uVar4 + 0x1000;
    if ((uint)local_90[0] <= uVar18) {
      uVar12 = uVar16;
    }
    local_90[0] = CONCAT44(local_90[0]._4_4_,uVar4 + 1);
    lVar20 = 0;
    if (uVar7 <= uVar18) {
      lVar20 = lVar15;
    }
    *(long *)(param_1 + 0x38) = lVar15;
    lVar15 = _jiffies;
    pvVar10 = (void *)vzalloc(uVar12);
    if (pvVar10 == (void *)0x0) {
      _printk(&DAT_00101544,"erase_block",uVar12);
    }
    else if (lVar20 == 0) {
LAB_001007a4:
      rw_bdev(lVar17,pvVar10,uVar12,0x801,lVar20);
      vfree(pvVar10);
      uVar9 = jiffies_to_msecs(_jiffies - lVar15);
      _printk(&DAT_001015a4,"erase_block",uVar9);
    }
    else {
      rw_bdev(lVar17,pvVar10,0x1000,0,lVar20);
      uVar16 = 0;
      do {
        if ((uVar12 == uVar16) || (uVar12 < uVar16)) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(1,0x100858);
          (*pcVar8)();
        }
        if (*(char *)((long)pvVar10 + uVar16) != '\0') {
          memset(pvVar10,0,0x1000);
          goto LAB_001007a4;
        }
        uVar16 = uVar16 + 1;
      } while (uVar16 != 0x1000);
    }
    sprintf(__s,"%d\n",local_90[0] & 0xffffffff);
    rw_bdev(lVar17,__s,0x1000,0x801,0);
    vfree(__s);
  }
  puVar11 = (undefined1 *)vzalloc(0x1000);
  *(undefined1 **)(param_1 + 0x28) = puVar11;
  if (puVar11 == (undefined1 *)0x0) {
    _printk(&DAT_001014f1,"store_work_thread");
    uVar13 = 0xfffffff4;
  }
  else {
    *puVar11 = 10;
    *(undefined4 *)(param_1 + 0x30) = 1;
    uVar12 = kthread_should_stop();
    if ((uVar12 & 1) == 0) {
      lVar17 = param_1 + 0x88;
      plVar1 = (long *)(param_1 + 0x60);
      do {
        if (*(char *)(param_1 + 0x21) != '\0') break;
        uVar12 = *(ulong *)(param_1 + 0x48);
        if ((uVar12 < 0x19001) && (*(char *)(param_1 + 0x20) == '\0')) {
          local_90[3] = 0;
          local_90[4] = 0;
          local_90[1] = 0;
          local_90[2] = 0;
          local_90[0] = 0;
          init_wait_entry(local_90,0);
          lVar15 = prepare_to_wait_event(lVar17,local_90,1);
          uVar12 = *(ulong *)(param_1 + 0x48);
          if (uVar12 < 0x19001) {
            lVar20 = 0xfa;
            do {
              if (lVar20 == 0 && *(char *)(param_1 + 0x20) != '\0') {
                lVar20 = 1;
              }
              if ((*(char *)(param_1 + 0x20) != '\0') || (lVar20 == 0)) break;
              if (lVar15 != 0) goto LAB_001004a8;
              lVar20 = schedule_timeout(lVar20);
              lVar15 = prepare_to_wait_event(lVar17,local_90,1);
              uVar12 = *(ulong *)(param_1 + 0x48);
            } while (uVar12 < 0x19001);
          }
          finish_wait(lVar17,local_90);
          uVar12 = *(ulong *)(param_1 + 0x48);
        }
LAB_001004a8:
        if (((long *)*plVar1 != plVar1) && (uVar12 != 0)) {
          pvVar10 = (void *)vzalloc(uVar12 + *(uint *)(param_1 + 0x30));
          uVar16 = (ulong)*(uint *)(param_1 + 0x30);
          if (pvVar10 == (void *)0x0) {
            _printk(&DAT_00101618,"store_work_thread",uVar12 + uVar16);
          }
          else {
            if (*(uint *)(param_1 + 0x30) != 0) {
              memcpy(pvVar10,*(void **)(param_1 + 0x28),uVar16);
            }
            _raw_spin_lock(param_1 + 0x80);
            while (plVar21 = (long *)*plVar1, plVar21 != plVar1) {
              plVar5 = plVar21 + -2;
              if (plVar5 != (long *)0x0) {
                if (*plVar5 == 0) {
LAB_00100598:
                  uVar14 = __list_del_entry_valid(plVar21);
                  if ((uVar14 & 1) != 0) {
                    lVar15 = *plVar21;
                    plVar2 = (long *)plVar21[1];
                    *(long **)(lVar15 + 8) = plVar2;
                    *plVar2 = lVar15;
                  }
                  *plVar21 = -0x2152ffffffffff00;
                  plVar21[1] = (long)&DAT_dead000000000122;
                }
                else {
                  uVar4 = *(uint *)(plVar21 + -1);
                  if (uVar4 == 0) {
                    kfree();
                    goto LAB_00100598;
                  }
                  uVar14 = uVar16 + uVar4;
                  if (*(ulong *)(param_1 + 0x50) <
                      (uVar14 + *(long *)(param_1 + 0x40)) - (ulong)*(uint *)(param_1 + 0x30)) {
                    *(undefined1 *)(param_1 + 0x21) = 1;
                    _printk(&DAT_0010156e,"store_work_thread",*(long *)(param_1 + 0x40));
                    break;
                  }
                  if (uVar12 + *(uint *)(param_1 + 0x30) < uVar14) break;
                  memcpy((void *)((long)pvVar10 + uVar16),(void *)plVar21[-2],(ulong)uVar4);
                  uVar4 = *(uint *)(plVar21 + -1);
                  uVar14 = __list_del_entry_valid(plVar21);
                  if ((uVar14 & 1) != 0) {
                    lVar15 = *plVar21;
                    plVar2 = (long *)plVar21[1];
                    *(long **)(lVar15 + 8) = plVar2;
                    *plVar2 = lVar15;
                  }
                  uVar16 = uVar16 + uVar4;
                  *plVar21 = -0x2152ffffffffff00;
                  plVar21[1] = (long)&DAT_dead000000000122;
                  kfree(plVar21[-2]);
                }
                kfree(plVar5);
              }
            }
            *(ulong *)(param_1 + 0x48) =
                 (*(long *)(param_1 + 0x48) - uVar16) + (ulong)*(uint *)(param_1 + 0x30);
            _raw_spin_unlock(param_1 + 0x80);
            uVar12 = uVar16;
            if (0xfff < uVar16) {
              uVar12 = uVar16 & 0xfffffffffffff000;
            }
            rw_bdev(*(undefined8 *)(param_1 + 0x78),pvVar10,uVar12,0x801,
                    *(undefined8 *)(param_1 + 0x38));
            lVar15 = uVar16 - *(uint *)(param_1 + 0x30);
            *(long *)(param_1 + 0x38) = lVar15 + *(long *)(param_1 + 0x38);
            *(long *)(param_1 + 0x40) = *(long *)(param_1 + 0x40) + lVar15;
            *(uint *)(param_1 + 0x30) = (uint)uVar16 & 0xfff;
            if ((uVar16 & 0xfff) != 0) {
              memcpy(*(void **)(param_1 + 0x28),
                     (void *)((long)pvVar10 + (uVar16 & 0xfffffffffffff000)),uVar16 & 0xfff);
            }
            vfree(pvVar10);
          }
        }
        uVar12 = kthread_should_stop();
      } while ((uVar12 & 1) == 0);
    }
    uVar13 = 0;
  }
LAB_0010037c:
  *(undefined8 *)(bklog + 0x70) = 0;
  lVar17 = sp_el0;
  if (*(long *)(lVar17 + 0x638) != local_90[5]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar13);
  }
  return;
}



//------------------------------------------------------------
// sysrq_crash @ 00100860 size=196
// signature: undefined sysrq_crash(void)
// callers: []
//------------------------------------------------------------

void sysrq_crash(void)

{
  bool bVar1;
  uint uVar2;
  long lVar3;
  
  if ((bklog != 0) && (*(char *)(bklog + 0x21) == '\0')) {
    _printk(&DAT_00101334,"sysrq_crash");
    lVar3 = bklog + 0x88;
    *(undefined1 *)(bklog + 0x20) = 1;
    __wake_up(lVar3,3,1,0);
    if (*(long *)(bklog + 0x48) != 0) {
      uVar2 = (int)(*(long *)(bklog + 0x48) + 0xfffU >> 0xc) * 10;
      if ((int)uVar2 < 0x65) {
        uVar2 = 100;
      }
      _printk(&DAT_001013d6,"force_flush_logs",(ulong)uVar2);
      lVar3 = -(ulong)uVar2;
      do {
        __const_udelay(0x418958);
        bVar1 = lVar3 != -1;
        lVar3 = lVar3 + 1;
      } while (bVar1);
    }
  }
  return;
}



//------------------------------------------------------------
// get_bootargs @ 00100924 size=356
// signature: undefined get_bootargs(void)
// callers: [init_module]
//------------------------------------------------------------

undefined8 get_bootargs(undefined8 param_1,void *param_2,ulong param_3)

{
  int iVar1;
  long lVar2;
  size_t sVar3;
  char *__s;
  char *pcVar4;
  undefined8 uVar5;
  char *local_60;
  char *local_58;
  char *local_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_58 = (char *)0x0;
  local_50 = (char *)0x0;
  local_60 = (char *)0x0;
  lVar2 = of_find_node_opts_by_path("/chosen",0);
  if ((lVar2 != 0) &&
     (iVar1 = of_property_read_string(lVar2,"mmi,bootconfig",&local_50), iVar1 == 0)) {
    sVar3 = strlen(local_50);
    __s = (char *)__kmalloc(sVar3 + 1,0xdc0);
    if (__s != (char *)0x0) {
      strlcpy(__s,local_50,sVar3 + 1);
      sVar3 = strlen(__s);
      local_58 = (char *)strnstr(__s,param_1,sVar3);
      if (local_58 == (char *)0x0) {
LAB_00100a5c:
        uVar5 = 0;
      }
      else {
        local_60 = strsep(&local_58," ");
        if ((((local_60 == (char *)0x0) || (pcVar4 = strsep(&local_60,"="), pcVar4 == (char *)0x0))
            || (pcVar4 = strsep(&local_60,"\n"), pcVar4 == (char *)0x0)) ||
           (sVar3 = strlen(pcVar4), (param_3 & 0xffffffff) < sVar3)) goto LAB_00100a5c;
        memcpy(param_2,pcVar4,sVar3);
        uVar5 = 1;
      }
      kfree(__s);
      goto LAB_0010098c;
    }
  }
  uVar5 = 0;
LAB_0010098c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// rw_bdev @ 00100a88 size=376
// signature: undefined rw_bdev(void)
// callers: [store_work_thread]
//------------------------------------------------------------

void rw_bdev(undefined8 param_1,long param_2,long param_3,undefined4 param_4,ulong param_5)

{
  int iVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  uint uVar8;
  ulong uVar9;
  ulong uVar10;
  
  uVar10 = param_3 + 0xfffU >> 0xc;
  if (0 < (int)uVar10) {
    uVar9 = uVar10 & 0xffffffff;
    do {
      uVar8 = (uint)uVar9;
      uVar6 = uVar8;
      if (0xff < uVar8) {
        uVar6 = 0x100;
      }
      uVar7 = (ulong)uVar6;
      lVar3 = bio_alloc_bioset(param_1,uVar7,0,0xcc0,&fs_bio_set);
      if (lVar3 == 0) {
        return;
      }
      iVar2 = (int)uVar10 - uVar8;
      *(ulong *)(lVar3 + 0x20) = (((param_5 >> 0xc) + (uVar10 & 0xffffffff)) - uVar9) * 8;
      *(undefined4 *)(lVar3 + 0x10) = param_4;
      uVar9 = uVar7;
      do {
        lVar5 = param_2 + (long)iVar2 * 0x1000;
        uVar4 = is_vmalloc_addr(lVar5);
        if ((uVar4 & 1) == 0) {
          lVar5 = ((lVar5 * 0x100 >> 8) + 0x8000000000U >> 0xc) * 0x40 + -0x200000000;
        }
        else {
          lVar5 = vmalloc_to_page(lVar5);
        }
        iVar1 = bio_add_page(lVar3,lVar5,0x1000,0);
        if (iVar1 == 0) {
          bio_put(lVar3);
          return;
        }
        uVar9 = uVar9 - 1;
        iVar2 = iVar2 + 1;
      } while (uVar9 != 0);
      iVar2 = submit_bio_wait(lVar3);
      if (iVar2 != 0) {
        _printk(&DAT_001015e5,"bk_submit_bio",uVar7,param_4,iVar2);
      }
      bio_put(lVar3);
      uVar9 = (ulong)(uVar8 - uVar6);
    } while (0 < (int)(uVar8 - uVar6));
  }
  return;
}



//------------------------------------------------------------
// bk_console_write @ 00100c04 size=272
// signature: undefined bk_console_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bk_console_write(undefined8 param_1,void *param_2,uint param_3)

{
  undefined8 *puVar1;
  long lVar2;
  long lVar3;
  undefined8 *puVar4;
  void *__dest;
  ulong uVar5;
  long *plVar6;
  
  if (((param_3 != 0) && (bklog != 0)) && (*(char *)(bklog + 0x21) == '\0')) {
    puVar4 = (undefined8 *)kmalloc_trace(_kthread_create_on_node,0x8b20,0x20);
    if (puVar4 != (undefined8 *)0x0) {
      __dest = (void *)__kmalloc((ulong)param_3,0x8b20);
      *puVar4 = __dest;
      if (__dest != (void *)0x0) {
        memcpy(__dest,param_2,(ulong)param_3);
        lVar2 = bklog;
        *(uint *)(puVar4 + 1) = param_3;
        _raw_spin_lock(lVar2 + 0x80);
        lVar3 = bklog;
        puVar1 = puVar4 + 2;
        plVar6 = *(long **)(bklog + 0x68);
        lVar2 = bklog + 0x60;
        uVar5 = __list_add_valid(puVar1,plVar6,lVar2);
        if ((uVar5 & 1) != 0) {
          *(undefined8 **)(lVar3 + 0x68) = puVar1;
          puVar4[2] = lVar2;
          puVar4[3] = plVar6;
          *plVar6 = (long)puVar1;
        }
        lVar2 = bklog + 0x80;
        uVar5 = *(long *)(bklog + 0x48) + (ulong)*(uint *)(puVar4 + 1);
        *(ulong *)(bklog + 0x48) = uVar5;
        _raw_spin_unlock(lVar2);
        if (0x19000 < uVar5) {
          __wake_up(bklog + 0x88,3,1,0);
        }
      }
    }
  }
  return;
}



//------------------------------------------------------------
// bk_reboot @ 00100d18 size=200
// signature: undefined bk_reboot(void)
// callers: []
//------------------------------------------------------------

undefined8 bk_reboot(void)

{
  bool bVar1;
  uint uVar2;
  long lVar3;
  
  if ((bklog != 0) && (*(char *)(bklog + 0x21) == '\0')) {
    _printk(&DAT_001012f9,"bk_reboot");
    lVar3 = bklog + 0x88;
    *(undefined1 *)(bklog + 0x20) = 1;
    __wake_up(lVar3,3,1,0);
    if (*(long *)(bklog + 0x48) != 0) {
      uVar2 = (int)(*(long *)(bklog + 0x48) + 0xfffU >> 0xc) * 10;
      if ((int)uVar2 < 0x65) {
        uVar2 = 100;
      }
      _printk(&DAT_001013d6,"force_flush_logs",(ulong)uVar2);
      lVar3 = -(ulong)uVar2;
      do {
        __const_udelay(0x418958);
        bVar1 = lVar3 != -1;
        lVar3 = lVar3 + 1;
      } while (bVar1);
    }
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00100de4 size=704
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void init_module(void)

{
  long lVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  ulong uVar5;
  undefined8 uVar6;
  undefined4 local_4c;
  int local_48;
  char cStack_44;
  ulong local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  _local_48 = 0;
  local_40 = 0;
  iVar3 = get_bootargs("androidboot.dump_bklog=",&local_48,0x20);
  if (iVar3 == 0) {
LAB_00100e4c:
    iVar3 = get_bootargs("androidboot.bklog_part=",&local_48,0x20);
    if (((iVar3 != 0) && ((char)local_48 != '\0')) ||
       ((iVar3 = get_bootargs("androidboot.bklog_cycle=",&local_48,0x20), iVar3 != 0 &&
        ((char)local_48 != '\0')))) goto LAB_00100e8c;
    _printk(&DAT_00101644,"bk_log_init");
LAB_00101030:
    uVar6 = 0;
  }
  else {
    if ((local_48 != 0x65757274 || cStack_44 != '\0') && ((short)local_48 != 0x31))
    goto LAB_00100e4c;
LAB_00100e8c:
    puVar4 = (undefined8 *)kmalloc_trace(_strscpy,0xdc0,0xa0);
    bklog = puVar4;
    if (puVar4 != (undefined8 *)0x0) {
      *(undefined1 *)(puVar4 + 4) = 0;
      local_38 = 0;
      uStack_30 = 0;
      _local_48 = 0;
      local_40 = 0;
      iVar3 = get_bootargs("androidboot.bklog_part=",&local_48,0x20);
      puVar2 = bklog;
      if (iVar3 == 0) {
        uVar6 = CONCAT71(s_PARTLABEL_logks_00101674._8_7_,s_PARTLABEL_logks_00101674[7]);
        *bklog = CONCAT17(s_PARTLABEL_logks_00101674[7],s_PARTLABEL_logks_00101674._0_7_);
        *(undefined8 *)((long)puVar2 + 7) = uVar6;
      }
      else {
        strscpy(puVar4,"PARTLABEL=",0xb);
        strlcat(puVar4,&local_48,0x16);
      }
      local_40 = local_40 & 0xffffffffffff0000;
      _local_48 = 0;
      local_4c = 0;
      iVar3 = get_bootargs("androidboot.bklog_cycle=",&local_48,10);
      puVar4 = bklog;
      if (iVar3 == 0) {
        *(undefined1 *)((long)bklog + 0x22) = 0;
LAB_00100f6c:
        *(undefined1 *)((long)puVar4 + 0x22) = 5;
      }
      else {
        sscanf((char *)&local_48,"%d\n",&local_4c);
        puVar4 = bklog;
        *(char *)((long)bklog + 0x22) = (char)local_4c;
        if ((char)local_4c == '\0') goto LAB_00100f6c;
      }
      puVar4[0xc] = puVar4 + 0xc;
      puVar4[0xd] = puVar4 + 0xc;
      __init_waitqueue_head(puVar4 + 0x11,"&bklog->log_wq",&bk_log_init___key);
      puVar4 = bklog;
      *(undefined4 *)(bklog + 0x10) = 0;
      uVar5 = kthread_create_on_node(store_work_thread,puVar4,0xffffffff,"store_bklog");
      if (uVar5 < 0xfffffffffffff001) {
        wake_up_process(uVar5);
        bklog[0xe] = uVar5;
        strscpy(&bk_console,"bklog",6);
        DAT_001016d0 = 0x15;
        register_console(&bk_console);
        register_reboot_notifier(&bk_reboot_notify);
        register_die_notifier(&bk_die_notify);
        tracepoint_probe_register(&__tracepoint_android_vh_sysrq_crash,sysrq_crash,0);
        goto LAB_00101030;
      }
      bklog[0xe] = uVar5;
      _printk(&DAT_00101392,"bk_log_init");
      kfree(bklog);
    }
    uVar6 = 0xfffffff4;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001010a8 size=328
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  
  if (bklog != 0) {
    plVar4 = (long *)(bklog + 0x70);
    *(undefined1 *)(bklog + 0x21) = 1;
    if (*plVar4 != 0) {
      kthread_stop();
    }
    unregister_console(&bk_console);
    unregister_reboot_notifier(&bk_reboot_notify);
    unregister_die_notifier(&bk_die_notify);
    tracepoint_probe_unregister(&__tracepoint_android_vh_sysrq_crash,sysrq_crash,0);
    lVar3 = bklog;
    if (*(long *)(bklog + 0x78) != 0) {
      blkdev_put(*(long *)(bklog + 0x78),0x83);
      lVar3 = bklog;
      *(undefined8 *)(bklog + 0x78) = 0;
    }
    _raw_spin_lock(lVar3 + 0x80);
    plVar4 = *(long **)(bklog + 0x60);
    if (plVar4 != (long *)(bklog + 0x60)) {
      do {
        plVar5 = (long *)*plVar4;
        uVar2 = __list_del_entry_valid(plVar4);
        if ((uVar2 & 1) != 0) {
          lVar3 = *plVar4;
          plVar1 = (long *)plVar4[1];
          *(long **)(lVar3 + 8) = plVar1;
          *plVar1 = lVar3;
        }
        *plVar4 = -0x2152ffffffffff00;
        plVar4[1] = (long)&DAT_dead000000000122;
        kfree(plVar4[-2]);
        kfree(plVar4 + -2);
        plVar4 = plVar5;
      } while (plVar5 != (long *)(bklog + 0x60));
    }
    _raw_spin_unlock(bklog + 0x80);
    lVar3 = bklog;
    if (*(long *)(bklog + 0x28) != 0) {
      vfree(*(long *)(bklog + 0x28));
      lVar3 = bklog;
      *(undefined8 *)(bklog + 0x28) = 0;
    }
    if (lVar3 != 0) {
      kfree();
      bklog = 0;
    }
  }
  return;
}



//------------------------------------------------------------
// kmalloc_trace @ 00103008 size=1
// signature: undefined kmalloc_trace(void)
// callers: [bk_console_write, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00103010 size=1
// signature: undefined strscpy(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlcat @ 00103018 size=1
// signature: undefined strlcat(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcat(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 00103020 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [init_module, store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00103028 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_create_on_node @ 00103030 size=1
// signature: undefined kthread_create_on_node(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_create_on_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wake_up_process @ 00103038 size=1
// signature: undefined wake_up_process(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wake_up_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_console @ 00103040 size=1
// signature: undefined register_console(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_console(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_reboot_notifier @ 00103048 size=1
// signature: undefined register_reboot_notifier(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_reboot_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_die_notifier @ 00103050 size=1
// signature: undefined register_die_notifier(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_die_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 00103060 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103068 size=1
// signature: undefined _printk(void)
// callers: [bk_reboot, rw_bdev, init_module, sysrq_crash, store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00103070 size=1
// signature: undefined kfree(void)
// callers: [cleanup_module, init_module, get_bootargs, store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103078 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [init_module, get_bootargs, store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_stop @ 00103080 size=1
// signature: undefined kthread_stop(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_console @ 00103088 size=1
// signature: undefined unregister_console(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_console(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_reboot_notifier @ 00103090 size=1
// signature: undefined unregister_reboot_notifier(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_reboot_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_die_notifier @ 00103098 size=1
// signature: undefined unregister_die_notifier(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_die_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_unregister @ 001030a0 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blkdev_put @ 001030a8 size=1
// signature: undefined blkdev_put(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blkdev_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 001030b0 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [cleanup_module, bk_console_write, store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001030b8 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [cleanup_module, store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 001030c0 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [cleanup_module, bk_console_write, store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vfree @ 001030c8 size=1
// signature: undefined vfree(void)
// callers: [cleanup_module, store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vzalloc @ 001030d8 size=1
// signature: undefined vzalloc(void)
// callers: [store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vzalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sprintf @ 001030e0 size=1
// signature: int sprintf(char * __s, char * __format, ...)
// callers: [store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_should_stop @ 001030e8 size=1
// signature: undefined kthread_should_stop(void)
// callers: [store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_should_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 001030f0 size=1
// signature: undefined init_wait_entry(void)
// callers: [store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 001030f8 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 00103100 size=1
// signature: undefined schedule_timeout(void)
// callers: [store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 00103108 size=1
// signature: undefined finish_wait(void)
// callers: [store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00103110 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [bk_console_write, get_bootargs, store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// name_to_dev_t @ 00103118 size=1
// signature: undefined name_to_dev_t(void)
// callers: [store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void name_to_dev_t(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00103120 size=1
// signature: undefined __const_udelay(void)
// callers: [bk_reboot, sysrq_crash, store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blkdev_get_by_dev @ 00103128 size=1
// signature: undefined blkdev_get_by_dev(void)
// callers: [store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blkdev_get_by_dev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00103130 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// jiffies_to_msecs @ 00103138 size=1
// signature: undefined jiffies_to_msecs(void)
// callers: [store_work_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void jiffies_to_msecs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 00103140 size=1
// signature: undefined __wake_up(void)
// callers: [bk_reboot, bk_console_write, sysrq_crash]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_opts_by_path @ 00103148 size=1
// signature: undefined of_find_node_opts_by_path(void)
// callers: [get_bootargs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_opts_by_path(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00103150 size=1
// signature: undefined of_property_read_string(void)
// callers: [get_bootargs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00103158 size=1
// signature: size_t strlen(char * __s)
// callers: [get_bootargs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00103160 size=1
// signature: undefined __kmalloc(void)
// callers: [bk_console_write, get_bootargs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlcpy @ 00103168 size=1
// signature: undefined strlcpy(void)
// callers: [get_bootargs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 00103170 size=1
// signature: undefined strnstr(void)
// callers: [get_bootargs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 00103178 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [get_bootargs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bio_alloc_bioset @ 00103188 size=1
// signature: undefined bio_alloc_bioset(void)
// callers: [rw_bdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bio_alloc_bioset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// is_vmalloc_addr @ 00103190 size=1
// signature: undefined is_vmalloc_addr(void)
// callers: [rw_bdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void is_vmalloc_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmalloc_to_page @ 00103198 size=1
// signature: undefined vmalloc_to_page(void)
// callers: [rw_bdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmalloc_to_page(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bio_add_page @ 001031a0 size=1
// signature: undefined bio_add_page(void)
// callers: [rw_bdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bio_add_page(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// submit_bio_wait @ 001031a8 size=1
// signature: undefined submit_bio_wait(void)
// callers: [rw_bdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void submit_bio_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bio_put @ 001031b0 size=1
// signature: undefined bio_put(void)
// callers: [rw_bdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bio_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001031b8 size=1
// signature: undefined __list_add_valid(void)
// callers: [bk_console_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



