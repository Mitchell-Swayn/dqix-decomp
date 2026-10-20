#include <globaldefs.h>
ARM
// Original: arm9/ov024 @ 0x021F6820; symbol: func_ov024_021f6820; size: 0x10.
extern "C" void BattleAI_SetActionChoiceIdentity(void* p, unsigned short a, unsigned char b, unsigned char c) { *(unsigned short*)p = a; *((unsigned char*)p + 2) = b; *((unsigned char*)p + 3) = c; }
