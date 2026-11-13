// Decompiled by Ghidra 12.2
// Program: rmnet_mem.ko
// Image base: 00100000

//------------------------------------------------------------
// rmnet_mem_page_ref_inc_entry @ 0010051c size=4
// signature: undefined rmnet_mem_page_ref_inc_entry(void)
// callers: []
//------------------------------------------------------------

void rmnet_mem_page_ref_inc_entry(long param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  
  piVar1 = (int *)(param_1 + 0x34);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar3) {
      *piVar1 = *piVar1 + 1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  return;
}



//------------------------------------------------------------
// FUN_00100530 @ 00100530 size=28
// signature: undefined FUN_00100530(void)
// callers: []
//------------------------------------------------------------

void FUN_00100530(long param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  
  piVar1 = (int *)(param_1 + 0x34);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar3) {
      *piVar1 = *piVar1 + 1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  return;
}



//------------------------------------------------------------
// rmnet_mem_mode_notify @ 00100550 size=100
// signature: undefined rmnet_mem_mode_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_mem_mode_notify(undefined4 param_1)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(0x101b20);
  raw_notifier_call_chain(rmnet_mem_notifier,param_1,0);
  _raw_spin_unlock_irqrestore(0x101b20,uVar1);
  return 1;
}



//------------------------------------------------------------
// rmnet_mem_register_notifier @ 001005b8 size=100
// signature: undefined rmnet_mem_register_notifier(void)
// callers: []
//------------------------------------------------------------

undefined4 rmnet_mem_register_notifier(undefined8 param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = _raw_spin_lock_irqsave(0x101b20);
  uVar1 = raw_notifier_chain_register(rmnet_mem_notifier,param_1);
  _raw_spin_unlock_irqrestore(0x101b20,uVar2);
  return uVar1;
}



//------------------------------------------------------------
// rmnet_mem_unregister_notifier @ 00100620 size=100
// signature: undefined rmnet_mem_unregister_notifier(void)
// callers: []
//------------------------------------------------------------

undefined4 rmnet_mem_unregister_notifier(undefined8 param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = _raw_spin_lock_irqsave(0x101b20);
  uVar1 = raw_notifier_chain_unregister(rmnet_mem_notifier,param_1);
  _raw_spin_unlock_irqrestore(0x101b20,uVar2);
  return uVar1;
}



//------------------------------------------------------------
// rmnet_mem_add_page @ 00100688 size=236
// signature: undefined rmnet_mem_add_page(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * rmnet_mem_add_page(undefined8 param_1,byte param_2)

{
  undefined8 *puVar1;
  long *plVar2;
  int iVar3;
  code *pcVar4;
  undefined8 *puVar5;
  ulong uVar6;
  long lVar7;
  
  puVar5 = (undefined8 *)kmalloc_trace(_kfree,0xb20,0x20);
  if (puVar5 != (undefined8 *)0x0) {
    if (4 < param_2) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x100774);
      (*pcVar4)();
    }
    if ((param_2 == 4) || (4 < param_2)) {
LAB_0010076c:
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(1,0x100770);
      (*pcVar4)();
    }
    uVar6 = (ulong)param_2;
    puVar1 = puVar5 + 1;
    *(byte *)(puVar5 + 3) = param_2;
    iVar3 = (&static_pool_size)[uVar6];
    *puVar5 = param_1;
    (&static_pool_size)[uVar6] = iVar3 + 1;
    puVar5[1] = puVar1;
    puVar5[2] = puVar1;
    if (param_2 != 4) {
      if (4 < param_2) goto LAB_0010076c;
      plVar2 = &rmnet_mem_pool + uVar6 * 2;
      lVar7 = *plVar2;
      uVar6 = __list_add_valid(puVar1,plVar2,lVar7);
      if ((uVar6 & 1) != 0) {
        puVar5[1] = lVar7;
        puVar5[2] = plVar2;
        *plVar2 = (long)puVar1;
        *(undefined8 **)(lVar7 + 8) = puVar1;
      }
    }
  }
  return puVar5;
}



//------------------------------------------------------------
// rmnet_mem_free_all @ 00100778 size=352
// signature: undefined rmnet_mem_free_all(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void rmnet_mem_free_all(void)

