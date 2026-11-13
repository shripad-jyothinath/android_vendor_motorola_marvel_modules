// Decompiled by Ghidra 12.2
// Program: qti-glink-adc.ko
// Image base: 00100000

//------------------------------------------------------------
// glink_adc_probe @ 001001a4 size=836
// signature: undefined glink_adc_probe(void)
// callers: []
//------------------------------------------------------------

ulong glink_adc_probe(undefined8 *param_1)

{
  undefined8 *puVar1;
  code *pcVar2;
  uint uVar3;
  undefined4 *puVar4;
  ulong uVar5;
  long lVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined8 *puVar9;
  ulong *puVar10;
  undefined *local_98;
  undefined8 local_90;
  ulong *local_88;
  code *local_80;
  undefined8 uStack_78;
  uint local_6c;
  long local_68;
  
  lVar6 = sp_el0;
  puVar1 = param_1 + 2;
  local_68 = *(long *)(lVar6 + 0x638);
  local_80 = (code *)0x0;
  uStack_78 = 0;
  local_90 = 0;
  local_88 = (ulong *)0x0;
  puVar4 = (undefined4 *)devm_iio_device_alloc(puVar1,0x90);
  if (puVar4 != (undefined4 *)0x0) {
    puVar10 = *(ulong **)(puVar4 + 0x110);
    puVar10[1] = (ulong)puVar1;
    __mutex_init(puVar10 + 2,"&adc->lock",&glink_adc_probe___key);
    *(undefined4 *)(puVar10 + 8) = 0;
    __init_swait_queue_head(puVar10 + 9,"&x->wait",&init_completion___key);
    param_1[0x15] = puVar10;
    local_90 = CONCAT44(local_90._4_4_,0x8010);
    local_80 = glink_adc_callback;
    local_98 = &DAT_00100f67;
    local_88 = puVar10;
    uVar3 = device_get_child_node_count(puVar10[1]);
    *(uint *)(puVar10 + 0xd) = uVar3;
    if (uVar3 == 0) {
      uVar5 = 0xffffffea;
      goto LAB_00100408;
    }
    uVar5 = devm_kmalloc(puVar10[1],(ulong)uVar3 * 0x98,0xdc0);
    puVar10[0xc] = uVar5;
    if (uVar5 != 0) {
      lVar6 = device_get_next_child_node(puVar10[1],0);
      if (lVar6 != 0) {
        puVar9 = (undefined8 *)(uVar5 + 0x88);
        do {
          local_6c = 0;
          uVar3 = fwnode_property_read_u32_array(lVar6,&DAT_00100ed1,&local_6c,1);
          if ((int)uVar3 < 0) {
            uVar5 = (ulong)uVar3;
            uVar8 = puVar10[1];
            uVar7 = fwnode_get_name(lVar6);
            _dev_err(uVar8,"missing channel number %s, ret=%d\n",uVar7,uVar5);
LAB_00100498:
            fwnode_handle_put(lVar6);
            goto LAB_00100408;
          }
          uVar5 = (ulong)local_6c & 0xff;
          if ((int)uVar5 - 4U < 0xfffffffd) {
            uVar8 = puVar10[1];
            uVar7 = fwnode_get_name(lVar6);
            _dev_err(uVar8,"%s invalid channel number %u\n",uVar7,uVar5);
            uVar5 = 0xffffffea;
            goto LAB_00100498;
          }
          *(uint *)((long)puVar9 + -0x84) = local_6c;
          if (((0x260 < uVar5 * 0x98) || ((int)uVar5 == 4)) ||
             (*(undefined4 *)(puVar9 + -0x11) = *(undefined4 *)(glink_adc_channels + uVar5 * 0x98),
             0x1d8 < uVar5 * 0x98)) {
LAB_001004e0:
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(1,0x1004e4);
            (*pcVar2)();
          }
          *puVar9 = *(undefined8 *)(glink_adc_channels + uVar5 * 0x98 + 0x88);
          fwnode_property_read_string(lVar6,"label",puVar9);
          puVar9[-1] = *puVar9;
          if (0x238 < uVar5 * 0x98) goto LAB_001004e0;
          puVar9[-0xc] = *(undefined8 *)(glink_adc_channels + uVar5 * 0x98 + 0x28);
          lVar6 = device_get_next_child_node(puVar10[1],lVar6);
          puVar9 = puVar9 + 0x13;
        } while (lVar6 != 0);
      }
      uVar5 = pmic_glink_register_client(puVar1,&local_98);
      *puVar10 = uVar5;
      if (uVar5 < 0xfffffffffffff001) {
        *(undefined8 **)(puVar4 + 0x1a) = puVar1;
        *(undefined8 *)(puVar4 + 0xbc) = param_1[0x5f];
        uVar7 = *param_1;
        *(undefined1 **)(puVar4 + 0x10c) = glink_adc_info;
        *puVar4 = 1;
        *(undefined8 *)(puVar4 + 0x108) = uVar7;
        *(ulong *)(puVar4 + 0x104) = puVar10[0xc];
        puVar4[0x106] = (int)puVar10[0xd];
        uVar5 = __devm_iio_device_register(puVar1,puVar4,&__this_module);
        if ((int)uVar5 < 0) {
          uVar5 = uVar5 & 0xffffffff;
          _dev_err(puVar1,"iio device registration failed, ret=%d\n",uVar5);
          pmic_glink_unregister_client(*puVar10);
        }
        else {
          uVar5 = 0;
        }
      }
      else if ((int)uVar5 == -0x205) {
        uVar5 = 0xfffffdfb;
      }
      else {
        _dev_err(puVar1,"Error registering glink ADC, ret=%d\n",uVar5 & 0xffffffff);
      }
      goto LAB_00100408;
    }
  }
  uVar5 = 0xfffffff4;
LAB_00100408:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5 & 0xffffffff;
}



