// Decompiled by Ghidra 12.2
// Program: f_fs_ipc_log.ko
// Image base: 00100000

//------------------------------------------------------------
// entry_ffs_user_copy_worker @ 001008ec size=440
// signature: undefined entry_ffs_user_copy_worker(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_user_copy_worker(long param_1,long *param_2)

{
  char *pcVar1;
  int iVar2;
  code *pcVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  
  lVar5 = *param_2;
  iVar2 = *(int *)(*(long *)(lVar5 + 0x38) + 0x54);
  if (iVar2 == 0) {
    iVar2 = *(int *)(*(long *)(lVar5 + 0x38) + 0x58);
  }
  if (0 < num_devices) {
    lVar6 = *(long *)(lVar5 + 0x58);
    if (DAT_00105ab0 == lVar6) {
      lVar6 = 0;
LAB_00100a44:
      uVar4 = (&ipc_log_s)[lVar6 * 8];
      goto LAB_00100a54;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar6) {
        lVar6 = 1;
        goto LAB_00100a44;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar6) {
          lVar6 = 2;
          goto LAB_00100a44;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar6) {
            lVar6 = 3;
            goto LAB_00100a44;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar6) {
              lVar6 = 4;
              goto LAB_00100a44;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar6) {
                lVar6 = 5;
                goto LAB_00100a44;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar6) {
                  lVar6 = 6;
                  goto LAB_00100a44;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar6) {
                    lVar6 = 7;
                    goto LAB_00100a44;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar6) {
                      lVar6 = 8;
                      goto LAB_00100a44;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100aa4);
                      (*pcVar3)();
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
  uVar4 = 0;
LAB_00100a54:
  *(long *)(param_1 + 0x30) = lVar5;
  pcVar1 = "write";
  if (*(char *)(lVar5 + -0x4f) != '\0') {
    pcVar1 = "read";
  }
  ipc_log_string(uVar4,"%s: enter: ret %d for %s",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),iVar2,pcVar1);
  return 0;
}



//------------------------------------------------------------
// exit_ffs_epfile_io @ 00100aa8 size=424
// signature: undefined exit_ffs_epfile_io(void)
// callers: []
//------------------------------------------------------------

undefined8 exit_ffs_epfile_io(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x30) + 0xd8);
  if (0 < num_devices) {
    lVar4 = *(long *)(lVar3 + 0x30);
    if (DAT_00105ab0 == lVar4) {
      lVar4 = 0;
LAB_00100bfc:
      uVar2 = (&ipc_log_s)[lVar4 * 8];
      goto LAB_00100c0c;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar4 = 1;
        goto LAB_00100bfc;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar4 = 2;
          goto LAB_00100bfc;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar4 = 3;
            goto LAB_00100bfc;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar4 = 4;
              goto LAB_00100bfc;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar4 = 5;
                goto LAB_00100bfc;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar4 = 6;
                  goto LAB_00100bfc;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar4 = 7;
                    goto LAB_00100bfc;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar4 = 8;
                      goto LAB_00100bfc;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x100c50);
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
  uVar2 = 0;
LAB_00100c0c:
  lVar4 = (long)(int)*param_2;
  if ((param_2[0x21] & 0x1fU) != 0x10) {
    lVar4 = *param_2;
  }
  ipc_log_string(uVar2,"%s: exit: %s ret %zd",*(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),
                 lVar3 + 0x50,lVar4);
  return 0;
}



//------------------------------------------------------------
// entry_ffs_epfile_io @ 00100c54 size=408
// signature: undefined entry_ffs_epfile_io(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_epfile_io(long param_1,long *param_2)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  lVar1 = param_2[1];
  lVar4 = *(long *)(*param_2 + 0xd8);
  if (0 < num_devices) {
    lVar5 = *(long *)(lVar4 + 0x30);
    if (DAT_00105ab0 == lVar5) {
      lVar5 = 0;
LAB_00100da0:
      uVar3 = (&ipc_log_s)[lVar5 * 8];
      goto LAB_00100db0;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar5) {
        lVar5 = 1;
        goto LAB_00100da0;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar5) {
          lVar5 = 2;
          goto LAB_00100da0;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar5) {
            lVar5 = 3;
            goto LAB_00100da0;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar5) {
              lVar5 = 4;
              goto LAB_00100da0;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar5) {
                lVar5 = 5;
                goto LAB_00100da0;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar5) {
                  lVar5 = 6;
                  goto LAB_00100da0;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar5) {
                    lVar5 = 7;
                    goto LAB_00100da0;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar5) {
                      lVar5 = 8;
                      goto LAB_00100da0;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x100dec);
                      (*pcVar2)();
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
  uVar3 = 0;
LAB_00100db0:
  *(long *)(param_1 + 0x30) = *param_2;
  *(long *)(param_1 + 0x38) = lVar1;
  ipc_log_string(uVar3,"%s: enter: %s about to queue %zd bytes",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),lVar4 + 0x50,
                 *(undefined8 *)(lVar1 + 0x20));
  return 0;
}



//------------------------------------------------------------
// entry_ffs_epfile_async_io_complete @ 00100df0 size=396
// signature: undefined entry_ffs_epfile_async_io_complete(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_epfile_async_io_complete(long param_1,long param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (0 < num_devices) {
    lVar3 = *(long *)(*(long *)(*(long *)(param_2 + 8) + 0x38) + 0xa8);
    if (DAT_00105ab0 == lVar3) {
      lVar3 = 0;
LAB_00100f3c:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_00100f4c;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar3) {
        lVar3 = 1;
        goto LAB_00100f3c;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar3) {
          lVar3 = 2;
          goto LAB_00100f3c;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar3) {
            lVar3 = 3;
            goto LAB_00100f3c;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar3) {
              lVar3 = 4;
              goto LAB_00100f3c;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar3) {
                lVar3 = 5;
                goto LAB_00100f3c;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar3) {
                  lVar3 = 6;
                  goto LAB_00100f3c;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar3) {
                    lVar3 = 7;
                    goto LAB_00100f3c;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar3) {
                      lVar3 = 8;
                      goto LAB_00100f3c;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x100f7c);
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
  uVar2 = 0;
LAB_00100f4c:
  ipc_log_string(uVar2,"%s: enter",*(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30));
  return 0;
}



//------------------------------------------------------------
// exit_ffs_epfile_write_iter @ 00100f80 size=440
// signature: undefined exit_ffs_epfile_write_iter(void)
// callers: []
//------------------------------------------------------------

undefined8 exit_ffs_epfile_write_iter(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (0 < num_devices) {
    lVar3 = *(long *)(*(long *)(**(long **)(param_1 + 0x30) + 0xd8) + 0x30);
    if (DAT_00105ab0 == lVar3) {
      lVar3 = 0;
LAB_001010d0:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_001010e0;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar3) {
        lVar3 = 1;
        goto LAB_001010d0;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar3) {
          lVar3 = 2;
          goto LAB_001010d0;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar3) {
            lVar3 = 3;
            goto LAB_001010d0;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar3) {
              lVar3 = 4;
              goto LAB_001010d0;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar3) {
                lVar3 = 5;
                goto LAB_001010d0;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar3) {
                  lVar3 = 6;
                  goto LAB_001010d0;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar3) {
                    lVar3 = 7;
                    goto LAB_001010d0;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar3) {
                      lVar3 = 8;
                      goto LAB_001010d0;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x101138);
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
  uVar2 = 0;
LAB_001010e0:
  lVar3 = (long)(int)*param_2;
  if ((param_2[0x21] & 0x1fU) != 0x10) {
    lVar3 = *param_2;
  }
  if ((lVar3 != -0x211) && (lVar3 != -0xc)) {
    ipc_log_string(uVar2,"%s: exit: ret %zd",*(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30));
  }
  return 0;
}



//------------------------------------------------------------
// entry_ffs_epfile_write_iter @ 0010113c size=404
// signature: undefined entry_ffs_epfile_write_iter(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_epfile_write_iter(long param_1,undefined8 *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (0 < num_devices) {
    lVar3 = *(long *)(*(long *)(*(long *)*param_2 + 0xd8) + 0x30);
    if (DAT_00105ab0 == lVar3) {
      lVar3 = 0;
LAB_0010128c:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_0010129c;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar3) {
        lVar3 = 1;
        goto LAB_0010128c;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar3) {
          lVar3 = 2;
          goto LAB_0010128c;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar3) {
            lVar3 = 3;
            goto LAB_0010128c;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar3) {
              lVar3 = 4;
              goto LAB_0010128c;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar3) {
                lVar3 = 5;
                goto LAB_0010128c;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar3) {
                  lVar3 = 6;
                  goto LAB_0010128c;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar3) {
                    lVar3 = 7;
                    goto LAB_0010128c;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar3) {
                      lVar3 = 8;
                      goto LAB_0010128c;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1012d0);
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
  uVar2 = 0;
LAB_0010129c:
  *(long **)(param_1 + 0x30) = (long *)*param_2;
  ipc_log_string(uVar2,"%s: enter",*(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30));
  return 0;
}



