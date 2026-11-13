// Decompiled by Ghidra 12.2
// Program: llcc_perfmon.ko
// Image base: 00100000

//------------------------------------------------------------
// llcc_perfmon_probe @ 001009ec size=1108
// signature: undefined llcc_perfmon_probe(void)
// callers: []
//------------------------------------------------------------

int llcc_perfmon_probe(long param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  long *plVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  long *plVar12;
  uint local_4c;
  long local_48;
  
  lVar7 = sp_el0;
  lVar8 = param_1 + 0x10;
  local_48 = *(long *)(lVar7 + 0x638);
  local_4c = 0;
  plVar12 = *(long **)(*(long *)(param_1 + 0x70) + 0x98);
  plVar6 = (long *)devm_kmalloc(lVar8,0xb60,0xdc0);
  iVar5 = -0xc;
  if ((plVar6 == (long *)0x0) || (plVar12 == (long *)0x0)) goto LAB_00100a58;
  if ((*plVar12 == 0) || (plVar12[1] == 0)) {
    iVar5 = -0x13;
    goto LAB_00100a58;
  }
  *plVar6 = *plVar12;
  lVar7 = plVar12[1];
  uVar11 = 0x34000;
  plVar6[1] = lVar7;
  iVar5 = *(int *)((long)plVar12 + 0x74);
  *(int *)((long)plVar6 + 0xb4c) = iVar5;
  uVar10 = 0x3400c;
  if (iVar5 < 0x15) {
    uVar10 = 0x3000c;
  }
  uVar2 = 0x6400c;
  if (iVar5 != 0x33) {
    uVar2 = uVar10;
  }
  regmap_read(lVar7,uVar2,&local_4c);
  uVar3 = local_4c;
  local_4c = 0;
  uVar1 = uVar3 >> 10 & 3;
  uVar3 = uVar3 >> 0x1c;
  if (uVar1 == 0) {
    uVar1 = 1;
  }
  *(uint *)(plVar6 + 10) = uVar3;
  *(uint *)(plVar6 + 0x167) = uVar1;
  if (uVar3 != 0) {
    uVar9 = 0;
    do {
      if (uVar9 == 0x10) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x100e3c);
        (*pcVar4)();
      }
      lVar7 = uVar9 * 4;
      uVar9 = uVar9 + 1;
      local_4c = (uint)uVar9;
      *(undefined4 *)((long)plVar6 + lVar7 + 0x10) = *(undefined4 *)(plVar12[0xd] + lVar7);
    } while (uVar9 < *(uint *)(plVar6 + 10));
  }
  uVar9 = devm_clk_get(lVar8,"qdss_clk");
  plVar6[0x168] = uVar9;
  if ((uVar9 == 0) || (0xfffffffffffff000 < uVar9)) {
    _printk(&DAT_00105da2);
    plVar6[0x168] = 0;
  }
  if ((*(int *)((long)plVar6 + 0xb4c) == 0x33) &&
     (iVar5 = regmap_write(plVar6[1],0x64100,0), iVar5 != 0)) {
    _printk(&DAT_001065dd,iVar5);
    goto LAB_00100a58;
  }
  iVar5 = sysfs_create_group(lVar8,llcc_perfmon_group);
  if (iVar5 != 0) {
    _printk(&DAT_00105e49);
    goto LAB_00100a58;
  }
  __mutex_init(plVar6 + 0x157,"&llcc_priv->mutex",&llcc_perfmon_probe___key);
  uVar1 = *(uint *)((long)plVar6 + 0xab4);
  *(long **)(param_1 + 0xa8) = plVar6;
  if (uVar1 < 8) {
    uVar1 = uVar1 + 1;
    *(uint *)((long)plVar6 + 0xab4) = uVar1;
    plVar6[0xb] = (long)&feac_port_ops;
  }
  else {
    _printk(&DAT_001065a7);
    uVar1 = *(uint *)((long)plVar6 + 0xab4);
  }
  if (uVar1 < 8) {
    uVar1 = uVar1 + 1;
    *(uint *)((long)plVar6 + 0xab4) = uVar1;
    plVar6[0xc] = (long)&ferc_port_ops;
  }
  else {
    _printk(&DAT_001065a7);
    uVar1 = *(uint *)((long)plVar6 + 0xab4);
  }
  if (uVar1 < 8) {
    uVar1 = uVar1 + 1;
    *(uint *)((long)plVar6 + 0xab4) = uVar1;
    plVar6[0xd] = (long)&fewc_port_ops;
  }
  else {
    _printk(&DAT_001065a7);
    uVar1 = *(uint *)((long)plVar6 + 0xab4);
  }
  if (uVar1 < 8) {
    uVar1 = uVar1 + 1;
    *(uint *)((long)plVar6 + 0xab4) = uVar1;
    plVar6[0xe] = (long)&beac_port_ops;
  }
  else {
    _printk(&DAT_001065a7);
    uVar1 = *(uint *)((long)plVar6 + 0xab4);
  }
  if (uVar1 < 8) {
    uVar1 = uVar1 + 1;
    *(uint *)((long)plVar6 + 0xab4) = uVar1;
    plVar6[0xf] = (long)&berc_port_ops;
  }
  else {
    _printk(&DAT_001065a7);
    uVar1 = *(uint *)((long)plVar6 + 0xab4);
  }
  if (uVar1 < 8) {
    uVar1 = uVar1 + 1;
    *(uint *)((long)plVar6 + 0xab4) = uVar1;
    plVar6[0x10] = (long)&trp_port_ops;
  }
  else {
    _printk(&DAT_001065a7);
    uVar1 = *(uint *)((long)plVar6 + 0xab4);
  }
  if (uVar1 < 8) {
    uVar1 = uVar1 + 1;
    *(uint *)((long)plVar6 + 0xab4) = uVar1;
    plVar6[0x11] = (long)&drp_port_ops;
  }
  else {
    _printk(&DAT_001065a7);
    uVar1 = *(uint *)((long)plVar6 + 0xab4);
  }
  if (uVar1 < 8) {
    *(uint *)((long)plVar6 + 0xab4) = uVar1 + 1;
    plVar6[0x12] = (long)&pmgr_port_ops;
  }
  else {
    _printk(&DAT_001065a7);
  }
  uVar10 = 1;
  hrtimer_init(plVar6 + 0x15d,1,1);
  plVar6[0x166] = 0;
  plVar6[0x162] = (long)llcc_perfmon_timer_handler;
  if (*(int *)((long)plVar6 + 0xb4c) < 0x15) {
    uVar11 = 0x30000;
  }
  uVar2 = 0x64000;
  if (*(int *)((long)plVar6 + 0xb4c) != 0x33) {
    uVar2 = uVar11;
  }
  *(undefined1 *)(plVar6 + 0x169) = 0;
  regmap_read(plVar6[1],uVar2,&local_4c);
  *(undefined4 *)((long)plVar6 + 0xb3c) = 0;
  if (local_4c == 0x1010200) {
LAB_00100df0:
    *(undefined4 *)((long)plVar6 + 0xb3c) = uVar10;
  }
  else if ((local_4c >> 0x19 != 0) || ((local_4c & 0xff000000) == 0x5000000)) {
    uVar10 = 5;
    if ((local_4c & 0xff000000) != 0x5000000) {
      uVar10 = 2;
    }
    goto LAB_00100df0;
  }
  _printk(&DAT_00106709,local_4c >> 0x18,local_4c >> 0x10 & 0xff,local_4c >> 8 & 0xff,
          (int)plVar6[0x167]);
  lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"llcc-occupancy-snapshot",0);
  iVar5 = 0;
  *(bool *)(plVar6 + 0x16b) = lVar8 != 0;
LAB_00100a58:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// llcc_perfmon_remove @ 00100e44 size=92
// signature: undefined llcc_perfmon_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 llcc_perfmon_remove(long param_1)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = *(long *)(param_1 + 0xa8) + 0xae8;
  while (uVar2 = hrtimer_active(lVar1), (uVar2 & 1) != 0) {
    hrtimer_cancel(lVar1);
  }
  sysfs_remove_group(param_1 + 0x10,llcc_perfmon_group);
  *(undefined8 *)(param_1 + 0xa8) = 0;
  return 0;
}



//------------------------------------------------------------
// llcc_perfmon_timer_handler @ 00100ea4 size=104
// signature: undefined llcc_perfmon_timer_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 llcc_perfmon_timer_handler(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  perfmon_counter_dump(param_1 + -0xae8);
  uVar3 = *(undefined8 *)(param_1 + 0x48);
  pcVar2 = *(code **)(*(long *)(param_1 + 0x30) + 0x30);
  if (*(int *)(pcVar2 + -4) != 0x7230bf2a) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100ee4);
    (*pcVar2)();
  }
  uVar1 = (*pcVar2)();
  hrtimer_forward(param_1,uVar1,uVar3);
  return 1;
}



//------------------------------------------------------------
// perfmon_counter_dump_show @ 00100f10 size=660
// signature: undefined perfmon_counter_dump_show(void)
// callers: []
//------------------------------------------------------------

long perfmon_counter_dump_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  code *pcVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  int *piVar12;
  ulong uVar13;
  long lVar14;
  uint uVar15;
  uint local_6c;
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  lVar10 = *(long *)(param_1 + 0x98);
  local_6c = 0;
  if (*(int *)(lVar10 + 0x998) == 0) {
    _printk(&DAT_001062f0);
    lVar11 = 0;
  }
  else {
    perfmon_counter_dump(lVar10);
    if (*(int *)(lVar10 + 0x998) == 0) {
      lVar11 = 0;
    }
    else {
      lVar11 = 0;
      uVar15 = 0;
      do {
        if (0x10 < uVar15) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x1011a0);
          (*pcVar6)();
        }
        uVar13 = (ulong)uVar15;
        piVar12 = (int *)(lVar10 + (ulong)uVar15 * 0x90 + 0x98);
        if ((*piVar12 == 3) && (1 < *(uint *)(lVar10 + 0xb38))) {
          uVar15 = uVar15 + 1;
          if (*(int *)(lVar10 + 0x50) == 0) {
LAB_00101084:
            lVar14 = 0;
          }
          else {
            uVar5 = 0;
            lVar14 = 0;
            do {
              lVar7 = lVar10 + uVar13 * 0x90 + uVar5 * 8;
              uVar2 = *(uint *)(lVar10 + 0x50);
              uVar5 = uVar5 + 1;
              lVar8 = *(long *)(lVar7 + 0xa8);
              lVar9 = *(long *)(lVar7 + 0x138);
              *(undefined8 *)(lVar7 + 0xa8) = 0;
              *(undefined8 *)(lVar7 + 0x138) = 0;
              lVar14 = lVar8 + lVar14 + lVar9;
            } while (uVar5 < uVar2);
          }
        }
        else {
          if (*(int *)(lVar10 + 0x50) == 0) goto LAB_00101084;
          uVar5 = 0;
          lVar14 = 0;
          lVar7 = lVar10 + 0xa8 + uVar13 * 0x90;
          do {
            lVar8 = uVar5 * 8;
            uVar2 = *(uint *)(lVar10 + 0x50);
            uVar5 = uVar5 + 1;
            lVar9 = *(long *)(lVar7 + lVar8);
            *(undefined8 *)(lVar7 + lVar8) = 0;
            lVar14 = lVar9 + lVar14;
          } while (uVar5 < uVar2);
        }
        if (uVar15 == *(int *)(lVar10 + 0x998) - 1U) {
          iVar3 = 0x36020;
          if (*(int *)(lVar10 + 0xb4c) < 0x15) {
            iVar3 = 0x31020;
          }
          iVar1 = 0x66020;
          if (*(int *)(lVar10 + 0xb4c) != 0x33) {
            iVar1 = iVar3;
          }
          regmap_read(*(undefined8 *)(lVar10 + 8),iVar1 + uVar15 * 4,&local_6c);
          if ((local_6c & 0x1000000) != 0) {
            iVar3 = scnprintf(param_3 + lVar11,0x1000 - lVar11,"CYCLE COUNT, ,");
            lVar11 = lVar11 + iVar3;
            iVar3 = scnprintf(param_3 + lVar11,0x1000 - lVar11,"0x%016llx\n",lVar14);
            lVar11 = lVar11 + iVar3;
            break;
          }
        }
        iVar3 = scnprintf(param_3 + lVar11,0x1000 - lVar11,"Port %02d,Event %03d,",*piVar12,
                          *(undefined4 *)(lVar10 + uVar13 * 0x90 + 0x9c));
        lVar11 = lVar11 + iVar3;
        iVar3 = scnprintf(param_3 + lVar11,0x1000 - lVar11,"0x%016llx\n",lVar14);
        lVar11 = lVar11 + iVar3;
        uVar15 = uVar15 + 1;
      } while (uVar15 < *(uint *)(lVar10 + 0x998));
    }
    lVar14 = *(long *)(lVar10 + 0xb30);
    if (lVar14 != 0) {
      pcVar6 = *(code **)(*(long *)(lVar10 + 0xb18) + 0x30);
      if (*(int *)(pcVar6 + -4) != 0x7230bf2a) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x101138);
        (*pcVar6)();
      }
      uVar4 = (*pcVar6)();
      hrtimer_forward(lVar10 + 0xae8,uVar4,lVar14);
    }
  }
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar11;
}



//------------------------------------------------------------
// perfmon_counter_dump @ 001011a4 size=424
// signature: undefined perfmon_counter_dump(void)
// callers: [llcc_perfmon_timer_handler, perfmon_counter_dump_show]
//------------------------------------------------------------

