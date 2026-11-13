// Decompiled by Ghidra 12.2
// Program: gunyah_qcom.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_scm_gh_rm_pre_mem_share @ 0010014c size=552
// signature: undefined qcom_scm_gh_rm_pre_mem_share(void)
// callers: []
//------------------------------------------------------------

int qcom_scm_gh_rm_pre_mem_share(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  byte bVar2;
  ushort uVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  ulong uVar8;
  uint uVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  ulong local_50;
  long local_48;
  
  lVar10 = sp_el0;
  local_48 = *(long *)(lVar10 + 0x638);
  local_50 = 0;
  if ((*(ulong *)(param_2 + 8) >> 0x3d == 0) &&
     (puVar7 = (undefined4 *)__kmalloc(*(ulong *)(param_2 + 8) << 3,0xdc0),
     puVar7 != (undefined4 *)0x0)) {
    if (*(long *)(param_2 + 8) != 0) {
      uVar13 = *(ulong *)(param_2 + 8);
      lVar10 = *(long *)(param_2 + 0x10);
      uVar8 = 0;
      do {
        uVar9 = (uint)*(ushort *)(lVar10 + uVar8 * 4);
        if (0x3f < uVar9) {
          uVar9 = 0x3a;
        }
        puVar7[uVar8 * 2] = uVar9;
        bVar2 = *(byte *)(lVar10 + uVar8 * 4 + 2);
        if ((bVar2 & 1) != 0) {
          lVar11 = *(long *)(param_2 + 0x10);
          puVar7[uVar8 * 2 + 1] = puVar7[uVar8 * 2 + 1] | 1;
          bVar2 = *(byte *)(lVar11 + uVar8 * 4 + 2);
        }
        if ((bVar2 >> 1 & 1) != 0) {
          lVar11 = *(long *)(param_2 + 0x10);
          puVar7[uVar8 * 2 + 1] = puVar7[uVar8 * 2 + 1] | 2;
          bVar2 = *(byte *)(lVar11 + uVar8 * 4 + 2);
        }
        if ((bVar2 >> 2 & 1) != 0) {
          puVar7[uVar8 * 2 + 1] = puVar7[uVar8 * 2 + 1] | 4;
        }
        uVar8 = (ulong)((int)uVar8 + 1);
      } while (uVar8 < uVar13);
    }
    if (*(long *)(param_2 + 0x18) != 0) {
      uVar13 = 0;
LAB_00100258:
      local_50 = 8;
      puVar1 = (undefined8 *)(*(long *)(param_2 + 0x20) + uVar13 * 0x10);
      iVar5 = qcom_scm_assign_mem(*puVar1,puVar1[1],&local_50,puVar7,*(undefined4 *)(param_2 + 8));
      uVar9 = (uint)uVar13;
      if (iVar5 == 0) goto code_r0x0010027c;
      if (*(ulong *)(param_2 + 8) == 0) {
        uVar13 = 0;
      }
      else {
        uVar8 = 0;
        uVar13 = 0;
        do {
          lVar10 = uVar8 * 4;
          uVar8 = (ulong)((int)uVar8 + 1);
          uVar3 = *(ushort *)(*(long *)(param_2 + 0x10) + lVar10);
          uVar12 = 1L << ((ulong)uVar3 & 0x3f);
          if (0x3f < uVar3) {
            uVar12 = 0x400000000000000;
          }
          uVar13 = uVar12 | uVar13;
        } while (uVar8 < *(ulong *)(param_2 + 8));
      }
      *puVar7 = 3;
      while (uVar9 = uVar9 - 1, -1 < (int)uVar9) {
        puVar1 = (undefined8 *)(*(long *)(param_2 + 0x20) + (ulong)uVar9 * 0x10);
        local_50 = uVar13;
        iVar6 = qcom_scm_assign_mem(*puVar1,puVar1[1],&local_50,puVar7,1);
        if (iVar6 != 0) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x800,0x100370);
          (*pcVar4)();
        }
      }
      goto LAB_00100294;
    }
LAB_00100290:
    iVar5 = 0;
LAB_00100294:
    kfree(puVar7);
  }
  else {
    iVar5 = -0xc;
  }
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
code_r0x0010027c:
  uVar13 = (ulong)(int)(uVar9 + 1);
  if (*(ulong *)(param_2 + 0x18) <= uVar13) goto LAB_00100290;
  goto LAB_00100258;
}



//------------------------------------------------------------
// qcom_scm_gh_rm_post_mem_reclaim @ 00100394 size=268
// signature: undefined qcom_scm_gh_rm_post_mem_reclaim(void)
// callers: []
//------------------------------------------------------------

