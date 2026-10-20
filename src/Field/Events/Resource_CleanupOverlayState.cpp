#include <globaldefs.h>
ARM
extern "C" void FieldDialogue_ReleasePresentation(void *self);
// Original: arm9/ov017 @ 0x021B98F8; symbol: func_ov017_021b98f8; size: 0xC.
extern "C" void Resource_CleanupOverlayState(void *self) { FieldDialogue_ReleasePresentation(self); }