//------------------------------------------------------------
// exit_ffs_epfile_read_iter @ 001012d4 size=424
// signature: undefined exit_ffs_epfile_read_iter(void)
// callers: []
//------------------------------------------------------------

undefined8 exit_ffs_epfile_read_iter(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (0 < num_devices) {
    lVar3 = *(long *)(*(long *)(**(long **)(param_1 + 0x30) + 0xd8) + 0x30);
    if (DAT_00105ab0 == lVar3) {
      lVar3 = 0;
LAB_00101424:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_00101434;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar3) {
        lVar3 = 1;
        goto LAB_00101424;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar3) {
          lVar3 = 2;
          goto LAB_00101424;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar3) {
            lVar3 = 3;
            goto LAB_00101424;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar3) {
              lVar3 = 4;
              goto LAB_00101424;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar3) {
                lVar3 = 5;
                goto LAB_00101424;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar3) {
                  lVar3 = 6;
                  goto LAB_00101424;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar3) {
                    lVar3 = 7;
                    goto LAB_00101424;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar3) {
                      lVar3 = 8;
                      goto LAB_00101424;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10147c);
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
  uVar2 = 0;
LAB_00101434:
  lVar3 = (long)(int)*param_2;
  if ((param_2[0x21] & 0x1fU) != 0x10) {
    lVar3 = *param_2;
  }
  ipc_log_string(uVar2,"%s: exit: ret %zd",*(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),lVar3
                );
  return 0;
}



//------------------------------------------------------------
// entry_ffs_epfile_read_iter @ 00101480 size=404
// signature: undefined entry_ffs_epfile_read_iter(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_epfile_read_iter(long param_1,undefined8 *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (0 < num_devices) {
    lVar3 = *(long *)(*(long *)(*(long *)*param_2 + 0xd8) + 0x30);
    if (DAT_00105ab0 == lVar3) {
      lVar3 = 0;
LAB_001015d0:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_001015e0;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar3) {
        lVar3 = 1;
        goto LAB_001015d0;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar3) {
          lVar3 = 2;
          goto LAB_001015d0;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar3) {
            lVar3 = 3;
            goto LAB_001015d0;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar3) {
              lVar3 = 4;
              goto LAB_001015d0;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar3) {
                lVar3 = 5;
                goto LAB_001015d0;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar3) {
                  lVar3 = 6;
                  goto LAB_001015d0;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar3) {
                    lVar3 = 7;
                    goto LAB_001015d0;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar3) {
                      lVar3 = 8;
                      goto LAB_001015d0;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x101614);
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
  uVar2 = 0;
LAB_001015e0:
  *(long **)(param_1 + 0x30) = (long *)*param_2;
  ipc_log_string(uVar2,"%s: enter",*(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30));
  return 0;
}



//------------------------------------------------------------
// entry_ffs_data_put @ 00101618 size=392
// signature: undefined entry_ffs_data_put(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_data_put(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *param_2;
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar4) {
      lVar3 = 0;
LAB_0010175c:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_0010176c;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar3 = 1;
        goto LAB_0010175c;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar3 = 2;
          goto LAB_0010175c;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar3 = 3;
            goto LAB_0010175c;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar3 = 4;
              goto LAB_0010175c;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar3 = 5;
                goto LAB_0010175c;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar3 = 6;
                  goto LAB_0010175c;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar3 = 7;
                    goto LAB_0010175c;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar3 = 8;
                      goto LAB_0010175c;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1017a0);
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
  uVar2 = 0;
LAB_0010176c:
  ipc_log_string(uVar2,"%s: ref %u",*(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),
                 *(undefined4 *)(lVar4 + 0x68));
  return 0;
}



//------------------------------------------------------------
// entry_ffs_sb_fill @ 001017a4 size=216
// signature: undefined entry_ffs_sb_fill(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 entry_ffs_sb_fill(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  ulong uVar2;
  char *__string;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(*(long *)(param_2 + 8) + 0x40) + 0x20);
  puVar1 = (undefined8 *)kmalloc_trace(_strlcat,0xb20,0x68);
  if (puVar1 == (undefined8 *)0x0) {
    return 0;
  }
  *puVar1 = 0xfffffffe0;
  puVar1[1] = puVar1 + 1;
  puVar1[2] = puVar1 + 1;
  puVar1[3] = create_ipc_context_work;
  __string = *(char **)(lVar3 + 200);
  uVar2 = strnlen(__string,0x29);
  if (uVar2 == 0xffffffffffffffff) {
    fortify_panic("strnlen");
  }
  else {
    if (uVar2 != 0x29) {
      uVar2 = uVar2 + 1;
    }
    if (uVar2 < 0x31) {
      strscpy(puVar1 + 7,__string);
      puVar1[6] = lVar3;
      queue_work_on(0x20,ipc_wq,puVar1);
      return 0;
    }
  }
  fortify_panic("strscpy");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// exit___ffs_ep0_queue_wait @ 00101880 size=396
// signature: undefined exit___ffs_ep0_queue_wait(void)
// callers: []
//------------------------------------------------------------

undefined8 exit___ffs_ep0_queue_wait(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x30);
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar4) {
      lVar3 = 0;
LAB_001019c4:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_001019d4;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar3 = 1;
        goto LAB_001019c4;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar3 = 2;
          goto LAB_001019c4;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar3 = 3;
            goto LAB_001019c4;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar3 = 4;
              goto LAB_001019c4;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar3 = 5;
                goto LAB_001019c4;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar3 = 6;
                  goto LAB_001019c4;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar3 = 7;
                    goto LAB_001019c4;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar3 = 8;
                      goto LAB_001019c4;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x101a0c);
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
  uVar2 = 0;
LAB_001019d4:
  ipc_log_string(uVar2,"%s: exit: state %d setup_state %d flags %lu",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),*(undefined4 *)(lVar4 + 0x70),
                 *(undefined4 *)(lVar4 + 0x74),*(undefined8 *)(lVar4 + 0xa0));
  return 0;
}



//------------------------------------------------------------
// entry___ffs_ep0_queue_wait @ 00101a10 size=400
// signature: undefined entry___ffs_ep0_queue_wait(void)
// callers: []
//------------------------------------------------------------

undefined8 entry___ffs_ep0_queue_wait(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *param_2;
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar4) {
      lVar3 = 0;
LAB_00101b54:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_00101b64;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar3 = 1;
        goto LAB_00101b54;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar3 = 2;
          goto LAB_00101b54;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar3 = 3;
            goto LAB_00101b54;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar3 = 4;
              goto LAB_00101b54;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar3 = 5;
                goto LAB_00101b54;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar3 = 6;
                  goto LAB_00101b54;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar3 = 7;
                    goto LAB_00101b54;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar3 = 8;
                      goto LAB_00101b54;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x101ba0);
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
  uVar2 = 0;
LAB_00101b64:
  *(long *)(param_1 + 0x30) = lVar4;
  ipc_log_string(uVar2,"%s: enter: state %d setup_state %d flags %lu",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),*(undefined4 *)(lVar4 + 0x70),
                 *(undefined4 *)(lVar4 + 0x74),*(undefined8 *)(lVar4 + 0xa0));
  return 0;
}



//------------------------------------------------------------
// exit_ffs_ep0_write @ 00101ba4 size=440
// signature: undefined exit_ffs_ep0_write(void)
// callers: []
//------------------------------------------------------------

