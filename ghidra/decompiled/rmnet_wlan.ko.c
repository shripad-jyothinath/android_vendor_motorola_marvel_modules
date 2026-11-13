// Decompiled by Ghidra 12.2
// Program: rmnet_wlan.ko
// Image base: 00100000

//------------------------------------------------------------
// DATARMNET07f0e0f286 @ 00100e1c size=168
// signature: undefined DATARMNET07f0e0f286(void)
// callers: [DATARMNET37a92021f9]
//------------------------------------------------------------

undefined8 DATARMNET07f0e0f286(long *param_1)

{
  long *plVar1;
  
  plVar1 = (long *)(&DATARMNET5413d6f8ec)[(uint)((int)param_1[2] * 0x61c88647) >> 0x1c];
  do {
    if (plVar1 == (long *)0x0) {
      return 0;
    }
    if ((*(char *)(plVar1 + 0xb) == '\0') && (*(char *)(plVar1 + 8) == (char)param_1[4])) {
      if (*(char *)(plVar1 + 8) == '\x04') {
        if ((*(int *)(plVar1 + 4) == (int)*param_1) && (*(int *)(plVar1 + 6) == (int)param_1[2])) {
LAB_00100ebc:
          return plVar1[9];
        }
      }
      else if ((plVar1[4] == *param_1 && plVar1[5] == param_1[1]) &&
              (plVar1[6] == param_1[2] && plVar1[7] == param_1[3])) goto LAB_00100ebc;
    }
    plVar1 = (long *)*plVar1;
  } while( true );
}



//------------------------------------------------------------
// DATARMNETf4e1a29dbc @ 00100ec8 size=88
// signature: undefined DATARMNETf4e1a29dbc(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETf4e1a29dbc(void)

{
  cancel_delayed_work_sync(&DATARMNET0b04fde883);
  DAT_001066f0 = 1;
  queue_delayed_work_on(0x20,_system_wq,&DATARMNET0b04fde883,0);
  cancel_delayed_work_sync(&DATARMNET0b04fde883);
  return;
}



//------------------------------------------------------------
// DATARMNET6f73df41cd @ 00100f24 size=456
// signature: undefined DATARMNET6f73df41cd(void)
// callers: []
//------------------------------------------------------------

void DATARMNET6f73df41cd(long param_1)

{
  short *psVar1;
  byte bVar2;
  long lVar3;
  long *plVar4;
  int iVar5;
  byte *pbVar6;
  undefined8 local_40;
  undefined8 local_38;
  ulong local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  plVar4 = DATARMNETcde6e442f5;
  lVar3 = sp_el0;
  local_18 = *(long *)(lVar3 + 0x638);
  if (DATARMNETcde6e442f5 == (long *)0x0) goto LAB_0010106c;
  if (*(short *)(param_1 + 0xb4) == -0x227a) {
    local_28 = 0;
    uStack_20 = 0;
    local_38 = 0;
    local_30 = 0;
    local_40 = 0;
    if (*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x74) < 0x28) {
      if (param_1 == 0) goto LAB_0010106c;
      iVar5 = skb_copy_bits(param_1,0,&local_40,0x28);
      pbVar6 = (byte *)&local_40;
      if (iVar5 < 0) goto LAB_0010106c;
    }
    else {
      pbVar6 = *(byte **)(param_1 + 0xe0);
      if (pbVar6 == (byte *)0x0) goto LAB_0010106c;
    }
    if (((*(byte *)((long)plVar4 + 0x24) != *pbVar6 >> 4) &&
        (*(long *)(pbVar6 + 8) != *plVar4 || *(long *)(pbVar6 + 0x10) != plVar4[1])) &&
       (*(long *)(pbVar6 + 0x18) != plVar4[2] || *(long *)(pbVar6 + 0x20) != plVar4[3]))
    goto LAB_0010106c;
    bVar2 = pbVar6[6];
  }
  else {
    if (*(short *)(param_1 + 0xb4) != 8) goto LAB_0010106c;
    local_30 = local_30 & 0xffffffff00000000;
    local_40 = 0;
    local_38 = 0;
    if (*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x74) < 0x14) {
      if (param_1 == 0) goto LAB_0010106c;
      iVar5 = skb_copy_bits(param_1,0,&local_40,0x14);
      pbVar6 = (byte *)&local_40;
      if (iVar5 < 0) goto LAB_0010106c;
    }
    else {
      pbVar6 = *(byte **)(param_1 + 0xe0);
      if (pbVar6 == (byte *)0x0) goto LAB_0010106c;
    }
    if (((*(byte *)((long)plVar4 + 0x24) != *pbVar6 >> 4) &&
        (*(int *)(pbVar6 + 0xc) != (int)*plVar4)) && (*(int *)(pbVar6 + 0x10) != (int)plVar4[2]))
    goto LAB_0010106c;
    bVar2 = pbVar6[9];
  }
  if (((bVar2 == 0x11) &&
      (psVar1 = (short *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb6)),
      *psVar1 == (short)plVar4[4])) && (psVar1[1] == *(short *)((long)plVar4 + 0x22))) {
    *(undefined4 *)(param_1 + 0x8c) = 0x9b6d0100;
    DATARMNET5ca94dbc3c(0x15);
  }
LAB_0010106c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET333c107558 @ 001010f0 size=60
// signature: undefined DATARMNET333c107558(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET333c107558(void)

{
  _rmnet_wlan_ll_tuple_hook = DATARMNET6f73df41cd;
  rmnet_module_hook_register(&DATARMNET1928843de7,2);
  return;
}



//------------------------------------------------------------
// DATARMNET4c08c7210c @ 00101130 size=52
// signature: undefined DATARMNET4c08c7210c(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET4c08c7210c(void)

{
  _rmnet_wlan_ll_tuple_hook = 0;
  rmnet_module_hook_unregister_no_sync(&DATARMNET1928843de7,2);
  synchronize_rcu();
  return;
}



//------------------------------------------------------------
// DATARMNET9f106ed933 @ 00101168 size=96
// signature: undefined DATARMNET9f106ed933(void)
// callers: [init_module]
//------------------------------------------------------------

undefined8 DATARMNET9f106ed933(void)

{
  DATARMNET0b04fde883 = 0xfffffffe0;
  DAT_00106670 = &DAT_00106670;
  DAT_00106678 = &DAT_00106670;
  DAT_00106680 = DATARMNET8211acc766;
  init_timer_key(&DAT_00106698,&delayed_work_timer_fn,0x200000,0,0);
  return 0;
}



//------------------------------------------------------------
// DATARMNET8211acc766 @ 001011cc size=288
// signature: undefined DATARMNET8211acc766(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET8211acc766(long param_1)

{
  char cVar1;
  long *plVar2;
  long lVar3;
  undefined8 uVar4;
  long *plVar5;
  long lVar6;
  long *plVar7;
  
  uVar4 = _raw_spin_lock_irqsave(&DATARMNET820642743b);
  lVar3 = _jiffies;
  lVar6 = 0;
  cVar1 = *(char *)(param_1 + 0x88);
  do {
    plVar7 = (long *)(&DATARMNET5413d6f8ec)[lVar6];
    while (plVar2 = plVar7, plVar2 != (long *)0x0) {
      plVar7 = (long *)*plVar2;
      if (((char)plVar2[0xb] == '\0') && ((cVar1 != '\0' || (500 < (ulong)(lVar3 - plVar2[10]))))) {
        plVar5 = (long *)plVar2[1];
        *(undefined1 *)(plVar2 + 0xb) = 1;
        if (plVar5 != (long *)0x0) {
          *plVar5 = (long)plVar7;
          if (plVar7 != (long *)0x0) {
            plVar7[1] = (long)plVar5;
          }
          plVar2[1] = 0;
        }
        kvfree_call_rcu(plVar2 + 2,0x10);
        DATARMNETf658004dbc = DATARMNETf658004dbc + -1;
      }
    }
    lVar6 = lVar6 + 1;
  } while (lVar6 != 0x10);
  if (DATARMNETf658004dbc != 0) {
    queue_delayed_work_on(0x20,_system_wq,param_1,0x7d);
  }
  _raw_spin_unlock_irqrestore(&DATARMNET820642743b,uVar4);
  return;
}



//------------------------------------------------------------
// DATARMNETf56cbaa2b1 @ 001012f0 size=92
// signature: undefined DATARMNETf56cbaa2b1(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNETf56cbaa2b1(void)

{
  cancel_delayed_work_sync(&DATARMNET0b04fde883);
  DAT_001066f0 = 1;
  queue_delayed_work_on(0x20,_system_wq,&DATARMNET0b04fde883,0);
  cancel_delayed_work_sync(&DATARMNET0b04fde883);
  return 0;
}



//------------------------------------------------------------
// DATARMNETd2f80b03ce @ 00101350 size=4072
// signature: undefined DATARMNETd2f80b03ce(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETd2f80b03ce(long *param_1)

