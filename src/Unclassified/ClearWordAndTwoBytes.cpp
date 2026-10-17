// Reviewed original ARM instructions; field semantics unresolved.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" char data_0210f844[];extern "C" volatile unsigned int data_02111824[];extern "C" unsigned int data_020fe9a4[];
// Original: arm9/main @ 0x020401E4; symbol: func_020401e4; size: 0x18.
extern "C" void ClearWordAndTwoBytes(char* p){*(int*)(p+8)=0;*(int*)p=0;p[4]=0;p[5]=0;}
