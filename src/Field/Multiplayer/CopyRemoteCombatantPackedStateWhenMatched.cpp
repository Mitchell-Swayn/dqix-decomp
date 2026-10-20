#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" char* FieldBattle_GetEncounterRequest(void*);extern "C" void* FieldBattle_GetScene(void*);extern "C" void* FieldBattle_GetCombatContext(void*);extern "C" int GameState_ReadProtagonistObjectIndex(void*);extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
// Original: arm9/ov017 @ 0x021C70E0; symbol: CopyRemoteCombatantPackedStateWhenMatched; size: 0xC4.
// Copies remote packed state and four signed halfwords after owner, protagonist and key guards.
extern "C" void CopyRemoteCombatantPackedStateWhenMatched(int unused,char* input,void* gs,char* owner){void* context=*(void**)(owner+0x3718);char* record=FieldBattle_GetEncounterRequest(context);if(!record)return;if(!FieldBattle_GetScene(context))return;if(!FieldBattle_GetCombatContext(context))return;if(*(signed char*)(record+0x2a)==GameState_ReadProtagonistObjectIndex(gs))return;if(*(unsigned short*)(record+8)!=*(unsigned short*)(input+4))return;char* object=_ZN9GameState19GetCombatantByIndexEi(gs,*(unsigned short*)(input+6));if(!object)return;memcpy(*(char**)(object+0x138)+0x58,input+8,4);*(short*)(*(char**)(object+0x138)+0x28)=*(short*)(input+12);*(short*)(*(char**)(object+0x138)+0x2a)=*(short*)(input+14);*(short*)(*(char**)(object+0x138)+0x2c)=*(short*)(input+16);*(short*)(*(char**)(object+0x138)+0x2e)=*(short*)(input+18);}