{
  long *plVar1;
  int *piVar2;
  short sVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  undefined4 *puVar11;
  long *plVar12;
  code *pcVar13;
  uint uVar14;
  long lVar15;
  ulong *puVar16;
  undefined8 *puVar17;
  char cVar18;
  ulong *puVar19;
  char cVar20;
  char local_12c [4];
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  long local_108;
  long lStack_100;
  ulong local_f8;
  long lStack_f0;
  undefined4 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  ulong local_a8;
  ulong local_a0;
  ulong local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  ulong local_80 [2];
  long local_70;
  uint uStack_6c;
  ulong local_68 [3];
  
  lVar15 = sp_el0;
  local_68[2] = *(long *)(lVar15 + 0x638);
  if (((param_1 == (long *)0x0) || (*param_1 == 0)) ||
     (lVar15 = *(long *)(*param_1 + 0x10), lVar15 == 0)) {
LAB_00101414:
    uVar7 = 3;
    goto LAB_00101418;
  }
  iVar6 = DATARMNETaba2beb199(lVar15,"r_rmnet_data",0xc);
  if (iVar6 != 0) {
    uVar7 = DATARMNETe447822105();
    iVar6 = DATARMNETaba2beb199(lVar15,uVar7,0x10);
    if (iVar6 != 0) {
      uVar7 = DATARMNET934406764d();
      iVar6 = DATARMNETaba2beb199(lVar15,uVar7,0x10);
      if (iVar6 != 0) goto LAB_00101414;
    }
    uVar7 = DATARMNET37a92021f9(param_1);
    goto LAB_00101418;
  }
  lVar15 = *param_1;
  local_e8 = 0;
  local_f8 = 0;
  lStack_f0 = 0;
  local_108 = 0;
  lStack_100 = 0;
  local_118 = 0;
  local_110 = 0;
  local_128 = 0;
  local_120 = 0;
  if ((lVar15 == 0) || ((*(ushort *)(lVar15 + 0x80) & 7) == 5)) goto LAB_00101414;
  if (*(short *)(lVar15 + 0xb4) == -0x227a) {
    local_c8 = 0;
    uStack_c0 = 0;
    local_d8 = 0;
    local_d0 = 0;
    local_e0 = 0;
    if (*(int *)(lVar15 + 0x70) - *(int *)(lVar15 + 0x74) < 0x28) {
      iVar6 = skb_copy_bits(lVar15,0,&local_e0,0x28);
      if (-1 < iVar6) {
        puVar17 = &local_d8;
        goto LAB_001014c8;
      }
      goto LAB_001017a8;
    }
    if (*(long *)(lVar15 + 0xe0) == 0) goto LAB_001017a8;
    puVar17 = (undefined8 *)(*(long *)(lVar15 + 0xe0) + 8);
LAB_001014c8:
    local_120 = *puVar17;
    local_118 = puVar17[1];
    local_110 = CONCAT71(local_110._1_7_,6);
LAB_001014d8:
    __rcu_read_lock();
    lVar8 = DATARMNETcc0a01df2a(&local_128);
    __rcu_read_unlock();
    if (lVar8 == 0) goto LAB_001017a8;
    cVar18 = *(char *)(lVar8 + 0x61);
    if (cVar18 != '\x03') {
      if (*(long *)(lVar15 + 0x10) != 0) {
        *(undefined8 *)(lVar15 + 0x68) = 7;
        *(uint *)(lVar15 + 0x82) = *(uint *)(lVar15 + 0x82) | 0x10000;
      }
      if (*(short *)(lVar15 + 0xb4) == -0x227a) {
        local_c8 = 0;
        uStack_c0 = 0;
        local_d8 = 0;
        local_d0 = 0;
        local_e0 = 0;
        local_80[0] = local_80[0] & 0xffffffffffff0000;
        if (*(int *)(lVar15 + 0x70) - *(int *)(lVar15 + 0x74) < 0x28) {
          puVar17 = &local_e0;
          iVar6 = skb_copy_bits(lVar15,0,&local_e0,0x28);
          if (-1 < iVar6) goto LAB_001015a4;
        }
        else {
          puVar17 = *(undefined8 **)(lVar15 + 0xe0);
          if (puVar17 != (undefined8 *)0x0) {
LAB_001015a4:
            local_12c[0] = *(char *)((long)puVar17 + 6);
            iVar6 = ipv6_skip_exthdr(lVar15,0x28,local_12c,local_80);
            if ((-1 < iVar6) && (((short)local_80[0] == 0 || (local_12c[0] != ',')))) {
              if (local_12c[0] == '\x06') goto LAB_001016ac;
              if (local_12c[0] == ':') {
                local_108 = puVar17[1];
                lStack_100 = puVar17[2];
                bVar4 = false;
                cVar20 = '\x06';
                uVar9 = puVar17[3];
                lStack_f0 = puVar17[4];
                local_f8 = uVar9;
                goto LAB_00101600;
              }
            }
          }
        }
      }
      else if (*(short *)(lVar15 + 0xb4) == 8) {
        local_d0 = local_d0 & 0xffffffff00000000;
        local_e0 = 0;
        local_d8 = 0;
        if (*(int *)(lVar15 + 0x70) - *(int *)(lVar15 + 0x74) < 0x14) {
          puVar17 = &local_e0;
          iVar6 = skb_copy_bits(lVar15,0,&local_e0,0x14);
          if (-1 < iVar6) goto LAB_00101550;
        }
        else {
          puVar17 = *(undefined8 **)(lVar15 + 0xe0);
          if (puVar17 != (undefined8 *)0x0) {
LAB_00101550:
            if (*(char *)((long)puVar17 + 9) == '\x06') {
LAB_001016ac:
              DATARMNET7ca470d54b(lVar15,0x200);
            }
            else {
              if (*(char *)((long)puVar17 + 9) != '\x01') goto LAB_001017ac;
              uVar9 = (ulong)*(uint *)(puVar17 + 2);
              cVar20 = '\x04';
              bVar4 = true;
              local_108 = CONCAT44(local_108._4_4_,*(undefined4 *)((long)puVar17 + 0xc));
              local_f8 = CONCAT44(local_f8._4_4_,*(uint *)(puVar17 + 2));
LAB_00101600:
              local_e8 = CONCAT31(local_e8._1_3_,cVar20);
              __rcu_read_lock();
              plVar1 = &DATARMNET5413d6f8ec + ((uint)((int)uVar9 * 0x61c88647) >> 0x1c);
              plVar12 = (long *)*plVar1;
              if (plVar12 != (long *)0x0) {
                do {
                  if (((char)plVar12[0xb] == '\0') && ((char)plVar12[8] == cVar20)) {
                    if (bVar4) {
                      if (((int)plVar12[4] == (int)local_108) && ((int)plVar12[6] == (int)uVar9))
                      goto LAB_00101698;
                    }
                    else if ((plVar12[4] == local_108 && plVar12[5] == lStack_100) &&
                            (plVar12[6] == local_f8 && plVar12[7] == lStack_f0)) {
LAB_00101698:
                      plVar12[10] = _jiffies;
                      __rcu_read_unlock();
                      goto LAB_001017ac;
                    }
                  }
                  plVar12 = (long *)*plVar12;
                } while (plVar12 != (long *)0x0);
              }
              __rcu_read_unlock();
              uVar7 = _raw_spin_lock_irqsave(&DATARMNET820642743b);
              plVar12 = (long *)kmalloc_trace(_dst_release,0xb20,0x60);
              if (plVar12 != (long *)0x0) {
                plVar12[9] = lVar8 + 0x48;
                plVar12[6] = local_f8;
                plVar12[7] = lStack_f0;
                lVar8 = *plVar1;
                *(undefined4 *)(plVar12 + 8) = local_e8;
                *plVar12 = lVar8;
                plVar12[4] = local_108;
                plVar12[5] = lStack_100;
                plVar12[1] = (long)plVar1;
                *plVar1 = (long)plVar12;
                if (lVar8 != 0) {
                  *(long **)(lVar8 + 8) = plVar12;
                }
                if (DATARMNETf658004dbc == 0) {
                  queue_delayed_work_on(0x20,_system_wq,&DATARMNET0b04fde883,0x7d);
                }
                DATARMNETf658004dbc = DATARMNETf658004dbc + 1;
              }
              _raw_spin_unlock_irqrestore(&DATARMNET820642743b,uVar7);
            }
          }
        }
      }
    }
  }
  else {
    if (*(short *)(lVar15 + 0xb4) == 8) {
      local_d0 = local_d0 & 0xffffffff00000000;
      local_e0 = 0;
      local_d8 = 0;
      if (*(int *)(lVar15 + 0x70) - *(int *)(lVar15 + 0x74) < 0x14) {
        iVar6 = skb_copy_bits(lVar15,0,&local_e0,0x14);
        if (-1 < iVar6) {
          puVar11 = (undefined4 *)((long)&local_d8 + 4);
          goto LAB_0010148c;
        }
      }
      else if (*(long *)(lVar15 + 0xe0) != 0) {
        puVar11 = (undefined4 *)(*(long *)(lVar15 + 0xe0) + 0xc);
LAB_0010148c:
        local_120 = CONCAT44(local_120._4_4_,*puVar11);
        local_110 = CONCAT71(local_110._1_7_,4);
        goto LAB_001014d8;
      }
    }
LAB_001017a8:
    cVar18 = '\x03';
  }
LAB_001017ac:
  if ((*(int *)(lVar15 + 0x74) != 0) && (*(int *)(lVar15 + 0x70) == *(int *)(lVar15 + 0x74))) {
    if (*(short *)(lVar15 + 0xb4) == 8) {
      uVar7 = 0x14;
LAB_001017e4:
      lVar8 = __pskb_pull_tail(lVar15,uVar7);
      if (lVar8 != 0) {
        *(short *)(lVar15 + 0xb8) =
             (short)*(undefined4 *)(lVar15 + 0xe0) - (short)*(undefined4 *)(lVar15 + 0xd8);
        DATARMNET17f6bc1be5(0x2c);
        goto LAB_00101808;
      }
      uVar7 = 0x2d;
    }
    else {
      if (*(short *)(lVar15 + 0xb4) == -0x227a) {
        uVar7 = 0x28;
        goto LAB_001017e4;
      }
      uVar7 = 0x2b;
    }
    goto LAB_001022b8;
  }
LAB_00101808:
  if (*(long *)(lVar15 + 0x10) == 0) {
LAB_001022bc:
    kfree_skb_reason(lVar15,1);
  }
  else {
    sVar3 = *(short *)(lVar15 + 0xb4);
    if ((cVar18 != '\x02') || (sVar3 != 8)) {
      if ((cVar18 == '\x02') && (sVar3 == -0x227a)) {
        local_68[0] = 0;
        local_68[1] = 0;
        local_80[1] = 0;
        local_70 = 0;
        local_88 = 0;
        local_80[0] = 0;
        local_98 = 0;
        uStack_90 = 0;
        local_a8 = 0;
        local_a0 = 0;
        local_b8 = 0;
        local_b0 = 0;
        local_c8 = 0;
        uStack_c0 = 0;
        local_d8 = 0;
        local_d0 = 0;
        local_e0 = 0;
        if (*(int *)(lVar15 + 0x70) - *(int *)(lVar15 + 0x74) < 0x28) {
          puVar16 = local_80;
          iVar6 = skb_copy_bits(lVar15,0,local_80,0x28);
          if (iVar6 < 0) goto LAB_00102228;
        }
        else {
          puVar16 = *(ulong **)(lVar15 + 0xe0);
          if (puVar16 == (ulong *)0x0) {
LAB_00102228:
            uVar7 = 9;
            goto LAB_001022b8;
          }
        }
        uVar7 = DATARMNET934406764d();
        lVar8 = dev_get_by_name_rcu(&init_net,uVar7);
        if (lVar8 == 0) {
          uVar7 = 10;
        }
        else {
          *(long *)(lVar15 + 0x10) = lVar8;
          local_d0._0_4_ = CONCAT13(2,(undefined3)local_d0);
          local_a0 = puVar16[1];
          local_98 = puVar16[2];
          local_b0 = puVar16[3];
          local_a8 = puVar16[4];
          local_e0 = CONCAT44(local_e0._4_4_,*(undefined4 *)(lVar8 + 0xd8));
          if (*(int *)(*(code **)(_ipv6_stub + 0x10) + -4) != -0x7ece3563) {
                    /* WARNING: Does not return */
            pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10198c);
            (*pcVar13)();
          }
          uVar9 = (**(code **)(_ipv6_stub + 0x10))(&init_net,0,&local_e0,0);
          if (uVar9 < 0xfffffffffffff001) {
            pcVar13 = *(code **)(*(long *)(uVar9 + 8) + 0x68);
            if (*(int *)(pcVar13 + -4) != 0x2f8e2e7) {
                    /* WARNING: Does not return */
              pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x101d88);
              (*pcVar13)();
            }
            uVar10 = (*pcVar13)(uVar9,0,&local_b0);
            dst_release(uVar9);
            if ((uVar10 < 0xfffffffffffff001) && (uVar10 != 0)) {
              if ((*(long *)(uVar10 + 0x178) == *(long *)(lVar15 + 0x10)) &&
                 (*(long *)(*(long *)(uVar10 + 0x178) + 0x218) != 0)) {
                uVar9 = neigh_resolve_output(uVar10,lVar15);
                neigh_release(uVar10);
                iVar6 = 3;
                if ((uVar9 & 0xfffffffd) == 0) {
                  iVar6 = 1;
                }
                goto LAB_001021d0;
              }
              DATARMNET17f6bc1be5(0xd);
              neigh_release(uVar10);
              goto LAB_001022bc;
            }
            uVar7 = 0xc;
          }
          else {
            uVar7 = 0xb;
          }
        }
      }
      else if ((cVar18 == '\x01') && (sVar3 == 8)) {
        local_70 = (ulong)uStack_6c << 0x20;
        local_80[0] = 0;
        local_80[1] = 0;
        local_a8 = 0;
        local_b8 = 0;
        local_b0 = 0;
        local_c8 = 0;
        uStack_c0 = 0;
        local_d8 = 0;
        local_d0 = 0;
        local_e0 = 0;
        if (*(int *)(lVar15 + 0x70) - *(int *)(lVar15 + 0x74) < 0x14) {
          puVar16 = local_80;
          iVar6 = skb_copy_bits(lVar15,0,local_80,0x14);
          if (iVar6 < 0) goto LAB_00102250;
        }
        else {
          puVar16 = *(ulong **)(lVar15 + 0xe0);
          if (puVar16 == (ulong *)0x0) {
LAB_00102250:
            uVar7 = 0x29;
            goto LAB_001022b8;
          }
        }
        uVar7 = DATARMNETe447822105();
        lVar8 = dev_get_by_name_rcu(&init_net,uVar7);
        if (lVar8 == 0) {
          uVar7 = 0x26;
        }
        else {
          local_b0 = CONCAT44((int)puVar16[2],(undefined4)local_b0);
          local_e0 = CONCAT44(local_e0._4_4_,*(undefined4 *)(lVar8 + 0xd8));
          local_d0._0_4_ = CONCAT13(2,(undefined3)local_d0);
          uVar9 = ip_route_output_flow(&init_net,&local_e0,0);
          if (uVar9 < 0xfffffffffffff001) {
LAB_00101dd0:
            local_b0 = CONCAT44(local_b0._4_4_,*(undefined4 *)((long)puVar16 + 0xc));
            uVar9 = xfrm_lookup(&init_net,uVar9,&local_e0,0,0);
            if (uVar9 < 0xfffffffffffff001) {
              *(ulong *)(lVar15 + 0x58) = uVar9;
              uVar5 = *(uint *)(lVar15 + 0x82) >> 0x10 & 1;
              if (uVar9 != 0) {
                uVar5 = 1;
              }
              uVar14 = 0x10000;
              if (uVar5 == 0) {
                uVar14 = 0;
              }
              *(uint *)(lVar15 + 0x82) = uVar14 | *(uint *)(lVar15 + 0x82) & 0xfffeffff;
              pcVar13 = *(code **)((uVar9 & 0xfffffffffffffffe) + 0x30);
              if (*(int *)(pcVar13 + -4) != -0x7147d0a9) {
                    /* WARNING: Does not return */
                pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x101ff0);
                (*pcVar13)();
              }
              (*pcVar13)(&init_net,0,lVar15);
              iVar6 = 0x23;
              goto LAB_001021d0;
            }
            uVar7 = 0x22;
          }
          else {
            DATARMNET17f6bc1be5(0x28,uVar9);
            lVar8 = dev_get_by_name_rcu(&init_net,"dummy0");
            if (lVar8 == 0) {
              uVar7 = 0x24;
            }
            else {
              local_e0 = CONCAT44(local_e0._4_4_,*(undefined4 *)(lVar8 + 0xd8));
              local_d0._0_4_ = CONCAT13(2,(undefined3)local_d0);
              uVar9 = ip_route_output_flow(&init_net,&local_e0,0);
              if (uVar9 < 0xfffffffffffff001) goto LAB_00101dd0;
              uVar7 = 0x25;
            }
          }
        }
      }
      else {
        puVar16 = local_68;
        puVar19 = local_80 + 1;
        if ((cVar18 == '\x01') && (sVar3 == -0x227a)) {
          local_68[0] = 0;
          local_68[1] = 0;
          local_80[1] = 0;
          local_70 = 0;
          local_88 = 0;
          local_80[0] = 0;
          local_98 = 0;
          uStack_90 = 0;
          local_a8 = 0;
          local_a0 = 0;
          local_b8 = 0;
          local_b0 = 0;
          local_c8 = 0;
          uStack_c0 = 0;
          local_d8 = 0;
          local_d0 = 0;
          local_e0 = 0;
          if (*(int *)(lVar15 + 0x70) - *(int *)(lVar15 + 0x74) < 0x28) {
            iVar6 = skb_copy_bits(lVar15,0,local_80,0x28);
            if (iVar6 < 0) goto LAB_001022b4;
          }
          else {
            lVar8 = *(long *)(lVar15 + 0xe0);
            if (lVar8 == 0) {
LAB_001022b4:
              uVar7 = 0x1a;
              goto LAB_001022b8;
            }
            puVar16 = (ulong *)(lVar8 + 0x18);
            puVar19 = (ulong *)(lVar8 + 8);
          }
          local_a0 = *puVar19;
          local_98 = puVar19[1];
          local_b0 = *puVar16;
          local_a8 = puVar16[1];
          if (*(int *)(*(code **)(_ipv6_stub + 0x10) + -4) != -0x7ece3563) {
                    /* WARNING: Does not return */
            pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x101b50);
            (*pcVar13)();
          }
          uVar9 = (**(code **)(_ipv6_stub + 0x10))(&init_net,0,&local_e0,0);
          if (uVar9 < 0xfffffffffffff001) {
LAB_00101f34:
            uVar9 = xfrm_lookup(&init_net,uVar9,&local_e0,0,0);
            if (uVar9 < 0xfffffffffffff001) {
              *(ulong *)(lVar15 + 0x58) = uVar9;
              uVar5 = *(uint *)(lVar15 + 0x82) >> 0x10 & 1;
              if (uVar9 != 0) {
                uVar5 = 1;
              }
              uVar14 = 0x10000;
              if (uVar5 == 0) {
                uVar14 = 0;
              }
              *(uint *)(lVar15 + 0x82) = uVar14 | *(uint *)(lVar15 + 0x82) & 0xfffeffff;
              pcVar13 = *(code **)((uVar9 & 0xfffffffffffffffe) + 0x30);
              if (*(int *)(pcVar13 + -4) != -0x7147d0a9) {
                    /* WARNING: Does not return */
                pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x102058);
                (*pcVar13)();
              }
              (*pcVar13)(&init_net,0,lVar15);
              iVar6 = 0x1d;
              goto LAB_001021d0;
            }
            uVar7 = 0x1c;
          }
          else {
            DATARMNET17f6bc1be5(0x1b,uVar9);
            lVar8 = dev_get_by_name_rcu(&init_net,"dummy0");
            if (lVar8 == 0) {
              uVar7 = 0x1e;
            }
            else {
              local_d0._0_4_ = CONCAT13(2,(undefined3)local_d0);
              local_e0 = CONCAT44(local_e0._4_4_,*(undefined4 *)(lVar8 + 0xd8));
              if (*(int *)(*(code **)(_ipv6_stub + 0x10) + -4) != -0x7ece3563) {
                    /* WARNING: Does not return */
                pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x101bc4);
                (*pcVar13)();
              }
              uVar9 = (**(code **)(_ipv6_stub + 0x10))(&init_net,0,&local_e0,0);
              if (uVar9 < 0xfffffffffffff001) goto LAB_00101f34;
              uVar7 = 0x1f;
            }
          }
        }
        else {
          if ((cVar18 == '\0') && (sVar3 == 8)) {
            local_70 = (ulong)uStack_6c << 0x20;
            local_80[0] = 0;
            local_80[1] = 0;
            local_a8 = 0;
            local_b8 = 0;
            local_b0 = 0;
            local_c8 = 0;
            uStack_c0 = 0;
            local_d8 = 0;
            local_d0 = 0;
            local_e0 = 0;
            if (*(int *)(lVar15 + 0x70) - *(int *)(lVar15 + 0x74) < 0x14) {
              puVar16 = local_80;
              iVar6 = skb_copy_bits(lVar15,0,local_80,0x14);
              if (-1 < iVar6) goto LAB_00101cac;
            }
            else {
              puVar16 = *(ulong **)(lVar15 + 0xe0);
              if (puVar16 != (ulong *)0x0) {
LAB_00101cac:
                uVar7 = DATARMNET934406764d();
                lVar8 = dev_get_by_name_rcu(&init_net,uVar7);
                if (lVar8 == 0) {
                  uVar7 = 0x2a;
                }
                else {
                  local_b0 = CONCAT44((int)puVar16[2],(undefined4)local_b0);
                  local_e0 = CONCAT44(local_e0._4_4_,*(undefined4 *)(lVar8 + 0xd8));
                  local_d0._0_4_ = CONCAT13(2,(undefined3)local_d0);
                  uVar9 = ip_route_output_flow(&init_net,&local_e0,0);
                  if (uVar9 < 0xfffffffffffff001) {
LAB_0010209c:
                    local_b0 = CONCAT44(local_b0._4_4_,*(undefined4 *)((long)puVar16 + 0xc));
                    uVar9 = xfrm_lookup(&init_net,uVar9,&local_e0,0,0);
                    if (uVar9 < 0xfffffffffffff001) {
                      *(ulong *)(lVar15 + 0x58) = uVar9;
                      uVar5 = *(uint *)(lVar15 + 0x82) >> 0x10 & 1;
                      if (uVar9 != 0) {
                        uVar5 = 1;
                      }
                      uVar14 = 0x10000;
                      if (uVar5 == 0) {
                        uVar14 = 0;
                      }
                      *(uint *)(lVar15 + 0x82) = uVar14 | *(uint *)(lVar15 + 0x82) & 0xfffeffff;
                      pcVar13 = *(code **)((uVar9 & 0xfffffffffffffffe) + 0x30);
                      if (*(int *)(pcVar13 + -4) != -0x7147d0a9) {
                    /* WARNING: Does not return */
                        pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x102160);
                        (*pcVar13)();
                      }
                      (*pcVar13)(&init_net,0,lVar15);
                      iVar6 = 0x15;
                      goto LAB_001021d0;
                    }
                    uVar7 = 0x14;
                  }
                  else {
                    DATARMNET17f6bc1be5(0x13,uVar9);
                    lVar8 = dev_get_by_name_rcu(&init_net,"dummy0");
                    if (lVar8 == 0) {
                      uVar7 = 0x18;
                    }
                    else {
                      local_e0 = CONCAT44(local_e0._4_4_,*(undefined4 *)(lVar8 + 0xd8));
                      local_d0._0_4_ = CONCAT13(2,(undefined3)local_d0);
                      uVar9 = ip_route_output_flow(&init_net,&local_e0,0);
                      if (uVar9 < 0xfffffffffffff001) goto LAB_0010209c;
                      uVar7 = 0x19;
                    }
                  }
                }
                goto LAB_001022b8;
              }
            }
            goto LAB_00102204;
          }
          if ((cVar18 != '\0') || (sVar3 != -0x227a)) goto LAB_001022bc;
          local_68[0] = 0;
          local_68[1] = 0;
          local_80[1] = 0;
          local_70 = 0;
          local_88 = 0;
          local_80[0] = 0;
          local_98 = 0;
          uStack_90 = 0;
          local_a8 = 0;
          local_a0 = 0;
          local_b8 = 0;
          local_b0 = 0;
          local_c8 = 0;
          uStack_c0 = 0;
          local_d8 = 0;
          local_d0 = 0;
          local_e0 = 0;
          if (*(int *)(lVar15 + 0x70) - *(int *)(lVar15 + 0x74) < 0x28) {
            iVar6 = skb_copy_bits(lVar15,0,local_80,0x28);
            if (iVar6 < 0) goto LAB_0010230c;
          }
          else {
            lVar8 = *(long *)(lVar15 + 0xe0);
            if (lVar8 == 0) {
LAB_0010230c:
              uVar7 = 0xe;
              goto LAB_001022b8;
            }
            puVar16 = (ulong *)(lVar8 + 0x18);
            puVar19 = (ulong *)(lVar8 + 8);
          }
          local_a0 = *puVar19;
          local_98 = puVar19[1];
          local_b0 = *puVar16;
          local_a8 = puVar16[1];
          if (*(int *)(*(code **)(_ipv6_stub + 0x10) + -4) != -0x7ece3563) {
                    /* WARNING: Does not return */
            pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x101ea0);
            (*pcVar13)();
          }
          uVar9 = (**(code **)(_ipv6_stub + 0x10))(&init_net,0,&local_e0,0);
          if (uVar9 < 0xfffffffffffff001) {
LAB_001020dc:
            uVar9 = xfrm_lookup(&init_net,uVar9,&local_e0,0,0);
            if (uVar9 < 0xfffffffffffff001) {
              *(ulong *)(lVar15 + 0x58) = uVar9;
              uVar5 = *(uint *)(lVar15 + 0x82) >> 0x10 & 1;
              if (uVar9 != 0) {
                uVar5 = 1;
              }
              uVar14 = 0x10000;
              if (uVar5 == 0) {
                uVar14 = 0;
              }
              *(uint *)(lVar15 + 0x82) = uVar14 | *(uint *)(lVar15 + 0x82) & 0xfffeffff;
              pcVar13 = *(code **)((uVar9 & 0xfffffffffffffffe) + 0x30);
              if (*(int *)(pcVar13 + -4) != -0x7147d0a9) {
                    /* WARNING: Does not return */
                pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x1021c8);
                (*pcVar13)();
              }
              (*pcVar13)(&init_net,0,lVar15);
              iVar6 = 0x11;
              goto LAB_001021d0;
            }
            uVar7 = 0x10;
          }
          else {
            DATARMNET17f6bc1be5(0xf,uVar9);
            lVar8 = dev_get_by_name_rcu(&init_net,"dummy0");
            if (lVar8 == 0) {
              uVar7 = 0x16;
            }
            else {
              local_d0._0_4_ = CONCAT13(2,(undefined3)local_d0);
              local_e0 = CONCAT44(local_e0._4_4_,*(undefined4 *)(lVar8 + 0xd8));
              if (*(int *)(*(code **)(_ipv6_stub + 0x10) + -4) != -0x7ece3563) {
                    /* WARNING: Does not return */
                pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x101f14);
                (*pcVar13)();
              }
              uVar9 = (**(code **)(_ipv6_stub + 0x10))(&init_net,0,&local_e0,0);
              if (uVar9 < 0xfffffffffffff001) goto LAB_001020dc;
              uVar7 = 0x17;
            }
          }
        }
      }
LAB_001022b8:
      DATARMNET17f6bc1be5(uVar7);
      goto LAB_001022bc;
    }
    local_70 = (ulong)uStack_6c << 0x20;
    local_80[0] = 0;
    local_80[1] = 0;
    local_a8 = 0;
    local_b8 = 0;
    local_b0 = 0;
    local_c8 = 0;
    uStack_c0 = 0;
    local_d8 = 0;
    local_d0 = 0;
    local_e0 = 0;
    if (*(int *)(lVar15 + 0x70) - *(int *)(lVar15 + 0x74) < 0x14) {
      puVar16 = local_80;
      iVar6 = skb_copy_bits(lVar15,0,local_80,0x14);
      if (iVar6 < 0) goto LAB_00102204;
    }
    else {
      puVar16 = *(ulong **)(lVar15 + 0xe0);
      if (puVar16 == (ulong *)0x0) {
LAB_00102204:
        uVar7 = 0x12;
        goto LAB_001022b8;
      }
    }
    uVar7 = DATARMNET934406764d();
    lVar8 = dev_get_by_name_rcu(&init_net,uVar7);
    if (lVar8 == 0) {
      uVar7 = 5;
      goto LAB_001022b8;
    }
    *(long *)(lVar15 + 0x10) = lVar8;
    local_b0 = CONCAT44(local_b0._4_4_,*(undefined4 *)((long)puVar16 + 0xc));
    local_b0 = *(ulong *)((long)puVar16 + 0xc);
    local_e0 = CONCAT44(local_e0._4_4_,*(undefined4 *)(lVar8 + 0xd8));
    local_d0._0_4_ = CONCAT13(2,(undefined3)local_d0);
    uVar9 = ip_route_output_flow(&init_net,&local_e0,0);
    if (0xfffffffffffff000 < uVar9) {
      uVar7 = 6;
      goto LAB_001022b8;
    }
    pcVar13 = *(code **)(*(long *)(uVar9 + 8) + 0x68);
    if (*(int *)(pcVar13 + -4) != 0x2f8e2e7) {
                    /* WARNING: Does not return */
      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x101c10);
      (*pcVar13)();
    }
    uVar10 = (*pcVar13)(uVar9,0,(long)&local_b0 + 4);
    dst_release(uVar9);
    if ((0xfffffffffffff000 < uVar10) || (uVar10 == 0)) {
      uVar7 = 7;
      goto LAB_001022b8;
    }
    if ((*(long *)(uVar10 + 0x178) != *(long *)(lVar15 + 0x10)) ||
       (*(long *)(*(long *)(uVar10 + 0x178) + 0x218) == 0)) {
      DATARMNET17f6bc1be5(8);
      piVar2 = (int *)(uVar10 + 0x30);
      Hint_Prefetch(piVar2,2,0,1);
      do {
        iVar6 = *piVar2;
        cVar18 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar2,0x10);
        if (bVar4) {
          *piVar2 = iVar6 + -1;
          cVar18 = ExclusiveMonitorsStatus();
        }
      } while (cVar18 != '\0');
      if (iVar6 == 1) {
        DataMemoryBarrier(2,1);
        neigh_destroy(uVar10);
      }
      else if (iVar6 < 1) {
        refcount_warn_saturate(piVar2,3);
      }
      goto LAB_001022bc;
    }
    uVar9 = neigh_resolve_output(uVar10,lVar15);
    neigh_release(uVar10);
    iVar6 = (uint)((uVar9 & 0xfffffffd) != 0) << 1;
LAB_001021d0:
    DATARMNET17f6bc1be5(iVar6);
  }
  uVar7 = 0;
LAB_00101418:
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) != local_68[2]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// neigh_release @ 00102348 size=104
// signature: undefined neigh_release(void)
// callers: [DATARMNETd2f80b03ce]
//------------------------------------------------------------

