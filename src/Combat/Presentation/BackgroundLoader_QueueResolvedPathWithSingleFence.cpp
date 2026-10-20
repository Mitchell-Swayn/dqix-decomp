#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader8AddFenceEv(void*);
struct FenceState { char padding[0x1c];unsigned flags; };
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" FenceState CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage;
extern "C" int Filesystem_SplitMatchedPathPrefixAndSuffix(const char*,char*,char*);
extern "C" unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
// Original: arm9/ov025 @ 0x021E25A4; symbol: BackgroundLoader_QueueResolvedPathWithSingleFence; size: 0x84.
// Adds a fence once under flag 2000 and queues either resolved GP2 member or original file path.
extern "C" unsigned BackgroundLoader_QueueResolvedPathWithSingleFence(const char* path) {
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(!(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.flags&0x2000)) {_ZN16BackgroundLoader8AddFenceEv(loader);CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.flags|=0x2000;}
 char archive[80],file[80];
 if(Filesystem_SplitMatchedPathPrefixAndSuffix(path,archive,file))return _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,archive,file,0);
 else return _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,path,0);
}
