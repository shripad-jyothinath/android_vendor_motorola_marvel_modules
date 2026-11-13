// Decompiled by Ghidra 12.2
// Program: qti_amoled_ecm.ko
// Image base: 00100000

//------------------------------------------------------------
// qti_amoled_ecm_probe @ 00100364 size=1384
// signature: undefined qti_amoled_ecm_probe(void)
// callers: []
//------------------------------------------------------------

ulong qti_amoled_ecm_probe(long param_1)

{
  long lVar1;
  undefined8 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  long *plVar7;
  undefined8 uVar8;
  long lVar9;
  char *pcVar10;
  ulong uVar11;
  int iVar12;
  ulong uVar13;
  undefined4 uVar14;
  long lVar15;
  undefined4 local_c0;
  undefined4 local_bc;
  long local_b8 [11];
  
  lVar9 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_b8[10] = *(long *)(lVar9 + 0x638);
  local_c0 = 0;
  plVar7 = (long *)devm_kmalloc(lVar1,0x108,0xdc0);
  if (plVar7 == (long *)0x0) {
    uVar13 = 0xfffffff4;
    goto LAB_00100800;
  }
  uVar8 = *(undefined8 *)(param_1 + 0x70);
  plVar7[1] = lVar1;
  lVar9 = dev_get_regmap(uVar8,0);
  *plVar7 = lVar9;
  if (lVar9 == 0) {
    _dev_err(lVar1,"Failed to get regmap\n");
    uVar13 = 0xffffffea;
    goto LAB_00100800;
  }
  local_bc = 0;
  local_b8[2] = local_b8[2] & 0xffffffff00000000;
  local_b8[0] = 0;
  local_b8[1] = 0;
  uVar3 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),&DAT_00102015,&local_bc,1,0);
  if ((int)uVar3 < 0) {
    uVar13 = (ulong)uVar3;
    _printk(&DAT_00101ee2,"amoled_ecm_parse_dt",uVar13);
LAB_001007ec:
    pcVar10 = "Failed to parse AMOLED ECM rc=%d\n";
  }
  else {
    uVar8 = *(undefined8 *)(param_1 + 0x2f8);
    *(undefined4 *)((long)plVar7 + 0xfc) = local_bc;
    uVar3 = of_property_read_string_helper(uVar8,"nvmem-names",0,0,0);
    uVar13 = (ulong)uVar3;
    if ((int)uVar3 < 0) {
      _printk(&DAT_0010242f,"amoled_ecm_parse_dt");
      goto LAB_001007ec;
    }
    *(uint *)(plVar7 + 0x1f) = uVar3;
    lVar9 = devm_kmalloc(lVar1,uVar13 << 5,0xdc0);
    plVar7[5] = lVar9;
    if (lVar9 == 0) {
LAB_00100734:
      uVar13 = 0xfffffff4;
      goto LAB_001007ec;
    }
    if (uVar3 != 0) {
      uVar13 = 0;
      do {
        scnprintf(local_b8,0x14,"ecm-sdam%d",uVar13);
        lVar15 = plVar7[1];
        iVar4 = of_irq_get_byname(*(undefined8 *)(lVar15 + 0x2e8),local_b8);
        if (iVar4 < 0) {
          _printk(&DAT_00102637,"amoled_ecm_parse_dt",iVar4);
          uVar13 = 0xffffffea;
          goto LAB_001007ec;
        }
        uVar8 = devm_kstrdup(lVar15,local_b8,0xcc0);
        uVar11 = -(uVar13 >> 0x1f) & 0xffffffe000000000 | uVar13 << 5;
        *(undefined8 *)(lVar9 + uVar11 + 0x10) = uVar8;
        if (*(long *)(plVar7[5] + uVar11 + 0x10) == 0) goto LAB_00100734;
        iVar12 = (int)uVar13;
        lVar15 = (long)iVar12 * 0x20;
        *(int *)(plVar7[5] + lVar15 + 0x18) = iVar4;
        scnprintf(local_b8,0x14,"amoled-ecm-sdam%d",uVar13);
        uVar8 = devm_nvmem_device_get(plVar7[1],local_b8);
        *(undefined8 *)(plVar7[5] + lVar15) = uVar8;
        lVar9 = plVar7[5];
        uVar11 = *(ulong *)(lVar9 + lVar15);
        if (0xfffffffffffff000 < uVar11) {
          puVar2 = (undefined8 *)(lVar9 + (long)iVar12 * 0x20);
          if ((int)uVar11 == -0x205) {
            uVar13 = 0xfffffdfb;
            *puVar2 = 0;
            goto LAB_001007ec;
          }
          uVar13 = uVar11 & 0xffffffff;
          _printk(&DAT_00101e5e,"amoled_ecm_parse_dt",uVar11 & 0xffffffff);
          *puVar2 = 0;
          if ((int)uVar11 < 0) goto LAB_001007ec;
          break;
        }
        uVar13 = (ulong)(iVar12 + 1U);
      } while (iVar12 + 1U < *(uint *)(plVar7 + 0x1f));
    }
    uVar3 = regmap_read(*plVar7,*(int *)((long)plVar7 + 0xfc) + 1,&local_c0);
    if (-1 < (int)uVar3) {
      *(char *)(plVar7 + 0x20) = (char)local_c0;
      *(undefined2 *)((long)plVar7 + 0x101) = 0;
      plVar7[0xc] = 0xfffffffe0;
      plVar7[3] = 0;
      plVar7[4] = 0x200000000;
      plVar7[2] = 0;
      plVar7[0xd] = (long)(plVar7 + 0xd);
      plVar7[0xe] = (long)(plVar7 + 0xd);
      plVar7[0xf] = (long)ecm_average_work;
      init_timer_key(plVar7 + 0x12,&delayed_work_timer_fn,0x200000,0,0);
      __mutex_init(plVar7 + 6,"&ecm->sdam_lock",&qti_amoled_ecm_probe___key);
      *(long **)(plVar7[1] + 0x98) = plVar7;
      if ((int)plVar7[0x1f] != 0) {
        uVar3 = 0;
        do {
          lVar15 = (long)(int)uVar3;
          lVar9 = plVar7[5] + lVar15 * 0x20;
          uVar5 = devm_request_threaded_irq
                            (plVar7[1],*(undefined4 *)(lVar9 + 0x18),0,sdam_full_irq_handler,0x2000,
                             *(undefined8 *)(lVar9 + 0x10),plVar7);
          if ((int)uVar5 < 0) {
            uVar13 = (ulong)uVar5;
            _dev_err(lVar1,"Failed to request IRQ(%s), rc=%d\n",
                     *(undefined8 *)(plVar7[5] + lVar15 * 0x20 + 0x10),uVar13);
            goto LAB_00100800;
          }
          uVar14 = 0x6c;
          if (uVar3 != 0) {
            uVar14 = 0x46;
          }
          *(undefined4 *)(plVar7[5] + lVar15 * 0x20 + 8) = uVar14;
          uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint *)(plVar7 + 0x1f));
      }
      uVar13 = devm_hwmon_device_register_with_groups(lVar1,"amoled_ecm",plVar7,&amoled_ecm_groups);
      if ((uVar13 == 0) || (0xfffffffffffff000 < uVar13)) {
        _printk(&DAT_00101ce4,"qti_amoled_ecm_probe",uVar13 & 0xffffffff);
      }
      else {
        uVar8 = *(undefined8 *)(plVar7[1] + 0x2e8);
        iVar4 = of_count_phandle_with_args(uVar8,"display-panels",0);
        if (iVar4 < 1) {
          uVar13 = 0;
        }
        else {
          iVar12 = 0;
          do {
            local_b8[8] = 0;
            local_b8[9] = 0;
            local_b8[6] = 0;
            local_b8[7] = 0;
            local_b8[4] = 0;
            local_b8[5] = 0;
            local_b8[2] = 0;
            local_b8[3] = 0;
            local_b8[0] = 0;
            local_b8[1] = 0;
            iVar6 = __of_parse_phandle_with_args(uVar8,"display-panels",0,0,iVar12,local_b8);
            uVar13 = 0xffffffed;
            if ((iVar6 != 0) || (local_b8[0] == 0)) goto LAB_00100800;
            uVar13 = of_drm_find_panel();
            if (uVar13 < 0xfffffffffffff001) {
              plVar7[0x1d] = uVar13;
              uVar11 = uVar13;
              goto joined_r0x00100700;
            }
            iVar12 = iVar12 + 1;
          } while (iVar4 != iVar12);
          uVar11 = plVar7[0x1d];
joined_r0x00100700:
          if (uVar11 == 0) {
            if ((int)uVar13 == -0x205) {
              uVar13 = 0xfffffdfb;
            }
            else {
              _printk(&DAT_00101c68,"qti_amoled_register_panel_notifier",uVar13 & 0xffffffff);
            }
          }
          else {
            uVar11 = panel_event_notifier_register(1,2,uVar11,panel_event_notifier_callback,plVar7);
            if (uVar11 < 0xfffffffffffff001) {
              uVar13 = 0;
              plVar7[0x1e] = uVar11;
            }
            else {
              _printk(&DAT_00101f91,"qti_amoled_register_panel_notifier",uVar11 & 0xffffffff);
              uVar13 = uVar11 & 0xffffffff;
            }
          }
        }
      }
      goto LAB_00100800;
    }
    uVar13 = (ulong)uVar3;
    pcVar10 = "Failed to read AB revision, rc=%d\n";
  }
  _dev_err(lVar1,pcVar10,uVar13);
