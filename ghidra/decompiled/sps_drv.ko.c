// Decompiled by Ghidra 12.2
// Program: sps_drv.ko
// Image base: 00100000

//------------------------------------------------------------
// bam_init @ 00102154 size=1112
// signature: undefined bam_init(void)
// callers: [sps_bam_enable]
//------------------------------------------------------------

undefined8
bam_init(undefined8 *param_1,undefined4 param_2,short param_3,undefined4 param_4,int *param_5,
        undefined4 *param_6,uint param_7)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  
  if (param_1 == (undefined8 *)0xd8) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 || (iVar1 = ___ratelimit(&bam_init__rs,"bam_init"), iVar1 != 0)))) {
      _printk(&DAT_001215d6,"bam_init",0xd8);
    }
    if (sps == 0) {
      uVar4 = 0xffffffff;
    }
    else {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_init",0xd8);
      uVar4 = 0xffffffff;
    }
  }
  else {
    if (((1 < logging_option) && (debug_level_option != 0)) &&
       ((print_limit_option == 0 || (iVar1 = ___ratelimit(bam_init__rs_2,"bam_init"), iVar1 != 0))))
    {
      _printk(&DAT_0011fade,"bam_init",param_1 + -0x18,*param_1,param_2);
    }
    if (*(uint *)(param_1 + 0x2c) < 4) {
      ipc_log_string(param_1[0x2a],"%s: sps: bam=%pa 0x%pK(va).ee=%d\n","bam_init",param_1 + -0x18,
                     *param_1,param_2);
    }
    iVar1 = bam_read_reg_field(param_1,1,0,0xff);
    if (iVar1 - 0x30U < 0xffffffd2) {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 || (iVar3 = ___ratelimit(bam_init__rs_5,"bam_init"), iVar3 != 0)))
         ) {
        _printk(&DAT_0011f5be,"bam_init",*param_1,iVar1);
      }
      ipc_log_string(param_1[0x2a],"%s: sps:bam 0x%pK(va) Invalid BAM REVISION 0x%x\n","bam_init",
                     *param_1,iVar1);
      uVar4 = 0xffffffed;
    }
    else {
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 || (iVar3 = ___ratelimit(bam_init__rs_8,"bam_init"), iVar3 != 0))
         )) {
        _printk(&DAT_00122168,"bam_init",*param_1,iVar1);
      }
      if (*(int *)(param_1 + 0x2c) == 0) {
        ipc_log_string(param_1[0x27],"%s: sps:REVISION of BAM 0x%pK is 0x%x\n","bam_init",*param_1,
                       iVar1);
      }
      if (param_3 == 0) {
        if ((logging_option != 1) &&
           ((print_limit_option < 3 ||
            (iVar3 = ___ratelimit(bam_init__rs_11,"bam_init"), iVar3 != 0)))) {
          _printk(&DAT_001208d0,"bam_init",*param_1);
        }
        ipc_log_string(param_1[0x2a],
                       "%s: sps:bam 0x%pK(va) summing_threshold is zero,use default 4\n","bam_init",
                       *param_1);
        param_3 = 4;
      }
      uVar2 = 0xfffff7ff;
      if ((param_7 & 0x10) != 0) {
        uVar2 = 0xffffe7ff;
      }
      bam_write_reg_field(0xffffe7ff,param_1,0,0,1,1);
      bam_write_reg_field(param_1,0,0,1,0);
      bam_write_reg_field(param_1,0,0,2,1);
      bam_write_reg_field(param_1,0,0,0x80000,0);
      bam_write_reg_field(param_1,0,0,0x60000,(param_7 & 0x20) == 0);
      if (enhd_pipe != '\0') {
        bam_write_reg_field(param_1,0,0,0x100000,param_7 >> 6 & 1);
      }
      bam_write_reg(param_1,6,0,param_3);
      bam_write_reg(param_1,0x17,0,uVar2);
      bam_write_reg_field(param_1,0x19,param_2,0x80000000,1);
      bam_write_reg(param_1,0xc,0,param_4);
      uVar2 = bam_read_reg_field(param_1,3,0,0xff);
      uVar4 = 0;
      *param_6 = uVar2;
      *param_5 = iVar1;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// bam_read_reg_field @ 001025ac size=520
// signature: undefined bam_read_reg_field(void)
// callers: [bam_check, bam_output_register_content, bam_pipe_check_pipe_empty, print_bam_pipe_desc_fifo, bam_pipe_enable, bam_pipe_is_enabled, bam_pipe_check_zlt, print_bam_test_bus_reg, bam_security_init, print_bam_selected_reg, bam_pipe_get_desc_write_offset, bam_init, bam_pipe_get_desc_read_offset, print_bam_pipe_selected_reg]
//------------------------------------------------------------

uint bam_read_reg_field(long *param_1,undefined4 param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 == (long *)0xd8) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar4 = ___ratelimit(bam_read_reg_field__rs,"bam_read_reg_field"), iVar4 != 0)))) {
      _printk(&DAT_001215d6,"bam_read_reg_field",0xd8);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_read_reg_field",0xd8);
    }
  }
  else {
    uVar2 = bam_get_register_offset(param_1);
    if (uVar2 != 0xffffffff) {
      uVar1 = (param_4 & 0xaaaaaaaa) >> 1 | (param_4 & 0x55555555) << 1;
      uVar1 = (uVar1 & 0xcccccccc) >> 2 | (uVar1 & 0x33333333) << 2;
      uVar1 = (uVar1 & 0xf0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f) << 4;
      uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
      uVar3 = readl(*param_1 + (ulong)uVar2);
      uVar1 = (uVar3 & param_4) >> (ulong)((uint)LZCOUNT(uVar1 >> 0x10 | uVar1 << 0x10) & 0x1f);
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar4 = ___ratelimit(bam_read_reg_field__rs_301,"bam_read_reg_field"), iVar4 != 0)))) {
        _printk(&DAT_0011d589,"bam_read_reg_field",*param_1,uVar2,param_4,uVar1);
      }
      if ((int)param_1[0x2c] == 0) {
        ipc_log_string(param_1[0x27],"%s: sps:bam 0x%pK(va) read reg 0x%x mask 0x%x r_val 0x%x\n",
                       "bam_read_reg_field",*param_1,uVar2,param_4,uVar1);
        return uVar1;
      }
      return uVar1;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar4 = ___ratelimit(bam_read_reg_field__rs_298,"bam_read_reg_field"), iVar4 != 0)))) {
      _printk(&DAT_0011fccc,"bam_read_reg_field",param_2);
    }
    ipc_log_string(param_1[0x2a],"%s: Failed to get the register offset for %d\n",
                   "bam_read_reg_field",param_2);
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// bam_write_reg_field @ 001027b4 size=540
// signature: undefined bam_write_reg_field(void)
// callers: [bam_disable_pipe, bam_pipe_enable, bam_exit, bam_pipe_exit, bam_pipe_set_irq, print_bam_test_bus_reg, bam_security_init, bam_pipe_init, bam_set_global_irq, bam_init, bam_pipe_satellite_mti, bam_pipe_set_desc_write_offset, bam_pipe_disable, bam_pipe_halt]
//------------------------------------------------------------

void bam_write_reg_field(long *param_1,undefined4 param_2,undefined8 param_3,uint param_4,
                        int param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 == (long *)0xd8) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar4 = ___ratelimit(bam_write_reg_field__rs,"bam_write_reg_field"), iVar4 != 0)))) {
      _printk(&DAT_001215d6,"bam_write_reg_field",0xd8);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_write_reg_field",0xd8);
    }
  }
  else {
    uVar2 = bam_get_register_offset(param_1);
    if (uVar2 == 0xffffffff) {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar4 = ___ratelimit(bam_write_reg_field__rs_304,"bam_write_reg_field"), iVar4 != 0)))) {
        _printk(&DAT_0011fccc,"bam_write_reg_field",param_2);
      }
      ipc_log_string(param_1[0x2a],"%s: Failed to get the register offset for %d\n",
                     "bam_write_reg_field",param_2);
    }
    else {
      uVar1 = (param_4 & 0xaaaaaaaa) >> 1 | (param_4 & 0x55555555) << 1;
      uVar1 = (uVar1 & 0xcccccccc) >> 2 | (uVar1 & 0x33333333) << 2;
      uVar1 = (uVar1 & 0xf0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f) << 4;
      uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
      uVar3 = readl(*param_1 + (ulong)uVar2);
      uVar1 = uVar3 & (param_4 ^ 0xffffffff) |
              param_5 << (ulong)((uint)LZCOUNT(uVar1 >> 0x10 | uVar1 << 0x10) & 0x1f);
      writel(uVar1,*param_1 + (ulong)uVar2);
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar4 = ___ratelimit(bam_write_reg_field__rs_305,"bam_write_reg_field"), iVar4 != 0)))) {
        _printk(&DAT_0011f78c,"bam_write_reg_field",*param_1,uVar2,uVar1);
      }
      if ((int)param_1[0x2c] == 0) {
        ipc_log_string(param_1[0x27],"%s: sps:bam 0x%pK(va) write reg 0x%x w_val 0x%x\n",
                       "bam_write_reg_field",*param_1,uVar2,uVar1);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// bam_write_reg @ 001029d0 size=492
// signature: undefined bam_write_reg(void)
// callers: [bam_pipe_init, bam_pipe_get_and_clear_irq_status, bam_pipe_reset, bam_exit, bam_init, bam_pipe_exit, bam_pipe_set_mti, bam_pipe_set_irq, bam_pipe_satellite_mti, bam_check_irq_source]
//------------------------------------------------------------

void bam_write_reg(long *param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 == (long *)0xd8) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(bam_write_reg__rs,"bam_write_reg"), iVar2 != 0)))) {
      _printk(&DAT_001215d6,"bam_write_reg",0xd8);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_write_reg",0xd8);
    }
  }
  else {
    uVar1 = bam_get_register_offset(param_1);
    if (uVar1 == 0xffffffff) {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar2 = ___ratelimit(bam_write_reg__rs_308,"bam_write_reg"), iVar2 != 0)))) {
        _printk(&DAT_0011fccc,"bam_write_reg",param_2);
      }
      ipc_log_string(param_1[0x2a],"%s: Failed to get the register offset for %d\n","bam_write_reg",
                     param_2);
    }
    else {
      writel(param_4,*param_1 + (ulong)uVar1);
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar2 = ___ratelimit(bam_write_reg__rs_309,"bam_write_reg"), iVar2 != 0)))) {
        _printk(&DAT_0011f78c,"bam_write_reg",*param_1,uVar1,param_4);
      }
      if ((int)param_1[0x2c] == 0) {
        ipc_log_string(param_1[0x27],"%s: sps:bam 0x%pK(va) write reg 0x%x w_val 0x%x\n",
                       "bam_write_reg",*param_1,uVar1,param_4);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// bam_set_global_irq @ 00102bc0 size=44
// signature: undefined bam_set_global_irq(void)
// callers: [sps_bam_enable_all_irqs, sps_bam_disable_all_irqs]
//------------------------------------------------------------

void bam_set_global_irq(undefined8 param_1,undefined4 param_2,undefined8 param_3,uint param_4)

{
  bam_write_reg_field(param_1,0x19,param_2,0x80000000,param_4 & 1);
  return;
}



//------------------------------------------------------------
// bam_security_init @ 00102bf0 size=824
// signature: undefined bam_security_init(void)
// callers: [sps_bam_enable]
//------------------------------------------------------------

undefined8 bam_security_init(undefined8 *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_1 == (undefined8 *)0xd8) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(bam_security_init__rs,"bam_security_init"), iVar1 != 0)))) {
      _printk(&DAT_001215d6,"bam_security_init",0xd8);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_security_init",0xd8);
    }
    uVar4 = 0xffffffff;
  }
  else {
    if (((1 < logging_option) && (debug_level_option != '\0')) &&
       ((print_limit_option == 0 ||
        (iVar1 = ___ratelimit(bam_security_init__rs_14,"bam_security_init"), iVar1 != 0)))) {
      _printk(&DAT_00121603,"bam_security_init",param_1 + -0x18,*param_1);
    }
    if (*(uint *)(param_1 + 0x2c) < 4) {
      ipc_log_string(param_1[0x2a],"%s: sps: bam=%pa 0x%pK(va)\n","bam_security_init",
                     param_1 + -0x18,*param_1);
    }
    iVar1 = bam_read_reg_field(param_1,1,0,0xff);
    uVar2 = bam_read_reg_field(param_1,3,0,0xff);
    if (iVar1 - 0x20U < 0xffffffe3) {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar3 = ___ratelimit(bam_security_init__rs_17,"bam_security_init"), iVar3 != 0)))) {
        _printk(&DAT_001244b4,"bam_security_init",*param_1,iVar1);
      }
      ipc_log_string(param_1[0x2a],
                     "%s: sps:bam 0x%pK(va) security is not supported for this BAM version 0x%x\n",
                     "bam_security_init",*param_1,iVar1);
    }
    else {
      if (uVar2 < 0x20) {
        if (uVar2 != 0) {
          uVar5 = 0;
          uVar6 = 1;
          do {
            if ((uVar6 & param_4) != 0) {
              bam_write_reg_field(param_1,0x3a,uVar5,7,param_2);
              bam_write_reg_field(param_1,0x3a,uVar5,0x1f00,param_3);
            }
            uVar5 = uVar5 + 1;
            uVar6 = uVar6 << 1;
          } while (uVar2 != uVar5);
        }
        if ((int)param_4 < 0) {
          bam_write_reg_field(param_1,0x14,0,7,param_2);
          bam_write_reg_field(param_1,0x14,0,0x1f00,param_3);
          bam_write_reg_field(param_1,0x14,0,0x80,0);
        }
        return 0;
      }
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar1 = ___ratelimit(bam_security_init__rs_20,"bam_security_init"), iVar1 != 0)))) {
        _printk(&DAT_0011e6b5,"bam_security_init",*param_1);
      }
      ipc_log_string(param_1[0x2a],
                     "%s: sps:bam 0x%pK(va) the number of pipes is more than the maximum number allowed\n"
                     ,"bam_security_init",*param_1);
    }
    uVar4 = 0xffffffed;
  }
  return uVar4;
}



//------------------------------------------------------------
// bam_check @ 00102f2c size=700
// signature: undefined bam_check(void)
// callers: [sps_bam_enable]
//------------------------------------------------------------

undefined8 bam_check(undefined8 *param_1,uint *param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (param_1 == (undefined8 *)0xd8) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 || (iVar1 = ___ratelimit(bam_check__rs,"bam_check"), iVar1 != 0))))
    {
      _printk(&DAT_001215d6,"bam_check",0xd8);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_check",0xd8);
    }
    return 0xffffffff;
  }
  if (((1 < logging_option) && (debug_level_option != '\0')) &&
     ((print_limit_option == 0 || (iVar1 = ___ratelimit(bam_check__rs_23,"bam_check"), iVar1 != 0)))
     ) {
    _printk(&DAT_00121603,"bam_check",param_1 + -0x18,*param_1);
  }
  if (*(uint *)(param_1 + 0x2c) < 4) {
    ipc_log_string(param_1[0x2a],"%s: sps: bam=%pa 0x%pK(va)\n","bam_check",param_1 + -0x18,*param_1
                  );
  }
  if (enhd_pipe == '\0') {
    iVar1 = bam_read_reg_field(param_1,0,0,2);
  }
  else {
    iVar1 = bam_read_reg_field(param_1,0x1b,param_3,0x80000000);
  }
  if (iVar1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 || (iVar1 = ___ratelimit(bam_check__rs_24,"bam_check"), iVar1 != 0))
       )) {
      _printk(&DAT_0011d99e,"bam_check",*param_1);
    }
    ipc_log_string(param_1[0x2a],"%s: sps: bam 0x%pK(va) is not enabled\n","bam_check",*param_1);
  }
  else {
    uVar2 = bam_read_reg(param_1,1,0);
    uVar2 = uVar2 & 0xff;
    uVar3 = bam_read_reg_field(param_1,3,0,0xff);
    *param_4 = uVar3;
    *param_2 = uVar2;
    if (0xffffffd1 < uVar2 - 0x30) {
      return 0;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 || (iVar1 = ___ratelimit(bam_check__rs_27,"bam_check"), iVar1 != 0))
       )) {
      _printk(&DAT_001250ac,"bam_check",*param_1,uVar2);
    }
    ipc_log_string(param_1[0x2a],"%s: sps: bam 0x%pK(va) Invalid BAM version 0x%x\n","bam_check",
                   *param_1,uVar2);
  }
  return 0xffffffed;
}



//------------------------------------------------------------
// bam_read_reg @ 001031e8 size=504
// signature: undefined bam_read_reg(void)
// callers: [bam_check, print_bam_pipe_desc_fifo, bam_pipe_get_and_clear_irq_status, bam_check_irq_source, print_bam_test_bus_reg, print_bam_selected_reg, print_bam_pipe_selected_reg]
//------------------------------------------------------------

undefined4 bam_read_reg(long *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == (long *)0xd8) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar3 = ___ratelimit(bam_read_reg__rs,"bam_read_reg"), iVar3 != 0)))) {
      _printk(&DAT_001215d6,"bam_read_reg",0xd8);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_read_reg",0xd8);
    }
  }
  else {
    uVar1 = bam_get_register_offset(param_1);
    if (uVar1 != 0xffffffff) {
      uVar2 = readl(*param_1 + (ulong)uVar1);
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar3 = ___ratelimit(bam_read_reg__rs_311,"bam_read_reg"), iVar3 != 0)))) {
        _printk(&DAT_0012064d,"bam_read_reg",*param_1,uVar1,param_2,uVar2);
      }
      if ((int)param_1[0x2c] == 0) {
        ipc_log_string(param_1[0x27],"%s: sps:bam 0x%pK(va) offset 0x%x reg 0x%x r_val 0x%x\n",
                       "bam_read_reg",*param_1,uVar1,param_2,uVar2);
        return uVar2;
      }
      return uVar2;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar3 = ___ratelimit(bam_read_reg__rs_310,"bam_read_reg"), iVar3 != 0)))) {
      _printk(&DAT_0011fccc,"bam_read_reg",param_2);
    }
    ipc_log_string(param_1[0x2a],"%s: Failed to get the register offset for %d\n","bam_read_reg",
                   param_2);
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// bam_exit @ 001033e4 size=388
// signature: undefined bam_exit(void)
// callers: [sps_bam_disable]
//------------------------------------------------------------

void bam_exit(undefined8 *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == (undefined8 *)0xd8) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 || (iVar1 = ___ratelimit(bam_exit__rs,"bam_exit"), iVar1 != 0)))) {
      _printk(&DAT_001215d6,"bam_exit",0xd8);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_exit",0xd8);
    }
  }
  else {
    if (((1 < logging_option) && (debug_level_option != '\0')) &&
       ((print_limit_option == 0 || (iVar1 = ___ratelimit(bam_exit__rs_30,"bam_exit"), iVar1 != 0)))
       ) {
      _printk(&DAT_0011fade,"bam_exit",param_1 + -0x18,*param_1,param_2);
    }
    if (*(uint *)(param_1 + 0x2c) < 4) {
      ipc_log_string(param_1[0x2a],"%s: sps: bam=%pa 0x%pK(va).ee=%d\n","bam_exit",param_1 + -0x18,
                     *param_1,param_2);
    }
    bam_write_reg_field(param_1,0x19,param_2,0x80000000,0);
    bam_write_reg(param_1,0xc,0,0);
    bam_write_reg_field(param_1,0,0,2,0);
  }
  return;
}



//------------------------------------------------------------
// bam_output_register_content @ 0010356c size=492
// signature: undefined bam_output_register_content(void)
// callers: [bam_check_irq_source, sps_bam_check_irq]
//------------------------------------------------------------

void bam_output_register_content(undefined8 *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  
  if (param_1 == (undefined8 *)0xd8) {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar3 = ___ratelimit(bam_output_register_content__rs,"bam_output_register_content"),
        iVar3 != 0)))) {
      _printk(&DAT_001215d6,"bam_output_register_content",0xd8);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_output_register_content",0xd8);
    }
  }
  else {
    print_bam_test_bus_reg(param_1,0);
    print_bam_selected_reg(param_1,8);
    uVar1 = bam_read_reg_field(param_1,3,0,0xff);
    if ((logging_option != '\x01') &&
       ((print_limit_option < 2 ||
        (iVar3 = ___ratelimit(bam_output_register_content__rs_31,"bam_output_register_content"),
        iVar3 != 0)))) {
      _printk(&DAT_00121621,"bam_output_register_content",param_1 + -0x18,*param_1,uVar1);
    }
    ipc_log_string(param_1[0x2a],"%s: sps:bam %pa 0x%pK(va) has %d pipes\n",
                   "bam_output_register_content",param_1 + -0x18,*param_1,uVar1);
    if (((enhd_pipe == '\0') ||
        (uVar2 = bam_read_reg_field(param_1,0x1b,param_2,0x7fffffff), enhd_pipe == '\0')) ||
       (uVar2 == 0)) {
      if (uVar1 != 0) {
        uVar2 = 0;
        do {
          print_bam_pipe_selected_reg(param_1,uVar2);
          uVar2 = uVar2 + 1;
        } while (uVar1 != uVar2);
      }
    }
    else if (uVar1 != 0) {
      uVar4 = 0;
      do {
        if ((uVar2 >> (uVar4 & 0x3f) & 1) != 0) {
          print_bam_pipe_selected_reg(param_1,uVar4 & 0xffffffff);
        }
        uVar4 = uVar4 + 1;
      } while (uVar1 != uVar4);
    }
  }
  return;
}



//------------------------------------------------------------
// print_bam_test_bus_reg @ 0010375c size=776
// signature: undefined print_bam_test_bus_reg(void)
// callers: [bam_output_register_content, sps_get_bam_debug_info, sps_set_bam_addr]
//------------------------------------------------------------

void print_bam_test_bus_reg(long param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  long lVar4;
  
  if (param_1 == 0) {
    return;
  }
  if (param_2 != 0) {
    if (((sps != 0) &&
        (ipc_log_string(*(undefined8 *)(sps + 0x118),
                        "%s: \nsps:Specified TEST_BUS_SEL value: 0x%x\n","print_bam_test_bus_reg",
                        param_2), sps != 0)) && (*(long *)(sps + 0x118) == 0)) {
      _printk(&DAT_001211b4,"print_bam_test_bus_reg",param_2);
    }
    bam_write_reg_field(param_1,0x15,0,0x7f,param_2);
    if (sps == 0) goto LAB_00103878;
    uVar3 = *(undefined8 *)(sps + 0x118);
    uVar1 = bam_read_reg(param_1,0x16,0);
    uVar2 = bam_read_reg_field(param_1,0x15,0,0x7f);
    ipc_log_string(uVar3,"%s: sps:BAM_TEST_BUS_REG:0x%x for TEST_BUS_SEL:0x%x\n\n",
                   "print_bam_test_bus_reg",uVar1,uVar2);
    if (sps == 0) goto LAB_00103878;
    if (*(long *)(sps + 0x118) == 0) {
      uVar1 = bam_read_reg(param_1,0x16,0);
      uVar2 = bam_read_reg_field(param_1,0x15,0,0x7f);
      _printk(&DAT_0011f754,"print_bam_test_bus_reg",uVar1,uVar2);
    }
  }
  if (((sps != 0) &&
      (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: %s","print_bam_test_bus_reg",
                      "\nsps:<testbus-begin> --- BAM TEST_BUS dump -----\n\n"), sps != 0)) &&
     (*(long *)(sps + 0x118) == 0)) {
    _printk(&DAT_0012561d,"print_bam_test_bus_reg",
            "\nsps:<testbus-begin> --- BAM TEST_BUS dump -----\n\n");
  }
LAB_00103878:
  lVar4 = 0;
  do {
    bam_write_reg_field(param_1,0x15,0,0x7f,*(undefined4 *)((long)&DAT_00125aa8 + lVar4));
    if (sps != 0) {
      uVar3 = *(undefined8 *)(sps + 0x118);
      uVar1 = bam_read_reg(param_1,0x16,0);
      uVar2 = bam_read_reg_field(param_1,0x15,0,0x7f);
      ipc_log_string(uVar3,"%s: sps:TEST_BUS_REG:0x%x\t  TEST_BUS_SEL:0x%x\n",
                     "print_bam_test_bus_reg",uVar1,uVar2);
      if ((sps != 0) && (*(long *)(sps + 0x118) == 0)) {
        uVar1 = bam_read_reg(param_1,0x16,0);
        uVar2 = bam_read_reg_field(param_1,0x15,0,0x7f);
        _printk(&DAT_00123c17,"print_bam_test_bus_reg",uVar1,uVar2);
      }
    }
    lVar4 = lVar4 + 4;
  } while (lVar4 != 0x88);
  if (((sps != 0) &&
      (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: %s","print_bam_test_bus_reg",
                      "\nsps:<testbus-end> --- BAM TEST_BUS dump -----\n\n"), sps != 0)) &&
     (*(long *)(sps + 0x118) == 0)) {
    _printk(&DAT_0012561d,"print_bam_test_bus_reg",
            "\nsps:<testbus-end> --- BAM TEST_BUS dump -----\n\n");
  }
  return;
}



//------------------------------------------------------------
// print_bam_selected_reg @ 00103a68 size=2644
// signature: undefined print_bam_selected_reg(void)
// callers: [bam_output_register_content, sps_get_bam_debug_info, sps_set_bam_addr]
//------------------------------------------------------------

void print_bam_selected_reg(long param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  
  if (param_1 != 0) {
    uVar1 = bam_read_reg(param_1,0,0);
    uVar2 = bam_read_reg(param_1,1,0);
    uVar3 = bam_read_reg_field(param_1,1,0,0xff);
    uVar4 = bam_read_reg_field(param_1,1,0,0xf00);
    uVar5 = bam_read_reg(param_1,3,0);
    uVar6 = bam_read_reg_field(param_1,3,0,0xff);
    iVar7 = bam_read_reg_field(param_1,3,0,0xc000);
    uVar8 = bam_read_reg(param_1,6,0);
    uVar9 = bam_read_reg_field(param_1,6,0,0xffff);
    uVar10 = bam_read_reg(param_1,0xc,0);
    uVar11 = bam_read_reg(param_1,10,0);
    uVar14 = 0;
    uVar13 = 0;
    uVar12 = 0;
    if (param_2 < 8) {
      uVar12 = bam_read_reg(param_1,0x18,param_2);
      uVar13 = bam_read_reg(param_1,0x19,param_2);
      uVar14 = bam_read_reg(param_1,0x1a,param_2);
    }
    uVar15 = bam_read_reg(param_1,0xe,0);
    uVar16 = bam_read_reg(param_1,0xf,0);
    uVar17 = bam_read_reg(param_1,0x11,0);
    uVar18 = bam_read_reg(param_1,0x17,0);
    uVar19 = bam_read_reg(param_1,2,0);
    uVar20 = bam_read_reg(param_1,0x10,0);
    uVar21 = 0;
    if ((param_2 < 8) && (enhd_pipe != '\0')) {
      uVar21 = bam_read_reg(param_1,0x1b,param_2);
    }
    if (((((sps != 0) &&
          (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: %s","print_bam_selected_reg",
                          "\nsps:<bam-begin> --- BAM-level registers ---\n\n"), sps != 0)) &&
         ((*(long *)(sps + 0x118) != 0 ||
          (_printk(&DAT_0012561d,"print_bam_selected_reg",
                   "\nsps:<bam-begin> --- BAM-level registers ---\n\n"), sps != 0)))) &&
        ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_CTRL: 0x%x\n",
                         "print_bam_selected_reg",uVar1), sps != 0 &&
         (((((*(long *)(sps + 0x118) != 0 ||
             (_printk(&DAT_00121d5f,"print_bam_selected_reg",uVar1), sps != 0)) &&
            (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_REVISION: 0x%x\n",
                            "print_bam_selected_reg",uVar2), sps != 0)) &&
           ((*(long *)(sps + 0x118) != 0 ||
            (_printk(&DAT_0011e737,"print_bam_selected_reg",uVar2), sps != 0)))) &&
          (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     REVISION: 0x%x\n",
                          "print_bam_selected_reg",uVar3), sps != 0)))))) &&
       ((((*(long *)(sps + 0x118) != 0 ||
          (_printk(&DAT_0011d041,"print_bam_selected_reg",uVar3), sps != 0)) &&
         (((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     NUM_EES: %d\n",
                           "print_bam_selected_reg",uVar4), sps != 0 &&
           (((*(long *)(sps + 0x118) != 0 ||
             (_printk(&DAT_001234e1,"print_bam_selected_reg",uVar4), sps != 0)) &&
            (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_SW_REVISION: 0x%x\n",
                            "print_bam_selected_reg",uVar19), sps != 0)))) &&
          (((*(long *)(sps + 0x118) != 0 ||
            (_printk(&DAT_00125626,"print_bam_selected_reg",uVar19), sps != 0)) &&
           (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_NUM_PIPES: %d\n",
                           "print_bam_selected_reg",uVar5), sps != 0)))))) &&
        ((*(long *)(sps + 0x118) != 0 ||
         (_printk(&DAT_0011f647,"print_bam_selected_reg",uVar5), sps != 0)))))) {
      uVar1 = 0x20;
      if (iVar7 != 0) {
        uVar1 = 0x24;
      }
      ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_DATA_ADDR_BUS_WIDTH: %d\n",
                     "print_bam_selected_reg",uVar1);
      if ((((sps != 0) &&
           (((*(long *)(sps + 0x118) != 0 ||
             (_printk(&DAT_00122554,"print_bam_selected_reg",uVar1), sps != 0)) &&
            (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     NUM_PIPES: %d\n",
                            "print_bam_selected_reg",uVar6), sps != 0)))) &&
          (((*(long *)(sps + 0x118) != 0 ||
            (_printk(&DAT_00124590,"print_bam_selected_reg",uVar6), sps != 0)) &&
           ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_DESC_CNT_TRSHLD: 0x%x\n",
                            "print_bam_selected_reg",uVar8), sps != 0 &&
            (((*(long *)(sps + 0x118) != 0 ||
              (_printk(&DAT_0011d05b,"print_bam_selected_reg",uVar8), sps != 0)) &&
             ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     DESC_CNT_TRSHLD: 0x%x (%d)\n",
                              "print_bam_selected_reg",uVar9,uVar9), sps != 0 &&
              ((((*(long *)(sps + 0x118) != 0 ||
                 (_printk(&DAT_00120d23,"print_bam_selected_reg",uVar9,uVar9), sps != 0)) &&
                (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_IRQ_EN: 0x%x\n",
                                "print_bam_selected_reg",uVar10), sps != 0)) &&
               ((*(long *)(sps + 0x118) != 0 ||
                (_printk(&DAT_00120154,"print_bam_selected_reg",uVar10), sps != 0)))))))))))))) &&
         ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_IRQ_STTS: 0x%x\n",
                          "print_bam_selected_reg",uVar11), sps != 0 &&
          (*(long *)(sps + 0x118) == 0)))) {
        _printk(&DAT_0011f154,"print_bam_selected_reg",uVar11);
      }
    }
    if (param_2 < 8) {
      if (sps == 0) {
        return;
      }
      ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_IRQ_SRCS_EE(%d): 0x%x\n",
                     "print_bam_selected_reg",param_2,uVar12);
      if (sps == 0) {
        return;
      }
      if ((*(long *)(sps + 0x118) == 0) &&
         (_printk(&DAT_001216c3,"print_bam_selected_reg",param_2,uVar12), sps == 0)) {
        return;
      }
      ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_IRQ_SRCS_MSK_EE(%d): 0x%x\n",
                     "print_bam_selected_reg",param_2,uVar13);
      if (sps == 0) {
        return;
      }
      if ((*(long *)(sps + 0x118) == 0) &&
         (_printk(&DAT_001238a1,"print_bam_selected_reg",param_2,uVar13), sps == 0)) {
        return;
      }
      ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_IRQ_SRCS_UNMASKED_EE(%d): 0x%x\n",
                     "print_bam_selected_reg",param_2,uVar14);
      if (sps == 0) {
        return;
      }
      if ((*(long *)(sps + 0x118) == 0) &&
         (_printk(&DAT_0011eb9b,"print_bam_selected_reg",param_2,uVar14), sps == 0)) {
        return;
      }
      ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_PIPE_ATTR_EE(%d): 0x%x\n",
                     "print_bam_selected_reg",param_2,uVar21);
      if (sps == 0) {
        return;
      }
      if (*(long *)(sps + 0x118) == 0) {
        _printk(&DAT_001251ac,"print_bam_selected_reg",param_2,uVar21);
      }
    }
    if (((((((sps != 0) &&
            (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_AHB_MASTER_ERR_CTRLS: 0x%x\n",
                            "print_bam_selected_reg",uVar15), sps != 0)) &&
           ((*(long *)(sps + 0x118) != 0 ||
            (_printk(&DAT_00122cbc,"print_bam_selected_reg",uVar15), sps != 0)))) &&
          (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_AHB_MASTER_ERR_ADDR: 0x%x\n",
                          "print_bam_selected_reg",uVar16), sps != 0)) &&
         (((*(long *)(sps + 0x118) != 0 ||
           (_printk(&DAT_0012018f,"print_bam_selected_reg",uVar16), sps != 0)) &&
          (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_AHB_MASTER_ERR_ADDR_MSB: 0x%x\n",
                          "print_bam_selected_reg",uVar20), sps != 0)))) &&
        (((*(long *)(sps + 0x118) != 0 ||
          (_printk(&DAT_0011d481,"print_bam_selected_reg",uVar20), sps != 0)) &&
         ((((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_AHB_MASTER_ERR_DATA: 0x%x\n",
                            "print_bam_selected_reg",uVar17), sps != 0 &&
            ((*(long *)(sps + 0x118) != 0 ||
             (_printk(&DAT_0011f6a6,"print_bam_selected_reg",uVar17), sps != 0)))) &&
           (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_CNFG_BITS: 0x%x\n",
                           "print_bam_selected_reg",uVar18), sps != 0)) &&
          ((((*(long *)(sps + 0x118) != 0 ||
             (_printk(&DAT_00121d96,"print_bam_selected_reg",uVar18), sps != 0)) &&
            (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_TIMER: 0x%x\n",
                            "print_bam_selected_reg",0), sps != 0)) &&
           (((*(long *)(sps + 0x118) != 0 ||
             (_printk(&DAT_0012091f,"print_bam_selected_reg",0), sps != 0)) &&
            ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_TIMER_CTRL: 0x%x\n",
                             "print_bam_selected_reg",0), sps != 0 &&
             ((*(long *)(sps + 0x118) != 0 ||
              (_printk(&DAT_0011da21,"print_bam_selected_reg",0), sps != 0)))))))))))))) &&
       ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: %s","print_bam_selected_reg",
                        "\nsps:<bam-end> --- BAM-level registers ---\n\n"), sps != 0 &&
        (*(long *)(sps + 0x118) == 0)))) {
      _printk(&DAT_0012561d,"print_bam_selected_reg",
              "\nsps:<bam-end> --- BAM-level registers ---\n\n");
    }
  }
  return;
}



//------------------------------------------------------------
// print_bam_pipe_selected_reg @ 001044c0 size=5428
// signature: undefined print_bam_pipe_selected_reg(void)
// callers: [bam_output_register_content, sps_get_bam_debug_info, sps_set_bam_addr]
//------------------------------------------------------------

void print_bam_pipe_selected_reg(long param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined4 uVar40;
  undefined4 uVar41;
  undefined4 uVar42;
  undefined4 uVar43;
  undefined4 uVar44;
  undefined4 uVar45;
  undefined4 uVar46;
  undefined4 uVar47;
  undefined4 uVar48;
  undefined *puVar49;
  
  if (param_1 == 0) {
    return;
  }
  uVar1 = bam_read_reg(param_1,0x1c,param_2);
  uVar2 = bam_read_reg_field(param_1,0x1c,param_2,0x20);
  iVar3 = bam_read_reg_field(param_1,0x1c,param_2,8);
  uVar4 = bam_read_reg(param_1,0x21,param_2);
  uVar5 = bam_read_reg(param_1,0x1f,param_2);
  uVar6 = bam_read_reg_field(param_1,0x1f,param_2,0x20);
  uVar7 = bam_read_reg_field(param_1,0x1f,param_2,1);
  uVar8 = bam_read_reg(param_1,0x24,param_2);
  uVar9 = bam_read_reg_field(param_1,0x24,param_2,0xffff);
  uVar10 = bam_read_reg_field(param_1,0x24,param_2,0xf0000);
  uVar11 = bam_read_reg_field(param_1,0x24,param_2,0x100000);
  uVar12 = bam_read_reg_field(param_1,0x24,param_2,0x1000000);
  uVar13 = bam_read_reg(param_1,0x25,param_2);
  uVar14 = bam_read_reg_field(param_1,0x25,param_2,0xffff);
  uVar15 = bam_read_reg_field(param_1,0x25,param_2,0xf0000);
  uVar16 = bam_read_reg_field(param_1,0x25,param_2,0x100000);
  uVar17 = bam_read_reg_field(param_1,0x25,param_2,0x400000);
  uVar18 = bam_read_reg_field(param_1,0x25,param_2,0x200000);
  uVar19 = bam_read_reg_field(param_1,0x25,param_2,0x800000);
  uVar20 = bam_read_reg_field(param_1,0x25,param_2,0x1000000);
  uVar21 = bam_read_reg(param_1,0x29,param_2);
  uVar22 = bam_read_reg_field(param_1,0x29,param_2,0xffff);
  uVar23 = bam_read_reg(param_1,0x28,param_2);
  uVar24 = bam_read_reg_field(param_1,0x28,param_2,0xffff);
  uVar25 = bam_read_reg(param_1,0x26,param_2);
  uVar26 = bam_read_reg(param_1,0x2c,param_2);
  uVar27 = bam_read_reg_field(param_1,0x2f,param_2,0xffff);
  uVar28 = bam_read_reg(param_1,0x2a,param_2);
  uVar29 = bam_read_reg_field(param_1,0x2f,param_2,0xffff0000);
  uVar30 = bam_read_reg(param_1,0x2f,param_2);
  uVar31 = bam_read_reg(param_1,0x2e,param_2);
  uVar32 = bam_read_reg_field(param_1,0x2e,param_2,0xffff);
  uVar33 = bam_read_reg(param_1,0x31,param_2);
  uVar34 = bam_read_reg_field(param_1,0x31,param_2,0xffff0000);
  uVar35 = bam_read_reg(param_1,0x32,param_2);
  uVar36 = bam_read_reg_field(param_1,0x32,param_2,0xffff);
  uVar37 = bam_read_reg(param_1,0x34,param_2);
  uVar38 = bam_read_reg(param_1,0x35,param_2);
  uVar39 = bam_read_reg(param_1,0x36,param_2);
  uVar40 = bam_read_reg(param_1,0x38,param_2);
  uVar41 = bam_read_reg(param_1,0x39,param_2);
  uVar42 = bam_read_reg(param_1,0x27,param_2);
  uVar43 = bam_read_reg(param_1,0x2d,param_2);
  uVar44 = bam_read_reg(param_1,0x2b,param_2);
  uVar45 = bam_read_reg(param_1,0x36,param_2);
  uVar46 = bam_read_reg_field(param_1,0x1c,param_2,0x1f0000);
  uVar47 = bam_read_reg(param_1,0x33,param_2);
  uVar48 = bam_read_reg_field(param_1,0x33,param_2,0xffff);
  if ((((sps != 0) &&
       (ipc_log_string(*(undefined8 *)(sps + 0x118),
                       "%s: \nsps:<pipe-begin> --- Registers of Pipe %d ---\n\n",
                       "print_bam_pipe_selected_reg",param_2), sps != 0)) &&
      ((*(long *)(sps + 0x118) != 0 ||
       (_printk(&DAT_0011e7d1,"print_bam_pipe_selected_reg",param_2), sps != 0)))) &&
     ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_CTRL: 0x%x\n",
                      "print_bam_pipe_selected_reg",uVar1), sps != 0 &&
      ((((*(long *)(sps + 0x118) != 0 ||
         (_printk(&DAT_0011ebc5,"print_bam_pipe_selected_reg",uVar1), sps != 0)) &&
        (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     SYS_MODE: %d\n",
                        "print_bam_pipe_selected_reg",uVar2), sps != 0)) &&
       (*(long *)(sps + 0x118) == 0)))))) {
    _printk(&DAT_0011ddd7,"print_bam_pipe_selected_reg",uVar2);
  }
  if (iVar3 == 0) {
    if (sps == 0) {
      return;
    }
    ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     DIRECTION:%d->Consumer\n",
                   "print_bam_pipe_selected_reg",0);
    if (sps == 0) {
      return;
    }
    if (*(long *)(sps + 0x118) != 0) goto joined_r0x00104a20;
    puVar49 = &DAT_00124cd2;
    iVar3 = 0;
  }
  else {
    if (sps == 0) {
      return;
    }
    ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     DIRECTION:%d->Producer\n",
                   "print_bam_pipe_selected_reg",iVar3);
    if (sps == 0) {
      return;
    }
    if (*(long *)(sps + 0x118) != 0) goto joined_r0x00104a20;
    puVar49 = &DAT_001225a4;
  }
  _printk(puVar49,"print_bam_pipe_selected_reg",iVar3);
joined_r0x00104a20:
  if ((((((((((sps != 0) &&
             (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     LOCK_GROUP: 0x%x (%d)\n",
                             "print_bam_pipe_selected_reg",uVar46,uVar46), sps != 0)) &&
            ((*(long *)(sps + 0x118) != 0 ||
             (_printk(&DAT_0011fc57,"print_bam_pipe_selected_reg",uVar46,uVar46), sps != 0)))) &&
           (((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_IRQ_EN: 0x%x\n",
                             "print_bam_pipe_selected_reg",uVar4), sps != 0 &&
             (((*(long *)(sps + 0x118) != 0 ||
               (_printk(&DAT_0011fc78,"print_bam_pipe_selected_reg",uVar4), sps != 0)) &&
              ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_IRQ_STTS: 0x%x\n",
                               "print_bam_pipe_selected_reg",uVar5), sps != 0 &&
               (((*(long *)(sps + 0x118) != 0 ||
                 (_printk(&DAT_00123bd8,"print_bam_pipe_selected_reg",uVar5), sps != 0)) &&
                (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     TRNSFR_END_IRQ(EOT): 0x%x\n",
                                "print_bam_pipe_selected_reg",uVar6), sps != 0)))))))) &&
            ((*(long *)(sps + 0x118) != 0 ||
             (_printk(&DAT_0012298a,"print_bam_pipe_selected_reg",uVar6), sps != 0)))))) &&
          (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     PRCSD_DESC_IRQ(INT): 0x%x\n",
                          "print_bam_pipe_selected_reg",uVar7), sps != 0)) &&
         (((((*(long *)(sps + 0x118) != 0 ||
             (_printk(&DAT_001201b4,"print_bam_pipe_selected_reg",uVar7), sps != 0)) &&
            ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_PRDCR_SDBND: 0x%x\n",
                             "print_bam_pipe_selected_reg",uVar8), sps != 0 &&
             (((*(long *)(sps + 0x118) != 0 ||
               (_printk(&DAT_0011fc92,"print_bam_pipe_selected_reg",uVar8), sps != 0)) &&
              (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     BYTES_FREE: 0x%x (%d)\n",
                              "print_bam_pipe_selected_reg",uVar9,uVar9), sps != 0)))))) &&
           ((*(long *)(sps + 0x118) != 0 ||
            (_printk(&DAT_0011f6ee,"print_bam_pipe_selected_reg",uVar9,uVar9), sps != 0)))) &&
          (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     CTRL: 0x%x\n",
                          "print_bam_pipe_selected_reg",uVar10), sps != 0)))) &&
        (((((((*(long *)(sps + 0x118) != 0 ||
              (_printk(&DAT_0011da3d,"print_bam_pipe_selected_reg",uVar10), sps != 0)) &&
             ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     TOGGLE: %d\n",
                              "print_bam_pipe_selected_reg",uVar11), sps != 0 &&
              ((((*(long *)(sps + 0x118) != 0 ||
                 (_printk(&DAT_001221c2,"print_bam_pipe_selected_reg",uVar11), sps != 0)) &&
                (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     SB_UPDATED: %d\n",
                                "print_bam_pipe_selected_reg",uVar12), sps != 0)) &&
               ((*(long *)(sps + 0x118) != 0 ||
                (_printk(&DAT_0011e1f2,"print_bam_pipe_selected_reg",uVar12), sps != 0)))))))) &&
            ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_CNSMR_SDBND: 0x%x\n",
                             "print_bam_pipe_selected_reg",uVar13), sps != 0 &&
             ((*(long *)(sps + 0x118) != 0 ||
              (_printk(&DAT_00120d49,"print_bam_pipe_selected_reg",uVar13), sps != 0)))))) &&
           ((((((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     WAIT_4_ACK: %d\n",
                                "print_bam_pipe_selected_reg",uVar19), sps != 0 &&
                (((*(long *)(sps + 0x118) != 0 ||
                  (_printk(&DAT_0011e20c,"print_bam_pipe_selected_reg",uVar19), sps != 0)) &&
                 (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     BYTES_AVAIL: 0x%x (%d)\n",
                                 "print_bam_pipe_selected_reg",uVar14,uVar14), sps != 0)))) &&
               (((*(long *)(sps + 0x118) != 0 ||
                 (_printk(&DAT_00120d68,"print_bam_pipe_selected_reg",uVar14,uVar14), sps != 0)) &&
                (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     CTRL: 0x%x\n",
                                "print_bam_pipe_selected_reg",uVar15), sps != 0)))) &&
              ((*(long *)(sps + 0x118) != 0 ||
               (_printk(&DAT_0011da3d,"print_bam_pipe_selected_reg",uVar15), sps != 0)))) &&
             ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     TOGGLE: %d\n",
                              "print_bam_pipe_selected_reg",uVar16), sps != 0 &&
              (((*(long *)(sps + 0x118) != 0 ||
                (_printk(&DAT_001221c2,"print_bam_pipe_selected_reg",uVar16), sps != 0)) &&
               (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     ACK_TOGGLE: %d\n",
                               "print_bam_pipe_selected_reg",uVar17), sps != 0)))))) &&
            (((*(long *)(sps + 0x118) != 0 ||
              (_printk(&DAT_00123f63,"print_bam_pipe_selected_reg",uVar17), sps != 0)) &&
             (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     ACK_TOGGLE_R: %d\n",
                             "print_bam_pipe_selected_reg",uVar18), sps != 0)))))) &&
          ((((*(long *)(sps + 0x118) != 0 ||
             (_printk(&DAT_00120d8a,"print_bam_pipe_selected_reg",uVar18), sps != 0)) &&
            ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     SB_UPDATED: %d\n",
                             "print_bam_pipe_selected_reg",uVar20), sps != 0 &&
             (((((*(long *)(sps + 0x118) != 0 ||
                 (_printk(&DAT_0011e1f2,"print_bam_pipe_selected_reg",uVar20), sps != 0)) &&
                (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_SW_DESC_OFST: 0x%x\n",
                                "print_bam_pipe_selected_reg",uVar21), sps != 0)) &&
               ((*(long *)(sps + 0x118) != 0 ||
                (_printk(&DAT_0011da53,"print_bam_pipe_selected_reg",uVar21), sps != 0)))) &&
              (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     SW_DESC_OFST: 0x%x\n",
                              "print_bam_pipe_selected_reg",uVar22), sps != 0)))))) &&
           (((*(long *)(sps + 0x118) != 0 ||
             (_printk(&DAT_0011da73,"print_bam_pipe_selected_reg",uVar22), sps != 0)) &&
            ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_EVNT_REG: 0x%x\n",
                             "print_bam_pipe_selected_reg",uVar23), sps != 0 &&
             (((*(long *)(sps + 0x118) != 0 ||
               (_printk(&DAT_0011ec27,"print_bam_pipe_selected_reg",uVar23), sps != 0)) &&
              (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     DESC_FIFO_PEER_OFST: 0x%x\n",
                              "print_bam_pipe_selected_reg",uVar24), sps != 0)))))))))) &&
         ((((((*(long *)(sps + 0x118) != 0 ||
              (_printk(&DAT_001229af,"print_bam_pipe_selected_reg",uVar24), sps != 0)) &&
             ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_RETR_CNTXT: 0x%x\n",
                              "print_bam_pipe_selected_reg",uVar33), sps != 0 &&
              ((*(long *)(sps + 0x118) != 0 ||
               (_printk(&DAT_00121133,"print_bam_pipe_selected_reg",uVar33), sps != 0)))))) &&
            (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     RETR_OFFSET: 0x%x\n",
                            "print_bam_pipe_selected_reg",uVar34), sps != 0)) &&
           ((((*(long *)(sps + 0x118) != 0 ||
              (_printk(&DAT_00123518,"print_bam_pipe_selected_reg",uVar34), sps != 0)) &&
             (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_SI_CNTXT: 0x%x\n",
                             "print_bam_pipe_selected_reg",uVar35), sps != 0)) &&
            ((*(long *)(sps + 0x118) != 0 ||
             (_printk(&DAT_0011e808,"print_bam_pipe_selected_reg",uVar35), sps != 0)))))) &&
          (((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     SI_OFFSET: 0x%x\n",
                            "print_bam_pipe_selected_reg",uVar36), sps != 0 &&
            ((*(long *)(sps + 0x118) != 0 ||
             (_printk(&DAT_0011fcb1,"print_bam_pipe_selected_reg",uVar36), sps != 0)))) &&
           (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_DF_CNTXT: 0x%x\n",
                           "print_bam_pipe_selected_reg",uVar47), sps != 0)))))))) &&
       ((((((*(long *)(sps + 0x118) != 0 ||
            (_printk(&DAT_0011e226,"print_bam_pipe_selected_reg",uVar47), sps != 0)) &&
           (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     DF_OFFSET: 0x%x\n",
                           "print_bam_pipe_selected_reg",uVar48), sps != 0)) &&
          ((*(long *)(sps + 0x118) != 0 ||
           (_printk(&DAT_00121753,"print_bam_pipe_selected_reg",uVar48), sps != 0)))) &&
         ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_DESC_FIFO_ADDR: 0x%x\n",
                          "print_bam_pipe_selected_reg",uVar26), sps != 0 &&
          ((*(long *)(sps + 0x118) != 0 ||
           (_printk(&DAT_0012176e,"print_bam_pipe_selected_reg",uVar26), sps != 0)))))) &&
        (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_DESC_FIFO_ADDR_MSB: 0x%x\n",
                        "print_bam_pipe_selected_reg",uVar43), sps != 0)))) &&
      ((((*(long *)(sps + 0x118) != 0 ||
         (_printk(&DAT_001245c9,"print_bam_pipe_selected_reg",uVar43), sps != 0)) &&
        (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_DATA_FIFO_ADDR: 0x%x\n",
                        "print_bam_pipe_selected_reg",uVar28), sps != 0)) &&
       (((((*(long *)(sps + 0x118) != 0 ||
           (_printk(&DAT_00124cf4,"print_bam_pipe_selected_reg",uVar28), sps != 0)) &&
          ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_DATA_FIFO_ADDR_MSB: 0x%x\n",
                           "print_bam_pipe_selected_reg",uVar44), sps != 0 &&
           ((*(long *)(sps + 0x118) != 0 ||
            (_printk(&DAT_0012391f,"print_bam_pipe_selected_reg",uVar44), sps != 0)))))) &&
         ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_FIFO_SIZES: 0x%x\n",
                          "print_bam_pipe_selected_reg",uVar30), sps != 0 &&
          (((*(long *)(sps + 0x118) != 0 ||
            (_printk(&DAT_00121a5f,"print_bam_pipe_selected_reg",uVar30), sps != 0)) &&
           (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     DESC_FIFO_SIZE: 0x%x (%d)\n",
                           "print_bam_pipe_selected_reg",uVar27,uVar27), sps != 0)))))) &&
        ((*(long *)(sps + 0x118) != 0 ||
         (_printk(&DAT_00123559,"print_bam_pipe_selected_reg",uVar27,uVar27), sps != 0)))))))) &&
     ((((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     DATA_FIFO_SIZE: 0x%x (%d)\n",
                        "print_bam_pipe_selected_reg",uVar29,uVar29), sps != 0 &&
        ((*(long *)(sps + 0x118) != 0 ||
         (_printk(&DAT_0011e266,"print_bam_pipe_selected_reg",uVar29,uVar29), sps != 0)))) &&
       (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_EVNT_DEST_ADDR: 0x%x\n",
                       "print_bam_pipe_selected_reg",uVar25), sps != 0)) &&
      ((((((*(long *)(sps + 0x118) != 0 ||
           (_printk(&DAT_0012116d,"print_bam_pipe_selected_reg",uVar25), sps != 0)) &&
          (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_EVNT_DEST_ADDR_MSB: 0x%x\n",
                          "print_bam_pipe_selected_reg",uVar42), sps != 0)) &&
         ((*(long *)(sps + 0x118) != 0 ||
          (_printk(&DAT_00120968,"print_bam_pipe_selected_reg",uVar42), sps != 0)))) &&
        ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_EVNT_GEN_TRSHLD: 0x%x\n",
                         "print_bam_pipe_selected_reg",uVar31), sps != 0 &&
         ((*(long *)(sps + 0x118) != 0 ||
          (_printk(&DAT_0011e824,"print_bam_pipe_selected_reg",uVar31), sps != 0)))))) &&
       (((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s:     EVNT_GEN_TRSHLD: 0x%x (%d)\n",
                         "print_bam_pipe_selected_reg",uVar32,uVar32), sps != 0 &&
         (((((*(long *)(sps + 0x118) != 0 ||
             (_printk(&DAT_0011e28b,"print_bam_pipe_selected_reg",uVar32,uVar32), sps != 0)) &&
            (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_AU_PSM_CNTXT_1: 0x%x\n",
                            "print_bam_pipe_selected_reg",uVar37), sps != 0)) &&
           (((*(long *)(sps + 0x118) != 0 ||
             (_printk(&DAT_00122d14,"print_bam_pipe_selected_reg",uVar37), sps != 0)) &&
            ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_PSM_CNTXT_2: 0x%x\n",
                             "print_bam_pipe_selected_reg",uVar38), sps != 0 &&
             ((*(long *)(sps + 0x118) != 0 ||
              (_printk(&DAT_001229d4,"print_bam_pipe_selected_reg",uVar38), sps != 0)))))))) &&
          (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_PSM_CNTXT_3: 0x%x\n",
                          "print_bam_pipe_selected_reg",uVar39), sps != 0)))) &&
        (((((*(long *)(sps + 0x118) != 0 ||
            (_printk(&DAT_00123193,"print_bam_pipe_selected_reg",uVar39), sps != 0)) &&
           (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_PSM_CNTXT_3_MSB: 0x%x\n",
                           "print_bam_pipe_selected_reg",uVar45), sps != 0)) &&
          (((*(long *)(sps + 0x118) != 0 ||
            (_printk(&DAT_0011ec43,"print_bam_pipe_selected_reg",uVar45), sps != 0)) &&
           (((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_PSM_CNTXT_4: 0x%x\n",
                             "print_bam_pipe_selected_reg",uVar40), sps != 0 &&
             ((*(long *)(sps + 0x118) != 0 ||
              (_printk(&DAT_0011f1b0,"print_bam_pipe_selected_reg",uVar40), sps != 0)))) &&
            (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_PSM_CNTXT_5: 0x%x\n",
                            "print_bam_pipe_selected_reg",uVar41), sps != 0)))))) &&
         ((((((*(long *)(sps + 0x118) != 0 ||
              (_printk(&DAT_001205ab,"print_bam_pipe_selected_reg",uVar41), sps != 0)) &&
             (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_TIMER: 0x%x\n",
                             "print_bam_pipe_selected_reg",0), sps != 0)) &&
            ((*(long *)(sps + 0x118) != 0 ||
             (_printk(&DAT_00123f97,"print_bam_pipe_selected_reg",0), sps != 0)))) &&
           (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_P_TIMER_CTRL: 0x%x\n",
                           "print_bam_pipe_selected_reg",0), sps != 0)) &&
          (((*(long *)(sps + 0x118) != 0 ||
            (_printk(&DAT_001201d9,"print_bam_pipe_selected_reg",0), sps != 0)) &&
           ((ipc_log_string(*(undefined8 *)(sps + 0x118),
                            "%s: \nsps:<pipe-end> --- Registers of Pipe %d ---\n\n",
                            "print_bam_pipe_selected_reg",param_2), sps != 0 &&
            (*(long *)(sps + 0x118) == 0)))))))))))))))) {
    _printk(&DAT_0012520a,"print_bam_pipe_selected_reg",param_2);
  }
  return;
}



//------------------------------------------------------------
// bam_check_irq_source @ 001059f8 size=848
// signature: undefined bam_check_irq_source(void)
// callers: [sps_bam_check_irq]
//------------------------------------------------------------

uint bam_check_irq_source(undefined8 *param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == (undefined8 *)0xd8) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar3 = ___ratelimit(bam_check_irq_source__rs,"bam_check_irq_source"), iVar3 != 0)))) {
      _printk(&DAT_001215d6,"bam_check_irq_source",0xd8);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_check_irq_source",0xd8);
    }
    return 0xffffffff;
  }
  uVar1 = bam_read_reg(param_1,0x18,param_2);
  if (-1 < (int)uVar1) goto LAB_00105c64;
  uVar2 = bam_read_reg(param_1,10,0);
  if ((uVar2 >> 2 & 1) == 0) {
    if ((uVar2 >> 1 & 1) != 0) {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar3 = ___ratelimit(bam_check_irq_source__rs_37,"bam_check_irq_source"), iVar3 != 0))))
      {
        _printk(&DAT_00124501,"bam_check_irq_source",param_1 + -0x18,*param_1,uVar2);
      }
      ipc_log_string(param_1[0x2a],
                     "%s: sps:bam %pa 0x%pK(va);bam irq status=0x%x\nsps: BAM_HRESP_ERR_IRQ\n",
                     "bam_check_irq_source",param_1 + -0x18,*param_1,uVar2);
      bam_output_register_content(param_1,param_2);
      uVar4 = 2;
      goto LAB_00105c4c;
    }
    if ((uVar2 >> 4 & 1) != 0) {
      if (((1 < logging_option) && (2 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar3 = ___ratelimit(bam_check_irq_source__rs_40,"bam_check_irq_source"), iVar3 != 0))))
      {
        _printk(&DAT_00120073,"bam_check_irq_source",*param_1);
      }
      if (*(uint *)(param_1 + 0x2c) < 2) {
        ipc_log_string(param_1[0x28],"%s: sps:bam 0x%pK(va);receive BAM_TIMER_IRQ\n",
                       "bam_check_irq_source",*param_1);
      }
      uVar4 = 3;
      goto LAB_00105c4c;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 2 ||
        (iVar3 = ___ratelimit(bam_check_irq_source__rs_43,"bam_check_irq_source"), iVar3 != 0)))) {
      _printk(&DAT_0011dd93,"bam_check_irq_source",param_1 + -0x18,*param_1,uVar2);
    }
    ipc_log_string(param_1[0x2a],"%s: sps:bam %pa 0x%pK(va);bam irq status=0x%x\n",
                   "bam_check_irq_source",param_1 + -0x18,*param_1,uVar2);
  }
  else {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar3 = ___ratelimit(bam_check_irq_source__rs_34,"bam_check_irq_source"), iVar3 != 0)))) {
      _printk(&DAT_0012345f,"bam_check_irq_source",param_1 + -0x18,*param_1,uVar2);
    }
    ipc_log_string(param_1[0x2a],
                   "%s: sps:bam %pa 0x%pK(va);bam irq status=0x%x\nsps: BAM_ERROR_IRQ\n",
                   "bam_check_irq_source",param_1 + -0x18,*param_1,uVar2);
    bam_output_register_content(param_1,param_2);
    uVar4 = 1;
LAB_00105c4c:
    *param_4 = uVar4;
  }
  bam_write_reg(param_1,0xb,0,uVar2);
LAB_00105c64:
  return uVar1 & (param_3 | 0x80000000);
}



//------------------------------------------------------------
// bam_pipe_reset @ 00105d4c size=372
// signature: undefined bam_pipe_reset(void)
// callers: [sps_pipe_reset]
//------------------------------------------------------------

void bam_pipe_reset(undefined8 *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == (undefined8 *)0xd8) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(bam_pipe_reset__rs,"bam_pipe_reset"), iVar1 != 0)))) {
      _printk(&DAT_001215d6,"bam_pipe_reset",0xd8);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_pipe_reset",0xd8);
    }
  }
  else {
    if (((1 < logging_option) && (1 < debug_level_option)) &&
       ((print_limit_option == 0 ||
        (iVar1 = ___ratelimit(bam_pipe_reset__rs_46,"bam_pipe_reset"), iVar1 != 0)))) {
      _printk(&DAT_0012252e,"bam_pipe_reset",param_1 + -0x18,*param_1,param_2);
    }
    if (*(uint *)(param_1 + 0x2c) < 3) {
      ipc_log_string(param_1[0x29],"%s: sps: bam=%pa 0x%pK(va).pipe=%d\n","bam_pipe_reset",
                     param_1 + -0x18,*param_1,param_2);
    }
    bam_write_reg(param_1,0x1d,param_2,1);
    DataSynchronizationBarrier(3,2,0);
    bam_write_reg(param_1,0x1d,param_2,0);
    DataSynchronizationBarrier(3,2,0);
  }
  return;
}



//------------------------------------------------------------
// bam_disable_pipe @ 00105ec4 size=344
// signature: undefined bam_disable_pipe(void)
// callers: [sps_pipe_disable]
//------------------------------------------------------------

void bam_disable_pipe(long param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == 0xd8) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(bam_disable_pipe__rs,"bam_disable_pipe"), iVar1 != 0)))) {
      _printk(&DAT_001215d6,"bam_disable_pipe",0xd8);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_disable_pipe",0xd8);
    }
  }
  else {
    if (((1 < logging_option) && (1 < debug_level_option)) &&
       ((print_limit_option == 0 ||
        (iVar1 = ___ratelimit(bam_disable_pipe__rs_49,"bam_disable_pipe"), iVar1 != 0)))) {
      _printk(&DAT_00121d23,"bam_disable_pipe",param_1,param_2);
    }
    if (*(uint *)(param_1 + 0x160) < 3) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x148),"%s: sps: bam=0x%pK(va).pipe=%d\n",
                     "bam_disable_pipe",param_1,param_2);
    }
    bam_write_reg_field(param_1,0x1c,param_2,2,0);
    DataSynchronizationBarrier(3,2,0);
  }
  return;
}



//------------------------------------------------------------
// bam_pipe_check_zlt @ 00106020 size=496
// signature: undefined bam_pipe_check_zlt(void)
// callers: [sps_bam_pipe_is_empty]
//------------------------------------------------------------

undefined8 bam_pipe_check_zlt(long param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == 0xd8) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(bam_pipe_check_zlt__rs,"bam_pipe_check_zlt"), iVar1 != 0)))) {
      _printk(&DAT_001215d6,"bam_pipe_check_zlt",0xd8);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_pipe_check_zlt",0xd8);
    }
  }
  else {
    iVar1 = bam_read_reg_field(param_1,0x1e,param_2,4);
    if (iVar1 != 0) {
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar1 = ___ratelimit(bam_pipe_check_zlt__rs_52,"bam_pipe_check_zlt"), iVar1 != 0)))) {
        _printk(&DAT_00124989,"bam_pipe_check_zlt",param_1,param_2);
      }
      if (*(int *)(param_1 + 0x160) == 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x138),
                       "%s: sps: bam=0x%pK(va).pipe=%d: the last desc is ZLT\n","bam_pipe_check_zlt"
                       ,param_1,param_2);
        return 1;
      }
      return 1;
    }
    if (((1 < logging_option) && (3 < debug_level_option)) &&
       ((print_limit_option == 0 ||
        (iVar1 = ___ratelimit(bam_pipe_check_zlt__rs_55,"bam_pipe_check_zlt"), iVar1 != 0)))) {
      _printk(&DAT_00124549,"bam_pipe_check_zlt",param_1,param_2);
    }
    if (*(int *)(param_1 + 0x160) == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x138),
                     "%s: sps: bam=0x%pK(va).pipe=%d: the last desc is not ZLT\n",
                     "bam_pipe_check_zlt",param_1,param_2);
    }
  }
  return 0;
}



//------------------------------------------------------------
// bam_pipe_check_pipe_empty @ 00106214 size=496
// signature: undefined bam_pipe_check_pipe_empty(void)
// callers: [sps_bam_pipe_is_empty]
//------------------------------------------------------------

undefined8 bam_pipe_check_pipe_empty(long param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == 0xd8) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(bam_pipe_check_pipe_empty__rs,"bam_pipe_check_pipe_empty"), iVar1 != 0
        )))) {
      _printk(&DAT_001215d6,"bam_pipe_check_pipe_empty",0xd8);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_pipe_check_pipe_empty",0xd8);
    }
  }
  else {
    iVar1 = bam_read_reg_field(param_1,0x1e,param_2,8);
    if (iVar1 != 0) {
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar1 = ___ratelimit(bam_pipe_check_pipe_empty__rs_58,"bam_pipe_check_pipe_empty"),
          iVar1 != 0)))) {
        _printk(&DAT_0011d9c7,"bam_pipe_check_pipe_empty",param_1,param_2);
      }
      if (*(int *)(param_1 + 0x160) == 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x138),
                       "%s: sps: bam=0x%pK(va).pipe=%d: desc FIFO is empty\n",
                       "bam_pipe_check_pipe_empty",param_1,param_2);
        return 1;
      }
      return 1;
    }
    if (((1 < logging_option) && (3 < debug_level_option)) &&
       ((print_limit_option == 0 ||
        (iVar1 = ___ratelimit(bam_pipe_check_pipe_empty__rs_61,"bam_pipe_check_pipe_empty"),
        iVar1 != 0)))) {
      _printk(&DAT_0011e1a0,"bam_pipe_check_pipe_empty",param_1,param_2);
    }
    if (*(int *)(param_1 + 0x160) == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x138),
                     "%s: sps: bam=0x%pK(va).pipe=%d: desc FIFO is not empty\n",
                     "bam_pipe_check_pipe_empty",param_1,param_2);
    }
  }
  return 0;
}



//------------------------------------------------------------
// bam_pipe_init @ 00106408 size=1432
// signature: undefined bam_pipe_init(void)
// callers: [sps_bam_pipe_connect]
//------------------------------------------------------------

undefined8 bam_pipe_init(undefined8 *param_1,uint param_2,undefined2 *param_3,undefined4 param_4)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  undefined8 uVar7;
  int iVar8;
  
  if (param_1 == (undefined8 *)0xd8) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar6 = ___ratelimit(bam_pipe_init__rs,"bam_pipe_init"), iVar6 != 0)))) {
      _printk(&DAT_001215d6,"bam_pipe_init",0xd8);
    }
    if (sps == 0) {
      uVar7 = 0xffffffff;
    }
    else {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_pipe_init",0xd8);
      uVar7 = 0xffffffff;
    }
  }
  else {
    if (((1 < logging_option) && (1 < debug_level_option)) &&
       ((print_limit_option == 0 ||
        (iVar6 = ___ratelimit(bam_pipe_init__rs_64,"bam_pipe_init"), iVar6 != 0)))) {
      _printk(&DAT_0012252e,"bam_pipe_init",param_1 + -0x18,*param_1,param_2);
    }
    if (*(uint *)(param_1 + 0x2c) < 3) {
      ipc_log_string(param_1[0x29],"%s: sps: bam=%pa 0x%pK(va).pipe=%d\n","bam_pipe_init",
                     param_1 + -0x18,*param_1,param_2);
    }
    bam_write_reg(param_1,0x1d,param_2,1);
    bam_write_reg(param_1,0x1d,param_2,0);
    bam_write_reg_field(param_1,0x19,param_4,1 << (ulong)(param_2 & 0x1f),1);
    bam_write_reg(param_1,0x21,param_2,*(undefined4 *)(param_3 + 2));
    bam_write_reg_field(param_1,0x1c,param_2,8,*(undefined4 *)(param_3 + 4));
    bam_write_reg_field(param_1,0x1c,param_2,0x20,*(undefined4 *)(param_3 + 6));
    bam_write_reg(param_1,0x2e,param_2,*param_3);
    bam_write_reg(param_1,0x2c,param_2,*(undefined4 *)(param_3 + 0xc));
    bam_write_reg_field(param_1,0x2f,param_2,0xffff,*(undefined4 *)(param_3 + 0x10));
    bam_write_reg_field(param_1,0x1c,param_2,0x10,*(undefined4 *)(param_3 + 0x14));
    if ((*(uint *)(param_3 + 0xe) & 0xf) != 0) {
      bam_write_reg(param_1,0x2d,param_2,*(uint *)(param_3 + 0xe) & 0xf);
    }
    bam_write_reg_field(param_1,0x1c,param_2,0x1f0000,*(undefined4 *)(param_3 + 0x12));
    if (((1 < logging_option) && (3 < debug_level_option)) &&
       ((print_limit_option == 0 ||
        (iVar6 = ___ratelimit(bam_pipe_init__rs_65,"bam_pipe_init"), iVar6 != 0)))) {
      _printk(&DAT_00121a30,"bam_pipe_init",*param_1,param_2,*(undefined4 *)(param_3 + 0x12));
    }
    if (*(int *)(param_1 + 0x2c) == 0) {
      ipc_log_string(param_1[0x27],"%s: sps:bam=0x%pK(va).pipe=%d.lock_group=%d\n","bam_pipe_init",
                     *param_1,param_2,*(undefined4 *)(param_3 + 0x12));
      iVar6 = *(int *)(param_3 + 6);
      uVar4 = bam_type;
    }
    else {
      iVar6 = *(int *)(param_3 + 6);
      uVar4 = bam_type;
    }
    bam_type = uVar4;
    if (iVar6 == 0) {
      if (3 < uVar4) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x106930);
        (*pcVar5)();
      }
      if ((0x220 < (ulong)uVar4 * 0xec) || (0x224 < (ulong)uVar4 * 0xec)) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(1,0x10692c);
        (*pcVar5)();
      }
      iVar2 = *(int *)(param_3 + 0x18);
      iVar3 = *(int *)(param_3 + 0x1a);
      iVar6 = *(int *)(bam_regmap + (ulong)uVar4 * 0xec + 0xa0);
      bam_write_reg(param_1,0x2a,param_2,*(undefined4 *)(param_3 + 0x1c));
      bam_write_reg_field(param_1,0x2f,param_2,0xffff0000,*(undefined4 *)(param_3 + 0x20));
      if (*(char *)(param_3 + 0x22) == '\0') {
        iVar8 = 0x40;
        if (uVar4 != 0) {
          iVar8 = 0x1000;
        }
        iVar6 = iVar2 + iVar8 * iVar3 + iVar6;
      }
      else {
        iVar6 = *(int *)(param_3 + 0x18);
      }
      bam_write_reg(param_1,0x26,param_2,iVar6);
      if (((1 < logging_option) && (1 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar6 = ___ratelimit(bam_pipe_init__rs_68,"bam_pipe_init"), iVar6 != 0)))) {
        _printk(&DAT_0011cfd3,"bam_pipe_init",*param_1,param_2,*(undefined4 *)(param_3 + 0x18),
                *(undefined4 *)(param_3 + 0x1a));
      }
      if (*(uint *)(param_1 + 0x2c) < 3) {
        ipc_log_string(param_1[0x29],"%s: sps:bam=0x%pK(va).pipe=%d.peer_bam=0x%x.peer_pipe=%d\n",
                       "bam_pipe_init",*param_1,param_2,*(undefined4 *)(param_3 + 0x18),
                       *(undefined4 *)(param_3 + 0x1a));
      }
      if ((*(byte *)(param_3 + 0x1e) & 0xf) != 0) {
        bam_write_reg(param_1,0x27,param_2,0);
        bam_write_reg(param_1,0x2b,param_2,*(uint *)(param_3 + 0x1e) & 0xf);
      }
      bam_write_reg_field(param_1,0x1c,param_2,0x800,*(undefined4 *)(param_3 + 8));
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar6 = ___ratelimit(bam_pipe_init__rs_71,"bam_pipe_init"), iVar6 != 0)))) {
        pcVar1 = "Do not set";
        if (*(int *)(param_3 + 8) != 0) {
          pcVar1 = "Set";
        }
        _printk(&DAT_0011d00f,"bam_pipe_init",pcVar1);
      }
      if (*(int *)(param_1 + 0x2c) == 0) {
        pcVar1 = "Do not set";
        if (*(int *)(param_3 + 8) != 0) {
          pcVar1 = "Set";
        }
        ipc_log_string(param_1[0x27],"%s: sps:%s WRITE_NWD bit for this bam2bam pipe\n",
                       "bam_pipe_init",pcVar1);
      }
    }
    bam_write_reg_field(param_1,0x1c,param_2,2,1);
    uVar7 = 0;
  }
  return uVar7;
}



//------------------------------------------------------------
// bam_get_register_offset @ 001069a0 size=500
// signature: undefined bam_get_register_offset(void)
// callers: [bam_write_reg, bam_read_reg_field, bam_write_reg_field, bam_read_reg]
//------------------------------------------------------------

int bam_get_register_offset(long param_1,uint param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  
  if (3 < bam_type) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x106b90);
    (*pcVar1)();
  }
  if (param_1 == 0xd8) {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(bam_get_register_offset__rs,"bam_get_register_offset"), iVar2 != 0))))
    {
      _printk(&DAT_001215d6,"bam_get_register_offset",0xd8);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_get_register_offset",0xd8);
      return -1;
    }
LAB_00106b00:
    iVar2 = -1;
  }
  else {
    iVar2 = 0x1000;
    if (bam_type != 2) {
      iVar2 = 0x80;
    }
    iVar3 = -(uint)(0x17 < param_2);
    if ((param_2 & 0xfffffffc) == 0x18) {
      iVar3 = iVar2;
    }
    if (param_2 - 0x1c < 0x1e) {
      if (bam_type == 0) {
        iVar3 = 0x40;
        if (param_2 < 0x26) {
          iVar3 = 0x80;
        }
      }
      else {
        iVar3 = 0x1000;
      }
    }
    else if (param_2 == 0x3a) {
      iVar2 = 4;
      if (bam_type != 2) {
        iVar2 = 0x1000;
      }
      iVar3 = 0x80;
      if (bam_type != 0) {
        iVar3 = iVar2;
      }
    }
    else if ((0x17 < param_2) && ((param_2 & 0xfffffffc) != 0x18)) {
      if ((logging_option != '\x01') &&
         ((print_limit_option < 3 ||
          (iVar2 = ___ratelimit(bam_get_register_offset__rs_314,"bam_get_register_offset"),
          iVar2 != 0)))) {
        _printk(&DAT_00121a9e,"bam_get_register_offset",param_2);
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x150),"%s: Failed to find register offset for %d\n",
                     "bam_get_register_offset",param_2);
      goto LAB_00106b00;
    }
    if (0x2c0 < (ulong)bam_type * 0xec + (ulong)param_2 * 4) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(1,0x106b94);
      (*pcVar1)();
    }
    iVar2 = *(int *)(bam_regmap + (ulong)param_2 * 4 + (ulong)bam_type * 0xec) + iVar3 * param_3;
  }
  return iVar2;
}



//------------------------------------------------------------
// bam_pipe_exit @ 00106b98 size=408
// signature: undefined bam_pipe_exit(void)
// callers: [sps_bam_pipe_disconnect, sps_bam_pipe_connect]
//------------------------------------------------------------

void bam_pipe_exit(undefined8 *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_1 == (undefined8 *)0xd8) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(bam_pipe_exit__rs,"bam_pipe_exit"), iVar1 != 0)))) {
      _printk(&DAT_001215d6,"bam_pipe_exit",0xd8);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_pipe_exit",0xd8);
    }
  }
  else {
    if (((1 < logging_option) && (1 < debug_level_option)) &&
       ((print_limit_option == 0 ||
        (iVar1 = ___ratelimit(bam_pipe_exit__rs_76,"bam_pipe_exit"), iVar1 != 0)))) {
      _printk(&DAT_0012252e,"bam_pipe_exit",param_1 + -0x18,*param_1,param_2);
    }
    if (*(uint *)(param_1 + 0x2c) < 3) {
      ipc_log_string(param_1[0x29],"%s: sps: bam=%pa 0x%pK(va).pipe=%d\n","bam_pipe_exit",
                     param_1 + -0x18,*param_1,param_2);
    }
    bam_write_reg(param_1,0x21,param_2,0);
    bam_write_reg_field(param_1,0x19,param_3,1 << (ulong)(param_2 & 0x1f),0);
    bam_write_reg_field(param_1,0x1c,param_2,2,0);
  }
  return;
}



//------------------------------------------------------------
// bam_pipe_enable @ 00106d34 size=528
// signature: undefined bam_pipe_enable(void)
// callers: [sps_bam_pipe_enable]
//------------------------------------------------------------

void bam_pipe_enable(undefined8 *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == (undefined8 *)0xd8) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(bam_pipe_enable__rs,"bam_pipe_enable"), iVar1 != 0)))) {
      _printk(&DAT_001215d6,"bam_pipe_enable",0xd8);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_pipe_enable",0xd8);
    }
  }
  else {
    if (((1 < logging_option) && (1 < debug_level_option)) &&
       ((print_limit_option == 0 ||
        (iVar1 = ___ratelimit(bam_pipe_enable__rs_77,"bam_pipe_enable"), iVar1 != 0)))) {
      _printk(&DAT_0012252e,"bam_pipe_enable",param_1 + -0x18,*param_1,param_2);
    }
    if (*(uint *)(param_1 + 0x2c) < 3) {
      ipc_log_string(param_1[0x29],"%s: sps: bam=%pa 0x%pK(va).pipe=%d\n","bam_pipe_enable",
                     param_1 + -0x18,*param_1,param_2);
    }
    iVar1 = bam_read_reg_field(param_1,0x1c,param_2,2);
    if (iVar1 == 0) {
      bam_write_reg_field(param_1,0x1c,param_2,2,1);
    }
    else {
      if (((1 < logging_option) && (1 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar1 = ___ratelimit(bam_pipe_enable__rs_78,"bam_pipe_enable"), iVar1 != 0)))) {
        _printk(&DAT_0011f0c7,"bam_pipe_enable",*param_1,param_2);
      }
      if (*(uint *)(param_1 + 0x2c) < 3) {
        ipc_log_string(param_1[0x29],"%s: sps:bam=0x%pK(va).pipe=%d is already enabled\n",
                       "bam_pipe_enable",*param_1,param_2);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// bam_pipe_disable @ 00106f48 size=348
// signature: undefined bam_pipe_disable(void)
// callers: [sps_bam_pipe_disable]
//------------------------------------------------------------

void bam_pipe_disable(undefined8 *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == (undefined8 *)0xd8) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(bam_pipe_disable__rs,"bam_pipe_disable"), iVar1 != 0)))) {
      _printk(&DAT_001215d6,"bam_pipe_disable",0xd8);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_pipe_disable",0xd8);
    }
  }
  else {
    if (((1 < logging_option) && (1 < debug_level_option)) &&
       ((print_limit_option == 0 ||
        (iVar1 = ___ratelimit(bam_pipe_disable__rs_81,"bam_pipe_disable"), iVar1 != 0)))) {
      _printk(&DAT_0012252e,"bam_pipe_disable",param_1 + -0x18,*param_1,param_2);
    }
    if (*(uint *)(param_1 + 0x2c) < 3) {
      ipc_log_string(param_1[0x29],"%s: sps: bam=%pa 0x%pK(va).pipe=%d\n","bam_pipe_disable",
                     param_1 + -0x18,*param_1,param_2);
    }
    bam_write_reg_field(param_1,0x1c,param_2,2,0);
  }
  return;
}



//------------------------------------------------------------
// bam_pipe_is_enabled @ 001070a8 size=40
// signature: undefined bam_pipe_is_enabled(void)
// callers: [sps_bam_pipe_connect]
//------------------------------------------------------------

void bam_pipe_is_enabled(undefined8 param_1,undefined4 param_2)

{
  bam_read_reg_field(param_1,0x1c,param_2,2);
  return;
}



//------------------------------------------------------------
// bam_pipe_set_irq @ 001070d4 size=804
// signature: undefined bam_pipe_set_irq(void)
// callers: [sps_bam_enable_all_irqs, sps_bam_disable_all_irqs, pipe_set_irq, sps_bam_set_satellite]
//------------------------------------------------------------

void bam_pipe_set_irq(undefined8 *param_1,uint param_2,undefined4 param_3,uint param_4,
                     undefined4 param_5)

{
  int iVar1;
  
  if (param_1 == (undefined8 *)0xd8) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(bam_pipe_set_irq__rs,"bam_pipe_set_irq"), iVar1 != 0)))) {
      _printk(&DAT_001215d6,"bam_pipe_set_irq",0xd8);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: Failed to get dev for base addr 0x%pK\n",
                     "bam_pipe_set_irq",0xd8);
    }
  }
  else {
    if (((1 < logging_option) && (1 < debug_level_option)) &&
       ((print_limit_option == 0 ||
        (iVar1 = ___ratelimit(bam_pipe_set_irq__rs_82,"bam_pipe_set_irq"), iVar1 != 0)))) {
      _printk(&DAT_0011fbc7,"bam_pipe_set_irq",param_1 + -0x18,*param_1,param_2,param_3,param_4,
              param_5);
    }
    if (*(uint *)(param_1 + 0x2c) < 3) {
      ipc_log_string(param_1[0x29],
                     "%s: sps: bam=%pa 0x%pK(va).pipe=%d; irq_en:%d; src_mask:0x%x; ee:%d\n",
                     "bam_pipe_set_irq",param_1 + -0x18,*param_1,param_2,param_3,param_4,param_5);
    }
    if ((param_4 >> 6 & 1) != 0) {
      if (enhd_pipe == '\0') {
        param_4 = param_4 & 0xffffffbf;
        if (((1 < logging_option) && (1 < debug_level_option)) &&
           ((print_limit_option == 0 ||
            (iVar1 = ___ratelimit(bam_pipe_set_irq__rs_85,"bam_pipe_set_irq"), iVar1 != 0)))) {
          _printk(&DAT_001200dc,"bam_pipe_set_irq",param_2);
        }
        if (*(uint *)(param_1 + 0x2c) < 3) {
          ipc_log_string(param_1[0x29],"%s: SPS_O_RST_ERROR is not supported, pipe %d\n",
                         "bam_pipe_set_irq",param_2);
        }
      }
      else {
        bam_write_reg_field(param_1,0xc,0,4,0);
      }
    }
    if ((param_4 >> 7 & 1) != 0) {
      if (enhd_pipe == '\0') {
        param_4 = param_4 & 0xffffff7f;
        if (((1 < logging_option) && (1 < debug_level_option)) &&
           ((print_limit_option == 0 ||
            (iVar1 = ___ratelimit(bam_pipe_set_irq__rs_88,"bam_pipe_set_irq"), iVar1 != 0)))) {
          _printk(&DAT_00122c89,"bam_pipe_set_irq",param_2);
        }
        if (*(uint *)(param_1 + 0x2c) < 3) {
          ipc_log_string(param_1[0x29],"%s: SPS_O_HRESP_ERROR is not supported, pipe %d\n",
                         "bam_pipe_set_irq",param_2);
        }
      }
      else {
        bam_write_reg_field(param_1,0xc,0,2,0);
      }
    }
    bam_write_reg(param_1,0x21,param_2,param_4);
    bam_write_reg_field(param_1,0x19,param_5,1 << (ulong)(param_2 & 0x1f),param_3);
  }
  return;
}



//------------------------------------------------------------
// bam_pipe_satellite_mti @ 001073fc size=84
// signature: undefined bam_pipe_satellite_mti(void)
// callers: [sps_bam_set_satellite, sps_bam_enable]
//------------------------------------------------------------

void bam_pipe_satellite_mti(undefined8 param_1,uint param_2)

{
  bam_write_reg(param_1,0x21,param_2,0);
  bam_write_reg_field(param_1,8,0,1 << (ulong)(param_2 & 0x1f),1);
  return;
}



//------------------------------------------------------------
// bam_pipe_set_mti @ 00107454 size=48
// signature: undefined bam_pipe_set_mti(void)
// callers: [pipe_set_irq]
//------------------------------------------------------------

void bam_pipe_set_mti(undefined8 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_3 != 0) {
    uVar1 = param_4;
  }
  bam_write_reg(param_1,0x21,param_2,uVar1);
  return;
}



//------------------------------------------------------------
// bam_pipe_get_and_clear_irq_status @ 00107488 size=88
// signature: undefined bam_pipe_get_and_clear_irq_status(void)
// callers: [sps_bam_check_irq, pipe_set_irq]
//------------------------------------------------------------

undefined4 bam_pipe_get_and_clear_irq_status(undefined8 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = bam_read_reg(param_1,0x1f,param_2);
  bam_write_reg(param_1,0x20,param_2,uVar1);
  return uVar1;
}



//------------------------------------------------------------
// bam_pipe_set_desc_write_offset @ 001074e4 size=44
// signature: undefined bam_pipe_set_desc_write_offset(void)
// callers: [sps_bam_pipe_transfer_one, sps_bam_pipe_inject_zlt]
//------------------------------------------------------------

void bam_pipe_set_desc_write_offset(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  bam_write_reg_field(param_1,0x28,param_2,0xffff,param_3);
  return;
}



//------------------------------------------------------------
// bam_pipe_get_desc_write_offset @ 00107514 size=40
// signature: undefined bam_pipe_get_desc_write_offset(void)
// callers: [sps_bam_pipe_transfer_one, sps_bam_pipe_get_unused_desc_num, sps_bam_pipe_is_empty, sps_bam_pipe_pending_desc, pipe_handler_eot, sps_bam_pipe_inject_zlt]
//------------------------------------------------------------

void bam_pipe_get_desc_write_offset(undefined8 param_1,undefined4 param_2)

{
  bam_read_reg_field(param_1,0x28,param_2,0xffff);
  return;
}



//------------------------------------------------------------
// bam_pipe_get_desc_read_offset @ 00107540 size=40
// signature: undefined bam_pipe_get_desc_read_offset(void)
// callers: [sps_bam_pipe_get_iovec, sps_bam_pipe_get_unused_desc_num, sps_bam_pipe_is_empty, sps_bam_pipe_pending_desc, pipe_handler_eot, sps_bam_pipe_inject_zlt]
//------------------------------------------------------------

void bam_pipe_get_desc_read_offset(undefined8 param_1,undefined4 param_2)

{
  bam_read_reg_field(param_1,0x29,param_2,0xffff);
  return;
}



//------------------------------------------------------------
// bam_pipe_halt @ 0010756c size=48
// signature: undefined bam_pipe_halt(void)
// callers: [sps_flow_on, sps_flow_off]
//------------------------------------------------------------

void bam_pipe_halt(undefined8 param_1,undefined4 param_2,uint param_3)

{
  bam_write_reg_field(param_1,0x1e,param_2,1,param_3 & 1);
  return;
}



//------------------------------------------------------------
// print_bam_reg @ 001075a0 size=948
// signature: undefined print_bam_reg(void)
// callers: [sps_get_bam_debug_info, sps_set_bam_addr]
//------------------------------------------------------------

void print_bam_reg(undefined4 *param_1)

{
  undefined4 *puVar1;
  ulong uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  uint uVar9;
  int iVar10;
  ulong uVar11;
  int iVar12;
  
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  lVar7 = 0x1008;
  if (bam_type != 2) {
    lVar7 = 0x3c;
  }
  lVar8 = 0x1000;
  if (bam_type != 2) {
    lVar8 = 4;
  }
  if (sps != 0) {
    uVar4 = *(undefined4 *)((long)param_1 + lVar8);
    uVar5 = *(undefined4 *)((long)param_1 + lVar7);
    uVar3 = *param_1;
    ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: %s","print_bam_reg",
                   "\nsps:<bam-begin> --- Content of BAM-level registers---\n");
    if (((sps != 0) &&
        ((((*(long *)(sps + 0x118) != 0 ||
           (_printk(&DAT_0012561d,"print_bam_reg",
                    "\nsps:<bam-begin> --- Content of BAM-level registers---\n"), sps != 0)) &&
          (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_CTRL: 0x%x\n","print_bam_reg",uVar3)
          , sps != 0)) &&
         ((*(long *)(sps + 0x118) != 0 || (_printk(&DAT_00121d5f,"print_bam_reg",uVar3), sps != 0)))
         ))) && ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: BAM_REVISION: 0x%x\n",
                                 "print_bam_reg",uVar4), sps != 0 &&
                 (((*(long *)(sps + 0x118) != 0 ||
                   (_printk(&DAT_0011e737,"print_bam_reg",uVar4), sps != 0)) &&
                  ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: NUM_PIPES: 0x%x\n",
                                   "print_bam_reg",uVar5), sps != 0 && (*(long *)(sps + 0x118) == 0)
                   ))))))) {
      _printk(&DAT_00124ca2,"print_bam_reg",uVar5);
    }
  }
  uVar11 = 0;
  uVar2 = 0x301c;
  lVar7 = sps;
  lVar8 = sps;
  if (bam_type != 2) {
    uVar2 = 0x80;
  }
  do {
    if (lVar8 != 0) {
      puVar1 = (undefined4 *)((long)param_1 + uVar11);
      ipc_log_string(*(undefined8 *)(lVar8 + 0x118),"%s: bam addr 0x%x: 0x%x,0x%x,0x%x,0x%x\n",
                     "print_bam_reg",uVar11 & 0xffffffff,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
      lVar7 = sps;
      if (sps == 0) {
        lVar8 = 0;
      }
      else {
        lVar8 = sps;
        if (*(long *)(sps + 0x118) == 0) {
          _printk(&DAT_00123b99,"print_bam_reg",uVar11 & 0xffffffff,
                  *(undefined4 *)((long)param_1 + uVar11),puVar1[1],puVar1[2],puVar1[3]);
          lVar7 = sps;
          lVar8 = sps;
        }
      }
    }
    uVar11 = uVar11 + 0x10;
  } while (uVar11 < uVar2);
  uVar9 = 0x3000;
  if (bam_type != 2) {
    uVar9 = 0x800;
  }
  iVar10 = 0x1000;
  if (bam_type != 2) {
    iVar10 = 0x80;
  }
  iVar12 = 1;
  lVar8 = lVar7;
  do {
    while (lVar8 == 0) {
LAB_001077e8:
      iVar12 = iVar12 + 1;
      if (iVar12 == 9) {
        if (lVar7 == 0) {
          return;
        }
        ipc_log_string(*(undefined8 *)(lVar7 + 0x118),"%s: %s","print_bam_reg",
                       "\nsps:<bam-begin> --- Content of BAM-level registers ---\n");
        if (sps == 0) {
          return;
        }
        if (*(long *)(sps + 0x118) == 0) {
          _printk(&DAT_0012561d,"print_bam_reg",
                  "\nsps:<bam-begin> --- Content of BAM-level registers ---\n");
          return;
        }
        return;
      }
      uVar9 = uVar9 + iVar10;
    }
    uVar6 = uVar9 >> 2;
    ipc_log_string(*(undefined8 *)(lVar8 + 0x118),"%s: bam addr 0x%x: 0x%x,0x%x,0x%x,0x%x\n",
                   "print_bam_reg",uVar9,param_1[uVar6],param_1[uVar6 | 1],param_1[uVar6 | 2],
                   param_1[uVar6 | 3]);
    if (sps != 0) {
      lVar7 = sps;
      lVar8 = sps;
      if (*(long *)(sps + 0x118) == 0) {
        _printk(&DAT_00123b99,"print_bam_reg",uVar9,param_1[uVar6],param_1[uVar6 | 1],
                param_1[uVar6 | 2],param_1[uVar6 | 3]);
        lVar7 = sps;
        lVar8 = sps;
      }
      goto LAB_001077e8;
    }
    iVar12 = iVar12 + 1;
    if (iVar12 == 9) {
      return;
    }
    lVar7 = 0;
    lVar8 = 0;
    uVar9 = uVar9 + iVar10;
  } while( true );
}



//------------------------------------------------------------
// print_bam_pipe_reg @ 00107958 size=1316
// signature: undefined print_bam_pipe_reg(void)
// callers: [sps_get_bam_debug_info, sps_set_bam_addr]
//------------------------------------------------------------

void print_bam_pipe_reg(long param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  
  if (param_1 == 0) {
    return;
  }
  if ((((sps != 0) &&
       (ipc_log_string(*(undefined8 *)(sps + 0x118),
                       "%s: \nsps:<pipe-begin> --- Content of Pipe %d registers ---\n",
                       "print_bam_pipe_reg",param_2), sps != 0)) &&
      ((*(long *)(sps + 0x118) != 0 ||
       (_printk(&DAT_001234a3,"print_bam_pipe_reg",param_2), sps != 0)))) &&
     ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: %s","print_bam_pipe_reg",
                      "-- Pipe Management Registers --\n"), sps != 0 &&
      (*(long *)(sps + 0x118) == 0)))) {
    _printk(&DAT_0012561d,"print_bam_pipe_reg","-- Pipe Management Registers --\n");
  }
  iVar4 = 0x13000;
  if (bam_type != 2) {
    iVar4 = 0x1000;
  }
  uVar1 = iVar4 + param_2 * 0x1000;
  uVar2 = uVar1 | 0x80;
  lVar5 = sps;
  if (uVar1 < uVar2) {
    lVar6 = sps;
    do {
      if (lVar6 != 0) {
        uVar3 = (long)((ulong)uVar1 << 0x20) >> 0x22;
        ipc_log_string(*(undefined8 *)(lVar6 + 0x118),"%s: bam addr 0x%x: 0x%x,0x%x,0x%x,0x%x\n",
                       "print_bam_pipe_reg",uVar1,
                       *(undefined4 *)(param_1 + (long)((int)uVar1 >> 2) * 4),
                       *(undefined4 *)(param_1 + (uVar3 | 1) * 4),
                       *(undefined4 *)(param_1 + (uVar3 | 2) * 4),
                       *(undefined4 *)(param_1 + (uVar3 | 3) * 4));
        lVar5 = sps;
        if (sps == 0) {
          lVar6 = 0;
        }
        else {
          lVar6 = sps;
          if (*(long *)(sps + 0x118) == 0) {
            _printk(&DAT_00123b99,"print_bam_pipe_reg",uVar1,*(undefined4 *)(param_1 + uVar3 * 4),
                    *(undefined4 *)(param_1 + (uVar3 | 1) * 4),
                    *(undefined4 *)(param_1 + (uVar3 | 2) * 4),
                    *(undefined4 *)(param_1 + (uVar3 | 3) * 4));
            lVar5 = sps;
            lVar6 = sps;
          }
        }
      }
      uVar1 = uVar1 + 0x10;
    } while (uVar1 < uVar2);
  }
  if (((lVar5 != 0) &&
      (ipc_log_string(*(undefined8 *)(lVar5 + 0x118),"%s: %s","print_bam_pipe_reg",
                      "-- Pipe Configuration and Internal State Registers --\n"), sps != 0)) &&
     (*(long *)(sps + 0x118) == 0)) {
    _printk(&DAT_0012561d,"print_bam_pipe_reg",
            "-- Pipe Configuration and Internal State Registers --\n");
  }
  iVar4 = 0x13800;
  if (bam_type != 2) {
    iVar4 = 0x1800;
  }
  uVar1 = iVar4 + param_2 * 0x1000;
  if (uVar1 < (uVar1 | 0x40)) {
    if (sps != 0) {
      uVar3 = (long)((ulong)uVar1 << 0x20) >> 0x22;
      ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: bam addr 0x%x: 0x%x,0x%x,0x%x,0x%x\n",
                     "print_bam_pipe_reg",uVar1,
                     *(undefined4 *)(param_1 + (long)((int)uVar1 >> 2) * 4),
                     *(undefined4 *)(param_1 + (uVar3 | 1) * 4),
                     *(undefined4 *)(param_1 + (uVar3 | 2) * 4),
                     *(undefined4 *)(param_1 + (uVar3 | 3) * 4));
      if ((sps != 0) && (*(long *)(sps + 0x118) == 0)) {
        _printk(&DAT_00123b99,"print_bam_pipe_reg",uVar1,*(undefined4 *)(param_1 + uVar3 * 4),
                *(undefined4 *)(param_1 + (uVar3 | 1) * 4),
                *(undefined4 *)(param_1 + (uVar3 | 2) * 4),
                *(undefined4 *)(param_1 + (uVar3 | 3) * 4));
      }
    }
    uVar2 = uVar1 | 0x10;
    if (uVar2 < (uVar1 | 0x40)) {
      if (sps == 0) {
        return;
      }
      uVar3 = (long)((ulong)uVar2 << 0x20) >> 0x22;
      ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: bam addr 0x%x: 0x%x,0x%x,0x%x,0x%x\n",
                     "print_bam_pipe_reg",uVar2,
                     *(undefined4 *)(param_1 + (long)((int)uVar2 >> 2) * 4),
                     *(undefined4 *)(param_1 + (uVar3 | 1) * 4),
                     *(undefined4 *)(param_1 + (uVar3 | 2) * 4),
                     *(undefined4 *)(param_1 + (uVar3 | 3) * 4));
      if (sps == 0) {
        return;
      }
      if ((*(long *)(sps + 0x118) == 0) &&
         (_printk(&DAT_00123b99,"print_bam_pipe_reg",uVar2,*(undefined4 *)(param_1 + uVar3 * 4),
                  *(undefined4 *)(param_1 + (uVar3 | 1) * 4),
                  *(undefined4 *)(param_1 + (uVar3 | 2) * 4),
                  *(undefined4 *)(param_1 + (uVar3 | 3) * 4)), sps == 0)) {
        return;
      }
      uVar2 = uVar1 | 0x20;
      uVar3 = (long)((ulong)uVar2 << 0x20) >> 0x22;
      ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: bam addr 0x%x: 0x%x,0x%x,0x%x,0x%x\n",
                     "print_bam_pipe_reg",uVar2,
                     *(undefined4 *)(param_1 + (long)((int)uVar2 >> 2) * 4),
                     *(undefined4 *)(param_1 + (uVar3 | 1) * 4),
                     *(undefined4 *)(param_1 + (uVar3 | 2) * 4),
                     *(undefined4 *)(param_1 + (uVar3 | 3) * 4));
      if (sps == 0) {
        return;
      }
      if ((*(long *)(sps + 0x118) == 0) &&
         (_printk(&DAT_00123b99,"print_bam_pipe_reg",uVar2,*(undefined4 *)(param_1 + uVar3 * 4),
                  *(undefined4 *)(param_1 + (uVar3 | 1) * 4),
                  *(undefined4 *)(param_1 + (uVar3 | 2) * 4),
                  *(undefined4 *)(param_1 + (uVar3 | 3) * 4)), sps == 0)) {
        return;
      }
      uVar1 = uVar1 | 0x30;
      uVar3 = (long)((ulong)uVar1 << 0x20) >> 0x22;
      ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: bam addr 0x%x: 0x%x,0x%x,0x%x,0x%x\n",
                     "print_bam_pipe_reg",uVar1,
                     *(undefined4 *)(param_1 + (long)((int)uVar1 >> 2) * 4),
                     *(undefined4 *)(param_1 + (uVar3 | 1) * 4),
                     *(undefined4 *)(param_1 + (uVar3 | 2) * 4),
                     *(undefined4 *)(param_1 + (uVar3 | 3) * 4));
      if (sps == 0) {
        return;
      }
      if (*(long *)(sps + 0x118) == 0) {
        _printk(&DAT_00123b99,"print_bam_pipe_reg",uVar1,*(undefined4 *)(param_1 + uVar3 * 4),
                *(undefined4 *)(param_1 + (uVar3 | 1) * 4),
                *(undefined4 *)(param_1 + (uVar3 | 2) * 4),
                *(undefined4 *)(param_1 + (uVar3 | 3) * 4));
      }
    }
  }
  if (((sps != 0) &&
      (ipc_log_string(*(undefined8 *)(sps + 0x118),
                      "%s: \nsps:<pipe-end> --- Content of Pipe %d registers ---\n",
                      "print_bam_pipe_reg",param_2), sps != 0)) && (*(long *)(sps + 0x118) == 0)) {
    _printk(&DAT_00123107,"print_bam_pipe_reg",param_2);
  }
  return;
}



//------------------------------------------------------------
// print_bam_pipe_desc_fifo @ 00107e80 size=2552
// signature: undefined print_bam_pipe_desc_fifo(void)
// callers: [sps_get_bam_debug_info, sps_set_bam_addr]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void print_bam_pipe_desc_fifo(long param_1,undefined4 param_2,uint param_3)

{
  ulong uVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined8 uVar9;
  char *pcVar10;
  long lVar11;
  long lVar12;
  ulong uVar13;
  uint uVar14;
  undefined4 *puVar15;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  if (param_1 == 0) goto LAB_00108248;
  uVar4 = bam_read_reg(param_1,0x2c,param_2);
  uVar5 = bam_read_reg_field(param_1,0x2f,param_2,0xffff);
  if (uVar4 == 0) {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar8 = ___ratelimit(print_bam_pipe_desc_fifo__rs,"print_bam_pipe_desc_fifo"), iVar8 != 0))
       )) {
      _printk(&DAT_001249d9,"print_bam_pipe_desc_fifo",param_2);
    }
    if (sps == 0) goto LAB_00108248;
    uVar9 = *(undefined8 *)(sps + 0x110);
    pcVar10 = "%s: sps: desc FIFO address of Pipe %d is NULL\n";
  }
  else {
    if (uVar5 != 0) {
      if ((((sps != 0) &&
           (ipc_log_string(*(undefined8 *)(sps + 0x118),
                           "%s: \nsps:<desc-begin> --- descriptor FIFO of Pipe %d -----\n\n",
                           "print_bam_pipe_desc_fifo",param_2), sps != 0)) &&
          ((*(long *)(sps + 0x118) != 0 ||
           (_printk(&DAT_0011f1cf,"print_bam_pipe_desc_fifo",param_2), sps != 0)))) &&
         ((ipc_log_string(*(undefined8 *)(sps + 0x118),
                          "%s: BAM_P_DESC_FIFO_ADDR: 0x%x\nBAM_P_DESC_FIFO_SIZE: 0x%x (%d)\n\n",
                          "print_bam_pipe_desc_fifo",uVar4,uVar5,uVar5), sps != 0 &&
          (*(long *)(sps + 0x118) == 0)))) {
        _printk(&DAT_0011de12,"print_bam_pipe_desc_fifo",uVar4,uVar5,uVar5);
      }
      uVar13 = (ulong)uVar4 - _memstart_addr | 0xffffff8000000000;
      if (param_3 == 0) {
        if (((sps != 0) &&
            (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: %s","print_bam_pipe_desc_fifo",
                            "---------------- begin of FIFO ----------------\n\n"), sps != 0)) &&
           (*(long *)(sps + 0x118) == 0)) {
          _printk(&DAT_0012561d,"print_bam_pipe_desc_fifo",
                  "---------------- begin of FIFO ----------------\n\n");
        }
        uVar14 = 0;
        lVar11 = sps;
        lVar12 = sps;
LAB_001082ec:
        do {
          if (lVar12 != 0) {
            uVar1 = (long)((ulong)uVar14 << 0x20) >> 0x22;
            ipc_log_string(*(undefined8 *)(lVar12 + 0x118),"%s: addr 0x%x: 0x%x, 0x%x, 0x%x, 0x%x\n"
                           ,"print_bam_pipe_desc_fifo",uVar14 + uVar4,
                           *(undefined4 *)(uVar13 + (long)((int)uVar14 >> 2) * 4),
                           *(undefined4 *)(uVar13 + (uVar1 | 1) * 4),
                           *(undefined4 *)(uVar13 + (uVar1 | 2) * 4),
                           *(undefined4 *)(uVar13 + (uVar1 | 3) * 4));
            lVar11 = sps;
            if (sps == 0) {
              lVar12 = 0;
              uVar14 = uVar14 + 0x10;
              if (uVar5 <= uVar14) goto LAB_00108248;
              goto LAB_001082ec;
            }
            lVar12 = sps;
            if (*(long *)(sps + 0x118) == 0) {
              _printk(&DAT_00125261,"print_bam_pipe_desc_fifo",uVar14 + uVar4,
                      *(undefined4 *)(uVar13 + uVar1 * 4),*(undefined4 *)(uVar13 + (uVar1 | 1) * 4),
                      *(undefined4 *)(uVar13 + (uVar1 | 2) * 4),
                      *(undefined4 *)(uVar13 + (uVar1 | 3) * 4));
              lVar11 = sps;
              lVar12 = sps;
            }
          }
          uVar14 = uVar14 + 0x10;
        } while (uVar14 < uVar5);
        if ((lVar11 == 0) ||
           (ipc_log_string(*(undefined8 *)(lVar11 + 0x118),"%s: %s","print_bam_pipe_desc_fifo",
                           "\n----------------  end of FIFO  ----------------\n"), sps == 0))
        goto LAB_00108248;
        if (*(long *)(sps + 0x118) == 0) {
          pcVar10 = "\n----------------  end of FIFO  ----------------\n";
          goto LAB_001087f8;
        }
      }
      else if (param_3 == 100) {
        if (((sps != 0) &&
            (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: %s","print_bam_pipe_desc_fifo",
                            "----- start of data blocks -----\n"), sps != 0)) &&
           (*(long *)(sps + 0x118) == 0)) {
          _printk(&DAT_0012561d,"print_bam_pipe_desc_fifo","----- start of data blocks -----\n");
        }
        uVar14 = 0;
        do {
          lVar11 = _memstart_addr;
          uVar7 = *(uint *)(uVar13 + (long)((int)uVar14 >> 2) * 4);
          if ((uVar7 != 0) && (sps != 0)) {
            ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: desc addr:0x%x; data addr:0x%x:\n",
                           "print_bam_pipe_desc_fifo",uVar4 + uVar14,uVar7);
            if ((sps != 0) &&
               ((*(long *)(sps + 0x118) != 0 ||
                (_printk(&DAT_0012357e,"print_bam_pipe_desc_fifo",uVar4 + uVar14,(ulong)uVar7),
                sps != 0)))) {
              puVar15 = (undefined4 *)((ulong)uVar7 - lVar11 | 0xffffff8000000000);
              ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: 0x%x, 0x%x, 0x%x, 0x%x\n",
                             "print_bam_pipe_desc_fifo",*puVar15,puVar15[1],puVar15[2],puVar15[3]);
              if (((sps != 0) &&
                  ((((((*(long *)(sps + 0x118) != 0 ||
                       (_printk(&DAT_00123bf4,"print_bam_pipe_desc_fifo",*puVar15,puVar15[1],
                                puVar15[2],puVar15[3]), sps != 0)) &&
                      (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: 0x%x, 0x%x, 0x%x, 0x%x\n",
                                      "print_bam_pipe_desc_fifo",puVar15[4],puVar15[5],puVar15[6],
                                      puVar15[7]), sps != 0)) &&
                     ((*(long *)(sps + 0x118) != 0 ||
                      (_printk(&DAT_00123bf4,"print_bam_pipe_desc_fifo",puVar15[4],puVar15[5],
                               puVar15[6],puVar15[7]), sps != 0)))) &&
                    ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: 0x%x, 0x%x, 0x%x, 0x%x\n",
                                     "print_bam_pipe_desc_fifo",puVar15[8],puVar15[9],puVar15[10],
                                     puVar15[0xb]), sps != 0 &&
                     ((*(long *)(sps + 0x118) != 0 ||
                      (_printk(&DAT_00123bf4,"print_bam_pipe_desc_fifo",puVar15[8],puVar15[9],
                               puVar15[10],puVar15[0xb]), sps != 0)))))) &&
                   (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: 0x%x, 0x%x, 0x%x, 0x%x\n\n",
                                   "print_bam_pipe_desc_fifo",puVar15[0xc],puVar15[0xd],puVar15[0xe]
                                   ,puVar15[0xf]), sps != 0)))) && (*(long *)(sps + 0x118) == 0)) {
                _printk(&DAT_001205ca,"print_bam_pipe_desc_fifo",puVar15[0xc],puVar15[0xd],
                        puVar15[0xe],puVar15[0xf]);
              }
            }
          }
          uVar14 = uVar14 + 8;
        } while (uVar14 < uVar5);
        if ((sps == 0) ||
           (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: %s","print_bam_pipe_desc_fifo",
                           "----- end of data blocks -----\n"), sps == 0)) goto LAB_00108248;
        if (*(long *)(sps + 0x118) == 0) {
          pcVar10 = "----- end of data blocks -----\n";
LAB_001087f8:
          _printk(&DAT_0012561d,"print_bam_pipe_desc_fifo",pcVar10);
        }
      }
      else {
        uVar6 = bam_read_reg_field(param_1,0x29,param_2,0xffff);
        uVar2 = (param_3 & 0x1ffffff) * 0x40;
        uVar7 = uVar6 + uVar2;
        uVar14 = 0;
        if (uVar2 <= uVar6) {
          uVar14 = uVar6 + (param_3 & 0x1ffffff) * -0x40;
        }
        if (uVar7 <= uVar5) {
          uVar5 = uVar7;
        }
        if ((((sps != 0) &&
             (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: %s","print_bam_pipe_desc_fifo",
                             "------------ begin of partial FIFO ------------\n\n"), sps != 0)) &&
            ((*(long *)(sps + 0x118) != 0 ||
             (_printk(&DAT_0012561d,"print_bam_pipe_desc_fifo",
                      "------------ begin of partial FIFO ------------\n\n"), sps != 0)))) &&
           ((ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: %s","print_bam_pipe_desc_fifo",
                            "desc addr; desc content; desc flags\n"), sps != 0 &&
            (*(long *)(sps + 0x118) == 0)))) {
          _printk(&DAT_0012561d,"print_bam_pipe_desc_fifo","desc addr; desc content; desc flags\n");
        }
        for (; uVar14 < uVar5; uVar14 = uVar14 + 8) {
          uVar7 = uVar14 + 3;
          if (-1 < (int)uVar14) {
            uVar7 = uVar14;
          }
          puVar15 = (undefined4 *)(uVar13 + (long)((int)uVar7 >> 2) * 4);
          uVar2 = puVar15[1];
          local_78 = 0;
          uStack_70 = 0;
          local_88 = 0;
          uStack_80 = 0;
          local_98 = 0;
          uStack_90 = 0;
          local_a8 = 0;
          uStack_a0 = 0;
          local_b8 = 0;
          uStack_b0 = 0;
          uVar7 = scnprintf(&local_b8,0x28,"0x%x: 0x%x, 0x%x: ",uVar4 + uVar14,*puVar15,puVar15[1]);
          if ((int)uVar2 < 0) {
            if (0x50 < uVar7) goto LAB_00108870;
            iVar8 = scnprintf((long)&local_b8 + (ulong)uVar7,5,&DAT_001201f7);
            uVar7 = iVar8 + uVar7;
          }
          if ((uVar2 >> 0x1e & 1) != 0) {
            if (0x50 < uVar7) goto LAB_00108870;
            iVar8 = scnprintf((long)&local_b8 + (ulong)uVar7,5,&DAT_0011ec66);
            uVar7 = iVar8 + uVar7;
          }
          if ((uVar2 >> 0x1d & 1) != 0) {
            if (0x50 < uVar7) goto LAB_00108870;
            iVar8 = scnprintf((long)&local_b8 + (ulong)uVar7,5,&DAT_00124a0a);
            uVar7 = iVar8 + uVar7;
          }
          if ((uVar2 >> 0x1c & 1) != 0) {
            if (0x50 < uVar7) goto LAB_00108870;
            iVar8 = scnprintf((long)&local_b8 + (ulong)uVar7,5,&DAT_00122d36);
            uVar7 = iVar8 + uVar7;
          }
          if ((uVar2 >> 0x1b & 1) != 0) {
            if (0x50 < uVar7) goto LAB_00108870;
            iVar8 = scnprintf((long)&local_b8 + (ulong)uVar7,5,&DAT_00123945);
            uVar7 = iVar8 + uVar7;
          }
          if ((uVar2 >> 0x1a & 1) != 0) {
            if (0x50 < uVar7) goto LAB_00108870;
            iVar8 = scnprintf((long)&local_b8 + (ulong)uVar7,5,&DAT_001235a5);
            uVar7 = iVar8 + uVar7;
          }
          if ((uVar2 >> 0x19 & 1) != 0) {
            if (0x50 < uVar7) goto LAB_00108870;
            iVar8 = scnprintf((long)&local_b8 + (ulong)uVar7,5,&DAT_001211af);
            uVar7 = iVar8 + uVar7;
          }
          if ((uVar2 >> 0x18 & 1) != 0) {
            if (0x50 < uVar7) {
LAB_00108870:
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x108874);
              (*pcVar3)();
            }
            scnprintf((long)&local_b8 + (ulong)uVar7,5,&DAT_00123c12);
          }
          if (((sps != 0) &&
              (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: %s\n","print_bam_pipe_desc_fifo",
                              &local_b8), sps != 0)) && (*(long *)(sps + 0x118) == 0)) {
            _printk(&DAT_0011f22e,"print_bam_pipe_desc_fifo",&local_b8);
          }
        }
        if ((sps == 0) ||
           (ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: %s","print_bam_pipe_desc_fifo",
                           "\n------------  end of partial FIFO  ------------\n"), sps == 0))
        goto LAB_00108248;
        if (*(long *)(sps + 0x118) == 0) {
          pcVar10 = "\n------------  end of partial FIFO  ------------\n";
          goto LAB_001087f8;
        }
      }
      if (((sps != 0) &&
          (ipc_log_string(*(undefined8 *)(sps + 0x118),
                          "%s: \nsps:<desc-end> --- descriptor FIFO of Pipe %d -----\n\n",
                          "print_bam_pipe_desc_fifo",param_2), sps != 0)) &&
         (*(long *)(sps + 0x118) == 0)) {
        _printk(&DAT_00124a0f,"print_bam_pipe_desc_fifo",param_2);
      }
      goto LAB_00108248;
    }
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar8 = ___ratelimit(print_bam_pipe_desc_fifo__rs_255,"print_bam_pipe_desc_fifo"),
        iVar8 != 0)))) {
      _printk(&DAT_0011d501,"print_bam_pipe_desc_fifo",param_2);
    }
    if (sps == 0) goto LAB_00108248;
    uVar9 = *(undefined8 *)(sps + 0x110);
    pcVar10 = "%s: sps: desc FIFO size of Pipe %d is 0\n";
  }
  ipc_log_string(uVar9,pcVar10,"print_bam_pipe_desc_fifo",param_2);
LAB_00108248:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// readl @ 00108878 size=140
// signature: undefined readl(void)
// callers: [bam_read_reg_field, bam_write_reg_field, bam_read_reg]
//------------------------------------------------------------

undefined4 readl(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl,uVar1);
  uVar2 = *param_1;
  DataMemoryBarrier(0,1);
  log_post_read_mmio(uVar2,0x20,param_1,0x1088d0,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel @ 00108904 size=136
// signature: undefined writel(void)
// callers: [bam_write_reg, bam_write_reg_field]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10891c,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x10895c,uVar1);
  return;
}



//------------------------------------------------------------
// sps_bam_driver_init @ 00108994 size=8
// signature: undefined sps_bam_driver_init(void)
// callers: [msm_sps_probe]
//------------------------------------------------------------

undefined8 sps_bam_driver_init(void)

{
  return 0;
}



//------------------------------------------------------------
// sps_bam_check_irq @ 001089a0 size=3004
// signature: undefined sps_bam_check_irq(void)
// callers: [bam_isr, sps_bam_process_irq]
//------------------------------------------------------------

void sps_bam_check_irq(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  code *pcVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  uint uVar12;
  long *plVar13;
  undefined4 local_6c;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  if (((1 < logging_option) && (2 < debug_level_option)) &&
     ((print_limit_option == 0 ||
      (iVar9 = ___ratelimit(&sps_bam_check_irq__rs,"sps_bam_check_irq"), iVar9 != 0)))) {
    _printk(&DAT_0011fcfc,"sps_bam_check_irq",param_1 + 0x18);
  }
  if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 2)) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x218),"%s: sps: bam=%pa\n","sps_bam_check_irq",
                   param_1 + 0x18);
  }
  lVar1 = param_1 + 0xe4;
  uVar10 = _raw_spin_lock_irqsave(lVar1);
  if (*(char *)(param_1 + 0x338) == '\0') {
    lVar2 = param_1 + 0x18;
    lVar3 = param_1 + 0xd8;
    do {
      uVar12 = *(uint *)(param_1 + 0xf8);
      if ((*(byte *)(param_1 + 0xa0) >> 5 & 1) == 0) {
        local_6c = 0;
        uVar7 = bam_check_irq_source(lVar3,*(undefined4 *)(param_1 + 0x80),uVar12,&local_6c);
        if (((1 < logging_option) && (2 < debug_level_option)) &&
           ((print_limit_option == 0 ||
            (iVar9 = ___ratelimit(sps_bam_check_irq__rs_7,"sps_bam_check_irq"), iVar9 != 0)))) {
          _printk(&DAT_00122253,"sps_bam_check_irq",lVar2,uVar7,uVar12);
        }
        if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 2)) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x218),"%s: sps:bam=%pa;source=0x%x;mask=0x%x\n",
                         "sps_bam_check_irq",lVar2,uVar7,uVar12);
        }
        if (uVar7 == 0) {
          if (*(char *)(param_1 + 0x10) < '\0') {
            if (((1 < logging_option) && (1 < debug_level_option)) &&
               ((print_limit_option == 0 ||
                (iVar9 = ___ratelimit(sps_bam_check_irq__rs_10,"sps_bam_check_irq"), iVar9 != 0))))
            {
              _printk(&DAT_0011d5c5,"sps_bam_check_irq",lVar2,0);
            }
            if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 3)) {
              ipc_log_string(*(undefined8 *)(param_1 + 0x220),
                             "%s: sps: BAM %pa has no source (source = 0x%x)\n","sps_bam_check_irq",
                             lVar2,0);
            }
            _raw_spin_unlock_irqrestore(lVar1,uVar10);
            uVar10 = 0xffffffff;
            goto LAB_00109404;
          }
        }
        else if (((int)uVar7 < 0) && (*(long *)(param_1 + 0x68) != 0)) {
          if (((1 < logging_option) && (2 < debug_level_option)) &&
             ((print_limit_option == 0 ||
              (iVar9 = ___ratelimit(sps_bam_check_irq__rs_13,"sps_bam_check_irq"), iVar9 != 0)))) {
            _printk(&DAT_0011d0f6,"sps_bam_check_irq",lVar2,local_6c);
          }
          if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 2)) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x218),"%s: sps:bam=%pa;callback for case %d\n"
                           ,"sps_bam_check_irq",lVar2,local_6c);
          }
          if (*(int *)(*(code **)(param_1 + 0x68) + -4) != 0x78861429) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x108b84);
            (*pcVar6)();
          }
          (**(code **)(param_1 + 0x68))(local_6c,*(undefined8 *)(param_1 + 0x70));
        }
        uVar12 = *(uint *)(param_1 + 0xf8) & uVar7;
      }
      else {
        if (((1 < logging_option) && (2 < debug_level_option)) &&
           ((print_limit_option == 0 ||
            (iVar9 = ___ratelimit(sps_bam_check_irq__rs_16,"sps_bam_check_irq"), iVar9 != 0)))) {
          _printk(&DAT_0011e892,"sps_bam_check_irq",lVar2,uVar12);
        }
        if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 2)) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x218),"%s: sps:MTI:bam=%pa;source=0x%x\n",
                         "sps_bam_check_irq",lVar2,uVar12);
        }
      }
      plVar13 = (long *)(param_1 + 0x1f8);
      do {
        plVar13 = (long *)*plVar13;
        if (plVar13 == (long *)(param_1 + 0x1f8)) {
          if (uVar12 != 0) {
            if ((logging_option != 1) &&
               ((print_limit_option < 3 ||
                (iVar9 = ___ratelimit(sps_bam_check_irq__rs_19,"sps_bam_check_irq"), iVar9 != 0))))
            {
              _printk(&DAT_0011dad1,"sps_bam_check_irq",lVar2,uVar12);
            }
            if (param_1 != 0) {
              ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                             "%s: sps:IRQ from BAM %pa inactive pipe(s) 0x%x\n","sps_bam_check_irq",
                             lVar2,uVar12);
            }
            *(int *)(param_1 + 0x208) = *(int *)(param_1 + 0x208) + 1;
          }
          break;
        }
        if ((((plVar13 != (long *)0xffffffff77777777) && (plVar13 != (long *)0x0)) &&
            (*(char *)(plVar13 + 0x50) == '\0')) && ((*(uint *)(plVar13 + 0x18) & uVar12) != 0)) {
          uVar4 = *(undefined4 *)((long)plVar13 + 0xbc);
          uVar7 = bam_pipe_get_and_clear_irq_status(lVar3,uVar4);
          if (((1 < logging_option) && (3 < debug_level_option)) &&
             ((print_limit_option == 0 ||
              (iVar9 = ___ratelimit(pipe_handler__rs,"pipe_handler"), iVar9 != 0)))) {
            _printk(&DAT_00121f4f,"pipe_handler",lVar2,uVar4,uVar7);
          }
          if ((param_1 != 0) && (*(int *)(param_1 + 0x238) == 0)) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x210),"%s: sps: bam %pa.pipe %d.status=0x%x\n"
                           ,"pipe_handler",lVar2,uVar4,uVar7);
          }
          uVar7 = *(uint *)((long)plVar13 + 0xc4) & uVar7;
          if (uVar7 != 0) {
            if (((uVar7 & 0x21) != 0) && ((*(byte *)(plVar13 + 0x17) >> 4 & 1) == 0)) {
              pipe_handler_eot(param_1,plVar13);
              if (*(int *)(plVar13 + 0x4e) != 0) {
                iVar9 = 1;
                if ((uVar7 & 0x20) == 0) {
                  iVar9 = 2;
                }
                plVar13[0x4b] = 0;
                plVar13[0x4d] = 0;
                plVar13[0x4c] = 0;
                plVar13[0x4a] = 0;
                plVar13[0x49] = 0;
                plVar13[0x48] = 0;
                uVar11 = plVar13[(ulong)(iVar9 - 1U) * 4 + 0x25];
                *(int *)(plVar13 + 0x4b) = iVar9;
                plVar13[0x4a] = uVar11;
                trigger_event(param_1,plVar13 + (ulong)(iVar9 - 1U) * 4 + 0x22,plVar13 + 0x48);
              }
              uVar7 = uVar7 & 0xffffffde;
              if (uVar7 == 0) goto LAB_00108c50;
            }
            if ((uVar7 >> 2 & 1) != 0) {
              if (*(int *)((long)plVar13 + 0xe4) != 0) {
                uVar5 = *(undefined4 *)((long)plVar13 + 0xbc);
                if (((1 < logging_option) && (1 < debug_level_option)) &&
                   ((print_limit_option == 0 ||
                    (iVar9 = ___ratelimit(pipe_handler_wakeup__rs,"pipe_handler_wakeup"), iVar9 != 0
                    )))) {
                  _printk(&DAT_00120f48,"pipe_handler_wakeup",lVar2,uVar5,
                          *(undefined4 *)((long)plVar13 + 0xc4));
                }
                if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 3)) {
                  ipc_log_string(*(undefined8 *)(param_1 + 0x220),
                                 "%s: sps:BAM:%pa pipe %d wake_up_is_one_shot; irq_mask:0x%x\n",
                                 "pipe_handler_wakeup",lVar2,uVar5,
                                 *(undefined4 *)((long)plVar13 + 0xc4));
                }
                *(uint *)((long)plVar13 + 0xc4) = *(uint *)((long)plVar13 + 0xc4) & 0xfffffffb;
                pipe_set_irq(param_1,uVar5,*(undefined4 *)(plVar13 + 0x19));
              }
              plVar13[0x4b] = 0;
              plVar13[0x4d] = 0;
              plVar13[0x4c] = 0;
              plVar13[0x49] = 0;
              plVar13[0x48] = 0;
              *(undefined4 *)(plVar13 + 0x4b) = 4;
              plVar13[0x4a] = plVar13[0x31];
              trigger_event(param_1,plVar13 + 0x2e,plVar13 + 0x48);
              uVar7 = uVar7 & 0xfffffffb;
              if (uVar7 == 0) goto LAB_00108c50;
            }
            if ((uVar7 >> 1 & 1) != 0) {
              plVar13[0x4b] = 0;
              plVar13[0x4d] = 0;
              plVar13[0x4c] = 0;
              plVar13[0x49] = 0;
              plVar13[0x48] = 0;
              *(undefined4 *)(plVar13 + 0x4b) = 6;
              plVar13[0x4a] = plVar13[0x39];
              trigger_event(param_1,plVar13 + 0x36,plVar13 + 0x48);
              uVar7 = uVar7 & 0xfffffffd;
              if (uVar7 == 0) goto LAB_00108c50;
            }
            if ((uVar7 >> 3 & 1) != 0) {
              plVar13[0x4b] = 0;
              plVar13[0x4d] = 0;
              plVar13[0x4c] = 0;
              plVar13[0x49] = 0;
              plVar13[0x48] = 0;
              *(undefined4 *)(plVar13 + 0x4b) = 3;
              plVar13[0x4a] = plVar13[0x2d];
              trigger_event(param_1,plVar13 + 0x2a,plVar13 + 0x48);
              uVar7 = uVar7 & 0xfffffff7;
              if (uVar7 == 0) goto LAB_00108c50;
            }
            if (((uVar7 >> 6 & 1) != 0) && (enhd_pipe != '\0')) {
              if ((logging_option != 1) &&
                 ((print_limit_option < 3 ||
                  (iVar9 = ___ratelimit(pipe_handler__rs_315,"pipe_handler"), iVar9 != 0)))) {
                _printk(&DAT_0011e508,"pipe_handler",lVar2,uVar4,uVar7);
              }
              if (param_1 != 0) {
                ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                               "%s: sps:bam %pa ;pipe 0x%x irq status=0x%x\nsps: BAM_PIPE_IRQ_RST_ERROR\n"
                               ,"pipe_handler",lVar2,uVar4,uVar7);
              }
              bam_output_register_content(lVar3,*(undefined4 *)(param_1 + 0x80));
              plVar13[0x4b] = 0;
              plVar13[0x4d] = 0;
              plVar13[0x4c] = 0;
              plVar13[0x49] = 0;
              plVar13[0x48] = 0;
              *(undefined4 *)(plVar13 + 0x4b) = 8;
              plVar13[0x4a] = plVar13[0x41];
              trigger_event(param_1,plVar13 + 0x3e,plVar13 + 0x48);
              uVar7 = uVar7 & 0xffffffbf;
              if (uVar7 == 0) goto LAB_00108c50;
            }
            if (((uVar7 >> 7 & 1) != 0) && (enhd_pipe != '\0')) {
              if ((logging_option != 1) &&
                 ((print_limit_option < 3 ||
                  (iVar9 = ___ratelimit(pipe_handler__rs_318,"pipe_handler"), iVar9 != 0)))) {
                _printk(&DAT_00124e6f,"pipe_handler",lVar2,uVar4,uVar7);
              }
              if (param_1 != 0) {
                ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                               "%s: sps:bam %pa ;pipe 0x%x irq status=0x%x\nsps: BAM_PIPE_IRQ_HRESP_ERROR\n"
                               ,"pipe_handler",lVar2,uVar4,uVar7);
              }
              bam_output_register_content(lVar3,*(undefined4 *)(param_1 + 0x80));
              plVar13[0x4b] = 0;
              plVar13[0x4d] = 0;
              plVar13[0x4c] = 0;
              plVar13[0x49] = 0;
              plVar13[0x48] = 0;
              *(undefined4 *)(plVar13 + 0x4b) = 9;
              plVar13[0x4a] = plVar13[0x45];
              trigger_event(param_1,plVar13 + 0x42,plVar13 + 0x48);
              uVar7 = uVar7 & 0xffffff7f;
              if (uVar7 == 0) goto LAB_00108c50;
            }
            if ((uVar7 & 7) != 0) {
              plVar13[0x4b] = 0;
              plVar13[0x4d] = 0;
              plVar13[0x4c] = 0;
              plVar13[0x49] = 0;
              plVar13[0x48] = 0;
              *(undefined4 *)(plVar13 + 0x4b) = 7;
              plVar13[0x4a] = plVar13[0x3d];
              trigger_event(param_1,plVar13 + 0x3a,plVar13 + 0x48);
            }
          }
LAB_00108c50:
          uVar12 = uVar12 & (*(uint *)(plVar13 + 0x18) ^ 0xffffffff);
        }
      } while (uVar12 != 0);
      if (-1 < *(char *)(param_1 + 0x10)) break;
      uVar4 = *(undefined4 *)(param_1 + 0xf8);
      local_6c = 0;
      iVar9 = bam_check_irq_source(lVar3,*(undefined4 *)(param_1 + 0x80),uVar4,&local_6c);
      if (((1 < logging_option) && (2 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar8 = ___ratelimit(sps_bam_check_irq__rs_22,"sps_bam_check_irq"), iVar8 != 0)))) {
        _printk(&DAT_0012528a,"sps_bam_check_irq",lVar2,iVar9,uVar4);
      }
      if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 2)) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x218),
                       "%s: sps:check if there is any new IRQ coming:bam=%pa;source=0x%x;mask=0x%x\n"
                       ,"sps_bam_check_irq",lVar2,iVar9,uVar4);
      }
      if ((iVar9 < 0) && (*(long *)(param_1 + 0x68) != 0)) {
        if (((1 < logging_option) && (2 < debug_level_option)) &&
           ((print_limit_option == 0 ||
            (iVar8 = ___ratelimit(sps_bam_check_irq__rs_25,"sps_bam_check_irq"), iVar8 != 0)))) {
          _printk(&DAT_0011d0f6,"sps_bam_check_irq",lVar2,local_6c);
        }
        if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 2)) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x218),"%s: sps:bam=%pa;callback for case %d\n",
                         "sps_bam_check_irq",lVar2,local_6c);
        }
        if (*(int *)(*(code **)(param_1 + 0x68) + -4) != 0x78861429) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x108c30);
          (*pcVar6)();
        }
        (**(code **)(param_1 + 0x68))(local_6c,*(undefined8 *)(param_1 + 0x70));
      }
    } while (iVar9 != 0);
  }
  else {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar9 = ___ratelimit(sps_bam_check_irq__rs_4,"sps_bam_check_irq"), iVar9 != 0)))) {
      _printk(&DAT_0011f7bf,"sps_bam_check_irq",param_1 + 0x18);
    }
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                     "%s: sps:IRQ from BAM %pa can\'t be currently served\n","sps_bam_check_irq",
                     param_1 + 0x18);
    }
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar10);
  uVar10 = 0;
LAB_00109404:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar10);
  }
  return;
}



//------------------------------------------------------------
// sps_bam_enable @ 00109560 size=2836
// signature: undefined sps_bam_enable(void)
// callers: [sps_bam_reset, sps_bam_pipe_connect, sps_bam_device_init]
//------------------------------------------------------------

void sps_bam_enable(long param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  ulong uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  undefined8 uVar11;
  uint uVar12;
  int local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar4 = 0;
  local_3c = 0;
  if ((*(uint *)(param_1 + 0xa0) >> 3 & 1) != 0) goto LAB_00109d04;
  if (((*(uint *)(param_1 + 0x78) ^ 0xffffffff) & 0x1d) == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_bam_enable__rs,"sps_bam_enable"), iVar2 != 0)))) {
      _printk(&DAT_0012398d,"sps_bam_enable",param_1 + 0x18);
    }
    if (param_1 == 0) goto LAB_00109d00;
    uVar4 = *(undefined8 *)(param_1 + 0x228);
    pcVar5 = "%s: sps:No local access to BAM %pa\n";
LAB_001095f4:
    ipc_log_string(uVar4,pcVar5,"sps_bam_enable",param_1 + 0x18);
    uVar4 = 0xffffffff;
    goto LAB_00109d04;
  }
  if (((*(uint *)(param_1 + 0x10) >> 1 & 1) == 0) && (iVar2 = *(int *)(param_1 + 0x2c), iVar2 != 0))
  {
    if ((*(uint *)(param_1 + 0x10) >> 7 & 1) == 0) {
      iVar2 = request_threaded_irq(iVar2,bam_isr,0,4,&DAT_0011d5f7,param_1);
      if (((1 < logging_option) && (debug_level_option != '\0')) &&
         ((print_limit_option == 0 ||
          (iVar3 = ___ratelimit(sps_bam_enable__rs_32,"sps_bam_enable"), iVar3 != 0)))) {
        _printk(&DAT_00120e24,"sps_bam_enable",param_1 + 0x18,*(undefined4 *)(param_1 + 0x2c));
      }
      if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 4)) {
        pcVar5 = "%s: sps:BAM %pa uses level for IRQ# %d\n";
LAB_0010987c:
        ipc_log_string(*(undefined8 *)(param_1 + 0x228),pcVar5,"sps_bam_enable",param_1 + 0x18,
                       *(undefined4 *)(param_1 + 0x2c));
      }
    }
    else {
      iVar2 = request_threaded_irq(iVar2,bam_isr,0,1,&DAT_0011d5f7,param_1);
      if (((1 < logging_option) && (debug_level_option != '\0')) &&
         ((print_limit_option == 0 ||
          (iVar3 = ___ratelimit(sps_bam_enable__rs_29,"sps_bam_enable"), iVar3 != 0)))) {
        _printk(&DAT_001252d8,"sps_bam_enable",param_1 + 0x18,*(undefined4 *)(param_1 + 0x2c));
      }
      if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 4)) {
        pcVar5 = "%s: sps:BAM %pa uses edge for IRQ# %d\n";
        goto LAB_0010987c;
      }
    }
    if (iVar2 == 0) {
      *(uint *)(param_1 + 0xa0) = *(uint *)(param_1 + 0xa0) | 4;
      if ((*(byte *)(param_1 + 0x10) >> 3 & 1) != 0) {
        iVar2 = irq_set_irq_wake(*(undefined4 *)(param_1 + 0x2c),1);
        if (iVar2 != 0) {
          if ((logging_option != 1) &&
             ((print_limit_option < 3 ||
              (iVar2 = ___ratelimit(sps_bam_enable__rs_41,"sps_bam_enable"), iVar2 != 0)))) {
            _printk(&DAT_0012120e,"sps_bam_enable",param_1 + 0x18,*(undefined4 *)(param_1 + 0x2c));
          }
          if (param_1 == 0) goto LAB_00109d00;
          uVar4 = *(undefined8 *)(param_1 + 0x228);
          uVar7 = *(undefined4 *)(param_1 + 0x2c);
          pcVar5 = "%s: sps:Fail to enable wakeup irq for BAM %pa IRQ %d\n";
          goto LAB_001098ec;
        }
        if (((1 < logging_option) && (debug_level_option != '\0')) &&
           ((print_limit_option == 0 ||
            (iVar2 = ___ratelimit(sps_bam_enable__rs_44,"sps_bam_enable"), iVar2 != 0)))) {
          _printk(&DAT_0011f2d4,"sps_bam_enable",param_1 + 0x18,*(undefined4 *)(param_1 + 0x2c));
        }
        if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 4)) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                         "%s: sps:Enable wakeup irq for BAM %pa IRQ %d\n","sps_bam_enable",
                         param_1 + 0x18,*(undefined4 *)(param_1 + 0x2c));
        }
      }
      uVar4 = 0x16;
      goto LAB_00109678;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_bam_enable__rs_38,"sps_bam_enable"), iVar2 != 0)))) {
      _printk(&DAT_001211e3,"sps_bam_enable",param_1 + 0x18,*(undefined4 *)(param_1 + 0x2c));
    }
    if (param_1 == 0) goto LAB_00109d00;
    uVar4 = *(undefined8 *)(param_1 + 0x228);
    uVar7 = *(undefined4 *)(param_1 + 0x2c);
    pcVar5 = "%s: sps:Failed to enable BAM %pa IRQ %d\n";
  }
  else {
    uVar4 = 0;
    *(uint *)(param_1 + 0xa0) = *(uint *)(param_1 + 0xa0) & 0xfffffffb;
LAB_00109678:
    local_3c = 0;
    if ((*(byte *)(param_1 + 0x78) & 1) == 0) {
      iVar2 = bam_init(param_1 + 0xd8,*(undefined4 *)(param_1 + 0x80),
                       *(undefined4 *)(param_1 + 0x34),uVar4,param_1 + 0xe0,&local_3c,
                       *(undefined4 *)(param_1 + 0x10));
    }
    else {
      iVar2 = bam_check(param_1 + 0xd8,param_1 + 0xe0,*(undefined4 *)(param_1 + 0x80),&local_3c);
    }
    if (iVar2 == 0) {
      uVar8 = *(uint *)(param_1 + 0xe0);
      if (((((*(uint *)(param_1 + 0x78) ^ 0xffffffff) & 3) == 0) && (*(int *)(param_1 + 0x80) == 0))
         && (uVar8 < 3)) {
        if ((logging_option != 1) &&
           ((print_limit_option < 3 ||
            (iVar2 = ___ratelimit(sps_bam_enable__rs_50,"sps_bam_enable"), iVar2 != 0)))) {
          _printk(&DAT_00121e54,"sps_bam_enable");
        }
        if (param_1 != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                         "%s: sps: EE for satellite BAM must be set to non-zero\n","sps_bam_enable")
          ;
        }
      }
      else {
        if ((((*(uint *)(param_1 + 0xa0) >> 2 & 1) != 0) && ((*(uint *)(param_1 + 0x78) & 1) != 0))
           && (uVar8 < 3)) {
          if ((*(int *)(param_1 + 0x88) == 0) || (*(int *)(param_1 + 0x88) == -0x21524111)) {
            if ((logging_option != 1) &&
               ((print_limit_option < 3 ||
                (iVar2 = ___ratelimit(sps_bam_enable__rs_53,"sps_bam_enable"), iVar2 != 0)))) {
              _printk(&DAT_00120e4e,"sps_bam_enable",param_1 + 0x18);
            }
            if (param_1 != 0) {
              uVar4 = *(undefined8 *)(param_1 + 0x228);
              pcVar5 = "%s: sps:MTI destination address not specified for BAM %pa\n";
              goto LAB_001095f4;
            }
            goto LAB_00109d00;
          }
          *(uint *)(param_1 + 0xa0) = *(uint *)(param_1 + 0xa0) | 0x20;
        }
        if (local_3c != 0) {
          *(int *)(param_1 + 0x30) = local_3c;
          if ((1 < logging_option) && (debug_level_option != '\0')) {
            iVar2 = local_3c;
            if (print_limit_option != 0) {
              iVar2 = ___ratelimit(sps_bam_enable__rs_56,"sps_bam_enable");
              if (iVar2 == 0) goto LAB_001097ac;
              iVar2 = *(int *)(param_1 + 0x30);
            }
            _printk(&DAT_00124abd,"sps_bam_enable",param_1 + 0x18,iVar2);
          }
LAB_001097ac:
          if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 4)) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                           "%s: sps:BAM %pa number of pipes reported by hw: %d\n","sps_bam_enable",
                           param_1 + 0x18,*(undefined4 *)(param_1 + 0x30));
          }
        }
        if (uVar8 < 3) {
          if ((((*(byte *)(param_1 + 0x78) & 1) == 0) && (uVar8 < 3)) &&
             (uVar8 = *(uint *)(param_1 + 0x30), uVar8 != 0)) {
            uVar9 = 0;
            uVar12 = 1;
            do {
              if ((*(uint *)(param_1 + 0x7c) & uVar12) != 0) {
                bam_pipe_satellite_mti(param_1 + 0xd8,uVar9,0,*(undefined4 *)(param_1 + 0x80));
                uVar8 = *(uint *)(param_1 + 0x30);
              }
              uVar9 = uVar9 + 1;
              uVar12 = uVar12 << 1;
            } while (uVar9 < uVar8);
          }
LAB_00109dcc:
          iVar2 = *(int *)(param_1 + 0x9c);
          *(uint *)(param_1 + 0xa0) = *(uint *)(param_1 + 0xa0) | 8;
          if (*(char *)(param_1 + 0x98) == '\0') {
            if (iVar2 != 0) goto LAB_00109e0c;
LAB_00109e14:
            if ((logging_option != 1) &&
               ((print_limit_option < 2 ||
                (iVar2 = ___ratelimit(sps_bam_enable__rs_68,"sps_bam_enable"), iVar2 != 0)))) {
              _printk(&DAT_00125301,"sps_bam_enable",param_1 + 0x18,*(undefined8 *)(param_1 + 0xd8),
                      *(undefined4 *)(param_1 + 0xe0),*(undefined4 *)(param_1 + 0x30));
            }
            if (param_1 != 0) {
LAB_00109e5c:
              ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                             "%s: sps:BAM %pa (va:0x%pK) enabled: ver:0x%x, number of pipes:%d\n",
                             "sps_bam_enable",param_1 + 0x18,*(undefined8 *)(param_1 + 0xd8),
                             *(undefined4 *)(param_1 + 0xe0),*(undefined4 *)(param_1 + 0x30));
            }
          }
          else {
            if (iVar2 != 0) {
LAB_00109e0c:
              *(int *)(param_1 + 0x9c) = iVar2 + -1;
              goto LAB_00109e14;
            }
            if (((1 < logging_option) && (debug_level_option != '\0')) &&
               ((print_limit_option == 0 ||
                (iVar2 = ___ratelimit(sps_bam_enable__rs_71,"sps_bam_enable"), iVar2 != 0)))) {
              _printk(&DAT_00125301,"sps_bam_enable",param_1 + 0x18,*(undefined8 *)(param_1 + 0xd8),
                      *(undefined4 *)(param_1 + 0xe0),*(undefined4 *)(param_1 + 0x30));
            }
            if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 4)) goto LAB_00109e5c;
          }
          uVar4 = 0;
          goto LAB_00109d04;
        }
        uVar8 = *(uint *)(param_1 + 0x80);
        uVar6 = (ulong)uVar8;
        if (uVar8 < 4) {
          if (*(int *)(param_1 + 0x8c) != 0xa434553) goto LAB_00109dcc;
          puVar10 = *(uint **)(param_1 + 0x90);
          if (puVar10 == (uint *)0x0) {
            if ((logging_option != 1) &&
               ((print_limit_option < 3 ||
                (iVar2 = ___ratelimit(sps_bam_enable__rs_62,"sps_bam_enable"), iVar2 != 0)))) {
              _printk(&DAT_00123fbd,"sps_bam_enable",param_1 + 0x18);
            }
            if (param_1 != 0) {
              uVar4 = *(undefined8 *)(param_1 + 0x228);
              pcVar5 = "%s: sps:EE config table is not specified for BAM %pa\n";
              goto LAB_001095f4;
            }
          }
          else {
            *(uint *)(param_1 + 0x7c) = ~puVar10[uVar6 * 2];
            if ((*(byte *)(param_1 + 0x78) & 1) != 0) goto LAB_00109dcc;
            uVar9 = *puVar10;
            if ((puVar10[2] & uVar9) == 0) {
              if ((puVar10[4] & uVar9) == 0) {
                if ((puVar10[6] & uVar9) == 0) {
                  if ((puVar10[4] & puVar10[2]) == 0) {
                    if ((puVar10[6] & puVar10[2]) == 0) {
                      if ((puVar10[6] & puVar10[4]) == 0) {
                        lVar1 = param_1 + 0xd8;
                        bam_security_init(lVar1,0,puVar10[1],
                                          *puVar10 & 0x7fffffff | (uint)(uVar8 == 0) << 0x1f);
                        bam_security_init(lVar1,1,puVar10[3],
                                          puVar10[2] & 0x7fffffff |
                                          (uint)(*(int *)(param_1 + 0x80) == 1) << 0x1f);
                        bam_security_init(lVar1,2,puVar10[5],
                                          puVar10[4] & 0x7fffffff |
                                          (uint)(*(int *)(param_1 + 0x80) == 2) << 0x1f);
                        bam_security_init(lVar1,3,puVar10[7],
                                          puVar10[6] & 0x7fffffff |
                                          (uint)(*(int *)(param_1 + 0x80) == 3) << 0x1f);
                        goto LAB_00109dcc;
                      }
                      uVar4 = 3;
                      uVar11 = 2;
                    }
                    else {
                      uVar4 = 3;
                      uVar11 = 1;
                    }
                  }
                  else {
                    uVar4 = 2;
                    uVar11 = 1;
                  }
                }
                else {
                  uVar11 = 0;
                  uVar4 = 3;
                }
              }
              else {
                uVar11 = 0;
                uVar4 = 2;
              }
            }
            else {
              uVar11 = 0;
              uVar4 = 1;
            }
            if ((logging_option != 1) &&
               ((print_limit_option < 3 ||
                (iVar2 = ___ratelimit(sps_bam_enable__rs_65,"sps_bam_enable"), iVar2 != 0)))) {
              _printk(&DAT_0011db3e,"sps_bam_enable",param_1 + 0x18,uVar11,uVar4);
            }
            if (param_1 != 0) {
              ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                             "%s: sps:Overlapping pipe assignments for BAM %pa: EEs %d and %d\n",
                             "sps_bam_enable",param_1 + 0x18,uVar11,uVar4);
            }
          }
        }
        else {
          if (logging_option != 1) {
            if (2 < print_limit_option) {
              iVar2 = ___ratelimit(sps_bam_enable__rs_59,"sps_bam_enable");
              if (iVar2 == 0) goto LAB_001099d4;
              uVar6 = (ulong)*(uint *)(param_1 + 0x80);
            }
            _printk(&DAT_0011f338,"sps_bam_enable",param_1 + 0x18,uVar6);
          }
LAB_001099d4:
          if (param_1 != 0) {
            uVar4 = *(undefined8 *)(param_1 + 0x228);
            uVar7 = *(undefined4 *)(param_1 + 0x80);
            pcVar5 = "%s: sps:Invalid EE BAM %pa: %d\n";
            goto LAB_001098ec;
          }
        }
      }
LAB_00109d00:
      uVar4 = 0xffffffff;
      goto LAB_00109d04;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_bam_enable__rs_47,"sps_bam_enable"), iVar2 != 0)))) {
      _printk(&DAT_00123c48,"sps_bam_enable",param_1 + 0x18,*(undefined4 *)(param_1 + 0x2c));
    }
    if (param_1 == 0) goto LAB_00109d00;
    uVar4 = *(undefined8 *)(param_1 + 0x228);
    uVar7 = *(undefined4 *)(param_1 + 0x2c);
    pcVar5 = "%s: sps:Fail to init BAM %pa IRQ %d\n";
  }
LAB_001098ec:
  ipc_log_string(uVar4,pcVar5,"sps_bam_enable",param_1 + 0x18,uVar7);
  uVar4 = 0xffffffff;
LAB_00109d04:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// bam_isr @ 0010a078 size=932
// signature: undefined bam_isr(void)
// callers: []
//------------------------------------------------------------

undefined8 bam_isr(undefined4 param_1,long param_2)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  char local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if (((1 < logging_option) && (2 < debug_level_option)) &&
     ((print_limit_option == 0 || (iVar2 = ___ratelimit(bam_isr__rs,"bam_isr"), iVar2 != 0)))) {
    _printk(&DAT_001223d3,"bam_isr",param_2 + 0x18,param_1);
  }
  if ((param_2 != 0) && (*(uint *)(param_2 + 0x238) < 2)) {
    ipc_log_string(*(undefined8 *)(param_2 + 0x218),"%s: sps: bam:%pa; IRQ #:%d\n","bam_isr",
                   param_2 + 0x18,param_1);
  }
  if (*(char *)(param_2 + 0x10) < '\0') {
    pcVar3 = *(code **)(param_2 + 0x68);
    if (pcVar3 == (code *)0x0) {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 || (iVar2 = ___ratelimit(bam_isr__rs_277,"bam_isr"), iVar2 != 0)))
         ) {
        _printk(&DAT_0011e96e,"bam_isr",param_2 + 0x18);
      }
      if (param_2 != 0) {
        ipc_log_string(*(undefined8 *)(param_2 + 0x228),
                       "%s: sps: Client of BAM %pa requires confirmation but does not register callback\n"
                       ,"bam_isr",param_2 + 0x18);
      }
    }
    else {
      local_3c[0] = '\0';
      if (*(int *)(pcVar3 + -4) != 0x78861429) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10a124);
        (*pcVar3)();
      }
      (*pcVar3)(4,local_3c);
      if (local_3c[0] == '\0') {
        if (((1 < logging_option) && (2 < debug_level_option)) &&
           ((print_limit_option == 0 ||
            (iVar2 = ___ratelimit(bam_isr__rs_274,"bam_isr"), iVar2 != 0)))) {
          _printk(&DAT_001239ff,"bam_isr",param_2 + 0x18,param_1);
        }
        if ((param_2 != 0) && (*(uint *)(param_2 + 0x238) < 2)) {
          ipc_log_string(*(undefined8 *)(param_2 + 0x218),
                         "%s: sps: BAM is not ready and thus skip IRQ for bam:%pa IRQ #:%d\n",
                         "bam_isr",param_2 + 0x18,param_1);
        }
      }
      else {
        if (((1 < logging_option) && (2 < debug_level_option)) &&
           ((print_limit_option == 0 ||
            (iVar2 = ___ratelimit(bam_isr__rs_268,"bam_isr"), iVar2 != 0)))) {
          _printk(&DAT_00124b41,"bam_isr",param_2 + 0x18,param_1);
        }
        if ((param_2 != 0) && (*(uint *)(param_2 + 0x238) < 2)) {
          ipc_log_string(*(undefined8 *)(param_2 + 0x218),
                         "%s: sps: handle IRQ for bam:%pa IRQ #:%d\n","bam_isr",param_2 + 0x18,
                         param_1);
        }
        iVar2 = sps_bam_check_irq(param_2);
        if (iVar2 != 0) {
          if (((1 < logging_option) && (1 < debug_level_option)) &&
             ((print_limit_option == 0 ||
              (iVar2 = ___ratelimit(bam_isr__rs_271,"bam_isr"), iVar2 != 0)))) {
            _printk(&DAT_0011d73f,"bam_isr",param_2 + 0x18,param_1);
          }
          if ((param_2 != 0) && (*(uint *)(param_2 + 0x238) < 3)) {
            ipc_log_string(*(undefined8 *)(param_2 + 0x220),
                           "%s: sps: callback bam:%pa IRQ #:%d to poll the pipes\n","bam_isr",
                           param_2 + 0x18,param_1);
          }
        }
        if (*(int *)(*(code **)(param_2 + 0x68) + -4) != 0x78861429) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10a1d8);
          (*pcVar3)();
        }
        (**(code **)(param_2 + 0x68))(5,local_3c);
      }
    }
  }
  else {
    sps_bam_check_irq(param_2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// sps_bam_disable @ 0010a420 size=452
// signature: undefined sps_bam_disable(void)
// callers: [sps_bam_reset, sps_bam_device_de_init]
//------------------------------------------------------------

undefined4 sps_bam_disable(long param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0xa0);
  if ((uVar3 >> 3 & 1) != 0) {
    if ((~*(uint *)(param_1 + 0x78) & 0x1d) == 0) {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar2 = ___ratelimit(sps_bam_disable__rs,"sps_bam_disable"), iVar2 != 0)))) {
        _printk(&DAT_0012398d,"sps_bam_disable",param_1 + 0x18);
      }
      if (param_1 == 0) {
        return 0xffffffff;
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x228),"%s: sps:No local access to BAM %pa\n",
                     "sps_bam_disable",param_1 + 0x18);
      return 0xffffffff;
    }
    if ((*(uint *)(param_1 + 0x78) & 1) == 0) {
      if ((uVar3 >> 2 & 1) != 0) {
        bam_exit(param_1 + 0xd8,*(undefined4 *)(param_1 + 0x80));
        uVar3 = *(uint *)(param_1 + 0xa0);
        if (((uVar3 >> 2 & 1) != 0) && (*(int *)(param_1 + 0x2c) != 0)) {
          free_irq(*(int *)(param_1 + 0x2c),param_1);
          uVar3 = *(uint *)(param_1 + 0xa0);
        }
        uVar3 = uVar3 & 0xfffffffb;
      }
      bVar1 = logging_option;
      *(uint *)(param_1 + 0xa0) = uVar3 & 0xfffffff7;
      if (((1 < bVar1) && (debug_level_option != '\0')) &&
         ((print_limit_option == 0 ||
          (iVar2 = ___ratelimit(sps_bam_disable__rs_72,"sps_bam_disable"), iVar2 != 0)))) {
        _printk(&DAT_00122676,"sps_bam_disable",param_1 + 0x18);
      }
      if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 4)) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x228),"%s: sps:BAM %pa disabled\n",
                       "sps_bam_disable",param_1 + 0x18);
      }
    }
    else {
      *(uint *)(param_1 + 0xa0) = uVar3 & 0xfffffff7;
      if ((uVar3 >> 2 & 1) != 0) {
        if (*(int *)(param_1 + 0x2c) == 0) {
          return 0;
        }
        free_irq(*(int *)(param_1 + 0x2c),param_1);
        *(uint *)(param_1 + 0xa0) = *(uint *)(param_1 + 0xa0) & 0xfffffffb;
        return 0;
      }
    }
  }
  return 0;
}



//------------------------------------------------------------
// sps_bam_device_init @ 0010a5e8 size=656
// signature: undefined sps_bam_device_init(void)
// callers: [sps_register_bam_device]
//------------------------------------------------------------

undefined8 sps_bam_device_init(long param_1)

{
  byte bVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  if (*(long *)(param_1 + 0x20) == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_bam_device_init__rs,"sps_bam_device_init"), iVar2 != 0)))) {
      _printk(&DAT_0011ecb7,"sps_bam_device_init");
    }
    if (param_1 == 0) {
      return 0xffffffff;
    }
    uVar3 = *(undefined8 *)(param_1 + 0x228);
    pcVar4 = "%s: sps: NULL BAM virtual address\n";
    goto LAB_0010a714;
  }
  *(long *)(param_1 + 0xd8) = *(long *)(param_1 + 0x20);
  bVar1 = logging_option;
  if (*(int *)(param_1 + 0x30) == 0) {
    *(undefined4 *)(param_1 + 0x30) = 0x1f;
    if ((1 < bVar1) && (debug_level_option != '\0')) {
      if (print_limit_option == 0) {
        uVar5 = 0x1f;
      }
      else {
        iVar2 = ___ratelimit(sps_bam_device_init__rs_77,"sps_bam_device_init");
        if (iVar2 == 0) goto LAB_0010a74c;
        uVar5 = *(undefined4 *)(param_1 + 0x30);
      }
      _printk(&DAT_0011ecdc,"sps_bam_device_init",param_1 + 0x18,uVar5);
    }
LAB_0010a74c:
    if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 4)) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                     "%s: sps:BAM %pa: assuming max number of pipes: %d\n","sps_bam_device_init",
                     param_1 + 0x18,*(undefined4 *)(param_1 + 0x30));
    }
  }
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined8 *)(param_1 + 0xf8) = 0;
  *(undefined1 *)(param_1 + 0x338) = 0;
  *(long *)(param_1 + 0x1f8) = param_1 + 0x1f8;
  *(long *)(param_1 + 0x200) = param_1 + 0x1f8;
  *(undefined8 *)(param_1 + 0xe4) = 0;
  if (((*(byte *)(param_1 + 0x10) & 1) == 0) || (iVar2 = sps_bam_enable(param_1), iVar2 == 0)) {
    if (((1 < logging_option) && (debug_level_option != '\0')) &&
       ((print_limit_option == 0 ||
        (iVar2 = ___ratelimit(sps_bam_device_init__rs_83,"sps_bam_device_init"), iVar2 != 0)))) {
      _printk(&DAT_0011d5fb,"sps_bam_device_init",param_1 + 0x18,*(undefined4 *)(param_1 + 0x2c));
    }
    if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 4)) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x228),"%s: sps:BAM device: phys %pa IRQ %d\n",
                     "sps_bam_device_init",param_1 + 0x18,*(undefined4 *)(param_1 + 0x2c));
    }
    return 0;
  }
  if ((logging_option != 1) &&
     ((print_limit_option < 3 ||
      (iVar2 = ___ratelimit(sps_bam_device_init__rs_80,"sps_bam_device_init"), iVar2 != 0)))) {
    _printk(&DAT_001239b3,"sps_bam_device_init");
  }
  if (param_1 == 0) {
    return 0xffffffff;
  }
  uVar3 = *(undefined8 *)(param_1 + 0x228);
  pcVar4 = "%s: sps: Fail to enable bam device\n";
LAB_0010a714:
  ipc_log_string(uVar3,pcVar4,"sps_bam_device_init");
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_bam_device_de_init @ 0010a87c size=192
// signature: undefined sps_bam_device_de_init(void)
// callers: [sps_deregister_bam_device]
//------------------------------------------------------------

void sps_bam_device_de_init(long param_1)

{
  int iVar1;
  
  if (((1 < logging_option) && (debug_level_option != '\0')) &&
     ((print_limit_option == '\0' ||
      (iVar1 = ___ratelimit(sps_bam_device_de_init__rs,"sps_bam_device_de_init"), iVar1 != 0)))) {
    _printk(&DAT_0011db81,"sps_bam_device_de_init",param_1 + 0x18,*(undefined4 *)(param_1 + 0x2c));
  }
  if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 4)) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x228),"%s: sps:BAM device DEINIT: phys %pa IRQ %d\n",
                   "sps_bam_device_de_init",param_1 + 0x18,*(undefined4 *)(param_1 + 0x2c));
  }
  sps_bam_disable(param_1);
  return;
}



//------------------------------------------------------------
// sps_bam_reset @ 0010a940 size=424
// signature: undefined sps_bam_reset(void)
// callers: [sps_device_reset]
//------------------------------------------------------------

undefined8 sps_bam_reset(long param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  
  if (((1 < logging_option) && (debug_level_option != '\0')) &&
     ((print_limit_option == 0 ||
      (iVar2 = ___ratelimit(sps_bam_reset__rs,"sps_bam_reset"), iVar2 != 0)))) {
    _printk(&DAT_00121246,"sps_bam_reset",param_1 + 0x18,*(undefined4 *)(param_1 + 0x2c));
  }
  if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 4)) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x228),"%s: sps:BAM device RESET: phys %pa IRQ %d\n",
                   "sps_bam_reset",param_1 + 0x18,*(undefined4 *)(param_1 + 0x2c));
  }
  if ((*(byte *)(param_1 + 0xa0) >> 3 & 1) != 0) {
    if (*(uint *)(param_1 + 0x30) != 0) {
      uVar5 = 0;
      do {
        if (uVar5 == 0x1f) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10aacc);
          (*pcVar1)();
        }
        lVar4 = *(long *)(param_1 + 0x100 + uVar5 * 8);
        if ((lVar4 != -0x88888889) && (lVar4 != 0)) {
          if ((logging_option != 1) &&
             ((print_limit_option < 3 ||
              (iVar2 = ___ratelimit(sps_bam_reset__rs_90,"sps_bam_reset"), iVar2 != 0)))) {
            _printk(&DAT_0011f841,"sps_bam_reset",param_1 + 0x18,uVar5 & 0xffffffff);
          }
          if (param_1 == 0) {
            return 0xffffffff;
          }
          ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                         "%s: sps:BAM device %pa RESET failed: pipe %d in use\n","sps_bam_reset",
                         param_1 + 0x18,uVar5 & 0xffffffff);
          return 0xffffffff;
        }
        uVar5 = uVar5 + 1;
      } while (*(uint *)(param_1 + 0x30) != uVar5);
    }
    iVar2 = sps_bam_disable(param_1);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
  }
  uVar3 = sps_bam_enable(param_1);
  return uVar3;
}



//------------------------------------------------------------
// sps_bam_pipe_alloc @ 0010aaec size=804
// signature: undefined sps_bam_pipe_alloc(void)
// callers: [sps_rm_state_change]
//------------------------------------------------------------

ulong sps_bam_pipe_alloc(long param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  
  if (param_2 == 0xffffffff) {
    if ((*(byte *)(param_1 + 0x78) >> 2 & 1) == 0) {
      if (*(uint *)(param_1 + 0x30) != 0) {
        uVar6 = 0;
        uVar5 = 1;
        do {
          if ((*(uint *)(param_1 + 0x7c) & uVar5) == 0) {
            if (0x1e < uVar6) {
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10ae10);
              (*pcVar1)();
            }
            if (*(long *)(param_1 + 0x100 + uVar6 * 8) == 0) {
              uVar7 = uVar6 & 0xffffffff;
              goto LAB_0010ad6c;
            }
          }
          uVar6 = uVar6 + 1;
          uVar5 = uVar5 << 1;
        } while (*(uint *)(param_1 + 0x30) != uVar6);
      }
      if ((logging_option != '\x01') &&
         ((print_limit_option < 3 ||
          (iVar2 = ___ratelimit(sps_bam_pipe_alloc__rs_95,"sps_bam_pipe_alloc"), iVar2 != 0)))) {
        _printk(&DAT_00121ea7,"sps_bam_pipe_alloc",param_1 + 0x18);
      }
      if (param_1 == 0) {
        return 0xffffffff;
      }
      uVar3 = *(undefined8 *)(param_1 + 0x228);
      pcVar4 = "%s: sps:Fail to allocate pipe on BAM %pa\n";
    }
    else {
      if ((logging_option != '\x01') &&
         ((print_limit_option < 3 ||
          (iVar2 = ___ratelimit(sps_bam_pipe_alloc__rs,"sps_bam_pipe_alloc"), iVar2 != 0)))) {
        _printk(&DAT_00124055,"sps_bam_pipe_alloc",param_1 + 0x18);
      }
      if (param_1 == 0) {
        return 0xffffffff;
      }
      uVar3 = *(undefined8 *)(param_1 + 0x228);
      pcVar4 = "%s: sps:Restricted from allocating pipes on BAM %pa\n";
    }
    ipc_log_string(uVar3,pcVar4,"sps_bam_pipe_alloc",param_1 + 0x18);
    return 0xffffffff;
  }
  uVar6 = (ulong)param_2;
  if ((param_2 < 0x1f) && (param_2 < *(uint *)(param_1 + 0x30))) {
    if ((*(uint *)(param_1 + 0x7c) >> (uVar6 & 0x3f) & 1) != 0) {
      if ((logging_option != '\x01') &&
         ((print_limit_option < 3 ||
          (iVar2 = ___ratelimit(sps_bam_pipe_alloc__rs_101,"sps_bam_pipe_alloc"), iVar2 != 0)))) {
        _printk(&DAT_001222c5,"sps_bam_pipe_alloc",param_1 + 0x18,uVar6);
      }
      if (param_1 == 0) {
        return 0xffffffff;
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x228),"%s: sps:BAM %pa pipe %d is not local\n",
                     "sps_bam_pipe_alloc",param_1 + 0x18,uVar6);
      return 0xffffffff;
    }
    uVar7 = uVar6;
    if (*(long *)(param_1 + uVar6 * 8 + 0x100) == 0) {
LAB_0010ad6c:
      *(undefined8 *)(param_1 + uVar6 * 8 + 0x100) = 0xffffffff77777777;
      return uVar7;
    }
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_bam_pipe_alloc__rs_104,"sps_bam_pipe_alloc"), iVar2 != 0)))) {
      _printk(&DAT_0012022b,"sps_bam_pipe_alloc",uVar6,param_1 + 0x18);
    }
    if (param_1 == 0) {
      return 0xffffffff;
    }
    uVar3 = *(undefined8 *)(param_1 + 0x228);
    pcVar4 = "%s: sps:Pipe %d already allocated on BAM %pa\n";
  }
  else {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_bam_pipe_alloc__rs_98,"sps_bam_pipe_alloc"), iVar2 != 0)))) {
      _printk(&DAT_0011f878,"sps_bam_pipe_alloc",uVar6,param_1 + 0x18);
    }
    if (param_1 == 0) {
      return 0xffffffff;
    }
    uVar3 = *(undefined8 *)(param_1 + 0x228);
    pcVar4 = "%s: sps:Invalid pipe %d for allocate on BAM %pa\n";
  }
  ipc_log_string(uVar3,pcVar4,"sps_bam_pipe_alloc",uVar6,param_1 + 0x18);
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_bam_pipe_free @ 0010ae14 size=680
// signature: undefined sps_bam_pipe_free(void)
// callers: [sps_rm_free_map_rsrc]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sps_bam_pipe_free(long param_1,uint param_2)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  long *plVar7;
  long lVar8;
  
  if (param_2 < *(uint *)(param_1 + 0x30)) {
    if (0x1e < param_2) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10b0bc);
      (*pcVar4)();
    }
    lVar1 = param_1 + (ulong)param_2 * 8;
    lVar8 = *(long *)(lVar1 + 0x100);
    *(undefined8 *)(lVar1 + 0x100) = 0;
    if (lVar8 != -0x88888889) {
      if (lVar8 == 0) {
        if ((logging_option != '\x01') &&
           ((print_limit_option < 3 ||
            (iVar5 = ___ratelimit(sps_bam_pipe_free__rs_109,"sps_bam_pipe_free"), iVar5 != 0)))) {
          _printk(&DAT_0012408c,"sps_bam_pipe_free",param_2,param_1 + 0x18);
        }
        if (param_1 != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                         "%s: sps:Attempt to free unallocated pipe %d on BAM %pa\n",
                         "sps_bam_pipe_free",param_2,param_1 + 0x18);
        }
      }
      else {
        plVar2 = (long *)(lVar8 + 0x230);
        if (*(long **)(lVar8 + 0x230) != plVar2) {
          if ((logging_option != '\x01') &&
             ((print_limit_option < 3 ||
              (iVar5 = ___ratelimit(sps_bam_pipe_free__rs_112,"sps_bam_pipe_free"), iVar5 != 0)))) {
            _printk(&DAT_0012025b,"sps_bam_pipe_free",param_1 + 0x18,param_2);
          }
          if (param_1 != 0) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                           "%s: sps:Disconnect BAM %pa pipe %d with events pending\n",
                           "sps_bam_pipe_free",param_1 + 0x18,param_2);
          }
          plVar7 = (long *)*plVar2;
          if (plVar7 != plVar2) {
            uVar6 = __list_del_entry_valid(plVar7);
            if ((uVar6 & 1) != 0) {
              lVar1 = *plVar7;
              plVar3 = (long *)plVar7[1];
              *(long **)(lVar1 + 8) = plVar3;
              *plVar3 = lVar1;
            }
            *plVar7 = (long)&DAT_dead000000000100;
            plVar7[1] = -0x2152fffffffffede;
            kfree(plVar7);
            if (plVar2 != (long *)&DAT_dead000000000100) {
              do {
                uVar6 = __list_del_entry_valid(&DAT_dead000000000100);
                if ((uVar6 & 1) != 0) {
                  *(undefined8 **)(_DAT_dead000000000100 + 8) = _DAT_dead000000000108;
                  *_DAT_dead000000000108 = _DAT_dead000000000100;
                }
                _DAT_dead000000000100 = &DAT_dead000000000100;
                _DAT_dead000000000108 = (undefined8 *)0xdead000000000122;
                kfree(&DAT_dead000000000100);
              } while( true );
            }
          }
        }
        *(long *)lVar8 = lVar8;
        *(long *)(lVar8 + 8) = lVar8;
        *(undefined8 *)(lVar8 + 0xb8) = 0xffffffff00000000;
        *(undefined8 *)(lVar8 + 0xc0) = 0;
        *(undefined8 *)(lVar8 + 0xd8) = 0xffffffff;
        *(undefined4 *)(lVar8 + 0xe0) = 0;
        *(undefined1 *)(lVar8 + 0x280) = 0;
        *(undefined1 *)(lVar8 + 0xd0) = 0;
        memset((void *)(lVar8 + 0xe8),0,0x198);
        *(long **)(lVar8 + 0x230) = plVar2;
        *(long **)(lVar8 + 0x238) = plVar2;
      }
    }
  }
  else {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar5 = ___ratelimit(sps_bam_pipe_free__rs,"sps_bam_pipe_free"), iVar5 != 0)))) {
      _printk(&DAT_0011d647,"sps_bam_pipe_free",param_1 + 0x18,param_2);
    }
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x228),"%s: sps:Invalid BAM %pa pipe: %d\n",
                     "sps_bam_pipe_free",param_1 + 0x18,param_2);
    }
  }
  return;
}



//------------------------------------------------------------
// sps_bam_pipe_connect @ 0010b0c0 size=3268
// signature: undefined sps_bam_pipe_connect(void)
// callers: [sps_rm_state_change]
//------------------------------------------------------------

undefined8 sps_bam_pipe_connect(long *param_1,int *param_2)

{
  long *plVar1;
  uint uVar2;
  byte bVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  undefined8 uVar7;
  ulong uVar8;
  char *pcVar9;
  uint uVar10;
  long lVar11;
  undefined4 uVar12;
  int *piVar13;
  ulong uVar14;
  long lVar15;
  undefined8 *puVar16;
  long lVar17;
  long lVar18;
  uint uVar19;
  ulong uVar20;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  long local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  long local_78;
  undefined8 local_70;
  long local_68;
  
  lVar17 = sp_el0;
  local_68 = *(long *)(lVar17 + 0x638);
  local_78 = 0;
  local_70 = 0;
  lVar18 = param_1[0x16];
  local_88 = 0;
  local_80 = 0;
  local_98 = 0;
  local_90 = 0;
  local_a8 = 0;
  local_a0 = 0;
  local_b0 = 0;
  *param_1 = (long)param_1;
  param_1[1] = (long)param_1;
  param_1[0x17] = -0x100000000;
  param_1[0x18] = 0;
  param_1[0x1b] = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined1 *)(param_1 + 0x50) = 0;
  *(undefined1 *)(param_1 + 0x1a) = 0;
  memset(param_1 + 0x1d,0,0x198);
  plVar1 = param_1 + 0x46;
  param_1[0x46] = (long)plVar1;
  param_1[0x47] = (long)plVar1;
  bVar3 = logging_option;
  iVar6 = *param_2;
  local_78 = 0;
  local_70 = 0;
  local_80 = 0;
  local_98 = 0;
  local_90 = 0;
  *(int *)(param_1 + 0x1b) = iVar6;
  bVar5 = iVar6 == 0;
  uVar19 = param_2[1];
  lVar17 = lVar18 + 0x10;
  if (!bVar5) {
    lVar17 = lVar18 + 0x38;
  }
  local_a0 = 0;
  lVar11 = lVar18 + 0x38;
  if (!bVar5) {
    lVar11 = lVar18 + 0x10;
  }
  local_b0 = 0;
  local_a8 = (ulong)bVar5;
  local_88 = (ulong)(uVar19 >> 0x10 & 1);
  lVar15 = *(long *)(lVar17 + 0x20);
  uVar2 = *(uint *)(lVar17 + 0x10);
  uVar14 = (ulong)uVar2;
  if ((1 < bVar3) && (1 < debug_level_option)) {
    if (print_limit_option == 0) {
      iVar6 = *param_2;
    }
    else {
      iVar6 = ___ratelimit(sps_bam_pipe_connect__rs,"sps_bam_pipe_connect");
      if (iVar6 == 0) goto LAB_0010b1b0;
      iVar6 = *param_2;
      uVar19 = param_2[1];
    }
    _printk(&DAT_001240fe,"sps_bam_pipe_connect",lVar15 + 0x18,uVar14,iVar6,uVar19);
  }
LAB_0010b1b0:
  if ((lVar15 != 0) && (*(uint *)(lVar15 + 0x238) < 3)) {
    ipc_log_string(*(undefined8 *)(lVar15 + 0x220),
                   "%s: sps:BAM %pa; pipe %d; mode:%d; options:0x%x\n","sps_bam_pipe_connect",
                   lVar15 + 0x18,uVar14,*param_2,param_2[1]);
  }
  uVar8 = local_a8;
  if (uVar2 < *(uint *)(lVar15 + 0x30)) {
    local_88 = CONCAT44(*(undefined4 *)(lVar15 + 0x80),(undefined4)local_88);
    local_b0 = CONCAT62(local_b0._2_6_,(short)*(undefined4 *)(lVar17 + 0x14));
    local_90 = CONCAT44(*(undefined4 *)(lVar17 + 0x18),(uint)local_90);
    if (((*(uint *)(lVar15 + 0x78) >> 4 & 1) == 0) &&
       (uVar20 = 1L << (uVar14 & 0x3f), (uVar20 & *(uint *)(lVar15 + 0x7c)) == 0)) {
      if ((*(uint *)(lVar15 + 0x78) >> 3 & 1) == 0) {
        uVar19 = *(uint *)((long)param_1 + 0x54);
        if ((uVar19 >> 10 & 1) == 0) {
          if (*(long *)(lVar11 + 0x20) != 0) {
            local_a8 = local_a8 & 0xffffffff;
            *(uint *)(param_1 + 0x17) = *(uint *)(param_1 + 0x17) | 0x10;
            if ((*(byte *)(lVar15 + 0x11) >> 1 & 1) != 0) goto LAB_0010b3bc;
            local_80 = *(ulong *)(*(long *)(lVar11 + 0x20) + 0x18) & 0xffffffff;
            goto LAB_0010b42c;
          }
          local_a8 = CONCAT44(1,(undefined4)local_a8);
          param_1[0x1d] = *(long *)(lVar18 + 0x60);
          param_1[0x1e] = 0;
        }
        else {
          local_a8 = local_a8 & 0xffffffff;
          *(uint *)(param_1 + 0x17) = *(uint *)(param_1 + 0x17) | 0x10;
          if ((*(byte *)(lVar15 + 0x11) >> 1 & 1) != 0) {
LAB_0010b3bc:
            local_a8 = uVar8 & 0xffffffff;
            lVar17 = 0x40;
            if ((int)param_1[0x1b] != 0) {
              lVar17 = 0x28;
            }
            uVar8 = *(ulong *)((long)param_1 + lVar17);
            if (((1 < logging_option) && (1 < debug_level_option)) &&
               ((print_limit_option == 0 ||
                (iVar6 = ___ratelimit(sps_bam_pipe_connect__rs_122,"sps_bam_pipe_connect"),
                iVar6 != 0)))) {
              _printk(&DAT_001217dc,"sps_bam_pipe_connect",lVar15 + 0x18,uVar2,uVar8);
            }
            if ((lVar15 != 0) && (*(uint *)(lVar15 + 0x238) < 3)) {
              ipc_log_string(*(undefined8 *)(lVar15 + 0x220),
                             "%s: sps:BAM %pa pipe %d uses IOVA 0x%pK\n","sps_bam_pipe_connect",
                             lVar15 + 0x18,uVar2,uVar8);
            }
            uVar19 = *(uint *)((long)param_1 + 0x54);
            local_80 = uVar8 & 0xffffffff;
          }
LAB_0010b42c:
          if ((uVar19 >> 10 & 1) == 0) {
            uVar12 = *(undefined4 *)(lVar11 + 0x10);
          }
          else {
            uVar12 = (undefined4)param_1[9];
            local_80._0_4_ = (undefined4)param_1[7];
            local_70._0_5_ = CONCAT14(1,(undefined4)local_70);
          }
          local_80 = CONCAT44(uVar12,(undefined4)local_80);
          if ((((*(long *)(lVar18 + 0x68) == 0xdeadbeef) || (*(long *)(lVar18 + 0x88) == 0xdeadbeef)
               ) || (*(int *)(lVar18 + 0x78) == 0)) || (*(int *)(lVar18 + 0x98) == 0)) {
            if ((logging_option != 1) &&
               ((print_limit_option < 3 ||
                (iVar6 = ___ratelimit(sps_bam_pipe_connect__rs_125,"sps_bam_pipe_connect"),
                iVar6 != 0)))) {
              _printk(&DAT_001202aa,"sps_bam_pipe_connect",lVar15 + 0x18,uVar14);
            }
            if (lVar15 != 0) {
              uVar7 = *(undefined8 *)(lVar15 + 0x228);
              pcVar9 = "%s: sps:FIFO buffers are not allocated for BAM %pa pipe %d\n";
              goto LAB_0010b2c0;
            }
            goto LAB_0010b2d0;
          }
          if ((*(byte *)(lVar15 + 0x11) >> 1 & 1) == 0) {
            local_78 = *(long *)(lVar18 + 0x88);
          }
          else {
            lVar17 = param_1[0x11];
            local_78 = lVar17;
            if ((1 < logging_option) && (1 < debug_level_option)) {
              if (print_limit_option != 0) {
                iVar6 = ___ratelimit(sps_bam_pipe_connect__rs_128,"sps_bam_pipe_connect");
                if (iVar6 == 0) goto LAB_0010b6dc;
                lVar17 = param_1[0x11];
              }
              _printk(&DAT_001209c4,"sps_bam_pipe_connect",lVar15 + 0x18,uVar2,lVar17);
            }
LAB_0010b6dc:
            if ((lVar15 != 0) && (*(uint *)(lVar15 + 0x238) < 3)) {
              ipc_log_string(*(undefined8 *)(lVar15 + 0x220),
                             "%s: sps:BAM %pa pipe %d uses IOVA 0x%pK for data FIFO\n",
                             "sps_bam_pipe_connect",lVar15 + 0x18,uVar2,param_1[0x11]);
            }
          }
          local_70 = CONCAT44(local_70._4_4_,*(undefined4 *)(lVar18 + 0x98));
          if (*(long *)(lVar18 + 0x80) != 0) {
            if ((int)param_1[0x1b] != 0) goto LAB_0010b4e8;
            __memset_io(*(long *)(lVar18 + 0x80),0);
          }
          if ((int)param_1[0x1b] == 0) {
            if ((*(byte *)((long)param_2 + 6) >> 2 & 1) == 0) {
              local_a0 = (ulong)local_a0._4_4_ << 0x20;
            }
            else {
              local_a0 = CONCAT44(local_a0._4_4_,1);
            }
          }
        }
LAB_0010b4e8:
        uVar19 = (uint)uVar20;
        *(uint *)((long)param_1 + 0xbc) = uVar2;
        *(uint *)(param_1 + 0x18) = uVar19;
        if (*(long *)(lVar18 + 0x68) != 0xdeadbeef) {
          uVar10 = *(uint *)(lVar18 + 0x78);
          if (uVar10 < 0x10) {
            if (logging_option != 1) {
              if (2 < print_limit_option) {
                iVar6 = ___ratelimit(sps_bam_pipe_connect__rs_131,"sps_bam_pipe_connect");
                if (iVar6 == 0) goto LAB_0010b61c;
                uVar10 = *(uint *)(lVar18 + 0x78);
              }
              _printk(&DAT_0011d66b,"sps_bam_pipe_connect",lVar15 + 0x18,uVar2,uVar10);
            }
LAB_0010b61c:
            if (lVar15 != 0) {
              ipc_log_string(*(undefined8 *)(lVar15 + 0x228),
                             "%s: sps:Invalid descriptor FIFO size for BAM %pa pipe %d: %d\n",
                             "sps_bam_pipe_connect",lVar15 + 0x18,uVar2,
                             *(undefined4 *)(lVar18 + 0x78));
            }
            goto LAB_0010b2d0;
          }
          lVar17 = *(long *)(lVar18 + 0x60);
          if ((*(byte *)(lVar15 + 0x11) >> 1 & 1) == 0) {
            local_98 = *(long *)(lVar18 + 0x68);
          }
          else {
            lVar11 = param_1[0xd];
            local_98 = lVar11;
            if ((1 < logging_option) && (1 < debug_level_option)) {
              if (print_limit_option != 0) {
                iVar6 = ___ratelimit(sps_bam_pipe_connect__rs_134,"sps_bam_pipe_connect");
                if (iVar6 == 0) goto LAB_0010b76c;
                lVar11 = param_1[0xd];
              }
              _printk(&DAT_0011fd98,"sps_bam_pipe_connect",lVar15 + 0x18,uVar14,lVar11);
            }
LAB_0010b76c:
            if ((lVar15 != 0) && (*(uint *)(lVar15 + 0x238) < 3)) {
              ipc_log_string(*(undefined8 *)(lVar15 + 0x220),
                             "%s: sps:BAM %pa pipe %d uses IOVA 0x%pK for desc FIFO\n",
                             "sps_bam_pipe_connect",lVar15 + 0x18,uVar14,param_1[0xd]);
            }
          }
          local_90 = CONCAT44(local_90._4_4_,*(undefined4 *)(lVar18 + 0x78));
          if ((lVar17 != 0) && (((int)param_1[0x1b] == 0 || (local_a8._4_4_ == 1)))) {
            __memset_io(lVar17,0);
          }
        }
        *(uint *)((long)param_1 + 0xdc) = (uint)local_90 >> 3;
        *(uint *)(param_1 + 0x1c) = (uint)local_90;
        if (((*(byte *)(lVar15 + 0xa0) >> 3 & 1) != 0) ||
           (iVar6 = sps_bam_enable(lVar15), iVar6 == 0)) {
          if (0x1e < uVar2) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10bc9c);
            (*pcVar4)();
          }
          lVar17 = lVar15 + uVar14 * 8;
          if (*(long *)(lVar17 + 0x100) != -0x88888889) {
            if ((logging_option != 1) &&
               ((print_limit_option < 3 ||
                (iVar6 = ___ratelimit(sps_bam_pipe_connect__rs_137,"sps_bam_pipe_connect"),
                iVar6 != 0)))) {
              _printk(&DAT_00124d4d,"sps_bam_pipe_connect",uVar2,lVar15 + 0x18);
            }
            if (lVar15 != 0) {
              ipc_log_string(*(undefined8 *)(lVar15 + 0x228),
                             "%s: sps:Invalid pipe %d on BAM %pa for connect\n",
                             "sps_bam_pipe_connect",uVar2,lVar15 + 0x18);
            }
            goto LAB_0010b2d0;
          }
          lVar18 = lVar15 + 0xd8;
          iVar6 = bam_pipe_is_enabled(lVar18,uVar14);
          if (iVar6 != 0) {
            if (-1 < *(char *)((long)param_2 + 6)) {
              if ((logging_option != 1) &&
                 ((print_limit_option < 3 ||
                  (iVar6 = ___ratelimit(sps_bam_pipe_connect__rs_143,"sps_bam_pipe_connect"),
                  iVar6 != 0)))) {
                _printk(&DAT_001209fd,"sps_bam_pipe_connect",lVar15 + 0x18,uVar14);
              }
              if (lVar15 != 0) {
                uVar7 = *(undefined8 *)(lVar15 + 0x228);
                pcVar9 = "%s: sps:BAM %pa pipe %d sharing violation\n";
                goto LAB_0010b2c0;
              }
              goto LAB_0010b2d0;
            }
            if (((1 < logging_option) && (1 < debug_level_option)) &&
               ((print_limit_option == 0 ||
                (iVar6 = ___ratelimit(sps_bam_pipe_connect__rs_140,"sps_bam_pipe_connect"),
                iVar6 != 0)))) {
              _printk(&DAT_00124d7f,"sps_bam_pipe_connect",lVar15 + 0x18,uVar2);
            }
            if ((lVar15 != 0) && (*(uint *)(lVar15 + 0x238) < 3)) {
              ipc_log_string(*(undefined8 *)(lVar15 + 0x220),
                             "%s: sps:BAM %pa pipe %d is already enabled\n","sps_bam_pipe_connect",
                             lVar15 + 0x18,uVar2);
            }
          }
          iVar6 = bam_pipe_init(lVar18,uVar14,&local_b0,*(undefined4 *)(lVar15 + 0x80));
          if (iVar6 == 0) {
            puVar16 = (undefined8 *)(lVar17 + 0x100);
            *puVar16 = param_1;
            uVar10 = param_2[1];
            if (uVar10 == 0) {
              if ((*(byte *)(param_1 + 0x17) >> 4 & 1) == 0) goto LAB_0010b8f0;
            }
            else {
              if ((uVar10 >> 0x11 & 1) == 0) {
LAB_0010b8f0:
                if ((*(byte *)(lVar15 + 0xa0) >> 5 & 1) != 0) {
                  piVar13 = (int *)(lVar15 + 0x88);
                  goto LAB_0010b8fc;
                }
              }
              else {
                piVar13 = param_2 + 2;
LAB_0010b8fc:
                if (*piVar13 != -0x21524111) {
                  *(int *)((long)param_1 + 0xd4) = *piVar13;
                  *(uint *)(param_1 + 0x17) = *(uint *)(param_1 + 0x17) | 0x20;
                  uVar10 = param_2[1];
                }
              }
              iVar6 = sps_bam_pipe_set_params(lVar15,uVar14,uVar10);
              if (iVar6 != 0) {
                *puVar16 = 0xffffffff77777777;
                goto LAB_0010b938;
              }
            }
            *puVar16 = param_1;
            puVar16 = *(undefined8 **)(lVar15 + 0x200);
            *(uint *)(lVar15 + 0xf8) = *(uint *)(lVar15 + 0xf8) | uVar19;
            uVar8 = __list_add_valid(param_1,puVar16,lVar15 + 0x1f8);
            if ((uVar8 & 1) != 0) {
              *(long **)(lVar15 + 0x200) = param_1;
              *param_1 = lVar15 + 0x1f8;
              param_1[1] = (long)puVar16;
              *puVar16 = param_1;
            }
            if (((1 < logging_option) && (1 < debug_level_option)) &&
               ((print_limit_option == 0 ||
                (iVar6 = ___ratelimit(sps_bam_pipe_connect__rs_149,"sps_bam_pipe_connect"),
                iVar6 != 0)))) {
              _printk(&DAT_001231b2,"sps_bam_pipe_connect",lVar15 + 0x18,uVar14,(int)param_1[0x18],
                      *(undefined4 *)(lVar15 + 0xf8));
            }
            if ((lVar15 != 0) && (*(uint *)(lVar15 + 0x238) < 3)) {
              ipc_log_string(*(undefined8 *)(lVar15 + 0x220),
                             "%s: sps:BAM %pa; pipe %d; pipe_index_mask:0x%x; pipe_active_mask:0x%x\n"
                             ,"sps_bam_pipe_connect",lVar15 + 0x18,uVar14,(int)param_1[0x18],
                             *(undefined4 *)(lVar15 + 0xf8));
            }
            uVar7 = 0;
            *(uint *)(param_1 + 0x17) = *(uint *)(param_1 + 0x17) | 2;
            goto LAB_0010b2d4;
          }
          if ((logging_option != 1) &&
             ((print_limit_option < 3 ||
              (iVar6 = ___ratelimit(sps_bam_pipe_connect__rs_146,"sps_bam_pipe_connect"), iVar6 != 0
              )))) {
            _printk(&DAT_00125771,"sps_bam_pipe_connect",lVar15 + 0x18,uVar14);
          }
          if (lVar15 != 0) {
            ipc_log_string(*(undefined8 *)(lVar15 + 0x228),"%s: sps:BAM %pa pipe %d init error\n",
                           "sps_bam_pipe_connect",lVar15 + 0x18,uVar14);
          }
LAB_0010b938:
          if (*(char *)((long)param_2 + 6) < '\0') {
            if (((1 < logging_option) && (1 < debug_level_option)) &&
               ((print_limit_option == 0 ||
                (iVar6 = ___ratelimit(sps_bam_pipe_connect__rs_152,"sps_bam_pipe_connect"),
                iVar6 != 0)))) {
              _printk(&DAT_0011e942,"sps_bam_pipe_connect",lVar15 + 0x18,uVar14);
            }
            if ((lVar15 != 0) && (*(uint *)(lVar15 + 0x238) < 3)) {
              ipc_log_string(*(undefined8 *)(lVar15 + 0x220),
                             "%s: sps:BAM %pa pipe %d connection exits\n","sps_bam_pipe_connect",
                             lVar15 + 0x18,uVar2);
            }
          }
          else {
            bam_pipe_exit(lVar18,uVar2,*(undefined4 *)(lVar15 + 0x80));
          }
        }
        uVar7 = 0xffffffff;
        *param_1 = (long)param_1;
        param_1[1] = (long)param_1;
        param_1[0x17] = -0x100000000;
        param_1[0x18] = 0;
        param_1[0x1b] = 0xffffffff;
        *(undefined4 *)(param_1 + 0x1c) = 0;
        *(undefined1 *)(param_1 + 0x1a) = 0;
        memset(param_1 + 0x1d,0,0x199);
        param_1[0x46] = (long)(param_1 + 0x46);
        param_1[0x47] = (long)plVar1;
        goto LAB_0010b2d4;
      }
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar6 = ___ratelimit(sps_bam_pipe_connect__rs_119,"sps_bam_pipe_connect"), iVar6 != 0))))
      {
        _printk(&DAT_0011e908,"sps_bam_pipe_connect",lVar15 + 0x18,uVar14);
      }
      if (lVar15 != 0) {
        uVar7 = *(undefined8 *)(lVar15 + 0x228);
        pcVar9 = "%s: sps:BAM %pa pipe %d remote config is not supported\n";
        goto LAB_0010b2c0;
      }
    }
    else {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar6 = ___ratelimit(sps_bam_pipe_connect__rs_118,"sps_bam_pipe_connect"), iVar6 != 0))))
      {
        _printk(&DAT_001222c5,"sps_bam_pipe_connect",lVar15 + 0x18,uVar2);
      }
      if (lVar15 != 0) {
        uVar7 = *(undefined8 *)(lVar15 + 0x228);
        pcVar9 = "%s: sps:BAM %pa pipe %d is not local\n";
        goto LAB_0010b2c0;
      }
    }
  }
  else {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar6 = ___ratelimit(sps_bam_pipe_connect__rs_117,"sps_bam_pipe_connect"), iVar6 != 0)))) {
      _printk(&DAT_0011d647,"sps_bam_pipe_connect",lVar15 + 0x18,uVar14);
    }
    if (lVar15 == 0) goto LAB_0010b2d0;
    uVar7 = *(undefined8 *)(lVar15 + 0x228);
    pcVar9 = "%s: sps:Invalid BAM %pa pipe: %d\n";
LAB_0010b2c0:
    ipc_log_string(uVar7,pcVar9,"sps_bam_pipe_connect",lVar15 + 0x18,uVar2);
  }
LAB_0010b2d0:
  uVar7 = 0xffffffff;
LAB_0010b2d4:
  lVar17 = sp_el0;
  if (*(long *)(lVar17 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// sps_bam_pipe_set_params @ 0010bd88 size=876
// signature: undefined sps_bam_pipe_set_params(void)
// callers: [sps_bam_pipe_connect, sps_set_config]
//------------------------------------------------------------

undefined8 sps_bam_pipe_set_params(long param_1,uint param_2,uint param_3)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  char *pcVar7;
  long lVar8;
  
  if (0x1e < param_2) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10c0d8);
    (*pcVar3)();
  }
  lVar8 = *(long *)(param_1 + (ulong)param_2 * 8 + 0x100);
  if (((1 < logging_option) && (1 < debug_level_option)) &&
     ((print_limit_option == 0 ||
      (iVar4 = ___ratelimit(sps_bam_pipe_set_params__rs,"sps_bam_pipe_set_params"), iVar4 != 0)))) {
    _printk(&DAT_001226c7,"sps_bam_pipe_set_params",param_1 + 0x18,param_2,param_3);
  }
  if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 3)) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x220),"%s: sps:BAM %pa pipe %d opt 0x%x\n",
                   "sps_bam_pipe_set_params",param_1 + 0x18,param_2,param_3);
  }
  *(uint *)(lVar8 + 0xcc) = param_3 & 0x80000000;
  *(byte *)(lVar8 + 0xd0) = (byte)(param_3 >> 0x13) & 1;
  if (((param_3 & 0x13000021) != 0) && ((*(uint *)(lVar8 + 0xb8) >> 4 & 1) != 0)) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar4 = ___ratelimit(sps_bam_pipe_set_params__rs_163,"sps_bam_pipe_set_params"), iVar4 != 0
        )))) {
      _printk(&DAT_001202e8,"sps_bam_pipe_set_params",param_1 + 0x18,param_2,param_3);
    }
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                     "%s: sps:Invalid option for BAM-to-BAM: BAM %pa pipe %d opt 0x%x\n",
                     "sps_bam_pipe_set_params",param_1 + 0x18,param_2,param_3);
    }
    return 0xffffffff;
  }
  if (((((param_3 & 0x2000000) != 0) || (*(long *)(lVar8 + 0xf8) != 0)) ||
      (*(int *)(lVar8 + 0xdc) == 0)) || ((*(uint *)(lVar8 + 0xb8) >> 4 & 1) != 0))
  goto LAB_0010beac;
  uVar1 = *(int *)(lVar8 + 0xe0) + *(int *)(lVar8 + 0xdc) * 8;
  if (uVar1 < 0x1001) {
    if ((*(byte *)(param_1 + 0x11) & 1) == 0) {
      lVar5 = __kmalloc(uVar1,0xdc0);
      *(long *)(lVar8 + 0xf8) = lVar5;
    }
    else {
      lVar2 = param_1 + (ulong)param_2 * 8;
      lVar5 = *(long *)(lVar2 + 0x240);
      if (lVar5 != 0) {
        *(long *)(lVar8 + 0xf8) = lVar5;
        goto LAB_0010bfc4;
      }
      uVar6 = __kmalloc(uVar1,0xdc0);
      *(undefined8 *)(lVar8 + 0xf8) = uVar6;
      *(undefined8 *)(lVar2 + 0x240) = uVar6;
      lVar5 = *(long *)(lVar8 + 0xf8);
    }
    if (lVar5 == 0) {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar4 = ___ratelimit(sps_bam_pipe_set_params__rs_166,"sps_bam_pipe_set_params"),
          iVar4 != 0)))) {
        _printk(&DAT_001226eb,"sps_bam_pipe_set_params",param_2,param_1 + 0x18);
      }
      if (param_1 == 0) {
        return 0xfffffff4;
      }
      uVar6 = *(undefined8 *)(param_1 + 0x228);
      pcVar7 = "%s: sps:No memory for pipe%d of BAM %pa\n";
LAB_0010c028:
      ipc_log_string(uVar6,pcVar7,"sps_bam_pipe_set_params",param_2,param_1 + 0x18);
      return 0xfffffff4;
    }
  }
  else {
    lVar5 = vzalloc(uVar1);
    *(long *)(lVar8 + 0xf8) = lVar5;
    if (lVar5 == 0) {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar4 = ___ratelimit(sps_bam_pipe_set_params__rs_169,"sps_bam_pipe_set_params"),
          iVar4 != 0)))) {
        _printk(&DAT_00121ef4,"sps_bam_pipe_set_params",param_2,param_1 + 0x18);
      }
      if (param_1 == 0) {
        return 0xfffffff4;
      }
      uVar6 = *(undefined8 *)(param_1 + 0x228);
      pcVar7 = "%s: sps:No memory for pipe %d of BAM %pa\n";
      goto LAB_0010c028;
    }
  }
LAB_0010bfc4:
  *(undefined4 *)(lVar8 + 0x100) = *(undefined4 *)(lVar8 + 0xf4);
  *(ulong *)(lVar8 + 0x108) = lVar5 + (ulong)*(uint *)(lVar8 + 0xe0);
LAB_0010beac:
  *(uint *)(lVar8 + 0xc4) = param_3 & 0xff;
  pipe_set_irq(param_1,param_2,param_3 & 0x1000000);
  *(uint *)(lVar8 + 0xe4) = param_3 & 0x8000000;
  *(uint *)(lVar8 + 0x270) = param_3 & 0x2000000;
  *(uint *)(lVar8 + 0x274) = param_3 & 0x10000000;
  return 0;
}



//------------------------------------------------------------
// sps_bam_pipe_disconnect @ 0010c0f8 size=844
// signature: undefined sps_bam_pipe_disconnect(void)
// callers: [sps_rm_state_change]
//------------------------------------------------------------

undefined8 sps_bam_pipe_disconnect(long param_1,ulong param_2)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  code *pcVar4;
  int iVar5;
  char *pcVar6;
  ulong uVar7;
  long *plVar8;
  undefined8 uVar9;
  uint uVar10;
  ulong uVar11;
  
  uVar7 = param_2 & 0xffffffff;
  if ((uint)param_2 < *(uint *)(param_1 + 0x30)) {
    if (0x1e < (uint)param_2) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10c428);
      (*pcVar4)();
    }
    lVar1 = param_1 + uVar7 * 8;
    plVar8 = *(long **)(lVar1 + 0x100);
    if (plVar8 == (long *)0xffffffff77777777 || plVar8 == (long *)0x0) {
      uVar9 = 0xffffffff;
    }
    else {
      uVar11 = 1L << (param_2 & 0x3f);
      uVar10 = (uint)uVar11;
      if ((uVar11 & *(uint *)(param_1 + 0xf8)) != 0) {
        uVar9 = _raw_spin_lock_irqsave(param_1 + 0xe4);
        uVar11 = __list_del_entry_valid(plVar8);
        if ((uVar11 & 1) != 0) {
          lVar2 = *plVar8;
          plVar3 = (long *)plVar8[1];
          *(long **)(lVar2 + 8) = plVar3;
          *plVar3 = lVar2;
        }
        *plVar8 = (long)&DAT_dead000000000100;
        plVar8[1] = -0x2152fffffffffede;
        *(uint *)(param_1 + 0xf8) = *(uint *)(param_1 + 0xf8) & (uVar10 ^ 0xffffffff);
        _raw_spin_unlock_irqrestore(param_1 + 0xe4,uVar9);
      }
      *(uint *)(param_1 + 0xfc) = *(uint *)(param_1 + 0xfc) & ~uVar10;
      if (*(char *)((long)plVar8 + 0x56) < '\0') {
        if (((1 < logging_option) && (1 < debug_level_option)) &&
           ((print_limit_option == 0 ||
            (iVar5 = ___ratelimit(sps_bam_pipe_disconnect__rs_155,"sps_bam_pipe_disconnect"),
            iVar5 != 0)))) {
          _printk(&DAT_00121ed3,"sps_bam_pipe_disconnect",param_1 + 0x18,uVar7);
        }
        if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 3)) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x220),"%s: sps:BAM %pa pipe %d exits\n",
                         "sps_bam_pipe_disconnect",param_1 + 0x18,uVar7);
        }
      }
      else {
        bam_pipe_exit(param_1 + 0xd8,uVar7,*(undefined4 *)(param_1 + 0x80));
      }
      if (plVar8[0x1f] != 0) {
        uVar10 = (int)plVar8[0x1c] + *(int *)((long)plVar8 + 0xdc) * 8;
        if (uVar10 < 0x1001) {
          if ((*(byte *)(param_1 + 0x11) & 1) == 0) {
            kfree();
          }
          else {
            memset((void *)plVar8[0x1f],0,(ulong)uVar10);
          }
        }
        else {
          vfree();
        }
        plVar8[0x1f] = 0;
      }
      *(undefined8 *)(lVar1 + 0x100) = 0xffffffff77777777;
      *plVar8 = (long)plVar8;
      plVar8[1] = (long)plVar8;
      plVar8[0x17] = -0x100000000;
      plVar8[0x18] = 0;
      plVar8[0x1b] = 0xffffffff;
      *(undefined4 *)(plVar8 + 0x1c) = 0;
      *(undefined1 *)(plVar8 + 0x50) = 0;
      *(undefined1 *)(plVar8 + 0x1a) = 0;
      memset(plVar8 + 0x1d,0,0x198);
      uVar9 = 0;
      plVar8[0x46] = (long)(plVar8 + 0x46);
      plVar8[0x47] = (long)(plVar8 + 0x46);
    }
    if ((plVar8 != (long *)0x0) && (plVar8 != (long *)0xffffffff77777777)) {
      return uVar9;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar5 = ___ratelimit(sps_bam_pipe_disconnect__rs_158,"sps_bam_pipe_disconnect"), iVar5 != 0
        )))) {
      _printk(&DAT_00125368,"sps_bam_pipe_disconnect",param_1 + 0x18,uVar7);
    }
    if (param_1 == 0) {
      return uVar9;
    }
    pcVar6 = "%s: sps:BAM %pa pipe %d already disconnected\n";
  }
  else {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar5 = ___ratelimit(sps_bam_pipe_disconnect__rs,"sps_bam_pipe_disconnect"), iVar5 != 0))))
    {
      _printk(&DAT_0011d647,"sps_bam_pipe_disconnect",param_1 + 0x18,uVar7);
    }
    uVar9 = 0xffffffff;
    if (param_1 == 0) {
      return 0xffffffff;
    }
    pcVar6 = "%s: sps:Invalid BAM %pa pipe: %d\n";
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x228),pcVar6,"sps_bam_pipe_disconnect",param_1 + 0x18,
                 uVar7);
  return uVar9;
}



//------------------------------------------------------------
// pipe_set_irq @ 0010c444 size=596
// signature: undefined pipe_set_irq(void)
// callers: [sps_bam_pipe_set_params, sps_bam_check_irq]
//------------------------------------------------------------

void pipe_set_irq(long param_1,uint param_2,int param_3)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  uint uVar5;
  long lVar6;
  
  if (0x1e < param_2) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10c660);
    (*pcVar1)();
  }
  lVar6 = *(long *)(param_1 + (ulong)param_2 * 8 + 0x100);
  if (((1 < logging_option) && (1 < debug_level_option)) &&
     ((print_limit_option == '\0' ||
      (iVar3 = ___ratelimit(pipe_set_irq__rs,"pipe_set_irq"), iVar3 != 0)))) {
    _printk(&DAT_00123684,"pipe_set_irq",param_1 + 0x18,param_2,param_3,
            *(undefined4 *)(lVar6 + 0xc4),*(undefined4 *)(lVar6 + 0xb8),
            *(undefined4 *)(param_1 + 0xa0));
  }
  if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 3)) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x220),
                   "%s: sps:BAM:%pa; pipe %d; poll:%d, irq_mask:0x%x; pipe state:0x%x; dev state:0x%x\n"
                   ,"pipe_set_irq",param_1 + 0x18,param_2,param_3,*(undefined4 *)(lVar6 + 0xc4),
                   *(undefined4 *)(lVar6 + 0xb8),*(undefined4 *)(param_1 + 0xa0));
  }
  if ((param_3 == 0) && (*(int *)(lVar6 + 0xc4) != 0)) {
    uVar5 = *(uint *)(lVar6 + 0xb8);
    if ((*(byte *)(param_1 + 0xa0) >> 2 & 1) == 0) {
      bVar2 = 1 < logging_option;
      *(uint *)(lVar6 + 0xb8) = uVar5 & 0xfffffffb;
      *(undefined4 *)(lVar6 + 200) = 1;
      if (((bVar2) && (1 < debug_level_option)) &&
         ((print_limit_option == '\0' ||
          (iVar3 = ___ratelimit(pipe_set_irq__rs_284,"pipe_set_irq"), iVar3 != 0)))) {
        _printk(&DAT_0011f8df,"pipe_set_irq",param_1 + 0x18,param_2);
      }
      if ((param_1 == 0) || (2 < *(uint *)(param_1 + 0x238))) {
        uVar4 = 0;
      }
      else {
        ipc_log_string(*(undefined8 *)(param_1 + 0x220),
                       "%s: sps:BAM %pa pipe %d forced to use polling\n","pipe_set_irq",
                       param_1 + 0x18,param_2);
        uVar4 = 0;
      }
      goto LAB_0010c4ec;
    }
    if ((uVar5 & 0x14) == 0x10) {
      bam_pipe_get_and_clear_irq_status(param_1 + 0xd8,param_2);
      uVar5 = *(uint *)(lVar6 + 0xb8);
    }
    uVar5 = uVar5 | 4;
    uVar4 = 1;
    *(undefined4 *)(lVar6 + 200) = 0;
  }
  else {
    uVar4 = 0;
    uVar5 = *(uint *)(lVar6 + 0xb8) & 0xfffffffb;
    *(undefined4 *)(lVar6 + 200) = 1;
  }
  *(uint *)(lVar6 + 0xb8) = uVar5;
LAB_0010c4ec:
  if ((*(byte *)(lVar6 + 0xb8) >> 5 & 1) == 0) {
    bam_pipe_set_irq(param_1 + 0xd8,param_2,uVar4,*(undefined4 *)(lVar6 + 0xc4),
                     *(undefined4 *)(param_1 + 0x80));
  }
  else {
    bam_pipe_set_mti(param_1 + 0xd8,param_2,uVar4,*(undefined4 *)(lVar6 + 0xc4),
                     *(undefined4 *)(lVar6 + 0xd4));
  }
  return;
}



//------------------------------------------------------------
// sps_bam_enable_all_irqs @ 0010c69c size=208
// signature: undefined sps_bam_enable_all_irqs(void)
// callers: [sps_bam_enable_irqs]
//------------------------------------------------------------

void sps_bam_enable_all_irqs(long param_1)

{
  undefined8 uVar1;
  long *plVar2;
  
  uVar1 = _raw_spin_lock_irqsave(param_1 + 0xe4);
  bam_set_global_irq(param_1 + 0xd8,*(undefined4 *)(param_1 + 0x80),0x16,1);
  for (plVar2 = *(long **)(param_1 + 0x1f8); plVar2 != (long *)(param_1 + 0x1f8);
      plVar2 = (long *)*plVar2) {
    if (((plVar2 != (long *)0xffffffff77777777) && (plVar2 != (long *)0x0)) &&
       (*(char *)(plVar2 + 0x50) == '\0')) {
      bam_pipe_set_irq(param_1 + 0xd8,*(undefined4 *)((long)plVar2 + 0xbc),1,
                       *(undefined4 *)((long)plVar2 + 0xc4),*(undefined4 *)(param_1 + 0x80));
    }
  }
  DataSynchronizationBarrier(3,2,0);
  *(undefined1 *)(param_1 + 0x338) = 0;
  _raw_spin_unlock_irqrestore(param_1 + 0xe4,uVar1);
  return;
}



//------------------------------------------------------------
// sps_bam_disable_all_irqs @ 0010c770 size=212
// signature: undefined sps_bam_disable_all_irqs(void)
// callers: [sps_bam_disable_irqs]
//------------------------------------------------------------

void sps_bam_disable_all_irqs(long param_1)

{
  undefined8 uVar1;
  long *plVar2;
  
  uVar1 = _raw_spin_lock_irqsave(param_1 + 0xe4);
  bam_set_global_irq(param_1 + 0xd8,*(undefined4 *)(param_1 + 0x80),0,0);
  for (plVar2 = *(long **)(param_1 + 0x1f8); plVar2 != (long *)(param_1 + 0x1f8);
      plVar2 = (long *)*plVar2) {
    if (((plVar2 != (long *)0xffffffff77777777) && (plVar2 != (long *)0x0)) &&
       (*(char *)(plVar2 + 0x50) == '\0')) {
      bam_pipe_set_irq(param_1 + 0xd8,*(undefined4 *)((long)plVar2 + 0xbc),0,0,
                       *(undefined4 *)(param_1 + 0x80));
    }
  }
  DataSynchronizationBarrier(3,2,0);
  *(undefined1 *)(param_1 + 0x338) = 1;
  _raw_spin_unlock_irqrestore(param_1 + 0xe4,uVar1);
  return;
}



//------------------------------------------------------------
// sps_bam_pipe_enable @ 0010c848 size=76
// signature: undefined sps_bam_pipe_enable(void)
// callers: [sps_rm_state_change]
//------------------------------------------------------------

undefined8 sps_bam_pipe_enable(long param_1,uint param_2)

{
  code *pcVar1;
  long lVar2;
  
  if (0x1e < param_2) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10c894);
    (*pcVar1)();
  }
  lVar2 = *(long *)(param_1 + (ulong)param_2 * 8 + 0x100);
  bam_pipe_enable(param_1 + 0xd8);
  *(uint *)(lVar2 + 0xb8) = *(uint *)(lVar2 + 0xb8) | 8;
  return 0;
}



//------------------------------------------------------------
// sps_bam_pipe_disable @ 0010c898 size=284
// signature: undefined sps_bam_pipe_disable(void)
// callers: [sps_rm_state_change]
//------------------------------------------------------------

undefined8 sps_bam_pipe_disable(long param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  
  if (0x1e < param_2) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10c98c);
    (*pcVar1)();
  }
  lVar3 = *(long *)(param_1 + (ulong)param_2 * 8 + 0x100);
  if (*(char *)(lVar3 + 0x56) < '\0') {
    if (((1 < logging_option) && (1 < debug_level_option)) &&
       ((print_limit_option == '\0' ||
        (iVar2 = ___ratelimit(sps_bam_pipe_disable__rs,"sps_bam_pipe_disable"), iVar2 != 0)))) {
      _printk(&DAT_00123cbd,"sps_bam_pipe_disable",param_1 + 0x18,param_2);
    }
    if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 3)) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x220),
                     "%s: sps:BAM %pa pipe %d enters disable state\n","sps_bam_pipe_disable",
                     param_1 + 0x18,param_2);
    }
  }
  else {
    bam_pipe_disable(param_1 + 0xd8,param_2);
  }
  *(uint *)(lVar3 + 0xb8) = *(uint *)(lVar3 + 0xb8) & 0xfffffff7;
  return 0;
}



//------------------------------------------------------------
// sps_bam_pipe_reg_event @ 0010c9b8 size=520
// signature: undefined sps_bam_pipe_reg_event(void)
// callers: [sps_register_event]
//------------------------------------------------------------

undefined8 sps_bam_pipe_reg_event(long param_1,uint param_2,uint *param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  
  if (0x1e < param_2) {
LAB_0010cbbc:
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10cbc0);
    (*pcVar2)();
  }
  lVar5 = *(long *)(param_1 + (ulong)param_2 * 8 + 0x100);
  if (((*(int *)(lVar5 + 0x270) == 0) || (*(long *)(param_3 + 2) == 0)) ||
     (uVar4 = param_3[1], uVar4 == 0)) {
    lVar6 = 0;
    do {
      if ((*(uint *)((long)&DAT_00125df8 + lVar6) & *param_3) != 0) {
        uVar4 = *(int *)((long)&opt_event_table + lVar6) - 1;
        if ((int)uVar4 < 0) {
          if ((logging_option != '\x01') &&
             ((print_limit_option < 3 ||
              (iVar3 = ___ratelimit(sps_bam_pipe_reg_event__rs_179,"sps_bam_pipe_reg_event"),
              iVar3 != 0)))) {
            _printk(&DAT_00123ced,"sps_bam_pipe_reg_event",param_1 + 0x18,param_2,param_3[1]);
          }
          if (param_1 != 0) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                           "%s: sps:Negative event index: BAM %pa pipe %d mode %d\n",
                           "sps_bam_pipe_reg_event",param_1 + 0x18,param_2,param_3[1]);
          }
        }
        else {
          if (9 < uVar4) goto LAB_0010cbbc;
          lVar1 = lVar5 + (ulong)uVar4 * 0x20;
          *(undefined8 *)(lVar1 + 0x110) = *(undefined8 *)(param_3 + 2);
          *(undefined8 *)(lVar1 + 0x118) = *(undefined8 *)(param_3 + 4);
          *(uint *)(lVar1 + 0x120) = param_3[1];
          *(undefined8 *)(lVar1 + 0x128) = *(undefined8 *)(param_3 + 6);
        }
      }
      lVar6 = lVar6 + 0xc;
      if (lVar6 == 0x60) {
        return 0;
      }
    } while( true );
  }
  if (logging_option != '\x01') {
    if (2 < print_limit_option) {
      iVar3 = ___ratelimit(sps_bam_pipe_reg_event__rs,"sps_bam_pipe_reg_event");
      if (iVar3 == 0) goto LAB_0010ca48;
      uVar4 = param_3[1];
    }
    _printk(&DAT_0011d19a,"sps_bam_pipe_reg_event",param_1 + 0x18,param_2,uVar4);
  }
LAB_0010ca48:
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                   "%s: sps:Only callback events support for NO_Q: BAM %pa pipe %d mode %d\n",
                   "sps_bam_pipe_reg_event",param_1 + 0x18,param_2,param_3[1]);
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_bam_pipe_transfer_one @ 0010cbc4 size=1556
// signature: undefined sps_bam_pipe_transfer_one(void)
// callers: [sps_bam_pipe_transfer, sps_transfer_one]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

undefined8
sps_bam_pipe_transfer_one
          (long param_1,uint param_2,undefined4 param_3,uint param_4,long param_5,uint param_6)

{
  uint uVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined8 *puVar7;
  uint uVar8;
  long lVar9;
  undefined8 local_48;
  
  if (0x1e < param_2) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10d168);
    (*pcVar2)();
  }
  lVar9 = *(long *)(param_1 + (ulong)param_2 * 8 + 0x100);
  local_48 = 0;
  if (((1 < logging_option) && (3 < debug_level_option)) &&
     ((print_limit_option == 0 ||
      (iVar4 = ___ratelimit(sps_bam_pipe_transfer_one__rs,"sps_bam_pipe_transfer_one"), iVar4 != 0))
     )) {
    _printk(&DAT_001235cc,"sps_bam_pipe_transfer_one",param_1 + 0x18,param_2,param_3,param_4,param_6
           );
  }
  if ((param_1 != 0) && (*(int *)(param_1 + 0x238) == 0)) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x210),
                   "%s: sps:BAM %pa pipe %d addr 0x%pK size 0x%x flags 0x%x\n",
                   "sps_bam_pipe_transfer_one",param_1 + 0x18,param_2,param_3,param_4,param_6);
  }
  if ((*(byte *)(lVar9 + 0xb8) & 0x50) == 0) {
    iVar4 = *(int *)(lVar9 + 0x270);
    if ((param_5 == 0) || (iVar4 == 0)) {
      uVar1 = *(int *)(lVar9 + 0xf0) + 8;
      if (*(uint *)(lVar9 + 0xe0) <= uVar1) {
        uVar1 = 0;
      }
      if (uVar1 != *(uint *)(lVar9 + 0xf4)) {
LAB_0010cecc:
        if (iVar4 == 0) {
          puVar7 = (undefined8 *)(*(long *)(lVar9 + 0xf8) + (ulong)*(uint *)(lVar9 + 0xf0));
        }
        else {
          puVar7 = &local_48;
        }
        *(undefined4 *)puVar7 = param_3;
        *(short *)((long)puVar7 + 4) = (short)param_4;
        if ((param_6 >> 4 & 1) == 0) {
          uVar8 = (param_6 & 0xff0f) << 0x10 | param_4 & 0xffff;
        }
        else {
          uVar8 = param_4 & 0xffff | (param_6 & 0xf) << 0x10;
          if (*(int *)(lVar9 + 0xd8) == 0) {
            uVar8 = uVar8 | 0x80000000;
          }
          else {
            uVar8 = uVar8 | 0xc0000000;
          }
        }
        *(uint *)((long)puVar7 + 4) = uVar8;
        *(undefined8 *)(*(long *)(lVar9 + 0xe8) + (ulong)*(uint *)(lVar9 + 0xf0)) = *puVar7;
        if (*(int *)(lVar9 + 0x270) == 0) {
          *(long *)(*(long *)(lVar9 + 0x108) + ((ulong)*(uint *)(lVar9 + 0xf0) & 0xfffffff8)) =
               param_5;
          *(uint *)(lVar9 + 0xf0) = uVar1;
        }
        else {
          *(uint *)(lVar9 + 0xf0) = uVar1;
        }
        if ((param_6 >> 5 & 1) == 0) {
          DataSynchronizationBarrier(3,2,0);
          bam_pipe_set_desc_write_offset(param_1 + 0xd8,param_2,uVar1);
          iVar4 = *(int *)(param_1 + 0x238);
        }
        else {
          iVar4 = *(int *)(param_1 + 0x238);
        }
        if (iVar4 == 0) {
          if (((1 < logging_option) && (3 < debug_level_option)) &&
             ((print_limit_option == 0 ||
              (iVar4 = ___ratelimit(sps_bam_pipe_transfer_one__rs_200,"sps_bam_pipe_transfer_one"),
              iVar4 != 0)))) {
            uVar3 = bam_pipe_get_desc_write_offset(param_1 + 0xd8,param_2);
            _printk(&DAT_0011f414,"sps_bam_pipe_transfer_one",param_1 + 0x18,param_2,uVar1,uVar3);
          }
          if ((param_1 != 0) && (*(int *)(param_1 + 0x238) == 0)) {
            uVar5 = *(undefined8 *)(param_1 + 0x210);
            uVar3 = bam_pipe_get_desc_write_offset(param_1 + 0xd8,param_2);
            ipc_log_string(uVar5,
                           "%s: sps: BAM phy addr:%pa; pipe %d; write pointer to tell HW: 0x%x; write pointer read from HW: 0x%x\n"
                           ,"sps_bam_pipe_transfer_one",param_1 + 0x18,param_2,uVar1,uVar3);
          }
        }
        return 0;
      }
      if ((*(int *)(lVar9 + 0x274) == 0) && (*(int *)(lVar9 + 200) != 0)) {
        pipe_handler_eot(param_1,lVar9);
        if (uVar1 != *(uint *)(lVar9 + 0xf4)) {
          iVar4 = *(int *)(lVar9 + 0x270);
          goto LAB_0010cecc;
        }
        if ((sps_bam_pipe_transfer_one_show_recom & 1) == 0) {
          sps_bam_pipe_transfer_one_show_recom = 1;
          if ((logging_option != 1) &&
             ((print_limit_option < 3 ||
              (iVar4 = ___ratelimit(sps_bam_pipe_transfer_one__rs_190,"sps_bam_pipe_transfer_one"),
              iVar4 != 0)))) {
            _printk(&DAT_0011e33c,"sps_bam_pipe_transfer_one",param_1 + 0x18,param_2);
          }
          if (param_1 != 0) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                           "%s: sps:Client of BAM %pa pipe %d is recommended to have flow control\n"
                           ,"sps_bam_pipe_transfer_one",param_1 + 0x18,param_2);
          }
        }
        if (((1 < logging_option) && (2 < debug_level_option)) &&
           ((print_limit_option == 0 ||
            (iVar4 = ___ratelimit(sps_bam_pipe_transfer_one__rs_193,"sps_bam_pipe_transfer_one"),
            iVar4 != 0)))) {
          _printk(&DAT_00124af3,"sps_bam_pipe_transfer_one",param_1 + 0x18,param_2);
        }
        if (param_1 == 0) {
          return 0xffffffff;
        }
        if (1 < *(uint *)(param_1 + 0x238)) {
          return 0xffffffff;
        }
        uVar5 = *(undefined8 *)(param_1 + 0x218);
        pcVar6 = "%s: sps:Descriptor FIFO is full for BAM %pa pipe %d after pipe_handler_eot\n";
      }
      else {
        if ((sps_bam_pipe_transfer_one_show_recom & 1) == 0) {
          sps_bam_pipe_transfer_one_show_recom = 1;
          if ((logging_option != 1) &&
             ((print_limit_option < 3 ||
              (iVar4 = ___ratelimit(sps_bam_pipe_transfer_one__rs_196,"sps_bam_pipe_transfer_one"),
              iVar4 != 0)))) {
            _printk(&DAT_0011e33c,"sps_bam_pipe_transfer_one",param_1 + 0x18,param_2);
          }
          if (param_1 != 0) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                           "%s: sps:Client of BAM %pa pipe %d is recommended to have flow control\n"
                           ,"sps_bam_pipe_transfer_one",param_1 + 0x18,param_2);
          }
        }
        if (((1 < logging_option) && (2 < debug_level_option)) &&
           ((print_limit_option == 0 ||
            (iVar4 = ___ratelimit(sps_bam_pipe_transfer_one__rs_197,"sps_bam_pipe_transfer_one"),
            iVar4 != 0)))) {
          _printk(&DAT_0011fdf0,"sps_bam_pipe_transfer_one",param_1 + 0x18,param_2);
        }
        if (param_1 == 0) {
          return 0xffffffff;
        }
        if (1 < *(uint *)(param_1 + 0x238)) {
          return 0xffffffff;
        }
        uVar5 = *(undefined8 *)(param_1 + 0x218);
        pcVar6 = "%s: sps:Descriptor FIFO is full for BAM %pa pipe %d\n";
      }
    }
    else {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar4 = ___ratelimit(sps_bam_pipe_transfer_one__rs_187,"sps_bam_pipe_transfer_one"),
          iVar4 != 0)))) {
        _printk(&DAT_0011ed9a,"sps_bam_pipe_transfer_one",param_1 + 0x18,param_2);
      }
      if (param_1 == 0) {
        return 0xffffffff;
      }
      uVar5 = *(undefined8 *)(param_1 + 0x228);
      pcVar6 = "%s: sps:User pointer arg non-NULL: BAM %pa pipe %d\n";
    }
  }
  else {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar4 = ___ratelimit(sps_bam_pipe_transfer_one__rs_184,"sps_bam_pipe_transfer_one"),
        iVar4 != 0)))) {
      _printk(&DAT_00124dad,"sps_bam_pipe_transfer_one",param_1 + 0x18,param_2);
    }
    if (param_1 == 0) {
      return 0xffffffff;
    }
    uVar5 = *(undefined8 *)(param_1 + 0x228);
    pcVar6 = "%s: sps:Transfer on BAM-to-BAM: BAM %pa pipe %d\n";
  }
  ipc_log_string(uVar5,pcVar6,"sps_bam_pipe_transfer_one",param_1 + 0x18,param_2);
  return 0xffffffff;
}



//------------------------------------------------------------
// pipe_handler_eot @ 0010d1d8 size=1520
// signature: undefined pipe_handler_eot(void)
// callers: [sps_bam_pipe_get_iovec, sps_bam_pipe_transfer_one, sps_bam_check_irq, sps_bam_pipe_get_event]
//------------------------------------------------------------

void pipe_handler_eot(long param_1,long param_2)

{
  long lVar1;
  undefined8 *puVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  undefined4 uVar7;
  uint uVar8;
  bool bVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  undefined8 uVar15;
  char *pcVar16;
  undefined8 *puVar17;
  undefined8 *puVar18;
  long lVar19;
  undefined8 *puVar20;
  undefined8 *puVar21;
  uint uVar22;
  ulong uVar23;
  undefined8 *puVar24;
  long *plVar25;
  
  uVar11 = *(undefined4 *)(param_2 + 0xbc);
  if (*(int *)(param_2 + 0x278) == 0) {
    lVar1 = param_1 + 0xd8;
    iVar13 = *(int *)(param_2 + 0xd8);
    *(undefined4 *)(param_2 + 0x278) = 1;
    uVar10 = bam_pipe_get_desc_read_offset(lVar1,uVar11);
    uVar23 = (ulong)uVar10;
    if (*(int *)(param_1 + 0x238) == 0) {
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar14 = ___ratelimit(pipe_handler_eot__rs_289,"pipe_handler_eot"), iVar14 != 0)))) {
        uVar7 = *(undefined4 *)(param_2 + 0xbc);
        uVar12 = bam_pipe_get_desc_write_offset(lVar1,uVar11);
        _printk(&DAT_0012580d,"pipe_handler_eot",uVar7,uVar23,uVar12,*(undefined4 *)(param_2 + 0xf4)
               );
      }
      if ((param_1 != 0) && (*(int *)(param_1 + 0x238) == 0)) {
        uVar15 = *(undefined8 *)(param_1 + 0x210);
        uVar7 = *(undefined4 *)(param_2 + 0xbc);
        uVar11 = bam_pipe_get_desc_write_offset(lVar1,uVar11);
        ipc_log_string(uVar15,
                       "%s: sps: pipe index:%d; read pointer:0x%x; write pointer:0x%x; sys.acked_offset:0x%x\n"
                       ,"pipe_handler_eot",uVar7,uVar23,uVar11,*(undefined4 *)(param_2 + 0xf4));
      }
    }
    uVar22 = uVar10;
    if ((iVar13 == 0) && (*(char *)(param_2 + 0xd0) != '\0')) {
      if (uVar10 == 0) {
        uVar23 = (ulong)*(uint *)(param_2 + 0xe0);
      }
      uVar22 = (int)uVar23 - 8;
      if ((*(byte *)(*(long *)(param_2 + 0xe8) + uVar23 + -1) & 0x40) != 0) {
        uVar22 = uVar10;
      }
    }
    if (*(int *)(param_2 + 0x270) == 0) {
      lVar1 = 0xf4;
      if (*(int *)(param_2 + 0x274) != 0) {
        lVar1 = 0x100;
      }
      uVar10 = *(uint *)(param_2 + lVar1);
      uVar23 = (ulong)uVar10;
      if (uVar10 != uVar22) {
        uVar4 = (*(uint *)(param_2 + 0xc4) & 0x20) << 9;
        uVar5 = uVar4 | (*(uint *)(param_2 + 0xc4) & 1) << 0xf;
        if (iVar13 == 0) {
          puVar18 = *(undefined8 **)(param_2 + 0xe8);
          puVar21 = (undefined8 *)((long)puVar18 + uVar23);
          puVar24 = (undefined8 *)((long)*(undefined8 **)(param_2 + 0xf8) + uVar23);
          if (uVar22 < uVar10) {
            puVar2 = (undefined8 *)((long)puVar18 + (ulong)*(uint *)(param_2 + 0xe0));
            bVar9 = puVar21 < puVar2;
            puVar17 = *(undefined8 **)(param_2 + 0xf8);
            puVar20 = puVar21;
            puVar21 = puVar18;
            if (bVar9) {
              do {
                puVar21 = puVar20 + 1;
                *puVar24 = *puVar20;
                puVar20 = puVar21;
                puVar24 = puVar24 + 1;
              } while (puVar21 < puVar2);
              puVar18 = *(undefined8 **)(param_2 + 0xe8);
              puVar17 = *(undefined8 **)(param_2 + 0xf8);
              puVar21 = puVar18;
            }
          }
          else {
            puVar17 = puVar24;
          }
          for (; puVar21 < (undefined8 *)((long)puVar18 + (ulong)uVar22); puVar21 = puVar21 + 1) {
            *puVar17 = *puVar21;
            puVar17 = puVar17 + 1;
          }
        }
        puVar21 = (undefined8 *)(param_2 + 0x240);
        puVar24 = (undefined8 *)(*(long *)(param_2 + 0xf8) + uVar23);
        plVar25 = (long *)(*(long *)(param_2 + 0x108) + (uVar23 & 0xfffffff8));
        while( true ) {
          if (((1 < logging_option) && (3 < debug_level_option)) &&
             ((print_limit_option == 0 ||
              (iVar13 = ___ratelimit(pipe_handler_eot__rs_298,"pipe_handler_eot"), iVar13 != 0)))) {
            puVar6 = &DAT_0012037f;
            if (*plVar25 != 0) {
              puVar6 = &DAT_001213a8;
            }
            _printk(&DAT_001203e7,"pipe_handler_eot",*(undefined4 *)(param_2 + 0xbc),
                    *(undefined4 *)puVar24,*(uint *)((long)puVar24 + 4) & 0xffff,
                    *(uint *)((long)puVar24 + 4) >> 0x10,uVar5,puVar6);
          }
          if ((param_1 != 0) && (*(int *)(param_1 + 0x238) == 0)) {
            puVar6 = &DAT_0012037f;
            if (*plVar25 != 0) {
              puVar6 = &DAT_001213a8;
            }
            ipc_log_string(*(undefined8 *)(param_1 + 0x210),
                           "%s: sps: pipe index:%d; iovec addr:0x%pK; size:0x%x; flags:0x%x; enabled:0x%x; *user is %s NULL\n"
                           ,"pipe_handler_eot",*(undefined4 *)(param_2 + 0xbc),
                           *(undefined4 *)puVar24,*(uint *)((long)puVar24 + 4) & 0xffff,
                           *(uint *)((long)puVar24 + 4) >> 0x10,uVar5,puVar6);
          }
          uVar10 = (int)uVar23 + 8;
          if (*(uint *)(param_2 + 0xe0) <= uVar10) {
            uVar10 = 0;
          }
          uVar23 = (ulong)uVar10;
          *(uint *)(param_2 + lVar1) = uVar10;
          uVar8 = *(uint *)((long)puVar24 + 4) >> 0x10;
          if ((*plVar25 != 0) || ((uVar8 & uVar5) != 0)) {
            *(undefined8 *)(param_2 + 0x260) = 0;
            *(undefined8 *)(param_2 + 0x268) = 0;
            *(undefined8 *)(param_2 + 0x250) = 0;
            *(undefined8 *)(param_2 + 600) = 0;
            *puVar21 = 0;
            *(undefined8 *)(param_2 + 0x248) = 0;
            if (puVar21 == (undefined8 *)0x0) {
              if ((logging_option != 1) &&
                 ((print_limit_option < 3 ||
                  (iVar13 = ___ratelimit(pipe_handler_eot__rs_302,"pipe_handler_eot"), iVar13 != 0))
                 )) {
                _printk(&DAT_0011df81,"pipe_handler_eot",*(undefined4 *)(param_2 + 0xbc));
              }
              if (param_1 != 0) {
                ipc_log_string(*(undefined8 *)(param_1 + 0x228),"%s: sps: pipe %d: event is NULL\n",
                               "pipe_handler_eot",*(undefined4 *)(param_2 + 0xbc));
              }
            }
            else {
              iVar13 = 1;
              if ((uVar8 & uVar4) == 0) {
                iVar13 = 2;
              }
              *(undefined8 *)(param_2 + 0x260) = *puVar24;
              lVar19 = *plVar25;
              lVar3 = param_2 + (ulong)(iVar13 - 1) * 0x20;
              *(int *)(param_2 + 600) = iVar13;
              *(long *)(param_2 + 0x268) = lVar19;
              *(undefined8 *)(param_2 + 0x250) = *(undefined8 *)(lVar3 + 0x128);
              trigger_event(param_1,lVar3 + 0x110,puVar21);
            }
          }
          if (uVar10 == uVar22) break;
          if (uVar10 == 0) {
            puVar24 = *(undefined8 **)(param_2 + 0xf8);
            plVar25 = *(long **)(param_2 + 0x108);
          }
          else {
            puVar24 = puVar24 + 1;
            plVar25 = plVar25 + 1;
          }
        }
        *(undefined4 *)(param_2 + 0x278) = 0;
        return;
      }
      *(undefined4 *)(param_2 + 0x278) = 0;
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar13 = ___ratelimit(pipe_handler_eot__rs_295,"pipe_handler_eot"), iVar13 != 0)))) {
        _printk(&DAT_00123ded,"pipe_handler_eot",*(undefined4 *)(param_2 + 0xbc));
      }
      if (param_1 == 0) {
        return;
      }
      if (*(int *)(param_1 + 0x238) != 0) {
        return;
      }
      uVar15 = *(undefined8 *)(param_1 + 0x210);
      pcVar16 = "%s: sps: there is no completed desc to process for pipe %d\n";
    }
    else {
      if (*(int *)(param_2 + 0x274) == 0) {
        *(uint *)(param_2 + 0xf4) = uVar22;
      }
      *(undefined4 *)(param_2 + 0x278) = 0;
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar13 = ___ratelimit(pipe_handler_eot__rs_292,"pipe_handler_eot"), iVar13 != 0)))) {
        _printk(&DAT_001223f1,"pipe_handler_eot",*(undefined4 *)(param_2 + 0xbc));
      }
      if (param_1 == 0) {
        return;
      }
      if (*(int *)(param_1 + 0x238) != 0) {
        return;
      }
      uVar15 = *(undefined8 *)(param_1 + 0x210);
      pcVar16 = "%s: sps: pipe %d has no queue\n";
    }
    goto LAB_0010d37c;
  }
  if ((1 < logging_option) && (3 < debug_level_option)) {
    if (print_limit_option != 0) {
      iVar13 = ___ratelimit(pipe_handler_eot__rs,"pipe_handler_eot");
      if (iVar13 == 0) goto LAB_0010d220;
      uVar11 = *(undefined4 *)(param_2 + 0xbc);
    }
    _printk(&DAT_00120380,"pipe_handler_eot",uVar11);
  }
LAB_0010d220:
  if (param_1 == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x238) != 0) {
    return;
  }
  uVar15 = *(undefined8 *)(param_1 + 0x210);
  pcVar16 = "%s: sps: still handling EOT for pipe %d\n";
LAB_0010d37c:
  ipc_log_string(uVar15,pcVar16,"pipe_handler_eot",*(undefined4 *)(param_2 + 0xbc));
  return;
}



//------------------------------------------------------------
// sps_bam_pipe_transfer @ 0010d7cc size=576
// signature: undefined sps_bam_pipe_transfer(void)
// callers: [sps_transfer]
//------------------------------------------------------------

void sps_bam_pipe_transfer(long param_1,uint param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  uint uVar6;
  long lVar7;
  uint *puVar8;
  uint local_4c;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  local_4c = 0;
  if (0x1e < param_2) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10da08);
    (*pcVar1)();
  }
  uVar5 = (ulong)param_2;
  if (*(int *)(param_3 + 0x10) == 0) {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar3 = ___ratelimit(sps_bam_pipe_transfer__rs,"sps_bam_pipe_transfer"), iVar3 != 0)))) {
      _printk(&DAT_00121adf,"sps_bam_pipe_transfer",param_1 + 0x18,uVar5);
    }
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x228),"%s: sps:iovec count zero: BAM %pa pipe %d\n",
                     "sps_bam_pipe_transfer",param_1 + 0x18,uVar5);
    }
  }
  else {
    lVar7 = *(long *)(param_1 + uVar5 * 8 + 0x100);
    if ((*(int *)(lVar7 + 0x274) == 0) && (*(int *)(lVar7 + 200) != 0)) {
      sps_bam_pipe_get_unused_desc_num(param_1,uVar5,&local_4c);
      uVar6 = ~local_4c + (*(uint *)(lVar7 + 0xe0) >> 3);
    }
    else {
      sps_bam_get_free_count(param_1,uVar5,&local_4c);
      uVar6 = local_4c;
    }
    if (*(uint *)(param_3 + 0x10) <= uVar6) {
      iVar3 = *(uint *)(param_3 + 0x10) - 1;
      if (-1 < iVar3) {
        uVar4 = 0;
        puVar8 = (uint *)(*(long *)(param_3 + 8) + 4);
        do {
          uVar6 = *puVar8 >> 0x10;
          if (iVar3 == 0) {
            uVar4 = *(undefined8 *)(param_3 + 0x18);
          }
          else {
            uVar6 = uVar6 | 0x20;
          }
          iVar2 = sps_bam_pipe_transfer_one(param_1,uVar5,puVar8[-1],*puVar8 & 0xffff,uVar4,uVar6);
          if (iVar2 != 0) goto LAB_0010d93c;
          iVar3 = iVar3 + -1;
          puVar8 = puVar8 + 2;
        } while (-1 < iVar3);
      }
      uVar4 = 0;
      goto LAB_0010d99c;
    }
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar3 = ___ratelimit(sps_bam_pipe_transfer__rs_205,"sps_bam_pipe_transfer"), iVar3 != 0))))
    {
      _printk(&DAT_0011fe27,"sps_bam_pipe_transfer",param_1 + 0x18,uVar5,uVar6);
    }
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                     "%s: sps:Insufficient free desc: BAM %pa pipe %d: %d\n","sps_bam_pipe_transfer"
                     ,param_1 + 0x18,uVar5,uVar6);
    }
  }
LAB_0010d93c:
  uVar4 = 0xffffffff;
LAB_0010d99c:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// sps_bam_pipe_get_unused_desc_num @ 0010da10 size=344
// signature: undefined sps_bam_pipe_get_unused_desc_num(void)
// callers: [sps_bam_pipe_transfer, sps_get_unused_desc_num]
//------------------------------------------------------------

undefined8 sps_bam_pipe_get_unused_desc_num(long param_1,uint param_2,uint *param_3)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  
  if (0x1e < param_2) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10db4c);
    (*pcVar2)();
  }
  lVar7 = *(long *)(param_1 + (ulong)param_2 * 8 + 0x100);
  if (lVar7 == 0) {
    uVar6 = 0xffffffff;
  }
  else {
    iVar1 = *(int *)(lVar7 + 0xe0);
    uVar3 = bam_pipe_get_desc_read_offset(param_1 + 0xd8,param_2);
    if (((*(byte *)(param_1 + 0x11) >> 2 & 1) == 0) || ((*(byte *)(lVar7 + 0xb8) >> 4 & 1) != 0)) {
      uVar4 = bam_pipe_get_desc_write_offset(param_1 + 0xd8,param_2);
    }
    else {
      uVar4 = *(uint *)(lVar7 + 0xf0);
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == '\0' ||
          (iVar5 = ___ratelimit(sps_bam_pipe_get_unused_desc_num__rs,
                                "sps_bam_pipe_get_unused_desc_num"), iVar5 != 0)))) {
        _printk(&DAT_0011fe99,"sps_bam_pipe_get_unused_desc_num",param_1 + 0x18,param_2,uVar4);
      }
      if ((param_1 != 0) && (*(int *)(param_1 + 0x238) == 0)) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x210),
                       "%s: sps:BAM %pa pipe %d: peer offset in cache:0x%x\n",
                       "sps_bam_pipe_get_unused_desc_num",param_1 + 0x18,param_2,uVar4);
      }
    }
    uVar6 = 0;
    if (uVar3 <= uVar4) {
      iVar1 = 0;
    }
    *param_3 = (uVar4 - uVar3) + iVar1 >> 3;
  }
  return uVar6;
}



//------------------------------------------------------------
// sps_bam_get_free_count @ 0010db6c size=268
// signature: undefined sps_bam_get_free_count(void)
// callers: [sps_get_free_count, sps_bam_pipe_transfer]
//------------------------------------------------------------

undefined8 sps_bam_get_free_count(long param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  uint uVar5;
  long lVar6;
  
  if (0x1e < param_2) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10dc78);
    (*pcVar2)();
  }
  lVar6 = *(long *)(param_1 + (ulong)param_2 * 8 + 0x100);
  if ((*(byte *)(lVar6 + 0xb8) & 0x50) == 0) {
    uVar1 = *(uint *)(lVar6 + 0xe0);
    uVar4 = 0;
    uVar5 = *(int *)(lVar6 + 0xf0) + 8;
    if (uVar1 <= uVar5) {
      uVar5 = 0;
    }
    if (uVar5 <= *(uint *)(lVar6 + 0xf4)) {
      uVar1 = 0;
    }
    uVar5 = (*(uint *)(lVar6 + 0xf4) - uVar5) + uVar1 >> 3;
  }
  else {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar3 = ___ratelimit(sps_bam_get_free_count__rs,"sps_bam_get_free_count"), iVar3 != 0)))) {
      _printk(&DAT_001227ef,"sps_bam_get_free_count",param_1 + 0x18,param_2);
    }
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                     "%s: sps:Free count on BAM-to-BAM or remote: BAM %pa pipe %d\n",
                     "sps_bam_get_free_count",param_1 + 0x18,param_2);
    }
    uVar5 = 0;
    uVar4 = 0xffffffff;
  }
  *param_3 = uVar5;
  return uVar4;
}



//------------------------------------------------------------
// sps_bam_pipe_inject_zlt @ 0010dc7c size=1256
// signature: undefined sps_bam_pipe_inject_zlt(void)
// callers: [sps_pipe_inject_zlt]
//------------------------------------------------------------

undefined8 sps_bam_pipe_inject_zlt(long param_1,uint param_2)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  ulong uVar8;
  undefined8 uVar9;
  long lVar10;
  
  if (0x1e < param_2) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10e0d8);
    (*pcVar2)();
  }
  lVar10 = *(long *)(param_1 + (ulong)param_2 * 8 + 0x100);
  if ((*(byte *)(lVar10 + 0xb8) >> 4 & 1) == 0) {
    if (((1 < logging_option) && (1 < debug_level_option)) &&
       ((print_limit_option == 0 ||
        (iVar6 = ___ratelimit(sps_bam_pipe_inject_zlt__rs_210,"sps_bam_pipe_inject_zlt"), iVar6 != 0
        )))) {
      _printk(&DAT_00125398,"sps_bam_pipe_inject_zlt",param_1 + 0x18,param_2);
    }
    if ((param_1 == 0) || (2 < *(uint *)(param_1 + 0x238))) goto LAB_0010dd18;
    pcVar7 = "%s: sps: BAM-to-System pipe: BAM %pa pipe %d\n";
  }
  else {
    if (((1 < logging_option) && (1 < debug_level_option)) &&
       ((print_limit_option == 0 ||
        (iVar6 = ___ratelimit(sps_bam_pipe_inject_zlt__rs,"sps_bam_pipe_inject_zlt"), iVar6 != 0))))
    {
      _printk(&DAT_00124687,"sps_bam_pipe_inject_zlt",param_1 + 0x18,param_2);
    }
    if ((param_1 == 0) || (2 < *(uint *)(param_1 + 0x238))) goto LAB_0010dd18;
    pcVar7 = "%s: sps: BAM-to-BAM pipe: BAM %pa pipe %d\n";
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x220),pcVar7,"sps_bam_pipe_inject_zlt",param_1 + 0x18,
                 param_2);
LAB_0010dd18:
  if ((*(byte *)(lVar10 + 0xb8) >> 3 & 1) == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar6 = ___ratelimit(sps_bam_pipe_inject_zlt__rs_213,"sps_bam_pipe_inject_zlt"), iVar6 != 0
        )))) {
      _printk(&DAT_00124131,"sps_bam_pipe_inject_zlt",param_1 + 0x18,param_2);
    }
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x228),"%s: sps: BAM %pa pipe %d is not enabled\n",
                     "sps_bam_pipe_inject_zlt",param_1 + 0x18,param_2);
    }
  }
  else {
    lVar1 = param_1 + 0xd8;
    uVar3 = bam_pipe_get_desc_read_offset(lVar1,param_2);
    uVar4 = bam_pipe_get_desc_write_offset(lVar1,param_2);
    uVar8 = (ulong)uVar4;
    if (((1 < logging_option) && (1 < debug_level_option)) &&
       ((print_limit_option == 0 ||
        (iVar6 = ___ratelimit(sps_bam_pipe_inject_zlt__rs_216,"sps_bam_pipe_inject_zlt"), iVar6 != 0
        )))) {
      _printk(&DAT_00124e2c,"sps_bam_pipe_inject_zlt",param_1 + 0x18,param_2,uVar3,uVar8);
    }
    if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 3)) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x220),
                     "%s: sps: BAM %pa pipe %d: read pointer:0x%x; write pointer:0x%x\n",
                     "sps_bam_pipe_inject_zlt",param_1 + 0x18,param_2,uVar3,uVar8);
    }
    if (uVar3 != uVar4) {
      uVar4 = uVar4 + 8;
      if (*(uint *)(lVar10 + 0xe0) <= uVar4) {
        if (((1 < logging_option) && (1 < debug_level_option)) &&
           ((print_limit_option == 0 ||
            (iVar6 = ___ratelimit(sps_bam_pipe_inject_zlt__rs_222,"sps_bam_pipe_inject_zlt"),
            iVar6 != 0)))) {
          _printk(&DAT_0012279b,"sps_bam_pipe_inject_zlt",param_1 + 0x18,param_2,uVar4);
        }
        if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 3)) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x220),
                         "%s: sps: BAM %pa pipe %d: next write is 0x%x: wrap around\n",
                         "sps_bam_pipe_inject_zlt",param_1 + 0x18,param_2,uVar4);
        }
        uVar4 = 0;
      }
      *(undefined8 *)(*(long *)(lVar10 + 0x58) + uVar8) = 0x4000000000000000;
      bam_pipe_set_desc_write_offset(lVar1,param_2,uVar4);
      DataSynchronizationBarrier(3,2,0);
      if (((1 < logging_option) && (1 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar6 = ___ratelimit(sps_bam_pipe_inject_zlt__rs_225,"sps_bam_pipe_inject_zlt"),
          iVar6 != 0)))) {
        uVar5 = bam_pipe_get_desc_write_offset(lVar1,param_2);
        _printk(&DAT_0011e3cc,"sps_bam_pipe_inject_zlt",param_1 + 0x18,param_2,uVar4,uVar5);
      }
      if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 3)) {
        uVar9 = *(undefined8 *)(param_1 + 0x220);
        uVar5 = bam_pipe_get_desc_write_offset(lVar1,param_2);
        ipc_log_string(uVar9,
                       "%s: sps: BAM %pa pipe %d: write pointer to tell HW: 0x%x; write pointer read from HW: 0x%x\n"
                       ,"sps_bam_pipe_inject_zlt",param_1 + 0x18,param_2,uVar4,uVar5);
      }
      return 0;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar6 = ___ratelimit(sps_bam_pipe_inject_zlt__rs_219,"sps_bam_pipe_inject_zlt"), iVar6 != 0
        )))) {
      _printk(&DAT_0012274a,"sps_bam_pipe_inject_zlt",param_1 + 0x18,param_2,uVar3);
    }
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                     "%s: sps: BAM %pa pipe %d: read pointer 0x%x is already equal to write pointer\n"
                     ,"sps_bam_pipe_inject_zlt",param_1 + 0x18,param_2,uVar3);
    }
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_bam_pipe_get_event @ 0010e168 size=628
// signature: undefined sps_bam_pipe_get_event(void)
// callers: [sps_get_event]
//------------------------------------------------------------

undefined8 sps_bam_pipe_get_event(long param_1,uint param_2,long *param_3)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  ulong uVar7;
  long *plVar8;
  long lVar9;
  
  if (0x1e < param_2) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10e3a4);
    (*pcVar4)();
  }
  lVar9 = *(long *)(param_1 + (ulong)param_2 * 8 + 0x100);
  if (*(int *)(lVar9 + 0x270) == 0) {
    if ((*(int *)(lVar9 + 200) != 0) && ((*(byte *)(lVar9 + 0xb8) >> 4 & 1) == 0)) {
      pipe_handler_eot(param_1,lVar9);
    }
    if (*(undefined8 **)(lVar9 + 0x230) == (undefined8 *)(lVar9 + 0x230)) {
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar5 = ___ratelimit(sps_bam_pipe_get_event__rs_230,"sps_bam_pipe_get_event"), iVar5 != 0
          )))) {
        _printk(&DAT_0011e42a,"sps_bam_pipe_get_event",param_1 + 0x18);
      }
      if ((param_1 != 0) && (*(int *)(param_1 + 0x238) == 0)) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x210),"%s: sps:events_q of bam %pa is empty\n",
                       "sps_bam_pipe_get_event",param_1 + 0x18);
      }
    }
    else {
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar5 = ___ratelimit(sps_bam_pipe_get_event__rs_233,"sps_bam_pipe_get_event"), iVar5 != 0
          )))) {
        _printk(&DAT_001257dd,"sps_bam_pipe_get_event",param_1 + 0x18);
      }
      if ((param_1 != 0) && (*(int *)(param_1 + 0x238) == 0)) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x210),"%s: sps:events_q of bam %pa is not empty\n"
                       ,"sps_bam_pipe_get_event",param_1 + 0x18);
      }
      plVar8 = *(long **)(lVar9 + 0x230);
      uVar7 = __list_del_entry_valid(plVar8);
      if ((uVar7 & 1) != 0) {
        lVar9 = *plVar8;
        plVar1 = (long *)plVar8[1];
        *(long **)(lVar9 + 8) = plVar1;
        *plVar1 = lVar9;
      }
      *plVar8 = (long)&DAT_dead000000000100;
      plVar8[1] = -0x2152fffffffffede;
      if (plVar8 != (long *)0x0) {
        lVar2 = plVar8[5];
        lVar9 = plVar8[2];
        lVar3 = plVar8[3];
        param_3[2] = plVar8[4];
        param_3[3] = lVar2;
        *param_3 = lVar9;
        param_3[1] = lVar3;
        kfree(plVar8);
        return 0;
      }
    }
    uVar6 = 0;
  }
  else {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar5 = ___ratelimit(sps_bam_pipe_get_event__rs,"sps_bam_pipe_get_event"), iVar5 != 0)))) {
      _printk(&DAT_001253f1,"sps_bam_pipe_get_event",param_1 + 0x18,param_2,lVar9);
    }
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                     "%s: sps:Invalid connection for event: BAM %pa pipe %d context 0x%pK\n",
                     "sps_bam_pipe_get_event",param_1 + 0x18,param_2,lVar9);
    }
    uVar6 = 0xffffffff;
  }
  *(undefined4 *)(param_3 + 1) = 0;
  return uVar6;
}



//------------------------------------------------------------
// sps_bam_pipe_get_iovec @ 0010e3e0 size=728
// signature: undefined sps_bam_pipe_get_iovec(void)
// callers: [sps_get_iovec]
//------------------------------------------------------------

undefined8 sps_bam_pipe_get_iovec(long param_1,uint param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  code *pcVar5;
  bool bVar6;
  uint uVar7;
  int iVar8;
  long lVar9;
  
  if (0x1e < param_2) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10e654);
    (*pcVar5)();
  }
  lVar9 = *(long *)(param_1 + (ulong)param_2 * 8 + 0x100);
  if ((*(int *)(lVar9 + 0x274) == 0) || ((*(byte *)(lVar9 + 0xb8) & 0x50) != 0)) {
    return 0xffffffff;
  }
  iVar8 = *(int *)(lVar9 + 200);
  if (((iVar8 == 0) && (*(int *)(lVar9 + 0xcc) == 0)) || (*(int *)(lVar9 + 0x270) != 0)) {
    if (*(int *)(lVar9 + 0x270) == 0) goto LAB_0010e4b4;
LAB_0010e450:
    uVar7 = bam_pipe_get_desc_read_offset(param_1 + 0xd8,param_2);
  }
  else {
    if ((1 < logging_option) && (3 < debug_level_option)) {
      if (print_limit_option != '\0') {
        iVar8 = ___ratelimit(sps_bam_pipe_get_iovec__rs,"sps_bam_pipe_get_iovec");
        if (iVar8 == 0) goto LAB_0010e470;
        iVar8 = *(int *)(lVar9 + 200);
      }
      _printk(&DAT_00123607,"sps_bam_pipe_get_iovec",param_1 + 0x18,param_2,iVar8,
              *(undefined4 *)(lVar9 + 0xcc));
    }
LAB_0010e470:
    if ((param_1 != 0) && (*(int *)(param_1 + 0x238) == 0)) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x210),
                     "%s: sps: BAM: %pa; pipe index:%d; polled is %d; hybrid is %d\n",
                     "sps_bam_pipe_get_iovec",param_1 + 0x18,param_2,*(undefined4 *)(lVar9 + 200),
                     *(undefined4 *)(lVar9 + 0xcc));
    }
    pipe_handler_eot(param_1,lVar9);
    if (*(int *)(lVar9 + 0x270) != 0) goto LAB_0010e450;
LAB_0010e4b4:
    uVar7 = *(uint *)(lVar9 + 0x100);
  }
  if (uVar7 == *(uint *)(lVar9 + 0xf4)) {
    *param_3 = 0;
    if (((1 < logging_option) && (3 < debug_level_option)) &&
       ((print_limit_option == '\0' ||
        (iVar8 = ___ratelimit(sps_bam_pipe_get_iovec__rs_238,"sps_bam_pipe_get_iovec"), iVar8 != 0))
       )) {
      _printk(&DAT_00121b0c,"sps_bam_pipe_get_iovec",param_1 + 0x18,param_2);
    }
    if (param_1 == 0) {
      return 0;
    }
    if (*(int *)(param_1 + 0x238) == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x210),
                     "%s: sps: BAM: %pa; pipe index:%d; no iovec to process\n",
                     "sps_bam_pipe_get_iovec",param_1 + 0x18,param_2);
      return 0;
    }
    return 0;
  }
  puVar1 = (undefined8 *)(*(long *)(lVar9 + 0xe8) + (ulong)*(uint *)(lVar9 + 0xf4));
  *param_3 = *puVar1;
  uVar7 = *(int *)(lVar9 + 0xf4) + 8;
  if (*(uint *)(lVar9 + 0xe0) <= uVar7) {
    uVar7 = 0;
  }
  bVar6 = 1 < logging_option;
  *(uint *)(lVar9 + 0xf4) = uVar7;
  if ((bVar6) && (3 < debug_level_option)) {
    if (print_limit_option == '\0') {
      uVar2 = *(undefined4 *)puVar1;
      uVar3 = *(uint *)((long)puVar1 + 4);
      uVar4 = *(undefined4 *)(lVar9 + 0xbc);
    }
    else {
      iVar8 = ___ratelimit(sps_bam_pipe_get_iovec__rs_241,"sps_bam_pipe_get_iovec");
      if (iVar8 == 0) goto LAB_0010e540;
      uVar2 = *(undefined4 *)puVar1;
      uVar3 = *(uint *)((long)puVar1 + 4);
      uVar4 = *(undefined4 *)(lVar9 + 0xbc);
      uVar7 = *(uint *)(lVar9 + 0xf4);
    }
    _printk(&DAT_00123d26,"sps_bam_pipe_get_iovec",uVar4,uVar2,uVar3 & 0xffff,uVar3 >> 0x10,uVar7);
  }
LAB_0010e540:
  if ((param_1 != 0) && (*(int *)(param_1 + 0x238) == 0)) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x210),
                   "%s: sps: pipe index:%d; iovec addr:0x%pK; size:0x%x; flags:0x%x; acked_offset:0x%x\n"
                   ,"sps_bam_pipe_get_iovec",*(undefined4 *)(lVar9 + 0xbc),*(undefined4 *)puVar1,
                   *(uint *)((long)puVar1 + 4) & 0xffff,*(uint *)((long)puVar1 + 4) >> 0x10,
                   *(undefined4 *)(lVar9 + 0xf4));
  }
  return 0;
}



//------------------------------------------------------------
// sps_bam_pipe_is_empty @ 0010e6bc size=896
// signature: undefined sps_bam_pipe_is_empty(void)
// callers: [sps_is_pipe_empty]
//------------------------------------------------------------

undefined8 sps_bam_pipe_is_empty(long param_1,uint param_2,int *param_3)

{
  long lVar1;
  undefined *puVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  
  if (0x1e < param_2) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10e9e8);
    (*pcVar3)();
  }
  lVar8 = *(long *)(param_1 + (ulong)param_2 * 8 + 0x100);
  if ((*(byte *)(lVar8 + 0xb8) >> 6 & 1) != 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar6 = ___ratelimit(sps_bam_pipe_is_empty__rs,"sps_bam_pipe_is_empty"), iVar6 != 0)))) {
      _printk(&DAT_00120a76,"sps_bam_pipe_is_empty",param_1 + 0x18,param_2);
    }
    if (param_1 == 0) {
      return 0xffffffff;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x228),"%s: sps:Is empty on remote: BAM %pa pipe %d\n",
                   "sps_bam_pipe_is_empty",param_1 + 0x18,param_2);
    return 0xffffffff;
  }
  lVar1 = param_1 + 0xd8;
  uVar4 = bam_pipe_get_desc_read_offset(lVar1,param_2);
  if ((*(byte *)(lVar8 + 0xb8) >> 4 & 1) == 0) {
    uVar5 = *(uint *)(lVar8 + 0xf4);
  }
  else {
    uVar5 = bam_pipe_get_desc_write_offset(lVar1,param_2);
  }
  if (uVar4 == uVar5) {
    *param_3 = 1;
  }
  else {
    if ((*(byte *)(lVar8 + 0xb8) >> 4 & 1) == 0) {
      *param_3 = 0;
      if (((1 < logging_option) && (2 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar6 = ___ratelimit(sps_bam_pipe_is_empty__rs_246,"sps_bam_pipe_is_empty"), iVar6 != 0))
         )) {
        _printk(&DAT_0011d6d5,"sps_bam_pipe_is_empty",*(undefined4 *)(lVar8 + 0xbc));
      }
      if (param_1 == 0) {
        return 0;
      }
      if (*(uint *)(param_1 + 0x238) < 2) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x218),
                       "%s: sps: pipe index:%d; this sys2bam pipe is NOT empty\n",
                       "sps_bam_pipe_is_empty",*(undefined4 *)(lVar8 + 0xbc));
        return 0;
      }
      return 0;
    }
    uVar7 = bam_pipe_check_zlt(lVar1,param_2);
    if ((uVar7 & 1) != 0) {
      uVar7 = bam_pipe_check_pipe_empty(lVar1,param_2);
      uVar5 = uVar5 + 8;
      if (*(uint *)(lVar8 + 0xe0) <= uVar5) {
        uVar5 = 0;
      }
      if (uVar5 == uVar4) {
        *param_3 = 1;
        if ((uVar7 & 1) == 0) {
          if (((1 < logging_option) && (debug_level_option != 0)) &&
             ((print_limit_option == 0 ||
              (iVar6 = ___ratelimit(sps_bam_pipe_is_empty__rs_249,"sps_bam_pipe_is_empty"),
              iVar6 != 0)))) {
            _printk(&DAT_0011e452,"sps_bam_pipe_is_empty",param_1 + 0x18,param_2);
          }
          if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 4)) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x228),
                           "%s: sps:BAM %pa pipe %d pipe empty checking for ZLT\n",
                           "sps_bam_pipe_is_empty",param_1 + 0x18,param_2);
          }
        }
        goto LAB_0010e88c;
      }
    }
    *param_3 = 0;
  }
LAB_0010e88c:
  if (((1 < logging_option) && (2 < debug_level_option)) &&
     ((print_limit_option == 0 ||
      (iVar6 = ___ratelimit(sps_bam_pipe_is_empty__rs_252,"sps_bam_pipe_is_empty"), iVar6 != 0)))) {
    puVar2 = &DAT_00125809;
    if (*param_3 != 0) {
      puVar2 = &DAT_0012037f;
    }
    _printk(&DAT_0011d21c,"sps_bam_pipe_is_empty",*(undefined4 *)(lVar8 + 0xbc),puVar2);
  }
  if ((param_1 != 0) && (*(uint *)(param_1 + 0x238) < 2)) {
    puVar2 = &DAT_00125809;
    if (*param_3 != 0) {
      puVar2 = &DAT_0012037f;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x218),
                   "%s: sps: pipe index:%d; this pipe is %s empty\n","sps_bam_pipe_is_empty",
                   *(undefined4 *)(lVar8 + 0xbc),puVar2);
  }
  return 0;
}



//------------------------------------------------------------
// sps_bam_set_satellite @ 0010ea40 size=528
// signature: undefined sps_bam_set_satellite(void)
// callers: [sps_set_owner]
//------------------------------------------------------------

undefined8 sps_bam_set_satellite(long param_1,ulong param_2)

{
  long lVar1;
  long *plVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  char *pcVar6;
  ulong uVar7;
  long *plVar8;
  ulong uVar9;
  
  if (0x1e < (uint)param_2) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10ec50);
    (*pcVar3)();
  }
  uVar7 = param_2 & 0xffffffff;
  if ((*(uint *)(param_1 + 0x78) & 3) == 2) {
    uVar9 = 1L << (param_2 & 0x3f);
    if ((uVar9 & *(uint *)(param_1 + 0xf8)) != 0) {
      plVar8 = *(long **)(param_1 + uVar7 * 8 + 0x100);
      if ((int)plVar8[0x19] == 0) {
        bam_pipe_set_irq(param_1 + 0xd8,uVar7,0,*(undefined4 *)((long)plVar8 + 0xc4),
                         *(undefined4 *)(param_1 + 0x80));
      }
      if ((*(uint *)(param_1 + 0xe0) < 3) &&
         (((*(byte *)(plVar8 + 0x17) >> 5 & 1) == 0 || ((int)plVar8[0x19] != 0)))) {
        bam_pipe_satellite_mti(param_1 + 0xd8,uVar7,0,*(undefined4 *)(param_1 + 0x80));
        *(uint *)(plVar8 + 0x17) = *(uint *)(plVar8 + 0x17) | 0x20;
      }
      uVar7 = __list_del_entry_valid(plVar8);
      if ((uVar7 & 1) != 0) {
        lVar1 = *plVar8;
        plVar2 = (long *)plVar8[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar8 = (long)&DAT_dead000000000100;
      plVar8[1] = -0x2152fffffffffede;
      *(uint *)(param_1 + 0xf8) = *(uint *)(param_1 + 0xf8) & ((uint)uVar9 ^ 0xffffffff);
      *(uint *)(param_1 + 0xfc) = *(uint *)(param_1 + 0xfc) | *(uint *)(plVar8 + 0x18);
      *(uint *)(plVar8 + 0x17) = *(uint *)(plVar8 + 0x17) | 0x40;
      return 0;
    }
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar4 = ___ratelimit(sps_bam_set_satellite__rs_261,"sps_bam_set_satellite"), iVar4 != 0))))
    {
      _printk(&DAT_0011d70f,"sps_bam_set_satellite",param_1 + 0x18,uVar7);
    }
    if (param_1 == 0) {
      return 0xffffffff;
    }
    uVar5 = *(undefined8 *)(param_1 + 0x228);
    pcVar6 = "%s: sps:BAM %pa pipe %d not local and active\n";
  }
  else {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar4 = ___ratelimit(sps_bam_set_satellite__rs,"sps_bam_set_satellite"), iVar4 != 0)))) {
      _printk(&DAT_00123647,"sps_bam_set_satellite",param_1 + 0x18,uVar7);
    }
    if (param_1 == 0) {
      return 0xffffffff;
    }
    uVar5 = *(undefined8 *)(param_1 + 0x228);
    pcVar6 = "%s: sps:Cannot grant satellite control to BAM %pa pipe %d\n";
  }
  ipc_log_string(uVar5,pcVar6,"sps_bam_set_satellite",param_1 + 0x18,uVar7);
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_bam_pipe_pending_desc @ 0010ec54 size=80
// signature: undefined sps_bam_pipe_pending_desc(void)
// callers: [sps_pipe_pending_desc]
//------------------------------------------------------------

bool sps_bam_pipe_pending_desc(long param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = bam_pipe_get_desc_read_offset(param_1 + 0xd8);
  iVar2 = bam_pipe_get_desc_write_offset(param_1 + 0xd8,param_2);
  return iVar1 != iVar2;
}



//------------------------------------------------------------
// trigger_event @ 0010eca4 size=400
// signature: undefined trigger_event(void)
// callers: [sps_bam_check_irq, pipe_handler_eot]
//------------------------------------------------------------

void trigger_event(long param_1,long *param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  
  if (*param_2 != 0) {
    complete();
    if (((1 < logging_option) && (3 < debug_level_option)) &&
       ((print_limit_option == '\0' ||
        (iVar2 = ___ratelimit(trigger_event__rs_308,"trigger_event"), iVar2 != 0)))) {
      _printk(&DAT_0011e9ce,"trigger_event",*(undefined4 *)*param_2);
    }
    if ((param_1 != 0) && (*(int *)(param_1 + 0x238) == 0)) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x210),"%s: sps: done=%d\n","trigger_event",
                     *(undefined4 *)*param_2);
    }
  }
  if (param_2[1] != 0) {
    if (((1 < logging_option) && (3 < debug_level_option)) &&
       ((print_limit_option == '\0' ||
        (iVar2 = ___ratelimit(trigger_event__rs_311,"trigger_event"), iVar2 != 0)))) {
      _printk(&DAT_0012561d,"trigger_event","sps:trigger_event.using callback\n");
    }
    if ((param_1 != 0) && (*(int *)(param_1 + 0x238) == 0)) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x210),"%s: %s","trigger_event",
                     "sps:trigger_event.using callback\n");
    }
    if (*(int *)((code *)param_2[1] + -4) != -0x64eb7981) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10ed6c);
      (*pcVar1)();
    }
    (*(code *)param_2[1])(param_3 + 0x10);
  }
  return;
}



//------------------------------------------------------------
// sps_debugfs_record @ 0010ee38 size=212
// signature: undefined sps_debugfs_record(void)
// callers: []
//------------------------------------------------------------

void sps_debugfs_record(undefined8 param_1)

{
  int iVar1;
  
  mutex_lock(&sps_debugfs_lock);
  if (debugfs_record_enabled != '\0') {
    if (debugfs_buf_size <= debugfs_buf_used + 0x50) {
      debugfs_buf_used = 0;
      wraparound = '\x01';
    }
    iVar1 = scnprintf(debugfs_buf + (ulong)debugfs_buf_used,debugfs_buf_size - debugfs_buf_used,
                      param_1);
    debugfs_buf_used = debugfs_buf_used + iVar1;
    if (wraparound == '\x01') {
      scnprintf(debugfs_buf + (ulong)debugfs_buf_used,debugfs_buf_size - debugfs_buf_used,
                "\n**** end line of sps log ****\n\n");
    }
  }
  mutex_unlock(&sps_debugfs_lock);
  return;
}



//------------------------------------------------------------
// sps_get_bam_debug_info @ 0010ef10 size=2404
// signature: undefined sps_get_bam_debug_info(void)
// callers: []
//------------------------------------------------------------

undefined8 sps_get_bam_debug_info(long param_1,int param_2,ulong param_3,int param_4,int param_5)

{
  undefined8 *puVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined *puVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar3 = ___ratelimit(&sps_get_bam_debug_info__rs,"sps_get_bam_debug_info"), iVar3 != 0))))
    {
      _printk(&DAT_0011dfa4,"sps_get_bam_debug_info");
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: device handle should not be 0\n",
                     "sps_get_bam_debug_info");
    }
    return 0xffffffff;
  }
  if ((sps == 0) || (*(int *)(sps + 0x30) == 0)) {
    if (((1 < logging_option) && (debug_level_option != '\0')) &&
       ((print_limit_option == 0 ||
        (iVar3 = ___ratelimit(sps_get_bam_debug_info__rs_3,"sps_get_bam_debug_info"), iVar3 != 0))))
    {
      _printk(&DAT_00122f05,"sps_get_bam_debug_info");
    }
    if ((sps == 0) || (3 < *(uint *)(sps + 0x120))) {
      return 0xfffffdfb;
    }
    ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: sps driver is not ready\n",
                   "sps_get_bam_debug_info");
    return 0xfffffdfb;
  }
  param_3 = param_3 & 0xffffffff;
  mutex_lock(sps + 0x70);
  lVar4 = sps_h2bam(param_1);
  if (lVar4 == 0) {
    _printk(&DAT_00121b5b,param_1);
    mutex_unlock(sps + 0x70);
    return 0xffffffff;
  }
  mutex_unlock(sps + 0x70);
  uVar2 = *(uint *)(lVar4 + 0x30);
  uVar8 = (ulong)uVar2;
  if (sps != 0) {
    ipc_log_string(*(undefined8 *)(sps + 0x118),"%s: sps:<bam-addr> dump BAM:%pa\n",
                   "sps_get_bam_debug_info",lVar4 + 0x18);
    if ((sps != 0) && (*(long *)(sps + 0x118) == 0)) {
      _printk(&DAT_0011d28f,"sps_get_bam_debug_info",lVar4 + 0x18);
    }
  }
  if (0x62 < param_2 - 1U) {
switchD_0010efdc_caseD_11:
    puVar5 = &DAT_0011dff5;
LAB_0010f804:
    _printk(puVar5);
    return 0;
  }
  puVar1 = (undefined8 *)(lVar4 + 0xd8);
  switch(param_2) {
  case 1:
    print_bam_reg(*puVar1);
    if (uVar2 != 0) {
      uVar6 = 0;
      do {
        print_bam_pipe_reg(*puVar1,uVar6);
        uVar6 = uVar6 + 1;
      } while (uVar2 != uVar6);
      return 0;
    }
    break;
  case 2:
    print_bam_reg(*puVar1);
    break;
  case 4:
    if (uVar2 != 0) {
      uVar6 = 0;
      do {
        print_bam_pipe_selected_reg(puVar1,uVar6);
        uVar6 = uVar6 + 1;
      } while (uVar2 != uVar6);
      return 0;
    }
    break;
  case 5:
    if (uVar2 != 0) {
      uVar7 = 0;
      do {
        if ((param_3 >> (uVar7 & 0x3f) & 1) != 0) {
          print_bam_pipe_selected_reg(puVar1,uVar7 & 0xffffffff);
        }
        uVar7 = uVar7 + 1;
      } while (uVar8 != uVar7);
      return 0;
    }
    break;
  case 6:
    print_bam_pipe_selected_reg(puVar1,4);
    print_bam_pipe_selected_reg(puVar1,5);
    break;
  case 7:
    if (uVar2 != 0) {
      uVar6 = 0;
      do {
        print_bam_pipe_desc_fifo(puVar1,uVar6,0);
        uVar6 = uVar6 + 1;
      } while (uVar2 != uVar6);
      return 0;
    }
    break;
  case 8:
    if (uVar2 != 0) {
      uVar7 = 0;
      do {
        if ((param_3 >> (uVar7 & 0x3f) & 1) != 0) {
          print_bam_pipe_desc_fifo(puVar1,uVar7 & 0xffffffff,0);
        }
        uVar7 = uVar7 + 1;
      } while (uVar8 != uVar7);
      return 0;
    }
    break;
  case 9:
    print_bam_pipe_desc_fifo(puVar1,4,0);
    goto LAB_0010f3ec;
  case 10:
    if (uVar2 != 0) {
      uVar6 = 0;
      do {
        print_bam_pipe_selected_reg(puVar1,uVar6);
        print_bam_pipe_desc_fifo(puVar1,uVar6,0);
        uVar6 = uVar6 + 1;
      } while (uVar2 != uVar6);
      return 0;
    }
    break;
  case 0xb:
    if (uVar2 != 0) {
      uVar7 = 0;
      do {
        if ((param_3 >> (uVar7 & 0x3f) & 1) != 0) {
          print_bam_pipe_selected_reg(puVar1,uVar7 & 0xffffffff);
          print_bam_pipe_desc_fifo(puVar1,uVar7 & 0xffffffff,0);
        }
        uVar7 = uVar7 + 1;
      } while (uVar8 != uVar7);
      return 0;
    }
    break;
  case 0xc:
    print_bam_pipe_selected_reg(puVar1,4);
    print_bam_pipe_desc_fifo(puVar1,4,0);
    print_bam_pipe_selected_reg(puVar1,5);
LAB_0010f3ec:
    print_bam_pipe_desc_fifo(puVar1,5,0);
    break;
  case 0xd:
    if (param_4 != 0) {
      print_bam_test_bus_reg(puVar1,param_4);
      return 0;
    }
    puVar5 = &DAT_0011dfce;
    goto LAB_0010f804;
  case 0xe:
    if (param_5 == 0) {
      param_5 = 1;
    }
    if (uVar2 != 0) {
      uVar7 = 0;
      do {
        if ((param_3 >> (uVar7 & 0x3f) & 1) != 0) {
          print_bam_pipe_desc_fifo(puVar1,uVar7 & 0xffffffff,param_5);
        }
        uVar7 = uVar7 + 1;
      } while (uVar8 != uVar7);
      return 0;
    }
    break;
  case 0xf:
    if (uVar2 != 0) {
      uVar7 = 0;
      do {
        if ((param_3 >> (uVar7 & 0x3f) & 1) != 0) {
          print_bam_pipe_desc_fifo(puVar1,uVar7 & 0xffffffff,100);
        }
        uVar7 = uVar7 + 1;
      } while (uVar8 != uVar7);
      return 0;
    }
    break;
  case 0x10:
    if (uVar2 != 0) {
      uVar7 = 0;
      do {
        if ((param_3 >> (uVar7 & 0x3f) & 1) != 0) {
          print_bam_pipe_reg(*puVar1,uVar7 & 0xffffffff);
        }
        uVar7 = uVar7 + 1;
      } while (uVar8 != uVar7);
      return 0;
    }
    break;
  default:
    goto switchD_0010efdc_caseD_11;
  case 0x5b:
    print_bam_test_bus_reg(puVar1,param_4);
    print_bam_selected_reg(puVar1,*(undefined4 *)(lVar4 + 0x80));
    if (uVar2 != 0) {
      uVar6 = 0;
      do {
        print_bam_pipe_selected_reg(puVar1,uVar6);
        uVar6 = uVar6 + 1;
      } while (uVar2 != uVar6);
      return 0;
    }
    break;
  case 0x5c:
    print_bam_test_bus_reg(puVar1,param_4);
    print_bam_selected_reg(puVar1,*(undefined4 *)(lVar4 + 0x80));
    if (uVar2 != 0) {
      uVar7 = 0;
      do {
        if ((param_3 >> (uVar7 & 0x3f) & 1) != 0) {
          print_bam_pipe_selected_reg(puVar1,uVar7 & 0xffffffff);
        }
        uVar7 = uVar7 + 1;
      } while (uVar8 != uVar7);
      return 0;
    }
    break;
  case 0x5d:
    if (param_5 == 0) {
      param_5 = 1;
    }
    print_bam_test_bus_reg(puVar1,param_4);
    print_bam_selected_reg(puVar1,*(undefined4 *)(lVar4 + 0x80));
    if (uVar2 != 0) {
      uVar7 = 0;
      do {
        if ((param_3 >> (uVar7 & 0x3f) & 1) != 0) {
          print_bam_pipe_selected_reg(puVar1,uVar7 & 0xffffffff);
        }
        uVar7 = uVar7 + 1;
      } while (uVar8 != uVar7);
      if (uVar2 != 0) {
        uVar7 = 0;
        do {
          if ((param_3 >> (uVar7 & 0x3f) & 1) != 0) {
            print_bam_pipe_desc_fifo(puVar1,uVar7 & 0xffffffff,param_5);
          }
          uVar7 = uVar7 + 1;
        } while (uVar8 != uVar7);
        return 0;
      }
    }
    break;
  case 0x5e:
    if (param_5 == 0) {
      param_5 = 1;
    }
    print_bam_test_bus_reg(puVar1,param_4);
    print_bam_selected_reg(puVar1,*(undefined4 *)(lVar4 + 0x80));
    if (uVar2 != 0) {
      uVar7 = 0;
      do {
        if ((param_3 >> (uVar7 & 0x3f) & 1) != 0) {
          print_bam_pipe_selected_reg(puVar1,uVar7 & 0xffffffff);
          print_bam_pipe_desc_fifo(puVar1,uVar7 & 0xffffffff,param_5);
        }
        uVar7 = uVar7 + 1;
      } while (uVar8 != uVar7);
      return 0;
    }
    break;
  case 0x5f:
    print_bam_test_bus_reg(puVar1,param_4);
    print_bam_selected_reg(puVar1,*(undefined4 *)(lVar4 + 0x80));
    if (uVar2 != 0) {
      uVar7 = 0;
      do {
        if ((param_3 >> (uVar7 & 0x3f) & 1) != 0) {
          print_bam_pipe_selected_reg(puVar1,uVar7 & 0xffffffff);
        }
        uVar7 = uVar7 + 1;
      } while (uVar8 != uVar7);
      if (uVar2 != 0) {
        uVar7 = 0;
        do {
          if ((param_3 >> (uVar7 & 0x3f) & 1) != 0) {
            print_bam_pipe_desc_fifo(puVar1,uVar7 & 0xffffffff,0);
          }
          uVar7 = uVar7 + 1;
        } while (uVar8 != uVar7);
        return 0;
      }
    }
    break;
  case 0x60:
    print_bam_test_bus_reg(puVar1,param_4);
    print_bam_selected_reg(puVar1,*(undefined4 *)(lVar4 + 0x80));
    if (uVar2 != 0) {
      uVar7 = 0;
      do {
        if ((param_3 >> (uVar7 & 0x3f) & 1) != 0) {
          print_bam_pipe_selected_reg(puVar1,uVar7 & 0xffffffff);
          print_bam_pipe_desc_fifo(puVar1,uVar7 & 0xffffffff,0);
        }
        uVar7 = uVar7 + 1;
      } while (uVar8 != uVar7);
      return 0;
    }
    break;
  case 0x61:
    print_bam_test_bus_reg(puVar1,param_4);
    print_bam_selected_reg(puVar1,*(undefined4 *)(lVar4 + 0x80));
    if (uVar2 != 0) {
      uVar7 = 0;
      do {
        if ((param_3 >> (uVar7 & 0x3f) & 1) != 0) {
          print_bam_pipe_selected_reg(puVar1,uVar7 & 0xffffffff);
        }
        uVar7 = uVar7 + 1;
      } while (uVar8 != uVar7);
      if (uVar2 != 0) {
        uVar7 = 0;
        do {
          if ((param_3 >> (uVar7 & 0x3f) & 1) != 0) {
            print_bam_pipe_desc_fifo(puVar1,uVar7 & 0xffffffff,0);
          }
          uVar7 = uVar7 + 1;
        } while (uVar8 != uVar7);
        if (uVar2 != 0) {
          uVar7 = 0;
          do {
            if ((param_3 >> (uVar7 & 0x3f) & 1) != 0) {
              print_bam_pipe_desc_fifo(puVar1,uVar7 & 0xffffffff,100);
            }
            uVar7 = uVar7 + 1;
          } while (uVar8 != uVar7);
          return 0;
        }
      }
    }
    break;
  case 0x62:
    print_bam_test_bus_reg(puVar1,param_4);
    print_bam_selected_reg(puVar1,*(undefined4 *)(lVar4 + 0x80));
    if (uVar2 != 0) {
      uVar7 = 0;
      do {
        if ((param_3 >> (uVar7 & 0x3f) & 1) != 0) {
          print_bam_pipe_selected_reg(puVar1,uVar7 & 0xffffffff);
          print_bam_pipe_desc_fifo(puVar1,uVar7 & 0xffffffff,0);
          print_bam_pipe_desc_fifo(puVar1,uVar7 & 0xffffffff,100);
        }
        uVar7 = uVar7 + 1;
      } while (uVar8 != uVar7);
      return 0;
    }
    break;
  case 99:
    print_bam_test_bus_reg(puVar1,param_4);
    print_bam_reg(*puVar1);
    if (uVar2 != 0) {
      uVar6 = 0;
      do {
        print_bam_pipe_reg(*puVar1,uVar6);
        uVar6 = uVar6 + 1;
      } while (uVar2 != uVar6);
      print_bam_selected_reg(puVar1,*(undefined4 *)(lVar4 + 0x80));
      if (uVar2 == 0) {
        return 0;
      }
      uVar6 = 0;
      do {
        print_bam_pipe_selected_reg(puVar1,uVar6);
        uVar6 = uVar6 + 1;
      } while (uVar2 != uVar6);
      if (uVar2 == 0) {
        return 0;
      }
      uVar6 = 0;
      do {
        print_bam_pipe_desc_fifo(puVar1,uVar6,0);
        uVar6 = uVar6 + 1;
      } while (uVar2 != uVar6);
      if (uVar2 == 0) {
        return 0;
      }
      uVar6 = 0;
      do {
        print_bam_pipe_desc_fifo(puVar1,uVar6,100);
        uVar6 = uVar6 + 1;
      } while (uVar2 != uVar6);
      return 0;
    }
  case 3:
    print_bam_selected_reg(puVar1,*(undefined4 *)(lVar4 + 0x80));
  }
  return 0;
}



//------------------------------------------------------------
// sps_h2bam @ 0010f878 size=372
// signature: undefined sps_h2bam(void)
// callers: [sps_pipe_inject_zlt, sps_device_reset, sps_rm_state_change, sps_get_bam_addr, sps_deregister_bam_device, sps_bam_process_irq, sps_pipe_pending_desc, sps_bam_enable_irqs, sps_connect, sps_get_bam_debug_info, sps_pipe_disable, sps_pipe_reset, sps_bam_disable_irqs]
//------------------------------------------------------------

long * sps_h2bam(long param_1)

{
  int iVar1;
  long *plVar2;
  
  if (((1 < logging_option) && (2 < debug_level_option)) &&
     ((print_limit_option == 0 || (iVar1 = ___ratelimit(sps_h2bam__rs,"sps_h2bam"), iVar1 != 0)))) {
    _printk(&DAT_00124739,"sps_h2bam",param_1);
  }
  if ((sps != 0) && (*(uint *)(sps + 0x120) < 2)) {
    ipc_log_string(*(undefined8 *)(sps + 0x100),"%s: sps: BAM handle:0x%pK\n","sps_h2bam",param_1);
  }
  plVar2 = (long *)0x0;
  if ((param_1 != 0) && (param_1 != 0x7fffffffffffffff)) {
    plVar2 = (long *)(sps + 0xa0);
    do {
      plVar2 = (long *)*plVar2;
      if (plVar2 == (long *)(sps + 0xa0)) {
        if ((logging_option != 1) &&
           ((print_limit_option < 3 ||
            (iVar1 = ___ratelimit(sps_h2bam__rs_30,"sps_h2bam"), iVar1 != 0)))) {
          _printk(&DAT_00124ef3,"sps_h2bam",param_1);
        }
        if (sps != 0) {
          ipc_log_string(*(undefined8 *)(sps + 0x110),
                         "%s: sps:Can\'t find BAM device for handle 0x%pK\n","sps_h2bam",param_1);
        }
        return (long *)0;
      }
    } while (plVar2 != (long *)param_1);
  }
  return plVar2;
}



//------------------------------------------------------------
// sps_phy2h @ 0010f9f0 size=680
// signature: undefined sps_phy2h(void)
// callers: []
//------------------------------------------------------------

void sps_phy2h(long param_1,long *param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long *plVar4;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = param_1;
  if (((1 < logging_option) && (1 < debug_level_option)) &&
     ((print_limit_option == 0 || (iVar2 = ___ratelimit(sps_phy2h__rs,"sps_phy2h"), iVar2 != 0)))) {
    _printk(&DAT_0011f4ab,"sps_phy2h");
  }
  if ((sps == 0) ||
     (((*(uint *)(sps + 0x120) < 3 &&
       (ipc_log_string(*(undefined8 *)(sps + 0x108),"%s: Enter\n","sps_phy2h"), sps == 0)) ||
      (*(int *)(sps + 0x30) == 0)))) {
    if (((1 < logging_option) && (debug_level_option != 0)) &&
       ((print_limit_option == 0 || (iVar2 = ___ratelimit(sps_phy2h__rs_13,"sps_phy2h"), iVar2 != 0)
        ))) {
      _printk(&DAT_00122f05,"sps_phy2h");
    }
    if ((sps != 0) && (*(uint *)(sps + 0x120) < 4)) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: sps driver is not ready\n","sps_phy2h");
    }
    uVar3 = 0xfffffdfb;
  }
  else if (param_2 == (long *)0x0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 || (iVar2 = ___ratelimit(sps_phy2h__rs_14,"sps_phy2h"), iVar2 != 0))
       )) {
      _printk(&DAT_00120ae2,"sps_phy2h");
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: handle is NULL\n","sps_phy2h");
    }
    uVar3 = 0xffffffff;
  }
  else {
    plVar4 = (long *)(sps + 0xa0);
    do {
      plVar4 = (long *)*plVar4;
      if (plVar4 == (long *)(sps + 0xa0)) {
        if ((logging_option != 1) &&
           ((print_limit_option < 3 ||
            (iVar2 = ___ratelimit(sps_phy2h__rs_17,"sps_phy2h"), iVar2 != 0)))) {
          _printk(&DAT_0011ee1c,"sps_phy2h",&local_40);
        }
        if (sps != 0) {
          ipc_log_string(*(undefined8 *)(sps + 0x110),
                         "%s: sps: BAM device %pa is not registered yet\n","sps_phy2h",&local_40);
        }
        uVar3 = 0xffffffed;
        goto LAB_0010fadc;
      }
    } while (plVar4[3] != param_1);
    uVar3 = 0;
    *param_2 = (long)plVar4;
  }
LAB_0010fadc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// sps_setup_bam2bam_fifo @ 0010fc9c size=724
// signature: undefined sps_setup_bam2bam_fifo(void)
// callers: []
//------------------------------------------------------------

undefined8 sps_setup_bam2bam_fifo(undefined8 *param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined1 *puVar2;
  undefined8 uVar3;
  void *__s;
  char *pcVar4;
  ulong uVar5;
  
  uVar5 = (ulong)param_2;
  if (((1 < logging_option) && (2 < debug_level_option)) &&
     ((print_limit_option == 0 ||
      (iVar1 = ___ratelimit(sps_setup_bam2bam_fifo__rs,"sps_setup_bam2bam_fifo"), iVar1 != 0)))) {
    _printk(&DAT_0011f4ab,"sps_setup_bam2bam_fifo");
  }
  if ((sps != 0) && (*(uint *)(sps + 0x120) < 2)) {
    ipc_log_string(*(undefined8 *)(sps + 0x100),"%s: Enter\n","sps_setup_bam2bam_fifo");
  }
  if ((param_1 == (undefined8 *)0x0) || (param_3 == 0)) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_setup_bam2bam_fifo__rs_20,"sps_setup_bam2bam_fifo"), iVar1 != 0)))
       ) {
      _printk(&DAT_00120afd,"sps_setup_bam2bam_fifo");
    }
    if (sps != 0) {
      uVar3 = *(undefined8 *)(sps + 0x110);
      pcVar4 = "%s: sps: invalid buffer address or size\n";
LAB_0010fd9c:
      ipc_log_string(uVar3,pcVar4,"sps_setup_bam2bam_fifo");
    }
LAB_0010fda8:
    uVar3 = 0xffffffff;
  }
  else {
    if ((sps == 0) || (*(int *)(sps + 0x30) == 0)) {
      if (((1 < logging_option) && (debug_level_option != 0)) &&
         ((print_limit_option == 0 ||
          (iVar1 = ___ratelimit(sps_setup_bam2bam_fifo__rs_23,"sps_setup_bam2bam_fifo"), iVar1 != 0)
          ))) {
        _printk(&DAT_00122f05,"sps_setup_bam2bam_fifo");
      }
      if ((sps != 0) && (*(uint *)(sps + 0x120) < 4)) {
        ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: sps driver is not ready\n",
                       "sps_setup_bam2bam_fifo");
      }
      return 0xfffffdfb;
    }
    if (param_4 == 0) {
      if ((uVar5 < *(ulong *)(sps + 0x38)) ||
         (*(ulong *)(sps + 0x38) + (ulong)*(uint *)(sps + 0x40) < (ulong)(param_3 + param_2))) {
        if (logging_option != 1) {
          if (2 < print_limit_option) {
            puVar2 = sps_setup_bam2bam_fifo__rs_27;
            goto LAB_0010ff24;
          }
          goto LAB_0010fe30;
        }
        goto LAB_0010fe44;
      }
    }
    else {
      if (*(uint *)(sps + 0x40) < param_3 + param_2) {
        if (logging_option != 1) {
          if (2 < print_limit_option) {
            puVar2 = sps_setup_bam2bam_fifo__rs_24;
LAB_0010ff24:
            iVar1 = ___ratelimit(puVar2,"sps_setup_bam2bam_fifo");
            if (iVar1 == 0) goto LAB_0010fe44;
          }
LAB_0010fe30:
          _printk(&DAT_001246fc,"sps_setup_bam2bam_fifo");
        }
LAB_0010fe44:
        if (sps != 0) {
          uVar3 = *(undefined8 *)(sps + 0x110);
          pcVar4 = "%s: sps: requested mem is out of pipe mem range\n";
          goto LAB_0010fd9c;
        }
        goto LAB_0010fda8;
      }
      uVar5 = *(long *)(sps + 0x38) + (ulong)param_2;
    }
    param_1[1] = uVar5;
    __s = (void *)spsi_get_mem_ptr();
    *param_1 = __s;
    *(uint *)(param_1 + 3) = param_3;
    memset(__s,0,(ulong)param_3);
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// sps_connect @ 0010ff74 size=1092
// signature: undefined sps_connect(void)
// callers: []
//------------------------------------------------------------

int sps_connect(long param_1,undefined8 *param_2)

{
  long lVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  char *pcVar6;
  
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 || (iVar3 = ___ratelimit(sps_connect__rs,"sps_connect"), iVar3 != 0)
        ))) {
      _printk(&DAT_0011e9ed,"sps_connect");
    }
    if (sps == 0) {
      return -1;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar6 = "%s: sps: pipe is NULL\n";
  }
  else if (param_2 == (undefined8 *)0x0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar3 = ___ratelimit(sps_connect__rs_35,"sps_connect"), iVar3 != 0)))) {
      _printk(&DAT_001236d9,"sps_connect");
    }
    if (sps == 0) {
      return -1;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar6 = "%s: sps: connection is NULL\n";
  }
  else {
    if (sps == 0) {
      return -0x13;
    }
    if (*(int *)(sps + 0x30) == 0) {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar3 = ___ratelimit(sps_connect__rs_38,"sps_connect"), iVar3 != 0)))) {
        _printk(&DAT_00124756,"sps_connect");
      }
      if (sps == 0) {
        return -0xb;
      }
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: sps driver is not ready\n","sps_connect"
                    );
      return -0xb;
    }
    if ((*(uint *)((long)param_2 + 0x7c) == 0xcccccccc) || (*(uint *)((long)param_2 + 0x7c) < 0x20))
    {
      mutex_lock(sps + 0x70);
      lVar5 = 0;
      if (*(int *)((long)param_2 + 0x2c) != 0) {
        lVar5 = 0x18;
      }
      uVar4 = *(undefined8 *)((long)param_2 + lVar5);
      lVar5 = sps_h2bam(uVar4);
      if (lVar5 == 0) {
        if ((logging_option != 1) &&
           ((print_limit_option < 3 ||
            (iVar3 = ___ratelimit(sps_connect__rs_43,"sps_connect"), iVar3 != 0)))) {
          _printk(&DAT_00124224,"sps_connect",uVar4);
        }
        if (sps != 0) {
          ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps:Invalid BAM device handle: 0x%pK\n",
                         "sps_connect",uVar4);
        }
        iVar3 = -1;
      }
      else {
        lVar1 = lVar5 + 0xa8;
        mutex_lock(lVar1);
        if (((1 < logging_option) && (1 < debug_level_option)) &&
           ((print_limit_option == 0 ||
            (iVar3 = ___ratelimit(sps_connect__rs_46,"sps_connect"), iVar3 != 0)))) {
          puVar2 = &DAT_0011fecf;
          if (*(int *)((long)param_2 + 0x2c) != 0) {
            puVar2 = &DAT_00121bd1;
          }
          _printk(&DAT_0011d804,"sps_connect",lVar5 + 0x18,*param_2,param_2[3],puVar2);
        }
        if (*(uint *)(lVar5 + 0x238) < 3) {
          puVar2 = &DAT_0011fecf;
          if (*(int *)((long)param_2 + 0x2c) != 0) {
            puVar2 = &DAT_00121bd1;
          }
          ipc_log_string(*(undefined8 *)(lVar5 + 0x220),
                         "%s: sps: bam %pa src 0x%pK dest 0x%pK mode %s\n","sps_connect",
                         lVar5 + 0x18,*param_2,param_2[3],puVar2);
        }
        memcpy((void *)(param_1 + 0x20),param_2,0x90);
        iVar3 = sps_rm_state_change(param_1,0x1535053);
        if (iVar3 == 0) {
          iVar3 = sps_rm_state_change(param_1,0x2535053);
          mutex_unlock(lVar1);
          if (iVar3 != 0) {
            sps_disconnect(param_1);
          }
        }
        else {
          mutex_unlock(lVar1);
        }
      }
      mutex_unlock(sps + 0x70);
      return iVar3;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar3 = ___ratelimit(sps_connect__rs_40,"sps_connect"), iVar3 != 0)))) {
      _printk(&DAT_00122412,"sps_connect");
    }
    if (sps == 0) {
      return -1;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar6 = "%s: sps: The value of pipe lock group is invalid\n";
  }
  ipc_log_string(uVar4,pcVar6,"sps_connect");
  return -1;
}



//------------------------------------------------------------
// sps_disconnect @ 001103bc size=684
// signature: undefined sps_disconnect(void)
// callers: [sps_connect]
//------------------------------------------------------------

int sps_disconnect(long param_1)

{
  undefined *puVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  long lVar6;
  
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar3 = ___ratelimit(sps_disconnect__rs,"sps_disconnect"), iVar3 != 0)))) {
      _printk(&DAT_0011ee4d,"sps_disconnect");
    }
    if (sps == 0) {
      return -1;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: Invalid pipe\n";
  }
  else {
    lVar6 = *(long *)(param_1 + 0x18);
    if (lVar6 == 0) {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar3 = ___ratelimit(sps_disconnect__rs_53,"sps_disconnect"), iVar3 != 0)))) {
        _printk(&DAT_0012477a,"sps_disconnect");
      }
      if (sps == 0) {
        return -1;
      }
      uVar4 = *(undefined8 *)(sps + 0x110);
      pcVar5 = "%s: sps: BAM device of this pipe is NULL\n";
    }
    else {
      if (((1 < logging_option) && (1 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar3 = ___ratelimit(sps_disconnect__rs_56,"sps_disconnect"), iVar3 != 0)))) {
        puVar1 = &DAT_0011fecf;
        if (*(int *)(param_1 + 0x4c) != 0) {
          puVar1 = &DAT_00121bd1;
        }
        _printk(&DAT_0011d804,"sps_disconnect",lVar6 + 0x18,*(undefined8 *)(param_1 + 0x20),
                *(undefined8 *)(param_1 + 0x38),puVar1);
      }
      if (*(uint *)(lVar6 + 0x238) < 3) {
        puVar1 = &DAT_0011fecf;
        if (*(int *)(param_1 + 0x4c) != 0) {
          puVar1 = &DAT_00121bd1;
        }
        ipc_log_string(*(undefined8 *)(lVar6 + 0x220),
                       "%s: sps: bam %pa src 0x%pK dest 0x%pK mode %s\n","sps_disconnect",
                       lVar6 + 0x18,*(undefined8 *)(param_1 + 0x20),*(undefined8 *)(param_1 + 0x38),
                       puVar1);
      }
      lVar2 = 0xa8;
      if (*(int *)(param_1 + 0x4c) != 0) {
        lVar2 = 0xb0;
      }
      if (*(long *)(*(long *)(param_1 + 0xb0) + lVar2) == param_1) {
        mutex_lock(lVar6 + 0xa8);
        iVar3 = sps_rm_state_change(param_1,0);
        mutex_unlock(lVar6 + 0xa8);
        if (iVar3 == 0) {
          sps_rm_config_init(param_1 + 0x20);
          return 0;
        }
        return iVar3;
      }
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar3 = ___ratelimit(sps_disconnect__rs_57,"sps_disconnect"), iVar3 != 0)))) {
        _printk(&DAT_00125865,"sps_disconnect");
      }
      if (sps == 0) {
        return -1;
      }
      uVar4 = *(undefined8 *)(sps + 0x110);
      pcVar5 = "%s: sps: Client context is corrupt\n";
    }
  }
  ipc_log_string(uVar4,pcVar5,"sps_disconnect");
  return -1;
}



//------------------------------------------------------------
// sps_register_event @ 0011066c size=760
// signature: undefined sps_register_event(void)
// callers: []
//------------------------------------------------------------

int sps_register_event(long param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_register_event__rs,"sps_register_event"), iVar1 != 0)))) {
      _printk(&DAT_0011e9ed,"sps_register_event");
    }
    if (sps != 0) {
      uVar4 = *(undefined8 *)(sps + 0x110);
      pcVar5 = "%s: sps: pipe is NULL\n";
LAB_0011080c:
      ipc_log_string(uVar4,pcVar5,"sps_register_event");
      return -1;
    }
  }
  else if (param_2 == (undefined4 *)0x0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_register_event__rs_60,"sps_register_event"), iVar1 != 0)))) {
      _printk(&DAT_0012329a,"sps_register_event");
    }
    if (sps != 0) {
      uVar4 = *(undefined8 *)(sps + 0x110);
      pcVar5 = "%s: sps: registered event is NULL\n";
      goto LAB_0011080c;
    }
  }
  else {
    if (sps == 0) {
      return -0x13;
    }
    if (*(int *)(sps + 0x30) == 0) {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar1 = ___ratelimit(sps_register_event__rs_63,"sps_register_event"), iVar1 != 0)))) {
        _printk(&DAT_001232e2,"sps_register_event");
      }
      if (sps != 0) {
        ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: sps driver not ready\n",
                       "sps_register_event");
      }
      return -0xb;
    }
    lVar3 = sps_bam_lock();
    if (lVar3 != 0) {
      if (((1 < logging_option) && (1 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar1 = ___ratelimit(sps_register_event__rs_66,"sps_register_event"), iVar1 != 0)))) {
        _printk(&DAT_0012044a,"sps_register_event",*param_2);
      }
      if (*(uint *)(lVar3 + 0x238) < 3) {
        ipc_log_string(*(undefined8 *)(lVar3 + 0x220),"%s: sps: events:%d\n","sps_register_event",
                       *param_2);
      }
      iVar1 = sps_bam_pipe_reg_event(lVar3,*(undefined4 *)(param_1 + 0xbc),param_2);
      _raw_spin_unlock_irqrestore(lVar3 + 0xe8,*(undefined8 *)(lVar3 + 0xf0));
      if (iVar1 == 0) {
        return 0;
      }
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar2 = ___ratelimit(sps_register_event__rs_69,"sps_register_event"), iVar2 != 0)))) {
        _printk(&DAT_001236f8,"sps_register_event",*(long *)(param_1 + 0x18) + 0x18,
                *(undefined4 *)(param_1 + 0xbc));
      }
      ipc_log_string(*(undefined8 *)(lVar3 + 0x228),
                     "%s: sps:Fail to register event for BAM %pa pipe %d\n","sps_register_event",
                     *(long *)(param_1 + 0x18) + 0x18,*(undefined4 *)(param_1 + 0xbc));
      return iVar1;
    }
  }
  return -1;
}



//------------------------------------------------------------
// sps_bam_lock @ 00110964 size=380
// signature: undefined sps_bam_lock(void)
// callers: [sps_transfer, sps_is_pipe_empty, sps_get_free_count, sps_flow_on, sps_get_iovec, sps_register_event, sps_set_owner, sps_flow_off, sps_get_unused_desc_num, sps_transfer_one, sps_set_config, sps_get_event]
//------------------------------------------------------------

long sps_bam_lock(long param_1)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  uint uVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x18);
  if (lVar6 == 0) {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar3 = ___ratelimit(sps_bam_lock__rs,"sps_bam_lock"), iVar3 != 0)))) {
      _printk(&DAT_0011e085,"sps_bam_lock");
    }
    if (sps == 0) {
      return 0;
    }
    ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: Connection is not in connected state\n",
                   "sps_bam_lock");
    return 0;
  }
  uVar4 = _raw_spin_lock_irqsave(lVar6 + 0xe8);
  *(undefined8 *)(lVar6 + 0xf0) = uVar4;
  uVar5 = *(uint *)(lVar6 + 0x30);
  uVar1 = *(uint *)(param_1 + 0xbc);
  if (uVar1 < uVar5) {
    if (0x1e < uVar1) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x110ae0);
      (*pcVar2)();
    }
    if (*(long *)(lVar6 + (ulong)uVar1 * 8 + 0x100) == param_1) {
      return lVar6;
    }
  }
  if (logging_option != '\x01') {
    if (2 < print_limit_option) {
      iVar3 = ___ratelimit(sps_bam_lock__rs_258,"sps_bam_lock");
      if (iVar3 == 0) goto LAB_001109f8;
      uVar5 = *(uint *)(lVar6 + 0x30);
    }
    _printk(&DAT_00123042,"sps_bam_lock",lVar6 + 0x18,uVar1,uVar5);
  }
LAB_001109f8:
  ipc_log_string(*(undefined8 *)(lVar6 + 0x228),
                 "%s: sps:Client not owner of BAM %pa pipe: %d (max %d)\n","sps_bam_lock",
                 lVar6 + 0x18,uVar1,*(undefined4 *)(lVar6 + 0x30));
  _raw_spin_unlock_irqrestore(lVar6 + 0xe8,*(undefined8 *)(lVar6 + 0xf0));
  return 0;
}



//------------------------------------------------------------
// sps_flow_on @ 00110ae4 size=208
// signature: undefined sps_flow_on(void)
// callers: []
//------------------------------------------------------------

undefined8 sps_flow_on(long param_1)

{
  int iVar1;
  long lVar2;
  
  if (param_1 == 0) {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 || (iVar1 = ___ratelimit(sps_flow_on__rs,"sps_flow_on"), iVar1 != 0)
        ))) {
      _printk(&DAT_0011e9ed,"sps_flow_on");
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: pipe is NULL\n","sps_flow_on");
    }
  }
  else {
    lVar2 = sps_bam_lock();
    if (lVar2 != 0) {
      bam_pipe_halt(lVar2 + 0xd8,*(undefined4 *)(param_1 + 0xbc),0);
      _raw_spin_unlock_irqrestore(lVar2 + 0xe8,*(undefined8 *)(lVar2 + 0xf0));
      return 0;
    }
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_flow_off @ 00110bb8 size=208
// signature: undefined sps_flow_off(void)
// callers: []
//------------------------------------------------------------

undefined8 sps_flow_off(long param_1)

{
  int iVar1;
  long lVar2;
  
  if (param_1 == 0) {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_flow_off__rs,"sps_flow_off"), iVar1 != 0)))) {
      _printk(&DAT_0011e9ed,"sps_flow_off");
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: pipe is NULL\n","sps_flow_off");
    }
  }
  else {
    lVar2 = sps_bam_lock();
    if (lVar2 != 0) {
      bam_pipe_halt(lVar2 + 0xd8,*(undefined4 *)(param_1 + 0xbc),1);
      _raw_spin_unlock_irqrestore(lVar2 + 0xe8,*(undefined8 *)(lVar2 + 0xf0));
      return 0;
    }
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_transfer @ 00110c8c size=840
// signature: undefined sps_transfer(void)
// callers: []
//------------------------------------------------------------

undefined4 sps_transfer(long param_1,long *param_2)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  uint uVar6;
  uint *puVar7;
  
  if (param_1 == 0) {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_transfer__rs,"sps_transfer"), iVar1 != 0)))) {
      _printk(&DAT_0011e9ed,"sps_transfer");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: pipe is NULL\n";
  }
  else if (param_2 == (long *)0x0) {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_transfer__rs_72,"sps_transfer"), iVar1 != 0)))) {
      _printk(&DAT_0012588b,"sps_transfer");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: transfer is NULL\n";
  }
  else if (param_2[1] == 0) {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_transfer__rs_75,"sps_transfer"), iVar1 != 0)))) {
      _printk(&DAT_00121fb7,"sps_transfer");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: iovec list is NULL\n";
  }
  else if ((int)param_2[2] == 0) {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_transfer__rs_78,"sps_transfer"), iVar1 != 0)))) {
      _printk(&DAT_001213de,"sps_transfer");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: iovec list is empty\n";
  }
  else if (*param_2 == 0) {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_transfer__rs_81,"sps_transfer"), iVar1 != 0)))) {
      _printk(&DAT_00121879,"sps_transfer");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: iovec list address is invalid\n";
  }
  else {
    uVar6 = 0;
    puVar7 = (uint *)(param_2[1] + 4);
    while ((*puVar7 >> 0xf & 1) == 0) {
      iVar1 = sps_check_iovec_flags(*puVar7 >> 0x10);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      uVar6 = uVar6 + 1;
      puVar7 = puVar7 + 2;
      if (*(uint *)(param_2 + 2) <= uVar6) {
        lVar3 = sps_bam_lock(param_1);
        if (lVar3 == 0) {
          return 0xffffffff;
        }
        uVar2 = sps_bam_pipe_transfer(lVar3,*(undefined4 *)(param_1 + 0xbc),param_2);
        _raw_spin_unlock_irqrestore(lVar3 + 0xe8,*(undefined8 *)(lVar3 + 0xf0));
        return uVar2;
      }
    }
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_transfer__rs_84,"sps_transfer"), iVar1 != 0)))) {
      _printk(&DAT_00123747,"sps_transfer");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: iovec size is invalid\n";
  }
  ipc_log_string(uVar4,pcVar5,"sps_transfer");
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_check_iovec_flags @ 00110fd4 size=744
// signature: undefined sps_check_iovec_flags(void)
// callers: [sps_transfer, sps_transfer_one]
//------------------------------------------------------------

undefined8 sps_check_iovec_flags(uint param_1)

{
  int iVar1;
  char *pcVar2;
  
  if ((param_1 & 0x5800) == 0x1000) {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_check_iovec_flags__rs,"sps_check_iovec_flags"), iVar1 != 0)))) {
      _printk(&DAT_0012432c,"sps_check_iovec_flags");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    pcVar2 = "%s: sps: NWD is only valid with EOT or CMD\n";
  }
  else if (((param_1 ^ 0xffffffff) & 0x4800) == 0) {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_check_iovec_flags__rs_263,"sps_check_iovec_flags"), iVar1 != 0))))
    {
      _printk(&DAT_0011ff7b,"sps_check_iovec_flags");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    pcVar2 = "%s: sps: EOT and CMD are not allowed to coexist\n";
  }
  else if (((param_1 & 0x600) == 0) || ((param_1 >> 0xb & 1) != 0)) {
    if ((param_1 & 0x600) == 0x600) {
      if ((logging_option != '\x01') &&
         ((print_limit_option < 3 ||
          (iVar1 = ___ratelimit(sps_check_iovec_flags__rs_269,"sps_check_iovec_flags"), iVar1 != 0))
         )) {
        _printk(&DAT_0011eefd,"sps_check_iovec_flags");
      }
      if (sps == 0) {
        return 0xffffffff;
      }
      pcVar2 = "%s: sps: Can\'t lock and unlock a pipe by the same Command Descriptor\n";
    }
    else if (((param_1 ^ 0xffffffff) & 0x900) == 0) {
      if ((logging_option != '\x01') &&
         ((print_limit_option < 3 ||
          (iVar1 = ___ratelimit(sps_check_iovec_flags__rs_272,"sps_check_iovec_flags"), iVar1 != 0))
         )) {
        _printk(&DAT_00124857,"sps_check_iovec_flags");
      }
      if (sps == 0) {
        return 0xffffffff;
      }
      pcVar2 = "%s: sps: Immediate and CMD are not allowed to coexist\n";
    }
    else {
      if (((param_1 ^ 0xffffffff) & 0x1100) != 0) {
        return 0;
      }
      if ((logging_option != '\x01') &&
         ((print_limit_option < 3 ||
          (iVar1 = ___ratelimit(sps_check_iovec_flags__rs_275,"sps_check_iovec_flags"), iVar1 != 0))
         )) {
        _printk(&DAT_0011ffae,"sps_check_iovec_flags");
      }
      if (sps == 0) {
        return 0xffffffff;
      }
      pcVar2 = "%s: sps: Immediate and NWD are not allowed to coexist\n";
    }
  }
  else {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_check_iovec_flags__rs_266,"sps_check_iovec_flags"), iVar1 != 0))))
    {
      _printk(&DAT_00120822,"sps_check_iovec_flags");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    pcVar2 = "%s: sps: pipe lock/unlock flags are only valid with Command Descriptor\n";
  }
  ipc_log_string(*(undefined8 *)(sps + 0x110),pcVar2,"sps_check_iovec_flags");
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_transfer_one @ 001112c0 size=272
// signature: undefined sps_transfer_one(void)
// callers: []
//------------------------------------------------------------

undefined4
sps_transfer_one(long param_1,ulong param_2,undefined4 param_3,undefined8 param_4,uint param_5)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  
  if (param_1 == 0) {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_transfer_one__rs,"sps_transfer_one"), iVar1 != 0)))) {
      _printk(&DAT_0011e9ed,"sps_transfer_one");
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: pipe is NULL\n","sps_transfer_one");
    }
  }
  else {
    iVar1 = sps_check_iovec_flags(param_5);
    if ((iVar1 == 0) && (lVar3 = sps_bam_lock(param_1), lVar3 != 0)) {
      uVar2 = sps_bam_pipe_transfer_one
                        (lVar3,*(undefined4 *)(param_1 + 0xbc),param_2 & 0xffffffff,param_3,param_4,
                         (uint)(param_2 >> 0x20) & 0xf | param_5);
      _raw_spin_unlock_irqrestore(lVar3 + 0xe8,*(undefined8 *)(lVar3 + 0xf0));
      return uVar2;
    }
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_get_event @ 001113d4 size=332
// signature: undefined sps_get_event(void)
// callers: []
//------------------------------------------------------------

undefined4 sps_get_event(long param_1,long param_2)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  if (param_1 == 0) {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_get_event__rs,"sps_get_event"), iVar2 != 0)))) {
      _printk(&DAT_0011e9ed,"sps_get_event");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: pipe is NULL\n";
  }
  else {
    if (param_2 != 0) {
      lVar3 = sps_bam_lock();
      if (lVar3 == 0) {
        return 0xffffffff;
      }
      uVar1 = sps_bam_pipe_get_event(lVar3,*(undefined4 *)(param_1 + 0xbc),param_2);
      _raw_spin_unlock_irqrestore(lVar3 + 0xe8,*(undefined8 *)(lVar3 + 0xf0));
      return uVar1;
    }
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_get_event__rs_87,"sps_get_event"), iVar2 != 0)))) {
      _printk(&DAT_00120460,"sps_get_event");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: event_notify is NULL\n";
  }
  ipc_log_string(uVar4,pcVar5,"sps_get_event");
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_is_pipe_empty @ 00111524 size=332
// signature: undefined sps_is_pipe_empty(void)
// callers: []
//------------------------------------------------------------

undefined4 sps_is_pipe_empty(long param_1,long param_2)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  if (param_1 == 0) {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_is_pipe_empty__rs,"sps_is_pipe_empty"), iVar2 != 0)))) {
      _printk(&DAT_0011e9ed,"sps_is_pipe_empty");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: pipe is NULL\n";
  }
  else {
    if (param_2 != 0) {
      lVar3 = sps_bam_lock();
      if (lVar3 == 0) {
        return 0xffffffff;
      }
      uVar1 = sps_bam_pipe_is_empty(lVar3,*(undefined4 *)(param_1 + 0xbc),param_2);
      _raw_spin_unlock_irqrestore(lVar3 + 0xe8,*(undefined8 *)(lVar3 + 0xf0));
      return uVar1;
    }
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_is_pipe_empty__rs_90,"sps_is_pipe_empty"), iVar2 != 0)))) {
      _printk(&DAT_00125457,"sps_is_pipe_empty");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: result pointer is NULL\n";
  }
  ipc_log_string(uVar4,pcVar5,"sps_is_pipe_empty");
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_get_free_count @ 00111674 size=332
// signature: undefined sps_get_free_count(void)
// callers: []
//------------------------------------------------------------

undefined4 sps_get_free_count(long param_1,long param_2)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  if (param_1 == 0) {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_get_free_count__rs,"sps_get_free_count"), iVar2 != 0)))) {
      _printk(&DAT_0011e9ed,"sps_get_free_count");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: pipe is NULL\n";
  }
  else {
    if (param_2 != 0) {
      lVar3 = sps_bam_lock();
      if (lVar3 == 0) {
        return 0xffffffff;
      }
      uVar1 = sps_bam_get_free_count(lVar3,*(undefined4 *)(param_1 + 0xbc),param_2);
      _raw_spin_unlock_irqrestore(lVar3 + 0xe8,*(undefined8 *)(lVar3 + 0xf0));
      return uVar1;
    }
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_get_free_count__rs_93,"sps_get_free_count"), iVar2 != 0)))) {
      _printk(&DAT_00125457,"sps_get_free_count");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: result pointer is NULL\n";
  }
  ipc_log_string(uVar4,pcVar5,"sps_get_free_count");
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_device_reset @ 001117c4 size=648
// signature: undefined sps_device_reset(void)
// callers: []
//------------------------------------------------------------

int sps_device_reset(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_device_reset__rs,"sps_device_reset"), iVar1 != 0)))) {
      _printk(&DAT_0011dfa4,"sps_device_reset");
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: device handle should not be 0\n",
                     "sps_device_reset");
    }
    return -1;
  }
  if ((sps == 0) || (*(int *)(sps + 0x30) == 0)) {
    if (((1 < logging_option) && (debug_level_option != '\0')) &&
       ((print_limit_option == 0 ||
        (iVar1 = ___ratelimit(sps_device_reset__rs_94,"sps_device_reset"), iVar1 != 0)))) {
      _printk(&DAT_00122f05,"sps_device_reset");
    }
    if ((sps == 0) || (3 < *(uint *)(sps + 0x120))) {
      return -0x205;
    }
    ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: sps driver is not ready\n",
                   "sps_device_reset");
    return -0x205;
  }
  mutex_lock(sps + 0x70);
  lVar3 = sps_h2bam(param_1);
  if (lVar3 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_device_reset__rs_95,"sps_device_reset"), iVar1 != 0)))) {
      _printk(&DAT_00124224,"sps_device_reset",param_1);
    }
    iVar1 = -1;
    if (sps == 0) goto LAB_00111988;
    pcVar4 = "%s: sps:Invalid BAM device handle: 0x%pK\n";
  }
  else {
    mutex_lock(lVar3 + 0xa8);
    iVar1 = sps_bam_reset(lVar3);
    mutex_unlock(lVar3 + 0xa8);
    if (iVar1 == 0) goto LAB_00111988;
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_device_reset__rs_96,"sps_device_reset"), iVar2 != 0)))) {
      _printk(&DAT_001258a8,"sps_device_reset",param_1);
    }
    if (sps == 0) goto LAB_00111988;
    pcVar4 = "%s: sps:Fail to reset BAM device: 0x%pK\n";
  }
  ipc_log_string(*(undefined8 *)(sps + 0x110),pcVar4,"sps_device_reset",param_1);
LAB_00111988:
  mutex_unlock(sps + 0x70);
  return iVar1;
}



//------------------------------------------------------------
// sps_get_config @ 00111a50 size=616
// signature: undefined sps_get_config(void)
// callers: []
//------------------------------------------------------------

undefined8 sps_get_config(long param_1,void *param_2)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  long lVar4;
  
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_get_config__rs,"sps_get_config"), iVar1 != 0)))) {
      _printk(&DAT_0011e9ed,"sps_get_config");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar2 = *(undefined8 *)(sps + 0x110);
    pcVar3 = "%s: sps: pipe is NULL\n";
LAB_00111b54:
    ipc_log_string(uVar2,pcVar3,"sps_get_config");
    return 0xffffffff;
  }
  if (param_2 == (void *)0x0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_get_config__rs_99,"sps_get_config"), iVar1 != 0)))) {
      _printk(&DAT_0011f984,"sps_get_config");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar2 = *(undefined8 *)(sps + 0x110);
    pcVar3 = "%s: sps: config pointer is NULL\n";
    goto LAB_00111b54;
  }
  lVar4 = *(long *)(param_1 + 0x18);
  if (lVar4 == 0) {
    if (((1 < logging_option) && (3 < debug_level_option)) &&
       ((print_limit_option == 0 ||
        (iVar1 = ___ratelimit(sps_get_config__rs_102,"sps_get_config"), iVar1 != 0)))) {
      _printk(&DAT_00122f6a,"sps_get_config","sps_get_config");
    }
    if ((sps != 0) && (*(int *)(sps + 0x120) == 0)) {
      ipc_log_string(*(undefined8 *)(sps + 0xf8),"%s: sps:%s\n","sps_get_config","sps_get_config");
    }
    goto LAB_00111b9c;
  }
  if (1 < logging_option) {
    if (3 < debug_level_option) {
      if (print_limit_option != 0) {
        iVar1 = ___ratelimit(sps_get_config__rs_105,"sps_get_config");
        if (iVar1 == 0) goto LAB_00111bd0;
        lVar4 = *(long *)(param_1 + 0x18);
      }
      _printk(&DAT_0012074f,"sps_get_config",lVar4 + 0x18,*(undefined4 *)(param_1 + 0xbc),
              *(undefined4 *)(param_1 + 0x54));
    }
LAB_00111bd0:
    lVar4 = *(long *)(param_1 + 0x18);
    if (lVar4 == 0) goto LAB_00111b9c;
  }
  if (*(int *)(lVar4 + 0x238) == 0) {
    ipc_log_string(*(undefined8 *)(lVar4 + 0x210),"%s: sps: BAM: %pa; pipe index:%d; options:0x%x\n"
                   ,"sps_get_config",lVar4 + 0x18,*(undefined4 *)(param_1 + 0xbc),
                   *(undefined4 *)(param_1 + 0x54));
  }
LAB_00111b9c:
  memcpy(param_2,(void *)(param_1 + 0x20),0x90);
  return 0;
}



//------------------------------------------------------------
// sps_set_config @ 00111cbc size=600
// signature: undefined sps_set_config(void)
// callers: []
//------------------------------------------------------------

int sps_set_config(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_set_config__rs,"sps_set_config"), iVar1 != 0)))) {
      _printk(&DAT_0011e9ed,"sps_set_config");
    }
    if (sps == 0) {
      return -1;
    }
    uVar3 = *(undefined8 *)(sps + 0x110);
    pcVar4 = "%s: sps: pipe is NULL\n";
  }
  else if (param_2 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_set_config__rs_108,"sps_set_config"), iVar1 != 0)))) {
      _printk(&DAT_0011f984,"sps_set_config");
    }
    if (sps == 0) {
      return -1;
    }
    uVar3 = *(undefined8 *)(sps + 0x110);
    pcVar4 = "%s: sps: config pointer is NULL\n";
  }
  else {
    lVar2 = sps_bam_lock();
    if (lVar2 != 0) {
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar1 = ___ratelimit(sps_set_config__rs_112,"sps_set_config"), iVar1 != 0)))) {
        _printk(&DAT_00122850,"sps_set_config",lVar2 + 0x18,*(undefined4 *)(param_1 + 0xbc),
                *(undefined4 *)(param_2 + 0x34));
      }
      if (*(int *)(lVar2 + 0x238) == 0) {
        ipc_log_string(*(undefined8 *)(lVar2 + 0x210),
                       "%s: sps: BAM: %pa; pipe index:%d, config-options:0x%x\n","sps_set_config",
                       lVar2 + 0x18,*(undefined4 *)(param_1 + 0xbc),*(undefined4 *)(param_2 + 0x34))
        ;
      }
      iVar1 = sps_bam_pipe_set_params
                        (lVar2,*(undefined4 *)(param_1 + 0xbc),*(undefined4 *)(param_2 + 0x34));
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_2 + 0x34);
      }
      _raw_spin_unlock_irqrestore(lVar2 + 0xe8,*(undefined8 *)(lVar2 + 0xf0));
      return iVar1;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_set_config__rs_109,"sps_set_config"), iVar1 != 0)))) {
      _printk(&DAT_00122f78,"sps_set_config");
    }
    if (sps == 0) {
      return -1;
    }
    uVar3 = *(undefined8 *)(sps + 0x110);
    pcVar4 = "%s: sps: BAM is NULL\n";
  }
  ipc_log_string(uVar3,pcVar4,"sps_set_config");
  return -1;
}



//------------------------------------------------------------
// sps_set_owner @ 00111f18 size=688
// signature: undefined sps_set_owner(void)
// callers: []
//------------------------------------------------------------

int sps_set_owner(long param_1,int param_2,undefined8 *param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_set_owner__rs,"sps_set_owner"), iVar1 != 0)))) {
      _printk(&DAT_0011e9ed,"sps_set_owner");
    }
    if (sps != 0) {
      uVar3 = *(undefined8 *)(sps + 0x110);
      pcVar4 = "%s: sps: pipe is NULL\n";
LAB_0011205c:
      ipc_log_string(uVar3,pcVar4,"sps_set_owner");
      return -1;
    }
  }
  else if (param_3 == (undefined8 *)0x0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_set_owner__rs_115,"sps_set_owner"), iVar1 != 0)))) {
      _printk(&DAT_001236d9,"sps_set_owner");
    }
    if (sps != 0) {
      uVar3 = *(undefined8 *)(sps + 0x110);
      pcVar4 = "%s: sps: connection is NULL\n";
      goto LAB_0011205c;
    }
  }
  else if (param_2 == 2) {
    lVar2 = sps_bam_lock();
    if (lVar2 != 0) {
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar1 = ___ratelimit(sps_set_owner__rs_119,"sps_set_owner"), iVar1 != 0)))) {
        _printk(&DAT_0011e5a6,"sps_set_owner",lVar2 + 0x18,*(undefined4 *)(param_1 + 0xbc));
      }
      if (*(int *)(lVar2 + 0x238) == 0) {
        ipc_log_string(*(undefined8 *)(lVar2 + 0x210),"%s: sps: BAM: %pa; pipe index:%d\n",
                       "sps_set_owner",lVar2 + 0x18,*(undefined4 *)(param_1 + 0xbc));
      }
      iVar1 = sps_bam_set_satellite(lVar2,*(undefined4 *)(param_1 + 0xbc));
      if (iVar1 == 0) {
        if (*(int *)(param_1 + 0x4c) == 0) {
          *param_3 = *(undefined8 *)(*(long *)(param_1 + 0xb0) + 0x18);
          puVar5 = (undefined4 *)(*(long *)(param_1 + 0xb0) + 0x20);
        }
        else {
          *param_3 = *(undefined8 *)(*(long *)(param_1 + 0xb0) + 0x40);
          puVar5 = (undefined4 *)(*(long *)(param_1 + 0xb0) + 0x48);
        }
        *(undefined4 *)(param_3 + 1) = *puVar5;
        *(undefined8 *)((long)param_3 + 0xc) = 0x11111111;
      }
      _raw_spin_unlock_irqrestore(lVar2 + 0xe8,*(undefined8 *)(lVar2 + 0xf0));
      return iVar1;
    }
  }
  else {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_set_owner__rs_116,"sps_set_owner"), iVar1 != 0)))) {
      _printk(&DAT_00122f90,"sps_set_owner",param_2);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: Unsupported ownership state: %d\n",
                     "sps_set_owner",param_2);
    }
  }
  return -1;
}



//------------------------------------------------------------
// sps_alloc_mem @ 001121cc size=772
// signature: undefined sps_alloc_mem(void)
// callers: []
//------------------------------------------------------------

undefined8 sps_alloc_mem(long param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  
  if (sps == 0) {
    return 0xffffffed;
  }
  if (*(int *)(sps + 0x30) == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_alloc_mem__rs,"sps_alloc_mem"), iVar1 != 0)))) {
      _printk(&DAT_00124756,"sps_alloc_mem");
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: sps driver is not ready\n",
                     "sps_alloc_mem");
    }
    return 0xfffffff5;
  }
  if ((param_3 == (undefined8 *)0x0) || (*(int *)(param_3 + 3) == 0)) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_alloc_mem__rs_122,"sps_alloc_mem"), iVar1 != 0)))) {
      _printk(&DAT_00124250,"sps_alloc_mem");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar3 = *(undefined8 *)(sps + 0x110);
    pcVar4 = "%s: sps: invalid memory buffer address or size\n";
  }
  else {
    if (param_1 == 0) {
      if (((1 < logging_option) && (1 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar1 = ___ratelimit(sps_alloc_mem__rs_125,"sps_alloc_mem"), iVar1 != 0)))) {
        _printk(&DAT_00123a5a,"sps_alloc_mem");
      }
      if ((sps != 0) && (*(uint *)(sps + 0x120) < 3)) {
        ipc_log_string(*(undefined8 *)(sps + 0x108),
                       "%s: sps: allocate pipe memory before setup pipe\n","sps_alloc_mem");
      }
    }
    else {
      if (((1 < logging_option) && (1 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar1 = ___ratelimit(sps_alloc_mem__rs_128,"sps_alloc_mem"), iVar1 != 0)))) {
        _printk(&DAT_00124282,"sps_alloc_mem",*(undefined4 *)(param_1 + 0xbc));
      }
      if ((sps != 0) && (*(uint *)(sps + 0x120) < 3)) {
        ipc_log_string(*(undefined8 *)(sps + 0x108),"%s: sps:allocate pipe memory for pipe %d\n",
                       "sps_alloc_mem",*(undefined4 *)(param_1 + 0xbc));
      }
    }
    lVar2 = sps_mem_alloc_io(*(undefined4 *)(param_3 + 3));
    param_3[1] = lVar2;
    if (lVar2 != 0xdeadbeef) {
      uVar3 = spsi_get_mem_ptr();
      *param_3 = uVar3;
      return 0;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_alloc_mem__rs_131,"sps_alloc_mem"), iVar1 != 0)))) {
      _printk(&DAT_00122fbc,"sps_alloc_mem");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar3 = *(undefined8 *)(sps + 0x110);
    pcVar4 = "%s: sps: invalid address of allocated memory\n";
  }
  ipc_log_string(uVar3,pcVar4,"sps_alloc_mem");
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_free_mem @ 001124d4 size=628
// signature: undefined sps_free_mem(void)
// callers: []
//------------------------------------------------------------

undefined8 sps_free_mem(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (((1 < logging_option) && (3 < debug_level_option)) &&
     ((print_limit_option == 0 ||
      (iVar1 = ___ratelimit(sps_free_mem__rs,"sps_free_mem"), iVar1 != 0)))) {
    _printk(&DAT_00121fe7,"sps_free_mem");
  }
  if ((sps != 0) && (*(int *)(sps + 0x120) == 0)) {
    ipc_log_string(*(undefined8 *)(sps + 0xf8),"%s: sps: Enter\n","sps_free_mem");
  }
  if ((param_2 == 0) || (*(long *)(param_2 + 8) == 0xdeadbeef)) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_free_mem__rs_136,"sps_free_mem"), iVar1 != 0)))) {
      _printk(&DAT_00122455,"sps_free_mem");
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: invalid memory to free\n","sps_free_mem"
                    );
    }
    uVar2 = 0xffffffff;
  }
  else {
    if (param_1 == 0) {
      if (((1 < logging_option) && (1 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar1 = ___ratelimit(sps_free_mem__rs_139,"sps_free_mem"), iVar1 != 0)))) {
        _printk(&DAT_0011f9a7,"sps_free_mem");
      }
      if ((sps != 0) && (*(uint *)(sps + 0x120) < 3)) {
        ipc_log_string(*(undefined8 *)(sps + 0x108),"%s: sps: free pipe memory\n","sps_free_mem");
      }
    }
    else {
      if (((1 < logging_option) && (1 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar1 = ___ratelimit(sps_free_mem__rs_142,"sps_free_mem"), iVar1 != 0)))) {
        _printk(&DAT_001247a6,"sps_free_mem",*(undefined4 *)(param_1 + 0xbc));
      }
      if ((sps != 0) && (*(uint *)(sps + 0x120) < 3)) {
        ipc_log_string(*(undefined8 *)(sps + 0x108),"%s: sps:free pipe memory for pipe %d\n",
                       "sps_free_mem",*(undefined4 *)(param_1 + 0xbc));
      }
    }
    sps_mem_free_io(*(undefined8 *)(param_2 + 8),*(undefined4 *)(param_2 + 0x18));
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// sps_get_unused_desc_num @ 0011274c size=480
// signature: undefined sps_get_unused_desc_num(void)
// callers: []
//------------------------------------------------------------

undefined4 sps_get_unused_desc_num(long param_1,long param_2)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_get_unused_desc_num__rs,"sps_get_unused_desc_num"), iVar2 != 0))))
    {
      _printk(&DAT_0011e9ed,"sps_get_unused_desc_num");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: pipe is NULL\n";
  }
  else {
    if (param_2 != 0) {
      lVar3 = sps_bam_lock();
      if (lVar3 == 0) {
        return 0xffffffff;
      }
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar2 = ___ratelimit(sps_get_unused_desc_num__rs_146,"sps_get_unused_desc_num"),
          iVar2 != 0)))) {
        _printk(&DAT_0011e5a6,"sps_get_unused_desc_num",lVar3 + 0x18,*(undefined4 *)(param_1 + 0xbc)
               );
      }
      if (*(int *)(lVar3 + 0x238) == 0) {
        ipc_log_string(*(undefined8 *)(lVar3 + 0x210),"%s: sps: BAM: %pa; pipe index:%d\n",
                       "sps_get_unused_desc_num",lVar3 + 0x18,*(undefined4 *)(param_1 + 0xbc));
      }
      uVar1 = sps_bam_pipe_get_unused_desc_num(lVar3,*(undefined4 *)(param_1 + 0xbc),param_2);
      _raw_spin_unlock_irqrestore(lVar3 + 0xe8,*(undefined8 *)(lVar3 + 0xf0));
      return uVar1;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_get_unused_desc_num__rs_145,"sps_get_unused_desc_num"), iVar2 != 0
        )))) {
      _printk(&DAT_00125457,"sps_get_unused_desc_num");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: result pointer is NULL\n";
  }
  ipc_log_string(uVar4,pcVar5,"sps_get_unused_desc_num");
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_ctrl_bam_dma_clk @ 00112930 size=708
// signature: undefined sps_ctrl_bam_dma_clk(void)
// callers: []
//------------------------------------------------------------

int sps_ctrl_bam_dma_clk(ulong param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  if ((sps == 0) || (*(int *)(sps + 0x30) == 0)) {
    if (((1 < logging_option) && (debug_level_option != 0)) &&
       ((print_limit_option == 0 ||
        (iVar1 = ___ratelimit(sps_ctrl_bam_dma_clk__rs,"sps_ctrl_bam_dma_clk"), iVar1 != 0)))) {
      _printk(&DAT_00122f05,"sps_ctrl_bam_dma_clk");
    }
    if ((sps != 0) && (*(uint *)(sps + 0x120) < 4)) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: sps driver is not ready\n",
                     "sps_ctrl_bam_dma_clk");
    }
    iVar1 = -0x205;
  }
  else if ((param_1 & 1) == 0) {
    if (((1 < logging_option) && (2 < debug_level_option)) &&
       ((print_limit_option == 0 ||
        (iVar1 = ___ratelimit(sps_ctrl_bam_dma_clk__rs_154,"sps_ctrl_bam_dma_clk"), iVar1 != 0)))) {
      _printk(&DAT_0012561d,"sps_ctrl_bam_dma_clk","sps:relinquish bam dma clk\n");
    }
    if ((sps != 0) && (*(uint *)(sps + 0x120) < 2)) {
      ipc_log_string(*(undefined8 *)(sps + 0x100),"%s: %s","sps_ctrl_bam_dma_clk",
                     "sps:relinquish bam dma clk\n");
    }
    uVar3 = *(undefined8 *)(sps + 0x20);
    clk_disable(uVar3);
    clk_unprepare(uVar3);
    iVar1 = 0;
  }
  else {
    if (((1 < logging_option) && (2 < debug_level_option)) &&
       ((print_limit_option == 0 ||
        (iVar1 = ___ratelimit(sps_ctrl_bam_dma_clk__rs_147,"sps_ctrl_bam_dma_clk"), iVar1 != 0)))) {
      _printk(&DAT_0012561d,"sps_ctrl_bam_dma_clk","sps:vote for bam dma clk\n");
    }
    if ((sps != 0) && (*(uint *)(sps + 0x120) < 2)) {
      ipc_log_string(*(undefined8 *)(sps + 0x100),"%s: %s","sps_ctrl_bam_dma_clk",
                     "sps:vote for bam dma clk\n");
    }
    uVar3 = *(undefined8 *)(sps + 0x20);
    iVar1 = clk_prepare(uVar3);
    if (iVar1 == 0) {
      iVar1 = clk_enable(uVar3);
      if (iVar1 == 0) {
        return 0;
      }
      clk_unprepare(uVar3);
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_ctrl_bam_dma_clk__rs_151,"sps_ctrl_bam_dma_clk"), iVar2 != 0)))) {
      _printk(&DAT_00121ff9,"sps_ctrl_bam_dma_clk",iVar1);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps:fail to enable bamdma_clk:ret=%d\n",
                     "sps_ctrl_bam_dma_clk",iVar1);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// sps_register_bam_device @ 00112bf8 size=2804
// signature: undefined sps_register_bam_device(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 sps_register_bam_device(byte *param_1,undefined8 *param_2)

{
  long *plVar1;
  long *param3;
  int iVar2;
  long lVar3;
  ulong uVar4;
  char *pcVar5;
  long *plVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  byte *pbVar9;
  long lVar10;
  char local_a8 [80];
  long local_58;
  
  lVar10 = sp_el0;
  local_58 = *(long *)(lVar10 + 0x638);
  local_a8[0x40] = '\0';
  local_a8[0x41] = '\0';
  local_a8[0x42] = '\0';
  local_a8[0x43] = '\0';
  local_a8[0x44] = '\0';
  local_a8[0x45] = '\0';
  local_a8[0x46] = '\0';
  local_a8[0x47] = '\0';
  local_a8[0x48] = '\0';
  local_a8[0x49] = '\0';
  local_a8[0x4a] = '\0';
  local_a8[0x4b] = '\0';
  local_a8[0x4c] = '\0';
  local_a8[0x4d] = '\0';
  local_a8[0x4e] = '\0';
  local_a8[0x4f] = '\0';
  local_a8[0x30] = '\0';
  local_a8[0x31] = '\0';
  local_a8[0x32] = '\0';
  local_a8[0x33] = '\0';
  local_a8[0x34] = '\0';
  local_a8[0x35] = '\0';
  local_a8[0x36] = '\0';
  local_a8[0x37] = '\0';
  local_a8[0x38] = '\0';
  local_a8[0x39] = '\0';
  local_a8[0x3a] = '\0';
  local_a8[0x3b] = '\0';
  local_a8[0x3c] = '\0';
  local_a8[0x3d] = '\0';
  local_a8[0x3e] = '\0';
  local_a8[0x3f] = '\0';
  local_a8[0x20] = '\0';
  local_a8[0x21] = '\0';
  local_a8[0x22] = '\0';
  local_a8[0x23] = '\0';
  local_a8[0x24] = '\0';
  local_a8[0x25] = '\0';
  local_a8[0x26] = '\0';
  local_a8[0x27] = '\0';
  local_a8[0x28] = '\0';
  local_a8[0x29] = '\0';
  local_a8[0x2a] = '\0';
  local_a8[0x2b] = '\0';
  local_a8[0x2c] = '\0';
  local_a8[0x2d] = '\0';
  local_a8[0x2e] = '\0';
  local_a8[0x2f] = '\0';
  local_a8[0x10] = '\0';
  local_a8[0x11] = '\0';
  local_a8[0x12] = '\0';
  local_a8[0x13] = '\0';
  local_a8[0x14] = '\0';
  local_a8[0x15] = '\0';
  local_a8[0x16] = '\0';
  local_a8[0x17] = '\0';
  local_a8[0x18] = '\0';
  local_a8[0x19] = '\0';
  local_a8[0x1a] = '\0';
  local_a8[0x1b] = '\0';
  local_a8[0x1c] = '\0';
  local_a8[0x1d] = '\0';
  local_a8[0x1e] = '\0';
  local_a8[0x1f] = '\0';
  local_a8[0] = '\0';
  local_a8[1] = '\0';
  local_a8[2] = '\0';
  local_a8[3] = '\0';
  local_a8[4] = '\0';
  local_a8[5] = '\0';
  local_a8[6] = '\0';
  local_a8[7] = '\0';
  local_a8[8] = '\0';
  local_a8[9] = '\0';
  local_a8[10] = '\0';
  local_a8[0xb] = '\0';
  local_a8[0xc] = '\0';
  local_a8[0xd] = '\0';
  local_a8[0xe] = '\0';
  local_a8[0xf] = '\0';
  if (param_1 == (byte *)0x0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_register_bam_device__rs,"sps_register_bam_device"), iVar2 != 0))))
    {
      _printk(&DAT_00122889,"sps_register_bam_device");
    }
    if (sps != 0) {
      uVar7 = *(undefined8 *)(sps + 0x110);
      pcVar5 = "%s: sps: bam_props is NULL\n";
LAB_00112ea0:
      ipc_log_string(uVar7,pcVar5,"sps_register_bam_device");
    }
  }
  else if (param_2 == (undefined8 *)0x0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_register_bam_device__rs_158,"sps_register_bam_device"), iVar2 != 0
        )))) {
      _printk(&DAT_001242ae,"sps_register_bam_device");
    }
    if (sps != 0) {
      uVar7 = *(undefined8 *)(sps + 0x110);
      pcVar5 = "%s: sps: device handle is NULL\n";
      goto LAB_00112ea0;
    }
  }
  else {
    if (sps == 0) {
      _printk(&DAT_00123004);
      uVar7 = 0xfffffdfb;
      goto LAB_00112eb0;
    }
    if (logging_option < 2) {
LAB_00112c64:
      if (*(uint *)(sps + 0x120) < 4) {
        ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: Client requests to register BAM %pa\n"
                       ,"sps_register_bam_device",param_1 + 8);
      }
    }
    else {
      if ((debug_level_option != 0) &&
         ((print_limit_option == 0 ||
          (iVar2 = ___ratelimit(sps_register_bam_device__rs_162,"sps_register_bam_device"),
          iVar2 != 0)))) {
        _printk(&DAT_001258e0,"sps_register_bam_device",param_1 + 8);
      }
      if (sps != 0) goto LAB_00112c64;
    }
    if ((*(int *)(sps + 0x30) == 0) && ((*param_1 >> 2 & 1) == 0)) {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar2 = ___ratelimit(sps_register_bam_device__rs_165,"sps_register_bam_device"),
          iVar2 != 0)))) {
        _printk(&DAT_001232e2,"sps_register_bam_device");
      }
      if (sps == 0) {
        uVar7 = 0xfffffff5;
      }
      else {
        ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: sps driver not ready\n",
                       "sps_register_bam_device");
        uVar7 = 0xfffffff5;
      }
      goto LAB_00112eb0;
    }
    if (((((*(uint *)(param_1 + 0x68) ^ 0xffffffff) & 0x1d) == 0) ||
        (*(long *)(param_1 + 0x10) != 0)) || (*(int *)(param_1 + 0x18) != 0)) {
      if (((*(uint *)(param_1 + 0x68) & 1) != 0) || (*(int *)(param_1 + 0x24) != 0)) {
        *param_2 = 0;
        mutex_lock(sps + 0x70);
        pbVar9 = param_1 + 8;
        lVar10 = *(long *)pbVar9;
        if (((1 < logging_option) && (1 < debug_level_option)) &&
           ((print_limit_option == 0 || (iVar2 = ___ratelimit(phy2bam__rs,"phy2bam"), iVar2 != 0))))
        {
          _printk(&DAT_0011f4ab,"phy2bam");
        }
        if ((sps != 0) && (*(uint *)(sps + 0x120) < 3)) {
          ipc_log_string(*(undefined8 *)(sps + 0x108),"%s: Enter\n","phy2bam");
        }
        plVar6 = (long *)(sps + 0xa0);
        do {
          plVar6 = (long *)*plVar6;
          if (plVar6 == (long *)(sps + 0xa0)) goto LAB_00112ee8;
        } while (plVar6[3] != lVar10);
        if (plVar6 == (long *)0x0) {
LAB_00112ee8:
          if ((((*(uint *)(param_1 + 0x68) ^ 0xffffffff) & 0x1d) == 0) ||
             (*(long *)(param_1 + 0x10) != 0)) {
            lVar10 = 0;
LAB_00112f04:
            plVar6 = (long *)kmalloc_trace(_debugfs_create_file,0xdc0,0x340);
            if (plVar6 != (long *)0x0) {
              memset(plVar6,0,0x340);
              plVar1 = plVar6 + 0x15;
              __mutex_init(plVar1,"&bam->lock",&sps_register_bam_device___key);
              mutex_lock(plVar1);
              memcpy(plVar6 + 2,param_1,0x90);
              if (lVar10 != 0) {
                plVar6[4] = lVar10;
              }
              param3 = plVar6 + 3;
              snprintf(local_a8,0x50,"sps_bam_%pa_0",param3);
              lVar3 = ipc_log_context_create(10,local_a8,0);
              plVar6[0x42] = lVar3;
              if (lVar3 == 0) {
                if ((logging_option != 1) &&
                   ((print_limit_option < 3 ||
                    (iVar2 = ___ratelimit(sps_register_bam_device__rs_180,"sps_register_bam_device")
                    , iVar2 != 0)))) {
                  _printk(&DAT_0011f4d2,"sps_register_bam_device",param3);
                }
                if (sps != 0) {
                  ipc_log_string(*(undefined8 *)(sps + 0x110),
                                 "%s: unable to create IPC Log 0 for bam %pa\n",
                                 "sps_register_bam_device",param3);
                }
              }
              snprintf(local_a8,0x50,"sps_bam_%pa_1",param3);
              lVar3 = ipc_log_context_create(10,local_a8,0);
              plVar6[0x43] = lVar3;
              if (lVar3 == 0) {
                if ((logging_option != 1) &&
                   ((print_limit_option < 3 ||
                    (iVar2 = ___ratelimit(sps_register_bam_device__rs_184,"sps_register_bam_device")
                    , iVar2 != 0)))) {
                  _printk(&DAT_0011e031,"sps_register_bam_device",param3);
                }
                if (sps != 0) {
                  ipc_log_string(*(undefined8 *)(sps + 0x110),
                                 "%s: unable to create IPC Log 1 for bam %pa\n",
                                 "sps_register_bam_device",param3);
                }
              }
              snprintf(local_a8,0x50,"sps_bam_%pa_2",param3);
              lVar3 = ipc_log_context_create(10,local_a8,0);
              plVar6[0x44] = lVar3;
              if (lVar3 == 0) {
                if ((logging_option != 1) &&
                   ((print_limit_option < 3 ||
                    (iVar2 = ___ratelimit(sps_register_bam_device__rs_188,"sps_register_bam_device")
                    , iVar2 != 0)))) {
                  _printk(&DAT_00121485,"sps_register_bam_device",param3);
                }
                if (sps != 0) {
                  ipc_log_string(*(undefined8 *)(sps + 0x110),
                                 "%s: unable to create IPC Log 2 for bam %pa\n",
                                 "sps_register_bam_device",param3);
                }
              }
              snprintf(local_a8,0x50,"sps_bam_%pa_3",param3);
              lVar3 = ipc_log_context_create(10,local_a8,0);
              plVar6[0x45] = lVar3;
              if (lVar3 == 0) {
                if ((logging_option != 1) &&
                   ((print_limit_option < 3 ||
                    (iVar2 = ___ratelimit(sps_register_bam_device__rs_192,"sps_register_bam_device")
                    , iVar2 != 0)))) {
                  _printk(&DAT_00123ab7,"sps_register_bam_device",param3);
                }
                if (sps != 0) {
                  ipc_log_string(*(undefined8 *)(sps + 0x110),
                                 "%s: unable to create IPC Log 3 for bam %pa\n",
                                 "sps_register_bam_device",param3);
                }
              }
              snprintf(local_a8,0x50,"sps_bam_%pa_4",param3);
              lVar3 = ipc_log_context_create(10,local_a8,0);
              plVar6[0x46] = lVar3;
              if (lVar3 == 0) {
                if ((logging_option != 1) &&
                   ((print_limit_option < 3 ||
                    (iVar2 = ___ratelimit(sps_register_bam_device__rs_196,"sps_register_bam_device")
                    , iVar2 != 0)))) {
                  _printk(&DAT_001204b1,"sps_register_bam_device",param3);
                }
                if (sps != 0) {
                  ipc_log_string(*(undefined8 *)(sps + 0x110),
                                 "%s: unable to create IPC Log 4 for bam %pa\n",
                                 "sps_register_bam_device",param3);
                }
              }
              iVar2 = 3;
              if (*(int *)(param_1 + 0x74) != 0) {
                iVar2 = *(int *)(param_1 + 0x74);
              }
              *(int *)(plVar6 + 0x47) = iVar2;
              iVar2 = sps_bam_device_init(plVar6);
              mutex_unlock(plVar1);
              lVar3 = sps;
              if (iVar2 == 0) {
                puVar8 = *(undefined8 **)(sps + 0xa8);
                lVar10 = sps + 0xa0;
                uVar4 = __list_add_valid(plVar6,puVar8,lVar10);
                if ((uVar4 & 1) != 0) {
                  *(long **)(lVar3 + 0xa8) = plVar6;
                  *plVar6 = lVar10;
                  plVar6[1] = (long)puVar8;
                  *puVar8 = plVar6;
                }
                *param_2 = plVar6;
                mutex_unlock(sps + 0x70);
                if ((logging_option != 1) &&
                   ((print_limit_option < 2 ||
                    (iVar2 = ___ratelimit(sps_register_bam_device__rs_202,"sps_register_bam_device")
                    , iVar2 != 0)))) {
                  _printk(&DAT_00124f63,"sps_register_bam_device",param3);
                }
                ipc_log_string(plVar6[0x45],"%s: sps:BAM %pa is registered\n",
                               "sps_register_bam_device",param3);
                uVar7 = 0;
                goto LAB_00112eb0;
              }
              if ((logging_option != 1) &&
                 ((print_limit_option < 3 ||
                  (iVar2 = ___ratelimit(sps_register_bam_device__rs_199,"sps_register_bam_device"),
                  iVar2 != 0)))) {
                _printk(&DAT_00125910,"sps_register_bam_device",param3);
              }
              ipc_log_string(plVar6[0x45],"%s: sps:Fail to init BAM device: phys %pa\n",
                             "sps_register_bam_device",param3);
              mutex_unlock(sps + 0x70);
              if (lVar10 != 0) {
                iounmap(plVar6[4]);
              }
              kfree(plVar6);
              goto LAB_00112eac;
            }
          }
          else {
            uVar7 = 0x68000000000713;
            if (arm64_use_ng_mappings != '\0') {
              uVar7 = 0x68000000000f13;
            }
            lVar10 = ioremap_prot(*(undefined8 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x18),uVar7
                                 );
            if (lVar10 != 0) goto LAB_00112f04;
            if ((logging_option != 1) &&
               ((print_limit_option < 3 ||
                (iVar2 = ___ratelimit(sps_register_bam_device__rs_175,"sps_register_bam_device"),
                iVar2 != 0)))) {
              _printk(&DAT_001254b1,"sps_register_bam_device",pbVar9,*(undefined4 *)(param_1 + 0x18)
                     );
            }
            if (sps != 0) {
              ipc_log_string(*(undefined8 *)(sps + 0x110),
                             "%s: sps:Unable to map BAM IO mem:%pa size:0x%x\n",
                             "sps_register_bam_device",pbVar9,*(undefined4 *)(param_1 + 0x18));
            }
          }
          uVar7 = 0xffffffff;
        }
        else {
          mutex_unlock(sps + 0x70);
          if ((logging_option != 1) &&
             ((print_limit_option < 3 ||
              (iVar2 = ___ratelimit(sps_register_bam_device__rs_172,"sps_register_bam_device"),
              iVar2 != 0)))) {
            _printk(&DAT_0011ff42,"sps_register_bam_device",plVar6 + 3);
          }
          if (sps != 0) {
            ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps:BAM is already registered: %pa\n",
                           "sps_register_bam_device",plVar6 + 3);
          }
          uVar7 = 0xffffffef;
        }
        mutex_unlock(sps + 0x70);
        goto LAB_00112eb0;
      }
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar2 = ___ratelimit(sps_register_bam_device__rs_169,"sps_register_bam_device"),
          iVar2 != 0)))) {
        _printk(&DAT_0011d874,"sps_register_bam_device",param_1 + 8);
      }
      if (sps != 0) {
        uVar7 = *(undefined8 *)(sps + 0x110);
        pcVar5 = "%s: sps:Invalid device ctrl properties for BAM: %pa\n";
        goto LAB_001134a4;
      }
    }
    else {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar2 = ___ratelimit(sps_register_bam_device__rs_166,"sps_register_bam_device"),
          iVar2 != 0)))) {
        _printk(&DAT_00123334,"sps_register_bam_device",param_1 + 8);
      }
      if (sps != 0) {
        uVar7 = *(undefined8 *)(sps + 0x110);
        pcVar5 = "%s: sps:Invalid properties for BAM: %pa\n";
LAB_001134a4:
        ipc_log_string(uVar7,pcVar5,"sps_register_bam_device",param_1 + 8);
      }
    }
  }
LAB_00112eac:
  uVar7 = 0xffffffff;
LAB_00112eb0:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// sps_deregister_bam_device @ 001136f0 size=628
// signature: undefined sps_deregister_bam_device(void)
// callers: []
//------------------------------------------------------------

undefined8 sps_deregister_bam_device(long param_1)

{
  long *plVar1;
  int iVar2;
  long *plVar3;
  ulong uVar4;
  undefined8 uVar5;
  char *pcVar6;
  long lVar7;
  
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_deregister_bam_device__rs,"sps_deregister_bam_device"), iVar2 != 0
        )))) {
      _printk(&DAT_0011dfa4,"sps_deregister_bam_device");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar5 = *(undefined8 *)(sps + 0x110);
    pcVar6 = "%s: sps: device handle should not be 0\n";
  }
  else {
    plVar3 = (long *)sps_h2bam();
    if (plVar3 != (long *)0x0) {
      if (((1 < logging_option) && (debug_level_option != '\0')) &&
         ((print_limit_option == 0 ||
          (iVar2 = ___ratelimit(sps_deregister_bam_device__rs_208,"sps_deregister_bam_device"),
          iVar2 != 0)))) {
        _printk(&DAT_0011e611,"sps_deregister_bam_device",plVar3 + 3);
      }
      if ((sps != 0) && (*(uint *)(sps + 0x120) < 4)) {
        ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: SPS deregister BAM: phys %pa\n",
                       "sps_deregister_bam_device",plVar3 + 3);
      }
      if ((*(byte *)((long)plVar3 + 0x11) & 1) != 0) {
        lVar7 = 0;
        do {
          kfree(*(undefined8 *)((long)plVar3 + lVar7 + 0x240));
          lVar7 = lVar7 + 8;
        } while (lVar7 != 0xf8);
      }
      mutex_lock(sps + 0x70);
      uVar4 = __list_del_entry_valid(plVar3);
      if ((uVar4 & 1) != 0) {
        lVar7 = *plVar3;
        plVar1 = (long *)plVar3[1];
        *(long **)(lVar7 + 8) = plVar1;
        *plVar1 = lVar7;
      }
      *plVar3 = (long)&DAT_dead000000000100;
      plVar3[1] = -0x2152fffffffffede;
      mutex_unlock(sps + 0x70);
      mutex_lock(plVar3 + 0x15);
      sps_bam_device_de_init(plVar3);
      mutex_unlock(plVar3 + 0x15);
      ipc_log_context_destroy(plVar3[0x42]);
      ipc_log_context_destroy(plVar3[0x43]);
      ipc_log_context_destroy(plVar3[0x44]);
      ipc_log_context_destroy(plVar3[0x45]);
      ipc_log_context_destroy(plVar3[0x46]);
      if ((int)plVar3[5] != 0) {
        iounmap(plVar3[4]);
      }
      kfree(plVar3);
      return 0;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_deregister_bam_device__rs_205,"sps_deregister_bam_device"),
        iVar2 != 0)))) {
      _printk(&DAT_0011e5e2,"sps_deregister_bam_device");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar5 = *(undefined8 *)(sps + 0x110);
    pcVar6 = "%s: sps: did not find a BAM for this handle\n";
  }
  ipc_log_string(uVar5,pcVar6,"sps_deregister_bam_device");
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_get_iovec @ 00113968 size=580
// signature: undefined sps_get_iovec(void)
// callers: []
//------------------------------------------------------------

undefined4 sps_get_iovec(long param_1,long param_2)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_get_iovec__rs,"sps_get_iovec"), iVar2 != 0)))) {
      _printk(&DAT_0011e9ed,"sps_get_iovec");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: pipe is NULL\n";
  }
  else if (param_2 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_get_iovec__rs_211,"sps_get_iovec"), iVar2 != 0)))) {
      _printk(&DAT_0011e63a,"sps_get_iovec");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: iovec pointer is NULL\n";
  }
  else {
    lVar3 = sps_bam_lock();
    if (lVar3 != 0) {
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar2 = ___ratelimit(sps_get_iovec__rs_217,"sps_get_iovec"), iVar2 != 0)))) {
        _printk(&DAT_0011e5a6,"sps_get_iovec",lVar3 + 0x18,*(undefined4 *)(param_1 + 0xbc));
      }
      if (*(int *)(lVar3 + 0x238) == 0) {
        ipc_log_string(*(undefined8 *)(lVar3 + 0x210),"%s: sps: BAM: %pa; pipe index:%d\n",
                       "sps_get_iovec",lVar3 + 0x18,*(undefined4 *)(param_1 + 0xbc));
      }
      uVar1 = sps_bam_pipe_get_iovec(lVar3,*(undefined4 *)(param_1 + 0xbc),param_2);
      _raw_spin_unlock_irqrestore(lVar3 + 0xe8,*(undefined8 *)(lVar3 + 0xf0));
      return uVar1;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_get_iovec__rs_214,"sps_get_iovec"), iVar2 != 0)))) {
      _printk(&DAT_001207fb,"sps_get_iovec");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar4 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: BAM is not found by handle\n";
  }
  ipc_log_string(uVar4,pcVar5,"sps_get_iovec");
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_timer_ctrl @ 00113bb0 size=8
// signature: undefined sps_timer_ctrl(void)
// callers: []
//------------------------------------------------------------

undefined8 sps_timer_ctrl(void)

{
  return 0;
}



//------------------------------------------------------------
// sps_pipe_reset @ 00113bbc size=556
// signature: undefined sps_pipe_reset(void)
// callers: []
//------------------------------------------------------------

undefined8 sps_pipe_reset(long param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  char *pcVar4;
  
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_pipe_reset__rs,"sps_pipe_reset"), iVar1 != 0)))) {
      _printk(&DAT_001247fb,"sps_pipe_reset");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar2 = *(undefined8 *)(sps + 0x110);
    pcVar4 = "%s: sps: BAM handle is NULL\n";
  }
  else if (param_2 < 0x1f) {
    lVar3 = sps_h2bam();
    if (lVar3 != 0) {
      if (((1 < logging_option) && (1 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar1 = ___ratelimit(sps_pipe_reset__rs_224,"sps_pipe_reset"), iVar1 != 0)))) {
        _printk(&DAT_0011e5a6,"sps_pipe_reset",lVar3 + 0x18,param_2);
      }
      if (*(uint *)(lVar3 + 0x238) < 3) {
        ipc_log_string(*(undefined8 *)(lVar3 + 0x220),"%s: sps: BAM: %pa; pipe index:%d\n",
                       "sps_pipe_reset",lVar3 + 0x18,param_2);
      }
      bam_pipe_reset(lVar3 + 0xd8,param_2);
      return 0;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_pipe_reset__rs_223,"sps_pipe_reset"), iVar1 != 0)))) {
      _printk(&DAT_001207fb,"sps_pipe_reset");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar2 = *(undefined8 *)(sps + 0x110);
    pcVar4 = "%s: sps: BAM is not found by handle\n";
  }
  else {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_pipe_reset__rs_220,"sps_pipe_reset"), iVar1 != 0)))) {
      _printk(&DAT_0011f9ed,"sps_pipe_reset");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar2 = *(undefined8 *)(sps + 0x110);
    pcVar4 = "%s: sps: pipe index is invalid\n";
  }
  ipc_log_string(uVar2,pcVar4,"sps_pipe_reset");
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_pipe_disable @ 00113dec size=552
// signature: undefined sps_pipe_disable(void)
// callers: []
//------------------------------------------------------------

undefined8 sps_pipe_disable(long param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  char *pcVar4;
  
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_pipe_disable__rs,"sps_pipe_disable"), iVar1 != 0)))) {
      _printk(&DAT_001247fb,"sps_pipe_disable");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar2 = *(undefined8 *)(sps + 0x110);
    pcVar4 = "%s: sps: BAM handle is NULL\n";
  }
  else if (param_2 < 0x1f) {
    lVar3 = sps_h2bam();
    if (lVar3 != 0) {
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar1 = ___ratelimit(sps_pipe_disable__rs_227,"sps_pipe_disable"), iVar1 != 0)))) {
        _printk(&DAT_0011e5a6,"sps_pipe_disable",lVar3 + 0x18,param_2);
      }
      if (*(int *)(lVar3 + 0x238) == 0) {
        ipc_log_string(*(undefined8 *)(lVar3 + 0x210),"%s: sps: BAM: %pa; pipe index:%d\n",
                       "sps_pipe_disable",lVar3 + 0x18,param_2);
      }
      bam_disable_pipe(lVar3 + 0xd8,param_2);
      return 0;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_pipe_disable__rs_226,"sps_pipe_disable"), iVar1 != 0)))) {
      _printk(&DAT_001207fb,"sps_pipe_disable");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar2 = *(undefined8 *)(sps + 0x110);
    pcVar4 = "%s: sps: BAM is not found by handle\n";
  }
  else {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_pipe_disable__rs_225,"sps_pipe_disable"), iVar1 != 0)))) {
      _printk(&DAT_0011f9ed,"sps_pipe_disable");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar2 = *(undefined8 *)(sps + 0x110);
    pcVar4 = "%s: sps: pipe index is invalid\n";
  }
  ipc_log_string(uVar2,pcVar4,"sps_pipe_disable");
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_pipe_pending_desc @ 00114018 size=684
// signature: undefined sps_pipe_pending_desc(void)
// callers: []
//------------------------------------------------------------

undefined8 sps_pipe_pending_desc(long param_1,uint param_2,byte *param_3)

{
  byte bVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  char *pcVar5;
  
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_pipe_pending_desc__rs,"sps_pipe_pending_desc"), iVar2 != 0)))) {
      _printk(&DAT_001247fb,"sps_pipe_pending_desc");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar3 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: BAM handle is NULL\n";
  }
  else if (param_2 < 0x1f) {
    if (param_3 == (byte *)0x0) {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar2 = ___ratelimit(sps_pipe_pending_desc__rs_229,"sps_pipe_pending_desc"), iVar2 != 0))
         )) {
        _printk(&DAT_00124bbc,"sps_pipe_pending_desc");
      }
      if (sps == 0) {
        return 0xffffffff;
      }
      uVar3 = *(undefined8 *)(sps + 0x110);
      pcVar5 = "%s: sps: input flag is NULL\n";
    }
    else {
      lVar4 = sps_h2bam();
      if (lVar4 != 0) {
        if (((1 < logging_option) && (3 < debug_level_option)) &&
           ((print_limit_option == 0 ||
            (iVar2 = ___ratelimit(sps_pipe_pending_desc__rs_235,"sps_pipe_pending_desc"), iVar2 != 0
            )))) {
          _printk(&DAT_0011e5a6,"sps_pipe_pending_desc",lVar4 + 0x18,param_2);
        }
        if (*(int *)(lVar4 + 0x238) == 0) {
          ipc_log_string(*(undefined8 *)(lVar4 + 0x210),"%s: sps: BAM: %pa; pipe index:%d\n",
                         "sps_pipe_pending_desc",lVar4 + 0x18,param_2);
        }
        bVar1 = sps_bam_pipe_pending_desc(lVar4,param_2);
        *param_3 = bVar1 & 1;
        return 0;
      }
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar2 = ___ratelimit(sps_pipe_pending_desc__rs_232,"sps_pipe_pending_desc"), iVar2 != 0))
         )) {
        _printk(&DAT_0011d314,"sps_pipe_pending_desc");
      }
      if (sps == 0) {
        return 0xffffffff;
      }
      uVar3 = *(undefined8 *)(sps + 0x110);
      pcVar5 = "%s: sps: :BAM is not found by handle\n";
    }
  }
  else {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_pipe_pending_desc__rs_228,"sps_pipe_pending_desc"), iVar2 != 0))))
    {
      _printk(&DAT_0011f9ed,"sps_pipe_pending_desc");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar3 = *(undefined8 *)(sps + 0x110);
    pcVar5 = "%s: sps: pipe index is invalid\n";
  }
  ipc_log_string(uVar3,pcVar5,"sps_pipe_pending_desc");
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_bam_process_irq @ 001142c8 size=420
// signature: undefined sps_bam_process_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 sps_bam_process_irq(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_bam_process_irq__rs,"sps_bam_process_irq"), iVar1 != 0)))) {
      _printk(&DAT_001247fb,"sps_bam_process_irq");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar3 = *(undefined8 *)(sps + 0x110);
    pcVar4 = "%s: sps: BAM handle is NULL\n";
  }
  else {
    lVar2 = sps_h2bam();
    if (lVar2 != 0) {
      if (((1 < logging_option) && (2 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar1 = ___ratelimit(sps_bam_process_irq__rs_237,"sps_bam_process_irq"), iVar1 != 0)))) {
        _printk(&DAT_00122025,"sps_bam_process_irq",lVar2 + 0x18);
      }
      if (*(uint *)(lVar2 + 0x238) < 2) {
        ipc_log_string(*(undefined8 *)(lVar2 + 0x218),"%s: sps: BAM: %pa\n","sps_bam_process_irq",
                       lVar2 + 0x18);
      }
      uVar3 = sps_bam_check_irq(lVar2);
      return uVar3;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_bam_process_irq__rs_236,"sps_bam_process_irq"), iVar1 != 0)))) {
      _printk(&DAT_001207fb,"sps_bam_process_irq");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar3 = *(undefined8 *)(sps + 0x110);
    pcVar4 = "%s: sps: BAM is not found by handle\n";
  }
  ipc_log_string(uVar3,pcVar4,"sps_bam_process_irq");
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_bam_enable_irqs @ 00114470 size=424
// signature: undefined sps_bam_enable_irqs(void)
// callers: []
//------------------------------------------------------------

undefined8 sps_bam_enable_irqs(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_bam_enable_irqs__rs,"sps_bam_enable_irqs"), iVar1 != 0)))) {
      _printk(&DAT_001247fb,"sps_bam_enable_irqs");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar3 = *(undefined8 *)(sps + 0x110);
    pcVar4 = "%s: sps: BAM handle is NULL\n";
  }
  else {
    lVar2 = sps_h2bam();
    if (lVar2 != 0) {
      if (((1 < logging_option) && (2 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar1 = ___ratelimit(sps_bam_enable_irqs__rs_241,"sps_bam_enable_irqs"), iVar1 != 0)))) {
        _printk(&DAT_00122025,"sps_bam_enable_irqs",lVar2 + 0x18);
      }
      if (*(uint *)(lVar2 + 0x238) < 2) {
        ipc_log_string(*(undefined8 *)(lVar2 + 0x218),"%s: sps: BAM: %pa\n","sps_bam_enable_irqs",
                       lVar2 + 0x18);
      }
      sps_bam_enable_all_irqs(lVar2);
      return 0;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_bam_enable_irqs__rs_240,"sps_bam_enable_irqs"), iVar1 != 0)))) {
      _printk(&DAT_001207fb,"sps_bam_enable_irqs");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar3 = *(undefined8 *)(sps + 0x110);
    pcVar4 = "%s: sps: BAM is not found by handle\n";
  }
  ipc_log_string(uVar3,pcVar4,"sps_bam_enable_irqs");
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_bam_disable_irqs @ 0011461c size=424
// signature: undefined sps_bam_disable_irqs(void)
// callers: []
//------------------------------------------------------------

undefined8 sps_bam_disable_irqs(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_bam_disable_irqs__rs,"sps_bam_disable_irqs"), iVar1 != 0)))) {
      _printk(&DAT_001247fb,"sps_bam_disable_irqs");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar3 = *(undefined8 *)(sps + 0x110);
    pcVar4 = "%s: sps: BAM handle is NULL\n";
  }
  else {
    lVar2 = sps_h2bam();
    if (lVar2 != 0) {
      if (((1 < logging_option) && (2 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar1 = ___ratelimit(sps_bam_disable_irqs__rs_243,"sps_bam_disable_irqs"), iVar1 != 0))))
      {
        _printk(&DAT_00122025,"sps_bam_disable_irqs",lVar2 + 0x18);
      }
      if (*(uint *)(lVar2 + 0x238) < 2) {
        ipc_log_string(*(undefined8 *)(lVar2 + 0x218),"%s: sps: BAM: %pa\n","sps_bam_disable_irqs",
                       lVar2 + 0x18);
      }
      sps_bam_disable_all_irqs(lVar2);
      return 0;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_bam_disable_irqs__rs_242,"sps_bam_disable_irqs"), iVar1 != 0)))) {
      _printk(&DAT_001207fb,"sps_bam_disable_irqs");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar3 = *(undefined8 *)(sps + 0x110);
    pcVar4 = "%s: sps: BAM is not found by handle\n";
  }
  ipc_log_string(uVar3,pcVar4,"sps_bam_disable_irqs");
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_get_bam_addr @ 001147c8 size=496
// signature: undefined sps_get_bam_addr(void)
// callers: []
//------------------------------------------------------------

undefined8 sps_get_bam_addr(long param_1,undefined8 *param_2,undefined4 *param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined8 *puVar5;
  undefined4 uVar6;
  
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_get_bam_addr__rs,"sps_get_bam_addr"), iVar1 != 0)))) {
      _printk(&DAT_001247fb,"sps_get_bam_addr");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar3 = *(undefined8 *)(sps + 0x110);
    pcVar4 = "%s: sps: BAM handle is NULL\n";
  }
  else {
    lVar2 = sps_h2bam();
    if (lVar2 != 0) {
      puVar5 = (undefined8 *)(lVar2 + 0x18);
      *param_2 = *puVar5;
      uVar6 = *(undefined4 *)(lVar2 + 0x28);
      *param_3 = uVar6;
      if ((1 < logging_option) && (1 < debug_level_option)) {
        if (print_limit_option != 0) {
          iVar1 = ___ratelimit(sps_get_bam_addr__rs_245,"sps_get_bam_addr");
          if (iVar1 == 0) goto LAB_00114814;
          uVar6 = *param_3;
        }
        _printk(&DAT_0012203a,"sps_get_bam_addr",puVar5,param_2,uVar6);
      }
LAB_00114814:
      if (*(uint *)(lVar2 + 0x238) < 3) {
        ipc_log_string(*(undefined8 *)(lVar2 + 0x220),"%s: sps: BAM: %pa; base:%pa; size:%d\n",
                       "sps_get_bam_addr",puVar5,param_2,*param_3);
      }
      return 0;
    }
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_get_bam_addr__rs_244,"sps_get_bam_addr"), iVar1 != 0)))) {
      _printk(&DAT_001207fb,"sps_get_bam_addr");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    uVar3 = *(undefined8 *)(sps + 0x110);
    pcVar4 = "%s: sps: BAM is not found by handle\n";
  }
  ipc_log_string(uVar3,pcVar4,"sps_get_bam_addr");
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_pipe_inject_zlt @ 001149bc size=676
// signature: undefined sps_pipe_inject_zlt(void)
// callers: []
//------------------------------------------------------------

int sps_pipe_inject_zlt(long param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  undefined8 *puVar5;
  
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_pipe_inject_zlt__rs,"sps_pipe_inject_zlt"), iVar1 != 0)))) {
      _printk(&DAT_001247fb,"sps_pipe_inject_zlt");
    }
    if (sps == 0) {
      return -1;
    }
    puVar5 = (undefined8 *)(sps + 0x110);
    iVar1 = -1;
    pcVar4 = "%s: sps: BAM handle is NULL\n";
  }
  else if (param_2 < 0x1f) {
    lVar3 = sps_h2bam();
    if (lVar3 == 0) {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar1 = ___ratelimit(sps_pipe_inject_zlt__rs_249,"sps_pipe_inject_zlt"), iVar1 != 0)))) {
        _printk(&DAT_001207fb,"sps_pipe_inject_zlt");
      }
      if (sps == 0) {
        return -1;
      }
      puVar5 = (undefined8 *)(sps + 0x110);
      iVar1 = -1;
      pcVar4 = "%s: sps: BAM is not found by handle\n";
    }
    else {
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar1 = ___ratelimit(sps_pipe_inject_zlt__rs_250,"sps_pipe_inject_zlt"), iVar1 != 0)))) {
        _printk(&DAT_0011e5a6,"sps_pipe_inject_zlt",lVar3 + 0x18,param_2);
      }
      if (*(int *)(lVar3 + 0x238) == 0) {
        ipc_log_string(*(undefined8 *)(lVar3 + 0x210),"%s: sps: BAM: %pa; pipe index:%d\n",
                       "sps_pipe_inject_zlt",lVar3 + 0x18,param_2);
      }
      iVar1 = sps_bam_pipe_inject_zlt(lVar3,param_2);
      if (iVar1 == 0) {
        return 0;
      }
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar2 = ___ratelimit(sps_pipe_inject_zlt__rs_251,"sps_pipe_inject_zlt"), iVar2 != 0)))) {
        _printk(&DAT_0012335f,"sps_pipe_inject_zlt");
      }
      puVar5 = (undefined8 *)(lVar3 + 0x228);
      pcVar4 = "%s: sps: failed to inject a ZLT\n";
    }
  }
  else {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_pipe_inject_zlt__rs_248,"sps_pipe_inject_zlt"), iVar1 != 0)))) {
      _printk(&DAT_0011f9ed,"sps_pipe_inject_zlt");
    }
    if (sps == 0) {
      return -1;
    }
    puVar5 = (undefined8 *)(sps + 0x110);
    iVar1 = -1;
    pcVar4 = "%s: sps: pipe index is invalid\n";
  }
  ipc_log_string(*puVar5,pcVar4,"sps_pipe_inject_zlt");
  return iVar1;
}



//------------------------------------------------------------
// sps_alloc_endpoint @ 00114c64 size=376
// signature: undefined sps_alloc_endpoint(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * sps_alloc_endpoint(void)

{
  int iVar1;
  void *__s;
  
  if (((1 < logging_option) && (3 < debug_level_option)) &&
     ((print_limit_option == '\0' ||
      (iVar1 = ___ratelimit(sps_alloc_endpoint__rs,"sps_alloc_endpoint"), iVar1 != 0)))) {
    _printk(&DAT_00121fe7,"sps_alloc_endpoint");
  }
  if ((sps != 0) && (*(int *)(sps + 0x120) == 0)) {
    ipc_log_string(*(undefined8 *)(sps + 0xf8),"%s: sps: Enter\n","sps_alloc_endpoint");
  }
  __s = (void *)kmalloc_trace(_debugfs_create_file,0xdc0,0x288);
  if (__s != (void *)0x0) {
    if (((1 < logging_option) && (3 < debug_level_option)) &&
       ((print_limit_option == '\0' ||
        (iVar1 = ___ratelimit(sps_client_init__rs,"sps_client_init"), iVar1 != 0)))) {
      _printk(&DAT_0011f4ab,"sps_client_init");
    }
    if ((sps != 0) && (*(int *)(sps + 0x120) == 0)) {
      ipc_log_string(*(undefined8 *)(sps + 0xf8),"%s: Enter\n","sps_client_init");
    }
    memset(__s,0,0x288);
    sps_rm_config_init((long)__s + 0x20);
    *(undefined4 *)((long)__s + 0x10) = 0;
    *(undefined8 *)((long)__s + 0x18) = 0;
  }
  return __s;
}



//------------------------------------------------------------
// sps_free_endpoint @ 00114de0 size=628
// signature: undefined sps_free_endpoint(void)
// callers: []
//------------------------------------------------------------

undefined8 sps_free_endpoint(long param_1)

{
  int iVar1;
  
  if (((1 < logging_option) && (3 < debug_level_option)) &&
     ((print_limit_option == 0 ||
      (iVar1 = ___ratelimit(sps_free_endpoint__rs,"sps_free_endpoint"), iVar1 != 0)))) {
    _printk(&DAT_00121fe7,"sps_free_endpoint");
  }
  if ((sps != 0) && (*(int *)(sps + 0x120) == 0)) {
    ipc_log_string(*(undefined8 *)(sps + 0xf8),"%s: sps: Enter\n","sps_free_endpoint");
  }
  if (param_1 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_free_endpoint__rs_254,"sps_free_endpoint"), iVar1 != 0)))) {
      _printk(&DAT_0011e9ed,"sps_free_endpoint");
    }
    if (sps == 0) {
      return 0xffffffff;
    }
    ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps: pipe is NULL\n","sps_free_endpoint");
    return 0xffffffff;
  }
  if (((1 < logging_option) && (3 < debug_level_option)) &&
     ((print_limit_option == 0 ||
      (iVar1 = ___ratelimit(sps_client_de_init__rs,"sps_client_de_init"), iVar1 != 0)))) {
    _printk(&DAT_0011f4ab,"sps_client_de_init");
  }
  if ((sps == 0) || (*(int *)(sps + 0x120) != 0)) {
    iVar1 = *(int *)(param_1 + 0x10);
  }
  else {
    ipc_log_string(*(undefined8 *)(sps + 0xf8),"%s: Enter\n","sps_client_de_init");
    iVar1 = *(int *)(param_1 + 0x10);
  }
  if (iVar1 == 0) {
    *(undefined8 *)(param_1 + 0x18) = 0;
    *(undefined8 *)(param_1 + 0x20) = 0;
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(undefined8 *)(param_1 + 0x30) = 0;
    *(undefined8 *)(param_1 + 0x38) = 0;
    *(undefined8 *)(param_1 + 0x40) = 0;
    *(undefined8 *)(param_1 + 0x48) = 0;
    *(undefined8 *)(param_1 + 0x50) = 0;
    *(undefined8 *)(param_1 + 0x58) = 0;
    *(undefined8 *)(param_1 + 0x60) = 0;
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined8 *)(param_1 + 0x78) = 0;
    *(undefined8 *)(param_1 + 0x80) = 0;
    *(undefined8 *)(param_1 + 0x88) = 0;
    *(undefined8 *)(param_1 + 0x90) = 0;
    *(undefined8 *)(param_1 + 0x98) = 0;
    *(undefined8 *)(param_1 + 0xa0) = 0;
    *(undefined8 *)(param_1 + 0xa8) = 0;
    *(undefined8 *)(param_1 + 0xb0) = 0;
    kfree(param_1);
    return 0;
  }
  if (logging_option != 1) {
    if (2 < print_limit_option) {
      iVar1 = ___ratelimit(sps_client_de_init__rs_279,"sps_client_de_init");
      if (iVar1 == 0) goto LAB_00114e74;
      iVar1 = *(int *)(param_1 + 0x10);
    }
    _printk(&DAT_001233ca,"sps_client_de_init",iVar1);
  }
LAB_00114e74:
  if (sps != 0) {
    ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps:De-init client in connected state: 0x%x\n",
                   "sps_client_de_init",*(undefined4 *)(param_1 + 0x10));
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_read_info @ 00115058 size=168
// signature: undefined sps_read_info(void)
// callers: []
//------------------------------------------------------------

long sps_read_info(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  
  mutex_lock(&sps_debugfs_lock);
  if (debugfs_record_enabled == '\0') {
    lVar2 = 0;
  }
  else {
    iVar1 = debugfs_buf_size + -0x50;
    if (wraparound == '\0') {
      iVar1 = debugfs_buf_used;
    }
    iVar1 = simple_read_from_buffer(param_2,param_3,param_4,debugfs_buf,(long)iVar1);
    lVar2 = (long)iVar1;
  }
  mutex_unlock(&sps_debugfs_lock);
  return lVar2;
}



//------------------------------------------------------------
// sps_set_info @ 00115104 size=696
// signature: undefined sps_set_info(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong sps_set_info(undefined8 param_1,ulong param_2,ulong param_3)

{
  byte *pbVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  undefined *puVar5;
  undefined8 *puVar6;
  long lVar7;
  ulong uVar8;
  uint uVar9;
  byte local_a8 [80];
  long local_58;
  
  lVar7 = sp_el0;
  local_58 = *(long *)(lVar7 + 0x638);
  uVar4 = param_3;
  if (0x4f < param_3) {
    uVar4 = 0x50;
  }
  local_a8[0x40] = 0;
  local_a8[0x41] = 0;
  local_a8[0x42] = 0;
  local_a8[0x43] = 0;
  local_a8[0x44] = 0;
  local_a8[0x45] = 0;
  local_a8[0x46] = 0;
  local_a8[0x47] = 0;
  local_a8[0x48] = 0;
  local_a8[0x49] = 0;
  local_a8[0x4a] = 0;
  local_a8[0x4b] = 0;
  local_a8[0x4c] = 0;
  local_a8[0x4d] = 0;
  local_a8[0x4e] = 0;
  local_a8[0x4f] = 0;
  local_a8[0x30] = 0;
  local_a8[0x31] = 0;
  local_a8[0x32] = 0;
  local_a8[0x33] = 0;
  local_a8[0x34] = 0;
  local_a8[0x35] = 0;
  local_a8[0x36] = 0;
  local_a8[0x37] = 0;
  local_a8[0x38] = 0;
  local_a8[0x39] = 0;
  local_a8[0x3a] = 0;
  local_a8[0x3b] = 0;
  local_a8[0x3c] = 0;
  local_a8[0x3d] = 0;
  local_a8[0x3e] = 0;
  local_a8[0x3f] = 0;
  local_a8[0x20] = 0;
  local_a8[0x21] = 0;
  local_a8[0x22] = 0;
  local_a8[0x23] = 0;
  local_a8[0x24] = 0;
  local_a8[0x25] = 0;
  local_a8[0x26] = 0;
  local_a8[0x27] = 0;
  local_a8[0x28] = 0;
  local_a8[0x29] = 0;
  local_a8[0x2a] = 0;
  local_a8[0x2b] = 0;
  local_a8[0x2c] = 0;
  local_a8[0x2d] = 0;
  local_a8[0x2e] = 0;
  local_a8[0x2f] = 0;
  local_a8[0x10] = 0;
  local_a8[0x11] = 0;
  local_a8[0x12] = 0;
  local_a8[0x13] = 0;
  local_a8[0x14] = 0;
  local_a8[0x15] = 0;
  local_a8[0x16] = 0;
  local_a8[0x17] = 0;
  local_a8[0x18] = 0;
  local_a8[0x19] = 0;
  local_a8[0x1a] = 0;
  local_a8[0x1b] = 0;
  local_a8[0x1c] = 0;
  local_a8[0x1d] = 0;
  local_a8[0x1e] = 0;
  local_a8[0x1f] = 0;
  local_a8[0] = 0;
  local_a8[1] = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  local_a8[6] = 0;
  local_a8[7] = 0;
  local_a8[8] = 0;
  local_a8[9] = 0;
  local_a8[10] = 0;
  local_a8[0xb] = 0;
  local_a8[0xc] = 0;
  local_a8[0xd] = 0;
  local_a8[0xe] = 0;
  local_a8[0xf] = 0;
  __check_object_size(local_a8,uVar4,0);
  puVar6 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
     (uVar8 = param_2, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
    uVar8 = param_2 & (long)(param_2 << 8) >> 8;
  }
  if (uVar8 <= 0x8000000000 - uVar4) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar8 = daif;
      if ((uVar8 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      puVar6 = (undefined8 *)puVar6[1];
      uVar3 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar6;
      InstructionSynchronizationBarrier();
      daif = uVar8;
    }
    uVar4 = __arch_copy_from_user(puVar6,local_a8,param_2 & 0xff7fffffffffffff,uVar4);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar8 = daif;
      if ((uVar8 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar8;
    }
  }
  if (uVar4 == 0) {
    lVar7 = 0;
    uVar9 = 0;
    do {
      pbVar1 = local_a8 + lVar7;
      if (9 < *pbVar1 - 0x30) break;
      lVar7 = lVar7 + 1;
      uVar9 = ((uint)*pbVar1 + uVar9 * 10) - 0x30;
    } while (lVar7 != 0x50);
    _printk(&DAT_00123b10,uVar9);
    if ((logging_option & 0xfd) == 0) {
      puVar5 = &DAT_0011eab1;
    }
    else if (uVar9 == 0) {
      puVar5 = &DAT_001228c8;
    }
    else {
      if (uVar9 < 0x200000) {
        iVar2 = uVar9 << 10;
        mutex_lock(&sps_debugfs_lock);
        if (debugfs_record_enabled == '\0') {
LAB_001152e0:
          debugfs_buf_size = iVar2;
          debugfs_buf = __kmalloc(iVar2,0xdc0);
          if (debugfs_buf == 0) {
            debugfs_buf_size = 0;
            mutex_unlock(&sps_debugfs_lock);
            param_3 = 0xfffffffffffffff4;
            goto LAB_00115358;
          }
          debugfs_buf_used = 0;
          wraparound = 0;
          debugfs_record_enabled = '\x01';
        }
        else {
          if (debugfs_buf_size != iVar2) {
            debugfs_record_enabled = '\0';
            debugfs_buf_used = 0;
            wraparound = 0;
            kfree(debugfs_buf);
            debugfs_buf = 0;
            goto LAB_001152e0;
          }
          _printk(&DAT_00122b70);
        }
        mutex_unlock(&sps_debugfs_lock);
        goto LAB_00115358;
      }
      puVar5 = &DAT_001228fe;
    }
    _printk(puVar5);
  }
  param_3 = 0xfffffffffffffff2;
LAB_00115358:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// sps_read_logging_option @ 001153d8 size=168
// signature: undefined sps_read_logging_option(void)
// callers: []
//------------------------------------------------------------

void sps_read_logging_option
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
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
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  iVar2 = scnprintf(&local_88,0x50,&DAT_0011f500,logging_option);
  simple_read_from_buffer(param_2,param_3,param_4,&local_88,(long)iVar2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// sps_set_logging_option @ 00115484 size=284
// signature: undefined sps_set_logging_option(void)
// callers: []
//------------------------------------------------------------

long sps_set_logging_option(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  iVar2 = kstrtouint_from_user(param_2,param_3,10,&local_3c);
  if (iVar2 == 0) {
    _printk(&DAT_0011d373,local_3c);
    if (local_3c < 4) {
      mutex_lock(&sps_debugfs_lock);
      if (((local_3c & 0xfffffffd) == 0) && ((logging_option & 0xfd) == 1)) {
        debugfs_record_enabled = 0;
        kfree(debugfs_buf);
        debugfs_buf = 0;
        debugfs_buf_used = 0;
        debugfs_buf_size = 0;
        wraparound = 0;
      }
      logging_option = (byte)local_3c;
      mutex_unlock(&sps_debugfs_lock);
    }
    else {
      _printk(&DAT_0011ef45);
    }
  }
  else {
    param_3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// sps_set_bam_addr @ 001155a4 size=2404
// signature: undefined sps_set_bam_addr(void)
// callers: []
//------------------------------------------------------------

ulong sps_set_bam_addr(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  undefined8 *puVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  ulong uVar8;
  long *plVar9;
  uint local_4c;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_4c = 0;
  uVar3 = kstrtouint_from_user(param_2,param_3,10,&local_4c);
  if (uVar3 != 0) {
    param_3 = (ulong)uVar3;
    goto LAB_001155f0;
  }
  _printk(&DAT_001210d1,local_4c);
  uVar6 = (ulong)local_4c;
  if (((1 < logging_option) && (1 < debug_level_option)) &&
     ((print_limit_option == '\0' || (iVar4 = ___ratelimit(phy2bam__rs,"phy2bam"), iVar4 != 0)))) {
    _printk(&DAT_0011f4ab,"phy2bam");
  }
  if ((sps != 0) && (*(uint *)(sps + 0x120) < 3)) {
    ipc_log_string(*(undefined8 *)(sps + 0x108),"%s: Enter\n","phy2bam");
  }
  plVar9 = (long *)(sps + 0xa0);
  do {
    plVar9 = (long *)*plVar9;
    if (plVar9 == (long *)(sps + 0xa0)) goto LAB_00115714;
  } while (plVar9[3] != uVar6);
  if (plVar9 == (long *)0x0) {
LAB_00115714:
    _printk(&DAT_001248a0,local_4c);
    goto LAB_001155f0;
  }
  if (log_level_sel < 5) {
    *(uint *)(plVar9 + 0x47) = log_level_sel;
  }
  if (0x62 < reg_dump_option - 1) {
switchD_001156e4_caseD_11:
    _printk(&DAT_0011fa5f);
    goto LAB_001155f0;
  }
  uVar3 = *(uint *)(plVar9 + 6);
  uVar6 = (ulong)uVar3;
  puVar1 = plVar9 + 0x1b;
  switch((uint)reg_dump_option) {
  case 1:
    print_bam_reg(*puVar1);
    if (uVar3 != 0) {
      uVar7 = 0;
      do {
        print_bam_pipe_reg(*puVar1,uVar7);
        uVar7 = uVar7 + 1;
      } while (uVar3 != uVar7);
    }
    break;
  case 2:
    print_bam_reg(*puVar1);
    break;
  case 4:
    if (uVar3 != 0) {
      uVar7 = 0;
      do {
        print_bam_pipe_selected_reg(puVar1,uVar7);
        uVar7 = uVar7 + 1;
      } while (uVar3 != uVar7);
    }
    break;
  case 5:
    if (uVar3 != 0) {
      uVar8 = 0;
      uVar5 = (ulong)bam_pipe_sel;
      do {
        if ((uVar5 >> (uVar8 & 0x3f) & 1) != 0) {
          print_bam_pipe_selected_reg(puVar1,uVar8 & 0xffffffff);
          uVar5 = (ulong)bam_pipe_sel;
        }
        uVar8 = uVar8 + 1;
      } while (uVar6 != uVar8);
    }
    break;
  case 6:
    print_bam_pipe_selected_reg(puVar1,4);
    print_bam_pipe_selected_reg(puVar1,5);
    break;
  case 7:
    if (uVar3 != 0) {
      uVar7 = 0;
      do {
        print_bam_pipe_desc_fifo(puVar1,uVar7,0);
        uVar7 = uVar7 + 1;
      } while (uVar3 != uVar7);
    }
    break;
  case 8:
    if (uVar3 != 0) {
      uVar8 = 0;
      uVar5 = (ulong)bam_pipe_sel;
      do {
        if ((uVar5 >> (uVar8 & 0x3f) & 1) != 0) {
          print_bam_pipe_desc_fifo(puVar1,uVar8 & 0xffffffff,0);
          uVar5 = (ulong)bam_pipe_sel;
        }
        uVar8 = uVar8 + 1;
      } while (uVar6 != uVar8);
    }
    break;
  case 9:
    print_bam_pipe_desc_fifo(puVar1,4,0);
    goto LAB_00115af0;
  case 10:
    if (uVar3 != 0) {
      uVar7 = 0;
      do {
        print_bam_pipe_selected_reg(puVar1,uVar7);
        print_bam_pipe_desc_fifo(puVar1,uVar7,0);
        uVar7 = uVar7 + 1;
      } while (uVar3 != uVar7);
    }
    break;
  case 0xb:
    if (uVar3 != 0) {
      uVar8 = 0;
      uVar5 = (ulong)bam_pipe_sel;
      do {
        if ((uVar5 >> (uVar8 & 0x3f) & 1) != 0) {
          print_bam_pipe_selected_reg(puVar1,uVar8 & 0xffffffff);
          print_bam_pipe_desc_fifo(puVar1,uVar8 & 0xffffffff,0);
          uVar5 = (ulong)bam_pipe_sel;
        }
        uVar8 = uVar8 + 1;
      } while (uVar6 != uVar8);
    }
    break;
  case 0xc:
    print_bam_pipe_selected_reg(puVar1,4);
    print_bam_pipe_desc_fifo(puVar1,4,0);
    print_bam_pipe_selected_reg(puVar1,5);
LAB_00115af0:
    print_bam_pipe_desc_fifo(puVar1,5,0);
    break;
  case 0xd:
    if (testbus_sel == 0) {
      _printk(&DAT_00124bee);
    }
    print_bam_test_bus_reg(puVar1,testbus_sel);
    break;
  case 0xe:
    if (desc_option == 0) {
      desc_option = 1;
    }
    if (uVar3 != 0) {
      uVar8 = 0;
      uVar5 = (ulong)bam_pipe_sel;
      do {
        if ((uVar5 >> (uVar8 & 0x3f) & 1) != 0) {
          print_bam_pipe_desc_fifo(puVar1,uVar8 & 0xffffffff,desc_option);
          uVar5 = (ulong)bam_pipe_sel;
        }
        uVar8 = uVar8 + 1;
      } while (uVar6 != uVar8);
    }
    break;
  case 0xf:
    if (uVar3 != 0) {
      uVar8 = 0;
      uVar5 = (ulong)bam_pipe_sel;
      do {
        if ((uVar5 >> (uVar8 & 0x3f) & 1) != 0) {
          print_bam_pipe_desc_fifo(puVar1,uVar8 & 0xffffffff,100);
          uVar5 = (ulong)bam_pipe_sel;
        }
        uVar8 = uVar8 + 1;
      } while (uVar6 != uVar8);
    }
    break;
  case 0x10:
    if (uVar3 != 0) {
      uVar8 = 0;
      uVar5 = (ulong)bam_pipe_sel;
      do {
        if ((uVar5 >> (uVar8 & 0x3f) & 1) != 0) {
          print_bam_pipe_reg(*puVar1,uVar8 & 0xffffffff);
          uVar5 = (ulong)bam_pipe_sel;
        }
        uVar8 = uVar8 + 1;
      } while (uVar6 != uVar8);
    }
    break;
  default:
    goto switchD_001156e4_caseD_11;
  case 0x5b:
    print_bam_test_bus_reg(puVar1,testbus_sel);
    print_bam_selected_reg(puVar1,*(undefined4 *)(plVar9 + 0x10));
    if (uVar3 != 0) {
      uVar7 = 0;
      do {
        print_bam_pipe_selected_reg(puVar1,uVar7);
        uVar7 = uVar7 + 1;
      } while (uVar3 != uVar7);
    }
    break;
  case 0x5c:
    print_bam_test_bus_reg(puVar1,testbus_sel);
    print_bam_selected_reg(puVar1,*(undefined4 *)(plVar9 + 0x10));
    if (uVar3 != 0) {
      uVar8 = 0;
      uVar5 = (ulong)bam_pipe_sel;
      do {
        if ((uVar5 >> (uVar8 & 0x3f) & 1) != 0) {
          print_bam_pipe_selected_reg(puVar1,uVar8 & 0xffffffff);
          uVar5 = (ulong)bam_pipe_sel;
        }
        uVar8 = uVar8 + 1;
      } while (uVar6 != uVar8);
    }
    break;
  case 0x5d:
    if (desc_option == 0) {
      desc_option = 1;
    }
    print_bam_test_bus_reg(puVar1,testbus_sel);
    print_bam_selected_reg(puVar1,*(undefined4 *)(plVar9 + 0x10));
    if (uVar3 != 0) {
      uVar8 = 0;
      uVar5 = (ulong)bam_pipe_sel;
      do {
        if ((uVar5 >> (uVar8 & 0x3f) & 1) != 0) {
          print_bam_pipe_selected_reg(puVar1,uVar8 & 0xffffffff);
          uVar5 = (ulong)bam_pipe_sel;
        }
        uVar8 = uVar8 + 1;
      } while (uVar6 != uVar8);
      if (uVar3 != 0) {
        uVar8 = 0;
        uVar5 = (ulong)bam_pipe_sel;
        do {
          if ((uVar5 >> (uVar8 & 0x3f) & 1) != 0) {
            print_bam_pipe_desc_fifo(puVar1,uVar8 & 0xffffffff,desc_option);
            uVar5 = (ulong)bam_pipe_sel;
          }
          uVar8 = uVar8 + 1;
        } while (uVar6 != uVar8);
      }
    }
    break;
  case 0x5e:
    if (desc_option == 0) {
      desc_option = 1;
    }
    print_bam_test_bus_reg(puVar1,testbus_sel);
    print_bam_selected_reg(puVar1,*(undefined4 *)(plVar9 + 0x10));
    if (uVar3 != 0) {
      uVar8 = 0;
      uVar5 = (ulong)bam_pipe_sel;
      do {
        if ((uVar5 >> (uVar8 & 0x3f) & 1) != 0) {
          print_bam_pipe_selected_reg(puVar1,uVar8 & 0xffffffff);
          print_bam_pipe_desc_fifo(puVar1,uVar8 & 0xffffffff,desc_option);
          uVar5 = (ulong)bam_pipe_sel;
        }
        uVar8 = uVar8 + 1;
      } while (uVar6 != uVar8);
    }
    break;
  case 0x5f:
    print_bam_test_bus_reg(puVar1,testbus_sel);
    print_bam_selected_reg(puVar1,*(undefined4 *)(plVar9 + 0x10));
    if (uVar3 != 0) {
      uVar8 = 0;
      uVar5 = (ulong)bam_pipe_sel;
      do {
        if ((uVar5 >> (uVar8 & 0x3f) & 1) != 0) {
          print_bam_pipe_selected_reg(puVar1,uVar8 & 0xffffffff);
          uVar5 = (ulong)bam_pipe_sel;
        }
        uVar8 = uVar8 + 1;
      } while (uVar6 != uVar8);
      if (uVar3 != 0) {
        uVar8 = 0;
        uVar5 = (ulong)bam_pipe_sel;
        do {
          if ((uVar5 >> (uVar8 & 0x3f) & 1) != 0) {
            print_bam_pipe_desc_fifo(puVar1,uVar8 & 0xffffffff,0);
            uVar5 = (ulong)bam_pipe_sel;
          }
          uVar8 = uVar8 + 1;
        } while (uVar6 != uVar8);
      }
    }
    break;
  case 0x60:
    print_bam_test_bus_reg(puVar1,testbus_sel);
    print_bam_selected_reg(puVar1,*(undefined4 *)(plVar9 + 0x10));
    if (uVar3 != 0) {
      uVar8 = 0;
      uVar5 = (ulong)bam_pipe_sel;
      do {
        if ((uVar5 >> (uVar8 & 0x3f) & 1) != 0) {
          print_bam_pipe_selected_reg(puVar1,uVar8 & 0xffffffff);
          print_bam_pipe_desc_fifo(puVar1,uVar8 & 0xffffffff,0);
          uVar5 = (ulong)bam_pipe_sel;
        }
        uVar8 = uVar8 + 1;
      } while (uVar6 != uVar8);
    }
    break;
  case 0x61:
    print_bam_test_bus_reg(puVar1,testbus_sel);
    print_bam_selected_reg(puVar1,*(undefined4 *)(plVar9 + 0x10));
    if (uVar3 != 0) {
      uVar8 = 0;
      uVar5 = (ulong)bam_pipe_sel;
      do {
        if ((uVar5 >> (uVar8 & 0x3f) & 1) != 0) {
          print_bam_pipe_selected_reg(puVar1,uVar8 & 0xffffffff);
          uVar5 = (ulong)bam_pipe_sel;
        }
        uVar8 = uVar8 + 1;
      } while (uVar6 != uVar8);
      if (uVar3 != 0) {
        uVar8 = 0;
        uVar5 = (ulong)bam_pipe_sel;
        do {
          if ((uVar5 >> (uVar8 & 0x3f) & 1) != 0) {
            print_bam_pipe_desc_fifo(puVar1,uVar8 & 0xffffffff,0);
            uVar5 = (ulong)bam_pipe_sel;
          }
          uVar8 = uVar8 + 1;
        } while (uVar6 != uVar8);
        if (uVar3 != 0) {
          uVar8 = 0;
          uVar5 = (ulong)bam_pipe_sel;
          do {
            if ((uVar5 >> (uVar8 & 0x3f) & 1) != 0) {
              print_bam_pipe_desc_fifo(puVar1,uVar8 & 0xffffffff,100);
              uVar5 = (ulong)bam_pipe_sel;
            }
            uVar8 = uVar8 + 1;
          } while (uVar6 != uVar8);
        }
      }
    }
    break;
  case 0x62:
    print_bam_test_bus_reg(puVar1,testbus_sel);
    print_bam_selected_reg(puVar1,*(undefined4 *)(plVar9 + 0x10));
    if (uVar3 != 0) {
      uVar8 = 0;
      uVar5 = (ulong)bam_pipe_sel;
      do {
        if ((uVar5 >> (uVar8 & 0x3f) & 1) != 0) {
          print_bam_pipe_selected_reg(puVar1,uVar8 & 0xffffffff);
          print_bam_pipe_desc_fifo(puVar1,uVar8 & 0xffffffff,0);
          print_bam_pipe_desc_fifo(puVar1,uVar8 & 0xffffffff,100);
          uVar5 = (ulong)bam_pipe_sel;
        }
        uVar8 = uVar8 + 1;
      } while (uVar6 != uVar8);
    }
    break;
  case 99:
    print_bam_test_bus_reg(puVar1,testbus_sel);
    print_bam_reg(*puVar1);
    if (uVar3 != 0) {
      uVar7 = 0;
      do {
        print_bam_pipe_reg(*puVar1,uVar7);
        uVar7 = uVar7 + 1;
      } while (uVar3 != uVar7);
      print_bam_selected_reg(puVar1,*(undefined4 *)(plVar9 + 0x10));
      if (uVar3 != 0) {
        uVar7 = 0;
        do {
          print_bam_pipe_selected_reg(puVar1,uVar7);
          uVar7 = uVar7 + 1;
        } while (uVar3 != uVar7);
        if (uVar3 != 0) {
          uVar7 = 0;
          do {
            print_bam_pipe_desc_fifo(puVar1,uVar7,0);
            uVar7 = uVar7 + 1;
          } while (uVar3 != uVar7);
          if (uVar3 != 0) {
            uVar7 = 0;
            do {
              print_bam_pipe_desc_fifo(puVar1,uVar7,100);
              uVar7 = uVar7 + 1;
            } while (uVar3 != uVar7);
          }
        }
      }
      break;
    }
  case 3:
    print_bam_selected_reg(puVar1,*(undefined4 *)(plVar9 + 0x10));
  }
LAB_001155f0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// msm_sps_probe @ 00115f0c size=3872
// signature: undefined msm_sps_probe(void)
// callers: []
//------------------------------------------------------------

int msm_sps_probe(long param_1)

{
  undefined8 *puVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  char *pcVar10;
  undefined4 uVar11;
  undefined *puVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  
  if (((1 < logging_option) && (debug_level_option != 0)) &&
     ((print_limit_option == 0 ||
      (iVar4 = ___ratelimit(msm_sps_probe__rs,"msm_sps_probe"), iVar4 != 0)))) {
    _printk(&DAT_00121fe7,"msm_sps_probe");
  }
  if ((sps != (undefined8 *)0x0) && (*(uint *)(sps + 0x24) < 4)) {
    ipc_log_string(sps[0x22],"%s: sps: Enter\n","msm_sps_probe");
  }
  if (*(long *)(param_1 + 0x2f8) == 0) {
    d_type = 0;
    if (((1 < logging_option) && (debug_level_option != 0)) &&
       ((print_limit_option == 0 ||
        (iVar4 = ___ratelimit(get_platform_data__rs,"get_platform_data"), iVar4 != 0)))) {
      _printk(&DAT_00121fe7,"get_platform_data");
    }
    if ((sps != (undefined8 *)0x0) && (*(uint *)(sps + 0x24) < 4)) {
      ipc_log_string(sps[0x22],"%s: sps: Enter\n","get_platform_data");
    }
    puVar14 = sps;
    if (*(undefined4 **)(param_1 + 0xa0) == (undefined4 *)0x0) {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar4 = ___ratelimit(get_platform_data__rs_367,"get_platform_data"), iVar4 != 0)))) {
        _printk(&DAT_001208ae,"get_platform_data");
      }
      if (sps != (undefined8 *)0x0) {
        ipc_log_string(sps[0x22],"%s: sps: invalid platform data\n","get_platform_data");
      }
      bVar2 = logging_option;
      *(undefined4 *)(sps + 0xd) = 0;
      if ((bVar2 != 1) &&
         ((print_limit_option < 3 ||
          (iVar4 = ___ratelimit(msm_sps_probe__rs_332,"msm_sps_probe"), iVar4 != 0)))) {
        _printk(&DAT_0011d3a6,"msm_sps_probe");
      }
      if (sps == (undefined8 *)0x0) {
        return -0x13;
      }
      ipc_log_string(sps[0x22],"%s: sps: :Fail to get platform data\n","msm_sps_probe");
      return -0x13;
    }
    uVar11 = **(undefined4 **)(param_1 + 0xa0);
    bVar3 = 1 < logging_option;
    *(undefined4 *)(sps + 0xd) = uVar11;
    if ((bVar3) && (puVar14 = sps, debug_level_option != 0)) {
      if (print_limit_option != 0) {
        iVar4 = ___ratelimit(get_platform_data__rs_370,"get_platform_data");
        puVar14 = sps;
        if (iVar4 == 0) goto joined_r0x00116a3c;
        uVar11 = *(undefined4 *)(sps + 0xd);
      }
      _printk(&DAT_001259fa,"get_platform_data",uVar11);
      puVar14 = sps;
    }
joined_r0x00116a3c:
    if ((puVar14 != (undefined8 *)0x0) && (*(uint *)(puVar14 + 0x24) < 4)) {
      ipc_log_string(puVar14[0x22],"%s: sps:bamdma_restricted_pipes=0x%x\n","get_platform_data",
                     *(undefined4 *)(puVar14 + 0xd));
    }
    piVar6 = (int *)platform_get_resource_byname(param_1,0x200,"pipe_mem");
    puVar14 = sps;
    if (piVar6 != (int *)0x0) {
      puVar13 = sps + 7;
      *puVar13 = *(undefined8 *)piVar6;
      iVar4 = (piVar6[2] - *piVar6) + 1;
      bVar3 = 1 < logging_option;
      *(int *)(puVar14 + 8) = iVar4;
      if ((bVar3) && (debug_level_option != 0)) {
        if (print_limit_option != 0) {
          iVar4 = ___ratelimit(get_platform_data__rs_374,"get_platform_data");
          if (iVar4 == 0) goto LAB_0011608c;
          puVar13 = sps + 7;
          iVar4 = *(int *)(sps + 8);
        }
        _printk(&DAT_001224b3,"get_platform_data",puVar13,iVar4);
      }
LAB_0011608c:
      if ((sps != (undefined8 *)0x0) && (*(uint *)(sps + 0x24) < 4)) {
        ipc_log_string(sps[0x22],"%s: sps:pipemem.base=%pa,size=0x%x\n","get_platform_data",sps + 7,
                       *(undefined4 *)(sps + 8));
      }
    }
    if (((1 < logging_option) && (3 < debug_level_option)) &&
       ((print_limit_option == 0 ||
        (iVar4 = ___ratelimit(msm_sps_probe__rs_335,"msm_sps_probe"), iVar4 != 0)))) {
      _printk(&DAT_0012561d,"msm_sps_probe","sps:get platform data\n");
    }
    if ((sps != (undefined8 *)0x0) && (*(int *)(sps + 0x24) == 0)) {
      ipc_log_string(sps[0x1f],"%s: %s","msm_sps_probe","sps:get platform data\n");
    }
    bam_type = 0;
  }
  else {
    iVar4 = of_property_read_variable_u32_array
                      (*(long *)(param_1 + 0x2f8),"qcom,device-type",&d_type,1,0);
    if (iVar4 < 0) {
      d_type = 3;
      if (((1 < logging_option) && (debug_level_option != 0)) &&
         ((print_limit_option == 0 ||
          (iVar4 = ___ratelimit(get_device_tree_data__rs,"get_device_tree_data"), iVar4 != 0)))) {
        _printk(&DAT_0012190f,"get_device_tree_data",d_type);
      }
      if ((sps != (undefined8 *)0x0) && (*(uint *)(sps + 0x24) < 4)) {
        pcVar10 = "%s: sps:default device type %d\n";
        goto LAB_0011613c;
      }
    }
    else {
      if (((1 < logging_option) && (debug_level_option != 0)) &&
         ((print_limit_option == 0 ||
          (iVar4 = ___ratelimit(get_device_tree_data__rs_358,"get_device_tree_data"), iVar4 != 0))))
      {
        _printk(&DAT_00122927,"get_device_tree_data",d_type);
      }
      if ((sps != (undefined8 *)0x0) && (*(uint *)(sps + 0x24) < 4)) {
        pcVar10 = "%s: sps:device type is %d\n";
LAB_0011613c:
        ipc_log_string(sps[0x22],pcVar10,"get_device_tree_data",d_type);
      }
    }
    lVar7 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,pipe-attr-ee",0);
    enhd_pipe = lVar7 != 0;
    if ((1 < logging_option) && (debug_level_option != 0)) {
      if (print_limit_option == 0) {
        puVar12 = &DAT_0012037f;
        if (lVar7 == 0) {
          puVar12 = &DAT_001213a8;
        }
      }
      else {
        iVar4 = ___ratelimit(get_device_tree_data__rs_362,"get_device_tree_data");
        if (iVar4 == 0) goto LAB_00116184;
        puVar12 = &DAT_001213a8;
        if (enhd_pipe != '\0') {
          puVar12 = &DAT_0012037f;
        }
      }
      _printk(&DAT_0011fff6,"get_device_tree_data",puVar12);
    }
LAB_00116184:
    if ((sps != (undefined8 *)0x0) && (*(uint *)(sps + 0x24) < 4)) {
      puVar12 = &DAT_001213a8;
      if (enhd_pipe != '\0') {
        puVar12 = &DAT_0012037f;
      }
      ipc_log_string(sps[0x22],"%s: sps:PIPE_ATTR_EE is %s supported\n","get_device_tree_data",
                     puVar12);
    }
    if (((1 < logging_option) && (3 < debug_level_option)) &&
       ((print_limit_option == 0 ||
        (iVar4 = ___ratelimit(msm_sps_probe__rs_324,"msm_sps_probe"), iVar4 != 0)))) {
      _printk(&DAT_0012561d,"msm_sps_probe","sps:get data from device tree\n");
    }
    if ((sps != (undefined8 *)0x0) && (*(int *)(sps + 0x24) == 0)) {
      ipc_log_string(sps[0x1f],"%s: %s","msm_sps_probe","sps:get data from device tree\n");
    }
    lVar7 = of_match_device(msm_sps_match,param_1 + 0x10);
    if (lVar7 == 0) {
      bam_type = 1;
      if (((1 < logging_option) && (debug_level_option != 0)) &&
         ((print_limit_option == 0 ||
          (iVar4 = ___ratelimit(msm_sps_probe__rs_329,"msm_sps_probe"), iVar4 != 0)))) {
        _printk(&DAT_00124c1e,"msm_sps_probe",bam_type);
      }
      if ((sps != (undefined8 *)0x0) && (*(uint *)(sps + 0x24) < 4)) {
        uVar8 = sps[0x22];
        pcVar10 = "%s: sps:use default BAM type:%d\n";
        goto LAB_00116298;
      }
    }
    else {
      bam_type = **(undefined4 **)(lVar7 + 0xc0);
      if (((1 < logging_option) && (debug_level_option != 0)) &&
         ((print_limit_option == 0 ||
          (iVar4 = ___ratelimit(msm_sps_probe__rs_326,"msm_sps_probe"), iVar4 != 0)))) {
        _printk(&DAT_0011fa83,"msm_sps_probe",bam_type);
      }
      if ((sps != (undefined8 *)0x0) && (*(uint *)(sps + 0x24) < 4)) {
        uVar8 = sps[0x22];
        pcVar10 = "%s: sps:BAM type is:%d\n";
LAB_00116298:
        ipc_log_string(uVar8,pcVar10,"msm_sps_probe",bam_type);
      }
    }
  }
  uVar8 = __class_create(&__this_module,"msm_sps",&msm_sps_probe___key);
  *sps = uVar8;
  iVar4 = alloc_chrdev_region(sps + 1,0,1,"msm_sps");
  if (iVar4 != 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar5 = ___ratelimit(msm_sps_probe__rs_337,"msm_sps_probe"), iVar5 != 0)))) {
      _printk(&DAT_001259d6,"msm_sps_probe");
    }
    if (sps != (undefined8 *)0x0) {
      ipc_log_string(sps[0x22],"%s: sps: alloc_chrdev_region err\n","msm_sps_probe");
    }
    goto LAB_00116828;
  }
  uVar9 = device_create(*sps,0,*(undefined4 *)(sps + 1),sps,"msm_sps");
  puVar14 = sps;
  sps[2] = uVar9;
  if (uVar9 < 0xfffffffffffff001) {
    if (*(long *)(param_1 + 0x2f8) != 0) {
      *(long *)(uVar9 + 0x2e8) = *(long *)(param_1 + 0x2f8);
    }
    if (d_type == 0) {
      uVar9 = clk_get(puVar14[2],"mem_clk");
      sps[3] = uVar9;
      if (uVar9 < 0xfffffffffffff001) {
        iVar4 = clk_prepare(uVar9);
        if (iVar4 == 0) {
          iVar4 = clk_enable(uVar9);
          if (iVar4 == 0) goto LAB_001163e0;
          clk_unprepare(uVar9);
        }
        if ((logging_option != 1) &&
           ((print_limit_option < 3 ||
            (iVar5 = ___ratelimit(msm_sps_probe__rs_347,"msm_sps_probe"), iVar5 != 0)))) {
          _printk(&DAT_001218e9,"msm_sps_probe");
        }
        if (sps != (undefined8 *)0x0) {
          ipc_log_string(sps[0x22],"%s: sps: failed to enable pmem_clk\n","msm_sps_probe");
        }
        goto LAB_001167f4;
      }
      if (uVar9 == 0xfffffffffffffdfb) {
        iVar4 = -0x205;
      }
      else {
        if ((logging_option != 1) &&
           ((print_limit_option < 3 ||
            (iVar4 = ___ratelimit(msm_sps_probe__rs_344,"msm_sps_probe"), iVar4 != 0)))) {
          _printk(&DAT_0011d3cd,"msm_sps_probe");
        }
        if (sps == (undefined8 *)0x0) {
          iVar4 = 0;
        }
        else {
          ipc_log_string(sps[0x22],"%s: sps: fail to get pmem_clk\n","msm_sps_probe");
          iVar4 = 0;
        }
      }
    }
    else {
LAB_001163e0:
      if (((1 < logging_option) && (debug_level_option != 0)) &&
         ((print_limit_option == 0 ||
          (iVar4 = ___ratelimit(sps_device_init__rs,"sps_device_init"), iVar4 != 0)))) {
        _printk(&DAT_0011f4ab,"sps_device_init");
      }
      if ((sps != (undefined8 *)0x0) && (*(uint *)(sps + 0x24) < 4)) {
        ipc_log_string(sps[0x22],"%s: Enter\n","sps_device_init");
      }
      iVar4 = sps_mem_init(sps[7],*(undefined4 *)(sps + 8));
      puVar14 = sps;
      if (iVar4 == 0) {
        puVar13 = sps + 0x14;
        puVar1 = sps + 0xe;
        sps[0x14] = puVar13;
        puVar14[0x15] = puVar13;
        __mutex_init(puVar1,"&sps->lock",&sps_device_init___key);
        iVar4 = sps_rm_init(sps + 0x17,*(undefined4 *)((long)sps + 0x6c));
        if (iVar4 == 0) {
          iVar4 = sps_bam_driver_init(*(undefined4 *)((long)sps + 0x6c));
          if (iVar4 == 0) {
            iVar4 = sps_map_init(0,*(undefined4 *)((long)sps + 0x6c));
            puVar14 = sps;
            if (iVar4 == 0) {
              bVar3 = logging_option != 1;
              *(undefined4 *)(sps + 6) = 1;
              if (bVar3) {
                if ((print_limit_option < 2) ||
                   (iVar4 = ___ratelimit(msm_sps_probe__rs_353,"msm_sps_probe"), iVar4 != 0)) {
                  _printk(&DAT_0012561d,"msm_sps_probe","sps:sps is ready\n");
                }
                puVar14 = sps;
              }
              if (puVar14 != (undefined8 *)0x0) {
                ipc_log_string(puVar14[0x22],"%s: %s","msm_sps_probe","sps:sps is ready\n");
              }
              return 0;
            }
            if ((logging_option != 1) &&
               ((print_limit_option < 3 ||
                (iVar4 = ___ratelimit(sps_device_init__rs_387,"sps_device_init"), iVar4 != 0)))) {
              _printk(&DAT_0011e0e7,"sps_device_init");
            }
            if (sps != (undefined8 *)0x0) {
              pcVar10 = "%s: sps: SPS connection mapping init failed\n";
              goto LAB_00116768;
            }
          }
          else {
            if ((logging_option != 1) &&
               ((print_limit_option < 3 ||
                (iVar4 = ___ratelimit(sps_device_init__rs_384,"sps_device_init"), iVar4 != 0)))) {
              _printk(&DAT_00124ff8,"sps_device_init");
            }
            if (sps != (undefined8 *)0x0) {
              pcVar10 = "%s: sps: SPS BAM driver init failed\n";
LAB_00116768:
              ipc_log_string(sps[0x22],pcVar10,"sps_device_init");
            }
          }
        }
        else {
          if ((logging_option != 1) &&
             ((print_limit_option < 3 ||
              (iVar4 = ___ratelimit(sps_device_init__rs_381,"sps_device_init"), iVar4 != 0)))) {
            _printk(&DAT_001220a4,"sps_device_init");
          }
          if (sps != (undefined8 *)0x0) {
            pcVar10 = "%s: sps: Fail to init SPS resource manager\n";
            goto LAB_00116768;
          }
        }
      }
      else {
        if ((logging_option != 1) &&
           ((print_limit_option < 3 ||
            (iVar4 = ___ratelimit(sps_device_init__rs_377,"sps_device_init"), iVar4 != 0)))) {
          _printk(&DAT_001214f9,"sps_device_init");
        }
        if (sps != (undefined8 *)0x0) {
          pcVar10 = "%s: sps: SPS memory init failed\n";
          goto LAB_00116768;
        }
      }
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar4 = ___ratelimit(msm_sps_probe__rs_350,"msm_sps_probe"), iVar4 != 0)))) {
        _printk(&DAT_00124371,"msm_sps_probe");
      }
      if (sps != (undefined8 *)0x0) {
        ipc_log_string(sps[0x22],"%s: sps: sps_device_init err\n","msm_sps_probe");
      }
      if (d_type == 0) {
        uVar8 = sps[3];
        clk_disable(uVar8);
        clk_unprepare(uVar8);
        iVar4 = -1;
LAB_001167f4:
        if (d_type == 0) {
          clk_put(sps[3]);
        }
      }
      else {
        iVar4 = -1;
      }
    }
    device_destroy(*sps,*(undefined4 *)(sps + 1));
  }
  else {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar4 = ___ratelimit(msm_sps_probe__rs_340,"msm_sps_probe"), iVar4 != 0)))) {
      _printk(&DAT_0011dcc4,"msm_sps_probe");
    }
    if (sps == (undefined8 *)0x0) {
      iVar4 = 0;
    }
    else {
      ipc_log_string(sps[0x22],"%s: sps: device_create err\n","msm_sps_probe");
      iVar4 = 0;
    }
  }
  unregister_chrdev_region(*(undefined4 *)(sps + 1),1);
LAB_00116828:
  class_destroy(*sps);
  return iVar4;
}



//------------------------------------------------------------
// msm_sps_remove @ 00116e30 size=536
// signature: undefined msm_sps_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_sps_remove(void)

{
  int iVar1;
  
  if (((1 < logging_option) && (debug_level_option != '\0')) &&
     ((print_limit_option == 0 ||
      (iVar1 = ___ratelimit(msm_sps_remove__rs,"msm_sps_remove"), iVar1 != 0)))) {
    _printk(&DAT_00121fe7,"msm_sps_remove");
  }
  if ((sps != (undefined8 *)0x0) && (*(uint *)(sps + 0x24) < 4)) {
    ipc_log_string(sps[0x22],"%s: sps: Enter\n","msm_sps_remove");
  }
  device_destroy(*sps,*(undefined4 *)(sps + 1));
  unregister_chrdev_region(*(undefined4 *)(sps + 1),1);
  class_destroy(*sps);
  if (((1 < logging_option) && (debug_level_option != '\0')) &&
     ((print_limit_option == 0 ||
      (iVar1 = ___ratelimit(sps_device_de_init__rs,"sps_device_de_init"), iVar1 != 0)))) {
    _printk(&DAT_0011f4ab,"sps_device_de_init");
  }
  if ((sps != (undefined8 *)0x0) &&
     ((3 < *(uint *)(sps + 0x24) ||
      (ipc_log_string(sps[0x22],"%s: Enter\n","sps_device_de_init"), sps != (undefined8 *)0x0)))) {
    if ((undefined8 *)sps[0x14] != sps + 0x14) {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar1 = ___ratelimit(sps_device_de_init__rs_390,"sps_device_de_init"), iVar1 != 0)))) {
        _printk(&DAT_001220d2,"sps_device_de_init");
      }
      if (sps != (undefined8 *)0x0) {
        ipc_log_string(sps[0x22],"%s: sps: BAMs are still registered\n","sps_device_de_init");
      }
    }
    sps_map_de_init();
  }
  sps_mem_de_init();
  clk_put(sps[5]);
  if (d_type == 0) {
    clk_put(sps[3]);
  }
  clk_put(sps[4]);
  return 0;
}



//------------------------------------------------------------
// sps_map_init @ 00117074 size=268
// signature: undefined sps_map_init(void)
// callers: [msm_sps_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 sps_map_init(long param_1,undefined4 param_2)

{
  int iVar1;
  long *plVar2;
  
  sps_maps = 0;
  DAT_00126628 = 0;
  _DAT_0012662c = 0;
  if (param_1 != 0) {
    DAT_00126628 = 0;
    for (plVar2 = (long *)(param_1 + 8); ((int)plVar2[-1] != -0x21524111 || (*plVar2 != 0xdeadbeef))
        ; plVar2 = plVar2 + 0xb) {
      DAT_00126628 = DAT_00126628 + 1;
    }
    sps_maps = param_1;
    _DAT_0012662c = param_2;
    if (((1 < logging_option) && (3 < debug_level_option)) &&
       ((print_limit_option == '\0' ||
        (iVar1 = ___ratelimit(&sps_map_init__rs,"sps_map_init"), iVar1 != 0)))) {
      _printk(&DAT_00125a22,"sps_map_init",DAT_00126628);
    }
    if ((sps != 0) && (*(int *)(sps + 0x120) == 0)) {
      ipc_log_string(*(undefined8 *)(sps + 0xf8),"%s: sps: %d mappings\n","sps_map_init",
                     DAT_00126628);
    }
  }
  return 0;
}



//------------------------------------------------------------
// sps_map_de_init @ 00117184 size=16
// signature: undefined sps_map_de_init(void)
// callers: [msm_sps_remove]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sps_map_de_init(void)

{
  sps_maps = 0;
  _DAT_00126628 = 0;
  return;
}



//------------------------------------------------------------
// sps_map_find @ 00117198 size=588
// signature: undefined sps_map_find(void)
// callers: [sps_rm_state_change]
//------------------------------------------------------------

undefined8 sps_map_find(long *param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  long lVar6;
  long *plVar7;
  int *piVar8;
  
  if (DAT_00126628 != 0) {
    piVar8 = (int *)(sps_maps + 0x28);
    iVar1 = DAT_00126628;
    do {
      if (((piVar8[-10] == (int)*param_1) && (piVar8[-4] == (int)param_1[3])) &&
         (piVar8[2] == (int)param_1[6])) {
        plVar7 = (long *)(piVar8 + 4);
        lVar2 = spsi_get_mem_ptr(*plVar7);
        if (lVar2 == 0) {
          if ((logging_option != '\x01') &&
             ((print_limit_option < 3 ||
              (iVar1 = ___ratelimit(sps_map_find__rs,"sps_map_find"), iVar1 != 0)))) {
            _printk(&DAT_0011dcf4,"sps_map_find",plVar7);
          }
          if (sps == 0) {
            return 0xffffffff;
          }
          uVar4 = *(undefined8 *)(sps + 0x110);
          pcVar5 = "%s: sps:Cannot get virt addr for I/O buffer: %pa\n";
LAB_00117298:
          ipc_log_string(uVar4,pcVar5,"sps_map_find",plVar7);
          return 0xffffffff;
        }
        if ((piVar8[10] == 0) || (plVar7 = (long *)(piVar8 + 8), *plVar7 == 0xdeadbeef)) {
          lVar3 = 0;
        }
        else {
          lVar3 = spsi_get_mem_ptr();
          if (lVar3 == 0) {
            if ((logging_option != '\x01') &&
               ((print_limit_option < 3 ||
                (iVar1 = ___ratelimit(sps_map_find__rs_4,"sps_map_find"), iVar1 != 0)))) {
              _printk(&DAT_001243af,"sps_map_find",plVar7);
            }
            if (sps == 0) {
              return 0xffffffff;
            }
            uVar4 = *(undefined8 *)(sps + 0x110);
            pcVar5 = "%s: sps:Can\'t get virt addr for I/O buffer: %pa\n";
            goto LAB_00117298;
          }
        }
        if (*param_1 != 0x7fffffffffffffff) {
          *(int *)(param_1 + 2) = piVar8[-6];
        }
        if (param_1[3] != 0x7fffffffffffffff) {
          *(int *)(param_1 + 5) = *piVar8;
        }
        lVar6 = -0x14;
        if (*(int *)((long)param_1 + 0x2c) != 0) {
          lVar6 = 4;
        }
        *(int *)(param_1 + 0xf) = *(int *)((long)piVar8 + lVar6);
        *(int *)(param_1 + 10) = piVar8[6];
        lVar6 = *(long *)(piVar8 + 4);
        param_1[7] = lVar2;
        param_1[8] = lVar6;
        if ((piVar8[10] == 0) || (*(long *)(piVar8 + 8) == 0xdeadbeef)) {
          return 0;
        }
        *(int *)(param_1 + 0xe) = piVar8[10];
        lVar2 = *(long *)(piVar8 + 8);
        param_1[0xb] = lVar3;
        param_1[0xc] = lVar2;
        return 0;
      }
      iVar1 = iVar1 + -1;
      piVar8 = piVar8 + 0x16;
    } while (iVar1 != 0);
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// spsi_get_mem_ptr @ 001173e8 size=288
// signature: undefined spsi_get_mem_ptr(void)
// callers: [sps_setup_bam2bam_fifo, sps_map_find, sps_rm_state_change, sps_alloc_mem]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong spsi_get_mem_ptr(ulong param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = param_1;
  if ((param_1 < _iomem_phys) || (_iomem_phys + iomem_size <= param_1)) {
    uVar3 = param_1 - _memstart_addr | 0xffffff8000000000;
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(&spsi_get_mem_ptr__rs,"spsi_get_mem_ptr"), iVar2 != 0)))) {
      _printk(&DAT_00123ea5,"spsi_get_mem_ptr","spsi_get_mem_ptr",&local_30);
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps:%s.invalid phys addr=0x%pa\n",
                     "spsi_get_mem_ptr","spsi_get_mem_ptr",&local_30);
    }
  }
  else {
    uVar3 = iomem_virt + (param_1 - _iomem_phys);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// sps_mem_alloc_io @ 0011750c size=484
// signature: undefined sps_mem_alloc_io(void)
// callers: [sps_rm_state_change, sps_alloc_mem]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long sps_mem_alloc_io(int param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  lVar3 = gen_pool_alloc_algo_owner
                    (pool,param_1,*(undefined8 *)(pool + 0x20),*(undefined8 *)(pool + 0x28),0);
  if (lVar3 == 0) {
    if ((logging_option != 1) &&
       ((print_limit_option < 3 ||
        (iVar2 = ___ratelimit(sps_mem_alloc_io__rs,"sps_mem_alloc_io"), iVar2 != 0)))) {
      _printk(&DAT_0011e669,"sps_mem_alloc_io",param_1);
    }
    lVar3 = 0xdeadbeef;
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps:gen_pool_alloc %d bytes fail\n",
                     "sps_mem_alloc_io",param_1);
    }
  }
  else {
    local_30 = (ulong)(uint)((int)lVar3 - (int)iomem_virt) + _iomem_phys;
    total_alloc = total_alloc + param_1;
    if (((1 < logging_option) && (debug_level_option != '\0')) &&
       ((print_limit_option == 0 ||
        (iVar2 = ___ratelimit(sps_mem_alloc_io__rs_4,"sps_mem_alloc_io"), iVar2 != 0)))) {
      _printk(&DAT_0011f515,"sps_mem_alloc_io","sps_mem_alloc_io",&local_30,lVar3,param_1);
    }
    if ((sps != 0) && (*(uint *)(sps + 0x120) < 4)) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps:%s.phys=%pa.virt=0x%pK.size=0x%x\n",
                     "sps_mem_alloc_io","sps_mem_alloc_io",&local_30,lVar3,param_1);
    }
    lVar3 = local_30;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3;
}



//------------------------------------------------------------
// sps_mem_free_io @ 001176f4 size=320
// signature: undefined sps_mem_free_io(void)
// callers: [sps_free_mem, sps_rm_free_map_rsrc]
//------------------------------------------------------------

void sps_mem_free_io(undefined8 param_1,int param_2)

{
  long lVar1;
  int iVar2;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  lVar1 = (ulong)(uint)((int)param_1 - iomem_phys) + iomem_virt;
  local_30 = param_1;
  if (((1 < logging_option) && (debug_level_option != '\0')) &&
     ((print_limit_option == '\0' ||
      (iVar2 = ___ratelimit(sps_mem_free_io__rs,"sps_mem_free_io"), iVar2 != 0)))) {
    _printk(&DAT_0011f515,"sps_mem_free_io","sps_mem_free_io",&local_30,lVar1,param_2);
  }
  if ((sps != 0) && (*(uint *)(sps + 0x120) < 4)) {
    ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps:%s.phys=%pa.virt=0x%pK.size=0x%x\n",
                   "sps_mem_free_io","sps_mem_free_io",&local_30,lVar1,param_2);
  }
  gen_pool_free_owner(pool,lVar1,param_2,0);
  total_free = total_free + param_2;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// sps_mem_init @ 00117838 size=776
// signature: undefined sps_mem_init(void)
// callers: [msm_sps_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 sps_mem_init(long param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  
  if ((d_type & 0xfffffffd) == 0 || imem != '\0') {
    _iomem_phys = param_1;
    iomem_size = param_2;
    if (param_1 == 0) {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar1 = ___ratelimit(sps_mem_init__rs,"sps_mem_init"), iVar1 != 0)))) {
        _printk(&DAT_001248ed,"sps_mem_init","sps_mem_init");
      }
      if (sps == 0) {
        return 0xffffffff;
      }
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps:%s:Invalid Pipe-Mem address\n",
                     "sps_mem_init","sps_mem_init");
      return 0xffffffff;
    }
    uVar2 = 0x68000000000713;
    if (arm64_use_ng_mappings != '\0') {
      uVar2 = 0x68000000000f13;
    }
    iomem_virt = ioremap_prot(param_1,param_2,uVar2);
    if (iomem_virt == 0) {
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar1 = ___ratelimit(sps_mem_init__rs_9,"sps_mem_init"), iVar1 != 0)))) {
        _printk(&DAT_0012151c,"sps_mem_init","sps_mem_init");
      }
      if (sps == 0) {
        return 0xfffffff4;
      }
      uVar2 = *(undefined8 *)(sps + 0x110);
      pcVar3 = "%s: sps:%s:Failed to IO map pipe memory\n";
      goto LAB_00117a54;
    }
    if (((1 < logging_option) && (3 < debug_level_option)) &&
       ((print_limit_option == 0 ||
        (iVar1 = ___ratelimit(sps_mem_init__rs_12,"sps_mem_init"), iVar1 != 0)))) {
      _printk(&DAT_0012193a,"sps_mem_init","sps_mem_init",&iomem_phys,iomem_virt);
    }
    if ((sps != 0) && (*(int *)(sps + 0x120) == 0)) {
      ipc_log_string(*(undefined8 *)(sps + 0xf8),"%s: sps:%s.iomem_phys=%pa,iomem_virt=0x%pK\n",
                     "sps_mem_init","sps_mem_init",&iomem_phys,iomem_virt);
    }
  }
  pool = gen_pool_create(8,0xffffffff);
  if (pool != 0) {
    if ((((d_type & 0xfffffffd) == 0) || (imem != '\0')) &&
       (uVar2 = gen_pool_add_owner(pool,iomem_virt,0xffffffffffffffff,iomem_size,0xffffffff,0),
       (int)uVar2 != 0)) {
      return uVar2;
    }
    return 0;
  }
  if ((logging_option != 1) &&
     ((print_limit_option < 3 ||
      (iVar1 = ___ratelimit(sps_mem_init__rs_15,"sps_mem_init"), iVar1 != 0)))) {
    _printk(&DAT_001224fd,"sps_mem_init","sps_mem_init");
  }
  if (sps == 0) {
    return 0xfffffff4;
  }
  uVar2 = *(undefined8 *)(sps + 0x110);
  pcVar3 = "%s: sps:%s:Failed to create a new memory pool\n";
LAB_00117a54:
  ipc_log_string(uVar2,pcVar3,"sps_mem_init","sps_mem_init");
  return 0xfffffff4;
}



//------------------------------------------------------------
// sps_mem_de_init @ 00117b44 size=232
// signature: undefined sps_mem_de_init(void)
// callers: [msm_sps_remove]
//------------------------------------------------------------

undefined8 sps_mem_de_init(void)

{
  int iVar1;
  undefined8 uVar2;
  
  if (iomem_virt != 0) {
    gen_pool_destroy(pool);
    pool = 0;
    iounmap(iomem_virt);
    iomem_virt = 0;
  }
  if (total_alloc == total_free) {
    uVar2 = 0;
  }
  else {
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar1 = ___ratelimit(sps_mem_de_init__rs,"sps_mem_de_init"), iVar1 != 0)))) {
      _printk(&DAT_00121547,"sps_mem_de_init","sps_mem_de_init");
    }
    if (sps != 0) {
      ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps:%s:some memory not free\n",
                     "sps_mem_de_init","sps_mem_de_init");
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



//------------------------------------------------------------
// sps_rm_init @ 00117c30 size=72
// signature: undefined sps_rm_init(void)
// callers: [msm_sps_probe]
//------------------------------------------------------------

undefined8 sps_rm_init(long param_1)

{
  sps_rm = param_1;
  *(long *)param_1 = param_1;
  *(long *)(param_1 + 8) = param_1;
  __mutex_init(param_1 + 0x10,"&sps_rm->lock",&sps_rm_init___key);
  return 0;
}



//------------------------------------------------------------
// sps_rm_config_init @ 00117c7c size=44
// signature: undefined sps_rm_config_init(void)
// callers: [sps_disconnect, sps_alloc_endpoint]
//------------------------------------------------------------

void sps_rm_config_init(undefined8 *param_1)

{
  param_1[0x10] = 0xcccccccccccccccc;
  param_1[0x11] = 0xcccccccccccccccc;
  param_1[0xe] = 0xcccccccccccccccc;
  param_1[0xf] = 0xcccccccccccccccc;
  param_1[0xc] = 0xcccccccccccccccc;
  param_1[0xd] = 0xcccccccccccccccc;
  param_1[10] = 0xcccccccccccccccc;
  param_1[0xb] = 0xcccccccccccccccc;
  param_1[8] = 0xcccccccccccccccc;
  param_1[9] = 0xcccccccccccccccc;
  param_1[6] = 0xcccccccccccccccc;
  param_1[7] = 0xcccccccccccccccc;
  param_1[4] = 0xcccccccccccccccc;
  param_1[5] = 0xcccccccccccccccc;
  param_1[2] = 0xcccccccccccccccc;
  param_1[3] = 0xcccccccccccccccc;
  *param_1 = 0xcccccccccccccccc;
  param_1[1] = 0xcccccccccccccccc;
  return;
}



//------------------------------------------------------------
// sps_rm_state_change @ 00117cac size=4720
// signature: undefined sps_rm_state_change(void)
// callers: [sps_connect, sps_disconnect]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sps_rm_state_change(long param_1,int param_2)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  byte bVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  ulong uVar10;
  char *pcVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  long *plVar15;
  long lVar16;
  long lVar17;
  uint uVar18;
  uint uVar19;
  undefined8 uVar20;
  long *plVar21;
  undefined8 *puVar22;
  long *plVar23;
  long *plVar24;
  long *plVar25;
  undefined8 *puVar26;
  long *plVar27;
  undefined4 local_78;
  undefined8 local_74;
  undefined4 local_6c;
  long local_68;
  
  lVar16 = sp_el0;
  local_68 = *(long *)(lVar16 + 0x638);
  iVar9 = *(int *)(param_1 + 0x10);
  if ((param_2 == 0x1535053) && (iVar9 == 0)) {
    iVar9 = *(int *)(param_1 + 0x50);
    if (*(int *)(param_1 + 0xa8) != -0x33333334) {
      uVar20 = *(undefined8 *)(param_1 + 0x38);
      *(undefined8 *)(param_1 + 0x28) = 0xcccccccccccccccc;
      *(undefined8 *)(param_1 + 0x30) = 0xcccccccccccccccc;
      *(undefined8 *)(param_1 + 0x58) = 0xcccccccccccccccc;
      *(undefined8 *)(param_1 + 0x60) = 0xcccccccccccccccc;
      *(undefined8 *)(param_1 + 0x68) = 0xcccccccccccccccc;
      *(undefined8 *)(param_1 + 0x70) = 0xcccccccccccccccc;
      *(undefined8 *)(param_1 + 0x78) = 0xcccccccccccccccc;
      *(undefined8 *)(param_1 + 0x80) = 0xcccccccccccccccc;
      *(undefined8 *)(param_1 + 0x88) = 0xcccccccccccccccc;
      *(undefined8 *)(param_1 + 0x90) = 0xcccccccccccccccc;
      *(undefined8 *)(param_1 + 0x98) = 0xcccccccccccccccc;
      *(undefined8 *)(param_1 + 0xa0) = 0xcccccccccccccccc;
      *(undefined8 *)(param_1 + 0xa8) = 0xcccccccccccccccc;
      *(undefined8 *)(param_1 + 0x38) = 0xcccccccccccccccc;
      *(undefined8 *)(param_1 + 0x40) = 0xcccccccccccccccc;
      *(undefined8 *)(param_1 + 0x48) = 0xcccccccccccccccc;
      *(undefined8 *)(param_1 + 0x50) = 0xcccccccccccccccc;
      *(undefined8 *)(param_1 + 0x38) = uVar20;
      *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
      *(int *)(param_1 + 0x50) = iVar9;
    }
    if (iVar9 == 0) {
LAB_00117dd0:
      mutex_lock(sps_rm + 2);
      if ((*(uint *)(param_1 + 0x10) & 0xffffff) == 0x535053) {
        if ((logging_option != '\x01') &&
           ((print_limit_option < 3 ||
            (iVar9 = ___ratelimit(sps_rm_alloc__rs_18,"sps_rm_alloc"), iVar9 != 0)))) {
          _printk(&DAT_00122128,"sps_rm_alloc","sps_rm_alloc");
        }
        if (sps != 0) {
          pcVar11 = "%s: sps:%s:Client connection already allocated\n";
          goto LAB_00118c24;
        }
      }
      else {
        puVar22 = (undefined8 *)*sps_rm;
        if (puVar22 != sps_rm) {
          do {
            if ((((((*(long *)(param_1 + 0x20) == puVar22[2]) &&
                   (*(long *)(param_1 + 0x38) == puVar22[7])) &&
                  ((*(int *)(param_1 + 0x30) == -0x33333334 ||
                   (*(int *)(param_1 + 0x30) == *(int *)(puVar22 + 4))))) &&
                 (((*(int *)(param_1 + 0x48) == -0x33333334 ||
                   (*(int *)(param_1 + 0x48) == *(int *)(puVar22 + 9))) &&
                  (*(int *)(param_1 + 0x50) == *(int *)(puVar22 + 0x14))))) &&
                ((*(int *)(param_1 + 0x70) == -0x33333334 ||
                 ((*(int *)(param_1 + 0x70) == *(int *)(puVar22 + 0xf) &&
                  (((*(long *)(param_1 + 0x60) == -0x3333333333333334 ||
                    (*(long *)(param_1 + 0x58) == -0x3333333333333334)) ||
                   ((*(long *)(param_1 + 0x60) == puVar22[0xd] &&
                    (*(long *)(param_1 + 0x58) == puVar22[0xc])))))))))) &&
               ((*(int *)(param_1 + 0x90) == -0x33333334 ||
                ((*(int *)(param_1 + 0x90) == *(int *)(puVar22 + 0x13) &&
                 (((*(long *)(param_1 + 0x80) == -0x3333333333333334 ||
                   (*(long *)(param_1 + 0x78) == -0x3333333333333334)) ||
                  ((*(long *)(param_1 + 0x80) == puVar22[0x11] &&
                   (*(long *)(param_1 + 0x78) == puVar22[0x10])))))))))) {
              if (*(int *)(param_1 + 0x4c) == 0) {
                lVar16 = puVar22[0x15];
              }
              else {
                lVar16 = puVar22[0x16];
              }
              if (lVar16 == 0) {
                if ((puVar22 != (undefined8 *)0x0) &&
                   (iVar9 = sps_rm_assign(param_1,puVar22), iVar9 == 0)) goto LAB_0011869c;
                break;
              }
            }
            puVar22 = (undefined8 *)*puVar22;
          } while (puVar22 != sps_rm);
        }
        puVar22 = (undefined8 *)kmalloc_trace(_ipc_log_context_destroy,0xdc0,0xd8);
        if (puVar22 == (undefined8 *)0x0) {
          if ((logging_option != '\x01') &&
             ((print_limit_option < 3 ||
              (iVar9 = ___ratelimit(sps_rm_create__rs,"sps_rm_create"), iVar9 != 0)))) {
            _printk(&DAT_001215a3,"sps_rm_create","sps_rm_create");
          }
          if (sps != 0) {
            ipc_log_string(*(undefined8 *)(sps + 0x110),
                           "%s: sps:%s:Failed to allocate connection struct\n","sps_rm_create",
                           "sps_rm_create");
          }
        }
        else {
          puVar22[0x16] = 0;
          puVar22[0x17] = 0;
          puVar22[0x14] = 0;
          puVar22[0x15] = 0;
          puVar22[0x12] = 0;
          puVar22[0x13] = 0;
          puVar22[0xe] = 0;
          puVar22[0xf] = 0;
          iVar9 = *(int *)(param_1 + 0x70);
          plVar27 = puVar22 + 0x10;
          *plVar27 = 0;
          plVar24 = puVar22 + 0x11;
          *plVar24 = 0;
          plVar23 = puVar22 + 0xd;
          *plVar23 = 0;
          puVar22[0x18] = 0;
          puVar22[0x19] = 0xdeadbeef;
          *plVar23 = 0xdeadbeef;
          *plVar24 = 0xdeadbeef;
          puVar22[0x1a] = 0xdeadbeef;
          lVar17 = *(long *)(param_1 + 0x38);
          puVar22[10] = 0;
          puVar22[0xb] = 0;
          puVar22[8] = 0;
          puVar22[9] = 0;
          puVar22[5] = 0;
          puVar22[6] = 0;
          plVar21 = puVar22 + 0xc;
          *plVar21 = 0;
          plVar25 = puVar22 + 7;
          *plVar25 = 0;
          puVar22[3] = 0;
          puVar22[4] = 0;
          *puVar22 = 0;
          puVar22[1] = 0;
          lVar16 = *(long *)(param_1 + 0x20);
          *(undefined8 *)((long)puVar22 + 0xbc) = 0xffffffffffffffff;
          iVar5 = *(int *)(param_1 + 0x90);
          *plVar25 = lVar17;
          uVar14 = *(undefined4 *)(param_1 + 0x50);
          plVar15 = puVar22 + 2;
          *plVar15 = 0;
          *plVar15 = lVar16;
          *(int *)(puVar22 + 0xf) = iVar9;
          *(int *)(puVar22 + 0x13) = iVar5;
          *(undefined4 *)(puVar22 + 0x14) = uVar14;
          if (((iVar9 != -0x33333334) && (*(long *)(param_1 + 0x60) != -0x3333333333333334)) &&
             (*(long *)(param_1 + 0x58) != -0x3333333333333334)) {
            uVar3 = *(undefined8 *)(param_1 + 0x60);
            uVar20 = *(undefined8 *)(param_1 + 0x68);
            uVar4 = *(undefined8 *)(param_1 + 0x70);
            *plVar21 = *(long *)(param_1 + 0x58);
            puVar22[0xd] = uVar3;
            puVar22[0xe] = uVar20;
            puVar22[0xf] = uVar4;
          }
          if (((iVar5 != -0x33333334) && (*(long *)(param_1 + 0x80) != -0x3333333333333334)) &&
             (*(long *)(param_1 + 0x78) != -0x3333333333333334)) {
            uVar3 = *(undefined8 *)(param_1 + 0x80);
            uVar20 = *(undefined8 *)(param_1 + 0x88);
            uVar4 = *(undefined8 *)(param_1 + 0x90);
            *plVar27 = *(long *)(param_1 + 0x78);
            puVar22[0x11] = uVar3;
            puVar22[0x12] = uVar20;
            puVar22[0x13] = uVar4;
          }
          iVar9 = *(int *)(param_1 + 0x30);
          iVar5 = *(int *)(param_1 + 0x48);
          iVar2 = *(int *)(param_1 + 0x4c);
          if (iVar9 == -0x33333334) {
            iVar9 = -1;
          }
          if (iVar5 == -0x33333334) {
            iVar5 = -1;
          }
          *(int *)(puVar22 + 4) = iVar9;
          *(int *)(puVar22 + 9) = iVar5;
          lVar16 = sps_h2bam();
          puVar22[6] = lVar16;
          if (lVar16 == 0) {
            if (*plVar15 == 0x7fffffffffffffff) {
              *(undefined4 *)(puVar22 + 4) = 0xffffffff;
              bVar6 = *(byte *)(param_1 + 0x55);
              goto joined_r0x00118198;
            }
            if ((logging_option != '\x01') &&
               ((print_limit_option < 3 ||
                (iVar9 = ___ratelimit(sps_rm_create__rs_34,"sps_rm_create"), iVar9 != 0)))) {
              _printk(&DAT_00124438,"sps_rm_create",plVar15);
            }
            if (sps == 0) goto LAB_00118bc4;
            uVar20 = *(undefined8 *)(sps + 0x110);
            pcVar11 = "%s: sps:Invalid BAM handle: %pK\n";
LAB_00118bc0:
            ipc_log_string(uVar20,pcVar11,"sps_rm_create",plVar15);
          }
          else {
            bVar6 = *(byte *)(param_1 + 0x55);
joined_r0x00118198:
            if ((bVar6 >> 2 & 1) == 0) {
              lVar16 = sps_h2bam(puVar22[7]);
              puVar22[0xb] = lVar16;
              if (lVar16 == 0) {
                if (*plVar25 != 0x7fffffffffffffff) {
                  if ((logging_option != '\x01') &&
                     ((print_limit_option < 3 ||
                      (iVar9 = ___ratelimit(sps_rm_create__rs_37,"sps_rm_create"), iVar9 != 0)))) {
                    _printk(&DAT_001230de,"sps_rm_create",plVar25);
                  }
                  if (sps != 0) {
                    uVar20 = *(undefined8 *)(sps + 0x110);
                    pcVar11 = "%s: sps:Invalid BAM handle: %pK";
                    plVar15 = plVar25;
                    goto LAB_00118bc0;
                  }
                  goto LAB_00118bc4;
                }
                *(undefined4 *)(puVar22 + 9) = 0xffffffff;
              }
            }
            if (iVar2 == 0) {
              lVar16 = puVar22[6];
              if (lVar16 != 0) {
LAB_001181c8:
                iVar9 = sps_bam_pipe_alloc(lVar16,*(undefined4 *)(puVar22 + 4));
                *(int *)((long)puVar22 + 0xbc) = iVar9;
                if (iVar9 == -1) goto LAB_00118bc4;
                lVar17 = puVar22[0xb];
                *(int *)(puVar22 + 4) = iVar9;
                puVar22[3] = *(undefined8 *)(lVar16 + 0x18);
                *(undefined4 *)((long)puVar22 + 0x24) = *(undefined4 *)(lVar16 + 0x54);
                if (lVar17 != 0) goto LAB_00118200;
                goto LAB_0011822c;
              }
            }
            else {
              lVar17 = puVar22[0xb];
              if (lVar17 != 0) {
                lVar16 = puVar22[6];
                if (lVar16 != 0) goto LAB_001181c8;
LAB_00118200:
                iVar9 = sps_bam_pipe_alloc(lVar17,*(undefined4 *)(puVar22 + 9));
                *(int *)(puVar22 + 0x18) = iVar9;
                if (iVar9 == -1) goto LAB_00118bc4;
                *(int *)(puVar22 + 9) = iVar9;
                puVar22[8] = *(undefined8 *)(lVar17 + 0x18);
                *(undefined4 *)((long)puVar22 + 0x4c) = *(undefined4 *)(lVar17 + 0x54);
LAB_0011822c:
                lVar16 = puVar22[6];
                if (lVar16 == 0) {
                  uVar12 = 0;
                  uVar18 = 0;
                }
                else {
                  uVar18 = *(uint *)(lVar16 + 0x58);
                  uVar12 = *(uint *)(lVar16 + 0x5c);
                }
                lVar17 = puVar22[0xb];
                uVar19 = uVar18;
                uVar13 = uVar12;
                if (lVar17 != 0) {
                  uVar19 = *(uint *)(lVar17 + 0x58);
                  if (*(uint *)(lVar17 + 0x58) <= uVar18) {
                    uVar19 = uVar18;
                  }
                  uVar13 = *(uint *)(lVar17 + 0x5c);
                  if (*(uint *)(lVar17 + 0x5c) <= uVar12) {
                    uVar13 = uVar12;
                  }
                }
                uVar18 = *(uint *)(puVar22 + 0xf);
                if (*(uint *)(puVar22 + 0xf) == 0xcccccccc) {
                  *(uint *)(puVar22 + 0xf) = uVar19;
                  uVar18 = uVar19;
                }
                if ((lVar16 == 0) || (lVar17 == 0)) {
                  if ((*(byte *)(param_1 + 0x55) >> 2 & 1) == 0) {
                    uVar12 = uVar18 & 0xffff0000;
                    *(undefined4 *)(puVar22 + 0x13) = 0;
                  }
                  else {
                    uVar12 = uVar18 >> 0x10;
                  }
                  if (uVar12 != 0) goto LAB_00118464;
LAB_001184c8:
                  if ((uVar18 == 0) || (*plVar23 != 0xdeadbeef)) {
LAB_00118560:
                    if ((*(int *)(puVar22 + 0x13) == 0) || (*plVar24 != 0xdeadbeef)) {
LAB_00118604:
                      iVar9 = sps_rm_assign(param_1,puVar22);
                      puVar1 = sps_rm;
                      if (iVar9 == 0) {
                        puVar26 = (undefined8 *)sps_rm[1];
                        uVar10 = __list_add_valid(puVar22,puVar26,sps_rm);
                        if ((uVar10 & 1) != 0) {
                          puVar1[1] = puVar22;
                          *puVar22 = puVar1;
                          puVar22[1] = puVar26;
                          *puVar26 = puVar22;
                        }
LAB_0011869c:
                        puVar1 = sps_rm + 2;
                        *(int *)(puVar22 + 0x17) = *(int *)(puVar22 + 0x17) + 1;
                        mutex_unlock(puVar1);
                        iVar9 = *(int *)(param_1 + 0x10);
                        goto LAB_001186b8;
                      }
                      if ((logging_option != '\x01') &&
                         ((print_limit_option < 3 ||
                          (iVar9 = ___ratelimit(sps_rm_create__rs_57,"sps_rm_create"), iVar9 != 0)))
                         ) {
                        _printk(&DAT_00122c1e,"sps_rm_create","sps_rm_create");
                      }
                      if (sps != 0) {
                        uVar20 = *(undefined8 *)(sps + 0x110);
                        pcVar11 = "%s: sps:%s:failed to assign a connection to the client\n";
                        plVar15 = (long *)"sps_rm_create";
                        goto LAB_00118bc0;
                      }
                    }
                    else {
                      lVar16 = sps_mem_alloc_io();
                      puVar22[0x1a] = lVar16;
                      if (lVar16 == 0xdeadbeef) {
                        if ((logging_option != '\x01') &&
                           ((print_limit_option < 3 ||
                            (iVar9 = ___ratelimit(sps_rm_create__rs_55,"sps_rm_create"), iVar9 != 0)
                            ))) {
                          _printk(&DAT_00125a78,"sps_rm_create",*(undefined4 *)(puVar22 + 0x13));
                        }
                        if (sps != 0) {
                          uVar20 = *(undefined8 *)(sps + 0x110);
                          uVar14 = *(undefined4 *)(puVar22 + 0x13);
                          goto LAB_001185e4;
                        }
                      }
                      else {
                        *plVar24 = lVar16;
                        lVar16 = spsi_get_mem_ptr();
                        *plVar27 = lVar16;
                        if (lVar16 != 0) goto LAB_00118604;
                        if ((logging_option != '\x01') &&
                           ((print_limit_option < 3 ||
                            (iVar9 = ___ratelimit(sps_rm_create__rs_56,"sps_rm_create"), iVar9 != 0)
                            ))) {
                          _printk(&DAT_00123826,"sps_rm_create",plVar24);
                        }
                        if (sps != 0) {
                          uVar20 = *(undefined8 *)(sps + 0x110);
                          plVar23 = plVar24;
                          goto LAB_00118bb8;
                        }
                      }
                    }
                    goto LAB_00118bc4;
                  }
                  lVar16 = sps_mem_alloc_io(uVar18);
                  puVar22[0x19] = lVar16;
                  if (lVar16 != 0xdeadbeef) {
                    *plVar23 = lVar16;
                    lVar16 = spsi_get_mem_ptr();
                    *plVar21 = lVar16;
                    if (lVar16 != 0) goto LAB_00118560;
                    if ((logging_option != '\x01') &&
                       ((print_limit_option < 3 ||
                        (iVar9 = ___ratelimit(sps_rm_create__rs_52,"sps_rm_create"), iVar9 != 0))))
                    {
                      _printk(&DAT_00123826,"sps_rm_create",plVar23);
                    }
                    if (sps == 0) goto LAB_00118bc4;
                    uVar20 = *(undefined8 *)(sps + 0x110);
LAB_00118bb8:
                    pcVar11 = "%s: sps:Cannot get virt addr for I/O buffer:%pa\n";
                    plVar15 = plVar23;
                    goto LAB_00118bc0;
                  }
                  if ((logging_option != '\x01') &&
                     ((print_limit_option < 3 ||
                      (iVar9 = ___ratelimit(sps_rm_create__rs_49,"sps_rm_create"), iVar9 != 0)))) {
                    _printk(&DAT_00125a78,"sps_rm_create",*(undefined4 *)(puVar22 + 0xf));
                  }
                  if (sps == 0) goto LAB_00118bc4;
                  uVar20 = *(undefined8 *)(sps + 0x110);
                  uVar14 = *(undefined4 *)(puVar22 + 0xf);
LAB_001185e4:
                  pcVar11 = "%s: sps:I/O memory allocation failure:0x%x\n";
                }
                else {
                  uVar12 = *(uint *)(puVar22 + 0x13);
                  if (uVar12 == 0xcccccccc) {
                    *(uint *)(puVar22 + 0x13) = uVar13;
                    uVar12 = uVar13;
                    if ((uVar18 & 0xffff0000) == 0) goto LAB_00118400;
                  }
                  else if (uVar18 < 0x10000) {
LAB_00118400:
                    if (uVar12 < 0x10000) goto LAB_001184c8;
                    if (logging_option != '\x01') {
                      if (2 < print_limit_option) {
                        iVar9 = ___ratelimit(sps_rm_create__rs_46,"sps_rm_create");
                        if (iVar9 == 0) goto LAB_0011843c;
                        uVar12 = *(uint *)(puVar22 + 0x13);
                      }
                      _printk(&DAT_0012445b,"sps_rm_create",uVar12);
                    }
LAB_0011843c:
                    if (sps == 0) goto LAB_00118bc4;
                    uVar20 = *(undefined8 *)(sps + 0x110);
                    pcVar11 = "%s: sps:Invalid data FIFO size: 0x%x\n";
                    uVar14 = *(undefined4 *)(puVar22 + 0x13);
                    goto LAB_001184b8;
                  }
LAB_00118464:
                  if (logging_option != '\x01') {
                    if (2 < print_limit_option) {
                      iVar9 = ___ratelimit(sps_rm_create__rs_43,"sps_rm_create");
                      if (iVar9 == 0) goto LAB_0011849c;
                      uVar18 = *(uint *)(puVar22 + 0xf);
                    }
                    _printk(&DAT_00120543,"sps_rm_create",uVar18);
                  }
LAB_0011849c:
                  if (sps == 0) goto LAB_00118bc4;
                  uVar20 = *(undefined8 *)(sps + 0x110);
                  pcVar11 = "%s: sps:Invalid desc FIFO size: 0x%x\n";
                  uVar14 = *(undefined4 *)(puVar22 + 0xf);
                }
LAB_001184b8:
                ipc_log_string(uVar20,pcVar11,"sps_rm_create",uVar14);
                goto LAB_00118bc4;
              }
            }
            if ((logging_option != '\x01') &&
               ((print_limit_option < 3 ||
                (iVar9 = ___ratelimit(sps_rm_create__rs_40,"sps_rm_create"), iVar9 != 0)))) {
              _printk(&DAT_00121ced,"sps_rm_create",iVar2,plVar15,plVar25);
            }
            if (sps != 0) {
              ipc_log_string(*(undefined8 *)(sps + 0x110),
                             "%s: sps:Invalid BAM endpt: dir %d src %pK dest %pK\n","sps_rm_create",
                             iVar2,plVar15,plVar25);
            }
          }
LAB_00118bc4:
          sps_rm_free_map_rsrc(puVar22);
          kfree(puVar22);
        }
        if ((logging_option != '\x01') &&
           ((print_limit_option < 3 ||
            (iVar9 = ___ratelimit(sps_rm_alloc__rs_21,"sps_rm_alloc"), iVar9 != 0)))) {
          _printk(&DAT_001243e2,"sps_rm_alloc","sps_rm_alloc");
        }
        if (sps != 0) {
          pcVar11 = "%s: sps:%s:Failed to allocate connection\n";
LAB_00118c24:
          ipc_log_string(*(undefined8 *)(sps + 0x110),pcVar11,"sps_rm_alloc","sps_rm_alloc");
        }
      }
      mutex_unlock(sps_rm + 2);
    }
    else {
      if (iVar9 == -0x33333334) {
        *(undefined4 *)(param_1 + 0x50) = 0;
        goto LAB_00117dd0;
      }
      iVar9 = sps_map_find(param_1 + 0x20);
      if (iVar9 == 0) goto LAB_00117dd0;
      if ((logging_option != '\x01') &&
         ((print_limit_option < 3 ||
          (iVar9 = ___ratelimit(sps_rm_alloc__rs,"sps_rm_alloc"), iVar9 != 0)))) {
        _printk(&DAT_0011f56d,"sps_rm_alloc","sps_rm_alloc");
      }
      if (sps != 0) {
        ipc_log_string(*(undefined8 *)(sps + 0x110),"%s: sps:%s:Failed to find connection mapping\n"
                       ,"sps_rm_alloc","sps_rm_alloc");
      }
    }
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar9 = ___ratelimit(&sps_rm_state_change__rs,"sps_rm_state_change"), iVar9 != 0)))) {
      _printk(&DAT_0011eae1,"sps_rm_state_change",*(undefined8 *)(param_1 + 0x18),
              *(undefined4 *)(param_1 + 0xbc));
    }
    lVar16 = *(long *)(param_1 + 0x18);
    if (lVar16 != 0) {
      uVar20 = *(undefined8 *)(lVar16 + 0x228);
      pcVar11 = "%s: sps:Fail to allocate resource for BAM 0x%pK pipe %d\n";
LAB_00118c94:
      uVar14 = *(undefined4 *)(param_1 + 0xbc);
LAB_00118c98:
      ipc_log_string(uVar20,pcVar11,"sps_rm_state_change",lVar16,uVar14);
    }
  }
  else {
LAB_001186b8:
    if ((param_2 != 0x2535053) || (iVar9 != 0x1535053)) {
      bVar7 = param_2 == 0;
      if (iVar9 == 0x3535053) {
LAB_00118884:
        if ((param_2 == 0x4535053) || (param_2 == 0)) {
          iVar9 = sps_bam_pipe_disable
                            (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0xbc));
          if (iVar9 != 0) {
            if ((logging_option != '\x01') &&
               ((print_limit_option < 3 ||
                (iVar9 = ___ratelimit(sps_rm_state_change__rs_9,"sps_rm_state_change"), iVar9 != 0))
               )) {
              _printk(&DAT_001237f4,"sps_rm_state_change",*(long *)(param_1 + 0x18) + 0x18,
                      *(undefined4 *)(param_1 + 0xbc));
            }
            lVar16 = *(long *)(param_1 + 0x18);
            if (lVar16 != 0) {
              uVar20 = *(undefined8 *)(lVar16 + 0x228);
              lVar16 = lVar16 + 0x18;
              uVar14 = *(undefined4 *)(param_1 + 0xbc);
              pcVar11 = "%s: sps:Failed to set BAM %pa pipe %d flow off\n";
              goto LAB_00118c98;
            }
            goto LAB_00118ca4;
          }
          *(undefined4 *)(param_1 + 0x10) = 0x2535053;
LAB_0011890c:
          if (bVar7) {
            lVar16 = *(long *)(param_1 + 0x18);
            lVar17 = 0x20;
            if (*(int *)(param_1 + 0x4c) != 0) {
              lVar17 = 0x48;
            }
            uVar14 = *(undefined4 *)(*(long *)(param_1 + 0xb0) + lVar17);
            if (*(int *)(lVar16 + 0x2c) != 0) {
              synchronize_irq();
            }
            lVar16 = lVar16 + 0xe4;
            uVar20 = _raw_spin_lock_irqsave(lVar16);
            *(undefined1 *)(param_1 + 0x280) = 1;
            _raw_spin_unlock_irqrestore(lVar16,uVar20);
            iVar9 = sps_bam_pipe_disconnect(*(undefined8 *)(param_1 + 0x18),uVar14);
            if (iVar9 != 0) {
              if ((logging_option != '\x01') &&
                 ((print_limit_option < 3 ||
                  (iVar9 = ___ratelimit(sps_rm_state_change__rs_12,"sps_rm_state_change"),
                  iVar9 != 0)))) {
                _printk(&DAT_00123b3a,"sps_rm_state_change",*(long *)(param_1 + 0x18) + 0x18,
                        *(undefined4 *)(param_1 + 0xbc));
              }
              lVar16 = *(long *)(param_1 + 0x18);
              if (lVar16 != 0) {
                uVar20 = *(undefined8 *)(lVar16 + 0x228);
                lVar16 = lVar16 + 0x18;
                uVar14 = *(undefined4 *)(param_1 + 0xbc);
                pcVar11 = "%s: sps:Failed to disconnect BAM %pa pipe %d\n";
                goto LAB_00118c98;
              }
              goto LAB_00118ca4;
            }
            if (*(int *)(param_1 + 0x4c) == 1) {
              puVar22 = (undefined8 *)(*(long *)(param_1 + 0xb0) + 0xb0);
LAB_001189f4:
              *puVar22 = 0;
            }
            else if (*(int *)(param_1 + 0x4c) == 0) {
              puVar22 = (undefined8 *)(*(long *)(param_1 + 0xb0) + 0xa8);
              goto LAB_001189f4;
            }
            plVar23 = *(long **)(param_1 + 0xb0);
            mutex_lock(sps_rm + 2);
            lVar16 = 0xa8;
            if (*(int *)(param_1 + 0x4c) != 0) {
              lVar16 = 0xb0;
            }
            *(undefined8 *)((long)plVar23 + lVar16) = 0;
            *(undefined8 *)(param_1 + 0xb0) = 0;
            *(undefined4 *)(param_1 + 0x10) = 0;
            sps_rm_free_map_rsrc(plVar23);
            iVar9 = (int)plVar23[0x17] + -1;
            *(int *)(plVar23 + 0x17) = iVar9;
            if (iVar9 < 1) {
              if ((plVar23[0x15] != 0) || (plVar23[0x16] != 0)) {
                if ((logging_option != '\x01') &&
                   ((print_limit_option < 3 ||
                    (iVar9 = ___ratelimit(sps_rm_remove_ref__rs,"sps_rm_remove_ref"), iVar9 != 0))))
                {
                  _printk(&DAT_001215a3,"sps_rm_remove_ref","sps_rm_remove_ref");
                }
                if (sps != 0) {
                  ipc_log_string(*(undefined8 *)(sps + 0x110),
                                 "%s: sps:%s:Failed to allocate connection struct\n",
                                 "sps_rm_remove_ref","sps_rm_remove_ref");
                }
              }
              uVar10 = __list_del_entry_valid(plVar23);
              if ((uVar10 & 1) != 0) {
                lVar16 = *plVar23;
                plVar15 = (long *)plVar23[1];
                *(long **)(lVar16 + 8) = plVar15;
                *plVar15 = lVar16;
              }
              *plVar23 = (long)&DAT_dead000000000100;
              plVar23[1] = -0x2152fffffffffede;
              kfree(plVar23);
            }
            mutex_unlock(sps_rm + 2);
            uVar20 = 0;
            *(undefined8 *)(param_1 + 0xb0) = 0;
            *(undefined8 *)(param_1 + 0x18) = 0;
            *(undefined4 *)(param_1 + 0x10) = 0;
            goto LAB_00118ca8;
          }
        }
      }
      else if (iVar9 == 0x2535053) {
        if ((param_2 != 0) && (param_2 != 0x4535053)) {
          bVar8 = false;
          goto LAB_001187f4;
        }
        goto LAB_0011890c;
      }
      uVar20 = 0;
      goto LAB_00118ca8;
    }
    local_78 = *(undefined4 *)(param_1 + 0x4c);
    local_6c = 0;
    local_74 = 0;
    if (*(int *)(param_1 + 0x54) != -0x33333334) {
      local_6c = *(undefined4 *)(param_1 + 0xa4);
      local_74 = CONCAT44(*(undefined4 *)(param_1 + 0xa0),*(int *)(param_1 + 0x54));
    }
    iVar9 = sps_bam_pipe_connect(param_1,&local_78);
    if (iVar9 == 0) {
      *(undefined4 *)(param_1 + 0x10) = 0x2535053;
      if (((*(long *)(param_1 + 0x20) == 0x7fffffffffffffff) ||
          (*(long *)(param_1 + 0x38) == 0x7fffffffffffffff)) &&
         (*(int *)(*(long *)(param_1 + 0xb0) + 0x78) != 0)) {
        bVar7 = false;
        bVar8 = *(long *)(*(long *)(param_1 + 0xb0) + 0x68) != 0xdeadbeef;
      }
      else {
        bVar8 = false;
        bVar7 = false;
      }
LAB_001187f4:
      if (((param_2 != 0x3535053) && (!bVar8)) && ((*(byte *)(param_1 + 0x57) >> 5 & 1) == 0))
      goto LAB_0011890c;
      iVar9 = sps_bam_pipe_enable(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0xbc));
      if (iVar9 == 0) {
        *(undefined4 *)(param_1 + 0x10) = 0x3535053;
        goto LAB_00118884;
      }
      if ((logging_option != '\x01') &&
         ((print_limit_option < 3 ||
          (iVar9 = ___ratelimit(sps_rm_state_change__rs_6,"sps_rm_state_change"), iVar9 != 0)))) {
        _printk(&DAT_00120c49,"sps_rm_state_change",*(long *)(param_1 + 0x18) + 0x18,
                *(undefined4 *)(param_1 + 0xbc));
      }
      lVar16 = *(long *)(param_1 + 0x18);
      if (lVar16 == 0) goto LAB_00118ca4;
      uVar20 = *(undefined8 *)(lVar16 + 0x228);
      lVar16 = lVar16 + 0x18;
      uVar14 = *(undefined4 *)(param_1 + 0xbc);
      pcVar11 = "%s: sps:Failed to set BAM %pa pipe %d flow on\n";
      goto LAB_00118c98;
    }
    if ((logging_option != '\x01') &&
       ((print_limit_option < 3 ||
        (iVar9 = ___ratelimit(sps_rm_state_change__rs_3,"sps_rm_state_change"), iVar9 != 0)))) {
      _printk(&DAT_0011f018,"sps_rm_state_change",*(undefined8 *)(param_1 + 0x18),
              *(undefined4 *)(param_1 + 0xbc));
    }
    lVar16 = *(long *)(param_1 + 0x18);
    if (lVar16 != 0) {
      uVar20 = *(undefined8 *)(lVar16 + 0x228);
      pcVar11 = "%s: sps:Failed to connect BAM 0x%pK pipe %d\n";
      goto LAB_00118c94;
    }
  }
LAB_00118ca4:
  uVar20 = 0xffffffff;
LAB_00118ca8:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar20);
  }
  return;
}



//------------------------------------------------------------
// sps_rm_assign @ 00118f1c size=712
// signature: undefined sps_rm_assign(void)
// callers: [sps_rm_state_change]
//------------------------------------------------------------

undefined8 sps_rm_assign(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  char *pcVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  if (*(int *)(param_1 + 0x4c) == 0) {
    if (*(long *)(param_2 + 0xa8) != 0) goto LAB_00118f8c;
    if (*(long *)(param_2 + 0x30) != 0) {
      *(long *)(param_2 + 0xa8) = param_1;
      *(long *)(param_1 + 0x18) = *(long *)(param_2 + 0x30);
      *(undefined4 *)(param_1 + 0xbc) = *(undefined4 *)(param_2 + 0x20);
      if (*(int *)(param_1 + 0x98) != -0x33333334) {
        *(int *)(param_2 + 0x24) = *(int *)(param_1 + 0x98);
      }
      if (*(int *)(param_1 + 0x9c) != -0x33333334) {
        *(int *)(param_2 + 0x28) = *(int *)(param_1 + 0x9c);
      }
      goto LAB_00119030;
    }
  }
  else {
    if (*(long *)(param_2 + 0xb0) != 0) {
LAB_00118f8c:
      if ((logging_option != 1) &&
         ((print_limit_option < 3 ||
          (iVar4 = ___ratelimit(sps_rm_assign__rs,"sps_rm_assign"), iVar4 != 0)))) {
        _printk(&DAT_00122bed,"sps_rm_assign","sps_rm_assign");
      }
      if (sps == 0) {
        return 0xffffffff;
      }
      uVar7 = *(undefined8 *)(sps + 0x110);
      pcVar5 = "%s: sps:%s:The end point is already connected\n";
      goto LAB_00118fdc;
    }
    if (*(long *)(param_2 + 0x58) != 0) {
      *(long *)(param_2 + 0xb0) = param_1;
      *(long *)(param_1 + 0x18) = *(long *)(param_2 + 0x58);
      *(undefined4 *)(param_1 + 0xbc) = *(undefined4 *)(param_2 + 0x48);
      if (*(int *)(param_1 + 0x98) != -0x33333334) {
        *(int *)(param_2 + 0x4c) = *(int *)(param_1 + 0x98);
      }
      if (*(int *)(param_1 + 0x9c) != -0x33333334) {
        *(int *)(param_2 + 0x50) = *(int *)(param_1 + 0x9c);
      }
LAB_00119030:
      *(long *)(param_1 + 0xb0) = param_2;
      if (((1 < logging_option) && (3 < debug_level_option)) &&
         ((print_limit_option == 0 ||
          (iVar4 = ___ratelimit(sps_rm_assign__rs_29,"sps_rm_assign"), iVar4 != 0)))) {
        _printk(&DAT_0011e691,"sps_rm_assign","sps_rm_assign",*(long *)(param_1 + 0x18) + 0x18,
                *(undefined4 *)(param_1 + 0xbc));
      }
      lVar6 = *(long *)(param_1 + 0x18);
      if ((lVar6 != 0) && (*(int *)(lVar6 + 0x238) == 0)) {
        ipc_log_string(*(undefined8 *)(lVar6 + 0x210),"%s: sps:%s.bam %pa.pipe_index=%d\n",
                       "sps_rm_assign","sps_rm_assign",lVar6 + 0x18,*(undefined4 *)(param_1 + 0xbc))
        ;
        lVar6 = *(long *)(param_1 + 0x18);
      }
      *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_2 + 0x20);
      *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_2 + 0x48);
      if ((*(byte *)(lVar6 + 0x11) >> 1 & 1) == 0) {
        uVar7 = 0;
        uVar8 = 0;
      }
      else {
        uVar8 = *(undefined8 *)(param_1 + 0x68);
        uVar7 = *(undefined8 *)(param_1 + 0x88);
      }
      uVar2 = *(undefined8 *)(param_2 + 0x78);
      uVar1 = *(undefined8 *)(param_2 + 0x60);
      uVar3 = *(undefined8 *)(param_2 + 0x68);
      *(undefined8 *)(param_1 + 0x68) = *(undefined8 *)(param_2 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = uVar2;
      *(undefined8 *)(param_1 + 0x58) = uVar1;
      *(undefined8 *)(param_1 + 0x60) = uVar3;
      uVar2 = *(undefined8 *)(param_2 + 0x98);
      uVar1 = *(undefined8 *)(param_2 + 0x80);
      uVar3 = *(undefined8 *)(param_2 + 0x88);
      *(undefined8 *)(param_1 + 0x88) = *(undefined8 *)(param_2 + 0x90);
      *(undefined8 *)(param_1 + 0x90) = uVar2;
      *(undefined8 *)(param_1 + 0x78) = uVar1;
      *(undefined8 *)(param_1 + 0x80) = uVar3;
      if ((*(byte *)(lVar6 + 0x11) >> 1 & 1) != 0) {
        *(undefined8 *)(param_1 + 0x68) = uVar8;
        *(undefined8 *)(param_1 + 0x88) = uVar7;
      }
      *(undefined4 *)(param_1 + 0x10) = 0x1535053;
      return 0;
    }
  }
  if ((logging_option != 1) &&
     ((print_limit_option < 3 ||
      (iVar4 = ___ratelimit(sps_rm_assign__rs_26,"sps_rm_assign"), iVar4 != 0)))) {
    _printk(&DAT_00125040,"sps_rm_assign","sps_rm_assign");
  }
  if (sps == 0) {
    return 0xffffffff;
  }
  uVar7 = *(undefined8 *)(sps + 0x110);
  pcVar5 = "%s: sps:%s:The end point is empty\n";
LAB_00118fdc:
  ipc_log_string(uVar7,pcVar5,"sps_rm_assign","sps_rm_assign");
  return 0xffffffff;
}



//------------------------------------------------------------
// sps_rm_free_map_rsrc @ 001191e4 size=188
// signature: undefined sps_rm_free_map_rsrc(void)
// callers: [sps_rm_state_change]
//------------------------------------------------------------

void sps_rm_free_map_rsrc(long param_1)

{
  if ((*(long *)(param_1 + 0xa8) == 0) && (*(long *)(param_1 + 0xb0) == 0)) {
    if (*(int *)(param_1 + 0xbc) != -1) {
      sps_bam_pipe_free(*(undefined8 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x20));
      *(undefined4 *)(param_1 + 0xbc) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
    }
    if (*(int *)(param_1 + 0xc0) != -1) {
      sps_bam_pipe_free(*(undefined8 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x48));
      *(undefined4 *)(param_1 + 0xc0) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x48) = 0xffffffff;
    }
    if (*(long *)(param_1 + 200) != 0xdeadbeef) {
      sps_mem_free_io(*(long *)(param_1 + 200),*(undefined4 *)(param_1 + 0x78));
      *(undefined8 *)(param_1 + 200) = 0xdeadbeef;
      *(undefined8 *)(param_1 + 0x68) = 0xdeadbeef;
    }
    if (*(long *)(param_1 + 0xd0) != 0xdeadbeef) {
      sps_mem_free_io(*(long *)(param_1 + 0xd0),*(undefined4 *)(param_1 + 0x98));
      *(undefined8 *)(param_1 + 0xd0) = 0xdeadbeef;
      *(undefined8 *)(param_1 + 0x88) = 0xdeadbeef;
    }
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001268c8 size=912
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 init_module(void)

{
  undefined *puVar1;
  long lVar2;
  undefined8 uVar3;
  
  debugfs_record_enabled = 0;
  logging_option = 0;
  debug_level_option = 0;
  reg_dump_option = 0;
  testbus_sel = 0;
  print_limit_option = 0;
  bam_pipe_sel = 0;
  desc_option = 0;
  debugfs_buf_size = 0;
  log_level_sel = 5;
  debugfs_buf_used = 0;
  wraparound = 0;
  dent = debugfs_create_dir(&DAT_0011d5f7,0);
  if (dent < 0xfffffffffffff001) {
    dfile_info = debugfs_create_file(&DAT_001210cc,0x1b4,dent,0,sps_info_ops);
    puVar1 = &DAT_0012551b;
    if ((dfile_info != 0) && (dfile_info < 0xfffffffffffff001)) {
      dfile_logging_option =
           debugfs_create_file("logging_option",0x1b4,dent,0,sps_logging_option_ops);
      puVar1 = &DAT_0011ea7f;
      if ((dfile_logging_option != 0) && (dfile_logging_option < 0xfffffffffffff001)) {
        debugfs_create_u8("debug_level_option",0x1b4,dent,&debug_level_option);
        debugfs_create_u8("print_limit_option",0x1b4,dent,&print_limit_option);
        debugfs_create_u8("reg_dump_option",0x1b4,dent,&reg_dump_option);
        debugfs_create_u32("testbus_sel",0x1b4,dent,&testbus_sel);
        debugfs_create_u32("bam_pipe_sel",0x1b4,dent,&bam_pipe_sel);
        debugfs_create_u32("desc_option",0x1b4,dent,&desc_option);
        dfile_bam_addr = debugfs_create_file("bam_addr",0x1b4,dent,0,sps_bam_addr_ops);
        puVar1 = &DAT_00121c2a;
        if ((dfile_bam_addr != 0) && (dfile_bam_addr < 0xfffffffffffff001)) {
          debugfs_create_u32("log_level_sel",0x1b4,dent,&log_level_sel);
          __mutex_init(&sps_debugfs_lock,"&sps_debugfs_lock",&sps_debugfs_init___key);
          goto LAB_00126afc;
        }
      }
    }
    _printk(puVar1);
    debugfs_remove(dent);
  }
  else {
    _printk(&DAT_001259a8);
  }
LAB_00126afc:
  sps = kmalloc_trace(_debugfs_create_dir,0xdc0,0x128);
  if (sps == 0) {
    uVar3 = 0xfffffff4;
  }
  else {
    lVar2 = ipc_log_context_create(10,"sps_ipc_log0",0);
    *(long *)(sps + 0xf8) = lVar2;
    if (lVar2 == 0) {
      _printk(&DAT_001218cc);
    }
    lVar2 = ipc_log_context_create(10,"sps_ipc_log1",0);
    *(long *)(sps + 0x100) = lVar2;
    if (lVar2 == 0) {
      _printk(&DAT_00122062);
    }
    lVar2 = ipc_log_context_create(10,"sps_ipc_log2",0);
    *(long *)(sps + 0x108) = lVar2;
    if (lVar2 == 0) {
      _printk(&DAT_001254fe);
    }
    lVar2 = ipc_log_context_create(10,"sps_ipc_log3",0);
    *(long *)(sps + 0x110) = lVar2;
    if (lVar2 == 0) {
      _printk(&DAT_0012598b);
    }
    lVar2 = ipc_log_context_create(0x1e,"sps_ipc_log4",0);
    *(long *)(sps + 0x118) = lVar2;
    if (lVar2 == 0) {
      _printk(&DAT_00124f84);
    }
    uVar3 = __platform_driver_register(&msm_sps_driver,&__this_module);
  }
  return uVar3;
}



//------------------------------------------------------------
// cleanup_module @ 00126c5c size=88
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&msm_sps_driver);
  kfree(sps);
  sps = 0;
  debugfs_remove(dent);
  kfree(debugfs_buf);
  debugfs_buf = 0;
  return;
}



//------------------------------------------------------------
// ipc_log_string @ 00129000 size=1
// signature: undefined ipc_log_string(void)
// callers: [bam_output_register_content, print_bam_pipe_desc_fifo, sps_bam_pipe_get_event, print_bam_selected_reg, sps_bam_pipe_set_params, sps_register_bam_device, bam_init, sps_bam_pipe_disconnect, sps_bam_pipe_is_empty, bam_pipe_disable, bam_disable_pipe, sps_get_free_count, bam_read_reg_field, sps_get_config, pipe_set_irq, sps_deregister_bam_device, bam_pipe_check_zlt, sps_bam_pipe_alloc, bam_pipe_init, bam_isr, bam_write_reg_field, sps_bam_pipe_disable, sps_alloc_endpoint, bam_security_init, sps_bam_enable_irqs, sps_get_bam_debug_info, sps_free_endpoint, sps_bam_pipe_transfer, print_bam_pipe_reg, sps_bam_pipe_connect, sps_bam_disable_irqs, sps_transfer, bam_exit, sps_bam_pipe_get_iovec, msm_sps_probe, sps_get_unused_desc_num, pipe_handler_eot, sps_bam_pipe_inject_zlt, sps_bam_process_irq, sps_bam_disable, sps_pipe_disable, sps_mem_init, sps_bam_set_satellite, bam_check, spsi_get_mem_ptr, sps_phy2h, bam_get_register_offset, bam_pipe_set_irq, sps_bam_check_irq, sps_alloc_mem, sps_get_event, sps_disconnect, sps_is_pipe_empty, sps_rm_assign, sps_register_event, sps_bam_enable, sps_bam_lock, sps_pipe_inject_zlt, bam_pipe_enable, sps_bam_pipe_reg_event, sps_free_mem, sps_device_reset, bam_write_reg, trigger_event, sps_rm_state_change, bam_check_irq_source, sps_flow_off, sps_bam_device_init, sps_connect, sps_bam_device_de_init, sps_mem_free_io, print_bam_reg, print_bam_pipe_selected_reg, sps_pipe_reset, bam_pipe_check_pipe_empty, sps_setup_bam2bam_fifo, sps_h2bam, sps_bam_pipe_transfer_one, sps_get_bam_addr, sps_mem_alloc_io, print_bam_test_bus_reg, sps_mem_de_init, sps_transfer_one, sps_map_init, sps_ctrl_bam_dma_clk, sps_check_iovec_flags, sps_get_iovec, bam_read_reg, sps_set_config, sps_bam_reset, sps_map_find, bam_pipe_exit, sps_bam_pipe_get_unused_desc_num, sps_set_bam_addr, sps_bam_pipe_free, sps_pipe_pending_desc, bam_pipe_reset, sps_flow_on, sps_bam_get_free_count, msm_sps_remove, sps_set_owner]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00129008 size=1
// signature: undefined _printk(void)
// callers: [bam_output_register_content, print_bam_pipe_desc_fifo, sps_bam_pipe_get_event, print_bam_selected_reg, sps_bam_pipe_set_params, sps_register_bam_device, bam_init, sps_bam_pipe_disconnect, sps_bam_pipe_is_empty, bam_pipe_disable, bam_disable_pipe, sps_get_free_count, bam_read_reg_field, sps_get_config, pipe_set_irq, sps_deregister_bam_device, bam_pipe_check_zlt, sps_bam_pipe_alloc, bam_pipe_init, bam_isr, bam_write_reg_field, sps_bam_pipe_disable, sps_alloc_endpoint, bam_security_init, sps_bam_enable_irqs, sps_get_bam_debug_info, sps_free_endpoint, sps_bam_pipe_transfer, print_bam_pipe_reg, sps_bam_pipe_connect, sps_bam_disable_irqs, sps_transfer, bam_exit, sps_bam_pipe_get_iovec, msm_sps_probe, sps_get_unused_desc_num, pipe_handler_eot, sps_bam_pipe_inject_zlt, sps_bam_process_irq, sps_bam_disable, sps_pipe_disable, sps_mem_init, sps_bam_set_satellite, bam_check, spsi_get_mem_ptr, sps_phy2h, bam_get_register_offset, init_module, bam_pipe_set_irq, sps_bam_check_irq, sps_alloc_mem, sps_get_event, sps_disconnect, sps_is_pipe_empty, sps_rm_assign, sps_register_event, sps_bam_enable, sps_bam_lock, sps_pipe_inject_zlt, bam_pipe_enable, sps_bam_pipe_reg_event, sps_free_mem, sps_device_reset, bam_write_reg, trigger_event, sps_rm_state_change, bam_check_irq_source, sps_flow_off, sps_bam_device_init, sps_set_info, sps_connect, sps_bam_device_de_init, sps_mem_free_io, print_bam_reg, print_bam_pipe_selected_reg, sps_pipe_reset, bam_pipe_check_pipe_empty, sps_setup_bam2bam_fifo, sps_h2bam, sps_bam_pipe_transfer_one, sps_get_bam_addr, sps_mem_alloc_io, print_bam_test_bus_reg, sps_mem_de_init, sps_transfer_one, sps_map_init, sps_ctrl_bam_dma_clk, sps_check_iovec_flags, sps_get_iovec, bam_read_reg, sps_set_config, sps_bam_reset, sps_map_find, bam_pipe_exit, sps_bam_pipe_get_unused_desc_num, sps_set_bam_addr, sps_bam_pipe_free, sps_pipe_pending_desc, bam_pipe_reset, sps_flow_on, sps_bam_get_free_count, msm_sps_remove, sps_set_owner, sps_set_logging_option]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00129010 size=1
// signature: undefined ___ratelimit(void)
// callers: [bam_check, bam_output_register_content, spsi_get_mem_ptr, print_bam_pipe_desc_fifo, sps_phy2h, bam_get_register_offset, bam_pipe_set_irq, sps_bam_check_irq, sps_bam_pipe_get_event, sps_alloc_mem, sps_get_event, sps_bam_pipe_set_params, sps_disconnect, sps_is_pipe_empty, sps_rm_assign, sps_register_bam_device, bam_init, sps_register_event, sps_bam_pipe_disconnect, sps_bam_pipe_is_empty, bam_pipe_disable, sps_bam_enable, sps_bam_lock, sps_pipe_inject_zlt, bam_disable_pipe, bam_pipe_enable, sps_bam_pipe_reg_event, sps_get_free_count, sps_free_mem, sps_device_reset, bam_write_reg, trigger_event, bam_read_reg_field, sps_rm_state_change, bam_check_irq_source, sps_get_config, pipe_set_irq, sps_deregister_bam_device, bam_pipe_check_zlt, sps_flow_off, sps_bam_device_init, sps_bam_pipe_alloc, bam_pipe_init, sps_connect, sps_bam_device_de_init, sps_mem_free_io, bam_isr, bam_write_reg_field, sps_pipe_reset, bam_pipe_check_pipe_empty, sps_setup_bam2bam_fifo, sps_h2bam, sps_bam_pipe_disable, sps_bam_pipe_transfer_one, sps_alloc_endpoint, sps_get_bam_addr, sps_mem_alloc_io, sps_mem_de_init, sps_transfer_one, sps_map_init, bam_security_init, sps_ctrl_bam_dma_clk, sps_bam_enable_irqs, sps_get_bam_debug_info, sps_check_iovec_flags, sps_free_endpoint, sps_bam_pipe_transfer, sps_get_iovec, bam_read_reg, sps_bam_pipe_connect, sps_set_config, sps_bam_disable_irqs, sps_transfer, sps_bam_reset, bam_exit, sps_bam_pipe_get_iovec, sps_map_find, bam_pipe_exit, sps_bam_pipe_get_unused_desc_num, msm_sps_probe, sps_get_unused_desc_num, sps_set_bam_addr, sps_bam_pipe_free, pipe_handler_eot, sps_bam_pipe_inject_zlt, sps_bam_process_irq, sps_pipe_pending_desc, bam_pipe_reset, sps_flow_on, sps_bam_get_free_count, sps_bam_disable, sps_pipe_disable, sps_mem_init, msm_sps_remove, sps_bam_set_satellite, sps_set_owner]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00129020 size=1
// signature: undefined scnprintf(void)
// callers: [print_bam_pipe_desc_fifo, sps_read_logging_option, sps_debugfs_record]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00129028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [spsi_get_mem_ptr, print_bam_pipe_desc_fifo, sps_phy2h, sps_rm_state_change, sps_bam_check_irq, sps_mem_alloc_io, sps_set_bam_addr, sps_read_logging_option, sps_set_info, sps_bam_pipe_transfer, sps_mem_free_io, sps_register_bam_device, bam_isr, sps_bam_enable, sps_bam_pipe_connect, sps_set_logging_option]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00129030 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 00129038 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00129040 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 00129048 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00129050 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [sps_bam_enable_all_irqs, sps_bam_lock, sps_bam_disable_all_irqs, sps_rm_state_change, sps_bam_check_irq, sps_bam_pipe_disconnect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00129058 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [sps_bam_enable_all_irqs, sps_transfer, sps_bam_lock, sps_get_free_count, sps_bam_disable_all_irqs, sps_rm_state_change, sps_bam_check_irq, sps_flow_off, sps_get_unused_desc_num, sps_transfer_one, sps_get_event, sps_is_pipe_empty, sps_flow_on, sps_get_iovec, sps_register_event, sps_bam_pipe_disconnect, sps_set_owner, sps_set_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_threaded_irq @ 00129060 size=1
// signature: undefined request_threaded_irq(void)
// callers: [sps_bam_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 00129068 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [sps_bam_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_irq @ 00129070 size=1
// signature: undefined free_irq(void)
// callers: [sps_bam_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00129078 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [sps_rm_state_change, sps_bam_pipe_disconnect, sps_bam_set_satellite, sps_deregister_bam_device, sps_bam_pipe_get_event, sps_bam_pipe_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00129080 size=1
// signature: undefined kfree(void)
// callers: [sps_free_endpoint, cleanup_module, sps_register_bam_device, sps_rm_state_change, sps_bam_pipe_disconnect, sps_deregister_bam_device, sps_bam_pipe_get_event, sps_bam_pipe_free, sps_set_info, sps_set_logging_option]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00129088 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [sps_setup_bam2bam_fifo, sps_register_bam_device, sps_alloc_endpoint, sps_bam_pipe_disconnect, sps_bam_pipe_free, sps_bam_pipe_connect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memset_io @ 00129090 size=1
// signature: undefined __memset_io(void)
// callers: [sps_bam_pipe_connect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memset_io(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00129098 size=1
// signature: undefined __list_add_valid(void)
// callers: [sps_register_bam_device, sps_rm_state_change, sps_bam_pipe_connect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001290a0 size=1
// signature: undefined __kmalloc(void)
// callers: [sps_bam_pipe_set_params, sps_set_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vzalloc @ 001290a8 size=1
// signature: undefined vzalloc(void)
// callers: [sps_bam_pipe_set_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vzalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vfree @ 001290b0 size=1
// signature: undefined vfree(void)
// callers: [sps_bam_pipe_disconnect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 001290b8 size=1
// signature: undefined complete(void)
// callers: [trigger_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001290c0 size=1
// signature: undefined mutex_lock(void)
// callers: [sps_connect, sps_disconnect, sps_get_bam_debug_info, sps_device_reset, sps_register_bam_device, sps_rm_state_change, sps_read_info, sps_deregister_bam_device, sps_debugfs_record, sps_set_info, sps_set_logging_option]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001290c8 size=1
// signature: undefined mutex_unlock(void)
// callers: [sps_connect, sps_disconnect, sps_get_bam_debug_info, sps_device_reset, sps_register_bam_device, sps_rm_state_change, sps_read_info, sps_deregister_bam_device, sps_debugfs_record, sps_set_info, sps_set_logging_option]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001290d0 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [sps_connect, sps_register_bam_device, sps_get_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 001290d8 size=1
// signature: undefined clk_prepare(void)
// callers: [msm_sps_probe, sps_ctrl_bam_dma_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 001290e0 size=1
// signature: undefined clk_enable(void)
// callers: [msm_sps_probe, sps_ctrl_bam_dma_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001290e8 size=1
// signature: undefined clk_unprepare(void)
// callers: [msm_sps_probe, sps_ctrl_bam_dma_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001290f0 size=1
// signature: undefined clk_disable(void)
// callers: [msm_sps_probe, sps_ctrl_bam_dma_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00129100 size=1
// signature: undefined kmalloc_trace(void)
// callers: [sps_register_bam_device, init_module, sps_rm_state_change, sps_alloc_endpoint]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00129108 size=1
// signature: undefined __mutex_init(void)
// callers: [sps_rm_init, sps_register_bam_device, init_module, msm_sps_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00129110 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [sps_register_bam_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00129118 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [sps_register_bam_device, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 00129120 size=1
// signature: undefined iounmap(void)
// callers: [sps_register_bam_device, sps_deregister_bam_device, sps_mem_de_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ioremap_prot @ 00129130 size=1
// signature: undefined ioremap_prot(void)
// callers: [sps_register_bam_device, sps_mem_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ioremap_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 00129138 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [sps_deregister_bam_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00129140 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00129148 size=1
// signature: undefined debugfs_create_file(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_u8 @ 00129150 size=1
// signature: undefined debugfs_create_u8(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_u8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_u32 @ 00129158 size=1
// signature: undefined debugfs_create_u32(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_u32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00129160 size=1
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
// debugfs_remove @ 00129168 size=1
// signature: undefined debugfs_remove(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 00129170 size=1
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
// simple_read_from_buffer @ 00129178 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [sps_read_info, sps_read_logging_option]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00129180 size=1
// signature: undefined __check_object_size(void)
// callers: [sps_set_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00129198 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [sps_set_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint_from_user @ 001291a8 size=1
// signature: undefined kstrtouint_from_user(void)
// callers: [sps_set_bam_addr, sps_set_logging_option]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001291b0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [msm_sps_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 001291b8 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [msm_sps_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001291c0 size=1
// signature: undefined of_find_property(void)
// callers: [msm_sps_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_match_device @ 001291c8 size=1
// signature: undefined of_match_device(void)
// callers: [msm_sps_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 001291d0 size=1
// signature: undefined __class_create(void)
// callers: [msm_sps_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 001291d8 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [msm_sps_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 001291e0 size=1
// signature: undefined device_create(void)
// callers: [msm_sps_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_get @ 001291e8 size=1
// signature: undefined clk_get(void)
// callers: [msm_sps_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_put @ 001291f0 size=1
// signature: undefined clk_put(void)
// callers: [msm_sps_probe, msm_sps_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 001291f8 size=1
// signature: undefined device_destroy(void)
// callers: [msm_sps_probe, msm_sps_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 00129200 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [msm_sps_probe, msm_sps_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 00129208 size=1
// signature: undefined class_destroy(void)
// callers: [msm_sps_probe, msm_sps_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_alloc_algo_owner @ 00129210 size=1
// signature: undefined gen_pool_alloc_algo_owner(void)
// callers: [sps_mem_alloc_io]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_alloc_algo_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_free_owner @ 00129218 size=1
// signature: undefined gen_pool_free_owner(void)
// callers: [sps_mem_free_io]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_free_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_create @ 00129220 size=1
// signature: undefined gen_pool_create(void)
// callers: [sps_mem_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_add_owner @ 00129228 size=1
// signature: undefined gen_pool_add_owner(void)
// callers: [sps_mem_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_add_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_destroy @ 00129230 size=1
// signature: undefined gen_pool_destroy(void)
// callers: [sps_mem_de_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// synchronize_irq @ 00129238 size=1
// signature: undefined synchronize_irq(void)
// callers: [sps_rm_state_change]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void synchronize_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



