#include <globaldefs.h>
ARM
#include <std_library_functions.h>
struct GameState;
// Original data: arm9/ov000 @ 0x2183650; symbol: data_ov000_02183650.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffff04000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" signed char GameStateCollectPresentFourSlotPartyIndices_UnknownRoleInitializedBytes[4];
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned GameState_CopyActivePartySlotList(GameState*,void*);
extern "C" char* BattleMenu_FindPartyCommandRecord(void*,int);
// Original: arm9/ov000 @ 0x0217EDD4; symbol: func_ov000_0217edd4; size: 0xA8.
extern "C" void GameState_CollectPresentFourSlotPartyIndices(void* self,signed char* out,signed char* count) {
 signed char ids[4];
 COPY_ARRAY(ids,GameStateCollectPresentFourSlotPartyIndices_UnknownRoleInitializedBytes);
 signed char source[4];
 signed char size=GameState_CopyActivePartySlotList((GameState*)_ZN9GameState11GetInstanceEv(),source);
 memcpy(ids,source,size);
 *count=0;
 for(int i=0;i<size;i++) {
  if(BattleMenu_FindPartyCommandRecord(self,ids[i])) {
   out[*count]=ids[i];
   (*count)++;
  }
 }
}