LAB_00100800:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_b8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar13 & 0xffffffff;
}



//------------------------------------------------------------
// qti_amoled_ecm_remove @ 001008d0 size=44
// signature: undefined qti_amoled_ecm_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qti_amoled_ecm_remove(long param_1)

{
  if (*(long *)(*(long *)(param_1 + 0xa8) + 0xf0) != 0) {
    panel_event_notifier_unregister();
  }
  return 0;
}



//------------------------------------------------------------
// ecm_average_work @ 00100900 size=200
// signature: undefined ecm_average_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ecm_average_work(long param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  
  mutex_lock(param_1 + -0x30);
  uVar1 = *(uint *)(param_1 + -0x48);
  if ((uVar1 == 0) || (*(ulong *)(param_1 + -0x50) == 0)) {
    iVar2 = ___ratelimit(ecm_average_work__rs,"ecm_average_work");
    if (iVar2 != 0) {
      _printk(&DAT_00102703,"ecm_average_work",*(undefined4 *)(param_1 + -0x48),
              *(undefined8 *)(param_1 + -0x50));
    }
    uVar4 = 0;
  }
  else {
    uVar4 = 0;
    if ((ulong)uVar1 != 0) {
      uVar4 = (undefined2)(*(ulong *)(param_1 + -0x50) / (ulong)uVar1);
    }
  }
  *(undefined2 *)(param_1 + -0x3e) = uVar4;
  *(undefined8 *)(param_1 + -0x50) = 0;
  *(undefined4 *)(param_1 + -0x48) = 0;
  mutex_unlock(param_1 + -0x30);
  if ((*(char *)(param_1 + 0xa2) == '\0') && (*(char *)(param_1 + 0xa1) != '\0')) {
    uVar3 = __msecs_to_jiffies(*(undefined4 *)(param_1 + -0x44));
    queue_delayed_work_on(0x20,_system_wq,param_1,uVar3);
  }
  return;
}



