// Original ARM and access widths reviewed; resource addresses follow exact relocations.
#include <GameState/GameState.h>
#include <Resource/Script.h>
extern "C" {int GameState_ReadAttributeBits12To19(void*,int);void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);extern char* data_02110370[];}struct SignedSix{signed char value:6;unsigned char unused:1;unsigned char flag:1;};struct Direction{unsigned low:24;signed int value:3;unsigned high:5;};
extern "C" char data_02108da8[];extern "C" char data_020f0ca0[];
extern "C" char data_021536c4[];extern "C" char data_020f2e2c[];
extern "C" char data_020fdd30[];extern "C" char data_020ef6f4[];
// Original: arm9/main @ 0x02086E9C; symbol: func_02086e9c; size: 0x54.
extern "C" int ReadFirstFlaggedRecordSignedSixBitValue(char* p){for(unsigned char i=0;i<*(unsigned char*)(p+0x2c8c);++i){SignedSix* q=(SignedSix*)(p+0xf80+i*0x23c);if(q->flag)return q->value;}return -1;}
