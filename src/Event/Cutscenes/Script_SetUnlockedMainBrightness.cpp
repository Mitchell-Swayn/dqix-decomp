#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x0215B710; symbol: Script_SetUnlockedMainBrightness; size: 0x1C.
// Calls Script_SetBrightnessByMode with mode 17 (unlock and set main brightness) and returns success.
extern "C" int Script_SetBrightnessByMode(int, char *, int);
extern "C" int Script_SetUnlockedMainBrightness(char *parameters, int count) {
    Script_SetBrightnessByMode(17, parameters, count);
    return 1;
}