//------------------------------------------------------------
// sdam_full_irq_handler @ 001009cc size=1236
// signature: undefined sdam_full_irq_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 sdam_full_irq_handler(int param_1,long param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  byte bVar5;
  undefined8 uVar6;
  int iVar7;
  undefined *puVar8;
  uint uVar9;
  ulong uVar10;
  int iVar11;
  long lVar12;
  ulong uVar13;
  byte local_78 [4];
  byte local_74 [4];
  byte local_70 [4];
  ushort local_6c [2];
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  local_6c[0] = 0;
  local_70[0] = 0;
  local_74[0] = 0;
  local_78[0] = 0;
  if (*(int *)(param_2 + 0xf8) != 0) {
    lVar12 = 0;
    uVar10 = 0;
    do {
      uVar9 = (uint)uVar10;
      if (*(int *)(*(undefined8 **)(param_2 + 0x28) + (long)(int)uVar9 * 4 + 3) == param_1) {
        if ((int)uVar9 < 0) goto LAB_00100ac0;
        iVar7 = nvmem_device_read(**(undefined8 **)(param_2 + 0x28),0x50,1,local_70);
        uVar6 = _system_wq;
        if (iVar7 < 0) {
          _printk(&DAT_0010214e,"sdam_full_irq_handler",iVar7);
          goto LAB_00100df0;
        }
        uVar3 = *(uint *)(param_2 + 0x24);
        if (1 < uVar3) goto LAB_00100df0;
        if ((local_70[0] >> 2 & 1) != 0) {
          if ((uVar3 & 0xff) == 0) {
            if (*(uint *)(param_2 + 0x18) < 10) {
              iVar7 = ___ratelimit(handle_ecm_abort__rs_28,"handle_ecm_abort");
              if (iVar7 != 0) {
                _printk(&DAT_0010237c,"handle_ecm_abort",*(undefined4 *)(param_2 + 0x18));
              }
              goto LAB_00100b00;
            }
            *(undefined1 *)(param_2 + 0x102) = 1;
            queue_delayed_work_on(0x20,uVar6,param_2 + 0x60,0);
LAB_00100b44:
            iVar7 = amoled_ecm_disable(param_2);
            if (-1 < iVar7) goto LAB_00100b50;
            _printk(&DAT_001024ed,"handle_ecm_abort",iVar7);
          }
          else {
            if ((uVar3 & 0xff) == 1) {
              iVar7 = ___ratelimit(handle_ecm_abort__rs,"handle_ecm_abort");
              if (iVar7 != 0) {
                _printk(&DAT_00101e93,"handle_ecm_abort");
              }
LAB_00100b00:
              *(undefined2 *)(param_2 + 0x22) = 0;
              goto LAB_00100b44;
            }
            iVar7 = ___ratelimit(handle_ecm_abort__rs_30,"handle_ecm_abort");
            if (iVar7 != 0) {
              _printk(&DAT_0010223d,"handle_ecm_abort",uVar3);
            }
            iVar7 = -0x16;
            *(undefined2 *)(param_2 + 0x22) = 0;
          }
          _printk(&DAT_001020c4,"sdam_full_irq_handler",iVar7);
          goto LAB_00100df0;
        }
LAB_00100b50:
        if (uVar9 < 3) {
          iVar7 = nvmem_device_read(**(undefined8 **)(param_2 + 0x28),
                                    *(undefined4 *)(&DAT_00102958 + (long)(int)uVar9 * 4),1,local_74
                                   );
          if (-1 < iVar7) {
            iVar11 = *(int *)(*(long *)(param_2 + 0x28) + lVar12 + 8);
            iVar7 = (uint)local_74[0] - iVar11;
            iVar1 = 0xc1 - iVar11;
            if (-1 < 0xc0 - iVar11) {
              iVar1 = 0xc0 - iVar11;
            }
            uVar9 = iVar7 + 2U;
            if (-1 < iVar7 + 1) {
              uVar9 = iVar7 + 1;
            }
            iVar1 = iVar1 >> 1;
            iVar2 = (int)uVar9 >> 1;
            if ((iVar7 + 2U < 3) || (iVar1 < iVar2)) {
              _printk(&DAT_00102745,"sdam_full_irq_handler",iVar2,iVar1);
              goto LAB_00100df0;
            }
            mutex_lock(param_2 + 0x30);
            iVar7 = nvmem_device_read(**(undefined8 **)(param_2 + 0x28),0x60,1,local_78);
            if (iVar7 < 0) {
              puVar8 = &DAT_00101c10;
              goto LAB_00100ddc;
            }
            bVar5 = (byte)(0x10L << (uVar10 & 0x3f));
            local_78[0] = local_78[0] & (bVar5 ^ 0xff);
            iVar7 = nvmem_device_write(**(undefined8 **)(param_2 + 0x28),0x60,1,local_78);
            if (iVar7 < 0) goto LAB_00100d2c;
            uVar9 = 0xf;
            if (*(char *)(param_2 + 0x100) != '\0') {
              uVar9 = 0x10;
            }
            if (iVar11 < (int)(uint)local_74[0]) {
              uVar13 = 0;
              goto LAB_00100c44;
            }
            uVar13 = 0;
            goto LAB_00100c84;
          }
        }
        else {
          iVar7 = -0x16;
        }
        puVar8 = &DAT_00101dae;
        goto LAB_00100ddc;
      }
      uVar10 = uVar10 + 1;
      lVar12 = lVar12 + 0x20;
    } while (*(int *)(param_2 + 0xf8) != (int)uVar10);
  }
  uVar10 = 0xfffffffe;
