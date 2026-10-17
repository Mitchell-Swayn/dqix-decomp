// Original widths and exact mangled method symbols reviewed; globals resolved by relocation targets.
#include <GameState/GameState.h>
#include <Resource/Script.h>
extern "C" {extern char* data_02108740[];extern char* data_02108efc[];extern int data_020fdd30[];void AllocateIndexedWordArrayAndResetCount(void*,void*,int);void* memcpy(void*,const void*,unsigned);}int SendCommandToArm7(int,int,bool);struct BitOne{unsigned char value:1;unsigned char rest:7;};
// Original: arm9/main @ 0x0206980C; symbol: func_0206980c; size: 0x28.
extern "C" int TextStream_WriteMarkerFF0A(void** p){void* out=*p;unsigned short v=65290;memcpy(out,&v,2);return 2;}
