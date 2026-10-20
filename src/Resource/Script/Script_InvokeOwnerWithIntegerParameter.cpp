#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x20fdc4c; symbol: data_020fdc4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage[];extern "C" void WorldMap_AllocateBackgroundResources(void*,unsigned,void*);
// Original: arm9/main @ 0x0201F500; symbol: func_0201f500; size: 0x28.
extern "C" int Script_InvokeOwnerWithIntegerParameter(Script::Parameter* p){unsigned n=p->ToInt();WorldMap_AllocateBackgroundResources(*(void**)(PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage+16),n,*(void**)(PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage+8));return 1;}
