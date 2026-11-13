// Decompiled by Ghidra 12.2
// Program: hwmon.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_hwmon_attr_show @ 00100914 size=124
// signature: undefined __traceiter_hwmon_attr_show(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_hwmon_attr_show
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00102f68;
  plVar2 = DAT_00102f68;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x26ce444b) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10096c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_hwmon_attr_store @ 00100994 size=124
// signature: undefined __traceiter_hwmon_attr_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_hwmon_attr_store
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00102fb0;
  plVar2 = _DAT_00102fb0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x26ce444b) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1009ec);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_hwmon_attr_show_string @ 00100a14 size=124
// signature: undefined __traceiter_hwmon_attr_show_string(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_hwmon_attr_show_string
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00102ff8;
  plVar2 = _DAT_00102ff8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x224269c7) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100a6c);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_hwmon_attr_class @ 00100a94 size=252
// signature: undefined trace_event_raw_event_hwmon_attr_class(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_hwmon_attr_class
               (long param_1,undefined4 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_3 != (char *)0x0) {
      __s = param_3;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_78,param_1,(long)iVar1 + 0x18);
    if (lVar3 != 0) {
      *(undefined4 *)(lVar3 + 8) = param_2;
      *(uint *)(lVar3 + 0xc) = iVar1 * 0x10000 | 0x18;
      strcpy((char *)(lVar3 + 0x18),__s);
      *(undefined8 *)(lVar3 + 0x10) = param_4;
      trace_event_buffer_commit(&local_78);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_hwmon_attr_class @ 00100b94 size=340
// signature: undefined perf_trace_hwmon_attr_class(void)
// callers: []
//------------------------------------------------------------

void perf_trace_hwmon_attr_class(long param_1,undefined4 param_2,char *param_3,undefined8 param_4)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  __s = "(null)";
  if (param_3 != (char *)0x0) {
    __s = param_3;
  }
  local_68 = *(long *)(lVar5 + 0x638);
  local_70 = 0;
  local_74 = 0;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar4 + 0x24U & 0xfffffff8) - 4;
    lVar5 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar5 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      *(ulong *)(local_70 + 0x100) = uVar2;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(undefined4 *)(lVar5 + 8) = param_2;
      *(int *)(lVar5 + 0xc) = (int)sVar4 * 0x10000 + 0x10018;
      strcpy((char *)(lVar5 + 0x18),__s);
      *(undefined8 *)(lVar5 + 0x10) = param_4;
      perf_trace_run_bpf_submit(lVar5,iVar3,local_74,param_1,1,local_70,plVar1,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_hwmon_attr_show_string @ 00100cec size=308
// signature: undefined trace_event_raw_event_hwmon_attr_show_string(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_hwmon_attr_show_string
               (long param_1,undefined4 param_2,char *param_3,char *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *__s;
  char *__s_00;
  size_t sVar4;
  size_t sVar5;
  long lVar6;
  ulong uVar7;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar7 = __trace_trigger_soft_disabled(param_1), (uVar7 & 1) == 0)) {
    __s = "(null)";
    if (param_3 != (char *)0x0) {
      __s = param_3;
    }
    sVar4 = strlen(__s);
    __s_00 = "(null)";
    if (param_4 != (char *)0x0) {
      __s_00 = param_4;
    }
    iVar1 = (int)sVar4 + 1;
    sVar5 = strlen(__s_00);
    iVar2 = (int)sVar5 + 1;
    lVar6 = trace_event_buffer_reserve(&local_88,param_1,(long)(iVar2 + iVar1) + 0x14);
    if (lVar6 != 0) {
      uVar3 = (int)sVar4 + 0x15;
      *(undefined4 *)(lVar6 + 8) = param_2;
      *(uint *)(lVar6 + 0xc) = iVar1 * 0x10000 | 0x14;
      *(uint *)(lVar6 + 0x10) = uVar3 | iVar2 * 0x10000;
      strcpy((char *)(lVar6 + 0x14),__s);
      strcpy((char *)(lVar6 + (ulong)(uVar3 & 0xffff)),__s_00);
      trace_event_buffer_commit(&local_88);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_hwmon_attr_show_string @ 00100e24 size=388
// signature: undefined perf_trace_hwmon_attr_show_string(void)
// callers: []
//------------------------------------------------------------

void perf_trace_hwmon_attr_show_string(long param_1,undefined4 param_2,char *param_3,char *param_4)

{
  int iVar1;
  long *plVar2;
  char *__s;
  char *__s_00;
  ulong uVar3;
  int iVar4;
  size_t sVar5;
  size_t sVar6;
  long lVar7;
  int iVar8;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar7 = sp_el0;
  __s = "(null)";
  if (param_3 != (char *)0x0) {
    __s = param_3;
  }
  local_68 = *(long *)(lVar7 + 0x638);
  local_70 = 0;
  local_74 = 0;
  sVar5 = strlen(__s);
  __s_00 = "(null)";
  if (param_4 != (char *)0x0) {
    __s_00 = param_4;
  }
  sVar6 = strlen(__s_00);
  lVar7 = tpidr_el1;
  plVar2 = (long *)(lVar7 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = (int)sVar6 + 1;
    iVar8 = (int)sVar5;
    iVar4 = (iVar8 + iVar1 + 0x20U & 0xfffffff8) - 4;
    lVar7 = perf_trace_buf_alloc(iVar4,&local_70,&local_74);
    if (lVar7 != 0) {
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      *(ulong *)(local_70 + 0x100) = uVar3;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(undefined4 *)(lVar7 + 8) = param_2;
      *(int *)(lVar7 + 0xc) = iVar8 * 0x10000 + 0x10014;
      *(uint *)(lVar7 + 0x10) = iVar8 + 0x15U | iVar1 * 0x10000;
      strcpy((char *)(lVar7 + 0x14),__s);
      strcpy((char *)(lVar7 + (ulong)(iVar8 + 0x15U & 0xffff)),__s_00);
      perf_trace_run_bpf_submit(lVar7,iVar4,local_74,param_1,1,local_70,plVar2,0);
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_hwmon_attr_class @ 00100fac size=32
// signature: undefined __bpf_trace_hwmon_attr_class(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_hwmon_attr_class(undefined8 param_1,undefined4 param_2)

{
  bpf_trace_run3(param_1,param_2);
  return;
}



//------------------------------------------------------------
// __bpf_trace_hwmon_attr_show_string @ 00100fd0 size=32
// signature: undefined __bpf_trace_hwmon_attr_show_string(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_hwmon_attr_show_string(undefined8 param_1,undefined4 param_2)

{
  bpf_trace_run3(param_1,param_2);
  return;
}



//------------------------------------------------------------
// hwmon_notify_event @ 00100ff4 size=336
// signature: undefined hwmon_notify_event(void)
// callers: []
//------------------------------------------------------------

void hwmon_notify_event(long param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined5 uStack_48;
  undefined3 local_43;
  undefined5 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_90 = &local_60;
  uStack_40 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_43 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  uStack_88 = 0;
  if ((param_2 < 10) && (param_3 < *(uint *)(&__templates_size + (ulong)param_2 * 4))) {
    if (9 < param_2) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x101144);
      (*pcVar3)();
    }
    iVar1 = param_4;
    if (param_2 != 9 && param_2 != 2) {
      iVar1 = param_4 + 1;
    }
    scnprintf(&local_80,0x20,*(undefined8 *)((&__templates)[param_2] + (ulong)param_3 * 8),iVar1);
    scnprintf(&local_60,0x25,"NAME=%s",&local_80);
    sysfs_notify(param_1,0,&local_80);
    kobject_uevent_env(param_1,2,&local_90);
    if (param_2 == 1) {
      for (puVar5 = *(undefined8 **)(param_1 + 0x398); puVar5 != (undefined8 *)(param_1 + 0x398);
          puVar5 = (undefined8 *)*puVar5) {
        if (*(int *)(puVar5 + 3) == param_4) {
          thermal_zone_device_update(puVar5[4],0);
        }
      }
    }
    uVar4 = 0;
  }
  else {
    uVar4 = 0xffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// hwmon_device_register_with_groups @ 00101148 size=48
// signature: undefined hwmon_device_register_with_groups(void)
// callers: []
//------------------------------------------------------------

undefined8 hwmon_device_register_with_groups(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    return 0xffffffffffffffea;
  }
  uVar1 = __hwmon_device_register();
  return uVar1;
}



//------------------------------------------------------------
// __hwmon_device_register @ 00101178 size=1804
// signature: undefined __hwmon_device_register(void)
// callers: [hwmon_device_register_with_info, devm_hwmon_device_register_with_info, hwmon_device_register_for_thermal, hwmon_device_register, hwmon_device_register_with_groups, devm_hwmon_device_register_with_groups]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
__hwmon_device_register(long param_1,char *param_2,undefined8 param_3,long *param_4,long *param_5)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  bool bVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  undefined8 *puVar11;
  long lVar12;
  ulong uVar13;
  long *plVar14;
  undefined8 *puVar15;
  undefined *puVar16;
  ulong uVar17;
  uint *puVar18;
  int iVar19;
  undefined1 *puVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  undefined8 *puVar24;
  uint uVar25;
  int local_cc;
  int local_bc;
  undefined8 local_70;
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  local_70 = 0;
  if ((param_2 != (char *)0x0) &&
     ((*param_2 == '\0' || (pcVar10 = strpbrk(param_2,"-* \t\n"), pcVar10 != (char *)0x0)))) {
    _dev_warn(param_1,"hwmon: \'%s\' is not a valid name attribute, please fix\n",param_2);
  }
  iVar6 = ida_alloc_range(hwmon_ida,0,0xffffffff,0xcc0);
  if (iVar6 < 0) {
    puVar15 = (undefined8 *)(long)iVar6;
    goto LAB_001017bc;
  }
  puVar11 = (undefined8 *)kmalloc_trace(_device_register,0xdc0,1000);
  if (puVar11 == (undefined8 *)0x0) {
    iVar9 = -0xc;
  }
  else if (param_4 == (long *)0x0) {
LAB_00101690:
    puVar11[0x66] = param_5;
    if (param_1 == 0) {
      lVar12 = 0;
      *puVar11 = param_2;
      puVar11[0xe] = 0;
      puVar11[0x65] = &hwmon_class;
    }
    else {
      uVar13 = device_property_present(param_1,"label");
      if ((uVar13 & 1) != 0) {
        uVar8 = device_property_read_string(param_1,"label",&local_70);
        if ((int)uVar8 < 0) {
          plVar14 = (long *)(ulong)uVar8;
          goto LAB_00101708;
        }
        lVar12 = kstrdup(local_70,0xcc0);
        puVar11[1] = lVar12;
        if (lVar12 == 0) goto LAB_00101704;
      }
      *puVar11 = param_2;
      puVar11[0xe] = param_1;
      puVar11[0x65] = &hwmon_class;
      do {
        lVar12 = *(long *)(param_1 + 0x2e8);
        if (lVar12 != 0) goto LAB_00101768;
        param_1 = *(long *)(param_1 + 0x60);
      } while (param_1 != 0);
      lVar12 = 0;
    }
LAB_00101768:
    puVar15 = puVar11 + 2;
    puVar11[0x5f] = lVar12;
    puVar11[0x74] = param_4;
    puVar11[0x15] = param_3;
    dev_set_name(puVar15,"hwmon%d",iVar6);
    iVar9 = device_register(puVar15);
    if (iVar9 == 0) {
      puVar11[0x75] = puVar11 + 0x75;
      puVar11[0x76] = puVar11 + 0x75;
      if ((((param_4 == (long *)0x0) || (puVar11[0x5f] == 0)) || (*(long *)(*param_4 + 8) == 0)) ||
         (((**(int **)param_4[1] != 0 || ((**(byte **)(*(int **)param_4[1] + 2) >> 4 & 1) == 0)) ||
          (iVar9 = hwmon_thermal_register_sensors(puVar15), iVar9 == 0)))) goto LAB_001017bc;
      device_unregister(puVar15);
    }
    else {
      put_device(puVar15);
    }
  }
  else {
    if ((param_5 == (long *)0x0) || (*param_5 == 0)) {
      uVar13 = 0x10;
LAB_00101260:
      lVar12 = __kmalloc(uVar13,0xdc0);
      puVar11[0x7c] = lVar12;
      if (lVar12 == 0) {
LAB_00101704:
        plVar14 = (long *)0xfffffff4;
      }
      else {
        plVar14 = (long *)param_4[1];
        lVar12 = *plVar14;
        if (lVar12 != 0) {
          iVar19 = 0;
          iVar9 = 0;
          do {
            if (**(int **)(lVar12 + 8) == 0) {
              iVar22 = 0;
            }
            else {
              iVar22 = 0;
              iVar23 = 1;
              do {
                iVar7 = __sw_hweight32();
                iVar22 = iVar7 + iVar22;
                lVar1 = (long)iVar23;
                iVar23 = iVar23 + 1;
              } while (*(int *)(*(long *)(lVar12 + 8) + lVar1 * 4) != 0);
              plVar14 = (long *)param_4[1];
            }
            iVar9 = iVar9 + 1;
            iVar19 = iVar22 + iVar19;
            lVar12 = plVar14[iVar9];
          } while (lVar12 != 0);
          if (iVar19 != 0) {
            uVar8 = iVar19 + 1;
            if (((int)uVar8 < 0) ||
               (plVar14 = (long *)__kmalloc(-(ulong)(uVar8 >> 0x1f) & 0xfffffff800000000 |
                                            (ulong)uVar8 << 3,0xdc0), plVar14 == (long *)0x0)) {
              plVar14 = (long *)0xfffffffffffffff4;
            }
            else {
              puVar15 = (undefined8 *)param_4[1];
              puVar18 = (uint *)*puVar15;
              if (puVar18 != (uint *)0x0) {
                local_bc = 0;
                local_cc = 0;
                do {
                  uVar8 = *puVar18;
                  if (9 < uVar8) {
                    iVar9 = -0x16;
                    lVar12 = *plVar14;
joined_r0x00101864:
                    if (lVar12 != 0) {
                      iVar19 = 1;
                      do {
                        kfree();
                        lVar12 = (long)iVar19;
                        iVar19 = iVar19 + 1;
                      } while (plVar14[lVar12] != 0);
                    }
                    kfree(plVar14);
                    plVar14 = (long *)(long)iVar9;
                    break;
                  }
                  uVar21 = **(uint **)(puVar18 + 2);
                  if (uVar21 == 0) {
                    iVar9 = 0;
                  }
                  else {
                    iVar9 = 0;
                    iVar19 = 0;
                    puVar16 = (&__templates)[uVar8];
                    uVar8 = *(uint *)(&__templates_size + (ulong)uVar8 * 4);
                    puVar15 = (undefined8 *)*param_4;
                    do {
                      do {
                        uVar25 = (uVar21 & 0xaaaaaaaa) >> 1 | (uVar21 & 0x55555555) << 1;
                        uVar25 = (uVar25 & 0xcccccccc) >> 2 | (uVar25 & 0x33333333) << 2;
                        uVar25 = (uVar25 & 0xf0f0f0f0) >> 4 | (uVar25 & 0xf0f0f0f) << 4;
                        uVar25 = (uVar25 & 0xff00ff00) >> 8 | (uVar25 & 0xff00ff) << 8;
                        lVar12 = LZCOUNT(uVar25 >> 0x10 | uVar25 << 0x10);
                        uVar25 = (uint)lVar12;
                        if (uVar8 <= uVar25) {
                          iVar9 = -0x16;
                          goto LAB_00101614;
                        }
                        uVar2 = *puVar18;
                        if (((((uVar25 == 0x15) && (uVar2 == 1)) ||
                             ((uVar25 == 10 && ((uVar2 & 0xfffffffe) == 2)))) ||
                            ((uVar25 == 0x16 && (uVar2 == 4)))) ||
                           ((uVar25 == 2 && (uVar2 - 5 < 2)))) {
                          bVar4 = true;
                        }
                        else {
                          bVar4 = uVar25 == 2 && uVar2 == 7;
                        }
                        puVar20 = *(undefined1 **)(puVar16 + lVar12 * 8);
                        if (puVar20 != (undefined1 *)0x0) {
                          if (*(int *)((code *)*puVar15 + -4) != 0x1b984032) {
                    /* WARNING: Does not return */
                            pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x101448);
                            (*pcVar3)();
                          }
                          uVar5 = (*(code *)*puVar15)(param_3,uVar2,lVar12);
                          if (uVar5 != 0) {
                            if ((uVar5 & 0x124) == 0) {
LAB_00101488:
                              if (((uVar5 & 0x92) != 0) && (puVar15[3] == 0)) goto LAB_00101594;
                              puVar24 = (undefined8 *)
                                        kmalloc_trace(_device_property_read_string,0xdc0,0x58);
                              if (puVar24 == (undefined8 *)0x0) {
                                puVar24 = (undefined8 *)0xfffffffffffffff4;
                              }
                              else {
                                if (uVar2 != 0) {
                                  iVar22 = iVar19;
                                  if (uVar2 != 9 && uVar2 != 2) {
                                    iVar22 = iVar19 + 1;
                                  }
                                  scnprintf((undefined1 *)((long)puVar24 + 0x34),0x20,puVar20,iVar22
                                           );
                                  puVar20 = (undefined1 *)((long)puVar24 + 0x34);
                                }
                                *(uint *)(puVar24 + 5) = uVar2;
                                *(uint *)((long)puVar24 + 0x2c) = uVar25;
                                *(int *)(puVar24 + 6) = iVar19;
                                pcVar3 = hwmon_attr_show_string;
                                if (!bVar4) {
                                  pcVar3 = hwmon_attr_show;
                                }
                                *puVar24 = puVar20;
                                *(ushort *)(puVar24 + 1) = uVar5;
                                puVar24[2] = pcVar3;
                                puVar24[3] = hwmon_attr_store;
                                puVar24[4] = puVar15;
                                if (puVar24 < (undefined8 *)0xfffffffffffff001) {
                                  plVar14[(long)local_bc + (long)iVar9] = (long)puVar24;
                                  iVar9 = iVar9 + 1;
                                  goto LAB_00101398;
                                }
                              }
                            }
                            else {
                              if (bVar4) {
                                lVar12 = puVar15[2];
                              }
                              else {
                                lVar12 = puVar15[1];
                              }
                              if (lVar12 != 0) goto LAB_00101488;
LAB_00101594:
                              puVar24 = (undefined8 *)&DAT_ffffffffffffffea;
                            }
                            iVar9 = (int)puVar24;
                            goto LAB_001015ac;
                          }
                        }
LAB_00101398:
                        uVar21 = uVar21 & (1 << (ulong)(uVar25 & 0x1f) ^ 0xffffffffU);
                      } while (uVar21 != 0);
                      iVar19 = iVar19 + 1;
                      uVar21 = *(uint *)(*(long *)(puVar18 + 2) + (long)iVar19 * 4);
                    } while (uVar21 != 0);
LAB_001015ac:
                    if (iVar9 < 0) {
LAB_00101614:
                      lVar12 = *plVar14;
                      goto joined_r0x00101864;
                    }
                    puVar15 = (undefined8 *)param_4[1];
                  }
                  local_cc = local_cc + 1;
                  puVar18 = (uint *)puVar15[local_cc];
                  local_bc = iVar9 + local_bc;
                } while (puVar18 != (uint *)0x0);
              }
              if (plVar14 < (long *)0xfffffffffffff001) {
                puVar11[0x7a] = plVar14;
                *(undefined8 **)puVar11[0x7c] = puVar11 + 0x77;
                if ((param_5 != (long *)0x0) && (lVar12 = *param_5, lVar12 != 0)) {
                  uVar13 = 1;
                  do {
                    uVar17 = -(uVar13 >> 0x1f) & 0xfffffff800000000 | uVar13 << 3;
                    uVar13 = (ulong)((int)uVar13 + 1);
                    *(long *)(puVar11[0x7c] + uVar17) = lVar12;
                    lVar12 = *(long *)((long)param_5 + uVar17);
                  } while (lVar12 != 0);
                }
                param_5 = (long *)puVar11[0x7c];
                goto LAB_00101690;
              }
            }
            goto LAB_00101708;
          }
        }
        plVar14 = (long *)&DAT_ffffffffffffffea;
      }
    }
    else {
      uVar13 = 2;
      do {
        iVar9 = (int)uVar13;
        uVar8 = iVar9 + 1;
        uVar13 = (ulong)uVar8;
      } while (param_5[iVar9 + -1] != 0);
      if (-1 < (int)uVar8) {
        uVar13 = -(ulong)(uVar8 >> 0x1f) & 0xfffffff800000000 | uVar13 << 3;
        goto LAB_00101260;
      }
      plVar14 = (long *)0xfffffff4;
      puVar11[0x7c] = 0;
    }
LAB_00101708:
    iVar9 = (int)plVar14;
    plVar14 = (long *)puVar11[0x7a];
    if (plVar14 != (long *)0x0) {
      if (*plVar14 != 0) {
        iVar19 = 1;
        do {
          kfree();
          lVar12 = (long)iVar19;
          iVar19 = iVar19 + 1;
        } while (plVar14[lVar12] != 0);
      }
      kfree(plVar14);
    }
    kfree(puVar11[0x7c]);
    kfree(puVar11[1]);
    kfree(puVar11);
  }
  ida_free(hwmon_ida,iVar6);
  puVar15 = (undefined8 *)(long)iVar9;
LAB_001017bc:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar15;
}



//------------------------------------------------------------
// hwmon_device_register_with_info @ 00101888 size=76
// signature: undefined hwmon_device_register_with_info(void)
// callers: []
//------------------------------------------------------------

undefined8
hwmon_device_register_with_info(long param_1,long param_2,undefined8 param_3,long *param_4)

{
  undefined8 uVar1;
  
  uVar1 = 0xffffffffffffffea;
  if ((((param_1 != 0) && (param_2 != 0)) && (param_4 != (long *)0x0)) &&
     ((((long *)*param_4 != (long *)0x0 && (*(long *)*param_4 != 0)) && (param_4[1] != 0)))) {
    uVar1 = __hwmon_device_register(param_1);
  }
  return uVar1;
}



//------------------------------------------------------------
// hwmon_device_register_for_thermal @ 001018d8 size=56
// signature: undefined hwmon_device_register_for_thermal(void)
// callers: []
//------------------------------------------------------------

undefined8 hwmon_device_register_for_thermal(long param_1,long param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0xffffffffffffffea;
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = __hwmon_device_register(param_1,param_2,param_3,0,0);
  }
  return uVar1;
}



//------------------------------------------------------------
// hwmon_device_register @ 00101914 size=72
// signature: undefined hwmon_device_register(void)
// callers: []
//------------------------------------------------------------

void hwmon_device_register(undefined8 param_1)

{
  _dev_warn(param_1,
            "hwmon_device_register() is deprecated. Please convert the driver to use hwmon_device_register_with_info().\n"
           );
  __hwmon_device_register(param_1,0,0,0,0);
  return;
}



//------------------------------------------------------------
// hwmon_device_unregister @ 00101960 size=144
// signature: undefined hwmon_device_unregister(void)
// callers: []
//------------------------------------------------------------

void hwmon_device_unregister(undefined8 *param_1)

{
  long lVar1;
  int iVar2;
  char *param0;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  param0 = (char *)param_1[0xe];
  local_2c = 0;
  if (param0 == (char *)0x0) {
    param0 = (char *)*param_1;
  }
  iVar2 = sscanf(param0,"hwmon%d",&local_2c);
  if (iVar2 == 1) {
    device_unregister(param_1);
    ida_free(hwmon_ida,local_2c);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// devm_hwmon_device_register_with_groups @ 001019f4 size=200
// signature: undefined devm_hwmon_device_register_with_groups(void)
// callers: []
//------------------------------------------------------------

ulong devm_hwmon_device_register_with_groups
                (long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  ulong *puVar1;
  ulong uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffffffffffea;
  }
  else {
    puVar1 = (ulong *)__devres_alloc_node(devm_hwmon_release,8,0xcc0,0xffffffff,"devm_hwmon_release"
                                         );
    if (puVar1 == (ulong *)0x0) {
      uVar2 = 0xfffffffffffffff4;
    }
    else {
      if (param_2 == 0) {
        uVar2 = 0xffffffffffffffea;
      }
      else {
        uVar2 = __hwmon_device_register(param_1,param_2,param_3,0,param_4);
        if (uVar2 < 0xfffffffffffff001) {
          *puVar1 = uVar2;
          devres_add(param_1,puVar1);
          return uVar2;
        }
      }
      devres_free(puVar1);
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// devm_hwmon_release @ 00101ac0 size=144
// signature: undefined devm_hwmon_release(void)
// callers: []
//------------------------------------------------------------

void devm_hwmon_release(undefined8 param_1,undefined8 *param_2)

{
  long lVar1;
  int iVar2;
  char *param0;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  param_2 = (undefined8 *)*param_2;
  local_2c = 0;
  param0 = (char *)param_2[0xe];
  if (param0 == (char *)0x0) {
    param0 = (char *)*param_2;
  }
  iVar2 = sscanf(param0,"hwmon%d",&local_2c);
  if (iVar2 == 1) {
    device_unregister(param_2);
    ida_free(hwmon_ida,local_2c);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// devm_hwmon_device_register_with_info @ 00101b54 size=240
// signature: undefined devm_hwmon_device_register_with_info(void)
// callers: []
//------------------------------------------------------------

ulong devm_hwmon_device_register_with_info
                (long param_1,long param_2,undefined8 param_3,long *param_4,undefined8 param_5)

{
  ulong *puVar1;
  ulong uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffffffffffea;
  }
  else {
    puVar1 = (ulong *)__devres_alloc_node(devm_hwmon_release,8,0xcc0,0xffffffff,"devm_hwmon_release"
                                         );
    if (puVar1 == (ulong *)0x0) {
      uVar2 = 0xfffffffffffffff4;
    }
    else {
      uVar2 = 0xffffffffffffffea;
      if ((((param_2 == 0) || (param_4 == (long *)0x0)) || ((long *)*param_4 == (long *)0x0)) ||
         (((*(long *)*param_4 == 0 || (param_4[1] == 0)) ||
          (uVar2 = __hwmon_device_register(param_1,param_2,param_3,param_4,param_5),
          0xfffffffffffff000 < uVar2)))) {
        devres_free(puVar1);
      }
      else {
        *puVar1 = uVar2;
        devres_add(param_1,puVar1);
      }
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// devm_hwmon_device_unregister @ 00101c48 size=56
// signature: undefined devm_hwmon_device_unregister(void)
// callers: []
//------------------------------------------------------------

void devm_hwmon_device_unregister(undefined8 param_1)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = devres_release((int)param_1,devm_hwmon_release,devm_hwmon_match,param_1);
  if (iVar2 != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x101c80);
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// devm_hwmon_match @ 00101c88 size=16
// signature: undefined devm_hwmon_match(void)
// callers: []
//------------------------------------------------------------

bool devm_hwmon_match(undefined8 param_1,long *param_2,long param_3)

{
  return *param_2 == param_3;
}



//------------------------------------------------------------
// hwmon_sanitize_name @ 00101c9c size=104
// signature: undefined hwmon_sanitize_name(void)
// callers: []
//------------------------------------------------------------

byte * hwmon_sanitize_name(undefined8 param_1)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar2 = (byte *)kstrdup(param_1,0xcc0);
  if (pbVar2 == (byte *)0x0) {
    return (byte *)0xfffffffffffffff4;
  }
  pbVar3 = pbVar2;
  do {
    bVar1 = *pbVar3;
    if (bVar1 < 0x2e) {
      if ((1L << ((ulong)bVar1 & 0x3f) & 0x240100000600U) == 0) {
        if ((ulong)bVar1 == 0) {
          return pbVar2;
        }
      }
      else {
        *pbVar3 = 0x5f;
      }
    }
    pbVar3 = pbVar3 + 1;
  } while( true );
}



//------------------------------------------------------------
// devm_hwmon_sanitize_name @ 00101d08 size=116
// signature: undefined devm_hwmon_sanitize_name(void)
// callers: []
//------------------------------------------------------------

byte * devm_hwmon_sanitize_name(long param_1,undefined8 param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  if (param_1 == 0) {
    pbVar2 = &DAT_ffffffffffffffea;
  }
  else {
    pbVar2 = (byte *)devm_kstrdup(param_1,param_2,0xcc0);
    if (pbVar2 != (byte *)0x0) {
      pbVar3 = pbVar2;
      do {
        bVar1 = *pbVar3;
        if (bVar1 < 0x2e) {
          if ((1L << ((ulong)bVar1 & 0x3f) & 0x240100000600U) == 0) {
            if ((ulong)bVar1 == 0) {
              return pbVar2;
            }
          }
          else {
            *pbVar3 = 0x5f;
          }
        }
        pbVar3 = pbVar3 + 1;
      } while( true );
    }
    pbVar2 = (byte *)0xfffffffffffffff4;
  }
  return pbVar2;
}



//------------------------------------------------------------
// trace_raw_output_hwmon_attr_class @ 00101d80 size=112
// signature: undefined trace_raw_output_hwmon_attr_class(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_hwmon_attr_class(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"index=%d, attr_name=%s, val=%ld\n",*(undefined4 *)(lVar2 + 8),
                       lVar2 + (ulong)*(ushort *)(lVar2 + 0xc),*(undefined8 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_hwmon_attr_show_string @ 00101df4 size=116
// signature: undefined trace_raw_output_hwmon_attr_show_string(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_hwmon_attr_show_string(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"index=%d, attr_name=%s, val=%s\n",*(undefined4 *)(lVar2 + 8),
                       lVar2 + (ulong)*(ushort *)(lVar2 + 0xc),
                       lVar2 + (ulong)*(ushort *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// hwmon_thermal_register_sensors @ 00101e68 size=452
// signature: undefined hwmon_thermal_register_sensors(void)
// callers: [__hwmon_device_register]
//------------------------------------------------------------

ulong hwmon_thermal_register_sensors(long param_1)

{
  long *plVar1;
  short sVar2;
  long *plVar3;
  ulong uVar4;
  ulong uVar5;
  uint uVar6;
  int *piVar7;
  code *pcVar8;
  undefined8 uVar9;
  int iVar10;
  undefined8 *puVar11;
  long lVar12;
  long *plVar13;
  int iVar14;
  long lVar15;
  
  puVar11 = *(undefined8 **)(param_1 + 0x390);
  lVar12 = puVar11[1];
  plVar13 = (long *)(lVar12 + 8);
  piVar7 = (int *)*plVar13;
  if (piVar7 != (int *)0x0) {
    uVar9 = *(undefined8 *)(param_1 + 0x98);
    plVar1 = (long *)(param_1 + 0x398);
    iVar10 = 1;
    do {
      if ((*piVar7 == 1) && (uVar6 = **(uint **)(piVar7 + 2), uVar6 != 0)) {
        iVar14 = 0;
        do {
          if ((uVar6 >> 1 & 1) != 0) {
            pcVar8 = *(code **)*puVar11;
            if (*(int *)(pcVar8 + -4) != 0x1b984032) {
                    /* WARNING: Does not return */
              pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x101f50);
              (*pcVar8)();
            }
            sVar2 = (*pcVar8)(uVar9,1,1,iVar14);
            if (sVar2 != 0) {
              plVar3 = (long *)devm_kmalloc(param_1,0x28,0xdc0);
              if (plVar3 == (long *)0x0) {
                return 0xfffffff4;
              }
              plVar3[2] = param_1;
              *(int *)(plVar3 + 3) = iVar14;
              uVar4 = devm_thermal_of_zone_register(param_1,iVar14,plVar3,hwmon_thermal_ops);
              if (uVar4 < 0xfffffffffffff001) {
                uVar5 = devm_add_action(param_1,hwmon_thermal_remove_sensor,plVar3);
                if ((int)uVar5 != 0) {
                  return uVar5;
                }
                lVar15 = *plVar1;
                plVar3[4] = uVar4;
                uVar4 = __list_add_valid(plVar3,plVar1,lVar15);
                if ((uVar4 & 1) != 0) {
                  *(long **)(lVar15 + 8) = plVar3;
                  *plVar3 = lVar15;
                  plVar3[1] = (long)plVar1;
                  *plVar1 = (long)plVar3;
                }
              }
              else if (uVar4 == 0xffffffffffffffed) {
                _dev_info(param_1,"temp%d_input not attached to any thermal zone\n",iVar14 + 1);
                devm_kfree(param_1,plVar3);
              }
              else if ((int)uVar4 != 0) {
                return uVar4 & 0xffffffff;
              }
            }
          }
          iVar14 = iVar14 + 1;
          uVar6 = *(uint *)(*(long *)(*plVar13 + 8) + (long)iVar14 * 4);
        } while (uVar6 != 0);
      }
      iVar10 = iVar10 + 1;
      plVar13 = (long *)(lVar12 + (long)iVar10 * 8);
      piVar7 = (int *)*plVar13;
    } while (piVar7 != (int *)0x0);
  }
  return 0;
}



//------------------------------------------------------------
// hwmon_dev_release @ 00102030 size=116
// signature: undefined hwmon_dev_release(void)
// callers: []
//------------------------------------------------------------

void hwmon_dev_release(long param_1)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  
  plVar2 = *(long **)(param_1 + 0x3c0);
  if (plVar2 != (long *)0x0) {
    if (*plVar2 != 0) {
      iVar3 = 1;
      do {
        kfree();
        lVar1 = (long)iVar3;
        iVar3 = iVar3 + 1;
      } while (plVar2[lVar1] != 0);
    }
    kfree(plVar2);
  }
  kfree(*(undefined8 *)(param_1 + 0x3d0));
  kfree(*(undefined8 *)(param_1 + -8));
  kfree(param_1 + -0x10);
  return;
}



//------------------------------------------------------------
// hwmon_attr_show_string @ 001020a8 size=204
// signature: undefined hwmon_attr_show_string(void)
// callers: []
//------------------------------------------------------------

long hwmon_attr_show_string(undefined8 param_1,long param_2,char *param_3)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  code *pcVar5;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  iVar1 = *(int *)(param_2 + 0x28);
  local_40 = 0;
  pcVar5 = *(code **)(*(long *)(param_2 + 0x20) + 0x10);
  if (*(int *)(pcVar5 + -4) != 0x1c051495) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x102108);
    (*pcVar5)();
  }
  iVar4 = (*pcVar5)(param_1,iVar1,*(undefined4 *)(param_2 + 0x2c),*(undefined4 *)(param_2 + 0x30),
                    &local_40);
  if (-1 < iVar4) {
    uVar2 = *(uint *)(param_2 + 0x30);
    if (iVar1 != 9 && iVar1 != 2) {
      uVar2 = uVar2 + 1;
    }
    iVar4 = sprintf(param_3,"%s\n",(ulong)uVar2,local_40);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar4;
}



//------------------------------------------------------------
// hwmon_attr_show @ 00102224 size=204
// signature: undefined hwmon_attr_show(void)
// callers: []
//------------------------------------------------------------

long hwmon_attr_show(undefined8 param_1,long param_2,char *param_3)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  code *pcVar4;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  pcVar4 = *(code **)(*(long *)(param_2 + 0x20) + 8);
  if (*(int *)(pcVar4 + -4) != 0x4c3dc34a) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x102280);
    (*pcVar4)();
  }
  iVar3 = (*pcVar4)(param_1,*(undefined4 *)(param_2 + 0x28),*(undefined4 *)(param_2 + 0x2c),
                    *(undefined4 *)(param_2 + 0x30),&local_40);
  if (-1 < iVar3) {
    uVar1 = *(uint *)(param_2 + 0x30);
    if (*(int *)(param_2 + 0x28) != 9 && *(int *)(param_2 + 0x28) != 2) {
      uVar1 = uVar1 + 1;
    }
    iVar3 = sprintf(param_3,"%ld\n",(ulong)uVar1,local_40);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar3;
}



//------------------------------------------------------------
// hwmon_attr_store @ 001023a0 size=224
// signature: undefined hwmon_attr_store(void)
// callers: []
//------------------------------------------------------------

long hwmon_attr_store(undefined8 param_1,long param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  iVar2 = kstrtoll(param_3,10,&local_40);
  if (-1 < iVar2) {
    pcVar3 = *(code **)(*(long *)(param_2 + 0x20) + 0x18);
    if (*(int *)(pcVar3 + -4) != -0x7a509979) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10241c);
      (*pcVar3)();
    }
    iVar2 = (*pcVar3)(param_1,*(undefined4 *)(param_2 + 0x28),*(undefined4 *)(param_2 + 0x2c),
                      *(undefined4 *)(param_2 + 0x30),local_40);
    if (-1 < iVar2) goto LAB_001024f8;
  }
  param_4 = (long)iVar2;
LAB_001024f8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// hwmon_dev_attr_is_visible @ 00102530 size=64
// signature: undefined hwmon_dev_attr_is_visible(void)
// callers: []
//------------------------------------------------------------

undefined2 hwmon_dev_attr_is_visible(long param_1,undefined **param_2)

{
  long lVar1;
  
  if (param_2 == &dev_attr_name) {
    lVar1 = *(long *)(param_1 + -0x10);
  }
  else {
    if (param_2 != &dev_attr_label) goto LAB_00102568;
    lVar1 = *(long *)(param_1 + -8);
  }
  if (lVar1 == 0) {
    return 0;
  }
LAB_00102568:
  return *(undefined2 *)(param_2 + 1);
}



//------------------------------------------------------------
// name_show @ 00102574 size=52
// signature: undefined name_show(void)
// callers: []
//------------------------------------------------------------

long name_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = sprintf(param_3,"%s\n",*(undefined8 *)(param_1 + -0x10));
  return (long)iVar1;
}



//------------------------------------------------------------
// label_show @ 001025ac size=52
// signature: undefined label_show(void)
// callers: []
//------------------------------------------------------------

long label_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = sysfs_emit(param_3,&DAT_00103e56,*(undefined8 *)(param_1 + -8));
  return (long)iVar1;
}



//------------------------------------------------------------
// hwmon_thermal_remove_sensor @ 001025e4 size=76
// signature: undefined hwmon_thermal_remove_sensor(void)
// callers: []
//------------------------------------------------------------

void hwmon_thermal_remove_sensor(long *param_1)

{
  long lVar1;
  long *plVar2;
  uint uVar3;
  
  uVar3 = __list_del_entry_valid();
  if ((uVar3 & 1) != 0) {
    lVar1 = *param_1;
    plVar2 = (long *)param_1[1];
    *(long **)(lVar1 + 8) = plVar2;
    *plVar2 = lVar1;
  }
  *param_1 = -0x2152ffffffffff00;
  param_1[1] = -0x2152fffffffffede;
  return;
}



//------------------------------------------------------------
// hwmon_thermal_get_temp @ 00102634 size=164
// signature: undefined hwmon_thermal_get_temp(void)
// callers: []
//------------------------------------------------------------

void hwmon_thermal_get_temp(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x3f0) + 0x10);
  pcVar3 = *(code **)(**(long **)(lVar1 + 0x390) + 8);
  if (*(int *)(pcVar3 + -4) != 0x4c3dc34a) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x102698);
    (*pcVar3)();
  }
  uVar2 = (*pcVar3)(lVar1,1,1,*(undefined4 *)(*(long *)(param_1 + 0x3f0) + 0x18),&local_30);
  if (-1 < (int)uVar2) {
    uVar2 = 0;
    *param_2 = (int)local_30;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// hwmon_thermal_set_trips @ 001026dc size=280
// signature: undefined hwmon_thermal_set_trips(void)
// callers: []
//------------------------------------------------------------

undefined8 hwmon_thermal_set_trips(long param_1,int param_2,int param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  int *piVar3;
  long lVar4;
  long *plVar5;
  undefined8 *puVar6;
  uint uVar7;
  
  lVar4 = *(long *)(param_1 + 0x3f0);
  plVar5 = *(long **)(*(long *)(lVar4 + 0x10) + 0x390);
  pcVar2 = *(code **)(*plVar5 + 0x18);
  if (pcVar2 != (code *)0x0) {
    puVar6 = (undefined8 *)plVar5[1];
    piVar3 = (int *)*puVar6;
    if (piVar3 != (int *)0x0) {
      uVar7 = 0;
      do {
        if (*piVar3 == 1) {
          if ((*(uint *)(*(long *)(piVar3 + 2) + (long)*(int *)(lVar4 + 0x18) * 4) >> 5 & 1) != 0) {
            if (*(int *)(pcVar2 + -4) != -0x7a509979) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102770);
              (*pcVar2)();
            }
            uVar1 = (*pcVar2)(*(long *)(lVar4 + 0x10),1,5,(long)*(int *)(lVar4 + 0x18),(long)param_2
                             );
            if (((int)uVar1 != 0) && ((int)uVar1 != -0x5f)) {
              return uVar1;
            }
          }
          if ((*(uint *)(*(long *)(puVar6[uVar7] + 8) + (long)*(int *)(lVar4 + 0x18) * 4) >> 7 & 1)
              == 0) {
            return 0;
          }
          if (*(int *)(*(code **)(*plVar5 + 0x18) + -4) != -0x7a509979) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1027c8);
            (*pcVar2)();
          }
          uVar1 = (**(code **)(*plVar5 + 0x18))
                            (*(undefined8 *)(lVar4 + 0x10),1,7,(long)*(int *)(lVar4 + 0x18),
                             (long)param_3);
          if ((int)uVar1 == 0) {
            return 0;
          }
          if ((int)uVar1 == -0x5f) {
            return 0;
          }
          return uVar1;
        }
        uVar7 = uVar7 + 1;
        piVar3 = (int *)puVar6[uVar7];
      } while (piVar3 != (int *)0x0);
    }
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00102978 size=80
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = __class_register(&hwmon_class,&hwmon_init___key);
  if (iVar1 != 0) {
    _printk(&DAT_00103919);
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 001029cc size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  class_unregister(&hwmon_class);
  return;
}



