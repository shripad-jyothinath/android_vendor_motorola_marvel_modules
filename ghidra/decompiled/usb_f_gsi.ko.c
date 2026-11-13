// Decompiled by Ghidra 12.2
// Program: usb_f_gsi.ko
// Image base: 00100000

//------------------------------------------------------------
// ipa_ready_callback @ 0010177c size=76
// signature: undefined ipa_ready_callback(void)
// callers: []
//------------------------------------------------------------

void ipa_ready_callback(undefined8 *param_1)

{
  DAT_0010b4b0 = param_1[1];
  DAT_0010b4b8 = param_1[2];
  ipa_ops = *param_1;
  DAT_0010b4d0 = param_1[5];
  DAT_0010b4d8 = param_1[6];
  DAT_0010b4c0 = param_1[3];
  DAT_0010b4c8 = param_1[4];
  complete_all(&wait_for_ipa_ready);
  return;
}



//------------------------------------------------------------
// init_module @ 001017cc size=596
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

ulong init_module(void)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  ipa_usb_wq = alloc_workqueue("k_ipa_usb",0xe,1);
  if (ipa_usb_wq == 0) {
    _printk(&DAT_0010d481,"fgsi_init");
    uVar3 = 0xfffffff4;
  }
  else {
    __mutex_init(inst_status,"&inst_status[i].gsi_lock",&fgsi_init___key);
    __mutex_init(0x10b530,"&inst_status[i].gsi_lock",&fgsi_init___key);
    __mutex_init(0x10b570,"&inst_status[i].gsi_lock",&fgsi_init___key);
    __mutex_init(0x10b5b0,"&inst_status[i].gsi_lock",&fgsi_init___key);
    __mutex_init(0x10b5f0,"&inst_status[i].gsi_lock",&fgsi_init___key);
    __mutex_init(0x10b630,"&inst_status[i].gsi_lock",&fgsi_init___key);
    __mutex_init(0x10b670,"&inst_status[i].gsi_lock",&fgsi_init___key);
    uVar3 = __class_create(&__this_module,"gsi_usb",&fgsi_init___key_6);
    if (uVar3 < 0xfffffffffffff001) {
      gsi_class = uVar3;
      uVar2 = alloc_chrdev_region(&local_3c,0,3,"gsi_usb");
      if (uVar2 == 0) {
        major = local_3c >> 0x14;
        debugfs = debugfs_create_dir("usb_gsi",0);
        if (debugfs != 0) {
          debugfs_create_file("remote_wakeup_enable",0x180,debugfs,inst_status,&fops_usb_gsi_rw);
          debugfs_create_file("remote_wakeup_interval",0x180,debugfs,inst_status,
                              &fops_usb_gsi_rw_timer);
          debugfs_create_bool("log_ctrl_packets",0x1a4,debugfs,&DAT_0010b6d0);
        }
        uVar3 = usb_function_register(&gsiusb_func);
        uVar3 = uVar3 & 0xffffffff;
      }
      else {
        uVar3 = (ulong)uVar2;
        _printk(&DAT_0010e9b7,"fgsi_init",uVar3);
        class_destroy(gsi_class);
        gsi_class = 0;
      }
    }
    else {
      gsi_class = 0;
      _printk(&DAT_0010c69d,"fgsi_init",uVar3 & 0xffffffff);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// usb_gsi_rw_write @ 00101a24 size=360
// signature: undefined usb_gsi_rw_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 usb_gsi_rw_write(undefined8 param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  char *pcVar6;
  char local_3c [4];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_3c[0] = '\0';
  lVar3 = get_connected_gsi();
  if (lVar3 != 0) {
    if (param_2 == 0) {
      uVar4 = *(undefined8 *)(lVar3 + 0x570);
      pcVar6 = "%s: buffer is Null.\n";
    }
    else {
      iVar2 = kstrtou8_from_user(param_2,param_3,0,local_3c);
      if (iVar2 != 0) {
        ipc_log_string(*(undefined8 *)(lVar3 + 0x570),"%s: Invalid value. err:%d\n",
                       "usb_gsi_rw_write",iVar2);
        _printk(&DAT_0010ce29,"usb_gsi_rw_write",iVar2);
        goto LAB_00101b1c;
      }
      if ((bool)*(char *)(lVar3 + 0x5b8) == (local_3c[0] != '\0')) {
        uVar4 = *(undefined8 *)(lVar3 + 0x570);
        if (local_3c[0] == '\0') {
          pcVar6 = "%s: RW already disabled\n";
        }
        else {
          pcVar6 = "%s: RW already enabled\n";
        }
      }
      else {
        *(bool *)(lVar3 + 0x5b8) = local_3c[0] != '\0';
        lVar1 = _jiffies;
        if (local_3c[0] == '\0') {
          del_timer_sync(lVar3 + 0x580);
          uVar4 = *(undefined8 *)(lVar3 + 0x570);
          pcVar6 = "%s: timer deleted\n";
        }
        else {
          lVar5 = __msecs_to_jiffies(*(undefined2 *)(lVar3 + 0x5ba));
          mod_timer(lVar3 + 0x580,lVar5 + lVar1);
          uVar4 = *(undefined8 *)(lVar3 + 0x570);
          pcVar6 = "%s: timer initialized\n";
        }
      }
    }
    ipc_log_string(uVar4,pcVar6,"usb_gsi_rw_write");
  }
LAB_00101b1c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// usb_gsi_rw_open @ 00101b90 size=48
// signature: undefined usb_gsi_rw_open(void)
// callers: []
//------------------------------------------------------------

void usb_gsi_rw_open(long param_1,undefined8 param_2)

{
  single_open(param_2,usb_gsi_rw_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// get_connected_gsi @ 00101bc0 size=208
// signature: undefined get_connected_gsi(void)
// callers: [usb_gsi_rw_timer_write, usb_gsi_rw_timer_show, usb_gsi_rw_write, usb_gsi_rw_show]
//------------------------------------------------------------

long get_connected_gsi(void)

{
  long lVar1;
  
  if (((((inst_status._56_8_ == 0) || (lVar1 = *(long *)(inst_status._56_8_ + 0xb8), lVar1 == 0)) ||
       (*(int *)(lVar1 + 0x108) == 0)) &&
      ((((((inst_status._120_8_ == 0 || (lVar1 = *(long *)(inst_status._120_8_ + 0xb8), lVar1 == 0))
          || (*(int *)(lVar1 + 0x108) == 0)) &&
         (((inst_status._184_8_ == 0 || (lVar1 = *(long *)(inst_status._184_8_ + 0xb8), lVar1 == 0))
          || (*(int *)(lVar1 + 0x108) == 0)))) &&
        (((inst_status._248_8_ == 0 || (lVar1 = *(long *)(inst_status._248_8_ + 0xb8), lVar1 == 0))
         || (*(int *)(lVar1 + 0x108) == 0)))) &&
       (((inst_status._312_8_ == 0 || (lVar1 = *(long *)(inst_status._312_8_ + 0xb8), lVar1 == 0))
        || (*(int *)(lVar1 + 0x108) == 0)))))) &&
     ((((inst_status._376_8_ == 0 || (lVar1 = *(long *)(inst_status._376_8_ + 0xb8), lVar1 == 0)) ||
       (*(int *)(lVar1 + 0x108) == 0)) &&
      (((inst_status._440_8_ == 0 || (lVar1 = *(long *)(inst_status._440_8_ + 0xb8), lVar1 == 0)) ||
       (*(int *)(lVar1 + 0x108) == 0)))))) {
    return 0;
  }
  return lVar1;
}



//------------------------------------------------------------
// usb_gsi_rw_show @ 00101c94 size=68
// signature: undefined usb_gsi_rw_show(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_gsi_rw_show(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = get_connected_gsi();
  if (lVar1 != 0) {
    seq_printf(param_1,&DAT_0010cc08,*(undefined1 *)(lVar1 + 0x5b8));
  }
  return 0;
}



//------------------------------------------------------------
// usb_gsi_rw_timer_write @ 00101cdc size=300
// signature: undefined usb_gsi_rw_timer_write(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_gsi_rw_timer_write(undefined8 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  ushort local_3c [2];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_3c[0] = 0;
  lVar2 = get_connected_gsi();
  if (lVar2 != 0) {
    if (param_2 == 0) {
      ipc_log_string(*(undefined8 *)(lVar2 + 0x570),"%s: buffer is NULL.\n","usb_gsi_rw_timer_write"
                    );
    }
    else {
      iVar1 = kstrtou16_from_user(param_2,param_3,0,local_3c);
      if (iVar1 == 0) {
        if (local_3c[0] - 0x2711 < 0xffffd8f0) {
          ipc_log_string(*(undefined8 *)(lVar2 + 0x570),"%s: value must be > 0 and < 10000.\n",
                         "usb_gsi_rw_timer_write");
          _printk(&DAT_0010d4be,"usb_gsi_rw_timer_write");
        }
        else {
          *(ushort *)(lVar2 + 0x5ba) = local_3c[0];
        }
      }
      else {
        ipc_log_string(*(undefined8 *)(lVar2 + 0x570),"%s: Invalid value. err:%d\n",
                       "usb_gsi_rw_timer_write",iVar1);
        _printk(&DAT_0010ce29,"usb_gsi_rw_timer_write",iVar1);
      }
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// usb_gsi_rw_timer_open @ 00101e0c size=48
// signature: undefined usb_gsi_rw_timer_open(void)
// callers: []
//------------------------------------------------------------

void usb_gsi_rw_timer_open(long param_1,undefined8 param_2)

{
  single_open(param_2,usb_gsi_rw_timer_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// usb_gsi_rw_timer_show @ 00101e40 size=68
// signature: undefined usb_gsi_rw_timer_show(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_gsi_rw_timer_show(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = get_connected_gsi();
  if (lVar1 != 0) {
    seq_printf(param_1,"%ums\n",*(undefined2 *)(lVar1 + 0x5ba));
  }
  return 0;
}



//------------------------------------------------------------
// gsi_alloc_inst @ 00101e88 size=112
// signature: undefined gsi_alloc_inst(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long gsi_alloc_inst(void)

{
  long lVar1;
  
  lVar1 = kmalloc_trace(_config_group_init_type_name,0xdc0,0xc0);
  if (lVar1 == 0) {
    lVar1 = -0xc;
  }
  else {
    *(code **)(lVar1 + 0xa8) = gsi_set_inst_name;
    *(code **)(lVar1 + 0xb0) = gsi_free_inst;
    config_group_init_type_name(lVar1,&DAT_0010cf0c,&gsi_func_type);
  }
  return lVar1;
}



//------------------------------------------------------------
// gsi_alloc @ 00101efc size=324
// signature: undefined gsi_alloc(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_alloc(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined *puVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0xb8);
  uVar1 = *(uint *)(puVar4 + 0x1b);
  if (puVar4 != (undefined8 *)0x0) {
    ipc_log_string(puVar4[0xae],"%s: prot id %d","gsi_bind_config",uVar1);
  }
  if ((uVar1 < 7) && ((0x5fU >> (ulong)(uVar1 & 0x1f) & 1) != 0)) {
    puVar3 = (&PTR_rndis_gsi_strings_0010b308)[(int)uVar1];
    *puVar4 = (&PTR_s_rndis_0010b2d0)[(int)uVar1];
    puVar4[1] = puVar3;
    puVar4[9] = gsi_bind;
    puVar4[10] = gsi_unbind;
    puVar4[0xd] = gsi_set_alt;
    puVar4[0xe] = gsi_get_alt;
    puVar4[0xf] = gsi_disable;
    puVar4[0x10] = gsi_setup;
    puVar4[0xb] = gsi_free_func;
    puVar4[0x14] = gsi_get_status;
    puVar4[0x15] = gsi_func_suspend;
    puVar4[0x12] = gsi_suspend;
    puVar4[0x13] = gsi_resume;
    uVar2 = *(undefined8 *)(param_1 + 0xb8);
  }
  else if (puVar4 == (undefined8 *)0x0) {
    uVar2 = 0xffffffffffffffea;
  }
  else {
    ipc_log_string(puVar4[0xae],"%s: invalid prot id %d","gsi_bind_config",uVar1);
    _printk(&DAT_0010d3a1,"gsi_bind_config",uVar1);
    uVar2 = 0xffffffffffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// gsi_set_inst_name @ 00102044 size=1248
// signature: undefined gsi_set_inst_name(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong gsi_set_inst_name(undefined8 *param_1,char *param_2)

{
  long lVar1;
  undefined1 *puVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  size_t sVar8;
  ulong uVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined6 uStack_78;
  undefined2 local_72;
  undefined6 uStack_70;
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  uStack_70 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_72 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_98 = 0;
  sVar8 = strlen(param_2);
  if (0x28 < (int)sVar8 + 1) {
    uVar10 = 0xffffffdc;
    goto LAB_001023d0;
  }
  if (param_2 == (char *)0x0) {
LAB_00102168:
    _printk(&DAT_0010dc47,"gsi_set_inst_name",param_2);
    uVar10 = 0xffffffea;
    goto LAB_001023d0;
  }
  iVar4 = strncasecmp(param_2,"rndis",5);
  if (iVar4 == 0) {
    lVar11 = 0;
  }
  else {
    iVar5 = strncasecmp(param_2,"ecm",3);
    if (iVar5 == 0) {
      lVar11 = 1;
    }
    else {
      iVar5 = strncasecmp(param_2,"rmnet",5);
      if (iVar5 == 0) {
        lVar11 = 2;
      }
      else {
        iVar5 = strncasecmp(param_2,"mbim",4);
        if (iVar5 == 0) {
          lVar11 = 3;
        }
        else {
          iVar5 = strncasecmp(param_2,"dpl",3);
          if (iVar5 == 0) {
            lVar11 = 4;
          }
          else {
            iVar5 = strncasecmp(param_2,"ncm",3);
            if (iVar5 != 0) goto LAB_00102168;
            lVar11 = 6;
          }
        }
      }
    }
  }
  puVar2 = inst_status + lVar11 * 0x40;
  mutex_lock(puVar2);
  lVar12 = *(long *)(inst_status + lVar11 * 0x40 + 0x38);
  mutex_unlock(puVar2);
  if (lVar12 != 0) {
    _printk(&DAT_0010ddc7,"gsi_set_inst_name",lVar11);
    uVar10 = 0xfffffff0;
    goto LAB_001023d0;
  }
  if (iVar4 == 0) {
    config_group_init_type_name(param_1,*param_1,&gsi_func_rndis_type);
  }
  uVar10 = kmalloc_trace(_ida_alloc_range,0xdc0,0x5c0);
  if (uVar10 == 0) {
    uVar10 = 0xfffffffffffffff4;
    goto LAB_001023d0;
  }
  *(undefined4 *)(uVar10 + 0x24c) = 0;
  *(undefined8 *)(uVar10 + 0x250) = 0xfffffffe0;
  *(ulong *)(uVar10 + 600) = uVar10 + 600;
  *(ulong *)(uVar10 + 0x260) = uVar10 + 600;
  *(code **)(uVar10 + 0x268) = ipa_work_handler;
  init_timer_key(uVar10 + 0x280,&delayed_work_timer_fn,0x200000,0,0);
  uVar3 = ipa_usb_wq;
  *(undefined8 *)(uVar10 + 0x224) = 0xffffffeaffffffea;
  *(int *)(uVar10 + 0xd8) = (int)lVar11;
  *(undefined8 *)(uVar10 + 0x2d8) = uVar3;
  *(ulong *)(uVar10 + 0x520) = uVar10 + 0x520;
  *(ulong *)(uVar10 + 0x528) = uVar10 + 0x520;
  *(ulong *)(uVar10 + 0x530) = uVar10 + 0x530;
  *(ulong *)(uVar10 + 0x538) = uVar10 + 0x530;
  *(undefined4 *)(uVar10 + 0x548) = 0;
  __init_waitqueue_head(uVar10 + 0x508,"&gsi->c_port.read_wq",&gsi_function_ctrl_port_init___key);
  uVar6 = *(int *)(uVar10 + 0xd8) - 2;
  if (2 < uVar6) goto LAB_0010232c;
  lVar12 = uVar10 + 0x450;
  strlcat(lVar12,(&PTR_s_rmnet_ctrl_0010b340)[(int)uVar6],0xf);
  uVar6 = ida_alloc_range(gsi_ida,0,2,0xcc0);
  if ((int)uVar6 < 0) {
    _printk(&DAT_0010daa8,"gsi_function_ctrl_port_init",uVar6);
LAB_00102510:
    kfree(uVar10);
    uVar10 = (ulong)(int)uVar6;
  }
  else {
    lVar1 = uVar10 + 0x460;
    cdev_init(lVar1,&gsi_ctrl_dev_fops);
    uVar7 = cdev_add(lVar1,uVar6 | major << 0x14,1);
    if (uVar7 != 0) {
      ipc_log_string(*(undefined8 *)(uVar10 + 0x570),"%s: Failed to add cdev for (%s)\n",
                     "gsi_function_ctrl_port_init",lVar12);
      _printk(&DAT_0010c53e,"gsi_function_ctrl_port_init",lVar12);
      ida_free(gsi_ida,uVar6);
      uVar6 = uVar7;
      goto LAB_00102510;
    }
    uVar9 = device_create(gsi_class,0,uVar6 | major << 0x14,0,lVar12);
    if (0xfffffffffffff000 < uVar9) {
      ipc_log_string(*(undefined8 *)(uVar10 + 0x570),"%s: device_create failed for (%s)\n",
                     "gsi_function_ctrl_port_init",lVar12);
      _printk(&DAT_0010dccb,"gsi_function_ctrl_port_init",lVar12);
      cdev_del(lVar1);
      ida_free(gsi_ida,uVar6);
      uVar6 = (uint)uVar9;
      if ((uint)uVar9 != 0) goto LAB_00102510;
    }
LAB_0010232c:
    *(undefined2 *)(uVar10 + 0x5ba) = 500;
    init_timer_key(uVar10 + 0x580,gsi_rw_timer_func,0,0,0);
  }
  if (uVar10 < 0xfffffffffffff001) {
    param_1[0x17] = uVar10;
    scnprintf(&local_98,0x2e,"gsi.%s",param_2);
    lVar12 = ipc_log_context_create(10,&local_98,0);
    if (lVar12 == 0) {
      _printk(&DAT_0010d0f9,"gsi_set_inst_name",&local_98);
    }
    *(long *)(param_1[0x17] + 0x570) = lVar12;
    mutex_lock(puVar2);
    *(undefined8 **)(inst_status + lVar11 * 0x40 + 0x38) = param_1;
    inst_status[lVar11 * 0x40 + 0x30] = 1;
    mutex_unlock(puVar2);
    uVar10 = 0;
  }
LAB_001023d0:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10 & 0xffffffff;
}



//------------------------------------------------------------
// gsi_free_inst @ 00102528 size=360
// signature: undefined gsi_free_inst(void)
// callers: []
//------------------------------------------------------------

void gsi_free_inst(long param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  code *pcVar3;
  ulong uVar4;
  long lVar5;
  
  if ((param_1 != 0) && (lVar5 = *(long *)(param_1 + 0xb8), lVar5 != 0)) {
    uVar2 = *(uint *)(lVar5 + 0xd8);
    uVar4 = (ulong)uVar2;
    if (6 < uVar2) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x102690);
      (*pcVar3)();
    }
    puVar1 = inst_status + uVar4 * 0x40;
    mutex_lock(puVar1);
    if (*(char *)(*(long *)(param_1 + 0xb8) + 0x500) == '\0') {
      ipc_log_context_destroy(*(undefined8 *)(*(long *)(param_1 + 0xb8) + 0x570));
      lVar5 = *(long *)(param_1 + 0xb8);
      uVar2 = *(uint *)(lVar5 + 0x4e0);
      if (uVar2 != 0) {
        device_destroy(gsi_class);
        cdev_del(lVar5 + 0x460);
        *(undefined4 *)(lVar5 + 0x4e0) = 0;
        ida_free(gsi_ida,uVar2 & 0xfffff);
        lVar5 = *(long *)(param_1 + 0xb8);
      }
      kfree(lVar5);
      kfree(param_1);
      if ((0x1c0 < (uVar4 << 6 | 0x30)) ||
         (inst_status[uVar4 * 0x40 + 0x30] = 0, 0x1c0 < (uVar4 << 6 | 0x38))) {
LAB_00102688:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(1,0x10268c);
        (*pcVar3)();
      }
      *(undefined8 *)(inst_status + uVar4 * 0x40 + 0x38) = 0;
      mutex_unlock(puVar1);
    }
    else {
      if (0x1c0 < (uVar4 << 6 | 0x30)) goto LAB_00102688;
      inst_status[uVar4 * 0x40 + 0x30] = 0;
      mutex_unlock(puVar1);
      ipc_log_string(*(undefined8 *)(lVar5 + 0x570),
                     "%s: [prot_id = %d] Dev is open, free mem when dev close\n","gsi_free_inst",
                     uVar2);
      _printk(&DAT_0010dfab,"gsi_free_inst",uVar4);
    }
  }
  return;
}



//------------------------------------------------------------
// gsi_opts_release @ 00102694 size=80
// signature: undefined gsi_opts_release(void)
// callers: []
//------------------------------------------------------------

void gsi_opts_release(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0xb8);
  if (puVar1 != (undefined8 *)0x0) {
    ipc_log_string(puVar1[0xae],"%s: releasing %s instance\n","gsi_opts_release",*puVar1);
  }
  usb_put_function_instance(param_1);
  return;
}



//------------------------------------------------------------
// gsi_info_show @ 001026e8 size=1532
// signature: undefined gsi_info_show(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long gsi_info_show(long param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0xb8);
  lVar3 = kmalloc_trace(_cdev_init,0xdc0,0x1000);
  if (lVar3 == 0) {
    lVar3 = -0xc;
  }
  else {
    if ((lVar6 == 0) || (*(int *)(lVar6 + 0x108) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = scnprintf(lVar3,0x1000,"Info: Prot_id:%d\n",*(undefined4 *)(lVar6 + 0xd8));
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%55s\n",
                        "==================================================");
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10s\n","Ctrl Name: ",
                        lVar6 + 0x450);
      uVar1 = uVar1 + iVar2;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n","Ctrl Online: ",
                        *(undefined4 *)(lVar6 + 0x4fc));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n","Ctrl Open: ",
                        *(undefined1 *)(lVar6 + 0x500));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n",
                        "Ctrl Host to Modem: ",*(undefined4 *)(lVar6 + 0x554));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n",
                        "Ctrl Modem to Host: ",*(undefined4 *)(lVar6 + 0x560));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n",
                        "Ctrl Cpd to Modem: ",*(undefined4 *)(lVar6 + 0x558));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n",
                        "Ctrl Cpd From Modem: ",*(undefined4 *)(lVar6 + 0x55c));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n","Ctrl Pkt Drops: ",
                        *(undefined4 *)(lVar6 + 0x564));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s\n","==============");
      uVar1 = uVar1 + iVar2;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n","Protocol ID: ",
                        *(undefined4 *)(lVar6 + 0xd8));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n","SM State: ",
                        *(undefined4 *)(lVar6 + 0x2e0));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n","IN XferRscIndex: "
                        ,*(undefined4 *)(lVar6 + 0x22c));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10d\n","IN Chnl Hdl: ",
                        *(undefined4 *)(lVar6 + 0x224));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10x\n",
                        "IN Chnl Dbl Addr: ",*(undefined4 *)(lVar6 + 0x170));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n","IN TRB Ring Len: "
                        ,*(undefined2 *)(lVar6 + 0x39c));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10x\n",
                        "IN TRB Base Addr: ",*(undefined4 *)(lVar6 + 0x3b0));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10x\n",
                        "GEVENTCNTLO IN Addr: ",*(undefined4 *)(lVar6 + 0x390));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10x\n",
                        "DEPCMDLO IN Addr: ",*(undefined4 *)(lVar6 + 0x3a4));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10x\n",
                        "IN LastTRB Addr Off: ",*(undefined2 *)(lVar6 + 0x3a0));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n","IN Buffer Size: ",
                        *(undefined1 *)(lVar6 + 0x3a2));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n","IN/DL Aggr Size: "
                        ,*(undefined4 *)(lVar6 + 0x43c));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s\n","==============");
      uVar1 = uVar1 + iVar2;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n",
                        "OUT XferRscIndex: ",*(undefined4 *)(lVar6 + 0x230));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10d\n","OUT Channel Hdl: "
                        ,*(undefined4 *)(lVar6 + 0x228));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10x\n",
                        "OUT Channel Dbl Addr: ",*(undefined4 *)(lVar6 + 0x1c8));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n",
                        "OUT TRB Ring Len: ",*(undefined2 *)(lVar6 + 0x3ec));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10x\n",
                        "OUT TRB Base Addr: ",*(undefined4 *)(lVar6 + 0x400));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10x\n",
                        "GEVENTCNTLO OUT Addr: ",*(undefined4 *)(lVar6 + 0x3e0));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10x\n",
                        "DEPCMDLO OUT Addr: ",*(undefined4 *)(lVar6 + 0x3f4));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10x\n",
                        "OUT LastTRB Addr Off: ",*(undefined2 *)(lVar6 + 0x3f0));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n","OUT Buffer Size: "
                        ,*(undefined1 *)(lVar6 + 0x3f2));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n",
                        "OUT/UL Aggr Size: ",*(undefined4 *)(lVar6 + 0x434));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n",
                        "OUT/UL Packets to dev: ",*(undefined4 *)(lVar6 + 0x438));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n",
                        "Net_ready_trigger:",*(undefined1 *)(lVar6 + 0x241));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s\n","USB Bus Events");
      lVar5 = 0;
      uVar4 = (ulong)(uVar1 + iVar2);
      do {
        iVar2 = scnprintf(lVar3 + uVar4,0x1000 - uVar4,&DAT_0010c928,
                          *(undefined1 *)(lVar6 + 0x2e4 + lVar5));
        lVar5 = lVar5 + 1;
        uVar1 = iVar2 + (int)uVar4;
        uVar4 = (ulong)uVar1;
      } while (lVar5 != 0x80);
      iVar2 = scnprintf(lVar3 + uVar4,0x1000 - uVar4,&DAT_0010e4d9);
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n","Eventq head: ",
                        *(undefined1 *)(lVar6 + 0x364));
      uVar1 = iVar2 + uVar1;
      iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x1000 - (ulong)uVar1,"%25s %10u\n","Eventq tail: ",
                        *(undefined1 *)(lVar6 + 0x365));
      uVar1 = iVar2 + uVar1;
      if (0xfff < uVar1) {
        uVar1 = 0x1000;
      }
    }
    iVar2 = scnprintf(param_2,uVar1,lVar3);
    kfree(lVar3);
    lVar3 = (long)iVar2;
  }
  return lVar3;
}



//------------------------------------------------------------
// gsi_rndis_class_id_show @ 00102ce8 size=56
// signature: undefined gsi_rndis_class_id_show(void)
// callers: []
//------------------------------------------------------------

long gsi_rndis_class_id_show(long param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = scnprintf(param_2,0x1000,&DAT_0010cc08,*(undefined4 *)(*(long *)(param_1 + 0xb8) + 0x110))
  ;
  return (long)iVar1;
}



