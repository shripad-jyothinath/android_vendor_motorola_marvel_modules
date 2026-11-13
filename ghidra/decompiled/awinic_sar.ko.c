// Decompiled by Ghidra 12.2
// Program: awinic_sar.ko
// Image base: 00100000

//------------------------------------------------------------
// aw_sar_i2c_read @ 0010133c size=944
// signature: undefined aw_sar_i2c_read(void)
// callers: [reset_store, aw_sar_diff_get, aw963xx_sar_get_firmware_info, aw963xx_update_firmware, aw963xx_get_cap_offset, aw963xx_sar_chip_info_get, aw_sar_check_init_over_irq, aw963xx_check_chipid, aw963xx_irq_handle_func, aw963xx_get_signed_cap, aw_sar_reg_get, reg_show, aw_sar_i2c_write_bits, aw96xxx_monitor_work_func, aw963xx_rc_irqscr]
//------------------------------------------------------------

void aw_sar_i2c_read(long param_1,uint param_2,uint *param_3)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  ushort local_80;
  undefined2 uStack_7e;
  undefined2 local_7c;
  undefined8 local_78;
  undefined1 *puStack_70;
  undefined8 local_68;
  ulong uStack_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_7c = 0;
  local_80 = 0;
  uStack_7e = 0;
  if (param_1 == 0) {
    _printk(&DAT_00109f89);
    uVar4 = 0xffffffff;
  }
  else {
    local_80 = (ushort)(param_2 >> 8) & 0xff | (ushort)((param_2 & 0xff00ff) << 8);
    uVar5 = (ulong)&local_80 | 2;
    local_78 = (ulong)CONCAT24(2,(uint)*(ushort *)(param_1 + 2));
    local_68._0_6_ = CONCAT42(0x40001,*(ushort *)(param_1 + 2));
    local_68 = (ulong)(uint6)local_68;
    puStack_70 = (undefined1 *)&local_80;
    uStack_60 = uVar5;
    iVar3 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_78,2);
    if (iVar3 < 0) {
      param_2 = param_2 & 0xffff;
      _dev_err(param_1 + 0x20," [%s:%s:%d] i2c read error reg: 0x%04x, ret= %d cnt= %d\n",
               "aw_sar_comm_interface.c","aw_sar_i2c_read",0x3e,param_2,iVar3,5);
      usleep_range_state(2000,3000,2);
      local_78 = CONCAT62(0x20000,*(undefined2 *)(param_1 + 2));
      local_68._0_6_ = CONCAT42(0x40001,*(undefined2 *)(param_1 + 2));
      local_68 = (ulong)(uint6)local_68;
      puStack_70 = (undefined1 *)&local_80;
      uStack_60 = uVar5;
      iVar3 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_78,2);
      if (iVar3 < 0) {
        _dev_err(param_1 + 0x20," [%s:%s:%d] i2c read error reg: 0x%04x, ret= %d cnt= %d\n",
                 "aw_sar_comm_interface.c","aw_sar_i2c_read",0x3e,param_2,iVar3,4);
        usleep_range_state(2000,3000,2);
        local_78 = CONCAT62(0x20000,*(undefined2 *)(param_1 + 2));
        local_68._0_6_ = CONCAT42(0x40001,*(undefined2 *)(param_1 + 2));
        local_68 = (ulong)(uint6)local_68;
        puStack_70 = (undefined1 *)&local_80;
        uStack_60 = uVar5;
        iVar3 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_78,2);
        if (iVar3 < 0) {
          _dev_err(param_1 + 0x20," [%s:%s:%d] i2c read error reg: 0x%04x, ret= %d cnt= %d\n",
                   "aw_sar_comm_interface.c","aw_sar_i2c_read",0x3e,param_2,iVar3,3);
          usleep_range_state(2000,3000,2);
          local_78 = CONCAT62(0x20000,*(undefined2 *)(param_1 + 2));
          local_68._0_6_ = CONCAT42(0x40001,*(undefined2 *)(param_1 + 2));
          local_68 = (ulong)(uint6)local_68;
          puStack_70 = (undefined1 *)&local_80;
          uStack_60 = uVar5;
          iVar3 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_78,2);
          if (iVar3 < 0) {
            _dev_err(param_1 + 0x20," [%s:%s:%d] i2c read error reg: 0x%04x, ret= %d cnt= %d\n",
                     "aw_sar_comm_interface.c","aw_sar_i2c_read",0x3e,param_2,iVar3,2);
            usleep_range_state(2000,3000,2);
            local_78 = CONCAT62(0x20000,*(undefined2 *)(param_1 + 2));
            local_68._0_6_ = CONCAT42(0x40001,*(undefined2 *)(param_1 + 2));
            local_68 = (ulong)(uint6)local_68;
            puStack_70 = (undefined1 *)&local_80;
            uStack_60 = uVar5;
            iVar3 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_78,2);
            if (iVar3 < 0) {
              lVar1 = param_1 + 0x20;
              _dev_err(lVar1," [%s:%s:%d] i2c read error reg: 0x%04x, ret= %d cnt= %d\n",
                       "aw_sar_comm_interface.c","aw_sar_i2c_read",0x3e,param_2,iVar3,1);
              usleep_range_state(2000,3000,2);
              local_78 = CONCAT62(0x20000,*(undefined2 *)(param_1 + 2));
              local_68._0_6_ = CONCAT42(0x40001,*(undefined2 *)(param_1 + 2));
              local_68 = (ulong)(uint6)local_68;
              puStack_70 = (undefined1 *)&local_80;
              uStack_60 = uVar5;
              iVar3 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_78,2);
              if (iVar3 < 0) {
                _dev_err(lVar1," [%s:%s:%d] i2c read error reg: 0x%04x, ret= %d cnt= %d\n",
                         "aw_sar_comm_interface.c","aw_sar_i2c_read",0x3e,param_2,iVar3,0);
                usleep_range_state(2000,3000,2);
                _dev_err(lVar1," [%s:%s:%d] i2c read error!\n","aw_sar_comm_interface.c",
                         "aw_sar_i2c_read",0x46);
                uVar4 = 0xffffffff;
                goto LAB_001013e0;
              }
            }
          }
        }
      }
    }
    uVar4 = 0;
    uVar2 = (CONCAT22(local_7c,uStack_7e) & 0xff00ff00) >> 8 |
            (CONCAT22(local_7c,uStack_7e) & 0xff00ff) << 8;
    *param_3 = uVar2 >> 0x10 | uVar2 << 0x10;
  }
LAB_001013e0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// aw_sar_i2c_write @ 001016f0 size=768
// signature: undefined aw_sar_i2c_write(void)
// callers: [reg_store, aw_sar_soft_rst_set, aw_sar_soft_reset, aw_sar_update_reg_set, aw963xx_update_firmware, aw_sar_para_loaded, aw_sar_update_work, aw963xx_set_deepsleep_cmd, aw_sar_chip_init, aw963xx_set_sleep_cmd, aw_sar_reg_set, aw963xx_load_reg_bin, aw963xx_set_active_cmd, aw_sar_load_reg, aw_sar_i2c_write_bits, aw96xxx_monitor_work_func]
//------------------------------------------------------------

void aw_sar_i2c_write(long param_1,uint param_2,ulong param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined2 local_70;
  undefined6 uStack_6e;
  undefined1 *puStack_68;
  undefined1 local_60;
  undefined1 local_5f;
  undefined1 local_5e;
  undefined1 local_5d;
  undefined1 local_5c;
  undefined1 local_5b;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  if (param_1 == 0) {
    _printk(&DAT_00109f89);
LAB_001017c0:
    uVar3 = 0xffffffff;
  }
  else {
    local_60 = (undefined1)(param_2 >> 8);
    uVar4 = param_3 & 0xffffffff;
    local_5f = (undefined1)param_2;
    local_5d = (undefined1)(param_3 >> 0x10);
    local_5c = (undefined1)(param_3 >> 8);
    local_5e = (undefined1)(param_3 >> 0x18);
    local_5b = (undefined1)param_3;
    _local_70 = CONCAT62(0x60000,*(undefined2 *)(param_1 + 2));
    puStack_68 = &local_60;
    iVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_70,1);
    if (iVar2 < 0) {
      param_2 = param_2 & 0xffff;
      _dev_err(param_1 + 0x20,
               " [%s:%s:%d] i2c write error reg: 0x%04x data: 0x%08x, ret= %d cnt= %d\n",
               "aw_sar_comm_interface.c","aw_sar_i2c_write",0x70,param_2,uVar4,iVar2,5);
      _local_70 = CONCAT62(0x60000,*(undefined2 *)(param_1 + 2));
      puStack_68 = &local_60;
      iVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_70,1);
      if (iVar2 < 0) {
        _dev_err(param_1 + 0x20,
                 " [%s:%s:%d] i2c write error reg: 0x%04x data: 0x%08x, ret= %d cnt= %d\n",
                 "aw_sar_comm_interface.c","aw_sar_i2c_write",0x70,param_2,uVar4,iVar2,4);
        _local_70 = CONCAT62(0x60000,*(undefined2 *)(param_1 + 2));
        puStack_68 = &local_60;
        iVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_70,1);
        if (iVar2 < 0) {
          _dev_err(param_1 + 0x20,
                   " [%s:%s:%d] i2c write error reg: 0x%04x data: 0x%08x, ret= %d cnt= %d\n",
                   "aw_sar_comm_interface.c","aw_sar_i2c_write",0x70,param_2,uVar4,iVar2,3);
          _local_70 = CONCAT62(0x60000,*(undefined2 *)(param_1 + 2));
          puStack_68 = &local_60;
          iVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_70,1);
          if (iVar2 < 0) {
            _dev_err(param_1 + 0x20,
                     " [%s:%s:%d] i2c write error reg: 0x%04x data: 0x%08x, ret= %d cnt= %d\n",
                     "aw_sar_comm_interface.c","aw_sar_i2c_write",0x70,param_2,uVar4,iVar2,2);
            _local_70 = CONCAT62(0x60000,*(undefined2 *)(param_1 + 2));
            puStack_68 = &local_60;
            iVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_70,1);
            if (iVar2 < 0) {
              lVar1 = param_1 + 0x20;
              _dev_err(lVar1,
                       " [%s:%s:%d] i2c write error reg: 0x%04x data: 0x%08x, ret= %d cnt= %d\n",
                       "aw_sar_comm_interface.c","aw_sar_i2c_write",0x70,param_2,uVar4,iVar2,1);
              _local_70 = CONCAT62(0x60000,*(undefined2 *)(param_1 + 2));
              puStack_68 = &local_60;
              iVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_70,1);
              if (iVar2 < 0) {
                _dev_err(lVar1,
                         " [%s:%s:%d] i2c write error reg: 0x%04x data: 0x%08x, ret= %d cnt= %d\n",
                         "aw_sar_comm_interface.c","aw_sar_i2c_write",0x70,param_2,uVar4,iVar2,0);
                _dev_err(lVar1," [%s:%s:%d] i2c write error!\n","aw_sar_comm_interface.c",
                         "aw_sar_i2c_write",0x77);
                goto LAB_001017c0;
              }
            }
          }
        }
      }
    }
    uVar3 = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// aw_sar_i2c_write_bits @ 001019f4 size=144
// signature: undefined aw_sar_i2c_write_bits(void)
// callers: [reset_store, aw_sar_ps_notify_callback_work, capsensor_set_enable, aw_sar_aot_set, cali_show, aw963xx_enable_clock]
//------------------------------------------------------------

undefined8 aw_sar_i2c_write_bits(undefined8 param_1,ulong param_2,uint param_3,uint param_4)

{
  long lVar1;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  aw_sar_i2c_read(param_1,param_2,&local_3c);
  aw_sar_i2c_write(param_1,param_2 & 0xffffffff,
                   local_3c & param_3 | param_4 & (param_3 ^ 0xffffffff));
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw_sar_i2c_write_seq @ 00101a88 size=708
// signature: undefined aw_sar_i2c_write_seq(void)
// callers: [aw963xx_update_firmware, aw_sar_awrw_set]
//------------------------------------------------------------

void aw_sar_i2c_write_seq(long param_1,undefined8 param_2,ushort param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = (ulong)param_3 << 0x20;
  local_48 = CONCAT62(local_48._2_6_,*(undefined2 *)(param_1 + 2));
  uStack_40 = param_2;
  iVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_48,1);
  if (iVar2 < 0) {
    _dev_err(param_1 + 0x20," [%s:%s:%d] awinic i2c write seq error %d\n","aw_sar_comm_interface.c",
             "aw_sar_i2c_write_seq",0xa4,iVar2);
    usleep_range_state(2000,3000,2);
    local_48 = (ulong)param_3 << 0x20;
    local_48 = CONCAT62(local_48._2_6_,*(undefined2 *)(param_1 + 2));
    uStack_40 = param_2;
    iVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_48,1);
    if (iVar2 < 0) {
      _dev_err(param_1 + 0x20," [%s:%s:%d] awinic i2c write seq error %d\n",
               "aw_sar_comm_interface.c","aw_sar_i2c_write_seq",0xa4,iVar2);
      usleep_range_state(2000,3000,2);
      local_48 = (ulong)param_3 << 0x20;
      local_48 = CONCAT62(local_48._2_6_,*(undefined2 *)(param_1 + 2));
      uStack_40 = param_2;
      iVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_48,1);
      if (iVar2 < 0) {
        _dev_err(param_1 + 0x20," [%s:%s:%d] awinic i2c write seq error %d\n",
                 "aw_sar_comm_interface.c","aw_sar_i2c_write_seq",0xa4,iVar2);
        usleep_range_state(2000,3000,2);
        local_48 = (ulong)param_3 << 0x20;
        local_48 = CONCAT62(local_48._2_6_,*(undefined2 *)(param_1 + 2));
        uStack_40 = param_2;
        iVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_48,1);
        if (iVar2 < 0) {
          _dev_err(param_1 + 0x20," [%s:%s:%d] awinic i2c write seq error %d\n",
                   "aw_sar_comm_interface.c","aw_sar_i2c_write_seq",0xa4,iVar2);
          usleep_range_state(2000,3000,2);
          local_48 = (ulong)param_3 << 0x20;
          local_48 = CONCAT62(local_48._2_6_,*(undefined2 *)(param_1 + 2));
          uStack_40 = param_2;
          iVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_48,1);
          if (iVar2 < 0) {
            lVar1 = param_1 + 0x20;
            _dev_err(lVar1," [%s:%s:%d] awinic i2c write seq error %d\n","aw_sar_comm_interface.c",
                     "aw_sar_i2c_write_seq",0xa4,iVar2);
            usleep_range_state(2000,3000,2);
            local_48 = (ulong)param_3 << 0x20;
            local_48 = CONCAT62(local_48._2_6_,*(undefined2 *)(param_1 + 2));
            uStack_40 = param_2;
            iVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_48,1);
            if (iVar2 < 0) {
              _dev_err(lVar1," [%s:%s:%d] awinic i2c write seq error %d\n","aw_sar_comm_interface.c"
                       ,"aw_sar_i2c_write_seq",0xa4,iVar2);
              usleep_range_state(2000,3000,2);
              _dev_err(lVar1," [%s:%s:%d] awinic i2c write error!\n","aw_sar_comm_interface.c",
                       "aw_sar_i2c_write_seq",0xab);
              uVar3 = 0xffffffff;
              goto LAB_00101ae0;
            }
          }
        }
      }
    }
  }
  uVar3 = 0;
LAB_00101ae0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// aw_sar_i2c_read_seq @ 00101d50 size=832
// signature: undefined aw_sar_i2c_read_seq(void)
// callers: [aw963xx_update_firmware, aw_sar_awrw_set]
//------------------------------------------------------------

void aw_sar_i2c_read_seq(long param_1,undefined8 param_2,ushort param_3,undefined8 param_4,
                        undefined2 param_5)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  param_3 = param_3 & 0xff;
  local_78 = (ulong)param_3 << 0x20;
  local_78 = CONCAT62(local_78._2_6_,*(undefined2 *)(param_1 + 2));
  local_68 = CONCAT62(1,*(undefined2 *)(param_1 + 2));
  local_68._0_6_ = CONCAT24(param_5,(undefined4)local_68);
  local_68 = (ulong)(uint6)local_68;
  uStack_70 = param_2;
  uStack_60 = param_4;
  iVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_78,2);
  if (iVar2 < 0) {
    _dev_err(param_1 + 0x20," [%s:%s:%d] awinic sar i2c write error %d\n","aw_sar_comm_interface.c",
             "aw_sar_i2c_read_seq",0xc5,iVar2);
    usleep_range_state(2000,3000,2);
    local_78 = (ulong)param_3 << 0x20;
    local_78 = CONCAT62(local_78._2_6_,*(undefined2 *)(param_1 + 2));
    local_68._0_4_ = CONCAT22(1,*(undefined2 *)(param_1 + 2));
    local_68._0_6_ = CONCAT24(param_5,(undefined4)local_68);
    local_68 = (ulong)(uint6)local_68;
    uStack_70 = param_2;
    uStack_60 = param_4;
    iVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_78,2);
    if (iVar2 < 0) {
      _dev_err(param_1 + 0x20," [%s:%s:%d] awinic sar i2c write error %d\n",
               "aw_sar_comm_interface.c","aw_sar_i2c_read_seq",0xc5,iVar2);
      usleep_range_state(2000,3000,2);
      local_78 = (ulong)param_3 << 0x20;
      local_78 = CONCAT62(local_78._2_6_,*(undefined2 *)(param_1 + 2));
      local_68._0_4_ = CONCAT22(1,*(undefined2 *)(param_1 + 2));
      local_68._0_6_ = CONCAT24(param_5,(undefined4)local_68);
      local_68 = (ulong)(uint6)local_68;
      uStack_70 = param_2;
      uStack_60 = param_4;
      iVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_78,2);
      if (iVar2 < 0) {
        _dev_err(param_1 + 0x20," [%s:%s:%d] awinic sar i2c write error %d\n",
                 "aw_sar_comm_interface.c","aw_sar_i2c_read_seq",0xc5,iVar2);
        usleep_range_state(2000,3000,2);
        local_78 = (ulong)param_3 << 0x20;
        local_78 = CONCAT62(local_78._2_6_,*(undefined2 *)(param_1 + 2));
        local_68._0_4_ = CONCAT22(1,*(undefined2 *)(param_1 + 2));
        local_68._0_6_ = CONCAT24(param_5,(undefined4)local_68);
        local_68 = (ulong)(uint6)local_68;
        uStack_70 = param_2;
        uStack_60 = param_4;
        iVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_78,2);
        if (iVar2 < 0) {
          _dev_err(param_1 + 0x20," [%s:%s:%d] awinic sar i2c write error %d\n",
                   "aw_sar_comm_interface.c","aw_sar_i2c_read_seq",0xc5,iVar2);
          usleep_range_state(2000,3000,2);
          local_78 = (ulong)param_3 << 0x20;
          local_78 = CONCAT62(local_78._2_6_,*(undefined2 *)(param_1 + 2));
          local_68._0_4_ = CONCAT22(1,*(undefined2 *)(param_1 + 2));
          local_68._0_6_ = CONCAT24(param_5,(undefined4)local_68);
          local_68 = (ulong)(uint6)local_68;
          uStack_70 = param_2;
          uStack_60 = param_4;
          iVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_78,2);
          if (iVar2 < 0) {
            lVar1 = param_1 + 0x20;
            _dev_err(lVar1," [%s:%s:%d] awinic sar i2c write error %d\n","aw_sar_comm_interface.c",
                     "aw_sar_i2c_read_seq",0xc5,iVar2);
            usleep_range_state(2000,3000,2);
            local_78 = (ulong)param_3 << 0x20;
            local_78 = CONCAT62(local_78._2_6_,*(undefined2 *)(param_1 + 2));
            local_68._0_4_ = CONCAT22(1,*(undefined2 *)(param_1 + 2));
            local_68._0_6_ = CONCAT24(param_5,(undefined4)local_68);
            local_68 = (ulong)(uint6)local_68;
            uStack_70 = param_2;
            uStack_60 = param_4;
            iVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_78,2);
            if (iVar2 < 0) {
              _dev_err(lVar1," [%s:%s:%d] awinic sar i2c write error %d\n","aw_sar_comm_interface.c"
                       ,"aw_sar_i2c_read_seq",0xc5,iVar2);
              usleep_range_state(2000,3000,2);
              _dev_err(lVar1," [%s:%s:%d] awinic sar i2c read error!\n","aw_sar_comm_interface.c",
                       "aw_sar_i2c_read_seq",0xcd);
              uVar3 = 0xffffffff;
              goto LAB_00101dcc;
            }
          }
        }
      }
    }
  }
  uVar3 = 0;
LAB_00101dcc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// aw_sar_parsing_bin_file @ 00102094 size=664
// signature: undefined aw_sar_parsing_bin_file(void)
// callers: [aw_sar_load_bin_comm]
//------------------------------------------------------------

int aw_sar_parsing_bin_file(undefined8 *param_1)

{
  code *pcVar1;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  ulong uVar5;
  int *piVar6;
  
  _printk("AWINIC_BIN %s,line= %d,aw_bin_parse code version:%s\n","aw_sar_parsing_bin_file",0x290,
          "V0.0.7-V1.0.4");
  if (param_1 == (undefined8 *)0x0) {
    _printk("AWINIC_BIN_ERR %s,line= %d,aw_bin_parse bin is NULL\n","aw_sar_parsing_bin_file",0x292)
    ;
    iVar2 = -8;
  }
  else {
    iVar2 = *(int *)((long)param_1 + 0x1c3c);
    *param_1 = param_1 + 0x387;
    param_1[1] = 0;
    *(undefined4 *)(param_1 + 2) = 0;
    _printk("AWINIC_BIN %s,line= %d,aw_bin_parse header_version 0x%x\n",
            "aw_check_bin_header_version",0x277,iVar2);
    if (iVar2 == 0x1000000) {
      iVar2 = aw_parse_bin_header_1_0_0(param_1);
      if (-1 < iVar2) {
        *param_1 = 0;
        if (*(int *)(param_1 + 1) != 0) {
          uVar5 = 0;
          piVar6 = (int *)((long)param_1 + 0x24);
          do {
            iVar2 = aw_check_sum(param_1,uVar5 & 0xffffffff);
            if (iVar2 < 0) {
              pcVar3 = "AWINIC_BIN_ERR %s,line= %d,aw_bin_parse check sum data error\n";
              uVar4 = 0x2a7;
              goto LAB_001021a4;
            }
            _printk("AWINIC_BIN %s,line= %d,enter\n","aw_check_data_version",0x143);
            if (uVar5 == 100) {
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10232c);
              (*pcVar1)();
            }
            if (*piVar6 != 1) {
              _printk("AWINIC_BIN_ERR %s,line= %d,aw_bin_parse Unrecognized this bin data version\n"
                      ,"aw_check_data_version",0x14a);
              _printk("AWINIC_BIN_ERR %s,line= %d,aw_bin_parse check data version error\n",
                      "aw_sar_parsing_bin_file",0x2ad);
              return -4;
            }
            iVar2 = piVar6[-1];
            if (iVar2 == 0x21) {
              iVar2 = aw_check_soc_app_num_v1(param_1,uVar5 & 0xffffffff);
              if (iVar2 < 0) {
                pcVar3 = "AWINIC_BIN_ERR %s,line= %d,aw_bin_parse check soc app num error\n";
                uVar4 = 0x2ca;
                goto LAB_001021a4;
              }
            }
            else if (iVar2 == 0x10) {
              iVar2 = aw_check_dsp_reg_num_v1(param_1,uVar5 & 0xffffffff);
              if (iVar2 < 0) {
                pcVar3 = "AWINIC_BIN_ERR %s,line= %d,aw_bin_parse check dsp reg num error\n";
                uVar4 = 0x2c1;
                goto LAB_001021a4;
              }
            }
            else if (iVar2 == 0) {
              iVar2 = aw_check_register_num_v1(param_1,uVar5 & 0xffffffff);
              if (iVar2 < 0) {
                pcVar3 = "AWINIC_BIN_ERR %s,line= %d,aw_bin_parse check register num error\n";
                uVar4 = 0x2b8;
                goto LAB_001021a4;
              }
            }
            else {
              piVar6[8] = piVar6[1];
            }
            uVar5 = uVar5 + 1;
            piVar6 = piVar6 + 0x12;
          } while (uVar5 < *(uint *)(param_1 + 1));
        }
        _printk("AWINIC_BIN %s,line= %d,aw_bin_parse parsing success\n","aw_sar_parsing_bin_file",
                0x2d3);
        return 0;
      }
    }
    else {
      _printk("AWINIC_BIN_ERR %s,line= %d,aw_bin_parse Unrecognized this bin header version \n",
              "aw_check_bin_header_version",0x280);
      iVar2 = -1;
    }
    pcVar3 = "AWINIC_BIN_ERR %s,line= %d,aw_bin_parse check bin header version error\n";
    uVar4 = 0x29d;
LAB_001021a4:
    _printk(pcVar3,"aw_sar_parsing_bin_file",uVar4);
  }
  return iVar2;
}



//------------------------------------------------------------
// aw_check_sum @ 0010232c size=424
// signature: undefined aw_check_sum(void)
// callers: [aw_sar_parsing_bin_file_new, aw_sar_parsing_bin_file]
//------------------------------------------------------------

undefined8 aw_check_sum(long param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  byte *pbVar7;
  ulong uVar8;
  int iVar9;
  int iVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  
  _printk("AWINIC_BIN %s,line= %d,enter\n","aw_check_sum",0x123);
  if (99 < param_2) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1024d4);
    (*pcVar3)();
  }
  lVar12 = param_1 + (ulong)param_2 * 0x48;
  uVar13 = (ulong)(uint)(*(int *)(lVar12 + 0x48) - *(int *)(lVar12 + 0x14));
  _printk("AWINIC_BIN %s,line= %d,aw_bin_parse p_check_sum = %p\n","aw_check_sum",0x128,
          param_1 + uVar13 + 0x1c38);
  iVar2 = *(int *)(param_1 + uVar13 + 0x1c38);
  uVar1 = *(int *)(lVar12 + 0x14) + *(int *)(lVar12 + 0x28);
  if (uVar1 < 5) {
    iVar10 = 0;
  }
  else {
    uVar6 = (ulong)uVar1 - 4;
    if (uVar6 < 2) {
      iVar10 = 0;
      lVar12 = 4;
    }
    else {
      uVar8 = uVar6 & 0xfffffffffffffffe;
      iVar9 = 0;
      iVar10 = 0;
      lVar12 = uVar8 + 4;
      pbVar7 = (byte *)(uVar13 + param_1 + 0x1c3d);
      uVar11 = uVar8;
      do {
        uVar11 = uVar11 - 2;
        iVar9 = iVar9 + (uint)pbVar7[-1];
        iVar10 = iVar10 + (uint)*pbVar7;
        pbVar7 = pbVar7 + 2;
      } while (uVar11 != 0);
      iVar10 = iVar10 + iVar9;
      if (uVar6 == uVar8) goto LAB_00102444;
    }
    lVar5 = (ulong)uVar1 - lVar12;
    pbVar7 = (byte *)(lVar12 + uVar13 + param_1 + 0x1c38);
    do {
      lVar5 = lVar5 + -1;
      iVar10 = iVar10 + (uint)*pbVar7;
      pbVar7 = pbVar7 + 1;
    } while (lVar5 != 0);
  }
LAB_00102444:
  _printk("AWINIC_BIN %s,line= %d,aw_bin_parse bin_num=%d, check_sum = 0x%x, sum_data = 0x%x\n",
          "aw_check_sum",0x134,param_2,iVar2,iVar10);
  if (iVar10 == iVar2) {
    uVar4 = 0;
  }
  else {
    _printk("AWINIC_BIN_ERR %s,line= %d,aw_bin_parse check sum or check bin data len error\n",
            "aw_check_sum",0x137);
    _printk("AWINIC_BIN_ERR %s,line= %d,aw_bin_parse bin_num=%d, check_sum = 0x%x, sum_data = 0x%x\n"
            ,"aw_check_sum",0x138,param_2,iVar2,iVar10);
    uVar4 = 0xfffffffd;
  }
  return uVar4;
}



//------------------------------------------------------------
// aw_check_register_num_v1 @ 001024d4 size=332
// signature: undefined aw_check_register_num_v1(void)
// callers: [aw_sar_parsing_bin_file_new, aw_sar_parsing_bin_file]
//------------------------------------------------------------

