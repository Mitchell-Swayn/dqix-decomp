#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <Resource/Script.h>
extern "C" {
// Original data: arm9/main @ 0x20f1640; symbol: data_020f1640.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 640000006ca709026500000074a70902660000007ca7090267000000bca709020000000000000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109ba8; symbol: data_02109ba8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern void **ScriptAllocateZeroedStateAndExecute_UnknownRoleZeroInitializedStorage;extern Script::OpcodeLookupEntry ScriptAllocateZeroedStateAndExecute_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x0209A8B4; symbol: func_0209a8b4; size: 0x88.
void Script_AllocateZeroedStateAndExecute(void **p,SafeAllocator *a,void *code,unsigned int len){Script s;void *data=a->Allocate(0x550);*p=data;if(data){memset(data,0,0x550);ScriptAllocateZeroedStateAndExecute_UnknownRoleZeroInitializedStorage=p;s.Initialize();s.SetOpcodeLookup(ScriptAllocateZeroedStateAndExecute_UnknownRoleProcedureReferenceRecords);s.Load(code,len);s.Execute();ScriptAllocateZeroedStateAndExecute_UnknownRoleZeroInitializedStorage=0;}}
}