void perfmon_counter_dump(undefined8 *param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  uint local_6c;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  local_6c = 0;
  if (*(int *)(param_1 + 0x133) != 0) {
    iVar2 = *(int *)((long)param_1 + 0xb4c);
    uVar4 = 0x67000;
    if (iVar2 != 0x33) {
      if (iVar2 < 0x29) {
        uVar4 = 0x36010;
        if (iVar2 < 0x15) {
          uVar4 = 0x31010;
        }
      }
      else {
        uVar4 = 0x37000;
      }
    }
    regmap_write(param_1[1],uVar4,1);
    uVar5 = (ulong)*(uint *)(param_1 + 0x133);
    if (*(uint *)(param_1 + 0x133) != 0) {
      uVar7 = 0;
      lVar8 = 0xa8;
      do {
        if (uVar7 == 0x11) {
LAB_00101344:
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x101348);
          (*pcVar3)();
        }
        iVar2 = *(int *)((long)param_1 + 0xb4c);
        if (iVar2 == 0x33) {
          iVar1 = 0x67008;
          iVar2 = *(int *)(param_1 + 10);
        }
        else if (iVar2 < 0x29) {
          iVar1 = 0x36060;
          if (iVar2 < 0x15) {
            iVar1 = 0x31060;
          }
          iVar2 = *(int *)(param_1 + 10);
        }
        else {
          iVar1 = 0x37008;
          iVar2 = *(int *)(param_1 + 10);
        }
        if (iVar2 != 0) {
          uVar5 = 0;
          do {
            if (uVar5 == 0x10) goto LAB_00101344;
            regmap_read(*param_1,iVar1 + (int)uVar7 * 4 + *(int *)((long)param_1 + uVar5 * 4 + 0x10)
                        ,&local_6c);
            lVar6 = uVar5 * 8;
            uVar5 = uVar5 + 1;
            *(ulong *)((long)param_1 + lVar6 + lVar8) =
                 *(long *)((long)param_1 + lVar6 + lVar8) + (ulong)local_6c;
          } while (uVar5 < *(uint *)(param_1 + 10));
          uVar5 = (ulong)*(uint *)(param_1 + 0x133);
        }
        uVar7 = uVar7 + 1;
        lVar8 = lVar8 + 0x90;
      } while (uVar7 < uVar5);
    }
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perfmon_configure_store @ 00101350 size=1100
// signature: undefined perfmon_configure_store(void)
// callers: []
//------------------------------------------------------------

undefined8 perfmon_configure_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  size_t sVar6;
  ulong uVar7;
  code *pcVar8;
  uint uVar9;
  uint uVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  undefined8 *puVar14;
  uint local_8c;
  ulong local_88;
  ulong local_80;
  uint local_74;
  char *local_70;
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  lVar12 = *(long *)(param_1 + 0x98);
  local_74 = 0;
  local_88 = 0;
  local_80 = 0;
  local_8c = 0;
  local_70 = param_3;
  mutex_lock(lVar12 + 0xab8);
  iVar4 = *(int *)(lVar12 + 0x998);
  if (iVar4 == 0x10) {
    uVar1 = 0x3605c;
    if (*(int *)(lVar12 + 0xb4c) < 0x15) {
      uVar1 = 0x3105c;
    }
    uVar2 = 0x6605c;
    if (*(int *)(lVar12 + 0xb4c) != 0x33) {
      uVar2 = uVar1;
    }
    regmap_read(*(undefined8 *)(lVar12 + 8),uVar2,&local_8c);
    if ((local_8c & 0x1000000) == 0) {
      _printk(&DAT_001062af);
      param_4 = 0xffffffffffffffea;
      goto LAB_00101730;
    }
    iVar4 = *(int *)(lVar12 + 0x998);
  }
  if (iVar4 != 0) {
    local_74 = iVar4 - 1;
  }
  pcVar5 = strsep(&local_70," ");
  if (pcVar5 != (char *)0x0) {
    sVar6 = strlen(pcVar5);
    if (sVar6 == 7) {
      if (*(int *)(lVar12 + 0xab0) != 2) {
        _printk(&DAT_00105ec4);
        goto LAB_00101730;
      }
      uVar7 = sysfs_streq(pcVar5,"FILTER0");
      if ((uVar7 & 1) == 0) {
        uVar7 = sysfs_streq(pcVar5,"FILTER1");
        if ((uVar7 & 1) == 0) {
          _printk(&DAT_00105cc2);
          goto LAB_00101730;
        }
        lVar13 = 1;
      }
      else {
        lVar13 = 0;
      }
      pcVar5 = strsep(&local_70," ");
      if (pcVar5 == (char *)0x0) goto LAB_001016d0;
    }
    else {
      lVar13 = 0;
    }
LAB_001014ac:
    do {
      iVar4 = kstrtoull(pcVar5,0,&local_80);
      if ((iVar4 != 0) || (*(uint *)(lVar12 + 0xab4) <= local_80)) break;
      if ((sVar6 == 7) &&
         ((*(uint *)(lVar12 + lVar13 * 4 + 0x9a8) >> (ulong)((uint)local_80 & 0x1f) & 1) == 0)) {
        _printk(&DAT_0010636a);
LAB_00101684:
        remove_counters(lVar12);
        goto LAB_00101730;
      }
      pcVar5 = strsep(&local_70," ");
      if ((pcVar5 == (char *)0x0) || (iVar4 = kstrtoull(pcVar5,0,&local_88), iVar4 != 0)) break;
      pcVar5 = strsep(&local_70," ");
      if (0x7f < local_88) {
        _printk(&DAT_00105a97);
        if (pcVar5 == (char *)0x0) break;
        goto LAB_001014ac;
      }
      if (local_80 == 3) {
        uVar10 = (uint)*(byte *)(lVar12 + 0xb38);
      }
      else {
        uVar10 = 0;
      }
      if (local_74 == 0x10 - uVar10) {
        _printk(&DAT_00106071);
        break;
      }
      if (0x10 < local_74) {
LAB_00101794:
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x101798);
        (*pcVar8)();
      }
      lVar11 = lVar12 + (ulong)local_74 * 0x90;
      *(int *)(lVar11 + 0x98) = (int)local_80;
      *(int *)(lVar11 + 0x9c) = (int)local_88;
      if (sVar6 == 7) {
        lVar11 = lVar12 + (ulong)local_74 * 0x90;
        *(undefined1 *)(lVar11 + 0xa0) = 1;
        *(char *)(lVar11 + 0xa1) = (char)lVar13;
      }
      if (*(int *)(lVar12 + 0x50) != 0) {
        uVar7 = 0;
        do {
          uVar10 = *(uint *)(lVar12 + 0x50);
          *(undefined8 *)(lVar12 + 0xa8 + (ulong)local_74 * 0x90 + uVar7 * 8) = 0;
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar10);
      }
      if (7 < local_80) goto LAB_00101794;
      puVar14 = *(undefined8 **)(lVar12 + local_80 * 8 + 0x58);
      pcVar8 = (code *)*puVar14;
      if (*(int *)(pcVar8 + -4) != -0x7e133f8b) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1015e4);
        (*pcVar8)();
      }
      uVar7 = (*pcVar8)(lVar12,local_88 & 0xffffffff,&local_74,1);
      uVar10 = local_74;
      local_74 = local_74 + 1;
      if ((uVar7 & 1) == 0) {
        *(uint *)(lVar12 + 0x998) = local_74;
        goto LAB_00101684;
      }
      _printk(&DAT_00106463,uVar10,local_88,local_80);
      uVar10 = *(uint *)(lVar12 + 0x9a0);
      uVar9 = 1 << (ulong)((uint)local_80 & 0x1f);
      if (((uVar9 & uVar10) == 0) && (pcVar8 = (code *)puVar14[1], pcVar8 != (code *)0x0)) {
        if (*(int *)(pcVar8 + -4) != -0x969b12f) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x822a,0x101648);
          (*pcVar8)();
        }
        (*pcVar8)(lVar12,1);
        uVar10 = *(uint *)(lVar12 + 0x9a0);
        uVar9 = 1 << (ulong)((uint)local_80 & 0x1f);
      }
      *(uint *)(lVar12 + 0x9a0) = uVar9 | uVar10;
    } while (pcVar5 != (char *)0x0);
  }
LAB_001016d0:
  if (local_74 == 0) {
    _printk(&DAT_00105dd1);
  }
  else {
    if (local_74 < 0x10) {
      iVar4 = 0x36020;
      if (*(int *)(lVar12 + 0xb4c) < 0x15) {
        iVar4 = 0x31020;
      }
      local_8c = 0xc1000000;
      iVar3 = 0x66020;
      if (*(int *)(lVar12 + 0xb4c) != 0x33) {
        iVar3 = iVar4;
      }
      iVar4 = local_74 * 4;
      local_74 = local_74 + 1;
      regmap_write(*(undefined8 *)(lVar12 + 8),iVar3 + iVar4,0xc1000000);
    }
    *(uint *)(lVar12 + 0x998) = local_74;
  }
LAB_00101730:
  mutex_unlock(lVar12 + 0xab8);
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// remove_counters @ 0010179c size=560
// signature: undefined remove_counters(void)
// callers: [perfmon_configure_store, perfmon_remove_store]
//------------------------------------------------------------

void remove_counters(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 *puVar9;
  undefined8 *puVar10;
  uint local_70;
  uint local_6c;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  uVar7 = *(uint *)(param_1 + 0x998);
  local_70 = 0;
  if (uVar7 == 0) {
    _printk(&DAT_00105d01);
  }
  else {
    uVar4 = 0;
    local_6c = 0;
    do {
      if ((int)uVar4 == uVar7 - 1) {
        iVar2 = 0x36020;
        if (*(int *)(param_1 + 0xb4c) < 0x15) {
          iVar2 = 0x31020;
        }
        iVar1 = 0x66020;
        if (*(int *)(param_1 + 0xb4c) != 0x33) {
          iVar1 = iVar2;
        }
        iVar1 = iVar1 + (int)uVar4 * 4;
        regmap_read(*(undefined8 *)(param_1 + 8),iVar1,&local_70);
        if ((local_70 & 0x1000000) != 0) {
          regmap_write(*(undefined8 *)(param_1 + 8),iVar1,0);
          break;
        }
        uVar4 = (ulong)local_6c;
      }
      if (0x10 < (uint)uVar4) {
LAB_001019c4:
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x1019c8);
        (*pcVar5)();
      }
      puVar8 = (uint *)(param_1 + uVar4 * 0x90 + 0x98);
      uVar7 = *puVar8;
      uVar6 = (uint)uVar4;
      if (uVar7 != 8) {
        if (7 < uVar7) goto LAB_001019c4;
        puVar10 = *(undefined8 **)(param_1 + (ulong)uVar7 * 8 + 0x58);
        pcVar5 = (code *)*puVar10;
        if (*(int *)(pcVar5 + -4) != -0x7e133f8b) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1018e0);
          (*pcVar5)();
        }
        (*pcVar5)(param_1,0,&local_6c,0);
        puVar9 = (undefined4 *)(param_1 + uVar4 * 0x90 + 0x9c);
        _printk(&DAT_001063b9,local_6c,*puVar9,*puVar8);
        uVar7 = *(uint *)(param_1 + 0x9a0);
        uVar6 = 1 << (ulong)(*puVar8 & 0x1f);
        if (((uVar6 & uVar7) != 0) && (pcVar5 = (code *)puVar10[1], pcVar5 != (code *)0x0)) {
          if (*(int *)(pcVar5 + -4) != -0x969b12f) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x822a,0x101938);
            (*pcVar5)();
          }
          (*pcVar5)(param_1,0);
          uVar7 = *(uint *)(param_1 + 0x9a0);
          uVar6 = 1 << (ulong)(*puVar8 & 0x1f);
        }
        *puVar8 = 8;
        *puVar9 = 0xff;
        *(uint *)(param_1 + 0x9a0) = uVar7 & (uVar6 ^ 0xffffffff);
        uVar6 = local_6c;
      }
      uVar7 = *(uint *)(param_1 + 0x998);
      local_6c = uVar6 + 1;
      uVar4 = (ulong)local_6c;
    } while (local_6c < uVar7);
    *(undefined4 *)(param_1 + 0x998) = 0;
    _printk(&DAT_00105b15);
    if (*(int *)(param_1 + 0xab0) != 0) {
      _printk(&DAT_0010669a);
      remove_filters(param_1);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// remove_filters @ 001019cc size=400
// signature: undefined remove_filters(void)
// callers: [remove_counters, perfmon_filter_config_store, perfmon_filter_remove_store]
//------------------------------------------------------------

void remove_filters(long param_1)

{
  long lVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  undefined *puVar5;
  code *pcVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  
  uVar4 = *(uint *)(param_1 + 0x9ac) | *(uint *)(param_1 + 0x9a8);
  if (uVar4 == 0) {
    puVar5 = &DAT_00105f1c;
  }
  else {
    lVar7 = 0;
    lVar8 = param_1;
    do {
      if ((uVar4 >> (ulong)((uint)lVar7 & 0x1f) & 1) != 0) {
        lVar9 = 0;
        do {
          lVar1 = lVar8 + lVar9;
          cVar2 = *(char *)(lVar1 + 0x9b0);
          cVar3 = *(char *)(lVar1 + 0x9b1);
          if (cVar2 != '\0' || cVar3 != '\0') {
            lVar10 = *(long *)(param_1 + lVar7 * 8 + 0x58);
            pcVar6 = *(code **)(lVar10 + 0x10);
            if (pcVar6 != (code *)0x0) {
              if (cVar2 != '\0') {
                if (*(int *)(pcVar6 + -4) != 0x3b4afb8e) {
                    /* WARNING: Does not return */
                  pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x101a9c);
                  (*pcVar6)();
                }
                (*pcVar6)(param_1,cVar2,0,0,0,0);
                *(undefined1 *)(lVar1 + 0x9b0) = 0;
              }
              if (cVar3 != '\0') {
                pcVar6 = *(code **)(lVar10 + 0x10);
                if (*(int *)(pcVar6 + -4) != 0x3b4afb8e) {
                    /* WARNING: Does not return */
                  pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x101adc);
                  (*pcVar6)();
                }
                (*pcVar6)(param_1,cVar3,0,0,0,1);
                *(undefined1 *)(lVar1 + 0x9b1) = 0;
              }
            }
          }
          lVar9 = lVar9 + 2;
        } while (lVar9 != 0x20);
      }
      lVar7 = lVar7 + 1;
      lVar8 = lVar8 + 0x20;
    } while (lVar7 != 8);
    puVar5 = &DAT_001061c5;
    *(undefined8 *)(param_1 + 0x9a8) = 0;
    *(undefined4 *)(param_1 + 0xab0) = 0;
    *(undefined1 *)(param_1 + 0xa0) = 0;
    *(undefined1 *)(param_1 + 0x130) = 0;
    *(undefined1 *)(param_1 + 0x1c0) = 0;
    *(undefined1 *)(param_1 + 0x250) = 0;
    *(undefined1 *)(param_1 + 0x2e0) = 0;
    *(undefined1 *)(param_1 + 0x370) = 0;
    *(undefined1 *)(param_1 + 0x400) = 0;
    *(undefined1 *)(param_1 + 0x490) = 0;
    *(undefined1 *)(param_1 + 0x520) = 0;
    *(undefined1 *)(param_1 + 0x5b0) = 0;
    *(undefined1 *)(param_1 + 0x640) = 0;
    *(undefined1 *)(param_1 + 0x6d0) = 0;
    *(undefined1 *)(param_1 + 0x760) = 0;
    *(undefined1 *)(param_1 + 0x7f0) = 0;
    *(undefined1 *)(param_1 + 0x880) = 0;
    *(undefined1 *)(param_1 + 0x910) = 0;
  }
  _printk(puVar5);
  return;
}



//------------------------------------------------------------
// perfmon_remove_store @ 00101b60 size=1116
// signature: undefined perfmon_remove_store(void)
// callers: []
//------------------------------------------------------------

