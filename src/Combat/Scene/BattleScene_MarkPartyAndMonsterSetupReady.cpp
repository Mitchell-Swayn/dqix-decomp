#include <globaldefs.h>
ARM
extern "C" void BattleScene_EnableFlags(unsigned char* p, unsigned int bits);
// Original: arm9/ov000 @ 0x02166E3C; symbol: func_ov000_02166e3c; size: 0x20.
extern "C" void BattleScene_MarkPartyAndMonsterSetupReady(unsigned char* p) { BattleScene_EnableFlags(p, 2); BattleScene_EnableFlags(p, 4); }
