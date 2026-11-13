// Decompiled by Ghidra 12.2
// Program: clk-rpmh.ko
// Image base: 00100000

//------------------------------------------------------------
// clk_rpmh_prepare @ 001002bc size=80
// signature: undefined clk_rpmh_prepare(void)
// callers: []
//------------------------------------------------------------

undefined4 clk_rpmh_prepare(undefined8 param_1)

{
  undefined4 uVar1;
  
  mutex_lock(rpmh_clk_lock);
  uVar1 = clk_rpmh_aggregate_state_send_command(param_1,1);
  mutex_unlock(rpmh_clk_lock);
  return uVar1;
}



//------------------------------------------------------------
// clk_rpmh_unprepare @ 00100310 size=72
// signature: undefined clk_rpmh_unprepare(void)
// callers: []
//------------------------------------------------------------

void clk_rpmh_unprepare(undefined8 param_1)

{
  mutex_lock(rpmh_clk_lock);
  clk_rpmh_aggregate_state_send_command(param_1,0);
  mutex_unlock(rpmh_clk_lock);
  return;
}



//------------------------------------------------------------
// clk_rpmh_recalc_rate @ 0010035c size=12
// signature: undefined clk_rpmh_recalc_rate(void)
// callers: []
//------------------------------------------------------------

ulong clk_rpmh_recalc_rate(long param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = 0;
  if ((ulong)*(byte *)(param_1 + 0x20) != 0) {
    uVar1 = param_2 / *(byte *)(param_1 + 0x20);
  }
  return uVar1;
}



//------------------------------------------------------------
// clk_rpmh_aggregate_state_send_command @ 00100368 size=452
// signature: undefined clk_rpmh_aggregate_state_send_command(void)
// callers: [clk_rpmh_prepare, clk_rpmh_unprepare]
//------------------------------------------------------------

undefined8 clk_rpmh_aggregate_state_send_command(long param_1,ulong param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 local_58;
  ulong local_54;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  if ((param_2 & 1) == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = *(uint *)(param_1 + 0x38);
  }
  *(uint *)(param_1 + 0x2c) = uVar7;
  local_54 = 0;
  uVar7 = *(uint *)(*(long *)(param_1 + 0x48) + 0x2c) | uVar7;
  *(uint *)(param_1 + 0x30) = uVar7;
  *(uint *)(*(long *)(param_1 + 0x48) + 0x30) = uVar7;
  uVar1 = *(uint *)(param_1 + 0x30);
  local_58 = *(undefined4 *)(param_1 + 0x24);
  uVar2 = *(uint *)(param_1 + 0x28);
  uVar7 = *(uint *)(param_1 + 0x34) ^ uVar1;
  uVar8 = uVar1;
  if ((uVar7 & 1) != 0) {
    if ((uVar1 & 1) != 0) {
      local_54 = (ulong)uVar2;
    }
    iVar5 = rpmh_write_async(*(undefined8 *)(param_1 + 0x40),0,&local_58,1);
    if (iVar5 != 0) {
      pcVar6 = "sleep";
      goto LAB_001004d8;
    }
    uVar8 = *(uint *)(param_1 + 0x30);
    uVar7 = uVar8 ^ *(uint *)(param_1 + 0x34);
  }
  if ((uVar7 >> 1 & 1) != 0) {
    if ((uVar1 >> 1 & 1) != 0) {
      local_54 = CONCAT44(local_54._4_4_,uVar2);
    }
    iVar5 = rpmh_write_async(*(undefined8 *)(param_1 + 0x40),1,&local_58,1);
    if (iVar5 != 0) {
      pcVar6 = "wake";
      goto LAB_001004d8;
    }
    uVar8 = *(uint *)(param_1 + 0x30);
    uVar7 = uVar8 ^ *(uint *)(param_1 + 0x34);
  }
  if ((uVar7 >> 2 & 1) != 0) {
    if ((uVar1 >> 2 & 1) != 0) {
      local_54 = CONCAT44(local_54._4_4_,uVar2);
    }
    if (uVar1 == 0) {
      iVar5 = rpmh_write_async(*(undefined8 *)(param_1 + 0x40),2,&local_58,1);
    }
    else {
      iVar5 = rpmh_write();
    }
    if (iVar5 != 0) {
      pcVar6 = "active";
LAB_001004d8:
      _dev_err(*(undefined8 *)(param_1 + 0x40),"set %s state of %s failed: (%d)\n",pcVar6,
               *(undefined8 *)(param_1 + 0x18),iVar5);
      if ((param_2 & 1) == 0) {
        uVar9 = *(undefined4 *)(param_1 + 0x38);
        pcVar6 = "disable";
      }
      else {
        uVar9 = 0;
        pcVar6 = "enable";
      }
      *(undefined4 *)(param_1 + 0x2c) = uVar9;
      __warn_printk("clk: %s failed to %s\n",*(undefined8 *)(param_1 + 0x18),pcVar6);
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x800,0x100528);
      (*pcVar4)();
    }
    uVar8 = *(uint *)(param_1 + 0x30);
  }
  *(uint *)(param_1 + 0x34) = uVar8;
  *(uint *)(*(long *)(param_1 + 0x48) + 0x34) = uVar8;
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// clk_rpmh_bcm_prepare @ 00100534 size=32
// signature: undefined clk_rpmh_bcm_prepare(void)
// callers: []
//------------------------------------------------------------

