// Decompiled by Ghidra 12.2
// Program: cqhci.ko
// Image base: 00100000

//------------------------------------------------------------
// cqhci_deactivate @ 00100854 size=208
// signature: undefined cqhci_deactivate(void)
// callers: []
//------------------------------------------------------------

undefined8 cqhci_deactivate(long param_1)

{
  uint uVar1;
  code *pcVar2;
  long *plVar3;
  
  plVar3 = *(long **)(param_1 + 0x5f8);
  if (((char)plVar3[7] != '\0') && (*(char *)((long)plVar3 + 0x3b) != '\0')) {
    pcVar2 = *(code **)(*plVar3 + 0x10);
    if (pcVar2 == (code *)0x0) {
      uVar1 = readl_relaxed(plVar3[1] + 8);
    }
    else {
      if (*(int *)(pcVar2 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1008f0);
        (*pcVar2)();
      }
      uVar1 = (*pcVar2)(plVar3,8);
    }
    pcVar2 = *(code **)(*plVar3 + 8);
    if (pcVar2 == (code *)0x0) {
      writel_relaxed(uVar1 & 0xfffffffe,plVar3[1] + 8);
    }
    else {
      if (*(int *)(pcVar2 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x10091c);
        (*pcVar2)();
      }
      (*pcVar2)(plVar3,uVar1 & 0xfffffffe,8);
    }
    *(undefined1 *)(plVar3[2] + 0x605) = 0;
    *(undefined1 *)((long)plVar3 + 0x3b) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// cqhci_resume @ 00100928 size=8
// signature: undefined cqhci_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 cqhci_resume(void)

{
  return 0;
}



//------------------------------------------------------------
// cqhci_irq @ 00100934 size=2676
// signature: undefined cqhci_irq(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

undefined8 cqhci_irq(long param_1,undefined8 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  long lVar8;
  undefined4 uVar9;
  code *pcVar10;
  long lVar11;
  long lVar12;
  long *plVar13;
  long *plVar14;
  long *plVar15;
  ulong local_70;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  plVar13 = *(long **)(param_1 + 0x5f8);
  local_70 = 0;
  pcVar10 = *(code **)(*plVar13 + 0x10);
  if (pcVar10 == (code *)0x0) {
    uVar4 = readl_relaxed(plVar13[1] + 0x10);
  }
  else {
    if (*(int *)(pcVar10 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x100f88);
      (*pcVar10)();
    }
    uVar4 = (*pcVar10)(plVar13,0x10);
  }
  if ((param_4 == 0 && param_3 == 0) && ((uVar4 & 0x34) == 0)) {
    pcVar10 = *(code **)(*plVar13 + 8);
    if (pcVar10 == (code *)0x0) {
      writel_relaxed(uVar4,plVar13[1] + 0x10);
    }
    else {
      if (*(int *)(pcVar10 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x100fb4);
        (*pcVar10)();
      }
      (*pcVar10)(plVar13,uVar4,0x10);
    }
    goto LAB_001009c4;
  }
  if ((uVar4 >> 2 & 1) == 0) {
    if ((uVar4 >> 4 & 1) != 0) goto LAB_00100ce4;
LAB_00100c48:
    if ((uVar4 >> 5 & 1) != 0) goto LAB_00100cf4;
LAB_00100c4c:
    lVar8 = *(long *)(param_1 + 0x78);
  }
  else {
    *(int *)(param_1 + 0x6f8) = *(int *)(param_1 + 0x6f8) + 1;
    if ((uVar4 >> 4 & 1) == 0) goto LAB_00100c48;
LAB_00100ce4:
    *(int *)(param_1 + 0x6fc) = *(int *)(param_1 + 0x6fc) + 1;
    if ((uVar4 >> 5 & 1) == 0) goto LAB_00100c4c;
LAB_00100cf4:
    *(int *)(param_1 + 0x700) = *(int *)(param_1 + 0x700) + 1;
    lVar8 = *(long *)(param_1 + 0x78);
  }
  if (lVar8 == 0) {
    lVar8 = *(long *)(param_1 + 8);
  }
  _printk(&DAT_00104d5f,lVar8,uVar4,param_3,param_4);
  cqhci_dumpregs(plVar13);
  pcVar10 = *(code **)(*plVar13 + 8);
  if (pcVar10 == (code *)0x0) {
    writel_relaxed(uVar4,plVar13[1] + 0x10);
  }
  else {
    if (*(int *)(pcVar10 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x101034);
      (*pcVar10)();
    }
    (*pcVar10)(plVar13,uVar4,0x10);
  }
  plVar14 = *(long **)(param_1 + 0x5f8);
  _raw_spin_lock(plVar14 + 3);
  pcVar10 = *(code **)(*plVar14 + 0x10);
  if (pcVar10 == (code *)0x0) {
    uVar5 = readl_relaxed(plVar14[1] + 0x54);
  }
  else {
    if (*(int *)(pcVar10 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x10105c);
      (*pcVar10)();
    }
    uVar5 = (*pcVar10)(plVar14,0x54);
  }
  if (*(char *)((long)plVar14 + 0x3d) == '\0') {
    if ((int)plVar14[5] == 0) {
      if ((cqhci_error_irq___already_done & 1) == 0) {
        lVar8 = *(long *)(param_1 + 0x78);
        cqhci_error_irq___already_done = 1;
        if (lVar8 == 0) {
          lVar8 = *(long *)(param_1 + 8);
        }
        __warn_printk("%s: cqhci: error when idle. IRQ status: 0x%08x cmd error %d data error %d TERRI: 0x%08x\n"
                      ,lVar8,uVar4,param_3,param_4,uVar5);
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x800,0x100ed0);
        (*pcVar10)();
      }
    }
    else {
      if ((uVar5 >> 0xf & 1) != 0) {
        uVar7 = (ulong)(uVar5 >> 8 & 0x1f);
        lVar8 = *(long *)(plVar14[0x17] + uVar7 * 0x10);
        if (lVar8 != 0) {
          iVar1 = param_4;
          if (param_3 != 0) {
            iVar1 = param_3;
          }
          uVar9 = 8;
          if (iVar1 != -0x6e) {
            uVar9 = 0x10;
          }
          uVar2 = 4;
          if (iVar1 != -0x54) {
            uVar2 = uVar9;
          }
          *(undefined4 *)(plVar14[0x17] + uVar7 * 0x10 + 8) = uVar2;
          lVar11 = *(long *)(param_1 + 0x5f8);
          if (*(char *)(lVar11 + 0x3d) == '\0') {
            *(undefined1 *)(lVar11 + 0x3d) = 1;
            __wake_up(lVar11 + 0xa0,3,1,0);
            pcVar10 = *(code **)(lVar8 + 0x68);
            if (pcVar10 != (code *)0x0) {
              if (*(int *)(pcVar10 + -4) != -0x44011c92) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x100da4);
                (*pcVar10)();
              }
              (*pcVar10)(lVar8);
            }
          }
        }
      }
      if ((int)uVar5 < 0) {
        uVar7 = (ulong)(uVar5 >> 0x18 & 0x1f);
        lVar8 = *(long *)(plVar14[0x17] + uVar7 * 0x10);
        if (lVar8 != 0) {
          iVar1 = param_3;
          if (param_4 != 0) {
            iVar1 = param_4;
          }
          uVar9 = 8;
          if (iVar1 != -0x6e) {
            uVar9 = 0x10;
          }
          uVar2 = 4;
          if (iVar1 != -0x54) {
            uVar2 = uVar9;
          }
          *(undefined4 *)(plVar14[0x17] + uVar7 * 0x10 + 8) = uVar2;
          lVar11 = *(long *)(param_1 + 0x5f8);
          if (*(char *)(lVar11 + 0x3d) == '\0') {
            *(undefined1 *)(lVar11 + 0x3d) = 1;
            __wake_up(lVar11 + 0xa0,3,1,0);
            pcVar10 = *(code **)(lVar8 + 0x68);
            if (pcVar10 != (code *)0x0) {
              if (*(int *)(pcVar10 + -4) != -0x44011c92) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x100f60);
                (*pcVar10)();
              }
              (*pcVar10)(lVar8);
            }
          }
        }
      }
      if ((uVar4 >> 5 & 1) != 0) {
        pcVar10 = *(code **)(*plVar14 + 0x10);
        if (pcVar10 == (code *)0x0) {
          uVar5 = readl_relaxed(plVar14[1] + 0x3c);
        }
        else {
          if (*(int *)(pcVar10 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
            pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x101084);
            (*pcVar10)();
          }
          uVar5 = (*pcVar10)(plVar14,0x3c);
        }
        if ((cqhci_error_irq___already_done_22 & 1) == 0) {
          lVar8 = *(long *)(param_1 + 0x78);
          cqhci_error_irq___already_done_22 = 1;
          if (lVar8 == 0) {
            lVar8 = *(long *)(param_1 + 8);
          }
          __warn_printk("%s: cqhci: invalid crypto configuration error. IRQ status: 0x%08x TDPE: 0x%08x\n"
                        ,lVar8,uVar4,uVar5);
                    /* WARNING: Does not return */
          pcVar10 = (code *)SoftwareBreakpoint(0x800,0x1010b8);
          (*pcVar10)();
        }
        if (uVar5 != 0) {
          iVar1 = param_3;
          if (param_4 != 0) {
            iVar1 = param_4;
          }
          uVar9 = 8;
          if (iVar1 != -0x6e) {
            uVar9 = 0x10;
          }
          uVar2 = 4;
          if (iVar1 != -0x54) {
            uVar2 = uVar9;
          }
          do {
            uVar6 = (uVar5 & 0xaaaaaaaa) >> 1 | (uVar5 & 0x55555555) << 1;
            uVar6 = (uVar6 & 0xcccccccc) >> 2 | (uVar6 & 0x33333333) << 2;
            uVar6 = (uVar6 & 0xf0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f) << 4;
            uVar6 = (uVar6 & 0xff00ff00) >> 8 | (uVar6 & 0xff00ff) << 8;
            lVar8 = LZCOUNT(uVar6 >> 0x10 | uVar6 << 0x10);
            lVar11 = *(long *)(plVar14[0x17] + lVar8 * 0x10);
            if (lVar11 != 0) {
              *(undefined4 *)(plVar14[0x17] + lVar8 * 0x10 + 8) = uVar2;
              lVar12 = *(long *)(param_1 + 0x5f8);
              if (*(char *)(lVar12 + 0x3d) == '\0') {
                *(undefined1 *)(lVar12 + 0x3d) = 1;
                __wake_up(lVar12 + 0xa0,3,1,0);
                pcVar10 = *(code **)(lVar11 + 0x68);
                if (pcVar10 != (code *)0x0) {
                  if (*(int *)(pcVar10 + -4) != -0x44011c92) {
                    /* WARNING: Does not return */
                    pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x100e84);
                    (*pcVar10)();
                  }
                  (*pcVar10)(lVar11);
                }
              }
            }
            uVar5 = uVar5 & (1 << (ulong)((uint)lVar8 & 0x1f) ^ 0xffffffffU);
          } while (uVar5 != 0);
        }
      }
      if (*(char *)((long)plVar14 + 0x3d) == '\0') {
        plVar15 = (long *)plVar14[0x17];
        lVar8 = *plVar15;
        if (lVar8 == 0) {
          lVar8 = plVar15[2];
          if (lVar8 == 0) {
            lVar8 = plVar15[4];
            if (lVar8 == 0) {
              lVar8 = plVar15[6];
              if (lVar8 == 0) {
                lVar8 = plVar15[8];
                if (lVar8 == 0) {
                  lVar8 = plVar15[10];
                  if (lVar8 == 0) {
                    lVar8 = plVar15[0xc];
                    if (lVar8 == 0) {
                      lVar8 = plVar15[0xe];
                      if (lVar8 == 0) {
                        lVar8 = plVar15[0x10];
                        if (lVar8 == 0) {
                          lVar8 = plVar15[0x12];
                          if (lVar8 == 0) {
                            lVar8 = plVar15[0x14];
                            if (lVar8 == 0) {
                              lVar8 = plVar15[0x16];
                              if (lVar8 == 0) {
                                lVar8 = plVar15[0x18];
                                if (lVar8 == 0) {
                                  lVar8 = plVar15[0x1a];
                                  if (lVar8 == 0) {
                                    lVar8 = plVar15[0x1c];
                                    if (lVar8 == 0) {
                                      lVar8 = plVar15[0x1e];
                                      if (lVar8 == 0) {
                                        lVar8 = plVar15[0x20];
                                        if (lVar8 == 0) {
                                          lVar8 = plVar15[0x22];
                                          if (lVar8 == 0) {
                                            lVar8 = plVar15[0x24];
                                            if (lVar8 == 0) {
                                              lVar8 = plVar15[0x26];
                                              if (lVar8 == 0) {
                                                lVar8 = plVar15[0x28];
                                                if (lVar8 == 0) {
                                                  lVar8 = plVar15[0x2a];
                                                  if (lVar8 == 0) {
                                                    lVar8 = plVar15[0x2c];
                                                    if (lVar8 == 0) {
                                                      lVar8 = plVar15[0x2e];
                                                      if (lVar8 == 0) {
                                                        lVar8 = plVar15[0x30];
                                                        if (lVar8 == 0) {
                                                          lVar8 = plVar15[0x32];
                                                          if (lVar8 == 0) {
                                                            lVar8 = plVar15[0x34];
                                                            if (lVar8 == 0) {
                                                              lVar8 = plVar15[0x36];
                                                              if (lVar8 == 0) {
                                                                lVar8 = plVar15[0x38];
                                                                if (lVar8 == 0) {
                                                                  lVar8 = plVar15[0x3a];
                                                                  if (lVar8 == 0) {
                                                                    lVar8 = plVar15[0x3c];
                                                                    if (lVar8 == 0) {
                                                                      lVar8 = plVar15[0x3e];
                                                                      if (lVar8 == 0)
                                                                      goto LAB_00100cc8;
                                                                      lVar11 = 0x1f;
                                                                    }
                                                                    else {
                                                                      lVar11 = 0x1e;
                                                                    }
                                                                  }
                                                                  else {
                                                                    lVar11 = 0x1d;
                                                                  }
                                                                }
                                                                else {
                                                                  lVar11 = 0x1c;
                                                                }
                                                              }
                                                              else {
                                                                lVar11 = 0x1b;
                                                              }
                                                            }
                                                            else {
                                                              lVar11 = 0x1a;
                                                            }
                                                          }
                                                          else {
                                                            lVar11 = 0x19;
                                                          }
                                                        }
                                                        else {
                                                          lVar11 = 0x18;
                                                        }
                                                      }
                                                      else {
                                                        lVar11 = 0x17;
                                                      }
                                                    }
                                                    else {
                                                      lVar11 = 0x16;
                                                    }
                                                  }
                                                  else {
                                                    lVar11 = 0x15;
                                                  }
                                                }
                                                else {
                                                  lVar11 = 0x14;
                                                }
                                              }
                                              else {
                                                lVar11 = 0x13;
                                              }
                                            }
                                            else {
                                              lVar11 = 0x12;
                                            }
                                          }
                                          else {
                                            lVar11 = 0x11;
                                          }
                                        }
                                        else {
                                          lVar11 = 0x10;
                                        }
                                      }
                                      else {
                                        lVar11 = 0xf;
                                      }
                                    }
                                    else {
                                      lVar11 = 0xe;
                                    }
                                  }
                                  else {
                                    lVar11 = 0xd;
                                  }
                                }
                                else {
                                  lVar11 = 0xc;
                                }
                              }
                              else {
                                lVar11 = 0xb;
                              }
                            }
                            else {
                              lVar11 = 10;
                            }
                          }
                          else {
                            lVar11 = 9;
                          }
                        }
                        else {
                          lVar11 = 8;
                        }
                      }
                      else {
                        lVar11 = 7;
                      }
                    }
                    else {
                      lVar11 = 6;
                    }
                  }
                  else {
                    lVar11 = 5;
                  }
                }
                else {
                  lVar11 = 4;
                }
              }
              else {
                lVar11 = 3;
              }
            }
            else {
              lVar11 = 2;
            }
          }
          else {
            lVar11 = 1;
          }
        }
        else {
          lVar11 = 0;
        }
        if (param_4 != 0) {
          param_3 = param_4;
        }
        uVar9 = 8;
        if (param_3 != -0x6e) {
          uVar9 = 0x10;
        }
        uVar2 = 4;
        if (param_3 != -0x54) {
          uVar2 = uVar9;
        }
        *(undefined4 *)(plVar15 + lVar11 * 2 + 1) = uVar2;
        lVar11 = *(long *)(param_1 + 0x5f8);
        if (*(char *)(lVar11 + 0x3d) == '\0') {
          *(undefined1 *)(lVar11 + 0x3d) = 1;
          __wake_up(lVar11 + 0xa0,3,1,0);
          pcVar10 = *(code **)(lVar8 + 0x68);
          if (pcVar10 != (code *)0x0) {
            if (*(int *)(pcVar10 + -4) != -0x44011c92) {
                    /* WARNING: Does not return */
              pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x1013b0);
              (*pcVar10)();
            }
            (*pcVar10)(lVar8);
          }
        }
      }
    }
  }
