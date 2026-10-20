#include <globaldefs.h>
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
// Original data: arm9/main @ 0x20f0cc8; symbol: data_020f0cc8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 640000001826070265000000202607026600000028260702670000007c2607020000000000000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108db0; symbol: data_02108db0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct State{unsigned char flag,pad;unsigned short count;unsigned value;unsigned* params;unsigned index,owner;};extern "C" State ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage;extern "C" Script::OpcodeLookupEntry ScriptExecuteCodeWithGlobalContextValues_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x020727F8; symbol: func_020727f8; size: 0xB4.
extern "C" ARM void BackgroundLoader_LoadAndExecuteMessageScript(unsigned owner,const char* path,unsigned parameters,unsigned value,unsigned char flag){unsigned size;BackgroundLoader::AddLockGlobal();void* code=LoadFileIntoMemory(path,Main_UnknownRoleZeroInitializedStorage_Variant6,&size);if(code){ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.owner=owner;ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.index=0;ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.params=&parameters;ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.count=1;ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.value=value;ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.flag=flag;Script script;script.Initialize();script.SetOpcodeLookup(ScriptExecuteCodeWithGlobalContextValues_UnknownRoleProcedureReferenceRecords);script.Load(code,size);script.Execute();}BackgroundLoader::RemoveLockGlobal();}
