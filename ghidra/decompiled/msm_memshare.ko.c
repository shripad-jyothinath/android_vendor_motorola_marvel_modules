// Decompiled by Ghidra 12.2
// Program: msm_memshare.ko
// Image base: 00100000

//------------------------------------------------------------
// memshare_alloc @ 00100384 size=112
// signature: undefined memshare_alloc(void)
// callers: [handle_alloc_generic_req, memshare_probe]
//------------------------------------------------------------

undefined4 memshare_alloc(undefined8 param_1,undefined4 param_2,long param_3)

{
  long lVar1;
  undefined4 uVar2;
  
  if (param_3 == 0) {
    _dev_err(*memsh_drv,"memshare: Failed memory block allocation\n");
    uVar2 = 0xfffffff4;
  }
  else {
    lVar1 = dma_alloc_attrs(param_1,param_2,param_3 + 0x40,0xcc0,0);
    uVar2 = 0xfffffff4;
    if (lVar1 != 0) {
      uVar2 = 0;
    }
    *(long *)(param_3 + 0x48) = lVar1;
  }
  return uVar2;
}



//------------------------------------------------------------
// memshare_probe @ 001003f8 size=1928
// signature: undefined memshare_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int memshare_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  long *plVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  char *pcVar10;
  ulong uVar11;
  undefined4 uVar12;
  char *local_a8;
  undefined8 local_a0;
  long local_98 [11];
  
  lVar9 = sp_el0;
  local_98[10] = *(long *)(lVar9 + 0x638);
  lVar9 = param_1 + 0x10;
  iVar4 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2f8),"qcom,memshare-peripheral");
  if (iVar4 == 0) {
    plVar6 = (long *)devm_kmalloc(lVar9,0x98,0xdc0);
    if (plVar6 != (long *)0x0) {
      *plVar6 = lVar9;
      memsh_drv = plVar6;
      *(long **)(param_1 + 0xa8) = plVar6;
      __mutex_init(plVar6 + 7,"&drv->mem_free",&memshare_probe___key);
      __mutex_init(plVar6 + 1,"&drv->mem_share",&memshare_probe___key_4);
      plVar6[0xd] = 0xfffffffe0;
      plVar6[0xe] = (long)(plVar6 + 0xe);
      plVar6[0xf] = (long)(plVar6 + 0xe);
      uVar7 = _system_wq;
      plVar6[0x10] = (long)memshare_init_worker;
      queue_work_on(0x20,uVar7,plVar6 + 0xd);
      lVar8 = 0;
      do {
        lVar1 = lVar8 + 0x58;
        *(undefined4 *)((long)&DAT_00102778 + lVar8) = 0;
        *(undefined8 *)((long)&DAT_00102748 + lVar8) = 0x1ffffffff;
        *(undefined8 *)((long)&DAT_00102750 + lVar8) = 0;
        *(undefined8 *)((long)&DAT_00102780 + lVar8) = 0;
        *(undefined8 *)((long)&DAT_00102788 + lVar8) = 0;
        *(undefined8 *)((long)&memblock + lVar8) = 0xffffffff000003e8;
        *(undefined2 *)((long)&DAT_00102790 + lVar8) = 0;
        lVar8 = lVar1;
      } while (lVar1 != 0x370);
      num_clients = 0;
      iVar4 = of_platform_populate(*(undefined8 *)(param_1 + 0x2f8),0,0,lVar9);
      if (iVar4 == 0) {
        qcom_register_ssr_notifier("modem",&nb);
      }
      else {
        _dev_err(*memsh_drv,"memshare: error populating the devices\n");
      }
      goto LAB_00100560;
    }
  }
  else {
    local_a8 = (char *)0x0;
    local_a0 = 0;
    plVar6 = (long *)devm_kmalloc(lVar9,0x18,0xdc0);
    if (plVar6 != (long *)0x0) {
      uVar7 = *(undefined8 *)(param_1 + 0x2f8);
      *plVar6 = lVar9;
      *(long **)(param_1 + 0xa8) = plVar6;
      iVar4 = of_property_read_variable_u32_array
                        (uVar7,"qcom,peripheral-size",(long)&local_a0 + 4,1,0);
      if (iVar4 < 0) {
        lVar9 = *plVar6;
        pcVar10 = "memshare: Error reading size of clients, rc: %d\n";
      }
      else {
        iVar4 = of_property_read_variable_u32_array
                          (*(undefined8 *)(param_1 + 0x2f8),"qcom,client-id",&local_a0,1,0);
        if (-1 < iVar4) {
          lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,allocate-boot-time",0);
          if (9 < num_clients) goto LAB_00100b7c;
          if (0x360 < (ulong)num_clients * 0x58) goto LAB_00100b74;
          *(uint *)(&DAT_00102750 + (ulong)num_clients * 0xb) = (uint)(lVar8 != 0);
          lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,allocate-on-request",0);
          if (9 < num_clients) goto LAB_00100b7c;
          if (0x354 < (ulong)num_clients * 0x58) goto LAB_00100b74;
          *(uint *)(&DAT_0010275c + (ulong)num_clients * 0x58) = (uint)(lVar8 != 0);
          lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,guard-band",0);
          if (9 < num_clients) goto LAB_00100b7c;
          if (0x350 < (ulong)num_clients * 0x58) goto LAB_00100b74;
          *(uint *)(&DAT_00102760 + (ulong)num_clients * 0x58) = (uint)(lVar8 != 0);
          lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,shared",0);
          uVar2 = num_clients;
          if (lVar8 == 0) {
            if (9 < num_clients) goto LAB_00100b7c;
            if (((0x34c < (ulong)num_clients * 0x58) ||
                (uVar11 = (ulong)num_clients,
                *(undefined4 *)(&DAT_00102764 + (ulong)num_clients * 0x58) = 1,
                0x348 < uVar11 * 0x58)) ||
               (*(undefined4 *)(&DAT_00102768 + (ulong)uVar2 * 0x58) = 0xf,
               0x340 < (ulong)uVar2 * 0x58)) goto LAB_00100b74;
            *(undefined4 *)(&DAT_00102770 + (ulong)uVar2 * 0x58) = 6;
          }
          else {
            if (9 < num_clients) goto LAB_00100b7c;
            if ((((0x34c < (ulong)num_clients * 0x58) ||
                 (uVar11 = (ulong)num_clients,
                 *(undefined4 *)(&DAT_00102764 + (ulong)num_clients * 0x58) = 2,
                 0x348 < uVar11 * 0x58)) ||
                (*(undefined4 *)(&DAT_00102768 + (ulong)uVar2 * 0x58) = 3,
                0x344 < (ulong)uVar2 * 0x58)) ||
               ((*(undefined4 *)(&DAT_0010276c + (ulong)uVar2 * 0x58) = 0xf,
                0x340 < (ulong)uVar2 * 0x58 ||
                (*(undefined4 *)(&DAT_00102770 + (ulong)uVar2 * 0x58) = 6,
                0x33c < (ulong)uVar2 * 0x58)))) goto LAB_00100b74;
            *(undefined4 *)(&DAT_00102774 + (ulong)uVar2 * 0x58) = 6;
          }
          iVar4 = of_property_read_string(*(undefined8 *)(param_1 + 0x2f8),"label",&local_a8);
          pcVar10 = local_a8;
          if (iVar4 != 0) {
            pcVar10 = "memshare: Error reading peripheral info for client, rc: %d\n";
            goto LAB_0010088c;
          }
          iVar4 = strcmp(local_a8,"modem");
          if (iVar4 == 0) {
            uVar11 = (ulong)num_clients;
            if (9 < num_clients) goto LAB_00100b7c;
            if ((0x370 < (uVar11 * 0x58 | 4)) || (0x370 < ((ulong)num_clients * 0x58 | 4)))
            goto LAB_00100b74;
            *(undefined4 *)((long)&memblock + (ulong)num_clients * 0x58 + 4) = 0;
          }
          else {
            iVar4 = strcmp(pcVar10,"adsp");
            if (iVar4 == 0) {
              uVar11 = (ulong)num_clients;
              if (9 < num_clients) goto LAB_00100b7c;
              if ((0x370 < (uVar11 * 0x58 | 4)) || (0x370 < ((ulong)num_clients * 0x58 | 4)))
              goto LAB_00100b74;
              uVar12 = 1;
            }
            else {
              iVar4 = strcmp(pcVar10,"wcnss");
              uVar11 = (ulong)num_clients;
              if (iVar4 != 0) {
                if (9 < num_clients) goto LAB_00100b7c;
                goto LAB_00100954;
              }
              if (9 < num_clients) goto LAB_00100b7c;
              if ((0x370 < (uVar11 * 0x58 | 4)) || (0x370 < ((ulong)num_clients * 0x58 | 4)))
              goto LAB_00100b74;
              uVar12 = 2;
            }
            *(undefined4 *)((long)&memblock + uVar11 * 0x58 + 4) = uVar12;
          }
LAB_00100954:
          if (((0x334 < uVar11 * 0x58) ||
              (*(int *)(&DAT_0010277c + uVar11 * 0x58) = local_a0._4_4_, 0x370 < uVar11 * 0x58)) ||
             (uVar11 == 10)) goto LAB_00100b74;
          local_98[8] = 0;
          local_98[9] = 0;
          local_98[6] = 0;
          local_98[7] = 0;
          *(undefined4 *)(&memblock + uVar11 * 0xb) = (undefined4)local_a0;
          uVar7 = *(undefined8 *)(param_1 + 0x2f8);
          *(undefined4 *)(plVar6 + 1) = (undefined4)local_a0;
          local_98[4] = 0;
          local_98[5] = 0;
          local_98[2] = 0;
          local_98[3] = 0;
          local_98[0] = 0;
          local_98[1] = 0;
          iVar4 = __of_parse_phandle_with_args(uVar7,"memory-region",0,0,0,local_98);
          pcVar10 = "memshare: Continuing with allocation from CMA\n";
          if ((iVar4 == 0) && (local_98[0] != 0)) {
            iVar4 = of_reserved_mem_device_init_by_idx(lVar9,*(undefined8 *)(param_1 + 0x2f8),0);
            if (iVar4 != 0) {
              pcVar10 = "memshare: Failed to initialize memory region rc: %d\n";
              goto LAB_00100894;
            }
            pcVar10 = "memshare: Memory allocation from shared DMA pool\n";
          }
          _dev_info(lVar9,pcVar10);
          uVar11 = (ulong)num_clients;
          if (9 < num_clients) goto LAB_00100b7c;
          if (0x360 < uVar11 * 0x58) {
LAB_00100b74:
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(1,0x100b78);
            (*pcVar3)();
          }
          if (*(int *)(&DAT_00102750 + (ulong)num_clients * 0xb) != 0) {
            if (local_a0._4_4_ != 0) {
              if (0x350 < (ulong)num_clients * 0x58) goto LAB_00100b74;
              iVar4 = local_a0._4_4_;
              if (*(int *)(&DAT_00102760 + (ulong)num_clients * 0x58) != 0) {
                iVar4 = local_a0._4_4_ + 0x1000;
                local_a0 = CONCAT44(iVar4,(undefined4)local_a0);
              }
              iVar4 = memshare_alloc(*plVar6,iVar4,&memblock + uVar11 * 0xb);
              uVar2 = num_clients;
              if (iVar4 != 0) {
                _dev_err(*memsh_drv,
                         "memshare_child: Unable to allocate memory for guaranteed clients, rc: %d\n"
                         ,iVar4);
                local_98[8] = 0;
                local_98[9] = 0;
                local_98[6] = 0;
                local_98[7] = 0;
                local_98[4] = 0;
                local_98[5] = 0;
                local_98[2] = 0;
                local_98[3] = 0;
                local_98[0] = 0;
                local_98[1] = 0;
                iVar5 = __of_parse_phandle_with_args
                                  (*(undefined8 *)(param_1 + 0x2f8),"memory-region",0,0,0,local_98);
                if ((iVar5 == 0) && (local_98[0] != 0)) {
                  of_reserved_mem_device_release(lVar9);
                }
                goto LAB_00100560;
              }
              if (9 < num_clients) {
LAB_00100b7c:
                    /* WARNING: Does not return */
                pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100b80);
                (*pcVar3)();
              }
              if ((0x338 < (ulong)num_clients * 0x58) ||
                 (uVar11 = (ulong)num_clients,
                 (&DAT_00102778)[(ulong)num_clients * 0x16] = local_a0._4_4_, 0x35c < uVar11 * 0x58)
                 ) goto LAB_00100b74;
              *(undefined4 *)((long)&DAT_00102750 + (ulong)uVar2 * 0x58 + 4) = 1;
              shared_hyp_mapping();
              uVar11 = (ulong)num_clients;
              if (9 < num_clients) goto LAB_00100b7c;
            }
          }
          if (9 < uVar11) goto LAB_00100b74;
          num_clients = (int)uVar11 + 1;
          iVar4 = 0;
          (&memsh_child)[uVar11] = plVar6;
          goto LAB_00100560;
        }
        pcVar10 = "memshare: Error reading client id, rc: %d\n";
LAB_0010088c:
        lVar9 = *memsh_drv;
      }
LAB_00100894:
      _dev_err(lVar9,pcVar10,iVar4);
      goto LAB_00100560;
    }
  }
  iVar4 = -0xc;
