#include <globaldefs.h>
ARM
extern "C" void ResetPresentStateResources(void *);
// Original: arm9/ov017 @ 0x021B8450; symbol: Resource_ResetPresentStateFromField6AC; size: 0x18.
// Passes the nonnull pointer at object offset 0x6ac to ResetPresentStateResources.
extern "C" void FieldBattle_ResetSceneResources(unsigned char *p) {
    void *value = *(void **)(p + 0x6ac);
    if (value != 0) ResetPresentStateResources(value);
}
