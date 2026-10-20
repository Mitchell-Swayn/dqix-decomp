#include <globaldefs.h>
#include <Resource/Script.h>
ARM
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
extern "C" unsigned ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage[2];extern "C" Script::OpcodeLookupEntry ScriptExecuteWithTemporaryPairGlobals_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x02028048; symbol: func_02028048; size: 0x68.
extern "C" void Script_ExecuteWithTemporaryPairGlobals(unsigned a,unsigned b,const void* code,unsigned size){ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage[0]=a;ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage[1]=b;Script s;s.Initialize();s.SetOpcodeLookup(ScriptExecuteWithTemporaryPairGlobals_UnknownRoleProcedureReferenceRecords);s.Load(code,size);s.Execute();ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage[1]=0;ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage[0]=0;}
