#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original data: arm9/main @ 0x20fdc4c; symbol: data_020fdc4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
int _ZNK6Script9Parameter5ToIntEv(void *);extern unsigned int PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage[];void WorldMap_AllocateBackgroundPlacements(unsigned int,int,unsigned int);
// Original: arm9/main @ 0x0201F580; symbol: func_0201f580; size: 0x28.
bool Script_InvokeStateIntegerCommand(void *p){int v=_ZNK6Script9Parameter5ToIntEv(p);WorldMap_AllocateBackgroundPlacements(PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage[4],v,PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage[2]);return true;}
}
