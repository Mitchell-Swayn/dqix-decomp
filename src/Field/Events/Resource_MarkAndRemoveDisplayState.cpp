#include <globaldefs.h>
ARM
extern "C" void FieldEscape_ReleaseExitEffectResources(void *, int);

// Original: arm9/ov017 @ 0x021AC294; symbol: func_ov017_021ac294; size: 0x14.
extern "C" void Resource_MarkAndRemoveDisplayState(void *object) {
    ((unsigned char *)object)[1] = 1;
    FieldEscape_ReleaseExitEffectResources(object, 1);
}
