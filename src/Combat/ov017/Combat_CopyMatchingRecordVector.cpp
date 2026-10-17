#include <globaldefs.h>
ARM
extern "C" {
void* OV017_GetEmbeddedField1C(void*);
void* OV017_ReadWordField6AC(void*);
void* OV017_ReadWordField6B0(void*);
void* _ZN9GameState19GetCombatantByIndexEi(void*,int);
void* _ZN8Vector3iaSERKS_(void*,const void*);
}
// Original: arm9/ov017 @ 0x021C88CC; symbol: func_ov017_021c88cc; size: 0x80.
extern "C" void Combat_CopyMatchingRecordVector(void* unused,char* record,void* state,char* context) {
 void* object=*(void**)(context+0x3718);
 char* embedded=(char*)OV017_GetEmbeddedField1C(object);
 if(!embedded) return;
 if(!OV017_ReadWordField6AC(object)) return;
 if(!OV017_ReadWordField6B0(object)) return;
 if(*(unsigned short*)(embedded+8)!=*(unsigned short*)(record+0x12)) return;
 char* combatant=(char*)_ZN9GameState19GetCombatantByIndexEi(state,*(short*)(record+0x10));
 if(!combatant || !*(void**)(combatant+0x13c)) return;
 _ZN8Vector3iaSERKS_(*(char**)(combatant+0x13c)+0x10,record+4);
}
