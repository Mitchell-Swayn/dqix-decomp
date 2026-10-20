#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
// Original data: arm9/ov001 @ 0x21658d8; symbol: data_ov001_021658d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" {unsigned Script_ReadParameterString(void*);int sprintf(char*,const char*,...);void* _ZN16BackgroundLoader11GetInstanceEv();void _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(void*,const char*,void**,unsigned*);void _ZN16BackgroundLoader13AddLockGlobalEv();void _ZN16BackgroundLoader16RemoveLockGlobalEv();unsigned Event_LoadFileIntoSharedScratch(const char*,void**);void Script_BuildOwnedTextTable(void*,unsigned,void*,unsigned);extern char Script_LoadEventTextTable_PathDataS[],EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[],ScriptDisplayEventText_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/ov001 @ 0x0215E1CC; symbol: LoadScriptNamedResourceWithScratchFallback; size: 0xb0.
// Loads formatted script resource from cache or locked scratch and clears completion byte.
extern "C" int Script_LoadEventTextTable(void* parameter){char path[40];void* file;unsigned length;sprintf(path,Script_LoadEventTextTable_PathDataS,Script_ReadParameterString(parameter));int locked=0;_ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(_ZN16BackgroundLoader11GetInstanceEv(),path,&file,&length);if(!file){_ZN16BackgroundLoader13AddLockGlobalEv();locked=1;if(!Event_LoadFileIntoSharedScratch(path,&file)){_ZN16BackgroundLoader16RemoveLockGlobalEv();return 0;}}Script_BuildOwnedTextTable(ScriptDisplayEventText_UnknownRoleZeroInitializedStorage,*(unsigned*)EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage,file,length);if(locked)_ZN16BackgroundLoader16RemoveLockGlobalEv();EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[0x8c]=0;return 1;}
