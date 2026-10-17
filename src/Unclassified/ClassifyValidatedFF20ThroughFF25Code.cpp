#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" int IsCopiedHalfwordHighByteFF(void*,unsigned short*);
// Original: arm9/main @ 0x02044420; symbol: func_02044420; size: 0x74.
extern "C" int ClassifyValidatedFF20ThroughFF25Code(void* object,const void* data) {
 int result=0; unsigned short code;memcpy(&code,data,2);
 if(!IsCopiedHalfwordHighByteFF(object,&code))return 0;
 switch(code){case 0xff20:case 0xff21:case 0xff23:case 0xff24:result=1;break;case 0xff22:case 0xff25:result=2;break;}
 return result;
}