{
  int *piVar1;
  long *plVar2;
  byte bVar3;
  int iVar4;
  char cVar5;
  bool bVar6;
  long *plVar7;
  code *pcVar8;
  undefined8 uVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  long *plVar13;
  
  uVar9 = _raw_spin_lock_irqsave(&rmnet_mem_lock);
  lVar12 = 0;
  do {
    plVar7 = (long *)(&rmnet_mem_pool)[lVar12 * 2];
    while (plVar7 != &rmnet_mem_pool + lVar12 * 2) {
      plVar13 = (long *)*plVar7;
      uVar10 = __list_del_entry_valid(plVar7);
      if ((uVar10 & 1) != 0) {
        lVar11 = *plVar7;
        plVar2 = (long *)plVar7[1];
        *(long **)(lVar11 + 8) = plVar2;
        *plVar2 = lVar11;
      }
      lVar11 = plVar7[-1];
      *plVar7 = -0x2152ffffffffff00;
      plVar7[1] = -0x2152fffffffffede;
      if ((*(ulong *)(lVar11 + 8) & 1) != 0) {
        lVar11 = *(ulong *)(lVar11 + 8) - 1;
      }
      piVar1 = (int *)(lVar11 + 0x34);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar4 = *piVar1;
        cVar5 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar6) {
          *piVar1 = iVar4 + -1;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      DataMemoryBarrier(2,3);
      if (iVar4 + -1 == 0) {
        __folio_put();
      }
      bVar3 = *(byte *)(plVar7 + 2);
      if (4 < bVar3) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x1008f8);
        (*pcVar8)();
      }
      if ((bVar3 == 4) || (4 < bVar3)) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(1,0x1008f4);
        (*pcVar8)();
      }
      (&static_pool_size)[bVar3] = (&static_pool_size)[bVar3] + -1;
      kfree(plVar7 + -1);
      plVar7 = plVar13;
    }
    lVar12 = lVar12 + 1;
    if (lVar12 == 4) {
      _raw_spin_unlock_irqrestore(&rmnet_mem_lock,uVar9);
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// rmnet_mem_get_pages_entry @ 001008fc size=1364
// signature: undefined rmnet_mem_get_pages_entry(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long rmnet_mem_get_pages_entry
               (uint param_1,uint param_2,undefined4 *param_3,uint *param_4,uint param_5)

{
  ulong uVar1;
  undefined8 *puVar2;
  int *piVar3;
  ulong uVar4;
  long lVar5;
  long *plVar6;
  char cVar7;
  bool bVar8;
  bool bVar9;
  undefined8 uVar10;
  code *pcVar11;
  undefined8 uVar12;
  ulong uVar13;
  long *plVar14;
  undefined4 uVar15;
  long lVar16;
  long lVar17;
  int iVar18;
  ulong uVar19;
  uint uVar20;
  ulong uVar21;
  long lVar22;
  long *plVar23;
  undefined8 *puVar24;
  
  uVar19 = (ulong)param_2;
  uVar12 = _raw_spin_lock_irqsave(&rmnet_mem_lock);
  if ((3 < param_2) || (4 < param_5)) {
                    /* WARNING: Does not return */
    pcVar11 = (code *)SoftwareBreakpoint(0x5512,0x100e3c);
    (*pcVar11)();
  }
  if ((param_5 == 4) || (4 < param_5)) goto LAB_00100e34;
  lVar16 = (ulong)param_5 * 4;
  *(int *)(rmnet_mem_id_req + lVar16) = *(int *)(rmnet_mem_id_req + lVar16) + 1;
  if (3 < param_2) goto LAB_00100e34;
  uVar21 = (ulong)param_2;
  lVar17 = uVar21 * 4;
  lVar22 = 0;
  uVar20 = param_2 - 1;
  *(int *)(rmnet_mem_order_requests + lVar17) = *(int *)(rmnet_mem_order_requests + lVar17) + 1;
  uVar1 = uVar21;
  while (uVar20 < 3) {
    plVar14 = &rmnet_mem_pool + uVar1 * 2;
    uVar4 = uVar1 << 4 | 8;
    puVar2 = &DAT_00101b40 + uVar1 * 2;
    iVar18 = 6;
    while( true ) {
      plVar23 = (long *)*plVar14 + -1;
      if ((long *)*plVar14 == plVar14 || plVar23 == (long *)0x0) goto LAB_00100b1c;
      if (*(int *)(*plVar23 + 0x34) == 1) break;
      plVar23 = (long *)*plVar14;
      if (plVar23 == plVar14) goto LAB_00100a08;
      uVar13 = __list_del_entry_valid(plVar23);
      if ((uVar13 & 1) != 0) {
        lVar5 = *plVar23;
        plVar6 = (long *)plVar23[1];
        *(long **)(lVar5 + 8) = plVar6;
        *plVar6 = lVar5;
      }
      if (0x40 < uVar4) goto LAB_00100e34;
      puVar24 = (undefined8 *)*puVar2;
      uVar13 = __list_add_valid(plVar23,puVar24,plVar14);
      if ((uVar13 & 1) != 0) {
        if (0x40 < uVar4) goto LAB_00100e34;
        *puVar2 = plVar23;
        *plVar23 = (long)plVar14;
        plVar23[1] = (long)puVar24;
        *puVar24 = plVar23;
      }
LAB_00100a08:
      iVar18 = iVar18 + -1;
      if (iVar18 == 0) goto LAB_00100b1c;
    }
    if ((uVar1 & 0x3ffffffffffffffc) != 0) goto LAB_00100e34;
    *(int *)(rmnet_mem_id_recycled + uVar1 * 4) = *(int *)(rmnet_mem_id_recycled + uVar1 * 4) + 1;
    lVar22 = *plVar23;
    piVar3 = (int *)(lVar22 + 0x34);
    Hint_Prefetch(piVar3,2,0,1);
    do {
      cVar7 = '\x01';
      bVar9 = (bool)ExclusiveMonitorPass(piVar3,0x10);
      if (bVar9) {
        *piVar3 = *piVar3 + 1;
        cVar7 = ExclusiveMonitorsStatus();
      }
    } while (cVar7 != '\0');
    plVar23 = (long *)*plVar14;
    if (plVar23 != plVar14) {
      uVar13 = __list_del_entry_valid(plVar23);
      if ((uVar13 & 1) != 0) {
        lVar5 = *plVar23;
        plVar6 = (long *)plVar23[1];
        *(long **)(lVar5 + 8) = plVar6;
        *plVar6 = lVar5;
      }
      if (0x40 < uVar4) goto LAB_00100e34;
      puVar24 = (undefined8 *)*puVar2;
      uVar13 = __list_add_valid(plVar23,puVar24,plVar14);
      if ((uVar13 & 1) != 0) {
        if (0x40 < uVar4) goto LAB_00100e34;
        *puVar2 = plVar23;
        *plVar23 = (long)plVar14;
        plVar23[1] = (long)puVar24;
        *puVar24 = plVar23;
      }
    }
LAB_00100b1c:
    uVar20 = (uint)uVar1;
    if ((param_4 != (uint *)0x0) && (lVar22 != 0)) {
      *param_4 = uVar20;
      break;
    }
    uVar1 = uVar1 + 1;
  }
  if (3 < param_2) goto LAB_00100e34;
  if ((int)(&static_pool_size)[uVar21] < *(int *)(&max_pool_size + lVar17)) {
    if (3 < param_2) goto LAB_00100e34;
    if (*(int *)(pool_unbound_feature + uVar21 * 4) == 0) goto LAB_00100ba4;
    bVar9 = false;
    if (lVar22 == 0) goto LAB_00100c10;
LAB_00100bbc:
    if (!bVar9) goto LAB_00100bc4;
  }
  else {
LAB_00100ba4:
    _raw_spin_unlock_irqrestore(&rmnet_mem_lock,uVar12);
    bVar9 = true;
    if (lVar22 != 0) goto LAB_00100bbc;
LAB_00100c10:
    if (3 < param_5) {
LAB_00100e34:
                    /* WARNING: Does not return */
      pcVar11 = (code *)SoftwareBreakpoint(1,0x100e38);
      (*pcVar11)();
    }
    *(int *)(DATARMNETfb2a1a4560 + lVar16) = *(int *)(DATARMNETfb2a1a4560 + lVar16) + 1;
    if (param_2 < 3) {
      uVar10 = tpidr_el1;
      uVar20 = param_1 | 0x60000;
      if (!bVar9) {
        uVar20 = 0xe0a20;
      }
      lVar22 = __alloc_pages(uVar20,uVar19,0,0);
      if (lVar22 != 0) {
        if (!bVar9) {
          plVar14 = (long *)kmalloc_trace(_kfree,0xb20,0x20);
          if (plVar14 != (long *)0x0) {
            if (3 < param_2) goto LAB_00100e34;
            plVar6 = plVar14 + 1;
            plVar23 = &rmnet_mem_pool + uVar19 * 2;
            *(char *)(plVar14 + 3) = (char)param_2;
            iVar18 = (&static_pool_size)[uVar19];
            *plVar14 = lVar22;
            (&static_pool_size)[uVar19] = iVar18 + 1;
            plVar14[1] = (long)plVar6;
            plVar14[2] = (long)plVar6;
            lVar16 = *plVar23;
            uVar19 = __list_add_valid(plVar6,plVar23,lVar16);
            if ((uVar19 & 1) != 0) {
              plVar14[1] = lVar16;
              plVar14[2] = (long)plVar23;
              *plVar23 = (long)plVar6;
              *(long **)(lVar16 + 8) = plVar6;
            }
          }
          piVar3 = (int *)(lVar22 + 0x34);
          Hint_Prefetch(piVar3,2,0,1);
          do {
            cVar7 = '\x01';
            bVar8 = (bool)ExclusiveMonitorPass(piVar3,0x10);
            if (bVar8) {
              *piVar3 = *piVar3 + 1;
              cVar7 = ExclusiveMonitorsStatus();
            }
          } while (cVar7 != '\0');
        }
        if (param_4 != (uint *)0x0) {
          *param_4 = param_2;
        }
      }
      goto LAB_00100bbc;
    }
    if (bVar9) {
      lVar22 = 0;
      if (param_3 == (undefined4 *)0x0) {
        return 0;
      }
      if (param_4 == (uint *)0x0) {
        return 0;
      }
      goto LAB_00100c00;
    }
    uVar10 = tpidr_el1;
    lVar22 = __alloc_pages(uVar10,0xe0a20,uVar19,0,0);
    if (lVar22 != 0) {
      plVar14 = (long *)kmalloc_trace(_kfree,0xb20,0x20);
      if (plVar14 != (long *)0x0) {
        uVar19 = (ulong)(param_2 & 0xff);
        if (3 < (param_2 & 0xff)) goto LAB_00100e34;
        *(char *)(plVar14 + 3) = (char)param_2;
        plVar6 = plVar14 + 1;
        *plVar14 = lVar22;
        plVar23 = &rmnet_mem_pool + uVar19 * 2;
        (&static_pool_size)[uVar19] = (&static_pool_size)[uVar19] + 1;
        plVar14[1] = (long)plVar6;
        plVar14[2] = (long)plVar6;
        lVar16 = *plVar23;
        uVar19 = __list_add_valid(plVar6,plVar23,lVar16);
        if ((uVar19 & 1) != 0) {
          plVar14[1] = lVar16;
          plVar14[2] = (long)plVar23;
          *plVar23 = (long)plVar6;
          *(long **)(lVar16 + 8) = plVar6;
        }
      }
      piVar3 = (int *)(lVar22 + 0x34);
      Hint_Prefetch(piVar3,2,0,1);
      do {
        cVar7 = '\x01';
        bVar9 = (bool)ExclusiveMonitorPass(piVar3,0x10);
        if (bVar9) {
          *piVar3 = *piVar3 + 1;
          cVar7 = ExclusiveMonitorsStatus();
        }
      } while (cVar7 != '\0');
    }
    if (param_4 != (uint *)0x0) {
      *param_4 = param_2;
    }
LAB_00100bc4:
    _raw_spin_unlock_irqrestore(&rmnet_mem_lock,uVar12);
  }
  if ((param_3 != (undefined4 *)0x0 && param_4 != (uint *)0x0) && (lVar22 != 0)) {
    uVar20 = *param_4;
    if (uVar20 == param_2) {
      *param_3 = 0;
      return lVar22;
    }
    if (param_2 < uVar20) {
      uVar15 = 0xfffffffd;
    }
    else {
      if (param_2 <= uVar20) {
        return lVar22;
      }
      uVar15 = 0xfffffffe;
    }
    *param_3 = uVar15;
    return lVar22;
  }
  if (param_3 == (undefined4 *)0x0 || param_4 == (uint *)0x0) {
    return lVar22;
  }
LAB_00100c00:
  *param_3 = 0xffffffff;
  *param_4 = 0;
  return lVar22;
}



//------------------------------------------------------------
// rmnet_mem_put_page_entry @ 00100e78 size=100
// signature: undefined rmnet_mem_put_page_entry(void)
// callers: []
//------------------------------------------------------------

void rmnet_mem_put_page_entry(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  
  if ((*(ulong *)(param_1 + 8) & 1) != 0) {
    param_1 = *(ulong *)(param_1 + 8) - 1;
  }
  piVar1 = (int *)(param_1 + 0x34);
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
  DataMemoryBarrier(2,3);
  if (iVar2 + -1 == 0) {
    __folio_put();
  }
  return;
}



//------------------------------------------------------------
// rmnet_mem_adjust @ 00100f0c size=580
// signature: undefined rmnet_mem_adjust(void)
// callers: [mem_update_pool_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rmnet_mem_adjust(uint param_1,byte param_2)

{
  int *piVar1;
  long *plVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  undefined8 uVar6;
  code *pcVar7;
  undefined8 uVar8;
  long lVar9;
  long *plVar10;
  ulong uVar11;
  ulong uVar12;
  long *plVar13;
  int iVar14;
  
  if ((param_1 < 0x2bd) && (param_2 < 4)) {
    uVar12 = (ulong)param_2;
    iVar14 = param_1 - (&static_pool_size)[uVar12];
    if (iVar14 != 0) {
      uVar8 = _raw_spin_lock_irqsave(&rmnet_mem_lock);
      if (3 < param_2) {
LAB_00101178:
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(1,0x10117c);
        (*pcVar7)();
      }
      if ((uint)(&static_pool_size)[uVar12] < param_1) {
        if (0 < iVar14) {
          plVar13 = &rmnet_mem_pool + uVar12 * 2;
          do {
            uVar6 = tpidr_el1;
            lVar9 = __alloc_pages(uVar6,0xe0a20,param_2,0,0);
            if ((lVar9 != 0) &&
               (plVar10 = (long *)kmalloc_trace(_kfree,0xb20,0x20), plVar10 != (long *)0x0)) {
              if (3 < param_2) goto LAB_00101178;
              iVar3 = (&static_pool_size)[uVar12];
              plVar2 = plVar10 + 1;
              *(byte *)(plVar10 + 3) = param_2;
              *plVar10 = lVar9;
              (&static_pool_size)[uVar12] = iVar3 + 1;
              plVar10[1] = (long)plVar2;
              plVar10[2] = (long)plVar2;
              lVar9 = *plVar13;
              uVar11 = __list_add_valid(plVar2,plVar13,lVar9);
              if ((uVar11 & 1) != 0) {
                plVar10[1] = lVar9;
                plVar10[2] = (long)plVar13;
                *plVar13 = (long)plVar2;
                *(long **)(lVar9 + 8) = plVar2;
              }
            }
            iVar14 = iVar14 + -1;
          } while (iVar14 != 0);
        }
      }
      else {
        if (3 < param_2) goto LAB_00101178;
        plVar13 = (long *)(&rmnet_mem_pool)[uVar12 * 2];
        do {
          if (plVar13 == &rmnet_mem_pool + uVar12 * 2) break;
          plVar10 = (long *)*plVar13;
          uVar11 = __list_del_entry_valid(plVar13);
          if ((uVar11 & 1) != 0) {
            lVar9 = *plVar13;
            plVar2 = (long *)plVar13[1];
            *(long **)(lVar9 + 8) = plVar2;
            *plVar2 = lVar9;
          }
          lVar9 = plVar13[-1];
          *plVar13 = -0x2152ffffffffff00;
          plVar13[1] = -0x2152fffffffffede;
          if ((*(ulong *)(lVar9 + 8) & 1) != 0) {
            lVar9 = *(ulong *)(lVar9 + 8) - 1;
          }
          piVar1 = (int *)(lVar9 + 0x34);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            iVar14 = *piVar1;
            cVar4 = '\x01';
            bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar5) {
              *piVar1 = iVar14 + -1;
              cVar4 = ExclusiveMonitorsStatus();
            }
          } while (cVar4 != '\0');
          DataMemoryBarrier(2,3);
          if (iVar14 + -1 == 0) {
            __folio_put();
          }
          kfree(plVar13 + -1);
          if (3 < param_2) goto LAB_00101178;
          iVar14 = (&static_pool_size)[uVar12];
          (&static_pool_size)[uVar12] = iVar14 - 1U;
          plVar13 = plVar10;
        } while (iVar14 - 1U != param_1);
      }
      _raw_spin_unlock_irqrestore(&rmnet_mem_lock,uVar8);
    }
  }
  return;
}