//------------------------------------------------------------
// glink_adc_remove @ 001004ec size=40
// signature: undefined glink_adc_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 glink_adc_remove(long param_1)

{
  pmic_glink_unregister_client(**(undefined8 **)(param_1 + 0xa8));
  return 0;
}



//------------------------------------------------------------
// glink_adc_callback @ 00100518 size=140
// signature: undefined glink_adc_callback(void)
// callers: []
//------------------------------------------------------------

undefined8 glink_adc_callback(long param_1,undefined8 *param_2,long param_3)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  if (*(int *)(param_2 + 1) == 0x49) {
    if (param_3 == 0x24) {
      *(undefined8 *)(param_1 + 0x6c) = *param_2;
      uVar1 = param_2[3];
      uVar2 = *(undefined4 *)(param_2 + 4);
      uVar3 = param_2[1];
      *(undefined8 *)(param_1 + 0x7c) = param_2[2];
      *(undefined4 *)(param_1 + 0x8c) = uVar2;
      *(undefined8 *)(param_1 + 0x84) = uVar1;
      *(undefined8 *)(param_1 + 0x74) = uVar3;
      complete(param_1 + 0x40);
    }
    else {
      _dev_err(*(undefined8 *)(param_1 + 8),"Invalid read response, glink packet size=%zu\n");
    }
  }
  else {
    _dev_err(*(undefined8 *)(param_1 + 8),"Unknown opcode %u\n",*(int *)(param_2 + 1));
  }
  return 0;
}



//------------------------------------------------------------
// glink_adc_read_raw @ 001005a8 size=80
// signature: undefined glink_adc_read_raw(void)
// callers: []
//------------------------------------------------------------

int glink_adc_read_raw(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                      long param_5)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_5 == 0) {
    uVar2 = 0;
  }
  else {
    if (param_5 != 1) {
      return -0x16;
    }
    uVar2 = param_3;
    param_3 = 0;
  }
  iVar1 = glink_adc_read_channel(*(undefined8 *)(param_1 + 0x440),param_2,uVar2,param_3);
  if (-1 < iVar1) {
    iVar1 = 1;
  }
  return iVar1;
}



//------------------------------------------------------------
// glink_adc_fwnode_xlate @ 001005fc size=68
// signature: undefined glink_adc_fwnode_xlate(void)
// callers: []
//------------------------------------------------------------

ulong glink_adc_fwnode_xlate(long param_1,long param_2)