undefined4 qcom_scm_gh_rm_post_mem_reclaim(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  ushort uVar2;
  code *pcVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  ulong local_48 [3];
  
  lVar6 = sp_el0;
  local_48[2] = *(long *)(lVar6 + 0x638);
  local_48[1] = 0x700000003;
  if (*(ulong *)(param_2 + 8) == 0) {
    uVar8 = 0;
    lVar6 = *(long *)(param_2 + 0x18);
  }
  else {
    uVar5 = 0;
    uVar8 = 0;
    do {
      lVar6 = uVar5 * 4;
      uVar5 = (ulong)((int)uVar5 + 1);
      uVar2 = *(ushort *)(*(long *)(param_2 + 0x10) + lVar6);
      uVar7 = 1L << ((ulong)uVar2 & 0x3f);
      if (0x3f < uVar2) {
        uVar7 = 0x400000000000000;
      }
      uVar8 = uVar7 | uVar8;
    } while (uVar5 < *(ulong *)(param_2 + 8));
    lVar6 = *(long *)(param_2 + 0x18);
  }
  if (lVar6 != 0) {
    uVar5 = 0;
    do {
      puVar1 = (undefined8 *)(*(long *)(param_2 + 0x20) + uVar5 * 0x10);
      local_48[0] = uVar8;
      iVar4 = qcom_scm_assign_mem(*puVar1,puVar1[1],local_48,local_48 + 1,1);
      if (iVar4 != 0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x10045c);
        (*pcVar3)();
      }
      uVar5 = (ulong)((int)uVar5 + 1);
    } while (uVar5 < *(ulong *)(param_2 + 0x18));
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48[2]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// qcom_scm_gh_pin_pages @ 001004b4 size=112
// signature: undefined qcom_scm_gh_pin_pages(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_scm_gh_pin_pages(ulong param_1,long param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  long lVar5;
  
  if (param_2 != 0) {
    lVar4 = (param_1 >> 6 & 0x3ffffffffffffc0) + (_memstart_addr >> 0xc) * -0x40 + -0x200000000;
    do {
      lVar5 = lVar4;
      if ((*(ulong *)(lVar4 + 8) & 1) != 0) {
        lVar5 = *(ulong *)(lVar4 + 8) - 1;
      }
      piVar1 = (int *)(lVar5 + 0x34);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar3) {
          *piVar1 = *piVar1 + 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      lVar4 = lVar4 + 0x40;
      param_2 = param_2 + -0x1000;
    } while (param_2 != 0);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00100530 size=228
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined4 extraout_w1;
  undefined4 uVar5;
  long lVar6;
  
  lVar6 = sp_el0;
  lVar6 = *(long *)(lVar6 + 0x638);
  iVar2 = arm_smccc_1_1_get_conduit();
  uVar5 = extraout_w1;
  if (iVar2 == 1) {
    uVar3 = 0x86003f01;
    CallSecureMonitor(0);
  }
  else if (iVar2 == 2) {
    uVar3 = 0x86003f01;
    CallHyperVisor(0);
  }
  else {
    uVar5 = 0;
    param_3 = 0;
    param_4 = 0;
    uVar3 = 0xffffffff;
  }
  if (CONCAT44(uVar5,uVar3) == 0x1b57370bbd54bd19 &&
      CONCAT44(param_4,param_3) == -0x1962acab649f906c) {
    uVar4 = gh_rm_register_platform_ops(&qcom_scm_gh_rm_platform_ops);
  }
  else {
    uVar4 = 0xffffffed;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != lVar6) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100620 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  gh_rm_unregister_platform_ops(&qcom_scm_gh_rm_platform_ops);
  return;
}



//------------------------------------------------------------
// arm_smccc_1_1_get_conduit @ 00101000 size=1
// signature: undefined arm_smccc_1_1_get_conduit(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void arm_smccc_1_1_get_conduit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arm_smccc_sve_check @ 00101008 size=1
// signature: undefined __arm_smccc_sve_check(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arm_smccc_sve_check(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_register_platform_ops @ 00101010 size=1
// signature: undefined gh_rm_register_platform_ops(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_register_platform_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00101018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_scm_gh_rm_pre_mem_share, init_module, qcom_scm_gh_rm_post_mem_reclaim]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_unregister_platform_ops @ 00101020 size=1
// signature: undefined gh_rm_unregister_platform_ops(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_unregister_platform_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00101028 size=1
// signature: undefined __kmalloc(void)
// callers: [qcom_scm_gh_rm_pre_mem_share]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_assign_mem @ 00101030 size=1
// signature: undefined qcom_scm_assign_mem(void)
// callers: [qcom_scm_gh_rm_pre_mem_share, qcom_scm_gh_rm_post_mem_reclaim]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_assign_mem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00101038 size=1
// signature: undefined kfree(void)
// callers: [qcom_scm_gh_rm_pre_mem_share]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



