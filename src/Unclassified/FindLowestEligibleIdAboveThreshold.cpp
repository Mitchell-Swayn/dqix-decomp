// Original ARM field widths and control flow reviewed; Script context uses original relocation targets.
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <Resource/Script.h>
extern "C" {void* memcpy(void*,const void*,unsigned);void ClearField18Flag1AndField58Flag7000000AndBytes76And99(void*);int GameState_ReadAttributeBits12To19(void*,int);extern char data_0214e33c[];extern char data_020f2308[];}struct Direction{unsigned low:24;signed int value:3;unsigned high:5;};
// Original: arm9/main @ 0x02072238; symbol: func_02072238; size: 0x6C.
extern "C" char* FindLowestEligibleIdAboveThreshold(char* p,int threshold){unsigned count=*(unsigned short*)(p+10);char* data=*(char**)(p+4);char* result=0;int best=32767;for(unsigned short i=0;i<count;++i){char* q=data+i*32;if((*(unsigned*)(q+16)<<10)>>31){int id=*(short*)(q+26);if(id>threshold&&best>id&&*(short*)(q+22)<=0){best=id;result=q;}}}return result;}
