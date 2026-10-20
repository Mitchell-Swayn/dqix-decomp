#include <globaldefs.h>
ARM
extern "C" void KrakPot_ResetRecipeInventoryContext(char* p);
// Original: arm9/ov006 @ 0x02153730; symbol: func_ov006_02153730; size: 0xC.
extern "C" void KrakPot_ReleaseRecipeInventoryContext(char* p)
{
    KrakPot_ResetRecipeInventoryContext(p);
}
