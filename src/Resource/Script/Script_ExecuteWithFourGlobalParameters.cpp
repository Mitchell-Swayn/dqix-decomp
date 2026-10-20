#include <globaldefs.h>
#include <std_library_functions.h>
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
extern "C" {
// Original data: arm9/main @ 0x20f0a3c; symbol: data_020f0a3c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 6400000034ed06026500000044ed06026600000050ee06026700000058ee06020000000000000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108d04; symbol: data_02108d04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int ScriptExecuteWithFourGlobalParameters_UnknownRoleZeroInitializedStorage[];extern Script::OpcodeLookupEntry ScriptExecuteWithFourGlobalParameters_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x0206EE80; symbol: func_0206ee80; size: 0x6C.
void Script_ExecuteWithFourGlobalParameters(unsigned int a,unsigned int b,void *code,unsigned int len,unsigned int c,short d){ScriptExecuteWithFourGlobalParameters_UnknownRoleZeroInitializedStorage[3]=a;ScriptExecuteWithFourGlobalParameters_UnknownRoleZeroInitializedStorage[2]=c;*(short *)ScriptExecuteWithFourGlobalParameters_UnknownRoleZeroInitializedStorage=d;ScriptExecuteWithFourGlobalParameters_UnknownRoleZeroInitializedStorage[1]=b;Script script;script.Initialize();script.SetOpcodeLookup(ScriptExecuteWithFourGlobalParameters_UnknownRoleProcedureReferenceRecords);script.Load(code,len);script.Execute();}
}
