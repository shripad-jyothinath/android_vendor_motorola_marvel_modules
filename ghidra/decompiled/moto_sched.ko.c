// Decompiled by Ghidra 12.2
// Program: moto_sched.ko
// Image base: 00100000

//------------------------------------------------------------
// mdpf_proc_init @ 00103a54 size=8
// signature: undefined mdpf_proc_init(void)
// callers: []
//------------------------------------------------------------

undefined8 mdpf_proc_init(void)

{
  return 0;
}



//------------------------------------------------------------
// mdpf_proc_deinit @ 00103a60 size=4
// signature: undefined mdpf_proc_deinit(void)
// callers: []
//------------------------------------------------------------

void mdpf_proc_deinit(void)

{
  return;
}



//------------------------------------------------------------
// moto_sched_proc_init @ 00103a68 size=740
// signature: undefined moto_sched_proc_init(void)
// callers: [init_module]
//------------------------------------------------------------

undefined8 moto_sched_proc_init(void)

{
  long lVar1;
  
  d_moto_sched = proc_mkdir("moto_sched",0);
  if (d_moto_sched == 0) {
    _printk(&DAT_001107d0,"moto_sched_proc_init");
  }
  else {
    lVar1 = proc_create("enabled",0x1b6,d_moto_sched,&proc_enabled_fops);
    if (lVar1 == 0) {
      _printk(&DAT_00110719,"moto_sched_proc_init");
    }
    else {
      lVar1 = proc_create("ux_scene",0x1b6,d_moto_sched,proc_ux_scene_fops);
      if (lVar1 == 0) {
        _printk(&DAT_00110da8,"moto_sched_proc_init");
      }
      else {
        lVar1 = proc_create("ux_task",0x1b6,d_moto_sched,proc_ux_task_fops);
        if (lVar1 == 0) {
          _printk(&DAT_0011095e,"moto_sched_proc_init");
        }
        else {
          lVar1 = proc_create("boost_prio",0x1b6,d_moto_sched,proc_boost_prio_fops);
          if (lVar1 == 0) {
            _printk(&DAT_00111511,"moto_sched_proc_init");
          }
          else {
            lVar1 = proc_create("boost_task_util",0x1b6,d_moto_sched,proc_boost_task_util_fops);
            if (lVar1 == 0) {
              _printk(&DAT_001113ee,"moto_sched_proc_init");
            }
            else {
              lVar1 = proc_create("version",0x124,d_moto_sched,proc_version_fops);
              if (lVar1 == 0) {
                _printk(&DAT_00110a3f,"moto_sched_proc_init");
              }
              else {
                lVar1 = proc_create("debug",0x1b6,d_moto_sched,proc_debug_fops);
                if (lVar1 == 0) {
                  _printk(&DAT_0011109a,"moto_sched_proc_init");
                }
                else {
                  lVar1 = proc_create("boost_pid",0x1b6,d_moto_sched,proc_boost_pid_fops);
                  if (lVar1 == 0) {
                    _printk(&DAT_001116ea,"moto_sched_proc_init");
                  }
                  else {
                    lVar1 = proc_create("all_ux_tasks",0x124,d_moto_sched,all_ux_tasks_fops);
                    if (lVar1 != 0) {
                      return 0;
                    }
                    _printk(&DAT_00110d30,"moto_sched_proc_init");
                    remove_proc_entry("boost_pid",d_moto_sched);
                  }
                  remove_proc_entry("debug",d_moto_sched);
                }
                remove_proc_entry("version",d_moto_sched);
              }
              remove_proc_entry("boost_task_util",d_moto_sched);
            }
            remove_proc_entry("boost_prio",d_moto_sched);
          }
          remove_proc_entry("ux_task",d_moto_sched);
        }
        remove_proc_entry("ux_scene",d_moto_sched);
      }
      remove_proc_entry("enabled",d_moto_sched);
    }
    remove_proc_entry("moto_sched",0);
  }
  return 0xfffffffe;
}



//------------------------------------------------------------
// moto_sched_proc_deinit @ 00103d50 size=196
// signature: undefined moto_sched_proc_deinit(void)
// callers: []
//------------------------------------------------------------

void moto_sched_proc_deinit(void)

{
  remove_proc_entry("all_ux_tasks",d_moto_sched);
  remove_proc_entry("boost_pid",d_moto_sched);
  remove_proc_entry("debug",d_moto_sched);
  remove_proc_entry("version",d_moto_sched);
  remove_proc_entry("boost_task_util",d_moto_sched);
  remove_proc_entry("boost_prio",d_moto_sched);
  remove_proc_entry("ux_task",d_moto_sched);
  remove_proc_entry("ux_scene",d_moto_sched);
  remove_proc_entry("enabled",d_moto_sched);
  remove_proc_entry("moto_sched",0);
  return;
}



//------------------------------------------------------------
// proc_enabled_read @ 00103e18 size=308
// signature: undefined proc_enabled_read(void)
// callers: []
//------------------------------------------------------------

void proc_enabled_read(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char local_138 [256];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_138[0xf0] = '\0';
  local_138[0xf1] = '\0';
  local_138[0xf2] = '\0';
  local_138[0xf3] = '\0';
  local_138[0xf4] = '\0';
  local_138[0xf5] = '\0';
  local_138[0xf6] = '\0';
  local_138[0xf7] = '\0';
  local_138[0xf8] = '\0';
  local_138[0xf9] = '\0';
  local_138[0xfa] = '\0';
  local_138[0xfb] = '\0';
  local_138[0xfc] = '\0';
  local_138[0xfd] = '\0';
  local_138[0xfe] = '\0';
  local_138[0xff] = '\0';
  local_138[0xe0] = '\0';
  local_138[0xe1] = '\0';
  local_138[0xe2] = '\0';
  local_138[0xe3] = '\0';
  local_138[0xe4] = '\0';
  local_138[0xe5] = '\0';
  local_138[0xe6] = '\0';
  local_138[0xe7] = '\0';
  local_138[0xe8] = '\0';
  local_138[0xe9] = '\0';
  local_138[0xea] = '\0';
  local_138[0xeb] = '\0';
  local_138[0xec] = '\0';
  local_138[0xed] = '\0';
  local_138[0xee] = '\0';
  local_138[0xef] = '\0';
  local_138[0xd0] = '\0';
  local_138[0xd1] = '\0';
  local_138[0xd2] = '\0';
  local_138[0xd3] = '\0';
  local_138[0xd4] = '\0';
  local_138[0xd5] = '\0';
  local_138[0xd6] = '\0';
  local_138[0xd7] = '\0';
  local_138[0xd8] = '\0';
  local_138[0xd9] = '\0';
  local_138[0xda] = '\0';
  local_138[0xdb] = '\0';
  local_138[0xdc] = '\0';
  local_138[0xdd] = '\0';
  local_138[0xde] = '\0';
  local_138[0xdf] = '\0';
  local_138[0xc0] = '\0';
  local_138[0xc1] = '\0';
  local_138[0xc2] = '\0';
  local_138[0xc3] = '\0';
  local_138[0xc4] = '\0';
  local_138[0xc5] = '\0';
  local_138[0xc6] = '\0';
  local_138[199] = '\0';
  local_138[200] = '\0';
  local_138[0xc9] = '\0';
  local_138[0xca] = '\0';
  local_138[0xcb] = '\0';
  local_138[0xcc] = '\0';
  local_138[0xcd] = '\0';
  local_138[0xce] = '\0';
  local_138[0xcf] = '\0';
  local_138[0xb0] = '\0';
  local_138[0xb1] = '\0';
  local_138[0xb2] = '\0';
  local_138[0xb3] = '\0';
  local_138[0xb4] = '\0';
  local_138[0xb5] = '\0';
  local_138[0xb6] = '\0';
  local_138[0xb7] = '\0';
  local_138[0xb8] = '\0';
  local_138[0xb9] = '\0';
  local_138[0xba] = '\0';
  local_138[0xbb] = '\0';
  local_138[0xbc] = '\0';
  local_138[0xbd] = '\0';
  local_138[0xbe] = '\0';
  local_138[0xbf] = '\0';
  local_138[0xa0] = '\0';
  local_138[0xa1] = '\0';
  local_138[0xa2] = '\0';
  local_138[0xa3] = '\0';
  local_138[0xa4] = '\0';
  local_138[0xa5] = '\0';
  local_138[0xa6] = '\0';
  local_138[0xa7] = '\0';
  local_138[0xa8] = '\0';
  local_138[0xa9] = '\0';
  local_138[0xaa] = '\0';
  local_138[0xab] = '\0';
  local_138[0xac] = '\0';
  local_138[0xad] = '\0';
  local_138[0xae] = '\0';
  local_138[0xaf] = '\0';
  local_138[0x90] = '\0';
  local_138[0x91] = '\0';
  local_138[0x92] = '\0';
  local_138[0x93] = '\0';
  local_138[0x94] = '\0';
  local_138[0x95] = '\0';
  local_138[0x96] = '\0';
  local_138[0x97] = '\0';
  local_138[0x98] = '\0';
  local_138[0x99] = '\0';
  local_138[0x9a] = '\0';
  local_138[0x9b] = '\0';
  local_138[0x9c] = '\0';
  local_138[0x9d] = '\0';
  local_138[0x9e] = '\0';
  local_138[0x9f] = '\0';
  local_138[0x80] = '\0';
  local_138[0x81] = '\0';
  local_138[0x82] = '\0';
  local_138[0x83] = '\0';
  local_138[0x84] = '\0';
  local_138[0x85] = '\0';
  local_138[0x86] = '\0';
  local_138[0x87] = '\0';
  local_138[0x88] = '\0';
  local_138[0x89] = '\0';
  local_138[0x8a] = '\0';
  local_138[0x8b] = '\0';
  local_138[0x8c] = '\0';
  local_138[0x8d] = '\0';
  local_138[0x8e] = '\0';
  local_138[0x8f] = '\0';
  local_138[0x70] = '\0';
  local_138[0x71] = '\0';
  local_138[0x72] = '\0';
  local_138[0x73] = '\0';
  local_138[0x74] = '\0';
  local_138[0x75] = '\0';
  local_138[0x76] = '\0';
  local_138[0x77] = '\0';
  local_138[0x78] = '\0';
  local_138[0x79] = '\0';
  local_138[0x7a] = '\0';
  local_138[0x7b] = '\0';
  local_138[0x7c] = '\0';
  local_138[0x7d] = '\0';
  local_138[0x7e] = '\0';
  local_138[0x7f] = '\0';
  local_138[0x60] = '\0';
  local_138[0x61] = '\0';
  local_138[0x62] = '\0';
  local_138[99] = '\0';
  local_138[100] = '\0';
  local_138[0x65] = '\0';
  local_138[0x66] = '\0';
  local_138[0x67] = '\0';
  local_138[0x68] = '\0';
  local_138[0x69] = '\0';
  local_138[0x6a] = '\0';
  local_138[0x6b] = '\0';
  local_138[0x6c] = '\0';
  local_138[0x6d] = '\0';
  local_138[0x6e] = '\0';
  local_138[0x6f] = '\0';
  local_138[0x50] = '\0';
  local_138[0x51] = '\0';
  local_138[0x52] = '\0';
  local_138[0x53] = '\0';
  local_138[0x54] = '\0';
  local_138[0x55] = '\0';
  local_138[0x56] = '\0';
  local_138[0x57] = '\0';
  local_138[0x58] = '\0';
  local_138[0x59] = '\0';
  local_138[0x5a] = '\0';
  local_138[0x5b] = '\0';
  local_138[0x5c] = '\0';
  local_138[0x5d] = '\0';
  local_138[0x5e] = '\0';
  local_138[0x5f] = '\0';
  local_138[0x40] = '\0';
  local_138[0x41] = '\0';
  local_138[0x42] = '\0';
  local_138[0x43] = '\0';
  local_138[0x44] = '\0';
  local_138[0x45] = '\0';
  local_138[0x46] = '\0';
  local_138[0x47] = '\0';
  local_138[0x48] = '\0';
  local_138[0x49] = '\0';
  local_138[0x4a] = '\0';
  local_138[0x4b] = '\0';
  local_138[0x4c] = '\0';
  local_138[0x4d] = '\0';
  local_138[0x4e] = '\0';
  local_138[0x4f] = '\0';
  local_138[0x30] = '\0';
  local_138[0x31] = '\0';
  local_138[0x32] = '\0';
  local_138[0x33] = '\0';
  local_138[0x34] = '\0';
  local_138[0x35] = '\0';
  local_138[0x36] = '\0';
  local_138[0x37] = '\0';
  local_138[0x38] = '\0';
  local_138[0x39] = '\0';
  local_138[0x3a] = '\0';
  local_138[0x3b] = '\0';
  local_138[0x3c] = '\0';
  local_138[0x3d] = '\0';
  local_138[0x3e] = '\0';
  local_138[0x3f] = '\0';
  local_138[0x20] = '\0';
  local_138[0x21] = '\0';
  local_138[0x22] = '\0';
  local_138[0x23] = '\0';
  local_138[0x24] = '\0';
  local_138[0x25] = '\0';
  local_138[0x26] = '\0';
  local_138[0x27] = '\0';
  local_138[0x28] = '\0';
  local_138[0x29] = '\0';
  local_138[0x2a] = '\0';
  local_138[0x2b] = '\0';
  local_138[0x2c] = '\0';
  local_138[0x2d] = '\0';
  local_138[0x2e] = '\0';
  local_138[0x2f] = '\0';
  local_138[0x10] = '\0';
  local_138[0x11] = '\0';
  local_138[0x12] = '\0';
  local_138[0x13] = '\0';
  local_138[0x14] = '\0';
  local_138[0x15] = '\0';
  local_138[0x16] = '\0';
  local_138[0x17] = '\0';
  local_138[0x18] = '\0';
  local_138[0x19] = '\0';
  local_138[0x1a] = '\0';
  local_138[0x1b] = '\0';
  local_138[0x1c] = '\0';
  local_138[0x1d] = '\0';
  local_138[0x1e] = '\0';
  local_138[0x1f] = '\0';
  local_138[0] = '\0';
  local_138[1] = '\0';
  local_138[2] = '\0';
  local_138[3] = '\0';
  local_138[4] = '\0';
  local_138[5] = '\0';
  local_138[6] = '\0';
  local_138[7] = '\0';
  local_138[8] = '\0';
  local_138[9] = '\0';
  local_138[10] = '\0';
  local_138[0xb] = '\0';
  local_138[0xc] = '\0';
  local_138[0xd] = '\0';
  local_138[0xe] = '\0';
  local_138[0xf] = '\0';
  iVar2 = snprintf(local_138,0x100,
                   "0x%x base=%d interaction=%d lock=%d binder=%d audio=%d camera=%d kswapd=%d boost=%d kernel=%d mdpf=%d kworker=%d irqwth=%d percpu_rwsem=%d bset_binder=%d\n"
                   ,moto_sched_enabled,moto_sched_enabled & 1,moto_sched_enabled >> 1 & 1,
                   moto_sched_enabled >> 2 & 1,moto_sched_enabled >> 3 & 1,
                   moto_sched_enabled >> 4 & 1,moto_sched_enabled >> 5 & 1,
                   moto_sched_enabled >> 6 & 1,moto_sched_enabled >> 7 & 1,
                   moto_sched_enabled >> 8 & 1,moto_sched_enabled >> 9 & 1,
                   moto_sched_enabled >> 10 & 1,moto_sched_enabled >> 0xb & 1,
                   moto_sched_enabled >> 0xc & 1,moto_sched_enabled >> 0xd & 1);
  simple_read_from_buffer(param_2,param_3,param_4,local_138,(long)iVar2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// proc_enabled_write @ 00103f50 size=440
// signature: undefined proc_enabled_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong proc_enabled_write(undefined8 param_1,ulong param_2,ulong param_3)

{
  undefined **ppuVar1;
  long lVar2;
  ulong uVar3;
  int iVar4;
  ulong uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  ulong uVar8;
  int local_3c;
  undefined5 local_38;
  undefined3 uStack_33;
  undefined5 uStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  if (0xb < param_3) {
    param_3 = 0xc;
  }
  local_28 = *(long *)(lVar2 + 0x638);
  local_3c = 0;
  local_38 = 0;
  uStack_33 = 0;
  uStack_30 = 0;
  __check_object_size(&local_38,param_3,0);
  puVar7 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
     (uVar8 = param_2, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
    uVar8 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar5 = param_3;
  if (uVar8 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar8 = daif;
      if ((uVar8 & 0x80) == 0) {
        uVar5 = daif;
        daif = uVar5 | 0xc0;
      }
      puVar7 = (undefined8 *)puVar7[1];
      uVar5 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar7;
      InstructionSynchronizationBarrier();
      daif = uVar8;
    }
    uVar5 = __arch_copy_from_user(puVar7,&local_38,param_2 & 0xff7fffffffffffff,param_3);
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
  if (uVar5 == 0) {
    *(undefined1 *)((long)&local_38 + param_3) = 0;
    uVar6 = strim(&local_38);
    iVar4 = kstrtoint(uVar6,0x10,&local_3c);
    if (iVar4 == 0) {
      moto_sched_enabled = local_3c;
      set_moto_sched_enabled();
      ppuVar1 = (undefined **)0x0;
      if (moto_sched_enabled != 0) {
        ppuVar1 = &sched_ops;
      }
      set_moto_sched_ops(ppuVar1);
    }
    else {
      param_3 = (ulong)iVar4;
    }
  }
  else {
    param_3 = 0xfffffffffffffff2;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// proc_ux_scene_read @ 00104124 size=156
// signature: undefined proc_ux_scene_read(void)
// callers: []
//------------------------------------------------------------

void proc_ux_scene_read(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char acStack_48 [16];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  acStack_48[8] = '\0';
  acStack_48[9] = '\0';
  acStack_48[10] = '\0';
  acStack_48[0xb] = '\0';
  acStack_48[0xc] = '\0';
  acStack_48[0] = '\0';
  acStack_48[1] = '\0';
  acStack_48[2] = '\0';
  acStack_48[3] = '\0';
  acStack_48[4] = '\0';
  acStack_48[5] = '\0';
  acStack_48[6] = '\0';
  acStack_48[7] = '\0';
  iVar2 = snprintf(acStack_48,0xd,"%d\n",(ulong)moto_sched_scene);
  simple_read_from_buffer(param_2,param_3,param_4,acStack_48,(long)iVar2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// proc_ux_scene_write @ 001041c4 size=436
// signature: undefined proc_ux_scene_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong proc_ux_scene_write(undefined8 param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  ulong uVar7;
  undefined4 local_3c;
  undefined5 local_38;
  undefined3 uStack_33;
  undefined5 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  if (0xb < param_3) {
    param_3 = 0xc;
  }
  local_28 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  local_38 = 0;
  uStack_33 = 0;
  uStack_30 = 0;
  __check_object_size(&local_38,param_3,0);
  puVar6 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
     (uVar7 = param_2, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
    uVar7 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar4 = param_3;
  if (uVar7 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar4 = daif;
        daif = uVar4 | 0xc0;
      }
      puVar6 = (undefined8 *)puVar6[1];
      uVar4 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar6;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
    uVar4 = __arch_copy_from_user(puVar6,&local_38,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
  }
  if (uVar4 == 0) {
    *(undefined1 *)((long)&local_38 + param_3) = 0;
    uVar5 = strim(&local_38);
    iVar3 = kstrtoint(uVar5,10,&local_3c);
    if (iVar3 == 0) {
      mutex_lock(proc_ux_scene_write_ux_scene_mutex);
      moto_sched_scene = local_3c;
      mutex_unlock(proc_ux_scene_write_ux_scene_mutex);
    }
    else {
      param_3 = (ulong)iVar3;
    }
  }
  else {
    param_3 = 0xfffffffffffffff2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// proc_ux_task_read @ 00104394 size=496
// signature: undefined proc_ux_task_read(void)
// callers: []
//------------------------------------------------------------

void proc_ux_task_read(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  uint uVar7;
  ulong uVar8;
  long lVar9;
  char local_158 [8];
  undefined7 uStack_150;
  undefined4 local_149;
  undefined5 uStack_145;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
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
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
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
  local_c8 = 0;
  uStack_c0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_108 = 0;
  uStack_100 = 0;
  local_118 = 0;
  uStack_110 = 0;
  local_128 = 0;
  uStack_120 = 0;
  local_138 = 0;
  uStack_130 = 0;
  uStack_145 = 0;
  uStack_140 = 0;
  local_158[0] = '\0';
  local_158[1] = '\0';
  local_158[2] = '\0';
  local_158[3] = '\0';
  local_158[4] = '\0';
  local_158[5] = '\0';
  local_158[6] = '\0';
  local_158[7] = '\0';
  uStack_150 = 0;
  local_149 = 0;
  lVar5 = find_task_by_vpid(global_task_pid_to_read);
  if (lVar5 == 0) {
    lVar9 = 0x12;
    local_158[0] = s_Can_not_find_task_00110818[0];
    local_158[1] = s_Can_not_find_task_00110818[1];
    local_158[2] = s_Can_not_find_task_00110818[2];
    local_158[3] = s_Can_not_find_task_00110818[3];
    local_158[4] = s_Can_not_find_task_00110818[4];
    local_158[5] = s_Can_not_find_task_00110818[5];
    local_158[6] = s_Can_not_find_task_00110818[6];
    local_158[7] = s_Can_not_find_task_00110818[7];
    uStack_150 = s_Can_not_find_task_00110818._8_7_;
    local_149 = CONCAT31(0xa6b,s_Can_not_find_task_00110818[0xf]);
    goto LAB_00104540;
  }
  puVar1 = (uint *)(lVar5 + 0x40);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar7 = *puVar1;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = uVar7 + 1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  if (uVar7 == 0) {
    uVar6 = 2;
LAB_00104504:
    refcount_warn_saturate(puVar1,uVar6);
    iVar4 = *(int *)(lVar5 + 0x630);
    if (iVar4 == 0) goto LAB_00104498;
LAB_00104448:
    uVar8 = *(ulong *)(lVar5 + 0xdd8);
    if ((uVar8 == 0) || (0xfffffffffffff000 < uVar8)) {
      _printk(&DAT_00110a81,iVar4);
      iVar4 = *(int *)(lVar5 + 0x630);
      goto LAB_00104498;
    }
    uVar7 = *(uint *)(uVar8 + 0x2c);
  }
  else {
    if ((int)(uVar7 + 1 | uVar7) < 0) {
      uVar6 = 1;
      goto LAB_00104504;
    }
    iVar4 = *(int *)(lVar5 + 0x630);
    if (iVar4 != 0) goto LAB_00104448;
LAB_00104498:
    uVar7 = 0;
  }
  iVar4 = snprintf(local_158,0x100,"comm=%s pid=%d tgid=%d ux_type=0x%x\n",(char *)(lVar5 + 0x848),
                   iVar4,*(int *)(lVar5 + 0x634),uVar7);
  lVar9 = (long)iVar4;
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar7 = *puVar1;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = uVar7 - 1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  if (uVar7 == 1) {
    DataMemoryBarrier(2,1);
    __put_task_struct(lVar5);
  }
  else if ((int)uVar7 < 1) {
    refcount_warn_saturate(puVar1,3);
  }
LAB_00104540:
  simple_read_from_buffer(param_2,param_3,param_4,local_158,lVar9);
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// proc_ux_task_write @ 001045a4 size=856
// signature: undefined proc_ux_task_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x001047b0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong proc_ux_task_write(undefined8 param_1,ulong param_2,ulong param_3)

{
  bool bVar1;
  long lVar2;
  ulong uVar3;
  byte bVar4;
  bool bVar5;
  byte bVar6;
  int iVar7;
  ulong uVar8;
  char *pcVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  ulong uVar12;
  undefined8 local_e8;
  char *local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined1 auStack_c8 [7];
  undefined4 local_c1;
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
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_e8 = 0;
  local_d0 = 0x3000;
  auStack_c8 = (undefined1  [7])0x300000;
  local_c1 = 0;
  if (0x7e < param_3) {
    param_3 = 0x7f;
  }
  local_b8 = 0;
  uStack_b0 = 0;
  local_e0 = (char *)0x0;
  local_d8 = 0x30;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  __check_object_size(&local_b8,param_3,0);
  puVar11 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar11 + 0x46) >> 5 & 1) != 0) ||
     (uVar12 = param_2, ((uint)*puVar11 >> 0x1a & 1) != 0)) {
    uVar12 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar8 = param_3;
  if (uVar12 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar12 = daif;
      if ((uVar12 & 0x80) == 0) {
        uVar8 = daif;
        daif = uVar8 | 0xc0;
      }
      puVar11 = (undefined8 *)puVar11[1];
      uVar8 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar11 & 0xffff000000000000 | uVar8 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar11;
      InstructionSynchronizationBarrier();
      daif = uVar12;
    }
    uVar8 = __arch_copy_from_user(puVar11,&local_b8,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar12 = daif;
      if ((uVar12 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar12;
    }
  }
  if (uVar8 == 0) {
    *(undefined1 *)((long)&local_b8 + param_3) = 0;
    local_e0 = (char *)strim(&local_b8);
    pcVar9 = strsep(&local_e0," ");
    if ((pcVar9 != (char *)0x0) && (*pcVar9 != '\0')) {
      strlcpy(&local_d8,pcVar9,9);
      pcVar9 = strsep(&local_e0," ");
      if ((pcVar9 != (char *)0x0) && (*pcVar9 != '\0')) {
        strlcpy((long)&local_d0 + 1,pcVar9,9);
        pcVar9 = strsep(&local_e0," ");
        if ((pcVar9 == (char *)0x0) || (*pcVar9 == '\0')) {
          bVar6 = 0;
          bVar4 = 1;
        }
        else {
          strlcpy(auStack_c8 + 2,pcVar9,9);
          strsep(&local_e0," ");
          bVar4 = 0;
          bVar6 = 1;
        }
        uVar10 = strim((long)&local_d0 + 1);
        iVar7 = kstrtoint(uVar10,10,(long)&local_e8 + 4);
        if (((iVar7 == 0) && (0 < local_e8._4_4_)) && (local_e8._4_4_ < 0x8001)) {
          bVar1 = (bool)(bVar4 ^ 1);
          if ((char)local_d8 != 'r') {
            bVar1 = true;
          }
          if (!bVar1) {
            global_task_pid_to_read = local_e8._4_4_;
            goto LAB_001048b0;
          }
          bVar1 = (bool)(bVar6 ^ 1);
          bVar5 = bVar1;
          if ((char)local_d8 != 'w') {
            bVar5 = true;
          }
          if (bVar5) {
            if ((char)local_d8 != 'c') {
              bVar1 = true;
            }
            if (bVar1) goto LAB_001047c4;
            uVar10 = strim(auStack_c8 + 2);
            iVar7 = kstrtoint(uVar10,10,&local_e8);
            if ((iVar7 == 0) && (-1 < (int)local_e8)) {
              task_ux_type_clear(local_e8._4_4_);
              goto LAB_001048b0;
            }
          }
          else {
            uVar10 = strim(auStack_c8 + 2);
            iVar7 = kstrtoint(uVar10,10,&local_e8);
            if ((iVar7 == 0) && (0 < (int)local_e8)) {
              task_ux_type_set(local_e8._4_4_);
              goto LAB_001048b0;
            }
          }
        }
        param_3 = (ulong)iVar7;
        goto LAB_001048b0;
      }
    }
  }
LAB_001047c4:
  param_3 = 0xfffffffffffffff2;
LAB_001048b0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// proc_boost_prio_read @ 00104918 size=156
// signature: undefined proc_boost_prio_read(void)
// callers: []
//------------------------------------------------------------

void proc_boost_prio_read
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char acStack_48 [16];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  acStack_48[8] = '\0';
  acStack_48[9] = '\0';
  acStack_48[10] = '\0';
  acStack_48[0xb] = '\0';
  acStack_48[0xc] = '\0';
  acStack_48[0] = '\0';
  acStack_48[1] = '\0';
  acStack_48[2] = '\0';
  acStack_48[3] = '\0';
  acStack_48[4] = '\0';
  acStack_48[5] = '\0';
  acStack_48[6] = '\0';
  acStack_48[7] = '\0';
  iVar2 = snprintf(acStack_48,0xd,"%d\n",(ulong)moto_boost_prio);
  simple_read_from_buffer(param_2,param_3,param_4,acStack_48,(long)iVar2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// proc_boost_prio_write @ 001049b8 size=436
// signature: undefined proc_boost_prio_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong proc_boost_prio_write(undefined8 param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  ulong uVar7;
  undefined4 local_3c;
  undefined5 local_38;
  undefined3 uStack_33;
  undefined5 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  if (0xb < param_3) {
    param_3 = 0xc;
  }
  local_28 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  local_38 = 0;
  uStack_33 = 0;
  uStack_30 = 0;
  __check_object_size(&local_38,param_3,0);
  puVar6 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
     (uVar7 = param_2, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
    uVar7 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar4 = param_3;
  if (uVar7 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar4 = daif;
        daif = uVar4 | 0xc0;
      }
      puVar6 = (undefined8 *)puVar6[1];
      uVar4 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar6;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
    uVar4 = __arch_copy_from_user(puVar6,&local_38,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
  }
  if (uVar4 == 0) {
    *(undefined1 *)((long)&local_38 + param_3) = 0;
    uVar5 = strim(&local_38);
    iVar3 = kstrtoint(uVar5,10,&local_3c);
    if (iVar3 == 0) {
      mutex_lock(proc_boost_prio_write_boost_prio_mutex);
      moto_boost_prio = local_3c;
      mutex_unlock(proc_boost_prio_write_boost_prio_mutex);
    }
    else {
      param_3 = (ulong)iVar3;
    }
  }
  else {
    param_3 = 0xfffffffffffffff2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// proc_boost_task_util_read @ 00104b88 size=156
// signature: undefined proc_boost_task_util_read(void)
// callers: []
//------------------------------------------------------------

void proc_boost_task_util_read
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char acStack_48 [16];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  acStack_48[8] = '\0';
  acStack_48[9] = '\0';
  acStack_48[10] = '\0';
  acStack_48[0xb] = '\0';
  acStack_48[0xc] = '\0';
  acStack_48[0] = '\0';
  acStack_48[1] = '\0';
  acStack_48[2] = '\0';
  acStack_48[3] = '\0';
  acStack_48[4] = '\0';
  acStack_48[5] = '\0';
  acStack_48[6] = '\0';
  acStack_48[7] = '\0';
  iVar2 = snprintf(acStack_48,0xd,"%d\n",(ulong)moto_boost_task_util);
  simple_read_from_buffer(param_2,param_3,param_4,acStack_48,(long)iVar2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// proc_boost_task_util_write @ 00104c28 size=436
// signature: undefined proc_boost_task_util_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong proc_boost_task_util_write(undefined8 param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  ulong uVar7;
  undefined4 local_3c;
  undefined5 local_38;
  undefined3 uStack_33;
  undefined5 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  if (0xb < param_3) {
    param_3 = 0xc;
  }
  local_28 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  local_38 = 0;
  uStack_33 = 0;
  uStack_30 = 0;
  __check_object_size(&local_38,param_3,0);
  puVar6 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
     (uVar7 = param_2, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
    uVar7 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar4 = param_3;
  if (uVar7 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar4 = daif;
        daif = uVar4 | 0xc0;
      }
      puVar6 = (undefined8 *)puVar6[1];
      uVar4 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar6;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
    uVar4 = __arch_copy_from_user(puVar6,&local_38,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
  }
  if (uVar4 == 0) {
    *(undefined1 *)((long)&local_38 + param_3) = 0;
    uVar5 = strim(&local_38);
    iVar3 = kstrtoint(uVar5,10,&local_3c);
    if (iVar3 == 0) {
      mutex_lock(proc_boost_task_util_write_boost_task_util_mutex);
      moto_boost_task_util = local_3c;
      mutex_unlock(proc_boost_task_util_write_boost_task_util_mutex);
    }
    else {
      param_3 = (ulong)iVar3;
    }
  }
  else {
    param_3 = 0xfffffffffffffff2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// proc_version_read @ 00104df8 size=156
// signature: undefined proc_version_read(void)
// callers: []
//------------------------------------------------------------

void proc_version_read(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char acStack_48 [16];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  acStack_48[8] = '\0';
  acStack_48[9] = '\0';
  acStack_48[10] = '\0';
  acStack_48[0xb] = '\0';
  acStack_48[0xc] = '\0';
  acStack_48[0] = '\0';
  acStack_48[1] = '\0';
  acStack_48[2] = '\0';
  acStack_48[3] = '\0';
  acStack_48[4] = '\0';
  acStack_48[5] = '\0';
  acStack_48[6] = '\0';
  acStack_48[7] = '\0';
  iVar2 = snprintf(acStack_48,0xd,"%d\n",0x3d4e1);
  simple_read_from_buffer(param_2,param_3,param_4,acStack_48,(long)iVar2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// proc_debug_read @ 00104e98 size=220
// signature: undefined proc_debug_read(void)
// callers: []
//------------------------------------------------------------

void proc_debug_read(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char local_b8 [128];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_b8[0x70] = '\0';
  local_b8[0x71] = '\0';
  local_b8[0x72] = '\0';
  local_b8[0x73] = '\0';
  local_b8[0x74] = '\0';
  local_b8[0x75] = '\0';
  local_b8[0x76] = '\0';
  local_b8[0x77] = '\0';
  local_b8[0x78] = '\0';
  local_b8[0x79] = '\0';
  local_b8[0x7a] = '\0';
  local_b8[0x7b] = '\0';
  local_b8[0x7c] = '\0';
  local_b8[0x7d] = '\0';
  local_b8[0x7e] = '\0';
  local_b8[0x7f] = '\0';
  local_b8[0x60] = '\0';
  local_b8[0x61] = '\0';
  local_b8[0x62] = '\0';
  local_b8[99] = '\0';
  local_b8[100] = '\0';
  local_b8[0x65] = '\0';
  local_b8[0x66] = '\0';
  local_b8[0x67] = '\0';
  local_b8[0x68] = '\0';
  local_b8[0x69] = '\0';
  local_b8[0x6a] = '\0';
  local_b8[0x6b] = '\0';
  local_b8[0x6c] = '\0';
  local_b8[0x6d] = '\0';
  local_b8[0x6e] = '\0';
  local_b8[0x6f] = '\0';
  local_b8[0x50] = '\0';
  local_b8[0x51] = '\0';
  local_b8[0x52] = '\0';
  local_b8[0x53] = '\0';
  local_b8[0x54] = '\0';
  local_b8[0x55] = '\0';
  local_b8[0x56] = '\0';
  local_b8[0x57] = '\0';
  local_b8[0x58] = '\0';
  local_b8[0x59] = '\0';
  local_b8[0x5a] = '\0';
  local_b8[0x5b] = '\0';
  local_b8[0x5c] = '\0';
  local_b8[0x5d] = '\0';
  local_b8[0x5e] = '\0';
  local_b8[0x5f] = '\0';
  local_b8[0x40] = '\0';
  local_b8[0x41] = '\0';
  local_b8[0x42] = '\0';
  local_b8[0x43] = '\0';
  local_b8[0x44] = '\0';
  local_b8[0x45] = '\0';
  local_b8[0x46] = '\0';
  local_b8[0x47] = '\0';
  local_b8[0x48] = '\0';
  local_b8[0x49] = '\0';
  local_b8[0x4a] = '\0';
  local_b8[0x4b] = '\0';
  local_b8[0x4c] = '\0';
  local_b8[0x4d] = '\0';
  local_b8[0x4e] = '\0';
  local_b8[0x4f] = '\0';
  local_b8[0x30] = '\0';
  local_b8[0x31] = '\0';
  local_b8[0x32] = '\0';
  local_b8[0x33] = '\0';
  local_b8[0x34] = '\0';
  local_b8[0x35] = '\0';
  local_b8[0x36] = '\0';
  local_b8[0x37] = '\0';
  local_b8[0x38] = '\0';
  local_b8[0x39] = '\0';
  local_b8[0x3a] = '\0';
  local_b8[0x3b] = '\0';
  local_b8[0x3c] = '\0';
  local_b8[0x3d] = '\0';
  local_b8[0x3e] = '\0';
  local_b8[0x3f] = '\0';
  local_b8[0x20] = '\0';
  local_b8[0x21] = '\0';
  local_b8[0x22] = '\0';
  local_b8[0x23] = '\0';
  local_b8[0x24] = '\0';
  local_b8[0x25] = '\0';
  local_b8[0x26] = '\0';
  local_b8[0x27] = '\0';
  local_b8[0x28] = '\0';
  local_b8[0x29] = '\0';
  local_b8[0x2a] = '\0';
  local_b8[0x2b] = '\0';
  local_b8[0x2c] = '\0';
  local_b8[0x2d] = '\0';
  local_b8[0x2e] = '\0';
  local_b8[0x2f] = '\0';
  local_b8[0x10] = '\0';
  local_b8[0x11] = '\0';
  local_b8[0x12] = '\0';
  local_b8[0x13] = '\0';
  local_b8[0x14] = '\0';
  local_b8[0x15] = '\0';
  local_b8[0x16] = '\0';
  local_b8[0x17] = '\0';
  local_b8[0x18] = '\0';
  local_b8[0x19] = '\0';
  local_b8[0x1a] = '\0';
  local_b8[0x1b] = '\0';
  local_b8[0x1c] = '\0';
  local_b8[0x1d] = '\0';
  local_b8[0x1e] = '\0';
  local_b8[0x1f] = '\0';
  local_b8[0] = '\0';
  local_b8[1] = '\0';
  local_b8[2] = '\0';
  local_b8[3] = '\0';
  local_b8[4] = '\0';
  local_b8[5] = '\0';
  local_b8[6] = '\0';
  local_b8[7] = '\0';
  local_b8[8] = '\0';
  local_b8[9] = '\0';
  local_b8[10] = '\0';
  local_b8[0xb] = '\0';
  local_b8[0xc] = '\0';
  local_b8[0xd] = '\0';
  local_b8[0xe] = '\0';
  local_b8[0xf] = '\0';
  snprintf(local_b8,0x80,"%d\n",(ulong)moto_sched_debug);
  iVar2 = snprintf(local_b8,0x80,"0x%x base=%d lock=%d binder=%d mdpf=%d \n",moto_sched_debug,
                   moto_sched_debug & 1,moto_sched_debug >> 1 & 1,moto_sched_debug >> 2 & 1,
                   moto_sched_debug >> 3 & 1);
  simple_read_from_buffer(param_2,param_3,param_4,local_b8,(long)iVar2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// proc_debug_write @ 00104f78 size=412
// signature: undefined proc_debug_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong proc_debug_write(undefined8 param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  ulong uVar7;
  undefined4 local_3c;
  undefined5 local_38;
  undefined3 uStack_33;
  undefined5 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  if (0xb < param_3) {
    param_3 = 0xc;
  }
  local_28 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  local_38 = 0;
  uStack_33 = 0;
  uStack_30 = 0;
  __check_object_size(&local_38,param_3,0);
  puVar6 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
     (uVar7 = param_2, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
    uVar7 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar4 = param_3;
  if (uVar7 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar4 = daif;
        daif = uVar4 | 0xc0;
      }
      puVar6 = (undefined8 *)puVar6[1];
      uVar4 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar6;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
    uVar4 = __arch_copy_from_user(puVar6,&local_38,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
  }
  if (uVar4 == 0) {
    *(undefined1 *)((long)&local_38 + param_3) = 0;
    uVar5 = strim(&local_38);
    iVar3 = kstrtoint(uVar5,0x10,&local_3c);
    if (iVar3 == 0) {
      moto_sched_debug = local_3c;
    }
    else {
      param_3 = (ulong)iVar3;
    }
  }
  else {
    param_3 = 0xfffffffffffffff2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// proc_boost_pid_read @ 00105130 size=156
// signature: undefined proc_boost_pid_read(void)
// callers: []
//------------------------------------------------------------

void proc_boost_pid_read(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  long lVar1;
  int iVar2;
  char acStack_48 [16];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  acStack_48[8] = '\0';
  acStack_48[9] = '\0';
  acStack_48[10] = '\0';
  acStack_48[0xb] = '\0';
  acStack_48[0xc] = '\0';
  acStack_48[0] = '\0';
  acStack_48[1] = '\0';
  acStack_48[2] = '\0';
  acStack_48[3] = '\0';
  acStack_48[4] = '\0';
  acStack_48[5] = '\0';
  acStack_48[6] = '\0';
  acStack_48[7] = '\0';
  iVar2 = snprintf(acStack_48,0xd,"%d\n",(ulong)global_boost_pid);
  simple_read_from_buffer(param_2,param_3,param_4,acStack_48,(long)iVar2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// proc_boost_pid_write @ 001051d0 size=412
// signature: undefined proc_boost_pid_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong proc_boost_pid_write(undefined8 param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  ulong uVar7;
  undefined4 local_3c;
  undefined5 local_38;
  undefined3 uStack_33;
  undefined5 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  if (0xb < param_3) {
    param_3 = 0xc;
  }
  local_28 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  local_38 = 0;
  uStack_33 = 0;
  uStack_30 = 0;
  __check_object_size(&local_38,param_3,0);
  puVar6 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
     (uVar7 = param_2, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
    uVar7 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar4 = param_3;
  if (uVar7 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar4 = daif;
        daif = uVar4 | 0xc0;
      }
      puVar6 = (undefined8 *)puVar6[1];
      uVar4 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar6;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
    uVar4 = __arch_copy_from_user(puVar6,&local_38,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
  }
  if (uVar4 == 0) {
    *(undefined1 *)((long)&local_38 + param_3) = 0;
    uVar5 = strim(&local_38);
    iVar3 = kstrtoint(uVar5,10,&local_3c);
    if (iVar3 == 0) {
      global_boost_pid = local_3c;
    }
    else {
      param_3 = (ulong)iVar3;
    }
  }
  else {
    param_3 = 0xfffffffffffffff2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// all_ux_tasks_read @ 00105388 size=380
// signature: undefined all_ux_tasks_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void all_ux_tasks_read(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  int iVar3;
  undefined8 *puVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  char local_88 [32];
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  local_88[0x10] = '\0';
  local_88[0x11] = '\0';
  local_88[0x12] = '\0';
  local_88[0x13] = '\0';
  local_88[0x14] = '\0';
  local_88[0x15] = '\0';
  local_88[0x16] = '\0';
  local_88[0x17] = '\0';
  local_88[0x18] = '\0';
  local_88[0x19] = '\0';
  local_88[0x1a] = '\0';
  local_88[0x1b] = '\0';
  local_88[0x1c] = '\0';
  local_88[0x1d] = '\0';
  local_88[0x1e] = '\0';
  local_88[0x1f] = '\0';
  local_88[0] = '\0';
  local_88[1] = '\0';
  local_88[2] = '\0';
  local_88[3] = '\0';
  local_88[4] = '\0';
  local_88[5] = '\0';
  local_88[6] = '\0';
  local_88[7] = '\0';
  local_88[8] = '\0';
  local_88[9] = '\0';
  local_88[10] = '\0';
  local_88[0xb] = '\0';
  local_88[0xc] = '\0';
  local_88[0xd] = '\0';
  local_88[0xe] = '\0';
  local_88[0xf] = '\0';
  __rcu_read_lock();
  if (_DAT_0011a610 == (undefined8 *)&DAT_0011a610) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
    puVar6 = _DAT_0011a610;
    do {
      puVar4 = (undefined8 *)(puVar6[0x68] + 0x10);
      for (puVar7 = (undefined8 *)*puVar4; puVar7 != puVar4; puVar7 = (undefined8 *)*puVar7) {
        if ((puVar7 != (undefined8 *)0x6f0) && (iVar1 = *(int *)(puVar7 + -0x18), iVar1 != 0)) {
          uVar5 = puVar7[0xdd];
          if ((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) {
            _printk(&DAT_00110a81,iVar1);
          }
          else if (0 < *(int *)(uVar5 + 0x2c)) {
            _printk(&DAT_00110afe,*(undefined4 *)((long)puVar7 + -0xbc),iVar1,puVar7 + 0x2b,
                    *(undefined4 *)((long)puVar7 + -0x66c),*(int *)(uVar5 + 0x2c),
                    *(undefined4 *)(puVar7[-0x15] + 0x630));
            iVar3 = iVar3 + 1;
          }
        }
        puVar4 = (undefined8 *)(puVar6[0x68] + 0x10);
      }
      puVar6 = (undefined8 *)*puVar6;
    } while (puVar6 != (undefined8 *)&DAT_0011a610);
  }
  __rcu_read_unlock();
  iVar3 = snprintf(local_88,0x20,"total: %d\n",iVar3);
  simple_read_from_buffer(param_2,param_3,param_4,local_88,(long)iVar3);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __traceiter_android_vh_syscall_prctl_finished @ 00105620 size=116
// signature: undefined __traceiter_android_vh_syscall_prctl_finished(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_android_vh_syscall_prctl_finished
          (undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00115ce0;
  plVar2 = DAT_00115ce0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x10bfa6e7) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105670);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_android_rvh_pr_set_vma_name_bypass @ 00105698 size=160
// signature: undefined __traceiter_android_rvh_pr_set_vma_name_bypass(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_android_rvh_pr_set_vma_name_bypass
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  code *pcVar1;
  undefined8 *puVar2;
  
  pcVar1 = (code *)*_DAT_00115d28;
  puVar2 = _DAT_00115d28;
  do {
    if (*(int *)(pcVar1 + -4) != 0x7207f8b8) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10570c);
      (*pcVar1)();
    }
    (*pcVar1)(puVar2[1],param_2,param_3,param_4,param_5,param_6,param_7);
    pcVar1 = (code *)puVar2[3];
    puVar2 = puVar2 + 3;
  } while (pcVar1 != (code *)0x0);
  return 0;
}



//------------------------------------------------------------
// __traceiter_msched_pr_set_vma_name_bypass @ 0010573c size=124
// signature: undefined __traceiter_msched_pr_set_vma_name_bypass(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_msched_pr_set_vma_name_bypass
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115d70;
  plVar2 = _DAT_00115d70;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x78ed723a) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105794);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_percpu_rwsem_down_read_preempt @ 001057bc size=124
// signature: undefined __traceiter_percpu_rwsem_down_read_preempt(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_percpu_rwsem_down_read_preempt
          (undefined8 param_1,undefined8 param_2,uint param_3,uint param_4)

{
  code *pcVar1;
  long *plVar2;
  
  if (_DAT_00115db8 != (long *)0x0) {
    plVar2 = _DAT_00115db8;
    do {
      if (*(int *)((code *)*plVar2 + -4) != 0x1613d83) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105814);
        (*pcVar1)();
      }
      (*(code *)*plVar2)(plVar2[1],param_2,param_3 & 1,param_4 & 1);
      plVar2 = plVar2 + 3;
    } while (*plVar2 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// __traceiter_percpu_rwsem_wait_complete @ 0010583c size=124
// signature: undefined __traceiter_percpu_rwsem_wait_complete(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_percpu_rwsem_wait_complete
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint param_4)

{
  code *pcVar1;
  long *plVar2;
  
  if (_DAT_00115e00 != (long *)0x0) {
    plVar2 = _DAT_00115e00;
    do {
      if (*(int *)((code *)*plVar2 + -4) != 0x494a3161) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105894);
        (*pcVar1)();
      }
      (*(code *)*plVar2)(plVar2[1],param_2,param_3,param_4 & 1);
      plVar2 = plVar2 + 3;
    } while (*plVar2 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// __traceiter_percpu_rwsem_up_write @ 001058bc size=100
// signature: undefined __traceiter_percpu_rwsem_up_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_percpu_rwsem_up_write(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115e48;
  plVar2 = _DAT_00115e48;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x25413e9d) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105900);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_msched_task_get_mvp_prio @ 00105924 size=172
// signature: undefined __traceiter_msched_task_get_mvp_prio(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_msched_task_get_mvp_prio
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined8 param_7,undefined4 param_8)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115e90;
  plVar2 = _DAT_00115e90;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x5314ab4b) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1059a4);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_msched_uclamp_restriction_result @ 001059d4 size=232
// signature: undefined __traceiter_msched_uclamp_restriction_result(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_msched_uclamp_restriction_result
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
          undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115ed8;
  plVar2 = _DAT_00115ed8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x45f4c624) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10,param_11,param_12);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105a88);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_msched_uclamp_inheritance_result @ 00105ac0 size=232
// signature: undefined __traceiter_msched_uclamp_inheritance_result(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_msched_uclamp_inheritance_result
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
          undefined4 param_5,undefined4 param_6,undefined8 param_7,undefined4 param_8,
          undefined2 param_9,undefined2 param_10,undefined2 param_11,undefined4 param_12)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115f20;
  plVar2 = _DAT_00115f20;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x13585578) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10,param_11,param_12);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105b74);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_sched_boost_ux_kworker @ 00105bac size=124
// signature: undefined __traceiter_sched_boost_ux_kworker(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_sched_boost_ux_kworker
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115f68;
  plVar2 = _DAT_00115f68;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x4f2cbf4c) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105c04);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_sched_wake_by_irq_kth @ 00105c2c size=100
// signature: undefined __traceiter_sched_wake_by_irq_kth(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_sched_wake_by_irq_kth(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115fb0;
  plVar2 = _DAT_00115fb0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x389e96a6) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105c70);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_sched_percpu_rwsem_hold_time @ 00105c94 size=116
// signature: undefined __traceiter_sched_percpu_rwsem_hold_time(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_sched_percpu_rwsem_hold_time(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115ff8;
  plVar2 = _DAT_00115ff8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x56a40912) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105ce4);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_sched_percpu_rwsem_starttime @ 00105d0c size=148
// signature: undefined __traceiter_sched_percpu_rwsem_starttime(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_sched_percpu_rwsem_starttime
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint param_4,undefined4 param_5,
          undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  
  if (_DAT_00116040 != (long *)0x0) {
    plVar2 = _DAT_00116040;
    do {
      if (*(int *)((code *)*plVar2 + -4) != 0x1765e33d) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105d78);
        (*pcVar1)();
      }
      (*(code *)*plVar2)(plVar2[1],param_2,param_3,param_4 & 1,param_5,param_6);
      plVar2 = plVar2 + 3;
    } while (*plVar2 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// __traceiter_binder_inherit_ux_type @ 00105da4 size=124
// signature: undefined __traceiter_binder_inherit_ux_type(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_binder_inherit_ux_type
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint param_4)

{
  code *pcVar1;
  long *plVar2;
  
  if (_DAT_00116088 != (long *)0x0) {
    plVar2 = _DAT_00116088;
    do {
      if (*(int *)((code *)*plVar2 + -4) != -0x615c3d5d) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105dfc);
        (*pcVar1)();
      }
      (*(code *)*plVar2)(plVar2[1],param_2,param_3,param_4 & 1);
      plVar2 = plVar2 + 3;
    } while (*plVar2 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// __traceiter_binder_pick_best_thread @ 00105e24 size=148
// signature: undefined __traceiter_binder_pick_best_thread(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_binder_pick_best_thread
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001160d0;
  plVar2 = _DAT_001160d0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x7f515c1f) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105e90);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_binder_nothread_be_select @ 00105ebc size=124
