#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" { char* BattleScene_GetActiveInstance(); void Combat_UpdateSelectedObjectVisibility(char*,int,int); void Combat_RestoreActionActorPlacementOnce(void*); extern unsigned char* CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[]; }
// Original: arm9/ov025 @ 0x021E4450; symbol: func_ov025_021e4450; size: 0xAC.
extern "C" int Combat_SetMappedSelectionVisibility(unsigned char* command) {
 char* control=BattleScene_GetActiveInstance();
 int selection=command[8];
 if(selection==5) { Combat_UpdateSelectedObjectVisibility(control,4,command[9]==0); selection=0; }
 else if(selection==6) { Combat_UpdateSelectedObjectVisibility(control,4,command[9]==0); selection=1; }
 if(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[3]) {
  Combat_RestoreActionActorPlacementOnce(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[3]);
  *(unsigned*)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[3]+0x1c4)&=~0x40;
 }
 Combat_UpdateSelectedObjectVisibility(control,selection,command[9]);
 return 1;
}