undefined8 aw_check_register_num_v1(long param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  undefined8 uVar6;
  uint *puVar7;
  long lVar8;
  
  _printk("AWINIC_BIN %s,line= %d,enter\n","aw_check_register_num_v1",0x159);
  if (99 < param_2) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x102620);
    (*pcVar5)();
  }
  lVar8 = param_1 + (ulong)param_2 * 0x48;
  puVar7 = (uint *)(lVar8 + 0x48);
  uVar3 = *puVar7;
  _printk("AWINIC_BIN %s,line= %d,aw_bin_parse p_check_sum = %p\n","aw_check_register_num_v1",0x15d,
          param_1 + (ulong)uVar3 + 0x1c38);
  uVar1 = *(uint *)(param_1 + (ulong)uVar3 + 0x1c38);
  uVar3 = *(int *)(lVar8 + 0x3c) + *(int *)(lVar8 + 0x38);
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = (*(int *)(lVar8 + 0x28) - 4U) / uVar3;
  }
  _printk("AWINIC_BIN %s,line= %d,aw_bin_parse bin_num=%d, parse_register_num = 0x%x, check_register_num = 0x%x\n"
          ,"aw_check_register_num_v1",0x166,param_2,uVar1,uVar4);
  if (uVar1 == uVar4) {
    iVar2 = *(int *)(lVar8 + 0x28);
    uVar6 = 0;
    uVar3 = *puVar7;
    param_1 = param_1 + (ulong)param_2 * 0x48;
    *(uint *)(param_1 + 0x4c) = uVar1;
    *(int *)(param_1 + 0x44) = iVar2 + -4;
    *puVar7 = uVar3 + 4;
  }
  else {
    _printk("AWINIC_BIN_ERR %s,line= %d,aw_bin_parse register num is error\n",
            "aw_check_register_num_v1",0x169);
    _printk("AWINIC_BIN_ERR %s,line= %d,aw_bin_parse bin_num=%d, parse_register_num = 0x%x, check_register_num = 0x%x\n"
            ,"aw_check_register_num_v1",0x16a,param_2,uVar1,uVar4);
    uVar6 = 0xfffffffb;
  }
  return uVar6;
}



//------------------------------------------------------------
// aw_check_dsp_reg_num_v1 @ 00102620 size=344
// signature: undefined aw_check_dsp_reg_num_v1(void)
// callers: [aw_sar_parsing_bin_file_new, aw_sar_parsing_bin_file]
//------------------------------------------------------------

undefined8 aw_check_dsp_reg_num_v1(long param_1,uint param_2)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  undefined8 uVar7;
  uint *puVar8;
  long lVar9;
  
  _printk("AWINIC_BIN %s,line= %d,enter\n","aw_check_dsp_reg_num_v1",0x17c);
  if (99 < param_2) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x102778);
    (*pcVar6)();
  }
  lVar9 = param_1 + (ulong)param_2 * 0x48;
  puVar8 = (uint *)(lVar9 + 0x48);
  lVar1 = param_1 + (ulong)*puVar8;
  _printk("AWINIC_BIN %s,line= %d,aw_bin_parse p_check_sum = %p\n","aw_check_dsp_reg_num_v1",0x180,
          (undefined4 *)(lVar1 + 0x1c38));
  uVar2 = *(uint *)(lVar1 + 0x1c40);
  uVar3 = *(uint *)(lVar1 + 0x1c3c);
  uVar5 = 0;
  if (uVar2 != 0) {
    uVar5 = (*(int *)(lVar9 + 0x28) - 0xcU) / uVar2;
  }
  *(uint *)(lVar9 + 0x50) = uVar2;
  _printk("AWINIC_BIN %s,line= %d,aw_bin_parse bin_num=%d, parse_dsp_reg_num = 0x%x, check_dsp_reg_num = 0x%x\n"
          ,"aw_check_dsp_reg_num_v1",0x18d,param_2,uVar3,uVar5);
  if (uVar3 == uVar5) {
    iVar4 = *(int *)(lVar9 + 0x28);
    uVar7 = 0;
    param_1 = param_1 + (ulong)param_2 * 0x48;
    uVar2 = *puVar8;
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(lVar1 + 0x1c38);
    *(uint *)(param_1 + 0x4c) = uVar3;
    *(int *)(param_1 + 0x44) = iVar4 + -0xc;
    *puVar8 = uVar2 + 0xc;
  }
  else {
    _printk("AWINIC_BIN_ERR %s,line= %d,aw_bin_parse dsp reg num is error\n",
            "aw_check_dsp_reg_num_v1",400);
    _printk("AWINIC_BIN_ERR %s,line= %d,aw_bin_parse bin_num=%d, parse_dsp_reg_num = 0x%x, check_dsp_reg_num = 0x%x\n"
            ,"aw_check_dsp_reg_num_v1",0x191,param_2,uVar3,uVar5);
    uVar7 = 0xfffffffa;
  }
  return uVar7;
}



//------------------------------------------------------------
// aw_check_soc_app_num_v1 @ 00102778 size=340
// signature: undefined aw_check_soc_app_num_v1(void)
// callers: [aw_sar_parsing_bin_file_new, aw_sar_parsing_bin_file]
//------------------------------------------------------------

undefined8 aw_check_soc_app_num_v1(long param_1,uint param_2)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  code *pcVar6;
  undefined8 uVar7;
  uint *puVar8;
  long lVar9;
  
  _printk("AWINIC_BIN %s,line= %d,enter\n","aw_check_soc_app_num_v1",0x1a6);
  if (99 < param_2) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x1028cc);
    (*pcVar6)();
  }
  lVar9 = param_1 + (ulong)param_2 * 0x48;
  puVar8 = (uint *)(lVar9 + 0x48);
  lVar1 = param_1 + (ulong)*puVar8;
  _printk("AWINIC_BIN %s,line= %d,aw_bin_parse p_check_sum = %p\n","aw_check_soc_app_num_v1",0x1aa,
          lVar1 + 0x1c38);
  *(undefined4 *)(lVar9 + 0x58) = *(undefined4 *)(lVar1 + 0x1c38);
  iVar2 = *(int *)(lVar1 + 0x1c40);
  iVar5 = *(int *)(lVar9 + 0x28) + -0xc;
  _printk("AWINIC_BIN %s,line= %d,aw_bin_parse bin_num=%d, parse_soc_app_num = 0x%x, check_soc_app_num = 0x%x\n"
          ,"aw_check_soc_app_num_v1",0x1b5,param_2,iVar2,iVar5);
  if (iVar2 == iVar5) {
    uVar3 = *puVar8;
    uVar7 = 0;
    param_1 = param_1 + (ulong)param_2 * 0x48;
    iVar5 = *(int *)(lVar9 + 0x28);
    *(int *)(param_1 + 0x4c) = iVar2;
    uVar4 = *(undefined4 *)(lVar1 + 0x1c3c);
    *puVar8 = uVar3 + 0xc;
    *(int *)(param_1 + 0x44) = iVar5 + -0xc;
    *(undefined4 *)(param_1 + 0x54) = uVar4;
  }
  else {
    _printk("AWINIC_BIN_ERR %s,line= %d,aw_bin_parse soc app num is error\n",
            "aw_check_soc_app_num_v1",0x1b8);
    _printk("AWINIC_BIN_ERR %s,line= %d,aw_bin_parse bin_num=%d, parse_soc_app_num = 0x%x, check_soc_app_num = 0x%x\n"
            ,"aw_check_soc_app_num_v1",0x1b9,param_2,iVar2,iVar5);
    uVar7 = 0xfffffff9;
  }
  return uVar7;
}



//------------------------------------------------------------
// aw_sar_parsing_bin_file_new @ 001028d0 size=600
// signature: undefined aw_sar_parsing_bin_file_new(void)
// callers: [aw_sar_load_bin_comm]
//------------------------------------------------------------

int aw_sar_parsing_bin_file_new(undefined8 *param_1)

{
  code *pcVar1;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  ulong uVar5;
  undefined4 *puVar6;
  
  _printk("AWINIC_BIN %s,line= %d,aw_bin_parse code version:%s\n","aw_sar_parsing_bin_file_new",
          0x2e3,"V0.0.7-V1.0.4");
  if (param_1 == (undefined8 *)0x0) {
    _printk("AWINIC_BIN_ERR %s,line= %d,aw_bin_parse bin is NULL\n","aw_sar_parsing_bin_file_new",
            0x2e5);
    iVar2 = -8;
  }
  else {
    iVar2 = *(int *)((long)param_1 + 0x1c3c);
    *param_1 = param_1 + 0x387;
    param_1[1] = 0;
    *(undefined4 *)(param_1 + 2) = 0;
    _printk("AWINIC_BIN %s,line= %d,aw_bin_parse header_version 0x%x\n",
            "aw_check_bin_header_version",0x277,iVar2);
    if (iVar2 == 0x1000000) {
      iVar2 = aw_parse_bin_header_1_0_0(param_1);
      if (-1 < iVar2) {
        *param_1 = 0;
        if (*(int *)(param_1 + 1) != 0) {
          uVar5 = 0;
          puVar6 = (undefined4 *)((long)param_1 + 0x24);
          do {
            iVar2 = aw_check_sum(param_1,uVar5 & 0xffffffff);
            if (iVar2 < 0) {
              pcVar3 = "AWINIC_BIN_ERR %s,line= %d,aw_bin_parse check sum data error\n";
              uVar4 = 0x2fa;
              goto LAB_001029e0;
            }
            if (uVar5 == 100) {
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x102b28);
              (*pcVar1)();
            }
            _printk("AWINIC_BIN %s,line= %d,aw_bin_parse bin data version is 0x%x\n",
                    "aw_check_data_version_new",0x150,*puVar6);
            iVar2 = puVar6[-1];
            if (iVar2 == 0x21) {
              iVar2 = aw_check_soc_app_num_v1(param_1,uVar5 & 0xffffffff);
              if (iVar2 < 0) {
                pcVar3 = "AWINIC_BIN_ERR %s,line= %d,aw_bin_parse check soc app num error\n";
                uVar4 = 0x312;
                goto LAB_001029e0;
              }
            }
            else if (iVar2 == 0x10) {
              iVar2 = aw_check_dsp_reg_num_v1(param_1,uVar5 & 0xffffffff);
              if (iVar2 < 0) {
                pcVar3 = "AWINIC_BIN_ERR %s,line= %d,aw_bin_parse check dsp reg num error\n";
                uVar4 = 0x30b;
                goto LAB_001029e0;
              }
            }
            else if (iVar2 == 0) {
              iVar2 = aw_check_register_num_v1(param_1,uVar5 & 0xffffffff);
              if (iVar2 < 0) {
                pcVar3 = "AWINIC_BIN_ERR %s,line= %d,aw_bin_parse check register num error\n";
                uVar4 = 0x304;
                goto LAB_001029e0;
              }
            }
            else {
              puVar6[8] = puVar6[1];
            }
            uVar5 = uVar5 + 1;
            puVar6 = puVar6 + 0x12;
          } while (uVar5 < *(uint *)(param_1 + 1));
        }
        _printk("AWINIC_BIN %s,line= %d,aw_bin_parse parsing success\n",
                "aw_sar_parsing_bin_file_new",0x319);
        return 0;
      }
    }
    else {
      _printk("AWINIC_BIN_ERR %s,line= %d,aw_bin_parse Unrecognized this bin header version \n",
              "aw_check_bin_header_version",0x280);
      iVar2 = -1;
    }
    pcVar3 = "AWINIC_BIN_ERR %s,line= %d,aw_bin_parse check bin header version error\n";
    uVar4 = 0x2f0;
LAB_001029e0:
    _printk(pcVar3,"aw_sar_parsing_bin_file_new",uVar4);
  }
  return iVar2;
}



//------------------------------------------------------------
// aw_sar_pow2 @ 00102b2c size=36
// signature: undefined aw_sar_pow2(void)
// callers: [aw963xx_get_signed_cap]
//------------------------------------------------------------

int aw_sar_pow2(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 1;
  }
  iVar1 = 1;
  do {
    iVar1 = iVar1 << 1;
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  return iVar1;
}



//------------------------------------------------------------
// aw_sar_load_reg @ 00102b54 size=220
// signature: undefined aw_sar_load_reg(void)
// callers: [aw963xx_load_reg_bin]
//------------------------------------------------------------

undefined8 aw_sar_load_reg(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (*(int *)(param_1 + 0x44) != 0) {
    uVar5 = 0;
    iVar3 = *(int *)(param_1 + 0x48);
    lVar2 = param_1 + 0x1c38;
    do {
      uVar1 = iVar3 + uVar5;
      iVar4 = aw_sar_i2c_write(param_2,CONCAT11(*(undefined1 *)(lVar2 + (ulong)(uVar1 + 1)),
                                                *(undefined1 *)(lVar2 + (ulong)uVar1)),
                               CONCAT13(*(undefined1 *)(lVar2 + (ulong)(uVar1 + 5)),
                                        CONCAT12(*(undefined1 *)(lVar2 + (ulong)(uVar1 + 4)),
                                                 CONCAT11(*(undefined1 *)
                                                           (lVar2 + (ulong)(uVar1 + 3)),
                                                          *(undefined1 *)
                                                           (lVar2 + (ulong)(uVar1 + 2))))));
      if (iVar4 < 0) {
        _dev_err(param_2 + 0x20," [%s:%s:%d] i2c write err\n","aw_sar_comm_interface.c",
                 "aw_sar_load_reg",0x34f);
        return 0xffffffff;
      }
      uVar5 = uVar5 + 6;
    } while (uVar5 < *(uint *)(param_1 + 0x44));
  }
  return 0;
}



//------------------------------------------------------------
// aw_sar_delay_ms @ 00102c34 size=60
// signature: undefined aw_sar_delay_ms(void)
// callers: []
//------------------------------------------------------------

void aw_sar_delay_ms(uint param_1)

{
  ulong uVar1;
  
  if (param_1 != 0) {
    uVar1 = (ulong)param_1;
    do {
      uVar1 = uVar1 - 1;
      __const_udelay(0x418958);
    } while (uVar1 != 0);
  }
  return;
}



//------------------------------------------------------------
// aw_parse_bin_header_1_0_0 @ 00102c70 size=808
// signature: undefined aw_parse_bin_header_1_0_0(void)
// callers: [aw_parse_bin_header_1_0_0, aw_sar_parsing_bin_file_new, aw_sar_parsing_bin_file]
//------------------------------------------------------------

undefined8 aw_parse_bin_header_1_0_0(long *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  undefined8 uVar6;
  int iVar7;
  
  _printk("AWINIC_BIN %s,line= %d,enter %s\n","aw_parse_bin_header_1_0_0",0x244,
          "aw_parse_bin_header_1_0_0");
  uVar2 = *(uint *)(*param_1 + 8);
  _printk("AWINIC_BIN %s,line= %d,aw_bin_parse bin_data_type 0x%x\n","aw_parse_bin_header_1_0_0",
          0x248,(ulong)uVar2);
  if ((uVar2 < 0x22) && ((1L << ((ulong)uVar2 & 0x3f) & 0x200010001U) != 0)) {
    _printk("AWINIC_BIN %s,line= %d,aw_bin_parse enter single bin branch\n",
            "aw_parse_bin_header_1_0_0",0x250);
    *(int *)(param_1 + 2) = (int)param_1[2] + 1;
    _printk("AWINIC_BIN %s,line= %d,%s bin->single_bin_parse_num is %d\n",
            "aw_parse_bin_header_1_0_0",0x253,"aw_parse_bin_header_1_0_0");
    if (*(int *)((long)param_1 + 0xc) == 0) {
      if (99 < *(uint *)(param_1 + 1)) goto LAB_00102f94;
      *(undefined4 *)(param_1 + (ulong)*(uint *)(param_1 + 1) * 9 + 9) = 0x3c;
    }
    aw_get_single_bin_header_1_0_0(param_1);
    uVar6 = 0;
  }
  else if (uVar2 == 0x2000) {
    _printk("AWINIC_BIN %s,line= %d,aw_bin_parse enter multi bin branch\n",
            "aw_parse_bin_header_1_0_0",0x25d);
    *(int *)((long)param_1 + 0xc) = *(int *)((long)param_1 + 0xc) + 1;
    _printk("AWINIC_BIN %s,line= %d,%s bin->multi_bin_parse_num is %d\n","aw_parse_bin_header_1_0_0"
            ,0x260,"aw_parse_bin_header_1_0_0");
    _printk("AWINIC_BIN %s,line= %d,aw_bin_parse enter multi bin branch -- %s\n",
            "aw_get_multi_bin_header_1_0_0",0x222,"aw_get_multi_bin_header_1_0_0");
    iVar3 = *(int *)(*param_1 + 0x3c);
    if (*(int *)((long)param_1 + 0xc) == 1) {
      if (99 < *(uint *)(param_1 + 1)) goto LAB_00102f94;
      *(undefined4 *)(param_1 + (ulong)*(uint *)(param_1 + 1) * 9 + 9) = 0x3c;
    }
    aw_get_single_bin_header_1_0_0(param_1);
    if (iVar3 != 0) {
      _printk("AWINIC_BIN %s,line= %d,aw_bin_parse enter multi bin for is %d\n",
              "aw_get_multi_bin_header_1_0_0",0x22c,0);
      _printk("AWINIC_BIN %s,line= %d,aw_bin_parse enter multi bin branch -- %s\n",
              "aw_parse_each_of_multi_bins_1_0_0",0x203,"aw_parse_each_of_multi_bins_1_0_0");
      uVar2 = *(uint *)(param_1 + 1) - 1;
      *param_1 = *param_1 + (ulong)(*(int *)(*param_1 + 0x40) + 0x3c);
      if (0x62 < uVar2) {
LAB_00102f94:
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x102f98);
        (*pcVar5)();
      }
      *(int *)(param_1 + (ulong)*(uint *)(param_1 + 1) * 9 + 9) =
           (int)param_1[(ulong)uVar2 * 9 + 9] + iVar3 * 8 + 0x40;
      uVar6 = aw_parse_bin_header_1_0_0(param_1);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
      if (iVar3 != 1) {
        iVar7 = 1;
        while( true ) {
          _printk("AWINIC_BIN %s,line= %d,aw_bin_parse enter multi bin for is %d\n",
                  "aw_get_multi_bin_header_1_0_0",0x22c,iVar7);
          _printk("AWINIC_BIN %s,line= %d,aw_bin_parse enter multi bin branch -- %s\n",
                  "aw_parse_each_of_multi_bins_1_0_0",0x203,"aw_parse_each_of_multi_bins_1_0_0");
          uVar2 = *(uint *)(param_1 + 1);
          uVar4 = uVar2 - 1;
          if (99 < uVar4) break;
          uVar1 = (int)param_1[(ulong)uVar4 * 9 + 5] + 0x3c;
          *param_1 = *param_1 + (ulong)uVar1;
          if (99 < uVar2) break;
          *(uint *)(param_1 + (ulong)uVar2 * 9 + 9) = uVar1 + (int)param_1[(ulong)uVar4 * 9 + 9];
          uVar6 = aw_parse_bin_header_1_0_0(param_1);
          if ((int)uVar6 < 0) {
            return uVar6;
          }
          iVar7 = iVar7 + 1;
          if (iVar7 == iVar3) {
            return 0;
          }
        }
        goto LAB_00102f94;
      }
    }
    uVar6 = 0;
  }
  else {
    _printk("AWINIC_BIN_ERR %s,line= %d,aw_bin_parse Unrecognized this bin data type\n",
            "aw_parse_bin_header_1_0_0",0x267);
    uVar6 = 0xfffffffe;
  }
  return uVar6;
}



//------------------------------------------------------------
// aw_get_single_bin_header_1_0_0 @ 00102f98 size=280
// signature: undefined aw_get_single_bin_header_1_0_0(void)
// callers: [aw_parse_bin_header_1_0_0]
//------------------------------------------------------------

void aw_get_single_bin_header_1_0_0(long *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  code *pcVar4;
  long lVar5;
  undefined4 *puVar6;
  
  _printk("AWINIC_BIN %s,line= %d,enter %s\n","aw_get_single_bin_header_1_0_0",0x1d0,
          "aw_get_single_bin_header_1_0_0");
  uVar1 = *(uint *)(param_1 + 1);
  if (uVar1 < 100) {
    puVar6 = (undefined4 *)*param_1;
    *(undefined4 *)((long)param_1 + (ulong)uVar1 * 0x48 + 0x14) = 0x3c;
    *(undefined4 *)(param_1 + (ulong)uVar1 * 9 + 3) = *puVar6;
    *(undefined4 *)((long)param_1 + (ulong)uVar1 * 0x48 + 0x1c) = puVar6[1];
    *(undefined4 *)(param_1 + (ulong)uVar1 * 9 + 4) = puVar6[2];
    *(undefined4 *)((long)param_1 + (ulong)uVar1 * 0x48 + 0x24) = puVar6[3];
    *(undefined4 *)(param_1 + (ulong)uVar1 * 9 + 5) = puVar6[4];
    *(undefined4 *)((long)param_1 + (ulong)uVar1 * 0x48 + 0x2c) = puVar6[5];
    *(undefined4 *)(param_1 + (ulong)uVar1 * 9 + 7) = puVar6[8];
    *(undefined4 *)((long)param_1 + (ulong)uVar1 * 0x48 + 0x3c) = puVar6[9];
    uVar2 = *(uint *)(param_1 + 1);
    *(undefined4 *)(param_1 + (ulong)uVar1 * 9 + 8) = puVar6[10];
    if (uVar2 < 100) {
      lVar5 = *param_1;
      *(undefined1 *)(param_1 + (ulong)uVar2 * 9 + 6) = *(undefined1 *)(lVar5 + 0x18);
      *(undefined1 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x31) = *(undefined1 *)(lVar5 + 0x19);
      *(undefined1 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x32) = *(undefined1 *)(lVar5 + 0x1a);
      *(undefined1 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x33) = *(undefined1 *)(lVar5 + 0x1b);
      *(undefined1 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x34) = *(undefined1 *)(lVar5 + 0x1c);
      *(undefined1 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x35) = *(undefined1 *)(lVar5 + 0x1d);
      *(undefined1 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x36) = *(undefined1 *)(lVar5 + 0x1e);
      uVar3 = *(undefined1 *)(lVar5 + 0x1f);
      *(undefined4 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x44) = 0;
      *(undefined8 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x54) = 0;
      *(undefined8 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x4c) = 0;
      *(undefined1 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x37) = uVar3;
      *(uint *)(param_1 + 1) = uVar2 + 1;
      return;
    }
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1030b0);
  (*pcVar4)();
}



//------------------------------------------------------------
// aw_sar_disable_irq @ 001030b4 size=60
// signature: undefined aw_sar_disable_irq(void)
// callers: []
//------------------------------------------------------------

void aw_sar_disable_irq(long param_1)

{
  if (*(char *)(param_1 + 0x21c) == '\0') {
    disable_irq(*(undefined4 *)(param_1 + 0x218));
    *(undefined1 *)(param_1 + 0x21c) = 1;
  }
  return;
}



//------------------------------------------------------------
// aw_sar_enable_irq @ 001030f4 size=60
// signature: undefined aw_sar_enable_irq(void)
// callers: []
//------------------------------------------------------------

void aw_sar_enable_irq(long param_1)

{
  if (*(char *)(param_1 + 0x21c) == '\x01') {
    enable_irq(*(undefined4 *)(param_1 + 0x218));
    *(undefined1 *)(param_1 + 0x21c) = 0;
  }
  return;
}



//------------------------------------------------------------
// aw_sar_load_bin_comm @ 00103134 size=744
// signature: undefined aw_sar_load_bin_comm(void)
// callers: [aw_sar_update_fw, aw_sar_prot_update_fw_set, aw_sar_load_def_reg_bin, aw_sar_reg_update_fw_set, aw_sar_update_work, aw_sar_reg_update_boot_set]
//------------------------------------------------------------

void aw_sar_load_bin_comm(long param_1)

{
  size_t *psVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  size_t __n;
  undefined8 uVar6;
  code *pcVar7;
  size_t *local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = (size_t *)0x0;
  iVar2 = request_firmware(&local_40,param_1 + 0x1e8,*(undefined8 *)(param_1 + 8));
  psVar1 = local_40;
  if (iVar2 == 0) {
    if (local_40 == (size_t *)0x0) {
      _dev_err(*(undefined8 *)(param_1 + 8)," [%s:%s:%d] def_reg_bin request error!\n","aw_sar.c",
               "aw_sar_parse_bin",0x99);
    }
    else {
      _dev_info(*(undefined8 *)(param_1 + 8)," [%s:%s:%d] def_reg_bin request successfully\n",
                "aw_sar.c","aw_sar_parse_bin",0x9c);
      lVar3 = __kmalloc(*psVar1 + 0x1c38,0xdc0);
      if (lVar3 != 0) {
        __n = *psVar1;
        *(int *)(lVar3 + 0x1c34) = (int)__n;
        memcpy((void *)(lVar3 + 0x1c38),(void *)psVar1[1],__n);
        release_firmware(psVar1);
        if (*(char *)(param_1 + 0x1d1) == '\0') {
          iVar2 = aw_sar_parsing_bin_file(lVar3);
          if (-1 < iVar2) goto LAB_00103274;
LAB_001032b4:
          _dev_err(*(undefined8 *)(param_1 + 8)," [%s:%s:%d] parse bin fail! ret = %d\n","aw_sar.c",
                   "aw_sar_parse_bin",0xb6,iVar2);
          goto LAB_001032d8;
        }
        iVar2 = aw_sar_parsing_bin_file_new(lVar3);
        if (iVar2 < 0) goto LAB_001032b4;
LAB_00103274:
        pcVar7 = *(code **)(param_1 + 0x208);
        if (pcVar7 == (code *)0x0) {
          _dev_err(*(undefined8 *)(param_1 + 8)," [%s:%s:%d] bin_opera_func is null error!\n",
                   "aw_sar.c","aw_sar_parse_bin",0xcc,iVar2);
        }
        else {
          if (*(int *)(pcVar7 + -4) != -0x2f7376) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x103358);
            (*pcVar7)();
          }
          iVar2 = (*pcVar7)(lVar3,param_1);
          if (iVar2 != 0) {
            _dev_err(*(undefined8 *)(param_1 + 8)," [%s:%s:%d] load_bin_to_chip error!\n","aw_sar.c"
                     ,"aw_sar_parse_bin",0xbe);
            pcVar7 = *(code **)(param_1 + 0x210);
            if (pcVar7 != (code *)0x0) {
              if (*(int *)(pcVar7 + -4) != -0x2f7376) {
                    /* WARNING: Does not return */
                pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x1033ac);
                (*pcVar7)();
              }
              iVar2 = (*pcVar7)(lVar3,param_1);
              if (iVar2 == 0) goto LAB_001033b4;
              _dev_err(*(undefined8 *)(param_1 + 8)," [%s:%s:%d] bin_load_fail_opera_func error!\n",
                       "aw_sar.c","aw_sar_parse_bin",0xc2);
            }
LAB_001032d8:
            kfree(lVar3);
            goto LAB_001032e0;
          }
        }
LAB_001033b4:
        kfree(lVar3);
        _dev_err(*(undefined8 *)(param_1 + 8)," [%s:%s:%d] load_def_reg_bin ok!!!\n","aw_sar.c",
                 "aw_sar_parse_bin",0xd3);
        uVar4 = 0;
        *(undefined1 *)(param_1 + 0x198) = 1;
        goto LAB_0010330c;
      }
      kfree();
      release_firmware(psVar1);
      _dev_err(*(undefined8 *)(param_1 + 8)," [%s:%s:%d] failed to allcating memory!\n","aw_sar.c",
               "aw_sar_parse_bin",0xa5);
    }
LAB_001032e0:
    uVar4 = *(undefined8 *)(param_1 + 8);
    pcVar5 = " [%s:%s:%d] reg_bin %s load error!\n";
    uVar6 = 0xef;
  }
  else {
    uVar4 = *(undefined8 *)(param_1 + 8);
    pcVar5 = " [%s:%s:%d] parse %s error!\n";
    uVar6 = 0xe7;
  }
  _dev_err(uVar4,pcVar5,"aw_sar.c","aw_sar_load_bin_comm",uVar6,param_1 + 0x1e8);
  uVar4 = 0xffffffff;
