// Reviewed original ARM instructions; field semantics unresolved.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" char data_0210f844[];extern "C" volatile unsigned int data_02111824[];extern "C" unsigned int data_020fe9a4[];
// Original: arm9/main @ 0x02088C38; symbol: func_02088c38; size: 0x1C.
extern "C" void ClearField18Flag2AndBytes6CAnd8F(char* p){*(unsigned int*)(p+0x18)&=~2u;p[0x6c]=0;p[0x8f]=0;}
