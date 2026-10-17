#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);extern "C" char data_020ef6d0[];extern "C" char data_020ef6ca[];extern "C" char data_020ef6d3[];
// Original: arm9/main @ 0x020265A8; symbol: func_020265a8; size: 0x94.
extern "C" void FormatThreeIndexedTextAndValueSlots(unsigned char* p,unsigned index,const char* text,unsigned value){if(index>=3)return;if(text&&*text){strcpy((char*)p+0x5fc+index*72,text);sprintf((char*)p+0x6d4+index*8,data_020ef6d0,value);return;}strcpy((char*)p+0x5fc+index*72,data_020ef6ca);strcpy((char*)p+0x6d4+index*8,data_020ef6d3);}
