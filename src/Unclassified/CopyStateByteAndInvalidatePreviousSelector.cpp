// Reviewed original ARM instructions; field semantics unresolved.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" char data_0210f844[];extern "C" volatile unsigned int data_02111824[];extern "C" unsigned int data_020fe9a4[];
// Original: arm9/main @ 0x020E25CC; symbol: func_020e25cc; size: 0x1C.
extern "C" void CopyStateByteAndInvalidatePreviousSelector(char* p){char v=p[0x16];p[0x14]=v;p[0x15]=-1;p[0x17]=0;}
