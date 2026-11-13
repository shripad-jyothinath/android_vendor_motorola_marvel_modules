// Decompiled by Ghidra 12.2
// Program: qti_battery_debug.ko
// Image base: 00100000

//------------------------------------------------------------
// battery_dbg_probe @ 0010049c size=1276
// signature: undefined battery_dbg_probe(void)
// callers: []
//------------------------------------------------------------

ulong battery_dbg_probe(long param_1)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  long *plVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  long *plVar11;
  char *local_a0;
  undefined8 local_98;
  long *local_90;
  code *local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar1 = sp_el0;
  lVar7 = param_1 + 0x10;
  local_68 = *(long *)(lVar1 + 0x638);
  local_88 = (code *)0x0;
  uStack_80 = 0;
  local_98 = 0;
  local_90 = (long *)0x0;
  plVar5 = (long *)devm_kmalloc(lVar7,0x12b0,0xdc0);
  if (plVar5 == (long *)0x0) {
    uVar6 = 0xfffffff4;
    goto LAB_00100954;
  }
  *plVar5 = lVar7;
  local_a0 = "battery_debug";
  local_98 = CONCAT44(local_98._4_4_,0x800d);
  local_88 = battery_dbg_callback;
  local_90 = plVar5;
  uVar6 = pmic_glink_register_client(lVar7,&local_a0);
  plVar5[1] = uVar6;
  if (0xfffffffffffff000 < uVar6) {
    if ((int)uVar6 == -0x205) {
      uVar6 = 0xfffffdfb;
    }
    else {
      _dev_err(*plVar5,"Error in registering with pmic_glink %d\n",uVar6 & 0xffffffff);
    }
    goto LAB_00100954;
  }
  plVar11 = plVar5 + 2;
  __mutex_init(plVar11,"&bd->lock",&battery_dbg_probe___key);
  *(undefined4 *)(plVar5 + 8) = 0;
  __init_swait_queue_head(plVar5 + 9,"&x->wait",&init_completion___key);
  lVar7 = *plVar5;
  *(long **)(param_1 + 0xa8) = plVar5;
  plVar5[0x20f] = (long)(plVar5 + 0xe);
  plVar5[0x210] = 0;
  uVar3 = sysfs_create_group(lVar7,battery_dbg_group);
  if (uVar3 != 0) {
    uVar6 = (ulong)uVar3;
    _dev_err(*plVar5,"Failed to create sysfs files for qbg_context: %d\n",uVar6);
    if ((int)uVar3 < 0) {
      pmic_glink_unregister_client(plVar5[1]);
      goto LAB_00100954;
    }
  }
  uVar8 = debugfs_create_dir("battery_debug",0);
  if (0xfffffffffffff000 < uVar8) {
    _printk(&DAT_001024c2,"battery_dbg_add_debugfs",uVar8 & 0xffffffff);
    uVar6 = 0;
    goto LAB_00100954;
  }
  uVar6 = debugfs_create_dir("votables",uVar8);
  if (uVar6 < 0xfffffffffffff001) {
    local_78 = 0x10000800d;
    uStack_70 = 0x15;
    mutex_lock(plVar11);
    *(undefined4 *)(plVar5 + 8) = 0;
    uVar3 = pmic_glink_write(plVar5[1],&local_78,0x10);
    if (uVar3 == 0) {
      iVar4 = wait_for_completion_timeout(plVar5 + 8,0xfa);
      if (iVar4 != 0) {
        mutex_unlock(plVar11);
        uVar3 = *(uint *)(plVar5 + 0x211);
        lVar7 = devm_kmalloc(*plVar5,(ulong)uVar3 * 0xd0,0xdc0);
        plVar5[0x254] = lVar7;
        if (lVar7 == 0) {
          uVar10 = 0xfffffff4;
          goto LAB_00100918;
        }
        if (uVar3 != 0) {
          iVar4 = 0;
          lVar7 = 0;
          plVar11 = plVar5 + 0x212;
          do {
            *(long **)(plVar5[0x254] + lVar7 + 0x10) = plVar5;
            *(int *)(plVar5[0x254] + lVar7 + 8) = iVar4;
            if (lVar7 == 0xa90) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x100994);
              (*pcVar2)();
            }
            uVar9 = debugfs_create_dir(plVar11,uVar6);
            if (uVar9 < 0xfffffffffffff001) {
              *(long **)(plVar5[0x254] + lVar7) = plVar11;
              uVar10 = debugfs_create_file("active",0x100,uVar9,plVar5[0x254] + lVar7,&active_fops);
              if ((((0xfffffffffffff000 < uVar10) && ((uVar10 & 0xffffffff) != 0)) ||
                  ((uVar10 = debugfs_create_file("winvote",0x100,uVar9,plVar5[0x254] + lVar7,
                                                 &winvote_fops), 0xfffffffffffff000 < uVar10 &&
                   ((uVar10 & 0xffffffff) != 0)))) ||
                 ((((uVar10 = debugfs_create_file("winner",0x100,uVar9,plVar5[0x254] + lVar7,
                                                  &winner_fops), 0xfffffffffffff000 < uVar10 &&
                    ((uVar10 & 0xffffffff) != 0)) ||
                   ((uVar10 = debugfs_create_file("voters",0x100,uVar9,plVar5[0x254] + lVar7,
                                                  &voters_fops), 0xfffffffffffff000 < uVar10 &&
                    ((uVar10 & 0xffffffff) != 0)))) ||
                  (((uVar10 = debugfs_create_file("votes",0x100,uVar9,plVar5[0x254] + lVar7,
                                                  &votes_fops), 0xfffffffffffff000 < uVar10 &&
                    ((uVar10 & 0xffffffff) != 0)) ||
                   ((uVar10 = debugfs_create_file("status",0x100,uVar9,plVar5[0x254] + lVar7,
                                                  &status_fops), 0xfffffffffffff000 < uVar10 &&
                    ((uVar10 & 0xffffffff) != 0)))))))) {
                _printk(&DAT_00102924,"battery_dbg_create_votable",uVar10 & 0xffffffff);
                goto LAB_00100944;
              }
            }
            else {
              _printk(&DAT_0010287b,"battery_dbg_create_votable",plVar11);
              if ((int)uVar9 != 0) {
                uVar10 = uVar9 & 0xffffffff;
                goto LAB_00100944;
              }
            }
            lVar7 = lVar7 + 0xd0;
            plVar11 = (long *)((long)plVar11 + 0xc);
            iVar4 = iVar4 + 1;
          } while ((ulong)uVar3 * 0xd0 != lVar7);
        }
        goto LAB_00100948;
      }
      _printk(&DAT_0010275c,"battery_dbg_write");
      uVar10 = 0xffffff92;
    }
    else {
      uVar10 = (ulong)uVar3;
    }
    mutex_unlock(plVar11);
    _printk(&DAT_001026aa,"battery_dbg_create_votables",uVar10);
  }
  else {
    _printk(&DAT_0010256a,"battery_dbg_create_votables");
    uVar10 = uVar6 & 0xffffffff;
LAB_00100944:
    if ((int)uVar10 == 0) {
LAB_00100948:
      uVar6 = 0;
      plVar5[0x20e] = uVar8;
      goto LAB_00100954;
    }
  }
