#include <globaldefs.h>
ARM
extern "C" void Graphics_DrawFourObjectsWithConditionalCameraSetup(char*);

// Original fallback callers can be weak; retain this entry point in its ROM range.
#pragma force_active on
// Original: arm9/ov006 @ 0x02158038; symbol: func_ov006_02158038; size: 0x1C.
// Draws the menu scene only while its active flag is set.
extern "C" void KrakPot_RenderActiveMenuScene(unsigned char* self)
{
    if (self[0x38f])
        Graphics_DrawFourObjectsWithConditionalCameraSetup(*(char**)(self + 0x10));
}

#pragma force_active reset