LAB_0010330c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// aw_sar_parse_dts_comm @ 00103420 size=904
// signature: undefined aw_sar_parse_dts_comm(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

undefined8 aw_sar_parse_dts_comm(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  undefined8 uVar4;
  
  iVar1 = of_property_read_variable_u32_array(param_2,"sar-num",param_3,1,0);
  if (iVar1 < 0) {
    pcVar3 = " [%s:%s:%d] multiple sar failed!\n";
    uVar4 = 0x101;
  }
  else {
    _dev_info(param_1," [%s:%s:%d] sar num = %d\n","aw_sar.c","aw_sar_parse_dts_comm",0x104,*param_3
             );
    iVar1 = of_get_named_gpio_flags(param_2,"irq-gpio",0,0);
    param_3[1] = iVar1;
    if (iVar1 < 0) {
      param_3[1] = 0xffffffff;
      _dev_err(param_1," [%s:%s:%d] no irq gpio provided.\n","aw_sar.c","aw_sar_parse_dts_comm",
               0x10a);
      return 0xffffffff;
    }
    _dev_info(param_1," [%s:%s:%d] irq gpio provided ok.\n","aw_sar.c","aw_sar_parse_dts_comm",0x10d
             );
    iVar1 = of_property_read_variable_u32_array(param_2,"monitor_esd_flag",param_3 + 8,1,0);
    if (iVar1 < 0) {
      _dev_err(param_1," [%s:%s:%d] monitor_esd_flag failed!\n","aw_sar.c","aw_sar_parse_dts_comm",
               0x112);
    }
    else {
      _dev_info(param_1," [%s:%s:%d] monitor_esd_flag = %d\n","aw_sar.c","aw_sar_parse_dts_comm",
                0x115,param_3[8]);
    }
    iVar1 = of_property_read_variable_u32_array(param_2,"channel_use_flag",param_3 + 2,1,0);
    if (-1 < iVar1) {
      _dev_info(param_1," [%s:%s:%d] channel_use_flag = 0x%x\n","aw_sar.c","aw_sar_parse_dts_comm",
                0x11d,param_3[2]);
      lVar2 = of_find_property(param_2,"aw_sar,pin_set_inter_pull-up",0);
      *(bool *)((long)param_3 + 0xd) = lVar2 != 0;
      _dev_info(param_1," [%s:%s:%d] aw_sar,use_inter_pull_up = <%d>\n","aw_sar.c",
                "aw_sar_parse_dts_comm",0x122);
      lVar2 = of_find_property(param_2,"aw_sar,using_pm_ops",0);
      *(bool *)((long)param_3 + 0xe) = lVar2 != 0;
      _dev_info(param_1," [%s:%s:%d] aw_sar,pin_set_inter_pull-up = <%d>\n","aw_sar.c",
                "aw_sar_parse_dts_comm",0x125);
      lVar2 = of_find_property(param_2,"aw_sar,update_fw",0);
      *(bool *)((long)param_3 + 0xf) = lVar2 != 0;
      _dev_info(param_1," [%s:%s:%d] aw_sar,update_fw = <%d>\n","aw_sar.c","aw_sar_parse_dts_comm",
                0x128);
      lVar2 = of_find_property(param_2,"aw_sar,use_plug_cail",0);
      *(bool *)(param_3 + 4) = lVar2 != 0;
      _dev_info(param_1," [%s:%s:%d] aw_sar,use_plug_cail_flag = <%d>\n","aw_sar.c",
                "aw_sar_parse_dts_comm",299);
      lVar2 = of_find_property(param_2,"aw_sar,new_fw_format",0);
      *(bool *)((long)param_3 + 0x11) = lVar2 != 0;
      _dev_info(param_1," [%s:%s:%d] aw_sar,new_fw_format_flag = <%d>\n","aw_sar.c",
                "aw_sar_parse_dts_comm",0x12e);
      of_property_read_string_helper(param_2,"platform_state",param_3 + 6,1,0);
      if (*(long *)(param_3 + 6) == 0) {
        return 0;
      }
      _dev_info(param_1," [%s:%s:%d] platform_state = <%s>\n","aw_sar.c","aw_sar_parse_dts_comm",
                0x132);
      return 0;
    }
    pcVar3 = " [%s:%s:%d] channel_use_flag failed!\n";
    uVar4 = 0x11a;
  }
  _dev_err(param_1,pcVar3,"aw_sar.c","aw_sar_parse_dts_comm",uVar4);
  return 0xffffffff;
}



//------------------------------------------------------------
// aw_sar_check_init_over_irq @ 001037ac size=436
// signature: undefined aw_sar_check_init_over_irq(void)
// callers: [aw_sar_chip_init, aw96xxx_monitor_work_func]
//------------------------------------------------------------

void aw_sar_check_init_over_irq(long *param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  code *pcVar5;
  long lVar6;
  short *psVar7;
  short sVar8;
  uint local_6c;
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  psVar7 = *(short **)(param_1[0x50] + 0x20);
  if (psVar7 == (short *)0x0) {
    uVar4 = 8;
  }
  else {
    pcVar5 = *(code **)(psVar7 + 0xc);
    if (pcVar5 == (code *)0x0) {
      local_6c = 0;
      lVar6 = *param_1;
      sVar8 = *psVar7;
      do {
        iVar3 = aw_sar_i2c_read(lVar6,*(undefined4 *)(psVar7 + 2),&local_6c);
        if (iVar3 < 0) {
          uVar4 = 0xffffffff;
          goto LAB_00103910;
        }
        if ((local_6c >> (ulong)(*(uint *)(psVar7 + 4) & 0x1f) & *(uint *)(psVar7 + 6)) ==
            *(uint *)(psVar7 + 8)) {
          uVar4 = 0;
          goto LAB_00103910;
        }
        lVar1 = lVar6 + 0x20;
        _dev_err(lVar1," [%s:%s:%d] init over irq no ok! val:0x%x cnt: %d\n","aw_sar.c",
                 "aw_sar_check_init_over_irq_func",0x75,local_6c,(int)sVar8);
        __const_udelay(0x418958);
        bVar2 = sVar8 != 0;
        sVar8 = sVar8 + -1;
      } while (bVar2);
      _dev_err(lVar1," [%s:%s:%d] init over irq error!\n","aw_sar.c",
               "aw_sar_check_init_over_irq_func",0x7b);
      pcVar5 = *(code **)(*(long *)(param_1[0x50] + 0x20) + 0x20);
      if (pcVar5 != (code *)0x0) {
        if (*(int *)(pcVar5 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1038fc);
          (*pcVar5)();
        }
        uVar4 = (*pcVar5)(param_1);
        if ((int)uVar4 == 0) {
          *(undefined1 *)(param_1 + 0x36) = 1;
          goto LAB_00103910;
        }
      }
      uVar4 = 0xfffffffb;
    }
    else {
      if (*(int *)(pcVar5 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x103810);
        (*pcVar5)();
      }
      uVar4 = (*pcVar5)(param_1);
    }
  }
LAB_00103910:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// aw_sar_soft_reset @ 00103964 size=176
// signature: undefined aw_sar_soft_reset(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_sar_soft_reset(long *param_1)

{
  int iVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  undefined2 *puVar5;
  
  puVar5 = *(undefined2 **)(param_1[0x50] + 0x18);
  if (puVar5 == (undefined2 *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    pcVar3 = *(code **)(puVar5 + 8);
    if (pcVar3 == (code *)0x0) {
      lVar4 = *param_1;
      iVar1 = aw_sar_i2c_write(lVar4,*puVar5,*(undefined4 *)(puVar5 + 2));
      if (iVar1 < 0) {
        _dev_err(lVar4 + 0x20," [%s:%s:%d] soft_reset error: %d\n","aw_sar.c",
                 "aw_sar_soft_reset_func",0x89,iVar1);
        uVar2 = 0xffffffff;
      }
      else {
        msleep(*(undefined4 *)(puVar5 + 4));
        uVar2 = 0;
      }
    }
    else {
      if (*(int *)(pcVar3 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1039a0);
        (*pcVar3)();
      }
      uVar2 = (*pcVar3)();
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// aw_sar_load_def_reg_bin @ 00103a18 size=228
// signature: undefined aw_sar_load_def_reg_bin(void)
// callers: [aw_sar_update_reg_set_func, aw_sar_update_reg_set, aw_sar_update_work, aw96xxx_monitor_work_func]
//------------------------------------------------------------

undefined8 aw_sar_load_def_reg_bin(long param_1)

{
  undefined8 uVar1;
  char *param3;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(*(long *)(param_1 + 0x280) + 0x30);
  if ((puVar2 == (undefined8 *)0x0) || (param3 = (char *)*puVar2, param3 == (char *)0x0)) {
    _dev_err(*(undefined8 *)(param_1 + 8),
             " [%s:%s:%d] p_reg_bin is NULL or bin_name is NULL error\n","aw_sar.c",
             "aw_sar_load_def_reg_bin",0x266);
    uVar1 = 8;
    *(undefined1 *)(param_1 + 0x1b2) = 9;
  }
  else {
    if (*(char **)(param_1 + 0x1d8) == (char *)0x0) {
      snprintf((char *)(param_1 + 0x1e8),0x1e,"%s_%d.bin",param3,*(int *)(param_1 + 0x1c0));
    }
    else {
      snprintf((char *)(param_1 + 0x1e8),0x1e,"%s_%s_%d.bin",param3,*(char **)(param_1 + 0x1d8),
               *(int *)(param_1 + 0x1c0));
    }
    _dev_info(*(undefined8 *)(param_1 + 8)," [%s:%s:%d] reg_name:%s\n","aw_sar.c",
              "aw_sar_load_def_reg_bin",0x272,param_1 + 0x1e8);
    *(undefined8 *)(param_1 + 0x208) =
         *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x280) + 0x30) + 8);
    uVar1 = aw_sar_load_bin_comm(param_1);
  }
  return uVar1;
}



//------------------------------------------------------------
// aw_sar_update_fw @ 00103b00 size=116
// signature: undefined aw_sar_update_fw(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_sar_update_fw(long param_1)

{
  undefined8 uVar1;
  long *plVar2;
  
  plVar2 = *(long **)(*(long *)(param_1 + 0x280) + 0x28);
  if ((plVar2 == (long *)0x0) || (*plVar2 == 0)) {
    uVar1 = 0xffffffff;
  }
  else {
    *(long *)(param_1 + 0x208) = plVar2[1];
    *(long *)(param_1 + 0x210) = plVar2[2];
    snprintf((char *)(param_1 + 0x1e8),0x1e,"%s_%d.bin",(char *)*plVar2,*(int *)(param_1 + 0x1c0));
    uVar1 = aw_sar_load_bin_comm(param_1);
  }
  return uVar1;
}



//------------------------------------------------------------
// aw_sar_update_reg_set_func @ 00103b78 size=64
// signature: undefined aw_sar_update_reg_set_func(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_sar_update_reg_set_func(long param_1)

{
  aw_sar_load_def_reg_bin();
  aw_sar_mode_set(param_1,*(undefined4 *)(*(long *)(*(long *)(param_1 + 0x280) + 0x38) + 4));
  return 0;
}



//------------------------------------------------------------
// aw_sar_mode_set @ 00103bbc size=312
// signature: undefined aw_sar_mode_set(void)
// callers: [aw_sar_suspend, aw_sar_update_reg_set_func, aw_sar_resume, aw_sar_update_reg_set, capsensor_set_enable, aw_sar_update_work, aw_sar_mode_operation_set, mode_store, aw_sar_i2c_shutdown, aw96xxx_monitor_work_func]
//------------------------------------------------------------

void aw_sar_mode_set(undefined8 *param_1,uint param_2)

{
  code *pcVar1;
  ulong uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  byte *pbVar5;
  
  puVar3 = *(undefined8 **)(param_1[0x50] + 0x68);
  if (puVar3 != (undefined8 *)0x0) {
    pcVar1 = (code *)puVar3[2];
    if (pcVar1 == (code *)0x0) {
      uVar2 = (ulong)*(byte *)(puVar3 + 1);
      if (uVar2 != 0) {
        uVar4 = *param_1;
        pbVar5 = (byte *)*puVar3;
        do {
          if ((((uint)pbVar5[1] == (param_2 & 0xff)) &&
              (pbVar5[2] == *(byte *)((long)param_1 + 0x1b1))) &&
             ((*pbVar5 == 0 || ((*pbVar5 & *(byte *)((long)param_1 + 0x19a)) != 0)))) {
            pcVar1 = *(code **)(pbVar5 + 8);
            if (pcVar1 != (code *)0x0) {
              if (*(int *)(pcVar1 + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
                pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103c88);
                (*pcVar1)();
              }
              (*pcVar1)(uVar4);
            }
            pcVar1 = *(code **)(pbVar5 + 0x10);
            if (pcVar1 != (code *)0x0) {
              if (*(int *)(pcVar1 + -4) != 0x1a23ed84) {
                    /* WARNING: Does not return */
                pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103cb0);
                (*pcVar1)();
              }
              (*pcVar1)(uVar4);
            }
            pcVar1 = *(code **)(pbVar5 + 0x18);
            if (pcVar1 != (code *)0x0) {
              if (*(int *)(pcVar1 + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
                pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103cd8);
                (*pcVar1)();
              }
              (*pcVar1)(uVar4);
            }
            break;
          }
          pbVar5 = pbVar5 + 0x20;
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
      }
      *(char *)((long)param_1 + 0x1b1) = (char)param_2;
    }
    else {
      if (*(int *)(pcVar1 + -4) != -0x1b09ea7e) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103c0c);
        (*pcVar1)();
      }
      (*pcVar1)(param_1,param_2);
    }
  }
  return;
}



//------------------------------------------------------------
// aw_sar_int_output @ 00103cf8 size=144
// signature: undefined aw_sar_int_output(void)
// callers: []
//------------------------------------------------------------

void aw_sar_int_output(long param_1,int param_2)

{
  long lVar1;
  undefined *puVar2;
  undefined8 uVar3;
  
  _printk(&DAT_0010aba3,"aw_sar_int_output",param_2);
  if (param_2 == 1) {
    lVar1 = *(long *)(param_1 + 0xa0);
    if (lVar1 == 0) {
      puVar2 = &DAT_00109ec2;
      goto LAB_00103d78;
    }
    uVar3 = *(undefined8 *)(param_1 + 0xb0);
  }
  else {
    if (param_2 != 0) {
      return;
    }
    lVar1 = *(long *)(param_1 + 0xa0);
    if (lVar1 == 0) {
      puVar2 = &DAT_0010b28c;
LAB_00103d78:
      _printk(puVar2,"aw_sar_int_output");
      return;
    }
    uVar3 = *(undefined8 *)(param_1 + 0xb8);
  }
  pinctrl_select_state(lVar1,uVar3);
  return;
}



//------------------------------------------------------------
// aw_sar_chip_init @ 00103d8c size=636
// signature: undefined aw_sar_chip_init(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 aw_sar_chip_init(long *param_1)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  code *pcVar6;
  undefined2 *puVar7;
  
  if (((param_1[0x50] != 0) &&
      (puVar5 = *(undefined8 **)(param_1[0x50] + 0x10), puVar5 != (undefined8 *)0x0)) &&
     (pcVar6 = (code *)*puVar5, pcVar6 != (code *)0x0)) {
    if (*(int *)(pcVar6 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103dd8);
      (*pcVar6)();
    }
    iVar1 = (*pcVar6)(param_1);
    if (iVar1 == 0) {
      puVar7 = *(undefined2 **)(param_1[0x50] + 0x18);
      if (puVar7 == (undefined2 *)0x0) {
LAB_00103fcc:
        lVar2 = param_1[1];
        pcVar3 = " [%s:%s:%d] soft_reset error!\n";
        uVar4 = 0x7da;
      }
      else {
        pcVar6 = *(code **)(puVar7 + 8);
        if (pcVar6 == (code *)0x0) {
          lVar2 = *param_1;
          iVar1 = aw_sar_i2c_write(lVar2,*puVar7,*(undefined4 *)(puVar7 + 2));
          if (iVar1 < 0) {
            _dev_err(lVar2 + 0x20," [%s:%s:%d] soft_reset error: %d\n","aw_sar.c",
                     "aw_sar_soft_reset_func",0x89,iVar1);
            goto LAB_00103fcc;
          }
          msleep(*(undefined4 *)(puVar7 + 4));
        }
        else {
          if (*(int *)(pcVar6 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103e10);
            (*pcVar6)();
          }
          iVar1 = (*pcVar6)(param_1);
          if (iVar1 != 0) goto LAB_00103fcc;
        }
        iVar1 = aw_sar_check_init_over_irq(param_1);
        if (iVar1 == 0) {
          lVar2 = param_1[0x50];
          pcVar6 = *(code **)(lVar2 + 0x98);
          if (pcVar6 != (code *)0x0) {
            if (*(int *)(pcVar6 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x8229,0x103e70);
              (*pcVar6)();
            }
            iVar1 = (*pcVar6)(param_1);
            if (iVar1 != 0) {
              _dev_err(param_1[1]," [%s:%s:%d] chip_other_operation error!\n","aw_sar.c",
                       "aw_sar_chip_init",0x7e7);
              pcVar6 = *(code **)(param_1[0x50] + 0xa0);
              if (pcVar6 == (code *)0x0) {
                return 0xffffffff;
              }
              if (*(int *)(pcVar6 + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
                pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103f9c);
                (*pcVar6)();
              }
              (*pcVar6)(param_1);
              return 0xffffffff;
            }
            lVar2 = param_1[0x50];
          }
          if (*(long *)(lVar2 + 0x30) != 0) {
            pcVar6 = *(code **)(*(long *)(lVar2 + 0x30) + 0x20);
            if (pcVar6 != (code *)0x0) {
              if (*(int *)(pcVar6 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
                pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103ea8);
                (*pcVar6)();
              }
              (*pcVar6)(param_1);
            }
            param_1[3] = 0xfffffffe0;
            param_1[4] = (long)(param_1 + 4);
            param_1[5] = (long)(param_1 + 4);
            param_1[6] = (long)aw_sar_update_work;
            init_timer_key(param_1 + 9,&delayed_work_timer_fn,0x200000,0,0);
            queue_delayed_work_on(0x20,_system_wq,param_1 + 3,0x4e2);
          }
          return 0;
        }
        lVar2 = param_1[1];
        pcVar3 = " [%s:%s:%d] check_init_over_irqt error!\n";
        uVar4 = 0x7e0;
      }
      goto LAB_00103fec;
    }
  }
  lVar2 = param_1[1];
  pcVar3 = " [%s:%s:%d] check_chipid error!\n";
  uVar4 = 0x7d3;
LAB_00103fec:
  _dev_err(lVar2,pcVar3,"aw_sar.c","aw_sar_chip_init",uVar4);
  return 0xffffffff;
}



//------------------------------------------------------------
// aw_sar_update_work @ 0010400c size=472
// signature: undefined aw_sar_update_work(void)
// callers: []
//------------------------------------------------------------

void aw_sar_update_work(long param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  long *plVar4;
  uint uVar5;
  
  puVar2 = (undefined8 *)(param_1 + -0x18);
  mutex_lock(&aw_sar_lock);
  if (*(char *)(param_1 + 0x1b7) != '\0') {
    _dev_info(*(undefined8 *)(param_1 + -0x10)," [%s:%s:%d] firmware upgrade start!\n","aw_sar.c",
              "aw_sar_update_work",0x599);
    plVar4 = *(long **)(*(long *)(param_1 + 0x268) + 0x28);
    if ((plVar4 != (long *)0x0) && (*plVar4 != 0)) {
      *(long *)(param_1 + 0x1f0) = plVar4[1];
      *(long *)(param_1 + 0x1f8) = plVar4[2];
      snprintf((char *)(param_1 + 0x1d0),0x1e,"%s_%d.bin",(char *)*plVar4,*(int *)(param_1 + 0x1a8))
      ;
      iVar1 = aw_sar_load_bin_comm(puVar2);
      if (iVar1 == 0) {
        _dev_info(*(undefined8 *)(param_1 + -0x10)," [%s:%s:%d] protocol upgrade firmware ok!\n",
                  "aw_sar.c","aw_sar_update_work",0x59f);
        goto LAB_00104040;
      }
    }
    _dev_err(*(undefined8 *)(param_1 + -0x10)," [%s:%s:%d] protocol upgrade firmware error!\n",
             "aw_sar.c","aw_sar_update_work",0x59c);
    *(undefined1 *)(param_1 + 0x19a) = 6;
  }
LAB_00104040:
  iVar1 = aw_sar_load_def_reg_bin(puVar2);
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + 0x19a) = 7;
    _dev_err(*(undefined8 *)(param_1 + -0x10)," [%s:%s:%d] reg_bin load err!\n","aw_sar.c",
             "aw_sar_update_work",0x5a7);
    plVar4 = *(long **)(*(long *)(param_1 + 0x268) + 0x48);
    if (plVar4 != (long *)0x0) {
      if ((int)plVar4[1] != 0) {
        uVar3 = *puVar2;
        uVar5 = 0;
        do {
          iVar1 = aw_sar_i2c_write(uVar3,*(undefined4 *)(*plVar4 + (long)(int)uVar5 * 4),
                                   *(undefined4 *)(*plVar4 + (long)(int)(uVar5 + 1) * 4));
          if (iVar1 != 0) break;
          uVar5 = uVar5 + 2;
        } while (uVar5 < *(uint *)(plVar4 + 1));
      }
      *(undefined1 *)(param_1 + 0x180) = 1;
    }
  }
  aw_sar_mode_set(puVar2,**(undefined4 **)(*(long *)(param_1 + 0x268) + 0x38));
  if (*(char *)(param_1 + 0x204) == '\x01') {
    enable_irq(*(undefined4 *)(param_1 + 0x200));
    *(undefined1 *)(param_1 + 0x204) = 0;
  }
  mutex_unlock(&aw_sar_lock);
  return;
}



//------------------------------------------------------------
// aw_sar_para_loaded @ 001041e4 size=124
// signature: undefined aw_sar_para_loaded(void)
// callers: [aw96xxx_monitor_work_func]
//------------------------------------------------------------

void aw_sar_para_loaded(undefined8 *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long *plVar3;
  uint uVar4;
  
  plVar3 = *(long **)(param_1[0x50] + 0x48);
  if (plVar3 != (long *)0x0) {
    if ((int)plVar3[1] != 0) {
      uVar2 = *param_1;
      uVar4 = 0;
      do {
        iVar1 = aw_sar_i2c_write(uVar2,*(undefined4 *)(*plVar3 + (long)(int)uVar4 * 4),
                                 *(undefined4 *)(*plVar3 + (long)(int)(uVar4 + 1) * 4));
        if (iVar1 != 0) break;
        uVar4 = uVar4 + 2;
      } while (uVar4 < *(uint *)(plVar3 + 1));
    }
    *(undefined1 *)(param_1 + 0x33) = 1;
  }
  return;
}