// signature: undefined __traceiter_binder_nothread_be_select(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_binder_nothread_be_select
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint param_4)

{
  code *pcVar1;
  long *plVar2;
  
  if (_DAT_00116118 != (long *)0x0) {
    plVar2 = _DAT_00116118;
    do {
      if (*(int *)((code *)*plVar2 + -4) != -0x615c3d5d) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105f14);
        (*pcVar1)();
      }
      (*(code *)*plVar2)(plVar2[1],param_2,param_3,param_4 & 1);
      plVar2 = plVar2 + 3;
    } while (*plVar2 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// __traceiter_binder_inherit_rt_prio @ 00105f3c size=116
// signature: undefined __traceiter_binder_inherit_rt_prio(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_binder_inherit_rt_prio(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00116160;
  plVar2 = _DAT_00116160;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x54a836a3) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105f8c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_binder_inherit_rt_check @ 00105fb4 size=164
// signature: undefined __traceiter_binder_inherit_rt_check(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_binder_inherit_rt_check
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined8 param_6,undefined8 param_7)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001161a8;
  plVar2 = _DAT_001161a8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x6843d3fa) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10602c);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_msched_pr_set_vma_name_bypass @ 0010605c size=216
// signature: undefined trace_event_raw_event_msched_pr_set_vma_name_bypass(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_msched_pr_set_vma_name_bypass
               (long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
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
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x30), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = *(undefined4 *)(param_2 + 0x630);
    *(undefined4 *)(lVar1 + 0xc) = *(undefined4 *)(param_2 + 0x634);
    uVar3 = *(undefined8 *)(param_2 + 0x850);
    uVar4 = *(undefined8 *)(param_2 + 0x848);
    *(undefined8 *)(lVar1 + 0x20) = param_3;
    *(undefined8 *)(lVar1 + 0x28) = param_4;
    *(undefined8 *)(lVar1 + 0x10) = uVar4;
    *(undefined8 *)(lVar1 + 0x18) = uVar3;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_msched_pr_set_vma_name_bypass @ 00106138 size=280
// signature: undefined perf_trace_msched_pr_set_vma_name_bypass(void)
// callers: []
//------------------------------------------------------------

void perf_trace_msched_pr_set_vma_name_bypass
               (long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x34,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = *(undefined4 *)(param_2 + 0x630);
    *(undefined4 *)(lVar3 + 0xc) = *(undefined4 *)(param_2 + 0x634);
    uVar4 = *(undefined8 *)(param_2 + 0x850);
    uVar5 = *(undefined8 *)(param_2 + 0x848);
    *(undefined8 *)(lVar3 + 0x20) = param_3;
    *(undefined8 *)(lVar3 + 0x28) = param_4;
    *(undefined8 *)(lVar3 + 0x10) = uVar5;
    *(undefined8 *)(lVar3 + 0x18) = uVar4;
    perf_trace_run_bpf_submit(lVar3,0x34,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_percpu_rwsem_down_read_preempt @ 00106254 size=272
// signature: undefined trace_event_raw_event_percpu_rwsem_down_read_preempt(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_percpu_rwsem_down_read_preempt
               (long param_1,long param_2,byte param_3,byte param_4)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar3 = __trace_trigger_soft_disabled(param_1), (uVar3 & 1) == 0)) &&
     (lVar2 = trace_event_buffer_reserve(&local_68,param_1,0x40), lVar2 != 0)) {
    *(long *)(lVar2 + 8) = param_2;
    lVar1 = sp_el0;
    *(undefined4 *)(lVar2 + 0x10) = *(undefined4 *)(lVar1 + 0x630);
    *(undefined4 *)(lVar2 + 0x14) = *(undefined4 *)(lVar1 + 0x634);
    uVar5 = *(undefined8 *)(lVar1 + 0x850);
    *(undefined8 *)(lVar2 + 0x18) = *(undefined8 *)(lVar1 + 0x848);
    *(undefined8 *)(lVar2 + 0x20) = uVar5;
    uVar6 = *(undefined8 *)(*(long *)(lVar1 + 0x670) + 0x850);
    uVar5 = *(undefined8 *)(*(long *)(lVar1 + 0x670) + 0x848);
    *(byte *)(lVar2 + 0x38) = param_3 & 1;
    *(byte *)(lVar2 + 0x39) = param_4 & 1;
    *(undefined8 *)(lVar2 + 0x28) = uVar5;
    *(undefined8 *)(lVar2 + 0x30) = uVar6;
    if (param_2 == 0) {
      uVar4 = 0xffffffff;
    }
    else {
      uVar4 = *(undefined4 *)(param_2 + 0x58);
    }
    *(undefined4 *)(lVar2 + 0x3c) = uVar4;
    trace_event_buffer_commit(&local_68);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_percpu_rwsem_down_read_preempt @ 00106368 size=336
// signature: undefined perf_trace_percpu_rwsem_down_read_preempt(void)
// callers: []
//------------------------------------------------------------

void perf_trace_percpu_rwsem_down_read_preempt(long param_1,long param_2,byte param_3,byte param_4)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar4 = tpidr_el1;
  plVar1 = (long *)(lVar4 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar4 = perf_trace_buf_alloc(0x44,&local_50,&local_54), lVar4 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    lVar3 = sp_el0;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(long *)(lVar4 + 8) = param_2;
    *(undefined4 *)(lVar4 + 0x10) = *(undefined4 *)(lVar3 + 0x630);
    *(undefined4 *)(lVar4 + 0x14) = *(undefined4 *)(lVar3 + 0x634);
    uVar6 = *(undefined8 *)(lVar3 + 0x850);
    *(undefined8 *)(lVar4 + 0x18) = *(undefined8 *)(lVar3 + 0x848);
    *(undefined8 *)(lVar4 + 0x20) = uVar6;
    uVar7 = *(undefined8 *)(*(long *)(lVar3 + 0x670) + 0x850);
    uVar6 = *(undefined8 *)(*(long *)(lVar3 + 0x670) + 0x848);
    *(byte *)(lVar4 + 0x38) = param_3 & 1;
    *(byte *)(lVar4 + 0x39) = param_4 & 1;
    *(undefined8 *)(lVar4 + 0x28) = uVar6;
    *(undefined8 *)(lVar4 + 0x30) = uVar7;
    if (param_2 == 0) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = *(undefined4 *)(param_2 + 0x58);
    }
    *(undefined4 *)(lVar4 + 0x3c) = uVar5;
    perf_trace_run_bpf_submit(lVar4,0x44,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_percpu_rwsem_wait_complete @ 001064bc size=248
// signature: undefined trace_event_raw_event_percpu_rwsem_wait_complete(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_percpu_rwsem_wait_complete
               (long param_1,long param_2,undefined4 param_3,byte param_4)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar3 = __trace_trigger_soft_disabled(param_1), (uVar3 & 1) == 0)) &&
     (lVar2 = trace_event_buffer_reserve(&local_68,param_1,0x30), lVar2 != 0)) {
    *(long *)(lVar2 + 8) = param_2;
    lVar1 = sp_el0;
    *(undefined4 *)(lVar2 + 0x10) = *(undefined4 *)(lVar1 + 0x630);
    uVar6 = *(undefined8 *)(lVar1 + 0x850);
    uVar5 = *(undefined8 *)(lVar1 + 0x848);
    *(undefined4 *)(lVar2 + 0x24) = param_3;
    *(byte *)(lVar2 + 0x28) = param_4 & 1;
    *(undefined8 *)(lVar2 + 0x1c) = uVar6;
    *(undefined8 *)(lVar2 + 0x14) = uVar5;
    if (param_2 == 0) {
      uVar4 = 0xffffffff;
    }
    else {
      uVar4 = *(undefined4 *)(param_2 + 0x58);
    }
    *(undefined4 *)(lVar2 + 0x2c) = uVar4;
    trace_event_buffer_commit(&local_68);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_percpu_rwsem_wait_complete @ 001065b8 size=312
// signature: undefined perf_trace_percpu_rwsem_wait_complete(void)
// callers: []
//------------------------------------------------------------

void perf_trace_percpu_rwsem_wait_complete
               (long param_1,long param_2,undefined4 param_3,byte param_4)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar4 = tpidr_el1;
  plVar1 = (long *)(lVar4 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar4 = perf_trace_buf_alloc(0x34,&local_50,&local_54), lVar4 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    lVar3 = sp_el0;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(long *)(lVar4 + 8) = param_2;
    *(undefined4 *)(lVar4 + 0x10) = *(undefined4 *)(lVar3 + 0x630);
    uVar7 = *(undefined8 *)(lVar3 + 0x850);
    uVar6 = *(undefined8 *)(lVar3 + 0x848);
    *(undefined4 *)(lVar4 + 0x24) = param_3;
    *(byte *)(lVar4 + 0x28) = param_4 & 1;
    *(undefined8 *)(lVar4 + 0x1c) = uVar7;
    *(undefined8 *)(lVar4 + 0x14) = uVar6;
    if (param_2 == 0) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = *(undefined4 *)(param_2 + 0x58);
    }
    *(undefined4 *)(lVar4 + 0x2c) = uVar5;
    perf_trace_run_bpf_submit(lVar4,0x34,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_percpu_rwsem_up_write @ 001066f4 size=216
// signature: undefined trace_event_raw_event_percpu_rwsem_up_write(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_percpu_rwsem_up_write(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar3 = __trace_trigger_soft_disabled(param_1), (uVar3 & 1) == 0)) &&
     (lVar2 = trace_event_buffer_reserve(&local_58,param_1,0x28), lVar2 != 0)) {
    *(long *)(lVar2 + 8) = param_2;
    lVar1 = sp_el0;
    *(undefined4 *)(lVar2 + 0x10) = *(undefined4 *)(lVar1 + 0x630);
    uVar5 = *(undefined8 *)(lVar1 + 0x848);
    *(undefined8 *)(lVar2 + 0x1c) = *(undefined8 *)(lVar1 + 0x850);
    *(undefined8 *)(lVar2 + 0x14) = uVar5;
    if (param_2 == 0) {
      uVar4 = 0xffffffff;
    }
    else {
      uVar4 = *(undefined4 *)(param_2 + 0x58);
    }
    *(undefined4 *)(lVar2 + 0x24) = uVar4;
    trace_event_buffer_commit(&local_58);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_percpu_rwsem_up_write @ 001067d0 size=284
// signature: undefined perf_trace_percpu_rwsem_up_write(void)
// callers: []
//------------------------------------------------------------

void perf_trace_percpu_rwsem_up_write(long param_1,long param_2)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  ulong unaff_x30;
  undefined1 auStack_50 [12];
  undefined4 local_44;
  long local_40;
  undefined8 local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_40 = 0;
  local_44 = 0;
  lVar4 = tpidr_el1;
  plVar1 = (long *)(lVar4 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar4 = perf_trace_buf_alloc(0x2c,&local_40,&local_44), lVar4 != 0)) {
    *(undefined1 **)(local_40 + 0xe8) = auStack_50 + 0x20;
    *(undefined1 **)(local_40 + 0xf8) = auStack_50;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    lVar3 = sp_el0;
    *(ulong *)(local_40 + 0x100) = uVar2;
    *(undefined8 *)(local_40 + 0x108) = 5;
    *(long *)(lVar4 + 8) = param_2;
    *(undefined4 *)(lVar4 + 0x10) = *(undefined4 *)(lVar3 + 0x630);
    uVar6 = *(undefined8 *)(lVar3 + 0x848);
    *(undefined8 *)(lVar4 + 0x1c) = *(undefined8 *)(lVar3 + 0x850);
    *(undefined8 *)(lVar4 + 0x14) = uVar6;
    if (param_2 == 0) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = *(undefined4 *)(param_2 + 0x58);
    }
    *(undefined4 *)(lVar4 + 0x24) = uVar5;
    perf_trace_run_bpf_submit(lVar4,0x2c,local_44,param_1,1,local_40,plVar1,0);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_msched_task_get_mvp_prio @ 001068f0 size=252
// signature: undefined trace_event_raw_event_msched_task_get_mvp_prio(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_msched_task_get_mvp_prio
               (long param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined8 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar3 = __trace_trigger_soft_disabled(param_1), (uVar3 & 1) == 0)) &&
     (lVar2 = trace_event_buffer_reserve(&local_88,param_1,0x30), lVar2 != 0)) {
    *(undefined4 *)(lVar2 + 8) = *(undefined4 *)(param_2 + 0x630);
    *(undefined4 *)(lVar2 + 0xc) = *(undefined4 *)(param_2 + 0x634);
    uVar1 = *(undefined4 *)(param_2 + 0x84);
    *(undefined4 *)(lVar2 + 0x18) = param_4;
    *(undefined4 *)(lVar2 + 0x1c) = param_5;
    *(undefined8 *)(lVar2 + 0x20) = param_7;
    *(undefined4 *)(lVar2 + 0x28) = param_6;
    *(undefined4 *)(lVar2 + 0x2c) = param_8;
    *(undefined4 *)(lVar2 + 0x10) = uVar1;
    *(undefined4 *)(lVar2 + 0x14) = param_3;
    trace_event_buffer_commit(&local_88);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_msched_task_get_mvp_prio @ 001069f0 size=316
// signature: undefined perf_trace_msched_task_get_mvp_prio(void)
// callers: []
//------------------------------------------------------------

void perf_trace_msched_task_get_mvp_prio
               (long param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined8 param_7,undefined4 param_8)

{
  long *plVar1;
  ulong uVar2;
  undefined4 uVar3;
  long lVar4;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  local_70 = 0;
  local_74 = 0;
  lVar4 = tpidr_el1;
  plVar1 = (long *)(lVar4 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar4 = perf_trace_buf_alloc(0x34,&local_70,&local_74), lVar4 != 0)) {
    *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
    *(undefined1 **)(local_70 + 0xf8) = auStack_80;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_70 + 0x100) = uVar2;
    *(undefined8 *)(local_70 + 0x108) = 5;
    *(undefined4 *)(lVar4 + 8) = *(undefined4 *)(param_2 + 0x630);
    *(undefined4 *)(lVar4 + 0xc) = *(undefined4 *)(param_2 + 0x634);
    uVar3 = *(undefined4 *)(param_2 + 0x84);
    *(undefined4 *)(lVar4 + 0x18) = param_4;
    *(undefined4 *)(lVar4 + 0x1c) = param_5;
    *(undefined8 *)(lVar4 + 0x20) = param_7;
    *(undefined4 *)(lVar4 + 0x28) = param_6;
    *(undefined4 *)(lVar4 + 0x2c) = param_8;
    *(undefined4 *)(lVar4 + 0x10) = uVar3;
    *(undefined4 *)(lVar4 + 0x14) = param_3;
    perf_trace_run_bpf_submit(lVar4,0x34,local_74,param_1,1,local_70,plVar1,0);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_msched_uclamp_restriction_result @ 00106b30 size=260
// signature: undefined trace_event_raw_event_msched_uclamp_restriction_result(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_msched_uclamp_restriction_result
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_88,param_1,0x34), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    *(undefined4 *)(lVar1 + 0x14) = param_5;
    *(undefined4 *)(lVar1 + 0x18) = param_6;
    *(undefined4 *)(lVar1 + 0x1c) = param_7;
    *(undefined4 *)(lVar1 + 0x20) = param_8;
    *(undefined4 *)(lVar1 + 0x24) = param_9;
    *(undefined4 *)(lVar1 + 0x28) = param_10;
    *(undefined4 *)(lVar1 + 0x2c) = param_11;
    *(undefined4 *)(lVar1 + 0x30) = param_12;
    trace_event_buffer_commit(&local_88);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_msched_uclamp_restriction_result @ 00106c38 size=328
// signature: undefined perf_trace_msched_uclamp_restriction_result(void)
// callers: []
//------------------------------------------------------------

void perf_trace_msched_uclamp_restriction_result
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_70 = 0;
  local_74 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x34,&local_70,&local_74), lVar3 != 0)) {
    *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
    *(undefined1 **)(local_70 + 0xf8) = auStack_80;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_70 + 0x100) = uVar2;
    *(undefined8 *)(local_70 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    *(undefined4 *)(lVar3 + 0x14) = param_5;
    *(undefined4 *)(lVar3 + 0x18) = param_6;
    *(undefined4 *)(lVar3 + 0x1c) = param_7;
    *(undefined4 *)(lVar3 + 0x20) = param_8;
    *(undefined4 *)(lVar3 + 0x24) = param_9;
    *(undefined4 *)(lVar3 + 0x28) = param_10;
    *(undefined4 *)(lVar3 + 0x2c) = param_11;
    *(undefined4 *)(lVar3 + 0x30) = param_12;
    perf_trace_run_bpf_submit(lVar3,0x34,local_74,param_1,1,local_70,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_msched_uclamp_inheritance_result @ 00106d84 size=272
// signature: undefined trace_event_raw_event_msched_uclamp_inheritance_result(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_msched_uclamp_inheritance_result
               (long param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
               undefined2 param_5,undefined2 param_6,undefined8 param_7,undefined2 param_8,
               undefined2 param_9,undefined2 param_10,undefined2 param_11,undefined4 param_12)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_88,param_1,0x38), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined8 *)(lVar1 + 0x10) = param_4;
    *(undefined2 *)(lVar1 + 0x18) = param_5;
    *(undefined2 *)(lVar1 + 0x1a) = param_6;
    *(undefined8 *)(lVar1 + 0x20) = param_7;
    *(undefined2 *)(lVar1 + 0x28) = param_8;
    *(undefined2 *)(lVar1 + 0x2a) = param_9;
    *(undefined2 *)(lVar1 + 0x2c) = param_10;
    *(undefined2 *)(lVar1 + 0x2e) = param_11;
    *(undefined4 *)(lVar1 + 0x30) = param_12;
    trace_event_buffer_commit(&local_88);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_msched_uclamp_inheritance_result @ 00106e98 size=336
// signature: undefined perf_trace_msched_uclamp_inheritance_result(void)
// callers: []
//------------------------------------------------------------

