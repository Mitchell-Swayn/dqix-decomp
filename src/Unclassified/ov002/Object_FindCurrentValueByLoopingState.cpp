#include <globaldefs.h>
ARM
extern "C" unsigned ReadCountByteWhenBothOwnerPointersSet(char*);
extern "C" void func_ov002_02156e90(void*);
// Original: arm9/ov002 @ 0x02156FF0; symbol: func_ov002_02156ff0; size: 0x40.
extern "C" unsigned Object_FindCurrentValueByLoopingState(char* self, unsigned value) {
    unsigned count;
    while ((count = ReadCountByteWhenBothOwnerPointersSet(self + 0xec8)) != 0) {
        unsigned current = *(unsigned*)(self + 0x1bb8);
        if (current == value) return current;
        func_ov002_02156e90(self);
    }
    return count;
}