//------------------------------------------------------------
// aw_sar_i2c_probe @ 00104264 size=4376
// signature: undefined aw_sar_i2c_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_sar_i2c_probe(long param_1)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  ulong uVar8;
  long *plVar9;
  long lVar10;
  char *pcVar11;
  char *pcVar12;
  code *pcVar13;
  long *plVar14;
  undefined8 uVar15;
  undefined8 *puVar16;
  long *plVar17;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined2 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined2 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  ulong local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined2 local_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  _printk(&DAT_00109acc,"aw_sar_i2c_probe");
  pcVar13 = *(code **)(*(long *)(*(long *)(param_1 + 0x18) + 0x10) + 0x20);
  if (*(int *)(pcVar13 + -4) != -0x70861f50) {
                    /* WARNING: Does not return */
    pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x1042cc);
    (*pcVar13)();
  }
  uVar8 = (*pcVar13)();
  if ((uVar8 & 1) == 0) {
    _printk(&DAT_0010c41d);
    uVar15 = 0xfffffffb;
    goto LAB_00104e1c;
  }
  lVar1 = param_1 + 0x20;
  plVar9 = (long *)devm_kmalloc(lVar1,0x290,0xdc0);
  if (plVar9 == (long *)0x0) {
    _printk(&DAT_0010b1d9);
    uVar15 = 0xffffffff;
    goto LAB_00104e1c;
  }
  *plVar9 = param_1;
  uVar15 = *(undefined8 *)(param_1 + 0x308);
  *(long **)(param_1 + 0xb8) = plVar9;
  plVar17 = plVar9 + 1;
  *plVar17 = lVar1;
  lVar10 = of_find_property(uVar15,"aw_sar,regulator-power-supply",0);
  *(bool *)((long)plVar9 + 0x1cc) = lVar10 != 0;
  _dev_info(*plVar17," [%s:%s:%d] regulator-power-supply = <%d>\n","aw_sar.c",
            "aw_sar_regulator_power",0x818);
  if (*(char *)((long)plVar9 + 0x1cc) == '\0') {
LAB_00104580:
    iVar4 = aw963xx_check_chipid(plVar9);
    if (iVar4 == 0) {
      *(undefined1 *)((long)plVar9 + 0x1b3) = 0;
      aw963xx_init(plVar9);
      _dev_info(plVar9[1]," [%s:%s:%d] current use drvier is :%d\n","aw_sar.c",
                "aw_sar_get_chip_info",0x92f,0);
      if (*(long *)(plVar9[0x50] + 8) == 0) {
LAB_00104da0:
        _dev_err(*plVar17," [%s:%s:%d] platform_rsc_init error!\n","aw_sar.c","aw_sar_init",0x7ff);
LAB_00104dc4:
        uVar15 = 0x85b;
        goto LAB_00104de4;
      }
      uVar5 = aw_sar_parse_dts_comm(plVar9[1],*(undefined8 *)(*plVar9 + 0x308),plVar9 + 0x38);
      pcVar13 = (code *)**(undefined8 **)(plVar9[0x50] + 8);
      if (pcVar13 != (code *)0x0) {
        if (*(int *)(pcVar13 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
          pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10460c);
          (*pcVar13)();
        }
        uVar6 = (*pcVar13)(plVar9);
        uVar5 = uVar6 | uVar5;
      }
      if (uVar5 != 0) {
        _dev_err(*plVar17," [%s:%s:%d] parse dts error!\n","aw_sar.c","aw_sar_platform_rsc_init",
                 0x74c);
        goto LAB_00104da0;
      }
      __mutex_init(&aw_sar_lock,"&aw_sar_lock",&aw_sar_init_lock___key);
      uVar7 = *(undefined4 *)(*(long *)(plVar9[0x50] + 0x38) + 8);
      *(undefined1 *)(plVar9 + 0x36) = 0;
      *(undefined1 *)((long)plVar9 + 0x1b2) = 0;
      *(char *)((long)plVar9 + 0x1b1) = (char)uVar7;
      if ((char)plVar9[0x3a] != '\0') {
        plVar14 = plVar9 + 0x1e;
        *plVar14 = (long)aw_sar_ps_notify_callback;
        plVar9[0x18] = 0xfffffffe0;
        plVar9[0x19] = (long)(plVar9 + 0x19);
        plVar9[0x1a] = (long)(plVar9 + 0x19);
        plVar9[0x1b] = (long)aw_sar_ps_notify_callback_work;
        iVar4 = power_supply_reg_notifier(plVar14);
        if (iVar4 == 0) {
          puVar16 = (undefined8 *)power_supply_get_by_name(&DAT_0010bd58);
          if (puVar16 != (undefined8 *)0x0) {
            local_90 = 0;
            iVar4 = power_supply_get_property(puVar16,4,&local_90);
            if (iVar4 != 0) {
              _dev_err(*plVar17," [%s:%s:%d] %s psy get property failed\n","aw_sar.c",
                       "aw_sar_ps_get_state",0x6c2,*(undefined8 *)*puVar16);
              _dev_err(*plVar17," [%s:%s:%d] psy get property failed rc=%d\n","aw_sar.c",
                       "aw_sar_ps_notify_init",0x701,iVar4);
              _dev_err(*plVar17," [%s:%s:%d] free_ps_notifier enter\n","aw_sar.c",
                       "aw_sar_ps_notify_init",0x707);
              power_supply_unreg_notifier(plVar14);
              goto LAB_001049ac;
            }
            pcVar11 = "online";
            if ((int)local_90 == 0) {
              pcVar11 = "not online";
            }
            *(bool *)((long)plVar9 + 0x199) = (int)local_90 != 0;
            _dev_info(plVar9[1]," [%s:%s:%d] %s is %s\n","aw_sar.c","aw_sar_ps_get_state",0x6c8,
                      *(undefined8 *)*puVar16,pcVar11);
          }
          goto LAB_00104654;
        }
        _dev_err(*plVar17," [%s:%s:%d] Unable to register ps_notifier: %d\n","aw_sar.c",
                 "aw_sar_ps_notify_init",0x6f9,iVar4);
LAB_001049ac:
        _dev_err(*plVar17," [%s:%s:%d] error creating power supply notify\n","aw_sar.c",
                 "aw_sar_platform_rsc_init",0x757);
LAB_00104d90:
        if ((char)plVar9[0x3a] != '\0') {
          power_supply_unreg_notifier(plVar9 + 0x1e);
        }
        goto LAB_00104da0;
      }
LAB_00104654:
      if (*(char *)((long)plVar9 + 0x1cd) != '\0') {
        local_60 = 0;
        local_70 = 0;
        uStack_68 = 0;
        local_80 = 0;
        uStack_78 = 0;
        local_90 = 0;
        uStack_88 = 0;
        local_98 = 0;
        local_a8 = 0;
        uStack_a0 = 0;
        local_b8 = 0;
        uStack_b0 = 0;
        local_c8 = 0;
        uStack_c0 = 0;
        local_d0 = 0;
        local_e0 = 0;
        uStack_d8 = 0;
        local_f0 = 0;
        uStack_e8 = 0;
        local_100 = 0;
        uStack_f8 = 0;
        uVar8 = devm_pinctrl_get(plVar9[1]);
        plVar9[0x14] = uVar8;
        if ((uVar8 == 0) || (0xfffffffffffff000 < uVar8)) {
          _printk(&DAT_0010b99d,"aw_sar_pinctrl_init");
        }
        else {
          snprintf((char *)&local_90,0x32,"aw_default_sar%d",(int)plVar9[0x38]);
          uVar8 = pinctrl_lookup_state(plVar9[0x14],&local_90);
          plVar9[0x15] = uVar8;
          if ((uVar8 == 0) || (0xfffffffffffff000 < uVar8)) {
            lVar10 = *plVar17;
            pcVar11 = " [%s:%s:%d] Failed get pinctrl state:default state\n";
            uVar15 = 0x617;
          }
          else {
            snprintf((char *)&local_100,0x32,"aw_int_output_high_sar%d",(int)plVar9[0x38]);
            uVar8 = pinctrl_lookup_state(plVar9[0x14],&local_100);
            plVar9[0x16] = uVar8;
            if ((uVar8 == 0) || (0xfffffffffffff000 < uVar8)) {
              lVar10 = *plVar17;
              pcVar11 = " [%s:%s:%d] Failed get pinctrl state:output_high\n";
              uVar15 = 0x621;
            }
            else {
              snprintf((char *)&local_c8,0x32,"aw_int_output_low_sar%d",(int)plVar9[0x38]);
              uVar8 = pinctrl_lookup_state(plVar9[0x14],&local_c8);
              plVar9[0x17] = uVar8;
              if ((uVar8 != 0) && (uVar8 < 0xfffffffffffff001)) {
                _printk(&DAT_0010aba3,"aw_sar_int_output",1);
                if (plVar9[0x14] == 0) {
                  _printk(&DAT_00109ec2,"aw_sar_int_output");
                }
                else {
                  pinctrl_select_state(plVar9[0x14],plVar9[0x16]);
                }
                goto LAB_0010465c;
              }
              lVar10 = *plVar17;
              pcVar11 = " [%s:%s:%d] Failed get pinctrl state:output_low\n";
              uVar15 = 0x62b;
            }
          }
          _dev_err(lVar10,pcVar11,"aw_sar.c","aw_sar_pinctrl_init",uVar15);
          devm_pinctrl_put(plVar9[0x14]);
        }
        plVar9[0x14] = 0;
        _dev_err(plVar9[1]," [%s:%s:%d] Failed get wanted pinctrl state\n","aw_sar.c",
                 "aw_sar_platform_rsc_init",0x76b);
LAB_00104d7c:
        if ((*(char *)((long)plVar9 + 0x1cd) != '\0') && (plVar9[0x14] != 0)) {
          devm_pinctrl_put();
        }
        goto LAB_00104d90;
      }
LAB_0010465c:
      *(long **)(*plVar9 + 0xb8) = plVar9;
      uVar5 = sysfs_create_group(*plVar9 + 0x20,aw_sar_attribute_group);
      if (*(char *)((long)plVar9 + 0x1cf) != '\0') {
        uVar6 = sysfs_create_group(*plVar9 + 0x20,aw_sar_update_attribute_group);
        uVar5 = uVar6 | uVar5;
      }
      pcVar13 = *(code **)(*(long *)(plVar9[0x50] + 8) + 0x10);
      if (pcVar13 != (code *)0x0) {
        if (*(int *)(pcVar13 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
          pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x1046c8);
          (*pcVar13)();
        }
        uVar6 = (*pcVar13)(plVar9);
        uVar5 = uVar6 | uVar5;
      }
      if (uVar5 != 0) {
        lVar10 = *plVar17;
        pcVar11 = " [%s:%s:%d] create node error!\n";
        pcVar12 = "aw_sar_platform_rsc_init";
        uVar15 = 0x774;
LAB_00104cbc:
        _dev_err(lVar10,pcVar11,"aw_sar.c",pcVar12,uVar15);
        sysfs_remove_group(*plVar9 + 0x20,aw_sar_attribute_group);
        if (*(char *)((long)plVar9 + 0x1cf) != '\0') {
          sysfs_remove_group(*plVar9 + 0x20,aw_sar_update_attribute_group);
        }
        if ((*(long *)(plVar9[0x50] + 8) != 0) &&
           (pcVar13 = *(code **)(*(long *)(plVar9[0x50] + 8) + 0x18), pcVar13 != (code *)0x0)) {
          if (*(int *)(pcVar13 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
            pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x104d20);
            (*pcVar13)();
          }
          (*pcVar13)(plVar9);
        }
        goto LAB_00104d7c;
      }
      puVar16 = *(undefined8 **)(*(long *)(plVar9[0x50] + 8) + 0x30);
      if (puVar16 == (undefined8 *)0x0) {
        lVar10 = *plVar17;
        pcVar11 = " [%s:%s:%d] AW_INVALID_PARA\n";
        pcVar12 = "aw_sar_irq_init";
        uVar15 = 0x199;
LAB_00104c58:
        _dev_err(lVar10,pcVar11,"aw_sar.c",pcVar12,uVar15);
LAB_00104c5c:
        _dev_err(*plVar17," [%s:%s:%d] interrupt initialization error!\n","aw_sar.c",
                 "aw_sar_platform_rsc_init",0x77b);
LAB_00104c80:
        if (((*(long *)(plVar9[0x50] + 8) == 0) ||
            (lVar10 = *(long *)(*(long *)(plVar9[0x50] + 8) + 0x30), lVar10 == 0)) ||
           (pcVar13 = *(code **)(lVar10 + 0x38), pcVar13 == (code *)0x0)) {
          lVar10 = *plVar17;
          pcVar11 = " [%s:%s:%d] aw_sar_irq_free\n";
          pcVar12 = "aw_sar_irq_free";
          uVar15 = 0x1ae;
        }
        else {
          if (*(int *)(pcVar13 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
            pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x104e70);
            (*pcVar13)();
          }
          (*pcVar13)(plVar9);
          lVar10 = plVar9[1];
          pcVar11 = " [%s:%s:%d] AW_INVALID_PARA\n";
          pcVar12 = "aw_sar_irq_free";
          uVar15 = 0x1ab;
        }
        goto LAB_00104cbc;
      }
      if (puVar16[6] == 0) {
        pcVar13 = (code *)puVar16[3];
        snprintf((char *)(plVar9 + 0x45),0x1e,"aw_sar%d_gpio",(int)plVar9[0x38]);
        snprintf((char *)((long)plVar9 + 0x246),0x1e,"aw_sar%d_irq",(int)plVar9[0x38]);
        if (0x1ff < *(uint *)((long)plVar9 + 0x1c4)) {
          lVar10 = *plVar17;
          pcVar11 = " [%s:%s:%d] irq gpio invalid!\n";
          pcVar12 = "aw_sar_irq_init_comm";
          uVar15 = 0x187;
          goto LAB_00104c58;
        }
        gpio_to_desc();
        uVar7 = gpiod_to_irq();
        *(undefined4 *)(plVar9 + 0x43) = uVar7;
        iVar4 = devm_gpio_request_one
                          (plVar9[1],*(undefined4 *)((long)plVar9 + 0x1c4),*puVar16,plVar9 + 0x45);
        if (iVar4 == 0) {
          pcVar2 = aw_sar_irq;
          if (pcVar13 != (code *)0x0) {
            pcVar2 = pcVar13;
          }
          iVar4 = devm_request_threaded_irq
                            (plVar9[1],(int)plVar9[0x43],puVar16[2],pcVar2,puVar16[1],
                             (char *)((long)plVar9 + 0x246),plVar9);
          if (iVar4 == 0) {
            _dev_info(plVar9[1]," [%s:%s:%d] IRQ request successfully!\n","aw_sar.c",
                      "aw_sar_irq_init_comm",0x17f);
            *(undefined1 *)(plVar9 + 0x37) = 1;
            _dev_info(plVar9[1]," [%s:%s:%d] %d\n","aw_sar.c","aw_sar_irq_init_comm",0x183,
                      *(undefined1 *)((long)plVar9 + 0x1b2));
          }
          else {
            _dev_err(plVar9[1]," [%s:%s:%d] failed to request IRQ %d: %d\n","aw_sar.c",
                     "aw_sar_irq_init_comm",0x17b,(int)plVar9[0x43]);
          }
        }
        else {
          _dev_err(*plVar17," [%s:%s:%d] request irq gpio failed, ret = %d\n","aw_sar.c",
                   "aw_sar_irq_init_comm",0x16b,iVar4);
        }
        _dev_info(plVar9[1]," [%s:%s:%d] disable_irq\n","aw_sar.c","aw_sar_irq_init_comm",0x18b);
        *(undefined1 *)((long)plVar9 + 0x21c) = 1;
        disable_irq((int)plVar9[0x43]);
      }
      else {
        _dev_err(plVar9[1]," [%s:%s:%d] p_irq_init_fn\n","aw_sar.c","aw_sar_irq_init",0x19e);
        pcVar13 = *(code **)(*(long *)(*(long *)(plVar9[0x50] + 8) + 0x30) + 0x30);
        if (*(int *)(pcVar13 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
          pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x104c08);
          (*pcVar13)();
        }
        iVar4 = (*pcVar13)(plVar9);
        if (iVar4 != 0) goto LAB_00104c5c;
      }
      pcVar13 = *(code **)(*(long *)((byte *)plVar9[0x50] + 8) + 0x20);
      if (pcVar13 == (code *)0x0) {
        lVar10 = devm_kmalloc(plVar9[1],(ulong)*(byte *)plVar9[0x50] * 0x28,0xdc0);
        plVar9[0x4f] = lVar10;
        if (lVar10 == 0) {
          lVar10 = *plVar17;
          pcVar11 = " [%s:%s:%d] devm_kzalloc err\n";
          uVar15 = 0x1bc;
LAB_00105300:
          _dev_err(lVar10,pcVar11,"aw_sar.c","aw_sar_input_init_comm",uVar15);
LAB_00105304:
          _dev_err(plVar9[1]," [%s:%s:%d] input_init error!\n","aw_sar.c","aw_sar_platform_rsc_init"
                   ,0x782);
          aw_sar_input_free(plVar9);
          goto LAB_00104c80;
        }
        if (*(char *)plVar9[0x50] != '\0') {
          uVar8 = 0;
          lVar10 = 8;
          do {
            iVar4 = snprintf((char *)(plVar9[0x4f] + lVar10 + 8),0x14,"Moto CapSense Ch%d",
                             (uint)uVar8);
            *(undefined4 *)(plVar9[0x4f] + lVar10 + -4) = 0;
            if ((*(uint *)(plVar9 + 0x39) >> (ulong)((uint)uVar8 & 0x1f) & 1) == 0) {
              *(undefined2 *)(plVar9[0x4f] + lVar10 + -8) = 0;
              *(undefined8 *)(plVar9[0x4f] + lVar10) = 0;
            }
            else {
              *(undefined2 *)(plVar9[0x4f] + lVar10 + -8) = 1;
              uVar15 = input_allocate_device(iVar4);
              *(undefined8 *)(plVar9[0x4f] + lVar10) = uVar15;
              plVar14 = *(long **)(plVar9[0x4f] + lVar10);
              if (plVar14 == (long *)0x0) goto LAB_00105304;
              *plVar14 = plVar9[0x4f] + lVar10 + 8;
              *(ulong *)(*(long *)(plVar9[0x4f] + lVar10) + 0x28) =
                   *(ulong *)(*(long *)(plVar9[0x4f] + lVar10) + 0x28) | 8;
              input_set_abs_params(*(undefined8 *)(plVar9[0x4f] + lVar10),0x19,0xffffffff,100,0,0);
              iVar4 = input_register_device(*(undefined8 *)(plVar9[0x4f] + lVar10));
              if (iVar4 != 0) {
                lVar10 = *plVar17;
                pcVar11 = " [%s:%s:%d] failed to register input device\n";
                uVar15 = 0x1d7;
                goto LAB_00105300;
              }
              input_event(*(undefined8 *)(plVar9[0x4f] + lVar10),3,0x19,0xffffffff);
              input_event(*(undefined8 *)(plVar9[0x4f] + lVar10),0,0,0);
            }
            uVar8 = uVar8 + 1;
            lVar10 = lVar10 + 0x28;
          } while (uVar8 < *(byte *)plVar9[0x50]);
        }
      }
      else {
        if (*(int *)(pcVar13 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
          pcVar13 = (code *)SoftwareBreakpoint(0x8229,0x104f54);
          (*pcVar13)();
        }
        iVar4 = (*pcVar13)(plVar9);
        if (iVar4 != 0) goto LAB_00105304;
      }
      iVar4 = aw_sar_chip_init(plVar9);
      if (iVar4 != 0) {
        aw_sar_input_free(plVar9);
        if (((*(long *)(plVar9[0x50] + 8) == 0) ||
            (lVar10 = *(long *)(*(long *)(plVar9[0x50] + 8) + 0x30), lVar10 == 0)) ||
           (pcVar13 = *(code **)(lVar10 + 0x38), pcVar13 == (code *)0x0)) {
          lVar10 = *plVar17;
          pcVar11 = " [%s:%s:%d] aw_sar_irq_free\n";
          uVar15 = 0x1ae;
        }
        else {
          if (*(int *)(pcVar13 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
            pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x105350);
            (*pcVar13)();
          }
          (*pcVar13)(plVar9);
          lVar10 = plVar9[1];
          pcVar11 = " [%s:%s:%d] AW_INVALID_PARA\n";
          uVar15 = 0x1ab;
        }
        _dev_err(lVar10,pcVar11,"aw_sar.c","aw_sar_irq_free",uVar15);
        sysfs_remove_group(*plVar9 + 0x20,aw_sar_attribute_group);
        if (*(char *)((long)plVar9 + 0x1cf) != '\0') {
          sysfs_remove_group(*plVar9 + 0x20,aw_sar_update_attribute_group);
        }
        if ((*(long *)(plVar9[0x50] + 8) != 0) &&
           (pcVar13 = *(code **)(*(long *)(plVar9[0x50] + 8) + 0x18), pcVar13 != (code *)0x0)) {
          if (*(int *)(pcVar13 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
            pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10526c);
            (*pcVar13)();
          }
          (*pcVar13)(plVar9);
        }
        if ((*(char *)((long)plVar9 + 0x1cd) != '\0') && (plVar9[0x14] != 0)) {
          devm_pinctrl_put();
        }
        goto LAB_00104dc4;
      }
      if ((int)plVar9[0x3c] == 0) {
        uVar15 = 0;
        goto LAB_00104e1c;
      }
      lVar10 = alloc_workqueue(&DAT_0010a613,0xe000a,1,"aw96xxx_sar_workqueue");
      plVar9[0x32] = lVar10;
      if (lVar10 != 0) {
        plVar9[0x21] = 0xfffffffe0;
        plVar9[0x22] = (long)(plVar9 + 0x22);
        plVar9[0x23] = (long)(plVar9 + 0x22);
        plVar9[0x24] = (long)aw96xxx_monitor_work_func;
        init_timer_key(plVar9 + 0x27,&delayed_work_timer_fn,0x200000,0,0);
        queue_delayed_work_on(0x20,plVar9[0x32],plVar9 + 0x21,0x4e2);
        uVar15 = 0;
        goto LAB_00104e1c;
      }
      _dev_err(lVar1," [%s:%s:%d] aw96xxx_sar_workqueue error\n\n","aw_sar.c","aw_sar_i2c_probe",
               0x863);
      uVar15 = 0;
      cVar3 = *(char *)((long)plVar9 + 0x1b3);
    }
    else {
      _dev_info(*plVar17," [%s:%s:%d] drvier:%d Not supported\n","aw_sar.c","aw_sar_get_chip_info",
                0x932,0);
      uVar15 = 0x854;
LAB_00104de4:
      _dev_err(lVar1," [%s:%s:%d] chip_init error!\n","aw_sar.c","aw_sar_i2c_probe",uVar15);
      uVar15 = 0xffffffff;
      cVar3 = *(char *)((long)plVar9 + 0x1b3);
    }
    if (cVar3 != '\0') {
                    /* WARNING: Does not return */
      pcVar13 = (code *)SoftwareBreakpoint(0x5512,0x1052bc);
      (*pcVar13)();
    }
    aw963xx_deinit(plVar9);
    cVar3 = *(char *)((long)plVar9 + 0x1cc);
  }
  else {
    local_80 = local_80 & 0xffffffff00000000;
    local_90 = 0;
    uStack_88 = 0;
    snprintf((char *)&local_90,0x14,"vcc%d",(int)plVar9[0x38]);
    uVar8 = regulator_get(plVar9[1],&local_90);
    plVar9[2] = uVar8;
    if (uVar8 < 0xfffffffffffff001) {
      iVar4 = regulator_count_voltages(uVar8);
      if ((0 < iVar4) && (iVar4 = regulator_set_voltage(plVar9[2],1700000,3600000), iVar4 != 0)) {
        _dev_err(plVar9[1]," [%s:%s:%d] regulator set vol failed rc = %d\n","aw_sar.c",
                 "aw_sar_regulator_power_init",0x65e,iVar4);
        regulator_put(plVar9[2]);
        goto LAB_001043dc;
      }
      iVar4 = regulator_enable(plVar9[2]);
      if (iVar4 == 0) {
        *(undefined1 *)((long)plVar9 + 0x1af) = 1;
        msleep(0x14);
      }
      else {
        _dev_err(*plVar17," [%s:%s:%d] regulator_enable vol failed rc = %d\n","aw_sar.c",
                 "aw_sar_power_enable",0x67f,iVar4);
      }
    }
    else {
      _dev_err(*plVar17," [%s:%s:%d] regulator get failed vcc rc = %d\n","aw_sar.c",
               "aw_sar_regulator_power_init",0x654);
LAB_001043dc:
      _dev_err(*plVar17," [%s:%s:%d] power init failed\n","aw_sar.c","aw_sar_regulator_power",0x81e)
      ;
    }
    iVar4 = regulator_get_voltage(plVar9[2]);
    if (1699999 < iVar4) goto LAB_00104580;
    __const_udelay(0x418958);
    iVar4 = regulator_get_voltage(plVar9[2]);
    if (1699999 < iVar4) goto LAB_00104580;
    __const_udelay(0x418958);
    iVar4 = regulator_get_voltage(plVar9[2]);
    if (1699999 < iVar4) goto LAB_00104580;
    __const_udelay(0x418958);
    iVar4 = regulator_get_voltage(plVar9[2]);
    if (1699999 < iVar4) goto LAB_00104580;
    __const_udelay(0x418958);
    iVar4 = regulator_get_voltage(plVar9[2]);
    if (1699999 < iVar4) goto LAB_00104580;
    __const_udelay(0x418958);
    iVar4 = regulator_get_voltage(plVar9[2]);
    if (1699999 < iVar4) goto LAB_00104580;
    __const_udelay(0x418958);
    iVar4 = regulator_get_voltage(plVar9[2]);
    if (1699999 < iVar4) goto LAB_00104580;
    __const_udelay(0x418958);
    iVar4 = regulator_get_voltage(plVar9[2]);
    if (1699999 < iVar4) goto LAB_00104580;
    __const_udelay(0x418958);
    iVar4 = regulator_get_voltage(plVar9[2]);
    if (1699999 < iVar4) goto LAB_00104580;
    __const_udelay(0x418958);
    iVar4 = regulator_get_voltage(plVar9[2]);
    if (1699999 < iVar4) goto LAB_00104580;
    __const_udelay(0x418958);
    msleep(0x14);
    _dev_err(plVar9[1]," [%s:%s:%d] get_voltage failed\n","aw_sar.c","aw_sar_regulator_power",0x823)
    ;
    if (*(char *)((long)plVar9 + 0x1af) != '\0') {
      regulator_disable(plVar9[2]);
      regulator_put(plVar9[2]);
    }
    _dev_err(lVar1," [%s:%s:%d] regulator_power error!\n","aw_sar.c","aw_sar_i2c_probe",0x84d);
    uVar15 = 0xfffffffd;
    cVar3 = *(char *)((long)plVar9 + 0x1cc);
  }
  if ((cVar3 != '\0') && (*(char *)((long)plVar9 + 0x1af) != '\0')) {
    regulator_disable(plVar9[2]);
    regulator_put(plVar9[2]);
  }
LAB_00104e1c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar15;
}



//------------------------------------------------------------
// aw_sar_i2c_remove @ 00105380 size=444
// signature: undefined aw_sar_i2c_remove(void)
// callers: []
//------------------------------------------------------------

void aw_sar_i2c_remove(long param_1)

{
  char *pcVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  long *plVar5;
  
  plVar5 = *(long **)(param_1 + 0xb8);
  pcVar3 = *(code **)(plVar5[0x50] + 0xa0);
  if (pcVar3 != (code *)0x0) {
    if (*(int *)(pcVar3 + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1053bc);
      (*pcVar3)();
    }
    (*pcVar3)(plVar5);
  }
  sysfs_remove_group(*plVar5 + 0x20,aw_sar_attribute_group);
  if (*(char *)((long)plVar5 + 0x1cf) != '\0') {
    sysfs_remove_group(*plVar5 + 0x20,aw_sar_update_attribute_group);
  }
  lVar4 = *(long *)(plVar5[0x50] + 8);
  if (lVar4 != 0) {
    pcVar3 = *(code **)(lVar4 + 0x18);
    if (pcVar3 != (code *)0x0) {
      if (*(int *)(pcVar3 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x105420);
        (*pcVar3)();
      }
      (*pcVar3)(plVar5);
      lVar4 = *(long *)(plVar5[0x50] + 8);
      if (lVar4 == 0) goto LAB_00105440;
    }
    if ((*(long *)(lVar4 + 0x30) != 0) &&
       (pcVar3 = *(code **)(*(long *)(lVar4 + 0x30) + 0x38), pcVar3 != (code *)0x0)) {
      if (*(int *)(pcVar3 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x105510);
        (*pcVar3)();
      }
      (*pcVar3)(plVar5);
      lVar4 = plVar5[1];
      pcVar1 = " [%s:%s:%d] AW_INVALID_PARA\n";
      uVar2 = 0x1ab;
      goto LAB_00105460;
    }
  }
LAB_00105440:
  lVar4 = plVar5[1];
  pcVar1 = " [%s:%s:%d] aw_sar_irq_free\n";
  uVar2 = 0x1ae;
LAB_00105460:
  _dev_err(lVar4,pcVar1,"aw_sar.c","aw_sar_irq_free",uVar2);
  aw_sar_input_free(plVar5);
  if ((*(char *)((long)plVar5 + 0x1cd) != '\0') && (plVar5[0x14] != 0)) {
    devm_pinctrl_put();
  }
  if ((*(char *)((long)plVar5 + 0x1cc) != '\0') && (*(char *)((long)plVar5 + 0x1af) != '\0')) {
    regulator_disable(plVar5[2]);
    regulator_put(plVar5[2]);
  }
  if ((char)plVar5[0x3a] != '\0') {
    power_supply_unreg_notifier(plVar5 + 0x1e);
  }
  if (*(char *)((long)plVar5 + 0x1b3) != '\0') {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10553c);
    (*pcVar3)();
  }
  aw963xx_deinit(plVar5);
  _dev_info(plVar5[1]," [%s:%s:%d] aw_sar_i2c_remove ok!\n","aw_sar.c","aw_sar_i2c_remove",0x895);
  return;
}



//------------------------------------------------------------
// aw_sar_i2c_shutdown @ 00105540 size=148
// signature: undefined aw_sar_i2c_shutdown(void)
// callers: []
//------------------------------------------------------------

void aw_sar_i2c_shutdown(long param_1)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0xb8);
  _dev_info(*(undefined8 *)(lVar3 + 8)," [%s:%s:%d] enter\n","aw_sar.c","aw_sar_i2c_shutdown",0x8d6)
  ;
  lVar1 = *(long *)(*(long *)(lVar3 + 0x280) + 8);
  if ((lVar1 != 0) && (lVar1 = *(long *)(lVar1 + 0x38), lVar1 != 0)) {
    pcVar2 = *(code **)(lVar1 + 0x20);
    if (pcVar2 == (code *)0x0) {
      aw_sar_mode_set(lVar3,*(undefined4 *)(lVar1 + 8));
    }
    else {
      if (*(int *)(pcVar2 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x1055b0);
        (*pcVar2)();
      }
      (*pcVar2)(lVar3);
    }
  }
  return;
}



//------------------------------------------------------------
// aw96xxx_monitor_work_func @ 001055d8 size=624
// signature: undefined aw96xxx_monitor_work_func(void)
// callers: []
//------------------------------------------------------------

void aw96xxx_monitor_work_func(long param_1)

