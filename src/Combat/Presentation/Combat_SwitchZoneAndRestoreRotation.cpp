#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
// Original data: arm9/ov025 @ 0x21ef9a8; symbol: data_ov025_021ef9a8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" {char* BattleScene_GetActiveInstance();char* GameResources_GetInstance();char* FieldBattle_GetEncounterRequest(void*);void* _ZN9GameState11GetInstanceEv();void* GameState_GetFieldAddress468(void*);char* ZoneTable_FindEntryByMapName(void*,char*);void _ZN6Zone3D10SwitchZoneEt(void*,unsigned short,int);void _ZN6Zone3D15SetZoneRotationEi(void*,int);void Combat_ResetActionProcedureState(void*);extern unsigned CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];extern char CombatInitializeActionPresentation_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/ov025 @ 0x021E58F0; symbol: SwitchCombatZoneAndRestoreRotation; size: 0xc4.
// Switches combat zone by descriptor or name and restores stored rotation after loading.
extern "C" int Combat_SwitchZoneAndRestoreRotation(char* self){char* control=BattleScene_GetActiveInstance();char* zone=control+0xec8;char* descriptor=FieldBattle_GetEncounterRequest(*(void**)(GameResources_GetInstance()+0x3718));unsigned state=CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[8];if(!state){unsigned short id=*(unsigned short*)(descriptor+2);if(*(char**)(self+8)){void* state=_ZN9GameState11GetInstanceEv();void* names=GameState_GetFieldAddress468(state);char* found=ZoneTable_FindEntryByMapName(names,*(char**)(self+8));if(!found)return 1;id=*(unsigned short*)found;}_ZN6Zone3D10SwitchZoneEt(zone,id,0);CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[8]=1;}else if(state==1&&!*(int*)(zone+0x424)){_ZN6Zone3D15SetZoneRotationEi(zone,*(short*)(control+0x36ec));Combat_ResetActionProcedureState(CombatInitializeActionPresentation_UnknownRoleZeroInitializedStorage);return 1;}return 0;}
