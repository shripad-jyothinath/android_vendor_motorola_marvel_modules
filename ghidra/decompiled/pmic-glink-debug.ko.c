// Decompiled by Ghidra 12.2
// Program: pmic-glink-debug.ko
// Image base: 00100000

//------------------------------------------------------------
// pmic_glink_debug_probe @ 0010028c size=1256
// signature: undefined pmic_glink_debug_probe(void)
// callers: []
//------------------------------------------------------------

ulong pmic_glink_debug_probe(long param_1)

{
  int iVar1;
  uint uVar2;
  ulong *puVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  char *pcVar7;
  long lVar8;
  ulong uVar9;
  long *plVar10;
  ulong uVar11;
  ulong uVar12;
  char *local_98;
  char *local_90;
  undefined8 local_88;
  ulong *local_80;
  code *local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar4 = sp_el0;
  uVar6 = param_1 + 0x10;
  local_68 = *(long *)(lVar4 + 0x638);
  local_78 = (code *)0x0;
  uStack_70 = 0;
  local_88 = 0;
  local_80 = (ulong *)0x0;
  local_98 = (char *)0x0;
  puVar3 = (ulong *)devm_kmalloc(uVar6,0x198,0xdc0);
  if (puVar3 == (ulong *)0x0) {
LAB_00100640:
    uVar11 = 0xfffffff4;
  }
  else {
    puVar3[1] = uVar6;
    __mutex_init(puVar3 + 2,"&gd->lock",&pmic_glink_debug_probe___key);
    *(undefined4 *)(puVar3 + 8) = 0;
    __init_swait_queue_head(puVar3 + 9,"&x->wait",&init_completion___key);
    *(ulong **)(param_1 + 0xa8) = puVar3;
    lVar4 = device_get_next_child_node(uVar6,0);
    if (lVar4 == 0) {
      uVar9 = 0;
      uVar12 = 0;
    }
    else {
      uVar12 = 0;
      uVar9 = 0;
      do {
        uVar5 = fwnode_property_read_string(lVar4,"qcom,bus-type",&local_98);
        pcVar7 = local_98;
        if ((int)uVar5 == 0) {
          iVar1 = strcmp(local_98,"i2c");
          if (iVar1 != 0) {
            iVar1 = strcmp(pcVar7,"spmi");
            if (iVar1 == 0) goto LAB_0010036c;
            _dev_err(puVar3[1],"unsupported bus type: %s\n",pcVar7);
            fwnode_handle_put(lVar4);
            uVar11 = 0xffffffea;
            goto LAB_00100644;
          }
          uVar12 = (ulong)((int)uVar12 + 1);
        }
        else {
          uVar11 = uVar5 & 0xffffffff;
          if ((int)uVar5 != -0x16) {
            fwnode_handle_put(lVar4);
            uVar6 = puVar3[1];
            pcVar7 = "Get qcom,bus-type failed, ret=%d\n";
            goto LAB_001006f4;
          }
LAB_0010036c:
          uVar9 = (ulong)((int)uVar9 + 1);
        }
        lVar4 = device_get_next_child_node(uVar6,lVar4);
      } while (lVar4 != 0);
    }
    if ((int)uVar9 == 0 && (int)uVar12 == 0) {
      _dev_err(uVar6,"pmic bus child nodes missing\n");
      uVar11 = 0xffffffed;
      goto LAB_00100644;
    }
    local_90 = "pmic_register_dump";
    local_88 = CONCAT44(local_88._4_4_,0x800f);
    local_78 = pmic_glink_debug_callback;
    local_80 = puVar3;
    uVar11 = pmic_glink_register_client(uVar6,&local_90);
    *puVar3 = uVar11;
    if (0xfffffffffffff000 < uVar11) {
      if ((int)uVar11 == -0x205) {
        uVar11 = 0xfffffdfb;
      }
      else {
        pcVar7 = "Error registering with pmic_glink, ret=%d\n";
LAB_001006f4:
        _dev_err(uVar6,pcVar7,uVar11 & 0xffffffff);
      }
      goto LAB_00100644;
    }
    if ((int)uVar9 != 0) {
      uVar9 = devm_kmalloc(uVar6,uVar9 << 3,0xdc0);
      puVar3[0x30] = uVar9;
      if (uVar9 == 0) goto LAB_00100640;
    }
    if ((int)uVar12 != 0) {
      uVar9 = devm_kmalloc(uVar6,uVar12 << 3,0xdc0);
      puVar3[0x31] = uVar9;
      if (uVar9 == 0) goto LAB_00100640;
    }
    uVar9 = device_get_next_child_node(uVar6,0);
    if (uVar9 == 0) {
      uVar11 = 0;
    }
    else {
      do {
        local_98 = (char *)0x0;
        iVar1 = fwnode_property_read_string(uVar9,"qcom,bus-type",&local_98);
        if ((iVar1 == 0) && (iVar1 = strcmp(local_98,"i2c"), iVar1 == 0)) {
          if (puVar3[0x31] == 0) goto LAB_001006a0;
          plVar10 = (long *)devm_kmalloc(puVar3[1],0x4d0,0xdc0);
          if (plVar10 == (long *)0x0) goto LAB_001006a8;
          uVar2 = fwnode_property_read_u32_array(uVar9,&DAT_001014c8,plVar10 + 0x99,1);
          if (uVar2 == 0) {
            uVar12 = puVar3[1];
            *plVar10 = (long)puVar3;
            plVar10[0x1b] = uVar12;
            plVar10[3] = (long)&glink_i2c_algo;
            if (uVar9 < 0xfffffffffffff001) {
              lVar4 = uVar9 - 0x18;
              if (*(undefined **)(uVar9 + 8) != &of_fwnode_ops) {
                lVar4 = 0;
              }
            }
            else {
              lVar4 = 0;
            }
            plVar10[0x6c] = lVar4;
            strscpy((long)plVar10 + 0x414,"glink-i2c",10);
            plVar10[0x22] = (long)plVar10;
            uVar2 = i2c_add_adapter(plVar10 + 1);
            if (uVar2 == 0) {
              uVar2 = *(uint *)((long)puVar3 + 0x194);
              *(uint *)((long)puVar3 + 0x194) = uVar2 + 1;
              *(long **)(puVar3[0x31] + (ulong)uVar2 * 8) = plVar10;
              uVar2 = devm_of_platform_populate(puVar3[1]);
              if (uVar2 == 0) goto LAB_00100558;
              uVar11 = (ulong)uVar2;
              goto LAB_001006bc;
            }
            uVar6 = puVar3[1];
            pcVar7 = "Add i2c adapter failed, ret=%d\n";
          }
          else {
            uVar6 = puVar3[1];
            pcVar7 = "Could not find reg property, ret=%d\n";
          }
          uVar11 = (ulong)uVar2;
          _dev_err(uVar6,pcVar7,uVar11);
LAB_001006bc:
          fwnode_handle_put(uVar9);
          pmic_glink_debug_remove(param_1);
          break;
        }
        if (puVar3[0x30] == 0) {
LAB_001006a0:
          uVar11 = 0xffffffed;
          goto LAB_001006bc;
        }
        lVar4 = spmi_controller_alloc(puVar3[1],0x18);
        if (lVar4 == 0) {
LAB_001006a8:
          uVar11 = 0xfffffff4;
          goto LAB_001006bc;
        }
        plVar10 = *(long **)(lVar4 + 0x98);
        *plVar10 = (long)puVar3;
        plVar10[1] = lVar4;
        uVar2 = fwnode_property_read_u32_array(uVar9,&DAT_001014c8,plVar10 + 2,1);
        if (uVar2 != 0) {
          uVar11 = (ulong)uVar2;
          _dev_err(puVar3[1],"Could not find reg property, ret=%d\n",uVar11);
LAB_001006b4:
          put_device(lVar4);
          goto LAB_001006bc;
        }
        *(code **)(lVar4 + 0x3a0) = spmi_glink_read_cmd;
        *(code **)(lVar4 + 0x3a8) = spmi_glink_write_cmd;
        *(code **)(lVar4 + 0x398) = spmi_glink_cmd;
        if (uVar9 < 0xfffffffffffff001) {
          lVar8 = uVar9 - 0x18;
          if (*(undefined **)(uVar9 + 8) != &of_fwnode_ops) {
            lVar8 = 0;
          }
        }
        else {
          lVar8 = 0;
        }
        *(long *)(lVar4 + 0x2e8) = lVar8;
        uVar2 = spmi_controller_add(lVar4);
        if (uVar2 != 0) {
          uVar11 = (ulong)uVar2;
          goto LAB_001006b4;
        }
        uVar12 = puVar3[0x32];
        *(uint *)(puVar3 + 0x32) = (uint)uVar12 + 1;
        *(long **)(puVar3[0x30] + (ulong)(uint)uVar12 * 8) = plVar10;
LAB_00100558:
        uVar9 = device_get_next_child_node(uVar6,uVar9);
        uVar11 = 0;
      } while (uVar9 != 0);
    }
  }
LAB_00100644:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11 & 0xffffffff;
}