undefined8 perfmon_remove_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  ulong uVar4;
  size_t sVar5;
  undefined *puVar6;
  code *pcVar7;
  uint uVar8;
  uint uVar9;
  long lVar10;
  long lVar11;
  undefined8 *puVar12;
  uint uVar13;
  ulong local_88;
  ulong local_80;
  uint local_78;
  uint local_74;
  char *local_70;
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  lVar11 = *(long *)(param_1 + 0x98);
  local_74 = 0;
  local_78 = 0;
  local_88 = 0;
  local_80 = 0;
  local_70 = param_3;
  mutex_lock(lVar11 + 0xab8);
  if (*(uint *)(lVar11 + 0x998) == 0) {
    _printk(&DAT_001064bf);
LAB_00101fac:
    param_4 = 0xffffffffffffffea;
  }
  else {
    uVar13 = *(uint *)(lVar11 + 0x99c);
    if ((uVar13 != 0) && (uVar13 < *(uint *)(lVar11 + 0x998))) {
      local_74 = uVar13;
    }
    pcVar3 = strsep(&local_70," ");
    if (pcVar3 != (char *)0x0) {
      uVar4 = sysfs_streq(pcVar3,"REMOVE");
      if ((uVar4 & 1) != 0) {
        _printk(&DAT_001066bc);
        remove_counters(lVar11);
        goto LAB_00101ed0;
      }
      sVar5 = strlen(pcVar3);
      if (sVar5 == 7) {
        if (*(int *)(lVar11 + 0xab0) == 2) {
          uVar4 = sysfs_streq(pcVar3,"FILTER0");
          if (((uVar4 & 1) != 0) || (uVar4 = sysfs_streq(pcVar3,"FILTER1"), (uVar4 & 1) != 0)) {
            pcVar3 = strsep(&local_70," ");
            if (pcVar3 == (char *)0x0) goto LAB_00101e4c;
            goto LAB_00101c58;
          }
          _printk(&DAT_00106324);
        }
        else {
          _printk(&DAT_00105d5f);
        }
LAB_00101fa4:
        remove_counters(lVar11);
        goto LAB_00101fac;
      }
LAB_00101c58:
      uVar13 = 0;
LAB_00101c6c:
      do {
        iVar2 = kstrtoull(pcVar3,0,&local_80);
        if ((iVar2 != 0) || (*(uint *)(lVar11 + 0xab4) <= local_80)) break;
        if (0x10 < local_74) {
LAB_00101fb4:
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x101fb8);
          (*pcVar7)();
        }
        lVar10 = lVar11 + (ulong)local_74 * 0x90;
        if (*(char *)(lVar10 + 0xa0) != '\0') {
          uVar4 = (ulong)*(byte *)(lVar11 + (ulong)local_74 * 0x90 + 0xa1);
          if (1 < uVar4) goto LAB_00101fb4;
          uVar13 = *(uint *)(lVar11 + uVar4 * 4 + 0x9a8) >> (ulong)((uint)local_80 & 0x1f) & 1;
        }
        if (local_80 != *(uint *)(lVar10 + 0x98)) {
          _printk(&DAT_0010661f,local_80,local_74);
          goto LAB_00101fa4;
        }
        if ((sVar5 != 7) == 0 && uVar13 == 0) {
          puVar6 = &DAT_0010611f;
LAB_00101f9c:
          _printk(puVar6,local_74);
          goto LAB_00101fa4;
        }
        if ((sVar5 != 7 & uVar13) == 1) {
          puVar6 = &DAT_00105f4c;
          goto LAB_00101f9c;
        }
        pcVar3 = strsep(&local_70," ");
        if ((pcVar3 == (char *)0x0) || (iVar2 = kstrtoull(pcVar3,0,&local_88), iVar2 != 0)) break;
        pcVar3 = strsep(&local_70," ");
        if (0x7f < local_88) {
          _printk(&DAT_00105a97);
          if (pcVar3 == (char *)0x0) break;
          goto LAB_00101c6c;
        }
        if (local_80 == 3) {
          uVar8 = (uint)*(byte *)(lVar11 + 0xb38);
        }
        else {
          uVar8 = 0;
        }
        if (local_74 == *(int *)(lVar11 + 0x998) - uVar8) break;
        if ((0x10 < local_74) ||
           (*(undefined8 *)(lVar11 + (ulong)local_74 * 0x90 + 0x98) = 0xff00000008, 7 < local_80))
        goto LAB_00101fb4;
        puVar12 = *(undefined8 **)(lVar11 + local_80 * 8 + 0x58);
        pcVar7 = (code *)*puVar12;
        if (*(int *)(pcVar7 + -4) != -0x7e133f8b) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x101db4);
          (*pcVar7)();
        }
        (*pcVar7)(lVar11,local_88 & 0xffffffff,&local_74,0);
        uVar8 = local_74;
        local_74 = local_74 + 1;
        *(int *)(lVar11 + 0x99c) = *(int *)(lVar11 + 0x99c) + 1;
        _printk(&DAT_001063b9,uVar8,local_88,local_80);
        uVar8 = *(uint *)(lVar11 + 0x9a0);
        uVar9 = 1 << (ulong)((uint)local_80 & 0x1f);
        if (((uVar9 & uVar8) != 0) && (pcVar7 = (code *)puVar12[1], pcVar7 != (code *)0x0)) {
          if (*(int *)(pcVar7 + -4) != -0x969b12f) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x822a,0x101e1c);
            (*pcVar7)();
          }
          (*pcVar7)(lVar11,0);
          uVar8 = *(uint *)(lVar11 + 0x9a0);
          uVar9 = 1 << (ulong)((uint)local_80 & 0x1f);
        }
        *(uint *)(lVar11 + 0x9a0) = uVar8 & (uVar9 ^ 0xffffffff);
      } while (pcVar3 != (char *)0x0);
    }
LAB_00101e4c:
    if (local_74 == *(int *)(lVar11 + 0x998) - 1U) {
      iVar2 = 0x36020;
      if (*(int *)(lVar11 + 0xb4c) < 0x15) {
        iVar2 = 0x31020;
      }
      iVar1 = 0x66020;
      if (*(int *)(lVar11 + 0xb4c) != 0x33) {
        iVar1 = iVar2;
      }
      iVar1 = iVar1 + local_74 * 4;
      regmap_read(*(undefined8 *)(lVar11 + 8),iVar1,&local_78);
      if ((local_78 & 0x1000000) != 0) {
        regmap_write(*(undefined8 *)(lVar11 + 8),iVar1,0);
        local_74 = local_74 + 1;
      }
    }
    if (local_74 == *(uint *)(lVar11 + 0x998)) {
      _printk(&DAT_00105e1a);
      *(undefined8 *)(lVar11 + 0x998) = 0;
    }
  }
LAB_00101ed0:
  mutex_unlock(lVar11 + 0xab8);
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// perfmon_filter_config_store @ 00101fc0 size=876
// signature: undefined perfmon_filter_config_store(void)
// callers: []
//------------------------------------------------------------

undefined8
perfmon_filter_config_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  code *pcVar8;
  long lVar9;
  long lVar10;
  undefined *puVar11;
  long lVar12;
  uint uVar13;
  ulong local_88;
  ulong local_80;
  undefined8 uStack_78;
  char *local_70;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  lVar9 = *(long *)(param_1 + 0x98);
  local_80 = 0;
  uStack_78 = 0;
  local_88 = 0;
  local_70 = param_3;
  if (*(int *)(lVar9 + 0x998) != 0) {
    _printk(&DAT_001060ed);
    goto LAB_001022ec;
  }
  lVar1 = lVar9 + 0xab8;
  mutex_lock(lVar1);
  pcVar4 = strsep(&local_70," ");
  if ((pcVar4 == (char *)0x0) || (uVar2 = find_filter_type(), uVar2 == 0)) {
    puVar11 = &DAT_00105b37;
  }
  else {
    pcVar4 = strsep(&local_70," ");
    if (pcVar4 == (char *)0x0) {
LAB_00102228:
      puVar11 = &DAT_00106755;
    }
    else {
      iVar3 = kstrtoull(pcVar4,0,&local_80);
      if (iVar3 == 0) {
        if (uVar2 == 1) {
          uVar5 = 0x40;
          if (*(int *)(lVar9 + 0xb4c) != 0x33) {
            uVar5 = 0x20;
          }
          if (uVar5 <= local_80) {
            puVar11 = &DAT_00105e77;
            goto LAB_001022d0;
          }
        }
        pcVar4 = strsep(&local_70," ");
        if (pcVar4 == (char *)0x0) goto LAB_00102228;
        iVar3 = kstrtoull(pcVar4,0,&uStack_78);
        if (iVar3 == 0) {
          pcVar4 = strsep(&local_70," ");
          if (pcVar4 == (char *)0x0) {
            uVar13 = 0;
          }
          else {
            uVar13 = 0;
            puVar11 = &DAT_00105b78;
            do {
              uVar5 = sysfs_streq(pcVar4,"FILTER0");
              if ((uVar5 & 1) != 0) {
                uVar5 = 0;
LAB_0010228c:
                if (*(int *)(lVar9 + 0xab0) == 1) {
                  puVar11 = &DAT_00106189;
                  goto LAB_001022d0;
                }
                *(undefined4 *)(lVar9 + 0xab0) = 2;
                _printk(&DAT_0010623b);
                if (uVar13 == 0) goto LAB_001022bc;
                goto LAB_00102164;
              }
              uVar5 = sysfs_streq(pcVar4,"FILTER1");
              if ((uVar5 & 1) != 0) {
                uVar5 = 1;
                goto LAB_0010228c;
              }
              iVar3 = kstrtoull(pcVar4,0,&local_88);
              if (iVar3 != 0) goto LAB_001022d0;
              if (7 < local_88) {
                puVar11 = &DAT_0010609c;
                goto LAB_001022d0;
              }
              uVar13 = uVar13 | 1 << (ulong)((uint)local_88 & 0x1f);
              pcVar4 = strsep(&local_70," ");
            } while (pcVar4 != (char *)0x0);
          }
          if (*(int *)(lVar9 + 0xab0) == 2) {
            puVar11 = &DAT_00106200;
          }
          else {
            uVar5 = 0;
            if (uVar13 != 0) {
LAB_00102164:
              if (*(int *)(lVar9 + 0xab0) != 2) {
                *(undefined4 *)(lVar9 + 0xab0) = 1;
                _printk(&DAT_00105d2e);
              }
              lVar10 = 0;
              lVar12 = (uVar5 | (ulong)uVar2 << 1) + 0x9b0;
              do {
                lVar7 = *(long *)(lVar9 + lVar10 * 8 + 0x58);
                if (*(long *)(lVar7 + 0x10) != 0 &&
                    (uVar13 & 1 << (ulong)((uint)lVar10 & 0x1f)) != 0) {
                  *(char *)(lVar9 + lVar12) = (char)uVar2;
                  pcVar8 = *(code **)(lVar7 + 0x10);
                  if (*(int *)(pcVar8 + -4) != 0x3b4afb8e) {
                    /* WARNING: Does not return */
                    pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1021f0);
                    (*pcVar8)();
                  }
                  uVar6 = (*pcVar8)(lVar9,uVar2,local_80,uStack_78,1,uVar5);
                  if ((uVar6 & 1) == 0) goto LAB_001022d8;
                }
                lVar10 = lVar10 + 1;
                lVar12 = lVar12 + 0x20;
              } while (lVar10 != 8);
              lVar9 = lVar9 + uVar5 * 4;
              *(uint *)(lVar9 + 0x9a8) = *(uint *)(lVar9 + 0x9a8) | uVar13;
              mutex_unlock(lVar1);
              goto LAB_001022ec;
            }
LAB_001022bc:
            puVar11 = &DAT_00105f90;
          }
          goto LAB_001022d0;
        }
      }
      puVar11 = &DAT_00106556;
    }
  }
LAB_001022d0:
  _printk(puVar11);
LAB_001022d8:
  remove_filters(lVar9);
  mutex_unlock(lVar1);
  param_4 = 0xffffffffffffffea;
LAB_001022ec:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// find_filter_type @ 0010232c size=312
// signature: undefined find_filter_type(void)
// callers: [perfmon_filter_config_store, perfmon_filter_remove_store]
//------------------------------------------------------------