LAB_00100ac0:
  _printk(&DAT_00102671,"sdam_full_irq_handler",uVar10 & 0xffffffff);
  goto LAB_00100df0;
  while( true ) {
    iVar11 = iVar11 + 2;
    uVar3 = 0;
    if (uVar9 != 0) {
      uVar3 = local_6c[0] / uVar9;
    }
    uVar13 = uVar13 + uVar3;
    if ((int)(uint)local_74[0] <= iVar11) break;
LAB_00100c44:
    iVar7 = nvmem_device_read(*(undefined8 *)(*(long *)(param_2 + 0x28) + lVar12),iVar11,2,local_6c)
    ;
    if (iVar7 < 0) {
      puVar8 = &DAT_00102103;
      goto LAB_00100ddc;
    }
  }
LAB_00100c84:
  local_78[0] = local_78[0] | bVar5;
  iVar7 = nvmem_device_write(**(undefined8 **)(param_2 + 0x28),0x60,1,local_78);
  if (iVar7 < 0) {
LAB_00100d2c:
    puVar8 = &DAT_00102071;
LAB_00100ddc:
    _printk(puVar8,"sdam_full_irq_handler",iVar7);
  }
  else if (uVar13 == 0) {
    _printk(&DAT_00101e15,"sdam_full_irq_handler",0);
  }
  else {
    uVar4 = 0;
    if ((long)iVar2 != 0) {
      uVar4 = uVar13 / (ulong)(long)iVar2;
    }
    *(ulong *)(param_2 + 0x10) = *(long *)(param_2 + 0x10) + uVar4;
    *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + 1;
    local_6c[0] = CONCAT11(local_6c[0]._1_1_,(char)(8L << (uVar10 & 0x3f)));
    iVar7 = nvmem_device_write(**(undefined8 **)(param_2 + 0x28),0x51,1,local_6c);
    if (iVar7 < 0) {
      puVar8 = &DAT_0010245e;
      goto LAB_00100ddc;
    }
    if ((*(int *)(param_2 + 0x24) == 1) && ((int)(uint)local_74[0] < iVar1)) {
      queue_delayed_work_on(0x20,_system_wq,param_2 + 0x60,0);
    }
  }
  mutex_unlock(param_2 + 0x30);
