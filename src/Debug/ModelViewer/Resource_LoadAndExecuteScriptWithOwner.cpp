#include <globaldefs.h>
ARM
struct RecordArray;
extern "C" void CharacterViewer_DestroyMenuCatalog(RecordArray*);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" void _ZN6Script10InitializeEv(void*);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void*,void*);
extern "C" void _ZN6Script4LoadEPKvj(void*,const void*,unsigned);
extern "C" void _ZN6Script7ExecuteEv(void*);
extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char*,void*,unsigned*);
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant6[];
extern "C" char Resource_LoadAndExecuteScriptWithOwner_PathDataBinCharaview4Bin[];
// Original data: arm9/ov015 @ 0x2194560; symbol: data_ov015_02194560.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
extern "C" void* CharacterViewerScriptAppendMenuEntry_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov015 @ 0x2193fa0; symbol: data_ov015_02193fa0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000a0b5180265000000c8b5180266000000bcb6180267000000e4b618020000000000000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
extern "C" char ResourceLoadAndExecuteScriptWithOwner_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/ov015 @ 0x0218BA44; symbol: func_ov015_0218ba44; size: 0xA4.
extern "C" void Resource_LoadAndExecuteScriptWithOwner(RecordArray* owner,const char* path){
 unsigned char script[0x430];unsigned size;
 CharacterViewer_DestroyMenuCatalog(owner);
 _ZN16BackgroundLoader13AddLockGlobalEv();
 void* code;
 if(path)code=_Z18LoadFileIntoMemoryPKcPvPj(path,Main_UnknownRoleZeroInitializedStorage_Variant6,&size);
 else code=_Z18LoadFileIntoMemoryPKcPvPj(Resource_LoadAndExecuteScriptWithOwner_PathDataBinCharaview4Bin,Main_UnknownRoleZeroInitializedStorage_Variant6,&size);
 if(code){
 CharacterViewerScriptAppendMenuEntry_UnknownRoleZeroInitializedStorage=owner;
 _ZN6Script10InitializeEv(script);
 _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(script,ResourceLoadAndExecuteScriptWithOwner_UnknownRoleProcedureReferenceRecords);
 _ZN6Script4LoadEPKvj(script,code,size);
 _ZN6Script7ExecuteEv(script);
 }
 _ZN16BackgroundLoader16RemoveLockGlobalEv();
}
