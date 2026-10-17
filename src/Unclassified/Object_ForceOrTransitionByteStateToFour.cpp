// Original ARM and access widths reviewed; resource addresses follow exact relocations.
#include <GameState/GameState.h>
#include <Resource/Script.h>
extern "C" {int GameState_ReadAttributeBits12To19(void*,int);void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);extern char* data_02110370[];}struct SignedSix{signed char value:6;unsigned char unused:1;unsigned char flag:1;};struct Direction{unsigned low:24;signed int value:3;unsigned high:5;};
extern "C" char data_02108da8[];extern "C" char data_020f0ca0[];
extern "C" char data_021536c4[];extern "C" char data_020f2e2c[];
extern "C" char data_020fdd30[];extern "C" char data_020ef6f4[];
// Original: arm9/main @ 0x0201FBE0; symbol: func_0201fbe0; size: 0x60.
extern "C" void Object_ForceOrTransitionByteStateToFour(unsigned char* p,int force){if(p[2]&&!force)return;if(*(unsigned short*)(p+4)&&!force)return;if(p[0]==2||p[0]==3||force||p[1]==3)p[1]=4;*(short*)(p+4)=0;}
