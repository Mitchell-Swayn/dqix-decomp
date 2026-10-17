#include <globaldefs.h>
extern "C" void *GameState_GetIndexedRecordAtF80(void *, int);
extern "C" void func_ov003_02167a5c(void *, int, int);
// Original: arm9/ov003 @ 0x02161438; symbol: func_ov003_02161438; size: 0x48.
extern "C" void OV003_ApplyIndexedSignedSixBitValue(void *object) {
    unsigned char *base = (unsigned char *)object + 0x400;
    int index = *(short *)(base + 0x8c) - 0x15 + (signed char)base[0x9f] * 4;
    int value = -1;
    void *record = GameState_GetIndexedRecordAtF80(object, index);
    if (record) value = ((signed char)*(unsigned char *)record << 26) >> 26;
    func_ov003_02167a5c(*(void **)((char *)object + 0x318), 6, value);
}
