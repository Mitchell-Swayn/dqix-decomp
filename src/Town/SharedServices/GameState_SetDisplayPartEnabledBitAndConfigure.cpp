#include <globaldefs.h>
ARM
extern "C" unsigned char *TextCanvas_FindDisplayPartByKey(unsigned char *, unsigned int);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char *, int);
// Original: arm9/ov003 @ 0x02166F80; symbol: func_ov003_02166f80; size: 0x44.
extern "C" int GameState_SetDisplayPartEnabledBitAndConfigure(char *object, unsigned int key, int enabled) {
    unsigned char *record = TextCanvas_FindDisplayPartByKey(*(unsigned char **)(object + 0x324), key);
    if (record != 0) {
        if (enabled) record[0xc5] |= 0x40;
        else record[0xc5] = record[0xc5] & 0xffffffbf;
        return TextCanvas_CreateAndConfigureDisplayPart(*(char **)(object + 0x324), key);
    }
    return (int)record;
}
