// Decompiled by Ghidra 12.2
// Program: cmd-db.ko
// Image base: 00100000

//------------------------------------------------------------
// cmd_db_ready @ 0010022c size=48
// signature: undefined cmd_db_ready(void)
// callers: []
//------------------------------------------------------------

undefined4 cmd_db_ready(void)

{
  undefined4 uVar1;
  
  if (cmd_db_header == 0) {
    return 0xfffffdfb;
  }
  uVar1 = 0xffffffea;
  if (*(int *)(cmd_db_header + 4) == 0xc0330db) {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// cmd_db_read_addr @ 00100260 size=224
// signature: undefined cmd_db_read_addr(void)
// callers: []
//------------------------------------------------------------

void cmd_db_read_addr(char *param_1)

{
  long lVar1;
  ushort uVar2;
  long lVar3;
  undefined4 uVar4;
  long lVar5;
  uint uVar6;
  long *plVar7;
  long local_30;
  long local_28;
  
  lVar3 = cmd_db_header;
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  if ((cmd_db_header != 0) && (*(int *)(cmd_db_header + 4) == 0xc0330db)) {
    strncpy((char *)&local_30,param_1,8);
    lVar5 = 0;
    while (lVar1 = lVar3 + lVar5 * 0x10, *(short *)(lVar1 + 8) != 0) {
      uVar2 = *(ushort *)(lVar1 + 0xe);
      uVar6 = (uint)uVar2;
      if (uVar2 != 0) {
        plVar7 = (long *)(lVar3 + 0x90 + (ulong)*(ushort *)(lVar3 + lVar5 * 0x10 + 10));
        do {
          if (*plVar7 == local_30) {
            uVar4 = (undefined4)plVar7[2];
            goto LAB_00100314;
          }
          plVar7 = plVar7 + 3;
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
      lVar5 = lVar5 + 1;
      if (lVar5 == 8) break;
    }
  }
  uVar4 = 0;
LAB_00100314:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// cmd_db_read_aux_data @ 00100344 size=276
// signature: undefined cmd_db_read_aux_data(void)
// callers: []
//------------------------------------------------------------

void cmd_db_read_aux_data(char *param_1,ulong *param_2)

{
  long lVar1;
  ushort uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  uint uVar7;
  long local_30;
  long local_28;
  
  lVar3 = cmd_db_header;
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  if (cmd_db_header == 0) {
    lVar4 = -0x205;
  }
  else if (*(int *)(cmd_db_header + 4) == 0xc0330db) {
    strncpy((char *)&local_30,param_1,8);
    lVar5 = 0;
    lVar4 = -0x13;
    do {
      lVar1 = lVar3 + lVar5 * 0x10;
      if (*(short *)(lVar1 + 8) == 0) {
        lVar4 = -0x13;
        break;
      }
      uVar2 = *(ushort *)(lVar1 + 0xe);
      uVar7 = (uint)uVar2;
      if (uVar2 != 0) {
        plVar6 = (long *)(lVar3 + 0x90 + (ulong)*(ushort *)(lVar3 + lVar5 * 0x10 + 10));
        do {
          if (*plVar6 == local_30) {
            if (param_2 != (ulong *)0x0) {
              *param_2 = (ulong)*(ushort *)((long)plVar6 + 0x14);
            }
            lVar4 = lVar3 + 0x90 + (ulong)*(ushort *)((long)plVar6 + 0x16) +
                    (ulong)*(ushort *)(lVar3 + lVar5 * 0x10 + 0xc);
            goto LAB_00100424;
          }
          plVar6 = plVar6 + 3;
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
      }
      lVar5 = lVar5 + 1;
    } while (lVar5 != 8);
  }
  else {
    lVar4 = -0x16;
  }
LAB_00100424:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// cmd_db_match_resource_addr @ 0010045c size=64
// signature: undefined cmd_db_match_resource_addr(void)
// callers: []
//------------------------------------------------------------

undefined8 cmd_db_match_resource_addr(uint param_1,uint param_2)

{
  if (param_1 == param_2) {
    return 1;
  }
  if (((param_1 & 0xf0000) == 0x40000) && ((param_2 >> 4 & 0xffff) == (param_1 >> 4 & 0xffff))) {
    return 1;
  }
  return 0;
}



//------------------------------------------------------------
// cmd_db_read_slave_id @ 001004a0 size=228
// signature: undefined cmd_db_read_slave_id(void)
// callers: []
//------------------------------------------------------------

void cmd_db_read_slave_id(char *param_1)

{
  long lVar1;
  long lVar2;
  ushort uVar3;
  long lVar4;
  uint uVar5;
  long *plVar6;
  long local_30;
  long local_28;
  
  lVar2 = cmd_db_header;
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  if ((cmd_db_header != 0) && (*(int *)(cmd_db_header + 4) == 0xc0330db)) {
    strncpy((char *)&local_30,param_1,8);
    lVar4 = 0;
    while (lVar1 = lVar2 + lVar4 * 0x10, *(short *)(lVar1 + 8) != 0) {
      uVar3 = *(ushort *)(lVar1 + 0xe);
      uVar5 = (uint)uVar3;
      if (uVar3 != 0) {
        plVar6 = (long *)(lVar2 + 0x90 + (ulong)*(ushort *)(lVar2 + lVar4 * 0x10 + 10));
        do {
          if (*plVar6 == local_30) {
            uVar3 = *(ushort *)((long)plVar6 + 0x12) & 7;
            goto LAB_00100558;
          }
          plVar6 = plVar6 + 3;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
      lVar4 = lVar4 + 1;
      if (lVar4 == 8) break;
    }
  }
  uVar3 = 0;
LAB_00100558:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// cmd_db_is_standalone @ 00100588 size=52
// signature: undefined cmd_db_is_standalone(void)
// callers: []
//------------------------------------------------------------

byte cmd_db_is_standalone(void)

{
  bool bVar1;
  
  if (cmd_db_header == 0) {
    bVar1 = false;
  }
  else {
    bVar1 = *(int *)(cmd_db_header + 4) == 0xc0330db;
  }
  return bVar1 & *(byte *)(cmd_db_header + 0x8c);
}



//------------------------------------------------------------
// cmd_db_dev_probe @ 001005c0 size=236
// signature: undefined cmd_db_dev_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 cmd_db_dev_probe(long param_1)

{
  long lVar1;
  char *pcVar2;
  
  lVar1 = of_reserved_mem_lookup(*(undefined8 *)(param_1 + 0x2f8));
  if (lVar1 == 0) {
    pcVar2 = "failed to acquire memory region\n";
  }
  else {
    cmd_db_header = memremap(*(undefined8 *)(lVar1 + 0x20),*(undefined8 *)(lVar1 + 0x28),4);
    if (cmd_db_header == 0) {
      cmd_db_header = 0;
      return 0xfffffff4;
    }
    if (*(int *)(cmd_db_header + 4) == 0xc0330db) {
      debugfs_create_file("cmd-db",0x100,0,0,cmd_db_debugfs_ops);
      if (cmd_db_header != 0) {
        if (*(int *)(cmd_db_header + 4) != 0xc0330db) {
          return 0;
        }
        if ((*(uint *)(cmd_db_header + 0x8c) & 1) == 0) {
          return 0;
        }
        _printk(&DAT_00100e05);
      }
      return 0;
    }
    pcVar2 = "Invalid Command DB Magic\n";
  }
  _dev_err(param_1 + 0x10,pcVar2);
  return 0xffffffea;
}



//------------------------------------------------------------
// open_cmd_db_debugfs @ 001006b0 size=48
// signature: undefined open_cmd_db_debugfs(void)
// callers: []
//------------------------------------------------------------

void open_cmd_db_debugfs(long param_1,undefined8 param_2)

{
  single_open(param_2,cmd_db_debugfs_dump,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// cmd_db_debugfs_dump @ 001006e4 size=404
// signature: undefined cmd_db_debugfs_dump(void)
// callers: []
//------------------------------------------------------------

undefined8 cmd_db_debugfs_dump(undefined8 param_1)

{
  long lVar1;
  char *pcVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  
  seq_puts(param_1,"Command DB DUMP\n");
  lVar4 = 0;
  do {
    pcVar2 = "ARC";
    switch(*(undefined2 *)(cmd_db_header + lVar4 * 0x10 + 8)) {
    case 0:
      goto switchD_00100774_caseD_0;
    default:
      pcVar2 = "Unknown";
      break;
    case 3:
      break;
    case 4:
      pcVar2 = "VRM";
      break;
    case 5:
      pcVar2 = "BCM";
    }
    lVar1 = cmd_db_header + lVar4 * 0x10;
    seq_printf(param_1,"Slave %s (v%u.%u)\n",pcVar2,*(ushort *)(lVar1 + 0x10) >> 8,
               *(ushort *)(lVar1 + 0x10) & 0xff);
    seq_puts(param_1,"-------------------------\n");
    if (*(ushort *)(lVar1 + 0xe) != 0) {
      uVar5 = 0;
      lVar3 = cmd_db_header + (ulong)*(ushort *)(lVar1 + 10) + 0x90;
      do {
        seq_printf(param_1,"0x%05x: %*pEp",*(undefined4 *)(lVar3 + 0x10),8,lVar3);
        if (*(short *)(lVar3 + 0x14) != 0) {
          seq_printf(param_1," [%*ph]",*(short *)(lVar3 + 0x14),
                     cmd_db_header +
                     (ulong)*(ushort *)(lVar1 + 0xc) + (ulong)*(ushort *)(lVar3 + 0x16) + 0x90);
        }
        seq_putc(param_1,10);
        uVar5 = uVar5 + 1;
        lVar3 = lVar3 + 0x18;
      } while (uVar5 < *(ushort *)(lVar1 + 0xe));
    }
    lVar4 = lVar4 + 1;
  } while (lVar4 != 8);
switchD_00100774_caseD_0:
  return 0;
}



//------------------------------------------------------------
// init_module @ 001008f8 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&cmd_db_dev_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// strncpy @ 00102000 size=1
// signature: char * strncpy(char * __dest, char * __src, size_t __n)
// callers: [cmd_db_read_aux_data, cmd_db_read_addr, cmd_db_read_slave_id]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strncpy(char *__dest,char *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102008 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [cmd_db_read_aux_data, cmd_db_read_addr, cmd_db_read_slave_id]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00102010 size=1
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
// of_reserved_mem_lookup @ 00102018 size=1
// signature: undefined of_reserved_mem_lookup(void)
// callers: [cmd_db_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memremap @ 00102020 size=1
// signature: undefined memremap(void)
// callers: [cmd_db_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void memremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00102028 size=1
// signature: undefined debugfs_create_file(void)
// callers: [cmd_db_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102030 size=1
// signature: undefined _printk(void)
// callers: [cmd_db_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102038 size=1
// signature: undefined _dev_err(void)
// callers: [cmd_db_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 00102040 size=1
// signature: undefined single_open(void)
// callers: [open_cmd_db_debugfs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 00102048 size=1
// signature: undefined seq_puts(void)
// callers: [cmd_db_debugfs_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00102050 size=1
// signature: undefined seq_printf(void)
// callers: [cmd_db_debugfs_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_putc @ 00102058 size=1
// signature: undefined seq_putc(void)
// callers: [cmd_db_debugfs_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_putc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



