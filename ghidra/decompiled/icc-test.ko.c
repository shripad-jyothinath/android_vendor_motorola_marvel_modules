// Decompiled by Ghidra 12.2
// Program: icc-test.ko
// Image base: 00100000

//------------------------------------------------------------
// get_write_op @ 001000e4 size=192
// signature: undefined get_write_op(void)
// callers: []
//------------------------------------------------------------

ulong get_write_op(undefined8 param_1,undefined8 param_2,ulong param_3,long *param_4)

{
  long lVar1;
  int iVar2;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = kstrtoul_from_user(param_2,param_3,10,&local_30);
  if (iVar2 == 0) {
    path = icc_get(icc_pdev + 0x10,src_port,dst_port);
    if (path < 0xfffffffffffff001) {
      *param_4 = *param_4 + param_3;
    }
    else {
      param_3 = path;
    }
  }
  else {
    param_3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// commit_write_op @ 001001a8 size=184
// signature: undefined commit_write_op(void)
// callers: []
//------------------------------------------------------------

ulong commit_write_op(undefined8 param_1,undefined8 param_2,ulong param_3,long *param_4)

{
  long lVar1;
  int iVar2;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = kstrtoul_from_user(param_2,param_3,10,&local_30);
  if (iVar2 == 0) {
    if (0xfffffffffffff000 < path) {
      param_3 = path;
      goto LAB_00100230;
    }
    iVar2 = icc_set_bw(path,avg_bw,peak_bw);
    if (iVar2 == 0) {
      *param_4 = *param_4 + param_3;
      goto LAB_00100230;
    }
  }
  param_3 = (long)iVar2;
LAB_00100230:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// init_module @ 00100264 size=288
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  undefined1 auVar1 [16];
  
  icc_pdev = platform_device_alloc("icc-test",0xfffffffe);
  platform_device_add();
  auVar1 = debugfs_create_dir("interconnect-test",0);
  debugfs_dir = auVar1._0_8_;
  if (debugfs_dir == 0) {
    _printk(&DAT_00100492,auVar1._8_8_,0);
  }
  debugfs_create_u32("src_port",0x180,debugfs_dir,&src_port);
  debugfs_create_u32("dst_port",0x180,debugfs_dir,&dst_port);
  debugfs_create_file(&DAT_00100474,0x80,debugfs_dir,0,&get_fops);
  debugfs_create_u32("avg_bw",0x180,debugfs_dir,&avg_bw);
  debugfs_create_u32("peak_bw",0x180,debugfs_dir,&peak_bw);
  debugfs_create_file("commit",0x80,debugfs_dir,0,&commit_fops);
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 00100388 size=84
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  if (path < 0xfffffffffffff001) {
    icc_put();
  }
  debugfs_remove(debugfs_dir);
  platform_device_del(icc_pdev);
  platform_device_put(icc_pdev);
  return;
}



//------------------------------------------------------------
// platform_device_alloc @ 00101000 size=1
// signature: undefined platform_device_alloc(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_add @ 00101008 size=1
// signature: undefined platform_device_add(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00101010 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_u32 @ 00101018 size=1
// signature: undefined debugfs_create_u32(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_u32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00101020 size=1
// signature: undefined debugfs_create_file(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00101028 size=1
// signature: undefined _printk(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_put @ 00101030 size=1
// signature: undefined icc_put(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00101038 size=1
// signature: undefined debugfs_remove(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_del @ 00101040 size=1
// signature: undefined platform_device_del(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_put @ 00101048 size=1
// signature: undefined platform_device_put(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoul_from_user @ 00101050 size=1
// signature: undefined kstrtoul_from_user(void)
// callers: [commit_write_op, get_write_op]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoul_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_get @ 00101058 size=1
// signature: undefined icc_get(void)
// callers: [get_write_op]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00101060 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [commit_write_op, get_write_op]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_bw @ 00101068 size=1
// signature: undefined icc_set_bw(void)
// callers: [commit_write_op]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



