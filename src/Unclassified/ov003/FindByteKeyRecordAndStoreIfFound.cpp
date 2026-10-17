#include <globaldefs.h>
ARM
extern "C" unsigned char* FindByteKeyInTwentyByteRecords(const unsigned char*, int);

// Original: arm9/ov003 @ 0x0215F4E4; symbol: func_ov003_0215f4e4; size: 0x18.
extern "C" unsigned char *FindByteKeyRecordAndStoreIfFound(const unsigned char *context, int key) {
    unsigned char *result = FindByteKeyInTwentyByteRecords(context, key);
    if (result != 0)
        *(unsigned char **)context = result;
    return result;
}