void clk_rpmh_bcm_prepare(undefined8 param_1)

{
  clk_rpmh_bcm_send_cmd(param_1,1);
  return;
}



//------------------------------------------------------------
// clk_rpmh_bcm_unprepare @ 00100558 size=188
// signature: undefined clk_rpmh_bcm_unprepare(void)
// callers: []
//------------------------------------------------------------

void clk_rpmh_bcm_unprepare(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 local_38;
  undefined4 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  local_38 = 0;
  mutex_lock(rpmh_clk_lock);
  if (*(int *)(param_1 + 0x34) != 0) {
    local_38 = CONCAT44(0x40000000,*(undefined4 *)(param_1 + 0x24));
    iVar2 = rpmh_write_async(*(undefined8 *)(param_1 + 0x40),2,&local_38,1);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x34) = 0;
    }
    else {
      _dev_err(*(undefined8 *)(param_1 + 0x40),"set active state of %s failed: (%d)\n",
               *(undefined8 *)(param_1 + 0x18),iVar2);
    }
  }
  mutex_unlock(rpmh_clk_lock);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_rpmh_bcm_recalc_rate @ 00100618 size=16
// signature: undefined clk_rpmh_bcm_recalc_rate(void)
// callers: []
//------------------------------------------------------------

long clk_rpmh_bcm_recalc_rate(long param_1)

{
  return (ulong)*(uint *)(param_1 + 0x3c) * (ulong)*(uint *)(param_1 + 0x30);
}



//------------------------------------------------------------
// clk_rpmh_round_rate @ 0010062c size=8
// signature: undefined clk_rpmh_round_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rpmh_round_rate(undefined8 param_1,undefined8 param_2)

{
  return param_2;
}



//------------------------------------------------------------
// clk_rpmh_bcm_set_rate @ 00100638 size=72
// signature: undefined clk_rpmh_bcm_set_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rpmh_bcm_set_rate(long param_1,ulong param_2)

{
  undefined4 uVar1;
  ulong uVar2;
  
  uVar1 = 0;
  if ((ulong)*(uint *)(param_1 + 0x3c) != 0) {
    uVar1 = (undefined4)(param_2 / *(uint *)(param_1 + 0x3c));
  }
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  uVar2 = clk_hw_is_prepared();
  if ((uVar2 & 1) != 0) {
    clk_rpmh_bcm_send_cmd(param_1,1);
  }
  return 0;
}



//------------------------------------------------------------
// clk_rpmh_bcm_send_cmd @ 00100680 size=284
// signature: undefined clk_rpmh_bcm_send_cmd(void)
// callers: [clk_rpmh_bcm_set_rate, clk_rpmh_bcm_prepare]
//------------------------------------------------------------

