#include <globaldefs.h>
#include <Resource/Script.h>
// Original data: arm9/main @ 0x20f0fb0; symbol: data_020f0fb0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 640000002cf107026500000058f1070266000000a8f407020000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108ee0; symbol: data_02108ee0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct State {unsigned b,a;};extern "C" State DisplayLayoutScriptAppendTypedPart_UnknownRoleZeroInitializedStorage;extern "C" Script::OpcodeLookupEntry ScriptExecuteCodeAndFinalizeGlobalContext_UnknownRoleProcedureReferenceRecords[];extern "C" void DisplayLayout_ResolvePartReferences(unsigned);
// Original: arm9/main @ 0x0207F524; symbol: func_0207f524; size: 0x70.
extern "C" ARM void Script_ExecuteCodeAndFinalizeGlobalContext(unsigned a,unsigned b,const void* code,unsigned size){if(b && code && size){DisplayLayoutScriptAppendTypedPart_UnknownRoleZeroInitializedStorage.b=b;DisplayLayoutScriptAppendTypedPart_UnknownRoleZeroInitializedStorage.a=a;Script script;script.Initialize();script.SetOpcodeLookup(ScriptExecuteCodeAndFinalizeGlobalContext_UnknownRoleProcedureReferenceRecords);script.Load(code,size);script.Execute();DisplayLayout_ResolvePartReferences(a);}}
