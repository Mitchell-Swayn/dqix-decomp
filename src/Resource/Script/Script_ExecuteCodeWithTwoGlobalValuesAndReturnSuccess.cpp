#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x20f0d2c; symbol: data_020f0d2c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffff.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f0d30; symbol: data_020f0d30.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000604007020000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108dd8; symbol: data_02108dd8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned ScriptSetMatchingIdAndEightGlobalHalfwords_UnknownRoleZeroInitializedStorage;extern "C" unsigned ScriptSetMatchingIdAndEightGlobalHalfwords_UnknownRoleInitializedBytes;extern "C" Script::OpcodeLookupEntry ScriptExecuteCodeWithTwoGlobalValuesAndReturnSuccess_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x0207416C; symbol: func_0207416c; size: 0x64.
extern "C" int Script_ExecuteCodeWithTwoGlobalValuesAndReturnSuccess(unsigned a,unsigned b,const void* code,unsigned size){ScriptSetMatchingIdAndEightGlobalHalfwords_UnknownRoleZeroInitializedStorage=a;ScriptSetMatchingIdAndEightGlobalHalfwords_UnknownRoleInitializedBytes=b;Script s;s.Initialize();s.SetOpcodeLookup(ScriptExecuteCodeWithTwoGlobalValuesAndReturnSuccess_UnknownRoleProcedureReferenceRecords);s.Load(code,size);s.Execute();return 1;}
