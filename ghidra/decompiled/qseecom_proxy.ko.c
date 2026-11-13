// Decompiled by Ghidra 12.2
// Program: qseecom_proxy.ko
// Image base: 00100000

//------------------------------------------------------------
// provide_qseecom_kernel_fun_ops @ 00100164 size=80
// signature: undefined provide_qseecom_kernel_fun_ops(void)
// callers: []
//------------------------------------------------------------

undefined8 provide_qseecom_kernel_fun_ops(undefined8 *param_1)

{
  undefined8 uVar1;
  
  if (param_1 == (undefined8 *)0x0) {
    _printk(&DAT_00100502);
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    DAT_00100630 = param_1[2];
    DAT_00100638 = param_1[3];
    qseecom_fun_ops = *param_1;
    DAT_00100628 = param_1[1];
  }
  return uVar1;
}



//------------------------------------------------------------
// qseecom_start_app @ 001001b8 size=160
// signature: undefined qseecom_start_app(void)
// callers: []
//------------------------------------------------------------

int qseecom_start_app(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  
  if (DAT_00100628 == (code *)0x0) {
    iVar2 = ___ratelimit(&qseecom_start_app__rs,"qseecom_start_app");
    if (iVar2 != 0) {
      _printk(&DAT_0010054e);
    }
    iVar2 = -0xb;
  }
  else {
    if (*(int *)(DAT_00100628 + -4) != 0x73f84108) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1001f0);
      (*pcVar1)();
    }
    iVar2 = (*DAT_00100628)();
    if (iVar2 != 0) {
      _printk(&DAT_00100585,"qseecom_start_app",param_2);
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// qseecom_shutdown_app @ 0010025c size=156
// signature: undefined qseecom_shutdown_app(void)
// callers: []
//------------------------------------------------------------

int qseecom_shutdown_app(void)

{
  code *pcVar1;
  int iVar2;
  
  if (DAT_00100630 == (code *)0x0) {
    iVar2 = ___ratelimit(qseecom_shutdown_app__rs,"qseecom_shutdown_app");
    if (iVar2 != 0) {
      _printk(&DAT_0010054e);
    }
    iVar2 = -0xb;
  }
  else {
    if (*(int *)(DAT_00100630 + -4) != -0xe215982) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100290);
      (*pcVar1)();
    }
    iVar2 = (*DAT_00100630)();
    if (iVar2 != 0) {
      _printk(&DAT_001005eb,"qseecom_shutdown_app",iVar2);
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// qseecom_send_command @ 001002fc size=156
// signature: undefined qseecom_send_command(void)
// callers: []
//------------------------------------------------------------

int qseecom_send_command(void)

{
  code *pcVar1;
  int iVar2;
  
  if (qseecom_fun_ops == (code *)0x0) {
    iVar2 = ___ratelimit(qseecom_send_command__rs,"qseecom_send_command");
    if (iVar2 != 0) {
      _printk(&DAT_0010054e);
    }
    iVar2 = -0xb;
  }
  else {
    if (*(int *)(qseecom_fun_ops + -4) != 0x34096af3) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100330);
      (*pcVar1)();
    }
    iVar2 = (*qseecom_fun_ops)();
    if (iVar2 != 0) {
      _printk(&DAT_001004bc,"qseecom_send_command",iVar2);
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// qseecom_process_listener_from_smcinvoke @ 0010039c size=156
// signature: undefined qseecom_process_listener_from_smcinvoke(void)
// callers: []
//------------------------------------------------------------

int qseecom_process_listener_from_smcinvoke(void)

{
  code *pcVar1;
  int iVar2;
  
  if (DAT_00100638 == (code *)0x0) {
    iVar2 = ___ratelimit(qseecom_process_listener_from_smcinvoke__rs,
                         "qseecom_process_listener_from_smcinvoke");
    if (iVar2 != 0) {
      _printk(&DAT_001005a1);
    }
    iVar2 = -0xb;
  }
  else {
    if (*(int *)(DAT_00100638 + -4) != -0x5ac95ca4) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1003d0);
      (*pcVar1)();
    }
    iVar2 = (*DAT_00100638)();
    if (iVar2 != 0) {
      _printk(&DAT_0010056e,"qseecom_process_listener_from_smcinvoke",iVar2);
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// _printk @ 00101000 size=1
// signature: undefined _printk(void)
// callers: [qseecom_process_listener_from_smcinvoke, qseecom_send_command, provide_qseecom_kernel_fun_ops, qseecom_shutdown_app, qseecom_start_app]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00101008 size=1
// signature: undefined ___ratelimit(void)
// callers: [qseecom_process_listener_from_smcinvoke, qseecom_send_command, qseecom_shutdown_app, qseecom_start_app]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