void perf_trace_msched_uclamp_inheritance_result
               (long param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
               undefined2 param_5,undefined2 param_6,undefined8 param_7,undefined2 param_8,
               undefined2 param_9,undefined2 param_10,undefined2 param_11,undefined4 param_12)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_70 = 0;
  local_74 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x3c,&local_70,&local_74), lVar3 != 0)) {
    *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
    *(undefined1 **)(local_70 + 0xf8) = auStack_80;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_70 + 0x100) = uVar2;
    *(undefined8 *)(local_70 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined8 *)(lVar3 + 0x10) = param_4;
    *(undefined2 *)(lVar3 + 0x18) = param_5;
    *(undefined2 *)(lVar3 + 0x1a) = param_6;
    *(undefined8 *)(lVar3 + 0x20) = param_7;
    *(undefined2 *)(lVar3 + 0x28) = param_8;
    *(undefined2 *)(lVar3 + 0x2a) = param_9;
    *(undefined2 *)(lVar3 + 0x2c) = param_10;
    *(undefined2 *)(lVar3 + 0x2e) = param_11;
    *(undefined4 *)(lVar3 + 0x30) = param_12;
    perf_trace_run_bpf_submit(lVar3,0x3c,local_74,param_1,1,local_70,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_sched_boost_ux_kworker @ 00106fec size=308
// signature: undefined trace_event_raw_event_sched_boost_ux_kworker(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_sched_boost_ux_kworker
               (long param_1,long param_2,undefined4 param_3,char *param_4)

{
  int iVar1;
  char *__s;
  long lVar2;
  size_t sVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar5 = __trace_trigger_soft_disabled(param_1), (uVar5 & 1) == 0)) {
    __s = "(null)";
    if (param_4 != (char *)0x0) {
      __s = param_4;
    }
    sVar3 = strlen(__s);
    iVar1 = (int)sVar3 + 1;
    lVar4 = trace_event_buffer_reserve(&local_78,param_1,(long)iVar1 + 0x3c);
    if (lVar4 != 0) {
      *(uint *)(lVar4 + 0x38) = iVar1 * 0x10000 | 0x3c;
      *(undefined4 *)(lVar4 + 8) = *(undefined4 *)(param_2 + 0x630);
      *(undefined4 *)(lVar4 + 0xc) = *(undefined4 *)(param_2 + 0x634);
      *(undefined4 *)(lVar4 + 0x10) = *(undefined4 *)(param_2 + 0x84);
      uVar6 = *(undefined8 *)(param_2 + 0x848);
      *(undefined8 *)(lVar4 + 0x1c) = *(undefined8 *)(param_2 + 0x850);
      lVar2 = sp_el0;
      *(undefined8 *)(lVar4 + 0x14) = uVar6;
      uVar6 = *(undefined8 *)(lVar2 + 0x848);
      uVar7 = *(undefined8 *)(lVar2 + 0x850);
      *(undefined4 *)(lVar4 + 0x34) = param_3;
      *(undefined8 *)(lVar4 + 0x24) = uVar6;
      *(undefined8 *)(lVar4 + 0x2c) = uVar7;
      strcpy((char *)(lVar4 + 0x3c),__s);
      trace_event_buffer_commit(&local_78);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_sched_boost_ux_kworker @ 00107124 size=396
// signature: undefined perf_trace_sched_boost_ux_kworker(void)
// callers: []
//------------------------------------------------------------

void perf_trace_sched_boost_ux_kworker(long param_1,long param_2,undefined4 param_3,char *param_4)

{
  int iVar1;
  long *plVar2;
  char *__s;
  ulong uVar3;
  long lVar4;
  size_t sVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar6 = sp_el0;
  __s = "(null)";
  if (param_4 != (char *)0x0) {
    __s = param_4;
  }
  local_68 = *(long *)(lVar6 + 0x638);
  local_70 = 0;
  local_74 = 0;
  sVar5 = strlen(__s);
  lVar6 = tpidr_el1;
  plVar2 = (long *)(lVar6 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = ((uint)sVar5 & 0xfffffff8) + 0x44;
    lVar6 = perf_trace_buf_alloc(iVar1,&local_70,&local_74);
    if (lVar6 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_70 + 0x100) = uVar3;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(uint *)(lVar6 + 0x38) = (uint)sVar5 * 0x10000 + 0x1003c;
      *(undefined4 *)(lVar6 + 8) = *(undefined4 *)(param_2 + 0x630);
      *(undefined4 *)(lVar6 + 0xc) = *(undefined4 *)(param_2 + 0x634);
      *(undefined4 *)(lVar6 + 0x10) = *(undefined4 *)(param_2 + 0x84);
      uVar7 = *(undefined8 *)(param_2 + 0x848);
      *(undefined8 *)(lVar6 + 0x1c) = *(undefined8 *)(param_2 + 0x850);
      lVar4 = sp_el0;
      *(undefined8 *)(lVar6 + 0x14) = uVar7;
      uVar8 = *(undefined8 *)(lVar4 + 0x848);
      uVar7 = *(undefined8 *)(lVar4 + 0x850);
      *(undefined4 *)(lVar6 + 0x34) = param_3;
      *(undefined8 *)(lVar6 + 0x24) = uVar8;
      *(undefined8 *)(lVar6 + 0x2c) = uVar7;
      strcpy((char *)(lVar6 + 0x3c),__s);
      perf_trace_run_bpf_submit(lVar6,iVar1,local_74,param_1,1,local_70,plVar2,0);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_sched_wake_by_irq_kth @ 001072b4 size=204
// signature: undefined trace_event_raw_event_sched_wake_by_irq_kth(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_sched_wake_by_irq_kth(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x24), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = *(undefined4 *)(param_2 + 0x630);
    *(undefined4 *)(lVar1 + 0xc) = *(undefined4 *)(param_2 + 0x634);
    *(undefined4 *)(lVar1 + 0x10) = *(undefined4 *)(param_2 + 0x84);
    uVar3 = *(undefined8 *)(param_2 + 0x848);
    *(undefined8 *)(lVar1 + 0x1c) = *(undefined8 *)(param_2 + 0x850);
    *(undefined8 *)(lVar1 + 0x14) = uVar3;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_sched_wake_by_irq_kth @ 00107384 size=272
// signature: undefined perf_trace_sched_wake_by_irq_kth(void)
// callers: []
//------------------------------------------------------------

void perf_trace_sched_wake_by_irq_kth(long param_1,long param_2)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  ulong unaff_x30;
  undefined1 auStack_50 [12];
  undefined4 local_44;
  long local_40;
  undefined8 local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  local_44 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x24,&local_40,&local_44), lVar3 != 0)) {
    *(undefined1 **)(local_40 + 0xe8) = auStack_50 + 0x20;
    *(undefined1 **)(local_40 + 0xf8) = auStack_50;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_40 + 0x100) = uVar2;
    *(undefined8 *)(local_40 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = *(undefined4 *)(param_2 + 0x630);
    *(undefined4 *)(lVar3 + 0xc) = *(undefined4 *)(param_2 + 0x634);
    *(undefined4 *)(lVar3 + 0x10) = *(undefined4 *)(param_2 + 0x84);
    uVar4 = *(undefined8 *)(param_2 + 0x848);
    *(undefined8 *)(lVar3 + 0x1c) = *(undefined8 *)(param_2 + 0x850);
    *(undefined8 *)(lVar3 + 0x14) = uVar4;
    perf_trace_run_bpf_submit(lVar3,0x24,local_44,param_1,1,local_40,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_sched_percpu_rwsem_hold_time @ 00107498 size=212
// signature: undefined trace_event_raw_event_sched_percpu_rwsem_hold_time(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_sched_percpu_rwsem_hold_time
               (long param_1,long param_2,undefined8 param_3)

{
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar3 = __trace_trigger_soft_disabled(param_1), (uVar3 & 1) == 0)) &&
     (lVar2 = trace_event_buffer_reserve(&local_58,param_1,0x30), lVar2 != 0)) {
    *(undefined4 *)(lVar2 + 8) = *(undefined4 *)(param_2 + 0x630);
    *(undefined4 *)(lVar2 + 0xc) = *(undefined4 *)(param_2 + 0x634);
    uVar1 = *(undefined4 *)(param_2 + 0x84);
    *(undefined8 *)(lVar2 + 0x28) = param_3;
    *(undefined4 *)(lVar2 + 0x10) = uVar1;
    uVar4 = *(undefined8 *)(param_2 + 0x848);
    *(undefined8 *)(lVar2 + 0x1c) = *(undefined8 *)(param_2 + 0x850);
    *(undefined8 *)(lVar2 + 0x14) = uVar4;
    trace_event_buffer_commit(&local_58);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_sched_percpu_rwsem_hold_time @ 00107570 size=288
// signature: undefined perf_trace_sched_percpu_rwsem_hold_time(void)
// callers: []
//------------------------------------------------------------

void perf_trace_sched_percpu_rwsem_hold_time(long param_1,long param_2,undefined8 param_3)

{
  long *plVar1;
  ulong uVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 uVar5;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar4 = tpidr_el1;
  plVar1 = (long *)(lVar4 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar4 = perf_trace_buf_alloc(0x34,&local_50,&local_54), lVar4 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined4 *)(lVar4 + 8) = *(undefined4 *)(param_2 + 0x630);
    *(undefined4 *)(lVar4 + 0xc) = *(undefined4 *)(param_2 + 0x634);
    uVar3 = *(undefined4 *)(param_2 + 0x84);
    *(undefined8 *)(lVar4 + 0x28) = param_3;
    *(undefined4 *)(lVar4 + 0x10) = uVar3;
    uVar5 = *(undefined8 *)(param_2 + 0x848);
    *(undefined8 *)(lVar4 + 0x1c) = *(undefined8 *)(param_2 + 0x850);
    *(undefined8 *)(lVar4 + 0x14) = uVar5;
    perf_trace_run_bpf_submit(lVar4,0x34,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_sched_percpu_rwsem_starttime @ 00107694 size=244
// signature: undefined trace_event_raw_event_sched_percpu_rwsem_starttime(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_sched_percpu_rwsem_starttime
               (long param_1,long param_2,undefined1 param_3,byte param_4,undefined4 param_5,
               undefined4 param_6)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_78,param_1,0x2c), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = *(undefined4 *)(param_2 + 0x630);
    *(undefined4 *)(lVar1 + 0xc) = *(undefined4 *)(param_2 + 0x84);
    uVar3 = *(undefined8 *)(param_2 + 0x850);
    uVar4 = *(undefined8 *)(param_2 + 0x848);
    *(undefined1 *)(lVar1 + 0x20) = param_3;
    *(byte *)(lVar1 + 0x21) = param_4 & 1;
    *(undefined4 *)(lVar1 + 0x24) = param_5;
    *(undefined4 *)(lVar1 + 0x28) = param_6;
    *(undefined8 *)(lVar1 + 0x10) = uVar4;
    *(undefined8 *)(lVar1 + 0x18) = uVar3;
    trace_event_buffer_commit(&local_78);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_sched_percpu_rwsem_starttime @ 0010778c size=308
// signature: undefined perf_trace_sched_percpu_rwsem_starttime(void)
// callers: []
//------------------------------------------------------------

void perf_trace_sched_percpu_rwsem_starttime
               (long param_1,long param_2,undefined1 param_3,byte param_4,undefined4 param_5,
               undefined4 param_6)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_60 = 0;
  local_64 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x2c,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = *(undefined4 *)(param_2 + 0x630);
    *(undefined4 *)(lVar3 + 0xc) = *(undefined4 *)(param_2 + 0x84);
    uVar4 = *(undefined8 *)(param_2 + 0x850);
    uVar5 = *(undefined8 *)(param_2 + 0x848);
    *(undefined1 *)(lVar3 + 0x20) = param_3;
    *(byte *)(lVar3 + 0x21) = param_4 & 1;
    *(undefined4 *)(lVar3 + 0x24) = param_5;
    *(undefined4 *)(lVar3 + 0x28) = param_6;
    *(undefined8 *)(lVar3 + 0x10) = uVar5;
    *(undefined8 *)(lVar3 + 0x18) = uVar4;
    perf_trace_run_bpf_submit(lVar3,0x2c,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_binder_inherit_ux_type @ 001078c4 size=236
// signature: undefined trace_event_raw_event_binder_inherit_ux_type(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_binder_inherit_ux_type
               (long param_1,long param_2,undefined4 param_3,byte param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
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
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x2c), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = *(undefined4 *)(param_2 + 0x630);
    *(undefined4 *)(lVar1 + 0xc) = *(undefined4 *)(param_2 + 0x634);
    *(undefined4 *)(lVar1 + 0x10) = *(undefined4 *)(param_2 + 0x84);
    uVar3 = *(undefined8 *)(param_2 + 0x850);
    uVar4 = *(undefined8 *)(param_2 + 0x848);
    *(undefined4 *)(lVar1 + 0x24) = param_3;
    *(byte *)(lVar1 + 0x28) = param_4 & 1;
    *(undefined8 *)(lVar1 + 0x1c) = uVar3;
    *(undefined8 *)(lVar1 + 0x14) = uVar4;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_binder_inherit_ux_type @ 001079b4 size=300
// signature: undefined perf_trace_binder_inherit_ux_type(void)
// callers: []
//------------------------------------------------------------

void perf_trace_binder_inherit_ux_type(long param_1,long param_2,undefined4 param_3,byte param_4)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x2c,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = *(undefined4 *)(param_2 + 0x630);
    *(undefined4 *)(lVar3 + 0xc) = *(undefined4 *)(param_2 + 0x634);
    *(undefined4 *)(lVar3 + 0x10) = *(undefined4 *)(param_2 + 0x84);
    uVar4 = *(undefined8 *)(param_2 + 0x850);
    uVar5 = *(undefined8 *)(param_2 + 0x848);
    *(undefined4 *)(lVar3 + 0x24) = param_3;
    *(byte *)(lVar3 + 0x28) = param_4 & 1;
    *(undefined8 *)(lVar3 + 0x1c) = uVar4;
    *(undefined8 *)(lVar3 + 0x14) = uVar5;
    perf_trace_run_bpf_submit(lVar3,0x2c,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_binder_pick_best_thread @ 00107ae4 size=276
// signature: undefined trace_event_raw_event_binder_pick_best_thread(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_binder_pick_best_thread
               (long param_1,undefined4 param_2,long param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6)

{
  long lVar1;
  ulong uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_78,param_1,0x30), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    if (param_3 == 0) {
      uVar3 = 0xffffffff;
      *(undefined1 *)(lVar1 + 0x1e) = 0;
      *(undefined4 *)(lVar1 + 0xc) = 0xffffffff;
      *(undefined4 *)(lVar1 + 0x18) = 0x6c756e28;
      *(undefined2 *)(lVar1 + 0x1c) = 0x296c;
    }
    else {
      *(undefined4 *)(lVar1 + 0xc) = *(undefined4 *)(param_3 + 0x630);
      uVar4 = *(undefined8 *)(param_3 + 0x850);
      *(undefined8 *)(lVar1 + 0x18) = *(undefined8 *)(param_3 + 0x848);
      *(undefined8 *)(lVar1 + 0x20) = uVar4;
      uVar3 = *(undefined4 *)(param_3 + 0x84);
    }
    *(undefined4 *)(lVar1 + 0x10) = uVar3;
    *(undefined4 *)(lVar1 + 0x14) = param_4;
    *(undefined4 *)(lVar1 + 0x28) = param_5;
    *(undefined4 *)(lVar1 + 0x2c) = param_6;
    trace_event_buffer_commit(&local_78);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_binder_pick_best_thread @ 00107bfc size=340
// signature: undefined perf_trace_binder_pick_best_thread(void)
// callers: []
//------------------------------------------------------------

void perf_trace_binder_pick_best_thread
               (long param_1,undefined4 param_2,long param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_60 = 0;
  local_64 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x34,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    if (param_3 == 0) {
      uVar4 = 0xffffffff;
      *(undefined1 *)(lVar3 + 0x1e) = 0;
      *(undefined4 *)(lVar3 + 0xc) = 0xffffffff;
      *(undefined4 *)(lVar3 + 0x18) = 0x6c756e28;
      *(undefined2 *)(lVar3 + 0x1c) = 0x296c;
    }
    else {
      *(undefined4 *)(lVar3 + 0xc) = *(undefined4 *)(param_3 + 0x630);
      uVar5 = *(undefined8 *)(param_3 + 0x850);
      *(undefined8 *)(lVar3 + 0x18) = *(undefined8 *)(param_3 + 0x848);
      *(undefined8 *)(lVar3 + 0x20) = uVar5;
      uVar4 = *(undefined4 *)(param_3 + 0x84);
    }
    *(undefined4 *)(lVar3 + 0x10) = uVar4;
    *(undefined4 *)(lVar3 + 0x14) = param_4;
    *(undefined4 *)(lVar3 + 0x28) = param_5;
    *(undefined4 *)(lVar3 + 0x2c) = param_6;
    perf_trace_run_bpf_submit(lVar3,0x34,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_binder_nothread_be_select @ 00107d54 size=236
// signature: undefined trace_event_raw_event_binder_nothread_be_select(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_binder_nothread_be_select
               (long param_1,long param_2,undefined4 param_3,byte param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
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
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x2c), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = *(undefined4 *)(param_2 + 0x630);
    *(undefined4 *)(lVar1 + 0xc) = *(undefined4 *)(param_2 + 0x634);
    *(undefined4 *)(lVar1 + 0x10) = *(undefined4 *)(param_2 + 0x84);
    uVar3 = *(undefined8 *)(param_2 + 0x850);
    uVar4 = *(undefined8 *)(param_2 + 0x848);
    *(undefined4 *)(lVar1 + 0x24) = param_3;
    *(byte *)(lVar1 + 0x28) = param_4 & 1;
    *(undefined8 *)(lVar1 + 0x1c) = uVar3;
    *(undefined8 *)(lVar1 + 0x14) = uVar4;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_binder_nothread_be_select @ 00107e44 size=300
// signature: undefined perf_trace_binder_nothread_be_select(void)
// callers: []
//------------------------------------------------------------

void perf_trace_binder_nothread_be_select(long param_1,long param_2,undefined4 param_3,byte param_4)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x2c,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = *(undefined4 *)(param_2 + 0x630);
    *(undefined4 *)(lVar3 + 0xc) = *(undefined4 *)(param_2 + 0x634);
    *(undefined4 *)(lVar3 + 0x10) = *(undefined4 *)(param_2 + 0x84);
    uVar4 = *(undefined8 *)(param_2 + 0x850);
    uVar5 = *(undefined8 *)(param_2 + 0x848);
    *(undefined4 *)(lVar3 + 0x24) = param_3;
    *(byte *)(lVar3 + 0x28) = param_4 & 1;
    *(undefined8 *)(lVar3 + 0x1c) = uVar4;
    *(undefined8 *)(lVar3 + 0x14) = uVar5;
    perf_trace_run_bpf_submit(lVar3,0x2c,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_binder_inherit_rt_prio @ 00107f74 size=244
// signature: undefined trace_event_raw_event_binder_inherit_rt_prio(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_binder_inherit_rt_prio(long param_1,long param_2,long param_3)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x40), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = *(undefined4 *)(param_2 + 0x630);
    *(undefined4 *)(lVar1 + 0xc) = *(undefined4 *)(param_2 + 0x634);
    *(undefined4 *)(lVar1 + 0x10) = *(undefined4 *)(param_2 + 0x84);
    uVar3 = *(undefined8 *)(param_2 + 0x848);
    *(undefined8 *)(lVar1 + 0x1c) = *(undefined8 *)(param_2 + 0x850);
    *(undefined8 *)(lVar1 + 0x14) = uVar3;
    *(undefined4 *)(lVar1 + 0x24) = *(undefined4 *)(param_3 + 0x630);
    *(undefined4 *)(lVar1 + 0x28) = *(undefined4 *)(param_3 + 0x634);
    *(undefined4 *)(lVar1 + 0x2c) = *(undefined4 *)(param_3 + 0x84);
    uVar3 = *(undefined8 *)(param_3 + 0x850);
    *(undefined8 *)(lVar1 + 0x30) = *(undefined8 *)(param_3 + 0x848);
    *(undefined8 *)(lVar1 + 0x38) = uVar3;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_binder_inherit_rt_prio @ 0010806c size=320
// signature: undefined perf_trace_binder_inherit_rt_prio(void)
// callers: []
//------------------------------------------------------------

void perf_trace_binder_inherit_rt_prio(long param_1,long param_2,long param_3)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x44,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = *(undefined4 *)(param_2 + 0x630);
    *(undefined4 *)(lVar3 + 0xc) = *(undefined4 *)(param_2 + 0x634);
    *(undefined4 *)(lVar3 + 0x10) = *(undefined4 *)(param_2 + 0x84);
    uVar4 = *(undefined8 *)(param_2 + 0x848);
    *(undefined8 *)(lVar3 + 0x1c) = *(undefined8 *)(param_2 + 0x850);
    *(undefined8 *)(lVar3 + 0x14) = uVar4;
    *(undefined4 *)(lVar3 + 0x24) = *(undefined4 *)(param_3 + 0x630);
    *(undefined4 *)(lVar3 + 0x28) = *(undefined4 *)(param_3 + 0x634);
    *(undefined4 *)(lVar3 + 0x2c) = *(undefined4 *)(param_3 + 0x84);
    uVar4 = *(undefined8 *)(param_3 + 0x850);
    *(undefined8 *)(lVar3 + 0x30) = *(undefined8 *)(param_3 + 0x848);
    *(undefined8 *)(lVar3 + 0x38) = uVar4;
    perf_trace_run_bpf_submit(lVar3,0x44,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_binder_inherit_rt_check @ 001081b0 size=272
// signature: undefined trace_event_raw_event_binder_inherit_rt_check(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_binder_inherit_rt_check
               (long param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined8 *param_6,undefined8 param_7)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_78,param_1,0x50), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = *(undefined4 *)(param_2 + 0x630);
    *(undefined4 *)(lVar1 + 0xc) = *(undefined4 *)(param_2 + 0x634);
    *(undefined4 *)(lVar1 + 0x10) = *(undefined4 *)(param_2 + 0x488);
    *(undefined4 *)(lVar1 + 0x14) = *(undefined4 *)(param_2 + 0x84);
    uVar3 = *(undefined8 *)(param_2 + 0x848);
    uVar4 = *(undefined8 *)(param_2 + 0x850);
    *(undefined4 *)(lVar1 + 0x28) = param_5;
    *(undefined4 *)(lVar1 + 0x2c) = param_3;
    *(undefined4 *)(lVar1 + 0x30) = param_4;
    *(undefined8 *)(lVar1 + 0x18) = uVar3;
    *(undefined8 *)(lVar1 + 0x20) = uVar4;
    uVar3 = *param_6;
    uVar4 = param_6[1];
    *(undefined8 *)(lVar1 + 0x48) = param_7;
    *(undefined8 *)(lVar1 + 0x34) = uVar3;
    *(undefined8 *)(lVar1 + 0x3c) = uVar4;
    trace_event_buffer_commit(&local_78);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_binder_inherit_rt_check @ 001082c4 size=344
// signature: undefined perf_trace_binder_inherit_rt_check(void)
// callers: []
//------------------------------------------------------------

void perf_trace_binder_inherit_rt_check
               (long param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined8 *param_6,undefined8 param_7)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_70 = 0;
  local_74 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x54,&local_70,&local_74), lVar3 != 0)) {
    *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
    *(undefined1 **)(local_70 + 0xf8) = auStack_80;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_70 + 0x100) = uVar2;
    *(undefined8 *)(local_70 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = *(undefined4 *)(param_2 + 0x630);
    *(undefined4 *)(lVar3 + 0xc) = *(undefined4 *)(param_2 + 0x634);
    *(undefined4 *)(lVar3 + 0x10) = *(undefined4 *)(param_2 + 0x488);
    *(undefined4 *)(lVar3 + 0x14) = *(undefined4 *)(param_2 + 0x84);
    uVar4 = *(undefined8 *)(param_2 + 0x848);
    uVar5 = *(undefined8 *)(param_2 + 0x850);
    *(undefined4 *)(lVar3 + 0x28) = param_5;
    *(undefined4 *)(lVar3 + 0x2c) = param_3;
    *(undefined4 *)(lVar3 + 0x30) = param_4;
    *(undefined8 *)(lVar3 + 0x18) = uVar4;
    *(undefined8 *)(lVar3 + 0x20) = uVar5;
    uVar4 = *param_6;
    uVar5 = param_6[1];
    *(undefined8 *)(lVar3 + 0x48) = param_7;
    *(undefined8 *)(lVar3 + 0x34) = uVar4;
    *(undefined8 *)(lVar3 + 0x3c) = uVar5;
    perf_trace_run_bpf_submit(lVar3,0x54,local_74,param_1,1,local_70,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_msched_pr_set_vma_name_bypass @ 00108420 size=28
// signature: undefined __bpf_trace_msched_pr_set_vma_name_bypass(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_msched_pr_set_vma_name_bypass(void)

{
  bpf_trace_run3();
  return;
}



//------------------------------------------------------------
// __bpf_trace_percpu_rwsem_down_read_preempt @ 00108440 size=36
// signature: undefined __bpf_trace_percpu_rwsem_down_read_preempt(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_percpu_rwsem_down_read_preempt
               (undefined8 param_1,undefined8 param_2,ulong param_3,ulong param_4)

{
  bpf_trace_run3(param_1,param_2,param_3 & 1,param_4 & 1);
  return;
}



//------------------------------------------------------------
// __bpf_trace_percpu_rwsem_wait_complete @ 00108468 size=36
// signature: undefined __bpf_trace_percpu_rwsem_wait_complete(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_percpu_rwsem_wait_complete
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,ulong param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4 & 1);
  return;
}



//------------------------------------------------------------
// __bpf_trace_percpu_rwsem_up_write @ 00108490 size=28
// signature: undefined __bpf_trace_percpu_rwsem_up_write(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_percpu_rwsem_up_write(void)

{
  bpf_trace_run1();
  return;
}



//------------------------------------------------------------
// __bpf_trace_msched_task_get_mvp_prio @ 001084b0 size=48
// signature: undefined __bpf_trace_msched_task_get_mvp_prio(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_msched_task_get_mvp_prio
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined8 param_7,undefined4 param_8)

{
  bpf_trace_run7(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



//------------------------------------------------------------
// __bpf_trace_msched_uclamp_restriction_result @ 001084e4 size=88
// signature: undefined __bpf_trace_msched_uclamp_restriction_result(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_msched_uclamp_restriction_result
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  bpf_trace_run11(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
                  param_11,param_12);
  return;
}



//------------------------------------------------------------
// __bpf_trace_msched_uclamp_inheritance_result @ 00108540 size=80
// signature: undefined __bpf_trace_msched_uclamp_inheritance_result(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_msched_uclamp_inheritance_result
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
               undefined2 param_5,undefined2 param_6,undefined8 param_7,undefined2 param_8,
               undefined2 param_9,undefined2 param_10,undefined2 param_11,undefined4 param_12)

{
  bpf_trace_run11(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
                  param_11,param_12);
  return;
}



//------------------------------------------------------------
// __bpf_trace_sched_boost_ux_kworker @ 00108594 size=32
// signature: undefined __bpf_trace_sched_boost_ux_kworker(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_sched_boost_ux_kworker(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  bpf_trace_run3(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_sched_wake_by_irq_kth @ 001085b8 size=28
// signature: undefined __bpf_trace_sched_wake_by_irq_kth(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_sched_wake_by_irq_kth(void)

{
  bpf_trace_run1();
  return;
}



//------------------------------------------------------------
// __bpf_trace_sched_percpu_rwsem_hold_time @ 001085d8 size=28
// signature: undefined __bpf_trace_sched_percpu_rwsem_hold_time(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_sched_percpu_rwsem_hold_time(void)

{
  bpf_trace_run2();
  return;
}



//------------------------------------------------------------
// __bpf_trace_sched_percpu_rwsem_starttime @ 001085f8 size=44
// signature: undefined __bpf_trace_sched_percpu_rwsem_starttime(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_sched_percpu_rwsem_starttime
               (undefined8 param_1,undefined8 param_2,undefined1 param_3,ulong param_4,
               undefined4 param_5,undefined4 param_6)

{
  bpf_trace_run5(param_1,param_2,param_3,param_4 & 1,param_5,param_6);
  return;
}



//------------------------------------------------------------
// __bpf_trace_binder_inherit_ux_type @ 00108628 size=36
// signature: undefined __bpf_trace_binder_inherit_ux_type(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_binder_inherit_ux_type
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,ulong param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4 & 1);
  return;
}



//------------------------------------------------------------
// __bpf_trace_binder_pick_best_thread @ 00108650 size=44
// signature: undefined __bpf_trace_binder_pick_best_thread(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_binder_pick_best_thread
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  bpf_trace_run5(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



//------------------------------------------------------------
// __bpf_trace_binder_nothread_be_select @ 00108680 size=36
// signature: undefined __bpf_trace_binder_nothread_be_select(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_binder_nothread_be_select
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,ulong param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4 & 1);
  return;
}



//------------------------------------------------------------
// __bpf_trace_binder_inherit_rt_prio @ 001086a8 size=28
// signature: undefined __bpf_trace_binder_inherit_rt_prio(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_binder_inherit_rt_prio(void)

{
  bpf_trace_run2();
  return;
}



//------------------------------------------------------------
// __bpf_trace_binder_inherit_rt_check @ 001086c8 size=40
// signature: undefined __bpf_trace_binder_inherit_rt_check(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_binder_inherit_rt_check
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  bpf_trace_run6(param_1,param_2,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// task_ux_type_set @ 001086f4 size=472
// signature: undefined task_ux_type_set(void)
// callers: [proc_ux_task_write]
//------------------------------------------------------------

void task_ux_type_set(undefined4 param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  undefined8 uVar6;
  undefined4 *puVar7;
  ulong uVar8;
  
  mutex_lock(ux_mutex);
  __rcu_read_lock();
  lVar5 = find_task_by_vpid(param_1);
  if (lVar5 == 0) {
    __rcu_read_unlock();
    goto LAB_00108890;
  }
  puVar1 = (uint *)(lVar5 + 0x40);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar2 = *puVar1;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar4) {
      *puVar1 = uVar2 + 1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (uVar2 == 0) {
    uVar6 = 2;
LAB_001087d4:
    refcount_warn_saturate(puVar1,uVar6);
    __rcu_read_unlock();
    if ((param_2 & 1) != 0) goto LAB_001087e4;
LAB_00108758:
    if ((param_2 >> 6 & 1) != 0) {
      puVar7 = &global_launcher_tgid;
      goto LAB_001087ec;
    }
    if ((param_2 >> 0x11 & 1) != 0) {
      puVar7 = &global_sysui_tgid;
      goto LAB_001087ec;
    }
    if ((param_2 >> 0xc & 1) != 0) {
      puVar7 = &global_sf_tgid;
      goto LAB_001087ec;
    }
    if ((param_2 >> 0xe & 1) != 0) {
      puVar7 = &global_audioapp_tgid;
      goto LAB_001087ec;
    }
    if ((param_2 >> 0x14 & 1) != 0) {
      puVar7 = &global_camera_tgid;
      goto LAB_001087ec;
    }
  }
  else {
    if ((int)(uVar2 + 1 | uVar2) < 0) {
      uVar6 = 1;
      goto LAB_001087d4;
    }
    __rcu_read_unlock();
    if ((param_2 & 1) == 0) goto LAB_00108758;
LAB_001087e4:
    puVar7 = &global_systemserver_tgid;
LAB_001087ec:
    *puVar7 = *(undefined4 *)(lVar5 + 0x634);
  }
  if (*(int *)(lVar5 + 0x630) != 0) {
    uVar8 = *(ulong *)(lVar5 + 0xdd8);
    if ((uVar8 == 0) || (0xfffffffffffff000 < uVar8)) {
      _printk(&DAT_00110a81);
    }
    else {
      *(uint *)(uVar8 + 0x2c) = *(uint *)(uVar8 + 0x2c) | param_2;
    }
  }
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar2 = *puVar1;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar4) {
      *puVar1 = uVar2 - 1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (uVar2 == 1) {
    DataMemoryBarrier(2,1);
    __put_task_struct(lVar5);
  }
  else if ((int)uVar2 < 1) {
    refcount_warn_saturate(puVar1,3);
  }
  if ((param_2 != 0x100) && ((moto_sched_debug & 1) != 0)) {
    __trace_bprintk(0x1088b0,task_ux_type_set_trace_printk_fmt,param_2,
                    *(undefined4 *)(lVar5 + 0x630));
  }
LAB_00108890:
  mutex_unlock(ux_mutex);
  return;
}



//------------------------------------------------------------
// task_ux_type_clear @ 001088ec size=424
// signature: undefined task_ux_type_clear(void)
// callers: [proc_ux_task_write]
//------------------------------------------------------------

void task_ux_type_clear(undefined4 param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  undefined8 uVar6;
  undefined4 *puVar7;
  ulong uVar8;
  
  mutex_lock(ux_mutex);
  __rcu_read_lock();
  lVar5 = find_task_by_vpid(param_1);
  if (lVar5 == 0) {
    __rcu_read_unlock();
    goto LAB_00108a58;
  }
  puVar1 = (uint *)(lVar5 + 0x40);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar2 = *puVar1;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar4) {
      *puVar1 = uVar2 + 1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (uVar2 == 0) {
    uVar6 = 2;
LAB_00108a08:
    refcount_warn_saturate(puVar1,uVar6);
    __rcu_read_unlock();
    if ((param_2 >> 0xe & 1) == 0) goto LAB_00108968;
LAB_00108950:
    puVar7 = &global_audioapp_tgid;
    if (global_audioapp_tgid != *(int *)(lVar5 + 0x634)) goto LAB_00108968;
LAB_00108974:
    *puVar7 = 0xffffffff;
  }
  else {
    if ((int)(uVar2 + 1 | uVar2) < 0) {
      uVar6 = 1;
      goto LAB_00108a08;
    }
    __rcu_read_unlock();
    if ((param_2 >> 0xe & 1) != 0) goto LAB_00108950;
LAB_00108968:
    if ((param_2 >> 0x14 & 1) != 0) {
      puVar7 = &global_camera_tgid;
      goto LAB_00108974;
    }
  }
  if (*(int *)(lVar5 + 0x630) != 0) {
    uVar8 = *(ulong *)(lVar5 + 0xdd8);
    if ((uVar8 == 0) || (0xfffffffffffff000 < uVar8)) {
      _printk(&DAT_00110a81);
    }
    else {
      *(uint *)(uVar8 + 0x2c) = *(uint *)(uVar8 + 0x2c) & (param_2 ^ 0xffffffff);
    }
  }
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar2 = *puVar1;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar4) {
      *puVar1 = uVar2 - 1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (uVar2 == 1) {
    DataMemoryBarrier(2,1);
    __put_task_struct(lVar5);
  }
  else if ((int)uVar2 < 1) {
    refcount_warn_saturate(puVar1,3);
  }
  if ((param_2 != 0x100) && ((moto_sched_debug & 1) != 0)) {
    __trace_bprintk(0x108a78,task_ux_type_clear_trace_printk_fmt,param_2,
                    *(undefined4 *)(lVar5 + 0x630));
  }
LAB_00108a58:
  mutex_unlock(ux_mutex);
  return;
}



//------------------------------------------------------------
// task_get_mvp_prio @ 00108ab4 size=984
// signature: undefined task_get_mvp_prio(void)
// callers: [binder_inherit_ux_type, rwsem_list_add, android_vh_binder_proc_transaction_finish, mutex_list_add_ux, android_vh_mutex_wait_start_handler, android_vh_rwsem_read_trylock_failed_handler, lock_inherit_ux_type, android_vh_percpu_rwsem_down_read_preempt_handler, android_rvh_pr_set_vma_name_bypass, lock_protect_update_starttime, android_vh_rwsem_wait_finish, android_vh_alter_mutex_list_add_handler, android_vh_rwsem_wake, android_vh_rwsem_record_rwsem_reader_owned, android_vh_rwsem_record_rwsem_writer_owned, binder_inherit_ux_type_from_client]
//------------------------------------------------------------

uint task_get_mvp_prio(long param_1,ulong param_2)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  uint uVar8;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x630) == 0)) {
LAB_00108b10:
    uVar8 = 0;
  }
  else {
    uVar7 = *(ulong *)(param_1 + 0xdd8);
    if ((uVar7 == 0) || (0xfffffffffffff000 < uVar7)) {
      _printk(&DAT_00110a81);
      goto LAB_00108b10;
    }
    uVar8 = *(uint *)(uVar7 + 0x2c);
  }
  uVar6 = *(uint *)(param_1 + 0x84);
  if ((int)uVar6 < 100) {
    return 0x3c;
  }
  if ((moto_sched_enabled >> 0xb & 1) == 0) {
LAB_00108b40:
    if ((param_1 != 0) &&
       ((((moto_sched_enabled >> 10 & 1) != 0 && (*(long *)(param_1 + 0x5a0) == 0)) &&
        (uVar6 == 100)))) {
      iVar3 = strncmp((char *)(param_1 + 0x848),"kworker/",8);
      if (iVar3 == 0) {
        iVar4 = strncmp((char *)(param_1 + 0x848),"kworker/u",9);
        iVar3 = global_launcher_tgid;
        if (iVar4 != 0) {
          uVar6 = 0;
          lVar2 = sp_el0;
          iVar4 = *(int *)(lVar2 + 0x84);
          iVar1 = *(int *)(lVar2 + 0x630);
          if ((lVar2 != 0) && (iVar1 != 0)) {
            uVar7 = *(ulong *)(lVar2 + 0xdd8);
            if ((uVar7 == 0) || (0xfffffffffffff000 < uVar7)) {
              _printk(&DAT_00110a81,iVar1);
              uVar6 = 0;
            }
            else {
              uVar6 = *(uint *)(uVar7 + 0x2c) & 8;
            }
          }
          if (*(int *)(lVar2 + 0x488) - 3U < 0xfffffffe) {
            if (uVar6 == 0) {
              uVar5 = 0x46;
              if (iVar1 != iVar3) {
                uVar5 = 0xffffffff;
              }
              uVar6 = 0x46;
              if ((*(long *)(lVar2 + 0xcd0) == 0 || iVar1 == iVar3) || 0x6e < iVar4) {
                uVar6 = uVar5;
              }
            }
            else {
              uVar6 = 0x4f;
            }
          }
          else {
            uVar6 = 0x46;
          }
          if (uVar6 != 0xffffffff) goto LAB_00108c50;
        }
      }
    }
  }
  else if (param_1 != 0) {
    if ((*(long *)(param_1 + 0x5a0) != 0) ||
       (lVar2 = sp_el0, (*(uint *)(lVar2 + 0x10) & 0xffff00) == 0)) goto LAB_00108b40;
    if (uVar6 < 0x79) {
      return 0x46;
    }
  }
  if ((uVar8 & 1) == 0) {
    if ((moto_sched_enabled >> 4 & 1) != 0) {
      if ((uVar8 >> 1 & 1) != 0) {
        uVar6 = 0x50;
        goto LAB_00108c50;
      }
      if ((uVar8 >> 0xd & 1) != 0) {
        iVar3 = *(int *)(param_1 + 0x84);
        uVar6 = 0x50;
        if (((iVar3 == 0x65) || (iVar3 == 0x68)) ||
           ((((((moto_sched_enabled >> 1 & 1) != 0 && ((moto_sched_scene & 3) != 0)) ||
              (((moto_sched_enabled >> 7 & 1) != 0 && ((moto_sched_scene >> 4 & 1) != 0)))) &&
             (iVar3 < 0x79)) && ((moto_sched_scene >> 2 & 1) != 0)))) goto LAB_00108c50;
      }
    }
    if ((uVar8 & 0xc0c) == 0) {
      if (((uVar8 & 0x70) == 0) && (*(int *)(param_1 + 0x630) != global_boost_pid)) {
        if (((moto_sched_enabled >> 6 & 1) == 0) || ((uVar8 >> 7 & 1) == 0)) {
          if ((uVar8 >> 0x18 & 1) == 0) {
            if (((uVar8 & 0x40100) == 0) &&
               ((*(int *)(param_1 + 0x634) != global_systemserver_tgid ||
                (*(int *)(param_1 + 0x84) != 0x69)))) {
              if (((param_2 & 1) == 0) || ((uVar8 & 0x80200) == 0)) {
                if ((((moto_sched_enabled >> 8 & 1) == 0) || ((uVar8 >> 0x15 & 1) == 0)) &&
                   ((uVar7 = task_in_ux_related_group(param_1), (uVar7 & 1) == 0 ||
                    ((moto_boost_prio < *(int *)(param_1 + 0x84) &&
                     (moto_boost_task_util <= *(ushort *)(param_1 + 0xc76))))))) {
                  uVar6 = 0xffffffff;
                }
                else {
                  uVar6 = 0x3c;
                }
              }
              else {
                uVar7 = get_moto_task_struct(param_1);
                uVar6 = 0x3c;
                if (((uVar7 != 0) && (uVar7 < 0xfffffffffffff001)) &&
                   (uVar6 = (uint)*(byte *)(uVar7 + 0x2b), *(byte *)(uVar7 + 0x2b) < 0x3d)) {
                  uVar6 = 0x3c;
                }
              }
            }
            else {
              uVar6 = 0x4e;
            }
          }
          else {
            uVar6 = 0x47;
          }
        }
        else {
          uVar6 = 0x41;
        }
      }
      else {
        uVar6 = 0x46;
      }
    }
    else {
      uVar6 = 0x4f;
    }
  }
  else {
    uVar6 = 100;
  }
