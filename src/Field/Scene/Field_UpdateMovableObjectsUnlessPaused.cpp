#include <globaldefs.h>
ARM
extern "C" int GameResources_GetMaskedPrimaryFlags(void*,unsigned);
extern "C" int LinkedQueue_GetFrontKindOrInvalid(char**);
extern "C" void Field_UpdatePartyFormationMovement(void*);
extern "C" void FieldMonster_UpdateVisibleGroupsAndCullDistantMonsters(void*);
extern "C" void GameState_AdvanceUnflaggedObjectsA0ThroughBF(void*);
// Original: arm9/ov017 @ 0x0218D06C; symbol: AdvanceUnmaskedStateByIndirectType38; size: 0x80.
// Advances unmasked state, selecting updates around indirect type 38.
extern "C" void Field_UpdateMovableObjectsUnlessPaused(char* p) {
 if(GameResources_GetMaskedPrimaryFlags(p,0x800)) return;
 int changed=0;
 if(LinkedQueue_GetFrontKindOrInvalid(*(char***)(p+0x36fc))!=38) {Field_UpdatePartyFormationMovement(p); changed=1;}
 if(LinkedQueue_GetFrontKindOrInvalid(*(char***)(p+0x36fc))!=38 || !(*(unsigned char**)(p+0x3b30))[11]) FieldMonster_UpdateVisibleGroupsAndCullDistantMonsters(p);
 if(changed) GameState_AdvanceUnflaggedObjectsA0ThroughBF(p);
}
