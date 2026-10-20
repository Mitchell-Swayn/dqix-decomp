#include <globaldefs.h>
ARM
extern "C" unsigned long long _Z19GetCurrentTimestampv();
extern "C" int Network_StartConfiguredWirelessRequest(const char*,const unsigned char*,int);
extern "C" unsigned Network_GetWirelessLifecycleState();
extern "C" unsigned Ov031_SelectValueFromObjectLowBits(const volatile unsigned char*);
extern "C" unsigned Ov031_DecodeModeToFlag(void*);

#define F(T,o) (*(T*)(self+(o)))
#pragma always_inline on
inline void ClearRequestMode(char* self){unsigned value=F(unsigned char,0xd0b);value&=~4;value&=~8;F(unsigned char,0xd0b)=value;}
// Original: arm9/ov031 @ 0x02213DD8; symbol: func_ov031_02213dd8; size: 0x13C.
// Retries a selected wireless configuration and records terminal status per selected slot.
extern "C" int Network_RetrySelectedWirelessRequest(char* self){
int state=Network_GetWirelessLifecycleState();
int offset;char* configs=self+0x470;
offset=(short)F(unsigned char,0xd13)*(short)0xc0;
if(state==3){
unsigned mode=Ov031_SelectValueFromObjectLowBits((unsigned char*)self);
unsigned char attempt=++F(unsigned char,0xd15);
if(attempt>3){F(unsigned char,0xd15)=0;(*(unsigned char*)((self+F(unsigned char,0xd13)*4)+0x444))=1;return 9;}
if(attempt!=1){
if(F(unsigned char,0xd14)==1){ClearRequestMode(self);}
else if(F(unsigned char,0xd14)==2){F(unsigned char,0xd15)=0;(*(unsigned char*)((self+F(unsigned char,0xd13)*4)+0x444))=3;return 9;}
else if(F(unsigned char,0xd14)==3){F(unsigned char,0xd15)=0;(*(unsigned char*)((self+F(unsigned char,0xd13)*4)+0x444))=4;return 9;}
else if(attempt==3){ClearRequestMode(self);}
}
unsigned extra=Ov031_DecodeModeToFlag(self);
Network_StartConfiguredWirelessRequest(configs+offset,(unsigned char*)self+0xcb8,mode|extra);
}else if(state==9){F(unsigned char,0xd15)=0;F(unsigned long long,0xcb0)=_Z19GetCurrentTimestampv();return 10;}
return 8;
}