LAB_00108c50:
  if (((byte)moto_sched_debug & 1) != 0) {
    __trace_bprintk(0x108e18,task_get_mvp_prio_trace_printk_fmt,*(undefined4 *)(param_1 + 0x630),
                    *(undefined4 *)(param_1 + 0x634),*(undefined4 *)(param_1 + 0x84),
                    moto_sched_scene,uVar8,*(undefined2 *)(param_1 + 0xc76),uVar6);
  }
  return uVar6;
}



//------------------------------------------------------------
// task_get_ux_type @ 001090dc size=76
// signature: undefined task_get_ux_type(void)
// callers: [binder_ux_type_set]
//------------------------------------------------------------

undefined4 task_get_ux_type(long param_1)

{
  ulong uVar1;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x630) != 0)) {
    uVar1 = *(ulong *)(param_1 + 0xdd8);
    if ((uVar1 != 0) && (uVar1 < 0xfffffffffffff001)) {
      return *(undefined4 *)(uVar1 + 0x2c);
    }
    _printk(&DAT_00110a81);
  }
  return 0;
}



//------------------------------------------------------------
// get_moto_task_struct @ 00109128 size=68
// signature: undefined get_moto_task_struct(void)
// callers: [task_get_mvp_prio]
//------------------------------------------------------------

ulong get_moto_task_struct(long param_1)

{
  ulong uVar1;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x630) != 0)) {
    uVar1 = *(ulong *)(param_1 + 0xdd8);
    if ((uVar1 != 0) && (uVar1 < 0xfffffffffffff001)) {
      return uVar1;
    }
    _printk(&DAT_00110a81);
  }
  return 0;
}



//------------------------------------------------------------
// task_in_ux_related_group @ 0010916c size=440
// signature: undefined task_in_ux_related_group(void)
// callers: [task_get_mvp_prio]
//------------------------------------------------------------

undefined8 task_in_ux_related_group(long param_1)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x630) == 0)) {
LAB_001091b0:
    uVar2 = 0;
  }
  else {
    uVar3 = *(ulong *)(param_1 + 0xdd8);
    if ((uVar3 == 0) || (0xfffffffffffff000 < uVar3)) {
      _printk(&DAT_00110a81);
      goto LAB_001091b0;
    }
    uVar2 = *(uint *)(uVar3 + 0x2c);
  }
  if (((moto_sched_enabled >> 4 & 1) == 0) || (((byte)moto_sched_scene >> 2 & 1) == 0)) {
    if ((((moto_sched_enabled >> 5 & 1) != 0) && (((byte)moto_sched_scene >> 3 & 1) != 0)) &&
       ((*(int *)(param_1 + 0x634) == global_camera_tgid || ((uVar2 >> 0x10 & 1) != 0)))) {
      if (*(int *)(param_1 + 0x84) < 0x78) {
        return 1;
      }
      if ((uVar2 >> 0x11 & 1) != 0) {
        return 1;
      }
      goto LAB_00109234;
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0x84);
    if (((uVar2 >> 0xd & 1) != 0) && (iVar1 < 0x79)) {
      return 1;
    }
    if (iVar1 == 0x65) {
      return 1;
    }
    if (iVar1 == 0x68) {
      return 1;
    }
  }
  if ((uVar2 >> 0x11 & 1) != 0) {
    return 1;
  }
LAB_00109234:
  if ((((moto_sched_enabled >> 1 & 1) != 0) && ((moto_sched_scene & 3) != 0)) ||
     (((moto_sched_enabled >> 7 & 1) != 0 && ((moto_sched_scene >> 4 & 1) != 0)))) {
    if ((((moto_sched_enabled >> 4 & 1) != 0) && ((moto_sched_scene >> 2 & 1) != 0)) &&
       (*(int *)(param_1 + 0x634) == global_audioapp_tgid)) {
      return 1;
    }
    if (((uVar2 >> 0xf & 1) != 0) && (*(int *)(param_1 + 0x84) < 0x79)) {
      return 1;
    }
    if ((*(long *)(param_1 + 0x5a0) == 0) && (*(int *)(param_1 + 0x84) == 100)) {
      return 1;
    }
    iVar1 = *(int *)(param_1 + 0x634);
    if (iVar1 == global_launcher_tgid) {
      return 1;
    }
    if (iVar1 == global_systemserver_tgid) {
      return 1;
    }
    if (iVar1 == global_sysui_tgid) {
      return 1;
    }
    if (iVar1 == global_sf_tgid) {
      return 1;
    }
    if (*(long *)(param_1 + 0xcd0) != 0) {
      return 1;
    }
  }
  if ((moto_boost_prio < *(int *)(param_1 + 0x84)) || (*(long *)(param_1 + 0xcd0) == 0)) {
    return 0;
  }
  return 1;
}



//------------------------------------------------------------
// task_get_mvp_limit @ 00109328 size=264
// signature: undefined task_get_mvp_limit(void)
// callers: []
//------------------------------------------------------------

undefined4 task_get_mvp_limit(long param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if ((moto_sched_scene & 1) == 0) {
    if ((char)moto_sched_enabled < '\0') {
      uVar4 = moto_sched_scene >> 4 & 1;
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 1;
  }
  if ((param_2 & 0xfffffffe) == 0x46) {
    uVar2 = 3000000000;
    if (uVar4 == 0) {
      uVar2 = 120000000;
    }
    return uVar2;
  }
  uVar2 = 3000000000;
  uVar3 = 3000000000;
  if (param_2 != 0x45) {
    if ((param_2 == 0x4e) || (iVar1 = *(int *)(param_1 + 0x634), iVar1 == global_systemserver_tgid))
    {
      if (uVar4 == 0) {
        uVar2 = 36000000;
      }
      return uVar2;
    }
    if ((((iVar1 == global_launcher_tgid) || (iVar1 == global_sysui_tgid)) ||
        (iVar1 == global_boost_pid)) || (*(long *)(param_1 + 0xcd0) != 0)) {
      if (uVar4 == 0) {
        uVar2 = 24000000;
      }
      return uVar2;
    }
    if (param_2 != 0x41) {
      if (uVar4 == 0) {
        uVar2 = 12000000;
      }
      uVar3 = 0;
      if (-1 < (int)param_2) {
        uVar3 = uVar2;
      }
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// binder_inherit_ux_type @ 00109434 size=428
// signature: undefined binder_inherit_ux_type(void)
// callers: [android_vh_binder_proc_transaction_finish]
//------------------------------------------------------------

void binder_inherit_ux_type(long param_1)

{
  long lVar1;
  int iVar2;
  bool bVar3;
  ulong uVar4;
  
  if (((byte)moto_sched_enabled >> 3 & 1) == 0) goto LAB_0010957c;
  lVar1 = sp_el0;
  iVar2 = task_get_mvp_prio(lVar1,1);
  if (iVar2 < 0x3c) goto LAB_0010957c;
  if ((param_1 == 0) || (*(int *)(param_1 + 0x630) == 0)) {
LAB_00109498:
    uVar4 = 0;
  }
  else {
    uVar4 = *(ulong *)(param_1 + 0xdd8);
    if ((uVar4 == 0) || (0xfffffffffffff000 < uVar4)) {
      _printk(&DAT_00110a81);
      goto LAB_00109498;
    }
  }
  if (*(int *)(lVar1 + 0x488) - 3U < 0xfffffffe) {
    iVar2 = task_get_mvp_prio(lVar1,1);
  }
  else {
    iVar2 = 100;
  }
  bVar3 = false;
  if ((uVar4 != 0) && (bVar3 = false, uVar4 < 0xfffffffffffff001)) {
    if ((int)(uint)*(byte *)(uVar4 + 0x2b) < iVar2) {
      bVar3 = true;
      *(char *)(uVar4 + 0x2b) = (char)iVar2;
    }
    else {
      bVar3 = false;
    }
  }
  if ((param_1 != 0) && (*(int *)(param_1 + 0x630) != 0)) {
    uVar4 = *(ulong *)(param_1 + 0xdd8);
    if ((uVar4 == 0) || (0xfffffffffffff000 < uVar4)) {
      _printk(&DAT_00110a81);
      if (*(int *)(param_1 + 0x630) != 0) goto LAB_00109514;
    }
    else if ((*(byte *)(uVar4 + 0x2d) >> 1 & 1) == 0) {
LAB_00109514:
      uVar4 = *(ulong *)(param_1 + 0xdd8);
      if ((uVar4 == 0) || (0xfffffffffffff000 < uVar4)) {
        _printk(&DAT_00110a81);
        iVar2 = *(int *)(param_1 + 0x630);
      }
      else {
        *(uint *)(uVar4 + 0x2c) = *(uint *)(uVar4 + 0x2c) | 0x200;
        if ((int)(uint)*(byte *)(uVar4 + 0x2b) < iVar2) {
          *(char *)(uVar4 + 0x2b) = (char)iVar2;
        }
        iVar2 = *(int *)(param_1 + 0x630);
      }
      if ((iVar2 != 0) &&
         ((*(ulong *)(param_1 + 0xdd8) == 0 || (0xfffffffffffff000 < *(ulong *)(param_1 + 0xdd8)))))
      {
        _printk(&DAT_00110a81);
      }
    }
    else if (!bVar3) goto LAB_0010957c;
  }
  resched_task(param_1,1);
LAB_0010957c:
  msched_uclamp_binder_set_priority_hook(param_1);
  return;
}



//------------------------------------------------------------
// task_has_ux_type @ 0010967c size=88
// signature: undefined task_has_ux_type(void)
// callers: [lock_protect_update_starttime]
//------------------------------------------------------------

bool task_has_ux_type(long param_1,uint param_2)

{
  ulong uVar1;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x630) != 0)) {
    uVar1 = *(ulong *)(param_1 + 0xdd8);
    if ((uVar1 != 0) && (uVar1 < 0xfffffffffffff001)) {
      return (*(uint *)(uVar1 + 0x2c) & param_2) != 0;
    }
    _printk(&DAT_00110a81,*(int *)(param_1 + 0x630));
  }
  return false;
}



//------------------------------------------------------------
// resched_task @ 001096d8 size=612
// signature: undefined resched_task(void)
// callers: [binder_inherit_ux_type, binder_inherit_ux_type_from_client, lock_inherit_ux_type, lock_clear_inherited_ux_type, lock_protect_update_starttime]
//------------------------------------------------------------

void resched_task(long param_1,ulong param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  long lVar6;
  undefined8 uVar7;
  code *pcVar8;
  long lVar9;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  local_58 = 0;
  local_50 = 0;
  if ((param_1 == 0) || ((*(int *)(param_1 + 0x488) != 3 && (*(int *)(param_1 + 0x488) != 0))))
  goto LAB_00109910;
  puVar1 = (uint *)(param_1 + 0x40);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar3 = *puVar1;
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar5) {
      *puVar1 = uVar3 + 1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  if (uVar3 == 0) {
    uVar7 = 2;
LAB_001098dc:
    refcount_warn_saturate(puVar1,uVar7);
  }
  else if ((int)(uVar3 + 1 | uVar3) < 0) {
    uVar7 = 1;
    goto LAB_001098dc;
  }
  lVar6 = task_rq_lock(param_1,&local_58);
  update_rq_clock();
  iVar2 = *(int *)(param_1 + 0x80);
  lVar9 = *(long *)(lVar6 + 0xaa0);
  if (iVar2 == 1) {
    deactivate_task(lVar6,param_1,10);
  }
  if (lVar9 == param_1) {
    if (*(long *)(lVar6 + 0xaa0) != param_1) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x800,0x1098bc);
      (*pcVar8)();
    }
    pcVar8 = *(code **)(*(long *)(param_1 + 0x340) + 0x38);
    if (*(int *)(pcVar8 + -4) != 0x7d2d01f9) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x109800);
      (*pcVar8)();
    }
    (*pcVar8)(lVar6,param_1);
  }
  if (iVar2 == 1) {
    activate_task(lVar6,param_1,10);
  }
  if (lVar9 == param_1) {
    pcVar8 = *(code **)(*(long *)(param_1 + 0x340) + 0x40);
    if (*(int *)(pcVar8 + -4) != 0x1fc33130) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x109850);
      (*pcVar8)();
    }
    (*pcVar8)(lVar6,param_1,0);
  }
  if ((*(int *)(param_1 + 0x80) == 1) && (*(int *)(lVar6 + 0x210) != 1)) {
    if (*(long *)(lVar6 + 0xaa0) == param_1) {
      if ((param_2 & 1) == 0) {
        resched_curr(lVar6);
      }
    }
    else {
      check_preempt_curr(lVar6,param_1,0);
    }
  }
  if (2 < *(uint *)(lVar6 + 0xac8)) {
    local_50 = CONCAT44(local_50._4_4_,4);
  }
  raw_spin_rq_unlock(lVar6);
  _raw_spin_unlock_irqrestore(param_1 + 0x924,local_58);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar3 = *puVar1;
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar5) {
      *puVar1 = uVar3 - 1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  if (uVar3 == 1) {
    DataMemoryBarrier(2,1);
    __put_task_struct(param_1);
  }
  else if ((int)uVar3 < 1) {
    refcount_warn_saturate(puVar1,3);
  }
LAB_00109910:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_1 != 0);
  }
  return;
}



//------------------------------------------------------------
// binder_inherit_ux_type_from_client @ 00109960 size=320
// signature: undefined binder_inherit_ux_type_from_client(void)
// callers: [binder_inherit_boost]
//------------------------------------------------------------

void binder_inherit_ux_type_from_client(long param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  
  if (((byte)moto_sched_enabled >> 3 & 1) != 0) {
    if ((param_1 != 0) && (*(int *)(param_1 + 0x630) != 0)) {
      uVar2 = *(ulong *)(param_1 + 0xdd8);
      if ((uVar2 == 0) || (0xfffffffffffff000 < uVar2)) {
        _printk(&DAT_00110a81);
      }
      else if ((*(byte *)(uVar2 + 0x2d) >> 1 & 1) != 0) {
        return;
      }
    }
    iVar1 = task_get_mvp_prio(param_2,1);
    if (0x3b < iVar1) {
      if (*(int *)(param_2 + 0x488) - 3U < 0xfffffffe) {
        iVar1 = task_get_mvp_prio(param_2,1);
      }
      else {
        iVar1 = 100;
      }
      if (param_1 == 0) {
        resched_task(0,1);
      }
      else {
        if (*(int *)(param_1 + 0x630) != 0) {
          uVar2 = *(ulong *)(param_1 + 0xdd8);
          if ((uVar2 == 0) || (0xfffffffffffff000 < uVar2)) {
            _printk(&DAT_00110a81);
          }
          else {
            *(uint *)(uVar2 + 0x2c) = *(uint *)(uVar2 + 0x2c) | 0x200;
            if ((int)(uint)*(byte *)(uVar2 + 0x2b) < iVar1) {
              *(char *)(uVar2 + 0x2b) = (char)iVar1;
            }
          }
        }
        resched_task(param_1,1);
        if ((*(int *)(param_1 + 0x630) != 0) &&
           ((*(ulong *)(param_1 + 0xdd8) == 0 || (0xfffffffffffff000 < *(ulong *)(param_1 + 0xdd8)))
           )) {
          _printk(&DAT_00110a81);
        }
      }
    }
  }
  return;
}



//------------------------------------------------------------
// binder_inherit_rt_prio @ 00109b44 size=252
// signature: undefined binder_inherit_rt_prio(void)
// callers: [binder_inherit_boost]
//------------------------------------------------------------

void binder_inherit_rt_prio(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  int local_40 [2];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if ((((((byte)moto_sched_enabled >> 3 & 1) == 0) || (*(long *)(param_1 + 0x20) == 0)) ||
      (global_sf_tgid != *(int *)(param_1 + 0x2c))) ||
     ((0xfffffffd < *(int *)(param_2 + 0x488) - 3U ||
      (*(int *)(param_2 + 0x84) <= *(int *)(param_1 + 0x6c))))) {
    uVar2 = 0;
  }
  else {
    local_40[0] = 99 - *(int *)(param_1 + 0x6c);
    sched_setscheduler_nocheck(param_2,*(uint *)(param_1 + 0x68) | 0x40000000,local_40);
    uVar2 = 1;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// trace_binder_inherit_rt_prio @ 00109d14 size=44
// signature: undefined trace_binder_inherit_rt_prio(void)
// callers: []
//------------------------------------------------------------

void trace_binder_inherit_rt_prio(void)

{
  return;
}



//------------------------------------------------------------
// binder_inherit_boost @ 00109de0 size=76
// signature: undefined binder_inherit_boost(void)
// callers: []
//------------------------------------------------------------

void binder_inherit_boost(long param_1,undefined8 param_2)

{
  ulong uVar1;
  
  if ((((param_1 != 0) && (uVar1 = binder_inherit_rt_prio(), (uVar1 & 1) == 0)) &&
      (*(long *)(param_1 + 0x20) != 0)) && (*(long *)(*(long *)(param_1 + 0x20) + 0x1a8) != 0)) {
    binder_inherit_ux_type_from_client(param_2);
  }
  return;
}



//------------------------------------------------------------
// binder_clear_inherited_ux_type @ 00109e30 size=228
// signature: undefined binder_clear_inherited_ux_type(void)
// callers: []
//------------------------------------------------------------

void binder_clear_inherited_ux_type(long param_1)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  
  if (((param_1 != 0) && ((moto_sched_enabled >> 3 & 1) != 0)) && (*(int *)(param_1 + 0x630) != 0))
  {
    uVar3 = *(ulong *)(param_1 + 0xdd8);
    if ((uVar3 == 0) || (0xfffffffffffff000 < uVar3)) {
      _printk(&DAT_00110a81);
    }
    else if ((*(byte *)(uVar3 + 0x2d) >> 1 & 1) != 0) {
      uVar3 = *(ulong *)(param_1 + 0xdd8);
      if ((uVar3 == 0) || (0xfffffffffffff000 < uVar3)) {
        _printk(&DAT_00110a81);
        iVar2 = *(int *)(param_1 + 0x630);
      }
      else {
        uVar1 = *(uint *)(uVar3 + 0x2c);
        *(uint *)(uVar3 + 0x2c) = uVar1 & 0xfffffdff;
        if ((uVar1 >> 0x13 & 1) == 0) {
          *(undefined1 *)(uVar3 + 0x2b) = 0;
        }
        iVar2 = *(int *)(param_1 + 0x630);
      }
      if ((iVar2 != 0) &&
         ((*(ulong *)(param_1 + 0xdd8) == 0 || (0xfffffffffffff000 < *(ulong *)(param_1 + 0xdd8)))))
      {
        _printk(&DAT_00110a81);
      }
    }
  }
  msched_uclamp_binder_restore_priority_hook(param_1);
  return;
}



//------------------------------------------------------------
// queue_ux_task @ 00109fbc size=620
// signature: undefined queue_ux_task(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void queue_ux_task(undefined8 param_1,long param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined *puVar5;
  ulong uVar6;
  ulong uVar7;
  
  if (param_2 == 0) {
    return;
  }
  if (param_3 != 0) {
    return;
  }
  if ((moto_sched_enabled >> 2 & 1) == 0) {
    return;
  }
  if (*(int *)(param_2 + 0x630) == 0) {
    return;
  }
  uVar7 = *(ulong *)(param_2 + 0xdd8);
  if ((uVar7 == 0) || (0xfffffffffffff000 < uVar7)) goto LAB_0010a124;
  uVar6 = *(ulong *)(param_2 + 0xdd8);
  if ((uVar6 == 0) || (0xfffffffffffff000 < uVar6)) {
LAB_0010a08c:
    _printk(&DAT_00110a81);
  }
  else if (((*(byte *)(uVar6 + 0x2e) >> 3 & 1) != 0) &&
          (uVar6 = jiffies_to_usecs(_jiffies), puVar5 = queue_ux_task_trace_printk_fmt,
          64000000 < (uVar6 & 0xffffffff) * 1000 - *(long *)(uVar7 + 0x30))) {
    if (((byte)moto_sched_debug & 1) == 0) {
      iVar1 = *(int *)(param_2 + 0x630);
    }
    else {
      uVar3 = *(undefined4 *)(param_2 + 0x630);
      uVar4 = *(undefined4 *)(uVar7 + 0x2c);
      uVar6 = jiffies_to_usecs(_jiffies);
      __trace_bprintk(0x10a148,puVar5,"dequeue task",uVar3,uVar4,
                      ((uVar6 & 0xffffffff) * 1000 - *(long *)(uVar7 + 0x30)) / 1000000);
      iVar1 = *(int *)(param_2 + 0x630);
    }
    if (iVar1 == 0) {
      return;
    }
    uVar6 = *(ulong *)(param_2 + 0xdd8);
    if ((uVar6 == 0) || (0xfffffffffffff000 < uVar6)) goto LAB_0010a08c;
    uVar2 = *(uint *)(uVar6 + 0x2c);
    *(undefined1 *)(uVar6 + 0x28) = 0;
    *(undefined8 *)(uVar6 + 0x30) = 0;
    *(uint *)(uVar6 + 0x2c) = uVar2 & 0xfff7ffff;
    if ((uVar2 >> 9 & 1) == 0) {
      *(undefined1 *)(uVar6 + 0x2b) = 0;
    }
  }
  if (*(int *)(param_2 + 0x630) == 0) {
    return;
  }
  uVar6 = *(ulong *)(param_2 + 0xdd8);
  if ((uVar6 != 0) && (uVar6 < 0xfffffffffffff001)) {
    if ((*(byte *)(uVar6 + 0x2e) >> 5 & 1) == 0) {
      return;
    }
    uVar6 = jiffies_to_usecs(_jiffies);
    puVar5 = queue_ux_task_trace_printk_fmt_11;
    if ((uVar6 & 0xffffffff) * 1000 - *(long *)(uVar7 + 0x38) < 0x3d09001) {
      return;
    }
    if (((byte)moto_sched_debug & 1) != 0) {
      uVar3 = *(undefined4 *)(param_2 + 0x630);
      uVar4 = *(undefined4 *)(uVar7 + 0x2c);
      uVar6 = jiffies_to_usecs(_jiffies);
      __trace_bprintk(0x10a1b8,puVar5,"dequeue task",uVar3,uVar4,
                      ((uVar6 & 0xffffffff) * 1000 - *(long *)(uVar7 + 0x30)) / 1000000);
    }
    *(undefined1 *)(uVar7 + 0x29) = 0;
    *(undefined8 *)(uVar7 + 0x38) = 0xffffffffffffffff;
    if (*(int *)(param_2 + 0x630) == 0) {
      return;
    }
    uVar7 = *(ulong *)(param_2 + 0xdd8);
    if ((uVar7 != 0) && (uVar7 < 0xfffffffffffff001)) {
      *(uint *)(uVar7 + 0x2c) = *(uint *)(uVar7 + 0x2c) & 0xffdfffff;
      return;
    }
  }
LAB_0010a124:
  _printk(&DAT_00110a81);
  return;
}



//------------------------------------------------------------
// binder_ux_type_set @ 0010a22c size=492
// signature: undefined binder_ux_type_set(void)
// callers: [android_vh_binder_proc_transaction_finish]
//------------------------------------------------------------

void binder_ux_type_set(long param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  long lVar7;
  undefined *puVar8;
  bool bVar9;
  undefined4 uVar10;
  ulong uVar11;
  uint uVar12;
  
  if (param_1 == 0) {
    return;
  }
  lVar7 = sp_el0;
  iVar1 = *(int *)(lVar7 + 0x634);
  bVar9 = (iVar1 == global_launcher_tgid || iVar1 == global_sysui_tgid) ||
          iVar1 == global_systemserver_tgid;
  if (((((bVar9) || (iVar1 == global_boost_pid)) || (*(long *)(lVar7 + 0xcd0) != 0)) &&
      (*(int *)(*(long *)(param_1 + 0x670) + 0x84) < 100)) ||
     (((*(int *)(*(long *)(lVar7 + 0x670) + 0x84) < 100 &&
       ((((iVar2 = *(int *)(param_1 + 0x634), iVar2 == global_launcher_tgid ||
          (iVar2 == global_sysui_tgid)) ||
         ((iVar2 == global_systemserver_tgid ||
          ((iVar2 == global_boost_pid || (*(long *)(param_1 + 0xcd0) != 0)))))) ||
        (*(int *)(*(long *)(param_1 + 0x670) + 0x84) < 100)))) ||
      ((((bVar9 || (iVar1 == global_boost_pid)) || (*(long *)(lVar7 + 0xcd0) != 0)) &&
       (((iVar1 = *(int *)(param_1 + 0x634), iVar1 == global_launcher_tgid ||
         (iVar1 == global_sysui_tgid)) ||
        ((iVar1 == global_systemserver_tgid ||
         ((iVar1 == global_boost_pid || (*(long *)(param_1 + 0xcd0) != 0)))))))))))) {
    if (*(int *)(param_1 + 0x630) == 0) goto LAB_0010a2cc;
    uVar11 = *(ulong *)(param_1 + 0xdd8);
    if ((uVar11 == 0) || (0xfffffffffffff000 < uVar11)) goto LAB_0010a3b8;
    uVar12 = *(uint *)(uVar11 + 0x2c) | 0x400;
  }
  else {
    if (*(int *)(param_1 + 0x630) == 0) goto LAB_0010a2cc;
    uVar11 = *(ulong *)(param_1 + 0xdd8);
    if ((uVar11 == 0) || (0xfffffffffffff000 < uVar11)) {
LAB_0010a3b8:
      _printk(&DAT_00110a81);
      goto LAB_0010a2cc;
    }
    uVar12 = *(uint *)(uVar11 + 0x2c) & 0xfffffbff;
  }
  *(uint *)(uVar11 + 0x2c) = uVar12;
LAB_0010a2cc:
  puVar8 = binder_ux_type_set_trace_printk_fmt;
  if (((byte)moto_sched_debug & 1) != 0) {
    uVar3 = *(undefined4 *)(lVar7 + 0x634);
    uVar4 = *(undefined4 *)(*(long *)(lVar7 + 0x670) + 0x84);
    uVar5 = *(undefined4 *)(param_1 + 0x634);
    uVar6 = *(undefined4 *)(*(long *)(param_1 + 0x670) + 0x84);
    uVar10 = task_get_ux_type(param_1);
    __trace_bprintk(0x10a3c8,puVar8,uVar3,uVar4,uVar5,uVar6,uVar10);
  }
  return;
}



//------------------------------------------------------------
// lock_inherit_ux_type @ 0010a41c size=480
// signature: undefined lock_inherit_ux_type(void)
// callers: [android_vh_rwsem_wake, android_vh_rwsem_record_rwsem_reader_owned, android_vh_rwsem_record_rwsem_writer_owned, android_vh_mutex_wait_start_handler]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint lock_inherit_ux_type(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  char cVar7;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_58 = 0;
  local_50 = 0;
  if (((param_1 == 0) || (param_2 == 0)) || (0xfffffffd < *(int *)(param_1 + 0x488) - 3U)) {
LAB_0010a4fc:
    uVar3 = 0;
    goto LAB_0010a500;
  }
  if (*(int *)(param_2 + 0x630) != 0) {
    uVar6 = *(ulong *)(param_2 + 0xdd8);
    if ((uVar6 == 0) || (0xfffffffffffff000 < uVar6)) {
      _printk(&DAT_00110a81,*(int *)(param_2 + 0x630));
    }
    else if (4 < *(byte *)(uVar6 + 0x28)) goto LAB_0010a4fc;
  }
  lVar4 = task_rq_lock(param_1,&local_58);
  if (*(int *)(param_2 + 0x630) == 0) {
LAB_0010a588:
    cVar7 = '\x01';
  }
  else {
    uVar6 = *(ulong *)(param_2 + 0xdd8);
    if ((uVar6 == 0) || (0xfffffffffffff000 < uVar6)) {
      _printk(&DAT_00110a81);
      goto LAB_0010a588;
    }
    cVar7 = *(char *)(uVar6 + 0x28) + '\x01';
  }
  if (*(int *)(param_2 + 0x488) - 3U < 0xfffffffe) {
    iVar2 = task_get_mvp_prio(param_2,1);
    iVar1 = *(int *)(param_1 + 0x630);
  }
  else {
    iVar2 = 100;
    iVar1 = *(int *)(param_1 + 0x630);
  }
  if (iVar1 != 0) {
    uVar6 = *(ulong *)(param_1 + 0xdd8);
    if ((uVar6 == 0) || (0xfffffffffffff000 < uVar6)) {
      _printk(&DAT_00110a81);
    }
    else {
      *(uint *)(uVar6 + 0x2c) = *(uint *)(uVar6 + 0x2c) | 0x80000;
      uVar5 = jiffies_to_usecs(_jiffies);
      *(char *)(uVar6 + 0x28) = cVar7;
      *(ulong *)(uVar6 + 0x30) = (uVar5 & 0xffffffff) * 1000;
      if ((int)(uint)*(byte *)(uVar6 + 0x2b) < iVar2) {
        *(char *)(uVar6 + 0x2b) = (char)iVar2;
      }
    }
  }
  if (2 < *(uint *)(lVar4 + 0xac8)) {
    local_50 = CONCAT44(local_50._4_4_,4);
  }
  raw_spin_rq_unlock(lVar4);
  _raw_spin_unlock_irqrestore(param_1 + 0x924,local_58);
  uVar3 = resched_task(param_1,1);