//------------------------------------------------------------
// gsi_rndis_class_id_store @ 00102d24 size=140
// signature: undefined gsi_rndis_class_id_store(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_rndis_class_id_store(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  byte local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0xb8);
  local_2c[0] = 0;
  iVar1 = kstrtou8(param_2,0,local_2c);
  if ((iVar1 == 0) && (local_2c[0] - 1 < 9)) {
    *(uint *)(lVar2 + 0x110) = (uint)local_2c[0];
  }
  else {
    param_3 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// ipa_work_handler @ 00102db4 size=2724
// signature: undefined ipa_work_handler(void)
// callers: []
//------------------------------------------------------------

void ipa_work_handler(long param_1)

{
  long lVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  undefined8 uVar8;
  undefined *puVar9;
  char *pcVar10;
  undefined4 uVar11;
  ulong uVar12;
  undefined8 *puVar13;
  long lVar14;
  long lVar15;
  undefined1 local_5c [4];
  long local_58;
  
  lVar14 = sp_el0;
  lVar1 = param_1 + 0x118;
  local_58 = *(long *)(lVar14 + 0x638);
  lVar14 = param_1 + -0x250;
  lVar15 = *(long *)(param_1 + -0x50);
  local_5c[0] = 0;
  uVar8 = _raw_spin_lock_irqsave(lVar1);
  if ((uint)*(byte *)(param_1 + 0x114) == (uint)*(byte *)(param_1 + 0x115)) {
    if (lVar14 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 800),"%s: event queue empty","read_event");
      _raw_spin_unlock_irqrestore(lVar1,uVar8);
      cVar6 = '\0';
      goto LAB_00102e64;
    }
    _raw_spin_unlock_irqrestore(lVar1,uVar8);
    cVar6 = '\0';
LAB_00102ea8:
    if (lVar15 == 0) goto LAB_001036ec;
    bVar4 = true;
joined_r0x00102eb4:
    if ((lVar15 != -0x78) && (lVar15 = *(long *)(lVar15 + 0xd8), lVar15 != 0)) {
      if (*(uint *)(param_1 + 0x90) < 8) {
        puVar13 = (undefined8 *)(param_1 + -0x110);
        switch(*(uint *)(param_1 + 0x90)) {
        case 1:
          if (cVar6 == '\x03') {
            if (*(int *)(param_1 + -0x148) == 0) {
              if (!bVar4) {
                ipc_log_string(*(undefined8 *)(param_1 + 800),"USB cable not connected\n");
                _printk(&DAT_0010e07c);
              }
            }
            else {
              usb_gadget_autopm_get(*(undefined8 *)(param_1 + -0x50));
              if (bVar4) {
                iVar7 = gsi_ep_enable(lVar14);
                if (iVar7 != 0) {
LAB_00102f14:
                  usb_composite_setup_continue(*(undefined8 *)(param_1 + -0x48));
                  lVar14 = *(long *)(param_1 + -0x50);
                  goto joined_r0x0010319c;
                }
              }
              else {
                ipc_log_string(*(undefined8 *)(param_1 + 800),"%s: get = %d","ipa_work_handler",
                               *(undefined4 *)(lVar15 + 0x1f8));
                iVar7 = gsi_ep_enable(lVar14);
                if (iVar7 != 0) {
                  ipc_log_string(*(undefined8 *)(param_1 + 800),"%s:ep enable err %d",
                                 "ipa_work_handler",iVar7);
                  _printk(&DAT_0010d8d8,"ipa_work_handler",iVar7);
                  goto LAB_00102f14;
                }
              }
              usb_composite_setup_continue(*(undefined8 *)(param_1 + -0x48));
              if (*(int *)(param_1 + -0x178) == 0) {
                lVar14 = *(long *)(param_1 + -0x50);
                *(undefined4 *)(param_1 + 0x90) = 4;
                goto joined_r0x0010319c;
              }
              iVar7 = ipa_connect_channels(puVar13);
              if (iVar7 == 0) {
                *(undefined4 *)(param_1 + 0x90) = 2;
                if (!bVar4) {
                  uVar8 = *(undefined8 *)(param_1 + 800);
                  pcVar10 = "%s: ST_INIT_EVT_SET_ALT";
                  goto LAB_001034d0;
                }
              }
              else {
                if (!bVar4) {
                  ipc_log_string(*(undefined8 *)(param_1 + 800),"%s: ipa_connect_channels failed\n",
                                 "ipa_work_handler");
                  _printk(&DAT_0010e9de,"ipa_work_handler");
                }
                ipa_data_path_disable(puVar13);
                if ((*(long *)(param_1 + -0x50) != 0) &&
                   (lVar14 = *(long *)(*(long *)(param_1 + -0x50) + 0xd8), lVar14 != 0)) {
                  __pm_runtime_idle(lVar14,5);
                }
                *(undefined4 *)(param_1 + 0x90) = 1;
              }
            }
          }
          break;
        case 2:
          if (cVar6 == '\b') {
            cVar6 = peek_event(puVar13);
            if (cVar6 == '\a') {
              read_event(puVar13);
              ipa_data_path_disable(puVar13);
              ipa_disconnect_channel(puVar13);
              *(undefined4 *)(param_1 + 0x90) = 1;
              if ((*(long *)(param_1 + -0x50) != 0) &&
                 (lVar14 = *(long *)(*(long *)(param_1 + -0x50) + 0xd8), lVar14 != 0)) {
                __pm_runtime_idle(lVar14,5);
              }
              if (!bVar4) {
                ipc_log_string(*(undefined8 *)(param_1 + 800),"%s: ST_WAIT_IPARDY_EVT_SUS_DIS",
                               "ipa_work_handler");
                uVar8 = *(undefined8 *)(param_1 + 800);
                pcVar10 = "%s: put_async1 = %d";
                goto LAB_001035e0;
              }
            }
            else {
              iVar7 = ipa_suspend_work_handler(puVar13);
              if (iVar7 == 0) {
                if ((*(long *)(param_1 + -0x50) != 0) &&
                   (lVar14 = *(long *)(*(long *)(param_1 + -0x50) + 0xd8), lVar14 != 0)) {
                  __pm_runtime_idle(lVar14,5);
                }
                if (!bVar4) {
                  ipc_log_string(*(undefined8 *)(param_1 + 800),"%s: ST_WAIT_IPARDY_EVT_SUS",
                                 "ipa_work_handler");
                  uVar8 = *(undefined8 *)(param_1 + 800);
                  pcVar10 = "%s: put_async2 = %d";
                  goto LAB_001035e0;
                }
              }
            }
          }
          else if (cVar6 == '\a') {
            ipa_data_path_disable(puVar13);
            ipa_disconnect_channel(puVar13);
            *(undefined4 *)(param_1 + 0x90) = 1;
            if ((*(long *)(param_1 + -0x50) != 0) &&
               (lVar14 = *(long *)(*(long *)(param_1 + -0x50) + 0xd8), lVar14 != 0)) {
              __pm_runtime_idle(lVar14,5);
            }
            if (!bVar4) {
              ipc_log_string(*(undefined8 *)(param_1 + 800),"%s: ST_WAIT_IPARDY_EVT_DIS",
                             "ipa_work_handler");
              uVar8 = *(undefined8 *)(param_1 + 800);
              pcVar10 = "%s: put_async3 = %d";
              goto LAB_001035e0;
            }
          }
          else if (cVar6 == '\x04') {
            cVar6 = peek_event(puVar13);
            if (cVar6 == '\b') {
              if (!bVar4) {
                uVar8 = *(undefined8 *)(param_1 + 800);
                pcVar10 = "%s: ST_WAIT_IPARDY_EVT_SUSPEND";
                goto LAB_001034d0;
              }
            }
            else {
              ipa_data_path_enable(puVar13);
              *(undefined4 *)(param_1 + 0x90) = 3;
              if (!bVar4) {
                uVar8 = *(undefined8 *)(param_1 + 800);
                pcVar10 = "%s: ST_WAIT_IPARDY_EVT_IPARDY %d";
                uVar11 = 0x464;
                goto LAB_001035e8;
              }
            }
          }
          break;
        case 3:
          if (cVar6 == '\x05') {
LAB_0010308c:
            cVar5 = peek_event(puVar13);
            if (cVar5 == '\x06') {
              read_event(puVar13);
              if (!bVar4) {
                uVar8 = *(undefined8 *)(param_1 + 800);
                pcVar10 = "%s: NO_OP NRDY_RDY";
                goto LAB_001034d0;
              }
            }
            else {
              if (cVar6 == '\x05') {
                if (!bVar4) {
                  ipc_log_string(*(undefined8 *)(param_1 + 800),"%s: ST_CON_HOST_NRDY\n",
                                 "ipa_work_handler");
                }
                local_5c[0] = 1;
                usb_gsi_ep_op(*puVar13,local_5c,0xb);
                gsi_rndis_ipa_reset_trigger(puVar13);
                usb_gsi_ep_op(*puVar13,0,6);
                usb_gsi_ep_op(*(undefined8 *)(param_1 + -0x108),0,6);
                ipa_disconnect_channel(puVar13);
                *(undefined4 *)(param_1 + 0x90) = 4;
                if (bVar4) {
LAB_0010363c:
                  lVar14 = *(long *)(param_1 + -0x50);
                  goto joined_r0x0010319c;
                }
                pcVar10 = "%s: ST_CON_EVT_HNRDY";
              }
              else {
                ipa_data_path_disable(puVar13);
                ipa_disconnect_channel(puVar13);
                *(undefined4 *)(param_1 + 0x90) = 1;
                if (bVar4) goto LAB_0010363c;
                pcVar10 = "%s: ST_CON_EVT_DIS";
              }
              ipc_log_string(*(undefined8 *)(param_1 + 800),pcVar10,"ipa_work_handler");
              if ((*(long *)(param_1 + -0x50) != 0) &&
                 (lVar14 = *(long *)(*(long *)(param_1 + -0x50) + 0xd8), lVar14 != 0)) {
                __pm_runtime_idle(lVar14,5);
              }
              uVar8 = *(undefined8 *)(param_1 + 800);
              pcVar10 = "%s: put_async4 = %d";
              uVar11 = *(undefined4 *)(lVar15 + 0x1f8);
LAB_001035e8:
              ipc_log_string(uVar8,pcVar10,"ipa_work_handler",uVar11);
            }
          }
          else if (cVar6 == '\b') {
            cVar6 = peek_event(puVar13);
            if (cVar6 == '\a') {
              read_event(puVar13);
              ipa_data_path_disable(puVar13);
              ipa_disconnect_channel(puVar13);
              *(undefined4 *)(param_1 + 0x90) = 1;
              if ((*(long *)(param_1 + -0x50) != 0) &&
                 (lVar14 = *(long *)(*(long *)(param_1 + -0x50) + 0xd8), lVar14 != 0)) {
                __pm_runtime_idle(lVar14,5);
              }
              if (!bVar4) {
                ipc_log_string(*(undefined8 *)(param_1 + 800),"%s: ST_CON_EVT_SUS_DIS",
                               "ipa_work_handler");
                uVar8 = *(undefined8 *)(param_1 + 800);
                pcVar10 = "%s: put_async5 = %d";
                goto LAB_001035e0;
              }
            }
            else {
              iVar7 = ipa_suspend_work_handler(puVar13);
              if (iVar7 == 0) {
                if ((*(long *)(param_1 + -0x50) != 0) &&
                   (lVar14 = *(long *)(*(long *)(param_1 + -0x50) + 0xd8), lVar14 != 0)) {
                  __pm_runtime_idle(lVar14,5);
                }
                if (!bVar4) {
                  uVar8 = *(undefined8 *)(param_1 + 800);
                  pcVar10 = "%s: ST_CON_EVT_SUS";
                  goto LAB_00102fb0;
                }
              }
            }
          }
          else if (cVar6 == '\a') goto LAB_0010308c;
          break;
        case 4:
          if (cVar6 != '\x06') {
            if (cVar6 == '\a') {
              usb_gadget_autopm_get(*(undefined8 *)(param_1 + -0x50));
              ipa_data_path_disable(puVar13);
              *(undefined4 *)(param_1 + 0x90) = 1;
              if ((*(long *)(param_1 + -0x50) != 0) &&
                 (lVar14 = *(long *)(*(long *)(param_1 + -0x50) + 0xd8), lVar14 != 0)) {
                __pm_runtime_idle(lVar14,5);
              }
              if (!bVar4) {
                ipc_log_string(*(undefined8 *)(param_1 + 800),"%s: ST_HOST_NRDY_EVT_DIS",
                               "ipa_work_handler");
                uVar8 = *(undefined8 *)(param_1 + 800);
                pcVar10 = "%s: put_async = %d";
                goto LAB_001035e0;
              }
            }
            break;
          }
          usb_gadget_autopm_get(*(undefined8 *)(param_1 + -0x50));
          if (bVar4) {
            iVar7 = ipa_connect_channels(puVar13);
            if (iVar7 == 0) {
              ipa_data_path_enable(puVar13);
              goto LAB_00103028;
            }
            goto LAB_0010363c;
          }
          ipc_log_string(*(undefined8 *)(param_1 + 800),"%s: get = %d","ipa_work_handler",
                         *(undefined4 *)(lVar15 + 0x1f8));
          iVar7 = ipa_connect_channels(puVar13);
          if (iVar7 != 0) {
            ipc_log_string(*(undefined8 *)(param_1 + 800),"%s: ipa_connect_channels failed\n",
                           "ipa_work_handler");
            _printk(&DAT_0010e9de,"ipa_work_handler");
            lVar14 = *(long *)(param_1 + -0x50);
            goto joined_r0x0010319c;
          }
          ipa_data_path_enable(puVar13);
          uVar8 = *(undefined8 *)(param_1 + 800);
          pcVar10 = "%s: ST_HOST_NRDY_EVT_HRDY_";
          *(undefined4 *)(param_1 + 0x90) = 3;
          goto LAB_001034d0;
        case 5:
          goto switchD_00102ee4_caseD_5;
        case 6:
          if (cVar6 == '\a') {
            ipa_data_path_disable(puVar13);
            ipa_disconnect_channel(puVar13);
            *(undefined4 *)(param_1 + 0x90) = 1;
            if ((*(long *)(param_1 + -0x50) != 0) &&
               (lVar14 = *(long *)(*(long *)(param_1 + -0x50) + 0xd8), lVar14 != 0)) {
              __pm_runtime_idle(lVar14,5);
            }
            if (!bVar4) {
              ipc_log_string(*(undefined8 *)(param_1 + 800),"%s: ST_SUS_IN_PROG_EVT_DIS",
                             "ipa_work_handler");
              uVar8 = *(undefined8 *)(param_1 + 800);
              pcVar10 = "%s: put_async7 = %d";
LAB_001035e0:
              uVar11 = *(undefined4 *)(lVar15 + 0x1f8);
              goto LAB_001035e8;
            }
          }
          else if (cVar6 == '\n') {
            ipa_resume_work_handler(puVar13);
            *(undefined4 *)(param_1 + 0x90) = 3;
            if ((*(long *)(param_1 + -0x50) != 0) &&
               (lVar14 = *(long *)(*(long *)(param_1 + -0x50) + 0xd8), lVar14 != 0)) {
              piVar2 = (int *)(lVar14 + 0x1f8);
              Hint_Prefetch(piVar2,2,0,1);
              do {
                cVar6 = '\x01';
                bVar3 = (bool)ExclusiveMonitorPass(piVar2,0x10);
                if (bVar3) {
                  *piVar2 = *piVar2 + 1;
                  cVar6 = ExclusiveMonitorsStatus();
                }
              } while (cVar6 != '\0');
            }
            if (!bVar4) {
              ipc_log_string(*(undefined8 *)(param_1 + 800),"%s: ST_SUS_IN_PROG_EVT_RES",
                             "ipa_work_handler");
              uVar8 = *(undefined8 *)(param_1 + 800);
              pcVar10 = "%s: get_nores1 = %d";
              goto LAB_001035e0;
            }
          }
          else if (cVar6 == '\t') {
            *(undefined4 *)(param_1 + 0x90) = 7;
            if ((*(long *)(param_1 + -0x50) != 0) &&
               (lVar14 = *(long *)(*(long *)(param_1 + -0x50) + 0xd8), lVar14 != 0)) {
              __pm_runtime_idle(lVar14,5);
            }
            if (!bVar4) {
              uVar8 = *(undefined8 *)(param_1 + 800);
              pcVar10 = "%s: ST_SUS_IN_PROG_EVT_IPA_SUS";
LAB_00102fb0:
              ipc_log_string(uVar8,pcVar10,"ipa_work_handler");
              uVar8 = *(undefined8 *)(param_1 + 800);
              pcVar10 = "%s: put_async6 = %d";
              goto LAB_001035e0;
            }
          }
          break;
        case 7:
          if (cVar6 == '\a') {
            usb_gadget_autopm_get(*(undefined8 *)(param_1 + -0x50));
            ipa_data_path_disable(puVar13);
            ipa_disconnect_channel(puVar13);
            *(undefined4 *)(param_1 + 0x90) = 1;
            if (bVar4) goto LAB_0010363c;
            ipc_log_string(*(undefined8 *)(param_1 + 800),"%s: ST_SUS_EVT_DIS","ipa_work_handler");
            lVar14 = *(long *)(param_1 + -0x50);
joined_r0x0010319c:
            if ((lVar14 != 0) && (*(long *)(lVar14 + 0xd8) != 0)) {
              __pm_runtime_idle(*(long *)(lVar14 + 0xd8),5);
            }
          }
          else if (cVar6 == '\n') {
            usb_gadget_autopm_get(*(undefined8 *)(param_1 + -0x50));
            if (!bVar4) {
              ipc_log_string(*(undefined8 *)(param_1 + 800),"%s: ST_SUS_EVT_RES","ipa_work_handler")
              ;
              ipc_log_string(*(undefined8 *)(param_1 + 800),"%s: get = %d","ipa_work_handler",
                             *(undefined4 *)(lVar15 + 0x1f8));
            }
            ipa_resume_work_handler(puVar13);
LAB_00103028:
            *(undefined4 *)(param_1 + 0x90) = 3;
          }
        }
      }
      else {
switchD_00102ee4_caseD_5:
        if (!bVar4) {
          uVar8 = *(undefined8 *)(param_1 + 800);
          pcVar10 = "%s: Invalid state to SM";
LAB_001034d0:
          ipc_log_string(uVar8,pcVar10,"ipa_work_handler");
        }
      }
      uVar8 = _raw_spin_lock_irqsave(lVar1);
      if ((uint)*(byte *)(param_1 + 0x114) == (uint)*(byte *)(param_1 + 0x115)) {
        if (!bVar4) {
          ipc_log_string(*(undefined8 *)(param_1 + 800),"%s: event queue empty","peek_event");
        }
        _raw_spin_unlock_irqrestore(lVar1,uVar8);
      }
      else {
        cVar6 = *(char *)(param_1 + ((ulong)(*(byte *)(param_1 + 0x114) + 1) & 0x7f) + 0x94);
        _raw_spin_unlock_irqrestore(lVar1,uVar8);
        if (cVar6 != '\0') {
          if (!bVar4) {
            ipc_log_string(*(undefined8 *)(param_1 + 800),"%s: New events to process",
                           "ipa_work_handler");
          }
          queue_delayed_work_on(0x20,*(undefined8 *)(param_1 + 0x88),param_1,0);
        }
      }
      goto LAB_001036ec;
    }
    if (bVar4) goto LAB_001036ec;
    ipc_log_string(*(undefined8 *)(param_1 + 800),"%s(): dev or dev->parent is NULL.\n",
                   "ipa_work_handler");
    puVar9 = &DAT_0010c7ed;
  }
  else {
    uVar12 = (ulong)(*(byte *)(param_1 + 0x114) + 1) & 0x7f;
    *(char *)(param_1 + 0x114) = (char)uVar12;
    cVar6 = *(char *)(param_1 + uVar12 + 0x94);
    _raw_spin_unlock_irqrestore(lVar1,uVar8);
    if (lVar14 == 0) goto LAB_00102ea8;
LAB_00102e64:
    ipc_log_string(*(undefined8 *)(param_1 + 800),"%s: event = %x sm_state %x","ipa_work_handler",
                   cVar6,*(undefined4 *)(param_1 + 0x90));
    if (lVar15 != 0) {
      bVar4 = false;
      goto joined_r0x00102eb4;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 800),"%s(): gadget is NULL.\n","ipa_work_handler");
    puVar9 = &DAT_0010e7a5;
  }
  _printk(puVar9,"ipa_work_handler");
LAB_001036ec:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gsi_rw_timer_func @ 00103868 size=204
// signature: undefined gsi_rw_timer_func(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gsi_rw_timer_func(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = param_1 + -0x580;
  if (*(int *)(param_1 + -0x478) == 0) {
    if (lVar2 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + -0x10),"%s: gsi not connected.. bail-out\n",
                     "gsi_rw_timer_func");
    }
    *(undefined1 *)(param_1 + 0x38) = 0;
  }
  else {
    if (lVar2 == 0) {
      gsi_wakeup_host(0);
      if (*(char *)(param_1 + 0x38) == '\0') {
        return;
      }
    }
    else {
      ipc_log_string(*(undefined8 *)(param_1 + -0x10),"%s: calling gsi_wakeup_host\n",
                     "gsi_rw_timer_func");
      gsi_wakeup_host(lVar2);
      if (*(char *)(param_1 + 0x38) == '\0') {
        return;
      }
      ipc_log_string(*(undefined8 *)(param_1 + -0x10),"%s: re-arm the timer\n","gsi_rw_timer_func");
    }
    lVar2 = _jiffies;
    lVar1 = __msecs_to_jiffies(*(undefined2 *)(param_1 + 0x3a));
    mod_timer(param_1,lVar1 + lVar2);
  }
  return;
}



//------------------------------------------------------------
// read_event @ 00103934 size=136
// signature: undefined read_event(void)
// callers: [ipa_work_handler]
//------------------------------------------------------------

void read_event(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(param_1 + 0x228);
  if (*(char *)(param_1 + 0x224) == *(char *)(param_1 + 0x225)) {
    if (param_1 != 0x140) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x430),"%s: event queue empty","read_event");
    }
  }
  else {
    *(byte *)(param_1 + 0x224) = *(char *)(param_1 + 0x224) + 1U & 0x7f;
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x228,uVar1);
  return;
}



//------------------------------------------------------------
// usb_gadget_autopm_get @ 001039bc size=72
// signature: undefined usb_gadget_autopm_get(void)
// callers: [ipa_work_handler]
//------------------------------------------------------------

void usb_gadget_autopm_get(long param_1)

{
  int iVar1;
  
  if (((param_1 != 0) && (*(long *)(param_1 + 0xd8) != 0)) &&
     (iVar1 = __pm_runtime_resume(*(long *)(param_1 + 0xd8),4), iVar1 < 0)) {
    __pm_runtime_idle(*(undefined8 *)(param_1 + 0xd8),4);
  }
  return;
}



//------------------------------------------------------------
// gsi_ep_enable @ 00103a04 size=248
// signature: undefined gsi_ep_enable(void)
// callers: [ipa_work_handler]
//------------------------------------------------------------

int gsi_ep_enable(long param_1)

{
  int iVar1;
  
  if ((*(long *)(param_1 + 0x140) != 0) && (*(long *)(*(long *)(param_1 + 0x140) + 0x38) == 0)) {
    iVar1 = config_ep_by_speed(*(undefined8 *)(param_1 + 0x200),param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: Enable IN ep","gsi_ep_enable");
    }
    iVar1 = usb_gsi_ep_op(*(undefined8 *)(param_1 + 0x140),param_1 + 0x150,0);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  if ((*(long *)(param_1 + 0x148) == 0) || (*(long *)(*(long *)(param_1 + 0x148) + 0x38) != 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = config_ep_by_speed(*(undefined8 *)(param_1 + 0x200),param_1);
    if (iVar1 == 0) {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: Enable OUT ep","gsi_ep_enable");
      }
      iVar1 = usb_gsi_ep_op(*(undefined8 *)(param_1 + 0x148),param_1 + 0x1a8,0);
      if ((iVar1 != 0) && (*(long *)(param_1 + 0x140) != 0)) {
        usb_gsi_ep_op(*(long *)(param_1 + 0x140),param_1 + 0x150,0xd);
      }
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// ipa_connect_channels @ 00103afc size=1680
// signature: undefined ipa_connect_channels(void)
// callers: [ipa_work_handler]
//------------------------------------------------------------

int ipa_connect_channels(undefined8 *param_1)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  long *plVar6;
  undefined8 local_a0;
  undefined4 local_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 *local_60;
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  local_68 = 0;
  local_60 = (undefined8 *)0x0;
  local_78 = 0;
  local_70 = 0;
  local_80 = 0;
  plVar6 = *(long **)(param_1[-0x22] + 0x30);
  local_88 = 0;
  local_90 = 0;
  local_98 = 0;
  local_a0 = 0;
  if (param_1 == (undefined8 *)0x140) {
    iVar4 = usb_gsi_ep_op(uRam0000000000000140,0x150,9);
    if (iVar4 != 0) goto LAB_00104004;
    iVar4 = usb_gsi_ep_op(uRam0000000000000140,0x150,1);
    if (iVar4 == 0) goto LAB_00103b9c;
  }
  else {
    ipc_log_string(param_1[0x86],"IN: num_bufs:=%zu, buf_len=%zu\n",param_1[4],param_1[5]);
    iVar4 = usb_gsi_ep_op(*param_1,param_1 + 2,9);
    if (iVar4 != 0) {
      ipc_log_string(param_1[0x86],"%s: GSI_EP_OP_PREPARE_TRBS failed: %d\n","ipa_connect_channels",
                     iVar4);
      _printk(&DAT_0010d310,"ipa_connect_channels",iVar4);
      goto LAB_00104004;
    }
    iVar4 = usb_gsi_ep_op(*param_1,param_1 + 2,1);
    if (iVar4 == 0) {
LAB_00103b9c:
      uVar5 = usb_gsi_ep_op(*param_1,0,8);
      *(undefined4 *)((long)param_1 + 0xec) = uVar5;
      param_1[0x49] = 0;
      param_1[0x4a] = 0;
      param_1[0x4b] = 0;
      param_1[0x4c] = 0;
      param_1[0x4d] = 0;
      param_1[0x4e] = 0;
      param_1[0x4f] = 0;
      param_1[0x50] = 0;
      param_1[0x51] = 0;
      param_1[0x52] = 0;
      local_60 = param_1 + 2;
      usb_gsi_ep_op(*param_1,&local_80,7);
      if (param_1 != (undefined8 *)0x140) {
        ipc_log_string(param_1[0x86],"%s: USB GSI IN OPS Completed","ipa_connect_channels");
      }
      *(undefined4 *)(param_1 + 0x4b) = 0;
      *(undefined4 *)((long)param_1 + 0x24c) = *(undefined4 *)(param_1 + -0xd);
      *(undefined4 *)(param_1 + 0x4a) = local_78._4_4_;
      param_1[0x51] = param_1 + 9;
      *(undefined1 *)((long)param_1 + 0x254) = (undefined1)local_70;
      *(undefined2 *)((long)param_1 + 0x25c) = local_70._2_2_;
      param_1[0x4e] = local_68;
      *(undefined2 *)(param_1 + 0x4c) = (undefined2)local_80;
      *(int *)(param_1 + 0x4f) = *(int *)(param_1 + 4) * *(int *)(param_1 + 5);
      param_1[0x50] = param_1[3];
      param_1[0x52] = param_1 + 0xb;
      if (param_1 != (undefined8 *)0x140) {
        ipc_log_string(param_1[0x86],"%s(): IN: sgt_xfer_rings:%pK sgt_data_buff:%pK\n",
                       "ipa_connect_channels");
      }
      *(undefined1 *)((long)param_1 + 0x262) = local_80._2_1_;
      *(undefined4 *)((long)param_1 + 0x264) = local_80._4_4_;
      *(undefined1 *)(param_1 + 0x4d) = (undefined1)local_78;
      if (param_1[1] == 0) {
LAB_00103dc4:
        uVar1 = *(uint *)(*plVar6 + 0x58);
        *(char *)((long)param_1 + 0x2ec) = (char)*(undefined4 *)((long)param_1 + 0xec);
        *(undefined1 *)((long)param_1 + 0x2ed) = 1;
        *(char *)((long)param_1 + 0x2ee) = (char)*(undefined4 *)(param_1 + 0x1e);
        *(undefined4 *)((long)param_1 + 0x2f4) = *(undefined4 *)((long)param_1 + 0xfc);
        uVar5 = 0x400;
        if (uVar1 < 5) {
          uVar5 = 0x200;
        }
        *(int *)(param_1 + 0x5e) = *(int *)(param_1 + -0xd);
        *(undefined4 *)((long)param_1 + 0x2fc) = *(undefined4 *)(param_1 + 0x1f);
        *(undefined4 *)(param_1 + 0x5d) = uVar5;
        *(undefined4 *)(param_1 + 0x5f) = 0xf;
        *(bool *)((long)param_1 + 0x2ef) = *(int *)(param_1 + -0xd) != 4;
        local_88 = 0;
        local_90 = 0;
        local_98 = 0;
        local_a0 = 0;
        uVar5 = 0xe10;
        if (*(uint *)(*plVar6 + 0x58) < 5) {
          uVar5 = 400;
        }
        *(undefined4 *)(param_1 + 0x60) = uVar5;
        if (param_1 != (undefined8 *)0x140) {
          ipc_log_string(param_1[0x86],"%s: Calling xdci_connect","ipa_connect_channels");
        }
        if (*(int *)(*(code **)(param_1[0x61] + 8) + -4) != 0x1d953172) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103e9c);
          (*pcVar3)();
        }
        iVar4 = (**(code **)(param_1[0x61] + 8))
                          (param_1 + 0x53,param_1 + 0x49,&local_a0,&local_90,param_1 + 0x5d);
        if (iVar4 == 0) {
          if (param_1 != (undefined8 *)0x140) {
            ipc_log_string(param_1[0x86],"%s: xdci_connect done","ipa_connect_channels");
            ipc_log_string(param_1[0x86],"%s: IN CH HDL %x","ipa_connect_channels",
                           local_90 & 0xffffffff);
            ipc_log_string(param_1[0x86],"%s: IN CH DBL addr %x","ipa_connect_channels",
                           local_90._4_4_);
            ipc_log_string(param_1[0x86],"%s: OUT CH HDL %x","ipa_connect_channels",
                           local_a0 & 0xffffffff);
            ipc_log_string(param_1[0x86],"%s: OUT CH DBL addr %x","ipa_connect_channels",
                           local_a0._4_4_);
          }
          iVar4 = 0;
          *(undefined4 *)((long)param_1 + 0xe4) = (undefined4)local_90;
          *(undefined4 *)(param_1 + 6) = local_90._4_4_;
          *(undefined4 *)(param_1 + 8) = local_88;
          if (*(int *)(param_1 + -0xd) != 4) {
            *(undefined4 *)(param_1 + 0x1d) = (undefined4)local_a0;
            *(undefined4 *)(param_1 + 0x11) = local_a0._4_4_;
            *(undefined4 *)(param_1 + 0x13) = local_98;
          }
          goto LAB_00104004;
        }
        lVar2 = lRam0000000000000148;
        if (param_1 != (undefined8 *)0x140) {
          ipc_log_string(param_1[0x86],"%s: IPA connect failed %d","ipa_connect_channels",iVar4);
          _printk(&DAT_0010e80e,"ipa_connect_channels",iVar4);
          lVar2 = param_1[1];
        }
        if (lVar2 != 0) {
          usb_gsi_ep_op(lVar2,0,6);
          goto LAB_00103ec0;
        }
      }
      else if (param_1 == (undefined8 *)0x140) {
        iVar4 = usb_gsi_ep_op(param_1[1],0x1a8,9);
        if (iVar4 == 0) {
          iVar4 = usb_gsi_ep_op(lRam0000000000000148,0x1a8,1);
          if (iVar4 == 0) goto LAB_00103cd8;
          goto LAB_00103ec0;
        }
      }
      else {
        ipc_log_string(param_1[0x86],"OUT: num_bufs:=%zu, buf_len=%zu\n",param_1[0xf],param_1[0x10])
        ;
        iVar4 = usb_gsi_ep_op(param_1[1],param_1 + 0xd,9);
        if (iVar4 == 0) {
          iVar4 = usb_gsi_ep_op(param_1[1],param_1 + 0xd,1);
          if (iVar4 == 0) {
LAB_00103cd8:
            uVar5 = usb_gsi_ep_op(param_1[1],0,8);
            *(undefined4 *)(param_1 + 0x1e) = uVar5;
            param_1[0x53] = 0;
            param_1[0x54] = 0;
            param_1[0x55] = 0;
            param_1[0x56] = 0;
            param_1[0x57] = 0;
            param_1[0x58] = 0;
            param_1[0x59] = 0;
            param_1[0x5a] = 0;
            param_1[0x5b] = 0;
            param_1[0x5c] = 0;
            local_60 = param_1 + 0xd;
            usb_gsi_ep_op(param_1[1],&local_80,7);
            if (param_1 != (undefined8 *)0x140) {
              ipc_log_string(param_1[0x86],"%s: USB GSI OUT OPS Completed","ipa_connect_channels");
            }
            *(undefined4 *)((long)param_1 + 0x29c) = *(undefined4 *)(param_1 + -0xd);
            *(undefined4 *)(param_1 + 0x54) = local_78._4_4_;
            param_1[0x5b] = param_1 + 0x14;
            *(undefined1 *)((long)param_1 + 0x2a4) = (undefined1)local_70;
            *(undefined4 *)(param_1 + 0x55) = 1;
            param_1[0x58] = local_68;
            *(undefined2 *)((long)param_1 + 0x2ac) = local_70._2_2_;
            *(int *)(param_1 + 0x59) = *(int *)(param_1 + 0xf) * *(int *)(param_1 + 0x10);
            param_1[0x5a] = param_1[0xe];
            param_1[0x5c] = param_1 + 0x16;
            if (param_1 != (undefined8 *)0x140) {
              ipc_log_string(param_1[0x86],"%s(): OUT: sgt_xfer_rings:%pK sgt_data_buff:%pK\n",
                             "ipa_connect_channels");
            }
            *(undefined2 *)(param_1 + 0x56) = (undefined2)local_80;
            *(undefined1 *)((long)param_1 + 0x2b2) = local_80._2_1_;
            *(undefined4 *)((long)param_1 + 0x2b4) = local_80._4_4_;
            *(undefined1 *)(param_1 + 0x57) = (undefined1)local_78;
            goto LAB_00103dc4;
          }
          ipc_log_string(param_1[0x86],"%s: GSI_EP_OP_STARTXFER failed: %d\n","ipa_connect_channels"
                         ,iVar4);
          _printk(&DAT_0010de1b,"ipa_connect_channels",iVar4);
LAB_00103ec0:
          if (param_1[1] != 0) {
            usb_gsi_ep_op(param_1[1],param_1 + 0xd,10);
          }
        }
        else {
          ipc_log_string(param_1[0x86],"%s: GSI_EP_OP_PREPARE_TRBS failed: %d\n",
                         "ipa_connect_channels",iVar4);
          _printk(&DAT_0010d310,"ipa_connect_channels",iVar4);
        }
      }
      usb_gsi_ep_op(*param_1,0,6);
    }
    else {
      ipc_log_string(param_1[0x86],"%s: GSI_EP_OP_STARTXFER failed: %d\n","ipa_connect_channels",
                     iVar4);
      _printk(&DAT_0010de1b,"ipa_connect_channels",iVar4);
    }
  }
  usb_gsi_ep_op(*param_1,param_1 + 2,10);
LAB_00104004:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// ipa_data_path_disable @ 0010418c size=180
// signature: undefined ipa_data_path_disable(void)
// callers: [ipa_work_handler]
//------------------------------------------------------------

void ipa_data_path_disable(long *param_1)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 1;
  if (param_1 != (long *)0x140) {
    ipc_log_string(param_1[0x86],"%s: Disable eps","ipa_data_path_disable");
  }
  if (*param_1 != 0) {
    usb_gsi_ep_op(*param_1,param_1 + 2,0xd);
  }
  if (param_1[1] != 0) {
    usb_gsi_ep_op(param_1[1],param_1 + 0xd,0xd);
  }
  if (*param_1 != 0) {
    usb_gsi_ep_op(*param_1,local_2c,0xb);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// peek_event @ 00104240 size=148
// signature: undefined peek_event(void)
// callers: [ipa_work_handler]
//------------------------------------------------------------

undefined1 peek_event(long param_1)

{
  undefined8 uVar1;
  undefined1 uVar2;
  
  uVar1 = _raw_spin_lock_irqsave(param_1 + 0x228);
  if ((uint)*(byte *)(param_1 + 0x224) == (uint)*(byte *)(param_1 + 0x225)) {
    if (param_1 != 0x140) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x430),"%s: event queue empty","peek_event");
    }
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined1 *)(param_1 + ((ulong)(*(byte *)(param_1 + 0x224) + 1) & 0x7f) + 0x1a4);
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x228,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// ipa_data_path_enable @ 001042d4 size=260
// signature: undefined ipa_data_path_enable(void)
// callers: [ipa_work_handler]
//------------------------------------------------------------

void ipa_data_path_enable(undefined8 *param_1)

{
  long lVar1;
  undefined1 local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = 0;
  if (param_1 != (undefined8 *)0x140) {
    ipc_log_string(param_1[0x86],"IN: db_reg_phs_addr_lsb = %x",*(undefined4 *)(param_1 + 6));
  }
  usb_gsi_ep_op(*param_1,param_1 + 2,2);
  lVar1 = param_1[1];
  if (lVar1 != 0) {
    if (param_1 != (undefined8 *)0x140) {
      ipc_log_string(param_1[0x86],"OUT: db_reg_phs_addr_lsb = %x",*(undefined4 *)(param_1 + 0x11));
      lVar1 = param_1[1];
    }
    usb_gsi_ep_op(lVar1,param_1 + 0xd,2);
    usb_gsi_ep_op(param_1[1],param_1 + 0xd,3);
  }
  usb_gsi_ep_op(*param_1,local_3c,0xb);
  usb_gsi_ep_op(*param_1,param_1 + 2,5);
  if (param_1[1] != 0) {
    usb_gsi_ep_op(param_1[1],param_1 + 0xd,5);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ipa_disconnect_channel @ 001043d8 size=292
// signature: undefined ipa_disconnect_channel(void)
// callers: [ipa_work_handler]
//------------------------------------------------------------

void ipa_disconnect_channel(long *param_1)

{
  code *pcVar1;
  int iVar2;
  
  if (param_1 != (long *)0x140) {
    ipc_log_string(param_1[0x86],"%s: Calling xdci_disconnect","ipa_disconnect_channel");
  }
  if (*(int *)(*(code **)(param_1[0x61] + 0x10) + -4) != 0x59b03b66) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104438);
    (*pcVar1)();
  }
  iVar2 = (**(code **)(param_1[0x61] + 0x10))
                    ((int)param_1[0x1d],*(undefined4 *)((long)param_1 + 0xe4),(int)param_1[-0xd]);
  if ((param_1 == (long *)0x140) || (iVar2 == 0)) {
    if (param_1 == (long *)0x140) goto LAB_00104464;
  }
  else {
    ipc_log_string(param_1[0x86],"%s: IPA disconnect failed %d","ipa_disconnect_channel",iVar2);
    _printk(&DAT_0010e59e,"ipa_disconnect_channel",iVar2);
  }
  ipc_log_string(param_1[0x86],"%s: xdci_disconnect done","ipa_disconnect_channel");
LAB_00104464:
  *(undefined8 *)((long)param_1 + 0xe4) = 0xffffffeaffffffea;
  if (*param_1 != 0) {
    usb_gsi_ep_op(*param_1,param_1 + 2,10);
    msm_ep_set_mode(*param_1,0);
  }
  if (param_1[1] != 0) {
    usb_gsi_ep_op(param_1[1],param_1 + 0xd,10);
    msm_ep_set_mode(param_1[1],0);
  }
  return;
}



//------------------------------------------------------------
// ipa_suspend_work_handler @ 001044fc size=640
// signature: undefined ipa_suspend_work_handler(void)
// callers: [ipa_work_handler]
//------------------------------------------------------------

int ipa_suspend_work_handler(undefined8 *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  long lVar6;
  bool bVar7;
  int iVar8;
  code *pcVar9;
  undefined1 local_60 [4];
  undefined1 local_5c [4];
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  puVar5 = param_1 + -0x28;
  local_60[0] = *(undefined1 *)((long)param_1 + -0x17);
  local_5c[0] = 0;
  if (puVar5 == (undefined8 *)0x0) {
    iVar8 = usb_gsi_ep_op(*param_1,local_60,0xc);
    if (iVar8 == 0) goto LAB_001045dc;
LAB_0010459c:
    uVar4 = *(undefined4 *)(param_1 + -0xd);
    uVar2 = *(undefined4 *)((long)param_1 + 0xe4);
    uVar3 = *(undefined4 *)(param_1 + 0x1d);
    if (*(uint *)(**(long **)(param_1[-0x22] + 0x30) + 0x58) < 5) {
      bVar7 = true;
      pcVar9 = *(code **)(param_1[0x61] + 0x20);
    }
    else {
      bVar7 = *(char *)((long)param_1 + -0x17) != '\0';
      pcVar9 = *(code **)(param_1[0x61] + 0x20);
    }
    if (puVar5 != (undefined8 *)0x0) {
      pcVar1 = "true";
      if (bVar7 == false) {
        pcVar1 = "false";
      }
      ipc_log_string(param_1[0x86],"%s: remote_wakeup_allowed:%s","usb_gsi_remote_wakeup_allowed",
                     pcVar1);
    }
    if (*(int *)(pcVar9 + -4) != 0x155b85c3) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8239,0x104660);
      (*pcVar9)();
    }
    iVar8 = (*pcVar9)(uVar3,uVar2,uVar4,bVar7);
    if (iVar8 == -0x73) {
      *(undefined4 *)(param_1 + 0x34) = 6;
      goto joined_r0x001045f4;
    }
    if (iVar8 == -0xe) {
      local_5c[0] = 0;
      usb_gsi_ep_op(*param_1,local_5c,0xb);
      gsi_wakeup_host(puVar5);
      goto joined_r0x001045f4;
    }
    if (iVar8 == 0) {
      *(undefined4 *)(param_1 + 0x34) = 7;
      if (puVar5 == (undefined8 *)0x0) {
        iVar8 = 0;
        goto LAB_00104740;
      }
      ipc_log_string(param_1[0x86],"%s: STATE SUSPENDED","ipa_suspend_work_handler");
      iVar8 = 0;
    }
    else {
      if (puVar5 == (undefined8 *)0x0) goto LAB_00104740;
      ipc_log_string(param_1[0x86],"%s: Error %d for %d","ipa_suspend_work_handler",iVar8,
                     *(undefined4 *)(param_1 + -0xd));
      _printk(&DAT_0010eac6,"ipa_suspend_work_handler",iVar8,*(undefined4 *)(param_1 + -0xd));
    }
  }
  else {
    ipc_log_string(param_1[0x86],"%s: f_suspend:%d","ipa_suspend_work_handler");
    iVar8 = usb_gsi_ep_op(*param_1,local_60,0xc);
    if (iVar8 != 0) {
      ipc_log_string(param_1[0x86],"%s: Calling xdci_suspend","ipa_suspend_work_handler");
      goto LAB_0010459c;
    }
LAB_001045dc:
    local_5c[0] = 0;
    usb_gsi_ep_op(*param_1,local_5c,0xb);
    iVar8 = -0xe;
joined_r0x001045f4:
    if (puVar5 == (undefined8 *)0x0) goto LAB_00104740;
  }
  ipc_log_string(param_1[0x86],"%s: xdci_suspend ret %d","ipa_suspend_work_handler",iVar8);
