// Original ARM field widths and control flow reviewed; Script context uses original relocation targets.
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <Resource/Script.h>
extern "C" {void* memcpy(void*,const void*,unsigned);void ClearField18Flag1AndField58Flag7000000AndBytes76And99(void*);int GameState_ReadAttributeBits12To19(void*,int);extern char data_0214e33c[];extern char data_020f2308[];}struct Direction{unsigned low:24;signed int value:3;unsigned high:5;};
// Original: arm9/main @ 0x020724F4; symbol: func_020724f4; size: 0x6C.
extern "C" void Object_AllocateFortyFourByteEntriesAndInvalidateKeys(char* p,SafeAllocator* a,unsigned count){if(*(void**)p)return;*(short*)(p+6)=0;*(short*)(p+4)=count;*(void**)p=a->Allocate(count*44);for(unsigned short i=0;i<count;++i)*(short*)(*(char**)p+i*44)=-1;}
