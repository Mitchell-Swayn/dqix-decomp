#include <globaldefs.h>
extern "C" void *FindIndexedGameStateObjectWithFlag400(void *, int, int, int *);
extern "C" int Ov024_TestNestedByteEqualFive();
extern "C" int func_ov024_021edc80(void *);
// Original: arm9/ov024 @ 0x021F26A8; symbol: func_ov024_021f26a8; size: 0x54.
extern "C" int OV024_ValidateAndStoreIndexedResult(void **objectField, unsigned short value, int key, int *flagOut, unsigned short *valueOut) {
    void *object = FindIndexedGameStateObjectWithFlag400(*objectField, value, key, flagOut);
    if (!object) return 0;
    if (Ov024_TestNestedByteEqualFive()) return 0;
    if (func_ov024_021edc80(object)) return 0;
    *valueOut = value;
    *flagOut = 1;
    return 1;
}
