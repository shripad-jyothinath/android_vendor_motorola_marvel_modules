// Decompiled by Ghidra 12.2
// Program: gh_cpusys_vm_mem_access.ko
// Image base: 00100000

//------------------------------------------------------------
// gh_cpusys_vm_get_share_mem_info @ 0010017c size=96
// signature: undefined gh_cpusys_vm_get_share_mem_info(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_cpusys_vm_get_share_mem_info(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  
  lVar4 = gh_cpusys_vm_drv_data;
  uVar5 = 0xffffffea;
  if ((param_1 != (undefined8 *)0x0) && (gh_cpusys_vm_drv_data != 0)) {
    if (*(char *)(gh_cpusys_vm_drv_data + 0x8c) == '\0') {
      return 0xfffffffa;
    }
    uVar2 = *(undefined8 *)(gh_cpusys_vm_drv_data + 0x20);
    uVar5 = 0;
    uVar1 = *(undefined8 *)(gh_cpusys_vm_drv_data + 8);
    uVar3 = *(undefined8 *)(gh_cpusys_vm_drv_data + 0x10);
    param_1[2] = *(undefined8 *)(gh_cpusys_vm_drv_data + 0x18);
    param_1[3] = uVar2;
    *param_1 = uVar1;
    param_1[1] = uVar3;
    uVar2 = *(undefined8 *)(lVar4 + 0x40);
    uVar1 = *(undefined8 *)(lVar4 + 0x28);
    uVar3 = *(undefined8 *)(lVar4 + 0x30);
    param_1[6] = *(undefined8 *)(lVar4 + 0x38);
    param_1[7] = uVar2;
    param_1[4] = uVar1;
    param_1[5] = uVar3;
    uVar2 = *(undefined8 *)(lVar4 + 0x60);
    uVar1 = *(undefined8 *)(lVar4 + 0x48);
    uVar3 = *(undefined8 *)(lVar4 + 0x50);
    param_1[10] = *(undefined8 *)(lVar4 + 0x58);
    param_1[0xb] = uVar2;
    param_1[8] = uVar1;
    param_1[9] = uVar3;
  }
  return uVar5;
}



//------------------------------------------------------------
// gh_cpusys_vm_mem_access_probe @ 001001e0 size=456
// signature: undefined gh_cpusys_vm_mem_access_probe(void)
// callers: []
//------------------------------------------------------------

void gh_cpusys_vm_mem_access_probe(long param_1)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  ulong uVar4;
  undefined8 uVar5;
  long local_88 [11];
  
  lVar1 = sp_el0;
  local_88[10] = *(long *)(lVar1 + 0x638);
  plVar3 = (long *)devm_kmalloc(param_1 + 0x10,0x90,0xdc0);
  if (plVar3 == (long *)0x0) {
    uVar4 = 0xfffffff4;
  }
  else {
    *(long **)(param_1 + 0xa8) = plVar3;
    uVar5 = *(undefined8 *)(param_1 + 0x2f8);
    gh_cpusys_vm_drv_data = plVar3;
    *plVar3 = param_1 + 0x10;
    iVar2 = of_property_read_variable_u32_array(uVar5,"gunyah-label",plVar3 + 0xd,1,0);
    if (iVar2 < 0) {
      _dev_err(*plVar3,"failed to find label info %d\n",iVar2);
    }
    else {
      local_88[8] = 0;
      local_88[9] = 0;
      local_88[6] = 0;
      local_88[7] = 0;
      local_88[4] = 0;
      local_88[5] = 0;
      local_88[2] = 0;
      local_88[3] = 0;
      local_88[0] = 0;
      local_88[1] = 0;
      iVar2 = __of_parse_phandle_with_args(uVar5,"shared-buffer",0,0,0,local_88);
      if ((iVar2 == 0) && (local_88[0] != 0)) {
        iVar2 = of_address_to_resource(local_88[0],0,plVar3 + 1);
        if (iVar2 == 0) {
          iVar2 = of_property_read_variable_u32_array
                            (uVar5,"peer-name",(undefined4 *)((long)plVar3 + 0x6c),1,0);
          if (iVar2 < 0) {
            *(undefined4 *)((long)plVar3 + 0x6c) = 0;
          }
          plVar3[0xe] = (long)gh_cpusys_vm_mem_rm_cb;
          *(undefined4 *)(plVar3 + 0x10) = 0x7fffffff;
          uVar4 = gh_rm_register_notifier();
          if ((int)uVar4 == 0) goto LAB_00100378;
          _dev_err(*plVar3,"fail to register notifier ret:%d\n",uVar4 & 0xffffffff);
          iVar2 = -0x205;
        }
        else {
          _dev_err(*plVar3,"of_address_to_resource failed %d\n",iVar2);
          iVar2 = -0x16;
        }
      }
      else {
        _dev_err(*plVar3,"failed to read shared-buffer info\n");
        iVar2 = -0xc;
      }
    }
    _dev_err(*plVar3,"fail to init cpusys vm mem access:%d\n",iVar2);
    uVar4 = 0;
  }
