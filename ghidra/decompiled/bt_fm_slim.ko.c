// Decompiled by Ghidra 12.2
// Program: bt_fm_slim.ko
// Image base: 00100000

//------------------------------------------------------------
// btfm_slim_write @ 0010058c size=344
// signature: undefined btfm_slim_write(void)
// callers: [btfm_slim_slave_enable_port]
//------------------------------------------------------------

int btfm_slim_write(long param_1,uint param_2,undefined4 param_3,char param_4)

{
  long lVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  
  puVar2 = &DAT_001025da;
  if (param_4 != '\0') {
    puVar2 = &DAT_0010245c;
  }
  _printk(&DAT_00102afe,"btfm_slim_write",puVar2);
  lVar1 = param_1 + 0x400;
  iVar4 = (param_2 & 0xffff) + 0x800;
  lVar6 = param_1 + 0x10;
  mutex_lock(lVar1);
  lVar5 = lVar6;
  if (param_4 != '\0') {
    lVar5 = *(long *)(param_1 + 8);
  }
  iVar3 = slim_writeb(lVar5,iVar4,param_3);
  mutex_unlock(lVar1);
  if (iVar3 != 0) {
    usleep_range_state(5000,0x13ec,2);
    mutex_lock(lVar1);
    lVar5 = lVar6;
    if (param_4 != '\0') {
      lVar5 = *(long *)(param_1 + 8);
    }
    iVar3 = slim_writeb(lVar5,iVar4,param_3);
    mutex_unlock(lVar1);
    if (iVar3 != 0) {
      usleep_range_state(5000,0x13ec,2);
      mutex_lock(lVar1);
      if (param_4 != '\0') {
        lVar6 = *(long *)(param_1 + 8);
      }
      iVar4 = slim_writeb(lVar6,iVar4,param_3);
      mutex_unlock(lVar1);
      if (iVar4 == 0) {
        return 0;
      }
      usleep_range_state(5000,0x13ec,2);
      return iVar4;
    }
  }
  return 0;
}



//------------------------------------------------------------
// btfm_slim_read @ 001006e8 size=276
// signature: undefined btfm_slim_read(void)
// callers: [btfm_slim_slave_hw_init]
//------------------------------------------------------------

int btfm_slim_read(long param_1,int param_2,char param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  
  lVar1 = param_1 + 0x400;
  lVar4 = param_1 + 0x10;
  param_2 = param_2 + 0x800;
  mutex_lock(lVar1);
  lVar3 = lVar4;
  if (param_3 != '\0') {
    lVar3 = *(long *)(param_1 + 8);
  }
  iVar2 = slim_readb(lVar3,param_2);
  mutex_unlock(lVar1);
  if (iVar2 < 1) {
    usleep_range_state(5000,0x13ec,2);
    mutex_lock(lVar1);
    lVar3 = lVar4;
    if (param_3 != '\0') {
      lVar3 = *(long *)(param_1 + 8);
    }
    iVar2 = slim_readb(lVar3,param_2);
    mutex_unlock(lVar1);
    if (iVar2 < 1) {
      usleep_range_state(5000,0x13ec,2);
      mutex_lock(lVar1);
      if (param_3 != '\0') {
        lVar4 = *(long *)(param_1 + 8);
      }
      iVar2 = slim_readb(lVar4,param_2);
      mutex_unlock(lVar1);
      if (iVar2 < 1) {
        usleep_range_state(5000,0x13ec,2);
      }
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// btfm_slim_enable_ch @ 00100800 size=580
// signature: undefined btfm_slim_enable_ch(void)
// callers: [btfm_slim_dai_prepare]
//------------------------------------------------------------

int btfm_slim_enable_ch(long param_1,long param_2,undefined4 param_3,undefined4 param_4,byte param_5
                       )

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  undefined *puVar5;
  code *pcVar6;
  ushort *puVar7;
  
  iVar3 = -0x16;
  if ((param_1 != 0) && (param_2 != 0)) {
    lVar4 = slim_stream_allocate(*(undefined8 *)(param_1 + 8),"BTFM_SLIM");
    *(long *)(param_2 + 0x40) = lVar4;
    if (lVar4 == 0) {
      _printk(&DAT_0010290c,"btfm_slim_enable_ch");
    }
    else {
      *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_1 + 0x444);
      uVar1 = *(ushort *)(param_1 + 0x448);
      *(undefined4 *)(param_2 + 0x18) = param_4;
      *(uint *)(param_2 + 0x20) = (uint)param_5;
      *(uint *)(param_2 + 0x38) = (uint)uVar1;
      lVar4 = __kmalloc((ulong)param_5 << 2,0xdc0);
      *(long *)(param_2 + 0x28) = lVar4;
      if (lVar4 == 0) {
        iVar3 = -0xc;
      }
      else {
        if (param_5 != 0) {
          lVar4 = 0;
          puVar7 = (ushort *)(param_2 + 0x10);
          do {
            pcVar6 = *(code **)(param_1 + 0x468);
            if (pcVar6 != (code *)0x0) {
              if (*(int *)(pcVar6 + -4) != 0x139f5d8d) {
                    /* WARNING: Does not return */
                pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1009d4);
                (*pcVar6)();
              }
              iVar3 = (*pcVar6)(param_1,(char)*puVar7,param_3,1);
              if (iVar3 < 0) {
                puVar5 = &DAT_00102c43;
                goto LAB_00100a04;
              }
            }
            *(uint *)(*(long *)(param_2 + 0x28) + lVar4) = (uint)(byte)puVar7[1];
            lVar4 = lVar4 + 4;
            *(ulong *)(param_2 + 0x30) = 1L << ((ulong)*puVar7 & 0x3f) | *(ulong *)(param_2 + 0x30);
            puVar7 = puVar7 + 0x24;
          } while ((ulong)param_5 * 4 != lVar4);
        }
        _printk(&DAT_00102b7a,"btfm_slim_enable_ch",*(undefined2 *)(param_2 + 0x10),
                *(undefined1 *)(param_2 + 0x12));
        uVar2 = btpower_get_chipset_version();
        _printk(&DAT_0010282e,"btfm_slim_enable_ch",uVar2);
        if (btfm_feedback_ch_setting != 0) {
          btfm_feedback_ch_setting = 0;
        }
        iVar3 = slim_stream_prepare(*(undefined8 *)(param_2 + 0x40),param_2 + 0x18);
        if (iVar3 == 0) {
          iVar3 = slim_stream_enable(*(undefined8 *)(param_2 + 0x40));
          if (iVar3 == 0) {
            btfm_num_ports_open = btfm_num_ports_open + 1;
            _printk(&DAT_00102e64,"btfm_slim_enable_ch");
            return 0;
          }
          puVar5 = &DAT_0010292f;
        }
        else {
          puVar5 = &DAT_00102bd0;
        }
LAB_00100a04:
        _printk(puVar5,"btfm_slim_enable_ch",iVar3);
        _printk(&DAT_0010298a,"btfm_slim_enable_ch",iVar3,btfm_num_ports_open);
        kfree(*(undefined8 *)(param_2 + 0x28));
        *(undefined8 *)(param_2 + 0x28) = 0;
      }
    }
  }
  return iVar3;
}



