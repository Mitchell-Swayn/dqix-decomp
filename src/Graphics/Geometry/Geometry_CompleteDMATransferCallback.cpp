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
// Original: arm9/main @ 0x020CA364; symbol: func_020ca364; size: 0x2C.
extern "C" void Geometry_CompleteDMATransferCallback(){*(int*)MIiDMACallback_UnknownRoleZeroInitializedStorage=0;Callback f=*(Callback*)(MIiDMACallback_UnknownRoleZeroInitializedStorage+16);void* p=*(void**)(MIiDMACallback_UnknownRoleZeroInitializedStorage+20);if(f)f(p);}
