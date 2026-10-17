// Original ARM field widths and control flow reviewed; Script context uses original relocation targets.
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <Resource/Script.h>
extern "C" {void* memcpy(void*,const void*,unsigned);void ClearField18Flag1AndField58Flag7000000AndBytes76And99(void*);int GameState_ReadAttributeBits12To19(void*,int);extern char data_0214e33c[];extern char data_020f2308[];}struct Direction{unsigned low:24;signed int value:3;unsigned high:5;};
// Original: arm9/main @ 0x0203109C; symbol: func_0203109c; size: 0x7C.
extern "C" int Bounds3D_TestAxisAlignedOverlap(int* a,int* b){if(a[0]<b[3])return 0;if(a[1]<b[4])return 0;if(a[2]<b[5])return 0;if(b[0]<a[3])return 0;if(b[1]<a[4])return 0;return b[2]>=a[5];}
