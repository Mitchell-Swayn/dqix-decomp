// Reviewed original ARM instructions; field semantics unresolved.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" char data_0210f844[];extern "C" volatile unsigned int data_02111824[];extern "C" unsigned int data_020fe9a4[];
// Original: arm9/main @ 0x02053CDC; symbol: func_02053cdc; size: 0x1C.
extern "C" int TestEitherField1B4Or1B8Positive(char* p){return *(int*)(p+0x1b4)>0 || *(int*)(p+0x1b8)>0;}
