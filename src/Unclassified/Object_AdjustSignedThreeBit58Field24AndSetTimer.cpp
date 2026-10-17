// Original ARM field widths and control flow reviewed; Script context uses original relocation targets.
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <Resource/Script.h>
extern "C" {void* memcpy(void*,const void*,unsigned);void ClearField18Flag1AndField58Flag7000000AndBytes76And99(void*);int GameState_ReadAttributeBits12To19(void*,int);extern char data_0214e33c[];extern char data_020f2308[];}struct Direction{unsigned low:24;signed int value:3;unsigned high:5;};
// Original: arm9/main @ 0x0208806C; symbol: func_0208806c; size: 0x78.
extern "C" int Object_AdjustSignedThreeBit58Field24AndSetTimer(char* p,int add){Direction* q=(Direction*)(p+88);int v=q->value+add;if(v>2)v=2;if(v< -2)v=-2;if(!v){ClearField18Flag1AndField58Flag7000000AndBytes76And99(p);return 0;}q->value=v;p[118]=5;p[153]=0;*(unsigned*)(p+24)|=1;return q->value;}