undefined4 find_filter_type(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(param_1,"SCID");
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    iVar1 = strcmp(param_1,"MID");
    if (iVar1 == 0) {
      uVar2 = 2;
    }
    else {
      iVar1 = strcmp(param_1,"PROFILING_TAG");
      if (iVar1 == 0) {
        uVar2 = 3;
      }
      else {
        iVar1 = strcmp(param_1,"WAY_ID");
        if (iVar1 == 0) {
          uVar2 = 4;
        }
        else {
          iVar1 = strcmp(param_1,"OPCODE");
          if (iVar1 == 0) {
            uVar2 = 5;
          }
          else {
            iVar1 = strcmp(param_1,"CACHEALLOC");
            if (iVar1 == 0) {
              uVar2 = 6;
            }
            else {
              iVar1 = strcmp(param_1,"MEMTAGOPS");
              if (iVar1 == 0) {
                uVar2 = 7;
              }
              else {
                iVar1 = strcmp(param_1,"MULTISCID");
                if (iVar1 == 0) {
                  uVar2 = 8;
                }
                else {
                  iVar1 = strcmp(param_1,"DIRTYINFO");
                  if (iVar1 == 0) {
                    uVar2 = 9;
                  }
                  else {
                    iVar1 = strcmp(param_1,"ADDR_MASK");
                    uVar2 = 10;
                    if (iVar1 != 0) {
                      uVar2 = 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// perfmon_filter_remove_store @ 00102468 size=1056
// signature: undefined perfmon_filter_remove_store(void)
// callers: []
//------------------------------------------------------------

undefined8
perfmon_filter_remove_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  ulong uVar6;
  undefined *puVar7;
  code *pcVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  uint uVar12;
  ulong uVar13;
  ulong local_88;
  ulong local_80 [2];
  char *pcStack_70;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  lVar9 = *(long *)(param_1 + 0x98);
  local_80[1] = 0;
  local_88 = 0;
  local_80[0] = 0;
  pcStack_70 = param_3;
  if (*(int *)(lVar9 + 0xab0) == 0) {
    puVar7 = &DAT_00106274;
  }
  else {
    if (*(int *)(lVar9 + 0x998) == 0) {
      mutex_lock(lVar9 + 0xab8);
      pcVar5 = strsep(&pcStack_70," ");
      if (pcVar5 == (char *)0x0) {
LAB_0010262c:
        puVar7 = &DAT_00105b37;
LAB_0010283c:
        _printk(puVar7);
      }
      else {
        uVar6 = sysfs_streq(pcVar5,"REMOVE");
        if ((uVar6 & 1) == 0) {
          uVar3 = find_filter_type(pcVar5);
          if (uVar3 == 0) goto LAB_0010262c;
          pcVar5 = strsep(&pcStack_70," ");
          if (pcVar5 == (char *)0x0) {
LAB_001027f0:
            puVar7 = &DAT_00106755;
          }
          else {
            iVar4 = kstrtoull(pcVar5,0,local_80);
            if (iVar4 == 0) {
              if (uVar3 == 1) {
                uVar6 = 0x40;
                if (*(int *)(lVar9 + 0xb4c) != 0x33) {
                  uVar6 = 0x20;
                }
                if (uVar6 <= local_80[0]) {
                  puVar7 = &DAT_00105e77;
                  goto LAB_0010283c;
                }
              }
              pcVar5 = strsep(&pcStack_70," ");
              if (pcVar5 == (char *)0x0) goto LAB_001027f0;
              iVar4 = kstrtoull(pcVar5,0,local_80 + 1);
              if (iVar4 == 0) {
                pcVar5 = strsep(&pcStack_70," ");
                if (pcVar5 == (char *)0x0) {
                  uVar12 = 0;
                }
                else {
                  uVar12 = 0;
                  do {
                    uVar6 = sysfs_streq(pcVar5,"FILTER0");
                    if ((uVar6 & 1) != 0) {
                      uVar6 = 0;
LAB_00102660:
                      if (*(int *)(lVar9 + 0xab0) != 1) goto LAB_0010266c;
                      _printk(&DAT_00105fd3);
                      goto LAB_00102840;
                    }
                    uVar6 = sysfs_streq(pcVar5,"FILTER1");
                    if ((uVar6 & 1) != 0) {
                      uVar6 = 1;
                      goto LAB_00102660;
                    }
                    iVar4 = kstrtoull(pcVar5,0,&local_88);
                    if (iVar4 != 0) goto LAB_00102624;
                    if (7 < local_88) {
                      puVar7 = &DAT_0010609c;
                      goto LAB_0010283c;
                    }
                    uVar12 = uVar12 | 1 << (ulong)((uint)local_88 & 0x1f);
                    pcVar5 = strsep(&pcStack_70," ");
                  } while (pcVar5 != (char *)0x0);
                }
                if (*(int *)(lVar9 + 0xab0) == 2) {
                  puVar7 = &DAT_00105ac2;
                  goto LAB_0010283c;
                }
LAB_00102624:
                uVar6 = 0;
LAB_0010266c:
                lVar10 = 0;
                puVar1 = (uint *)(lVar9 + uVar6 * 4 + 0x9a8);
                lVar11 = (uVar6 | (ulong)uVar3 << 1) + 0x9b0;
                uVar13 = uVar6 | 0x9ce;
                do {
                  uVar2 = 1 << (ulong)((uint)lVar10 & 0x1f);
                  if (((uVar12 & uVar2) != 0) &&
                     (pcVar8 = *(code **)(*(long *)(lVar9 + lVar10 * 8 + 0x58) + 0x10),
                     pcVar8 != (code *)0x0)) {
                    if (*(int *)(pcVar8 + -4) != 0x3b4afb8e) {
                    /* WARNING: Does not return */
                      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1026fc);
                      (*pcVar8)();
                    }
                    (*pcVar8)(lVar9,uVar3,0,0,0,uVar6);
                    *(undefined1 *)(lVar9 + lVar11) = 0;
                    if (((((((*(char *)(lVar9 + uVar13 + -0x1e) == '\0') &&
                            (*(char *)(lVar9 + uVar13 + -0x1c) == '\0')) &&
                           (*(char *)(lVar9 + uVar13 + -0x1a) == '\0')) &&
                          ((*(char *)(lVar9 + uVar13 + -0x18) == '\0' &&
                           (*(char *)(lVar9 + uVar13 + -0x16) == '\0')))) &&
                         ((*(char *)(lVar9 + uVar13 + -0x14) == '\0' &&
                          ((*(char *)(lVar9 + uVar13 + -0x12) == '\0' &&
                           (*(char *)(lVar9 + uVar13 + -0x10) == '\0')))))) &&
                        (*(char *)(lVar9 + uVar13 + -0xe) == '\0')) &&
                       ((((*(char *)(lVar9 + uVar13 + -0xc) == '\0' &&
                          (*(char *)(lVar9 + uVar13 + -10) == '\0')) &&
                         (*(char *)(lVar9 + uVar13 + -8) == '\0')) &&
                        (((*(char *)(lVar9 + uVar13 + -6) == '\0' &&
                          (*(char *)(lVar9 + uVar13 + -4) == '\0')) &&
                         ((*(char *)(lVar9 + uVar13 + -2) == '\0' &&
                          (*(char *)(lVar9 + uVar13) == '\0')))))))) {
                      uVar12 = uVar12 & ~uVar2;
                      *puVar1 = *puVar1 & (uVar2 ^ 0xffffffff);
                    }
                  }
                  lVar10 = lVar10 + 1;
                  lVar11 = lVar11 + 0x20;
                  uVar13 = uVar13 + 0x20;
                } while (lVar10 != 8);
                if ((*(int *)(lVar9 + 0x9a8) == 0) &&
                   ((*(int *)(lVar9 + 0xab0) == 2 && *(int *)(lVar9 + 0x9ac) == 0 ||
                    (*(int *)(lVar9 + 0xab0) == 1)))) {
                  *(undefined4 *)(lVar9 + 0xab0) = 0;
                }
                goto LAB_00102840;
              }
            }
            puVar7 = &DAT_00106556;
          }
          goto LAB_0010283c;
        }
        remove_filters(lVar9);
      }
LAB_00102840:
      mutex_unlock(lVar9 + 0xab8);
      goto LAB_00102848;
    }
    puVar7 = &DAT_001060ed;
  }
  _printk(puVar7);
LAB_00102848:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// perfmon_start_store @ 0010288c size=656
// signature: undefined perfmon_start_store(void)
// callers: []
//------------------------------------------------------------

undefined8
perfmon_start_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  code *pcVar6;
  uint uVar7;
  long lVar8;
  undefined8 uVar9;
  long lVar10;
  uint uVar11;
  long local_68;
  uint local_5c;
  long local_58;
  
  lVar10 = sp_el0;
  local_58 = *(long *)(lVar10 + 0x638);
  lVar10 = *(long *)(param_1 + 0x98);
  local_68 = 0;
  iVar4 = kstrtoull(param_3,0,&local_68);
  if (iVar4 != 0) {
    param_4 = 0xffffffffffffffea;
    goto LAB_00102ab0;
  }
  if (*(int *)(lVar10 + 0x998) == 0) {
    puVar5 = &DAT_00106161;
LAB_00102b0c:
    _printk(puVar5);
    param_4 = 0xffffffffffffffea;
  }
  else {
    lVar1 = lVar10 + 0xab8;
    mutex_lock(lVar1);
    if (local_68 == 0) {
      if (*(long *)(lVar10 + 0xb30) != 0) {
        hrtimer_cancel(lVar10 + 0xae8);
      }
      uVar11 = 0;
      uVar7 = 0xf;
    }
    else {
      lVar8 = *(long *)(lVar10 + 0xb40);
      if (lVar8 != 0) {
        iVar4 = clk_prepare(lVar8);
        if (iVar4 == 0) {
          iVar4 = clk_enable(lVar8);
          if (iVar4 == 0) {
            *(undefined1 *)(lVar10 + 0xb48) = 1;
            goto LAB_00102928;
          }
          clk_unprepare(lVar8);
        }
        mutex_unlock(lVar1);
        puVar5 = &DAT_00106665;
        goto LAB_00102b0c;
      }
LAB_00102928:
      lVar8 = *(long *)(lVar10 + 0xb30);
      if (lVar8 != 0) {
        if ((*(byte *)(lVar10 + 0xb20) & 1) == 0) {
          hrtimer_start_range_ns(lVar10 + 0xae8,lVar8,0,3);
        }
        else {
          pcVar6 = *(code **)(*(long *)(lVar10 + 0xb18) + 0x30);
          if (*(int *)(pcVar6 + -4) != 0x7230bf2a) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102990);
            (*pcVar6)();
          }
          uVar9 = (*pcVar6)();
          hrtimer_forward(lVar10 + 0xae8,uVar9,lVar8);
        }
      }
      uVar11 = 0x8000;
      uVar7 = *(int *)(lVar10 + 0x998) - 1U & 0xf;
    }
    uVar2 = 0x3600c;
    if (*(int *)(lVar10 + 0xb4c) < 0x15) {
      uVar2 = 0x3100c;
    }
    uVar3 = 0x6600c;
    if (*(int *)(lVar10 + 0xb4c) != 0x33) {
      uVar3 = uVar2;
    }
    if (*(long *)(lVar10 + 0xb40) == 0) {
      local_5c = 0;
      regmap_read(*(undefined8 *)(lVar10 + 8),uVar3,&local_5c);
      local_5c = local_5c & 0xffff5ffe | uVar11;
      regmap_write(*(undefined8 *)(lVar10 + 8),uVar3);
    }
    else if (*(char *)(lVar10 + 0xb48) != '\0') {
      local_5c = 0;
      regmap_read(*(undefined8 *)(lVar10 + 8),uVar3,&local_5c);
      local_5c = local_5c & 0xffff5ffe | uVar11;
      regmap_write(*(undefined8 *)(lVar10 + 8),uVar3);
      if (local_68 == 0) {
        uVar9 = *(undefined8 *)(lVar10 + 0xb40);
        clk_disable(uVar9);
        clk_unprepare(uVar9);
        *(undefined1 *)(lVar10 + 0xb48) = 0;
      }
    }
    uVar2 = 0x360ec;
    if (*(int *)(lVar10 + 0xb4c) < 0x15) {
      uVar2 = 0x310ec;
    }
    uVar3 = 0x660ec;
    if (*(int *)(lVar10 + 0xb4c) != 0x33) {
      uVar3 = uVar2;
    }
    regmap_write(*(undefined8 *)(lVar10 + 8),uVar3,uVar7);
    mutex_unlock(lVar1);
  }
LAB_00102ab0:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// perfmon_scid_status_show @ 00102b20 size=500
// signature: undefined perfmon_scid_status_show(void)
// callers: []
//------------------------------------------------------------

long perfmon_scid_status_show(long param_1,undefined8 param_2,long param_3)

{
  undefined4 uVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  code *pcVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  long lVar10;
  long lVar11;
  undefined8 *puVar12;
  ulong uVar13;
  uint local_6c;
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  puVar12 = *(undefined8 **)(param_1 + 0x98);
  local_6c = 0;
  if (*(char *)(puVar12 + 0x16b) != '\0') {
    uVar1 = 0x452a4;
    if (*(int *)((long)puVar12 + 0xb4c) != 0x33) {
      uVar1 = 0x2332c;
    }
    regmap_write(puVar12[1],uVar1,1);
    uVar1 = 0x452a4;
    if (*(int *)((long)puVar12 + 0xb4c) != 0x33) {
      uVar1 = 0x2332c;
    }
    regmap_write(puVar12[1],uVar1,0);
  }
  lVar10 = 0;
  uVar9 = 0;
  bVar6 = *(int *)((long)puVar12 + 0xb4c) == 0x33;
  do {
    uVar4 = uVar9 << 0xc | 4;
    uVar8 = 0x7ffff;
    if (!bVar6) {
      uVar8 = 0x7fff0000;
    }
    iVar7 = 0;
    uVar2 = uVar9 << 0xc | 0x1c;
    if (!bVar6) {
      iVar7 = 0x10;
      uVar2 = uVar4;
    }
    if (*(int *)(puVar12 + 10) == 0) {
      lVar11 = 0;
    }
    else {
      uVar13 = 0;
      lVar11 = 0;
      do {
        if (uVar13 == 0x10) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x102d10);
          (*pcVar5)();
        }
        regmap_read(*puVar12,*(int *)((long)puVar12 + uVar13 * 4 + 0x10) + uVar2,&local_6c);
        uVar13 = uVar13 + 1;
        local_6c = (local_6c & uVar8) >> iVar7;
        lVar11 = lVar11 + (ulong)local_6c;
      } while (uVar13 < *(uint *)(puVar12 + 10));
    }
    regmap_read(puVar12[1],uVar4,&local_6c);
    pcVar3 = "DEACTIVE";
    if ((local_6c & 1) != 0) {
      pcVar3 = "ACTIVE";
    }
    iVar7 = scnprintf(param_3 + lVar10,0x1000 - lVar10,"SCID %02d %10s",uVar9,pcVar3);
    lVar10 = lVar10 + iVar7;
    iVar7 = scnprintf(param_3 + lVar10,0x1000 - lVar10,",0x%08lx\n",lVar11);
    lVar10 = lVar10 + iVar7;
    uVar9 = uVar9 + 1;
    bVar6 = *(int *)((long)puVar12 + 0xb4c) == 0x33;
    uVar8 = 0x40;
    if (!bVar6) {
      uVar8 = 0x20;
    }
  } while (uVar9 < uVar8);
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar10;
}



//------------------------------------------------------------
// perfmon_ns_periodic_dump_store @ 00102d18 size=220
// signature: undefined perfmon_ns_periodic_dump_store(void)
// callers: []
//------------------------------------------------------------

undefined8
perfmon_ns_periodic_dump_store
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  code *pcVar4;
  long lVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x98);
  iVar2 = kstrtoll(param_3,0,lVar6 + 0xb30);
  if (iVar2 == 0) {
    mutex_lock(lVar6 + 0xab8);
    lVar5 = *(long *)(lVar6 + 0xb30);
    lVar1 = lVar6 + 0xae8;
    if (lVar5 == 0) {
      hrtimer_cancel(lVar1);
    }
    else if ((*(byte *)(lVar6 + 0xb20) & 1) == 0) {
      hrtimer_start_range_ns(lVar1,lVar5,0,3);
    }
    else {
      pcVar4 = *(code **)(*(long *)(lVar6 + 0xb18) + 0x30);
      if (*(int *)(pcVar4 + -4) != 0x7230bf2a) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x102dbc);
        (*pcVar4)();
      }
      uVar3 = (*pcVar4)();
      hrtimer_forward(lVar1,uVar3,lVar5);
    }
    mutex_unlock(lVar6 + 0xab8);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  return param_4;
}



//------------------------------------------------------------
// perfmon_beac_mc_proftag_store @ 00102df8 size=276
// signature: undefined perfmon_beac_mc_proftag_store(void)
// callers: []
//------------------------------------------------------------

undefined8
perfmon_beac_mc_proftag_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  int iVar2;
  undefined *puVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x98);
  puVar1 = (undefined8 *)(lVar4 + 0xb50);
  iVar2 = kstrtoull(param_3,0,puVar1);
  if (iVar2 != 0) {
    return 0xffffffffffffffea;
  }
  mutex_lock(lVar4 + 0xab8);
  switch(*(undefined8 *)(lVar4 + 0xb50)) {
  case 0:
    if ((*(byte *)(lVar4 + 0x9a8) & 1) != 0) {
      *puVar1 = 0;
      goto switchD_00102e60_default;
    }
    puVar3 = &DAT_00105bf8;
    break;
  case 1:
    if ((*(byte *)(lVar4 + 0x9ac) & 1) != 0) {
      *puVar1 = 1;
      goto switchD_00102e60_default;
    }
    puVar3 = &DAT_00105c40;
    break;
  case 2:
    *(undefined8 *)(lVar4 + 0xb50) = 2;
    if ((*(uint *)(lVar4 + 0x9a8) >> 3 & 1) != 0) goto switchD_00102e60_default;
    puVar3 = &DAT_00106013;
    goto LAB_00102ee8;
  case 3:
    if ((*(byte *)(lVar4 + 0x9ac) >> 3 & 1) != 0) {
      *puVar1 = 3;
      goto switchD_00102e60_default;
    }
    puVar3 = &DAT_0010641b;
    break;
  default:
    goto switchD_00102e60_default;
  }
  *puVar1 = 2;
LAB_00102ee8:
  _printk(puVar3);
switchD_00102e60_default:
  mutex_unlock(lVar4 + 0xab8);
  return param_4;
}



//------------------------------------------------------------
// feac_event_config @ 00102f10 size=496
// signature: undefined feac_event_config(void)
// callers: []
//------------------------------------------------------------

void feac_event_config(long param_1,uint param_2,uint *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  uint uVar9;
  uint local_4c;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  if (*(int *)(param_1 + 0xab0) == 2) {
    if (0xf < *param_3) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x103100);
      (*pcVar3)();
    }
    lVar7 = param_1 + (ulong)*param_3 * 0x90;
    uVar5 = (uint)*(byte *)(lVar7 + 0xa0);
    uVar6 = (uint)*(byte *)(lVar7 + 0xa1);
  }
  else {
    uVar6 = 0;
    uVar5 = *(uint *)(param_1 + 0x9a8) & 1;
  }
  uVar8 = 0xff;
  if (*(uint *)(param_1 + 0xb3c) != 5) {
    uVar8 = 0x7f;
  }
  if (*(uint *)(param_1 + 0xb3c) < 2) {
    uVar8 = 0x3f;
  }
  if ((param_4 & 1) == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = uVar8 & param_2;
    if (uVar5 != 0) {
      if (((param_2 - 0xe < 4) && (uVar6 == 1)) || ((param_2 - 0x6f < 4 && (uVar6 == 0)))) {
        _printk(&DAT_00105c88);
        uVar4 = 0;
        goto LAB_001030b4;
      }
      if ((3 < param_2 - 0xe) && (3 < param_2 - 0x6f)) {
        uVar9 = uVar9 | uVar6 << 0x10 | 0x80000000;
      }
    }
  }
  if (uVar5 != 0) {
    uVar8 = uVar8 | 0x80010000;
  }
  iVar2 = 0x43060;
  if (*(int *)(param_1 + 0xb4c) < 0x15) {
    iVar2 = 0x37060;
  }
  iVar1 = 0x73060;
  if (*(int *)(param_1 + 0xb4c) != 0x33) {
    iVar1 = iVar2;
  }
  iVar1 = iVar1 + *param_3 * 4;
  local_4c = 0;
  regmap_read(*(undefined8 *)(param_1 + 8),iVar1,&local_4c);
  local_4c = local_4c & (uVar8 ^ 0xffffffff) | uVar9 & uVar8;
  regmap_write(*(undefined8 *)(param_1 + 8),iVar1);
  uVar5 = *param_3;
  if (uVar5 < 0x10) {
    uVar6 = (uVar5 & 0x1f) << 0x10 | 0xc0000000;
    if ((param_4 & 1) == 0) {
      uVar6 = 0;
    }
    iVar2 = 0x36020;
    if (*(int *)(param_1 + 0xb4c) < 0x15) {
      iVar2 = 0x31020;
    }
    iVar1 = 0x66020;
    if (*(int *)(param_1 + 0xb4c) != 0x33) {
      iVar1 = iVar2;
    }
    regmap_write(*(undefined8 *)(param_1 + 8),iVar1 + uVar5 * 4,uVar6);
  }
  uVar4 = 1;