LAB_00100918:
  _printk(&DAT_00102849,"battery_dbg_add_debugfs",uVar10 & 0xffffffff);
  debugfs_remove(uVar8);
  uVar6 = 0;
LAB_00100954:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// battery_dbg_remove @ 0010099c size=112
// signature: undefined battery_dbg_remove(void)
// callers: []
//------------------------------------------------------------

int battery_dbg_remove(long param_1)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_1 + 0xa8);
  sysfs_remove_group(*puVar2,battery_dbg_group);
  debugfs_remove(puVar2[0x20e]);
  iVar1 = pmic_glink_unregister_client(puVar2[1]);
  if (iVar1 < 0) {
    _printk(&DAT_0010295e,"battery_dbg_remove",iVar1);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// battery_dbg_callback @ 00100a10 size=780
// signature: undefined battery_dbg_callback(void)
// callers: []
//------------------------------------------------------------

undefined8 battery_dbg_callback(long param_1,long param_2,ulong param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  char *pcVar5;
  ulong __n;
  long lVar6;
  
  __n = (ulong)*(uint *)(param_2 + 8);
  switch(*(uint *)(param_2 + 8)) {
  case 0x15:
    if (param_3 != 0x224) {
      _printk(&DAT_00102481,"handle_get_votables_list_message",0x224);
      return 0;
    }
    uVar2 = *(uint *)(param_2 + 0xc);
    if (0xb < uVar2) {
      puVar4 = &DAT_001025dd;
      pcVar5 = "handle_get_votables_list_message";
LAB_00100cc0:
      _printk(puVar4,pcVar5,uVar2,0xc);
      return 0;
    }
    uVar1 = *(uint *)(param_2 + 0x10);
    if (0x1f < uVar1) {
      puVar4 = &DAT_001026f1;
      pcVar5 = "handle_get_votables_list_message";
LAB_00100d10:
      _printk(puVar4,pcVar5,uVar1,0x20);
      return 0;
    }
    memcpy((void *)(param_1 + 0x1088),(uint *)(param_2 + 0xc),0x218);
    *(undefined1 *)(param_1 + 0x109b) = 0;
    *(undefined1 *)(param_1 + 0x10a7) = 0;
    *(undefined1 *)(param_1 + 0x10b3) = 0;
    *(undefined1 *)(param_1 + 0x10bf) = 0;
    *(undefined1 *)(param_1 + 0x10cb) = 0;
    *(undefined1 *)(param_1 + 0x10d7) = 0;
    *(undefined1 *)(param_1 + 0x10e3) = 0;
    *(undefined1 *)(param_1 + 0x10ef) = 0;
    *(undefined1 *)(param_1 + 0x10fb) = 0;
    *(undefined1 *)(param_1 + 0x1107) = 0;
    *(undefined1 *)(param_1 + 0x1113) = 0;
    *(undefined1 *)(param_1 + 0x111f) = 0;
    *(undefined1 *)(param_1 + 0x112b) = 0;
    *(undefined1 *)(param_1 + 0x1137) = 0;
    *(undefined1 *)(param_1 + 0x1143) = 0;
    *(undefined1 *)(param_1 + 0x114f) = 0;
    *(undefined1 *)(param_1 + 0x115b) = 0;
    *(undefined1 *)(param_1 + 0x1167) = 0;
    *(undefined1 *)(param_1 + 0x1173) = 0;
    *(undefined1 *)(param_1 + 0x117f) = 0;
    *(undefined1 *)(param_1 + 0x118b) = 0;
    *(undefined1 *)(param_1 + 0x1197) = 0;
    *(undefined1 *)(param_1 + 0x11a3) = 0;
    *(undefined1 *)(param_1 + 0x11af) = 0;
    *(undefined1 *)(param_1 + 0x11bb) = 0;
    *(undefined1 *)(param_1 + 0x11c7) = 0;
    *(undefined1 *)(param_1 + 0x11d3) = 0;
    *(undefined1 *)(param_1 + 0x11df) = 0;
    *(undefined1 *)(param_1 + 0x11eb) = 0;
    *(undefined1 *)(param_1 + 0x11f7) = 0;
    *(undefined1 *)(param_1 + 0x1203) = 0;
    *(undefined1 *)(param_1 + 0x120f) = 0;
    *(undefined1 *)(param_1 + 0x121b) = 0;
    *(undefined1 *)(param_1 + 0x1227) = 0;
    *(undefined1 *)(param_1 + 0x1233) = 0;
    *(undefined1 *)(param_1 + 0x123f) = 0;
    *(undefined1 *)(param_1 + 0x124b) = 0;
    *(undefined1 *)(param_1 + 0x1257) = 0;
    *(undefined1 *)(param_1 + 0x1263) = 0;
    *(undefined1 *)(param_1 + 0x126f) = 0;
    *(undefined1 *)(param_1 + 0x127b) = 0;
    *(undefined1 *)(param_1 + 0x1287) = 0;
    *(undefined1 *)(param_1 + 0x1293) = 0;
    *(undefined1 *)(param_1 + 0x129f) = 0;
    if (*(char *)(param_1 + 0x12a8) == '\0') {
      lVar6 = 0;
      pcVar5 = (char *)(param_1 + 0x1120);
      do {
        iVar3 = strcmp(pcVar5,"glink");
        if (iVar3 == 0) {
          *(char *)(param_1 + 0x12a8) = (char)lVar6;
          break;
        }
        lVar6 = lVar6 + 1;
        pcVar5 = pcVar5 + 0xc;
      } while (lVar6 != 0x20);
    }
    break;
  case 0x16:
    break;
  case 0x17:
    if (param_3 != 0xc0) {
      _printk(&DAT_00102481,"handle_get_votable_message",0xc0);
      return 0;
    }
    uVar2 = *(uint *)(param_2 + 0xc);
    if (0xb < uVar2) {
      puVar4 = &DAT_00102808;
      pcVar5 = "handle_get_votable_message";
      goto LAB_00100cc0;
    }
    if ((*(int *)(param_2 + 0xb4) != 0) && (uVar1 = *(uint *)(param_2 + 0xb8), 0x1f < uVar1)) {
      puVar4 = &DAT_001028eb;
      pcVar5 = "handle_get_votable_message";
      goto LAB_00100d10;
    }
    memcpy((void *)(*(long *)(param_1 + 0x12a0) + (ulong)uVar2 * 0xd0 + 0x18),
           (uint *)(param_2 + 0xc),0xb4);
    break;
  default:
    puVar4 = &DAT_001025ab;
    pcVar5 = "battery_dbg_callback";
LAB_00100ce0:
    _printk(puVar4,pcVar5,__n);
    return 0;
  case 0x36:
    if (0x1010 < param_3) {
      _printk(&DAT_001027c8,"handle_qbg_dump_message",param_3,0x1010);
      return 0;
    }
    __n = (ulong)*(uint *)(param_2 + 0xc);
    if (0x1000 < *(uint *)(param_2 + 0xc)) {
      puVar4 = &DAT_001023cf;
      pcVar5 = "handle_qbg_dump_message";
      goto LAB_00100ce0;
    }
    memcpy((void *)(param_1 + 0x70),(void *)(param_2 + 0x10),__n);
    *(ulong *)(param_1 + 0x1080) = __n;
    goto LAB_00100c08;
  }
LAB_00100c08:
  complete(param_1 + 0x40);
  return 0;
}



//------------------------------------------------------------
// battery_cell_id_show @ 00100d20 size=60
// signature: undefined battery_cell_id_show(void)
// callers: []
//------------------------------------------------------------

long battery_cell_id_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001024be,*(undefined4 *)(*(long *)(param_1 + 0x98) + 0x12ac)
                   );
  return (long)iVar1;
}



