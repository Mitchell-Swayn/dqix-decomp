#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void MIi_CpuClear32(int, void *, unsigned int);
extern "C" void WirelessCommand_SubmitOpcodeThirtyFiveWithPayload(void *, void *);
// Original: arm9/main @ 0x020D5974; symbol: func_020d5974; size: 0x48.
extern "C" void Build180TypeMessageWithHalfwordPair(void *object, unsigned short x, unsigned short y, unsigned int) {
    unsigned char local[0x1c];
    MIi_CpuClear32(0, local, 0x1c);
    *(unsigned int *)(local + 0) = 0x180;
    *(unsigned short *)(local + 0x12) = x;
    *(unsigned short *)(local + 0x14) = y;
    WirelessCommand_SubmitOpcodeThirtyFiveWithPayload(object, local);
}
