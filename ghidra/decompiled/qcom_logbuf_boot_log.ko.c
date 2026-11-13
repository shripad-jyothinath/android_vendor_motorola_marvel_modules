// Decompiled by Ghidra 12.2
// Program: qcom_logbuf_boot_log.ko
// Image base: 00100000

//------------------------------------------------------------
// dump_thread_func @ 001000c4 size=204
// signature: undefined dump_thread_func(void)
// callers: []
//------------------------------------------------------------

undefined8 dump_thread_func(void)

{
  long lVar1;
  ulong uVar2;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  uVar2 = kthread_should_stop();
  while ((uVar2 & 1) == 0) {
    while (uVar2 = kmsg_dump_get_line(&iter,1,boot_log_pos,boot_log_buf_left,&local_40),
          (uVar2 & 1) != 0) {
      boot_log_pos = boot_log_pos + local_40;
      boot_log_buf_left = boot_log_buf_left - (int)local_40;
      if (local_40 == 0) goto LAB_001000f4;
    }
    schedule_timeout_interruptible(0xfa);
    uVar2 = kthread_should_stop();
  }
LAB_001000f4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 00100194 size=52
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  if (dump_thread != 0) {
    kthread_stop();
  }
  kfree(boot_log_buf);
  return;
}



//------------------------------------------------------------
// init_module @ 001001cc size=428
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int init_module(void)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  long local_80 [8];
  
  lVar3 = sp_el0;
  local_80[7] = *(long *)(lVar3 + 0x638);
  local_80[0] = 0;
  local_80[1] = 0;
  local_80[5] = 0;
  local_80[6] = 0;
  local_80[3] = 0;
  local_80[4] = 0;
  local_80[2] = 0;
  lVar3 = kmalloc_large(0x80000,0xdc0);
  if (lVar3 == 0) {
    iVar2 = -0xc;
  }
  else {
    strscpy(local_80 + 1,"KBOOT_LOG",10);
    uVar4 = ((lVar3 << 8) >> 8) + 0x8000000000;
    local_80[6] = 0x80000;
    local_80[5] = _memstart_addr + uVar4;
    if (uVar4 >> 0x26 != 0) {
      local_80[5] = ((lVar3 << 8) >> 8) - _kimage_voffset;
    }
    local_80[4] = lVar3;
    iVar2 = msm_minidump_add_region(local_80 + 1);
    if (iVar2 < 0) {
      _printk(&DAT_0010048a);
      kfree(lVar3);
    }
    else {
      boot_log_buf_left = 0x80000;
      DataMemoryBarrier(2,3);
      boot_log_pos = lVar3;
      boot_log_buf = lVar3;
      kmsg_dump_rewind(&iter);
      uVar1 = DAT_00100380;
      kmsg_dump_get_buffer(&iter,1,boot_log_buf,0x80000,local_80);
      boot_log_pos = boot_log_pos + local_80[0];
      boot_log_buf_left = boot_log_buf_left - (int)local_80[0];
      iter = uVar1;
      uVar4 = kthread_create_on_node(dump_thread_func,0,0xffffffff,"dump_thread");
      if (uVar4 < 0xfffffffffffff001) {
        wake_up_process(uVar4);
      }
      iVar2 = 0;
      dump_thread = uVar4;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_80[7]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// kthread_should_stop @ 00101000 size=1
// signature: undefined kthread_should_stop(void)
// callers: [dump_thread_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_should_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmsg_dump_get_line @ 00101008 size=1
// signature: undefined kmsg_dump_get_line(void)
// callers: [dump_thread_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmsg_dump_get_line(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout_interruptible @ 00101010 size=1
// signature: undefined schedule_timeout_interruptible(void)
// callers: [dump_thread_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout_interruptible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00101018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [init_module, dump_thread_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_large @ 00101020 size=1
// signature: undefined kmalloc_large(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_large(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00101028 size=1
// signature: undefined strscpy(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_add_region @ 00101040 size=1
// signature: undefined msm_minidump_add_region(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_add_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmsg_dump_rewind @ 00101048 size=1
// signature: undefined kmsg_dump_rewind(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmsg_dump_rewind(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmsg_dump_get_buffer @ 00101050 size=1
// signature: undefined kmsg_dump_get_buffer(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmsg_dump_get_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_create_on_node @ 00101058 size=1
// signature: undefined kthread_create_on_node(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_create_on_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wake_up_process @ 00101060 size=1
// signature: undefined wake_up_process(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wake_up_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00101068 size=1
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
// kfree @ 00101070 size=1
// signature: undefined kfree(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_stop @ 00101078 size=1
// signature: undefined kthread_stop(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



