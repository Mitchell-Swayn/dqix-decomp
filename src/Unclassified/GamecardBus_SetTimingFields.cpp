#include <globaldefs.h>
struct BusTiming { unsigned first,second; };
// Original: arm9/main @ 0x020D14B0; symbol: func_020d14b0; size: 0x34.
 extern "C" ARM void GamecardBus_SetTimingFields(const BusTiming* p) { volatile unsigned short* reg=(volatile unsigned short*)0x04000204; *reg=(p->first<<2)|(*reg & ~12u); *reg=(p->second<<4)|(*reg & ~16u); }
