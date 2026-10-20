#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020494A0; symbol: func_020494a0; size: 0x20.
extern "C" unsigned int CombatantMotion_GetEffectiveTargetIndex(unsigned char* p) { unsigned char* q=*(unsigned char**)(p+0x13c); if (!q) return 255; unsigned char value=q[0x4c]; if (value==255) value=q[0x4d]; return value; }