LAB_00100cc8:
  _raw_spin_unlock(plVar14 + 3);
LAB_001009c4:
  if ((uVar4 >> 1 & 1) != 0) {
    pcVar10 = *(code **)(*plVar13 + 0x10);
    if (pcVar10 == (code *)0x0) {
      uVar5 = readl_relaxed(plVar13[1] + 0x2c);
    }
    else {
      if (*(int *)(pcVar10 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x100fdc);
        (*pcVar10)();
      }
      uVar5 = (*pcVar10)(plVar13,0x2c);
    }
    local_70 = (ulong)uVar5;
    pcVar10 = *(code **)(*plVar13 + 8);
    if (pcVar10 == (code *)0x0) {
      writel_relaxed(uVar5,plVar13[1] + 0x2c);
    }
    else {
      if (*(int *)(pcVar10 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x8229,0x101008);
        (*pcVar10)();
      }
      (*pcVar10)(plVar13,uVar5,0x2c);
    }
    _raw_spin_lock(plVar13 + 3);
    lVar8 = 0;
    while (uVar7 = _find_next_bit(&local_70,(long)*(int *)((long)plVar13 + 0x24),lVar8),
          uVar7 < (ulong)(long)*(int *)((long)plVar13 + 0x24)) {
      plVar15 = *(long **)(param_1 + 0x5f8);
      plVar14 = (long *)(plVar15[0x17] + (uVar7 & 0xffffffff) * 0x10);
      lVar8 = *plVar14;
      if (lVar8 == 0) {
        if ((cqhci_finish_mrq___already_done & 1) == 0) {
          lVar8 = *(long *)(param_1 + 0x78);
          cqhci_finish_mrq___already_done = 1;
          if (lVar8 == 0) {
            lVar8 = *(long *)(param_1 + 8);
          }
          __warn_printk("%s: cqhci: spurious TCN for tag %d\n",lVar8,uVar7 & 0xffffffff);
                    /* WARNING: Does not return */
          pcVar10 = (code *)SoftwareBreakpoint(0x800,0x100b94);
          (*pcVar10)();
        }
LAB_00100a84:
        lVar8 = uVar7 + 1;
      }
      else {
        if (*(char *)((long)plVar15 + 0x3d) == '\0') {
          cVar3 = *(char *)((long)plVar15 + 0x3e);
          *plVar14 = 0;
          *(int *)(plVar15 + 5) = (int)plVar15[5] + -1;
          lVar11 = *(long *)(lVar8 + 0x10);
          if (lVar11 == 0) {
            uVar5 = 0x100;
            if (cVar3 != '\0') {
              uVar5 = 0xa00;
            }
            pcVar10 = *(code **)(*plVar15 + 0x10);
            if (pcVar10 == (code *)0x0) {
              uVar6 = readl_relaxed(plVar15[1] + (ulong)uVar5);
            }
            else {
              if (*(int *)(pcVar10 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x100bbc);
                (*pcVar10)();
              }
              uVar6 = (*pcVar10)(plVar15,uVar5);
            }
            pcVar10 = *(code **)(*plVar15 + 8);
            if (pcVar10 == (code *)0x0) {
              writel_relaxed(uVar6 | 0x80000000,plVar15[1] + (ulong)uVar5);
            }
            else {
              if (*(int *)(pcVar10 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8229,0x100be8);
                (*pcVar10)();
              }
              (*pcVar10)(plVar15,uVar6 | 0x80000000,uVar5);
            }
          }
          else if (*(int *)(lVar11 + 0x14) == 0) {
            *(int *)(lVar11 + 0x1c) = *(int *)(lVar11 + 0xc) * *(int *)(lVar11 + 8);
          }
          else {
            *(undefined4 *)(lVar11 + 0x1c) = 0;
          }
          mmc_cqe_request_done(param_1,lVar8);
          goto LAB_00100a84;
        }
        lVar8 = uVar7 + 1;
        lVar11 = plVar15[0x17] + (uVar7 & 0xffffffff) * 0x10;
        *(uint *)(lVar11 + 8) = *(uint *)(lVar11 + 8) | 2;
      }
    }
    if ((*(char *)((long)plVar13 + 0x3c) != '\0') && ((int)plVar13[5] == 0)) {
      *(undefined1 *)((long)plVar13 + 0x3c) = 0;
      __wake_up(plVar13 + 0x14,3,1,0);
    }
    _raw_spin_unlock(plVar13 + 3);
  }
  if ((uVar4 >> 3 & 1) != 0) {
    __wake_up(plVar13 + 0x14,3,1,0);
  }
  if ((uVar4 & 1) != 0) {
    __wake_up(plVar13 + 0x14,3,1,0);
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// cqhci_dumpregs @ 001013b8 size=2108
// signature: undefined cqhci_dumpregs(void)
// callers: [cqhci_irq, cqhci_timeout]
//------------------------------------------------------------

void cqhci_dumpregs(long *param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  code *pcVar5;
  uint uVar6;
  long lVar7;
  
  lVar7 = param_1[2];
  lVar4 = *(long *)(lVar7 + 0x78);
  if (lVar4 == 0) {
    lVar4 = *(long *)(lVar7 + 8);
  }
  cVar1 = *(char *)((long)param_1 + 0x3e);
  _printk(&DAT_00104dc7,lVar4);
  lVar4 = *(long *)(lVar7 + 0x78);
  if (lVar4 == 0) {
    lVar4 = *(long *)(lVar7 + 8);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar2 = readl_relaxed(param_1[1] + 4);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101880);
      (*pcVar5)();
    }
    uVar2 = (*pcVar5)(param_1,4);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar3 = readl_relaxed(param_1[1]);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1018a8);
      (*pcVar5)();
    }
    uVar3 = (*pcVar5)(param_1,0);
  }
  _printk(&DAT_00105038,lVar4,uVar2,uVar3);
  lVar4 = *(long *)(lVar7 + 0x78);
  if (lVar4 == 0) {
    lVar4 = *(long *)(lVar7 + 8);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar2 = readl_relaxed(param_1[1] + 8);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1018d0);
      (*pcVar5)();
    }
    uVar2 = (*pcVar5)(param_1,8);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar3 = readl_relaxed(param_1[1] + 0xc);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1018f8);
      (*pcVar5)();
    }
    uVar3 = (*pcVar5)(param_1,0xc);
  }
  _printk(&DAT_00105164,lVar4,uVar2,uVar3);
  lVar4 = *(long *)(lVar7 + 0x78);
  if (lVar4 == 0) {
    lVar4 = *(long *)(lVar7 + 8);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar2 = readl_relaxed(param_1[1] + 0x10);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101920);
      (*pcVar5)();
    }
    uVar2 = (*pcVar5)(param_1,0x10);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar3 = readl_relaxed(param_1[1] + 0x14);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101948);
      (*pcVar5)();
    }
    uVar3 = (*pcVar5)(param_1,0x14);
  }
  _printk(&DAT_00105233,lVar4,uVar2,uVar3);
  lVar4 = *(long *)(lVar7 + 0x78);
  if (lVar4 == 0) {
    lVar4 = *(long *)(lVar7 + 8);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar2 = readl_relaxed(param_1[1] + 0x18);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101970);
      (*pcVar5)();
    }
    uVar2 = (*pcVar5)(param_1,0x18);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar3 = readl_relaxed(param_1[1] + 0x1c);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101998);
      (*pcVar5)();
    }
    uVar3 = (*pcVar5)(param_1,0x1c);
  }
  _printk(&DAT_00104fdb,lVar4,uVar2,uVar3);
  lVar4 = *(long *)(lVar7 + 0x78);
  if (lVar4 == 0) {
    lVar4 = *(long *)(lVar7 + 8);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar2 = readl_relaxed(param_1[1] + 0x20);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1019c0);
      (*pcVar5)();
    }
    uVar2 = (*pcVar5)(param_1,0x20);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar3 = readl_relaxed(param_1[1] + 0x24);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1019e8);
      (*pcVar5)();
    }
    uVar3 = (*pcVar5)(param_1,0x24);
  }
  _printk(&DAT_00104f01,lVar4,uVar2,uVar3);
  lVar4 = *(long *)(lVar7 + 0x78);
  if (lVar4 == 0) {
    lVar4 = *(long *)(lVar7 + 8);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar2 = readl_relaxed(param_1[1] + 0x28);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101a10);
      (*pcVar5)();
    }
    uVar2 = (*pcVar5)(param_1,0x28);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar3 = readl_relaxed(param_1[1] + 0x2c);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101a38);
      (*pcVar5)();
    }
    uVar3 = (*pcVar5)(param_1,0x2c);
  }
  _printk(&DAT_00104cb5,lVar4,uVar2,uVar3);
  lVar4 = *(long *)(lVar7 + 0x78);
  if (lVar4 == 0) {
    lVar4 = *(long *)(lVar7 + 8);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar2 = readl_relaxed(param_1[1] + 0x30);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101a60);
      (*pcVar5)();
    }
    uVar2 = (*pcVar5)(param_1,0x30);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar3 = readl_relaxed(param_1[1] + 0x34);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101a88);
      (*pcVar5)();
    }
    uVar3 = (*pcVar5)(param_1,0x34);
  }
  _printk(&DAT_00105266,lVar4,uVar2,uVar3);
  lVar4 = *(long *)(lVar7 + 0x78);
  if (lVar4 == 0) {
    lVar4 = *(long *)(lVar7 + 8);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar2 = readl_relaxed(param_1[1] + 0x38);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101ab0);
      (*pcVar5)();
    }
    uVar2 = (*pcVar5)(param_1,0x38);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar3 = readl_relaxed(param_1[1] + 0x40);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101ad8);
      (*pcVar5)();
    }
    uVar3 = (*pcVar5)(param_1,0x40);
  }
  _printk(&DAT_001052f6,lVar4,uVar2,uVar3);
  lVar4 = *(long *)(lVar7 + 0x78);
  if (lVar4 == 0) {
    lVar4 = *(long *)(lVar7 + 8);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar2 = readl_relaxed(param_1[1] + 0x44);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101b00);
      (*pcVar5)();
    }
    uVar2 = (*pcVar5)(param_1,0x44);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar3 = readl_relaxed(param_1[1] + 0x48);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101b28);
      (*pcVar5)();
    }
    uVar3 = (*pcVar5)(param_1,0x48);
  }
  _printk(&DAT_00105299,lVar4,uVar2,uVar3);
  lVar4 = *(long *)(lVar7 + 0x78);
  if (lVar4 == 0) {
    lVar4 = *(long *)(lVar7 + 8);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar2 = readl_relaxed(param_1[1] + 0x50);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101b50);
      (*pcVar5)();
    }
    uVar2 = (*pcVar5)(param_1,0x50);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar3 = readl_relaxed(param_1[1] + 0x54);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101b78);
      (*pcVar5)();
    }
    uVar3 = (*pcVar5)(param_1,0x54);
  }
  _printk(&DAT_0010506b,lVar4,uVar2,uVar3);
  lVar4 = *(long *)(lVar7 + 0x78);
  if (lVar4 == 0) {
    lVar4 = *(long *)(lVar7 + 8);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar2 = readl_relaxed(param_1[1] + 0x58);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101ba0);
      (*pcVar5)();
    }
    uVar2 = (*pcVar5)(param_1,0x58);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar3 = readl_relaxed(param_1[1] + 0x5c);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101bc8);
      (*pcVar5)();
    }
    uVar3 = (*pcVar5)(param_1,0x5c);
  }
  _printk(&DAT_00105329,lVar4,uVar2,uVar3);
  lVar4 = *(long *)(lVar7 + 0x78);
  if (lVar4 == 0) {
    lVar4 = *(long *)(lVar7 + 8);
  }
  uVar6 = 0x100;
  if (cVar1 != '\0') {
    uVar6 = 0xa00;
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar2 = readl_relaxed(param_1[1] + (ulong)uVar6);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101bec);
      (*pcVar5)();
    }
    uVar2 = (*pcVar5)(param_1);
  }
  _printk(&DAT_00104ee1,lVar4,uVar2);
  pcVar5 = *(code **)*param_1;
  if (pcVar5 == (code *)0x0) {
    lVar4 = *(long *)(lVar7 + 0x78);
    if (lVar4 == 0) {
      lVar4 = *(long *)(lVar7 + 8);
    }
    _printk(&DAT_00104f34,lVar4);
  }
  else {
    if (*(int *)(pcVar5 + -4) != 0x3af16e59) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101828);
      (*pcVar5)();
    }
    (*pcVar5)(lVar7);
  }
  return;
}



