#include <globaldefs.h>
ARM
#include <System/LoadToVRAM.h>
extern "C" char Graphics_InitializeBG2ResourceLoadersAndPriorities_PathCharJbBgStep3NcgL[];
extern "C" char Graphics_InitializeBG2ResourceLoadersAndPriorities_PathCharYbBgStep3NclL[];
extern "C" char Graphics_InitializeBG2ResourceLoadersAndPriorities_PathCharXb4MultiNscL[];
extern "C" void WfcUtility_LoadLocalizedResourceAndApply(void*,void (*)(const void*,unsigned,unsigned));
// Original: arm9/ov031 @ 0x02233A8C; symbol: func_ov031_02233a8c; size: 0xA8.
extern "C" void Graphics_InitializeBG2ResourceLoadersAndPriorities(void) {
    WfcUtility_LoadLocalizedResourceAndApply(Graphics_InitializeBG2ResourceLoadersAndPriorities_PathCharJbBgStep3NcgL,LoadToMainBG2CharacterData);
    WfcUtility_LoadLocalizedResourceAndApply(Graphics_InitializeBG2ResourceLoadersAndPriorities_PathCharYbBgStep3NclL,LoadToMainBGStandardPalette);
    WfcUtility_LoadLocalizedResourceAndApply(Graphics_InitializeBG2ResourceLoadersAndPriorities_PathCharXb4MultiNscL,LoadToMainBG2ScreenData);
    volatile unsigned short *sub = (volatile unsigned short *)0x04001008;
    volatile unsigned short *first = (volatile unsigned short *)0x04000008;
    volatile unsigned short *main = (volatile unsigned short *)0x0400000a;
    sub[0] = (sub[0] & ~3) | 3;
    sub[1] = (sub[1] & ~3) | 3;
    *first = (*first & ~3) | 3;
    main[0] = (main[0] & ~3) | 3;
    main[1] = (main[1] & ~3) | 3;
}
