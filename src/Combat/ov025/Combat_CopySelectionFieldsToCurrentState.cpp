#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov025_021ef988;
// Original: arm9/ov025 @ 0x021E82A0; symbol: func_ov025_021e82a0; size: 0x44.
extern "C" bool Combat_CopySelectionFieldsToCurrentState(void *selection) {
    unsigned char *state = (unsigned char *)*(void **)((unsigned char *)&data_ov025_021ef988 + 0x0C) + 0x540;
    *(unsigned short *)(state + 0x28) |= 2;
    state[0x35] = ((unsigned char *)selection)[0x0E];
    *(short *)(state + 0x2E) = *(short *)((unsigned char *)selection + 8);
    *(short *)(state + 0x30) = *(short *)((unsigned char *)selection + 0x0A);
    *(short *)(state + 0x32) = *(short *)((unsigned char *)selection + 0x0C);
    return true;
}
