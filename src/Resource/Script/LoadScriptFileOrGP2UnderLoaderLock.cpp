#include <globaldefs.h>
#include "Resource/Script.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
// Original data: arm9/main @ 0x20f1048; symbol: data_020f1048.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000bc99080265000000dc99080266000000fc99080267000000a09a080268000000c09a080269000000649b08026a000000909b08020000000000000000.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108efc; symbol: data_02108efc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char LoadScriptFileOrGP2UnderLoaderLock_PathDataBinPresetdtGp2[],LoadScriptFileOrGP2UnderLoaderLock_MarkupPresetdtLGBin[];extern "C" Script::OpcodeLookupEntry LoadScriptFileOrGP2UnderLoaderLock_UnknownRoleProcedureReferenceRecords[];extern "C" unsigned ScriptAllocateAndCopyNameArray_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x02089DE8; symbol: func_02089de8; size: 0xB8.
extern "C" ARM void LoadScriptFileOrGP2UnderLoaderLock(unsigned object,unsigned allocator,const char* path){unsigned length;Script script;BackgroundLoader::AddLockGlobal();void* buffer=Main_UnknownRoleZeroInitializedStorage_Variant6;void* data;if(path)data=LoadFileIntoMemory(path,buffer,&length);else data=Filesystem_ExtractLocalizedGp2FileToScratch(LoadScriptFileOrGP2UnderLoaderLock_PathDataBinPresetdtGp2,LoadScriptFileOrGP2UnderLoaderLock_MarkupPresetdtLGBin,&length);if(data){ScriptAllocateAndCopyNameArray_UnknownRoleZeroInitializedStorage[0]=object;ScriptAllocateAndCopyNameArray_UnknownRoleZeroInitializedStorage[3]=allocator;ScriptAllocateAndCopyNameArray_UnknownRoleZeroInitializedStorage[2]=0;ScriptAllocateAndCopyNameArray_UnknownRoleZeroInitializedStorage[1]=0;script.Initialize();script.SetOpcodeLookup(LoadScriptFileOrGP2UnderLoaderLock_UnknownRoleProcedureReferenceRecords);script.Load(data,length);script.Execute();}BackgroundLoader::RemoveLockGlobal();}