//------------------------------------------------------------
// cqhci_pltfm_init @ 00101bf8 size=172
// signature: undefined cqhci_pltfm_init(void)
// callers: []
//------------------------------------------------------------

long cqhci_pltfm_init(long param_1)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  long lVar4;
  
  plVar2 = (long *)platform_get_resource_byname(param_1,0x200,"cqhci");
  if (plVar2 == (long *)0x0) {
    lVar3 = -0x16;
  }
  else {
    lVar1 = param_1 + 0x10;
    lVar3 = devm_kmalloc(lVar1,0xf0,0xdc0);
    if (lVar3 == 0) {
      lVar3 = -0xc;
    }
    else {
      lVar4 = devm_ioremap(lVar1,*plVar2,(plVar2[1] - *plVar2) + 1);
      *(long *)(lVar3 + 8) = lVar4;
      if (lVar4 == 0) {
        _dev_err(lVar1,"failed to remap cqhci regs\n");
        lVar3 = -0x10;
      }
      else {
        *(long *)(lVar3 + 0xe0) = param_1;
      }
    }
  }
  return lVar3;
}



//------------------------------------------------------------
// cqhci_init @ 00101ca8 size=628
// signature: undefined cqhci_init(void)
// callers: []
//------------------------------------------------------------

int cqhci_init(long *param_1,undefined8 *param_2,undefined1 param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  code *pcVar5;
  undefined4 uVar6;
  
  *(undefined1 *)(param_1 + 4) = param_3;
  param_1[2] = (long)param_2;
  param_2[0xbf] = param_1;
  *(undefined4 *)((long)param_1 + 0x24) = 0x20;
  *(undefined4 *)((long)param_1 + 0x2c) = 0x1f;
  uVar6 = 0x1f;
  if ((*(uint *)(param_2 + 0x7d) & 0x1000000) == 0) {
    uVar6 = 0x20;
  }
  *(undefined4 *)(param_2 + 0xc0) = uVar6;
  param_2[0xbe] = &cqhci_cqe_ops;
  if ((int)*(uint *)((long)param_1 + 0x24) < 0) {
    param_1[0x17] = 0;
    lVar4 = param_2[0xf];
  }
  else {
    lVar4 = devm_kmalloc(*param_2,(ulong)*(uint *)((long)param_1 + 0x24) << 4,0xdc0);
    param_1[0x17] = lVar4;
    if (lVar4 != 0) {
      iVar1 = cqhci_qti_crypto_init(param_1);
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 3) = 0;
        *(undefined4 *)(param_1 + 0x10) = 0;
        __init_swait_queue_head(param_1 + 0x11,"&x->wait",&init_completion___key);
        __init_waitqueue_head(param_1 + 0x14,"&cq_host->wait_queue",&cqhci_init___key);
        lVar4 = param_2[0xf];
        if (lVar4 == 0) {
          lVar4 = param_2[1];
        }
        pcVar5 = *(code **)(*param_1 + 0x10);
        if (pcVar5 == (code *)0x0) {
          uVar2 = readl_relaxed(param_1[1]);
        }
        else {
          if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101eec);
            (*pcVar5)();
          }
          uVar2 = (*pcVar5)(param_1,0);
        }
        pcVar5 = *(code **)(*param_1 + 0x10);
        if (pcVar5 == (code *)0x0) {
          uVar3 = readl_relaxed(param_1[1]);
        }
        else {
          if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101f14);
            (*pcVar5)();
          }
          uVar3 = (*pcVar5)(param_1,0);
        }
        _printk(&DAT_0010535c,lVar4,uVar2 >> 8 & 0xf,(uVar3 & 0xf) + (uVar3 >> 4 & 0xf) * 10);
        return 0;
      }
      lVar4 = param_2[0xf];
      if (lVar4 == 0) {
        lVar4 = param_2[1];
      }
      _printk(&DAT_001052cc,lVar4);
      lVar4 = param_2[0xf];
      goto joined_r0x00101df4;
    }
    lVar4 = param_2[0xf];
  }
  iVar1 = -0xc;
joined_r0x00101df4:
  if (lVar4 == 0) {
    lVar4 = param_2[1];
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar2 = readl_relaxed(param_1[1]);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101e9c);
      (*pcVar5)();
    }
    uVar2 = (*pcVar5)(param_1,0);
  }
  pcVar5 = *(code **)(*param_1 + 0x10);
  if (pcVar5 == (code *)0x0) {
    uVar3 = readl_relaxed(param_1[1]);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101ec4);
      (*pcVar5)();
    }
    uVar3 = (*pcVar5)(param_1,0);
  }
  _printk(&DAT_00105128,lVar4,uVar2 >> 8 & 0xf,(uVar3 & 0xf) + (uVar3 >> 4 & 0xf) * 10,iVar1);
  return iVar1;
}



//------------------------------------------------------------
// readl_relaxed @ 00101f1c size=124
// signature: undefined readl_relaxed(void)
// callers: [cqhci_deactivate, cqhci_irq, cqhci_clear_all_tasks, __cqhci_enable, cqhci_recovery_finish, cqhci_dumpregs, cqhci_disable, cqhci_init, cqhci_request, cqhci_off, cqhci_halt, cqhci_enable]
//------------------------------------------------------------

undefined4 readl_relaxed(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x20,param_1,0x101f64,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 00101f98 size=132
// signature: undefined writel_relaxed(void)
// callers: [cqhci_deactivate, cqhci_irq, __cqhci_enable, cqhci_recovery_finish, cqhci_disable, cqhci_request, cqhci_off, cqhci_halt, cqhci_enable, cqhci_clear_all_tasks]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x101fb0,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x101fec,uVar1);
  return;
}



//------------------------------------------------------------
// cqhci_enable @ 00102020 size=756
// signature: undefined cqhci_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 cqhci_enable(long param_1,long param_2)

{
  undefined1 *__s;
  uint uVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  long lVar5;
  int iVar6;
  code *pcVar7;
  int iVar8;
  int iVar9;
  undefined8 *puVar10;
  undefined8 uVar11;
  long *plVar12;
  
  if (*(char *)(param_2 + 0x4f2) == '\0') {
    uVar11 = 0xffffffea;
  }
  else {
    plVar12 = *(long **)(param_1 + 0x5f8);
    if ((char)plVar12[7] == '\0') {
      *(undefined4 *)((long)plVar12 + 0x1c) = *(undefined4 *)(param_2 + 0x39c);
      if ((*(byte *)(plVar12 + 6) & 1) == 0) {
        iVar6 = 8;
      }
      else {
        pcVar7 = *(code **)(*plVar12 + 0x10);
        if (pcVar7 == (code *)0x0) {
          uVar4 = readl_relaxed(plVar12[1] + 8);
        }
        else {
          if (*(int *)(pcVar7 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x1022e0);
            (*pcVar7)();
          }
          uVar4 = (*pcVar7)(plVar12,8);
        }
        pcVar7 = *(code **)(*plVar12 + 8);
        if (pcVar7 == (code *)0x0) {
          writel_relaxed(uVar4 | 0x100,plVar12[1] + 8);
        }
        else {
          if (*(int *)(pcVar7 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x8229,0x10230c);
            (*pcVar7)();
          }
          (*pcVar7)(plVar12,uVar4 | 0x100,8);
        }
        iVar6 = 0x10;
      }
      *(char *)((long)plVar12 + 0x59) = (char)iVar6;
      if ((char)plVar12[4] == '\0') {
        iVar8 = 8;
        iVar9 = 8;
      }
      else {
        iVar9 = 0x10;
        iVar8 = 0x10;
        if ((*(byte *)((long)plVar12 + 0x34) & 1) != 0) {
          iVar8 = 0xc;
        }
      }
      *(char *)((long)plVar12 + 0x5a) = (char)iVar9;
      puVar10 = (undefined8 *)plVar12[2];
      *(char *)(plVar12 + 0xd) = (char)iVar8;
      *(char *)(plVar12 + 0xb) = (char)(iVar9 + iVar6);
      lVar5 = (long)(*(int *)((long)plVar12 + 0x24) * (iVar9 + iVar6));
      plVar12[8] = lVar5;
      plVar12[9] = (ulong)((uint)*(byte *)(puVar10 + 0xc0) * iVar8) *
                   (ulong)*(ushort *)(puVar10 + 0x7f);
      lVar5 = dmam_alloc_attrs(*puVar10,lVar5,plVar12 + 0xe,0xcc0,0);
      plVar12[10] = lVar5;
      if (lVar5 != 0) {
        lVar5 = dmam_alloc_attrs(*(undefined8 *)plVar12[2],plVar12[9],plVar12 + 0xf,0xcc0,0);
        plVar12[0xc] = lVar5;
        if (lVar5 != 0) {
          if (0 < *(int *)((long)plVar12 + 0x24)) {
            uVar4 = 0;
            do {
              uVar1 = uVar4 & 0xff;
              bVar2 = *(byte *)(plVar12 + 0xd);
              __s = (undefined1 *)
                    (plVar12[10] + (ulong)*(byte *)(plVar12 + 0xb) * (ulong)uVar1 +
                    (ulong)*(byte *)((long)plVar12 + 0x59));
              uVar3 = *(ushort *)(plVar12[2] + 0x3f8);
              lVar5 = plVar12[0xf];
              memset(__s,0,(ulong)*(byte *)((long)plVar12 + 0x5a));
              if (8 < *(byte *)((long)plVar12 + 0x5a)) {
                __s[8] = 0;
              }
              if ((uVar1 == 0x1f) && ((*(byte *)(plVar12[2] + 0x3eb) & 1) != 0)) {
                *__s = 2;
              }
              else {
                *__s = 0x31;
                lVar5 = lVar5 + (int)(uVar1 * bVar2 * (uint)uVar3);
                if ((char)plVar12[4] == '\0') {
                  *(int *)(__s + 4) = (int)lVar5;
                }
                else {
                  *(long *)(__s + 4) = lVar5;
                }
              }
              uVar4 = uVar4 + 1;
            } while ((int)uVar4 < *(int *)((long)plVar12 + 0x24));
          }
          __cqhci_enable(plVar12);
          pcVar7 = *(code **)(*plVar12 + 0x48);
          if (pcVar7 != (code *)0x0) {
            if (*(int *)(pcVar7 + -4) != -0x244f0d8a) {
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x102248);
              (*pcVar7)();
            }
            (*pcVar7)(param_1,1);
          }
          *(undefined1 *)(plVar12 + 7) = 1;
          return 0;
        }
        dmam_free_coherent(*(undefined8 *)plVar12[2],plVar12[8],plVar12[10],plVar12[0xe]);
        plVar12[10] = 0;
        plVar12[0xe] = 0;
      }
      lVar5 = *(long *)(param_1 + 0x78);
      if (lVar5 == 0) {
        lVar5 = *(long *)(param_1 + 8);
      }
      uVar11 = 0xfffffff4;
      _printk(&DAT_00104c6c,lVar5,0xfffffff4);
    }
    else {
      uVar11 = 0;
    }
  }
  return uVar11;
}



