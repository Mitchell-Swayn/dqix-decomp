#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x20f1b6c; symbol: data_020f1b6c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 640000004c7f0a0265000000547f0a02660000005c7f0a0267000000887f0a020000000000000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109fe0; symbol: data_02109fe0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();extern "C" const void* Filesystem_ExtractLocalizedGp2FileToScratch(const char*,const char*,unsigned*);extern "C" char Script_LoadArchiveCodeAndExecuteUnderGlobalLoaderLock_PathDataMapLoolaGp2[];extern "C" char Script_LoadArchiveCodeAndExecuteUnderGlobalLoaderLock_MarkupLoolaLGBin[];extern "C" void* ObjectAllocate44ByteArrayForPositiveCount_UnknownRoleZeroInitializedStorage[2];extern "C" Script::OpcodeLookupEntry ScriptLoadArchiveCodeAndExecuteUnderGlobalLoaderLock_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x020A818C; symbol: func_020a818c; size: 0x8C.
extern "C" void Script_LoadArchiveCodeAndExecuteUnderGlobalLoaderLock(void* a,void* b){_ZN16BackgroundLoader13AddLockGlobalEv();unsigned size=0;const void* code=Filesystem_ExtractLocalizedGp2FileToScratch(Script_LoadArchiveCodeAndExecuteUnderGlobalLoaderLock_PathDataMapLoolaGp2,Script_LoadArchiveCodeAndExecuteUnderGlobalLoaderLock_MarkupLoolaLGBin,&size);if(code){ObjectAllocate44ByteArrayForPositiveCount_UnknownRoleZeroInitializedStorage[0]=b;ObjectAllocate44ByteArrayForPositiveCount_UnknownRoleZeroInitializedStorage[1]=a;Script s;s.Initialize();s.SetOpcodeLookup(ScriptLoadArchiveCodeAndExecuteUnderGlobalLoaderLock_UnknownRoleProcedureReferenceRecords);s.Load(code,size);s.Execute();}_ZN16BackgroundLoader16RemoveLockGlobalEv();}
