#pragma optimize_for_size on
#include <globaldefs.h>

typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
extern "C" void ReadGlobalValueAt020FB3F0();
extern "C" void __clear(void*, unsigned);
extern "C" void BuildRecordsWithCumulativeHalfProductOffsets(void*, int, const void*, const void*, const void*, const void*);
extern "C" void ClearTwoWordsAndFollowingByte(void*);
extern "C" void WriteFirstWordValue(void*, int);
extern "C" void Object_SetWord4AndByte8(void*, const void*, int);
extern "C" void func_0205b234(void*, int, int, void*, int, int);

// Original: arm9/main @ 0x020230FC; symbol: func_020230fc; size: 0x11C.
extern "C" ARM void Text_GenerateGlyphLayoutAndRenderAdjustedLabel(void* self, int start, int length) {
    u16 offsets[0x12];
    char descriptor[0x24];
    u16 secondary[0x12];
    u16 primary[0x12];
    char renderState[12];
    char glyphData[0xd8];

    ReadGlobalValueAt020FB3F0();
    __clear(descriptor, 0x24);
    for (int i = 0; i < 0x12; ++i) {
        offsets[i] = (u16)(i << 3);
        secondary[i] = 8;
        primary[i] = 0x10;
    }
    *((unsigned char*)self + 0x5a8) = 0;
    if (*((signed char*)self + 0xba2) != 0) {
        *((unsigned char*)self + 0x5a8) = 1;
        BuildRecordsWithCumulativeHalfProductOffsets(glyphData, 0x12, offsets, descriptor, secondary, primary);
        int value = *(int*)((char*)self + 0xbe4);
        int aligned=(value+7)&~7;
        s16 adjustment = (s16)(value > 0x90
            ? -*(int*)((char*)self + 0xbe8)
            : ((aligned - value) >> 1));
        ClearTwoWordsAndFollowingByte(renderState);
        WriteFirstWordValue(renderState, start + length);
        Object_SetWord4AndByte8(renderState, glyphData, 0x12);
        func_0205b234(renderState, adjustment, 3,
                      (char*)self + 0xba2, 0xf, 0);
    }
}