LAB_00100560:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_98[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// memshare_remove @ 00100b84 size=76
// signature: undefined memshare_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 memshare_remove(void)

{
  if ((memsh_drv != 0) && (mem_share_svc_handle != 0)) {
    qmi_handle_release();
    kfree(mem_share_svc_handle);
    mem_share_svc_handle = 0;
  }
  return 0;
}



//------------------------------------------------------------
// memshare_init_worker @ 00100bd4 size=200
// signature: undefined memshare_init_worker(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void memshare_init_worker(void)

{
  int iVar1;
  
  mem_share_svc_handle = kmalloc_trace(_mem_alloc_generic_resp_msg_data_v01_ei,0xdc0,0x148);
  if (mem_share_svc_handle == 0) {
    return;
  }
  iVar1 = qmi_handle_init(mem_share_svc_handle,0x20,server_ops,qmi_memshare_handlers);
  if (iVar1 < 0) {
    _dev_err(*memsh_drv,"memshare: Creating mem_share_svc qmi handle failed\n");
  }
  else {
    iVar1 = qmi_add_server(mem_share_svc_handle,0x34,1,1);
    if (-1 < iVar1) {
      return;
    }
    _dev_err(*memsh_drv,"memshare: Registering mem share svc failed %d\n",iVar1);
    if (mem_share_svc_handle == 0) {
      return;
    }
    qmi_handle_release();
  }
  kfree(mem_share_svc_handle);
  mem_share_svc_handle = 0;
  return;
}



//------------------------------------------------------------
// shared_hyp_mapping @ 00100c9c size=556
// signature: undefined shared_hyp_mapping(void)
// callers: [handle_alloc_generic_req, memshare_probe]
//------------------------------------------------------------

void shared_hyp_mapping(uint param_1)

{
  uint *puVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  ulong uVar7;
  undefined8 local_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_50 = 8;
  if (9 < (int)param_1) {
    _dev_err(*memsh_drv,"memshare: hypervisor mapping failure for invalid client\n");
    goto LAB_00100e48;
  }
  if (10 < param_1) {
LAB_00100dcc:
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100dd0);
    (*pcVar3)();
  }
  uVar7 = (ulong)param_1 * 0x58;
  if (uVar7 < 0x34d) {
    puVar1 = (uint *)(&DAT_00102764 + (ulong)param_1 * 0x58);
    puVar5 = (undefined4 *)__kmalloc((ulong)*puVar1 << 3,0xdc0);
    if (puVar5 == (undefined4 *)0x0) goto LAB_00100e48;
    if (uVar7 < 0x34d) {
      if (*puVar1 == 0) {
        uVar6 = 0;
      }
      else {
        if (((0x348 < (ulong)param_1 * 0x58) ||
            (*puVar5 = *(undefined4 *)(&DAT_00102768 + (ulong)param_1 * 0x58),
            0x340 < (ulong)param_1 * 0x58)) ||
           (puVar5[1] = *(undefined4 *)(&DAT_00102770 + (ulong)param_1 * 0x58), 0x34c < uVar7))
        goto LAB_00100ec0;
        uVar6 = *puVar1;
        if (1 < uVar6) {
          if (((0x344 < (ulong)param_1 * 0x58) ||
              (puVar5[2] = *(undefined4 *)(&DAT_0010276c + (ulong)param_1 * 0x58),
              0x33c < (ulong)param_1 * 0x58)) ||
             (puVar5[3] = *(undefined4 *)(&DAT_00102774 + (ulong)param_1 * 0x58), 0x34c < uVar7))
          goto LAB_00100ec0;
          uVar6 = *puVar1;
          if (2 < uVar6) goto LAB_00100dcc;
        }
      }
      if (((ulong)param_1 * 0x58 < 0x331) && ((ulong)param_1 * 0x58 < 0x339)) {
        iVar4 = qcom_scm_assign_mem((&DAT_00102780)[(ulong)param_1 * 0xb],
                                    (&DAT_00102778)[(ulong)param_1 * 0x16],&local_50,puVar5,uVar6);
        kfree(puVar5);
        if (iVar4 == 0) {
          if (799 < (ulong)param_1 * 0x58) goto LAB_00100ec0;
          *(undefined1 *)((long)&DAT_00102790 + (ulong)param_1 * 0x58 + 1) = 1;
        }
        else {
          if (0x338 < (ulong)param_1 * 0x58) goto LAB_00100ec0;
          _dev_err(*memsh_drv,"memshare: qcom_scm_assign_mem failed size: %u, err: %d\n",
                   (&DAT_00102778)[(ulong)param_1 * 0x16],iVar4);
        }
LAB_00100e48:
        lVar2 = sp_el0;
        if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return;
      }
    }
  }
LAB_00100ec0:
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(1,0x100ec4);
  (*pcVar3)();
}



