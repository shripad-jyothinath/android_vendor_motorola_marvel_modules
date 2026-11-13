// Decompiled by Ghidra 12.2
// Program: bt_fm_swr.ko
// Image base: 00100000

//------------------------------------------------------------
// btfm_get_bt_soc_index @ 00100444 size=132
// signature: undefined btfm_get_bt_soc_index(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_get_bt_soc_index(int param_1)

{
  undefined8 uVar1;
  
  if (param_1 + 0xbfdfff00U < 6) {
    return 0;
  }
  uVar1 = 1;
  if ((param_1 != 0x40210200) && (param_1 != 0x40210100)) {
    if (param_1 == 0x40200200) {
      return 0;
    }
    _printk(&DAT_00101b6a,"btfm_get_bt_soc_index");
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// btfm_swr_hw_init @ 001004cc size=428
// signature: undefined btfm_swr_hw_init(void)
// callers: [btfm_swr_ioctl, btfm_swr_dai_startup]
//------------------------------------------------------------

int btfm_swr_hw_init(void)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = 0;
  if (*(char *)(pbtfmswr + 0x10) != '\0') {
    _printk(&DAT_0010192b,"btfm_swr_hw_init");
  }
  iVar3 = btpower_get_chipset_version();
  if (iVar3 < 0x40200200) {
    if (5 < iVar3 + 0xbfdfff00U) {
LAB_0010065c:
      _printk(&DAT_00101b6a,"btfm_get_bt_soc_index");
    }
  }
  else {
    uVar4 = 1;
    if ((iVar3 == 0x40210200) || (iVar3 == 0x40210100)) goto LAB_00100548;
    if (iVar3 != 0x40200200) goto LAB_0010065c;
  }
  uVar4 = 0;
LAB_00100548:
  *(undefined4 *)(pbtfmswr + 0x20) = uVar4;
  _printk(&DAT_001019e4,"btfm_swr_hw_init",iVar3);
  *(undefined1 **)(pbtfmswr + 0x28) = &slave_port + (long)*(int *)(pbtfmswr + 0x20) * 0x80;
  uVar5 = 0;
  do {
    iVar3 = swr_get_logical_dev_num
                      (*(undefined8 *)(pbtfmswr + 8),**(undefined8 **)(pbtfmswr + 0x28),local_3c);
    lVar1 = pbtfmswr;
    if (iVar3 == 0) {
      *(undefined1 *)(*(long *)(pbtfmswr + 8) + 0x40) = local_3c[0];
      *(undefined1 *)(lVar1 + 0x10) = 1;
      goto LAB_001005f8;
    }
    usleep_range_state(2000,0x834,2);
    bVar2 = uVar5 < 0xe;
    uVar5 = uVar5 + 1;
  } while (bVar2);
  _printk(&DAT_00101bf1,"btfm_swr_hw_init",0xf);
LAB_001005f8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// btfm_swr_enable_port @ 0010067c size=340
// signature: undefined btfm_swr_enable_port(void)
// callers: [btfm_swr_dai_prepare]
//------------------------------------------------------------

int btfm_swr_enable_port(char param_1,char param_2,undefined4 param_3,undefined1 param_4)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  undefined1 local_3c [4];
  undefined4 local_38;
  undefined1 local_34 [4];
  char local_30 [4];
  char local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = param_1 + -1;
  local_34[0] = 3;
  if (param_2 != '\x02') {
    local_34[0] = 1;
  }
  local_3c[0] = param_4;
  local_38 = param_3;
  local_30[0] = param_2;
  _printk(&DAT_00101387,"btfm_swr_enable_port",param_1,param_2);
  iVar2 = swr_connect_port(*(undefined8 *)(pbtfmswr + 8),local_2c,1,local_34,&local_38,local_30,
                           local_3c);
  if (iVar2 < 0) {
    puVar3 = &DAT_00101460;
    iVar4 = iVar2;
  }
  else {
    _printk(&DAT_001018b2,"btfm_swr_enable_port");
    iVar2 = swr_slvdev_datapath_control
                      (*(long *)(pbtfmswr + 8),*(undefined1 *)(*(long *)(pbtfmswr + 8) + 0x40),1);
    if (iVar2 < 0) {
      _printk(&DAT_001018de,"btfm_swr_enable_port");
    }
    else if (iVar2 == 0) {
      btfm_num_ports_open = btfm_num_ports_open + 1;
    }
    puVar3 = &DAT_00101bd2;
    iVar4 = btfm_num_ports_open;
  }
  _printk(puVar3,"btfm_swr_enable_port",iVar4);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// btfm_swr_disable_port @ 001007d4 size=312
// signature: undefined btfm_swr_disable_port(void)
// callers: [btfm_swr_dai_shutdown]
//------------------------------------------------------------

int btfm_swr_disable_port(char param_1,char param_2,undefined1 param_3)

{
  long lVar1;
  int iVar2;
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  char local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = param_1 + -1;
  local_30[0] = 3;
  if (param_2 != '\x02') {
    local_30[0] = 1;
  }
  local_34[0] = param_3;
  _printk(&DAT_00101489,"btfm_swr_disable_port",param_1);
  iVar2 = swr_disconnect_port(*(undefined8 *)(pbtfmswr + 8),local_2c,1,local_30,local_34);
  if (iVar2 < 0) {
    _printk(&DAT_00101a44,"btfm_swr_disable_port",iVar2);
  }
  _printk(&DAT_001018b2,"btfm_swr_disable_port");
  iVar2 = swr_slvdev_datapath_control
                    (*(long *)(pbtfmswr + 8),*(undefined1 *)(*(long *)(pbtfmswr + 8) + 0x40),0);
  if (iVar2 < 0) {
    _printk(&DAT_001018de,"btfm_swr_disable_port");
  }
  if (0 < btfm_num_ports_open) {
    btfm_num_ports_open = btfm_num_ports_open + -1;
  }
  _printk(&DAT_00101bd2,"btfm_swr_disable_port",btfm_num_ports_open);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// btfm_swr_probe @ 00100910 size=428
// signature: undefined btfm_swr_probe(void)
// callers: []
//------------------------------------------------------------

ulong btfm_swr_probe(long param_1)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  
  _printk(&DAT_00101908,"btfm_swr_probe");
  plVar1 = (long *)devm_kmalloc(param_1 + 0x48,0x30,0xdc0);
  pbtfmswr = plVar1;
  if (plVar1 == (long *)0x0) {
    _printk(&DAT_001014bb,"btfm_swr_probe");
    uVar2 = 0xfffffff4;
  }
  else {
    *(long **)(param_1 + 0xe0) = plVar1;
    *plVar1 = param_1 + 0x48;
    plVar1[1] = param_1;
    *(undefined1 *)(plVar1 + 2) = 0;
    uVar2 = btfm_swr_register_hw_ep();
    if ((int)uVar2 == 0) {
      btfm_swr_major = __register_chrdev(uVar2,0,0x100,"btfm_swr",bt_dev_fops);
      if (btfm_swr_major < 0) {
        _printk(&DAT_00101b97,"btfm_swr_probe","btfm_swr_probe");
      }
      else {
        btfm_swr_class = __class_create(&__this_module,"btfmswr-dev",&btfm_swr_probe___key);
        if (btfm_swr_class < 0xfffffffffffff001) {
          lVar3 = device_create(btfm_swr_class,0,btfm_swr_major << 0x14,0,"btfmswr");
          if (lVar3 != 0) {
            return 0;
          }
          _printk(&DAT_00101b97,"btfm_swr_probe","btfm_swr_probe");
          class_destroy(btfm_swr_class);
        }
        else {
          _printk(&DAT_001016fa,"btfm_swr_probe","btfm_swr_probe");
        }
        __unregister_chrdev(btfm_swr_major,0,0x100,"btfm_swr");
      }
      btfm_swr_unregister_hwep();
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = uVar2 & 0xffffffff;
      _printk(&DAT_001017d5,"btfm_swr_probe");
    }
    kfree(pbtfmswr);
  }
  return uVar2;
}



//------------------------------------------------------------
// btfm_swr_ioctl @ 00100ac0 size=104
// signature: undefined btfm_swr_ioctl(void)
// callers: []
//------------------------------------------------------------

long btfm_swr_ioctl(undefined8 param_1,int param_2)

{
  int iVar1;
  long lVar2;
  
  _printk(&DAT_00101908,"btfm_swr_ioctl");
  if (param_2 == 0xbfac) {
    _printk(&DAT_0010164c,"btfm_swr_ioctl");
    iVar1 = btfm_swr_hw_init();
    lVar2 = (long)iVar1;
  }
  else {
    lVar2 = 0;
  }
  return lVar2;
}



//------------------------------------------------------------
// btfm_get_sampling_rate @ 00100b2c size=248
// signature: undefined btfm_get_sampling_rate(void)
// callers: []
//------------------------------------------------------------

void btfm_get_sampling_rate(int *param_1)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  
  iVar1 = *param_1;
  uVar3 = (uint)usecase_codec;
  if (usecase_codec < 0xf) {
    if ((((iVar1 == 48000) || (iVar1 == 0xac44)) && (usecase_codec < 0xe)) &&
       ((1 << (ulong)(usecase_codec & 0x1f) & 0x2024U) != 0)) {
      *param_1 = iVar1 << 1;
      uVar3 = (uint)usecase_codec;
    }
    if ((uVar3 < 0xc) && ((1 << (ulong)(uVar3 & 0x1f) & 0xdc0U) != 0)) {
      *param_1 = 96000;
      uVar3 = (uint)usecase_codec;
    }
    if (uVar3 == 9) {
      *param_1 = 0x2ee00;
      uVar3 = (uint)usecase_codec;
    }
    if (0xe < uVar3) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x100c24);
      (*pcVar2)();
    }
    _printk(&DAT_00101af6,"btfm_get_sampling_rate",(&codec_text)[uVar3]);
  }
  else {
    _printk(&DAT_001014ee,"btfm_get_sampling_rate",iVar1);
  }
  return;
}