LAB_00100df0:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// amoled_ecm_disable @ 00100ea0 size=224
// signature: undefined amoled_ecm_disable(void)
// callers: [enable_store, sdam_full_irq_handler, panel_event_notifier_callback]
//------------------------------------------------------------

int amoled_ecm_disable(undefined8 *param_1)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = regmap_write(*param_1,*(int *)((long)param_1 + 0xfc) + 0xa1,0);
  if (iVar1 < 0) {
    puVar2 = &DAT_001024a1;
  }
  else {
    iVar1 = regmap_write(*param_1,*(int *)((long)param_1 + 0xfc) + 0xa0,0);
    if (iVar1 < 0) {
      puVar2 = &DAT_001022fe;
    }
    else {
      iVar1 = nvmem_device_write(*(undefined8 *)param_1[5],0x61,2,(long)param_1 + 0x22);
      if (-1 < iVar1) {
        cancel_delayed_work(param_1 + 0xc);
        *(undefined2 *)((long)param_1 + 0x22) = 0;
        param_1[2] = 0;
        *(undefined4 *)(param_1 + 3) = 0;
        *(undefined4 *)((long)param_1 + 0x24) = 2;
        *(undefined2 *)((long)param_1 + 0x101) = 0;
        return iVar1;
      }
      puVar2 = &DAT_0010226f;
    }
  }
  _printk(puVar2,"amoled_ecm_disable",iVar1);
  return iVar1;
}



//------------------------------------------------------------
// enable_show @ 00100f84 size=60
// signature: undefined enable_show(void)
// callers: []
//------------------------------------------------------------

long enable_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00101ecc,*(undefined1 *)(*(long *)(param_1 + 0x98) + 0x101))
  ;
  return (long)iVar1;
}



//------------------------------------------------------------
// enable_store @ 00100fc4 size=300
// signature: undefined enable_store(void)
// callers: []
//------------------------------------------------------------

