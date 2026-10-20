#include <globaldefs.h>
ARM
extern "C" int GameState_GetValidLinkedObjectIndex(unsigned int, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov000 @ 0x02182064; symbol: func_ov000_02182064; size: 0x18.
extern "C" int Combat_GetValidLinkedObjectIndexAtSlotOneKindOne(unsigned int a, unsigned int b, unsigned int c, unsigned int d) { (void)a; (void)d; return GameState_GetValidLinkedObjectIndex(b, 1, c, 1); }
