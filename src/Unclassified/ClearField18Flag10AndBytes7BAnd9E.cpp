// Reviewed original ARM instructions; field semantics unresolved.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" char data_0210f844[];extern "C" volatile unsigned int data_02111824[];extern "C" unsigned int data_020fe9a4[];
// Original: arm9/main @ 0x02088D4C; symbol: func_02088d4c; size: 0x1C.
extern "C" void ClearField18Flag10AndBytes7BAnd9E(char* p){*(unsigned int*)(p+0x18)&=~16u;p[0x7b]=0;p[0x9e]=0;}
