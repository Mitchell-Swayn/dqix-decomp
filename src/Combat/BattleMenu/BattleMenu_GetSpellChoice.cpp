#include <globaldefs.h>

// Original: arm9/ov000 @ 0x02171674; symbol: func_ov000_02171674; size: 0x24.
extern "C" ARM unsigned int BattleMenu_GetSpellChoice(unsigned char* table, int index) { if (index < 0 || index >= 0x42) return 0; return *(unsigned int*)(table + index * 4 + 0x9c); }
