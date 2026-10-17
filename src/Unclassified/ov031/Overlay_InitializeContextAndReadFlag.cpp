#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_0224e5b4[];
extern "C" void func_ov031_02211f24(int value);
// Original: arm9/ov031 @ 0x02211DB0; symbol: func_ov031_02211db0; size: 0x58.
extern "C" int Overlay_InitializeContextAndReadFlag(void) {
    unsigned char *context = *(unsigned char **)(data_ov031_0224e5b4 + 4);
    if (!context) return 0;
    if (*(unsigned *)context) {
        *(unsigned short *)(context + 4) = 3;
        func_ov031_02211f24(3);
        context = *(unsigned char **)(data_ov031_0224e5b4 + 4);
        return context[0x0c] != 0;
    }
    return 0;
}
