#include <globaldefs.h>
ARM
extern "C" void *ResourceStringTable_GetTextByKey(void *, int);
extern "C" int Text_AppendFormatString(char *, const char *);

// Original: arm9/ov003 @ 0x02159290; symbol: func_ov003_02159290; size: 0x48.
extern "C" void Church_AppendTwoMessageFragments(void *state, int firstIndex, int secondIndex) {
    void *records = (unsigned char *)state + 0x64;
    const char *text = (const char *)ResourceStringTable_GetTextByKey(records, (short)firstIndex);
    Text_AppendFormatString(*(char **)((unsigned char *)state + 0x7c), text);
    text = (const char *)ResourceStringTable_GetTextByKey(records, (short)secondIndex);
    Text_AppendFormatString(*(char **)((unsigned char *)state + 0x7c), text);
}
