#include <globaldefs.h>
extern "C" {
void TextCanvas_AdvanceDisplayState(void *, unsigned int);
// Original: arm9/main @ 0x0207FC6C; symbol: func_0207fc6c; size: 0x4C.
ARM void DisplayLayout_AdvanceActiveCanvases(unsigned char *param_1, unsigned int param_2) {
    unsigned char count;
    unsigned char *entry;
    unsigned int status = *(unsigned int *)(param_1 + 0x2c);
    if (status == 0) return;
    entry = *(unsigned char **)(param_1 + 0x30);
    if (entry == 0) return;
    count = param_1[0x39];
    for (unsigned char i = 0; i < count; ++i) {
        TextCanvas_AdvanceDisplayState(entry, param_2);
        entry += 0xe0;
    }
}
}