undefined8 exit_ffs_ep0_write(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x30) + 0xd8);
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar4) {
      lVar3 = 0;
LAB_00101cec:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_00101cfc;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar3 = 1;
        goto LAB_00101cec;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar3 = 2;
          goto LAB_00101cec;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar3 = 3;
            goto LAB_00101cec;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar3 = 4;
              goto LAB_00101cec;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar3 = 5;
                goto LAB_00101cec;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar3 = 6;
                  goto LAB_00101cec;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar3 = 7;
                    goto LAB_00101cec;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar3 = 8;
                      goto LAB_00101cec;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x101d5c);
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
  uVar2 = 0;
LAB_00101cfc:
  lVar3 = (long)(int)*param_2;
  if ((param_2[0x21] & 0x1fU) != 0x10) {
    lVar3 = *param_2;
  }
  if ((lVar3 != -0x2b) && (lVar3 != -0x16)) {
    ipc_log_string(uVar2,"%s: exit:ret %zd state %d setup_state %d flags %lu",
                   *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),lVar3,
                   *(undefined4 *)(lVar4 + 0x70),*(undefined4 *)(lVar4 + 0x74),
                   *(undefined8 *)(lVar4 + 0xa0));
  }
  return 0;
}



//------------------------------------------------------------
// entry_ffs_ep0_write @ 00101d60 size=408
// signature: undefined entry_ffs_ep0_write(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_ep0_write(long param_1,long *param_2)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  lVar2 = param_2[2];
  lVar5 = *(long *)(*param_2 + 0xd8);
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar5) {
      lVar4 = 0;
LAB_00101eac:
      uVar3 = (&ipc_log_s)[lVar4 * 8];
      goto LAB_00101ebc;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar5) {
        lVar4 = 1;
        goto LAB_00101eac;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar5) {
          lVar4 = 2;
          goto LAB_00101eac;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar5) {
            lVar4 = 3;
            goto LAB_00101eac;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar5) {
              lVar4 = 4;
              goto LAB_00101eac;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar5) {
                lVar4 = 5;
                goto LAB_00101eac;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar5) {
                  lVar4 = 6;
                  goto LAB_00101eac;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar5) {
                    lVar4 = 7;
                    goto LAB_00101eac;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar5) {
                      lVar4 = 8;
                      goto LAB_00101eac;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x101ef8);
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
  uVar3 = 0;
LAB_00101ebc:
  *(long *)(param_1 + 0x30) = *param_2;
  ipc_log_string(uVar3,"%s: enter:len %zu state %d setup_state %d flags %lu",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),lVar2,
                 *(undefined4 *)(lVar5 + 0x70),*(undefined4 *)(lVar5 + 0x74),
                 *(undefined8 *)(lVar5 + 0xa0));
  return 0;
}



//------------------------------------------------------------
// exit_ffs_ep0_read @ 00101efc size=424
// signature: undefined exit_ffs_ep0_read(void)
// callers: []
//------------------------------------------------------------

undefined8 exit_ffs_ep0_read(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x30) + 0xd8);
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar4) {
      lVar3 = 0;
LAB_00102044:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_00102054;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar3 = 1;
        goto LAB_00102044;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar3 = 2;
          goto LAB_00102044;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar3 = 3;
            goto LAB_00102044;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar3 = 4;
              goto LAB_00102044;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar3 = 5;
                goto LAB_00102044;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar3 = 6;
                  goto LAB_00102044;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar3 = 7;
                    goto LAB_00102044;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar3 = 8;
                      goto LAB_00102044;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1020a4);
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
  uVar2 = 0;
LAB_00102054:
  lVar3 = (long)(int)*param_2;
  if ((param_2[0x21] & 0x1fU) != 0x10) {
    lVar3 = *param_2;
  }
  ipc_log_string(uVar2,"%s: exit:ret %d state %d setup_state %d flags %lu",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),lVar3,
                 *(undefined4 *)(lVar4 + 0x70),*(undefined4 *)(lVar4 + 0x74),
                 *(undefined8 *)(lVar4 + 0xa0));
  return 0;
}



//------------------------------------------------------------
// entry_ffs_ep0_read @ 001020a8 size=436
// signature: undefined entry_ffs_ep0_read(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_ep0_read(long param_1,long *param_2)

{
  code *pcVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  
  uVar2 = param_2[2];
  lVar5 = *(long *)(*param_2 + 0xd8);
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar5) {
      lVar4 = 0;
LAB_001021f4:
      uVar3 = (&ipc_log_s)[lVar4 * 8];
      goto LAB_00102204;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar5) {
        lVar4 = 1;
        goto LAB_001021f4;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar5) {
          lVar4 = 2;
          goto LAB_001021f4;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar5) {
            lVar4 = 3;
            goto LAB_001021f4;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar5) {
              lVar4 = 4;
              goto LAB_001021f4;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar5) {
                lVar4 = 5;
                goto LAB_001021f4;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar5) {
                  lVar4 = 6;
                  goto LAB_001021f4;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar5) {
                    lVar4 = 7;
                    goto LAB_001021f4;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar5) {
                      lVar4 = 8;
                      goto LAB_001021f4;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10225c);
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
  uVar3 = 0;
LAB_00102204:
  *(long *)(param_1 + 0x30) = *param_2;
  uVar6 = uVar2 / 0xc;
  if (*(ushort *)(lVar5 + 0x7c) <= uVar6) {
    uVar6 = (ulong)*(ushort *)(lVar5 + 0x7c);
  }
  ipc_log_string(uVar3,"%s: enter:len %zu state %d setup_state %d flags %lu n %zu",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),uVar2,
                 *(undefined4 *)(lVar5 + 0x70),*(undefined4 *)(lVar5 + 0x74),
                 *(undefined8 *)(lVar5 + 0xa0),uVar6);
  return 0;
}



//------------------------------------------------------------
// entry_ffs_ep0_open @ 00102260 size=404
// signature: undefined entry_ffs_ep0_open(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_ep0_open(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(*param_2 + 0x2b8);
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar4) {
      lVar3 = 0;
LAB_001023a8:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_001023b8;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar3 = 1;
        goto LAB_001023a8;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar3 = 2;
          goto LAB_001023a8;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar3 = 3;
            goto LAB_001023a8;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar3 = 4;
              goto LAB_001023a8;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar3 = 5;
                goto LAB_001023a8;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar3 = 6;
                  goto LAB_001023a8;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar3 = 7;
                    goto LAB_001023a8;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar3 = 8;
                      goto LAB_001023a8;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1023f4);
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
  uVar2 = 0;
LAB_001023b8:
  ipc_log_string(uVar2,"%s: state %d setup_state %d flags %lu opened %d",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),*(undefined4 *)(lVar4 + 0x70),
                 *(undefined4 *)(lVar4 + 0x74),*(undefined8 *)(lVar4 + 0xa0),
                 *(undefined4 *)(lVar4 + 0x6c));
  return 0;
}



//------------------------------------------------------------
// entry_ffs_ep0_release @ 001023f8 size=404
// signature: undefined entry_ffs_ep0_release(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_ep0_release(long param_1,long param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_2 + 8) + 0xd8);
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar4) {
      lVar3 = 0;
LAB_00102540:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_00102550;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar3 = 1;
        goto LAB_00102540;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar3 = 2;
          goto LAB_00102540;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar3 = 3;
            goto LAB_00102540;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar3 = 4;
              goto LAB_00102540;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar3 = 5;
                goto LAB_00102540;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar3 = 6;
                  goto LAB_00102540;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar3 = 7;
                    goto LAB_00102540;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar3 = 8;
                      goto LAB_00102540;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10258c);
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
  uVar2 = 0;
LAB_00102550:
  ipc_log_string(uVar2,"%s: state %d setup_state %d flags %lu opened %d",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),*(undefined4 *)(lVar4 + 0x70),
                 *(undefined4 *)(lVar4 + 0x74),*(undefined8 *)(lVar4 + 0xa0),
                 *(undefined4 *)(lVar4 + 0x6c));
  return 0;
}



//------------------------------------------------------------
// entry_ffs_ep0_ioctl @ 00102590 size=404
// signature: undefined entry_ffs_ep0_ioctl(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_ep0_ioctl(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(*param_2 + 0xd8);
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar4) {
      lVar3 = 0;
LAB_001026d8:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_001026e8;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar3 = 1;
        goto LAB_001026d8;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar3 = 2;
          goto LAB_001026d8;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar3 = 3;
            goto LAB_001026d8;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar3 = 4;
              goto LAB_001026d8;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar3 = 5;
                goto LAB_001026d8;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar3 = 6;
                  goto LAB_001026d8;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar3 = 7;
                    goto LAB_001026d8;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar3 = 8;
                      goto LAB_001026d8;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x102724);
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
  uVar2 = 0;
