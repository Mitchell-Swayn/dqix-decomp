#include <globaldefs.h>
ARM
extern "C" void Resource_CleanupOverlaySlotAndBuffer(void *);
extern "C" void OV017_ProcessPresentPartyMembers(void);
// Original: arm9/ov017 @ 0x021C168C; symbol: func_ov017_021c168c; size: 0x1C.
extern "C" void Unclassified_SetObjectFlagAndRunFinalizer(void *object) {
    Resource_CleanupOverlaySlotAndBuffer(object);
    *(unsigned char *)((unsigned char *)object + 1) = 1;
    OV017_ProcessPresentPartyMembers();
}