{
  int iVar1;
  code *pcVar2;
  long *plVar3;
  long lVar4;
  undefined2 *puVar5;
  int local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  plVar3 = (long *)(param_1 + -0x108);
  local_3c = 0;
  mutex_lock(&aw_sar_lock);
  iVar1 = aw_sar_i2c_read(*plVar3,0,&local_3c);
  if (iVar1 != 0) {
    _dev_err(*(undefined8 *)(param_1 + -0x100)," [%s:%s:%d] read 0x0000 err: %d\n","aw_sar.c",
             "aw96xxx_monitor_work_func",0x7a3,iVar1);
    goto LAB_0010564c;
  }
  if ((local_3c == 0) && (*(char *)(param_1 + 0x90) != '\0')) {
    _dev_err(*(undefined8 *)(param_1 + -0x100)," [%s:%s:%d] aw96xxx may reset\n","aw_sar.c",
             "aw96xxx_monitor_work_func",0x7a9);
    *(undefined1 *)(param_1 + 0x90) = 0;
    if (*(char *)(param_1 + 0x114) == '\0') {
      disable_irq(*(undefined4 *)(param_1 + 0x110));
      *(undefined1 *)(param_1 + 0x114) = 1;
    }
    puVar5 = *(undefined2 **)(*(long *)(param_1 + 0x178) + 0x18);
    if (puVar5 != (undefined2 *)0x0) {
      pcVar2 = *(code **)(puVar5 + 8);
      if (pcVar2 == (code *)0x0) {
        lVar4 = *plVar3;
        iVar1 = aw_sar_i2c_write(lVar4,*puVar5,*(undefined4 *)(puVar5 + 2));
        if (-1 < iVar1) {
          msleep(*(undefined4 *)(puVar5 + 4));
          goto LAB_0010574c;
        }
        _dev_err(lVar4 + 0x20," [%s:%s:%d] soft_reset error: %d\n","aw_sar.c",
                 "aw_sar_soft_reset_func",0x89,iVar1);
      }
      else {
        if (*(int *)(pcVar2 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x105720);
          (*pcVar2)();
        }
        iVar1 = (*pcVar2)(plVar3);
        if (iVar1 == 0) {
LAB_0010574c:
          iVar1 = aw_sar_check_init_over_irq(plVar3);
          if (iVar1 != 0) {
            _dev_err(*(undefined8 *)(param_1 + -0x100)," [%s:%s:%d] check_init_over_irqt error!\n",
                     "aw_sar.c","aw96xxx_monitor_work_func",0x7b4);
            goto LAB_0010564c;
          }
          iVar1 = aw_sar_load_def_reg_bin(plVar3);
          if (iVar1 != 0) {
            *(undefined1 *)(param_1 + 0xaa) = 7;
            _dev_err(*(undefined8 *)(param_1 + -0x100)," [%s:%s:%d] reg_bin load err!\n","aw_sar.c",
                     "aw96xxx_monitor_work_func",0x7bb);
            aw_sar_para_loaded(plVar3);
          }
          aw_sar_mode_set(plVar3,*(undefined4 *)(*(long *)(*(long *)(param_1 + 0x178) + 0x38) + 4));
          if (*(char *)(param_1 + 0x114) == '\x01') {
            enable_irq(*(undefined4 *)(param_1 + 0x110));
            *(undefined1 *)(param_1 + 0x114) = 0;
          }
          goto LAB_00105638;
        }
      }
    }
    _dev_err(*(undefined8 *)(param_1 + -0x100)," [%s:%s:%d] soft_reset error!\n","aw_sar.c",
             "aw96xxx_monitor_work_func",0x7ae);
  }
  else {
LAB_00105638:
    queue_delayed_work_on(0x20,*(undefined8 *)(param_1 + 0x88),param_1,0x4e2);
  }
LAB_0010564c:
  mutex_unlock(&aw_sar_lock);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw_sar_input_free @ 00105848 size=284
// signature: undefined aw_sar_input_free(void)
// callers: [aw_sar_i2c_probe, aw_sar_i2c_remove]
//------------------------------------------------------------

void aw_sar_input_free(long param_1)

{
  undefined8 uVar1;
  char *pcVar2;
  char *pcVar3;
  undefined8 uVar4;
  long lVar5;
  code *pcVar6;
  ulong uVar7;
  ulong uVar8;
  
  lVar5 = *(long *)(*(long *)(param_1 + 0x280) + 8);
  if ((lVar5 == 0) || (pcVar6 = *(code **)(lVar5 + 0x28), pcVar6 == (code *)0x0)) {
    _dev_err(*(undefined8 *)(param_1 + 8)," [%s:%s:%d] aw_sar_input_free_comm\n","aw_sar.c",
             "aw_sar_input_free",0x203);
    uVar7 = (ulong)**(byte **)(param_1 + 0x280);
    if (**(byte **)(param_1 + 0x280) != 0) {
      uVar8 = 0;
      lVar5 = 8;
      do {
        if (*(long *)(*(long *)(param_1 + 0x278) + lVar5) != 0) {
          input_unregister_device();
          input_free_device(*(undefined8 *)(*(long *)(param_1 + 0x278) + lVar5));
          uVar7 = (ulong)**(byte **)(param_1 + 0x280);
        }
        uVar8 = uVar8 + 1;
        lVar5 = lVar5 + 0x28;
      } while (uVar8 < uVar7);
    }
    uVar1 = *(undefined8 *)(param_1 + 8);
    pcVar2 = " [%s:%s:%d] aw_sar_input_free ok\n";
    pcVar3 = "aw_sar_input_free_comm";
    uVar4 = 0x1f8;
  }
  else {
    if (*(int *)(pcVar6 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x105928);
      (*pcVar6)();
    }
    (*pcVar6)(param_1);
    uVar1 = *(undefined8 *)(param_1 + 8);
    pcVar2 = " [%s:%s:%d] AW_INVALID_PARA\n";
    pcVar3 = "aw_sar_input_free";
    uVar4 = 0x200;
  }
  _dev_err(uVar1,pcVar2,"aw_sar.c",pcVar3,uVar4);
  return;
}



//------------------------------------------------------------
// aw_sar_ps_notify_callback_work @ 00105968 size=96
// signature: undefined aw_sar_ps_notify_callback_work(void)
// callers: []
//------------------------------------------------------------

void aw_sar_ps_notify_callback_work(long param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  
  puVar1 = *(undefined4 **)(*(long *)(param_1 + 0x1c0) + 0x50);
  if (puVar1 != (undefined4 *)0x0) {
    pcVar2 = *(code **)(puVar1 + 4);
    if (pcVar2 == (code *)0x0) {
      aw_sar_i2c_write_bits(*(undefined8 *)(param_1 + -0xc0),*puVar1,puVar1[1],puVar1[2]);
    }
    else {
      if (*(int *)(pcVar2 + -4) != -0x272b8e18) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x1059a4);
        (*pcVar2)();
      }
      (*pcVar2)();
    }
  }
  return;
}



//------------------------------------------------------------
// aw_sar_ps_notify_callback @ 001059cc size=340
// signature: undefined aw_sar_ps_notify_callback(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 aw_sar_ps_notify_callback(long param_1,long param_2,undefined8 *param_3)

{
  long lVar1;
  int iVar2;
  char *__s1;
  char local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = '\0';
  if ((((param_2 == 0) && (param_3 != (undefined8 *)0x0)) && (((undefined8 *)*param_3)[6] != 0)) &&
     (__s1 = *(char **)*param_3, __s1 != (char *)0x0)) {
    iVar2 = strncmp(__s1,"usb",4);
    if (iVar2 == 0) {
      _dev_err(*(undefined8 *)(param_1 + -0xe8)," [%s:%s:%d] ps notification: event = %lu\n",
               "aw_sar.c","aw_sar_ps_notify_callback",0x6de,0);
      iVar2 = aw_sar_ps_get_state(param_1 + -0xf0,param_3,local_3c);
      if (iVar2 == 0) {
        if (*(char *)(param_1 + 0xa9) == local_3c[0]) {
          _dev_err(*(undefined8 *)(param_1 + -0xe8)," [%s:%s:%d] ps present state not change\n",
                   "aw_sar.c","aw_sar_ps_notify_callback",0x6e6);
        }
        else {
          *(char *)(param_1 + 0xa9) = local_3c[0];
          queue_work_on(0x20,_system_wq,param_1 + -0x30);
        }
      }
      else {
        _dev_err(*(undefined8 *)(param_1 + -0xe8)," [%s:%s:%d] psy get property failed,ret=%d\n",
                 "aw_sar.c","aw_sar_ps_notify_callback",0x6e1,iVar2);
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw_sar_ps_get_state @ 00105b20 size=256
// signature: undefined aw_sar_ps_get_state(void)
// callers: [aw_sar_ps_notify_callback]
//------------------------------------------------------------

int aw_sar_ps_get_state(long param_1,undefined8 *param_2,undefined8 param_3)

{
  char *pcVar1;
  long lVar2;
  int iVar3;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  iVar3 = power_supply_get_property(param_2,4,&local_40);
  if (iVar3 == 0) {
    pcVar1 = "online";
    if ((int)local_40 == 0) {
      pcVar1 = "not online";
    }
    *(bool *)param_3 = (int)local_40 != 0;
    _dev_info(*(undefined8 *)(param_1 + 8)," [%s:%s:%d] %s is %s\n","aw_sar.c","aw_sar_ps_get_state"
              ,0x6c8,*(undefined8 *)*param_2,pcVar1);
  }
  else {
    _dev_err(*(undefined8 *)(param_1 + 8)," [%s:%s:%d] %s psy get property failed\n","aw_sar.c",
             "aw_sar_ps_get_state",0x6c2,*(undefined8 *)*param_2);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// aw_sar_awrw_get @ 00105c24 size=452
// signature: undefined aw_sar_awrw_get(void)
// callers: []
//------------------------------------------------------------

long aw_sar_awrw_get(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  
  lVar4 = *(long *)(param_1 + 0x98);
  mutex_lock(&aw_sar_lock);
  lVar2 = *(long *)(*(long *)(lVar4 + 0x280) + 0x88);
  if ((lVar2 != 0) && (pcVar3 = *(code **)(lVar2 + 8), pcVar3 != (code *)0x0)) {
    if (*(int *)(pcVar3 + -4) != 0x3194cf9a) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x105c84);
      (*pcVar3)();
    }
    lVar2 = (*pcVar3)(lVar4,param_3);
    goto LAB_00105d94;
  }
  if (*(long *)(lVar4 + 0x270) == 0) {
    _dev_err(*(undefined8 *)(lVar4 + 8)," [%s:%s:%d] p_i2c_tranfar_data is NULL\n","aw_sar.c",
             "aw_sar_awrw_get_func",0x313);
    iVar1 = 0;
  }
  else {
    if (*(char *)(lVar4 + 0x268) == '\x02') {
      if (*(int *)(lVar4 + 0x26c) == 0) {
LAB_00105d5c:
        uVar5 = 0;
      }
      else {
        uVar6 = 0;
        uVar5 = 0;
        do {
          iVar1 = snprintf((char *)(param_3 + uVar5),0x1000 - uVar5,"0x%02x,",
                           (uint)*(byte *)(*(long *)(lVar4 + 0x270) + uVar6));
          uVar5 = (ulong)(uint)(iVar1 + (int)uVar5);
          uVar6 = uVar6 + 1;
        } while (uVar6 < *(uint *)(lVar4 + 0x26c));
      }
    }
    else {
      if ((uint)*(byte *)(lVar4 + 0x26b) * (uint)*(byte *)(lVar4 + 0x26a) == 0) goto LAB_00105d5c;
      lVar2 = 0;
      uVar5 = 0;
      do {
        iVar1 = snprintf((char *)(param_3 + uVar5),0x1000 - uVar5,"0x%02x,",
                         (uint)*(byte *)(*(long *)(lVar4 + 0x270) + (ulong)*(byte *)(lVar4 + 0x269)
                                        + lVar2));
        uVar5 = (ulong)(uint)(iVar1 + (int)uVar5);
        lVar2 = lVar2 + 1;
      } while ((uint)lVar2 < (uint)*(byte *)(lVar4 + 0x26b) * (uint)*(byte *)(lVar4 + 0x26a));
    }
    iVar1 = (int)uVar5;
    snprintf((char *)(param_3 + uVar5 + -1),0x1000 - uVar5,"\n");
    devm_kfree(*(undefined8 *)(lVar4 + 8),*(undefined8 *)(lVar4 + 0x270));
    *(undefined8 *)(lVar4 + 0x270) = 0;
  }
  lVar2 = (long)iVar1;
LAB_00105d94:
  mutex_unlock(&aw_sar_lock);
  return lVar2;
}



//------------------------------------------------------------
// aw_sar_awrw_set @ 00105dec size=1868
// signature: undefined aw_sar_awrw_set(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_sar_awrw_set(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  size_t sVar7;
  undefined8 uVar8;
  long lVar9;
  char *pcVar10;
  ulong uVar11;
  char *pcVar12;
  undefined8 uVar13;
  uint uVar14;
  code *pcVar15;
  undefined8 *puVar16;
  ulong uVar17;
  uint uVar18;
  ulong uVar19;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 local_80;
  uint local_78;
  uint local_74;
  undefined4 local_70;
  undefined2 local_6c [2];
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  puVar16 = *(undefined8 **)(param_1 + 0x98);
  mutex_lock(&aw_sar_lock);
  if ((*(undefined8 **)(puVar16[0x50] + 0x88) != (undefined8 *)0x0) &&
     (pcVar15 = (code *)**(undefined8 **)(puVar16[0x50] + 0x88), pcVar15 != (code *)0x0)) {
    if (*(int *)(pcVar15 + -4) != -0x341d15a5) {
                    /* WARNING: Does not return */
      pcVar15 = (code *)SoftwareBreakpoint(0x8228,0x105e6c);
      (*pcVar15)();
    }
    (*pcVar15)(puVar16,param_3,param_4);
    goto LAB_00106380;
  }
  local_78 = 0;
  local_88 = 0;
  local_80 = 0;
  local_8c = 0;
  local_70 = 0;
  iVar4 = sscanf(param_3,"0x%02x 0x%02x 0x%02x ",&local_78,(long)&local_80 + 4,&local_80);
  if (iVar4 == 3) {
    *(char *)(puVar16 + 0x4d) = (char)local_78;
    *(char *)((long)puVar16 + 0x269) = (char)((ulong)local_80 >> 0x20);
    *(char *)((long)puVar16 + 0x26a) = (char)local_80;
    if (4 < local_80._4_4_) goto LAB_00106380;
    if (local_78 < 2) {
      iVar4 = sscanf(param_3 + 0xf,"0x%02x ",&local_88);
      if (iVar4 == 1) {
        *(char *)((long)puVar16 + 0x26b) = (char)local_88;
        iVar4 = (uint)*(byte *)((long)puVar16 + 0x269) +
                ((uint)local_88 & 0xff) * (uint)*(byte *)((long)puVar16 + 0x26a);
        *(int *)((long)puVar16 + 0x26c) = iVar4;
        if (puVar16[0x4e] != 0) {
          devm_kfree(puVar16[1]);
          iVar4 = *(int *)((long)puVar16 + 0x26c);
          puVar16[0x4e] = 0;
        }
        lVar6 = devm_kmalloc(puVar16[1],iVar4,0xdc0);
        puVar16[0x4e] = lVar6;
        if (lVar6 == 0) {
          uVar8 = puVar16[1];
          pcVar10 = " [%s:%s:%d] devm_kzalloc error\n";
          pcVar12 = "aw_sar_awrw_handle";
          uVar13 = 0x354;
        }
        else {
          if (*(char *)(puVar16 + 0x4d) != '\x01') {
            if (*(char *)(puVar16 + 0x4d) == '\0') {
              uVar18 = *(uint *)((long)puVar16 + 0x26c);
              local_74 = 0;
              uVar14 = (uVar18 & 0xff) + (uVar18 & 0xff) * 4;
              sVar7 = strlen(param_3);
              if (uVar14 + 0x14 == (int)sVar7) {
                if ((uVar18 & 0xff) != 0) {
                  if (uVar14 < 6) {
                    uVar14 = 5;
                  }
                  uVar17 = 0;
                  param_3 = param_3 + 0x17;
                  do {
                    local_6c[0] = *(undefined2 *)(param_3 + -1);
                    iVar4 = sscanf((char *)local_6c,"%02x",&local_74);
                    if (iVar4 == 1) {
                      *(char *)(puVar16[0x4e] + uVar17) = (char)local_74;
                    }
                    uVar17 = uVar17 + 1;
                    param_3 = param_3 + 5;
                  } while ((uVar14 - 1 & 0xffff) / 5 + 1 != uVar17);
                  uVar18 = *(uint *)((long)puVar16 + 0x26c);
                  lVar6 = puVar16[0x4e];
                }
                aw_sar_i2c_write_seq(*puVar16,lVar6,uVar18);
                lVar6 = puVar16[0x4e];
              }
              else {
                _dev_err(puVar16[1]," [%s:%s:%d] awrw_write error\n","aw_sar.c","aw_sar_awrw_handle"
                         ,0x35b);
                lVar6 = puVar16[0x4e];
              }
              if (lVar6 != 0) {
                devm_kfree(puVar16[1]);
                puVar16[0x4e] = 0;
              }
            }
            goto LAB_00106380;
          }
          bVar1 = *(byte *)((long)puVar16 + 0x269);
          bVar2 = *(byte *)((long)puVar16 + 0x26a);
          local_74 = 0;
          bVar3 = *(byte *)((long)puVar16 + 0x26b);
          uVar17 = (ulong)bVar3;
          uVar14 = (uint)bVar1 * 5;
          sVar7 = strlen(param_3);
          if (uVar14 + 0x14 == (int)sVar7) {
            if (bVar1 == 0) {
              uVar11 = 0;
              lVar9 = lVar6;
              uVar19 = (ulong)bVar2;
            }
            else {
              if (uVar14 < 6) {
                uVar14 = 5;
              }
              uVar19 = 0;
              param_3 = param_3 + 0x17;
              do {
                local_6c[0] = *(undefined2 *)(param_3 + -1);
                iVar4 = sscanf((char *)local_6c,"%02x",&local_74);
                if (iVar4 == 1) {
                  *(char *)(puVar16[0x4e] + uVar19) = (char)local_74;
                }
                uVar19 = uVar19 + 1;
                param_3 = param_3 + 5;
              } while ((uVar14 - 1 & 0xffff) / 5 + 1 != uVar19);
              uVar11 = (ulong)*(byte *)((long)puVar16 + 0x269);
              bVar3 = *(byte *)((long)puVar16 + 0x26b);
              lVar9 = puVar16[0x4e];
              uVar19 = (ulong)*(byte *)((long)puVar16 + 0x26a);
            }
            iVar4 = aw_sar_i2c_read_seq(*puVar16,lVar9,uVar11,lVar9 + uVar11,
                                        (int)uVar19 * (uint)bVar3);
            if (iVar4 == 0) goto LAB_00106380;
            memset((void *)(lVar6 + (ulong)bVar1),0xff,uVar17 * bVar2);
          }
          uVar8 = puVar16[1];
          pcVar10 = " [%s:%s:%d] awrw_read error\n";
          pcVar12 = "aw_sar_awrw_handle";
          uVar13 = 0x364;
        }
      }
      else {
        uVar8 = puVar16[1];
        pcVar10 = " [%s:%s:%d] sscanf1 parse error!\n";
        pcVar12 = "aw_sar_awrw_set_func";
        uVar13 = 0x38e;
      }
    }
    else {
      if (local_78 != 2) goto LAB_00106380;
      iVar4 = sscanf(param_3 + 0xf,"0x%02x ",(long)&local_88 + 4);
      if (iVar4 == 1) {
        iVar5 = local_88._4_4_;
        iVar4 = (local_80._4_4_ * 5 + 5) * local_88._4_4_ + 0x14;
        sVar7 = strlen(param_3);
        if (iVar4 != (int)sVar7) {
          _dev_err(puVar16[1]," [%s:%s:%d] theory_len:%d, actual_len:%d error!\n","aw_sar.c",
                   "aw_sar_awrw_set_func",0x39f,iVar4);
          goto LAB_00106380;
        }
        iVar4 = 0;
        if (iVar5 != 0) {
          iVar4 = 0;
          uVar14 = 0;
          do {
            iVar5 = sscanf(param_3 + ((local_80._4_4_ * 5 + 5) * uVar14 + 0x14),"0x%02x",&local_88);
            if (iVar5 != 1) {
              uVar8 = puVar16[1];
              pcVar10 = " [%s:%s:%d] sscanf3 parse error!\n";
              pcVar12 = "aw_sar_awrw_set_func";
              uVar13 = 0x3a9;
              goto LAB_00106310;
            }
            uVar14 = uVar14 + 1;
            iVar4 = iVar4 + (int)local_80 * (uint)local_88;
          } while (uVar14 < local_88._4_4_);
        }
        *(int *)((long)puVar16 + 0x26c) = iVar4;
        if (puVar16[0x4e] != 0) {
          devm_kfree(puVar16[1]);
          puVar16[0x4e] = 0;
        }
        lVar6 = devm_kmalloc(puVar16[1],iVar4,0xdc0);
        puVar16[0x4e] = lVar6;
        if (lVar6 != 0) {
          if (local_88._4_4_ != 0) {
            uVar17 = 0;
            uVar14 = 0;
            do {
              iVar4 = (local_80._4_4_ * 5 + 5) * uVar14;
              iVar5 = sscanf(param_3 + (iVar4 + 0x14),"0x%02x",&local_88);
              if (iVar5 != 1) {
                uVar8 = puVar16[1];
                pcVar10 = " [%s:%s:%d] sscanf4 parse error!\n";
                pcVar12 = "aw_sar_awrw_set_func";
                uVar13 = 0x3c3;
                goto LAB_00106310;
              }
              if (local_80._4_4_ != 0) {
                iVar5 = sscanf(param_3 + (iVar4 + 0x19),"0x%02x",&local_8c);
                if (iVar5 == 1) {
                  local_70 = CONCAT31(local_70._1_3_,(char)local_8c);
                  uVar18 = local_80._4_4_;
                  if (local_80._4_4_ < 2) goto LAB_001060dc;
                  iVar5 = sscanf(param_3 + (iVar4 + 0x1e),"0x%02x",&local_8c);
                  if (iVar5 == 1) {
                    local_70._0_2_ = CONCAT11((char)local_8c,(undefined1)local_70);
                    uVar18 = local_80._4_4_;
                    if (local_80._4_4_ < 3) goto LAB_001060dc;
                    iVar5 = sscanf(param_3 + (iVar4 + 0x23),"0x%02x",&local_8c);
                    if (iVar5 == 1) {
                      local_70._0_3_ = CONCAT12((char)local_8c,(undefined2)local_70);
                      uVar18 = local_80._4_4_;
                      if (local_80._4_4_ < 4) goto LAB_001060dc;
                      iVar5 = sscanf(param_3 + (iVar4 + 0x28),"0x%02x",&local_8c);
                      if (iVar5 == 1) {
                        local_70 = CONCAT13((char)local_8c,(undefined3)local_70);
                        uVar18 = local_80._4_4_;
                        if (local_80._4_4_ < 5) goto LAB_001060dc;
                        iVar4 = sscanf(param_3 + (iVar4 + 0x2d),"0x%02x",&local_8c);
                        if (iVar4 == 1) {
                    /* WARNING: Does not return */
                          pcVar15 = (code *)SoftwareBreakpoint(0x5512,0x106538);
                          (*pcVar15)();
                        }
                      }
                    }
                  }
                }
                uVar8 = puVar16[1];
                pcVar10 = " [%s:%s:%d] sscanf5 parse error!\n";
                pcVar12 = "aw_sar_awrw_set_func";
                uVar13 = 0x3ce;
                goto LAB_00106310;
              }
              uVar18 = 0;
LAB_001060dc:
              aw_sar_i2c_read_seq(*puVar16,&local_70,uVar18,puVar16[0x4e] + uVar17,
                                  (uint)local_88 * (int)local_80);
              uVar14 = uVar14 + 1;
              uVar17 = (ulong)((int)uVar17 + (uint)local_88 * (int)local_80);
            } while (uVar14 < local_88._4_4_);
          }
          goto LAB_00106380;
        }
        uVar8 = puVar16[1];
        pcVar10 = " [%s:%s:%d] devm_kzalloc error\n";
        pcVar12 = "aw_sar_awrw_set_func";
        uVar13 = 0x3ba;
      }
      else {
        uVar8 = puVar16[1];
        pcVar10 = " [%s:%s:%d] sscanf2 parse error!\n";
        pcVar12 = "aw_sar_awrw_set_func";
        uVar13 = 0x396;
      }
    }
  }
  else {
    uVar8 = puVar16[1];
    pcVar10 = " [%s:%s:%d] sscanf0 parse error!\n";
    pcVar12 = "aw_sar_awrw_set_func";
    uVar13 = 0x380;
  }
LAB_00106310:
  _dev_err(uVar8,pcVar10,"aw_sar.c",pcVar12,uVar13);
LAB_00106380:
  mutex_unlock(&aw_sar_lock);
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aw_sar_reg_get @ 0010653c size=320
// signature: undefined aw_sar_reg_get(void)
// callers: []
//------------------------------------------------------------

long aw_sar_reg_get(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  undefined8 *puVar8;
  uint local_5c;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  puVar8 = *(undefined8 **)(param_1 + 0x98);
  local_5c = 0;
  lVar4 = puVar8[0x50];
  lVar5 = *(long *)(lVar4 + 0x40);
  if ((lVar5 == 0) || (*(int *)(lVar5 + 0x10) == 0)) {
    lVar7 = 0;
  }
  else {
    uVar6 = 0;
    lVar7 = 0;
    bVar2 = *(byte *)(lVar5 + 1);
    do {
      uVar6 = uVar6 & 0xffff;
      if ((*(byte *)(*(long *)(lVar5 + 8) + uVar6 * 4) & bVar2) != 0) {
        iVar3 = aw_sar_i2c_read(*puVar8,*(undefined2 *)(*(long *)(lVar5 + 8) + uVar6 * 4 + 2),
                                &local_5c);
        if (iVar3 < 0) {
          iVar3 = snprintf((char *)(param_3 + lVar7),0x1000 - lVar7,"i2c read error ret = %d\n",
                           iVar3);
          lVar7 = lVar7 + iVar3;
        }
        iVar3 = snprintf((char *)(param_3 + lVar7),0x1000 - lVar7,"%x,%x\n",
                         (uint)*(ushort *)
                                (*(long *)(*(long *)(puVar8[0x50] + 0x40) + 8) + uVar6 * 4 + 2),
                         local_5c);
        lVar4 = puVar8[0x50];
        lVar7 = lVar7 + iVar3;
      }
      lVar5 = *(long *)(lVar4 + 0x40);
      uVar1 = (int)uVar6 + 1;
      uVar6 = (ulong)uVar1;
    } while ((uVar1 & 0xffff) < *(uint *)(lVar5 + 0x10));
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar7;
}



//------------------------------------------------------------
// aw_sar_reg_set @ 00106680 size=284
// signature: undefined aw_sar_reg_set(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_sar_reg_set(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  ushort uVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 local_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  puVar6 = *(undefined8 **)(param_1 + 0x98);
  local_40 = 0;
  if (*(long *)(puVar6[0x50] + 0x40) == 0) {
    _dev_err(puVar6[1]," [%s:%s:%d] AW_INVALID_PARA\n","aw_sar.c","aw_sar_reg_set",0x423);
  }
  else {
    bVar2 = *(byte *)(*(long *)(puVar6[0x50] + 0x40) + 2);
    iVar3 = sscanf(param_3,"%x %x",(uint *)&local_40,(uint *)((ulong)&local_40 | 4));
    if (iVar3 == 2) {
      uVar1 = *(uint *)(*(long *)(puVar6[0x50] + 0x40) + 0x10);
      if (uVar1 != 0) {
        uVar4 = 0;
        lVar5 = *(long *)(*(long *)(puVar6[0x50] + 0x40) + 8);
        do {
          if ((uint)*(ushort *)(lVar5 + (ulong)uVar4 * 4 + 2) == ((uint)local_40 & 0xffff)) {
            if ((*(byte *)(lVar5 + (ulong)uVar4 * 4) & bVar2) != 0) {
              aw_sar_i2c_write(*puVar6,local_40 & 0xffffffff,local_40._4_4_);
            }
            break;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar1);
      }
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aw_sar_soft_rst_set @ 001067a0 size=316
// signature: undefined aw_sar_soft_rst_set(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_sar_soft_rst_set(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  code *pcVar2;
  long *plVar3;
  long lVar4;
  undefined2 *puVar5;
  int local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  plVar3 = *(long **)(param_1 + 0x98);
  local_3c = 0;
  iVar1 = sscanf(param_3,"%d",&local_3c);
  if (iVar1 == 1) {
    if ((local_3c == 1) &&
       (puVar5 = *(undefined2 **)(plVar3[0x50] + 0x18), puVar5 != (undefined2 *)0x0)) {
      pcVar2 = *(code **)(puVar5 + 8);
      if (pcVar2 == (code *)0x0) {
        lVar4 = *plVar3;
        iVar1 = aw_sar_i2c_write(lVar4,*puVar5,*(undefined4 *)(puVar5 + 2));
        if (iVar1 < 0) {
          _dev_err(lVar4 + 0x20," [%s:%s:%d] soft_reset error: %d\n","aw_sar.c",
                   "aw_sar_soft_reset_func",0x89,iVar1);
        }
        else {
          msleep(*(undefined4 *)(puVar5 + 4));
        }
      }
      else {
        if (*(int *)(pcVar2 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10682c);
          (*pcVar2)();
        }
        (*pcVar2)(plVar3);
      }
    }
  }
  else {
    _dev_err(plVar3[1]," [%s:%s:%d] sscanf parse err\n","aw_sar.c","aw_sar_soft_rst_set",0x442);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aw_sar_aot_set @ 001068e0 size=248
// signature: undefined aw_sar_aot_set(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_sar_aot_set(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined4 *puVar3;
  code *pcVar4;
  undefined8 *puVar5;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  puVar5 = *(undefined8 **)(param_1 + 0x98);
  local_2c = 0;
  iVar2 = sscanf(param_3,"%d",&local_2c);
  if (iVar2 == 1) {
    if (local_2c == 1) {
      puVar3 = *(undefined4 **)(puVar5[0x50] + 0x50);
      if (puVar3 != (undefined4 *)0x0) {
        pcVar4 = *(code **)(puVar3 + 4);
        if (pcVar4 == (code *)0x0) {
          aw_sar_i2c_write_bits(*puVar5,*puVar3,puVar3[1],puVar3[2]);
        }
        else {
          if (*(int *)(pcVar4 + -4) != -0x272b8e18) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x106968);
            (*pcVar4)();
          }
          (*pcVar4)(puVar5);
        }
      }
    }
    else {
      _dev_err(puVar5[1]," [%s:%s:%d] fail to set aot cali\n","aw_sar.c","aw_sar_aot_set",0x469);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aw_sar_update_reg_set @ 001069dc size=368
// signature: undefined aw_sar_update_reg_set(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_sar_update_reg_set(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  code *pcVar2;
  long *plVar3;
  long lVar4;
  undefined2 *puVar5;
  int local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  plVar3 = *(long **)(param_1 + 0x98);
  local_3c = 0;
  iVar1 = sscanf(param_3,"%d",&local_3c);
  if (iVar1 == 1) {
    if (local_3c == 1) {
      mutex_lock(&aw_sar_lock);
      puVar5 = *(undefined2 **)(plVar3[0x50] + 0x18);
      if (puVar5 != (undefined2 *)0x0) {
        pcVar2 = *(code **)(puVar5 + 8);
        if (pcVar2 == (code *)0x0) {
          lVar4 = *plVar3;
          iVar1 = aw_sar_i2c_write(lVar4,*puVar5,*(undefined4 *)(puVar5 + 2));
          if (iVar1 < 0) {
            _dev_err(lVar4 + 0x20," [%s:%s:%d] soft_reset error: %d\n","aw_sar.c",
                     "aw_sar_soft_reset_func",0x89,iVar1);
          }
          else {
            msleep(*(undefined4 *)(puVar5 + 4));
          }
        }
        else {
          if (*(int *)(pcVar2 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x106a74);
            (*pcVar2)();
          }
          (*pcVar2)(plVar3);
        }
      }
      aw_sar_load_def_reg_bin(plVar3);
      aw_sar_mode_set(plVar3,*(undefined4 *)(*(long *)(plVar3[0x50] + 0x38) + 4));
      mutex_unlock(&aw_sar_lock);
    }
  }
  else {
    _dev_err(plVar3[1]," [%s:%s:%d] sscanf parse error\n","aw_sar.c","aw_sar_update_reg_set",0x483);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aw_sar_diff_get @ 00106b50 size=356
// signature: undefined aw_sar_diff_get(void)
// callers: []
//------------------------------------------------------------

long aw_sar_diff_get(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  code *pcVar4;
  undefined8 *puVar5;
  uint param3;
  ushort *puVar6;
  int local_5c;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  puVar5 = *(undefined8 **)(param_1 + 0x98);
  local_5c = 0;
  puVar6 = *(ushort **)((char *)puVar5[0x50] + 0x58);
  if (puVar6 == (ushort *)0x0) {
    lVar3 = 8;
  }
  else {
    pcVar4 = *(code **)(puVar6 + 4);
    if (pcVar4 == (code *)0x0) {
      if (*(char *)puVar5[0x50] == '\0') {
        lVar3 = 0;
      }
      else {
        lVar3 = 0;
        param3 = 0;
        do {
          iVar2 = aw_sar_i2c_read(*puVar5,(uint)*puVar6 + puVar6[1] * param3,&local_5c);
          if (iVar2 != 0) {
            _dev_err(puVar5[1]," [%s:%s:%d] read diff err: %d\n","aw_sar.c","aw_sar_get_diff",0x4a7,
                     iVar2);
            lVar3 = -1;
            break;
          }
          iVar2 = 0;
          if (*(int *)(puVar6 + 2) != 0) {
            iVar2 = local_5c / *(int *)(puVar6 + 2);
          }
          iVar2 = snprintf((char *)(param_3 + lVar3),0x1000 - lVar3,"DIFF_CH%d = %d\n",param3,iVar2)
          ;
          lVar3 = lVar3 + iVar2;
          param3 = param3 + 1;
        } while (param3 < *(byte *)puVar5[0x50]);
      }
    }
    else {
      if (*(int *)(pcVar4 + -4) != 0x3194cf9a) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x106bbc);
        (*pcVar4)();
      }
      lVar3 = (*pcVar4)(puVar5,param_3);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3;
}



//------------------------------------------------------------
// aw_sar_mode_operation_get @ 00106cb8 size=88
// signature: undefined aw_sar_mode_operation_get(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_sar_mode_operation_get(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0x98) + 0x280) + 0x68);
  if ((lVar2 == 0) || (pcVar3 = *(code **)(lVar2 + 0x18), pcVar3 == (code *)0x0)) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(pcVar3 + -4) != 0x3194cf9a) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x106cf8);
      (*pcVar3)();
    }
    uVar1 = (*pcVar3)(*(long *)(param_1 + 0x98),param_3);
  }
  return uVar1;
}



//------------------------------------------------------------
// aw_sar_mode_operation_set @ 00106d14 size=176
// signature: undefined aw_sar_mode_operation_set(void)
// callers: []
//------------------------------------------------------------

undefined8
aw_sar_mode_operation_set(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_2c = 0;
  iVar1 = sscanf(param_3,"%d",&local_2c);
  if (iVar1 == 1) {
    aw_sar_mode_set(lVar2,local_2c);
  }
  else {
    _dev_err(*(undefined8 *)(lVar2 + 8)," [%s:%s:%d] sscanf parse err\n","aw_sar.c",
             "aw_sar_mode_operation_set",0x4db);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aw_sar_chip_info_get @ 00106dc8 size=224
// signature: undefined aw_sar_chip_info_get(void)
// callers: []
//------------------------------------------------------------

void aw_sar_chip_info_get(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  undefined8 *puVar2;
  code *pcVar3;
  long lVar4;
  long lVar5;
  long local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  iVar1 = snprintf(param_3,0x1000,"driver version: %s\n","v0.1.5.14");
  lVar5 = (long)iVar1;
  iVar1 = snprintf(param_3 + lVar5,0x1000 - lVar5,"reg_load_state: %d\n",
                   (uint)*(byte *)(lVar4 + 0x1b2));
  local_40 = lVar5 + iVar1;
  puVar2 = *(undefined8 **)(*(long *)(lVar4 + 0x280) + 0x80);
  if ((puVar2 != (undefined8 *)0x0) && (pcVar3 = (code *)*puVar2, pcVar3 != (code *)0x0)) {
    if (*(int *)(pcVar3 + -4) != -0x31604764) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x106e70);
      (*pcVar3)();
    }
    (*pcVar3)(lVar4,param_3,&local_40);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_40);
  }
  return;
}



//------------------------------------------------------------
// aw_sar_offset_get @ 00106eac size=88
// signature: undefined aw_sar_offset_get(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_sar_offset_get(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  code *pcVar3;
  
  puVar2 = *(undefined8 **)(*(long *)(*(long *)(param_1 + 0x98) + 0x280) + 0x60);
  if ((puVar2 == (undefined8 *)0x0) || (pcVar3 = (code *)*puVar2, pcVar3 == (code *)0x0)) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(pcVar3 + -4) != 0x3194cf9a) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x106eec);
      (*pcVar3)();
    }
    uVar1 = (*pcVar3)(*(long *)(param_1 + 0x98),param_3);
  }
  return uVar1;
}



