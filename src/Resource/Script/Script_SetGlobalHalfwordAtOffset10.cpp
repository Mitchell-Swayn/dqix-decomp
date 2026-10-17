// Original widths and exact mangled method symbols reviewed; globals resolved by relocation targets.
#include <GameState/GameState.h>
#include <Resource/Script.h>
extern "C" {extern char* data_02108740[];extern char* data_02108efc[];extern int data_020fdd30[];void AllocateIndexedWordArrayAndResetCount(void*,void*,int);void* memcpy(void*,const void*,unsigned);}int SendCommandToArm7(int,int,bool);struct BitOne{unsigned char value:1;unsigned char rest:7;};
// Original: arm9/main @ 0x020899DC; symbol: func_020899dc; size: 0x20.
extern "C" int Script_SetGlobalHalfwordAtOffset10(Script::Parameter* p){int v=p->ToInt();*(short*)(data_02108efc[0]+16)=v;return 1;}
