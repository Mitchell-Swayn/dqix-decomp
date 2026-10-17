#include <globaldefs.h>
ARM
extern "C" int SubmitFiveHalfwordOperation1EPayload(int, unsigned short, unsigned short, unsigned short, unsigned short);
// Original: arm9/ov031 @ 0x02239E48; symbol: func_ov031_02239e48; size: 0x20.
extern "C" int func_ov031_02239e48(int first, unsigned short fourth) {
    return SubmitFiveHalfwordOperation1EPayload(first, 3, 0x11, fourth, 0x1e);
}
