// Original ARM and access widths reviewed; resource addresses follow exact relocations.
#include <GameState/GameState.h>
#include <Resource/Script.h>
// Original data: arm9/main @ 0x2110370; symbol: data_02110370.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {int GameState_ReadAttributeBits12To19(void*,int);void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);extern char* NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage[];}struct SignedSix{signed char value:6;unsigned char unused:1;unsigned char flag:1;};struct Direction{unsigned low:24;signed int value:3;unsigned high:5;};
// Original data: arm9/main @ 0x20f0ca0; symbol: data_020f0ca0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 640000005c2307026500000064230702660000006c23070267000000982307020000000000000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108da8; symbol: data_02108da8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char ScriptConvertParameterToHalfwordAndDispatch_UnknownRoleZeroInitializedStorage[];extern "C" char ScriptExecuteCodeWithTwoGlobalContextValues_UnknownRoleProcedureReferenceRecords[];
// Original data: arm9/main @ 0x20f2e2c; symbol: data_020f2e2c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 6600000028570e026700000050570e020000000000000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21536c4; symbol: data_021536c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char ScriptExecuteCodeWithTwoOwnersAndReturnZero_UnknownRoleZeroInitializedStorage[];extern "C" char ScriptExecuteCodeWithTwoOwnersAndReturnZero_UnknownRoleProcedureReferenceRecords[];
// Original data: arm9/main @ 0x20ef6f4; symbol: data_020ef6f4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000e47c020265000000b07d020266000000447e020267000000ec7e020268000000907f020269000000b47f02026a000000bc7f02026b000000e07f0202 ...; full span in module reference.
// Observed span: 88 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20fdd30; symbol: data_020fdd30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage[];extern "C" char ScriptExecuteWithTemporaryPairGlobals_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x02095518; symbol: func_02095518; size: 0x60.
extern "C" void Quest_ResetOrderState(char* p){*(int*)(p+160)=0;*(int*)(p+164)=0;*(int*)(p+168)=0;*(int*)(p+0x4c4)=-1;memset(p,0,160);memset(p+172,255,204);memset(p+0x178,0,0x330);memset(p+0x4a8,0,26);}
