#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021E31B0; symbol: func_ov023_021e31b0; size: 0x34.
extern "C" void Menu_SetPartyPreviewMemberList(unsigned int* p, unsigned char* values, unsigned int count) {
    if (values == 0 || count == 0) return;
    *(unsigned int*)((char*)p + 0x4e8) = count;
    for (int i = 0; i < 4; ++i) *(unsigned int*)((char*)p + 0x4ec + i * 4) = values[i];
}
