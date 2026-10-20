#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0216F0BC; symbol: func_ov000_0216f0bc; size: 0x14.
extern "C" unsigned int BattleCamera_IsActionPairShotSettled(void* p) { return *((unsigned char*)p + 0x260) ? *((unsigned char*)p + 0x261) : 1; }