//------------------------------------------------------------
// btfm_slim_disable_ch @ 00100a48 size=888
// signature: undefined btfm_slim_disable_ch(void)
// callers: [btfm_slim_dai_shutdown]
//------------------------------------------------------------

int btfm_slim_disable_ch(long param_1,long param_2,uint param_3,byte param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  
  if (param_1 == 0) {
    return -0x16;
  }
  if (param_2 == 0) {
    return -0x16;
  }
  _printk(&DAT_00102ee0,"btfm_slim_disable_ch",*(undefined2 *)(param_2 + 0x10));
  if (*(long *)(param_2 + 0x40) == 0) {
    _printk(&DAT_001029c6,"btfm_slim_disable_ch");
    return -0x16;
  }
  if (((param_3 & 0xff) != 0) &&
     ((*(int *)(param_1 + 0x43c) == 0x15888 || (*(int *)(param_1 + 0x43c) == 0xac44)))) {
    _printk(&DAT_001029f0,"btfm_slim_disable_ch");
    iVar2 = slim_stream_unprepare_disconnect_port(*(undefined8 *)(param_2 + 0x40),1,0);
    if (iVar2 != 0) {
      _printk(&DAT_0010240d,"btfm_slim_disable_ch",iVar2);
    }
  }
  iVar2 = slim_stream_disable(*(undefined8 *)(param_2 + 0x40));
  if (iVar2 != 0) {
    _printk(&DAT_00102e83,"btfm_slim_disable_ch",iVar2);
    if (((*(int *)(param_1 + 0x43c) != 0xac44) && (*(int *)(param_1 + 0x43c) != 0x15888)) &&
       (iVar2 = slim_stream_unprepare_disconnect_port(*(undefined8 *)(param_2 + 0x40),1,0),
       iVar2 != 0)) {
      _printk(&DAT_0010240d,"btfm_slim_disable_ch",iVar2);
    }
  }
  iVar2 = slim_stream_unprepare_disconnect_port(*(undefined8 *)(param_2 + 0x40),0,1);
  if (iVar2 != 0) {
    _printk(&DAT_00102d17,"btfm_slim_disable_ch",iVar2);
  }
  uVar3 = (uint)param_4;
  if (param_4 != 0) {
    do {
      pcVar5 = *(code **)(param_1 + 0x468);
      if (pcVar5 != (code *)0x0) {
        if (*(int *)(pcVar5 + -4) != 0x139f5d8d) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x100c1c);
          (*pcVar5)();
        }
        iVar2 = (*pcVar5)(param_1,*(undefined1 *)(param_2 + 0x10),param_3,0);
        if (iVar2 < 0) {
          _printk(&DAT_00102ab1,"btfm_slim_disable_ch",iVar2);
          break;
        }
      }
      param_2 = param_2 + 0x48;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  *(undefined8 *)(param_2 + 0x30) = 0;
  if (*(long *)(param_2 + 0x28) == 0) {
    _printk(&DAT_0010284c,"btfm_slim_disable_ch");
  }
  else {
    kfree();
    _printk(&DAT_00102674,"btfm_slim_disable_ch");
    *(undefined8 *)(param_2 + 0x28) = 0;
  }
  if (0 < btfm_num_ports_open) {
    btfm_num_ports_open = btfm_num_ports_open + -1;
  }
  iVar1 = btfm_num_ports_open;
  *(undefined8 *)(param_2 + 0x40) = 0;
  _printk(&DAT_00102e64,"btfm_slim_disable_ch",iVar1);
  uVar3 = btpower_get_chipset_version();
  if (btfm_num_ports_open != 0) {
    return iVar2;
  }
  if ((int)uVar3 < 0x40140100) {
    if ((int)uVar3 < 0x400c0200) {
      if (0x30 < uVar3 + 0xbffdfee0) {
        return iVar2;
      }
      if ((1L << ((ulong)(uVar3 + 0xbffdfee0) & 0x3f) & 0x1000000010001U) == 0) {
        return iVar2;
      }
      goto LAB_00100da0;
    }
    if ((int)uVar3 < 0x400c1201) {
      if (uVar3 == 0x400c0200) goto LAB_00100da0;
      uVar4 = 0x210;
    }
    else {
      if (uVar3 == 0x400c1201) goto LAB_00100da0;
      uVar4 = 0x1211;
    }
    uVar4 = uVar4 | 0x400c0000;
  }
  else {
    if (((uVar3 + 0xbfebff00 < 0x21) &&
        ((1L << ((ulong)(uVar3 + 0xbfebff00) & 0x3f) & 0x100010001U) != 0)) ||
       (uVar3 + 0xbfe8ff00 < 2)) goto LAB_00100da0;
    uVar4 = 0x40170200;
  }
  if (uVar3 != uVar4) {
    return iVar2;
  }
LAB_00100da0:
  _printk(&DAT_001024eb,"btfm_slim_disable_ch");
  msleep(200);
  return iVar2;
}



