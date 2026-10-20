// Field widths and exact relocation-backed globals/callee contracts reviewed against original ARM.
#include <globaldefs.h>
#include <Resource/Script.h>
ARM
#pragma force_active on
// Original data: arm9/main @ 0x20fdc4c; symbol: data_020fdc4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109404; symbol: data_02109404.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2111684; symbol: data_02111684.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Triple{unsigned x,y,z;};typedef void(*Callback)(void*);extern "C" {char* strcpy(char*,const char*);char* GameState_GetIndexList(void*);int GameState_GetActivePartySlotCount(void*);unsigned Util_CountSetBits(unsigned);extern char PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage[],MIiDMACallback_UnknownRoleZeroInitializedStorage[],ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/main @ 0x020D6884; symbol: func_020d6884; size: 0x30.
extern "C" unsigned ComputeMaskedIndexPopulationStrideAndBase(char* p,unsigned n,unsigned base,unsigned bits){return *(unsigned short*)(p+2064)*Util_CountSetBits(n&((1<<bits)-1))+base;}
