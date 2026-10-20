#include <globaldefs.h>
ARM
extern "C" void KrakPot_ResetItemPreviewSprites(const char *);
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" void _ZN16BackgroundLoader8AddFenceEv(void);
extern "C" void *_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void *, const char *, const char *, void *);
// Original data: arm9/main @ 0x20f2a38; symbol: data_020f2a38.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex c82a0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char *CharacterViewerRun_UnknownRoleDataReferences_Variant2;
// Original data: arm9/main @ 0x20f2a30; symbol: data_020f2a30.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 612a0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char *CharacterViewerRun_UnknownRoleDataReferences;
// Original: arm9/ov006 @ 0x0215A33C; symbol: QueueTwoGP2FilesBehindLoaderFence; size: 0x48.
// Adds a loader fence, queues the two configured GP2 paths, and stores the task handle at object +0x354.
extern "C" void QueueTwoGP2FilesBehindLoaderFence(void *object) {
 KrakPot_ResetItemPreviewSprites(*(const char **)((char *)object + 0x10));
 void *loader = _ZN16BackgroundLoader11GetInstanceEv();
 _ZN16BackgroundLoader8AddFenceEv();
 *(void **)((char *)object + 0x354) = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader, CharacterViewerRun_UnknownRoleDataReferences_Variant2, CharacterViewerRun_UnknownRoleDataReferences, 0);
}