LAB_001030b4:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// feac_event_enable @ 00103104 size=484
// signature: undefined feac_event_enable(void)
// callers: []
//------------------------------------------------------------

void feac_event_enable(long param_1,ulong param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  long lVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint local_5c;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  uVar8 = 0xfffff01;
  uVar6 = 0x4002001;
  if (((*(uint *)(param_1 + 0x9a8) | *(uint *)(param_1 + 0x9ac)) & 1) == 0) {
LAB_0010325c:
    if ((param_2 & 1) == 0) {
      uVar6 = 0;
    }
  }
  else {
    if (*(int *)(param_1 + 0xb3c) == 0) {
      uVar6 = 0x4002003;
      uVar8 = 0xfffff07;
      goto LAB_0010325c;
    }
    uVar4 = 0x3400207e;
    uVar1 = *(uint *)(param_1 + 0x9a8) & 1;
    uVar8 = 0x3400207f;
    if (uVar1 != 0) {
      uVar8 = 0x1400202b;
    }
    uVar2 = *(uint *)(param_1 + 0x9ac) & 1;
    uVar6 = 0x1400202b;
    if (uVar2 != 0) {
      uVar6 = uVar8;
    }
    if ((param_2 & 1) == 0) {
      uVar6 = 0;
    }
    uVar8 = 0x3fffff7f;
    if (((*(int *)(param_1 + 0xb3c) != 1) && (uVar1 != 0)) && (uVar2 != 0)) {
      if ((param_2 & 1) == 0) {
        uVar4 = 0;
      }
      local_5c = 0;
      uVar3 = 0x430a0;
      if (*(int *)(param_1 + 0xb4c) < 0x15) {
        uVar3 = 0x370a0;
      }
      uVar7 = 0x730a0;
      if (*(int *)(param_1 + 0xb4c) != 0x33) {
        uVar7 = uVar3;
      }
      regmap_read(*(undefined8 *)(param_1 + 8),uVar7,&local_5c);
      local_5c = local_5c & 0xc0000080 | uVar6;
      regmap_write(*(undefined8 *)(param_1 + 8),uVar7);
      local_5c = 0;
      uVar3 = 0x430a4;
      if (*(int *)(param_1 + 0xb4c) < 0x15) {
        uVar3 = 0x370a4;
      }
      uVar7 = 0x730a4;
      if (*(int *)(param_1 + 0xb4c) != 0x33) {
        uVar7 = uVar3;
      }
      regmap_read(*(undefined8 *)(param_1 + 8),uVar7,&local_5c);
      local_5c = local_5c & 0xc0000081 | uVar4;
      goto LAB_001032a0;
    }
  }
  local_5c = 0;
  uVar3 = 0x430a0;
  if (*(int *)(param_1 + 0xb4c) < 0x15) {
    uVar3 = 0x370a0;
  }
  uVar7 = 0x730a0;
  if (*(int *)(param_1 + 0xb4c) != 0x33) {
    uVar7 = uVar3;
  }
  regmap_read(*(undefined8 *)(param_1 + 8),uVar7,&local_5c);
  local_5c = local_5c & (uVar8 ^ 0xffffffff) | uVar8 & uVar6;
LAB_001032a0:
  regmap_write(*(undefined8 *)(param_1 + 8),uVar7);
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// feac_event_filter_config @ 001032ec size=1116
// signature: undefined feac_event_filter_config(void)
// callers: []
//------------------------------------------------------------

uint feac_event_filter_config
               (long param_1,undefined4 param_2,ulong param_3,ulong param_4,uint param_5,
               char param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint local_5c;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  switch(param_2) {
  case 1:
    uVar5 = 1;
    goto LAB_00103508;
  case 2:
    iVar6 = *(int *)(param_1 + 0xb4c);
    uVar11 = (uint)param_3 | (uint)(param_4 << 0x10);
    if ((param_5 & 1) == 0) {
      uVar11 = 0;
    }
    uVar1 = 0x43014;
    if (iVar6 < 0x15) {
      uVar1 = 0x37014;
    }
    uVar8 = 0x73014;
    if (iVar6 != 0x33) {
      uVar8 = uVar1;
    }
    if (param_6 != '\0') {
      uVar1 = 0x43044;
      if (iVar6 < 0x15) {
        uVar1 = 0x37044;
      }
      uVar8 = 0x73044;
      if (iVar6 != 0x33) {
        uVar8 = uVar1;
      }
    }
    uVar7 = 0xffffffff;
    break;
  default:
    _printk(&DAT_00106528);
    uVar11 = 0;
    goto LAB_001036f8;
  case 5:
    iVar6 = *(int *)(param_1 + 0xb4c);
    uVar11 = (uint)(param_4 << 0x1c) | (uint)(param_3 << 0x18);
    if ((param_5 & 1) == 0) {
      uVar11 = 0;
    }
    uVar1 = 0x4300c;
    if (iVar6 < 0x15) {
      uVar1 = 0x3700c;
    }
    uVar8 = 0x7300c;
    if (iVar6 != 0x33) {
      uVar8 = uVar1;
    }
    if (param_6 == '\0') {
      uVar7 = 0xff000000;
    }
    else {
      uVar1 = 0x4303c;
      if (iVar6 < 0x15) {
        uVar1 = 0x3703c;
      }
      uVar8 = 0x7303c;
      if (iVar6 != 0x33) {
        uVar8 = uVar1;
      }
      uVar7 = 0xff000000;
    }
    break;
  case 6:
    iVar6 = *(int *)(param_1 + 0xb4c);
    uVar11 = (uint)(param_4 << 0x10) | (uint)(param_3 << 0xc);
    if ((param_5 & 1) == 0) {
      uVar11 = 0;
    }
    uVar1 = 0x4300c;
    if (iVar6 < 0x15) {
      uVar1 = 0x3700c;
    }
    uVar8 = 0x7300c;
    if (iVar6 != 0x33) {
      uVar8 = uVar1;
    }
    if (param_6 == '\0') {
      uVar7 = 0xff000;
    }
    else {
      uVar1 = 0x4303c;
      if (iVar6 < 0x15) {
        uVar1 = 0x3703c;
      }
      uVar8 = 0x7303c;
      if (iVar6 != 0x33) {
        uVar8 = uVar1;
      }
      uVar7 = 0xff000;
    }
    break;
  case 7:
    iVar6 = *(int *)(param_1 + 0xb4c);
    uVar11 = (uint)(param_4 << 0xc) | (uint)(param_3 << 10);
    if ((param_5 & 1) == 0) {
      uVar11 = 0;
    }
    uVar1 = 0x4301c;
    if (iVar6 < 0x15) {
      uVar1 = 0x3701c;
    }
    uVar8 = 0x7301c;
    if (iVar6 != 0x33) {
      uVar8 = uVar1;
    }
    if (param_6 == '\0') {
      uVar7 = 0x7c00;
    }
    else {
      uVar7 = 0x7c00;
LAB_00103574:
      uVar1 = 0x4304c;
      if (iVar6 < 0x15) {
        uVar1 = 0x3704c;
      }
      uVar8 = 0x7304c;
      if (iVar6 != 0x33) {
        uVar8 = uVar1;
      }
    }
    break;
  case 8:
    uVar5 = 8;
LAB_00103508:
    uVar11 = feac_scid_multiscid_set_remove(param_1,uVar5,param_3,param_4,param_5 & 1);
    goto LAB_001036f8;
  case 9:
    iVar6 = *(int *)(param_1 + 0xb4c);
    uVar11 = (uint)param_3 | (uint)(param_4 << 1);
    if ((param_5 & 1) == 0) {
      uVar11 = 0;
    }
    uVar1 = 0x4301c;
    if (iVar6 < 0x15) {
      uVar1 = 0x3701c;
    }
    uVar8 = 0x7301c;
    if (iVar6 != 0x33) {
      uVar8 = uVar1;
    }
    if (param_6 != '\0') {
      uVar7 = 7;
      goto LAB_00103574;
    }
    uVar7 = 7;
    break;
  case 10:
    if ((param_5 & 1) == 0) {
      uVar11 = 0;
      param_4 = 0;
      param_3 = 0;
    }
    else {
      uVar11 = (uint)(param_4 >> 0x1c) & 0xf0 | (uint)(param_3 >> 0x20) & 0xf;
    }
    iVar6 = *(int *)(param_1 + 0xb4c);
    uVar1 = 0x4300c;
    uVar2 = 0x43008;
    uVar4 = 0x43004;
    if (iVar6 < 0x15) {
      uVar1 = 0x3700c;
      uVar2 = 0x37008;
      uVar4 = 0x37004;
    }
    uVar8 = 0x7300c;
    uVar9 = 0x73008;
    uVar10 = 0x73004;
    if (iVar6 != 0x33) {
      uVar8 = uVar1;
      uVar9 = uVar2;
      uVar10 = uVar4;
    }
    if (param_6 != '\0') {
      uVar1 = 0x43034;
      if (iVar6 < 0x15) {
        uVar1 = 0x37034;
      }
      uVar2 = 0x4303c;
      uVar4 = 0x43038;
      if (iVar6 < 0x15) {
        uVar2 = 0x3703c;
        uVar4 = 0x37038;
      }
      uVar8 = 0x7303c;
      uVar9 = 0x73038;
      uVar10 = 0x73034;
      if (iVar6 != 0x33) {
        uVar8 = uVar2;
        uVar9 = uVar4;
        uVar10 = uVar1;
      }
    }
    local_5c = 0;
    regmap_read(*(undefined8 *)(param_1 + 8),uVar10,&local_5c);
    local_5c = (uint)param_3;
    regmap_write(*(undefined8 *)(param_1 + 8),uVar10,param_3 & 0xffffffff);
    local_5c = 0;
    regmap_read(*(undefined8 *)(param_1 + 8),uVar9,&local_5c);
    local_5c = (uint)param_4;
    regmap_write(*(undefined8 *)(param_1 + 8),uVar9,param_4 & 0xffffffff);
    uVar7 = 0x1ff;
  }
  local_5c = 0;
  regmap_read(*(undefined8 *)(param_1 + 8),uVar8,&local_5c);
  local_5c = local_5c & (uVar7 ^ 0xffffffff) | uVar7 & uVar11;
  regmap_write(*(undefined8 *)(param_1 + 8),uVar8);
  uVar11 = 1;
LAB_001036f8:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11 & 1;
}



//------------------------------------------------------------
// feac_scid_multiscid_set_remove @ 00103748 size=520
// signature: undefined feac_scid_multiscid_set_remove(void)
// callers: [feac_event_filter_config]
//------------------------------------------------------------

void feac_scid_multiscid_set_remove
               (long param_1,int param_2,ulong param_3,int param_4,uint param_5,char param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  bool bVar6;
  undefined8 uVar7;
  long lVar8;
  uint uVar9;
  uint uVar10;
  uint local_5c;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  uVar9 = (uint)param_3;
  if (param_2 == 8) {
    if (*(int *)(param_1 + 0xb4c) == 0x33) {
      if ((param_5 & 1) == 0) {
LAB_00103804:
        uVar9 = 0xffffffff;
        uVar10 = 0xffffffff;
        bVar6 = true;
      }
      else {
        uVar10 = (uint)(param_3 >> 0x20);
        bVar6 = true;
      }
      goto LAB_00103834;
    }
    if ((param_5 & 1) == 0) {
      param_3 = 0xffffffff;
    }
    uVar9 = (uint)param_3;
    bVar6 = *(int *)(param_1 + 0xb3c) != 0;
    if (!bVar6) {
      uVar9 = 0;
    }
  }
  else {
    if (param_2 != 1) {
      _printk(&DAT_00106528);
      uVar7 = 0;
      goto LAB_001038ec;
    }
    if (*(int *)(param_1 + 0xb3c) == 0) {
      uVar9 = uVar9 | param_4 << 0x10;
      if ((param_5 & 1) == 0) {
        uVar9 = 0;
      }
      if (*(int *)(param_1 + 0xb4c) == 0x33) {
        bVar6 = false;
        uVar10 = 0;
        goto LAB_00103834;
      }
    }
    else {
      if (*(int *)(param_1 + 0xb4c) != 0x33) {
        bVar6 = true;
        if ((param_5 & 1) == 0) {
          uVar9 = 0xffffffff;
        }
        else {
          uVar9 = 1 << (ulong)(uVar9 & 0x1f);
        }
        goto LAB_00103878;
      }
      if ((param_5 & 1) == 0) goto LAB_00103804;
      bVar6 = true;
      lVar8 = 1L << (param_3 & 0x3f);
      uVar9 = (uint)lVar8;
      uVar10 = (uint)((ulong)lVar8 >> 0x20);
LAB_00103834:
      uVar1 = 0x7302c;
      if (param_6 != '\0') {
        uVar1 = 0x7305c;
      }
      local_5c = 0;
      regmap_read(*(undefined8 *)(param_1 + 8),uVar1,&local_5c);
      if (!bVar6) {
        uVar10 = local_5c;
      }
      local_5c = uVar10;
      regmap_write(*(undefined8 *)(param_1 + 8),uVar1);
    }
    bVar6 = true;
  }
LAB_00103878:
  iVar4 = *(int *)(param_1 + 0xb4c);
  uVar1 = 0x43048;
  if (iVar4 < 0x15) {
    uVar1 = 0x37048;
  }
  uVar2 = 0x43018;
  if (iVar4 < 0x15) {
    uVar2 = 0x37018;
  }
  uVar3 = 0x73018;
  uVar5 = 0x73048;
  if (iVar4 != 0x33) {
    uVar3 = uVar2;
    uVar5 = uVar1;
  }
  if (param_6 != '\0') {
    uVar3 = uVar5;
  }
  local_5c = 0;
  regmap_read(*(undefined8 *)(param_1 + 8),uVar3,&local_5c);
  if (!bVar6) {
    uVar9 = local_5c;
  }
  local_5c = uVar9;
  regmap_write(*(undefined8 *)(param_1 + 8),uVar3);
  uVar7 = 1;
LAB_001038ec:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// ferc_event_config @ 00103954 size=404
// signature: undefined ferc_event_config(void)
// callers: []
//------------------------------------------------------------

undefined8 ferc_event_config(long param_1,uint param_2,uint *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  uint uVar9;
  uint local_5c;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  if (*(int *)(param_1 + 0xab0) == 2) {
    uVar6 = *param_3;
    if (0xf < uVar6) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x103ae8);
      (*pcVar5)();
    }
    lVar8 = param_1 + (ulong)uVar6 * 0x90;
    uVar9 = (uint)*(byte *)(lVar8 + 0xa0);
    uVar7 = (uint)*(byte *)(lVar8 + 0xa1) << 0x10 | 0x80000000;
  }
  else {
    uVar7 = 0x80000000;
    uVar9 = *(uint *)(param_1 + 0x9a8) & 2;
    uVar6 = *param_3;
  }
  uVar2 = 0x3f;
  if (uVar9 != 0) {
    uVar2 = 0x8001003f;
  }
  uVar4 = 0;
  if (uVar9 != 0) {
    uVar4 = uVar7;
  }
  uVar4 = uVar4 | param_2 & 0x3f;
  if ((param_4 & 1) == 0) {
    uVar4 = 0;
  }
  iVar3 = 0x49020;
  if (*(int *)(param_1 + 0xb4c) < 0x15) {
    iVar3 = 0x3b020;
  }
  iVar1 = 0x79020;
  if (*(int *)(param_1 + 0xb4c) != 0x33) {
    iVar1 = iVar3;
  }
  local_5c = 0;
  iVar1 = iVar1 + uVar6 * 4;
  regmap_read(*(undefined8 *)(param_1 + 8),iVar1,&local_5c);
  local_5c = local_5c & (uVar2 ^ 0xffffffff) | uVar4 & uVar2;
  regmap_write(*(undefined8 *)(param_1 + 8),iVar1);
  uVar9 = *param_3;
  if (uVar9 < 0x10) {
    uVar6 = (uVar9 & 0x1f) << 0x10 | 0xc0000001;
    if ((param_4 & 1) == 0) {
      uVar6 = 0;
    }
    iVar3 = 0x36020;
    if (*(int *)(param_1 + 0xb4c) < 0x15) {
      iVar3 = 0x31020;
    }
    iVar1 = 0x66020;
    if (*(int *)(param_1 + 0xb4c) != 0x33) {
      iVar1 = iVar3;
    }
    regmap_write(*(undefined8 *)(param_1 + 8),iVar1 + uVar9 * 4,uVar6);
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// ferc_event_enable @ 00103aec size=192
// signature: undefined ferc_event_enable(void)
// callers: []
//------------------------------------------------------------

void ferc_event_enable(long param_1,ulong param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  long lVar4;
  uint local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  uVar3 = 0x4002001;
  if ((param_2 & 1) == 0) {
    uVar3 = 0;
  }
  local_3c = 0;
  uVar1 = 0x49060;
  if (*(int *)(param_1 + 0xb4c) < 0x15) {
    uVar1 = 0x3b060;
  }
  uVar2 = 0x79060;
  if (*(int *)(param_1 + 0xb4c) != 0x33) {
    uVar2 = uVar1;
  }
  regmap_read(*(undefined8 *)(param_1 + 8),uVar2,&local_3c);
  local_3c = local_3c & 0xf00000fe | uVar3;
  regmap_write(*(undefined8 *)(param_1 + 8),uVar2);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ferc_event_filter_config @ 00103bb0 size=272
// signature: undefined ferc_event_filter_config(void)
// callers: []
//------------------------------------------------------------

void ferc_event_filter_config
               (long param_1,int param_2,uint param_3,int param_4,uint param_5,char param_6)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  uint local_4c;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  if (param_2 == 3) {
    iVar5 = *(int *)(param_1 + 0xb4c);
    uVar2 = 0x49010;
    uVar3 = 0x49000;
    if (iVar5 < 0x15) {
      uVar2 = 0x3b010;
      uVar3 = 0x3b000;
    }
    uVar4 = 0x79000;
    if (iVar5 != 0x33) {
      uVar4 = uVar3;
    }
    uVar3 = 0x79010;
    if (iVar5 != 0x33) {
      uVar3 = uVar2;
    }
    if (param_6 != '\0') {
      uVar4 = uVar3;
    }
    local_4c = 0;
    regmap_read(*(undefined8 *)(param_1 + 8),uVar4,&local_4c);
    uVar1 = (param_3 | param_4 << 2) & 0xf;
    if ((param_5 & 1) == 0) {
      uVar1 = 0;
    }
    local_4c = local_4c & 0xfffffff0 | uVar1;
    regmap_write(*(undefined8 *)(param_1 + 8),uVar4);
  }
  else {
    _printk(&DAT_00106528);
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_2 == 3);
  }
  return;
}



//------------------------------------------------------------
// fewc_event_config @ 00103cc4 size=396
// signature: undefined fewc_event_config(void)
// callers: []
//------------------------------------------------------------

undefined8 fewc_event_config(long param_1,uint param_2,uint *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  uint uVar9;
  uint local_5c;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  if (*(int *)(param_1 + 0xab0) == 2) {
    uVar6 = *param_3;
    if (0xf < uVar6) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x103e50);
      (*pcVar5)();
    }
    lVar8 = param_1 + (ulong)uVar6 * 0x90;
    uVar9 = (uint)*(byte *)(lVar8 + 0xa0);
    uVar7 = (uint)*(byte *)(lVar8 + 0xa1) << 0x10 | 0x80000000;
  }
  else {
    uVar7 = 0x80000000;
    uVar9 = *(uint *)(param_1 + 0x9a8) & 4;
    uVar6 = *param_3;
  }
  uVar2 = 0x3f;
  if (uVar9 != 0) {
    uVar2 = 0x8001003f;
  }
  uVar4 = 0;
  if (uVar9 != 0) {
    uVar4 = uVar7;
  }
  uVar4 = uVar4 | param_2 & 0x3f;
  if ((param_4 & 1) == 0) {
    uVar4 = 0;
  }
  iVar3 = 0x39020;
  if (*(int *)(param_1 + 0xb4c) < 0x15) {
    iVar3 = 0x33020;
  }
  iVar1 = 0x69020;
  if (*(int *)(param_1 + 0xb4c) != 0x33) {
    iVar1 = iVar3;
  }
  iVar1 = iVar1 + uVar6 * 4;
  local_5c = 0;
  regmap_read(*(undefined8 *)(param_1 + 8),iVar1,&local_5c);
  local_5c = local_5c & (uVar2 ^ 0xffffffff) | uVar4 & uVar2;
  regmap_write(*(undefined8 *)(param_1 + 8),iVar1);
  uVar9 = *param_3;
  if (uVar9 < 0x10) {
    uVar6 = (uVar9 & 0x1f) << 0x10 | 0xc0000002;
    if ((param_4 & 1) == 0) {
      uVar6 = 0;
    }
    iVar3 = 0x36020;
    if (*(int *)(param_1 + 0xb4c) < 0x15) {
      iVar3 = 0x31020;
    }
    iVar1 = 0x66020;
    if (*(int *)(param_1 + 0xb4c) != 0x33) {
      iVar1 = iVar3;
    }
    regmap_write(*(undefined8 *)(param_1 + 8),iVar1 + uVar9 * 4,uVar6);
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// fewc_event_filter_config @ 00103e54 size=272
// signature: undefined fewc_event_filter_config(void)
// callers: []
//------------------------------------------------------------

void fewc_event_filter_config
               (long param_1,int param_2,uint param_3,int param_4,uint param_5,char param_6)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  uint local_4c;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  if (param_2 == 3) {
    iVar5 = *(int *)(param_1 + 0xb4c);
    uVar2 = 0x39010;
    uVar3 = 0x39000;
    if (iVar5 < 0x15) {
      uVar2 = 0x33010;
      uVar3 = 0x33000;
    }
    uVar4 = 0x69000;
    if (iVar5 != 0x33) {
      uVar4 = uVar3;
    }
    uVar3 = 0x69010;
    if (iVar5 != 0x33) {
      uVar3 = uVar2;
    }
    if (param_6 != '\0') {
      uVar4 = uVar3;
    }
    local_4c = 0;
    regmap_read(*(undefined8 *)(param_1 + 8),uVar4,&local_4c);
    uVar1 = (param_3 | param_4 << 2) & 0xf;
    if ((param_5 & 1) == 0) {
      uVar1 = 0;
    }
    local_4c = local_4c & 0xfffffff0 | uVar1;
    regmap_write(*(undefined8 *)(param_1 + 8),uVar4);
  }
  else {
    _printk(&DAT_00106528);
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_2 == 3);
  }
  return;
}



