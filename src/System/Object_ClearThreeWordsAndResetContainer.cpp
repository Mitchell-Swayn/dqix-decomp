// ARM callee/header contracts and exact original relocations reviewed; MMIO/shared-memory retained.
#include <globaldefs.h>
#include <System/Memory.h>
#include <System/Matrix.h>
ARM
#pragma force_active on
#pragma optimization_level 4
// Original data: arm9/main @ 0x20f2c14; symbol: data_020f2c14.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1210171b010000000200000000100000000000000000000000000000001000000000000000000000000000000010000000000000000000000000000000100000 ...; full span in module reference.
// Observed span: 72 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20fe9cc; symbol: data_020fe9cc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1536 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2107850; symbol: data_02107850.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2111800; symbol: data_02111800.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Flags{unsigned short a:9,value:3,b:4;};extern "C"{void LinkedList_RemoveNodeByIdentityWithIRQGuard(void*,void*);void Actor_InitializeRepresentationLinksAndMotionDelay(void*);void MIi_CpuClearFast(unsigned,void*,unsigned);void Text_CopyBoundedNullTerminatedString(const char*,char*,unsigned);void CombatStatus_SetAttributeWardKindAndRefreshDuration(char*,unsigned);void Graphics_BuildAndSubmitBillboardMatrix(int,void*,void*);extern char InvokeGlobalTailListHandler_UnknownRoleZeroInitializedStorage[],CombatantMotionAdvanceSidestep_UnknownRoleZeroInitializedStorage[],DebugTextWriteTileString_UnknownRoleZeroInitializedStorage[],WindowControlConfigureGlobalTable_UnknownRoleInitializedBytes[];}
// Original: arm9/main @ 0x02040504; symbol: func_02040504; size: 0x1C.
extern "C" void Object_ClearThreeWordsAndResetContainer(char* p){*(int*)(p+20)=0;*(int*)(p+24)=0;*(int*)(p+28)=0;Actor_InitializeRepresentationLinksAndMotionDelay(p);}