LAB_00104740:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}



//------------------------------------------------------------
// gsi_rndis_ipa_reset_trigger @ 0010477c size=96
// signature: undefined gsi_rndis_ipa_reset_trigger(void)
// callers: [ipa_work_handler]
//------------------------------------------------------------

void gsi_rndis_ipa_reset_trigger(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0x140) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x430),"%s: setting net_ready_trigger\n",
                   "gsi_rndis_ipa_reset_trigger");
  }
  uVar1 = _raw_spin_lock_irqsave(param_1 + 0x10c);
  *(undefined1 *)(param_1 + 0x101) = 0;
  _raw_spin_unlock_irqrestore(param_1 + 0x10c,uVar1);
  return;
}



//------------------------------------------------------------
// ipa_resume_work_handler @ 001047dc size=244
// signature: undefined ipa_resume_work_handler(void)
// callers: [ipa_work_handler]
//------------------------------------------------------------

void ipa_resume_work_handler(undefined8 *param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (param_1 != (undefined8 *)0x140) {
    ipc_log_string(param_1[0x86],"%s: Calling xdci_resume","ipa_resume_work_handler");
  }
  if (*(int *)(*(code **)(param_1[0x61] + 0x28) + -4) != 0x59b03b66) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x104848);
    (*pcVar2)();
  }
  iVar3 = (**(code **)(param_1[0x61] + 0x28))
                    (*(undefined4 *)(param_1 + 0x1d),*(undefined4 *)((long)param_1 + 0xe4),
                     *(undefined4 *)(param_1 + -0xd));
  if ((param_1 == (undefined8 *)0x140) || (iVar3 == 0)) {
    if (param_1 == (undefined8 *)0x140) goto LAB_00104890;
  }
  else {
    ipc_log_string(param_1[0x86],"%s: xdci_resume ret %d","ipa_resume_work_handler",iVar3);
  }
  ipc_log_string(param_1[0x86],"%s: xdci_resume done","ipa_resume_work_handler");
LAB_00104890:
  local_2c[0] = 0;
  usb_gsi_ep_op(*param_1,local_2c,0xb);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gsi_wakeup_host @ 001048d0 size=272
// signature: undefined gsi_wakeup_host(void)
// callers: [gsi_rw_timer_func, ipa_usb_notify_cb, ipa_suspend_work_handler]
//------------------------------------------------------------

void gsi_wakeup_host(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = **(long **)(*(long *)(param_1 + 0x30) + 0x30);
  if (param_1 == 0) {
    if (lVar2 == 0) {
      return;
    }
  }
  else {
    ipc_log_string(*(undefined8 *)(param_1 + 0x570),"Entering %s","gsi_wakeup_host");
    if (lVar2 == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x570),"FAILED: d_port->cdev->gadget == NULL");
      _printk(&DAT_0010e388);
      return;
    }
  }
  if ((*(uint *)(lVar2 + 0x58) < 5) || (*(char *)(param_1 + 0x128) == '\0')) {
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: Calling usb_gadget_wakeup",
                     "gsi_wakeup_host");
    }
    iVar1 = usb_gadget_wakeup(lVar2);
    if ((iVar1 == -0xb) || (iVar1 == -0x10)) {
      if (param_1 == 0) {
        return;
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x570),"RW delayed due to LPM exit.");
      return;
    }
  }
  else {
    iVar1 = -0x5f;
  }
  if ((param_1 != 0) && (iVar1 != 0)) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x570),"wakeup failed. ret=%d.",iVar1);
    _printk(&DAT_0010e3af,iVar1);
  }
  return;
}



//------------------------------------------------------------
// gsi_ctrl_dev_read @ 001049e4 size=1384
// signature: undefined gsi_ctrl_dev_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long gsi_ctrl_dev_read(long param_1,ulong param_2,ulong param_3)

{
  long *plVar1;
  char cVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 *puVar8;
  ulong uVar9;
  long lVar10;
  long *plVar11;
  ulong uVar12;
  long *plVar13;
  long lVar14;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  uVar12 = (ulong)**(uint **)(param_1 + 0xd8);
  if (7 < **(uint **)(param_1 + 0xd8)) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x104f34);
    (*pcVar4)();
  }
  mutex_lock(inst_status + uVar12 * 0x40);
  if (0x1c0 < (uVar12 << 6 | 0x30)) {
LAB_00104f2c:
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(1,0x104f30);
    (*pcVar4)();
  }
  cVar2 = inst_status[uVar12 * 0x40 + 0x30];
  mutex_unlock(inst_status + uVar12 * 0x40);
  if (cVar2 == '\0') {
    iVar5 = ___ratelimit(gsi_ctrl_dev_read__rs,"gsi_ctrl_dev_read");
    if (iVar5 == 0) {
      lVar10 = -0x13;
    }
    else {
      _printk(&DAT_0010eb3c,"gsi_ctrl_dev_read");
      lVar10 = -0x13;
    }
  }
  else {
    if (0x1c0 < (uVar12 << 6 | 0x38)) goto LAB_00104f2c;
    lVar14 = *(long *)(*(long *)(inst_status + uVar12 * 0x40 + 0x38) + 0xb8);
    if (lVar14 == -0x450) {
      ipc_log_string(uRam0000000000000120,"%s: gsi ctrl port %pK","gsi_ctrl_dev_read",0);
      _printk(&DAT_0010d16a,"gsi_ctrl_dev_read",0);
      lVar10 = -0x13;
    }
    else if (param_3 < 0x2001) {
      lVar10 = lVar14 + 0x548;
      uVar6 = _raw_spin_lock_irqsave(lVar10);
      plVar13 = *(long **)(lVar14 + 0x520);
      plVar11 = (long *)(lVar14 + 0x520);
      if (plVar13 == plVar11) {
        do {
          if (lVar14 != 0) {
            ipc_log_string(*(undefined8 *)(lVar14 + 0x570),"Requests list is empty. Wait.");
          }
          _raw_spin_unlock_irqrestore(lVar10,uVar6);
          if ((long *)*plVar11 == plVar11) {
            local_78 = 0;
            uStack_70 = 0;
            local_88 = 0;
            uStack_80 = 0;
            local_90 = 0;
            init_wait_entry(&local_90,0);
            while (lVar7 = prepare_to_wait_event(lVar14 + 0x508,&local_90,1),
                  (long *)*plVar11 == plVar11) {
              if (lVar7 != 0) {
                if (-1 < (int)lVar7) goto LAB_00104d9c;
                if (lVar14 == 0) {
                  lVar10 = -0x200;
                }
                else {
                  ipc_log_string(*(undefined8 *)(lVar14 + 0x570),"Waiting failed");
                  _printk(&DAT_0010e0f1);
                  lVar10 = -0x200;
                }
                goto LAB_00104cbc;
              }
              schedule();
            }
            finish_wait(lVar14 + 0x508,&local_90);
          }
LAB_00104d9c:
          if (lVar14 != 0) {
            ipc_log_string(*(undefined8 *)(lVar14 + 0x570),"Received request packet");
          }
          uVar6 = _raw_spin_lock_irqsave(lVar10);
          plVar13 = (long *)*plVar11;
        } while (plVar13 == plVar11);
      }
      plVar11 = plVar13 + -2;
      uVar12 = __list_del_entry_valid(plVar13);
      if ((uVar12 & 1) != 0) {
        lVar7 = *plVar13;
        plVar1 = (long *)plVar13[1];
        *(long **)(lVar7 + 8) = plVar1;
        *plVar1 = lVar7;
      }
      *plVar13 = -0x2152ffffffffff00;
      plVar13[1] = -0x2152fffffffffede;
      _raw_spin_unlock_irqrestore(lVar10,uVar6);
      if (param_3 < (ulong)(long)(int)plVar13[-1]) {
        if (lVar14 != 0) {
          ipc_log_string(*(undefined8 *)(lVar14 + 0x570),"cpkt size large:%d > buf size:%zu",
                         (int)plVar13[-1],param_3);
          _printk(&DAT_0010cf95,(int)plVar13[-1],param_3);
        }
        if (plVar11 != (long *)0x0) {
          kfree(*plVar11);
          kfree(plVar11);
        }
        lVar10 = -0xc;
      }
      else {
        if (lVar14 != 0) {
          ipc_log_string(*(undefined8 *)(lVar14 + 0x570),"%s: cpkt size:%d","gsi_ctrl_dev_read");
        }
        if (DAT_0010b6d0 != '\0') {
          iVar5 = (int)plVar13[-1];
          if (0x1d < iVar5) {
            iVar5 = 0x1e;
          }
          print_hex_dump(&DAT_0010e70b,"READ:",2,0x10,1,plVar13[-2],(long)iVar5,0);
        }
        uVar12 = (ulong)(int)plVar13[-1];
        if ((int)plVar13[-1] < 0) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x800,0x104f28);
          (*pcVar4)();
        }
        lVar10 = plVar13[-2];
        __check_object_size(lVar10,uVar12,1);
        puVar8 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
           (uVar9 = param_2, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
          uVar9 = param_2 & (long)(param_2 << 8) >> 8;
        }
        if (uVar9 <= 0x8000000000 - uVar12) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar9 = daif;
            if ((uVar9 & 0x80) == 0) {
              uVar3 = daif;
              daif = uVar3 | 0xc0;
            }
            puVar8 = (undefined8 *)puVar8[1];
            uVar3 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar8 & 0xffff000000000000 | uVar3 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar8;
            InstructionSynchronizationBarrier();
            daif = uVar9;
          }
          uVar12 = __arch_copy_to_user(puVar8,param_2 & 0xff7fffffffffffff,lVar10,uVar12);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar9 = daif;
            if ((uVar9 & 0x80) == 0) {
              uVar3 = daif;
              daif = uVar3 | 0xc0;
            }
            uVar3 = ttbr1_el1;
            ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar3 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar9;
          }
        }
        if ((int)uVar12 == 0) {
          if (lVar14 != 0) {
            ipc_log_string(*(undefined8 *)(lVar14 + 0x570),"%s: copied %d bytes to user",
                           "gsi_ctrl_dev_read",(int)plVar13[-1]);
          }
          lVar10 = (long)(int)plVar13[-1];
          *(int *)(lVar14 + 0x558) = *(int *)(lVar14 + 0x558) + 1;
        }
        else if (lVar14 == 0) {
          lVar10 = -0xe;
        }
        else {
          ipc_log_string(*(undefined8 *)(lVar14 + 0x570),"copy_to_user failed: err %d",
                         uVar12 & 0xffffffff);
          _printk(&DAT_0010e5bd,uVar12 & 0xffffffff);
          lVar10 = -0xe;
        }
        if (plVar11 != (long *)0x0) {
          kfree(*plVar11);
          kfree(plVar11);
        }
        if (lVar14 != 0) {
          ipc_log_string(*(undefined8 *)(lVar14 + 0x570),"%s: Exit %zu","gsi_ctrl_dev_read",param_3)
          ;
        }
      }
    }
    else if (lVar14 == 0) {
      lVar10 = -0x16;
    }
    else {
      ipc_log_string(*(undefined8 *)(lVar14 + 0x570),"Large buff size %zu, should be %d",param_3,
                     0x2000);
      _printk(&DAT_0010de93,param_3,0x2000);
      lVar10 = -0x16;
    }
  }
LAB_00104cbc:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar10;
}



//------------------------------------------------------------
// gsi_ctrl_dev_write @ 00104f6c size=1124
// signature: undefined gsi_ctrl_dev_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

size_t gsi_ctrl_dev_write(long param_1,ulong param_2,size_t param_3)

{
  long *plVar1;
  uint uVar2;
  char cVar3;
  ulong uVar4;
  code *pcVar5;
  int iVar6;
  long *plVar7;
  long lVar8;
  size_t __n;
  undefined8 uVar9;
  undefined8 *puVar10;
  long lVar11;
  ulong uVar12;
  long *plVar13;
  
  uVar2 = **(uint **)(param_1 + 0xd8);
  uVar12 = (ulong)uVar2;
  if (7 < uVar2) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x105388);
    (*pcVar5)();
  }
  if (uVar2 == 4) {
    return 0xffffffffffffffea;
  }
  mutex_lock(inst_status + uVar12 * 0x40);
  if (0x1c0 < (uVar12 << 6 | 0x30)) {
LAB_00105388:
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(1,0x10538c);
    (*pcVar5)();
  }
  cVar3 = inst_status[uVar12 * 0x40 + 0x30];
  mutex_unlock(inst_status + uVar12 * 0x40);
  if (cVar3 == '\0') {
    iVar6 = ___ratelimit(gsi_ctrl_dev_write__rs,"gsi_ctrl_dev_write");
    if (iVar6 == 0) {
      return 0xffffffffffffffed;
    }
    _printk(&DAT_0010eb3c,"gsi_ctrl_dev_write");
    return 0xffffffffffffffed;
  }
  if (0x1c0 < (uVar12 << 6 | 0x38)) goto LAB_00105388;
  lVar11 = *(long *)(*(long *)(inst_status + uVar12 * 0x40 + 0x38) + 0xb8);
  if (param_3 - 0x2001 < 0xffffffffffffe000) {
    if (lVar11 == 0) {
      return 0xffffffffffffffea;
    }
    ipc_log_string(*(undefined8 *)(lVar11 + 0x570),"error: ctrl pkt length %zu",param_3);
    _printk(&DAT_0010dad1,param_3);
    return 0xffffffffffffffea;
  }
  if (*(int *)(lVar11 + 0x108) == 0) {
    if (lVar11 == 0) {
      return 0xffffffffffffff98;
    }
    ipc_log_string(*(undefined8 *)(lVar11 + 0x570),"USB cable not connected\n");
    _printk(&DAT_0010e07c);
    return 0xffffffffffffff98;
  }
  if ((*(char *)(lVar11 + 0x128) != '\0') && (*(char *)(lVar11 + 0x129) == '\0')) {
    *(int *)(lVar11 + 0x564) = *(int *)(lVar11 + 0x564) + 1;
    if (lVar11 == 0) {
      return 0xffffffffffffffa1;
    }
    ipc_log_string(*(undefined8 *)(lVar11 + 0x570),"drop ctrl pkt of len %zu",param_3);
    _printk(&DAT_0010e4fd,param_3);
    return 0xffffffffffffffa1;
  }
  plVar7 = (long *)kmalloc_trace(_mutex_unlock,0xdc0,0x20);
  if (plVar7 == (long *)0x0) {
LAB_00105260:
    if (lVar11 != 0) {
      ipc_log_string(*(undefined8 *)(lVar11 + 0x570),"failed to allocate ctrl pkt");
      _printk(&DAT_0010c706);
    }
    return 0xfffffffffffffff4;
  }
  lVar8 = __kmalloc(param_3,0xcc0);
  *plVar7 = lVar8;
  if (lVar8 == 0) {
    kfree(plVar7);
    goto LAB_00105260;
  }
  iVar6 = (int)param_3;
  *(int *)(plVar7 + 1) = iVar6;
  if ((long *)0xfffffffffffff000 < plVar7) goto LAB_00105260;
  __check_object_size(lVar8,param_3,0);
  puVar10 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
     (uVar12 = param_2, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
    uVar12 = param_2 & (long)(param_2 << 8) >> 8;
  }
  __n = param_3;
  if (uVar12 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar12 = daif;
      if ((uVar12 & 0x80) == 0) {
        uVar4 = daif;
        daif = uVar4 | 0xc0;
      }
      puVar10 = (undefined8 *)puVar10[1];
      uVar4 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar10 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar10;
      InstructionSynchronizationBarrier();
      daif = uVar12;
    }
    __n = __arch_copy_from_user(puVar10,lVar8,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar12 = daif;
      if ((uVar12 & 0x80) == 0) {
        uVar4 = daif;
        daif = uVar4 | 0xc0;
      }
      uVar4 = ttbr1_el1;
      ttbr0_el1 = (uVar4 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar4 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar12;
    }
    if (__n == 0) goto LAB_00105164;
  }
  memset((void *)(lVar8 + (param_3 - __n)),0,__n);
  if ((int)__n != 0) {
    if (lVar11 != 0) {
      ipc_log_string(*(undefined8 *)(lVar11 + 0x570),"copy_from_user failed err:%d",__n & 0xffffffff
                    );
      _printk(&DAT_0010dd1f,__n & 0xffffffff);
    }
    kfree(*plVar7);
    kfree(plVar7);
    return (long)(int)__n;
  }
LAB_00105164:
  *(undefined4 *)((long)plVar7 + 0xc) = 4;
  cVar3 = DAT_0010b6d0;
  *(int *)(lVar11 + 0x55c) = *(int *)(lVar11 + 0x55c) + 1;
  if (cVar3 != '\0') {
    if (0x1d < iVar6) {
      iVar6 = 0x1e;
    }
    print_hex_dump(&DAT_0010e70b,"WRITE:",2,0x10,1,*plVar7,iVar6,0);
  }
  uVar9 = _raw_spin_lock_irqsave(lVar11 + 0x548);
  plVar13 = *(long **)(lVar11 + 0x538);
  plVar1 = plVar7 + 2;
  uVar12 = __list_add_valid(plVar1,plVar13,lVar11 + 0x530);
  if ((uVar12 & 1) != 0) {
    *(long **)(lVar11 + 0x538) = plVar1;
    plVar7[2] = lVar11 + 0x530;
    plVar7[3] = (long)plVar13;
    *plVar13 = (long)plVar1;
  }
  _raw_spin_unlock_irqrestore(lVar11 + 0x548,uVar9);
  iVar6 = gsi_ctrl_send_notification(lVar11);
  if (iVar6 == 0) {
    *(int *)(lVar11 + 0x560) = *(int *)(lVar11 + 0x560) + 1;
  }
  if (lVar11 == 0) {
    return param_3;
  }
  ipc_log_string(*(undefined8 *)(lVar11 + 0x570),"Exit %zu",param_3);
  return param_3;
}



//------------------------------------------------------------
// gsi_ctrl_dev_poll @ 001053ec size=452
// signature: undefined gsi_ctrl_dev_poll(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_ctrl_dev_poll(long param_1,undefined8 *param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  
  uVar6 = (ulong)**(uint **)(param_1 + 0xd8);
  if (7 < **(uint **)(param_1 + 0xd8)) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1055b0);
    (*pcVar4)();
  }
  mutex_lock(inst_status + uVar6 * 0x40);
  if (0x1c0 < (uVar6 << 6 | 0x30)) {
LAB_001055a8:
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(1,0x1055ac);
    (*pcVar4)();
  }
  cVar1 = inst_status[uVar6 * 0x40 + 0x30];
  mutex_unlock(inst_status + uVar6 * 0x40);
  if (cVar1 == '\0') {
    iVar2 = ___ratelimit(gsi_ctrl_dev_poll__rs,"gsi_ctrl_dev_poll");
    if (iVar2 != 0) {
      _printk(&DAT_0010eb3c,"gsi_ctrl_dev_poll");
      return 0x10;
    }
  }
  else {
    if (0x1c0 < (uVar6 << 6 | 0x38)) goto LAB_001055a8;
    lVar7 = *(long *)(*(long *)(inst_status + uVar6 * 0x40 + 0x38) + 0xb8);
    if (lVar7 + 0x450 != 0) {
      if (((param_2 != (undefined8 *)0x0) && (lVar7 + 0x508 != 0)) &&
         (pcVar4 = (code *)*param_2, pcVar4 != (code *)0x0)) {
        if (*(int *)(pcVar4 + -4) != 0x7db4acb9) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1054b0);
          (*pcVar4)();
        }
        (*pcVar4)(param_1,lVar7 + 0x508,param_2);
        DataMemoryBarrier(2,3);
      }
      uVar3 = _raw_spin_lock_irqsave(lVar7 + 0x548);
      if (*(long *)(lVar7 + 0x520) == lVar7 + 0x520) {
        uVar5 = 0;
      }
      else {
        if (lVar7 != 0) {
          ipc_log_string(*(undefined8 *)(lVar7 + 0x570),"%s sets POLLIN for %s","gsi_ctrl_dev_poll",
                         lVar7 + 0x450);
        }
        uVar5 = 0x41;
      }
      _raw_spin_unlock_irqrestore(lVar7 + 0x548,uVar3);
      return uVar5;
    }
    if (lVar7 != 0) {
      ipc_log_string(*(undefined8 *)(lVar7 + 0x570),"%s: gsi ctrl port %pK","gsi_ctrl_dev_poll",0);
      _printk(&DAT_0010d16a,"gsi_ctrl_dev_poll",0);
      return 0x10;
    }
  }
  return 0x10;
}



//------------------------------------------------------------
// gsi_ctrl_dev_ioctl @ 001055b4 size=2796
// signature: undefined gsi_ctrl_dev_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gsi_ctrl_dev_ioctl(long param_1,int param_2,ulong param_3)

