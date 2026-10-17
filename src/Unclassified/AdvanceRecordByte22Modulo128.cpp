#include <globaldefs.h>

// Original: arm9/main @ 0x0205AED0; symbol: func_0205aed0; size: 0x48.
extern "C" void AdvanceRecordByte22Modulo128(void *unused, unsigned char *records,
                                unsigned int count, signed char delta) {
    unsigned short i;
    (void)unused;
    if (records == 0) return;
    for (i = 0; i < count; ++i) {
        unsigned char *record = records + (unsigned int)i * 0x28;
        unsigned int sum = record[0x22] + delta;
        record[0x22] = (unsigned char)sum & 0xff;
        record[0x22] &= 0x7f;
    }
}
