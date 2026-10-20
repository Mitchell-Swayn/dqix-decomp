#include <globaldefs.h>
#include "Resource/Script.h"
// Original data: arm9/main @ 0x20fdc4c; symbol: data_020fdc4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage[];extern "C" void WorldMap_AppendBackgroundPlacement(void*,int,int,int,int);
// Original: arm9/main @ 0x0201F5A8; symbol: func_0201f5a8; size: 0x58.
extern "C" ARM int Script_InvokeOwnerWithFourIntegerParameters(Script::Parameter* p){int a=p[0].ToInt();int b=p[1].ToInt();int c=p[2].ToInt();int d=p[3].ToInt();WorldMap_AppendBackgroundPlacement(*(void**)(PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage+0x10),a,b,c,d);return 1;}
