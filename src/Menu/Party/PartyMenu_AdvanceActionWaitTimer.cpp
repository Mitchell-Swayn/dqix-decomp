#include <globaldefs.h>
ARM
// Original: arm9/ov002 @ 0x0216C628; symbol: func_ov002_0216c628; size: 0x2C.
// Decrements the action delay, clamping expired delays to zero.
extern "C" int PartyMenu_AdvanceActionWaitTimer(char* self,int elapsed) {
 struct Block {char prefix[0xc74];int timer;};
 Block* block=(Block*)(self+0x1000);
 if(block->timer>elapsed)block->timer-=elapsed;
 else {block->timer=0;return 0;}
 return 1;
}
