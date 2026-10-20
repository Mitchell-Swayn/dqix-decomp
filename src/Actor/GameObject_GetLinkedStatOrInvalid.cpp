// Reviewed original instruction stream; opaque fields require later semantic naming.
// Original: arm9/main @ 0x02052DF8; symbol: func_02052df8; size: 0x1C.
extern "C" int GameObject_GetLinkedStatOrInvalid(char* p,int i){char* q=*(char**)(p+0x150);if(q)return *(short*)(q+i*2+0x488);return -1;}
