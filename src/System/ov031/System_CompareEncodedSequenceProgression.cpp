#include <globaldefs.h>
THUMB
extern "C" unsigned char data_ov031_0224b0dc[];
extern "C" unsigned func_ov031_0221e650(const char*);
extern "C" void func_ov031_0221e354(const char*, unsigned, const void*, unsigned);
extern "C" int func_ov031_0221e4fc(const char*, const char*, unsigned);
extern "C" unsigned func_ov031_0221e638(unsigned short);
// Original: arm9/ov031 @ 0x0221D7E0; symbol: func_ov031_0221d7e0; size: 0x4C.
extern "C" int System_CompareEncodedSequenceProgression(const char* first, const char* second) {
    int result = 0;
    unsigned value = func_ov031_0221e650((const char*)data_ov031_0224b0dc);
    func_ov031_0221e354(second, 8, data_ov031_0224b0dc, value);
    if (func_ov031_0221e4fc(first, second, 6)) result--;
    else {
        unsigned a = func_ov031_0221e638(*(unsigned short*)(first + 6));
        unsigned b = func_ov031_0221e638(*(unsigned short*)(second + 6));
        if (a + 1 != b) result -= 2;
    }
    return result;
}