//------------------------------------------------------------
// btfm_slim_hw_init @ 00100dc4 size=1544
// signature: undefined btfm_slim_hw_init(void)
// callers: [btfm_slim_ioctl, btfm_slim_dai_startup]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int btfm_slim_hw_init(long param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  code *pcVar6;
  undefined2 uVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  
  if (param_1 == 0) {
    return -0x16;
  }
  if (*(char *)(param_1 + 0x430) != '\0') {
    return 0;
  }
  lVar10 = *(long *)(param_1 + 8);
  mutex_lock(param_1 + 0x3d0);
  _printk(&DAT_0010269f,"btfm_slim_hw_init",*(undefined2 *)(lVar10 + 0x394),
          *(undefined2 *)(lVar10 + 0x392),*(undefined1 *)(lVar10 + 0x391),
          *(undefined1 *)(lVar10 + 0x390));
  uVar2 = btpower_get_chipset_version();
  _printk(&DAT_0010282e,"btfm_slim_hw_init",uVar2);
  if ((int)uVar2 < 0x40074130) {
    if ((int)uVar2 < 0x40014320) {
      if (((0x24 < uVar2 + 0xbffefe00) ||
          ((1L << ((ulong)(uVar2 + 0xbffefe00) & 0x3f) & 0x1000100003U) == 0)) &&
         (uVar2 != 0x40010310)) {
        uVar5 = 800;
        goto LAB_00100f7c;
      }
LAB_00101060:
      uVar7 = 0x220;
      puVar4 = &DAT_00102c99;
      goto LAB_0010106c;
    }
    if (((uVar2 + 0xbffdfee0 < 0x31) &&
        ((1L << ((ulong)(uVar2 + 0xbffdfee0) & 0x3f) & 0x1000100010001U) != 0)) ||
       ((uVar2 + 0xbff8feff < 0x30 &&
        ((1L << ((ulong)(uVar2 + 0xbff8feff) & 0x3f) & 0x800080008001U) != 0)))) goto LAB_00101060;
    uVar5 = 0x4320;
LAB_00100f7c:
    uVar5 = uVar5 | 0x40010000;
LAB_00100f80:
    if (uVar2 == uVar5) goto LAB_00101060;
  }
  else {
    uVar7 = 0x221;
    puVar4 = &DAT_00102c68;
    if ((int)uVar2 < 0x400c1211) {
      if ((int)uVar2 < 0x400c0110) {
        if ((int)uVar2 < 0x40075130) {
          if (uVar2 != 0x40074130) {
            uVar5 = 0x40075120;
            goto LAB_00100f80;
          }
        }
        else if (uVar2 != 0x40075130) {
          uVar5 = 0x100;
          goto LAB_00101274;
        }
        goto LAB_00101060;
      }
      if ((int)uVar2 < 0x400c0210) {
        if (uVar2 != 0x400c0110) {
          uVar5 = 0x200;
LAB_00101274:
          if (uVar2 != (uVar5 | 0x400c0000)) goto LAB_001010b0;
        }
      }
      else if (uVar2 != 0x400c0210) {
        uVar5 = 0x1201;
        goto LAB_00101274;
      }
    }
    else if ((int)uVar2 < 0x40170100) {
      if ((0x20 < uVar2 + 0xbfebff00) ||
         ((1L << ((ulong)(uVar2 + 0xbfebff00) & 0x3f) & 0x100010001U) == 0)) {
        uVar5 = 0x1211;
        goto LAB_00101274;
      }
      uVar7 = 0x222;
      puVar4 = &DAT_001026ea;
    }
    else {
      if ((1 < uVar2 + 0xbfe8ff00) && (uVar2 != 0x40170200)) goto LAB_001010b0;
      uVar7 = 0x220;
      puVar4 = &DAT_00102525;
    }
LAB_0010106c:
    _printk(puVar4,"btfm_slim_hw_init");
    *(undefined1 *)(lVar10 + 0x3a5) = 0;
    *(undefined2 *)(lVar10 + 0x392) = uVar7;
    *(undefined2 *)(lVar10 + 0x394) = 0x217;
    *(undefined2 *)(lVar10 + 0x390) = 0x100;
    *(undefined8 *)(param_1 + 0x98) = 0;
    uVar8 = *(undefined8 *)(*(long *)(param_1 + 8) + 0x398);
    *(undefined2 *)(param_1 + 0x3a4) = 0x217;
    *(undefined2 *)(param_1 + 0x3a2) = uVar7;
    *(undefined2 *)(param_1 + 0x3a0) = 0;
    *(undefined8 *)(param_1 + 0x3a8) = uVar8;
    *(undefined2 *)(param_1 + 0x3b4) = 0;
  }
LAB_001010b0:
  _printk(&DAT_00102877,"btfm_slim_hw_init",*(undefined2 *)(lVar10 + 0x394),
          *(undefined2 *)(lVar10 + 0x392),*(undefined1 *)(lVar10 + 0x391),
          *(undefined1 *)(lVar10 + 0x390));
  _printk(&DAT_00102a25,"btfm_slim_hw_init",*(undefined2 *)(param_1 + 0x3a4),
          *(undefined2 *)(param_1 + 0x3a2),*(undefined1 *)(param_1 + 0x3a1),
          *(undefined1 *)(param_1 + 0x3a0));
  lVar10 = _jiffies;
  uVar8 = *(undefined8 *)(param_1 + 8);
  _printk(&DAT_00102a76,"btfm_slim_get_logical_addr");
  do {
    iVar3 = slim_get_logical_addr(uVar8);
    lVar9 = _jiffies;
    if (iVar3 == 0) {
      _printk(&DAT_00102a76,"btfm_slim_get_logical_addr");
      goto LAB_00101170;
    }
    usleep_range_state(1000,0x44c,2);
  } while ((-0x19 - lVar10) + _jiffies < 0);
LAB_0010119c:
  _printk(&DAT_00102b27,"btfm_slim_hw_init",iVar3);
LAB_001011b4:
  mutex_unlock(param_1 + 0x3d0);
  return iVar3;
  while (usleep_range_state(1000,0x44c,2), (-0x19 - lVar9) + _jiffies < 0) {
LAB_00101170:
    iVar3 = slim_get_logical_addr(param_1 + 0x10);
    if (iVar3 == 0) {
      iVar3 = btpower_get_chipset_version();
      _printk(&DAT_0010282e,"btfm_slim_alloc_port",iVar3);
      lVar9 = *(long *)(param_1 + 0x450);
      lVar10 = *(long *)(param_1 + 0x458);
      if ((iVar3 + 0xbffefcf0U < 0x4011) && (sVar1 = *(short *)(lVar10 + 0x10), sVar1 != 0xff)) {
        if (sVar1 == 1) {
          uVar7 = 5;
LAB_001012a0:
          *(undefined2 *)(lVar10 + 0x10) = uVar7;
        }
        else if (sVar1 == 2) {
          uVar7 = 4;
          goto LAB_001012a0;
        }
        _printk(&DAT_00102a7e,"btfm_slim_alloc_port");
        sVar1 = *(short *)(lVar10 + 0x58);
        if (sVar1 != 0xff) {
          if (sVar1 == 1) {
            uVar7 = 5;
LAB_001012f0:
            *(undefined2 *)(lVar10 + 0x58) = uVar7;
          }
          else if (sVar1 == 2) {
            uVar7 = 4;
            goto LAB_001012f0;
          }
          _printk(&DAT_00102a7e,"btfm_slim_alloc_port");
          sVar1 = *(short *)(lVar10 + 0xa0);
          if (sVar1 != 0xff) {
            if (sVar1 == 1) {
              uVar7 = 5;
LAB_00101330:
              *(undefined2 *)(lVar10 + 0xa0) = uVar7;
            }
            else if (sVar1 == 2) {
              uVar7 = 4;
              goto LAB_00101330;
            }
            _printk(&DAT_00102a7e,"btfm_slim_alloc_port");
            sVar1 = *(short *)(lVar10 + 0xe8);
            if (sVar1 != 0xff) {
              if (sVar1 == 1) {
                uVar7 = 5;
LAB_00101370:
                *(undefined2 *)(lVar10 + 0xe8) = uVar7;
              }
              else if (sVar1 == 2) {
                uVar7 = 4;
                goto LAB_00101370;
              }
              _printk(&DAT_00102a7e,"btfm_slim_alloc_port");
              sVar1 = *(short *)(lVar10 + 0x130);
              if (sVar1 != 0xff) {
                if (sVar1 == 1) {
                  uVar7 = 5;
LAB_001013b0:
                  *(undefined2 *)(lVar10 + 0x130) = uVar7;
                }
                else if (sVar1 == 2) {
                  uVar7 = 4;
                  goto LAB_001013b0;
                }
                _printk(&DAT_00102a7e,"btfm_slim_alloc_port");
              }
            }
          }
        }
        lVar10 = *(long *)(param_1 + 0x458);
      }
      iVar3 = -0x16;
      if ((lVar9 != 0) && (iVar3 = -0x16, lVar10 != 0)) {
        pcVar6 = *(code **)(param_1 + 0x460);
        if (pcVar6 == (code *)0x0) {
          iVar3 = 0;
        }
        else {
          if (*(int *)(pcVar6 + -4) != 0x2373e618) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x10123c);
            (*pcVar6)();
          }
          iVar3 = (*pcVar6)(param_1);
        }
        *(undefined1 *)(param_1 + 0x430) = 1;
      }
      goto LAB_001011b4;
    }
  }
  goto LAB_0010119c;
}



