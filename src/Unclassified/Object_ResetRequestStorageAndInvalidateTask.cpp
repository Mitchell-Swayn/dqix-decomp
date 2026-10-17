// Original ARM and access widths reviewed; resource addresses follow exact relocations.
#include <GameState/GameState.h>
#include <Resource/Script.h>
extern "C" {int GameState_ReadAttributeBits12To19(void*,int);void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);extern char* data_02110370[];}struct SignedSix{signed char value:6;unsigned char unused:1;unsigned char flag:1;};struct Direction{unsigned low:24;signed int value:3;unsigned high:5;};
extern "C" char data_02108da8[];extern "C" char data_020f0ca0[];
extern "C" char data_021536c4[];extern "C" char data_020f2e2c[];
extern "C" char data_020fdd30[];extern "C" char data_020ef6f4[];
// Original: arm9/main @ 0x02095518; symbol: func_02095518; size: 0x60.
extern "C" void Object_ResetRequestStorageAndInvalidateTask(char* p){*(int*)(p+160)=0;*(int*)(p+164)=0;*(int*)(p+168)=0;*(int*)(p+0x4c4)=-1;memset(p,0,160);memset(p+172,255,204);memset(p+0x178,0,0x330);memset(p+0x4a8,0,26);}
