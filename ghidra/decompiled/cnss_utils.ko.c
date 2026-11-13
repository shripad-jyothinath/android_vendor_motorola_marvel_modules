// Decompiled by Ghidra 12.2
// Program: cnss_utils.ko
// Image base: 00100000

//------------------------------------------------------------
// cnss_utils_set_wlan_unsafe_channel @ 001004d4 size=156
// signature: undefined cnss_utils_set_wlan_unsafe_channel(void)
// callers: []
//------------------------------------------------------------

undefined8 cnss_utils_set_wlan_unsafe_channel(undefined8 param_1,void *param_2,ushort param_3)

{
  ushort *puVar1;
  ushort *puVar2;
  undefined8 uVar3;
  
  puVar2 = cnss_utils_priv;
  if (cnss_utils_priv == (ushort *)0x0) {
    uVar3 = 0xffffffea;
  }
  else {
    puVar1 = cnss_utils_priv + 0xa8;
    mutex_lock(puVar1);
    uVar3 = 0xffffffea;
    if ((param_2 != (void *)0x0) && (param_3 < 0x9e)) {
      *puVar2 = param_3;
      if (param_3 != 0) {
        memcpy(puVar2 + 1,param_2,(ulong)param_3 << 1);
      }
      uVar3 = 0;
    }
    mutex_unlock(puVar1);
  }
  return uVar3;
}



//------------------------------------------------------------
// cnss_utils_get_wlan_unsafe_channel @ 00100574 size=168
// signature: undefined cnss_utils_get_wlan_unsafe_channel(void)
// callers: []
//------------------------------------------------------------

undefined8
cnss_utils_get_wlan_unsafe_channel(undefined8 param_1,void *param_2,ushort *param_3,ushort param_4)

{
  ushort *puVar1;
  ushort *puVar2;
  undefined8 uVar3;
  
  puVar2 = cnss_utils_priv;
  if (cnss_utils_priv == (ushort *)0x0) {
    uVar3 = 0xffffffea;
  }
  else {
    puVar1 = cnss_utils_priv + 0xa8;
    mutex_lock(puVar1);
    uVar3 = 0xffffffea;
    if ((param_2 != (void *)0x0) && (param_3 != (ushort *)0x0)) {
      if ((ulong)param_4 < (ulong)*puVar2 * 2) {
        uVar3 = 0xfffffff4;
      }
      else {
        *param_3 = *puVar2;
        memcpy(param_2,puVar2 + 1,(ulong)*puVar2 << 1);
        uVar3 = 0;
      }
    }
    mutex_unlock(puVar1);
  }
  return uVar3;
}



//------------------------------------------------------------
// cnss_utils_update_device_type @ 00100620 size=148
// signature: undefined cnss_utils_update_device_type(void)
// callers: []
//------------------------------------------------------------

undefined4 cnss_utils_update_device_type(int param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  undefined *puVar5;
  
  lVar3 = cnss_utils_priv;
  if (cnss_utils_priv == 0) {
    uVar4 = 0xffffffea;
  }
  else {
    lVar1 = cnss_utils_priv + 0x1d0;
    mutex_lock(lVar1);
    _printk(&DAT_0010169c,param_1);
    iVar2 = *(int *)(lVar3 + 0x200);
    if (iVar2 == -1) {
      *(int *)(lVar3 + 0x200) = param_1;
      puVar5 = &DAT_001015f1;
      iVar2 = param_1;
    }
    else {
      puVar5 = &DAT_00101553;
    }
    _printk(puVar5,iVar2);
    mutex_unlock(lVar1);
    uVar4 = *(undefined4 *)(lVar3 + 0x200);
  }
  return uVar4;
}



//------------------------------------------------------------
// cnss_utils_wlan_set_dfs_nol @ 001006b8 size=168
// signature: undefined cnss_utils_wlan_set_dfs_nol(void)
// callers: []
//------------------------------------------------------------