//------------------------------------------------------------
// btfm_slim_hw_deinit @ 001013d0 size=104
// signature: undefined btfm_slim_hw_deinit(void)
// callers: [btfm_slim_dai_shutdown]
//------------------------------------------------------------

undefined8 btfm_slim_hw_deinit(long param_1)

{
  undefined8 uVar1;
  
  _printk(&DAT_00102a76,"btfm_slim_hw_deinit");
  if (param_1 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    if (*(char *)(param_1 + 0x430) != '\0') {
      mutex_lock(param_1 + 0x3d0);
      *(undefined1 *)(param_1 + 0x430) = 0;
      mutex_unlock(param_1 + 0x3d0);
    }
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// btfm_slim_get_hwep_details @ 0010143c size=4
// signature: undefined btfm_slim_get_hwep_details(void)
// callers: []
//------------------------------------------------------------

void btfm_slim_get_hwep_details(void)

{
  return;
}



//------------------------------------------------------------
// btfm_slim_probe @ 00101444 size=644
// signature: undefined btfm_slim_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int btfm_slim_probe(long *param_1)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  
  lVar3 = param_1[0xe];
  if (lVar3 == 0) {
    lVar3 = *param_1;
  }
  _printk(&DAT_001025de,"btfm_slim_probe",lVar3);
  *(undefined1 *)((long)param_1 + 0x3a5) = 1;
  is_registered = 0;
  dev_set_name(param_1,&DAT_00102729,"btfmslim_slave");
  lVar3 = param_1[0xe];
  if (lVar3 == 0) {
    lVar3 = *param_1;
  }
  _printk(&DAT_001025de,"btfm_slim_probe",lVar3);
  _printk(&DAT_0010273f,"btfm_slim_probe");
  if (param_1[0x73] == 0) {
    iVar1 = -0x16;
  }
  else {
    plVar2 = (long *)kmalloc_trace(_snd_soc_register_component,0xdc0,0x470);
    if (plVar2 == (long *)0x0) {
      _printk(&DAT_00102ef0,"btfm_slim_probe");
      iVar1 = -0xc;
    }
    else {
      plVar2[1] = (long)param_1;
      plVar2[0x8a] = (long)&slave_rxport;
      plVar2[0x8b] = (long)slave_txport;
      plVar2[0x8c] = (long)btfm_slim_slave_hw_init;
      plVar2[0x8d] = (long)btfm_slim_slave_enable_port;
      __mutex_init(plVar2 + 0x7a,"&btfm_slim->io_lock",&btfm_slim_probe___key);
      __mutex_init(plVar2 + 0x80,"&btfm_slim->xfer_lock",&btfm_slim_probe___key_39);
      param_1[0x13] = (long)plVar2;
      *plVar2 = (long)param_1;
      iVar1 = btpower_register_slimdev(param_1);
      if (iVar1 < 0) {
        iVar1 = -0x205;
      }
      else {
        btfm_slim_drv_data = plVar2;
        btfm_slim_major = __register_chrdev(0,0,0x100,"btfm_slim",bt_dev_fops);
        if (btfm_slim_major < 0) {
          _printk(&DAT_00102ddc,"btfm_slim_probe","btfm_slim_probe");
        }
        else {
          btfm_slim_class = __class_create(&__this_module,"btfmslim-dev",&btfm_slim_probe___key_43);
          if (btfm_slim_class < 0xfffffffffffff001) {
            lVar3 = device_create(btfm_slim_class,0,btfm_slim_major << 0x14,0,"btfmslim");
            if (lVar3 != 0) {
              return iVar1;
            }
            _printk(&DAT_00102ddc,"btfm_slim_probe","btfm_slim_probe");
            class_destroy(btfm_slim_class);
          }
          else {
            _printk(&DAT_0010275d,"btfm_slim_probe","btfm_slim_probe");
          }
          __unregister_chrdev(btfm_slim_major,0,0x100,"btfm_slim");
        }
        iVar1 = -1;
      }
      btfm_slim_unregister_codec(param_1);
      kfree(plVar2);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// btfm_slim_remove @ 001016cc size=48
// signature: undefined btfm_slim_remove(void)
// callers: []
//------------------------------------------------------------

void btfm_slim_remove(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 0x98);
  snd_soc_unregister_component();
  kfree(uVar1);
  return;
}



//------------------------------------------------------------
// btfm_slim_status @ 00101700 size=100
// signature: undefined btfm_slim_status(void)
// callers: []
//------------------------------------------------------------

int btfm_slim_status(long param_1)

{
  int iVar1;
  
  if (((is_registered & 1) == 0) &&
     (iVar1 = btfm_slim_register_codec(*(undefined8 *)(param_1 + 0x98)), iVar1 != 0)) {
    _printk(&DAT_00102bf7,"btfm_slim_status");
  }
  else {
    iVar1 = 0;
    is_registered = 1;
  }
  return iVar1;
}



//------------------------------------------------------------
// btfm_slim_ioctl @ 00101768 size=80
// signature: undefined btfm_slim_ioctl(void)
// callers: []
//------------------------------------------------------------

long btfm_slim_ioctl(undefined8 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0xbfac) {
    _printk(&DAT_0010246f,"btfm_slim_ioctl");
    iVar1 = btfm_slim_hw_init(btfm_slim_drv_data);
    return (long)iVar1;
  }
  return 0;
}



//------------------------------------------------------------
// btfm_slim_register_codec @ 001017bc size=120
// signature: undefined btfm_slim_register_codec(void)
// callers: [btfm_slim_status]
//------------------------------------------------------------

int btfm_slim_register_codec(undefined8 *param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = *param_1;
  _dev_err(uVar2,&DAT_00102cca);
  iVar1 = snd_soc_register_component(uVar2,btfmslim_codec,&btfmslim_dai,5);
  if (iVar1 != 0) {
    _printk(&DAT_001028c8,"btfm_slim_register_codec",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// btfm_slim_unregister_codec @ 00101838 size=28
// signature: undefined btfm_slim_unregister_codec(void)
// callers: [btfm_slim_probe]
//------------------------------------------------------------

void btfm_slim_unregister_codec(void)

{
  snd_soc_unregister_component();
  return;
}



//------------------------------------------------------------
// btfm_slim_codec_probe @ 00101858 size=44
// signature: undefined btfm_slim_codec_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_slim_codec_probe(undefined8 param_1)

{
  snd_soc_add_component_controls(param_1,status_controls,2);
  return 0;
}



//------------------------------------------------------------
// btfm_slim_codec_remove @ 00101888 size=4
// signature: undefined btfm_slim_codec_remove(void)
// callers: []
//------------------------------------------------------------

void btfm_slim_codec_remove(void)

{
  return;
}



//------------------------------------------------------------
// btfm_slim_codec_read @ 00101890 size=8
// signature: undefined btfm_slim_codec_read(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_slim_codec_read(void)

{
  return 0;
}



//------------------------------------------------------------
// btfm_slim_codec_write @ 0010189c size=8
// signature: undefined btfm_slim_codec_write(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_slim_codec_write(void)

{
  return 0;
}



//------------------------------------------------------------
// btfm_soc_status_get @ 001018a8 size=20
// signature: undefined btfm_soc_status_get(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_soc_status_get(undefined8 param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) = (ulong)bt_soc_enable_status;
  return 1;
}



//------------------------------------------------------------
// btfm_soc_status_put @ 001018c0 size=8
// signature: undefined btfm_soc_status_put(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_soc_status_put(void)

{
  return 1;
}



//------------------------------------------------------------
// btfm_get_feedback_ch_setting @ 001018cc size=20
// signature: undefined btfm_get_feedback_ch_setting(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_get_feedback_ch_setting(undefined8 param_1,long param_2)

{
  *(long *)(param_2 + 0x48) = (long)btfm_feedback_ch_setting;
  return 1;
}



//------------------------------------------------------------
// btfm_put_feedback_ch_setting @ 001018e4 size=20
// signature: undefined btfm_put_feedback_ch_setting(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_put_feedback_ch_setting(undefined8 param_1,long param_2)

{
  btfm_feedback_ch_setting = (int)*(undefined8 *)(param_2 + 0x48);
  return 1;
}



//------------------------------------------------------------
// btfm_slim_dai_set_channel_map @ 001018fc size=208
// signature: undefined btfm_slim_dai_set_channel_map(void)
// callers: []
//------------------------------------------------------------

undefined8
btfm_slim_dai_set_channel_map(long param_1,uint param_2,long param_3,uint param_4,long param_5)

{
  bool bVar1;
  long lVar2;
  short *psVar3;
  long lVar4;
  uint uVar5;
  
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0x58) + 0x18) + 0x98);
  if (lVar2 == 0) {
    return 0xffffffea;
  }
  lVar4 = *(long *)(lVar2 + 0x450);
  lVar2 = *(long *)(lVar2 + 0x458);
  if (lVar4 == 0 || lVar2 == 0) {
    return 0;
  }
  if (*(short *)(lVar4 + 0x10) != 0xff && param_4 != 0) {
    psVar3 = (short *)(lVar4 + 0x58);
    uVar5 = 1;
    do {
      *(undefined1 *)(psVar3 + -0x23) =
           *(undefined1 *)
            (param_5 + (-(ulong)(uVar5 - 1 >> 0x1f) & 0xfffffffc00000000 | (ulong)(uVar5 - 1) << 2))
      ;
      if (*psVar3 == 0xff) break;
      bVar1 = uVar5 < param_4;
      psVar3 = psVar3 + 0x24;
      uVar5 = uVar5 + 1;
    } while (bVar1);
  }
  if ((*(short *)(lVar2 + 0x10) != 0xff) && (param_2 != 0)) {
    psVar3 = (short *)(lVar2 + 0x58);
    uVar5 = 1;
    do {
      *(undefined1 *)(psVar3 + -0x23) =
           *(undefined1 *)
            (param_3 + (-(ulong)(uVar5 - 1 >> 0x1f) & 0xfffffffc00000000 | (ulong)(uVar5 - 1) << 2))
      ;
      if (*psVar3 == 0xff) {
        return 0;
      }
      bVar1 = uVar5 < param_2;
      psVar3 = psVar3 + 0x24;
      uVar5 = uVar5 + 1;
    } while (bVar1);
  }
  return 0;
}



//------------------------------------------------------------
// btfm_slim_dai_get_channel_map @ 001019d0 size=596
// signature: undefined btfm_slim_dai_get_channel_map(void)
// callers: []
//------------------------------------------------------------

undefined8
btfm_slim_dai_get_channel_map(long param_1,uint *param_2,uint *param_3,uint *param_4,uint *param_5)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  long lVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  
  lVar6 = *(long *)(*(long *)(*(long *)(param_1 + 0x58) + 0x18) + 0x98);
  if (lVar6 == 0) {
    return 0xffffffea;
  }
  uVar2 = *(undefined4 *)(param_1 + 8);
  uVar8 = 1;
  switch(uVar2) {
  case 0:
    uVar8 = 2;
  case 1:
  case 4:
    if ((param_2 == (uint *)0x0) || (param_3 == (uint *)0x0)) {
      puVar1 = &DAT_0010277e;
      param_5 = param_3;
      param_4 = param_2;
LAB_00101ba8:
      _printk(puVar1,"btfm_slim_dai_get_channel_map",param_5,param_4);
      return 0xffffffea;
    }
    piVar7 = *(int **)(lVar6 + 0x458);
    if (piVar7 == (int *)0x0) {
      return 0xffffffea;
    }
    uVar11 = 0;
    puVar3 = param_3;
    param_3 = param_5;
    uVar5 = uVar8;
    break;
  case 2:
  case 3:
    if ((param_4 == (uint *)0x0) || (param_5 == (uint *)0x0)) {
      puVar1 = &DAT_001025ef;
      goto LAB_00101ba8;
    }
    piVar7 = *(int **)(lVar6 + 0x450);
    if (piVar7 == (int *)0x0) {
      return 0xffffffea;
    }
    uVar8 = 0;
    uVar11 = 1;
    uVar5 = 1;
    puVar3 = param_5;
    break;
  default:
    puVar1 = &DAT_001027d8;
    goto LAB_00101c10;
  }
  *param_3 = 0;
  *param_2 = uVar8;
  *param_4 = uVar11;
  iVar10 = *piVar7;
  if (iVar10 != 5) {
    iVar9 = *(int *)(param_1 + 8);
    if (iVar10 == iVar9) {
      piVar4 = piVar7;
      iVar9 = iVar10;
    }
    else {
      piVar4 = piVar7 + 0x12;
      if (*piVar4 == 5) goto LAB_00101bfc;
      if (*piVar4 != iVar9) {
        piVar4 = piVar7 + 0x24;
        if (*piVar4 == 5) goto LAB_00101bfc;
        if (*piVar4 != iVar9) {
          piVar4 = piVar7 + 0x36;
          if (*piVar4 == 5) goto LAB_00101bfc;
          if (*piVar4 != iVar9) {
            if ((piVar7[0x48] == 5) || (piVar7[0x48] != iVar9)) goto LAB_00101bfc;
            piVar4 = piVar7 + 0x48;
          }
        }
      }
    }
    if (iVar9 != 5) {
      *puVar3 = (uint)*(byte *)((long)piVar4 + 0x12);
      if (uVar5 < 2) {
        return 0;
      }
      piVar7 = piVar4 + 0x12;
      if (piVar7 == (int *)0x0) {
        return 0xffffffea;
      }
      iVar10 = *piVar7;
      if (iVar10 != 5) {
        iVar9 = *(int *)(param_1 + 8);
        if (iVar10 != iVar9) {
          piVar7 = piVar4 + 0x24;
          if (*piVar7 == 5) goto LAB_00101bfc;
          if (*piVar7 != iVar9) {
            piVar7 = piVar4 + 0x36;
            if (*piVar7 == 5) goto LAB_00101bfc;
            if (*piVar7 != iVar9) {
              if (piVar4[0x48] == 5) goto LAB_00101bfc;
              if (piVar4[0x48] == iVar9) {
                piVar7 = piVar4 + 0x48;
              }
              else {
                if ((piVar4[0x5a] == 5) || (piVar4[0x5a] != iVar9)) goto LAB_00101bfc;
                piVar7 = piVar4 + 0x5a;
              }
            }
          }
          iVar10 = iVar9;
        }
        if (iVar10 != 5) {
          puVar3[1] = (uint)*(byte *)((long)piVar7 + 0x12);
          return 0;
        }
      }
    }
  }
LAB_00101bfc:
  uVar2 = *(undefined4 *)(param_1 + 8);
  puVar1 = &DAT_00102e32;
LAB_00101c10:
  _printk(puVar1,"btfm_slim_dai_get_channel_map",uVar2);
  return 0xffffffea;
}