LAB_001026e8:
  ipc_log_string(uVar2,"%s: state %d setup_state %d flags %lu opened %d",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),*(undefined4 *)(lVar4 + 0x70),
                 *(undefined4 *)(lVar4 + 0x74),*(undefined8 *)(lVar4 + 0xa0),
                 *(undefined4 *)(lVar4 + 0x6c));
  return 0;
}



//------------------------------------------------------------
// entry_ffs_epfile_open @ 00102728 size=412
// signature: undefined entry_ffs_epfile_open(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_epfile_open(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(*param_2 + 0x2b8) + 0x30);
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar4) {
      lVar3 = 0;
LAB_00102874:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_00102884;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar3 = 1;
        goto LAB_00102874;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar3 = 2;
          goto LAB_00102874;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar3 = 3;
            goto LAB_00102874;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar3 = 4;
              goto LAB_00102874;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar3 = 5;
                goto LAB_00102874;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar3 = 6;
                  goto LAB_00102874;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar3 = 7;
                    goto LAB_00102874;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar3 = 8;
                      goto LAB_00102874;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1028c4);
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
  uVar2 = 0;
LAB_00102884:
  ipc_log_string(uVar2,"%s: %s: state %d setup_state %d flag %lu opened %u",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),
                 *(long *)(*param_2 + 0x2b8) + 0x50,*(undefined4 *)(lVar4 + 0x70),
                 *(undefined4 *)(lVar4 + 0x74),*(undefined8 *)(lVar4 + 0xa0),
                 *(undefined4 *)(lVar4 + 0x6c));
  return 0;
}



//------------------------------------------------------------
// exit_ffs_aio_cancel @ 001028c8 size=424
// signature: undefined exit_ffs_aio_cancel(void)
// callers: []
//------------------------------------------------------------

undefined8 exit_ffs_aio_cancel(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (0 < num_devices) {
    lVar3 = *(long *)(*(long *)(**(long **)(param_1 + 0x30) + 0xd8) + 0x30);
    if (DAT_00105ab0 == lVar3) {
      lVar3 = 0;
LAB_00102a20:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_00102a30;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar3) {
        lVar3 = 1;
        goto LAB_00102a20;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar3) {
          lVar3 = 2;
          goto LAB_00102a20;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar3) {
            lVar3 = 3;
            goto LAB_00102a20;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar3) {
              lVar3 = 4;
              goto LAB_00102a20;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar3) {
                lVar3 = 5;
                goto LAB_00102a20;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar3) {
                  lVar3 = 6;
                  goto LAB_00102a20;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar3) {
                    lVar3 = 7;
                    goto LAB_00102a20;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar3) {
                      lVar3 = 8;
                      goto LAB_00102a20;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x102a70);
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
  uVar2 = 0;
LAB_00102a30:
  lVar3 = (long)(int)*param_2;
  if ((param_2[0x21] & 0x1fU) != 0x10) {
    lVar3 = *param_2;
  }
  ipc_log_string(uVar2,"%s: exit: mask %u",*(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),lVar3
                );
  return 0;
}



//------------------------------------------------------------
// entry_ffs_aio_cancel @ 00102a74 size=416
// signature: undefined entry_ffs_aio_cancel(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_aio_cancel(long param_1,undefined8 *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = *(long *)(*(long *)*param_2 + 0xd8);
  if (0 < num_devices) {
    lVar4 = *(long *)(lVar3 + 0x30);
    if (DAT_00105ab0 == lVar4) {
      lVar4 = 0;
LAB_00102bc4:
      uVar2 = (&ipc_log_s)[lVar4 * 8];
      goto LAB_00102bd4;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar4 = 1;
        goto LAB_00102bc4;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar4 = 2;
          goto LAB_00102bc4;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar4 = 3;
            goto LAB_00102bc4;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar4 = 4;
              goto LAB_00102bc4;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar4 = 5;
                goto LAB_00102bc4;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar4 = 6;
                  goto LAB_00102bc4;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar4 = 7;
                    goto LAB_00102bc4;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar4 = 8;
                      goto LAB_00102bc4;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x102c14);
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
  uVar2 = 0;
LAB_00102bd4:
  *(long **)(param_1 + 0x30) = (long *)*param_2;
  lVar3 = *(long *)(lVar3 + 0x30);
  ipc_log_string(uVar2,"%s: enter:state %d setup_state %d flag %lu",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),*(undefined4 *)(lVar3 + 0x70),
                 *(undefined4 *)(lVar3 + 0x74),*(undefined8 *)(lVar3 + 0xa0));
  return 0;
}



//------------------------------------------------------------
// entry_ffs_epfile_release @ 00102c18 size=412
// signature: undefined entry_ffs_epfile_release(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_epfile_release(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(*param_2 + 0x2b8) + 0x30);
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar4) {
      lVar3 = 0;
LAB_00102d64:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_00102d74;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar3 = 1;
        goto LAB_00102d64;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar3 = 2;
          goto LAB_00102d64;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar3 = 3;
            goto LAB_00102d64;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar3 = 4;
              goto LAB_00102d64;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar3 = 5;
                goto LAB_00102d64;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar3 = 6;
                  goto LAB_00102d64;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar3 = 7;
                    goto LAB_00102d64;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar3 = 8;
                      goto LAB_00102d64;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x102db4);
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
  uVar2 = 0;
LAB_00102d74:
  ipc_log_string(uVar2,"%s: %s: state %d setup_state %d flag %lu opened %u",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),
                 *(long *)(*param_2 + 0x2b8) + 0x50,*(undefined4 *)(lVar4 + 0x70),
                 *(undefined4 *)(lVar4 + 0x74),*(undefined8 *)(lVar4 + 0xa0),
                 *(undefined4 *)(lVar4 + 0x6c));
  return 0;
}



//------------------------------------------------------------
// exit_ffs_epfile_ioctl @ 00102db8 size=424
// signature: undefined exit_ffs_epfile_ioctl(void)
// callers: []
//------------------------------------------------------------

undefined8 exit_ffs_epfile_ioctl(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x30) + 0xd8);
  if (0 < num_devices) {
    lVar4 = *(long *)(lVar3 + 0x30);
    if (DAT_00105ab0 == lVar4) {
      lVar4 = 0;
LAB_00102f0c:
      uVar2 = (&ipc_log_s)[lVar4 * 8];
      goto LAB_00102f1c;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar4 = 1;
        goto LAB_00102f0c;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar4 = 2;
          goto LAB_00102f0c;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar4 = 3;
            goto LAB_00102f0c;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar4 = 4;
              goto LAB_00102f0c;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar4 = 5;
                goto LAB_00102f0c;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar4 = 6;
                  goto LAB_00102f0c;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar4 = 7;
                    goto LAB_00102f0c;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar4 = 8;
                      goto LAB_00102f0c;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x102f60);
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
  uVar2 = 0;
LAB_00102f1c:
  lVar4 = (long)(int)*param_2;
  if ((param_2[0x21] & 0x1fU) != 0x10) {
    lVar4 = *param_2;
  }
  ipc_log_string(uVar2,"%s: exit: %s: ret %d\n",*(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),
                 lVar3 + 0x50,lVar4);
  return 0;
}



