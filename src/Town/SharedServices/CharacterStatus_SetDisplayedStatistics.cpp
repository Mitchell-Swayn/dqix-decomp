#include <globaldefs.h>
ARM
extern "C" void TextCanvas_SetEntryNumericValue(char *p, int i, int v);
// Original: arm9/ov003 @ 0x02168088; symbol: func_ov003_02168088; size: 0x4C.
extern "C" void CharacterStatus_SetDisplayedStatistics(void *self, const int *values) {
    if (values == 0) return;
    char *object = *(char **)((char *)self + 0x10);
    int index = 0x13;
    unsigned char count = 0;
    while (count < 12) {
        TextCanvas_SetEntryNumericValue(object, index, values[count]);
        index = (short)(index + 1);
        count = (unsigned char)(count + 1);
    }
}