//------------------------------------------------------------
// strlen @ 00106000 size=1
// signature: size_t strlen(char * __s)
// callers: [trace_event_raw_event_hwmon_attr_class, perf_trace_hwmon_attr_class, trace_event_raw_event_hwmon_attr_show_string, perf_trace_hwmon_attr_show_string]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 00106008 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_hwmon_attr_class, trace_event_raw_event_hwmon_attr_show_string]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 00106010 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [trace_event_raw_event_hwmon_attr_class, perf_trace_hwmon_attr_class, trace_event_raw_event_hwmon_attr_show_string, perf_trace_hwmon_attr_show_string]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 00106018 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_hwmon_attr_class, trace_event_raw_event_hwmon_attr_show_string]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 00106020 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_hwmon_attr_class, trace_event_raw_event_hwmon_attr_show_string]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00106028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [trace_event_raw_event_hwmon_attr_class, hwmon_attr_store, hwmon_attr_show_string, perf_trace_hwmon_attr_class, trace_event_raw_event_hwmon_attr_show_string, hwmon_attr_show, hwmon_device_unregister, hwmon_thermal_get_temp, perf_trace_hwmon_attr_show_string, devm_hwmon_release, hwmon_notify_event, __hwmon_device_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 00106030 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_hwmon_attr_class, perf_trace_hwmon_attr_show_string]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 00106038 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_hwmon_attr_class, perf_trace_hwmon_attr_show_string]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run3 @ 00106040 size=1
// signature: undefined bpf_trace_run3(void)
// callers: [__bpf_trace_hwmon_attr_class, __bpf_trace_hwmon_attr_show_string]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00106048 size=1
// signature: undefined scnprintf(void)
// callers: [hwmon_notify_event, __hwmon_device_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_notify @ 00106050 size=1
// signature: undefined sysfs_notify(void)
// callers: [hwmon_notify_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_uevent_env @ 00106058 size=1
// signature: undefined kobject_uevent_env(void)
// callers: [hwmon_notify_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_uevent_env(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_zone_device_update @ 00106060 size=1
// signature: undefined thermal_zone_device_update(void)
// callers: [hwmon_notify_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_zone_device_update(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strpbrk @ 00106068 size=1
// signature: char * strpbrk(char * __s, char * __accept)
// callers: [__hwmon_device_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strpbrk(char *__s,char *__accept)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ida_alloc_range @ 00106070 size=1
// signature: undefined ida_alloc_range(void)
// callers: [__hwmon_device_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ida_alloc_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00106080 size=1
// signature: undefined kmalloc_trace(void)
// callers: [__hwmon_device_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00106088 size=1
// signature: undefined __kmalloc(void)
// callers: [__hwmon_device_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sw_hweight32 @ 00106090 size=1
// signature: undefined __sw_hweight32(void)
// callers: [__hwmon_device_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sw_hweight32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 00106098 size=1
// signature: undefined _dev_warn(void)
// callers: [hwmon_device_register, __hwmon_device_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001060a0 size=1
// signature: undefined kfree(void)
// callers: [hwmon_dev_release, __hwmon_device_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_property_present @ 001060a8 size=1
// signature: undefined device_property_present(void)
// callers: [__hwmon_device_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_property_present(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_property_read_string @ 001060b0 size=1
// signature: undefined device_property_read_string(void)
// callers: [__hwmon_device_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrdup @ 001060b8 size=1
// signature: undefined kstrdup(void)
// callers: [hwmon_sanitize_name, __hwmon_device_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 001060c0 size=1
// signature: undefined dev_set_name(void)
// callers: [__hwmon_device_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_register @ 001060c8 size=1
// signature: undefined device_register(void)
// callers: [__hwmon_device_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 001060d0 size=1
// signature: undefined put_device(void)
// callers: [__hwmon_device_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ida_free @ 001060d8 size=1
// signature: undefined ida_free(void)
// callers: [hwmon_device_unregister, devm_hwmon_release, __hwmon_device_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ida_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_unregister @ 001060e0 size=1
// signature: undefined device_unregister(void)
// callers: [hwmon_device_unregister, devm_hwmon_release, __hwmon_device_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 001060e8 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [hwmon_device_unregister, devm_hwmon_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devres_alloc_node @ 001060f0 size=1
// signature: undefined __devres_alloc_node(void)
// callers: [devm_hwmon_device_register_with_info, devm_hwmon_device_register_with_groups]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devres_alloc_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devres_add @ 001060f8 size=1
// signature: undefined devres_add(void)
// callers: [devm_hwmon_device_register_with_info, devm_hwmon_device_register_with_groups]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devres_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devres_free @ 00106100 size=1
// signature: undefined devres_free(void)
// callers: [devm_hwmon_device_register_with_info, devm_hwmon_device_register_with_groups]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devres_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devres_release @ 00106108 size=1
// signature: undefined devres_release(void)
// callers: [devm_hwmon_device_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devres_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kstrdup @ 00106110 size=1
// signature: undefined devm_kstrdup(void)
// callers: [devm_hwmon_sanitize_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_register @ 00106118 size=1
// signature: undefined __class_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00106120 size=1
// signature: undefined _printk(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_unregister @ 00106128 size=1
// signature: undefined class_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_raw_output_prep @ 00106130 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_hwmon_attr_class, trace_raw_output_hwmon_attr_show_string]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 00106138 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_hwmon_attr_class, trace_raw_output_hwmon_attr_show_string]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 00106140 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_hwmon_attr_class, trace_raw_output_hwmon_attr_show_string]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00106148 size=1
// signature: undefined _dev_info(void)
// callers: [hwmon_thermal_register_sensors]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 00106150 size=1
// signature: undefined devm_kfree(void)
// callers: [hwmon_thermal_register_sensors]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00106158 size=1
// signature: undefined devm_kmalloc(void)
// callers: [hwmon_thermal_register_sensors]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_thermal_of_zone_register @ 00106160 size=1
// signature: undefined devm_thermal_of_zone_register(void)
// callers: [hwmon_thermal_register_sensors]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_thermal_of_zone_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_add_action @ 00106168 size=1
// signature: undefined devm_add_action(void)
// callers: [hwmon_thermal_register_sensors]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_add_action(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00106170 size=1
// signature: undefined __list_add_valid(void)
// callers: [hwmon_thermal_register_sensors]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sprintf @ 00106178 size=1
// signature: int sprintf(char * __s, char * __format, ...)
// callers: [hwmon_attr_show_string, name_show, hwmon_attr_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoll @ 00106198 size=1
// signature: undefined kstrtoll(void)
// callers: [hwmon_attr_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoll(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_emit @ 001061a0 size=1
// signature: undefined sysfs_emit(void)
// callers: [label_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_emit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001061a8 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [hwmon_thermal_remove_sensor]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