//------------------------------------------------------------
// mem_update_pool_work @ 00101180 size=220
// signature: undefined mem_update_pool_work(void)
// callers: []
//------------------------------------------------------------

void mem_update_pool_work(void)

{
  long lVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  lVar1 = sp_el0;
  *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 0x200;
  rmnet_mem_adjust(target_static_pool_size,0);
  local_bh_enable();
  *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 0x200;
  rmnet_mem_adjust(DAT_00101bf4,1);
  local_bh_enable();
  *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 0x200;
  rmnet_mem_adjust(DAT_00101bf8,2);
  local_bh_enable();
  *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 0x200;
  rmnet_mem_adjust(DAT_00101bfc,3);
  uVar2 = DAT_00101bfc;
  uVar3 = _raw_spin_lock_irqsave(0x101b20);
  raw_notifier_call_chain(rmnet_mem_notifier,uVar2,0);
  _raw_spin_unlock_irqrestore(0x101b20,uVar3);
  local_bh_enable();
  return;
}



//------------------------------------------------------------
// local_bh_enable @ 0010125c size=40
// signature: undefined local_bh_enable(void)
// callers: [mem_update_pool_work]
//------------------------------------------------------------

void local_bh_enable(void)

{
  __local_bh_enable_ip(local_bh_enable,0x200);
  return;
}



