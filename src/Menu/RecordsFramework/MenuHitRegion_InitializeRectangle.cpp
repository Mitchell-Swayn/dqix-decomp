#include <globaldefs.h>
ARM
extern "C" void MenuRecord_ResetHeader(char*);
// Original: arm9/ov023 @ 0x021FD320; symbol: func_ov023_021fd320; size: 0x70.
extern "C" int MenuHitRegion_InitializeRectangle(char* record, int unused, unsigned value, unsigned kind, unsigned first, unsigned second, unsigned third, unsigned fourth, unsigned finalByte) {
    MenuRecord_ResetHeader(record);
    *(unsigned short*)(record + 4) = 19;
    *(unsigned short*)(record + 6) = (unsigned short)value;
    *(unsigned short*)(record + 8) = (unsigned short)kind;
    *(unsigned*)(record + 0x1c) = 2;
    *(unsigned short*)(record + 0x20) = (unsigned short)value;
    *(unsigned short*)(record + 0x22) = (unsigned short)first;
    *(unsigned short*)(record + 0x24) = (unsigned short)second;
    *(unsigned short*)(record + 0x26) = (unsigned short)third;
    *(unsigned short*)(record + 0x28) = (unsigned short)fourth;
    *(unsigned short*)(record + 0x2a) = 0;
    record[0x2c] = finalByte;
    return 1;
}