//------------------------------------------------------------
// aw_sar_prot_update_fw_get @ 00106f08 size=204
// signature: undefined aw_sar_prot_update_fw_get(void)
// callers: []
//------------------------------------------------------------

void aw_sar_prot_update_fw_get(long param_1,undefined8 param_2,char *param_3)

{
  char *param3;
  int iVar1;
  long lVar2;
  code *pcVar3;
  long lVar4;
  long local_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  param3 = "ok";
  if (*(int *)(lVar4 + 0x1b4) != 0) {
    param3 = "error";
  }
  iVar1 = snprintf(param_3,0x1000,"protocol update state:%s!\n",param3);
  local_30 = (long)iVar1;
  lVar2 = *(long *)(*(long *)(lVar4 + 0x280) + 0x70);
  if ((lVar2 != 0) && (pcVar3 = *(code **)(lVar2 + 0x18), pcVar3 != (code *)0x0)) {
    if (*(int *)(pcVar3 + -4) != -0x31604764) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x106fa0);
      (*pcVar3)();
    }
    (*pcVar3)(lVar4,param_3,&local_30);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_30);
  }
  return;
}



//------------------------------------------------------------
// aw_sar_prot_update_fw_set @ 00106fd8 size=200
// signature: undefined aw_sar_prot_update_fw_set(void)
// callers: []
//------------------------------------------------------------

undefined8
aw_sar_prot_update_fw_set(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  char cVar2;
  long *plVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x98);
  mutex_lock(&aw_sar_lock);
  cVar2 = *(char *)(lVar4 + 0x21c);
  if (cVar2 == '\0') {
    disable_irq(*(undefined4 *)(lVar4 + 0x218));
    cVar2 = '\x01';
    *(undefined1 *)(lVar4 + 0x21c) = 1;
  }
  plVar3 = *(long **)(*(long *)(lVar4 + 0x280) + 0x70);
  if ((plVar3 == (long *)0x0) || (*plVar3 == 0)) {
    uVar1 = 0xffffffff;
  }
  else {
    *(long *)(lVar4 + 0x208) = plVar3[1];
    *(long *)(lVar4 + 0x210) = plVar3[2];
    snprintf((char *)(lVar4 + 0x1e8),0x1e,"%s_%d.bin",(char *)*plVar3,*(int *)(lVar4 + 0x1c0));
    uVar1 = aw_sar_load_bin_comm(lVar4);
    cVar2 = *(char *)(lVar4 + 0x21c);
  }
  *(undefined4 *)(lVar4 + 0x1b4) = uVar1;
  if (cVar2 == '\x01') {
    enable_irq(*(undefined4 *)(lVar4 + 0x218));
    *(undefined1 *)(lVar4 + 0x21c) = 0;
  }
  mutex_unlock(&aw_sar_lock);
  return param_4;
}



//------------------------------------------------------------
// aw_sar_reg_update_fw_set @ 001070a4 size=188
// signature: undefined aw_sar_reg_update_fw_set(void)
// callers: []
//------------------------------------------------------------

undefined8
aw_sar_reg_update_fw_set(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  long *plVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  mutex_lock(&aw_sar_lock);
  cVar1 = *(char *)(lVar3 + 0x21c);
  if (cVar1 == '\0') {
    disable_irq(*(undefined4 *)(lVar3 + 0x218));
    cVar1 = '\x01';
    *(undefined1 *)(lVar3 + 0x21c) = 1;
  }
  plVar2 = *(long **)(*(long *)(lVar3 + 0x280) + 0x78);
  if ((plVar2 != (long *)0x0) && (*plVar2 != 0)) {
    *(long *)(lVar3 + 0x208) = plVar2[1];
    *(long *)(lVar3 + 0x210) = plVar2[2];
    snprintf((char *)(lVar3 + 0x1e8),0x1e,"%s_%d.bin",(char *)*plVar2,*(int *)(lVar3 + 0x1c0));
    aw_sar_load_bin_comm(lVar3);
    cVar1 = *(char *)(lVar3 + 0x21c);
  }
  if (cVar1 == '\x01') {
    enable_irq(*(undefined4 *)(lVar3 + 0x218));
    *(undefined1 *)(lVar3 + 0x21c) = 0;
  }
  mutex_unlock(&aw_sar_lock);
  return param_4;
}



//------------------------------------------------------------
// aw_sar_reg_update_boot_set @ 00107164 size=196
// signature: undefined aw_sar_reg_update_boot_set(void)
// callers: []
//------------------------------------------------------------

undefined8
aw_sar_reg_update_boot_set(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char *param3;
  char cVar1;
  undefined8 *puVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  if (*(long *)(*(long *)(lVar3 + 0x280) + 0x90) != 0) {
    mutex_lock(&aw_sar_lock);
    cVar1 = *(char *)(lVar3 + 0x21c);
    if (cVar1 == '\0') {
      disable_irq(*(undefined4 *)(lVar3 + 0x218));
      cVar1 = '\x01';
      *(undefined1 *)(lVar3 + 0x21c) = 1;
    }
    puVar2 = *(undefined8 **)(*(long *)(lVar3 + 0x280) + 0x90);
    if ((puVar2 != (undefined8 *)0x0) && (param3 = (char *)*puVar2, param3 != (char *)0x0)) {
      snprintf((char *)(lVar3 + 0x1e8),0x1e,"%s_%d.bin",param3,*(int *)(lVar3 + 0x1c0));
      *(undefined8 *)(lVar3 + 0x208) =
           *(undefined8 *)(*(long *)(*(long *)(lVar3 + 0x280) + 0x90) + 8);
      aw_sar_load_bin_comm(lVar3);
      cVar1 = *(char *)(lVar3 + 0x21c);
    }
    if (cVar1 == '\x01') {
      enable_irq(*(undefined4 *)(lVar3 + 0x218));
      *(undefined1 *)(lVar3 + 0x21c) = 0;
    }
    mutex_unlock(&aw_sar_lock);
  }
  return param_4;
}



//------------------------------------------------------------
// aw_sar_irq @ 0010722c size=160
// signature: undefined aw_sar_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_sar_irq(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  
  lVar2 = *(long *)(*(long *)(param_2[0x50] + 8) + 0x30);
  pcVar3 = *(code **)(lVar2 + 0x20);
  if (pcVar3 == (code *)0x0) {
    uVar1 = 0;
    pcVar3 = *(code **)(lVar2 + 0x28);
  }
  else {
    if (*(int *)(pcVar3 + -4) != 0x1a23ed84) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x107270);
      (*pcVar3)();
    }
    uVar1 = (*pcVar3)(*param_2);
    pcVar3 = *(code **)(*(long *)(*(long *)(param_2[0x50] + 8) + 0x30) + 0x28);
  }
  if (pcVar3 != (code *)0x0) {
    if (*(int *)(pcVar3 + -4) != -0x59df4355) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1072a4);
      (*pcVar3)();
    }
    (*pcVar3)(uVar1,param_2);
  }
  return 1;
}



//------------------------------------------------------------
// aw_sar_suspend @ 001072d0 size=200
// signature: undefined aw_sar_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_sar_suspend(long param_1)

{
  long lVar1;
  undefined4 *puVar2;
  code *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x98);
  _dev_info(*(undefined8 *)(lVar4 + 8)," [%s:%s:%d] enter\n","aw_sar.c","aw_sar_suspend",0x8a1);
  if (*(char *)(lVar4 + 0x1ce) != '\0') {
    lVar1 = *(long *)(*(long *)(lVar4 + 0x280) + 8);
    if (lVar1 == 0) {
      return 0;
    }
    puVar2 = *(undefined4 **)(lVar1 + 0x38);
    if (puVar2 == (undefined4 *)0x0) {
      return 0;
    }
    pcVar3 = *(code **)(puVar2 + 4);
    if (pcVar3 != (code *)0x0) {
      if (*(int *)(pcVar3 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x107348);
        (*pcVar3)();
      }
      (*pcVar3)(lVar4);
      return 0;
    }
    aw_sar_mode_set(lVar4,*puVar2);
    if (*(char *)(lVar4 + 0x21c) == '\0') {
      disable_irq(*(undefined4 *)(lVar4 + 0x218));
      *(undefined1 *)(lVar4 + 0x21c) = 1;
    }
  }
  if (*(int *)(lVar4 + 0x1e0) != 0) {
    cancel_delayed_work_sync(lVar4 + 0x108);
  }
  return 0;
}



//------------------------------------------------------------
// aw_sar_resume @ 0010739c size=224
// signature: undefined aw_sar_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_sar_resume(long param_1)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  _dev_info(*(undefined8 *)(lVar3 + 8)," [%s:%s:%d] enter\n","aw_sar.c","aw_sar_resume",0x8bc);
  if (*(char *)(lVar3 + 0x1ce) != '\0') {
    lVar1 = *(long *)(*(long *)(lVar3 + 0x280) + 8);
    if (lVar1 == 0) {
      return 0;
    }
    lVar1 = *(long *)(lVar1 + 0x38);
    if (lVar1 == 0) {
      return 0;
    }
    pcVar2 = *(code **)(lVar1 + 0x18);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x107414);
        (*pcVar2)();
      }
      (*pcVar2)(lVar3);
      return 0;
    }
    if (*(char *)(lVar3 + 0x21c) == '\x01') {
      enable_irq(*(undefined4 *)(lVar3 + 0x218));
      *(undefined1 *)(lVar3 + 0x21c) = 0;
      lVar1 = *(long *)(*(long *)(*(long *)(lVar3 + 0x280) + 8) + 0x38);
    }
    aw_sar_mode_set(lVar3,*(undefined4 *)(lVar1 + 4));
  }
  if (*(int *)(lVar3 + 0x1e0) != 0) {
    queue_delayed_work_on(0x20,*(undefined8 *)(lVar3 + 400),lVar3 + 0x108,0x4e2);
  }
  return 0;
}



//------------------------------------------------------------
// aw963xx_check_chipid @ 00107480 size=584
// signature: undefined aw963xx_check_chipid(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

