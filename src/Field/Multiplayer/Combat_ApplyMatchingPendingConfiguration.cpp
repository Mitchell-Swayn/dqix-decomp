#include <globaldefs.h>
ARM
extern "C" void* FieldBattle_GetEncounterRequest(void*);
extern "C" void* FieldBattle_GetScene(void*);
extern "C" void CombatScene_SetPendingPackedConfiguration(unsigned char*,unsigned int,unsigned short,unsigned int,unsigned short,unsigned short);
struct Message { unsigned short prefix[2]; unsigned short id:16; unsigned short x,y; unsigned short low:4; unsigned short high:12; unsigned short other:4; unsigned short rest:12; };
// Original: arm9/ov017 @ 0x021CD2DC; symbol: Object_ApplyPackedFieldsWhenIdentifierMatches; size: 0x80.
extern "C" void Combat_ApplyMatchingPendingConfiguration(void*,Message* msg,void*,char* state) {
 void* object=*(void**)(state+0x3718);
 char* embedded=(char*)FieldBattle_GetEncounterRequest(object);
 unsigned short id=msg->id;
 if(*(unsigned short*)(embedded+8)==id) {
  unsigned char* target=(unsigned char*)FieldBattle_GetScene(object);
  if(target) CombatScene_SetPendingPackedConfiguration(target,msg->x,msg->y,msg->low,msg->other,msg->high);
 }
}
