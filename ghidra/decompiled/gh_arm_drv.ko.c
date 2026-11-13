// Decompiled by Ghidra 12.2
// Program: gh_arm_drv.ko
// Image base: 00100000

//------------------------------------------------------------
// gh_get_irq @ 001001b4 size=176
// signature: undefined gh_get_irq(void)
// callers: []
//------------------------------------------------------------

void gh_get_irq(int param_1,undefined4 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 local_88;
  undefined8 uStack_80;
  int local_78;
  undefined4 uStack_74;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_70 = 0;
  if (param_1 - 0x3fbU < 0xfffffc25) {
    _printk(&DAT_0010051f,"gh_get_irq",param_1);
  }
  local_78 = param_1 + -0x20;
  uStack_80 = 3;
  local_88 = param_3;
  uStack_74 = param_2;
  irq_create_fwspec_mapping(&local_88);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gh_get_virq @ 00100268 size=64
// signature: undefined gh_get_virq(void)
// callers: []
//------------------------------------------------------------

int gh_get_virq(int param_1)

{
  int iVar1;
  
  iVar1 = idr_alloc(&gh_rm_free_virq_idr,&gh_rm_free_virq_idr,param_1 + -0x20,0x3fb,0xcc0);
  if (-1 < iVar1) {
    iVar1 = iVar1 + 0x20;
  }
  return iVar1;
}



//------------------------------------------------------------
// gh_put_virq @ 001002ac size=88
// signature: undefined gh_put_virq(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_put_virq(int param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = idr_find(&gh_rm_free_virq_idr,(long)(param_1 + -0x20));
  if (lVar1 == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    idr_remove(&gh_rm_free_virq_idr,(long)(param_1 + -0x20));
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// gh_put_irq @ 00100308 size=120
// signature: undefined gh_put_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_put_irq(int param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  if ((0 < param_1) && (lVar2 = irq_get_irq_data(), lVar2 != 0)) {
    iVar1 = *(int *)(lVar2 + 8);
    irq_dispose_mapping(param_1);
    lVar3 = (long)(iVar1 + -0x20);
    lVar2 = idr_find(&gh_rm_free_virq_idr,lVar3);
    if (lVar2 != 0) {
      idr_remove(&gh_rm_free_virq_idr,lVar3);
      return 0;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// gh_arch_validate_vm_exited_notif @ 00100384 size=104
// signature: undefined gh_arch_validate_vm_exited_notif(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_arch_validate_vm_exited_notif(long param_1,long param_2)

{
  undefined8 uVar1;
  short sVar2;
  
  sVar2 = *(short *)(param_2 + 2);
  if ((sVar2 == 1) || (sVar2 == 2)) {
LAB_001003bc:
    uVar1 = 0;
    *(short *)(param_2 + 2) = sVar2;
  }
  else {
    if (sVar2 == 3) {
      if (param_1 == 0xc) {
        sVar2 = 2;
        goto LAB_001003bc;
      }
      _printk(&DAT_0010057f,"gh_arch_validate_vm_exited_notif",param_1);
    }
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// init_module @ 001003f0 size=8
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 001003fc size=4
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  return;
}



//------------------------------------------------------------
// irq_create_fwspec_mapping @ 00101000 size=1
// signature: undefined irq_create_fwspec_mapping(void)
// callers: [gh_get_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_create_fwspec_mapping(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00101008 size=1
// signature: undefined _printk(void)
// callers: [gh_get_irq, gh_arch_validate_vm_exited_notif]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00101010 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [gh_get_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_alloc @ 00101018 size=1
// signature: undefined idr_alloc(void)
// callers: [gh_get_virq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_find @ 00101020 size=1
// signature: undefined idr_find(void)
// callers: [gh_put_virq, gh_put_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_remove @ 00101028 size=1
// signature: undefined idr_remove(void)
// callers: [gh_put_virq, gh_put_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_get_irq_data @ 00101030 size=1
// signature: undefined irq_get_irq_data(void)
// callers: [gh_put_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_get_irq_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_dispose_mapping @ 00101038 size=1
// signature: undefined irq_dispose_mapping(void)
// callers: [gh_put_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_dispose_mapping(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



