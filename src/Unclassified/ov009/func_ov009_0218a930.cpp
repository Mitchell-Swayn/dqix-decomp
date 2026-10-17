#include <globaldefs.h>
ARM
struct CountdownState { char unknown[0xd96]; short remaining; };
// Original: arm9/ov009 @ 0x0218A930; symbol: func_ov009_0218a930; size: 0x2C.
extern "C" int func_ov009_0218a930(CountdownState* state,int amount) {
 if(state->remaining>amount) state->remaining-=amount;
 else { state->remaining=0; return 0; }
 return 1;
}
