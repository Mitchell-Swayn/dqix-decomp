#include <globaldefs.h>
ARM
extern "C" bool GameObject_IsDead(void*);
// Original: arm9/main @ 0x02049EFC; symbol: func_02049efc; size: 0x2C.
 extern "C" void CombatantMotion_DeactivateWhenObjectFlagged(unsigned char* p) { if (!*(void**)(p+0x13c))return; if (GameObject_IsDead(p)) (*(unsigned char**)(p+0x13c))[0x56]=0; }
