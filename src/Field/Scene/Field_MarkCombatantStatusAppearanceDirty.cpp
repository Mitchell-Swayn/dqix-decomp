#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*, int);
extern "C" int GameState_TestGroupedMemberLinkedOrCombatantFlag(void*, int);
extern "C" char* GameState_GetIndexedByteField(char*, int);
// Original: arm9/ov017 @ 0x02191fec; GameState_UpdateIndexedCombatantByteFlags; 240 bytes
extern "C" int Field_MarkCombatantStatusAppearanceDirty(void* self, int index) {
 int result = 1;
 void* state = _ZN9GameState11GetInstanceEv();
 void* combatant = _ZN9GameState19GetCombatantByIndexEi(state, index);
 if (combatant && ((*(unsigned int*)(*(unsigned int*)((char*)combatant + 0x138) + 0x14) & 0x01000000) != 0)) {
  if (GameState_GetIndexedByteField((char*)self, index)) {
   unsigned char* flags = (unsigned char*)GameState_GetIndexedByteField((char*)self, index);
   if (flags) *flags |= 1;
   flags = (unsigned char*)GameState_GetIndexedByteField((char*)self, index);
   if (flags) *flags |= 4;
  }
  result = 0;
 }
 if (GameState_TestGroupedMemberLinkedOrCombatantFlag(self, index)) {
  if (GameState_GetIndexedByteField((char*)self, index)) {
   unsigned char* flags = (unsigned char*)GameState_GetIndexedByteField((char*)self, index);
   if (flags) *flags |= 1;
   flags = (unsigned char*)GameState_GetIndexedByteField((char*)self, index);
   if (flags) *flags |= 2;
  }
  result = 0;
 }
 return result;
}
