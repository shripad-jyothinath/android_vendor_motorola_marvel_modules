// Decompiled by Ghidra 12.2
// Program: pm8941-pwrkey.ko
// Image base: 00100000

//------------------------------------------------------------
// pm8941_pwrkey_probe @ 00100264 size=1148
// signature: undefined pm8941_pwrkey_probe(void)
// callers: []
//------------------------------------------------------------

int pm8941_pwrkey_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  long lVar7;
  uint *puVar8;
  char *pcVar9;
  uint uVar10;
  undefined8 uVar11;
  long lVar12;
  uint local_64;
  int local_60;
  uint local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  lVar1 = param_1 + 0x10;
  local_64 = 0;
  local_60 = 0;
  iVar3 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),"debounce",&local_60,1,0);
  if (iVar3 < 0) {
    local_60 = 0x3d09;
  }
  else if (local_60 - 0x1e8481U < 0xffe17b80) {
    _dev_err(lVar1,"invalid debounce time: %u\n");
    iVar3 = -0x16;
    goto LAB_001004e8;
  }
  lVar4 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"bias-pull-up",0);
  plVar5 = (long *)devm_kmalloc(lVar1,0x68,0xdc0);
  if (plVar5 == (long *)0x0) {
LAB_001004c0:
    iVar3 = -0xc;
    goto LAB_001004e8;
  }
  *plVar5 = lVar1;
  lVar6 = of_device_get_match_data(lVar1);
  plVar5[0xc] = lVar6;
  if (lVar6 == 0) {
    pcVar9 = "match data not found\n";
LAB_00100638:
    _dev_err(lVar1,pcVar9);
    iVar3 = -0x13;
    goto LAB_001004e8;
  }
  lVar12 = *(long *)(param_1 + 0x70);
  uVar11 = *(undefined8 *)(param_1 + 0x2f8);
  lVar7 = dev_get_regmap(lVar12,0);
  plVar5[3] = lVar7;
  if (lVar7 == 0) {
    uVar11 = *(undefined8 *)(lVar12 + 0x2e8);
    lVar7 = dev_get_regmap(*(undefined8 *)(lVar12 + 0x60),0);
    plVar5[3] = lVar7;
    if (lVar7 == 0) {
      pcVar9 = "failed to locate regmap\n";
      goto LAB_00100638;
    }
  }
  *(int *)(plVar5 + 0xb) = local_60;
  *(bool *)((long)plVar5 + 0x5d) = lVar4 != 0;
  puVar8 = (uint *)__of_get_address(uVar11,0,0xffffffff,0,0);
  if (puVar8 == (uint *)0x0) {
    _dev_err(lVar1,"reg property missing\n");
    iVar3 = -0x16;
    goto LAB_001004e8;
  }
  uVar10 = (*puVar8 & 0xff00ff00) >> 8 | (*puVar8 & 0xff00ff) << 8;
  uVar10 = uVar10 >> 0x10 | uVar10 << 0x10;
  *(uint *)((long)plVar5 + 0xc) = uVar10;
  if ((*(char *)(lVar6 + 10) != '\0') &&
     (puVar8 = (uint *)__of_get_address(uVar11,1,0xffffffff,0,0), puVar8 != (uint *)0x0)) {
    uVar2 = (*puVar8 & 0xff00ff00) >> 8 | (*puVar8 & 0xff00ff) << 8;
    *(uint *)(plVar5 + 2) = uVar2 >> 0x10 | uVar2 << 0x10;
  }
  iVar3 = platform_get_irq(param_1,0);
  *(int *)(plVar5 + 1) = iVar3;
  if (iVar3 < 0) goto LAB_001004e8;
  iVar3 = regmap_read(lVar7,uVar10 + 1,plVar5 + 5);
  if (iVar3 == 0) {
    iVar3 = regmap_read(plVar5[3],*(int *)((long)plVar5 + 0xc) + 5,(long)plVar5 + 0x2c);
    if (iVar3 == 0) {
      iVar3 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"linux,code",plVar5 + 9,1,0);
      if (iVar3 < 0) {
        *(undefined4 *)(plVar5 + 9) = 0x74;
      }
      lVar4 = devm_input_allocate_device(lVar1);
      plVar5[4] = lVar4;
      if (lVar4 == 0) goto LAB_001004c0;
      input_set_capability(lVar4,1,(int)plVar5[9]);
      *(undefined8 *)plVar5[4] = *(undefined8 *)(plVar5[0xc] + 0x10);
      *(undefined8 *)(plVar5[4] + 8) = *(undefined8 *)(plVar5[0xc] + 0x18);
      iVar3 = pm8941_pwrkey_hw_init(plVar5);
      if (iVar3 != 0) {
        pcVar9 = "Failed to initialize H/W : %d\n";
        goto LAB_001006b4;
      }
      local_5c = 0;
      iVar3 = (int)plVar5[2];
      if (*(char *)(plVar5[0xc] + 10) == '\0') {
        if (iVar3 == 0) {
          iVar3 = *(int *)((long)plVar5 + 0xc);
        }
LAB_001004d0:
        iVar3 = regmap_read(plVar5[3],iVar3 + 0x71,&local_5c);
        if (iVar3 != 0) goto LAB_001004e8;
        uVar10 = 0xf;
        if (*(uint *)((long)plVar5 + 0x2c) < 4) {
          uVar10 = 7;
        }
        *(uint *)((long)plVar5 + 0x4c) = 2000000 >> (ulong)(uVar10 & (local_5c ^ 0xffffffff));
      }
      else {
        if (iVar3 != 0) goto LAB_001004d0;
        _dev_err(*plVar5,"PON_PBS address missing, can\'t read HW debounce time\n");
      }
      lVar4 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,log-kpd-event",0);
      *(bool *)((long)plVar5 + 0x5e) = lVar4 != 0;
      if (lVar4 != 0) {
        iVar3 = regmap_read(plVar5[3],*(int *)((long)plVar5 + 0xc) + 0x10,&local_64);
        if (iVar3 == 0) {
          _printk(&DAT_001015e9,local_64,local_64 & 1);
        }
        else {
          _dev_err(lVar1,"failed to read PON_RT_STS rc=%d\n",iVar3);
        }
      }
      iVar3 = devm_request_threaded_irq
                        (lVar1,(int)plVar5[1],0,pm8941_pwrkey_irq,0x2000,
                         *(undefined8 *)(plVar5[0xc] + 0x10),plVar5);
      if (iVar3 == 0) {
        iVar3 = input_register_device(plVar5[4]);
        if (iVar3 == 0) {
          if (*(char *)(plVar5[0xc] + 8) != '\0') {
            plVar5[6] = (long)pm8941_reboot_notify;
            iVar3 = register_reboot_notifier();
            if (iVar3 != 0) {
              pcVar9 = "failed to register reboot notifier: %d\n";
              goto LAB_001006b4;
            }
          }
          *(long **)(param_1 + 0xa8) = plVar5;
          device_set_wakeup_capable(lVar1,1);
          device_wakeup_enable(lVar1);
          iVar3 = 0;
          goto LAB_001004e8;
        }
        pcVar9 = "failed to register input device: %d\n";
      }
      else {
        pcVar9 = "failed requesting IRQ: %d\n";
      }
    }
    else {
      pcVar9 = "failed to read subtype: %d\n";
    }
  }
  else {
    pcVar9 = "failed to read revision: %d\n";
  }
