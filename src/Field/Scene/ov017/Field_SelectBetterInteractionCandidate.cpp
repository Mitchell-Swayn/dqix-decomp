#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
typedef unsigned char undefined1;
extern "C" unsigned char GameObject_GetLadderTraversalActive(int);
extern "C" int FieldInput_IsPostCommandCooldownExpired(const unsigned char*);
struct Lookup { unsigned char bytes[15]; };
extern "C" Lookup FieldSelectBetterInteractionCandidate_UnknownRoleInitializedBytes;
struct Record { unsigned char index, kind; unsigned short value; unsigned char enabled; unsigned char pad[3]; unsigned a,b; short priority, extra; };
struct Pair { unsigned a,b; };
// Original: arm9/ov017 @ 0x0219B33C; symbol: Field_SelectBetterInteractionCandidate; size: 0x100.
// Copies an eligible record when its signed priority does not exceed the current one; kind 18 uses an index remapping table.
extern "C" void Field_SelectBetterInteractionCandidate(unsigned char* self, const Record* record) {
 GameObject* object=GameState::GetInstance()->GetUnknownGameObject();
 if (!FieldInput_IsPostCommandCooldownExpired(self)) return;
 if (object && ((*(unsigned*)((char*)object+0x18c)&1) || GameObject_GetLadderTraversalActive((int)object))) return;
 if (*(short*)(self+0x36c4)<record->priority || *(int*)(self+0x4080)) return;
 self[0x36b4]=record->index;
 self[0x36b5]=record->kind;
 *(unsigned short*)(self+0x36b6)=record->value;
 self[0x36b8]=record->enabled;
 *(unsigned long long*)(self+0x36bc)=*(const unsigned long long*)&record->a;
 *(short*)(self+0x36c4)=record->priority;
 *(short*)(self+0x36c6)=record->extra;
 if(record->kind==18) {
  Lookup table=FieldSelectBetterInteractionCandidate_UnknownRoleInitializedBytes;
  self[0x36b5]=table.bytes[record->index];
 }
}
