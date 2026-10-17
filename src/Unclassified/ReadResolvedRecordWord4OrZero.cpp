// Reviewed original ARM instructions; field semantics unresolved.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" char data_0210f844[];extern "C" volatile unsigned int data_02111824[];extern "C" unsigned int data_020fe9a4[];
// Original: arm9/main @ 0x020550A8; symbol: func_020550a8; size: 0x18.
extern "C" int ReadResolvedRecordWord4OrZero(char* p){char* q=ReadSignedWordAtOffset4(p);int v;if(q==0)v=0;else v=*(int*)(q+4);return v;}
