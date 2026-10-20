#include <globaldefs.h>
#include <std_library_functions.h>
#include <Resource/Script.h>
extern "C" {
// Original data: arm9/main @ 0x20f22d0; symbol: data_020f22d0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000dc390d020000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21142c4; symbol: data_021142c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern void *ScriptAppendNpcAttributeRecord_UnknownRoleZeroInitializedStorage;extern Script::OpcodeLookupEntry NpcAttributesLoadRecordsFromScript_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x020D3C84; symbol: func_020d3c84; size: 0x6C.
void NpcAttributes_LoadRecordsFromScript(char *p,void *code,unsigned int len){Script script;memset(p,0,0xb4);*(int *)(p+0xb4)=0;ScriptAppendNpcAttributeRecord_UnknownRoleZeroInitializedStorage=p;script.Initialize();script.SetOpcodeLookup(NpcAttributesLoadRecordsFromScript_UnknownRoleProcedureReferenceRecords);script.Load(code,len);script.Execute();}
}
