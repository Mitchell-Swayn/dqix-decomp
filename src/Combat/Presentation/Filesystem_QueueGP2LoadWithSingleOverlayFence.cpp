#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
ARM
struct OverlayState {unsigned char unknown[0x1c];unsigned flags;};
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" OverlayState CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov025 @ 0x021E2628; symbol: func_ov025_021e2628; size: 0x54.
// Adds one loader fence while overlay flag 0x2000 is clear, sets that flag, and queues the named GP2 file with no explicit allocator.
extern "C" int Filesystem_QueueGP2LoadWithSingleOverlayFence(const char* archive,const char* name) {
 BackgroundLoader* loader=BackgroundLoader::GetInstance();
 if(!(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.flags&0x2000)) {
 loader->AddFence();
 CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.flags|=0x2000;
 }
 return loader->QueueLoadFileInGP2(archive,name,0);
}
