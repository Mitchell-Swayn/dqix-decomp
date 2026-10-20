#include <globaldefs.h>
ARM
extern "C" int IsOverlayTaskAvailable();
extern "C" void System_SetSharedStateUnlessTwoUnderMutex(int);
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
extern "C" void YssdClient_SetWorkerPhase(int);
extern "C" void _Z19SleepCurrentContextj(unsigned);
// Original: arm9/ov031 @ 0x02210720; symbol: System_AdvanceReadyStateOrSleep; size: 0x60.
// When the readiness helper reports true, selects state 2, then reads the indirect state word and maps states 1 and 2 to stored values 2 and 0; other states sleep for 100 ticks.
extern "C" void System_AdvanceReadyStateOrSleep(void) {
    if (IsOverlayTaskAvailable())
        System_SetSharedStateUnlessTwoUnderMutex(2);
    unsigned state = *(unsigned *)((unsigned char *)*(void **)&YssdClientRunWorker_UnknownRoleZeroInitializedStorage + 4);
    switch (state) {
    case 1:
        YssdClient_SetWorkerPhase(2);
        break;
    case 2:
        YssdClient_SetWorkerPhase(0);
        break;
    default:
        _Z19SleepCurrentContextj(100);
        break;
    }
}
