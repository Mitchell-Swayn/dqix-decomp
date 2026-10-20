#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void Graphics_LoadPartyPalettePreset(int, int);
extern "C" void PartyStatus_RenderMemberPortraitLabels(int, void *);
// Original: arm9/main @ 0x02020AA0; symbol: func_02020aa0; size: 0x4C.
extern "C" void PartyStatus_RefreshAllMemberPortraitLabels(void *object, int, int, int) {
    Graphics_LoadPartyPalettePreset(6, -1);
    Graphics_LoadPartyPalettePreset(7, -1);
    signed char i = 0;
    goto check;
body:
    PartyStatus_RenderMemberPortraitLabels(i, (char *)object + 0xe8);
    i = (signed char)(i + 1);
check:
    if (i < 4) goto body;
}