LAB_001006b4:
  _dev_err(lVar1,pcVar9,iVar3);
LAB_001004e8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// pm8941_pwrkey_remove @ 001006e4 size=52
// signature: undefined pm8941_pwrkey_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 pm8941_pwrkey_remove(long param_1)

{
  if (*(char *)(*(long *)(*(long *)(param_1 + 0xa8) + 0x60) + 8) != '\0') {
    unregister_reboot_notifier(*(long *)(param_1 + 0xa8) + 0x30);
  }
  return 0;
}



//------------------------------------------------------------
// pm8941_pwrkey_hw_init @ 00100718 size=300
// signature: undefined pm8941_pwrkey_hw_init(void)
// callers: [pm8941_pwrkey_resume, pm8941_pwrkey_restore, pm8941_pwrkey_probe]
//------------------------------------------------------------

int pm8941_pwrkey_hw_init(undefined8 *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  
  piVar3 = (int *)param_1[0xc];
  if (*(char *)((long)piVar3 + 9) != '\0') {
    uVar4 = 0xe;
    if (*(uint *)((long)param_1 + 0x2c) < 4) {
      uVar4 = 6;
    }
    uVar5 = 0xf;
    if (*(uint *)((long)param_1 + 0x2c) < 4) {
      uVar5 = 7;
    }
    iVar1 = 0x1f - (int)LZCOUNT((uint)(*(int *)(param_1 + 0xb) << (ulong)uVar4) / 1000000);
    if ((uint)(*(int *)(param_1 + 0xb) << (ulong)uVar4) < 1000000) {
      iVar1 = -1;
    }
    iVar1 = regmap_update_bits_base
                      (param_1[3],*(int *)((long)param_1 + 0xc) + 0x71,uVar5,iVar1,0,0,0);
    if (iVar1 != 0) {
      _dev_err(*param_1,"failed to set debounce config: %d\n",iVar1);
      return iVar1;
    }
    piVar3 = (int *)param_1[0xc];
  }
  iVar1 = *piVar3;
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar2 = 0;
    if (*(char *)((long)param_1 + 0x5d) != '\0') {
      iVar2 = iVar1;
    }
    iVar2 = regmap_update_bits_base
                      (param_1[3],*(int *)((long)param_1 + 0xc) + 0x70,iVar1,iVar2,0,0,0);
    iVar1 = 0;
    if (iVar2 != 0) {
      _dev_err(*param_1,"failed to set pull-up config: %d\n",iVar2);
      iVar1 = iVar2;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// pm8941_pwrkey_irq @ 00100848 size=580
// signature: undefined pm8941_pwrkey_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 pm8941_pwrkey_irq(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  long local_138;
  uint local_12c;
  char local_128 [256];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_12c = 0;
  local_140 = 0;
  local_138 = 0;
  local_150 = 0;
  uStack_148 = 0;
  local_160 = 0;
  uStack_158 = 0;
  local_168 = 0;
  local_128[0xf8] = '\0';
  local_128[0xf9] = '\0';
  local_128[0xfa] = '\0';
  local_128[0xfb] = '\0';
  local_128[0xfc] = '\0';
  local_128[0xfd] = '\0';
  local_128[0xfe] = '\0';
  local_128[0xe8] = '\0';
  local_128[0xe9] = '\0';
  local_128[0xea] = '\0';
  local_128[0xeb] = '\0';
  local_128[0xec] = '\0';
  local_128[0xed] = '\0';
  local_128[0xee] = '\0';
  local_128[0xef] = '\0';
  local_128[0xf0] = '\0';
  local_128[0xf1] = '\0';
  local_128[0xf2] = '\0';
  local_128[0xf3] = '\0';
  local_128[0xf4] = '\0';
  local_128[0xf5] = '\0';
  local_128[0xf6] = '\0';
  local_128[0xf7] = 0;
  local_128[0xd8] = '\0';
  local_128[0xd9] = '\0';
  local_128[0xda] = '\0';
  local_128[0xdb] = '\0';
  local_128[0xdc] = '\0';
  local_128[0xdd] = '\0';
  local_128[0xde] = '\0';
  local_128[0xdf] = '\0';
  local_128[0xe0] = '\0';
  local_128[0xe1] = '\0';
  local_128[0xe2] = '\0';
  local_128[0xe3] = '\0';
  local_128[0xe4] = '\0';
  local_128[0xe5] = '\0';
  local_128[0xe6] = '\0';
  local_128[0xe7] = '\0';
  local_128[200] = '\0';
  local_128[0xc9] = '\0';
  local_128[0xca] = '\0';
  local_128[0xcb] = '\0';
  local_128[0xcc] = '\0';
  local_128[0xcd] = '\0';
  local_128[0xce] = '\0';
  local_128[0xcf] = '\0';
  local_128[0xd0] = '\0';
  local_128[0xd1] = '\0';
  local_128[0xd2] = '\0';
  local_128[0xd3] = '\0';
  local_128[0xd4] = '\0';
  local_128[0xd5] = '\0';
  local_128[0xd6] = '\0';
  local_128[0xd7] = '\0';
  local_128[0xb8] = '\0';
  local_128[0xb9] = '\0';
  local_128[0xba] = '\0';
  local_128[0xbb] = '\0';
  local_128[0xbc] = '\0';
  local_128[0xbd] = '\0';
  local_128[0xbe] = '\0';
  local_128[0xbf] = '\0';
  local_128[0xc0] = '\0';
  local_128[0xc1] = '\0';
  local_128[0xc2] = '\0';
  local_128[0xc3] = '\0';
  local_128[0xc4] = '\0';
  local_128[0xc5] = '\0';
  local_128[0xc6] = '\0';
  local_128[199] = '\0';
  local_128[0xa8] = '\0';
  local_128[0xa9] = '\0';
  local_128[0xaa] = '\0';
  local_128[0xab] = '\0';
  local_128[0xac] = '\0';
  local_128[0xad] = '\0';
  local_128[0xae] = '\0';
  local_128[0xaf] = '\0';
  local_128[0xb0] = '\0';
  local_128[0xb1] = '\0';
  local_128[0xb2] = '\0';
  local_128[0xb3] = '\0';
  local_128[0xb4] = '\0';
  local_128[0xb5] = '\0';
  local_128[0xb6] = '\0';
  local_128[0xb7] = '\0';
  local_128[0x98] = '\0';
  local_128[0x99] = '\0';
  local_128[0x9a] = '\0';
  local_128[0x9b] = '\0';
  local_128[0x9c] = '\0';
  local_128[0x9d] = '\0';
  local_128[0x9e] = '\0';
  local_128[0x9f] = '\0';
  local_128[0xa0] = '\0';
  local_128[0xa1] = '\0';
  local_128[0xa2] = '\0';
  local_128[0xa3] = '\0';
  local_128[0xa4] = '\0';
  local_128[0xa5] = '\0';
  local_128[0xa6] = '\0';
  local_128[0xa7] = '\0';
  local_128[0x88] = '\0';
  local_128[0x89] = '\0';
  local_128[0x8a] = '\0';
  local_128[0x8b] = '\0';
  local_128[0x8c] = '\0';
  local_128[0x8d] = '\0';
  local_128[0x8e] = '\0';
  local_128[0x8f] = '\0';
  local_128[0x90] = '\0';
  local_128[0x91] = '\0';
  local_128[0x92] = '\0';
  local_128[0x93] = '\0';
  local_128[0x94] = '\0';
  local_128[0x95] = '\0';
  local_128[0x96] = '\0';
  local_128[0x97] = '\0';
  local_128[0x78] = '\0';
  local_128[0x79] = '\0';
  local_128[0x7a] = '\0';
  local_128[0x7b] = '\0';
  local_128[0x7c] = '\0';
  local_128[0x7d] = '\0';
  local_128[0x7e] = '\0';
  local_128[0x7f] = '\0';
  local_128[0x80] = '\0';
  local_128[0x81] = '\0';
  local_128[0x82] = '\0';
  local_128[0x83] = '\0';
  local_128[0x84] = '\0';
  local_128[0x85] = '\0';
  local_128[0x86] = '\0';
  local_128[0x87] = '\0';
  local_128[0x68] = '\0';
  local_128[0x69] = '\0';
  local_128[0x6a] = '\0';
  local_128[0x6b] = '\0';
  local_128[0x6c] = '\0';
  local_128[0x6d] = '\0';
  local_128[0x6e] = '\0';
  local_128[0x6f] = '\0';
  local_128[0x70] = '\0';
  local_128[0x71] = '\0';
  local_128[0x72] = '\0';
  local_128[0x73] = '\0';
  local_128[0x74] = '\0';
  local_128[0x75] = '\0';
  local_128[0x76] = '\0';
  local_128[0x77] = '\0';
  local_128[0x58] = '\0';
  local_128[0x59] = '\0';
  local_128[0x5a] = '\0';
  local_128[0x5b] = '\0';
  local_128[0x5c] = '\0';
  local_128[0x5d] = '\0';
  local_128[0x5e] = '\0';
  local_128[0x5f] = '\0';
  local_128[0x60] = '\0';
  local_128[0x61] = '\0';
  local_128[0x62] = '\0';
  local_128[99] = '\0';
  local_128[100] = '\0';
  local_128[0x65] = '\0';
  local_128[0x66] = '\0';
  local_128[0x67] = '\0';
  local_128[0x48] = '\0';
  local_128[0x49] = '\0';
  local_128[0x4a] = '\0';
  local_128[0x4b] = '\0';
  local_128[0x4c] = '\0';
  local_128[0x4d] = '\0';
  local_128[0x4e] = '\0';
  local_128[0x4f] = '\0';
  local_128[0x50] = '\0';
  local_128[0x51] = '\0';
  local_128[0x52] = '\0';
  local_128[0x53] = '\0';
  local_128[0x54] = '\0';
  local_128[0x55] = '\0';
  local_128[0x56] = '\0';
  local_128[0x57] = '\0';
  local_128[0x38] = '\0';
  local_128[0x39] = '\0';
  local_128[0x3a] = '\0';
  local_128[0x3b] = '\0';
  local_128[0x3c] = '\0';
  local_128[0x3d] = '\0';
  local_128[0x3e] = '\0';
  local_128[0x3f] = '\0';
  local_128[0x40] = '\0';
  local_128[0x41] = '\0';
  local_128[0x42] = '\0';
  local_128[0x43] = '\0';
  local_128[0x44] = '\0';
  local_128[0x45] = '\0';
  local_128[0x46] = '\0';
  local_128[0x47] = '\0';
  local_128[0x28] = '\0';
  local_128[0x29] = '\0';
  local_128[0x2a] = '\0';
  local_128[0x2b] = '\0';
  local_128[0x2c] = '\0';
  local_128[0x2d] = '\0';
  local_128[0x2e] = '\0';
  local_128[0x2f] = '\0';
  local_128[0x30] = '\0';
  local_128[0x31] = '\0';
  local_128[0x32] = '\0';
  local_128[0x33] = '\0';
  local_128[0x34] = '\0';
  local_128[0x35] = '\0';
  local_128[0x36] = '\0';
  local_128[0x37] = '\0';
  local_128[0x18] = '\0';
  local_128[0x19] = '\0';
  local_128[0x1a] = '\0';
  local_128[0x1b] = '\0';
  local_128[0x1c] = '\0';
  local_128[0x1d] = '\0';
  local_128[0x1e] = '\0';
  local_128[0x1f] = '\0';
  local_128[0x20] = '\0';
  local_128[0x21] = '\0';
  local_128[0x22] = '\0';
  local_128[0x23] = '\0';
  local_128[0x24] = '\0';
  local_128[0x25] = '\0';
  local_128[0x26] = '\0';
  local_128[0x27] = '\0';
  local_128[8] = '\0';
  local_128[9] = '\0';
  local_128[10] = '\0';
  local_128[0xb] = '\0';
  local_128[0xc] = '\0';
  local_128[0xd] = '\0';
  local_128[0xe] = '\0';
  local_128[0xf] = '\0';
  local_128[0x10] = '\0';
  local_128[0x11] = '\0';
  local_128[0x12] = '\0';
  local_128[0x13] = '\0';
  local_128[0x14] = '\0';
  local_128[0x15] = '\0';
  local_128[0x16] = '\0';
  local_128[0x17] = '\0';
  local_128[0] = '\0';
  local_128[1] = '\0';
  local_128[2] = '\0';
  local_128[3] = '\0';
  local_128[4] = '\0';
  local_128[5] = '\0';
  local_128[6] = '\0';
  local_128[7] = '\0';
  ktime_get_real_ts64(&local_140);
  time64_to_tm(local_140,0,&local_168);
  snprintf(local_128,0xff,"%u-%02d-%02d %02d:%02d:%02d.%06ld UTC",(int)local_150 + 0x76c,
           (int)uStack_158 + 1,local_160._4_4_,(int)local_160,local_168._4_4_,(int)local_168,
           local_138);
  _printk(&DAT_001018a9,"pm8941_pwrkey_irq",local_128);
  if (((*(int *)(param_2 + 0x4c) == 0) || (lVar2 = ktime_get(), *(long *)(param_2 + 0x50) <= lVar2))
     && (iVar1 = regmap_read(*(undefined8 *)(param_2 + 0x18),*(int *)(param_2 + 0xc) + 0x10,
                             &local_12c), iVar1 == 0)) {
    if ((*(char *)(param_2 + 0x5e) != '\0') &&
       (iVar1 = ___ratelimit(pm8941_pwrkey_irq__rs,"pm8941_pwrkey_irq"), iVar1 != 0)) {
      _printk(&DAT_001017c5,local_12c,(*(uint *)(*(long *)(param_2 + 0x60) + 4) & local_12c) != 0);
    }
    local_12c = local_12c & *(uint *)(*(long *)(param_2 + 0x60) + 4);
    _printk(&DAT_00101569,*(undefined4 *)(param_2 + 0x48),*(undefined1 *)(param_2 + 0x5c));
    if ((*(int *)(param_2 + 0x4c) != 0) && (local_12c == 0)) {
      lVar2 = ktime_get();
      *(ulong *)(param_2 + 0x50) = lVar2 + (ulong)*(uint *)(param_2 + 0x4c) * 1000;
    }
    if ((*(char *)(param_2 + 0x5c) == '\0') && (local_12c == 0)) {
      input_event(*(undefined8 *)(param_2 + 0x20),1,*(undefined4 *)(param_2 + 0x48),1);
      input_event(*(undefined8 *)(param_2 + 0x20),0,0,0);
    }
    *(bool *)(param_2 + 0x5c) = local_12c != 0;
    input_event(*(undefined8 *)(param_2 + 0x20),1,*(undefined4 *)(param_2 + 0x48));
    input_event(*(undefined8 *)(param_2 + 0x20),0,0,0);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// pm8941_reboot_notify @ 00100a90 size=308
// signature: undefined pm8941_reboot_notify(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 pm8941_reboot_notify(long param_1,ulong param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 0x5a;
  if (*(int *)(param_1 + -8) != 0) {
    iVar3 = 0x5b;
  }
  iVar2 = regmap_update_bits_base
                    (*(undefined8 *)(param_1 + -0x18),*(int *)(param_1 + -0x24) + iVar3,0x80,0,0,0,0
                    );
  if (iVar2 != 0) {
    _dev_err(*(undefined8 *)(param_1 + -0x30),"unable to clear ps hold reset enable: %d\n",iVar2);
  }
  usleep_range_state(100,1000,2);
  uVar4 = 7;
  if (_reboot_mode == 1) {
    uVar4 = 1;
  }
  uVar1 = 4;
  if ((param_2 & 0xfffffffffffffffe) != 2) {
    uVar1 = uVar4;
  }
  iVar2 = regmap_update_bits_base
                    (*(undefined8 *)(param_1 + -0x18),*(int *)(param_1 + -0x24) + 0x5a,0xf,uVar1,0,0
                     ,0);
  if (iVar2 != 0) {
    _dev_err(*(undefined8 *)(param_1 + -0x30),"unable to set ps hold reset type: %d\n",iVar2);
  }
  iVar3 = regmap_update_bits_base
                    (*(undefined8 *)(param_1 + -0x18),*(int *)(param_1 + -0x24) + iVar3,0x80,0x80,0,
                     0,0);
  if (iVar3 != 0) {
    _dev_err(*(undefined8 *)(param_1 + -0x30),"unable to re-set enable: %d\n",iVar3);
  }
  return 0;
}



//------------------------------------------------------------
// pm8941_pwrkey_suspend @ 00100bc8 size=124
// signature: undefined pm8941_pwrkey_suspend(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 pm8941_pwrkey_suspend(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  if (_pm_suspend_target_state == 3) {
    if (0 < *(int *)(lVar1 + 8)) {
      disable_irq();
      devm_free_irq(param_1,*(undefined4 *)(lVar1 + 8),lVar1);
    }
  }
  else if (((*(ushort *)(param_1 + 0x10c) & 1) != 0) && (*(long *)(param_1 + 0x148) != 0)) {
    irq_set_irq_wake(*(undefined4 *)(lVar1 + 8),1);
  }
  return 0;
}



