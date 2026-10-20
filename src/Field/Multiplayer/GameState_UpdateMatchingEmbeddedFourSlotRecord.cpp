#include <globaldefs.h>
ARM
extern "C" {
void GameState_UpdateFourSlotRecord(char*,int,int,int,void*,signed char,signed char);
void* FieldBattle_GetScene(void*);
void* FieldBattle_GetCombatContext(void*);
void* FieldBattle_GetEncounterRequest(void*);
}
// Original: arm9/ov017 @ 0x021C6B04; symbol: func_ov017_021c6b04; size: 0x88.
extern "C" void GameState_UpdateMatchingEmbeddedFourSlotRecord(void* unused,unsigned char* record,int unused2,unsigned char* context) {
 void* owner=*(void**)(context+0x3718);
 unsigned char* embedded=(unsigned char*)FieldBattle_GetEncounterRequest(owner);
 if(embedded) {
  char* target=(char*)FieldBattle_GetScene(owner);
  if(target && FieldBattle_GetCombatContext(owner) && *(unsigned short*)(embedded+8)==*(unsigned short*)(record+4))
   GameState_UpdateFourSlotRecord(target,*(short*)(record+4),*(unsigned short*)(record+6),record[8],(void*)(unsigned)record[9],*(signed char*)(record+10),*(signed char*)(record+11));
 }
}