//------------------------------------------------------------
// pmic_glink_debug_remove @ 00100778 size=184
// signature: undefined pmic_glink_debug_remove(void)
// callers: [pmic_glink_debug_probe]
//------------------------------------------------------------

undefined8 pmic_glink_debug_remove(long param_1)

{
  uint uVar1;
  long lVar2;
  undefined8 *puVar3;
  uint uVar4;
  
  puVar3 = *(undefined8 **)(param_1 + 0xa8);
  if (*(int *)(puVar3 + 0x32) != 0) {
    uVar1 = 0;
    do {
      lVar2 = *(long *)(puVar3[0x30] + (long)(int)uVar1 * 8);
      if (lVar2 != 0) {
        spmi_controller_remove(*(undefined8 *)(lVar2 + 8));
        if (*(long *)(*(long *)(puVar3[0x30] + (long)(int)uVar1 * 8) + 8) != 0) {
          put_device();
        }
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(puVar3 + 0x32));
  }
  uVar1 = *(uint *)((long)puVar3 + 0x194);
  if (uVar1 != 0) {
    uVar4 = 0;
    do {
      lVar2 = *(long *)(puVar3[0x31] + (long)(int)uVar4 * 8);
      if (lVar2 != 0) {
        i2c_del_adapter(lVar2 + 8);
        uVar1 = *(uint *)((long)puVar3 + 0x194);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  pmic_glink_unregister_client(*puVar3);
  return 0;
}



//------------------------------------------------------------
// pmic_glink_debug_callback @ 00100834 size=212
// signature: undefined pmic_glink_debug_callback(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_glink_debug_callback(long param_1,void *param_2,long param_3)

{
  undefined8 uVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = *(int *)((long)param_2 + 8);
  if (iVar3 == 0x38) {
    if (param_3 != 0x10) {
      _dev_err(*(undefined8 *)(param_1 + 8),"Invalid write response, glink packet size=%zu\n");
      return 0;
    }
    iVar3 = *(int *)((long)param_2 + 0xc);
    if (iVar3 == 0) {
LAB_0010088c:
      complete(param_1 + 0x40);
      return 0;
    }
    uVar1 = *(undefined8 *)(param_1 + 8);
    pcVar2 = "glink write failed, ret=%d\n";
  }
  else if (iVar3 == 0x37) {
    if (param_3 != 0x11c) {
      _dev_err(*(undefined8 *)(param_1 + 8),"Invalid read response, glink packet size=%zu\n");
      return 0;
    }
    iVar3 = *(int *)((long)param_2 + 0x18);
    if (-1 < iVar3) {
      memcpy((void *)(param_1 + 0x60),param_2,0x11c);
      goto LAB_0010088c;
    }
    uVar1 = *(undefined8 *)(param_1 + 8);
    pcVar2 = "glink read failed, ret=%d\n";
  }
  else {
    uVar1 = *(undefined8 *)(param_1 + 8);
    pcVar2 = "Unknown opcode %u\n";
  }
  _dev_err(uVar1,pcVar2,iVar3);
  return 0;
}



//------------------------------------------------------------
// i2c_glink_xfer @ 0010090c size=328
// signature: undefined i2c_glink_xfer(void)
// callers: []
//------------------------------------------------------------

int i2c_glink_xfer(long param_1,long param_2,int param_3)

{
  short *psVar1;
  long lVar2;
  ushort uVar3;
  short sVar4;
  ushort uVar5;
  long lVar6;
  int iVar7;
  long *plVar8;
  ushort *puVar9;
  long lVar10;
  long lVar11;
  uint uVar12;
  ulong uVar13;
  
  plVar8 = *(long **)(param_1 + 0x108);
  if (plVar8 == (long *)0x0) {
    param_3 = -0x13;
  }
  else if (0 < param_3) {
    uVar12 = 0;
    lVar11 = *plVar8;
    lVar6 = plVar8[0x99];
    do {
      uVar3 = *(ushort *)(param_2 + (long)(int)uVar12 * 0x10 + 4);
      if (uVar3 < 2) {
        return -0x16;
      }
      lVar10 = (long)(int)uVar12;
      uVar13 = lVar10 + 1;
      psVar1 = (short *)(param_2 + lVar10 * 0x10);
      puVar9 = *(ushort **)(psVar1 + 4);
      sVar4 = *psVar1;
      uVar5 = *puVar9;
      uVar5 = uVar5 >> 8 | uVar5 << 8;
      if (((((int)uVar13 < param_3) && ((*(ushort *)(param_2 + uVar13 * 0x10 + 2) & 1) != 0)) &&
          (sVar4 == *(short *)(param_2 + uVar13 * 0x10))) &&
         (lVar2 = param_2 + uVar13 * 0x10, *(short *)(lVar2 + 4) != 0)) {
        iVar7 = pmic_glink_debug_read_regs(lVar11,(int)lVar6,sVar4,uVar5,*(undefined8 *)(lVar2 + 8))
        ;
      }
      else {
        if (uVar3 < 3) {
          return -0x16;
        }
        if ((*(ushort *)(param_2 + lVar10 * 0x10 + 2) & 1) != 0) {
          return -0x16;
        }
        iVar7 = pmic_glink_debug_write_regs
                          (lVar11,(int)lVar6,sVar4,uVar5,puVar9 + 1,(ulong)uVar3 - 2);
        uVar13 = (ulong)uVar12;
      }
      if (iVar7 != 0) {
        _dev_err(*(undefined8 *)(lVar11 + 8),"%s failed\n","i2c_glink_xfer");
        return iVar7;
      }
      uVar12 = (int)uVar13 + 1;
    } while ((int)uVar12 < param_3);
  }
  return param_3;
}



//------------------------------------------------------------
// i2c_glink_func @ 00100a58 size=8
// signature: undefined i2c_glink_func(void)
// callers: []
//------------------------------------------------------------

undefined8 i2c_glink_func(void)

{
  return 1;
}



//------------------------------------------------------------
// pmic_glink_debug_read_regs @ 00100a60 size=372
// signature: undefined pmic_glink_debug_read_regs(void)
// callers: [i2c_glink_xfer, spmi_glink_read_cmd]
//------------------------------------------------------------

int pmic_glink_debug_read_regs
              (undefined8 *param_1,undefined4 param_2,uint param_3,uint param_4,void *param_5,
              ulong param_6)

{
  size_t sVar1;
  size_t __n;
  long lVar2;
  int iVar3;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 uStack_7c;
  uint local_78;
  uint uStack_74;
  uint local_70;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  mutex_lock();
  do {
    local_78 = param_3 & 0xff;
    local_88 = 0x10000800f;
    sVar1 = param_6;
    if (0xff < param_6) {
      sVar1 = 0x100;
    }
    uStack_74 = param_4 & 0xffff;
    __n = 0x100 - ((ulong)param_4 & 0xff);
    if (sVar1 + ((ulong)param_4 & 0xff) < 0x101) {
      __n = sVar1;
    }
    *(undefined4 *)(param_1 + 8) = 0;
    local_80 = 0x37;
    uStack_7c = param_2;
    local_70 = (uint)__n;
    iVar3 = pmic_glink_write(*param_1,&local_88,0x1c);
    if (iVar3 != 0) goto LAB_00100b74;
    iVar3 = wait_for_completion_timeout(param_1 + 8,0xfa);
    if (iVar3 == 0) {
      _dev_err(param_1[1],"Error, timed out sending message\n");
      iVar3 = -0x6e;
      goto LAB_00100b74;
    }
    if (__n != *(uint *)(param_1 + 0xf)) {
      iVar3 = -0x16;
      goto LAB_00100b74;
    }
    memcpy(param_5,(void *)((long)param_1 + 0x7c),__n);
    param_5 = (void *)((long)param_5 + __n);
    param_4 = (param_4 & 0xffff) + ((uint)__n & 0xffff);
    param_6 = param_6 - __n;
    param_3 = param_3 + (param_4 >> 0x10);
  } while (param_6 != 0);
  iVar3 = 0;
LAB_00100b74:
  mutex_unlock(param_1 + 2);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// pmic_glink_debug_write_regs @ 00100bd4 size=308
// signature: undefined pmic_glink_debug_write_regs(void)
// callers: [spmi_glink_write_cmd, i2c_glink_xfer]
//------------------------------------------------------------

int pmic_glink_debug_write_regs
              (undefined8 *param_1,undefined4 param_2,uint param_3,uint param_4,byte *param_5,
              long param_6)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 uStack_7c;
  uint local_78;
  uint uStack_74;
  uint local_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  mutex_lock();
  do {
    local_78 = param_3 & 0xff;
    uStack_74 = param_4 & 0xffff;
    local_88 = 0x10000800f;
    local_80 = 0x38;
    local_70 = (uint)*param_5;
    *(undefined4 *)(param_1 + 8) = 0;
    uStack_7c = param_2;
    iVar3 = pmic_glink_write(*param_1,&local_88,0x1c);
    if (iVar3 != 0) goto LAB_00100ca8;
    iVar3 = wait_for_completion_timeout(param_1 + 8,0xfa);
    if (iVar3 == 0) {
      _dev_err(param_1[1],"Error, timed out sending message\n");
      iVar3 = -0x6e;
      goto LAB_00100ca8;
    }
    bVar2 = param_6 != 0;
    param_4 = param_4 & 0xffff;
    if (bVar2) {
      param_4 = param_4 + 1;
    }
    if (bVar2) {
      param_5 = param_5 + 1;
    }
    param_6 = param_6 - (ulong)bVar2;
    param_3 = param_3 + (param_4 >> 0x10);
  } while (param_6 != 0);
  iVar3 = 0;
LAB_00100ca8:
  mutex_unlock(param_1 + 2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// spmi_glink_cmd @ 00100d0c size=8
// signature: undefined spmi_glink_cmd(void)
// callers: []
//------------------------------------------------------------

undefined8 spmi_glink_cmd(void)

{
  return 0xffffffa1;
}



//------------------------------------------------------------
// spmi_glink_read_cmd @ 00100d18 size=48
// signature: undefined spmi_glink_read_cmd(void)
// callers: []
//------------------------------------------------------------

int spmi_glink_read_cmd(long param_1)

{
  int iVar1;
  
  iVar1 = pmic_glink_debug_read_regs
                    (**(undefined8 **)(param_1 + 0x98),
                     *(undefined4 *)(*(undefined8 **)(param_1 + 0x98) + 2));
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// spmi_glink_write_cmd @ 00100d4c size=48
// signature: undefined spmi_glink_write_cmd(void)
// callers: []
//------------------------------------------------------------

int spmi_glink_write_cmd(long param_1)

{
  int iVar1;
  
  iVar1 = pmic_glink_debug_write_regs
                    (**(undefined8 **)(param_1 + 0x98),
                     *(undefined4 *)(*(undefined8 **)(param_1 + 0x98) + 2));
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 00100d80 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&pmic_glink_debug_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100db0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&pmic_glink_debug_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00103000 size=1
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
// platform_driver_unregister @ 00103008 size=1
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
// devm_kmalloc @ 00103010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [pmic_glink_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00103018 size=1
// signature: undefined __mutex_init(void)
// callers: [pmic_glink_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00103020 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [pmic_glink_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_get_next_child_node @ 00103028 size=1
// signature: undefined device_get_next_child_node(void)
// callers: [pmic_glink_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_get_next_child_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fwnode_property_read_string @ 00103030 size=1
// signature: undefined fwnode_property_read_string(void)
// callers: [pmic_glink_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fwnode_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00103038 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [pmic_glink_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_register_client @ 00103040 size=1
// signature: undefined pmic_glink_register_client(void)
// callers: [pmic_glink_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_register_client(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// spmi_controller_alloc @ 00103048 size=1
// signature: undefined spmi_controller_alloc(void)
// callers: [pmic_glink_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void spmi_controller_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fwnode_property_read_u32_array @ 00103050 size=1
// signature: undefined fwnode_property_read_u32_array(void)
// callers: [pmic_glink_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fwnode_property_read_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// spmi_controller_add @ 00103060 size=1
// signature: undefined spmi_controller_add(void)
// callers: [pmic_glink_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void spmi_controller_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00103068 size=1
// signature: undefined strscpy(void)
// callers: [pmic_glink_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_add_adapter @ 00103070 size=1
// signature: undefined i2c_add_adapter(void)
// callers: [pmic_glink_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_add_adapter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_of_platform_populate @ 00103078 size=1
// signature: undefined devm_of_platform_populate(void)
// callers: [pmic_glink_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103080 size=1
// signature: undefined _dev_err(void)
// callers: [pmic_glink_debug_callback, i2c_glink_xfer, pmic_glink_debug_read_regs, pmic_glink_debug_probe, pmic_glink_debug_write_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 00103088 size=1
// signature: undefined put_device(void)
// callers: [pmic_glink_debug_remove, pmic_glink_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fwnode_handle_put @ 00103090 size=1
// signature: undefined fwnode_handle_put(void)
// callers: [pmic_glink_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fwnode_handle_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103098 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [pmic_glink_debug_read_regs, pmic_glink_debug_probe, pmic_glink_debug_write_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// spmi_controller_remove @ 001030a0 size=1
// signature: undefined spmi_controller_remove(void)
// callers: [pmic_glink_debug_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void spmi_controller_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_del_adapter @ 001030a8 size=1
// signature: undefined i2c_del_adapter(void)
// callers: [pmic_glink_debug_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_del_adapter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_unregister_client @ 001030b0 size=1
// signature: undefined pmic_glink_unregister_client(void)
// callers: [pmic_glink_debug_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_unregister_client(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001030b8 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [pmic_glink_debug_callback, pmic_glink_debug_read_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 001030c0 size=1
// signature: undefined complete(void)
// callers: [pmic_glink_debug_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001030c8 size=1
// signature: undefined mutex_lock(void)
// callers: [pmic_glink_debug_read_regs, pmic_glink_debug_write_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_write @ 001030d0 size=1
// signature: undefined pmic_glink_write(void)
// callers: [pmic_glink_debug_read_regs, pmic_glink_debug_write_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 001030d8 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [pmic_glink_debug_read_regs, pmic_glink_debug_write_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001030e0 size=1
// signature: undefined mutex_unlock(void)
// callers: [pmic_glink_debug_read_regs, pmic_glink_debug_write_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



