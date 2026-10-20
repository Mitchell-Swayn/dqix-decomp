#include <globaldefs.h>
ARM
struct Kind {unsigned value:4,rest:28;};
struct Payload {unsigned first;unsigned pad:27,flag0:1,flag1:1,rest:3;};
struct Entry {Payload* payload;char* text;Kind kind;};
struct Bit {unsigned char value:1,rest:7;};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_GetObjectWithFlag100(void*,int);
extern "C" char* GameState_GetIndexList(void*);
extern "C" int GameObject_GetLinkedStatOrInvalid(char*,int);
extern "C" Entry* ZoneState2754_FindPrimaryRecordByKey(void*,int);
extern "C" void GameObject_SetLinkedStatAndMarkChanged(void*,int,int);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
extern "C" void Graphics_CopyTypedRecordIntoSlot(void*,Entry*,int);
extern "C" void CharacterState_ClearEquipmentByKind(unsigned char*,int);
extern "C" int Inventory_AddItemQuantityToTypeGroup(void*,unsigned,int,unsigned);
// Original data: arm9/ov005 @ 0x215cc0c; symbol: data_ov005_0215cc0c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0708060004010509.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov005.md.
extern "C" unsigned char GameStateRemoveEntriesMissingObjectFlag_UnknownRoleInitializedBytes[];
// Original: arm9/ov005 @ 0x0215840C; symbol: func_ov005_0215840c; size: 0x154.
extern "C" int GameState_RemoveEntriesMissingObjectFlag(char* self,int index) {
 void* game=_ZN9GameState11GetInstanceEv();
 char* object=GameState_GetObjectWithFlag100(game,index);
 if(!object)return 0;
 int result=0;
 int selected=((Bit*)(*(char**)(object+0x150)+0x49c))->value;
 for(int i=0;i<7;i++) {
 Entry* entry; int slot=GameStateRemoveEntriesMissingObjectFlag_UnknownRoleInitializedBytes[i];
 int key=GameObject_GetLinkedStatOrInvalid(object,slot);
 entry=ZoneState2754_FindPrimaryRecordByKey(*(void**)(self+0xdf4),key);
 if(!entry)continue;
 int flags[2]={entry->payload->flag0,entry->payload->flag1};
 if(flags[selected])continue;
 int fallback=-1;int custom=-1;
 if(slot==0) {fallback=1000;custom=0;}
 GameObject_SetLinkedStatAndMarkChanged(object,slot,-1);
 unsigned char* target=GameObject_GetLinkedIndexedState(object);
 Entry* replacement=ZoneState2754_FindPrimaryRecordByKey(*(void**)(self+0xdf4),fallback);
 if(replacement)Graphics_CopyTypedRecordIntoSlot(target,replacement,custom);
 else CharacterState_ClearEquipmentByKind(target,entry->kind.value);
 Inventory_AddItemQuantityToTypeGroup(GameState_GetIndexList(game)+0x1d4,key,1,entry->kind.value);
 result=1;
 }
 return result;
}