LAB_0010a500:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3 & 1;
}



//------------------------------------------------------------
// lock_clear_inherited_ux_type @ 0010a750 size=468
// signature: undefined lock_clear_inherited_ux_type(void)
// callers: [android_vh_mutex_wait_start_handler, android_vh_mutex_unlock_slowpath_handler, android_vh_rwsem_wake_finish_handler]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint lock_clear_inherited_ux_type(long param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined *puVar4;
  uint uVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_68 = 0;
  local_60 = 0;
  uVar5 = 0;
  if (param_1 != 0) {
    if ((*(int *)(param_1 + 0x488) - 3U < 0xfffffffe) && (*(int *)(param_1 + 0x630) != 0)) {
      uVar8 = *(ulong *)(param_1 + 0xdd8);
      if ((uVar8 == 0) ||
         (((0xfffffffffffff000 < uVar8 || (uVar7 = *(ulong *)(param_1 + 0xdd8), uVar7 == 0)) ||
          (0xfffffffffffff000 < uVar7)))) {
        _printk(&DAT_00110a81);
      }
      else if ((*(byte *)(uVar7 + 0x2e) >> 3 & 1) != 0) {
        lVar6 = task_rq_lock(param_1,&local_68);
        puVar4 = lock_clear_inherited_ux_type_trace_printk_fmt;
        if (((byte)moto_sched_debug & 1) == 0) {
          iVar1 = *(int *)(param_1 + 0x630);
        }
        else {
          uVar2 = *(undefined4 *)(param_1 + 0x630);
          uVar3 = *(undefined4 *)(uVar8 + 0x2c);
          uVar7 = jiffies_to_usecs(_jiffies);
          __trace_bprintk(0x10a8b0,puVar4,param_2,uVar2,uVar3,
                          ((uVar7 & 0xffffffff) * 1000 - *(long *)(uVar8 + 0x30)) / 1000000);
          iVar1 = *(int *)(param_1 + 0x630);
        }
        if (iVar1 != 0) {
          uVar8 = *(ulong *)(param_1 + 0xdd8);
          if ((uVar8 == 0) || (0xfffffffffffff000 < uVar8)) {
            _printk(&DAT_00110a81);
          }
          else {
            uVar5 = *(uint *)(uVar8 + 0x2c);
            *(undefined1 *)(uVar8 + 0x28) = 0;
            *(undefined8 *)(uVar8 + 0x30) = 0;
            *(uint *)(uVar8 + 0x2c) = uVar5 & 0xfff7ffff;
            if ((uVar5 >> 9 & 1) == 0) {
              *(undefined1 *)(uVar8 + 0x2b) = 0;
            }
          }
        }
        if (2 < *(uint *)(lVar6 + 0xac8)) {
          local_60 = CONCAT44(local_60._4_4_,4);
        }
        raw_spin_rq_unlock(lVar6);
        _raw_spin_unlock_irqrestore(param_1 + 0x924,local_68);
        uVar5 = resched_task(param_1,0);
        goto LAB_0010a868;
      }
    }
    uVar5 = 0;
  }
LAB_0010a868:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5 & 1;
}



//------------------------------------------------------------
// lock_protect_update_starttime @ 0010a994 size=836
// signature: undefined lock_protect_update_starttime(void)
// callers: [android_vh_record_pcpu_rwsem_time_early]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lock_protect_update_starttime(long param_1,long param_2,undefined8 param_3)

{
  char cVar1;
  ulong uVar2;
  ulong uVar3;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x630) == 0)) {
LAB_0010a9e0:
    uVar3 = 0;
  }
  else {
    uVar3 = *(ulong *)(param_1 + 0xdd8);
    if ((uVar3 == 0) || (0xfffffffffffff000 < uVar3)) {
      _printk(&DAT_00110a81);
      goto LAB_0010a9e0;
    }
  }
  if ((locking_inited == '\0' || param_1 == 0) || uVar3 == 0) {
    return;
  }
  if (0xfffffffffffff000 < uVar3) {
    return;
  }
  if (((byte)moto_sched_debug >> 1 & 1) == 0) {
    if (param_2 == 0) {
LAB_0010ab9c:
      if (*(char *)(uVar3 + 0x29) == '\0') {
        if (((byte)moto_sched_debug & 1) == 0) {
          return;
        }
        __trace_bprintk(0x10ac08,lock_protect_update_starttime_trace_printk_fmt_30,param_3,0);
        return;
      }
      *(char *)(uVar3 + 0x29) = *(char *)(uVar3 + 0x29) + -1;
      if (*(char *)(uVar3 + 0x29) != '\0') {
        return;
      }
      if (*(int *)(param_1 + 0x630) != 0) {
        uVar3 = *(ulong *)(param_1 + 0xdd8);
        if ((uVar3 == 0) || (0xfffffffffffff000 < uVar3)) {
          _printk(&DAT_00110a81);
        }
        else {
          *(uint *)(uVar3 + 0x2c) = *(uint *)(uVar3 + 0x2c) & 0xffdfffff;
        }
        if ((*(int *)(param_1 + 0x630) != 0) &&
           ((*(ulong *)(param_1 + 0xdd8) == 0 || (0xfffffffffffff000 < *(ulong *)(param_1 + 0xdd8)))
           )) {
          _printk(&DAT_00110a81);
        }
      }
      task_get_mvp_prio(param_1,1);
      resched_task(param_1,0);
      return;
    }
  }
  else {
    if (param_2 == 0) {
      if (*(byte *)(uVar3 + 0x29) == 0) {
        _printk(&DAT_0011082b,param_3,0);
      }
      uVar2 = task_has_ux_type(param_1,0x200000);
      if ((uVar2 & 1) == 0) {
        _printk(&DAT_001112b9);
      }
      else {
        uVar2 = jiffies_to_usecs(_jiffies);
        uVar2 = (uVar2 & 0xffffffff) * 1000 - *(long *)(uVar3 + 0x38);
        if (40999999 < uVar2) {
          __trace_bprintk(0x10ab48,lock_protect_update_starttime_trace_printk_fmt,param_3,
                          *(undefined4 *)(param_1 + 0x84),*(undefined1 *)(uVar3 + 0x29),
                          uVar2 / 1000000);
          if ((100999999 < uVar2) &&
             (_printk(&DAT_001109eb,param_3,*(undefined4 *)(param_1 + 0x84),
                      *(undefined1 *)(uVar3 + 0x29),uVar2 / 1000000), 500999999 < uVar2)) {
            dump_stack();
          }
        }
      }
      goto LAB_0010ab9c;
    }
    if (0x20 < *(byte *)(uVar3 + 0x29)) {
      __trace_bprintk(0x10aae8,lock_protect_update_starttime_trace_printk_fmt_26,param_3);
    }
  }
  cVar1 = *(char *)(uVar3 + 0x29);
  if (cVar1 == '\0') {
    if (*(int *)(param_1 + 0x630) != 0) {
      uVar2 = *(ulong *)(param_1 + 0xdd8);
      if ((uVar2 == 0) || (0xfffffffffffff000 < uVar2)) {
        _printk(&DAT_00110a81);
      }
      else {
        *(uint *)(uVar2 + 0x2c) = *(uint *)(uVar2 + 0x2c) | 0x200000;
      }
    }
    uVar2 = jiffies_to_usecs(_jiffies);
    *(ulong *)(uVar3 + 0x38) = (uVar2 & 0xffffffff) * 1000;
    resched_task(param_1,1);
    cVar1 = *(char *)(uVar3 + 0x29);
  }
  *(char *)(uVar3 + 0x29) = cVar1 + '\x01';
  if ((*(int *)(param_1 + 0x630) != 0) &&
     ((*(ulong *)(param_1 + 0xdd8) == 0 || (0xfffffffffffff000 < *(ulong *)(param_1 + 0xdd8))))) {
    _printk(&DAT_00110a81);
  }
  task_get_mvp_prio(param_1,1);
  return;
}



//------------------------------------------------------------
// register_vendor_comm_hooks @ 0010af0c size=148
// signature: undefined register_vendor_comm_hooks(void)
// callers: [init_module]
//------------------------------------------------------------

void register_vendor_comm_hooks(void)

{
  tracepoint_probe_register
            (&__tracepoint_android_vh_binder_proc_transaction_finish,
             android_vh_binder_proc_transaction_finish,0);
  tracepoint_probe_register
            (&__tracepoint_android_vh_percpu_rwsem_down_read,
             android_vh_percpu_rwsem_down_read_preempt_handler,0);
  android_rvh_probe_register
            (&__tracepoint_android_rvh_percpu_rwsem_wait_complete,
             android_rvh_percpu_rwsem_wait_complete_handler,0);
  tracepoint_probe_register
            (&__tracepoint_android_vh_percpu_rwsem_up_write,android_vh_percpu_rwsem_up_write_handler
             ,0);
  msched_uclamp_register_vendor_comm_hooks();
  android_rvh_probe_register
            (&__tracepoint_android_rvh_pr_set_vma_name_bypass,android_rvh_pr_set_vma_name_bypass,0);
  return;
}



//------------------------------------------------------------
// android_vh_binder_proc_transaction_finish @ 0010afa4 size=552
// signature: undefined android_vh_binder_proc_transaction_finish(void)
// callers: []
//------------------------------------------------------------

void android_vh_binder_proc_transaction_finish
               (undefined8 param_1,long param_2,long param_3,long param_4,uint param_5,uint param_6)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  undefined8 uVar6;
  long *plVar7;
  int iVar8;
  uint uVar9;
  long lVar10;
  long lVar11;
  
  if (*(long *)(param_3 + 0x20) == 0) {
    lVar3 = 0;
  }
  else {
    lVar3 = *(long *)(*(long *)(param_3 + 0x20) + 0x1a8);
  }
  if ((param_2 == 0) || (lVar4 = sp_el0, lVar4 == param_4)) goto LAB_0010b000;
  if ((param_4 != 0) && ((param_5 & 1) == 0)) {
    binder_ux_type_set(param_4);
    goto LAB_0010b000;
  }
  if ((((param_4 != 0) || ((param_6 & 1) == 0)) || (lVar3 == 0)) ||
     ((iVar1 = task_get_mvp_prio(lVar3,1), iVar1 < 0x3c ||
      ((moto_sched_enabled._1_1_ >> 5 & 1) == 0)))) goto LAB_0010b000;
  lVar4 = rb_first(param_2 + 0x10);
  lVar3 = 0;
  if (lVar4 == 0) {
    uVar6 = 0;
    goto code_r0x0010b1a8;
  }
  iVar1 = 0x7fffffff;
  lVar10 = lVar3;
LAB_0010b0ac:
  lVar11 = lVar4 + -8;
  lVar3 = lVar10;
  if (((lVar11 == 0) || (*(char *)(lVar4 + 0x198) != '\0')) ||
     ((*(long *)(lVar4 + 0x1a0) == 0 ||
      ((((*(byte *)(lVar4 + 0x2c) & 1) == 0 ||
        (iVar2 = task_get_mvp_prio(*(long *)(lVar4 + 0x1a0),1),
        *(int *)(*(long *)(lVar4 + 0x1a0) + 0x84) < 100)) || (-1 < iVar2)))))) goto LAB_0010b09c;
  lVar3 = *(long *)(lVar4 + 0x38);
  if (lVar3 == 0) {
    plVar5 = (long *)(lVar4 + 0x40);
    if ((long *)*plVar5 == plVar5) goto LAB_0010b198;
    plVar7 = (long *)*plVar5;
    if (plVar7 != plVar5) {
      iVar2 = 0;
      if ((plVar7 != (long *)0x0) && (plVar7 == *(long **)(lVar4 + 0x48))) {
        if ((*(uint *)(plVar7 + 2) & 0xfffffffe) != 2) {
          iVar2 = 0;
          goto LAB_0010b108;
        }
        goto LAB_0010b198;
      }
      goto LAB_0010b108;
    }
    iVar2 = 0;
LAB_0010b088:
    iVar8 = 0;
  }
  else {
    iVar2 = 0;
    do {
      lVar3 = *(long *)(lVar3 + 0x30);
      iVar2 = iVar2 + 100;
    } while (lVar3 != 0);
    plVar7 = *(long **)(lVar4 + 0x40);
LAB_0010b108:
    if (plVar7 == (long *)(lVar4 + 0x40)) goto LAB_0010b088;
    iVar8 = 0;
    do {
      if (plVar7 == (long *)0x0) {
        uVar9 = 1;
      }
      else {
        uVar9 = (uint)((*(uint *)(plVar7 + 2) & 0xfffffffe) != 2);
      }
      plVar7 = (long *)*plVar7;
      iVar8 = uVar9 + iVar8;
    } while (plVar7 != (long *)(lVar4 + 0x40));
  }
  iVar2 = iVar2 + iVar8 * 10;
  lVar3 = lVar11;
  if (iVar1 <= iVar2) {
    lVar3 = lVar10;
    iVar2 = iVar1;
  }
  iVar1 = iVar2;
LAB_0010b09c:
  lVar4 = rb_next(lVar4);
  lVar10 = lVar3;
  if (lVar4 == 0) goto LAB_0010b190;
  goto LAB_0010b0ac;
LAB_0010b190:
  lVar11 = lVar3;
  if (lVar3 == 0) {
    uVar6 = 0;
  }
  else {
LAB_0010b198:
    uVar6 = *(undefined8 *)(lVar11 + 0x1a8);
    lVar3 = lVar11;
  }
code_r0x0010b1a8:
  if ((lVar3 != 0) && (*(long *)(lVar3 + 0x1a8) != 0)) {
    binder_inherit_ux_type(uVar6);
  }
LAB_0010b000:
  return;
}



//------------------------------------------------------------
// android_vh_percpu_rwsem_down_read_preempt_handler @ 0010b298 size=484
// signature: undefined android_vh_percpu_rwsem_down_read_preempt_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void android_vh_percpu_rwsem_down_read_preempt_handler
               (undefined8 param_1,long param_2,undefined8 param_3,undefined1 *param_4)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  long lVar8;
  int iVar9;
  
  if ((((param_2 != 0) && (param_4 != (undefined1 *)0x0)) &&
      ((moto_sched_enabled._1_1_ >> 4 & 1) != 0)) && (*(int *)(param_2 + 0x58) != 0)) {
    iVar7 = 0;
    iVar9 = 0;
    while (uVar6 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar7), uVar6 < _nr_cpu_ids
          ) {
      if ((uVar6 & 0xffffffe0) != 0) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10b520);
        (*pcVar5)();
      }
      iVar9 = *(int *)(*(long *)(&__per_cpu_offset + (ulong)uVar6 * 8) + *(long *)(param_2 + 0x30))
              + iVar9;
      iVar7 = uVar6 + 1;
    }
    if ((iVar9 != 0) && (*(int *)(param_2 + 0x58) != 0)) {
      lVar4 = sp_el0;
      if ((*(int *)(lVar4 + 0x634) != global_launcher_tgid) ||
         ((iVar7 = task_get_mvp_prio(lVar4,1), iVar7 != 0x46 ||
          (iVar7 = strcmp((char *)(lVar4 + 0x848),"RenderThread"), iVar7 != 0)))) {
        iVar7 = strncmp((char *)(lVar4 + 0x848),"binder",6);
        if (iVar7 != 0) {
          return;
        }
        __rcu_read_lock();
        lVar8 = find_task_by_vpid(*(undefined4 *)(lVar4 + 0x634));
        if ((lVar8 == 0) || (*(int *)(lVar8 + 0x488) - 3U < 0xfffffffe)) {
          __rcu_read_unlock();
          return;
        }
        __rcu_read_unlock();
      }
      *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + 1;
      *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + 1;
      lVar8 = tpidr_el1;
      piVar1 = (int *)(lVar8 + *(long *)(param_2 + 0x30));
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar3) {
          *piVar1 = *piVar1 + 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      lVar8 = *(long *)(lVar4 + 0x10) + -1;
      *(int *)(lVar4 + 0x10) = (int)lVar8;
      if ((lVar8 == 0) || (*(long *)(lVar4 + 0x10) == 0)) {
        preempt_schedule_notrace();
      }
      DataMemoryBarrier(2,3);
      *param_4 = 1;
      lVar8 = *(long *)(lVar4 + 0x10) + -1;
      *(int *)(lVar4 + 0x10) = (int)lVar8;
      if ((lVar8 == 0) || (*(long *)(lVar4 + 0x10) == 0)) {
        preempt_schedule();
      }
    }
  }
  return;
}



//------------------------------------------------------------
// android_rvh_percpu_rwsem_wait_complete_handler @ 0010b5a8 size=64
// signature: undefined android_rvh_percpu_rwsem_wait_complete_handler(void)
// callers: []
//------------------------------------------------------------

void android_rvh_percpu_rwsem_wait_complete_handler(void)

{
  return;
}



//------------------------------------------------------------
// android_vh_percpu_rwsem_up_write_handler @ 0010b698 size=44
// signature: undefined android_vh_percpu_rwsem_up_write_handler(void)
// callers: []
//------------------------------------------------------------

void android_vh_percpu_rwsem_up_write_handler(void)

{
  return;
}



//------------------------------------------------------------
// android_rvh_pr_set_vma_name_bypass @ 0010b764 size=296
// signature: undefined android_rvh_pr_set_vma_name_bypass(void)
// callers: []
//------------------------------------------------------------

void android_rvh_pr_set_vma_name_bypass
               (undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4,int *param_5,
               undefined4 *param_6,undefined1 *param_7)

{
  char cVar1;
  bool bVar2;
  long lVar3;
  int iVar4;
  
  if (((param_2 != 0) && (param_6 != (undefined4 *)0x0)) && (param_7 != (undefined1 *)0x0)) {
    lVar3 = sp_el0;
    iVar4 = task_get_mvp_prio(lVar3,1);
    if (((iVar4 == 0x46) || (*(int *)(lVar3 + 0x634) == global_sysui_tgid)) ||
       (*(int *)(lVar3 + 0x634) == global_sf_tgid)) {
      iVar4 = down_write_trylock(param_2 + 0x60);
      if (iVar4 == 0) {
        *param_7 = 1;
        *param_6 = 0;
        if (param_5 != (int *)0x0) {
          Hint_Prefetch(param_5,2,0,1);
          do {
            iVar4 = *param_5;
            cVar1 = '\x01';
            bVar2 = (bool)ExclusiveMonitorPass(param_5,0x10);
            if (bVar2) {
              *param_5 = iVar4 + -1;
              cVar1 = ExclusiveMonitorsStatus();
            }
          } while (cVar1 != '\0');
          if (iVar4 == 1) {
            DataMemoryBarrier(2,1);
            kfree(param_5);
          }
          else if (iVar4 < 1) {
            refcount_warn_saturate(param_5,3);
          }
        }
      }
      else {
        *(int *)(param_2 + 0xb0) = *(int *)(param_2 + 0xb0) + 1;
        up_write(param_2 + 0x60);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_msched_pr_set_vma_name_bypass @ 0010b94c size=108
// signature: undefined trace_raw_output_msched_pr_set_vma_name_bypass(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_msched_pr_set_vma_name_bypass
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "msched_pr_set_vma_name_bypass: task=%s pid=%d tgid=%d addr=0x%lx size=%lu\n"
                       ,lVar2 + 0x10,*(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined8 *)(lVar2 + 0x20),*(undefined8 *)(lVar2 + 0x28));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_percpu_rwsem_down_read_preempt @ 0010b9bc size=140
// signature: undefined trace_raw_output_percpu_rwsem_down_read_preempt(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_percpu_rwsem_down_read_preempt
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"sem=%p task=%d/%d (%s/%s) try=%d hook_ret=%d block=%d\n",
                       *(undefined8 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0x10),
                       *(undefined4 *)(lVar2 + 0x14),lVar2 + 0x18,lVar2 + 0x28,
                       *(undefined1 *)(lVar2 + 0x38),*(undefined1 *)(lVar2 + 0x39),
                       *(undefined4 *)(lVar2 + 0x3c));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_percpu_rwsem_wait_complete @ 0010ba4c size=120
// signature: undefined trace_raw_output_percpu_rwsem_wait_complete(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_percpu_rwsem_wait_complete(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"sem=%p task=%d(%s) state=%d complete=%d block=%d\n",
                       *(undefined8 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0x10),lVar2 + 0x14,
                       *(undefined4 *)(lVar2 + 0x24),*(undefined1 *)(lVar2 + 0x28),
                       *(undefined4 *)(lVar2 + 0x2c));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_percpu_rwsem_up_write @ 0010bac8 size=112
// signature: undefined trace_raw_output_percpu_rwsem_up_write(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_percpu_rwsem_up_write(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"sem=%p task=%d(%s) block_before=%d\n",*(undefined8 *)(lVar2 + 8),
                       *(undefined4 *)(lVar2 + 0x10),lVar2 + 0x14,*(undefined4 *)(lVar2 + 0x24));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_msched_task_get_mvp_prio @ 0010bb3c size=136
// signature: undefined trace_raw_output_msched_task_get_mvp_prio(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_msched_task_get_mvp_prio(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "pid=%d tgid=%d prio=%d scene=%d ux_type=%d current_pid=%d current_ux_type=%d task_util=%lu mvp_prio=%d\n"
                       ,*(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x2c),
                       *(undefined4 *)(lVar2 + 0x14),*(undefined4 *)(lVar2 + 0x18),
                       *(undefined4 *)(lVar2 + 0x1c),*(undefined8 *)(lVar2 + 0x20),
                       *(undefined4 *)(lVar2 + 0x28));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_msched_uclamp_restriction_result @ 0010bbc8 size=148
// signature: undefined trace_raw_output_msched_uclamp_restriction_result(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_msched_uclamp_restriction_result
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "pid=%d clamp_id=%d req=%u eff=%u max=%u tg=[%u,%u] pi=[%u,%u] binder=[%u,%u]\n"
                       ,*(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14),
                       *(undefined4 *)(lVar2 + 0x18),*(undefined4 *)(lVar2 + 0x1c),
                       *(undefined4 *)(lVar2 + 0x20),*(undefined4 *)(lVar2 + 0x24),
                       *(undefined4 *)(lVar2 + 0x28),*(undefined4 *)(lVar2 + 0x2c),
                       *(undefined4 *)(lVar2 + 0x30));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_msched_uclamp_inheritance_result @ 0010bc60 size=164
// signature: undefined trace_raw_output_msched_uclamp_inheritance_result(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_msched_uclamp_inheritance_result
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "p=%d pi=%d p_util=%lu [%u,%u] pi_util=%lu [%u,%u] inherit_min=%u inherit_max=%u type=%d\n"
                       ,*(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined8 *)(lVar2 + 0x10),*(undefined2 *)(lVar2 + 0x18),
                       *(undefined2 *)(lVar2 + 0x1a),*(undefined8 *)(lVar2 + 0x20),
                       *(undefined2 *)(lVar2 + 0x28),*(undefined2 *)(lVar2 + 0x2a),
                       *(undefined2 *)(lVar2 + 0x2c),*(undefined2 *)(lVar2 + 0x2e),
                       *(undefined4 *)(lVar2 + 0x30));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_sched_boost_ux_kworker @ 0010bd08 size=136
// signature: undefined trace_raw_output_sched_boost_ux_kworker(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_sched_boost_ux_kworker(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "pid=%d tgid=%d prio=%d comm=%s waker=%s waker_prio=%d trigger_reason=%s\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),lVar2 + 0x14,lVar2 + 0x24,
                       *(undefined4 *)(lVar2 + 0x34),lVar2 + (ulong)*(ushort *)(lVar2 + 0x38));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_sched_wake_by_irq_kth @ 0010bd94 size=108
// signature: undefined trace_raw_output_sched_wake_by_irq_kth(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_sched_wake_by_irq_kth(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"pid=%d tgid=%d prio=%d comm=%s\n",*(undefined4 *)(lVar2 + 8),
                       *(undefined4 *)(lVar2 + 0xc),*(undefined4 *)(lVar2 + 0x10),lVar2 + 0x14);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_sched_percpu_rwsem_hold_time @ 0010be04 size=112
// signature: undefined trace_raw_output_sched_percpu_rwsem_hold_time(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_sched_percpu_rwsem_hold_time
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"pid=%d tgid=%d prio=%d comm=%s hold_time=%lu\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),lVar2 + 0x14,*(undefined8 *)(lVar2 + 0x28));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_sched_percpu_rwsem_starttime @ 0010be78 size=128
// signature: undefined trace_raw_output_sched_percpu_rwsem_starttime(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_sched_percpu_rwsem_starttime
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"pid=%d prio=%d comm=%s depth=%d acquire=%d ux_type=%d mvp=%d\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),lVar2 + 0x10,
                       *(undefined1 *)(lVar2 + 0x20),*(undefined1 *)(lVar2 + 0x21),
                       *(undefined4 *)(lVar2 + 0x24),*(undefined4 *)(lVar2 + 0x28));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_binder_inherit_ux_type @ 0010befc size=116
// signature: undefined trace_raw_output_binder_inherit_ux_type(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_binder_inherit_ux_type(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"binder_ux: pid=%d tgid=%d prio=%d comm=%s ux_type=%d set=%d\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),lVar2 + 0x14,*(undefined4 *)(lVar2 + 0x24),
                       *(undefined1 *)(lVar2 + 0x28));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_binder_pick_best_thread @ 0010bf74 size=124
// signature: undefined trace_raw_output_binder_pick_best_thread(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_binder_pick_best_thread(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "proc=%d best_pid=%d best_comm=%s prio=%d mvpprio=%d idle=%d score=%d\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),lVar2 + 0x18,
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14),
                       *(undefined4 *)(lVar2 + 0x28),*(undefined4 *)(lVar2 + 0x2c));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_binder_nothread_be_select @ 0010bff4 size=116
// signature: undefined trace_raw_output_binder_nothread_be_select(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_binder_nothread_be_select(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"pid=%d tgid=%d prio=%d comm=%s proc=%d epoll=%d\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),lVar2 + 0x14,*(undefined4 *)(lVar2 + 0x24),
                       *(undefined1 *)(lVar2 + 0x28));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_binder_inherit_rt_prio @ 0010c06c size=136
// signature: undefined trace_raw_output_binder_inherit_rt_prio(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_binder_inherit_rt_prio(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "pid=%d tgid=%d prio=%d comm=%s call_pid=%d call_tgid=%d call_prio=%d call_comm=%s\n"
                       ,*(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),lVar2 + 0x14,*(undefined4 *)(lVar2 + 0x24),
                       *(undefined4 *)(lVar2 + 0x28),*(undefined4 *)(lVar2 + 0x2c),lVar2 + 0x30);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_binder_inherit_rt_check @ 0010c0f8 size=144
// signature: undefined trace_raw_output_binder_inherit_rt_check(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_binder_inherit_rt_check(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "pid=%d tgid=%d policy=%d prio=%d comm=%s call_pid=%d call_policy=%d call_prio=%d call_comm=%s to_thread=%lu\n"
                       ,*(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14),lVar2 + 0x18,
                       *(undefined4 *)(lVar2 + 0x28),*(undefined4 *)(lVar2 + 0x2c),
                       *(undefined4 *)(lVar2 + 0x30),lVar2 + 0x34,*(undefined8 *)(lVar2 + 0x48));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_binder_nothread_be_select @ 0010c188 size=52
// signature: undefined trace_binder_nothread_be_select(void)
// callers: []
//------------------------------------------------------------

void trace_binder_nothread_be_select(void)

{
  return;
}



//------------------------------------------------------------
// proc_has_epoll_threads @ 0010c268 size=76
// signature: undefined proc_has_epoll_threads(void)
// callers: []
//------------------------------------------------------------

uint proc_has_epoll_threads(long param_1)

{
  long lVar1;
  uint uVar2;
  
  lVar1 = rb_first(param_1 + 0x10);
  if (lVar1 == 0) {
    uVar2 = 0;
  }
  else {
    do {
      uVar2 = *(uint *)(lVar1 + 0x2c) >> 5 & 1;
      if ((*(uint *)(lVar1 + 0x2c) >> 5 & 1) != 0) {
        return uVar2;
      }
      lVar1 = rb_next();
    } while (lVar1 != 0);
  }
  return uVar2;
}



//------------------------------------------------------------
// android_vh_dup_task_struct_handler @ 0010c364 size=332
// signature: undefined android_vh_dup_task_struct_handler(void)
// callers: []
//------------------------------------------------------------

void android_vh_dup_task_struct_handler(undefined8 param_1,long param_2,long param_3)

{
  ulong uVar1;
  uint uVar2;
  
  if (param_3 != 0) {
    if (*(int *)(param_3 + 0x630) == 0) {
      uVar2 = 0;
    }
    else {
      uVar1 = *(ulong *)(param_3 + 0xdd8);
      if ((uVar1 == 0) || (0xfffffffffffff000 < uVar1)) {
        _printk(&DAT_0011100e);
        uVar2 = 0;
      }
      else {
        uVar2 = *(uint *)(uVar1 + 0x2c) & 0x1a008;
      }
    }
    if (((param_2 != 0) &&
        (((*(ulong *)(param_2 + 0xdd8) == 0 || (0xfffffffffffff000 < *(ulong *)(param_2 + 0xdd8)))
         && (uVar1 = kmem_cache_alloc(msched_task_struct_cachep,0xa20), uVar1 != 0)))) &&
       (uVar1 < 0xfffffffffffff001)) {
      *(undefined8 *)(uVar1 + 0x40) = 0;
      *(undefined8 *)(uVar1 + 0x48) = 0;
      *(undefined8 *)(uVar1 + 0x30) = 0;
      *(undefined8 *)(uVar1 + 0x38) = 0;
      *(long *)(uVar1 + 0x20) = param_2;
      *(undefined8 *)(uVar1 + 0x28) = 0;
      *(undefined8 *)(uVar1 + 0x10) = 0;
      *(undefined8 *)(uVar1 + 0x18) = 0;
      *(ulong *)uVar1 = uVar1;
      *(ulong *)(uVar1 + 8) = uVar1;
      DataMemoryBarrier(2,3);
      *(ulong *)(param_2 + 0xdd8) = uVar1;
      if (uVar2 != 0) {
        if (*(int *)(param_2 + 0x630) != 0) {
          uVar1 = *(ulong *)(param_2 + 0xdd8);
          if ((uVar1 == 0) || (0xfffffffffffff000 < uVar1)) {
            _printk(&DAT_0011100e);
          }
          else {
            *(uint *)(uVar1 + 0x2c) = *(uint *)(uVar1 + 0x2c) | uVar2;
          }
        }
        if (((byte)moto_sched_debug & 1) != 0) {
          __trace_bprintk(0x10c48c,android_vh_dup_task_struct_handler_trace_printk_fmt,uVar2,
                          *(undefined4 *)(param_3 + 0x630),*(undefined4 *)(param_2 + 0x630));
        }
      }
      msched_uclamp_vh_dup_task_struct(param_1,param_2,param_3);
    }
  }
  return;
}



//------------------------------------------------------------
// init_moto_task_struct @ 0010c4b4 size=28
// signature: undefined init_moto_task_struct(void)
// callers: []
//------------------------------------------------------------

void init_moto_task_struct(long param_1)

{
  *(undefined8 *)(param_1 + 0x40) = 0;
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(long *)param_1 = param_1;
  *(long *)(param_1 + 8) = param_1;
  return;
}



//------------------------------------------------------------
// android_vh_free_task_handler @ 0010c4d4 size=84
// signature: undefined android_vh_free_task_handler(void)
// callers: []
//------------------------------------------------------------

void android_vh_free_task_handler(undefined8 param_1,long param_2)

{
  ulong uVar1;
  
  if (((param_2 != 0) && (uVar1 = *(ulong *)(param_2 + 0xdd8), uVar1 != 0)) &&
     (uVar1 < 0xfffffffffffff001)) {
    *(undefined8 *)(param_2 + 0xdd8) = 0;
    reset_rwsem_owner_list(uVar1);
    *(undefined8 *)(uVar1 + 0x20) = 0;
    kmem_cache_free(msched_task_struct_cachep,uVar1);
  }
  return;
}



//------------------------------------------------------------
// msched_oemdata_init @ 0010c52c size=192
// signature: undefined msched_oemdata_init(void)
// callers: [init_module]
//------------------------------------------------------------

undefined8 msched_oemdata_init(void)

