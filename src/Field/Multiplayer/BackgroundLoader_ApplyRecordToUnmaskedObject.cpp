#include <globaldefs.h>
ARM
extern "C" char* GameState_GetObjectWithFlag100(void*,int);
extern "C" bool GameObject_HasQueuedActions(void*);
extern "C" void BackgroundLoader_RemoveObjectTaskAndResetLoadFields(void*);
extern "C" void* FieldBattle_GetEncounterRequest(void*);
extern "C" unsigned PartySelection_GetMemberMask(void*,unsigned);
extern "C" void GameObject_StartActionResourceSequence(void*,void*,int);
// Original: arm9/ov017 @ 0x021CC26C; symbol: BackgroundLoader_ApplyRecordToUnmaskedObject; size: 0x84.
// Cancels a loaded object for nonzero record byte A, otherwise applies record unless masked.
extern "C" void BackgroundLoader_ApplyRecordToUnmaskedObject(void* unused,unsigned char* record,void* game,char* resources) {
 int index=record[4];int value=record[5];char* object=GameState_GetObjectWithFlag100(game,index);if(!object)return;
 if(record[10]) {if(GameObject_HasQueuedActions(object))BackgroundLoader_RemoveObjectTaskAndResetLoadFields(object);return;}
 void* entry=FieldBattle_GetEncounterRequest(*(void**)(resources+0x3718));
 if(entry && PartySelection_GetMemberMask(entry,index&255))return;
 GameObject_StartActionResourceSequence(object,record+6,value);
}
