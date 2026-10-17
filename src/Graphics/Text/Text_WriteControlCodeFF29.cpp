// Original widths and exact mangled method symbols reviewed; globals resolved by relocation targets.
#include <GameState/GameState.h>
#include <Resource/Script.h>
extern "C" {extern char* data_02108740[];extern char* data_02108efc[];extern int data_020fdd30[];void AllocateIndexedWordArrayAndResetCount(void*,void*,int);void* memcpy(void*,const void*,unsigned);}int SendCommandToArm7(int,int,bool);struct BitOne{unsigned char value:1;unsigned char rest:7;};
// Original: arm9/main @ 0x0206999C; symbol: func_0206999c; size: 0x28.
extern "C" int Text_WriteControlCodeFF29(void** p){void* out=*p;unsigned short v=65321;memcpy(out,&v,2);return 2;}