//------------------------------------------------------------
// btfm_slim_dai_startup @ 00101c28 size=40
// signature: undefined btfm_slim_dai_startup(void)
// callers: []
//------------------------------------------------------------

void btfm_slim_dai_startup(undefined8 param_1,long param_2)

{
  btfm_slim_hw_init(*(undefined8 *)(*(long *)(*(long *)(param_2 + 0x58) + 0x18) + 0x98));
  return;
}



//------------------------------------------------------------
// btfm_slim_dai_shutdown @ 00101c54 size=328
// signature: undefined btfm_slim_dai_shutdown(void)
// callers: []
//------------------------------------------------------------

void btfm_slim_dai_shutdown(undefined8 param_1,long param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  long lVar9;
  
  uVar2 = *(uint *)(param_2 + 8);
  if (uVar2 < 5) {
    lVar9 = *(long *)(*(long *)(*(long *)(param_2 + 0x58) + 0x18) + 0x98);
    switch(uVar2) {
    case 0:
      uVar6 = 0;
      puVar8 = (undefined8 *)(lVar9 + 0x458);
      uVar7 = 2;
      break;
    default:
      uVar6 = 0;
      puVar8 = (undefined8 *)(lVar9 + 0x458);
      uVar7 = 1;
      break;
    case 2:
    case 3:
      puVar8 = (undefined8 *)(lVar9 + 0x450);
      uVar6 = 1;
      uVar7 = 1;
    }
    puVar5 = (uint *)*puVar8;
    if (*puVar5 != 5 && *puVar5 != uVar2) {
      uVar3 = puVar5[0x12];
      puVar4 = puVar5 + 0x12;
      if (((uVar3 == 5 || uVar3 == uVar2) ||
          (uVar3 = puVar5[0x24], puVar4 = puVar5 + 0x24, uVar3 == 5 || uVar3 == uVar2)) ||
         (uVar3 = puVar5[0x36], puVar4 = puVar5 + 0x36, uVar3 == 5 || uVar3 == uVar2)) {
        puVar5 = puVar4;
      }
      else {
        puVar4 = puVar5 + 0x48;
        puVar1 = puVar5 + 0x5a;
        puVar5 = puVar5 + 0x48;
        if (*puVar4 != uVar2 && *puVar4 != 5) {
          puVar5 = puVar1;
        }
      }
    }
    if (((short)puVar5[4] == 0xff) || (*puVar5 == 5)) {
      _printk(&DAT_001027fb,"btfm_slim_dai_shutdown",uVar6,uVar7);
    }
    else {
      btfm_slim_disable_ch(lVar9);
      btfm_slim_hw_deinit(lVar9);
    }
  }
  else {
    _printk(&DAT_00102c26,"btfm_slim_dai_shutdown",uVar2);
  }
  return;
}