//------------------------------------------------------------
// DATARMNETe85d734d4f @ 00101294 size=256
// signature: undefined DATARMNETe85d734d4f(void)
// callers: [DATARMNET291f036d31, DATARMNET8e48a951e4]
//------------------------------------------------------------

void DATARMNETe85d734d4f(undefined4 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  undefined4 local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = __alloc_skb(0xe94,0xa20,0,0xffffffff);
  if (lVar2 != 0) {
    lVar3 = genlmsg_put(lVar2,0,0,&DATARMNET595b5c3a9e,0,1);
    if (lVar3 != 0) {
      local_3c = param_1;
      iVar1 = nla_put(lVar2,3,4,&local_3c);
      if (iVar1 == 0) {
        *(int *)(lVar3 + -0x14) =
             (*(int *)(lVar2 + 0xd8) + *(int *)(lVar2 + 0xd0)) - ((int)lVar3 + -0x14);
        iVar1 = netlink_unicast(*(undefined8 *)(*(long *)(param_2 + 0x28) + 0x118),lVar2,
                                *(undefined4 *)(param_2 + 4),0x40);
        if (-1 < iVar1) {
          uVar4 = 0;
          goto LAB_00101328;
        }
        goto LAB_00101324;
      }
    }
    kfree(lVar2);
  }
LAB_00101324:
  uVar4 = 0xffffffff;
LAB_00101328:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// rmnet_mem_nl_register @ 00101398 size=36
// signature: undefined rmnet_mem_nl_register(void)
// callers: [init_module]
//------------------------------------------------------------

void rmnet_mem_nl_register(void)

{
  genl_register_family(&DATARMNET595b5c3a9e);
  return;
}



//------------------------------------------------------------
// rmnet_mem_nl_unregister @ 001013c0 size=36
// signature: undefined rmnet_mem_nl_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void rmnet_mem_nl_unregister(void)

{
  genl_unregister_family(&DATARMNET595b5c3a9e);
  return;
}



//------------------------------------------------------------
// DATARMNET291f036d31 @ 001013e8 size=164
// signature: undefined DATARMNET291f036d31(void)
// callers: []
//------------------------------------------------------------

void DATARMNET291f036d31(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = 0;
  lVar2 = *(long *)(*(long *)(param_2 + 0x20) + 8);
  if (lVar2 == 0) {
    uVar1 = 0x191;
  }
  else {
    nla_memcpy(&local_30,lVar2,8);
    lVar2 = __alloc_skb(0xe80,0xcc0,0,0xffffffff);
    if (lVar2 == 0) {
      uVar1 = 0xfffffff4;
      goto LAB_00101460;
    }
    uVar1 = 400;
  }
  DATARMNETe85d734d4f(uVar1,param_2);
  uVar1 = 0;
LAB_00101460:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET8e48a951e4 @ 00101490 size=404
// signature: undefined DATARMNET8e48a951e4(void)
// callers: []
//------------------------------------------------------------

void DATARMNET8e48a951e4(undefined8 param_1,long param_2)

{
  bool bVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 local_40;
  undefined8 local_38;
  uint local_30;
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  local_30 = 0;
  local_40 = 0;
  local_38 = 0;
  lVar5 = *(long *)(*(long *)(param_2 + 0x20) + 0x10);
  if (lVar5 == 0) {
    uVar4 = 0x191;
  }
  else {
    iVar3 = nla_memcpy(&local_40,lVar5,0x14);
    if (iVar3 < 1) {
      if ((local_30 & 1) == 0) goto LAB_001014f8;
LAB_001014e4:
      if ((int)local_40 == static_pool_size) goto LAB_001014f8;
      bVar1 = true;
      target_static_pool_size = (int)local_40;
      uVar4 = local_40;
      uVar2 = local_38;
    }
    else {
      _printk(&DAT_00102035,"DATARMNET8e48a951e4",local_30);
      if ((local_30 & 1) != 0) goto LAB_001014e4;
LAB_001014f8:
      bVar1 = false;
      uVar4 = local_40;
      uVar2 = local_38;
    }
    if (((local_30 >> 1 & 1) != 0) &&
       (local_40._4_4_ = (int)((ulong)uVar4 >> 0x20), local_40._4_4_ != DAT_00101b2c)) {
      bVar1 = true;
      DAT_00101bf4 = local_40._4_4_;
    }
    if (((local_30 >> 2 & 1) != 0) && (local_38._0_4_ = (int)uVar2, (int)local_38 != DAT_00101b30))
    {
      bVar1 = true;
      DAT_00101bf8 = (int)local_38;
    }
    if (((local_30 >> 3 & 1) != 0) &&
       (local_38._4_4_ = (int)((ulong)uVar2 >> 0x20), local_38._4_4_ != DAT_00101b34)) {
      bVar1 = true;
      DAT_00101bfc = local_38._4_4_;
    }
    local_40 = uVar4;
    local_38 = uVar2;
    if ((bVar1) && (mem_wq != 0)) {
      queue_work_on(0x20,mem_wq,&pool_adjust_work);
    }
    lVar5 = __alloc_skb(0xe80,0xcc0,0,0xffffffff);
    if (lVar5 == 0) {
      uVar4 = 0xfffffff4;
      goto LAB_001015d4;
    }
    uVar4 = 400;
  }
  DATARMNETe85d734d4f(uVar4,param_2);
  uVar4 = 0;
LAB_001015d4:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001016c8 size=200
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined *puVar4;
  long lVar5;
  
  _printk(&DAT_00101fd8,"rmnet_mem_module_init");
  lVar5 = 0;
  do {
    lVar2 = (long)&rmnet_mem_pool + lVar5;
    lVar1 = lVar5 + 0x10;
    *(long *)lVar2 = lVar2;
    *(long *)((long)&DAT_00101b40 + lVar5) = lVar2;
    lVar5 = lVar1;
  } while (lVar1 != 0x40);
  mem_wq = alloc_workqueue("mem_wq",0x10,0);
  if (mem_wq == 0) {
    puVar4 = &DAT_00101ffb;
  }
  else {
    pool_adjust_work = 0xfffffffe0;
    DAT_00101bc8 = &DAT_00101bc8;
    DAT_00101bd0 = &DAT_00101bc8;
    DAT_00101bd8 = mem_update_pool_work;
    uVar3 = rmnet_mem_nl_register();
    if ((int)uVar3 == 0) {
      return uVar3;
    }
    puVar4 = &DAT_0010205e;
  }
  _printk(puVar4,"rmnet_mem_module_init");
  return 0xfffffff4;
}



//------------------------------------------------------------
// cleanup_module @ 00101794 size=84
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  rmnet_mem_nl_unregister();
  if (mem_wq != 0) {
    cancel_work_sync(&pool_adjust_work);
    drain_workqueue(mem_wq);
    destroy_workqueue(mem_wq);
    mem_wq = 0;
  }
  rmnet_mem_free_all();
  return;
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00103008 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [rmnet_mem_free_all, rmnet_mem_get_pages_entry, rmnet_mem_adjust, rmnet_mem_register_notifier, mem_update_pool_work, rmnet_mem_mode_notify, rmnet_mem_unregister_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// raw_notifier_call_chain @ 00103010 size=1
// signature: undefined raw_notifier_call_chain(void)
// callers: [mem_update_pool_work, rmnet_mem_mode_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void raw_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00103018 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [rmnet_mem_free_all, rmnet_mem_get_pages_entry, rmnet_mem_adjust, rmnet_mem_register_notifier, mem_update_pool_work, rmnet_mem_mode_notify, rmnet_mem_unregister_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// raw_notifier_chain_register @ 00103020 size=1
// signature: undefined raw_notifier_chain_register(void)
// callers: [rmnet_mem_register_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void raw_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// raw_notifier_chain_unregister @ 00103028 size=1
// signature: undefined raw_notifier_chain_unregister(void)
// callers: [rmnet_mem_unregister_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void raw_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00103038 size=1
// signature: undefined kmalloc_trace(void)
// callers: [rmnet_mem_get_pages_entry, rmnet_mem_adjust, rmnet_mem_add_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00103040 size=1
// signature: undefined __list_add_valid(void)
// callers: [rmnet_mem_get_pages_entry, rmnet_mem_adjust, rmnet_mem_add_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00103048 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [rmnet_mem_free_all, rmnet_mem_get_pages_entry, rmnet_mem_adjust]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __folio_put @ 00103058 size=1
// signature: undefined __folio_put(void)
// callers: [rmnet_mem_free_all, rmnet_mem_adjust, rmnet_mem_put_page_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __folio_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00103060 size=1
// signature: undefined kfree(void)
// callers: [rmnet_mem_free_all, rmnet_mem_adjust, DATARMNETe85d734d4f]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_pages @ 00103070 size=1
// signature: undefined __alloc_pages(void)
// callers: [rmnet_mem_get_pages_entry, rmnet_mem_adjust]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103078 size=1
// signature: undefined _printk(void)
// callers: [DATARMNET8e48a951e4, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00103080 size=1
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
// cancel_work_sync @ 00103088 size=1
// signature: undefined cancel_work_sync(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drain_workqueue @ 00103090 size=1
// signature: undefined drain_workqueue(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drain_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 00103098 size=1
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
// __local_bh_enable_ip @ 001030a0 size=1
// signature: undefined __local_bh_enable_ip(void)
// callers: [local_bh_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __local_bh_enable_ip(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_skb @ 001030b8 size=1
// signature: undefined __alloc_skb(void)
// callers: [DATARMNET291f036d31, DATARMNETe85d734d4f, DATARMNET8e48a951e4]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genlmsg_put @ 001030c0 size=1
// signature: undefined genlmsg_put(void)
// callers: [DATARMNETe85d734d4f]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genlmsg_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nla_put @ 001030c8 size=1
// signature: undefined nla_put(void)
// callers: [DATARMNETe85d734d4f]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nla_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netlink_unicast @ 001030d0 size=1
// signature: undefined netlink_unicast(void)
// callers: [DATARMNETe85d734d4f]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netlink_unicast(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030d8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [DATARMNET291f036d31, DATARMNETe85d734d4f, DATARMNET8e48a951e4]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genl_register_family @ 001030e0 size=1
// signature: undefined genl_register_family(void)
// callers: [rmnet_mem_nl_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genl_register_family(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genl_unregister_family @ 001030e8 size=1
// signature: undefined genl_unregister_family(void)
// callers: [rmnet_mem_nl_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genl_unregister_family(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nla_memcpy @ 001030f0 size=1
// signature: undefined nla_memcpy(void)
// callers: [DATARMNET291f036d31, DATARMNET8e48a951e4]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nla_memcpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001030f8 size=1
// signature: undefined queue_work_on(void)
// callers: [DATARMNET8e48a951e4]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



