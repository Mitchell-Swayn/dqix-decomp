// Reviewed original ARM instructions; field semantics unresolved.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" char data_0210f844[];extern "C" volatile unsigned int data_02111824[];extern "C" unsigned int data_020fe9a4[];
// Original: arm9/main @ 0x0202E7D4; symbol: func_0202e7d4; size: 0x1C.
extern "C" void Object_ReadVectorComponentsAtOffset70(int* p,int* x,int* y,int* z){*x=p[0x1c];*y=p[0x1d];*z=p[0x1e];}
