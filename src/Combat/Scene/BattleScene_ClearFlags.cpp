#include <globaldefs.h>
// Original: arm9/ov000 @ 0x02160fbc; symbol: func_ov000_02160fbc; size: 0x18.
extern "C" void BattleScene_ClearFlags(void* object, unsigned int mask) { unsigned int* flags=(unsigned int*)((char*)object+0x55f4); *flags &= ~mask; }
