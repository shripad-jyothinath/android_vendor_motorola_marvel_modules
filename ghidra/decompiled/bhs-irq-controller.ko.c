// Decompiled by Ghidra 12.2
// Program: bhs-irq-controller.ko
// Image base: 00100000

//------------------------------------------------------------
// bhs_ipcc_irqs_store @ 001000d4 size=440
// signature: undefined bhs_ipcc_irqs_store(void)
// callers: []
//------------------------------------------------------------

long bhs_ipcc_irqs_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  uint local_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_4c = 0;
  iVar2 = kstrtoint(param_3,10,&local_4c);
  if (iVar2 == 0) {
    if (local_4c < 2) {
      mutex_lock(bhs_irq_mutex);
      if (local_4c == 1) {
        if (0 < smp2p_adsp_irq) {
          disable_irq_nosync();
        }
        if (0 < smp2p_wpss_irq) {
          disable_irq_nosync();
        }
        if (0 < smp2p_modem_irq) {
          disable_irq_nosync();
        }
        if (0 < smp2p_cdsp_irq) {
          disable_irq_nosync();
        }
        if (0 < glink_modem_irq) {
          disable_irq_nosync(glink_modem_irq);
        }
        puVar3 = &DAT_00100709;
      }
      else {
        if (0 < smp2p_adsp_irq) {
          enable_irq();
        }
        if (0 < smp2p_wpss_irq) {
          enable_irq();
        }
        if (0 < smp2p_modem_irq) {
          enable_irq();
        }
        if (0 < smp2p_cdsp_irq) {
          enable_irq();
        }
        if (0 < glink_modem_irq) {
          enable_irq(glink_modem_irq);
        }
        puVar3 = &DAT_00100674;
      }
      _printk(puVar3,smp2p_adsp_irq,smp2p_wpss_irq,smp2p_modem_irq,smp2p_cdsp_irq,glink_modem_irq);
      mutex_unlock(bhs_irq_mutex);
    }
    else {
      param_4 = -0x16;
    }
  }
  else {
    param_4 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// init_module @ 00100290 size=644
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int init_module(void)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  int *piVar5;
  int local_5c;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_5c = 0;
  lVar3 = of_find_compatible_node(0,0,"qcom,smp2p");
  if (lVar3 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    do {
      iVar1 = of_property_read_variable_u32_array(lVar3,"qcom,remote-pid",&local_5c,1,0);
      if ((-1 < iVar1) && (iVar1 = of_irq_get(lVar3,0), 0 < iVar1)) {
        if (local_5c < 5) {
          if (local_5c == 1) {
            piVar5 = &smp2p_modem_irq;
          }
          else {
            if (local_5c != 2) goto LAB_00100390;
            piVar5 = &smp2p_adsp_irq;
          }
        }
        else if (local_5c == 5) {
          piVar5 = &smp2p_cdsp_irq;
        }
        else {
          if (local_5c != 0xd) goto LAB_00100390;
          piVar5 = &smp2p_wpss_irq;
        }
        iVar2 = iVar2 + 1;
        *piVar5 = iVar1;
      }
LAB_00100390:
      lVar3 = of_find_compatible_node(lVar3,0,"qcom,smp2p");
    } while (lVar3 != 0);
  }
  lVar3 = of_find_compatible_node(0,0,"qcom,volcano-modem-pas");
  if (lVar3 != 0) {
    do {
      lVar4 = of_get_child_by_name(lVar3,"glink-edge");
      if (lVar4 != 0) {
        iVar1 = of_property_read_variable_u32_array(lVar4,"qcom,remote-pid",&local_5c,1,0);
        if ((-1 < iVar1) && (local_5c == 1)) {
          iVar1 = of_irq_get(lVar4,0);
          if (0 < iVar1) {
            iVar2 = iVar2 + 1;
            glink_modem_irq = iVar1;
          }
        }
      }
      lVar3 = of_find_compatible_node(lVar3,0,"qcom,volcano-modem-pas");
    } while (lVar3 != 0);
  }
  if (iVar2 < 1) {
    _printk(&DAT_001006db);
    iVar2 = -0x13;
  }
  else {
    irq_kobj = kobject_create_and_add("bhs_irq_ctrl",_kernel_kobj);
    if (irq_kobj == 0) {
      _printk(&DAT_0010072e);
      iVar2 = -0xc;
    }
    else {
      iVar2 = sysfs_create_file_ns(irq_kobj,&bhs_ipcc_irqs_attr,0);
      if (iVar2 != 0) {
        _printk(&DAT_001006a5);
        kobject_put(irq_kobj);
        irq_kobj = 0;
      }
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// cleanup_module @ 00100518 size=72
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  if (irq_kobj != 0) {
    sysfs_remove_file_ns(irq_kobj,&bhs_ipcc_irqs_attr,0);
    kobject_put(irq_kobj);
    irq_kobj = 0;
  }
  return;
}



//------------------------------------------------------------
// of_find_compatible_node @ 00102000 size=1
// signature: undefined of_find_compatible_node(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_compatible_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102008 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_irq_get @ 00102010 size=1
// signature: undefined of_irq_get(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_irq_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_child_by_name @ 00102018 size=1
// signature: undefined of_get_child_by_name(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_child_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_create_and_add @ 00102028 size=1
// signature: undefined kobject_create_and_add(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_create_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_file_ns @ 00102030 size=1
// signature: undefined sysfs_create_file_ns(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102038 size=1
// signature: undefined _printk(void)
// callers: [bhs_ipcc_irqs_store, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_put @ 00102040 size=1
// signature: undefined kobject_put(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102048 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [bhs_ipcc_irqs_store, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_file_ns @ 00102050 size=1
// signature: undefined sysfs_remove_file_ns(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 00102058 size=1
// signature: undefined kstrtoint(void)
// callers: [bhs_ipcc_irqs_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00102060 size=1
// signature: undefined mutex_lock(void)
// callers: [bhs_ipcc_irqs_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq_nosync @ 00102068 size=1
// signature: undefined disable_irq_nosync(void)
// callers: [bhs_ipcc_irqs_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq_nosync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 00102070 size=1
// signature: undefined enable_irq(void)
// callers: [bhs_ipcc_irqs_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00102078 size=1
// signature: undefined mutex_unlock(void)
// callers: [bhs_ipcc_irqs_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