{
  long *plVar1;
  undefined8 *puVar2;
  long lVar3;
  long *plVar4;
  undefined4 uVar5;
  char cVar6;
  ulong uVar7;
  long *plVar8;
  code *pcVar9;
  int iVar10;
  undefined8 uVar11;
  undefined *puVar12;
  char *pcVar13;
  undefined8 *puVar14;
  uint uVar15;
  long lVar16;
  long lVar17;
  undefined4 uVar18;
  ulong uVar19;
  long *plVar20;
  undefined8 *puVar21;
  long *plVar22;
  uint local_7c;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  
  lVar17 = sp_el0;
  local_58 = *(long *)(lVar17 + 0x638);
  local_68 = 0;
  local_60 = 0;
  local_78 = 0;
  local_70 = 0;
  uVar19 = (ulong)**(uint **)(param_1 + 0xd8);
  if (7 < **(uint **)(param_1 + 0xd8)) {
                    /* WARNING: Does not return */
    pcVar9 = (code *)SoftwareBreakpoint(0x5512,0x106024);
    (*pcVar9)();
  }
  local_7c = 0;
  mutex_lock(inst_status + uVar19 * 0x40);
  if (0x1c0 < (uVar19 << 6 | 0x30)) {
LAB_0010601c:
                    /* WARNING: Does not return */
    pcVar9 = (code *)SoftwareBreakpoint(1,0x106020);
    (*pcVar9)();
  }
  cVar6 = inst_status[uVar19 * 0x40 + 0x30];
  mutex_unlock(inst_status + uVar19 * 0x40);
  if (cVar6 == '\0') {
    iVar10 = ___ratelimit(gsi_ctrl_dev_ioctl__rs,"gsi_ctrl_dev_ioctl");
    if (iVar10 == 0) {
      lVar17 = -0x13;
    }
    else {
      _printk(&DAT_0010eb3c,"gsi_ctrl_dev_ioctl");
      lVar17 = -0x13;
    }
    goto LAB_00105ee8;
  }
  if (0x1c0 < (uVar19 << 6 | 0x38)) goto LAB_0010601c;
  lVar16 = *(long *)(*(long *)(inst_status + uVar19 * 0x40 + 0x38) + 0xb8);
  uVar15 = (uint)_cpu_hwcaps;
  if (*(int *)(lVar16 + 0x108) == 0) {
    if (param_2 == -0x7ffb90fb) goto LAB_00105ae4;
    if (param_2 != -0x7ffb8dfe) {
      if (lVar16 == 0) {
        lVar17 = -0x68;
      }
      else {
        ipc_log_string(*(undefined8 *)(lVar16 + 0x570),"%s:cmd %u failed, USB not connected\n",
                       "gsi_ctrl_dev_ioctl",param_2);
        _printk(&DAT_0010cc63,"gsi_ctrl_dev_ioctl",param_2);
        lVar17 = -0x68;
      }
      goto LAB_00105ee8;
    }
LAB_001059a0:
    local_7c = *(uint *)(lVar16 + 0x108);
    if (*(int *)(lVar16 + 0xd8) == 2) {
      local_7c = (uint)*(byte *)(lVar16 + 0x578);
    }
    puVar14 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
       (uVar19 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
      uVar19 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar19 < 0x7ffffffffd) {
      if ((uVar15 >> 0x1d & 1) == 0) {
        uVar19 = daif;
        if ((uVar19 & 0x80) == 0) {
          uVar7 = daif;
          daif = uVar7 | 0xc0;
        }
        puVar14 = (undefined8 *)puVar14[1];
        uVar7 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar14 & 0xffff000000000000 | uVar7 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar14;
        InstructionSynchronizationBarrier();
        daif = uVar19;
      }
      iVar10 = __arch_copy_to_user(puVar14,param_3 & 0xff7fffffffffffff,&local_7c,4);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar19 = daif;
        if ((uVar19 & 0x80) == 0) {
          uVar7 = daif;
          daif = uVar7 | 0xc0;
        }
        uVar7 = ttbr1_el1;
        ttbr0_el1 = (uVar7 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar7 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar19;
      }
      if (iVar10 != 0) goto LAB_00105a80;
      lVar17 = 0;
      if (lVar16 == 0) goto LAB_00105ee4;
    }
    else {
LAB_00105a80:
      lVar17 = -0xe00000000;
      if (lVar16 == 0) goto LAB_00105ee4;
      ipc_log_string(*(undefined8 *)(lVar16 + 0x570),"copy_to_user fail LINE_STATE");
      _printk(&DAT_0010c866);
    }
    ipc_log_string(*(undefined8 *)(lVar16 + 0x570),"%s: Sent line_state: %d for prot id:%d",
                   "gsi_ctrl_dev_ioctl",local_7c,*(undefined4 *)(lVar16 + 0xd8));
  }
  else if (param_2 < -0x7fef8dfd) {
    if (param_2 < -0x7ffb8dfe) {
      if (param_2 == -0x7ffd90fd) {
        puVar14 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
           (uVar19 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
          uVar19 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (uVar19 < 0x7fffffffff) {
          if ((uVar15 >> 0x1d & 1) == 0) {
            uVar19 = daif;
            if ((uVar19 & 0x80) == 0) {
              uVar7 = daif;
              daif = uVar7 | 0xc0;
            }
            puVar14 = (undefined8 *)puVar14[1];
            uVar7 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar14 & 0xffff000000000000 | uVar7 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar14;
            InstructionSynchronizationBarrier();
            daif = uVar19;
          }
          iVar10 = __arch_copy_to_user(puVar14,param_3 & 0xff7fffffffffffff,lVar16 + 0x248,2);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar19 = daif;
            if ((uVar19 & 0x80) == 0) {
              uVar7 = daif;
              daif = uVar7 | 0xc0;
            }
            uVar7 = ttbr1_el1;
            ttbr0_el1 = (uVar7 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar7 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar19;
          }
          if (iVar10 != 0) goto LAB_00105bd4;
          lVar17 = 0;
          if (lVar16 == 0) goto LAB_00105ee4;
        }
        else {
LAB_00105bd4:
          lVar17 = -0xe00000000;
          if (lVar16 == 0) goto LAB_00105ee4;
          ipc_log_string(*(undefined8 *)(lVar16 + 0x570),"copy_to_user fail DATAGRAM");
          _printk(&DAT_0010cfdf);
        }
        ipc_log_string(*(undefined8 *)(lVar16 + 0x570),"Sent NTB datagrams count %d",
                       *(undefined2 *)(lVar16 + 0x248));
      }
      else {
        if (param_2 != -0x7ffb90fe) goto LAB_00105ae4;
        puVar14 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
           (uVar19 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
          uVar19 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (uVar19 < 0x7ffffffffd) {
          if ((uVar15 >> 0x1d & 1) == 0) {
            uVar19 = daif;
            if ((uVar19 & 0x80) == 0) {
              uVar7 = daif;
              daif = uVar7 | 0xc0;
            }
            puVar14 = (undefined8 *)puVar14[1];
            uVar7 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar14 & 0xffff000000000000 | uVar7 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar14;
            InstructionSynchronizationBarrier();
            daif = uVar19;
          }
          iVar10 = __arch_copy_to_user(puVar14,param_3 & 0xff7fffffffffffff,lVar16 + 0x244,4);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar19 = daif;
            if ((uVar19 & 0x80) == 0) {
              uVar7 = daif;
              daif = uVar7 | 0xc0;
            }
            uVar7 = ttbr1_el1;
            ttbr0_el1 = (uVar7 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar7 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar19;
          }
          if (iVar10 != 0) goto LAB_00105768;
          lVar17 = 0;
          if (lVar16 == 0) goto LAB_00105ee4;
        }
        else {
LAB_00105768:
          lVar17 = -0xe00000000;
          if (lVar16 == 0) goto LAB_00105ee4;
          ipc_log_string(*(undefined8 *)(lVar16 + 0x570),"copy_to_user failNTB_SIZE");
          _printk(&DAT_0010e70e);
        }
        ipc_log_string(*(undefined8 *)(lVar16 + 0x570),"Sent NTB size %d",
                       *(undefined4 *)(lVar16 + 0x244));
      }
    }
    else {
      if (param_2 == -0x7ffb8dfe) goto LAB_001059a0;
      if (param_2 == -0x7fef90fc) goto LAB_00105958;
LAB_00105ae4:
      lVar17 = -0x1600000000;
      if (lVar16 != 0) {
        ipc_log_string(*(undefined8 *)(lVar16 + 0x570),"wrong parameter");
        puVar12 = &DAT_0010d38f;
LAB_00105b08:
        _printk(puVar12);
      }
    }
  }
  else if (param_2 < 0x7204) {
    if (param_2 != -0x7fef8dfd) {
      if (param_2 != -0x7fef8dfa) goto LAB_00105ae4;
      if ((*(long *)(lVar16 + 0x148) != 0) &&
         (local_78 = CONCAT44(*(int *)(lVar16 + 0x1b8) * *(int *)(lVar16 + 0x1c0),
                              *(int *)(lVar16 + 0x1c0)), lVar16 != 0)) {
        ipc_log_string(*(undefined8 *)(lVar16 + 0x570),"prot id :%d OUT: buf_len:%u total_len: %u",
                       *(undefined4 *)(lVar16 + 0xd8));
      }
      if ((*(long *)(lVar16 + 0x140) != 0) &&
         (local_70 = CONCAT44(*(int *)(lVar16 + 0x160) * *(int *)(lVar16 + 0x168),
                              *(int *)(lVar16 + 0x168)), lVar16 != 0)) {
        ipc_log_string(*(undefined8 *)(lVar16 + 0x570),"prot id :%d IN: buf_len:%u total_len:%u\n",
                       *(undefined4 *)(lVar16 + 0xd8));
      }
      puVar14 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
         (uVar19 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
        uVar19 = param_3 & (long)(param_3 << 8) >> 8;
      }
      if (uVar19 < 0x7ffffffff1) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar19 = daif;
          if ((uVar19 & 0x80) == 0) {
            uVar7 = daif;
            daif = uVar7 | 0xc0;
          }
          puVar14 = (undefined8 *)puVar14[1];
          uVar7 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar14 & 0xffff000000000000 | uVar7 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar14;
          InstructionSynchronizationBarrier();
          daif = uVar19;
        }
        iVar10 = __arch_copy_to_user(puVar14,param_3 & 0xff7fffffffffffff,&local_78,0x10);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar19 = daif;
          if ((uVar19 & 0x80) == 0) {
            uVar7 = daif;
            daif = uVar7 | 0xc0;
          }
          uVar7 = ttbr1_el1;
          ttbr0_el1 = (uVar7 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar7 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar19;
        }
        if (iVar10 == 0) goto LAB_00105c28;
      }
      lVar17 = -0xe00000000;
      if (lVar16 == 0) goto LAB_00105ee4;
      ipc_log_string(*(undefined8 *)(lVar16 + 0x570),"QTI_CTRL_DATA_BUF_INFO: copy_to_user failed");
      puVar12 = &DAT_0010cda9;
      goto LAB_00105b08;
    }
LAB_00105958:
    if (lVar16 != 0) {
      ipc_log_string(*(undefined8 *)(lVar16 + 0x570),"%s: EP_LOOKUP for prot id:%d",
                     "gsi_ctrl_dev_ioctl",*(undefined4 *)(lVar16 + 0xd8));
    }
    iVar10 = *(int *)(lVar16 + 0x224);
    if (*(int *)(lVar16 + 0xd8) == 4) {
      if (iVar10 == -0x16) {
LAB_00105c44:
        lVar17 = -0xb00000000;
        goto LAB_00105ee4;
      }
      uVar5 = *(undefined4 *)(lVar16 + 0xe0);
      uVar18 = 0xffffffff;
    }
    else {
      if ((iVar10 == -0x16) && (*(int *)(lVar16 + 0x228) == -0x16)) goto LAB_00105c44;
      uVar5 = *(undefined4 *)(lVar16 + 0xe0);
      uVar18 = *(undefined4 *)(lVar16 + 0x228);
    }
    local_68 = CONCAT44(uVar5,2);
    local_60 = CONCAT44(iVar10,uVar18);
    if (lVar16 != 0) {
      ipc_log_string(*(undefined8 *)(lVar16 + 0x570),"%s: prot id :%d ep_type:%d intf:%d",
                     "gsi_ctrl_dev_ioctl",*(int *)(lVar16 + 0xd8),2);
      ipc_log_string(*(undefined8 *)(lVar16 + 0x570),"%s: ipa_cons_idx:%d ipa_prod_idx:%d",
                     "gsi_ctrl_dev_ioctl",uVar18,iVar10);
    }
    puVar14 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
       (uVar19 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
      uVar19 = param_3 & (long)(param_3 << 8) >> 8;
    }
    iVar10 = 0x10;
    if (uVar19 < 0x7ffffffff1) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar19 = daif;
        if ((uVar19 & 0x80) == 0) {
          uVar7 = daif;
          daif = uVar7 | 0xc0;
        }
        puVar14 = (undefined8 *)puVar14[1];
        uVar7 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar14 & 0xffff000000000000 | uVar7 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar14;
        InstructionSynchronizationBarrier();
        daif = uVar19;
      }
      iVar10 = __arch_copy_to_user(puVar14,param_3 & 0xff7fffffffffffff,&local_68,0x10);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar19 = daif;
        if ((uVar19 & 0x80) == 0) {
          uVar7 = daif;
          daif = uVar7 | 0xc0;
        }
        uVar7 = ttbr1_el1;
        ttbr0_el1 = (uVar7 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar7 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar19;
      }
    }
    lVar17 = 0;
    if (iVar10 != 0) {
      lVar17 = -0xe00000000;
    }
    if ((lVar16 != 0) && (iVar10 != 0)) {
      ipc_log_string(*(undefined8 *)(lVar16 + 0x570),"copy_to_user fail MBIM");
      _printk(&DAT_0010d673);
      lVar17 = -0xe00000000;
    }
  }
  else {
    if (param_2 == 0x7205) {
      if (*(int *)(lVar16 + 0xd8) != 4) {
        lVar17 = 0;
        *(undefined4 *)(lVar16 + 0x4fc) = 1;
        goto LAB_00105ee4;
      }
      if (lVar16 != 0) {
        uVar11 = *(undefined8 *)(lVar16 + 0x570);
        pcVar13 = "%s:Modem Online not handled";
LAB_00105c1c:
        ipc_log_string(uVar11,pcVar13,"gsi_ctrl_dev_ioctl");
      }
    }
    else {
      if (param_2 != 0x7204) goto LAB_00105ae4;
      if (*(int *)(lVar16 + 0xd8) != 4) {
        lVar17 = lVar16 + 0x548;
        *(undefined4 *)(lVar16 + 0x4fc) = 0;
        uVar11 = _raw_spin_lock_irqsave(lVar17);
        plVar1 = (long *)(lVar16 + 0x530);
        plVar8 = *(long **)(lVar16 + 0x530);
        while (plVar8 != plVar1) {
          plVar20 = plVar8 + -2;
          plVar22 = (long *)*plVar8;
          uVar19 = __list_del_entry_valid(plVar8);
          if ((uVar19 & 1) != 0) {
            lVar3 = *plVar8;
            plVar4 = (long *)plVar8[1];
            *(long **)(lVar3 + 8) = plVar4;
            *plVar4 = lVar3;
          }
          *plVar8 = -0x2152ffffffffff00;
          plVar8[1] = -0x2152fffffffffede;
          plVar8 = plVar22;
          if (plVar20 != (long *)0x0) {
            kfree(*plVar20);
            kfree(plVar20);
          }
        }
        _raw_spin_unlock_irqrestore(lVar17,uVar11);
        puVar14 = (undefined8 *)kmalloc_trace(_mutex_unlock,0xdc0,0x20);
        if (puVar14 != (undefined8 *)0x0) {
          *(undefined4 *)(puVar14 + 1) = 0;
          *puVar14 = 0x10;
          if (puVar14 < (undefined8 *)0xfffffffffffff001) {
            *(undefined4 *)((long)puVar14 + 0xc) = 3;
            uVar11 = _raw_spin_lock_irqsave(lVar17);
            puVar21 = *(undefined8 **)(lVar16 + 0x538);
            puVar2 = puVar14 + 2;
            uVar19 = __list_add_valid(puVar2,puVar21,plVar1);
            if ((uVar19 & 1) != 0) {
              *(undefined8 **)(lVar16 + 0x538) = puVar2;
              puVar14[2] = plVar1;
              puVar14[3] = puVar21;
              *puVar21 = puVar2;
            }
            _raw_spin_unlock_irqrestore(lVar17,uVar11);
            gsi_ctrl_send_notification(lVar16);
            goto LAB_00105c28;
          }
        }
        if (lVar16 == 0) {
          lVar17 = -0xc;
        }
        else {
          ipc_log_string(*(undefined8 *)(lVar16 + 0x570),"%s: err allocating cpkt\n",
                         "gsi_ctrl_dev_ioctl");
          _printk(&DAT_0010d246,"gsi_ctrl_dev_ioctl");
          lVar17 = -0xc;
        }
        goto LAB_00105ee8;
      }
      if (lVar16 != 0) {
        uVar11 = *(undefined8 *)(lVar16 + 0x570);
        pcVar13 = "%s:Modem Offline not handled";
        goto LAB_00105c1c;
      }
    }
LAB_00105c28:
    lVar17 = 0;
  }
LAB_00105ee4:
  lVar17 = lVar17 >> 0x20;
LAB_00105ee8:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar17);
  }
  return;
}



//------------------------------------------------------------
// gsi_ctrl_dev_open @ 0010611c size=388
// signature: undefined gsi_ctrl_dev_open(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_ctrl_dev_open(long param_1,long param_2,undefined8 param_3)

{
  undefined1 *puVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  uint *puVar5;
  ulong uVar6;
  
  lVar4 = *(long *)(param_1 + 0x290);
  if (lVar4 == 0x10) {
    iVar3 = ___ratelimit(gsi_ctrl_dev_open__rs,"gsi_ctrl_dev_open",param_3,0);
    if (iVar3 != 0) {
      _printk(&DAT_0010d68c,"gsi_ctrl_dev_open",0);
      return 0xffffffed;
    }
  }
  else {
    puVar5 = (uint *)(lVar4 + -0x388);
    uVar6 = (ulong)*puVar5;
    if (7 < *puVar5) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10629c);
      (*pcVar2)();
    }
    puVar1 = inst_status + uVar6 * 0x40;
    if (lVar4 != 0x460) {
      ipc_log_string(*(undefined8 *)(lVar4 + 0x110),"%s: open ctrl dev %s","gsi_ctrl_dev_open");
    }
    mutex_lock(puVar1);
    *(uint **)(param_2 + 0xd8) = puVar5;
    if (0x1c0 < (uVar6 << 6 | 0x30)) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x1062a0);
      (*pcVar2)();
    }
    if (inst_status[uVar6 * 0x40 + 0x30] != '\0') {
      if (*(char *)(lVar4 + 0xa0) == '\0') {
        *(undefined1 *)(lVar4 + 0xa0) = 1;
        mutex_unlock(puVar1);
        return 0;
      }
      mutex_unlock(puVar1);
      if (lVar4 != 0x460) {
        ipc_log_string(*(undefined8 *)(lVar4 + 0x110),"%s: Already opened\n","gsi_ctrl_dev_open");
      }
      return 0xfffffff0;
    }
    mutex_unlock(puVar1);
    if (lVar4 != 0x460) {
      ipc_log_string(*(undefined8 *)(lVar4 + 0x110),
                     "%s: [prot_id = %d], GSI instance freed already\n","gsi_ctrl_dev_open",*puVar5)
      ;
      _printk(&DAT_0010e888,"gsi_ctrl_dev_open",*puVar5);
      return 0xffffffed;
    }
  }
  return 0xffffffed;
}



//------------------------------------------------------------
// gsi_ctrl_dev_release @ 001062a4 size=304
// signature: undefined gsi_ctrl_dev_release(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_ctrl_dev_release(undefined8 param_1,long param_2)

{
  long *plVar1;
  undefined1 *puVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  ulong uVar8;
  
  uVar3 = **(uint **)(param_2 + 0xd8);
  uVar8 = (ulong)uVar3;
  if (7 < uVar3) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1063d4);
    (*pcVar4)();
  }
  lVar7 = uVar8 * 0x40;
  puVar2 = inst_status + lVar7;
  mutex_lock(puVar2);
  if (0x1c0 < (uVar8 << 6 | 0x30)) {
LAB_001063cc:
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(1,0x1063d0);
    (*pcVar4)();
  }
  uVar8 = uVar8 << 6 | 0x38;
  plVar1 = (long *)(inst_status + lVar7 + 0x38);
  if (inst_status[lVar7 + 0x30] == '\0') {
    if (0x1c0 < uVar8) goto LAB_001063cc;
    if (*plVar1 != 0) {
      gsi_inst_clean();
      if (0x1c0 < uVar8) goto LAB_001063cc;
      *plVar1 = 0;
    }
    mutex_unlock(puVar2);
    iVar5 = ___ratelimit(gsi_ctrl_dev_release__rs,"gsi_ctrl_dev_release");
    if (iVar5 == 0) {
      uVar6 = 0xffffffed;
    }
    else {
      _printk(&DAT_0010d82a,"gsi_ctrl_dev_release",uVar3);
      uVar6 = 0xffffffed;
    }
  }
  else {
    if (0x1c0 < uVar8) goto LAB_001063cc;
    *(undefined1 *)(*(long *)(*plVar1 + 0xb8) + 0x500) = 0;
    lVar7 = *(long *)(*plVar1 + 0xb8);
    mutex_unlock(puVar2);
    if (lVar7 != 0) {
      if (0x1c0 < uVar8) goto LAB_001063cc;
      ipc_log_string(*(undefined8 *)(lVar7 + 0x570),"close ctrl dev %s\n",
                     *(long *)(*plVar1 + 0xb8) + 0x450);
    }
    uVar6 = 0;
  }
  return uVar6;
}



//------------------------------------------------------------
// gsi_ctrl_pkt_free @ 001063d4 size=56
// signature: undefined gsi_ctrl_pkt_free(void)
// callers: [ipa_usb_notify_cb]
//------------------------------------------------------------

void gsi_ctrl_pkt_free(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    kfree(*param_1);
    kfree(param_1);
  }
  return;
}



//------------------------------------------------------------
// gsi_ctrl_send_notification @ 0010640c size=960
// signature: undefined gsi_ctrl_send_notification(void)
// callers: [gsi_ctrl_dev_write, ipa_usb_notify_cb, gsi_ctrl_send_response_complete, gsi_ctrl_dev_ioctl, gsi_resume, gsi_rndis_response_available]
//------------------------------------------------------------

int gsi_ctrl_send_notification(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  char *pcVar6;
  undefined8 uVar7;
  long *plVar8;
  long lVar9;
  uint uVar10;
  undefined4 uVar11;
  long lVar12;
  long *plVar13;
  long *plVar14;
  undefined1 *puVar15;
  long lVar16;
  
  plVar14 = *(long **)(param_1 + 0x4f0);
  if (*(int *)(param_1 + 0x108) == 0) {
    if (param_1 == 0) {
      return -0x13;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: cable disconnect",
                   "gsi_ctrl_send_notification");
    return -0x13;
  }
  lVar1 = param_1 + 0x548;
  uVar4 = _raw_spin_lock_irqsave(lVar1);
  plVar13 = *(long **)(param_1 + 0x530);
  if (plVar13 == (long *)(param_1 + 0x530)) {
    _raw_spin_unlock_irqrestore(lVar1,uVar4);
    if (param_1 == 0) {
      return 0;
    }
    uVar4 = *(undefined8 *)(param_1 + 0x570);
    pcVar6 = "%s: cpkt_resp_q is empty\n";
LAB_001064dc:
    ipc_log_string(uVar4,pcVar6,"gsi_ctrl_send_notification");
    return 0;
  }
  if (param_1 == 0) {
    puVar15 = &DAT_000004f8;
    if (DAT_000004f8 != '\0') {
      _raw_spin_unlock_irqrestore(0x548,uVar4);
      return 0;
    }
  }
  else {
    ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: notify_req_queued:%d\n",
                   "gsi_ctrl_send_notification",*(undefined1 *)(param_1 + 0x4f8));
    if (*(char *)(param_1 + 0x4f8) != '\0') {
      _raw_spin_unlock_irqrestore(lVar1,uVar4);
      uVar4 = *(undefined8 *)(param_1 + 0x570);
      pcVar6 = "%s: notify_req is already queued.\n";
      goto LAB_001064dc;
    }
    plVar13 = *(long **)(param_1 + 0x530);
    puVar15 = (undefined1 *)(param_1 + 0x4f8);
    ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: cpkt->type:%d\n",
                   "gsi_ctrl_send_notification",*(undefined4 *)((long)plVar13 + -4));
  }
  if (3 < *(int *)((long)plVar13 + -4) - 1U) {
    _raw_spin_unlock_irqrestore(lVar1,uVar4);
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s:unknown notify state",
                     "gsi_ctrl_send_notification");
      _printk(&DAT_0010daee,"gsi_ctrl_send_notification");
    }
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x106598);
    (*pcVar2)();
  }
  lVar16 = *plVar14;
  switch(*(int *)((long)plVar13 + -4)) {
  case 1:
    *(undefined1 *)(lVar16 + 1) = 0;
    *(undefined2 *)(lVar16 + 2) = 1;
    break;
  case 2:
    plVar8 = *(long **)(*(long *)(param_1 + 0x30) + 0x30);
    *(undefined1 *)(lVar16 + 1) = 0x2a;
    *(undefined2 *)(lVar16 + 2) = 0;
    *(undefined2 *)(lVar16 + 6) = 8;
    lVar12 = *plVar8;
    lVar9 = *plVar14;
    if (*(uint *)(lVar12 + 0x5c) < 5) {
      if (2 < *(uint *)(lVar12 + 0x5c)) {
        uVar10 = *(uint *)(lVar12 + 0x58);
LAB_00106628:
        if (uVar10 == 3) {
          uVar11 = 0x19640000;
          goto LAB_00106640;
        }
      }
      uVar11 = 0x947000;
    }
    else {
      uVar10 = *(uint *)(lVar12 + 0x58);
      if (uVar10 < 5) goto LAB_00106628;
      uVar11 = 0x32c80000;
    }
LAB_00106640:
    *(undefined4 *)(lVar9 + 8) = uVar11;
    *(undefined4 *)(lVar9 + 0xc) = uVar11;
    if (param_1 != 0) {
      lVar9 = *plVar8;
      if (*(uint *)(lVar9 + 0x5c) < 5) {
        if (2 < *(uint *)(lVar9 + 0x5c)) {
          uVar10 = *(uint *)(lVar9 + 0x58);
LAB_00106680:
          if (uVar10 == 3) {
            uVar7 = 0x19640000;
            goto LAB_00106698;
          }
        }
        uVar7 = 0x947000;
      }
      else {
        uVar10 = *(uint *)(lVar9 + 0x58);
        if (uVar10 < 5) goto LAB_00106680;
        uVar7 = 0x32c80000;
      }
LAB_00106698:
      ipc_log_string(*(undefined8 *)(param_1 + 0x570),"notify speed %d",uVar7);
    }
    goto LAB_001066a4;
  case 3:
    *(undefined1 *)(lVar16 + 1) = 0;
    *(undefined2 *)(lVar16 + 2) = 0;
    break;
  case 4:
    *(undefined2 *)(lVar16 + 2) = 0;
    *(undefined2 *)(lVar16 + 6) = 0;
    *(undefined1 *)(lVar16 + 1) = 1;
    if (*(int *)(param_1 + 0xd8) == 0) {
      *(undefined8 *)*plVar14 = 1;
      goto LAB_001066a4;
    }
    goto LAB_001066e8;
  }
  *(undefined2 *)(lVar16 + 6) = 0;
LAB_001066a4:
  plVar14 = plVar13 + -2;
  uVar5 = __list_del_entry_valid(plVar13);
  if ((uVar5 & 1) != 0) {
    lVar9 = *plVar13;
    plVar8 = (long *)plVar13[1];
    *(long **)(lVar9 + 8) = plVar8;
    *plVar8 = lVar9;
  }
  *plVar13 = -0x2152ffffffffff00;
  plVar13[1] = -0x2152fffffffffede;
  if (plVar14 != (long *)0x0) {
    kfree(*plVar14);
    kfree(plVar14);
  }
LAB_001066e8:
  *puVar15 = 1;
  _raw_spin_unlock_irqrestore(lVar1,uVar4);
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x570),"send Notify type %02x",
                   *(undefined1 *)(lVar16 + 1));
  }
  if (*(char *)(param_1 + 0x128) == '\0') {
    iVar3 = usb_ep_queue(*(undefined8 *)(param_1 + 0x4e8),*(undefined8 *)(param_1 + 0x4f0),0xa20);
    if ((-1 < iVar3) && (*(char *)(param_1 + 0x128) == '\0')) goto LAB_00106738;
  }
  else {
    iVar3 = -0x5f;
  }
  uVar4 = _raw_spin_lock_irqsave(lVar1);
  *puVar15 = 0;
  _raw_spin_unlock_irqrestore(lVar1,uVar4);
LAB_00106738:
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: ret:%d req_queued:%d",
                   "queue_notification_request",iVar3,*puVar15);
  }
  return iVar3;
}



//------------------------------------------------------------
// gsi_ctrl_clear_cpkt_queues @ 001067d0 size=304
// signature: undefined gsi_ctrl_clear_cpkt_queues(void)
// callers: [gsi_disable, gsi_ctrl_notify_resp_complete]
//------------------------------------------------------------

