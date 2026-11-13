// Decompiled by Ghidra 12.2
// Program: dcvs_fp.ko
// Image base: 00100000

//------------------------------------------------------------
// setup_ddrllcc_fp_device @ 0010016c size=148
// signature: undefined setup_ddrllcc_fp_device(void)
// callers: []
//------------------------------------------------------------

undefined8 setup_ddrllcc_fp_device(undefined8 param_1,long param_2,long param_3)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  undefined8 uVar4;
  
  if (*(uint *)(param_2 + 0x68) < 2) {
    mutex_lock(&ddrllcc_lock);
    lVar3 = ddrllcc_data;
    if (ddrllcc_data == 0) {
      uVar4 = 0xfffffdfb;
    }
    else {
      plVar1 = (long *)(ddrllcc_data + 0x10);
      *(long *)(param_3 + 0x78) = ddrllcc_data;
      *(code **)(param_3 + 0x80) = ddrllcc_fp_commit;
      uVar4 = 0;
      plVar2 = (long *)(lVar3 + 8);
      if (*(int *)(param_2 + 0x68) != 0) {
        plVar2 = plVar1;
      }
      *plVar2 = param_3;
    }
    mutex_unlock(&ddrllcc_lock);
  }
  else {
    uVar4 = 0xffffffea;
  }
  return uVar4;
}



//------------------------------------------------------------
// ddrllcc_fp_commit @ 00100204 size=216
// signature: undefined ddrllcc_fp_commit(void)
// callers: []
//------------------------------------------------------------

