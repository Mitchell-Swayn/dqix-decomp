#include <globaldefs.h>
ARM
extern "C" void Alltrades_AdvanceVocationStatPreview(void);
// Original: arm9/ov003 @ 0x02154450; symbol: func_ov003_02154450; size: 0xC.
extern "C" void Alltrades_UpdateVocationStatPreviewCallback(void)
{
    Alltrades_AdvanceVocationStatPreview();
}
