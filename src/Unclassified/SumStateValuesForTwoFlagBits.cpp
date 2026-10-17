// Original ARM and access widths reviewed; resource addresses follow exact relocations.
#include <GameState/GameState.h>
#include <Resource/Script.h>
extern "C" {int GameState_ReadAttributeBits12To19(void*,int);void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);extern char* data_02110370[];}struct SignedSix{signed char value:6;unsigned char unused:1;unsigned char flag:1;};struct Direction{unsigned low:24;signed int value:3;unsigned high:5;};
extern "C" char data_02108da8[];extern "C" char data_020f0ca0[];
extern "C" char data_021536c4[];extern "C" char data_020f2e2c[];
extern "C" char data_020fdd30[];extern "C" char data_020ef6f4[];
// Original: arm9/main @ 0x02085C80; symbol: func_02085c80; size: 0x50.
extern "C" int SumStateValuesForTwoFlagBits(unsigned char* p){GameState* g=GameState::GetInstance();int v=0;if(p[0x8f3]&2)v+=GameState_ReadAttributeBits12To19(g,57);if(p[0x8f3]&32)v+=GameState_ReadAttributeBits12To19(g,61);return v;}