//------------------------------------------------------------
// btfm_swr_dai_get_configs @ 00100c28 size=220
// signature: undefined btfm_swr_dai_get_configs(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_swr_dai_get_configs(long *param_1,byte *param_2,byte param_3)

{
  uint uVar1;
  undefined *puVar2;
  undefined4 uVar3;
  char cVar4;
  bool bVar5;
  byte bVar6;
  byte bVar7;
  long lVar8;
  
  uVar1 = (uint)param_3;
  lVar8 = *(long *)(*param_1 + 0x98);
  _printk(&DAT_001015f1,"btfm_swr_dai_get_configs",uVar1);
  *param_2 = param_3;
  bVar6 = usecase_codec;
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(lVar8 + 0x14);
  uVar3 = *(undefined4 *)(lVar8 + 0x18);
  param_2[10] = bVar6;
  param_2[8] = (byte)uVar3;
  param_2[9] = *(byte *)(lVar8 + 0x1e);
  cVar4 = *(char *)(lVar8 + 0x1e);
  param_2[0xb] = 5;
  bVar6 = 3;
  if (cVar4 != '\x02') {
    bVar6 = 1;
  }
  bVar5 = 1 < uVar1 - 3;
  puVar2 = &DAT_0010172a;
  if (bVar5) {
    puVar2 = &DAT_0010196f;
  }
  bVar7 = 1;
  if (!bVar5) {
    bVar7 = 2;
  }
  param_2[0xd] = bVar6;
  _printk(puVar2,"btfm_swr_dai_get_configs",uVar1);
  param_2[0xc] = bVar7;
  return 1;
}