//------------------------------------------------------------
// pm8941_pwrkey_resume @ 00100c48 size=200
// signature: undefined pm8941_pwrkey_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int pm8941_pwrkey_resume(long param_1)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  if (_pm_suspend_target_state == 3) {
    iVar1 = pm8941_pwrkey_hw_init(lVar3);
    if (iVar1 == 0) {
      iVar1 = devm_request_threaded_irq
                        (param_1,*(undefined4 *)(lVar3 + 8),0,pm8941_pwrkey_irq,0x2000,
                         *(undefined8 *)(*(long *)(lVar3 + 0x60) + 0x10),lVar3);
      if (iVar1 == 0) {
        return 0;
      }
      pcVar2 = "failed requesting IRQ: %d\n";
    }
    else {
      pcVar2 = "Failed to initialize H/W error :%d\n";
    }
    _dev_err(param_1,pcVar2,iVar1);
  }
  else {
    if (((*(ushort *)(param_1 + 0x10c) & 1) != 0) && (*(long *)(param_1 + 0x148) != 0)) {
      irq_set_irq_wake(*(undefined4 *)(lVar3 + 8),0);
    }
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// pm8941_pwrkey_freeze @ 00100d14 size=76
// signature: undefined pm8941_pwrkey_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 pm8941_pwrkey_freeze(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  if (0 < *(int *)(lVar1 + 8)) {
    disable_irq();
    devm_free_irq(param_1,*(undefined4 *)(lVar1 + 8),lVar1);
  }
  return 0;
}