//------------------------------------------------------------
// cqhci_disable @ 00102318 size=304
// signature: undefined cqhci_disable(void)
// callers: []
//------------------------------------------------------------

void cqhci_disable(undefined8 *param_1)

{
  uint uVar1;
  code *pcVar2;
  long *plVar3;
  
  plVar3 = (long *)param_1[0xbf];
  if ((char)plVar3[7] != '\0') {
    cqhci_off();
    pcVar2 = *(code **)(*plVar3 + 0x10);
    if (pcVar2 == (code *)0x0) {
      uVar1 = readl_relaxed(plVar3[1] + 8);
    }
    else {
      if (*(int *)(pcVar2 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102414);
        (*pcVar2)();
      }
      uVar1 = (*pcVar2)(plVar3,8);
    }
    pcVar2 = *(code **)(*plVar3 + 8);
    if (pcVar2 == (code *)0x0) {
      writel_relaxed(uVar1 & 0xfffffffe,plVar3[1] + 8);
    }
    else {
      if (*(int *)(pcVar2 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x102440);
        (*pcVar2)();
      }
      (*pcVar2)(plVar3,uVar1 & 0xfffffffe,8);
    }
    *(undefined1 *)(plVar3[2] + 0x605) = 0;
    *(undefined1 *)((long)plVar3 + 0x3b) = 0;
    pcVar2 = *(code **)(*plVar3 + 0x48);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x244f0d8a) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1023ac);
        (*pcVar2)();
      }
      (*pcVar2)(param_1,0);
    }
    dmam_free_coherent(*param_1,plVar3[9],plVar3[0xc],plVar3[0xf]);
    dmam_free_coherent(*param_1,plVar3[8],plVar3[10],plVar3[0xe]);
    plVar3[0xc] = 0;
    plVar3[10] = 0;
    *(undefined1 *)(plVar3 + 7) = 0;
  }
  return;
}



//------------------------------------------------------------
// cqhci_request @ 0010244c size=1400
// signature: undefined cqhci_request(void)
// callers: []
//------------------------------------------------------------

int cqhci_request(undefined8 *param_1,long param_2)

{
  uint uVar1;
  char cVar2;
  long lVar3;
  int iVar4;
  ulong uVar5;
  undefined4 uVar6;
  long lVar7;
  ulong *puVar8;
  undefined8 uVar9;
  uint uVar10;
  code *pcVar11;
  long *plVar12;
  uint *puVar13;
  long *plVar14;
  ulong uVar15;
  ulong local_70;
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  if (*(long *)(param_2 + 8) == 0) {
    uVar15 = (ulong)*(uint *)(param_2 + 0x7c);
  }
  else {
    uVar15 = 0x1f;
  }
  plVar12 = (long *)param_1[0xbf];
  if ((char)plVar12[7] == '\0') {
    lVar7 = param_1[0xf];
    if (lVar7 == 0) {
      lVar7 = param_1[1];
    }
    _printk(&DAT_001050fc,lVar7);
    iVar4 = -0x16;
    goto LAB_001028bc;
  }
  if (*(char *)((long)plVar12 + 0x3b) == '\0') {
    __cqhci_enable(plVar12);
    cVar2 = *(char *)((long)param_1 + 0x605);
  }
  else {
    cVar2 = *(char *)((long)param_1 + 0x605);
  }
  if (cVar2 == '\0') {
    lVar7 = *plVar12;
    pcVar11 = *(code **)(lVar7 + 0x30);
    if (pcVar11 != (code *)0x0) {
      if (*(int *)(pcVar11 + -4) != 0x3af16e59) {
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x8229,0x1024f0);
        (*pcVar11)();
      }
      (*pcVar11)(param_1);
      lVar7 = *plVar12;
    }
    pcVar11 = *(code **)(lVar7 + 8);
    if (pcVar11 == (code *)0x0) {
      writel_relaxed(0,plVar12[1] + 0xc);
    }
    else {
      if (*(int *)(pcVar11 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x10291c);
        (*pcVar11)();
      }
      (*pcVar11)(plVar12,0,0xc);
    }
    *(undefined1 *)((long)param_1 + 0x605) = 1;
    pcVar11 = *(code **)(*plVar12 + 0x10);
    if (pcVar11 == (code *)0x0) {
      uVar5 = readl_relaxed(plVar12[1] + 0xc);
    }
    else {
      if (*(int *)(pcVar11 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x102944);
        (*pcVar11)();
      }
      uVar5 = (*pcVar11)(plVar12,0xc);
    }
    if ((uVar5 & 1) != 0) {
      lVar7 = param_1[0xf];
      if (lVar7 == 0) {
        lVar7 = param_1[1];
      }
      _printk(&DAT_00105207,lVar7);
    }
    pcVar11 = *(code **)(*plVar12 + 0x18);
    if (pcVar11 != (code *)0x0) {
      if (*(int *)(pcVar11 + -4) != 0x3af16e59) {
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x10255c);
        (*pcVar11)();
      }
      (*pcVar11)(param_1);
    }
  }
  lVar7 = *(long *)(param_2 + 0x10);
  if (lVar7 == 0) {
    plVar14 = (long *)param_1[0xbf];
    local_70 = 0;
    uVar1 = *(uint *)(*(long *)(param_2 + 8) + 0x18);
    puVar8 = (ulong *)(plVar14[10] +
                      (ulong)*(byte *)(plVar14 + 0xb) * (ulong)*(byte *)((long)plVar14 + 0x2c));
    uVar5 = (ulong)uVar1 & 1;
    uVar10 = 0x1000000;
    if ((uVar1 & 0x1d) != 0) {
      uVar10 = 0x1800000;
    }
    uVar1 = 0;
    if ((int)uVar5 != 0) {
      uVar1 = uVar10;
    }
    memset(puVar8,0,(ulong)*(byte *)((long)plVar14 + 0x59));
    local_70 = local_70 |
               (uVar5 << 0x16 | ((ulong)**(uint **)(param_2 + 8) & 0x3f) << 0x10 | (ulong)uVar1) ^
               0x40402f;
    pcVar11 = *(code **)(*plVar14 + 0x28);
    if (pcVar11 != (code *)0x0) {
      if (*(int *)(pcVar11 + -4) != 0x3f6be510) {
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x8229,0x102744);
        (*pcVar11)();
      }
      (*pcVar11)(param_1,param_2,&local_70);
    }
    *puVar8 = *puVar8 | local_70;
    *(ulong *)((long)puVar8 + 4) = (ulong)*(uint *)(*(long *)(param_2 + 8) + 4);
LAB_00102764:
    plVar14 = plVar12 + 3;
    uVar9 = _raw_spin_lock_irqsave(plVar14);
    if (*(char *)((long)plVar12 + 0x3d) == '\0') {
      uVar5 = -(uVar15 >> 0x1f) & 0xfffffff000000000 | uVar15 << 4;
      *(long *)(plVar12[0x17] + uVar5) = param_2;
      *(undefined4 *)(plVar12[0x17] + uVar5 + 8) = 0;
      *(int *)(plVar12 + 5) = (int)plVar12[5] + 1;
      DataSynchronizationBarrier(3,2,0);
      pcVar11 = *(code **)(*plVar12 + 8);
      iVar4 = 1 << (ulong)((uint)uVar15 & 0x1f);
      if (pcVar11 == (code *)0x0) {
        writel_relaxed(iVar4,plVar12[1] + 0x28);
      }
      else {
        if (*(int *)(pcVar11 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x8229,0x10298c);
          (*pcVar11)();
        }
        (*pcVar11)(plVar12,iVar4,0x28);
      }
      pcVar11 = *(code **)(*plVar12 + 0x10);
      if (pcVar11 == (code *)0x0) {
        readl_relaxed(plVar12[1] + 0x28);
      }
      else {
        if (*(int *)(pcVar11 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x1029b4);
          (*pcVar11)();
        }
        (*pcVar11)(plVar12,0x28);
      }
      _raw_spin_unlock_irqrestore(plVar14,uVar9);
      iVar4 = 0;
    }
    else {
      _raw_spin_unlock_irqrestore(plVar14,uVar9);
      lVar7 = *(long *)(param_2 + 0x10);
      if (lVar7 != 0) {
        uVar6 = 1;
        if ((*(uint *)(lVar7 + 0x18) & 0x200) != 0) {
          uVar6 = 2;
        }
        dma_unmap_sg_attrs(*param_1,*(undefined8 *)(lVar7 + 0x38),*(undefined4 *)(lVar7 + 0x30),
                           uVar6,0);
      }
      iVar4 = -0x10;
    }
  }
  else {
    uVar1 = *(uint *)(lVar7 + 0x18);
    uVar10 = (uint)uVar15 & 0xff;
    puVar8 = (ulong *)(plVar12[10] + (ulong)*(byte *)(plVar12 + 0xb) * (ulong)uVar10);
    *puVar8 = (ulong)(uVar1 >> 8) & 0x40 | (ulong)(uVar1 >> 2) & 0x800 |
              ((ulong)(uVar1 >> 9) & 1) << 0xc | ((ulong)(uVar1 >> 0xb) & 1) << 0xd |
              ((ulong)(uVar1 >> 10) & 1) << 0xe | (ulong)(uint)(*(int *)(lVar7 + 0xc) << 0x10) |
              (ulong)*(uint *)(lVar7 + 0x10) << 0x20 | 0x2f;
    if ((*(byte *)(plVar12 + 6) & 1) != 0) {
      uVar5 = 0;
      if (*(long *)(param_2 + 0x80) != 0) {
        uVar5 = *(ulong *)(*(long *)(param_2 + 0x80) + 8);
        if (uVar5 >> 0x20 != 0) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x800,0x1029c0);
          (*pcVar11)();
        }
        uVar5 = uVar5 | (ulong)*(uint *)(param_2 + 0x88) << 0x20 | 0x800000000000;
      }
      puVar8[1] = uVar5;
    }
    lVar7 = *(long *)(param_2 + 0x10);
    if (lVar7 == 0) {
      iVar4 = -0x16;
    }
    else {
      uVar6 = 1;
      if ((*(uint *)(lVar7 + 0x18) & 0x100) == 0) {
        uVar6 = 2;
      }
      lVar3 = plVar12[4];
      iVar4 = dma_map_sg_attrs(**(undefined8 **)(param_2 + 0x70),*(undefined8 *)(lVar7 + 0x38),
                               *(undefined4 *)(lVar7 + 0x30),uVar6,0);
      if (iVar4 == 0) {
        _printk(&DAT_00105116,"cqhci_dma_map",*(undefined4 *)(lVar7 + 0x30));
        iVar4 = -0xc;
      }
      else if (-1 < iVar4) {
        lVar7 = *(long *)(lVar7 + 0x38);
        puVar13 = (uint *)(plVar12[0xc] +
                          (long)(int)(uVar10 * *(byte *)(plVar12 + 0xd) *
                                     (uint)*(ushort *)(plVar12[2] + 0x3f8)));
        do {
          uVar10 = 0x23;
          if (iVar4 != 1) {
            uVar10 = 0x21;
          }
          uVar9 = *(undefined8 *)(lVar7 + 0x10);
          *puVar13 = uVar10 | *(int *)(lVar7 + 0x18) << 0x10;
          if ((char)lVar3 == '\0') {
            puVar13[1] = (uint)uVar9;
          }
          else {
            *(undefined8 *)(puVar13 + 1) = uVar9;
          }
          puVar13 = (uint *)((long)puVar13 + (ulong)*(byte *)(plVar12 + 0xd));
          lVar7 = sg_next();
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        goto LAB_00102764;
      }
    }
    lVar7 = *(long *)(*(long *)(param_2 + 0x70) + 0x78);
    if (lVar7 == 0) {
      lVar7 = *(long *)(*(long *)(param_2 + 0x70) + 8);
    }
    _printk(&DAT_00104da1,lVar7,"cqhci_prep_tran_desc",iVar4);
    lVar7 = param_1[0xf];
    if (lVar7 == 0) {
      lVar7 = param_1[1];
    }
    _printk(&DAT_00104ce8,lVar7,iVar4);
  }
LAB_001028bc:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// cqhci_post_req @ 001029d4 size=68
// signature: undefined cqhci_post_req(void)
// callers: []
//------------------------------------------------------------

void cqhci_post_req(undefined8 *param_1,long param_2)