//------------------------------------------------------------
// entry_ffs_epfile_ioctl @ 00102f64 size=432
// signature: undefined entry_ffs_epfile_ioctl(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_epfile_ioctl(long param_1,long *param_2)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  
  lVar3 = param_2[2];
  lVar1 = param_2[1];
  lVar5 = *(long *)(*param_2 + 0xd8);
  if (0 < num_devices) {
    lVar6 = *(long *)(lVar5 + 0x30);
    if (DAT_00105ab0 == lVar6) {
      lVar6 = 0;
LAB_001030b8:
      uVar4 = (&ipc_log_s)[lVar6 * 8];
      goto LAB_001030c8;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar6) {
        lVar6 = 1;
        goto LAB_001030b8;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar6) {
          lVar6 = 2;
          goto LAB_001030b8;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar6) {
            lVar6 = 3;
            goto LAB_001030b8;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar6) {
              lVar6 = 4;
              goto LAB_001030b8;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar6) {
                lVar6 = 5;
                goto LAB_001030b8;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar6) {
                  lVar6 = 6;
                  goto LAB_001030b8;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar6) {
                    lVar6 = 7;
                    goto LAB_001030b8;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar6) {
                      lVar6 = 8;
                      goto LAB_001030b8;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x103114);
                      (*pcVar2)();
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
  uVar4 = 0;
LAB_001030c8:
  *(long *)(param_1 + 0x30) = *param_2;
  lVar6 = *(long *)(lVar5 + 0x30);
  ipc_log_string(uVar4,"%s: %s: code 0x%08x value %#lx state %d setup_state %d flag %lu",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),lVar5 + 0x50,lVar1,lVar3,
                 *(undefined4 *)(lVar6 + 0x70),*(undefined4 *)(lVar6 + 0x74),
                 *(undefined8 *)(lVar6 + 0xa0));
  return 0;
}



//------------------------------------------------------------
// entry_ffs_data_opened @ 00103118 size=404
// signature: undefined entry_ffs_data_opened(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_data_opened(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *param_2;
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar4) {
      lVar3 = 0;
LAB_0010325c:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_0010326c;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar3 = 1;
        goto LAB_0010325c;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar3 = 2;
          goto LAB_0010325c;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar3 = 3;
            goto LAB_0010325c;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar3 = 4;
              goto LAB_0010325c;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar3 = 5;
                goto LAB_0010325c;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar3 = 6;
                  goto LAB_0010325c;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar3 = 7;
                    goto LAB_0010325c;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar3 = 8;
                      goto LAB_0010325c;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1032ac);
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
  uVar2 = 0;
LAB_0010326c:
  ipc_log_string(uVar2,"%s: enter: state %d setup_state %d flag %lu opened %d ref %d",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),*(undefined4 *)(lVar4 + 0x70),
                 *(undefined4 *)(lVar4 + 0x74),*(undefined8 *)(lVar4 + 0xa0),
                 *(undefined4 *)(lVar4 + 0x6c),*(undefined4 *)(lVar4 + 0x68));
  return 0;
}



//------------------------------------------------------------
// entry_ffs_data_closed @ 001032b0 size=400
// signature: undefined entry_ffs_data_closed(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_data_closed(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *param_2;
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar4) {
      lVar3 = 0;
LAB_001033f4:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_00103404;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar3 = 1;
        goto LAB_001033f4;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar3 = 2;
          goto LAB_001033f4;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar3 = 3;
            goto LAB_001033f4;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar3 = 4;
              goto LAB_001033f4;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar3 = 5;
                goto LAB_001033f4;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar3 = 6;
                  goto LAB_001033f4;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar3 = 7;
                    goto LAB_001033f4;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar3 = 8;
                      goto LAB_001033f4;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x103440);
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
  uVar2 = 0;
LAB_00103404:
  ipc_log_string(uVar2,"%s: state %d setup_state %d flag %lu opened %d",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),*(undefined4 *)(lVar4 + 0x70),
                 *(undefined4 *)(lVar4 + 0x74),*(undefined8 *)(lVar4 + 0xa0),
                 *(undefined4 *)(lVar4 + 0x6c));
  return 0;
}



//------------------------------------------------------------
// entry_ffs_data_clear @ 00103444 size=396
// signature: undefined entry_ffs_data_clear(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_data_clear(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *param_2;
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar4) {
      lVar3 = 0;
LAB_00103588:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_00103598;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar3 = 1;
        goto LAB_00103588;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar3 = 2;
          goto LAB_00103588;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar3 = 3;
            goto LAB_00103588;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar3 = 4;
              goto LAB_00103588;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar3 = 5;
                goto LAB_00103588;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar3 = 6;
                  goto LAB_00103588;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar3 = 7;
                    goto LAB_00103588;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar3 = 8;
                      goto LAB_00103588;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1035d0);
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
  uVar2 = 0;
LAB_00103598:
  ipc_log_string(uVar2,"%s: enter: state %d setup_state %d flag %lu",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),*(undefined4 *)(lVar4 + 0x70),
                 *(undefined4 *)(lVar4 + 0x74),*(undefined8 *)(lVar4 + 0xa0));
  return 0;
}



//------------------------------------------------------------
// exit_functionfs_bind @ 001035d4 size=412
// signature: undefined exit_functionfs_bind(void)
// callers: []
//------------------------------------------------------------

undefined8 exit_functionfs_bind(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (0 < num_devices) {
    lVar3 = *(long *)(param_1 + 0x30);
    if (DAT_00105ab0 == lVar3) {
      lVar3 = 0;
LAB_00103718:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_00103728;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar3) {
        lVar3 = 1;
        goto LAB_00103718;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar3) {
          lVar3 = 2;
          goto LAB_00103718;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar3) {
            lVar3 = 3;
            goto LAB_00103718;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar3) {
              lVar3 = 4;
              goto LAB_00103718;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar3) {
                lVar3 = 5;
                goto LAB_00103718;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar3) {
                  lVar3 = 6;
                  goto LAB_00103718;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar3) {
                    lVar3 = 7;
                    goto LAB_00103718;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar3) {
                      lVar3 = 8;
                      goto LAB_00103718;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x103770);
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
  uVar2 = 0;
LAB_00103728:
  lVar3 = (long)(int)*param_2;
  if ((param_2[0x21] & 0x1fU) != 0x10) {
    lVar3 = *param_2;
  }
  ipc_log_string(uVar2,"%s: functionfs_bind returned %d",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),lVar3);
  return 0;
}



//------------------------------------------------------------
// entry_functionfs_bind @ 00103774 size=400
// signature: undefined entry_functionfs_bind(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_functionfs_bind(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *param_2;
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar4) {
      lVar3 = 0;
LAB_001038b8:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_001038c8;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar3 = 1;
        goto LAB_001038b8;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar3 = 2;
          goto LAB_001038b8;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar3 = 3;
            goto LAB_001038b8;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar3 = 4;
              goto LAB_001038b8;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar3 = 5;
                goto LAB_001038b8;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar3 = 6;
                  goto LAB_001038b8;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar3 = 7;
                    goto LAB_001038b8;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar3 = 8;
                      goto LAB_001038b8;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x103904);
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
  uVar2 = 0;
LAB_001038c8:
  *(long *)(param_1 + 0x30) = lVar4;
  ipc_log_string(uVar2,"%s: enter: state %d setup_state %d flag %lu",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),*(undefined4 *)(lVar4 + 0x70),
                 *(undefined4 *)(lVar4 + 0x74),*(undefined8 *)(lVar4 + 0xa0));
  return 0;
}



//------------------------------------------------------------
// entry_ffs_func_eps_disable @ 00103908 size=400
// signature: undefined entry_ffs_func_eps_disable(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_func_eps_disable(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(*param_2 + 0x10);
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar4) {
      lVar3 = 0;
LAB_00103a50:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_00103a60;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar3 = 1;
        goto LAB_00103a50;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar3 = 2;
          goto LAB_00103a50;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar3 = 3;
            goto LAB_00103a50;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar3 = 4;
              goto LAB_00103a50;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar3 = 5;
                goto LAB_00103a50;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar3 = 6;
                  goto LAB_00103a50;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar3 = 7;
                    goto LAB_00103a50;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar3 = 8;
                      goto LAB_00103a50;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x103a98);
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
  uVar2 = 0;
LAB_00103a60:
  ipc_log_string(uVar2,"%s: enter: state %d setup_state %d flag %lu",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),*(undefined4 *)(lVar4 + 0x70),
                 *(undefined4 *)(lVar4 + 0x74),*(undefined8 *)(lVar4 + 0xa0));
  return 0;
}



//------------------------------------------------------------
// exit_ffs_func_bind @ 00103a9c size=404
// signature: undefined exit_ffs_func_bind(void)
// callers: []
//------------------------------------------------------------