void gsi_ctrl_clear_cpkt_queues(long param_1,ulong param_2)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  undefined8 uVar4;
  ulong uVar5;
  long *plVar6;
  long *plVar7;
  
  uVar4 = _raw_spin_lock_irqsave(param_1 + 0x548);
  if ((param_2 & 1) == 0) {
    plVar3 = *(long **)(param_1 + 0x520);
    while (plVar3 != (long *)(param_1 + 0x520)) {
      plVar6 = plVar3 + -2;
      plVar7 = (long *)*plVar3;
      uVar5 = __list_del_entry_valid(plVar3);
      if ((uVar5 & 1) != 0) {
        lVar1 = *plVar3;
        plVar2 = (long *)plVar3[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar3 = -0x2152ffffffffff00;
      plVar3[1] = -0x2152fffffffffede;
      plVar3 = plVar7;
      if (plVar6 != (long *)0x0) {
        kfree(*plVar6);
        kfree(plVar6);
      }
    }
  }
  plVar3 = *(long **)(param_1 + 0x530);
  while (plVar3 != (long *)(param_1 + 0x530)) {
    plVar6 = plVar3 + -2;
    plVar7 = (long *)*plVar3;
    uVar5 = __list_del_entry_valid(plVar3);
    if ((uVar5 & 1) != 0) {
      lVar1 = *plVar3;
      plVar2 = (long *)plVar3[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *plVar3 = -0x2152ffffffffff00;
    plVar3[1] = -0x2152fffffffffede;
    plVar3 = plVar7;
    if (plVar6 != (long *)0x0) {
      kfree(*plVar6);
      kfree(plVar6);
    }
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x548,uVar4);
  return;
}



//------------------------------------------------------------
// gsi_inst_clean @ 00106900 size=124
// signature: undefined gsi_inst_clean(void)
// callers: [gsi_ctrl_dev_release]
//------------------------------------------------------------

void gsi_inst_clean(long param_1)

{
  uint uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xb8);
  uVar1 = *(uint *)(lVar2 + 0x4e0);
  if (uVar1 != 0) {
    device_destroy(gsi_class);
    cdev_del(lVar2 + 0x460);
    *(undefined4 *)(lVar2 + 0x4e0) = 0;
    ida_free(gsi_ida,uVar1 & 0xfffff);
    lVar2 = *(long *)(param_1 + 0xb8);
  }
  kfree(lVar2);
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// gsi_bind @ 00106980 size=4096
// signature: undefined gsi_bind(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int gsi_bind(long param_1,undefined8 *param_2)

{
  undefined1 uVar1;
  bool bVar2;
  bool bVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined5 *puVar9;
  ulong uVar10;
  ulong uVar11;
  undefined8 uVar12;
  byte bVar13;
  undefined8 *puVar14;
  undefined1 *puVar15;
  undefined **ppuVar16;
  undefined **ppuVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  undefined8 *puVar21;
  undefined8 uVar22;
  long lVar23;
  undefined1 *puVar24;
  undefined **ppuVar25;
  undefined4 uVar26;
  undefined8 uVar27;
  uint uVar28;
  undefined1 *puVar29;
  undefined1 *puVar30;
  undefined1 *puVar31;
  undefined1 *puVar32;
  undefined1 *local_110;
  undefined1 *local_b0;
  ulong local_a8;
  undefined1 *local_a0;
  long local_98;
  undefined1 *local_90;
  ulong local_88;
  ulong local_80;
  undefined1 *local_78;
  
  puVar14 = *(undefined8 **)(param_1 + 0x30);
  if (*(int *)(param_2 + 0x1b) == 4 || *(int *)(param_2 + 0x1b) == 2) {
    *(undefined4 *)((long)param_2 + 0xdc) = 0xffffffed;
  }
  else {
    iVar5 = usb_interface_id(param_1,param_2);
    *(int *)((long)param_2 + 0xdc) = iVar5;
    if (iVar5 < 0) {
      return iVar5;
    }
  }
  iVar5 = usb_interface_id(param_1,param_2);
  *(int *)(param_2 + 0x1c) = iVar5;
  if (iVar5 < 0) {
    return iVar5;
  }
  local_b0 = (undefined1 *)0x0;
  local_a8 = 0;
  local_98 = 0;
  local_90 = (undefined1 *)0x0;
  uVar27 = 0;
  uVar12 = 0;
  puVar18 = (undefined1 *)0x0;
  bVar2 = true;
  puVar29 = (undefined1 *)0x0;
  puVar31 = (undefined1 *)0x0;
  puVar32 = (undefined1 *)0x0;
  puVar24 = (undefined1 *)0x0;
  puVar19 = (undefined1 *)0x0;
  local_80 = 0;
  local_78 = qdss_gsi_data_intf_desc;
  puVar9 = (undefined5 *)0x0;
  uVar10 = 0;
  puVar21 = (undefined8 *)0x0;
  local_110 = (undefined1 *)0x0;
  lVar23 = 0;
  local_a0 = qdss_gsi_fs_data_desc;
  uVar11 = 0;
  puVar20 = qdss_gsi_hs_data_desc;
  puVar30 = qdss_gsi_ss_data_desc;
  local_88 = 0x20;
  ppuVar25 = &qdss_gsi_fs_data_only_desc;
  ppuVar17 = &qdss_gsi_hs_data_only_desc;
  uVar26 = 8;
  uVar7 = 0x4000;
  uVar22 = 0xf;
  bVar3 = true;
  ppuVar16 = &qdss_gsi_ss_data_only_desc;
  puVar15 = &qdss_gsi_string_defs;
  switch(*(undefined4 *)(param_2 + 0x1b)) {
  case 0:
    param_2[0x47] = 0x600000004000;
    uVar11 = rndis_register(gsi_rndis_response_available,param_2);
    if (0xfffffffffffff000 < uVar11) {
      return iVar5;
    }
    param_2[0x20] = uVar11;
    rndis_set_param_medium(uVar11,0,0);
    puVar21 = param_2 + 0x43;
    get_random_bytes((long)param_2 + 0x21e,6);
    *(byte *)((long)param_2 + 0x21e) = *(byte *)((long)param_2 + 0x21e) & 0xfc | 2;
    get_random_bytes(puVar21,6);
    *(byte *)(param_2 + 0x43) = *(byte *)(param_2 + 0x43) & 0xfc | 2;
    if (param_2 != (undefined8 *)0x0) {
      ipc_log_string(param_2[0xae],"setting host_ethaddr=%pM, device_ethaddr = %pM",puVar21,
                     (long)param_2 + 0x21e);
    }
    *(undefined4 *)(param_2 + 0x1d) = *(undefined4 *)puVar21;
    *(undefined2 *)((long)param_2 + 0xec) = *(undefined2 *)((long)param_2 + 0x21c);
    rndis_set_host_mac(param_2[0x20],param_2 + 0x1d);
    if (((param_2[0x1f] != 0) && (*(int *)((long)param_2 + 0xe4) != 0)) &&
       (iVar6 = rndis_set_param_vendor(param_2[0x20]), iVar6 != 0)) goto LAB_00107668;
    rndis_gsi_control_intf[5] = 0xe0;
    rndis_gsi_control_intf[6] = 1;
    rndis_gsi_control_intf[7] = 3;
    switch(*(undefined4 *)(param_2 + 0x22)) {
    case 0:
      *(undefined4 *)(param_2 + 0x22) = 3;
    case 3:
      rndis_gsi_control_intf[5] = 0xef;
      rndis_gsi_control_intf[6] = 4;
      rndis_gsi_control_intf[7] = 1;
      break;
    case 2:
      rndis_gsi_control_intf[5] = 0xef;
      rndis_gsi_control_intf[7] = 1;
      break;
    case 4:
      rndis_gsi_control_intf[5] = 0xef;
      rndis_gsi_control_intf[6] = 4;
      rndis_gsi_control_intf[7] = 2;
      break;
    case 5:
      rndis_gsi_control_intf[5] = 0xef;
      rndis_gsi_control_intf[6] = 4;
      break;
    case 6:
      rndis_gsi_control_intf[5] = 0xef;
      rndis_gsi_control_intf[7] = 4;
      rndis_gsi_control_intf[6] = 4;
      break;
    case 7:
      rndis_gsi_control_intf[5] = 0xef;
      rndis_gsi_control_intf[6] = 4;
      rndis_gsi_control_intf[7] = 5;
      break;
    case 8:
      rndis_gsi_control_intf[5] = 0xef;
      rndis_gsi_control_intf[6] = 4;
      rndis_gsi_control_intf[7] = 6;
      break;
    case 9:
      rndis_gsi_control_intf[5] = 0xef;
      rndis_gsi_control_intf[6] = 4;
      rndis_gsi_control_intf[7] = 7;
    }
    puVar21 = &rndis_gsi_iad_descriptor;
    lVar23 = 0;
    uVar10 = 0;
    local_90 = (undefined1 *)0x0;
    local_80 = 0;
    local_b0 = (undefined1 *)0x0;
    local_a8 = 8;
    puVar15 = &rndis_gsi_string_defs;
    local_a0 = rndis_gsi_fs_in_desc;
    ppuVar16 = &gsi_eth_ss_function;
    ppuVar17 = &gsi_eth_hs_function;
    local_88 = 0x40;
    ppuVar25 = &gsi_eth_fs_function;
    puVar18 = rndis_gsi_ss_notify_desc;
    puVar29 = rndis_gsi_ss_out_desc;
    puVar30 = rndis_gsi_ss_in_desc;
    puVar31 = rndis_gsi_hs_notify_desc;
    puVar32 = rndis_gsi_hs_out_desc;
    puVar20 = rndis_gsi_hs_in_desc;
    puVar24 = rndis_gsi_fs_notify_desc;
    puVar19 = rndis_gsi_fs_out_desc;
    local_110 = rndis_gsi_control_intf;
    uVar28 = 2;
    uVar12 = 0x6000;
    uVar22 = 0x32;
    uVar7 = 0x4000;
    local_98 = 1;
    uVar26 = 8;
    puVar9 = &rndis_gsi_union_desc;
    local_78 = rndis_gsi_data_intf;
    rndis_gsi_iad_descriptor._4_1_ = rndis_gsi_control_intf[5];
    rndis_gsi_iad_descriptor._5_1_ = rndis_gsi_control_intf[6];
    rndis_gsi_iad_descriptor._6_1_ = rndis_gsi_control_intf[7];
    goto LAB_00107194;
  case 1:
    param_2[0x47] = 0x80000000800;
    get_random_bytes((long)param_2 + 0x21e,6);
    *(byte *)((long)param_2 + 0x21e) = *(byte *)((long)param_2 + 0x21e) & 0xfc | 2;
    get_random_bytes(param_2 + 0x43,6);
    bVar13 = *(byte *)(param_2 + 0x43) & 0xfc | 2;
    *(byte *)(param_2 + 0x43) = bVar13;
    if (param_2 != (undefined8 *)0x0) {
      ipc_log_string(param_2[0xae],"setting host_ethaddr=%pM, device_ethaddr = %pM",param_2 + 0x43,
                     (long)param_2 + 0x21e);
      bVar13 = *(byte *)(param_2 + 0x43);
    }
    scnprintf(param_2 + 0x1d,0xe,"%02X%02X%02X%02X%02X%02X",bVar13,
              *(undefined1 *)((long)param_2 + 0x219),*(undefined1 *)((long)param_2 + 0x21a),
              *(undefined1 *)((long)param_2 + 0x21b),*(undefined1 *)((long)param_2 + 0x21c),
              *(undefined1 *)((long)param_2 + 0x21d));
    puVar15 = &ecm_gsi_string_defs;
    uVar28 = 0;
    puVar21 = (undefined8 *)0x0;
    local_a0 = ecm_gsi_fs_in_desc;
    uVar26 = 0x10;
    ppuVar16 = &ecm_gsi_ss_function;
    ppuVar17 = &ecm_gsi_hs_function;
    local_b0 = ecm_gsi_data_nop_intf;
    ppuVar25 = &ecm_gsi_fs_function;
    puVar18 = ecm_gsi_ss_notify_desc;
    puVar29 = ecm_gsi_ss_out_desc;
    local_90 = ecm_gsi_desc;
    local_88 = 0x40;
    puVar30 = ecm_gsi_ss_in_desc;
    puVar31 = ecm_gsi_hs_notify_desc;
    puVar32 = ecm_gsi_hs_out_desc;
    puVar20 = ecm_gsi_hs_in_desc;
    puVar24 = ecm_gsi_fs_notify_desc;
    puVar19 = ecm_gsi_fs_out_desc;
    puVar9 = &ecm_gsi_union_desc;
    uVar7 = 0x800;
    uVar12 = 0x800;
    local_78 = ecm_gsi_data_intf;
    local_110 = ecm_gsi_control_intf;
    local_a8 = 0;
    DAT_0010b9e8 = param_2 + 0x1d;
    goto LAB_0010718c;
  case 2:
    puVar9 = (undefined5 *)0x0;
    uVar10 = 0;
    puVar21 = (undefined8 *)0x0;
    local_110 = (undefined1 *)0x0;
    lVar23 = 0;
    uVar11 = 0;
    param_2[0x47] = 0x600000004000;
    puVar19 = rmnet_gsi_fs_out_desc;
    puVar24 = rmnet_gsi_fs_notify_desc;
    puVar20 = rmnet_gsi_hs_in_desc;
    local_80 = 0;
    local_78 = rmnet_gsi_interface_desc;
    puVar32 = rmnet_gsi_hs_out_desc;
    puVar31 = rmnet_gsi_hs_notify_desc;
    local_a0 = rmnet_gsi_fs_in_desc;
    puVar30 = rmnet_gsi_ss_in_desc;
    puVar29 = rmnet_gsi_ss_out_desc;
    puVar18 = rmnet_gsi_ss_notify_desc;
    ppuVar25 = &rmnet_gsi_fs_function;
    ppuVar17 = &rmnet_gsi_hs_function;
    uVar22 = 0x32;
    uVar12 = 0x7c00;
    uVar27 = 0xe;
    local_88 = 0x20;
    uVar7 = 0x7c00;
    ppuVar16 = &rmnet_gsi_ss_function;
    puVar15 = &rmnet_gsi_string_defs;
    bVar2 = false;
    local_b0 = (undefined1 *)0x0;
    local_a8 = 0;
    local_98 = 0;
    local_90 = (undefined1 *)0x0;
    break;
  case 3:
    lVar23 = 0;
    puVar15 = &mbim_gsi_string_defs;
    param_2[0x47] = 0x600000004000;
    mbim_gsi_desc._9_2_ = 0x800;
    uVar26 = 8;
    ppuVar16 = &mbim_gsi_ss_function;
    local_a8 = 8;
    ppuVar17 = &mbim_gsi_hs_function;
    ppuVar25 = &mbim_gsi_fs_function;
    puVar18 = mbim_gsi_ss_notify_desc;
    local_a0 = mbim_gsi_fs_in_desc;
    puVar29 = mbim_gsi_ss_out_desc;
    puVar30 = mbim_gsi_ss_in_desc;
    local_b0 = mbim_gsi_data_nop_intf;
    puVar31 = mbim_gsi_hs_notify_desc;
    puVar32 = mbim_gsi_hs_out_desc;
    local_88 = 0x30;
    puVar20 = mbim_gsi_hs_in_desc;
    puVar24 = mbim_gsi_fs_notify_desc;
    puVar19 = mbim_gsi_fs_out_desc;
    puVar9 = &mbim_gsi_union_desc;
    puVar21 = &mbim_gsi_iad_desc;
    uVar28 = 0xffffffff;
    uVar22 = 0xf;
    uVar7 = 0x4000;
    local_80 = 9;
    local_98 = 1;
    local_78 = mbim_gsi_data_intf;
    local_110 = mbim_gsi_control_intf;
    if (param_2 == (undefined8 *)0x0) {
      uVar10 = 0;
      local_90 = (undefined1 *)0x0;
      uVar12 = 0x4000;
      goto LAB_00107194;
    }
    uVar10 = 0;
    uVar12 = 0x4000;
    local_90 = (undefined1 *)0x0;
    if (*(byte *)(param_1 + 0x28) - 5 < 0xfffffffd) goto LAB_00107194;
    ipc_log_string(param_2[0xae],"MBIM in configuration %d");
    lVar23 = 0;
    uVar10 = 0;
    puVar15 = &mbim_gsi_string_defs;
    ppuVar16 = &mbim_gsi_ss_function;
    local_a8 = 8;
    ppuVar17 = &mbim_gsi_hs_function;
    ppuVar25 = &mbim_gsi_fs_function;
    local_a0 = mbim_gsi_fs_in_desc;
    puVar18 = mbim_gsi_ss_notify_desc;
    puVar29 = mbim_gsi_ss_out_desc;
    puVar30 = mbim_gsi_ss_in_desc;
    local_b0 = mbim_gsi_data_nop_intf;
    puVar31 = mbim_gsi_hs_notify_desc;
    puVar32 = mbim_gsi_hs_out_desc;
    puVar20 = mbim_gsi_hs_in_desc;
    local_88 = 0x30;
    puVar24 = mbim_gsi_fs_notify_desc;
    puVar19 = mbim_gsi_fs_out_desc;
    puVar21 = &mbim_gsi_iad_desc;
    uVar7 = 0x4000;
    local_98 = 1;
    uVar12 = 0x4000;
    local_78 = mbim_gsi_data_intf;
    local_110 = mbim_gsi_control_intf;
    local_90 = (undefined1 *)0x0;
    uVar28 = 0xffffffff;
    uVar26 = 8;
    goto LAB_00107190;
  case 4:
    break;
  default:
    if (param_2 == (undefined8 *)0x0) {
      return -0x16;
    }
    ipc_log_string(param_2[0xae],"%s: Invalid prot id %d","gsi_bind");
    _printk(&DAT_0010c5ea,"gsi_bind",*(undefined4 *)(param_2 + 0x1b));
    return -0x16;
  case 6:
    param_2[0x47] = 0x600000004000;
    get_random_bytes((long)param_2 + 0x21e,6);
    *(byte *)((long)param_2 + 0x21e) = *(byte *)((long)param_2 + 0x21e) & 0xfc | 2;
    get_random_bytes(param_2 + 0x43,6);
    bVar13 = *(byte *)(param_2 + 0x43) & 0xfc | 2;
    *(byte *)(param_2 + 0x43) = bVar13;
    if (param_2 != (undefined8 *)0x0) {
      ipc_log_string(param_2[0xae],"setting host_ethaddr=%pM, device_ethaddr = %pM",param_2 + 0x43,
                     (long)param_2 + 0x21e);
      bVar13 = *(byte *)(param_2 + 0x43);
    }
    scnprintf(param_2 + 0x1d,0xe,"%02X%02X%02X%02X%02X%02X",bVar13,
              *(undefined1 *)((long)param_2 + 0x219),*(undefined1 *)((long)param_2 + 0x21a),
              *(undefined1 *)((long)param_2 + 0x21b),*(undefined1 *)((long)param_2 + 0x21c),
              *(undefined1 *)((long)param_2 + 0x21d));
    puVar15 = &ncm_string_defs;
    ppuVar16 = &ncm_ss_function;
    ppuVar17 = &ncm_hs_function;
    local_a8 = 8;
    ppuVar25 = &ncm_fs_function;
    puVar18 = ss_ncm_notify_desc;
    local_a0 = fs_ncm_in_desc;
    puVar29 = ss_ncm_out_desc;
    puVar30 = ss_ncm_in_desc;
    local_b0 = ncm_data_nop_intf;
    puVar31 = hs_ncm_notify_desc;
    puVar32 = hs_ncm_out_desc;
    local_90 = ecm_desc;
    local_88 = 0x50;
    puVar20 = hs_ncm_in_desc;
    puVar24 = fs_ncm_notify_desc;
    puVar19 = fs_ncm_out_desc;
    puVar9 = &ncm_union_desc;
    puVar21 = &ncm_iad_desc;
    uVar28 = 3;
    uVar7 = 0x4000;
    uVar12 = 0x4000;
    uVar26 = 8;
    local_78 = ncm_data_intf;
    local_110 = ncm_control_intf;
    PTR_DAT_0010baa8 = (undefined *)(param_2 + 0x1d);
LAB_0010718c:
    local_98 = 2;
    uVar10 = 0xd;
    lVar23 = 1;
LAB_00107190:
    local_80 = 9;
    uVar22 = 0xf;
LAB_00107194:
    iVar5 = usb_string_id(puVar14);
    if (iVar5 < 0) goto LAB_00107668;
    *puVar15 = (char)iVar5;
    bVar2 = false;
    bVar3 = false;
    local_110[8] = (char)iVar5;
    uVar27 = 0xe;
    uVar11 = (ulong)uVar28;
  }
  iVar5 = usb_string_id(puVar14);
  if (iVar5 < 0) goto LAB_00107668;
  if (local_88 == local_98 * 0x10) goto LAB_0010797c;
  puVar15[local_98 * 0x10] = (char)iVar5;
  local_78[8] = (char)iVar5;
  if ((puVar21 != (undefined8 *)0x0) && (-1 < (int)uVar11)) {
    iVar5 = usb_string_id(uVar11,puVar14);
    if (iVar5 < 0) goto LAB_00107668;
    if (local_88 <= uVar11 * 0x10) goto LAB_0010797c;
    puVar15[uVar11 * 0x10] = (char)iVar5;
    if (local_a8 < 7) goto LAB_0010797c;
    *(char *)((long)puVar21 + 7) = (char)iVar5;
  }
  if (local_90 != (undefined1 *)0x0) {
    iVar5 = usb_string_id(puVar14);
    if (iVar5 < 0) goto LAB_00107668;
    puVar15[lVar23 * 0x10] = (char)iVar5;
    if (uVar10 < 3) goto LAB_0010797c;
    local_90[3] = (char)iVar5;
  }
  if (local_110 != (undefined1 *)0x0) {
    if (bVar3) goto LAB_0010797c;
    local_110[2] = (char)*(undefined4 *)((long)param_2 + 0xdc);
  }
  if (puVar21 != (undefined8 *)0x0) {
    if (local_a8 < 2) goto LAB_0010797c;
    *(char *)((long)puVar21 + 2) = (char)*(undefined4 *)((long)param_2 + 0xdc);
  }
  if (puVar9 != (undefined5 *)0x0) {
    if (bVar3) goto LAB_0010797c;
    *(char *)((long)puVar9 + 3) = (char)*(undefined4 *)((long)param_2 + 0xdc);
    *(char *)((long)puVar9 + 4) = (char)*(undefined4 *)(param_2 + 0x1c);
  }
  local_78[2] = (char)*(undefined4 *)(param_2 + 0x1c);
  if (local_b0 != (undefined1 *)0x0) {
    if (local_80 < 2) goto LAB_0010797c;
    local_b0[2] = (char)*(undefined4 *)(param_2 + 0x1c);
  }
  puVar21 = (undefined8 *)usb_ep_autoconfig(*puVar14,local_a0);
  if (puVar21 != (undefined8 *)0x0) {
    param_2[0x28] = puVar21;
    msm_ep_set_mode(puVar21,2);
    *puVar21 = puVar14;
    if (puVar19 != (undefined1 *)0x0) {
      puVar21 = (undefined8 *)usb_ep_autoconfig(*puVar14);
      if (puVar21 == (undefined8 *)0x0) goto LAB_00107614;
      param_2[0x29] = puVar21;
      msm_ep_set_mode(puVar21,2);
      *puVar21 = puVar14;
    }
    if (puVar24 == (undefined1 *)0x0) {
LAB_00107534:
      param_2[0x2c] = uVar22;
      param_2[0x2d] = uVar7;
      if (param_2[0x29] != 0) {
        param_2[0x37] = uVar27;
        param_2[0x38] = uVar12;
      }
      *(undefined4 *)(param_2 + 0x6d) = 0;
      *(undefined2 *)((long)param_2 + 0x364) = 0x7f7f;
      uVar1 = local_a0[2];
      puVar20[2] = uVar1;
      puVar30[2] = uVar1;
      if (puVar19 != (undefined1 *)0x0) {
        if (bVar2) goto LAB_0010797c;
        puVar32[2] = puVar19[2];
        puVar29[2] = puVar19[2];
      }
      if (puVar24 != (undefined1 *)0x0) {
        if (bVar2) {
LAB_0010797c:
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(1,0x107980);
          (*pcVar4)();
        }
        puVar31[2] = puVar24[2];
        puVar18[2] = puVar24[2];
      }
      iVar5 = usb_assign_descriptors(param_2,ppuVar25,ppuVar17,ppuVar16,ppuVar16);
      if (iVar5 == 0) {
        iVar5 = wait_for_completion_timeout(&wait_for_ipa_ready,0x4e2);
        pcVar4 = ipa_ops;
        if (iVar5 == 0) {
          if (param_2 == (undefined8 *)0x0) {
            iVar5 = -0x6e;
          }
          else {
            ipc_log_string(param_2[0xae],"%s: ipa ready timeout","gsi_complete_bind");
            _printk(&DAT_0010d972,"gsi_complete_bind");
            iVar5 = -0x6e;
          }
        }
        else {
          param_2[0x89] = &ipa_ops;
          param_2[0x42] = ipa_usb_notify_cb;
          if (*(int *)(pcVar4 + -4) != 0x14e35d3a) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x107704);
            (*pcVar4)();
          }
          iVar5 = (*pcVar4)(*(undefined4 *)(param_2 + 0x1b),param_2 + 0x43,ipa_usb_notify_cb,param_2
                           );
          if (iVar5 == 0) {
            *(undefined4 *)(param_2 + 0x5c) = 1;
            return 0;
          }
          if (param_2 != (undefined8 *)0x0) {
            ipc_log_string(param_2[0xae],"%s: failed to init teth prot(%d) with err:%d",
                           "gsi_complete_bind",*(undefined4 *)(param_2 + 0x1b),iVar5);
            _printk(&DAT_0010d98a,"gsi_complete_bind",*(undefined4 *)(param_2 + 0x1b),iVar5);
          }
        }
        goto LAB_00107668;
      }
      if (*(int *)(param_2 + 0x1b) == 6) {
        kfree(*(undefined8 *)param_2[0x23]);
        usb_ep_free_request(param_2[0x9d],param_2[0x23]);
      }
      if (((long *)param_2[0x9e] != (long *)0x0) && (*(long *)param_2[0x9e] != 0)) {
        kfree();
      }
      goto LAB_00107604;
    }
    puVar21 = (undefined8 *)usb_ep_autoconfig(*puVar14,puVar24);
    if (puVar21 != (undefined8 *)0x0) {
      param_2[0x9d] = puVar21;
      *puVar21 = puVar14;
      lVar23 = usb_ep_alloc_request(puVar21,0xcc0);
      param_2[0x9e] = lVar23;
      if (lVar23 != 0) {
        uVar8 = __kmalloc(uVar26,0xcc0);
        *(undefined8 *)param_2[0x9e] = uVar8;
        if (*(long *)param_2[0x9e] == 0) {
LAB_00107604:
          lVar23 = param_2[0x9e];
        }
        else {
          *(undefined4 *)((long *)param_2[0x9e] + 1) = uVar26;
          *(undefined8 **)(param_2[0x9e] + 0x38) = param_2;
          *(code **)(param_2[0x9e] + 0x30) = gsi_ctrl_notify_resp_complete;
          puVar15 = *(undefined1 **)param_2[0x9e];
          *puVar15 = 0xa1;
          iVar5 = *(int *)((long)param_2 + 0xdc);
          if (iVar5 == -0x13) {
            iVar5 = *(int *)(param_2 + 0x1c);
          }
          *(short *)(puVar15 + 4) = (short)iVar5;
          if (*(int *)(param_2 + 0x1b) != 6) {
LAB_00107528:
            *(undefined2 *)(puVar15 + 6) = 0;
            goto LAB_00107534;
          }
          lVar23 = usb_ep_alloc_request(param_2[0x9d],0xcc0);
          param_2[0x23] = lVar23;
          if (lVar23 == 0) goto LAB_00107604;
          uVar8 = kmalloc_trace(_mutex_unlock,0xcc0,0x10);
          *(undefined8 *)param_2[0x23] = uVar8;
          if (*(long *)param_2[0x23] != 0) {
            ((long *)param_2[0x23])[7] = (long)param_2;
            *(code **)(param_2[0x23] + 0x30) = gsi_ncm_notify_complete;
            goto LAB_00107528;
          }
          usb_ep_free_request(param_2[0x9d]);
          param_2[0x23] = 0;
          lVar23 = param_2[0x9e];
        }
        if (lVar23 != 0) {
          usb_ep_free_request(param_2[0x9d]);
        }
      }
    }
  }
LAB_00107614:
  if ((undefined8 *)param_2[0x9d] != (undefined8 *)0x0) {
    *(undefined8 *)param_2[0x9d] = 0;
  }
  lVar23 = param_2[0x29];
  if ((lVar23 != 0) && (*(long *)(lVar23 + 0x38) != 0)) {
    msm_ep_set_mode(lVar23,0);
    *(undefined8 *)param_2[0x29] = 0;
  }
  lVar23 = param_2[0x28];
  if ((lVar23 != 0) && (*(long *)(lVar23 + 0x38) != 0)) {
    msm_ep_set_mode(lVar23,0);
    *(undefined8 *)param_2[0x28] = 0;
  }
  if (param_2 != (undefined8 *)0x0) {
    ipc_log_string(param_2[0xae],"%s: bind failed for %s","gsi_update_function_bind_params",*param_2
                  );
    _printk(&DAT_0010db6d,"gsi_update_function_bind_params",*param_2);
  }
  iVar5 = -0xc;
LAB_00107668:
  rndis_deregister(param_2[0x20]);
  return iVar5;
}



//------------------------------------------------------------
// gsi_unbind @ 00107984 size=316
// signature: undefined gsi_unbind(void)
// callers: []
//------------------------------------------------------------

void gsi_unbind(undefined8 param_1,long param_2)

{
  code *pcVar1;
  
  if (param_2 != 0) {
    ipc_log_string(*(undefined8 *)(param_2 + 0x570),"%s:id:%d: dwq start","gsi_unbind",
                   *(undefined4 *)(param_2 + 0xd8));
  }
  if (*(int *)(param_2 + 0x108) != 0) {
    gsi_disable(param_2);
  }
  drain_workqueue(*(undefined8 *)(param_2 + 0x2d8));
  if (param_2 != 0) {
    ipc_log_string(*(undefined8 *)(param_2 + 0x570),"%s:id:%d: dwq end","gsi_unbind",
                   *(undefined4 *)(param_2 + 0xd8));
  }
  pcVar1 = *(code **)(*(long *)(param_2 + 0x448) + 0x18);
  if (*(int *)(pcVar1 + -4) != 0x1ff561ac) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x107a14);
    (*pcVar1)();
  }
  (*pcVar1)(*(undefined4 *)(param_2 + 0xd8));
  rndis_gsi_string_defs = 0;
  ecm_gsi_string_defs = 0;
  rmnet_gsi_string_defs = 0;
  mbim_gsi_string_defs = 0;
  qdss_gsi_string_defs = 0;
  ncm_string_defs = 0;
  if (*(int *)(param_2 + 0xd8) == 0) {
    *(undefined4 *)(param_2 + 0x2e0) = 0;
    rndis_deregister(*(undefined8 *)(param_2 + 0x100));
  }
  usb_free_all_descriptors(param_2);
  if (*(long *)(param_2 + 0x4e8) != 0) {
    kfree(**(undefined8 **)(param_2 + 0x4f0));
    usb_ep_free_request(*(undefined8 *)(param_2 + 0x4e8),*(undefined8 *)(param_2 + 0x4f0));
    if ((*(long *)(param_2 + 0x4e8) != 0) && (*(int *)(param_2 + 0xd8) == 6)) {
      kfree(**(undefined8 **)(param_2 + 0x118));
      usb_ep_free_request(*(undefined8 *)(param_2 + 0x4e8),*(undefined8 *)(param_2 + 0x118));
    }
  }
  return;
}



//------------------------------------------------------------
// gsi_set_alt @ 00107ac4 size=1408
// signature: undefined gsi_set_alt(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 gsi_set_alt(long param_1,int param_2,uint param_3)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  int iVar5;
  undefined *puVar6;
  long *plVar7;
  uint uVar8;
  long lVar9;
  ulong uVar10;
  undefined1 uVar11;
  undefined8 uVar12;
  undefined8 *puVar13;
  
  puVar13 = *(undefined8 **)(*(long *)(param_1 + 0x30) + 0x30);
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x570),"intf=%u, alt=%u",param_2,param_3);
  }
  if (*(int *)(param_1 + 0xdc) == param_2) {
    if (param_3 == 0) goto LAB_00107b30;
  }
  else if ((param_3 == 0) && (*(int *)(param_1 + 0xd8) == 2)) {
LAB_00107b30:
    plVar7 = *(long **)(param_1 + 0x4e8);
    if (plVar7 != (long *)0x0) {
      if (*plVar7 != 0) {
        usb_ep_disable(plVar7);
        plVar7 = *(long **)(param_1 + 0x4e8);
      }
      iVar5 = config_ep_by_speed(*puVar13,param_1,plVar7);
      if (iVar5 != 0) {
        *(undefined8 *)(*(long *)(param_1 + 0x4e8) + 0x38) = 0;
        if (param_1 == 0) {
          return 0xffffffea;
        }
        ipc_log_string(*(undefined8 *)(param_1 + 0x570),"Config-fail notify ep %s: err %d",
                       *(undefined8 *)(*(long *)(param_1 + 0x4e8) + 8),iVar5);
        lVar9 = *(long *)(param_1 + 0x4e8);
        puVar6 = &DAT_0010dd7b;
LAB_00107bd0:
        _printk(puVar6,*(undefined8 *)(lVar9 + 8),iVar5);
        return 0xffffffea;
      }
      iVar5 = usb_ep_enable();
      if (iVar5 != 0) {
        if (param_1 == 0) {
          return 0xffffffea;
        }
        ipc_log_string(*(undefined8 *)(param_1 + 0x570),"usb ep#%s enable failed, err#%d",
                       *(undefined8 *)(*(long *)(param_1 + 0x4e8) + 8),iVar5);
        lVar9 = *(long *)(param_1 + 0x4e8);
        puVar6 = &DAT_0010d1b9;
        goto LAB_00107bd0;
      }
      **(long **)(param_1 + 0x4e8) = param_1;
    }
  }
  if (*(int *)(param_1 + 0xe0) != param_2) {
    uVar12 = 0;
    goto LAB_00107f14;
  }
  uVar8 = *(uint *)(param_1 + 0xd8);
  *(undefined1 *)(param_1 + 0x241) = 0;
  if ((uVar8 < 7) && ((1 << (ulong)(uVar8 & 0x1f) & 0x55U) != 0)) {
    if ((*(long **)(param_1 + 0x140) == (long *)0x0) || (**(long **)(param_1 + 0x140) != 0)) {
      param_3 = 0;
    }
    else {
      param_3 = 1;
    }
  }
  else if (1 < param_3) goto LAB_00107f70;
  if (param_3 == *(byte *)(param_1 + 0x10c)) {
LAB_00107c54:
    uVar12 = 0;
    *(char *)(param_1 + 0x10c) = (char)param_3;
joined_r0x00107ef8:
    if (param_1 == 0) goto LAB_00107f14;
  }
  else {
    plVar7 = *(long **)(param_1 + 0x140);
    if (plVar7 == (long *)0x0) {
      if (param_3 != 0) goto LAB_00107c9c;
LAB_00107ce4:
      if ((*(long **)(param_1 + 0x148) != (long *)0x0) && (**(long **)(param_1 + 0x148) == 0))
      goto LAB_00107cf4;
      goto LAB_00107c54;
    }
    if (*plVar7 != 0) {
      *(undefined4 *)(param_1 + 0x244) = 0x4000;
    }
    if (param_3 != 0) {
      if (plVar7 != (long *)0x0) {
        uVar11 = 2;
        if (uVar8 == 4) {
          uVar11 = 3;
        }
        *(undefined1 *)(param_1 + 0x184) = uVar11;
      }
LAB_00107c9c:
      if (*(long *)(param_1 + 0x148) != 0) {
        *(undefined1 *)(param_1 + 0x1dc) = 1;
      }
      uVar12 = *puVar13;
      *(undefined8 **)(param_1 + 0x208) = puVar13;
      *(undefined8 *)(param_1 + 0x200) = uVar12;
      if (uVar8 == 0) {
        lVar9 = **(long **)(*(long *)(param_1 + 0x30) + 0x30);
        if (*(uint *)(lVar9 + 0x5c) < 5) {
          if (2 < *(uint *)(lVar9 + 0x5c)) {
            uVar8 = *(uint *)(lVar9 + 0x58);
LAB_00107d8c:
            if (uVar8 == 3) {
              uVar12 = 0x410000;
              goto LAB_00107da4;
            }
          }
          uVar12 = 0x17c00;
        }
        else {
          uVar8 = *(uint *)(lVar9 + 0x58);
          if (uVar8 < 5) goto LAB_00107d8c;
          uVar12 = 0x820000;
        }
LAB_00107da4:
        rndis_set_param_medium(*(undefined8 *)(param_1 + 0x100),0,uVar12);
        rndis_signal_connect(*(undefined8 *)(param_1 + 0x100));
        uVar10 = dev_get_by_name(&init_net,"rndis0");
        if (uVar10 == 0) goto LAB_00107f70;
        lVar9 = sp_el0;
        *(int *)(lVar9 + 0x10) = *(int *)(lVar9 + 0x10) + 1;
        lVar4 = tpidr_el1;
        piVar1 = (int *)(lVar4 + *(long *)(uVar10 + 0x4d8));
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar3) {
            *piVar1 = *piVar1 + -1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        lVar4 = *(long *)(lVar9 + 0x10) + -1;
        *(int *)(lVar9 + 0x10) = (int)lVar4;
        if ((lVar4 == 0) || (*(long *)(lVar9 + 0x10) == 0)) {
          preempt_schedule_notrace();
        }
        if (0xfffffffffffff000 < uVar10) goto LAB_00107f70;
        if (param_1 != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x570),"RNDIS RX/TX early activation");
        }
        *(undefined2 *)(param_1 + 0x236) = 0;
        rndis_set_param_dev(*(undefined8 *)(param_1 + 0x100),uVar10,param_1 + 0x236);
        uVar8 = *(uint *)(param_1 + 0xd8);
      }
      if (uVar8 == 6) {
        if (((*(long *)(param_1 + 0x140) == 0) || (*(long *)(param_1 + 0x148) == 0)) &&
           ((iVar5 = config_ep_by_speed(*puVar13,param_1), iVar5 != 0 ||
            (iVar5 = config_ep_by_speed(*puVar13,param_1,*(undefined8 *)(param_1 + 0x148)),
            iVar5 != 0)))) {
          *(undefined8 *)(*(long *)(param_1 + 0x140) + 0x38) = 0;
          *(undefined8 *)(*(long *)(param_1 + 0x148) + 0x38) = 0;
LAB_00107f70:
          if ((*(long **)(param_1 + 0x4e8) != (long *)0x0) && (**(long **)(param_1 + 0x4e8) != 0)) {
            usb_ep_disable();
          }
          return 0xffffffea;
        }
      }
      else if (uVar8 == 1) {
        *(undefined2 *)(param_1 + 0x236) = 0xf;
      }
      uVar12 = _raw_spin_lock_irqsave(param_1 + 0x368);
      uVar10 = (ulong)(*(byte *)(param_1 + 0x365) + 1) & 0x7f;
      *(char *)(param_1 + 0x365) = (char)uVar10;
      if ((uint)uVar10 == (uint)*(byte *)(param_1 + 0x364)) {
        if (param_1 != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: event queue overflow error",
                         "post_event");
          _printk(&DAT_0010dbb8,"post_event");
        }
      }
      else {
        *(undefined1 *)(param_1 + uVar10 + 0x2e4) = 3;
      }
      _raw_spin_unlock_irqrestore(param_1 + 0x368,uVar12);
      queue_delayed_work_on(0x20,*(undefined8 *)(param_1 + 0x2d8),param_1 + 0x250,1);
      uVar12 = 0x7fff;
      *(char *)(param_1 + 0x10c) = (char)param_3;
      goto joined_r0x00107ef8;
    }
    if ((plVar7 == (long *)0x0) || (*plVar7 != 0)) goto LAB_00107ce4;
LAB_00107cf4:
    uVar12 = _raw_spin_lock_irqsave(param_1 + 0x368);
    uVar10 = (ulong)(*(byte *)(param_1 + 0x365) + 1) & 0x7f;
    *(char *)(param_1 + 0x365) = (char)uVar10;
    if ((uint)uVar10 == (uint)*(byte *)(param_1 + 0x364)) {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: event queue overflow error",
                       "post_event");
        _printk(&DAT_0010dbb8,"post_event");
        goto LAB_00107fb0;
      }
      _raw_spin_unlock_irqrestore(0x368,uVar12);
      queue_delayed_work_on(0x20,_DAT_000002d8,0x250,0);
