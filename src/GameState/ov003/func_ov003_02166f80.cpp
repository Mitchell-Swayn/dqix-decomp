#include <globaldefs.h>
ARM
extern "C" unsigned char *FindTwoHundredTwentyFourByteRecordByByteKey(unsigned char *, unsigned int);
extern "C" int Object_CreateAndConfigureSelectedDisplayPart(char *, int);
// Original: arm9/ov003 @ 0x02166F80; symbol: func_ov003_02166f80; size: 0x44.
extern "C" int func_ov003_02166f80(char *object, unsigned int key, int enabled) {
    unsigned char *record = FindTwoHundredTwentyFourByteRecordByByteKey(*(unsigned char **)(object + 0x324), key);
    if (record != 0) {
        if (enabled) record[0xc5] |= 0x40;
        else record[0xc5] = record[0xc5] & 0xffffffbf;
        return Object_CreateAndConfigureSelectedDisplayPart(*(char **)(object + 0x324), key);
    }
    return (int)record;
}
