#include <globaldefs.h>
ARM
struct GameState;
extern "C" void* FieldBattle_GetEncounterRequest(void*);
extern "C" void* FieldBattle_GetScene(void*);
extern "C" void* FieldBattle_GetCombatContext(void*);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" char* _ZN9GameState19GetCombatantByIndexEi(GameState*,int);
// Original: arm9/ov017 @ 0x021C6CA0; symbol: func_ov017_021c6ca0; size: 0xB0.
extern "C" void Combat_ApplyMatchingRemotePacketFields(void* unused,unsigned char* packet,GameState* state,unsigned char* resources) {
 void* owner=*(void**)(resources+0x3718);
 unsigned char* info=(unsigned char*)FieldBattle_GetEncounterRequest(owner);
 if(!info) return;
 if(!FieldBattle_GetScene(owner)) return;
 if(!FieldBattle_GetCombatContext(owner)) return;
 int protagonist=GameState_ReadProtagonistObjectIndex(state);
 if(*(signed char*)(info+0x2a)==protagonist) return;
 if(*(unsigned short*)(info+8)!=*(unsigned short*)(packet+4)) return;
 char* object=_ZN9GameState19GetCombatantByIndexEi(state,*(unsigned short*)(packet+6));
 if(!object) return;
 *(unsigned short*)(*(char**)(object+0x138))=*(unsigned short*)(packet+8);
 *(unsigned short*)(*(char**)(object+0x138)+2)=*(unsigned short*)(packet+10);
 *(unsigned*)(*(char**)(object+0x138)+0x14)=*(unsigned*)(packet+12);
 *(unsigned*)(*(char**)(object+0x138)+0x18)=*(unsigned*)(packet+16);
}
