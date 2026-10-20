// Exact ARM widths, branches and relocation-backed callee contracts reviewed.
#include <globaldefs.h>
#include <Resource/Script.h>
#include <GameState/GameState.h>
ARM
#pragma force_active on
// Original data: arm9/main @ 0x20fdc4c; symbol: data_020fdc4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2105244; symbol: data_02105244.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109404; symbol: data_02109404.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Twelve{unsigned count:12,rest:20;};extern "C"{void NetworkOwnership_ClearEntry(void*);void func_0204719c(void*);int sprintf(char*,const char*,...);int Network_IsClientSession(void*);int Network_FindWirelessSlotByMemberId(void*,int);void GameState_ClearObjectByIndex(GameState*,int);void ObjectPool_ResetDisplayContainer(void*);extern char PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage[],ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage[];extern char* TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/main @ 0x02054248; symbol: func_02054248; size: 0x38.
extern "C" void GameObject_ConsumePendingTransitionFlag(char* p){unsigned f=*(unsigned*)(p+396);if(!(f&256))return;unsigned a=f&128;if(a)*(unsigned*)(p+396)=f|1;else if(a)*(unsigned*)(p+396)=f&~1;*(unsigned*)(p+396)&=~256;}
