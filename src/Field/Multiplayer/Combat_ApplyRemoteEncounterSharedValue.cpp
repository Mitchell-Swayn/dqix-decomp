#include <globaldefs.h>
ARM
extern "C" char* FieldBattle_GetScene(void*);
extern "C" char* FieldBattle_GetCombatContext(void*);
extern "C" char* FieldBattle_GetEncounterRequest(void*);
// Original: arm9/ov017 @ 0x021C840C; symbol: func_ov017_021c840c; size: 0x6C.
// Accepts the shared word and request byte only for the matching remote encounter identifier.
extern "C" int GameState_ReadProtagonistObjectIndex(void*);
extern "C" void Combat_ApplyRemoteEncounterSharedValue(void*,char* packet,void* state,char* resources) {
 void* owner=*(void**)(resources+0x3718);
 char* request=FieldBattle_GetEncounterRequest(owner);
 if(!request) return;
 char* context=FieldBattle_GetCombatContext(owner);
 if(!context) return;
 if(*(signed char*)(request+0x2a)==GameState_ReadProtagonistObjectIndex(state))return;
 if(*(unsigned short*)(request+8)==*(unsigned short*)(packet+4)) {
 *(unsigned*)(context+0x8e20)=*(unsigned*)(packet+8);
 *(unsigned char*)(request+5)=*(unsigned char*)(packet+6);
 }
}