{
  long lVar1;
  undefined4 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x10);
  if (lVar1 != 0) {
    uVar2 = 1;
    if ((*(uint *)(lVar1 + 0x18) & 0x200) != 0) {
      uVar2 = 2;
    }
    dma_unmap_sg_attrs(*param_1,*(undefined8 *)(lVar1 + 0x38),*(undefined4 *)(lVar1 + 0x30),uVar2,0)
    ;
  }
  return;
}



//------------------------------------------------------------
// cqhci_off @ 00102a1c size=440
// signature: undefined cqhci_off(void)
// callers: [cqhci_disable]
//------------------------------------------------------------

void cqhci_off(long param_1)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  long *plVar5;
  
  plVar5 = *(long **)(param_1 + 0x5f8);
  if ((((char)plVar5[7] != '\0') && (*(char *)(param_1 + 0x605) != '\0')) &&
     (*(char *)((long)plVar5 + 0x3d) == '\0')) {
    lVar3 = *plVar5;
    pcVar4 = *(code **)(lVar3 + 0x20);
    if (pcVar4 != (code *)0x0) {
      if (*(int *)(pcVar4 + -4) != -0x244f0d8a) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x102a7c);
        (*pcVar4)();
      }
      (*pcVar4)(param_1,0);
      lVar3 = *plVar5;
    }
    pcVar4 = *(code **)(lVar3 + 8);
    if (pcVar4 == (code *)0x0) {
      writel_relaxed(1,plVar5[1] + 0xc);
    }
    else {
      if (*(int *)(pcVar4 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x102b88);
        (*pcVar4)();
      }
      (*pcVar4)(plVar5,1,0xc);
    }
    lVar3 = ktime_get();
    while( true ) {
      pcVar4 = *(code **)(*plVar5 + 0x10);
      if (pcVar4 == (code *)0x0) {
        uVar1 = readl_relaxed(plVar5[1] + 0xc);
      }
      else {
        if (*(int *)(pcVar4 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x102af8);
          (*pcVar4)();
        }
        uVar1 = (*pcVar4)(plVar5,0xc);
      }
      if ((uVar1 & 1) != 0) goto joined_r0x00102bb4;
      lVar2 = ktime_get();
      if (lVar3 + 100000 < lVar2) break;
      Yield();
    }
    pcVar4 = *(code **)(*plVar5 + 0x10);
    if (pcVar4 == (code *)0x0) {
      uVar1 = readl_relaxed(plVar5[1] + 0xc);
    }
    else {
      if (*(int *)(pcVar4 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x102bb0);
        (*pcVar4)();
      }
      uVar1 = (*pcVar4)(plVar5,0xc);
    }
joined_r0x00102bb4:
    if ((uVar1 & 1) == 0) {
      lVar3 = *(long *)(param_1 + 0x78);
      if (lVar3 == 0) {
        lVar3 = *(long *)(param_1 + 8);
      }
      _printk(&DAT_00104fc0,lVar3);
    }
    pcVar4 = *(code **)(*plVar5 + 0x38);
    if (pcVar4 != (code *)0x0) {
      if (*(int *)(pcVar4 + -4) != 0x3af16e59) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x102b48);
        (*pcVar4)();
      }
      (*pcVar4)(param_1);
    }
    *(undefined1 *)(param_1 + 0x605) = 0;
  }
  return;
}



//------------------------------------------------------------
// cqhci_wait_for_idle @ 00102bd8 size=296
// signature: undefined cqhci_wait_for_idle(void)
// callers: []
//------------------------------------------------------------

undefined4 cqhci_wait_for_idle(long param_1)

{
  long lVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  long lVar7;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  lVar7 = *(long *)(param_1 + 0x5f8);
  lVar1 = lVar7 + 0x18;
  uVar5 = _raw_spin_lock_irqsave(lVar1);
  bVar3 = *(int *)(lVar7 + 0x28) != 0;
  bVar4 = *(char *)(lVar7 + 0x3d) == '\0';
  uVar6 = 0;
  if (!bVar4) {
    uVar6 = 0xfffffff0;
  }
  *(bool *)(lVar7 + 0x3c) = bVar4 && bVar3;
  _raw_spin_unlock_irqrestore(lVar1,uVar5);
  if (bVar4 && bVar3) {
    local_58 = 0;
    uStack_50 = 0;
    local_68 = 0;
    uStack_60 = 0;
    local_70 = 0;
    init_wait_entry(&local_70,0);
    while( true ) {
      prepare_to_wait_event(lVar7 + 0xa0,&local_70,2);
      uVar5 = _raw_spin_lock_irqsave(lVar1);
      cVar2 = *(char *)(lVar7 + 0x3d);
      bVar3 = *(int *)(lVar7 + 0x28) != 0;
      *(bool *)(lVar7 + 0x3c) = bVar3 && cVar2 == '\0';
      _raw_spin_unlock_irqrestore(lVar1,uVar5);
      if (!bVar3 || cVar2 != '\0') break;
      schedule();
    }
    uVar6 = 0;
    if (cVar2 != '\0') {
      uVar6 = 0xfffffff0;
    }
    finish_wait(lVar7 + 0xa0,&local_70);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// cqhci_timeout @ 00102d04 size=280
// signature: undefined cqhci_timeout(void)
// callers: []
//------------------------------------------------------------

bool cqhci_timeout(long param_1,long param_2,undefined1 *param_3)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  
  lVar3 = *(long *)(param_1 + 0x5f8);
  if (*(long *)(param_2 + 8) == 0) {
    uVar4 = (ulong)*(uint *)(param_2 + 0x7c);
  }
  else {
    uVar4 = 0x1f;
  }
  lVar2 = lVar3 + 0x18;
  lVar6 = *(long *)(lVar3 + 0xb8);
  uVar1 = _raw_spin_lock_irqsave(lVar2);
  lVar5 = *(long *)(lVar6 + (-(uVar4 >> 0x1f) & 0xfffffff000000000 | uVar4 << 4));
  if (lVar5 == param_2) {
    lVar6 = lVar6 + (long)(int)uVar4 * 0x10;
    *(uint *)(lVar6 + 8) = *(uint *)(lVar6 + 8) | 1;
    lVar6 = *(long *)(param_1 + 0x5f8);
    if (*(char *)(lVar6 + 0x3d) == '\0') {
      *(undefined1 *)(lVar6 + 0x3d) = 1;
      __wake_up(lVar6 + 0xa0,3,1,0);
    }
    *param_3 = *(undefined1 *)(lVar3 + 0x3d);
    _raw_spin_unlock_irqrestore(lVar2,uVar1);
    lVar2 = *(long *)(param_1 + 0x78);
    if (lVar2 == 0) {
      lVar2 = *(long *)(param_1 + 8);
    }
    _printk(&DAT_0010500e,lVar2,uVar4,*(undefined4 *)(lVar3 + 0x28));
    cqhci_dumpregs(lVar3);
  }
  else {
    _raw_spin_unlock_irqrestore(lVar2,uVar1);
  }
  return lVar5 == param_2;
}



//------------------------------------------------------------
// cqhci_recovery_start @ 00102e20 size=116
// signature: undefined cqhci_recovery_start(void)
// callers: []
//------------------------------------------------------------

void cqhci_recovery_start(long param_1)

{
  code *pcVar1;
  long *plVar2;
  
  plVar2 = *(long **)(param_1 + 0x5f8);
  if (*(char *)((long)plVar2 + 0x3d) == '\0') {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x102e94);
    (*pcVar1)();
  }
  cqhci_halt(param_1,500);
  pcVar1 = *(code **)(*plVar2 + 0x20);
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != -0x244f0d8a) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102e78);
      (*pcVar1)();
    }
    (*pcVar1)(param_1,1);
  }
  *(undefined1 *)(param_1 + 0x605) = 0;
  return;
}



//------------------------------------------------------------
// cqhci_recovery_finish @ 00102e9c size=864
// signature: undefined cqhci_recovery_finish(void)
// callers: []
//------------------------------------------------------------

void cqhci_recovery_finish(long param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  int iVar6;
  code *pcVar7;
  long lVar8;
  long lVar9;
  long *plVar10;
  long lVar11;
  long lVar12;
  undefined4 uVar13;
  
  plVar10 = *(long **)(param_1 + 0x5f8);
  if (*(char *)((long)plVar10 + 0x3d) == '\0') {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x800,0x1030cc);
    (*pcVar7)();
  }
  uVar1 = cqhci_halt(param_1,0x14);
  uVar2 = cqhci_clear_all_tasks(param_1);
  pcVar7 = *(code **)(*plVar10 + 0x10);
  if (pcVar7 == (code *)0x0) {
    uVar3 = readl_relaxed(plVar10[1] + 8);
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x1030f0);
      (*pcVar7)();
    }
    uVar3 = (*pcVar7)(plVar10,8);
  }
  pcVar7 = *(code **)(*plVar10 + 8);
  if (pcVar7 == (code *)0x0) {
    writel_relaxed(uVar3 & 0xfffffffe,plVar10[1] + 8);
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8229,0x10311c);
      (*pcVar7)();
    }
    (*pcVar7)(plVar10,uVar3 & 0xfffffffe,8);
  }
  pcVar7 = *(code **)(*plVar10 + 0x10);
  if (pcVar7 == (code *)0x0) {
    uVar3 = readl_relaxed(plVar10[1] + 8);
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x103144);
      (*pcVar7)();
    }
    uVar3 = (*pcVar7)(plVar10,8);
  }
  pcVar7 = *(code **)(*plVar10 + 8);
  if (pcVar7 == (code *)0x0) {
    writel_relaxed(uVar3 | 1,plVar10[1] + 8);
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8229,0x103170);
      (*pcVar7)();
    }
    (*pcVar7)(plVar10,uVar3 | 1,8);
  }
  cqhci_halt(param_1,0x14);
  if ((uVar2 & uVar1 & 1) == 0) {
    cqhci_clear_all_tasks(param_1);
  }
  iVar6 = *(int *)((long)plVar10 + 0x24);
  if (0 < iVar6) {
    lVar11 = 0;
    lVar12 = 0;
    do {
      lVar9 = plVar10[0x17];
      lVar5 = *(long *)(lVar9 + lVar11);
      if (lVar5 != 0) {
        *(undefined8 *)(lVar9 + lVar11) = 0;
        *(int *)(plVar10 + 5) = (int)plVar10[5] + -1;
        lVar8 = *(long *)(lVar5 + 0x10);
        if (lVar8 == 0) {
          uVar1 = *(uint *)(lVar9 + lVar11 + 8);
          uVar13 = 0;
          if (uVar1 != 0) {
            if ((uVar1 >> 2 & 1) == 0) {
              uVar13 = 0xfffffffb;
              if ((uVar1 & 9) != 0) {
                uVar13 = 0xffffff92;
              }
            }
            else {
              uVar13 = 0xffffffac;
            }
          }
          *(undefined4 *)(*(long *)(lVar5 + 8) + 0x20) = uVar13;
        }
        else {
          *(undefined4 *)(lVar8 + 0x1c) = 0;
          uVar1 = *(uint *)(lVar9 + lVar11 + 8);
          uVar13 = 0;
          if (uVar1 != 0) {
            if ((uVar1 >> 2 & 1) == 0) {
              uVar13 = 0xfffffffb;
              if ((uVar1 & 9) != 0) {
                uVar13 = 0xffffff92;
              }
            }
            else {
              uVar13 = 0xffffffac;
            }
          }
          *(undefined4 *)(lVar8 + 0x14) = uVar13;
        }
        mmc_cqe_request_done(plVar10[2]);
        iVar6 = *(int *)((long)plVar10 + 0x24);
      }
      lVar12 = lVar12 + 1;
      lVar11 = lVar11 + 0x10;
    } while (lVar12 < iVar6);
  }
  if ((int)plVar10[5] != 0) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x800,0x10317c);
    (*pcVar7)();
  }
  uVar4 = _raw_spin_lock_irqsave(plVar10 + 3);
  *(undefined4 *)(plVar10 + 5) = 0;
  *(undefined1 *)((long)plVar10 + 0x3d) = 0;
  *(undefined1 *)(param_1 + 0x605) = 0;
  _raw_spin_unlock_irqrestore(plVar10 + 3,uVar4);
  DataSynchronizationBarrier(3,2,0);
  pcVar7 = *(code **)(*plVar10 + 8);
  if (pcVar7 == (code *)0x0) {
    writel_relaxed(9,plVar10[1] + 0x10);
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x1031a4);
      (*pcVar7)();
    }
    (*pcVar7)(plVar10,9,0x10);
  }
  pcVar7 = *(code **)(*plVar10 + 8);
  if (pcVar7 == (code *)0x0) {
    writel_relaxed(0x36,plVar10[1] + 0x14);
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x1031d0);
      (*pcVar7)();
    }
    (*pcVar7)(plVar10,0x36,0x14);
  }
  pcVar7 = *(code **)(*plVar10 + 8);
  if (pcVar7 == (code *)0x0) {
    writel_relaxed(0x36,plVar10[1] + 0x18);
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x1031fc);
      (*pcVar7)();
    }
    (*pcVar7)(plVar10,0x36,0x18);
  }
  return;
}



//------------------------------------------------------------
// __cqhci_enable @ 00103204 size=1200
// signature: undefined __cqhci_enable(void)
// callers: [cqhci_request, cqhci_enable]
//------------------------------------------------------------

void __cqhci_enable(long *param_1)

