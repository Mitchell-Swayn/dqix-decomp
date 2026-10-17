#include <globaldefs.h>
ARM
extern "C" void *SelectStateWordByPriorityMask(unsigned mask);
extern "C" int Resource_ReadSharedPointerUnderMutex(void);
extern "C" unsigned func_ov031_022135ac(unsigned value);
extern "C" unsigned GetWordAtGlobalPointerOffset1004(void);
extern "C" void func_ov031_02219080(void);
// Original: arm9/ov031 @ 0x02215478; symbol: func_ov031_02215478; size: 0x6C.
extern "C" int Overlay_AdvancePrioritySelectedState(void *state) {
    unsigned char *bytes = (unsigned char *)state;
    unsigned char *selected = (unsigned char *)SelectStateWordByPriorityMask(1);
    int status = Resource_ReadSharedPointerUnderMutex();
    if (status != 0) {
        unsigned value = func_ov031_022135ac(bytes[0xd0d]);
        if (selected[0x15] == value) *(unsigned *)(selected + 0x10) = GetWordAtGlobalPointerOffset1004();
        func_ov031_02219080();
        if (status == 11) return 15;
        *(bytes + 0x444 + (bytes[0xd13] << 2)) = 1;
        return 11;
    }
    return 14;
}