LAB_00107ff8:
      uVar12 = 0;
      *(undefined1 *)(param_1 + 0x10c) = 0;
      goto LAB_00107f14;
    }
    *(undefined1 *)(param_1 + uVar10 + 0x2e4) = 7;
LAB_00107fb0:
    _raw_spin_unlock_irqrestore(param_1 + 0x368,uVar12);
    queue_delayed_work_on(0x20,*(undefined8 *)(param_1 + 0x2d8),param_1 + 0x250,0);
    if (param_1 == 0) goto LAB_00107ff8;
    ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: Disconnecting\n","gsi_handle_data_alt");
    uVar12 = 0;
    *(undefined1 *)(param_1 + 0x10c) = 0;
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x570),"DATA_INTERFACE id = %d, status = %d",
                 *(undefined4 *)(param_1 + 0xe0),param_3);
LAB_00107f14:
  *(undefined4 *)(param_1 + 0x108) = 1;
  if (*(int *)(param_1 + 0xd8) == 4) {
    gsi_ctrl_send_cpkt_tomodem(param_1,0,0);
  }
  return uVar12;
}



//------------------------------------------------------------
// gsi_get_alt @ 00108048 size=88
// signature: undefined gsi_get_alt(void)
// callers: []
//------------------------------------------------------------

ulong gsi_get_alt(long param_1,int param_2)

{
  if (*(int *)(param_1 + 0xdc) == param_2) {
    return 0;
  }
  if ((*(uint *)(param_1 + 0xd8) < 5) &&
     ((1 << (ulong)(*(uint *)(param_1 + 0xd8) & 0x1f) & 0x15U) != 0)) {
    return 0;
  }
  if (*(int *)(param_1 + 0xe0) == param_2) {
    return (ulong)*(byte *)(param_1 + 0x10c);
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// gsi_setup @ 001080a4 size=1960
// signature: undefined gsi_setup(void)
// callers: []
//------------------------------------------------------------

uint gsi_setup(long param_1,undefined1 *param_2)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  long *plVar4;
  ushort uVar5;
  short sVar6;
  ushort uVar7;
  ushort uVar8;
  uint uVar9;
  ulong uVar10;
  undefined8 uVar11;
  int *__src;
  char *pcVar12;
  uint uVar13;
  uint uVar14;
  undefined8 *puVar15;
  uint uVar16;
  long *plVar17;
  uint uVar18;
  long *plVar19;
  long *plVar20;
  uint local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  plVar20 = *(long **)(*(long *)(param_1 + 0x30) + 0x30);
  puVar15 = (undefined8 *)plVar20[1];
  if (*(int *)(param_1 + 0x108) == 0) {
    if (param_1 == 0) {
      uVar9 = 0xffffff95;
    }
    else {
      ipc_log_string(*(undefined8 *)(param_1 + 0x570),"usb cable is not connected");
      uVar9 = 0xffffff95;
    }
    goto LAB_001087e8;
  }
  uVar5 = *(ushort *)(param_2 + 4);
  sVar6 = *(short *)(param_2 + 2);
  uVar8 = CONCAT11(*param_2,param_2[1]);
  uVar7 = *(ushort *)(param_2 + 6);
  uVar14 = (uint)uVar7;
  uVar16 = (uint)uVar5;
  uVar13 = uVar14;
  if (uVar8 < 0x218a) {
    if (uVar8 < 0x2143) {
      if (uVar8 == 0x2100) {
        uVar18 = *(uint *)(param_1 + 0xdc);
        if (uVar18 == 0xffffffed) {
          uVar18 = *(uint *)(param_1 + 0xe0);
        }
        if (param_1 != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x570),"USB_CDC_SEND_ENCAPSULATED_COMMAND");
        }
        uVar9 = 0xffffffa1;
        if ((sVar6 != 0) || (uVar18 != uVar16)) goto LAB_001087e8;
        puVar15[7] = param_1;
        pcVar2 = gsi_rndis_command_complete;
        if (*(int *)(param_1 + 0xd8) != 0) {
          pcVar2 = gsi_ctrl_cmd_complete;
        }
        puVar15[6] = pcVar2;
      }
      else if (uVar8 == 0x2105) {
        if (param_1 != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x570),"USB_CDC_RESET_FUNCTION");
        }
        puVar15[6] = gsi_ctrl_reset_cmd_complete;
        puVar15[7] = param_1;
        uVar13 = 0;
      }
      else {
        if (uVar8 != 0x2122) goto switchD_001081c8_caseD_a181;
        if (*(int *)(param_1 + 0xd8) == 2) {
          *(byte *)(param_1 + 0x578) = (byte)sVar6 & 1;
        }
        if (param_1 != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x570),
                         "%s: USB_CDC_REQ_SET_CONTROL_LINE_STATE DTR:%d\n",
                         "handle_set_control_line_state");
        }
        gsi_ctrl_send_cpkt_tomodem(param_1,0,0);
        uVar13 = 0;
      }
    }
    else if (uVar8 == 0x2143) {
      uVar13 = *(uint *)(param_1 + 0xdc);
      if (uVar13 == 0xffffffed) {
        uVar13 = *(uint *)(param_1 + 0xe0);
      }
      uVar9 = 0xffffffa1;
      if ((uVar14 != 0) || (uVar13 != uVar16)) goto LAB_001087e8;
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x570),"packet filter %02x",sVar6);
      }
      *(short *)(param_1 + 0x236) = sVar6;
      uVar13 = 0;
    }
    else if (uVar8 == 0x2184) {
      uVar13 = *(uint *)(param_1 + 0xdc);
      if (uVar13 == 0xffffffed) {
        uVar13 = *(uint *)(param_1 + 0xe0);
      }
      uVar9 = 0xffffffa1;
      if ((uVar14 != 0) || (uVar13 != uVar16)) goto LAB_001087e8;
      if (param_1 != 0) {
        uVar11 = *(undefined8 *)(param_1 + 0x570);
        pcVar12 = "Set NTB format as: %d\n";
        goto LAB_00108628;
      }
LAB_00108648:
      uVar13 = 0;
    }
    else {
      if (uVar8 != 0x2186) goto switchD_001081c8_caseD_a181;
      uVar9 = *(uint *)(param_1 + 0xdc);
      if (uVar9 == 0xffffffed) {
        uVar9 = *(uint *)(param_1 + 0xe0);
      }
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x570),"USB_CDC_SET_NTB_INPUT_SIZE");
      }
      if (((sVar6 == 0) && (uVar14 == 4 || uVar14 == 8)) && (uVar9 == uVar16)) {
        *(uint *)(puVar15 + 1) = uVar14;
        puVar15[6] = gsi_ctrl_set_ntb_cmd_complete;
        puVar15[7] = param_1;
      }
      else {
        if (param_1 == 0) goto LAB_00108648;
        ipc_log_string(*(undefined8 *)(param_1 + 0x570),"wrong NTB length %d",uVar7);
        _printk(&DAT_0010d7ae,uVar7);
        uVar13 = 0;
      }
    }
  }
  else {
    switch(uVar8) {
    case 0xa180:
      uVar9 = *(uint *)(param_1 + 0xdc);
      if (uVar9 == 0xffffffed) {
        uVar9 = *(uint *)(param_1 + 0xe0);
      }
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x570),"USB_CDC_GET_NTB_PARAMETERS");
      }
      uVar13 = 0;
      if (((sVar6 == 0) && (uVar7 != 0)) && (uVar9 == uVar16)) {
        uVar13 = uVar14;
        if (0x1b < uVar7) {
          uVar13 = 0x1c;
        }
        if (*(int *)(param_1 + 0xd8) == 6) {
          memcpy((void *)*puVar15,ncm_ntb_parameters,(ulong)uVar13);
          if (param_1 != 0) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x570),"Host asked NTB parameters");
          }
        }
        else {
          memcpy((void *)*puVar15,mbim_gsi_ntb_parameters,(ulong)uVar13);
        }
      }
      break;
    case 0xa181:
    case 0xa182:
    case 0xa184:
    case 0xa186:
    case 0xa187:
    case 0xa188:
switchD_001081c8_caseD_a181:
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x570),
                       "Invalid control request %02x.%02x v%04x i%04x l%d",*param_2,param_2[1],sVar6
                       ,uVar5,uVar7);
        _printk(&DAT_0010e44f,*param_2,param_2[1],sVar6,uVar5,uVar7);
        uVar9 = 0xffffffa1;
        goto LAB_001087e8;
      }
LAB_0010863c:
      uVar9 = 0xffffffa1;
      goto LAB_001087e8;
    case 0xa183:
      uVar9 = *(uint *)(param_1 + 0xdc);
      if (uVar9 == 0xffffffed) {
        uVar9 = *(uint *)(param_1 + 0xe0);
      }
      if (((sVar6 != 0) || (uVar14 < 2)) || (uVar9 != uVar16)) {
        if (param_1 != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x570),"Wrong NTB get format req\n");
          _printk(&DAT_0010dc04);
          uVar9 = 0xffffffa1;
          goto LAB_001087e8;
        }
        goto LAB_0010863c;
      }
      *(undefined2 *)*puVar15 = 0;
      if (param_1 != 0) {
        uVar11 = *(undefined8 *)(param_1 + 0x570);
        pcVar12 = "Host asked NTB Format.";
        goto LAB_00108508;
      }
LAB_00108650:
      uVar13 = 2;
      break;
    case 0xa185:
      uVar9 = *(uint *)(param_1 + 0xdc);
      if (uVar9 == 0xffffffed) {
        uVar9 = *(uint *)(param_1 + 0xe0);
      }
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x570),"USB_CDC_GET_NTB_INPUT_SIZE");
      }
      uVar13 = 0;
      if (((sVar6 == 0) && (3 < uVar14)) && (uVar9 == uVar16)) {
        *(undefined4 *)*puVar15 = *(undefined4 *)(param_1 + 0x244);
        if (param_1 == 0) {
          uVar13 = 4;
        }
        else {
          ipc_log_string(*(undefined8 *)(param_1 + 0x570),"Reply to host INPUT SIZE %d",
                         *(undefined4 *)(param_1 + 0x244));
          uVar13 = 4;
        }
      }
      break;
    case 0xa189:
      uVar13 = *(uint *)(param_1 + 0xdc);
      if (uVar13 == 0xffffffed) {
        uVar13 = *(uint *)(param_1 + 0xe0);
      }
      uVar9 = 0xffffffa1;
      if (((sVar6 != 0) || (uVar14 < 2)) || (uVar13 != uVar5)) goto LAB_001087e8;
      *(undefined2 *)*puVar15 = 0;
      if (param_1 == 0) goto LAB_00108650;
      uVar11 = *(undefined8 *)(param_1 + 0x570);
      pcVar12 = "Host asked CRC Format. Gave 0x0000";
LAB_00108508:
      ipc_log_string(uVar11,pcVar12);
      uVar13 = 2;
      break;
    default:
      if (uVar8 == 0x218a) {
        if (uVar14 != 0) goto LAB_0010863c;
        if (param_1 == 0) goto LAB_00108648;
        uVar11 = *(undefined8 *)(param_1 + 0x570);
        pcVar12 = "Host asked to set CRC format as: %d\n";
LAB_00108628:
        ipc_log_string(uVar11,pcVar12,sVar6);
        uVar13 = 0;
      }
      else {
        if (uVar8 != 0xa101) goto switchD_001081c8_caseD_a181;
        uVar9 = *(uint *)(param_1 + 0xdc);
        local_5c = 0;
        if (uVar9 == 0xffffffed) {
          uVar9 = *(uint *)(param_1 + 0xe0);
        }
        if (param_1 != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x570),"USB_CDC_GET_ENCAPSULATED_RESPONSE");
        }
        if ((sVar6 != 0) || (uVar9 != uVar5)) goto LAB_0010863c;
        if (*(int *)(param_1 + 0xd8) == 0) {
          __src = (int *)rndis_get_next_response(*(undefined8 *)(param_1 + 0x100),&local_5c);
          if (__src == (int *)0x0) goto LAB_00108648;
          if (*__src == -0x7ffffffe) {
            if (param_1 == 0) {
              __src[8] = 0xf;
              __src[9] = __src[9] * 0xf;
            }
            else {
              ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: max_pkt_per_xfer : %d",
                             "handle_get_encapsulated_response",0xf);
              __src[8] = 0xf;
              __src[9] = __src[9] * 0xf;
              ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: pkt_alignment_factor : %d",
                             "handle_get_encapsulated_response",4);
            }
            __src[10] = 4;
          }
          memcpy((void *)*puVar15,__src,(ulong)local_5c);
          rndis_free_response(*(undefined8 *)(param_1 + 0x100),__src);
          uVar13 = local_5c;
          uVar9 = local_5c;
          if ((int)local_5c < 0) goto LAB_001087e8;
        }
        else {
          lVar1 = param_1 + 0x548;
          _raw_spin_lock(lVar1);
          plVar19 = *(long **)(param_1 + 0x530);
          if (plVar19 == (long *)(param_1 + 0x530)) {
            if (param_1 != 0) {
              ipc_log_string(*(undefined8 *)(param_1 + 0x570),"ctrl resp queue empty");
            }
            _raw_spin_unlock(lVar1);
            uVar13 = 0;
          }
          else {
            plVar17 = plVar19 + -2;
            uVar10 = __list_del_entry_valid(plVar19);
            if ((uVar10 & 1) != 0) {
              lVar3 = *plVar19;
              plVar4 = (long *)plVar19[1];
              *(long **)(lVar3 + 8) = plVar4;
              *plVar4 = lVar3;
            }
            *plVar19 = -0x2152ffffffffff00;
            plVar19[1] = -0x2152fffffffffede;
            *(int *)(param_1 + 0x568) = *(int *)(param_1 + 0x568) + 1;
            _raw_spin_unlock(lVar1);
            uVar13 = *(uint *)(plVar19 + -1);
            if (uVar14 <= *(uint *)(plVar19 + -1)) {
              uVar13 = uVar14;
            }
            memcpy((void *)*puVar15,(void *)plVar19[-2],(ulong)uVar13);
            if (plVar17 != (long *)0x0) {
              kfree(*plVar17);
              kfree(plVar17);
            }
            puVar15[6] = gsi_ctrl_send_response_complete;
            puVar15[7] = param_1;
            if (param_1 != 0) {
              ipc_log_string(*(undefined8 *)(param_1 + 0x570),"copied encap_resp %d bytes",
                             (ulong)uVar13);
            }
          }
        }
      }
    }
  }
  *(uint *)(puVar15 + 1) = uVar13;
  *(uint *)(puVar15 + 5) =
       *(uint *)(puVar15 + 5) & 0xfff80000 |
       *(uint *)(puVar15 + 5) & 0x3ffff | (uint)(uVar13 < uVar14) << 0x12;
  uVar9 = usb_ep_queue(*(undefined8 *)(*plVar20 + 0x40),puVar15,0xa20);
  if ((int)uVar9 < 0) {
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x570),"response on err %d",uVar9);
      _printk(&DAT_0010e023,uVar9);
    }
  }
  else {
    *(byte *)((long)plVar20 + 0x94) = *(byte *)((long)plVar20 + 0x94) | 1;
  }
LAB_001087e8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}



//------------------------------------------------------------
// gsi_disable @ 00108850 size=376
// signature: undefined gsi_disable(void)
// callers: [gsi_unbind]
//------------------------------------------------------------

void gsi_disable(undefined8 *param_1)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  *(undefined4 *)(param_1 + 0x21) = 0;
  iVar1 = *(int *)(param_1 + 0x1b);
  if (iVar1 == 0) {
    rndis_uninit(param_1[0x20]);
    iVar1 = *(int *)(param_1 + 0x1b);
  }
  if (iVar1 == 2) {
    *(undefined1 *)(param_1 + 0xaf) = 0;
    plVar2 = (long *)param_1[0x9d];
  }
  else {
    plVar2 = (long *)param_1[0x9d];
  }
  if ((plVar2 != (long *)0x0) && (*plVar2 != 0)) {
    usb_ep_disable();
    *(undefined8 *)param_1[0x9d] = 0;
  }
  gsi_ctrl_clear_cpkt_queues(param_1,0);
  gsi_ctrl_send_cpkt_tomodem(param_1,0,0);
  *(undefined1 *)(param_1 + 0x9f) = 0;
  if (*(char *)((long)param_1 + 0x10c) == '\0') {
    if (param_1 != (undefined8 *)0x0) {
      ipc_log_string(param_1[0xae],"%s: data intf is closed","gsi_disable");
    }
  }
  else {
    *(undefined1 *)((long)param_1 + 0x10c) = 0;
    *(undefined1 *)((long)param_1 + 0x5bc) = 0;
    if (param_1 != (undefined8 *)0x0) {
      ipc_log_string(param_1[0xae],"%s deactivated",*param_1);
    }
    *(undefined1 *)((long)param_1 + 0x241) = 0;
    uVar3 = _raw_spin_lock_irqsave(param_1 + 0x6d);
    uVar4 = (ulong)(*(byte *)((long)param_1 + 0x365) + 1) & 0x7f;
    *(char *)((long)param_1 + 0x365) = (char)uVar4;
    if ((uint)uVar4 == (uint)*(byte *)((long)param_1 + 0x364)) {
      if (param_1 != (undefined8 *)0x0) {
        ipc_log_string(param_1[0xae],"%s: event queue overflow error","post_event");
        _printk(&DAT_0010dbb8,"post_event");
      }
    }
    else {
      *(undefined1 *)((long)param_1 + uVar4 + 0x2e4) = 7;
    }
    _raw_spin_unlock_irqrestore(param_1 + 0x6d,uVar3);
    queue_delayed_work_on(0x20,param_1[0x5b],param_1 + 0x4a,0);
  }
  return;
}



//------------------------------------------------------------
// gsi_free_func @ 001089cc size=4
// signature: undefined gsi_free_func(void)
// callers: []
//------------------------------------------------------------

void gsi_free_func(void)

{
  return;
}



//------------------------------------------------------------
// gsi_suspend @ 001089d4 size=312
// signature: undefined gsi_suspend(void)
// callers: [gsi_func_suspend]
//------------------------------------------------------------

void gsi_suspend(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  undefined1 local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if (*(char *)(param_1 + 0x128) == '\0') {
    local_3c[0] = 1;
    usb_gsi_ep_op(*(undefined8 *)(param_1 + 0x140),local_3c,0xb);
    uVar2 = _raw_spin_lock_irqsave(param_1 + 0x368);
    uVar3 = (ulong)(*(byte *)(param_1 + 0x365) + 1) & 0x7f;
    *(char *)(param_1 + 0x365) = (char)uVar3;
    if ((uint)uVar3 == (uint)*(byte *)(param_1 + 0x364)) {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: event queue overflow error",
                       "post_event");
        _printk(&DAT_0010dbb8,"post_event");
      }
    }
    else {
      *(undefined1 *)(param_1 + uVar3 + 0x2e4) = 8;
    }
    _raw_spin_unlock_irqrestore(param_1 + 0x368,uVar2);
    queue_delayed_work_on(0x20,*(undefined8 *)(param_1 + 0x2d8),param_1 + 0x250,0);
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x570),"gsi suspended");
    }
  }
  else if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: func already suspended, return\n",
                   "gsi_suspend");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gsi_get_status @ 00108b10 size=8
// signature: undefined gsi_get_status(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_get_status(void)

{
  return 0;
}



//------------------------------------------------------------
// gsi_func_suspend @ 00108b1c size=160
// signature: undefined gsi_func_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_func_suspend(undefined8 *param_1,uint param_2)

{
  undefined *puVar1;
  byte bVar2;
  
  if (param_1 != (undefined8 *)0x0) {
    puVar1 = &DAT_0010cf0c;
    if ((undefined *)*param_1 != (undefined *)0x0) {
      puVar1 = (undefined *)*param_1;
    }
    ipc_log_string(param_1[0xae],"func susp %u cmd for %s",param_2 & 0xff,puVar1);
  }
  bVar2 = (byte)((param_2 & 0xff) >> 1) & 1;
  if ((param_2 & 1) == 0) {
    if (*(char *)(param_1 + 0x25) != '\0') {
      *(undefined1 *)(param_1 + 0x25) = 0;
      gsi_resume(param_1);
    }
    *(byte *)((long)param_1 + 0x129) = bVar2;
  }
  else {
    *(byte *)((long)param_1 + 0x129) = bVar2;
    if (*(char *)(param_1 + 0x25) == '\0') {
      gsi_suspend(param_1);
      *(undefined1 *)(param_1 + 0x25) = 1;
    }
  }
  return 0;
}



//------------------------------------------------------------
// gsi_resume @ 00108bc0 size=508
// signature: undefined gsi_resume(void)
// callers: [gsi_func_suspend]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gsi_resume(long param_1)

{
  char *pcVar1;
  bool bVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  long *plVar6;
  
  plVar6 = *(long **)(*(long *)(param_1 + 0x30) + 0x30);
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s for prot_id:%d","gsi_resume",
                   *(undefined4 *)(param_1 + 0xd8));
  }
  lVar3 = *plVar6;
  if ((*(uint *)(lVar3 + 0x58) < 5) || (*(char *)(param_1 + 0x128) == '\0')) {
    if ((*(long *)(param_1 + 0x4e8) != 0) && (*(long *)(*(long *)(param_1 + 0x4e8) + 0x38) == 0)) {
      config_ep_by_speed(lVar3,param_1);
    }
    gsi_ctrl_send_notification(param_1);
    if (*(int *)(param_1 + 0xd8) == 0) {
      if (*(uint *)(**(long **)(*(long *)(param_1 + 0x30) + 0x30) + 0x58) < 5) {
        bVar2 = true;
      }
      else {
        bVar2 = *(char *)(param_1 + 0x129) != '\0';
      }
      if (param_1 != 0) {
        pcVar1 = "true";
        if (!bVar2) {
          pcVar1 = "false";
        }
        ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: remote_wakeup_allowed:%s",
                       "usb_gsi_remote_wakeup_allowed",pcVar1);
      }
      if (((!bVar2) && (*(char *)(param_1 + 0x5bc) != '\0')) &&
         (lVar3 = *(long *)(param_1 + 0x100), lVar3 != 0)) {
        if (*(int *)(lVar3 + 8) != 2) {
          gsi_rndis_flow_ctrl_enable(0);
          lVar3 = *(long *)(param_1 + 0x100);
        }
        *(undefined4 *)(lVar3 + 8) = 2;
      }
    }
    uVar4 = _raw_spin_lock_irqsave(param_1 + 0x368);
    uVar5 = (ulong)(*(byte *)(param_1 + 0x365) + 1) & 0x7f;
    *(char *)(param_1 + 0x365) = (char)uVar5;
    if ((uint)uVar5 == (uint)*(byte *)(param_1 + 0x364)) {
      if (param_1 == 0) {
        _raw_spin_unlock_irqrestore(0x368,uVar4);
        queue_delayed_work_on(0x20,_DAT_000002d8,0x250,0);
        return;
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: event queue overflow error","post_event")
      ;
      _printk(&DAT_0010dbb8,"post_event");
    }
    else {
      *(undefined1 *)(param_1 + uVar5 + 0x2e4) = 10;
    }
    _raw_spin_unlock_irqrestore(param_1 + 0x368,uVar4);
    queue_delayed_work_on(0x20,*(undefined8 *)(param_1 + 0x2d8),param_1 + 0x250,0);
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: for prot_id:%d completed","gsi_resume",
                     *(undefined4 *)(param_1 + 0xd8));
    }
  }
  return;
}



//------------------------------------------------------------
// gsi_rndis_response_available @ 00108dc0 size=248
// signature: undefined gsi_rndis_response_available(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gsi_rndis_response_available(long param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined8 *puVar5;
  
  puVar2 = (undefined8 *)kmalloc_trace(_mutex_unlock,0xb20,0x20);
  if (puVar2 != (undefined8 *)0x0) {
    *(undefined4 *)(puVar2 + 1) = 0;
    *puVar2 = 0x10;
    if (puVar2 < (undefined8 *)0xfffffffffffff001) {
      *(undefined4 *)((long)puVar2 + 0xc) = 4;
      uVar3 = _raw_spin_lock_irqsave(param_1 + 0x548);
      puVar5 = *(undefined8 **)(param_1 + 0x538);
      puVar1 = puVar2 + 2;
      uVar4 = __list_add_valid(puVar1,puVar5,param_1 + 0x530);
      if ((uVar4 & 1) != 0) {
        *(undefined8 **)(param_1 + 0x538) = puVar1;
        puVar2[2] = param_1 + 0x530;
        puVar2[3] = puVar5;
        *puVar5 = puVar1;
      }
      _raw_spin_unlock_irqrestore(param_1 + 0x548,uVar3);
      gsi_ctrl_send_notification(param_1);
      return;
    }
  }
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: err allocating cpkt\n",
                   "gsi_rndis_response_available");
    _printk(&DAT_0010d246,"gsi_rndis_response_available");
  }
  return;
}



//------------------------------------------------------------
// ipa_usb_notify_cb @ 00108ebc size=768
// signature: undefined ipa_usb_notify_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ipa_usb_notify_cb(int param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  ulong uVar7;
  char *pcVar8;
  int iVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  
  if (param_2 == 0) {
    return 0xffffffea;
  }
  lVar1 = param_2 + 0x24c;
  uVar3 = _raw_spin_lock_irqsave(lVar1);
  if (param_1 == 2) {
    uVar4 = _raw_spin_lock_irqsave(param_2 + 0x368);
    uVar7 = (ulong)(*(byte *)(param_2 + 0x365) + 1) & 0x7f;
    *(char *)(param_2 + 0x365) = (char)uVar7;
    if ((uint)uVar7 == (uint)*(byte *)(param_2 + 0x364)) {
      ipc_log_string(*(undefined8 *)(param_2 + 0x570),"%s: event queue overflow error","post_event")
      ;
      _printk(&DAT_0010dbb8,"post_event");
    }
    else {
      *(undefined1 *)(param_2 + uVar7 + 0x2e4) = 9;
    }
    _raw_spin_unlock_irqrestore(param_2 + 0x368,uVar4);
  }
  else {
    if (param_1 == 1) {
      gsi_wakeup_host(param_2);
      goto LAB_00108fa8;
    }
    if (param_1 != 0) goto LAB_00108fa8;
    if (*(char *)(param_2 + 0x241) != '\0') {
      _raw_spin_unlock_irqrestore(lVar1,uVar3);
      ipc_log_string(*(undefined8 *)(param_2 + 0x570),"%s: Already triggered","ipa_usb_notify_cb");
      return 1;
    }
    ipc_log_string(*(undefined8 *)(param_2 + 0x570),"%s: Set net_ready_trigger","ipa_usb_notify_cb")
    ;
    _printk(&DAT_0010ceca,"ipa_usb_notify_cb");
    iVar9 = *(int *)(param_2 + 0xd8);
    *(undefined1 *)(param_2 + 0x241) = 1;
    if (iVar9 == 6) {
      _raw_spin_lock(param_2 + 0x548);
      *(undefined1 *)(param_2 + 0x120) = 2;
      gsi_ncm_do_notify(param_2);
      _raw_spin_unlock(param_2 + 0x548);
LAB_001090c0:
      iVar9 = *(int *)(param_2 + 0xd8);
    }
    else if (iVar9 == 1) {
      puVar5 = (undefined8 *)kmalloc_trace(_mutex_unlock,0xb20,0x20);
      if (puVar5 != (undefined8 *)0x0) {
        *(undefined4 *)(puVar5 + 1) = 0;
        *puVar5 = 0x10;
        uVar4 = _mutex_unlock;
        if (puVar5 < (undefined8 *)0xfffffffffffff001) {
          *(undefined4 *)((long)puVar5 + 0xc) = 1;
          puVar6 = (undefined8 *)kmalloc_trace(uVar4,0xb20,0x20);
          if (puVar6 != (undefined8 *)0x0) {
            *(undefined4 *)(puVar6 + 1) = 0;
            *puVar6 = 0x10;
            if (puVar6 < (undefined8 *)0xfffffffffffff001) {
              *(undefined4 *)((long)puVar6 + 0xc) = 2;
              _raw_spin_lock(param_2 + 0x548);
              puVar11 = *(undefined8 **)(param_2 + 0x538);
              puVar10 = puVar5 + 2;
              lVar2 = param_2 + 0x530;
              uVar7 = __list_add_valid(puVar10,puVar11,lVar2);
              if ((uVar7 & 1) != 0) {
                *(undefined8 **)(param_2 + 0x538) = puVar10;
                puVar5[2] = lVar2;
                puVar5[3] = puVar11;
                *puVar11 = puVar10;
              }
              puVar10 = *(undefined8 **)(param_2 + 0x538);
              puVar5 = puVar6 + 2;
              uVar7 = __list_add_valid(puVar5,puVar10,lVar2);
              if ((uVar7 & 1) != 0) {
                *(undefined8 **)(param_2 + 0x538) = puVar5;
                puVar6[2] = lVar2;
                puVar6[3] = puVar10;
                *puVar10 = puVar5;
              }
              _raw_spin_unlock(param_2 + 0x548);
              gsi_ctrl_send_notification(param_2);
              goto LAB_001090c0;
            }
          }
          _raw_spin_unlock_irqrestore(lVar1,uVar3);
          gsi_ctrl_pkt_free(puVar5);
          uVar3 = *(undefined8 *)(param_2 + 0x570);
          pcVar8 = "%s: err cpkt_notify_speed\n";
          goto LAB_0010912c;
        }
      }
      _raw_spin_unlock_irqrestore(lVar1,uVar3);
      uVar3 = *(undefined8 *)(param_2 + 0x570);
      pcVar8 = "%s: err cpkt_notify_connect\n";
LAB_0010912c:
      ipc_log_string(uVar3,pcVar8,"ipa_usb_notify_cb");
      return 0xfffffff4;
    }
    if (iVar9 == 0) goto LAB_00108fa8;
    post_event(param_2 + 0x140,4);
  }
  queue_delayed_work_on(0x20,*(undefined8 *)(param_2 + 0x2d8),param_2 + 0x250,0);
LAB_00108fa8:
  _raw_spin_unlock_irqrestore(lVar1,uVar3);
  return 1;
}



//------------------------------------------------------------
// gsi_ctrl_notify_resp_complete @ 001091c0 size=216
// signature: undefined gsi_ctrl_notify_resp_complete(void)
// callers: []
//------------------------------------------------------------

void gsi_ctrl_notify_resp_complete(undefined8 param_1,long *param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = param_2[7];
  lVar4 = *param_2;
  iVar1 = *(int *)((long)param_2 + 0x54);
  uVar2 = _raw_spin_lock_irqsave(lVar3 + 0x548);
  *(undefined1 *)(lVar3 + 0x4f8) = 0;
  _raw_spin_unlock_irqrestore(lVar3 + 0x548,uVar2);
  if (iVar1 != -0x6c) {
    if (iVar1 == 0) {
      return;
    }
    if (iVar1 != -0x68) {
      if (lVar3 == 0) {
        return;
      }
      ipc_log_string(*(undefined8 *)(lVar3 + 0x570),"Unknown event %02x --> %d",
                     *(undefined1 *)(lVar4 + 1),*(undefined4 *)((long)param_2 + 0x54));
      _printk(&DAT_0010e745,*(undefined1 *)(lVar4 + 1),*(undefined4 *)((long)param_2 + 0x54));
      return;
    }
  }
  if (lVar3 != 0) {
    ipc_log_string(*(undefined8 *)(lVar3 + 0x570),"ESHUTDOWN/ECONNRESET, connection gone");
  }
  gsi_ctrl_clear_cpkt_queues(lVar3,0);
  gsi_ctrl_send_cpkt_tomodem(lVar3,0,0);
  return;
}



//------------------------------------------------------------
// gsi_ncm_notify_complete @ 0010929c size=248
// signature: undefined gsi_ncm_notify_complete(void)
// callers: []
//------------------------------------------------------------

void gsi_ncm_notify_complete(undefined8 param_1,long *param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  
  lVar5 = param_2[7];
  lVar6 = *param_2;
  plVar7 = *(long **)(*(long *)(lVar5 + 0x30) + 0x30);
  _raw_spin_lock(lVar5 + 0x548);
  iVar2 = *(int *)((long)param_2 + 0x54);
  if ((iVar2 == -0x6c) || (iVar2 == -0x68)) {
    *(undefined4 *)(lVar5 + 0x124) = 0;
    *(undefined1 *)(lVar5 + 0x120) = 0;
  }
  else if (iVar2 == 0) {
    _dev_err(*plVar7 + 0x78,"Notification %02x sent\n",*(undefined1 *)(lVar6 + 1));
    piVar1 = (int *)(lVar5 + 0x124);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = *piVar1 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
  }
  else {
    _dev_err(*plVar7 + 0x78,"event %02x --> %d\n",*(undefined1 *)(lVar6 + 1));
    piVar1 = (int *)(lVar5 + 0x124);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = *piVar1 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
  }
  gsi_ncm_do_notify(lVar5);
  _raw_spin_unlock(lVar5 + 0x548);
  return;
}



