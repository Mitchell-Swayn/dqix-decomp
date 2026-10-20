#include <globaldefs.h>
ARM
extern "C" void NSBXX_Model_SetPolygonID(void *, unsigned int);

// Original: arm9/ov017 @ 0x021923E0; symbol: func_ov017_021923e0; size: 0x20.
extern "C" void Graphics_SetNestedModelPolygonIDIfAvailable(void *object, unsigned int polygonId) {
    void *nested = *(void **)((unsigned char *)object + 8);
    if (nested != 0) {
        void *model = *(void **)((unsigned char *)nested + 0x54);
        if (model != 0)
            NSBXX_Model_SetPolygonID(model, polygonId);
    }
}