//------------------------------------------------------------
// btfm_slim_dai_hw_params @ 00101da0 size=140
// signature: undefined btfm_slim_dai_hw_params(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_slim_dai_hw_params(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  
  uVar2 = *(uint *)(param_2 + 0x24);
  lVar4 = *(long *)(*(long *)(*(long *)(param_3 + 0x58) + 0x18) + 0x98);
  if (uVar2 == 0) {
    uVar2 = *(uint *)(param_2 + 0x28);
    if (uVar2 == 0) {
      uVar3 = 0;
      goto LAB_00101df0;
    }
    uVar3 = 0x20;
  }
  else {
    uVar3 = 0;
  }
  uVar2 = (uVar2 & 0xaaaaaaaa) >> 1 | (uVar2 & 0x55555555) << 1;
  uVar2 = (uVar2 & 0xcccccccc) >> 2 | (uVar2 & 0x33333333) << 2;
  uVar2 = (uVar2 & 0xf0f0f0f0) >> 4 | (uVar2 & 0xf0f0f0f) << 4;
  uVar2 = (uVar2 & 0xff00ff00) >> 8 | (uVar2 & 0xff00ff) << 8;
  uVar3 = (uint)LZCOUNT(uVar2 >> 0x10 | uVar2 << 0x10) | uVar3;
