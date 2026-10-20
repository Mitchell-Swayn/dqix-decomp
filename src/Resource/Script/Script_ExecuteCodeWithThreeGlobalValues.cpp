#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" {
// Original data: arm9/main @ 0x20f05f8; symbol: data_020f05f8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 01000000384d060202000000404d060203000000484d06020000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108ce0; symbol: data_02108ce0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int ScriptPrependLabelNodeForValidEntry_UnknownRoleZeroInitializedStorage[];extern Script::OpcodeLookupEntry ScriptExecuteCodeWithThreeGlobalValues_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x02064E2C; symbol: func_02064e2c; size: 0x5C.
bool Script_ExecuteCodeWithThreeGlobalValues(unsigned int a,unsigned int b,unsigned int c,void *code,unsigned int len){ScriptPrependLabelNodeForValidEntry_UnknownRoleZeroInitializedStorage[2]=a;ScriptPrependLabelNodeForValidEntry_UnknownRoleZeroInitializedStorage[1]=b;ScriptPrependLabelNodeForValidEntry_UnknownRoleZeroInitializedStorage[0]=c;Script script;script.Initialize();script.SetOpcodeLookup(ScriptExecuteCodeWithThreeGlobalValues_UnknownRoleProcedureReferenceRecords);script.Load(code,len);script.Execute();return true;}
}
