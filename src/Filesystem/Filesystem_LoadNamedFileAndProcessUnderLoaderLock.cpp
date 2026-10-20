#include <globaldefs.h>
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char*,void*,unsigned*);extern "C" char Filesystem_LoadNamedFileAndProcessUnderLoaderLock_PathDataEventEventbattleBin[];extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant6[];extern "C" void Script_ExecuteCodeWithTwoGlobalValuesAndReturnSuccess(void*,void*,void*,unsigned);
// Original: arm9/main @ 0x02074114; symbol: func_02074114; size: 0x58.
extern "C" ARM int Filesystem_LoadNamedFileAndProcessUnderLoaderLock(void* a,void* b){unsigned size;_ZN16BackgroundLoader13AddLockGlobalEv();void* ptr=_Z18LoadFileIntoMemoryPKcPvPj(Filesystem_LoadNamedFileAndProcessUnderLoaderLock_PathDataEventEventbattleBin,Main_UnknownRoleZeroInitializedStorage_Variant6,&size);if(ptr){Script_ExecuteCodeWithTwoGlobalValuesAndReturnSuccess(a,b,ptr,size);_ZN16BackgroundLoader16RemoveLockGlobalEv();return 1;}_ZN16BackgroundLoader16RemoveLockGlobalEv();return 0;}
