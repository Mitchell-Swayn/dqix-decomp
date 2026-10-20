#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021AFB1C; symbol: func_ov017_021afb1c; size: 0xC.
extern "C" void Field_RequestPartyMemberSnapshotTransfer(unsigned char *p) {
    *(unsigned int *)(p + 0x30) = 1;
}