LAB_00101df0:
  uVar1 = snd_pcm_format_width(uVar3);
  *(undefined4 *)(lVar4 + 0x444) = uVar1;
  *(short *)(lVar4 + 0x448) = (short)*(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(lVar4 + 0x440) = *(undefined4 *)(param_3 + 8);
  return 0;
}



//------------------------------------------------------------
// btfm_slim_dai_prepare @ 00101e30 size=460
// signature: undefined btfm_slim_dai_prepare(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_slim_dai_prepare(long param_1,undefined8 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  int *piVar4;
  undefined8 *puVar6;
  int *piVar5;
  long lVar7;
  
  uVar1 = *(uint *)(param_1 + 0x3c);
  bt_soc_enable_status = 0;
  lVar7 = *(long *)(*(long *)(param_2[0xb] + 0x18) + 0x98);
  *(short *)(lVar7 + 0x448) = (short)uVar1;
  _printk(&DAT_00102d4d,"btfm_slim_dai_prepare",*param_2,*(undefined4 *)(param_2 + 1),
          *(undefined4 *)(param_2 + 9),uVar1 & 0xffff);
  *(undefined4 *)(lVar7 + 0x43c) = *(undefined4 *)(param_2 + 9);
  iVar2 = *(int *)(param_2 + 1);
  switch(iVar2) {
  case 0:
    uVar3 = 0;
    puVar6 = (undefined8 *)(lVar7 + 0x458);
    break;
  case 1:
  case 4:
    uVar3 = 0;
    puVar6 = (undefined8 *)(lVar7 + 0x458);
    break;
  case 2:
  case 3:
    puVar6 = (undefined8 *)(lVar7 + 0x450);
    uVar3 = 1;
    break;
  default:
    _printk(&DAT_00102c26,"btfm_slim_dai_prepare",iVar2);
    goto LAB_00101fc8;
  }
  piVar5 = (int *)*puVar6;
  if (*piVar5 == 5 || *piVar5 == iVar2) {
    piVar4 = piVar5;
  }
  else {
    piVar4 = piVar5 + 0x12;
    if ((*piVar4 != 5) && (*piVar4 != iVar2)) {
      piVar4 = piVar5 + 0x24;
      if ((*piVar4 != 5) && (*piVar4 != iVar2)) {
        piVar4 = piVar5 + 0x36;
        if ((*piVar4 != 5) && (*piVar4 != iVar2)) {
          piVar4 = piVar5 + 0x48;
          if (piVar5[0x48] != iVar2 && piVar5[0x48] != 5) {
            piVar4 = piVar5 + 0x5a;
          }
        }
      }
    }
  }
  if (((short)piVar4[4] == 0xff) || (*piVar4 == 5)) {
    _printk(&DAT_001027fb,"btfm_slim_dai_prepare",uVar3);
LAB_00101fc8:
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = btfm_slim_enable_ch(lVar7,piVar4,uVar3,*(undefined4 *)(param_2 + 9));
    if ((int)uVar3 == 0) {
      bt_soc_enable_status = 1;
    }
    else if ((int)uVar3 == -0x6a) {
      _printk(&DAT_00102550,"btfm_slim_dai_prepare");
      uVar3 = 0;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// btfm_slim_slave_hw_init @ 00102000 size=160
// signature: undefined btfm_slim_slave_hw_init(void)
// callers: []
//------------------------------------------------------------

int btfm_slim_slave_hw_init(long param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar2 = -0x16;
  }
  else {
    iVar2 = btfm_slim_read(param_1,1,0);
    if (iVar2 < 0) {
      _printk(&DAT_00102da2,"btfm_slim_slave_hw_init",iVar2,1);
    }
    iVar3 = btfm_slim_read(param_1,2,0);
    puVar1 = &DAT_00102da2;
    iVar2 = iVar3;
    if (-1 < iVar3) {
      puVar1 = &DAT_00102a97;
      iVar2 = 0;
    }
    _printk(puVar1,"btfm_slim_slave_hw_init",iVar3,2);
  }
  return iVar2;
}



//------------------------------------------------------------
// btfm_slim_slave_enable_port @ 001020a4 size=764
// signature: undefined btfm_slim_slave_enable_port(void)
// callers: []
//------------------------------------------------------------

int btfm_slim_slave_enable_port(long param_1,uint param_2,char param_3,char param_4)

{
  uint uVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 uVar7;
  byte bVar8;
  
  if (param_3 == '\0') {
    if (param_4 != '\0') {
      _printk(&DAT_001024a3,"is_fm_port",*(undefined4 *)(param_1 + 0x440));
      if (*(int *)(param_1 + 0x440) == 0) {
        uVar1 = param_2 & 0xff;
        uVar7 = 0x10;
        if (uVar1 != 4) {
          uVar7 = 6;
        }
        uVar2 = 0x20;
        if (uVar1 != 5) {
          uVar2 = uVar7;
        }
        iVar6 = uVar1 * 4 + 0x100;
        _printk(&DAT_00102616,"btfm_slim_slave_enable_port",uVar2,iVar6);
        iVar4 = btfm_slim_write(param_1,iVar6,uVar2,0);
        if (iVar4 < 0) goto LAB_00102354;
      }
      else if ((param_2 & 0xff) == 2) {
        iVar4 = btfm_slim_write(param_1,0x108,4,0);
        if (iVar4 < 0) {
          iVar6 = 0x108;
          goto LAB_00102354;
        }
      }
      else if (((param_2 & 0xff) == 0) && (iVar4 = btfm_slim_write(param_1,0x100,1,0), iVar4 < 0)) {
        iVar6 = 0x100;
        goto LAB_00102354;
      }
      iVar6 = (param_2 & 0xff) + 0x1f0;
      iVar4 = btfm_slim_write(param_1,iVar6,3,0);
      if (iVar4 < 0) goto LAB_00102354;
    }
    iVar6 = (param_2 & 0xff) + 0x50;
  }
  else {
    if (((param_4 != '\0') && (*(int *)(param_1 + 0x43c) != 0xac44)) &&
       (*(int *)(param_1 + 0x43c) != 0x15888)) {
      bVar3 = 0x17 < (param_2 & 0xff);
      uVar1 = param_2 - 0x10;
      if (bVar3) {
        uVar1 = param_2 - 0x18;
      }
      iVar6 = 0x180;
      if (bVar3) {
        iVar6 = 0x181;
      }
      iVar6 = iVar6 + (uVar1 & 0xff) * 4;
      iVar4 = btfm_slim_write(param_1,iVar6,1 << (ulong)(uVar1 & 0x1f),0);
      if (iVar4 < 0) goto LAB_00102354;
    }
    iVar6 = (param_2 & 0xff) + 0x30;
  }
  bVar3 = param_4 != '\0';
  _printk(&DAT_001024a3,"is_fm_port",*(undefined4 *)(param_1 + 0x440));
  if (*(int *)(param_1 + 0x440) == 0) {
    bVar8 = bVar3 | 0x10;
    if ((param_2 & 0xff) != 0) goto LAB_0010230c;
LAB_00102304:
    if (param_4 == '\0') goto LAB_0010230c;
    puVar5 = &DAT_00102ce1;
LAB_00102388:
    _printk(puVar5,"btfm_slim_slave_enable_port",bVar8,iVar6);
  }
  else {
    if ((param_2 & 0xff) == 0) {
      bVar8 = bVar3 | 2;
      if (param_4 == '\0') {
        bVar8 = 0;
      }
      if ((param_2 & 0xff) == 0) goto LAB_00102304;
    }
    else {
      bVar8 = bVar3 | 0x16;
      if (param_4 == '\0') {
        bVar8 = 0;
      }
    }
LAB_0010230c:
    if (((param_2 & 0xff) == 2) && (param_4 != '\0')) {
      puVar5 = &DAT_0010263d;
      goto LAB_00102388;
    }
  }
  iVar4 = btfm_slim_write(param_1,iVar6,bVar8,0);
  if (-1 < iVar4) {
    return iVar4;
  }
LAB_00102354:
  _printk(&DAT_00102f20,"btfm_slim_slave_enable_port",iVar4,iVar6);
  return iVar4;
}



//------------------------------------------------------------
// init_module @ 001023a4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __slim_driver_register(&btfm_slim_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001023d4 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  slim_driver_unregister(&btfm_slim_driver);
  return;
}