//------------------------------------------------------------
// mem_share_svc_disconnect_cb @ 00100ecc size=4
// signature: undefined mem_share_svc_disconnect_cb(void)
// callers: []
//------------------------------------------------------------

void mem_share_svc_disconnect_cb(void)

{
  return;
}



//------------------------------------------------------------
// handle_alloc_generic_req @ 00100ed4 size=1392
// signature: undefined handle_alloc_generic_req(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void handle_alloc_generic_req
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,uint *param_4)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong uVar11;
  undefined8 *puVar12;
  ulong uVar13;
  undefined4 local_6c;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  local_6c = 0;
  mutex_lock(memsh_drv + 1);
  _dev_info(*memsh_drv,
            "memshare_alloc: memory alloc request received for client id: %d, proc_id: %d, request size: %d\n"
            ,param_4[1],param_4[2],*param_4);
  puVar8 = (undefined4 *)kmalloc_trace(_qcom_glink_mem_entry_free,0xdc0,0x418);
  if (puVar8 != (undefined4 *)0x0) {
    uVar6 = param_4[1];
    uVar2 = param_4[2];
    *puVar8 = 0x20001;
    uVar6 = check_client(uVar6,uVar2,0);
    uVar10 = (ulong)uVar6;
    if ((int)uVar6 < 10) {
      if (num_clients != 0) {
        uVar2 = param_4[1];
        puVar12 = memsh_child;
        if (*(uint *)(memsh_child + 1) == uVar2) {
LAB_00101104:
          _dev_info(*memsh_drv,"memshare_alloc: found client with client_id: %d, index: %d\n",uVar2,
                    uVar10);
          if (puVar12 != (undefined8 *)0x0) {
            if (9 < uVar6) {
LAB_00101440:
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x101444);
              (*pcVar5)();
            }
            uVar11 = uVar10 * 0x58;
            if (0x35c < uVar11) goto LAB_00101434;
            uVar13 = (ulong)uVar6;
            piVar1 = (int *)((long)&DAT_00102750 + (ulong)uVar6 * 0x58 + 4);
            if ((*piVar1 == 0) && (uVar2 = *param_4, uVar2 != 0)) {
              if (0x334 < uVar13 * 0x58) goto LAB_00101434;
              uVar3 = *(uint *)(&DAT_0010277c + uVar13 * 0x58);
              if (uVar3 < uVar2) {
                *param_4 = uVar3;
                uVar2 = uVar3;
              }
              if (0x350 < uVar13 * 0x58) goto LAB_00101434;
              if (*(int *)(&DAT_00102760 + uVar13 * 0x58) != 0) {
                uVar2 = uVar2 + 0x1000;
              }
              iVar7 = memshare_alloc(*puVar12,uVar2,&memblock + (ulong)uVar6 * 0xb);
              if (iVar7 == 0) {
                if (800 < uVar13 * 0x58) goto LAB_00101434;
                *(char *)(&DAT_00102790 + uVar13 * 0x2c) =
                     *(char *)(&DAT_00102790 + uVar13 * 0x2c) + '\x01';
                if (((0x35c < uVar11) || (*piVar1 = 1, 0x338 < uVar13 * 0x58)) ||
                   ((&DAT_00102778)[uVar13 * 0x16] = *param_4, 0x370 < (uVar13 * 0x58 | 4)))
                goto LAB_00101434;
                *(uint *)((long)&memblock + uVar13 * 0x58 + 4) = param_4[2];
              }
              else {
                _dev_err(*memsh_drv,
                         "memshare_alloc: unable to allocate memory of size: %d for requested client\n"
                         ,uVar2);
                local_6c = 1;
              }
            }
            if (&memblock + (ulong)uVar6 * 0xb != (undefined8 *)0x0) {
              if (0x34c < uVar13 * 0x58) goto LAB_00101434;
              if (1 < *(uint *)(&DAT_00102764 + uVar13 * 0x58)) {
                if (((0x328 < uVar13 * 0x58) || (0x330 < uVar13 * 0x58)) || (0x338 < uVar13 * 0x58))
                goto LAB_00101434;
                uVar9 = qcom_glink_mem_entry_init
                                  (*puVar12,(&DAT_00102788)[uVar13 * 0xb],
                                   (&DAT_00102780)[uVar13 * 0xb],(&DAT_00102778)[uVar13 * 0x16],
                                   (&DAT_00102780)[uVar13 * 0xb] & 0xffffffff);
                puVar12[2] = uVar9;
              }
            }
            if ((0x368 < uVar13 * 0x58) ||
               (*(uint *)(&DAT_00102748 + uVar13 * 0xb) = param_4[3], 0x358 < uVar13 * 0x58)) {
LAB_00101434:
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(1,0x101438);
              (*pcVar5)();
            }
            (&DAT_00102758)[uVar13 * 0x16] = 1;
            fill_alloc_response(puVar8,uVar6,&local_6c);
            if (799 < uVar13 * 0x58) goto LAB_00101434;
            if (*(char *)((long)&DAT_00102790 + uVar13 * 0x58 + 1) == '\0') {
              if (0x35c < uVar11) goto LAB_00101434;
              if (*piVar1 != 0) {
                shared_hyp_mapping(uVar10);
              }
            }
            mutex_unlock(memsh_drv + 1);
            _dev_info(*memsh_drv,
                      "memshare_alloc: client_id: %d, alloc_resp.num_bytes: %d, alloc_resp.resp.result: %lx\n"
                      ,param_4[1],puVar8[8],*(undefined2 *)puVar8);
            iVar7 = qmi_send_response(mem_share_svc_handle,param_2,param_3,0x22,0x418,
                                      &mem_alloc_generic_resp_msg_data_v01_ei,puVar8);
            if (iVar7 < 0) {
              _dev_err(*memsh_drv,"memshare_alloc: Error sending the alloc response: %d\n");
            }
            kfree(puVar8);
            goto LAB_00100f64;
          }
        }
        else if (num_clients != 1) {
          puVar12 = DAT_00102ab8;
          if (*(uint *)(DAT_00102ab8 + 1) == uVar2) goto LAB_00101104;
          if (num_clients != 2) {
            puVar12 = DAT_00102ac0;
            if (*(uint *)(DAT_00102ac0 + 1) == uVar2) goto LAB_00101104;
            if (num_clients != 3) {
              puVar12 = DAT_00102ac8;
              if (*(uint *)(DAT_00102ac8 + 1) == uVar2) goto LAB_00101104;
              if (num_clients != 4) {
                puVar12 = DAT_00102ad0;
                if (*(uint *)(DAT_00102ad0 + 1) == uVar2) goto LAB_00101104;
                if (num_clients != 5) {
                  puVar12 = DAT_00102ad8;
                  if (*(uint *)(DAT_00102ad8 + 1) == uVar2) goto LAB_00101104;
                  if (num_clients != 6) {
                    puVar12 = DAT_00102ae0;
                    if (*(uint *)(DAT_00102ae0 + 1) == uVar2) goto LAB_00101104;
                    if (num_clients != 7) {
                      puVar12 = DAT_00102ae8;
                      if (*(uint *)(DAT_00102ae8 + 1) == uVar2) goto LAB_00101104;
                      if (num_clients != 8) {
                        puVar12 = DAT_00102af0;
                        if (*(uint *)(DAT_00102af0 + 1) == uVar2) goto LAB_00101104;
                        if (num_clients != 9) {
                          puVar12 = DAT_00102af8;
                          if (*(uint *)(DAT_00102af8 + 1) == uVar2) goto LAB_00101104;
                          if (num_clients != 10) goto LAB_00101440;
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
      _dev_err(*memsh_drv,"memshare_alloc: No valid client node found\n");
    }
    else {
      _dev_err(*memsh_drv,
               "memshare_alloc: client not found for index: %d, requested client: %d, proc_id: %d\n"
               ,uVar10,param_4[1],param_4[2]);
    }
    kfree(puVar8);
  }
  mutex_unlock(memsh_drv + 1);
LAB_00100f64:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// handle_free_generic_req @ 00101448 size=1380
// signature: undefined handle_free_generic_req(void)
// callers: []
//------------------------------------------------------------

void handle_free_generic_req(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int *piVar1;
  undefined8 *puVar2;
  long lVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  ulong uVar7;
  undefined2 uVar8;
  undefined8 *puVar9;
  ulong uVar10;
  undefined4 local_88;
  ulong local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_80 = 0;
  uStack_78 = 3;
  local_70 = 7;
  mutex_lock(memsh_drv + 7);
  local_88 = 0x30000;
  _dev_info(*memsh_drv,
            "memshare_free: handling memory free request with client id: %d, proc_id: %d\n",
            *(undefined4 *)(param_4 + 0x40c),*(undefined4 *)(param_4 + 0x414));
  uVar5 = check_client(*(undefined4 *)(param_4 + 0x40c),*(undefined4 *)(param_4 + 0x414),1);
  if (9 < (int)uVar5) {
    _dev_err(*memsh_drv,"memshare_free: invalid client request to free memory\n");
  }
  if (num_clients != 0) {
    iVar6 = *(int *)(param_4 + 0x40c);
    puVar9 = memsh_child;
    if (*(int *)(memsh_child + 1) == iVar6) {
LAB_00101540:
      _dev_info(*memsh_drv,"memshare_free: found client with client_id: %d, index: %d\n",iVar6,uVar5
               );
      if (puVar9 != (undefined8 *)0x0) {
        if (puVar9[2] != 0) {
          qcom_glink_mem_entry_free();
          puVar9[2] = 0;
        }
        if (9 < (int)uVar5) goto LAB_001018c8;
        if (9 < uVar5) {
LAB_00101768:
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10176c);
          (*pcVar4)();
        }
        if (0x360 < (ulong)uVar5 * 0x58) goto LAB_001019a4;
        if (*(int *)(&DAT_00102750 + (ulong)uVar5 * 0xb) == 0) {
          uVar10 = (ulong)uVar5;
          if (0x354 < uVar10 * 0x58) goto LAB_001019a4;
          if (*(int *)(&DAT_0010275c + uVar10 * 0x58) != 0) goto LAB_001018c8;
          if (0x35c < uVar10 * 0x58) goto LAB_001019a4;
          piVar1 = (int *)((long)&DAT_00102750 + uVar10 * 0x58 + 4);
          if (*piVar1 == 0) goto LAB_001018c8;
          if (0x34c < uVar10 * 0x58) {
LAB_001019a4:
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(1,0x1019a8);
            (*pcVar4)();
          }
          iVar6 = *(int *)(&DAT_00102764 + uVar10 * 0x58);
          if (iVar6 == 0) {
            uVar7 = 0;
          }
          else {
            if (0x348 < uVar10 * 0x58) goto LAB_001019a4;
            uVar7 = 1L << ((ulong)*(uint *)(&DAT_00102768 + uVar10 * 0x58) & 0x3f);
            if (iVar6 != 1) {
              if (0x344 < uVar10 * 0x58) goto LAB_001019a4;
              if (iVar6 != 2) goto LAB_00101768;
              uVar7 = 1L << ((ulong)*(uint *)(&DAT_0010276c + uVar10 * 0x58) & 0x3f) | uVar7;
            }
          }
          local_80 = uVar7;
          if ((0x330 < uVar10 * 0x58) || (0x338 < uVar10 * 0x58)) goto LAB_001019a4;
          puVar2 = &DAT_00102780 + uVar10 * 0xb;
          iVar6 = qcom_scm_assign_mem(*puVar2,(&DAT_00102778)[uVar10 * 0x16],&local_80,&uStack_78,1)
          ;
          if (iVar6 != 0) {
            if (799 < uVar10 * 0x58) goto LAB_001019a4;
            if (*(char *)((long)&DAT_00102790 + uVar10 * 0x58 + 1) == '\x01') {
              _dev_err(*memsh_drv,"memshare_free: failed to unmap the region for client id:%d\n",
                       uVar5);
            }
          }
          if ((0x338 < uVar10 * 0x58) || (0x350 < uVar10 * 0x58)) goto LAB_001019a4;
          iVar6 = (&DAT_00102778)[uVar10 * 0x16];
          if (*(int *)(&DAT_00102760 + uVar10 * 0x58) != 0) {
            iVar6 = iVar6 + 0x1000;
          }
          if ((((0x328 < uVar10 * 0x58) || (0x330 < uVar10 * 0x58)) ||
              (dma_free_attrs(*puVar9,(long)iVar6,(&DAT_00102788)[uVar10 * 0xb],*puVar2,0),
              0x35c < uVar10 * 0x58)) || (*piVar1 = 0, 0x360 < (ulong)uVar5 * 0x58))
          goto LAB_001019a4;
          *(int *)(&DAT_00102750 + (ulong)uVar5 * 0xb) = 0;
          *puVar2 = 0;
          (&DAT_00102788)[uVar10 * 0xb] = 0;
          if ((0x368 < uVar10 * 0x58) ||
             (*(undefined4 *)(&DAT_00102748 + uVar10 * 0xb) = 0xffffffff, 0x364 < uVar10 * 0x58))
          goto LAB_001019a4;
          *(undefined4 *)((long)&DAT_00102748 + uVar10 * 0x58 + 4) = 1;
        }
        else {
LAB_001018c8:
          _dev_err(*memsh_drv,
                   "memshare_free: cannot free the memory for a guaranteed client (client index: %d)\n"
                   ,uVar5);
        }
        uVar8 = 0x29;
        if ((int)uVar5 < 10) {
          uVar8 = 0;
        }
        local_88 = CONCAT22(uVar8,(ushort)(9 < (int)uVar5));
        mutex_unlock(memsh_drv + 7);
        iVar6 = qmi_send_response(mem_share_svc_handle,param_2,param_3,0x23,0xff,
                                  &mem_free_generic_resp_msg_data_v01_ei,&local_88);
        if (iVar6 < 0) {
          _dev_err(*memsh_drv,"memshare_free: error sending the free response: %d\n");
        }
        goto LAB_00101934;
      }
    }
    else if (num_clients != 1) {
      puVar9 = DAT_00102ab8;
      if (*(int *)(DAT_00102ab8 + 1) == iVar6) goto LAB_00101540;
      if (num_clients != 2) {
        puVar9 = DAT_00102ac0;
        if (*(int *)(DAT_00102ac0 + 1) == iVar6) goto LAB_00101540;
        if (num_clients != 3) {
          puVar9 = DAT_00102ac8;
          if (*(int *)(DAT_00102ac8 + 1) == iVar6) goto LAB_00101540;
          if (num_clients != 4) {
            puVar9 = DAT_00102ad0;
            if (*(int *)(DAT_00102ad0 + 1) == iVar6) goto LAB_00101540;
            if (num_clients != 5) {
              puVar9 = DAT_00102ad8;
              if (*(int *)(DAT_00102ad8 + 1) == iVar6) goto LAB_00101540;
              if (num_clients != 6) {
                puVar9 = DAT_00102ae0;
                if (*(int *)(DAT_00102ae0 + 1) == iVar6) goto LAB_00101540;
                if (num_clients != 7) {
                  puVar9 = DAT_00102ae8;
                  if (*(int *)(DAT_00102ae8 + 1) == iVar6) goto LAB_00101540;
                  if (num_clients != 8) {
                    puVar9 = DAT_00102af0;
                    if (*(int *)(DAT_00102af0 + 1) == iVar6) goto LAB_00101540;
                    if (num_clients != 9) {
                      puVar9 = DAT_00102af8;
                      if (*(int *)(DAT_00102af8 + 1) == iVar6) goto LAB_00101540;
                      if (num_clients != 10) goto LAB_00101768;
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
  _dev_err(*memsh_drv,"memshare_free: No valid client node found\n");
  mutex_unlock(memsh_drv + 7);
LAB_00101934:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// handle_query_size_req @ 001019b0 size=376
// signature: undefined handle_query_size_req(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void handle_query_size_req
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  mutex_lock(memsh_drv + 1);
  puVar6 = (undefined4 *)kmalloc_trace(_mutex_lock,0xdc0,0xc);
  if (puVar6 != (undefined4 *)0x0) {
    uVar4 = check_client(*param_4,param_4[2],0);
    puVar2 = memsh_drv;
    if ((int)uVar4 < 10) {
      if (9 < uVar4) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x101b24);
        (*pcVar3)();
      }
      if (0x334 < (ulong)uVar4 * 0x58) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(1,0x101b28);
        (*pcVar3)();
      }
      *puVar6 = 0;
      uVar1 = *(undefined4 *)(&DAT_0010277c + (ulong)uVar4 * 0x58);
      *(undefined1 *)(puVar6 + 1) = 1;
      puVar6[2] = uVar1;
      mutex_unlock(puVar2 + 1);
      _dev_info(*memsh_drv,
                "memshare_query: client_id : %d, query_resp.size :%d, query_resp.resp.result :%lx\n"
                ,*param_4,uVar1,0);
      iVar5 = qmi_send_response(mem_share_svc_handle,param_2,param_3,0x24,0xff,
                                &mem_query_size_resp_msg_data_v01_ei,puVar6);
      if (iVar5 < 0) {
        _dev_err(*memsh_drv,"memshare_query: Error sending the query response: %d\n");
      }
      kfree(puVar6);
      return;
    }
    _dev_err(*memsh_drv,"memshare_query: client not found, requested client: %d, proc_id: %d\n",
             *param_4,param_4[2]);
    kfree(puVar6);
  }
  mutex_unlock(memsh_drv + 1);
  return;
}



//------------------------------------------------------------
// check_client @ 00101b28 size=816
// signature: undefined check_client(void)
// callers: [handle_alloc_generic_req, handle_free_generic_req, handle_query_size_req]
//------------------------------------------------------------

long check_client(int param_1,int param_2,int param_3)

{
  code *pcVar1;
  long lVar2;
  int *piVar3;
  
  if (num_clients != 0) {
    if (((int)memblock == param_1) && (memblock._4_4_ == param_2)) {
      return 0;
    }
    if (num_clients != 1) {
      if (((int)DAT_00102798 == param_1) && (DAT_00102798._4_4_ == param_2)) {
        return 1;
      }
      if (num_clients != 2) {
        if ((DAT_001027f0 == param_1) && (DAT_001027f4 == param_2)) {
          return 2;
        }
        if (num_clients != 3) {
          if ((DAT_00102848 == param_1) && (DAT_0010284c == param_2)) {
            return 3;
          }
          if (num_clients != 4) {
            if ((DAT_001028a0 == param_1) && (DAT_001028a4 == param_2)) {
              return 4;
            }
            if (num_clients != 5) {
              if ((DAT_001028f8 == param_1) && (DAT_001028fc == param_2)) {
                return 5;
              }
              if (num_clients != 6) {
                if ((DAT_00102950 == param_1) && (DAT_00102954 == param_2)) {
                  return 6;
                }
                if (num_clients != 7) {
                  if ((DAT_001029a8 == param_1) && (DAT_001029ac == param_2)) {
                    return 7;
                  }
                  if (num_clients != 8) {
                    if ((DAT_00102a00 == param_1) && (DAT_00102a04 == param_2)) {
                      return 8;
                    }
                    if (num_clients != 9) {
                      if ((DAT_00102a58 == param_1) && (DAT_00102a5c == param_2)) {
                        return 9;
                      }
                      if (num_clients != 10) {
                    /* WARNING: Does not return */
                        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x101e58);
                        (*pcVar1)();
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
  if (param_3 != 0) {
    return 1000;
  }
  if ((int)memblock == 1000) {
    lVar2 = 0;
    piVar3 = (int *)&memblock;
  }
  else {
    piVar3 = (int *)&DAT_00102798;
    if ((int)DAT_00102798 == 1000) {
      lVar2 = 1;
    }
    else {
      piVar3 = &DAT_001027f0;
      if (DAT_001027f0 == 1000) {
        lVar2 = 2;
      }
      else {
        piVar3 = &DAT_00102848;
        if (DAT_00102848 == 1000) {
          lVar2 = 3;
        }
        else {
          piVar3 = &DAT_001028a0;
          if (DAT_001028a0 == 1000) {
            lVar2 = 4;
          }
          else {
            piVar3 = &DAT_001028f8;
            if (DAT_001028f8 == 1000) {
              lVar2 = 5;
            }
            else {
              piVar3 = &DAT_00102950;
              if (DAT_00102950 == 1000) {
                lVar2 = 6;
              }
              else {
                piVar3 = &DAT_001029a8;
                if (DAT_001029a8 == 1000) {
                  lVar2 = 7;
                }
                else {
                  piVar3 = &DAT_00102a00;
                  if (DAT_00102a00 == 1000) {
                    lVar2 = 8;
                  }
                  else {
                    piVar3 = &DAT_00102a58;
                    if (DAT_00102a58 != 1000) {
                      return 1000;
                    }
                    lVar2 = 9;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  *piVar3 = param_1;
  (&DAT_00102750)[lVar2 * 0xb] = 0;
  *(int *)((long)&memblock + lVar2 * 0x58 + 4) = param_2;
  return lVar2;
}



//------------------------------------------------------------
// fill_alloc_response @ 00101e58 size=164
// signature: undefined fill_alloc_response(void)
// callers: [handle_alloc_generic_req]
//------------------------------------------------------------

void fill_alloc_response(ushort *param_1,uint param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  
  *(undefined1 *)(param_1 + 2) = 1;
  if (9 < param_2) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x101efc);
    (*pcVar3)();
  }
  if ((ulong)param_2 * 0x58 < 0x369) {
    uVar1 = *(undefined4 *)(&DAT_00102748 + (ulong)param_2 * 0xb);
    *(undefined1 *)(param_1 + 6) = 1;
    param_1[8] = 1;
    param_1[9] = 0;
    *(undefined4 *)(param_1 + 4) = uVar1;
    if (((ulong)param_2 * 0x58 < 0x331) &&
       (*(undefined8 *)(param_1 + 0xc) = (&DAT_00102780)[(ulong)param_2 * 0xb],
       (ulong)param_2 * 0x58 < 0x339)) {
      *(undefined4 *)(param_1 + 0x10) = (&DAT_00102778)[(ulong)param_2 * 0x16];
      iVar2 = *param_3;
      *param_1 = (ushort)(iVar2 != 0);
      param_1[1] = (ushort)(iVar2 != 0) << 1;
      return;
    }
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(1,0x101ef8);
  (*pcVar3)();
}



//------------------------------------------------------------
// modem_notifier_cb @ 00101f00 size=780
// signature: undefined modem_notifier_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 modem_notifier_cb(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  char cVar4;
  undefined8 *puVar5;
  long lVar6;
  undefined8 *puVar7;
  ulong local_80 [4];
  
  lVar6 = sp_el0;
  local_80[3] = *(long *)(lVar6 + 0x638);
  local_80[0] = 0;
  local_80[1] = 3;
  local_80[2] = 7;
  mutex_lock(memsh_drv + 1);
  switch(param_2) {
  case 0:
    break;
  case 1:
    _dev_info(*memsh_drv,"memshare: QCOM_SSR_AFTER_POWERUP: Modem has booted up\n");
    lVar6 = 0;
    puVar7 = &memsh_child;
    do {
      cVar4 = *(char *)((long)&DAT_00102790 + lVar6);
      if (cVar4 != '\0' && 1 < bootup_request) {
        cVar4 = cVar4 + -1;
        *(char *)((long)&DAT_00102790 + lVar6) = cVar4;
      }
      if (((((cVar4 == '\0') && (*(int *)((long)&memblock + lVar6 + 4) == 0)) &&
           (*(int *)((long)&DAT_00102750 + lVar6) == 0)) &&
          ((*(int *)(&DAT_0010275c + lVar6) == 0 && (*(int *)((long)&DAT_00102750 + lVar6 + 4) != 0)
           ))) && (*(int *)((long)&DAT_00102758 + lVar6) == 0)) {
        puVar5 = (undefined8 *)*puVar7;
        iVar1 = *(int *)((long)&DAT_00102778 + lVar6);
        _dev_info(*memsh_drv,
                  "memshare: hypervisor unmapping for allocated memory with client id: %d\n",
                  *(undefined4 *)((long)&memblock + lVar6));
        if (*(char *)((long)&DAT_00102790 + lVar6 + 1) != '\0') {
          iVar3 = *(int *)(&DAT_00102764 + lVar6);
          if (((iVar3 != 0) &&
              (local_80[0] = 1L << ((ulong)*(uint *)(&DAT_00102768 + lVar6) & 0x3f) | local_80[0],
              iVar3 != 1)) &&
             (local_80[0] = 1L << ((ulong)*(uint *)(&DAT_0010276c + lVar6) & 0x3f) | local_80[0],
             iVar3 != 2)) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1022e8);
            (*pcVar2)();
          }
          iVar3 = qcom_scm_assign_mem(*(undefined8 *)((long)&DAT_00102780 + lVar6),
                                      *(undefined4 *)((long)&DAT_00102778 + lVar6),local_80,
                                      local_80 + 1,1);
          if ((iVar3 == 0) || (*(char *)((long)&DAT_00102790 + lVar6 + 1) != '\x01')) {
            *(undefined1 *)((long)&DAT_00102790 + lVar6 + 1) = 0;
          }
          else {
            _dev_err(*memsh_drv,
                     "memshare: failed to hypervisor unmap the memory region for client id: %d\n",
                     *(undefined4 *)((long)&memblock + lVar6));
          }
        }
        if (*(int *)(&DAT_00102760 + lVar6) != 0) {
          iVar1 = iVar1 + 0x1000;
        }
        dma_free_attrs(*puVar5,(long)iVar1,*(undefined8 *)((long)&DAT_00102788 + lVar6),
                       *(undefined8 *)((long)&DAT_00102780 + lVar6),0);
        *(undefined4 *)((long)&DAT_00102750 + lVar6 + 4) = 0;
        *(undefined4 *)((long)&DAT_00102750 + lVar6) = 0;
        *(undefined8 *)((long)&DAT_00102780 + lVar6) = 0;
        *(undefined8 *)((long)&DAT_00102788 + lVar6) = 0;
        *(undefined8 *)((long)&DAT_00102748 + lVar6) = 0x1ffffffff;
      }
      lVar6 = lVar6 + 0x58;
      puVar7 = puVar7 + 1;
    } while (lVar6 != 0x370);
    bootup_request = bootup_request + 1;
    break;
  case 2:
    bootup_request = bootup_request + 1;
    _dev_info(*memsh_drv,"memshare: QCOM_SSR_BEFORE_SHUTDOWN: bootup_request:%d\n");
    DAT_00102758 = 0;
    DAT_001027b0 = 0;
    DAT_00102808 = 0;
    DAT_00102860 = 0;
    DAT_001028b8 = 0;
    DAT_00102910 = 0;
    DAT_00102968 = 0;
    DAT_001029c0 = 0;
    DAT_00102a18 = 0;
    DAT_00102a70 = 0;
    break;
  case 3:
  }
  mutex_unlock(memsh_drv + 1);
  _dev_info(*memsh_drv,"memshare: notifier_cb processed for code: %d\n",param_2);
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_80[3]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00102474 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&memshare_pdriver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001024a4 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&memshare_pdriver);
  return;
}



//------------------------------------------------------------
// dma_alloc_attrs @ 00105000 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [memshare_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00105008 size=1
// signature: undefined _dev_err(void)
// callers: [handle_alloc_generic_req, modem_notifier_cb, handle_free_generic_req, memshare_alloc, memshare_init_worker, handle_query_size_req, memshare_probe, shared_hyp_mapping]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00105010 size=1
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
// platform_driver_unregister @ 00105018 size=1
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
// of_device_is_compatible @ 00105020 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [memshare_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00105028 size=1
// signature: undefined devm_kmalloc(void)
// callers: [memshare_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00105030 size=1
// signature: undefined __mutex_init(void)
// callers: [memshare_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00105040 size=1
// signature: undefined queue_work_on(void)
// callers: [memshare_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_populate @ 00105048 size=1
// signature: undefined of_platform_populate(void)
// callers: [memshare_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_register_ssr_notifier @ 00105050 size=1
// signature: undefined qcom_register_ssr_notifier(void)
// callers: [memshare_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_register_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00105058 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [memshare_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00105060 size=1
// signature: undefined of_find_property(void)
// callers: [memshare_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00105068 size=1
// signature: undefined of_property_read_string(void)
// callers: [memshare_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00105070 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [memshare_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00105078 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [memshare_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_device_init_by_idx @ 00105080 size=1
// signature: undefined of_reserved_mem_device_init_by_idx(void)
// callers: [memshare_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_device_init_by_idx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00105088 size=1
// signature: undefined _dev_info(void)
// callers: [handle_alloc_generic_req, modem_notifier_cb, handle_free_generic_req, handle_query_size_req, memshare_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_device_release @ 00105090 size=1
// signature: undefined of_reserved_mem_device_release(void)
// callers: [memshare_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_device_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105098 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [handle_alloc_generic_req, modem_notifier_cb, handle_free_generic_req, memshare_probe, shared_hyp_mapping]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_release @ 001050a0 size=1
// signature: undefined qmi_handle_release(void)
// callers: [memshare_remove, memshare_init_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001050a8 size=1
// signature: undefined kfree(void)
// callers: [memshare_remove, handle_alloc_generic_req, memshare_init_worker, handle_query_size_req, shared_hyp_mapping]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001050b8 size=1
// signature: undefined kmalloc_trace(void)
// callers: [handle_alloc_generic_req, memshare_init_worker, handle_query_size_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_init @ 001050c0 size=1
// signature: undefined qmi_handle_init(void)
// callers: [memshare_init_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_add_server @ 001050c8 size=1
// signature: undefined qmi_add_server(void)
// callers: [memshare_init_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_add_server(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001050d0 size=1
// signature: undefined __kmalloc(void)
// callers: [shared_hyp_mapping]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_assign_mem @ 001050d8 size=1
// signature: undefined qcom_scm_assign_mem(void)
// callers: [modem_notifier_cb, handle_free_generic_req, shared_hyp_mapping]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_assign_mem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001050e0 size=1
// signature: undefined mutex_lock(void)
// callers: [handle_alloc_generic_req, modem_notifier_cb, handle_free_generic_req, handle_query_size_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001050e8 size=1
// signature: undefined mutex_unlock(void)
// callers: [handle_alloc_generic_req, modem_notifier_cb, handle_free_generic_req, handle_query_size_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_mem_entry_init @ 001050f0 size=1
// signature: undefined qcom_glink_mem_entry_init(void)
// callers: [handle_alloc_generic_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_mem_entry_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_send_response @ 00105100 size=1
// signature: undefined qmi_send_response(void)
// callers: [handle_alloc_generic_req, handle_free_generic_req, handle_query_size_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_send_response(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_mem_entry_free @ 00105108 size=1
// signature: undefined qcom_glink_mem_entry_free(void)
// callers: [handle_free_generic_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_mem_entry_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 00105110 size=1
// signature: undefined dma_free_attrs(void)
// callers: [modem_notifier_cb, handle_free_generic_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