//------------------------------------------------------------
// pm8941_pwrkey_restore @ 00100d64 size=152
// signature: undefined pm8941_pwrkey_restore(void)
// callers: []
//------------------------------------------------------------

int pm8941_pwrkey_restore(long param_1)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  iVar1 = pm8941_pwrkey_hw_init(lVar3);
  if (iVar1 == 0) {
    iVar1 = devm_request_threaded_irq
                      (param_1,*(undefined4 *)(lVar3 + 8),0,pm8941_pwrkey_irq,0x2000,
                       *(undefined8 *)(*(long *)(lVar3 + 0x60) + 0x10),lVar3);
    if (iVar1 == 0) {
      return 0;
    }
    pcVar2 = "failed requesting IRQ: %d\n";
  }
  else {
    pcVar2 = "Failed to initialize H/W error :%d\n";
  }
  _dev_err(param_1,pcVar2,iVar1);
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 00100e00 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&pm8941_pwrkey_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100e30 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&pm8941_pwrkey_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00103000 size=1
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
// platform_driver_unregister @ 00103008 size=1
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
// of_property_read_variable_u32_array @ 00103010 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [pm8941_pwrkey_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103018 size=1
// signature: undefined _dev_err(void)
// callers: [pm8941_reboot_notify, pm8941_pwrkey_resume, pm8941_pwrkey_restore, pm8941_pwrkey_probe, pm8941_pwrkey_hw_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00103020 size=1
// signature: undefined of_find_property(void)
// callers: [pm8941_pwrkey_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103028 size=1
// signature: undefined devm_kmalloc(void)
// callers: [pm8941_pwrkey_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 00103030 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [pm8941_pwrkey_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00103038 size=1
// signature: undefined dev_get_regmap(void)
// callers: [pm8941_pwrkey_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_get_address @ 00103040 size=1
// signature: undefined __of_get_address(void)
// callers: [pm8941_pwrkey_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_get_address(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 00103048 size=1
// signature: undefined platform_get_irq(void)
// callers: [pm8941_pwrkey_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00103050 size=1
// signature: undefined regmap_read(void)
// callers: [pm8941_pwrkey_probe, pm8941_pwrkey_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_input_allocate_device @ 00103058 size=1
// signature: undefined devm_input_allocate_device(void)
// callers: [pm8941_pwrkey_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_input_allocate_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_set_capability @ 00103060 size=1
// signature: undefined input_set_capability(void)
// callers: [pm8941_pwrkey_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_set_capability(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00103068 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [pm8941_pwrkey_resume, pm8941_pwrkey_restore, pm8941_pwrkey_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_register_device @ 00103070 size=1
// signature: undefined input_register_device(void)
// callers: [pm8941_pwrkey_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_register_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_reboot_notifier @ 00103078 size=1
// signature: undefined register_reboot_notifier(void)
// callers: [pm8941_pwrkey_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_reboot_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_set_wakeup_capable @ 00103080 size=1
// signature: undefined device_set_wakeup_capable(void)
// callers: [pm8941_pwrkey_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_enable @ 00103088 size=1
// signature: undefined device_wakeup_enable(void)
// callers: [pm8941_pwrkey_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103090 size=1
// signature: undefined _printk(void)
// callers: [pm8941_pwrkey_probe, pm8941_pwrkey_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103098 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [pm8941_pwrkey_probe, pm8941_pwrkey_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_reboot_notifier @ 001030a0 size=1
// signature: undefined unregister_reboot_notifier(void)
// callers: [pm8941_pwrkey_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_reboot_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 001030a8 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [pm8941_reboot_notify, pm8941_pwrkey_hw_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_real_ts64 @ 001030b0 size=1
// signature: undefined ktime_get_real_ts64(void)
// callers: [pm8941_pwrkey_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_real_ts64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// time64_to_tm @ 001030b8 size=1
// signature: undefined time64_to_tm(void)
// callers: [pm8941_pwrkey_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void time64_to_tm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 001030c0 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [pm8941_pwrkey_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 001030c8 size=1
// signature: undefined ktime_get(void)
// callers: [pm8941_pwrkey_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 001030d0 size=1
// signature: undefined ___ratelimit(void)
// callers: [pm8941_pwrkey_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_event @ 001030d8 size=1
// signature: undefined input_event(void)
// callers: [pm8941_pwrkey_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 001030e0 size=1
// signature: undefined usleep_range_state(void)
// callers: [pm8941_reboot_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 001030f8 size=1
// signature: undefined disable_irq(void)
// callers: [pm8941_pwrkey_freeze, pm8941_pwrkey_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_free_irq @ 00103100 size=1
// signature: undefined devm_free_irq(void)
// callers: [pm8941_pwrkey_freeze, pm8941_pwrkey_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 00103108 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [pm8941_pwrkey_resume, pm8941_pwrkey_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



