#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void Graphics_ResetTilePayloadWithUnitScale(void*);
// Original: arm9/main @ 0x02075D58; symbol: func_02075d58; size: 0xC.
extern "C" void Graphics_ResetOwnedTilePayload(void* object){Graphics_ResetTilePayloadWithUnitScale(object);}
