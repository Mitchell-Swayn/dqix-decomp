#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov004_0217101c[];
extern "C" void func_ov023_021f65b4(void*, void*, unsigned short, unsigned);
// Original: arm9/ov004 @ 0x02165EF4; symbol: func_ov004_02165ef4; size: 0x38.
extern "C" void Filesystem_QueuePositionRecord(void* object) {
    char* state = *(char**)data_ov004_0217101c;
    int value = *(short*)(state + 0x4C);
    int adjusted = value + 7;
    int quarter = adjusted >> 2;
    int rounded = adjusted + ((unsigned)quarter >> 29);
    int result = (rounded << 13) >> 16;
    func_ov023_021f65b4(object, (void*)0x5B, 0, result);
}
