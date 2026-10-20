#include <globaldefs.h>
#include <Resource/Script.h>
// Original data: arm9/main @ 0x20fdc4c; symbol: data_020fdc4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" { extern unsigned char PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage[]; void WorldMap_ClearChestMarkers(void*); void WorldMap_AllocateChestZoneNames(void*,unsigned char); void WorldMap_SetChestZoneName(void*,unsigned char,unsigned short,const char*);
// Original: arm9/main @ 0x0201F8D0; symbol: func_0201f8d0; size: 0x80.
 ARM int Script_LoadPairedIntegerTextEntries(Script::Parameter* params,int count) { int n=count/2; WorldMap_ClearChestMarkers(*(void**)(PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage+16));WorldMap_AllocateChestZoneNames(*(void**)(PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage+16),n); for(int i=0;i<n;i++){ int key=params->ToInt(); Script::Parameter* text=params+1;params+=2; const char* value=text->ToString();WorldMap_SetChestZoneName(*(void**)(PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage+16),i,key,value); }return 1; } }
