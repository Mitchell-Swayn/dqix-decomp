#include <globaldefs.h>
ARM
extern "C" void *ResolveIndexedRecordAndReturnSecondWord(void *, int);
extern "C" int AppendFormatText(char *, const char *);

// Original: arm9/ov003 @ 0x02159290; symbol: func_ov003_02159290; size: 0x48.
extern "C" void func_ov003_02159290(void *state, int firstIndex, int secondIndex) {
    void *records = (unsigned char *)state + 0x64;
    const char *text = (const char *)ResolveIndexedRecordAndReturnSecondWord(records, (short)firstIndex);
    AppendFormatText(*(char **)((unsigned char *)state + 0x7c), text);
    text = (const char *)ResolveIndexedRecordAndReturnSecondWord(records, (short)secondIndex);
    AppendFormatText(*(char **)((unsigned char *)state + 0x7c), text);
}