long enable_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  char local_3c [4];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_3c[0] = '\0';
  iVar2 = kstrtobool(param_3,local_3c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else if (*(char *)(lVar3 + 0x101) == local_3c[0]) {
    pcVar1 = "disabled";
    if (local_3c[0] != '\0') {
      pcVar1 = "enabled";
    }
    _printk(&DAT_0010232e,"enable_store",pcVar1);
    param_4 = -0x16;
  }
  else if (local_3c[0] == '\0') {
    iVar2 = amoled_ecm_disable(lVar3);
    if (iVar2 < 0) {
      _printk(&DAT_001024ed,"enable_store",iVar2);
      param_4 = (long)iVar2;
    }
    else {
      *(undefined2 *)(lVar3 + 0x20) = 0;
      *(undefined4 *)(lVar3 + 0x1c) = 0;
    }
  }
  else {
    iVar2 = amoled_ecm_enable(lVar3);
    if (iVar2 < 0) {
      _printk(&DAT_001025b1,"enable_store",iVar2);
      param_4 = (long)iVar2;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// amoled_ecm_enable @ 001010f0 size=1160
// signature: undefined amoled_ecm_enable(void)
// callers: [enable_store, panel_event_notifier_callback]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int amoled_ecm_enable(undefined8 *param_1)

{
  ulong uVar1;
  undefined1 uVar2;
  long lVar3;
  int iVar4;
  undefined8 uVar5;
  undefined *puVar6;
  undefined4 uVar7;
  ulong uVar8;
  ulong uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  ulong uVar13;
  uint uVar14;
  uint uVar15;
  undefined1 *puVar16;
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  if (*(short *)(param_1 + 4) == 0) {
    if (*(int *)((long)param_1 + 0x1c) == 0) {
      iVar4 = -0x16;
      goto LAB_001014a4;
    }
    uVar7 = 0;
LAB_00101150:
    *(undefined4 *)((long)param_1 + 0x24) = uVar7;
    if (1 < *(byte *)(param_1 + 0x20)) {
      _printk(&DAT_00102524,"amoled_ecm_enable");
      iVar4 = -0x13;
      goto LAB_001014a4;
    }
    puVar16 = &ecm_reset_config;
    iVar4 = nvmem_device_write(*(undefined8 *)param_1[5],ecm_reset_config,1,&DAT_00101bd1);
    if (iVar4 < 0) {
LAB_0010130c:
      uVar2 = *puVar16;
      puVar6 = &DAT_00101d38;
LAB_0010131c:
      _printk(puVar6,"ecm_reset_sdam_config",uVar2,iVar4);
    }
    else {
      puVar16 = &DAT_00101bd2;
      iVar4 = nvmem_device_write(*(undefined8 *)param_1[5],DAT_00101bd2,1,&DAT_00101bd3);
      if (iVar4 < 0) goto LAB_0010130c;
      puVar16 = &DAT_00101bd4;
      iVar4 = nvmem_device_write(*(undefined8 *)param_1[5],DAT_00101bd4,1,&DAT_00101bd5);
      if (iVar4 < 0) goto LAB_0010130c;
      puVar16 = &DAT_00101bd6;
      iVar4 = nvmem_device_write(*(undefined8 *)param_1[5],DAT_00101bd6,1,&DAT_00101bd7);
      if (iVar4 < 0) goto LAB_0010130c;
      puVar16 = &DAT_00101bd8;
      iVar4 = nvmem_device_write(*(undefined8 *)param_1[5],DAT_00101bd8,1,&DAT_00101bd9);
      if (iVar4 < 0) goto LAB_0010130c;
      puVar16 = &DAT_00101bda;
      iVar4 = nvmem_device_write(*(undefined8 *)param_1[5],DAT_00101bda,1,&DAT_00101bdb);
      if (iVar4 < 0) goto LAB_0010130c;
      puVar16 = &DAT_00101bdc;
      iVar4 = nvmem_device_write(*(undefined8 *)param_1[5],DAT_00101bdc,1,&DAT_00101bdd);
      if (iVar4 < 0) goto LAB_0010130c;
      puVar16 = &DAT_00101bde;
      iVar4 = nvmem_device_write(*(undefined8 *)param_1[5],DAT_00101bde,1,&DAT_00101bdf);
      if (iVar4 < 0) goto LAB_0010130c;
      puVar16 = &DAT_00101be0;
      iVar4 = nvmem_device_write(*(undefined8 *)param_1[5],DAT_00101be0,1,&DAT_00101be1);
      if (iVar4 < 0) goto LAB_0010130c;
      puVar16 = &DAT_00101be2;
      iVar4 = nvmem_device_write(*(undefined8 *)param_1[5],DAT_00101be2,1,&DAT_00101be3);
      if (iVar4 < 0) goto LAB_0010130c;
      puVar16 = &DAT_00101be4;
      iVar4 = nvmem_device_write(*(undefined8 *)param_1[5],DAT_00101be4,1,&DAT_00101be5);
      if (iVar4 < 0) goto LAB_0010130c;
      uVar12 = *(uint *)(param_1 + 0x1f);
      uVar8 = (ulong)uVar12;
      if (uVar12 == 0) {
        local_40[0] = 0;
        local_3c[0] = 0;
      }
      else {
        if (uVar12 == 1) {
          uVar9 = 0;
          uVar11 = 0;
          uVar14 = 0;
        }
        else {
          uVar13 = 0;
          uVar12 = 0;
          uVar11 = 0;
          uVar10 = 0;
          uVar14 = 0;
          uVar9 = uVar8 & 0xfffffffe;
          do {
            uVar1 = uVar13 + 1;
            uVar15 = (uint)(1L << (uVar13 & 0x3f));
            uVar12 = uVar12 | uVar15;
            uVar10 = uVar10 | uVar15;
            uVar13 = uVar13 + 2;
            uVar15 = (uint)(1L << (uVar1 & 0x3f));
            uVar11 = uVar11 | uVar15;
            uVar14 = uVar14 | uVar15;
          } while (uVar13 != uVar9);
          uVar14 = uVar14 | uVar10;
          local_40[0] = (undefined1)uVar14;
          uVar11 = uVar11 | uVar12;
          local_3c[0] = (undefined1)uVar11;
          if (uVar9 == uVar8) goto LAB_001013cc;
        }
        do {
          uVar13 = uVar9 & 0x3f;
          uVar9 = uVar9 + 1;
          uVar12 = (uint)(1L << uVar13);
          uVar11 = uVar11 | uVar12;
          local_3c[0] = (undefined1)uVar11;
          uVar14 = uVar14 | uVar12;
          local_40[0] = (undefined1)uVar14;
        } while (uVar8 != uVar9);
      }
LAB_001013cc:
      iVar4 = nvmem_device_write(*(undefined8 *)param_1[5],0x5f,1,local_3c);
      if (iVar4 < 0) {
        puVar6 = &DAT_00102574;
        uVar2 = local_3c[0];
        goto LAB_0010131c;
      }
      iVar4 = nvmem_device_write(*(undefined8 *)param_1[5],0x60,1,local_40);
      if (-1 < iVar4) {
        usleep_range_state(10000,12000,2);
        iVar4 = nvmem_device_write(*(undefined8 *)param_1[5],0x54,1,(int *)((long)param_1 + 0x24));
        if (iVar4 < 0) {
          puVar6 = &DAT_001025e7;
        }
        else {
          iVar4 = regmap_write(*param_1,*(int *)((long)param_1 + 0xfc) + 0xa0,0x80);
          if (iVar4 < 0) {
            puVar6 = &DAT_00101de2;
          }
          else {
            iVar4 = regmap_write(*param_1,*(int *)((long)param_1 + 0xfc) + 0xa1,0x80);
            if (-1 < iVar4) {
              if (*(int *)((long)param_1 + 0x24) == 0) {
                uVar5 = __msecs_to_jiffies(*(undefined4 *)((long)param_1 + 0x1c));
                queue_delayed_work_on(0x20,_system_wq,param_1 + 0xc,uVar5);
              }
              *(undefined1 *)((long)param_1 + 0x101) = 1;
              goto LAB_001014a4;
            }
            puVar6 = &DAT_001023bf;
          }
        }
        goto LAB_00101334;
      }
      _printk(&DAT_00102020,"ecm_reset_sdam_config",local_40[0],iVar4);
      usleep_range_state(10000,12000,2);
    }
    puVar6 = &DAT_001022ad;
  }
  else {
    iVar4 = nvmem_device_write(*(undefined8 *)param_1[5],0x55,2);
    if (-1 < iVar4) {
      uVar7 = 1;
      goto LAB_00101150;
    }
    puVar6 = &DAT_001026c5;
  }
LAB_00101334:
  _printk(puVar6,"amoled_ecm_enable",iVar4);
LAB_001014a4:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// frames_show @ 0010157c size=60
// signature: undefined frames_show(void)
// callers: []
//------------------------------------------------------------

long frames_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00101e11,*(undefined2 *)(*(long *)(param_1 + 0x98) + 0x20));
  return (long)iVar1;
}



//------------------------------------------------------------
// frames_store @ 001015bc size=168
// signature: undefined frames_store(void)
// callers: []
//------------------------------------------------------------

void frames_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  short local_2c [2];
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_2c[0] = 0;
  if (*(char *)(lVar3 + 0x101) == '\0') {
    iVar1 = kstrtou16(param_3,0,local_2c);
    uVar2 = 0xffffffffffffffea;
    if ((-1 < iVar1) && (local_2c[0] != 0)) {
      *(short *)(lVar3 + 0x20) = local_2c[0];
      uVar2 = param_4;
    }
  }
  else {
    _printk(&DAT_00101f10,"frames_store");
    uVar2 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// time_period_show @ 00101668 size=60
// signature: undefined time_period_show(void)
// callers: []
//------------------------------------------------------------

long time_period_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00101e11,*(undefined4 *)(*(long *)(param_1 + 0x98) + 0x1c));
  return (long)iVar1;
}



//------------------------------------------------------------
// time_period_store @ 001016a8 size=168
// signature: undefined time_period_store(void)
// callers: []
//------------------------------------------------------------

void time_period_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  int local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_2c = 0;
  if (*(char *)(lVar3 + 0x101) == '\0') {
    iVar1 = kstrtouint(param_3,0,&local_2c);
    uVar2 = 0xffffffffffffffea;
    if ((-1 < iVar1) && (local_2c != 0)) {
      *(int *)(lVar3 + 0x1c) = local_2c;
      uVar2 = param_4;
    }
  }
  else {
    _printk(&DAT_0010219f,"time_period_store");
    uVar2 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// avg_current_show @ 00101754 size=60
// signature: undefined avg_current_show(void)
// callers: []
//------------------------------------------------------------

long avg_current_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00101e11,*(undefined2 *)(*(long *)(param_1 + 0x98) + 0x22));
  return (long)iVar1;
}