{
  long lVar1;
  undefined8 uVar2;
  
  msched_task_struct_cachep =
       kmem_cache_create("moto_task_struct",0x50,0,0x4040000,init_moto_task_struct);
  if (msched_task_struct_cachep == 0) {
    uVar2 = 0xfffffff4;
  }
  else {
    tracepoint_probe_register
              (&__tracepoint_android_vh_dup_task_struct,android_vh_dup_task_struct_handler,0);
    tracepoint_probe_register(&__tracepoint_android_vh_free_task,android_vh_free_task_handler,0);
    lVar1 = tpidr_el1;
    stop_machine(init_moto_struct_node_in_vendor_task_data,0,
                 stop_machine +
                 (((ulong)*(uint *)(&cpu_number + lVar1) & 0x3f) * 8 -
                 ((ulong)(*(uint *)(&cpu_number + lVar1) >> 3) & 0x1ffffff8)));
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// init_moto_struct_node_in_vendor_task_data @ 0010c5f0 size=388
// signature: undefined init_moto_struct_node_in_vendor_task_data(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 init_moto_struct_node_in_vendor_task_data(void)

{
  code *pcVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  long lVar8;
  
  _raw_read_lock(&tasklist_lock);
  puVar6 = _DAT_0011a610;
  if (_DAT_0011a610 != (undefined8 *)&DAT_0011a610) {
    do {
      puVar5 = (undefined8 *)(puVar6[0x68] + 0x10);
      for (puVar7 = (undefined8 *)*puVar5; puVar7 != puVar5; puVar7 = (undefined8 *)*puVar7) {
        if ((((puVar7[0xdd] == 0) || (0xfffffffffffff000 < (ulong)puVar7[0xdd])) &&
            (uVar3 = kmem_cache_alloc(msched_task_struct_cachep,0xa20), uVar3 != 0)) &&
           (uVar3 < 0xfffffffffffff001)) {
          *(undefined8 **)(uVar3 + 0x20) = puVar7 + -0xde;
          DataMemoryBarrier(2,3);
          puVar7[0xdd] = uVar3;
        }
        puVar5 = (undefined8 *)(puVar6[0x68] + 0x10);
      }
      puVar6 = (undefined8 *)*puVar6;
    } while (puVar6 != (undefined8 *)&DAT_0011a610);
  }
  iVar4 = 0;
  while( true ) {
    uVar2 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,iVar4);
    if (_nr_cpu_ids <= uVar2) {
      _raw_read_unlock(&tasklist_lock);
      return 0;
    }
    if (0x1f < (ulong)uVar2) break;
    if (*(long *)(&__per_cpu_offset + (ulong)uVar2 * 8) != -0x11a2d0) {
      lVar8 = *(long *)(*(long *)(&__per_cpu_offset + (ulong)uVar2 * 8) + 0x11ad78);
      if (((*(ulong *)(lVar8 + 0xdd8) == 0) || (0xfffffffffffff000 < *(ulong *)(lVar8 + 0xdd8))) &&
         ((uVar3 = kmem_cache_alloc(msched_task_struct_cachep,0xa20), uVar3 != 0 &&
          (uVar3 < 0xfffffffffffff001)))) {
        *(long *)(uVar3 + 0x20) = lVar8;
        DataMemoryBarrier(2,3);
        *(ulong *)(lVar8 + 0xdd8) = uVar3;
      }
    }
    iVar4 = uVar2 + 1;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10c774);
  (*pcVar1)();
}



//------------------------------------------------------------
// msched_oemdata_deinit @ 0010c778 size=84
// signature: undefined msched_oemdata_deinit(void)
// callers: []
//------------------------------------------------------------

void msched_oemdata_deinit(void)

{
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_dup_task_struct,android_vh_dup_task_struct_handler,0);
  tracepoint_probe_unregister(&__tracepoint_android_vh_free_task,android_vh_free_task_handler,0);
  kmem_cache_destroy(msched_task_struct_cachep);
  return;
}



//------------------------------------------------------------
// __traceiter_rwsem_pi_start @ 0010c7d4 size=140
// signature: undefined __traceiter_rwsem_pi_start(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_rwsem_pi_start
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,uint param_5)

{
  code *pcVar1;
  long *plVar2;
  
  if (DAT_001161f0 != (long *)0x0) {
    plVar2 = DAT_001161f0;
    do {
      if (*(int *)((code *)*plVar2 + -4) != 0x19766d58) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10c838);
        (*pcVar1)();
      }
      (*(code *)*plVar2)(plVar2[1],param_2,param_3,param_4,param_5 & 1);
      plVar2 = plVar2 + 3;
    } while (*plVar2 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// __traceiter_rwsem_pi_finish @ 0010c864 size=124
// signature: undefined __traceiter_rwsem_pi_finish(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_rwsem_pi_finish
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00116238;
  plVar2 = _DAT_00116238;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x4927ddb5) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10c8bc);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_lock_pi_start @ 0010c8e4 size=124
// signature: undefined __traceiter_lock_pi_start(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_lock_pi_start
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00116280;
  plVar2 = _DAT_00116280;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0xfb36e4e) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10c93c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_lock_pi_finish @ 0010c964 size=116
// signature: undefined __traceiter_lock_pi_finish(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_lock_pi_finish(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001162c8;
  plVar2 = _DAT_001162c8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x60f99b4b) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10c9b4);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_set_user_nice @ 0010c9dc size=124
// signature: undefined __traceiter_set_user_nice(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_set_user_nice(undefined8 param_1,undefined8 param_2,undefined8 param_3,uint param_4)

{
  code *pcVar1;
  long *plVar2;
  
  if (_DAT_00116310 != (long *)0x0) {
    plVar2 = _DAT_00116310;
    do {
      if (*(int *)((code *)*plVar2 + -4) != -0x2ca20e4d) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10ca34);
        (*pcVar1)();
      }
      (*(code *)*plVar2)(plVar2[1],param_2,param_3,param_4 & 1);
      plVar2 = plVar2 + 3;
    } while (*plVar2 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// __traceiter_locking_debug_trace @ 0010ca5c size=148
// signature: undefined __traceiter_locking_debug_trace(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_locking_debug_trace
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00116358;
  plVar2 = _DAT_00116358;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x75fb4249) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10cac8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_rwsem_read_trylock_steal @ 0010caf4 size=124
// signature: undefined __traceiter_rwsem_read_trylock_steal(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_rwsem_read_trylock_steal
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001163a0;
  plVar2 = _DAT_001163a0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x7eba8ac7) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10cb4c);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_rwsem_pi_start @ 0010cb74 size=264
// signature: undefined trace_event_raw_event_rwsem_pi_start(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_rwsem_pi_start
               (long param_1,undefined8 param_2,long param_3,long param_4,byte param_5)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
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
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x40), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0x10) = *(undefined4 *)(param_3 + 0x630);
    uVar3 = *(undefined8 *)(param_3 + 0x848);
    *(undefined8 *)(lVar1 + 0x1c) = *(undefined8 *)(param_3 + 0x850);
    *(undefined8 *)(lVar1 + 0x14) = uVar3;
    if (param_4 == 0) {
      *(undefined1 *)(lVar1 + 0x28) = 0;
      *(undefined4 *)(lVar1 + 0x24) = 0xffffffff;
    }
    else {
      *(undefined4 *)(lVar1 + 0x24) = *(undefined4 *)(param_4 + 0x630);
      uVar3 = *(undefined8 *)(param_4 + 0x850);
      *(undefined8 *)(lVar1 + 0x28) = *(undefined8 *)(param_4 + 0x848);
      *(undefined8 *)(lVar1 + 0x30) = uVar3;
    }
    *(byte *)(lVar1 + 0x38) = param_5 & 1;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_rwsem_pi_start @ 0010cc80 size=336
// signature: undefined perf_trace_rwsem_pi_start(void)
// callers: []
//------------------------------------------------------------

void perf_trace_rwsem_pi_start
               (long param_1,undefined8 param_2,long param_3,long param_4,byte param_5)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_60 = 0;
  local_64 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x44,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined8 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0x10) = *(undefined4 *)(param_3 + 0x630);
    uVar4 = *(undefined8 *)(param_3 + 0x848);
    *(undefined8 *)(lVar3 + 0x1c) = *(undefined8 *)(param_3 + 0x850);
    *(undefined8 *)(lVar3 + 0x14) = uVar4;
    if (param_4 == 0) {
      *(undefined1 *)(lVar3 + 0x28) = 0;
      *(undefined4 *)(lVar3 + 0x24) = 0xffffffff;
    }
    else {
      *(undefined4 *)(lVar3 + 0x24) = *(undefined4 *)(param_4 + 0x630);
      uVar4 = *(undefined8 *)(param_4 + 0x850);
      *(undefined8 *)(lVar3 + 0x28) = *(undefined8 *)(param_4 + 0x848);
      *(undefined8 *)(lVar3 + 0x30) = uVar4;
    }
    *(byte *)(lVar3 + 0x38) = param_5 & 1;
    perf_trace_run_bpf_submit(lVar3,0x44,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_rwsem_pi_finish @ 0010cdd4 size=252
// signature: undefined trace_event_raw_event_rwsem_pi_finish(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_rwsem_pi_finish
               (long param_1,undefined8 param_2,long param_3,long param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
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
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x38), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0x10) = *(undefined4 *)(param_3 + 0x630);
    uVar3 = *(undefined8 *)(param_3 + 0x848);
    *(undefined8 *)(lVar1 + 0x1c) = *(undefined8 *)(param_3 + 0x850);
    *(undefined8 *)(lVar1 + 0x14) = uVar3;
    if (param_4 == 0) {
      *(undefined1 *)(lVar1 + 0x28) = 0;
      *(undefined4 *)(lVar1 + 0x24) = 0xffffffff;
    }
    else {
      *(undefined4 *)(lVar1 + 0x24) = *(undefined4 *)(param_4 + 0x630);
      uVar3 = *(undefined8 *)(param_4 + 0x850);
      *(undefined8 *)(lVar1 + 0x28) = *(undefined8 *)(param_4 + 0x848);
      *(undefined8 *)(lVar1 + 0x30) = uVar3;
    }
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_rwsem_pi_finish @ 0010ced4 size=316
// signature: undefined perf_trace_rwsem_pi_finish(void)
// callers: []
//------------------------------------------------------------

void perf_trace_rwsem_pi_finish(long param_1,undefined8 param_2,long param_3,long param_4)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x3c,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined8 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0x10) = *(undefined4 *)(param_3 + 0x630);
    uVar4 = *(undefined8 *)(param_3 + 0x848);
    *(undefined8 *)(lVar3 + 0x1c) = *(undefined8 *)(param_3 + 0x850);
    *(undefined8 *)(lVar3 + 0x14) = uVar4;
    if (param_4 == 0) {
      *(undefined1 *)(lVar3 + 0x28) = 0;
      *(undefined4 *)(lVar3 + 0x24) = 0xffffffff;
    }
    else {
      *(undefined4 *)(lVar3 + 0x24) = *(undefined4 *)(param_4 + 0x630);
      uVar4 = *(undefined8 *)(param_4 + 0x850);
      *(undefined8 *)(lVar3 + 0x28) = *(undefined8 *)(param_4 + 0x848);
      *(undefined8 *)(lVar3 + 0x30) = uVar4;
    }
    perf_trace_run_bpf_submit(lVar3,0x3c,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_lock_pi_start @ 0010d014 size=288
// signature: undefined trace_event_raw_event_lock_pi_start(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_lock_pi_start(long param_1,long param_2,long param_3,char *param_4)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_4 != (char *)0x0) {
      __s = param_4;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_78,param_1,(long)iVar1 + 0x34);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 0x30) = iVar1 * 0x10000 | 0x34;
      *(undefined4 *)(lVar3 + 8) = *(undefined4 *)(param_3 + 0x630);
      uVar5 = *(undefined8 *)(param_3 + 0x848);
      *(undefined8 *)(lVar3 + 0x14) = *(undefined8 *)(param_3 + 0x850);
      *(undefined8 *)(lVar3 + 0xc) = uVar5;
      *(undefined4 *)(lVar3 + 0x1c) = *(undefined4 *)(param_2 + 0x630);
      uVar5 = *(undefined8 *)(param_2 + 0x850);
      *(undefined8 *)(lVar3 + 0x20) = *(undefined8 *)(param_2 + 0x848);
      *(undefined8 *)(lVar3 + 0x28) = uVar5;
      strcpy((char *)(lVar3 + 0x34),__s);
      trace_event_buffer_commit(&local_78);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_lock_pi_start @ 0010d138 size=376
// signature: undefined perf_trace_lock_pi_start(void)
// callers: []
//------------------------------------------------------------

void perf_trace_lock_pi_start(long param_1,long param_2,long param_3,char *param_4)

{
  int iVar1;
  long *plVar2;
  char *__s;
  ulong uVar3;
  size_t sVar4;
  long lVar5;
  undefined8 uVar6;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  __s = "(null)";
  if (param_4 != (char *)0x0) {
    __s = param_4;
  }
  local_68 = *(long *)(lVar5 + 0x638);
  local_70 = 0;
  local_74 = 0;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar2 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = ((uint)sVar4 & 0xfffffff8) + 0x3c;
    lVar5 = perf_trace_buf_alloc(iVar1,&local_70,&local_74);
    if (lVar5 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_70 + 0x100) = uVar3;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(uint *)(lVar5 + 0x30) = (uint)sVar4 * 0x10000 + 0x10034;
      *(undefined4 *)(lVar5 + 8) = *(undefined4 *)(param_3 + 0x630);
      uVar6 = *(undefined8 *)(param_3 + 0x848);
      *(undefined8 *)(lVar5 + 0x14) = *(undefined8 *)(param_3 + 0x850);
      *(undefined8 *)(lVar5 + 0xc) = uVar6;
      *(undefined4 *)(lVar5 + 0x1c) = *(undefined4 *)(param_2 + 0x630);
      uVar6 = *(undefined8 *)(param_2 + 0x850);
      *(undefined8 *)(lVar5 + 0x20) = *(undefined8 *)(param_2 + 0x848);
      *(undefined8 *)(lVar5 + 0x28) = uVar6;
      strcpy((char *)(lVar5 + 0x34),__s);
      perf_trace_run_bpf_submit(lVar5,iVar1,local_74,param_1,1,local_70,plVar2,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_lock_pi_finish @ 0010d2b4 size=256
// signature: undefined trace_event_raw_event_lock_pi_finish(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_lock_pi_finish(long param_1,long param_2,char *param_3)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_3 != (char *)0x0) {
      __s = param_3;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_68,param_1,(long)iVar1 + 0x20);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 0x1c) = iVar1 * 0x10000 | 0x20;
      *(undefined4 *)(lVar3 + 8) = *(undefined4 *)(param_2 + 0x630);
      uVar5 = *(undefined8 *)(param_2 + 0x848);
      *(undefined8 *)(lVar3 + 0x14) = *(undefined8 *)(param_2 + 0x850);
      *(undefined8 *)(lVar3 + 0xc) = uVar5;
      strcpy((char *)(lVar3 + 0x20),__s);
      trace_event_buffer_commit(&local_68);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_lock_pi_finish @ 0010d3b8 size=348
// signature: undefined perf_trace_lock_pi_finish(void)
// callers: []
//------------------------------------------------------------

void perf_trace_lock_pi_finish(long param_1,long param_2,char *param_3)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  undefined8 uVar6;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar5 = sp_el0;
  __s = "(null)";
  if (param_3 != (char *)0x0) {
    __s = param_3;
  }
  local_58 = *(long *)(lVar5 + 0x638);
  local_60 = 0;
  local_64 = 0;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar4 + 0x2cU & 0xfffffff8) - 4;
    lVar5 = perf_trace_buf_alloc(iVar3,&local_60,&local_64);
    if (lVar5 != 0) {
      *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
      *(undefined1 **)(local_60 + 0xf8) = auStack_70;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_60 + 0x100) = uVar2;
      *(undefined8 *)(local_60 + 0x108) = 5;
      *(int *)(lVar5 + 0x1c) = (int)sVar4 * 0x10000 + 0x10020;
      *(undefined4 *)(lVar5 + 8) = *(undefined4 *)(param_2 + 0x630);
      uVar6 = *(undefined8 *)(param_2 + 0x848);
      *(undefined8 *)(lVar5 + 0x14) = *(undefined8 *)(param_2 + 0x850);
      *(undefined8 *)(lVar5 + 0xc) = uVar6;
      strcpy((char *)(lVar5 + 0x20),__s);
      perf_trace_run_bpf_submit(lVar5,iVar3,local_64,param_1,1,local_60,plVar1,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_set_user_nice @ 0010d518 size=220
// signature: undefined trace_event_raw_event_set_user_nice(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_set_user_nice(long param_1,long param_2,undefined8 param_3,byte param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
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
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x30), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = *(undefined4 *)(param_2 + 0x630);
    uVar3 = *(undefined8 *)(param_2 + 0x850);
    uVar4 = *(undefined8 *)(param_2 + 0x848);
    *(undefined8 *)(lVar1 + 0x20) = param_3;
    *(byte *)(lVar1 + 0x28) = param_4 & 1;
    *(undefined8 *)(lVar1 + 0x14) = uVar3;
    *(undefined8 *)(lVar1 + 0xc) = uVar4;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_set_user_nice @ 0010d5f8 size=284
// signature: undefined perf_trace_set_user_nice(void)
// callers: []
//------------------------------------------------------------

void perf_trace_set_user_nice(long param_1,long param_2,undefined8 param_3,byte param_4)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x34,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = *(undefined4 *)(param_2 + 0x630);
    uVar4 = *(undefined8 *)(param_2 + 0x850);
    uVar5 = *(undefined8 *)(param_2 + 0x848);
    *(undefined8 *)(lVar3 + 0x20) = param_3;
    *(byte *)(lVar3 + 0x28) = param_4 & 1;
    *(undefined8 *)(lVar3 + 0x14) = uVar4;
    *(undefined8 *)(lVar3 + 0xc) = uVar5;
    perf_trace_run_bpf_submit(lVar3,0x34,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_locking_debug_trace @ 0010d718 size=328
// signature: undefined trace_event_raw_event_locking_debug_trace(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_locking_debug_trace
               (long param_1,undefined8 param_2,char *param_3,char *param_4,undefined8 param_5,
               undefined8 param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *__s;
  char *__s_00;
  size_t sVar4;
  size_t sVar5;
  long lVar6;
  ulong uVar7;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar7 = __trace_trigger_soft_disabled(param_1), (uVar7 & 1) == 0)) {
    __s = "(null)";
    if (param_3 != (char *)0x0) {
      __s = param_3;
    }
    sVar4 = strlen(__s);
    __s_00 = "(null)";
    if (param_4 != (char *)0x0) {
      __s_00 = param_4;
    }
    iVar1 = (int)sVar4 + 1;
    sVar5 = strlen(__s_00);
    iVar2 = (int)sVar5 + 1;
    lVar6 = trace_event_buffer_reserve(&local_98,param_1,(long)(iVar2 + iVar1) + 0x28);
    if (lVar6 != 0) {
      uVar3 = (int)sVar4 + 0x29;
      *(undefined8 *)(lVar6 + 8) = param_2;
      *(uint *)(lVar6 + 0x10) = iVar1 * 0x10000 | 0x28;
      *(uint *)(lVar6 + 0x14) = uVar3 | iVar2 * 0x10000;
      strcpy((char *)(lVar6 + 0x28),__s);
      strcpy((char *)(lVar6 + (ulong)(uVar3 & 0xffff)),__s_00);
      *(undefined8 *)(lVar6 + 0x18) = param_5;
      *(undefined8 *)(lVar6 + 0x20) = param_6;
      trace_event_buffer_commit(&local_98);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_locking_debug_trace @ 0010d864 size=404
// signature: undefined perf_trace_locking_debug_trace(void)
// callers: []
//------------------------------------------------------------

void perf_trace_locking_debug_trace
               (long param_1,undefined8 param_2,char *param_3,char *param_4,undefined8 param_5,
               undefined8 param_6)

{
  int iVar1;
  long *plVar2;
  char *__s;
  char *__s_00;
  ulong uVar3;
  int iVar4;
  size_t sVar5;
  size_t sVar6;
  long lVar7;
  int iVar8;
  ulong unaff_x30;
  undefined1 auStack_90 [8];
  undefined8 local_88;
  undefined8 local_80;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar7 = sp_el0;
  __s = "(null)";
  if (param_3 != (char *)0x0) {
    __s = param_3;
  }
  local_68 = *(long *)(lVar7 + 0x638);
  local_70 = 0;
  local_74 = 0;
  local_88 = param_5;
  local_80 = param_6;
  sVar5 = strlen(__s);
  __s_00 = "(null)";
  if (param_4 != (char *)0x0) {
    __s_00 = param_4;
  }
  sVar6 = strlen(__s_00);
  lVar7 = tpidr_el1;
  plVar2 = (long *)(lVar7 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = (int)sVar6 + 1;
    iVar8 = (int)sVar5;
    iVar4 = (iVar8 + iVar1 + 0x34U & 0xfffffff8) - 4;
    lVar7 = perf_trace_buf_alloc(iVar4,&local_70,&local_74);
    if (lVar7 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_90 + 0x30;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xf8) = auStack_90;
      *(ulong *)(local_70 + 0x100) = uVar3;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(undefined8 *)(lVar7 + 8) = param_2;
      *(int *)(lVar7 + 0x10) = iVar8 * 0x10000 + 0x10028;
      *(uint *)(lVar7 + 0x14) = iVar8 + 0x29U | iVar1 * 0x10000;
      strcpy((char *)(lVar7 + 0x28),__s);
      strcpy((char *)(lVar7 + (ulong)(iVar8 + 0x29U & 0xffff)),__s_00);
      *(undefined8 *)(lVar7 + 0x18) = local_88;
      *(undefined8 *)(lVar7 + 0x20) = local_80;
      perf_trace_run_bpf_submit(lVar7,iVar4,local_74,param_1,1,local_70,plVar2,0);
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_rwsem_read_trylock_steal @ 0010d9fc size=212
// signature: undefined trace_event_raw_event_rwsem_read_trylock_steal(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_rwsem_read_trylock_steal
               (long param_1,long param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar3 = __trace_trigger_soft_disabled(param_1), (uVar3 & 1) == 0)) &&
     (lVar2 = trace_event_buffer_reserve(&local_68,param_1,0x30), lVar2 != 0)) {
    uVar4 = *(undefined8 *)(param_2 + 0x850);
    *(undefined8 *)(lVar2 + 8) = *(undefined8 *)(param_2 + 0x848);
    *(undefined8 *)(lVar2 + 0x10) = uVar4;
    uVar1 = *(undefined4 *)(param_2 + 0x630);
    *(undefined8 *)(lVar2 + 0x20) = param_3;
    *(undefined4 *)(lVar2 + 0x28) = param_4;
    *(undefined4 *)(lVar2 + 0x18) = uVar1;
    trace_event_buffer_commit(&local_68);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_rwsem_read_trylock_steal @ 0010dad4 size=276
// signature: undefined perf_trace_rwsem_read_trylock_steal(void)
// callers: []
//------------------------------------------------------------

void perf_trace_rwsem_read_trylock_steal
               (long param_1,long param_2,undefined8 param_3,undefined4 param_4)

{
  long *plVar1;
  ulong uVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 uVar5;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar4 = tpidr_el1;
  plVar1 = (long *)(lVar4 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar4 = perf_trace_buf_alloc(0x34,&local_50,&local_54), lVar4 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    uVar5 = *(undefined8 *)(param_2 + 0x850);
    *(undefined8 *)(lVar4 + 8) = *(undefined8 *)(param_2 + 0x848);
    *(undefined8 *)(lVar4 + 0x10) = uVar5;
    uVar3 = *(undefined4 *)(param_2 + 0x630);
    *(undefined8 *)(lVar4 + 0x20) = param_3;
    *(undefined4 *)(lVar4 + 0x28) = param_4;
    *(undefined4 *)(lVar4 + 0x18) = uVar3;
    perf_trace_run_bpf_submit(lVar4,0x34,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_rwsem_pi_start @ 0010dbec size=32
// signature: undefined __bpf_trace_rwsem_pi_start(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_rwsem_pi_start(void)

{
  bpf_trace_run4();
  return;
}



//------------------------------------------------------------
// __bpf_trace_rwsem_pi_finish @ 0010dc10 size=28
// signature: undefined __bpf_trace_rwsem_pi_finish(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_rwsem_pi_finish(void)

{
  bpf_trace_run3();
  return;
}



//------------------------------------------------------------
// __bpf_trace_lock_pi_start @ 0010dc30 size=28
// signature: undefined __bpf_trace_lock_pi_start(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_lock_pi_start(void)

{
  bpf_trace_run3();
  return;
}



//------------------------------------------------------------
// __bpf_trace_lock_pi_finish @ 0010dc50 size=28
// signature: undefined __bpf_trace_lock_pi_finish(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_lock_pi_finish(void)

{
  bpf_trace_run2();
  return;
}



//------------------------------------------------------------
// __bpf_trace_set_user_nice @ 0010dc70 size=32
// signature: undefined __bpf_trace_set_user_nice(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_set_user_nice(void)

{
  bpf_trace_run3();
  return;
}



//------------------------------------------------------------
// __bpf_trace_locking_debug_trace @ 0010dc94 size=28
// signature: undefined __bpf_trace_locking_debug_trace(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_locking_debug_trace(void)

{
  bpf_trace_run5();
  return;
}



//------------------------------------------------------------
// __bpf_trace_rwsem_read_trylock_steal @ 0010dcb4 size=32
// signature: undefined __bpf_trace_rwsem_read_trylock_steal(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_rwsem_read_trylock_steal(void)

{
  bpf_trace_run3();
  return;
}



//------------------------------------------------------------
// trace_raw_output_rwsem_pi_start @ 0010dcd8 size=120
// signature: undefined trace_raw_output_rwsem_pi_start(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_rwsem_pi_start(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"sem=%p waiter=%d(%s) owner=%d(%s) boosted=%d\n",
                       *(undefined8 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0x10),lVar2 + 0x14,
                       *(undefined4 *)(lVar2 + 0x24),lVar2 + 0x28,*(undefined1 *)(lVar2 + 0x38));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_rwsem_pi_finish @ 0010dd54 size=116
// signature: undefined trace_raw_output_rwsem_pi_finish(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_rwsem_pi_finish(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"sem=%p waiter=%d(%s) owner=%d(%s) cleanup\n",
                       *(undefined8 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0x10),lVar2 + 0x14,
                       *(undefined4 *)(lVar2 + 0x24),lVar2 + 0x28);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_lock_pi_start @ 0010ddcc size=120
// signature: undefined trace_raw_output_lock_pi_start(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_lock_pi_start(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"lock=%s waiter=%d(%s) boosted owner=%d(%s)\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 0x30),*(undefined4 *)(lVar2 + 8),
                       lVar2 + 0xc,*(undefined4 *)(lVar2 + 0x1c),lVar2 + 0x20);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_lock_pi_finish @ 0010de48 size=112
// signature: undefined trace_raw_output_lock_pi_finish(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_lock_pi_finish(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"lock=%s owner=%d(%s) cleared\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 0x1c),*(undefined4 *)(lVar2 + 8),
                       lVar2 + 0xc);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_set_user_nice @ 0010debc size=112
// signature: undefined trace_raw_output_set_user_nice(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_set_user_nice(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"pid=%d comm=%s nice=%ld allowed=%d\n",*(undefined4 *)(lVar2 + 8),
                       lVar2 + 0xc,*(undefined8 *)(lVar2 + 0x20),*(undefined1 *)(lVar2 + 0x28));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_locking_debug_trace @ 0010df30 size=120
// signature: undefined trace_raw_output_locking_debug_trace(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_locking_debug_trace(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"lock=%p func=%s reason=\"%s\" val1=0x%lx val2=0x%lx\n",
                       *(undefined8 *)(lVar2 + 8),lVar2 + (ulong)*(ushort *)(lVar2 + 0x10),
                       lVar2 + (ulong)*(ushort *)(lVar2 + 0x14),*(undefined8 *)(lVar2 + 0x18),
                       *(undefined8 *)(lVar2 + 0x20));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_rwsem_read_trylock_steal @ 0010dfac size=112
// signature: undefined trace_raw_output_rwsem_read_trylock_steal(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_rwsem_read_trylock_steal(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"task=%s pid=%d sem=%p mvp_prio=%d\n",lVar2 + 8,
                       *(undefined4 *)(lVar2 + 0x18),*(undefined8 *)(lVar2 + 0x20),
                       *(undefined4 *)(lVar2 + 0x28));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// locking_opt_init @ 0010e03c size=48
// signature: undefined locking_opt_init(void)
// callers: [init_module]
//------------------------------------------------------------

undefined8 locking_opt_init(void)

{
  register_mutex_vendor_hooks();
  register_rwsem_vendor_hooks();
  locking_inited = 1;
  return 0;
}



//------------------------------------------------------------
// locking_opt_exit @ 0010e070 size=32
// signature: undefined locking_opt_exit(void)
// callers: []
//------------------------------------------------------------

void locking_opt_exit(void)

{
  unregister_rwsem_vendor_hooks();
  unregister_mutex_vendor_hooks();
  return;
}



//------------------------------------------------------------
// android_vh_mutex_unlock_slowpath_handler @ 0010e094 size=52
// signature: undefined android_vh_mutex_unlock_slowpath_handler(void)
// callers: []
//------------------------------------------------------------

void android_vh_mutex_unlock_slowpath_handler(void)

{
  undefined8 uVar1;
  
  if (locking_inited != '\0') {
    uVar1 = sp_el0;
    lock_clear_inherited_ux_type(uVar1,"mutex_wait_finish");
  }
  return;
}



//------------------------------------------------------------
// register_mutex_vendor_hooks @ 0010e0cc size=96
// signature: undefined register_mutex_vendor_hooks(void)
// callers: [locking_opt_init]
//------------------------------------------------------------

void register_mutex_vendor_hooks(void)

{
  tracepoint_probe_register
            (&__tracepoint_android_vh_alter_mutex_list_add,android_vh_alter_mutex_list_add_handler,0
            );
  tracepoint_probe_register
            (&__tracepoint_android_vh_mutex_wait_start,android_vh_mutex_wait_start_handler,0);
  tracepoint_probe_register
            (&__tracepoint_android_vh_mutex_unlock_slowpath,android_vh_mutex_unlock_slowpath_handler
             ,0);
  return;
}



//------------------------------------------------------------
// android_vh_alter_mutex_list_add_handler @ 0010e130 size=144
// signature: undefined android_vh_alter_mutex_list_add_handler(void)
// callers: []
//------------------------------------------------------------

void android_vh_alter_mutex_list_add_handler
               (undefined8 param_1,long param_2,long param_3,long *param_4,undefined1 *param_5)

{
  undefined8 uVar1;
  int iVar2;
  undefined1 uVar3;
  
  if (locking_inited != '\0') {
    uVar1 = sp_el0;
    iVar2 = task_get_mvp_prio(uVar1,1);
    uVar3 = 0;
    if ((((param_2 != 0) && (param_3 != 0)) && (param_4 != (long *)0x0)) &&
       (((uVar3 = 0, *param_4 != 0 && (uVar3 = 0, param_4[1] != 0)) && (0x3b < iVar2)))) {
      mutex_list_add_ux(param_3,param_4);
      uVar3 = 1;
    }
    *param_5 = uVar3;
  }
  return;
}



//------------------------------------------------------------
// android_vh_mutex_wait_start_handler @ 0010e1c4 size=396
// signature: undefined android_vh_mutex_wait_start_handler(void)
// callers: []
//------------------------------------------------------------

void android_vh_mutex_wait_start_handler(undefined8 param_1,ulong *param_2)

{
  uint *puVar1;
  ulong uVar2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  long lVar6;
  int iVar7;
  ulong uVar8;
  undefined8 uVar9;
  
  if (param_2 == (ulong *)0x0) {
    return;
  }
  if (locking_inited == '\0') {
    return;
  }
  lVar6 = sp_el0;
  if ((99 < *(int *)(lVar6 + 0x84)) && (iVar7 = task_get_mvp_prio(lVar6,1), iVar7 < 0x3c)) {
    return;
  }
  uVar2 = *param_2 & 0xfffffffffffffff8;
  if (uVar2 == 0) {
    if (((byte)moto_sched_debug & 1) == 0) {
      return;
    }
    __trace_bprintk(0x10e2b0,android_vh_mutex_wait_start_handler_trace_printk_fmt,
                    *(undefined4 *)(lVar6 + 0x630));
    return;
  }
  puVar1 = (uint *)(uVar2 + 0x40);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar3 = *puVar1;
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar5) {
      *puVar1 = uVar3 + 1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  if (uVar3 == 0) {
    uVar9 = 2;
  }
  else {
    if (-1 < (int)(uVar3 + 1 | uVar3)) goto LAB_0010e23c;
    uVar9 = 1;
  }
  refcount_warn_saturate(puVar1,uVar9);
LAB_0010e23c:
  uVar8 = lock_inherit_ux_type(uVar2,lVar6,"mutex_wait");
  if (((uVar8 & 1) != 0) && ((*param_2 & 0xfffffffffffffff8) != uVar2)) {
    if (((byte)moto_sched_debug & 1) != 0) {
      __trace_bprintk(0x10e2d4,android_vh_mutex_wait_start_handler_trace_printk_fmt_7,
                      *param_2 & 0xfffffffffffffff8,uVar2);
    }
    lock_clear_inherited_ux_type(uVar2,"mutex_wait");
  }
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar3 = *puVar1;
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar5) {
      *puVar1 = uVar3 - 1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  if (uVar3 == 1) {
    DataMemoryBarrier(2,1);
    __put_task_struct(uVar2);
  }
  else if ((int)uVar3 < 1) {
    refcount_warn_saturate(puVar1,3);
  }
  return;
}



//------------------------------------------------------------
// unregister_mutex_vendor_hooks @ 0010e370 size=96
// signature: undefined unregister_mutex_vendor_hooks(void)
// callers: [locking_opt_exit]
//------------------------------------------------------------

void unregister_mutex_vendor_hooks(void)

{
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_alter_mutex_list_add,android_vh_alter_mutex_list_add_handler,0
            );
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_mutex_wait_start,android_vh_mutex_wait_start_handler,0);
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_mutex_unlock_slowpath,android_vh_mutex_unlock_slowpath_handler
             ,0);
  return;
}



//------------------------------------------------------------
// mutex_list_add_ux @ 0010e3d0 size=284
// signature: undefined mutex_list_add_ux(void)
// callers: [android_vh_alter_mutex_list_add_handler]
//------------------------------------------------------------

void mutex_list_add_ux(long *param_1,long *param_2)

{
  undefined4 uVar1;
  long lVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  long lVar7;
  ulong uVar8;
  long *plVar9;
  int iVar10;
  long *plVar11;
  
  lVar2 = sp_el0;
  iVar4 = task_get_mvp_prio(lVar2,1);
  if ((long *)*param_2 != param_2) {
    iVar10 = 0;
    plVar9 = (long *)*param_2;
    do {
      plVar11 = (long *)*plVar9;
      if ((((plVar9 != (long *)0x0) && (lVar7 = plVar9[2], lVar7 != 0)) &&
          (100 < *(int *)(lVar7 + 0x84))) &&
         (iVar5 = task_get_mvp_prio(lVar7,1), puVar3 = mutex_list_add_ux_trace_printk_fmt,
         iVar5 < iVar4)) {
        if (((byte)moto_sched_debug & 1) != 0) {
          uVar1 = *(undefined4 *)(lVar2 + 0x630);
          uVar6 = task_get_mvp_prio(plVar9[2],1);
          __trace_bprintk(0x10e4b0,puVar3,uVar1,iVar4,uVar6,iVar10);
        }
        plVar9 = (long *)plVar9[1];
        param_2 = (long *)*plVar9;
        goto LAB_0010e474;
      }
      iVar10 = iVar10 + 1;
      plVar9 = plVar11;
    } while (plVar11 != param_2);
  }
  plVar9 = (long *)param_2[1];
LAB_0010e474:
  uVar8 = __list_add_valid(param_1,plVar9,param_2);
  if ((uVar8 & 1) != 0) {
    param_2[1] = (long)param_1;
    *param_1 = (long)param_2;
    param_1[1] = (long)plVar9;
    *plVar9 = (long)param_1;
  }
  return;
}