//------------------------------------------------------------
// beac_event_config @ 00103f68 size=712
// signature: undefined beac_event_config(void)
// callers: []
//------------------------------------------------------------

void beac_event_config(long param_1,uint param_2,uint *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined8 *puVar8;
  uint uVar9;
  long lVar10;
  uint uVar11;
  int iVar12;
  uint local_6c;
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  if (*(int *)(param_1 + 0xab0) == 2) {
    if (0xf < *param_3) goto LAB_0010422c;
    lVar10 = param_1 + (ulong)*param_3 * 0x90;
    uVar7 = (uint)*(byte *)(lVar10 + 0xa0);
    uVar11 = (uint)*(byte *)(lVar10 + 0xa1);
    if ((param_4 & 1) != 0) goto LAB_00103ff0;
LAB_00103fd4:
    uVar9 = 0;
  }
  else {
    uVar11 = 0;
    uVar7 = *(uint *)(param_1 + 0x9a8) & 8;
    if ((param_4 & 1) == 0) goto LAB_00103fd4;
LAB_00103ff0:
    uVar9 = param_2 & 0x3f;
    if (uVar7 != 0) {
      if ((((param_2 & 0xfffffffe) == 0x18) && (uVar11 == 1)) ||
         (((param_2 & 0xfffffffe) == 0x26 && (uVar11 == 0)))) {
        _printk(&DAT_001067ad);
        uVar6 = 0;
        goto LAB_001041dc;
      }
      uVar9 = uVar9 | uVar11 << 0x10 | 0x80000000;
    }
  }
  if (*(int *)(param_1 + 0xb38) != 0) {
    uVar11 = 0x3f;
    if (uVar7 != 0) {
      uVar11 = 0x8001003f;
    }
    iVar12 = 0;
    uVar7 = 0;
    do {
      local_6c = 0;
      iVar1 = 0x61040;
      if (*(int *)(param_1 + 0xb4c) < 0x15) {
        iVar1 = 0x49040;
      }
      iVar3 = 0xc1040;
      if (*(int *)(param_1 + 0xb4c) != 0x33) {
        iVar3 = iVar1;
      }
      iVar1 = iVar12 + iVar3 + (*param_3 + uVar7) * 4;
      regmap_read(*(undefined8 *)(param_1 + 8),iVar1,&local_6c);
      local_6c = local_6c & ~uVar11 | uVar9 & uVar11;
      regmap_write(*(undefined8 *)(param_1 + 8),iVar1);
      uVar4 = *param_3;
      if (uVar4 < 0x10) {
        uVar2 = (uVar4 & 0x1f) << 0x10 | 0xc0000003;
        if ((param_4 & 1) == 0) {
          uVar2 = 0;
        }
        iVar1 = 0x36020;
        if (*(int *)(param_1 + 0xb4c) < 0x15) {
          iVar1 = 0x31020;
        }
        iVar3 = 0x66020;
        if (*(int *)(param_1 + 0xb4c) != 0x33) {
          iVar3 = iVar1;
        }
        regmap_write(*(undefined8 *)(param_1 + 8),iVar3 + uVar4 * 4,uVar2);
      }
      if (uVar7 == 1) {
        uVar4 = *param_3 + 1;
        if (uVar4 < 0x10) {
          uVar2 = uVar4 * 0x10000 & 0x1f0000 | 0xc0000008;
          if ((param_4 & 1) == 0) {
            uVar2 = 0;
          }
          iVar1 = 0x36020;
          if (*(int *)(param_1 + 0xb4c) < 0x15) {
            iVar1 = 0x31020;
          }
          iVar3 = 0x66020;
          if (*(int *)(param_1 + 0xb4c) != 0x33) {
            iVar3 = iVar1;
          }
          regmap_write(*(undefined8 *)(param_1 + 8),iVar3 + uVar4 * 4,uVar2);
        }
      }
      uVar7 = uVar7 + 1;
      iVar12 = iVar12 + 0x4000;
    } while (uVar7 < *(uint *)(param_1 + 0xb38));
    if (1 < *(uint *)(param_1 + 0xb38)) {
      uVar7 = *param_3;
      *param_3 = uVar7 + 1;
      if (0x10 < uVar7) {
LAB_0010422c:
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x104230);
        (*pcVar5)();
      }
      param_1 = param_1 + (ulong)uVar7 * 0x90;
      puVar8 = (undefined8 *)(param_1 + 0x98);
      *puVar8 = 0xff00000008;
      if ((param_4 & 1) != 0) {
        uVar6 = 1;
        *(undefined4 *)puVar8 = 3;
        *(uint *)(param_1 + 0x9c) = param_2;
        goto LAB_001041dc;
      }
    }
  }
  uVar6 = 1;
LAB_001041dc:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// beac_event_enable @ 00104234 size=564
// signature: undefined beac_event_enable(void)
// callers: []
//------------------------------------------------------------

