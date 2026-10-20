#include <globaldefs.h>
#include <Resource/Script.h>
// Original data: arm9/main @ 0x20fdc4c; symbol: data_020fdc4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0201F600; symbol: func_0201f600; size: 0x34.
extern "C" ARM int WorldMapScript_SetMapScale(Script::Parameter* p){float value=p->ToFloat();int result=(int)(4096.0f*value);*(int*)(*(char**)(PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage+16)+56)=result;return 1;}
