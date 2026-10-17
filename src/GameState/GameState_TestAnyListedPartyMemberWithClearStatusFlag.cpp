#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" unsigned char* GameState_GetIndexList(GameState*);
struct Status{char pad[0x49c];unsigned char flag:1;unsigned char rest:7;};struct Object{char pad[0x150];Status* status;};
// Original: arm9/main @ 0x020685F0; symbol: func_020685f0; size: 0x60.
extern "C" int GameState_TestAnyListedPartyMemberWithClearStatusFlag(GameState* state){unsigned char* list=GameState_GetIndexList(state);for(int i=0;i<list[0xf7c];i++){Object* obj=(Object*)state->GetPartyMemberByIndex((list+i)[0xf78]);if(obj&&!obj->status->flag)return 1;}return 0;}