undefined8 exit_ffs_func_bind(long param_1,int *param_2)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = *(long *)(param_1 + 0x30);
  if (lVar2 == 0) {
    return 0;
  }
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar2) {
      lVar2 = 0;
LAB_00103c14:
      uVar3 = (&ipc_log_s)[lVar2 * 8];
      goto joined_r0x00103ba0;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar2) {
        lVar2 = 1;
        goto LAB_00103c14;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar2) {
          lVar2 = 2;
          goto LAB_00103c14;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar2) {
            lVar2 = 3;
            goto LAB_00103c14;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar2) {
              lVar2 = 4;
              goto LAB_00103c14;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar2) {
                lVar2 = 5;
                goto LAB_00103c14;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar2) {
                  lVar2 = 6;
                  goto LAB_00103c14;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar2) {
                    lVar2 = 7;
                    goto LAB_00103c14;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar2) {
                      lVar2 = 8;
                      goto LAB_00103c14;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x103c30);
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
  uVar3 = 0;
joined_r0x00103ba0:
  if (*param_2 < 0) {
    ipc_log_string(uVar3,"%s: exit: ret %d",*(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30));
  }
  return 0;
}



//------------------------------------------------------------
// entry_ffs_func_bind @ 00103c34 size=416
// signature: undefined entry_ffs_func_bind(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_func_bind(long param_1,long param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = **(long **)(*(long *)(*(long *)(param_2 + 8) + 200) + 0xb8);
  if (lVar4 == 0) {
    return 0;
  }
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar4) {
      lVar3 = 0;
LAB_00103d88:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_00103d98;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar3 = 1;
        goto LAB_00103d88;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar3 = 2;
          goto LAB_00103d88;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar3 = 3;
            goto LAB_00103d88;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar3 = 4;
              goto LAB_00103d88;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar3 = 5;
                goto LAB_00103d88;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar3 = 6;
                  goto LAB_00103d88;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar3 = 7;
                    goto LAB_00103d88;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar3 = 8;
                      goto LAB_00103d88;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x103dd4);
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
  uVar2 = 0;
LAB_00103d98:
  *(long *)(param_1 + 0x30) = lVar4;
  ipc_log_string(uVar2,"%s: enter: state %d setup_state %d flag %lu",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),*(undefined4 *)(lVar4 + 0x70),
                 *(undefined4 *)(lVar4 + 0x74),*(undefined8 *)(lVar4 + 0xa0));
  return 0;
}



//------------------------------------------------------------
// entry_ffs_reset_work @ 00103dd8 size=392
// signature: undefined entry_ffs_reset_work(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_reset_work(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (0 < num_devices) {
    lVar3 = *param_2 + -400;
    if (DAT_00105ab0 == lVar3) {
      lVar3 = 0;
LAB_00103f20:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_00103f30;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar3) {
        lVar3 = 1;
        goto LAB_00103f20;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar3) {
          lVar3 = 2;
          goto LAB_00103f20;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar3) {
            lVar3 = 3;
            goto LAB_00103f20;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar3) {
              lVar3 = 4;
              goto LAB_00103f20;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar3) {
                lVar3 = 5;
                goto LAB_00103f20;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar3) {
                  lVar3 = 6;
                  goto LAB_00103f20;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar3) {
                    lVar3 = 7;
                    goto LAB_00103f20;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar3) {
                      lVar3 = 8;
                      goto LAB_00103f20;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x103f60);
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
  uVar2 = 0;
LAB_00103f30:
  ipc_log_string(uVar2,"%s: enter",*(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30));
  return 0;
}



//------------------------------------------------------------
// entry_ffs_func_set_alt @ 00103f64 size=404
// signature: undefined entry_ffs_func_set_alt(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_func_set_alt(long param_1,long *param_2)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar2 = param_2[2];
  if (0 < num_devices) {
    lVar4 = *(long *)(*param_2 + -0x28);
    if (DAT_00105ab0 == lVar4) {
      lVar4 = 0;
LAB_001040b0:
      uVar3 = (&ipc_log_s)[lVar4 * 8];
      goto LAB_001040c0;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar4 = 1;
        goto LAB_001040b0;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar4 = 2;
          goto LAB_001040b0;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar4 = 3;
            goto LAB_001040b0;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar4 = 4;
              goto LAB_001040b0;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar4 = 5;
                goto LAB_001040b0;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar4 = 6;
                  goto LAB_001040b0;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar4 = 7;
                    goto LAB_001040b0;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar4 = 8;
                      goto LAB_001040b0;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1040f8);
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
  uVar3 = 0;
LAB_001040c0:
  *(long *)(param_1 + 0x30) = *param_2 + -0x38;
  ipc_log_string(uVar3,"%s: enter: alt %d",*(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),lVar2
                );
  return 0;
}



//------------------------------------------------------------
// entry_ffs_func_disable @ 001040fc size=392
// signature: undefined entry_ffs_func_disable(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_func_disable(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (0 < num_devices) {
    lVar3 = *(long *)(*param_2 + -0x28);
    if (DAT_00105ab0 == lVar3) {
      lVar3 = 0;
LAB_00104244:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_00104254;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar3) {
        lVar3 = 1;
        goto LAB_00104244;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar3) {
          lVar3 = 2;
          goto LAB_00104244;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar3) {
            lVar3 = 3;
            goto LAB_00104244;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar3) {
              lVar3 = 4;
              goto LAB_00104244;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar3) {
                lVar3 = 5;
                goto LAB_00104244;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar3) {
                  lVar3 = 6;
                  goto LAB_00104244;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar3) {
                    lVar3 = 7;
                    goto LAB_00104244;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar3) {
                      lVar3 = 8;
                      goto LAB_00104244;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x104284);
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
  uVar2 = 0;
LAB_00104254:
  ipc_log_string(uVar2,"%s: enter",*(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30));
  return 0;
}



//------------------------------------------------------------
// entry_ffs_func_setup @ 00104288 size=428
// signature: undefined entry_ffs_func_setup(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_func_setup(long param_1,long *param_2)

{
  undefined1 *puVar1;
  code *pcVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  puVar1 = (undefined1 *)param_2[1];
  lVar5 = *(long *)(*param_2 + -0x28);
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar5) {
      lVar4 = 0;
LAB_001043d4:
      uVar3 = (&ipc_log_s)[lVar4 * 8];
      goto LAB_001043e4;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar5) {
        lVar4 = 1;
        goto LAB_001043d4;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar5) {
          lVar4 = 2;
          goto LAB_001043d4;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar5) {
            lVar4 = 3;
            goto LAB_001043d4;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar5) {
              lVar4 = 4;
              goto LAB_001043d4;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar5) {
                lVar4 = 5;
                goto LAB_001043d4;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar5) {
                  lVar4 = 6;
                  goto LAB_001043d4;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar5) {
                    lVar4 = 7;
                    goto LAB_001043d4;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar5) {
                      lVar4 = 8;
                      goto LAB_001043d4;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x104434);
                      (*pcVar2)();
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
  uVar3 = 0;
LAB_001043e4:
  ipc_log_string(uVar3,"%s: enter: state %d reqtype=%02x req=%02x wv=%04x wi=%04x wl=%04x",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),*(undefined4 *)(lVar5 + 0x70),
                 *puVar1,puVar1[1],*(undefined2 *)(puVar1 + 2),*(undefined2 *)(puVar1 + 4),
                 *(undefined2 *)(puVar1 + 6));
  return 0;
}



//------------------------------------------------------------
// entry_ffs_func_suspend @ 00104438 size=392
// signature: undefined entry_ffs_func_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_func_suspend(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (0 < num_devices) {
    lVar3 = *(long *)(*param_2 + -0x28);
    if (DAT_00105ab0 == lVar3) {
      lVar3 = 0;
LAB_00104580:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_00104590;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar3) {
        lVar3 = 1;
        goto LAB_00104580;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar3) {
          lVar3 = 2;
          goto LAB_00104580;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar3) {
            lVar3 = 3;
            goto LAB_00104580;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar3) {
              lVar3 = 4;
              goto LAB_00104580;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar3) {
                lVar3 = 5;
                goto LAB_00104580;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar3) {
                  lVar3 = 6;
                  goto LAB_00104580;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar3) {
                    lVar3 = 7;
                    goto LAB_00104580;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar3) {
                      lVar3 = 8;
                      goto LAB_00104580;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1045c0);
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
  uVar2 = 0;
LAB_00104590:
  ipc_log_string(uVar2,"%s: enter",*(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30));
  return 0;
}