undefined8 cnss_utils_wlan_set_dfs_nol(undefined8 param_1,long param_2,short param_3)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar1 = cnss_utils_priv;
  if (cnss_utils_priv == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = 0xffffffea;
    if ((param_2 != 0) && (param_3 != 0)) {
      lVar3 = kmemdup(param_2,param_3,0xa20);
      if (lVar3 == 0) {
        uVar2 = 0xfffffff4;
      }
      else {
        _raw_spin_lock_bh(lVar1 + 0x180);
        uVar2 = *(undefined8 *)(lVar1 + 0x140);
        *(long *)(lVar1 + 0x140) = lVar3;
        *(short *)(lVar1 + 0x148) = param_3;
        _raw_spin_unlock_bh(lVar1 + 0x180);
        kfree(uVar2);
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// cnss_utils_wlan_get_dfs_nol @ 00100764 size=168
// signature: undefined cnss_utils_wlan_get_dfs_nol(void)
// callers: []
//------------------------------------------------------------

ulong cnss_utils_wlan_get_dfs_nol(undefined8 param_1,void *param_2,ushort param_3)

{
  long lVar1;
  ushort uVar2;
  long lVar3;
  uint uVar4;
  ulong __n;
  
  lVar3 = cnss_utils_priv;
  if (cnss_utils_priv == 0) {
    return 0xffffffea;
  }
  if (param_2 == (void *)0x0) {
    return 0xffffffea;
  }
  if (param_3 == 0) {
    return 0xffffffea;
  }
  lVar1 = cnss_utils_priv + 0x180;
  _raw_spin_lock_bh(lVar1);
  if (*(long *)(lVar3 + 0x140) != 0) {
    uVar2 = *(ushort *)(lVar3 + 0x148);
    if (uVar2 != 0) {
      uVar4 = (uint)param_3;
      if (uVar2 <= uVar4) {
        uVar4 = (uint)uVar2;
      }
      __n = (ulong)uVar4;
      memcpy(param_2,*(void **)(lVar3 + 0x140),__n);
      goto LAB_001007e8;
    }
  }
  __n = 0xfffffffe;
LAB_001007e8:
  _raw_spin_unlock_bh(lVar1);
  return __n;
}



//------------------------------------------------------------
// cnss_utils_increment_driver_load_cnt @ 00100810 size=28
// signature: undefined cnss_utils_increment_driver_load_cnt(void)
// callers: []
//------------------------------------------------------------

void cnss_utils_increment_driver_load_cnt(void)

{
  if (cnss_utils_priv != 0) {
    *(int *)(cnss_utils_priv + 0x184) = *(int *)(cnss_utils_priv + 0x184) + 1;
  }
  return;
}



//------------------------------------------------------------
// cnss_utils_get_driver_load_cnt @ 00100830 size=28
// signature: undefined cnss_utils_get_driver_load_cnt(void)
// callers: []
//------------------------------------------------------------

undefined4 cnss_utils_get_driver_load_cnt(void)

{
  if (cnss_utils_priv == 0) {
    return 0xffffffea;
  }
  return *(undefined4 *)(cnss_utils_priv + 0x184);
}



//------------------------------------------------------------
// cnss_utils_set_wlan_mac_address @ 00100850 size=280
// signature: undefined cnss_utils_set_wlan_mac_address(void)
// callers: []
//------------------------------------------------------------

undefined8 cnss_utils_set_wlan_mac_address(undefined4 *param_1,uint param_2)

{
  long lVar1;
  uint uVar2;
  
  lVar1 = cnss_utils_priv;
  if (cnss_utils_priv != 0) {
    if ((param_2 != 0) && (param_2 % 6 == 0)) {
      if (0x1d < param_2) {
        _printk(&DAT_00101770,4);
        return 0xffffffea;
      }
      if (*(int *)(cnss_utils_priv + 0x1a0) == 0) {
        *(uint *)(cnss_utils_priv + 0x1a0) = param_2 / 6;
        if (5 < param_2) {
          uVar2 = param_2 / 6;
          *(undefined4 *)(lVar1 + 0x188) = *param_1;
          if (uVar2 < 2) {
            uVar2 = 1;
          }
          *(undefined2 *)(lVar1 + 0x18c) = *(undefined2 *)(param_1 + 1);
          if (0xb < param_2) {
            *(undefined4 *)(lVar1 + 0x18e) = *(undefined4 *)((long)param_1 + 6);
            *(undefined2 *)(lVar1 + 0x192) = *(undefined2 *)((long)param_1 + 10);
            if (uVar2 != 2) {
              *(undefined4 *)(lVar1 + 0x194) = param_1[3];
              *(undefined2 *)(lVar1 + 0x198) = *(undefined2 *)(param_1 + 4);
              if (uVar2 != 3) {
                *(undefined4 *)(lVar1 + 0x19a) = *(undefined4 *)((long)param_1 + 0x12);
                *(undefined2 *)(lVar1 + 0x19e) = *(undefined2 *)((long)param_1 + 0x16);
                return 0;
              }
            }
          }
        }
      }
      else {
        _printk(&DAT_0010163f,*(int *)(cnss_utils_priv + 0x1a0),0);
      }
      return 0;
    }
    _printk(&DAT_0010150a);
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// cnss_utils_set_wlan_derived_mac_address @ 0010096c size=280
// signature: undefined cnss_utils_set_wlan_derived_mac_address(void)
// callers: []
//------------------------------------------------------------

undefined8 cnss_utils_set_wlan_derived_mac_address(undefined4 *param_1,uint param_2)

{
  long lVar1;
  uint uVar2;
  
  lVar1 = cnss_utils_priv;
  if (cnss_utils_priv != 0) {
    if ((param_2 != 0) && (param_2 % 6 == 0)) {
      if (0x1d < param_2) {
        _printk(&DAT_00101770,4);
        return 0xffffffea;
      }
      if (*(int *)(cnss_utils_priv + 0x1bc) == 0) {
        *(uint *)(cnss_utils_priv + 0x1bc) = param_2 / 6;
        if (5 < param_2) {
          uVar2 = param_2 / 6;
          *(undefined4 *)(lVar1 + 0x1a4) = *param_1;
          if (uVar2 < 2) {
            uVar2 = 1;
          }
          *(undefined2 *)(lVar1 + 0x1a8) = *(undefined2 *)(param_1 + 1);
          if (0xb < param_2) {
            *(undefined4 *)(lVar1 + 0x1aa) = *(undefined4 *)((long)param_1 + 6);
            *(undefined2 *)(lVar1 + 0x1ae) = *(undefined2 *)((long)param_1 + 10);
            if (uVar2 != 2) {
              *(undefined4 *)(lVar1 + 0x1b0) = param_1[3];
              *(undefined2 *)(lVar1 + 0x1b4) = *(undefined2 *)(param_1 + 4);
              if (uVar2 != 3) {
                *(undefined4 *)(lVar1 + 0x1b6) = *(undefined4 *)((long)param_1 + 0x12);
                *(undefined2 *)(lVar1 + 0x1ba) = *(undefined2 *)((long)param_1 + 0x16);
                return 0;
              }
            }
          }
        }
      }
      else {
        _printk(&DAT_0010163f,*(int *)(cnss_utils_priv + 0x1bc),1);
      }
      return 0;
    }
    _printk(&DAT_0010150a);
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// cnss_utils_get_wlan_mac_address @ 00100a88 size=92
// signature: undefined cnss_utils_get_wlan_mac_address(void)
// callers: []
//------------------------------------------------------------

long cnss_utils_get_wlan_mac_address(undefined8 param_1,int *param_2)

{
  long lVar1;
  int iVar2;
  
  if (cnss_utils_priv != 0) {
    iVar2 = *(int *)(cnss_utils_priv + 0x1a0);
    if (iVar2 != 0) {
      lVar1 = cnss_utils_priv + 0x188;
      goto LAB_00100ad0;
    }
    _printk(&DAT_001016ed,0);
  }
  iVar2 = 0;
  lVar1 = 0;
LAB_00100ad0:
  *param_2 = iVar2;
  return lVar1;
}



//------------------------------------------------------------
// cnss_utils_get_wlan_derived_mac_address @ 00100ae8 size=92
// signature: undefined cnss_utils_get_wlan_derived_mac_address(void)
// callers: []
//------------------------------------------------------------

long cnss_utils_get_wlan_derived_mac_address(undefined8 param_1,int *param_2)

{
  long lVar1;
  int iVar2;
  
  if (cnss_utils_priv != 0) {
    iVar2 = *(int *)(cnss_utils_priv + 0x1bc);
    if (iVar2 != 0) {
      lVar1 = cnss_utils_priv + 0x1a4;
      goto LAB_00100b30;
    }
    _printk(&DAT_001016ed,1);
  }
  iVar2 = 0;
  lVar1 = 0;
LAB_00100b30:
  *param_2 = iVar2;
  return lVar1;
}



//------------------------------------------------------------
// cnss_utils_set_cc_source @ 00100b48 size=20
// signature: undefined cnss_utils_set_cc_source(void)
// callers: []
//------------------------------------------------------------

void cnss_utils_set_cc_source(undefined8 param_1,undefined4 param_2)

{
  if (cnss_utils_priv != 0) {
    *(undefined4 *)(cnss_utils_priv + 0x1c0) = param_2;
  }
  return;
}



//------------------------------------------------------------
// cnss_utils_get_cc_source @ 00100b60 size=28
// signature: undefined cnss_utils_get_cc_source(void)
// callers: []
//------------------------------------------------------------

undefined4 cnss_utils_get_cc_source(void)

{
  if (cnss_utils_priv == 0) {
    return 0xffffffea;
  }
  return *(undefined4 *)(cnss_utils_priv + 0x1c0);
}



//------------------------------------------------------------
// cnss_utils_mac_write @ 00100b80 size=764
// signature: undefined cnss_utils_mac_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cnss_utils_mac_write(long param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  char *__s2;
  char *pcVar4;
  size_t sVar5;
  undefined *puVar6;
  ulong uVar7;
  undefined8 *puVar8;
  ulong uVar9;
  char *pcVar10;
  undefined1 *puVar11;
  long lVar12;
  undefined1 local_dc [4];
  char *local_d8;
  undefined2 local_cc;
  undefined1 local_ca;
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
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar12 = sp_el0;
  local_48 = *(long *)(lVar12 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  lVar12 = *(long *)(*(long *)(param_1 + 0xd8) + 0x80);
  uVar7 = param_3;
  if (0x7e < param_3) {
    uVar7 = 0x7f;
  }
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
  local_d8 = (char *)0x0;
  local_dc[0] = 0;
  local_ca = 0;
  local_cc = 0;
  __check_object_size(&local_c8,uVar7,0);
  puVar8 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
     (uVar9 = param_2, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
    uVar9 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar3 = uVar7;
  if (uVar9 <= 0x8000000000 - uVar7) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar9 = daif;
      if ((uVar9 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      puVar8 = (undefined8 *)puVar8[1];
      uVar3 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar8 & 0xffff000000000000 | uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar8;
      InstructionSynchronizationBarrier();
      daif = uVar9;
    }
    uVar3 = __arch_copy_from_user(puVar8,&local_c8,param_2 & 0xff7fffffffffffff,uVar7);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar9 = daif;
      if ((uVar9 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      uVar1 = ttbr1_el1;
      ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar9;
    }
  }
  if (uVar3 == 0) {
    local_d8 = (char *)&local_c8;
    local_d8[uVar7] = '\0';
    __s2 = strsep(&local_d8,"\n");
    uVar7 = 0xffffffffffffffea;
    if ((__s2 == (char *)0x0) || (local_d8 == (char *)0x0)) goto LAB_00100e30;
    pcVar4 = strsep(&local_d8,"\n");
    if (pcVar4 != (char *)0x0) {
      iVar2 = strcmp("0x",pcVar4);
      if (iVar2 == 0) {
        sVar5 = strlen(pcVar4);
        pcVar10 = (char *)(sVar5 - 2);
        if ((sVar5 - 0xe < 0x25) && ((ulong)pcVar10 % 0xc == 0)) {
          iVar2 = strcmp("provisioned",__s2);
          if (iVar2 == 0) {
            puVar11 = (undefined1 *)(lVar12 + 0x188);
            *(int *)(lVar12 + 0x1a0) = (int)((ulong)pcVar10 / 0xc);
          }
          else {
            iVar2 = strcmp("derived",__s2);
            if (iVar2 != 0) {
              puVar6 = &DAT_0010172b;
              pcVar10 = __s2;
              goto LAB_00100e28;
            }
            puVar11 = (undefined1 *)(lVar12 + 0x1a4);
            *(int *)(lVar12 + 0x1bc) = (int)((ulong)pcVar10 / 0xc);
          }
          if (pcVar10 != (char *)0x0) {
            pcVar4 = pcVar4 + 3;
            do {
              local_cc = CONCAT11(*pcVar4,pcVar4[-1]);
              iVar2 = kstrtou8(&local_cc,0x10,local_dc);
              if (iVar2 != 0) goto LAB_00100e2c;
              pcVar10 = pcVar10 + -1;
              pcVar4 = pcVar4 + 2;
              *puVar11 = local_dc[0];
              puVar11 = puVar11 + 1;
            } while (pcVar10 != (char *)0x0);
          }
          uVar7 = param_3;
          goto LAB_00100e30;
        }
        puVar6 = &DAT_001015c0;
LAB_00100e28:
        _printk(puVar6,pcVar10);
      }
      else {
        _printk(&DAT_001014d2);
      }
    }
  }
LAB_00100e2c:
  uVar7 = 0xffffffffffffffea;
LAB_00100e30:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// cnss_utils_mac_open @ 00100e98 size=48
// signature: undefined cnss_utils_mac_open(void)
// callers: []
//------------------------------------------------------------

void cnss_utils_mac_open(long param_1,undefined8 param_2)

{
  single_open(param_2,cnss_utils_mac_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// cnss_utils_mac_show @ 00100ecc size=716
// signature: undefined cnss_utils_mac_show(void)
// callers: []
//------------------------------------------------------------

undefined8 cnss_utils_mac_show(long param_1)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x80);
  if ((*(int *)(lVar3 + 0x1a0) != 0) &&
     (seq_puts(param_1,"\nProvisioned MAC addresseses\n"), *(int *)(lVar3 + 0x1a0) != 0)) {
    uVar1 = *(uint *)(lVar3 + 0x188);
    seq_printf(param_1,"MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",uVar1 & 0xff,uVar1 >> 8 & 0xff,
               uVar1 >> 0x10 & 0xff,uVar1 >> 0x18,*(ushort *)(lVar3 + 0x18c) & 0xff,
               *(ushort *)(lVar3 + 0x18c) >> 8);
    if (1 < *(uint *)(lVar3 + 0x1a0)) {
      uVar1 = *(uint *)(lVar3 + 0x18e);
      seq_printf(param_1,"MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",uVar1 & 0xff,uVar1 >> 8 & 0xff,
                 uVar1 >> 0x10 & 0xff,uVar1 >> 0x18,*(ushort *)(lVar3 + 0x192) & 0xff,
                 *(ushort *)(lVar3 + 0x192) >> 8);
      if (2 < *(uint *)(lVar3 + 0x1a0)) {
        uVar1 = *(uint *)(lVar3 + 0x194);
        seq_printf(param_1,"MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",uVar1 & 0xff,uVar1 >> 8 & 0xff
                   ,uVar1 >> 0x10 & 0xff,uVar1 >> 0x18,*(ushort *)(lVar3 + 0x198) & 0xff,
                   *(ushort *)(lVar3 + 0x198) >> 8);
        if (3 < *(uint *)(lVar3 + 0x1a0)) {
          uVar1 = *(uint *)(lVar3 + 0x19a);
          seq_printf(param_1,"MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",uVar1 & 0xff,
                     uVar1 >> 8 & 0xff,uVar1 >> 0x10 & 0xff,uVar1 >> 0x18,
                     *(ushort *)(lVar3 + 0x19e) & 0xff,*(ushort *)(lVar3 + 0x19e) >> 8);
          uVar1 = *(uint *)(lVar3 + 0x1a0);
          if ((4 < uVar1) &&
             (seq_printf(param_1,"MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",uVar1 & 0xff,
                         uVar1 >> 8 & 0xff,uVar1 >> 0x10 & 0xff,uVar1 >> 0x18,
                         *(ushort *)(lVar3 + 0x1a4) & 0xff,*(ushort *)(lVar3 + 0x1a4) >> 8),
             5 < *(uint *)(lVar3 + 0x1a0))) goto LAB_00101194;
        }
      }
    }
  }
  if ((*(int *)(lVar3 + 0x1bc) != 0) &&
     (seq_puts(param_1,"\nDerived MAC addresseses\n"), *(int *)(lVar3 + 0x1bc) != 0)) {
    uVar1 = *(uint *)(lVar3 + 0x1a4);
    seq_printf(param_1,"MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",uVar1 & 0xff,uVar1 >> 8 & 0xff,
               uVar1 >> 0x10 & 0xff,uVar1 >> 0x18,*(ushort *)(lVar3 + 0x1a8) & 0xff,
               *(ushort *)(lVar3 + 0x1a8) >> 8);
    if (1 < *(uint *)(lVar3 + 0x1bc)) {
      uVar1 = *(uint *)(lVar3 + 0x1aa);
      seq_printf(param_1,"MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",uVar1 & 0xff,uVar1 >> 8 & 0xff,
                 uVar1 >> 0x10 & 0xff,uVar1 >> 0x18,*(ushort *)(lVar3 + 0x1ae) & 0xff,
                 *(ushort *)(lVar3 + 0x1ae) >> 8);
      if (2 < *(uint *)(lVar3 + 0x1bc)) {
        uVar1 = *(uint *)(lVar3 + 0x1b0);
        seq_printf(param_1,"MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",uVar1 & 0xff,uVar1 >> 8 & 0xff
                   ,uVar1 >> 0x10 & 0xff,uVar1 >> 0x18,*(ushort *)(lVar3 + 0x1b4) & 0xff,
                   *(ushort *)(lVar3 + 0x1b4) >> 8);
        if (3 < *(uint *)(lVar3 + 0x1bc)) {
          uVar1 = *(uint *)(lVar3 + 0x1b6);
          seq_printf(param_1,"MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",uVar1 & 0xff,
                     uVar1 >> 8 & 0xff,uVar1 >> 0x10 & 0xff,uVar1 >> 0x18,
                     *(ushort *)(lVar3 + 0x1ba) & 0xff,*(ushort *)(lVar3 + 0x1ba) >> 8);
          uVar1 = *(uint *)(lVar3 + 0x1bc);
          if ((4 < uVar1) &&
             (seq_printf(param_1,"MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",uVar1 & 0xff,
                         uVar1 >> 8 & 0xff,uVar1 >> 0x10 & 0xff,uVar1 >> 0x18,
                         *(ushort *)(lVar3 + 0x1c0) & 0xff,*(ushort *)(lVar3 + 0x1c0) >> 8),
             5 < *(uint *)(lVar3 + 0x1bc))) {
LAB_00101194:
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x101198);
            (*pcVar2)();
          }
        }
      }
    }
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00101368 size=296
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 init_module(void)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = of_find_node_with_property(0,"qcom,wlan");
  if (lVar1 != 0) {
    do {
      uVar2 = of_device_is_available(lVar1);
      if ((uVar2 & 1) != 0) {
        lVar1 = kmalloc_trace(_strcmp,0xdc0,0x208);
        if (lVar1 == 0) {
          return 0xfffffff4;
        }
        *(undefined4 *)(lVar1 + 0x1c0) = 0;
        *(undefined4 *)(lVar1 + 0x200) = 0xffffffff;
        __mutex_init(lVar1 + 0x150,"&priv->unsafe_channel_list_lock",&cnss_utils_init___key);
        __mutex_init(lVar1 + 0x1d0,"&priv->cnss_device_id_lock",&cnss_utils_init___key_13);
        *(undefined4 *)(lVar1 + 0x180) = 0;
        uVar2 = debugfs_create_dir("cnss_utils",0);
        if (uVar2 < 0xfffffffffffff001) {
          *(ulong *)(lVar1 + 0x1c8) = uVar2;
          debugfs_create_file("mac_address",0x180,uVar2,lVar1,&cnss_utils_mac_fops);
        }
        else {
          _printk(&DAT_00101595,uVar2 & 0xffffffff);
        }
        cnss_utils_priv = lVar1;
        return 0;
      }
      lVar1 = of_find_node_with_property(lVar1,"qcom,wlan");
    } while (lVar1 != 0);
  }
  return 0xffffffed;
}



//------------------------------------------------------------
// cleanup_module @ 00101494 size=48
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  kfree(cnss_utils_priv);
  cnss_utils_priv = 0;
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00103000 size=1
// signature: undefined mutex_lock(void)
// callers: [cnss_utils_get_wlan_unsafe_channel, cnss_utils_set_wlan_unsafe_channel, cnss_utils_update_device_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00103008 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [cnss_utils_get_wlan_unsafe_channel, cnss_utils_set_wlan_unsafe_channel, cnss_utils_wlan_get_dfs_nol]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103010 size=1
// signature: undefined mutex_unlock(void)
// callers: [cnss_utils_get_wlan_unsafe_channel, cnss_utils_set_wlan_unsafe_channel, cnss_utils_update_device_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103018 size=1
// signature: undefined _printk(void)
// callers: [cnss_utils_set_wlan_mac_address, cnss_utils_get_wlan_mac_address, cnss_utils_mac_write, cnss_utils_update_device_type, cnss_utils_get_wlan_derived_mac_address, cnss_utils_set_wlan_derived_mac_address, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmemdup @ 00103020 size=1
// signature: undefined kmemdup(void)
// callers: [cnss_utils_wlan_set_dfs_nol]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmemdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_bh @ 00103028 size=1
// signature: undefined _raw_spin_lock_bh(void)
// callers: [cnss_utils_wlan_set_dfs_nol, cnss_utils_wlan_get_dfs_nol]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_bh @ 00103030 size=1
// signature: undefined _raw_spin_unlock_bh(void)
// callers: [cnss_utils_wlan_set_dfs_nol, cnss_utils_wlan_get_dfs_nol]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00103038 size=1
// signature: undefined kfree(void)
// callers: [cnss_utils_wlan_set_dfs_nol, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_with_property @ 00103040 size=1
// signature: undefined of_find_node_with_property(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_with_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_available @ 00103048 size=1
// signature: undefined of_device_is_available(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00103058 size=1
// signature: undefined kmalloc_trace(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00103060 size=1
// signature: undefined __mutex_init(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00103068 size=1
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
// debugfs_create_file @ 00103070 size=1
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
// __check_object_size @ 00103078 size=1
// signature: undefined __check_object_size(void)
// callers: [cnss_utils_mac_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00103090 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [cnss_utils_mac_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 00103098 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [cnss_utils_mac_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001030a0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [cnss_utils_mac_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 001030a8 size=1
// signature: size_t strlen(char * __s)
// callers: [cnss_utils_mac_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtou8 @ 001030b0 size=1
// signature: undefined kstrtou8(void)
// callers: [cnss_utils_mac_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtou8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030b8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [cnss_utils_mac_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 001030c8 size=1
// signature: undefined single_open(void)
// callers: [cnss_utils_mac_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 001030d0 size=1
// signature: undefined seq_puts(void)
// callers: [cnss_utils_mac_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 001030d8 size=1
// signature: undefined seq_printf(void)
// callers: [cnss_utils_mac_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



