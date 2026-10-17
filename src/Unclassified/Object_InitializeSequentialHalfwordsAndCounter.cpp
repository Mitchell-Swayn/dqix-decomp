// Original ARM and access widths reviewed; resource addresses follow exact relocations.
#include <GameState/GameState.h>
#include <Resource/Script.h>
extern "C" {int GameState_ReadAttributeBits12To19(void*,int);void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);extern char* data_02110370[];}struct SignedSix{signed char value:6;unsigned char unused:1;unsigned char flag:1;};struct Direction{unsigned low:24;signed int value:3;unsigned high:5;};
extern "C" char data_02108da8[];extern "C" char data_020f0ca0[];
extern "C" char data_021536c4[];extern "C" char data_020f2e2c[];
extern "C" char data_020fdd30[];extern "C" char data_020ef6f4[];
// Original: arm9/main @ 0x02012244; symbol: func_02012244; size: 0x54.
extern "C" void Object_InitializeSequentialHalfwordsAndCounter(char* p){short* q=(short*)p;q[2]=1;q[3]=2;q[4]=3;q[5]=4;q[6]=5;q[7]=6;q[8]=7;q[9]=0;q[10]=1000;p[28]=1;*(int*)(p+24)=0;}