//------------------------------------------------------------
// battery_cell_id_store @ 00100d60 size=76
// signature: undefined battery_cell_id_store(void)
// callers: []
//------------------------------------------------------------

undefined8
battery_cell_id_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  iVar1 = kstrtouint(param_3,0,*(long *)(param_1 + 0x98) + 0x12ac);
  if (iVar1 != 0) {
    param_4 = 0xffffffffffffffea;
  }
  return param_4;
}



//------------------------------------------------------------
// qbg_blob_read @ 00100db0 size=104
// signature: undefined qbg_blob_read(void)
// callers: []
//------------------------------------------------------------

void qbg_blob_read(undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4,
                  undefined8 param_5,undefined8 param_6)

{
  long lVar1;
  undefined8 local_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_20 = param_5;
  memory_read_from_buffer
            (param_4,param_6,&local_20,*(undefined8 *)(*(long *)(param_2 + 0x98) + 0x1078),
             *(undefined8 *)(*(long *)(param_2 + 0x98) + 0x1080));
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qbg_blob_write @ 00100e1c size=240
// signature: undefined qbg_blob_write(void)
// callers: []
//------------------------------------------------------------

long qbg_blob_write(undefined8 param_1,long param_2)

{
  long lVar1;
  int iVar2;
  long in_x5;
  long lVar3;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 uStack_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  lVar3 = *(long *)(param_2 + 0x98);
  lVar1 = lVar3 + 0x10;
  uStack_3c = *(undefined4 *)(lVar3 + 0x12ac);
  local_48 = 0x10000800d;
  local_40 = 0x36;
  mutex_lock(lVar1);
  *(undefined4 *)(lVar3 + 0x40) = 0;
  iVar2 = pmic_glink_write(*(undefined8 *)(lVar3 + 8),&local_48,0x10);
  if (iVar2 == 0) {
    iVar2 = wait_for_completion_timeout((undefined4 *)(lVar3 + 0x40),0xfa);
    if (iVar2 == 0) {
      _printk(&DAT_0010275c,"battery_dbg_write");
      mutex_unlock(lVar1);
      in_x5 = -0x6e;
    }
    else {
      mutex_unlock(lVar1);
    }
  }
  else {
    mutex_unlock(lVar1);
    if (iVar2 < 0) {
      in_x5 = (long)iVar2;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return in_x5;
}



//------------------------------------------------------------
// active_open @ 00100f10 size=48
// signature: undefined active_open(void)
// callers: []
//------------------------------------------------------------

void active_open(long param_1,undefined8 param_2)

{
  single_open(param_2,active_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// active_show @ 00100f44 size=288
// signature: undefined active_show(void)
// callers: []
//------------------------------------------------------------

int active_show(long param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 uStack_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  puVar4 = *(undefined8 **)(param_1 + 0x80);
  lVar3 = puVar4[2];
  local_58 = 0x10000800d;
  uStack_4c = *(undefined4 *)(puVar4 + 1);
  lVar1 = lVar3 + 0x10;
  local_50 = 0x17;
  mutex_lock(lVar1);
  *(undefined4 *)(lVar3 + 0x40) = 0;
  iVar2 = pmic_glink_write(*(undefined8 *)(lVar3 + 8),&local_58,0x10);
  if (iVar2 == 0) {
    iVar2 = wait_for_completion_timeout((undefined4 *)(lVar3 + 0x40),0xfa);
    if (iVar2 != 0) {
      mutex_unlock(lVar1);
      seq_printf(param_1,&DAT_00102740,*(undefined4 *)(puVar4 + 0x18));
      iVar2 = 0;
      goto LAB_00100fe4;
    }
    _printk(&DAT_0010275c,"battery_dbg_write");
    iVar2 = -0x6e;
  }
  mutex_unlock(lVar1);
  _printk(&DAT_001023ff,"active_show",*puVar4,iVar2);
LAB_00100fe4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// winvote_open @ 00101068 size=48
// signature: undefined winvote_open(void)
// callers: []
//------------------------------------------------------------

void winvote_open(long param_1,undefined8 param_2)

{
  single_open(param_2,winvote_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// winvote_show @ 0010109c size=304
// signature: undefined winvote_show(void)
// callers: []
//------------------------------------------------------------

int winvote_show(long param_1)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 uStack_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  puVar5 = *(undefined8 **)(param_1 + 0x80);
  lVar4 = puVar5[2];
  local_58 = 0x10000800d;
  uStack_4c = *(undefined4 *)(puVar5 + 1);
  lVar1 = lVar4 + 0x10;
  local_50 = 0x17;
  mutex_lock(lVar1);
  *(undefined4 *)(lVar4 + 0x40) = 0;
  iVar2 = pmic_glink_write(*(undefined8 *)(lVar4 + 8),&local_58,0x10);
  if (iVar2 == 0) {
    iVar2 = wait_for_completion_timeout((undefined4 *)(lVar4 + 0x40),0xfa);
    if (iVar2 != 0) {
      mutex_unlock(lVar1);
      if (*(int *)(puVar5 + 0x18) == 0) {
        uVar3 = 0xffffffea;
      }
      else {
        uVar3 = *(undefined4 *)((long)puVar5 + 0x1c);
      }
      seq_printf(param_1,&DAT_001025a7,uVar3);
      iVar2 = 0;
      goto LAB_0010114c;
    }
    _printk(&DAT_0010275c,"battery_dbg_write");
    iVar2 = -0x6e;
  }
  mutex_unlock(lVar1);
  _printk(&DAT_001023ff,"winvote_show",*puVar5,iVar2);
LAB_0010114c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// winner_open @ 001011d0 size=48
// signature: undefined winner_open(void)
// callers: []
//------------------------------------------------------------

void winner_open(long param_1,undefined8 param_2)

{
  single_open(param_2,winner_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// winner_show @ 00101204 size=328
// signature: undefined winner_show(void)
// callers: []
//------------------------------------------------------------

int winner_show(long param_1)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  undefined8 *puVar4;
  long lVar5;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 uStack_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  puVar4 = *(undefined8 **)(param_1 + 0x80);
  lVar5 = puVar4[2];
  local_58 = 0x10000800d;
  uStack_4c = *(undefined4 *)(puVar4 + 1);
  lVar1 = lVar5 + 0x10;
  local_50 = 0x17;
  mutex_lock(lVar1);
  *(undefined4 *)(lVar5 + 0x40) = 0;
  iVar2 = pmic_glink_write(*(undefined8 *)(lVar5 + 8),&local_58,0x10);
  if (iVar2 == 0) {
    iVar2 = wait_for_completion_timeout((undefined4 *)(lVar5 + 0x40),0xfa);
    if (iVar2 != 0) {
      mutex_unlock(lVar1);
      if (*(int *)(puVar4 + 0x18) == 0) {
        puVar3 = &DAT_00102642;
      }
      else {
        puVar3 = (undefined *)(lVar5 + (ulong)*(uint *)((long)puVar4 + 0xc4) * 0xc + 0x1120);
      }
      seq_printf(param_1,&DAT_00102734,puVar3);
      iVar2 = 0;
      goto LAB_001012cc;
    }
    _printk(&DAT_0010275c,"battery_dbg_write");
    iVar2 = -0x6e;
  }
  mutex_unlock(lVar1);
  _printk(&DAT_001023ff,"winner_show",*puVar4,iVar2);
LAB_001012cc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// voters_open @ 00101350 size=48
// signature: undefined voters_open(void)
// callers: []
//------------------------------------------------------------

void voters_open(long param_1,undefined8 param_2)

{
  single_open(param_2,voters_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// voters_show @ 00101384 size=396
// signature: undefined voters_show(void)
// callers: []
//------------------------------------------------------------

int voters_show(long param_1)

{
  long lVar1;
  uint uVar2;
  ulong uVar4;
  ulong uVar3;
  int iVar5;
  ulong uVar6;
  long lVar7;
  undefined8 *puVar8;
  undefined8 local_78;
  undefined4 local_70;
  undefined4 uStack_6c;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  puVar8 = *(undefined8 **)(param_1 + 0x80);
  lVar7 = puVar8[2];
  local_78 = 0x10000800d;
  uStack_6c = *(undefined4 *)(puVar8 + 1);
  lVar1 = lVar7 + 0x10;
  local_70 = 0x17;
  mutex_lock(lVar1);
  *(undefined4 *)(lVar7 + 0x40) = 0;
  iVar5 = pmic_glink_write(*(undefined8 *)(lVar7 + 8),&local_78,0x10);
  if (iVar5 == 0) {
    iVar5 = wait_for_completion_timeout((undefined4 *)(lVar7 + 0x40),0xfa);
    if (iVar5 != 0) {
      mutex_unlock(lVar1);
      uVar6 = 0;
      uVar2 = *(uint *)(puVar8 + 0x18);
      do {
        uVar6 = -1L << (uVar6 & 0x3f) & (ulong)uVar2;
        uVar3 = (uVar6 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar6 & 0x5555555555555555) << 1;
        uVar3 = (uVar3 & 0xcccccccccccccccc) >> 2 | (uVar3 & 0x3333333333333333) << 2;
        uVar3 = (uVar3 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar3 & 0xf0f0f0f0f0f0f0f) << 4;
        uVar4 = (uVar3 & 0xff00ff00ff00ff00) >> 8 | (uVar3 & 0xff00ff00ff00ff) << 8;
        uVar3 = 0x20;
        if (uVar6 != 0) {
          uVar3 = LZCOUNT((uVar4 >> 0x10 | (uVar4 & 0xffff0000ffff) << 0x10) << 0x20);
        }
        if (0x1f < uVar3) break;
        seq_printf(param_1,&DAT_0010267b,lVar7 + uVar3 * 0xc + 0x1120);
        uVar6 = uVar3 + 1;
      } while (uVar3 != 0x1f);
      seq_puts(param_1,&DAT_001027ac);
      iVar5 = 0;
      goto LAB_00101488;
    }
    _printk(&DAT_0010275c,"battery_dbg_write");
    iVar5 = -0x6e;
  }
  mutex_unlock(lVar1);
  _printk(&DAT_001023ff,"voters_show",*puVar8,iVar5);
LAB_00101488:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// votes_open @ 00101514 size=48
// signature: undefined votes_open(void)
// callers: []
//------------------------------------------------------------

void votes_open(long param_1,undefined8 param_2)

{
  single_open(param_2,votes_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// votes_show @ 00101548 size=376
// signature: undefined votes_show(void)
// callers: []
//------------------------------------------------------------

int votes_show(long param_1)

{
  long lVar1;
  uint uVar2;
  ulong uVar4;
  ulong uVar3;
  int iVar5;
  ulong uVar6;
  long lVar7;
  undefined8 *puVar8;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 uStack_5c;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  puVar8 = *(undefined8 **)(param_1 + 0x80);
  lVar7 = puVar8[2];
  local_68 = 0x10000800d;
  uStack_5c = *(undefined4 *)(puVar8 + 1);
  lVar1 = lVar7 + 0x10;
  local_60 = 0x17;
  mutex_lock(lVar1);
  *(undefined4 *)(lVar7 + 0x40) = 0;
  iVar5 = pmic_glink_write(*(undefined8 *)(lVar7 + 8),&local_68,0x10);
  if (iVar5 == 0) {
    iVar5 = wait_for_completion_timeout((undefined4 *)(lVar7 + 0x40),0xfa);
    if (iVar5 != 0) {
      mutex_unlock(lVar1);
      uVar6 = 0;
      uVar2 = *(uint *)(puVar8 + 0x18);
      do {
        uVar6 = -1L << (uVar6 & 0x3f) & (ulong)uVar2;
        uVar3 = (uVar6 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar6 & 0x5555555555555555) << 1;
        uVar3 = (uVar3 & 0xcccccccccccccccc) >> 2 | (uVar3 & 0x3333333333333333) << 2;
        uVar3 = (uVar3 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar3 & 0xf0f0f0f0f0f0f0f) << 4;
        uVar4 = (uVar3 & 0xff00ff00ff00ff00) >> 8 | (uVar3 & 0xff00ff00ff00ff) << 8;
        uVar3 = 0x20;
        if (uVar6 != 0) {
          uVar3 = LZCOUNT((uVar4 >> 0x10 | (uVar4 & 0xffff0000ffff) << 0x10) << 0x20);
        }
        if (0x1f < uVar3) break;
        seq_printf(param_1,&DAT_0010295a,*(undefined4 *)((long)puVar8 + uVar3 * 4 + 0x40));
        uVar6 = uVar3 + 1;
      } while (uVar3 != 0x1f);
      seq_puts(param_1,&DAT_001027ac);
      iVar5 = 0;
      goto LAB_0010163c;
    }
    _printk(&DAT_0010275c,"battery_dbg_write");
    iVar5 = -0x6e;
  }
  mutex_unlock(lVar1);
  _printk(&DAT_001023ff,"votes_show",*puVar8,iVar5);
LAB_0010163c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// status_open @ 001016c4 size=48
// signature: undefined status_open(void)
// callers: []
//------------------------------------------------------------

void status_open(long param_1,undefined8 param_2)

{
  single_open(param_2,status_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// status_show @ 001016f8 size=484
// signature: undefined status_show(void)
// callers: []
//------------------------------------------------------------

int status_show(long param_1)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  ulong uVar6;
  ulong uVar5;
  int iVar7;
  ulong uVar8;
  undefined8 *puVar9;
  long lVar10;
  undefined8 local_78;
  undefined4 local_70;
  undefined4 uStack_6c;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  puVar9 = *(undefined8 **)(param_1 + 0x80);
  lVar10 = puVar9[2];
  local_78 = 0x10000800d;
  uStack_6c = *(undefined4 *)(puVar9 + 1);
  lVar1 = lVar10 + 0x10;
  local_70 = 0x17;
  mutex_lock(lVar1);
  *(undefined4 *)(lVar10 + 0x40) = 0;
  iVar7 = pmic_glink_write(*(undefined8 *)(lVar10 + 8),&local_78,0x10);
  if (iVar7 == 0) {
    iVar7 = wait_for_completion_timeout((undefined4 *)(lVar10 + 0x40),0xfa);
    if (iVar7 != 0) {
      mutex_unlock(lVar1);
      uVar2 = *(uint *)(puVar9 + 0x18);
      if (uVar2 == 0) {
        seq_puts(param_1,&DAT_001027ac);
      }
      else {
        uVar3 = *(uint *)((long)puVar9 + 0xc4);
        uVar8 = 0;
        uVar4 = *(undefined4 *)((long)puVar9 + 0x1c);
        do {
          uVar8 = -1L << (uVar8 & 0x3f) & (ulong)uVar2;
          uVar5 = (uVar8 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar8 & 0x5555555555555555) << 1;
          uVar5 = (uVar5 & 0xcccccccccccccccc) >> 2 | (uVar5 & 0x3333333333333333) << 2;
          uVar5 = (uVar5 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar5 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar6 = (uVar5 & 0xff00ff00ff00ff00) >> 8 | (uVar5 & 0xff00ff00ff00ff) << 8;
          uVar5 = 0x20;
          if (uVar8 != 0) {
            uVar5 = LZCOUNT((uVar6 >> 0x10 | (uVar6 & 0xffff0000ffff) << 0x10) << 0x20);
          }
          if (0x1f < uVar5) break;
          seq_printf(param_1,"           %-*s: %-*s: %d\n",0xc,*puVar9,0xc,
                     lVar10 + uVar5 * 0xc + 0x1120,*(undefined4 *)((long)puVar9 + uVar5 * 4 + 0x40))
          ;
          uVar8 = uVar5 + 1;
        } while (uVar5 != 0x1f);
        seq_printf(param_1,"EFFECTIVE: %-*s: %-*s: %d\n",0xc,*puVar9,0xc,
                   lVar10 + (ulong)uVar3 * 0xc + 0x1120,uVar4);
      }
      iVar7 = 0;
      goto LAB_00101854;
    }
    _printk(&DAT_0010275c,"battery_dbg_write");
    iVar7 = -0x6e;
  }
  mutex_unlock(lVar1);
  _printk(&DAT_001023ff,"status_show",*puVar9,iVar7);
LAB_00101854:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// init_module @ 001018e0 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&battery_dbg_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101910 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&battery_dbg_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00104000 size=1
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
// platform_driver_unregister @ 00104008 size=1
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
// devm_kmalloc @ 00104010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [battery_dbg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_register_client @ 00104018 size=1
// signature: undefined pmic_glink_register_client(void)
// callers: [battery_dbg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_register_client(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00104020 size=1
// signature: undefined __mutex_init(void)
// callers: [battery_dbg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00104028 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [battery_dbg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 00104030 size=1
// signature: undefined sysfs_create_group(void)
// callers: [battery_dbg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00104038 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [battery_dbg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00104040 size=1
// signature: undefined mutex_lock(void)
// callers: [voters_show, winner_show, winvote_show, qbg_blob_write, battery_dbg_probe, votes_show, status_show, active_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_write @ 00104048 size=1
// signature: undefined pmic_glink_write(void)
// callers: [voters_show, winner_show, winvote_show, qbg_blob_write, battery_dbg_probe, votes_show, status_show, active_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00104050 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [voters_show, winner_show, winvote_show, qbg_blob_write, battery_dbg_probe, votes_show, status_show, active_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104058 size=1
// signature: undefined mutex_unlock(void)
// callers: [voters_show, winner_show, winvote_show, qbg_blob_write, battery_dbg_probe, votes_show, status_show, active_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104060 size=1
// signature: undefined _printk(void)
// callers: [voters_show, winner_show, winvote_show, qbg_blob_write, battery_dbg_probe, votes_show, battery_dbg_remove, status_show, battery_dbg_callback, active_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00104068 size=1
// signature: undefined debugfs_create_file(void)
// callers: [battery_dbg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104070 size=1
// signature: undefined _dev_err(void)
// callers: [battery_dbg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_unregister_client @ 00104078 size=1
// signature: undefined pmic_glink_unregister_client(void)
// callers: [battery_dbg_probe, battery_dbg_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_unregister_client(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00104080 size=1
// signature: undefined debugfs_remove(void)
// callers: [battery_dbg_probe, battery_dbg_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104088 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [voters_show, winner_show, qbg_blob_read, winvote_show, qbg_blob_write, battery_dbg_probe, votes_show, status_show, active_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_group @ 00104090 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [battery_dbg_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00104098 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [battery_dbg_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001040a0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [battery_dbg_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 001040a8 size=1
// signature: undefined complete(void)
// callers: [battery_dbg_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 001040b0 size=1
// signature: undefined scnprintf(void)
// callers: [battery_cell_id_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 001040b8 size=1
// signature: undefined kstrtouint(void)
// callers: [battery_cell_id_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memory_read_from_buffer @ 001040c0 size=1
// signature: undefined memory_read_from_buffer(void)
// callers: [qbg_blob_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void memory_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 001040c8 size=1
// signature: undefined single_open(void)
// callers: [active_open, voters_open, votes_open, winner_open, winvote_open, status_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 001040d0 size=1
// signature: undefined seq_printf(void)
// callers: [voters_show, winner_show, winvote_show, votes_show, status_show, active_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 001040d8 size=1
// signature: undefined seq_puts(void)
// callers: [voters_show, votes_show, status_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