void beac_event_enable(long param_1,ulong param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint local_6c;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  uVar7 = 0x2000;
  if (((*(uint *)(param_1 + 0x9a8) | *(uint *)(param_1 + 0x9ac)) >> 3 & 1) == 0) {
    uVar3 = 0x4002001;
    uVar8 = 0xff00;
    uVar6 = 0x2000;
    iVar9 = *(int *)(param_1 + 0xb38);
  }
  else {
    uVar6 = 0x2078;
    if ((*(uint *)(param_1 + 0x9ac) & 8) == 0) {
      uVar6 = 0x2000;
    }
    uVar7 = 0x2028;
    if ((*(uint *)(param_1 + 0x9a8) & 8) == 0) {
      uVar7 = 0x2000;
    }
    uVar8 = 0xff78;
    uVar3 = 0x4002029;
    iVar9 = *(int *)(param_1 + 0xb38);
  }
  if (iVar9 != 0) {
    bVar5 = (param_2 & 1) == 0;
    if (bVar5) {
      uVar7 = 0;
      uVar3 = 0;
    }
    if (bVar5) {
      uVar6 = 0;
    }
    iVar9 = 0;
    uVar10 = 0;
    do {
      local_6c = 0;
      iVar1 = 0x61088;
      if (*(int *)(param_1 + 0xb4c) < 0x15) {
        iVar1 = 0x49088;
      }
      iVar2 = 0xc1088;
      if (*(int *)(param_1 + 0xb4c) != 0x33) {
        iVar2 = iVar1;
      }
      regmap_read(*(undefined8 *)(param_1 + 8),iVar2 + iVar9,&local_6c);
      local_6c = local_6c & ~uVar8 | uVar8 & uVar7;
      regmap_write(*(undefined8 *)(param_1 + 8),iVar2 + iVar9);
      local_6c = 0;
      iVar1 = 0x6108c;
      if (*(int *)(param_1 + 0xb4c) < 0x15) {
        iVar1 = 0x4908c;
      }
      iVar2 = 0xc108c;
      if (*(int *)(param_1 + 0xb4c) != 0x33) {
        iVar2 = iVar1;
      }
      regmap_read(*(undefined8 *)(param_1 + 8),iVar2 + iVar9,&local_6c);
      local_6c = local_6c & ~uVar8 | uVar8 & uVar6;
      regmap_write(*(undefined8 *)(param_1 + 8),iVar2 + iVar9);
      local_6c = 0;
      iVar1 = 0x61080;
      if (*(int *)(param_1 + 0xb4c) < 0x15) {
        iVar1 = 0x49080;
      }
      iVar2 = 0xc1080;
      if (*(int *)(param_1 + 0xb4c) != 0x33) {
        iVar2 = iVar1;
      }
      regmap_read(*(undefined8 *)(param_1 + 8),iVar2 + iVar9,&local_6c);
      local_6c = local_6c & (uVar8 ^ 0xf000fff8) | (uVar8 | 0x4000001) & uVar3;
      regmap_write(*(undefined8 *)(param_1 + 8),iVar2 + iVar9);
      uVar10 = uVar10 + 1;
      iVar9 = iVar9 + 0x4000;
    } while (uVar10 < *(uint *)(param_1 + 0xb38));
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// beac_event_filter_config @ 0010446c size=968
// signature: undefined beac_event_filter_config(void)
// callers: []
//------------------------------------------------------------

void beac_event_filter_config
               (long param_1,int param_2,long param_3,ulong param_4,uint param_5,byte param_6)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint local_6c;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  uVar5 = (uint)param_3;
  if (param_2 == 2) {
    iVar1 = *(int *)(param_1 + 0xb4c);
    uVar5 = uVar5 | (uint)(param_4 << 0x10);
    if ((param_5 & 1) == 0) {
      uVar5 = 0;
    }
    iVar2 = 0x61008;
    if (iVar1 < 0x15) {
      iVar2 = 0x49008;
    }
    iVar7 = 0xc1008;
    if (iVar1 != 0x33) {
      iVar7 = iVar2;
    }
    *(ulong *)(param_1 + 0xb50) = (ulong)param_6 + 2;
    if (param_6 != 0) {
      iVar2 = 0x61028;
      if (iVar1 < 0x15) {
        iVar2 = 0x49028;
      }
      iVar7 = 0xc1028;
      if (iVar1 != 0x33) {
        iVar7 = iVar2;
      }
    }
    uVar8 = 0xffffffff;
    iVar1 = *(int *)(param_1 + 0xb38);
  }
  else if (param_2 == 10) {
    if (*(int *)(param_1 + 0xb38) != 0) {
      iVar2 = *(int *)(param_1 + 0xb4c);
      uVar8 = 0;
      iVar1 = 0x61030;
      iVar7 = 0x61010;
      if (iVar2 < 0x15) {
        iVar1 = 0x49030;
        iVar7 = 0x49010;
      }
      iVar9 = 0xc1010;
      if (iVar2 != 0x33) {
        iVar9 = iVar7;
      }
      iVar7 = 0xc1030;
      if (iVar2 != 0x33) {
        iVar7 = iVar1;
      }
      if (param_6 != 0) {
        iVar9 = iVar7;
      }
      if ((param_5 & 1) == 0) {
        uVar5 = 0;
      }
      do {
        local_6c = 0;
        regmap_read(*(undefined8 *)(param_1 + 8),iVar9,&local_6c);
        local_6c = uVar5;
        regmap_write(*(undefined8 *)(param_1 + 8),iVar9,uVar5);
        iVar9 = iVar9 + 0x4000;
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(uint *)(param_1 + 0xb38));
      if (*(uint *)(param_1 + 0xb38) != 0) {
        iVar2 = *(int *)(param_1 + 0xb4c);
        uVar5 = 0;
        iVar1 = 0x6102c;
        iVar7 = 0x6100c;
        if (iVar2 < 0x15) {
          iVar1 = 0x4902c;
          iVar7 = 0x4900c;
        }
        iVar9 = 0xc100c;
        if (iVar2 != 0x33) {
          iVar9 = iVar7;
        }
        iVar7 = 0xc102c;
        if (iVar2 != 0x33) {
          iVar7 = iVar1;
        }
        if (param_6 != 0) {
          iVar9 = iVar7;
        }
        uVar8 = (uint)param_4;
        if ((param_5 & 1) == 0) {
          uVar8 = 0;
        }
        do {
          local_6c = 0;
          regmap_read(*(undefined8 *)(param_1 + 8),iVar9,&local_6c);
          local_6c = uVar8;
          regmap_write(*(undefined8 *)(param_1 + 8),iVar9,uVar8);
          iVar9 = iVar9 + 0x4000;
          uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint *)(param_1 + 0xb38));
      }
    }
    if ((param_5 & 1) == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = (uint)(param_4 >> 0x1c) & 0xf0 | (uint)((ulong)param_3 >> 0x20) & 0xf;
    }
    iVar2 = *(int *)(param_1 + 0xb4c);
    iVar1 = 0x61014;
    if (iVar2 < 0x15) {
      iVar1 = 0x49014;
    }
    iVar7 = 0xc1014;
    if (iVar2 != 0x33) {
      iVar7 = iVar1;
    }
    *(ulong *)(param_1 + 0xb50) = (ulong)param_6 + 2;
    if (param_6 != 0) {
      iVar1 = 0x61034;
      if (iVar2 < 0x15) {
        iVar1 = 0x49034;
      }
      iVar7 = 0xc1034;
      if (iVar2 != 0x33) {
        iVar7 = iVar1;
      }
    }
    uVar8 = 0x1ff;
    iVar1 = *(int *)(param_1 + 0xb38);
  }
  else {
    if (param_2 != 3) {
      _printk(&DAT_00106528);
      uVar4 = 0;
      goto LAB_001047e4;
    }
    iVar1 = *(int *)(param_1 + 0xb4c);
    uVar5 = (uint)(param_4 << 0xe) | (uint)(param_3 << 0xc);
    if ((param_5 & 1) == 0) {
      uVar5 = 0;
    }
    iVar2 = 0x61014;
    if (iVar1 < 0x15) {
      iVar2 = 0x49014;
    }
    iVar7 = 0xc1014;
    if (iVar1 != 0x33) {
      iVar7 = iVar2;
    }
    *(ulong *)(param_1 + 0xb50) = (ulong)(param_3 == 2);
    if (param_6 != 0) {
      iVar2 = 0x61034;
      if (iVar1 < 0x15) {
        iVar2 = 0x49034;
      }
      iVar7 = 0xc1034;
      if (iVar1 != 0x33) {
        iVar7 = iVar2;
      }
    }
    uVar8 = 0xf000;
    iVar1 = *(int *)(param_1 + 0xb38);
  }
  if (iVar1 != 0) {
    uVar6 = 0;
    do {
      local_6c = 0;
      regmap_read(*(undefined8 *)(param_1 + 8),iVar7,&local_6c);
      local_6c = local_6c & ~uVar8 | uVar8 & uVar5;
      regmap_write(*(undefined8 *)(param_1 + 8),iVar7);
      iVar7 = iVar7 + 0x4000;
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_1 + 0xb38));
  }
  if ((param_5 & 1) == 0) {
    uVar4 = 1;
    *(undefined8 *)(param_1 + 0xb50) = 2;
  }
  else {
    uVar4 = 1;
  }
LAB_001047e4:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// berc_event_config @ 00104838 size=396
// signature: undefined berc_event_config(void)
// callers: []
//------------------------------------------------------------

