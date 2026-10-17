// Original widths and exact mangled method symbols reviewed; globals resolved by relocation targets.
#include <GameState/GameState.h>
#include <Resource/Script.h>
extern "C" {extern char* data_02108740[];extern char* data_02108efc[];extern int data_020fdd30[];void AllocateIndexedWordArrayAndResetCount(void*,void*,int);void* memcpy(void*,const void*,unsigned);}int SendCommandToArm7(int,int,bool);struct BitOne{unsigned char value:1;unsigned char rest:7;};
// Original: arm9/main @ 0x020CF8BC; symbol: func_020cf8bc; size: 0x28.
extern "C" int SendPackedArm7CommandFive(unsigned v){return SendCommandToArm7(5,(v<<8)&0x7f00,false)>=0;}