//------------------------------------------------------------
// reset_rwsem_owner_list @ 0010e4f0 size=104
// signature: undefined reset_rwsem_owner_list(void)
// callers: [android_vh_free_task_handler]
//------------------------------------------------------------

void reset_rwsem_owner_list(long *param_1)

{
  long lVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  if (param_1 != (long *)0x0) {
    uVar3 = _raw_spin_lock_irqsave(&RWSEM_SPIN_LOCK);
    uVar4 = __list_del_entry_valid(param_1);
    if ((uVar4 & 1) != 0) {
      lVar1 = *param_1;
      plVar2 = (long *)param_1[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *param_1 = (long)param_1;
    param_1[1] = (long)param_1;
    _raw_spin_unlock_irqrestore(&RWSEM_SPIN_LOCK,uVar3);
  }
  return;
}



//------------------------------------------------------------
// rwsem_list_add @ 0010e55c size=392
// signature: undefined rwsem_list_add(void)
// callers: [android_vh_alter_rwsem_list_add_handler]
//------------------------------------------------------------

undefined8 rwsem_list_add(long param_1,long *param_2,long *param_3)

{
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  ulong uVar6;
  undefined8 uVar7;
  long lVar8;
  long *plVar9;
  int iVar10;
  long *plVar11;
  
  if ((param_2 == (long *)0x0) || (param_3 == (long *)0x0)) {
    _printk(&DAT_001116ba,param_2,param_3);
    uVar7 = 0;
  }
  else {
    uVar7 = sp_el0;
    iVar3 = task_get_mvp_prio(uVar7,1);
    if (iVar3 < 1) {
      uVar7 = 0;
    }
    else {
      if ((long *)*param_3 != param_3) {
        iVar10 = 0;
        plVar9 = (long *)*param_3;
        do {
          plVar11 = (long *)*plVar9;
          if (((plVar9 != (long *)0x0) && (100 < *(int *)(plVar9[2] + 0x84))) &&
             (iVar4 = task_get_mvp_prio(plVar9[2],1), puVar2 = rwsem_list_add_trace_printk_fmt,
             iVar4 < iVar3)) {
            if (((byte)moto_sched_debug & 1) != 0) {
              uVar1 = *(undefined4 *)(param_1 + 0x630);
              uVar5 = task_get_mvp_prio(plVar9[2],1);
              __trace_bprintk(0x10e6a8,puVar2,uVar1,iVar3,uVar5,iVar10);
            }
            *(char *)(param_2 + 5) = (char)plVar9[5];
            plVar11 = (long *)plVar9[1];
            *(undefined1 *)(plVar9 + 5) = 0;
            lVar8 = *plVar11;
            uVar6 = __list_add_valid(param_2,plVar11,lVar8);
            if ((uVar6 & 1) != 0) {
              *(long **)(lVar8 + 8) = param_2;
              *param_2 = lVar8;
              param_2[1] = (long)plVar11;
              *plVar11 = (long)param_2;
              return 1;
            }
            goto LAB_0010e66c;
          }
          iVar10 = iVar10 + 1;
          plVar9 = plVar11;
        } while (plVar11 != param_3);
      }
      plVar9 = (long *)param_3[1];
      uVar6 = __list_add_valid(param_2,plVar9,param_3);
      if ((uVar6 & 1) == 0) {
LAB_0010e66c:
        uVar7 = 1;
      }
      else {
        uVar7 = 1;
        param_3[1] = (long)param_2;
        *param_2 = (long)param_3;
        param_2[1] = (long)plVar9;
        *plVar9 = (long)param_2;
      }
    }
  }
  return uVar7;
}



//------------------------------------------------------------
// test_wait_timeout @ 0010e6e8 size=256
// signature: undefined test_wait_timeout(void)
// callers: [android_vh_alter_rwsem_list_add_handler]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 test_wait_timeout(undefined8 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined4 uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  
  puVar4 = test_wait_timeout_trace_printk_fmt;
  if (param_1 == (undefined8 *)0x0) {
    return 0;
  }
  if ((((uint)*param_1 >> 1 & 1) != 0) && (lVar7 = param_1[3], lVar7 != 0)) {
    lVar6 = *(long *)(lVar7 + 0x10);
    if (lVar6 == 0) {
      return 0;
    }
    lVar8 = *(long *)(lVar7 + 0x20);
    lVar7 = lVar8 + 0x4e2;
    if (lVar7 - _jiffies < 0) {
      if (((byte)moto_sched_debug & 1) != 0) {
        uVar1 = *(undefined4 *)(lVar6 + 0x630);
        uVar2 = *(undefined4 *)(lVar6 + 0x634);
        uVar3 = *(undefined4 *)(lVar6 + 0x84);
        uVar5 = task_get_ux_type();
        __trace_bprintk(0x10e774,puVar4,"test_wait_timeout",0xb4,lVar6 + 0x848,uVar1,uVar2,uVar3,
                        uVar5,lVar8,lVar8,lVar7,lVar7,_jiffies,_jiffies);
      }
      return 1;
    }
  }
  return 0;
}



//------------------------------------------------------------
// task_get_ux_type @ 0010e7e8 size=76
// signature: undefined task_get_ux_type(void)
// callers: [test_wait_timeout]
//------------------------------------------------------------

undefined4 task_get_ux_type(long param_1)

{
  ulong uVar1;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x630) != 0)) {
    uVar1 = *(ulong *)(param_1 + 0xdd8);
    if ((uVar1 != 0) && (uVar1 < 0xfffffffffffff001)) {
      return *(undefined4 *)(uVar1 + 0x2c);
    }
    _printk(&DAT_0011100e);
  }
  return 0;
}



//------------------------------------------------------------
// register_rwsem_vendor_hooks @ 0010e838 size=320
// signature: undefined register_rwsem_vendor_hooks(void)
// callers: [locking_opt_init]
//------------------------------------------------------------

void register_rwsem_vendor_hooks(void)

{
  tracepoint_probe_register
            (&__tracepoint_android_vh_alter_rwsem_list_add,android_vh_alter_rwsem_list_add_handler,0
            );
  tracepoint_probe_register(&__tracepoint_android_vh_rwsem_init,android_vh_rwsem_init,0);
  tracepoint_probe_register
            (&__tracepoint_android_vh_clear_rwsem_reader_owned,android_vh_rwsem_clear_rwsem_owned,0)
  ;
  tracepoint_probe_register
            (&__tracepoint_android_vh_clear_rwsem_writer_owned,android_vh_rwsem_clear_rwsem_owned,0)
  ;
  tracepoint_probe_register(&__tracepoint_android_vh_rwsem_wake,android_vh_rwsem_wake,0);
  tracepoint_probe_register
            (&__tracepoint_android_vh_rwsem_wake_finish,android_vh_rwsem_wake_finish_handler,0);
  tracepoint_probe_register
            (&__tracepoint_android_vh_record_rwsem_writer_owned,
             android_vh_rwsem_record_rwsem_writer_owned,0);
  tracepoint_probe_register
            (&__tracepoint_android_vh_record_rwsem_reader_owned,
             android_vh_rwsem_record_rwsem_reader_owned,0);
  tracepoint_probe_register
            (&__tracepoint_android_vh_rwsem_read_wait_finish,android_vh_rwsem_wait_finish,0);
  tracepoint_probe_register
            (&__tracepoint_android_vh_rwsem_write_wait_finish,android_vh_rwsem_wait_finish,0);
  tracepoint_probe_register
            (&__tracepoint_android_vh_record_pcpu_rwsem_time_early,
             android_vh_record_pcpu_rwsem_time_early,0);
  tracepoint_probe_register
            (&__tracepoint_android_vh_rwsem_read_trylock_failed,
             android_vh_rwsem_read_trylock_failed_handler,0);
  return;
}



//------------------------------------------------------------
// android_vh_alter_rwsem_list_add_handler @ 0010e97c size=124
// signature: undefined android_vh_alter_rwsem_list_add_handler(void)
// callers: []
//------------------------------------------------------------

void android_vh_alter_rwsem_list_add_handler
               (undefined8 param_1,long param_2,long param_3,undefined1 *param_4)

{
  ulong uVar1;
  
  if ((((param_2 != 0) && (param_3 != 0)) && (locking_inited != '\0')) &&
     (((*(int *)(param_2 + 0x18) != 1 && (uVar1 = test_wait_timeout(param_3), (uVar1 & 1) == 0)) &&
      (uVar1 = rwsem_list_add(*(undefined8 *)(param_2 + 0x10),param_2,param_3 + 0x18),
      (uVar1 & 1) != 0)))) {
    *param_4 = 1;
  }
  return;
}



//------------------------------------------------------------
// android_vh_rwsem_init @ 0010e9fc size=108
// signature: undefined android_vh_rwsem_init(void)
// callers: []
//------------------------------------------------------------

void android_vh_rwsem_init(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_2 != 0) && (locking_inited != '\0')) {
    uVar1 = _raw_spin_lock_irqsave(&RWSEM_SPIN_LOCK);
    *(undefined8 *)(param_2 + 0x28) = 0;
    *(long *)(param_2 + 0x30) = param_2 + 0x30;
    *(long *)(param_2 + 0x38) = param_2 + 0x30;
    _raw_spin_unlock_irqrestore(&RWSEM_SPIN_LOCK,uVar1);
  }
  return;
}



//------------------------------------------------------------
// android_vh_rwsem_clear_rwsem_owned @ 0010eaf8 size=216
// signature: undefined android_vh_rwsem_clear_rwsem_owned(void)
// callers: []
//------------------------------------------------------------

void android_vh_rwsem_clear_rwsem_owned(undefined8 param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  long *plVar5;
  
  lVar1 = sp_el0;
  if ((lVar1 != 0) && (*(int *)(lVar1 + 0x630) != 0)) {
    plVar5 = *(long **)(lVar1 + 0xdd8);
    if ((plVar5 != (long *)0x0) && (plVar5 < (long *)0xfffffffffffff001)) goto LAB_0010eb40;
    _printk(&DAT_0011100e);
  }
  plVar5 = (long *)0x0;
LAB_0010eb40:
  if ((locking_inited != '\0' && plVar5 != (long *)0x0) && (plVar5 < (long *)0xfffffffffffff001)) {
    uVar3 = _raw_spin_lock_irqsave(&RWSEM_SPIN_LOCK);
    if (((long *)*plVar5 != plVar5) && (plVar5[2] == param_2)) {
      uVar4 = __list_del_entry_valid(plVar5);
      if ((uVar4 & 1) != 0) {
        lVar1 = *plVar5;
        plVar2 = (long *)plVar5[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar5 = (long)plVar5;
      plVar5[1] = (long)plVar5;
      plVar5[2] = 0;
    }
    _raw_spin_unlock_irqrestore(&RWSEM_SPIN_LOCK,uVar3);
  }
  return;
}



//------------------------------------------------------------
// android_vh_rwsem_wake @ 0010ec50 size=876
// signature: undefined android_vh_rwsem_wake(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x0010f05c) */

void android_vh_rwsem_wake(undefined8 param_1,long param_2)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  long lVar6;
  byte bVar7;
  code *pcVar8;
  int iVar9;
  undefined8 uVar10;
  ulong uVar11;
  undefined8 uVar12;
  long lVar13;
  ulong uVar14;
  long *plVar15;
  long lVar16;
  long *plVar17;
  long local_e8 [17];
  
  lVar6 = sp_el0;
  local_e8[0x10] = *(long *)(lVar6 + 0x638);
  if ((param_2 == 0) || (locking_inited == '\0')) goto LAB_0010f010;
  lVar6 = sp_el0;
  iVar9 = task_get_mvp_prio(lVar6,1);
  if ((iVar9 < 0x3c) && (100 < *(int *)(lVar6 + 0x84))) goto LAB_0010f010;
  local_e8[0xe] = 0;
  local_e8[0xf] = 0;
  local_e8[0xc] = 0;
  local_e8[0xd] = 0;
  local_e8[10] = 0;
  local_e8[0xb] = 0;
  local_e8[8] = 0;
  local_e8[9] = 0;
  local_e8[6] = 0;
  local_e8[7] = 0;
  local_e8[4] = 0;
  local_e8[5] = 0;
  local_e8[2] = 0;
  local_e8[3] = 0;
  local_e8[0] = 0;
  local_e8[1] = 0;
  if ((*(long *)(param_2 + 0x38) == 0) || (plVar15 = (long *)(param_2 + 0x30), *plVar15 == 0))
  goto LAB_0010f010;
  uVar10 = _raw_spin_lock_irqsave(&RWSEM_SPIN_LOCK);
  plVar17 = *(long **)(param_2 + 0x30);
  uVar14 = *(ulong *)(param_2 + 8) & 0xfffffffffffffff8;
  if (plVar17 == plVar15) {
    bVar7 = 0;
  }
  else {
    bVar7 = 0;
    do {
      uVar11 = plVar17[4];
      if (uVar11 != 0) {
        bVar7 = uVar11 == uVar14 | bVar7;
        lock_inherit_ux_type(uVar11,lVar6,"rwsem_owner_boost");
      }
      plVar17 = (long *)*plVar17;
    } while (plVar17 != plVar15);
  }
  if ((!(bool)(bVar7 | uVar14 == 0)) && ((*(ulong *)(param_2 + 8) & 1) == 0)) {
    puVar1 = (uint *)(uVar14 + 0x40);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar3 = *puVar1;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar5) {
        *puVar1 = uVar3 + 1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    if (uVar3 == 0) {
      uVar12 = 2;
LAB_0010ee74:
      refcount_warn_saturate(puVar1,uVar12);
    }
    else if ((int)(uVar3 + 1 | uVar3) < 0) {
      uVar12 = 1;
      goto LAB_0010ee74;
    }
    lock_inherit_ux_type(uVar14,lVar6,"rwsem_cowner_boost");
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar3 = *puVar1;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar5) {
        *puVar1 = uVar3 - 1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    if (uVar3 == 1) {
      DataMemoryBarrier(2,1);
      __put_task_struct(uVar14);
    }
    else if ((int)uVar3 < 1) {
      refcount_warn_saturate(puVar1,3);
    }
  }
  plVar15 = (long *)(param_2 + 0x18);
  plVar17 = (long *)*plVar15;
  if (plVar17 != plVar15) {
    uVar14 = 0;
    do {
      lVar13 = plVar17[2];
      uVar11 = uVar14;
      if (lVar13 == lVar6) break;
      if ((lVar13 != 0) && ((int)uVar14 < 0x10)) {
        puVar1 = (uint *)(lVar13 + 0x40);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          uVar3 = *puVar1;
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar5) {
            *puVar1 = uVar3 + 1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        if (uVar3 == 0) {
          uVar12 = 2;
LAB_0010eecc:
          refcount_warn_saturate(puVar1,uVar12);
        }
        else if ((int)(uVar3 + 1 | uVar3) < 0) {
          uVar12 = 1;
          goto LAB_0010eecc;
        }
        if (0xf < uVar14) goto LAB_0010f058;
        uVar11 = uVar14 + 1;
        local_e8[uVar14] = plVar17[2];
      }
      plVar17 = (long *)*plVar17;
      uVar14 = uVar11;
    } while (plVar17 != plVar15);
    if (0 < (int)uVar11) {
      lVar13 = 0;
      do {
        if (lVar13 == 0x80) {
LAB_0010f058:
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x10f05c);
          (*pcVar8)();
        }
        lVar16 = *(long *)((long)local_e8 + lVar13);
        lock_inherit_ux_type(lVar16,lVar6,"rwsem_waiter_boost");
        piVar2 = (int *)(lVar16 + 0x40);
        Hint_Prefetch(piVar2,2,0,1);
        do {
          iVar9 = *piVar2;
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
          if (bVar5) {
            *piVar2 = iVar9 + -1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        if (iVar9 == 1) {
          DataMemoryBarrier(2,1);
          __put_task_struct(lVar16);
        }
        else if (iVar9 < 1) {
          refcount_warn_saturate(piVar2,3);
        }
        lVar13 = lVar13 + 8;
      } while (uVar11 * 8 != lVar13);
    }
  }
  *(undefined8 *)(param_2 + 0x28) = 1;
  _raw_spin_unlock_irqrestore(&RWSEM_SPIN_LOCK,uVar10);
LAB_0010f010:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_e8[0x10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// android_vh_rwsem_wake_finish_handler @ 0010f0e4 size=52
// signature: undefined android_vh_rwsem_wake_finish_handler(void)
// callers: []
//------------------------------------------------------------

void android_vh_rwsem_wake_finish_handler(void)

{
  undefined8 uVar1;
  
  if (locking_inited != '\0') {
    uVar1 = sp_el0;
    lock_clear_inherited_ux_type(uVar1,"rwsem_wake_finish");
  }
  return;
}



//------------------------------------------------------------
// android_vh_rwsem_record_rwsem_writer_owned @ 0010f11c size=312
// signature: undefined android_vh_rwsem_record_rwsem_writer_owned(void)
// callers: []
//------------------------------------------------------------

void android_vh_rwsem_record_rwsem_writer_owned(undefined8 param_1,long param_2)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  long *plVar6;
  long *plVar7;
  
  lVar2 = sp_el0;
  if ((lVar2 != 0) && (*(int *)(lVar2 + 0x630) != 0)) {
    plVar6 = *(long **)(lVar2 + 0xdd8);
    if ((plVar6 != (long *)0x0) && (plVar6 < (long *)0xfffffffffffff001)) goto joined_r0x0010f170;
    _printk(&DAT_0011100e);
  }
  plVar6 = (long *)0x0;
joined_r0x0010f170:
  if ((((param_2 != 0) && (locking_inited != '\0')) && (plVar6 != (long *)0x0)) &&
     (plVar6 < (long *)0xfffffffffffff001)) {
    plVar1 = (long *)(param_2 + 0x30);
    uVar4 = _raw_spin_lock_irqsave(&RWSEM_SPIN_LOCK);
    if ((*(long **)(param_2 + 0x38) == (long *)0x0) ||
       (plVar7 = *(long **)(param_2 + 0x38), *plVar1 == 0)) {
      *(long **)(param_2 + 0x30) = plVar1;
      *(long **)(param_2 + 0x38) = plVar1;
      plVar7 = plVar1;
    }
    if ((long *)*plVar6 == plVar6) {
      uVar5 = __list_add_valid(plVar6,plVar7,plVar1);
      if ((uVar5 & 1) != 0) {
        *(long **)(param_2 + 0x38) = plVar6;
        *plVar6 = (long)plVar1;
        plVar6[1] = (long)plVar7;
        *plVar7 = (long)plVar6;
      }
      plVar6[2] = param_2;
    }
    if (((*(long *)(param_2 + 0x28) != 0) && (iVar3 = task_get_mvp_prio(lVar2,1), iVar3 < 0x3c)) &&
       (100 < *(int *)(lVar2 + 0x84))) {
      lock_inherit_ux_type(lVar2,lVar2,"rwsem_leak_boost");
    }
    _raw_spin_unlock_irqrestore(&RWSEM_SPIN_LOCK,uVar4);
  }
  return;
}



//------------------------------------------------------------
// android_vh_rwsem_record_rwsem_reader_owned @ 0010f2d4 size=488
// signature: undefined android_vh_rwsem_record_rwsem_reader_owned(void)
// callers: []
//------------------------------------------------------------

void android_vh_rwsem_record_rwsem_reader_owned(undefined8 param_1,long param_2,long *param_3)

{
  long *plVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  long lVar6;
  long *plVar7;
  long *plVar8;
  undefined8 *puVar9;
  
  if (param_2 == 0) {
    return;
  }
  if (locking_inited == '\0') {
    return;
  }
  plVar1 = (long *)(param_2 + 0x30);
  uVar4 = _raw_spin_lock_irqsave(&RWSEM_SPIN_LOCK);
  plVar7 = *(long **)(param_2 + 0x38);
  if ((plVar7 == (long *)0x0) || (*plVar1 == 0)) {
    *(long **)(param_2 + 0x30) = plVar1;
    *(long **)(param_2 + 0x38) = plVar1;
    plVar7 = plVar1;
  }
  if ((param_3 == (long *)0x0) || (plVar8 = (long *)*param_3, plVar8 == param_3)) {
    lVar6 = sp_el0;
    if ((lVar6 != 0) && (*(int *)(lVar6 + 0x630) != 0)) {
      plVar8 = *(long **)(lVar6 + 0xdd8);
      if ((plVar8 == (long *)0x0) || ((long *)0xfffffffffffff000 < plVar8)) {
        _printk(&DAT_0011100e);
      }
      else {
        if ((long *)*plVar8 == plVar8) {
          uVar5 = __list_add_valid(plVar8,plVar7,plVar1);
          if ((uVar5 & 1) != 0) {
            *(long **)(param_2 + 0x38) = plVar8;
            *plVar8 = (long)plVar1;
            plVar8[1] = (long)plVar7;
            *plVar7 = (long)plVar8;
          }
          plVar8[2] = param_2;
        }
        if (((*(long *)(param_2 + 0x28) != 0) && (iVar3 = task_get_mvp_prio(lVar6,1), iVar3 < 0x3c))
           && (100 < *(int *)(lVar6 + 0x84))) {
          lock_inherit_ux_type(lVar6,lVar6,"rwsem_leak_boost");
        }
      }
    }
  }
  else {
    uVar2 = sp_el0;
    do {
      lVar6 = plVar8[2];
      if ((lVar6 != 0) && (*(int *)(lVar6 + 0x630) != 0)) {
        plVar7 = *(long **)(lVar6 + 0xdd8);
        if ((plVar7 == (long *)0x0) || ((long *)0xfffffffffffff000 < plVar7)) {
          _printk(&DAT_0011100e);
        }
        else if ((long *)*plVar7 == plVar7) {
          puVar9 = *(undefined8 **)(param_2 + 0x38);
          uVar5 = __list_add_valid(plVar7,puVar9,plVar1);
          if ((uVar5 & 1) != 0) {
            *(long **)(param_2 + 0x38) = plVar7;
            *plVar7 = (long)plVar1;
            plVar7[1] = (long)puVar9;
            *puVar9 = plVar7;
          }
          plVar7[2] = param_2;
        }
      }
      plVar8 = (long *)*plVar8;
    } while (plVar8 != param_3);
  }
  _raw_spin_unlock_irqrestore(&RWSEM_SPIN_LOCK,uVar4);
  return;
}



//------------------------------------------------------------
// android_vh_rwsem_wait_finish @ 0010f5ac size=120
// signature: undefined android_vh_rwsem_wait_finish(void)
// callers: []
//------------------------------------------------------------

void android_vh_rwsem_wait_finish(undefined8 param_1,long param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  if ((param_2 != 0) && (locking_inited != '\0')) {
    lVar1 = sp_el0;
    iVar2 = task_get_mvp_prio(lVar1,1);
    if ((0x3b < iVar2) || (*(int *)(lVar1 + 0x84) < 0x65)) {
      uVar3 = _raw_spin_lock_irqsave(&RWSEM_SPIN_LOCK);
      *(undefined8 *)(param_2 + 0x28) = 0;
      _raw_spin_unlock_irqrestore(&RWSEM_SPIN_LOCK,uVar3);
    }
  }
  return;
}



//------------------------------------------------------------
// android_vh_record_pcpu_rwsem_time_early @ 0010f628 size=76
// signature: undefined android_vh_record_pcpu_rwsem_time_early(void)
// callers: []
//------------------------------------------------------------

void android_vh_record_pcpu_rwsem_time_early
               (undefined8 param_1,undefined8 param_2,undefined *param_3)

{
  undefined8 uVar1;
  
  if ((param_3 == &cgroup_threadgroup_rwsem) && (locking_inited != '\0')) {
    uVar1 = sp_el0;
    lock_protect_update_starttime(uVar1,param_2,"percpu_rwsem",&cgroup_threadgroup_rwsem);
  }
  return;
}



//------------------------------------------------------------
// android_vh_rwsem_read_trylock_failed_handler @ 0010f678 size=216
// signature: undefined android_vh_rwsem_read_trylock_failed_handler(void)
// callers: []
//------------------------------------------------------------

void android_vh_rwsem_read_trylock_failed_handler
               (undefined8 param_1,long *param_2,long param_3,undefined4 *param_4)

{
  char cVar1;
  bool bVar2;
  long lVar3;
  int iVar4;
  
  if ((((param_4 != (undefined4 *)0x0) && (param_2 != (long *)0x0)) && (locking_inited != '\0')) &&
     ((param_2[1] & 1U) != 0)) {
    lVar3 = sp_el0;
    iVar4 = task_get_mvp_prio(lVar3,1);
    if (((lVar3 != 0) &&
        (((0xfffffffd < *(int *)(lVar3 + 0x488) - 3U ||
          ((iVar4 == 0x46 && (iVar4 = strcmp((char *)(lVar3 + 0x848),"RenderThread"), iVar4 == 0))))
         && (0xff < *param_2)))) &&
       ((((uint)*param_2 >> 2 & 1) == 0 && (*param_4 = 1, param_3 == 0)))) {
      Hint_Prefetch(param_2,2,0,1);
      do {
        cVar1 = '\x01';
        bVar2 = (bool)ExclusiveMonitorPass(param_2,0x10);
        if (bVar2) {
          *param_2 = *param_2 + 0x100;
          cVar1 = ExclusiveMonitorsStatus();
        }
      } while (cVar1 != '\0');
    }
  }
  return;
}



//------------------------------------------------------------
// unregister_rwsem_vendor_hooks @ 0010f7c8 size=320
// signature: undefined unregister_rwsem_vendor_hooks(void)
// callers: [locking_opt_exit]
//------------------------------------------------------------

void unregister_rwsem_vendor_hooks(void)

{
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_alter_rwsem_list_add,android_vh_alter_rwsem_list_add_handler,0
            );
  tracepoint_probe_unregister(&__tracepoint_android_vh_rwsem_init,android_vh_rwsem_init,0);
  tracepoint_probe_unregister(&__tracepoint_android_vh_rwsem_wake,android_vh_rwsem_wake,0);
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_rwsem_wake_finish,android_vh_rwsem_wake_finish_handler,0);
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_record_rwsem_writer_owned,
             android_vh_rwsem_record_rwsem_writer_owned,0);
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_record_rwsem_reader_owned,
             android_vh_rwsem_record_rwsem_reader_owned,0);
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_clear_rwsem_writer_owned,android_vh_rwsem_clear_rwsem_owned,0)
  ;
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_clear_rwsem_reader_owned,android_vh_rwsem_clear_rwsem_owned,0)
  ;
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_rwsem_read_wait_finish,android_vh_rwsem_wait_finish,0);
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_rwsem_write_wait_finish,android_vh_rwsem_wait_finish,0);
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_record_pcpu_rwsem_time_early,
             android_vh_record_pcpu_rwsem_time_early,0);
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_rwsem_read_trylock_failed,
             android_vh_rwsem_read_trylock_failed_handler,0);
  return;
}



//------------------------------------------------------------
// rvh_uclamp_eff_get @ 0010f92c size=492
// signature: undefined rvh_uclamp_eff_get(void)
// callers: [set_uclamp_inheritance, uclamp_eff_value_moto]
//------------------------------------------------------------

void rvh_uclamp_eff_get(undefined8 param_1,long param_2,uint param_3,uint *param_4,uint *param_5,
                       undefined4 *param_6)

{
  uint uVar1;
  code *pcVar2;
  bool bVar3;
  ulong uVar4;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ulong uVar9;
  
  if (param_2 == 0) {
    return;
  }
  if (*(int *)(param_2 + 0x630) == 0) {
    return;
  }
  if ((*(ulong *)(param_2 + 0xdd8) == 0) || (0xfffffffffffff000 < *(ulong *)(param_2 + 0xdd8))) {
    _printk(&DAT_0011100e);
    return;
  }
  if ((moto_sched_enabled._1_1_ >> 1 & 1) == 0) {
    *param_6 = 0;
    return;
  }
  *param_6 = 1;
  if (2 < param_3) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10fba0);
    (*pcVar2)();
  }
  uVar8 = *(uint *)(param_2 + (ulong)param_3 * 4 + 0x350);
  if (*(int *)(param_2 + 0x630) == 0) goto LAB_0010fa90;
  uVar9 = *(ulong *)(param_2 + 0xdd8);
  if ((uVar9 == 0) || (0xfffffffffffff000 < uVar9)) {
    _printk(&DAT_0011100e);
    if (*(int *)(param_2 + 0x630) == 0) goto LAB_0010fa90;
    uVar9 = 0;
    uVar4 = *(ulong *)(param_2 + 0xdd8);
    if (uVar4 != 0) goto LAB_0010f9c4;
LAB_0010faf0:
    _printk(&DAT_0011100e);
    uVar4 = 0;
  }
  else {
    uVar4 = *(ulong *)(param_2 + 0xdd8);
    if (uVar4 == 0) goto LAB_0010faf0;
LAB_0010f9c4:
    if (0xfffffffffffff000 < uVar4) goto LAB_0010faf0;
  }
  if ((((uVar9 != 0) && (uVar9 < 0xfffffffffffff001)) && (uVar4 != 0)) &&
     (uVar4 < 0xfffffffffffff001)) {
    puVar5 = *(undefined **)(param_2 + 0x348);
    if (puVar5 == &root_task_group) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(uint *)(puVar5 + 0x1a0) & 0x7ff;
    }
    uVar6 = uVar8 & 0x7ff;
    uVar1 = uVar6;
    if (uVar6 <= uVar7) {
      uVar1 = uVar7;
    }
    if ((*(uint *)(puVar5 + 0x1a4) & 0x7ff) <= uVar6) {
      uVar1 = *(uint *)(puVar5 + 0x1a4) & 0x7ff;
    }
    uVar7 = uVar1;
    if (uVar1 <= *(ushort *)(uVar9 + 0x44)) {
      uVar7 = (uint)*(ushort *)(uVar9 + 0x44);
    }
    if (*(ushort *)(uVar9 + 0x46) <= uVar1) {
      uVar7 = (uint)*(ushort *)(uVar9 + 0x46);
    }
    if (*(char *)(uVar4 + 0x48) != '\0') {
      uVar6 = uVar7;
      if (uVar7 <= *(ushort *)(uVar4 + 0x40)) {
        uVar6 = (uint)*(ushort *)(uVar4 + 0x40);
      }
      bVar3 = *(ushort *)(uVar4 + 0x42) <= uVar7;
      uVar7 = uVar6;
      if (bVar3) {
        uVar7 = (uint)*(ushort *)(uVar4 + 0x42);
      }
    }
    uVar6 = uVar7 / 0x33;
    if (0x12 < uVar6) {
      uVar6 = 0x13;
    }
    uVar8 = uVar8 & 0xffff0000 | uVar7 & 0x7ff | uVar6 << 0xb;
  }
LAB_0010fa90:
  if ((*param_4 & 0x7ff) < (uVar8 & 0x7ff)) {
    *param_5 = *param_4;
  }
  else {
    *param_5 = uVar8;
  }
  return;
}



//------------------------------------------------------------
// trace_msched_uclamp_restriction_result @ 0010fc70 size=56
// signature: undefined trace_msched_uclamp_restriction_result(void)
// callers: []
//------------------------------------------------------------

void trace_msched_uclamp_restriction_result(void)

{
  return;
}



//------------------------------------------------------------
// set_uclamp_inheritance @ 0010fd40 size=480
// signature: undefined set_uclamp_inheritance(void)
// callers: [rvh_rtmutex_prepare_setprio, msched_uclamp_binder_set_priority_hook, msched_uclamp_binder_restore_priority_hook]
//------------------------------------------------------------

