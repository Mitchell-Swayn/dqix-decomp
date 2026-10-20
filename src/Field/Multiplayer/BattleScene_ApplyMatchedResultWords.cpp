#include <globaldefs.h>
ARM
extern "C" char* FieldBattle_GetScene(void*);
extern "C" char* FieldBattle_GetCombatContext(void*);
extern "C" char* FieldBattle_GetEncounterRequest(void*);
// Original: arm9/ov017 @ 0x021CF694; symbol: func_ov017_021cf694; size: 0x70.
// Copies two result words into the matching battle scene and enables flag 0x20000.
extern "C" void BattleScene_EnableFlags(void*,unsigned);
extern "C" void BattleScene_ApplyMatchedResultWords(void*,char* packet,void*,char* resources) {
 void* owner=*(void**)(resources+0x3718);
 char* request=FieldBattle_GetEncounterRequest(owner);
 if(!request)return;
 char* scene=FieldBattle_GetScene(owner);
 if(!scene)return;
 if(!FieldBattle_GetCombatContext(owner))return;
 if(*(unsigned short*)(packet+12)!=*(unsigned short*)(request+8))return;
 unsigned first=*(unsigned*)(packet+4),second=*(unsigned*)(packet+8);
 *(unsigned*)(scene+0x6e3c)=first;
 *(unsigned*)(scene+0x6e40)=second;
 BattleScene_EnableFlags(scene,0x20000);
}
