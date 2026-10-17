extern "C" unsigned int data_021117ec[]; extern "C" volatile int data_02111808; unsigned int GetIRQInterruptState(); void HandleCommandReceivedFromArm7();
// Original: arm9/main @ 0x020CE188; symbol: func_020ce188; size: 0x50.
 extern "C" void IPC_PollPendingReplyWhenInterruptsUnavailable() { volatile int *pending=&data_02111808; if(!data_021117ec[7])return; volatile unsigned short *enabled=(volatile unsigned short *)0x04000208; do { if(GetIRQInterruptState()==128 || !*enabled)HandleCommandReceivedFromArm7(); }while(*pending); }