int ddrllcc_fp_commit(long param_1,int *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x78);
  uVar3 = *puVar4;
  if ((param_3 & 1) != 0) {
    uVar1 = 0;
    if (*(uint *)((long)puVar4 + 0x1c) != 0) {
      uVar1 = (uint)(*(int *)(puVar4 + 4) * *param_2) / *(uint *)((long)puVar4 + 0x1c);
    }
    *(uint *)((long)puVar4 + 0x3c) = uVar1 & 0x3fff | 0x60000000;
  }
  if ((param_3 >> 1 & 1) != 0) {
    uVar1 = 0;
    if (*(uint *)((long)puVar4 + 0x2c) != 0) {
      uVar1 = (uint)(*(int *)(puVar4 + 6) * param_2[3]) / *(uint *)((long)puVar4 + 0x2c);
    }
    *(uint *)(puVar4 + 9) = uVar1 & 0x3fff | 0x60000000;
  }
  iVar2 = rpmh_update_fast_path(uVar3,puVar4 + 7,2,param_3);
  if (iVar2 < 0) {
    _dev_err(uVar3,"Error updating RPMH fast path: %d\n",iVar2);
  }
  else {
    if ((param_3 & 1) != 0) {
      *(int *)(puVar4[1] + 0x18) = *param_2;
    }
    if ((param_3 >> 1 & 1) != 0) {
      *(int *)(puVar4[2] + 0x18) = param_2[3];
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// qcom_dcvs_fp_probe @ 001002e0 size=440
// signature: undefined qcom_dcvs_fp_probe(void)
// callers: []
//------------------------------------------------------------

int qcom_dcvs_fp_probe(long param_1)

{
  int iVar1;
  long *plVar2;
  char *pcVar3;
  long *plVar4;
  
  param_1 = param_1 + 0x10;
  mutex_lock(&ddrllcc_lock);
  if (ddrllcc_data == (long *)0x0) {
    plVar2 = (long *)devm_kmalloc(param_1,0x50,0xdc0);
    if (plVar2 == (long *)0x0) {
      iVar1 = -0xc;
    }
    else {
      *plVar2 = param_1;
      iVar1 = populate_bcm_data(param_1,plVar2 + 3,"qcom,ddr-bcm-name");
      if (iVar1 < 0) {
        pcVar3 = "qcom,ddr-bcm-name";
      }
      else {
        iVar1 = populate_bcm_data(param_1,plVar2 + 5,"qcom,llcc-bcm-name");
        if (-1 < iVar1) {
          plVar4 = plVar2 + 7;
          *(int *)plVar4 = (int)plVar2[3];
          *(undefined8 *)((long)plVar2 + 0x3c) = 0x60000000;
          plVar2[9] = 0x60000000;
          *(int *)((long)plVar2 + 0x44) = (int)plVar2[5];
          iVar1 = rpmh_init_fast_path(param_1,plVar4,2);
          if (iVar1 < 0) {
            pcVar3 = "Error initializing rpmh fast path: %d\n";
          }
          else {
            iVar1 = rpmh_write_async(param_1,0,plVar4,2);
            if (iVar1 < 0) {
              pcVar3 = "Error initing dcvs_fp sleep vote: %d\n";
            }
            else {
              *(undefined4 *)((long)plVar2 + 0x3c) = 0x60000001;
              *(undefined4 *)(plVar2 + 9) = 0x60000001;
              iVar1 = rpmh_write_async(param_1,1,plVar4,2);
              if (-1 < iVar1) {
                ddrllcc_data = plVar2;
                goto LAB_001003e4;
              }
              pcVar3 = "Error initing dcvs_fp wake vote: %d\n";
            }
          }
          _dev_err(param_1,pcVar3,iVar1);
          goto LAB_001003e4;
        }
        pcVar3 = "qcom,llcc-bcm-name";
      }
      _dev_err(param_1,"Error importing %s bcm data: %d\n",pcVar3,iVar1);
    }
  }
  else {
    _dev_err(param_1,"Only one fast path client allowed\n");
    iVar1 = -0x16;
  }
LAB_001003e4:
  mutex_unlock(&ddrllcc_lock);
  return iVar1;
}



//------------------------------------------------------------
// populate_bcm_data @ 00100498 size=328
// signature: undefined populate_bcm_data(void)
// callers: [qcom_dcvs_fp_probe]
//------------------------------------------------------------

ulong populate_bcm_data(long param_1,int *param_2,undefined8 param_3)

{
  byte *pbVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  char *pcVar6;
  long local_48;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_48 = 0;
  local_40 = 0;
  uVar3 = of_property_read_string(*(undefined8 *)(param_1 + 0x2e8),param_3,&local_40);
  if ((int)uVar3 < 0) {
    puVar5 = (uint *)(ulong)uVar3;
    pcVar6 = "Error reading %s: %d\n";
  }
  else {
    iVar4 = cmd_db_read_addr(local_40);
    *param_2 = iVar4;
    if (iVar4 == 0) {
      _dev_err(param_1,"Error getting addr for: %s\n");
      puVar5 = (uint *)0xffffffea;
      goto LAB_00100544;
    }
    puVar5 = (uint *)cmd_db_read_aux_data(local_40,&local_48);
    if (puVar5 < (uint *)0xfffffffffffff001) {
      if (local_48 == 8) {
        param_2[1] = *puVar5 / 1000;
        param_2[2] = (uint)(ushort)puVar5[1];
        pbVar1 = (byte *)((long)puVar5 + 6);
        puVar5 = (uint *)0x0;
        param_2[3] = (uint)*pbVar1;
      }
      else {
        _dev_err(param_1,"Bad data len for %s: %d\n",local_40);
        puVar5 = (uint *)0xffffffea;
      }
      goto LAB_00100544;
    }
    pcVar6 = "Error reading %s aux data: %d\n";
    param_3 = local_40;
  }
  _dev_err(param_1,pcVar6,param_3,(ulong)puVar5 & 0xffffffff);
LAB_00100544:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)puVar5 & 0xffffffff;
}



//------------------------------------------------------------
// init_module @ 00100600 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_dcvs_fp_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100630 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_dcvs_fp_driver);
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00102000 size=1
// signature: undefined mutex_lock(void)
// callers: [qcom_dcvs_fp_probe, setup_ddrllcc_fp_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00102008 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcom_dcvs_fp_probe, setup_ddrllcc_fp_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmh_update_fast_path @ 00102010 size=1
// signature: undefined rpmh_update_fast_path(void)
// callers: [ddrllcc_fp_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmh_update_fast_path(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102018 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_dcvs_fp_probe, populate_bcm_data, ddrllcc_fp_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00102020 size=1
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
// platform_driver_unregister @ 00102028 size=1
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
// devm_kmalloc @ 00102030 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_dcvs_fp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmh_init_fast_path @ 00102038 size=1
// signature: undefined rpmh_init_fast_path(void)
// callers: [qcom_dcvs_fp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmh_init_fast_path(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmh_write_async @ 00102040 size=1
// signature: undefined rpmh_write_async(void)
// callers: [qcom_dcvs_fp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmh_write_async(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00102048 size=1
// signature: undefined of_property_read_string(void)
// callers: [populate_bcm_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cmd_db_read_addr @ 00102050 size=1
// signature: undefined cmd_db_read_addr(void)
// callers: [populate_bcm_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cmd_db_read_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cmd_db_read_aux_data @ 00102058 size=1
// signature: undefined cmd_db_read_aux_data(void)
// callers: [populate_bcm_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cmd_db_read_aux_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102060 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [populate_bcm_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



