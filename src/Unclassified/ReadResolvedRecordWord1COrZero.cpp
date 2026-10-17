// Reviewed original ARM instructions; field semantics unresolved.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" char data_0210f844[];extern "C" volatile unsigned int data_02111824[];extern "C" unsigned int data_020fe9a4[];
// Original: arm9/main @ 0x02055138; symbol: func_02055138; size: 0x18.
extern "C" int ReadResolvedRecordWord1COrZero(char* p){char* q=ReadSignedWordAtOffset4(p);int v;if(q==0)v=0;else v=*(int*)(q+0x1c);return v;}