void set_uclamp_inheritance(long param_1,long param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined8 local_90;
  undefined8 local_88;
  undefined1 auStack_7c [4];
  uint local_78 [2];
  undefined4 local_70 [2];
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  local_90 = 0;
  local_88 = 0;
  if (param_4 == 1) {
    lVar4 = __task_rq_lock();
  }
  else {
    lVar4 = task_rq_lock(param_1,&local_90);
  }
  uVar9 = (uint)*(ushort *)(param_1 + 0xc76);
  uVar5 = uclamp_eff_value_moto(param_1,0);
  local_78[0] = 0;
  local_70[0] = 0x9c00;
  uVar7 = *(uint *)(param_1 + 0x35c);
  if ((*(uint *)(param_1 + 0x35c) >> 0x10 & 1) == 0) {
    rvh_uclamp_eff_get(uVar5,param_1,1,local_70,local_78,auStack_7c);
    uVar7 = local_78[0];
  }
  uVar7 = uVar7 & 0x7ff;
  if (param_2 == 0) {
    *param_3 = 0x4000000;
  }
  else {
    uVar10 = (uint)*(ushort *)(param_2 + 0xc76);
    uVar6 = uclamp_eff_value_moto(param_2,0);
    local_78[0] = 0;
    local_70[0] = 0x9c00;
    uVar8 = *(uint *)(param_2 + 0x35c);
    if ((*(uint *)(param_2 + 0x35c) >> 0x10 & 1) == 0) {
      rvh_uclamp_eff_get(uVar6,param_2,1,local_70,local_78,auStack_7c);
      uVar8 = local_78[0];
    }
    uVar1 = (uint)uVar5 & 0xffff;
    uVar2 = (uint)uVar6 & 0xffff;
    uVar8 = uVar8 & 0x7ff;
    uVar3 = uVar9;
    if (uVar9 <= uVar1) {
      uVar3 = uVar1;
    }
    if (uVar7 <= uVar9) {
      uVar3 = uVar7;
    }
    uVar9 = uVar10;
    if (uVar10 <= uVar2) {
      uVar9 = uVar2;
    }
    if (uVar8 <= uVar10) {
      uVar9 = uVar8;
    }
    if ((uVar9 < 0x400) && (uVar3 < uVar9)) {
      *(short *)param_3 = (short)uVar9;
    }
    if ((uVar7 < uVar8) || (uVar7 < uVar9)) {
      *(short *)((long)param_3 + 2) = (short)uVar8;
    }
  }
  if (param_4 == 1) {
    if (2 < *(uint *)(lVar4 + 0xac8)) {
      local_88 = CONCAT44(local_88._4_4_,4);
    }
    raw_spin_rq_unlock(lVar4);
  }
  else {
    if (2 < *(uint *)(lVar4 + 0xac8)) {
      local_88 = CONCAT44(local_88._4_4_,4);
    }
    raw_spin_rq_unlock(lVar4);
    _raw_spin_unlock_irqrestore(param_1 + 0x924,local_90);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// uclamp_eff_value_moto @ 00110040 size=192
// signature: undefined uclamp_eff_value_moto(void)
// callers: [set_uclamp_inheritance]
//------------------------------------------------------------

uint uclamp_eff_value_moto(long param_1,uint param_2)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  uint *puVar4;
  undefined1 auStack_3c [4];
  uint local_38 [2];
  undefined4 local_30 [2];
  long local_28;
  
  lVar3 = sp_el0;
  lVar1 = param_1 + (ulong)param_2 * 4;
  local_28 = *(long *)(lVar3 + 0x638);
  uVar2 = *(uint *)(lVar1 + 0x358);
  local_38[0] = 0;
  local_30[0] = 0x9c00;
  if ((uVar2 >> 0x10 & 1) == 0) {
    puVar4 = local_38;
    rvh_uclamp_eff_get(param_1,param_1,param_2,local_30,local_38,auStack_3c);
  }
  else {
    puVar4 = (uint *)(lVar1 + 0x358);
    if ((param_2 == 0) && (((byte)moto_sched_debug >> 3 & 1) != 0)) {
      __trace_bprintk(0x1100dc,uclamp_eff_value_moto_trace_printk_fmt,
                      *(undefined4 *)(param_1 + 0x630),uVar2 & 0x7ff);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return *puVar4 & 0x7ff;
}



//------------------------------------------------------------
// msched_uclamp_vh_dup_task_struct @ 00110104 size=4
// signature: undefined msched_uclamp_vh_dup_task_struct(void)
// callers: [android_vh_dup_task_struct_handler]
//------------------------------------------------------------

void msched_uclamp_vh_dup_task_struct(void)

{
  return;
}



//------------------------------------------------------------
// msched_uclamp_binder_set_priority_hook @ 0011010c size=212
// signature: undefined msched_uclamp_binder_set_priority_hook(void)
// callers: [binder_inherit_ux_type]
//------------------------------------------------------------

void msched_uclamp_binder_set_priority_hook(long param_1)

{
  int iVar1;
  char cVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  ulong uVar5;
  
  if (((param_1 != 0) && ((moto_sched_enabled >> 9 & 1) != 0)) &&
     (iVar1 = *(int *)(param_1 + 0x630), iVar1 != 0)) {
    uVar5 = *(ulong *)(param_1 + 0xdd8);
    if ((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) {
      _printk(&DAT_0011100e,iVar1);
    }
    else {
      if (((byte)moto_sched_debug >> 3 & 1) == 0) {
        cVar2 = *(char *)(uVar5 + 0x48);
      }
      else {
        if (*(long *)(param_1 + 0x640) == 0) {
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = *(undefined4 *)(*(long *)(param_1 + 0x640) + 0x630);
        }
        __trace_bprintk(0x110194,msched_uclamp_binder_set_priority_hook_trace_printk_fmt,
                        *(undefined4 *)(param_1 + 0x634),iVar1,*(undefined2 *)(param_1 + 0xc76),
                        *(byte *)(param_1 + 0x5e4) & 1,uVar4);
        cVar2 = *(char *)(uVar5 + 0x48);
      }
      if (cVar2 == '\0') {
        uVar3 = sp_el0;
        *(undefined1 *)(uVar5 + 0x48) = 1;
        set_uclamp_inheritance(param_1,uVar3,uVar5 + 0x40,0);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// msched_uclamp_binder_restore_priority_hook @ 001101e4 size=208
// signature: undefined msched_uclamp_binder_restore_priority_hook(void)
// callers: [binder_clear_inherited_ux_type]
//------------------------------------------------------------

void msched_uclamp_binder_restore_priority_hook(long param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  ulong uVar4;
  
  if (((param_1 != 0) && ((moto_sched_enabled >> 9 & 1) != 0)) &&
     (iVar1 = *(int *)(param_1 + 0x630), iVar1 != 0)) {
    uVar4 = *(ulong *)(param_1 + 0xdd8);
    if ((uVar4 == 0) || (0xfffffffffffff000 < uVar4)) {
      _printk(&DAT_0011100e,iVar1);
    }
    else {
      if (((byte)moto_sched_debug >> 3 & 1) == 0) {
        cVar2 = *(char *)(uVar4 + 0x48);
      }
      else {
        if (*(long *)(param_1 + 0x640) == 0) {
          uVar3 = 0xffffffff;
        }
        else {
          uVar3 = *(undefined4 *)(*(long *)(param_1 + 0x640) + 0x630);
        }
        __trace_bprintk(0x110268,msched_uclamp_binder_restore_priority_hook_trace_printk_fmt,
                        *(undefined4 *)(param_1 + 0x634),iVar1,*(undefined2 *)(param_1 + 0xc76),
                        *(byte *)(param_1 + 0x5e4) & 1,uVar3);
        cVar2 = *(char *)(uVar4 + 0x48);
      }
      if (cVar2 != '\0') {
        set_uclamp_inheritance(param_1,0,uVar4 + 0x40,0);
        *(undefined1 *)(uVar4 + 0x48) = 0;
      }
    }
  }
  return;
}



//------------------------------------------------------------
// msched_uclamp_register_vendor_comm_hooks @ 001102b8 size=100
// signature: undefined msched_uclamp_register_vendor_comm_hooks(void)
// callers: [register_vendor_comm_hooks]
//------------------------------------------------------------

undefined8 msched_uclamp_register_vendor_comm_hooks(void)

{
  android_rvh_probe_register
            (&__tracepoint_android_rvh_rtmutex_prepare_setprio,rvh_rtmutex_prepare_setprio,0);
  android_rvh_probe_register(&__tracepoint_android_rvh_uclamp_eff_get,rvh_uclamp_eff_get,0);
  android_rvh_probe_register(&__tracepoint_android_rvh_sched_fork_init,rvh_sched_fork_init,0);
  return 0;
}



//------------------------------------------------------------
// rvh_rtmutex_prepare_setprio @ 00110320 size=108
// signature: undefined rvh_rtmutex_prepare_setprio(void)
// callers: []
//------------------------------------------------------------

void rvh_rtmutex_prepare_setprio(undefined8 param_1,long param_2,undefined8 param_3)

{
  ulong uVar1;
  
  if ((param_2 != 0) && ((moto_sched_enabled >> 9 & 1) != 0)) {
    if (*(int *)(param_2 + 0x630) != 0) {
      uVar1 = *(ulong *)(param_2 + 0xdd8);
      if ((uVar1 == 0) || (0xfffffffffffff000 < uVar1)) {
        _printk(&DAT_0011100e,*(int *)(param_2 + 0x630));
      }
      else {
        set_uclamp_inheritance(param_2,param_3,uVar1 + 0x44,1);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// rvh_sched_fork_init @ 00110390 size=84
// signature: undefined rvh_sched_fork_init(void)
// callers: []
//------------------------------------------------------------

void rvh_sched_fork_init(undefined8 param_1,long param_2)

{
  ulong uVar1;
  
  if ((param_2 != 0) && (*(int *)(param_2 + 0x630) != 0)) {
    uVar1 = *(ulong *)(param_2 + 0xdd8);
    if ((uVar1 == 0) || (0xfffffffffffff000 < uVar1)) {
      _printk(&DAT_0011100e);
    }
    else {
      *(undefined1 *)(uVar1 + 0x48) = 0;
      *(undefined8 *)(uVar1 + 0x40) = 0x400000004000000;
    }
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001103f8 size=68
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  undefined8 uVar1;
  
  uVar1 = msched_oemdata_init();
  if (((int)uVar1 == 0) && (uVar1 = moto_sched_proc_init(), (int)uVar1 == 0)) {
    register_vendor_comm_hooks();
    locking_opt_init();
    _printk(&DAT_00110921);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// _printk @ 0011a000 size=1
// signature: undefined _printk(void)
// callers: [proc_ux_task_read, binder_inherit_ux_type, init_module, android_vh_rwsem_clear_rwsem_owned, moto_sched_proc_init, all_ux_tasks_read, lock_clear_inherited_ux_type, lock_protect_update_starttime, task_ux_type_set, get_moto_task_struct, binder_ux_type_set, binder_inherit_ux_type_from_client, task_get_ux_type, msched_uclamp_binder_set_priority_hook, rvh_sched_fork_init, task_in_ux_related_group, msched_uclamp_binder_restore_priority_hook, rvh_rtmutex_prepare_setprio, rwsem_list_add, task_get_ux_type, lock_inherit_ux_type, task_has_ux_type, task_get_mvp_prio, task_ux_type_clear, android_vh_rwsem_record_rwsem_reader_owned, android_vh_rwsem_record_rwsem_writer_owned, rvh_uclamp_eff_get, queue_ux_task, android_vh_dup_task_struct_handler, binder_clear_inherited_ux_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_mkdir @ 0011a008 size=1
// signature: undefined proc_mkdir(void)
// callers: [moto_sched_proc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_mkdir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_create @ 0011a010 size=1
// signature: undefined proc_create(void)
// callers: [moto_sched_proc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// remove_proc_entry @ 0011a018 size=1
// signature: undefined remove_proc_entry(void)
// callers: [moto_sched_proc_init, moto_sched_proc_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void remove_proc_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 0011a020 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [proc_ux_task_read, proc_boost_pid_read, proc_version_read, proc_boost_task_util_read, proc_debug_read, all_ux_tasks_read, proc_boost_prio_read, proc_ux_scene_read, proc_enabled_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 0011a028 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [proc_ux_task_read, proc_boost_pid_read, proc_version_read, proc_boost_task_util_read, proc_debug_read, all_ux_tasks_read, proc_boost_prio_read, proc_ux_scene_read, proc_enabled_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0011a030 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [perf_trace_sched_boost_ux_kworker, perf_trace_set_user_nice, perf_trace_msched_uclamp_restriction_result, trace_event_raw_event_rwsem_read_trylock_steal, proc_boost_task_util_write, trace_event_raw_event_lock_pi_finish, uclamp_eff_value_moto, perf_trace_rwsem_read_trylock_steal, trace_event_raw_event_lock_pi_start, proc_enabled_read, proc_debug_write, perf_trace_msched_pr_set_vma_name_bypass, trace_event_raw_event_binder_inherit_ux_type, proc_ux_task_write, trace_event_raw_event_binder_nothread_be_select, perf_trace_msched_uclamp_inheritance_result, trace_event_raw_event_binder_pick_best_thread, perf_trace_percpu_rwsem_up_write, perf_trace_binder_inherit_rt_check, proc_ux_scene_write, trace_event_raw_event_msched_uclamp_restriction_result, perf_trace_sched_percpu_rwsem_hold_time, perf_trace_lock_pi_finish, lock_inherit_ux_type, perf_trace_binder_inherit_rt_prio, perf_trace_locking_debug_trace, proc_boost_task_util_read, trace_event_raw_event_binder_inherit_rt_prio, trace_event_raw_event_set_user_nice, trace_event_raw_event_sched_percpu_rwsem_hold_time, perf_trace_sched_wake_by_irq_kth, proc_ux_task_read, proc_boost_pid_write, trace_event_raw_event_binder_inherit_rt_check, proc_debug_read, all_ux_tasks_read, trace_event_raw_event_locking_debug_trace, binder_inherit_rt_prio, lock_clear_inherited_ux_type, proc_boost_prio_write, trace_event_raw_event_msched_task_get_mvp_prio, perf_trace_lock_pi_start, resched_task, set_uclamp_inheritance, android_vh_rwsem_wake, proc_boost_prio_read, trace_event_raw_event_msched_uclamp_inheritance_result, trace_event_raw_event_sched_boost_ux_kworker, perf_trace_msched_task_get_mvp_prio, trace_event_raw_event_rwsem_pi_start, perf_trace_rwsem_pi_start, proc_boost_pid_read, proc_version_read, trace_event_raw_event_rwsem_pi_finish, trace_event_raw_event_percpu_rwsem_wait_complete, proc_ux_scene_read, trace_event_raw_event_percpu_rwsem_up_write, perf_trace_binder_nothread_be_select, perf_trace_rwsem_pi_finish, trace_event_raw_event_percpu_rwsem_down_read_preempt, trace_event_raw_event_sched_wake_by_irq_kth, perf_trace_sched_percpu_rwsem_starttime, perf_trace_percpu_rwsem_wait_complete, perf_trace_binder_pick_best_thread, proc_enabled_write, perf_trace_percpu_rwsem_down_read_preempt, perf_trace_binder_inherit_ux_type, trace_event_raw_event_msched_pr_set_vma_name_bypass, trace_event_raw_event_sched_percpu_rwsem_starttime]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 0011a038 size=1
// signature: undefined __check_object_size(void)
// callers: [proc_ux_task_write, proc_ux_scene_write, proc_boost_pid_write, proc_boost_task_util_write, proc_enabled_write, proc_debug_write, proc_boost_prio_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 0011a050 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [proc_ux_task_write, proc_ux_scene_write, proc_boost_pid_write, proc_boost_task_util_write, proc_enabled_write, proc_debug_write, proc_boost_prio_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strim @ 0011a058 size=1
// signature: undefined strim(void)
// callers: [proc_ux_task_write, proc_ux_scene_write, proc_boost_pid_write, proc_boost_task_util_write, proc_enabled_write, proc_debug_write, proc_boost_prio_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strim(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 0011a060 size=1
// signature: undefined kstrtoint(void)
// callers: [proc_ux_task_write, proc_ux_scene_write, proc_boost_pid_write, proc_boost_task_util_write, proc_enabled_write, proc_debug_write, proc_boost_prio_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// set_moto_sched_enabled @ 0011a068 size=1
// signature: undefined set_moto_sched_enabled(void)
// callers: [proc_enabled_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void set_moto_sched_enabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// set_moto_sched_ops @ 0011a070 size=1
// signature: undefined set_moto_sched_ops(void)
// callers: [proc_enabled_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void set_moto_sched_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0011a080 size=1
// signature: undefined mutex_lock(void)
// callers: [task_ux_type_set, task_ux_type_clear, proc_ux_scene_write, proc_boost_task_util_write, proc_boost_prio_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0011a088 size=1
// signature: undefined mutex_unlock(void)
// callers: [task_ux_type_set, task_ux_type_clear, proc_ux_scene_write, proc_boost_task_util_write, proc_boost_prio_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// find_task_by_vpid @ 0011a090 size=1
// signature: undefined find_task_by_vpid(void)
// callers: [proc_ux_task_read, task_ux_type_set, task_ux_type_clear, android_vh_percpu_rwsem_down_read_preempt_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void find_task_by_vpid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __put_task_struct @ 0011a098 size=1
// signature: undefined __put_task_struct(void)
// callers: [proc_ux_task_read, task_ux_type_set, task_ux_type_clear, resched_task, android_vh_rwsem_wake, android_vh_mutex_wait_start_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __put_task_struct(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 0011a0a0 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [proc_ux_task_read, task_ux_type_set, task_ux_type_clear, resched_task, android_vh_rwsem_wake, android_vh_mutex_wait_start_handler, android_rvh_pr_set_vma_name_bypass]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 0011a0a8 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [proc_ux_task_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlcpy @ 0011a0b0 size=1
// signature: undefined strlcpy(void)
// callers: [proc_ux_task_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_lock @ 0011a0b8 size=1
// signature: undefined __rcu_read_lock(void)
// callers: [task_ux_type_set, task_ux_type_clear, all_ux_tasks_read, android_vh_percpu_rwsem_down_read_preempt_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_unlock @ 0011a0c8 size=1
// signature: undefined __rcu_read_unlock(void)
// callers: [task_ux_type_set, task_ux_type_clear, all_ux_tasks_read, android_vh_percpu_rwsem_down_read_preempt_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 0011a0d0 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_binder_inherit_rt_check, trace_event_raw_event_rwsem_pi_finish, trace_event_raw_event_msched_uclamp_restriction_result, trace_event_raw_event_rwsem_read_trylock_steal, trace_event_raw_event_locking_debug_trace, trace_event_raw_event_lock_pi_finish, trace_event_raw_event_percpu_rwsem_wait_complete, trace_event_raw_event_percpu_rwsem_up_write, trace_event_raw_event_lock_pi_start, trace_event_raw_event_percpu_rwsem_down_read_preempt, trace_event_raw_event_msched_task_get_mvp_prio, trace_event_raw_event_binder_inherit_ux_type, trace_event_raw_event_sched_wake_by_irq_kth, trace_event_raw_event_binder_nothread_be_select, trace_event_raw_event_msched_uclamp_inheritance_result, trace_event_raw_event_sched_boost_ux_kworker, trace_event_raw_event_binder_pick_best_thread, trace_event_raw_event_msched_pr_set_vma_name_bypass, trace_event_raw_event_binder_inherit_rt_prio, trace_event_raw_event_set_user_nice, trace_event_raw_event_sched_percpu_rwsem_starttime, trace_event_raw_event_sched_percpu_rwsem_hold_time, trace_event_raw_event_rwsem_pi_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 0011a0d8 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_binder_inherit_rt_check, trace_event_raw_event_rwsem_pi_finish, trace_event_raw_event_msched_uclamp_restriction_result, trace_event_raw_event_rwsem_read_trylock_steal, trace_event_raw_event_locking_debug_trace, trace_event_raw_event_lock_pi_finish, trace_event_raw_event_percpu_rwsem_wait_complete, trace_event_raw_event_percpu_rwsem_up_write, trace_event_raw_event_lock_pi_start, trace_event_raw_event_percpu_rwsem_down_read_preempt, trace_event_raw_event_msched_task_get_mvp_prio, trace_event_raw_event_binder_inherit_ux_type, trace_event_raw_event_sched_wake_by_irq_kth, trace_event_raw_event_binder_nothread_be_select, trace_event_raw_event_msched_uclamp_inheritance_result, trace_event_raw_event_sched_boost_ux_kworker, trace_event_raw_event_binder_pick_best_thread, trace_event_raw_event_msched_pr_set_vma_name_bypass, trace_event_raw_event_binder_inherit_rt_prio, trace_event_raw_event_set_user_nice, trace_event_raw_event_sched_percpu_rwsem_starttime, trace_event_raw_event_sched_percpu_rwsem_hold_time, trace_event_raw_event_rwsem_pi_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 0011a0e0 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_binder_inherit_rt_check, trace_event_raw_event_rwsem_pi_finish, trace_event_raw_event_msched_uclamp_restriction_result, trace_event_raw_event_rwsem_read_trylock_steal, trace_event_raw_event_locking_debug_trace, trace_event_raw_event_lock_pi_finish, trace_event_raw_event_percpu_rwsem_wait_complete, trace_event_raw_event_percpu_rwsem_up_write, trace_event_raw_event_lock_pi_start, trace_event_raw_event_percpu_rwsem_down_read_preempt, trace_event_raw_event_msched_task_get_mvp_prio, trace_event_raw_event_binder_inherit_ux_type, trace_event_raw_event_sched_wake_by_irq_kth, trace_event_raw_event_binder_nothread_be_select, trace_event_raw_event_msched_uclamp_inheritance_result, trace_event_raw_event_sched_boost_ux_kworker, trace_event_raw_event_binder_pick_best_thread, trace_event_raw_event_msched_pr_set_vma_name_bypass, trace_event_raw_event_binder_inherit_rt_prio, trace_event_raw_event_set_user_nice, trace_event_raw_event_sched_percpu_rwsem_starttime, trace_event_raw_event_sched_percpu_rwsem_hold_time, trace_event_raw_event_rwsem_pi_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 0011a0e8 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_sched_boost_ux_kworker, perf_trace_rwsem_pi_start, perf_trace_binder_inherit_rt_check, perf_trace_set_user_nice, perf_trace_msched_uclamp_restriction_result, perf_trace_sched_percpu_rwsem_hold_time, perf_trace_lock_pi_finish, perf_trace_rwsem_read_trylock_steal, perf_trace_binder_inherit_rt_prio, perf_trace_msched_pr_set_vma_name_bypass, perf_trace_locking_debug_trace, perf_trace_binder_nothread_be_select, perf_trace_rwsem_pi_finish, perf_trace_sched_percpu_rwsem_starttime, perf_trace_lock_pi_start, perf_trace_percpu_rwsem_wait_complete, perf_trace_msched_uclamp_inheritance_result, perf_trace_binder_pick_best_thread, perf_trace_percpu_rwsem_down_read_preempt, perf_trace_binder_inherit_ux_type, perf_trace_msched_task_get_mvp_prio, perf_trace_percpu_rwsem_up_write, perf_trace_sched_wake_by_irq_kth]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 0011a0f0 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_sched_boost_ux_kworker, perf_trace_rwsem_pi_start, perf_trace_binder_inherit_rt_check, perf_trace_set_user_nice, perf_trace_msched_uclamp_restriction_result, perf_trace_sched_percpu_rwsem_hold_time, perf_trace_lock_pi_finish, perf_trace_rwsem_read_trylock_steal, perf_trace_binder_inherit_rt_prio, perf_trace_msched_pr_set_vma_name_bypass, perf_trace_locking_debug_trace, perf_trace_binder_nothread_be_select, perf_trace_rwsem_pi_finish, perf_trace_sched_percpu_rwsem_starttime, perf_trace_lock_pi_start, perf_trace_percpu_rwsem_wait_complete, perf_trace_msched_uclamp_inheritance_result, perf_trace_binder_pick_best_thread, perf_trace_percpu_rwsem_down_read_preempt, perf_trace_binder_inherit_ux_type, perf_trace_msched_task_get_mvp_prio, perf_trace_percpu_rwsem_up_write, perf_trace_sched_wake_by_irq_kth]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0011a0f8 size=1
// signature: size_t strlen(char * __s)
// callers: [perf_trace_sched_boost_ux_kworker, perf_trace_lock_pi_start, perf_trace_lock_pi_finish, trace_event_raw_event_locking_debug_trace, trace_event_raw_event_lock_pi_finish, trace_event_raw_event_sched_boost_ux_kworker, trace_event_raw_event_lock_pi_start, perf_trace_locking_debug_trace]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 0011a100 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [perf_trace_sched_boost_ux_kworker, perf_trace_lock_pi_start, perf_trace_lock_pi_finish, trace_event_raw_event_locking_debug_trace, trace_event_raw_event_lock_pi_finish, trace_event_raw_event_sched_boost_ux_kworker, trace_event_raw_event_lock_pi_start, perf_trace_locking_debug_trace]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run3 @ 0011a108 size=1
// signature: undefined bpf_trace_run3(void)
// callers: [__bpf_trace_binder_inherit_ux_type, __bpf_trace_binder_nothread_be_select, __bpf_trace_percpu_rwsem_down_read_preempt, __bpf_trace_rwsem_pi_finish, __bpf_trace_rwsem_read_trylock_steal, __bpf_trace_lock_pi_start, __bpf_trace_sched_boost_ux_kworker, __bpf_trace_set_user_nice, __bpf_trace_msched_pr_set_vma_name_bypass, __bpf_trace_percpu_rwsem_wait_complete]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run1 @ 0011a110 size=1
// signature: undefined bpf_trace_run1(void)
// callers: [__bpf_trace_percpu_rwsem_up_write, __bpf_trace_sched_wake_by_irq_kth]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run7 @ 0011a118 size=1
// signature: undefined bpf_trace_run7(void)
// callers: [__bpf_trace_msched_task_get_mvp_prio]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run7(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run11 @ 0011a120 size=1
// signature: undefined bpf_trace_run11(void)
// callers: [__bpf_trace_msched_uclamp_restriction_result, __bpf_trace_msched_uclamp_inheritance_result]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run11(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run2 @ 0011a128 size=1
// signature: undefined bpf_trace_run2(void)
// callers: [__bpf_trace_binder_inherit_rt_prio, __bpf_trace_sched_percpu_rwsem_hold_time, __bpf_trace_lock_pi_finish]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run5 @ 0011a130 size=1
// signature: undefined bpf_trace_run5(void)
// callers: [__bpf_trace_binder_pick_best_thread, __bpf_trace_sched_percpu_rwsem_starttime, __bpf_trace_locking_debug_trace]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run5(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run6 @ 0011a138 size=1
// signature: undefined bpf_trace_run6(void)
// callers: [__bpf_trace_binder_inherit_rt_check]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run6(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_bprintk @ 0011a140 size=1
// signature: undefined __trace_bprintk(void)
// callers: [rwsem_list_add, mutex_list_add_ux, android_vh_mutex_wait_start_handler, uclamp_eff_value_moto, lock_clear_inherited_ux_type, task_get_mvp_prio, lock_protect_update_starttime, task_ux_type_set, task_ux_type_clear, binder_ux_type_set, queue_ux_task, msched_uclamp_binder_set_priority_hook, test_wait_timeout, msched_uclamp_binder_restore_priority_hook, android_vh_dup_task_struct_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_bprintk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncmp @ 0011a148 size=1
// signature: int strncmp(char * __s1, char * __s2, size_t __n)
// callers: [android_vh_percpu_rwsem_down_read_preempt_handler, task_get_mvp_prio]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule_notrace @ 0011a160 size=1
// signature: undefined preempt_schedule_notrace(void)
// callers: [android_vh_percpu_rwsem_down_read_preempt_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule_notrace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// task_rq_lock @ 0011a168 size=1
// signature: undefined task_rq_lock(void)
// callers: [resched_task, set_uclamp_inheritance, lock_inherit_ux_type, lock_clear_inherited_ux_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void task_rq_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// update_rq_clock @ 0011a170 size=1
// signature: undefined update_rq_clock(void)
// callers: [resched_task]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void update_rq_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// check_preempt_curr @ 0011a178 size=1
// signature: undefined check_preempt_curr(void)
// callers: [resched_task]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void check_preempt_curr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// deactivate_task @ 0011a180 size=1
// signature: undefined deactivate_task(void)
// callers: [resched_task]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void deactivate_task(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// activate_task @ 0011a188 size=1
// signature: undefined activate_task(void)
// callers: [resched_task]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void activate_task(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// resched_curr @ 0011a190 size=1
// signature: undefined resched_curr(void)
// callers: [resched_task]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void resched_curr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// raw_spin_rq_unlock @ 0011a198 size=1
// signature: undefined raw_spin_rq_unlock(void)
// callers: [resched_task, set_uclamp_inheritance, lock_inherit_ux_type, lock_clear_inherited_ux_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void raw_spin_rq_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0011a1a0 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [android_vh_rwsem_wait_finish, android_vh_rwsem_clear_rwsem_owned, resched_task, set_uclamp_inheritance, android_vh_rwsem_wake, android_vh_rwsem_record_rwsem_reader_owned, android_vh_rwsem_record_rwsem_writer_owned, reset_rwsem_owner_list, lock_inherit_ux_type, lock_clear_inherited_ux_type, android_vh_rwsem_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_setscheduler_nocheck @ 0011a1a8 size=1
// signature: undefined sched_setscheduler_nocheck(void)
// callers: [binder_inherit_rt_prio]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sched_setscheduler_nocheck(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// jiffies_to_usecs @ 0011a1b8 size=1
// signature: undefined jiffies_to_usecs(void)
// callers: [queue_ux_task, lock_inherit_ux_type, lock_clear_inherited_ux_type, lock_protect_update_starttime]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void jiffies_to_usecs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dump_stack @ 0011a1c0 size=1
// signature: undefined dump_stack(void)
// callers: [lock_protect_update_starttime]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dump_stack(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 0011a1d0 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [register_vendor_comm_hooks, msched_oemdata_init, register_mutex_vendor_hooks, register_rwsem_vendor_hooks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// android_rvh_probe_register @ 0011a1e8 size=1
// signature: undefined android_rvh_probe_register(void)
// callers: [register_vendor_comm_hooks, msched_uclamp_register_vendor_comm_hooks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void android_rvh_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rb_first @ 0011a1f8 size=1
// signature: undefined rb_first(void)
// callers: [android_vh_binder_proc_transaction_finish, proc_has_epoll_threads]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rb_first(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rb_next @ 0011a200 size=1
// signature: undefined rb_next(void)
// callers: [android_vh_binder_proc_transaction_finish, proc_has_epoll_threads]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rb_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 0011a220 size=1
// signature: undefined _find_next_bit(void)
// callers: [init_moto_struct_node_in_vendor_task_data, android_vh_percpu_rwsem_down_read_preempt_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0011a228 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [android_vh_rwsem_read_trylock_failed_handler, android_vh_percpu_rwsem_down_read_preempt_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule @ 0011a230 size=1
// signature: undefined preempt_schedule(void)
// callers: [android_vh_percpu_rwsem_down_read_preempt_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_write_trylock @ 0011a238 size=1
// signature: undefined down_write_trylock(void)
// callers: [android_rvh_pr_set_vma_name_bypass]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_write_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_write @ 0011a248 size=1
// signature: undefined up_write(void)
// callers: [android_rvh_pr_set_vma_name_bypass]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0011a250 size=1
// signature: undefined kfree(void)
// callers: [android_rvh_pr_set_vma_name_bypass]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_raw_output_prep @ 0011a260 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_percpu_rwsem_wait_complete, trace_raw_output_sched_boost_ux_kworker, trace_raw_output_binder_inherit_rt_check, trace_raw_output_percpu_rwsem_down_read_preempt, trace_raw_output_binder_inherit_rt_prio, trace_raw_output_lock_pi_start, trace_raw_output_msched_pr_set_vma_name_bypass, trace_raw_output_rwsem_pi_start, trace_raw_output_locking_debug_trace, trace_raw_output_binder_nothread_be_select, trace_raw_output_msched_uclamp_restriction_result, trace_raw_output_sched_percpu_rwsem_hold_time, trace_raw_output_lock_pi_finish, trace_raw_output_percpu_rwsem_up_write, trace_raw_output_msched_task_get_mvp_prio, trace_raw_output_binder_inherit_ux_type, trace_raw_output_binder_pick_best_thread, trace_raw_output_msched_uclamp_inheritance_result, trace_raw_output_rwsem_pi_finish, trace_raw_output_sched_percpu_rwsem_starttime, trace_raw_output_set_user_nice, trace_raw_output_rwsem_read_trylock_steal, trace_raw_output_sched_wake_by_irq_kth]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 0011a268 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_percpu_rwsem_wait_complete, trace_raw_output_sched_boost_ux_kworker, trace_raw_output_binder_inherit_rt_check, trace_raw_output_percpu_rwsem_down_read_preempt, trace_raw_output_binder_inherit_rt_prio, trace_raw_output_lock_pi_start, trace_raw_output_msched_pr_set_vma_name_bypass, trace_raw_output_rwsem_pi_start, trace_raw_output_locking_debug_trace, trace_raw_output_binder_nothread_be_select, trace_raw_output_msched_uclamp_restriction_result, trace_raw_output_sched_percpu_rwsem_hold_time, trace_raw_output_lock_pi_finish, trace_raw_output_percpu_rwsem_up_write, trace_raw_output_msched_task_get_mvp_prio, trace_raw_output_binder_inherit_ux_type, trace_raw_output_binder_pick_best_thread, trace_raw_output_msched_uclamp_inheritance_result, trace_raw_output_rwsem_pi_finish, trace_raw_output_sched_percpu_rwsem_starttime, trace_raw_output_set_user_nice, trace_raw_output_rwsem_read_trylock_steal, trace_raw_output_sched_wake_by_irq_kth]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 0011a270 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_percpu_rwsem_wait_complete, trace_raw_output_sched_boost_ux_kworker, trace_raw_output_binder_inherit_rt_check, trace_raw_output_percpu_rwsem_down_read_preempt, trace_raw_output_binder_inherit_rt_prio, trace_raw_output_lock_pi_start, trace_raw_output_msched_pr_set_vma_name_bypass, trace_raw_output_rwsem_pi_start, trace_raw_output_locking_debug_trace, trace_raw_output_binder_nothread_be_select, trace_raw_output_msched_uclamp_restriction_result, trace_raw_output_sched_percpu_rwsem_hold_time, trace_raw_output_lock_pi_finish, trace_raw_output_percpu_rwsem_up_write, trace_raw_output_msched_task_get_mvp_prio, trace_raw_output_binder_inherit_ux_type, trace_raw_output_binder_pick_best_thread, trace_raw_output_msched_uclamp_inheritance_result, trace_raw_output_rwsem_pi_finish, trace_raw_output_sched_percpu_rwsem_starttime, trace_raw_output_set_user_nice, trace_raw_output_rwsem_read_trylock_steal, trace_raw_output_sched_wake_by_irq_kth]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmem_cache_alloc @ 0011a288 size=1
// signature: undefined kmem_cache_alloc(void)
// callers: [init_moto_struct_node_in_vendor_task_data, android_vh_dup_task_struct_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmem_cache_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmem_cache_free @ 0011a290 size=1
// signature: undefined kmem_cache_free(void)
// callers: [android_vh_free_task_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmem_cache_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmem_cache_create @ 0011a298 size=1
// signature: undefined kmem_cache_create(void)
// callers: [msched_oemdata_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmem_cache_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// stop_machine @ 0011a2b8 size=1
// signature: undefined stop_machine(void)
// callers: [msched_oemdata_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void stop_machine(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_lock @ 0011a2c8 size=1
// signature: undefined _raw_read_lock(void)
// callers: [init_moto_struct_node_in_vendor_task_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_unlock @ 0011a2d8 size=1
// signature: undefined _raw_read_unlock(void)
// callers: [init_moto_struct_node_in_vendor_task_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_unregister @ 0011a2e0 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [unregister_mutex_vendor_hooks, unregister_rwsem_vendor_hooks, msched_oemdata_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmem_cache_destroy @ 0011a2e8 size=1
// signature: undefined kmem_cache_destroy(void)
// callers: [msched_oemdata_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmem_cache_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run4 @ 0011a2f0 size=1
// signature: undefined bpf_trace_run4(void)
// callers: [__bpf_trace_rwsem_pi_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0011a310 size=1
// signature: undefined __list_add_valid(void)
// callers: [rwsem_list_add, android_vh_rwsem_record_rwsem_reader_owned, android_vh_rwsem_record_rwsem_writer_owned, mutex_list_add_ux]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0011a318 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [android_vh_rwsem_wait_finish, android_vh_rwsem_clear_rwsem_owned, android_vh_rwsem_wake, android_vh_rwsem_record_rwsem_reader_owned, android_vh_rwsem_record_rwsem_writer_owned, reset_rwsem_owner_list, android_vh_rwsem_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0011a320 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [android_vh_rwsem_clear_rwsem_owned, reset_rwsem_owner_list]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __task_rq_lock @ 0011a398 size=1
// signature: undefined __task_rq_lock(void)
// callers: [set_uclamp_inheritance]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __task_rq_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



