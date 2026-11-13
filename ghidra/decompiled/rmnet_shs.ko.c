// Decompiled by Ghidra 12.2
// Program: rmnet_shs.ko
// Image base: 00100000

//------------------------------------------------------------
// DATARMNET4095253347 @ 00103b4c size=104
// signature: undefined DATARMNET4095253347(void)
// callers: [DATARMNET7492293980]
//------------------------------------------------------------

void DATARMNET4095253347(long param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  ulong uVar3;
  
  puVar2 = DATARMNET30a3e83974;
  puVar1 = (undefined *)(param_1 + 0x10);
  uVar3 = __list_add_valid(puVar1,&DATARMNET30a3e83974,DATARMNET30a3e83974);
  if ((uVar3 & 1) != 0) {
    *(undefined **)(puVar2 + 8) = puVar1;
    *(undefined **)(param_1 + 0x10) = puVar2;
    *(undefined ***)(param_1 + 0x18) = &DATARMNET30a3e83974;
    DATARMNET30a3e83974 = puVar1;
  }
  return;
}



//------------------------------------------------------------
// DATARMNETf7d317ed55 @ 00103c3c size=84
// signature: undefined DATARMNETf7d317ed55(void)
// callers: [DATARMNETd6ee05f1b4, DATARMNET5fb4151598]
//------------------------------------------------------------

void DATARMNETf7d317ed55(long param_1)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  
  lVar1 = param_1 + 0x10;
  uVar4 = __list_del_entry_valid(lVar1);
  if ((uVar4 & 1) != 0) {
    lVar2 = *(long *)(param_1 + 0x10);
    plVar3 = *(long **)(param_1 + 0x18);
    *(long **)(lVar2 + 8) = plVar3;
    *plVar3 = lVar2;
  }
  *(long *)(param_1 + 0x10) = lVar1;
  *(long *)(param_1 + 0x18) = lVar1;
  return;
}



//------------------------------------------------------------
// DATARMNET36e5e526fa @ 00103d18 size=128
// signature: undefined DATARMNET36e5e526fa(void)
// callers: [DATARMNETf5b8fce55d, DATARMNET3ae0d614d6, DATARMNETb062995420]
//------------------------------------------------------------

void DATARMNET36e5e526fa(long param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  ulong uVar3;
  
  _raw_spin_lock_bh(&DATARMNETfbdbab2ef6);
  puVar2 = DATARMNET9825511866;
  puVar1 = (undefined *)(param_1 + 0x50);
  uVar3 = __list_add_valid(puVar1,&DATARMNET9825511866,DATARMNET9825511866);
  if ((uVar3 & 1) != 0) {
    *(undefined **)(param_1 + 0x50) = puVar2;
    *(undefined ***)(param_1 + 0x58) = &DATARMNET9825511866;
    DATARMNET9825511866 = puVar1;
    *(undefined **)(puVar2 + 8) = puVar1;
  }
  _raw_spin_unlock_bh(&DATARMNETfbdbab2ef6);
  return;
}



//------------------------------------------------------------
// DATARMNET2fe780019f @ 00103e20 size=108
// signature: undefined DATARMNET2fe780019f(void)
// callers: [DATARMNET39391a8bc5]
//------------------------------------------------------------

void DATARMNET2fe780019f(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  
  _raw_spin_lock_bh(&DATARMNETfbdbab2ef6);
  uVar3 = __list_del_entry_valid(param_1 + 0x50);
  if ((uVar3 & 1) != 0) {
    lVar1 = *(long *)(param_1 + 0x50);
    plVar2 = *(long **)(param_1 + 0x58);
    *(long **)(lVar1 + 8) = plVar2;
    *plVar2 = lVar1;
  }
  *(undefined8 *)(param_1 + 0x58) = 0xdead000000000122;
  _raw_spin_unlock_bh(&DATARMNETfbdbab2ef6);
  return;
}



//------------------------------------------------------------
// DATARMNETb4a6870b3b @ 00103f14 size=108
// signature: undefined DATARMNETb4a6870b3b(void)
// callers: [DATARMNET39391a8bc5]
//------------------------------------------------------------

void DATARMNETb4a6870b3b(long param_1)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  
  _raw_spin_lock_bh(&DATARMNETfbdbab2ef6);
  lVar1 = param_1 + 0x40;
  uVar4 = __list_del_entry_valid(lVar1);
  if ((uVar4 & 1) != 0) {
    lVar2 = *(long *)(param_1 + 0x40);
    plVar3 = *(long **)(param_1 + 0x48);
    *(long **)(lVar2 + 8) = plVar3;
    *plVar3 = lVar2;
  }
  *(long *)(param_1 + 0x40) = lVar1;
  *(long *)(param_1 + 0x48) = lVar1;
  _raw_spin_unlock_bh(&DATARMNETfbdbab2ef6);
  return;
}



//------------------------------------------------------------
// DATARMNETd8a6375e9c @ 00104008 size=124
// signature: undefined DATARMNETd8a6375e9c(void)
// callers: [DATARMNET5b2ed86112]
//------------------------------------------------------------

void DATARMNETd8a6375e9c(long param_1,long *param_2)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  _raw_spin_lock_bh(&DATARMNETfbdbab2ef6);
  lVar3 = *param_2;
  lVar1 = param_1 + 0x40;
  uVar2 = __list_add_valid(lVar1,param_2,lVar3);
  if ((uVar2 & 1) != 0) {
    *(long *)(lVar3 + 8) = lVar1;
    *(long *)(param_1 + 0x40) = lVar3;
    *(long **)(param_1 + 0x48) = param_2;
    *param_2 = lVar1;
  }
  _raw_spin_unlock_bh(&DATARMNETfbdbab2ef6);
  return;
}



//------------------------------------------------------------
// DATARMNET9914e9761e @ 0010410c size=152
// signature: undefined DATARMNET9914e9761e(void)
// callers: [DATARMNET5b2ed86112]
//------------------------------------------------------------

void DATARMNET9914e9761e(long param_1,long *param_2,undefined8 param_3)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  long lVar4;
  
  _raw_spin_lock_bh(&DATARMNETfbdbab2ef6,param_2,param_3,*(undefined2 *)(param_1 + 0x136));
  lVar1 = param_1 + 0x40;
  uVar3 = __list_del_entry_valid(lVar1);
  if ((uVar3 & 1) != 0) {
    lVar4 = *(long *)(param_1 + 0x40);
    plVar2 = *(long **)(param_1 + 0x48);
    *(long **)(lVar4 + 8) = plVar2;
    *plVar2 = lVar4;
  }
  lVar4 = *param_2;
  uVar3 = __list_add_valid(lVar1,param_2,lVar4);
  if ((uVar3 & 1) != 0) {
    *(long *)(lVar4 + 8) = lVar1;
    *(long *)(param_1 + 0x40) = lVar4;
    *(long **)(param_1 + 0x48) = param_2;
    *param_2 = lVar1;
  }
  _raw_spin_unlock_bh(&DATARMNETfbdbab2ef6);
  return;
}



//------------------------------------------------------------
// DATARMNET6bf538fa23 @ 00104228 size=36
// signature: undefined DATARMNET6bf538fa23(void)
// callers: [DATARMNETf5f83b943f, DATARMNETe421c4e1db, DATARMNET59b415aded, DATARMNETcfbc4f0c39, DATARMNET794d7587bd, DATARMNET33a80d3bf7, DATARMNETfbd34e70a2, DATARMNET968bc5b80d, DATARMNET9efe8a3d18, DATARMNET601894f27b, DATARMNET1ab1f570f2, DATARMNETb3a7180954, DATARMNET28d33bd09f, DATARMNET57bcb932f3, DATARMNETe35719979c, DATARMNETb9d10d8cc0, DATARMNET0935e3beb9, DATARMNETd005aa7157, DATARMNET2a9f67714f, DATARMNET18464ea5e3]
//------------------------------------------------------------

void DATARMNET6bf538fa23(void)

{
  _raw_spin_lock_bh(&DATARMNETec2a4f5211);
  return;
}



//------------------------------------------------------------
// DATARMNETaea4c85748 @ 00104250 size=36
// signature: undefined DATARMNETaea4c85748(void)
// callers: [DATARMNETf5f83b943f, DATARMNETe421c4e1db, DATARMNET59b415aded, DATARMNETcfbc4f0c39, DATARMNET794d7587bd, DATARMNET33a80d3bf7, DATARMNETfbd34e70a2, DATARMNET968bc5b80d, DATARMNET9efe8a3d18, DATARMNET601894f27b, DATARMNET1ab1f570f2, DATARMNETb3a7180954, DATARMNET28d33bd09f, DATARMNET57bcb932f3, DATARMNETe35719979c, DATARMNETb9d10d8cc0, DATARMNET0935e3beb9, DATARMNETd005aa7157, DATARMNET2a9f67714f, DATARMNET18464ea5e3]
//------------------------------------------------------------

void DATARMNETaea4c85748(void)

{
  _raw_spin_unlock_bh(&DATARMNETec2a4f5211);
  return;
}



//------------------------------------------------------------
// DATARMNETe46c480d71 @ 00104278 size=228
// signature: undefined DATARMNETe46c480d71(void)
// callers: [DATARMNETcd6e26f0ad, DATARMNETe9173bbe0e]
//------------------------------------------------------------

void DATARMNETe46c480d71(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined **ppuVar4;
  
  if ((undefined **)DATARMNET30a3e83974 != &DATARMNET30a3e83974) {
    bVar2 = false;
    uVar3 = 0xff;
    ppuVar4 = (undefined **)DATARMNET30a3e83974;
    do {
      if (*(char *)((long)ppuVar4 + 0x5e) != '\0') {
        if (*(ushort *)((long)ppuVar4 + 0x5c) != 0) {
          bVar2 = true;
          uVar3 = uVar3 & *(ushort *)((long)ppuVar4 + 0x5c);
        }
      }
      ppuVar4 = (undefined **)*ppuVar4;
    } while (ppuVar4 != &DATARMNET30a3e83974);
    if (bVar2) {
      if (DATARMNETecc0627c70[0x670] == uVar3) {
        return;
      }
      iVar1 = (uVar3 & 1) + (uVar3 >> 7) + (uVar3 >> 1 & 1) + (uVar3 >> 2 & 1) + (uVar3 >> 3 & 1) +
              (uVar3 >> 4 & 1) + (uVar3 >> 5 & 1) + (uVar3 >> 6 & 1);
      DATARMNETecc0627c70[0x671] = (char)iVar1;
      DATARMNETecc0627c70[0x670] = (char)uVar3;
      _printk(&DAT_00114fe9,uVar3,iVar1);
      return;
    }
  }
  DATARMNETecc0627c70._1648_2_ = 0;
  return;
}



//------------------------------------------------------------
// DATARMNET310c3eb16e @ 00104360 size=68
// signature: undefined DATARMNET310c3eb16e(void)
// callers: [DATARMNET02fc8b29a0, DATARMNET45d8cdb224]
//------------------------------------------------------------

int DATARMNET310c3eb16e(uint param_1)

{
  return (param_1 & 1) + (param_1 >> 1 & 1) + (param_1 >> 2 & 1) + (param_1 >> 3 & 1) +
         (param_1 >> 4 & 1) + (param_1 >> 5 & 1) + (param_1 >> 6 & 1) + ((param_1 & 0x80) >> 7);
}



//------------------------------------------------------------
// DATARMNETde8ee16f92 @ 001043a8 size=108
// signature: undefined DATARMNETde8ee16f92(void)
// callers: [DATARMNET39391a8bc5, DATARMNETe377e0368d]
//------------------------------------------------------------

void DATARMNETde8ee16f92(long param_1)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  
  lVar1 = param_1 + 0x40;
  uVar4 = __list_del_entry_valid(lVar1);
  if ((uVar4 & 1) != 0) {
    lVar2 = *(long *)(param_1 + 0x40);
    plVar3 = *(long **)(param_1 + 0x48);
    *(long **)(lVar2 + 8) = plVar3;
    *plVar3 = lVar2;
  }
  *(long *)(param_1 + 0x40) = lVar1;
  *(long *)(param_1 + 0x48) = lVar1;
  DATARMNET349c3a0cab(*(undefined2 *)(param_1 + 0xce),0);
  return;
}



//------------------------------------------------------------
// DATARMNET3e37ad2816 @ 0010449c size=124
// signature: undefined DATARMNET3e37ad2816(void)
// callers: [DATARMNETf5821256ad, DATARMNETe377e0368d, DATARMNET756778f14f]
//------------------------------------------------------------

void DATARMNET3e37ad2816(long param_1,long *param_2)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  lVar3 = *param_2;
  lVar1 = param_1 + 0x40;
  uVar2 = __list_add_valid(lVar1,param_2,lVar3);
  if ((uVar2 & 1) != 0) {
    *(long *)(lVar3 + 8) = lVar1;
    *(long *)(param_1 + 0x40) = lVar3;
    *(long **)(param_1 + 0x48) = param_2;
    *param_2 = lVar1;
  }
  DATARMNET349c3a0cab(*(undefined2 *)(param_1 + 0xce),1);
  return;
}



//------------------------------------------------------------
// DATARMNETe102b3a798 @ 001045a0 size=172
// signature: undefined DATARMNETe102b3a798(void)
// callers: [DATARMNET756778f14f, DATARMNETe488c1c396]
//------------------------------------------------------------

void DATARMNETe102b3a798(long param_1,long *param_2,undefined4 param_3)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  long lVar4;
  
  lVar1 = param_1 + 0x40;
  uVar3 = __list_del_entry_valid(lVar1);
  if ((uVar3 & 1) != 0) {
    lVar4 = *(long *)(param_1 + 0x40);
    plVar2 = *(long **)(param_1 + 0x48);
    *(long **)(lVar4 + 8) = plVar2;
    *plVar2 = lVar4;
  }
  lVar4 = *param_2;
  uVar3 = __list_add_valid(lVar1,param_2,lVar4);
  if ((uVar3 & 1) != 0) {
    *(long *)(lVar4 + 8) = lVar1;
    *(long *)(param_1 + 0x40) = lVar4;
    *(long **)(param_1 + 0x48) = param_2;
    *param_2 = lVar1;
  }
  DATARMNET349c3a0cab(*(undefined2 *)(param_1 + 0xce),1);
  DATARMNET349c3a0cab(param_3,0);
  return;
}



//------------------------------------------------------------
// DATARMNET4bde88919f @ 001046d4 size=44
// signature: undefined DATARMNET4bde88919f(void)
// callers: [DATARMNETe488c1c396]
//------------------------------------------------------------

void DATARMNET4bde88919f(byte param_1,int param_2)

{
  if (param_1 < 8) {
    *(int *)(DATARMNET443cf5aaaf + (ulong)param_1 * 4) =
         *(int *)(DATARMNET443cf5aaaf + (ulong)param_1 * 4) + param_2;
  }
  return;
}



//------------------------------------------------------------
// DATARMNETfc888b4d3e @ 00104704 size=56
// signature: undefined DATARMNETfc888b4d3e(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETfc888b4d3e(ushort param_1)

{
  if (param_1 < 8) {
    return (&DATARMNET713717107f)[param_1];
  }
  DAT_0011daa0 = DAT_0011daa0 + 1;
  return 0;
}



//------------------------------------------------------------
// DATARMNET362b15f941 @ 00104740 size=24
// signature: undefined DATARMNET362b15f941(void)
// callers: [DATARMNETf5821256ad, DATARMNET9a7769cf21, DATARMNETe377e0368d, DATARMNET95736008d9, DATARMNET6af33ebb5b, DATARMNET02fc8b29a0, DATARMNET24e4475345, DATARMNET3c1fc10379, DATARMNETcd6e26f0ad, DATARMNETc54e431bbc]
//------------------------------------------------------------

uint DATARMNET362b15f941(uint param_1)

{
  return ~(uint)DATARMNETecc0627c70[0x689] >> (ulong)(param_1 & 0x1f) & 1;
}



//------------------------------------------------------------
// DATARMNETadb0248bd4 @ 0010475c size=104
// signature: undefined DATARMNETadb0248bd4(void)
// callers: [DATARMNET756778f14f, DATARMNETe488c1c396, DATARMNETcd6e26f0ad]
//------------------------------------------------------------

undefined4 DATARMNETadb0248bd4(byte param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 8) {
    uVar1 = (&DAT_0011cb38)[(ulong)param_1 * 10];
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// DATARMNETeb3978575d @ 00104854 size=104
// signature: undefined DATARMNETeb3978575d(void)
// callers: [DATARMNETe377e0368d, DATARMNET02fc8b29a0, DATARMNETfbc06e60f1]
//------------------------------------------------------------

undefined4 DATARMNETeb3978575d(byte param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 8) {
    uVar1 = (&DAT_0011cb3c)[(ulong)param_1 * 10];
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// DATARMNETeea3cef5b6 @ 0010494c size=104
// signature: undefined DATARMNETeea3cef5b6(void)
// callers: [DATARMNETe377e0368d, DATARMNETe488c1c396, DATARMNETc54e431bbc]
//------------------------------------------------------------

undefined4 DATARMNETeea3cef5b6(byte param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 8) {
    uVar1 = *(undefined4 *)(&DAT_0011cb40 + (ulong)param_1 * 0x28);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// DATARMNET4e292977da @ 00104a44 size=44
// signature: undefined DATARMNET4e292977da(void)
// callers: []
//------------------------------------------------------------

ulong DATARMNET4e292977da(undefined8 param_1,long param_2,long param_3)

{
  ulong uVar1;
  
  uVar1 = 0;
  if ((param_2 != 0) && (param_3 != 0)) {
    if (*(ulong *)(param_3 + 0x58) < *(ulong *)(param_2 + 0x58)) {
      return 0xffffffff;
    }
    uVar1 = (ulong)(*(ulong *)(param_2 + 0x58) < *(ulong *)(param_3 + 0x58));
  }
  return uVar1;
}



//------------------------------------------------------------
// DATARMNET3c489db64a @ 00104a74 size=44
// signature: undefined DATARMNET3c489db64a(void)
// callers: []
//------------------------------------------------------------

ulong DATARMNET3c489db64a(undefined8 param_1,long param_2,long param_3)

{
  ulong uVar1;
  
  uVar1 = 0;
  if ((param_2 != 0) && (param_3 != 0)) {
    if (*(ulong *)(param_3 + 0x58) < *(ulong *)(param_2 + 0x58)) {
      return 0xffffffff;
    }
    uVar1 = (ulong)(*(ulong *)(param_2 + 0x58) < *(ulong *)(param_3 + 0x58));
  }
  return uVar1;
}



//------------------------------------------------------------
// DATARMNETd5c15f1ff3 @ 00104aa4 size=44
// signature: undefined DATARMNETd5c15f1ff3(void)
// callers: []
//------------------------------------------------------------

ulong DATARMNETd5c15f1ff3(undefined8 param_1,long param_2,long param_3)

{
  ulong uVar1;
  
  uVar1 = 0;
  if ((param_2 != 0) && (param_3 != 0)) {
    if (*(ulong *)(param_3 + 0x18) < *(ulong *)(param_2 + 0x18)) {
      return 0xffffffff;
    }
    uVar1 = (ulong)(*(ulong *)(param_2 + 0x18) < *(ulong *)(param_3 + 0x18));
  }
  return uVar1;
}



//------------------------------------------------------------
// DATARMNET85af86a36d @ 00104ad4 size=44
// signature: undefined DATARMNET85af86a36d(void)
// callers: []
//------------------------------------------------------------

ulong DATARMNET85af86a36d(undefined8 param_1,long param_2,long param_3)

{
  ulong uVar1;
  
  uVar1 = 0;
  if ((param_2 != 0) && (param_3 != 0)) {
    if (*(ulong *)(param_3 + 0x18) < *(ulong *)(param_2 + 0x18)) {
      return 0xffffffff;
    }
    uVar1 = (ulong)(*(ulong *)(param_2 + 0x18) < *(ulong *)(param_3 + 0x18));
  }
  return uVar1;
}



//------------------------------------------------------------
// DATARMNETf181a18009 @ 00104b04 size=288
// signature: undefined DATARMNETf181a18009(void)
// callers: [DATARMNET217fe38119]
//------------------------------------------------------------

int DATARMNETf181a18009(undefined *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  undefined **ppuVar5;
  ulong uVar6;
  uint uVar7;
  int iVar8;
  
  if (param_1 == (undefined *)0x0) {
    DATARMNET68d84e7b98 = DATARMNET68d84e7b98 + 1;
    return -1;
  }
  _raw_spin_lock_bh(&DATARMNETec2a4f5211);
  ppuVar5 = (undefined **)DATARMNET30a3e83974;
  while( true ) {
    if (ppuVar5 == &DATARMNET30a3e83974) {
      DAT_0011da78 = DAT_0011da78 + 1;
      _raw_spin_unlock_bh(&DATARMNETec2a4f5211);
      return -1;
    }
    if ((*(char *)((long)ppuVar5 + 0x5e) != '\0') && (ppuVar5[2] == param_1)) break;
    ppuVar5 = (undefined **)*ppuVar5;
  }
  uVar1 = *(uint *)(ppuVar5 + 0xd);
  uVar2 = *(uint *)(ppuVar5 + 0xc);
  if ((uVar2 & 0xff) < (uint)((ulong)uVar1 & 0xff)) {
    uVar7 = uVar2 & 0xff;
    uVar6 = (ulong)uVar2 & 0xff;
    if (uVar7 < 9) {
      uVar7 = 8;
    }
    do {
      if (uVar7 == uVar6) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x104c24);
        (*pcVar4)();
      }
      iVar8 = *(int *)((long)ppuVar5 + uVar6 * 4 + 0x18);
      if (-1 < iVar8) goto LAB_00104bf4;
      uVar6 = uVar6 + 1;
    } while (uVar6 < ((ulong)uVar1 & 0xff));
  }
  iVar8 = -1;
  if ((int)uVar1 <= (int)(uVar2 + 1)) {
LAB_00104bf4:
    iVar3 = 0;
    if (uVar1 != 0) {
      iVar3 = (int)(uVar2 + 1) / (int)uVar1;
    }
    *(uint *)(ppuVar5 + 0xc) = (uVar2 + 1) - iVar3 * uVar1;
  }
  _raw_spin_unlock_bh(&DATARMNETec2a4f5211);
  return iVar8;
}



//------------------------------------------------------------
// DATARMNET98b2a0ce62 @ 00104c28 size=268
// signature: undefined DATARMNET98b2a0ce62(void)
// callers: [DATARMNET217fe38119]
//------------------------------------------------------------

int DATARMNET98b2a0ce62(undefined *param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  code *pcVar4;
  undefined **ppuVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  int iVar9;
  
  if (param_1 == (undefined *)0x0) {
    DATARMNET68d84e7b98 = DATARMNET68d84e7b98 + 1;
    return -1;
  }
  _raw_spin_lock_bh(&DATARMNETec2a4f5211);
  ppuVar5 = (undefined **)DATARMNET30a3e83974;
  while( true ) {
    if (ppuVar5 == &DATARMNET30a3e83974) {
      DAT_0011da78 = DAT_0011da78 + 1;
      _raw_spin_unlock_bh(&DATARMNETec2a4f5211);
      return -1;
    }
    if ((*(char *)((long)ppuVar5 + 0x5e) != '\0') && (ppuVar5[2] == param_1)) break;
    ppuVar5 = (undefined **)*ppuVar5;
  }
  bVar1 = *(byte *)((long)ppuVar5 + 100);
  uVar8 = (ulong)bVar1;
  bVar2 = *(byte *)((long)ppuVar5 + 0x6c);
  if (bVar1 < bVar2) {
    uVar7 = (uint)bVar1;
    if (uVar7 < 9) {
      uVar7 = 8;
    }
    do {
      if (uVar7 == uVar8) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x104d34);
        (*pcVar4)();
      }
      iVar9 = *(int *)((long)ppuVar5 + uVar8 * 4 + 0x38);
      if (-1 < iVar9) {
        uVar7 = ((uint)uVar8 & 0xff) + 1;
        uVar3 = 0;
        uVar6 = (uint)bVar2;
        if (uVar6 != 0) {
          uVar3 = uVar7 / uVar6;
        }
        *(uint *)((long)ppuVar5 + 100) = uVar7 - uVar3 * uVar6;
        goto LAB_00104d10;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < bVar2);
  }
  iVar9 = -1;
LAB_00104d10:
  _raw_spin_unlock_bh(&DATARMNETec2a4f5211);
  return iVar9;
}



//------------------------------------------------------------
// DATARMNET7f1d9480cb @ 00104d38 size=28
// signature: undefined DATARMNET7f1d9480cb(void)
// callers: []
//------------------------------------------------------------

void DATARMNET7f1d9480cb(void)

{
  DATARMNET4063c95208();
  return;
}



//------------------------------------------------------------
// DATARMNETa4bd2ef52c @ 00104d58 size=28
// signature: undefined DATARMNETa4bd2ef52c(void)
// callers: []
//------------------------------------------------------------

void DATARMNETa4bd2ef52c(void)

{
  DATARMNET7b6c061b06();
  return;
}



//------------------------------------------------------------
// DATARMNET928c931df9 @ 00104d78 size=188
// signature: undefined DATARMNET928c931df9(void)
// callers: [DATARMNET45d8cdb224]
//------------------------------------------------------------

uint DATARMNET928c931df9(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar3 = *param_1;
  uVar6 = 0;
  if (uVar3 == 0) {
    return 0;
  }
  uVar4 = 0;
  if (uVar3 != 1) {
    uVar6 = 0;
    if ((-uVar3 & 0xff) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0;
      if (uVar3 - 1 < 0x100) {
        uVar7 = 0;
        uVar5 = 0;
        uVar4 = 0;
        uVar6 = uVar3 & 0xfffffffe;
        do {
          uVar2 = uVar7 & 0xfe;
          uVar7 = uVar7 + 2;
          uVar5 = uVar5 | 1 << (ulong)(*(ushort *)((long)param_1 + (ulong)uVar2 * 2 + 0x18) & 0x1f);
          uVar4 = uVar4 | 1 << (ulong)(*(ushort *)((long)param_1 + (ulong)(uVar2 | 1) * 2 + 0x18) &
                                      0x1f);
        } while (uVar6 != uVar7);
        uVar4 = uVar4 | uVar5;
        if (uVar3 == uVar6) {
          return uVar4;
        }
      }
    }
  }
  do {
    bVar1 = (byte)uVar6;
    uVar6 = uVar6 + 1;
    uVar4 = uVar4 | 1 << (ulong)(*(ushort *)((long)param_1 + (ulong)bVar1 * 2 + 0x18) & 0x1f);
  } while ((uVar6 & 0xff) < uVar3);
  return uVar4;
}



//------------------------------------------------------------
// DATARMNET04e8d1b862 @ 00104e38 size=188
// signature: undefined DATARMNET04e8d1b862(void)
// callers: [DATARMNETf5821256ad, DATARMNETb6bff4a724, DATARMNET756778f14f, DATARMNETe02152c351]
//------------------------------------------------------------

uint DATARMNET04e8d1b862(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (((param_2 & 0xff) >> (ulong)(param_1 & 0x1f) & 1) != 0) {
    uVar1 = param_2 & 1;
    if ((param_1 & 0xff) == 0) {
      if (uVar1 == 0) {
        return 0xffffffff;
      }
      return 0;
    }
    uVar2 = param_2 & 2;
    if ((param_1 & 0xff) != 1) {
      uVar1 = uVar1 + (uVar2 >> 1);
      uVar2 = param_2 & 4;
      if ((param_1 & 0xff) != 2) {
        uVar1 = uVar1 + (uVar2 >> 2);
        uVar2 = param_2 & 8;
        if ((param_1 & 0xff) != 3) {
          uVar1 = uVar1 + (uVar2 >> 3);
          uVar2 = param_2 & 0x10;
          if ((param_1 & 0xff) != 4) {
            uVar1 = uVar1 + (uVar2 >> 4);
            param_1 = param_1 & 0xff;
            uVar2 = param_2 & 0x20;
            if (param_1 != 5) {
              uVar1 = uVar1 + (uVar2 >> 5);
              uVar2 = param_2 & 0x40;
              if (param_1 == 7) {
                if ((param_2 >> 7 & 1) == 0) {
                  return 0xffffffff;
                }
                return uVar1 + (uVar2 >> 6);
              }
              if (param_1 != 6) {
                return 0xffffffff;
              }
            }
            if (uVar2 == 0) {
              return 0xffffffff;
            }
            return uVar1;
          }
        }
      }
    }
    if (uVar2 != 0) {
      return uVar1;
    }
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// DATARMNET217fe38119 @ 00104ef8 size=112
// signature: undefined DATARMNET217fe38119(void)
// callers: []
//------------------------------------------------------------

int DATARMNET217fe38119(ulong param_1,undefined8 param_2)

{
  int iVar1;
  
  if ((0x18 < param_1 >> 0xd) || (iVar1 = DATARMNETf181a18009(param_2), iVar1 == -1)) {
    iVar1 = DATARMNET98b2a0ce62(param_2);
  }
  return iVar1;
}



//------------------------------------------------------------
// DATARMNETefcaf5fbe9 @ 00104ffc size=248
// signature: undefined DATARMNETefcaf5fbe9(void)
// callers: [DATARMNETe24386452c, DATARMNETf4aefff4c2, DATARMNET71b0abb49e, DATARMNETb9e0ebf153, DATARMNET9303cec796]
//------------------------------------------------------------

long DATARMNETefcaf5fbe9(long param_1,uint param_2,uint param_3,long param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  uint *puVar6;
  ulong uVar7;
  ulong uVar8;
  
  uVar1 = *(uint *)(param_1 + 0x70);
  lVar5 = 0;
  if ((param_2 <= uVar1) && (param_3 <= uVar1)) {
    if (uVar1 < param_3 + param_2) {
      lVar5 = 0;
    }
    else {
      uVar1 = uVar1 - *(int *)(param_1 + 0x74);
      if (uVar1 < param_3 + param_2) {
        uVar7 = (ulong)*(byte *)(*(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4) + 2);
        if (uVar7 != 0) {
          puVar6 = (uint *)((ulong)*(uint *)(param_1 + 0xd4) + *(long *)(param_1 + 0xd8) + 0x54);
          uVar4 = (ulong)(param_2 - uVar1);
          do {
            uVar1 = puVar6[-1];
            uVar3 = (uint)uVar4;
            uVar8 = (ulong)(uVar3 - uVar1);
            if ((uVar3 < uVar1) && (uVar8 = uVar4, uVar3 + param_3 <= uVar1)) {
              return ((*(ulong *)(puVar6 + -3) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                     (ulong)*puVar6 + uVar4;
            }
            puVar6 = puVar6 + 4;
            uVar7 = uVar7 - 1;
            uVar4 = uVar8;
          } while (uVar7 != 0);
        }
        iVar2 = skb_copy_bits(param_1,param_2,param_4);
        if (iVar2 != 0) {
          param_4 = 0;
        }
        lVar5 = param_4;
      }
      else {
        lVar5 = *(long *)(param_1 + 0xe0) + (ulong)param_2;
      }
    }
  }
  return lVar5;
}



//------------------------------------------------------------
// DATARMNET44459105b4 @ 00105100 size=1092
// signature: undefined DATARMNET44459105b4(void)
// callers: [DATARMNETf5821256ad, DATARMNET756778f14f]
//------------------------------------------------------------

void DATARMNET44459105b4(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  long lVar5;
  int iVar6;
  ulong uVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  uint *puVar11;
  ulong uVar12;
  byte *pbVar13;
  undefined8 *puVar14;
  undefined1 local_a0 [4];
  undefined2 local_9c [2];
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined4 local_80;
  byte local_78 [24];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_78[0x10] = 0;
  local_78[0x11] = 0;
  local_78[0x12] = 0;
  local_78[0x13] = 0;
  local_78[0] = 0;
  local_78[1] = 0;
  local_78[2] = 0;
  local_78[3] = 0;
  local_78[4] = 0;
  local_78[5] = 0;
  local_78[6] = 0;
  local_78[7] = 0;
  local_78[8] = 0;
  local_78[9] = 0;
  local_78[10] = 0;
  local_78[0xb] = 0;
  local_78[0xc] = 0;
  local_78[0xd] = 0;
  local_78[0xe] = 0;
  local_78[0xf] = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_60 = 0;
  local_80 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_98 = 0;
  local_9c[0] = 0;
  local_a0[0] = 0;
  if (*(short *)(param_1 + 0xb4) == -0x227a) {
    if (*(uint *)(param_1 + 0x70) < 0x28) goto LAB_00105534;
    uVar4 = *(uint *)(param_1 + 0x70) - *(int *)(param_1 + 0x74);
    if (uVar4 < 0x28) {
      uVar7 = (ulong)*(byte *)(*(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4) + 2);
      if (uVar7 != 0) {
        puVar11 = (uint *)((ulong)*(uint *)(param_1 + 0xd4) + *(long *)(param_1 + 0xd8) + 0x54);
        uVar10 = (ulong)-uVar4;
        do {
          uVar4 = puVar11[-1];
          uVar8 = (uint)uVar10;
          uVar12 = (ulong)(uVar8 - uVar4);
          if ((uVar8 < uVar4) && (uVar12 = uVar10, uVar8 + 0x28 <= uVar4)) {
            puVar14 = (undefined8 *)
                      (((*(ulong *)(puVar11 + -3) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                       (ulong)*puVar11 + uVar10);
            goto LAB_001052b0;
          }
          uVar7 = uVar7 - 1;
          puVar11 = puVar11 + 4;
          uVar10 = uVar12;
        } while (uVar7 != 0);
      }
      puVar14 = &local_60;
      iVar6 = skb_copy_bits(param_1,0,&local_60,0x28);
      if (iVar6 != 0) goto LAB_00105534;
    }
    else {
      puVar14 = *(undefined8 **)(param_1 + 0xe0);
LAB_001052b0:
      if (puVar14 == (undefined8 *)0x0) goto LAB_00105534;
    }
    *(ushort *)(param_2 + 0x1b) = (ushort)*(byte *)((long)puVar14 + 6);
    *param_2 = *puVar14;
    uVar2 = puVar14[4];
    uVar1 = puVar14[1];
    uVar3 = puVar14[2];
    param_2[3] = puVar14[3];
    param_2[4] = uVar2;
    param_2[1] = uVar1;
    param_2[2] = uVar3;
    local_a0[0] = *(undefined1 *)((long)puVar14 + 6);
    uVar7 = ipv6_skip_exthdr(param_1,0x28,local_a0,local_9c);
    if ((int)uVar7 < 0) goto LAB_00105534;
  }
  else {
    uVar7 = 0;
    if (*(short *)(param_1 + 0xb4) == 8) {
      if (*(uint *)(param_1 + 0x70) < 0x14) goto LAB_00105534;
      uVar4 = *(uint *)(param_1 + 0x70) - *(int *)(param_1 + 0x74);
      if (uVar4 < 0x14) {
        uVar7 = (ulong)*(byte *)(*(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4) + 2);
        if (uVar7 != 0) {
          puVar11 = (uint *)((ulong)*(uint *)(param_1 + 0xd4) + *(long *)(param_1 + 0xd8) + 0x54);
          uVar10 = (ulong)-uVar4;
          do {
            uVar4 = puVar11[-1];
            uVar8 = (uint)uVar10;
            uVar12 = (ulong)(uVar8 - uVar4);
            if ((uVar8 < uVar4) && (uVar12 = uVar10, uVar8 + 0x14 <= uVar4)) {
              pbVar13 = (byte *)(((*(ulong *)(puVar11 + -3) & 0x3ffffffffffc0) << 6 |
                                 0xff00000000000000) + (ulong)*puVar11 + uVar10);
              goto LAB_001052a4;
            }
            uVar7 = uVar7 - 1;
            puVar11 = puVar11 + 4;
            uVar10 = uVar12;
          } while (uVar7 != 0);
        }
        pbVar13 = local_78;
        iVar6 = skb_copy_bits(param_1,0,local_78,0x14);
        if (iVar6 != 0) goto LAB_00105534;
      }
      else {
        pbVar13 = *(byte **)(param_1 + 0xe0);
LAB_001052a4:
        if (pbVar13 == (byte *)0x0) goto LAB_00105534;
      }
      *(ushort *)(param_2 + 0x1b) = (ushort)pbVar13[9];
      uVar1 = *(undefined8 *)pbVar13;
      uVar2 = *(undefined8 *)(pbVar13 + 8);
      *(undefined4 *)(param_2 + 2) = *(undefined4 *)(pbVar13 + 0x10);
      *param_2 = uVar1;
      param_2[1] = uVar2;
      uVar7 = (ulong)((*pbVar13 & 0xf) << 2);
    }
  }
  if (*(short *)(param_2 + 0x1b) == 0x11) {
    uVar8 = *(uint *)(param_1 + 0x70);
    uVar4 = (uint)uVar7 & 0xffff;
    if (((uVar4 <= uVar8) && (7 < uVar8)) && (uVar4 + 8 <= uVar8)) {
      uVar8 = uVar8 - *(int *)(param_1 + 0x74);
      if (uVar8 < uVar4 + 8) {
        uVar7 = (ulong)*(byte *)(*(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4) + 2);
        if (uVar7 != 0) {
          puVar11 = (uint *)((ulong)*(uint *)(param_1 + 0xd4) + *(long *)(param_1 + 0xd8) + 0x54);
          uVar10 = (ulong)(uVar4 - uVar8);
          do {
            uVar8 = puVar11[-1];
            uVar9 = (uint)uVar10;
            uVar12 = (ulong)(uVar9 - uVar8);
            if ((uVar9 < uVar8) && (uVar12 = uVar10, uVar9 + 8 <= uVar8)) {
              puVar14 = (undefined8 *)
                        (((*(ulong *)(puVar11 + -3) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                         (ulong)*puVar11 + uVar10);
              goto LAB_001054e0;
            }
            uVar7 = uVar7 - 1;
            puVar11 = puVar11 + 4;
            uVar10 = uVar12;
          } while (uVar7 != 0);
        }
        puVar14 = &local_98;
        iVar6 = skb_copy_bits(param_1,uVar4,&local_98,8);
        if (iVar6 != 0) goto LAB_00105534;
      }
      else {
        puVar14 = (undefined8 *)(*(long *)(param_1 + 0xe0) + (uVar7 & 0xffff));
LAB_001054e0:
        if (puVar14 == (undefined8 *)0x0) goto LAB_00105534;
      }
      param_2[5] = *puVar14;
    }
  }
  else if (*(short *)(param_2 + 0x1b) == 6) {
    uVar8 = *(uint *)(param_1 + 0x70);
    uVar4 = (uint)uVar7 & 0xffff;
    if (((uVar4 <= uVar8) && (0x13 < uVar8)) && (uVar4 + 0x14 <= uVar8)) {
      uVar8 = uVar8 - *(int *)(param_1 + 0x74);
      if (uVar8 < uVar4 + 0x14) {
        uVar7 = (ulong)*(byte *)(*(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4) + 2);
        if (uVar7 != 0) {
          puVar11 = (uint *)((ulong)*(uint *)(param_1 + 0xd4) + *(long *)(param_1 + 0xd8) + 0x54);
          uVar10 = (ulong)(uVar4 - uVar8);
          do {
            uVar8 = puVar11[-1];
            uVar9 = (uint)uVar10;
            uVar12 = (ulong)(uVar9 - uVar8);
            if ((uVar9 < uVar8) && (uVar12 = uVar10, uVar9 + 0x14 <= uVar8)) {
              puVar14 = (undefined8 *)
                        (((*(ulong *)(puVar11 + -3) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                         (ulong)*puVar11 + uVar10);
              goto LAB_001054d0;
            }
            uVar7 = uVar7 - 1;
            puVar11 = puVar11 + 4;
            uVar10 = uVar12;
          } while (uVar7 != 0);
        }
        puVar14 = &local_90;
        iVar6 = skb_copy_bits(param_1,uVar4,&local_90,0x14);
        if (iVar6 != 0) goto LAB_00105534;
      }
      else {
        puVar14 = (undefined8 *)(*(long *)(param_1 + 0xe0) + (uVar7 & 0xffff));
LAB_001054d0:
        if (puVar14 == (undefined8 *)0x0) goto LAB_00105534;
      }
      uVar1 = *puVar14;
      uVar2 = puVar14[1];
      *(undefined4 *)(param_2 + 7) = *(undefined4 *)(puVar14 + 2);
      param_2[5] = uVar1;
      param_2[6] = uVar2;
    }
  }
LAB_00105534:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET8532ab3089 @ 00105568 size=200
// signature: undefined DATARMNET8532ab3089(void)
// callers: [DATARMNETf5821256ad, DATARMNETcba2f7f7b6, DATARMNET337eca0417, DATARMNET23c7ddd780]
//------------------------------------------------------------

uint DATARMNET8532ab3089(int param_1,uint param_2,uint param_3,char param_4)

{
  code *pcVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    DAT_0011da40 = DAT_0011da40 + 1;
    uVar2 = 0;
  }
  else {
    if (param_2 < 8) {
      if ((9 < param_2 - 1) || (uVar2 = param_2 - 1 >> 1, uVar2 == 4)) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(1,0x105630);
        (*pcVar1)();
      }
      uVar2 = param_3 & 0xffffff |
              ((param_2 & 1) + param_1) * *(int *)(&DAT_001155a0 + (ulong)uVar2 * 4) * 0x10000000;
    }
    else {
      uVar2 = 0;
    }
    if (param_4 != '\0') {
      uVar2 = uVar2 & 0xfff00000 | 0x77777;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// trace_rmnet_shs_high @ 001056f0 size=44
// signature: undefined trace_rmnet_shs_high(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

void trace_rmnet_shs_high(void)

{
  return;
}



//------------------------------------------------------------
// DATARMNETe9173bbe0e @ 001057a4 size=808
// signature: undefined DATARMNETe9173bbe0e(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETe9173bbe0e(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  char *__s1;
  
  __s1 = (char *)*param_3;
  if (__s1 == (char *)0x0) {
    DATARMNET68d84e7b98 = DATARMNET68d84e7b98 + 1;
  }
  else {
    iVar3 = strncmp(__s1,"rmnet_data",10);
    uVar1 = DATARMNETecc0627c70._392_8_;
    if (iVar3 == 0) {
      switch(param_2) {
      case 1:
        if ((DATARMNETecc0627c70[0x669] == '\0') && (DATARMNETecc0627c70[0x66d] != '\0')) {
          if (DATARMNETecc0627c70._392_8_ == 0) {
            _printk(&DAT_001154ad);
          }
          else {
            DATARMNETecc0627c70[0x120] = 1;
            DATARMNETecc0627c70[0x148] = 1;
            if ((*(byte *)(DATARMNETecc0627c70._392_8_ + 0xb) >> 5 & 1) != 0) {
              DATARMNETecc0627c70._296_8_ = DATARMNET78bb6be330;
              DATARMNETecc0627c70._304_8_ = DATARMNETf61cd23b90;
              DATARMNETecc0627c70._336_8_ = DATARMNET4684d6c911;
            }
            DATARMNETecc0627c70._360_8_ = DATARMNET7f1d9480cb;
            DATARMNETecc0627c70._368_8_ = DATARMNETa4bd2ef52c;
            iVar3 = rmnet_map_dl_ind_register(DATARMNETecc0627c70._392_8_);
            if (iVar3 != 0) {
              _printk(&DAT_001151ac,"DATARMNETe9173bbe0e");
            }
            iVar3 = rmnet_map_pb_ind_register(uVar1,0x11c5e0);
            if (iVar3 != 0) {
              _printk(&DAT_00115275,"DATARMNETe9173bbe0e");
            }
            iVar3 = qmi_rmnet_ps_ind_register(uVar1,0x11c600);
            if (iVar3 != 0) {
              _printk(&DAT_001151d4,"DATARMNETe9173bbe0e");
            }
            DATARMNET7492293980(__s1);
            DATARMNET039ac6d55d();
            DATARMNET0a6fb12cb2();
            DATARMNETe46c480d71();
            DATARMNETa871eeb7e7();
            DATARMNET7520667b38();
            rmnet_module_hook_register(DATARMNETf6217b20b8,1);
            tracepoint_probe_register
                      (&__tracepoint_android_vh_do_wake_up_sync,DATARMNET3e88a91b63,0);
            DATARMNETecc0627c70[0x669] = '\x01';
          }
        }
        else {
          DATARMNET7492293980(__s1);
        }
        break;
      case 2:
        DATARMNETd6ee05f1b4(__s1);
        break;
      case 5:
        bVar2 = DATARMNET2cb9ae589c != -1;
        DATARMNET2cb9ae589c = DATARMNET2cb9ae589c + 1;
        if ((bVar2) && (DATARMNETecc0627c70[0x66d] == '\0')) {
          _printk(&DAT_00114eff,__s1);
          lVar5 = rmnet_get_port(*(undefined8 *)(__s1 + 0xa48));
          if (lVar5 == 0) {
            _printk(&DAT_00115110);
          }
          else {
            DATARMNET45d8cdb224(*(undefined8 *)(__s1 + 0xa48),__s1);
            DATARMNET3ae0d614d6();
            DATARMNETe1f95274f1();
            DATARMNETecc0627c70[0x66b] = 1;
          }
        }
        break;
      case 6:
        DATARMNET2cb9ae589c = DATARMNET2cb9ae589c + -1;
        if ((DATARMNET2cb9ae589c == 0) && (DATARMNETecc0627c70[0x66d] != '\0')) {
          _printk(&DAT_00115342,__s1);
          DATARMNET203752febd();
          DATARMNETa871eeb7e7();
          rmnet_module_hook_unregister_no_sync(DATARMNETf6217b20b8,1);
          qmi_rmnet_ps_ind_deregister(DATARMNETecc0627c70._392_8_,0x11c600);
          rmnet_map_dl_ind_deregister(DATARMNETecc0627c70._392_8_,0x11c5b8);
          rmnet_map_pb_ind_deregister(DATARMNETecc0627c70._392_8_,0x11c5e0);
          DATARMNETeacad8334e();
          DATARMNET90fe3a4b56();
          uVar4 = DATARMNET02cdd9b125();
          if (DATARMNETecc0627c70[0x669] != '\0') {
            tracepoint_probe_unregister
                      (&__tracepoint_android_vh_do_wake_up_sync,DATARMNET3e88a91b63,0);
          }
          DATARMNETf7dcab9a9e();
          DATARMNET9297340f58(uVar4);
          trace_rmnet_shs_high(1);
        }
      }
    }
  }
  return 0;
}



//------------------------------------------------------------
// DATARMNET3e88a91b63 @ 00105b54 size=88
// signature: undefined DATARMNET3e88a91b63(void)
// callers: []
//------------------------------------------------------------

void DATARMNET3e88a91b63(undefined8 param_1,undefined8 param_2,undefined4 *param_3,long param_4)

{
  if ((*(short *)(param_4 + 0x214) == 0x11 || *(short *)(param_4 + 0x214) == 6) &&
     ((*(uint *)(param_4 + 0x84) & 0xfffff) == 0x77777)) {
    *param_3 = 1;
    __wake_up(param_2,1,1,0xc3);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET82d7f4ffa2 @ 00105bb8 size=216
// signature: undefined DATARMNET82d7f4ffa2(void)
// callers: [DATARMNETe6e8431304]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET82d7f4ffa2(void)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    uVar2 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar3);
    if (_nr_cpu_ids <= uVar2) break;
    if ((uVar2 & 0xffffffe0) != 0) goto LAB_00105c8c;
    iVar3 = uVar2 + 1;
    *(undefined8 *)(*(long *)(&__per_cpu_offset + (ulong)uVar2 * 8) + DATARMNETc4b1be7898_0) =
         0x7fffffff00000000;
  }
  iVar3 = 0;
  while( true ) {
    uVar2 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar3);
    if (_nr_cpu_ids <= uVar2) {
      return;
    }
    if ((uVar2 & 0xffffffe0) != 0) break;
    *(undefined8 *)(*(long *)(&__per_cpu_offset + (ulong)uVar2 * 8) + DATARMNET7cf8d49bd5_0) =
         0x7fffffff00000000;
    iVar3 = uVar2 + 1;
  }
LAB_00105c8c:
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x105c90);
  (*pcVar1)();
}



//------------------------------------------------------------
// DATARMNET5e4aeef593 @ 00105c94 size=92
// signature: undefined DATARMNET5e4aeef593(void)
// callers: [DATARMNET02fc8b29a0]
//------------------------------------------------------------

void DATARMNET5e4aeef593(uint param_1)

{
  if ((param_1 < 8) && ((DATARMNETecc0627c70[0x68a] >> (ulong)(param_1 & 0x1f) & 1) == 0)) {
    *(undefined8 *)(*(long *)(&__per_cpu_offset + (ulong)param_1 * 8) + DATARMNETc4b1be7898_0) =
         0x7fffffff7fffffff;
  }
  return;
}



//------------------------------------------------------------
// DATARMNETfb7007f025 @ 00105d5c size=244
// signature: undefined DATARMNETfb7007f025(void)
// callers: [DATARMNET02fc8b29a0, DATARMNETc54e431bbc]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETfb7007f025(void)

{
  undefined8 uVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar1 = sp_el0;
  do {
    uVar3 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar4);
    if (_nr_cpu_ids <= uVar3) {
      if (((DATARMNETbfcbb4b8ac & 1) == 0) && (DATARMNETde8f350999 != 0)) {
        queue_work_on(2,DATARMNETde8f350999,&DATARMNETbfcbb4b8ac);
      }
      return;
    }
    if ((DATARMNETecc0627c70[0x689] >> (ulong)(uVar3 & 0x1f) & 1) == 0) {
      if ((uVar3 & 0xffffffe0) != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x105eb4);
        (*pcVar2)();
      }
      *(undefined8 *)(*(long *)(&__per_cpu_offset + (ulong)uVar3 * 8) + DATARMNETc4b1be7898_0) =
           0x7fffffff7fffffff;
    }
    iVar4 = uVar3 + 1;
  } while( true );
}



//------------------------------------------------------------
// DATARMNET202a68d7d0 @ 00105eb8 size=244
// signature: undefined DATARMNET202a68d7d0(void)
// callers: [DATARMNET4684d6c911]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET202a68d7d0(void)

{
  undefined8 uVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar1 = sp_el0;
  do {
    uVar3 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar4);
    if (_nr_cpu_ids <= uVar3) {
      if (((DATARMNET3dc8e3c69f & 1) == 0) && (DATARMNETde8f350999 != 0)) {
        queue_work_on(2,DATARMNETde8f350999,&DATARMNET3dc8e3c69f);
      }
      return;
    }
    if ((DATARMNETecc0627c70[0x689] >> (ulong)(uVar3 & 0x1f) & 1) == 0) {
      if ((uVar3 & 0xffffffe0) != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x106010);
        (*pcVar2)();
      }
      *(undefined8 *)(*(long *)(&__per_cpu_offset + (ulong)uVar3 * 8) + DATARMNET7cf8d49bd5_0) =
           0x7fffffff7fffffff;
    }
    iVar4 = uVar3 + 1;
  } while( true );
}



//------------------------------------------------------------
// DATARMNET371703c28d @ 00106014 size=224
// signature: undefined DATARMNET371703c28d(void)
// callers: [DATARMNET4ce9744605]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET371703c28d(void)

{
  undefined8 uVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar1 = sp_el0;
  while( true ) {
    uVar3 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar4);
    if (_nr_cpu_ids <= uVar3) {
      if (((DATARMNETbfcbb4b8ac & 1) == 0) && (DATARMNETde8f350999 != 0)) {
        queue_work_on(2,DATARMNETde8f350999,&DATARMNETbfcbb4b8ac);
      }
      return;
    }
    if ((uVar3 & 0xffffffe0) != 0) break;
    *(undefined8 *)(*(long *)(&__per_cpu_offset + (ulong)uVar3 * 8) + DATARMNETc4b1be7898_0) =
         0x7fffffff00000000;
    iVar4 = uVar3 + 1;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x106158);
  (*pcVar2)();
}



//------------------------------------------------------------
// DATARMNETf20806b279 @ 0010615c size=224
// signature: undefined DATARMNETf20806b279(void)
// callers: [DATARMNETbfbe1f5cd0]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETf20806b279(void)

{
  undefined8 uVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar1 = sp_el0;
  while( true ) {
    uVar3 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar4);
    if (_nr_cpu_ids <= uVar3) {
      if (((DATARMNET3dc8e3c69f & 1) == 0) && (DATARMNETde8f350999 != 0)) {
        queue_work_on(2,DATARMNETde8f350999,&DATARMNET3dc8e3c69f);
      }
      return;
    }
    if ((uVar3 & 0xffffffe0) != 0) break;
    *(undefined8 *)(*(long *)(&__per_cpu_offset + (ulong)uVar3 * 8) + DATARMNET7cf8d49bd5_0) =
         0x7fffffff00000000;
    iVar4 = uVar3 + 1;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1062a0);
  (*pcVar2)();
}



//------------------------------------------------------------
// DATARMNETe6e8431304 @ 001062a4 size=560
// signature: undefined DATARMNETe6e8431304(void)
// callers: [DATARMNET45d8cdb224]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DATARMNETe6e8431304(void)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined *puVar5;
  long lVar6;
  
  DATARMNETc4b1be7898_0 = __alloc_percpu(8,4);
  if (DATARMNETc4b1be7898_0 != 0) {
    DATARMNET7cf8d49bd5_0 = __alloc_percpu(8,4);
    if (DATARMNET7cf8d49bd5_0 == 0) {
      free_percpu(DATARMNETc4b1be7898_0);
    }
    else {
      if ((DATARMNETde8f350999 != 0) ||
         (DATARMNETde8f350999 = alloc_workqueue("shs_boost_wq",0x10,0), DATARMNETde8f350999 != 0)) {
        iVar3 = 0;
        do {
          uVar2 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar3);
          if (_nr_cpu_ids <= uVar2) {
            DATARMNETbfcbb4b8ac = 0xfffffffe0;
            DAT_001192d8 = &DAT_001192d8;
            DAT_001192e0 = &DAT_001192d8;
            DAT_001192e8 = DATARMNETb90d2272b4;
            DATARMNET3dc8e3c69f = 0xfffffffe0;
            DAT_00119310 = &DAT_00119310;
            DAT_00119318 = &DAT_00119310;
            DAT_00119320 = DATARMNET5a406b068f;
            DATARMNET82d7f4ffa2();
            return 0;
          }
          if ((uVar2 & 0xffffffe0) != 0) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1064d4);
            (*pcVar1)();
          }
          lVar6 = *(long *)(&__per_cpu_offset + (ulong)uVar2 * 8);
          lVar4 = cpufreq_cpu_get(uVar2);
          if (lVar4 == 0) {
            puVar5 = &DAT_0011521f;
LAB_00106498:
            _printk(puVar5,"DATARMNETe6e8431304",uVar2);
            return -3;
          }
          iVar3 = freq_qos_add_request(lVar4 + 0xa0,&DATARMNET17d6a9530a + lVar6,1,0);
          if (iVar3 < 0) {
            puVar5 = &DAT_001150dd;
LAB_001064bc:
            _printk(puVar5,"DATARMNETe6e8431304",iVar3);
            return iVar3;
          }
          lVar6 = *(long *)(&__per_cpu_offset + (ulong)uVar2 * 8);
          lVar4 = cpufreq_cpu_get(uVar2);
          if (lVar4 == 0) {
            puVar5 = &DAT_00115440;
            goto LAB_00106498;
          }
          iVar3 = freq_qos_add_request(lVar4 + 0xa0,DATARMNET68a4af61b9 + lVar6,1,0);
          if (iVar3 < 0) {
            puVar5 = &DAT_0011546d;
            goto LAB_001064bc;
          }
          iVar3 = uVar2 + 1;
        } while( true );
      }
      DATARMNET82d7f4ffa2();
      free_percpu(DATARMNETc4b1be7898_0);
      free_percpu(DATARMNET7cf8d49bd5_0);
      if (DATARMNETde8f350999 != 0) {
        destroy_workqueue();
        DATARMNETde8f350999 = 0;
        return -0xc;
      }
    }
  }
  return -0xc;
}



//------------------------------------------------------------
// DATARMNETb90d2272b4 @ 001064d8 size=168
// signature: undefined DATARMNETb90d2272b4(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETb90d2272b4(void)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  
  cpus_read_lock();
  iVar3 = 0;
  while( true ) {
    uVar2 = _find_next_bit(&__cpu_online_mask,_nr_cpu_ids,iVar3);
    if (_nr_cpu_ids <= uVar2) {
      cpus_read_unlock();
      return;
    }
    if (0x1f < (ulong)uVar2) break;
    freq_qos_update_request
              (&DATARMNET17d6a9530a + *(long *)(&__per_cpu_offset + (ulong)uVar2 * 8),
               *(undefined4 *)
                (*(long *)(&__per_cpu_offset + (ulong)uVar2 * 8) + DATARMNETc4b1be7898_0));
    iVar3 = uVar2 + 1;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x106580);
  (*pcVar1)();
}



//------------------------------------------------------------
// DATARMNET5a406b068f @ 00106584 size=232
// signature: undefined DATARMNET5a406b068f(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET5a406b068f(void)

{
  undefined8 uVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  
  cpus_read_lock();
  iVar4 = 0;
  uVar1 = sp_el0;
  while( true ) {
    uVar3 = _find_next_bit(&__cpu_online_mask,_nr_cpu_ids,iVar4);
    if (_nr_cpu_ids <= uVar3) {
      cpus_read_unlock();
      return;
    }
    if (0x1f < (ulong)uVar3) break;
    freq_qos_update_request
              (DATARMNET68a4af61b9 + *(long *)(&__per_cpu_offset + (ulong)uVar3 * 8),
               *(undefined4 *)
                (*(long *)(&__per_cpu_offset + (ulong)uVar3 * 8) + DATARMNET7cf8d49bd5_0));
    iVar4 = uVar3 + 1;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1066d4);
  (*pcVar2)();
}



//------------------------------------------------------------
// DATARMNETdf74db7e38 @ 001066d8 size=268
// signature: undefined DATARMNETdf74db7e38(void)
// callers: [DATARMNET9297340f58]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNETdf74db7e38(void)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  
  iVar3 = 0;
  while( true ) {
    uVar2 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar3);
    if (_nr_cpu_ids <= uVar2) {
      if (DATARMNETde8f350999 != 0) {
        destroy_workqueue();
        DATARMNETde8f350999 = 0;
      }
      free_percpu(DATARMNETc4b1be7898_0);
      free_percpu(DATARMNET7cf8d49bd5_0);
      return 0;
    }
    if ((uVar2 & 0xffffffe0) != 0) break;
    lVar4 = *(long *)(&__per_cpu_offset + (ulong)uVar2 * 8);
    if (((lVar4 != -0x122798) && (*(ulong *)(&DAT_001227c8 + lVar4) != 0)) &&
       (*(ulong *)(&DAT_001227c8 + lVar4) < 0xfffffffffffff001)) {
      freq_qos_remove_request();
      lVar4 = *(long *)(&__per_cpu_offset + (ulong)uVar2 * 8);
    }
    if (((lVar4 != -0x1227d8) && (*(ulong *)(DATARMNET68a4af61b9 + lVar4 + 0x30) != 0)) &&
       (*(ulong *)(DATARMNET68a4af61b9 + lVar4 + 0x30) < 0xfffffffffffff001)) {
      freq_qos_remove_request();
    }
    iVar3 = uVar2 + 1;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1067e4);
  (*pcVar1)();
}



//------------------------------------------------------------
// DATARMNETf4aefff4c2 @ 00106800 size=500
// signature: undefined DATARMNETf4aefff4c2(void)
// callers: [DATARMNETf5821256ad]
//------------------------------------------------------------

undefined8 DATARMNETf4aefff4c2(long param_1)

{
  byte bVar1;
  long lVar2;
  byte *pbVar3;
  undefined8 uVar4;
  undefined2 local_f8 [4];
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined4 local_e0;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_e0 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_70 = 0;
  local_f8[0] = 0;
  if (*(short *)(param_1 + 0xb4) == -0x227a) {
    lVar2 = DATARMNETefcaf5fbe9(param_1,0,0x28,&local_70);
    if (lVar2 != 0) {
      bVar1 = *(byte *)(lVar2 + 6);
      if (bVar1 < 0x2c) {
        uVar4 = 1;
        if ((bVar1 == 6) || (bVar1 == 0x11)) goto LAB_00106ae0;
      }
      else if (bVar1 == 0x2c) {
        if (((*(uint *)(param_1 + 0x70) & 0xfffffffe) != 0x28) &&
           (pbVar3 = (byte *)skb_header_pointer(param_1,local_f8), pbVar3 != (byte *)0x0)) {
          bVar1 = *pbVar3;
          goto joined_r0x00106ab8;
        }
      }
      else {
        if (bVar1 == 0x32) goto LAB_00106abc;
        if (bVar1 == 0x3a) {
          *(undefined4 *)(param_1 + 0x94) = 0;
          *(ushort *)(param_1 + 0x80) = *(ushort *)(param_1 + 0x80) | 0x200;
          uVar4 = 0;
          goto LAB_00106ae0;
        }
      }
    }
  }
  else {
    uVar4 = 0;
    if (*(short *)(param_1 + 0xb4) != 8) goto LAB_00106ae0;
    lVar2 = DATARMNETefcaf5fbe9(param_1,0,0x14,&local_f0);
    if (lVar2 != 0) {
      bVar1 = *(byte *)(lVar2 + 9);
      if ((*(ushort *)(lVar2 + 6) & 0xff3f) == 0) {
        uVar4 = 1;
        if (bVar1 < 0x11) {
          if (bVar1 == 1) goto LAB_001069bc;
          if (bVar1 == 6) goto LAB_00106ae0;
        }
        else {
          if (bVar1 == 0x11) goto LAB_00106ae0;
joined_r0x00106ab8:
          if (bVar1 == 0x32) goto LAB_00106abc;
        }
      }
      else {
        if (bVar1 == 0x32) {
LAB_00106abc:
          uVar4 = 0;
          *(undefined4 *)(param_1 + 0x94) = 0xaaaaaa;
          *(ushort *)(param_1 + 0x80) = *(ushort *)(param_1 + 0x80) | 0x200;
          goto LAB_00106ae0;
        }
        if (bVar1 == 1) {
LAB_001069bc:
          *(undefined4 *)(param_1 + 0x94) = 0;
          *(ushort *)(param_1 + 0x80) = *(ushort *)(param_1 + 0x80) | 0x200;
          uVar4 = 0;
          goto LAB_00106ae0;
        }
      }
    }
  }
  uVar4 = 0;
LAB_00106ae0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



//------------------------------------------------------------
// trace_print_icmp_rx @ 00106bb8 size=36
// signature: undefined trace_print_icmp_rx(void)
// callers: []
//------------------------------------------------------------

void trace_print_icmp_rx(void)

{
  return;
}



//------------------------------------------------------------
// skb_header_pointer @ 00106c58 size=96
// signature: undefined skb_header_pointer(void)
// callers: [DATARMNETf4aefff4c2]
//------------------------------------------------------------

long skb_header_pointer(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  
  if ((*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x74)) + -0x28 < 2) {
    lVar2 = 0;
    if (param_1 != 0) {
      iVar1 = skb_copy_bits(param_1,0x28,param_2,2);
      lVar2 = 0;
      if (-1 < iVar1) {
        lVar2 = param_2;
      }
    }
  }
  else {
    lVar2 = *(long *)(param_1 + 0xe0) + 0x28;
  }
  return lVar2;
}



//------------------------------------------------------------
// DATARMNET71b0abb49e @ 00106cbc size=492
// signature: undefined DATARMNET71b0abb49e(void)
// callers: [DATARMNETe24386452c]
//------------------------------------------------------------

void DATARMNET71b0abb49e(undefined8 param_1,long param_2,long *param_3)

{
  byte bVar1;
  short sVar2;
  long lVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  short *psVar10;
  undefined2 local_80 [2];
  char local_7c [4];
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_60 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_78 = 0;
  local_80[0] = 0;
  if ((char)param_3[5] == '\0') {
    bVar4 = true;
    if (*(char *)((long)param_3 + 0x29) == '\0') goto LAB_00106d64;
LAB_00106d28:
    bVar5 = *(long *)(param_2 + 0x18) == *param_3 && *(long *)(param_2 + 0x20) == param_3[1];
    if (*(char *)((long)param_3 + 0x2b) != '\0') goto LAB_00106d44;
LAB_00106d70:
    local_7c[0] = *(char *)(param_2 + 6);
    bVar6 = true;
  }
  else {
    bVar4 = *(long *)(param_2 + 8) == param_3[2] && *(long *)(param_2 + 0x10) == param_3[3];
    if (*(char *)((long)param_3 + 0x29) != '\0') goto LAB_00106d28;
LAB_00106d64:
    bVar5 = true;
    if (*(char *)((long)param_3 + 0x2b) == '\0') goto LAB_00106d70;
LAB_00106d44:
    local_7c[0] = *(char *)(param_2 + 6);
    bVar6 = *(char *)((long)param_3 + 0x2a) == local_7c[0];
  }
  bVar7 = *(short *)((long)param_3 + 0x22) == 0;
  bVar8 = *(short *)((long)param_3 + 0x26) == 0;
  if (*(short *)((long)param_3 + 0x22) == 0 && *(short *)((long)param_3 + 0x26) == 0) {
    bVar7 = true;
LAB_00106da0:
    bVar8 = true;
  }
  else {
    iVar9 = ipv6_skip_exthdr(param_1,0x28,local_7c,local_80);
    if (iVar9 < 0) {
      bVar1 = 0;
      goto LAB_00106db4;
    }
    if (*(char *)(param_2 + 6) == '\x11') {
      psVar10 = (short *)DATARMNETefcaf5fbe9(param_1,iVar9,8,&local_78);
      if (psVar10 != (short *)0x0) {
        if (*(short *)((long)param_3 + 0x22) != 0) goto LAB_00106e34;
LAB_00106e74:
        bVar7 = true;
        sVar2 = *(short *)((long)param_3 + 0x26);
        goto joined_r0x00106e7c;
      }
LAB_00106e98:
      bVar7 = false;
      bVar8 = false;
    }
    else if (*(char *)(param_2 + 6) == '\x06') {
      psVar10 = (short *)DATARMNETefcaf5fbe9(param_1,iVar9,0x14,&local_70);
      if (psVar10 == (short *)0x0) goto LAB_00106e98;
      if (*(short *)((long)param_3 + 0x22) == 0) goto LAB_00106e74;
LAB_00106e34:
      bVar7 = *psVar10 == (short)param_3[4];
      sVar2 = *(short *)((long)param_3 + 0x26);
joined_r0x00106e7c:
      if (sVar2 == 0) goto LAB_00106da0;
      bVar8 = psVar10[1] == *(short *)((long)param_3 + 0x24);
    }
  }
  bVar1 = bVar4 & bVar5 & bVar8 & bVar6 & bVar7;
LAB_00106db4:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar1);
  }
  return;
}



//------------------------------------------------------------
// DATARMNETb9e0ebf153 @ 00106eac size=412
// signature: undefined DATARMNETb9e0ebf153(void)
// callers: [DATARMNETe24386452c]
//------------------------------------------------------------

byte DATARMNETb9e0ebf153(undefined8 param_1,byte *param_2,int *param_3)

{
  int iVar1;
  long lVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  short *psVar8;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_58 = 0;
  if ((char)param_3[10] == '\0') {
    bVar3 = true;
    if (*(char *)((long)param_3 + 0x29) != '\0') goto LAB_00106f00;
LAB_00106f38:
    bVar4 = true;
    if (*(char *)((long)param_3 + 0x2b) != '\0') goto LAB_00106f18;
LAB_00106f44:
    bVar5 = true;
  }
  else {
    bVar3 = *(int *)(param_2 + 0xc) == param_3[4];
    if (*(char *)((long)param_3 + 0x29) == '\0') goto LAB_00106f38;
LAB_00106f00:
    bVar4 = *(int *)(param_2 + 0x10) == *param_3;
    if (*(char *)((long)param_3 + 0x2b) == '\0') goto LAB_00106f44;
LAB_00106f18:
    bVar5 = param_2[9] == *(byte *)((long)param_3 + 0x2a);
  }
  bVar6 = *(short *)((long)param_3 + 0x22) == 0;
  bVar7 = *(short *)((long)param_3 + 0x26) == 0;
  if (*(short *)((long)param_3 + 0x22) == 0 && *(short *)((long)param_3 + 0x26) == 0) {
    bVar6 = true;
LAB_00106f6c:
    bVar7 = true;
  }
  else {
    iVar1 = (*param_2 & 0xf) << 2;
    if (param_2[9] == 0x11) {
      psVar8 = (short *)DATARMNETefcaf5fbe9(param_1,iVar1,8,&local_58);
      if (psVar8 != (short *)0x0) {
        if (*(short *)((long)param_3 + 0x22) != 0) goto LAB_00106fa8;
LAB_00106fdc:
        bVar6 = true;
        if (*(short *)((long)param_3 + 0x26) == 0) goto LAB_00106f6c;
LAB_00106fe8:
        bVar7 = psVar8[1] == (short)param_3[9];
        goto LAB_00107008;
      }
    }
    else {
      if (param_2[9] != 6) goto LAB_00107008;
      psVar8 = (short *)DATARMNETefcaf5fbe9(param_1,iVar1,0x14,&local_50);
      if (psVar8 != (short *)0x0) {
        if (*(short *)((long)param_3 + 0x22) == 0) goto LAB_00106fdc;
LAB_00106fa8:
        bVar6 = *psVar8 == (short)param_3[8];
        if (*(short *)((long)param_3 + 0x26) != 0) goto LAB_00106fe8;
        goto LAB_00106f6c;
      }
    }
    bVar6 = false;
    bVar7 = false;
  }
LAB_00107008:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar3 & bVar4 & bVar5 & bVar6 & bVar7;
}



//------------------------------------------------------------
// DATARMNET8fc45abdc4 @ 0010704c size=344
// signature: undefined DATARMNET8fc45abdc4(void)
// callers: [DATARMNET2ac305d296, DATARMNETd52d50282d]
//------------------------------------------------------------

byte DATARMNET8fc45abdc4(long param_1,long param_2)

{
  bool bVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  
  cVar2 = *(char *)(param_1 + 0x4c);
  if (((*(char *)(param_1 + 0x4e) != '\0') && (*(char *)(param_2 + 0x4e) != '\0')) &&
     (*(char *)(param_1 + 0x4e) == *(char *)(param_2 + 0x4e))) {
    return 1;
  }
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (*(char *)(param_2 + 0x48) != '\0') goto LAB_001070a0;
    bVar3 = true;
  }
  else if ((*(char *)(param_2 + 0x48) == '\0') || (cVar2 != '\x04')) {
LAB_001070a0:
    bVar3 = false;
    if (*(long *)(param_2 + 0x30) == *(long *)(param_1 + 0x30)) {
      bVar3 = *(long *)(param_2 + 0x38) == *(long *)(param_1 + 0x38);
    }
  }
  else {
    bVar3 = *(int *)(param_1 + 0x30) == *(int *)(param_2 + 0x30);
  }
  if (*(char *)(param_1 + 0x49) == '\0') {
    if (*(char *)(param_2 + 0x49) == '\0') {
      bVar4 = true;
      goto LAB_001070f4;
    }
  }
  else if ((*(char *)(param_2 + 0x49) != '\0') && (cVar2 == '\x04')) {
    bVar4 = *(int *)(param_1 + 0x20) == *(int *)(param_2 + 0x20);
    goto LAB_001070f4;
  }
  bVar4 = false;
  if (*(long *)(param_2 + 0x20) == *(long *)(param_1 + 0x20)) {
    bVar4 = *(long *)(param_2 + 0x28) == *(long *)(param_1 + 0x28);
  }
LAB_001070f4:
  bVar5 = *(char *)(param_1 + 0x4b) == '\0' && *(char *)(param_2 + 0x4b) == '\0';
  if ((*(char *)(param_1 + 0x4b) != '\0') && (*(char *)(param_2 + 0x4b) != '\0')) {
    bVar5 = *(char *)(param_1 + 0x4a) == *(char *)(param_2 + 0x4a);
  }
  bVar6 = *(short *)(param_1 + 0x42) == 0 && *(short *)(param_2 + 0x42) == 0;
  if ((*(short *)(param_1 + 0x42) != 0) && (*(short *)(param_2 + 0x42) != 0)) {
    bVar6 = *(short *)(param_1 + 0x40) == *(short *)(param_2 + 0x40);
  }
  bVar7 = *(short *)(param_1 + 0x46) == 0 && *(short *)(param_2 + 0x46) == 0;
  if ((*(short *)(param_1 + 0x46) != 0) && (*(short *)(param_2 + 0x46) != 0)) {
    bVar7 = *(short *)(param_1 + 0x44) == *(short *)(param_2 + 0x44);
  }
  bVar1 = false;
  if (cVar2 == *(char *)(param_2 + 0x4c)) {
    bVar1 = bVar3;
  }
  return bVar1 & bVar6 & bVar4 & bVar5 & bVar7;
}



//------------------------------------------------------------
// DATARMNETe24386452c @ 001071a8 size=416
// signature: undefined DATARMNETe24386452c(void)
// callers: [DATARMNET756778f14f]
//------------------------------------------------------------

undefined8 DATARMNETe24386452c(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_68 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_60 = 0;
  _raw_spin_lock_bh(&DATARMNETd83ee17944);
  if (*(short *)(param_1 + 0xb4) == -0x227a) {
    lVar2 = DATARMNETefcaf5fbe9(param_1,0,0x28,&local_60);
    if (lVar2 != 0) {
      uVar4 = 0;
      if (((&DATARMNET5750992efb)[(uint)(*(int *)(lVar2 + 8) * 0x61c88647) >> 0x17] != 0) &&
         (lVar3 = (&DATARMNET5750992efb)[(uint)(*(int *)(lVar2 + 8) * 0x61c88647) >> 0x17] + -0x10,
         lVar3 != 0)) {
        uVar4 = 0;
        do {
          lVar5 = *(long *)(lVar3 + 0x10);
          iVar1 = DATARMNET71b0abb49e(param_1,lVar2,lVar3 + 0x20);
          if (iVar1 != 0) goto LAB_00107304;
        } while ((lVar5 != 0) && (lVar3 = lVar5 + -0x10, lVar3 != 0));
      }
      goto LAB_00107308;
    }
  }
  else {
    uVar4 = 0;
    if (*(short *)(param_1 + 0xb4) != 8) goto LAB_00107308;
    lVar2 = DATARMNETefcaf5fbe9(param_1,0,0x14,&local_78);
    if (lVar2 != 0) {
      uVar4 = 0;
      if (((&DATARMNET5750992efb)[(uint)(*(int *)(lVar2 + 0xc) * 0x61c88647) >> 0x17] != 0) &&
         (lVar3 = (&DATARMNET5750992efb)[(uint)(*(int *)(lVar2 + 0xc) * 0x61c88647) >> 0x17] + -0x10
         , lVar3 != 0)) {
        uVar4 = 0;
        do {
          lVar5 = *(long *)(lVar3 + 0x10);
          iVar1 = DATARMNETb9e0ebf153(param_1,lVar2,lVar3 + 0x20);
          if (iVar1 != 0) goto LAB_00107304;
        } while ((lVar5 != 0) && (lVar3 = lVar5 + -0x10, lVar3 != 0));
      }
      goto LAB_00107308;
    }
  }
  uVar4 = 0;
LAB_00107308:
  _raw_spin_unlock_bh(&DATARMNETd83ee17944);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
LAB_00107304:
  uVar4 = 1;
  goto LAB_00107308;
}



//------------------------------------------------------------
// DATARMNETd52d50282d @ 0010734c size=324
// signature: undefined DATARMNETd52d50282d(void)
// callers: [DATARMNET283f08f439]
//------------------------------------------------------------

void DATARMNETd52d50282d(undefined8 param_1)

{
  bool bVar1;
  int iVar2;
  long *plVar3;
  undefined **ppuVar4;
  undefined *puVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  
  _raw_spin_lock_bh(&DATARMNETd83ee17944);
  uVar7 = 0;
  do {
    lVar6 = (&DATARMNET5750992efb)[uVar7] + -0x10;
    if ((&DATARMNET5750992efb)[uVar7] != 0 && lVar6 != 0) {
      do {
        lVar8 = *(long *)(lVar6 + 0x10);
        iVar2 = DATARMNET8fc45abdc4(lVar6,param_1);
        if (iVar2 != 0) {
          plVar3 = *(long **)(lVar6 + 0x18);
          if (plVar3 != (long *)0x0) {
            *plVar3 = lVar8;
            if (lVar8 != 0) {
              *(long **)(lVar8 + 8) = plVar3;
            }
            *(undefined8 *)(lVar6 + 0x18) = 0;
          }
          kfree(lVar6);
          goto LAB_001073ec;
        }
      } while ((lVar8 != 0) && (lVar6 = lVar8 + -0x10, lVar6 != 0));
    }
    bVar1 = uVar7 < 0x1ff;
    uVar7 = uVar7 + 1;
  } while (bVar1);
LAB_001073ec:
  _raw_spin_unlock_bh(&DATARMNETd83ee17944);
  _raw_spin_lock_bh(&DATARMNETfbdbab2ef6);
  ppuVar4 = (undefined **)DATARMNET9825511866;
  if ((undefined **)DATARMNET9825511866 != &DATARMNET9825511866) {
    do {
      puVar5 = ppuVar4[2];
      if ((puVar5 != (undefined *)0x0) && (puVar5[0xdb] == '\0')) {
        puVar5[0xdb] = 2;
      }
      ppuVar4 = (undefined **)*ppuVar4;
    } while (ppuVar4 != &DATARMNET9825511866);
  }
  _raw_spin_unlock_bh(&DATARMNETfbdbab2ef6);
  kfree(param_1);
  DATARMNETecc0627c70[0x668] = DATARMNETecc0627c70[0x668] + -1;
  DATARMNET75ae82094a = DATARMNET75ae82094a + -1;
  return;
}



//------------------------------------------------------------
// DATARMNET1e918c8e0d @ 00107494 size=320
// signature: undefined DATARMNET1e918c8e0d(void)
// callers: [DATARMNET2ac305d296]
//------------------------------------------------------------

void DATARMNET1e918c8e0d(long param_1)

{
  char cVar1;
  
  _printk(&DAT_00114f1b,*(undefined1 *)(param_1 + 0x4b),*(undefined1 *)(param_1 + 0x48),
          *(undefined1 *)(param_1 + 0x49),*(undefined2 *)(param_1 + 0x46),
          *(undefined2 *)(param_1 + 0x42),*(undefined1 *)(param_1 + 0x4c),
          *(undefined1 *)(param_1 + 0x4e));
  _printk(&DAT_00114fad,*(undefined1 *)(param_1 + 0x4c));
  _printk(&DAT_00114eb8,*(undefined1 *)(param_1 + 0x4a));
  _printk(&DAT_0011514d,*(undefined2 *)(param_1 + 0x44));
  _printk(&DAT_00115364,*(undefined2 *)(param_1 + 0x40));
  _printk(&DAT_001151fc,*(undefined1 *)(param_1 + 0x49));
  _printk(&DAT_00115173,*(undefined1 *)(param_1 + 0x48));
  _printk(&DAT_00115095,*(undefined1 *)(param_1 + 0x4e));
  cVar1 = *(char *)(param_1 + 0x4c);
  if (cVar1 == '\x04') {
    if (*(char *)(param_1 + 0x49) == '\0') {
      return;
    }
    if (*(char *)(param_1 + 0x48) == '\0') {
      return;
    }
    _printk(&DAT_0011502e,*(undefined4 *)(param_1 + 0x20));
    _printk(&DAT_00115389,*(undefined4 *)(param_1 + 0x30));
    cVar1 = *(char *)(param_1 + 0x4c);
  }
  if (((cVar1 == '\x06') && (*(char *)(param_1 + 0x49) != '\0')) &&
     (*(char *)(param_1 + 0x48) != '\0')) {
    _printk(&DAT_00115053,*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x28),
            *(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x20));
    _printk(&DAT_001153b5,*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x38),
            *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x30));
  }
  return;
}



//------------------------------------------------------------
// DATARMNET2ac305d296 @ 001075d8 size=412
// signature: undefined DATARMNET2ac305d296(void)
// callers: [DATARMNET283f08f439]
//------------------------------------------------------------

void DATARMNET2ac305d296(long param_1)

{
  long *plVar1;
  int iVar2;
  undefined4 *puVar3;
  long *plVar4;
  undefined **ppuVar5;
  undefined *puVar6;
  long lVar7;
  long lVar8;
  
  _raw_spin_lock_bh(&DATARMNETd83ee17944);
  lVar8 = 0;
  do {
    lVar7 = (&DATARMNET5750992efb)[lVar8] + -0x10;
    if ((&DATARMNET5750992efb)[lVar8] != 0 && lVar7 != 0) {
      do {
        iVar2 = DATARMNET8fc45abdc4(lVar7,param_1);
        if (iVar2 != 0) {
          kfree(param_1);
          puVar3 = &DATARMNETd83ee17944;
          goto LAB_00107660;
        }
      } while ((*(long *)(lVar7 + 0x10) != 0) &&
              (lVar7 = *(long *)(lVar7 + 0x10) + -0x10, lVar7 != 0));
    }
    lVar8 = lVar8 + 1;
  } while (lVar8 != 0x200);
  if (DATARMNETecc0627c70[0x668] < 100) {
    DATARMNETecc0627c70[0x668] = DATARMNETecc0627c70[0x668] + 1;
    DATARMNET75ae82094a = DATARMNET75ae82094a + 1;
    if (DATARMNET756bdd424a != 0) {
      DATARMNET1e918c8e0d(param_1);
    }
    plVar1 = &DATARMNET5750992efb + ((uint)(*(int *)(param_1 + 0x30) * 0x61c88647) >> 0x17);
    lVar8 = *plVar1;
    plVar4 = (long *)(param_1 + 0x10);
    *plVar4 = lVar8;
    if (lVar8 != 0) {
      *(long **)(lVar8 + 8) = plVar4;
    }
    *plVar1 = (long)plVar4;
    *(long **)(param_1 + 0x18) = plVar1;
    _raw_spin_unlock_bh(&DATARMNETd83ee17944);
    _raw_spin_lock_bh(&DATARMNETfbdbab2ef6);
    ppuVar5 = (undefined **)DATARMNET9825511866;
    if ((undefined **)DATARMNET9825511866 != &DATARMNET9825511866) {
      do {
        puVar6 = ppuVar5[2];
        if ((puVar6 != (undefined *)0x0) && (puVar6[0xdb] == '\0')) {
          puVar6[0xdb] = 2;
        }
        ppuVar5 = (undefined **)*ppuVar5;
      } while (ppuVar5 != &DATARMNET9825511866);
    }
    puVar3 = (undefined4 *)&DATARMNETfbdbab2ef6;
LAB_00107660:
    _raw_spin_unlock_bh(puVar3);
  }
  else {
    kfree(param_1);
    _raw_spin_unlock_bh(&DATARMNETd83ee17944);
    DAT_0011db18 = DAT_0011db18 + 1;
  }
  return;
}



//------------------------------------------------------------
// DATARMNET337eca0417 @ 00107778 size=112
// signature: undefined DATARMNET337eca0417(void)
// callers: []
//------------------------------------------------------------

void DATARMNET337eca0417(long param_1,long param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  if (*(ushort *)(param_2 + 0xd0) == 0) {
    uVar1 = DATARMNETecc0627c70[0x671];
    if (DATARMNETecc0627c70[0x670] == '\0') {
      return;
    }
  }
  else {
    uVar1 = *(undefined1 *)(param_2 + 0xd2);
    if ((*(ushort *)(param_2 + 0xd0) & 0xff) == 0) {
      return;
    }
  }
  uVar2 = DATARMNET8532ab3089(*(undefined2 *)(param_2 + 0xcc),uVar1,*(undefined4 *)(param_2 + 0xc0),
                              0);
  *(undefined4 *)(param_1 + 0x94) = uVar2;
  return;
}



//------------------------------------------------------------
// DATARMNETf5821256ad @ 001077ec size=1268
// signature: undefined DATARMNETf5821256ad(void)
// callers: [DATARMNET756778f14f]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNETf5821256ad(long param_1,ushort *param_2)

{
  undefined1 *puVar1;
  ushort uVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  byte bVar6;
  byte bVar7;
  code *pcVar8;
  undefined2 uVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  long lVar13;
  undefined1 uVar14;
  uint uVar15;
  long *plVar16;
  long *plVar17;
  ulong uVar18;
  long lVar19;
  ulong uVar20;
  undefined8 uVar21;
  
  bVar6 = DATARMNETecc0627c70[0x670];
  iVar5 = DATARMNET3874292c18;
  DATARMNETefe3dcad0a = DATARMNETefe3dcad0a + 1;
  if ((*(byte *)(param_1 + 0x81) & 3) == 0) {
    __skb_get_hash(param_1);
  }
  iVar12 = *(int *)(param_1 + 0x94);
  if (((*param_2 & 1) == 0) && (iVar10 = DATARMNETf4aefff4c2(param_1), iVar10 == 0))
  goto LAB_00107ca0;
  _raw_spin_lock_bh(&DATARMNETd83ee17944);
  iVar10 = DATARMNET3874292c18;
  for (plVar16 = (long *)(&DATARMNET58fe8ac797)[(uint)(iVar12 * 0x61c88647) >> 0x17];
      (plVar16 != (long *)0x0 && (lVar13 = (long)(plVar16 + -0x10), lVar13 != 0));
      plVar16 = (long *)*plVar16) {
    if (iVar12 == *(int *)(plVar16 + 8)) {
      *(short *)((long)plVar16 + 0x4e) = (short)DATARMNET3874292c18;
      uVar9 = DATARMNET04e8d1b862(iVar10,bVar6);
      *(undefined2 *)((long)plVar16 + 0x4c) = uVar9;
      goto LAB_00107a38;
    }
  }
  if (iVar5 < 0) {
    plVar16 = &DAT_0011da98;
  }
  else if ((long)DATARMNETecc0627c70._1632_8_ < 0x2bd) {
    lVar13 = kmalloc_trace(_rmnet_module_hook_perf_ingress,0xb20,0xe0);
    bVar7 = DATARMNETecc0627c70[0x670];
    if (lVar13 != 0) {
      Hint_Prefetch(0x11caf8,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(0x11caf8,0x10);
        if (bVar4) {
          cVar3 = ExclusiveMonitorsStatus();
          DATARMNETecc0627c70._1632_8_ = DATARMNETecc0627c70._1632_8_ + 1;
        }
      } while (cVar3 != '\0');
      uVar2 = param_2[1];
      uVar21 = *(undefined8 *)(param_1 + 0x10);
      *(short *)(lVar13 + 0xce) = (short)iVar5;
      uVar11 = *(undefined4 *)(param_1 + 0x94);
      *(ushort *)(lVar13 + 0xd0) = uVar2;
      *(ushort *)(lVar13 + 0xd2) = (ushort)bVar7;
      *(undefined8 *)(lVar13 + 0x50) = uVar21;
      *(undefined4 *)(lVar13 + 0xc0) = uVar11;
      *(undefined1 *)(lVar13 + 0xdb) = 1;
      uVar9 = DATARMNET04e8d1b862(iVar5,bVar6);
      *(undefined2 *)(lVar13 + 0xcc) = uVar9;
      lVar19 = tpidr_el1;
      uVar11 = *(undefined4 *)(&cpu_number + lVar19);
      *(short *)(lVar13 + 0xce) = (short)uVar11;
      uVar9 = DATARMNET04e8d1b862(uVar11,bVar6);
      *(undefined2 *)(lVar13 + 0xcc) = uVar9;
      *(long *)(lVar13 + 0x40) = lVar13 + 0x40;
      *(long *)(lVar13 + 0x48) = lVar13 + 0x40;
      DATARMNET44459105b4(param_1,lVar13);
      DATARMNET350f55bfca(lVar13);
      uVar2 = *(ushort *)(lVar13 + 0xce);
      if (8 < (ulong)uVar2) goto LAB_00107ccc;
      puVar1 = (undefined1 *)(*(long *)(lVar13 + 0x50) + 0xa40);
      if (puVar1 == (undefined1 *)0x0) {
        DATARMNET68d84e7b98 = DATARMNET68d84e7b98 + 1;
      }
      else {
        *(undefined1 *)(*(long *)(lVar13 + 0x58) + 0x13b) = *puVar1;
      }
      DATARMNET3e37ad2816(lVar13,&DATARMNET148e775ece + (ulong)uVar2 * 5);
      plVar16 = &DATARMNET58fe8ac797 + ((uint)(*(int *)(param_1 + 0x94) * 0x61c88647) >> 0x17);
      lVar19 = *plVar16;
      plVar17 = (long *)(lVar13 + 0x80);
      *plVar17 = lVar19;
      *(long **)(lVar13 + 0x88) = plVar16;
      *plVar16 = (long)plVar17;
      if (lVar19 != 0) {
        *(long **)(lVar19 + 8) = plVar17;
      }
LAB_00107a38:
      _raw_spin_unlock_bh(&DATARMNETd83ee17944);
      if (*(ushort *)(lVar13 + 0xd0) == 0) {
        uVar14 = DATARMNETecc0627c70[0x671];
        if (DATARMNETecc0627c70[0x670] != 0) goto LAB_00107a58;
      }
      else {
        uVar14 = *(undefined1 *)(lVar13 + 0xd2);
        if ((*(ushort *)(lVar13 + 0xd0) & 0xff) != 0) {
LAB_00107a58:
          uVar11 = DATARMNET8532ab3089(*(undefined2 *)(lVar13 + 0xcc),uVar14,
                                       *(undefined4 *)(lVar13 + 0xc0),0);
          *(undefined4 *)(param_1 + 0x94) = uVar11;
        }
      }
      cVar3 = *(char *)(lVar13 + 0xdc);
      if (cVar3 == '\0') {
        lVar19 = tpidr_el1;
        iVar12 = DATARMNET362b15f941(*(undefined4 *)(&cpu_number + lVar19));
        if (iVar12 == 0) {
          cVar3 = *(char *)(lVar13 + 0xdc);
          goto joined_r0x00107ba8;
        }
        lVar19 = tpidr_el1;
        uVar15 = *(uint *)(&cpu_number + lVar19);
        if (0x1f < uVar15) goto LAB_00107ccc;
        if (((uint)(*(int *)(__rcu_read_unlock + *(long *)(&__per_cpu_offset + (ulong)uVar15 * 8)) +
                   *(int *)(__sw_hweight64 + *(long *)(&__per_cpu_offset + (ulong)uVar15 * 8))) <
             0x14) && (iVar12 = DATARMNETdc7bead533((ulong)uVar15,4000), iVar12 != 0)) {
LAB_00107b64:
          *(undefined4 *)(param_1 + 0x94) = 0;
          *(ushort *)(param_1 + 0x80) = *(ushort *)(param_1 + 0x80) | 0x200;
        }
        else if (*(char *)(lVar13 + 0xdc) == '\0') {
          uVar14 = 1;
          goto LAB_00107b84;
        }
      }
      else {
joined_r0x00107ba8:
        if (cVar3 != '\x02') {
          lVar19 = tpidr_el1;
          iVar12 = DATARMNET362b15f941(*(undefined4 *)(&cpu_number + lVar19));
          if (iVar12 == 0) {
            lVar19 = tpidr_el1;
            uVar15 = *(uint *)(&cpu_number + lVar19);
            if (0x1f < uVar15) goto LAB_00107ccc;
            if (((uint)(*(int *)(__rcu_read_unlock +
                                *(long *)(&__per_cpu_offset + (ulong)uVar15 * 8)) +
                       *(int *)(__sw_hweight64 + *(long *)(&__per_cpu_offset + (ulong)uVar15 * 8)))
                 < 0x14) && (iVar12 = DATARMNETdc7bead533((ulong)uVar15,12000), iVar12 != 0))
            goto LAB_00107b64;
            uVar14 = 2;
LAB_00107b84:
            *(undefined1 *)(lVar13 + 0xdc) = uVar14;
            *(short *)(lVar13 + 0xce) = (short)iVar5;
            uVar9 = DATARMNET04e8d1b862(iVar5,bVar6);
            *(undefined2 *)(lVar13 + 0xcc) = uVar9;
          }
        }
      }
      uVar20 = (ulong)*(ushort *)(*(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4) + 6);
      if (uVar20 == 0) {
        uVar20 = (ulong)*(ushort *)(lVar13 + 0xce);
        *(long *)(lVar13 + 0x90) = *(long *)(lVar13 + 0x90) + 1;
        if (7 < uVar20) goto LAB_00107ccc;
        uVar15 = 1;
        (&DAT_0011cb44)[uVar20 * 10] = (&DAT_0011cb44)[uVar20 * 10] + 1;
      }
      else {
        uVar18 = (ulong)*(ushort *)(lVar13 + 0xce);
        *(ulong *)(lVar13 + 0x90) = *(long *)(lVar13 + 0x90) + uVar20;
        if (7 < uVar18) {
LAB_00107ccc:
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x107cd0);
          (*pcVar8)();
        }
        (&DAT_0011cb44)[uVar18 * 10] = (&DAT_0011cb44)[uVar18 * 10] + 1;
        uVar15 = (uint)*(ushort *)(*(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4) + 6)
        ;
      }
      *(uint *)(lVar13 + 0x7c) = *(int *)(lVar13 + 0x7c) + uVar15;
      *(long *)(lVar13 + 0x98) = *(long *)(lVar13 + 0x98) + 1;
      *(ulong *)(lVar13 + 0xa8) = *(long *)(lVar13 + 0xa8) + (ulong)*(uint *)(param_1 + 0x2c);
      *(ulong *)(lVar13 + 0xb0) = *(long *)(lVar13 + 0xb0) + (ulong)*(uint *)(param_1 + 0x30);
      if (*(int *)(param_1 + 0x8c) == 0xda1a) {
        *(int *)(lVar13 + 0xb8) = *(int *)(lVar13 + 0xb8) + 1;
      }
      *(ulong *)(lVar13 + 0xa0) = *(long *)(lVar13 + 0xa0) + (ulong)*(uint *)(param_1 + 0x70);
      goto LAB_00107ca0;
    }
    plVar16 = &DAT_0011da38;
  }
  else {
    plVar16 = &DAT_0011da48;
  }
  *plVar16 = *plVar16 + 1;
  _raw_spin_unlock_bh(&DATARMNETd83ee17944);
LAB_00107ca0:
  DATARMNETe767554e6e(param_1);
  return 0;
}



//------------------------------------------------------------
// DATARMNET44499733f2 @ 00107cf4 size=104
// signature: undefined DATARMNET44499733f2(void)
// callers: [DATARMNET45d8cdb224]
//------------------------------------------------------------

void DATARMNET44499733f2(void)

{
  DATARMNET148e775ece = &DATARMNET148e775ece;
  DAT_0011b350 = &DATARMNET148e775ece;
  DAT_0011b370 = &DAT_0011b370;
  DAT_0011b378 = &DAT_0011b370;
  DAT_0011b398 = &DAT_0011b398;
  DAT_0011b3a0 = &DAT_0011b398;
  DAT_0011b3c0 = &DAT_0011b3c0;
  DAT_0011b3c8 = &DAT_0011b3c0;
  DAT_0011b3e8 = &DAT_0011b3e8;
  DAT_0011b3f0 = &DAT_0011b3e8;
  DAT_0011b410 = &DAT_0011b410;
  DAT_0011b418 = &DAT_0011b410;
  DAT_0011b438 = &DAT_0011b438;
  DAT_0011b440 = &DAT_0011b438;
  DAT_0011b460 = &DAT_0011b460;
  DAT_0011b468 = &DAT_0011b460;
  return;
}



//------------------------------------------------------------
// DATARMNET90fe3a4b56 @ 00107d60 size=284
// signature: undefined DATARMNET90fe3a4b56(void)
// callers: [DATARMNET9297340f58, DATARMNET740f3b34b3, DATARMNETe9173bbe0e]
//------------------------------------------------------------

void DATARMNET90fe3a4b56(void)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  long lVar4;
  
  _raw_spin_lock_bh(&DATARMNETd83ee17944);
  lVar3 = 0;
  do {
    lVar4 = (&DATARMNET58fe8ac797)[lVar3] + -0x10;
    if ((&DATARMNET58fe8ac797)[lVar3] != 0 && lVar4 != 0) {
      do {
        lVar1 = *(long *)(lVar4 + 0x10);
        plVar2 = *(long **)(lVar4 + 0x18);
        if (plVar2 != (long *)0x0) {
          *plVar2 = lVar1;
          if (lVar1 != 0) {
            *(long **)(lVar1 + 8) = plVar2;
          }
          *(undefined8 *)(lVar4 + 0x18) = 0;
        }
      } while ((lVar1 != 0) && (lVar4 = lVar1 + -0x10, lVar4 != 0));
    }
    lVar3 = lVar3 + 1;
  } while (lVar3 != 0x200);
  lVar3 = 0;
  do {
    lVar4 = (&DATARMNET5750992efb)[lVar3] + -0x10;
    if ((&DATARMNET5750992efb)[lVar3] != 0 && lVar4 != 0) {
      do {
        lVar1 = *(long *)(lVar4 + 0x10);
        plVar2 = *(long **)(lVar4 + 0x18);
        if (plVar2 != (long *)0x0) {
          *plVar2 = lVar1;
          if (lVar1 != 0) {
            *(long **)(lVar1 + 8) = plVar2;
          }
          *(undefined8 *)(lVar4 + 0x18) = 0;
        }
        kfree();
        DATARMNETecc0627c70[0x668] = DATARMNETecc0627c70[0x668] + -1;
        DATARMNET75ae82094a = DATARMNET75ae82094a + -1;
      } while ((lVar1 != 0) && (lVar4 = lVar1 + -0x10, lVar4 != 0));
    }
    lVar3 = lVar3 + 1;
  } while (lVar3 != 0x200);
  _raw_spin_unlock_bh(&DATARMNETd83ee17944);
  return;
}



//------------------------------------------------------------
// DATARMNET713da9913c @ 00107e9c size=392
// signature: undefined DATARMNET713da9913c(void)
// callers: [DATARMNET765b8ecfba, DATARMNET02fc8b29a0]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET713da9913c(long param_1,ulong param_2)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  byte bVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  uint uVar8;
  undefined4 *puVar9;
  ulong local_40 [2];
  
  lVar7 = sp_el0;
  local_40[1] = *(long *)(lVar7 + 0x638);
  local_40[0] = 0;
  puVar9 = *(undefined4 **)(param_1 + 0x40);
  if (puVar9 == (undefined4 *)0x0) {
    puVar1 = local_40 + ((param_2 & 0xffffffff) >> 6 & 3);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 1L << (param_2 & 0x3f);
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    iVar5 = __bitmap_weight(local_40,_nr_cpu_ids);
    uVar8 = iVar5 * 2 + 0x18;
    if (uVar8 < 0x41) {
      uVar8 = 0x40;
    }
    puVar9 = (undefined4 *)__kmalloc(uVar8,0xb20);
    bVar4 = DATARMNETecc0627c70[0x689];
    if (puVar9 == (undefined4 *)0x0) {
      uVar6 = 0xfffffffffffffff4;
    }
    else {
      *(ushort *)(puVar9 + 6) = (ushort)param_2 & 0xff;
      *puVar9 = 1;
      lVar7 = 0x40;
      if ((bVar4 >> (ulong)((uint)param_2 & 0x1f) & 1) != 0) {
        lVar7 = 0x48;
      }
      *(long *)((long)&DATARMNETb7ddf3c5dd + lVar7) =
           *(long *)((long)&DATARMNETb7ddf3c5dd + lVar7) + 1;
      __rcu_read_lock();
      lVar7 = *(long *)(param_1 + 0x40);
      *(long *)(param_1 + 0x40) = (long)puVar9;
      if (lVar7 != 0) {
        kfree();
      }
      __rcu_read_unlock();
      uVar6 = 0;
    }
  }
  else {
    *(ushort *)(puVar9 + 6) = (ushort)param_2 & 0xff;
    *puVar9 = 1;
    if ((DATARMNETecc0627c70[0x689] >> (ulong)((uint)param_2 & 0x1f) & 1) == 0) {
      uVar6 = 0;
      DAT_0011d8d0 = DAT_0011d8d0 + 1;
    }
    else {
      uVar6 = 0;
      DAT_0011d8d8 = DAT_0011d8d8 + 1;
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_40[1]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET9303cec796 @ 00108034 size=1060
// signature: undefined DATARMNET9303cec796(void)
// callers: [DATARMNET756778f14f]
//------------------------------------------------------------

undefined8 DATARMNET9303cec796(long param_1,undefined1 *param_2)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  byte *pbVar5;
  undefined8 uVar6;
  undefined1 auVar7 [16];
  int local_10c;
  undefined2 local_108 [4];
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined4 local_f0;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_f0 = 0;
  local_100 = 0;
  uStack_f8 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_80 = 0;
  local_108[0] = 0;
  local_10c = 0;
  iVar2 = rmnet_module_hook_perf_ingress(&local_10c,param_1);
  if ((iVar2 != 0) && (uVar6 = 0, local_10c == 0)) goto LAB_001084a0;
  if (*(short *)(param_1 + 0xb4) == -0x227a) {
    lVar3 = DATARMNETefcaf5fbe9(param_1,0,0x28,&local_80);
    if (lVar3 != 0) {
      bVar1 = *(byte *)(lVar3 + 6);
      if (bVar1 < 0x2c) {
        uVar6 = 1;
        if ((bVar1 == 6) || (bVar1 == 0x11)) goto LAB_001084a0;
      }
      else if (bVar1 == 0x2c) {
        if (((*(uint *)(param_1 + 0x70) & 0xfffffffe) != 0x28) &&
           (pbVar5 = (byte *)skb_header_pointer(param_1,local_108), pbVar5 != (byte *)0x0)) {
          bVar1 = *pbVar5;
          goto joined_r0x001082a8;
        }
      }
      else {
        if (bVar1 == 0x32) goto LAB_001082ac;
        if (bVar1 == 0x3a) {
          *(undefined4 *)(param_1 + 0x94) = 0;
          *(ushort *)(param_1 + 0x80) = *(ushort *)(param_1 + 0x80) | 0x200;
          ktime_get_with_offset(1);
          auVar7 = ns_to_timespec64();
          uVar6 = DATARMNETecc0627c70._1656_8_;
          lVar3 = 0x7fffffffffffffff;
          if (auVar7._0_8_ < 0x225c17d04) {
            lVar3 = auVar7._8_8_ + auVar7._0_8_ * 1000000000;
          }
          uVar4 = hrtimer_active(0x11c528);
          if ((uVar4 & 1) == 0) {
            hrtimer_start_range_ns(0x11c528,1200000000,0,3);
            __pm_stay_awake(DATARMNETecc0627c70._1664_8_);
          }
          else {
            hrtimer_cancel(0x11c528);
            hrtimer_start_range_ns(0x11c528,1200000000,0,3);
          }
          DATARMNET064fbe9e3a = 2;
          uVar4 = hrtimer_active(0x11c4e0);
          if (((uVar4 & 1) == 0) &&
             ((hrtimer_start_range_ns(0x11c4e0,950000000,0,3), lVar3 - uVar6 < 201000000 ||
              (DATARMNETecc0627c70._1656_8_ == 0)))) {
            *param_2 = 1;
          }
          else {
            DATARMNET930a441406 = DATARMNET930a441406 + 1;
          }
        }
      }
    }
  }
  else if ((*(short *)(param_1 + 0xb4) == 8) &&
          (lVar3 = DATARMNETefcaf5fbe9(param_1,0,0x14,&local_100), lVar3 != 0)) {
    bVar1 = *(byte *)(lVar3 + 9);
    if ((*(ushort *)(lVar3 + 6) & 0xff3f) == 0) {
      uVar6 = 1;
      if (bVar1 < 0x11) {
        if (bVar1 == 1) goto LAB_001081f0;
        if (bVar1 == 6) goto LAB_001084a0;
      }
      else {
        if (bVar1 == 0x11) goto LAB_001084a0;
joined_r0x001082a8:
        if (bVar1 == 0x32) goto LAB_001082ac;
      }
    }
    else {
      if (bVar1 == 0x32) {
LAB_001082ac:
        uVar6 = 0;
        *(undefined4 *)(param_1 + 0x94) = 0xaaaaaa;
        DATARMNETcb9ef310a4 = DATARMNETcb9ef310a4 + 1;
        *(ushort *)(param_1 + 0x80) = *(ushort *)(param_1 + 0x80) | 0x200;
        goto LAB_001084a0;
      }
      if (bVar1 == 1) {
LAB_001081f0:
        *(undefined4 *)(param_1 + 0x94) = 0;
        *(ushort *)(param_1 + 0x80) = *(ushort *)(param_1 + 0x80) | 0x200;
        ktime_get_with_offset(1);
        auVar7 = ns_to_timespec64();
        uVar6 = DATARMNETecc0627c70._1656_8_;
        lVar3 = 0x7fffffffffffffff;
        if (auVar7._0_8_ < 0x225c17d04) {
          lVar3 = auVar7._8_8_ + auVar7._0_8_ * 1000000000;
        }
        uVar4 = hrtimer_active(0x11c528);
        if ((uVar4 & 1) == 0) {
          hrtimer_start_range_ns(0x11c528,1200000000,0,3);
          __pm_stay_awake(DATARMNETecc0627c70._1664_8_);
        }
        else {
          hrtimer_cancel(0x11c528);
          hrtimer_start_range_ns(0x11c528,1200000000,0,3);
        }
        DATARMNET064fbe9e3a = 2;
        uVar4 = hrtimer_active(0x11c4e0);
        if (((uVar4 & 1) == 0) &&
           ((hrtimer_start_range_ns(0x11c4e0,950000000,0,3), lVar3 - uVar6 < 201000000 ||
            (DATARMNETecc0627c70._1656_8_ == 0)))) {
          *param_2 = 1;
        }
        else {
          DATARMNET930a441406 = DATARMNET930a441406 + 1;
        }
      }
    }
  }
  uVar6 = 0;
LAB_001084a0:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// trace_print_icmp_rx @ 00108614 size=36
// signature: undefined trace_print_icmp_rx(void)
// callers: []
//------------------------------------------------------------

void trace_print_icmp_rx(void)

{
  return;
}



//------------------------------------------------------------
// skb_header_pointer @ 001086b4 size=96
// signature: undefined skb_header_pointer(void)
// callers: [DATARMNET9303cec796]
//------------------------------------------------------------

long skb_header_pointer(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  
  if ((*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x74)) + -0x28 < 2) {
    lVar2 = 0;
    if (param_1 != 0) {
      iVar1 = skb_copy_bits(param_1,0x28,param_2,2);
      lVar2 = 0;
      if (-1 < iVar1) {
        lVar2 = param_2;
      }
    }
  }
  else {
    lVar2 = *(long *)(param_1 + 0xe0) + 0x28;
  }
  return lVar2;
}



//------------------------------------------------------------
// trace_rmnet_shs_low @ 00108714 size=44
// signature: undefined trace_rmnet_shs_low(void)
// callers: [DATARMNET756778f14f]
//------------------------------------------------------------

void trace_rmnet_shs_low(void)

{
  return;
}



//------------------------------------------------------------
// DATARMNETe767554e6e @ 001087c8 size=68
// signature: undefined DATARMNETe767554e6e(void)
// callers: [DATARMNETf5821256ad, DATARMNETcba2f7f7b6, DATARMNET756778f14f, DATARMNET23c7ddd780]
//------------------------------------------------------------

void DATARMNETe767554e6e(undefined8 param_1)

{
  netif_receive_skb(param_1);
  return;
}



//------------------------------------------------------------
// DATARMNET514ce0bf59 @ 001088a0 size=68
// signature: undefined DATARMNET514ce0bf59(void)
// callers: [DATARMNETcba2f7f7b6, DATARMNET23c7ddd780]
//------------------------------------------------------------

void DATARMNET514ce0bf59(undefined8 param_1)

{
  netif_rx(param_1);
  return;
}



//------------------------------------------------------------
// DATARMNET2efb1a51c7 @ 00108978 size=72
// signature: undefined DATARMNET2efb1a51c7(void)
// callers: []
//------------------------------------------------------------

int DATARMNET2efb1a51c7(long param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(long *)(param_1 + 0x58) + 0x11c);
  return (uVar1 & 1) + (uVar1 >> 1 & 1) + (uVar1 >> 2 & 1) + (uVar1 >> 3 & 1) +
         (uVar1 >> 4 & 1) + (uVar1 >> 5 & 1) + (uVar1 >> 6 & 1) + (uVar1 >> 7 & 1);
}



//------------------------------------------------------------
// DATARMNET762cfa52fe @ 001089c4 size=564
// signature: undefined DATARMNET762cfa52fe(void)
// callers: [DATARMNET756778f14f, DATARMNET6af33ebb5b]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 DATARMNET762cfa52fe(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  if ((param_1 & 1) == 0) {
    uVar3 = 0xffffffff;
    iVar4 = -1;
  }
  else {
    if ((undefined8 **)DATARMNET0997c5650d == &DATARMNET0997c5650d) {
      return 0;
    }
    uVar3 = 0;
    iVar4 = DATARMNETcff375d916;
  }
  if (((param_1 & 0xff) >> 1 & 1) == 0) {
  }
  else {
    if ((undefined8 **)DAT_0011cb50 == &DAT_0011cb50) {
      return 1;
    }
    if (iVar4 == -1 || DAT_0011cc6c <= iVar4) {
      uVar3 = 1;
      iVar4 = DAT_0011cc6c;
    }
  }
  if (((param_1 & 0xff) >> 2 & 1) == 0) {
    iVar1 = iVar4;
    uVar2 = uVar3;
  }
  else {
    if ((undefined8 **)DAT_0011cb78 == &DAT_0011cb78) {
      return 2;
    }
    iVar1 = _DAT_0011cc70;
    uVar2 = 2;
    if (iVar4 != -1 && iVar4 < _DAT_0011cc70) {
      iVar1 = iVar4;
      uVar2 = uVar3;
    }
  }
  if (((param_1 & 0xff) >> 3 & 1) == 0) {
    iVar4 = iVar1;
    uVar3 = uVar2;
  }
  else {
    if ((undefined8 **)DAT_0011cba0 == &DAT_0011cba0) {
      return 3;
    }
    iVar4 = _DAT_0011cc74;
    uVar3 = 3;
    if (iVar1 != -1 && iVar1 < _DAT_0011cc74) {
      iVar4 = iVar1;
      uVar3 = uVar2;
    }
  }
  if (((param_1 & 0xff) >> 4 & 1) == 0) {
    iVar1 = iVar4;
    uVar2 = uVar3;
  }
  else {
    if ((undefined8 **)DAT_0011cbc8 == &DAT_0011cbc8) {
      return 4;
    }
    iVar1 = _DAT_0011cc78;
    uVar2 = 4;
    if (iVar4 != -1 && iVar4 < _DAT_0011cc78) {
      iVar1 = iVar4;
      uVar2 = uVar3;
    }
  }
  if (((param_1 & 0xff) >> 5 & 1) == 0) {
    iVar4 = iVar1;
    uVar3 = uVar2;
  }
  else {
    if ((undefined8 **)DAT_0011cbf0 == &DAT_0011cbf0) {
      return 5;
    }
    iVar4 = _DAT_0011cc7c;
    uVar3 = 5;
    if (iVar1 != -1 && iVar1 < _DAT_0011cc7c) {
      iVar4 = iVar1;
      uVar3 = uVar2;
    }
  }
  if (((param_1 & 0xff) >> 6 & 1) == 0) {
    iVar1 = iVar4;
    uVar2 = uVar3;
  }
  else {
    if ((undefined8 **)DAT_0011cc18 == &DAT_0011cc18) {
      return 6;
    }
    iVar1 = _DAT_0011cc80;
    uVar2 = 6;
    if (iVar4 != -1 && iVar4 < _DAT_0011cc80) {
      iVar1 = iVar4;
      uVar2 = uVar3;
    }
  }
  if ((param_1 >> 7 & 1) == 0) {
    return uVar2;
  }
  if ((undefined8 **)DAT_0011cc40 == &DAT_0011cc40) {
    return 7;
  }
  uVar3 = 7;
  if (iVar1 < _DAT_0011cc84 && iVar1 != -1) {
    uVar3 = uVar2;
  }
  return uVar3;
}



//------------------------------------------------------------
// DATARMNET6af33ebb5b @ 00108bfc size=484
// signature: undefined DATARMNET6af33ebb5b(void)
// callers: [DATARMNETb6bff4a724]
//------------------------------------------------------------

ulong DATARMNET6af33ebb5b(long param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  int iVar8;
  ulong uVar9;
  uint uVar10;
  uint uVar11;
  
  if (*(char *)(param_1 + 0xd4) == '\0') {
    uVar9 = (ulong)*(ushort *)(param_1 + 0xce);
    if (7 < uVar9) {
LAB_00108dd8:
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x108ddc);
      (*pcVar7)();
    }
    if (0x11c < uVar9 * 0x28) {
LAB_00108ddc:
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(1,0x108de0);
      (*pcVar7)();
    }
    if (((&DAT_0011cb4c)[uVar9 * 0x28] == '\0') || (iVar8 = DATARMNET362b15f941(), iVar8 == 0)) {
      if (*(long *)(param_1 + 0x58) == 0) {
        uVar9 = 0xffffffff;
      }
      else {
        uVar2 = *(ushort *)(param_1 + 0xce);
        uVar9 = (ulong)uVar2;
        uVar3 = *(ushort *)(*(long *)(param_1 + 0x58) + 0x134);
        uVar4 = 1 << (ulong)(uVar2 & 0x1f);
        uVar6 = DATARMNET121c8bc82a | DATARMNETecc0627c70[0x66f];
        if ((uVar6 & uVar4) == 0) {
          uVar10 = (uint)uVar3;
          uVar5 = 1 << (ulong)(uVar10 & 0x1f);
          if ((uVar5 & DATARMNETecc0627c70[0x66f]) == 0) {
            if (7 < uVar10) goto LAB_00108dd8;
            if (0x11c < (ulong)uVar3 * 0x28) goto LAB_00108ddc;
            uVar4 = (uint)uVar3;
            if ((&DAT_0011cb4c)[(ulong)uVar10 * 0x28] != '\0') {
              uVar4 = (uint)uVar2;
            }
            uVar9 = (ulong)uVar4;
          }
          else {
            uVar10 = (uint)DATARMNETecc0627c70[0x68a];
            if ((uVar5 & DATARMNETecc0627c70[0x689]) != 0) {
              uVar10 = (uint)DATARMNETecc0627c70[0x689];
            }
            uVar11 = (uint)DATARMNETecc0627c70[0x689];
            uVar5 = (uint)DATARMNETecc0627c70[0x68a];
            if ((uVar4 & uVar11) != 0) {
              uVar5 = uVar11;
            }
            if ((uVar10 & (uint)*(ushort *)(param_1 + 0xd0) & (uVar6 ^ 0xffffffff)) != 0) {
              uVar11 = uVar10;
            }
            if (uVar11 != uVar5) {
              uVar9 = DATARMNET762cfa52fe((uint)*(ushort *)(param_1 + 0xd0) &
                                          (DATARMNETecc0627c70[0x66f] ^ 0xffffffff) & uVar11);
            }
          }
        }
        else {
          bVar1 = DATARMNETecc0627c70[0x68a];
          if ((DATARMNETecc0627c70[0x689] >> (ulong)(uVar3 & 0x1f) & 1) != 0) {
            bVar1 = DATARMNETecc0627c70[0x689];
          }
          uVar4 = (uint)DATARMNETecc0627c70[0x689];
          if (((uint)bVar1 & (uVar6 ^ 0xffffffff) & (uint)*(ushort *)(param_1 + 0xd0)) != 0) {
            uVar4 = (uint)bVar1;
          }
          uVar9 = DATARMNET762cfa52fe(uVar4 & (uVar6 ^ 0xffffffff) &
                                      (uint)*(ushort *)(param_1 + 0xd0));
          if ((DATARMNETecc0627c70[0x66f] >> (ulong)(*(ushort *)(param_1 + 0xce) & 0x1f) & 1) != 0)
          {
            DAT_0011d8e0 = DAT_0011d8e0 + 1;
          }
        }
      }
    }
    else {
      uVar9 = DATARMNET762cfa52fe((uint)DATARMNETecc0627c70[0x689] &
                                  ((DATARMNET121c8bc82a | DATARMNETecc0627c70[0x66f]) ^ 0xffffffff)
                                  & (uint)*(ushort *)(param_1 + 0xd0));
      if (((int)uVar9 < 0) && (*(long *)(param_1 + 0x58) != 0)) {
        uVar9 = (ulong)*(ushort *)(*(long *)(param_1 + 0x58) + 0x134);
      }
    }
  }
  else {
    uVar9 = (ulong)DATARMNETecc0627c70[0x672];
  }
  return uVar9;
}



//------------------------------------------------------------
// DATARMNETb6bff4a724 @ 00108de4 size=112
// signature: undefined DATARMNETb6bff4a724(void)
// callers: [DATARMNETe488c1c396]
//------------------------------------------------------------

void DATARMNETb6bff4a724(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = DATARMNET6af33ebb5b();
  iVar1 = DATARMNET04e8d1b862(uVar2,*(undefined1 *)(param_1 + 0xd0));
  if (iVar1 < 0) {
    DATARMNET04e8d1b862(*(undefined1 *)(param_1 + 0xce),*(undefined1 *)(param_1 + 0xd0));
  }
  return;
}



//------------------------------------------------------------
// DATARMNET349c3a0cab @ 00108ee0 size=76
// signature: undefined DATARMNET349c3a0cab(void)
// callers: [DATARMNET3e37ad2816, DATARMNETe102b3a798, DATARMNETde8ee16f92]
//------------------------------------------------------------

void DATARMNET349c3a0cab(ushort param_1,uint param_2)

{
  if (7 < param_1) {
    DAT_0011dac0 = DAT_0011dac0 + 1;
    return;
  }
  if ((param_2 & 1) == 0) {
    (&DATARMNETcff375d916)[param_1] = (&DATARMNETcff375d916)[param_1] + -1;
    return;
  }
  (&DATARMNETcff375d916)[param_1] = (&DATARMNETcff375d916)[param_1] + 1;
  return;
}



//------------------------------------------------------------
// DATARMNETb1157fd5c4 @ 00108f30 size=248
// signature: undefined DATARMNETb1157fd5c4(void)
// callers: [DATARMNETe074a09496]
//------------------------------------------------------------

void DATARMNETb1157fd5c4(byte param_1)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  
  if (7 < param_1) {
    return;
  }
  __rcu_read_lock();
  uVar4 = (ulong)param_1;
  lVar1 = uVar4 + (ulong)param_1 * 4;
  uVar5 = lVar1 * 8;
  if (uVar5 < 0x131) {
    lVar3 = *(long *)(&__per_cpu_offset + uVar4 * 8);
    (&DAT_0011cb38)[lVar1 * 2] = *(int *)(&__tracepoint_rmnet_shs_err + lVar3);
    if (uVar4 * 0x28 < 0x12d) {
      (&DAT_0011cb3c)[uVar4 * 10] = *(undefined4 *)(&DAT_001262ec + lVar3);
      __rcu_read_unlock();
      if ((uVar5 < 0x131) && (uVar4 * 0x28 < 0x129)) {
        *(undefined4 *)(&DAT_0011cb40 + uVar4 * 0x28) =
             (&DAT_0011cb3c)[uVar4 * 10] - (&DAT_0011cb38)[lVar1 * 2];
        return;
      }
    }
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(1,0x109028);
  (*pcVar2)();
}



//------------------------------------------------------------
// DATARMNETe074a09496 @ 001090a8 size=168
// signature: undefined DATARMNETe074a09496(void)
// callers: [DATARMNETe377e0368d, DATARMNET756778f14f, DATARMNETe488c1c396, DATARMNETfbc06e60f1]
//------------------------------------------------------------

void DATARMNETe074a09496(void)

{
  undefined8 uVar1;
  ulong uVar2;
  
  __rcu_read_lock();
  uVar2 = 0;
  uVar1 = sp_el0;
  do {
    if ((*(ulong *)(&__cpu_online_mask + (uVar2 >> 3 & 0x1ffffffffffffff8)) >> (uVar2 & 0x3f) & 1)
        != 0) {
      DATARMNETb1157fd5c4(uVar2 & 0xffffffff);
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 8);
  __rcu_read_unlock();
  return;
}



//------------------------------------------------------------
// DATARMNET765b8ecfba @ 001091bc size=224
// signature: undefined DATARMNET765b8ecfba(void)
// callers: []
//------------------------------------------------------------

void DATARMNET765b8ecfba(long param_1,uint param_2)

{
  undefined1 uVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 local_a0;
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
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
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
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = 0;
  uVar2 = rmnet_is_real_dev_registered();
  if ((int)uVar2 == 0) {
    DAT_0011dae0 = DAT_0011dae0 + 1;
  }
  else {
    lVar3 = DATARMNET713da9913c(*(undefined8 *)(param_1 + 0x308),param_2);
    uVar1 = DATARMNETecc0627c70[0x676];
    if (lVar3 == 0) {
      DATARMNETecc0627c70[0x66f] = (undefined1)(1 << (ulong)(param_2 & 0x1f));
      DATARMNETecc0627c70[0x673] = DATARMNETecc0627c70[0x676];
      DATARMNETecc0627c70[0x676] = (char)param_2;
      DATARMNET1d4b1eff85(&local_a0,uVar1,param_2);
      DATARMNETb5d58adbe7(&local_a0);
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// DATARMNETe488c1c396 @ 001092a0 size=1000
// signature: undefined DATARMNETe488c1c396(void)
// callers: [DATARMNETe02152c351]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNETe488c1c396(long param_1,byte param_2)

{
  uint uVar1;
  int iVar2;
  undefined1 uVar3;
  ushort uVar4;
  undefined2 uVar5;
  code *pcVar6;
  bool bVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  ushort uVar13;
  ulong uVar14;
  long *plVar15;
  uint uVar16;
  long lVar17;
  uint uVar18;
  ulong uVar19;
  
  uVar4 = *(ushort *)(param_1 + 0xd0);
  uVar8 = DATARMNETb6bff4a724();
  uVar13 = *(ushort *)(param_1 + 0xce);
  if (((int)uVar8 < 0) || (*(undefined1 *)(param_1 + 0xda) = 1, (uVar4 & 0xff) == 0)) {
    *(undefined1 *)(param_1 + 0xda) = 0;
    return 1;
  }
  if (uVar8 == *(ushort *)(param_1 + 0xcc)) {
    return 1;
  }
  if (*(char *)(param_1 + 0xd4) != '\0') {
    uVar13 = (ushort)DATARMNETecc0627c70[0x676];
  }
  uVar9 = DATARMNETadb0248bd4(uVar13);
  iVar2 = *(int *)(param_1 + 0xbc);
  uVar13 = *(ushort *)(param_1 + 0xce);
  uVar19 = (ulong)uVar13;
  if (*(char *)(param_1 + 0xd4) == '\0') {
    if ((param_2 < 4) && (uVar9 < iVar2 + (uint)*(ushort *)(param_1 + 0xd6))) {
      iVar10 = DATARMNETeea3cef5b6(uVar19);
      if (iVar10 != 0) {
        return 0;
      }
      bVar7 = _DAT_0011d9a0 == -1;
      _DAT_0011d9a0 = _DAT_0011d9a0 + 1;
      if (bVar7) {
        return 0;
      }
    }
  }
  else if (param_2 == 0) {
    return 0;
  }
  if (DATARMNETa7909611da == 0) {
    return 1;
  }
  uVar4 = *(ushort *)(param_1 + 0xd0);
  uVar1 = uVar8 & 0xff;
  uVar16 = (uint)uVar4;
  uVar18 = uVar16 & 1;
  if ((uVar8 & 0xff) == 0) {
    uVar18 = 0;
    lVar17 = 0;
    if ((uVar4 & 1) == 0) goto LAB_001093b4;
  }
  else {
LAB_001093b4:
    if ((uVar18 == uVar1) && ((uVar4 & 2) != 0)) {
      lVar17 = 1;
    }
    else {
      uVar18 = uVar18 + ((uVar16 & 2) >> 1);
      if ((uVar18 == uVar1) && ((uVar4 & 4) != 0)) {
        lVar17 = 2;
      }
      else {
        uVar18 = uVar18 + ((uVar16 & 4) >> 2);
        if ((uVar18 == uVar1) && ((uVar4 & 8) != 0)) {
          lVar17 = 3;
        }
        else {
          uVar18 = uVar18 + ((uVar16 & 8) >> 3);
          if ((uVar18 == uVar1) && ((uVar4 & 0x10) != 0)) {
            lVar17 = 4;
          }
          else {
            uVar18 = uVar18 + ((uVar16 & 0x10) >> 4);
            if ((uVar18 == uVar1) && ((uVar4 & 0x20) != 0)) {
              lVar17 = 5;
            }
            else {
              uVar18 = uVar18 + ((uVar16 & 0x20) >> 5);
              if ((uVar18 == uVar1) && ((uVar4 & 0x40) != 0)) {
                lVar17 = 6;
              }
              else {
                if ((uVar4 >> 7 & 1) == 0) {
                  return 1;
                }
                if (uVar18 + ((uVar16 & 0x40) >> 6) != uVar1) {
                  return 1;
                }
                lVar17 = 7;
              }
            }
          }
        }
      }
    }
  }
  (&DAT_0011cb44)[lVar17 * 10] = (&DAT_0011cb44)[lVar17 * 10] + *(int *)(param_1 + 0x78);
  uVar14 = (ulong)*(ushort *)(param_1 + 0xce);
  if (7 < uVar14) {
LAB_00109680:
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x109684);
    (*pcVar6)();
  }
  if (uVar14 * 0x28 < 0x125) {
    (&DAT_0011cb44)[uVar14 * 10] = (&DAT_0011cb44)[uVar14 * 10] - *(int *)(param_1 + 0x78);
    *(short *)(param_1 + 0xcc) = (short)uVar8;
    *(short *)(param_1 + 0xce) = (short)lVar17;
    if (uVar9 < iVar2 + (uint)*(ushort *)(param_1 + 0xd6)) {
      DAT_0011d8a0 = DAT_0011d8a0 + 1;
      DAT_0011d8a8 = DAT_0011d8a8 + (ulong)((iVar2 - uVar9) + (uint)*(ushort *)(param_1 + 0xd6));
      DATARMNET4bde88919f(uVar19);
      uVar5 = *(undefined2 *)(param_1 + 0xd6);
      uVar3 = *(undefined1 *)(param_1 + 0xd4);
      uVar11 = DATARMNETeea3cef5b6(uVar19);
      uVar12 = DATARMNETeea3cef5b6(lVar17);
      _printk(&DAT_001154e9,uVar3,lVar17,uVar19,uVar5,iVar2,uVar9,param_2,uVar11,uVar12);
    }
    if (7 < uVar13) goto LAB_00109680;
    if (uVar19 * 0x28 < 0x11d) {
      if ((&DAT_0011cb4c)[uVar19 * 0x28] == '\0') {
        plVar15 = &DAT_0011d898;
        if ((DATARMNET121c8bc82a >> (ulong)(uVar13 & 0x1f) & 1) != 0) {
          plVar15 = &DAT_0011d8f8;
        }
      }
      else {
        (&DAT_0011cb4d)[lVar17 * 0x28] = 1;
        plVar15 = &DATARMNETb7ddf3c5dd;
      }
      uVar19 = (ulong)*(ushort *)(param_1 + 0xce);
      *plVar15 = *plVar15 + 1;
      if (8 < uVar19) goto LAB_00109680;
      DATARMNETe074a09496();
      if (uVar19 * 0x28 < 0x131) {
        *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0x78) + (&DAT_0011cb38)[uVar19 * 10];
        if (*(long *)(param_1 + 0x58) != 0) {
          *(short *)(*(long *)(param_1 + 0x58) + 0x134) = (short)lVar17;
        }
        DATARMNETe102b3a798(param_1,&DATARMNET0997c5650d + uVar19 * 5,(uint)uVar13);
        if (DATARMNET756bdd424a == 0) {
          return 1;
        }
        return 1;
      }
    }
  }
                    /* WARNING: Does not return */
  pcVar6 = (code *)SoftwareBreakpoint(1,0x109688);
  (*pcVar6)();
}



//------------------------------------------------------------
// trace_rmnet_shs_high @ 00109788 size=44
// signature: undefined trace_rmnet_shs_high(void)
// callers: [DATARMNET756778f14f]
//------------------------------------------------------------

void trace_rmnet_shs_high(void)

{
  return;
}



//------------------------------------------------------------
// DATARMNETfbc06e60f1 @ 00109840 size=548
// signature: undefined DATARMNETfbc06e60f1(void)
// callers: [DATARMNET056c939591]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETfbc06e60f1(ulong param_1)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  uint uVar10;
  
  DATARMNETe074a09496();
  _raw_spin_lock_bh(&DATARMNET3764d083f0);
  iVar5 = DATARMNETeb3978575d(param_1 & 0xffffffff);
  uVar6 = (uint)param_1;
  if (7 < (uVar6 & 0xff)) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x109a64);
    (*pcVar4)();
  }
  param_1 = param_1 & 0xff;
  if (param_1 * 0x28 < 0x141) {
    puVar1 = &DATARMNET0997c5650d + param_1 * 5;
    if ((undefined8 *)*puVar1 == puVar1) {
      uVar7 = 0;
      uVar10 = 0;
    }
    else {
      uVar10 = 0;
      uVar7 = 0;
      puVar8 = (undefined8 *)*puVar1;
      do {
        iVar2 = *(int *)(puVar8 + 7);
        puVar9 = (undefined8 *)*puVar8;
        if (iVar2 != 0) {
          iVar3 = *(int *)(puVar8 + 6);
          DATARMNETe02152c351(puVar8 + -8,7,1,0);
          uVar7 = iVar2 + uVar7;
          uVar10 = uVar10 + iVar3;
          if ((uint)*(ushort *)((long)puVar8 + 0x8e) == (uVar6 & 0xff)) {
            iVar5 = iVar2 + iVar5;
            *(int *)((long)puVar8 + 0x7c) = iVar5;
          }
        }
        puVar8 = puVar9;
      } while (puVar9 != puVar1);
    }
    DATARMNETecc0627c70._1616_8_ = DATARMNETecc0627c70._1616_8_ - (ulong)uVar10;
    DATARMNETecc0627c70._1624_8_ = DATARMNETecc0627c70._1624_8_ - (ulong)uVar7;
    if (((param_1 * 0x28 < 0x11d) && ((&DAT_0011cb4c)[param_1 * 0x28] = 0, param_1 * 0x90 < 0x479))
       && (*(undefined4 *)(DATARMNETecc0627c70 + param_1 * 0x90 + 0x218) = 0, param_1 * 0x28 < 0x125
          )) {
      (&DAT_0011cb44)[param_1 * 10] = 0;
      _raw_spin_unlock_bh(&DATARMNET3764d083f0);
      if (((uint)DATARMNETecc0627c70[0x673] == (uVar6 & 0xff)) && (_rmnet_shs_switch != 0)) {
        _rmnet_shs_switch = 0;
        rmnet_module_hook_unregister_no_sync(DATARMNET28a9685974,1);
        DATARMNETecc0627c70._1652_2_ = 0;
        DATARMNETecc0627c70[0x673] = DATARMNETecc0627c70[0x676];
      }
      return;
    }
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(1,0x109a60);
  (*pcVar4)();
}



//------------------------------------------------------------
// DATARMNETe02152c351 @ 00109b60 size=740
// signature: undefined DATARMNETe02152c351(void)
// callers: [DATARMNETe377e0368d, DATARMNETfbc06e60f1]
//------------------------------------------------------------

bool DATARMNETe02152c351(long param_1,uint param_2,ulong param_3,ulong param_4,ulong param_5)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  uint uVar6;
  undefined2 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  bVar1 = *(byte *)(param_1 + 0xd0);
  uVar5 = param_4;
  if (DATARMNET756bdd424a != 0) {
    uVar5 = (ulong)(param_2 & 0xff);
    param_5 = (ulong)((uint)param_3 & 0xff);
  }
  uVar8 = bVar1 & 1;
  bVar2 = *(byte *)(param_1 + 0xcc);
  uVar9 = (uint)bVar1;
  uVar3 = uVar8;
  if (bVar2 == 0) {
    uVar3 = 0;
    uVar6 = 0;
    if ((bVar1 & 1) == 0) goto LAB_00109bc8;
  }
  else {
LAB_00109bc8:
    if ((uVar3 == bVar2) && ((bVar1 & 2) != 0)) {
      uVar6 = 1;
    }
    else {
      uVar3 = uVar3 + ((bVar1 & 2) >> 1);
      uVar10 = (uint)bVar1;
      uVar6 = (uint)bVar2;
      if ((uVar3 == uVar6) && ((bVar1 & 4) != 0)) {
        uVar6 = 2;
      }
      else {
        uVar3 = uVar3 + ((uVar10 & 4) >> 2);
        if ((uVar3 == uVar6) && ((bVar1 & 8) != 0)) {
          uVar6 = 3;
        }
        else {
          uVar3 = uVar3 + ((uVar10 & 8) >> 3);
          if ((uVar3 == uVar6) && ((bVar1 & 0x10) != 0)) {
            uVar6 = 4;
          }
          else {
            uVar3 = uVar3 + ((uVar10 & 0x10) >> 4);
            if ((uVar3 == uVar6) && ((bVar1 & 0x20) != 0)) {
              uVar6 = 5;
            }
            else {
              uVar3 = uVar3 + ((uVar10 & 0x20) >> 5);
              if ((uVar3 == bVar2) && ((bVar1 & 0x40) != 0)) {
                uVar6 = 6;
              }
              else {
                uVar6 = 7;
                if (uVar3 + ((uVar9 & 0x40) >> 6) != (uint)bVar2 || -1 < (char)bVar1) {
                  uVar6 = 0xffffffff;
                }
              }
            }
          }
        }
      }
    }
  }
  if (uVar6 == *(ushort *)(param_1 + 0xce)) goto LAB_00109ddc;
  uVar3 = DATARMNET04e8d1b862(*(ushort *)(param_1 + 0xce),bVar1,param_3,uVar5,param_5);
  if ((int)uVar3 < 0) {
    uVar7 = 0;
    *(undefined2 *)(param_1 + 0xcc) = 0;
    if ((bVar1 & 1) == 0) {
      if ((bVar1 >> 1 & 1) == 0) {
        if ((bVar1 >> 2 & 1) == 0) {
          if ((bVar1 >> 3 & 1) == 0) {
            if ((bVar1 >> 4 & 1) == 0) {
              if ((bVar1 >> 5 & 1) == 0) {
                if ((bVar1 >> 6 & 1) == 0) {
                  uVar7 = 7;
                  if (-1 < (char)bVar1) {
                    uVar7 = 0xffff;
                  }
                  goto LAB_00109db8;
                }
                goto LAB_00109db4;
              }
              goto LAB_00109dac;
            }
            goto LAB_00109da4;
          }
          goto LAB_00109d9c;
        }
        goto LAB_00109d94;
      }
      goto LAB_00109d8c;
    }
  }
  else {
    uVar6 = uVar3 & 0xff;
    *(short *)(param_1 + 0xcc) = (short)uVar3;
    if (uVar6 == 0) {
      uVar8 = 0;
      uVar7 = 0;
      if ((bVar1 & 1) != 0) goto LAB_00109db8;
    }
    if ((uVar8 == uVar6) && ((bVar1 & 2) != 0)) {
LAB_00109d8c:
      uVar7 = 1;
    }
    else {
      uVar8 = uVar8 + ((uVar9 & 2) >> 1);
      if ((uVar8 == uVar6) && ((bVar1 & 4) != 0)) {
LAB_00109d94:
        uVar7 = 2;
      }
      else {
        uVar8 = uVar8 + ((uVar9 & 4) >> 2);
        if ((uVar8 == uVar6) && ((bVar1 & 8) != 0)) {
LAB_00109d9c:
          uVar7 = 3;
        }
        else {
          uVar8 = uVar8 + ((uVar9 & 8) >> 3);
          if ((uVar8 == uVar6) && ((bVar1 & 0x10) != 0)) {
LAB_00109da4:
            uVar7 = 4;
          }
          else {
            uVar8 = uVar8 + ((uVar9 & 0x10) >> 4);
            if ((uVar8 == uVar6) && ((bVar1 & 0x20) != 0)) {
LAB_00109dac:
              uVar7 = 5;
            }
            else {
              uVar8 = uVar8 + ((uVar9 & 0x20) >> 5);
              if ((uVar8 == uVar6) && ((bVar1 & 0x40) != 0)) {
LAB_00109db4:
                uVar7 = 6;
              }
              else {
                uVar7 = 7;
                if (uVar8 + ((uVar9 & 0x40) >> 6) != uVar6 || -1 < (char)bVar1) {
                  uVar7 = 0xffff;
                }
              }
            }
          }
        }
      }
    }
  }
LAB_00109db8:
  *(undefined2 *)(param_1 + 0xce) = uVar7;
  DAT_0011da98 = DAT_0011da98 + 1;
  param_2 = 1;
LAB_00109ddc:
  iVar4 = DATARMNETe488c1c396(param_1,param_2);
  if (iVar4 != 0) {
    DATARMNETcba2f7f7b6(param_1,param_3 & 0xffffffff,param_4);
  }
  return iVar4 != 0;
}



//------------------------------------------------------------
// DATARMNETa871eeb7e7 @ 00109fc8 size=48
// signature: undefined DATARMNETa871eeb7e7(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETa871eeb7e7(void)

{
  _rmnet_shs_switch = 0;
  rmnet_module_hook_unregister_no_sync(DATARMNET28a9685974,1);
  return;
}



//------------------------------------------------------------
// DATARMNET056c939591 @ 00109ffc size=48
// signature: undefined DATARMNET056c939591(void)
// callers: []
//------------------------------------------------------------

void DATARMNET056c939591(long param_1)

{
  DATARMNETfbc06e60f1(*(undefined1 *)(param_1 + 0x44));
  DAT_0011d978 = DAT_0011d978 + 1;
  return;
}



//------------------------------------------------------------
// DATARMNETcba2f7f7b6 @ 0010a030 size=976
// signature: undefined DATARMNETcba2f7f7b6(void)
// callers: [DATARMNETe02152c351]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETcba2f7f7b6(long param_1,char param_2,long *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 uVar4;
  byte bVar3;
  char cVar5;
  short sVar6;
  undefined2 uVar7;
  code *pcVar8;
  bool bVar9;
  undefined8 *puVar10;
  long lVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  ushort uVar14;
  uint uVar15;
  undefined8 *puVar16;
  undefined8 *puVar17;
  uint uVar18;
  undefined4 local_64;
  
  lVar11 = *(long *)(param_1 + 0x60);
  if (lVar11 != 0) {
    uVar14 = *(ushort *)(param_1 + 0xd0);
    if (uVar14 == 0) {
      uVar14 = (ushort)DATARMNETecc0627c70[0x670];
      uVar4 = DATARMNETecc0627c70[0x671];
    }
    else {
      uVar4 = *(undefined1 *)(param_1 + 0xd2);
    }
    bVar3 = *(byte *)(param_1 + 0xce);
    if (7 < bVar3) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x10a484);
      (*pcVar8)();
    }
    if (0x11a < (ulong)bVar3 * 0x28) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(1,0x10a488);
      (*pcVar8)();
    }
    cVar5 = (&DAT_0011cb4e)[(ulong)(uint)bVar3 * 0x28];
    bVar9 = rmnet_shs_no_sync_off != 0;
    if ((uVar14 & 0xff) == 0) {
      local_64 = 0;
      *(undefined1 *)(param_1 + 0xda) = 0;
    }
    else {
      local_64 = DATARMNET8532ab3089(*(undefined2 *)(param_1 + 0xcc),uVar4,
                                     *(undefined4 *)(lVar11 + 0x94));
    }
    if (*(undefined8 **)(param_1 + 0x60) != (undefined8 *)0x0) {
      bVar3 = *(byte *)(*(long *)(param_1 + 0x58) + 0x13f);
      uVar13 = sp_el0;
      puVar16 = *(undefined8 **)(param_1 + 0x60);
      do {
        if (*(char *)(param_1 + 0xda) != '\0') {
          *(undefined4 *)((long)puVar16 + 0x94) = local_64;
        }
        puVar17 = (undefined8 *)*puVar16;
        *puVar16 = 0;
        if (cVar5 != '\0' && bVar9) {
          DATARMNET952c960091 = DATARMNET952c960091 + 1;
        }
        if ((bVar3 == 0) || (*(char *)(param_1 + 0xd4) != '\0')) {
          if (param_2 == '\0') {
            if (*(char *)(param_1 + 0xd4) == '\0') {
              DATARMNETe767554e6e(puVar16);
            }
            else {
              if (param_3 == (long *)0x0) goto LAB_0010a158;
              if (*param_3 == 0) {
                puVar16[1] = puVar16;
                *param_3 = (long)puVar16;
              }
              else {
                **(undefined8 **)(*param_3 + 8) = puVar16;
                *(undefined8 **)(*param_3 + 8) = puVar16;
              }
            }
          }
          else if ((param_2 == '\x01') && (*(char *)(param_1 + 0xd4) == '\0')) {
            DATARMNET514ce0bf59(puVar16);
          }
          else {
LAB_0010a158:
            _DAT_0011d998 = _DAT_0011d998 + 1;
            netif_rx(puVar16);
          }
        }
        else {
          if (*(short *)(param_1 + 0xd8) == 0x11) {
            DAT_0011dad0 = DAT_0011dad0 + 1;
          }
          lVar11 = puVar16[0x1b] + (ulong)*(uint *)((long)puVar16 + 0xd4);
          uVar14 = *(ushort *)(lVar11 + 6);
          uVar15 = (uint)uVar14;
          if (bVar3 < uVar14) {
            sVar6 = *(short *)(lVar11 + 4);
            uVar2 = *(undefined4 *)(lVar11 + 0x18);
            uVar7 = 0;
            uVar18 = (uint)bVar3;
            if (bVar3 != 0) {
              uVar7 = (undefined2)(((bVar3 - 1) + (uint)uVar14) / uVar18);
            }
            *(ushort *)(lVar11 + 4) = sVar6 * (ushort)bVar3;
            *(undefined2 *)(lVar11 + 6) = uVar7;
            puVar10 = (undefined8 *)__skb_gso_segment(puVar16,1,0);
            if ((puVar10 != (undefined8 *)0x0) && (puVar10 < (undefined8 *)0xfffffffffffff001)) {
              if (1 < uVar18) {
                puVar12 = puVar10;
                do {
                  uVar1 = uVar15 & 0xffff;
                  uVar15 = uVar15 - uVar18;
                  lVar11 = puVar12[0x1b] + (ulong)*(uint *)((long)puVar12 + 0xd4);
                  if (uVar18 <= uVar1) {
                    uVar1 = uVar18;
                  }
                  *(undefined4 *)(lVar11 + 0x18) = uVar2;
                  *(short *)(lVar11 + 4) = sVar6;
                  *(short *)(lVar11 + 6) = (short)uVar1;
                } while ((1 < (uVar15 & 0xffff)) &&
                        (puVar12 = (undefined8 *)*puVar12, puVar12 != (undefined8 *)0x0));
              }
              do {
                while( true ) {
                  puVar12 = (undefined8 *)*puVar10;
                  *(undefined4 *)((long)puVar10 + 0x94) = *(undefined4 *)((long)puVar16 + 0x94);
                  uVar13 = puVar16[2];
                  *puVar10 = 0;
                  puVar10[2] = uVar13;
                  puVar10 = puVar12;
                  if (param_2 == '\0') break;
                  netif_rx();
                  if (puVar12 == (undefined8 *)0x0) goto LAB_0010a338;
                }
                netif_receive_skb();
              } while (puVar12 != (undefined8 *)0x0);
LAB_0010a338:
              consume_skb(puVar16);
              goto LAB_0010a184;
            }
            *(short *)(lVar11 + 4) = sVar6;
            *(ushort *)(lVar11 + 6) = uVar14;
          }
          if (param_2 == '\0') {
            netif_receive_skb(puVar16);
          }
          else {
            netif_rx();
          }
        }
LAB_0010a184:
        puVar16 = puVar17;
      } while (puVar17 != (undefined8 *)0x0);
    }
    *(undefined4 *)(param_1 + 0x78) = 0;
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(long *)(param_1 + 0x60) = 0;
  }
  return;
}



//------------------------------------------------------------
// DATARMNET23c7ddd780 @ 0010a584 size=340
// signature: undefined DATARMNET23c7ddd780(void)
// callers: [DATARMNET39391a8bc5]
//------------------------------------------------------------

void DATARMNET23c7ddd780(long param_1,char param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  ulong uVar7;
  
  puVar5 = *(undefined8 **)(param_1 + 0x60);
  if (puVar5 == (undefined8 *)0x0) {
    return;
  }
  if (*(char *)(param_1 + 0xd0) == '\0') {
    uVar3 = 0;
    *(undefined1 *)(param_1 + 0xda) = 0;
  }
  else {
    uVar3 = DATARMNET8532ab3089(*(undefined2 *)(param_1 + 0xcc),*(undefined1 *)(param_1 + 0xd2),
                                *(undefined4 *)((long)puVar5 + 0x94),0);
    puVar5 = *(undefined8 **)(param_1 + 0x60);
    if (puVar5 == (undefined8 *)0x0) {
      uVar4 = 0;
      uVar7 = 0;
      goto LAB_0010a654;
    }
  }
  uVar7 = 0;
  uVar4 = 0;
  do {
    if (*(char *)(param_1 + 0xda) != '\0') {
      *(undefined4 *)((long)puVar5 + 0x94) = uVar3;
    }
    puVar6 = (undefined8 *)*puVar5;
    iVar1 = *(int *)(puVar5 + 0xe);
    *puVar5 = 0;
    if (param_2 == '\x01') {
      if (*(char *)(param_1 + 0xd4) != '\0') goto LAB_0010a5fc;
      DATARMNET514ce0bf59();
    }
    else if ((param_2 == '\0') && (*(char *)(param_1 + 0xd4) == '\0')) {
      DATARMNETe767554e6e();
    }
    else {
LAB_0010a5fc:
      netif_rx();
    }
    uVar7 = (ulong)(uint)(iVar1 + (int)uVar7);
    uVar4 = uVar4 + 1;
    puVar5 = puVar6;
  } while (puVar6 != (undefined8 *)0x0);
LAB_0010a654:
  DATARMNETecc0627c70._1616_8_ = DATARMNETecc0627c70._1616_8_ - uVar7;
  DATARMNETecc0627c70._1624_8_ = DATARMNETecc0627c70._1624_8_ - (ulong)uVar4;
  DAT_0011da80 = DAT_0011da80 + 1;
  uVar7 = (ulong)*(ushort *)(param_1 + 0xce);
  if (7 < uVar7) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10a6d4);
    (*pcVar2)();
  }
  if (0x124 < uVar7 * 0x28) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(1,0x10a6d8);
    (*pcVar2)();
  }
  (&DAT_0011cb44)[uVar7 * 10] = (&DAT_0011cb44)[uVar7 * 10] - uVar4;
  return;
}



//------------------------------------------------------------
// DATARMNETe377e0368d @ 0010a6dc size=1076
// signature: undefined DATARMNETe377e0368d(void)
// callers: [DATARMNET7ed4cef8a3, DATARMNET756778f14f, DATARMNETa4bf9fbf64, DATARMNET613a81eca8]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETe377e0368d(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  long lVar6;
  code *pcVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined8 *puVar12;
  ulong uVar13;
  undefined8 *puVar14;
  ulong uVar15;
  int iVar16;
  undefined8 *puVar17;
  undefined8 *puVar18;
  undefined8 uVar19;
  undefined1 auVar20 [16];
  undefined8 local_80;
  undefined8 *local_78;
  undefined8 *local_70;
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  local_70 = (undefined8 *)0x0;
  local_78 = (undefined8 *)0x0;
  DATARMNETe074a09496();
  uVar15 = 0;
  puVar14 = (undefined8 *)0x0;
  local_80 = 0;
  do {
    iVar9 = DATARMNETeb3978575d(uVar15 & 0xffffffff);
    puVar18 = &DATARMNET0997c5650d + uVar15 * 5;
    puVar17 = (undefined8 *)*puVar18;
    if (puVar17 == puVar18) {
      iVar16 = 0;
    }
    else {
      iVar16 = 0;
      puVar12 = puVar17;
      do {
        piVar1 = (int *)((long)puVar12 + 0x3c);
        puVar12 = (undefined8 *)*puVar12;
        iVar16 = *piVar1 + iVar16;
      } while (puVar12 != puVar18);
    }
    if (DATARMNET12565c8f98 != 0) {
      DATARMNETc54e431bbc(uVar15 & 0xffffffff,iVar16);
      puVar17 = (undefined8 *)*puVar18;
    }
    if (puVar17 == puVar18) {
      iVar16 = 0;
    }
    else {
      iVar16 = 0;
      do {
        iVar2 = *(int *)(puVar17 + 7);
        puVar12 = (undefined8 *)*puVar17;
        if (iVar2 != 0) {
          uVar19 = puVar17[6];
          iVar3 = *(int *)((long)puVar17 + 0x3c);
          if (*(char *)((long)puVar17 + 0x94) != '\0') {
            puVar14 = puVar17 + -8;
          }
          cVar8 = DATARMNETe02152c351(puVar17 + -8,param_1,param_2,&local_70);
          if (cVar8 != '\0') {
            uVar13 = (ulong)*(ushort *)((long)puVar17 + 0x8e);
            if (7 < uVar13) goto LAB_0010ab04;
            if (0x124 < uVar13 * 0x28) {
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(1,0x10ab0c);
              (*pcVar7)();
            }
            iVar16 = iVar3 + iVar16;
            (&DAT_0011cb44)[uVar13 * 10] = (&DAT_0011cb44)[uVar13 * 10] - iVar2;
            *(undefined4 *)((long)puVar17 + 0x3c) = 0;
            local_80 = CONCAT44(iVar2 + local_80._4_4_,(int)local_80 + (int)uVar19);
            if (uVar15 == *(ushort *)((long)puVar17 + 0x8e)) {
              iVar9 = iVar2 + iVar9;
              *(int *)((long)puVar17 + 0x7c) = iVar9;
            }
          }
        }
        puVar17 = puVar12;
      } while (puVar12 != puVar18);
    }
    if (DATARMNET12565c8f98 != 0) {
      iVar9 = DATARMNET362b15f941(uVar15 & 0xffffffff);
      uVar10 = DATARMNETa1ac2608b5;
      if ((iVar9 != 0) && ((&DAT_0011cb4c)[uVar15 * 0x28] == '\0')) {
        ktime_get_with_offset(1);
        auVar20 = ns_to_timespec64();
        lVar6 = uVar15 * 0x90;
        if (uVar10 < 6) {
          uVar10 = 5;
        }
        uVar4 = *(uint *)(DATARMNETecc0627c70 + lVar6 + 0x218);
        if ((auVar20._8_8_ - *(long *)(DATARMNETecc0627c70 + lVar6 + 0x210)) +
            (auVar20._0_8_ - *(long *)(DATARMNETecc0627c70 + lVar6 + 0x208)) * 1000000000 <
            (long)(int)(uVar10 * 1000000)) {
          iVar16 = uVar4 + iVar16;
        }
        else {
          if ((uint)(&DATARMNETd75e474598)[uVar15] < uVar4) {
            (&DATARMNETd75e474598)[uVar15] = uVar4;
          }
          *(undefined1 (*) [16])(DATARMNETecc0627c70 + lVar6 + 0x208) = auVar20;
        }
        *(int *)(DATARMNETecc0627c70 + lVar6 + 0x218) = iVar16;
      }
      DATARMNETc54e431bbc(uVar15 & 0xffffffff,0);
    }
    uVar10 = DATARMNETeea3cef5b6(uVar15 & 0xffffffff);
    if ((uint)(&DATARMNET84413d1257)[uVar15] <= uVar10) {
      uVar11 = DATARMNETeea3cef5b6(uVar15 & 0xffffffff);
      (&DATARMNET84413d1257)[uVar15] = uVar11;
    }
    uVar15 = uVar15 + 1;
  } while (uVar15 != 8);
  DATARMNETecc0627c70._1616_8_ = DATARMNETecc0627c70._1616_8_ - (local_80 & 0xffffffff);
  DATARMNETecc0627c70._1624_8_ = DATARMNETecc0627c70._1624_8_ - (local_80 >> 0x20);
  if ((local_70 != (undefined8 *)0x0) && (puVar14 != (undefined8 *)0x0)) {
    uVar5 = *(ushort *)((long)puVar14 + 0xce);
    if (8 < (ulong)uVar5) {
LAB_0010ab04:
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x10ab08);
      (*pcVar7)();
    }
    DATARMNETecc0627c70[0x68b] = 1;
    _raw_spin_unlock_bh(&DATARMNET3764d083f0);
    *(undefined2 *)((long)puVar14 + 0xd6) = 0;
    local_78 = local_70;
    if (local_70 != (undefined8 *)0x0) {
      local_78 = local_70;
      do {
        puVar17 = (undefined8 *)*local_78;
        *local_78 = 0;
        DATARMNETde8ee16f92(puVar14);
        rmnet_rx_handler(&local_78);
        DATARMNET3e37ad2816(puVar14,&DATARMNET0997c5650d + (ulong)uVar5 * 5);
        local_78 = puVar17;
      } while (puVar17 != (undefined8 *)0x0);
    }
    _raw_spin_lock_bh(&DATARMNET3764d083f0);
    _rmnet_shs_switch = 0;
    rmnet_module_hook_unregister_no_sync(DATARMNET28a9685974,1);
    DATARMNETecc0627c70[0x68b] = 0;
    DATARMNETecc0627c70._1652_2_ = 0;
    DATARMNETecc0627c70[0x673] = DATARMNETecc0627c70[0x676];
  }
  if (((long)DATARMNETecc0627c70._1616_8_ < 1) || ((long)DATARMNETecc0627c70._1624_8_ < 1)) {
    DATARMNETecc0627c70[0x66a] = 0;
    DATARMNETecc0627c70._1616_8_ = 0;
    DATARMNETecc0627c70._1624_8_ = 0;
    DATARMNETecc0627c70[0x66c] = 2;
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNETc54e431bbc @ 0010ac08 size=404
// signature: undefined DATARMNETc54e431bbc(void)
// callers: [DATARMNETe377e0368d]
//------------------------------------------------------------

void DATARMNETc54e431bbc(uint param_1,int param_2)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  ulong uVar8;
  ulong uVar9;
  
  iVar5 = DATARMNET227d2ff866;
  if (7 < (param_1 & 0xff)) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x10ad9c);
    (*pcVar6)();
  }
  uVar9 = (ulong)param_1 & 0xff;
  if (0x478 < (uVar9 + (ulong)(byte)param_1 * 8) * 0x10) {
LAB_0010ad94:
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(1,0x10ad98);
    (*pcVar6)();
  }
  uVar3 = *(uint *)(DATARMNET65393dea13 + uVar9 * 4);
  uVar2 = *(uint *)(DATARMNETecc0627c70 + uVar9 * 0x90 + 0x218);
  lVar4 = (ulong)(uVar3 <= uVar2) << 2;
  iVar7 = DATARMNETeea3cef5b6((ulong)param_1);
  if ((uint)(iVar7 + param_2) < *(uint *)(DATARMNETbc049ffc4c + uVar9 * 4)) {
    if (uVar2 < uVar3) {
      return;
    }
  }
  else {
    lVar4 = 5;
  }
  iVar7 = DATARMNET362b15f941(param_1 & 0xff);
  if (iVar7 != 0) {
    uVar8 = uVar9 * 0x28;
    if (0x11c < uVar8) goto LAB_0010ad94;
    if ((((&DAT_0011cb4c)[uVar8] == '\0') && ((param_1 & 0xff) != 1)) &&
       ((uint)DATARMNETecc0627c70[0x673] != (param_1 & 0xff))) {
      if (0x11c < uVar8) goto LAB_0010ad94;
      (&DAT_0011cb4c)[uVar8] = '\x01';
      DATARMNETfb7007f025();
      lVar1 = uVar9 * 0x90 + 0x11c628;
      uVar9 = hrtimer_active(lVar1);
      if ((uVar9 & 1) != 0) {
        hrtimer_cancel(lVar1);
      }
      iVar7 = 1000000;
      if (iVar5 != 0) {
        iVar7 = iVar5 * 1000000;
      }
      hrtimer_start_range_ns(lVar1,iVar7,0,1);
      (&DATARMNETb7ddf3c5dd)[lVar4] = (&DATARMNETb7ddf3c5dd)[lVar4] + 1;
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNETa4bf9fbf64 @ 0010ada0 size=216
// signature: undefined DATARMNETa4bf9fbf64(void)
// callers: [DATARMNETa7afc8cdaa, DATARMNET756778f14f]
//------------------------------------------------------------

void DATARMNETa4bf9fbf64(undefined4 param_1,uint param_2)

{
  ulong uVar1;
  
  _raw_spin_lock_bh(&DATARMNET3764d083f0);
  DATARMNETe377e0368d(param_1,param_2);
  _raw_spin_unlock_bh(&DATARMNET3764d083f0);
  if ((param_2 & 0xff) == 1) {
    if (((DATARMNET365ddeca1c != 0) && (DATARMNETecc0627c70._1616_8_ != 0)) &&
       (DATARMNETecc0627c70._1624_8_ != 0)) {
      uVar1 = hrtimer_active(DATARMNETecc0627c70);
      if ((uVar1 & 1) != 0) {
        hrtimer_cancel(DATARMNETecc0627c70);
      }
      hrtimer_start_range_ns(DATARMNETecc0627c70,DATARMNET4ac8af832c * 1000000,0,1);
    }
    DAT_0011d970 = DAT_0011d970 + 1;
  }
  return;
}



//------------------------------------------------------------
// DATARMNET495dab3d72 @ 0010ae7c size=448
// signature: undefined DATARMNET495dab3d72(void)
// callers: [DATARMNET756778f14f]
//------------------------------------------------------------

void DATARMNET495dab3d72(long param_1,long param_2)

{
  code *pcVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  ulong uVar5;
  
  uVar5 = (ulong)*(ushort *)(*(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4) + 6);
  if (uVar5 == 0) {
    uVar5 = (ulong)*(ushort *)(param_2 + 0xce);
    *(long *)(param_2 + 0x90) = *(long *)(param_2 + 0x90) + 1;
    if (7 < uVar5) goto LAB_0010b034;
    if (0x124 < uVar5 * 0x28) goto LAB_0010b038;
    uVar2 = 1;
    (&DAT_0011cb44)[uVar5 * 10] = (&DAT_0011cb44)[uVar5 * 10] + 1;
  }
  else {
    uVar3 = (ulong)*(ushort *)(param_2 + 0xce);
    *(ulong *)(param_2 + 0x90) = *(long *)(param_2 + 0x90) + uVar5;
    if (7 < uVar3) {
LAB_0010b034:
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10b038);
      (*pcVar1)();
    }
    if (0x124 < uVar3 * 0x28) {
LAB_0010b038:
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(1,0x10b03c);
      (*pcVar1)();
    }
    (&DAT_0011cb44)[uVar3 * 10] = (&DAT_0011cb44)[uVar3 * 10] + 1;
    uVar2 = (uint)*(ushort *)(*(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4) + 6);
  }
  *(uint *)(param_2 + 0x7c) = *(int *)(param_2 + 0x7c) + uVar2;
  *(long *)(param_2 + 0x98) = *(long *)(param_2 + 0x98) + 1;
  *(ulong *)(param_2 + 0xa8) = *(long *)(param_2 + 0xa8) + (ulong)*(uint *)(param_1 + 0x2c);
  *(ulong *)(param_2 + 0xb0) = *(long *)(param_2 + 0xb0) + (ulong)*(uint *)(param_1 + 0x30);
  *(undefined4 *)(param_2 + 0xc4) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(param_2 + 200) = *(undefined4 *)(param_1 + 0x38);
  *(ulong *)(param_2 + 0xa0) = *(long *)(param_2 + 0xa0) + (ulong)*(uint *)(param_1 + 0x70);
  *(ulong *)(param_2 + 0x70) = *(long *)(param_2 + 0x70) + (ulong)*(uint *)(param_1 + 0x70);
  DATARMNETecc0627c70._1616_8_ = DATARMNETecc0627c70._1616_8_ + (ulong)*(uint *)(param_1 + 0x70);
  if (*(int *)(param_2 + 0x78) == 0) {
    iVar4 = 1;
    *(long *)(param_2 + 0x60) = param_1;
    *(long *)(param_2 + 0x68) = param_1;
  }
  else {
    **(long **)(param_2 + 0x68) = param_1;
    iVar4 = *(int *)(param_2 + 0x78) + 1;
    *(undefined8 *)(param_2 + 0x68) = **(undefined8 **)(param_2 + 0x68);
  }
  *(int *)(param_2 + 0x78) = iVar4;
  DATARMNETecc0627c70._1624_8_ = DATARMNETecc0627c70._1624_8_ + 1;
  return;
}



//------------------------------------------------------------
// DATARMNET0a73c53ae6 @ 0010b0b0 size=256
// signature: undefined DATARMNET0a73c53ae6(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNET0a73c53ae6(long param_1,undefined8 param_2,undefined8 param_3,ulong param_4)

{
  undefined8 uVar1;
  code *pcVar2;
  
  if (DATARMNET756bdd424a != 0) {
    param_4 = (ulong)DATARMNETecc0627c70[0x66c];
  }
  if (0 < CONCAT44(DATARMNETecc0627c70._1628_4_,DATARMNETecc0627c70._1624_4_)) {
    if (DATARMNETecc0627c70[0x66c] == 2) {
      DATARMNETecc0627c70[0x66c] = 0;
      return 0;
    }
    if (DATARMNETecc0627c70[0x66c] == 1) {
      queue_work_on(0x20,_system_wq,&shs_rx_work,param_4);
    }
    else if (DATARMNETecc0627c70[0x66c] == 0) {
      DATARMNETecc0627c70[0x66c] = 1;
      pcVar2 = *(code **)(*(long *)(param_1 + 0x30) + 0x30);
      if (*(int *)(pcVar2 + -4) != 0x7230bf2a) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10b134);
        (*pcVar2)();
      }
      uVar1 = (*pcVar2)();
      hrtimer_forward(param_1,uVar1,2000000);
      return 1;
    }
  }
  return 0;
}



//------------------------------------------------------------
// DATARMNET2ba63fbd90 @ 0010b350 size=52
// signature: undefined DATARMNET2ba63fbd90(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET2ba63fbd90(void)

{
  __pm_relax(DATARMNETecc0627c70._1664_8_);
  DATARMNET064fbe9e3a = 1;
  return 0;
}



//------------------------------------------------------------
// DATARMNETc2b0dbbb32 @ 0010b388 size=184
// signature: undefined DATARMNETc2b0dbbb32(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETc2b0dbbb32(void)

{
  long lVar1;
  undefined1 auVar2 [16];
  undefined8 local_90;
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
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
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
  local_90 = 0;
  DATARMNET8d0d510d45(DATARMNETe4a6d22824,&local_90);
  DATARMNETb5d58adbe7(&local_90);
  ktime_get_with_offset(1);
  auVar2 = ns_to_timespec64();
  DATARMNETecc0627c70._1656_8_ = 0x7fffffffffffffff;
  if (auVar2._0_8_ < 0x225c17d04) {
    DATARMNETecc0627c70._1656_8_ = auVar2._8_8_ + auVar2._0_8_ * 1000000000;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// DATARMNET4ce9744605 @ 0010b444 size=64
// signature: undefined DATARMNET4ce9744605(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNET4ce9744605(long param_1)

{
  DATARMNET371703c28d();
  queue_work_on(0x20,_system_wq,param_1 + 0x48);
  return 0;
}



//------------------------------------------------------------
// DATARMNETbfbe1f5cd0 @ 0010b488 size=64
// signature: undefined DATARMNETbfbe1f5cd0(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETbfbe1f5cd0(void)

{
  DATARMNETf20806b279();
  return 0;
}



//------------------------------------------------------------
// DATARMNETe1f95274f1 @ 0010b550 size=604
// signature: undefined DATARMNETe1f95274f1(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

void DATARMNETe1f95274f1(void)

{
  DATARMNETecc0627c70[0x21c] = 0;
  DATARMNETecc0627c70._472_8_ = 0xfffffffe0;
  DATARMNETecc0627c70._480_8_ = 0x11c678;
  DATARMNETecc0627c70._488_8_ = 0x11c678;
  DATARMNETecc0627c70._496_8_ = DATARMNET056c939591;
  hrtimer_init(0x11c628,1,1);
  DATARMNETecc0627c70._440_8_ = DATARMNET4ce9744605;
  DATARMNETecc0627c70[0x2ac] = 1;
  DATARMNETecc0627c70._616_8_ = 0xfffffffe0;
  DATARMNETecc0627c70._624_8_ = 0x11c708;
  DATARMNETecc0627c70._632_8_ = 0x11c708;
  DATARMNETecc0627c70._640_8_ = DATARMNET056c939591;
  hrtimer_init(0x11c6b8,1,1);
  DATARMNETecc0627c70._584_8_ = DATARMNET4ce9744605;
  DATARMNETecc0627c70._760_8_ = 0xfffffffe0;
  DATARMNETecc0627c70[0x33c] = 2;
  DATARMNETecc0627c70._768_8_ = 0x11c798;
  DATARMNETecc0627c70._776_8_ = 0x11c798;
  DATARMNETecc0627c70._784_8_ = DATARMNET056c939591;
  hrtimer_init(0x11c748,1,1);
  DATARMNETecc0627c70._728_8_ = DATARMNET4ce9744605;
  DATARMNETecc0627c70._904_8_ = 0xfffffffe0;
  DATARMNETecc0627c70[0x3cc] = 3;
  DATARMNETecc0627c70._912_8_ = 0x11c828;
  DATARMNETecc0627c70._920_8_ = 0x11c828;
  DATARMNETecc0627c70._928_8_ = DATARMNET056c939591;
  hrtimer_init(0x11c7d8,1,1);
  DATARMNETecc0627c70._872_8_ = DATARMNET4ce9744605;
  DATARMNETecc0627c70._1048_8_ = 0xfffffffe0;
  DATARMNETecc0627c70[0x45c] = 4;
  DATARMNETecc0627c70._1056_8_ = 0x11c8b8;
  DATARMNETecc0627c70._1064_8_ = 0x11c8b8;
  DATARMNETecc0627c70._1072_8_ = DATARMNET056c939591;
  hrtimer_init(0x11c868,1,1);
  DATARMNETecc0627c70._1016_8_ = DATARMNET4ce9744605;
  DATARMNETecc0627c70._1192_8_ = 0xfffffffe0;
  DATARMNETecc0627c70[0x4ec] = 5;
  DATARMNETecc0627c70._1200_8_ = 0x11c948;
  DATARMNETecc0627c70._1208_8_ = 0x11c948;
  DATARMNETecc0627c70._1216_8_ = DATARMNET056c939591;
  hrtimer_init(0x11c8f8,1,1);
  DATARMNETecc0627c70._1160_8_ = DATARMNET4ce9744605;
  DATARMNETecc0627c70._1336_8_ = 0xfffffffe0;
  DATARMNETecc0627c70[0x57c] = 6;
  DATARMNETecc0627c70._1344_8_ = 0x11c9d8;
  DATARMNETecc0627c70._1352_8_ = 0x11c9d8;
  DATARMNETecc0627c70._1360_8_ = DATARMNET056c939591;
  hrtimer_init(0x11c988,1,1);
  DATARMNETecc0627c70._1304_8_ = DATARMNET4ce9744605;
  DATARMNETecc0627c70._1480_8_ = 0xfffffffe0;
  DATARMNETecc0627c70[0x60c] = 7;
  DATARMNETecc0627c70._1488_8_ = 0x11ca68;
  DATARMNETecc0627c70._1496_8_ = 0x11ca68;
  DATARMNETecc0627c70._1504_8_ = DATARMNET056c939591;
  hrtimer_init(0x11ca18,1,1);
  DATARMNETecc0627c70._1448_8_ = DATARMNET4ce9744605;
  hrtimer_init(DATARMNETecc0627c70,1,1);
  DATARMNETecc0627c70._40_8_ = DATARMNET0a73c53ae6;
  hrtimer_init(0x11c4e0,1,1);
  DATARMNETecc0627c70._112_8_ = DATARMNETc2b0dbbb32;
  hrtimer_init(0x11c528,1,1);
  DATARMNETecc0627c70._184_8_ = DATARMNET2ba63fbd90;
  hrtimer_init(0x11c570,1,1);
  DATARMNETecc0627c70._256_8_ = DATARMNETbfbe1f5cd0;
  shs_rx_work = 0xfffffffe0;
  DAT_0011cc90 = &DAT_0011cc90;
  DAT_0011cc98 = &DAT_0011cc90;
  DAT_0011cca0 = DATARMNETa7afc8cdaa;
  return;
}



//------------------------------------------------------------
// DATARMNETa7afc8cdaa @ 0010b7b0 size=136
// signature: undefined DATARMNETa7afc8cdaa(void)
// callers: []
//------------------------------------------------------------

void DATARMNETa7afc8cdaa(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        ,ulong param_5)

{
  long lVar1;
  
  if (DATARMNET756bdd424a != 0) {
    param_5 = (ulong)DATARMNETecc0627c70[0x66c];
  }
  if ((DATARMNETecc0627c70._1624_8_ != 0) && (DATARMNETecc0627c70[0x66c] == 1)) {
    lVar1 = sp_el0;
    *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 0x200;
    DATARMNETa4bf9fbf64(0,1,param_3,param_4,param_5);
    local_bh_enable();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET02cdd9b125 @ 0010b940 size=196
// signature: undefined DATARMNET02cdd9b125(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

undefined4 DATARMNET02cdd9b125(void)

{
  undefined4 uVar1;
  
  uVar1 = DATARMNET12565c8f98;
  DATARMNET12565c8f98 = 0;
  hrtimer_cancel(0x11c628);
  cancel_work_sync(0x11c670);
  hrtimer_cancel(0x11c6b8);
  cancel_work_sync(0x11c700);
  hrtimer_cancel(0x11c748);
  cancel_work_sync(0x11c790);
  hrtimer_cancel(0x11c7d8);
  cancel_work_sync(0x11c820);
  hrtimer_cancel(0x11c868);
  cancel_work_sync(0x11c8b0);
  hrtimer_cancel(0x11c8f8);
  cancel_work_sync(0x11c940);
  hrtimer_cancel(0x11c988);
  cancel_work_sync(0x11c9d0);
  hrtimer_cancel(0x11ca18);
  cancel_work_sync(0x11ca60);
  cancel_work_sync(&shs_rx_work);
  return uVar1;
}



//------------------------------------------------------------
// DATARMNET82e88dbb56 @ 0010ba08 size=304
// signature: undefined DATARMNET82e88dbb56(void)
// callers: [DATARMNET2aa4ef6ff9]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNET82e88dbb56(undefined8 param_1,uint param_2)

{
  long *plVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  long lVar5;
  code *pcVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  
  if (0x1f < param_2) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x10bb38);
    (*pcVar6)();
  }
  lVar10 = *(long *)(&__per_cpu_offset + (ulong)param_2 * 8);
  rtnl_lock();
  lVar8 = skb_dequeue_tail(param_1);
  if (lVar8 != 0) {
    lVar4 = sp_el0;
    do {
      iVar7 = rmnet_is_real_dev_registered(*(undefined8 *)(lVar8 + 0x10));
      if (iVar7 != 0) {
        _DAT_0011dac8 = _DAT_0011dac8 + 1;
        lVar9 = *(long *)(*(long *)(lVar8 + 0x10) + 0x1e8);
        if ((lVar9 != 0) || (lVar9 = netdev_core_stats_alloc(*(long *)(lVar8 + 0x10)), lVar9 != 0))
        {
          *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + 1;
          lVar5 = tpidr_el1;
          plVar1 = (long *)(lVar5 + lVar9);
          do {
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(plVar1,0x10);
            if (bVar3) {
              *plVar1 = *plVar1 + 1;
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
          lVar9 = *(long *)(lVar4 + 0x10) + -1;
          *(int *)(lVar4 + 0x10) = (int)lVar9;
          if ((lVar9 == 0) || (*(long *)(lVar4 + 0x10) == 0)) {
            preempt_schedule_notrace();
          }
        }
        *(int *)(&__tracepoint_rmnet_shs_err + lVar10) =
             *(int *)(&__tracepoint_rmnet_shs_err + lVar10) + 1;
        *(int *)(rtnl_unlock + lVar10) = *(int *)(rtnl_unlock + lVar10) + 1;
        kfree_skb_reason(lVar8,1);
      }
      lVar8 = skb_dequeue_tail(param_1);
    } while (lVar8 != 0);
  }
  rtnl_unlock();
  return 0;
}



//------------------------------------------------------------
// DATARMNET4684d6c911 @ 0010bb3c size=136
// signature: undefined DATARMNET4684d6c911(void)
// callers: []
//------------------------------------------------------------

void DATARMNET4684d6c911(void)

{
  ulong uVar1;
  
  DATARMNET202a68d7d0();
  uVar1 = hrtimer_active(0x11c570);
  if ((uVar1 & 1) != 0) {
    hrtimer_cancel(0x11c570);
  }
  hrtimer_start_range_ns(0x11c570,DATARMNET2be16c76ac * 1000000,0,1);
  return;
}



//------------------------------------------------------------
// DATARMNET78bb6be330 @ 0010bc3c size=28
// signature: undefined DATARMNET78bb6be330(void)
// callers: []
//------------------------------------------------------------

void DATARMNET78bb6be330(void)

{
  DATARMNET7ed4cef8a3();
  return;
}



//------------------------------------------------------------
// DATARMNET7ed4cef8a3 @ 0010bc5c size=256
// signature: undefined DATARMNET7ed4cef8a3(void)
// callers: [DATARMNET78bb6be330]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET7ed4cef8a3(uint *param_1,undefined8 param_2,undefined8 param_3,ulong param_4,
                        ulong param_5)

{
  uint uVar1;
  
  if (DATARMNET756bdd424a != 0) {
    param_4 = (ulong)*param_1;
    param_5 = (ulong)param_1[2];
  }
  uVar1 = *param_1;
  if (DATARMNET016351c9e4 == 0 || DATARMNET016351c9e4 < uVar1) {
    DATARMNET016351c9e4 = uVar1;
  }
  else {
    if (DATARMNET756bdd424a != 0) {
      _printk(&DAT_001152b6,DATARMNET016351c9e4,uVar1,param_4,param_5);
      uVar1 = *param_1;
    }
    DATARMNET016351c9e4 = uVar1;
    DAT_0011db10 = DAT_0011db10 + 1;
  }
  if (DATARMNET3764d083f0 == 0) {
    if ((0 < (long)DATARMNETecc0627c70._1624_8_) && (DATARMNETecc0627c70[0x66e] != '\x02')) {
      _DAT_0011d968 = _DAT_0011d968 + 1;
      _raw_spin_lock_bh(&DATARMNET3764d083f0);
      DATARMNETe377e0368d(0,0);
      _raw_spin_unlock_bh(&DATARMNET3764d083f0);
    }
    DATARMNETecc0627c70[0x66e] = '\x01';
  }
  return;
}



//------------------------------------------------------------
// DATARMNETf61cd23b90 @ 0010bde4 size=28
// signature: undefined DATARMNETf61cd23b90(void)
// callers: []
//------------------------------------------------------------

void DATARMNETf61cd23b90(void)

{
  DATARMNET613a81eca8();
  return;
}



//------------------------------------------------------------
// DATARMNET613a81eca8 @ 0010be04 size=160
// signature: undefined DATARMNET613a81eca8(void)
// callers: [DATARMNETf61cd23b90]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET613a81eca8(uint *param_1,undefined8 param_2,undefined8 param_3,ulong param_4,
                        undefined8 param_5,ulong param_6)

{
  if (DATARMNET756bdd424a != 0) {
    param_6 = (ulong)*param_1;
    param_4 = (ulong)(uint)DATARMNETecc0627c70._1624_4_;
  }
  DATARMNETecc0627c70[0x66e] = 2;
  if ((0 < CONCAT44(DATARMNETecc0627c70._1628_4_,DATARMNETecc0627c70._1624_4_)) &&
     (DATARMNET3764d083f0 == 0)) {
    _DAT_0011d960 = _DAT_0011d960 + 1;
    _raw_spin_lock_bh(&DATARMNET3764d083f0,param_2,param_3,param_4,param_5,param_6);
    DATARMNETe377e0368d(0,0);
    _raw_spin_unlock_bh(&DATARMNET3764d083f0);
  }
  return;
}



//------------------------------------------------------------
// DATARMNETaeb508acb0 @ 0010bf24 size=768
// signature: undefined DATARMNETaeb508acb0(void)
// callers: [DATARMNET45d8cdb224]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETaeb508acb0(void)

{
  long lVar1;
  code *pcVar2;
  bool bVar3;
  bool bVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  undefined8 uVar9;
  long lVar10;
  ulong uVar11;
  undefined8 local_e8;
  ulong local_e0 [16];
  
  lVar8 = sp_el0;
  local_e0[0xf] = *(long *)(lVar8 + 0x638);
  lVar8 = 0;
  uVar7 = (ulong)_nr_cpu_ids;
  local_e0[0xd] = 0;
  local_e0[0xe] = 0;
  local_e0[0xb] = 0;
  local_e0[0xc] = 0;
  local_e0[9] = 0;
  local_e0[10] = 0;
  local_e0[7] = 0;
  local_e0[8] = 0;
  local_e0[5] = 0;
  local_e0[6] = 0;
  local_e0[3] = 0;
  local_e0[4] = 0;
  local_e0[1] = 0;
  local_e0[2] = 0;
  local_e8 = 0;
  local_e0[0] = 0;
  while( true ) {
    uVar5 = _find_next_bit(&__cpu_possible_mask,uVar7,(long)(int)lVar8);
    uVar7 = (ulong)_nr_cpu_ids;
    if (uVar7 <= (uVar5 & 0xffffffff)) break;
    if ((uVar5 >> 3 & 0x1fffffff) != 0) {
LAB_0010c21c:
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10c220);
      (*pcVar2)();
    }
    lVar10 = (long)(int)uVar5;
    uVar11 = (long)(uVar5 << 0x20) >> 0x1c;
    *(char *)(local_e0 + lVar10 * 2 + -1) = (char)uVar5;
    if (0x80 < (uVar11 | 1)) goto LAB_0010c218;
    lVar8 = 0;
    lVar1 = (long)(int)uVar5 * 0x38;
    *(char *)((long)local_e0 + lVar10 * 0x10 + -7) = (char)*(undefined4 *)(&cpu_scale + lVar1);
    while( true ) {
      uVar6 = _find_next_bit(wakeup_source_register + lVar1,uVar7,(long)(int)lVar8);
      uVar7 = (ulong)_nr_cpu_ids;
      if (uVar7 <= (uVar6 & 0xffffffff)) break;
      if (0x80 < (uVar11 | 2)) goto LAB_0010c218;
      lVar8 = uVar6 + 1;
      *(byte *)((ulong)(local_e0 + lVar10 * 2 + -1) | 2) =
           *(byte *)((ulong)(local_e0 + lVar10 * 2 + -1) | 2) | (byte)(1L << (uVar6 & 0x3f));
    }
    if (0x1f < (uVar5 & 0xffffffff)) goto LAB_0010c21c;
    if (0x80 < (uVar11 | 8)) goto LAB_0010c218;
    lVar8 = uVar5 + 1;
    local_e0[lVar10 * 2] =
         *(ulong *)(&cpu_scale + *(long *)(&__per_cpu_offset + (uVar5 & 0xffffffff) * 8));
  }
  bVar3 = local_e0[2] < (ulong)(long)(int)local_e0[0];
  uVar7 = local_e0[2];
  if (!bVar3) {
    uVar7 = local_e0[0];
  }
  bVar4 = (ulong)(long)(int)uVar7 <= local_e0[4];
  uVar5 = local_e0[4];
  if (bVar4) {
    uVar5 = uVar7;
  }
  uVar7 = 2;
  if (bVar4) {
    uVar7 = (ulong)bVar3;
  }
  bVar3 = (ulong)(long)(int)uVar5 <= local_e0[6];
  uVar11 = local_e0[6];
  if (bVar3) {
    uVar11 = uVar5;
  }
  uVar5 = 3;
  if (bVar3) {
    uVar5 = uVar7;
  }
  bVar3 = (ulong)(long)(int)uVar11 <= local_e0[8];
  uVar7 = local_e0[8];
  if (bVar3) {
    uVar7 = uVar11;
  }
  uVar11 = 4;
  if (bVar3) {
    uVar11 = uVar5;
  }
  bVar3 = (ulong)(long)(int)uVar7 <= local_e0[10];
  uVar5 = local_e0[10];
  if (bVar3) {
    uVar5 = uVar7;
  }
  uVar7 = 5;
  if (bVar3) {
    uVar7 = uVar11;
  }
  bVar3 = (ulong)(long)(int)uVar5 <= local_e0[0xc];
  uVar11 = local_e0[0xc];
  if (bVar3) {
    uVar11 = uVar5;
  }
  uVar5 = 6;
  if (bVar3) {
    uVar5 = uVar7;
  }
  uVar7 = 7;
  if ((ulong)(long)(int)uVar11 <= local_e0[0xe]) {
    uVar7 = uVar5;
  }
  if ((uVar7 << 4 | 2) < 0x81) {
    DATARMNETecc0627c70[0x68a] = *(byte *)((long)local_e0 + uVar7 * 0x10 + -6);
    DATARMNETecc0627c70[0x688] = __sw_hweight64();
    uVar9 = 100000;
    DAT_00119228 = 210000;
    DATARMNETecc0627c70[0x689] = ~DATARMNETecc0627c70[0x68a];
    DATARMNET4793ed48af = 40000;
    DATARMNET713717107f = DAT_00119228;
    if ((DATARMNETecc0627c70[0x68a] & 1) != 0) {
      DATARMNET4793ed48af = 0;
      DATARMNET713717107f = uVar9;
    }
    bVar3 = (DATARMNETecc0627c70[0x68a] & 2) != 0;
    DAT_00119238 = 40000;
    if (bVar3) {
      DAT_00119238 = 0;
    }
    DAT_001191f8 = DAT_00119228;
    if (bVar3) {
      DAT_001191f8 = uVar9;
    }
    DAT_00119240 = 40000;
    DAT_00119200 = DAT_00119228;
    if ((DATARMNETecc0627c70[0x68a] & 4) != 0) {
      DAT_00119240 = 0;
      DAT_00119200 = uVar9;
    }
    bVar3 = (DATARMNETecc0627c70[0x68a] & 8) != 0;
    DAT_00119248 = 40000;
    if (bVar3) {
      DAT_00119248 = 0;
    }
    DAT_00119208 = DAT_00119228;
    if (bVar3) {
      DAT_00119208 = uVar9;
    }
    bVar3 = (DATARMNETecc0627c70[0x68a] & 0x10) != 0;
    DAT_00119210 = DAT_00119228;
    if (bVar3) {
      DAT_00119210 = uVar9;
    }
    DAT_00119250 = 40000;
    if (bVar3) {
      DAT_00119250 = 0;
    }
    DAT_00119258 = 40000;
    DAT_00119218 = DAT_00119228;
    if ((DATARMNETecc0627c70[0x68a] & 0x20) != 0) {
      DAT_00119258 = 0;
      DAT_00119218 = uVar9;
    }
    DAT_00119260 = 40000;
    DAT_00119220 = DAT_00119228;
    if ((DATARMNETecc0627c70[0x68a] & 0x40) != 0) {
      DAT_00119260 = 0;
      DAT_00119220 = uVar9;
    }
    DAT_00119268 = 40000;
    if ((char)DATARMNETecc0627c70[0x68a] < '\0') {
      DAT_00119268 = 0;
      DAT_00119228 = uVar9;
    }
    lVar8 = sp_el0;
    if (*(long *)(lVar8 + 0x638) != local_e0[0xf]) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
LAB_0010c218:
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(1,0x10c21c);
  (*pcVar2)();
}



//------------------------------------------------------------
// DATARMNET45d8cdb224 @ 0010c228 size=340
// signature: undefined DATARMNET45d8cdb224(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

void DATARMNET45d8cdb224(undefined8 param_1,long param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  
  if (DATARMNETecc0627c70[0x66d] == '\0') {
    if (*(long *)(*(long *)(param_2 + 0x308) + 0x40) == 0) {
      uVar2 = 0;
      uVar1 = 0;
    }
    else {
      uVar1 = DATARMNET928c931df9();
      uVar2 = DATARMNET310c3eb16e();
    }
    DATARMNETecc0627c70._392_8_ = rmnet_get_port(param_1);
    DATARMNETecc0627c70[0x66f] = 2;
    DATARMNETecc0627c70._1650_2_ = 0x101;
    DATARMNETecc0627c70[0x676] = 1;
    DATARMNETecc0627c70[0x670] = uVar1;
    DATARMNETecc0627c70[0x671] = uVar2;
    DATARMNETaeb508acb0();
    DATARMNET0997c5650d = &DATARMNET0997c5650d;
    DAT_0011cb30 = &DATARMNET0997c5650d;
    DAT_0011cb50 = &DAT_0011cb50;
    DAT_0011cb58 = &DAT_0011cb50;
    DAT_0011cb78 = &DAT_0011cb78;
    DAT_0011cb80 = &DAT_0011cb78;
    DAT_0011cba0 = &DAT_0011cba0;
    DAT_0011cba8 = &DAT_0011cba0;
    DAT_0011cbc8 = &DAT_0011cbc8;
    DAT_0011cbd0 = &DAT_0011cbc8;
    DAT_0011cbf0 = &DAT_0011cbf0;
    DAT_0011cbf8 = &DAT_0011cbf0;
    DAT_0011cc18 = &DAT_0011cc18;
    DAT_0011cc20 = &DAT_0011cc18;
    DAT_0011cc40 = &DAT_0011cc40;
    DAT_0011cc48 = &DAT_0011cc40;
    DATARMNETe6e8431304();
    DATARMNET44499733f2();
    iVar3 = register_oom_notifier(&DATARMNET105c85d84c);
    if (iVar3 < 0) {
      _printk(&DAT_0011500d);
    }
    _printk(&DAT_00115564,DATARMNETecc0627c70[0x670]);
    DATARMNETecc0627c70._1664_8_ = wakeup_source_register(0,"RMNET_SHS");
    DATARMNETecc0627c70[0x66d] = '\x01';
  }
  return;
}



//------------------------------------------------------------
// DATARMNETeacad8334e @ 0010c380 size=212
// signature: undefined DATARMNETeacad8334e(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

void DATARMNETeacad8334e(void)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  if (DATARMNETecc0627c70._1624_8_ != 0) {
    _raw_spin_lock_bh(&DATARMNET3764d083f0);
    lVar2 = 0;
    do {
      lVar3 = (&DATARMNETbfe1afe595)[lVar2] + -0x80;
      if ((&DATARMNETbfe1afe595)[lVar2] != 0 && lVar3 != 0) {
        do {
          plVar1 = *(long **)(lVar3 + 0x60);
          lVar4 = *(long *)(lVar3 + 0x80);
          while (plVar1 != (long *)0x0) {
            plVar1 = (long *)*plVar1;
            consume_skb();
          }
          *(undefined4 *)(lVar3 + 0x78) = 0;
          *(undefined8 *)(lVar3 + 0x68) = 0;
          *(undefined8 *)(lVar3 + 0x70) = 0;
          *(long *)(lVar3 + 0x60) = 0;
        } while ((lVar4 != 0) && (lVar3 = lVar4 + -0x80, lVar3 != 0));
      }
      lVar2 = lVar2 + 1;
    } while (lVar2 != 0x200);
    DATARMNETecc0627c70[0x66a] = 0;
    DATARMNETecc0627c70._1616_8_ = 0;
    DATARMNETecc0627c70._1624_8_ = 0;
    DATARMNETecc0627c70[0x66c] = 2;
    _raw_spin_unlock_bh(&DATARMNET3764d083f0);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET02fc8b29a0 @ 0010c458 size=712
// signature: undefined DATARMNET02fc8b29a0(void)
// callers: [DATARMNET756778f14f]
//------------------------------------------------------------

void DATARMNET02fc8b29a0(long param_1,long param_2,long param_3)

{
  int iVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  code *pcVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  ulong uVar10;
  uint uVar11;
  undefined8 local_c0;
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
  
  lVar9 = sp_el0;
  local_48 = *(long *)(lVar9 + 0x638);
  *(undefined1 *)(param_1 + 0xd4) = 1;
  *(undefined2 *)(param_1 + 0xd0) = *(undefined2 *)(param_2 + 2);
  uVar6 = DATARMNET310c3eb16e();
  *(undefined2 *)(param_1 + 0xd2) = uVar6;
  bVar3 = DATARMNETecc0627c70[0x676];
  *(undefined2 *)(param_1 + 0xd6) = 0;
  *(ushort *)(param_1 + 0xce) = (ushort)bVar3;
  *(ushort *)(param_1 + 0xcc) = (ushort)bVar3;
  iVar7 = DATARMNET362b15f941();
  if (iVar7 != 0) {
    DATARMNET5e4aeef593(DATARMNETecc0627c70[0x672]);
    DATARMNETfb7007f025();
  }
  bVar3 = DATARMNETecc0627c70[0x672];
  local_58 = 0;
  uStack_50 = 0;
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
  local_c0 = 0;
  iVar7 = rmnet_is_real_dev_registered(param_3);
  if (iVar7 == 0) {
    DAT_0011dae0 = DAT_0011dae0 + 1;
  }
  else {
    lVar9 = DATARMNET713da9913c(*(undefined8 *)(param_3 + 0x308),bVar3);
    bVar4 = DATARMNETecc0627c70[0x676];
    if (lVar9 == 0) {
      DATARMNETecc0627c70[0x676] = bVar3;
      DATARMNETecc0627c70[0x66f] = (undefined1)(1 << (ulong)(bVar3 & 0x1f));
      DATARMNETecc0627c70[0x673] = bVar4;
      DATARMNET1d4b1eff85(&local_c0,bVar4,(uint)bVar3);
      DATARMNETb5d58adbe7(&local_c0);
    }
  }
  if (0x1f < (ulong)*(ushort *)(param_1 + 0xce)) {
LAB_0010c718:
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10c71c);
    (*pcVar5)();
  }
  uVar11 = *(int *)(__sw_hweight64 +
                   *(long *)(&__per_cpu_offset + (ulong)*(ushort *)(param_1 + 0xce) * 8)) +
           *(int *)(__rcu_read_unlock +
                   *(long *)(&__per_cpu_offset + (ulong)*(ushort *)(param_1 + 0xce) * 8));
  if (DATARMNET673cf85e28 < uVar11) {
    DATARMNET673cf85e28 = uVar11;
  }
  iVar7 = DATARMNETeb3978575d(DATARMNETecc0627c70[0x672]);
  *(uint *)(param_1 + 0xbc) = iVar7 + uVar11;
  if (0x1f < (ulong)DATARMNETecc0627c70[0x672]) goto LAB_0010c718;
  iVar7 = *(int *)(__rcu_read_unlock +
                  *(long *)(&__per_cpu_offset + (ulong)DATARMNETecc0627c70[0x672] * 8));
  iVar1 = *(int *)(__sw_hweight64 +
                  *(long *)(&__per_cpu_offset + (ulong)DATARMNETecc0627c70[0x672] * 8));
  iVar8 = DATARMNET362b15f941(*(undefined2 *)(param_1 + 0xce));
  if (iVar8 == 0) {
    uVar2 = *(ushort *)(param_1 + 0xce);
    if (iVar7 + uVar11 + iVar1 < 5) {
      if (7 < uVar2) goto LAB_0010c718;
      uVar10 = hrtimer_active((ulong)uVar2 * 0x90 + 0x11c628);
      if ((uVar10 & 1) != 0) goto LAB_0010c6e8;
      if (7 < (ulong)*(ushort *)(param_1 + 0xce)) goto LAB_0010c718;
      lVar9 = (ulong)*(ushort *)(param_1 + 0xce) * 0x90 + 0x11c628;
      uVar11 = DATARMNET566e381630 / 0x14;
    }
    else {
      if (7 < uVar2) goto LAB_0010c718;
      uVar10 = hrtimer_active((ulong)uVar2 * 0x90 + 0x11c628);
      if ((uVar10 & 1) != 0) goto LAB_0010c6e8;
      if (7 < (ulong)*(ushort *)(param_1 + 0xce)) goto LAB_0010c718;
      lVar9 = (ulong)*(ushort *)(param_1 + 0xce) * 0x90 + 0x11c628;
      uVar11 = DATARMNET566e381630 >> 1;
    }
  }
  else {
    if (7 < (ulong)*(ushort *)(param_1 + 0xce)) goto LAB_0010c718;
    uVar10 = hrtimer_active((ulong)*(ushort *)(param_1 + 0xce) * 0x90 + 0x11c628);
    if ((uVar10 & 1) != 0) goto LAB_0010c6e8;
    if (7 < (ulong)*(ushort *)(param_1 + 0xce)) goto LAB_0010c718;
    lVar9 = (ulong)*(ushort *)(param_1 + 0xce) * 0x90 + 0x11c628;
    uVar11 = DATARMNET566e381630;
  }
  hrtimer_start_range_ns(lVar9,uVar11 * 1000000,0,1);
LAB_0010c6e8:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET756778f14f @ 0010c724 size=2364
// signature: undefined DATARMNET756778f14f(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNET756778f14f(long param_1,ushort *param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  ushort uVar4;
  char cVar5;
  byte bVar6;
  code *pcVar7;
  undefined2 uVar8;
  int iVar9;
  uint uVar10;
  long lVar11;
  ulong uVar12;
  long *plVar13;
  undefined8 uVar14;
  long *plVar15;
  long lVar16;
  bool bVar17;
  char local_d4 [4];
  undefined8 local_d0;
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
  
  bVar6 = DATARMNETecc0627c70[0x670];
  lVar11 = sp_el0;
  local_58 = *(long *)(lVar11 + 0x638);
  local_d4[0] = '\0';
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
  local_d0 = 0;
  if ((*param_2 & 1) == 0) {
    iVar9 = DATARMNET9303cec796(param_1,local_d4);
    cVar5 = local_d4[0];
    if (iVar9 == 0) {
      DATARMNETe767554e6e(param_1);
      if (cVar5 != '\0') {
        DATARMNET8d0d510d45(1,&local_d0);
        DATARMNETb5d58adbe7(&local_d0);
      }
      goto LAB_0010d108;
    }
  }
  if ((bVar6 == 0) || (DATARMNETecc0627c70[0x66d] == '\0')) {
    DATARMNETe767554e6e(param_1);
    DAT_0011da30 = DAT_0011da30 + 1;
    goto LAB_0010d108;
  }
  if ((*(ushort *)(param_1 + 0x80) & 0x300) == 0) {
    __skb_get_hash(param_1);
    if (param_2[1] == 0) goto LAB_0010c8e8;
LAB_0010c7d0:
    iVar9 = 0xdead;
    *(undefined4 *)(param_1 + 0x94) = 0xdead;
    lVar11 = tpidr_el1;
    if ((*(uint *)(&cpu_number + lVar11) == (uint)DATARMNETecc0627c70[0x673]) &&
       ((uint)DATARMNETecc0627c70[0x673] != (uint)DATARMNETecc0627c70[0x676])) {
      netif_rx(param_1);
      DATARMNETecc0627c70._1652_2_ = DATARMNETecc0627c70._1652_2_ + 1;
      if (DATARMNETf4cacbb5dc < (ushort)DATARMNETecc0627c70._1652_2_) {
        _raw_spin_lock_bh(&DATARMNET3764d083f0);
        DATARMNETe377e0368d(8,0);
        _raw_spin_unlock_bh(&DATARMNET3764d083f0);
        _rmnet_shs_switch = 0;
        rmnet_module_hook_unregister_no_sync(DATARMNET28a9685974,1);
        DATARMNETecc0627c70._1652_2_ = 0;
        DAT_0011daf0 = DAT_0011daf0 + 1;
      }
      goto LAB_0010d108;
    }
  }
  else {
    if (param_2[1] != 0) goto LAB_0010c7d0;
LAB_0010c8e8:
    iVar9 = *(int *)(param_1 + 0x94);
  }
  _raw_spin_lock_bh(&DATARMNET3764d083f0);
  for (plVar13 = (long *)(&DATARMNETbfe1afe595)[(uint)(iVar9 * 0x61c88647) >> 0x17];
      (plVar13 != (long *)0x0 && (lVar11 = (long)(plVar13 + -0x10), lVar11 != 0));
      plVar13 = (long *)*plVar13) {
    if (iVar9 == *(int *)(plVar13 + 8)) {
      if (*(char *)((long)plVar13 + 0x5b) != '\0') {
        if (*(char *)((long)plVar13 + 0x5b) == '\x02') {
          iVar9 = DATARMNETe24386452c(param_1);
          *(bool *)((long)plVar13 + 0x5b) = iVar9 != 0;
        }
        _raw_spin_unlock_bh(&DATARMNET3764d083f0);
        plVar13[2] = plVar13[2] + 1;
        plVar13[4] = plVar13[4] + (ulong)*(uint *)(param_1 + 0x70);
        goto LAB_0010cd14;
      }
      if (*(char *)((long)plVar13 + 0x54) == '\0') goto LAB_0010cd44;
      DATARMNETe074a09496();
      lVar16 = tpidr_el1;
      if (*(uint *)(&cpu_number + lVar16) != (uint)DATARMNETecc0627c70[0x676]) {
        DAT_0011db08 = DAT_0011db08 + 1;
      }
      if ((uint)DATARMNETecc0627c70[0x672] != (uint)DATARMNETecc0627c70[0x676]) {
        uVar10 = (uint)DATARMNETecc0627c70[0x676];
        if (*(ushort *)((long)plVar13 + 0x4e) != uVar10) {
          if (8 < uVar10) goto LAB_0010d144;
          DATARMNETe102b3a798(lVar11,uVar10 * 0x28 + 0x11cb28);
          DAT_0011d8f0 = DAT_0011d8f0 + 1;
        }
        DATARMNET02fc8b29a0(lVar11,param_2,*(undefined8 *)(param_1 + 0x10));
        netif_rx(param_1);
        goto LAB_0010cda8;
      }
      *(short *)((long)plVar13 + 0x56) = *(short *)((long)plVar13 + 0x56) + 1;
      DATARMNET495dab3d72(param_1,lVar11);
      if (_rmnet_shs_switch == 0) {
        bVar17 = false;
        uVar14 = 2;
        DAT_0011daf8 = DAT_0011daf8 + 1;
        goto LAB_0010cdb0;
      }
      uVar10 = DATARMNETadb0248bd4(DATARMNETecc0627c70[0x676]);
      if (*(int *)((long)plVar13 + 0x3c) + (uint)*(ushort *)((long)plVar13 + 0x56) <= uVar10) {
        bVar17 = false;
        uVar14 = 3;
        goto LAB_0010cdb0;
      }
      if ((DATARMNETaf998640fd == 0) || (*(uint *)(plVar13 + -1) <= DATARMNETaf998640fd))
      goto LAB_0010cd34;
      bVar17 = false;
      uVar14 = 1;
      DATARMNET14ed771dfb = DATARMNET14ed771dfb + 1;
      goto LAB_0010cdb0;
    }
  }
  uVar10 = (uint)DATARMNETecc0627c70[0x670] &
           ((DATARMNET121c8bc82a | DATARMNETecc0627c70[0x66f]) ^ 0xffffffff);
  uVar2 = (uint)DATARMNETecc0627c70[0x689];
  if ((uVar10 & DATARMNETecc0627c70[0x68a]) != 0) {
    uVar2 = (uint)DATARMNETecc0627c70[0x68a];
  }
  if (param_2[1] == 0) {
    iVar9 = DATARMNET762cfa52fe(uVar10 & uVar2);
    if (iVar9 < 0) goto LAB_0010c9ac;
LAB_0010c97c:
    if ((long)DATARMNETecc0627c70._1632_8_ < 0x2bd) {
      lVar11 = kmalloc_trace(_rmnet_module_hook_perf_ingress,0xb20,0xe0);
      if (lVar11 == 0) {
        DAT_0011da38 = DAT_0011da38 + 1;
      }
      else {
        Hint_Prefetch(0x11caf8,2,0,1);
        do {
          cVar5 = '\x01';
          bVar17 = (bool)ExclusiveMonitorPass(0x11caf8,0x10);
          if (bVar17) {
            cVar5 = ExclusiveMonitorsStatus();
            DATARMNETecc0627c70._1632_8_ = DATARMNETecc0627c70._1632_8_ + 1;
          }
        } while (cVar5 != '\0');
        uVar14 = *(undefined8 *)(param_1 + 0x10);
        uVar3 = *(undefined4 *)(param_1 + 0x94);
        *(short *)(lVar11 + 0xce) = (short)iVar9;
        *(undefined8 *)(lVar11 + 0x50) = uVar14;
        *(undefined4 *)(lVar11 + 0xc0) = uVar3;
        uVar8 = DATARMNET04e8d1b862(iVar9,bVar6);
        *(undefined2 *)(lVar11 + 0xcc) = uVar8;
        *(long *)(lVar11 + 0x40) = lVar11 + 0x40;
        *(long *)(lVar11 + 0x48) = lVar11 + 0x40;
        DATARMNET44459105b4(param_1,lVar11);
        DATARMNET350f55bfca(lVar11);
        bVar6 = DATARMNETecc0627c70[0x671];
        if (*(long *)(lVar11 + 0x58) != 0) {
          if (param_2[1] == 0) {
            *(ushort *)(lVar11 + 0xd0) = (ushort)DATARMNETecc0627c70[0x670];
            *(ushort *)(lVar11 + 0xd2) = (ushort)bVar6;
          }
          else {
            DATARMNETe074a09496();
            DATARMNET02fc8b29a0(lVar11,param_2,*(undefined8 *)(param_1 + 0x10));
          }
          uVar4 = *(ushort *)(lVar11 + 0xce);
          if (8 < (ulong)uVar4) {
LAB_0010d144:
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x10d148);
            (*pcVar7)();
          }
          puVar1 = (undefined1 *)(*(long *)(lVar11 + 0x50) + 0xa40);
          if (puVar1 == (undefined1 *)0x0) {
            DATARMNET68d84e7b98 = DATARMNET68d84e7b98 + 1;
          }
          else {
            *(undefined1 *)(*(long *)(lVar11 + 0x58) + 0x13b) = *puVar1;
          }
          DATARMNET3e37ad2816(lVar11,&DATARMNET0997c5650d + (ulong)uVar4 * 5);
          plVar13 = &DATARMNETbfe1afe595 + ((uint)(*(int *)(param_1 + 0x94) * 0x61c88647) >> 0x17);
          lVar16 = *plVar13;
          plVar15 = (long *)(lVar11 + 0x80);
          *plVar15 = lVar16;
          *(long **)(lVar11 + 0x88) = plVar13;
          *plVar13 = (long)plVar15;
          if (lVar16 != 0) {
            *(long **)(lVar16 + 8) = plVar15;
          }
          iVar9 = DATARMNETe24386452c(param_1);
          if (iVar9 == 0) {
            if (*(char *)(lVar11 + 0xd4) == '\0') {
LAB_0010cd44:
              DATARMNET495dab3d72(param_1,lVar11);
LAB_0010cda8:
              uVar14 = 0;
              bVar17 = true;
LAB_0010cdb0:
              if (((DATARMNETecc0627c70[0x66a] == '\0') && (DATARMNETecc0627c70._1624_8_ != 0)) &&
                 (DATARMNET365ddeca1c != 0)) {
                DATARMNETecc0627c70[0x66a] = '\x01';
                DATARMNETecc0627c70[0x66c] = '\0';
                _raw_spin_unlock_bh(&DATARMNET3764d083f0);
                uVar12 = hrtimer_active(DATARMNETecc0627c70);
                if ((uVar12 & 1) != 0) {
                  if (DATARMNET756bdd424a != 0) {
                    trace_rmnet_shs_low(7,0x22,2000000,0xdef,0xdef,0xdef,param_1);
                  }
                  hrtimer_cancel(DATARMNETecc0627c70);
                }
                hrtimer_start_range_ns(DATARMNETecc0627c70,DATARMNET4ac8af832c * 1000000,0,1);
              }
              else {
                _raw_spin_unlock_bh(&DATARMNET3764d083f0);
              }
              if ((long)(ulong)DATARMNET7d18c0bcf8 < (long)DATARMNETecc0627c70._1624_8_) {
                if (DATARMNET58b009b16b != 0) {
                  _DAT_0011d948 = _DAT_0011d948 + 1;
                }
                _raw_spin_lock_bh(&DATARMNET3764d083f0);
                uVar14 = 5;
              }
              else {
                if ((long)DATARMNETecc0627c70._1616_8_ <= (long)(ulong)DATARMNETea75c7b6f6) {
                  if (bVar17) {
                    if (((*param_2 >> 2 & 1) == 0) || (DATARMNETecc0627c70._1624_8_ == 0)) {
                      if (DATARMNETecc0627c70[0x66c] == '\x01') {
                        _DAT_0011d958 = _DAT_0011d958 + 1;
                        if (DATARMNET756bdd424a != 0) {
                          trace_rmnet_shs_high
                                    (8,0x2d,1,DATARMNETecc0627c70._1624_8_,0xdef,0xdef,0,0);
                        }
                      }
                      else {
                        if ((((*param_2 >> 2 & 1) != 0) || (DATARMNETecc0627c70._1624_8_ == 0)) ||
                           (DATARMNETecc0627c70[0x66e] == '\x01')) goto LAB_0010d108;
                        _DAT_0011d968 = _DAT_0011d968 + 1;
                      }
                    }
                    else if (DATARMNET58b009b16b != 0) {
                      _DAT_0011d988 = _DAT_0011d988 + 1;
                    }
                    uVar14 = 0;
                  }
                  else {
                    if (DATARMNET756bdd424a != 0) {
                      trace_rmnet_shs_high(8,0x2f,1,DATARMNETecc0627c70._1624_8_,0xdef,0xdef,0,0);
                    }
                    if (DATARMNET58b009b16b != 0) {
                      _DAT_0011d990 = _DAT_0011d990 + 1;
                    }
                  }
                  DATARMNETa4bf9fbf64(uVar14,0);
                  goto LAB_0010d108;
                }
                if (DATARMNET58b009b16b != 0) {
                  _DAT_0011d950 = _DAT_0011d950 + 1;
                }
                if (DATARMNET756bdd424a != 0) {
                  trace_rmnet_shs_high(8,0x2e,0,0xdef,0xdef,0xdef,0,0);
                }
                _raw_spin_lock_bh(&DATARMNET3764d083f0);
                uVar14 = 6;
              }
              DATARMNETe377e0368d(uVar14,0);
              _raw_spin_unlock_bh(&DATARMNET3764d083f0);
            }
            else {
              netif_rx(param_1);
LAB_0010cd34:
              _raw_spin_unlock_bh(&DATARMNET3764d083f0);
            }
          }
          else {
            *(undefined1 *)(lVar11 + 0xdb) = 1;
            _raw_spin_unlock_bh(&DATARMNET3764d083f0);
LAB_0010cd14:
            DATARMNETf5821256ad(param_1,param_2);
          }
          goto LAB_0010d108;
        }
        Hint_Prefetch(0x11caf8,2,0,1);
        do {
          cVar5 = '\x01';
          bVar17 = (bool)ExclusiveMonitorPass(0x11caf8,0x10);
          if (bVar17) {
            cVar5 = ExclusiveMonitorsStatus();
            DATARMNETecc0627c70._1632_8_ = DATARMNETecc0627c70._1632_8_ + -1;
          }
        } while (cVar5 != '\0');
        kfree(lVar11);
      }
    }
    else {
      DAT_0011da48 = DAT_0011da48 + 1;
    }
  }
  else {
    iVar9 = DATARMNET362c14e98b();
    if (-1 < iVar9) goto LAB_0010c97c;
LAB_0010c9ac:
    DAT_0011da98 = DAT_0011da98 + 1;
  }
  _raw_spin_unlock_bh(&DATARMNET3764d083f0);
  DAT_0011da28 = DAT_0011da28 + 1;
  DATARMNETe767554e6e(param_1);
LAB_0010d108:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// DATARMNET203752febd @ 0010d3a0 size=48
// signature: undefined DATARMNET203752febd(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET203752febd(void)

{
  _rmnet_shs_skb_entry = 0;
  rmnet_module_hook_unregister_no_sync(DATARMNETef42b9f0b2,1);
  return;
}



//------------------------------------------------------------
// DATARMNET7520667b38 @ 0010d3d4 size=56
// signature: undefined DATARMNET7520667b38(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET7520667b38(void)

{
  _rmnet_shs_skb_entry = DATARMNET756778f14f;
  rmnet_module_hook_register(DATARMNETef42b9f0b2,1);
  return;
}



//------------------------------------------------------------
// DATARMNET8f9da46b14 @ 0010d410 size=56
// signature: undefined DATARMNET8f9da46b14(void)
// callers: [DATARMNET4063c95208, DATARMNET29175fb5fc]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET8f9da46b14(void)

{
  _rmnet_shs_switch = DATARMNET756778f14f;
  rmnet_module_hook_register(DATARMNET28a9685974,1);
  return;
}



//------------------------------------------------------------
// DATARMNET9297340f58 @ 0010d44c size=144
// signature: undefined DATARMNET9297340f58(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

void DATARMNET9297340f58(undefined4 param_1)

{
  DATARMNETdf74db7e38();
  DATARMNET90fe3a4b56();
  DATARMNETecc0627c70[0x669] = 0;
  unregister_oom_notifier(&DATARMNET105c85d84c);
  if (DATARMNETecc0627c70[0x66b] != '\0') {
    hrtimer_cancel(DATARMNETecc0627c70);
  }
  hrtimer_cancel(0x11c4e0);
  hrtimer_cancel(0x11c528);
  wakeup_source_unregister(DATARMNETecc0627c70._1664_8_);
  memset(DATARMNETecc0627c70,0,0x690);
  DATARMNET12565c8f98 = param_1;
  return;
}



//------------------------------------------------------------
// local_bh_enable @ 0010d4dc size=40
// signature: undefined local_bh_enable(void)
// callers: [DATARMNETa7afc8cdaa]
//------------------------------------------------------------

void local_bh_enable(void)

{
  __local_bh_enable_ip(local_bh_enable,0x200);
  return;
}



//------------------------------------------------------------
// DATARMNET2aa4ef6ff9 @ 0010d508 size=252
// signature: undefined DATARMNET2aa4ef6ff9(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNET2aa4ef6ff9(undefined8 param_1,undefined8 param_2,int *param_3)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  
  iVar3 = 0;
  while( true ) {
    uVar2 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar3);
    if (_nr_cpu_ids <= uVar2) {
      return 0;
    }
    if ((uVar2 & 0xffffffe0) != 0) break;
    lVar4 = *(long *)(&__per_cpu_offset + (ulong)uVar2 * 8);
    if (DATARMNET1ad396a890 - 1 <
        (uint)(*(int *)(__sw_hweight64 + lVar4) + *(int *)(__rcu_read_unlock + lVar4))) {
      DATARMNET82e88dbb56(&cpu_topology + lVar4,uVar2);
      if (DATARMNET1ad396a890 <= *(uint *)(__sw_hweight64 + lVar4)) {
        DATARMNET82e88dbb56(__kmalloc + lVar4,uVar2);
      }
      *param_3 = *param_3 + 1;
    }
    iVar3 = uVar2 + 1;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10d604);
  (*pcVar1)();
}



//------------------------------------------------------------
// DATARMNETdc7bead533 @ 0010d6b8 size=88
// signature: undefined DATARMNETdc7bead533(void)
// callers: [DATARMNETf5821256ad]
//------------------------------------------------------------

bool DATARMNETdc7bead533(uint param_1,uint param_2)

{
  code *pcVar1;
  
  if (7 < param_1) {
    DAT_0011daa0 = DAT_0011daa0 + 1;
    return false;
  }
  if (0x578 < (ulong)param_1 * 0x98) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(1,0x10d710);
    (*pcVar1)();
  }
  return (ulong)param_2 < (ulong)(&DAT_0011db80)[(ulong)param_1 * 0x13];
}



//------------------------------------------------------------
// DATARMNETa6e92c3315 @ 0010d714 size=136
// signature: undefined DATARMNETa6e92c3315(void)
// callers: [DATARMNET39391a8bc5, DATARMNETf5b8fce55d, DATARMNET3ae0d614d6, DATARMNETb062995420]
//------------------------------------------------------------

void DATARMNETa6e92c3315(long param_1)

{
  *(undefined1 *)(param_1 + 0x13f) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x137) = 0;
  *(undefined8 *)(param_1 + 0x128) = 0;
  *(undefined8 *)(param_1 + 0x130) = 0xffffffff;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined8 *)(param_1 + 0x78) = 0;
  *(undefined8 *)(param_1 + 0x80) = 0;
  *(undefined8 *)(param_1 + 0x88) = 0;
  *(undefined8 *)(param_1 + 0x90) = 0;
  *(undefined8 *)(param_1 + 0x98) = 0;
  *(undefined8 *)(param_1 + 0xa0) = 0;
  *(undefined8 *)(param_1 + 0xc0) = 0;
  *(undefined8 *)(param_1 + 200) = 0;
  *(undefined8 *)(param_1 + 0xd0) = 0;
  *(undefined8 *)(param_1 + 0xd8) = 0;
  *(undefined8 *)(param_1 + 0xe0) = 0;
  *(undefined8 *)(param_1 + 0xe8) = 0;
  *(undefined8 *)(param_1 + 0xf0) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0;
  *(undefined8 *)(param_1 + 0x108) = 0;
  *(undefined8 *)(param_1 + 0x110) = 0;
  *(undefined8 *)(param_1 + 0x118) = 0;
  *(undefined8 *)(param_1 + 0x120) = 0;
  *(long *)(param_1 + 0x40) = param_1 + 0x40;
  *(long *)(param_1 + 0x48) = param_1 + 0x40;
  *(undefined1 *)(param_1 + 0x13e) = 0;
  *(undefined1 *)(param_1 + 0x13c) = 0;
  return;
}



//------------------------------------------------------------
// DATARMNETf5b8fce55d @ 0010d820 size=168
// signature: undefined DATARMNETf5b8fce55d(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETf5b8fce55d(char param_1,undefined1 param_2)

{
  long lVar1;
  
  if (param_1 != '\0') {
    do {
      lVar1 = kmalloc_trace(_ktime_get_with_offset,0xb20,0x140);
      if (lVar1 == 0) {
        DAT_0011da60 = DAT_0011da60 + 1;
      }
      else {
        *(undefined1 *)(lVar1 + 0x13d) = param_2;
        DATARMNETa6e92c3315();
        *(long *)(lVar1 + 0x50) = lVar1 + 0x50;
        *(long *)(lVar1 + 0x58) = lVar1 + 0x50;
        *(long *)(lVar1 + 0x40) = lVar1 + 0x40;
        *(long *)(lVar1 + 0x48) = lVar1 + 0x40;
        DATARMNET36e5e526fa(lVar1);
      }
      param_1 = param_1 + -1;
    } while (param_1 != '\0');
  }
  return;
}



//------------------------------------------------------------
// DATARMNETb062995420 @ 0010d8cc size=268
// signature: undefined DATARMNETb062995420(void)
// callers: [DATARMNET350f55bfca]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined ** DATARMNETb062995420(void)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  
  __rcu_read_lock();
  _raw_spin_lock_bh(&DATARMNETfbdbab2ef6);
  ppuVar2 = &DATARMNET9825511866;
  do {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &DATARMNET9825511866) {
      ppuVar1 = (undefined **)0x0;
      goto LAB_0010d934;
    }
  } while (*(char *)((long)ppuVar2 + 0xec) != '\0');
  ppuVar1 = ppuVar2 + -10;
  *(undefined1 *)((long)ppuVar2 + 0xec) = 1;
  *(undefined1 *)((long)ppuVar2 + 0xee) = 1;
LAB_0010d934:
  _raw_spin_unlock_bh(&DATARMNETfbdbab2ef6);
  __rcu_read_unlock();
  if (ppuVar1 == (undefined **)0x0) {
    ppuVar1 = (undefined **)kmalloc_trace(_ktime_get_with_offset,0xb20,0x140);
    if (ppuVar1 == (undefined **)0x0) {
      DAT_0011da60 = DAT_0011da60 + 1;
    }
    else {
      DATARMNETa6e92c3315(ppuVar1);
      *(undefined2 *)((long)ppuVar1 + 0x13c) = 1;
      *(undefined1 *)((long)ppuVar1 + 0x13e) = 1;
      ppuVar1[10] = (undefined *)(ppuVar1 + 10);
      ppuVar1[0xb] = (undefined *)(ppuVar1 + 10);
      ppuVar1[8] = (undefined *)(ppuVar1 + 8);
      ppuVar1[9] = (undefined *)(ppuVar1 + 8);
      DATARMNET36e5e526fa(ppuVar1);
    }
  }
  return ppuVar1;
}



//------------------------------------------------------------
// DATARMNET350f55bfca @ 0010dae0 size=236
// signature: undefined DATARMNET350f55bfca(void)
// callers: [DATARMNETf5821256ad, DATARMNET756778f14f]
//------------------------------------------------------------

void DATARMNET350f55bfca(long param_1)

{
  int iVar1;
  long lVar2;
  undefined1 auVar3 [16];
  
  if (param_1 == 0) {
    DAT_0011daa8 = DAT_0011daa8 + 1;
  }
  else {
    lVar2 = DATARMNETb062995420();
    *(long *)(param_1 + 0x58) = lVar2;
    if (lVar2 != 0) {
      ktime_get_with_offset(1);
      auVar3 = ns_to_timespec64();
      *(undefined4 *)(*(long *)(param_1 + 0x58) + 0x124) = *(undefined4 *)(param_1 + 0xc0);
      *(undefined2 *)(*(long *)(param_1 + 0x58) + 0x138) = *(undefined2 *)(param_1 + 0xd8);
      *(undefined2 *)(*(long *)(param_1 + 0x58) + 0x136) = *(undefined2 *)(param_1 + 0xce);
      *(undefined2 *)(*(long *)(param_1 + 0x58) + 0x134) = *(undefined2 *)(param_1 + 0xce);
      iVar1 = DATARMNETc252c204a8;
      *(undefined1 *)(*(long *)(param_1 + 0x58) + 0x13f) = 0;
      if ((iVar1 != 0) && (*(short *)(*(long *)(param_1 + 0x58) + 0x138) == 6)) {
        *(undefined1 *)(*(long *)(param_1 + 0x58) + 0x13f) = 2;
      }
      *(long *)(*(long *)(param_1 + 0x58) + 0x60) = param_1;
      lVar2 = auVar3._8_8_ + auVar3._0_8_ * 1000000000;
      *(long *)(*(long *)(param_1 + 0x58) + 0x68) = lVar2;
      *(long *)(*(long *)(param_1 + 0x58) + 0x70) = lVar2;
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNET0aa47ce397 @ 0010dc54 size=200
// signature: undefined DATARMNET0aa47ce397(void)
// callers: [DATARMNET9a7769cf21]
//------------------------------------------------------------

void DATARMNET0aa47ce397(long param_1)

{
  undefined **ppuVar1;
  long lVar2;
  
  if (param_1 == 0) {
    DAT_0011daa8 = DAT_0011daa8 + 1;
  }
  else {
    ppuVar1 = &DATARMNET30a3e83974;
    do {
      ppuVar1 = (undefined **)*ppuVar1;
      if (ppuVar1 == &DATARMNET30a3e83974) {
        return;
      }
    } while (*(undefined **)(*(long *)(param_1 + 0x60) + 0x50) != ppuVar1[2]);
    *(uint *)(param_1 + 0x110) = (uint)*(ushort *)((long)ppuVar1 + 0x5c);
    *(uint *)(param_1 + 0x118) = (uint)*(ushort *)(ppuVar1 + 0xb);
    *(uint *)(param_1 + 0x11c) = (uint)*(ushort *)((long)ppuVar1 + 0x5a);
    if (*(short *)(param_1 + 0x138) == 6) {
      lVar2 = -0x10;
    }
    else {
      if (*(short *)(param_1 + 0x138) != 0x11) {
        return;
      }
      lVar2 = -8;
    }
    *(long *)((long)ppuVar1 + lVar2) = *(long *)((long)ppuVar1 + lVar2) + *(long *)(param_1 + 0xa0);
  }
  return;
}



//------------------------------------------------------------
// DATARMNETc55315279b @ 0010dd94 size=452
// signature: undefined DATARMNETc55315279b(void)
// callers: [DATARMNET9a7769cf21]
//------------------------------------------------------------

void DATARMNETc55315279b(long param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  
  if (DATARMNET58b009b16b == 0) {
    return;
  }
  if ((param_1 == 0) || (param_2 == 0)) {
    DAT_0011daa8 = DAT_0011daa8 + 1;
    return;
  }
  uVar3 = *(uint *)(param_1 + 0x130);
  if ((int)uVar3 < 0) {
    uVar1 = -DATARMNETe038d33545;
    uVar3 = DATARMNETe038d33545 & 0x1f;
    DATARMNETe038d33545 = DATARMNETe038d33545 + 1;
    if (-1 < (int)uVar1) {
      uVar3 = -(uVar1 & 0x1f);
    }
    *(uint *)(param_1 + 0x130) = uVar3;
  }
  if (uVar3 < 0x20) {
    *(ulong *)(DATARMNETbf3b6fdfc8 + (ulong)uVar3 * 8) = (ulong)*(uint *)(param_1 + 0x124);
    if (*(uint *)(param_1 + 0x130) < 0x20) {
      *(ulong *)(DATARMNET0fec241216 + (ulong)*(uint *)(param_1 + 0x130) * 8) =
           (ulong)*(ushort *)(param_2 + 0xd8);
      if (*(uint *)(param_1 + 0x130) < 0x20) {
        *(long *)(DATARMNET9e5e8e4048 + (ulong)*(uint *)(param_1 + 0x130) * 8) =
             *(long *)(param_1 + 0x78) / 1000000000;
        if (*(uint *)(param_1 + 0x130) < 0x20) {
          *(undefined8 *)(DATARMNET4b1ae621cd + (ulong)*(uint *)(param_1 + 0x130) * 8) =
               *(undefined8 *)(param_1 + 0xa0);
          if (*(uint *)(param_1 + 0x130) < 0x20) {
            *(undefined8 *)(DATARMNETf5133a99c6 + (ulong)*(uint *)(param_1 + 0x130) * 8) =
                 *(undefined8 *)(param_1 + 0x98);
            if (*(uint *)(param_1 + 0x130) < 0x20) {
              *(undefined8 *)(DATARMNET47956cbb0f + (ulong)*(uint *)(param_1 + 0x130) * 8) =
                   *(undefined8 *)(param_1 + 0x88);
              if (*(uint *)(param_1 + 0x130) < 0x20) {
                *(undefined8 *)(DATARMNET338c8e7a2b + (ulong)*(uint *)(param_1 + 0x130) * 8) =
                     *(undefined8 *)(param_1 + 0x80);
                if (*(uint *)(param_1 + 0x130) < 0x20) {
                  *(uint *)(&DATARMNETdba344c809 + (ulong)*(uint *)(param_1 + 0x130) * 4) =
                       (uint)*(ushort *)(param_1 + 0x136);
                  if (*(uint *)(param_1 + 0x130) < 0x20) {
                    *(uint *)(DATARMNET99a934c43a + (ulong)*(uint *)(param_1 + 0x130) * 4) =
                         (uint)*(ushort *)(param_1 + 0x134);
                    if (*(uint *)(param_1 + 0x130) < 0x20) {
                      *(undefined8 *)(DATARMNETc5d73c43e6 + (ulong)*(uint *)(param_1 + 0x130) * 8) =
                           *(undefined8 *)(param_1 + 8);
                      if (*(uint *)(param_1 + 0x130) < 0x20) {
                        *(undefined8 *)(DATARMNETf4aa8ec23f + (ulong)*(uint *)(param_1 + 0x130) * 8)
                             = *(undefined8 *)(param_1 + 0x10);
                        if (*(uint *)(param_1 + 0x130) < 0x20) {
                          *(undefined8 *)
                           (DATARMNET6d75219ffb + (ulong)*(uint *)(param_1 + 0x130) * 8) =
                               *(undefined8 *)(param_1 + 0x18);
                          return;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10df58);
  (*pcVar2)();
}



//------------------------------------------------------------
// DATARMNETd245b71b63 @ 0010df5c size=52
// signature: undefined DATARMNETd245b71b63(void)
// callers: []
//------------------------------------------------------------

bool DATARMNETd245b71b63(long param_1,long param_2)

{
  if ((param_1 == 0) || (param_2 == 0)) {
    DAT_0011daa8 = DAT_0011daa8 + 1;
    return false;
  }
  return *(long *)(param_2 + 0x90) != *(long *)(param_1 + 0x80);
}



//------------------------------------------------------------
// DATARMNETb49b4f6385 @ 0010df94 size=100
// signature: undefined DATARMNETb49b4f6385(void)
// callers: [DATARMNET9a7769cf21]
//------------------------------------------------------------

void DATARMNETb49b4f6385(long param_1,long param_2)

{
  if ((param_1 == 0) || (param_2 == 0)) {
    DAT_0011daa8 = DAT_0011daa8 + 1;
  }
  else {
    *(long *)(param_1 + 0x78) = DATARMNETb3a4036d6d - *(long *)(param_1 + 0x68);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET9a7769cf21 @ 0010e074 size=644
// signature: undefined DATARMNET9a7769cf21(void)
// callers: [DATARMNETcd6e26f0ad]
//------------------------------------------------------------

void DATARMNET9a7769cf21(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                        undefined8 param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  ulong uVar14;
  
  if (param_1 == 0) {
    DAT_0011daa8 = DAT_0011daa8 + 1;
  }
  else {
    lVar12 = *(long *)(param_1 + 0x60);
    if (lVar12 == 0) {
      DAT_0011daa8 = DAT_0011daa8 + 1;
    }
    else if (*(long *)(lVar12 + 0x90) != *(long *)(param_1 + 0x80)) {
      DATARMNET0aa47ce397(param_1,param_2,param_3,*(undefined4 *)(param_1 + 0x124),param_5,
                          *(undefined8 *)(param_1 + 0x98),*(undefined8 *)(param_1 + 0xa0));
      *(undefined8 *)(param_1 + 0x78) = 0;
      lVar11 = DATARMNETb3a4036d6d;
      lVar6 = *(long *)(*(long *)(lVar12 + 0x58) + 0x68);
      *(long *)(param_1 + 0x70) = lVar6;
      uVar7 = lVar11 - lVar6;
      lVar6 = *(long *)(*(long *)(lVar12 + 0x58) + 0x80);
      *(long *)(param_1 + 0xf0) = lVar6;
      iVar5 = *(int *)(*(long *)(lVar12 + 0x58) + 0x10c);
      *(int *)(param_1 + 0x108) = iVar5;
      lVar13 = *(long *)(*(long *)(lVar12 + 0x58) + 0x90);
      *(long *)(param_1 + 0xf8) = lVar13;
      *(undefined8 *)(param_1 + 0xd0) = *(undefined8 *)(*(long *)(lVar12 + 0x58) + 0xe0);
      *(undefined8 *)(param_1 + 0xd8) = *(undefined8 *)(*(long *)(lVar12 + 0x58) + 0xe8);
      lVar10 = *(long *)(*(long *)(lVar12 + 0x58) + 0x88);
      *(long *)(param_1 + 0x68) = lVar11;
      *(long *)(param_1 + 0x100) = lVar10;
      lVar11 = *(long *)(lVar12 + 0x90);
      *(long *)(param_1 + 0x80) = lVar11;
      uVar14 = lVar11 - lVar6;
      iVar2 = *(int *)(lVar12 + 0xb8);
      *(int *)(param_1 + 0x10c) = iVar2;
      *(bool *)(param_1 + 0x13a) = iVar2 != iVar5;
      iVar5 = DATARMNET1fc3ad67fd;
      lVar11 = *(long *)(lVar12 + 0x98);
      bVar4 = DATARMNET1fc3ad67fd == 0;
      *(long *)(param_1 + 0x90) = lVar11;
      *(undefined8 *)(param_1 + 0xe0) = *(undefined8 *)(lVar12 + 0xa8);
      if (bVar4 || (long)uVar7 <= (long)(ulong)(uint)(iVar5 * 1000000)) {
        uVar7 = 100000000;
      }
      *(undefined8 *)(param_1 + 0xe8) = *(undefined8 *)(lVar12 + 0xb0);
      uVar8 = 0;
      if (uVar7 != 0) {
        uVar8 = (uVar14 * 1000000000) / uVar7;
      }
      lVar6 = *(long *)(lVar12 + 0xa0);
      *(long *)(param_1 + 0x88) = lVar6;
      uVar9 = 0;
      if (uVar7 != 0) {
        uVar9 = (ulong)((lVar6 - lVar10) * 1000000000) / uVar7;
      }
      *(ulong *)(param_1 + 0x98) = uVar8;
      *(ulong *)(param_1 + 0xa0) = uVar9 << 3;
      iVar5 = DATARMNET362b15f941(*(undefined2 *)(param_1 + 0x136));
      if (*(long *)(param_1 + 0xa8) == 0) {
        uVar8 = *(ulong *)(param_1 + 0x98);
        uVar7 = uVar8;
      }
      else {
        uVar8 = *(ulong *)(param_1 + 0x98);
        uVar1 = 100 - DATARMNETcab56af6d5;
        uVar3 = DATARMNETcab56af6d5;
        if (iVar5 != 0) {
          uVar1 = DATARMNETcab56af6d5;
          uVar3 = 100 - DATARMNETcab56af6d5;
        }
        uVar9 = (ulong)((uVar3 & 0xffff) + (uVar1 & 0xffff));
        uVar7 = 0;
        if (uVar9 != 0) {
          uVar7 = (((ulong)(*(long *)(param_1 + 0xb0) + *(long *)(param_1 + 0xa8)) >> 1) *
                   (ulong)(uVar3 & 0xffff) + uVar8 * ((ulong)uVar1 & 0xffff)) / uVar9;
        }
      }
      uVar9 = lVar11 - lVar13;
      *(ulong *)(param_1 + 0xb0) = uVar7;
      if (uVar9 == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = 0;
        if (uVar9 != 0) {
          uVar7 = uVar14 / uVar9;
        }
      }
      *(ulong *)(param_1 + 0xa8) = uVar8;
      *(ulong *)(param_1 + 0xb8) = uVar7;
      *(long *)(param_1 + 0xc0) = *(long *)(param_1 + 0xe0) - *(long *)(param_1 + 0xd0);
      *(long *)(param_1 + 200) = *(long *)(param_1 + 0xe8) - *(long *)(param_1 + 0xd8);
      DATARMNETc55315279b(param_1,lVar12);
      *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(lVar12 + 0xc4);
      *(undefined4 *)(param_1 + 300) = *(undefined4 *)(lVar12 + 200);
      return;
    }
    *(undefined8 *)(param_1 + 0xb0) = 0;
    *(undefined8 *)(param_1 + 0x98) = 0;
    *(undefined8 *)(param_1 + 0xa0) = 0;
    DATARMNETb49b4f6385(param_1,lVar12);
    DATARMNETc55315279b(param_1,lVar12);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET5b2ed86112 @ 0010e3e8 size=364
// signature: undefined DATARMNET5b2ed86112(void)
// callers: [DATARMNETcd6e26f0ad]
//------------------------------------------------------------

void DATARMNET5b2ed86112(long param_1,undefined8 param_2,undefined8 param_3)

{
  ushort uVar1;
  code *pcVar2;
  long lVar3;
  long *plVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  
  if (param_1 == 0) {
    lVar3 = 1;
    plVar4 = &DAT_0011daa8;
    goto LAB_0010e524;
  }
  if (0 < *(long *)(param_1 + 0x78)) {
    return;
  }
  uVar1 = *(ushort *)(*(long *)(param_1 + 0x60) + 0xce);
  if (7 < (ulong)uVar1) {
    lVar3 = 1;
    plVar4 = &DAT_0011da20;
    goto LAB_0010e524;
  }
  lVar5 = *(long *)(param_1 + 0x80);
  lVar3 = *(long *)(param_1 + 0x88);
  lVar8 = *(long *)(param_1 + 0xf0);
  lVar7 = *(long *)(param_1 + 0x100);
  uVar6 = (uint)uVar1;
  if ((uint)uVar1 == (uint)*(ushort *)(param_1 + 0x136)) {
    if (*(char *)(param_1 + 0x13e) != '\0') {
LAB_0010e47c:
      DATARMNET0349051465(uVar6);
      DATARMNETd8a6375e9c(param_1,uVar6 * 0x98 + 0x11db38);
      *(undefined1 *)(param_1 + 0x13e) = 0;
      goto LAB_0010e4c4;
    }
  }
  else {
    if (*(char *)(param_1 + 0x13e) != '\0') goto LAB_0010e47c;
    DATARMNET9914e9761e(param_1,(uint)uVar1 * 0x98 + 0x11db38,param_3,
                        *(undefined4 *)(param_1 + 0x124));
    DATARMNET0349051465(uVar6);
    DATARMNET3669e7b703(*(undefined2 *)(param_1 + 0x136));
LAB_0010e4c4:
    *(ushort *)(param_1 + 0x136) = uVar1;
  }
  uVar6 = (uint)uVar1;
  if ((ulong)uVar1 * 0x98 < 0x591) {
    lVar5 = lVar5 - lVar8;
    (&DAT_0011db68)[(ulong)uVar6 * 0x13] = (&DAT_0011db68)[(ulong)uVar6 * 0x13] + lVar5;
    if (uVar6 * 0x98 < 0x589) {
      lVar3 = lVar3 - lVar7;
      (&DAT_0011db70)[(ulong)uVar6 * 0x13] = (&DAT_0011db70)[(ulong)uVar6 * 0x13] + lVar3;
      DAT_0011e058 = DAT_0011e058 + lVar5;
      plVar4 = &DAT_0011e060;
LAB_0010e524:
      *plVar4 = *plVar4 + lVar3;
      return;
    }
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(1,0x10e554);
  (*pcVar2)();
}



//------------------------------------------------------------
// DATARMNET0349051465 @ 0010e5d4 size=128
// signature: undefined DATARMNET0349051465(void)
// callers: [DATARMNET5b2ed86112]
//------------------------------------------------------------

void DATARMNET0349051465(ushort param_1)

{
  code *pcVar1;
  ulong uVar2;
  
  if (param_1 < 8) {
    uVar2 = (ulong)param_1;
    if (0x534 < uVar2 * 0x98) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(1,0x10e654);
      (*pcVar1)();
    }
    (&DAT_0011dbc4)[uVar2 * 0x26] = (&DAT_0011dbc4)[uVar2 * 0x26] + 1;
  }
  else {
    DAT_0011daa0 = DAT_0011daa0 + 1;
  }
  return;
}



//------------------------------------------------------------
// DATARMNET3669e7b703 @ 0010e6d4 size=140
// signature: undefined DATARMNET3669e7b703(void)
// callers: [DATARMNET39391a8bc5, DATARMNET5b2ed86112]
//------------------------------------------------------------

void DATARMNET3669e7b703(ushort param_1)

{
  int iVar1;
  code *pcVar2;
  ulong uVar3;
  
  if (param_1 < 8) {
    uVar3 = (ulong)param_1 * 0x98;
    if (0x534 < uVar3) {
LAB_0010e75c:
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x10e760);
      (*pcVar2)();
    }
    iVar1 = (&DAT_0011dbc4)[(ulong)param_1 * 0x26];
    if (0 < iVar1) {
      if (0x534 < uVar3) goto LAB_0010e75c;
      (&DAT_0011dbc4)[(ulong)param_1 * 0x26] = iVar1 + -1;
    }
  }
  else {
    DAT_0011daa0 = DAT_0011daa0 + 1;
  }
  return;
}



//------------------------------------------------------------
// DATARMNETdfb8ee742f @ 0010e7e0 size=228
// signature: undefined DATARMNETdfb8ee742f(void)
// callers: [DATARMNET466244e5d6, DATARMNET95736008d9]
//------------------------------------------------------------

void DATARMNETdfb8ee742f(short param_1,undefined2 param_2,long param_3)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  _raw_spin_lock_bh(&DATARMNET3764d083f0);
  lVar2 = 0;
  uVar1 = sp_el0;
  do {
    lVar3 = (&DATARMNETbfe1afe595)[lVar2] + -0x80;
    if ((&DATARMNETbfe1afe595)[lVar2] != 0 && lVar3 != 0) {
      do {
        lVar4 = *(long *)(lVar3 + 0x80);
        if (((*(long *)(lVar3 + 0x58) != 0) &&
            (*(short *)(*(long *)(lVar3 + 0x58) + 0x134) == param_1)) &&
           (*(long *)(lVar3 + 0x50) == *(long *)(param_3 + 0x20))) {
          *(undefined2 *)(*(long *)(lVar3 + 0x58) + 0x134) = param_2;
        }
      } while ((lVar4 != 0) && (lVar3 = lVar4 + -0x80, lVar3 != 0));
    }
    lVar2 = lVar2 + 1;
  } while (lVar2 != 0x200);
  _raw_spin_unlock_bh(&DATARMNET3764d083f0);
  return;
}



//------------------------------------------------------------
// DATARMNETd406e89a85 @ 0010e980 size=164
// signature: undefined DATARMNETd406e89a85(void)
// callers: []
//------------------------------------------------------------

ulong DATARMNETd406e89a85(ulong param_1)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar2 = 0;
  if ((param_1 & 1) != 0) {
    uVar2 = DAT_0011db80;
  }
  uVar1 = DAT_0011dc18;
  if (DAT_0011dc18 <= uVar2) {
    uVar1 = uVar2;
  }
  if ((param_1 & 2) != 0) {
    uVar2 = uVar1;
  }
  uVar1 = DAT_0011dcb0;
  if (DAT_0011dcb0 <= uVar2) {
    uVar1 = uVar2;
  }
  if ((param_1 & 4) != 0) {
    uVar2 = uVar1;
  }
  uVar1 = DAT_0011dd48;
  if (DAT_0011dd48 <= uVar2) {
    uVar1 = uVar2;
  }
  if ((param_1 & 8) != 0) {
    uVar2 = uVar1;
  }
  uVar1 = DAT_0011dde0;
  if (DAT_0011dde0 <= uVar2) {
    uVar1 = uVar2;
  }
  if ((param_1 & 0x10) != 0) {
    uVar2 = uVar1;
  }
  uVar1 = DAT_0011de78;
  if (DAT_0011de78 <= uVar2) {
    uVar1 = uVar2;
  }
  if ((param_1 & 0x20) != 0) {
    uVar2 = uVar1;
  }
  uVar1 = DAT_0011df10;
  if (DAT_0011df10 <= uVar2) {
    uVar1 = uVar2;
  }
  if ((param_1 & 0x40) != 0) {
    uVar2 = uVar1;
  }
  uVar1 = DAT_0011dfa8;
  if (DAT_0011dfa8 <= uVar2) {
    uVar1 = uVar2;
  }
  if ((param_1 & 0x80) != 0) {
    uVar2 = uVar1;
  }
  return uVar2;
}



//------------------------------------------------------------
// DATARMNET362c14e98b @ 0010ea28 size=272
// signature: undefined DATARMNET362c14e98b(void)
// callers: [DATARMNET756778f14f, DATARMNETcd6e26f0ad, DATARMNETe00453a3e4]
//------------------------------------------------------------

ulong DATARMNET362c14e98b(uint param_1)

{
  uint uVar1;
  undefined8 uVar2;
  bool bVar3;
  ulong uVar4;
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  uint uVar10;
  ulong *puVar11;
  uint uVar12;
  uint uVar13;
  ulong uVar14;
  
  puVar11 = &DAT_0011dfa8;
  uVar12 = 0xffffffff;
  uVar13 = 0xffffffff;
  uVar2 = sp_el0;
  uVar6 = 7;
  uVar8 = 0xffffffffffffffff;
  uVar10 = 0xffffffff;
  do {
    uVar5 = (uint)uVar6;
    uVar7 = uVar8;
    uVar9 = uVar10;
    if (((((param_1 & 0xffff) >> (ulong)(uVar5 & 0x1f) & 1) != 0) &&
        (uVar14 = 1L << (uVar6 & 0x3f),
        (*(ulong *)(&__cpu_online_mask + (uVar6 >> 3 & 0x1ffffffffffffff8)) & uVar14) != 0)) &&
       (uVar4 = walt_get_cpus_taken(), (uVar4 & uVar14) == 0)) {
      uVar1 = *(uint *)((long)puVar11 + 0x44);
      if (uVar1 == 0) goto LAB_0010eb8c;
      uVar14 = *puVar11;
      uVar9 = uVar5;
      if (uVar14 != 0 || uVar13 <= uVar1) {
        uVar9 = uVar10;
        uVar1 = uVar13;
      }
      uVar13 = uVar1;
      uVar7 = uVar14;
      if (uVar8 <= uVar14) {
        uVar7 = uVar8;
      }
      if (uVar14 <= uVar8) {
        uVar12 = uVar5;
      }
    }
    puVar11 = puVar11 + -0x13;
    bVar3 = uVar6 != 0;
    uVar6 = uVar6 - 1;
    uVar8 = uVar7;
    uVar10 = uVar9;
  } while (bVar3);
  if (-1 < (int)uVar9) {
    uVar12 = uVar9;
  }
  uVar6 = (ulong)uVar12;
LAB_0010eb8c:
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// DATARMNET3c1fc10379 @ 0010ebb8 size=464
// signature: undefined DATARMNET3c1fc10379(void)
// callers: [DATARMNET466244e5d6, DATARMNET95736008d9]
//------------------------------------------------------------

ulong DATARMNET3c1fc10379(ulong param_1,long param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  long *plVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  
  uVar7 = param_1 & 0xffffffff;
  if (param_2 == 0) {
    DAT_0011da78 = DAT_0011da78 + 1;
    return uVar7;
  }
  if (((uint)param_1 & 0xffff) < 9) {
    uVar9 = param_1 & 0xffff;
    if (0x578 < uVar9 * 0x98) {
LAB_0010ee70:
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x10ee74);
      (*pcVar3)();
    }
    if (((uint)param_1 & 0xffff) != 8) {
      uVar10 = (&DATARMNET4793ed48af)[uVar9];
      uVar8 = (&DAT_0011db80)[uVar9 * 0x13];
      iVar4 = DATARMNET362b15f941(uVar7);
      if (((iVar4 != 0) || (uVar8 <= uVar10)) && ((&DAT_0011cb4d)[uVar9 * 0x28] == '\0')) {
        uVar10 = 0;
        plVar6 = &DAT_0011db80;
        uVar2 = sp_el0;
        do {
          if (((uVar9 != uVar10) &&
              (uVar5 = (uint)uVar10,
              (1 << (ulong)(uVar5 & 0x1f) & (uint)*(byte *)(param_2 + 0x6c) &
              (((byte)DATARMNET121c8bc82a | DATARMNETecc0627c70[0x66f]) ^ 0xff)) != 0)) &&
             ((*(ulong *)(&__cpu_online_mask + (uVar10 >> 3 & 0x1ffffffffffffff8)) >>
               (uVar10 & 0x3f) & 1) != 0)) {
            uVar1 = *plVar6 + uVar8;
            if (((ulong)(&DATARMNET713717107f)[uVar10] <= uVar1 ||
                uVar1 <= (ulong)(&DATARMNET4793ed48af)[uVar10]) || *plVar6 != 0) {
              uVar5 = (uint)uVar7;
            }
            uVar7 = (ulong)uVar5;
          }
          uVar10 = uVar10 + 1;
          plVar6 = plVar6 + 0x13;
        } while (uVar10 != 8);
        if (7 < ((uint)uVar7 & 0xffff)) goto LAB_0010ee6c;
        if (0x578 < (uVar7 & 0xffff) * 0x98) goto LAB_0010ee70;
      }
      return uVar7;
    }
  }
LAB_0010ee6c:
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10ee70);
  (*pcVar3)();
}



//------------------------------------------------------------
// DATARMNET466244e5d6 @ 0010eee0 size=136
// signature: undefined DATARMNET466244e5d6(void)
// callers: []
//------------------------------------------------------------

void DATARMNET466244e5d6(uint param_1)

{
  uint uVar1;
  undefined **ppuVar2;
  
  ppuVar2 = (undefined **)DATARMNET30a3e83974;
  if ((undefined **)DATARMNET30a3e83974 != &DATARMNET30a3e83974) {
    do {
      if (*(char *)((long)ppuVar2 + 0x5e) != '\0') {
        uVar1 = DATARMNET3c1fc10379(param_1,ppuVar2 + -2);
        if ((uVar1 & 0xffff) != (param_1 & 0xffff)) {
          DATARMNETdfb8ee742f(param_1,uVar1,ppuVar2 + -2);
        }
      }
      ppuVar2 = (undefined **)*ppuVar2;
    } while (ppuVar2 != &DATARMNET30a3e83974);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET769bbe36c6 @ 0010ef6c size=164
// signature: undefined DATARMNET769bbe36c6(void)
// callers: []
//------------------------------------------------------------

uint DATARMNET769bbe36c6(uint param_1,uint param_2,long param_3)

{
  uint uVar1;
  
  if (param_3 == 0) {
    DAT_0011da78 = DAT_0011da78 + 1;
    return 0;
  }
  uVar1 = param_2 & 0xffff;
  if (7 < (uVar1 | param_1 & 0xffff)) {
    DAT_0011daa0 = DAT_0011daa0 + 1;
    return 0;
  }
  if ((param_1 & 0xffff) == uVar1) {
    return 0;
  }
  return (uint)(*(ulong *)(&__cpu_online_mask + ((ulong)(uVar1 >> 3) & 0x1ff8)) >>
               ((ulong)uVar1 & 0x3f)) &
         (uint)((1 << (ulong)(param_2 & 0x1f) & (uint)*(ushort *)(param_3 + 0x6c) &
                ((DATARMNET121c8bc82a | DATARMNETecc0627c70[0x66f]) ^ 0xffffffff)) != 0);
}



//------------------------------------------------------------
// DATARMNET5f72606f6f @ 0010f014 size=612
// signature: undefined DATARMNET5f72606f6f(void)
// callers: [DATARMNET29175fb5fc]
//------------------------------------------------------------

undefined8 DATARMNET5f72606f6f(uint param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  undefined8 uVar2;
  bool bVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined **ppuVar7;
  long lVar8;
  
  uVar1 = param_2 & 0xffff;
  param_1 = param_1 & 0xffff;
  if ((uVar1 | param_1) < 8) {
    _raw_spin_lock_bh(&DATARMNETec2a4f5211);
    if ((undefined **)DATARMNET30a3e83974 != &DATARMNET30a3e83974) {
      uVar2 = sp_el0;
      ppuVar7 = (undefined **)DATARMNET30a3e83974;
      do {
        if (*(char *)((long)ppuVar7 + 0x5e) != '\0') {
          if (ppuVar7 == (undefined **)0x10) {
            DAT_0011da78 = DAT_0011da78 + 1;
          }
          else if (((param_1 != uVar1) &&
                   ((*(ulong *)(&__cpu_online_mask + (ulong)(uVar1 >> 6) * 8) &
                    1L << ((ulong)uVar1 & 0x3f)) != 0)) &&
                  ((1 << (ulong)(param_2 & 0x1f) & (uint)*(ushort *)((long)ppuVar7 + 0x5c) &
                   ((DATARMNET121c8bc82a | DATARMNETecc0627c70[0x66f]) ^ 0xffffffff)) != 0)) {
            _raw_spin_lock_bh(&DATARMNET3764d083f0);
            lVar8 = 0;
            bVar3 = false;
            do {
              lVar6 = (&DATARMNETbfe1afe595)[lVar8] + -0x80;
              if ((&DATARMNETbfe1afe595)[lVar8] != 0 && lVar6 != 0) {
                do {
                  lVar4 = *(long *)(lVar6 + 0x58);
                  lVar5 = *(long *)(lVar6 + 0x80);
                  if ((((lVar4 != 0) && ((param_3 == 0 || (*(int *)(lVar4 + 0x124) == param_3)))) &&
                      (*(ushort *)(lVar4 + 0x134) == param_1)) &&
                     (*(undefined **)(lVar6 + 0x50) == ppuVar7[2])) {
                    *(short *)(*(long *)(lVar6 + 0x58) + 0x134) = (short)param_2;
                    if (param_4 < 8) {
                      *(long *)(lVar4 + (ulong)param_4 * 8) =
                           *(long *)(lVar4 + (ulong)param_4 * 8) + 1;
                    }
                    if (param_3 != 0) {
                      _raw_spin_unlock_bh(&DATARMNET3764d083f0);
                      goto LAB_0010f2dc;
                    }
                    bVar3 = true;
                  }
                } while ((lVar5 != 0) && (lVar6 = lVar5 + -0x80, lVar6 != 0));
              }
              lVar8 = lVar8 + 1;
            } while (lVar8 != 0x200);
            _raw_spin_unlock_bh(&DATARMNET3764d083f0);
            if (bVar3) {
LAB_0010f2dc:
              _raw_spin_unlock_bh(&DATARMNETec2a4f5211);
              return 1;
            }
          }
        }
        ppuVar7 = (undefined **)*ppuVar7;
      } while (ppuVar7 != &DATARMNET30a3e83974);
    }
    _raw_spin_unlock_bh(&DATARMNETec2a4f5211);
  }
  else {
    DAT_0011daa0 = DAT_0011daa0 + 1;
  }
  return 0;
}



//------------------------------------------------------------
// DATARMNETf85599b9d8 @ 0010f314 size=200
// signature: undefined DATARMNETf85599b9d8(void)
// callers: [DATARMNETd81d2866ba]
//------------------------------------------------------------

undefined8 DATARMNETf85599b9d8(int param_1,undefined1 param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  _raw_spin_lock_bh(&DATARMNET3764d083f0);
  lVar2 = 0;
  do {
    lVar1 = (&DATARMNETbfe1afe595)[lVar2] + -0x80;
    if ((&DATARMNETbfe1afe595)[lVar2] != 0 && lVar1 != 0) {
      do {
        if ((*(long *)(lVar1 + 0x58) != 0) && (*(int *)(*(long *)(lVar1 + 0x58) + 0x124) == param_1)
           ) {
          uVar3 = 1;
          *(undefined1 *)(*(long *)(lVar1 + 0x58) + 0x13f) = param_2;
          goto LAB_0010f3ac;
        }
      } while ((*(long *)(lVar1 + 0x80) != 0) &&
              (lVar1 = *(long *)(lVar1 + 0x80) + -0x80, lVar1 != 0));
    }
    lVar2 = lVar2 + 1;
    if (lVar2 == 0x200) {
      uVar3 = 0;
LAB_0010f3ac:
      _raw_spin_unlock_bh(&DATARMNET3764d083f0);
      return uVar3;
    }
  } while( true );
}



//------------------------------------------------------------
// DATARMNET1faf2b953f @ 0010f468 size=36
// signature: undefined DATARMNET1faf2b953f(void)
// callers: [DATARMNET9bbfc822c2]
//------------------------------------------------------------

bool DATARMNET1faf2b953f(void)

{
  int iVar1;
  
  iVar1 = rmnet_module_hook_perf_set_thresh();
  return iVar1 != 0;
}



//------------------------------------------------------------
// DATARMNET5e1aaed12b @ 0010f490 size=4
// signature: undefined DATARMNET5e1aaed12b(void)
// callers: []
//------------------------------------------------------------

void DATARMNET5e1aaed12b(void)

{
  return;
}



//------------------------------------------------------------
// DATARMNET468586cca6 @ 0010f498 size=4
// signature: undefined DATARMNET468586cca6(void)
// callers: []
//------------------------------------------------------------

void DATARMNET468586cca6(void)

{
  return;
}



//------------------------------------------------------------
// DATARMNET7792d4f4ad @ 0010f4a0 size=252
// signature: undefined DATARMNET7792d4f4ad(void)
// callers: [DATARMNETcd6e26f0ad]
//------------------------------------------------------------

void DATARMNET7792d4f4ad(long param_1,long param_2,long param_3,long param_4,long param_5)

{
  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) || ((param_4 == 0 || (param_5 == 0))))
  {
    DAT_0011daa8 = DAT_0011daa8 + 1;
  }
  else {
    list_sort(0,param_1,DATARMNET85af86a36d);
    list_sort(0,param_2,DATARMNETd5c15f1ff3);
    list_sort(0,param_4,DATARMNET3c489db64a);
    list_sort(0,param_5,DATARMNET4e292977da);
    DATARMNET5157210c44(param_1);
    DATARMNET0e273eab79(param_2);
    DATARMNETe15af8eb6d(param_3);
    DATARMNET78f3a0ca4f(param_4);
    DATARMNETa3d6c4072d(param_5);
    DATARMNET78666f33a1();
    DATARMNET5945236cd3(0x33c);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET95736008d9 @ 0010f624 size=420
// signature: undefined DATARMNET95736008d9(void)
// callers: [DATARMNETcd6e26f0ad]
//------------------------------------------------------------

void DATARMNET95736008d9(void)

{
  uint uVar1;
  ulong uVar2;
  undefined8 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  undefined **ppuVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
  
  uVar8 = 0;
  uVar3 = sp_el0;
  do {
    if (0 < (int)(&DAT_0011dbc4)[uVar8 * 0x26]) {
      uVar13 = (&DATARMNET713717107f)[uVar8];
      uVar9 = (&DAT_0011db80)[uVar8 * 0x13];
      uVar12 = (&DATARMNET4793ed48af)[uVar8];
      lVar10 = (&DAT_0011db90)[uVar8 * 0x13];
      lVar14 = (&DAT_0011dba0)[uVar8 * 0x13];
      iVar5 = DATARMNET362b15f941(uVar8 & 0xffffffff);
      uVar1 = 100 - DATARMNETcab56af6d5;
      uVar4 = DATARMNETcab56af6d5;
      if (iVar5 != 0) {
        uVar1 = DATARMNETcab56af6d5;
        uVar4 = 100 - DATARMNETcab56af6d5;
      }
      uVar7 = (ulong)((uVar4 & 0xffff) + (uVar1 & 0xffff));
      uVar2 = 0;
      if (uVar7 != 0) {
        uVar2 = (((ulong)(lVar14 + lVar10) >> 1) * (ulong)(uVar4 & 0xffff) +
                uVar9 * ((ulong)uVar1 & 0xffff)) / uVar7;
      }
      (&DAT_0011dba0)[uVar8 * 0x13] = uVar2;
      ppuVar11 = (undefined **)DATARMNET30a3e83974;
      if ((((uVar13 < uVar2) ||
           (((DATARMNET121c8bc82a | DATARMNETecc0627c70[0x66f]) >> (ulong)((uint)uVar8 & 0x1f) & 1)
            != 0)) ||
          ((*(ulong *)(&__cpu_online_mask + (uVar8 >> 3 & 0x1ffffffffffffff8)) >> (uVar8 & 0x3f) & 1
           ) == 0)) || ((uVar2 < uVar12 && (uVar9 < uVar12)))) {
        for (; ppuVar11 != &DATARMNET30a3e83974; ppuVar11 = (undefined **)*ppuVar11) {
          if (*(char *)((long)ppuVar11 + 0x5e) != '\0') {
            uVar6 = DATARMNET3c1fc10379(uVar8 & 0xffffffff,ppuVar11 + -2);
            if (uVar8 != (ushort)uVar6) {
              DATARMNETdfb8ee742f(uVar8 & 0xffffffff,uVar6,ppuVar11 + -2);
            }
          }
        }
      }
    }
    uVar8 = uVar8 + 1;
  } while (uVar8 != 8);
  return;
}



//------------------------------------------------------------
// DATARMNETe00453a3e4 @ 0010f860 size=316
// signature: undefined DATARMNETe00453a3e4(void)
// callers: [DATARMNETcd6e26f0ad, DATARMNET0a6fb12cb2]
//------------------------------------------------------------

void DATARMNETe00453a3e4(long param_1)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  
  if (param_1 == 0) {
    DAT_0011da78 = DAT_0011da78 + 1;
  }
  else {
    lVar4 = 0;
    uVar6 = (uint)*(ushort *)(param_1 + 0x68);
    uVar5 = (uint)*(ushort *)(param_1 + 0x6a);
    *(undefined8 *)(param_1 + 0x28) = 0xffffffffffffffff;
    *(undefined8 *)(param_1 + 0x30) = 0xffffffffffffffff;
    *(undefined8 *)(param_1 + 0x38) = 0xffffffffffffffff;
    *(undefined8 *)(param_1 + 0x40) = 0xffffffffffffffff;
    *(undefined8 *)(param_1 + 0x48) = 0xffffffffffffffff;
    *(undefined8 *)(param_1 + 0x50) = 0xffffffffffffffff;
    *(undefined8 *)(param_1 + 0x58) = 0xffffffffffffffff;
    *(undefined8 *)(param_1 + 0x60) = 0xffffffffffffffff;
    do {
      uVar3 = DATARMNET362c14e98b(uVar6 & ((DATARMNET121c8bc82a | DATARMNETecc0627c70[0x66f]) ^
                                          0xffffffff));
      if ((int)uVar3 < 0) break;
      if (lVar4 == 8) goto LAB_0010fa0c;
      lVar7 = lVar4 * 4;
      uVar6 = uVar6 & (1 << (ulong)(uVar3 & 0x1f) ^ 0xffffffffU);
      lVar4 = lVar4 + 1;
      *(uint *)(param_1 + lVar7 + 0x28) = uVar3;
    } while (uVar6 != 0);
    lVar7 = 0;
    do {
      uVar6 = DATARMNET362c14e98b(uVar5 & ((DATARMNET121c8bc82a | DATARMNETecc0627c70[0x66f]) ^
                                          0xffffffff));
      if ((int)uVar6 < 0) break;
      if (lVar7 == 8) {
LAB_0010fa0c:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10fa10);
        (*pcVar2)();
      }
      lVar1 = lVar7 * 4;
      uVar5 = uVar5 & (1 << (ulong)(uVar6 & 0x1f) ^ 0xffffffffU);
      lVar7 = lVar7 + 1;
      *(uint *)(param_1 + lVar1 + 0x48) = uVar6;
    } while (uVar5 != 0);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(uint *)(param_1 + 0x78) = (uint)lVar4 & 0xff;
    *(uint *)(param_1 + 0x7c) = (uint)lVar7 & 0xff;
  }
  return;
}



//------------------------------------------------------------
// DATARMNET0a6fb12cb2 @ 0010fa88 size=80
// signature: undefined DATARMNET0a6fb12cb2(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

void DATARMNET0a6fb12cb2(void)

{
  undefined **ppuVar1;
  
  for (ppuVar1 = (undefined **)DATARMNET30a3e83974; ppuVar1 != &DATARMNET30a3e83974;
      ppuVar1 = (undefined **)*ppuVar1) {
    if (*(char *)((long)ppuVar1 + 0x5e) != '\0') {
      DATARMNETe00453a3e4(ppuVar1 + -2);
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNET39391a8bc5 @ 0010fadc size=588
// signature: undefined DATARMNET39391a8bc5(void)
// callers: [DATARMNETf7dcab9a9e, DATARMNETb4b5fc9686]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET39391a8bc5(char param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  bool bVar2;
  undefined8 uVar3;
  long *plVar4;
  undefined *puVar5;
  long lVar6;
  undefined **ppuVar7;
  undefined *puVar8;
  undefined **ppuVar9;
  undefined **ppuVar10;
  
  __rcu_read_lock();
  _raw_spin_lock_bh(&DATARMNET3764d083f0);
  if ((undefined **)DATARMNET9825511866 != &DATARMNET9825511866) {
    uVar3 = sp_el0;
    ppuVar10 = (undefined **)DATARMNET9825511866;
    do {
      puVar8 = ppuVar10[2];
      ppuVar7 = (undefined **)*ppuVar10;
      if ((puVar8 != (undefined *)0x0) &&
         ((param_1 != '\0' || (DATARMNETecc0627c70[0x68b] == '\0')))) {
        puVar5 = ppuVar10[5];
        if ((DATARMNETa804c0b904 < (ulong)((long)puVar5 / 1000000000)) ||
           (((2999999999 < (long)puVar5 && (0x8c < DATARMNETecc0627c70._1632_4_)) ||
            ((8999999999 < (long)puVar5 && (0x46 < DATARMNETecc0627c70._1632_4_)))))) {
          if (((puVar8[0xd4] == '\0') || (param_1 != '\0')) || (_rmnet_shs_switch == 0))
          goto LAB_0010fc14;
        }
        else if (param_1 != '\0') {
LAB_0010fc14:
          ppuVar9 = ppuVar10 + -10;
          DATARMNET23c7ddd780(puVar8,1,param_3,*(undefined4 *)(puVar8 + 0xc0));
          DATARMNET3669e7b703(*(undefined2 *)((long)ppuVar10 + 0xe6));
          if (puVar8[0xdb] == '\0') {
            DATARMNETde8ee16f92(puVar8);
            plVar4 = *(long **)(puVar8 + 0x88);
            if (plVar4 != (long *)0x0) {
              lVar6 = *(long *)(puVar8 + 0x80);
              *plVar4 = lVar6;
              if (lVar6 != 0) {
                *(long **)(lVar6 + 8) = plVar4;
              }
              *(undefined8 *)(puVar8 + 0x88) = 0;
            }
            *(undefined8 *)(puVar8 + 0x40) = 0;
            *(undefined8 *)(puVar8 + 0x48) = 0;
            kfree(puVar8);
          }
          else {
            _raw_spin_lock_bh(&DATARMNETd83ee17944);
            DATARMNETde8ee16f92(puVar8);
            plVar4 = *(long **)(puVar8 + 0x88);
            if (plVar4 != (long *)0x0) {
              lVar6 = *(long *)(puVar8 + 0x80);
              *plVar4 = lVar6;
              if (lVar6 != 0) {
                *(long **)(lVar6 + 8) = plVar4;
              }
              *(undefined8 *)(puVar8 + 0x88) = 0;
            }
            *(undefined8 *)(puVar8 + 0x40) = 0;
            *(undefined8 *)(puVar8 + 0x48) = 0;
            kfree(puVar8);
            _raw_spin_unlock_bh(&DATARMNETd83ee17944);
          }
          DATARMNETb4a6870b3b(ppuVar9);
          if ((param_1 == '\0') && (*(char *)((long)ppuVar10 + 0xed) != '\0')) {
            DATARMNETa6e92c3315(ppuVar9);
          }
          else {
            DATARMNET2fe780019f(ppuVar9);
            *ppuVar10 = (undefined *)0x0;
            ppuVar10[1] = (undefined *)0x0;
            kfree(ppuVar9);
          }
          Hint_Prefetch(0x11caf8,2,0,1);
          do {
            cVar1 = '\x01';
            bVar2 = (bool)ExclusiveMonitorPass(0x11caf8,0x10);
            if (bVar2) {
              cVar1 = ExclusiveMonitorsStatus();
              DATARMNETecc0627c70._1632_8_ = DATARMNETecc0627c70._1632_8_ + -1;
            }
          } while (cVar1 != '\0');
        }
      }
      ppuVar10 = ppuVar7;
    } while (ppuVar7 != &DATARMNET9825511866);
  }
  _raw_spin_unlock_bh(&DATARMNET3764d083f0);
  __rcu_read_unlock();
  return;
}



//------------------------------------------------------------
// DATARMNETe69c918dc8 @ 0010fdc4 size=192
// signature: undefined DATARMNETe69c918dc8(void)
// callers: [DATARMNETcd6e26f0ad, DATARMNET039ac6d55d, DATARMNET7492293980]
//------------------------------------------------------------

void DATARMNETe69c918dc8(long param_1)

{
  ulong uVar1;
  uint *puVar2;
  uint uVar3;
  byte bVar4;
  
  if ((param_1 != 0) && (*(long *)(param_1 + 0x20) != 0)) {
    __rcu_read_lock();
    if (*(long *)(param_1 + 0x20) != 0) {
      puVar2 = *(uint **)(*(long *)(*(long *)(param_1 + 0x20) + 0x308) + 0x40);
      *(undefined2 *)(param_1 + 0x6c) = 0;
      if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
        uVar3 = 0;
        bVar4 = 0;
        do {
          uVar1 = (ulong)bVar4;
          bVar4 = bVar4 + 1;
          uVar3 = uVar3 | 1 << (ulong)(*(ushort *)((long)puVar2 + uVar1 * 2 + 0x18) & 0x1f);
          *(short *)(param_1 + 0x6c) = (short)uVar3;
        } while ((uint)bVar4 < *puVar2);
      }
      __rcu_read_unlock();
      *(ushort *)(param_1 + 0x68) = *(ushort *)(param_1 + 0x6c) & 0xf;
      *(ushort *)(param_1 + 0x6a) = *(ushort *)(param_1 + 0x6c) & 0xf0;
      return;
    }
    _printk(&DAT_0011540e,0);
  }
  DAT_0011da78 = DAT_0011da78 + 1;
  return;
}



//------------------------------------------------------------
// DATARMNETd6ee05f1b4 @ 0010fe88 size=148
// signature: undefined DATARMNETd6ee05f1b4(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

void DATARMNETd6ee05f1b4(undefined *param_1)

{
  undefined **ppuVar1;
  
  if (param_1 == (undefined *)0x0) {
    DATARMNET68d84e7b98 = DATARMNET68d84e7b98 + 1;
  }
  else {
    _raw_spin_lock_bh(&DATARMNETec2a4f5211);
    ppuVar1 = &DATARMNET30a3e83974;
    do {
      ppuVar1 = (undefined **)*ppuVar1;
      if (ppuVar1 == &DATARMNET30a3e83974) goto LAB_0010feec;
    } while (ppuVar1[2] != param_1);
    *(undefined1 *)((long)ppuVar1 + 0x5e) = 0;
    DATARMNETf7d317ed55(ppuVar1 + -2);
    *ppuVar1 = (undefined *)0x0;
    ppuVar1[1] = (undefined *)0x0;
    kfree(ppuVar1 + -2);
LAB_0010feec:
    _raw_spin_unlock_bh(&DATARMNETec2a4f5211);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET7492293980 @ 0010ff20 size=168
// signature: undefined DATARMNET7492293980(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET7492293980(long param_1)

{
  long lVar1;
  
  if (param_1 == 0) {
    DATARMNET68d84e7b98 = DATARMNET68d84e7b98 + 1;
  }
  else {
    _raw_spin_lock_bh(&DATARMNETec2a4f5211);
    lVar1 = kmalloc_trace(___rcu_read_unlock,0xb20,0x80);
    if (lVar1 == 0) {
      DAT_0011da68 = DAT_0011da68 + 1;
    }
    else {
      *(long *)(lVar1 + 0x20) = param_1;
      *(undefined1 *)(lVar1 + 0x6e) = 1;
      *(long *)(lVar1 + 0x10) = lVar1 + 0x10;
      *(long *)(lVar1 + 0x18) = lVar1 + 0x10;
      DATARMNETe69c918dc8();
      DATARMNET4095253347(lVar1);
    }
    _raw_spin_unlock_bh(&DATARMNETec2a4f5211);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET039ac6d55d @ 0010ffcc size=84
// signature: undefined DATARMNET039ac6d55d(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

void DATARMNET039ac6d55d(void)

{
  undefined **ppuVar1;
  
  for (ppuVar1 = (undefined **)DATARMNET30a3e83974; ppuVar1 != &DATARMNET30a3e83974;
      ppuVar1 = (undefined **)*ppuVar1) {
    if (*(char *)((long)ppuVar1 + 0x5e) != '\0') {
      DATARMNETe69c918dc8(ppuVar1 + -2);
      ppuVar1[-2] = (undefined *)0x0;
      ppuVar1[-1] = (undefined *)0x0;
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNETedc898218c @ 00110024 size=244
// signature: undefined DATARMNETedc898218c(void)
// callers: [DATARMNETcd6e26f0ad]
//------------------------------------------------------------

void DATARMNETedc898218c(void)

{
  undefined **ppuVar1;
  long lVar2;
  ulong uVar3;
  
  DAT_0011cd00 = 0;
  DAT_0011cd08 = 0;
  DATARMNET2d482e7d9f = 0;
  DAT_0011ccf8 = 0;
  DAT_0011cb48 = 0;
  DAT_0011cb70 = 0;
  DAT_0011cb98 = 0;
  DAT_0011cbc0 = 0;
  DAT_0011cbe8 = 0;
  DAT_0011cc10 = 0;
  DAT_0011cc38 = 0;
  DAT_0011cc60 = 0;
  __rcu_read_lock();
  ppuVar1 = (undefined **)DATARMNET9825511866;
  if ((undefined **)DATARMNET9825511866 != &DATARMNET9825511866) {
    do {
      if (*(char *)((long)ppuVar1 + 0xec) != '\0') {
        if ((((undefined *)0x64 < ppuVar1[0xc]) && ((undefined *)0xc8 < ppuVar1[6])) &&
           ((ulong)*(ushort *)((long)ppuVar1 + 0xe6) < 8)) {
          lVar2 = (ulong)*(ushort *)((long)ppuVar1 + 0xe6) * 4;
          *(int *)((long)&DATARMNET2d482e7d9f + lVar2) =
               *(int *)((long)&DATARMNET2d482e7d9f + lVar2) + 1;
        }
        uVar3 = (ulong)*(ushort *)((long)ppuVar1 + 0xe6);
        if ((uVar3 < 8) && (*(char *)((long)ppuVar1 + 0xef) != '\0')) {
          (&DAT_0011cb48)[uVar3 * 10] = (&DAT_0011cb48)[uVar3 * 10] + 1;
        }
      }
      ppuVar1 = (undefined **)*ppuVar1;
    } while (ppuVar1 != &DATARMNET9825511866);
  }
  __rcu_read_unlock();
  return;
}



//------------------------------------------------------------
// DATARMNETcd6e26f0ad @ 0011011c size=2336
// signature: undefined DATARMNETcd6e26f0ad(void)
// callers: [DATARMNETb4b5fc9686]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETcd6e26f0ad(void)

{
  uint uVar1;
  long lVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  char cVar7;
  ulong uVar8;
  int iVar9;
  int iVar10;
  undefined1 uVar11;
  ulong uVar12;
  ulong uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  ulong uVar16;
  long *plVar17;
  long lVar18;
  undefined **ppuVar19;
  undefined **ppuVar20;
  undefined1 *puVar21;
  long lVar22;
  long lVar23;
  undefined1 auVar24 [16];
  ulong local_e0;
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
  long local_68;
  
  lVar23 = sp_el0;
  local_68 = *(long *)(lVar23 + 0x638);
  ktime_get_with_offset(1);
  auVar24 = ns_to_timespec64();
  DATARMNETb3a4036d6d = auVar24._8_8_ + auVar24._0_8_ * 1000000000;
  for (ppuVar20 = (undefined **)DATARMNET30a3e83974; ppuVar20 != &DATARMNET30a3e83974;
      ppuVar20 = (undefined **)*ppuVar20) {
    if (*(char *)((long)ppuVar20 + 0x5e) != '\0') {
      DATARMNETe69c918dc8(ppuVar20 + -2);
      ppuVar20[-2] = (undefined *)0x0;
      ppuVar20[-1] = (undefined *)0x0;
    }
  }
  DATARMNETe46c480d71();
  local_e0 = walt_get_cpus_taken();
  if (DATARMNET68dc14b50d != 0) {
    DATARMNET121c8bc82a = (uint)local_e0 & 3;
    if (1 < ((uint)(local_e0 >> 1) & 1) + ((uint)local_e0 & 1)) {
      DAT_0011db28 = DAT_0011db28 + 1;
    }
    if (((DATARMNET121c8bc82a >> (ulong)(DATARMNETecc0627c70[0x676] & 0x1f) & 1) != 0) &&
       (iVar9 = DATARMNET362c14e98b((uint)(DATARMNETecc0627c70[0x689] & DATARMNETecc0627c70[0x670])
                                    & ((DATARMNETecc0627c70[0x66f] | DATARMNET121c8bc82a) ^
                                      0xffffffff)), 0 < iVar9)) {
      DATARMNETecc0627c70[0x672] = (undefined1)iVar9;
      __rcu_read_lock();
      _rmnet_shs_switch = DATARMNET756778f14f;
      __rcu_read_unlock();
    }
  }
  local_e0 = 0;
  iVar9 = walt_get_cpus_in_state1(&local_e0);
  if (-1 < iVar9) {
    if (((uint)local_e0 & 0x60) == 0x60) {
      if (((DATARMNETecc0627c70[0x689] ^ 0xff) & 0x60) != 0) goto LAB_00110380;
      DATARMNETecc0627c70[0x68a] = DATARMNETecc0627c70[0x68a] | 0x60;
      DATARMNETecc0627c70[0x689] = ~DATARMNETecc0627c70[0x68a];
      DATARMNETecc0627c70[0x688] = __sw_hweight64();
      DAT_00119258 = 0;
      DAT_00119260 = 0;
      DAT_00119218 = 100000;
      DAT_00119220 = 100000;
      plVar17 = &DAT_0011d930;
    }
    else {
      if (((DATARMNETecc0627c70[0x68a] ^ 0xff) & 0x60) != 0) goto LAB_00110380;
      DATARMNETecc0627c70[0x689] = DATARMNETecc0627c70[0x689] | 0x60;
      DATARMNETecc0627c70[0x68a] = ~DATARMNETecc0627c70[0x689];
      DATARMNETecc0627c70[0x688] = __sw_hweight64(DATARMNETecc0627c70[0x68a]);
      DAT_00119258 = 40000;
      DAT_00119260 = 40000;
      DAT_00119218 = 210000;
      DAT_00119220 = 210000;
      plVar17 = &DAT_0011d938;
    }
    *plVar17 = *plVar17 + 1;
  }
LAB_00110380:
  if (((DATARMNETd619186789 ^ 0xffffffff) & 0x7f) == 0) {
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
    local_e0 = 0;
    DATARMNET1d4b1eff85(&local_e0,DATARMNETecc0627c70[0x676],DATARMNETecc0627c70[0x676]);
    DATARMNETb5d58adbe7(&local_e0);
  }
  __rcu_read_lock();
  ppuVar20 = (undefined **)DATARMNET9825511866;
  if ((undefined **)DATARMNET9825511866 != &DATARMNET9825511866) {
    do {
      if ((*(char *)((long)ppuVar20 + 0xec) != '\0') && (ppuVar20[2] != (undefined *)0x0)) {
        ppuVar19 = ppuVar20 + -10;
        DATARMNET9a7769cf21(ppuVar19);
        DATARMNET5b2ed86112(ppuVar19);
        if (DATARMNETc252c204a8 == 0) {
          *(undefined1 *)(*(long *)(ppuVar20[2] + 0x58) + 0x13f) = 0;
        }
        else {
          if (ppuVar20[2][0xdb] == '\0') {
            DATARMNET6f4b0915d3(ppuVar19,&DATARMNET3208cd0982);
          }
          else {
            DATARMNET312b06829d(ppuVar19,&DATARMNET922b4752e2);
          }
          iVar9 = DATARMNET362b15f941(*(undefined2 *)((long)ppuVar20 + 0xe6));
          if (iVar9 == 0) {
            DATARMNET24e4475345(ppuVar19,&DATARMNET6c23f11e81);
          }
          if (*(short *)(ppuVar20 + 0x1d) == 6) {
            DATARMNET28a80d526e(ppuVar19,&DATARMNETf91b305f4e);
          }
        }
      }
      ppuVar20 = (undefined **)*ppuVar20;
    } while (ppuVar20 != &DATARMNET9825511866);
  }
  __rcu_read_unlock();
  lVar23 = 0;
  uVar16 = 0;
  puVar21 = &DAT_0011cb4e;
  uVar15 = sp_el0;
  do {
    lVar2 = (long)&DATARMNET6cdd58e74c + lVar23;
    lVar18 = *(long *)((long)&DAT_0011db68 + lVar23);
    lVar22 = *(long *)((long)&DAT_0011db50 + lVar23);
    iVar10 = DATARMNETadb0248bd4(uVar16 & 0xffffffff);
    iVar9 = *(int *)((long)&DAT_0011dbbc + lVar23);
    if (*(int *)((long)&DAT_0011dbbc + lVar23) == 0) {
      *(int *)((long)&DAT_0011dbbc + lVar23) = iVar10;
      iVar9 = iVar10;
    }
    iVar5 = *(int *)((long)&DAT_0011dbb0 + lVar23);
    bVar6 = puVar21[-1];
    *(int *)((long)&DAT_0011dbb0 + lVar23) = iVar10;
    *(int *)((long)&DAT_0011dbb4 + lVar23) = iVar5;
    *(int *)((long)&DAT_0011dbc0 + lVar23) = iVar10 - iVar9;
    *(int *)((long)&DAT_0011dbb8 + lVar23) = iVar10 - iVar5;
    if (bVar6 != 0) {
      uVar1 = bVar6 + 1;
      uVar4 = 2;
      if (DATARMNET25c61a512c != 0) {
        uVar4 = DATARMNET25c61a512c;
      }
      cVar7 = '\0';
      if (uVar4 != 0) {
        cVar7 = (char)(uVar1 / uVar4);
      }
      puVar21[-1] = (char)uVar1 - cVar7 * (char)uVar4;
    }
    if (lVar18 == lVar22) {
      *(long *)((long)&DAT_0011db48 + lVar23) = DATARMNETb3a4036d6d;
      iVar9 = DATARMNETc252c204a8;
      *(undefined8 *)((long)&DAT_0011dba0 + lVar23) = 0;
      *(undefined8 *)((long)&DAT_0011db88 + lVar23) = 0;
      *(undefined8 *)((long)&DAT_0011db80 + lVar23) = 0;
      if (iVar9 != 0) {
        DATARMNETc6439e3d71(&DATARMNET6cdd58e74c,lVar2,&DATARMNETe46ae760db);
      }
      if (DATARMNET58b009b16b != 0) {
        if (lVar2 == 0) {
          *puVar21 = 0;
          goto LAB_00110810;
        }
        uVar15 = *(undefined8 *)((long)&DAT_0011db80 + lVar23);
        (&DATARMNET79263b1183)[uVar16] = *(undefined8 *)((long)&DAT_0011db88 + lVar23);
        uVar3 = *(undefined4 *)((long)&DAT_0011dbc4 + lVar23);
        (&DATARMNET229d52b629)[uVar16] = uVar15;
        uVar15 = *(undefined8 *)((long)&DAT_0011db70 + lVar23);
        (&DATARMNET18f2ba4444)[uVar16] = uVar3;
        uVar14 = *(undefined8 *)((long)&DAT_0011db68 + lVar23);
        (&DATARMNET77240d48ee)[uVar16] = uVar15;
        uVar1 = *(uint *)((long)&DAT_0011dbb8 + lVar23);
        (&DATARMNET77189ab85c)[uVar16] = uVar14;
        uVar4 = *(uint *)((long)&DAT_0011dbc0 + lVar23);
        (&DATARMNETd27ed7efea)[uVar16] = (ulong)uVar1;
        (&DATARMNET377ecf13ca)[uVar16] = (ulong)uVar4;
      }
      *puVar21 = 0;
    }
    else {
      uVar12 = DATARMNETb3a4036d6d - *(long *)((long)&DAT_0011db48 + lVar23);
      uVar15 = *(undefined8 *)((long)&DAT_0011db80 + lVar23);
      uVar14 = *(undefined8 *)((long)&DAT_0011db88 + lVar23);
      if (DATARMNET1fc3ad67fd == 0 ||
          (long)uVar12 <= (long)(ulong)(uint)(DATARMNET1fc3ad67fd * 1000000)) {
        uVar12 = 100000000;
      }
      uVar13 = 0;
      if (uVar12 != 0) {
        uVar13 = (ulong)((lVar18 - lVar22) * 1000000000) / uVar12;
      }
      uVar8 = 0;
      if (uVar12 != 0) {
        uVar8 = (ulong)((*(long *)((long)&DAT_0011db70 + lVar23) -
                        *(long *)((long)&DAT_0011db58 + lVar23)) * 1000000000) / uVar12;
      }
      *(ulong *)((long)&DAT_0011db80 + lVar23) = uVar13;
      *(ulong *)((long)&DAT_0011db88 + lVar23) = uVar8 << 3;
      iVar9 = DATARMNET362b15f941(uVar16 & 0xffffffff);
      if (*(long *)((long)&DAT_0011db90 + lVar23) == 0) {
        uVar12 = *(ulong *)((long)&DAT_0011dba0 + lVar23);
      }
      else {
        uVar1 = DATARMNETcab56af6d5;
        if (iVar9 != 0) {
          uVar1 = 100 - DATARMNETcab56af6d5;
        }
        uVar4 = 100 - DATARMNETcab56af6d5;
        if (iVar9 != 0) {
          uVar4 = DATARMNETcab56af6d5;
        }
        uVar13 = (ulong)((uVar1 & 0xffff) + (uVar4 & 0xffff));
        uVar12 = 0;
        if (uVar13 != 0) {
          uVar12 = (((ulong)(*(long *)((long)&DAT_0011dba0 + lVar23) +
                            *(long *)((long)&DAT_0011db90 + lVar23)) >> 1) * (ulong)(uVar1 & 0xffff)
                   + *(long *)((long)&DAT_0011db80 + lVar23) * ((ulong)uVar4 & 0xffff)) / uVar13;
        }
      }
      *(undefined8 *)((long)&DAT_0011db90 + lVar23) = uVar15;
      lVar18 = DATARMNETb3a4036d6d;
      *(undefined8 *)((long)&DAT_0011db98 + lVar23) = uVar14;
      *(ulong *)((long)&DAT_0011dba0 + lVar23) = uVar12;
      *(undefined8 *)((long)&DAT_0011db50 + lVar23) = *(undefined8 *)((long)&DAT_0011db68 + lVar23);
      *(long *)((long)&DAT_0011db48 + lVar23) = lVar18;
      *(undefined8 *)((long)&DAT_0011db58 + lVar23) = *(undefined8 *)((long)&DAT_0011db70 + lVar23);
      *(undefined8 *)((long)&DAT_0011dba8 + lVar23) = *(undefined8 *)((long)&DAT_0011db88 + lVar23);
      iVar10 = DATARMNET362b15f941(uVar16 & 0xffffffff);
      iVar9 = DATARMNETc252c204a8;
      if ((iVar10 == 0) || (0x4a36 < *(long *)((long)&DAT_0011db80 + lVar23) - 0x3a99U)) {
        uVar11 = 0;
      }
      else {
        uVar11 = 1;
      }
      *puVar21 = uVar11;
      if (iVar9 != 0) {
        DATARMNETc6439e3d71(&DATARMNET6cdd58e74c,lVar2,&DATARMNETe46ae760db);
      }
      if (DATARMNET58b009b16b != 0) {
        if (lVar2 == 0) {
LAB_00110810:
          DAT_0011daa8 = DAT_0011daa8 + 1;
        }
        else {
          (&DATARMNET18f2ba4444)[uVar16] = *(undefined4 *)((long)&DAT_0011dbc4 + lVar23);
          uVar14 = *(undefined8 *)((long)&DAT_0011db70 + lVar23);
          uVar15 = *(undefined8 *)((long)&DAT_0011db80 + lVar23);
          (&DATARMNET79263b1183)[uVar16] = *(undefined8 *)((long)&DAT_0011db88 + lVar23);
          (&DATARMNET229d52b629)[uVar16] = uVar15;
          uVar15 = *(undefined8 *)((long)&DAT_0011db68 + lVar23);
          (&DATARMNET77240d48ee)[uVar16] = uVar14;
          uVar1 = *(uint *)((long)&DAT_0011dbb8 + lVar23);
          (&DATARMNET77189ab85c)[uVar16] = uVar15;
          uVar4 = *(uint *)((long)&DAT_0011dbc0 + lVar23);
          (&DATARMNETd27ed7efea)[uVar16] = (ulong)uVar1;
          (&DATARMNET377ecf13ca)[uVar16] = (ulong)uVar4;
        }
      }
    }
    uVar16 = uVar16 + 1;
    lVar23 = lVar23 + 0x98;
    puVar21 = puVar21 + 0x28;
    if (lVar23 == 0x4c0) {
      uVar16 = DATARMNETb3a4036d6d - DAT_0011dff8;
      DAT_0011dff8 = DATARMNETb3a4036d6d;
      if (DATARMNET1fc3ad67fd == 0 ||
          (long)uVar16 <= (long)(ulong)(uint)(DATARMNET1fc3ad67fd * 1000000)) {
        uVar16 = 100000000;
      }
      uVar12 = 0;
      if (uVar16 != 0) {
        uVar12 = (ulong)((DAT_0011e060 - DAT_0011e038) * 1000000000) / uVar16;
      }
      lVar23 = DAT_0011e058 - DAT_0011e030;
      DAT_0011e030 = DAT_0011e058;
      DAT_0011e038 = DAT_0011e060;
      uVar13 = 0;
      if (uVar16 != 0) {
        uVar13 = (ulong)(lVar23 * 1000000000) / uVar16;
      }
      DAT_0011e048 = DAT_0011e070;
      DAT_0011e050 = DAT_0011e078;
      DAT_0011e000 = DAT_0011e010;
      DAT_0011e008 = DAT_0011e018;
      if (DATARMNETecc0627c70._392_8_ == 0) {
        DAT_0011da70 = DAT_0011da70 + 1;
      }
      else {
        DAT_0011e020 = (ulong)((*(long *)(DATARMNETecc0627c70._392_8_ + 0xa38) - DAT_0011e018) *
                              1000000000) / 100000000;
        DAT_0011e028 = (ulong)((*(long *)(DATARMNETecc0627c70._392_8_ + 0xa30) - DAT_0011e010) *
                              1000000000) / 100000000 << 3;
        DAT_0011e010 = *(long *)(DATARMNETecc0627c70._392_8_ + 0xa30);
        DAT_0011e018 = *(long *)(DATARMNETecc0627c70._392_8_ + 0xa38);
      }
      DAT_0011e070 = uVar13;
      DAT_0011e078 = uVar12 << 3;
      if (DATARMNETc252c204a8 == 0) {
        DATARMNET95736008d9();
      }
      else {
        DATARMNET7792d4f4ad(&DATARMNETe46ae760db,&DATARMNET6c23f11e81,&DATARMNETf91b305f4e,
                            &DATARMNET3208cd0982,&DATARMNET922b4752e2);
        DATARMNETa1b141715b(&DATARMNET6c23f11e81);
        DATARMNET3af54cd726(&DATARMNETf91b305f4e);
        DATARMNETb177316a15(&DATARMNETe46ae760db);
        DATARMNETcc489fbbad(&DATARMNET3208cd0982);
        DATARMNETf7730d41c1(&DATARMNET922b4752e2);
      }
      for (ppuVar20 = (undefined **)DATARMNET30a3e83974; ppuVar20 != &DATARMNET30a3e83974;
          ppuVar20 = (undefined **)*ppuVar20) {
        if (*(char *)((long)ppuVar20 + 0x5e) != '\0') {
          DATARMNETe00453a3e4(ppuVar20 + -2);
        }
      }
      DATARMNETedc898218c();
      lVar23 = sp_el0;
      if (*(long *)(lVar23 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// DATARMNETb4b5fc9686 @ 00110dec size=140
// signature: undefined DATARMNETb4b5fc9686(void)
// callers: []
//------------------------------------------------------------

void DATARMNETb4b5fc9686(void)

{
  undefined8 uVar1;
  
  DATARMNETd619186789 = DATARMNETd619186789 + 1;
  _raw_spin_lock_bh(&DATARMNETec2a4f5211);
  DATARMNETcd6e26f0ad();
  _raw_spin_unlock_bh(&DATARMNETec2a4f5211);
  DATARMNET39391a8bc5(0);
  uVar1 = __msecs_to_jiffies(DATARMNET1fc3ad67fd);
  queue_delayed_work_on(0x20,DATARMNETf141197982,DATARMNET9dc7755be5,uVar1);
  return;
}



//------------------------------------------------------------
// DATARMNET5fb4151598 @ 00110f84 size=152
// signature: undefined DATARMNET5fb4151598(void)
// callers: [DATARMNETf7dcab9a9e]
//------------------------------------------------------------

void DATARMNET5fb4151598(void)

{
  undefined8 uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  
  if ((undefined **)DATARMNET30a3e83974 != &DATARMNET30a3e83974) {
    uVar1 = sp_el0;
    ppuVar2 = (undefined **)DATARMNET30a3e83974;
    do {
      ppuVar3 = (undefined **)*ppuVar2;
      DATARMNETf7d317ed55(ppuVar2 + -2);
      *ppuVar2 = (undefined *)0x0;
      ppuVar2[1] = (undefined *)0x0;
      kfree(ppuVar2 + -2);
      ppuVar2 = ppuVar3;
    } while (ppuVar3 != &DATARMNET30a3e83974);
  }
  return;
}



//------------------------------------------------------------
// DATARMNETf7dcab9a9e @ 00111090 size=148
// signature: undefined DATARMNETf7dcab9a9e(void)
// callers: [DATARMNET3ae0d614d6, DATARMNETe9173bbe0e]
//------------------------------------------------------------

void DATARMNETf7dcab9a9e(void)

{
  if (DATARMNETf141197982 != 0 && DATARMNET9dc7755be5 != 0) {
    DATARMNET28d33bd09f();
    DATARMNET5945236cd3(0x2a);
    cancel_delayed_work_sync(DATARMNET9dc7755be5);
    drain_workqueue(DATARMNETf141197982);
    destroy_workqueue(DATARMNETf141197982);
    kfree(DATARMNET9dc7755be5);
    DATARMNET9dc7755be5 = 0;
    DATARMNETf141197982 = 0;
    DATARMNET39391a8bc5(1);
    DATARMNET5fb4151598();
  }
  return;
}



//------------------------------------------------------------
// DATARMNETd3d1d13f44 @ 00111230 size=100
// signature: undefined DATARMNETd3d1d13f44(void)
// callers: [DATARMNET3ae0d614d6]
//------------------------------------------------------------

void DATARMNETd3d1d13f44(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  long lVar3;
  
  lVar3 = 0;
  puVar2 = &DATARMNET6cdd58e74c;
  uVar1 = sp_el0;
  do {
    *puVar2 = puVar2;
    puVar2[1] = puVar2;
    *(short *)(puVar2 + 0x12) = (short)lVar3;
    lVar3 = lVar3 + 1;
    puVar2 = puVar2 + 0x13;
  } while (lVar3 != 8);
  return;
}



//------------------------------------------------------------
// DATARMNET4063c95208 @ 00111340 size=164
// signature: undefined DATARMNET4063c95208(void)
// callers: [DATARMNET7f1d9480cb]
//------------------------------------------------------------

void DATARMNET4063c95208(void)

{
  DATARMNETaf95716235 = DATARMNETaf95716235 + 1;
  if (DATARMNETf141197982 != 0 && DATARMNET9dc7755be5 != 0) {
    cancel_delayed_work_sync();
  }
  DAT_0011cd00 = 0;
  DAT_0011cd08 = 0;
  DATARMNET2d482e7d9f = 0;
  DAT_0011ccf8 = 0;
  __rcu_read_lock();
  if (((DATARMNETecc0627c70[0x689] >> (ulong)(DATARMNETecc0627c70[0x676] & 0x1f) & 1) != 0) &&
     (((byte)DATARMNET121c8bc82a >> 1 & 1) == 0)) {
    DATARMNETecc0627c70[0x672] = 1;
    DATARMNET8f9da46b14();
    DAT_0011d8e8 = DAT_0011d8e8 + 1;
  }
  __rcu_read_unlock();
  return;
}



//------------------------------------------------------------
// DATARMNET7b6c061b06 @ 001113e8 size=80
// signature: undefined DATARMNET7b6c061b06(void)
// callers: [DATARMNETa4bd2ef52c]
//------------------------------------------------------------

void DATARMNET7b6c061b06(void)

{
  DATARMNET7e039054c6 = DATARMNET7e039054c6 + 1;
  if (DATARMNETf141197982 != 0 && DATARMNET9dc7755be5 != 0) {
    queue_delayed_work_on(0x20,DATARMNETf141197982,DATARMNET9dc7755be5,0);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET3ae0d614d6 @ 0011143c size=368
// signature: undefined DATARMNET3ae0d614d6(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET3ae0d614d6(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  long lVar4;
  char cVar5;
  
  if (DATARMNETf141197982 == 0) {
    DATARMNETf5f83b943f();
    DATARMNETf141197982 = alloc_workqueue("rmnet_shs_wq",2,1);
    if (DATARMNETf141197982 == 0) {
      DAT_0011da50 = DAT_0011da50 + 1;
    }
    else {
      DATARMNET9dc7755be5 = (undefined8 *)kmalloc_trace(_alt_cb_patch_nops,0xa20,0x88);
      if (DATARMNET9dc7755be5 == (undefined8 *)0x0) {
        DAT_0011da58 = DAT_0011da58 + 1;
        DATARMNETf7dcab9a9e();
      }
      else {
        cVar5 = '\x10';
        do {
          lVar4 = kmalloc_trace(_ktime_get_with_offset,0xb20,0x140);
          if (lVar4 == 0) {
            DAT_0011da60 = DAT_0011da60 + 1;
          }
          else {
            *(undefined1 *)(lVar4 + 0x13d) = 1;
            DATARMNETa6e92c3315();
            *(long *)(lVar4 + 0x50) = lVar4 + 0x50;
            *(long *)(lVar4 + 0x58) = lVar4 + 0x50;
            *(long *)(lVar4 + 0x40) = lVar4 + 0x40;
            *(long *)(lVar4 + 0x48) = lVar4 + 0x40;
            DATARMNET36e5e526fa(lVar4);
          }
          cVar5 = cVar5 + -1;
        } while (cVar5 != '\0');
        DATARMNETd3d1d13f44();
        puVar3 = DATARMNET9dc7755be5;
        puVar1 = DATARMNET9dc7755be5 + 1;
        puVar2 = DATARMNET9dc7755be5 + 6;
        *DATARMNET9dc7755be5 = 0xfffffffe0;
        puVar3[1] = puVar1;
        puVar3[2] = puVar1;
        puVar3[3] = DATARMNETb4b5fc9686;
        init_timer_key(puVar2,&delayed_work_timer_fn,0x200000,0,0);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNETb709a938b5 @ 001116b8 size=124
// signature: undefined DATARMNETb709a938b5(void)
// callers: [DATARMNETdd3b17f0c3, DATARMNET392890a12b]
//------------------------------------------------------------

undefined4 DATARMNETb709a938b5(ushort param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (param_1 < 8) {
    if (0x534 < (uint)param_1 * 0x98) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(1,0x111734);
      (*pcVar1)();
    }
    uVar2 = (&DAT_0011dbc4)[(ulong)(uint)param_1 * 0x26];
  }
  else {
    uVar2 = 0xffffffff;
    DAT_0011da20 = DAT_0011da20 + 1;
  }
  return uVar2;
}



//------------------------------------------------------------
// DATARMNET392890a12b @ 001117c4 size=128
// signature: undefined DATARMNET392890a12b(void)
// callers: []
//------------------------------------------------------------

int DATARMNET392890a12b(void)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  uVar1 = sp_el0;
  iVar4 = -1;
  do {
    iVar2 = DATARMNETb709a938b5(iVar3);
    if (iVar2 <= iVar4) {
      iVar2 = iVar4;
    }
    iVar3 = iVar3 + 1;
    iVar4 = iVar2;
  } while (iVar3 != 8);
  return iVar2;
}



//------------------------------------------------------------
// DATARMNETdd3b17f0c3 @ 001118c4 size=164
// signature: undefined DATARMNETdd3b17f0c3(void)
// callers: []
//------------------------------------------------------------

int DATARMNETdd3b17f0c3(ushort param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 < 9) {
    iVar4 = (uint)(3 < param_1) << 2;
    iVar2 = 8;
    if ((param_1 & 0xfffc) == 0) {
      iVar2 = 4;
    }
    iVar3 = -1;
    do {
      iVar1 = DATARMNETb709a938b5(iVar4);
      iVar4 = iVar4 + 1;
      if (iVar1 <= iVar3) {
        iVar1 = iVar3;
      }
      iVar3 = iVar1;
    } while (iVar2 != iVar4);
  }
  else {
    iVar1 = -1;
    DAT_0011da20 = DAT_0011da20 + 1;
  }
  return iVar1;
}



//------------------------------------------------------------
// DATARMNET5d4ca1da1c @ 00111a88 size=260
// signature: undefined DATARMNET5d4ca1da1c(void)
// callers: [DATARMNETd81d2866ba, DATARMNET283f08f439, DATARMNET29175fb5fc, DATARMNET9bbfc822c2]
//------------------------------------------------------------

void DATARMNET5d4ca1da1c(int *param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  undefined4 local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = __alloc_skb(0xe94,0xa20,0,0xffffffff);
  if (lVar2 != 0) {
    lVar3 = genlmsg_put(lVar2,0,*param_1 + 1,&DATARMNETecc643c219,0,1);
    if (lVar3 != 0) {
      local_3c = param_2;
      iVar1 = nla_put(lVar2,2,4,&local_3c);
      if (iVar1 == 0) {
        *(int *)(lVar3 + -0x14) =
             (*(int *)(lVar2 + 0xd8) + *(int *)(lVar2 + 0xd0)) - ((int)lVar3 + -0x14);
        iVar1 = netlink_unicast(*(undefined8 *)(*(long *)(param_1 + 10) + 0x118),lVar2,param_1[1],
                                0x40);
        if (-1 < iVar1) {
          uVar4 = 0;
          goto LAB_00111b20;
        }
        goto LAB_00111b1c;
      }
    }
    kfree(lVar2);
  }
LAB_00111b1c:
  uVar4 = 0xffffffff;
LAB_00111b20:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET5945236cd3 @ 00111b90 size=296
// signature: undefined DATARMNET5945236cd3(void)
// callers: [DATARMNETf7dcab9a9e, DATARMNET7792d4f4ad, DATARMNETeabd69d1ab]
//------------------------------------------------------------

void DATARMNET5945236cd3(undefined4 param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  undefined4 local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  if (DATARMNETb01cbc5ec9 == 0) {
    uVar4 = 0xffffffff;
    goto LAB_00111c48;
  }
  lVar2 = __alloc_skb(0xe94,0xa20,0,0xffffffff);
  iVar1 = DATARMNET7c4038843f;
  if (lVar2 != 0) {
    DATARMNET7c4038843f = DATARMNET7c4038843f + 1;
    lVar3 = genlmsg_put(lVar2,0,iVar1,&DATARMNETecc643c219,0,1);
    if (lVar3 != 0) {
      local_3c = param_1;
      iVar1 = nla_put(lVar2,2,4,&local_3c);
      if (iVar1 == 0) {
        *(int *)(lVar3 + -0x14) =
             (*(int *)(lVar2 + 0xd8) + *(int *)(lVar2 + 0xd0)) - ((int)lVar3 + -0x14);
        iVar1 = netlink_unicast(*(undefined8 *)(DATARMNETb01cbc5ec9 + 0x118),lVar2,
                                DATARMNET373156e169,0x40);
        if (-1 < iVar1) {
          uVar4 = 0;
          goto LAB_00111c48;
        }
        goto LAB_00111c34;
      }
    }
    kfree(lVar2);
  }
LAB_00111c34:
  uVar4 = 0xffffffff;
  DATARMNETc252c204a8 = 0;
LAB_00111c48:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// DATARMNETa9a7fa898c @ 00111cbc size=308
// signature: undefined DATARMNETa9a7fa898c(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETa9a7fa898c(void)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  int local_3c;
  long local_38;
  
  iVar4 = DATARMNET7c4038843f;
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  DATARMNET7c4038843f = DATARMNET7c4038843f + 1;
  lVar5 = __alloc_skb(0xe94,0xa20,0,0xffffffff);
  iVar2 = DATARMNET7c4038843f;
  if (lVar5 != 0) {
    DATARMNET7c4038843f = DATARMNET7c4038843f + 1;
    lVar6 = genlmsg_put(lVar5,0,iVar2,&DATARMNETecc643c219,0,1);
    if (lVar6 != 0) {
      local_3c = iVar4;
      iVar4 = nla_put(lVar5,2,4,&local_3c);
      if (iVar4 == 0) {
        *(int *)(lVar6 + -0x14) =
             (*(int *)(lVar5 + 0xd8) + *(int *)(lVar5 + 0xd0)) - ((int)lVar6 + -0x14);
        uVar7 = _DAT_001264f8;
        uVar1 = DAT_00118fa8;
        if (DAT_00118faf == '\0') {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x800,0x111dec);
          (*pcVar3)();
        }
        *(undefined4 *)(lVar5 + 0x38) = DAT_00118fa8;
        netlink_broadcast(uVar7,lVar5,0,uVar1,0xa20);
        uVar7 = 0;
        goto LAB_00111d68;
      }
    }
    kfree(lVar5);
  }
  uVar7 = 0xffffffff;
  DATARMNETc252c204a8 = 0;
LAB_00111d68:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET740f3b34b3 @ 00111df8 size=48
// signature: undefined DATARMNET740f3b34b3(void)
// callers: []
//------------------------------------------------------------

int DATARMNET740f3b34b3(undefined8 param_1,long param_2)

{
  DATARMNET90fe3a4b56();
  return -(uint)(param_2 == 0);
}



//------------------------------------------------------------
// DATARMNET283f08f439 @ 00111e2c size=180
// signature: undefined DATARMNET283f08f439(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNET283f08f439(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  if (param_2 == 0) {
    return 0xffffffff;
  }
  lVar4 = *(long *)(*(long *)(param_2 + 0x20) + 0x28);
  if (((lVar4 == 0) || (lVar2 = kmalloc_trace(___rcu_read_unlock,0xb20,0x50), lVar2 == 0)) ||
     (iVar1 = nla_memcpy(lVar2 + 0x20,lVar4,0x30), iVar1 < 1)) {
    uVar3 = 0x398;
  }
  else {
    if (*(char *)(lVar2 + 0x4f) == '\0') {
      DATARMNETd52d50282d(lVar2);
    }
    else if (*(char *)(lVar2 + 0x4f) == '\x01') {
      DATARMNET2ac305d296(lVar2);
    }
    uVar3 = 0x3a1;
  }
  DATARMNET5d4ca1da1c(param_2,uVar3);
  return 0;
}



//------------------------------------------------------------
// DATARMNETd81d2866ba @ 00111ee4 size=208
// signature: undefined DATARMNETd81d2866ba(void)
// callers: []
//------------------------------------------------------------

void DATARMNETd81d2866ba(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_30 = 0;
  if (param_2 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    lVar3 = *(long *)(*(long *)(param_2 + 0x20) + 0x20);
    if ((lVar3 == 0) || (iVar1 = nla_memcpy(&local_30,lVar3,8), iVar1 < 1)) {
      DATARMNET5d4ca1da1c(param_2,0x398);
    }
    else {
      iVar1 = DATARMNETf85599b9d8(local_30 & 0xffffffff,local_30._4_4_);
      if (iVar1 == 1) {
        DATARMNET5d4ca1da1c(param_2,0x3a1);
      }
      else {
        DATARMNET5d4ca1da1c(param_2,0x398);
      }
    }
    uVar2 = 0;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// trace_rmnet_shs_wq_high @ 00112090 size=44
// signature: undefined trace_rmnet_shs_wq_high(void)
// callers: [DATARMNET29175fb5fc]
//------------------------------------------------------------

void trace_rmnet_shs_wq_high(void)

{
  return;
}



//------------------------------------------------------------
// DATARMNET9bbfc822c2 @ 00112144 size=172
// signature: undefined DATARMNET9bbfc822c2(void)
// callers: []
//------------------------------------------------------------

void DATARMNET9bbfc822c2(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined4 uVar4;
  undefined8 local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_30 = 0;
  if (param_2 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    lVar3 = *(long *)(*(long *)(param_2 + 0x20) + 0x30);
    if (lVar3 == 0) {
      uVar4 = 0x3a2;
    }
    else {
      iVar1 = nla_memcpy(&local_30,lVar3,8);
      uVar4 = 0x3a2;
      if (0 < iVar1) {
        iVar1 = DATARMNET1faf2b953f(local_30 & 0xffffffff,local_30._4_4_);
        uVar4 = 0x3a2;
        if (iVar1 == 1) {
          uVar4 = 0x3a3;
        }
      }
    }
    DATARMNET5d4ca1da1c(param_2,uVar4);
    uVar2 = 0;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET29175fb5fc @ 001121f4 size=640
// signature: undefined DATARMNET29175fb5fc(void)
// callers: []
//------------------------------------------------------------

void DATARMNET29175fb5fc(undefined8 param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  uint uVar5;
  undefined8 local_38;
  undefined4 local_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_30 = 0;
  local_38 = 0;
  if (param_2 == 0) {
LAB_00112300:
    uVar3 = 0xffffffff;
    goto LAB_00112304;
  }
  lVar4 = *(long *)(*(long *)(param_2 + 0x20) + 0x18);
  if ((lVar4 == 0) || (iVar2 = nla_memcpy(&local_38,lVar4,0xc), iVar2 < 1)) {
    uVar3 = 0x2d0;
  }
  else {
    if ((7 < local_30._2_2_) || (7 < (local_30 & 0xffff))) {
      DAT_0011da10 = DAT_0011da10 + 1;
LAB_001122f4:
      uVar3 = 0x12d;
LAB_001122fc:
      DATARMNET5d4ca1da1c(param_2,uVar3);
      goto LAB_00112300;
    }
    uVar5 = (uint)local_30._2_2_;
    switch(local_38._4_4_) {
    case 4:
      DAT_0011d8c8 = DAT_0011d8c8 + 1;
      uVar1 = 1 << (ulong)(uVar5 & 0x1f);
      if ((uVar1 & DATARMNETecc0627c70[0x689]) == 0) {
LAB_001123f4:
        uVar3 = 300;
        goto LAB_001122fc;
      }
      if ((DATARMNET121c8bc82a & uVar1) != 0) {
        DAT_0011d918 = DAT_0011d918 + 1;
        goto LAB_001122f4;
      }
      if ((uVar5 != DATARMNETecc0627c70[0x676]) || (local_30._2_2_ != DATARMNETecc0627c70[0x672])) {
        if ((DATARMNETecc0627c70[0x689] >> (ulong)(DATARMNETecc0627c70[0x676] & 0x1f) & 1) != 0) {
          DAT_0011d928 = DAT_0011d928 + 1;
        }
        goto LAB_001124bc;
      }
      break;
    case 5:
      uVar5 = 1 << (ulong)(uVar5 & 0x1f);
      DAT_0011d8c0 = DAT_0011d8c0 + 1;
      if (((uVar5 & DATARMNETecc0627c70[0x68a]) == 0) ||
         ((DATARMNETecc0627c70[0x68a] >> (ulong)(DATARMNETecc0627c70[0x672] & 0x1f) & 1) != 0))
      goto LAB_001123f4;
      if ((DATARMNET121c8bc82a & uVar5) != 0) {
        DAT_0011d920 = DAT_0011d920 + 1;
        goto LAB_001122f4;
      }
LAB_001124bc:
      DATARMNETecc0627c70[0x672] = (byte)(local_30 >> 0x10);
      __rcu_read_lock();
      DATARMNET8f9da46b14();
      __rcu_read_unlock();
      break;
    case 6:
      DATARMNET3874292c18 = uVar5;
      break;
    case 7:
      DATARMNETbb1a9dff8b = uVar5;
      break;
    default:
      iVar2 = DATARMNET5f72606f6f(local_30 & 0xffff,uVar5,local_38 & 0xffffffff);
      if (iVar2 == 1) {
        DATARMNET5d4ca1da1c(param_2,0x2d7);
        uVar3 = 0x35;
      }
      else {
        DATARMNET5d4ca1da1c(param_2,0x2d0);
        uVar3 = 0x36;
      }
      trace_rmnet_shs_wq_high
                (uVar3,(undefined2)local_30,local_30._2_2_,(undefined4)local_38,local_38._4_4_);
      goto LAB_001122dc;
    }
    uVar3 = 300;
  }
  DATARMNET5d4ca1da1c(param_2,uVar3);
LAB_001122dc:
  uVar3 = 0;
LAB_00112304:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// DATARMNETc850634243 @ 00112554 size=104
// signature: undefined DATARMNETc850634243(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETc850634243(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (DATARMNETc252c204a8 == 0) {
    DATARMNETc252c204a8 = 1;
  }
  if (param_2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    DATARMNETb01cbc5ec9 = *(undefined8 *)(param_2 + 0x28);
    uVar1 = 0;
    DATARMNET373156e169 = *(undefined4 *)(param_2 + 4);
  }
  return uVar1;
}



//------------------------------------------------------------
// DATARMNET8d0d510d45 @ 00112650 size=184
// signature: undefined DATARMNET8d0d510d45(void)
// callers: [DATARMNETc2b0dbbb32, DATARMNET756778f14f]
//------------------------------------------------------------

void DATARMNET8d0d510d45(undefined4 param_1,undefined8 *param_2)

{
  long lVar1;
  long local_38;
  long lStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  lStack_30 = 0;
  if (param_2 != (undefined8 *)0x0) {
    param_2[0xd] = 0;
    param_2[0xe] = 0;
    param_2[0xb] = 0;
    param_2[0xc] = 0;
    param_2[9] = 0;
    param_2[10] = 0;
    param_2[7] = 0;
    param_2[8] = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    *param_2 = 0;
    ktime_get_real_ts64(&local_38);
    *(undefined4 *)param_2 = param_1;
    *(undefined2 *)((long)param_2 + 5) = 0;
    *(undefined1 *)((long)param_2 + 7) = 0;
    *(undefined1 *)((long)param_2 + 4) = 1;
    *(undefined2 *)((long)param_2 + 0x62) = 1;
    *(undefined1 *)((long)param_2 + 0x72) = 1;
    *(undefined2 *)(param_2 + 0xe) = 1;
    param_2[0xd] = lStack_30 + local_38 * 1000000000;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET1d4b1eff85 @ 0011270c size=192
// signature: undefined DATARMNET1d4b1eff85(void)
// callers: [DATARMNET02fc8b29a0, DATARMNET765b8ecfba, DATARMNETcd6e26f0ad]
//------------------------------------------------------------

void DATARMNET1d4b1eff85(undefined8 *param_1,undefined1 param_2,undefined1 param_3)

{
  long lVar1;
  long local_48;
  long lStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  lStack_40 = 0;
  if (param_1 != (undefined8 *)0x0) {
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    param_1[9] = 0;
    param_1[10] = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    *param_1 = 0;
    ktime_get_real_ts64(&local_48);
    *(undefined1 *)param_1 = param_2;
    *(undefined1 *)((long)param_1 + 1) = param_3;
    *(undefined2 *)((long)param_1 + 0x62) = 2;
    *(undefined1 *)((long)param_1 + 0x72) = 1;
    *(undefined2 *)(param_1 + 0xe) = 1;
    param_1[0xd] = lStack_40 + local_48 * 1000000000;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNETb5d58adbe7 @ 001127d0 size=232
// signature: undefined DATARMNETb5d58adbe7(void)
// callers: [DATARMNET02fc8b29a0, DATARMNETc2b0dbbb32, DATARMNET765b8ecfba, DATARMNET756778f14f, DATARMNETcd6e26f0ad]
//------------------------------------------------------------

undefined8 DATARMNETb5d58adbe7(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  if ((DATARMNET77097baa98 != 0) &&
     (lVar2 = __alloc_skb(0xe94,0xa20,0,0xffffffff), iVar1 = DATARMNETf1e47cb243, lVar2 != 0)) {
    DATARMNETf1e47cb243 = DATARMNETf1e47cb243 + 1;
    lVar3 = genlmsg_put(lVar2,0,iVar1,&rmnet_shs_genl_msg_family,0,1);
    if ((lVar3 == 0) || (iVar1 = nla_put(lVar2,2,0x78,param_1), iVar1 != 0)) {
      kfree(lVar2);
    }
    else {
      *(int *)(lVar3 + -0x14) =
           (*(int *)(lVar2 + 0xd8) + *(int *)(lVar2 + 0xd0)) - ((int)lVar3 + -0x14);
      iVar1 = netlink_unicast(*(undefined8 *)(DATARMNET77097baa98 + 0x118),lVar2,DATARMNET990a29d492
                              ,0x40);
      if (-1 < iVar1) {
        return 0;
      }
    }
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// DATARMNETd65d1351b9 @ 001128bc size=52
// signature: undefined DATARMNETd65d1351b9(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETd65d1351b9(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_2 != 0) && (DATARMNETc252c204a8 != 0)) {
    DATARMNET77097baa98 = *(undefined8 *)(param_2 + 0x28);
    uVar1 = 0;
    DATARMNET990a29d492 = *(undefined4 *)(param_2 + 4);
  }
  return uVar1;
}



//------------------------------------------------------------
// DATARMNET0dbc627e8f @ 001128f4 size=112
// signature: undefined DATARMNET0dbc627e8f(void)
// callers: [init_module]
//------------------------------------------------------------

undefined8 DATARMNET0dbc627e8f(void)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  puVar2 = &DATARMNETecc643c219;
  DATARMNETc252c204a8 = 0;
  iVar1 = genl_register_family(&DATARMNETecc643c219);
  if (iVar1 == 0) {
    puVar2 = &rmnet_shs_genl_msg_family;
    iVar1 = genl_register_family(&rmnet_shs_genl_msg_family);
    uVar3 = 0;
    if (iVar1 == 0) {
      return 0;
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  genl_unregister_family(puVar2);
  return uVar3;
}



//------------------------------------------------------------
// DATARMNETeabd69d1ab @ 00112968 size=68
// signature: undefined DATARMNETeabd69d1ab(void)
// callers: [cleanup_module]
//------------------------------------------------------------

undefined8 DATARMNETeabd69d1ab(void)

{
  DATARMNET5945236cd3(0x2a);
  genl_unregister_family(&DATARMNETecc643c219);
  DATARMNETc252c204a8 = 0;
  genl_unregister_family(&rmnet_shs_genl_msg_family);
  return 0;
}



//------------------------------------------------------------
// DATARMNET28a80d526e @ 001129c8 size=196
// signature: undefined DATARMNET28a80d526e(void)
// callers: [DATARMNETcd6e26f0ad]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET28a80d526e(long param_1,long *param_2)

{
  long lVar1;
  undefined4 uVar2;
  long *plVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  
  if ((param_1 == 0) || (param_2 == (long *)0x0)) {
    DAT_0011daa8 = DAT_0011daa8 + 1;
  }
  else {
    plVar3 = (long *)kmalloc_trace(___rcu_read_lock,0xb20,0x38);
    if (plVar3 == (long *)0x0) {
      DAT_0011dab0 = DAT_0011dab0 + 1;
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 300);
      lVar6 = *(long *)(param_1 + 0xb0);
      *(undefined2 *)((long)plVar3 + 0x34) = *(undefined2 *)(param_1 + 0x136);
      lVar5 = *(long *)(param_1 + 0x124);
      *(undefined4 *)(plVar3 + 6) = uVar2;
      lVar1 = *(long *)(param_1 + 0xa0);
      lVar7 = *param_2;
      plVar3[2] = *(long *)(param_1 + 0x98);
      plVar3[3] = lVar6;
      plVar3[4] = lVar1;
      plVar3[5] = lVar5;
      uVar4 = __list_add_valid(plVar3,param_2,lVar7);
      if ((uVar4 & 1) != 0) {
        *(long **)(lVar7 + 8) = plVar3;
        *plVar3 = lVar7;
        plVar3[1] = (long)param_2;
        *param_2 = (long)plVar3;
      }
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNET3af54cd726 @ 00112a90 size=140
// signature: undefined DATARMNET3af54cd726(void)
// callers: [DATARMNETcd6e26f0ad]
//------------------------------------------------------------

void DATARMNET3af54cd726(long *param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  
  if (param_1 == (long *)0x0) {
    DAT_0011daa8 = DAT_0011daa8 + 1;
  }
  else {
    plVar3 = (long *)*param_1;
    while (plVar3 != param_1) {
      plVar5 = (long *)*plVar3;
      uVar4 = __list_del_entry_valid(plVar3);
      if ((uVar4 & 1) != 0) {
        lVar1 = *plVar3;
        plVar2 = (long *)plVar3[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar3 = (long)plVar3;
      plVar3[1] = (long)plVar3;
      kfree(plVar3);
      plVar3 = plVar5;
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNET24e4475345 @ 00112b20 size=196
// signature: undefined DATARMNET24e4475345(void)
// callers: [DATARMNETcd6e26f0ad]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET24e4475345(long param_1,long *param_2)

{
  undefined4 uVar1;
  int iVar2;
  long *plVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  
  if ((param_1 == 0) || (param_2 == (long *)0x0)) {
    DAT_0011daa8 = DAT_0011daa8 + 1;
  }
  else {
    iVar2 = DATARMNET362b15f941(*(undefined2 *)(param_1 + 0x136));
    if (iVar2 == 0) {
      plVar3 = (long *)kmalloc_trace(___rcu_read_lock,0xb20,0x28);
      if (plVar3 == (long *)0x0) {
        DAT_0011dab0 = DAT_0011dab0 + 1;
      }
      else {
        uVar1 = *(undefined4 *)(param_1 + 0x124);
        lVar5 = *(long *)(param_1 + 0xb0);
        lVar6 = *(long *)(param_1 + 0x98);
        *(undefined2 *)((long)plVar3 + 0x24) = *(undefined2 *)(param_1 + 0x136);
        lVar7 = *param_2;
        *(undefined4 *)(plVar3 + 4) = uVar1;
        plVar3[2] = lVar6;
        plVar3[3] = lVar5;
        uVar4 = __list_add_valid(plVar3,param_2,lVar7);
        if ((uVar4 & 1) != 0) {
          *(long **)(lVar7 + 8) = plVar3;
          *plVar3 = lVar7;
          plVar3[1] = (long)param_2;
          *param_2 = (long)plVar3;
        }
      }
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNETa1b141715b @ 00112be8 size=140
// signature: undefined DATARMNETa1b141715b(void)
// callers: [DATARMNETcd6e26f0ad]
//------------------------------------------------------------

void DATARMNETa1b141715b(long *param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  
  if (param_1 == (long *)0x0) {
    DAT_0011daa8 = DAT_0011daa8 + 1;
  }
  else {
    plVar3 = (long *)*param_1;
    while (plVar3 != param_1) {
      plVar5 = (long *)*plVar3;
      uVar4 = __list_del_entry_valid(plVar3);
      if ((uVar4 & 1) != 0) {
        lVar1 = *plVar3;
        plVar2 = (long *)plVar3[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar3 = (long)plVar3;
      plVar3[1] = (long)plVar3;
      kfree(plVar3);
      plVar3 = plVar5;
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNETc6439e3d71 @ 00112c78 size=272
// signature: undefined DATARMNETc6439e3d71(void)
// callers: [DATARMNETcd6e26f0ad]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETc6439e3d71(long param_1,long param_2,long *param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  code *pcVar4;
  long *plVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  
  if ((param_2 == 0) || (param_3 == (long *)0x0)) {
    DAT_0011daa8 = DAT_0011daa8 + 1;
  }
  else {
    uVar6 = (ulong)*(ushort *)(param_2 + 0x90);
    if (7 < uVar6) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x112d88);
      (*pcVar4)();
    }
    uVar8 = (&DATARMNET713717107f)[uVar6];
    iVar3 = *(int *)(param_1 + uVar6 * 0x98 + 0x8c);
    plVar5 = (long *)kmalloc_trace(___rcu_read_lock,0xb20,0x30);
    if (plVar5 == (long *)0x0) {
      DAT_0011dab0 = DAT_0011dab0 + 1;
    }
    else {
      *(undefined2 *)(plVar5 + 5) = *(undefined2 *)(param_2 + 0x90);
      if (iVar3 < 1) {
        lVar7 = *param_3;
        plVar5[2] = uVar8;
        plVar5[3] = uVar8;
        plVar5[4] = 0;
      }
      else {
        lVar7 = *param_3;
        lVar1 = 0;
        if (*(ulong *)(param_2 + 0x48) <= uVar8) {
          lVar1 = uVar8 - *(ulong *)(param_2 + 0x48);
        }
        lVar2 = 0;
        if (*(ulong *)(param_2 + 0x68) <= uVar8) {
          lVar2 = uVar8 - *(ulong *)(param_2 + 0x68);
        }
        plVar5[4] = *(long *)(param_2 + 0x50);
        plVar5[2] = lVar1;
        plVar5[3] = lVar2;
      }
      uVar6 = __list_add_valid(plVar5,param_3,lVar7);
      if ((uVar6 & 1) != 0) {
        *(long **)(lVar7 + 8) = plVar5;
        *plVar5 = lVar7;
        plVar5[1] = (long)param_3;
        *param_3 = (long)plVar5;
      }
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNETb177316a15 @ 00112d8c size=140
// signature: undefined DATARMNETb177316a15(void)
// callers: [DATARMNETcd6e26f0ad]
//------------------------------------------------------------

void DATARMNETb177316a15(long *param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  
  if (param_1 == (long *)0x0) {
    DAT_0011daa8 = DAT_0011daa8 + 1;
  }
  else {
    plVar3 = (long *)*param_1;
    while (plVar3 != param_1) {
      plVar5 = (long *)*plVar3;
      uVar4 = __list_del_entry_valid(plVar3);
      if ((uVar4 & 1) != 0) {
        lVar1 = *plVar3;
        plVar2 = (long *)plVar3[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar3 = (long)plVar3;
      plVar3[1] = (long)plVar3;
      kfree(plVar3);
      plVar3 = plVar5;
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNET312b06829d @ 00112e1c size=260
// signature: undefined DATARMNET312b06829d(void)
// callers: [DATARMNETcd6e26f0ad]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET312b06829d(long param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  long *plVar8;
  ulong uVar9;
  long *plVar10;
  long lVar11;
  
  if ((param_1 == 0) || (param_2 == (long *)0x0)) {
    DAT_0011daa8 = DAT_0011daa8 + 1;
  }
  else {
    plVar8 = (long *)kmalloc_trace(_alt_cb_patch_nops,0xb20,0x90);
    if ((plVar8 == (long *)0x0) || (plVar10 = *(long **)(param_1 + 0x60), plVar10 == (long *)0x0)) {
      DAT_0011dab0 = DAT_0011dab0 + 1;
    }
    else {
      lVar2 = *(long *)(param_1 + 0xa0);
      lVar1 = *(long *)(param_1 + 0xb0);
      lVar3 = *(long *)(param_1 + 0xb8);
      uVar4 = *(undefined4 *)(param_1 + 0x136);
      uVar6 = *(undefined1 *)(param_1 + 0x13b);
      plVar8[10] = *(long *)(param_1 + 0x98);
      plVar8[0xb] = lVar1;
      uVar5 = *(undefined4 *)(param_1 + 0x124);
      plVar8[0xc] = lVar2;
      plVar8[0xd] = lVar3;
      uVar7 = *(undefined1 *)(param_1 + 0x13a);
      *(undefined1 *)(plVar8 + 0x11) = uVar6;
      *(undefined4 *)(plVar8 + 0x10) = uVar5;
      *(undefined4 *)((long)plVar8 + 0x84) = uVar4;
      lVar1 = *(long *)(param_1 + 0xc0);
      lVar2 = *(long *)(param_1 + 200);
      *(undefined1 *)((long)plVar8 + 0x89) = uVar7;
      lVar11 = *param_2;
      plVar8[0xe] = lVar1;
      plVar8[0xf] = lVar2;
      plVar8[2] = *plVar10;
      lVar2 = plVar10[4];
      lVar1 = plVar10[1];
      lVar3 = plVar10[2];
      plVar8[5] = plVar10[3];
      plVar8[6] = lVar2;
      plVar8[3] = lVar1;
      plVar8[4] = lVar3;
      lVar1 = plVar10[5];
      lVar2 = plVar10[6];
      *(int *)(plVar8 + 9) = (int)plVar10[7];
      plVar8[7] = lVar1;
      plVar8[8] = lVar2;
      uVar9 = __list_add_valid(plVar8,param_2,lVar11);
      if ((uVar9 & 1) != 0) {
        *(long **)(lVar11 + 8) = plVar8;
        *plVar8 = lVar11;
        plVar8[1] = (long)param_2;
        *param_2 = (long)plVar8;
      }
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNET6f4b0915d3 @ 00112f24 size=252
// signature: undefined DATARMNET6f4b0915d3(void)
// callers: [DATARMNETcd6e26f0ad]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET6f4b0915d3(long param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  long *plVar7;
  ulong uVar8;
  long *plVar9;
  long lVar10;
  
  if ((param_1 == 0) || (param_2 == (long *)0x0)) {
    DAT_0011daa8 = DAT_0011daa8 + 1;
  }
  else {
    plVar7 = (long *)kmalloc_trace(_alt_cb_patch_nops,0xb20,0x90);
    if ((plVar7 == (long *)0x0) || (plVar9 = *(long **)(param_1 + 0x60), plVar9 == (long *)0x0)) {
      DAT_0011dab0 = DAT_0011dab0 + 1;
    }
    else {
      lVar2 = *(long *)(param_1 + 0xa0);
      lVar1 = *(long *)(param_1 + 0xb0);
      lVar3 = *(long *)(param_1 + 0xb8);
      uVar4 = *(undefined4 *)(param_1 + 0x136);
      uVar6 = *(undefined1 *)(param_1 + 0x13b);
      plVar7[10] = *(long *)(param_1 + 0x98);
      plVar7[0xb] = lVar1;
      uVar5 = *(undefined4 *)(param_1 + 0x124);
      plVar7[0xc] = lVar2;
      plVar7[0xd] = lVar3;
      *(undefined1 *)(plVar7 + 0x11) = uVar6;
      *(undefined4 *)(plVar7 + 0x10) = uVar5;
      *(undefined4 *)((long)plVar7 + 0x84) = uVar4;
      lVar1 = *(long *)(param_1 + 200);
      lVar10 = *param_2;
      plVar7[0xe] = *(long *)(param_1 + 0xc0);
      plVar7[0xf] = lVar1;
      plVar7[2] = *plVar9;
      lVar2 = plVar9[4];
      lVar1 = plVar9[1];
      lVar3 = plVar9[2];
      plVar7[5] = plVar9[3];
      plVar7[6] = lVar2;
      plVar7[3] = lVar1;
      plVar7[4] = lVar3;
      lVar1 = plVar9[5];
      lVar2 = plVar9[6];
      *(int *)(plVar7 + 9) = (int)plVar9[7];
      plVar7[7] = lVar1;
      plVar7[8] = lVar2;
      uVar8 = __list_add_valid(plVar7,param_2,lVar10);
      if ((uVar8 & 1) != 0) {
        *(long **)(lVar10 + 8) = plVar7;
        *plVar7 = lVar10;
        plVar7[1] = (long)param_2;
        *param_2 = (long)plVar7;
      }
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNETf7730d41c1 @ 00113024 size=140
// signature: undefined DATARMNETf7730d41c1(void)
// callers: [DATARMNETcd6e26f0ad]
//------------------------------------------------------------

void DATARMNETf7730d41c1(long *param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  
  if (param_1 == (long *)0x0) {
    DAT_0011daa8 = DAT_0011daa8 + 1;
  }
  else {
    plVar3 = (long *)*param_1;
    while (plVar3 != param_1) {
      plVar5 = (long *)*plVar3;
      uVar4 = __list_del_entry_valid(plVar3);
      if ((uVar4 & 1) != 0) {
        lVar1 = *plVar3;
        plVar2 = (long *)plVar3[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar3 = (long)plVar3;
      plVar3[1] = (long)plVar3;
      kfree(plVar3);
      plVar3 = plVar5;
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNETcc489fbbad @ 001130b4 size=140
// signature: undefined DATARMNETcc489fbbad(void)
// callers: [DATARMNETcd6e26f0ad]
//------------------------------------------------------------

void DATARMNETcc489fbbad(long *param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  
  if (param_1 == (long *)0x0) {
    DAT_0011daa8 = DAT_0011daa8 + 1;
  }
  else {
    plVar3 = (long *)*param_1;
    while (plVar3 != param_1) {
      plVar5 = (long *)*plVar3;
      uVar4 = __list_del_entry_valid(plVar3);
      if ((uVar4 & 1) != 0) {
        lVar1 = *plVar3;
        plVar2 = (long *)plVar3[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar3 = (long)plVar3;
      plVar3[1] = (long)plVar3;
      kfree(plVar3);
      plVar3 = plVar5;
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNET5157210c44 @ 00113144 size=560
// signature: undefined DATARMNET5157210c44(void)
// callers: [DATARMNET7792d4f4ad]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET5157210c44(long *param_1)

{
  long *plVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  long *plVar5;
  long lVar6;
  
  plVar1 = DATARMNET410036d5ac;
  if (param_1 != (long *)0x0) {
    plVar5 = (long *)*param_1;
    if (plVar5 != param_1) {
      DATARMNET63c47f3c37 = plVar5[2];
      DAT_0011e148 = plVar5[3];
      DAT_0011e150 = plVar5[4];
      DAT_0011e158 = *(undefined2 *)(plVar5 + 5);
      DAT_0011e15a = DATARMNETecc0627c70[0x689];
      plVar5 = (long *)*plVar5;
      if (plVar5 != param_1) {
        DAT_0011e163 = plVar5[3];
        DAT_0011e15b = plVar5[2];
        DAT_0011e16b = plVar5[4];
        DAT_0011e173 = (undefined2)plVar5[5];
        DAT_0011e175 = DATARMNETecc0627c70[0x689];
        plVar5 = (long *)*plVar5;
        if (plVar5 != param_1) {
          DAT_0011e17e = plVar5[3];
          DAT_0011e176 = plVar5[2];
          DAT_0011e186 = plVar5[4];
          DAT_0011e18e = (undefined2)plVar5[5];
          DAT_0011e190 = DATARMNETecc0627c70[0x689];
          plVar5 = (long *)*plVar5;
          if (plVar5 != param_1) {
            DAT_0011e199 = plVar5[3];
            DAT_0011e191 = plVar5[2];
            DAT_0011e1a1 = plVar5[4];
            DAT_0011e1a9 = (undefined2)plVar5[5];
            DAT_0011e1ab = DATARMNETecc0627c70[0x689];
            plVar5 = (long *)*plVar5;
            if (plVar5 != param_1) {
              DAT_0011e1b4 = plVar5[3];
              DAT_0011e1ac = plVar5[2];
              DAT_0011e1bc = plVar5[4];
              DAT_0011e1c4 = (undefined2)plVar5[5];
              DAT_0011e1c6 = DATARMNETecc0627c70[0x689];
              plVar5 = (long *)*plVar5;
              if (plVar5 != param_1) {
                DAT_0011e1cf = plVar5[3];
                DAT_0011e1c7 = plVar5[2];
                DAT_0011e1d7 = plVar5[4];
                DAT_0011e1df = (undefined2)plVar5[5];
                DAT_0011e1e1 = DATARMNETecc0627c70[0x689];
                plVar5 = (long *)*plVar5;
                if (plVar5 != param_1) {
                  DAT_0011e1ea = plVar5[3];
                  DAT_0011e1e2 = plVar5[2];
                  DAT_0011e1f2 = plVar5[4];
                  DAT_0011e1fa = (undefined2)plVar5[5];
                  DAT_0011e1fc = DATARMNETecc0627c70[0x689];
                  plVar5 = (long *)*plVar5;
                  if (plVar5 != param_1) {
                    DAT_0011e205 = plVar5[3];
                    DAT_0011e1fd = plVar5[2];
                    DAT_0011e20d = plVar5[4];
                    DAT_0011e215 = (undefined2)plVar5[5];
                    DAT_0011e217 = DATARMNETecc0627c70[0x689];
                  }
                }
              }
            }
          }
        }
      }
    }
    if (DATARMNET410036d5ac != (long *)0x0) {
      memcpy((void *)*DATARMNET410036d5ac,&DATARMNET63c47f3c37,0xd8);
      uVar4 = _DAT_00126898;
      uVar3 = _DAT_0012688c;
      uVar2 = _DAT_00126884;
      lVar6 = *plVar1;
      *(undefined8 *)(lVar6 + 0xd8) = _DAT_00126890;
      *(undefined4 *)(lVar6 + 0xe0) = uVar4;
      *(undefined8 *)(lVar6 + 0xe4) = uVar2;
      *(undefined4 *)(lVar6 + 0xec) = uVar3;
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNET0e273eab79 @ 00113378 size=248
// signature: undefined DATARMNET0e273eab79(void)
// callers: [DATARMNET7792d4f4ad]
//------------------------------------------------------------

void DATARMNET0e273eab79(long *param_1)

{
  ulong uVar1;
  ulong uVar2;
  code *pcVar3;
  ulong uVar4;
  long *plVar5;
  
  if (param_1 != (long *)0x0) {
    plVar5 = (long *)*param_1;
    if (plVar5 == param_1) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0;
      do {
        if (plVar5[2] != 0) {
          if (99 < (uint)uVar4) break;
          uVar1 = uVar4 * 0x1e;
          if (0xb9c < uVar1) {
LAB_0011346c:
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(1,0x113470);
            (*pcVar3)();
          }
          uVar2 = uVar4 * 0x1e;
          *(undefined2 *)(&DAT_0011e23c + uVar2) = *(undefined2 *)((long)plVar5 + 0x24);
          if (((0xb9c < uVar2) || (*(int *)(&DAT_0011e238 + uVar2) = (int)plVar5[4], 0xba8 < uVar2))
             || (*(long *)(&DAT_0011e228 + uVar4 * 0x1e) = plVar5[3], 0xbb0 < uVar1))
          goto LAB_0011346c;
          uVar4 = (ulong)((uint)uVar4 + 1);
          *(long *)((long)&DATARMNET22b4032799 + uVar1) = plVar5[2];
        }
        plVar5 = (long *)*plVar5;
      } while (plVar5 != param_1);
    }
    if (DATARMNET19c47a9f3a != (long *)0x0) {
      *(short *)*DATARMNET19c47a9f3a = (short)uVar4;
      memcpy((void *)(*DATARMNET19c47a9f3a + 2),&DATARMNET22b4032799,3000);
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNETe15af8eb6d @ 00113474 size=316
// signature: undefined DATARMNETe15af8eb6d(void)
// callers: [DATARMNET7792d4f4ad]
//------------------------------------------------------------

void DATARMNETe15af8eb6d(long *param_1)

{
  code *pcVar1;
  uint uVar2;
  long *plVar3;
  ulong uVar4;
  
  if (param_1 != (long *)0x0) {
    plVar3 = (long *)*param_1;
    if (plVar3 == param_1) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0;
      do {
        if (plVar3[2] != 0) {
          if (99 < uVar2) break;
          if (0xeb4 < (ulong)uVar2 * 0x26) {
LAB_0011356c:
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(1,0x113570);
            (*pcVar1)();
          }
          uVar4 = (ulong)uVar2;
          *(undefined2 *)(&DAT_0011ee04 + uVar4 * 0x26) = *(undefined2 *)((long)plVar3 + 0x34);
          if ((((0xebc < uVar4 * 0x26) ||
               (*(int *)(&DAT_0011edf8 + uVar4 * 0x26) = (int)plVar3[5], 0xec8 < uVar4 * 0x26)) ||
              (*(long *)(&DAT_0011ede8 + uVar4 * 0x26) = plVar3[3], 0xed0 < (ulong)uVar2 * 0x26)) ||
             (((*(long *)((long)&DATARMNETb0d78d576f + (ulong)uVar2 * 0x26) = plVar3[2],
               0xec0 < uVar4 * 0x26 ||
               (*(long *)(&DAT_0011edf0 + uVar4 * 0x26) = plVar3[4], 0xeb4 < uVar4 * 0x26)) ||
              (*(int *)(&DAT_0011ee00 + uVar4 * 0x26) = (int)plVar3[6], 0xeb8 < uVar4 * 0x26))))
          goto LAB_0011356c;
          uVar2 = uVar2 + 1;
          *(undefined4 *)(&DAT_0011edfc + uVar4 * 0x26) = *(undefined4 *)((long)plVar3 + 0x2c);
        }
        plVar3 = (long *)*plVar3;
      } while (plVar3 != param_1);
    }
    if (DATARMNET22e796eff3 != (long *)0x0) {
      *(short *)*DATARMNET22e796eff3 = (short)uVar2;
      memcpy((void *)(*DATARMNET22e796eff3 + 2),&DATARMNETb0d78d576f,0xed8);
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNET78f3a0ca4f @ 001135b4 size=440
// signature: undefined DATARMNET78f3a0ca4f(void)
// callers: [DATARMNET7792d4f4ad]
//------------------------------------------------------------

void DATARMNET78f3a0ca4f(long *param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  code *pcVar6;
  uint uVar7;
  long *plVar8;
  
  if (param_1 != (long *)0x0) {
    plVar8 = (long *)*param_1;
    if (plVar8 == param_1) {
      uVar7 = 0;
    }
    else {
      uVar7 = 0;
      do {
        if (plVar8[10] != 0) {
          if (0x1d < uVar7) break;
          lVar5 = (ulong)uVar7 * 0x75;
          *(long *)((long)&DATARMNET3d25ff4ef4 + lVar5) = plVar8[2];
          lVar2 = plVar8[6];
          lVar1 = plVar8[3];
          lVar3 = plVar8[4];
          *(long *)((long)&DAT_0011fcd8 + lVar5) = plVar8[5];
          *(long *)((long)&DAT_0011fce0 + lVar5) = lVar2;
          *(long *)((long)&DAT_0011fcc8 + lVar5) = lVar1;
          *(long *)((long)&DAT_0011fcd0 + lVar5) = lVar3;
          lVar1 = plVar8[7];
          lVar2 = plVar8[8];
          *(int *)((long)&DAT_0011fcf8 + lVar5) = (int)plVar8[9];
          *(long *)((long)&DAT_0011fce8 + lVar5) = lVar1;
          *(long *)((long)&DAT_0011fcf0 + lVar5) = lVar2;
          if ((((((0xd44 < (ulong)uVar7 * 0x75) ||
                 (*(undefined2 *)(&DAT_0011fd30 + (ulong)uVar7 * 0x75) =
                       *(undefined2 *)((long)plVar8 + 0x84), 0xd46 < (ulong)uVar7 * 0x75)) ||
                (*(int *)(&DAT_0011fd2c + (ulong)uVar7 * 0x75) = (int)plVar8[0x10],
                0xd6a < (ulong)uVar7 * 0x75)) ||
               ((*(long *)(&DAT_0011fd04 + (ulong)uVar7 * 0x75) = plVar8[0xb],
                0xd72 < (ulong)uVar7 * 0x75 ||
                (*(long *)(&DAT_0011fcfc + (ulong)uVar7 * 0x75) = plVar8[10],
                0xd62 < (ulong)uVar7 * 0x75)))) ||
              ((*(long *)(&DAT_0011fd0c + (ulong)uVar7 * 0x75) = plVar8[0xc],
               0xd42 < (ulong)uVar7 * 0x75 ||
               ((*(undefined2 *)(&DAT_0011fd32 + (ulong)uVar7 * 0x75) =
                      *(undefined2 *)((long)plVar8 + 0x86), 0xd42 < (ulong)uVar7 * 0x75 ||
                ((&DAT_0011fd34)[(ulong)uVar7 * 0x75] = (char)plVar8[0x11],
                0xd5a < (ulong)uVar7 * 0x75)))))) ||
             ((*(long *)(&DAT_0011fd14 + (ulong)uVar7 * 0x75) = plVar8[0xd],
              0xd52 < (ulong)uVar7 * 0x75 ||
              (*(long *)(&DAT_0011fd1c + (ulong)uVar7 * 0x75) = plVar8[0xe],
              0xd4a < (ulong)uVar7 * 0x75)))) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(1,0x11376c);
            (*pcVar6)();
          }
          uVar4 = (ulong)uVar7;
          uVar7 = uVar7 + 1;
          *(long *)(&DAT_0011fd24 + uVar4 * 0x75) = plVar8[0xf];
        }
        plVar8 = (long *)*plVar8;
      } while (plVar8 != param_1);
    }
    if (DATARMNET9b8000d2a7 != (long *)0x0) {
      *(short *)*DATARMNET9b8000d2a7 = (short)uVar7;
      memcpy((void *)(*DATARMNET9b8000d2a7 + 2),&DATARMNET3d25ff4ef4,0xdb6);
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNETa3d6c4072d @ 00113770 size=280
// signature: undefined DATARMNETa3d6c4072d(void)
// callers: [DATARMNET7792d4f4ad]
//------------------------------------------------------------

void DATARMNETa3d6c4072d(long *param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  bool bVar4;
  long *plVar5;
  undefined1 *puVar6;
  ulong uVar7;
  ulong uVar8;
  
  if (param_1 != (long *)0x0) {
    plVar5 = (long *)*param_1;
    if (plVar5 == param_1) {
      uVar8 = 0;
    }
    else {
      puVar6 = &DAT_00120af5;
      uVar7 = 0;
      do {
        *(long *)(puVar6 + -0x75) = plVar5[2];
        lVar2 = plVar5[6];
        lVar1 = plVar5[3];
        lVar3 = plVar5[4];
        *(long *)(puVar6 + -0x5d) = plVar5[5];
        *(long *)(puVar6 + -0x55) = lVar2;
        *(long *)(puVar6 + -0x6d) = lVar1;
        *(long *)(puVar6 + -0x65) = lVar3;
        lVar1 = plVar5[8];
        lVar2 = plVar5[9];
        *(long *)(puVar6 + -0x4d) = plVar5[7];
        *(int *)(puVar6 + -0x3d) = (int)lVar2;
        *(long *)(puVar6 + -0x45) = lVar1;
        *(undefined2 *)(puVar6 + -5) = *(undefined2 *)((long)plVar5 + 0x84);
        *(int *)(puVar6 + -9) = (int)plVar5[0x10];
        *(long *)(puVar6 + -0x31) = plVar5[0xb];
        *(long *)(puVar6 + -0x39) = plVar5[10];
        *puVar6 = *(undefined1 *)((long)plVar5 + 0x89);
        *(long *)(puVar6 + -0x29) = plVar5[0xc];
        *(undefined2 *)(puVar6 + -3) = *(undefined2 *)((long)plVar5 + 0x86);
        puVar6[-1] = (char)plVar5[0x11];
        *(long *)(puVar6 + -0x21) = plVar5[0xd];
        *(long *)(puVar6 + -0x19) = plVar5[0xe];
        *(long *)(puVar6 + -0x11) = plVar5[0xf];
        uVar8 = uVar7 + 1;
        plVar5 = (long *)*plVar5;
        if (plVar5 == param_1) break;
        puVar6 = puVar6 + 0x76;
        bVar4 = uVar7 < 0x1d;
        uVar7 = uVar8;
      } while (bVar4);
    }
    if (DATARMNET835a28686c != (long *)0x0) {
      *(short *)*DATARMNET835a28686c = (short)uVar8;
      memcpy((void *)(*DATARMNET835a28686c + 2),&DATARMNET2fdef9da24,0xdd4);
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNET78666f33a1 @ 0011388c size=640
// signature: undefined DATARMNET78666f33a1(void)
// callers: [DATARMNET7792d4f4ad]
//------------------------------------------------------------

void DATARMNET78666f33a1(void)

{
  code *pcVar1;
  size_t __n;
  undefined8 uVar2;
  char *__string;
  uint uVar3;
  undefined *puVar4;
  undefined **ppuVar5;
  ulong uVar6;
  undefined1 in_z12 [32];
  undefined4 in_p1;
  
  uVar2 = DATARMNETecc0627c70._392_8_;
  if (DATARMNETecc0627c70._392_8_ == 0) {
    DAT_0011da70 = DAT_0011da70 + 1;
  }
  else {
    if ((undefined **)DATARMNET30a3e83974 == &DATARMNET30a3e83974) {
      uVar3 = 0;
    }
    else {
      uVar3 = 0;
      ppuVar5 = (undefined **)DATARMNET30a3e83974;
      do {
        if (*(char *)((long)ppuVar5 + 0x5e) != '\0') {
          if (0x27 < uVar3) break;
          puVar4 = ppuVar5[2];
          if (puVar4 + 0xa40 != (undefined1 *)0x0) {
            if (0xf10 < (ulong)uVar3 * 0x61) {
LAB_00113af0:
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(1,0x113af4);
              (*pcVar1)();
            }
            uVar6 = (ulong)uVar3;
            *(undefined8 *)(DATARMNETf46265286b + uVar6 * 0x61 + 0x10) =
                 *(undefined8 *)(puVar4 + 0xaf8);
            if (((((0xf08 < uVar6 * 0x61) ||
                  (*(undefined8 *)(DATARMNETf46265286b + uVar6 * 0x61 + 0x18) =
                        *(undefined8 *)(puVar4 + 0xb28), 0xef8 < uVar6 * 0x61)) ||
                 (*(undefined8 *)(DATARMNETf46265286b + uVar6 * 0x61 + 0x28) =
                       *(undefined8 *)(puVar4 + 3000), 0xef0 < uVar6 * 0x61)) ||
                ((*(undefined8 *)(DATARMNETf46265286b + uVar6 * 0x61 + 0x30) =
                       *(undefined8 *)(puVar4 + 0xbc0), 0xee8 < uVar6 * 0x61 ||
                 (*(undefined8 *)(DATARMNETf46265286b + uVar6 * 0x61 + 0x38) =
                       *(undefined8 *)(puVar4 + 0xbc8), 0xee0 < uVar6 * 0x61)))) ||
               ((*(undefined8 *)(DATARMNETf46265286b + uVar6 * 0x61 + 0x40) =
                      *(undefined8 *)(puVar4 + 0xbd0), 0xec8 < uVar6 * 0x61 ||
                (DATARMNETf46265286b[uVar6 * 0x61 + 0x60] = puVar4[0xa40], 0xec8 < uVar6 * 0x61))))
            goto LAB_00113af0;
            *(undefined8 *)(DATARMNETf46265286b + uVar6 * 0x61 + 0x58) =
                 *(undefined8 *)(uVar2 + 0xad0);
            __string = ppuVar5[2];
            __n = strnlen(__string,0x10);
            if (0x10 < __n) {
              fortify_panic("strnlen");
LAB_00113b00:
              uVar2 = fortify_panic("__fortify_strlen");
              SVE_ldff1w(in_z12,in_p1,puVar4,uVar2);
              DATARMNETe4c5563cdb = proc_mkdir(&DAT_00115130,0);
              if (DATARMNETe4c5563cdb != 0) {
                proc_set_user(DATARMNETe4c5563cdb,0x3e9,0x3e9);
                proc_create("rmnet_shs_caps",0x1a4,DATARMNETe4c5563cdb,&DATARMNET668485bd14);
                proc_create("rmnet_shs_flows",0x1a4,DATARMNETe4c5563cdb,DATARMNETe84fbaa6af);
                proc_create("rmnet_shs_ss_flows",0x1a4,DATARMNETe4c5563cdb,DATARMNET8fe5f892a8);
                proc_create("rmnet_shs_fflows",0x1a4,DATARMNETe4c5563cdb,DATARMNET0104d40d4b);
                proc_create("rmnet_shs_ll_flows",0x1a4,DATARMNETe4c5563cdb,DATARMNETddcdf7bd4e);
                proc_create("rmnet_shs_netdev",0x1a4,DATARMNETe4c5563cdb,DATARMNET6eb63d9ad0);
                DATARMNET6bf538fa23();
                DATARMNET410036d5ac = 0;
                DATARMNET19c47a9f3a = 0;
                DATARMNET22e796eff3 = 0;
                DATARMNET9b8000d2a7 = 0;
                DATARMNET835a28686c = 0;
                DATARMNET67d31dc40a = (long *)0x0;
                DATARMNETaea4c85748();
              }
              return;
            }
            if (__n == 0x10) goto LAB_00113b00;
            memcpy(DATARMNETf46265286b + (ulong)uVar3 * 0x61,__string,__n);
            if (((0xf27 < (ulong)uVar3 * 0x61 + __n) ||
                ((DATARMNETf46265286b + (ulong)uVar3 * 0x61)[__n] = 0, 0xf00 < uVar6 * 0x61)) ||
               ((*(undefined8 *)(DATARMNETf46265286b + uVar6 * 0x61 + 0x20) =
                      *(undefined8 *)(puVar4 + 0xab8), 0xed0 < uVar6 * 0x61 ||
                (*(undefined **)(DATARMNETf46265286b + uVar6 * 0x61 + 0x50) = ppuVar5[-2],
                0xed8 < uVar6 * 0x61)))) goto LAB_00113af0;
            uVar3 = uVar3 + 1;
            *(undefined **)(DATARMNETf46265286b + uVar6 * 0x61 + 0x48) = ppuVar5[-1];
          }
        }
        ppuVar5 = (undefined **)*ppuVar5;
      } while (ppuVar5 != &DATARMNET30a3e83974);
    }
    if (DATARMNET67d31dc40a != (long *)0x0) {
      *(short *)*DATARMNET67d31dc40a = (short)uVar3;
      memcpy((void *)(*DATARMNET67d31dc40a + 2),DATARMNETf46265286b,0xf28);
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNETf5f83b943f @ 00113b10 size=296
// signature: undefined DATARMNETf5f83b943f(void)
// callers: [DATARMNET3ae0d614d6]
//------------------------------------------------------------

void DATARMNETf5f83b943f(void)

{
  DATARMNETe4c5563cdb = proc_mkdir(&DAT_00115130,0);
  if (DATARMNETe4c5563cdb != 0) {
    proc_set_user(DATARMNETe4c5563cdb,0x3e9,0x3e9);
    proc_create("rmnet_shs_caps",0x1a4,DATARMNETe4c5563cdb,&DATARMNET668485bd14);
    proc_create("rmnet_shs_flows",0x1a4,DATARMNETe4c5563cdb,DATARMNETe84fbaa6af);
    proc_create("rmnet_shs_ss_flows",0x1a4,DATARMNETe4c5563cdb,DATARMNET8fe5f892a8);
    proc_create("rmnet_shs_fflows",0x1a4,DATARMNETe4c5563cdb,DATARMNET0104d40d4b);
    proc_create("rmnet_shs_ll_flows",0x1a4,DATARMNETe4c5563cdb,DATARMNETddcdf7bd4e);
    proc_create("rmnet_shs_netdev",0x1a4,DATARMNETe4c5563cdb,DATARMNET6eb63d9ad0);
    DATARMNET6bf538fa23();
    DATARMNET410036d5ac = 0;
    DATARMNET19c47a9f3a = 0;
    DATARMNET22e796eff3 = 0;
    DATARMNET9b8000d2a7 = 0;
    DATARMNET835a28686c = 0;
    DATARMNET67d31dc40a = 0;
    DATARMNETaea4c85748();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET28d33bd09f @ 00113c3c size=204
// signature: undefined DATARMNET28d33bd09f(void)
// callers: [DATARMNETf7dcab9a9e]
//------------------------------------------------------------

void DATARMNET28d33bd09f(void)

{
  remove_proc_entry("rmnet_shs_caps",DATARMNETe4c5563cdb);
  remove_proc_entry("rmnet_shs_flows",DATARMNETe4c5563cdb);
  remove_proc_entry("rmnet_shs_ss_flows",DATARMNETe4c5563cdb);
  remove_proc_entry("rmnet_shs_fflows",DATARMNETe4c5563cdb);
  remove_proc_entry("rmnet_shs_ll_flows",DATARMNETe4c5563cdb);
  remove_proc_entry("rmnet_shs_netdev",DATARMNETe4c5563cdb);
  remove_proc_entry(&DAT_00115130,0);
  DATARMNET6bf538fa23();
  DATARMNET410036d5ac = 0;
  DATARMNET19c47a9f3a = 0;
  DATARMNET22e796eff3 = 0;
  DATARMNET9b8000d2a7 = 0;
  DATARMNET835a28686c = 0;
  DATARMNET67d31dc40a = 0;
  DATARMNETaea4c85748();
  return;
}



//------------------------------------------------------------
// DATARMNET33a80d3bf7 @ 00113d0c size=228
// signature: undefined DATARMNET33a80d3bf7(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNET33a80d3bf7(undefined8 param_1,long param_2)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  long *plVar5;
  long lVar6;
  undefined8 uVar7;
  
  DATARMNET6bf538fa23();
  if (DATARMNET410036d5ac == (long *)0x0) {
    plVar5 = (long *)kmalloc_trace(___rcu_read_lock,0xb20,0x10);
    if (plVar5 == (long *)0x0) {
      uVar7 = 0xfffffff4;
      goto LAB_00113d60;
    }
    lVar6 = get_zeroed_page(0xa20);
    *plVar5 = lVar6;
    if (lVar6 == 0) {
      kfree(plVar5);
      uVar7 = 0xfffffff4;
      goto LAB_00113d60;
    }
    DATARMNET410036d5ac = plVar5;
    *(undefined4 *)(plVar5 + 1) = 1;
  }
  else {
    puVar1 = (uint *)(DATARMNET410036d5ac + 1);
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
      uVar7 = 2;
    }
    else {
      if (-1 < (int)(uVar2 + 1 | uVar2)) goto LAB_00113d54;
      uVar7 = 1;
    }
    refcount_warn_saturate(puVar1,uVar7);
  }
LAB_00113d54:
  uVar7 = 0;
  *(long **)(param_2 + 0xd8) = DATARMNET410036d5ac;
LAB_00113d60:
  DATARMNETaea4c85748();
  return uVar7;
}



//------------------------------------------------------------
// DATARMNETaf2aa1d70f @ 00113e00 size=8
// signature: undefined DATARMNETaf2aa1d70f(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETaf2aa1d70f(void)

{
  return 0;
}



//------------------------------------------------------------
// DATARMNET4761dcd3fd @ 00113e0c size=8
// signature: undefined DATARMNET4761dcd3fd(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET4761dcd3fd(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  return param_3;
}



//------------------------------------------------------------
// DATARMNETcfbc4f0c39 @ 00113e18 size=168
// signature: undefined DATARMNETcfbc4f0c39(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETcfbc4f0c39(undefined8 param_1,long param_2)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  uint *puVar4;
  undefined8 *puVar5;
  
  DATARMNET6bf538fa23();
  if (DATARMNET410036d5ac != 0) {
    puVar5 = *(undefined8 **)(param_2 + 0xd8);
    puVar4 = (uint *)(puVar5 + 1);
    if (*puVar4 < 2) {
      free_pages(*puVar5,0);
      kfree(puVar5);
      DATARMNET410036d5ac = 0;
      *(undefined8 *)(param_2 + 0xd8) = 0;
    }
    else {
      Hint_Prefetch(puVar4,2,0,1);
      do {
        uVar1 = *puVar4;
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar4,0x10);
        if (bVar3) {
          *puVar4 = uVar1 - 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      if ((int)uVar1 < 2) {
        refcount_warn_saturate(puVar4,4);
      }
    }
  }
  DATARMNETaea4c85748();
  return 0;
}



//------------------------------------------------------------
// DATARMNET54418f934d @ 00113ed4 size=128
// signature: undefined DATARMNET54418f934d(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET54418f934d(long param_1,long param_2)

{
  int iVar1;
  
  *(undefined ***)(param_2 + 0x78) = &DATARMNETfa4e968e7d;
  iVar1 = *(int *)(*(long *)(param_2 + 0x10) + 0xb0);
  if (*(int *)(param_2 + 0x28) != iVar1) {
    down_write(*(undefined8 *)(param_2 + 0x30));
    *(int *)(param_2 + 0x28) = iVar1;
    up_write(*(undefined8 *)(param_2 + 0x30));
  }
  *(ulong *)(param_2 + 0x20) = *(ulong *)(param_2 + 0x20) | 0x4040000;
  *(undefined8 *)(param_2 + 0x90) = *(undefined8 *)(param_1 + 0xd8);
  return 0;
}



//------------------------------------------------------------
// DATARMNET6069bf201a @ 00113f58 size=4
// signature: undefined DATARMNET6069bf201a(void)
// callers: []
//------------------------------------------------------------

void DATARMNET6069bf201a(void)

{
  return;
}



//------------------------------------------------------------
// DATARMNET0f6b7f3f93 @ 00113f60 size=4
// signature: undefined DATARMNET0f6b7f3f93(void)
// callers: []
//------------------------------------------------------------

void DATARMNET0f6b7f3f93(void)

{
  return;
}



//------------------------------------------------------------
// DATARMNET9efe8a3d18 @ 00113f68 size=168
// signature: undefined DATARMNET9efe8a3d18(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET9efe8a3d18(long *param_1)

{
  int *piVar1;
  long lVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  
  DATARMNET6bf538fa23();
  if ((DATARMNET410036d5ac == 0) || (**(long **)(*param_1 + 0x90) == 0)) {
    uVar7 = 0x40;
  }
  else {
    lVar5 = (((**(long **)(*param_1 + 0x90) << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40;
    lVar2 = lVar5 + -0x200000000;
    uVar6 = *(ulong *)(lVar5 + -0x1fffffff8);
    lVar5 = lVar2;
    if ((uVar6 & 1) != 0) {
      lVar5 = uVar6 - 1;
    }
    piVar1 = (int *)(lVar5 + 0x34);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = *piVar1 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    uVar7 = 0;
    param_1[10] = lVar2;
  }
  DATARMNETaea4c85748();
  return uVar7;
}



//------------------------------------------------------------
// DATARMNET0935e3beb9 @ 00114020 size=228
// signature: undefined DATARMNET0935e3beb9(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNET0935e3beb9(undefined8 param_1,long param_2)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  long *plVar5;
  long lVar6;
  undefined8 uVar7;
  
  DATARMNET6bf538fa23();
  if (DATARMNET19c47a9f3a == (long *)0x0) {
    plVar5 = (long *)kmalloc_trace(___rcu_read_lock,0xb20,0x10);
    if (plVar5 == (long *)0x0) {
      uVar7 = 0xfffffff4;
      goto LAB_00114074;
    }
    lVar6 = get_zeroed_page(0xa20);
    *plVar5 = lVar6;
    if (lVar6 == 0) {
      kfree(plVar5);
      uVar7 = 0xfffffff4;
      goto LAB_00114074;
    }
    DATARMNET19c47a9f3a = plVar5;
    *(undefined4 *)(plVar5 + 1) = 1;
  }
  else {
    puVar1 = (uint *)(DATARMNET19c47a9f3a + 1);
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
      uVar7 = 2;
    }
    else {
      if (-1 < (int)(uVar2 + 1 | uVar2)) goto LAB_00114068;
      uVar7 = 1;
    }
    refcount_warn_saturate(puVar1,uVar7);
  }
LAB_00114068:
  uVar7 = 0;
  *(long **)(param_2 + 0xd8) = DATARMNET19c47a9f3a;
LAB_00114074:
  DATARMNETaea4c85748();
  return uVar7;
}



//------------------------------------------------------------
// DATARMNET2a9f67714f @ 00114114 size=168
// signature: undefined DATARMNET2a9f67714f(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET2a9f67714f(undefined8 param_1,long param_2)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  uint *puVar4;
  undefined8 *puVar5;
  
  DATARMNET6bf538fa23();
  if (DATARMNET19c47a9f3a != 0) {
    puVar5 = *(undefined8 **)(param_2 + 0xd8);
    puVar4 = (uint *)(puVar5 + 1);
    if (*puVar4 < 2) {
      free_pages(*puVar5,0);
      kfree(puVar5);
      DATARMNET19c47a9f3a = 0;
      *(undefined8 *)(param_2 + 0xd8) = 0;
    }
    else {
      Hint_Prefetch(puVar4,2,0,1);
      do {
        uVar1 = *puVar4;
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar4,0x10);
        if (bVar3) {
          *puVar4 = uVar1 - 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      if ((int)uVar1 < 2) {
        refcount_warn_saturate(puVar4,4);
      }
    }
  }
  DATARMNETaea4c85748();
  return 0;
}



//------------------------------------------------------------
// DATARMNETc55748448d @ 001141d0 size=128
// signature: undefined DATARMNETc55748448d(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETc55748448d(long param_1,long param_2)

{
  int iVar1;
  
  *(undefined ***)(param_2 + 0x78) = &DATARMNETe9c0626068;
  iVar1 = *(int *)(*(long *)(param_2 + 0x10) + 0xb0);
  if (*(int *)(param_2 + 0x28) != iVar1) {
    down_write(*(undefined8 *)(param_2 + 0x30));
    *(int *)(param_2 + 0x28) = iVar1;
    up_write(*(undefined8 *)(param_2 + 0x30));
  }
  *(ulong *)(param_2 + 0x20) = *(ulong *)(param_2 + 0x20) | 0x4040000;
  *(undefined8 *)(param_2 + 0x90) = *(undefined8 *)(param_1 + 0xd8);
  return 0;
}



//------------------------------------------------------------
// DATARMNETd005aa7157 @ 00114254 size=168
// signature: undefined DATARMNETd005aa7157(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETd005aa7157(long *param_1)

{
  int *piVar1;
  long lVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  
  DATARMNET6bf538fa23();
  if ((DATARMNET19c47a9f3a == 0) || (**(long **)(*param_1 + 0x90) == 0)) {
    uVar7 = 0x40;
  }
  else {
    lVar5 = (((**(long **)(*param_1 + 0x90) << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40;
    lVar2 = lVar5 + -0x200000000;
    uVar6 = *(ulong *)(lVar5 + -0x1fffffff8);
    lVar5 = lVar2;
    if ((uVar6 & 1) != 0) {
      lVar5 = uVar6 - 1;
    }
    piVar1 = (int *)(lVar5 + 0x34);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = *piVar1 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    uVar7 = 0;
    param_1[10] = lVar2;
  }
  DATARMNETaea4c85748();
  return uVar7;
}



//------------------------------------------------------------
// DATARMNETfbd34e70a2 @ 0011430c size=228
// signature: undefined DATARMNETfbd34e70a2(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNETfbd34e70a2(undefined8 param_1,long param_2)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  long *plVar5;
  long lVar6;
  undefined8 uVar7;
  
  DATARMNET6bf538fa23();
  if (DATARMNET22e796eff3 == (long *)0x0) {
    plVar5 = (long *)kmalloc_trace(___rcu_read_lock,0xb20,0x10);
    if (plVar5 == (long *)0x0) {
      uVar7 = 0xfffffff4;
      goto LAB_00114360;
    }
    lVar6 = get_zeroed_page(0xa20);
    *plVar5 = lVar6;
    if (lVar6 == 0) {
      kfree(plVar5);
      uVar7 = 0xfffffff4;
      goto LAB_00114360;
    }
    DATARMNET22e796eff3 = plVar5;
    *(undefined4 *)(plVar5 + 1) = 1;
  }
  else {
    puVar1 = (uint *)(DATARMNET22e796eff3 + 1);
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
      uVar7 = 2;
    }
    else {
      if (-1 < (int)(uVar2 + 1 | uVar2)) goto LAB_00114354;
      uVar7 = 1;
    }
    refcount_warn_saturate(puVar1,uVar7);
  }
LAB_00114354:
  uVar7 = 0;
  *(long **)(param_2 + 0xd8) = DATARMNET22e796eff3;
LAB_00114360:
  DATARMNETaea4c85748();
  return uVar7;
}



//------------------------------------------------------------
// DATARMNET968bc5b80d @ 00114400 size=168
// signature: undefined DATARMNET968bc5b80d(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET968bc5b80d(undefined8 param_1,long param_2)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  uint *puVar4;
  undefined8 *puVar5;
  
  DATARMNET6bf538fa23();
  if (DATARMNET22e796eff3 != 0) {
    puVar5 = *(undefined8 **)(param_2 + 0xd8);
    puVar4 = (uint *)(puVar5 + 1);
    if (*puVar4 < 2) {
      free_pages(*puVar5,0);
      kfree(puVar5);
      DATARMNET22e796eff3 = 0;
      *(undefined8 *)(param_2 + 0xd8) = 0;
    }
    else {
      Hint_Prefetch(puVar4,2,0,1);
      do {
        uVar1 = *puVar4;
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar4,0x10);
        if (bVar3) {
          *puVar4 = uVar1 - 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      if ((int)uVar1 < 2) {
        refcount_warn_saturate(puVar4,4);
      }
    }
  }
  DATARMNETaea4c85748();
  return 0;
}



//------------------------------------------------------------
// DATARMNET43c6d751a2 @ 001144bc size=128
// signature: undefined DATARMNET43c6d751a2(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET43c6d751a2(long param_1,long param_2)

{
  int iVar1;
  
  *(undefined ***)(param_2 + 0x78) = &DATARMNET9a89317a86;
  iVar1 = *(int *)(*(long *)(param_2 + 0x10) + 0xb0);
  if (*(int *)(param_2 + 0x28) != iVar1) {
    down_write(*(undefined8 *)(param_2 + 0x30));
    *(int *)(param_2 + 0x28) = iVar1;
    up_write(*(undefined8 *)(param_2 + 0x30));
  }
  *(ulong *)(param_2 + 0x20) = *(ulong *)(param_2 + 0x20) | 0x4040000;
  *(undefined8 *)(param_2 + 0x90) = *(undefined8 *)(param_1 + 0xd8);
  return 0;
}



//------------------------------------------------------------
// DATARMNETb3a7180954 @ 00114540 size=168
// signature: undefined DATARMNETb3a7180954(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETb3a7180954(long *param_1)

{
  int *piVar1;
  long lVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  
  DATARMNET6bf538fa23();
  if ((DATARMNET22e796eff3 == 0) || (**(long **)(*param_1 + 0x90) == 0)) {
    uVar7 = 0x40;
  }
  else {
    lVar5 = (((**(long **)(*param_1 + 0x90) << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40;
    lVar2 = lVar5 + -0x200000000;
    uVar6 = *(ulong *)(lVar5 + -0x1fffffff8);
    lVar5 = lVar2;
    if ((uVar6 & 1) != 0) {
      lVar5 = uVar6 - 1;
    }
    piVar1 = (int *)(lVar5 + 0x34);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = *piVar1 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    uVar7 = 0;
    param_1[10] = lVar2;
  }
  DATARMNETaea4c85748();
  return uVar7;
}



//------------------------------------------------------------
// DATARMNET57bcb932f3 @ 001145f8 size=228
// signature: undefined DATARMNET57bcb932f3(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNET57bcb932f3(undefined8 param_1,long param_2)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  long *plVar5;
  long lVar6;
  undefined8 uVar7;
  
  DATARMNET6bf538fa23();
  if (DATARMNET9b8000d2a7 == (long *)0x0) {
    plVar5 = (long *)kmalloc_trace(___rcu_read_lock,0xb20,0x10);
    if (plVar5 == (long *)0x0) {
      uVar7 = 0xfffffff4;
      goto LAB_0011464c;
    }
    lVar6 = get_zeroed_page(0xa20);
    *plVar5 = lVar6;
    if (lVar6 == 0) {
      kfree(plVar5);
      uVar7 = 0xfffffff4;
      goto LAB_0011464c;
    }
    DATARMNET9b8000d2a7 = plVar5;
    *(undefined4 *)(plVar5 + 1) = 1;
  }
  else {
    puVar1 = (uint *)(DATARMNET9b8000d2a7 + 1);
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
      uVar7 = 2;
    }
    else {
      if (-1 < (int)(uVar2 + 1 | uVar2)) goto LAB_00114640;
      uVar7 = 1;
    }
    refcount_warn_saturate(puVar1,uVar7);
  }
LAB_00114640:
  uVar7 = 0;
  *(long **)(param_2 + 0xd8) = DATARMNET9b8000d2a7;
LAB_0011464c:
  DATARMNETaea4c85748();
  return uVar7;
}



//------------------------------------------------------------
// DATARMNET59b415aded @ 001146ec size=168
// signature: undefined DATARMNET59b415aded(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET59b415aded(undefined8 param_1,long param_2)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  uint *puVar4;
  undefined8 *puVar5;
  
  DATARMNET6bf538fa23();
  if (DATARMNET9b8000d2a7 != 0) {
    puVar5 = *(undefined8 **)(param_2 + 0xd8);
    puVar4 = (uint *)(puVar5 + 1);
    if (*puVar4 < 2) {
      free_pages(*puVar5,0);
      kfree(puVar5);
      DATARMNET9b8000d2a7 = 0;
      *(undefined8 *)(param_2 + 0xd8) = 0;
    }
    else {
      Hint_Prefetch(puVar4,2,0,1);
      do {
        uVar1 = *puVar4;
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar4,0x10);
        if (bVar3) {
          *puVar4 = uVar1 - 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      if ((int)uVar1 < 2) {
        refcount_warn_saturate(puVar4,4);
      }
    }
  }
  DATARMNETaea4c85748();
  return 0;
}



//------------------------------------------------------------
// DATARMNET7cc042bdf3 @ 001147a8 size=128
// signature: undefined DATARMNET7cc042bdf3(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET7cc042bdf3(long param_1,long param_2)

{
  int iVar1;
  
  *(undefined ***)(param_2 + 0x78) = &DATARMNET5462c2ce60;
  iVar1 = *(int *)(*(long *)(param_2 + 0x10) + 0xb0);
  if (*(int *)(param_2 + 0x28) != iVar1) {
    down_write(*(undefined8 *)(param_2 + 0x30));
    *(int *)(param_2 + 0x28) = iVar1;
    up_write(*(undefined8 *)(param_2 + 0x30));
  }
  *(ulong *)(param_2 + 0x20) = *(ulong *)(param_2 + 0x20) | 0x4040000;
  *(undefined8 *)(param_2 + 0x90) = *(undefined8 *)(param_1 + 0xd8);
  return 0;
}



//------------------------------------------------------------
// DATARMNETe35719979c @ 0011482c size=168
// signature: undefined DATARMNETe35719979c(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETe35719979c(long *param_1)

{
  int *piVar1;
  long lVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  
  DATARMNET6bf538fa23();
  if ((DATARMNET9b8000d2a7 == 0) || (**(long **)(*param_1 + 0x90) == 0)) {
    uVar7 = 0x40;
  }
  else {
    lVar5 = (((**(long **)(*param_1 + 0x90) << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40;
    lVar2 = lVar5 + -0x200000000;
    uVar6 = *(ulong *)(lVar5 + -0x1fffffff8);
    lVar5 = lVar2;
    if ((uVar6 & 1) != 0) {
      lVar5 = uVar6 - 1;
    }
    piVar1 = (int *)(lVar5 + 0x34);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = *piVar1 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    uVar7 = 0;
    param_1[10] = lVar2;
  }
  DATARMNETaea4c85748();
  return uVar7;
}



//------------------------------------------------------------
// DATARMNET601894f27b @ 001148e4 size=228
// signature: undefined DATARMNET601894f27b(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNET601894f27b(undefined8 param_1,long param_2)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  long *plVar5;
  long lVar6;
  undefined8 uVar7;
  
  DATARMNET6bf538fa23();
  if (DATARMNET835a28686c == (long *)0x0) {
    plVar5 = (long *)kmalloc_trace(___rcu_read_lock,0xb20,0x10);
    if (plVar5 == (long *)0x0) {
      uVar7 = 0xfffffff4;
      goto LAB_00114938;
    }
    lVar6 = get_zeroed_page(0xa20);
    *plVar5 = lVar6;
    if (lVar6 == 0) {
      kfree(plVar5);
      uVar7 = 0xfffffff4;
      goto LAB_00114938;
    }
    DATARMNET835a28686c = plVar5;
    *(undefined4 *)(plVar5 + 1) = 1;
  }
  else {
    puVar1 = (uint *)(DATARMNET835a28686c + 1);
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
      uVar7 = 2;
    }
    else {
      if (-1 < (int)(uVar2 + 1 | uVar2)) goto LAB_0011492c;
      uVar7 = 1;
    }
    refcount_warn_saturate(puVar1,uVar7);
  }
LAB_0011492c:
  uVar7 = 0;
  *(long **)(param_2 + 0xd8) = DATARMNET835a28686c;
LAB_00114938:
  DATARMNETaea4c85748();
  return uVar7;
}



//------------------------------------------------------------
// DATARMNET794d7587bd @ 001149d8 size=168
// signature: undefined DATARMNET794d7587bd(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET794d7587bd(undefined8 param_1,long param_2)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  uint *puVar4;
  undefined8 *puVar5;
  
  DATARMNET6bf538fa23();
  if (DATARMNET835a28686c != 0) {
    puVar5 = *(undefined8 **)(param_2 + 0xd8);
    puVar4 = (uint *)(puVar5 + 1);
    if (*puVar4 < 2) {
      free_pages(*puVar5,0);
      kfree(puVar5);
      DATARMNET835a28686c = 0;
      *(undefined8 *)(param_2 + 0xd8) = 0;
    }
    else {
      Hint_Prefetch(puVar4,2,0,1);
      do {
        uVar1 = *puVar4;
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar4,0x10);
        if (bVar3) {
          *puVar4 = uVar1 - 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      if ((int)uVar1 < 2) {
        refcount_warn_saturate(puVar4,4);
      }
    }
  }
  DATARMNETaea4c85748();
  return 0;
}



//------------------------------------------------------------
// DATARMNET150e284e90 @ 00114a94 size=128
// signature: undefined DATARMNET150e284e90(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET150e284e90(long param_1,long param_2)

{
  int iVar1;
  
  *(undefined ***)(param_2 + 0x78) = &DATARMNET523167fa26;
  iVar1 = *(int *)(*(long *)(param_2 + 0x10) + 0xb0);
  if (*(int *)(param_2 + 0x28) != iVar1) {
    down_write(*(undefined8 *)(param_2 + 0x30));
    *(int *)(param_2 + 0x28) = iVar1;
    up_write(*(undefined8 *)(param_2 + 0x30));
  }
  *(ulong *)(param_2 + 0x20) = *(ulong *)(param_2 + 0x20) | 0x4040000;
  *(undefined8 *)(param_2 + 0x90) = *(undefined8 *)(param_1 + 0xd8);
  return 0;
}



//------------------------------------------------------------
// DATARMNET1ab1f570f2 @ 00114b18 size=168
// signature: undefined DATARMNET1ab1f570f2(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET1ab1f570f2(long *param_1)

{
  int *piVar1;
  long lVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  
  DATARMNET6bf538fa23();
  if ((DATARMNET835a28686c == 0) || (**(long **)(*param_1 + 0x90) == 0)) {
    uVar7 = 0x40;
  }
  else {
    lVar5 = (((**(long **)(*param_1 + 0x90) << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40;
    lVar2 = lVar5 + -0x200000000;
    uVar6 = *(ulong *)(lVar5 + -0x1fffffff8);
    lVar5 = lVar2;
    if ((uVar6 & 1) != 0) {
      lVar5 = uVar6 - 1;
    }
    piVar1 = (int *)(lVar5 + 0x34);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = *piVar1 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    uVar7 = 0;
    param_1[10] = lVar2;
  }
  DATARMNETaea4c85748();
  return uVar7;
}



//------------------------------------------------------------
// DATARMNETb9d10d8cc0 @ 00114bd0 size=228
// signature: undefined DATARMNETb9d10d8cc0(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNETb9d10d8cc0(undefined8 param_1,long param_2)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  long *plVar5;
  long lVar6;
  undefined8 uVar7;
  
  DATARMNET6bf538fa23();
  if (DATARMNET67d31dc40a == (long *)0x0) {
    plVar5 = (long *)kmalloc_trace(___rcu_read_lock,0xb20,0x10);
    if (plVar5 == (long *)0x0) {
      uVar7 = 0xfffffff4;
      goto LAB_00114c24;
    }
    lVar6 = get_zeroed_page(0xa20);
    *plVar5 = lVar6;
    if (lVar6 == 0) {
      kfree(plVar5);
      uVar7 = 0xfffffff4;
      goto LAB_00114c24;
    }
    DATARMNET67d31dc40a = plVar5;
    *(undefined4 *)(plVar5 + 1) = 1;
  }
  else {
    puVar1 = (uint *)(DATARMNET67d31dc40a + 1);
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
      uVar7 = 2;
    }
    else {
      if (-1 < (int)(uVar2 + 1 | uVar2)) goto LAB_00114c18;
      uVar7 = 1;
    }
    refcount_warn_saturate(puVar1,uVar7);
  }
LAB_00114c18:
  uVar7 = 0;
  *(long **)(param_2 + 0xd8) = DATARMNET67d31dc40a;
LAB_00114c24:
  DATARMNETaea4c85748();
  return uVar7;
}



//------------------------------------------------------------
// DATARMNET18464ea5e3 @ 00114cc4 size=168
// signature: undefined DATARMNET18464ea5e3(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET18464ea5e3(undefined8 param_1,long param_2)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  uint *puVar4;
  undefined8 *puVar5;
  
  DATARMNET6bf538fa23();
  if (DATARMNET67d31dc40a != 0) {
    puVar5 = *(undefined8 **)(param_2 + 0xd8);
    puVar4 = (uint *)(puVar5 + 1);
    if (*puVar4 < 2) {
      free_pages(*puVar5,0);
      kfree(puVar5);
      DATARMNET67d31dc40a = 0;
      *(undefined8 *)(param_2 + 0xd8) = 0;
    }
    else {
      Hint_Prefetch(puVar4,2,0,1);
      do {
        uVar1 = *puVar4;
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar4,0x10);
        if (bVar3) {
          *puVar4 = uVar1 - 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      if ((int)uVar1 < 2) {
        refcount_warn_saturate(puVar4,4);
      }
    }
  }
  DATARMNETaea4c85748();
  return 0;
}



//------------------------------------------------------------
// DATARMNET444e2eb654 @ 00114d80 size=128
// signature: undefined DATARMNET444e2eb654(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET444e2eb654(long param_1,long param_2)

{
  int iVar1;
  
  *(undefined ***)(param_2 + 0x78) = &DATARMNET41944cc550;
  iVar1 = *(int *)(*(long *)(param_2 + 0x10) + 0xb0);
  if (*(int *)(param_2 + 0x28) != iVar1) {
    down_write(*(undefined8 *)(param_2 + 0x30));
    *(int *)(param_2 + 0x28) = iVar1;
    up_write(*(undefined8 *)(param_2 + 0x30));
  }
  *(ulong *)(param_2 + 0x20) = *(ulong *)(param_2 + 0x20) | 0x4040000;
  *(undefined8 *)(param_2 + 0x90) = *(undefined8 *)(param_1 + 0xd8);
  return 0;
}



//------------------------------------------------------------
// DATARMNETe421c4e1db @ 00114e04 size=168
// signature: undefined DATARMNETe421c4e1db(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETe421c4e1db(long *param_1)

{
  int *piVar1;
  long lVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  
  DATARMNET6bf538fa23();
  if ((DATARMNET67d31dc40a == 0) || (**(long **)(*param_1 + 0x90) == 0)) {
    uVar7 = 0x40;
  }
  else {
    lVar5 = (((**(long **)(*param_1 + 0x90) << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40;
    lVar2 = lVar5 + -0x200000000;
    uVar6 = *(ulong *)(lVar5 + -0x1fffffff8);
    lVar5 = lVar2;
    if ((uVar6 & 1) != 0) {
      lVar5 = uVar6 - 1;
    }
    piVar1 = (int *)(lVar5 + 0x34);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = *piVar1 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    uVar7 = 0;
    param_1[10] = lVar2;
  }
  DATARMNETaea4c85748();
  return uVar7;
}



//------------------------------------------------------------
// init_module @ 001155b4 size=88
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  _printk(&DAT_00115300,"DATARMNET163e93649e",DATARMNETbc8418e817);
  DATARMNET0dbc627e8f();
  register_netdevice_notifier(&DATARMNET5fc54f7a13);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00115698 size=80
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  unregister_netdevice_notifier(&DATARMNET5fc54f7a13);
  DATARMNETeabd69d1ab();
  _printk(&DAT_00114ed1,"DATARMNETf3298dab6f");
  return;
}



//------------------------------------------------------------
// __list_add_valid @ 00126008 size=1
// signature: undefined __list_add_valid(void)
// callers: [DATARMNET4095253347, DATARMNET3e37ad2816, DATARMNET24e4475345, DATARMNET36e5e526fa, DATARMNET28a80d526e, DATARMNETc6439e3d71, DATARMNET312b06829d, DATARMNETe102b3a798, DATARMNETd8a6375e9c, DATARMNET9914e9761e, DATARMNET6f4b0915d3]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule_notrace @ 00126028 size=1
// signature: undefined preempt_schedule_notrace(void)
// callers: [DATARMNET82e88dbb56]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule_notrace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00126030 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [DATARMNETb4a6870b3b, DATARMNETde8ee16f92, DATARMNETcc489fbbad, DATARMNET2fe780019f, DATARMNETf7730d41c1, DATARMNETe102b3a798, DATARMNET3af54cd726, DATARMNETf7d317ed55, DATARMNET9914e9761e, DATARMNETa1b141715b, DATARMNETb177316a15]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_bh @ 00126038 size=1
// signature: undefined _raw_spin_lock_bh(void)
// callers: [DATARMNETb4a6870b3b, DATARMNET39391a8bc5, DATARMNETeacad8334e, DATARMNET5f72606f6f, DATARMNETb062995420, DATARMNETdfb8ee742f, DATARMNETa4bf9fbf64, DATARMNET756778f14f, DATARMNETfbc06e60f1, DATARMNETd52d50282d, DATARMNETf85599b9d8, DATARMNET7ed4cef8a3, DATARMNETd6ee05f1b4, DATARMNET6bf538fa23, DATARMNETe377e0368d, DATARMNET98b2a0ce62, DATARMNETf181a18009, DATARMNETe24386452c, DATARMNETf5821256ad, DATARMNET2fe780019f, DATARMNET36e5e526fa, DATARMNET613a81eca8, DATARMNETd8a6375e9c, DATARMNET9914e9761e, DATARMNET2ac305d296, DATARMNET7492293980, DATARMNET90fe3a4b56, DATARMNETb4b5fc9686]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_bh @ 00126040 size=1
// signature: undefined _raw_spin_unlock_bh(void)
// callers: [DATARMNETb4a6870b3b, DATARMNET39391a8bc5, DATARMNETeacad8334e, DATARMNET5f72606f6f, DATARMNETb062995420, DATARMNETdfb8ee742f, DATARMNETa4bf9fbf64, DATARMNET756778f14f, DATARMNETfbc06e60f1, DATARMNETaea4c85748, DATARMNETd52d50282d, DATARMNETf85599b9d8, DATARMNET7ed4cef8a3, DATARMNETd6ee05f1b4, DATARMNETe377e0368d, DATARMNET98b2a0ce62, DATARMNETf181a18009, DATARMNETe24386452c, DATARMNETf5821256ad, DATARMNET2fe780019f, DATARMNET36e5e526fa, DATARMNET613a81eca8, DATARMNETd8a6375e9c, DATARMNET9914e9761e, DATARMNET2ac305d296, DATARMNET7492293980, DATARMNET90fe3a4b56, DATARMNETb4b5fc9686]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00126048 size=1
// signature: undefined _printk(void)
// callers: [DATARMNET45d8cdb224, DATARMNET7ed4cef8a3, cleanup_module, DATARMNETe46c480d71, DATARMNETe488c1c396, DATARMNETe69c918dc8, DATARMNETe6e8431304, DATARMNET1e918c8e0d, init_module, DATARMNETe9173bbe0e]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_copy_bits @ 00126078 size=1
// signature: undefined skb_copy_bits(void)
// callers: [skb_header_pointer, DATARMNETefcaf5fbe9, DATARMNET44459105b4, skb_header_pointer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_copy_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipv6_skip_exthdr @ 00126080 size=1
// signature: undefined ipv6_skip_exthdr(void)
// callers: [DATARMNET44459105b4, DATARMNET71b0abb49e]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipv6_skip_exthdr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00126088 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [DATARMNET02fc8b29a0, DATARMNETaeb508acb0, DATARMNET765b8ecfba, DATARMNET71b0abb49e, DATARMNETe377e0368d, DATARMNET8d0d510d45, DATARMNETf4aefff4c2, DATARMNETa9a7fa898c, DATARMNET29175fb5fc, DATARMNET5945236cd3, DATARMNETb9e0ebf153, DATARMNET713da9913c, DATARMNETe24386452c, DATARMNETc2b0dbbb32, DATARMNETd81d2866ba, DATARMNET756778f14f, DATARMNETcd6e26f0ad, DATARMNET1d4b1eff85, DATARMNET44459105b4, DATARMNET5d4ca1da1c, DATARMNET9303cec796, DATARMNET9bbfc822c2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_netdevice_notifier @ 00126090 size=1
// signature: undefined register_netdevice_notifier(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_netdevice_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_netdevice_notifier @ 00126098 size=1
// signature: undefined unregister_netdevice_notifier(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_netdevice_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncmp @ 001260a0 size=1
// signature: int strncmp(char * __s1, char * __s2, size_t __n)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_map_dl_ind_register @ 001260a8 size=1
// signature: undefined rmnet_map_dl_ind_register(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_map_dl_ind_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_map_pb_ind_register @ 001260b0 size=1
// signature: undefined rmnet_map_pb_ind_register(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_map_pb_ind_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_rmnet_ps_ind_register @ 001260b8 size=1
// signature: undefined qmi_rmnet_ps_ind_register(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_rmnet_ps_ind_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_module_hook_register @ 001260c0 size=1
// signature: undefined rmnet_module_hook_register(void)
// callers: [DATARMNET8f9da46b14, DATARMNET7520667b38, DATARMNETe9173bbe0e]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_module_hook_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 001260d0 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_get_port @ 001260d8 size=1
// signature: undefined rmnet_get_port(void)
// callers: [DATARMNET45d8cdb224, DATARMNETe9173bbe0e]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_get_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_module_hook_unregister_no_sync @ 001260e0 size=1
// signature: undefined rmnet_module_hook_unregister_no_sync(void)
// callers: [DATARMNET203752febd, DATARMNETa871eeb7e7, DATARMNET756778f14f, DATARMNETfbc06e60f1, DATARMNETe377e0368d, DATARMNETe9173bbe0e]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_module_hook_unregister_no_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_rmnet_ps_ind_deregister @ 001260e8 size=1
// signature: undefined qmi_rmnet_ps_ind_deregister(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_rmnet_ps_ind_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_map_dl_ind_deregister @ 001260f0 size=1
// signature: undefined rmnet_map_dl_ind_deregister(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_map_dl_ind_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_map_pb_ind_deregister @ 001260f8 size=1
// signature: undefined rmnet_map_pb_ind_deregister(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_map_pb_ind_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_unregister @ 00126100 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [DATARMNETe9173bbe0e]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 00126108 size=1
// signature: undefined __wake_up(void)
// callers: [DATARMNET3e88a91b63]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 00126138 size=1
// signature: undefined _find_next_bit(void)
// callers: [DATARMNETaeb508acb0, DATARMNETdf74db7e38, DATARMNET2aa4ef6ff9, DATARMNETb90d2272b4, DATARMNET371703c28d, DATARMNET82d7f4ffa2, DATARMNET202a68d7d0, DATARMNETe6e8431304, DATARMNET5a406b068f, DATARMNETf20806b279, DATARMNETfb7007f025]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00126150 size=1
// signature: undefined queue_work_on(void)
// callers: [DATARMNET0a73c53ae6, DATARMNET371703c28d, DATARMNET4ce9744605, DATARMNET202a68d7d0, DATARMNETf20806b279, DATARMNETfb7007f025]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_percpu @ 00126168 size=1
// signature: undefined __alloc_percpu(void)
// callers: [DATARMNETe6e8431304]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_percpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00126170 size=1
// signature: undefined alloc_workqueue(void)
// callers: [DATARMNET3ae0d614d6, DATARMNETe6e8431304]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpufreq_cpu_get @ 00126178 size=1
// signature: undefined cpufreq_cpu_get(void)
// callers: [DATARMNETe6e8431304]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpufreq_cpu_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// freq_qos_add_request @ 00126180 size=1
// signature: undefined freq_qos_add_request(void)
// callers: [DATARMNETe6e8431304]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void freq_qos_add_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_percpu @ 00126188 size=1
// signature: undefined free_percpu(void)
// callers: [DATARMNETdf74db7e38, DATARMNETe6e8431304]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_percpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 00126190 size=1
// signature: undefined destroy_workqueue(void)
// callers: [DATARMNETf7dcab9a9e, DATARMNETdf74db7e38, DATARMNETe6e8431304]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpus_read_lock @ 00126198 size=1
// signature: undefined cpus_read_lock(void)
// callers: [DATARMNETb90d2272b4, DATARMNET5a406b068f]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpus_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// freq_qos_update_request @ 001261a0 size=1
// signature: undefined freq_qos_update_request(void)
// callers: [DATARMNETb90d2272b4, DATARMNET5a406b068f]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void freq_qos_update_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpus_read_unlock @ 001261a8 size=1
// signature: undefined cpus_read_unlock(void)
// callers: [DATARMNETb90d2272b4, DATARMNET5a406b068f]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpus_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// freq_qos_remove_request @ 001261b0 size=1
// signature: undefined freq_qos_remove_request(void)
// callers: [DATARMNETdf74db7e38]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void freq_qos_remove_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001261d8 size=1
// signature: undefined kfree(void)
// callers: [DATARMNET2a9f67714f, DATARMNET39391a8bc5, DATARMNETcc489fbbad, DATARMNET601894f27b, DATARMNET59b415aded, DATARMNETf7730d41c1, DATARMNET968bc5b80d, DATARMNET3af54cd726, DATARMNET5945236cd3, DATARMNET18464ea5e3, DATARMNETa1b141715b, DATARMNET0935e3beb9, DATARMNET756778f14f, DATARMNET57bcb932f3, DATARMNET5d4ca1da1c, DATARMNETd52d50282d, DATARMNETcfbc4f0c39, DATARMNET33a80d3bf7, DATARMNET5fb4151598, DATARMNETf7dcab9a9e, DATARMNETb5d58adbe7, DATARMNETd6ee05f1b4, DATARMNETa9a7fa898c, DATARMNETfbd34e70a2, DATARMNET794d7587bd, DATARMNETb9d10d8cc0, DATARMNET713da9913c, DATARMNET2ac305d296, DATARMNET90fe3a4b56, DATARMNETb177316a15]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __skb_get_hash @ 001261e0 size=1
// signature: undefined __skb_get_hash(void)
// callers: [DATARMNETf5821256ad, DATARMNET756778f14f]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __skb_get_hash(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001261f0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [DATARMNET3ae0d614d6, DATARMNET601894f27b, DATARMNET24e4475345, DATARMNET283f08f439, DATARMNET312b06829d, DATARMNETfbd34e70a2, DATARMNETb062995420, DATARMNETf5b8fce55d, DATARMNETb9d10d8cc0, DATARMNET0935e3beb9, DATARMNETf5821256ad, DATARMNET756778f14f, DATARMNET28a80d526e, DATARMNETc6439e3d71, DATARMNET57bcb932f3, DATARMNET7492293980, DATARMNET33a80d3bf7, DATARMNET6f4b0915d3]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_weight @ 00126208 size=1
// signature: undefined __bitmap_weight(void)
// callers: [DATARMNET713da9913c]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_weight(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00126210 size=1
// signature: undefined __kmalloc(void)
// callers: [DATARMNET713da9913c]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_lock @ 00126218 size=1
// signature: undefined __rcu_read_lock(void)
// callers: [DATARMNET39391a8bc5, DATARMNETcd6e26f0ad, DATARMNET29175fb5fc, DATARMNETedc898218c, DATARMNETb062995420, DATARMNETe074a09496, DATARMNETe69c918dc8, DATARMNET4063c95208, DATARMNET713da9913c, DATARMNETb1157fd5c4]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_unlock @ 00126220 size=1
// signature: undefined __rcu_read_unlock(void)
// callers: [DATARMNET39391a8bc5, DATARMNETcd6e26f0ad, DATARMNET29175fb5fc, DATARMNETedc898218c, DATARMNETb062995420, DATARMNETe074a09496, DATARMNETe69c918dc8, DATARMNET4063c95208, DATARMNET713da9913c, DATARMNETb1157fd5c4]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_module_hook_perf_ingress @ 00126228 size=1
// signature: undefined rmnet_module_hook_perf_ingress(void)
// callers: [DATARMNET9303cec796]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_module_hook_perf_ingress(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_with_offset @ 00126230 size=1
// signature: undefined ktime_get_with_offset(void)
// callers: [DATARMNETc2b0dbbb32, DATARMNETcd6e26f0ad, DATARMNETe377e0368d, DATARMNET9303cec796, DATARMNET350f55bfca]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_with_offset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ns_to_timespec64 @ 00126238 size=1
// signature: undefined ns_to_timespec64(void)
// callers: [DATARMNETc2b0dbbb32, DATARMNETcd6e26f0ad, DATARMNETe377e0368d, DATARMNET9303cec796, DATARMNET350f55bfca]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ns_to_timespec64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_active @ 00126240 size=1
// signature: undefined hrtimer_active(void)
// callers: [DATARMNET02fc8b29a0, DATARMNETa4bf9fbf64, DATARMNETc54e431bbc, DATARMNET4684d6c911, DATARMNET756778f14f, DATARMNET9303cec796]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_active(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_cancel @ 00126248 size=1
// signature: undefined hrtimer_cancel(void)
// callers: [DATARMNET9297340f58, DATARMNETa4bf9fbf64, DATARMNETc54e431bbc, DATARMNET4684d6c911, DATARMNET756778f14f, DATARMNET02cdd9b125, DATARMNET9303cec796]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_cancel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_start_range_ns @ 00126250 size=1
// signature: undefined hrtimer_start_range_ns(void)
// callers: [DATARMNET02fc8b29a0, DATARMNETa4bf9fbf64, DATARMNETc54e431bbc, DATARMNET4684d6c911, DATARMNET756778f14f, DATARMNET9303cec796]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_start_range_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_stay_awake @ 00126258 size=1
// signature: undefined __pm_stay_awake(void)
// callers: [DATARMNET9303cec796]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netif_receive_skb @ 00126260 size=1
// signature: undefined netif_receive_skb(void)
// callers: [DATARMNETe767554e6e, DATARMNETcba2f7f7b6]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netif_receive_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netif_rx @ 00126268 size=1
// signature: undefined netif_rx(void)
// callers: [DATARMNET23c7ddd780, DATARMNET756778f14f, DATARMNETcba2f7f7b6, DATARMNET514ce0bf59]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netif_rx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_is_real_dev_registered @ 00126270 size=1
// signature: undefined rmnet_is_real_dev_registered(void)
// callers: [DATARMNET02fc8b29a0, DATARMNET765b8ecfba, DATARMNET82e88dbb56]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_is_real_dev_registered(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __skb_gso_segment @ 00126290 size=1
// signature: undefined __skb_gso_segment(void)
// callers: [DATARMNETcba2f7f7b6]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __skb_gso_segment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// consume_skb @ 00126298 size=1
// signature: undefined consume_skb(void)
// callers: [DATARMNETeacad8334e, DATARMNETcba2f7f7b6]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void consume_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_rx_handler @ 001262a0 size=1
// signature: undefined rmnet_rx_handler(void)
// callers: [DATARMNETe377e0368d]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_rx_handler(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_forward @ 001262a8 size=1
// signature: undefined hrtimer_forward(void)
// callers: [DATARMNET0a73c53ae6]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_forward(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_relax @ 001262b8 size=1
// signature: undefined __pm_relax(void)
// callers: [DATARMNET2ba63fbd90]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_init @ 001262c0 size=1
// signature: undefined hrtimer_init(void)
// callers: [DATARMNETe1f95274f1]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 001262c8 size=1
// signature: undefined cancel_work_sync(void)
// callers: [DATARMNET02cdd9b125]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rtnl_lock @ 001262d0 size=1
// signature: undefined rtnl_lock(void)
// callers: [DATARMNET82e88dbb56]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rtnl_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_dequeue_tail @ 001262d8 size=1
// signature: undefined skb_dequeue_tail(void)
// callers: [DATARMNET82e88dbb56]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_dequeue_tail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_skb_reason @ 001262e0 size=1
// signature: undefined kfree_skb_reason(void)
// callers: [DATARMNET82e88dbb56]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_skb_reason(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netdev_core_stats_alloc @ 001262e8 size=1
// signature: undefined netdev_core_stats_alloc(void)
// callers: [DATARMNET82e88dbb56]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netdev_core_stats_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rtnl_unlock @ 001262f0 size=1
// signature: undefined rtnl_unlock(void)
// callers: [DATARMNET82e88dbb56]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rtnl_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sw_hweight64 @ 00126308 size=1
// signature: undefined __sw_hweight64(void)
// callers: [DATARMNETaeb508acb0, DATARMNETcd6e26f0ad]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sw_hweight64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_oom_notifier @ 00126310 size=1
// signature: undefined register_oom_notifier(void)
// callers: [DATARMNET45d8cdb224]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_oom_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_register @ 00126318 size=1
// signature: undefined wakeup_source_register(void)
// callers: [DATARMNET45d8cdb224]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_oom_notifier @ 00126328 size=1
// signature: undefined unregister_oom_notifier(void)
// callers: [DATARMNET9297340f58]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_oom_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_unregister @ 00126330 size=1
// signature: undefined wakeup_source_unregister(void)
// callers: [DATARMNET9297340f58]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00126338 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [DATARMNET9297340f58]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __local_bh_enable_ip @ 00126340 size=1
// signature: undefined __local_bh_enable_ip(void)
// callers: [local_bh_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __local_bh_enable_ip(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// walt_get_cpus_taken @ 00126370 size=1
// signature: undefined walt_get_cpus_taken(void)
// callers: [DATARMNETcd6e26f0ad, DATARMNET362c14e98b]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void walt_get_cpus_taken(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_module_hook_perf_set_thresh @ 00126378 size=1
// signature: undefined rmnet_module_hook_perf_set_thresh(void)
// callers: [DATARMNET1faf2b953f]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_module_hook_perf_set_thresh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// list_sort @ 00126380 size=1
// signature: undefined list_sort(void)
// callers: [DATARMNET7792d4f4ad]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void list_sort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// walt_get_cpus_in_state1 @ 00126388 size=1
// signature: undefined walt_get_cpus_in_state1(void)
// callers: [DATARMNETcd6e26f0ad]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void walt_get_cpus_in_state1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00126390 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [DATARMNETb4b5fc9686]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 00126398 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [DATARMNET7b6c061b06, DATARMNETb4b5fc9686]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 001263a0 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [DATARMNETf7dcab9a9e, DATARMNET4063c95208]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drain_workqueue @ 001263a8 size=1
// signature: undefined drain_workqueue(void)
// callers: [DATARMNETf7dcab9a9e]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drain_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 001263b8 size=1
// signature: undefined init_timer_key(void)
// callers: [DATARMNET3ae0d614d6]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_skb @ 001263c0 size=1
// signature: undefined __alloc_skb(void)
// callers: [DATARMNETb5d58adbe7, DATARMNET5d4ca1da1c, DATARMNETa9a7fa898c, DATARMNET5945236cd3]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genlmsg_put @ 001263c8 size=1
// signature: undefined genlmsg_put(void)
// callers: [DATARMNETb5d58adbe7, DATARMNET5d4ca1da1c, DATARMNETa9a7fa898c, DATARMNET5945236cd3]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genlmsg_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nla_put @ 001263d0 size=1
// signature: undefined nla_put(void)
// callers: [DATARMNETb5d58adbe7, DATARMNET5d4ca1da1c, DATARMNETa9a7fa898c, DATARMNET5945236cd3]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nla_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netlink_unicast @ 001263d8 size=1
// signature: undefined netlink_unicast(void)
// callers: [DATARMNETb5d58adbe7, DATARMNET5d4ca1da1c, DATARMNET5945236cd3]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netlink_unicast(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netlink_broadcast @ 001263e8 size=1
// signature: undefined netlink_broadcast(void)
// callers: [DATARMNETa9a7fa898c]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netlink_broadcast(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nla_memcpy @ 001263f0 size=1
// signature: undefined nla_memcpy(void)
// callers: [DATARMNETd81d2866ba, DATARMNET283f08f439, DATARMNET29175fb5fc, DATARMNET9bbfc822c2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nla_memcpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_real_ts64 @ 001263f8 size=1
// signature: undefined ktime_get_real_ts64(void)
// callers: [DATARMNET1d4b1eff85, DATARMNET8d0d510d45]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_real_ts64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genl_register_family @ 00126400 size=1
// signature: undefined genl_register_family(void)
// callers: [DATARMNET0dbc627e8f]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genl_register_family(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genl_unregister_family @ 00126408 size=1
// signature: undefined genl_unregister_family(void)
// callers: [DATARMNET0dbc627e8f, DATARMNETeabd69d1ab]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genl_unregister_family(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00126410 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [DATARMNET78f3a0ca4f, DATARMNET0e273eab79, DATARMNET78666f33a1, DATARMNETe15af8eb6d, DATARMNET5157210c44, DATARMNETa3d6c4072d]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00126418 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [DATARMNET78666f33a1]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00126420 size=1
// signature: undefined fortify_panic(void)
// callers: [DATARMNET78666f33a1]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_mkdir @ 00126428 size=1
// signature: undefined proc_mkdir(void)
// callers: [DATARMNETf5f83b943f]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_mkdir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_set_user @ 00126430 size=1
// signature: undefined proc_set_user(void)
// callers: [DATARMNETf5f83b943f]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_set_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_create @ 00126438 size=1
// signature: undefined proc_create(void)
// callers: [DATARMNETf5f83b943f]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// remove_proc_entry @ 00126440 size=1
// signature: undefined remove_proc_entry(void)
// callers: [DATARMNET28d33bd09f]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void remove_proc_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_zeroed_page @ 00126448 size=1
// signature: undefined get_zeroed_page(void)
// callers: [DATARMNET0935e3beb9, DATARMNET601894f27b, DATARMNET57bcb932f3, DATARMNETfbd34e70a2, DATARMNET33a80d3bf7, DATARMNETb9d10d8cc0]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_zeroed_page(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 00126450 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [DATARMNET0935e3beb9, DATARMNET2a9f67714f, DATARMNET601894f27b, DATARMNET59b415aded, DATARMNET968bc5b80d, DATARMNET57bcb932f3, DATARMNETcfbc4f0c39, DATARMNETfbd34e70a2, DATARMNET794d7587bd, DATARMNET33a80d3bf7, DATARMNETb9d10d8cc0, DATARMNET18464ea5e3]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_pages @ 00126458 size=1
// signature: undefined free_pages(void)
// callers: [DATARMNET2a9f67714f, DATARMNET59b415aded, DATARMNET968bc5b80d, DATARMNETcfbc4f0c39, DATARMNET794d7587bd, DATARMNET18464ea5e3]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_write @ 00126460 size=1
// signature: undefined down_write(void)
// callers: [DATARMNET150e284e90, DATARMNETc55748448d, DATARMNET54418f934d, DATARMNET444e2eb654, DATARMNET7cc042bdf3, DATARMNET43c6d751a2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_write @ 00126468 size=1
// signature: undefined up_write(void)
// callers: [DATARMNET150e284e90, DATARMNETc55748448d, DATARMNET54418f934d, DATARMNET444e2eb654, DATARMNET7cc042bdf3, DATARMNET43c6d751a2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



