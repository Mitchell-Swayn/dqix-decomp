// Original widths and exact mangled method symbols reviewed; globals resolved by relocation targets.
#include <GameState/GameState.h>
#include <Resource/Script.h>
extern "C" {extern char* data_02108740[];extern char* data_02108efc[];extern int data_020fdd30[];void AllocateIndexedWordArrayAndResetCount(void*,void*,int);void* memcpy(void*,const void*,unsigned);}int SendCommandToArm7(int,int,bool);struct BitOne{unsigned char value:1;unsigned char rest:7;};
// Original: arm9/main @ 0x0204A714; symbol: func_0204a714; size: 0x28.
extern "C" void SubBackground2_SetScrollOffsets(unsigned a,unsigned b){*(volatile unsigned*)0x4001018=(a&511)|((b<<16)&(511<<16));}
