#include <globaldefs.h>

// Original: arm9/ov000 @ 0x02169a58; symbol: func_ov000_02169a58; size: 0x4c.
extern "C" void* FindValueInLinkedHalfwordLists(void* list, int value) {
    volatile unsigned char* node = (volatile unsigned char*)list;
    while (node != 0) {
        for (int i = 0; i < *(volatile unsigned short*)(node + 4); i++) {
            unsigned short* values = *(unsigned short* volatile*)node;
            if (values[i] == value) return (void*)node;
        }
        node = *(volatile unsigned char* volatile*)(node + 0xc);
    }
    return 0;
}