//------------------------------------------------------------
// entry_ffs_func_resume @ 001045c4 size=392
// signature: undefined entry_ffs_func_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_func_resume(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (0 < num_devices) {
    lVar3 = *(long *)(*param_2 + -0x28);
    if (DAT_00105ab0 == lVar3) {
      lVar3 = 0;
LAB_0010470c:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_0010471c;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar3) {
        lVar3 = 1;
        goto LAB_0010470c;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar3) {
          lVar3 = 2;
          goto LAB_0010470c;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar3) {
            lVar3 = 3;
            goto LAB_0010470c;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar3) {
              lVar3 = 4;
              goto LAB_0010470c;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar3) {
                lVar3 = 5;
                goto LAB_0010470c;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar3) {
                  lVar3 = 6;
                  goto LAB_0010470c;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar3) {
                    lVar3 = 7;
                    goto LAB_0010470c;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar3) {
                      lVar3 = 8;
                      goto LAB_0010470c;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10474c);
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
  uVar2 = 0;
LAB_0010471c:
  ipc_log_string(uVar2,"%s: enter",*(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30));
  return 0;
}



//------------------------------------------------------------
// exit_ffs_func_unbind @ 00104750 size=396
// signature: undefined exit_ffs_func_unbind(void)
// callers: []
//------------------------------------------------------------

undefined8 exit_ffs_func_unbind(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x38);
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar4) {
      lVar3 = 0;
LAB_00104894:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_001048a4;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar3 = 1;
        goto LAB_00104894;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar3 = 2;
          goto LAB_00104894;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar3 = 3;
            goto LAB_00104894;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar3 = 4;
              goto LAB_00104894;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar3 = 5;
                goto LAB_00104894;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar3 = 6;
                  goto LAB_00104894;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar3 = 7;
                    goto LAB_00104894;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar3 = 8;
                      goto LAB_00104894;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1048dc);
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
  uVar2 = 0;
LAB_001048a4:
  ipc_log_string(uVar2,"%s: exit: state %d setup_state %d flag %lu",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),*(undefined4 *)(lVar4 + 0x70),
                 *(undefined4 *)(lVar4 + 0x74),*(undefined8 *)(lVar4 + 0xa0));
  return 0;
}



//------------------------------------------------------------
// entry_ffs_func_unbind @ 001048e0 size=412
// signature: undefined entry_ffs_func_unbind(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_func_unbind(long param_1,long param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = *(long *)(*(long *)(param_2 + 8) + -0x28);
  lVar5 = *(long *)(*(long *)(param_2 + 8) + 200);
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar4) {
      lVar3 = 0;
LAB_00104a2c:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_00104a3c;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar3 = 1;
        goto LAB_00104a2c;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar3 = 2;
          goto LAB_00104a2c;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar3 = 3;
            goto LAB_00104a2c;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar3 = 4;
              goto LAB_00104a2c;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar3 = 5;
                goto LAB_00104a2c;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar3 = 6;
                  goto LAB_00104a2c;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar3 = 7;
                    goto LAB_00104a2c;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar3 = 8;
                      goto LAB_00104a2c;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x104a7c);
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
  uVar2 = 0;
LAB_00104a3c:
  *(long *)(param_1 + 0x38) = lVar4;
  ipc_log_string(uVar2,"%s: enter: state %d setup_state %d flag %lu refcnt %u",
                 *(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30),*(undefined4 *)(lVar4 + 0x70),
                 *(undefined4 *)(lVar4 + 0x74),*(undefined8 *)(lVar4 + 0xa0),
                 *(undefined4 *)(lVar5 + 0xc0));
  return 0;
}



//------------------------------------------------------------
// exit_ffs_closed @ 00104a80 size=456
// signature: undefined exit_ffs_closed(void)
// callers: []
//------------------------------------------------------------

undefined8 exit_ffs_closed(long param_1)

{
  code *pcVar1;
  char *pcVar2;
  undefined8 uVar3;
  long lVar4;
  uint uVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x30);
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar6) {
      lVar4 = 0;
LAB_00104c00:
      uVar3 = (&ipc_log_s)[lVar4 * 8];
      uVar5 = (uint)*(undefined8 *)(lVar6 + 0xa0);
      goto joined_r0x00104b84;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar6) {
        lVar4 = 1;
        goto LAB_00104c00;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar6) {
          lVar4 = 2;
          goto LAB_00104c00;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar6) {
            lVar4 = 3;
            goto LAB_00104c00;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar6) {
              lVar4 = 4;
              goto LAB_00104c00;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar6) {
                lVar4 = 5;
                goto LAB_00104c00;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar6) {
                  lVar4 = 6;
                  goto LAB_00104c00;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar6) {
                    lVar4 = 7;
                    goto LAB_00104c00;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar6) {
                      lVar4 = 8;
                      goto LAB_00104c00;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x104c48);
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
  uVar3 = 0;
  uVar5 = (uint)*(undefined8 *)(lVar6 + 0xa0);
joined_r0x00104b84:
  if ((uVar5 >> 1 & 1) == 0) {
    if ((((*(long *)(lVar6 + 0xd0) != 0) &&
         (lVar6 = *(long *)(*(long *)(lVar6 + 0xd0) + 8), lVar6 != 0)) &&
        (*(char *)(lVar6 + 0xc4) == '\0')) &&
       ((*(long *)(lVar6 + 0x30) != 0 && (*(int *)(lVar6 + 0x1c) != 0)))) {
      return 0;
    }
    pcVar2 = "%s: exit error";
  }
  else {
    pcVar2 = "%s: unreg gadget done";
  }
  ipc_log_string(uVar3,pcVar2,*(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30));
  return 0;
}