{
  ulong uVar1;
  int *piVar2;
  
  if (0 < (int)*(uint *)(param_1 + 0x418)) {
    uVar1 = 0;
    piVar2 = (int *)(*(long *)(param_1 + 0x410) + 4);
    do {
      if (*(long *)(param_2 + 0x10) == (long)*piVar2) {
        return uVar1;
      }
      uVar1 = uVar1 + 1;
      piVar2 = piVar2 + 0x26;
    } while (*(uint *)(param_1 + 0x418) != uVar1);
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// glink_adc_read_channel @ 00100640 size=316
// signature: undefined glink_adc_read_channel(void)
// callers: [glink_adc_read_raw]
//------------------------------------------------------------

int glink_adc_read_channel(undefined8 *param_1,long param_2,undefined4 *param_3,undefined4 *param_4)

{
  long lVar1;
  int iVar2;
  undefined8 local_60;
  undefined4 local_58;
  uint uStack_54;
  uint local_50;
  uint uStack_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  uStack_4c = *(uint *)(param_2 + 4);
  local_60 = 0x100008010;
  uStack_54 = uStack_4c >> 0x10;
  local_50 = uStack_4c >> 8 & 0xff;
  uStack_4c = uStack_4c & 0xff;
  local_58 = 0x49;
  mutex_lock(param_1 + 2);
  *(undefined4 *)(param_1 + 8) = 0;
  iVar2 = pmic_glink_write(*param_1,&local_60,0x18);
  if (iVar2 == 0) {
    iVar2 = wait_for_completion_timeout(param_1 + 8,0xfa);
    if (iVar2 == 0) {
      _dev_err(param_1[1],"Error, ADC conversion timed out\n");
      iVar2 = -0x6e;
    }
    else if (*(int *)((long)param_1 + 0x8c) == 0) {
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = *(undefined4 *)(param_1 + 0x11);
      }
      if (param_4 == (undefined4 *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = 0;
        *param_4 = *(undefined4 *)((long)param_1 + 0x84);
      }
    }
    else {
      _dev_err(param_1[1],"glink ADC read failed, bus_id=%u, pmic_id=%u, chan=%u, ret=%u\n",
               *(undefined4 *)(param_1 + 0xf),*(undefined4 *)((long)param_1 + 0x7c),
               *(undefined4 *)(param_1 + 0x10));
      iVar2 = -5;
    }
  }
  mutex_unlock(param_1 + 2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// init_module @ 00100780 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&glink_adc_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001007b0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&glink_adc_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00102000 size=1
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
// platform_driver_unregister @ 00102008 size=1
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
// devm_iio_device_alloc @ 00102010 size=1
// signature: undefined devm_iio_device_alloc(void)
// callers: [glink_adc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_iio_device_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00102018 size=1
// signature: undefined __mutex_init(void)
// callers: [glink_adc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00102020 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [glink_adc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_get_child_node_count @ 00102028 size=1
// signature: undefined device_get_child_node_count(void)
// callers: [glink_adc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_get_child_node_count(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102030 size=1
// signature: undefined devm_kmalloc(void)
// callers: [glink_adc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_get_next_child_node @ 00102038 size=1
// signature: undefined device_get_next_child_node(void)
// callers: [glink_adc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_get_next_child_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fwnode_property_read_u32_array @ 00102040 size=1
// signature: undefined fwnode_property_read_u32_array(void)
// callers: [glink_adc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fwnode_property_read_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fwnode_property_read_string @ 00102048 size=1
// signature: undefined fwnode_property_read_string(void)
// callers: [glink_adc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fwnode_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_register_client @ 00102050 size=1
// signature: undefined pmic_glink_register_client(void)
// callers: [glink_adc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_register_client(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_iio_device_register @ 00102058 size=1
// signature: undefined __devm_iio_device_register(void)
// callers: [glink_adc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_iio_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fwnode_get_name @ 00102060 size=1
// signature: undefined fwnode_get_name(void)
// callers: [glink_adc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fwnode_get_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102068 size=1
// signature: undefined _dev_err(void)
// callers: [glink_adc_probe, glink_adc_callback, glink_adc_read_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fwnode_handle_put @ 00102070 size=1
// signature: undefined fwnode_handle_put(void)
// callers: [glink_adc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fwnode_handle_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_unregister_client @ 00102078 size=1
// signature: undefined pmic_glink_unregister_client(void)
// callers: [glink_adc_probe, glink_adc_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_unregister_client(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102080 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [glink_adc_probe, glink_adc_read_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00102088 size=1
// signature: undefined complete(void)
// callers: [glink_adc_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00102090 size=1
// signature: undefined mutex_lock(void)
// callers: [glink_adc_read_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_write @ 00102098 size=1
// signature: undefined pmic_glink_write(void)
// callers: [glink_adc_read_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 001020a0 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [glink_adc_read_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001020a8 size=1
// signature: undefined mutex_unlock(void)
// callers: [glink_adc_read_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



