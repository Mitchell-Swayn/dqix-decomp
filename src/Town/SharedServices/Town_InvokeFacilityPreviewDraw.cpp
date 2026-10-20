#include <globaldefs.h>
ARM
extern "C" void Town_DrawFacilityModelPreview(void *);

// Original: arm9/ov003 @ 0x02173EF4; symbol: func_ov003_02173ef4; size: 0x10.
extern "C" void Town_InvokeFacilityPreviewDraw(void *object) {
    Town_DrawFacilityModelPreview((unsigned char *)object + 0x1e0);
}