int clk_rpmh_bcm_send_cmd(long param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined8 local_48;
  undefined4 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  local_48 = 0;
  mutex_lock(rpmh_clk_lock);
  uVar4 = 0;
  if (((param_2 & 1) != 0) && (uVar4 = *(uint *)(param_1 + 0x30), uVar4 == 0)) {
    uVar4 = 1;
  }
  if (0x3ffe < uVar4) {
    uVar4 = 0x3fff;
  }
  if (*(uint *)(param_1 + 0x34) == uVar4) {
    iVar2 = 0;
  }
  else {
    uVar3 = 0x60000000;
    if ((param_2 & 1) == 0) {
      uVar3 = 0x40000000;
    }
    local_48 = CONCAT44(uVar4 | uVar3,*(undefined4 *)(param_1 + 0x24));
    if ((param_2 & 1) == 0) {
      iVar2 = rpmh_write_async(*(undefined8 *)(param_1 + 0x40),2,&local_48,1);
    }
    else {
      iVar2 = rpmh_write();
    }
    if (iVar2 == 0) {
      *(uint *)(param_1 + 0x34) = uVar4;
    }
    else {
      _dev_err(*(undefined8 *)(param_1 + 0x40),"set active state of %s failed: (%d)\n",
               *(undefined8 *)(param_1 + 0x18),iVar2);
    }
  }
  mutex_unlock(rpmh_clk_lock);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// clk_rpmh_probe @ 001007a0 size=516
// signature: undefined clk_rpmh_probe(void)
// callers: []
//------------------------------------------------------------

int clk_rpmh_probe(long param_1)

{
  code *pcVar1;
  int iVar2;
  long *plVar3;
  int *piVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  long local_70;
  long local_68;
  
  lVar9 = sp_el0;
  param_1 = param_1 + 0x10;
  local_68 = *(long *)(lVar9 + 0x638);
  plVar3 = (long *)of_device_get_match_data(param_1);
  if (plVar3 == (long *)0x0) {
    iVar2 = -0x13;
  }
  else {
    if (plVar3[1] != 0) {
      uVar8 = 0;
      lVar9 = *plVar3;
      do {
        local_70 = 0;
        lVar7 = *(long *)(lVar9 + uVar8 * 8);
        if (lVar7 != 0) {
          uVar5 = **(undefined8 **)(lVar7 + 0x10);
          if ((undefined *)(*(undefined8 **)(lVar7 + 0x10))[1] != &clk_fixed_factor_ops) {
            iVar2 = cmd_db_read_addr(*(undefined8 *)(lVar7 + 0x18));
            if (iVar2 == 0) {
              *(undefined8 *)(lVar9 + uVar8 * 8) = 0;
              if (*(char *)(lVar7 + 0x21) == '\0') {
                __warn_printk("clk-rpmh: Missing RPMh resource address for %s\n",
                              *(undefined8 *)(lVar7 + 0x18));
                    /* WARNING: Does not return */
                pcVar1 = (code *)SoftwareBreakpoint(0x800,0x100988);
                (*pcVar1)();
              }
              goto LAB_00100810;
            }
            piVar4 = (int *)cmd_db_read_aux_data(*(undefined8 *)(lVar7 + 0x18),&local_70);
            if ((int *)0xfffffffffffff000 < piVar4) {
              __warn_printk("clk-rpmh: error reading RPMh aux data for %s (%d)\n",
                            *(undefined8 *)(lVar7 + 0x18),(ulong)piVar4 & 0xffffffff);
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10096c);
              (*pcVar1)();
            }
            if (local_70 == 8) {
              *(int *)(lVar7 + 0x3c) = *piVar4 * 1000;
            }
            *(long *)(lVar7 + 0x40) = param_1;
            *(int *)(lVar7 + 0x24) = *(int *)(lVar7 + 0x24) + iVar2;
            lVar7 = *(long *)(lVar9 + uVar8 * 8);
          }
          iVar2 = devm_clk_hw_register(param_1,lVar7);
          if (iVar2 != 0) {
            _dev_err(param_1,"failed to register %s\n",uVar5);
            goto LAB_00100918;
          }
          iVar2 = clk_hw_debug_register(param_1,*(undefined8 *)(lVar9 + uVar8 * 8));
          if (iVar2 != 0) {
            puVar6 = *(undefined8 **)(*(long *)(lVar9 + uVar8 * 8) + 0x10);
            if (puVar6 == (undefined8 *)0x0) {
              uVar5 = clk_hw_get_name();
            }
            else {
              uVar5 = *puVar6;
            }
            _dev_warn(param_1,"Failed to add %s to debug list\n",uVar5);
          }
        }
LAB_00100810:
        uVar8 = (ulong)((int)uVar8 + 1);
      } while (uVar8 < (ulong)plVar3[1]);
    }
    iVar2 = devm_of_clk_add_hw_provider(param_1,of_clk_rpmh_hw_get,plVar3);
    if (iVar2 != 0) {
      _dev_err(param_1,"Failed to add clock provider\n");
    }
  }
LAB_00100918:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// of_clk_rpmh_hw_get @ 001009b0 size=88
// signature: undefined of_clk_rpmh_hw_get(void)
// callers: []
//------------------------------------------------------------

long of_clk_rpmh_hw_get(long param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  
  if ((ulong)*(uint *)(param_1 + 0xc) < (ulong)param_2[1]) {
    lVar2 = *(long *)(*param_2 + (ulong)*(uint *)(param_1 + 0xc) * 8);
    lVar1 = -2;
    if (lVar2 != 0) {
      lVar1 = lVar2;
    }
  }
  else {
    _printk(&DAT_00108701,"of_clk_rpmh_hw_get");
    lVar1 = -0x16;
  }
  return lVar1;
}



//------------------------------------------------------------
// init_module @ 00100a0c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&clk_rpmh_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100a3c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&clk_rpmh_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 0010a000 size=1
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
// platform_driver_unregister @ 0010a008 size=1
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
// mutex_lock @ 0010a010 size=1
// signature: undefined mutex_lock(void)
// callers: [clk_rpmh_bcm_send_cmd, clk_rpmh_prepare, clk_rpmh_unprepare, clk_rpmh_bcm_unprepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010a018 size=1
// signature: undefined mutex_unlock(void)
// callers: [clk_rpmh_bcm_send_cmd, clk_rpmh_prepare, clk_rpmh_unprepare, clk_rpmh_bcm_unprepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmh_write_async @ 0010a020 size=1
// signature: undefined rpmh_write_async(void)
// callers: [clk_rpmh_bcm_send_cmd, clk_rpmh_aggregate_state_send_command, clk_rpmh_bcm_unprepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmh_write_async(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmh_write @ 0010a028 size=1
// signature: undefined rpmh_write(void)
// callers: [clk_rpmh_bcm_send_cmd, clk_rpmh_aggregate_state_send_command]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmh_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010a030 size=1
// signature: undefined _dev_err(void)
// callers: [clk_rpmh_bcm_send_cmd, clk_rpmh_aggregate_state_send_command, clk_rpmh_probe, clk_rpmh_bcm_unprepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 0010a038 size=1
// signature: undefined __warn_printk(void)
// callers: [clk_rpmh_aggregate_state_send_command, clk_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010a040 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [clk_rpmh_bcm_send_cmd, clk_rpmh_aggregate_state_send_command, clk_rpmh_probe, clk_rpmh_bcm_unprepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_hw_is_prepared @ 0010a048 size=1
// signature: undefined clk_hw_is_prepared(void)
// callers: [clk_rpmh_bcm_set_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_hw_is_prepared(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 0010a050 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [clk_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cmd_db_read_addr @ 0010a060 size=1
// signature: undefined cmd_db_read_addr(void)
// callers: [clk_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cmd_db_read_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cmd_db_read_aux_data @ 0010a068 size=1
// signature: undefined cmd_db_read_aux_data(void)
// callers: [clk_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cmd_db_read_aux_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_hw_register @ 0010a070 size=1
// signature: undefined devm_clk_hw_register(void)
// callers: [clk_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_hw_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_hw_debug_register @ 0010a078 size=1
// signature: undefined clk_hw_debug_register(void)
// callers: [clk_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_hw_debug_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_hw_get_name @ 0010a080 size=1
// signature: undefined clk_hw_get_name(void)
// callers: [clk_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_hw_get_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 0010a088 size=1
// signature: undefined _dev_warn(void)
// callers: [clk_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_of_clk_add_hw_provider @ 0010a090 size=1
// signature: undefined devm_of_clk_add_hw_provider(void)
// callers: [clk_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_of_clk_add_hw_provider(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010a098 size=1
// signature: undefined _printk(void)
// callers: [of_clk_rpmh_hw_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



