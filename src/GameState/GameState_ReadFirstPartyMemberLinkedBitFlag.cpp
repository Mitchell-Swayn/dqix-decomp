// Original widths and exact mangled method symbols reviewed; globals resolved by relocation targets.
#include <GameState/GameState.h>
#include <Resource/Script.h>
extern "C" {extern char* data_02108740[];extern char* data_02108efc[];extern int data_020fdd30[];void AllocateIndexedWordArrayAndResetCount(void*,void*,int);void* memcpy(void*,const void*,unsigned);}int SendCommandToArm7(int,int,bool);struct BitOne{unsigned char value:1;unsigned char rest:7;};
// Original: arm9/main @ 0x02068558; symbol: func_02068558; size: 0x28.
extern "C" unsigned GameState_ReadFirstPartyMemberLinkedBitFlag(GameState* g){char* p=(char*)g->GetPartyMemberByIndex(0);if(!p)return 0;char* q=*(char**)(p+0x150);return ((BitOne*)(q+0x49c))->value;}
