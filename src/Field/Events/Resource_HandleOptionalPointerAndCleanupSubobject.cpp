#include <globaldefs.h>
ARM
extern "C" void RefreshPackedTextUnlessModeSuppressesIt(void *);
extern "C" void QuestMessagePanel_FinalizePresentation(void *);
// Original: arm9/ov017 @ 0x021B9928; symbol: Resource_HandleOptionalPointerAndCleanupSubobject; size: 0x24.
// Calls a handler for a nonnull pointer at +0x118 and always cleans up the subobject at +0x30.
extern "C" void Resource_HandleOptionalPointerAndCleanupSubobject(unsigned char *p) {
    void *value = *(void **)(p + 0x118);
    if (value != 0) RefreshPackedTextUnlessModeSuppressesIt(value);
    QuestMessagePanel_FinalizePresentation(p + 0x30);
}
