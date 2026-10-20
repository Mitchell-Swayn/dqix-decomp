#include <globaldefs.h>
ARM
extern "C" void MenuRecord_ResetHeader(char *p);
// Original: arm9/ov023 @ 0x021FBA80; symbol: func_ov023_021fba80; size: 0x2C.
extern "C" int Menu_InitializeFlagQueryRecord(void *record, int unused, unsigned int first, unsigned int second) {
    MenuRecord_ResetHeader((char *)record);
    *(unsigned short *)((char *)record + 4) = 0x0e;
    *(unsigned short *)((char *)record + 6) = (unsigned short)first;
    *(unsigned short *)((char *)record + 8) = (unsigned short)second;
    return 1;
}