{
  uint uVar1;
  ulong uVar2;
  code *pcVar3;
  long lVar4;
  
  lVar4 = param_1[2];
  pcVar3 = *(code **)(*param_1 + 0x10);
  if (pcVar3 == (code *)0x0) {
    uVar1 = readl_relaxed(param_1[1] + 8);
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103464);
      (*pcVar3)();
    }
    uVar1 = (*pcVar3)(param_1,8);
  }
  if ((uVar1 & 1) != 0) {
    uVar1 = uVar1 & 0xfffffffe;
    pcVar3 = *(code **)(*param_1 + 8);
    if (pcVar3 == (code *)0x0) {
      writel_relaxed(uVar1,param_1[1] + 8);
    }
    else {
      if (*(int *)(pcVar3 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103680);
        (*pcVar3)();
      }
      (*pcVar3)(param_1,uVar1,8);
    }
  }
  pcVar3 = *(code **)(*param_1 + 8);
  uVar1 = *(uint *)(lVar4 + 1000) >> 0xc & 0x1000 | uVar1 & 0xffffee00 |
          uVar1 & 0xff | *(uint *)(lVar4 + 1000) >> 0x1a & 2 | (*(uint *)(param_1 + 6) & 1) << 8;
  if (pcVar3 == (code *)0x0) {
    writel_relaxed(uVar1,param_1[1] + 8);
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103498);
      (*pcVar3)();
    }
    (*pcVar3)(param_1,uVar1,8);
  }
  pcVar3 = *(code **)(*param_1 + 8);
  if (pcVar3 == (code *)0x0) {
    writel_relaxed((int)param_1[0xe],param_1[1] + 0x20);
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x1034c4);
      (*pcVar3)();
    }
    (*pcVar3)(param_1,(int)param_1[0xe],0x20);
  }
  pcVar3 = *(code **)(*param_1 + 8);
  if (pcVar3 == (code *)0x0) {
    writel_relaxed(*(undefined4 *)((long)param_1 + 0x74),param_1[1] + 0x24);
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x1034f0);
      (*pcVar3)();
    }
    (*pcVar3)(param_1,*(undefined4 *)((long)param_1 + 0x74),0x24);
  }
  pcVar3 = *(code **)(*param_1 + 8);
  if (pcVar3 == (code *)0x0) {
    writel_relaxed(*(undefined4 *)((long)param_1 + 0x1c),param_1[1] + 0x44);
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x10351c);
      (*pcVar3)();
    }
    (*pcVar3)(param_1,*(undefined4 *)((long)param_1 + 0x1c),0x44);
  }
  pcVar3 = *(code **)(*param_1 + 8);
  if (pcVar3 == (code *)0x0) {
    writel_relaxed(0x70001,param_1[1] + 0x40);
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10354c);
      (*pcVar3)();
    }
    (*pcVar3)(param_1,0x70001,0x40);
  }
  pcVar3 = *(code **)(*param_1 + 8);
  if (pcVar3 == (code *)0x0) {
    writel_relaxed(0,param_1[1] + 0x14);
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103578);
      (*pcVar3)();
    }
    (*pcVar3)(param_1,0,0x14);
  }
  pcVar3 = *(code **)(*param_1 + 8);
  if (pcVar3 == (code *)0x0) {
    writel_relaxed(0,param_1[1] + 0x18);
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1035a4);
      (*pcVar3)();
    }
    (*pcVar3)(param_1,0,0x18);
  }
  pcVar3 = *(code **)(*param_1 + 8);
  if (pcVar3 == (code *)0x0) {
    writel_relaxed(uVar1 | 1,param_1[1] + 8);
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x1035d0);
      (*pcVar3)();
    }
    (*pcVar3)(param_1,uVar1 | 1,8);
  }
  pcVar3 = *(code **)(*param_1 + 0x10);
  if (pcVar3 == (code *)0x0) {
    uVar2 = readl_relaxed(param_1[1] + 0xc);
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1035f8);
      (*pcVar3)();
    }
    uVar2 = (*pcVar3)(param_1,0xc);
  }
  if ((uVar2 & 1) != 0) {
    pcVar3 = *(code **)(*param_1 + 8);
    if (pcVar3 == (code *)0x0) {
      writel_relaxed(0,param_1[1] + 0xc);
    }
    else {
      if (*(int *)(pcVar3 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1036ac);
        (*pcVar3)();
      }
      (*pcVar3)(param_1,0,0xc);
    }
  }
  *(undefined1 *)(lVar4 + 0x605) = 1;
  pcVar3 = *(code **)(*param_1 + 0x18);
  if (pcVar3 != (code *)0x0) {
    if (*(int *)(pcVar3 + -4) != 0x3af16e59) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1033e8);
      (*pcVar3)();
    }
    (*pcVar3)(lVar4);
  }
  DataSynchronizationBarrier(3,2,0);
  pcVar3 = *(code **)(*param_1 + 8);
  if (pcVar3 == (code *)0x0) {
    writel_relaxed(0x36,param_1[1] + 0x14);
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103628);
      (*pcVar3)();
    }
    (*pcVar3)(param_1,0x36,0x14);
  }
  pcVar3 = *(code **)(*param_1 + 8);
  if (pcVar3 == (code *)0x0) {
    writel_relaxed(0x36,param_1[1] + 0x18);
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103654);
      (*pcVar3)();
    }
    (*pcVar3)(param_1,0x36,0x18);
  }
  *(undefined1 *)((long)param_1 + 0x3b) = 1;
  return;
}



//------------------------------------------------------------
// cqhci_halt @ 001036b4 size=972
// signature: undefined cqhci_halt(void)
// callers: [cqhci_recovery_start, cqhci_recovery_finish]
//------------------------------------------------------------

void cqhci_halt(long param_1,undefined4 param_2)

{
  byte bVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  undefined8 uVar5;
  code *pcVar6;
  long *plVar7;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  plVar7 = *(long **)(param_1 + 0x5f8);
  pcVar6 = *(code **)(*plVar7 + 0x10);
  if (pcVar6 == (code *)0x0) {
    uVar3 = readl_relaxed(plVar7[1] + 0xc);
  }
  else {
    if (*(int *)(pcVar6 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1038fc);
      (*pcVar6)();
    }
    uVar3 = (*pcVar6)(plVar7,0xc);
  }
  if ((uVar3 & 1) == 0) {
    pcVar6 = *(code **)(*plVar7 + 8);
    if (pcVar6 == (code *)0x0) {
      writel_relaxed(1,plVar7[1] + 0x14);
    }
    else {
      if (*(int *)(pcVar6 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x10392c);
        (*pcVar6)();
      }
      (*pcVar6)(plVar7,1,0x14);
    }
    pcVar6 = *(code **)(*plVar7 + 8);
    if (pcVar6 == (code *)0x0) {
      writel_relaxed(1,plVar7[1] + 0x18);
    }
    else {
      if (*(int *)(pcVar6 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103958);
        (*pcVar6)();
      }
      (*pcVar6)(plVar7,1,0x18);
    }
    pcVar6 = *(code **)(*plVar7 + 0x10);
    if (pcVar6 == (code *)0x0) {
      uVar2 = readl_relaxed(plVar7[1] + 0xc);
    }
    else {
      if (*(int *)(pcVar6 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103980);
        (*pcVar6)();
      }
      uVar2 = (*pcVar6)(plVar7,0xc);
    }
    pcVar6 = *(code **)(*plVar7 + 8);
    if (pcVar6 == (code *)0x0) {
      writel_relaxed(uVar2 | 1,plVar7[1] + 0xc);
    }
    else {
      if (*(int *)(pcVar6 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8229,0x1039ac);
        (*pcVar6)();
      }
      (*pcVar6)(plVar7,uVar2 | 1,0xc);
    }
    lVar4 = __msecs_to_jiffies(param_2);
    pcVar6 = *(code **)(*plVar7 + 0x10);
    if (pcVar6 == (code *)0x0) {
      uVar3 = readl_relaxed(plVar7[1] + 0xc);
    }
    else {
      if (*(int *)(pcVar6 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1039d4);
        (*pcVar6)();
      }
      uVar3 = (*pcVar6)(plVar7,0xc);
    }
    if (((uVar3 & 1) == 0) && ((uVar3 & 1) != 0 || lVar4 != -1)) {
      local_48 = 0;
      uStack_40 = 0;
      local_58 = 0;
      uStack_50 = 0;
      local_60 = 0;
      lVar4 = __msecs_to_jiffies(param_2);
      lVar4 = lVar4 + 1;
      init_wait_entry(&local_60,0);
      while( true ) {
        prepare_to_wait_event(plVar7 + 0x14,&local_60,2);
        pcVar6 = *(code **)(*plVar7 + 0x10);
        if (pcVar6 == (code *)0x0) {
          bVar1 = readl_relaxed(plVar7[1] + 0xc);
        }
        else {
          if (*(int *)(pcVar6 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103844);
            (*pcVar6)();
          }
          bVar1 = (*pcVar6)(plVar7,0xc);
        }
        if ((bVar1 & 1 & lVar4 == 0) != 0) {
          lVar4 = 1;
        }
        if (((bVar1 & 1) != 0) || (lVar4 == 0)) break;
        lVar4 = schedule_timeout(lVar4);
      }
      finish_wait(plVar7 + 0x14,&local_60);
    }
    pcVar6 = *(code **)(*plVar7 + 8);
    if (pcVar6 == (code *)0x0) {
      writel_relaxed(0,plVar7[1] + 0x14);
    }
    else {
      if (*(int *)(pcVar6 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103a00);
        (*pcVar6)();
      }
      (*pcVar6)(plVar7,0,0x14);
    }
    pcVar6 = *(code **)(*plVar7 + 8);
    if (pcVar6 == (code *)0x0) {
      writel_relaxed(0,plVar7[1] + 0x18);
    }
    else {
      if (*(int *)(pcVar6 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103a2c);
        (*pcVar6)();
      }
      (*pcVar6)(plVar7,0,0x18);
    }
    pcVar6 = *(code **)(*plVar7 + 0x10);
    if (pcVar6 == (code *)0x0) {
      uVar3 = readl_relaxed(plVar7[1] + 0xc);
    }
    else {
      if (*(int *)(pcVar6 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103a54);
        (*pcVar6)();
      }
      uVar3 = (*pcVar6)(plVar7,0xc);
    }
    if ((uVar3 & 1) == 0) {
      lVar4 = *(long *)(param_1 + 0x78);
      if (lVar4 == 0) {
        lVar4 = *(long *)(param_1 + 8);
      }
      _printk(&DAT_00105379,lVar4);
      uVar5 = 0;
      goto LAB_001038b0;
    }
  }
  uVar5 = 1;
LAB_001038b0:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// cqhci_clear_all_tasks @ 00103a80 size=868
// signature: undefined cqhci_clear_all_tasks(void)
// callers: [cqhci_recovery_finish]
//------------------------------------------------------------

void cqhci_clear_all_tasks(long param_1)

{
  uint uVar1;
  code *pcVar2;
  long *plVar3;
  long lVar4;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  plVar3 = *(long **)(param_1 + 0x5f8);
  pcVar2 = *(code **)(*plVar3 + 8);
  if (pcVar2 == (code *)0x0) {
    writel_relaxed(8,plVar3[1] + 0x14);
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103c8c);
      (*pcVar2)();
    }
    (*pcVar2)(plVar3,8,0x14);
  }
  pcVar2 = *(code **)(*plVar3 + 8);
  if (pcVar2 == (code *)0x0) {
    writel_relaxed(8,plVar3[1] + 0x18);
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103cb8);
      (*pcVar2)();
    }
    (*pcVar2)(plVar3,8,0x18);
  }
  pcVar2 = *(code **)(*plVar3 + 0x10);
  if (pcVar2 == (code *)0x0) {
    uVar1 = readl_relaxed(plVar3[1] + 0xc);
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103ce0);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)(plVar3,0xc);
  }
  pcVar2 = *(code **)(*plVar3 + 8);
  if (pcVar2 == (code *)0x0) {
    writel_relaxed(uVar1 | 0x100,plVar3[1] + 0xc);
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x103d0c);
      (*pcVar2)();
    }
    (*pcVar2)(plVar3,uVar1 | 0x100,0xc);
  }
  pcVar2 = *(code **)(*plVar3 + 0x10);
  if (pcVar2 == (code *)0x0) {
    uVar1 = readl_relaxed(plVar3[1] + 0xc);
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103d34);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)(plVar3,0xc);
  }
  if ((uVar1 >> 8 & 1) != 0) {
    local_48 = 0;
    uStack_40 = 0;
    local_58 = 0;
    uStack_50 = 0;
    local_60 = 0;
    init_wait_entry(&local_60,0);
    lVar4 = 6;
    while( true ) {
      prepare_to_wait_event(plVar3 + 0x14,&local_60,2);
      pcVar2 = *(code **)(*plVar3 + 0x10);
      if (pcVar2 == (code *)0x0) {
        uVar1 = readl_relaxed(plVar3[1] + 0xc);
      }
      else {
        if (*(int *)(pcVar2 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103bc8);
          (*pcVar2)();
        }
        uVar1 = (*pcVar2)(plVar3,0xc);
      }
      if (lVar4 == 0 && (uVar1 & 0x100) == 0) {
        lVar4 = 1;
      }
      if (((uVar1 >> 8 & 1) == 0) || (lVar4 == 0)) break;
      lVar4 = schedule_timeout(lVar4);
    }
    finish_wait(plVar3 + 0x14,&local_60);
  }
  pcVar2 = *(code **)(*plVar3 + 8);
  if (pcVar2 == (code *)0x0) {
    writel_relaxed(0,plVar3[1] + 0x14);
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103d64);
      (*pcVar2)();
    }
    (*pcVar2)(plVar3,0,0x14);
  }
  pcVar2 = *(code **)(*plVar3 + 8);
  if (pcVar2 == (code *)0x0) {
    writel_relaxed(0,plVar3[1] + 0x18);
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103d90);
      (*pcVar2)();
    }
    (*pcVar2)(plVar3,0,0x18);
  }
  pcVar2 = *(code **)(*plVar3 + 0x10);
  if (pcVar2 == (code *)0x0) {
    uVar1 = readl_relaxed(plVar3[1] + 0xc);
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103db8);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)(plVar3,0xc);
  }
  if ((uVar1 >> 8 & 1) != 0) {
    lVar4 = *(long *)(param_1 + 0x78);
    if (lVar4 == 0) {
      lVar4 = *(long *)(param_1 + 8);
    }
    _printk(&DAT_00105197,lVar4);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail((uVar1 & 0x100) == 0);
  }
  return;
}



