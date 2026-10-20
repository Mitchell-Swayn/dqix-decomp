#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021A85E8; symbol: ItemTrade_TickIncomingOfferTimeout; size: 0x2C.
// Subtracts the requested step while countdown+0x38 exceeds it; otherwise clears it.
extern "C" bool ItemTrade_TickIncomingOfferTimeout(void* self,int step) {
 short* countdown=(short*)((char*)self+0x38);
 if(*countdown>step)*countdown-=step;
 else {*countdown=0;return false;}
 return true;
}