//------------------------------------------------------------
// _printk @ 00105000 size=1
// signature: undefined _printk(void)
// callers: [btfm_slim_dai_prepare, btfm_slim_dai_get_channel_map, btfm_slim_slave_hw_init, btfm_slim_slave_enable_port, btfm_slim_disable_ch, btfm_slim_status, btfm_slim_write, btfm_slim_hw_init, btfm_slim_probe, btfm_slim_ioctl, btfm_slim_hw_deinit, btfm_slim_dai_shutdown, btfm_slim_enable_ch, btfm_slim_register_codec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00105008 size=1
// signature: undefined mutex_lock(void)
// callers: [btfm_slim_write, btfm_slim_hw_init, btfm_slim_hw_deinit, btfm_slim_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// slim_writeb @ 00105010 size=1
// signature: undefined slim_writeb(void)
// callers: [btfm_slim_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void slim_writeb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00105018 size=1
// signature: undefined mutex_unlock(void)
// callers: [btfm_slim_write, btfm_slim_hw_init, btfm_slim_hw_deinit, btfm_slim_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00105020 size=1
// signature: undefined usleep_range_state(void)
// callers: [btfm_slim_write, btfm_slim_hw_init, btfm_slim_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// slim_readb @ 00105028 size=1
// signature: undefined slim_readb(void)
// callers: [btfm_slim_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void slim_readb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// slim_stream_allocate @ 00105030 size=1
// signature: undefined slim_stream_allocate(void)
// callers: [btfm_slim_enable_ch]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void slim_stream_allocate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00105038 size=1
// signature: undefined __kmalloc(void)
// callers: [btfm_slim_enable_ch]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// btpower_get_chipset_version @ 00105040 size=1
// signature: undefined btpower_get_chipset_version(void)
// callers: [btfm_slim_hw_init, btfm_slim_disable_ch, btfm_slim_enable_ch]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void btpower_get_chipset_version(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// slim_stream_prepare @ 00105048 size=1
// signature: undefined slim_stream_prepare(void)
// callers: [btfm_slim_enable_ch]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void slim_stream_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// slim_stream_enable @ 00105050 size=1
// signature: undefined slim_stream_enable(void)
// callers: [btfm_slim_enable_ch]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void slim_stream_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00105058 size=1
// signature: undefined kfree(void)
// callers: [btfm_slim_remove, btfm_slim_probe, btfm_slim_disable_ch, btfm_slim_enable_ch]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// slim_stream_unprepare_disconnect_port @ 00105060 size=1
// signature: undefined slim_stream_unprepare_disconnect_port(void)
// callers: [btfm_slim_disable_ch]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void slim_stream_unprepare_disconnect_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// slim_stream_disable @ 00105068 size=1
// signature: undefined slim_stream_disable(void)
// callers: [btfm_slim_disable_ch]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void slim_stream_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00105070 size=1
// signature: undefined msleep(void)
// callers: [btfm_slim_disable_ch]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// slim_get_logical_addr @ 00105080 size=1
// signature: undefined slim_get_logical_addr(void)
// callers: [btfm_slim_hw_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void slim_get_logical_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __slim_driver_register @ 00105088 size=1
// signature: undefined __slim_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __slim_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// slim_driver_unregister @ 00105090 size=1
// signature: undefined slim_driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void slim_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 00105098 size=1
// signature: undefined dev_set_name(void)
// callers: [btfm_slim_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001050a8 size=1
// signature: undefined kmalloc_trace(void)
// callers: [btfm_slim_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001050b0 size=1
// signature: undefined __mutex_init(void)
// callers: [btfm_slim_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// btpower_register_slimdev @ 001050b8 size=1
// signature: undefined btpower_register_slimdev(void)
// callers: [btfm_slim_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void btpower_register_slimdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __register_chrdev @ 001050c0 size=1
// signature: undefined __register_chrdev(void)
// callers: [btfm_slim_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __register_chrdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 001050c8 size=1
// signature: undefined __class_create(void)
// callers: [btfm_slim_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 001050d0 size=1
// signature: undefined device_create(void)
// callers: [btfm_slim_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 001050d8 size=1
// signature: undefined class_destroy(void)
// callers: [btfm_slim_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __unregister_chrdev @ 001050e0 size=1
// signature: undefined __unregister_chrdev(void)
// callers: [btfm_slim_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __unregister_chrdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_unregister_component @ 001050e8 size=1
// signature: undefined snd_soc_unregister_component(void)
// callers: [btfm_slim_unregister_codec, btfm_slim_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_unregister_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001050f0 size=1
// signature: undefined _dev_err(void)
// callers: [btfm_slim_register_codec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_register_component @ 001050f8 size=1
// signature: undefined snd_soc_register_component(void)
// callers: [btfm_slim_register_codec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_register_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_add_component_controls @ 00105100 size=1
// signature: undefined snd_soc_add_component_controls(void)
// callers: [btfm_slim_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_add_component_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_pcm_format_width @ 00105108 size=1
// signature: undefined snd_pcm_format_width(void)
// callers: [btfm_slim_dai_hw_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_pcm_format_width(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



