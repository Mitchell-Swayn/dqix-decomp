// Reviewed original ARM fields and signedness; global ownership resolved through original relocation.
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
extern "C" {char* FindThirtyTwoByteRecordByHalfwordKey(void*,int);void* memset(void*,int,unsigned);extern char data_0210f3c0[];}
// Original: arm9/main @ 0x02092D18; symbol: func_02092d18; size: 0x48.
extern "C" int GameState_FindByteKeyInFourSlots(void*,int key){char* p=(char*)GameState::GetInstance();for(unsigned char i=0;i<4;++i)if(*((unsigned char*)p+i+0x7f76)==key)return (signed char)i;return -1;}
