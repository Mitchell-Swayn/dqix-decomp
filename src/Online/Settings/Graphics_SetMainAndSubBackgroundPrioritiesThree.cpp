#include <globaldefs.h>
ARM
struct BackgroundControl { unsigned short priority:2; unsigned short other:14; };
// Original: arm9/ov031 @ 0x02229A0C; symbol: func_ov031_02229a0c; size: 0x68.
// Sets priority3 on sub BG0/1 and main BG0/1/2 control registers.
extern "C" void Graphics_SetMainAndSubBackgroundPrioritiesThree() {
 ((volatile BackgroundControl*)0x04001008)->priority=3;
 ((volatile BackgroundControl*)0x0400100a)->priority=3;
 ((volatile BackgroundControl*)0x04000008)->priority=3;
 ((volatile BackgroundControl*)0x0400000a)->priority=3;
 ((volatile BackgroundControl*)0x0400000c)->priority=3;
}
