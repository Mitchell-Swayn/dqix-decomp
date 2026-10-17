#include <globaldefs.h>
struct InputStateProjection { unsigned char preceding[0x28]; unsigned short x,y; unsigned char middle[6]; unsigned short held; unsigned char tail[4]; unsigned char flags;};
struct InputStateOwner {void* preceding; InputStateProjection* state;};
extern "C" InputStateOwner data_ov031_02290d40;
// Original: arm9/ov031 @ 0x0223D354; symbol: func_ov031_0223d354; size: 0x40.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM int AreInputMaskBitsHeld(unsigned int mask) {
 if(((*(volatile unsigned short*)0x027fffa8)&0x8000)>>15) return 0;
 return (mask&data_ov031_02290d40.state->held)==mask;
}
