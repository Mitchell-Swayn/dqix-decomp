#include <globaldefs.h>
ARM
extern "C" char data_020ef078[];extern "C" int sprintf(char*,const char*,...);
// Original: arm9/main @ 0x0204887C; symbol: func_0204887c; size: 0x30.
extern "C" void Object_ReplaceRecordAndCopyPreviousName(unsigned char* p,unsigned char* next) { unsigned char* old=*(unsigned char**)(p+0x148);*(unsigned char**)(p+0x148)=next;if(!old)return;sprintf((char*)*(unsigned char**)(p+0x148)+0x2c,data_020ef078,(char*)old+0x2c); }
