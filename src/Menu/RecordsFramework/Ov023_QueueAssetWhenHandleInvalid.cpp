#include <globaldefs.h>
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" unsigned int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void *, const char *, const char *, void *);
extern "C" void *Menu_GetDisplayRecordRegistry(void *);
extern "C" void MenuRecordList_SetBackgroundTaskId(void *, unsigned int);
extern "C" int MenuRecordList_GetBackgroundTaskId(void *);
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
// Original: arm9/ov023 @ 0x021FBEF0; symbol: func_ov023_021fbef0; size: 0x5C.
extern "C" void *Ov023_QueueAssetWhenHandleInvalid(char *object, void *state) {
    void *entry = Menu_GetDisplayRecordRegistry(state);
    if (MenuRecordList_GetBackgroundTaskId(entry) >= 0) return *(void **)(object + 0x1c);
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    unsigned int handle = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader, CharacterViewerRun_UnknownRoleDataReferences_Variant2, CharacterViewerRun_UnknownRoleDataReferences, 0);
    MenuRecordList_SetBackgroundTaskId(entry, handle);
    return (void *)1;
}