int aw963xx_check_chipid(undefined8 *param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  if (param_1 == (undefined8 *)0x0) {
    iVar2 = -9;
    goto LAB_001074ac;
  }
  iVar2 = aw_sar_i2c_read(*param_1,0xff10,&local_2c);
  if (iVar2 < 0) {
    _dev_err(param_1[1]," [%s:%s:%d] read CHIP ID failed: %d\n","aw963xx.c","aw963xx_check_chipid",
             0x29d,iVar2);
    goto LAB_001074ac;
  }
  if (local_2c < -0x569cf7f0) {
    if (local_2c == -0x569cfcc0) {
      _dev_info(param_1[1]," [%s:%s:%d] aw96303 detected, 0x%04x\n","aw963xx.c",
                "aw963xx_check_chipid",0x2a3,0xa9630340);
      uVar3 = 0x33303336397761;
    }
    else {
      if (local_2c != -0x569cfae0) {
LAB_00107698:
        _dev_info(param_1[1]," [%s:%s:%d] chip id error, 0x%04x\n","aw963xx.c",
                  "aw963xx_check_chipid",0x2b7);
        iVar2 = -1;
        goto LAB_001074ac;
      }
      _dev_info(param_1[1]," [%s:%s:%d] aw96305 detected, 0x%04x\n","aw963xx.c",
                "aw963xx_check_chipid",0x2a8,0xa9630520);
      uVar3 = 0x35303336397761;
    }
  }
  else if (local_2c == -0x569cf7f0) {
    _dev_info(param_1[1]," [%s:%s:%d] aw96308 detected, 0x%04x\n","aw963xx.c","aw963xx_check_chipid"
              ,0x2ad,0xa9630810);
    uVar3 = 0x38303336397761;
  }
  else {
    if (local_2c != -0x569ceff0) goto LAB_00107698;
    _dev_info(param_1[1]," [%s:%s:%d] aw96310 detected, 0x%04x\n","aw963xx.c","aw963xx_check_chipid"
              ,0x2b2,0xa9631010);
    uVar3 = 0x30313336397761;
  }
  iVar2 = 0;
  *(undefined8 *)((long)param_1 + 0x19b) = uVar3;
LAB_001074ac:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// aw963xx_init @ 001076cc size=180
// signature: undefined aw963xx_init(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

undefined8 aw963xx_init(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  _printk(&DAT_0010c2b1,"aw963xx_init");
  if (param_1 == 0) {
    _printk(&DAT_00109b5c);
    uVar2 = 0xffffffff;
  }
  else {
    lVar1 = devm_kmalloc(*(undefined8 *)(param_1 + 8),0xbc8,0xdc0);
    *(long *)(param_1 + 0x288) = lVar1;
    if (lVar1 == 0) {
      _dev_err(*(undefined8 *)(param_1 + 8)," [%s:%s:%d] priv_data failed to malloc memory!\n",
               "aw963xx.c","aw963xx_init",0x5c7);
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0;
      *(long *)(lVar1 + 0x38) = param_1;
      g_aw963xx = lVar1;
      *(undefined1 **)(param_1 + 0x280) = &g_aw963xx_chip_config;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// aw963xx_deinit @ 00107784 size=132
// signature: undefined aw963xx_deinit(void)
// callers: [aw_sar_i2c_probe, aw_sar_i2c_remove]
//------------------------------------------------------------

void aw963xx_deinit(long param_1)

{
  _printk(&DAT_0010c2b1,"aw963xx_deinit");
  if ((param_1 != 0) && (*(long *)(param_1 + 0x288) != 0)) {
    del_timer_sync(*(long *)(param_1 + 0x288) + 0x70);
    if (*(long *)(param_1 + 0x288) != 0) {
      devm_kfree(*(undefined8 *)(param_1 + 8));
    }
    _dev_info(*(undefined8 *)(param_1 + 8)," [%s:%s:%d] aw963xx_deinit ok!\n","aw963xx.c",
              "aw963xx_deinit",0x5e6);
  }
  return;
}



//------------------------------------------------------------
// aw_sar_custom_flie_node_create @ 0010780c size=844
// signature: undefined aw_sar_custom_flie_node_create(void)
// callers: []
//------------------------------------------------------------

int aw_sar_custom_flie_node_create(long param_1)

{
  long lVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined *puVar9;
  uint uVar10;
  undefined8 *puVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  
  if (param_1 == 0) {
    iVar4 = -1;
  }
  else {
    lVar12 = *(long *)(param_1 + 0x288);
    *(undefined1 **)(lVar12 + 0xb0) = &__this_module;
    puVar11 = (undefined8 *)(lVar12 + 0xa8);
    *puVar11 = "capsense";
    iVar4 = __class_register(puVar11,&aw_sar_custom_flie_node_create___key);
    if (iVar4 < 0) {
      uVar5 = *(undefined8 *)(param_1 + 8);
      pcVar6 = " [%s:%s:%d] Create fsys class failed (%d)\n\n";
      uVar7 = 0x51f;
    }
    else {
      iVar4 = class_create_file_ns(puVar11,&class_attr_cali,0);
      if (iVar4 < 0) {
        uVar5 = *(undefined8 *)(param_1 + 8);
        pcVar6 = " [%s:%s:%d] Create cali file failed (%d)\n\n";
        uVar7 = 0x525;
      }
      else {
        iVar4 = class_create_file_ns(puVar11,&class_attr_reset,0);
        if (iVar4 < 0) {
          uVar5 = *(undefined8 *)(param_1 + 8);
          pcVar6 = " [%s:%s:%d] Create cali file failed (%d)\n\n";
          uVar7 = 0x52b;
        }
        else {
          iVar4 = class_create_file_ns(puVar11,&class_attr_int_state,0);
          if (iVar4 < 0) {
            uVar5 = *(undefined8 *)(param_1 + 8);
            pcVar6 = " [%s:%s:%d] Create int_state file failed (%d)\n\n";
            uVar7 = 0x531;
          }
          else {
            iVar4 = class_create_file_ns(puVar11,&class_attr_mode,0);
            if (iVar4 < 0) {
              uVar5 = *(undefined8 *)(param_1 + 8);
              pcVar6 = " [%s:%s:%d] Create mode file failed (%d)\n\n";
              uVar7 = 0x537;
            }
            else {
              iVar4 = class_create_file_ns(puVar11,&class_attr_reg,0);
              if (iVar4 < 0) {
                uVar5 = *(undefined8 *)(param_1 + 8);
                pcVar6 = " [%s:%s:%d] Create reg file failed (%d)\n\n";
                uVar7 = 0x53d;
              }
              else {
                iVar4 = class_create_file_ns(puVar11,&class_attr_offset,0);
                if (-1 < iVar4) {
                  lVar13 = 0;
                  lVar14 = 0;
                  do {
                    if ((*(short *)(*(long *)(param_1 + 0x278) + lVar14) != 0) &&
                       (*(long *)(*(long *)(param_1 + 0x278) + lVar14 + 8) != 0)) {
                      uVar8 = (ulong)g_aw963xx_counter;
                      lVar1 = lVar12 + lVar13;
                      bVar3 = 0xd < g_aw963xx_counter;
                      *(code **)(lVar1 + 0x1e8) = capsensor_set_enable;
                      *(undefined8 *)(lVar1 + 0x1f0) = 0;
                      if (bVar3) {
                    /* WARNING: Does not return */
                        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x107b58);
                        (*pcVar2)();
                      }
                      puVar9 = (&g_aw963xx_ch_name)[uVar8];
                      *(undefined **)(lVar1 + 400) = &DAT_0010b675;
                      *(undefined8 *)(lVar1 + 0x198) = 0;
                      *(undefined4 *)(lVar1 + 0x1a0) = 0;
                      *(undefined **)(lVar1 + 0x160) = puVar9;
                      *(char **)(lVar1 + 0x168) = "awinic";
                      *(undefined4 *)(lVar1 + 0x170) = 1;
                      *(undefined **)(lVar1 + 0x180) = &DAT_00109ba6;
                      *(undefined **)(lVar1 + 0x188) = &DAT_00109ca6;
                      *(undefined4 *)(lVar1 + 0x178) = 0x10010;
                      *(undefined8 *)(lVar1 + 0x1ac) = 0x6400000000;
                      iVar4 = sensors_classdev_register
                                        (*(long *)(*(long *)(param_1 + 0x278) + lVar14 + 8) + 0x240,
                                         lVar1 + 0x148);
                      if (iVar4 < 0) {
                        _dev_err(*(undefined8 *)(param_1 + 8),
                                 " [%s:%s:%d] create ch0 cap sensor_class  file failed (%d)\n\n",
                                 "aw963xx.c","aw_sar_custom_flie_node_create",0x561,iVar4);
                      }
                      uVar10 = 0xe;
                      if (g_aw963xx_counter + 1 < 0xe) {
                        uVar10 = g_aw963xx_counter + 1;
                      }
                      g_aw963xx_counter = uVar10;
                    }
                    lVar14 = lVar14 + 0x28;
                    lVar13 = lVar13 + 0xe0;
                  } while (lVar13 != 0xa80);
                  return iVar4;
                }
                uVar5 = *(undefined8 *)(param_1 + 8);
                pcVar6 = " [%s:%s:%d] Create offset file failed (%d)\n\n";
                uVar7 = 0x543;
              }
            }
          }
        }
      }
    }
    _dev_err(uVar5,pcVar6,"aw963xx.c","aw_sar_custom_flie_node_create",uVar7,iVar4);
  }
  return iVar4;
}



//------------------------------------------------------------
// aw_sar_custom_flie_node_free @ 00107b5c size=300
// signature: undefined aw_sar_custom_flie_node_free(void)
// callers: []
//------------------------------------------------------------

void aw_sar_custom_flie_node_free(long param_1)

{
  long lVar1;
  long lVar2;
  
  _printk(&DAT_0010c2b1,"aw_sar_custom_flie_node_free");
  if (param_1 != 0) {
    lVar2 = 0;
    lVar1 = *(long *)(param_1 + 0x288);
    do {
      if ((*(short *)(*(long *)(param_1 + 0x278) + lVar2) != 0) &&
         (*(long *)(*(long *)(param_1 + 0x278) + lVar2 + 8) != 0)) {
        g_aw963xx_counter = g_aw963xx_counter - 1;
        if ((int)g_aw963xx_counter < 1) {
          g_aw963xx_counter = 0;
        }
        sensors_classdev_unregister(lVar1 + (ulong)g_aw963xx_counter * 0xe0 + 0x148);
      }
      lVar2 = lVar2 + 0x28;
    } while (lVar2 != 0x1e0);
    lVar1 = lVar1 + 0xa8;
    class_remove_file_ns(lVar1,&class_attr_offset,0);
    class_remove_file_ns(lVar1,&class_attr_reg,0);
    class_remove_file_ns(lVar1,&class_attr_mode,0);
    class_remove_file_ns(lVar1,&class_attr_int_state,0);
    class_remove_file_ns(lVar1,&class_attr_cali,0);
    class_remove_file_ns(lVar1,&class_attr_reset,0);
    class_unregister(lVar1);
  }
  return;
}



//------------------------------------------------------------
// aw963xx_parse_dts @ 00107c8c size=288
// signature: undefined aw963xx_parse_dts(void)
// callers: []
//------------------------------------------------------------

undefined8 aw963xx_parse_dts(long *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)param_1[0x51];
  uVar2 = *(undefined8 *)(*param_1 + 0x308);
  iVar1 = of_property_read_variable_u32_array(uVar2,"irq-mux",puVar3,1,0);
  if (iVar1 < 0) {
    _dev_err(param_1[1]," [%s:%s:%d] irq-mux not detected\n","aw963xx.c","aw963xx_parse_dts",0x344);
  }
  else {
    _dev_info(param_1[1]," [%s:%s:%d] irq-mux =  %d\n","aw963xx.c","aw963xx_parse_dts",0x346,*puVar3
             );
  }
  iVar1 = of_property_read_variable_u32_array(uVar2,"start-mode",puVar3 + 1,1,0);
  if (iVar1 < 0) {
    _dev_err(param_1[1]," [%s:%s:%d] start-mode not detected\n","aw963xx.c","aw963xx_parse_dts",
             0x34b);
  }
  else {
    _dev_info(param_1[1]," [%s:%s:%d] start-mode =  %d\n","aw963xx.c","aw963xx_parse_dts",0x34d,
              puVar3[1]);
  }
  return 0;
}



//------------------------------------------------------------
// aw963xx_rc_irqscr @ 00107db0 size=88
// signature: undefined aw963xx_rc_irqscr(void)
// callers: []
//------------------------------------------------------------

void aw963xx_rc_irqscr(undefined8 param_1)

{
  long lVar1;
  undefined4 local_1c;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c = 0;
  aw_sar_i2c_read(param_1,0xf080,&local_1c);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}



//------------------------------------------------------------
// aw963xx_irq_handle_func @ 00107e0c size=340
// signature: undefined aw963xx_irq_handle_func(void)
// callers: []
//------------------------------------------------------------

void aw963xx_irq_handle_func(undefined8 param_1,undefined8 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  uint uVar8;
  uint local_88 [12];
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_88[8] = 0;
  local_88[9] = 0;
  local_88[10] = 0;
  local_88[0xb] = 0;
  local_88[4] = 0;
  local_88[5] = 0;
  local_88[6] = 0;
  local_88[7] = 0;
  local_88[0] = 0;
  local_88[1] = 0;
  local_88[2] = 0;
  local_88[3] = 0;
  aw_sar_i2c_read(*param_2,0x20,&local_58);
  aw_sar_i2c_read(*param_2,0x24,(ulong)&local_58 | 4);
  lVar6 = 0;
  lVar7 = 0;
  do {
    lVar5 = *(long *)(param_2[0x4f] + lVar6 + 8);
    if (lVar5 != 0) {
      uVar1 = *(uint *)(param_2[0x4f] + lVar6 + 4);
      uVar2 = local_88[lVar7];
      uVar8 = (uint)local_58 >> (ulong)((uint)lVar7 & 0x1f) & 1;
      uVar4 = local_58._4_4_ >> (ulong)((uint)lVar7 & 0x1f) & 1;
      uVar3 = uVar4 << 1 | uVar8 | uVar2;
      local_88[lVar7] = uVar3;
      if (uVar1 != uVar3) {
        if ((uVar2 >> 3 & 1) == 0) {
          if ((uVar2 >> 2 & 1) == 0) {
            uVar8 = uVar8 | uVar2 & 1;
            if (uVar4 != 0 || (uVar2 & 2) != 0) {
              uVar8 = 2;
            }
          }
          else {
            uVar8 = 3;
          }
        }
        else {
          uVar8 = 4;
        }
        input_event(lVar5,3,0x19,uVar8);
        input_event(*(undefined8 *)(param_2[0x4f] + lVar6 + 8),0,0,0);
        *(uint *)(param_2[0x4f] + lVar6 + 4) = uVar3;
      }
    }
    lVar7 = lVar7 + 1;
    lVar6 = lVar6 + 0x28;
  } while (lVar7 != 0xc);
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw963xx_update_firmware @ 00107f64 size=2528
// signature: undefined aw963xx_update_firmware(void)
// callers: []
//------------------------------------------------------------

int aw963xx_update_firmware(long param_1,undefined8 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  void *__s;
  void *pvVar11;
  undefined8 uVar12;
  char *pcVar13;
  undefined8 uVar14;
  ulong uVar15;
  uint uVar16;
  ulong uVar17;
  ulong __n;
  uint uVar18;
  long lVar19;
  int iVar20;
  undefined8 uVar21;
  uint uVar22;
  ulong uVar23;
  undefined8 *puVar24;
  ulong uVar25;
  uint uVar26;
  uint local_6c;
  long local_68;
  
  lVar19 = sp_el0;
  local_68 = *(long *)(lVar19 + 0x638);
  lVar19 = param_2[0x51];
  uVar21 = *param_2;
  _printk(&DAT_0010c2b1,"aw963xx_update_firmware");
  if (*(int *)(lVar19 + 4) == 0) {
    _dev_info(param_2[1]," [%s:%s:%d] no need to update fw.\n","aw963xx.c","aw963xx_update_firmware"
              ,0xf7);
LAB_00108900:
    iVar10 = 0;
  }
  else {
    aw_sar_i2c_write(uVar21,0xfff4,0x3c00d11f);
    aw_sar_i2c_write(uVar21,0xc400,0x21660000);
    aw_sar_i2c_write(uVar21,0xf800,0x10100);
    aw_sar_i2c_write(uVar21,0xffe4,0x3c000000);
    uVar2 = *(uint *)(param_1 + 0x48);
    uVar3 = *(uint *)(param_1 + 0x4c);
    if (3 < uVar3) {
      lVar19 = param_1 + 0x1c38;
      uVar15 = (ulong)(uVar3 >> 2);
      uVar16 = uVar2;
      do {
        uVar18 = uVar16 + 3;
        uVar1 = uVar16 + 2;
        uVar26 = uVar16 + 1;
        uVar17 = (ulong)uVar16;
        uVar15 = uVar15 - 1;
        uVar16 = uVar16 + 4;
        uVar5 = *(undefined1 *)(lVar19 + (ulong)uVar26);
        uVar6 = *(undefined1 *)(lVar19 + uVar17);
        *(undefined1 *)(lVar19 + uVar17) = *(undefined1 *)(lVar19 + (ulong)uVar18);
        *(undefined1 *)(lVar19 + (ulong)uVar26) = *(undefined1 *)(lVar19 + (ulong)uVar1);
        *(undefined1 *)(lVar19 + (ulong)uVar1) = uVar5;
        *(undefined1 *)(lVar19 + (ulong)uVar18) = uVar6;
      } while (uVar15 != 0);
    }
    uVar4 = *(undefined4 *)(param_1 + 0x58);
    puVar24 = param_2 + 1;
    __s = (void *)devm_kmalloc(*puVar24,0x400,0xdc0);
    if (__s == (void *)0x0) {
      _dev_err(*puVar24," [%s:%s:%d] devm_kzalloc error\n","aw963xx.c","aw963xx_sram_data_write",
               0xa7);
LAB_001087a4:
      _dev_info(*puVar24," [%s:%s:%d] sram_data_write error\n","aw963xx.c","aw963xx_update_firmware"
                ,0x10d);
    }
    else {
      uVar16 = uVar3 & 0x3ff;
      uVar17 = (ulong)uVar16;
      memset(&aw963xx_buf_2,0xff,0x402);
      uVar15 = (ulong)(uVar3 >> 10);
      if ((uVar3 & 0x3ff) != 0) {
        uVar15 = uVar15 + 1;
      }
      _dev_info(*puVar24," [%s:%s:%d] fw_bin_version = 0x%x\n","aw963xx.c","aw963xx_sram_data_write"
                ,0xb0,uVar4);
      _dev_info(*puVar24," [%s:%s:%d] download_addr = 0x%x\n","aw963xx.c","aw963xx_sram_data_write",
                0xb1,0x2000);
      _dev_info(*puVar24," [%s:%s:%d] start_index = %d\n","aw963xx.c","aw963xx_sram_data_write",0xb2
                ,uVar2);
      _dev_info(*puVar24," [%s:%s:%d] fw_len = %d\n","aw963xx.c","aw963xx_sram_data_write",0xb3,
                uVar3);
      if ((int)uVar15 != 0) {
        uVar25 = 0;
        uVar23 = (ulong)((int)uVar15 - 1);
        uVar1 = 0x3f8 - uVar3 & 0x3ff;
        __n = (ulong)uVar1;
        uVar18 = uVar16 | 0x2000;
        uVar26 = 0x2ff8 - uVar16;
        do {
          memset(__s,0,0x400);
          iVar8 = (int)uVar25 * 0x400;
          uVar22 = iVar8 + 0x2000;
          DAT_0010edd5 = 0;
          pvVar11 = (void *)(param_1 + 0x1c38 + (ulong)(iVar8 + uVar2));
          aw963xx_buf_2 = (undefined1)(uVar22 >> 8);
          if (uVar25 == uVar23) {
            memcpy(&DAT_0010edd6,pvVar11,uVar17);
            iVar8 = aw_sar_i2c_write_seq(*param_2,&aw963xx_buf_2,uVar16 + 2);
            if (iVar8 != 0) {
              pcVar13 = " [%s:%s:%d] cnt%d, write_seq error!\n";
              uVar12 = *puVar24;
              uVar14 = 0xd1;
              uVar25 = uVar23;
              goto LAB_00108624;
            }
            iVar8 = aw_sar_i2c_read_seq(*param_2,&aw963xx_buf_2,2,__s,uVar17);
            if (iVar8 != 0) {
              pcVar13 = " [%s:%s:%d] cnt%d, read_seq error!\n";
              uVar12 = *puVar24;
              uVar14 = 0xd7;
              uVar25 = uVar23;
              goto LAB_00108624;
            }
            iVar8 = bcmp(&DAT_0010edd6,__s,uVar17);
            if (iVar8 == 0) {
              pvVar11 = (void *)devm_kmalloc(*puVar24,0x400,0xdc0);
              if (pvVar11 != (void *)0x0) {
                uVar22 = uVar22 | uVar16;
                iVar8 = (uint)(uVar1 != 0) + (0x4ff8 - uVar22 >> 10);
                _dev_info(*puVar24," [%s:%s:%d] last_pack_len = %d\n","aw963xx.c",
                          "aw963xx_sram_fill_not_wrote_area",0x5d,__n);
                _dev_info(*puVar24," [%s:%s:%d] pack_cnt = %d\n","aw963xx.c",
                          "aw963xx_sram_fill_not_wrote_area",0x5e,iVar8);
                _dev_info(*puVar24," [%s:%s:%d] offset = 0x%x\n","aw963xx.c",
                          "aw963xx_sram_fill_not_wrote_area",0x5f,uVar22);
                memset(&aw963xx_buf_1,0xff,0x402);
                if (iVar8 != 0) {
                  iVar20 = 0;
                  iVar10 = (uint)(uVar1 != 0) + (uVar26 >> 10);
                  iVar8 = iVar8 + -1;
                  uVar22 = uVar18;
                  do {
                    memset(pvVar11,0,0x400);
                    aw963xx_buf_1 = (undefined1)(uVar22 >> 8);
                    DAT_0010e9d1 = (undefined1)uVar3;
                    if (iVar10 + iVar20 != 1) {
                      iVar9 = aw_sar_i2c_write_seq(*param_2,&aw963xx_buf_1,0x402);
                      if (iVar9 == 0) {
                        iVar9 = aw_sar_i2c_read_seq(*param_2,&aw963xx_buf_1,2,pvVar11,0x400);
                        if (iVar9 != 0) {
                          iVar8 = -iVar20;
                          pcVar13 = " [%s:%s:%d] cnt%d, read_seq error!\n";
                          uVar12 = *puVar24;
                          uVar14 = 0x71;
                          goto LAB_00108730;
                        }
                        iVar9 = bcmp(&DAT_0010e9d2,pvVar11,0x400);
                        if (iVar9 == 0) goto LAB_00108448;
                        uVar12 = *puVar24;
                        uVar14 = 0x76;
LAB_0010875c:
                        _dev_err(uVar12," [%s:%s:%d] read is not equal to write \n","aw963xx.c",
                                 "aw963xx_sram_fill_not_wrote_area",uVar14);
                      }
                      else {
                        iVar8 = -iVar20;
                        pcVar13 = " [%s:%s:%d] cnt%d, write_seq error!\n";
                        uVar12 = *puVar24;
                        uVar14 = 0x6b;
LAB_00108730:
                        _dev_info(uVar12,pcVar13,"aw963xx.c","aw963xx_sram_fill_not_wrote_area",
                                  uVar14,iVar8);
                      }
                      devm_kfree(*puVar24,pvVar11);
                      goto LAB_0010876c;
                    }
                    iVar9 = aw_sar_i2c_write_seq(*param_2,&aw963xx_buf_1,uVar1 + 2);
                    if (iVar9 != 0) {
                      pcVar13 = " [%s:%s:%d] cnt%d, write_seq error!\n";
                      uVar12 = *puVar24;
                      uVar14 = 0x7d;
                      goto LAB_00108730;
                    }
                    iVar9 = aw_sar_i2c_read_seq(*param_2,&aw963xx_buf_1,2,pvVar11,__n);
                    if (iVar9 != 0) {
                      pcVar13 = " [%s:%s:%d] cnt%d, read_seq error!\n";
                      uVar12 = *puVar24;
                      uVar14 = 0x83;
                      goto LAB_00108730;
                    }
                    iVar9 = bcmp(&DAT_0010e9d2,pvVar11,__n);
                    if (iVar9 != 0) {
                      uVar12 = *puVar24;
                      uVar14 = 0x88;
                      goto LAB_0010875c;
                    }
LAB_00108448:
                    iVar20 = iVar20 + -1;
                    uVar22 = uVar22 + 0x400;
                  } while (iVar10 + iVar20 != 0);
                }
                devm_kfree(*puVar24,pvVar11);
                goto LAB_00108260;
              }
              _dev_err(*puVar24," [%s:%s:%d] devm_kzalloc error\n","aw963xx.c",
                       "aw963xx_sram_fill_not_wrote_area",0x59);
LAB_0010876c:
              _dev_info(*puVar24," [%s:%s:%d] cnt%d, sram_fill_not_wrote_area error!\n","aw963xx.c",
                        "aw963xx_sram_data_write",0xe3,uVar23);
              uVar12 = *puVar24;
LAB_0010879c:
              devm_kfree(uVar12,__s);
              goto LAB_001087a4;
            }
            _dev_err(*puVar24," [%s:%s:%d] read is not equal to write \n","aw963xx.c",
                     "aw963xx_sram_data_write",0xdc);
            break;
          }
          memcpy(&DAT_0010edd6,pvVar11,0x400);
          iVar8 = aw_sar_i2c_write_seq(*param_2,&aw963xx_buf_2,0x402);
          if (iVar8 != 0) {
            pcVar13 = " [%s:%s:%d] cnt%d, write_seq error!\n";
            uVar12 = *puVar24;
            uVar14 = 0xbe;
LAB_00108624:
            _dev_info(uVar12,pcVar13,"aw963xx.c","aw963xx_sram_data_write",uVar14,
                      uVar25 & 0xffffffff);
LAB_00108628:
            uVar12 = *puVar24;
            goto LAB_0010879c;
          }
          iVar8 = aw_sar_i2c_read_seq(*param_2,&aw963xx_buf_2,2,__s,0x400);
          if (iVar8 != 0) {
            pcVar13 = " [%s:%s:%d] cnt%d, read_seq error!\n";
            uVar12 = *puVar24;
            uVar14 = 0xc4;
            goto LAB_00108624;
          }
          iVar8 = bcmp(&DAT_0010edd6,__s,0x400);
          if (iVar8 != 0) {
            _dev_err(*puVar24," [%s:%s:%d] read is not equal to write \n","aw963xx.c",
                     "aw963xx_sram_data_write",0xc9);
            goto LAB_00108628;
          }
LAB_00108260:
          uVar25 = uVar25 + 1;
          uVar18 = uVar18 + 0x400;
          uVar26 = uVar26 - 0x400;
        } while (uVar25 != uVar15);
      }
      devm_kfree(*puVar24,__s);
      _dev_info(*puVar24," [%s:%s:%d] sram_data_write OK\n","aw963xx.c","aw963xx_update_firmware",
                0x10b);
    }
    __const_udelay(0xc49c08);
    aw_sar_i2c_write(uVar21,0xf800,0x100);
    aw_sar_i2c_write(uVar21,0xff0c,0);
    msleep(0x1e);
    iVar8 = -1000;
    local_6c = 0;
    do {
      iVar10 = aw_sar_i2c_read(*param_2,0xf080,&local_6c);
      if (iVar10 != 0) {
        _dev_err(*puVar24," [%s:%s:%d] i2c error %d\n","aw963xx.c","aw963xx_read_init_over_irq",0x18
                 ,iVar10);
        goto LAB_00108904;
      }
      if ((local_6c & 1) != 0) {
        _dev_info(param_2[1]," [%s:%s:%d] read init irq success!\n","aw963xx.c",
                  "aw963xx_read_init_over_irq",0x1c);
        aw_sar_i2c_read(*param_2,0x5c,&local_6c);
        _dev_info(param_2[1]," [%s:%s:%d] firmware version = 0x%08x\n","aw963xx.c",
                  "aw963xx_read_init_over_irq",0x1e,local_6c);
        goto LAB_00108900;
      }
      __const_udelay(0x418958);
      bVar7 = iVar8 != -1;
      iVar8 = iVar8 + 1;
    } while (bVar7);
    aw_sar_i2c_read(*param_2,0x5c,&local_6c);
    _dev_info(param_2[1]," [%s:%s:%d] firmware version = 0x%08x\n","aw963xx.c",
              "aw963xx_read_init_over_irq",0x25,local_6c);
    iVar10 = -1;
  }
LAB_00108904:
  lVar19 = sp_el0;
  if (*(long *)(lVar19 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar10;
}



//------------------------------------------------------------
// aw963xx_sar_get_firmware_info @ 00108948 size=148
// signature: undefined aw963xx_sar_get_firmware_info(void)
// callers: []
//------------------------------------------------------------

void aw963xx_sar_get_firmware_info(undefined8 *param_1,long param_2,long *param_3)

{
  long lVar1;
  int iVar2;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  aw_sar_i2c_read(*param_1,0x5c,&local_2c);
  iVar2 = snprintf((char *)(param_2 + *param_3),0x1000 - *param_3,"firmware is 0x%08x\n",local_2c);
  *param_3 = *param_3 + (long)iVar2;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw963xx_load_reg_bin @ 001089e0 size=296
// signature: undefined aw963xx_load_reg_bin(void)
// callers: []
//------------------------------------------------------------

undefined4 aw963xx_load_reg_bin(long param_1,undefined8 *param_2)

{
  char *__s1;
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int *piVar5;
  
  __s1 = (char *)((long)param_2 + 0x19b);
  piVar5 = (int *)param_2[0x51];
  iVar1 = strncmp(__s1,(char *)(param_1 + 0x30),8);
  if (iVar1 != 0) {
    _dev_err(param_2[1]," [%s:%s:%d] load_binname(%s) incompatible with chip type(%s)\n","aw963xx.c"
             ,"aw963xx_load_reg_bin",0x12f,__s1,(char *)(param_1 + 0x30));
  }
  uVar2 = aw_sar_load_reg(param_1,*param_2);
  iVar1 = strncmp(__s1,"aw96308",8);
  if ((iVar1 == 0) || (iVar1 = strncmp(__s1,"aw96310",8), iVar1 == 0)) {
    if (*piVar5 == 2) {
      uVar3 = 4;
      uVar4 = 0x20;
    }
    else {
      if (*piVar5 != 5) {
        return uVar2;
      }
      uVar3 = 0x20;
      uVar4 = 0x800;
    }
    aw_sar_i2c_write(*param_2,0xfff4,0x3c00d013);
    aw_sar_i2c_write(*param_2,0xc100,uVar4);
    aw_sar_i2c_write(*param_2,0xe018,uVar3);
  }
  return uVar2;
}



//------------------------------------------------------------
// aw963xx_get_cap_offset_send_to_debug @ 00108b0c size=44
// signature: undefined aw963xx_get_cap_offset_send_to_debug(void)
// callers: []
//------------------------------------------------------------

undefined8 aw963xx_get_cap_offset_send_to_debug(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    return 0;
  }
  uVar1 = aw963xx_get_cap_offset(param_1,param_2,0);
  return uVar1;
}



//------------------------------------------------------------
// aw963xx_get_cap_offset @ 00108b38 size=1436
// signature: undefined aw963xx_get_cap_offset(void)
// callers: [aw963xx_get_cap_offset_send_to_debug, offset_show]
//------------------------------------------------------------

void aw963xx_get_cap_offset(undefined8 *param_1,long param_2,long param_3)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  char *__format;
  uint uVar5;
  ulong uVar6;
  uint uVar7;
  ulong uVar8;
  uint uVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  long local_80;
  undefined8 local_70;
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  uVar8 = 0;
  lVar11 = param_1[0x51];
  local_70 = 0;
  do {
    aw_sar_i2c_read(*param_1,(int)uVar8 * 0x118 + 0x130,(long)&local_70 + 4);
    if ((local_70._4_4_ >> 0x10 & 1) != 0) {
      uVar6 = (ulong)(local_70._4_4_ >> 0xb) & 0x1f;
      if (0xb < (uint)uVar6) goto LAB_001090cc;
      *(undefined4 *)(lVar11 + uVar6 * 4 + 8) = 1;
    }
    if ((local_70._4_4_ >> 9 & 1) != 0) {
      uVar9 = local_70._4_4_ >> 4 & 0x1f;
      if (0xb < uVar9) {
LAB_001090cc:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1090d0);
        (*pcVar2)();
      }
      *(undefined4 *)(lVar11 + (ulong)uVar9 * 4 + 8) = 1;
    }
    _dev_info(param_1[1]," [%s:%s:%d] ch%d = %d\n","aw963xx.c","aw963xx_get_ref_ch_enable",0x1c6,
              uVar8 & 0xffffffff,*(undefined4 *)(lVar11 + 8 + uVar8 * 4));
    uVar8 = uVar8 + 1;
  } while (uVar8 != 0xc);
  uVar8 = 0;
  lVar10 = 0;
  uVar9 = 0;
  local_80 = 0;
  lVar12 = param_3 + 1;
  do {
    uVar7 = (uint)uVar8;
    iVar3 = uVar7 * 0x118;
    aw_sar_i2c_read(*param_1,iVar3 + 0x10c,&local_70);
    local_70 = local_70 & 0xffffffff;
    iVar1 = (uVar7 & 0xff) * 0x118;
    aw_sar_i2c_read(*param_1,iVar1 + 0x11c,(long)&local_70 + 4);
    if ((local_70._4_4_ >> 0x1b & 1) == 0) {
      aw_sar_i2c_read(*param_1,iVar1 + 0x120,(long)&local_70 + 4);
      uVar5 = 10;
      if ((local_70 & 0x80000000000) != 0) {
        uVar5 = 0x14;
      }
    }
    else {
      uVar5 = local_70._4_4_ >> 0x1d & 3;
      if (uVar5 == 3) {
        uVar5 = 0x28;
      }
      else {
        uVar5 = 0x1a1410 >> (ulong)(uVar5 << 3);
      }
    }
    if (((uint)local_70 & 0xff) == 5) {
      if (*(int *)(lVar11 + 8 + uVar8 * 4) == 1) {
        local_70 = local_70 & 0xffffffff;
        aw_sar_i2c_read(*param_1,uVar7 * 0x8c + 0x10f8,(long)&local_70 + 4);
        uVar7 = ((local_70._4_4_ >> 0x10 & 0xff) * 0x98 + (local_70._4_4_ >> 8 & 0xff) * 0x26ac) *
                (uVar5 & 0xff);
        uVar9 = uVar7 / 100000;
        uVar6 = (ulong)uVar7 / 10;
        _dev_info(param_1[1]," [%s:%s:%d] ref cap_ofst = %d\n","aw963xx.c","aw963xx_get_cap_offset",
                  0x238,uVar6);
        if (param_2 != 0) {
          __format = "ref unsigned cap ofst ch%d: %d.%dpf\r\n";
LAB_00108e40:
          uVar7 = (int)uVar6 + (int)(uVar6 / 10000) * -10000;
LAB_0010904c:
          uVar6 = (ulong)uVar9;
LAB_0010905c:
          iVar3 = snprintf((char *)(param_2 + lVar10),0x1000 - lVar10,__format,uVar8 & 0xffffffff,
                           uVar6,(ulong)uVar7);
          lVar10 = lVar10 + iVar3;
        }
      }
      else {
        iVar3 = aw963xx_get_signed_cap(param_1,iVar3 + 0x118);
        iVar3 = iVar3 * (uVar5 & 0xff);
        uVar9 = iVar3 / 100000;
        uVar7 = iVar3 / 10;
        _dev_info(param_1[1]," [%s:%s:%d] cap_ofst1 = 0x%x\n","aw963xx.c","aw963xx_get_cap_offset",
                  0x245,uVar7);
        if (iVar3 < -9) {
          _dev_info(param_1[1]," [%s:%s:%d] cap_ofst2 = 0x%x\n","aw963xx.c","aw963xx_get_cap_offset"
                    ,0x248,uVar7);
          if (param_2 != 0) {
            __format = "mutual cap ofst ch%d: -%d.%dpf\r\n";
            goto LAB_00108fc4;
          }
        }
        else {
          _dev_info(param_1[1]," [%s:%s:%d] cap_ofst2 = 0x%x\n","aw963xx.c","aw963xx_get_cap_offset"
                    ,0x251,uVar7);
          if (param_2 != 0) {
            __format = "mutual cap ofst ch%d: %d.%dpf\r\n";
            goto LAB_00109040;
          }
        }
      }
    }
    else if (((uint)local_70 & 0xff) == 4) {
      iVar3 = aw963xx_get_signed_cap(param_1,iVar3 + 0x118);
      iVar3 = iVar3 * (uVar5 & 0xff);
      uVar9 = iVar3 / 100000;
      uVar7 = iVar3 / 10;
      _dev_info(param_1[1]," [%s:%s:%d] cap_ofst1 = 0x%x\n","aw963xx.c","aw963xx_get_cap_offset",
                0x21c,uVar7);
      if (iVar3 < -9) {
        _dev_info(param_1[1]," [%s:%s:%d] cap_ofst2 = 0x%x\n","aw963xx.c","aw963xx_get_cap_offset",
                  0x21f,uVar7);
        if (param_2 != 0) {
          __format = "signed cap ofst ch%d: -%d.%dpf\r\n";
LAB_00108fc4:
          uVar6 = (ulong)-uVar7 / 10000;
          uVar7 = -uVar7 % 10000;
          goto LAB_0010905c;
        }
      }
      else {
        _dev_info(param_1[1]," [%s:%s:%d] cap_ofst2 = 0x%x\n","aw963xx.c","aw963xx_get_cap_offset",
                  0x228,uVar7);
        if (param_2 != 0) {
          __format = "signed cap ofst ch%d: %d.%dpf\r\n";
LAB_00109040:
          uVar7 = uVar7 % 10000;
          goto LAB_0010904c;
        }
      }
    }
    else if ((local_70 & 0xff) == 0) {
      local_70 = local_70 & 0xffffffff;
      aw_sar_i2c_read(*param_1,iVar3 + 0x118,(long)&local_70 + 4);
      uVar7 = ((local_70._4_4_ >> 0x10 & 0xff) * 0x98 + (local_70._4_4_ >> 8 & 0xff) * 0x26ac) *
              (uVar5 & 0xff);
      uVar9 = uVar7 / 100000;
      uVar6 = (ulong)uVar7 / 10;
      _dev_info(param_1[1]," [%s:%s:%d] cap_ofst = %d\n","aw963xx.c","aw963xx_get_cap_offset",0x20e,
                uVar6);
      if (param_2 != 0) {
        __format = "unsigned cap ofst ch%d: %d.%dpf\r\n";
        goto LAB_00108e40;
      }
    }
    else {
      _dev_info(param_1[1]," [%s:%s:%d] aw963xx ofst error 0x%x\n","aw963xx.c",
                "aw963xx_get_cap_offset",0x25d,(uint)local_70 & 0xf);
    }
    if (param_3 == 0) {
      lVar4 = lVar10;
    }
    else {
      *(uint *)(lVar12 + -1) = uVar9;
      local_80 = local_80 + 4;
      lVar4 = local_80;
    }
    uVar8 = uVar8 + 1;
    lVar12 = lVar12 + 4;
    if (uVar8 == 0xc) {
      lVar11 = sp_el0;
      if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail(lVar4);
      }
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// aw963xx_get_signed_cap @ 001090d4 size=412
// signature: undefined aw963xx_get_signed_cap(void)
// callers: [aw963xx_get_cap_offset]
//------------------------------------------------------------

int aw963xx_get_signed_cap(undefined8 *param_1,undefined8 param_2)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_5c = 0;
  aw_sar_i2c_read(*param_1,param_2,&local_5c);
  uVar2 = local_5c;
  iVar3 = aw_sar_pow2(0);
  iVar4 = aw_sar_pow2(1);
  iVar5 = aw_sar_pow2(2);
  iVar6 = aw_sar_pow2(3);
  iVar7 = aw_sar_pow2(4);
  iVar8 = aw_sar_pow2(5);
  iVar9 = aw_sar_pow2(6);
  iVar10 = aw_sar_pow2(7);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return ((uVar2 & 1) * -0x4d58 + 0x26ac & (int)(uVar2 << 0x17) >> 0x1f) * iVar3 +
         ((uVar2 & 2) * -0x26ac + 0x26ac & (int)(uVar2 << 0x16) >> 0x1f) * iVar4 +
         ((uVar2 >> 1 & 2) * -0x26ac + 0x26ac & (int)(uVar2 << 0x15) >> 0x1f) * iVar5 +
         ((uVar2 >> 2 & 2) * -0x26ac + 0x26ac & (int)(uVar2 << 0x14) >> 0x1f) * iVar6 +
         ((uVar2 >> 3 & 2) * -0x26ac + 0x26ac & (int)(uVar2 << 0x13) >> 0x1f) * iVar7 +
         ((uVar2 >> 4 & 2) * -0x26ac + 0x26ac & (int)(uVar2 << 0x12) >> 0x1f) * iVar8 +
         ((uVar2 >> 5 & 2) * -0x26ac + 0x26ac & (int)(uVar2 << 0x11) >> 0x1f) * iVar9 +
         ((uVar2 >> 6 & 2) * -0x26ac + 0x26ac & (int)(uVar2 << 0x10) >> 0x1f) * iVar10 +
         (uVar2 >> 0x10 & 0xff) * 0x98;
}



//------------------------------------------------------------
// aw963xx_operation_mode_get @ 00109274 size=176
// signature: undefined aw963xx_operation_mode_get(void)
// callers: []
//------------------------------------------------------------

undefined8 aw963xx_operation_mode_get(long param_1,char *param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  uVar7 = s_operation_mode__Active_0010c7dc._16_8_;
  uVar6 = s_operation_mode__Active_0010c7dc._8_8_;
  uVar5 = s_operation_mode__DeepSleep_0010a8a7._16_8_;
  uVar3 = s_operation_mode__DeepSleep_0010a8a7._8_8_;
  uVar2 = s_operation_mode__DeepSleep_0010a8a7._0_8_;
  uVar4 = s_operation_mode__Unconfirmed_0010a505._8_8_;
  cVar1 = *(char *)(param_1 + 0x1b1);
  if (cVar1 == '\x03') {
    param_2[0x17] = 'e';
    param_2[0x18] = 'p';
    param_2[0x19] = '\n';
    param_2[0x1a] = '\0';
    *(undefined8 *)param_2 = uVar2;
    *(undefined8 *)(param_2 + 8) = uVar3;
    *(undefined8 *)(param_2 + 0x10) = uVar5;
    return 0x1a;
  }
  if (cVar1 == '\x02') {
    uVar4 = CONCAT17(s_operation_mode__Sleep_0010b4ff[0xf],s_operation_mode__Sleep_0010b4ff._8_7_);
    uVar2 = CONCAT71(s_operation_mode__Sleep_0010b4ff._16_7_,s_operation_mode__Sleep_0010b4ff[0xf]);
    *(undefined8 *)param_2 = s_operation_mode__Sleep_0010b4ff._0_8_;
    *(undefined8 *)(param_2 + 8) = uVar4;
    *(undefined8 *)(param_2 + 0xf) = uVar2;
    return 0x16;
  }
  if (cVar1 == '\x01') {
    *(undefined8 *)param_2 = s_operation_mode__Active_0010c7dc._0_8_;
    *(undefined8 *)(param_2 + 8) = uVar6;
    *(undefined8 *)(param_2 + 0x10) = uVar7;
    return 0x17;
  }
  uVar2 = CONCAT35(s_operation_mode__Unconfirmed_0010a505._21_3_,
                   s_operation_mode__Unconfirmed_0010a505._16_5_);
  uVar3 = CONCAT53(s_operation_mode__Unconfirmed_0010a505._24_5_,
                   s_operation_mode__Unconfirmed_0010a505._21_3_);
  *(undefined8 *)param_2 = s_operation_mode__Unconfirmed_0010a505._0_8_;
  *(undefined8 *)(param_2 + 8) = uVar4;
  *(undefined8 *)(param_2 + 0x10) = uVar2;
  *(undefined8 *)(param_2 + 0x15) = uVar3;
  return 0x1c;
}



//------------------------------------------------------------
// aw963xx_enable_clock @ 00109328 size=40
// signature: undefined aw963xx_enable_clock(void)
// callers: []
//------------------------------------------------------------

void aw963xx_enable_clock(undefined8 param_1)

{
  aw_sar_i2c_write_bits(param_1,0xff00,0xfffffffe,1);
  return;
}



//------------------------------------------------------------
// aw963xx_set_active_cmd @ 00109354 size=36
// signature: undefined aw963xx_set_active_cmd(void)
// callers: []
//------------------------------------------------------------

void aw963xx_set_active_cmd(undefined8 param_1)

{
  aw_sar_i2c_write(param_1,0xf008,1);
  return;
}



//------------------------------------------------------------
// aw963xx_set_sleep_cmd @ 0010937c size=36
// signature: undefined aw963xx_set_sleep_cmd(void)
// callers: []
//------------------------------------------------------------

void aw963xx_set_sleep_cmd(undefined8 param_1)

{
  aw_sar_i2c_write(param_1,0xf008,2);
  return;
}



//------------------------------------------------------------
// aw963xx_set_deepsleep_cmd @ 001093a4 size=36
// signature: undefined aw963xx_set_deepsleep_cmd(void)
// callers: []
//------------------------------------------------------------

void aw963xx_set_deepsleep_cmd(undefined8 param_1)

{
  aw_sar_i2c_write(param_1,0xf008,3);
  return;
}



//------------------------------------------------------------
// aw963xx_sar_chip_info_get @ 001093cc size=296
// signature: undefined aw963xx_sar_chip_info_get(void)
// callers: []
//------------------------------------------------------------

void aw963xx_sar_chip_info_get(undefined8 *param_1,long param_2,long *param_3)

{
  long lVar1;
  int iVar2;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  iVar2 = snprintf((char *)(param_2 + *param_3),0x1000 - *param_3,
                   "sar%d, aw963xx chip driver version:%s\n",*(int *)(param_1 + 0x38),"v0.1.1.14");
  lVar1 = *param_3 + (long)iVar2;
  *param_3 = lVar1;
  iVar2 = snprintf((char *)(param_2 + lVar1),0x1000 - lVar1,"The driver supports UI\n");
  *param_3 = *param_3 + (long)iVar2;
  aw_sar_i2c_read(*param_1,0xff10,&local_3c);
  iVar2 = snprintf((char *)(param_2 + *param_3),0x1000 - *param_3,"chipid is 0x%08x\n",local_3c);
  *param_3 = *param_3 + (long)iVar2;
  aw_sar_i2c_read(*param_1,0xf084,&local_3c);
  iVar2 = snprintf((char *)(param_2 + *param_3),0x1000 - *param_3,"REG_HOSTIRQEN is 0x%08x\n",
                   local_3c);
  *param_3 = *param_3 + (long)iVar2;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// capsensor_set_enable @ 001094f8 size=452
// signature: undefined capsensor_set_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 capsensor_set_enable(long param_1,int param_2)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  int iVar4;
  char *__s1;
  long lVar5;
  long lVar6;
  
  lVar5 = g_aw963xx;
  _printk(&DAT_0010c2b1,"capsensor_set_enable");
  if ((lVar5 != 0) && (puVar3 = *(undefined8 **)(lVar5 + 0x38), puVar3 != (undefined8 *)0x0)) {
    iVar4 = 0;
    lVar5 = 0;
    lVar6 = puVar3[0x4f];
    do {
      if ((*(short *)(lVar6 + lVar5) != 0) && (lVar1 = lVar6 + lVar5, *(long *)(lVar1 + 8) != 0)) {
        __s1 = *(char **)(param_1 + 0x18);
        iVar2 = strcmp(__s1,(char *)(lVar1 + 0x10));
        if (iVar2 == 0) {
          if (param_2 == 0) {
            _printk(&DAT_0010b253,iVar4,__s1);
            if (capsensor_set_enable_sar_cali_flag == 1) {
              aw_sar_mode_set(puVar3,2);
              capsensor_set_enable_sar_cali_flag = 0;
            }
            input_event(*(undefined8 *)(puVar3[0x4f] + lVar5 + 8),3,0x19,0xffffffff);
            input_event(*(undefined8 *)(puVar3[0x4f] + lVar5 + 8),0,0,0);
            *(undefined4 *)(puVar3[0x4f] + lVar5 + 4) = 0xffffffff;
            return 0;
          }
          if (param_2 != 1) {
            return 0;
          }
          _printk(&DAT_0010c13f,iVar4,__s1);
          if ((capsensor_set_enable_sar_cali_flag & 1) == 0) {
            aw_sar_i2c_write_bits(*puVar3,4,0xfffff000,0xfff);
            aw_sar_mode_set(puVar3,1);
            capsensor_set_enable_sar_cali_flag = 1;
          }
          input_event(*(undefined8 *)(puVar3[0x4f] + lVar5 + 8),3,0x19,0);
          input_event(*(undefined8 *)(puVar3[0x4f] + lVar5 + 8),0,0,0);
          return 0;
        }
      }
      lVar5 = lVar5 + 0x28;
      iVar4 = iVar4 + 1;
    } while (lVar5 != 0x1e0);
  }
  return 0;
}



//------------------------------------------------------------
// cali_show @ 001096c0 size=108
// signature: undefined cali_show(void)
// callers: []
//------------------------------------------------------------

long cali_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  
  if ((param_1 == 0xa8) || (*(undefined8 **)(param_1 + -0x70) == (undefined8 *)0x0)) {
    lVar3 = 0;
  }
  else {
    uVar2 = aw_sar_i2c_write_bits(**(undefined8 **)(param_1 + -0x70),4,0xfffff000,0xfff);
    iVar1 = snprintf(param_3,8,"%d\n",uVar2 & 0xffffffff);
    lVar3 = (long)iVar1;
  }
  return lVar3;
}



//------------------------------------------------------------
// reset_store @ 00109730 size=216
// signature: undefined reset_store(void)
// callers: []
//------------------------------------------------------------

undefined8 reset_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  if ((param_1 == 0xa8) || (puVar3 = *(undefined8 **)(param_1 + -0x70), puVar3 == (undefined8 *)0x0)
     ) {
    param_4 = 0;
  }
  else {
    aw_sar_i2c_read(*puVar3,0x1c,&local_3c);
    iVar2 = strncmp(param_3,"reset",5);
    if (((iVar2 == 0) || (*param_3 == '1')) && ((local_3c & 0x3000000) == 0x1000000)) {
      aw_sar_i2c_write_bits(*puVar3,4,0xfffff000,0xfff);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// int_state_show @ 0010980c size=80
// signature: undefined int_state_show(void)
// callers: []
//------------------------------------------------------------

long int_state_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  
  if ((param_1 == 0xa8) || (*(long *)(param_1 + -0x70) == 0)) {
    lVar2 = 0;
  }
  else {
    iVar1 = snprintf(param_3,8,"%d\n",(ulong)*(byte *)(*(long *)(param_1 + -0x70) + 0x1b8));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// mode_show @ 00109860 size=88
// signature: undefined mode_show(void)
// callers: []
//------------------------------------------------------------

long mode_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  
  if ((param_1 == 0xa8) || (*(long *)(param_1 + -0x70) == 0)) {
    lVar2 = 0;
  }
  else {
    iVar1 = snprintf(param_3,8,"%d\n",
                     (ulong)(*(char *)(*(long *)(param_1 + -0x70) + 0x1b1) == '\x01'));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// mode_store @ 001098bc size=84
// signature: undefined mode_store(void)
// callers: []
//------------------------------------------------------------

undefined8 mode_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  undefined4 uVar1;
  
  if ((param_1 == 0xa8) || (*(long *)(param_1 + -0x70) == 0)) {
    param_4 = 0;
  }
  else {
    uVar1 = 1;
    if (*param_3 != '\x01') {
      uVar1 = 2;
    }
    aw_sar_mode_set(*(long *)(param_1 + -0x70),uVar1);
  }
  return param_4;
}



//------------------------------------------------------------
// reg_show @ 00109914 size=88
// signature: undefined reg_show(void)
// callers: []
//------------------------------------------------------------

undefined8 reg_show(long param_1)

{
  undefined8 uVar1;
  
  if ((param_1 == 0xa8) || (*(undefined8 **)(param_1 + -0x70) == (undefined8 *)0x0)) {
    uVar1 = 0;
  }
  else if (*(char *)(param_1 + 0x98) == '\0') {
    uVar1 = 0xffffffffffffffff;
  }
  else {
    *(undefined1 *)(param_1 + 0x98) = 0;
    aw_sar_i2c_read(**(undefined8 **)(param_1 + -0x70),*(undefined2 *)(param_1 + 0x9a));
    uVar1 = 4;
  }
  return uVar1;
}



//------------------------------------------------------------
// reg_store @ 00109970 size=188
// signature: undefined reg_store(void)
// callers: []
//------------------------------------------------------------

undefined8 reg_store(long param_1,undefined8 param_2,ushort *param_3,long param_4)

{
  ushort uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  if (param_1 == 0xa8) {
    uVar4 = 0;
  }
  else {
    puVar3 = *(undefined8 **)(param_1 + -0x70);
    uVar4 = 0;
    if (puVar3 != (undefined8 *)0x0) {
      if (param_4 == 7) {
        if ((char)param_3[3] == '\0') {
          uVar2 = (*(uint *)(param_3 + 1) & 0xff00ff00) >> 8 |
                  (*(uint *)(param_3 + 1) & 0xff00ff) << 8;
          aw_sar_i2c_write(*puVar3,*param_3 >> 8 | *param_3 << 8,uVar2 >> 0x10 | uVar2 << 0x10);
        }
        else if ((char)param_3[3] == '\x01') {
          uVar1 = *param_3;
          *(undefined1 *)(param_1 + 0x98) = 1;
          *(ushort *)(param_1 + 0x9a) = uVar1 >> 8 | uVar1 << 8;
          return 7;
        }
        uVar4 = 7;
      }
      else {
        _dev_err(puVar3[1]," [%s:%s:%d] params error[ count == %lu !=2]\n\n","aw963xx.c","reg_store"
                 ,0x476,param_4);
        uVar4 = 0xffffffffffffffff;
      }
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// offset_show @ 00109a30 size=72
// signature: undefined offset_show(void)
// callers: []
//------------------------------------------------------------

undefined8 offset_show(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  if (param_1 == 0xa8) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
    if ((param_3 != 0) && (*(long *)(param_1 + -0x70) != 0)) {
      uVar1 = aw963xx_get_cap_offset(*(long *)(param_1 + -0x70),0);
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// init_module @ 0010c91c size=100
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  _printk(&DAT_00109bdd,"v0.1.5.14");
  iVar1 = i2c_register_driver(&__this_module,&aw_sar_i2c_driver);
  if (iVar1 != 0) {
    _printk(&DAT_0010bf34);
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 0010c984 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  i2c_del_driver(&aw_sar_i2c_driver);
  return;
}



//------------------------------------------------------------
// i2c_transfer @ 00111000 size=1
// signature: undefined i2c_transfer(void)
// callers: [aw_sar_i2c_write_seq, aw_sar_i2c_write, aw_sar_i2c_read, aw_sar_i2c_read_seq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_transfer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00111008 size=1
// signature: undefined _printk(void)
// callers: [aw_sar_parsing_bin_file, aw_get_single_bin_header_1_0_0, aw_sar_parsing_bin_file_new, aw_sar_i2c_probe, aw_sar_custom_flie_node_free, aw_sar_i2c_write, aw963xx_update_firmware, aw_check_soc_app_num_v1, aw_parse_bin_header_1_0_0, aw_check_dsp_reg_num_v1, aw963xx_init, capsensor_set_enable, aw_check_register_num_v1, aw_check_sum, aw_sar_i2c_read, aw_sar_int_output, aw963xx_deinit, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00111010 size=1
// signature: undefined _dev_err(void)
// callers: [aw_sar_custom_flie_node_create, aw_sar_i2c_write_seq, aw_sar_i2c_write, aw_sar_update_work, aw963xx_update_firmware, aw_sar_i2c_read_seq, aw_sar_reg_set, aw_sar_ps_notify_callback, aw_sar_load_reg, reg_store, aw_sar_load_def_reg_bin, aw_sar_input_free, aw_sar_mode_operation_set, aw963xx_load_reg_bin, aw_sar_i2c_probe, aw_sar_i2c_remove, aw_sar_awrw_get, aw_sar_parse_dts_comm, aw_sar_soft_reset, aw_sar_load_bin_comm, aw963xx_check_chipid, aw_sar_soft_rst_set, aw_sar_awrw_set, aw963xx_parse_dts, aw_sar_aot_set, aw_sar_update_reg_set, aw_sar_ps_get_state, aw_sar_check_init_over_irq, aw963xx_init, aw_sar_chip_init, aw_sar_i2c_read, aw96xxx_monitor_work_func, aw_sar_diff_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00111018 size=1
// signature: undefined usleep_range_state(void)
// callers: [aw_sar_i2c_write_seq, aw_sar_i2c_read, aw_sar_i2c_read_seq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00111020 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [aw_sar_i2c_write_seq, aw_sar_i2c_write, aw963xx_update_firmware, aw_sar_i2c_read_seq, aw_sar_reg_set, aw_sar_ps_notify_callback, aw963xx_irq_handle_func, aw963xx_get_signed_cap, aw_sar_mode_operation_set, aw_sar_reg_get, reset_store, aw_sar_i2c_probe, aw_sar_chip_info_get, aw_sar_prot_update_fw_get, aw963xx_rc_irqscr, aw963xx_get_cap_offset, aw_sar_load_bin_comm, aw963xx_check_chipid, aw_sar_soft_rst_set, aw_sar_awrw_set, aw_sar_aot_set, aw_sar_i2c_write_bits, aw_sar_update_reg_set, aw_sar_ps_get_state, aw_sar_check_init_over_irq, aw963xx_sar_get_firmware_info, aw963xx_sar_chip_info_get, aw_sar_i2c_read, aw96xxx_monitor_work_func, aw_sar_diff_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00111028 size=1
// signature: undefined __const_udelay(void)
// callers: [aw_sar_check_init_over_irq, aw_sar_i2c_probe, aw963xx_update_firmware, aw_sar_delay_ms]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 00111030 size=1
// signature: undefined disable_irq(void)
// callers: [aw_sar_reg_update_boot_set, aw_sar_i2c_probe, aw_sar_disable_irq, aw_sar_prot_update_fw_set, aw_sar_suspend, aw_sar_reg_update_fw_set, aw96xxx_monitor_work_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 00111038 size=1
// signature: undefined enable_irq(void)
// callers: [aw_sar_reg_update_boot_set, aw_sar_resume, aw_sar_prot_update_fw_set, aw_sar_update_work, aw_sar_enable_irq, aw_sar_reg_update_fw_set, aw96xxx_monitor_work_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_firmware @ 00111040 size=1
// signature: undefined request_firmware(void)
// callers: [aw_sar_load_bin_comm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00111048 size=1
// signature: undefined _dev_info(void)
// callers: [aw_sar_i2c_probe, aw_sar_i2c_remove, aw_sar_parse_dts_comm, aw_sar_i2c_shutdown, aw963xx_get_cap_offset, aw_sar_load_bin_comm, aw_sar_update_work, aw963xx_check_chipid, aw963xx_update_firmware, aw963xx_parse_dts, aw_sar_resume, aw_sar_ps_get_state, aw_sar_load_def_reg_bin, aw_sar_suspend, aw963xx_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00111050 size=1
// signature: undefined __kmalloc(void)
// callers: [aw_sar_load_bin_comm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00111058 size=1
// signature: undefined kfree(void)
// callers: [aw_sar_load_bin_comm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// release_firmware @ 00111060 size=1
// signature: undefined release_firmware(void)
// callers: [aw_sar_load_bin_comm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void release_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00111068 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [aw_sar_load_bin_comm, aw963xx_update_firmware]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00111070 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [aw_sar_parse_dts_comm, aw963xx_parse_dts]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 00111078 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [aw_sar_parse_dts_comm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00111080 size=1
// signature: undefined of_find_property(void)
// callers: [aw_sar_i2c_probe, aw_sar_parse_dts_comm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 00111088 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [aw_sar_parse_dts_comm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00111090 size=1
// signature: undefined msleep(void)
// callers: [aw_sar_update_reg_set, aw_sar_i2c_probe, aw_sar_soft_reset, aw_sar_chip_init, aw963xx_update_firmware, aw_sar_soft_rst_set, aw96xxx_monitor_work_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00111098 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [aw_sar_update_fw, aw_sar_i2c_probe, aw_sar_chip_info_get, aw_sar_prot_update_fw_get, aw_sar_awrw_get, aw963xx_get_cap_offset, aw_sar_update_work, aw_sar_reg_update_fw_set, aw_sar_reg_update_boot_set, cali_show, aw963xx_sar_get_firmware_info, aw963xx_sar_chip_info_get, aw_sar_load_def_reg_bin, aw_sar_prot_update_fw_set, mode_show, aw_sar_reg_get, aw_sar_diff_get, int_state_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_select_state @ 001110a0 size=1
// signature: undefined pinctrl_select_state(void)
// callers: [aw_sar_i2c_probe, aw_sar_int_output]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_select_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 001110b0 size=1
// signature: undefined init_timer_key(void)
// callers: [aw_sar_i2c_probe, aw_sar_chip_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 001110c0 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [aw_sar_resume, aw_sar_i2c_probe, aw_sar_chip_init, aw96xxx_monitor_work_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_register_driver @ 001110c8 size=1
// signature: undefined i2c_register_driver(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_register_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_del_driver @ 001110d0 size=1
// signature: undefined i2c_del_driver(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_del_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001110d8 size=1
// signature: undefined mutex_lock(void)
// callers: [aw_sar_update_reg_set, aw_sar_reg_update_boot_set, aw_sar_awrw_get, aw_sar_prot_update_fw_set, aw_sar_update_work, aw_sar_awrw_set, aw_sar_reg_update_fw_set, aw96xxx_monitor_work_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001110e0 size=1
// signature: undefined mutex_unlock(void)
// callers: [aw_sar_update_reg_set, aw_sar_reg_update_boot_set, aw_sar_awrw_get, aw_sar_prot_update_fw_set, aw_sar_update_work, aw_sar_awrw_set, aw_sar_reg_update_fw_set, aw96xxx_monitor_work_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 001110e8 size=1
// signature: undefined devm_kmalloc(void)
// callers: [aw_sar_i2c_probe, aw963xx_init, aw963xx_update_firmware, aw_sar_awrw_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_get @ 001110f0 size=1
// signature: undefined regulator_get(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_count_voltages @ 001110f8 size=1
// signature: undefined regulator_count_voltages(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_count_voltages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 00111100 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 00111108 size=1
// signature: undefined regulator_enable(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_get_voltage @ 00111110 size=1
// signature: undefined regulator_get_voltage(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_get_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00111118 size=1
// signature: undefined __mutex_init(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 00111120 size=1
// signature: undefined sysfs_create_group(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_put @ 00111128 size=1
// signature: undefined regulator_put(void)
// callers: [aw_sar_i2c_probe, aw_sar_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_reg_notifier @ 00111130 size=1
// signature: undefined power_supply_reg_notifier(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_reg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_by_name @ 00111138 size=1
// signature: undefined power_supply_get_by_name(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_property @ 00111140 size=1
// signature: undefined power_supply_get_property(void)
// callers: [aw_sar_ps_get_state, aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_get @ 00111148 size=1
// signature: undefined devm_pinctrl_get(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_lookup_state @ 00111150 size=1
// signature: undefined pinctrl_lookup_state(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_lookup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 00111158 size=1
// signature: undefined gpio_to_desc(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_to_irq @ 00111160 size=1
// signature: undefined gpiod_to_irq(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_to_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_gpio_request_one @ 00111168 size=1
// signature: undefined devm_gpio_request_one(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_gpio_request_one(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00111170 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_unreg_notifier @ 00111178 size=1
// signature: undefined power_supply_unreg_notifier(void)
// callers: [aw_sar_i2c_probe, aw_sar_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_unreg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_group @ 00111180 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [aw_sar_i2c_probe, aw_sar_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_put @ 00111188 size=1
// signature: undefined devm_pinctrl_put(void)
// callers: [aw_sar_i2c_probe, aw_sar_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 00111190 size=1
// signature: undefined regulator_disable(void)
// callers: [aw_sar_i2c_probe, aw_sar_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00111198 size=1
// signature: undefined alloc_workqueue(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_allocate_device @ 001111a0 size=1
// signature: undefined input_allocate_device(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_allocate_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_set_abs_params @ 001111a8 size=1
// signature: undefined input_set_abs_params(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_set_abs_params(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_register_device @ 001111b0 size=1
// signature: undefined input_register_device(void)
// callers: [aw_sar_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_register_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_event @ 001111b8 size=1
// signature: undefined input_event(void)
// callers: [aw_sar_i2c_probe, aw963xx_irq_handle_func, capsensor_set_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_unregister_device @ 001111c0 size=1
// signature: undefined input_unregister_device(void)
// callers: [aw_sar_input_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_unregister_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_free_device @ 001111c8 size=1
// signature: undefined input_free_device(void)
// callers: [aw_sar_input_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_free_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncmp @ 001111d0 size=1
// signature: int strncmp(char * __s1, char * __s2, size_t __n)
// callers: [reset_store, aw_sar_ps_notify_callback, aw963xx_load_reg_bin]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001111d8 size=1
// signature: undefined queue_work_on(void)
// callers: [aw_sar_ps_notify_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 001111e0 size=1
// signature: undefined devm_kfree(void)
// callers: [aw_sar_awrw_get, aw963xx_update_firmware, aw_sar_awrw_set, aw963xx_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 001111e8 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [aw_sar_reg_set, aw_sar_update_reg_set, aw_sar_soft_rst_set, aw_sar_mode_operation_set, aw_sar_awrw_set, aw_sar_aot_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 001111f0 size=1
// signature: size_t strlen(char * __s)
// callers: [aw_sar_awrw_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001111f8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [aw963xx_update_firmware, aw_sar_awrw_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 00111200 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [aw_sar_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// del_timer_sync @ 00111208 size=1
// signature: undefined del_timer_sync(void)
// callers: [aw963xx_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void del_timer_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_register @ 00111210 size=1
// signature: undefined __class_register(void)
// callers: [aw_sar_custom_flie_node_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_create_file_ns @ 00111218 size=1
// signature: undefined class_create_file_ns(void)
// callers: [aw_sar_custom_flie_node_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sensors_classdev_register @ 00111220 size=1
// signature: undefined sensors_classdev_register(void)
// callers: [aw_sar_custom_flie_node_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sensors_classdev_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sensors_classdev_unregister @ 00111228 size=1
// signature: undefined sensors_classdev_unregister(void)
// callers: [aw_sar_custom_flie_node_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sensors_classdev_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_remove_file_ns @ 00111230 size=1
// signature: undefined class_remove_file_ns(void)
// callers: [aw_sar_custom_flie_node_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_remove_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_unregister @ 00111238 size=1
// signature: undefined class_unregister(void)
// callers: [aw_sar_custom_flie_node_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bcmp @ 00111240 size=1
// signature: int bcmp(void * __s1, void * __s2, size_t __n)
// callers: [aw963xx_update_firmware]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int bcmp(void *__s1,void *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00111248 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [capsensor_set_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



