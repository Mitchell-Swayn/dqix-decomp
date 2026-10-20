#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02088A34; symbol: func_02088a34; size: 0x20.
extern "C" void CombatantState_ActivateRotstopper(unsigned char* p) { p[0x64]=4;p[0x87]=0;*(unsigned int*)(p+0x14)|=0x20000000; }
