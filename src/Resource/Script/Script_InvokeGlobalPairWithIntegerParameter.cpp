// Original widths and exact mangled method symbols reviewed; globals resolved by relocation targets.
#include <GameState/GameState.h>
#include <Resource/Script.h>
extern "C" {extern char* data_02108740[];extern char* data_02108efc[];extern int data_020fdd30[];void AllocateIndexedWordArrayAndResetCount(void*,void*,int);void* memcpy(void*,const void*,unsigned);}int SendCommandToArm7(int,int,bool);struct BitOne{unsigned char value:1;unsigned char rest:7;};
// Original: arm9/main @ 0x02027FE8; symbol: func_02027fe8; size: 0x24.
extern "C" int Script_InvokeGlobalPairWithIntegerParameter(Script::Parameter* p){int v=p->ToInt();AllocateIndexedWordArrayAndResetCount((void*)data_020fdd30[0],(void*)data_020fdd30[1],v);return 1;}