//------------------------------------------------------------
// gsi_ctrl_send_cpkt_tomodem @ 001093ac size=412
// signature: undefined gsi_ctrl_send_cpkt_tomodem(void)
// callers: [gsi_ctrl_cmd_complete, gsi_ctrl_reset_cmd_complete, gsi_disable, gsi_set_alt, gsi_ctrl_notify_resp_complete, gsi_setup]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gsi_ctrl_send_cpkt_tomodem(long param_1,void *param_2,ulong param_3)

{
  long lVar1;
  long *plVar2;
  undefined8 uVar3;
  long *plVar4;
  long lVar5;
  ulong uVar6;
  long *plVar7;
  
  lVar1 = param_1 + 0x548;
  uVar3 = _raw_spin_lock_irqsave(lVar1);
  if (*(char *)(param_1 + 0x500) == '\0') {
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: ctrl device %s is not open",
                     "gsi_ctrl_send_cpkt_tomodem",param_1 + 0x450);
    }
    *(int *)(param_1 + 0x564) = *(int *)(param_1 + 0x564) + 1;
  }
  else {
    plVar4 = (long *)kmalloc_trace(_mutex_unlock,0xb20,0x20);
    if (plVar4 != (long *)0x0) {
      lVar5 = __kmalloc(param_3 & 0xffffffff,0xa20);
      *plVar4 = lVar5;
      if (lVar5 == 0) {
        kfree(plVar4);
      }
      else {
        *(int *)(plVar4 + 1) = (int)param_3;
        if (plVar4 < (long *)0xfffffffffffff001) {
          memcpy((void *)*plVar4,param_2,param_3);
          plVar7 = *(long **)(param_1 + 0x528);
          plVar2 = plVar4 + 2;
          *(int *)(plVar4 + 1) = (int)param_3;
          uVar6 = __list_add_valid(plVar2,plVar7,param_1 + 0x520);
          if ((uVar6 & 1) != 0) {
            *(long **)(param_1 + 0x528) = plVar2;
            plVar4[2] = param_1 + 0x520;
            plVar4[3] = (long)plVar7;
            *plVar7 = (long)plVar2;
          }
          *(int *)(param_1 + 0x554) = *(int *)(param_1 + 0x554) + 1;
          _raw_spin_unlock_irqrestore(lVar1,uVar3);
          if (param_1 != 0) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: Wake up read queue",
                           "gsi_ctrl_send_cpkt_tomodem");
          }
          __wake_up(param_1 + 0x508,3,1,0);
          return;
        }
      }
    }
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: Reset func pkt allocation failed",
                     "gsi_ctrl_send_cpkt_tomodem");
      _printk(&DAT_0010d3c9,"gsi_ctrl_send_cpkt_tomodem");
    }
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar3);
  return;
}



//------------------------------------------------------------
// gsi_ncm_do_notify @ 00109548 size=616
// signature: undefined gsi_ncm_do_notify(void)
// callers: [gsi_ncm_notify_complete, ipa_usb_notify_cb]
//------------------------------------------------------------

void gsi_ncm_do_notify(long param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  undefined1 uVar6;
  long lVar7;
  uint uVar8;
  undefined4 uVar9;
  long lVar10;
  long *plVar11;
  undefined1 *puVar12;
  long *plVar13;
  
  plVar11 = *(long **)(param_1 + 0x118);
  plVar13 = *(long **)(*(long *)(param_1 + 0x30) + 0x30);
  if (*(int *)(param_1 + 0x124) != 0) {
    return;
  }
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: notify state: %d","gsi_ncm_do_notify",
                   *(undefined1 *)(param_1 + 0x120));
  }
  cVar2 = *(char *)(param_1 + 0x120);
  if (cVar2 == '\0') {
    return;
  }
  piVar1 = (int *)(param_1 + 0x124);
  puVar12 = (undefined1 *)*plVar11;
  if (cVar2 == '\x02') {
    *(undefined2 *)(puVar12 + 2) = 0;
    puVar12[1] = 0x2a;
    *(undefined2 *)(puVar12 + 6) = 8;
    *(undefined4 *)(plVar11 + 1) = 0x10;
    lVar7 = *plVar11;
    lVar10 = *plVar13;
    uVar9 = 0;
    if (lVar10 != 0) {
      if (*(uint *)(lVar10 + 0x5c) < 5) {
        if (2 < *(uint *)(lVar10 + 0x5c)) {
          uVar8 = *(uint *)(lVar10 + 0x58);
LAB_00109644:
          if (uVar8 == 3) {
            uVar9 = 0x19640000;
            goto LAB_0010965c;
          }
        }
        uVar9 = 0x947000;
      }
      else {
        uVar8 = *(uint *)(lVar10 + 0x58);
        if (uVar8 < 6) {
          if (uVar8 != 5) goto LAB_00109644;
          uVar9 = 3750000000;
        }
        else {
          uVar9 = 4250000000;
        }
      }
    }
LAB_0010965c:
    *(undefined4 *)(lVar7 + 8) = uVar9;
    *(undefined4 *)(lVar7 + 0xc) = uVar9;
    if (param_1 != 0) {
      lVar7 = *plVar13;
      if (lVar7 == 0) {
        uVar5 = 0;
      }
      else if (*(uint *)(lVar7 + 0x5c) < 5) {
        if (2 < *(uint *)(lVar7 + 0x5c)) {
          uVar8 = *(uint *)(lVar7 + 0x58);
LAB_001096bc:
          if (uVar8 == 3) {
            uVar5 = 0x19640000;
            goto LAB_001096d4;
          }
        }
        uVar5 = 0x947000;
      }
      else {
        uVar8 = *(uint *)(lVar7 + 0x58);
        if (uVar8 < 6) {
          if (uVar8 != 5) goto LAB_001096bc;
          uVar5 = 3750000000;
        }
        else {
          uVar5 = 4250000000;
        }
      }
LAB_001096d4:
      ipc_log_string(*(undefined8 *)(param_1 + 0x570),"notify speed %u\n",uVar5);
    }
    uVar6 = 1;
  }
  else {
    if (cVar2 != '\x01') goto LAB_001096e8;
    uVar6 = 0;
    puVar12[1] = 0;
    *(undefined2 *)(puVar12 + 6) = 0;
    *(undefined2 *)(puVar12 + 2) = 1;
    *(undefined4 *)(plVar11 + 1) = 8;
  }
  *(undefined1 *)(param_1 + 0x120) = uVar6;
LAB_001096e8:
  *puVar12 = 0xa1;
  *(short *)(puVar12 + 4) = (short)*(undefined4 *)(param_1 + 0xdc);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar3) {
      *piVar1 = *piVar1 + 1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  _raw_spin_unlock(param_1 + 0x548);
  iVar4 = usb_ep_queue(*(undefined8 *)(param_1 + 0x4e8),plVar11,0xa20);
  _raw_spin_lock(param_1 + 0x548);
  if (iVar4 < 0) {
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = *piVar1 + -1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x570),"%s: notify --> %d\n","gsi_ncm_do_notify",
                     iVar4);
      _printk(&DAT_0010e776,"gsi_ncm_do_notify",iVar4);
    }
  }
  return;
}



//------------------------------------------------------------
// post_event @ 001097c4 size=168
// signature: undefined post_event(void)
// callers: [ipa_usb_notify_cb]
//------------------------------------------------------------

void post_event(long param_1,undefined1 param_2)

{
  undefined8 uVar1;
  ulong uVar2;
  
  uVar1 = _raw_spin_lock_irqsave(param_1 + 0x228);
  uVar2 = (ulong)(*(byte *)(param_1 + 0x225) + 1) & 0x7f;
  *(char *)(param_1 + 0x225) = (char)uVar2;
  if ((uint)uVar2 == (uint)*(byte *)(param_1 + 0x224)) {
    if (param_1 != 0x140) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x430),"%s: event queue overflow error","post_event")
      ;
      _printk(&DAT_0010dbb8,"post_event");
    }
  }
  else {
    *(undefined1 *)(param_1 + uVar2 + 0x1a4) = param_2;
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x228,uVar1);
  return;
}



//------------------------------------------------------------
// gsi_ctrl_reset_cmd_complete @ 00109870 size=40
// signature: undefined gsi_ctrl_reset_cmd_complete(void)
// callers: []
//------------------------------------------------------------

void gsi_ctrl_reset_cmd_complete(undefined8 param_1,undefined8 *param_2)

{
  gsi_ctrl_send_cpkt_tomodem(param_2[7],*param_2,0);
  return;
}



//------------------------------------------------------------
// gsi_rndis_command_complete @ 0010989c size=384
// signature: undefined gsi_rndis_command_complete(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gsi_rndis_command_complete(undefined8 param_1,long *param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  if ((int *)*param_2 == (int *)0x0) {
    return;
  }
  lVar4 = param_2[7];
  lVar3 = *(long *)(lVar4 + 0x100);
  if (lVar3 == 0) {
    return;
  }
  iVar1 = *(int *)*param_2;
  if (iVar1 == 3) {
    if (lVar4 != 0) {
      ipc_log_string(*(undefined8 *)(lVar4 + 0x570),"RNDIS_MSG_HALT, state:%d\n",
                     *(undefined4 *)(lVar3 + 8));
      lVar3 = *(long *)(lVar4 + 0x100);
    }
    if (*(int *)(lVar3 + 8) == 2) {
      gsi_rndis_flow_ctrl_enable(1,lVar3);
      lVar3 = *(long *)(lVar4 + 0x100);
    }
    *(undefined4 *)(lVar3 + 8) = 0;
    return;
  }
  lVar5 = *(long *)(*(long *)(lVar4 + 0x30) + 0x30);
  iVar2 = rndis_msg_parser(lVar3);
  if ((iVar2 < 0) && (lVar4 != 0)) {
    ipc_log_string(*(undefined8 *)(lVar4 + 0x570),"RNDIS command error %d, %d/%d",iVar2,
                   (int)param_2[0xb],(int)param_2[1]);
    _printk(&DAT_0010c8cf,iVar2,(int)param_2[0xb],(int)param_2[1]);
  }
  if (iVar1 == 5) {
    if (*(int *)(*param_2 + 0xc) == 0x1010e) {
      gsi_rndis_flow_ctrl_enable(**(short **)(*(long *)(lVar4 + 0x100) + 0x20) == 0);
    }
  }
  else if (iVar1 == 2) {
    lVar3 = *param_2;
    if (lVar4 == 0) {
      _DAT_00000238 = *(undefined4 *)(lVar3 + 0x14);
    }
    else {
      ipc_log_string(*(undefined8 *)(lVar4 + 0x570),"RNDIS host major:%d minor:%d version\n",
                     *(undefined4 *)(lVar3 + 0xc),*(undefined4 *)(lVar3 + 0x10));
      *(undefined4 *)(lVar4 + 0x238) = *(undefined4 *)(lVar3 + 0x14);
      ipc_log_string(*(undefined8 *)(lVar4 + 0x570),"RNDIS host DL MaxTransferSize:%d\n",
                     *(undefined4 *)(lVar3 + 0x14));
    }
  }
  *(byte *)(lVar5 + 0x94) = *(byte *)(lVar5 + 0x94) & 0xfe;
  return;
}



//------------------------------------------------------------
// gsi_ctrl_cmd_complete @ 00109a20 size=72
// signature: undefined gsi_ctrl_cmd_complete(void)
// callers: []
//------------------------------------------------------------

void gsi_ctrl_cmd_complete(undefined8 param_1,undefined8 *param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_2[7] + 0x30) + 0x30);
  gsi_ctrl_send_cpkt_tomodem(param_2[7],*param_2,*(undefined4 *)(param_2 + 0xb));
  *(byte *)(lVar1 + 0x94) = *(byte *)(lVar1 + 0x94) & 0xfe;
  return;
}



//------------------------------------------------------------
// gsi_rndis_flow_ctrl_enable @ 00109a68 size=388
// signature: undefined gsi_rndis_flow_ctrl_enable(void)
// callers: [gsi_resume, gsi_rndis_command_complete]
//------------------------------------------------------------

void gsi_rndis_flow_ctrl_enable(uint param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_2 + 0x48);
  if (lVar4 == 0) {
    _printk(&DAT_0010d749,"gsi_rndis_flow_ctrl_enable",0);
  }
  else {
    lVar1 = lVar4 + 0x368;
    if ((param_1 & 1) == 0) {
      ipc_log_string(*(undefined8 *)(lVar4 + 0x570),"%s: posting HOST_READY\n",
                     "gsi_rndis_flow_ctrl_enable");
      uVar2 = _raw_spin_lock_irqsave(lVar1);
      uVar3 = (ulong)(*(byte *)(lVar4 + 0x365) + 1) & 0x7f;
      *(char *)(lVar4 + 0x365) = (char)uVar3;
      if ((uint)uVar3 == (uint)*(byte *)(lVar4 + 0x364)) {
        ipc_log_string(*(undefined8 *)(lVar4 + 0x570),"%s: event queue overflow error","post_event")
        ;
        _printk(&DAT_0010dbb8,"post_event");
      }
      else {
        *(undefined1 *)(lVar4 + uVar3 + 0x2e4) = 6;
      }
      _raw_spin_unlock_irqrestore(lVar1,uVar2);
      *(undefined1 *)(lVar4 + 0x5bc) = 1;
    }
    else {
      ipc_log_string(*(undefined8 *)(lVar4 + 0x570),"%s: posting HOST_NRDY\n",
                     "gsi_rndis_flow_ctrl_enable");
      uVar2 = _raw_spin_lock_irqsave(lVar1);
      uVar3 = (ulong)(*(byte *)(lVar4 + 0x365) + 1) & 0x7f;
      *(char *)(lVar4 + 0x365) = (char)uVar3;
      if ((uint)uVar3 == (uint)*(byte *)(lVar4 + 0x364)) {
        ipc_log_string(*(undefined8 *)(lVar4 + 0x570),"%s: event queue overflow error","post_event")
        ;
        _printk(&DAT_0010dbb8,"post_event");
      }
      else {
        *(undefined1 *)(lVar4 + uVar3 + 0x2e4) = 5;
      }
      _raw_spin_unlock_irqrestore(lVar1,uVar2);
    }
    queue_delayed_work_on(0x20,*(undefined8 *)(lVar4 + 0x2d8),lVar4 + 0x250,0);
  }
  return;
}



//------------------------------------------------------------
// gsi_ctrl_send_response_complete @ 00109bf0 size=32
// signature: undefined gsi_ctrl_send_response_complete(void)
// callers: []
//------------------------------------------------------------

void gsi_ctrl_send_response_complete(undefined8 param_1,long param_2)

{
  gsi_ctrl_send_notification(*(undefined8 *)(param_2 + 0x38));
  return;
}



//------------------------------------------------------------
// gsi_ctrl_set_ntb_cmd_complete @ 00109c14 size=316
// signature: undefined gsi_ctrl_set_ntb_cmd_complete(void)
// callers: []
//------------------------------------------------------------

void gsi_ctrl_set_ntb_cmd_complete(undefined8 param_1,undefined8 *param_2)

{
  long lVar1;
  int iVar2;
  
  lVar1 = param_2[7];
  if (lVar1 != 0) {
    ipc_log_string(*(undefined8 *)(lVar1 + 0x570),"dev:%pK",lVar1);
  }
  param_2[7] = 0;
  if ((*(int *)((long)param_2 + 0x54) == 0) &&
     (iVar2 = *(int *)(param_2 + 0xb), iVar2 == *(int *)(param_2 + 1))) {
    if (iVar2 == 8) {
      iVar2 = *(int *)*param_2;
      if (0xffffc7fe < iVar2 - 0x4001U) {
        *(short *)(lVar1 + 0x248) = (short)((int *)*param_2)[1];
LAB_00109cdc:
        if (lVar1 != 0) {
          ipc_log_string(*(undefined8 *)(lVar1 + 0x570),"Set NTB INPUT SIZE %d",iVar2);
        }
        *(int *)(lVar1 + 0x244) = iVar2;
        return;
      }
    }
    else if (iVar2 == 4) {
      iVar2 = *(int *)*param_2;
      if (0xffffc7fe < iVar2 - 0x4001U) goto LAB_00109cdc;
    }
    else {
      iVar2 = 0;
    }
    if (lVar1 == 0) goto LAB_00109c9c;
  }
  else {
    if (lVar1 == 0) goto LAB_00109c9c;
    ipc_log_string(*(undefined8 *)(lVar1 + 0x570),"Bad control-OUT transfer");
    _printk(&DAT_0010e659);
    iVar2 = 0;
  }
  ipc_log_string(*(undefined8 *)(lVar1 + 0x570),"Illegal NTB INPUT SIZE %d from host",iVar2);
  _printk(&DAT_0010e991,iVar2);
LAB_00109c9c:
  usb_ep_set_halt(param_1);
  return;
}



//------------------------------------------------------------
// rndis_signal_connect @ 00109e80 size=40
// signature: undefined rndis_signal_connect(void)
// callers: [gsi_set_alt]
//------------------------------------------------------------

void rndis_signal_connect(long param_1)

{
  *(undefined4 *)(param_1 + 0x14) = 0;
  rndis_indicate_status_msg(param_1,0x4001000b);
  return;
}



//------------------------------------------------------------
// rndis_indicate_status_msg @ 00109ea8 size=240
// signature: undefined rndis_indicate_status_msg(void)
// callers: [rndis_signal_connect, rndis_signal_disconnect]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 rndis_indicate_status_msg(long param_1,undefined4 param_2)

{
  code *pcVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  
  if (*(int *)(param_1 + 8) == 0) {
    uVar4 = 0xfffffdf4;
  }
  else {
    plVar2 = (long *)kmalloc_trace(_mutex_unlock,0xa20,0x34);
    if (plVar2 == (long *)0x0) {
      uVar4 = 0xfffffff4;
    }
    else {
      plVar2[2] = (long)(plVar2 + 4);
      plVar2[3] = 0x14;
      _raw_spin_lock(param_1 + 0x60);
      puVar5 = *(undefined8 **)(param_1 + 0x58);
      uVar3 = __list_add_valid(plVar2,puVar5,param_1 + 0x50);
      if ((uVar3 & 1) != 0) {
        *(long **)(param_1 + 0x58) = plVar2;
        *plVar2 = param_1 + 0x50;
        plVar2[1] = (long)puVar5;
        *puVar5 = plVar2;
      }
      _raw_spin_unlock(param_1 + 0x60);
      puVar5 = (undefined8 *)plVar2[2];
      *(undefined4 *)(puVar5 + 1) = param_2;
      *puVar5 = 0x1400000007;
      *(undefined8 *)((long)puVar5 + 0xc) = 0;
      if (*(int *)(*(code **)(param_1 + 0x40) + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x109f68);
        (*pcVar1)();
      }
      (**(code **)(param_1 + 0x40))(*(undefined8 *)(param_1 + 0x48));
      uVar4 = 0;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// rndis_signal_disconnect @ 00109f9c size=44
// signature: undefined rndis_signal_disconnect(void)
// callers: []
//------------------------------------------------------------

void rndis_signal_disconnect(long param_1)

{
  *(undefined4 *)(param_1 + 0x14) = 1;
  rndis_indicate_status_msg(param_1,0x4001000c);
  return;
}



//------------------------------------------------------------
// rndis_uninit @ 00109fcc size=248
// signature: undefined rndis_uninit(void)
// callers: [gsi_disable]
//------------------------------------------------------------

void rndis_uninit(long param_1)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  ulong uVar6;
  long *plVar7;
  long lVar8;
  
  if (param_1 != 0) {
    lVar1 = param_1 + 0x60;
    plVar2 = (long *)(param_1 + 0x50);
    *(undefined4 *)(param_1 + 8) = 0;
    while( true ) {
      _raw_spin_lock(lVar1);
      plVar7 = plVar2;
      do {
        plVar7 = (long *)*plVar7;
        if (plVar7 == plVar2) {
          _raw_spin_unlock(lVar1);
          return;
        }
      } while (*(int *)((long)plVar7 + 0x1c) != 0);
      *(undefined4 *)((long)plVar7 + 0x1c) = 1;
      _raw_spin_unlock(lVar1);
      lVar8 = plVar7[2];
      if (lVar8 == 0) break;
      _raw_spin_lock(lVar1);
      plVar7 = (long *)*plVar2;
      while (plVar5 = plVar7, plVar5 != plVar2) {
        plVar7 = (long *)*plVar5;
        if (plVar5[2] == lVar8) {
          uVar6 = __list_del_entry_valid(plVar5);
          if ((uVar6 & 1) != 0) {
            lVar3 = *plVar5;
            plVar4 = (long *)plVar5[1];
            *(long **)(lVar3 + 8) = plVar4;
            *plVar4 = lVar3;
          }
          *plVar5 = -0x2152ffffffffff00;
          plVar5[1] = -0x2152fffffffffede;
          kfree(plVar5);
        }
      }
      _raw_spin_unlock(lVar1);
    }
  }
  return;
}



//------------------------------------------------------------
// rndis_get_next_response @ 0010a0c8 size=136
// signature: undefined rndis_get_next_response(void)
// callers: [gsi_setup]
//------------------------------------------------------------

undefined8 rndis_get_next_response(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  long *plVar3;
  
  if (param_2 == (undefined4 *)0x0) {
LAB_0010a138:
    uVar2 = 0;
  }
  else {
    lVar1 = param_1 + 0x60;
    _raw_spin_lock(lVar1);
    plVar3 = (long *)(param_1 + 0x50);
    do {
      plVar3 = (long *)*plVar3;
      if (plVar3 == (long *)(param_1 + 0x50)) {
        _raw_spin_unlock(lVar1);
        goto LAB_0010a138;
      }
    } while (*(int *)((long)plVar3 + 0x1c) != 0);
    *(undefined4 *)((long)plVar3 + 0x1c) = 1;
    *param_2 = *(undefined4 *)(plVar3 + 3);
    _raw_spin_unlock(lVar1);
    uVar2 = plVar3[2];
  }
  return uVar2;
}



//------------------------------------------------------------
// rndis_free_response @ 0010a154 size=172
// signature: undefined rndis_free_response(void)
// callers: [gsi_setup]
//------------------------------------------------------------

void rndis_free_response(long param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  
  _raw_spin_lock(param_1 + 0x60);
  plVar5 = *(long **)(param_1 + 0x50);
  while (plVar3 = plVar5, plVar3 != (long *)(param_1 + 0x50)) {
    plVar5 = (long *)*plVar3;
    if (plVar3[2] == param_2) {
      uVar4 = __list_del_entry_valid(plVar3);
      if ((uVar4 & 1) != 0) {
        lVar1 = *plVar3;
        plVar2 = (long *)plVar3[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar3 = -0x2152ffffffffff00;
      plVar3[1] = -0x2152fffffffffede;
      kfree(plVar3);
    }
  }
  _raw_spin_unlock(param_1 + 0x60);
  return;
}



//------------------------------------------------------------
// rndis_set_host_mac @ 0010a204 size=8
// signature: undefined rndis_set_host_mac(void)
// callers: [gsi_bind]
//------------------------------------------------------------

void rndis_set_host_mac(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x18) = param_2;
  return;
}



//------------------------------------------------------------
// rndis_msg_parser @ 0010a210 size=2264
// signature: undefined rndis_msg_parser(void)
// callers: [gsi_rndis_command_complete]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rndis_msg_parser(long param_1,undefined4 *param_2)

{
  uint *__dest;
  ulong *puVar1;
  undefined4 uVar2;
  long lVar3;
  long *plVar4;
  uint uVar5;
  char cVar6;
  bool bVar7;
  long *plVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  code *pcVar13;
  int *piVar14;
  long *plVar15;
  ulong uVar16;
  undefined8 uVar17;
  size_t sVar18;
  int iVar19;
  uint uVar20;
  long lVar21;
  undefined4 *puVar22;
  int iVar23;
  undefined4 *puVar24;
  int iVar25;
  long *plVar26;
  undefined8 *puVar27;
  undefined8 *puVar28;
  long lVar29;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
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
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar21 = sp_el0;
  local_68 = *(long *)(lVar21 + 0x638);
  if (param_2 == (undefined4 *)0x0) goto LAB_0010a774;
  if (param_1 == 0) goto LAB_0010a7fc;
  uVar2 = param_2[1];
  switch(*param_2) {
  case 2:
    *(undefined4 *)(param_1 + 8) = 1;
    if (*(long *)(param_1 + 0x28) != 0) {
      plVar15 = (long *)kmalloc_trace(_delayed_work_timer_fn,0xa20,0x54,uVar2);
      if (plVar15 == (long *)0x0) goto LAB_0010a774;
      plVar15[2] = (long)(plVar15 + 4);
      plVar15[3] = 0x34;
      _raw_spin_lock(param_1 + 0x60);
      puVar27 = *(undefined8 **)(param_1 + 0x58);
      uVar16 = __list_add_valid(plVar15,puVar27,param_1 + 0x50);
      if ((uVar16 & 1) != 0) {
        *(long **)(param_1 + 0x58) = plVar15;
        *plVar15 = param_1 + 0x50;
        plVar15[1] = (long)puVar27;
        *puVar27 = plVar15;
      }
      _raw_spin_unlock(param_1 + 0x60);
      puVar27 = (undefined8 *)plVar15[2];
      *puVar27 = 0x3480000002;
      uVar2 = param_2[2];
      *(undefined8 *)((long)puVar27 + 0xc) = 0x100000000;
      *(undefined8 *)((long)puVar27 + 0x14) = 0x100000000;
      *(undefined8 *)((long)puVar27 + 0x1c) = 0x100000000;
      *(undefined4 *)(puVar27 + 1) = uVar2;
      iVar19 = *(int *)(*(long *)(param_1 + 0x28) + 0xe0);
      puVar27[5] = 0;
      *(undefined4 *)(puVar27 + 6) = 0;
      *(int *)((long)puVar27 + 0x24) = iVar19 + 0x50;
      break;
    }
    goto LAB_0010a7fc;
  case 3:
    *(undefined4 *)(param_1 + 8) = 0;
    uVar17 = 0;
    if (*(long *)(param_1 + 0x28) == 0) goto LAB_0010aa90;
    netif_carrier_off();
    lVar21 = *(long *)(*(long *)(param_1 + 0x28) + 0x3c0);
    *(undefined8 *)(lVar21 + 200) = _jiffies;
    DataMemoryBarrier(2,3);
    puVar1 = (ulong *)(lVar21 + 0xd0);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar6 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar7) {
        *puVar1 = *puVar1 | 1;
        cVar6 = ExclusiveMonitorsStatus();
      }
    } while (cVar6 != '\0');
    goto LAB_0010aa8c;
  case 4:
    if (*(long *)(param_1 + 0x28) == 0) goto LAB_0010a7fc;
    plVar15 = (long *)kmalloc_trace(_config_group_init_type_name,0xa20,0xa8,uVar2);
    if (plVar15 == (long *)0x0) goto LAB_0010a774;
    plVar15[2] = (long)(plVar15 + 4);
    plVar15[3] = 0x88;
    _raw_spin_lock(param_1 + 0x60);
    puVar27 = *(undefined8 **)(param_1 + 0x58);
    uVar16 = __list_add_valid(plVar15,puVar27,param_1 + 0x50);
    if ((uVar16 & 1) != 0) {
      *(long **)(param_1 + 0x58) = plVar15;
      *plVar15 = param_1 + 0x50;
      plVar15[1] = (long)puVar27;
      *puVar27 = plVar15;
    }
    _raw_spin_unlock(param_1 + 0x60);
    puVar24 = (undefined4 *)plVar15[2];
    *puVar24 = 0x80000004;
    local_130 = 0;
    puVar24[2] = param_2[2];
    lVar21 = plVar15[2];
    local_78 = 0;
    uStack_70 = 0;
    iVar19 = param_2[3];
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
    local_d8 = 0;
    uStack_d0 = 0;
    local_e8 = 0;
    uStack_e0 = 0;
    local_f8 = 0;
    uStack_f0 = 0;
    local_108 = 0;
    uStack_100 = 0;
    local_118 = 0;
    uStack_110 = 0;
    local_128 = 0;
    uStack_120 = 0;
    if (lVar21 == 0) {
LAB_0010aa50:
      puVar22 = puVar24 + 5;
      puVar24[1] = 0x18;
      *(undefined8 *)(puVar24 + 3) = 0xc00000bb;
      goto LAB_0010aa68;
    }
    __dest = (uint *)(lVar21 + 0x18);
    *(undefined4 *)(lVar21 + 0x14) = 0x10;
    piVar14 = (int *)dev_get_stats(*(undefined8 *)(param_1 + 0x28),&local_130);
    uVar10 = _DAT_0010b45c;
    uVar9 = _DAT_0010b454;
    uVar17 = _DAT_0010b44c;
    if (0x20100 < iVar19) {
      if (iVar19 < 0x1010101) {
        switch(iVar19) {
        case 0x20101:
          if (piVar14 != (int *)0x0) {
            iVar19 = piVar14[10];
            iVar23 = piVar14[0xe];
            iVar25 = piVar14[2];
LAB_0010a8fc:
            uVar20 = iVar25 - (iVar19 + iVar23);
            goto LAB_0010aa08;
          }
          break;
        case 0x20102:
          if (piVar14 != (int *)0x0) {
            iVar19 = piVar14[8];
            iVar23 = piVar14[0xc];
            iVar25 = *piVar14;
            goto LAB_0010a8fc;
          }
          break;
        case 0x20103:
          if (piVar14 != (int *)0x0) {
            uVar20 = (uint)*(undefined8 *)(piVar14 + 10);
LAB_0010a910:
            iVar19 = 4;
            *__dest = uVar20;
            goto LAB_0010aa10;
          }
          break;
        case 0x20104:
          if (piVar14 != (int *)0x0) {
            uVar20 = (uint)*(undefined8 *)(piVar14 + 8);
            goto LAB_0010a910;
          }
          break;
        case 0x20105:
          if (piVar14 != (int *)0x0) {
            uVar20 = (uint)*(undefined8 *)(piVar14 + 0xc);
            goto LAB_0010a910;
          }
          break;
        default:
          goto switchD_0010a448_caseD_10105;
        }
        goto LAB_0010aa40;
      }
      if (0x1020100 < iVar19) {
        if (iVar19 == 0x1020101) {
          if (piVar14 != (int *)0x0) {
            uVar20 = (uint)*(undefined8 *)(piVar14 + 0x1a);
            goto LAB_0010a910;
          }
          goto LAB_0010aa40;
        }
        if (iVar19 != 0x1020102) {
          iVar23 = 0x1020103;
          goto LAB_0010a924;
        }
        goto switchD_0010a448_caseD_10102;
      }
      switch(iVar19) {
      case 0x1010101:
      case 0x1010102:
        if (*(long *)(param_1 + 0x28) == 0) goto LAB_0010aa40;
        iVar19 = 6;
        uVar20 = **(uint **)(param_1 + 0x18);
        *(short *)(lVar21 + 0x1c) = (short)(*(uint **)(param_1 + 0x18))[1];
        break;
      case 0x1010103:
        uVar20 = 0xe0000000;
        goto LAB_0010aa08;
      case 0x1010104:
        goto switchD_0010a448_caseD_10116;
      case 0x1010105:
        goto switchD_0010a448_caseD_10102;
      default:
        goto switchD_0010a448_caseD_10105;
      }
      goto LAB_0010aa0c;
    }
    switch(iVar19) {
    case 0x10101:
      iVar19 = 0x70;
      *(undefined8 *)(lVar21 + 0x68) = _DAT_0010b444;
      *(undefined8 *)(lVar21 + 0x70) = uVar17;
      uVar11 = _DAT_0010b42c;
      uVar17 = _DAT_0010b424;
      *(undefined8 *)(lVar21 + 0x78) = uVar9;
      *(undefined8 *)(lVar21 + 0x80) = uVar10;
      uVar12 = _DAT_0010b43c;
      uVar10 = _DAT_0010b434;
      *(undefined8 *)(lVar21 + 0x48) = uVar17;
      *(undefined8 *)(lVar21 + 0x50) = uVar11;
      uVar9 = _DAT_0010b40c;
      uVar17 = _DAT_0010b404;
      *(undefined8 *)(lVar21 + 0x58) = uVar10;
      *(undefined8 *)(lVar21 + 0x60) = uVar12;
      uVar11 = _DAT_0010b41c;
      uVar10 = _DAT_0010b414;
      *(undefined8 *)(lVar21 + 0x28) = uVar17;
      *(undefined8 *)(lVar21 + 0x30) = uVar9;
      uVar9 = DAT_0010b3fc;
      uVar17 = oid_supported_list;
      *(undefined8 *)(lVar21 + 0x38) = uVar10;
      *(undefined8 *)(lVar21 + 0x40) = uVar11;
      *(undefined8 *)__dest = uVar17;
      *(undefined8 *)(lVar21 + 0x20) = uVar9;
      goto LAB_0010aa10;
    case 0x10102:
      goto switchD_0010a448_caseD_10102;
    case 0x10103:
    case 0x10104:
      uVar20 = *(uint *)(param_1 + 0xc);
      break;
    case 0x10105:
    case 0x10108:
    case 0x10109:
    case 0x1010f:
    case 0x10110:
    case 0x10112:
    case 0x10115:
switchD_0010a448_caseD_10105:
      _printk(&DAT_0010ce09,"gen_ndis_query_resp",iVar19);
LAB_0010aa40:
      *(undefined4 *)(lVar21 + 0x10) = 0;
      *(undefined4 *)(plVar15 + 3) = 0x18;
      *(undefined4 *)(lVar21 + 4) = 0x18;
      goto LAB_0010aa50;
    case 0x10106:
    case 0x1010a:
    case 0x1010b:
      if (*(long *)(param_1 + 0x28) == 0) goto LAB_0010aa40;
      uVar20 = *(uint *)(*(long *)(param_1 + 0x28) + 0xe0);
      break;
    case 0x10107:
      if (*(int *)(param_1 + 0x14) == 1) {
        uVar20 = 0;
      }
      else {
        uVar20 = *(uint *)(param_1 + 0x10);
      }
      break;
    case 0x1010c:
      uVar20 = *(uint *)(param_1 + 0x30);
      break;
    case 0x1010d:
      if (*(char **)(param_1 + 0x38) == (char *)0x0) goto switchD_0010a448_caseD_10102;
      sVar18 = strlen(*(char **)(param_1 + 0x38));
      iVar19 = (int)sVar18;
      memcpy(__dest,*(void **)(param_1 + 0x38),sVar18 & 0xffffffff);
      goto LAB_0010aa10;
    case 0x1010e:
      uVar20 = (uint)**(ushort **)(param_1 + 0x20);
      break;
    case 0x10111:
      uVar20 = 0x616;
      break;
    case 0x10113:
      uVar20 = 0x12;
      break;
    case 0x10114:
      uVar20 = *(uint *)(param_1 + 0x14);
      break;
    case 0x10116:
switchD_0010a448_caseD_10116:
      uVar20 = 1;
      break;
    default:
      iVar23 = 0x10202;
LAB_0010a924:
      if (iVar19 != iVar23) goto switchD_0010a448_caseD_10105;
      goto switchD_0010a448_caseD_10102;
    }
LAB_0010aa08:
    iVar19 = 4;
LAB_0010aa0c:
    *__dest = uVar20;
LAB_0010aa10:
    puVar22 = puVar24 + 3;
    *(int *)(lVar21 + 0x10) = iVar19;
    *(int *)(plVar15 + 3) = iVar19 + 0x18;
    *(int *)(lVar21 + 4) = iVar19 + 0x18;
LAB_0010aa68:
    *puVar22 = 0;
    break;
  case 5:
    uVar20 = param_2[4];
    uVar17 = 0xffffffea;
    if (0x616 < uVar20) goto LAB_0010aa90;
    uVar5 = param_2[5];
    if ((0x616 < uVar5) || (uVar5 - 0x60e < 0xfffff9ea)) goto LAB_0010aa90;
    plVar15 = (long *)kmalloc_trace(_mutex_unlock,0xa20,0x30,uVar2);
    if (plVar15 == (long *)0x0) goto LAB_0010a774;
    plVar15[2] = (long)(plVar15 + 4);
    plVar15[3] = 0x10;
    _raw_spin_lock(param_1 + 0x60);
    puVar27 = *(undefined8 **)(param_1 + 0x58);
    uVar16 = __list_add_valid(plVar15,puVar27,param_1 + 0x50);
    if ((uVar16 & 1) != 0) {
      *(long **)(param_1 + 0x58) = plVar15;
      *plVar15 = param_1 + 0x50;
      plVar15[1] = (long)puVar27;
      *puVar27 = plVar15;
    }
    _raw_spin_unlock(param_1 + 0x60);
    puVar24 = (undefined4 *)plVar15[2];
    *puVar24 = 0x80000005;
    puVar24[1] = 0x10;
    puVar24[2] = param_2[2];
    if (plVar15[2] == 0) {
LAB_0010a9fc:
      puVar24[3] = 0xc00000bb;
    }
    else {
      iVar19 = param_2[3];
      if (iVar19 != 0x1010103) {
        if (iVar19 != 0x1010e) {
          _printk(&DAT_0010d2a8,"gen_ndis_set_resp",iVar19,uVar20);
          goto LAB_0010a9fc;
        }
        **(undefined2 **)(param_1 + 0x20) =
             (short)*(undefined4 *)((long)(param_2 + 2) + (ulong)uVar5);
        if (**(short **)(param_1 + 0x20) == 0) {
          *(undefined4 *)(param_1 + 8) = 1;
          netif_carrier_off(*(undefined8 *)(param_1 + 0x28));
          lVar21 = *(long *)(*(long *)(param_1 + 0x28) + 0x3c0);
          *(undefined8 *)(lVar21 + 200) = _jiffies;
          DataMemoryBarrier(2,3);
          puVar1 = (ulong *)(lVar21 + 0xd0);
          Hint_Prefetch(puVar1,2,0,1);
          do {
            cVar6 = '\x01';
            bVar7 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar7) {
              *puVar1 = *puVar1 | 1;
              cVar6 = ExclusiveMonitorsStatus();
            }
          } while (cVar6 != '\0');
        }
        else {
          *(undefined4 *)(param_1 + 8) = 2;
          netif_carrier_on(*(undefined8 *)(param_1 + 0x28));
          if ((*(ulong *)(*(long *)(param_1 + 0x28) + 0x38) & 1) != 0) {
            netif_tx_wake_queue(*(undefined8 *)(*(long *)(param_1 + 0x28) + 0x3c0));
          }
        }
      }
      puVar24[3] = 0;
    }
    break;
  case 6:
    lVar21 = param_1 + 0x60;
    plVar15 = (long *)(param_1 + 0x50);
    while( true ) {
      _raw_spin_lock(lVar21);
      plVar26 = plVar15;
      do {
        plVar26 = (long *)*plVar26;
        if (plVar26 == plVar15) {
          _raw_spin_unlock(lVar21);
          goto LAB_0010a6f0;
        }
      } while (*(int *)((long)plVar26 + 0x1c) != 0);
      *(undefined4 *)((long)plVar26 + 0x1c) = 1;
      _raw_spin_unlock(lVar21);
      lVar29 = plVar26[2];
      if (lVar29 == 0) break;
      _raw_spin_lock(lVar21);
      plVar26 = (long *)*plVar15;
      while (plVar8 = plVar26, plVar8 != plVar15) {
        plVar26 = (long *)*plVar8;
        if (plVar8[2] == lVar29) {
          uVar16 = __list_del_entry_valid(plVar8);
          if ((uVar16 & 1) != 0) {
            lVar3 = *plVar8;
            plVar4 = (long *)plVar8[1];
            *(long **)(lVar3 + 8) = plVar4;
            *plVar4 = lVar3;
          }
          *plVar8 = -0x2152ffffffffff00;
          plVar8[1] = -0x2152fffffffffede;
          kfree(plVar8);
        }
      }
      _raw_spin_unlock(lVar21);
    }
LAB_0010a6f0:
    puVar27 = (undefined8 *)kmalloc_trace(_mutex_unlock,0xa20,0x30);
    if (puVar27 == (undefined8 *)0x0) {
LAB_0010a774:
      uVar17 = 0xfffffff4;
      goto LAB_0010aa90;
    }
    puVar27[2] = puVar27 + 4;
    puVar27[3] = 0x10;
    _raw_spin_lock(lVar21);
    puVar28 = *(undefined8 **)(param_1 + 0x58);
    uVar16 = __list_add_valid(puVar27,puVar28,plVar15);
    if ((uVar16 & 1) != 0) {
      *(undefined8 **)(param_1 + 0x58) = puVar27;
      *puVar27 = plVar15;
      puVar27[1] = puVar28;
      *puVar28 = puVar27;
    }
    _raw_spin_unlock(lVar21);
    puVar24 = (undefined4 *)puVar27[2];
    *(undefined8 *)(puVar24 + 1) = 0x10;
    puVar24[3] = 1;
    *puVar24 = 0x80000006;
    break;
  default:
    _printk(&DAT_0010e674,"rndis_msg_parser");
LAB_0010a7fc:
    uVar17 = 0xfffffdf4;
    goto LAB_0010aa90;
  case 8:
    plVar15 = (long *)kmalloc_trace(_mutex_unlock,0xa20,0x30,uVar2);
    if (plVar15 == (long *)0x0) goto LAB_0010a774;
    plVar15[2] = (long)(plVar15 + 4);
    plVar15[3] = 0x10;
    _raw_spin_lock(param_1 + 0x60);
    puVar27 = *(undefined8 **)(param_1 + 0x58);
    uVar16 = __list_add_valid(plVar15,puVar27,param_1 + 0x50);
    if ((uVar16 & 1) != 0) {
      *(long **)(param_1 + 0x58) = plVar15;
      *plVar15 = param_1 + 0x50;
      plVar15[1] = (long)puVar27;
      *puVar27 = plVar15;
    }
    _raw_spin_unlock(param_1 + 0x60);
    puVar24 = (undefined4 *)plVar15[2];
    *puVar24 = 0x80000008;
    puVar24[1] = 0x10;
    puVar24[2] = param_2[2];
    puVar24[3] = 0;
  }
  if (*(int *)(*(code **)(param_1 + 0x40) + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
    pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10aa88);
    (*pcVar13)();
  }
  (**(code **)(param_1 + 0x40))(*(undefined8 *)(param_1 + 0x48));
LAB_0010aa8c:
  uVar17 = 0;
LAB_0010aa90:
  lVar21 = sp_el0;
  if (*(long *)(lVar21 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar17);
  }
  return;
switchD_0010a448_caseD_10102:
  iVar19 = 4;
  *__dest = 0;
  goto LAB_0010aa10;
}



