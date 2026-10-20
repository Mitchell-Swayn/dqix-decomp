#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x20fdc4c; symbol: data_020fdc4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage[];extern "C" void WorldMap_SetZoneNameAndInvalidateTreasureMarkers(void*,const char*);extern "C" void Object_AppendAllocatedNamedRecord(void*,int,const char*,void*);
// Original: arm9/main @ 0x0201F528; symbol: func_0201f528; size: 0x58.
extern "C" int Script_DispatchStringAndIntegerToStoredTarget(Script::Parameter* p){int n=p[0].ToInt();const char* text=p[1].ToString();if(!text)return 0;WorldMap_SetZoneNameAndInvalidateTreasureMarkers(*(void**)(PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage+16),text);Object_AppendAllocatedNamedRecord(*(void**)(PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage+16),n,text,*(void**)(PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage+8));return 1;}