void neigh_release(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  
  piVar1 = (int *)(param_1 + 0x30);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    iVar2 = *piVar1;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar4) {
      *piVar1 = iVar2 + -1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (iVar2 == 1) {
    DataMemoryBarrier(2,1);
    neigh_destroy(param_1);
  }
  else if (iVar2 < 1) {
    refcount_warn_saturate(piVar1,3);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET579f75aa50 @ 001023c4 size=228
// signature: undefined DATARMNET579f75aa50(void)
// callers: [DATARMNET37a92021f9]
//------------------------------------------------------------

undefined4 DATARMNET579f75aa50(long param_1,undefined2 param_2,long param_3)

{
  long lVar1;
  undefined4 uVar2;
  undefined4 local_48;
  undefined8 local_44;
  long local_3c;
  undefined8 local_34;
  long local_2c;
  undefined8 local_24;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  uVar2 = 0xffffffff;
  local_24 = 0;
  local_2c = 0;
  local_34 = 0;
  local_3c = 0;
  local_44 = 0;
  if ((*(byte *)(param_3 + 5) < 0x33) &&
     ((1L << ((ulong)*(byte *)(param_3 + 5) & 0x3f) & 0x4000000020040U) != 0)) {
    lVar1 = *(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8);
    local_48 = *(undefined4 *)(lVar1 + 0xc);
    local_3c = (ulong)*(uint *)(lVar1 + 0x10) << 0x20;
    local_2c = (ulong)*(ushort *)(lVar1 + 4) << 0x30;
    local_24 = CONCAT44(4,CONCAT22(*(ushort *)(lVar1 + 6) >> 8 |
                                   (*(ushort *)(lVar1 + 6) & 0x1f) << 8,param_2));
    uVar2 = DATARMNET9d6ad3b16f(param_1,param_3,&local_48);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// DATARMNET9d6ad3b16f @ 001024a8 size=900
// signature: undefined DATARMNET9d6ad3b16f(void)
// callers: [DATARMNET579f75aa50, DATARMNETaca8ca54ed]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNET9d6ad3b16f(long *param_1,undefined4 *param_2,long *param_3,long param_4)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  long lVar5;
  int iVar6;
  ulong uVar7;
  undefined4 uVar8;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  long *plVar12;
  undefined8 *puVar13;
  
  uVar11 = 1;
  lVar2 = param_1[0x1b] + (ulong)*(uint *)((long)param_1 + 0xd4);
  if (*(int *)(lVar2 + 0x1c) != 0) goto LAB_001024e0;
  DATARMNET5ca94dbc3c(5);
  *(undefined4 *)(lVar2 + 0x1c) = 1;
  uVar11 = _raw_spin_lock_irqsave(&DATARMNET531b038fcd);
  for (plVar12 = (long *)(&DATARMNET6e79f38051)[(uint)((int)param_3[4] * 0x61c88647) >> 0x1c];
      plVar12 != (long *)0x0; plVar12 = (long *)*plVar12) {
    if (((*(char *)(plVar12 + 0xf) == '\0') && ((char)param_3[5] == *(char *)(plVar12 + 0xc))) &&
       ((int)param_3[4] == *(int *)(plVar12 + 0xb))) {
      if ((char)param_3[5] == '\x04') {
        if (((int)*param_3 == *(int *)(plVar12 + 7)) && ((int)param_3[2] == *(int *)(plVar12 + 9)))
        goto LAB_00102600;
      }
      else if ((*param_3 == plVar12[7] && param_3[1] == plVar12[8]) &&
              (param_3[2] == plVar12[9] && param_3[3] == plVar12[10])) goto LAB_00102600;
    }
  }
  plVar12 = (long *)kmalloc_trace(_dst_release,0xb20,0x80);
  if (plVar12 == (long *)0x0) {
    _raw_spin_unlock_irqrestore(&DATARMNET531b038fcd,uVar11);
    uVar11 = 0xffffffff;
    goto LAB_001024e0;
  }
  *(undefined4 *)(plVar12 + 2) = 0;
  plVar12[3] = (long)(plVar12 + 3);
  plVar12[4] = (long)(plVar12 + 3);
  lVar5 = param_3[4];
  lVar3 = param_3[3];
  lVar10 = param_3[4];
  plVar12[9] = param_3[2];
  plVar12[10] = lVar3;
  plVar1 = &DATARMNET6e79f38051 + ((uint)((int)lVar5 * 0x61c88647) >> 0x1c);
  lVar9 = param_3[5];
  lVar3 = *param_3;
  lVar5 = param_3[1];
  plVar12[0xb] = lVar10;
  *(int *)(plVar12 + 0xc) = (int)lVar9;
  lVar9 = *plVar1;
  plVar12[7] = lVar3;
  plVar12[8] = lVar5;
  *plVar12 = lVar9;
  plVar12[1] = (long)plVar1;
  *plVar1 = (long)plVar12;
  if (lVar9 != 0) {
    *(long **)(lVar9 + 8) = plVar12;
  }
  if (DATARMNETdef6cfba1c == 0) {
    queue_delayed_work_on(0x20,_system_wq,&DATARMNETa41953a37b,0xd);
  }
  DATARMNETdef6cfba1c = DATARMNETdef6cfba1c + 1;
LAB_00102600:
  _raw_spin_unlock_irqrestore(&DATARMNET531b038fcd,uVar11);
  plVar12[0xe] = _jiffies;
  if (plVar12[0xd] != 0) {
    if ((ulong)plVar12[0xd] < 0xfffffffffffff001) {
      iVar6 = DATARMNET4899053671(param_1);
      if (iVar6 == 0) {
        uVar11 = 6;
        goto LAB_001027a4;
      }
      DATARMNET5ca94dbc3c(7);
    }
    uVar11 = 1;
    goto LAB_001024e0;
  }
  if (*(short *)((long)param_3 + 0x26) != 0) {
    uVar11 = _raw_spin_lock_irqsave(plVar12 + 2);
    puVar13 = (undefined8 *)plVar12[4];
    uVar7 = __list_add_valid(param_1,puVar13,plVar12 + 3);
    if ((uVar7 & 1) != 0) {
      plVar12[4] = (long)param_1;
      *param_1 = (long)(plVar12 + 3);
      param_1[1] = (long)puVar13;
      *puVar13 = param_1;
    }
    _raw_spin_unlock_irqrestore(plVar12 + 2,uVar11);
    uVar11 = 8;
    goto LAB_001027a4;
  }
  cVar4 = *(char *)((long)param_2 + 5);
  if (cVar4 == '\x06') {
LAB_00102758:
    *(undefined2 *)param_2 =
         *(undefined2 *)(param_1[0x1c] + (ulong)*(ushort *)((long)param_3 + 0x24) + 2);
    uVar7 = DATARMNETa8b2566e6a(param_1,param_2,*(undefined2 *)((long)param_3 + 0x24));
    if ((uVar7 & 1) == 0) goto LAB_001027c0;
    uVar7 = DATARMNET0a4704e5e0(param_2);
    if ((uVar7 & 1) != 0) {
      kfree_skb_reason(param_1,1);
      uVar11 = 0x12;
LAB_001027a4:
      DATARMNET5ca94dbc3c(uVar11);
      return 0;
    }
    DATARMNET5ca94dbc3c(10);
  }
  else {
    if (cVar4 == '2') {
      *param_2 = *(undefined4 *)(param_1[0x1c] + (ulong)*(ushort *)((long)param_3 + 0x24));
    }
    else if (cVar4 == '\x11') goto LAB_00102758;
LAB_001027c0:
    uVar7 = DATARMNET4eafcdee07(param_2);
    if ((uVar7 & 1) != 0) {
      plVar12[0xd] = param_4;
      iVar6 = DATARMNET4899053671(param_1,param_4);
      uVar8 = 6;
      if (iVar6 != 0) {
        uVar8 = 7;
      }
      DATARMNET5ca94dbc3c(uVar8);
      uVar11 = 1;
      DATARMNETc7c83f614f(plVar12,1);
      if (iVar6 == 0) {
        return 0;
      }
      goto LAB_001024e0;
    }
  }
  plVar12[0xd] = -0x16;
  uVar11 = 1;
  DATARMNETc7c83f614f(plVar12,1);
LAB_001024e0:
  *(undefined4 *)(lVar2 + 0x1c) = 0;
  return uVar11;
}



//------------------------------------------------------------
// DATARMNETaca8ca54ed @ 00102830 size=716
// signature: undefined DATARMNETaca8ca54ed(void)
// callers: [DATARMNET37a92021f9]
//------------------------------------------------------------

void DATARMNETaca8ca54ed(long param_1,short param_2,long param_3,undefined8 param_4)

{
  long lVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  uint uVar9;
  char cVar10;
  char *pcVar11;
  uint local_a8 [2];
  char local_a0 [8];
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined4 local_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  uVar6 = 0xffffffff;
  local_70 = 0;
  local_80 = 0;
  local_78 = 0;
  local_90 = 0;
  local_88 = 0;
  local_98 = 0;
  if ((*(byte *)(param_3 + 5) < 0x33) &&
     ((1L << ((ulong)*(byte *)(param_3 + 5) & 0x3f) & 0x4100000020040U) != 0)) {
    lVar1 = *(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8);
    cVar10 = *(char *)(lVar1 + 6);
    iVar5 = (int)lVar1 - *(int *)(param_1 + 0xe0);
    uVar9 = iVar5 + 0x28;
    local_a0[0] = '\0';
    local_a0[1] = '\0';
    bVar3 = cVar10 == ',';
    uVar7 = ipv6_ext_hdr(cVar10);
    if ((cVar10 != ';') && ((uVar7 & 1) != 0)) {
      iVar5 = -0x28 - iVar5;
      do {
        if ((*(int *)(param_1 + 0x70) + iVar5) - *(int *)(param_1 + 0x74) < 2) {
          if (param_1 == 0) goto LAB_00102abc;
          pcVar11 = local_a0;
          iVar4 = skb_copy_bits(param_1,uVar9,local_a0,2);
          if (iVar4 < 0) goto LAB_00102abc;
        }
        else {
          pcVar11 = (char *)(*(long *)(param_1 + 0xe0) + (long)(int)uVar9);
          if (pcVar11 == (char *)0x0) goto LAB_00102abc;
        }
        if (cVar10 == '+') {
          local_a8[0] = 0;
          if ((*(int *)(param_1 + 0x70) + iVar5) - *(int *)(param_1 + 0x74) < 4) {
            if ((param_1 == 0) || (iVar5 = skb_copy_bits(param_1,uVar9,local_a8,4), iVar5 < 0))
            goto LAB_00102abc;
          }
          else if (*(long *)(param_1 + 0xe0) + (long)(int)uVar9 == 0) goto LAB_00102abc;
          lVar8 = 3;
LAB_00102978:
          iVar5 = (uint)(byte)pcVar11[1] << lVar8;
        }
        else {
          if (cVar10 == '3') {
            lVar8 = 2;
            goto LAB_00102978;
          }
          if (cVar10 == ',') {
            local_a8[0] = local_a8[0] & 0xffff0000;
            if (1 < (int)((*(int *)(param_1 + 0x70) - (uVar9 + *(int *)(param_1 + 0x74))) + -2)) {
              if (*(long *)(param_1 + 0xe0) + (long)(int)(uVar9 + 2) != 0) goto LAB_001029fc;
              goto LAB_00102abc;
            }
            if ((param_1 == 0) || (iVar5 = skb_copy_bits(param_1,uVar9 + 2,local_a8,2), iVar5 < 0))
            goto LAB_00102abc;
            goto LAB_001029fc;
          }
          if (bVar3) goto LAB_001029fc;
          iVar5 = (uint)(byte)pcVar11[1] << 3;
        }
        cVar10 = *pcVar11;
        iVar5 = uVar9 + iVar5;
        uVar9 = iVar5 + 8;
        local_a0[0] = '\0';
        local_a0[1] = '\0';
        bVar3 = cVar10 == ',';
        uVar7 = ipv6_ext_hdr(cVar10);
      } while ((cVar10 != ';') && (iVar5 = -8 - iVar5, (uVar7 & 1) != 0));
    }
    if (bVar3) {
LAB_001029fc:
      local_70 = CONCAT31(local_70._1_3_,6);
      local_98 = *(undefined8 *)(lVar1 + 8);
      local_90 = *(undefined8 *)(lVar1 + 0x10);
      local_88 = *(undefined8 *)(lVar1 + 0x18);
      local_80 = *(undefined8 *)(lVar1 + 0x20);
      lVar1 = *(long *)(param_1 + 0xe0) + (ulong)uVar9;
      uVar2 = *(ushort *)(lVar1 + 2);
      if (*(char *)(param_3 + 5) == ',') {
        param_2 = param_2 + 8;
      }
      local_78 = CONCAT26(uVar2 >> 8 & 0xf8 | uVar2 << 8,
                          CONCAT24(param_2,*(undefined4 *)(lVar1 + 4)));
      uVar6 = DATARMNET9d6ad3b16f(param_1,param_3,&local_98,param_4);
    }
    else {
LAB_00102abc:
      uVar6 = 0xffffffff;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET49c2c17e77 @ 00102b00 size=96
// signature: undefined DATARMNET49c2c17e77(void)
// callers: [init_module]
//------------------------------------------------------------

undefined8 DATARMNET49c2c17e77(void)

{
  DATARMNETa41953a37b = 0xfffffffe0;
  DAT_00106708 = &DAT_00106708;
  DAT_00106710 = &DAT_00106708;
  DAT_00106718 = DATARMNETad2b7fd8f5;
  init_timer_key(&DAT_00106730,&delayed_work_timer_fn,0x200000,0,0);
  return 0;
}



//------------------------------------------------------------
// DATARMNETad2b7fd8f5 @ 00102b64 size=488
// signature: undefined DATARMNETad2b7fd8f5(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETad2b7fd8f5(long param_1)

{
  long lVar1;
  long *plVar2;
  char cVar3;
  long *plVar4;
  long lVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulong uVar9;
  undefined8 uVar10;
  long *plVar11;
  ulong uVar12;
  long *plVar13;
  long lVar14;
  long *plVar15;
  long *plVar16;
  
  uVar7 = _raw_spin_lock_irqsave(&DATARMNET531b038fcd);
  lVar5 = _jiffies;
  cVar3 = *(char *)(param_1 + 0x88);
  lVar14 = 0;
  do {
    plVar16 = (long *)(&DATARMNET6e79f38051)[lVar14];
    while (plVar4 = plVar16, plVar4 != (long *)0x0) {
      plVar16 = (long *)*plVar4;
      if (((char)plVar4[0xf] == '\0') && ((cVar3 != '\0' || (0x19 < (ulong)(lVar5 - plVar4[0xe])))))
      {
        plVar11 = (long *)plVar4[1];
        *(undefined1 *)(plVar4 + 0xf) = 1;
        if (plVar11 != (long *)0x0) {
          *plVar11 = (long)plVar16;
          if (plVar16 != (long *)0x0) {
            plVar16[1] = (long)plVar11;
          }
          plVar4[1] = 0;
        }
        uVar12 = plVar4[0xd];
        uVar8 = _raw_spin_lock_irqsave(plVar4 + 2);
        plVar11 = plVar4 + 3;
        if ((long *)*plVar11 != plVar11) {
          plVar13 = (long *)*plVar11;
          do {
            plVar15 = (long *)*plVar13;
            uVar9 = __list_del_entry_valid(plVar13);
            if ((uVar9 & 1) != 0) {
              lVar1 = *plVar13;
              plVar2 = (long *)plVar13[1];
              *(long **)(lVar1 + 8) = plVar2;
              *plVar2 = lVar1;
            }
            *plVar13 = 0;
            plVar13[1] = 0;
            if (uVar12 == 0 || 0xfffffffffffff000 < uVar12) {
              __netif_rx(plVar13);
            }
            else {
              iVar6 = DATARMNET4899053671(plVar13,uVar12);
              if (iVar6 == 0) {
                uVar10 = 6;
              }
              else {
                __netif_rx(plVar13);
                uVar10 = 7;
              }
              DATARMNET5ca94dbc3c(uVar10);
            }
            plVar13 = plVar15;
          } while (plVar15 != plVar11);
        }
        _raw_spin_unlock_irqrestore(plVar4 + 2,uVar8);
        kvfree_call_rcu(plVar4 + 5,0x28);
        DATARMNET5ca94dbc3c(9);
        DATARMNETdef6cfba1c = DATARMNETdef6cfba1c + -1;
      }
    }
    lVar14 = lVar14 + 1;
  } while (lVar14 != 0x10);
  if (DATARMNETdef6cfba1c != 0) {
    queue_delayed_work_on(0x20,_system_wq,param_1,0xd);
  }
  _raw_spin_unlock_irqrestore(&DATARMNET531b038fcd,uVar7);
  return;
}



//------------------------------------------------------------
// DATARMNET8c0e010dfb @ 00102d50 size=88
// signature: undefined DATARMNET8c0e010dfb(void)
// callers: [DATARMNETbb4efa5b3d]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET8c0e010dfb(void)

{
  cancel_delayed_work_sync(&DATARMNETa41953a37b);
  DAT_00106788 = 1;
  queue_delayed_work_on(0x20,_system_wq,&DATARMNETa41953a37b,0);
  cancel_delayed_work_sync(&DATARMNETa41953a37b);
  return;
}



//------------------------------------------------------------
// DATARMNETedae8262e1 @ 00102dac size=116
// signature: undefined DATARMNETedae8262e1(void)
// callers: [DATARMNETb8b35fdc18, DATARMNETbb4efa5b3d]
//------------------------------------------------------------

void DATARMNETedae8262e1(long param_1)

{
  long lVar1;
  long *plVar2;
  
  __rcu_read_lock();
  lVar1 = 0;
  do {
    for (plVar2 = (long *)(&DATARMNET6e79f38051)[lVar1]; plVar2 != (long *)0x0;
        plVar2 = (long *)*plVar2) {
      if (plVar2[0xd] == param_1) {
        plVar2[0xd] = 0xffffffffffffffea;
      }
    }
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x10);
  __rcu_read_unlock();
  return;
}



//------------------------------------------------------------
// DATARMNETc7c83f614f @ 00102e20 size=296
// signature: undefined DATARMNETc7c83f614f(void)
// callers: [DATARMNET9d6ad3b16f]
//------------------------------------------------------------

void DATARMNETc7c83f614f(long param_1,ulong param_2)

{
  long lVar1;
  long *plVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  ulong uVar6;
  undefined8 uVar7;
  long *plVar8;
  ulong uVar9;
  long *plVar10;
  long *plVar11;
  
  uVar9 = *(ulong *)(param_1 + 0x68);
  pcVar3 = (code *)&netif_receive_skb;
  if ((param_2 & 1) == 0) {
    pcVar3 = __netif_rx;
  }
  uVar5 = _raw_spin_lock_irqsave(param_1 + 0x10);
  plVar8 = (long *)(param_1 + 0x18);
  if ((long *)*plVar8 != plVar8) {
    plVar10 = (long *)*plVar8;
    do {
      plVar11 = (long *)*plVar10;
      uVar6 = __list_del_entry_valid(plVar10);
      if ((uVar6 & 1) != 0) {
        lVar1 = *plVar10;
        plVar2 = (long *)plVar10[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar10 = 0;
      plVar10[1] = 0;
      if (uVar9 == 0 || 0xfffffffffffff000 < uVar9) {
        if (*(int *)(pcVar3 + -4) != 0x1d6d0cb6) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8238,0x102ea8);
          (*pcVar3)();
        }
        (*pcVar3)(plVar10);
      }
      else {
        iVar4 = DATARMNET4899053671(plVar10,uVar9);
        if (iVar4 == 0) {
          uVar7 = 6;
        }
        else {
          if (*(int *)(pcVar3 + -4) != 0x1d6d0cb6) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x8238,0x102f08);
            (*pcVar3)();
          }
          (*pcVar3)(plVar10);
          uVar7 = 7;
        }
        DATARMNET5ca94dbc3c(uVar7);
      }
      plVar10 = plVar11;
    } while (plVar11 != plVar8);
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x10,uVar5);
  return;
}



//------------------------------------------------------------
// DATARMNET72501635c8 @ 00102f4c size=648
// signature: undefined DATARMNET72501635c8(void)
// callers: []
//------------------------------------------------------------

int DATARMNET72501635c8(undefined8 param_1,long param_2)

{
  ushort uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  uint uVar5;
  ushort *puVar6;
  ulong uVar7;
  char *pcVar8;
  undefined8 *puVar9;
  undefined8 local_78;
  long local_70;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_78 = 0;
  local_70 = 0;
  puVar6 = *(ushort **)(*(long *)(param_2 + 0x20) + 8);
  if (puVar6 == (ushort *)0x0) {
    pcVar8 = "Must supply tuple info";
    puVar9 = *(undefined8 **)(param_2 + 0x40);
    do_trace_netlink_extack("Must supply tuple info");
    iVar2 = -0x16;
  }
  else {
    if (*puVar6 < 8) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0;
      uVar5 = *puVar6 - 4;
      puVar6 = puVar6 + 2;
      do {
        uVar1 = *puVar6;
        if (uVar1 < 4 || uVar5 < uVar1) break;
        uVar4 = (ulong)((int)uVar4 + 1);
        uVar7 = (ulong)(uVar1 + 3) & 0x1fffc;
        uVar5 = uVar5 - (int)uVar7;
        puVar6 = (ushort *)((long)puVar6 + uVar7);
      } while (3 < (int)uVar5);
    }
    lVar3 = __kmalloc(uVar4 << 3,0xdc0);
    if (lVar3 != 0) {
      puVar6 = *(ushort **)(*(long *)(param_2 + 0x20) + 8);
      uVar1 = *puVar6;
      if (uVar1 < 8) {
        uVar4 = 0;
      }
      else {
        uVar4 = 0;
        uVar5 = uVar1 - 4;
        puVar6 = puVar6 + 2;
        while (uVar1 = *puVar6, 3 < uVar1 && uVar1 <= uVar5) {
          puVar9 = *(undefined8 **)(param_2 + 0x40);
          if (-1 < (short)puVar6[1]) {
            do_trace_netlink_extack("NLA_F_NESTED is missing");
            iVar2 = -0x16;
            if (puVar9 != (undefined8 *)0x0) {
              *puVar9 = "NLA_F_NESTED is missing";
              puVar9[1] = puVar6;
              puVar9[2] = 0;
            }
            goto LAB_0010311c;
          }
          iVar2 = __nla_parse(&local_78,1,puVar6 + 2,uVar1 - 4,DATARMNET19c5fce390,0x1f,puVar9);
          if (iVar2 != 0) goto LAB_0010311c;
          if (local_70 == 0) {
            puVar9 = *(undefined8 **)(param_2 + 0x40);
            pcVar8 = "Must specify tuple entry";
LAB_001031b0:
            do_trace_netlink_extack(pcVar8);
            if (puVar9 == (undefined8 *)0x0) {
              iVar2 = 0;
            }
            else {
              iVar2 = 0;
              *puVar9 = pcVar8;
            }
            goto LAB_0010311c;
          }
          if ((*(byte *)(local_70 + 8) | 2) != 6) {
            puVar9 = *(undefined8 **)(param_2 + 0x40);
            pcVar8 = "Invalid IP protocol";
            goto LAB_001031b0;
          }
          if ((0x32 < *(byte *)(local_70 + 9)) ||
             ((1L << ((ulong)*(byte *)(local_70 + 9) & 0x3f) & 0x4000000020040U) == 0)) {
            puVar9 = *(undefined8 **)(param_2 + 0x40);
            pcVar8 = "Invalid transport protocol";
            goto LAB_001031b0;
          }
          *(undefined8 *)(lVar3 + uVar4 * 8) = *(undefined8 *)(local_70 + 4);
          uVar4 = (ulong)((int)uVar4 + 1);
          uVar7 = (ulong)(*puVar6 + 3) & 0x1fffc;
          uVar5 = uVar5 - (int)uVar7;
          puVar6 = (ushort *)((long)puVar6 + uVar7);
          if ((int)uVar5 < 4) break;
        }
      }
      iVar2 = DATARMNET53f12a0f7d(lVar3,uVar4,param_2);
LAB_0010311c:
      kfree(lVar3);
      goto LAB_00103124;
    }
    pcVar8 = "Kernel OOM";
    puVar9 = *(undefined8 **)(param_2 + 0x40);
    do_trace_netlink_extack("Kernel OOM");
    iVar2 = -0xc;
  }
  if (puVar9 != (undefined8 *)0x0) {
    *puVar9 = pcVar8;
  }
LAB_00103124:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// DATARMNET41dd9b14ab @ 001031d8 size=544
// signature: undefined DATARMNET41dd9b14ab(void)
// callers: []
//------------------------------------------------------------

int DATARMNET41dd9b14ab(undefined8 param_1,long param_2)

{
  ushort uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  uint uVar5;
  ushort *puVar6;
  ulong uVar7;
  char *pcVar8;
  undefined8 *puVar9;
  undefined8 local_68;
  long local_60;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_68 = 0;
  local_60 = 0;
  puVar6 = *(ushort **)(*(long *)(param_2 + 0x20) + 8);
  if (puVar6 == (ushort *)0x0) {
    puVar9 = *(undefined8 **)(param_2 + 0x40);
    pcVar8 = "Must supply tuple info";
    do_trace_netlink_extack("Must supply tuple info");
    iVar2 = -0x16;
  }
  else {
    if (*puVar6 < 8) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0;
      uVar5 = *puVar6 - 4;
      puVar6 = puVar6 + 2;
      do {
        uVar1 = *puVar6;
        if (uVar1 < 4 || uVar5 < uVar1) break;
        uVar4 = (ulong)((int)uVar4 + 1);
        uVar7 = (ulong)(uVar1 + 3) & 0x1fffc;
        uVar5 = uVar5 - (int)uVar7;
        puVar6 = (ushort *)((long)puVar6 + uVar7);
      } while (3 < (int)uVar5);
    }
    lVar3 = __kmalloc(uVar4 << 3,0xdc0);
    if (lVar3 != 0) {
      puVar6 = *(ushort **)(*(long *)(param_2 + 0x20) + 8);
      uVar1 = *puVar6;
      if (uVar1 < 8) {
        uVar4 = 0;
      }
      else {
        uVar4 = 0;
        uVar5 = uVar1 - 4;
        puVar6 = puVar6 + 2;
        while (uVar1 = *puVar6, 3 < uVar1 && uVar1 <= uVar5) {
          puVar9 = *(undefined8 **)(param_2 + 0x40);
          if (-1 < (short)puVar6[1]) {
            do_trace_netlink_extack("NLA_F_NESTED is missing");
            iVar2 = -0x16;
            if (puVar9 != (undefined8 *)0x0) {
              *puVar9 = "NLA_F_NESTED is missing";
              puVar9[1] = puVar6;
              puVar9[2] = 0;
            }
            goto LAB_0010336c;
          }
          iVar2 = __nla_parse(&local_68,1,puVar6 + 2,uVar1 - 4,DATARMNET19c5fce390,0x1f,puVar9);
          if (iVar2 != 0) goto LAB_0010336c;
          if (local_60 == 0) {
            puVar9 = *(undefined8 **)(param_2 + 0x40);
            do_trace_netlink_extack("Must specify tuple entry");
            iVar2 = -0x16;
            if (puVar9 != (undefined8 *)0x0) {
              *puVar9 = "Must specify tuple entry";
            }
            goto LAB_0010336c;
          }
          *(undefined8 *)(lVar3 + uVar4 * 8) = *(undefined8 *)(local_60 + 4);
          uVar4 = (ulong)((int)uVar4 + 1);
          uVar7 = (ulong)(*puVar6 + 3) & 0x1fffc;
          uVar5 = uVar5 - (int)uVar7;
          puVar6 = (ushort *)((long)puVar6 + uVar7);
          if ((int)uVar5 < 4) break;
        }
      }
      iVar2 = DATARMNET07f6485c9b(lVar3,uVar4,param_2);
LAB_0010336c:
      kfree(lVar3);
      goto LAB_00103374;
    }
    puVar9 = *(undefined8 **)(param_2 + 0x40);
    pcVar8 = "Kernel OOM";
    do_trace_netlink_extack("Kernel OOM");
    iVar2 = -0xc;
  }
  if (puVar9 != (undefined8 *)0x0) {
    *puVar9 = pcVar8;
  }
LAB_00103374:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// DATARMNETf1fa473089 @ 001033fc size=144
// signature: undefined DATARMNETf1fa473089(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETf1fa473089(undefined8 param_1,long param_2)

{
  byte bVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  char *pcVar5;
  undefined8 *puVar6;
  
  lVar3 = *(long *)(*(long *)(param_2 + 0x20) + 0x10);
  if ((lVar3 == 0) || (lVar4 = *(long *)(*(long *)(param_2 + 0x20) + 0x30), lVar4 == 0)) {
    pcVar5 = "Must specify device and network info";
  }
  else {
    bVar1 = *(byte *)(lVar4 + 4);
    if (bVar1 < 3) {
      if (bVar1 == 1) {
        uVar2 = DATARMNET92e5468fc5();
        return uVar2;
      }
      uVar2 = DATARMNET97b2388e63(lVar3 + 4);
      return uVar2;
    }
    pcVar5 = "Network type not supported!";
  }
  puVar6 = *(undefined8 **)(param_2 + 0x40);
  do_trace_netlink_extack(pcVar5);
  if (puVar6 != (undefined8 *)0x0) {
    *puVar6 = pcVar5;
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// DATARMNETcd9478470c @ 00103490 size=208
// signature: undefined DATARMNETcd9478470c(void)
// callers: []
//------------------------------------------------------------

int DATARMNETcd9478470c(undefined8 param_1,long param_2)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  char *pcVar5;
  undefined8 *puVar6;
  
  lVar3 = *(long *)(*(long *)(param_2 + 0x20) + 0x10);
  if ((lVar3 == 0) || (lVar4 = *(long *)(*(long *)(param_2 + 0x20) + 0x30), lVar4 == 0)) {
    puVar6 = *(undefined8 **)(param_2 + 0x40);
    pcVar5 = "Kernel error, unregistering notifier failed";
  }
  else {
    bVar1 = *(byte *)(lVar4 + 4);
    if (bVar1 < 3) {
      if (bVar1 == 1) {
        iVar2 = DATARMNET9d7bb9a63d();
      }
      else {
        iVar2 = DATARMNETa903cd5994(lVar3 + 4,param_2);
      }
      if (iVar2 == 0) {
        return 0;
      }
      puVar6 = *(undefined8 **)(param_2 + 0x40);
      pcVar5 = "Kernel error, unregistering notifier failed";
      do_trace_netlink_extack("Kernel error, unregistering notifier failed");
      if (puVar6 == (undefined8 *)0x0) {
        return iVar2;
      }
      goto LAB_001034f4;
    }
    puVar6 = *(undefined8 **)(param_2 + 0x40);
    pcVar5 = "Network type not supported!";
  }
  do_trace_netlink_extack(pcVar5);
  if (puVar6 == (undefined8 *)0x0) {
    return -0x16;
  }
  iVar2 = -0x16;
LAB_001034f4:
  *puVar6 = pcVar5;
  return iVar2;
}



//------------------------------------------------------------
// DATARMNETb86993aefb @ 00103564 size=444
// signature: undefined DATARMNETb86993aefb(void)
// callers: []
//------------------------------------------------------------

undefined4 DATARMNETb86993aefb(undefined8 param_1,long param_2)

{
  ushort *__s;
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined1 uVar8;
  long lVar9;
  ushort *puVar10;
  undefined8 *puVar11;
  long local_58 [3];
  long local_40;
  long local_38;
  
  lVar9 = sp_el0;
  local_38 = *(long *)(lVar9 + 0x638);
  lVar9 = *(long *)(param_2 + 0x20);
  local_58[2] = 0;
  local_40 = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  if (((*(long *)(lVar9 + 0x18) == 0) || (*(long *)(lVar9 + 0x20) == 0)) ||
     (*(long *)(lVar9 + 0x30) == 0)) {
    pcVar7 = "Must specify FWD device, address, and network";
  }
  else {
    local_40 = (ulong)*(byte *)(*(long *)(lVar9 + 0x30) + 4) << 8;
    puVar10 = *(ushort **)(lVar9 + 0x18);
    __s = puVar10 + 2;
    pcVar7 = strchr((char *)__s,0x3a);
    iVar5 = *puVar10 - 4;
    if (pcVar7 == (char *)0x0) {
      iVar5 = in4_pton(__s,iVar5,local_58 + 1,0xffffffff,0);
      if (iVar5 == 1) {
        uVar8 = 4;
        goto LAB_00103674;
      }
      pcVar7 = "FWD address is invalid in IPv4";
    }
    else {
      iVar5 = in6_pton(__s,iVar5,local_58 + 1,0xffffffff,0);
      if (iVar5 == 1) {
        uVar8 = 6;
LAB_00103674:
        local_40 = CONCAT71(local_40._1_7_,uVar8);
        local_58[0] = dev_get_by_name(*(undefined8 *)(param_2 + 0x28),
                                      *(long *)(*(long *)(param_2 + 0x20) + 0x20) + 4);
        if (local_58[0] != 0) {
          uVar6 = DATARMNET947eb110d2(local_58,param_2);
          if (local_58[0] != 0) {
            lVar9 = sp_el0;
            *(int *)(lVar9 + 0x10) = *(int *)(lVar9 + 0x10) + 1;
            lVar4 = tpidr_el1;
            piVar1 = (int *)(lVar4 + *(long *)(local_58[0] + 0x4d8));
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
          }
          goto LAB_00103628;
        }
        pcVar7 = "Invalid FWD device name";
      }
      else {
        pcVar7 = "FWD address is invalid in IPv6";
      }
    }
  }
  puVar11 = *(undefined8 **)(param_2 + 0x40);
  do_trace_netlink_extack(pcVar7);
  if (puVar11 == (undefined8 *)0x0) {
    uVar6 = 0xffffffea;
  }
  else {
    uVar6 = 0xffffffea;
    *puVar11 = pcVar7;
  }
LAB_00103628:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// DATARMNETc175a08219 @ 00103724 size=444
// signature: undefined DATARMNETc175a08219(void)
// callers: []
//------------------------------------------------------------

undefined4 DATARMNETc175a08219(undefined8 param_1,long param_2)

{
  ushort *__s;
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined1 uVar8;
  long lVar9;
  ushort *puVar10;
  undefined8 *puVar11;
  long local_58 [3];
  long local_40;
  long local_38;
  
  lVar9 = sp_el0;
  local_38 = *(long *)(lVar9 + 0x638);
  lVar9 = *(long *)(param_2 + 0x20);
  local_58[2] = 0;
  local_40 = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  if (((*(long *)(lVar9 + 0x18) == 0) || (*(long *)(lVar9 + 0x20) == 0)) ||
     (*(long *)(lVar9 + 0x30) == 0)) {
    pcVar7 = "Must specify FWD device and address";
  }
  else {
    local_40 = (ulong)*(byte *)(*(long *)(lVar9 + 0x30) + 4) << 8;
    puVar10 = *(ushort **)(lVar9 + 0x18);
    __s = puVar10 + 2;
    pcVar7 = strchr((char *)__s,0x3a);
    iVar5 = *puVar10 - 4;
    if (pcVar7 == (char *)0x0) {
      iVar5 = in4_pton(__s,iVar5,local_58 + 1,0xffffffff,0);
      if (iVar5 == 1) {
        uVar8 = 4;
        goto LAB_00103834;
      }
      pcVar7 = "FWD address is invalid in IPv4";
    }
    else {
      iVar5 = in6_pton(__s,iVar5,local_58 + 1,0xffffffff,0);
      if (iVar5 == 1) {
        uVar8 = 6;
LAB_00103834:
        local_40 = CONCAT71(local_40._1_7_,uVar8);
        local_58[0] = dev_get_by_name(*(undefined8 *)(param_2 + 0x28),
                                      *(long *)(*(long *)(param_2 + 0x20) + 0x20) + 4);
        if (local_58[0] != 0) {
          uVar6 = DATARMNETb8b35fdc18(local_58,param_2);
          if (local_58[0] != 0) {
            lVar9 = sp_el0;
            *(int *)(lVar9 + 0x10) = *(int *)(lVar9 + 0x10) + 1;
            lVar4 = tpidr_el1;
            piVar1 = (int *)(lVar4 + *(long *)(local_58[0] + 0x4d8));
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
          }
          goto LAB_001037e8;
        }
        pcVar7 = "Invalid FWD device name";
      }
      else {
        pcVar7 = "FWD address is invalid in IPv6";
      }
    }
  }
  puVar11 = *(undefined8 **)(param_2 + 0x40);
  do_trace_netlink_extack(pcVar7);
  if (puVar11 == (undefined8 *)0x0) {
    uVar6 = 0xffffffea;
  }
  else {
    uVar6 = 0xffffffea;
    *puVar11 = pcVar7;
  }
LAB_001037e8:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// DATARMNETc5f6c112ec @ 001038e4 size=88
// signature: undefined DATARMNETc5f6c112ec(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETc5f6c112ec(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 *puVar3;
  
  lVar2 = *(long *)(*(long *)(param_2 + 0x20) + 0x28);
  if (lVar2 == 0) {
    puVar3 = *(undefined8 **)(param_2 + 0x40);
    do_trace_netlink_extack("Must specify encap port");
    uVar1 = 0xffffffea;
    if (puVar3 != (undefined8 *)0x0) {
      *puVar3 = "Must specify encap port";
    }
  }
  else {
    uVar1 = DATARMNET8d5a5a7047(*(undefined2 *)(lVar2 + 4));
  }
  return uVar1;
}



//------------------------------------------------------------
// DATARMNETa6aec23397 @ 00103940 size=88
// signature: undefined DATARMNETa6aec23397(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETa6aec23397(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 *puVar3;
  
  lVar2 = *(long *)(*(long *)(param_2 + 0x20) + 0x28);
  if (lVar2 == 0) {
    puVar3 = *(undefined8 **)(param_2 + 0x40);
    do_trace_netlink_extack("Must specify encap port");
    uVar1 = 0xffffffea;
    if (puVar3 != (undefined8 *)0x0) {
      *puVar3 = "Must specify encap port";
    }
  }
  else {
    uVar1 = DATARMNETc97c6a4265(*(undefined2 *)(lVar2 + 4));
  }
  return uVar1;
}



//------------------------------------------------------------
// DATARMNETa4773cb837 @ 0010399c size=32
// signature: undefined DATARMNETa4773cb837(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETa4773cb837(void)

{
  DATARMNET078f6bd384();
  return 0;
}



//------------------------------------------------------------
// DATARMNET16add73734 @ 001039c0 size=88
// signature: undefined DATARMNET16add73734(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET16add73734(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 *puVar3;
  
  lVar2 = *(long *)(*(long *)(param_2 + 0x20) + 0x28);
  if (lVar2 == 0) {
    puVar3 = *(undefined8 **)(param_2 + 0x40);
    do_trace_netlink_extack("Must specify encap port");
    uVar1 = 0xffffffea;
    if (puVar3 != (undefined8 *)0x0) {
      *puVar3 = "Must specify encap port";
    }
  }
  else {
    uVar1 = DATARMNET59b8376224(*(undefined2 *)(lVar2 + 4));
  }
  return uVar1;
}



//------------------------------------------------------------
// DATARMNETb318ed4796 @ 00103a1c size=88
// signature: undefined DATARMNETb318ed4796(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETb318ed4796(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 *puVar3;
  
  lVar2 = *(long *)(*(long *)(param_2 + 0x20) + 0x28);
  if (lVar2 == 0) {
    puVar3 = *(undefined8 **)(param_2 + 0x40);
    do_trace_netlink_extack("Must specify encap port");
    uVar1 = 0xffffffea;
    if (puVar3 != (undefined8 *)0x0) {
      *puVar3 = "Must specify encap port";
    }
  }
  else {
    uVar1 = DATARMNET0b12e969c5(*(undefined2 *)(lVar2 + 4));
  }
  return uVar1;
}



//------------------------------------------------------------
// DATARMNET6a53c4576d @ 00103a78 size=472
// signature: undefined DATARMNET6a53c4576d(void)
// callers: []
//------------------------------------------------------------

void DATARMNET6a53c4576d(undefined8 param_1,long param_2)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  long lVar5;
  undefined8 *puVar6;
  ushort *puVar7;
  ushort *puVar8;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  lVar5 = *(long *)(param_2 + 0x20);
  local_48 = 0;
  local_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_60 = 0;
  puVar7 = *(ushort **)(lVar5 + 0x38);
  if ((((puVar7 == (ushort *)0x0) || (*(long *)(lVar5 + 0x40) == 0)) ||
      (*(long *)(lVar5 + 0x48) == 0)) || (*(long *)(lVar5 + 0x50) == 0)) {
    puVar6 = *(undefined8 **)(param_2 + 0x40);
    pcVar2 = "Must specify FWD device and address";
  }
  else {
    puVar8 = puVar7 + 2;
    pcVar2 = strchr((char *)puVar8,0x3a);
    if (pcVar2 == (char *)0x0) {
      iVar1 = in4_pton(puVar8,*puVar7 - 4,&local_60,0xffffffff,0);
      if (iVar1 == 1) {
        uVar4 = 4;
        goto LAB_00103b80;
      }
      puVar6 = *(undefined8 **)(param_2 + 0x40);
      pcVar2 = "SRC address is invalid in IPv4";
    }
    else {
      iVar1 = in6_pton(puVar8,*puVar7 - 4,&local_60,0xffffffff,0);
      if (iVar1 == 1) {
        uVar4 = 6;
LAB_00103b80:
        local_40._0_5_ = CONCAT14(uVar4,(undefined4)local_40);
        puVar8 = *(ushort **)(*(long *)(param_2 + 0x20) + 0x40);
        puVar7 = puVar8 + 2;
        pcVar2 = strchr((char *)puVar7,0x3a);
        iVar1 = *puVar8 - 4;
        if (pcVar2 == (char *)0x0) {
          iVar1 = in4_pton(puVar7,iVar1,&uStack_50,0xffffffff,0);
          if (iVar1 == 1) goto LAB_00103c10;
          puVar6 = *(undefined8 **)(param_2 + 0x40);
          pcVar2 = "DST address is invalid in IPv4";
        }
        else {
          iVar1 = in6_pton(puVar7,iVar1,&uStack_50,0xffffffff,0);
          if (iVar1 == 1) {
LAB_00103c10:
            local_40._0_4_ =
                 CONCAT22(*(undefined2 *)(*(long *)(*(long *)(param_2 + 0x20) + 0x50) + 4),
                          *(undefined2 *)(*(long *)(*(long *)(param_2 + 0x20) + 0x48) + 4));
            DATARMNET4c1c11d8a5(&local_60);
            uVar3 = 0;
            goto LAB_00103b38;
          }
          puVar6 = *(undefined8 **)(param_2 + 0x40);
          pcVar2 = "DST address is invalid in IPv6";
        }
      }
      else {
        puVar6 = *(undefined8 **)(param_2 + 0x40);
        pcVar2 = "SRC address is invalid in IPv6";
      }
    }
  }
  do_trace_netlink_extack(pcVar2);
  if (puVar6 == (undefined8 *)0x0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0xffffffea;
    *puVar6 = pcVar2;
  }
LAB_00103b38:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET425149b729 @ 00103c54 size=32
// signature: undefined DATARMNET425149b729(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET425149b729(void)

{
  DATARMNET56fde5181e();
  return 0;
}



//------------------------------------------------------------
// DATARMNETc0cc5d08ba @ 00103c78 size=148
// signature: undefined DATARMNETc0cc5d08ba(void)
// callers: []
//------------------------------------------------------------

void DATARMNETc0cc5d08ba(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  long local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  uVar2 = DATARMNETe14c875532(&local_30,&DATARMNET61e8f41aae,param_2);
  if ((int)uVar2 == 0) {
    if (local_30 == 0) {
      uVar2 = 0xffffffea;
    }
    else {
      netlink_unicast(*(undefined8 *)(*(long *)(param_2 + 0x28) + 0x118),local_30,
                      *(undefined4 *)(param_2 + 4),0x40);
      uVar2 = 0;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// DATARMNETcc0a01df2a @ 00103d38 size=108
// signature: undefined DATARMNETcc0a01df2a(void)
// callers: [DATARMNETd2f80b03ce]
//------------------------------------------------------------

void DATARMNETcc0a01df2a(long param_1)

{
  long *plVar1;
  
  plVar1 = (long *)(&DATARMNET78ed39f13b)[(uint)(*(int *)(param_1 + 8) * 0x61c88647) >> 0x1c];
  if (plVar1 != (long *)0x0) {
    do {
      if ((char)plVar1[0xc] == *(char *)(param_1 + 0x18)) {
        if (*(char *)(param_1 + 0x18) == '\x04') {
          if ((int)plVar1[10] == *(int *)(param_1 + 8)) {
            return;
          }
        }
        else if (*(long *)(param_1 + 8) == plVar1[10]) {
          return;
        }
      }
      plVar1 = (long *)*plVar1;
    } while (plVar1 != (long *)0x0);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET59b8376224 @ 00103da8 size=128
// signature: undefined DATARMNET59b8376224(void)
// callers: [DATARMNET16add73734]
//------------------------------------------------------------

undefined8 DATARMNET59b8376224(uint param_1)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = *(long **)(DATARMNET665d2f133f + (ulong)((param_1 & 0xffff) * 0x61c88647 >> 0x1c) * 8);
  do {
    plVar2 = plVar3;
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    plVar3 = (long *)*plVar2;
  } while ((uint)*(ushort *)(plVar2 + 4) != (param_1 & 0xffff));
  plVar1 = (long *)plVar2[1];
  if (plVar1 != (long *)0x0) {
    *plVar1 = (long)plVar3;
    if (plVar3 != (long *)0x0) {
      plVar3[1] = (long)plVar1;
    }
    plVar2[1] = 0;
  }
  kvfree_call_rcu(plVar2 + 2,0x10);
  DATARMNET5ca94dbc3c(0x11);
  return 0;
}



//------------------------------------------------------------
// DATARMNET0b12e969c5 @ 00103e2c size=244
// signature: undefined DATARMNET0b12e969c5(void)
// callers: [DATARMNETb318ed4796]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNET0b12e969c5(ushort param_1,long param_2)

{
  long *plVar1;
  undefined8 uVar2;
  long *plVar3;
  long lVar4;
  char *pcVar5;
  undefined8 *puVar6;
  
  __rcu_read_lock();
  plVar1 = (long *)(DATARMNET665d2f133f + (ulong)((uint)param_1 * 0x61c88647 >> 0x1c) * 8);
  plVar3 = plVar1;
  do {
    plVar3 = (long *)*plVar3;
    if (plVar3 == (long *)0x0) {
      __rcu_read_unlock();
      plVar3 = (long *)kmalloc_trace(_ipv6_stub,0xdc0,0x28);
      if (plVar3 != (long *)0x0) {
        lVar4 = *plVar1;
        *(ushort *)(plVar3 + 4) = param_1;
        *plVar3 = lVar4;
        plVar3[1] = (long)plVar1;
        *plVar1 = (long)plVar3;
        if (lVar4 != 0) {
          *(long **)(lVar4 + 8) = plVar3;
        }
        DATARMNET5ca94dbc3c(0x10);
        return 0;
      }
      puVar6 = *(undefined8 **)(param_2 + 0x40);
      pcVar5 = "Cannot allocate encap port memory";
      do_trace_netlink_extack("Cannot allocate encap port memory");
      uVar2 = 0xfffffff4;
      if (puVar6 == (undefined8 *)0x0) {
        return 0xfffffff4;
      }
      goto LAB_00103f08;
    }
  } while ((uint)*(ushort *)(plVar3 + 4) != (uint)param_1);
  __rcu_read_unlock();
  puVar6 = *(undefined8 **)(param_2 + 0x40);
  pcVar5 = "Encap port already present";
  do_trace_netlink_extack("Encap port already present");
  uVar2 = 0xffffffef;
  if (puVar6 != (undefined8 *)0x0) {
LAB_00103f08:
    *puVar6 = pcVar5;
  }
  return uVar2;
}



//------------------------------------------------------------
// DATARMNET37a92021f9 @ 00103f24 size=940
// signature: undefined DATARMNET37a92021f9(void)
// callers: [DATARMNETd2f80b03ce]
//------------------------------------------------------------

undefined4 DATARMNET37a92021f9(long *param_1)

{
  byte *pbVar1;
  ushort uVar2;
  int iVar3;
  long *plVar4;
  ulong uVar5;
  undefined8 uVar6;
  undefined4 *puVar7;
  long lVar8;
  byte bVar9;
  undefined4 uVar10;
  undefined8 *puVar11;
  long lVar12;
  byte local_74 [4];
  undefined8 local_70;
  ulong local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  long local_38;
  
  lVar12 = sp_el0;
  local_38 = *(long *)(lVar12 + 0x638);
  lVar12 = *param_1;
  local_40 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  if ((lVar12 == 0) || ((*(ushort *)(lVar12 + 0x80) & 7) == 5)) {
    uVar10 = 3;
    goto LAB_0010419c;
  }
  __rcu_read_lock();
  DATARMNET5ca94dbc3c(2);
  if (*(short *)(lVar12 + 0xb4) == -0x227a) {
    local_68 = local_68 & 0xffffffffffff0000;
    lVar8 = *(long *)(lVar12 + 0xd8) + (ulong)*(ushort *)(lVar12 + 0xb8);
    local_74[0] = *(byte *)(lVar8 + 6);
    iVar3 = ipv6_skip_exthdr(lVar12,0x28,local_74,&local_68);
    if (-1 < iVar3) {
      if (local_74[0] == 0x3a) {
        local_60 = *(undefined8 *)(lVar8 + 0x18);
        uStack_58 = *(undefined8 *)(lVar8 + 0x20);
        local_50 = *(undefined8 *)(lVar8 + 8);
        uStack_48 = *(undefined8 *)(lVar8 + 0x10);
        local_40 = CONCAT31(local_40._1_3_,6);
        plVar4 = (long *)DATARMNET07f0e0f286(&local_60);
        if (plVar4 != (long *)0x0) goto LAB_001040d0;
      }
      uVar6 = local_70;
      for (plVar4 = (long *)(&DATARMNET78ed39f13b)
                            [(uint)((int)*(long *)(lVar8 + 0x18) * 0x61c88647) >> 0x1c];
          plVar4 != (long *)0x0; plVar4 = (long *)*plVar4) {
        if ((*(char *)(plVar4 + 0xc) == '\x06') && (*(long *)(lVar8 + 0x18) == plVar4[10])) {
          plVar4 = plVar4 + 9;
          local_70._0_5_ = CONCAT14(6,(undefined4)local_70);
          local_70._6_2_ = SUB82(uVar6,6);
          local_70._0_6_ = CONCAT15(local_74[0],(undefined5)local_70);
          bVar9 = local_74[0];
          if ((short)local_68 == 0) goto LAB_001041cc;
          iVar3 = DATARMNETaca8ca54ed(lVar12,iVar3,&local_70,plVar4);
          goto LAB_0010417c;
        }
      }
    }
LAB_00104194:
    uVar10 = 3;
  }
  else {
    if (*(short *)(lVar12 + 0xb4) != 8) goto LAB_00104194;
    pbVar1 = (byte *)(*(long *)(lVar12 + 0xd8) + (ulong)*(ushort *)(lVar12 + 0xb8));
    if (pbVar1[9] == 1) {
      local_60 = CONCAT44(local_60._4_4_,*(undefined4 *)(pbVar1 + 0x10));
      local_40 = CONCAT31(local_40._1_3_,4);
      local_50 = CONCAT44(local_50._4_4_,*(undefined4 *)(pbVar1 + 0xc));
      plVar4 = (long *)DATARMNET07f0e0f286(&local_60);
      if (plVar4 == (long *)0x0) goto LAB_00103fdc;
LAB_001040d0:
      lVar8 = *plVar4;
      if (lVar8 == 0) {
        uVar6 = 4;
LAB_00104190:
        DATARMNET5ca94dbc3c(uVar6);
        goto LAB_00104194;
      }
      DATARMNET7ca470d54b(lVar12,0x1200);
      *(long *)(lVar12 + 0x10) = lVar8;
      __dev_queue_xmit(lVar12,0);
      uVar6 = 3;
LAB_001040f8:
      DATARMNET5ca94dbc3c(uVar6);
      uVar10 = 0;
    }
    else {
LAB_00103fdc:
      uVar6 = local_70;
      plVar4 = (long *)(&DATARMNET78ed39f13b)[(uint)(*(int *)(pbVar1 + 0x10) * 0x61c88647) >> 0x1c];
joined_r0x00103ffc:
      if (plVar4 == (long *)0x0) goto LAB_00104194;
      if ((*(char *)(plVar4 + 0xc) != '\x04') || (*(int *)(plVar4 + 10) != *(int *)(pbVar1 + 0x10)))
      goto LAB_00104004;
      plVar4 = plVar4 + 9;
      local_70._0_5_ = CONCAT14(4,(undefined4)local_70);
      local_70._6_2_ = SUB82(uVar6,6);
      local_70._0_6_ = CONCAT15(pbVar1[9],(undefined5)local_70);
      iVar3 = (*pbVar1 & 0xf) << 2;
      bVar9 = pbVar1[9];
      if ((*(ushort *)(pbVar1 + 6) & 0xff3f) != 0) {
        iVar3 = DATARMNET579f75aa50(lVar12,iVar3,&local_70,plVar4);
LAB_0010417c:
        uVar10 = 0;
        if (iVar3 != 0) {
          uVar10 = 3;
        }
        goto LAB_00104198;
      }
LAB_001041cc:
      if (bVar9 != 6) {
        if (bVar9 != 0x32) {
          if (bVar9 != 0x11) goto LAB_00104194;
          goto LAB_001041e4;
        }
        local_68 = 0;
        puVar7 = (undefined4 *)skb_header_pointer(lVar12,iVar3,8,&local_68);
        if (puVar7 != (undefined4 *)0x0) {
          local_70 = CONCAT44(local_70._4_4_,*puVar7);
          goto LAB_00104270;
        }
        uVar6 = 0x14;
        goto LAB_00104190;
      }
LAB_001041e4:
      uVar2 = *(ushort *)(*(long *)(lVar12 + 0xe0) + (long)iVar3 + 2);
      local_70 = CONCAT62(local_70._2_6_,uVar2);
      uVar5 = DATARMNETa8b2566e6a(lVar12,&local_70,iVar3);
      if ((uVar5 & 1) != 0) {
        puVar11 = (undefined8 *)
                  (DATARMNET665d2f133f + (ulong)((uint)uVar2 * 0x61c88647 >> 0x1c) * 8);
        do {
          puVar11 = (undefined8 *)*puVar11;
          if (puVar11 == (undefined8 *)0x0) {
            uVar6 = 10;
            goto LAB_00104190;
          }
        } while (*(ushort *)(puVar11 + 4) != uVar2);
        kfree_skb_reason(lVar12,1);
        uVar6 = 0x12;
        goto LAB_001040f8;
      }
LAB_00104270:
      uVar5 = DATARMNET4eafcdee07(&local_70);
      if ((uVar5 & 1) != 0) goto LAB_001040d0;
      if (*(int *)(lVar12 + 0xa8) != 0x20002) goto LAB_00104194;
      lVar8 = dev_get_by_name_rcu(&init_net,"dummy0");
      if (lVar8 == 0) {
        uVar6 = 0x16;
        goto LAB_00104190;
      }
      uVar10 = 3;
      *(long *)(lVar12 + 0x10) = lVar8;
      *(undefined4 *)(lVar12 + 0xa8) = 0;
    }
  }
LAB_00104198:
  __rcu_read_unlock();
LAB_0010419c:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
LAB_00104004:
  plVar4 = (long *)*plVar4;
  goto joined_r0x00103ffc;
}



//------------------------------------------------------------
// DATARMNETa8b2566e6a @ 001042d4 size=332
// signature: undefined DATARMNETa8b2566e6a(void)
// callers: [DATARMNET37a92021f9, DATARMNET9d6ad3b16f]
//------------------------------------------------------------

bool DATARMNETa8b2566e6a(long param_1,ushort *param_2,int param_3)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  undefined8 *puVar5;
  short *psVar6;
  int local_24;
  short local_20 [4];
  long local_18;
  
  lVar1 = sp_el0;
  bVar2 = false;
  local_18 = *(long *)(lVar1 + 0x638);
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_24 = 0;
  if (*(char *)((long)param_2 + 5) != '\x11') goto LAB_001043f4;
  puVar5 = &DATARMNET133502ca0e + ((uint)*param_2 * 0x61c88647 >> 0x1c);
  do {
    puVar5 = (undefined8 *)*puVar5;
    if (puVar5 == (undefined8 *)0x0) goto LAB_001043f0;
  } while ((uint)*(ushort *)(puVar5 + 4) != (uint)*param_2);
  if (*(int *)(param_1 + 0x70) - (*(int *)(param_1 + 0x74) + param_3) < 8) {
    if (param_1 != 0) {
      iVar3 = skb_copy_bits(param_1,param_3,local_20,8);
      psVar6 = local_20;
      if (-1 < iVar3) goto LAB_00104360;
    }
  }
  else {
    psVar6 = (short *)(*(long *)(param_1 + 0xe0) + (long)param_3);
    if (psVar6 != (short *)0x0) {
LAB_00104360:
      if (*psVar6 != -0xbff) {
        if ((*(int *)(param_1 + 0x70) - (*(int *)(param_1 + 0x74) + param_3)) + -8 < 4) {
          if (param_1 != 0) {
            iVar3 = skb_copy_bits(param_1,param_3 + 8,&local_24,4);
            piVar4 = &local_24;
            if (-1 < iVar3) goto LAB_00104394;
          }
        }
        else {
          piVar4 = (int *)(*(long *)(param_1 + 0xe0) + (long)(param_3 + 8));
          if (piVar4 != (int *)0x0) {
LAB_00104394:
            bVar2 = *piVar4 != 0;
            goto LAB_001043f4;
          }
        }
      }
    }
  }
LAB_001043f0:
  bVar2 = false;
LAB_001043f4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar2;
}



//------------------------------------------------------------
// DATARMNET0a4704e5e0 @ 00104424 size=64
// signature: undefined DATARMNET0a4704e5e0(void)
// callers: [DATARMNET9d6ad3b16f]
//------------------------------------------------------------

bool DATARMNET0a4704e5e0(ushort *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(DATARMNET665d2f133f + (ulong)((uint)*param_1 * 0x61c88647 >> 0x1c) * 8);
  do {
    puVar1 = (undefined8 *)*puVar1;
    if (puVar1 == (undefined8 *)0x0) break;
  } while ((uint)*(ushort *)(puVar1 + 4) != (uint)*param_1);
  return puVar1 != (undefined8 *)0x0;
}



//------------------------------------------------------------
// skb_header_pointer @ 00104464 size=92
// signature: undefined skb_header_pointer(void)
// callers: [DATARMNET37a92021f9, DATARMNET7ca470d54b]
//------------------------------------------------------------

long skb_header_pointer(long param_1,int param_2,int param_3,long param_4)

{
  int iVar1;
  long lVar2;
  
  if (*(int *)(param_1 + 0x70) - (*(int *)(param_1 + 0x74) + param_2) < param_3) {
    lVar2 = 0;
    if (param_1 != 0) {
      iVar1 = skb_copy_bits(param_1,param_2,param_4,param_3);
      lVar2 = 0;
      if (-1 < iVar1) {
        lVar2 = param_4;
      }
    }
  }
  else {
    lVar2 = *(long *)(param_1 + 0xe0) + (long)param_2;
  }
  return lVar2;
}



//------------------------------------------------------------
// DATARMNET4eafcdee07 @ 001044c4 size=132
// signature: undefined DATARMNET4eafcdee07(void)
// callers: [DATARMNET37a92021f9, DATARMNET9d6ad3b16f]
//------------------------------------------------------------

undefined8 DATARMNET4eafcdee07(ushort *param_1)

{
  long *plVar1;
  
  plVar1 = (long *)(&DATARMNET1903907456)[(uint)*param_1 * 0x61c88647 >> 0x1c];
  if (plVar1 != (long *)0x0) {
    do {
      if ((*(char *)((long)plVar1 + 0x24) == (char)param_1[2]) &&
         (*(char *)((long)plVar1 + 0x25) == *(char *)((long)param_1 + 5))) {
        if ((char)param_1[2] == '2') {
          if ((int)plVar1[4] == *(int *)param_1) {
            return 1;
          }
        }
        else if ((uint)*(ushort *)(plVar1 + 4) == (uint)*param_1) {
          return 1;
        }
      }
      plVar1 = (long *)*plVar1;
    } while (plVar1 != (long *)0x0);
  }
  return 0;
}



//------------------------------------------------------------
// DATARMNET4899053671 @ 0010454c size=96
// signature: undefined DATARMNET4899053671(void)
// callers: [DATARMNETad2b7fd8f5, DATARMNET9d6ad3b16f, DATARMNETc7c83f614f]
//------------------------------------------------------------

undefined8 DATARMNET4899053671(long param_1,long *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *param_2;
  if (lVar3 == 0) {
    uVar2 = 0xffffffed;
    uVar1 = 4;
  }
  else {
    DATARMNET7ca470d54b(param_1,0x1200);
    *(long *)(param_1 + 0x10) = lVar3;
    __dev_queue_xmit(param_1,0);
    uVar2 = 0;
    uVar1 = 3;
  }
  DATARMNET5ca94dbc3c(uVar1);
  return uVar2;
}



//------------------------------------------------------------
// DATARMNET7ca470d54b @ 001045b0 size=1268
// signature: undefined DATARMNET7ca470d54b(void)
// callers: [DATARMNET37a92021f9, DATARMNET4899053671, DATARMNETd2f80b03ce]
//------------------------------------------------------------

void DATARMNET7ca470d54b(long param_1,uint param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  undefined4 uVar5;
  short sVar6;
  uint uVar7;
  int iVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  undefined4 *puVar11;
  long lVar12;
  uint uVar13;
  char *pcVar14;
  undefined2 uVar15;
  uint uVar16;
  byte *pbVar17;
  char local_b8 [4];
  undefined2 local_b4 [2];
  byte local_b0 [16];
  ulong local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  long local_48;
  
  lVar12 = sp_el0;
  local_48 = *(long *)(lVar12 + 0x638);
  sVar6 = *(short *)(param_1 + 0xb4);
  local_50 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_88 = 0;
  if (sVar6 == 8) {
    local_a0 = local_a0 & 0xffffffff00000000;
    local_b0[0] = 0;
    local_b0[1] = 0;
    local_b0[2] = 0;
    local_b0[3] = 0;
    local_b0[4] = 0;
    local_b0[5] = 0;
    local_b0[6] = 0;
    local_b0[7] = 0;
    local_b0[8] = 0;
    local_b0[9] = 0;
    local_b0[10] = 0;
    local_b0[0xb] = 0;
    local_b0[0xc] = 0;
    local_b0[0xd] = 0;
    local_b0[0xe] = 0;
    local_b0[0xf] = 0;
    if (*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x74) < 0x14) {
      if (param_1 != 0) {
        pbVar17 = local_b0;
        iVar8 = skb_copy_bits(param_1,0,local_b0,0x14);
        if (-1 < iVar8) goto LAB_00104620;
      }
    }
    else {
      pbVar17 = *(byte **)(param_1 + 0xe0);
      if (pbVar17 != (byte *)0x0) {
LAB_00104620:
        if (pbVar17[9] != 6) goto LAB_00104800;
        uVar7 = (*pbVar17 & 0xf) << 2;
LAB_0010469c:
        uVar7 = uVar7 & 0xffff;
        if ((int)((*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x74)) - uVar7) < 0x14) {
          if (param_1 != 0) {
            puVar10 = &local_88;
            iVar8 = skb_copy_bits(param_1,uVar7,&local_88,0x14);
            if (-1 < iVar8) goto LAB_001046c0;
          }
        }
        else {
          puVar10 = (undefined8 *)(*(long *)(param_1 + 0xe0) + (ulong)uVar7);
          if (puVar10 != (undefined8 *)0x0) {
LAB_001046c0:
            if ((*(uint *)((long)puVar10 + 0xc) & param_2) == 0) goto LAB_00104800;
            uVar3 = *(uint *)((long)puVar10 + 0xc) >> 2 & 0x3c;
            uVar2 = uVar7 + uVar3;
            uVar13 = *(uint *)(param_1 + 0x70) - *(int *)(param_1 + 0x74);
            iVar8 = uVar2 - uVar13;
            if ((uVar2 < uVar13 || iVar8 == 0) ||
               ((uVar2 <= *(uint *)(param_1 + 0x70) &&
                (lVar12 = __pskb_pull_tail(param_1,iVar8), lVar12 != 0)))) {
              if ((*(byte *)(param_1 + 0x7e) & 1) != 0) {
                lVar12 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
                if (((*(uint *)(lVar12 + 0x20) & 0xffff) != 1) &&
                   (((uVar13 = *(uint *)(lVar12 + 0x20),
                     (uVar13 & 0xffff) - ((int)uVar13 >> 0x10) != 1 ||
                     ((uint)*(ushort *)(param_1 + 0x7a) <
                      uVar2 + (*(int *)(param_1 + 0xe0) - (int)*(long *)(param_1 + 0xd8)))) &&
                    (iVar8 = pskb_expand_head(param_1,0,0,0xa20), iVar8 != 0)))) goto LAB_00104834;
              }
              if ((int)((*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x74)) - uVar7) < (int)uVar3)
              {
                if (param_1 != 0) {
                  puVar10 = &local_88;
                  iVar8 = skb_copy_bits(param_1,uVar7,&local_88,uVar3);
                  if (-1 < iVar8) goto LAB_00104770;
                }
              }
              else {
                puVar10 = (undefined8 *)(*(long *)(param_1 + 0xe0) + (ulong)uVar7);
                if (puVar10 != (undefined8 *)0x0) {
LAB_00104770:
                  if (0x14 < uVar3) {
                    uVar13 = 0x14;
                    do {
                      if (*(byte *)((long)puVar10 + (ulong)uVar13) == 2) {
                        if (*(char *)((long)puVar10 + (ulong)uVar13 + 1) == '\x04') {
                          uVar7 = (uint)*(ushort *)((long)puVar10 + (ulong)(uVar13 + 2));
                          if (uVar7 < 0x7405) goto LAB_00104800;
                          if (((*(ushort *)(param_1 + 0x80) ^ 0xffff) & 0x60) != 0) {
                            uVar7 = (~(uint)*(ushort *)(puVar10 + 2) - uVar7) + 0x7404;
                            *(ushort *)(puVar10 + 2) =
                                 (ushort)((uVar7 >> 0x10 | uVar7 * 0x10000) + uVar7 >> 0x10) ^
                                 0xffff;
                          }
                          uVar9 = 0xb;
                          *(undefined2 *)((long)puVar10 + (ulong)(uVar13 + 2)) = 0x7404;
                          goto LAB_00104838;
                        }
LAB_0010478c:
                        uVar16 = (uint)*(byte *)((long)puVar10 + (ulong)uVar13 + 1);
                        if (uVar16 == 0) {
                          uVar16 = 1;
                        }
                      }
                      else {
                        if (1 < *(byte *)((long)puVar10 + (ulong)uVar13)) goto LAB_0010478c;
                        uVar16 = 1;
                      }
                      uVar13 = uVar16 + uVar13;
                    } while (uVar13 < uVar3);
                  }
                  uVar13 = *(uint *)(param_1 + 0x70);
                  uVar9 = 0xc;
                  if ((uVar2 < uVar13) || (uVar3 == 0x3c)) goto LAB_00104838;
                  if (*(int *)(param_1 + 0x74) == 0) {
                    if (*(int *)(param_1 + 0xd4) - *(int *)(param_1 + 0xd0) < 4) {
                      iVar8 = (*(int *)(param_1 + 0xd0) - *(int *)(param_1 + 0xd4)) + 4;
                      goto LAB_00104820;
                    }
                  }
                  else {
                    iVar8 = 4;
LAB_00104820:
                    iVar8 = pskb_expand_head(param_1,0,iVar8,0xa20);
                    if ((iVar8 != 0) ||
                       (puVar10 = (undefined8 *)skb_header_pointer(param_1,uVar7,uVar3,&local_88),
                       puVar10 == (undefined8 *)0x0)) goto LAB_00104834;
                    uVar13 = *(uint *)(param_1 + 0x70);
                  }
                  uVar13 = uVar13 - uVar7;
                  puVar1 = puVar10 + 2;
                  DATARMNETc03853e26d(puVar1,param_1,
                                      ((uVar13 & 0xff00ff00) >> 8 | (uVar13 & 0xff00ff) << 8) &
                                      0xffff,((uVar13 + 4 & 0xff00ff00) >> 8 |
                                             (uVar13 + 4 & 0xff00ff) << 8) & 0xffff,1);
                  puVar11 = (undefined4 *)skb_put(param_1,4);
                  uVar15 = 0x1802;
                  if (sVar6 != 8) {
                    uVar15 = 0x7404;
                  }
                  *(undefined2 *)puVar11 = 0x402;
                  *(undefined2 *)((long)puVar11 + 2) = uVar15;
                  DATARMNET9a8d756527(puVar1,param_1,0,*puVar11,0);
                  uVar5 = *(undefined4 *)((long)puVar10 + 0xc);
                  uVar4 = (ushort)uVar5;
                  *(ushort *)((long)puVar10 + 0xc) = uVar4 + 0x10 & 0xf0 | uVar4 & 0xff0f;
                  DATARMNET9a8d756527(puVar1,param_1,uVar5,*(undefined4 *)((long)puVar10 + 0xc),0);
                  lVar12 = *(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8);
                  if (sVar6 == 8) {
                    uVar9 = 0xb;
                    uVar2 = (uint)(*(ushort *)(param_1 + 0x70) >> 8) |
                            (*(ushort *)(param_1 + 0x70) & 0xff00ff) << 8;
                    uVar7 = (*(ushort *)(lVar12 + 10) ^ 0xffff) + (*(ushort *)(lVar12 + 2) ^ 0xffff)
                    ;
                    uVar7 = uVar7 + uVar2 + (uVar7 >> 0x10);
                    uVar4 = (ushort)uVar7;
                    if ((uVar7 & 0xffff) < uVar2) {
                      uVar4 = uVar4 + 1;
                    }
                    *(ushort *)(lVar12 + 10) = ~uVar4;
                    *(ushort *)(lVar12 + 2) =
                         *(ushort *)(param_1 + 0x70) >> 8 | *(ushort *)(param_1 + 0x70) << 8;
                  }
                  else {
                    uVar9 = 0xb;
                    uVar7 = ((uint)(*(ushort *)(lVar12 + 4) >> 8) |
                            (*(ushort *)(lVar12 + 4) & 0xff00ff) << 8) + 4;
                    *(ushort *)(lVar12 + 4) =
                         (ushort)(uVar7 >> 8) & 0xff | (ushort)((uVar7 & 0xff00ff) << 8);
                  }
                  goto LAB_00104838;
                }
              }
            }
          }
        }
      }
    }
  }
  else if (sVar6 == -0x227a) {
    local_98 = 0;
    uStack_90 = 0;
    local_b0[8] = 0;
    local_b0[9] = 0;
    local_b0[10] = 0;
    local_b0[0xb] = 0;
    local_b0[0xc] = 0;
    local_b0[0xd] = 0;
    local_b0[0xe] = 0;
    local_b0[0xf] = 0;
    local_a0 = 0;
    local_b0[0] = 0;
    local_b0[1] = 0;
    local_b0[2] = 0;
    local_b0[3] = 0;
    local_b0[4] = 0;
    local_b0[5] = 0;
    local_b0[6] = 0;
    local_b0[7] = 0;
    local_b4[0] = 0;
    local_b8[0] = '\0';
    if (*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x74) < 0x28) {
      if ((param_1 != 0) && (iVar8 = skb_copy_bits(param_1,0,local_b0,0x28), -1 < iVar8)) {
        pcVar14 = (char *)((ulong)local_b0 | 6);
        goto LAB_00104674;
      }
    }
    else if (*(long *)(param_1 + 0xe0) != 0) {
      pcVar14 = (char *)(*(long *)(param_1 + 0xe0) + 6);
LAB_00104674:
      local_b8[0] = *pcVar14;
      uVar7 = ipv6_skip_exthdr(param_1,0x28,local_b8,local_b4);
      if (local_b8[0] == '\x06') goto LAB_0010469c;
LAB_00104800:
      uVar9 = 0xc;
      goto LAB_00104838;
    }
  }
LAB_00104834:
  uVar9 = 0xd;
LAB_00104838:
  DATARMNET5ca94dbc3c(uVar9);
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNETc03853e26d @ 00104aa4 size=200
// signature: undefined DATARMNETc03853e26d(void)
// callers: [DATARMNET7ca470d54b]
//------------------------------------------------------------

void DATARMNETc03853e26d(ushort *param_1,long param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  ushort uVar2;
  
  param_3 = param_3 & 0xffff;
  param_4 = param_4 & 0xffff;
  if (((*(ushort *)(param_2 + 0x80) ^ 0xffff) & 0x60) == 0) {
    if ((param_5 & 1) != 0) {
      uVar2 = *param_1;
      param_3 = ~param_3;
      uVar1 = uVar2 + param_3 + param_4 +
              (uint)(param_4 + uVar2 + param_3 + (uint)CARRY4((uint)uVar2,param_3) < param_4) +
              (uint)CARRY4((uint)uVar2,param_3);
      *param_1 = (ushort)((uVar1 >> 0x10 | uVar1 * 0x10000) + uVar1 >> 0x10);
    }
  }
  else {
    uVar1 = (param_4 - param_3) + ~(uint)*param_1;
    if (uVar1 < param_4) {
      uVar1 = uVar1 + 1;
    }
    *param_1 = (ushort)((uVar1 >> 0x10 | uVar1 << 0x10) + uVar1 >> 0x10) ^ 0xffff;
    if (((*(ushort *)(param_2 + 0x80) & 0x60) == 0x40) && ((param_5 & 1) != 0)) {
      param_3 = ~param_3;
      uVar1 = ~*(uint *)(param_2 + 0x88);
      *(uint *)(param_2 + 0x88) =
           ~(uVar1 + param_3 + param_4 +
             (uint)(param_4 + uVar1 + param_3 + (uint)CARRY4(uVar1,param_3) < param_4) +
            (uint)CARRY4(uVar1,param_3));
      return;
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNET9a8d756527 @ 00104b6c size=204
// signature: undefined DATARMNET9a8d756527(void)
// callers: [DATARMNET7ca470d54b]
//------------------------------------------------------------

void DATARMNET9a8d756527(ushort *param_1,long param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  ushort uVar2;
  
  if (((*(ushort *)(param_2 + 0x80) ^ 0xffff) & 0x60) == 0) {
    if ((param_5 & 1) != 0) {
      uVar2 = *param_1;
      param_3 = ~param_3;
      uVar1 = uVar2 + param_3 + param_4 +
              (uint)(param_4 + uVar2 + param_3 + (uint)CARRY4((uint)uVar2,param_3) < param_4) +
              (uint)CARRY4((uint)uVar2,param_3);
      *param_1 = (ushort)((uVar1 >> 0x10 | uVar1 * 0x10000) + uVar1 >> 0x10);
    }
  }
  else {
    uVar1 = ~(uint)*param_1;
    param_3 = ~param_3;
    uVar1 = uVar1 + param_3 + param_4 +
            (uint)(param_4 + uVar1 + param_3 + (uint)CARRY4(uVar1,param_3) < param_4) +
            (uint)CARRY4(uVar1,param_3);
    *param_1 = (ushort)((uVar1 >> 0x10 | uVar1 * 0x10000) + uVar1 >> 0x10) ^ 0xffff;
    if (((*(ushort *)(param_2 + 0x80) & 0x60) == 0x40) && ((param_5 & 1) != 0)) {
      uVar1 = ~*(uint *)(param_2 + 0x88);
      *(uint *)(param_2 + 0x88) =
           ~(uVar1 + param_3 + param_4 +
             (uint)(param_4 + uVar1 + param_3 + (uint)CARRY4(uVar1,param_3) < param_4) +
            (uint)CARRY4(uVar1,param_3));
      return;
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNET53f12a0f7d @ 00104c3c size=440
// signature: undefined DATARMNET53f12a0f7d(void)
// callers: [DATARMNET72501635c8]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNET53f12a0f7d(long param_1,uint param_2,long param_3)

{
  long *plVar1;
  ushort *puVar2;
  long *plVar3;
  long lVar4;
  undefined8 uVar5;
  ulong uVar6;
  undefined8 *puVar7;
  
  mutex_lock(&DATARMNET63a2b7773e);
  if (param_2 != 0) {
    uVar6 = 0;
    do {
      puVar2 = (ushort *)(param_1 + uVar6 * 8);
      __rcu_read_lock();
      plVar3 = (long *)(&DATARMNET1903907456)[(uint)*puVar2 * 0x61c88647 >> 0x1c];
      if (plVar3 != (long *)0x0) {
        do {
          if ((*(char *)((long)plVar3 + 0x24) == (char)puVar2[2]) &&
             (*(char *)((long)plVar3 + 0x25) == *(char *)((long)puVar2 + 5))) {
            if ((char)puVar2[2] == '2') {
              if ((int)plVar3[4] != *(int *)puVar2) goto LAB_00104cf8;
            }
            else if ((uint)*(ushort *)(plVar3 + 4) != (uint)*puVar2) goto LAB_00104cf8;
            __rcu_read_unlock();
            puVar7 = *(undefined8 **)(param_3 + 0x40);
            do_trace_netlink_extack("Tuple already present");
            if (puVar7 != (undefined8 *)0x0) {
              *puVar7 = "Tuple already present";
            }
            goto LAB_00104cb8;
          }
LAB_00104cf8:
          plVar3 = (long *)*plVar3;
        } while (plVar3 != (long *)0x0);
      }
      __rcu_read_unlock();
      plVar3 = (long *)kmalloc_trace(_ipv6_stub,0xdc0,0x28);
      if (plVar3 == (long *)0x0) {
        puVar7 = *(undefined8 **)(param_3 + 0x40);
        do_trace_netlink_extack("Cannot allocate tuple memory");
        uVar5 = 0xfffffff4;
        if (puVar7 != (undefined8 *)0x0) {
          *puVar7 = "Cannot allocate tuple memory";
        }
        goto LAB_00104da0;
      }
      lVar4 = *(long *)puVar2;
      plVar3[4] = lVar4;
      plVar1 = &DATARMNET1903907456 + (((uint)lVar4 & 0xffff) * 0x61c88647 >> 0x1c);
      lVar4 = *plVar1;
      *plVar3 = lVar4;
      plVar3[1] = (long)plVar1;
      *plVar1 = (long)plVar3;
      if (lVar4 != 0) {
        *(long **)(lVar4 + 8) = plVar3;
      }
      DATARMNET5ca94dbc3c(0);
      DATARMNET7c77d83017 = DATARMNET7c77d83017 + 1;
LAB_00104cb8:
      uVar6 = uVar6 + 1;
    } while (uVar6 != param_2);
  }
  uVar5 = 0;
LAB_00104da0:
  mutex_unlock(&DATARMNET63a2b7773e);
  return uVar5;
}



//------------------------------------------------------------
// DATARMNET07f6485c9b @ 00104df8 size=356
// signature: undefined DATARMNET07f6485c9b(void)
// callers: [DATARMNET41dd9b14ab]
//------------------------------------------------------------

undefined8 DATARMNET07f6485c9b(long param_1,uint param_2,long param_3)

{
  ushort *puVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  ulong uVar5;
  undefined8 *puVar6;
  
  mutex_lock(&DATARMNET63a2b7773e);
  if (param_2 != 0) {
    uVar5 = 0;
    do {
      puVar1 = (ushort *)(param_1 + uVar5 * 8);
      if ((long *)(&DATARMNET1903907456)[(uint)*puVar1 * 0x61c88647 >> 0x1c] != (long *)0x0) {
        plVar2 = (long *)(&DATARMNET1903907456)[(uint)*puVar1 * 0x61c88647 >> 0x1c];
        do {
          plVar3 = (long *)*plVar2;
          if ((*(char *)((long)plVar2 + 0x24) == (char)puVar1[2]) &&
             (*(char *)((long)plVar2 + 0x25) == *(char *)((long)puVar1 + 5))) {
            if ((char)puVar1[2] == '2') {
              if ((int)plVar2[4] != *(int *)puVar1) goto LAB_00104ec0;
            }
            else if ((uint)*(ushort *)(plVar2 + 4) != (uint)*puVar1) goto LAB_00104ec0;
            plVar4 = (long *)plVar2[1];
            if (plVar4 != (long *)0x0) {
              *plVar4 = (long)plVar3;
              if (plVar3 != (long *)0x0) {
                plVar3[1] = (long)plVar4;
              }
              plVar2[1] = 0;
            }
            kvfree_call_rcu(plVar2 + 2,0x10);
            DATARMNET5ca94dbc3c(1);
            DATARMNET7c77d83017 = DATARMNET7c77d83017 + -1;
            goto LAB_00104e80;
          }
LAB_00104ec0:
          plVar2 = plVar3;
        } while (plVar3 != (long *)0x0);
      }
      puVar6 = *(undefined8 **)(param_3 + 0x40);
      do_trace_netlink_extack("No such tuple");
      if (puVar6 != (undefined8 *)0x0) {
        *puVar6 = "No such tuple";
      }
LAB_00104e80:
      uVar5 = uVar5 + 1;
    } while (uVar5 != param_2);
  }
  mutex_unlock(&DATARMNET63a2b7773e);
  return 0;
}



//------------------------------------------------------------
// DATARMNET97b2388e63 @ 00104f60 size=632
// signature: undefined DATARMNET97b2388e63(void)
// callers: [DATARMNETf1fa473089]
//------------------------------------------------------------

int DATARMNET97b2388e63(char *param_1,long param_2)

{
  int iVar1;
  size_t __n;
  char *pcVar2;
  undefined8 *puVar3;
  
  if ((DATARMNET30500ba48c == *param_1) &&
     ((DAT_001069a5 == '\0' ||
      ((DAT_001069a5 == param_1[1] &&
       ((DAT_001069a6 == '\0' ||
        ((DAT_001069a6 == param_1[2] &&
         ((DAT_001069a7 == '\0' ||
          ((DAT_001069a7 == param_1[3] &&
           ((DAT_001069a8 == '\0' ||
            ((DAT_001069a8 == param_1[4] &&
             ((DAT_001069a9 == '\0' ||
              ((DAT_001069a9 == param_1[5] &&
               ((DAT_001069aa == '\0' ||
                ((DAT_001069aa == param_1[6] &&
                 ((DAT_001069ab == '\0' ||
                  ((DAT_001069ab == param_1[7] &&
                   ((DAT_001069ac == '\0' ||
                    ((DAT_001069ac == param_1[8] &&
                     ((DAT_001069ad == '\0' ||
                      ((DAT_001069ad == param_1[9] &&
                       ((DAT_001069ae == '\0' ||
                        ((DAT_001069ae == param_1[10] &&
                         ((DAT_001069af == '\0' ||
                          ((DAT_001069af == param_1[0xb] &&
                           ((DAT_001069b0 == '\0' ||
                            ((DAT_001069b0 == param_1[0xc] &&
                             ((DAT_001069b1 == '\0' ||
                              ((DAT_001069b1 == param_1[0xd] &&
                               ((DAT_001069b2 == '\0' ||
                                ((DAT_001069b2 == param_1[0xe] &&
                                 ((DAT_001069b3 == '\0' || (DAT_001069b3 == param_1[0xf]))))))))))))
                            )))))))))))))))))))))))))))))))))))))))))))))))) {
    puVar3 = *(undefined8 **)(param_2 + 0x40);
    pcVar2 = "Device is already set";
    do_trace_netlink_extack("Device is already set");
    iVar1 = 0;
joined_r0x00105148:
    if (puVar3 != (undefined8 *)0x0) {
      *puVar3 = pcVar2;
    }
  }
  else {
    if (DATARMNET30500ba48c != '\0') {
      iVar1 = unregister_netdevice_notifier(&DATARMNETa1726000d8);
      if (iVar1 != 0) {
        puVar3 = *(undefined8 **)(param_2 + 0x40);
        pcVar2 = "Kernel error, notifier unregister failed";
        do_trace_netlink_extack("Kernel error, notifier unregister failed");
        goto joined_r0x00105148;
      }
      DATARMNET30500ba48c = '\0';
    }
    __n = strlen(param_1);
    if (0xe < __n) {
      __n = 0xf;
    }
    memcpy(&DATARMNET30500ba48c,param_1,__n);
    (&DATARMNET30500ba48c)[__n] = 0;
    iVar1 = register_netdevice_notifier(&DATARMNETa1726000d8);
    if (iVar1 != 0) {
      puVar3 = *(undefined8 **)(param_2 + 0x40);
      do_trace_netlink_extack("Kernel error, notifier failed");
      if (puVar3 != (undefined8 *)0x0) {
        *puVar3 = "Kernel error, notifier failed";
      }
      DATARMNET30500ba48c = '\0';
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// DATARMNETaba2beb199 @ 001051dc size=48
// signature: undefined DATARMNETaba2beb199(void)
// callers: [DATARMNETd2f80b03ce]
//------------------------------------------------------------

int DATARMNETaba2beb199(byte *param_1,byte *param_2,long param_3)

{
  byte *pbVar1;
  
  while( true ) {
    pbVar1 = param_1 + 1;
    if (param_3 == 0) {
      return 0;
    }
    if ((uint)*param_1 - (uint)*param_2 != 0) break;
    param_2 = param_2 + 1;
    param_3 = param_3 + -1;
    param_1 = pbVar1;
    if (*pbVar1 == 0) {
      return 0;
    }
  }
  return (uint)*param_1 - (uint)*param_2;
}



//------------------------------------------------------------
// DATARMNET92e5468fc5 @ 00105210 size=512
// signature: undefined DATARMNET92e5468fc5(void)
// callers: [DATARMNETf1fa473089]
//------------------------------------------------------------

undefined8 DATARMNET92e5468fc5(char *param_1,long param_2)

{
  size_t __n;
  undefined8 *puVar1;
  
  if ((DATARMNET755f0f0df8 == *param_1) &&
     ((DAT_001069b5 == '\0' ||
      ((DAT_001069b5 == param_1[1] &&
       ((DAT_001069b6 == '\0' ||
        ((DAT_001069b6 == param_1[2] &&
         ((DAT_001069b7 == '\0' ||
          ((DAT_001069b7 == param_1[3] &&
           ((DAT_001069b8 == '\0' ||
            ((DAT_001069b8 == param_1[4] &&
             ((DAT_001069b9 == '\0' ||
              ((DAT_001069b9 == param_1[5] &&
               ((DAT_001069ba == '\0' ||
                ((DAT_001069ba == param_1[6] &&
                 ((DAT_001069bb == '\0' ||
                  ((DAT_001069bb == param_1[7] &&
                   ((DAT_001069bc == '\0' ||
                    ((DAT_001069bc == param_1[8] &&
                     ((DAT_001069bd == '\0' ||
                      ((DAT_001069bd == param_1[9] &&
                       ((DAT_001069be == '\0' ||
                        ((DAT_001069be == param_1[10] &&
                         ((DAT_001069bf == '\0' ||
                          ((DAT_001069bf == param_1[0xb] &&
                           ((DAT_001069c0 == '\0' ||
                            ((DAT_001069c0 == param_1[0xc] &&
                             ((DAT_001069c1 == '\0' ||
                              ((DAT_001069c1 == param_1[0xd] &&
                               ((DAT_001069c2 == '\0' ||
                                ((DAT_001069c2 == param_1[0xe] &&
                                 ((DAT_001069c3 == '\0' || (DAT_001069c3 == param_1[0xf]))))))))))))
                            )))))))))))))))))))))))))))))))))))))))))))))))) {
    puVar1 = *(undefined8 **)(param_2 + 0x40);
    do_trace_netlink_extack("Device is already set");
    if (puVar1 == (undefined8 *)0x0) {
      return 0;
    }
    *puVar1 = "Device is already set";
    return 0;
  }
  DATARMNET755f0f0df8 = 0;
  __n = strlen(param_1);
  if (0xe < __n) {
    __n = 0xf;
  }
  memcpy(&DATARMNET755f0f0df8,param_1,__n);
  (&DATARMNET755f0f0df8)[__n] = 0;
  return 0;
}



//------------------------------------------------------------
// DATARMNETa903cd5994 @ 00105414 size=72
// signature: undefined DATARMNETa903cd5994(void)
// callers: [DATARMNETcd9478470c]
//------------------------------------------------------------

undefined8 DATARMNETa903cd5994(void)

{
  undefined8 uVar1;
  
  if (DATARMNET30500ba48c == '\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = unregister_netdevice_notifier(&DATARMNETa1726000d8);
    if ((int)uVar1 == 0) {
      DATARMNET30500ba48c = '\0';
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// DATARMNET9d7bb9a63d @ 00105460 size=16
// signature: undefined DATARMNET9d7bb9a63d(void)
// callers: [DATARMNETcd9478470c]
//------------------------------------------------------------

undefined8 DATARMNET9d7bb9a63d(void)

{
  DATARMNET755f0f0df8 = 0;
  return 0;
}



//------------------------------------------------------------
// DATARMNET947eb110d2 @ 00105474 size=528
// signature: undefined DATARMNET947eb110d2(void)
// callers: [DATARMNETb86993aefb]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DATARMNET947eb110d2(undefined8 *param_1,long param_2)

{
  long *plVar1;
  char *__string;
  long lVar2;
  code *pcVar3;
  int iVar4;
  size_t __n;
  long lVar5;
  long *plVar6;
  undefined8 *puVar7;
  
  mutex_lock(DATARMNETf46fb02ac6);
  __rcu_read_lock();
  plVar6 = (long *)(&DATARMNET78ed39f13b)[(uint)(*(int *)(param_1 + 1) * 0x61c88647) >> 0x1c];
  if (plVar6 != (long *)0x0) {
    do {
      if ((char)plVar6[0xc] == *(char *)(param_1 + 3)) {
        if (*(char *)(param_1 + 3) == '\x04') {
          if ((int)plVar6[10] != *(int *)(param_1 + 1)) goto LAB_001054e4;
        }
        else if (param_1[1] != plVar6[10]) goto LAB_001054e4;
        puVar7 = *(undefined8 **)(param_2 + 0x40);
        do_trace_netlink_extack("FWD information already present");
        if (puVar7 != (undefined8 *)0x0) {
          *puVar7 = "FWD information already present";
        }
        __rcu_read_unlock();
        iVar4 = -0x11;
        goto LAB_0010563c;
      }
LAB_001054e4:
      plVar6 = (long *)*plVar6;
    } while (plVar6 != (long *)0x0);
  }
  __rcu_read_unlock();
  plVar6 = (long *)kmalloc_trace(_dst_release,0xdc0,0x68);
  if (plVar6 == (long *)0x0) {
    puVar7 = *(undefined8 **)(param_2 + 0x40);
    do_trace_netlink_extack("Cannot allocate FWD context");
    iVar4 = -0xc;
    if (puVar7 != (undefined8 *)0x0) {
      *puVar7 = "Cannot allocate FWD context";
    }
LAB_0010563c:
    mutex_unlock(DATARMNETf46fb02ac6);
    return iVar4;
  }
  lVar5 = param_1[3];
  __string = (char *)*param_1;
  lVar2 = param_1[1];
  plVar6[0xb] = param_1[2];
  plVar6[0xc] = lVar5;
  plVar6[9] = 0;
  plVar6[10] = lVar2;
  __n = strnlen(__string,0x10);
  if (__n < 0x11) {
    if (__n != 0x10) {
      memcpy(plVar6 + 7,__string,__n);
      if (0xffffffffffffff96 < __n - 0x31) {
        *(undefined1 *)((long)(plVar6 + 7) + __n) = 0;
        plVar6[4] = (long)DATARMNETe98553a8fc;
        iVar4 = register_netdevice_notifier();
        if (iVar4 == 0) {
          iVar4 = 0;
          plVar1 = &DATARMNET78ed39f13b + ((uint)(*(int *)(param_1 + 1) * 0x61c88647) >> 0x1c);
          lVar5 = *plVar1;
          *plVar6 = lVar5;
          plVar6[1] = (long)plVar1;
          *plVar1 = (long)plVar6;
          if (lVar5 != 0) {
            *(long **)(lVar5 + 8) = plVar6;
          }
        }
        else {
          puVar7 = *(undefined8 **)(param_2 + 0x40);
          do_trace_netlink_extack("Registering FWD notifier failed");
          if (puVar7 != (undefined8 *)0x0) {
            *puVar7 = "Registering FWD notifier failed";
          }
          kfree(plVar6);
        }
        goto LAB_0010563c;
      }
      goto LAB_00105680;
    }
  }
  else {
    fortify_panic("strnlen");
  }
  fortify_panic("__fortify_strlen");
LAB_00105680:
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(1,0x105684);
  (*pcVar3)();
}



//------------------------------------------------------------
// DATARMNETb8b35fdc18 @ 00105688 size=672
// signature: undefined DATARMNETb8b35fdc18(void)
// callers: [DATARMNETc175a08219]
//------------------------------------------------------------

int DATARMNETb8b35fdc18(undefined8 *param_1,long param_2)

{
  int iVar1;
  char *pcVar2;
  long *plVar3;
  long lVar4;
  long *plVar5;
  undefined8 *puVar6;
  
  mutex_lock(DATARMNETf46fb02ac6);
  __rcu_read_lock();
  plVar5 = (long *)(&DATARMNET78ed39f13b)[(uint)(*(int *)(param_1 + 1) * 0x61c88647) >> 0x1c];
  if (plVar5 != (long *)0x0) {
    do {
      if ((char)plVar5[0xc] == *(char *)(param_1 + 3)) {
        if (*(char *)(param_1 + 3) == '\x04') {
          if ((int)plVar5[10] == *(int *)(param_1 + 1)) {
LAB_00105718:
            __rcu_read_unlock();
            pcVar2 = (char *)*param_1;
            if (((char)plVar5[7] != *pcVar2) ||
               ((*(char *)((long)plVar5 + 0x39) != '\0' &&
                ((*(char *)((long)plVar5 + 0x39) != pcVar2[1] ||
                 ((*(char *)((long)plVar5 + 0x3a) != '\0' &&
                  ((*(char *)((long)plVar5 + 0x3a) != pcVar2[2] ||
                   ((*(char *)((long)plVar5 + 0x3b) != '\0' &&
                    ((*(char *)((long)plVar5 + 0x3b) != pcVar2[3] ||
                     ((*(char *)((long)plVar5 + 0x3c) != '\0' &&
                      ((*(char *)((long)plVar5 + 0x3c) != pcVar2[4] ||
                       ((*(char *)((long)plVar5 + 0x3d) != '\0' &&
                        ((*(char *)((long)plVar5 + 0x3d) != pcVar2[5] ||
                         ((*(char *)((long)plVar5 + 0x3e) != '\0' &&
                          ((*(char *)((long)plVar5 + 0x3e) != pcVar2[6] ||
                           ((*(char *)((long)plVar5 + 0x3f) != '\0' &&
                            ((*(char *)((long)plVar5 + 0x3f) != pcVar2[7] ||
                             (((char)plVar5[8] != '\0' &&
                              (((char)plVar5[8] != pcVar2[8] ||
                               ((*(char *)((long)plVar5 + 0x41) != '\0' &&
                                ((*(char *)((long)plVar5 + 0x41) != pcVar2[9] ||
                                 ((*(char *)((long)plVar5 + 0x42) != '\0' &&
                                  ((*(char *)((long)plVar5 + 0x42) != pcVar2[10] ||
                                   ((*(char *)((long)plVar5 + 0x43) != '\0' &&
                                    ((*(char *)((long)plVar5 + 0x43) != pcVar2[0xb] ||
                                     ((*(char *)((long)plVar5 + 0x44) != '\0' &&
                                      ((*(char *)((long)plVar5 + 0x44) != pcVar2[0xc] ||
                                       ((*(char *)((long)plVar5 + 0x45) != '\0' &&
                                        ((*(char *)((long)plVar5 + 0x45) != pcVar2[0xd] ||
                                         ((*(char *)((long)plVar5 + 0x46) != '\0' &&
                                          ((*(char *)((long)plVar5 + 0x46) != pcVar2[0xe] ||
                                           ((*(char *)((long)plVar5 + 0x47) != '\0' &&
                                            (*(char *)((long)plVar5 + 0x47) != pcVar2[0xf]))))))))))
                                       )))))))))))))))))))))))))))))))))))))))))))))))))) {
              puVar6 = *(undefined8 **)(param_2 + 0x40);
              pcVar2 = "Incorrect FWD device";
              do_trace_netlink_extack("Incorrect FWD device");
              iVar1 = -0x13;
              goto joined_r0x001058e8;
            }
            iVar1 = unregister_netdevice_notifier(plVar5 + 4);
            if (iVar1 != 0) {
              puVar6 = *(undefined8 **)(param_2 + 0x40);
              pcVar2 = "Unregistering notifier failed";
              do_trace_netlink_extack("Unregistering notifier failed");
              goto joined_r0x001058e8;
            }
            plVar3 = (long *)plVar5[1];
            if (plVar3 != (long *)0x0) {
              lVar4 = *plVar5;
              *plVar3 = lVar4;
              if (lVar4 != 0) {
                *(long **)(lVar4 + 8) = plVar3;
              }
              plVar5[1] = 0;
            }
            DATARMNETedae8262e1(plVar5 + 9);
            kvfree_call_rcu(plVar5 + 2,0x10);
            iVar1 = 0;
            goto LAB_001058ac;
          }
        }
        else if (param_1[1] == plVar5[10]) goto LAB_00105718;
      }
      plVar5 = (long *)*plVar5;
    } while (plVar5 != (long *)0x0);
  }
  __rcu_read_unlock();
  puVar6 = *(undefined8 **)(param_2 + 0x40);
  pcVar2 = "No such FWD information";
  do_trace_netlink_extack("No such FWD information");
  iVar1 = -3;
joined_r0x001058e8:
  if (puVar6 != (undefined8 *)0x0) {
    *puVar6 = pcVar2;
  }
LAB_001058ac:
  mutex_unlock(DATARMNETf46fb02ac6);
  return iVar1;
}



//------------------------------------------------------------
// DATARMNET8d5a5a7047 @ 0010592c size=272
// signature: undefined DATARMNET8d5a5a7047(void)
// callers: [DATARMNETc5f6c112ec]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNET8d5a5a7047(ushort param_1,long param_2)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined8 *puVar6;
  
  mutex_lock(DATARMNET954bef55d0);
  __rcu_read_lock();
  plVar1 = &DATARMNET133502ca0e + ((uint)param_1 * 0x61c88647 >> 0x1c);
  plVar2 = plVar1;
  do {
    plVar2 = (long *)*plVar2;
    if (plVar2 == (long *)0x0) {
      __rcu_read_unlock();
      plVar2 = (long *)kmalloc_trace(_ipv6_stub,0xdc0,0x28);
      if (plVar2 == (long *)0x0) {
        pcVar5 = "Cannot allocate encap port memory";
        puVar6 = *(undefined8 **)(param_2 + 0x40);
        do_trace_netlink_extack("Cannot allocate encap port memory");
        uVar4 = 0xfffffff4;
        if (puVar6 == (undefined8 *)0x0) goto LAB_00105a18;
        goto LAB_00105a14;
      }
      lVar3 = *plVar1;
      *(ushort *)(plVar2 + 4) = param_1;
      *plVar2 = lVar3;
      plVar2[1] = (long)plVar1;
      *plVar1 = (long)plVar2;
      if (lVar3 != 0) {
        *(long **)(lVar3 + 8) = plVar2;
      }
      DATARMNET5ca94dbc3c(0xe);
      uVar4 = 0;
      goto LAB_00105a18;
    }
  } while ((uint)*(ushort *)(plVar2 + 4) != (uint)param_1);
  __rcu_read_unlock();
  pcVar5 = "Encap port already present";
  puVar6 = *(undefined8 **)(param_2 + 0x40);
  do_trace_netlink_extack("Encap port already present");
  uVar4 = 0xffffffef;
  if (puVar6 != (undefined8 *)0x0) {
LAB_00105a14:
    *puVar6 = pcVar5;
  }
LAB_00105a18:
  mutex_unlock(DATARMNET954bef55d0);
  return uVar4;
}



//------------------------------------------------------------
// DATARMNETc97c6a4265 @ 00105a40 size=212
// signature: undefined DATARMNETc97c6a4265(void)
// callers: [DATARMNETa6aec23397]
//------------------------------------------------------------

undefined8 DATARMNETc97c6a4265(uint param_1,long param_2)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  
  mutex_lock(DATARMNET954bef55d0);
  plVar2 = (long *)(&DATARMNET133502ca0e)[(param_1 & 0xffff) * 0x61c88647 >> 0x1c];
  do {
    plVar1 = plVar2;
    if (plVar1 == (long *)0x0) {
      puVar5 = *(undefined8 **)(param_2 + 0x40);
      do_trace_netlink_extack("No such port value");
      uVar4 = 0xfffffffd;
      if (puVar5 != (undefined8 *)0x0) {
        *puVar5 = "No such port value";
      }
      goto LAB_00105af0;
    }
    plVar2 = (long *)*plVar1;
  } while ((uint)*(ushort *)(plVar1 + 4) != (param_1 & 0xffff));
  plVar3 = (long *)plVar1[1];
  if (plVar3 != (long *)0x0) {
    *plVar3 = (long)plVar2;
    if (plVar2 != (long *)0x0) {
      plVar2[1] = (long)plVar3;
    }
    plVar1[1] = 0;
  }
  kvfree_call_rcu(plVar1 + 2,0x10);
  DATARMNET5ca94dbc3c(0xf);
  uVar4 = 0;
LAB_00105af0:
  mutex_unlock(DATARMNET954bef55d0);
  return uVar4;
}



//------------------------------------------------------------
// DATARMNET4c1c11d8a5 @ 00105b18 size=196
// signature: undefined DATARMNET4c1c11d8a5(void)
// callers: [DATARMNET6a53c4576d]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNET4c1c11d8a5(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  mutex_lock(DATARMNET38726379d1);
  puVar3 = (undefined8 *)kmalloc_trace(_ipv6_stub,0xdc0,0x28);
  if (puVar3 == (undefined8 *)0x0) {
    uVar4 = 0xfffffff4;
  }
  else {
    uVar4 = param_1[3];
    uVar5 = param_1[4];
    puVar3[2] = param_1[2];
    puVar3[3] = uVar4;
    uVar4 = *param_1;
    uVar1 = param_1[1];
    puVar3[4] = uVar5;
    *puVar3 = uVar4;
    puVar3[1] = uVar1;
    uVar4 = _raw_spin_lock_irqsave(&DATARMNETe6ee7c273e);
    puVar2 = DATARMNETcde6e442f5;
    DATARMNETcde6e442f5 = puVar3;
    _raw_spin_unlock_irqrestore(&DATARMNETe6ee7c273e,uVar4);
    synchronize_rcu();
    uVar4 = 0;
    if (puVar2 != (undefined8 *)0x0) {
      kfree(puVar2);
      uVar4 = 0;
    }
  }
  mutex_unlock(DATARMNET38726379d1);
  return uVar4;
}



//------------------------------------------------------------
// DATARMNET56fde5181e @ 00105be0 size=116
// signature: undefined DATARMNET56fde5181e(void)
// callers: [DATARMNET425149b729]
//------------------------------------------------------------

undefined8 DATARMNET56fde5181e(void)

{
  long lVar1;
  undefined8 uVar2;
  
  mutex_lock(DATARMNET38726379d1);
  uVar2 = _raw_spin_lock_irqsave(&DATARMNETe6ee7c273e);
  lVar1 = DATARMNETcde6e442f5;
  DATARMNETcde6e442f5 = 0;
  _raw_spin_unlock_irqrestore(&DATARMNETe6ee7c273e,uVar2);
  synchronize_rcu();
  if (lVar1 != 0) {
    kfree(lVar1);
  }
  mutex_unlock(DATARMNET38726379d1);
  return 0;
}



//------------------------------------------------------------
// DATARMNETe14c875532 @ 00105c58 size=472
// signature: undefined DATARMNETe14c875532(void)
// callers: [DATARMNETc0cc5d08ba]
//------------------------------------------------------------

undefined8 DATARMNETe14c875532(long *param_1,undefined8 param_2,undefined4 *param_3)

{
  short *psVar1;
  short *psVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  long *plVar10;
  long lVar11;
  
  mutex_lock(&DATARMNET63a2b7773e);
  lVar6 = __alloc_skb(DATARMNET7c77d83017 * 0xc + 0x18,0xcc0,0,0xffffffff);
  if (lVar6 == 0) {
    uVar8 = 0xfffffff4;
  }
  else {
    lVar7 = genlmsg_put(lVar6,param_3[1],*param_3,param_2,0,0xe);
    if (lVar7 != 0) {
      lVar9 = *(long *)(lVar6 + 0xd8);
      uVar3 = *(uint *)(lVar6 + 0xd0);
      iVar5 = nla_put(lVar6,0x8001,0,0);
      if ((-1 < iVar5) && (psVar1 = (short *)(lVar9 + (ulong)uVar3), psVar1 != (short *)0x0)) {
        lVar9 = 0;
        do {
          for (plVar10 = (long *)(&DATARMNET1903907456)[lVar9]; plVar10 != (long *)0x0;
              plVar10 = (long *)*plVar10) {
            lVar11 = *(long *)(lVar6 + 0xd8);
            uVar3 = *(uint *)(lVar6 + 0xd0);
            iVar5 = nla_put(lVar6,0x8001,0,0);
            if ((-1 < iVar5) && (psVar2 = (short *)(lVar11 + (ulong)uVar3), psVar2 != (short *)0x0))
            {
              iVar5 = nla_put(lVar6,1,8,plVar10 + 4);
              if (iVar5 == 0) {
                *psVar2 = ((short)*(undefined4 *)(lVar6 + 0xd8) +
                          (short)*(undefined4 *)(lVar6 + 0xd0)) - (short)psVar2;
              }
              else {
                if (psVar2 < *(short **)(lVar6 + 0xe0)) {
                    /* WARNING: Does not return */
                  pcVar4 = (code *)SoftwareBreakpoint(0x800,0x105db8);
                  (*pcVar4)();
                }
                skb_trim(lVar6,(int)psVar2 - (int)*(short **)(lVar6 + 0xe0));
              }
            }
          }
          lVar9 = lVar9 + 1;
        } while (lVar9 != 0x10);
        *psVar1 = ((short)*(undefined4 *)(lVar6 + 0xd8) + (short)*(undefined4 *)(lVar6 + 0xd0)) -
                  (short)psVar1;
        *(int *)(lVar7 + -0x14) =
             (*(int *)(lVar6 + 0xd8) + *(int *)(lVar6 + 0xd0)) - ((int)lVar7 + -0x14);
        *param_1 = lVar6;
        mutex_unlock(&DATARMNET63a2b7773e);
        return 0;
      }
    }
    kfree(lVar6);
    uVar8 = 0xffffffea;
  }
  return uVar8;
}



//------------------------------------------------------------
// DATARMNET078f6bd384 @ 00105e3c size=32
// signature: undefined DATARMNET078f6bd384(void)
// callers: [DATARMNETa4773cb837]
//------------------------------------------------------------

undefined8 DATARMNET078f6bd384(void)

{
  DATARMNETbb4efa5b3d();
  return 0;
}



//------------------------------------------------------------
// DATARMNETbb4efa5b3d @ 00105e5c size=536
// signature: undefined DATARMNETbb4efa5b3d(void)
// callers: [DATARMNET078f6bd384, DATARMNETfae36afa03]
//------------------------------------------------------------

void DATARMNETbb4efa5b3d(void)

{
  long *plVar1;
  int iVar2;
  undefined8 uVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  
  if ((DATARMNET30500ba48c != '\0') &&
     (iVar2 = unregister_netdevice_notifier(&DATARMNETa1726000d8), iVar2 == 0)) {
    DATARMNET30500ba48c = '\0';
  }
  DATARMNET755f0f0df8 = 0;
  mutex_lock(DATARMNET954bef55d0);
  lVar6 = 0;
  do {
    plVar7 = (long *)(&DATARMNET133502ca0e)[lVar6];
    while (plVar7 != (long *)0x0) {
      plVar1 = (long *)*plVar7;
      plVar4 = (long *)plVar7[1];
      if (plVar4 != (long *)0x0) {
        *plVar4 = (long)plVar1;
        if (plVar1 != (long *)0x0) {
          plVar1[1] = (long)plVar4;
        }
        plVar7[1] = 0;
      }
      kvfree_call_rcu(plVar7 + 2,0x10);
      plVar7 = plVar1;
    }
    lVar6 = lVar6 + 1;
  } while (lVar6 != 0x10);
  mutex_unlock(DATARMNET954bef55d0);
  DATARMNET8c0e010dfb();
  mutex_lock(DATARMNETf46fb02ac6);
  lVar6 = 0;
  do {
    plVar7 = (long *)(&DATARMNET78ed39f13b)[lVar6];
    while (plVar1 = plVar7, plVar1 != (long *)0x0) {
      plVar7 = (long *)*plVar1;
      iVar2 = unregister_netdevice_notifier(plVar1 + 4);
      if (iVar2 == 0) {
        plVar4 = (long *)plVar1[1];
        if (plVar4 != (long *)0x0) {
          lVar5 = *plVar1;
          *plVar4 = lVar5;
          if (lVar5 != 0) {
            *(long **)(lVar5 + 8) = plVar4;
          }
          plVar1[1] = 0;
        }
        DATARMNETedae8262e1(plVar1 + 9);
        kvfree_call_rcu(plVar1 + 2,0x10);
      }
    }
    lVar6 = lVar6 + 1;
  } while (lVar6 != 0x10);
  mutex_unlock(DATARMNETf46fb02ac6);
  mutex_lock(&DATARMNET63a2b7773e);
  lVar6 = 0;
  DATARMNET7c77d83017 = 0;
  do {
    plVar7 = (long *)(&DATARMNET1903907456)[lVar6];
    while (plVar7 != (long *)0x0) {
      plVar1 = (long *)*plVar7;
      plVar4 = (long *)plVar7[1];
      if (plVar4 != (long *)0x0) {
        *plVar4 = (long)plVar1;
        if (plVar1 != (long *)0x0) {
          plVar1[1] = (long)plVar4;
        }
        plVar7[1] = 0;
      }
      kvfree_call_rcu(plVar7 + 2,0x10);
      plVar7 = plVar1;
    }
    lVar6 = lVar6 + 1;
  } while (lVar6 != 0x10);
  mutex_unlock(&DATARMNET63a2b7773e);
  mutex_lock(DATARMNET38726379d1);
  uVar3 = _raw_spin_lock_irqsave(&DATARMNETe6ee7c273e);
  lVar6 = DATARMNETcde6e442f5;
  DATARMNETcde6e442f5 = 0;
  _raw_spin_unlock_irqrestore(&DATARMNETe6ee7c273e,uVar3);
  synchronize_rcu();
  if (lVar6 != 0) {
    kfree(lVar6);
  }
  mutex_unlock(DATARMNET38726379d1);
  return;
}



//------------------------------------------------------------
// DATARMNETfae36afa03 @ 00106078 size=28
// signature: undefined DATARMNETfae36afa03(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void DATARMNETfae36afa03(void)

{
  DATARMNETbb4efa5b3d();
  return;
}



//------------------------------------------------------------
// DATARMNET934406764d @ 00106098 size=12
// signature: undefined DATARMNET934406764d(void)
// callers: [DATARMNETd2f80b03ce]
//------------------------------------------------------------

undefined1 * DATARMNET934406764d(void)

{
  return &DATARMNET30500ba48c;
}



//------------------------------------------------------------
// DATARMNETe447822105 @ 001060a8 size=12
// signature: undefined DATARMNETe447822105(void)
// callers: [DATARMNETd2f80b03ce]
//------------------------------------------------------------

undefined1 * DATARMNETe447822105(void)

{
  return &DATARMNET755f0f0df8;
}



//------------------------------------------------------------
// DATARMNET0ed065ddb7 @ 001060b8 size=624
// signature: undefined DATARMNET0ed065ddb7(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET0ed065ddb7(undefined8 param_1,long param_2,undefined8 *param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined *puVar4;
  char cVar5;
  
  pcVar3 = (char *)*param_3;
  if (pcVar3 == (char *)0x0) {
    return 0;
  }
  cVar5 = *pcVar3;
  if (cVar5 != DATARMNET30500ba48c) {
    return 0;
  }
  cVar1 = pcVar3[1];
  if (cVar1 == '\0') {
    if (cVar5 != 'r') goto LAB_001062d4;
  }
  else {
    if (cVar1 != DAT_001069a5) {
      return 0;
    }
    if (pcVar3[2] != '\0') {
      if (pcVar3[2] != DAT_001069a6) {
        return 0;
      }
      if (pcVar3[3] != '\0') {
        if (pcVar3[3] != DAT_001069a7) {
          return 0;
        }
        if (pcVar3[4] != '\0') {
          if (pcVar3[4] != DAT_001069a8) {
            return 0;
          }
          if (pcVar3[5] != '\0') {
            if (pcVar3[5] != DAT_001069a9) {
              return 0;
            }
            if (pcVar3[6] != '\0') {
              if (pcVar3[6] != DAT_001069aa) {
                return 0;
              }
              if (pcVar3[7] != '\0') {
                if (pcVar3[7] != DAT_001069ab) {
                  return 0;
                }
                if (pcVar3[8] != '\0') {
                  if (pcVar3[8] != DAT_001069ac) {
                    return 0;
                  }
                  if (pcVar3[9] != '\0') {
                    if (pcVar3[9] != DAT_001069ad) {
                      return 0;
                    }
                    if (pcVar3[10] != '\0') {
                      if (pcVar3[10] != DAT_001069ae) {
                        return 0;
                      }
                      if (pcVar3[0xb] != '\0') {
                        if (pcVar3[0xb] != DAT_001069af) {
                          return 0;
                        }
                        if (pcVar3[0xc] != '\0') {
                          if (pcVar3[0xc] != DAT_001069b0) {
                            return 0;
                          }
                          if (pcVar3[0xd] != '\0') {
                            if (pcVar3[0xd] != DAT_001069b1) {
                              return 0;
                            }
                            if (pcVar3[0xe] != '\0') {
                              if (pcVar3[0xe] != DAT_001069b2) {
                                return 0;
                              }
                              if ((pcVar3[0xf] != '\0') && (pcVar3[0xf] != DAT_001069b3)) {
                                return 0;
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
          }
        }
      }
    }
    if ((cVar5 != 'r') ||
       ((cVar1 != '\0' &&
        ((cVar1 != 'm' ||
         ((((((cVar5 = pcVar3[2], cVar5 != 'n' || (cVar5 = pcVar3[3], cVar5 != 'e')) ||
             (cVar5 = pcVar3[4], cVar5 != 't')) ||
            ((cVar5 = pcVar3[5], cVar5 != '_' || (cVar5 = pcVar3[6], cVar5 != 'd')))) ||
           ((cVar5 = pcVar3[7], cVar5 != 'a' ||
            ((cVar5 = pcVar3[8], cVar5 != 't' || (cVar5 = pcVar3[9], cVar5 != 'a')))))) &&
          (cVar5 != '\0')))))))) {
LAB_001062d4:
      if (param_2 != 5) {
        if (param_2 == 6) {
          netdev_rx_handler_unregister();
          return 0;
        }
        return 0;
      }
      iVar2 = netdev_rx_handler_register(pcVar3,DATARMNET37a92021f9,0);
      if (iVar2 == 0) {
        return 0;
      }
      puVar4 = &DAT_001077c8;
      goto LAB_00106318;
    }
  }
  puVar4 = &DAT_001076f2;
LAB_00106318:
  _printk(puVar4,"DATARMNET0ed065ddb7");
  return 0;
}



//------------------------------------------------------------
// DATARMNETe98553a8fc @ 0010632c size=580
// signature: undefined DATARMNETe98553a8fc(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETe98553a8fc(long param_1,long param_2,undefined8 *param_3)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  long lVar5;
  char *pcVar6;
  long lVar7;
  
  pcVar6 = (char *)*param_3;
  if (((pcVar6 != (char *)0x0) && (*pcVar6 == *(char *)(param_1 + 0x18))) &&
     ((pcVar6[1] == '\0' ||
      ((pcVar6[1] == *(char *)(param_1 + 0x19) &&
       ((pcVar6[2] == '\0' ||
        ((pcVar6[2] == *(char *)(param_1 + 0x1a) &&
         ((pcVar6[3] == '\0' ||
          ((pcVar6[3] == *(char *)(param_1 + 0x1b) &&
           ((pcVar6[4] == '\0' ||
            ((pcVar6[4] == *(char *)(param_1 + 0x1c) &&
             ((pcVar6[5] == '\0' ||
              ((pcVar6[5] == *(char *)(param_1 + 0x1d) &&
               ((pcVar6[6] == '\0' ||
                ((pcVar6[6] == *(char *)(param_1 + 0x1e) &&
                 ((pcVar6[7] == '\0' ||
                  ((pcVar6[7] == *(char *)(param_1 + 0x1f) &&
                   ((pcVar6[8] == '\0' ||
                    ((pcVar6[8] == *(char *)(param_1 + 0x20) &&
                     ((pcVar6[9] == '\0' ||
                      ((pcVar6[9] == *(char *)(param_1 + 0x21) &&
                       ((pcVar6[10] == '\0' ||
                        ((pcVar6[10] == *(char *)(param_1 + 0x22) &&
                         ((pcVar6[0xb] == '\0' ||
                          ((pcVar6[0xb] == *(char *)(param_1 + 0x23) &&
                           ((pcVar6[0xc] == '\0' ||
                            ((pcVar6[0xc] == *(char *)(param_1 + 0x24) &&
                             ((pcVar6[0xd] == '\0' ||
                              ((pcVar6[0xd] == *(char *)(param_1 + 0x25) &&
                               ((pcVar6[0xe] == '\0' ||
                                ((pcVar6[0xe] == *(char *)(param_1 + 0x26) &&
                                 ((pcVar6[0xf] == '\0' || (pcVar6[0xf] == *(char *)(param_1 + 0x27))
                                  ))))))))))))))))))))))))))))))))))))))))))))))))))))))))))) {
    if (param_2 == 1) {
      if (*(long *)(param_1 + 0x28) == 0) {
        lVar7 = sp_el0;
        *(int *)(lVar7 + 0x10) = *(int *)(lVar7 + 0x10) + 1;
        lVar4 = tpidr_el1;
        piVar1 = (int *)(lVar4 + *(long *)(pcVar6 + 0x4d8));
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar3) {
            *piVar1 = *piVar1 + 1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        lVar4 = *(long *)(lVar7 + 0x10) + -1;
        *(int *)(lVar7 + 0x10) = (int)lVar4;
        if ((lVar4 == 0) || (*(long *)(lVar7 + 0x10) == 0)) {
          preempt_schedule_notrace();
        }
        *(char **)(param_1 + 0x28) = pcVar6;
      }
    }
    else if ((param_2 == 10) && (lVar7 = *(long *)(param_1 + 0x28), lVar7 != 0)) {
      lVar4 = sp_el0;
      *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + 1;
      lVar5 = tpidr_el1;
      piVar1 = (int *)(lVar5 + *(long *)(lVar7 + 0x4d8));
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar3) {
          *piVar1 = *piVar1 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      lVar7 = *(long *)(lVar4 + 0x10) + -1;
      *(int *)(lVar4 + 0x10) = (int)lVar7;
      if ((lVar7 == 0) || (*(long *)(lVar4 + 0x10) == 0)) {
        preempt_schedule_notrace();
      }
      *(undefined8 *)(param_1 + 0x28) = 0;
    }
  }
  return 0;
}



//------------------------------------------------------------
// DATARMNET5ca94dbc3c @ 0010659c size=36
// signature: undefined DATARMNET5ca94dbc3c(void)
// callers: [DATARMNET37a92021f9, DATARMNETad2b7fd8f5, DATARMNET59b8376224, DATARMNETc97c6a4265, DATARMNET7ca470d54b, DATARMNET07f6485c9b, DATARMNET0b12e969c5, DATARMNET9d6ad3b16f, DATARMNET8d5a5a7047, DATARMNETc7c83f614f, DATARMNET53f12a0f7d, DATARMNET6f73df41cd, DATARMNET4899053671]
//------------------------------------------------------------

void DATARMNET5ca94dbc3c(uint param_1)

{
  if (param_1 < 0x17) {
    *(long *)(&DATARMNET24d235c444 + (ulong)param_1 * 8) =
         *(long *)(&DATARMNET24d235c444 + (ulong)param_1 * 8) + 1;
  }
  return;
}



//------------------------------------------------------------
// DATARMNET17f6bc1be5 @ 001065c4 size=36
// signature: undefined DATARMNET17f6bc1be5(void)
// callers: [DATARMNETd2f80b03ce]
//------------------------------------------------------------

void DATARMNET17f6bc1be5(uint param_1)

{
  if (param_1 < 0x2e) {
    *(long *)(DATARMNET9f5801b25f + (ulong)param_1 * 8) =
         *(long *)(DATARMNET9f5801b25f + (ulong)param_1 * 8) + 1;
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00107834 size=224
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  _printk(&DAT_0010765b,"DATARMNET7eb0fa5c8f");
  iVar1 = genl_register_family(&DATARMNET61e8f41aae);
  if (iVar1 == 0) {
    iVar1 = DATARMNET9f106ed933();
    if (iVar1 == 0) {
      iVar1 = DATARMNET49c2c17e77();
      if (iVar1 == 0) {
        DATARMNET333c107558();
        _printk(&DAT_0010767c,"DATARMNET7eb0fa5c8f");
        return 0;
      }
      _printk(&DAT_00107598,"DATARMNET7eb0fa5c8f",iVar1);
      DATARMNETf56cbaa2b1();
    }
    else {
      _printk(&DAT_001077ec,"DATARMNET7eb0fa5c8f",iVar1);
    }
    genl_unregister_family(&DATARMNET61e8f41aae);
  }
  else {
    _printk(&DAT_001075fa,"DATARMNET7eb0fa5c8f",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00107918 size=144
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  int iVar1;
  
  _printk(&DAT_0010769e,"DATARMNET7a381832d5");
  iVar1 = DATARMNETf56cbaa2b1();
  if (iVar1 != 0) {
    _printk(&DAT_00107751,"DATARMNET7a381832d5",iVar1);
  }
  DATARMNETfae36afa03();
  iVar1 = genl_unregister_family(&DATARMNET61e8f41aae);
  if (iVar1 != 0) {
    _printk(&DAT_001076ba,"DATARMNET7a381832d5",iVar1);
  }
  DATARMNET4c08c7210c();
  _printk(&DAT_00107783,"DATARMNET7a381832d5");
  return;
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 0010a000 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [DATARMNETf56cbaa2b1, DATARMNET8c0e010dfb, DATARMNETf4e1a29dbc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 0010a010 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [DATARMNETad2b7fd8f5, DATARMNETf56cbaa2b1, DATARMNET9d6ad3b16f, DATARMNET8c0e010dfb, DATARMNETf4e1a29dbc, DATARMNETd2f80b03ce, DATARMNET8211acc766]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_copy_bits @ 0010a018 size=1
// signature: undefined skb_copy_bits(void)
// callers: [DATARMNETa8b2566e6a, DATARMNETaca8ca54ed, skb_header_pointer, DATARMNET6f73df41cd, DATARMNETd2f80b03ce, DATARMNET7ca470d54b]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_copy_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010a020 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [DATARMNET37a92021f9, DATARMNET6a53c4576d, DATARMNETa8b2566e6a, DATARMNETc0cc5d08ba, DATARMNETaca8ca54ed, DATARMNETd2f80b03ce, DATARMNETc175a08219, DATARMNET7ca470d54b, DATARMNET72501635c8, DATARMNET41dd9b14ab, DATARMNETb86993aefb, DATARMNET6f73df41cd, DATARMNET579f75aa50]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_module_hook_register @ 0010a030 size=1
// signature: undefined rmnet_module_hook_register(void)
// callers: [DATARMNET333c107558]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_module_hook_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_module_hook_unregister_no_sync @ 0010a038 size=1
// signature: undefined rmnet_module_hook_unregister_no_sync(void)
// callers: [DATARMNET4c08c7210c]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_module_hook_unregister_no_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// synchronize_rcu @ 0010a040 size=1
// signature: undefined synchronize_rcu(void)
// callers: [DATARMNETbb4efa5b3d, DATARMNET4c08c7210c, DATARMNET56fde5181e, DATARMNET4c1c11d8a5]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void synchronize_rcu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 0010a050 size=1
// signature: undefined init_timer_key(void)
// callers: [DATARMNET9f106ed933, DATARMNET49c2c17e77]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0010a058 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [DATARMNETad2b7fd8f5, DATARMNETbb4efa5b3d, DATARMNET9d6ad3b16f, DATARMNETc7c83f614f, DATARMNET56fde5181e, DATARMNET4c1c11d8a5, DATARMNETd2f80b03ce, DATARMNET8211acc766]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kvfree_call_rcu @ 0010a068 size=1
// signature: undefined kvfree_call_rcu(void)
// callers: [DATARMNETad2b7fd8f5, DATARMNETbb4efa5b3d, DATARMNET59b8376224, DATARMNETc97c6a4265, DATARMNET07f6485c9b, DATARMNET8211acc766, DATARMNETb8b35fdc18]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kvfree_call_rcu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0010a070 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [DATARMNETad2b7fd8f5, DATARMNETbb4efa5b3d, DATARMNET9d6ad3b16f, DATARMNETc7c83f614f, DATARMNET56fde5181e, DATARMNET4c1c11d8a5, DATARMNETd2f80b03ce, DATARMNET8211acc766]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_lock @ 0010a078 size=1
// signature: undefined __rcu_read_lock(void)
// callers: [DATARMNET37a92021f9, DATARMNET0b12e969c5, DATARMNET8d5a5a7047, DATARMNETedae8262e1, DATARMNET53f12a0f7d, DATARMNETd2f80b03ce, DATARMNET947eb110d2, DATARMNETb8b35fdc18]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_unlock @ 0010a080 size=1
// signature: undefined __rcu_read_unlock(void)
// callers: [DATARMNET37a92021f9, DATARMNET0b12e969c5, DATARMNET8d5a5a7047, DATARMNETedae8262e1, DATARMNET53f12a0f7d, DATARMNETd2f80b03ce, DATARMNET947eb110d2, DATARMNETb8b35fdc18]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipv6_skip_exthdr @ 0010a088 size=1
// signature: undefined ipv6_skip_exthdr(void)
// callers: [DATARMNET37a92021f9, DATARMNETd2f80b03ce, DATARMNET7ca470d54b]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipv6_skip_exthdr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010a098 size=1
// signature: undefined kmalloc_trace(void)
// callers: [DATARMNET0b12e969c5, DATARMNET9d6ad3b16f, DATARMNET8d5a5a7047, DATARMNET53f12a0f7d, DATARMNET4c1c11d8a5, DATARMNETd2f80b03ce, DATARMNET947eb110d2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pskb_pull_tail @ 0010a0a0 size=1
// signature: undefined __pskb_pull_tail(void)
// callers: [DATARMNETd2f80b03ce, DATARMNET7ca470d54b]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pskb_pull_tail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_by_name_rcu @ 0010a0b0 size=1
// signature: undefined dev_get_by_name_rcu(void)
// callers: [DATARMNET37a92021f9, DATARMNETd2f80b03ce]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_by_name_rcu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ip_route_output_flow @ 0010a0b8 size=1
// signature: undefined ip_route_output_flow(void)
// callers: [DATARMNETd2f80b03ce]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ip_route_output_flow(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dst_release @ 0010a0c8 size=1
// signature: undefined dst_release(void)
// callers: [DATARMNETd2f80b03ce]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dst_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// neigh_destroy @ 0010a0d8 size=1
// signature: undefined neigh_destroy(void)
// callers: [neigh_release, DATARMNETd2f80b03ce]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void neigh_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xfrm_lookup @ 0010a0e0 size=1
// signature: undefined xfrm_lookup(void)
// callers: [DATARMNETd2f80b03ce]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xfrm_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// neigh_resolve_output @ 0010a0e8 size=1
// signature: undefined neigh_resolve_output(void)
// callers: [DATARMNETd2f80b03ce]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void neigh_resolve_output(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_skb_reason @ 0010a0f0 size=1
// signature: undefined kfree_skb_reason(void)
// callers: [DATARMNET37a92021f9, DATARMNET9d6ad3b16f, DATARMNETd2f80b03ce]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_skb_reason(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 0010a0f8 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [neigh_release, DATARMNETd2f80b03ce]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0010a100 size=1
// signature: undefined __list_add_valid(void)
// callers: [DATARMNET9d6ad3b16f]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipv6_ext_hdr @ 0010a108 size=1
// signature: undefined ipv6_ext_hdr(void)
// callers: [DATARMNETaca8ca54ed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipv6_ext_hdr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __netif_rx @ 0010a110 size=1
// signature: undefined __netif_rx(void)
// callers: [DATARMNETad2b7fd8f5, DATARMNETc7c83f614f]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __netif_rx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0010a118 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [DATARMNETad2b7fd8f5, DATARMNETc7c83f614f]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010a128 size=1
// signature: undefined _printk(void)
// callers: [DATARMNET0ed065ddb7, cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genl_register_family @ 0010a130 size=1
// signature: undefined genl_register_family(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genl_register_family(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genl_unregister_family @ 0010a138 size=1
// signature: undefined genl_unregister_family(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genl_unregister_family(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// do_trace_netlink_extack @ 0010a140 size=1
// signature: undefined do_trace_netlink_extack(void)
// callers: [DATARMNET6a53c4576d, DATARMNET97b2388e63, DATARMNET92e5468fc5, DATARMNETb318ed4796, DATARMNETc97c6a4265, DATARMNETc175a08219, DATARMNET07f6485c9b, DATARMNETc5f6c112ec, DATARMNET947eb110d2, DATARMNETb8b35fdc18, DATARMNET72501635c8, DATARMNET41dd9b14ab, DATARMNET0b12e969c5, DATARMNET8d5a5a7047, DATARMNETcd9478470c, DATARMNET53f12a0f7d, DATARMNETb86993aefb, DATARMNET16add73734, DATARMNETf1fa473089, DATARMNETa6aec23397]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void do_trace_netlink_extack(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0010a148 size=1
// signature: undefined __kmalloc(void)
// callers: [DATARMNET72501635c8, DATARMNET41dd9b14ab]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __nla_parse @ 0010a150 size=1
// signature: undefined __nla_parse(void)
// callers: [DATARMNET72501635c8, DATARMNET41dd9b14ab]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __nla_parse(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010a158 size=1
// signature: undefined kfree(void)
// callers: [DATARMNET72501635c8, DATARMNET41dd9b14ab, DATARMNETbb4efa5b3d, DATARMNETe14c875532, DATARMNET56fde5181e, DATARMNET4c1c11d8a5, DATARMNET947eb110d2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strchr @ 0010a160 size=1
// signature: char * strchr(char * __s, int __c)
// callers: [DATARMNET6a53c4576d, DATARMNETb86993aefb, DATARMNETc175a08219]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strchr(char *__s,int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// in6_pton @ 0010a168 size=1
// signature: undefined in6_pton(void)
// callers: [DATARMNET6a53c4576d, DATARMNETb86993aefb, DATARMNETc175a08219]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void in6_pton(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// in4_pton @ 0010a170 size=1
// signature: undefined in4_pton(void)
// callers: [DATARMNET6a53c4576d, DATARMNETb86993aefb, DATARMNETc175a08219]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void in4_pton(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_by_name @ 0010a178 size=1
// signature: undefined dev_get_by_name(void)
// callers: [DATARMNETb86993aefb, DATARMNETc175a08219]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule_notrace @ 0010a180 size=1
// signature: undefined preempt_schedule_notrace(void)
// callers: [DATARMNETb86993aefb, DATARMNETc175a08219, DATARMNETe98553a8fc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule_notrace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netlink_unicast @ 0010a188 size=1
// signature: undefined netlink_unicast(void)
// callers: [DATARMNETc0cc5d08ba]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netlink_unicast(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __dev_queue_xmit @ 0010a190 size=1
// signature: undefined __dev_queue_xmit(void)
// callers: [DATARMNET37a92021f9, DATARMNET4899053671]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __dev_queue_xmit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pskb_expand_head @ 0010a198 size=1
// signature: undefined pskb_expand_head(void)
// callers: [DATARMNET7ca470d54b]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pskb_expand_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_put @ 0010a1a0 size=1
// signature: undefined skb_put(void)
// callers: [DATARMNET7ca470d54b]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010a1a8 size=1
// signature: undefined mutex_lock(void)
// callers: [DATARMNETbb4efa5b3d, DATARMNET8d5a5a7047, DATARMNETe14c875532, DATARMNET53f12a0f7d, DATARMNET56fde5181e, DATARMNET4c1c11d8a5, DATARMNETc97c6a4265, DATARMNET07f6485c9b, DATARMNET947eb110d2, DATARMNETb8b35fdc18]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010a1b0 size=1
// signature: undefined mutex_unlock(void)
// callers: [DATARMNETbb4efa5b3d, DATARMNET8d5a5a7047, DATARMNETe14c875532, DATARMNET53f12a0f7d, DATARMNET56fde5181e, DATARMNET4c1c11d8a5, DATARMNETc97c6a4265, DATARMNET07f6485c9b, DATARMNET947eb110d2, DATARMNETb8b35fdc18]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_netdevice_notifier @ 0010a1b8 size=1
// signature: undefined unregister_netdevice_notifier(void)
// callers: [DATARMNETbb4efa5b3d, DATARMNET97b2388e63, DATARMNETa903cd5994, DATARMNETb8b35fdc18]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_netdevice_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0010a1c0 size=1
// signature: size_t strlen(char * __s)
// callers: [DATARMNET97b2388e63, DATARMNET92e5468fc5]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0010a1c8 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [DATARMNET97b2388e63, DATARMNET92e5468fc5, DATARMNET947eb110d2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_netdevice_notifier @ 0010a1d0 size=1
// signature: undefined register_netdevice_notifier(void)
// callers: [DATARMNET97b2388e63, DATARMNET947eb110d2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_netdevice_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 0010a1d8 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [DATARMNET947eb110d2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 0010a1e0 size=1
// signature: undefined fortify_panic(void)
// callers: [DATARMNET947eb110d2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_skb @ 0010a1e8 size=1
// signature: undefined __alloc_skb(void)
// callers: [DATARMNETe14c875532]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genlmsg_put @ 0010a1f0 size=1
// signature: undefined genlmsg_put(void)
// callers: [DATARMNETe14c875532]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genlmsg_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nla_put @ 0010a1f8 size=1
// signature: undefined nla_put(void)
// callers: [DATARMNETe14c875532]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nla_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_trim @ 0010a200 size=1
// signature: undefined skb_trim(void)
// callers: [DATARMNETe14c875532]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_trim(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netdev_rx_handler_unregister @ 0010a208 size=1
// signature: undefined netdev_rx_handler_unregister(void)
// callers: [DATARMNET0ed065ddb7]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netdev_rx_handler_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netdev_rx_handler_register @ 0010a210 size=1
// signature: undefined netdev_rx_handler_register(void)
// callers: [DATARMNET0ed065ddb7]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netdev_rx_handler_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



