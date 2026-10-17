// Reviewed original ARM instructions; field semantics unresolved.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" char data_0210f844[];extern "C" volatile unsigned int data_02111824[];extern "C" unsigned int data_020fe9a4[];
// Original: arm9/main @ 0x020A8170; symbol: func_020a8170; size: 0x1C.
extern "C" void ClearPointerHalfwordsAndWordRecord(char* p){*(int*)p=0;*(short*)(p+4)=0;*(short*)(p+6)=0;*(int*)(p+8)=0;*(short*)(p+12)=0;}
