#include <globaldefs.h>
ARM
// Original: arm9/ov006 @ 0x02158D8C; symbol: func_ov006_02158d8c; size: 0x54.
extern "C" void *func_ov006_02158d8c(void *obj, int index) {
    void *current = *(void **)((char *)obj + 0x30);
    int remaining = index;
    short traversed = 0;
    while (current != 0 && remaining != 0) {
        void *next = *(void **)((char *)current + 0x1c);
        if (next == 0) {
            *(unsigned short *)((char *)obj + 0x36a) = (unsigned short)(traversed + 0x29);
            break;
        }
        remaining = (short)(remaining - 1);
        traversed = (short)(traversed + 1);
        current = next;
    }
    return current;
}