//------------------------------------------------------------
// panel_event_notifier_callback @ 00101794 size=184
// signature: undefined panel_event_notifier_callback(void)
// callers: []
//------------------------------------------------------------

void panel_event_notifier_callback(undefined8 param_1,int *param_2,long param_3)

{
  int iVar1;
  undefined *puVar2;
  
  if (param_2 == (int *)0x0) {
    _printk(&DAT_001023f6,"panel_event_notifier_callback");
    return;
  }
  if (*param_2 == 2) {
    if (*(char *)(param_3 + 0x103) == '\0') {
      return;
    }
    iVar1 = amoled_ecm_enable(param_3);
    if (-1 < iVar1) {
      *(undefined1 *)(param_3 + 0x103) = 0;
      return;
    }
    puVar2 = &DAT_00101c9e;
  }
  else {
    if (*param_2 != 1) {
      return;
    }
    if (*(char *)(param_3 + 0x101) == '\0') {
      return;
    }
    iVar1 = amoled_ecm_disable(param_3);
    if (-1 < iVar1) {
      *(undefined1 *)(param_3 + 0x103) = 1;
      return;
    }
    puVar2 = &DAT_00101fd3;
  }
  _printk(puVar2,"panel_event_notifier_callback",iVar1);
  return;
}



//------------------------------------------------------------
// init_module @ 00101850 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qti_amoled_ecm_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101880 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qti_amoled_ecm_driver);
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
// callers: [qti_amoled_ecm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00104018 size=1
// signature: undefined dev_get_regmap(void)
// callers: [qti_amoled_ecm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00104020 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qti_amoled_ecm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 00104028 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [qti_amoled_ecm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00104030 size=1
// signature: undefined scnprintf(void)
// callers: [enable_show, avg_current_show, qti_amoled_ecm_probe, time_period_show, frames_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_irq_get_byname @ 00104038 size=1
// signature: undefined of_irq_get_byname(void)
// callers: [qti_amoled_ecm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_irq_get_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kstrdup @ 00104040 size=1
// signature: undefined devm_kstrdup(void)
// callers: [qti_amoled_ecm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_nvmem_device_get @ 00104048 size=1
// signature: undefined devm_nvmem_device_get(void)
// callers: [qti_amoled_ecm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_nvmem_device_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00104050 size=1
// signature: undefined regmap_read(void)
// callers: [qti_amoled_ecm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00104060 size=1
// signature: undefined init_timer_key(void)
// callers: [qti_amoled_ecm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00104068 size=1
// signature: undefined __mutex_init(void)
// callers: [qti_amoled_ecm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00104070 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [qti_amoled_ecm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_hwmon_device_register_with_groups @ 00104078 size=1
// signature: undefined devm_hwmon_device_register_with_groups(void)
// callers: [qti_amoled_ecm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_hwmon_device_register_with_groups(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_count_phandle_with_args @ 00104080 size=1
// signature: undefined of_count_phandle_with_args(void)
// callers: [qti_amoled_ecm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_count_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00104088 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qti_amoled_ecm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_drm_find_panel @ 00104090 size=1
// signature: undefined of_drm_find_panel(void)
// callers: [qti_amoled_ecm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_drm_find_panel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panel_event_notifier_register @ 00104098 size=1
// signature: undefined panel_event_notifier_register(void)
// callers: [qti_amoled_ecm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panel_event_notifier_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001040a0 size=1
// signature: undefined _dev_err(void)
// callers: [qti_amoled_ecm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001040a8 size=1
// signature: undefined _printk(void)
// callers: [time_period_store, enable_store, ecm_average_work, amoled_ecm_disable, frames_store, qti_amoled_ecm_probe, amoled_ecm_enable, sdam_full_irq_handler, panel_event_notifier_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001040b0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [time_period_store, enable_store, frames_store, qti_amoled_ecm_probe, amoled_ecm_enable, sdam_full_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panel_event_notifier_unregister @ 001040b8 size=1
// signature: undefined panel_event_notifier_unregister(void)
// callers: [qti_amoled_ecm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panel_event_notifier_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001040c0 size=1
// signature: undefined mutex_lock(void)
// callers: [ecm_average_work, sdam_full_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 001040c8 size=1
// signature: undefined ___ratelimit(void)
// callers: [ecm_average_work, sdam_full_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001040d0 size=1
// signature: undefined mutex_unlock(void)
// callers: [ecm_average_work, sdam_full_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 001040d8 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [ecm_average_work, amoled_ecm_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 001040e8 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [ecm_average_work, amoled_ecm_enable, sdam_full_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_device_read @ 001040f0 size=1
// signature: undefined nvmem_device_read(void)
// callers: [sdam_full_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_device_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_device_write @ 001040f8 size=1
// signature: undefined nvmem_device_write(void)
// callers: [amoled_ecm_disable, amoled_ecm_enable, sdam_full_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_device_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 00104100 size=1
// signature: undefined regmap_write(void)
// callers: [amoled_ecm_disable, amoled_ecm_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work @ 00104108 size=1
// signature: undefined cancel_delayed_work(void)
// callers: [amoled_ecm_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtobool @ 00104110 size=1
// signature: undefined kstrtobool(void)
// callers: [enable_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtobool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00104118 size=1
// signature: undefined usleep_range_state(void)
// callers: [amoled_ecm_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtou16 @ 00104120 size=1
// signature: undefined kstrtou16(void)
// callers: [frames_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtou16(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00104128 size=1
// signature: undefined kstrtouint(void)
// callers: [time_period_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