LAB_00100378:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_88[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// gh_cpusys_vm_mem_access_remove @ 001003ac size=48
// signature: undefined gh_cpusys_vm_mem_access_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_cpusys_vm_mem_access_remove(long param_1)

{
  gh_cpusys_vm_drv_data = 0;
  gh_rm_unregister_notifier(*(long *)(param_1 + 0xa8) + 0x70);
  return 0;
}



//------------------------------------------------------------
// gh_cpusys_vm_mem_rm_cb @ 001003e0 size=240
// signature: undefined gh_cpusys_vm_mem_rm_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_cpusys_vm_mem_rm_cb(long param_1,long param_2,short *param_3)

{
  long lVar1;
  int iVar2;
  undefined2 local_30 [2];
  short local_2c [2];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  local_30[0] = 0;
  if (param_2 == 0x56100008) {
    if (((((char)param_3[2] == '\v') || ((char)param_3[2] == '\x02')) &&
        (iVar2 = ghd_rm_get_vmid(*(undefined4 *)(param_1 + -4),local_2c), iVar2 == 0)) &&
       (((iVar2 = ghd_rm_get_vmid(1,local_30), iVar2 == 0 && (local_2c[0] == *param_3)) &&
        ((char)param_3[2] == '\x02')))) {
      iVar2 = gh_cpusys_vm_share_mem((undefined8 *)(param_1 + -0x70),local_30[0]);
      if (iVar2 == 0) {
        *(undefined1 *)(param_1 + 0x1c) = 1;
      }
      else {
        _dev_err(*(undefined8 *)(param_1 + -0x70),"failed to share memory\n");
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// gh_cpusys_vm_share_mem @ 001004d0 size=500
// signature: undefined gh_cpusys_vm_share_mem(void)
// callers: [gh_cpusys_vm_mem_rm_cb]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int gh_cpusys_vm_share_mem(undefined8 *param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  long lVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  ulong local_70;
  ulong uStack_68;
  uint local_60 [3];
  undefined4 uStack_54;
  uint local_50 [2];
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_60[0] = (uint)param_2 & 0xffff;
  local_60[2] = (uint)param_3 & 0xffff;
  local_50[1] = 7;
  uStack_68 = 1L << (param_2 & 0x3f);
  local_60[1] = 6;
  local_70 = 1L << (param_3 & 0x3f) | uStack_68;
  uStack_54 = 6;
  local_50[0] = local_60[0];
  iVar4 = qcom_scm_assign_mem(param_1[1],(param_1[2] - param_1[1]) + 1,&uStack_68,local_60,2);
  if (iVar4 == 0) {
    puVar5 = (undefined4 *)kmalloc_trace(_DAT_00102090,0xdc0,0xc);
    if (puVar5 == (undefined4 *)0x0) {
      iVar4 = -0xc;
    }
    else {
      puVar6 = (undefined2 *)kmalloc_trace(_DAT_00102090,0xdc0,0x14);
      if (puVar6 == (undefined2 *)0x0) {
        kfree(puVar5);
        iVar4 = -0xc;
      }
      else {
        lVar1 = param_1[1];
        lVar2 = param_1[2];
        *puVar5 = 2;
        *(undefined1 *)((long)puVar5 + 6) = 6;
        uVar3 = *(undefined4 *)(param_1 + 0xd);
        *(undefined1 *)((long)puVar5 + 10) = 6;
        *puVar6 = 1;
        *(long *)(puVar6 + 2) = lVar1;
        *(short *)(puVar5 + 1) = (short)param_2;
        *(long *)(puVar6 + 6) = (lVar2 - lVar1) + 1;
        *(short *)(puVar5 + 2) = (short)param_3;
        iVar4 = ghd_rm_mem_share(0,0,uVar3,puVar5,puVar6,0,param_1 + 0x11);
        if (iVar4 != 0) {
          _dev_err(*param_1,"%s: gh_rm_mem_share failed addr=%x size=%u err=%d\n",
                   "gh_cpusys_vm_share_mem",param_1[1],(param_1[2] - param_1[1]) + 1,iVar4);
          qcom_scm_assign_mem(param_1[1],(param_1[2] - param_1[1]) + 1,&local_70,local_50,1);
        }
        kfree(puVar5);
        kfree(puVar6);
      }
    }
  }
  else {
    _dev_err(*param_1,"%s: qcom_scm_assign_mem failed addr=%x size=%u err=%d\n",
             "gh_cpusys_vm_share_mem",param_1[1],(param_1[2] - param_1[1]) + 1,iVar4);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// init_module @ 001006ec size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&gh_cpusys_vm_mem_access_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010071c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&gh_cpusys_vm_mem_access_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00102000 size=1
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
// platform_driver_unregister @ 00102008 size=1
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
// devm_kmalloc @ 00102010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [gh_cpusys_vm_mem_access_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102018 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [gh_cpusys_vm_mem_access_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00102020 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [gh_cpusys_vm_mem_access_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 00102028 size=1
// signature: undefined of_address_to_resource(void)
// callers: [gh_cpusys_vm_mem_access_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_register_notifier @ 00102030 size=1
// signature: undefined gh_rm_register_notifier(void)
// callers: [gh_cpusys_vm_mem_access_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_register_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102038 size=1
// signature: undefined _dev_err(void)
// callers: [gh_cpusys_vm_share_mem, gh_cpusys_vm_mem_access_probe, gh_cpusys_vm_mem_rm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102040 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [gh_cpusys_vm_share_mem, gh_cpusys_vm_mem_access_probe, gh_cpusys_vm_mem_rm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_unregister_notifier @ 00102048 size=1
// signature: undefined gh_rm_unregister_notifier(void)
// callers: [gh_cpusys_vm_mem_access_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_unregister_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_get_vmid @ 00102050 size=1
// signature: undefined ghd_rm_get_vmid(void)
// callers: [gh_cpusys_vm_mem_rm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_get_vmid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_assign_mem @ 00102058 size=1
// signature: undefined qcom_scm_assign_mem(void)
// callers: [gh_cpusys_vm_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_assign_mem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00102068 size=1
// signature: undefined kmalloc_trace(void)
// callers: [gh_cpusys_vm_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_mem_share @ 00102070 size=1
// signature: undefined ghd_rm_mem_share(void)
// callers: [gh_cpusys_vm_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_mem_share(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102078 size=1
// signature: undefined kfree(void)
// callers: [gh_cpusys_vm_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