//------------------------------------------------------------
// btfm_swr_register_hw_ep @ 00100d08 size=280
// signature: undefined btfm_swr_register_hw_ep(void)
// callers: [btfm_swr_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int btfm_swr_register_hw_ep(undefined8 *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  uVar3 = *param_1;
  _printk(&DAT_0010186d,"btfm_swr_register_hw_ep");
  puVar2 = (undefined8 *)kmalloc_trace(_DAT_001040c0,0xdc0,0x70);
  if (puVar2 == (undefined8 *)0x0) {
    _printk(&DAT_00101757,"btfm_swr_register_hw_ep","btfm_swr_register_hw_ep");
    iVar1 = -0xc;
  }
  else {
    *puVar2 = uVar3;
    strscpy(puVar2 + 1,"btfmswr_slave",0xe);
    puVar2[9] = &btfmswr_hw_driver;
    puVar2[10] = &btfmswr_dai_driver;
    *(undefined4 *)(puVar2 + 0xc) = 5;
    _printk(&DAT_00101a75,"btfm_swr_register_hw_ep",5);
    *(undefined4 *)((long)puVar2 + 100) = 3;
    puVar2[0xb] = status_controls;
    iVar1 = btfmcodec_register_hw_ep(puVar2);
    if (iVar1 == 0) {
      _printk(&DAT_001013cf,"btfm_swr_register_hw_ep");
    }
    else {
      _printk(&DAT_00101805,"btfm_swr_register_hw_ep",iVar1);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// btfm_swr_unregister_hwep @ 00100e24 size=56
// signature: undefined btfm_swr_unregister_hwep(void)
// callers: [btfm_swr_probe]
//------------------------------------------------------------

void btfm_swr_unregister_hwep(void)

{
  _printk(&DAT_0010177d,"btfm_swr_unregister_hwep");
  btfmcodec_unregister_hw_ep("btfmswr_slave");
  return;
}



//------------------------------------------------------------
// btfm_swr_hwep_probe @ 00100e60 size=8
// signature: undefined btfm_swr_hwep_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_swr_hwep_probe(void)

{
  return 0;
}



//------------------------------------------------------------
// btfm_swr_hwep_remove @ 00100e6c size=4
// signature: undefined btfm_swr_hwep_remove(void)
// callers: []
//------------------------------------------------------------

void btfm_swr_hwep_remove(void)

{
  return;
}



//------------------------------------------------------------
// btfm_swr_hwep_read @ 00100e74 size=8
// signature: undefined btfm_swr_hwep_read(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_swr_hwep_read(void)

{
  return 0;
}



//------------------------------------------------------------
// btfm_swr_hwep_write @ 00100e80 size=8
// signature: undefined btfm_swr_hwep_write(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_swr_hwep_write(void)

{
  return 0;
}



//------------------------------------------------------------
// btfm_swr_dai_startup @ 00100e8c size=28
// signature: undefined btfm_swr_dai_startup(void)
// callers: []
//------------------------------------------------------------

void btfm_swr_dai_startup(void)

{
  btfm_swr_hw_init();
  return;
}



//------------------------------------------------------------
// btfm_swr_dai_shutdown @ 00100eac size=176
// signature: undefined btfm_swr_dai_shutdown(void)
// callers: []
//------------------------------------------------------------

void btfm_swr_dai_shutdown(long *param_1,uint param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(*param_1 + 0x98);
  _printk(&DAT_00101908,"btfm_swr_dai_shutdown");
  if ((lVar1 == 0) || (*(long *)(lVar1 + 0x28) == 0)) {
    _printk(&DAT_001016c4,"btfm_swr_dai_shutdown");
  }
  else if (param_2 < 5) {
    btfm_swr_disable_port
              (*(undefined1 *)(*(long *)(lVar1 + 0x28) + (ulong)param_2 * 0x18 + 0x18),
               *(undefined1 *)(lVar1 + 0x1e),0x686765666b >> (((ulong)param_2 & 7) << 3));
  }
  else {
    _printk(&DAT_00101a98,"btfm_swr_dai_shutdown",param_2);
  }
  return;
}



//------------------------------------------------------------
// btfm_swr_dai_hw_params @ 00100f60 size=32
// signature: undefined btfm_swr_dai_hw_params(void)
// callers: []
//------------------------------------------------------------

undefined8
btfm_swr_dai_hw_params(long *param_1,undefined4 param_2,undefined2 param_3,undefined1 param_4)

{
  long lVar1;
  
  lVar1 = *(long *)(*param_1 + 0x98);
  *(undefined4 *)(lVar1 + 0x18) = param_2;
  *(undefined2 *)(lVar1 + 0x1c) = param_3;
  *(undefined1 *)(lVar1 + 0x1e) = param_4;
  return 0;
}



//------------------------------------------------------------
// btfm_swr_dai_prepare @ 00100f84 size=508
// signature: undefined btfm_swr_dai_prepare(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_swr_dai_prepare(long *param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar5 = *(long *)(*param_1 + 0x98);
  bt_soc_enable_status = 0;
  _printk(&DAT_00101602,"btfm_swr_dai_prepare",param_4,param_2,param_3);
  if (param_4 == 0) {
    _printk(&DAT_00101ab5,"btfm_swr_dai_prepare");
    uVar4 = 0x6b;
    *(int *)(lVar5 + 0x14) = param_2;
  }
  else {
    if ((ulong)usecase_codec < 0xf) {
      if ((((param_2 == 48000) || (param_2 == 0xac44)) && (usecase_codec < 0xe)) &&
         ((1 << (ulong)(usecase_codec & 0x1f) & 0x2024U) != 0)) {
        param_2 = param_2 << 1;
      }
      if (0xe < usecase_codec) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(1,0x101180);
        (*pcVar3)();
      }
      uVar2 = usecase_codec - 6;
      iVar1 = param_2;
      if ((0x37U >> (ulong)(uVar2 & 0x1f) & 1) != 0) {
        iVar1 = 96000;
      }
      if (5 < (uVar2 & 0xff)) {
        iVar1 = param_2;
      }
      param_2 = 0x2ee00;
      if (usecase_codec != 9) {
        param_2 = iVar1;
      }
      _printk(&DAT_00101af6,"btfm_get_sampling_rate",(&codec_text)[usecase_codec],param_2);
    }
    else {
      _printk(&DAT_001014ee,"btfm_get_sampling_rate",param_2);
    }
    *(int *)(lVar5 + 0x14) = param_2;
    uVar4 = 0x66;
    switch(param_4) {
    case 1:
      break;
    case 2:
      uVar4 = 0x65;
      break;
    case 3:
      uVar4 = 0x67;
      break;
    case 4:
      uVar4 = 0x68;
      break;
    default:
      _printk(&DAT_00101a98,"btfm_swr_dai_prepare",param_4);
      return 0xffffffea;
    }
  }
  uVar4 = btfm_swr_enable_port
                    (*(undefined1 *)(*(long *)(lVar5 + 0x28) + (ulong)param_4 * 0x18 + 0x18),
                     *(undefined1 *)(lVar5 + 0x1e),param_2,uVar4);
  if ((int)uVar4 == 0) {
    bt_soc_enable_status = 1;
  }
  else if ((int)uVar4 == -0x6a) {
    _printk(&DAT_00101564,"btfm_swr_dai_prepare");
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// btfm_swr_dai_set_channel_map @ 00101184 size=8
// signature: undefined btfm_swr_dai_set_channel_map(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_swr_dai_set_channel_map(void)

{
  return 0;
}



//------------------------------------------------------------
// btfm_swr_dai_get_channel_map @ 00101190 size=176
// signature: undefined btfm_swr_dai_get_channel_map(void)
// callers: []
//------------------------------------------------------------

undefined8
btfm_swr_dai_get_channel_map
          (long *param_1,uint *param_2,undefined4 *param_3,uint *param_4,undefined4 *param_5,
          uint param_6)

{
  undefined8 uVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*param_1 + 0x98);
  *param_5 = 0;
  *param_3 = 0;
  *param_4 = 0;
  *param_2 = 0;
  if (param_6 < 5) {
    if ((1 << (ulong)(param_6 & 0x1f) & 0x13U) == 0) {
      uVar1 = 0;
      *param_4 = (uint)*(byte *)(lVar3 + 0x1e);
      uVar2 = 3;
      if (*(char *)(lVar3 + 0x1e) != '\x02') {
        uVar2 = 1;
      }
      *param_5 = uVar2;
    }
    else {
      uVar1 = 0;
      *param_2 = (uint)*(byte *)(lVar3 + 0x1e);
      uVar2 = 3;
      if (*(char *)(lVar3 + 0x1e) != '\x02') {
        uVar2 = 1;
      }
      *param_3 = uVar2;
    }
  }
  else {
    _printk(&DAT_001017af,"btfm_swr_dai_get_channel_map",param_6);
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// btfm_soc_status_get @ 00101244 size=20
// signature: undefined btfm_soc_status_get(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_soc_status_get(undefined8 param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) = (ulong)bt_soc_enable_status;
  return 1;
}



//------------------------------------------------------------
// btfm_soc_status_put @ 0010125c size=8
// signature: undefined btfm_soc_status_put(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_soc_status_put(void)

{
  return 1;
}



//------------------------------------------------------------
// btfm_get_feedback_ch_setting @ 00101268 size=20
// signature: undefined btfm_get_feedback_ch_setting(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_get_feedback_ch_setting(undefined8 param_1,long param_2)

{
  *(long *)(param_2 + 0x48) = (long)btfm_feedback_ch_setting;
  return 1;
}



//------------------------------------------------------------
// btfm_put_feedback_ch_setting @ 00101280 size=20
// signature: undefined btfm_put_feedback_ch_setting(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_put_feedback_ch_setting(undefined8 param_1,long param_2)

{
  btfm_feedback_ch_setting = (int)*(undefined8 *)(param_2 + 0x48);
  return 1;
}



//------------------------------------------------------------
// btfm_get_codec_type @ 00101298 size=20
// signature: undefined btfm_get_codec_type(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_get_codec_type(undefined8 param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) = (ulong)usecase_codec;
  return 1;
}



//------------------------------------------------------------
// btfm_put_codec_type @ 001012b0 size=20
// signature: undefined btfm_put_codec_type(void)
// callers: []
//------------------------------------------------------------

undefined8 btfm_put_codec_type(undefined8 param_1,long param_2)

{
  usecase_codec = (char)*(undefined8 *)(param_2 + 0x48);
  return 1;
}



//------------------------------------------------------------
// init_module @ 001012c8 size=56
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  _printk(&DAT_00101908,"btfm_swr_init");
  swr_driver_register(&btfm_swr_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101304 size=56
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  _printk(&DAT_00101908,"btfm_swr_exit");
  swr_driver_unregister(&btfm_swr_driver);
  return;
}



//------------------------------------------------------------
// _printk @ 00104000 size=1
// signature: undefined _printk(void)
// callers: [btfm_swr_disable_port, btfm_get_sampling_rate, btfm_swr_dai_prepare, btfm_swr_probe, btfm_swr_enable_port, btfm_swr_unregister_hwep, init_module, btfm_get_bt_soc_index, btfm_swr_register_hw_ep, btfm_swr_ioctl, btfm_swr_dai_get_configs, btfm_swr_hw_init, btfm_swr_dai_shutdown, btfm_swr_dai_get_channel_map, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// btpower_get_chipset_version @ 00104008 size=1
// signature: undefined btpower_get_chipset_version(void)
// callers: [btfm_swr_hw_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void btpower_get_chipset_version(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_get_logical_dev_num @ 00104010 size=1
// signature: undefined swr_get_logical_dev_num(void)
// callers: [btfm_swr_hw_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_get_logical_dev_num(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00104018 size=1
// signature: undefined usleep_range_state(void)
// callers: [btfm_swr_hw_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104020 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [btfm_swr_enable_port, btfm_swr_disable_port, btfm_swr_hw_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_connect_port @ 00104028 size=1
// signature: undefined swr_connect_port(void)
// callers: [btfm_swr_enable_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_connect_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_slvdev_datapath_control @ 00104030 size=1
// signature: undefined swr_slvdev_datapath_control(void)
// callers: [btfm_swr_enable_port, btfm_swr_disable_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_slvdev_datapath_control(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_disconnect_port @ 00104038 size=1
// signature: undefined swr_disconnect_port(void)
// callers: [btfm_swr_disable_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_disconnect_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_driver_register @ 00104040 size=1
// signature: undefined swr_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_driver_unregister @ 00104048 size=1
// signature: undefined swr_driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00104050 size=1
// signature: undefined devm_kmalloc(void)
// callers: [btfm_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __register_chrdev @ 00104058 size=1
// signature: undefined __register_chrdev(void)
// callers: [btfm_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __register_chrdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 00104060 size=1
// signature: undefined __class_create(void)
// callers: [btfm_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 00104068 size=1
// signature: undefined device_create(void)
// callers: [btfm_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 00104070 size=1
// signature: undefined class_destroy(void)
// callers: [btfm_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __unregister_chrdev @ 00104078 size=1
// signature: undefined __unregister_chrdev(void)
// callers: [btfm_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __unregister_chrdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00104080 size=1
// signature: undefined kfree(void)
// callers: [btfm_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00104090 size=1
// signature: undefined kmalloc_trace(void)
// callers: [btfm_swr_register_hw_ep]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00104098 size=1
// signature: undefined strscpy(void)
// callers: [btfm_swr_register_hw_ep]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// btfmcodec_register_hw_ep @ 001040a0 size=1
// signature: undefined btfmcodec_register_hw_ep(void)
// callers: [btfm_swr_register_hw_ep]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void btfmcodec_register_hw_ep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// btfmcodec_unregister_hw_ep @ 001040a8 size=1
// signature: undefined btfmcodec_unregister_hw_ep(void)
// callers: [btfm_swr_unregister_hwep]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void btfmcodec_unregister_hw_ep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



