#include <globaldefs.h>
ARM
extern "C" void ZoneFeatures_IgnoreOptionalObjectHook(void *object);
// Original: arm9/ov017 @ 0x02199480; symbol: func_ov017_02199480; size: 0x1C.
extern "C" void Field_InvokeSelectedFeatureNoOpHook(void *object) {
    void *nested = *(void **)((char *)object + 0x36bc);
    if (nested)
        ZoneFeatures_IgnoreOptionalObjectHook(nested);
}