//------------------------------------------------------------
// entry_ffs_closed @ 00104c4c size=392
// signature: undefined entry_ffs_closed(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_ffs_closed(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *param_2;
  if (0 < num_devices) {
    if (DAT_00105ab0 == lVar4) {
      lVar3 = 0;
LAB_00104d90:
      uVar2 = (&ipc_log_s)[lVar3 * 8];
      goto LAB_00104da0;
    }
    if (num_devices != 1) {
      if (DAT_00105af0 == lVar4) {
        lVar3 = 1;
        goto LAB_00104d90;
      }
      if (num_devices != 2) {
        if (DAT_00105b30 == lVar4) {
          lVar3 = 2;
          goto LAB_00104d90;
        }
        if (num_devices != 3) {
          if (DAT_00105b70 == lVar4) {
            lVar3 = 3;
            goto LAB_00104d90;
          }
          if (num_devices != 4) {
            if (DAT_00105bb0 == lVar4) {
              lVar3 = 4;
              goto LAB_00104d90;
            }
            if (num_devices != 5) {
              if (DAT_00105bf0 == lVar4) {
                lVar3 = 5;
                goto LAB_00104d90;
              }
              if (num_devices != 6) {
                if (DAT_00105c30 == lVar4) {
                  lVar3 = 6;
                  goto LAB_00104d90;
                }
                if (num_devices != 7) {
                  if (DAT_00105c70 == lVar4) {
                    lVar3 = 7;
                    goto LAB_00104d90;
                  }
                  if (num_devices != 8) {
                    if (DAT_00105cb0 == lVar4) {
                      lVar3 = 8;
                      goto LAB_00104d90;
                    }
                    if (num_devices != 9) {
                    /* WARNING: Does not return */
                      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x104dd4);
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
  uVar2 = 0;
LAB_00104da0:
  *(long *)(param_1 + 0x30) = lVar4;
  ipc_log_string(uVar2,"%s: enter",*(undefined8 *)(**(long **)(param_1 + 0x18) + 0x30));
  return 0;
}



//------------------------------------------------------------
// create_ipc_context_work @ 00104dd8 size=784
// signature: undefined create_ipc_context_work(void)
// callers: []
//------------------------------------------------------------

void create_ipc_context_work(long param_1)

{
  char *__s2;
  uint uVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  char local_70 [8];
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined2 local_40;
  long local_38;
  
  uVar1 = num_devices;
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  __s2 = (char *)(param_1 + 0x38);
  local_40 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = (char  [8])s_usb_ffs__00107240._0_8_;
  uStack_68 = 0;
  if (((int)num_devices < 1) || (DAT_00105ab8 == '\0')) {
LAB_00104f98:
    if ((int)uVar1 < 9) {
      strlcat(local_70,__s2,0x32);
      uVar4 = ipc_log_context_create(10,local_70,0);
      if ((uVar4 == 0) || (0xfffffffffffff000 < uVar4)) {
        _printk(&DAT_001056c4,"create_ipc_context_work",__s2);
      }
      else {
        uVar6 = (ulong)num_devices;
        if (8 < num_devices) {
LAB_001050e4:
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1050e8);
          (*pcVar2)();
        }
        (&ipc_log_s)[uVar6 * 8] = uVar4;
        if (0x240 < (uVar6 << 6 | 8)) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(1,0x1050e4);
          (*pcVar2)();
        }
        (&DAT_00105ab0)[uVar6 * 8] = *(undefined8 *)(param_1 + 0x30);
        strscpy(&DAT_00105ab8 + uVar6 * 0x40,__s2,0x29);
        num_devices = num_devices + 1;
      }
      goto LAB_00105090;
    }
  }
  else {
    iVar3 = strcmp(&DAT_00105ab8,__s2);
    if (iVar3 == 0) {
      lVar5 = 0;
LAB_0010507c:
      (&DAT_00105ab0)[lVar5 * 8] = *(undefined8 *)(param_1 + 0x30);
      goto LAB_00105090;
    }
    if ((uVar1 == 1) || (DAT_00105af8 == '\0')) goto LAB_00104f98;
    iVar3 = strcmp(&DAT_00105af8,__s2);
    if (iVar3 == 0) {
      lVar5 = 1;
      goto LAB_0010507c;
    }
    if ((uVar1 == 2) || (DAT_00105b38 == '\0')) goto LAB_00104f98;
    iVar3 = strcmp(&DAT_00105b38,__s2);
    if (iVar3 == 0) {
      lVar5 = 2;
      goto LAB_0010507c;
    }
    if ((uVar1 == 3) || (DAT_00105b78 == '\0')) goto LAB_00104f98;
    iVar3 = strcmp(&DAT_00105b78,__s2);
    if (iVar3 == 0) {
      lVar5 = 3;
      goto LAB_0010507c;
    }
    if ((uVar1 == 4) || (DAT_00105bb8 == '\0')) goto LAB_00104f98;
    iVar3 = strcmp(&DAT_00105bb8,__s2);
    if (iVar3 == 0) {
      lVar5 = 4;
      goto LAB_0010507c;
    }
    if ((uVar1 == 5) || (DAT_00105bf8 == '\0')) goto LAB_00104f98;
    iVar3 = strcmp(&DAT_00105bf8,__s2);
    if (iVar3 == 0) {
      lVar5 = 5;
      goto LAB_0010507c;
    }
    if ((uVar1 == 6) || (DAT_00105c38 == '\0')) goto LAB_00104f98;
    iVar3 = strcmp(&DAT_00105c38,__s2);
    if (iVar3 == 0) {
      lVar5 = 6;
      goto LAB_0010507c;
    }
    if ((uVar1 == 7) || (DAT_00105c78 == '\0')) goto LAB_00104f98;
    iVar3 = strcmp(&DAT_00105c78,__s2);
    if (iVar3 == 0) {
      lVar5 = 7;
      goto LAB_0010507c;
    }
    if ((uVar1 == 8) || (DAT_00105cb8 == '\0')) goto LAB_00104f98;
    iVar3 = strcmp(&DAT_00105cb8,__s2);
    if (iVar3 == 0) {
      lVar5 = 8;
      goto LAB_0010507c;
    }
    if (uVar1 != 9) goto LAB_001050e4;
  }
  _printk(&DAT_001054b2);
LAB_00105090:
  kfree(param_1);
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001050ec size=176
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  long lVar4;
  
  ipc_wq = alloc_workqueue("ipc_wq",0xa0002,1);
  if (ipc_wq == 0) {
    _printk(&DAT_00105976,"kretprobe_init");
    uVar2 = 0xfffffff4;
  }
  else {
    lVar4 = 0x1f;
    puVar3 = &ffsprobes;
    do {
      iVar1 = register_kretprobe(puVar3);
      if (iVar1 < 0) {
        _printk(&DAT_00105a25,*(undefined8 *)(puVar3 + 0x30),iVar1);
      }
      puVar3 = puVar3 + 0xb0;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// cleanup_module @ 001051a0 size=236
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  code *pcVar1;
  int iVar2;
  undefined1 *puVar3;
  long lVar4;
  long lVar5;
  
  destroy_workqueue(ipc_wq);
  if (0 < num_devices) {
    lVar4 = 0;
    lVar5 = 0;
    iVar2 = num_devices;
    do {
      if (lVar5 == 9) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10528c);
        (*pcVar1)();
      }
      if (0x240 < lVar4 + 8U) {
LAB_00105284:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(1,0x105288);
        (*pcVar1)();
      }
      if (*(long *)((long)&DAT_00105ab0 + lVar4) != 0) {
        if (lVar5 == 9) goto LAB_00105284;
        ipc_log_context_destroy(*(undefined8 *)((long)&ipc_log_s + lVar4));
        iVar2 = num_devices;
        *(undefined8 *)((long)&ipc_log_s + lVar4) = 0;
      }
      lVar5 = lVar5 + 1;
      lVar4 = lVar4 + 0x40;
    } while (lVar5 < iVar2);
  }
  lVar5 = 0x1f;
  puVar3 = &ffsprobes;
  do {
    unregister_kretprobe(puVar3);
    if (0 < *(int *)(puVar3 + 0x94)) {
      _printk(&DAT_00105806,*(int *)(puVar3 + 0x94),*(undefined8 *)(puVar3 + 0x30));
    }
    puVar3 = puVar3 + 0xb0;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  return;
}



//------------------------------------------------------------
// alloc_workqueue @ 00108000 size=1
// signature: undefined alloc_workqueue(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_kretprobe @ 00108008 size=1
// signature: undefined register_kretprobe(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_kretprobe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00108010 size=1
// signature: undefined _printk(void)
// callers: [create_ipc_context_work, init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 00108018 size=1
// signature: undefined destroy_workqueue(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 00108020 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_kretprobe @ 00108028 size=1
// signature: undefined unregister_kretprobe(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_kretprobe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00108030 size=1
// signature: undefined ipc_log_string(void)
// callers: [exit___ffs_ep0_queue_wait, exit_ffs_epfile_ioctl, entry_ffs_func_eps_disable, exit_ffs_ep0_write, entry_functionfs_bind, entry_ffs_func_suspend, entry_ffs_epfile_read_iter, exit_ffs_aio_cancel, entry_ffs_data_opened, entry_ffs_user_copy_worker, entry_ffs_epfile_release, exit_ffs_func_bind, entry_ffs_func_bind, entry_ffs_func_set_alt, entry_ffs_data_closed, entry_ffs_epfile_async_io_complete, entry___ffs_ep0_queue_wait, entry_ffs_epfile_io, exit_ffs_epfile_write_iter, entry_ffs_epfile_write_iter, entry_ffs_reset_work, entry_ffs_func_unbind, exit_ffs_func_unbind, entry_ffs_func_resume, exit_ffs_closed, entry_ffs_ep0_write, entry_ffs_epfile_open, exit_ffs_ep0_read, entry_ffs_data_put, entry_ffs_func_disable, entry_ffs_ep0_release, exit_ffs_epfile_read_iter, entry_ffs_ep0_open, exit_functionfs_bind, entry_ffs_epfile_ioctl, entry_ffs_closed, exit_ffs_epfile_io, entry_ffs_func_setup, entry_ffs_ep0_ioctl, entry_ffs_data_clear, entry_ffs_aio_cancel, entry_ffs_ep0_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00108040 size=1
// signature: undefined kmalloc_trace(void)
// callers: [entry_ffs_sb_fill]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00108048 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [entry_ffs_sb_fill]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00108050 size=1
// signature: undefined strscpy(void)
// callers: [entry_ffs_sb_fill, create_ipc_context_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00108058 size=1
// signature: undefined queue_work_on(void)
// callers: [entry_ffs_sb_fill]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00108060 size=1
// signature: undefined fortify_panic(void)
// callers: [entry_ffs_sb_fill]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00108068 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [create_ipc_context_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlcat @ 00108070 size=1
// signature: undefined strlcat(void)
// callers: [create_ipc_context_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcat(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00108078 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [create_ipc_context_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00108080 size=1
// signature: undefined kfree(void)
// callers: [create_ipc_context_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00108088 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [create_ipc_context_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