//------------------------------------------------------------
// rndis_register @ 0010ab08 size=188
// signature: undefined rndis_register(void)
// callers: [gsi_bind]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * rndis_register(long param_1,undefined8 param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    piVar2 = (int *)0xffffffffffffffea;
  }
  else {
    iVar1 = ida_alloc_range(&rndis_ida,0,999,0xcc0);
    if (iVar1 < 0) {
      piVar2 = (int *)0xffffffffffffffed;
    }
    else {
      piVar2 = (int *)kmalloc_trace(_delayed_work_timer_fn,0xdc0,0x68);
      if (piVar2 == (int *)0x0) {
        ida_free(&rndis_ida,iVar1);
        piVar2 = (int *)0xfffffffffffffff4;
      }
      else {
        *piVar2 = iVar1;
        piVar2[2] = 0;
        *(undefined1 *)(piVar2 + 1) = 1;
        piVar2[5] = 1;
        *(long *)(piVar2 + 0x10) = param_1;
        *(undefined8 *)(piVar2 + 0x12) = param_2;
        *(int **)(piVar2 + 0x14) = piVar2 + 0x14;
        *(int **)(piVar2 + 0x16) = piVar2 + 0x14;
        piVar2[0x18] = 0;
      }
    }
  }
  return piVar2;
}



//------------------------------------------------------------
// rndis_deregister @ 0010abc8 size=60
// signature: undefined rndis_deregister(void)
// callers: [gsi_unbind, gsi_bind]
//------------------------------------------------------------

void rndis_deregister(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    uVar1 = *param_1;
    kfree();
    ida_free(&rndis_ida,uVar1);
  }
  return;
}



//------------------------------------------------------------
// rndis_set_param_dev @ 0010ac08 size=40
// signature: undefined rndis_set_param_dev(void)
// callers: [gsi_set_alt]
//------------------------------------------------------------

undefined8 rndis_set_param_dev(long param_1,long param_2,undefined8 param_3)

{
  if (param_2 == 0) {
    return 0xffffffea;
  }
  if (param_1 == 0) {
    return 0xffffffff;
  }
  *(undefined8 *)(param_1 + 0x20) = param_3;
  *(long *)(param_1 + 0x28) = param_2;
  return 0;
}



//------------------------------------------------------------
// rndis_set_param_vendor @ 0010ac34 size=32
// signature: undefined rndis_set_param_vendor(void)
// callers: [gsi_bind]
//------------------------------------------------------------

undefined8 rndis_set_param_vendor(long param_1,undefined4 param_2,long param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1 != 0) && (param_3 != 0)) {
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0x30) = param_2;
    *(long *)(param_1 + 0x38) = param_3;
  }
  return uVar1;
}



//------------------------------------------------------------
// rndis_set_param_medium @ 0010ac58 size=28
// signature: undefined rndis_set_param_medium(void)
// callers: [gsi_bind, gsi_set_alt]
//------------------------------------------------------------

undefined8 rndis_set_param_medium(long param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 == 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x10) = param_3;
  return 0;
}



//------------------------------------------------------------
// rndis_add_hdr @ 0010ac78 size=100
// signature: undefined rndis_add_hdr(void)
// callers: []
//------------------------------------------------------------

void rndis_add_hdr(long param_1)

{
  undefined4 *puVar1;
  
  if (param_1 != 0) {
    puVar1 = (undefined4 *)skb_push(param_1,0x2c);
    *(undefined8 *)(puVar1 + 1) = 0;
    *(undefined8 *)(puVar1 + 3) = 0;
    *(undefined8 *)(puVar1 + 5) = 0;
    *(undefined8 *)(puVar1 + 7) = 0;
    *(undefined8 *)(puVar1 + 9) = 0;
    *puVar1 = 1;
    puVar1[1] = *(undefined4 *)(param_1 + 0x70);
    puVar1[2] = 0x24;
    puVar1[3] = *(int *)(param_1 + 0x70) + -0x2c;
  }
  return;
}



//------------------------------------------------------------
// rndis_rm_hdr @ 0010ace0 size=152
// signature: undefined rndis_rm_hdr(void)
// callers: []
//------------------------------------------------------------

undefined8 rndis_rm_hdr(undefined8 param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_2 + 0xe0);
  if (*piVar3 == 1) {
    lVar1 = skb_pull(param_2,piVar3[2] + 8);
    if (lVar1 == 0) {
      __dev_kfree_skb_any(param_2,1);
      uVar2 = 0xffffffb5;
    }
    else {
      skb_trim(param_2,piVar3[3]);
      skb_queue_tail(param_3,param_2);
      uVar2 = 0;
    }
  }
  else {
    __dev_kfree_skb_any(param_2,1);
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// cleanup_module @ 0010ae98 size=112
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  if (ipa_usb_wq != 0) {
    destroy_workqueue();
  }
  usb_function_unregister(&gsiusb_func);
  if (major != 0) {
    unregister_chrdev_region(major << 0x14,3);
    major = 0;
  }
  class_destroy(gsi_class);
  debugfs_remove(debugfs);
  return;
}



//------------------------------------------------------------
// complete_all @ 00111000 size=1
// signature: undefined complete_all(void)
// callers: [ipa_ready_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00111008 size=1
// signature: undefined alloc_workqueue(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00111010 size=1
// signature: undefined __mutex_init(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 00111018 size=1
// signature: undefined __class_create(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 00111020 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00111028 size=1
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
// debugfs_create_file @ 00111030 size=1
// signature: undefined debugfs_create_file(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_bool @ 00111038 size=1
// signature: undefined debugfs_create_bool(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_bool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_function_register @ 00111040 size=1
// signature: undefined usb_function_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_function_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00111048 size=1
// signature: undefined _printk(void)
// callers: [gsi_ctrl_dev_poll, gsi_ctrl_send_notification, ipa_work_handler, ipa_usb_notify_cb, gsi_rndis_flow_ctrl_enable, gsi_disable, gsi_suspend, gsi_wakeup_host, gsi_setup, gsi_ctrl_dev_write, ipa_connect_channels, gsi_ctrl_dev_open, gsi_alloc, gsi_free_inst, gsi_ncm_do_notify, rndis_msg_parser, gsi_set_alt, init_module, usb_gsi_rw_write, gsi_set_inst_name, gsi_resume, gsi_ctrl_dev_ioctl, gsi_ctrl_dev_release, usb_gsi_rw_timer_write, gsi_ctrl_notify_resp_complete, post_event, gsi_ctrl_dev_read, gsi_rndis_command_complete, gsi_ctrl_send_cpkt_tomodem, ipa_disconnect_channel, gsi_ctrl_set_ntb_cmd_complete, gsi_bind, ipa_suspend_work_handler, gsi_rndis_response_available]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 00111050 size=1
// signature: undefined class_destroy(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00111058 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [gsi_set_inst_name, ipa_data_path_enable, ipa_work_handler, gsi_ctrl_dev_ioctl, gsi_suspend, usb_gsi_rw_timer_write, gsi_setup, ipa_data_path_disable, gsi_rndis_class_id_store, gsi_ctrl_dev_read, ipa_connect_channels, rndis_msg_parser, ipa_resume_work_handler, ipa_suspend_work_handler, init_module, usb_gsi_rw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 00111060 size=1
// signature: undefined destroy_workqueue(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_function_unregister @ 00111068 size=1
// signature: undefined usb_function_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_function_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 00111070 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00111078 size=1
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
// kstrtou8_from_user @ 00111080 size=1
// signature: undefined kstrtou8_from_user(void)
// callers: [usb_gsi_rw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtou8_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00111090 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [gsi_rw_timer_func, usb_gsi_rw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mod_timer @ 00111098 size=1
// signature: undefined mod_timer(void)
// callers: [gsi_rw_timer_func, usb_gsi_rw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mod_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// del_timer_sync @ 001110a0 size=1
// signature: undefined del_timer_sync(void)
// callers: [usb_gsi_rw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void del_timer_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 001110a8 size=1
// signature: undefined ipc_log_string(void)
// callers: [gsi_ctrl_dev_poll, gsi_ctrl_send_notification, ipa_work_handler, ipa_usb_notify_cb, gsi_rndis_flow_ctrl_enable, gsi_disable, gsi_suspend, gsi_wakeup_host, gsi_setup, peek_event, gsi_ctrl_dev_write, ipa_connect_channels, gsi_ctrl_dev_open, gsi_alloc, gsi_free_inst, gsi_unbind, gsi_ncm_do_notify, gsi_rndis_ipa_reset_trigger, gsi_set_alt, usb_gsi_rw_write, gsi_opts_release, gsi_set_inst_name, ipa_data_path_enable, gsi_ep_enable, gsi_resume, gsi_ctrl_dev_ioctl, gsi_ctrl_dev_release, usb_gsi_rw_timer_write, gsi_ctrl_notify_resp_complete, ipa_data_path_disable, post_event, gsi_rw_timer_func, gsi_ctrl_dev_read, gsi_rndis_command_complete, gsi_ctrl_send_cpkt_tomodem, ipa_disconnect_channel, gsi_ctrl_set_ntb_cmd_complete, gsi_bind, gsi_func_suspend, ipa_resume_work_handler, ipa_suspend_work_handler, read_event, gsi_rndis_response_available]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 001110b0 size=1
// signature: undefined single_open(void)
// callers: [usb_gsi_rw_timer_open, usb_gsi_rw_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 001110b8 size=1
// signature: undefined seq_printf(void)
// callers: [usb_gsi_rw_timer_show, usb_gsi_rw_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtou16_from_user @ 001110c0 size=1
// signature: undefined kstrtou16_from_user(void)
// callers: [usb_gsi_rw_timer_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtou16_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001110d0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [gsi_set_inst_name, gsi_ctrl_dev_write, ipa_usb_notify_cb, gsi_ctrl_send_cpkt_tomodem, gsi_info_show, gsi_ctrl_dev_ioctl, rndis_msg_parser, rndis_register, gsi_bind, gsi_alloc_inst, rndis_indicate_status_msg, gsi_rndis_response_available]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// config_group_init_type_name @ 001110d8 size=1
// signature: undefined config_group_init_type_name(void)
// callers: [gsi_set_inst_name, gsi_alloc_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void config_group_init_type_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 001110e0 size=1
// signature: size_t strlen(char * __s)
// callers: [gsi_set_inst_name, rndis_msg_parser]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncasecmp @ 001110e8 size=1
// signature: int strncasecmp(char * __s1, char * __s2, size_t __n)
// callers: [gsi_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncasecmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001110f0 size=1
// signature: undefined mutex_lock(void)
// callers: [gsi_ctrl_dev_poll, gsi_set_inst_name, gsi_ctrl_dev_write, gsi_ctrl_dev_read, gsi_ctrl_dev_open, gsi_free_inst, gsi_ctrl_dev_ioctl, gsi_ctrl_dev_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001110f8 size=1
// signature: undefined mutex_unlock(void)
// callers: [gsi_ctrl_dev_poll, gsi_set_inst_name, gsi_ctrl_dev_write, gsi_ctrl_dev_read, gsi_ctrl_dev_open, gsi_free_inst, gsi_ctrl_dev_ioctl, gsi_ctrl_dev_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00111108 size=1
// signature: undefined init_timer_key(void)
// callers: [gsi_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00111110 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [gsi_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlcat @ 00111118 size=1
// signature: undefined strlcat(void)
// callers: [gsi_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcat(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ida_alloc_range @ 00111120 size=1
// signature: undefined ida_alloc_range(void)
// callers: [gsi_set_inst_name, rndis_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ida_alloc_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 00111128 size=1
// signature: undefined cdev_init(void)
// callers: [gsi_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 00111130 size=1
// signature: undefined cdev_add(void)
// callers: [gsi_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 00111138 size=1
// signature: undefined device_create(void)
// callers: [gsi_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00111140 size=1
// signature: undefined scnprintf(void)
// callers: [gsi_set_inst_name, gsi_info_show, gsi_bind, gsi_rndis_class_id_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00111148 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [gsi_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ida_free @ 00111150 size=1
// signature: undefined ida_free(void)
// callers: [gsi_set_inst_name, gsi_free_inst, gsi_inst_clean, rndis_register, rndis_deregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ida_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 00111158 size=1
// signature: undefined cdev_del(void)
// callers: [gsi_set_inst_name, gsi_free_inst, gsi_inst_clean]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00111160 size=1
// signature: undefined kfree(void)
// callers: [gsi_set_inst_name, gsi_ctrl_clear_cpkt_queues, gsi_ctrl_send_notification, gsi_inst_clean, gsi_info_show, gsi_ctrl_dev_ioctl, rndis_uninit, gsi_setup, rndis_free_response, gsi_ctrl_dev_write, gsi_ctrl_pkt_free, gsi_ctrl_dev_read, gsi_free_inst, gsi_unbind, gsi_ctrl_send_cpkt_tomodem, rndis_msg_parser, gsi_bind, rndis_deregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 00111168 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [gsi_free_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 00111170 size=1
// signature: undefined device_destroy(void)
// callers: [gsi_free_inst, gsi_inst_clean]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_put_function_instance @ 00111178 size=1
// signature: undefined usb_put_function_instance(void)
// callers: [gsi_opts_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_put_function_instance(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtou8 @ 00111180 size=1
// signature: undefined kstrtou8(void)
// callers: [gsi_rndis_class_id_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtou8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00111188 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [gsi_ctrl_dev_poll, gsi_ctrl_clear_cpkt_queues, gsi_ctrl_send_notification, ipa_work_handler, gsi_resume, ipa_usb_notify_cb, gsi_rndis_flow_ctrl_enable, gsi_ctrl_dev_ioctl, gsi_disable, gsi_suspend, gsi_ctrl_notify_resp_complete, peek_event, post_event, gsi_ctrl_dev_write, gsi_ctrl_dev_read, gsi_ctrl_send_cpkt_tomodem, gsi_rndis_ipa_reset_trigger, gsi_set_alt, read_event, gsi_rndis_response_available]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00111190 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [gsi_ctrl_dev_poll, gsi_ctrl_clear_cpkt_queues, gsi_ctrl_send_notification, ipa_work_handler, gsi_resume, ipa_usb_notify_cb, gsi_rndis_flow_ctrl_enable, gsi_ctrl_dev_ioctl, gsi_disable, gsi_suspend, gsi_ctrl_notify_resp_complete, peek_event, post_event, gsi_ctrl_dev_write, gsi_ctrl_dev_read, gsi_ctrl_send_cpkt_tomodem, gsi_rndis_ipa_reset_trigger, gsi_set_alt, read_event, gsi_rndis_response_available]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_composite_setup_continue @ 00111198 size=1
// signature: undefined usb_composite_setup_continue(void)
// callers: [ipa_work_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_composite_setup_continue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 001111a0 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [usb_gadget_autopm_get, ipa_work_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_gsi_ep_op @ 001111b0 size=1
// signature: undefined usb_gsi_ep_op(void)
// callers: [ipa_data_path_enable, gsi_ep_enable, ipa_connect_channels, ipa_work_handler, ipa_disconnect_channel, gsi_suspend, ipa_resume_work_handler, ipa_suspend_work_handler, ipa_data_path_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_gsi_ep_op(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 001111b8 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [ipa_work_handler, gsi_resume, ipa_usb_notify_cb, gsi_rndis_flow_ctrl_enable, gsi_disable, gsi_suspend, gsi_set_alt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 001111c0 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [usb_gadget_autopm_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// config_ep_by_speed @ 001111c8 size=1
// signature: undefined config_ep_by_speed(void)
// callers: [gsi_ep_enable, gsi_resume, gsi_set_alt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void config_ep_by_speed(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_ep_set_mode @ 001111d0 size=1
// signature: undefined msm_ep_set_mode(void)
// callers: [ipa_disconnect_channel, gsi_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_ep_set_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_gadget_wakeup @ 001111d8 size=1
// signature: undefined usb_gadget_wakeup(void)
// callers: [gsi_wakeup_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_gadget_wakeup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001111e0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [gsi_ctrl_clear_cpkt_queues, gsi_ctrl_dev_read, gsi_ctrl_send_notification, gsi_ctrl_dev_ioctl, rndis_msg_parser, rndis_uninit, gsi_setup, rndis_free_response]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// print_hex_dump @ 001111e8 size=1
// signature: undefined print_hex_dump(void)
// callers: [gsi_ctrl_dev_write, gsi_ctrl_dev_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void print_hex_dump(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 001111f0 size=1
// signature: undefined __check_object_size(void)
// callers: [gsi_ctrl_dev_write, gsi_ctrl_dev_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 00111200 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [gsi_ctrl_dev_read, gsi_ctrl_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00111208 size=1
// signature: undefined init_wait_entry(void)
// callers: [gsi_ctrl_dev_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00111210 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [gsi_ctrl_dev_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 00111218 size=1
// signature: undefined schedule(void)
// callers: [gsi_ctrl_dev_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 00111220 size=1
// signature: undefined finish_wait(void)
// callers: [gsi_ctrl_dev_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00111228 size=1
// signature: undefined ___ratelimit(void)
// callers: [gsi_ctrl_dev_poll, gsi_ctrl_dev_write, gsi_ctrl_dev_read, gsi_ctrl_dev_open, gsi_ctrl_dev_ioctl, gsi_ctrl_dev_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00111238 size=1
// signature: undefined __kmalloc(void)
// callers: [gsi_ctrl_dev_write, gsi_ctrl_send_cpkt_tomodem, gsi_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00111240 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [gsi_ctrl_dev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00111248 size=1
// signature: undefined __list_add_valid(void)
// callers: [gsi_ctrl_dev_write, ipa_usb_notify_cb, gsi_ctrl_send_cpkt_tomodem, gsi_ctrl_dev_ioctl, rndis_msg_parser, rndis_indicate_status_msg, gsi_rndis_response_available]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00111250 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [gsi_ctrl_dev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_queue @ 00111258 size=1
// signature: undefined usb_ep_queue(void)
// callers: [gsi_ctrl_send_notification, gsi_ncm_do_notify, gsi_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_queue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_interface_id @ 00111260 size=1
// signature: undefined usb_interface_id(void)
// callers: [gsi_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_interface_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_random_bytes @ 00111268 size=1
// signature: undefined get_random_bytes(void)
// callers: [gsi_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_random_bytes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_string_id @ 00111270 size=1
// signature: undefined usb_string_id(void)
// callers: [gsi_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_string_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_autoconfig @ 00111278 size=1
// signature: undefined usb_ep_autoconfig(void)
// callers: [gsi_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_autoconfig(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_alloc_request @ 00111280 size=1
// signature: undefined usb_ep_alloc_request(void)
// callers: [gsi_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_alloc_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_assign_descriptors @ 00111288 size=1
// signature: undefined usb_assign_descriptors(void)
// callers: [gsi_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_assign_descriptors(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_free_request @ 00111290 size=1
// signature: undefined usb_ep_free_request(void)
// callers: [gsi_unbind, gsi_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_free_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00111298 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [gsi_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drain_workqueue @ 001112a0 size=1
// signature: undefined drain_workqueue(void)
// callers: [gsi_unbind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drain_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_free_all_descriptors @ 001112a8 size=1
// signature: undefined usb_free_all_descriptors(void)
// callers: [gsi_unbind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_free_all_descriptors(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_disable @ 001112b0 size=1
// signature: undefined usb_ep_disable(void)
// callers: [gsi_disable, gsi_set_alt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_enable @ 001112b8 size=1
// signature: undefined usb_ep_enable(void)
// callers: [gsi_set_alt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_by_name @ 001112c8 size=1
// signature: undefined dev_get_by_name(void)
// callers: [gsi_set_alt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule_notrace @ 001112d0 size=1
// signature: undefined preempt_schedule_notrace(void)
// callers: [gsi_set_alt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule_notrace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001112d8 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [gsi_ctrl_send_cpkt_tomodem, rndis_msg_parser, gsi_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 001112e0 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [gsi_ncm_notify_complete, rndis_get_next_response, ipa_usb_notify_cb, gsi_ncm_do_notify, rndis_msg_parser, rndis_indicate_status_msg, rndis_uninit, gsi_setup, rndis_free_response]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 001112e8 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [gsi_ncm_notify_complete, rndis_get_next_response, ipa_usb_notify_cb, gsi_ncm_do_notify, rndis_msg_parser, rndis_indicate_status_msg, rndis_uninit, gsi_setup, rndis_free_response]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001112f0 size=1
// signature: undefined _dev_err(void)
// callers: [gsi_ncm_notify_complete]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 001112f8 size=1
// signature: undefined __wake_up(void)
// callers: [gsi_ctrl_send_cpkt_tomodem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_set_halt @ 00111300 size=1
// signature: undefined usb_ep_set_halt(void)
// callers: [gsi_ctrl_set_ntb_cmd_complete]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_set_halt(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_stats @ 00111320 size=1
// signature: undefined dev_get_stats(void)
// callers: [rndis_msg_parser]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_stats(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netif_carrier_off @ 00111328 size=1
// signature: undefined netif_carrier_off(void)
// callers: [rndis_msg_parser]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netif_carrier_off(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netif_carrier_on @ 00111330 size=1
// signature: undefined netif_carrier_on(void)
// callers: [rndis_msg_parser]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netif_carrier_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netif_tx_wake_queue @ 00111338 size=1
// signature: undefined netif_tx_wake_queue(void)
// callers: [rndis_msg_parser]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netif_tx_wake_queue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_push @ 00111340 size=1
// signature: undefined skb_push(void)
// callers: [rndis_add_hdr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_push(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_pull @ 00111348 size=1
// signature: undefined skb_pull(void)
// callers: [rndis_rm_hdr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_pull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_trim @ 00111350 size=1
// signature: undefined skb_trim(void)
// callers: [rndis_rm_hdr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_trim(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_queue_tail @ 00111358 size=1
// signature: undefined skb_queue_tail(void)
// callers: [rndis_rm_hdr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_queue_tail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __dev_kfree_skb_any @ 00111360 size=1
// signature: undefined __dev_kfree_skb_any(void)
// callers: [rndis_rm_hdr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __dev_kfree_skb_any(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