undefined8 berc_event_config(long param_1,uint param_2,uint *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  uint uVar9;
  uint local_5c;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  if (*(int *)(param_1 + 0xab0) == 2) {
    uVar6 = *param_3;
    if (0xf < uVar6) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x1049c4);
      (*pcVar5)();
    }
    lVar8 = param_1 + (ulong)uVar6 * 0x90;
    uVar9 = (uint)*(byte *)(lVar8 + 0xa0);
    uVar7 = (uint)*(byte *)(lVar8 + 0xa1) << 0x10 | 0x80000000;
  }
  else {
    uVar7 = 0x80000000;
    uVar9 = *(uint *)(param_1 + 0x9a8) & 0x10;
    uVar6 = *param_3;
  }
  uVar2 = 0x3f;
  if (uVar9 != 0) {
    uVar2 = 0x8001003f;
  }
  uVar4 = 0;
  if (uVar9 != 0) {
    uVar4 = uVar7;
  }
  uVar4 = uVar4 | param_2 & 0x3f;
  if ((param_4 & 1) == 0) {
    uVar4 = 0;
  }
  iVar3 = 0x3d020;
  if (*(int *)(param_1 + 0xb4c) < 0x15) {
    iVar3 = 0x39020;
  }
  iVar1 = 0x6d020;
  if (*(int *)(param_1 + 0xb4c) != 0x33) {
    iVar1 = iVar3;
  }
  iVar1 = iVar1 + uVar6 * 4;
  local_5c = 0;
  regmap_read(*(undefined8 *)(param_1 + 8),iVar1,&local_5c);
  local_5c = local_5c & (uVar2 ^ 0xffffffff) | uVar4 & uVar2;
  regmap_write(*(undefined8 *)(param_1 + 8),iVar1);
  uVar9 = *param_3;
  if (uVar9 < 0x10) {
    uVar6 = (uVar9 & 0x1f) << 0x10 | 0xc0000004;
    if ((param_4 & 1) == 0) {
      uVar6 = 0;
    }
    iVar3 = 0x36020;
    if (*(int *)(param_1 + 0xb4c) < 0x15) {
      iVar3 = 0x31020;
    }
    iVar1 = 0x66020;
    if (*(int *)(param_1 + 0xb4c) != 0x33) {
      iVar1 = iVar3;
    }
    regmap_write(*(undefined8 *)(param_1 + 8),iVar1 + uVar9 * 4,uVar6);
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// berc_event_enable @ 001049c8 size=192
// signature: undefined berc_event_enable(void)
// callers: []
//------------------------------------------------------------

void berc_event_enable(long param_1,ulong param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  long lVar4;
  uint local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  uVar3 = 0x4002001;
  if ((param_2 & 1) == 0) {
    uVar3 = 0;
  }
  local_3c = 0;
  uVar1 = 0x3d060;
  if (*(int *)(param_1 + 0xb4c) < 0x15) {
    uVar1 = 0x39060;
  }
  uVar2 = 0x6d060;
  if (*(int *)(param_1 + 0xb4c) != 0x33) {
    uVar2 = uVar1;
  }
  regmap_read(*(undefined8 *)(param_1 + 8),uVar2,&local_3c);
  local_3c = local_3c & 0xf00000fe | uVar3;
  regmap_write(*(undefined8 *)(param_1 + 8),uVar2);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// berc_event_filter_config @ 00104a8c size=256
// signature: undefined berc_event_filter_config(void)
// callers: []
//------------------------------------------------------------

undefined8
berc_event_filter_config
          (long param_1,int param_2,uint param_3,int param_4,uint param_5,char param_6)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  uint local_3c;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  if (param_2 == 3) {
    iVar5 = *(int *)(param_1 + 0xb4c);
    uVar2 = 0x3d010;
    uVar3 = 0x3d000;
    if (iVar5 < 0x15) {
      uVar2 = 0x39010;
      uVar3 = 0x39000;
    }
    uVar4 = 0x6d000;
    if (iVar5 != 0x33) {
      uVar4 = uVar3;
    }
    uVar3 = 0x6d010;
    if (iVar5 != 0x33) {
      uVar3 = uVar2;
    }
    if (param_6 != '\0') {
      uVar4 = uVar3;
    }
    local_3c = 0;
    regmap_read(*(undefined8 *)(param_1 + 8),uVar4,&local_3c);
    uVar1 = (param_3 | param_4 << 2) & 0xf;
    if ((param_5 & 1) == 0) {
      uVar1 = 0;
    }
    local_3c = local_3c & 0xfffffff0 | uVar1;
    regmap_write(*(undefined8 *)(param_1 + 8),uVar4);
  }
  else {
    _printk(&DAT_00106528);
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// trp_event_config @ 00104b90 size=400
// signature: undefined trp_event_config(void)
// callers: []
//------------------------------------------------------------

undefined8 trp_event_config(long param_1,uint param_2,uint *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  uint uVar5;
  long lVar6;
  uint uVar7;
  uint uVar8;
  uint local_5c;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  if (*(int *)(param_1 + 0xab0) == 2) {
    if (0xf < *param_3) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x104d20);
      (*pcVar4)();
    }
    lVar6 = param_1 + (ulong)*param_3 * 0x90;
    uVar7 = (uint)*(byte *)(lVar6 + 0xa0);
    uVar5 = (uint)*(byte *)(lVar6 + 0xa1) << 0x10 | 0x80000000;
  }
  else {
    uVar7 = *(uint *)(param_1 + 0x9a8) & 0x20;
    uVar5 = 0x80000000;
  }
  uVar8 = 0x7f;
  if (*(uint *)(param_1 + 0xb3c) < 2) {
    uVar8 = 0x3f;
  }
  uVar3 = 0;
  if (uVar7 != 0) {
    uVar3 = uVar5;
  }
  uVar3 = uVar8 & param_2 | uVar3;
  if (uVar7 != 0) {
    uVar8 = uVar8 | 0x80010000;
  }
  if ((param_4 & 1) == 0) {
    uVar3 = 0;
  }
  iVar1 = 0x48020;
  if (*(int *)(param_1 + 0xb4c) != 0x33) {
    iVar1 = 0x24020;
  }
  local_5c = 0;
  iVar1 = iVar1 + *param_3 * 4;
  regmap_read(*(undefined8 *)(param_1 + 8),iVar1,&local_5c);
  local_5c = local_5c & (uVar8 ^ 0xffffffff) | uVar3 & uVar8;
  regmap_write(*(undefined8 *)(param_1 + 8),iVar1);
  uVar7 = *param_3;
  if (uVar7 < 0x10) {
    uVar5 = (uVar7 & 0x1f) << 0x10 | 0xc0000005;
    if ((param_4 & 1) == 0) {
      uVar5 = 0;
    }
    iVar1 = 0x36020;
    if (*(int *)(param_1 + 0xb4c) < 0x15) {
      iVar1 = 0x31020;
    }
    iVar2 = 0x66020;
    if (*(int *)(param_1 + 0xb4c) != 0x33) {
      iVar2 = iVar1;
    }
    regmap_write(*(undefined8 *)(param_1 + 8),iVar2 + uVar7 * 4,uVar5);
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// trp_event_filter_config @ 00104d24 size=800
// signature: undefined trp_event_filter_config(void)
// callers: []
//------------------------------------------------------------

void trp_event_filter_config
               (long param_1,undefined4 param_2,ulong param_3,long param_4,uint param_5,char param_6
               )

{
  uint uVar1;
  undefined4 uVar2;
  bool bVar3;
  undefined8 uVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  uint uVar8;
  uint uVar9;
  uint local_5c;
  long local_58;
  
  lVar7 = sp_el0;
  local_58 = *(long *)(lVar7 + 0x638);
  uVar5 = (uint)param_3;
  switch(param_2) {
  case 1:
    if (*(int *)(param_1 + 0xb4c) == 0x33) {
      lVar7 = 1L << (param_3 & 0x3f);
      uVar5 = (uint)lVar7;
      uVar8 = (uint)((ulong)lVar7 >> 0x20);
      if ((param_5 & 1) == 0) {
        uVar8 = 0xffffffff;
        uVar5 = 0xffffffff;
      }
      uVar2 = 0x48120;
      if (param_6 != '\0') {
        uVar2 = 0x48130;
      }
      local_5c = 0;
      regmap_read(*(undefined8 *)(param_1 + 8),uVar2,&local_5c);
      local_5c = uVar8;
      regmap_write(*(undefined8 *)(param_1 + 8),uVar2,uVar8);
      iVar6 = *(int *)(param_1 + 0xb4c);
      if (param_6 == '\0') {
        uVar8 = 0x48008;
        if (iVar6 != 0x33) {
          uVar8 = 0x24008;
        }
      }
      else {
LAB_00104f08:
        uVar8 = 0x48018;
        if (iVar6 != 0x33) {
          uVar8 = 0x24018;
        }
      }
LAB_00104fac:
      uVar9 = 0xffffffff;
    }
    else if (*(uint *)(param_1 + 0xb3c) < 2) {
      uVar5 = uVar5 | (uint)(param_4 << 8);
      if ((param_5 & 1) == 0) {
        uVar5 = 0;
      }
      uVar8 = 0x24004;
      if (param_6 != '\0') {
        uVar8 = 0x24014;
      }
      uVar9 = 0x1f1f;
    }
    else {
      uVar9 = 0xffffffff;
      uVar5 = 1 << (ulong)(uVar5 & 0x1f);
      if ((param_5 & 1) == 0) {
        uVar5 = 0xffffffff;
      }
      uVar8 = 0x24008;
      if (param_6 != '\0') {
        uVar8 = 0x24018;
      }
    }
    break;
  default:
    _printk(&DAT_00106528);
    goto LAB_00104fe4;
  case 3:
    uVar5 = (uint)(param_4 << 0x1c) | (uint)(param_3 << 0x18);
    if ((param_5 & 1) == 0) {
      uVar5 = 0;
    }
    uVar8 = 0x48000;
    if (*(int *)(param_1 + 0xb4c) != 0x33) {
      uVar8 = 0x24000;
    }
    uVar9 = 0x33000000;
    goto LAB_00104e80;
  case 4:
    uVar5 = uVar5 | (uint)(param_4 << 8);
    if ((param_5 & 1) == 0) {
      uVar5 = 0;
    }
    uVar9 = 0x1f1f;
    uVar8 = 0x48000;
    if (*(int *)(param_1 + 0xb4c) != 0x33) {
      uVar8 = 0x24000;
    }
LAB_00104e80:
    uVar1 = 4;
    if (param_6 != '\0') {
      uVar1 = 0x14;
    }
    uVar8 = uVar8 | uVar1;
    break;
  case 8:
    if (*(int *)(param_1 + 0xb4c) == 0x33) {
      bVar3 = (param_5 & 1) == 0;
      uVar8 = (uint)(param_3 >> 0x20);
      if (bVar3) {
        uVar8 = 0xffffffff;
      }
      if (bVar3) {
        uVar5 = 0xffffffff;
      }
      uVar2 = 0x48120;
      if (param_6 != '\0') {
        uVar2 = 0x48130;
      }
      local_5c = 0;
      regmap_read(*(undefined8 *)(param_1 + 8),uVar2,&local_5c);
      local_5c = uVar8;
      regmap_write(*(undefined8 *)(param_1 + 8),uVar2,uVar8);
      iVar6 = *(int *)(param_1 + 0xb4c);
      if (param_6 != '\0') goto LAB_00104f08;
      uVar8 = 0x48008;
      if (iVar6 != 0x33) {
        uVar8 = 0x24008;
      }
      goto LAB_00104fac;
    }
    if (*(uint *)(param_1 + 0xb3c) < 2) {
      _printk(&DAT_00106528);
      uVar4 = 0;
      goto LAB_00104fe8;
    }
    uVar9 = 0xffffffff;
    if ((param_5 & 1) == 0) {
      param_3 = 0xffffffff;
    }
    uVar5 = (uint)param_3;
    uVar8 = 0x24008;
    if (param_6 != '\0') {
      uVar8 = 0x24018;
    }
  }
  local_5c = 0;
  regmap_read(*(undefined8 *)(param_1 + 8),uVar8,&local_5c);
  local_5c = local_5c & (uVar9 ^ 0xffffffff) | uVar9 & uVar5;
  regmap_write(*(undefined8 *)(param_1 + 8),uVar8);
LAB_00104fe4:
  uVar4 = 1;
LAB_00104fe8:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// drp_event_config @ 00105048 size=416
// signature: undefined drp_event_config(void)
// callers: []
//------------------------------------------------------------

undefined8 drp_event_config(long param_1,uint param_2,uint *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  uint uVar9;
  uint uVar10;
  uint local_4c;
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  if (*(int *)(param_1 + 0xab0) == 2) {
    uVar6 = *param_3;
    if (0xf < uVar6) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x1051e8);
      (*pcVar5)();
    }
    lVar8 = param_1 + (ulong)uVar6 * 0x90;
    uVar9 = (uint)*(byte *)(lVar8 + 0xa0);
    uVar7 = (uint)*(byte *)(lVar8 + 0xa1) << 0x10 | 0x80000000;
  }
  else {
    uVar7 = 0x80000000;
    uVar9 = *(uint *)(param_1 + 0x9a8) & 0x40;
    uVar6 = *param_3;
  }
  local_4c = 0;
  uVar10 = 0x7f;
  if (*(uint *)(param_1 + 0xb3c) < 2) {
    uVar10 = 0x3f;
  }
  uVar2 = uVar10;
  uVar4 = 0;
  if (uVar9 != 0) {
    uVar2 = uVar10 | 0x80010000;
    uVar4 = uVar7;
  }
  uVar4 = uVar10 & param_2 | uVar4;
  if ((param_4 & 1) == 0) {
    uVar4 = 0;
  }
  iVar3 = 0x51010;
  if (*(int *)(param_1 + 0xb4c) < 0x15) {
    iVar3 = 0x44010;
  }
  iVar1 = 0x81010;
  if (*(int *)(param_1 + 0xb4c) != 0x33) {
    iVar1 = iVar3;
  }
  iVar1 = iVar1 + uVar6 * 4;
  regmap_read(*(undefined8 *)(param_1 + 8),iVar1,&local_4c);
  local_4c = local_4c & (uVar2 ^ 0xffffffff) | uVar4 & uVar2;
  regmap_write(*(undefined8 *)(param_1 + 8),iVar1);
  uVar9 = *param_3;
  if (uVar9 < 0x10) {
    uVar6 = (uVar9 & 0x1f) << 0x10 | 0xc0000006;
    if ((param_4 & 1) == 0) {
      uVar6 = 0;
    }
    iVar3 = 0x36020;
    if (*(int *)(param_1 + 0xb4c) < 0x15) {
      iVar3 = 0x31020;
    }
    iVar1 = 0x66020;
    if (*(int *)(param_1 + 0xb4c) != 0x33) {
      iVar1 = iVar3;
    }
    regmap_write(*(undefined8 *)(param_1 + 8),iVar1 + uVar9 * 4,uVar6);
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// drp_event_enable @ 001051ec size=188
// signature: undefined drp_event_enable(void)
// callers: []
//------------------------------------------------------------

void drp_event_enable(long param_1,ulong param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  uint uVar4;
  uint local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  uVar4 = 0x2001;
  if ((param_2 & 1) == 0) {
    uVar4 = 0;
  }
  local_3c = 0;
  uVar1 = 0x51050;
  if (*(int *)(param_1 + 0xb4c) < 0x15) {
    uVar1 = 0x44050;
  }
  uVar2 = 0x81050;
  if (*(int *)(param_1 + 0xb4c) != 0x33) {
    uVar2 = uVar1;
  }
  regmap_read(*(undefined8 *)(param_1 + 8),uVar2,&local_3c);
  local_3c = local_3c & 0xffff00fe | uVar4;
  regmap_write(*(undefined8 *)(param_1 + 8),uVar2);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// pmgr_event_config @ 001052ac size=396
// signature: undefined pmgr_event_config(void)
// callers: []
//------------------------------------------------------------

undefined8 pmgr_event_config(long param_1,uint param_2,uint *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  long lVar8;
  uint uVar9;
  uint local_4c;
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  if (*(int *)(param_1 + 0xab0) == 2) {
    uVar5 = *param_3;
    if (0xf < uVar5) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x105438);
      (*pcVar4)();
    }
    lVar8 = param_1 + (ulong)uVar5 * 0x90;
    uVar9 = (uint)*(byte *)(lVar8 + 0xa0);
    uVar6 = (uint)*(byte *)(lVar8 + 0xa1) << 0x10 | 0x80000000;
  }
  else {
    uVar6 = 0x80000000;
    uVar9 = *(uint *)(param_1 + 0x9a8) & 0x80;
    uVar5 = *param_3;
  }
  uVar2 = 0x3f;
  if (uVar9 != 0) {
    uVar2 = 0x8001003f;
  }
  uVar3 = 0;
  if (uVar9 != 0) {
    uVar3 = uVar6;
  }
  uVar3 = uVar3 | param_2 & 0x3f;
  if ((param_4 & 1) == 0) {
    uVar3 = 0;
  }
  iVar7 = 0x4d000;
  if (*(int *)(param_1 + 0xb4c) < 0x15) {
    iVar7 = 0x3f000;
  }
  local_4c = 0;
  iVar1 = 0x7d000;
  if (*(int *)(param_1 + 0xb4c) != 0x33) {
    iVar1 = iVar7;
  }
  iVar1 = iVar1 + uVar5 * 4;
  regmap_read(*(undefined8 *)(param_1 + 8),iVar1,&local_4c);
  local_4c = local_4c & (uVar2 ^ 0xffffffff) | uVar3 & uVar2;
  regmap_write(*(undefined8 *)(param_1 + 8),iVar1);
  uVar9 = *param_3;
  if (uVar9 < 0x10) {
    uVar5 = (uVar9 & 0x1f) << 0x10 | 0xc0000007;
    if ((param_4 & 1) == 0) {
      uVar5 = 0;
    }
    iVar7 = 0x36020;
    if (*(int *)(param_1 + 0xb4c) < 0x15) {
      iVar7 = 0x31020;
    }
    iVar1 = 0x66020;
    if (*(int *)(param_1 + 0xb4c) != 0x33) {
      iVar1 = iVar7;
    }
    regmap_write(*(undefined8 *)(param_1 + 8),iVar1 + uVar9 * 4,uVar5);
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// init_module @ 0010543c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&llcc_perfmon_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010546c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&llcc_perfmon_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00108000 size=1
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
// platform_driver_unregister @ 00108008 size=1
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
// devm_kmalloc @ 00108010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [llcc_perfmon_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00108018 size=1
// signature: undefined regmap_read(void)
// callers: [perfmon_configure_store, perfmon_start_store, perfmon_counter_dump_show, fewc_event_filter_config, perfmon_scid_status_show, pmgr_event_config, beac_event_config, trp_event_config, perfmon_remove_store, feac_event_config, feac_scid_multiscid_set_remove, drp_event_config, berc_event_filter_config, ferc_event_enable, perfmon_counter_dump, feac_event_filter_config, ferc_event_config, beac_event_enable, llcc_perfmon_probe, berc_event_enable, berc_event_config, remove_counters, ferc_event_filter_config, feac_event_enable, fewc_event_config, beac_event_filter_config, trp_event_filter_config, drp_event_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 00108020 size=1
// signature: undefined devm_clk_get(void)
// callers: [llcc_perfmon_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00108028 size=1
// signature: undefined _printk(void)
// callers: [llcc_perfmon_probe, perfmon_configure_store, perfmon_start_store, perfmon_counter_dump_show, perfmon_beac_mc_proftag_store, fewc_event_filter_config, beac_event_config, perfmon_remove_store, feac_event_config, remove_counters, remove_filters, perfmon_filter_config_store, ferc_event_filter_config, feac_scid_multiscid_set_remove, perfmon_filter_remove_store, berc_event_filter_config, beac_event_filter_config, trp_event_filter_config, feac_event_filter_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 00108030 size=1
// signature: undefined regmap_write(void)
// callers: [perfmon_configure_store, perfmon_start_store, fewc_event_filter_config, perfmon_scid_status_show, pmgr_event_config, beac_event_config, trp_event_config, perfmon_remove_store, feac_event_config, feac_scid_multiscid_set_remove, drp_event_config, berc_event_filter_config, ferc_event_enable, perfmon_counter_dump, feac_event_filter_config, ferc_event_config, beac_event_enable, llcc_perfmon_probe, berc_event_enable, berc_event_config, remove_counters, ferc_event_filter_config, feac_event_enable, fewc_event_config, beac_event_filter_config, trp_event_filter_config, drp_event_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 00108038 size=1
// signature: undefined sysfs_create_group(void)
// callers: [llcc_perfmon_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00108040 size=1
// signature: undefined __mutex_init(void)
// callers: [llcc_perfmon_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_init @ 00108048 size=1
// signature: undefined hrtimer_init(void)
// callers: [llcc_perfmon_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00108050 size=1
// signature: undefined of_find_property(void)
// callers: [llcc_perfmon_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00108058 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [perfmon_configure_store, perfmon_start_store, perfmon_counter_dump_show, fewc_event_filter_config, perfmon_scid_status_show, pmgr_event_config, beac_event_config, trp_event_config, perfmon_remove_store, feac_event_config, perfmon_filter_config_store, feac_scid_multiscid_set_remove, drp_event_config, perfmon_filter_remove_store, berc_event_filter_config, ferc_event_enable, perfmon_counter_dump, feac_event_filter_config, ferc_event_config, beac_event_enable, llcc_perfmon_probe, berc_event_enable, berc_event_config, remove_counters, ferc_event_filter_config, feac_event_enable, fewc_event_config, beac_event_filter_config, trp_event_filter_config, drp_event_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_active @ 00108060 size=1
// signature: undefined hrtimer_active(void)
// callers: [llcc_perfmon_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_active(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_cancel @ 00108068 size=1
// signature: undefined hrtimer_cancel(void)
// callers: [perfmon_ns_periodic_dump_store, perfmon_start_store, llcc_perfmon_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_cancel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_group @ 00108070 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [llcc_perfmon_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_forward @ 00108078 size=1
// signature: undefined hrtimer_forward(void)
// callers: [perfmon_ns_periodic_dump_store, llcc_perfmon_timer_handler, perfmon_start_store, perfmon_counter_dump_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_forward(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00108080 size=1
// signature: undefined scnprintf(void)
// callers: [perfmon_counter_dump_show, perfmon_scid_status_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00108088 size=1
// signature: undefined mutex_lock(void)
// callers: [perfmon_ns_periodic_dump_store, perfmon_filter_config_store, perfmon_configure_store, perfmon_filter_remove_store, perfmon_start_store, perfmon_beac_mc_proftag_store, perfmon_remove_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 00108090 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [perfmon_filter_config_store, perfmon_configure_store, perfmon_filter_remove_store, perfmon_remove_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00108098 size=1
// signature: size_t strlen(char * __s)
// callers: [perfmon_configure_store, perfmon_remove_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_streq @ 001080a0 size=1
// signature: undefined sysfs_streq(void)
// callers: [perfmon_filter_config_store, perfmon_configure_store, perfmon_filter_remove_store, perfmon_remove_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_streq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 001080a8 size=1
// signature: undefined kstrtoull(void)
// callers: [perfmon_filter_config_store, perfmon_configure_store, perfmon_filter_remove_store, perfmon_start_store, perfmon_beac_mc_proftag_store, perfmon_remove_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001080b0 size=1
// signature: undefined mutex_unlock(void)
// callers: [perfmon_ns_periodic_dump_store, perfmon_filter_config_store, perfmon_configure_store, perfmon_filter_remove_store, perfmon_start_store, perfmon_beac_mc_proftag_store, perfmon_remove_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001080b8 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [find_filter_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 001080c0 size=1
// signature: undefined clk_prepare(void)
// callers: [perfmon_start_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 001080c8 size=1
// signature: undefined clk_enable(void)
// callers: [perfmon_start_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_start_range_ns @ 001080d0 size=1
// signature: undefined hrtimer_start_range_ns(void)
// callers: [perfmon_ns_periodic_dump_store, perfmon_start_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_start_range_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001080d8 size=1
// signature: undefined clk_disable(void)
// callers: [perfmon_start_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001080e0 size=1
// signature: undefined clk_unprepare(void)
// callers: [perfmon_start_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoll @ 001080e8 size=1
// signature: undefined kstrtoll(void)
// callers: [perfmon_ns_periodic_dump_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoll(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



