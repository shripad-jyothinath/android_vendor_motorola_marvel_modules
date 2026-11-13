// Decompiled by Ghidra 12.2
// Program: qnoc-qos.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_icc_set_qos @ 0010012c size=248
// signature: undefined qcom_icc_set_qos(void)
// callers: []
//------------------------------------------------------------

void qcom_icc_set_qos(long param_1)

{
  uint *puVar1;
  uint uVar2;
  
  if (((*(long *)(param_1 + 0x188) != 0) &&
      (puVar1 = *(uint **)(param_1 + 400), puVar1 != (uint *)0x0)) && (*puVar1 != 0)) {
    uVar2 = 0;
    do {
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + 0x188),
                 puVar1[(long)(int)uVar2 + 8] + (uint)**(byte **)(puVar1 + 2),0x1000000,
                 (ulong)*(byte *)(*(long *)(puVar1 + 6) + 8) << 0x18,0,0,0);
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + 0x188),
                 puVar1[(long)(int)uVar2 + 8] + (uint)**(byte **)(puVar1 + 2),0x70,
                 **(int **)(puVar1 + 6) << 4,0,0,0);
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + 0x188),
                 puVar1[(long)(int)uVar2 + 8] + (uint)**(byte **)(puVar1 + 2),8,
                 *(int *)(*(long *)(puVar1 + 6) + 4) << 3,0,0,0);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *puVar1);
  }
  return;
}



//------------------------------------------------------------
// qcom_icc_set_qnoc2_qos @ 00100228 size=240
// signature: undefined qcom_icc_set_qnoc2_qos(void)
// callers: []
//------------------------------------------------------------

void qcom_icc_set_qnoc2_qos(long param_1)

{
  uint *puVar1;
  uint uVar2;
  
  if (((*(long *)(param_1 + 0x188) != 0) &&
      (puVar1 = *(uint **)(param_1 + 400), puVar1 != (uint *)0x0)) && (*puVar1 != 0)) {
    uVar2 = 0;
    do {
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + 0x188),
                 puVar1[(long)(int)uVar2 + 8] + (uint)**(byte **)(puVar1 + 2),0xc,
                 *(int *)(*(long *)(puVar1 + 6) + 0x10) << 2,0,0,0);
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + 0x188),
                 puVar1[(long)(int)uVar2 + 8] + (uint)**(byte **)(puVar1 + 2),3,
                 *(undefined4 *)(*(long *)(puVar1 + 6) + 0xc),0,0,0);
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + 0x188),
                 puVar1[(long)(int)uVar2 + 8] + (uint)*(byte *)(*(long *)(puVar1 + 2) + 1),3,
                 *(undefined4 *)(*(long *)(puVar1 + 6) + 0x14),0,0,0);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *puVar1);
  }
  return;
}



//------------------------------------------------------------
// qcom_icc_set_bimc_qos @ 0010031c size=360
// signature: undefined qcom_icc_set_bimc_qos(void)
// callers: []
//------------------------------------------------------------

void qcom_icc_set_bimc_qos(long param_1)

{
  uint *puVar1;
  uint uVar2;
  
  if (((*(long *)(param_1 + 0x188) != 0) &&
      (puVar1 = *(uint **)(param_1 + 400), puVar1 != (uint *)0x0)) && (*puVar1 != 0)) {
    uVar2 = 0;
    do {
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + 0x188),
                 puVar1[(long)(int)uVar2 + 8] + (uint)**(byte **)(puVar1 + 2),0x707,
                 **(uint **)(puVar1 + 6) | **(uint **)(puVar1 + 6) << 8,0,0,0);
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + 0x188),
                 puVar1[(long)(int)uVar2 + 8] + (uint)**(byte **)(puVar1 + 2) + 4,0x707,
                 **(uint **)(puVar1 + 6) | **(uint **)(puVar1 + 6) << 8,0,0,0);
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + 0x188),
                 puVar1[(long)(int)uVar2 + 8] + (uint)**(byte **)(puVar1 + 2) + 8,0x707,
                 **(uint **)(puVar1 + 6) | **(uint **)(puVar1 + 6) << 8,0,0,0);
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + 0x188),
                 puVar1[(long)(int)uVar2 + 8] + (uint)**(byte **)(puVar1 + 2) + 0xc,0x707,
                 **(uint **)(puVar1 + 6) | **(uint **)(puVar1 + 6) << 8,0,0,0);
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + 0x188),
                 puVar1[(long)(int)uVar2 + 8] + (uint)*(byte *)(*(long *)(puVar1 + 2) + 1),1,
                 *(undefined4 *)(*(long *)(puVar1 + 6) + 0x18),0,0,0);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *puVar1);
  }
  return;
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00101000 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [qcom_icc_set_qos, qcom_icc_set_qnoc2_qos, qcom_icc_set_bimc_qos]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



