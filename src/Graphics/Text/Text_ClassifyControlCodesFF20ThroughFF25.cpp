#pragma thumb off
#pragma optimization_level 4

extern "C" {void* memcpy(void*,const void*,unsigned);int TextStream_IsControlToken(void*,const unsigned short*);}
// Original: arm9/main @ 0x0206ABF8; symbol: func_0206abf8; size: 0x74.
extern "C" unsigned Text_ClassifyControlCodesFF20ThroughFF25(void* owner,const void* input){unsigned short value;unsigned result=0;memcpy(&value,input,2);if(!TextStream_IsControlToken(owner,&value))return result;switch(value){case 0xff20:case 0xff21:case 0xff23:case 0xff24:result=1;break;case 0xff22:case 0xff25:result=2;break;}return result;}