//------------------------------------------------------------
// cqhci_crypto_init @ 00103dec size=624
// signature: undefined cqhci_crypto_init(void)
// callers: []
//------------------------------------------------------------

void cqhci_crypto_init(long *param_1)

{
  byte bVar1;
  undefined *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  long lVar6;
  code *pcVar7;
  int iVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong uVar11;
  undefined8 *puVar12;
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
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  puVar12 = (undefined8 *)param_1[2];
  if ((*(byte *)((long)puVar12 + 0x3eb) >> 3 & 1) == 0) {
LAB_00103e44:
    uVar5 = 0;
  }
  else {
    uVar9 = *puVar12;
    pcVar7 = *(code **)(*param_1 + 0x10);
    if (pcVar7 != (code *)0x0) {
      if (*(int *)(pcVar7 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x103ea4);
        (*pcVar7)();
      }
      uVar3 = (*pcVar7)(param_1,4);
      if ((uVar3 >> 0x1c & 1) != 0) goto LAB_00103eac;
      goto LAB_00103e44;
    }
    uVar3 = readl_relaxed(param_1[1] + 4);
    if ((uVar3 >> 0x1c & 1) == 0) goto LAB_00103e44;
LAB_00103eac:
    pcVar7 = *(code **)(*param_1 + 0x10);
    if (pcVar7 == (code *)0x0) {
      uVar5 = readl_relaxed(param_1[1] + 0x100);
    }
    else {
      if (*(int *)(pcVar7 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x104050);
        (*pcVar7)();
      }
      uVar5 = (*pcVar7)(param_1,0x100);
    }
    *(uint *)(param_1 + 0x18) = (uint)uVar5;
    *(uint *)(param_1 + 0x1a) = (uint)((ulong)uVar5 >> 0x10) & 0xff00;
    lVar6 = devm_kmalloc(uVar9,((uint)uVar5 & 0xff) << 2,0xdc0);
    param_1[0x19] = lVar6;
    if (lVar6 == 0) {
      uVar5 = 0xfffffff4;
    }
    else {
      bVar1 = *(byte *)((long)param_1 + 0xc1);
      uVar5 = devm_blk_crypto_profile_init(uVar9,puVar12 + 0xc1,bVar1 + 1);
      if ((int)uVar5 == 0) {
        puVar12[200] = uVar9;
        uVar9 = DAT_00105478;
        puVar2 = PTR_cqhci_crypto_keyslot_evict_00105470;
        puVar12[0xc1] = cqhci_crypto_ops;
        puVar12[0xc2] = puVar2;
        puVar12[0xc3] = uVar9;
        puVar12[0xc4] = 0x100000004;
        if ((char)param_1[0x18] != '\0') {
          uVar11 = 0;
          uVar10 = 0x104;
          do {
            pcVar7 = *(code **)(*param_1 + 0x10);
            if (pcVar7 == (code *)0x0) {
              uVar4 = readl_relaxed(param_1[1] + uVar10);
            }
            else {
              if (*(int *)(pcVar7 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
                pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x103fc8);
                (*pcVar7)();
              }
              uVar4 = (*pcVar7)(param_1,uVar10 & 0xffffffff);
            }
            *(undefined4 *)(param_1[0x19] + uVar11 * 4) = uVar4;
            uVar3 = *(uint *)(param_1[0x19] + uVar11 * 4);
            if ((uVar3 & 0xff00ff) == 0x30000) {
              *(uint *)((long)puVar12 + 0x62c) =
                   (uVar3 & 0xff00) << 1 | *(uint *)((long)puVar12 + 0x62c);
            }
            uVar11 = uVar11 + 1;
            uVar10 = uVar10 + 4;
          } while (uVar11 < *(byte *)(param_1 + 0x18));
        }
        iVar8 = 0;
        do {
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
          local_c8 = 0;
          uStack_c0 = 0;
          cqhci_crypto_program_key(param_1,&local_c8,iVar8);
          iVar8 = iVar8 + 1;
        } while (bVar1 + 1 != iVar8);
        uVar5 = 0;
        *(uint *)(param_1 + 6) = *(uint *)(param_1 + 6) | 1;
        goto LAB_00103e54;
      }
    }
  }
  *(uint *)(puVar12 + 0x7d) = *(uint *)(puVar12 + 0x7d) & 0xf7ffffff;
LAB_00103e54:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 0010405c size=124
// signature: undefined readl_relaxed(void)
// callers: [cqhci_crypto_init]
//------------------------------------------------------------

undefined4 readl_relaxed(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x20,param_1,0x1040a4,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// cqhci_crypto_keyslot_program @ 001040dc size=692
// signature: undefined cqhci_crypto_keyslot_program(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cqhci_crypto_keyslot_program(long param_1,uint *param_2,undefined4 param_3)

{
  uint uVar1;
  code *pcVar2;
  undefined8 *__dest;
  size_t __n;
  ulong uVar3;
  byte *pbVar4;
  long lVar5;
  long lVar6;
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
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  uVar1 = *param_2;
  if (5 < uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10438c);
    (*pcVar2)();
  }
  lVar6 = *(long *)(param_1 + -0x10);
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
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  if ((ulong)*(byte *)(lVar6 + 0xc0) != 0) {
    if (4 < uVar1) {
LAB_00104384:
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x104388);
      (*pcVar2)();
    }
    lVar5 = (ulong)uVar1 * 8;
    uVar3 = 0;
    pbVar4 = (byte *)(*(long *)(lVar6 + 200) + 1);
    do {
      if (*(uint *)(cqhci_crypto_algs + lVar5) == (uint)pbVar4[-1]) {
        if (0x28 < ((ulong)uVar1 << 3 | 4)) goto LAB_00104384;
        if ((*(uint *)(cqhci_crypto_algs + lVar5 + 4) == (uint)pbVar4[1]) &&
           ((param_2[1] >> 9 & (uint)*pbVar4) != 0)) {
          if (-1 < (int)uVar3) {
            uVar1 = param_2[5];
            __n = (size_t)uVar1;
            local_78._0_3_ = (uint3)CONCAT11((char)uVar3,(char)(param_2[1] >> 9));
            local_78 = (ulong)CONCAT13(0x80,(uint3)local_78);
            if (pbVar4[-1] == 0) {
              if (uVar1 < 0x102) {
                if ((0x81 < uVar1) && ((cqhci_crypto_keyslot_program___already_done & 1) == 0)) {
                  cqhci_crypto_keyslot_program___already_done = 1;
                  __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n"
                                ,(ulong)(uVar1 >> 1),
                                "field \"cfg.crypto_key\" at drivers/mmc/host/cqhci-crypto.c:95",
                                0x40);
                    /* WARNING: Does not return */
                  pcVar2 = (code *)SoftwareBreakpoint(0x800,0x104348);
                  (*pcVar2)();
                }
                memcpy(&local_b8,param_2 + 6,(ulong)(uVar1 >> 1));
                uVar1 = param_2[5];
                if (uVar1 < 0xc2) {
                  __n = (size_t)(uVar1 >> 1);
                  if ((0x41 < uVar1) && ((cqhci_crypto_keyslot_program___already_done_3 & 1) == 0))
                  {
                    cqhci_crypto_keyslot_program___already_done_3 = 1;
                    __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n"
                                  ,__n,
                                  "field \"cfg.crypto_key + 64/2\" at drivers/mmc/host/cqhci-crypto.c:97"
                                  ,0x20);
                    /* WARNING: Does not return */
                    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x104380);
                    (*pcVar2)();
                  }
                  __dest = &local_98;
                  param_2 = (uint *)((long)(param_2 + 6) + (ulong)(param_2[5] >> 1));
                  goto LAB_00104210;
                }
              }
            }
            else if (uVar1 < 0x81) {
              param_2 = param_2 + 6;
              if ((0x40 < uVar1) && ((cqhci_crypto_keyslot_program___already_done_5 & 1) == 0)) {
                cqhci_crypto_keyslot_program___already_done_5 = 1;
                __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n"
                              ,__n,"field \"cfg.crypto_key\" at drivers/mmc/host/cqhci-crypto.c:99",
                              0x40);
                    /* WARNING: Does not return */
                pcVar2 = (code *)SoftwareBreakpoint(0x800,0x104314);
                (*pcVar2)();
              }
              __dest = &local_b8;
LAB_00104210:
              memcpy(__dest,param_2,__n);
              cqhci_crypto_program_key(lVar6,&local_b8,param_3);
              local_b8 = 0;
              uStack_b0 = 0;
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
              lVar6 = sp_el0;
              if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
                __stack_chk_fail();
              }
              return;
            }
            fortify_panic("memcpy");
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
          break;
        }
      }
      uVar3 = uVar3 + 1;
      pbVar4 = pbVar4 + 4;
    } while (*(byte *)(lVar6 + 0xc0) != uVar3);
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x800,0x104210);
  (*pcVar2)();
}



//------------------------------------------------------------
// cqhci_crypto_keyslot_evict @ 001043a0 size=112
// signature: undefined cqhci_crypto_keyslot_evict(void)
// callers: []
//------------------------------------------------------------

void cqhci_crypto_keyslot_evict(long param_1)

{
  long lVar1;
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
  local_98 = 0;
  uStack_90 = 0;
  cqhci_crypto_program_key(*(undefined8 *)(param_1 + -0x10),&local_98);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// cqhci_crypto_program_key @ 00104410 size=440
// signature: undefined cqhci_crypto_program_key(void)
// callers: [cqhci_crypto_init, cqhci_crypto_keyslot_program, cqhci_crypto_keyslot_evict]
//------------------------------------------------------------

undefined8 cqhci_crypto_program_key(long *param_1,long param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  code *pcVar4;
  long lVar5;
  
  pcVar4 = *(code **)(*param_1 + 0x40);
  if (pcVar4 == (code *)0x0) {
    pcVar4 = *(code **)(*param_1 + 8);
    iVar2 = (int)param_1[0x1a] + param_3 * 0x80;
    iVar1 = iVar2 + 0x40;
    if (pcVar4 == (code *)0x0) {
      writel_relaxed(0,param_1[1] + (long)iVar1);
    }
    else {
      if (*(int *)(pcVar4 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10456c);
        (*pcVar4)();
      }
      (*pcVar4)(param_1,0,iVar1);
    }
    lVar5 = 0;
    do {
      pcVar4 = *(code **)(*param_1 + 8);
      if (pcVar4 == (code *)0x0) {
        writel_relaxed(*(undefined4 *)(param_2 + lVar5),param_1[1] + (long)(iVar2 + (int)lVar5));
      }
      else {
        if (*(int *)(pcVar4 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x1044e0);
          (*pcVar4)();
        }
        (*pcVar4)(param_1,*(undefined4 *)(param_2 + lVar5));
      }
      lVar5 = lVar5 + 4;
    } while (lVar5 != 0x40);
    pcVar4 = *(code **)(*param_1 + 8);
    if (pcVar4 == (code *)0x0) {
      writel_relaxed(*(undefined4 *)(param_2 + 0x44),param_1[1] + (long)(iVar2 + 0x44));
    }
    else {
      if (*(int *)(pcVar4 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x104594);
        (*pcVar4)();
      }
      (*pcVar4)(param_1,*(undefined4 *)(param_2 + 0x44));
    }
    pcVar4 = *(code **)(*param_1 + 8);
    if (pcVar4 == (code *)0x0) {
      writel_relaxed(*(undefined4 *)(param_2 + 0x40),param_1[1] + (long)iVar1);
    }
    else {
      if (*(int *)(pcVar4 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x1045c0);
        (*pcVar4)();
      }
      (*pcVar4)(param_1,*(undefined4 *)(param_2 + 0x40),iVar1);
    }
    uVar3 = 0;
  }
  else {
    if (*(int *)(pcVar4 + -4) != -0x52f95dd6) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x10445c);
      (*pcVar4)();
    }
    uVar3 = (*pcVar4)(param_1,param_2);
  }
  return uVar3;
}



//------------------------------------------------------------
// writel_relaxed @ 001045c8 size=132
// signature: undefined writel_relaxed(void)
// callers: [cqhci_crypto_program_key]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x1045e0,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x10461c,uVar1);
  return;
}



//------------------------------------------------------------
// cqhci_qti_crypto_init @ 00104654 size=576
// signature: undefined cqhci_qti_crypto_init(void)
// callers: [cqhci_init]
//------------------------------------------------------------

undefined8 cqhci_qti_crypto_init(long *param_1)

{
  undefined8 *puVar1;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  long lVar8;
  code *pcVar9;
  int iVar10;
  undefined8 uVar11;
  ulong uVar12;
  undefined8 *puVar13;
  ulong uVar14;
  
  puVar13 = (undefined8 *)param_1[2];
  if ((*(byte *)((long)puVar13 + 0x3eb) >> 3 & 1) != 0) {
    uVar11 = *puVar13;
    pcVar9 = *(code **)(*param_1 + 0x10);
    if (pcVar9 == (code *)0x0) {
      uVar5 = readl_relaxed(param_1[1] + 4);
    }
    else {
      if (*(int *)(pcVar9 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x1046e4);
        (*pcVar9)();
      }
      uVar5 = (*pcVar9)(param_1,4);
    }
    if ((uVar5 >> 0x1c & 1) != 0) {
      pcVar9 = *(code **)(*param_1 + 0x10);
      if (pcVar9 == (code *)0x0) {
        uVar7 = readl_relaxed(param_1[1] + 0x100);
      }
      else {
        if (*(int *)(pcVar9 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x10488c);
          (*pcVar9)();
        }
        uVar7 = (*pcVar9)(param_1,0x100);
      }
      *(uint *)(param_1 + 0x18) = (uint)uVar7;
      *(uint *)(param_1 + 0x1a) = (uint)((ulong)uVar7 >> 0x10) & 0xff00;
      lVar8 = devm_kmalloc(uVar11,((uint)uVar7 & 0xff) << 2,0xdc0);
      param_1[0x19] = lVar8;
      if (lVar8 == 0) {
        uVar7 = 0xfffffff4;
      }
      else {
        bVar2 = *(byte *)((long)param_1 + 0xc1);
        puVar1 = puVar13 + 0xc1;
        uVar7 = devm_blk_crypto_profile_init(uVar11,puVar1,bVar2 + 1);
        if ((int)uVar7 == 0) {
          puVar13[200] = uVar11;
          puVar4 = PTR_cqhci_crypto_qti_derive_raw_secret_001054b8;
          puVar3 = PTR_cqhci_crypto_qti_keyslot_evict_001054b0;
          *puVar1 = cqhci_crypto_qti_ops;
          puVar13[0xc2] = puVar3;
          puVar13[0xc3] = puVar4;
          puVar13[0xc4] = 0x200000004;
          if ((char)param_1[0x18] != '\0') {
            uVar14 = 0;
            uVar12 = 0x104;
            do {
              pcVar9 = *(code **)(*param_1 + 0x10);
              if (pcVar9 == (code *)0x0) {
                uVar6 = readl_relaxed(param_1[1] + uVar12);
              }
              else {
                if (*(int *)(pcVar9 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
                  pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x104808);
                  (*pcVar9)();
                }
                uVar6 = (*pcVar9)(param_1,uVar12 & 0xffffffff);
              }
              *(undefined4 *)(param_1[0x19] + uVar14 * 4) = uVar6;
              uVar5 = *(uint *)(param_1[0x19] + uVar14 * 4);
              if ((uVar5 & 0xff00ff) == 0x30000) {
                *(uint *)((long)puVar13 + 0x62c) =
                     (uVar5 & 0xff00) << 1 | *(uint *)((long)puVar13 + 0x62c);
              }
              uVar14 = uVar14 + 1;
              uVar12 = uVar12 + 4;
            } while (uVar14 < *(byte *)(param_1 + 0x18));
          }
          iVar10 = 0;
          do {
            if (*(int *)((code *)puVar13[0xc2] + -4) != 0x33834daf) {
                    /* WARNING: Does not return */
              pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x104848);
              (*pcVar9)();
            }
            (*(code *)puVar13[0xc2])(puVar1,0,iVar10);
            iVar10 = iVar10 + 1;
          } while (bVar2 + 1 != iVar10);
          *(uint *)(param_1 + 6) = *(uint *)(param_1 + 6) | 1;
          return 0;
        }
      }
      goto LAB_001046a0;
    }
  }
  uVar7 = 0;
LAB_001046a0:
  *(uint *)(puVar13 + 0x7d) = *(uint *)(puVar13 + 0x7d) & 0xf7ffffff;
  return uVar7;
}



//------------------------------------------------------------
// readl_relaxed @ 00104894 size=124
// signature: undefined readl_relaxed(void)
// callers: [cqhci_qti_crypto_init]
//------------------------------------------------------------

undefined4 readl_relaxed(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x20,param_1,0x1048dc,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// cqhci_crypto_qti_keyslot_program @ 00104914 size=332
// signature: undefined cqhci_crypto_qti_keyslot_program(void)
// callers: []
//------------------------------------------------------------

int cqhci_crypto_qti_keyslot_program(long param_1,uint *param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  byte *pbVar7;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  if (param_2 == (uint *)0x0) {
    _printk(&DAT_00104e02);
    iVar3 = -0x16;
LAB_00104a14:
    lVar5 = sp_el0;
    if (*(long *)(lVar5 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return iVar3;
  }
  uVar1 = *param_2;
  if (5 < uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x104a60);
    (*pcVar2)();
  }
  lVar5 = *(long *)(param_1 + -0x10);
  if ((ulong)*(byte *)(lVar5 + 0xc0) != 0) {
    if (4 < uVar1) {
LAB_00104a54:
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x104a58);
      (*pcVar2)();
    }
    lVar6 = (ulong)uVar1 * 8;
    uVar4 = 0;
    pbVar7 = (byte *)(*(long *)(lVar5 + 200) + 1);
    do {
      if (*(uint *)(cqhci_crypto_algs + lVar6) == (uint)pbVar7[-1]) {
        if (0x28 < ((ulong)uVar1 << 3 | 4)) goto LAB_00104a54;
        if ((*(uint *)(cqhci_crypto_algs + lVar6 + 4) == (uint)pbVar7[1]) &&
           ((param_2[1] >> 9 & (uint)*pbVar7) != 0)) {
          if (-1 < (int)uVar4) {
            local_38 = *(undefined8 *)(lVar5 + 0xd8);
            uStack_30 = *(undefined8 *)(lVar5 + 0xe8);
            iVar3 = crypto_qti_keyslot_program(&local_38);
            if (iVar3 != 0) {
              _printk(&DAT_00104e66,"cqhci_crypto_qti_keyslot_program",iVar3);
            }
            goto LAB_00104a14;
          }
          break;
        }
      }
      uVar4 = uVar4 + 1;
      pbVar7 = pbVar7 + 4;
    } while (*(byte *)(lVar5 + 0xc0) != uVar4);
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x800,0x104a14);
  (*pcVar2)();
}



//------------------------------------------------------------
// cqhci_crypto_qti_keyslot_evict @ 00104a64 size=148
// signature: undefined cqhci_crypto_qti_keyslot_evict(void)
// callers: [cqhci_qti_crypto_init]
//------------------------------------------------------------

int cqhci_crypto_qti_keyslot_evict(long param_1,undefined8 param_2,undefined4 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = *(undefined8 *)(*(long *)(param_1 + -0x10) + 0xd8);
  uStack_30 = *(undefined8 *)(*(long *)(param_1 + -0x10) + 0xe8);
  iVar2 = crypto_qti_keyslot_evict(&local_38,param_3,0x14);
  if (iVar2 != 0) {
    _printk(&DAT_00104e66,"cqhci_crypto_qti_keyslot_evict",iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// cqhci_crypto_qti_derive_raw_secret @ 00104afc size=144
// signature: undefined cqhci_crypto_qti_derive_raw_secret(void)
// callers: []
//------------------------------------------------------------

int cqhci_crypto_qti_derive_raw_secret(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = *(undefined8 *)(*(long *)(param_1 + -0x10) + 0xd8);
  uStack_30 = *(undefined8 *)(*(long *)(param_1 + -0x10) + 0xe8);
  iVar2 = crypto_qti_derive_raw_secret(&local_38);
  if (iVar2 != 0) {
    _printk(&DAT_00104e66,"cqhci_crypto_qti_derive_raw_secret",iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// __wake_up @ 00107000 size=1
// signature: undefined __wake_up(void)
// callers: [cqhci_irq, cqhci_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00107008 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [cqhci_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 00107010 size=1
// signature: undefined _find_next_bit(void)
// callers: [cqhci_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmc_cqe_request_done @ 00107018 size=1
// signature: undefined mmc_cqe_request_done(void)
// callers: [cqhci_irq, cqhci_recovery_finish]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmc_cqe_request_done(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 00107020 size=1
// signature: undefined __warn_printk(void)
// callers: [cqhci_irq, cqhci_crypto_keyslot_program]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00107028 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [cqhci_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00107030 size=1
// signature: undefined _printk(void)
// callers: [cqhci_irq, cqhci_timeout, cqhci_crypto_qti_keyslot_program, cqhci_crypto_qti_derive_raw_secret, cqhci_init, cqhci_request, cqhci_dumpregs, cqhci_off, cqhci_halt, cqhci_enable, cqhci_crypto_qti_keyslot_evict, cqhci_clear_all_tasks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00107038 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [cqhci_irq, cqhci_crypto_qti_keyslot_program, cqhci_crypto_qti_derive_raw_secret, cqhci_crypto_init, cqhci_crypto_keyslot_program, cqhci_request, cqhci_wait_for_idle, cqhci_halt, cqhci_crypto_keyslot_evict, cqhci_crypto_qti_keyslot_evict, cqhci_clear_all_tasks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00107040 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [cqhci_pltfm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00107048 size=1
// signature: undefined devm_kmalloc(void)
// callers: [cqhci_qti_crypto_init, cqhci_crypto_init, cqhci_init, cqhci_pltfm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00107050 size=1
// signature: undefined devm_ioremap(void)
// callers: [cqhci_pltfm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00107058 size=1
// signature: undefined _dev_err(void)
// callers: [cqhci_pltfm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00107060 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [cqhci_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00107068 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [cqhci_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00107070 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl_relaxed, readl_relaxed, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 00107078 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed, readl_relaxed, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00107080 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed, writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 00107088 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed, writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dmam_alloc_attrs @ 00107090 size=1
// signature: undefined dmam_alloc_attrs(void)
// callers: [cqhci_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dmam_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00107098 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [cqhci_request, cqhci_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dmam_free_coherent @ 001070a0 size=1
// signature: undefined dmam_free_coherent(void)
// callers: [cqhci_disable, cqhci_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dmam_free_coherent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_sg_attrs @ 001070a8 size=1
// signature: undefined dma_map_sg_attrs(void)
// callers: [cqhci_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_sg_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_next @ 001070b0 size=1
// signature: undefined sg_next(void)
// callers: [cqhci_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 001070b8 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [cqhci_timeout, cqhci_recovery_finish, cqhci_request, cqhci_wait_for_idle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001070c0 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [cqhci_timeout, cqhci_recovery_finish, cqhci_request, cqhci_wait_for_idle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_sg_attrs @ 001070c8 size=1
// signature: undefined dma_unmap_sg_attrs(void)
// callers: [cqhci_post_req, cqhci_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_sg_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 001070d0 size=1
// signature: undefined ktime_get(void)
// callers: [cqhci_off]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 001070d8 size=1
// signature: undefined init_wait_entry(void)
// callers: [cqhci_wait_for_idle, cqhci_halt, cqhci_clear_all_tasks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 001070e0 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [cqhci_wait_for_idle, cqhci_halt, cqhci_clear_all_tasks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 001070e8 size=1
// signature: undefined schedule(void)
// callers: [cqhci_wait_for_idle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 001070f0 size=1
// signature: undefined finish_wait(void)
// callers: [cqhci_wait_for_idle, cqhci_halt, cqhci_clear_all_tasks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 001070f8 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [cqhci_halt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 00107100 size=1
// signature: undefined schedule_timeout(void)
// callers: [cqhci_halt, cqhci_clear_all_tasks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_blk_crypto_profile_init @ 00107108 size=1
// signature: undefined devm_blk_crypto_profile_init(void)
// callers: [cqhci_qti_crypto_init, cqhci_crypto_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_blk_crypto_profile_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00107110 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [cqhci_crypto_keyslot_program]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00107118 size=1
// signature: undefined fortify_panic(void)
// callers: [cqhci_crypto_keyslot_program]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_qti_keyslot_program @ 00107120 size=1
// signature: undefined crypto_qti_keyslot_program(void)
// callers: [cqhci_crypto_qti_keyslot_program]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_qti_keyslot_program(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_qti_keyslot_evict @ 00107128 size=1
// signature: undefined crypto_qti_keyslot_evict(void)
// callers: [cqhci_crypto_qti_keyslot_evict]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_qti_keyslot_evict(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_qti_derive_raw_secret @ 00107130 size=1
// signature: undefined crypto_qti_derive_raw_secret(void)
// callers: [cqhci_crypto_qti_derive_raw_secret]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_qti_derive_raw_secret(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



